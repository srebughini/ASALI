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

#include "Asali.h"

namespace ASALI
{
    Asali::Asali()
    : doneThermoButton_("Done"),
      doneTransportButton_("Done"),
      doneAllButton_("Done"),
      doneReactorsButton_("Done"),
      discrimerButton_("Discrimer"),
      canteraInputButton_("Select CANTERA kinetic/properties file"),
      transportButton_("Transport properties"),
      thermoButton_("Thermodynamic properties"),
      allButton_("Thermodynamic & Transport properties"),
      equilibriumButton_("Themodynamic equilibrium (CANTERA)"),
      reactorsButton_("Catalytic reactors"),
      vacuumButton_("Vacuum properties"),
      transportSaveButton_("Save"),
      thermoSaveButton_("Save"),
      allSaveButton_("Save"),
      vacuumSaveButton_("Save"),
      equilibriumSaveButton_("Save"),
      batchSaveButton_("Save"),
      calculateButton_("Calculate"),
      equationsButton_("Equations"),
      batchRunButton_("Run"),
      startButton_("Start"),
      helpButton_("Available species"),
      defaultCanteraInputButton_("Default (only transport/thermodynamic)"),
      loadCanteraInputButton_("Load CANTERA kinetic/properties file"),
      noneInputButton_("User defined constant properties"),
      batchAsaliPropertiesButton_("Properties"),
      batchAsaliKineticButton_("Kinetics"),
      cpBox_(Gtk::ORIENTATION_VERTICAL),
      sBox_(Gtk::ORIENTATION_VERTICAL),
      hBox_(Gtk::ORIENTATION_VERTICAL),
      condBox_(Gtk::ORIENTATION_VERTICAL),
      muBox_(Gtk::ORIENTATION_VERTICAL),
      diffBox_(Gtk::ORIENTATION_VERTICAL),
      vacuumTempBox_(Gtk::ORIENTATION_VERTICAL),
      vacuumPressBox_(Gtk::ORIENTATION_VERTICAL),
      vacuumLengthBox_(Gtk::ORIENTATION_VERTICAL),
      vacuumDiffBox_(Gtk::ORIENTATION_VERTICAL),
      vacuumVelocityBox_(Gtk::ORIENTATION_VERTICAL),
      vacuumPathBox_(Gtk::ORIENTATION_VERTICAL),
      chemistryButtonsBox_(Gtk::ORIENTATION_VERTICAL),
      batchMainBox_(Gtk::ORIENTATION_VERTICAL),
      batchRecapMainBox_(Gtk::ORIENTATION_VERTICAL),
      batchRecapBox_(Gtk::ORIENTATION_VERTICAL),
      coverageBox_(Gtk::ORIENTATION_VERTICAL),
      buttonsBox_(Gtk::ORIENTATION_VERTICAL),
      batchButtonBox_(Gtk::ORIENTATION_VERTICAL),
      heading_("\nAuthor: Stefano Rebughini, PhD"
               "\nE-mail: ste.rebu@outlook.it"
               "\nhttps://github.com/srebughini/ASALI"
               "\nhttps://sourceforge.net/projects/asali"),
      kineticLabel_("<b>Please, load your CANTERA kinetic/propeties file</b>"
                    "<b>\nor select the default one (database/data.xml)</b>"
                    "\n\nLoading might take several minutes, depending"
                    "\non your system performances."),
      tempLabel_("Temperature"),
      pressLabel_("Pressure"),
      cpLabel_("Specific Heat"),
      hLabel_("Enthalpy"),
      sLabel_("Entropy"),
      condLabel_("Thermal conductivity"),
      muLabel_("Viscosity"),
      diffLabel_("Diffusivity"),
      vacuumTempLabel_("Temperature"),
      vacuumPressLabel_("Pressure"),
      vacuumLengthLabel_("Length"),
      vacuumDiffLabel_("Diffusivity"),
      vacuumSpecieLabel_("Specie"),
      vacuumKnudsenLabel_("Knudsen number"),
      vacuumVelocityLabel_("Mean gas velocity"),
      vacuumPathLabel_("Mean free path"),
      reactorsTypeLabel_("Reactor type"),
      kineticTypeLabel_("Kinetic type"),
      initialStateLabel_("Initial state"),
      finalStateLabel_("Final state"),
      batchVolumeLabel_("Volume"),
      batchLoadLabel_("Catalyst load"),
      batchTimeLabel_("Integration time"),
      batchSaveLabel_("Save solution every "),
      batchResolutionLabel_("Working at constant "),
      batchEnergyLabel_("Energy"),
      coverageLabel_("Please, insert the initial coverage composition"),
      bigLogo_("images/BigLogo.tiff"),
      chemistrySmallLogo_("images/SmallLogo.tiff"),
      smallLogo_("images/SmallLogo.tiff"),
      batchLogo1_("images/BatchLogo.tiff"),
      batchLogo2_("images/BatchLogo.tiff"),
      Kn_(-1),
      diffK_(-1),
      vK_(-1),
      lK_(-1),
      OP_(3),
      NS_(10),
      SURF_NS_(5),
      kineticType_("zero"),
      kineticTypeOld_("zero"),
      coverage_("none")
    {
        #include "Beer.H"

        batch_           = new ASALI::BatchEquations();
        asaliKinetic_    = new ASALI::asaliKinetic();
        asaliProperties_ = new ASALI::asaliProperties();

        exitButton_.resize(15);
        backButton_.resize(15);
        nextButton_.resize(15);
        mainMenuButton_.resize(15);
        for (unsigned int i=0;i<exitButton_.size();i++)
        {
            exitButton_[i] = new Gtk::Button("Exit");
            exitButton_[i]->signal_clicked().connect(sigc::mem_fun(*this,&Asali::exit));
            backButton_[i] = new Gtk::Button("< Back");
            nextButton_[i] = new Gtk::Button("Next >");
            mainMenuButton_[i] = new Gtk::Button("Menu");
            mainMenuButton_[i]->signal_clicked().connect(sigc::mem_fun(*this,&Asali::mainMenu));
        }

        //First window
        {
            this->set_border_width(15);
            this->set_title("ASALI");
            this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
            this->set_icon_from_file("images/Icon.tiff");

            //Add background grid
            this->add(grid_);

            //Adding the logo (position 1,0)
            grid_.attach(logoEventBox_,1,0,1,1);
            grid_.set_row_spacing(10);
            logoEventBox_.add(bigLogo_);
            logoEventBox_.set_events(Gdk::BUTTON_PRESS_MASK);
            logoEventBox_.signal_button_press_event().connect(sigc::mem_fun(*this,&Asali::chemistryMenu1));
            logoEventBox_.signal_realize().connect(sigc::mem_fun(*this,&Asali::changeCursor));

            //Adding beer
            beerLabel_.set_text(this->getBeer());
            beerLabel_.set_use_markup(true);
            beerLabel_.set_justify(Gtk::JUSTIFY_CENTER);
            grid_.attach(beerLabel_,1,1,1,1);

            //Adding the heading (position 1,1)
            heading_.set_justify(Gtk::JUSTIFY_LEFT);
            grid_.attach(heading_,1,2,1,1);

            //Adding starting button (position 1,2)
            grid_.attach(startButtonBox_,1,3,1,1);
            startButtonBox_.set_layout(Gtk::BUTTONBOX_CENTER);
            startButtonBox_.pack_start(startButton_, Gtk::PACK_SHRINK);
            startButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::chemistryMenu2));

