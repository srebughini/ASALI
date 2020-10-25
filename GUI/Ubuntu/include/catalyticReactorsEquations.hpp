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

#ifndef CATALYTICREACTORSEQUATIONS_H
#define CATALYTICREACTORSEQUATIONS_H

#include "pythonInterface.hpp"
#include <gtkmm.h>
#include "cantera/Interface.h"
#include "cantera/thermo.h"
#include "cantera/transport.h"
#include "cantera/kinetics.h"

namespace ASALI
{
class catalyticReactorsEquations
{
    public:
        catalyticReactorsEquations();

        #include "shared/Vector.H"

        void setCanteraThermo(Cantera::ThermoPhase*    gas);
        
        void setCanteraInterface(Cantera::Interface*   surface);
        
        void setCanteraKinetics(Cantera::Kinetics*    kinetic);
        
        void setCanteraTransport(Cantera::Transport*    transport);

        void setHomogeneousReactions(const bool flag)   {homogeneousReactions_  = flag;}

        void setHeterogeneusReactions(const bool flag)  {heterogeneusReactions_ = flag;}

        void setAsaliKinetic(ASALI::pythonInterface* pi, const std::vector<int> canteraIndex, const std::vector<std::string> n);

        void setKineticType(const std::string type);
        
        void turnOnUserDefined(const bool check);

        void set_QfromSurface(const std::vector<double> Q);
        
        void set_QfromGas(const std::vector<double> Q);
        
        void set_MW(const std::vector<double> MW);
        
        void set_diff(const std::vector<double> diff);
        
        void set_cp(const double cp);
        
        void set_cond(const double cond);
        
        void set_mu(const double mu);

        unsigned int NumberOfEquations()     const {return NE_;};

        virtual int Equations(double& t, std::vector<double>& y, std::vector<double>& dy);
        
        virtual void resize();
        
        virtual void store(const double tf,const std::vector<double> xf);

        double cp_;
        double mu_;
        double cond_;

        unsigned int NE_;
        unsigned int NC_;
        
        std::string type_;

        bool homogeneousReactions_ ;
        bool heterogeneusReactions_;
        bool userCheck_;

        Cantera::ThermoPhase*   gas_;
        Cantera::Interface*     surface_;
        Cantera::Kinetics*      kinetic_;
        Cantera::Transport*     transport_;
        ASALI::pythonInterface* pi_;

        std::vector<double>      QuserHom_;
        std::vector<double>      QuserHet_;
        std::vector<double>      MW_;
        std::vector<double>      diff_;
        
        std::vector<int>         canteraIndex_;
        
        std::vector<std::string> n_;

        std::vector<double> reactionRate(const std::vector<double> omega,const double T, const std::string type);
        std::vector<double> moleFraction(const std::vector<double> omega,const std::vector<double> MW, double MWmix);
        double              heatOfReaction(const std::vector<double> omega,const double T, const std::vector<double> h, const std::string type);
        double              meanMolecularWeight(const std::vector<double> omega,const std::vector<double> MW);
    };
}

#endif
