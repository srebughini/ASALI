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

#include <gtkmm.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctime>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <limits>
#include <thread>
#include "canteraInterface.h"
#include "speciesPopup.h"
#include "asaliKinetic.h"
#include "asaliProperties.h"
#include "asaliPlot.h"
#include "runBar.h"
#include "BatchInterface.h"
#include "BatchEquations.h"
#include "Ph1DodeInterface.h"
#include "Ph1DbvpInterface.h"
#include "Ph1DEquations.h"
#include "CstrInterface.h"
#include "CstrEquations.h"

namespace ASALI
{
    class Asali : public Gtk::Window
    {
        public:
            Asali();
            
            virtual ~Asali();
            
            #include "UnitConversion.H"
            
        private:

            void exit();
            void discrimer();
            void inputReader();
            void coverageReader();
            void vacuumReader();
            void batchReader();
            void ph1dReader();
            void cstrReader();
            void showAtomNames();
            void transportMenu();
            void thermoMenu();
            void allMenu();
            void vacuumMenu();
            void equilibriumMenu();
            void transportResults();
            void thermoResults();
            void allResults();
            void equilibriumResults();
            void vacuumRun();
            void equilibriumRun();
            void transportSave();
            void thermoSave();
            void allSave();
            void batchSave();
            void ph1dSave();
            void cstrSave();
            void vacuumSave();
            void equilibriumSave();
            void cpUnitConversion(bool check);
            void sUnitConversion(bool check);
            void hUnitConversion(bool check);
            void condUnitConversion(bool check);
            void diffUnitConversion(bool check);
            void diffSpecies(unsigned int row);
            void initialFractionUnitConversion();
            void finalFractionUnitConversion();
            void muUnitConversion(bool check);
            void mainMenu();
            void savedMessage();
            void noneInputError();
            void vacuumEvaluation();
            void changeCursor();
            void availableSpecies();
            void loadCanteraInput();
            void defaultCanteraInput();
            void noneInput();
            void chemistryMenu2();
            void reactorKineticMenu();
            void reactorsInput(const bool back);
            void batchMenu();
            void batchRecap();
            void batchRun();
            void batchPlot();
            void batchBar(const double fraction);
            void ph1dMenu();
            void ph1dRecap();
            void ph1dRun();
            void ph1dPlot();
            void ph1dBar(const double fraction);
            void cstrMenu();
            void cstrRecap();
            void cstrRun();
            void cstrPlot();
            void cstrBar(const double fraction);
            void propertiesShow();
            void kineticReader();
            void kineticShow();
            void batchCoverage();
            void ph1dCoverage();
            void cstrCoverage();
            bool chemistryMenu1(GdkEventButton*);
            
            std::vector<bool> setReactors();
            
            std::string       getBeer();

            Gtk::Button       doneThermoButton_;
            Gtk::Button       doneTransportButton_;
            Gtk::Button       doneAllButton_;
            Gtk::Button       doneReactorsButton_;
            Gtk::Button       discrimerButton_;
            Gtk::Button       canteraInputButton_;
            Gtk::Button       transportButton_;
            Gtk::Button       thermoButton_;
            Gtk::Button       allButton_;
            Gtk::Button       equilibriumButton_;
            Gtk::Button       reactorsButton_;
            Gtk::Button       vacuumButton_;
            Gtk::Button       transportSaveButton_;
            Gtk::Button       thermoSaveButton_;
            Gtk::Button       allSaveButton_;
            Gtk::Button       vacuumSaveButton_;
            Gtk::Button       equilibriumSaveButton_;
            Gtk::Button       batchSaveButton_;
            Gtk::Button       ph1dSaveButton_;
            Gtk::Button       cstrSaveButton_;
            Gtk::Button       calculateButton_;
            Gtk::Button       equationsButton_;
            Gtk::Button       batchRunButton_;
            Gtk::Button       ph1dRunButton_;
            Gtk::Button       cstrRunButton_;
            Gtk::Button       startButton_;
            Gtk::Button       helpButton_;
            Gtk::Button       defaultCanteraInputButton_;
            Gtk::Button       loadCanteraInputButton_;
            Gtk::Button       noneInputButton_;
            Gtk::Button       batchAsaliPropertiesButton_;
            Gtk::Button       batchAsaliKineticButton_;
            Gtk::Button       batchAsaliPlotButton_;
            Gtk::Button       ph1dAsaliPropertiesButton_;
            Gtk::Button       ph1dAsaliKineticButton_;
            Gtk::Button       ph1dAsaliPlotButton_;
            Gtk::Button       cstrAsaliPropertiesButton_;
            Gtk::Button       cstrAsaliKineticButton_;
            Gtk::Button       cstrAsaliPlotButton_;

