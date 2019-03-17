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
#   Department of Energy                                                                       #
#   Politecnico di Milano                                                                      #
#   Author: Stefano Rebughini <stefano.rebughini@polimi.it>                                    #
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

#ifndef CATALYTICPELLETEQUATIONS_H
#define CATALYTICPELLETEQUATIONS_H

#include <gtkmm.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctime>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <limits>
#include <Eigen/Dense>

// Cantera
#include "cantera/Interface.h"
#include "cantera/thermo.h"
#include "cantera/transport.h"
#include "cantera/kinetics.h"

namespace ASALI
{
class catalyticPelletEquations
{
    public:

        catalyticPelletEquations();

        #include "Vector.H"

        void setCanteraThermo(Cantera::ThermoPhase*    gas);
        
        void setCanteraInterface(Cantera::Interface*   surface);
        
        void setCanteraKinetics(Cantera::Kinetics*     kinetic);
        
        void setCanteraTransport(Cantera::Transport*   transport);

        void setHeterogeneusReactions(const bool flag)  {heterogeneusReactions_ = flag;}
        
        void setHomogeneousReactions(const bool flag)   {homogeneousReactions_ = flag;}

        void setAsaliKinetic(const unsigned int                           NR,
                             const std::vector<double>                    k,
                             const std::vector<double>                    Eatt,
                             const std::vector<double>                    n,
                             const std::vector<double>                    a,
                             const std::vector<double>                    b,
                             const std::vector<int>                       index1,
                             const std::vector<int>                       index2,
                             const std::vector<int>                       canteraIndex,
                             const std::vector<std::vector<std::string> > name,
                             const std::vector<std::vector<int> >         stoich,
                             const double converter);

        void setPressure(const double P);
        
        void setTemperature(const double T);

        void setCatalystProperties(const double alfa,const double tau,const double epsi);
        
        void setReductionCoefficient(const double rc);
        
        void setKineticType(const std::string type);
        
        void turnOnUserDefined(const bool check);
        
        void setInert(const unsigned int inertIndex);

        void set_MW(const std::vector<double> MW);
        
        void set_diff(const std::vector<double> diff);

        void setInletConditions(const std::vector<double> omega0);
        
        void setIntegrationTime(const double tF);
        
        void setNumberOfPoints(const double NP);
        
        void setPelletType(const std::string pelletType);
        
        void setDiffusionModel(const std::string modelType);
        
        void setResolutionType(const std::string resolution);
        
        void setSlab(const double tw);
        
        void setSphere(const double D);
        
        void setCylinder(const double D);
        
        void resize();
        
        void store(const double tf,const std::vector<double> xf);

        std::vector<double> getTime()            const {return Time_;};

        std::vector<std::vector<std::vector<double> > > getSpecie()      const {return Specie_;};
        std::vector<std::vector<std::vector<double> > > getSite()        const {return Site_;};

        unsigned int NumberOfEquations()     const {return NE_;};

        int Equations(double& t, std::vector<double>& y, std::vector<double>& dy);
        
        std::vector<bool> AlgebraicEquations() const {return algb_;};

        double getLength();

    private:

        double MWmix_;
        double cTot_;
        double rho_;
        double P_;
        double T_;
        double L_;
        double alfa_;
        double SD_;
        double dz_;
        double D_;
        double r_;
        double epsi_;
        double tau_;
        double tw_;
        double rc_;
        
        unsigned int NC_;
        unsigned int SURF_NC_;
        unsigned int NE_;
        unsigned int NP_;
        unsigned int inertIndex_;

        std::string type_;
        std::string pelletType_;
        std::string modelType_;
        std::string resolution_;

        bool heterogeneusReactions_;
        bool homogeneousReactions_;
        bool userCheck_;

        Cantera::ThermoPhase*  gas_;
        Cantera::Interface*    surface_;
        Cantera::Kinetics*     kinetic_;
        Cantera::Transport*    transport_;

        std::vector<double> omega_;
        std::vector<double> x_;
        std::vector<double> z_;
        std::vector<double> MW_;
        std::vector<double> RfromSurface_;
        std::vector<double> RfromGas_;
        std::vector<double> Z_;
        std::vector<double> Rsurface_;
        std::vector<double> dy_;
        std::vector<double> y_;
        std::vector<double> diff_;
        std::vector<double> omega0_;
        std::vector<double> rhoVector_;

        std::vector<std::vector<double> > omegaMatrix_;
        std::vector<std::vector<double> > xMatrix_;
        std::vector<std::vector<double> > Zmatrix_;
        std::vector<std::vector<double> > diffMatrix_;
        std::vector<std::vector<double> > fluxMatrix_;
        std::vector<std::vector<double> > RfromSurfaceMatrix_;
        std::vector<std::vector<double> > RfromGasMatrix_;
        std::vector<std::vector<double> > RsurfaceMatrix_;
        std::vector<std::vector<double> > MwMatrix_;

        unsigned int                           NR_;
        std::vector<double>                    k_;
        std::vector<double>                    Eatt_;
        std::vector<double>                    n_;
        std::vector<double>                    a_;
        std::vector<double>                    b_;
        std::vector<int>                       index1_;
        std::vector<int>                       index2_;
        std::vector<int>                       canteraIndex_;
        std::vector<std::vector<std::string> > name_;
        std::vector<std::vector<int> >         stoich_;
        double                                 converter_;
        
        std::vector<double>               reactionRate(const double T, const std::vector<double> omega,const double rho);
        std::vector<double>               fromMassToMoleFraction(const std::vector<double> omega,const std::vector<double> MW);
        std::vector<std::vector<double> > epsi_tau_model(const std::vector<std::vector<double> > diff,const std::vector<std::vector<double> > omega);
        std::vector<std::vector<double> > reduction_coefficient_model(const std::vector<std::vector<double> > diff,const std::vector<std::vector<double> > omega);
        double                            meanMolecularWeight(const std::vector<double> omega,const std::vector<double> MW);
        void                              properties(std::vector<double>& y);
        void                              slabOde(std::vector<double>& dy);
        void                              slab(std::vector<double>& dy);
        void                              sphereOde(std::vector<double>& dy);
        void                              sphere(std::vector<double>& dy);
        void                              cylinderOde(std::vector<double>& dy);
        void                              cylinder(std::vector<double>& dy);


        std::vector<double> Length_;
        std::vector<double> Time_;
        std::vector<std::vector<std::vector<double> > > Specie_;
        std::vector<std::vector<std::vector<double> > > Site_;

        std::vector<bool>   algb_;
    };
}

#endif
