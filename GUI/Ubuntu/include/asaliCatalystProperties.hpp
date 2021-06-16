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

#ifndef ASALICATALYSTPROPERTIES_H
#define ASALICATALYSTPROPERTIES_H

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
#include "asaliUnitConversionUtils.hpp"

namespace ASALI
{
    class asaliCatalystProperties : public Gtk::Window
    {
        public:
            asaliCatalystProperties();
            
            void doneInput();

            double get_rho()  {return rho_;};
            double get_cond() {return cond_;};
            double get_cp()   {return cp_;};
            double get_load() {return alfa_;};
            double get_T()    {return T_;};

            virtual ~asaliCatalystProperties();
            
        private:
            Gtk::Image        het1dLogo_;

            Gtk::Box          mainBox_;

            Gtk::Grid         mainGrid_;

            Gtk::Label        rhoLabel_;
            Gtk::Label        condLabel_;
            Gtk::Label        cpLabel_;
            Gtk::Label        loadLabel_;
            Gtk::Label        TLabel_;

            Gtk::Button       doneButton_;
            
            Gtk::ComboBoxText rhoCombo_;
            Gtk::ComboBoxText condCombo_;
            Gtk::ComboBoxText cpCombo_;
            Gtk::ComboBoxText loadCombo_;
            Gtk::ComboBoxText TCombo_;

            Gtk::Entry        rhoEntry_;
            Gtk::Entry        condEntry_;
            Gtk::Entry        cpEntry_;
            Gtk::Entry        loadEntry_;
            Gtk::Entry        TEntry_;

            double rho_;
            double cp_;
            double cond_;
            double alfa_;
            double T_;

            ASALI::asaliUnitConversionUtils   *unitConversion_;

    };
}

#endif
