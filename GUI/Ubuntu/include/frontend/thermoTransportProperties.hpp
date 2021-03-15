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

#ifndef THERMOTRANSPORTPROPERTIES_H
#define THERMOTRANSPORTPROPERTIES_H

#include "frontend/basicProperties.hpp"

namespace ASALI
{
    class thermoTransportProperties : public ASALI::basicProperties
    {
    public:
        thermoTransportProperties(ASALI::speciesPopup *speciesNames, std::string kineticType);

        virtual ~thermoTransportProperties();

        virtual void results();
        virtual void save();
        virtual void clean();
        virtual void update();
        
        void showAtomNames();
        void diffSpecies(unsigned int row);
        void condUnitConversion(bool check, unsigned int col);
        void muUnitConversion(bool check, unsigned int col);
        void diffUnitConversion(bool check, unsigned int col);
        void cpUnitConversion(bool check, unsigned int col);
        void hUnitConversion(bool check, unsigned int col);
        void sUnitConversion(bool check, unsigned int col);

        Gtk::Box condBox_;
        Gtk::Box muBox_;
        Gtk::Box diffBox_;
        Gtk::Box cpBox_;
        Gtk::Box hBox_;
        Gtk::Box sBox_;

        Gtk::Button exitButton2_;
        Gtk::Button saveButton_;
        Gtk::Button backButton_;

        Gtk::Grid resultsGrid_;

        Gtk::Label condLabel_;
        Gtk::Label muLabel_;
        Gtk::Label diffLabel_;
        Gtk::Label cpLabel_;
        Gtk::Label hLabel_;
        Gtk::Label sLabel_;

        Gtk::ComboBoxText condCombo_;
        Gtk::ComboBoxText diffCombo_;
        Gtk::ComboBoxText muCombo_;
        Gtk::ComboBoxText cpCombo_;
        Gtk::ComboBoxText hCombo_;
        Gtk::ComboBoxText sCombo_;

        std::vector<Gtk::Label *> nameVector_;
        std::vector<Gtk::Label *> condVector_;
        std::vector<Gtk::Label *> muVector_;
        std::vector<Gtk::Label *> diffVector_;
        std::vector<Gtk::Label *> cpVector_;
        std::vector<Gtk::Label *> hVector_;
        std::vector<Gtk::Label *> sVector_;
        std::vector<Gtk::ComboBoxText *> speciesCombo_;
        std::vector<Gtk::Box *> diffBoxVector_;

        std::vector<double> cp_;
        std::vector<double> h_;
        std::vector<double> s_;

    private:
    };
}

#endif
