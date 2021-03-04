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

#ifndef ASALIINTERFACE_H
#define ASALIINTERFACE_H
#include "backend/basicInterface.hpp"
#include "Asali.hpp"

namespace ASALI
{
    /// Class to estimate gas mixture properties using ASALI/API
    class asaliInterface : public ASALI::basicInterface
    {
    public:
        /// Class constructor
        asaliInterface();

        /// Set temperature in [K]
        void setTemperature(const double T);
        
        /// Set pressure in [Pa]
        void setPressure(const double p);

        /// Set mass fraction
        void setMoleFraction(const std::vector<double> x, const std::vector<std::string> name);
        
        /// Set mole fraction
        void setMassFraction(const std::vector<double> y, const std::vector<std::string> name);
        
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
        
        /// Check single species name
        int checkNames(std::string name);
        
        /// Return number of gas species in the gas mixture
        unsigned int numberOfGasSpecies();
        
        /// Return number of coverage species
        unsigned int numberOfSurfaceSpecies();

        /// Class destructor
        ~asaliInterface();

    private:
        ASALI::Asali *asali_;            /// ASALI/API object
        std::vector<std::string> names_; /// Gas species names in the ASALI/API database
    };
}

#endif
