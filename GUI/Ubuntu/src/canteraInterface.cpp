/*##############################################################################################
#                                                                                              #
#     #############       #############       #############       ####                ####     #
#    #             #     #             #     #             #     #    #              #    #    #
#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #
#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #
#    #    #####    #     #    #              #    #####    #     #    #              #    #    #
#    #             #     #    #########      #             #     #    #              #    #    #
#    #             #     #             #     #             #     #    #              #    #    #
#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #
#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #
#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #
#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #
#     ####     ####       #############       ####     ####       #############       ####     #
#                                                                                              #
#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #
#                                                                                              #
################################################################################################
#                                                                                              #
#   License                                                                                    #
#                                                                                              #
#   This file is part of ASALI.                                                                #
#                                                                                              #
#   ASALI is free software: you can redistribute it and/or modify                              #
#   it under the terms of the GNU General Public License as published by                       #
#   the Free Software Foundation, either version 3 of the License, or                          #
#   (at your option) any later version.                                                        #
#                                                                                              #
#   ASALI is distributed in the hope that it will be useful,                                   #
#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #
#   GNU General Public License for more details.                                               #
#                                                                                              #
#   You should have received a copy of the GNU General Public License                          #
#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #
#                                                                                              #
##############################################################################################*/

#include "canteraInterface.hpp"

namespace ASALI
{
    canteraInterface::canteraInterface(Cantera::ThermoPhase* thermo,
                                       Cantera::Transport*   transport):
    thermo_(thermo),
    transport_(transport),
    basicInterface(thermo, transport, kinetic, surface, kineticType)
    {

    }

    std::vector<int>  canteraInterface::checkNames(std::vector<std::string> &name)
    {
        std::vector<int> check(name.size());
        
        for (unsigned int i=0;i<name.size();i++)
        {
            this->convertToCaption(name[i]);
            check[i] = 1;
            for (unsigned int j=0;j<NS_;j++)
            {
                if ( name[i] == thermo_->speciesName(j) )
                {
                    check[i] = 0;
                    break;
                }
            }
        }

        return check;
    }
    

    int  canteraInterface::checkNames(std::string name)
    {
        int check = 1;

        this->convertToCaption(name);
        for (unsigned int j=0;j<NS_;j++)
        {
            if ( name == thermo_->speciesName(j) )
            {
                check = 0;
                break;
            }
        }

        return check;
    }

    void canteraInterface::setMoleFraction(const std::vector<double> x,const std::vector<std::string> name)
    {
        for (unsigned int i=0;i<NS_;i++)
        {
            x_[i] = 0.;
            for (unsigned int j=0;j<name.size();j++)
            {
                if ( name[j] == thermo_->speciesName(i) )
                {
                    x_[i] = x[j];
                    break;
                }
            }
        }
        thermo_->setState_TPX(T_,p_,x_);
        thermo_->getMassFractions(y_);
        
        for(unsigned int i=0;i<NS_;i++)
        {
            mass_[i] = y_[i];
            mole_[i] = x_[i];
            n_[i]    = thermo_->speciesName(i);
            MW_[i]   = thermo_->molecularWeight(i);
        }

    }

    void canteraInterface::setMassFraction(const std::vector<double> y,const std::vector<std::string> name)
    {
        for (unsigned int i=0;i<NS_;i++)
        {
            y_[i] = 0.;
            for (unsigned int j=0;j<name.size();j++)
            {
                if ( name[j] == thermo_->speciesName(i) )
                {
                    y_[i] = y[j];
                    break;
                }
            }
        }

        thermo_->setState_TPY(T_,p_,y_);
        thermo_->getMoleFractions(x_);

        for(unsigned int i=0;i<NS_;i++)
        {
            mass_[i] = y_[i];
            mole_[i] = x_[i];
            n_[i]    = thermo_->speciesName(i);
            MW_[i]   = thermo_->molecularWeight(i);
        }
    }
    
