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

#include "Chini.h"

namespace ASALI
{
    Chini::Chini()
    : doneThermoButton_("Done"),
      doneTransportButton_("Done"),
      doneAllButton_("Done"),
      doneReactorsButton_("Done"),
      discrimerButton_("Discrimer"),
      transportButton_("Transport properties"),
      thermoButton_("Thermodynamic properties"),
      allButton_("Thermodynamic & Transport properties"),
      vacuumButton_("Vacuum properties"),
      reactorsButton_("Ideal reactors"),
      transportSaveButton_("Save"),
      thermoSaveButton_("Save"),
      allSaveButton_("Save"),
      reactorSaveButton_("Save kinetic"),
      vacuumSaveButton_("Save"),
      calculateButton_("Calculate"),
      equationsButton_("Equations"),
      runButton_("Run"),
      startButton_("Start"),
      loadKineticButton_("Load kinetic"),
      helpButton_("Available species"),
      cpBox_(Gtk::ORIENTATION_VERTICAL),
      sBox_(Gtk::ORIENTATION_VERTICAL),
      hBox_(Gtk::ORIENTATION_VERTICAL),
      condBox_(Gtk::ORIENTATION_VERTICAL),
      muBox_(Gtk::ORIENTATION_VERTICAL),
      diffBox_(Gtk::ORIENTATION_VERTICAL),
      EattBox_(Gtk::ORIENTATION_VERTICAL),
      kBox_(Gtk::ORIENTATION_VERTICAL),
      vacuumTempBox_(Gtk::ORIENTATION_VERTICAL),
      vacuumPressBox_(Gtk::ORIENTATION_VERTICAL),
      vacuumLengthBox_(Gtk::ORIENTATION_VERTICAL),
      vacuumDiffBox_(Gtk::ORIENTATION_VERTICAL),
      buttonsBox_(Gtk::ORIENTATION_VERTICAL),
      heading_("Author: Stefano Rebughini, PhD"
               "\nE-mail: ste.rebu@outlook.it"
               "\nhttps://github.com/srebughini"),
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
      reactorsTypeLabel_("Type"),
      reactorsTimeLabel_("Residence time"),
      reactorsReactionLabel_("Reactions"),
      kLabel_("k"),
      nLabel_("n"),
      EattLabel_("Eatt"),
      aLabel_("a"),
      bLabel_("b"),
      bigLogo_("images/BigLogo.tiff"),
      smallLogo_("images/SmallLogo.tiff"),
      equationsImage_("images/ReactorsEquations.tiff"),
      reactionImage_("images/Reaction.tiff"),
      Kn_(-1),
      diffK_(-1),
      OP_(3),
      NS_(10),
      NR_(3)
    {
        speciesNames_        = new ASALI::speciesPopup();
        properties_          = new ASALI::Properties();
        propertiesInterface_ = new ASALI::propertiesInterface(properties_);

        exitButton_.resize(9);
        backButton_.resize(9);
        nextButton_.resize(9);
        for (unsigned int i=0;i<exitButton_.size();i++)
        {
            exitButton_[i] = new Gtk::Button("Exit");
            exitButton_[i]->signal_clicked().connect(sigc::mem_fun(*this,&Chini::exit));
            backButton_[i] = new Gtk::Button("< Back");
            nextButton_[i] = new Gtk::Button("Next >");
        }

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
        logoEventBox_.signal_button_press_event().connect(sigc::mem_fun(*this,&Chini::menu));
        logoEventBox_.signal_realize().connect(sigc::mem_fun(*this,&Chini::changeCursor));

        //Adding the heading (position 1,1)
        heading_.set_justify(Gtk::JUSTIFY_LEFT);
        grid_.attach(heading_,1,1,1,1);

        //Adding starting button (position 1,2)
        grid_.attach(startButtonBox_,1,2,1,1);
        startButtonBox_.set_layout(Gtk::BUTTONBOX_CENTER);
        startButtonBox_.pack_start(startButton_, Gtk::PACK_SHRINK);
        startButton_.signal_clicked().connect(sigc::mem_fun(*this,&Chini::backToMenu));

        //Adding discrimer button (position 0,2)
        grid_.attach(discrimerButtonBox_,0,2,1,1);
        discrimerButtonBox_.set_layout(Gtk::BUTTONBOX_START);
        discrimerButtonBox_.pack_start(discrimerButton_, Gtk::PACK_SHRINK);
        discrimerButton_.signal_clicked().connect(sigc::mem_fun(*this,&Chini::discrimer));

        //Adding exit button (position 2,2)
        grid_.attach(exitButtonBox_,2,2,1,1);
        exitButtonBox_.set_layout(Gtk::BUTTONBOX_END);
        exitButtonBox_.pack_start(*exitButton_[0], Gtk::PACK_SHRINK);

        this->show_all_children();

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
            buttonsBox_.pack_start(transportButton_, Gtk::PACK_SHRINK);
            transportButton_.signal_clicked().connect(sigc::mem_fun(*this,&Chini::transportMenu));
            buttonsBox_.pack_start(thermoButton_, Gtk::PACK_SHRINK);
            thermoButton_.signal_clicked().connect(sigc::mem_fun(*this,&Chini::thermoMenu));
            buttonsBox_.pack_start(allButton_, Gtk::PACK_SHRINK);
            allButton_.signal_clicked().connect(sigc::mem_fun(*this,&Chini::allMenu));
            buttonsBox_.pack_start(vacuumButton_, Gtk::PACK_SHRINK);
            vacuumButton_.signal_clicked().connect(sigc::mem_fun(*this,&Chini::vacuumMenu));
            buttonsBox_.pack_start(reactorsButton_, Gtk::PACK_SHRINK);
            reactorsButton_.signal_clicked().connect(sigc::mem_fun(*this,&Chini::reactorsMenu1));

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
            inputGrid_.attach(helpButton_,1,13,1,1);
            helpButton_.signal_clicked().connect(sigc::mem_fun(*this,&Chini::availableSpecies));

            //Add back button
            inputGrid_.attach(*backButton_[0],0,13,1,1);
            backButton_[0]->signal_clicked().connect(sigc::mem_fun(*this,&Chini::backToMenu));
            
            //Done buttons
            doneThermoButton_.signal_clicked().connect(sigc::mem_fun(*this,&Chini::thermoResults));
            doneTransportButton_.signal_clicked().connect(sigc::mem_fun(*this,&Chini::transportResults));
            doneAllButton_.signal_clicked().connect(sigc::mem_fun(*this,&Chini::allResults));
            nextButton_[0]->signal_clicked().connect(sigc::mem_fun(*this,&Chini::reactorsMenu2));
        }