            Gtk::Box          menuBox_;
            Gtk::Box          transportBox_;
            Gtk::Box          thermoBox_;
            Gtk::Box          allBox_;
            Gtk::Box          cpBox_;
            Gtk::Box          sBox_;
            Gtk::Box          hBox_;
            Gtk::Box          condBox_;
            Gtk::Box          muBox_;
            Gtk::Box          diffBox_;
            Gtk::Box          vacuumTempBox_;
            Gtk::Box          vacuumPressBox_;
            Gtk::Box          vacuumLengthBox_;
            Gtk::Box          vacuumDiffBox_;
            Gtk::Box          vacuumVelocityBox_;
            Gtk::Box          vacuumPathBox_;
            Gtk::Box          chemistryBox_;
            Gtk::Box          chemistryButtonsBox_;
            Gtk::Box          batchMainBox_;
            Gtk::Box          batchBox_;
            Gtk::Box          batchRecapMainBox_;
            Gtk::Box          batchRecapBox_;
            Gtk::Box          batchLogoBox_;
            Gtk::Box          ph1dMainBox_;
            Gtk::Box          ph1dLogoBox_;
            Gtk::Box          ph1dBox_;
            Gtk::Box          ph1dRecapMainBox_;
            Gtk::Box          ph1dRecapBox_;
            Gtk::Box          cstrMainBox_;
            Gtk::Box          cstrLogoBox_;
            Gtk::Box          cstrBox_;
            Gtk::Box          cstrRecapMainBox_;
            Gtk::Box          cstrRecapBox_;
            Gtk::Box          coverageBox_;

            Gtk::ButtonBox    exitButtonBox_;
            Gtk::ButtonBox    discrimerButtonBox_;
            Gtk::ButtonBox    buttonsBox_;
            Gtk::ButtonBox    startButtonBox_;
            Gtk::ButtonBox    batchButtonBox_;
            Gtk::ButtonBox    ph1dButtonBox_;
            Gtk::ButtonBox    cstrButtonBox_;
            
            Gtk::EventBox     logoEventBox_;

