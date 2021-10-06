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

#ifndef CATALYTICPELLETEQUATIONS_H
#define CATALYTICPELLETEQUATIONS_H

#include "catalyticReactorsEquations.hpp"
#include <Eigen/Dense>

namespace ASALI
{
    /// Class that describes CATALYTIC PELLET equations
    class catalyticPelletEquations : public ASALI::catalyticReactorsEquations
    {
    public:
        /// Class constructor
        catalyticPelletEquations();

        /// Set pressure in [Pa]
        void setPressure(const double P);

        /// Set temperature in [K]
        void setTemperature(const double T);

        /// Set catalyst properties: catalytic load in [1/m], catalyst tortuosity, catalyst void fraction
        void setCatalystProperties(const double alfa, const double tau, const double epsi);

        /// Set pore diameter [m]
        void setPoreDiameter(const double dp);

        /// Set inert specie index
        void setInert(const unsigned int inertIndex);

        /// Set reactor inlet conditions: mass fraction
        void setInletConditions(const std::vector<double> &omega0);

        /// Set integration time in [s]
        void setIntegrationTime(const double tF);

        /// Set number of discretization points
        void setNumberOfPoints(const double NP);

        /// Set pellet type
        void setPelletType(const std::string &pelletType);

        /// Set diffusion model
        void setDiffusionModel(const std::string &modelType);

        /// Set resolution type
        void setResolutionType(const std::string &resolution);

        /// Set slab thickness in [m]
        void setSlab(const double tw);

        /// Set sphere diameter in [m]
        void setSphere(const double D);

        /// Set cylinder diameter in [m]
        void setCylinder(const double D);

        /// Return integration time vector in [s]
        std::vector<double> getTime() const { return Time_; };

        /// Return gas mixture mass fraction in the gas phase at different integration times
        std::vector<std::vector<std::vector<double>>> getSpecie() const { return Specie_; };

        /// Return coverage at different integration times
        std::vector<std::vector<std::vector<double>>> getSite() const { return Site_; };

        /// Store results for plottnig and saving
        virtual void store(const double &tf, const std::vector<double> &xf);

        /// Resize variables based
        virtual void resize();

        /// Equations describing the catalytic pellet
        virtual int Equations(double &t, std::vector<double> &y, std::vector<double> &dy);

        /// Return algebraic equations flags
        std::vector<bool> AlgebraicEquations() const { return algb_; };

        /// Get length in [m]
        double getLength();

    private:
        double MWmix_; /// Gas mixture molecular weight in [g/mol]
        double cTot_;  /// Gas mixture concentration in [kmol/m3]
        double rho_;   /// Gas mixture density in [kg/m3]
        double L_;     /// Reactor length in [m]
        double dz_;    /// Discretization step for length [m]
        double D_;     /// Diameter [m]
        double r_;     /// Radius in [m]
        double epsi_;  /// Void fraction
        double tau_;   /// Tortuosity
        double tw_;    /// Slab thickness in [m]
        double dp_;    /// Particle diameter in [m]

        unsigned int NP_;         /// Number of discretization points
        unsigned int inertIndex_; /// Inert specie index

        std::string pelletType_; /// Pellet type
        std::string resolution_; /// Resolution method
        std::string modelType_;  /// Model type

        std::vector<double> z_;         /// Discretized length
        std::vector<double> dy_;        /// Accumulation term of mass and energy balance
        std::vector<double> y_;         /// Integration variables
        std::vector<double> omega0_;    /// Initial mass fraction
        std::vector<double> rhoVector_; /// Gas density in [kg/m3]
        std::vector<double> Length_;
        std::vector<double> Time_;

        std::vector<bool> algb_; /// Algebraic equations flags

        std::vector<std::vector<double>> omegaMatrix_;        /// Mass fraction in the gas phase
        std::vector<std::vector<double>> xMatrix_;            /// Mole fraction in the gas phase
        std::vector<std::vector<double>> Zmatrix_;            /// Coverage
        std::vector<std::vector<double>> diffMatrix_;         /// Mixture diffusion coefficients in [m2/s]
        std::vector<std::vector<double>> fluxMatrix_;         /// Species fluxes in [kg/m2/s]
        std::vector<std::vector<double>> RfromSurfaceMatrix_; /// Species heterogeneous reactions in [kg/m2/s]
        std::vector<std::vector<double>> RfromGasMatrix_;     /// Species homogeneous reactions in [kg/m3/s]
        std::vector<std::vector<double>> RsurfaceMatrix_;     /// Coverage heterogeneous reactions in [kg/m2/s]
        std::vector<std::vector<double>> MwMatrix_;           /// Species molecular weight in [g/mol]

        std::vector<std::vector<std::vector<double>>> Specie_;           /// Mass fraction at different integration time
        std::vector<std::vector<std::vector<double>>> Site_;             /// Coverage at different integration time
        std::vector<std::vector<std::vector<double>>> diffBinaryMatrix_; /// Binary diffusion coefficients in [m2/s]

        /// Epsi-tau model to estimate diffusion fluxes in [kg/m2/s]
        std::vector<std::vector<double>> epsi_tau_model(const std::vector<std::vector<double>> &diff, const std::vector<std::vector<double>> &omega);

        /// Dusty gas model to estimate diffusion fluxes in [kg/m2/s]
        std::vector<std::vector<double>> dusty_gas_model(const std::vector<std::vector<std::vector<double>>> &diff, const std::vector<std::vector<double>> &omega, const std::vector<std::vector<double>> &MW);

        /// Update gas mixture properties
        void properties(std::vector<double> &y);

        /// Equations describing the slab shape: ODE
        void slabOde(std::vector<double> &dy);

        /// Equations describing the slab shape: DAE
        void slab(std::vector<double> &dy);

        /// Equations describing the sphere shape: ODE
        void sphereOde(std::vector<double> &dy);

        /// Equations describing the sphere shape: DAE
        void sphere(std::vector<double> &dy);

        /// Equations describing the cylinder shape: ODE
        void cylinderOde(std::vector<double> &dy);

        /// Equations describing the cylinder shape: DAE
        void cylinder(std::vector<double> &dy);
    };
}
#endif
