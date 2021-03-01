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


#ifndef VACUUMPROPERTIES_H
#define VACUUMPROPERTIES_H

#include "transportProperties.hpp"

namespace ASALI
{
    class vacuumProperties : public ASALI::transportProperties
    {
        public:

            vacuumProperties(ASALI::speciesPopup *speciesNames,
                             std::string          kineticType);
            
            virtual ~vacuumProperties();
            
            virtual void save();

        private:
        
            void run();
            void read();

            Gtk::Grid grid_;
            
            Gtk::Button exitButton_;
            Gtk::Button saveButton_;
            Gtk::Button calculateButton_;
            Gtk::Button helpButton_;

            Gtk::Box tempBox_;
            Gtk::Box pressBox_;
            Gtk::Box lengthBox_;
            Gtk::Box diffBox_;
            Gtk::Box velocityBox_;
            Gtk::Box pathBox_;

            Gtk::Label tempLabel_;
            Gtk::Label pressLabel_;
            Gtk::Label lengthLabel_;
            Gtk::Label diffLabel_;
            Gtk::Label specieLabel_;
            Gtk::Label knudsenLabel_;
            Gtk::Label velocityLabel_;
            Gtk::Label pathLabel_;
            Gtk::Label diffResults_;
            Gtk::Label velocityResults_;
            Gtk::Label pathResults_;
            Gtk::Label knudsenResults_;
        
            Gtk::ComboBoxText pressCombo_;
            Gtk::ComboBoxText lengthCombo_;
            Gtk::ComboBoxText tempCombo_;
            Gtk::ComboBoxText diffCombo_;
            Gtk::ComboBoxText velocityCombo_;
            Gtk::ComboBoxText pathCombo_;

            Gtk::Entry specieEntry_;
            Gtk::Entry tempEntry_;
            Gtk::Entry pressEntry_;
            Gtk::Entry lengthEntry_;

            double Kn_;
            double diffK_;
            double vK_;
            double d_;
            double lK_;
    };
}

#endif
