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

#ifndef HET1DEQUATIONS_H
#define HET1DEQUATIONS_H

#include "catalyticReactorsEquations.hpp"

namespace ASALI
{
class het1dEquations : public ASALI::catalyticReactorsEquations
{
    public:
        het1dEquations();

        void setEnergy(const bool flag)                 {energyEquation_        = flag;}

        void setLength(const double L);
        
        void setSpecificMassFlowRate(const double G);
        
        void setPressure(const double P);

        void setCatalystProperties(const double alfa, const double rhos, const double cps, const double conds);

        void setInert(const unsigned int inertIndex);

        void setInletConditions(const std::vector<double> omega0, const double T0);
        
        void setIntegrationTime(const double tF);
        
        void setNumberOfPoints(const double NP);
        
        void setReactorType(const std::string reactorType);
        
        void setResolutionType(const std::string resolution);
        
        void setPackedBed(const double Dt,const double Dp, const double epsi);
        
        void setTubular(const double Dt,const double tw, const std::string section);
        
        void setHoneyComb(const double cpsi, const double tw, const std::string section);

        std::vector<double> getLength()          const {return Length_;};
        std::vector<double> getTime()            const {return Time_;};

        std::vector<std::vector<double> > getBulkTemperature() const {return TemperatureB_;};
        std::vector<std::vector<double> > getWallTemperature() const {return TemperatureW_;};

        std::vector<std::vector<std::vector<double> > > getBulkSpecie()      const {return SpecieB_;};
        std::vector<std::vector<std::vector<double> > > getWallSpecie()      const {return SpecieW_;};
        std::vector<std::vector<std::vector<double> > > getSite()            const {return Site_;};

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
        double Dp_;
        double Dt_;
        double epsi_;
        double Shinf_;
        double Nuinf_;
        double av_;
        double rhos_;
        double cps_;
        double conds_;
        double kHeat_;
        
        unsigned int SURF_NC_;
        unsigned int NP_;
        unsigned int inertIndex_;

        std::string reactorType_;
        std::string resolution_;

        bool energyEquation_;

        std::vector<double> omega_;
        std::vector<double> x_;
        std::vector<double> z_;
        std::vector<double> kMat_;
        std::vector<double> RfromGas_;
        std::vector<double> RfromSurface_;
        std::vector<double> Z_;
        std::vector<double> Rsurface_;
        std::vector<double> dy_;
        std::vector<double> y_;
        std::vector<double> h_;
        std::vector<double> omega0_;
        std::vector<double> kHeatVector_;
        std::vector<double> TBvector_;
        std::vector<double> TWvector_;
        std::vector<double> rhoVector_;
        std::vector<double> cpVector_;
        std::vector<double> condVector_;
        std::vector<double> QfromGasVector_;
        std::vector<double> QfromSurfaceVector_;

        std::vector<std::vector<double> > omegaBMatrix_;
        std::vector<std::vector<double> > omegaWMatrix_;
        std::vector<std::vector<double> > Zmatrix_;
        std::vector<std::vector<double> > diffMatrix_;
        std::vector<std::vector<double> > RfromGasMatrix_;
        std::vector<std::vector<double> > kMatMatrix_;
        std::vector<std::vector<double> > RfromSurfaceMatrix_;
        std::vector<std::vector<double> > RsurfaceMatrix_;

        std::vector<double> massTransferCoefficient(const double z, const double mu, const double rho, const std::vector<double> d);
        double              heatTransferCoefficient(const double z, const double mu, const double cond, const double cp);

        std::vector<double> Length_;
        std::vector<double> Time_;
        std::vector<double> Pressure_;
        std::vector<std::vector<double> > TemperatureB_;
        std::vector<std::vector<double> > TemperatureW_;
        std::vector<std::vector<std::vector<double> > > SpecieB_;
        std::vector<std::vector<std::vector<double> > > SpecieW_;
        std::vector<std::vector<std::vector<double> > > Site_;

        std::vector<bool>   algb_;
    };
}

#endif