            //Adding discrimer button (position 0,2)
            grid_.attach(discrimerButtonBox_,0,3,1,1);
            discrimerButtonBox_.set_layout(Gtk::BUTTONBOX_START);
            discrimerButtonBox_.pack_start(discrimerButton_, Gtk::PACK_SHRINK);
            discrimerButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::discrimer));

            //Adding exit button (position 2,2)
            grid_.attach(exitButtonBox_,2,3,1,1);
            exitButtonBox_.set_layout(Gtk::BUTTONBOX_END);
            exitButtonBox_.pack_start(*exitButton_[0], Gtk::PACK_SHRINK);

            this->show_all_children();
        }

        //Chemistry menu
        {
            //Adding logo
            chemistryBox_.set_halign(Gtk::ALIGN_START);
            chemistryBox_.set_spacing(10);
            chemistryBox_.pack_start(chemistrySmallLogo_, Gtk::PACK_SHRINK);

            //Adding thermo and transport buttons
            chemistryBox_.pack_start(chemistryButtonsBox_, Gtk::PACK_SHRINK);
            chemistryButtonsBox_.set_valign(Gtk::ALIGN_CENTER);
            chemistryButtonsBox_.set_spacing(10);
            chemistryButtonsBox_.pack_start(kineticLabel_, Gtk::PACK_SHRINK);
            kineticLabel_.set_use_markup(true);
            chemistryButtonsBox_.pack_start(defaultCanteraInputButton_, Gtk::PACK_SHRINK);
            defaultCanteraInputButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::defaultCanteraInput));
            chemistryButtonsBox_.pack_start(loadCanteraInputButton_, Gtk::PACK_SHRINK);
            loadCanteraInputButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::loadCanteraInput));
            chemistryButtonsBox_.pack_start(noneInputButton_, Gtk::PACK_SHRINK);
            noneInputButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::noneInput));
            
            //Adding exit button
            chemistryButtonsBox_.pack_start(*exitButton_[10], Gtk::PACK_SHRINK);
        }

        //Menu
        {
            //Adding logo
            menuBox_.set_halign(Gtk::ALIGN_START);
            menuBox_.set_spacing(10);
            menuBox_.pack_start(smallLogo_, Gtk::PACK_SHRINK);

            //Adding thermo and transport buttons
            menuBox_.pack_start(buttonsBox_, Gtk::PACK_SHRINK);
            buttonsBox_.set_layout(Gtk::BUTTONBOX_CENTER);
            buttonsBox_.set_spacing(10);
            buttonsBox_.set_homogeneous(true);
            buttonsBox_.pack_start(canteraInputButton_, Gtk::PACK_SHRINK);
            canteraInputButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::chemistryMenu2));
            buttonsBox_.pack_start(transportButton_, Gtk::PACK_SHRINK);
            transportButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::transportMenu));
            buttonsBox_.pack_start(thermoButton_, Gtk::PACK_SHRINK);
            thermoButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::thermoMenu));
            buttonsBox_.pack_start(allButton_, Gtk::PACK_SHRINK);
            allButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::allMenu));
            buttonsBox_.pack_start(vacuumButton_, Gtk::PACK_SHRINK);
            vacuumButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::vacuumMenu));
            buttonsBox_.pack_start(equilibriumButton_, Gtk::PACK_SHRINK);
            equilibriumButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::equilibriumMenu));
            buttonsBox_.pack_start(reactorsButton_, Gtk::PACK_SHRINK);
            reactorsButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::reactorKineticMenu));

            //Adding exit button
            buttonsBox_.pack_start(*exitButton_[1], Gtk::PACK_SHRINK);
        }
        
        //Input menu
        {
            inputGrid_.set_column_homogeneous(true);
            inputGrid_.set_column_spacing(10);
            inputGrid_.set_row_homogeneous(true);
            inputGrid_.set_row_spacing(10);

            //Add temperature selector
            inputGrid_.attach(tempLabel_,0,0,1,1);
            inputGrid_.attach(tempEntry_,1,0,1,1);
            tempEntry_.set_max_length(10);
            tempEntry_.set_text("298.15");
            inputGrid_.attach(tempCombo_,2,0,1,1);
            tempCombo_.append("K");
            tempCombo_.append("°C");
            tempCombo_.append("°F");
            tempCombo_.set_active(0);

            //Add temperature selector
            inputGrid_.attach(pressLabel_,0,1,1,1);
            inputGrid_.attach(pressEntry_,1,1,1,1);
            pressEntry_.set_max_length(10);
            pressEntry_.set_text("101325");
            inputGrid_.attach(pressCombo_,2,1,1,1);
            pressCombo_.append("Pa");
            pressCombo_.append("GPa");
            pressCombo_.append("MPa");
            pressCombo_.append("kPa");
            pressCombo_.append("bar");
            pressCombo_.append("torr");
            pressCombo_.append("mmHg");
            pressCombo_.append("atm");
            pressCombo_.set_active(0);
            
            //Add mole or mass fraction selection
            inputGrid_.attach(fractionCombo_,1,2,1,1);
            fractionCombo_.append("Mole fraction");
            fractionCombo_.append("Mass fraction");
            fractionCombo_.set_active(0);
            
            
            nameEntry_.resize(NS_);
            fractionEntry_.resize(NS_);
            for (unsigned int i=0;i<NS_;i++)
            {
                nameEntry_[i]     = new Gtk::Entry();
                fractionEntry_[i] = new Gtk::Entry();

                inputGrid_.attach(*nameEntry_[i],0,3+i,1,1);
                nameEntry_[i]->set_max_length(10);
                inputGrid_.attach(*fractionEntry_[i],1,3+i,1,1);
                fractionEntry_[i]->set_max_length(10);
                if ( i == 0 )
                {
                    nameEntry_[i]->set_text("AR");
                    fractionEntry_[i]->set_text("1");
                }
            }

            //Add help button
            helpButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::availableSpecies));

            //Add back button
            inputGrid_.attach(*backButton_[0],0,13,1,1);
            backButton_[0]->signal_clicked().connect(sigc::mem_fun(*this,&Asali::mainMenu));

            
            //Done buttons
            doneThermoButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::thermoResults));
            doneTransportButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::transportResults));
            doneAllButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::allResults));
            nextButton_[2]->signal_clicked().connect(sigc::mem_fun(*this,&Asali::equilibriumResults));

            //Go to batch recap (when ASALI kinetic is used)
            nextButton_[11]->signal_clicked().connect(sigc::mem_fun(*this,&Asali::batchRecap));

            //Go to batch coverage (when CANTERA kinetic is used)
            nextButton_[13]->signal_clicked().connect(sigc::mem_fun(*this,&Asali::batchCoverage));
            
            //Go back to reactor input
            backButton_[11]->signal_clicked().connect(sigc::bind<bool>(sigc::mem_fun(*this,&Asali::reactorsInput),true));
            backButton_[13]->signal_clicked().connect(sigc::bind<bool>(sigc::mem_fun(*this,&Asali::reactorsInput),true));
        }

        //Coverage menu
        {
            coverageBox_.set_halign(Gtk::ALIGN_START);
            coverageBox_.set_spacing(10);
            coverageBox_.pack_start(coverageLabel_, Gtk::PACK_SHRINK);
            coverageBox_.pack_start(coverageInputGrid_, Gtk::PACK_SHRINK);
            
            coverageInputGrid_.set_column_homogeneous(true);
            coverageInputGrid_.set_column_spacing(10);
            coverageInputGrid_.set_row_homogeneous(true);
            coverageInputGrid_.set_row_spacing(10);

            coverageNameEntry_.resize(SURF_NS_);
            coverageFractionEntry_.resize(SURF_NS_);
            for (unsigned int i=0;i<SURF_NS_;i++)
            {
                coverageNameEntry_[i]     = new Gtk::Entry();
                coverageFractionEntry_[i] = new Gtk::Entry();

                coverageInputGrid_.attach(*coverageNameEntry_[i],0,i,1,1);
                coverageNameEntry_[i]->set_max_length(10);
                coverageInputGrid_.attach(*coverageFractionEntry_[i],1,i,1,1);
                coverageFractionEntry_[i]->set_max_length(10);
                if ( i == 0 )
                {
                    coverageNameEntry_[i]->set_text("Pt(s)");
                    coverageFractionEntry_[i]->set_text("1");
                }
            }

            //Add back button for batch
            backButton_[14]->signal_clicked().connect(sigc::mem_fun(*this,&Asali::batchMenu));

            //Add next button for batch
            nextButton_[14]->signal_clicked().connect(sigc::mem_fun(*this,&Asali::batchRecap));
        }

        //Reactors/kinetic menu
        {
            reactorsGrid_.set_column_spacing(10);
            reactorsGrid_.set_row_spacing(10);
            reactorsGrid_.set_column_homogeneous(true);

            reactorsGrid_.attach(reactorsTypeLabel_,0,0,1,1);
            reactorsGrid_.attach(reactorsTypeCombo_,1,0,1,1);
            reactorsTypeCombo_.append("1D Pseudo-homogeneous Plug Flow Reactor");
            reactorsTypeCombo_.append("1D Heterogeneous Plug Flow Reactor");
            reactorsTypeCombo_.append("2D Pseudo-homogeneous Plug Flow Reactor");
            reactorsTypeCombo_.append("Batch Reactor");
            reactorsTypeCombo_.set_active(0);
            
            reactorsGrid_.attach(kineticTypeLabel_,0,1,1,1);
            reactorsGrid_.attach(kineticTypeCombo_,1,1,1,1);
            kineticTypeCombo_.append("CANTERA");
            kineticTypeCombo_.append("ASALI");
            kineticTypeCombo_.set_active(0);

            reactorsGrid_.attach(*backButton_[5],0,2,1,1);
            reactorsGrid_.attach(*nextButton_[5],1,2,1,1);
            backButton_[5]->signal_clicked().connect(sigc::mem_fun(*this,&Asali::mainMenu));
            nextButton_[5]->signal_clicked().connect(sigc::bind<bool>(sigc::mem_fun(*this,&Asali::reactorsInput),false));
        }
        
        //Batch reactor
        {
            batchMainBox_.set_halign(Gtk::ALIGN_START);
            batchMainBox_.set_spacing(10);
            batchMainBox_.pack_start(batchLogo1_, Gtk::PACK_SHRINK);
            batchMainBox_.pack_start(batchBox_, Gtk::PACK_SHRINK);

            batchBox_.set_halign(Gtk::ALIGN_START);
            batchBox_.set_spacing(10);
            batchBox_.pack_start(batchPropertiesGrid_, Gtk::PACK_SHRINK);
            {
                batchPropertiesGrid_.set_column_spacing(10);
                batchPropertiesGrid_.set_row_spacing(10);
                batchPropertiesGrid_.set_column_homogeneous(true);

                //Volume
                batchPropertiesGrid_.attach(batchVolumeLabel_,0,0,1,1);
                batchPropertiesGrid_.attach(batchVolumeEntry_,1,0,1,1);
                batchVolumeEntry_.set_text("1");
                batchPropertiesGrid_.attach(batchVolumeCombo_,2,0,1,1);
                batchVolumeCombo_.append("m\u00b3");
                batchVolumeCombo_.append("dm\u00b3");
                batchVolumeCombo_.append("cm\u00b3");
                batchVolumeCombo_.append("mm\u00b3");
                batchVolumeCombo_.append("cc");
                batchVolumeCombo_.append("l");
                batchVolumeCombo_.set_active(0);

                //Catalytic load
                batchPropertiesGrid_.attach(batchLoadLabel_,0,1,1,1);
                batchPropertiesGrid_.attach(batchLoadEntry_,1,1,1,1);
                batchLoadEntry_.set_text("1");
                batchPropertiesGrid_.attach(batchLoadCombo_,2,1,1,1);
                batchLoadCombo_.append("1/m");
                batchLoadCombo_.append("1/dm");
                batchLoadCombo_.append("1/cm");
                batchLoadCombo_.append("1/mm");
                batchLoadCombo_.set_active(0);

                //Time
                batchPropertiesGrid_.attach(batchTimeLabel_,0,2,1,1);
                batchPropertiesGrid_.attach(batchTimeEntry_,1,2,1,1);
                batchTimeEntry_.set_text("1");
                batchPropertiesGrid_.attach(batchTimeCombo_,2,2,1,1);
                batchTimeCombo_.append("s");
                batchTimeCombo_.append("min");
                batchTimeCombo_.append("h");
                batchTimeCombo_.append("d");
                batchTimeCombo_.set_active(0);

                //Save options
                batchPropertiesGrid_.attach(batchSaveLabel_,0,3,1,1);
                batchPropertiesGrid_.attach(batchSaveEntry_,1,3,1,1);
                batchSaveEntry_.set_text("0.1");
                batchPropertiesGrid_.attach(batchSaveCombo_,2,3,1,1);
                batchSaveCombo_.append("s");
                batchSaveCombo_.append("min");
                batchSaveCombo_.append("h");
                batchSaveCombo_.append("d");
                batchSaveCombo_.set_active(0);

                //Resolution type
                batchPropertiesGrid_.attach(batchResolutionLabel_,0,4,1,1);
                batchPropertiesGrid_.attach(batchResolutionCombo_,1,4,1,1);
                batchResolutionCombo_.append("volume");
                batchResolutionCombo_.append("pressure");
                batchResolutionCombo_.set_active(1);

                //Energy
                batchPropertiesGrid_.attach(batchEnergyLabel_,0,5,1,1);
                batchPropertiesGrid_.attach(batchEnergyCombo_,1,5,1,1);
                batchEnergyCombo_.append("on");
                batchEnergyCombo_.append("off");
                batchEnergyCombo_.set_active(1);
                
                //Buttons
                batchPropertiesGrid_.attach(*backButton_[10],0,6,1,1);
                batchPropertiesGrid_.attach(*mainMenuButton_[10],1,6,1,1);
                batchPropertiesGrid_.attach(*nextButton_[10],2,6,1,1);
                backButton_[10]->signal_clicked().connect(sigc::mem_fun(*this,&Asali::reactorKineticMenu));
                nextButton_[10]->signal_clicked().connect(sigc::mem_fun(*this,&Asali::batchMenu));
            }

            batchRecapMainBox_.set_halign(Gtk::ALIGN_START);
            batchRecapMainBox_.set_spacing(10);
            batchRecapMainBox_.pack_start(batchLogoBox_, Gtk::PACK_SHRINK);
            {
                batchLogoBox_.set_halign(Gtk::ALIGN_START);
                batchLogoBox_.set_spacing(10);
                batchLogoBox_.pack_start(batchLogo2_, Gtk::PACK_SHRINK);
                batchLogoBox_.pack_start(batchButtonBox_, Gtk::PACK_SHRINK);
                {
                    batchButtonBox_.set_layout(Gtk::BUTTONBOX_CENTER);
                    batchButtonBox_.set_spacing(10);
                    batchButtonBox_.pack_start(batchRunButton_, Gtk::PACK_SHRINK);
                    batchRunButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::batchRun));
                    batchButtonBox_.pack_start(batchSaveButton_, Gtk::PACK_SHRINK);
                    batchSaveButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::batchSave));
                    
                    batchAsaliKineticButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::kineticShow));
                    batchAsaliPropertiesButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::propertiesShow));
                }
            }

            batchRecapMainBox_.pack_start(batchRecapBox_, Gtk::PACK_SHRINK);
            {
                batchRecapBox_.set_halign(Gtk::ALIGN_START);
                batchRecapBox_.set_spacing(10);
                batchRecapBox_.pack_start(batchRecapGrid_, Gtk::PACK_SHRINK);
                {
                    batchRecapGrid_.set_column_spacing(10);
                    batchRecapGrid_.set_row_spacing(10);
                    batchRecapGrid_.set_column_homogeneous(true);
                    
                    //Volume
                    batchRecapVolumeLabel_.set_text("Volume");
                    batchRecapGrid_.attach(batchRecapVolumeLabel_,0,0,1,1);
                    batchRecapVolumeUDLabel_.set_text("m\u00b3");
                    batchRecapGrid_.attach(batchRecapVolumeUDLabel_,2,0,1,1);
                    batchRecapGrid_.attach(batchRecapVolumeValueLabel_,1,0,1,1);
                    
                    //Temperature
                    batchRecapTemperatureLabel_.set_text("Temperature");
                    batchRecapGrid_.attach(batchRecapTemperatureLabel_,0,1,1,1);
                    batchRecapTemperatureUDLabel_.set_text("K");
                    batchRecapGrid_.attach(batchRecapTemperatureUDLabel_,2,1,1,1);
                    batchRecapGrid_.attach(batchRecapTemperatureValueLabel_,1,1,1,1);

                    //Pressure
                    batchRecapPressureLabel_.set_text("Pressure");
                    batchRecapGrid_.attach(batchRecapPressureLabel_,0,2,1,1);
                    batchRecapPressureUDLabel_.set_text("Pa");
                    batchRecapGrid_.attach(batchRecapPressureUDLabel_,2,2,1,1);
                    batchRecapGrid_.attach(batchRecapPressureValueLabel_,1,2,1,1);

                    //Mole/Mass fraction
                    batchRecapGrid_.attach(batchRecapFractionLabel_,0,3,1,1);
                    batchRecapGrid_.attach(batchRecapFractionNameLabel_,1,3,1,1);
                    batchRecapGrid_.attach(batchRecapFractionValueLabel_,2,3,1,1);

                    //Load
                    batchRecapLoadLabel_.set_text("Catalyst load");
                    batchRecapGrid_.attach(batchRecapLoadLabel_,0,4,1,1);
                    batchRecapLoadUDLabel_.set_text("1/m");
                    batchRecapGrid_.attach(batchRecapLoadUDLabel_,2,4,1,1);
                    batchRecapGrid_.attach(batchRecapLoadValueLabel_,1,4,1,1);
                    
                    //Time
                    batchRecapTimeLabel_.set_text("Integration time");
                    batchRecapGrid_.attach(batchRecapTimeLabel_,0,5,1,1);
                    batchRecapTimeUDLabel_.set_text("s");
                    batchRecapGrid_.attach(batchRecapTimeUDLabel_,2,5,1,1);
                    batchRecapGrid_.attach(batchRecapTimeValueLabel_,1,5,1,1);
                    
                    //Save
                    batchRecapSaveLabel_.set_text("Save solution every");
                    batchRecapGrid_.attach(batchRecapSaveLabel_,0,6,1,1);
                    batchRecapSaveUDLabel_.set_text("s");
                    batchRecapGrid_.attach(batchRecapSaveUDLabel_,2,6,1,1);
                    batchRecapGrid_.attach(batchRecapSaveValueLabel_,1,6,1,1);
                    
                    //Resolution type
                    batchRecapResolutionLabel_.set_text("Working at constant");
                    batchRecapGrid_.attach(batchRecapResolutionLabel_,0,7,1,1);
                    batchRecapGrid_.attach(batchRecapResolutionValueLabel_,1,7,1,1);

                    //Energy type
                    batchRecapEnergyLabel_.set_text("Energy balance is");
                    batchRecapGrid_.attach(batchRecapEnergyLabel_,0,8,1,1);
                    batchRecapGrid_.attach(batchRecapEnergyValueLabel_,1,8,1,1);

                    //Kinetic type
                    batchRecapKineticLabel_.set_text("Kinetic model from");
                    batchRecapGrid_.attach(batchRecapKineticLabel_,0,9,1,1);
                    batchRecapGrid_.attach(batchRecapKineticValueLabel_,1,9,1,1);
                    //Buttons
                    batchRecapGrid_.attach(*backButton_[12],0,10,1,1);
                    batchRecapGrid_.attach(*mainMenuButton_[12],1,10,1,1);
                    batchRecapGrid_.attach(*exitButton_[12],2,10,1,1);
                    backButton_[12]->signal_clicked().connect(sigc::mem_fun(*this,&Asali::batchMenu));
                }
            }
        }

        //Thermo results menu
        {
            backButton_[1]->signal_clicked().connect(sigc::mem_fun(*this,&Asali::thermoMenu));
            thermoSaveButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::thermoSave));
        }
        
        //Transport results menu
        {
            backButton_[2]->signal_clicked().connect(sigc::mem_fun(*this,&Asali::transportMenu));
            transportSaveButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::transportSave));
        }

        //All results menu
        {
            backButton_[3]->signal_clicked().connect(sigc::mem_fun(*this,&Asali::allMenu));
            allSaveButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::allSave));
        }
        
        //Results
        {
            //Specific heat
            cpBox_.pack_start(cpLabel_, Gtk::PACK_SHRINK);
            cpBox_.pack_start(cpCombo_, Gtk::PACK_SHRINK);
            cpBox_.set_spacing(5);
            cpBox_.set_halign(Gtk::ALIGN_CENTER);
            cpCombo_.append("J/kmol/K");
            cpCombo_.append("J/mol/K");
            cpCombo_.append("J/kg/K");
            cpCombo_.append("cal/mol/K");
            cpCombo_.append("cal/kmol/K");
            cpCombo_.append("cal/kg/K");
            cpCombo_.set_active(0);
            cpCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this,&Asali::cpUnitConversion),true));

            //Entropy
            sBox_.pack_start(sLabel_, Gtk::PACK_SHRINK);
            sBox_.pack_start(sCombo_, Gtk::PACK_SHRINK);
            sBox_.set_spacing(5);
            sBox_.set_halign(Gtk::ALIGN_CENTER);
            sCombo_.append("J/kmol/K");
            sCombo_.append("J/mol/K");
            sCombo_.append("J/kg/K");
            sCombo_.append("cal/mol/K");
            sCombo_.append("cal/kmol/K");
            sCombo_.append("cal/kg/K");
            sCombo_.set_active(0);
            sCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this,&Asali::sUnitConversion),true));

            //Enthalpy
            hBox_.pack_start(hLabel_, Gtk::PACK_SHRINK);
            hBox_.pack_start(hCombo_, Gtk::PACK_SHRINK);
            hBox_.set_spacing(5);
            hBox_.set_halign(Gtk::ALIGN_CENTER);
            hCombo_.append("J/kmol");
            hCombo_.append("J/mol");
            hCombo_.append("J/kg");
            hCombo_.append("cal/kmol");
            hCombo_.append("cal/mol");
            hCombo_.append("cal/kg");
            hCombo_.set_active(0);
            hCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this,&Asali::hUnitConversion),true));

            //Thermal conductivity
            condBox_.pack_start(condLabel_, Gtk::PACK_SHRINK);
            condBox_.pack_start(condCombo_, Gtk::PACK_SHRINK);
            condBox_.set_spacing(5);
            condBox_.set_halign(Gtk::ALIGN_CENTER);
            condCombo_.append("W/m/K");
            condCombo_.append("cal/m/s/k");
            condCombo_.set_active(0);
            condCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this,&Asali::condUnitConversion),true));

            //Viscosity
            muBox_.pack_start(muLabel_, Gtk::PACK_SHRINK);
            muBox_.pack_start(muCombo_, Gtk::PACK_SHRINK);
            muBox_.set_spacing(5);
            muBox_.set_halign(Gtk::ALIGN_CENTER);
            muCombo_.append("Pas");
            muCombo_.append("cP");
            muCombo_.set_active(0);
            muCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this,&Asali::muUnitConversion),true));
            
            //Diffusivity
            diffBox_.pack_start(diffLabel_, Gtk::PACK_SHRINK);
            diffBox_.pack_start(diffCombo_, Gtk::PACK_SHRINK);
            diffBox_.set_spacing(5);
            diffBox_.set_halign(Gtk::ALIGN_CENTER);
            diffCombo_.append("m\u00b2/s");
            diffCombo_.set_active(0);
            diffCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this,&Asali::diffUnitConversion),true));
        }
    
        //Equilibrium menu
        {
            equilibriumGrid_.set_column_homogeneous(true);
            equilibriumGrid_.set_column_spacing(10);
            equilibriumGrid_.set_row_homogeneous(true);
            equilibriumGrid_.set_row_spacing(10);
            
            equilibriumGrid_.attach(equilibriumCombo_,0,1,1,1);
            equilibriumCombo_.append("Constant Pressure-Temperature");
            equilibriumCombo_.append("Constant Pressure-Enthalpy");
            equilibriumCombo_.set_active(0);
            equilibriumCombo_.signal_changed().connect(sigc::mem_fun(*this,&Asali::equilibriumRun));
            
            equilibriumGrid_.attach(initialStateLabel_,1,0,1,1);
            
            equilibriumGrid_.attach(finalStateLabel_,2,0,1,1);

            equilibriumGrid_.attach(initialFractionCombo_,1,1,1,1);
            initialFractionCombo_.append("Mole fraction");
            initialFractionCombo_.append("Mass fraction");
            initialFractionCombo_.set_active(0);
            initialFractionCombo_.signal_changed().connect(sigc::mem_fun(*this,&Asali::initialFractionUnitConversion));

            equilibriumGrid_.attach(finalFractionCombo_,2,1,1,1);
            finalFractionCombo_.append("Mole fraction");
            finalFractionCombo_.append("Mass fraction");
            finalFractionCombo_.set_active(0);
            finalFractionCombo_.signal_changed().connect(sigc::mem_fun(*this,&Asali::finalFractionUnitConversion));


            exitButton_[8]->signal_clicked().connect(sigc::mem_fun(*this,&Asali::exit));
            backButton_[8]->signal_clicked().connect(sigc::mem_fun(*this,&Asali::equilibriumMenu));
            equilibriumSaveButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::equilibriumSave));
        }

        //Vacuum menu
        {
            vacuumGrid_.set_column_homogeneous(true);
            vacuumGrid_.set_column_spacing(10);
            vacuumGrid_.set_row_spacing(10);

            //Add species
            vacuumGrid_.attach(vacuumSpecieLabel_,0,0,1,1);
            vacuumGrid_.attach(vacuumSpecieEntry_,0,1,1,1);
            vacuumSpecieEntry_.set_max_length(10);
            vacuumSpecieEntry_.set_text("AR");

            //Add temperature selector
            vacuumGrid_.attach(vacuumTempBox_,1,0,1,1);
            vacuumTempBox_.pack_start(vacuumTempLabel_, Gtk::PACK_SHRINK);
            vacuumTempBox_.pack_start(vacuumTempCombo_, Gtk::PACK_SHRINK);
            vacuumTempBox_.set_spacing(5);
            vacuumTempBox_.set_halign(Gtk::ALIGN_CENTER);
            vacuumTempCombo_.append("K");
            vacuumTempCombo_.append("°C");
            vacuumTempCombo_.append("°F");
            vacuumTempCombo_.set_active(0);
            vacuumGrid_.attach(vacuumTempEntry_,1,1,1,1);
            vacuumTempEntry_.set_max_length(10);
            vacuumTempEntry_.set_text("298.15");

            //Add temperature selector
            vacuumGrid_.attach(vacuumPressBox_,2,0,1,1);
            vacuumPressBox_.pack_start(vacuumPressLabel_, Gtk::PACK_SHRINK);
            vacuumPressBox_.pack_start(vacuumPressCombo_, Gtk::PACK_SHRINK);
            vacuumPressBox_.set_spacing(5);
            vacuumPressBox_.set_halign(Gtk::ALIGN_CENTER);
            vacuumPressCombo_.append("mbar");
            vacuumPressCombo_.append("mmHg");
            vacuumPressCombo_.append("torr");
            vacuumPressCombo_.append("Pa");
            vacuumPressCombo_.set_active(0);
            vacuumGrid_.attach(vacuumPressEntry_,2,1,1,1);
            vacuumPressEntry_.set_max_length(10);
            vacuumPressEntry_.set_text("1");

            //Add length selector
            vacuumGrid_.attach(vacuumLengthBox_,3,0,1,1);
            vacuumLengthBox_.pack_start(vacuumLengthLabel_, Gtk::PACK_SHRINK);
            vacuumLengthBox_.pack_start(vacuumLengthCombo_, Gtk::PACK_SHRINK);
            vacuumLengthBox_.set_spacing(5);
            vacuumLengthBox_.set_halign(Gtk::ALIGN_CENTER);
            vacuumLengthCombo_.append("km");
            vacuumLengthCombo_.append("m");
            vacuumLengthCombo_.append("dm");
            vacuumLengthCombo_.append("cm");
            vacuumLengthCombo_.append("mm");
            vacuumLengthCombo_.append("\u03BCm");
            vacuumLengthCombo_.append("nm");
            vacuumLengthCombo_.append("pm");
            vacuumLengthCombo_.set_active(1);
            vacuumGrid_.attach(vacuumLengthEntry_,3,1,1,1);
            vacuumLengthEntry_.set_max_length(10);
            vacuumLengthEntry_.set_text("1");

            //Add diffusion selector
            vacuumGrid_.attach(vacuumDiffBox_,0,2,1,1);
            vacuumDiffBox_.pack_start(vacuumDiffLabel_, Gtk::PACK_SHRINK);
            vacuumDiffBox_.pack_start(vacuumDiffCombo_, Gtk::PACK_SHRINK);
            vacuumDiffBox_.set_spacing(5);
            vacuumDiffBox_.set_halign(Gtk::ALIGN_CENTER);
            vacuumDiffCombo_.append("m\u00b2/s");
            vacuumDiffCombo_.append("cm\u00b2/s");
            vacuumDiffCombo_.set_active(0);
            vacuumDiffCombo_.signal_changed().connect(sigc::mem_fun(*this,&Asali::vacuumRun));

            //Add velocity selector
            vacuumGrid_.attach(vacuumVelocityBox_,1,2,1,1);
            vacuumVelocityBox_.pack_start(vacuumVelocityLabel_, Gtk::PACK_SHRINK);
            vacuumVelocityBox_.pack_start(vacuumVelocityCombo_, Gtk::PACK_SHRINK);
            vacuumVelocityBox_.set_spacing(5);
            vacuumVelocityBox_.set_halign(Gtk::ALIGN_CENTER);
            vacuumVelocityCombo_.append("km/s");
            vacuumVelocityCombo_.append("m/s");
            vacuumVelocityCombo_.append("cm/s");
            vacuumVelocityCombo_.set_active(1);
            vacuumVelocityCombo_.signal_changed().connect(sigc::mem_fun(*this,&Asali::vacuumRun));

            //Add path selector
            vacuumGrid_.attach(vacuumPathBox_,2,2,1,1);
            vacuumPathBox_.pack_start(vacuumPathLabel_, Gtk::PACK_SHRINK);
            vacuumPathBox_.pack_start(vacuumPathCombo_, Gtk::PACK_SHRINK);
            vacuumPathBox_.set_spacing(5);
            vacuumPathBox_.set_halign(Gtk::ALIGN_CENTER);
            vacuumPathCombo_.append("km");
            vacuumPathCombo_.append("m");
            vacuumPathCombo_.append("dm");
            vacuumPathCombo_.append("cm");
            vacuumPathCombo_.append("mm");
            vacuumPathCombo_.append("\u03BCm");
            vacuumPathCombo_.append("nm");
            vacuumPathCombo_.append("pm");
            vacuumPathCombo_.set_active(1);
            vacuumPathCombo_.signal_changed().connect(sigc::mem_fun(*this,&Asali::vacuumRun));

            //Add Knudsen number
            vacuumGrid_.attach(vacuumKnudsenLabel_,3,2,1,1);
            vacuumGrid_.attach(calculateButton_,1,5,1,1);
            vacuumGrid_.attach(vacuumSaveButton_,2,5,1,1);
            calculateButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::vacuumRun));
            vacuumSaveButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::vacuumSave));
            vacuumGrid_.attach(*exitButton_[9],3,5,1,1);
            vacuumGrid_.attach(*backButton_[9],0,5,1,1);
            exitButton_[9]->signal_clicked().connect(sigc::mem_fun(*this,&Asali::exit));
            backButton_[9]->signal_clicked().connect(sigc::mem_fun(*this,&Asali::mainMenu));
        }
    }

    Asali::~Asali()
    {
    }

    #include "PropertiesFunctions.H"
    #include "ReactorsFunctions.H"
    #include "VacuumFunctions.H"
    #include "EquilibriumFunctions.H"

    void Asali::changeCursor()
    {
        logoEventBox_.get_window()->set_cursor(Gdk::Cursor::create(Gdk::HAND1));
    }

    bool Asali::chemistryMenu1(GdkEventButton*)
    {
        //Clean the window
        this->remove();
        this->set_title("ASALI");

        //Add menu box
        this->add(chemistryBox_);

        //Resize
        this->resize(chemistryBox_.get_width(),chemistryBox_.get_height());

        this->show_all_children();

        return true;
    }

    void Asali::chemistryMenu2()
    {
        //Clean the window
        this->remove();
        this->set_title("ASALI");

        //Add menu box
        this->add(chemistryBox_);

        //Resize
        this->resize(chemistryBox_.get_width(),chemistryBox_.get_height());

        this->show_all_children();
    }

    void Asali::mainMenu()
    {
        //Clean the window
        this->remove();
        this->set_title("ASALI");

        //Add menu box
        this->add(menuBox_);

        //Resize
        this->resize(menuBox_.get_width(),menuBox_.get_height());

        this->show_all_children();
    }

    void Asali::discrimer()
    {
        Gtk::MessageDialog dialog(*this,"ASALI is free software: You can redistribute it and/or modify\n"
                                        " it the terms of the GNU General Public License as published by\n"
                                        "the Free Software Foundation, either version 3 of the License,\n"
                                        "or (at your option) any later version.\n"
                                        "\nASALI is distributed in the hope that it will be useful,\n"
                                        "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
                                        "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n"
                                        "\nSee the GNU General Public License for more details.\n"
                                        "You should have received a copy of the GNU General Public License\n"
                                        "along with ASALI. If not, see http://www.gnu.org/licenses/.\n",true,Gtk::MESSAGE_OTHER);
        dialog.run();
    }
    
    void Asali::savedMessage()
    {
        Gtk::MessageDialog dialog(*this,"Your file has been saved.\nThank you for using ASALI.",true,Gtk::MESSAGE_OTHER);
        dialog.set_secondary_text(this->getBeer(),true);
        dialog.run();
    }

    void Asali::noneInputError()
    {
        Gtk::MessageDialog dialog(*this,"This feauture is not available. To use it, please, select a CANTERA kinetic/properties file.",true,Gtk::MESSAGE_OTHER);
        dialog.set_secondary_text(this->getBeer(),true);
        dialog.run();
    }

    void Asali::coverageReader()
    {
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            std::vector<std::string>   n(SURF_NS_);
            std::vector<Glib::ustring> x(SURF_NS_);
            
            for (unsigned int i=0;i<SURF_NS_;i++)
            {
                n[i] = coverageNameEntry_[i]->get_text().c_str();
                x[i] = coverageFractionEntry_[i]->get_text().c_str();
            }

            nc_.clear();
            xc_.clear();
            for (unsigned int i=0;i<SURF_NS_;i++)
            {
                if ( !n[i].empty() )
                {
                    nc_.push_back(n[i]);
                    xc_.push_back(Glib::Ascii::strtod(x[i]));
                }
            }

            std::vector<int> check(nc_.size());
            {
                for (unsigned int i=0;i<nc_.size();i++)
                {
                    check[i] = 1;
                    for (unsigned int j=0;j<surface_->nSpecies();j++)
                    {
                        if ( nc_[i] == surface_->speciesName(j) )
                        {
                            check[i] = 0;
                            break;
                        }
                    }
                }

                for (unsigned int i=0;i<check.size();i++)
                {
                    if (check[i] == 1 )
                    {
                        checkCoverage_.first  = i;
                        checkCoverage_.second = false;
                        break;
                    }
                    else
                    {
                        checkCoverage_.first  = i;
                        checkCoverage_.second = true;
                    }
                }

                {
                    double sum = 0.;
                    for(unsigned int i=0;i<xc_.size();i++)
                    {
                        sum = sum + xc_[i];
                    }
                    
                    if ( sum != 1. )
                    {
                        checkCoverage_.first  = 4444;
                        checkCoverage_.second = false;
                    }
                }
            }
        }
        else
        {
            checkCoverage_.first  = 0;
            checkCoverage_.second = true;
        }
    }

    void Asali::inputReader()
    {
        T_ = Glib::Ascii::strtod(tempEntry_.get_text());
        p_ = Glib::Ascii::strtod(pressEntry_.get_text());

        ConvertsToKelvin(T_,tempCombo_.get_active_text());
        ConvertsToPascal(p_,pressCombo_.get_active_text());

        std::vector<std::string>   n(NS_);
        std::vector<Glib::ustring> x(NS_);
        
        for (unsigned int i=0;i<NS_;i++)
        {
            n[i] = nameEntry_[i]->get_text().c_str();
            x[i] = fractionEntry_[i]->get_text().c_str();
        }

        n_.clear();
        x_.clear();
        for (unsigned int i=0;i<10;i++)
        {
            if ( !n[i].empty() )
            {
                n_.push_back(n[i]);
                x_.push_back(Glib::Ascii::strtod(x[i]));
            }
        }
        
        if ( kineticType_ == "default" ||
             kineticType_ == "load" )
        {
            std::vector<int> check = canteraInterface_->checkNames(n_);

            for (unsigned int i=0;i<check.size();i++)
            {
                if (check[i] == 1 )
                {
                    checkInput_.first  = i;
                    checkInput_.second = false;
                    break;
                }
                else
                {
                    checkInput_.first  = i;
                    checkInput_.second = true;
                }
            }

            {
                double sum = 0.;
                for(unsigned int i=0;i<x_.size();i++)
                {
                    sum = sum + x_[i];
                }
                
                if ( sum != 1. )
                {
                    checkInput_.first  = 4444;
                    checkInput_.second = false;
                }
            }
        }
        else
        {
            checkInput_.first  = 0;
            checkInput_.second = true;
        }
        
    }

    void Asali::checkInput(unsigned int i)
    {
        if ( i == 4444 )
        {
            Gtk::MessageDialog dialog(*this,"Please, the sum of mass/mole fractions should be 1.",true,Gtk::MESSAGE_WARNING);
            dialog.set_secondary_text(this->getBeer(),true);
            dialog.run();
        }
        else
        {
            Gtk::MessageDialog dialog(*this,n_[i]+" is missing!!",true,Gtk::MESSAGE_WARNING);
            dialog.set_secondary_text(this->getBeer(),true);
            dialog.run();
        }
    }

    void Asali::checkCoverage(unsigned int i)
    {
        if ( i == 4444 )
        {
            Gtk::MessageDialog dialog(*this,"Please, the sum of mass/mole fractions should be 1.",true,Gtk::MESSAGE_WARNING);
            dialog.set_secondary_text(this->getBeer(),true);
            dialog.run();
        }
        else
        {
            Gtk::MessageDialog dialog(*this,nc_[i]+" is missing!!",true,Gtk::MESSAGE_WARNING);
            dialog.set_secondary_text(this->getBeer(),true);
            dialog.run();
        }
    }

    void Asali::defaultCanteraInput()
    {
        thermo_           = Cantera::newPhase("database/data.xml","gas");
        transport_        = Cantera::newDefaultTransportMgr(thermo_);
        canteraInterface_ = new ASALI::canteraInterface(thermo_,transport_);
        speciesNames_     = new ASALI::speciesPopup();

        if ( kineticType_ == "default" )
        {
            inputGrid_.remove(helpButton_);
        }

        inputGrid_.attach(helpButton_,1,13,1,1);

        kineticType_ = "default";
        this->mainMenu();
    }
    
    void Asali::noneInput()
    {
        if ( kineticType_ == "default" )
        {
            inputGrid_.remove(helpButton_);
        }

        kineticType_ = "none";

        this->mainMenu();
    }

    void Asali::loadCanteraInput()
    {
        Gtk::FileChooserDialog dialog("",Gtk::FILE_CHOOSER_ACTION_OPEN);
        dialog.set_transient_for(*this);

        //Add response buttons
        dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
        dialog.add_button("_Open", Gtk::RESPONSE_OK);

        //Show the dialog and wait for a user response
        int result = dialog.run();

        //Handle the response
        switch(result)
        {
            case(Gtk::RESPONSE_OK):
            {
                std::string filename = dialog.get_filename();
                std::ifstream input;
                const char *path = filename.c_str();
                input.open(path);

                if (filename.find("cti")!=std::string::npos)
                {
                    #if ASALI_ON_WINDOW == 1
                        Gtk::MessageDialog dialog(*this,"On WINDOWS you should use the xml version of CANTERA input file",true,Gtk::MESSAGE_WARNING);
                        dialog.set_secondary_text(this->getBeer(),true);
                        dialog.run();
                    #else
                        std::vector<std::string> readed;
                        while (!input.eof()) 
                        {
                            std::string line;
                            getline(input,line);

                            if (line.find("name")!=std::string::npos)
                            {
                                readed.push_back(line);
                            }
                        }
                        
                        std::vector<std::string> type(2);
                        type[0] = "none";
                        type[1] = "none";
                        for (unsigned int i=0;i<readed.size();i++)
                        {
                            std::string dummyString = readed[i];

                            for (std::size_t j=0;j<dummyString.size();j++)
                            {
                                if ( dummyString.substr(j,1) == "(" )
                                {
                                    dummyString.replace(j,1," ");
                                }
                                else if ( dummyString.substr(j,1) == "\"" )
                                {
                                    dummyString.replace(j,1," ");
                                }
                                else if ( dummyString.substr(j,1) == "=" )
                                {
                                    dummyString.replace(j,1," ");
                                }
                                else if ( dummyString.substr(j,1) == "," )
                                {
                                    dummyString.replace(j,1," ");
                                }
                                else if ( dummyString.substr(j,1) == "'" )
                                {
                                    dummyString.replace(j,1," ");
                                }
                            }

                            std::vector<std::string> dummyVector;
                            dummyVector.clear();

                            std::istringstream iss(dummyString);
                            while (iss >> dummyString)
                            {
                                dummyVector.push_back(dummyString);
                            }

                            if ( dummyVector.size() > 2 )
                            {
                                for (unsigned int j=0;j<dummyVector.size()-1;j++)
                                {
                                    if (dummyVector[j] == "ideal_gas" &&
                                        dummyVector[j + 1] == "name"  )
                                    {
                                        type[0] = dummyVector[j+2];
                                        type[0].erase(std::remove(type[0].begin(), type[0].end(), '"'), type[0].end());
                                        type[0].erase(std::remove(type[0].begin(), type[0].end(), ' '), type[0].end());
                                    }
                                    else if (dummyVector[j] == "ideal_interface" &&
                                             dummyVector[j + 1] == "name"  )
                                    {
                                        type[1] = dummyVector[j+2];
                                        type[1].erase(std::remove(type[1].begin(), type[1].end(), '"'), type[1].end());
                                        type[1].erase(std::remove(type[1].begin(), type[1].end(), ' '), type[1].end());
                                    }
                                }
                            }
                            
                            if ( type[0] != "none" && type[1] != "none")
                            {
                                break;
                            }
                        }
                        
                        if ( type[0] == "none" ||
                             type[1] == "none" )
                        {
                            Gtk::MessageDialog dialog(*this,"Something is wrong in your CANTERA kinetic file.",true,Gtk::MESSAGE_WARNING);
                            dialog.set_secondary_text(this->getBeer(),true);
                            dialog.run();
                        }
                        else
                        {
                            thermo_  = Cantera::newPhase(filename,type[0]);
                            std::vector<Cantera::ThermoPhase*> phases{thermo_};
                            for (unsigned int i=0;i<thermo_->nSpecies();i++)
                            {
                                std::cout << thermo_->speciesName(i) << std::endl;
                            }

                            kinetic_    = Cantera::newKineticsMgr(thermo_->xml(), phases);
                            surface_    = Cantera::importInterface(filename,type[1],phases);
                            transport_  = Cantera::newDefaultTransportMgr(thermo_);

                            canteraInterface_ = new ASALI::canteraInterface(thermo_,transport_);

                            if ( kineticType_ == "default" )
                            {
                                inputGrid_.remove(helpButton_);
                            }

                            kineticType_ = "load";

                            dialog.hide();
                            this->mainMenu();
                            break;
                        }
                    #endif
                }
                else if (filename.find("xml")!=std::string::npos)
                {
                    std::vector<std::string> readed(2);
                    {
                        std::vector<std::string> a;
                        std::vector<std::string> b;
                        while (!input.eof()) 
                        {
                            std::string line;
                            getline(input,line);
                            if (line.find("<phase ")!=std::string::npos)
                            {
                                a.push_back(line);
                            }
                            else if (line.find("<kinetics ")!=std::string::npos)
                            {
                                b.push_back(line);
                            }
                        }
                        
                        for (unsigned int i=0;i<b.size();i++)
                        {
                            if (b[i].find("Interface")!=std::string::npos)
                            {
                                readed[1] = a[i];
                            }
                            else if (b[i].find("GasKinetics")!=std::string::npos)
                            {
                                readed[0] = a[i];
                            }
                        }
                    }
                    
                    std::vector<std::string> type(2);
                    type[0] = "none";
                    type[1] = "none";
                    for (unsigned int i=0;i<readed.size();i++)
                    {
                        std::string dummyString = readed[i];

                        for (std::size_t j=0;j<dummyString.size();j++)
                        {
                            if ( dummyString.substr(j,1) == ">" )
                            {
                                dummyString.replace(j,1," ");
                            }
                            else if ( dummyString.substr(j,1) == "\"" )
                            {
                                dummyString.replace(j,1," ");
                            }
                            else if ( dummyString.substr(j,1) == "=" )
                            {
                                dummyString.replace(j,1," ");
                            }
                        }

                        std::vector<std::string> dummyVector;
                        dummyVector.clear();

                        std::istringstream iss(dummyString);
                        while (iss >> dummyString)
                        {
                            dummyVector.push_back(dummyString);
                        }

                        if ( dummyVector.size() > 4 )
                        {
                            for (unsigned int j=0;j<dummyVector.size()-1;j++)
                            {
                                if (dummyVector[j] == "<phase"  &&
                                    dummyVector[j + 1] == "dim" &&
                                    dummyVector[j + 3] == "id" )
                                {
                                    type[i] = dummyVector[j+4];
                                    type[i].erase(std::remove(type[i].begin(), type[i].end(), '"'), type[i].end());
                                    type[i].erase(std::remove(type[i].begin(), type[i].end(), ' '), type[i].end());
                                }
                            }
                        }
                        
                        if ( type[0] != "none" && type[1] != "none")
                        {
                            break;
                        }
                    }
                    
                    if ( type[0] == "none" ||
                         type[1] == "none" )
                    {
                        Gtk::MessageDialog dialog(*this,"Something is wrong in your CANTERA kinetic file.",true,Gtk::MESSAGE_WARNING);
                        dialog.set_secondary_text(this->getBeer(),true);
                        dialog.run();
                    }
                    else
                    {
                        thermo_     = Cantera::newPhase(filename,type[0]);
                        std::vector<Cantera::ThermoPhase*>  phases{thermo_};
                        surface_    = Cantera::importInterface(filename,type[1],phases);
                        kinetic_    = Cantera::newKineticsMgr(thermo_->xml(), phases);
                        transport_  = Cantera::newDefaultTransportMgr(thermo_);
                        
                        canteraInterface_ = new ASALI::canteraInterface(thermo_,transport_);

                        if ( kineticType_ == "default" )
                        {
                            inputGrid_.remove(helpButton_);
                        }

                        kineticType_ = "load";

                        dialog.hide();
                        this->mainMenu();
                        break;
                    }
                }
                else
                {
                    Gtk::MessageDialog dialog(*this,"Something is wrong in your CANTERA kinetic file.",true,Gtk::MESSAGE_WARNING);
                    dialog.set_secondary_text(this->getBeer(),true);
                    dialog.run();
                }
            }
            case(Gtk::RESPONSE_CANCEL):
            {
                dialog.hide();
                break;
            }
            default:
            {
                std::cout << "Unexpected button clicked." << std::endl;
                break;
            }
        }
    }

    void Asali::exit()
    {
        std::cout << std::endl;
        this->hide();
    }
    
    unsigned int Asali::specieIndex(const std::string n, const std::vector<std::string> v)
    {
        unsigned int id;
        for(unsigned int i=0;i<v.size();i++)
        {
            if ( n == v[i] )
            {
                id = i;
                break;
            }
        }
        return id;
    }

    void Asali::availableSpecies()
    {
        speciesNames_->show();
    }

    std::string Asali::getBeer()
    {
        srand(time(NULL));
        int i = rand()%beer_.size();
        return beer_[i];
    }

}
