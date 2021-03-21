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

if (heterogeneusReactions_ == true && alfa_ != 0.)
{
    if (type_ == "CANTERA")
    {
        chemistryInterface_->calculateHeterogeneousReactions(omega_, Z_, T_, P_);
        RfromSurface_ = chemistryInterface_->RfromSurface();
        Rsurface_ = chemistryInterface_->Rsurface();
        SD_ = chemistryInterface_->siteDensity();

        if (energyEquation_ == true)
        {
            QfromSurface_ = chemistryInterface_->QfromSurface();
        }
        else
        {
            QfromSurface_ = 0.;
        }
    }
    else if (type_ == "ASALI")
    {
        RfromSurface_ = this->reactionRate(x_, T_, "heterogeneous"); //kmol/m3/s

        if (energyEquation_ == true)
        {
            if (userCheck_ == false)
            {
                chemistryInterface_->setStateFromMoleFraction(x_.data(), T_, P_);
                std::vector<double> hArray = chemistryInterface_->getHmole();

                for (unsigned int i = 0; i < NC_; i++)
                {
                    h_[i] = hArray[canteraIndex_[i]];
                }

                QfromSurface_ = this->heatOfReaction(x_, T_, h_, "heterogeneous"); //W/m3
            }
            else
            {
                for (unsigned int i = 0; i < NC_; i++)
                {
                    h_[i] = 0.;
                }
                QfromSurface_ = this->heatOfReaction(x_, T_, h_, "heterogeneous"); //W/m3
            }
        }
        else
        {
            QfromSurface_ = 0.;
        }
    }
}
else
{
    for (unsigned int j = 0; j < NC_; j++)
    {
        RfromSurface_[j] = 0.;
    }

    for (unsigned int j = 0; j < SURF_NC_; j++)
    {
        Rsurface_[j] = 0.;
    }

    QfromSurface_ = 0.;
}