    void canteraInterface::equilibriumCalculate(std::string type)
    {
        thermo_->equilibrate(type);
        thermo_->getMassFractions(y_);
        thermo_->getMoleFractions(x_);
        
        for(unsigned int i=0;i<NS_;i++)
        {
            mass_[i] = y_[i];
            mole_[i] = x_[i];
            n_[i]    = thermo_->speciesName(i);
        }
    }
    
    double canteraInterface::temperature()
    {
        return thermo_->temperature();
    }
    
    double canteraInterface::density()
    {
        return thermo_->density();
    }

    void canteraInterface::vacuumCalculate()
    {
        for(unsigned int i=0;i<NS_;i++)
        {
            const Cantera::GasTransportData* transportData = dynamic_cast<Cantera::GasTransportData*>(thermo_->species(n_[i])->transport.get());
            v_[i] = std::sqrt(8.*8314.*T_/(pi_*MW_[i]));
            l_[i] = 1.38064852*1e-23*T_/(std::sqrt(2)*p_*std::pow(transportData->diameter,2.));
        }
    }

    void canteraInterface::thermoCalculate()
    {
        double h[NS_];
        double s[NS_];
        double cp[NS_];
        
        thermo_->getPartialMolarEnthalpies(h);
        thermo_->getPartialMolarEntropies(s);
        thermo_->getPartialMolarCp(cp);


        for (unsigned int i=0;i<NS_;i++)
        {
            n_[i]  = thermo_->speciesName(i);
            h_[i]  = h[i];
            s_[i]  = s[i];
            cp_[i] = cp[i];
            MW_[i] = thermo_->molecularWeight(i);
        }

        n_[NS_]  = "mix";
        h_[NS_]  = thermo_->enthalpy_mole();       //J/Kmol
        s_[NS_]  = thermo_->entropy_mole();        //J/Kmol/K
        cp_[NS_] = thermo_->cp_mole();             //J/Kmol/K
        MW_[NS_] = thermo_->meanMolecularWeight();
    }

    void canteraInterface::transportCalculate()
    {
        double mu[NS_];
        double diff[NS_*NS_];
        double diffM[NS_];
        
        transport_->getSpeciesViscosities(mu);
        transport_->getBinaryDiffCoeffs(NS_,diff);
        transport_->getMixDiffCoeffs(diffM);

        unsigned int counter = 0;
        for (unsigned int i=0;i<(NS_+1);i++)
        {
            if ( i == NS_ ) 
            {
                n_[i]     = "mix";
                mu_[i]    = transport_->viscosity();             //Pas
                cond_[i]  = transport_->thermalConductivity();   //W/m/K
                MW_[i]    = thermo_->meanMolecularWeight();
                for (unsigned int j=0;j<(NS_+1);j++)
                {
                    diff_[i][j] = -1.;
                }
            }
            else
            {
                n_[i]  = thermo_->speciesName(i);
                mu_[i] = mu[i];
                MW_[i] = thermo_->molecularWeight(i);

                for (unsigned int j=0;j<(NS_+1);j++)
                {
                    if ( j == NS_ )
                    {
                        diff_[i][j] = diffM[i];
                    }
                    else
                    {
                        diff_[i][j] = diff[counter++];
                    }
                }
            }
        }
        
        
        {
            double X[NS_];
            for (unsigned int i=0;i<NS_;i++)
            {
                for (unsigned int j=0;j<NS_;j++)
                {
                    if (j==i)
                    {
                        X[j] = 1.;
                    }
                    else
                    {
                        X[j] = 0.;
                    }
                }

                thermo_->setState_TPY(T_,p_,X);
                cond_[i] = transport_->thermalConductivity();
            }
        }
    }
    
    int canteraInterface::numberOfSpecies()
    {
		return thermo_->nSpecies();
	}

    canteraInterface::~canteraInterface()
    {
    }
}
