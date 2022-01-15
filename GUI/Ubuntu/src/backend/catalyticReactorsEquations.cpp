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

#include "backend/catalyticReactorsEquations.hpp"

namespace ASALI
{
    catalyticReactorsEquations::catalyticReactorsEquations()
    {
        vectorUtils_ = new ASALI::asaliVectorUtils();
    }

    void catalyticReactorsEquations::setInterface(ASALI::canteraInterface *chemistryInterface)
    {
        chemistryInterface_ = chemistryInterface;
    }

    void catalyticReactorsEquations::setHomogeneousReactions(const bool flag)
    {
        homogeneousReactions_ = flag;
    }

    void catalyticReactorsEquations::setHeterogeneusReactions(const bool flag)
    {
        heterogeneusReactions_ = flag;
    }

    void catalyticReactorsEquations::setKineticType(const std::string &type)
    {
        type_ = type;
    }

    void catalyticReactorsEquations::setAsaliKinetic(ASALI::pythonInterface *pi, const std::vector<int> &canteraIndex, const std::vector<std::string> &n)
    {
        pi_ = pi;
        canteraIndex_ = canteraIndex;
        n_ = n;

        if (pi_->getNumberOfHomReactions() > 0)
        {
            homogeneousReactions_ = true;
        }
        else
        {
            homogeneousReactions_ = false;
        }

        if (pi_->getNumberOfHetReactions() > 0)
        {
            heterogeneusReactions_ = true;
        }
        else
        {
            heterogeneusReactions_ = false;
        }
    }

    void catalyticReactorsEquations::turnOnUserDefined(const bool check)
    {
        userCheck_ = check;
    }

    void catalyticReactorsEquations::setMW(const std::vector<double> &MW)
    {
        MW_ = MW;
    }

    void catalyticReactorsEquations::setDiffMix(const std::vector<double> &diff)
    {
        diff_ = diff;
    }

    void catalyticReactorsEquations::setQfromSurface(const std::vector<double> &Q)
    {
        QuserHet_ = Q;
    }

    void catalyticReactorsEquations::setQfromGas(const std::vector<double> &Q)
    {
        QuserHom_ = Q;
    }

    void catalyticReactorsEquations::setCpMassMix(const double cp)
    {
        cp_ = cp;
    }

    void catalyticReactorsEquations::setMuMix(const double mu)
    {
        mu_ = mu;
    }

    void catalyticReactorsEquations::setCondMix(const double cond)
    {
        cond_ = cond;
    }

    void catalyticReactorsEquations::updateHomogenousChemistry()
    {
        if (homogeneousReactions_ == true)
        {
            if (type_ == "CANTERA")
            {
                chemistryInterface_->calculateHomogeneousReactions(omega_, T_, P_);
                RfromGas_ = chemistryInterface_->RfromGas();
                if (energyEquation_ == true)
                {
                    QfromGas_ = chemistryInterface_->QfromGas();
                }
                else
                {
                    QfromGas_ = 0.;
                }
            }
            else if (type_ == "ASALI")
            {
                RfromGas_ = this->reactionRate(x_, T_, "homogeneous"); //kmol/m3/s
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

                        QfromGas_ = this->heatOfReaction(x_, T_, h_, "homogeneous"); //W/m3
                    }
                    else
                    {
                        for (unsigned int i = 0; i < NC_; i++)
                        {
                            h_[i] = 0.;
                        }
                        QfromGas_ = this->heatOfReaction(x_, T_, h_, "homogeneous"); //W/m3
                    }
                }
                else
                {
                    QfromGas_ = 0.;
                }
            }
        }
        else
        {
            for (unsigned int j = 0; j < NC_; j++)
            {
                RfromGas_[j] = 0.; //kmol/m2/s
            }
            QfromGas_ = 0.;
        }
    }

    void catalyticReactorsEquations::updateHeterogeneousChemistry()
    {
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
    }

    std::vector<double> catalyticReactorsEquations::reactionRate(const std::vector<double> &x, const double T, const std::string &type)
    {
        std::vector<double> R;
        pi_->setTemperature(T);
        pi_->setMoleFraction(x, n_);
        if (type == "heterogeneous")
        {
            pi_->runHeterogeneous();
            R = pi_->getHetReactionRate();
        }
        else if (type == "homogeneous")
        {
            pi_->runHomogeneous();
            R = pi_->getHomReactionRate();
        }
        return R;
    }

    double catalyticReactorsEquations::heatOfReaction(const std::vector<double> &x, const double T, const std::vector<double> &h, const std::string &type)
    {
        double Q = 0;
        pi_->setTemperature(T);
        pi_->setMoleFraction(x, n_);

        if (type == "heterogeneous")
        {
            if (userCheck_ == false)
            {
                pi_->runAllHeterogeneous();
                std::vector<std::vector<double>> R = pi_->getAllHetReactionRate();
                for (unsigned int i = 0; i < NC_; i++)
                {
                    double Rtot = 0;
                    for (unsigned int j = 0; j < pi_->getNumberOfHetReactions(); j++)
                    {
                        Rtot = Rtot + R[j][i];
                    }
                    Q = Q + Rtot * h[i];
                }
            }
            else
            {
                pi_->runNetHeterogeneous();
                std::vector<double> R = pi_->getHetNetRate();
                for (unsigned int j = 0; j < R.size(); j++)
                {
                    Q = Q + R[j] * QuserHet_[j];
                }
            }
        }
        else if (type == "homogeneous")
        {
            if (userCheck_ == false)
            {
                pi_->runAllHomogeneous();
                std::vector<std::vector<double>> R = pi_->getAllHomReactionRate();
                for (unsigned int i = 0; i < NC_; i++)
                {
                    double Rtot = 0;
                    for (unsigned int j = 0; j < pi_->getNumberOfHomReactions(); j++)
                    {
                        Rtot = Rtot + R[j][i];
                    }
                    Q = Q + Rtot * h[i];
                }
            }
            else
            {
                pi_->runNetHomogeneous();
                std::vector<double> R = pi_->getHomNetRate();
                for (unsigned int j = 0; j < R.size(); j++)
                {
                    Q = Q + R[j] * QuserHom_[j];
                }
            }
        }

        return -Q;
    }

    double catalyticReactorsEquations::meanMolecularWeight(const std::vector<double> &omega, const std::vector<double> &MW)
    {
        double MWmix = 0.;
        for (unsigned int i = 0; i < NC_; i++)
        {
            MWmix = MWmix + omega[i] / MW[i];
        }
        return 1. / MWmix;
    }

    std::vector<double> catalyticReactorsEquations::moleFraction(const std::vector<double> &omega, const std::vector<double> &MW, double MWmix)
    {
        std::vector<double> x = omega;

        for (unsigned int i = 0; i < NC_; i++)
        {
            x[i] = omega[i] * MWmix / MW[i];
        }

        return x;
    }

    catalyticReactorsEquations::~catalyticReactorsEquations()
    {
        delete vectorUtils_;
    }
}
