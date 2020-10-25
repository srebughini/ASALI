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

#ifndef PH1DEQUATIONS_H
#define PH1DEQUATIONS_H

#include "catalyticReactorsEquations.hpp"

namespace ASALI
{
class ph1dEquations : public ASALI::catalyticReactorsEquations
{
    public:
        ph1dEquations();

       
        void setEnergy(const bool flag)                 {energyEquation_        = flag;}

        void setLength(const double L);
        
        void setSpecificMassFlowRate(const double G);


        void setPressure(const double P);

        void setTemperature(const double T);
        
        void setCatalystLoad(const double alfa);
        
        void setResolutionType(const std::string resolution);

        void setInletConditions(const std::vector<double> omega0, const double T0);
        
        void setIntegrationTime(const double tF);
        
        void setNumberOfPoints(const double NP);

        std::vector<double> getLength()      const {return Length_;};
        std::vector<double> getTime()        const {return Time_;};
        std::vector<double> getPressure()    const {return Pressure_;};
        std::vector<double> getTemperature() const {return Temperature_;};

        std::vector<std::vector<double> > getSpecie()      const {return Specie_;};
        std::vector<std::vector<double> > getSite()        const {return Site_;};

        std::vector<std::vector<double> > getTemperatureTransient() const {return TemperatureTransient_;};

        std::vector<std::vector<std::vector<double> > > getSpecieTransient()      const {return SpecieTransient_;};
        std::vector<std::vector<std::vector<double> > > getSiteTransient()        const {return SiteTransient_;};

        virtual void store(const double tf, const std::vector<double> xf);

        virtual void resize();

        virtual int Equations(double& t, std::vector<double>& y, std::vector<double>& dy);
        
        std::vector<bool> AlgebraicEquations() const {return algb_;};

    private:
        double MWmix_;
        double cTot_;
        double rho_;
        double P_;
        double T_;
        double L_;
        double G_;
        double alfa_;
        double QfromGas_;
        double QfromSurface_;
        double SD_;
        double T0_;
        double dz_;
        
        unsigned int SURF_NC_;
        unsigned int NP_;

        std::string resolution_;

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
        std::vector<double> omega0_;
        std::vector<double> Tvector_;
        std::vector<double> rhoVector_;
        std::vector<double> cpVector_;
        std::vector<double> condVector_;
        std::vector<double> QfromGasVector_;
        std::vector<double> QfromSurfaceVector_;

        std::vector<std::vector<double> > omegaMatrix_;
        std::vector<std::vector<double> > Zmatrix_;
        std::vector<std::vector<double> > diffMatrix_;
        std::vector<std::vector<double> > RfromGasMatrix_;
        std::vector<std::vector<double> > RfromSurfaceMatrix_;
        std::vector<std::vector<double> > RsurfaceMatrix_;

        std::vector<double> Length_;
        std::vector<double> Time_;
        std::vector<double> Pressure_;
        std::vector<double> Temperature_;
        std::vector<std::vector<double> > Specie_;
        std::vector<std::vector<double> > Site_;

        std::vector<std::vector<double> > TemperatureTransient_;
        std::vector<std::vector<std::vector<double> > > SpecieTransient_;
        std::vector<std::vector<std::vector<double> > > SiteTransient_;

        std::vector<bool>   algb_;
    };
}

#endif