            Gtk::Label        heading_;
            Gtk::Label        kineticLabel_;
            Gtk::Label        beerLabel_;
            Gtk::Label        tempLabel_;
            Gtk::Label        pressLabel_;
            Gtk::Label        fractionLabel_;
            Gtk::Label        cpLabel_;
            Gtk::Label        hLabel_;
            Gtk::Label        sLabel_;
            Gtk::Label        condLabel_;
            Gtk::Label        muLabel_;
            Gtk::Label        diffLabel_;
            Gtk::Label        vacuumTempLabel_;
            Gtk::Label        vacuumPressLabel_;
            Gtk::Label        vacuumLengthLabel_;
            Gtk::Label        vacuumDiffLabel_;
            Gtk::Label        vacuumSpecieLabel_;
            Gtk::Label        vacuumKnudsenLabel_;
            Gtk::Label        vacuumVelocityLabel_;
            Gtk::Label        vacuumPathLabel_;
            Gtk::Label        reactorsTypeLabel_;
            Gtk::Label        kineticTypeLabel_;
            Gtk::Label        initialStateLabel_;
            Gtk::Label        finalStateLabel_;
            Gtk::Label        batchVolumeLabel_;
            Gtk::Label        batchLoadLabel_;
            Gtk::Label        batchTimeLabel_;
            Gtk::Label        batchSaveLabel_;
            Gtk::Label        batchEnergyLabel_;
            Gtk::Label        batchRecapVolumeLabel_;
            Gtk::Label        batchRecapVolumeUDLabel_;
            Gtk::Label        batchRecapVolumeValueLabel_;
            Gtk::Label        batchRecapTemperatureLabel_;
            Gtk::Label        batchRecapTemperatureUDLabel_;
            Gtk::Label        batchRecapTemperatureValueLabel_;
            Gtk::Label        batchRecapPressureLabel_;
            Gtk::Label        batchRecapPressureUDLabel_;
            Gtk::Label        batchRecapPressureValueLabel_;
            Gtk::Label        batchRecapTimeLabel_;
            Gtk::Label        batchRecapTimeUDLabel_;
            Gtk::Label        batchRecapTimeValueLabel_;
            Gtk::Label        batchRecapLoadLabel_;
            Gtk::Label        batchRecapLoadUDLabel_;
            Gtk::Label        batchRecapLoadValueLabel_;
            Gtk::Label        batchRecapSaveLabel_;
            Gtk::Label        batchRecapSaveUDLabel_;
            Gtk::Label        batchRecapSaveValueLabel_;
            Gtk::Label        batchRecapFractionLabel_;
            Gtk::Label        batchRecapFractionNameLabel_;
            Gtk::Label        batchRecapFractionValueLabel_;
            Gtk::Label        batchRecapEnergyLabel_;
            Gtk::Label        batchRecapEnergyValueLabel_;
            Gtk::Label        batchRecapKineticLabel_;
            Gtk::Label        batchRecapKineticValueLabel_;
            Gtk::Label        coverageLabel_;
            Gtk::Label        ph1dLengthLabel_;
            Gtk::Label        ph1dVelocityLabel_;
            Gtk::Label        ph1dLoadLabel_;
            Gtk::Label        ph1dTimeLabel_;
            Gtk::Label        ph1dSaveLabel_;
            Gtk::Label        ph1dResolutionLabel_;
            Gtk::Label        ph1dEnergyLabel_;
            Gtk::Label        ph1dPointsLabel_;
            Gtk::Label        ph1dInertLabel_;
            Gtk::Label        ph1dRecapLengthLabel_;
            Gtk::Label        ph1dRecapLengthUDLabel_;
            Gtk::Label        ph1dRecapLengthValueLabel_;
            Gtk::Label        ph1dRecapVelocityLabel_;
            Gtk::Label        ph1dRecapVelocityUDLabel_;
            Gtk::Label        ph1dRecapVelocityValueLabel_;
            Gtk::Label        ph1dRecapTemperatureLabel_;
            Gtk::Label        ph1dRecapTemperatureUDLabel_;
            Gtk::Label        ph1dRecapTemperatureValueLabel_;
            Gtk::Label        ph1dRecapPressureLabel_;
            Gtk::Label        ph1dRecapPressureUDLabel_;
            Gtk::Label        ph1dRecapPressureValueLabel_;
            Gtk::Label        ph1dRecapTimeLabel_;
            Gtk::Label        ph1dRecapTimeUDLabel_;
            Gtk::Label        ph1dRecapTimeValueLabel_;
            Gtk::Label        ph1dRecapLoadLabel_;
            Gtk::Label        ph1dRecapLoadUDLabel_;
            Gtk::Label        ph1dRecapLoadValueLabel_;
            Gtk::Label        ph1dRecapSaveLabel_;
            Gtk::Label        ph1dRecapSaveUDLabel_;
            Gtk::Label        ph1dRecapSaveValueLabel_;
            Gtk::Label        ph1dRecapPointsLabel_;
            Gtk::Label        ph1dRecapPointsUDLabel_;
            Gtk::Label        ph1dRecapPointsValueLabel_;
            Gtk::Label        ph1dRecapInertLabel_;
            Gtk::Label        ph1dRecapInertValueLabel_;
            Gtk::Label        ph1dRecapFractionLabel_;
            Gtk::Label        ph1dRecapFractionNameLabel_;
            Gtk::Label        ph1dRecapFractionValueLabel_;
            Gtk::Label        ph1dRecapResolutionLabel_;
            Gtk::Label        ph1dRecapResolutionValueLabel_;
            Gtk::Label        ph1dRecapEnergyLabel_;
            Gtk::Label        ph1dRecapEnergyValueLabel_;
            Gtk::Label        ph1dRecapKineticLabel_;
            Gtk::Label        ph1dRecapKineticValueLabel_;
            Gtk::Label        cstrVolumeLabel_;
            Gtk::Label        cstrFlowLabel_;
            Gtk::Label        cstrLoadLabel_;
            Gtk::Label        cstrTimeLabel_;
            Gtk::Label        cstrSaveLabel_;
            Gtk::Label        cstrEnergyLabel_;
            Gtk::Label        cstrRecapVolumeLabel_;
            Gtk::Label        cstrRecapVolumeUDLabel_;
            Gtk::Label        cstrRecapVolumeValueLabel_;
            Gtk::Label        cstrRecapFlowLabel_;
            Gtk::Label        cstrRecapFlowUDLabel_;
            Gtk::Label        cstrRecapFlowValueLabel_;
            Gtk::Label        cstrRecapTemperatureLabel_;
            Gtk::Label        cstrRecapTemperatureUDLabel_;
            Gtk::Label        cstrRecapTemperatureValueLabel_;
            Gtk::Label        cstrRecapPressureLabel_;
            Gtk::Label        cstrRecapPressureUDLabel_;
            Gtk::Label        cstrRecapPressureValueLabel_;
            Gtk::Label        cstrRecapTimeLabel_;
            Gtk::Label        cstrRecapTimeUDLabel_;
            Gtk::Label        cstrRecapTimeValueLabel_;
            Gtk::Label        cstrRecapLoadLabel_;
            Gtk::Label        cstrRecapLoadUDLabel_;
            Gtk::Label        cstrRecapLoadValueLabel_;
            Gtk::Label        cstrRecapSaveLabel_;
            Gtk::Label        cstrRecapSaveUDLabel_;
            Gtk::Label        cstrRecapSaveValueLabel_;
            Gtk::Label        cstrRecapFractionLabel_;
            Gtk::Label        cstrRecapFractionNameLabel_;
            Gtk::Label        cstrRecapFractionValueLabel_;
            Gtk::Label        cstrRecapEnergyLabel_;
            Gtk::Label        cstrRecapEnergyValueLabel_;
            Gtk::Label        cstrRecapKineticLabel_;
            Gtk::Label        cstrRecapKineticValueLabel_;
            Gtk::Label*       vacuumKnuResults_;
            Gtk::Label*       vacuumDiffResults_;
            Gtk::Label*       vacuumVelocityResults_;
            Gtk::Label*       vacuumPathResults_;
            
