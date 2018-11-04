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

#include "het1dReactor.h"

namespace ASALI
{
    het1dReactor::het1dReactor(Cantera::ThermoPhase *thermo,
                               Cantera::Transport   *transport,
                               Cantera::Kinetics    *kinetic,
                               Cantera::Interface   *surface,
                               std::string           kineticType)
    : catalyticReactors(thermo, transport, kinetic, surface, kineticType),
      mainBox_(Gtk::ORIENTATION_VERTICAL),
      recapMainBox_(Gtk::ORIENTATION_VERTICAL),
      exitButton3_("Exit"),
      exitButton4_("Exit"),
      nextButton3_("Next"),
      backButton3_("Back"),
      catalystPropertiesButton_("Catalyst properties"),
      recapButtonBox_(Gtk::ORIENTATION_VERTICAL),
      lengthLabel_("Length"),
      velocityLabel_("Velocity"),
      loadLabel_("Catalyst load"),
      timeLabel_("Integration time"),
      saveLabel_("Save solution every"),
      energyLabel_("Energy"),
      pointsLabel_("Number of points"),
      inertLabel_("Inert specie"),
      reactorTypeLabel_("Reactor type"),
      packedBedTubeLabel_("Tube diameter"),
      packedBedParticleLabel_("Particle diameter"),
      packedBedVoidFractionLabel_("Void fraction"),
      tubularTubeLabel_("Tube diameter"),
      tubularDuctLabel_("Tube section"),
      tubularWallThicknessLabel_("Washcoat thickness"),
      honeyCombCPSILabel_("CPSI"),
      honeyCombWallThicknessLabel_("Wall thickness"),
      honeyCombDuctLabel_("Duct section"),
      logo1_("images/Het1DLogo.tiff"),
      logo2_("images/Het1DLogo.tiff"),
      reactorType_("none"),
      tubularBool_(false),
      honeyCombBool_(false),
      packedBedBool_(false),
      plotButtonBool_(false)
    {

        eq_ = new ASALI::het1dEquations();

        //Input
        {
            this->set_border_width(15);
            this->set_title("ASALI: 1D HET reactor");
            this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
            this->set_icon_from_file("images/Icon.tiff");

            //Add background grid
            this->add(mainBox_);

            mainBox_.set_halign(Gtk::ALIGN_START);
            mainBox_.set_spacing(10);
            mainBox_.pack_start(logo1_, Gtk::PACK_SHRINK);
            mainBox_.pack_start(secondBox_, Gtk::PACK_SHRINK);

            secondBox_.set_halign(Gtk::ALIGN_START);
            secondBox_.set_spacing(10);
            secondBox_.pack_start(propertiesGrid_, Gtk::PACK_SHRINK);
            {
                propertiesGrid_.set_column_spacing(10);
                propertiesGrid_.set_row_spacing(10);
                propertiesGrid_.set_column_homogeneous(true);

                //Length
                propertiesGrid_.attach(lengthLabel_,0,0,1,1);
                propertiesGrid_.attach(lengthEntry_,1,0,1,1);
                lengthEntry_.set_text("1");
                propertiesGrid_.attach(lengthCombo_,2,0,1,1);
                lengthCombo_.append("m");
                lengthCombo_.append("dm");
                lengthCombo_.append("cm");
                lengthCombo_.append("mm");
                lengthCombo_.set_active(0);

                //Velocity
                propertiesGrid_.attach(velocityLabel_,0,1,1,1);
                propertiesGrid_.attach(velocityEntry_,1,1,1,1);
                velocityEntry_.set_text("1");
                propertiesGrid_.attach(velocityCombo_,2,1,1,1);
                velocityCombo_.append("m/s");
                velocityCombo_.append("cm/s");
                velocityCombo_.append("m/min");
                velocityCombo_.append("cm/min");
                velocityCombo_.append("m/h");
                velocityCombo_.append("cm/h");
                velocityCombo_.set_active(0);

                //Time
                propertiesGrid_.attach(timeLabel_,0,2,1,1);
                propertiesGrid_.attach(timeEntry_,1,2,1,1);
                timeEntry_.set_text("1");
                propertiesGrid_.attach(timeCombo_,2,2,1,1);
                timeCombo_.append("s");
                timeCombo_.append("min");
                timeCombo_.append("h");
                timeCombo_.append("d");
                timeCombo_.set_active(0);

                //Save options
                propertiesGrid_.attach(saveLabel_,0,3,1,1);
                propertiesGrid_.attach(saveEntry_,1,3,1,1);
                saveEntry_.set_text("0.1");
                propertiesGrid_.attach(saveCombo_,2,3,1,1);
                saveCombo_.append("s");
                saveCombo_.append("min");
                saveCombo_.append("h");
                saveCombo_.append("d");
                saveCombo_.set_active(0);

                //Number of points
                propertiesGrid_.attach(pointsLabel_,3,0,1,1);
                propertiesGrid_.attach(pointsEntry_,4,0,1,1);
                pointsEntry_.set_text("10");

                //Inert species
                propertiesGrid_.attach(inertLabel_,3,1,1,1);
                propertiesGrid_.attach(inertEntry_,4,1,1,1);
                inertEntry_.set_text("AR");

                //Energy
                propertiesGrid_.attach(energyLabel_,3,2,1,1);
                propertiesGrid_.attach(energyCombo_,4,2,1,1);
                energyCombo_.append("on");
                energyCombo_.append("off");
                energyCombo_.set_active(1);

                //Type
                propertiesGrid_.attach(reactorTypeLabel_,3,3,1,1);
                propertiesGrid_.attach(reactorTypeCombo_,4,3,1,1);
                reactorTypeCombo_.append("tubular");
                reactorTypeCombo_.append("packed bed");
                reactorTypeCombo_.append("honeycomb");
                reactorTypeCombo_.signal_changed().connect(sigc::mem_fun(*this,&het1dReactor::options));
                reactorTypeCombo_.set_active(0);

                //Tubular
                {
                    tubularTubeEntry_.set_text("1");

                    tubularTubeCombo_.append("m");
                    tubularTubeCombo_.append("dm");
                    tubularTubeCombo_.append("cm");
                    tubularTubeCombo_.append("mm");
                    tubularTubeCombo_.set_active(0);

                    tubularWallThicknessEntry_.set_text("1");

                    tubularWallThicknessCombo_.append("cm");
                    tubularWallThicknessCombo_.append("mm");
                    tubularWallThicknessCombo_.append("\u03BCm");
                    tubularWallThicknessCombo_.set_active(2);
                    

                    tubularDuctCombo_.append("square");
                    tubularDuctCombo_.append("circle");
                    tubularDuctCombo_.append("triangle");
                    tubularDuctCombo_.set_active(1);
                }

                //Honeycomb
                {
                    honeyCombCPSIEntry_.set_text("400");

                    honeyCombWallThicknessCombo_.append("cm");
                    honeyCombWallThicknessCombo_.append("mm");
                    honeyCombWallThicknessCombo_.append("\u03BCm");
                    honeyCombWallThicknessCombo_.set_active(1);

                    honeyCombWallThicknessEntry_.set_text("1");

                    honeyCombDuctCombo_.append("square");
                    honeyCombDuctCombo_.append("circle");
                    honeyCombDuctCombo_.append("triangle");
                    honeyCombDuctCombo_.set_active(1);
                }
                
                //Packed bed
                {
                    packedBedTubeEntry_.set_text("1");

                    packedBedTubeCombo_.append("m");
                    packedBedTubeCombo_.append("dm");
                    packedBedTubeCombo_.append("cm");
                    packedBedTubeCombo_.append("mm");
                    packedBedTubeCombo_.set_active(0);

                    packedBedParticleEntry_.set_text("1");

                    packedBedParticleCombo_.append("m");
                    packedBedParticleCombo_.append("dm");
                    packedBedParticleCombo_.append("cm");
                    packedBedParticleCombo_.append("mm");
                    packedBedParticleCombo_.set_active(0);
                    
                    packedBedVoidFractionEntry_.set_text("0.42");
                }
                
                //Beer
                {
                    beerLabel_.set_text(this->getBeerShort());
                    beerLabel_.set_use_markup(true);
                    beerLabel_.set_justify(Gtk::JUSTIFY_CENTER);
                    propertiesGrid_.attach(beerLabel_,3,4,2,3);
                }
                
                //Buttons
                propertiesGrid_.attach(exitButton3_,0,11,2,1);
                exitButton3_.signal_clicked().connect(sigc::mem_fun(*this,&het1dReactor::exit));
                propertiesGrid_.attach(nextButton3_,3,11,2,1);
                nextButton3_.signal_clicked().connect(sigc::mem_fun(*this,&het1dReactor::composition));

                this->show_all_children();
            }
        }

        //Recap
        {
            recapMainBox_.set_halign(Gtk::ALIGN_CENTER);
            recapMainBox_.set_spacing(10);
            recapMainBox_.pack_start(logoBox_, Gtk::PACK_SHRINK);
            {
                logoBox_.set_halign(Gtk::ALIGN_CENTER);
                logoBox_.set_spacing(10);
                logoBox_.pack_start(logo2_, Gtk::PACK_SHRINK);
                logoBox_.pack_start(recapButtonBox_, Gtk::PACK_SHRINK);
                {
                    recapButtonBox_.set_layout(Gtk::BUTTONBOX_CENTER);
                    recapButtonBox_.set_spacing(10);
                    recapButtonBox_.set_homogeneous(true);
                    recapButtonBox_.pack_start(runButton_, Gtk::PACK_SHRINK);
                    run_ = runButton_.signal_clicked().connect(sigc::mem_fun(*this,&het1dReactor::catalystPropertiesShow));
                    recapButtonBox_.pack_start(saveButton_, Gtk::PACK_SHRINK);
                    saveButton_.signal_clicked().connect(sigc::mem_fun(*this,&het1dReactor::save));
                    recapButtonBox_.pack_start(catalystPropertiesButton_, Gtk::PACK_SHRINK);
                    catalystPropertiesButton_.signal_clicked().connect(sigc::mem_fun(*this,&het1dReactor::catalystPropertiesShow));
                    asaliPlotButton_.signal_clicked().connect(sigc::mem_fun(*this,&het1dReactor::plot));
                    
                    asaliKineticButton_.signal_clicked().connect(sigc::mem_fun(*this,&het1dReactor::kineticShow));
                    asaliPropertiesButton_.signal_clicked().connect(sigc::mem_fun(*this,&het1dReactor::propertiesShow));

                    {
                        if ( kineticType_ == "none" )
                        {
                            recapButtonBox_.pack_start(asaliKineticButton_, Gtk::PACK_SHRINK);
                            recapButtonBox_.pack_start(asaliPropertiesButton_, Gtk::PACK_SHRINK);
                        }
                        else if ( kineticType_ == "default" )
                        {
                            recapButtonBox_.pack_start(asaliKineticButton_, Gtk::PACK_SHRINK);
                        }
                        else if ( kineticType_ == "nokinetic" )
                        {
                            recapButtonBox_.pack_start(asaliKineticButton_, Gtk::PACK_SHRINK);
                        }
                        else if ( kineticType_ == "load" )
                        {
                        }
                    }

                }
            }

            recapMainBox_.pack_start(recapBox_, Gtk::PACK_SHRINK);
            {
                recapBox_.set_halign(Gtk::ALIGN_START);
                recapBox_.set_spacing(10);
                recapBox_.pack_start(recapGrid_, Gtk::PACK_SHRINK);
                {
                    recapGrid_.set_column_spacing(10);
                    recapGrid_.set_row_spacing(10);
                    recapGrid_.set_column_homogeneous(true);
                    
                    recapGrid_.set_column_spacing(10);
                    recapGrid_.set_row_spacing(10);
                    recapGrid_.set_column_homogeneous(true);

                    //Reactor type
                    recapReactorTypeLabel_.set_text("Reactor type");
                    recapGrid_.attach(recapReactorTypeLabel_,0,0,1,1);
                    recapGrid_.attach(recapReactorTypeValueLabel_,1,0,1,1);

                    //Energy type
                    recapEnergyLabel_.set_text("Energy balance is");
                    recapGrid_.attach(recapEnergyLabel_,0,1,1,1);
                    recapGrid_.attach(recapEnergyValueLabel_,1,1,1,1);

                    //Kinetic type
                    recapKineticLabel_.set_text("Kinetic model from");
                    recapGrid_.attach(recapKineticLabel_,0,2,1,1);
                    recapGrid_.attach(recapKineticValueLabel_,1,2,1,1);

                     //Time
                    recapTimeLabel_.set_text("Integration time");
                    recapTimeUDLabel_.set_text("s");
                    recapGrid_.attach(recapTimeLabel_,0,3,1,1);
                    recapGrid_.attach(recapTimeUDLabel_,2,3,1,1);
                    recapGrid_.attach(recapTimeValueLabel_,1,3,1,1);
            
                    //Save
                    recapSaveLabel_.set_text("Save solution every");
                    recapSaveUDLabel_.set_text("s");
                    recapGrid_.attach(recapSaveLabel_,0,4,1,1);
                    recapGrid_.attach(recapSaveUDLabel_,2,4,1,1);
                    recapGrid_.attach(recapSaveValueLabel_,1,4,1,1);

                    //Points
                    recapPointsLabel_.set_text("Solving with");
                    recapPointsUDLabel_.set_text("points");
                    recapGrid_.attach(recapPointsLabel_,0,5,1,1);
                    recapGrid_.attach(recapPointsUDLabel_,2,5,1,1);
                    recapGrid_.attach(recapPointsValueLabel_,1,5,1,1);

                    //Inert
                    recapInertLabel_.set_text("Inert species is");
                    recapGrid_.attach(recapInertLabel_,0,6,1,1);
                    recapGrid_.attach(recapInertValueLabel_,1,6,1,1);

                    //Velocity
                    recapVelocityLabel_.set_text("Velocity");
                    recapGrid_.attach(recapVelocityLabel_,3,0,1,1);
                    recapVelocityUDLabel_.set_text("m/s");
                    recapGrid_.attach(recapVelocityUDLabel_,5,0,1,1);
                    recapGrid_.attach(recapVelocityValueLabel_,4,0,1,1);

                    //Temperature
                    recapTemperatureLabel_.set_text("Temperature");
                    recapGrid_.attach(recapTemperatureLabel_,3,1,1,1);
                    recapTemperatureUDLabel_.set_text("K");
                    recapGrid_.attach(recapTemperatureUDLabel_,5,1,1,1);
                    recapGrid_.attach(recapTemperatureValueLabel_,4,1,1,1);

                    //Pressure
                    recapPressureLabel_.set_text("Pressure");
                    recapGrid_.attach(recapPressureLabel_,3,2,1,1);
                    recapPressureUDLabel_.set_text("Pa");
                    recapGrid_.attach(recapPressureUDLabel_,5,2,1,1);
                    recapGrid_.attach(recapPressureValueLabel_,4,2,1,1);

                    //Mole/Mass fraction
                    recapGrid_.attach(recapFractionLabel_,3,3,1,1);
                    recapGrid_.attach(recapFractionNameLabel_,5,3,1,1);
                    recapGrid_.attach(recapFractionValueLabel_,4,3,1,1);

                    //Length
                    recapLengthLabel_.set_text("Length");
                    recapGrid_.attach(recapLengthLabel_,3,4,1,1);
                    recapLengthUDLabel_.set_text("m");
                    recapGrid_.attach(recapLengthUDLabel_,5,4,1,1);
                    recapGrid_.attach(recapLengthValueLabel_,4,4,1,1);
                    
                    //Tubular
                    {
                        recapTubularTubeLabel_.set_text("Tube diameter");
                        recapTubularTubeUDLabel_.set_text("m");
                        recapTubularWallThicknessLabel_.set_text("Washcoat thickness");
                        recapTubularWallThicknessUDLabel_.set_text("m");
                        recapTubularDuctLabel_.set_text("Tube section");
                    }
                    
                    //Honeycomb
                    {
                        recapHoneyCombCPSILabel_.set_text("CPSI");
                        recapHoneyCombWallThicknessLabel_.set_text("Wall thickness");
                        recapHoneyCombWallThicknessUDLabel_.set_text("m");
                        recapHoneyCombDuctLabel_.set_text("Channel section");
                    }
                    
                    //Packedbed
                    {
                        recapPackedBedTubeLabel_.set_text("Tube diameter");
                        recapPackedBedTubeUDLabel_.set_text("m");
                        recapPackedBedVoidFractionLabel_.set_text("Void fraction");
                        recapPackedBedParticleLabel_.set_text("Particle diameter");
                        recapPackedBedParticleUDLabel_.set_text("m");
                    }
                    
                    //Buttons
                    recapGrid_.attach(backButton3_,0,13,3,1);
                    backButton3_.signal_clicked().connect(sigc::mem_fun(*this,&het1dReactor::input));
                    recapGrid_.attach(exitButton4_,3,13,3,1);
                    exitButton4_.signal_clicked().connect(sigc::mem_fun(*this,&het1dReactor::exit));
                }
            }
        }
    }