        //Reactors menu
        {
            reactorsGrid_.set_column_spacing(10);
            reactorsGrid_.set_row_spacing(10);

            reactorsGrid_.attach(reactorsDimensionGrid_,0,0,1,1);
            
            
            reactorsDimensionGrid_.set_column_spacing(10);
            reactorsDimensionGrid_.set_row_spacing(10);
            reactorsDimensionGrid_.set_column_homogeneous(true);
            
            
            //Reactor type selector
            reactorsDimensionGrid_.attach(reactorsTypeLabel_,0,0,1,1);
            reactorsDimensionGrid_.attach(reactorsTypeCombo_,1,0,1,1);
            reactorsTypeCombo_.append("PFR");
            reactorsTypeCombo_.append("CSTR");
            reactorsTypeCombo_.append("BATCH");
            reactorsTypeCombo_.set_active(0);

            //Add time selector
            reactorsDimensionGrid_.attach(reactorsTimeLabel_,0,2,1,1);
            reactorsDimensionGrid_.attach(reactorsTimeBox_,1,2,1,1);
            reactorsTimeBox_.set_halign(Gtk::ALIGN_START);
            reactorsTimeBox_.set_spacing(10);
            reactorsTimeBox_.pack_start(reactorsTimeEntry_, Gtk::PACK_SHRINK);
            reactorsTimeEntry_.set_max_length(10);
            reactorsTimeEntry_.set_text("1");
            reactorsTimeBox_.pack_start(reactorsTimeCombo_, Gtk::PACK_SHRINK);
            reactorsTimeCombo_.append("s               ");
            reactorsTimeCombo_.append("min             ");
            reactorsTimeCombo_.append("h               ");
            reactorsTimeCombo_.set_active(0);
            
            
            reactorsGrid_.attach(reactionImage_,2,0,1,1);
            
            //Reaction label
            reactorsGrid_.attach(reactorsReactionLabel_,0,1,1,1);
            
            //Reactions
            reactorsReactionBox_.resize(NR_+1);
            reactionNumbers_.resize(NR_);
            stoichCombo_.resize(NR_);
            reactionEntry_.resize(NR_);
            reactionLabel_.resize(NR_);
            for (unsigned int i=0;i<NR_;i++)
            {
                reactorsReactionBox_[i] = new Gtk::Box();
                reactorsGrid_.attach(*reactorsReactionBox_[i],0,2+i,1,1);
                reactorsReactionBox_[i]->set_halign(Gtk::ALIGN_START);
                reactorsReactionBox_[i]->set_spacing(10);
                
                reactionNumbers_[i]    = new Gtk::Label(Glib::Ascii::dtostr(i+1) + ":");
                reactorsReactionBox_[i]->pack_start(*reactionNumbers_[i], Gtk::PACK_SHRINK);
                
                stoichCombo_[i].resize(4);
                reactionEntry_[i].resize(4);
                reactionLabel_[i].resize(3);
                for (unsigned int j=0;j<4;j++)
                {
                    stoichCombo_[i][j]  = new Gtk::ComboBoxText();
                    reactionEntry_[i][j] = new Gtk::Entry();
                    
                    for (unsigned int k=1;k<10;k++)
                    {
                        stoichCombo_[i][j]->append(Glib::Ascii::dtostr(k));
                    }
                    stoichCombo_[i][j]->set_active(0);
                    reactionEntry_[i][j]->set_max_length(5);
                    reactionEntry_[i][j]->set_width_chars(5);
                    reactorsReactionBox_[i]->pack_start(*stoichCombo_[i][j], Gtk::PACK_SHRINK);
                    reactorsReactionBox_[i]->pack_start(*reactionEntry_[i][j], Gtk::PACK_SHRINK);
                    
                    if ( j == 0 )
                    {
                        reactionLabel_[i][j] = new Gtk::Label("+");
                        reactorsReactionBox_[i]->pack_start(*reactionLabel_[i][j], Gtk::PACK_SHRINK);
                    }
                    else if ( j == 1 )
                    {
                        reactionLabel_[i][j] = new Gtk::Label("---->");
                        reactorsReactionBox_[i]->pack_start(*reactionLabel_[i][j], Gtk::PACK_SHRINK);
                    }
                    else if ( j == 2 )
                    {
                        reactionLabel_[i][j] = new Gtk::Label("+");
                        reactorsReactionBox_[i]->pack_start(*reactionLabel_[i][j], Gtk::PACK_SHRINK);
                    }
                }
            }
            
            
            {
                stoichCombo_[0][0]->set_active(1);
                reactionEntry_[0][0]->set_text("H2");
                
                stoichCombo_[0][1]->set_active(0);
                reactionEntry_[0][1]->set_text("O2");
                
                stoichCombo_[0][2]->set_active(1);
                reactionEntry_[0][2]->set_text("H2O");
            }

            //Reaction parameters
            reactorsGrid_.attach(reactorsParameterGridLabels_,2,1,1,1);
            {
                reactorsParameterGridLabels_.set_column_homogeneous(true);
                reactorsParameterGridLabels_.set_column_spacing(10);
                reactorsParameterGridLabels_.set_row_homogeneous(true);
                reactorsParameterGridLabels_.set_row_spacing(10);
                reactorsParameterGridLabels_.attach(kBox_,0,0,1,1);
                kBox_.set_spacing(10);
                kBox_.pack_start(kLabel_,Gtk::PACK_SHRINK);
                kBox_.pack_start(kCombo_, Gtk::PACK_SHRINK);
                kCombo_.append("m\u00b3/s/K/mol");
                kCombo_.append("L/s/K/mol");
                kCombo_.append("cc/s/K/mol");
                kCombo_.append("m\u00b3/s/K/kmol");
                kCombo_.append("L/s/K/kmol");
                kCombo_.append("cc/s/K/kmol");
                kCombo_.set_active(0);

                reactorsParameterGridLabels_.attach(nLabel_,1,0,1,1);
                reactorsParameterGridLabels_.attach(EattBox_,2,0,1,1);
                EattBox_.set_spacing(10);
                EattBox_.pack_start(EattLabel_,Gtk::PACK_SHRINK);
                EattBox_.pack_start(EattCombo_, Gtk::PACK_SHRINK);
                EattCombo_.append("J/mol");
                EattCombo_.append("J/kmol");
                EattCombo_.append("cal/mol");
                EattCombo_.append("cal/kmol");
                EattCombo_.set_active(0);
                reactorsParameterGridLabels_.attach(aLabel_,3,0,1,1);
                reactorsParameterGridLabels_.attach(bLabel_,4,0,1,1);
                
                reactorsParameterGrid_.resize(NR_);
                kEntry_.resize(NR_);
                nEntry_.resize(NR_);
                EattEntry_.resize(NR_);
                aEntry_.resize(NR_);
                bEntry_.resize(NR_);
                for (unsigned int i=0;i<NR_;i++)
                {
                    reactorsParameterGrid_[i] = new Gtk::Grid();
                    reactorsGrid_.attach(*reactorsParameterGrid_[i],2,2+i,1,1);
                    reactorsParameterGrid_[i]->set_column_homogeneous(true);
                    reactorsParameterGrid_[i]->set_column_spacing(10);
                    reactorsParameterGrid_[i]->set_row_homogeneous(true);
                    reactorsParameterGrid_[i]->set_row_spacing(10);
                
                    kEntry_[i]    = new Gtk::Entry();
                    kEntry_[i]->set_max_length(10);
                    kEntry_[i]->set_width_chars(8);
                    nEntry_[i]    = new Gtk::Entry();
                    nEntry_[i]->set_max_length(10);
                    nEntry_[i]->set_width_chars(8);
                    EattEntry_[i] = new Gtk::Entry();
                    EattEntry_[i]->set_max_length(10);
                    EattEntry_[i]->set_width_chars(8);
                    aEntry_[i]    = new Gtk::Entry();
                    aEntry_[i]->set_max_length(10);
                    aEntry_[i]->set_width_chars(8);
                    bEntry_[i]    = new Gtk::Entry();
                    bEntry_[i]->set_max_length(10);
                    bEntry_[i]->set_width_chars(8);

                    reactorsParameterGrid_[i]->attach(*kEntry_[i]   ,0,0+i,1,1);
                    reactorsParameterGrid_[i]->attach(*nEntry_[i]   ,1,0+i,1,1);
                    reactorsParameterGrid_[i]->attach(*EattEntry_[i],2,0+i,1,1);
                    reactorsParameterGrid_[i]->attach(*aEntry_[i]   ,3,0+i,1,1);
                    reactorsParameterGrid_[i]->attach(*bEntry_[i]   ,4,0+i,1,1);
                    
                    if ( i == 0 )
                    {
                        kEntry_[i]->set_text("100");
                        nEntry_[i]->set_text("0");
                        EattEntry_[i]->set_text("0");
                        aEntry_[i]->set_text("1");
                        bEntry_[i]->set_text("0");
                    }
                        

                }
            }
            
            //Buttons
            {
                reactorsButtonGrid_.resize(2);
                for (unsigned int i=0;i<2;i++)
                {
                    reactorsButtonGrid_[i] = new Gtk::Grid();
                    reactorsButtonGrid_[i]->set_column_homogeneous(true);
                    reactorsButtonGrid_[i]->set_column_spacing(10);
                    reactorsButtonGrid_[i]->set_row_homogeneous(true);
                    reactorsButtonGrid_[i]->set_row_spacing(10);
                }

                reactorsGrid_.attach(*reactorsButtonGrid_[0],0,2+NR_,1,1);
                reactorsGrid_.attach(*reactorsButtonGrid_[1],2,2+NR_,1,1);

                reactorsButtonGrid_[0]->attach(*backButton_[5],0,0,1,1);
                backButton_[5]->signal_clicked().connect(sigc::mem_fun(*this,&Chini::reactorsMenu1));
                reactorsButtonGrid_[0]->attach(equationsButton_,1,0,1,1);
                equationsButton_.signal_clicked().connect(sigc::mem_fun(*this,&Chini::equations));
                reactorsButtonGrid_[0]->attach(loadKineticButton_,2,0,1,1);
                loadKineticButton_.signal_clicked().connect(sigc::mem_fun(*this,&Chini::loadKineticInput));

                for (unsigned int i=1;i<3;i++)
                {
                    empty_.push_back(new Gtk::Label(""));
                    reactorsButtonGrid_[0]->attach(*empty_[empty_.size() - 1],1+i,0,1,1);
                }
                
                for (unsigned int i=0;i<1;i++)
                {
                    empty_.push_back(new Gtk::Label(""));
                    reactorsButtonGrid_[1]->attach(*empty_[empty_.size() - 1],i,NR_,1,1);
                }

                reactorsButtonGrid_[1]->attach(reactorSaveButton_,1,NR_,1,1);
                reactorSaveButton_.signal_clicked().connect(sigc::mem_fun(*this,&Chini::saveKineticInput));
                reactorsButtonGrid_[1]->attach(runButton_,2,NR_,1,1);
                runButton_.signal_clicked().connect(sigc::mem_fun(*this,&Chini::runReactors));
                reactorsButtonGrid_[1]->attach(*exitButton_[7],3,NR_,1,1);
            }
        }

        //Thermo results menu
        {
            backButton_[1]->signal_clicked().connect(sigc::mem_fun(*this,&Chini::thermoMenu));
            thermoSaveButton_.signal_clicked().connect(sigc::mem_fun(*this,&Chini::thermoSave));
        }
        
        //Transport results menu
        {
            backButton_[2]->signal_clicked().connect(sigc::mem_fun(*this,&Chini::transportMenu));
            transportSaveButton_.signal_clicked().connect(sigc::mem_fun(*this,&Chini::transportSave));
        }

