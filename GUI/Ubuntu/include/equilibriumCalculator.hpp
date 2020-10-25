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

#include "transportProperties.hpp"

namespace ASALI
{
    class equilibriumCalculator : public ASALI::transportProperties
    {
        public:

            equilibriumCalculator(ASALI::canteraInterface        *canteraInterface,
                                  ASALI::speciesPopup            *speciesNames,
                                  std::string                     kineticType);
            
            virtual ~equilibriumCalculator();
            
            virtual void save();
            virtual void results();
            virtual void showAtomNames();

        private:
        
            void clean();
            void initialFractionUnitConversion();
            void finalFractionUnitConversion();

            Gtk::Button       exitButton2_;
            Gtk::Button       saveButton_;
            Gtk::Button       backButton_;

            Gtk::Label        initialStateLabel_;
            Gtk::Label        finalStateLabel_;

            
            Gtk::Grid         resultsGrid_;
            
            Gtk::ComboBoxText equilibriumCombo_;
            Gtk::ComboBoxText initialFractionCombo_;
            Gtk::ComboBoxText finalFractionCombo_;


            std::vector<Gtk::Label *> nameVector_;
            std::vector<Gtk::Label *> initialFractionVector_;
            std::vector<Gtk::Label *> finalFractionVector_;

            double         Teq_;

            std::vector<double>      xeq_;
            std::vector<double>      yeq_;
    };
}

#endif
