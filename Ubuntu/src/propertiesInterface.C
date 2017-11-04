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

#include "propertiesInterface.h"

namespace ASALI
{
    propertiesInterface::propertiesInterface(ASALI::Properties* properties):
    properties_(properties)
    {
        T_       = 0.;
        p_       = 0.;

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

    std::vector<int>  propertiesInterface::checkNames(std::vector<std::string>& name)
    {
        std::vector<int> check(name.size());
        
        for (unsigned int i=0;i<name.size();i++)
        {
            check[i] = 1;
            this->convertToCaption(name[i]);
            for (unsigned int j=0;j<properties_->numberOfAllSpecies();j++)
            {
                if ( name[i] == properties_->allSpeciesName()[j] )
                {
                    check[i] = 0;
                    break;
                }
            }
        }

        return check;
    }
    
    
    void propertiesInterface::setTemperature(const double T)
    {
        T_ = T;
        properties_->setTemperature(T_);
    }
    
    void propertiesInterface::setPressure(const double p)
    {
        p_ = p;
        properties_->setPressure(p_);
    }
    
    void propertiesInterface::setMoleFraction(const std::vector<double> x,const std::vector<std::string> name)
    {
        properties_->setSpecies(name);
        properties_->setMoleFraction(x);
        
        NS_   = properties_->numberOfSpecies();
        mass_ = properties_->massFraction();
        mole_ = x;
        
        std::vector<double>      MW = properties_->speciesMolecularWeight();
        std::vector<std::string> n  = properties_->speciesName();

        mole_.resize(NS_);
        mass_.resize(NS_);
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

        for (unsigned int i=0;i<NS_;i++)
        {
            MW_[i] = MW[i];
            n_[i]  = n[i];
        }
    }

    void propertiesInterface::setMassFraction(const std::vector<double> y,const std::vector<std::string> name)
    {
        properties_->setSpecies(name);
        properties_->setMassFraction(y);

        NS_   = properties_->numberOfSpecies();
        mass_ = y;
        mole_ = properties_->moleFraction();

        std::vector<double>      MW = properties_->speciesMolecularWeight();
        std::vector<std::string> n  = properties_->speciesName();

        mole_.resize(NS_);
        mass_.resize(NS_);
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


        for (unsigned int i=0;i<NS_;i++)
        {
            MW_[i] = MW[i];
            n_[i]  = n[i];
        }
    }
    
    void propertiesInterface::vacuumCalculate()
    {
        v_ = properties_->aritmeticMeanGasVelocity();
        l_ = properties_->meanFreePath();
    }
    
    void propertiesInterface::thermoCalculate()
    {
        std::vector<double>  cp = properties_->speciesMolarCp();
        std::vector<double>  h  = properties_->speciesMolarEnthalpy();
        std::vector<double>  s  = properties_->speciesMolarEntropy();
        std::vector<double>  MW = properties_->speciesMolecularWeight();

        for (unsigned int i=0;i<NS_;i++)
        {
            h_[i]  = h[i];
            s_[i]  = s[i];
            cp_[i] = cp[i];
            MW_[i] = MW[i];
        }

        n_[NS_]  = "mix";
        h_[NS_]  = properties_->mixtureMolarEnthalpy();       //J/Kmol
        s_[NS_]  = properties_->mixtureMolarEntropy();        //J/Kmol/K
        cp_[NS_] = properties_->mixtureMolarCp();             //J/Kmol/K
        MW_[NS_] = properties_->mixtureMolecularWeight();
    }

    void propertiesInterface::transportCalculate()
    {
        std::vector<double>               mu    = properties_->speciesViscosity();
        std::vector<std::vector<double> > diff  = properties_->binaryDiffusion();
        std::vector<double>               cond  = properties_->speciesThermalConductivity();
        std::vector<double>               diffM = properties_->mixtureDiffusion();
        std::vector<double>               MW    = properties_->speciesMolecularWeight();

        for (unsigned int i=0;i<(NS_+1);i++)
        {
            if ( i == NS_ ) 
            {
                n_[i]    = "mix";
                mu_[i]   = properties_->mixtureViscosity();             //Pas
                cond_[i] = properties_->mixtureThermalConductivity();   //W/m/K
                MW_[i]   = properties_->mixtureMolecularWeight();
                for (unsigned int j=0;j<(NS_+1);j++)
                {
                    diff_[i][j] = -1.;
                }
            }
            else
            {
                mu_[i]   = mu[i];
                cond_[i] = cond[i];
                MW_[i]   = MW[i];

                for (unsigned int j=0;j<(NS_+1);j++)
                {
                    if ( j == NS_ )
                    {
                        diff_[i][j] = diffM[i];
                    }
                    else
                    {
                        diff_[i][j] = diff[i][j];
                    }
                }
            }
        }
    }

    void propertiesInterface::convertToCaption(std::string& n)
    {
        for(unsigned int i=0;i<26;i++)
        {
            std::replace(n.begin(),n.end(),*small[i].c_str(),*big[i].c_str());
        }
    }

    propertiesInterface::~propertiesInterface()
    {
    }
}
