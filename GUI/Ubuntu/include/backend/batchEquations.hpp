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

#include "backend/catalyticReactorsEquations.hpp"

namespace ASALI
{
    /// Class that describes BATCH reactor equations
    class batchEquations : public ASALI::catalyticReactorsEquations
    {
    public:
        /// Class constructor
        batchEquations();

        /// Enable/disable energy balance
        void setEnergy(const bool flag);

        /// Set reactor volume in [m3]
        void setVolume(const double V);

        /// Set pressure in [Pa]
        void setPressure(const double P);

        /// Set temperature in [K]
        void setTemperature(const double T);

        /// Set catalytic load in [m2/m3]
        void setCatalystLoad(const double alfa);

        /// Set integration time in [s]
        void setIntegrationTime(const double tF);

        /// Return integration time vector in [s]
        inline std::vector<double> getTime() const { return Time_; };
        
        /// Return total mass at different integration times in [kg]
        inline std::vector<double> getMass() const { return Mass_; };
        
        /// Return total volume at different integration times in [m3]
        inline std::vector<double> getVolume() const { return Volume_; };
        
        /// Return temperature at different integration times in [K]
        inline std::vector<double> getTemperature() const { return Temperature_; };

        /// Return gas mixture mass fraction at different integration times
        inline std::vector<std::vector<double>> getSpecie() const { return Specie_; };
        
        /// Return coverage at different integration times
        inline std::vector<std::vector<double>> getSite() const { return Site_; };

        /// Equations describing the catalytic reactors
        int Equations(double &t, std::vector<double> &y, std::vector<double> &dy);

        /// Resize variables based
        void resize();

        /// Store results for plottnig and saving
        void store(const double tf, const std::vector<double> xf);

        /// Class destructor
        ~batchEquations();

    private:
        double MWmix_;        /// Gas mixture molecular weight in [g/mol]
        double cTot_;         /// Gas mixture concentration in [kmol/m3]
        double rho_;          /// Gas mixture density in [kg/m3]
        double P_;            /// Gas mixture pressure in [Pa]
        double T_;            /// Gas mixture temperature in [K]
        double V_;            /// Reactor volume in [m3]
        double alfa_;         /// Catalytic load in [m2/m3]
        double mass_;         /// Total mass in [kg]
        double QfromGas_;     /// Homogeneous heat of reactions in [W/m3]
        double QfromSurface_; /// Heterogeneous heat of reactions in [W/m2]
        double SD_;           /// Site density in [1/m2]
        double dt_;           /// Integration time step [s]

        unsigned int SURF_NC_; /// Number of coverage species
        unsigned int TC_;      /// Number of integration steps

        bool energyEquation_;  /// Bool to enable/disable energy balance

        std::vector<double> omega_;         /// Mass fraction
        std::vector<double> x_;             /// Mole fraction
        std::vector<double> RfromGas_;      /// Species homogeneous reactions in [kg/m3/s]
        std::vector<double> RfromSurface_;  /// Species heterogeneous reactions in [kg/m2/s]
        std::vector<double> Z_;             /// Coverage
        std::vector<double> Rsurface_;      /// Coverage heterogeneous reactions in [kg/m2/s]
        std::vector<double> dy_;            /// Accumulation term of mass and energy balance
        std::vector<double> y_;             /// Integration variables
        std::vector<double> h_;             /// Species mass enthalpy in [J/kg]

        std::vector<double> Time_;                /// Integration time vector [s]
        std::vector<double> Mass_;                /// Total mass at different integration times in [kg]
        std::vector<double> Volume_;              /// Total volume at different integration times in [m3]
        std::vector<double> Temperature_;         /// Temperature at different integration times in [K]
        std::vector<std::vector<double>> Specie_; /// Gas mixture mass fraction at different integration times
        std::vector<std::vector<double>> Site_;   /// Coverage at different integration times
    };
}

#endif
