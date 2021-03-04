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

#ifndef HET1DREACTORS_H
#define HET1DREACTORS_H

#include "frontend/catalyticReactors.hpp"
#include "backend/odeInterface.hpp"
#include "backend/bvpInterface.hpp"
#include "backend/het1dEquations.hpp"

namespace ASALI
{
    class het1dReactor : public ASALI::catalyticReactors
    {
    public:
        het1dReactor(std::string kineticType);

        virtual ~het1dReactor();

        virtual void input();
        virtual void read();
        virtual void recap();
        virtual void propertiesShow();
        virtual void catalystPropertiesShow();
        virtual void run();
        virtual void save();
        virtual void plot();

    private:
        void options();
        void clean();

        Gtk::Box mainBox_;
        Gtk::Box secondBox_;
        Gtk::Box recapMainBox_;
        Gtk::Box recapBox_;
        Gtk::Box logoBox_;

        Gtk::Button exitButton3_;
        Gtk::Button exitButton4_;
        Gtk::Button nextButton3_;
        Gtk::Button backButton3_;
        Gtk::Button catalystPropertiesButton_;

        Gtk::ButtonBox recapButtonBox_;

        Gtk::Grid propertiesGrid_;
        Gtk::Grid recapGrid_;

        Gtk::Label lengthLabel_;
        Gtk::Label velocityLabel_;
        Gtk::Label loadLabel_;
        Gtk::Label timeLabel_;
        Gtk::Label saveLabel_;
        Gtk::Label energyLabel_;
        Gtk::Label pointsLabel_;
        Gtk::Label inertLabel_;
        Gtk::Label reactorTypeLabel_;
        Gtk::Label beerLabel_;
        Gtk::Label packedBedTubeLabel_;
        Gtk::Label packedBedParticleLabel_;
        Gtk::Label packedBedVoidFractionLabel_;
        Gtk::Label tubularTubeLabel_;
        Gtk::Label tubularDuctLabel_;
        Gtk::Label tubularWallThicknessLabel_;
        Gtk::Label honeyCombCPSILabel_;
        Gtk::Label honeyCombWallThicknessLabel_;
        Gtk::Label honeyCombDuctLabel_;
        Gtk::Label recapLengthLabel_;
        Gtk::Label recapLengthUDLabel_;
        Gtk::Label recapLengthValueLabel_;
        Gtk::Label recapVelocityLabel_;
        Gtk::Label recapVelocityUDLabel_;
        Gtk::Label recapVelocityValueLabel_;
        Gtk::Label recapTemperatureLabel_;
        Gtk::Label recapTemperatureUDLabel_;
        Gtk::Label recapTemperatureValueLabel_;
        Gtk::Label recapPressureLabel_;
        Gtk::Label recapPressureUDLabel_;
        Gtk::Label recapPressureValueLabel_;
        Gtk::Label recapTimeLabel_;
        Gtk::Label recapTimeUDLabel_;
        Gtk::Label recapTimeValueLabel_;
        Gtk::Label recapSaveLabel_;
        Gtk::Label recapSaveUDLabel_;
        Gtk::Label recapSaveValueLabel_;
        Gtk::Label recapPointsLabel_;
        Gtk::Label recapPointsUDLabel_;
        Gtk::Label recapPointsValueLabel_;
        Gtk::Label recapInertLabel_;
        Gtk::Label recapInertValueLabel_;
        Gtk::Label recapReactorTypeLabel_;
        Gtk::Label recapReactorTypeValueLabel_;
        Gtk::Label recapFractionLabel_;
        Gtk::Label recapFractionNameLabel_;
        Gtk::Label recapFractionValueLabel_;
        Gtk::Label recapEnergyLabel_;
        Gtk::Label recapEnergyValueLabel_;
        Gtk::Label recapKineticLabel_;
        Gtk::Label recapKineticValueLabel_;
        Gtk::Label recapTubularTubeLabel_;
        Gtk::Label recapTubularTubeUDLabel_;
        Gtk::Label recapTubularTubeValueLabel_;
        Gtk::Label recapTubularDuctLabel_;
        Gtk::Label recapTubularDuctValueLabel_;
        Gtk::Label recapTubularWallThicknessLabel_;
        Gtk::Label recapTubularWallThicknessUDLabel_;
        Gtk::Label recapTubularWallThicknessValueLabel_;
        Gtk::Label recapPackedBedTubeLabel_;
        Gtk::Label recapPackedBedTubeUDLabel_;
        Gtk::Label recapPackedBedTubeValueLabel_;
        Gtk::Label recapPackedBedVoidFractionLabel_;
        Gtk::Label recapPackedBedVoidFractionValueLabel_;
        Gtk::Label recapPackedBedParticleLabel_;
        Gtk::Label recapPackedBedParticleUDLabel_;
        Gtk::Label recapPackedBedParticleValueLabel_;
        Gtk::Label recapHoneyCombCPSILabel_;
        Gtk::Label recapHoneyCombCPSIValueLabel_;
        Gtk::Label recapHoneyCombWallThicknessLabel_;
        Gtk::Label recapHoneyCombWallThicknessUDLabel_;
        Gtk::Label recapHoneyCombWallThicknessValueLabel_;
        Gtk::Label recapHoneyCombDuctLabel_;
        Gtk::Label recapHoneyCombDuctValueLabel_;

        Gtk::Entry lengthEntry_;
        Gtk::Entry velocityEntry_;
        Gtk::Entry timeEntry_;
        Gtk::Entry loadEntry_;
        Gtk::Entry saveEntry_;
        Gtk::Entry pointsEntry_;
        Gtk::Entry inertEntry_;
        Gtk::Entry tubularTubeEntry_;
        Gtk::Entry tubularWallThicknessEntry_;
        Gtk::Entry honeyCombCPSIEntry_;
        Gtk::Entry honeyCombWallThicknessEntry_;
        Gtk::Entry packedBedTubeEntry_;
        Gtk::Entry packedBedParticleEntry_;
        Gtk::Entry packedBedVoidFractionEntry_;

        Gtk::ComboBoxText lengthCombo_;
        Gtk::ComboBoxText velocityCombo_;
        Gtk::ComboBoxText timeCombo_;
        Gtk::ComboBoxText loadCombo_;
        Gtk::ComboBoxText energyCombo_;
        Gtk::ComboBoxText saveCombo_;
        Gtk::ComboBoxText reactorTypeCombo_;
        Gtk::ComboBoxText tubularTubeCombo_;
        Gtk::ComboBoxText tubularWallThicknessCombo_;
        Gtk::ComboBoxText tubularDuctCombo_;
        Gtk::ComboBoxText honeyCombWallThicknessCombo_;
        Gtk::ComboBoxText honeyCombDuctCombo_;
        Gtk::ComboBoxText packedBedTubeCombo_;
        Gtk::ComboBoxText packedBedParticleCombo_;

        Gtk::Image logo1_;
        Gtk::Image logo2_;

        double L_;
        double v_;
        double dt_;
        double tf_;
        double alfa_;
        double cpsi_;
        double tw_;
        double Dt_;
        double Dp_;
        double epsi_;

        unsigned int NP_;

        std::string energy_;
        std::string section_;
        std::string reactorType_;

        bool tubularBool_;
        bool honeyCombBool_;
        bool packedBedBool_;
        bool plotButtonBool_;

        ASALI::het1dEquations *eq_;

        sigc::connection run_;
    };
}

#endif