    het1dReactor::~het1dReactor()
    {
    }

    void het1dReactor::options()
    {
        if ( reactorType_ == "honeycomb" )
        {
            propertiesGrid_.remove(honeyCombCPSILabel_);
            propertiesGrid_.remove(honeyCombCPSIEntry_);
            propertiesGrid_.remove(honeyCombWallThicknessLabel_);
            propertiesGrid_.remove(honeyCombWallThicknessEntry_);
            propertiesGrid_.remove(honeyCombWallThicknessCombo_);
            propertiesGrid_.remove(honeyCombDuctLabel_);
            propertiesGrid_.remove(honeyCombDuctCombo_);
        }
        else if ( reactorType_ == "tubular" )
        {
            propertiesGrid_.remove(tubularTubeLabel_);
            propertiesGrid_.remove(tubularTubeEntry_);
            propertiesGrid_.remove(tubularTubeCombo_);

            propertiesGrid_.remove(tubularDuctLabel_);
            propertiesGrid_.remove(tubularDuctCombo_);
            
            propertiesGrid_.remove(tubularWallThicknessLabel_);
            propertiesGrid_.remove(tubularWallThicknessEntry_);
            propertiesGrid_.remove(tubularWallThicknessCombo_);

        }
        else if ( reactorType_ == "packed bed" )
        {
            propertiesGrid_.remove(packedBedTubeLabel_);
            propertiesGrid_.remove(packedBedTubeEntry_);
            propertiesGrid_.remove(packedBedTubeCombo_);
            propertiesGrid_.remove(packedBedParticleLabel_);
            propertiesGrid_.remove(packedBedParticleEntry_);
            propertiesGrid_.remove(packedBedParticleCombo_);
            propertiesGrid_.remove(packedBedVoidFractionLabel_);
            propertiesGrid_.remove(packedBedVoidFractionEntry_);
        }

        beerLabel_.set_text(this->getBeerShort());
        beerLabel_.set_use_markup(true);
        beerLabel_.set_justify(Gtk::JUSTIFY_CENTER);

        if ( reactorTypeCombo_.get_active_row_number() == 0 )
        {
            propertiesGrid_.attach(tubularTubeLabel_,0,4,1,1);
            propertiesGrid_.attach(tubularTubeEntry_,1,4,1,1);
            propertiesGrid_.attach(tubularTubeCombo_,2,4,1,1);

            propertiesGrid_.attach(tubularWallThicknessLabel_,0,5,1,1);
            propertiesGrid_.attach(tubularWallThicknessEntry_,1,5,1,1);
            propertiesGrid_.attach(tubularWallThicknessCombo_,2,5,1,1);


            propertiesGrid_.attach(tubularDuctLabel_,0,6,1,1);
            propertiesGrid_.attach(tubularDuctCombo_,1,6,1,1);

            reactorType_ = "tubular";
        }
        else if ( reactorTypeCombo_.get_active_row_number() == 1 )
        {
            propertiesGrid_.attach(packedBedTubeLabel_,0,4,1,1);
            propertiesGrid_.attach(packedBedTubeEntry_,1,4,1,1);
            propertiesGrid_.attach(packedBedTubeCombo_,2,4,1,1);

            propertiesGrid_.attach(packedBedParticleLabel_,0,5,1,1);
            propertiesGrid_.attach(packedBedParticleEntry_,1,5,1,1);
            propertiesGrid_.attach(packedBedParticleCombo_,2,5,1,1);

            propertiesGrid_.attach(packedBedVoidFractionLabel_,0,6,1,1);
            propertiesGrid_.attach(packedBedVoidFractionEntry_,1,6,1,1);

            reactorType_ = "packed bed";
        }
        else if ( reactorTypeCombo_.get_active_row_number() == 2 )
        {

            propertiesGrid_.attach(honeyCombCPSILabel_,0,4,1,1);
            propertiesGrid_.attach(honeyCombCPSIEntry_,1,4,1,1);

            propertiesGrid_.attach(honeyCombWallThicknessLabel_,0,5,1,1);
            propertiesGrid_.attach(honeyCombWallThicknessEntry_,1,5,1,1);
            propertiesGrid_.attach(honeyCombWallThicknessCombo_,2,5,1,1);

            propertiesGrid_.attach(honeyCombDuctLabel_,0,6,1,1);
            propertiesGrid_.attach(honeyCombDuctCombo_,1,6,1,1);

            reactorType_ = "honeycomb";
        }
        
        this->resize(mainBox_.get_width(),mainBox_.get_height());
        this->show_all_children();
    }

