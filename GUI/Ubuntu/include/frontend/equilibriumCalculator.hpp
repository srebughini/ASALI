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

#ifndef EQUILIBRIUMCALCULATOR_H
#define EQUILIBRIUMCALCULATOR_H

#include "frontend/transportProperties.hpp"

namespace ASALI
{
    class equilibriumCalculator : public ASALI::thermoTransportProperties
    {
    public:
        equilibriumCalculator(ASALI::speciesPopup *speciesNames, std::string kineticType);

        virtual ~equilibriumCalculator();

        void save();
        void results();
        void clean();
        void update();
        void showAtomNames();

    private:
        void initialFractionUnitConversion();
        void finalFractionUnitConversion();

        Gtk::Label initialStateLabel_;
        Gtk::Label finalStateLabel_;

        Gtk::ComboBoxText equilibriumCombo_;
        Gtk::ComboBoxText initialFractionCombo_;
        Gtk::ComboBoxText finalFractionCombo_;

        std::vector<Gtk::Label *> initialFractionVector_;
        std::vector<Gtk::Label *> finalFractionVector_;

        double Teq_;

        std::vector<double> xeq_;
        std::vector<double> yeq_;
    };
}
#endif
