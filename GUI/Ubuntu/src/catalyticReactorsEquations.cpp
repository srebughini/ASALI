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

#include "catalyticReactorsEquations.hpp"

namespace ASALI
{
    catalyticReactorsEquations::catalyticReactorsEquations()
    {
        vectorUtils_ = new ASALI::asaliVectorUtils();
    }

    void catalyticReactorsEquations::setCanteraThermo(Cantera::ThermoPhase* gas)
    {
        gas_ = gas;
    }
    
    void catalyticReactorsEquations::setCanteraInterface(Cantera::Interface* surface)
    {
        surface_ = surface;
    }

    void catalyticReactorsEquations::setCanteraKinetics(Cantera::Kinetics* kinetic)
    {
        kinetic_ = kinetic;
    }

    void catalyticReactorsEquations::setCanteraTransport(Cantera::Transport* transport)
    {
        transport_ = transport;
    }

    void catalyticReactorsEquations::setKineticType(const std::string type)
    {
        type_ = type;
    }

    void catalyticReactorsEquations::setAsaliKinetic(ASALI::pythonInterface* pi, const std::vector<int> canteraIndex, const std::vector<std::string> n)
    {
        pi_           = pi;
        canteraIndex_ = canteraIndex;
        n_            = n;
    }

    void catalyticReactorsEquations::turnOnUserDefined(const bool check)
    {
        userCheck_ = check;
    }
    
    
    void catalyticReactorsEquations::set_MW(const std::vector<double> MW)
    {
        MW_ = MW;
    }

    void catalyticReactorsEquations::set_diff(const std::vector<double> diff)
    {
        diff_ = diff;
    }

    void catalyticReactorsEquations::set_QfromSurface(const std::vector<double> Q)
    {
        QuserHet_ = Q;
    }

    void catalyticReactorsEquations::set_QfromGas(const std::vector<double> Q)
    {
        QuserHom_ = Q;
    }

    void catalyticReactorsEquations::set_cp(const double cp)
    {
        cp_ = cp;
    }

    void catalyticReactorsEquations::set_mu(const double mu)
    {
        mu_ = mu;
    }

    void catalyticReactorsEquations::set_cond(const double cond)
    {
        cond_ = cond;
    }

    std::vector<double> catalyticReactorsEquations::reactionRate(const std::vector<double> x,const double T,const std::string type)
    {
        std::vector<double> R;
        pi_->setTemperature(T);
        pi_->setMoleFraction(x,n_);
        if ( type == "heterogeneous" )
        {
            pi_->runHeterogeneous();
            R = pi_->getHetReactionRate();
        }
        else if ( type == "homogeneous" )
        {
            pi_->runHomogeneous();
            R = pi_->getHomReactionRate();
        }
        return R;
    }

    double catalyticReactorsEquations::heatOfReaction(const std::vector<double> x,const double T, const std::vector<double> h,const std::string type)
    {
        double Q = 0;
        pi_->setTemperature(T);
        pi_->setMoleFraction(x,n_);

        if ( type == "heterogeneous" )
        {
            if ( userCheck_ == false )
            {
                pi_->runAllHeterogeneous();
                std::vector<std::vector<double> > R = pi_->getAllHetReactionRate();
                for (unsigned int i=0;i<NC_;i++)
                {
                    double Rtot = 0;
                    for (unsigned int j=0;j<pi_->getNumberOfHetReactions();j++)
                    {
                        Rtot = Rtot + R[j][i];
                    }
                    Q = Q + Rtot*h[i];
                }
            }
            else
            {
                pi_->runNetHeterogeneous();
                std::vector<double> R = pi_->getHetNetRate();
                for (unsigned int j=0;j<R.size();j++)
                {
                    Q = Q + R[j]*QuserHet_[j];
                }
            }
        }
        else if ( type == "homogeneous" )
        {
            if ( userCheck_ == false )
            {
                pi_->runAllHomogeneous();
                std::vector<std::vector<double> > R = pi_->getAllHomReactionRate();
                for (unsigned int i=0;i<NC_;i++)
                {
                    double Rtot = 0;
                    for (unsigned int j=0;j<pi_->getNumberOfHomReactions();j++)
                    {
                        Rtot = Rtot + R[j][i];
                    }
                    Q = Q + Rtot*h[i];
                }
            }
            else
            {
                pi_->runNetHomogeneous();
                std::vector<double> R = pi_->getHomNetRate();
                for (unsigned int j=0;j<R.size();j++)
                {
                    Q = Q + R[j]*QuserHom_[j];
                }
            }
        }

        return -Q;
    }

    double catalyticReactorsEquations::meanMolecularWeight(const std::vector<double> omega,const std::vector<double> MW)
    {
        double MWmix = 0.;
        for (unsigned int i=0;i<NC_;i++)
        {
            MWmix = MWmix + omega[i]/MW[i];
        }
        return 1./MWmix;
    }
    
    std::vector<double> catalyticReactorsEquations::moleFraction(const std::vector<double> omega,const std::vector<double> MW, double MWmix)
    {
        std::vector<double> x = omega;
        
        for (unsigned int i=0;i<NC_;i++)
        {
            x[i] = omega[i]*MWmix/MW[i];
        }
        
        return x;
    }

    void catalyticReactorsEquations::resize() {}
    
    void catalyticReactorsEquations::store(const double tf,const std::vector<double> xf) {}

    int catalyticReactorsEquations::Equations(double& t, std::vector<double>& y, std::vector<double>& dy) {return 0;}
}