    void het1dReactor::clean()
    {
        recapGrid_.remove(recapFractionLabel_);
        recapGrid_.remove(recapFractionNameLabel_);
        recapGrid_.remove(recapFractionValueLabel_);
        recapGrid_.remove(recapLengthLabel_);
        recapGrid_.remove(recapLengthUDLabel_);
        recapGrid_.remove(recapLengthValueLabel_);

        if ( plotButtonBool_ )
        {
            recapButtonBox_.remove(asaliPlotButton_);
            plotButtonBool_ = false;
        }

        if (tubularBool_)
        {
            recapGrid_.remove(recapTubularTubeLabel_);
            recapGrid_.remove(recapTubularTubeUDLabel_);
            recapGrid_.remove(recapTubularTubeValueLabel_);
            recapGrid_.remove(recapTubularDuctLabel_);
            recapGrid_.remove(recapTubularDuctValueLabel_);
            recapGrid_.remove(recapTubularWallThicknessLabel_);
            recapGrid_.remove(recapTubularWallThicknessUDLabel_);
            recapGrid_.remove(recapTubularWallThicknessValueLabel_);
        }
        else if (packedBedBool_)
        {
            recapGrid_.remove(recapPackedBedTubeLabel_);
            recapGrid_.remove(recapPackedBedTubeUDLabel_);
            recapGrid_.remove(recapPackedBedTubeValueLabel_);
            recapGrid_.remove(recapPackedBedVoidFractionLabel_);
            recapGrid_.remove(recapPackedBedVoidFractionValueLabel_);
            recapGrid_.remove(recapPackedBedParticleLabel_);
            recapGrid_.remove(recapPackedBedParticleUDLabel_);
            recapGrid_.remove(recapPackedBedParticleValueLabel_);
        }
        else if (honeyCombBool_)
        {
            recapGrid_.remove(recapHoneyCombCPSILabel_);
            recapGrid_.remove(recapHoneyCombCPSIValueLabel_);
            recapGrid_.remove(recapHoneyCombWallThicknessLabel_);
            recapGrid_.remove(recapHoneyCombWallThicknessUDLabel_);
            recapGrid_.remove(recapHoneyCombWallThicknessValueLabel_);
            recapGrid_.remove(recapHoneyCombDuctLabel_);
            recapGrid_.remove(recapHoneyCombDuctValueLabel_);
        }
    }

    void het1dReactor::read()
    {
        L_     = Glib::Ascii::strtod(lengthEntry_.get_text());
        v_     = Glib::Ascii::strtod(velocityEntry_.get_text());
        tf_    = Glib::Ascii::strtod(timeEntry_.get_text());
        dt_    = Glib::Ascii::strtod(saveEntry_.get_text());
        NP_    = Glib::Ascii::strtod(pointsEntry_.get_text());

        ConvertsToMeter(L_,lengthCombo_.get_active_text());
        ConvertsToMeterPerSecond(v_,velocityCombo_.get_active_text());
        ConvertsToSecond(tf_,timeCombo_.get_active_text());
        ConvertsToSecond(dt_,saveCombo_.get_active_text());

        reactorType_ = reactorTypeCombo_.get_active_text();
        energy_      = energyCombo_.get_active_text();
        inert_       = inertEntry_.get_text();
        asaliProperties_->convertToCaption(inert_);
        
        if ( reactorTypeCombo_.get_active_text() == "tubular" )
        {
            Dt_ = Glib::Ascii::strtod(tubularTubeEntry_.get_text());

            ConvertsToMeter(Dt_,tubularTubeCombo_.get_active_text());

            section_ = tubularDuctCombo_.get_active_text();
            
            tw_      = Glib::Ascii::strtod(tubularWallThicknessEntry_.get_text());

            ConvertsToMeter(tw_,tubularWallThicknessCombo_.get_active_text());
        }
        else if ( reactorTypeCombo_.get_active_text() == "packed bed" )
        {
            Dt_   = Glib::Ascii::strtod(packedBedTubeEntry_.get_text());
            Dp_   = Glib::Ascii::strtod(packedBedParticleEntry_.get_text());
            epsi_ = Glib::Ascii::strtod(packedBedVoidFractionEntry_.get_text());

            ConvertsToMeter(Dt_,packedBedTubeCombo_.get_active_text());
            ConvertsToMeter(Dp_,packedBedParticleCombo_.get_active_text());
        }
        else if ( reactorTypeCombo_.get_active_text() == "honeycomb" )
        {
            cpsi_    = Glib::Ascii::strtod(honeyCombCPSIEntry_.get_text());
            tw_      = Glib::Ascii::strtod(honeyCombWallThicknessEntry_.get_text());

            ConvertsToMeter(tw_,honeyCombWallThicknessCombo_.get_active_text());

            section_ = honeyCombDuctCombo_.get_active_text();
        }
    }

