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
#include <gtkmm.h>

namespace ASALI
{
    /// Abstract class that describes catalytic reactors equations
    class catalyticReactorsEquations
    {
    public:
        catalyticReactorsEquations();

         #include "shared/Vector.H"

        /// Set gas mixture chemistry interface
        void setInterface(ASALI::canteraInterface *chemistryInterface);

        /// Set bool to enable or disable homogeneous reactions
        void setHomogeneousReactions(const bool flag);

        /// Set bool to enable or disable homogeneous reactions
        void setHeterogeneusReactions(const bool flag);

        /// Set type of kinetic scheme used
        void setKineticType(const std::string type);

        /// Enable used defined properties
        void turnOnUserDefined(const bool check);

        /// Set ASALI kinetic parameters
        void setAsaliKinetic(ASALI::pythonInterface *pi, const std::vector<int> canteraIndex, const std::vector<std::string> n);

        /// Set user defined heterogeneous heat of reactions in [W/m2]
        void setQfromSurface(const std::vector<double> Q);

        /// Set user defined homogeneous heat of reactions in [W/m3]
        void setQfromGas(const std::vector<double> Q);

        /// Set user defined species molecular weight in [g/mol]
        void setMW(const std::vector<double> MW);

        /// Set user defined species mixture diffusion coefficient in [m2/s]
        void setDiffMix(const std::vector<double> diff);

        /// Set user defined gas mixture mass specific heat in [J/kg/K]
        void setCpMassMix(const double cp);

        /// Set user defined gas mixture thermal conductivity in [W/m/K]
        void setCondMix(const double cond);

        /// Set user defined gas mixture viscosity in [Pas]
        void setMuMix(const double mu);

        /// Estimate reaction rates using python interface
        std::vector<double> reactionRate(const std::vector<double> omega, const double T, const std::string type);
        
        /// Estimate mole fraction from mass fraction and mean molecular weight
        std::vector<double> moleFraction(const std::vector<double> omega, const std::vector<double> MW, double MWmix);
        
        /// Estimate heat of reaction using python interface
        double heatOfReaction(const std::vector<double> omega, const double T, const std::vector<double> h, const std::string type);
        
        /// Estimate mean molecular weight [g/mol]
        double meanMolecularWeight(const std::vector<double> omega, const std::vector<double> MW);

        /// Return number of reactions 
        inline unsigned int NumberOfEquations() { return NE_; };

        /// Equations describing the catalytic reactors
        virtual int Equations(double &t, std::vector<double> &y, std::vector<double> &dy) = 0;

        /// Resize variables based
        virtual void resize() = 0;

        /// Store results for plottnig and saving
        virtual void store(const double tf, const std::vector<double> xf) = 0;

        /// Class destructor
        virtual ~catalyticReactorsEquations();

        double cp_;    /// Gas mixture mass specific heat in [J/kg/K]
        double mu_;    /// Gas mixture viscosity in [Pas]
        double cond_;  /// Gas mixture thermal conductivity in [W/m/K]

        unsigned int NE_; /// Number of equations
        unsigned int NC_; /// Number of gas species

        std::string type_; /// Kinetic type

        bool homogeneousReactions_;  /// Bool to enable/disable homogeneous reactions
        bool heterogeneusReactions_; /// Bool to enable/disable heterogeneous reactions
        bool userCheck_;             /// Bool to enable/disable user defined gas mixture properties

        ASALI::pythonInterface *pi_;                  /// Python interface pointer
        ASALI::canteraInterface *chemistryInterface_; /// Gas mixture chemistry interface pointer

        std::vector<double> QuserHom_; /// User defined homogeneous heat of reactions in [W/m3]
        std::vector<double> QuserHet_; /// User defined heterogeneous heat of reactions in [W/m2]
        std::vector<double> MW_;       /// Species molecular weight in [g/mol]
        std::vector<double> diff_;     /// Species mixture diffusion coefficient in [m2/s]

        std::vector<int> canteraIndex_; /// Cantera index to order species

        std::vector<std::string> n_;    /// Species names

    private:
    };
}

#endif
