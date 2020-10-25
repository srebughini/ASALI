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
#include "canteraInterface.hpp"
#include "speciesPopup.hpp"

namespace ASALI
{
    class basicProperties : public Gtk::Window
    {
        public:
            basicProperties(ASALI::canteraInterface        *canteraInterface,
                            ASALI::speciesPopup            *speciesNames,
                            std::string                     kineticType);
            
            #include "shared/FileManager.H"
            
            virtual ~basicProperties();

            virtual void results();
            virtual void save();
            virtual void clean();
            virtual void showAtomNames();

            #include "shared/UnitConversion.H"
            #include "shared/Vector.H"

            void exit();
            void availableSpecies();
            void input();
            void savedMessage();
            void inputReader();
            void checkInput(unsigned int i);
            void title(std::string title);

            std::string getBeer();
            std::string getBeerShort();

            Gtk::Button       helpButton_;
            Gtk::Button       exitButton1_;
            Gtk::Button       doneButton_;

            Gtk::Grid         inputGrid_;

            Gtk::Label        tempLabel_;
            Gtk::Label        pressLabel_;
            Gtk::Label        fractionLabel_;
            
            Gtk::Entry        tempEntry_;
            Gtk::Entry        pressEntry_;

            Gtk::ComboBoxText tempCombo_;
            Gtk::ComboBoxText pressCombo_;
            Gtk::ComboBoxText fractionCombo_;

            std::vector<Gtk::Entry *> nameEntry_;
            std::vector<Gtk::Entry *> fractionEntry_;

            unsigned int NS_;
            unsigned int OP_;
            
            double       T_;
            double       p_;

            std::pair<unsigned int,bool>  checkInput_;

            std::vector<double>      x_;
            std::vector<double>      y_;

            std::vector<std::string>  n_;
            std::vector<std::string>  beer_;
            std::vector<std::string>  beerShort_;

            std::string kineticType_;
            
            ASALI::canteraInterface        *canteraInterface_;
            ASALI::speciesPopup            *speciesNames_;
    };
}

#endif