    void het1dReactor::input()
    {
        {
            signal.disconnect();
            signal = nextButton1_.signal_clicked().connect(sigc::mem_fun(*this,&het1dReactor::kineticShow));
        }
        this->remove();
        this->options();
        this->add(mainBox_);
        this->resize(mainBox_.get_width(),mainBox_.get_height());
        this->show_all_children();
    }

    void het1dReactor::recap()
    {
        this->compositionReader();
        this->coverageReader();
        if ( checkComposition_.second == false )
        {
            this->checkComposition(checkComposition_.first);
        }
        else if ( checkCoverage_.second == false )
        {
            this->checkCoverage(checkCoverage_.first);
        }
        else
        {
            this->read();
            this->kineticReader();
            this->remove();
            this->clean();
            this->add(recapMainBox_);

            //Reactor type
            {
                recapReactorTypeValueLabel_.set_text(reactorType_);
            }

            //Velocity
            {
                std::ostringstream s;
                s << v_;
                recapVelocityValueLabel_.set_text(s.str());
            }

            //Temperature
            {
                std::ostringstream s;
                s << T_;
                recapTemperatureValueLabel_.set_text(s.str());
            }
            
            //Pressure
            {
                std::ostringstream s;
                s << p_;
                recapPressureValueLabel_.set_text(s.str());
            }
            
            int NC = -1;
            //Mole/mass fraction
            {
                recapFractionLabel_.set_text(fractionCombo_.get_active_text());
                {
                    std::string s1;
                    std::string s2;
                    for (unsigned int i=0;i<n_.size();i++)
                    {
                        if ( x_[i] != 0 && NC == -1)
                        {
                            s1 = n_[i];
                            std::ostringstream so;
                            so << x_[i];
                            s2 = so.str();
                            NC++;
                        }
                        else if ( x_[i] != 0 && NC != -1)
                        {
                            s1 = s1 + "\n" + n_[i];
                            std::ostringstream so;
                            so << x_[i];
                            s2 = s2 + "\n" + so.str();
                            NC++;
                        }
                    }
                    recapFractionNameLabel_.set_text(s1);
                    recapFractionValueLabel_.set_text(s2);
                }

                {
                    recapGrid_.attach(recapFractionLabel_,3,3,1,NC+1);
                    recapGrid_.attach(recapFractionNameLabel_,5,3,1,NC+1);
                    recapGrid_.attach(recapFractionValueLabel_,4,3,1,NC+1);
                }
            }
            
            //Length
            {
                recapGrid_.attach(recapLengthLabel_,3,4+NC,1,1);
                recapGrid_.attach(recapLengthUDLabel_,5,4+NC,1,1);
                recapGrid_.attach(recapLengthValueLabel_,4,4+NC,1,1);
                {
                    std::ostringstream s;
                    s << L_;
                    recapLengthValueLabel_.set_text(s.str());
                }
            }

            //Time
            {
                std::ostringstream s;
                s << tf_;
                recapTimeValueLabel_.set_text(s.str());
            }

            //Save
            {
                std::ostringstream s;
                s << dt_;
                recapSaveValueLabel_.set_text(s.str());
            }

            //Points
            {
                std::ostringstream s;
                s << NP_;
                recapPointsValueLabel_.set_text(s.str());
            }

            //Inert
            {
                recapInertValueLabel_.set_text(inert_);
            }

            if ( reactorType_ == "tubular" )
            {
                recapGrid_.attach(recapTubularTubeLabel_,3,5+NC,1,1);
                recapGrid_.attach(recapTubularTubeUDLabel_,5,5+NC,1,1);
                recapGrid_.attach(recapTubularTubeValueLabel_,4,5+NC,1,1);
                {
                    std::ostringstream s;
                    s << Dt_;
                    recapTubularTubeValueLabel_.set_text(s.str());
                }

                recapGrid_.attach(recapTubularWallThicknessLabel_,3,6+NC,1,1);
                recapGrid_.attach(recapTubularWallThicknessUDLabel_,5,6+NC,1,1);
                recapGrid_.attach(recapTubularWallThicknessValueLabel_,4,6+NC,1,1);
                {
                    std::ostringstream s;
                    s << tw_;
                    recapTubularWallThicknessValueLabel_.set_text(s.str());
                }
                
                recapGrid_.attach(recapTubularDuctLabel_,3,7+NC,1,1);
                recapGrid_.attach(recapTubularDuctValueLabel_,4,7+NC,1,1);
                {
                    recapTubularDuctValueLabel_.set_text(section_);
                }
                tubularBool_   = true;
                packedBedBool_ = false;
                honeyCombBool_ = false;
            }
            else if ( reactorType_ == "honeycomb" )
            {
                recapGrid_.attach(recapHoneyCombCPSILabel_,3,5+NC,1,1);
                recapGrid_.attach(recapHoneyCombCPSIValueLabel_,4,5+NC,1,1);
                {
                    std::ostringstream s;
                    s << cpsi_;
                    recapHoneyCombCPSIValueLabel_.set_text(s.str());
                }

                recapGrid_.attach(recapHoneyCombWallThicknessLabel_,3,6+NC,1,1);
                recapGrid_.attach(recapHoneyCombWallThicknessUDLabel_,5,6+NC,1,1);
                recapGrid_.attach(recapHoneyCombWallThicknessValueLabel_,4,6+NC,1,1);
                {
                    std::ostringstream s;
                    s << tw_;
                    recapHoneyCombWallThicknessValueLabel_.set_text(s.str());
                }

                recapGrid_.attach(recapHoneyCombDuctLabel_,3,7+NC,1,1);
                recapGrid_.attach(recapHoneyCombDuctValueLabel_,4,7+NC,1,1);
                {
                    recapHoneyCombDuctValueLabel_.set_text(section_);
                }

                tubularBool_   = false;
                packedBedBool_ = false;
                honeyCombBool_ = true;
            }
            else if ( reactorType_ == "packed bed" )
            {
                recapGrid_.attach(recapPackedBedTubeLabel_,3,5+NC,1,1);
                recapGrid_.attach(recapPackedBedTubeUDLabel_,5,5+NC,1,1);
                recapGrid_.attach(recapPackedBedTubeValueLabel_,4,5+NC,1,1);
                {
                    std::ostringstream s;
                    s << Dt_;
                    recapPackedBedTubeValueLabel_.set_text(s.str());
                }

                recapGrid_.attach(recapPackedBedVoidFractionLabel_,3,6+NC,1,1);
                recapGrid_.attach(recapPackedBedVoidFractionValueLabel_,4,6+NC,1,1);
                {
                    std::ostringstream s;
                    s << epsi_;
                    recapPackedBedVoidFractionValueLabel_.set_text(s.str());
                }

                recapGrid_.attach(recapPackedBedParticleLabel_,3,7+NC,1,1);
                recapGrid_.attach(recapPackedBedParticleUDLabel_,5,7+NC,1,1);
                recapGrid_.attach(recapPackedBedParticleValueLabel_,4,7+NC,1,1);
                {
                    std::ostringstream s;
                    s << Dp_;
                    recapPackedBedParticleValueLabel_.set_text(s.str());
                }

                tubularBool_   = false;
                packedBedBool_ = true;
                honeyCombBool_ = false;
            }
            
            //Kinetic
            {
                recapKineticValueLabel_.set_text(kineticCombo_.get_active_text());
            }

            {
                recapEnergyValueLabel_.set_text(energy_);
            }

            if ( kineticType_ == "load" && kineticCombo_.get_active_text() == "ASALI" )
            {
                if (asaliKineticButton_.get_parent() != nullptr )
                {
                    recapButtonBox_.remove(asaliKineticButton_);
                }
                recapButtonBox_.pack_start(asaliKineticButton_, Gtk::PACK_SHRINK);
            }

        }
        this->resize(recapMainBox_.get_width(),recapMainBox_.get_height());
        this->show_all_children();
    }

