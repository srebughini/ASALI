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

#ifndef CHEMKINCONVERTER_H
#define CHEMKINCONVERTER_H

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
#include "backend/beerQuote.hpp"
#include "backend/asaliFileManager.hpp"

namespace ASALI
{
    /// Class to convert Cantera (https://cantera.org) .cti input to .xml
    class chemkinConverter : public Gtk::Window
    {
    public:
        /// Class constructor
        chemkinConverter();

        /// Class destructor
        ~chemkinConverter();

    private:
        /// Function to close the window
        void exit();

        /// Function to clean input
        void clean();

        /// Function to load input files
        void load(const int index);

        /// Shows saving message popup
        void savedMessage();

        /// Shows error message during saving popup
        void notSavedMessage();

        /// Run conversion
        void run();

        /// Shows message
        void help();

        /// Shows error message
        void error(const std::string &type);

        /// Check converted file
        bool checkConvertedFile(const std::string &filename);

        Gtk::Box mainBox_;   /// Background box
        Gtk::Box buttonBox_; /// Background button box

        Gtk::Grid endGrid_; /// Background grid

        Gtk::Button kinetic_;   /// Gas kinetic button
        Gtk::Button thermo_;    /// Thermodinamic button
        Gtk::Button transport_; /// Transport button
        Gtk::Button surface_;   /// Surface kinetic button
        Gtk::Button output_;    /// Output button
        Gtk::Button help_;      /// Help button
        Gtk::Button exit_;      /// Exit button

        Gtk::Image logo_; /// Logo

        std::vector<std::string> files_; /// Vector of files name to be converted

        ASALI::beerQuote *beerQuote_;         /// Object to get random beer quotes
        ASALI::asaliFileManager fileManager_; /// Object to handle opening/closing of files
    };
}
#endif