            Gtk::Grid         grid_;
            Gtk::Grid         inputGrid_;
            Gtk::Grid         thermoGrid_;
            Gtk::Grid         transportGrid_;
            Gtk::Grid         allGrid_;
            Gtk::Grid         reactorsGrid_;
            Gtk::Grid         equilibriumGrid_;
            Gtk::Grid         vacuumGrid_;
            Gtk::Grid         batchPropertiesGrid_;
            Gtk::Grid         batchRecapGrid_;
            Gtk::Grid         ph1dPropertiesGrid_;
            Gtk::Grid         ph1dRecapGrid_;
            Gtk::Grid         cstrPropertiesGrid_;
            Gtk::Grid         cstrRecapGrid_;
            Gtk::Grid         coverageInputGrid_;
            
            Gtk::Image        bigLogo_;
            Gtk::Image        chemistrySmallLogo_;
            Gtk::Image        smallLogo_;
            Gtk::Image        batchLogo1_;
            Gtk::Image        batchLogo2_;
            Gtk::Image        ph1dLogo1_;
            Gtk::Image        ph1dLogo2_;
            Gtk::Image        cstrLogo1_;
            Gtk::Image        cstrLogo2_;
            
            Gtk::Frame        batchOperatingConditionsFrame_;
            
            Gtk::Entry        tempEntry_;
            Gtk::Entry        pressEntry_;
            Gtk::Entry        vacuumSpecieEntry_;
            Gtk::Entry        vacuumTempEntry_;
            Gtk::Entry        vacuumPressEntry_;
            Gtk::Entry        vacuumLengthEntry_;
            Gtk::Entry        batchVolumeEntry_;
            Gtk::Entry        batchTimeEntry_;
            Gtk::Entry        batchLoadEntry_;
            Gtk::Entry        batchSaveEntry_;
            Gtk::Entry        ph1dLengthEntry_;
            Gtk::Entry        ph1dVelocityEntry_;
            Gtk::Entry        ph1dTimeEntry_;
            Gtk::Entry        ph1dLoadEntry_;
            Gtk::Entry        ph1dSaveEntry_;
            Gtk::Entry        ph1dPointsEntry_;
            Gtk::Entry        ph1dInertEntry_;
            Gtk::Entry        cstrVolumeEntry_;
            Gtk::Entry        cstrFlowEntry_;
            Gtk::Entry        cstrTimeEntry_;
            Gtk::Entry        cstrLoadEntry_;
            Gtk::Entry        cstrSaveEntry_;
            