        //All results menu
        {
            backButton_[3]->signal_clicked().connect(sigc::mem_fun(*this,&Chini::allMenu));
            allSaveButton_.signal_clicked().connect(sigc::mem_fun(*this,&Chini::allSave));
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
            cpCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this,&Chini::cpUnitConversion),true));

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
            sCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this,&Chini::sUnitConversion),true));

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
            hCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this,&Chini::hUnitConversion),true));

            //Thermal conductivity
            condBox_.pack_start(condLabel_, Gtk::PACK_SHRINK);
            condBox_.pack_start(condCombo_, Gtk::PACK_SHRINK);
            condBox_.set_spacing(5);
            condBox_.set_halign(Gtk::ALIGN_CENTER);
            condCombo_.append("W/m/K");
            condCombo_.append("cal/m/s/k");
            condCombo_.set_active(0);
            condCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this,&Chini::condUnitConversion),true));

            //Viscosity
            muBox_.pack_start(muLabel_, Gtk::PACK_SHRINK);
            muBox_.pack_start(muCombo_, Gtk::PACK_SHRINK);
            muBox_.set_spacing(5);
            muBox_.set_halign(Gtk::ALIGN_CENTER);
            muCombo_.append("Pas");
            muCombo_.append("cP");
            muCombo_.set_active(0);
            muCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this,&Chini::muUnitConversion),true));
            
            //Diffusivity
            diffBox_.pack_start(diffLabel_, Gtk::PACK_SHRINK);
            diffBox_.pack_start(diffCombo_, Gtk::PACK_SHRINK);
            diffBox_.set_spacing(5);
            diffBox_.set_halign(Gtk::ALIGN_CENTER);
            diffCombo_.append("m\u00b2/s");
            diffCombo_.set_active(0);
            diffCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this,&Chini::diffUnitConversion),true));
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
            vacuumGrid_.attach(vacuumDiffBox_,4,0,1,1);
            vacuumDiffBox_.pack_start(vacuumDiffLabel_, Gtk::PACK_SHRINK);
            vacuumDiffBox_.pack_start(vacuumDiffCombo_, Gtk::PACK_SHRINK);
            vacuumDiffBox_.set_spacing(5);
            vacuumDiffBox_.set_halign(Gtk::ALIGN_CENTER);
            vacuumDiffCombo_.append("m\u00b2/s");
            vacuumDiffCombo_.append("cm\u00b2/s");
            vacuumDiffCombo_.set_active(0);
            vacuumDiffCombo_.signal_changed().connect(sigc::mem_fun(*this,&Chini::vacuumRun));
            
            //Add Knudsen number
            vacuumGrid_.attach(vacuumKnudsenLabel_,5,0,1,1);
            vacuumGrid_.attach(calculateButton_,1,3,1,1);
            vacuumGrid_.attach(vacuumSaveButton_,2,3,1,1);
            calculateButton_.signal_clicked().connect(sigc::mem_fun(*this,&Chini::vacuumRun));
            vacuumSaveButton_.signal_clicked().connect(sigc::mem_fun(*this,&Chini::vacuumSave));
            vacuumGrid_.attach(*exitButton_[8],5,3,1,1);
            vacuumGrid_.attach(*backButton_[8],0,3,1,1);
            exitButton_[8]->signal_clicked().connect(sigc::mem_fun(*this,&Chini::exit));
            backButton_[8]->signal_clicked().connect(sigc::mem_fun(*this,&Chini::backToMenu));
        }
    }

    Chini::~Chini()
    {
    }

    void Chini::changeCursor()
    {
        logoEventBox_.get_window()->set_cursor(Gdk::Cursor::create(Gdk::HAND1));
    }

    bool Chini::menu(GdkEventButton*)
    {
        //Clean the window
        this->remove();
        this->set_title("ASALI");

        //Add menu box
        this->add(menuBox_);

        //Resize
        this->resize(menuBox_.get_width(),menuBox_.get_height());

        this->show_all_children();

        return true;
    }

    void Chini::backToMenu()
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

    void Chini::transportMenu()
    {
        //Clean the window
        this->remove();
        this->set_title("ASALI: Transport properties");
        
        //Add thermo menu grid
        this->add(inputGrid_);
        
        if ( window_ == "transport" )
        {
            transportGrid_.remove(*backButton_[2]);
            transportGrid_.remove(*exitButton_[4]);
            transportGrid_.remove(transportSaveButton_);
            this->cleanTransport();
            inputGrid_.remove(doneTransportButton_);
            inputGrid_.attach(doneTransportButton_,2,13,1,1);
            window_ = "transportMenu";
        }
        else if ( window_ == "thermo" )
        {
            inputGrid_.remove(doneThermoButton_);
            inputGrid_.attach(doneTransportButton_,2,13,1,1);
            window_ = "transportMenu";
        }
        else if ( window_ == "all" )
        {
            this->cleanAll();
            inputGrid_.remove(doneAllButton_);
            inputGrid_.attach(doneTransportButton_,2,13,1,1);
            window_ = "transportMenu";
        }
        else if ( window_ == "transportMenu" )
        {
            inputGrid_.remove(doneTransportButton_);
            inputGrid_.attach(doneTransportButton_,2,13,1,1);
            window_ = "transportMenu";
        }
        else if ( window_ == "allMenu" )
        {
            inputGrid_.remove(doneAllButton_);
            inputGrid_.attach(doneTransportButton_,2,13,1,1);
            window_ = "transportMenu";
        }
        else if ( window_ == "thermoMenu" )
        {
            inputGrid_.remove(doneThermoButton_);
            inputGrid_.attach(doneTransportButton_,2,13,1,1);
            window_ = "transportMenu";
        }
        else if ( window_ == "reactorsMenu" )
        {
            inputGrid_.remove(*nextButton_[0]);
            inputGrid_.attach(doneTransportButton_,2,13,1,1);
            window_ = "transportMenu";
        }
        else
        {
            inputGrid_.attach(doneTransportButton_,2,13,1,1);
            window_ = "transportMenu";
        }

        //Resize
        this->resize(inputGrid_.get_width(),inputGrid_.get_height ());
        this->show_all_children();
    }

    void Chini::thermoMenu()
    {
        //Clean the window
        this->remove();
        this->set_title("ASALI: Thermodynamic properties");
        
        //Add thermo menu grid
        this->add(inputGrid_);

        if ( window_ == "thermo" )
        {
            thermoGrid_.remove(*backButton_[1]);
            thermoGrid_.remove(*exitButton_[5]);
            thermoGrid_.remove(thermoSaveButton_);
            this->cleanThermo();
            inputGrid_.remove(doneThermoButton_);
            inputGrid_.attach(doneThermoButton_,2,13,1,1);
            window_ = "thermoMenu";
        }
        else if ( window_ == "transport" )
        {
            inputGrid_.remove(doneTransportButton_);
            inputGrid_.attach(doneThermoButton_,2,13,1,1);
            window_ = "thermoMenu";
        }
        else if ( window_ == "all" )
        {
            this->cleanAll();
            inputGrid_.remove(doneAllButton_);
            inputGrid_.attach(doneThermoButton_,2,13,1,1);
            window_ = "thermoMenu";
        }
        else if ( window_ == "transportMenu" )
        {
            inputGrid_.remove(doneTransportButton_);
            inputGrid_.attach(doneThermoButton_,2,13,1,1);
            window_ = "thermoMenu";
        }
        else if ( window_ == "allMenu" )
        {
            inputGrid_.remove(doneAllButton_);
            inputGrid_.attach(doneThermoButton_,2,13,1,1);
            window_ = "thermoMenu";
        }
        else if ( window_ == "thermoMenu" )
        {
            inputGrid_.remove(doneThermoButton_);
            inputGrid_.attach(doneThermoButton_,2,13,1,1);
            window_ = "thermoMenu";
        }
        else if ( window_ == "reactorsMenu" )
        {
            inputGrid_.remove(*nextButton_[0]);
            inputGrid_.attach(doneThermoButton_,2,13,1,1);
            window_ = "thermoMenu";
        }
        else
        {
            inputGrid_.attach(doneThermoButton_,2,13,1,1);
            window_ = "thermoMenu";
        }

        //Resize
        this->resize(inputGrid_.get_width(),inputGrid_.get_height ());
        this->show_all_children();
    }

    void Chini::allMenu()
    {
        //Clean the window
        this->remove();
        this->set_title("ASALI: Thermodynamic & Transport properties");
        
        //Add thermo menu grid
        this->add(inputGrid_);

        if ( window_ == "all" )
        {
            allGrid_.remove(*backButton_[3]);
            allGrid_.remove(*exitButton_[6]);
            allGrid_.remove(allSaveButton_);
            this->cleanAll();
            inputGrid_.remove(doneAllButton_);
            inputGrid_.attach(doneAllButton_,2,13,1,1);
            window_ = "allMenu";
        }
        else if ( window_ == "transport" )
        {
            this->cleanTransport();
            inputGrid_.remove(doneTransportButton_);
            inputGrid_.attach(doneAllButton_,2,13,1,1);
            window_ = "allMenu";
        }
        else if ( window_ == "thermo" )
        {
            this->cleanThermo();
            inputGrid_.remove(doneThermoButton_);
            inputGrid_.attach(doneAllButton_,2,13,1,1);
            window_ = "allMenu";
        }
        else if ( window_ == "transportMenu" )
        {
            inputGrid_.remove(doneTransportButton_);
            inputGrid_.attach(doneAllButton_,2,13,1,1);
            window_ = "allMenu";
        }
        else if ( window_ == "allMenu" )
        {
            inputGrid_.remove(doneAllButton_);
            inputGrid_.attach(doneAllButton_,2,13,1,1);
            window_ = "allMenu";
        }
        else if ( window_ == "thermoMenu" )
        {
            inputGrid_.remove(doneThermoButton_);
            inputGrid_.attach(doneAllButton_,2,13,1,1);
            window_ = "allMenu";
        }
        else if ( window_ == "reactorsMenu" )
        {
            inputGrid_.remove(*nextButton_[0]);
            inputGrid_.attach(doneAllButton_,2,13,1,1);
            window_ = "allMenu";
        }
        else
        {
            inputGrid_.attach(doneAllButton_,2,13,1,1);
            window_ = "allMenu";
        }

        //Resize
        this->resize(inputGrid_.get_width(),inputGrid_.get_height ());
        this->show_all_children();
    }

    void Chini::vacuumMenu()
    {
        //Clean the window
        this->remove();
        this->set_title("ASALI: Vacuum properties");
        
        //Add thermo menu grid
        this->add(vacuumGrid_);
        
        this->vacuumRun();
        
        //Resize
        this->resize(vacuumGrid_.get_width(),vacuumGrid_.get_height ());
        this->show_all_children();

    }

    void Chini::reactorsMenu1()
    {
        //Clean the window
        this->remove();
        this->set_title("ASALI: Ideal reactor");
        
        //Add thermo menu grid
        this->add(inputGrid_);
        
        if ( window_ == "transport" )
        {
            this->cleanTransport();
            inputGrid_.remove(doneTransportButton_);
            inputGrid_.attach(*nextButton_[0],2,13,1,1);
            window_ = "reactorsMenu";
        }
        else if ( window_ == "thermo" )
        {
            this->cleanThermo();
            inputGrid_.remove(doneThermoButton_);
            inputGrid_.attach(*nextButton_[0],2,13,1,1);
            window_ = "reactorsMenu";
        }
        else if ( window_ == "all" )
        {
            this->cleanAll();
            inputGrid_.remove(doneAllButton_);
            inputGrid_.attach(*nextButton_[0],2,13,1,1);
            window_ = "reactorsMenu";
        }
        else if ( window_ == "transportMenu" )
        {
            inputGrid_.remove(doneTransportButton_);
            inputGrid_.attach(*nextButton_[0],2,13,1,1);
            window_ = "reactorsMenu";
        }
        else if ( window_ == "allMenu" )
        {
            inputGrid_.remove(doneAllButton_);
            inputGrid_.attach(*nextButton_[0],2,13,1,1);
            window_ = "reactorsMenu";
        }
        else if ( window_ == "thermoMenu" )
        {
            inputGrid_.remove(doneThermoButton_);
            inputGrid_.attach(*nextButton_[0],2,13,1,1);
            window_ = "reactorsMenu";
        }
        else if ( window_ == "reactorsMenu" )
        {
            inputGrid_.remove(*nextButton_[0]);
            inputGrid_.attach(*nextButton_[0],2,13,1,1);
            window_ = "reactorsMenu";
        }
        else
        {
            inputGrid_.attach(*nextButton_[0],2,13,1,1);
            window_ = "reactorsMenu";
        }

        //Resize
        this->resize(inputGrid_.get_width(),inputGrid_.get_height ());
        this->show_all_children();
    }
    
    void Chini::cleanTransport()
    {
        transportGrid_.remove(condBox_);
        if ( condVector_.size() != 0)
        {
            for (unsigned int i=0;i<condVector_.size();i++)
            {
                transportGrid_.remove(*condVector_[i]);
            }
        }
        transportGrid_.remove(muBox_);
        if ( muVector_.size() != 0)
        {
            for (unsigned int i=0;i<muVector_.size();i++)
            {
                transportGrid_.remove(*muVector_[i]);
            }
        }
        transportGrid_.remove(diffBox_);
        if ( diffBoxVector_.size() != 0)
        {
            for (unsigned int i=0;i<diffBoxVector_.size();i++)
            {
                transportGrid_.remove(*diffBoxVector_[i]);
            }
        }
    }

    void Chini::cleanThermo()
    {
        thermoGrid_.remove(cpBox_);
        if ( cpVector_.size() != 0)
        {
            for (unsigned int i=0;i<cpVector_.size();i++)
            {
                thermoGrid_.remove(*cpVector_[i]);
            }
        }
        thermoGrid_.remove(sBox_);
        if ( sVector_.size() != 0)
        {
            for (unsigned int i=0;i<sVector_.size();i++)
            {
                thermoGrid_.remove(*sVector_[i]);
            }
        }
        thermoGrid_.remove(hBox_);
        if ( hVector_.size() != 0)
        {
            for (unsigned int i=0;i<hVector_.size();i++)
            {
                thermoGrid_.remove(*hVector_[i]);
            }
        }
    }
    
    void Chini::cleanAll()
    {
        allGrid_.remove(cpBox_);
        if ( cpVector_.size() != 0)
        {
            for (unsigned int i=0;i<cpVector_.size();i++)
            {
                allGrid_.remove(*cpVector_[i]);
            }
        }
        allGrid_.remove(sBox_);
        if ( sVector_.size() != 0)
        {
            for (unsigned int i=0;i<sVector_.size();i++)
            {
                allGrid_.remove(*sVector_[i]);
            }
        }
        allGrid_.remove(hBox_);
        if ( hVector_.size() != 0)
        {
            for (unsigned int i=0;i<hVector_.size();i++)
            {
                allGrid_.remove(*hVector_[i]);
            }
        }
        allGrid_.remove(condBox_);
        if ( condVector_.size() != 0)
        {
            for (unsigned int i=0;i<condVector_.size();i++)
            {
                allGrid_.remove(*condVector_[i]);
            }
        }
        allGrid_.remove(muBox_);
        if ( muVector_.size() != 0)
        {
            for (unsigned int i=0;i<muVector_.size();i++)
            {
                allGrid_.remove(*muVector_[i]);
            }
        }
        allGrid_.remove(diffBox_);
        if ( diffBoxVector_.size() != 0)
        {
            for (unsigned int i=0;i<diffBoxVector_.size();i++)
            {
                allGrid_.remove(*diffBoxVector_[i]);
            }
        }
    }

    void Chini::reactorsMenu2()
    {
        //Read inlet composition
        this->inputReader();
        if ( checkInput_.second == false )
        {
            this->checkInput(checkInput_.first);
        }
        else
        {
            //Clean the window
            this->remove();
            this->set_title("ASALI: Ideal reactor");
            
            //Add thermo menu grid
            this->add(reactorsGrid_);
            
            //Resize
            this->resize(reactorsGrid_.get_width(),reactorsGrid_.get_height ());
            this->show_all_children();
        }
    }

    void Chini::showAtomNames()
    {
        if ( window_ == "thermo" )
        {
            if ( thermoVector_.size() != 0)
            {
                for (unsigned int i=0;i<thermoVector_.size();i++)
                {
                    thermoGrid_.remove(*thermoVector_[i]);
                }
            }

            thermoVector_.clear();
            thermoVector_.resize(n_.size());

            for (unsigned int i=0;i<n_.size();i++)
            { 
                thermoVector_[i] = new Gtk::Label(n_[i]);
                thermoGrid_.attach(*thermoVector_[i],0,i+1,1,1);
            }
        }
        else if ( window_ == "transport" )
        {
            if ( transportVector_.size() != 0)
            {
                for (unsigned int i=0;i<transportVector_.size();i++)
                {
                    transportGrid_.remove(*transportVector_[i]);
                }
            }

            transportVector_.clear();
            transportVector_.resize(n_.size());

            for (unsigned int i=0;i<n_.size();i++)
            { 
                transportVector_[i] = new Gtk::Label(n_[i]);
                transportGrid_.attach(*transportVector_[i],0,i+1,1,1);
            }
        }
        else if ( window_ == "all" )
        {
            if ( allVector_.size() != 0)
            {
                for (unsigned int i=0;i<allVector_.size();i++)
                {
                    allGrid_.remove(*allVector_[i]);
                }
            }

            allVector_.clear();
            allVector_.resize(n_.size());

            for (unsigned int i=0;i<n_.size();i++)
            { 
                allVector_[i] = new Gtk::Label(n_[i]);
                allGrid_.attach(*allVector_[i],0,i+1,1,1);
            }

        }
    }
    
    void Chini::cpUnitConversion(bool check)
    {
        if ( check == true )
        {
            if ( window_ == "thermo" )
            {
                if ( cpVector_.size() != 0)
                {
                    for (unsigned int i=0;i<cpVector_.size();i++)
                    {
                        thermoGrid_.remove(*cpVector_[i]);
                    }
                }
            }
            else if ( window_ == "all" )
            {
                if ( cpVector_.size() != 0)
                {
                    for (unsigned int i=0;i<cpVector_.size();i++)
                    {
                        allGrid_.remove(*cpVector_[i]);
                    }
                }
            }
        }

        cpVector_.clear();
        cpVector_.resize(n_.size());
        std::vector<double> converter(n_.size());

        if ( cpCombo_.get_active_row_number() == 0 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1.; //J/kmol/K
            }
        }
        else if ( cpCombo_.get_active_row_number() == 1 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./1.e03; //J/mol/K
            }
        }
        else if ( cpCombo_.get_active_row_number() == 2 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./MW_[i]; //J/kg/K
            }
        }
        else if ( cpCombo_.get_active_row_number() == 3 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./4.186; //cal/kmol/K
            }
        }
        else if ( cpCombo_.get_active_row_number() == 4 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./(1.e03*4.186); //cal/mol/K
            }
        }
        else if ( cpCombo_.get_active_row_number() == 5 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./(MW_[i]*4.186); //cal/kg/K
            }
        }

        if ( window_ == "thermo" )
        { 
            for (unsigned int i=0;i<n_.size();i++)
            {
                std::stringstream cp;
                cp << std::scientific << std::setprecision(OP_) << cp_[i]*converter[i];
                cpVector_[i] = new Gtk::Label(cp.str());
                thermoGrid_.attach(*cpVector_[i],1,i+1,1,1);
            }
        }
        else if ( window_ == "all" )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                std::stringstream cp;
                cp << std::scientific << std::setprecision(OP_) << cp_[i]*converter[i];
                cpVector_[i] = new Gtk::Label(cp.str());
                allGrid_.attach(*cpVector_[i],1,i+1,1,1);
            }
        }
        
        this->show_all_children();
    }

    void Chini::hUnitConversion(bool check)
    {
        if ( check == true )
        {
            if ( window_ == "thermo" )
            {
                if ( hVector_.size() != 0)
                {
                    for (unsigned int i=0;i<hVector_.size();i++)
                    {
                        thermoGrid_.remove(*hVector_[i]);
                    }
                }
            }
            else if ( window_ == "all" )
            {
                if ( hVector_.size() != 0)
                {
                    for (unsigned int i=0;i<hVector_.size();i++)
                    {
                        allGrid_.remove(*hVector_[i]);
                    }
                }
            }
        }

        hVector_.clear();
        hVector_.resize(n_.size());
        std::vector<double> converter(n_.size());

        if ( hCombo_.get_active_row_number() == 0 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1.; //J/kmol
            }
        }
        else if ( hCombo_.get_active_row_number() == 1 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./1.e03; //J/mol
            }
        }
        else if ( hCombo_.get_active_row_number() == 2 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./MW_[i]; //J/kg
            }
        }
        else if ( hCombo_.get_active_row_number() == 3 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./4.186; //cal/kmol
            }
        }
        else if ( hCombo_.get_active_row_number() == 4 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./(1.e03*4.186); //cal/mol
            }
        }
        else if ( hCombo_.get_active_row_number() == 5 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./(MW_[i]*4.186); //cal/kg
            }
        }

        if ( window_ == "thermo" )
        { 
            for (unsigned int i=0;i<n_.size();i++)
            {
                std::stringstream h;
                h << std::scientific << std::setprecision(OP_) << h_[i]*converter[i];
                hVector_[i] = new Gtk::Label(h.str());
                thermoGrid_.attach(*hVector_[i],2,i+1,1,1);
            }
        }
        else if ( window_ == "all" )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                std::stringstream h;
                h << std::scientific << std::setprecision(OP_) << h_[i]*converter[i];
                hVector_[i] = new Gtk::Label(h.str());
                allGrid_.attach(*hVector_[i],2,i+1,1,1);
            }
        }
        
        this->show_all_children();
    }
    
    void Chini::sUnitConversion(bool check)
    {
        if ( check == true )
        {
            if ( window_ == "thermo" )
            {
                if ( sVector_.size() != 0)
                {
                    for (unsigned int i=0;i<sVector_.size();i++)
                    {
                        thermoGrid_.remove(*sVector_[i]);
                    }
                }
            }
            else if ( window_ == "all" )
            {
                if ( sVector_.size() != 0)
                {
                    for (unsigned int i=0;i<sVector_.size();i++)
                    {
                        allGrid_.remove(*sVector_[i]);
                    }
                }
            }
        }

        sVector_.clear();
        sVector_.resize(n_.size());
        std::vector<double> converter(n_.size());

        if ( sCombo_.get_active_row_number() == 0 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1.; //J/kmol/K
            }
        }
        else if ( sCombo_.get_active_row_number() == 1 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./1.e03; //J/mol/K
            }
        }
        else if ( sCombo_.get_active_row_number() == 2 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./MW_[i]; //J/kg/K
            }
        }
        else if ( sCombo_.get_active_row_number() == 3 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./4.186; //cal/kmol/K
            }
        }
        else if ( sCombo_.get_active_row_number() == 4 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./(1.e03*4.186); //cal/mol/K
            }
        }
        else if ( sCombo_.get_active_row_number() == 5 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./(MW_[i]*4.186); //cal/kg/K
            }
        }

        if ( window_ == "thermo" )
        { 
            for (unsigned int i=0;i<n_.size();i++)
            {
                std::stringstream s;
                s << std::scientific << std::setprecision(OP_) << std::setprecision(OP_) << s_[i]*converter[i];
                sVector_[i] = new Gtk::Label(s.str());
                thermoGrid_.attach(*sVector_[i],3,i+1,1,1);
            }
        }
        else if ( window_ == "all" )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                std::stringstream s;
                s << std::scientific << std::setprecision(OP_) << s_[i]*converter[i];
                sVector_[i] = new Gtk::Label(s.str());
                allGrid_.attach(*sVector_[i],3,i+1,1,1);
            }
        }
        
        this->show_all_children();
    }

    void Chini::condUnitConversion(bool check)
    {
        if ( check == true )
        {
            if ( window_ == "transport" )
            {
                if ( condVector_.size() != 0)
                {
                    for (unsigned int i=0;i<condVector_.size();i++)
                    {
                        transportGrid_.remove(*condVector_[i]);
                    }
                }
            }
            else if ( window_ == "all" )
            {
                if ( condVector_.size() != 0)
                {
                    for (unsigned int i=0;i<condVector_.size();i++)
                    {
                        allGrid_.remove(*condVector_[i]);
                    }
                }
            }
        }

        condVector_.clear();
        condVector_.resize(n_.size());
        std::vector<double> converter(n_.size());

        if ( condCombo_.get_active_row_number() == 0 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1.; //W/m/K
            }
        }
        else if ( condCombo_.get_active_row_number() == 1 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./4.186; //cal/m/s/K
            }
        }

        if ( window_ == "transport" )
        { 
            for (unsigned int i=0;i<n_.size();i++)
            {
                std::stringstream cond;
                cond << std::scientific << std::setprecision(OP_) << cond_[i]*converter[i];
                condVector_[i] = new Gtk::Label(cond.str());
                transportGrid_.attach(*condVector_[i],1,i+1,1,1);
            }
        }
        else if ( window_ == "all" )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                std::stringstream cond;
                cond << std::scientific << std::setprecision(OP_) << cond_[i]*converter[i];
                condVector_[i] = new Gtk::Label(cond.str());
                allGrid_.attach(*condVector_[i],4,i+1,1,1);
            }
        }
        
        this->show_all_children();
    }

    void Chini::muUnitConversion(bool check)
    {
        if ( check == true )
        {
            if ( window_ == "transport" )
            {
                if ( muVector_.size() != 0)
                {
                    for (unsigned int i=0;i<muVector_.size();i++)
                    {
                        transportGrid_.remove(*muVector_[i]);
                    }
                }
            }
            else if ( window_ == "all" )
            {
                if ( muVector_.size() != 0)
                {
                    for (unsigned int i=0;i<muVector_.size();i++)
                    {
                        allGrid_.remove(*muVector_[i]);
                    }
                }
            }
        }

        muVector_.clear();
        muVector_.resize(n_.size());
        std::vector<double> converter(n_.size());

        if ( muCombo_.get_active_row_number() == 0 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1.; //Pa
            }
        }
        else if ( muCombo_.get_active_row_number() == 1 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1e03; //cP
            }
        }

        if ( window_ == "transport" )
        { 
            for (unsigned int i=0;i<n_.size();i++)
            {
                std::stringstream mu;
                mu << std::scientific << std::setprecision(OP_) << mu_[i]*converter[i];
                muVector_[i] = new Gtk::Label(mu.str());
                transportGrid_.attach(*muVector_[i],2,i+1,1,1);
            }
        }
        else if ( window_ == "all" )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                std::stringstream mu;
                mu << std::scientific << std::setprecision(OP_) << mu_[i]*converter[i];
                muVector_[i] = new Gtk::Label(mu.str());
                allGrid_.attach(*muVector_[i],5,i+1,1,1);
            }
        }
        
        this->show_all_children();
    }

    void Chini::diffUnitConversion(bool check)
    {
        if ( check == true )
        {
            if ( window_ == "transport" )
            {
                if ( diffBoxVector_.size() != 0)
                {
                    for (unsigned int i=0;i<diffBoxVector_.size();i++)
                    {
                        transportGrid_.remove(*diffBoxVector_[i]);
                    }
                }
            }
            else if ( window_ == "all" )
            {
                if ( diffBoxVector_.size() != 0)
                {
                    for (unsigned int i=0;i<diffBoxVector_.size();i++)
                    {
                        allGrid_.remove(*diffBoxVector_[i]);
                    }
                }
            }
        }
        
        speciesCombo_.clear();
        diffBoxVector_.clear();
        diffVector_.clear();
        speciesCombo_.resize(n_.size());
        diffBoxVector_.resize(n_.size());
        diffVector_.resize(n_.size());

        for (unsigned int i=0;i<n_.size();i++)
        { 
            speciesCombo_[i]  = new Gtk::ComboBoxText();
            diffBoxVector_[i] = new Gtk::Box();
            for (unsigned int j=0;j<n_.size();j++)
            {
                speciesCombo_[i]->append(n_[j]);
                speciesCombo_[i]->set_active(j);
            }
            speciesCombo_[i]->signal_changed().connect(sigc::bind<unsigned int>(sigc::mem_fun(*this,&Chini::diffSpecies),i));
            diffBoxVector_[i]->pack_end(*speciesCombo_[i]);
        }


        if ( window_ == "transport" )
        { 
            for (unsigned int i=0;i<n_.size();i++)
            {
                this->diffSpecies(i);
                transportGrid_.attach(*diffBoxVector_[i],3,i+1,1,1);
            }
        }
        else if ( window_ == "all" )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                this->diffSpecies(i);
                allGrid_.attach(*diffBoxVector_[i],6,i+1,1,1);
            }
        }
        
        this->show_all_children();
    }

    void Chini::diffSpecies(unsigned int row)
    {
        double converter = 0.;
        if ( diffCombo_.get_active_row_number() == 0 )
        {
            converter = 1.; //m2/s
        }

        for (unsigned int i=0;i<n_.size();i++)
        {
            if ( speciesCombo_[row]->get_active_row_number() == int(i) )
            {
                std::string diffstr = "";

                if ( diff_[row][i] == -1 )
                {
                    diffstr = "n.a.";
                    if ( diffBoxVector_[row]->get_children().size() == 1 )
                    {
                        diffBoxVector_[row]->remove(*diffBoxVector_[row]->get_children()[0]);
                    }
                    else if ( diffBoxVector_[row]->get_children().size() == 2 )
                    {
                        diffBoxVector_[row]->remove(*diffBoxVector_[row]->get_children()[0]);
                        diffBoxVector_[row]->remove(*diffBoxVector_[row]->get_children()[1]);
                    }
                }
                else
                {
                    std::stringstream diff;
                    diff << std::scientific << std::setprecision(OP_) << diff_[row][i]*converter;
                    diffstr = diffstr + diff.str() + " in ";

                    if ( diffBoxVector_[row]->get_children().size() > 1 )
                    {
                        diffBoxVector_[row]->remove(*diffBoxVector_[row]->get_children()[0]);
                    }
                }
                

                diffVector_[i] = new Gtk::Label(diffstr);
                diffBoxVector_[row]->pack_start(*diffVector_[i]);

                break;
            }
        }

        this->show_all_children();
    }

    void Chini::thermoResults()
    {
        window_ = "thermo";
        this->inputReader();
        if ( checkInput_.second == false )
        {
            this->checkInput(checkInput_.first);
        }
        else
        {
            propertiesInterface_->setTemperature(T_);
            propertiesInterface_->setPressure(p_);
            if ( fractionCombo_.get_active_row_number() == 0 )
            {
                propertiesInterface_->setMoleFraction(x_,n_);
            }
            else if ( fractionCombo_.get_active_row_number() == 1 )
            {
                propertiesInterface_->setMassFraction(x_,n_);
            }

            propertiesInterface_->thermoCalculate();
            x_.clear();
            y_.clear();
            x_.resize(n_.size());
            y_.resize(n_.size());
            {
                x_ = propertiesInterface_->moleFractions();
                y_ = propertiesInterface_->massFractions();
            }

            if ( n_.size() > 1 )
            {
                n_.push_back("mix");
            }

            cp_.clear();
            h_.clear();
            s_.clear();
            MW_.clear();
            cp_.resize(n_.size());
            s_.resize(n_.size());
            h_.resize(n_.size());
            MW_.resize(n_.size());
            

            std::vector<double> h  = propertiesInterface_->h();
            std::vector<double> cp = propertiesInterface_->cp();
            std::vector<double> s  = propertiesInterface_->s();
            std::vector<double> MW = propertiesInterface_->MW();
            
            
            for (unsigned int i=0;i<n_.size();i++)
            {
                h_[i]  = h[i];
                s_[i]  = s[i];
                cp_[i] = cp[i];
                MW_[i] = MW[i];
            }

            //Thermo grid menu
            {
                thermoGrid_.set_column_homogeneous(true);
                thermoGrid_.set_column_spacing(10);
                thermoGrid_.set_row_spacing(10);

                //Add heading
                thermoGrid_.attach(cpBox_,1,0,1,1);
                thermoGrid_.attach(hBox_,2,0,1,1);
                thermoGrid_.attach(sBox_,3,0,1,1);

                //Add back button
                thermoGrid_.attach(*backButton_[1],0,n_.size()+2,1,1);

                //Add print on file
                thermoGrid_.attach(thermoSaveButton_,1,n_.size()+2,1,1);

                //Add exit button
                thermoGrid_.attach(*exitButton_[5],3,n_.size()+2,1,1);
            }

            this->remove();
            this->add(thermoGrid_);
            this->resize(thermoGrid_.get_width(),thermoGrid_.get_height());
            this->showAtomNames();
            this->cpUnitConversion(false);
            this->hUnitConversion(false);
            this->sUnitConversion(false);
        }
    }

    void Chini::transportResults()
    {
        window_ = "transport";
        this->inputReader();

        if ( checkInput_.second == false )
        {
            this->checkInput(checkInput_.first);
        }
        else
        {
            propertiesInterface_->setTemperature(T_);
            propertiesInterface_->setPressure(p_);
            if ( fractionCombo_.get_active_row_number() == 0 )
            {
                propertiesInterface_->setMoleFraction(x_,n_);
            }
            else if ( fractionCombo_.get_active_row_number() == 1 )
            {
                propertiesInterface_->setMassFraction(x_,n_);
            }

            propertiesInterface_->transportCalculate();
            x_.clear();
            y_.clear();
            x_.resize(n_.size());
            y_.resize(n_.size());
            {
                x_ = propertiesInterface_->moleFractions();
                y_ = propertiesInterface_->massFractions();
            }

            if ( n_.size() > 1 )
            {
                n_.push_back("mix");
            }

            mu_.clear();
            cond_.clear();
            diff_.clear();
            MW_.clear();
            mu_.resize(n_.size());
            cond_.resize(n_.size());
            diff_.resize(n_.size());
            MW_.resize(n_.size());
            for (unsigned int i=0;i<n_.size();i++)
            {
                diff_[i].resize(n_.size());
            }
            
            std::vector<double>               mu   = propertiesInterface_->mu();
            std::vector<std::vector<double> > diff = propertiesInterface_->diff();
            std::vector<double>               cond = propertiesInterface_->cond();
            std::vector<double>               MW   = propertiesInterface_->MW();
            
            
            for (unsigned int i=0;i<n_.size();i++)
            {
                mu_[i]   = mu[i];
                cond_[i] = cond[i];
                MW_[i]   = MW[i];
                for (unsigned int j=0;j<n_.size();j++)
                {
                    diff_[i][j] = diff[i][j];
                } 
            }

            //Transport grid menu
            {
                transportGrid_.set_column_homogeneous(true);
                transportGrid_.set_column_spacing(10);
                transportGrid_.set_row_spacing(10);
                
                //Add heading
                transportGrid_.attach(condBox_,1,0,1,1);
                transportGrid_.attach(muBox_,2,0,1,1);
                transportGrid_.attach(diffBox_,3,0,1,1);

                //Add back button
                transportGrid_.attach(*backButton_[2],0,n_.size()+2,1,1);

                //Add print on file
                transportGrid_.attach(transportSaveButton_,1,n_.size()+2,1,1);

                //Add exit button
                transportGrid_.attach(*exitButton_[4],3,n_.size()+2,1,1);
            }

            this->remove();
            this->add(transportGrid_);
            this->resize(transportGrid_.get_width(),transportGrid_.get_height());
            this->showAtomNames();
            this->condUnitConversion(false);
            this->muUnitConversion(false);
            this->diffUnitConversion(false);
        }
    }

    void Chini::allResults()
    {
        window_ = "all";
        this->inputReader();
        if ( checkInput_.second == false )
        {
            this->checkInput(checkInput_.first);
        }
        else
        {
            propertiesInterface_->setTemperature(T_);
            propertiesInterface_->setPressure(p_);
            if ( fractionCombo_.get_active_row_number() == 0 )
            {
                propertiesInterface_->setMoleFraction(x_,n_);
            }
            else if ( fractionCombo_.get_active_row_number() == 1 )
            {
                propertiesInterface_->setMassFraction(x_,n_);
            }

            propertiesInterface_->transportCalculate();
            propertiesInterface_->thermoCalculate();
            x_.clear();
            y_.clear();
            x_.resize(n_.size());
            y_.resize(n_.size());
            {
                x_ = propertiesInterface_->moleFractions();
                y_ = propertiesInterface_->massFractions();
            }

            if ( n_.size() > 1 )
            {
                n_.push_back("mix");
            }

            MW_.clear();
            MW_.resize(n_.size());

            //Transport
            {
                mu_.clear();
                cond_.clear();
                diff_.clear();
                MW_.clear();
                mu_.resize(n_.size());
                cond_.resize(n_.size());
                diff_.resize(n_.size());
                MW_.resize(n_.size());
                for (unsigned int i=0;i<n_.size();i++)
                {
                    diff_[i].resize(n_.size());
                }
                
                std::vector<double>               mu   = propertiesInterface_->mu();
                std::vector<std::vector<double> > diff = propertiesInterface_->diff();
                std::vector<double>               cond = propertiesInterface_->cond();
                std::vector<double>               MW   = propertiesInterface_->MW();
                
                
                for (unsigned int i=0;i<n_.size();i++)
                {
                    mu_[i]   = mu[i];
                    cond_[i] = cond[i];
                    MW_[i]   = MW[i];
                    for (unsigned int j=0;j<n_.size();j++)
                    {
                        diff_[i][j] = diff[i][j];
                    } 
                }
            }

            //Thermo
            {
                cp_.clear();
                h_.clear();
                s_.clear();
                MW_.clear();
                cp_.resize(n_.size());
                s_.resize(n_.size());
                h_.resize(n_.size());
                MW_.resize(n_.size());
                

                std::vector<double> h  = propertiesInterface_->h();
                std::vector<double> cp = propertiesInterface_->cp();
                std::vector<double> s  = propertiesInterface_->s();
                std::vector<double> MW = propertiesInterface_->MW();
                
                
                for (unsigned int i=0;i<n_.size();i++)
                {
                    h_[i]  = h[i];
                    s_[i]  = s[i];
                    cp_[i] = cp[i];
                    MW_[i] = MW[i];
                }
            }

            //All grid menu
            {
                allGrid_.set_column_homogeneous(true);
                allGrid_.set_column_spacing(10);
                allGrid_.set_row_spacing(10);
                
                //Add heading
                allGrid_.attach(cpBox_,1,0,1,1);
                allGrid_.attach(hBox_,2,0,1,1);
                allGrid_.attach(sBox_,3,0,1,1);
                allGrid_.attach(condBox_,4,0,1,1);
                allGrid_.attach(muBox_,5,0,1,1);
                allGrid_.attach(diffBox_,6,0,1,1);


                //Add back button
                allGrid_.attach(*backButton_[3],0,n_.size()+2,1,1);

                //Add print on file
                allGrid_.attach(allSaveButton_,1,n_.size()+2,1,1);

                //Add exit button
                allGrid_.attach(*exitButton_[6],6,n_.size()+2,1,1);
            }

            this->remove();
            this->add(allGrid_);
            this->resize(allGrid_.get_width(),allGrid_.get_height());
            this->showAtomNames();
            this->condUnitConversion(false);
            this->muUnitConversion(false);
            this->diffUnitConversion(false);
            this->cpUnitConversion(false);
            this->sUnitConversion(false);
            this->hUnitConversion(false);
        }
    }

    void Chini::vacuumRun()
    {
        if ( diffK_ >= 0. )
        {
            vacuumGrid_.remove(*vacuumDiffResults_);
        }

        if ( Kn_ >= 0. )
        {
            vacuumGrid_.remove(*vacuumKnuResults_);
        }

        this->vacuumReader();

        if ( checkInput_.second == false )
        {
            this->checkInput(checkInput_.first);
        }
        else
        {
            propertiesInterface_->setTemperature(T_);
            propertiesInterface_->setPressure(p_);
            propertiesInterface_->setMoleFraction(x_,n_);
            propertiesInterface_->vacuumCalculate();
            
            {
                std::vector<double> vm = propertiesInterface_->vm();
                std::vector<double> l  = propertiesInterface_->l();

                Kn_    = l[0]/d_;
                if ( Kn_ > 1. ) //molecular
                {
                    diffK_ = vm[0]*d_/3.;
                }
                else //viscous
                {
                    propertiesInterface_->transportCalculate();
                    std::vector<std::vector<double> > diff = propertiesInterface_->diff();
                    diffK_ = diff[0][0];
                }
            }

            if ( vacuumDiffCombo_.get_active_row_number() == 1 )
            {
                diffK_ = diffK_*1e04; 
            }

            {
                std::stringstream diffK;
                diffK << std::scientific << std::setprecision(OP_) << diffK_;
                vacuumDiffResults_ = new Gtk::Label(diffK.str());
            }
            
            {
                std::stringstream Kn;
                Kn << std::scientific << std::setprecision(OP_) << Kn_;
                vacuumKnuResults_ = new Gtk::Label(Kn.str());
            }

            vacuumGrid_.attach(*vacuumDiffResults_,4,1,1,1);
            vacuumGrid_.attach(*vacuumKnuResults_,5,1,1,1);

            this->show_all_children();
        }
    }

    void Chini::discrimer()
    {
        Gtk::MessageDialog dialog(*this,"ASALI is open-source software.\n"
                                        "You can redistribute it and/or modify it the terms of\n"
                                        "the GNU General Public License as published by\n"
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
    
    void Chini::savedMessage()
    {
        Gtk::MessageDialog dialog(*this,"Your file has been saved.\nThank you for using ASALI.",true,Gtk::MESSAGE_OTHER);
        dialog.run();
    }

    void Chini::transportSave()
    {
        Gtk::FileChooserDialog dialog("",Gtk::FILE_CHOOSER_ACTION_SAVE);
        dialog.set_transient_for(*this);

        //Add response buttons
        dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
        dialog.add_button("_Save", Gtk::RESPONSE_OK);

        //Show the dialog and wait for a user response
        int result = dialog.run();

        //Handle the response
        switch(result)
        {
            case(Gtk::RESPONSE_OK):
            {
                std::string filename = dialog.get_filename();
                std::ofstream output;
                const char *path = filename.c_str();
                output.open(path,std::ios::out);

                output << "Temperature:     " << T_ << " K" << std::endl;
                output << "Pressure:        " << p_ << " Pa" << std::endl;
                output << std::endl;
                output.setf(std::ios::scientific);
                output.precision(6);
                output << "Species\t" << "x           \ty           \t\u03BB           \t\u03BC           \t\u0393           " << std::endl;
                for (unsigned int i=0;i<n_.size();i++)
                {
                    for (unsigned int j=i;j<n_.size();j++)
                    {
                        if ( i == n_.size() - 1 )
                        {
                            output << n_[i] << " " << "  " << "\t" << "             " << "\t" << "             " << "\t" << cond_[i] << "\t" << mu_[i] << std::endl;
                        }
                        else
                        {
                            if ( j == i)
                            {
                                output << n_[i] << " " << n_[j] << "\t" << x_[i] << "\t" << y_[i] << "\t" << cond_[i] << "\t" << mu_[i] << "\t" << diff_[i][j] << std::endl;
                            }
                            else
                            {
                                output << n_[i] << " " << n_[j] << "\t" << "           " << "\t" << "           " << "\t" << "           " << "\t" << "           " << "\t" << diff_[i][j] << std::endl;
                            }
                        }
                    }
                }
                output << std::endl;
                output << std::endl;
                output << "x: mole fraction" << std::endl;
                output << "y: mass fraction" << std::endl;
                output << "\u03BB: thermal conductivity [W/m/K]" << std::endl;
                output << "\u03BC: viscosity            [Pas]" << std::endl;
                output << "\u0393: diffusivity          [m\u00b2/s]" << std::endl;
                output.close();
                dialog.hide();
                this->savedMessage();
                break;
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

    void Chini::allSave()
    {
        Gtk::FileChooserDialog dialog("",Gtk::FILE_CHOOSER_ACTION_SAVE);
        dialog.set_transient_for(*this);

        //Add response buttons
        dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
        dialog.add_button("_Save", Gtk::RESPONSE_OK);

        //Show the dialog and wait for a user response
        int result = dialog.run();

        //Handle the response
        switch(result)
        {
            case(Gtk::RESPONSE_OK):
            {
                std::string filename = dialog.get_filename();
                std::ofstream output;
                const char *path = filename.c_str();
                output.open(path,std::ios::out);
                
                output << "Temperature:     " << T_ << " K" << std::endl;
                output << "Pressure:        " << p_ << " Pa" << std::endl;
                output << std::endl;
                output.setf(std::ios::scientific);
                output.precision(6);

                output << "Species\t" << "x            \ty            \tCp           \tH            \tS            \t\u03BB           \t\u03BC           \t\u0393           " << std::endl;
                for (unsigned int i=0;i<n_.size();i++)
                {
                    for (unsigned int j=i;j<n_.size();j++)
                    {
                        if ( i == n_.size() - 1 )
                        {
                            output << n_[i] << " " << "  " << "\t" << "             " << "\t" << "             " << "\t" << cp_[i]/1e03 << "\t" << h_[i]/1e03 << "\t" << s_[i]/1e03 << "\t" << cond_[i] << "\t" << mu_[i] << "\t" << diff_[i][j] <<  std::endl;
                        }
                        else
                        {
                            if ( j == i)
                            {
                                output << n_[i] << " " << n_[j] << "\t" << x_[i] << "\t" << y_[i] << "\t" << cp_[i]/1e03 << "\t" << h_[i]/1e03 << "\t" << s_[i]/1e03 << "\t" << cond_[i] << "\t" << mu_[i] << "\t" << diff_[i][j] <<  std::endl;
                            }
                            else
                            {
                                output << n_[i] << " " << n_[j] << "\t" << "           " << "\t" << "           " << "\t" << "           " << "\t" << "           " << "\t" << "           " << "\t" << "           " << "\t" << "           " << "\t" << diff_[i][j] << std::endl;
                            }
                        }
                    }
                }
                output << std::endl;
                output << "x : mole fraction" << std::endl;
                output << "y : mass fraction" << std::endl;
                output << "Cp: specific heat        [J/mol/K]" << std::endl;
                output << "H : enthalpy             [J/mol]" << std::endl;
                output << "S : entropy              [J/mol/K]" << std::endl;
                output << "\u03BB : thermal conductivity [W/m/K]" << std::endl;
                output << "\u03BC : viscosity            [Pas]" << std::endl;
                output << "\u0393 : diffusivity          [m\u00b2/s]" << std::endl;
                output.close();
                dialog.hide();
                this->savedMessage();
                break;
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

    void Chini::vacuumSave()
    {
        Gtk::FileChooserDialog dialog("",Gtk::FILE_CHOOSER_ACTION_SAVE);
        dialog.set_transient_for(*this);

        //Add response buttons
        dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
        dialog.add_button("_Save", Gtk::RESPONSE_OK);

        //Show the dialog and wait for a user response
        int result = dialog.run();

        //Handle the response
        switch(result)
        {
            case(Gtk::RESPONSE_OK):
            {
                std::string filename = dialog.get_filename();
                std::ofstream output;
                const char *path = filename.c_str();
                output.open(path,std::ios::out);
                
                output << "Temperature:     " << T_ << " K" << std::endl;
                output << "Pressure:        " << p_ << " Pa" << std::endl;
                output << "Species:         " << n_[0] << std::endl;
                output << "Length:          " << d_ << " m" << std::endl;
                output << std::endl;
                output.setf(std::ios::scientific);
                output.precision(3);
                output << "Diffusivity:     " << diffK_ << " m\u00b2/s" << std::endl;
                output << "Knudsen number:  " << Kn_ << std::endl;
                output.close();
                dialog.hide();
                this->savedMessage();
                break;
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

    void Chini::thermoSave()
    {
        Gtk::FileChooserDialog dialog("",Gtk::FILE_CHOOSER_ACTION_SAVE);
        dialog.set_transient_for(*this);

        //Add response buttons
        dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
        dialog.add_button("_Save", Gtk::RESPONSE_OK);

        //Show the dialog and wait for a user response
        int result = dialog.run();

        //Handle the response
        switch(result)
        {
            case(Gtk::RESPONSE_OK):
            {
                std::string filename = dialog.get_filename();
                std::ofstream output;
                const char *path = filename.c_str();
                output.open(path,std::ios::out);
                
                output << "Temperature:     " << T_ << " K" << std::endl;
                output << "Pressure:        " << p_ << " Pa" << std::endl;
                output << std::endl;
                output.setf(std::ios::scientific);
                output.precision(6);

                output << "Species\t" << "x            \ty            \tCp           \tH            \tS            \t" << std::endl;
                for (unsigned int i=0;i<n_.size();i++)
                {
                    if ( i == n_.size() - 1)
                    {
                        output << n_[i] << "\t" << "           " << "\t" << "           " << "\t" << cp_[i]/1e03 << "\t" << h_[i]/1e03 << "\t" << s_[i]/1e03 << std::endl;
                    }
                    else
                    {
                        output << n_[i] << "\t" << x_[i] << "\t" << y_[i] << "\t" << cp_[i]/1e03 << "\t" << h_[i]/1e03 << "\t" << s_[i]/1e03 << std::endl;
                    }
                }
                
                output << std::endl;
                output << "x : mole fraction" << std::endl;
                output << "y : mass fraction" << std::endl;
                output << "Cp: specific heat  [J/mol/K]" << std::endl;
                output << "H : enthalpy       [J/mol]" << std::endl;
                output << "S : entropy        [J/mol/K]" << std::endl;
                output.close();
                dialog.hide();
                this->savedMessage();
                break;
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

    void Chini::reactorSave()
    {
        Gtk::FileChooserDialog dialog("",Gtk::FILE_CHOOSER_ACTION_SAVE);
        dialog.set_transient_for(*this);

        //Add response buttons
        dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
        dialog.add_button("_Save", Gtk::RESPONSE_OK);

        //Show the dialog and wait for a user response
        int result = dialog.run();

        //Handle the response
        switch(result)
        {
            case(Gtk::RESPONSE_OK):
            {
                std::string filename = dialog.get_filename();
                std::ofstream output;
                const char *path = filename.c_str();
                output.open(path,std::ios::out);
                
                output << "Temperature:     " << T_ << " K" << std::endl;
                output << "Pressure:        " << p_ << " Pa" << std::endl;
                output << "Residence time:  " << tau_ << " s" << std::endl;
                output << "Reactor type:    " << reactorsTypeCombo_.get_active_text() << std::endl;

                std::vector<double>               z = reactors_->getTime();
                std::vector<std::vector<double> > y = reactors_->getResults();
                std::vector<std::vector<double> > x = reactors_->getResults();

                for (unsigned int i=0;i<z.size();i++)
                {
                    std::vector<double> mole(n_.size());
                    for (unsigned int j=0;j<n_.size();j++)
                    {
                        mole[j] = x[i][j]*8314.*T_/(p_*MW_[j]); //From rho to mole fraction
                        x[i][j] = mole[j];
                    }

                    propertiesInterface_->setTemperature(T_);
                    propertiesInterface_->setPressure(p_);
                    propertiesInterface_->setMoleFraction(mole,n_);
                    y[i] = propertiesInterface_->massFractions();
                }

                output << std::endl;
                output.setf(std::ios::scientific);
                output.precision(6);

                output << "Mole fraction" << std::endl;
                output << "Time [s]" << "\t";
                for (unsigned int i=0;i<n_.size();i++)
                {
                    output << n_[i] << "\t";
                }
                output << std::endl;
                
                for (unsigned int j=0;j<z.size();j++)
                {
                    output << z[j] << "\t";
                    for (unsigned int i=0;i<(n_.size());i++)
                    {
                        output << x[j][i] << "\t";
                    }
                    output << std::endl;
                }
                output << std::endl;

                output << "Mass fraction" << std::endl;
                output << "Time [s]" << "\t";
                for (unsigned int i=0;i<n_.size();i++)
                {
                    output << n_[i] << "\t";
                }
                output << std::endl;
                
                for (unsigned int j=0;j<z.size();j++)
                {
                    output << z[j] << "\t";
                    for (unsigned int i=0;i<(n_.size());i++)
                    {
                        output << y[j][i] << "\t";
                    }
                    output << std::endl;
                }
                output.close();
                dialog.hide();
                this->savedMessage();
                break;
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

    void Chini::vacuumReader()
    {
        T_ = Glib::Ascii::strtod(vacuumTempEntry_.get_text());
        p_ = Glib::Ascii::strtod(vacuumPressEntry_.get_text());
        d_ = Glib::Ascii::strtod(vacuumLengthEntry_.get_text());

        ConvertsToKelvin(T_,vacuumTempCombo_.get_active_text());
        ConvertsToPascal(p_,vacuumPressCombo_.get_active_text());
        ConvertsToMeter(d_,vacuumLengthCombo_.get_active_text());
        
        n_.resize(1);
        x_.resize(1);
        
        n_[0] = vacuumSpecieEntry_.get_text().c_str();
        x_[0] = 1.;

        std::vector<int> check = propertiesInterface_->checkNames(n_);

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

    void Chini::inputReader()
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
        
        std::vector<int> check = propertiesInterface_->checkNames(n_);

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
    
    void Chini::checkInput(unsigned int i)
    {
        if ( i == 4444 )
        {
            Gtk::MessageDialog dialog(*this,"Plase, the sum of mass/mole fractions should be 1.",true,Gtk::MESSAGE_WARNING);
            dialog.run();
        }
        else
        {
            Gtk::MessageDialog dialog(*this,n_[i]+" is missing in ASALI database.\nYou can add it by modifying\ndatabase/data.cti",true,Gtk::MESSAGE_WARNING);
            dialog.run();
        }
    }

    void Chini::equations()
    {
        Gtk::MessageDialog dialog(*this,"",true,Gtk::MESSAGE_OTHER);
        dialog.set_image(equationsImage_);
        dialog.show_all();
        dialog.run();
    }
    
    void Chini::runReactors()
    {
        std::vector<bool> done = this->setReactors();
        if (done[0] == true &&
            done[1] == true)
        {
            //Solving
            reactors_ = new ASALI::IdealReactors(n_.size(),nr_.size());

            reactors_->set_T(T_);
            reactors_->set_p(p_);

            propertiesInterface_->setTemperature(T_);
            propertiesInterface_->setPressure(p_);

            if ( fractionCombo_.get_active_row_number() == 0 )
            {
                propertiesInterface_->setMoleFraction(x_,n_);
            }
            else if ( fractionCombo_.get_active_row_number() == 1 )
            {
                propertiesInterface_->setMassFraction(x_,n_);
            }

            MW_.clear();
            MW_.resize(n_.size());
            x_.clear();
            x_.resize(n_.size());
            
            x_  = propertiesInterface_->moleFractions();
            MW_ = propertiesInterface_->MW();

            std::vector<double> rho(n_.size() + 1.);
            for (unsigned int i=0;i<n_.size();i++)
            {
                rho[i] = p_*x_[i]*MW_[i]/(8314.*T_); //Kg/m3
            }
            
            rho[n_.size()] = T_;

            reactors_->set_k(kr_);
            reactors_->set_Eatt(Eattr_);
            reactors_->set_n(nr_);
            reactors_->set_a(ar_);
            reactors_->set_b(br_);
            reactors_->set_index(index1_,index2_);
            reactors_->set_MW(MW_);
            reactors_->set_stoich(stoich_);

            reactors_->set_converter(specieConverter_);


            reactors_->set_reactor(reactorsTypeCombo_.get_active_text());

            {
                tau_ = Glib::Ascii::strtod(reactorsTimeEntry_.get_text().c_str());
                ConvertsToSecond(tau_,tempCombo_.get_active_text());
                reactors_->set_residence_time(tau_);
                reactors_->set_inlet(rho);

                if ( reactorsTypeCombo_.get_active_text() == "CSTR")
                {
                    tau_ = tau_*4.;
                }
            }

            reactors_->setInitialConditions(rho,0.);

            rho.clear();
            rho.resize(n_.size()+1);
            std::cout << "\n\n" << std::endl;
            reactors_->solve(rho,tau_);
            std::cout << "\n" << std::endl;

            this->reactorSave();
        }
        else if (done[1] == false)
        {
            Gtk::MessageDialog dialog(*this,"Plase fill all the parameter for\nthe reactions you are considering.",true,Gtk::MESSAGE_OTHER);
            dialog.run();
        }
    }

    std::vector<bool> Chini::setReactors()
    {
        //Get species names and initial composition
        std::vector<bool> done(2);
        done[0] = false;
        done[1] = false;
        
        this->inputReader();
        
        for (unsigned int i=0;i<NR_;i++)
        {
            for (unsigned int j=0;j<4;j++)
            {
                std::string name = reactionEntry_[i][j]->get_text().c_str();
                if ( !name.empty() )
                {
                         done[1] = true;
                    bool test    = false;
                    for (unsigned int k=0;k<n_.size();k++)
                    {
                        if ( name == n_[k] )
                        {
                            test = true;
                            break;
                        }
                    }

                    if ( test == false )
                    {
                        n_.push_back(name);
                        x_.push_back(0.0);
                    }
                    
                    if ( j == 0 )
                    {
                        index1_.push_back(specieIndex(name,n_));
                    }
                    else if ( j == 1 )
                    {
                        index2_.push_back(specieIndex(name,n_));
                    }
                }
            }
        }

        std::vector<int> check = propertiesInterface_->checkNames(n_);

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

        if ( checkInput_.second == false )
        {
            this->checkInput(checkInput_.first);
            done[0] = false;
        }
        else
        {
            done[0] = true;
        }


        //Get reaction parameter (k)
        kr_.clear();
        for (unsigned int i=0;i<NR_;i++)
        {
            std::string value = kEntry_[i]->get_text().c_str();
            if (!value.empty())
            {
                kr_.push_back(Glib::Ascii::strtod(value));
            }
        }
        
        //Get reaction parameter (n)
        nr_.clear();
        for (unsigned int i=0;i<NR_;i++)
        {
            std::string value = nEntry_[i]->get_text().c_str();
            if (!value.empty())
            {
                nr_.push_back(Glib::Ascii::strtod(value));
            }
        }
        
        //Get reaction parameter (Eatt)
        Eattr_.clear();
        for (unsigned int i=0;i<NR_;i++)
        {
            std::string value = EattEntry_[i]->get_text().c_str();
            if (!value.empty())
            {
                Eattr_.push_back(Glib::Ascii::strtod(value));
            }
        }
            
        //Get reaction parameter (a)
        ar_.clear();
        for (unsigned int i=0;i<NR_;i++)
        {
            std::string value = aEntry_[i]->get_text().c_str();
            if (!value.empty())
            {
                ar_.push_back(Glib::Ascii::strtod(value));
            }
        }

        //Get reaction parameter (b)
        br_.clear();
        for (unsigned int i=0;i<NR_;i++)
        {
            std::string value = bEntry_[i]->get_text().c_str();
            if (!value.empty())
            {
                br_.push_back(Glib::Ascii::strtod(value));
            }
        }

        //Check reaction input
        done[1] = this->reactionInputCheck(done[1]);

        if (done[1])
        {
            stoich_.clear();
            stoich_.resize(kr_.size());
            //Stoichiometric coefficients
            for (unsigned int i=0;i<kr_.size();i++)
            {
                std::vector<int> S(n_.size());
                
                for (unsigned int k=0;k<n_.size();k++)
                {
                    S[k] = 0;
                }

                for (unsigned int j=0;j<4;j++)
                {
                    std::string name = reactionEntry_[i][j]->get_text().c_str();
                    for (unsigned int k=0;k<n_.size();k++)
                    {
                        if (name == n_[k] && j < 2)
                        {
                            S[k] = stoichCombo_[i][j]->get_active_row_number()+1;
                            S[k] = -S[k];
                        }
                        else if (name == n_[k] && j >= 2)
                        {
                            S[k] = stoichCombo_[i][j]->get_active_row_number()  + 1;
                        }
                    }
                }
                stoich_[i] = S;
            }
                
            //Conversion of Eatt to J/Kmol
            {
                double converter = 1.;
                if (EattCombo_.get_active_row_number() == 0)
                {
                    converter = 1./1e-03;
                }
                else if (EattCombo_.get_active_row_number() == 1)
                {
                    converter = 1.;
                }
                else if (EattCombo_.get_active_row_number() == 2)
                {
                    converter = 4186./1e-03;
                }
                else if (EattCombo_.get_active_row_number() == 3)
                {
                    converter = 4186.;
                }

                for (unsigned int i=0;i<Eattr_.size();i++)
                {
                    Eattr_[i] = Eattr_[i]*converter;
                }
            }

            //Conversion of k
            {
                if (kCombo_.get_active_row_number() == 0)
                {
                    specieConverter_ = 1e03;
                }
                else if (kCombo_.get_active_row_number() == 1)
                {
                    specieConverter_ = 1e03/1e03;
                }
                else if (kCombo_.get_active_row_number() == 2)
                {
                    specieConverter_ = 1e03/1e06;
                }
                else if (kCombo_.get_active_row_number() == 3)
                {
                    specieConverter_ = 1.;
                }
                else if (kCombo_.get_active_row_number() == 4)
                {
                    specieConverter_ = 1./1e03;
                }
                else if (kCombo_.get_active_row_number() == 5)
                {
                    specieConverter_ = 1./1e06;
                }
            }
        }

        return done;
    }

    void Chini::saveKineticInput()
    {
        Gtk::FileChooserDialog dialog("",Gtk::FILE_CHOOSER_ACTION_SAVE);
        dialog.set_transient_for(*this);

        //Add response buttons
        dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
        dialog.add_button("_Save", Gtk::RESPONSE_OK);

        //Show the dialog and wait for a user response
        int result = dialog.run();

        //Handle the response
        switch(result)
        {
            case(Gtk::RESPONSE_OK):
            {
                std::string filename = dialog.get_filename();
                std::ofstream output;
                const char *path = filename.c_str();
                output.open(path,std::ios::out);
                
                output << "#Asali kinetic file" << std::endl;
                for (unsigned int i=0;i<NR_;i++)
                {
                    output << "#Reaction " << i + 1 << std::endl;
                    for (unsigned int j=0;j<4;j++)
                    {
                        std::string name = reactionEntry_[i][j]->get_text().c_str();
                        if ( !name.empty() )
                        {
                            output << stoichCombo_[i][j]->get_active_row_number() << std::endl;
                            output << reactionEntry_[i][j]->get_text() << std::endl;
                        }
                        else
                        {
                            output << 0. << std::endl;
                            output << "none" << std::endl;
                        }
                    }

                    //k
                    {
                        std::string value = kEntry_[i]->get_text().c_str();
                        if (!value.empty())
                        {
                            output << kEntry_[i]->get_text() << std::endl;
                        }
                        else
                        {
                            output << "none" << std::endl;
                        }
                    }

                    //n
                    {
                        std::string value = nEntry_[i]->get_text().c_str();
                        if (!value.empty())
                        {
                            output << nEntry_[i]->get_text() << std::endl;
                        }
                        else
                        {
                            output << "none" << std::endl;
                        }
                    }

                    //Eatt
                    {
                        std::string value = EattEntry_[i]->get_text().c_str();
                        if (!value.empty())
                        {
                            output << EattEntry_[i]->get_text() << std::endl;
                        }
                        else
                        {
                            output << "none" << std::endl;
                        }
                    }

                    //a
                    {
                        std::string value = aEntry_[i]->get_text().c_str();
                        if (!value.empty())
                        {
                            output << aEntry_[i]->get_text() << std::endl;
                        }
                        else
                        {
                            output << "none" << std::endl;
                        }
                    }

                    //b
                    {
                        std::string value = bEntry_[i]->get_text().c_str();
                        if (!value.empty())
                        {
                            output << bEntry_[i]->get_text() << std::endl;
                        }
                        else
                        {
                            output << "none" << std::endl;
                        }
                    }
                    
                    output << kCombo_.get_active_row_number() << std::endl;
                    output << EattCombo_.get_active_row_number() << std::endl;
                }

                output.close();
                dialog.hide();
                this->savedMessage();
                break;
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

    void Chini::loadKineticInput()
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

                std::vector<std::string> readed;
                
                while (!input.eof()) 
                {
                    std::string line;
                    getline(input,line);
                    if (line.find("#"))
                    {
                        readed.push_back(line);
                    }
                }

                unsigned int counter = 0;

                for (unsigned int i=0;i<NR_;i++)
                {
                    for (unsigned int j=0;j<4;j++)
                    {
                        stoichCombo_[i][j]->set_active(Glib::Ascii::strtod(readed[counter++]));

                        if ( readed[counter] != "none" )
                        {
                            reactionEntry_[i][j]->set_text(readed[counter]);
                        }
                        counter++;
                    }

                    //k
                    {
                        if ( readed[counter] != "none" )
                        {
                            kEntry_[i]->set_text(readed[counter]);
                        }
                        counter++;
                    }

                    //n
                    {
                        if ( readed[counter] != "none" )
                        {
                            nEntry_[i]->set_text(readed[counter]);
                        }
                        counter++;
                    }

                    //Eatt
                    {
                        if ( readed[counter] != "none" )
                        {
                            EattEntry_[i]->set_text(readed[counter]);
                        }
                        counter++;
                    }

                    //a
                    {
                        if ( readed[counter] != "none" )
                        {
                            aEntry_[i]->set_text(readed[counter]);
                        }
                        counter++;
                    }

                    //b
                    {
                        if ( readed[counter] != "none" )
                        {
                            bEntry_[i]->set_text(readed[counter]);
                        }
                        counter++;
                    }
                    
                    kCombo_.set_active(Glib::Ascii::strtod(readed[counter++]));
                    EattCombo_.set_active(Glib::Ascii::strtod(readed[counter++]));
                }

                dialog.hide();
                this->reactorsMenu2();
                break;
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

    void Chini::exit()
    {
        this->hide();
    }
    
    unsigned int Chini::specieIndex(const std::string n, const std::vector<std::string> v)
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

    bool Chini::reactionInputCheck(bool test)
    {
        bool check = false;
        
        if (test)
        {
            if ( kr_.size() == Eattr_.size() )
            {
                if ( Eattr_.size() == nr_.size() )
                {
                    if ( nr_.size() == ar_.size() )
                    {
                        if ( ar_.size() == br_.size() )
                        {
                            if ( br_.size() != 0 )
                            {
                                check = true;
                            }
                        }
                    }
                }
            }
        }
        return check;
    }

    void Chini::availableSpecies()
    {
        speciesNames_->show();
    }

}
