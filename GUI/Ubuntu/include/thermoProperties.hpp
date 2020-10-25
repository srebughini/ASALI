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


#ifndef THERMOPROPERTIES_H
#define THERMOPROPERTIES_H

#include "transportProperties.hpp"

namespace ASALI
{
    class thermoProperties : public ASALI::transportProperties
    {
        public:
            thermoProperties(ASALI::canteraInterface        *canteraInterface,
                             ASALI::speciesPopup            *speciesNames,
                             std::string                     kineticType);
            
            virtual ~thermoProperties();

            virtual void results();
            virtual void save();
            virtual void clean();
            virtual void showAtomNames();
            virtual void cpUnitConversion(bool check);
            virtual void hUnitConversion(bool check);
            virtual void sUnitConversion(bool check);

            std::vector<double>      cp_;
            std::vector<double>      h_;
            std::vector<double>      s_;
            
        private:

            Gtk::Box          cpBox_;
            Gtk::Box          hBox_;
            Gtk::Box          sBox_;

            Gtk::Button       exitButton2_;
            Gtk::Button       saveButton_;
            Gtk::Button       backButton_;
            
            Gtk::Grid         resultsGrid_;

            Gtk::Label        cpLabel_;
            Gtk::Label        hLabel_;
            Gtk::Label        sLabel_;
            
            Gtk::ComboBoxText cpCombo_;
            Gtk::ComboBoxText hCombo_;
            Gtk::ComboBoxText sCombo_;

            std::vector<Gtk::Label *>          nameVector_;
            std::vector<Gtk::Label *>          cpVector_;
            std::vector<Gtk::Label *>          hVector_;
            std::vector<Gtk::Label *>          sVector_;
            std::vector<Gtk::ComboBoxText *>   speciesCombo_;
    };
}

#endif