            Gtk::ComboBoxText vacuumPressCombo_;
            Gtk::ComboBoxText vacuumLengthCombo_;
            Gtk::ComboBoxText vacuumTempCombo_;
            Gtk::ComboBoxText vacuumDiffCombo_;
            Gtk::ComboBoxText vacuumVelocityCombo_;
            Gtk::ComboBoxText vacuumPathCombo_;
            Gtk::ComboBoxText tempCombo_;
            Gtk::ComboBoxText pressCombo_;
            Gtk::ComboBoxText fractionCombo_;
            Gtk::ComboBoxText thermoCombo_;
            Gtk::ComboBoxText transportCombo_;
            Gtk::ComboBoxText allCombo_;
            Gtk::ComboBoxText reactorsTypeCombo_;
            Gtk::ComboBoxText kineticTypeCombo_;
            Gtk::ComboBoxText cpCombo_;
            Gtk::ComboBoxText sCombo_;
            Gtk::ComboBoxText hCombo_;
            Gtk::ComboBoxText condCombo_;
            Gtk::ComboBoxText diffCombo_;
            Gtk::ComboBoxText muCombo_;
            Gtk::ComboBoxText equilibriumCombo_;
            Gtk::ComboBoxText initialFractionCombo_;
            Gtk::ComboBoxText finalFractionCombo_;
            Gtk::ComboBoxText batchVolumeCombo_;
            Gtk::ComboBoxText batchTimeCombo_;
            Gtk::ComboBoxText batchLoadCombo_;
            Gtk::ComboBoxText batchEnergyCombo_;
            Gtk::ComboBoxText batchSaveCombo_;
            Gtk::ComboBoxText ph1dLengthCombo_;
            Gtk::ComboBoxText ph1dVelocityCombo_;
            Gtk::ComboBoxText ph1dTimeCombo_;
            Gtk::ComboBoxText ph1dLoadCombo_;
            Gtk::ComboBoxText ph1dEnergyCombo_;
            Gtk::ComboBoxText ph1dSaveCombo_;
            Gtk::ComboBoxText ph1dResolutionCombo_;
            Gtk::ComboBoxText cstrVolumeCombo_;
            Gtk::ComboBoxText cstrFlowCombo_;
            Gtk::ComboBoxText cstrTimeCombo_;
            Gtk::ComboBoxText cstrLoadCombo_;
            Gtk::ComboBoxText cstrEnergyCombo_;
            Gtk::ComboBoxText cstrSaveCombo_;
            
