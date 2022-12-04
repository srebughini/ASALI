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

#include "backend/pythonInterface.hpp"
#include "backend/canteraInterface.hpp"
#include "backend/asaliVectorUtils.hpp"
#include <gtkmm.h>

namespace ASALI
{
    /// Abstract class that describes catalytic reactors equations
    class catalyticReactorsEquations
    {
    public:
        catalyticReactorsEquations();

        /// Set gas mixture chemistry interface
        void setInterface(ASALI::canteraInterface *chemistryInterface);

        /// Set bool to enable or disable homogeneous reactions
        void setHomogeneousReactions(const bool flag);

        /// Set bool to enable or disable homogeneous reactions
        void setHeterogeneusReactions(const bool flag);

        /// Set type of kinetic scheme used
        void setKineticType(const std::string &type);

        /// Enable used defined properties
        void turnOnUserDefined(const bool check);

        /// Set ASALI kinetic parameters
        void setAsaliKinetic(ASALI::pythonInterface *pi, const std::vector<int> &canteraIndex, const std::vector<std::string> &n);

        /// Set user defined heterogeneous heat of reactions in [W/m2]
        void setQfromSurface(const std::vector<double> &Q);

        /// Set user defined homogeneous heat of reactions in [W/m3]
        void setQfromGas(const std::vector<double> &Q);

        /// Set user defined species molecular weight in [g/mol]
        void setMW(const std::vector<double> &MW);

        /// Set user defined species mixture diffusion coefficient in [m2/s]
        void setDiffMix(const std::vector<double> &diff);

        /// Set user defined gas mixture mass specific heat in [J/kg/K]
        void setCpMassMix(const double cp);

        /// Set user defined gas mixture thermal conductivity in [W/m/K]
        void setCondMix(const double cond);

        /// Set user defined gas mixture viscosity in [Pas]
        void setMuMix(const double mu);

        /// Update homogeneous reaction rate and heat of reaction based on actual reactor conditions
        void updateHomogenousChemistry();

        /// Update heterogeneous reaction rate and heat of reaction based on actual reactor conditions
        void updateHeterogeneousChemistry();

        /// Estimate reaction rates using python interface
        std::vector<double> reactionRate(const std::vector<double> &x, const double T, const std::string &type);

        /// Estimate mole fraction from mass fraction and mean molecular weight
        std::vector<double> moleFraction(const std::vector<double> &omega, const std::vector<double> &MW, double MWmix);

        /// Estimate heat of reaction using python interface
        double heatOfReaction(const std::vector<double> &x, const double T, const std::vector<double> &h, const std::string &type);

        /// Estimate mean molecular weight [g/mol]
        double meanMolecularWeight(const std::vector<double> &omega, const std::vector<double> &MW);

        /// Return number of reactions
        inline unsigned int NumberOfEquations() const { return NE_; };

        /// Equations describing the catalytic reactors
        virtual int Equations(double &t, std::vector<double> &y, std::vector<double> &dy) = 0;

        /// Resize variables based
        virtual void resize() = 0;

        /// Store results for plottnig and saving
        virtual void store(const double &tf, const std::vector<double> &xf) = 0;

        /// Class destructor
        virtual ~catalyticReactorsEquations();

        double cp_;           /// Gas mixture mass specific heat in [J/kg/K]
        double mu_;           /// Gas mixture viscosity in [Pas]
        double cond_;         /// Gas mixture thermal conductivity in [W/m/K]
        double T_;            /// Temperature [K]
        double P_;            /// Pressure [Pa]
        double QfromGas_;     /// Homogeneous heat of reaction [W/m3]
        double QfromSurface_; /// Heterogeneous heat of reaction [W/m2]
        double alfa_;         /// Catalyst load [m3/m2]
        double SD_;           /// Site density in [1/m2]

        unsigned int NE_;      /// Number of equations
        unsigned int NC_;      /// Number of gas species
        unsigned int SURF_NC_; /// Number of coverage species

        std::string type_; /// Kinetic type

        bool homogeneousReactions_;  /// Bool to enable/disable homogeneous reactions
        bool heterogeneusReactions_; /// Bool to enable/disable heterogeneous reactions
        bool userCheck_;             /// Bool to enable/disable user defined gas mixture properties
        bool energyEquation_;        /// Bool to enable/disable energy balance

        ASALI::pythonInterface *pi_;                  /// Python interface pointer
        ASALI::canteraInterface *chemistryInterface_; /// Gas mixture chemistry interface pointer
        ASALI::asaliVectorUtils *vectorUtils_;        /// Object to performe vector operations with std::vector

        std::vector<double> QuserHom_;     /// User defined homogeneous heat of reactions in [W/m3]
        std::vector<double> QuserHet_;     /// User defined heterogeneous heat of reactions in [W/m2]
        std::vector<double> MW_;           /// Species molecular weight in [g/mol]
        std::vector<double> diff_;         /// Species mixture diffusion coefficient in [m2/s]
        std::vector<double> omega_;        /// Gas species mass fraction
        std::vector<double> x_;            /// Gas species mole fraction
        std::vector<double> Z_;            /// Coverage composition
        std::vector<double> h_;            /// Species enthalpy [J/kg]
        std::vector<double> RfromGas_;     /// Homogeneous reaction rates [kg/m3/s]
        std::vector<double> RfromSurface_; /// Heterogeneous reaction rates [kg/m2/s]
        std::vector<double> Rsurface_;     /// Coverage reaction rates [kg/m2/s]

        std::vector<int> canteraIndex_; /// Cantera index to order species

        std::vector<std::string> n_; /// Species names

    private:
    };
}
#endif
