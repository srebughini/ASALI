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


#ifndef PRESSUREDROPS_H
#define PRESSUREDROPS_H

#include "transportProperties.hpp"

namespace ASALI
{
    class pressureDrops : public ASALI::transportProperties
    {
        public:

            pressureDrops(ASALI::speciesPopup            *speciesNames,
                          std::string                     kineticType);
            
            virtual ~pressureDrops();

            virtual void results();

        private:

            void read();
            void run();
            void main();
            void options();
            void dpConversion(unsigned int i);

            Gtk::Box          mainBox_;
            Gtk::Box          secondBox_;
            Gtk::Box          logoBox_;

            Gtk::Button       calculateButton_;
            Gtk::Button       backButton3_;
            Gtk::Button       exitButton3_;

            Gtk::Grid         propertiesGrid_;

            Gtk::Label        lengthLabel_;
            Gtk::Label        velocityLabel_;
            Gtk::Label        pressureLabel_;
            Gtk::Label        beerLabel_;
            Gtk::Label        reactorTypeLabel_;
            Gtk::Label        packedBedTubeLabel_;
            Gtk::Label        packedBedParticleLabel_;
            Gtk::Label        packedBedVoidFractionLabel_;
            Gtk::Label        tubularTubeLabel_;
            Gtk::Label        tubularWallThicknessLabel_;
            Gtk::Label        honeyCombCPSILabel_;
            Gtk::Label        honeyCombWallThicknessLabel_;
            Gtk::Label        tubularDpLabel_;
            Gtk::Label        tubularDpValueLabel_;
            Gtk::Label        honeyCombDpLabel_;
            Gtk::Label        honeyCombDpValueLabel_;

            Gtk::Entry        lengthEntry_;
            Gtk::Entry        velocityEntry_;
            Gtk::Entry        timeEntry_;
            Gtk::Entry        loadEntry_;
            Gtk::Entry        saveEntry_;
            Gtk::Entry        pointsEntry_;
            Gtk::Entry        inertEntry_;
            Gtk::Entry        tubularTubeEntry_;
            Gtk::Entry        tubularWallThicknessEntry_;
            Gtk::Entry        honeyCombCPSIEntry_;
            Gtk::Entry        honeyCombWallThicknessEntry_;
            Gtk::Entry        packedBedTubeEntry_;
            Gtk::Entry        packedBedParticleEntry_;
            Gtk::Entry        packedBedVoidFractionEntry_;
            
            Gtk::ComboBoxText lengthCombo_;
            Gtk::ComboBoxText velocityCombo_;
            Gtk::ComboBoxText reactorTypeCombo_;
            Gtk::ComboBoxText tubularTubeCombo_;
            Gtk::ComboBoxText tubularWallThicknessCombo_;
            Gtk::ComboBoxText honeyCombWallThicknessCombo_;
            Gtk::ComboBoxText packedBedTubeCombo_;
            Gtk::ComboBoxText packedBedParticleCombo_;
            Gtk::ComboBoxText tubularDpCombo_;
            Gtk::ComboBoxText honeyCombDpCombo_;
            
            Gtk::Image        logo1_;
            Gtk::Image        logo2_;

            double L_;
            double v_;
            double cpsi_;
            double tw_;
            double Dt_;
            double Dp_;
            double epsi_;
            double dpTubular_;
            double dpHoneyComb_;

            std::string reactorType_;
            
            bool tubularBool_;
            bool honeyCombBool_;
            bool packedBedBool_;
            bool tubularDpBool_;
            bool honeyCombDpBool_;
            bool packedBedDpBool_;
            
            unsigned int Ndp_;

            std::vector<double>             dpPackedBed_;
            std::vector<Gtk::Label*>        packedBedDpLabel_;
            std::vector<Gtk::Label*>        packedBedDpValueLabel_;
            std::vector<Gtk::ComboBoxText*> packedBedDpCombo_;
    };
}

#endif
