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

#ifndef EQUILIBRIUMCALCULATOR_H
#define EQUILIBRIUMCALCULATOR_H

#include "frontend/transportProperties.hpp"

namespace ASALI
{
    /// Class to estimate gas mixture chemical equilibrium
    class equilibriumCalculator : public ASALI::thermoTransportProperties
    {
    public:
        /// Class constructor
        equilibriumCalculator(ASALI::speciesPopup *speciesNames, const std::string &kineticType);

        /// Function to save results
        void save();

        /// Function to get results
        void results();

        /// Function to clean input
        void clean();

        /// Update windows
        void update();

        /// Shows list of atoms
        void showAtomNames();

    private:
        /// Convert initial fraction from mass to mole and viceversa
        void initialFractionUnitConversion();

        /// Convert resulting fraction from mass to mole and viceversa
        void finalFractionUnitConversion();

        Gtk::Label initialStateLabel_; /// Initial state label for input
        Gtk::Label finalStateLabel_;   /// Final state label for input

        Gtk::ComboBoxText equilibriumCombo_;     /// Equilibrium type for input
        Gtk::ComboBoxText initialFractionCombo_; /// Mass/mole fraction for input
        Gtk::ComboBoxText finalFractionCombo_;   /// Mass/mole fraction for results

        std::vector<Gtk::Label *> initialFractionVector_; /// Initial mass/mole fraction composition for input
        std::vector<Gtk::Label *> finalFractionVector_;   /// Final mass/mole fraction composition

        double Teq_; /// Equilibrium temperature in [K]

        std::vector<double> xeq_; /// Equilibrium mole fraction
        std::vector<double> yeq_; /// Equilibrium mass fraction
    };
}
#endif
