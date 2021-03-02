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

#include "backend/basicInterface.hpp"

namespace ASALI
{
    basicInterface::basicInterface()
    {
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
    
    void basicInterface::resize()
    {
        T_        = 0.;
        p_        = 0.;
        
        NS_      = this->numberOfGasSpecies();
        SURF_NS_ = this->numberOfSurfaceSpecies();
        
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
        
        nc_.resize(SURF_NS_);
    }

    void basicInterface::setTemperature(const double T)
    {
        T_ = T;
    }
    
    void basicInterface::setPressure(const double p)
    {
        p_ = p;
    }

    void basicInterface::convertToCaption(std::string& n)
    {
        for(unsigned int i=0;i<26;i++)
        {
            std::replace(n.begin(),n.end(),*small[i].c_str(),*big[i].c_str());
        }
    }

    double basicInterface::specieProperty(std::string p,std::string n)
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
    
    void basicInterface::setMoleFraction(const std::vector<double> x,const std::vector<std::string> name) {}

    void basicInterface::setMassFraction(const std::vector<double> y,const std::vector<std::string> name) {}

    void basicInterface::setStateFromMassFraction(const double* y, const double T, const double P) {}
    
    void basicInterface::setStateFromMoleFraction(const double* x, const double T, const double P) {}

    void basicInterface::vacuumCalculate() {}

    void basicInterface::thermoCalculate() {}

    void basicInterface::transportCalculate() {}

    double basicInterface::getTemperature() { return 0.; }
    
    double basicInterface::getDensity() { return 0.; }

    double basicInterface::getCpMassMix() { return 0.; }
    
    double basicInterface::getCpMoleMix() { return 0.; }
    
    double basicInterface::getMWmix() { return 0.; }
    
    double basicInterface::getCondMix() { return 0.; }
    
    double basicInterface::getMuMix() { return 0.; }
    
    int  basicInterface::checkNames(std::string name) { return 0; }

    unsigned int basicInterface::numberOfGasSpecies()     { return 0; }
    
    unsigned int basicInterface::numberOfSurfaceSpecies() { return 0; }
    
    std::vector<double> basicInterface::getMW() { std::vector<double> dummy; return dummy; }
    
    std::vector<double> basicInterface::getHmole() { std::vector<double> dummy; return dummy; }
    
    std::vector<double> basicInterface::getSmole() { std::vector<double> dummy; return dummy; }
    
    std::vector<double> basicInterface::getCpMole() { std::vector<double> dummy; return dummy; }
    
    std::vector<double> basicInterface::getDiffMix() { std::vector<double> dummy; return dummy; }
    
    std::vector<double> basicInterface::getBinaryDiffVector() { std::vector<double> dummy; return dummy; }

    std::vector<int>  basicInterface::checkNames(std::vector<std::string> &name) { std::vector<int> dummy; return dummy; }

    basicInterface::~basicInterface()
    {
    }
}
