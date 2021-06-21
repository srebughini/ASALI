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

#include "basicProperties.hpp"

namespace ASALI
{
    class transportProperties : public ASALI::basicProperties
    {
        public:
            transportProperties(ASALI::canteraInterface        *canteraInterface,
                                ASALI::speciesPopup            *speciesNames,
                                std::string                     kineticType);
            
            
            virtual ~transportProperties();

            virtual void results();
            virtual void save();
            virtual void clean();
            virtual void showAtomNames();
            virtual void condUnitConversion(bool check);
            virtual void muUnitConversion(bool check);
            virtual void diffUnitConversion(bool check);
            virtual void diffSpecies(unsigned int row);

            std::vector<double>      MW_;
            std::vector<double>      cond_;
            std::vector<double>      mu_;

            std::vector<std::vector<double> > diff_;

        private:
            Gtk::Box          condBox_;
            Gtk::Box          muBox_;
            Gtk::Box          diffBox_;

            Gtk::Button       exitButton2_;
            Gtk::Button       saveButton_;
            Gtk::Button       backButton_;

            Gtk::Grid         resultsGrid_;

            Gtk::Label        condLabel_;
            Gtk::Label        muLabel_;
            Gtk::Label        diffLabel_;

            Gtk::ComboBoxText condCombo_;
            Gtk::ComboBoxText diffCombo_;
            Gtk::ComboBoxText muCombo_;

            std::vector<Gtk::Label *>          nameVector_;
            std::vector<Gtk::Label *>          condVector_;
            std::vector<Gtk::Label *>          muVector_;
            std::vector<Gtk::Label *>          diffVector_;
            std::vector<Gtk::ComboBoxText *>   speciesCombo_;
            std::vector<Gtk::Box *>            diffBoxVector_;
    };
}

#endif