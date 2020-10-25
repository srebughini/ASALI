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

#ifndef BATCHEQUATIONS_H
#define BATCHEQUATIONS_H

#include "catalyticReactorsEquations.hpp"

namespace ASALI
{
class batchEquations : public ASALI::catalyticReactorsEquations
{
    public:
        batchEquations();

        void setEnergy(const bool flag)                 {energyEquation_        = flag;}

        void setVolume(const double V);

        void setPressure(const double P);

        void setTemperature(const double T);
        
        void setCatalystLoad(const double alfa);

        void setIntegrationTime(const double tF);

        std::vector<double> getTime()        const {return Time_;};
        std::vector<double> getMass()        const {return Mass_;};
        std::vector<double> getVolume()      const {return Volume_;};
        std::vector<double> getTemperature() const {return Temperature_;};

        std::vector<std::vector<double> > getSpecie()      const {return Specie_;};
        std::vector<std::vector<double> > getSite()        const {return Site_;};

        virtual void store(const double tf, const std::vector<double> xf);

        virtual void resize();

        virtual int Equations(double& t, std::vector<double>& y, std::vector<double>& dy);

    private:
        double MWmix_;
        double cTot_;
        double rho_;
        double P_;
        double T_;
        double V_;
        double alfa_;
        double mass_;
        double QfromGas_;
        double QfromSurface_;
        double SD_;
        double dt_;
        
        unsigned int SURF_NC_;
        unsigned int TC_;
 
        bool energyEquation_;

        std::vector<double> omega_;
        std::vector<double> x_;
        std::vector<double> RfromGas_;
        std::vector<double> RfromSurface_;
        std::vector<double> Z_;
        std::vector<double> Rsurface_;
        std::vector<double> dy_;
        std::vector<double> y_;
        std::vector<double> h_;

        std::vector<double> Time_;
        std::vector<double> Mass_;
        std::vector<double> Volume_;
        std::vector<double> Temperature_;
        std::vector<std::vector<double> > Specie_;
        std::vector<std::vector<double> > Site_;
    };
}

#endif
