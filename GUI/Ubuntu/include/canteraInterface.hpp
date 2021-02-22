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

#ifndef CANTERAINTERFACE_H
#define CANTERAINTERFACE_H
#include "cantera/thermo.h"
#include "cantera/transport.h"
#include "cantera/kinetics.h"
#include "cantera/transport/TransportData.h"
#include "basicInterface.hpp"

namespace ASALI
{
    class canteraInterface : public ASALI::basicInterface
    {
        public:
            canteraInterface(Cantera::ThermoPhase* thermo,
                             Cantera::Transport*   transport,
                             Cantera::Kinetics*    kinetic,
                             Cantera::ThermoPhase* surface,
                             Cantera::Kinetics*    surface_kinetic);

            virtual void setMoleFraction(const std::vector<double> x,const std::vector<std::string> name);
            virtual void setMassFraction(const std::vector<double> y,const std::vector<std::string> name);
            virtual void thermoCalculate();
            virtual void transportCalculate();
            virtual void vacuumCalculate();
            virtual void calculateHomogeneousReactions(std::vector<double> omega, double T, double P);
            virtual void equilibriumCalculate(std::string type);
            virtual void setStateFromMassFraction(double* y, double T, double p);
            virtual void setStateFromMoleFraction(double* x, double T, double p);

            virtual double temperature();
            virtual double density();
            virtual double getCpMassMix();
            virtual double getCpMoleMix();
            virtual double getMWmix();

            virtual std::vector<double> getMW();
            virtual std::vector<double> getHmole();
            virtual std::vector<double> getSmole();
            virtual std::vector<double> getCpMole();

            virtual std::vector<int>  checkNames(std::vector<std::string>& name);
            virtual int               checkNames(std::string name);
            virtual unsigned int      numberOfGasSpecies();
            virtual unsigned int      numberOfSurfaceSpecies();

            virtual ~canteraInterface();
            
        private:

            Cantera::ThermoPhase* thermo_;
            Cantera::Transport*   transport_;
            Cantera::Kinetics*    kinetic_;
            Cantera::ThermoPhase* surface_;
            Cantera::Kinetics*    surface_kinetic_;
    };
}

#endif
