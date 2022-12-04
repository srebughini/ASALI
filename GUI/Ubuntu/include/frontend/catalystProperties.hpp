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

#ifndef CATALYSTPROPERTIES_H
#define CATALYSTPROPERTIES_H

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
#include "backend/asaliUnitConversionUtils.hpp"
#include "backend/asaliFileManager.hpp"

namespace ASALI
{
    /// Class to estimate catalyst properties
    class catalystProperties : public Gtk::Window
    {
    public:
        /// Class constructor
        catalystProperties();

        /// Class destructor
        ~catalystProperties();

        void doneInput();

        /// Return density in [kg/m3]
        inline double get_rho() const { return rho_; };

        /// Return thermal conducitivity in [W/m/K]
        inline double get_cond() const { return cond_; };

        /// Return specific heat in [J/kg/K]
        inline double get_cp() const { return cp_; };

        /// Return catalyst active phase load in [1/m]
        inline double get_load() const { return alfa_; };

        /// Return temperature in [K]
        inline double get_T() const { return T_; };

    private:
        Gtk::Image het1dLogo_; /// Logo

        Gtk::Box mainBox_; /// Background box

        Gtk::Grid mainGrid_; /// Background grid

        Gtk::Label rhoLabel_;  /// Density label for input
        Gtk::Label condLabel_; /// Thermal conductivity label for input
        Gtk::Label cpLabel_;   /// Specific heat label for input
        Gtk::Label loadLabel_; /// Catalyst active phase load label for input
        Gtk::Label TLabel_;    /// Temperature label for input

        Gtk::Button doneButton_; /// Done button

        Gtk::ComboBoxText rhoCombo_;  /// Density unit dimensions for input
        Gtk::ComboBoxText condCombo_; /// Thermal conductivity unit dimensions for input
        Gtk::ComboBoxText cpCombo_;   /// Specific heat unit dimensions for input
        Gtk::ComboBoxText loadCombo_; /// Catalyst active phase load unit dimensions for input
        Gtk::ComboBoxText TCombo_;    /// Temperature unit dimensions for input

        Gtk::Entry rhoEntry_;  /// Density entry box for input
        Gtk::Entry condEntry_; /// Thermal conductivity entry box for input
        Gtk::Entry cpEntry_;   /// Specific heat entry box for input
        Gtk::Entry loadEntry_; /// Catalyst active phase load entry box for input
        Gtk::Entry TEntry_;    /// Temperature entry box for input

        double rho_;  /// Density in [kg/m3]
        double cp_;   /// Specific heat in [J/kg/K]
        double cond_; /// Thermal conductivity in [W/m/K]
        double alfa_; /// Catalyst active phase load in [1/m]
        double T_;    /// Temperature in [K]

        ASALI::asaliUnitConversionUtils *unitConversion_; /// Object to work with unit dimensions
        ASALI::asaliFileManager fileManager_;             /// Object to handle opening/closing of files
    };
}
#endif
