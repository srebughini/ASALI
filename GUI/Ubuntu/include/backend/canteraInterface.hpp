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
#include "cantera/thermo/SurfPhase.h"
#include "cantera/kinetics/InterfaceKinetics.h"
#include "backend/basicInterface.hpp"

namespace ASALI
{
    /// Class to estimate gas mixture properties based on Cantera (https://cantera.org)
    class canteraInterface : public ASALI::basicInterface
    {
    public:
        /// Class constructor
        canteraInterface(std::string filepath,
                         std::string gasPhaseName,
                         std::string surfPhaseName,
                         bool        isKinetic);

        /// Set temperature in [K]
        void setTemperature(const double T);

        /// Set pressure in [Pa]
        void setPressure(const double p);

        /// Set mass fraction
        void setMoleFraction(const std::vector<double> &x, const std::vector<std::string> &name);

        /// Set mole fraction
        void setMassFraction(const std::vector<double> &y, const std::vector<std::string> &name);

        /// Set mass fraction, temperature in [K] and pressure in [Pa]
        void setStateFromMassFraction(const double *y, const double T, const double p);

        /// Set mole fraction, temperature in [K] and pressure in [Pa]
        void setStateFromMoleFraction(const double *x, const double T, const double p);

        /// Calculate thermodynamic properties
        void thermoCalculate();

        /// Calculate transport properties
        void transportCalculate();

        /// Calculate vacuum properties
        void vacuumCalculate();

        /// Get gas mixture temperature in [K]
        double getTemperature();

        /// Get gas mixture density in [kg/m3]
        double getDensity();

        /// Get gas mixture mass specific heat in [J/kg/K]
        double getCpMassMix();

        /// Get gas mixture molar specific heat in [J/kmol/K]
        double getCpMoleMix();

        /// Get gas mixture molecular weight in [g/mol]
        double getMWmix();

        /// Get gas mixture thermal conductivity in [W/m/K]
        double getCondMix();

        /// Get gas mixture viscosity in [Pas]
        double getMuMix();

        /// Get species molecular weight in [g/mol]
        std::vector<double> getMW();

        /// Get species molar enthalpy in [J/kmol]
        std::vector<double> getHmole();

        /// Get species molar entropy in [J/kmol/K]
        std::vector<double> getSmole();

        /// Get species molar specific heat in [J/kmol/K]
        std::vector<double> getCpMole();

        /// Get species mixture diffusion coefficient in [m2/s]
        std::vector<double> getDiffMix();

        /// Get species binary diffusion coefficient in [m2/s] as vector
        std::vector<double> getBinaryDiffVector();

        /// Check species names
        std::vector<int> checkNames(std::vector<std::string> &name);

        /// Return specie index from specie name
        int getSpecieIndex(std::string name);

        /// Check single species name
        int checkNames(std::string name);

        /// Return number of gas species in the gas mixture
        unsigned int numberOfGasSpecies();

        /// Return number of coverage species
        unsigned int numberOfSurfaceSpecies();

        /// Return the flag for surface species and reactions
        bool isSurface();

        /// Return number of homogeneous reactions
        unsigned int numberOfHomogeneousReactions();

        /// Calculate species homogeneous reactions
        void calculateHomogeneousReactions(std::vector<double> omega, double T, double p);

        /// Calculate species heterogeneous reactions
        void calculateHeterogeneousReactions(std::vector<double> omega, std::vector<double> Z, double T, double p);

        /// Calculate chemical equilibrium
        void equilibriumCalculate(std::string type);

        /// Convert double* to std::vector<double>
        static std::vector<double> doubleVectorToStdVector(double *double_vector, unsigned int vector_size);

        /// Return species homogeneous reactions in [kg/m3/s]
        inline std::vector<double> RfromGas() const { return RfromGas_; };

        /// Return species heterogeneous reactions in [kg/m2/s]
        inline std::vector<double> RfromSurface() const { return RfromSurface_; };

        /// Return coverage reactions in [kg/m2/s]
        inline std::vector<double> Rsurface() const { return Rsurface_; };

        /// Return homogeneous heat of reactions in [W/m3]
        inline double QfromGas() const { return QfromGas_; };

        /// Return heterogeneous heat of reactions in [W/m2]
        inline double QfromSurface() const { return QfromSurface_; };

        /// Return site density in [1/m2]
        inline double siteDensity() const { return SD_; };

    private:
        Cantera::ThermoPhase *thermo_;                                /// Cantera library thermo phase pointer
        Cantera::Transport *transport_;                               /// Cantera library transport phase pointer
        std::shared_ptr<Cantera::Kinetics> kinetic_;                  /// Cantera library homogeneous kinetic pointer
        std::shared_ptr<Cantera::SurfPhase> surface_;                 /// Cantera library surface phase pointer
        std::shared_ptr<Cantera::InterfaceKinetics> surface_kinetic_; /// Cantera library heterogeneous kinetic pointer

        double QfromGas_;     /// Homogeneous heat of reactions in [W/m3]
        double QfromSurface_; /// Heterogeneous heat of reactions in [W/m2]
        double SD_;           /// Site density in [1/m2]

        std::vector<double> RfromGas_;     /// Species homogeneous reactions in [kg/m3/s]
        std::vector<double> RfromSurface_; /// Species heterogeneous reactions in [kg/m2/s]
        std::vector<double> Rsurface_;     /// Coverage reactions in [kg/m2/s]

        bool is_surface_; /// Flag that enable surface species
    };
}
#endif
