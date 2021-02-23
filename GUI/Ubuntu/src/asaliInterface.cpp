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

#include "asaliInterface.hpp"

namespace ASALI
{
    asaliInterface::asaliInterface():
    basicInterface()
    {
        this->initialize();
        asali_ = new ASALI::Asali();
    }

    void asaliInterface::setTemperature(const double T)
    {
        T_ = T;
        asali_->setTemperature(T_);
    }
    
    void asaliInterface::setPressure(const double p)
    {
        p_ = p;
        asali_->setPressure(p_);
    }

    void asaliInterface::setMoleFraction(const std::vector<double> x,const std::vector<std::string> name)
    {
        asali_->setSpecies(name);
        names_ = asali_->speciesName();
        this->setStateFromMoleFraction(x.data(), T_, p_);
    }

    void asaliInterface::setMassFraction(const std::vector<double> y,const std::vector<std::string> name)
    {
        asali_->setSpecies(name);
        names_ = asali_->speciesName();
        this->setStateFromMassFraction(y.data(), T_, p_);
    }
    
    void asaliInterface::setStateFromMassFraction(const double* y, const double T, const double p)
    {
        T_ = T;
        p_ = p;

        std::vector<double> dummy(y, y + NS_);

        asali_->setMassFraction(dummy);
        asali_->setTemperature(T_);
        asali_->setPressure(p_);

		mole_ = asali_->moleFraction();
		mass_ = asali_->massFraction();

        x_ = mole_.data();
        y_ = mass_.data();
        
        for(unsigned int i=0;i<NS_;i++)
        {
            n_[i]  = asali_->speciesName()[i];
            MW_[i] = asali_->speciesMolecularWeight()[i];
        }
    }
    
    void asaliInterface::setStateFromMoleFraction(const double* x, const double T, const double p)
    {
        T_ = T;
        p_ = p;
        
        std::vector<double> dummy(x, x + NS_);
        
        asali_->setMoleFraction(dummy);
        asali_->setTemperature(T_);
        asali_->setPressure(p_);

		mole_ = asali_->moleFraction();
		mass_ = asali_->massFraction();

        x_ = mole_.data();
        y_ = mass_.data();
        
        for(unsigned int i=0;i<NS_;i++)
        {
            n_[i]  = asali_->speciesName()[i];
            MW_[i] = asali_->speciesMolecularWeight()[i];
        }
    }

    void asaliInterface::vacuumCalculate()
    {
		/*
        for(unsigned int i=0;i<NS_;i++)
        {
            const Cantera::GasTransportData* transportData = dynamic_cast<Cantera::GasTransportData*>(thermo_->species(n_[i])->transport.get());
            v_[i] = std::sqrt(8.*8314.*T_/(pi_*MW_[i]));
            l_[i] = 1.38064852*1e-23*T_/(std::sqrt(2)*p_*std::pow(transportData->diameter,2.));
        }*/
    }

    void asaliInterface::thermoCalculate()
    {
		/*
        double mw[NS_];
        double h[NS_];
        double s[NS_];
        double cp[NS_];

        thermo_->getMolecularWeights(mw);
        thermo_->getPartialMolarEnthalpies(h);
        thermo_->getPartialMolarEntropies(s);
        thermo_->getPartialMolarCp(cp);

        for (unsigned int i=0;i<NS_;i++)
        {
            n_[i]  = thermo_->speciesName(i);
            h_[i]  = h[i];
            s_[i]  = s[i];
            cp_[i] = cp[i];
            MW_[i] = mw[i];
        }

        n_[NS_]  = "mix";
        h_[NS_]  = thermo_->enthalpy_mole();       //J/Kmol
        s_[NS_]  = thermo_->entropy_mole();        //J/Kmol/K
        cp_[NS_] = this->getCpMoleMix();             //J/Kmol/K
        MW_[NS_] = this->getMWmix();
        */
    }

    void asaliInterface::transportCalculate()
    {
		/*
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
        }*/
    }
    
    double asaliInterface::getTemperature()
    {
        return T_;
    }
    
    double asaliInterface::getDensity()
    {
        return asali_->density();
    }

    double asaliInterface::getCpMassMix()
    {
        return asali_->mixtureMassCp();
    }
    
    double asaliInterface::getCpMoleMix()
    {
        return asali_->mixtureMolarCp();
    }
    
    double asaliInterface::getMWmix()
    {
        return asali_->mixtureMolecularWeight();
    }

    int  asaliInterface::checkNames(std::string name)
    {
        int check = 1;
        this->convertToCaption(name);
        for (unsigned int j=0;j<NS_;j++)
        {
            if ( name == names_[j] )
            {
                check = 0;
                break;
            }
        }
        return check;
    }

    unsigned int asaliInterface::numberOfGasSpecies()
    {
        return asali_->numberOfSpecies();
    }

    unsigned int asaliInterface::numberOfSurfaceSpecies()
    {
        return 0.;
    }

    std::vector<double> asaliInterface::getMW()
    {
        return asali_->speciesMolecularWeight();
    }

    std::vector<double> asaliInterface::getHmole()
    {
        return asali_->speciesMolarEnthalpy();
    }

    std::vector<double> asaliInterface::getSmole()
    {
        return asali_->speciesMolarEntropy();
    }

    std::vector<double> asaliInterface::getCpMole()
    {
        return asali_->speciesMolarCp();
    }

    std::vector<int>  asaliInterface::checkNames(std::vector<std::string> &name)
    {
        std::vector<int> check(name.size());
        
        for (unsigned int i=0;i<name.size();i++)
        {
            this->convertToCaption(name[i]);
            check[i] = 1;
            for (unsigned int j=0;j<NS_;j++)
            {
                if ( name[i] == names_[j] )
                {
                    check[i] = 0;
                    break;
                }
            }
        }

        return check;
    }

    asaliInterface::~asaliInterface()
    {
    }
}
