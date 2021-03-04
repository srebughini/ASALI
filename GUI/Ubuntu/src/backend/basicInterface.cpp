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
    }

    void basicInterface::resize()
    {
        T_ = 0.;
        p_ = 0.;

        NS_ = this->numberOfGasSpecies();
        SURF_NS_ = this->numberOfSurfaceSpecies();

        y_ = new double[NS_];
        x_ = new double[NS_];

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
        for (unsigned int i = 0; i < (NS_ + 1); i++)
        {
            diff_[i].resize(NS_ + 1);
        }

        nc_.resize(SURF_NS_);
    }

    void basicInterface::convertToCaption(std::string &n)
    {
        std::transform(n.begin(), n.end(), n.begin(), ::toupper);
    }
    
    int basicInterface::getSpecieIndex(std::string n)
    {
        for (unsigned int i = 0; i <= NS_; i++)
        {
            if (n_[i] == n)
            {
                return i;
            }
        }
        return -1;
    }

    double basicInterface::specieProperty(std::string p, std::string n)
    {
        if (n != "mix")
        {
            this->convertToCaption(n);
        }

        int idx = this->getSpecieIndex(n);

        if (p == "h")
        {
            return h_[idx];
        }
        else if (p == "s")
        {
            return s_[idx];
        }
        else if (p == "cp")
        {
            return cp_[idx];
        }
        else if (p == "cond")
        {
            return cond_[idx];
        }
        else if (p == "mu")
        {
            return mu_[idx];
        }
        else if (p == "mw")
        {
            return MW_[idx];
        }
        else if (p == "diff")
        {
            return diff_[idx][NS_];
        }
        else
        {
            return 0;
        }
    }

    basicInterface::~basicInterface()
    {
    }
}
