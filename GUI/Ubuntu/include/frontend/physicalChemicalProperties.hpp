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

#ifndef PHYSICALCHEMICALPROPERTIES_H
#define PHYSICALCHEMICALPROPERTIES_H

#include "frontend/basicProperties.hpp"

namespace ASALI
{
    class physicalChemicalProperties : public ASALI::basicProperties
    {
    public:
        physicalChemicalProperties(ASALI::speciesPopup *speciesNames, const std::string &kineticType);

        virtual void results();
        virtual void save();
        virtual void clean();

        void showAtomNames();
        void mwUnitConversion(bool check);
        void rhoUnitConversion(bool check);

        std::vector<double> rho_;

    private:
        Gtk::Box rhoBox_;
        Gtk::Box mwBox_;

        Gtk::Button exitButton2_;
        Gtk::Button saveButton_;
        Gtk::Button backButton_;

        Gtk::Label rhoLabel_;
        Gtk::Label mwLabel_;

        Gtk::ComboBoxText rhoCombo_;
        Gtk::ComboBoxText mwCombo_;

        std::vector<Gtk::Label *> rhoVector_;
        std::vector<Gtk::Label *> mwVector_;
    };
}
#endif
