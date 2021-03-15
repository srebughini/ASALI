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

#include "frontend/basicProperties.hpp"

namespace ASALI
{
    class transportProperties : public ASALI::basicProperties
    {
    public:
        transportProperties(ASALI::speciesPopup *speciesNames, std::string kineticType);

        virtual ~transportProperties();

        void results();
        void save();
        void clean();
        void condUnitConversion(bool check);
        void muUnitConversion(bool check);
        void diffUnitConversion(bool check);
        void diffSpecies(unsigned int row);

    private:
        Gtk::Box condBox_;
        Gtk::Box muBox_;
        Gtk::Box diffBox_;

        Gtk::Button exitButton2_;
        Gtk::Button saveButton_;
        Gtk::Button backButton_;

        Gtk::Label condLabel_;
        Gtk::Label muLabel_;
        Gtk::Label diffLabel_;

        Gtk::ComboBoxText condCombo_;
        Gtk::ComboBoxText diffCombo_;
        Gtk::ComboBoxText muCombo_;


        std::vector<Gtk::Label *> condVector_;
        std::vector<Gtk::Label *> muVector_;
        std::vector<Gtk::Label *> diffVector_;
        std::vector<Gtk::ComboBoxText *> speciesCombo_;
        std::vector<Gtk::Box *> diffBoxVector_;
    };
}

#endif