    void het1dReactor::run()
    {
        if ( kineticCombo_.get_active_text() == "CANTERA")
        {
            eq_->setCanteraThermo(thermo_);
            eq_->setCanteraTransport(transport_);
            eq_->setCanteraInterface(surface_);
            eq_->setCanteraKinetics(kinetic_);
            eq_->turnOnUserDefined(false);
            eq_->setHomogeneousReactions(false);
        }
        else if ( kineticCombo_.get_active_text() == "ASALI")
        {
            if ( kineticType_ == "none" )
            {
                this->compositionReader();
                this->kineticReader();
                eq_->turnOnUserDefined(true);
                eq_->setAsaliKinetic(asaliKinetic_->get_NR(),
                                     asaliKinetic_->get_k(),
                                     asaliKinetic_->get_Eatt(),
                                     asaliKinetic_->get_n(),
                                     asaliKinetic_->get_a(),
                                     asaliKinetic_->get_b(),
                                     index1_,
                                     index2_,
                                     canteraIndex_,
                                     asaliKinetic_->get_name(),
                                     stoich_,
                                     asaliKinetic_->get_converter());
                eq_->set_MW(asaliProperties_->get_MW());
                eq_->set_QfromSurface(asaliProperties_->get_Q());
                eq_->set_cp(asaliProperties_->get_cp());
                eq_->set_cond(asaliProperties_->get_cond());
                eq_->set_diff(asaliProperties_->get_diff());
                eq_->setHomogeneousReactions(false);
            }
            else
            {
                this->compositionReader();
                this->kineticReader();
                eq_->setCanteraThermo(thermo_);
                eq_->setCanteraTransport(transport_);
                eq_->turnOnUserDefined(false);
                eq_->setAsaliKinetic(asaliKinetic_->get_NR(),
                                     asaliKinetic_->get_k(),
                                     asaliKinetic_->get_Eatt(),
                                     asaliKinetic_->get_n(),
                                     asaliKinetic_->get_a(),
                                     asaliKinetic_->get_b(),
                                     index1_,
                                     index2_,
                                     canteraIndex_,
                                     asaliKinetic_->get_name(),
                                     stoich_,
                                     asaliKinetic_->get_converter());
                eq_->setHomogeneousReactions(false);
            }
        }

        eq_->setKineticType(kineticCombo_.get_active_text());
        eq_->setNumberOfPoints(NP_);
        eq_->setReactorType(reactorType_);
        eq_->setLength(L_);

        if ( reactorType_ == "tubular" )
        {
            eq_->setTubular(Dt_,tw_,section_);
        }
        else if ( reactorType_ == "packed bed" )
        {
            eq_->setPackedBed(Dt_,Dp_,epsi_);
        }
        else if ( reactorType_ == "honeycomb" )
        {
            eq_->setHoneyComb(cpsi_,tw_,section_);
        }

        eq_->resize();
        eq_->setHeterogeneusReactions(true);
            
        if ( energy_ == "on" )
        {
            eq_->setEnergy(true);
        }
        else if ( energy_ == "off" )
        {
            eq_->setEnergy(false);
        }
            
        eq_->setPressure(p_);
        eq_->setCatalystProperties(asaliCatalystProperties_->get_load(),
                                   asaliCatalystProperties_->get_rho(),
                                   asaliCatalystProperties_->get_cp(),
                                   asaliCatalystProperties_->get_cond());

        std::vector<double> x0(eq_->NumberOfEquations());
        if ( kineticType_ == "none" )
        {
            double MWmix = 0;
            std::vector<double> xInlet(x_.size());
            if ( fractionCombo_.get_active_row_number() == 0 )
            {
                xInlet = asaliProperties_->get_mass_fraction(asaliProperties_->get_MW(),x_);
                MWmix  = asaliProperties_->get_MWmix(asaliProperties_->get_MW(),xInlet);
            }
            else if ( fractionCombo_.get_active_row_number() == 1 )
            {
                for (unsigned int i=0;i<x_.size();i++)
                {
                    xInlet[i] = x_[i];
                }
                MWmix = asaliProperties_->get_MWmix(asaliProperties_->get_MW(),xInlet);
            }
            
            std::vector<double> xInside(x_.size());
            for (unsigned int i=0;i<x_.size();i++)
            {
                if ( n_[i] == inert_ )
                {
                    eq_->setInert(i);
                    xInside[i] = 1.;
                }
                else
                {
                    xInside[i] = 0.;
                }
            }

            unsigned int counter = 0;
            for (unsigned int i=0;i<NP_;i++)
            {
                for (unsigned int j=0;j<x_.size();j++)
                {
                    if ( i == 0 )
                    {
                        x0[counter++] = xInlet[j];
                    }
                    else
                    {
                        x0[counter++] = xInside[j];
                    }
                }
                for (unsigned int j=0;j<x_.size();j++)
                {
                    if ( i == 0 )
                    {
                        x0[counter++] = xInlet[j];
                    }
                    else
                    {
                        x0[counter++] = xInside[j];
                    }
                }
                x0[counter++] = T_;
                x0[counter++] = asaliCatalystProperties_->get_T();
            }

            eq_->setSpecificMassFlowRate(v_*p_*MWmix/(8314.*T_));
            eq_->setInletConditions(xInlet,T_);
        }
        else
        {
            if ( kineticCombo_.get_active_text() == "ASALI" )
            {
                canteraInterface_->setTemperature(T_);
                canteraInterface_->setPressure(p_);
                if ( fractionCombo_.get_active_row_number() == 0 )
                {
                    canteraInterface_->setMoleFraction(x_,n_);
                }
                else if ( fractionCombo_.get_active_row_number() == 1 )
                {
                    canteraInterface_->setMassFraction(x_,n_);
                }

                std::vector<double> xInlet(x_.size());
                {
                    std::vector<double> y = canteraInterface_->massFractions();
                    for (unsigned int i=0;i<n_.size();i++)
                    {
                        for (unsigned int j=0;j<canteraInterface_->nSpecies();j++)
                        {
                            if ( n_[i] == canteraInterface_->names()[j] )
                            {
                                xInlet[i] = y[j];
                                break;
                            }
                        }
                    }
                }

                std::vector<double> xInside(x_.size());
                for (unsigned int i=0;i<x_.size();i++)
                {
                    if ( n_[i] == inert_ )
                    {
                        eq_->setInert(i);
                        xInside[i] = 1.;
                    }
                    else
                    {
                        xInside[i] = 0.;
                    }
                }
                unsigned int counter = 0;
                for (unsigned int i=0;i<NP_;i++)
                {
                    for (unsigned int j=0;j<x_.size();j++)
                    {
                        if ( i == 0 )
                        {
                            x0[counter++] = xInlet[j];
                        }
                        else
                        {
                            x0[counter++] = xInside[j];
                        }
                    }
                    for (unsigned int j=0;j<x_.size();j++)
                    {
                        if ( i == 0 )
                        {
                            x0[counter++] = xInlet[j];
                        }
                        else
                        {
                            x0[counter++] = xInside[j];
                        }
                    }
                    x0[counter++] = T_;
                    x0[counter++] = asaliCatalystProperties_->get_T();
                }
                eq_->setSpecificMassFlowRate(v_*canteraInterface_->density());
                eq_->setInletConditions(xInlet,T_);
            }
            else
            {
                canteraInterface_->setTemperature(T_);
                canteraInterface_->setPressure(p_);
                if ( fractionCombo_.get_active_row_number() == 0 )
                {
                    canteraInterface_->setMoleFraction(x_,n_);
                }
                else if ( fractionCombo_.get_active_row_number() == 1 )
                {
                    canteraInterface_->setMassFraction(x_,n_);
                }

                std::vector<double> xInlet(thermo_->nSpecies());
                std::vector<double> xInside(thermo_->nSpecies());
                {
                    std::vector<double> y = canteraInterface_->massFractions();
                    for (unsigned int i=0;i<thermo_->nSpecies();i++)
                    {
                        if ( thermo_->speciesName(i) == inert_ )
                        {
                            eq_->setInert(i);
                            xInlet[i]  = y[i];
                            xInside[i] = 1.;
                        }
                        else
                        {
                            xInlet[i]  = y[i];
                            xInside[i] = 0.;
                        }
                    }
                }
                
                std::vector<double> thetaInlet(surface_->nSpecies());
                {
                    for (unsigned int i=0;i<nc_.size();i++)
                    {
                        for (unsigned int j=0;j<surface_->nSpecies();j++)
                        {
                            if ( nc_[i] == surface_->speciesName(j) )
                            {
                                thetaInlet[j] = xc_[i];
                                break;
                            }
                        }
                    }
                }

                unsigned int counter = 0;
                for (unsigned int i=0;i<NP_;i++)
                {
                    for (unsigned int j=0;j<thermo_->nSpecies();j++)
                    {
                        if ( i == 0 )
                        {
                            x0[counter++] = xInlet[j];
                        }
                        else
                        {
                            x0[counter++] = xInside[j];
                        }
                    }
                    for (unsigned int j=0;j<thermo_->nSpecies();j++)
                    {
                        if ( i == 0 )
                        {
                            x0[counter++] = xInlet[j];
                        }
                        else
                        {
                            x0[counter++] = xInside[j];
                        }
                    }
                    for (unsigned int j=0;j<surface_->nSpecies();j++)
                    {
                        x0[counter++] = thetaInlet[j];
                    }
                    x0[counter++] = T_;
                    x0[counter++] = asaliCatalystProperties_->get_T();
                }

                eq_->setSpecificMassFlowRate(v_*canteraInterface_->density());
                eq_->setInletConditions(xInlet,T_);
            }
        }

        ASALI::odeInterface<ASALI::het1dEquations> ode;
        ASALI::bvpInterface<ASALI::het1dEquations> bvp;

        eq_->setResolutionType("initial");
        this->bar(0.,"Starting...");
        ode.setEquations(eq_);
        ode.setInitialConditions(0.,x0);
        ode.solve(1e07,x0);

        bvp.setEquations(eq_);
        bvp.setBandDimensions(eq_->NumberOfEquations()/NP_ + 1,eq_->NumberOfEquations()/NP_ + 1);

        eq_->setResolutionType("model");
        eq_->store(0.,x0);
        this->bar(1e-05,"Starting...");

        //Start solving
        {
            double  ti    = 0.;
            double  tf    = 0.;
            double  dt    = 0.;
            
            if ( alfa_ != 0. )
            {
                dt = dt_/(eq_->NumberOfEquations()*5.);
            }
            else
            {
                dt = dt_/100.;
            }
            
            double  td    = 0;
            double  time0 = double(std::clock()/CLOCKS_PER_SEC);
            double  timef = 0.;
            double  tm    = 0;
            int     Nt    = int(tf_/dt) + 1;
            for (int i=0;i<Nt;i++)
            {
                tf = ti + dt;

                bvp.setInitialConditions(ti,x0);
                bvp.solve(tf,x0);

                td += dt;
                
                if ( std::fabs(td - dt_) < dt*0.001 )
                {
                    eq_->store(tf,x0);
                    td = 0.;
                }

                timef = double(std::clock()/CLOCKS_PER_SEC);
                tm    = (timef-time0)*(Nt-i+1)/(i+1);

                ti = tf;

                this->bar(double(i+1)*dt/tf_,"Remaning time: " + this->convertToTimeFormat(tm));

                if (!bar_->check() || !bvp.check())
                {
                    break;
                }
            }
        }

        bar_->exit();

        if ( ode.check()   == true &&
             bvp.check()   == true &&
             bar_->check() == true)
        {
            //Add plot button
            {
                recapButtonBox_.pack_start(asaliPlotButton_, Gtk::PACK_SHRINK);
                plotButtonBool_ = true;
                this->show_all_children();
            }
            this->save();
        }
    }

