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

#ifndef TRANSPORTPROPERTIES_H
#define TRANSPORTPROPERTIES_H

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

#include "frontend/speciesPopup.hpp"

#if ASALI_USING_CANTERA == 1
#include "backend/canteraInterface.hpp"
#else
#include "backend/asaliInterface.hpp"
#endif

namespace ASALI
{
    class transportProperties : public Gtk::Window
    {
    public:
        transportProperties(ASALI::speciesPopup *speciesNames,
                            std::string kineticType);

#include "shared/FileManager.H"

        virtual ~transportProperties();

        virtual void results();
        virtual void save();
        virtual void clean();
        virtual void showAtomNames();
        virtual void condUnitConversion(bool check);
        virtual void muUnitConversion(bool check);
        virtual void diffUnitConversion(bool check);
        virtual void diffSpecies(unsigned int row);

#include "shared/UnitConversion.H"
#include "shared/Vector.H"

        void exit();
        void availableSpecies();
        void input();
        void savedMessage();
        void inputReader();
        void checkInput(unsigned int i);

#if ASALI_USING_CANTERA == 1
        void setChemistryInterface(ASALI::canteraInterface *chemistryInterface);
#else
        void setChemistryInterface(ASALI::asaliInterface *chemistryInterface);
#endif

        std::string getBeer();
        std::string getBeerShort();

        Gtk::Button helpButton_;
        Gtk::Button exitButton1_;
        Gtk::Button doneButton_;

        Gtk::Grid inputGrid_;

        Gtk::Label tempLabel_;
        Gtk::Label pressLabel_;
        Gtk::Label fractionLabel_;

        Gtk::Entry tempEntry_;
        Gtk::Entry pressEntry_;

        Gtk::ComboBoxText tempCombo_;
        Gtk::ComboBoxText pressCombo_;
        Gtk::ComboBoxText fractionCombo_;

        std::vector<Gtk::Entry *> nameEntry_;
        std::vector<Gtk::Entry *> fractionEntry_;

        unsigned int NS_;
        unsigned int OP_;

        double T_;
        double p_;

        std::pair<unsigned int, bool> checkInput_;

        std::vector<double> x_;
        std::vector<double> y_;
        std::vector<double> MW_;
        std::vector<double> cond_;
        std::vector<double> mu_;

        std::vector<std::vector<double>> diff_;

        std::vector<std::string> n_;
        std::vector<std::string> beer_;
        std::vector<std::string> beerShort_;

        std::string kineticType_;

        ASALI::speciesPopup *speciesNames_;

#if ASALI_USING_CANTERA == 1
        ASALI::canteraInterface *chemistryInterface_;
#else
        ASALI::asaliInterface *chemistryInterface_;
#endif

    private:
        Gtk::Box condBox_;
        Gtk::Box muBox_;
        Gtk::Box diffBox_;

        Gtk::Button exitButton2_;
        Gtk::Button saveButton_;
        Gtk::Button backButton_;

        Gtk::Grid resultsGrid_;

        Gtk::Label condLabel_;
        Gtk::Label muLabel_;
        Gtk::Label diffLabel_;

        Gtk::ComboBoxText condCombo_;
        Gtk::ComboBoxText diffCombo_;
        Gtk::ComboBoxText muCombo_;

        std::vector<Gtk::Label *> nameVector_;
        std::vector<Gtk::Label *> condVector_;
        std::vector<Gtk::Label *> muVector_;
        std::vector<Gtk::Label *> diffVector_;
        std::vector<Gtk::ComboBoxText *> speciesCombo_;
        std::vector<Gtk::Box *> diffBoxVector_;
    };
}

#endif
