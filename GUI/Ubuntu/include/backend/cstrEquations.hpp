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

#ifndef CSTREQUATIONS_H
#define CSTREQUATIONS_H

#include "backend/catalyticReactorsEquations.hpp"

namespace ASALI
{
    /// Class that describes CSTR reactor equations
    class cstrEquations : public ASALI::catalyticReactorsEquations
    {
    public:
        /// Class constructor
        cstrEquations();

        /// Enable/disable energy balance
        void setEnergy(const bool flag);

        /// Set reactor volume in [m3]
        void setVolume(const double V);

        /// Set reactor inlet flow rate in [kg/s]
        void setFlow(const double Q);

        /// Set pressure in [Pa]
        void setPressure(const double P);

        /// Set temperature in [K]
        void setTemperature(const double T);

        /// Set catalytic load in [m2/m3]
        void setCatalystLoad(const double alfa);

        /// Set integration time in [s]
        void setIntegrationTime(const double tF);

        /// Set reactor inlet conditions: mass fraction and temperature in [K]
        void setInletConditions(const std::vector<double> omega0, const double T0);

        /// Return integration time vector in [s]
        inline std::vector<double> getTime() const { return Time_; };

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

    private:
        double MWmix_; /// Gas mixture molecular weight in [g/mol]
        double cTot_;  /// Gas mixture concentration in [kmol/m3]
        double rho_;   /// Gas mixture density in [kg/m3]
        double T0_;    /// Gas mixture initial temperature in [K]
        double V_;     /// Reactor volume in [m3]
        double mass_;  /// Total mass in [kg]
        double Q_;     /// Inlet mass flow rate [kg/s]
        double dt_;    /// Integration time step [s]

        unsigned int TC_; /// Number of integration steps

        std::vector<double> omega0_; /// Initial mass fraction
        std::vector<double> dy_;     /// Accumulation term of mass and energy balance
        std::vector<double> y_;      /// Integration variables

        std::vector<double> Time_;                /// Integration time vector [s]
        std::vector<double> Temperature_;         /// Temperature at different integration times in [K]
        std::vector<std::vector<double>> Specie_; /// Gas mixture mass fraction at different integration times
        std::vector<std::vector<double>> Site_;   /// Coverage at different integration times
    };
}
#endif
