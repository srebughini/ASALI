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
        names_.resize(NS_);

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

    double basicInterface::specieProperty(std::string p, std::string n)
    {
        int idx = 0;
        if (n != "mix")
        {
            this->convertToCaption(n);
            idx = this->getSpecieIndex(n);
        }
        else
        {
            idx = int(NS_);
        }

        this->convertToCaption(p);

        if (p == "H")
        {
            return h_[idx];
        }
        else if (p == "S")
        {
            return s_[idx];
        }
        else if (p == "CP")
        {
            return cp_[idx];
        }
        else if (p == "COND")
        {
            return cond_[idx];
        }
        else if (p == "MU")
        {
            return mu_[idx];
        }
        else if (p == "MW")
        {
            return MW_[idx];
        }
        else if (p == "DIFF")
        {
            return diff_[idx][NS_];
        }
        else
        {
            return 0;
        }
    }

    std::vector<double> basicInterface::getMoleFractionFromNames(const std::vector<std::string> &names)
    {
        std::vector<double> x(names.size());
        for (unsigned int i = 0; i < names.size(); i++)
        {
            for (unsigned int j = 0; j < names_.size(); j++)
            {
                if (names[i] == names_[j])
                {
                    x[i] = mole_[j];
                    break;
                }
            }
        }
        return x;
    }

    std::vector<double> basicInterface::getMassFractionFromNames(const std::vector<std::string> &names)
    {
        std::vector<double> y(names.size());
        for (unsigned int i = 0; i < names.size(); i++)
        {
            for (unsigned int j = 0; j < names_.size(); j++)
            {
                if (names[i] == names_[j])
                {
                    y[i] = mass_[j];
                    break;
                }
            }
        }
        return y;
    }

    basicInterface::~basicInterface()
    {
        delete[] x_;
        delete[] y_;
    }
}
