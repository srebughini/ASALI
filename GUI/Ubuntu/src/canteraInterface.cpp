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
    transport_(transport)
    {
        T_       = 0.;
        p_       = 0.;
        
        NS_      = thermo->nSpecies();
        
        y_       = new double[NS_];
        x_       = new double[NS_];
        
        mole_.resize(NS_);
        mass_.resize(NS_);
        v_.resize(NS_);
        l_.resize(NS_);
        h_.resize(NS_ + 1);
        s_.resize(NS_ + 1);
        cp_.resize(NS_ + 1);
        MW_.resize(NS_ + 1);
        n_.resize(NS_ + 1);
        mu_.resize(NS_ + 1);
        cond_.resize(NS_ + 1);
        
        diff_.resize(NS_ + 1);
        for (unsigned int i=0;i<(NS_+1);i++)
        {
            diff_[i].resize(NS_ + 1);
        }
        
        small.resize(26);    big.resize(26);
        small[0]  = "a";    big[0]  = "A";
        small[1]  = "b";    big[1]  = "B";
        small[2]  = "c";    big[2]  = "C";
        small[3]  = "d";    big[3]  = "D";
        small[4]  = "e";    big[4]  = "E";
        small[5]  = "f";    big[5]  = "F";
        small[6]  = "g";    big[6]  = "G";
        small[7]  = "h";    big[7]  = "H";
        small[8]  = "i";    big[8]  = "I";
        small[9]  = "j";    big[9]  = "J";
        small[10] = "k";    big[10] = "K";
        small[11] = "l";    big[11] = "L";
        small[12] = "m";    big[12] = "M";
        small[13] = "n";    big[13] = "N";
        small[14] = "o";    big[14] = "O";
        small[15] = "p";    big[15] = "P";
        small[16] = "q";    big[16] = "Q";
        small[17] = "r";    big[17] = "R";
        small[18] = "s";    big[18] = "S";
        small[19] = "t";    big[19] = "T";
        small[20] = "u";    big[20] = "U";
        small[21] = "v";    big[21] = "V";
        small[22] = "w";    big[22] = "W";
        small[23] = "x";    big[23] = "X";
        small[24] = "y";    big[24] = "Y";
        small[25] = "z";    big[25] = "Z";
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

    void canteraInterface::setTemperature(const double T)
    {
        T_ = T;
    }
    
    void canteraInterface::setPressure(const double p)
    {
        p_ = p;
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
    
    double canteraInterface::Temperature()
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
    
    void canteraInterface::convertToCaption(std::string& n)
    {
        for(unsigned int i=0;i<26;i++)
        {
            std::replace(n.begin(),n.end(),*small[i].c_str(),*big[i].c_str());
        }
    }

    double canteraInterface::specieProperty(std::string p,std::string n)
    {
        if ( n != "mix" )
        {
            for(unsigned int i=0;i<26;i++)
            {
                std::replace(n.begin(),n.end(),*small[i].c_str(),*big[i].c_str());
            }
        }

        double r = 0;
        
        if ( p == "h" )
        {
            for (unsigned int i=0;i<=NS_;i++)
            {
                if ( n_[i] == n )
                {
                    r = h_[i];
                    break;
                }
            }
        }
        else if ( p == "s" )
        {
            for (unsigned int i=0;i<=NS_;i++)
            {
                if ( n_[i] == n )
                {
                    r = s_[i];
                    break;
                }
            }
        }
        else if ( p == "cp" )
        {
            for (unsigned int i=0;i<=NS_;i++)
            {
                if ( n_[i] == n )
                {
                    r = cp_[i];
                    break;
                }
            }
        }
        else if ( p == "cond" )
        {
            for (unsigned int i=0;i<=NS_;i++)
            {
                if ( n_[i] == n )
                {
                    r = cond_[i];
                    break;
                }
            }
        }
        else if ( p == "mu" )
        {
            for (unsigned int i=0;i<=NS_;i++)
            {
                if ( n_[i] == n )
                {
                    r = mu_[i];
                    break;
                }
            }
        }
        else if ( p == "mw" )
        {
            for (unsigned int i=0;i<=NS_;i++)
            {
                if ( n_[i] == n )
                {
                    r = MW_[i];
                    break;
                }
            }
        }
        else if ( p == "diff" )
        {
            for (unsigned int i=0;i<=NS_;i++)
            {
                if ( n_[i] == n )
                {
                    r = diff_[i][NS_];
                    break;
                }
            }
        }
        
        return r;
    }

    canteraInterface::~canteraInterface()
    {
    }
}
