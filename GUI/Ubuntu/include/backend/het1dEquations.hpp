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

#include "backend/catalyticReactorsEquations.hpp"

namespace ASALI
{
    /// Class that describes 1D PFR heterogeneous reactor equations
    class het1dEquations : public ASALI::catalyticReactorsEquations
    {
    public:
        /// Class constructor
        het1dEquations();

        /// Enable/disable energy balance
        void setEnergy(const bool flag);

        /// Set reactor length in [m]
        void setLength(const double L);

        /// Set specific mass flow rate in [kg/m2/s]
        void setSpecificMassFlowRate(const double G);

        /// Set pressure in [Pa]
        void setPressure(const double P);

        /// Set catalyst properties: catalyst load in [m3/m2], catalyst density in [kg/m3], catalyst specific heat in [J/kg/K], catalyst thermal conducivity [W/m2/K]
        void setCatalystProperties(const double alfa, const double rhos, const double cps, const double conds);

        /// Set inert specie index
        void setInert(const unsigned int inertIndex);

        /// Set reactor inlet conditions: mass fraction and temperature in [K]
        void setInletConditions(const std::vector<double> omega0, const double T0);

        /// Set integration time in [s]
        void setIntegrationTime(const double tF);

        /// Set number of discretization points
        void setNumberOfPoints(const double NP);

        /// Set reactor type model
        void setReactorType(const std::string reactorType);

        /// Set resolution method
        void setResolutionType(const std::string resolution);

        /// Set packed bed reactor: tube diameter in [m], particle diameter [m], void fraction
        void setPackedBed(const double Dt, const double Dp, const double epsi);

        /// Set tubular reactor: tube diameter in [m], wall thickness [m], section shape
        void setTubular(const double Dt, const double tw, const std::string section);

        /// Set honeycomb reactor: CPSI, wall thickness [m], section shape
        void setHoneyComb(const double cpsi, const double tw, const std::string section);

        /// Return discretized reactor length [m]
        inline std::vector<double> getLength() const { return Length_; };

        /// Return integration time vector in [s]
        inline std::vector<double> getTime() const { return Time_; };

        /// Return gas temperature at different integration times in [K]
        inline std::vector<std::vector<double>> getBulkTemperature() const { return TemperatureB_; };

        /// Return catalyst temperature at different integration times in [K]
        inline std::vector<std::vector<double>> getWallTemperature() const { return TemperatureW_; };

        /// Return gas mixture mass fraction in the gas phase at different integration times
        inline std::vector<std::vector<std::vector<double>>> getBulkSpecie() const { return SpecieB_; };

        /// Return gas mixture mass fraction near the catalyst at different integration times
        inline std::vector<std::vector<std::vector<double>>> getWallSpecie() const { return SpecieW_; };

        /// Return coverage at different integration times
        inline std::vector<std::vector<std::vector<double>>> getSite() const { return Site_; };

        /// Equations describing the catalytic reactors
        int Equations(double &t, std::vector<double> &y, std::vector<double> &dy);

        /// Resize variables based
        void resize();

        /// Store results for plottnig and saving
        void store(const double tf, const std::vector<double> xf);

        /// Return algebraic equations flags
        std::vector<bool> AlgebraicEquations() const { return algb_; };

    private:
        double MWmix_; /// Gas mixture molecular weight in [g/mol]
        double cTot_;  /// Gas mixture concentration in [kmol/m3]
        double rho_;   /// Gas mixture density in [kg/m3]
        double T0_;    /// Gas mixture initial temperature in [K]
        double L_;     /// Reactor length in [m]
        double G_;     /// Specific mass flow rate [kg/m2/s]
        double dz_;    /// Discretization step for length [m]
        double Dp_;    /// Particle diameter [m]
        double Dt_;    /// Tube diameter [m]
        double epsi_;  /// Void fraction
        double Shinf_; /// Sherwood number
        double Nuinf_; /// Nusselt number
        double av_;    /// Reactor specific area [m2/m3]
        double rhos_;  /// Catalyst density [kg/m3]
        double cps_;   /// Catalyst specific heat [J/kg/K]
        double conds_; /// Catalyst thermal conductivity [W/m/K]
        double kHeat_; /// Heat transfer coefficient

        unsigned int NP_;         /// Number of discretization points
        unsigned int inertIndex_; /// Inert specie index

        std::string reactorType_; /// Reactor type
        std::string resolution_;  /// Resolution method

        std::vector<double> z_;                  /// Discretized length
        std::vector<double> kMat_;               /// Mass transfer coefficient
        std::vector<double> dy_;                 /// Accumulation term of mass and energy balance
        std::vector<double> y_;                  /// Integration variables
        std::vector<double> omega0_;             /// Initial mass fraction
        std::vector<double> kHeatVector_;        /// Heat transfer coefficient
        std::vector<double> TBvector_;           /// Gas temperature in [K]
        std::vector<double> TWvector_;           /// Catalyst temperature in [K]
        std::vector<double> rhoVector_;          /// Gas density in [kg/m3]
        std::vector<double> cpVector_;           /// Gas specific heat in [J/kg/K]
        std::vector<double> condVector_;         /// Gas thermal conductivity in [W/m2/K]
        std::vector<double> QfromGasVector_;     /// Homogeneous heat of reactions in [W/m3]
        std::vector<double> QfromSurfaceVector_; /// Heterogeneous heat of reactions in [W/m2]
        std::vector<double> Length_;             /// Discretized reactor length in [m]
        std::vector<double> Time_;               /// Integration time vector [s]
        std::vector<double> Pressure_;           /// Pressure at different integration times in [Pa]

        std::vector<bool> algb_; /// Algebraic equations flags

        std::vector<std::vector<double>> omegaBMatrix_;       /// Mass fraction in the gas phase
        std::vector<std::vector<double>> omegaWMatrix_;       /// Mole fraction on the catalyst
        std::vector<std::vector<double>> Zmatrix_;            /// Coverage
        std::vector<std::vector<double>> diffMatrix_;         /// Mixture diffusion coefficients in [m2/s]
        std::vector<std::vector<double>> RfromGasMatrix_;     /// Species homogeneous reactions in [kg/m3/s]
        std::vector<std::vector<double>> kMatMatrix_;         /// Heat transfer coefficient
        std::vector<std::vector<double>> RfromSurfaceMatrix_; /// Species heterogeneous reactions in [kg/m2/s]
        std::vector<std::vector<double>> RsurfaceMatrix_;     /// Coverage heterogeneous reactions in [kg/m2/s]
        std::vector<std::vector<double>> TemperatureB_;       /// Gas phase temperature at different integration times in [K]
        std::vector<std::vector<double>> TemperatureW_;       /// Catalyst temperature at different integration times in [K]

        std::vector<std::vector<std::vector<double>>> SpecieB_; /// Gas phase mass fraction at different integration time
        std::vector<std::vector<std::vector<double>>> SpecieW_; /// Catalyst phase mass fraction at different integration time
        std::vector<std::vector<std::vector<double>>> Site_;    /// Coverage at different integration time

        /// Estimate mass transfer coefficient from: distance from reactor inlet in [m], viscosity [Pas], density [kg/m3], diffusivity [m2/s]
        std::vector<double> massTransferCoefficient(const double z, const double mu, const double rho, const std::vector<double> d);

        /// Estimate heat transfer coefficient from: distance from reactor inlet in [m], viscosity [Pas], thermal condutivity [W/m2/K], specific heat [J/kg/K]
        double heatTransferCoefficient(const double z, const double mu, const double cond, const double cp);
    };
}
#endif
