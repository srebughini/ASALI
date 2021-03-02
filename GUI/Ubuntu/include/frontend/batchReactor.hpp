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


#ifndef BATCHREACTORS_H
#define BATCHREACTORS_H

#include "frontend/catalyticReactors.hpp"
#include "backend/odeInterface.hpp"
#include "backend/batchEquations.hpp"

namespace ASALI
{
    class batchReactor : public ASALI::catalyticReactors
    {
        public:

            batchReactor(std::string kineticType);
            
            virtual ~batchReactor();

            virtual void input();
            virtual void read();
            virtual void recap();
            virtual void propertiesShow();
            virtual void run();
            virtual void save();
            virtual void plot();

        private:

            void clean();

            Gtk::Box          mainBox_;
            Gtk::Box          secondBox_;
            Gtk::Box          recapMainBox_;
            Gtk::Box          recapBox_;
            Gtk::Box          logoBox_;

            Gtk::Button       exitButton3_;
            Gtk::Button       exitButton4_;
            Gtk::Button       nextButton3_;
            Gtk::Button       backButton3_;


            Gtk::ButtonBox    recapButtonBox_;

            Gtk::Grid         propertiesGrid_;
            Gtk::Grid         recapGrid_;
            
            Gtk::Label        volumeLabel_;
            Gtk::Label        loadLabel_;
            Gtk::Label        timeLabel_;
            Gtk::Label        saveLabel_;
            Gtk::Label        energyLabel_;
            Gtk::Label        recapVolumeLabel_;
            Gtk::Label        recapVolumeUDLabel_;
            Gtk::Label        recapVolumeValueLabel_;
            Gtk::Label        recapTemperatureLabel_;
            Gtk::Label        recapTemperatureUDLabel_;
            Gtk::Label        recapTemperatureValueLabel_;
            Gtk::Label        recapPressureLabel_;
            Gtk::Label        recapPressureUDLabel_;
            Gtk::Label        recapPressureValueLabel_;
            Gtk::Label        recapTimeLabel_;
            Gtk::Label        recapTimeUDLabel_;
            Gtk::Label        recapTimeValueLabel_;
            Gtk::Label        recapLoadLabel_;
            Gtk::Label        recapLoadUDLabel_;
            Gtk::Label        recapLoadValueLabel_;
            Gtk::Label        recapSaveLabel_;
            Gtk::Label        recapSaveUDLabel_;
            Gtk::Label        recapSaveValueLabel_;
            Gtk::Label        recapFractionLabel_;
            Gtk::Label        recapFractionNameLabel_;
            Gtk::Label        recapFractionValueLabel_;
            Gtk::Label        recapEnergyLabel_;
            Gtk::Label        recapEnergyValueLabel_;
            Gtk::Label        recapKineticLabel_;
            Gtk::Label        recapKineticValueLabel_;

            Gtk::Entry        volumeEntry_;
            Gtk::Entry        timeEntry_;
            Gtk::Entry        loadEntry_;
            Gtk::Entry        saveEntry_;
            
            Gtk::ComboBoxText volumeCombo_;
            Gtk::ComboBoxText timeCombo_;
            Gtk::ComboBoxText loadCombo_;
            Gtk::ComboBoxText energyCombo_;
            Gtk::ComboBoxText saveCombo_;
            
            Gtk::Image        logo1_;
            Gtk::Image        logo2_;

            double V_;
            double dt_;
            double tf_;
            double alfa_;
            
            std::string energy_;
            
            bool        plotButtonBool_;

            ASALI::batchEquations *eq_;


    };
}

#endif