    void het1dReactor::propertiesShow()
    {
        this->compositionReader();
        this->kineticReader();
        asaliProperties_->destroy();
        asaliProperties_->set_type("het1d");
        asaliProperties_->set_energy(energy_);
        asaliProperties_->set_n(n_);
        asaliProperties_->set_reactions(asaliKinetic_->get_name(),asaliKinetic_->get_stoich());
        asaliProperties_->build();
        asaliProperties_->show();

        {
            signal.disconnect();
            signal = nextButton1_.signal_clicked().connect(sigc::mem_fun(*this,&het1dReactor::recap));
        }
    }

    void het1dReactor::catalystPropertiesShow()
    {
        asaliCatalystProperties_->show();
        {
            run_.disconnect();
            run_ = runButton_.signal_clicked().connect(sigc::mem_fun(*this,&het1dReactor::run));
        }
    }

    void het1dReactor::save()
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
                output.setf(std::ios::scientific);
                output.precision(6);
                
                output << "Kinetic type:     " << kineticCombo_.get_active_text() << std::endl;
                output << "Reactor length:   " << L_ << " m" << std::endl;
                output << "Inlet velocity:   " << v_ << " m/s" << std::endl;
                output << "Pressure:         " << p_ << " Pa" << std::endl;
                output << "Integration time: " << tf_ << " s" << std::endl;

                std::vector<double>                             t   = eq_->getTime();
                std::vector<std::vector<double> >               Tb  = eq_->getBulkTemperature();
                std::vector<std::vector<double> >               Tw  = eq_->getWallTemperature();
                std::vector<std::vector<std::vector<double> > > yb  = eq_->getBulkSpecie();
                std::vector<std::vector<std::vector<double> > > yw  = eq_->getWallSpecie();
                std::vector<std::vector<std::vector<double> > > Z   = eq_->getSite();
                double                                          dz  = L_/double(NP_- 1);

