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

if ( heterogeneusReactions_ == true && alfa_ != 0.)
{
    if ( type_ == "CANTERA" )
    {
        {
            double* bulkArray     = omega_.data();
            double* coverageArray = Z_.data();
            double  reactionArray[NC_+SURF_NC_];

            gas_->setState_TPY(T_,P_,bulkArray);

            surface_->setTemperature(T_);
            surface_->setCoveragesNoNorm(coverageArray);
            surface_->getNetProductionRates(reactionArray);

            unsigned int rcounter = 0;
            for (unsigned int j=0;j<NC_;j++)
            {
                RfromSurface_[j] = reactionArray[rcounter++]; //kmol/m2/s
            }

            for (unsigned int j=0;j<SURF_NC_;j++)
            {
                Rsurface_[j] = reactionArray[rcounter++];
            }
        }
        
        if ( energyEquation_ == true )
        {
            double reactionArray[surface_->nReactions()];
            double enthalpyArray[surface_->nReactions()];
            surface_->getNetRatesOfProgress(reactionArray);
            surface_->getDeltaEnthalpy(enthalpyArray);
            QfromSurface_ = 0.;
            for (unsigned int j=0;j<surface_->nReactions();j++)
            {
                QfromSurface_ = QfromSurface_ + reactionArray[j]*enthalpyArray[j];  //J/kmol/s
            }

            QfromSurface_ = -QfromSurface_;

            SD_ = surface_->siteDensity();
        }
        else
        {
            QfromSurface_ = 0.;

            SD_ = surface_->siteDensity();
        }
    }
    else if ( type_ == "ASALI" )
    {
        RfromSurface_ = this->reactionRate(x_,T_,"heterogeneous"); //kmol/m3/s

        if ( energyEquation_ == true )
        {
            if ( userCheck_ == false )
            {
                double hArray[gas_->nSpecies()];
                gas_->getPartialMolarEnthalpies(hArray);
                
                for (unsigned int i=0;i<NC_;i++)
                {
                    h_[i] = hArray[canteraIndex_[i]];
                }

                QfromSurface_ = this->heatOfReaction(x_,T_,h_,"heterogeneous"); //W/m3
            }
            else
            {
                for (unsigned int i=0;i<NC_;i++)
                {
                    h_[i] = 0.;
                }
                QfromSurface_ = this->heatOfReaction(x_,T_,h_,"heterogeneous"); //W/m3
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
    for (unsigned int j=0;j<NC_;j++)
    {
        RfromSurface_[j] = 0.;
    }

    for (unsigned int j=0;j<SURF_NC_;j++)
    {
        Rsurface_[j] = 0.;
    }
    
    QfromSurface_ = 0.;
}
