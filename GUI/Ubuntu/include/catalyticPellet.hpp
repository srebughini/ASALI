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


#ifndef CATALYTICPELLET_H
#define CATALYTICPELLET_H

#include "catalyticReactors.hpp"
#include "odeInterface.hpp"
#include "bvpInterface.hpp"
#include "catalyticPelletEquations.hpp"

namespace ASALI
{
    class catalyticPellet : public ASALI::catalyticReactors
    {
        public:

            catalyticPellet(std::string kineticType);
            
            virtual ~catalyticPellet();

            virtual void input();
            virtual void read();
            virtual void recap();
            virtual void propertiesShow();
            virtual void run();
            virtual void save();
            virtual void plot();

        private:

            void pelletOptions();
            void modelOptions();
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
            
            Gtk::Label        loadLabel_;
            Gtk::Label        timeLabel_;
            Gtk::Label        saveLabel_;
            Gtk::Label        pointsLabel_;
            Gtk::Label        inertLabel_;
            Gtk::Label        epsiLabel_;
            Gtk::Label        tauLabel_;
            Gtk::Label        pelletTypeLabel_;
            Gtk::Label        modelTypeLabel_;
            Gtk::Label        beerLabel_;
            Gtk::Label        lengthLabel_;
            Gtk::Label        poreLabel_;
            Gtk::Label        recapTemperatureLabel_;
            Gtk::Label        recapTemperatureUDLabel_;
            Gtk::Label        recapTemperatureValueLabel_;
            Gtk::Label        recapPressureLabel_;
            Gtk::Label        recapPressureUDLabel_;
            Gtk::Label        recapPressureValueLabel_;
            Gtk::Label        recapTimeLabel_;
            Gtk::Label        recapTimeUDLabel_;
            Gtk::Label        recapTimeValueLabel_;
            Gtk::Label        recapSaveLabel_;
            Gtk::Label        recapSaveUDLabel_;
            Gtk::Label        recapSaveValueLabel_;
            Gtk::Label        recapPointsLabel_;
            Gtk::Label        recapPointsUDLabel_;
            Gtk::Label        recapPointsValueLabel_;
            Gtk::Label        recapInertLabel_;
            Gtk::Label        recapInertValueLabel_;
            Gtk::Label        recapEpsiLabel_;
            Gtk::Label        recapEpsiValueLabel_;
            Gtk::Label        recapTauLabel_;
            Gtk::Label        recapTauValueLabel_;
            Gtk::Label        recapPelletTypeLabel_;
            Gtk::Label        recapPelletTypeValueLabel_;
            Gtk::Label        recapModelTypeLabel_;
            Gtk::Label        recapModelTypeValueLabel_;
            Gtk::Label        recapFractionLabel_;
            Gtk::Label        recapFractionNameLabel_;
            Gtk::Label        recapFractionValueLabel_;
            Gtk::Label        recapLoadLabel_;
            Gtk::Label        recapLoadUDLabel_;
            Gtk::Label        recapLoadValueLabel_;
            Gtk::Label        recapKineticLabel_;
            Gtk::Label        recapKineticValueLabel_;
            Gtk::Label        recapLengthLabel_;
            Gtk::Label        recapLengthUDLabel_;
            Gtk::Label        recapLengthValueLabel_;
            Gtk::Label        recapPoreLabel_;
            Gtk::Label        recapPoreUDLabel_;
            Gtk::Label        recapPoreValueLabel_;

            Gtk::Entry        timeEntry_;
            Gtk::Entry        loadEntry_;
            Gtk::Entry        saveEntry_;
            Gtk::Entry        pointsEntry_;
            Gtk::Entry        inertEntry_;
            Gtk::Entry        epsiEntry_;
            Gtk::Entry        tauEntry_;
            Gtk::Entry        lengthEntry_;
            Gtk::Entry        poreEntry_;

            Gtk::ComboBoxText timeCombo_;
            Gtk::ComboBoxText loadCombo_;
            Gtk::ComboBoxText saveCombo_;
            Gtk::ComboBoxText pelletTypeCombo_;
            Gtk::ComboBoxText modelTypeCombo_;
            Gtk::ComboBoxText lengthCombo_;
            Gtk::ComboBoxText poreCombo_;
            
            Gtk::Image        logo1_;
            Gtk::Image        logo2_;

            double dt_;
            double tf_;
            double alfa_;
            double L_;
            double epsi_;
            double tau_;
            double dp_;
            
            unsigned int NP_;
            
            std::string pelletType_;
            std::string modelType_;
            
            bool        modelBool_;
            bool        recapModelBool_;
            bool        plotButtonBool_;

            ASALI::catalyticPelletEquations *eq_;


    };
}

#endif