            std::vector<Gtk::Label *>          transportVector_;
            std::vector<Gtk::Label *>          thermoVector_;
            std::vector<Gtk::Label *>          allVector_;
            std::vector<Gtk::Label *>          cpVector_;
            std::vector<Gtk::Label *>          hVector_;
            std::vector<Gtk::Label *>          sVector_;
            std::vector<Gtk::Label *>          condVector_;
            std::vector<Gtk::Label *>          muVector_;
            std::vector<Gtk::Label *>          diffVector_;
            std::vector<Gtk::Label *>          initialFractionVector_;
            std::vector<Gtk::Label *>          finalFractionVector_;
            std::vector<Gtk::Label *>          equilibriumVector_;
            std::vector<Gtk::ComboBoxText *>   speciesCombo_;
            std::vector<Gtk::Box *>            diffBoxVector_;
            std::vector<Gtk::Entry *>          nameEntry_;
            std::vector<Gtk::Entry *>          fractionEntry_;
            std::vector<Gtk::Entry *>          coverageNameEntry_;
            std::vector<Gtk::Entry *>          coverageFractionEntry_;
            std::vector<Gtk::Button *>         exitButton_;
            std::vector<Gtk::Button *>         backButton_;
            std::vector<Gtk::Button *>         nextButton_;
            std::vector<Gtk::Button *>         mainMenuButton_;

            double         T_;
            double         Teq_;
            double         p_;
            double         d_;
            double         Kn_;
            double         diffK_;
            double         vK_;
            double         lK_;
            double         tau_;
            double         specieConverter_;
            double         V_;
            double         v_;
            double         L_;
            double         alfa_;
            double         tf_;
            double         dt_;
            double         QfromSurface_;
            double         NP_;
            double         Q_;


            std::pair<unsigned int,bool>       checkInput_;
            std::pair<unsigned int,bool>       checkCoverage_;

            std::vector<double>      cp_;
            std::vector<double>      h_;
            std::vector<double>      s_;
            std::vector<double>      x_;
            std::vector<double>      xc_;
            std::vector<double>      y_;
            std::vector<double>      xeq_;
            std::vector<double>      yeq_;
            std::vector<double>      MW_;
            std::vector<double>      cond_;
            std::vector<double>      mu_;
            std::vector<double>      yF_;
            
            std::vector<int>      index1_;
            std::vector<int>      index2_;
            std::vector<int>      canteraIndex_;
            
            std::vector<std::vector<int> >    stoich_;
            
            std::vector<std::vector<double> > diff_;
            
            std::vector<std::string> n_;
            std::vector<std::string> nc_;
           
            int            OP_;
            unsigned int   NS_;
            unsigned int   SURF_NS_;

            std::string window_;
            std::string resolution_;
            std::string energy_;
            std::string kineticType_;
            std::string kineticTypeOld_;
            std::string coverage_;
            std::string inert_;

            bool        batchBool_;
            bool        ph1dBool_;
            bool        cstrBool_;
            
            Cantera::ThermoPhase        *thermo_;
            Cantera::Transport          *transport_;
            Cantera::Kinetics           *kinetic_;
            Cantera::Interface          *surface_;
            ASALI::canteraInterface     *canteraInterface_;
            ASALI::speciesPopup         *speciesNames_;
            ASALI::asaliKinetic         *asaliKinetic_;
            ASALI::asaliProperties      *asaliProperties_;
            ASALI::asaliPlot            *asaliPlot_;
            ASALI::BatchEquations       *batch_;
            ASALI::runBar               *batchBar_;
            ASALI::Ph1DEquations        *ph1d_;
            ASALI::runBar               *ph1dBar_;
            ASALI::CstrEquations        *cstr_;
            ASALI::runBar               *cstrBar_;

            unsigned int specieIndex(const std::string n, const std::vector<std::string> v);
            
            void         checkInput(unsigned int i);
            void         checkCoverage(unsigned int i);
            
            void         cleanThermo();
            void         cleanTransport();
            void         cleanAll();

            std::vector<std::string> beer_;

    };
}