                if ( kineticCombo_.get_active_text() == "ASALI" )
                {
                    //Conversion from mass to mole
                    std::vector<std::vector<std::vector<double> > > moleb = eq_->getBulkSpecie();
                    std::vector<std::vector<std::vector<double> > > molew = eq_->getWallSpecie();
                    {
                        if ( kineticType_ == "none" )
                        {
                            for (unsigned int j=0;j<t.size();j++)
                            {
                                for (unsigned int k=0;k<NP_;k++)
                                {
                                    std::vector<double> xb(n_.size());
                                    std::vector<double> xw(n_.size());
                                    for (unsigned int i=0;i<n_.size();i++)
                                    {
                                        xb[i] = yb[j][k][i];
                                        xw[i] = yw[j][k][i];
                                    }
                                    
                                    xb = asaliProperties_->get_mole_fraction(asaliProperties_->get_MW(),xb);
                                    xw = asaliProperties_->get_mole_fraction(asaliProperties_->get_MW(),xw);

                                    for (unsigned int i=0;i<n_.size();i++)
                                    {
                                        moleb[j][k][i] = xb[i];
                                        molew[j][k][i] = xw[i];
                                    }
                                }
                            }
                        }
                        else
                        {
                            for (unsigned int j=0;j<t.size();j++)
                            {
                                for (unsigned int k=0;k<NP_;k++)
                                {
                                    //Bulk
                                    {
                                        canteraInterface_->setTemperature(Tb[j][k]);
                                        canteraInterface_->setPressure(p_);
                                        std::vector<double> x(n_.size());
                                        for (unsigned int i=0;i<n_.size();i++)
                                        {
                                            x[i] = yb[j][k][i];
                                        }
                                        
                                        canteraInterface_->setMassFraction(x,n_);
                                        
                                        for (unsigned int i=0;i<n_.size();i++)
                                        {
                                            for (unsigned int q=0;q<canteraInterface_->names().size();q++)
                                            {
                                                if ( n_[i] == canteraInterface_->names()[q] )
                                                {
                                                    moleb[j][k][i] = canteraInterface_->moleFractions()[q];
                                                    break;
                                                }
                                            }
                                        }
                                    }

                                    //Wall
                                    {
                                        canteraInterface_->setTemperature(Tw[j][k]);
                                        canteraInterface_->setPressure(p_);
                                        std::vector<double> x(n_.size());
                                        for (unsigned int i=0;i<n_.size();i++)
                                        {
                                            x[i] = yw[j][k][i];
                                        }
                                        
                                        canteraInterface_->setMassFraction(x,n_);
                                        
                                        for (unsigned int i=0;i<n_.size();i++)
                                        {
                                            for (unsigned int q=0;q<canteraInterface_->names().size();q++)
                                            {
                                                if ( n_[i] == canteraInterface_->names()[q] )
                                                {
                                                    molew[j][k][i] = canteraInterface_->moleFractions()[q];
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }

                    for (unsigned int i=0;i<n_.size();i++)
                    {
                        output << "\nSpecie:           " << n_[i] << " (bulk) " << std::endl;

                        output << "Mass fraction" << std::endl;
                        output << "Length [m]/Time [s]" << "\t";
                        for (unsigned int j=0;j<t.size();j++)
                        {
                            output << t[j] << "\t";
                        }
                        
                        output << std::endl;
                        
                        for (unsigned int k=0;k<NP_;k++)
                        {
                            output << k*dz << "\t";
                            for (unsigned int j=0;j<t.size();j++)
                            {
                                output << yb[j][k][i] << "\t";
                            }
                            output << std::endl;
                        }
                        output << std::endl;
                        output << "Mole fraction" << std::endl;
                        output << "Length [m]/Time [s]" << "\t";
                        for (unsigned int j=0;j<t.size();j++)
                        {
                            output << t[j] << "\t";
                        }
                        
                        output << std::endl;
                        
                        for (unsigned int k=0;k<NP_;k++)
                        {
                            output << k*dz << "\t";
                            for (unsigned int j=0;j<t.size();j++)
                            {
                                output << moleb[j][k][i] << "\t";
                            }
                            output << std::endl;
                        }
                        output << std::endl;
                    }

                    for (unsigned int i=0;i<n_.size();i++)
                    {
                        output << "\nSpecie:           " << n_[i] << " (wall) " << std::endl;

                        output << "Mass fraction" << std::endl;
                        output << "Length [m]/Time [s]" << "\t";
                        for (unsigned int j=0;j<t.size();j++)
                        {
                            output << t[j] << "\t";
                        }
                        
                        output << std::endl;
                        
                        for (unsigned int k=0;k<NP_;k++)
                        {
                            output << k*dz << "\t";
                            for (unsigned int j=0;j<t.size();j++)
                            {
                                output << yw[j][k][i] << "\t";
                            }
                            output << std::endl;
                        }
                        output << std::endl;
                        output << "Mole fraction" << std::endl;
                        output << "Length [m]/Time [s]" << "\t";
                        for (unsigned int j=0;j<t.size();j++)
                        {
                            output << t[j] << "\t";
                        }
                        
                        output << std::endl;
                        
                        for (unsigned int k=0;k<NP_;k++)
                        {
                            output << k*dz << "\t";
                            for (unsigned int j=0;j<t.size();j++)
                            {
                                output << molew[j][k][i] << "\t";
                            }
                            output << std::endl;
                        }
                        output << std::endl;
                    }

                    output << "Temperature (bulk) [K]" << std::endl;
                    output << "Length [m]/Time [s]" << "\t";
                    for (unsigned int j=0;j<t.size();j++)
                    {
                        output << t[j] << "\t";
                    }
                    output << std::endl;
                    for (unsigned int k=0;k<NP_;k++)
                    {
                        output << k*dz << "\t";
                        for (unsigned int j=0;j<t.size();j++)
                        {
                            output << Tb[j][k] << "\t";
                        }
                        output << std::endl;
                    }
                    output << std::endl;
                    output << "Temperature (wall) [K]" << std::endl;
                    output << "Length [m]/Time [s]" << "\t";
                    for (unsigned int j=0;j<t.size();j++)
                    {
                        output << t[j] << "\t";
                    }
                    output << std::endl;
                    for (unsigned int k=0;k<NP_;k++)
                    {
                        output << k*dz << "\t";
                        for (unsigned int j=0;j<t.size();j++)
                        {
                            output << Tw[j][k] << "\t";
                        }
                        output << std::endl;
                    }
                    output << std::endl;
                }
                else if ( kineticCombo_.get_active_text() == "CANTERA" )
                {
                    //Conversion from mass to mole
                    std::vector<std::vector<std::vector<double> > > moleb = eq_->getBulkSpecie();
                    std::vector<std::vector<std::vector<double> > > molew = eq_->getWallSpecie();
                    {
                        std::vector<std::string> n(thermo_->nSpecies());
                        for (unsigned int i=0;i<thermo_->nSpecies();i++)
                        {
                            n[i] = thermo_->speciesName(i);
                        }
                        for (unsigned int j=0;j<t.size();j++)
                        {
                            for (unsigned int k=0;k<NP_;k++)
                            {
                                //Bulk
                                {
                                    canteraInterface_->setTemperature(Tb[j][k]);
                                    canteraInterface_->setPressure(p_);
                                    std::vector<double> x(thermo_->nSpecies());
                                    for (unsigned int i=0;i<thermo_->nSpecies();i++)
                                    {
                                        x[i] = yb[j][k][i];
                                    }
                                    canteraInterface_->setMassFraction(x,n);
                                    x = canteraInterface_->moleFractions();

                                    for (unsigned int i=0;i<thermo_->nSpecies();i++)
                                    {
                                        moleb[j][k][i] = x[i];
                                    }
                                }
                                //Wall
                                {
                                    canteraInterface_->setTemperature(Tw[j][k]);
                                    canteraInterface_->setPressure(p_);
                                    std::vector<double> x(thermo_->nSpecies());
                                    for (unsigned int i=0;i<thermo_->nSpecies();i++)
                                    {
                                        x[i] = yw[j][k][i];
                                    }
                                    canteraInterface_->setMassFraction(x,n);
                                    x = canteraInterface_->moleFractions();

                                    for (unsigned int i=0;i<thermo_->nSpecies();i++)
                                    {
                                        molew[j][k][i] = x[i];
                                    }
                                }
                            }
                        }
                    }

                    for (unsigned int i=0;i<thermo_->nSpecies();i++)
                    {
                        std::string name = thermo_->speciesName(i);
                        output << "\nSpecie:           " << name << " (bulk)" << std::endl;

                        output << "Mass fraction" << std::endl;
                        output << "Length [m]/Time [s]" << "\t";
                        for (unsigned int j=0;j<t.size();j++)
                        {
                            output << t[j] << "\t";
                        }
                        
                        output << std::endl;
                        
                        for (unsigned int k=0;k<NP_;k++)
                        {
                            output << k*dz << "\t";
                            for (unsigned int j=0;j<t.size();j++)
                            {
                                output << yb[j][k][i] << "\t";
                            }
                            output << std::endl;
                        }
                        output << std::endl;
                        output << "Mole fraction" << std::endl;
                        output << "Length [m]/Time [s]" << "\t";
                        for (unsigned int j=0;j<t.size();j++)
                        {
                            output << t[j] << "\t";
                        }
                        
                        output << std::endl;
                        
                        for (unsigned int k=0;k<NP_;k++)
                        {
                            output << k*dz << "\t";
                            for (unsigned int j=0;j<t.size();j++)
                            {
                                output << moleb[j][k][i] << "\t";
                            }
                            output << std::endl;
                        }
                        output << std::endl;
                    }

                    for (unsigned int i=0;i<thermo_->nSpecies();i++)
                    {
                        std::string name = thermo_->speciesName(i);
                        output << "\nSpecie:           " << name << " (wall)" << std::endl;

                        output << "Mass fraction" << std::endl;
                        output << "Length [m]/Time [s]" << "\t";
                        for (unsigned int j=0;j<t.size();j++)
                        {
                            output << t[j] << "\t";
                        }
                        
                        output << std::endl;
                        
                        for (unsigned int k=0;k<NP_;k++)
                        {
                            output << k*dz << "\t";
                            for (unsigned int j=0;j<t.size();j++)
                            {
                                output << yw[j][k][i] << "\t";
                            }
                            output << std::endl;
                        }
                        output << std::endl;
                        output << "Mole fraction" << std::endl;
                        output << "Length [m]/Time [s]" << "\t";
                        for (unsigned int j=0;j<t.size();j++)
                        {
                            output << t[j] << "\t";
                        }
                        
                        output << std::endl;
                        
                        for (unsigned int k=0;k<NP_;k++)
                        {
                            output << k*dz << "\t";
                            for (unsigned int j=0;j<t.size();j++)
                            {
                                output << molew[j][k][i] << "\t";
                            }
                            output << std::endl;
                        }
                        output << std::endl;
                    }

                    for (unsigned int i=0;i<surface_->nSpecies();i++)
                    {
                        std::string name = surface_->speciesName(i);
                        output << "\nSpecie:           " << name << std::endl;

                        output << "Length [m]/Time [s]" << "\t";
                        for (unsigned int j=0;j<t.size();j++)
                        {
                            output << t[j] << "\t";
                        }
                        
                        output << std::endl;
                        
                        for (unsigned int k=0;k<NP_;k++)
                        {
                            output << k*dz << "\t";
                            for (unsigned int j=0;j<t.size();j++)
                            {
                                output << Z[j][k][i] << "\t";
                            }
                            output << std::endl;
                        }
                        output << std::endl;
                    }

                    output << "Temperature (bulk) [K]" << std::endl;
                    output << "Length [m]/Time [s]" << "\t";
                    for (unsigned int j=0;j<t.size();j++)
                    {
                        output << t[j] << "\t";
                    }
                    output << std::endl;
                    for (unsigned int k=0;k<NP_;k++)
                    {
                        output << k*dz << "\t";
                        for (unsigned int j=0;j<t.size();j++)
                        {
                            output << Tb[j][k] << "\t";
                        }
                        output << std::endl;
                    }
                    output << std::endl;
                    output << "Temperature (wall) [K]" << std::endl;
                    output << "Length [m]/Time [s]" << "\t";
                    for (unsigned int j=0;j<t.size();j++)
                    {
                        output << t[j] << "\t";
                    }
                    output << std::endl;
                    for (unsigned int k=0;k<NP_;k++)
                    {
                        output << k*dz << "\t";
                        for (unsigned int j=0;j<t.size();j++)
                        {
                            output << Tw[j][k] << "\t";
                        }
                        output << std::endl;
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
                break;
            }
        }
    }

    void het1dReactor::plot()
    {
        if (!asaliPlot_)
        {
            delete asaliPlot_;
        }

        asaliPlot_ = new ASALI::asaliPlot();
        asaliPlot_->setTime(eq_->getTime());

        if ( kineticCombo_.get_active_text() == "ASALI" )
        {
            std::vector<double>                             t   = eq_->getTime();
            std::vector<std::vector<double> >               Tb  = eq_->getBulkTemperature();
            std::vector<std::vector<double> >               Tw  = eq_->getWallTemperature();
            std::vector<std::vector<std::vector<double> > > yb  = eq_->getBulkSpecie();
            std::vector<std::vector<std::vector<double> > > yw  = eq_->getWallSpecie();

            //Conversion from mass to mole
            std::vector<std::vector<std::vector<double> > > moleb = eq_->getBulkSpecie();
            std::vector<std::vector<std::vector<double> > > molew = eq_->getWallSpecie();
            {
                if ( kineticType_ == "none" )
                {
                    for (unsigned int j=0;j<t.size();j++)
                    {
                        for (unsigned int k=0;k<NP_;k++)
                        {
                            std::vector<double> xb(n_.size());
                            std::vector<double> xw(n_.size());
                            for (unsigned int i=0;i<n_.size();i++)
                            {
                                xb[i] = yb[j][k][i];
                                xw[i] = yw[j][k][i];
                            }
                            
                            xb = asaliProperties_->get_mole_fraction(asaliProperties_->get_MW(),xb);
                            xw = asaliProperties_->get_mole_fraction(asaliProperties_->get_MW(),xw);

                            for (unsigned int i=0;i<n_.size();i++)
                            {
                                moleb[j][k][i] = xb[i];
                                molew[j][k][i] = xw[i];
                            }
                        }
                    }
                }
                else
                {
                    for (unsigned int j=0;j<t.size();j++)
                    {
                        for (unsigned int k=0;k<NP_;k++)
                        {
                            //Bulk
                            {
                                canteraInterface_->setTemperature(Tb[j][k]);
                                canteraInterface_->setPressure(p_);
                                std::vector<double> x(n_.size());
                                for (unsigned int i=0;i<n_.size();i++)
                                {
                                    x[i] = yb[j][k][i];
                                }
                                canteraInterface_->setMassFraction(x,n_);
                                for (unsigned int i=0;i<n_.size();i++)
                                {
                                    for (unsigned int q=0;q<canteraInterface_->names().size();q++)
                                    {
                                        if ( n_[i] == canteraInterface_->names()[q] )
                                        {
                                            moleb[j][k][i] = canteraInterface_->moleFractions()[q];
                                            break;
                                        }
                                    }
                                }
                            }

                            //Wall
                            {
                                canteraInterface_->setTemperature(Tw[j][k]);
                                canteraInterface_->setPressure(p_);
                                std::vector<double> x(n_.size());
                                for (unsigned int i=0;i<n_.size();i++)
                                {
                                    x[i] = yw[j][k][i];
                                }
                                canteraInterface_->setMassFraction(x,n_);
                                for (unsigned int i=0;i<n_.size();i++)
                                {
                                    for (unsigned int q=0;q<canteraInterface_->names().size();q++)
                                    {
                                        if ( n_[i] == canteraInterface_->names()[q] )
                                        {
                                            molew[j][k][i] = canteraInterface_->moleFractions()[q];
                                            break;
                                        }
                                    }
                                }
                            }

                        }
                    }
                }
            }

            std::vector<std::string> n(n_.size()*2);
            for (unsigned int i=0;i<n_.size();i++)
            {
                n[i] = n_[i] + "(bulk)";
            }
            for (unsigned int i=0;i<n_.size();i++)
            {
                n[i+n_.size()] = n_[i] + "(wall)";
            }

            asaliPlot_->setSpecieNames(n);
            asaliPlot_->setSpecie(yb,moleb,yw,molew);
            asaliPlot_->setTemperature(Tb,Tw);
        }
        else if ( kineticCombo_.get_active_text() == "CANTERA" )
        {
            std::vector<double>                             t   = eq_->getTime();
            std::vector<std::vector<double> >               Tb  = eq_->getBulkTemperature();
            std::vector<std::vector<double> >               Tw  = eq_->getWallTemperature();
            std::vector<std::vector<std::vector<double> > > yb  = eq_->getBulkSpecie();
            std::vector<std::vector<std::vector<double> > > yw  = eq_->getWallSpecie();

            //Conversion from mass to mole
            std::vector<std::vector<std::vector<double> > > moleb = eq_->getBulkSpecie();
            std::vector<std::vector<std::vector<double> > > molew = eq_->getWallSpecie();
            std::vector<std::string> n(thermo_->nSpecies());
            {
                for (unsigned int i=0;i<thermo_->nSpecies();i++)
                {
                    n[i] = thermo_->speciesName(i);
                }

                for (unsigned int j=0;j<t.size();j++)
                {
                    for (unsigned int k=0;k<NP_;k++)
                    {
                        //Bulk
                        {
                            canteraInterface_->setTemperature(Tb[j][k]);
                            canteraInterface_->setPressure(p_);
                            std::vector<double> x(thermo_->nSpecies());
                            for (unsigned int i=0;i<thermo_->nSpecies();i++)
                            {
                                x[i] = yb[j][k][i];
                            }
                            canteraInterface_->setMassFraction(x,n);
                            x = canteraInterface_->moleFractions();

                            for (unsigned int i=0;i<thermo_->nSpecies();i++)
                            {
                                moleb[j][k][i] = x[i];
                            }
                        }
                        //Wall
                        {
                            canteraInterface_->setTemperature(Tw[j][k]);
                            canteraInterface_->setPressure(p_);
                            std::vector<double> x(thermo_->nSpecies());
                            for (unsigned int i=0;i<thermo_->nSpecies();i++)
                            {
                                x[i] = yw[j][k][i];
                            }
                            canteraInterface_->setMassFraction(x,n);
                            x = canteraInterface_->moleFractions();

                            for (unsigned int i=0;i<thermo_->nSpecies();i++)
                            {
                                molew[j][k][i] = x[i];
                            }
                        }
                    }
                }
            }

            n.resize(thermo_->nSpecies()*2);
            for (unsigned int i=0;i<thermo_->nSpecies();i++)
            {
                n[i] = thermo_->speciesName(i) + "(bulk)";
            }
            for (unsigned int i=0;i<thermo_->nSpecies();i++)
            {
                n[i+thermo_->nSpecies()] = thermo_->speciesName(i) + "(wall)";
            }

            asaliPlot_->setSpecieNames(n);
            asaliPlot_->setSpecie(yb,moleb,yw,molew);

            n.resize(surface_->nSpecies());
            for (unsigned int i=0;i<surface_->nSpecies();i++)
            {
                n[i] = surface_->speciesName(i);
            }
            asaliPlot_->setSiteNames(n);
            asaliPlot_->setSite(eq_->getSite());
            asaliPlot_->setTemperature(Tb,Tw);
        }
        
        
        //Length
        {
            double dz = L_/double(NP_- 1); 
            std::vector<double> l(NP_);
            for (unsigned int k=0;k<NP_;k++)
            {
                l[k] = k*dz;
            }
            asaliPlot_->setLength(l,lengthCombo_.get_active_text());
        }

        asaliPlot_->setType("het1d");
        asaliPlot_->build();
        asaliPlot_->show();
    }

}
