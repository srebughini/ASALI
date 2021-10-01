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

#include "backend/catalyticReactorsEquations.hpp"

namespace ASALI
{
    /// Class that describes 1D PFR homogeneous reactor equations
    class ph1dEquations : public ASALI::catalyticReactorsEquations
    {
    public:
        /// Class constructor
        ph1dEquations();

        /// Enable/disable energy balance
        void setEnergy(const bool flag) { energyEquation_ = flag; }

        /// Set reactor length in [m]
        void setLength(const double L);

        /// Set specific mass flow rate in [kg/m2/s]
        void setSpecificMassFlowRate(const double G);

        /// Set pressure in [Pa]
        void setPressure(const double P);

        /// Set temperature in [K]
        void setTemperature(const double T);

        /// Set catalyst load in [m3/m2]
        void setCatalystLoad(const double alfa);

        /// Set resolution method
        void setResolutionType(const std::string resolution);

        /// Set reactor inlet conditions: mass fraction and temperature in [K]
        void setInletConditions(const std::vector<double> omega0, const double T0);

        /// Set integration time in [s]
        void setIntegrationTime(const double tF);

        /// Set number of discretization points
        void setNumberOfPoints(const double NP);

        /// Return discretized reactor length [m]
        inline std::vector<double> getLength() const { return Length_; };

        /// Return integration time vector in [s]
        inline std::vector<double> getTime() const { return Time_; };

        /// Return pressure in [Pa]
        inline std::vector<double> getPressure() const { return Pressure_; };

        /// Return temperature in [K]
        inline std::vector<double> getTemperature() const { return Temperature_; };

        /// Return gas mixture mass fraction
        inline std::vector<std::vector<double>> getSpecie() const { return Specie_; };

        /// Return coverage
        inline std::vector<std::vector<double>> getSite() const { return Site_; };

        /// Return temperature at different integration times in [K]
        inline std::vector<std::vector<double>> getTemperatureTransient() const { return TemperatureTransient_; };

        /// Return gas mixture mass fraction at different integration times
        inline std::vector<std::vector<std::vector<double>>> getSpecieTransient() const { return SpecieTransient_; };

        /// Return coverage at different integration times
        inline std::vector<std::vector<std::vector<double>>> getSiteTransient() const { return SiteTransient_; };

        /// Store results for plottnig and saving
        virtual void store(const double tf, const std::vector<double> xf);

        /// Resize variables based
        virtual void resize();

        /// Equations describing the catalytic reactors
        virtual int Equations(double &t, std::vector<double> &y, std::vector<double> &dy);

        /// Return algebraic equations flags
        std::vector<bool> AlgebraicEquations() const { return algb_; };

    private:
        double MWmix_; /// Gas mixture molecular weight in [g/mol]
        double cTot_;  /// Gas mixture concentration in [kmol/m3]
        double rho_;   /// Gas mixture density in [kg/m3]
        double L_;     /// Reactor length in [m]
        double G_;     /// Specific mass flow rate [kg/m2/s]
        double T0_;    /// Gas mixture initial temperature in [K]
        double dz_;    /// Discretization step for length [m]

        unsigned int NP_; /// Number of discretization points

        std::string resolution_; /// Resolution method

        std::vector<double> dy_;                 /// Accumulation term of mass and energy balance
        std::vector<double> y_;                  /// Integration variables
        std::vector<double> omega0_;             /// Initial mass fraction
        std::vector<double> Tvector_;            /// Gas temperature in [K]
        std::vector<double> rhoVector_;          /// Gas density in [kg/m3]
        std::vector<double> cpVector_;           /// Gas specific heat in [J/kg/K]
        std::vector<double> condVector_;         /// Gas thermal conductivity in [W/m2/K]
        std::vector<double> QfromGasVector_;     /// Homogeneous heat of reactions in [W/m3]
        std::vector<double> QfromSurfaceVector_; /// Heterogeneous heat of reactions in [W/m2]
        std::vector<double> Length_;             /// Discretized reactor length in [m]
        std::vector<double> Time_;               /// Integration time vector [s]
        std::vector<double> Pressure_;           /// Pressure [Pa]
        std::vector<double> Temperature_;        /// Temperature [K]

        std::vector<bool> algb_; /// Algebraic equations flags

        std::vector<std::vector<double>> omegaMatrix_;        /// Mass fraction in the gas phase
        std::vector<std::vector<double>> Zmatrix_;            /// Coverage
        std::vector<std::vector<double>> diffMatrix_;         /// Mixture diffusion coefficients in [m2/s]
        std::vector<std::vector<double>> RfromGasMatrix_;     /// Species homogeneous reactions in [kg/m3/s]
        std::vector<std::vector<double>> RfromSurfaceMatrix_; /// Species heterogeneous reactions in [kg/m2/s]
        std::vector<std::vector<double>> RsurfaceMatrix_;     /// Coverage heterogeneous reactions in [kg/m2/s]
        std::vector<std::vector<double>> Specie_;             /// ass fraction in the gas phase
        std::vector<std::vector<double>> Site_;               /// Coverage

        std::vector<std::vector<double>> TemperatureTransient_;         /// Temperature at different integration times in [K]
        std::vector<std::vector<std::vector<double>>> SpecieTransient_; /// Mass fraction at different integration times
        std::vector<std::vector<std::vector<double>>> SiteTransient_;   /// Coverage at different integrations times
    };
}
#endif
