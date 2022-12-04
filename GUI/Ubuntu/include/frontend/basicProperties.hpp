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

#ifndef BASICPROPERTIES_H
#define BASICPROPERTIES_H

#include <gtkmm.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctime>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <limits>
#include <thread>
#include <numeric>
#include <functional>
#include <random>

#include "frontend/speciesPopup.hpp"
#include "backend/asaliUnitConversionUtils.hpp"
#include "backend/asaliFileManager.hpp"
#include "backend/beerQuote.hpp"
#include "backend/asaliVectorUtils.hpp"

#if ASALI_USING_CANTERA == 1
#include "backend/canteraInterface.hpp"
#else
#include "backend/asaliInterface.hpp"
#endif

namespace ASALI
{
        /// Vitrual class to estimate gas mixture properties
        class basicProperties : public Gtk::Window
        {
        public:
                /// Class constructor
                basicProperties(ASALI::speciesPopup *speciesNames, const std::string &kineticType);

                /// Class destructor
                virtual ~basicProperties();

                /// Virtual function to get results
                virtual void results() = 0;

                /// Virtual function to save results
                virtual void save() = 0;

                /// Function to close the window
                void exit();

                /// Shows available species in the database
                void availableSpecies();

                /// Shows input windows
                void input();

                /// Shows saving message popup
                void savedMessage();

                /// Read input
                void inputReader();

                /// Create grid for input window
                void createInputGrid();

                /// Check input
                void checkInput(unsigned int i);

#if ASALI_USING_CANTERA == 1
                /// Set object to estimate gas mixture properties
                void setChemistryInterface(ASALI::canteraInterface *chemistryInterface);
#else
                /// Set object to estimate gas mixture properties
                void setChemistryInterface(ASALI::asaliInterface *chemistryInterface);
#endif

                Gtk::Button helpButton_;  /// Help button
                Gtk::Button exitButton1_; /// Exit button
                Gtk::Button doneButton_;  /// Done button

                Gtk::Grid inputGrid_;   /// Background grid for input
                Gtk::Grid resultsGrid_; /// Background grid for results

                Gtk::Label tempLabel_;     /// Temperature label for input
                Gtk::Label pressLabel_;    /// Pressure label for input
                Gtk::Label fractionLabel_; /// Mass/Mole fraction label for input

                Gtk::Entry tempEntry_;  /// Temperature entry box for input
                Gtk::Entry pressEntry_; /// Pressure entry box for input

                Gtk::ComboBoxText tempCombo_;     /// Temperature unit dimensions for input
                Gtk::ComboBoxText pressCombo_;    /// Pressurre unit dimensions for input
                Gtk::ComboBoxText fractionCombo_; /// Mole or mass fraction for input

                std::vector<Gtk::Entry *> nameEntry_;     /// Species input names
                std::vector<Gtk::Entry *> fractionEntry_; /// Fraction input values

                std::vector<Gtk::Label *> nameVector_;

                unsigned int NS_; /// Number of species
                unsigned int OP_; /// Maximum number of input species

                double T_; /// Temperature [K]
                double p_; /// Pressure [Pa]

                std::pair<unsigned int, bool> checkInput_;

                std::vector<double> x_;    /// Mole fraction
                std::vector<double> y_;    /// Mass fraction
                std::vector<double> MW_;   /// Species molecular weigth [g/mol]
                std::vector<double> cond_; /// Species thermal conductivity [W/m/K]
                std::vector<double> mu_;   /// Species viscosity [Pas]

                std::vector<std::vector<double>> diff_; /// Species mixture diffusion [m2/s]

                std::vector<std::string> n_; /// Species names

                std::string kineticType_; /// Kinetic type

                ASALI::speciesPopup *speciesNames_;               /// Object to show the popup window with all available species
                ASALI::beerQuote *beerQuote_;                     /// Object to get random beer quotes
                ASALI::asaliUnitConversionUtils *unitConversion_; /// Object to work with unit dimensions
                ASALI::asaliVectorUtils *vectorUtils_;            /// Object to performe vector operations with std::vector
                ASALI::asaliFileManager fileManager_;             /// Object to handle opening/closing of files

#if ASALI_USING_CANTERA == 1
                ASALI::canteraInterface *chemistryInterface_; /// Object to get gas mixture properties
#else
                ASALI::asaliInterface *chemistryInterface_; /// Object to get gas mixture properties
#endif

        private:
        };
}
#endif
