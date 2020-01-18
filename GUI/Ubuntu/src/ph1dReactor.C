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

#include "ph1dReactor.h"

namespace ASALI
{
    ph1dReactor::ph1dReactor(Cantera::ThermoPhase *thermo,
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
      recapButtonBox_(Gtk::ORIENTATION_VERTICAL),
      lengthLabel_("Length"),
      velocityLabel_("Velocity"),
      loadLabel_("Catalyst load"),
      timeLabel_("Integration time"),
      saveLabel_("Save solution every"),
      energyLabel_("Energy"),
      pointsLabel_("Number of points"),
      inertLabel_("Inert specie"),
      resolutionLabel_("Resolution type"),
      logo1_("images/Ph1DLogo.png"),
      logo2_("images/Ph1DLogo.png"),
      plotButtonBool_(false)
    {

        eq_ = new ASALI::ph1dEquations();

        //Input
        {
            this->set_border_width(15);
            this->set_title("ASALI: 1D PH reactor");
            this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
            this->set_icon_from_file("images/Icon.png");

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
                
                //Catalytic load
                propertiesGrid_.attach(loadLabel_,0,2,1,1);
                propertiesGrid_.attach(loadEntry_,1,2,1,1);
                loadEntry_.set_text("1");
                propertiesGrid_.attach(loadCombo_,2,2,1,1);
                loadCombo_.append("1/m");
                loadCombo_.append("1/dm");
                loadCombo_.append("1/cm");
                loadCombo_.append("1/mm");
                loadCombo_.set_active(0);

                //Time
                propertiesGrid_.attach(timeLabel_,0,3,1,1);
                propertiesGrid_.attach(timeEntry_,1,3,1,1);
                timeEntry_.set_text("1");
                propertiesGrid_.attach(timeCombo_,2,3,1,1);
                timeCombo_.append("s");
                timeCombo_.append("min");
                timeCombo_.append("h");
                timeCombo_.append("d");
                timeCombo_.set_active(0);

                //Save options
                propertiesGrid_.attach(saveLabel_,0,4,1,1);
                propertiesGrid_.attach(saveEntry_,1,4,1,1);
                saveEntry_.set_text("0.1");
                propertiesGrid_.attach(saveCombo_,2,4,1,1);
                saveCombo_.append("s");
                saveCombo_.append("min");
                saveCombo_.append("h");
                saveCombo_.append("d");
                saveCombo_.set_active(0);

                //Number of points
                propertiesGrid_.attach(pointsLabel_,0,5,1,1);
                propertiesGrid_.attach(pointsEntry_,1,5,1,1);
                pointsEntry_.set_text("10");

                //Inert species
                propertiesGrid_.attach(inertLabel_,0,6,1,1);
                propertiesGrid_.attach(inertEntry_,1,6,1,1);
                inertEntry_.set_text("AR");

                //Resolution type
                propertiesGrid_.attach(resolutionLabel_,0,7,1,1);
                propertiesGrid_.attach(resolutionCombo_,1,7,1,1);
                resolutionCombo_.append("steady state");
                resolutionCombo_.append("transient");
                resolutionCombo_.set_active(0);

                //Energy
                propertiesGrid_.attach(energyLabel_,0,8,1,1);
                propertiesGrid_.attach(energyCombo_,1,8,1,1);
                energyCombo_.append("on");
                energyCombo_.append("off");
                energyCombo_.set_active(1);
                
                //Buttons
                propertiesGrid_.attach(exitButton3_,0,9,1,1);
                exitButton3_.signal_clicked().connect(sigc::mem_fun(*this,&ph1dReactor::exit));
                propertiesGrid_.attach(nextButton3_,2,9,1,1);
                nextButton3_.signal_clicked().connect(sigc::mem_fun(*this,&ph1dReactor::composition));

                this->show_all_children();
            }
        }

        //Recap
        {
            recapMainBox_.set_halign(Gtk::ALIGN_START);
            recapMainBox_.set_spacing(10);
            recapMainBox_.pack_start(logoBox_, Gtk::PACK_SHRINK);
            {
                logoBox_.set_halign(Gtk::ALIGN_START);
                logoBox_.set_spacing(10);
                logoBox_.pack_start(logo2_, Gtk::PACK_SHRINK);
                logoBox_.pack_start(recapButtonBox_, Gtk::PACK_SHRINK);
                {
                    recapButtonBox_.set_layout(Gtk::BUTTONBOX_CENTER);
                    recapButtonBox_.set_spacing(10);
                    recapButtonBox_.pack_start(runButton_, Gtk::PACK_SHRINK);
                    runButton_.signal_clicked().connect(sigc::mem_fun(*this,&ph1dReactor::run));
                    recapButtonBox_.pack_start(saveButton_, Gtk::PACK_SHRINK);
                    saveButton_.signal_clicked().connect(sigc::mem_fun(*this,&ph1dReactor::save));
                    asaliPlotButton_.signal_clicked().connect(sigc::mem_fun(*this,&ph1dReactor::plot));
                    
                    asaliKineticButton_.signal_clicked().connect(sigc::mem_fun(*this,&ph1dReactor::kineticShow));
                    asaliPropertiesButton_.signal_clicked().connect(sigc::mem_fun(*this,&ph1dReactor::propertiesShow));

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
                    
                   //Length
                    recapLengthLabel_.set_text("Length");
                    recapGrid_.attach(recapLengthLabel_,0,0,1,1);
                    recapLengthUDLabel_.set_text("m");
                    recapGrid_.attach(recapLengthUDLabel_,2,0,1,1);
                    recapGrid_.attach(recapLengthValueLabel_,1,0,1,1);

                    //Velocity
                    recapVelocityLabel_.set_text("Velocity");
                    recapGrid_.attach(recapVelocityLabel_,0,1,1,1);
                    recapVelocityUDLabel_.set_text("m/s");
                    recapGrid_.attach(recapVelocityUDLabel_,2,1,1,1);
                    recapGrid_.attach(recapVelocityValueLabel_,1,1,1,1);

                    //Temperature
                    recapTemperatureLabel_.set_text("Temperature");
                    recapGrid_.attach(recapTemperatureLabel_,0,2,1,1);
                    recapTemperatureUDLabel_.set_text("K");
                    recapGrid_.attach(recapTemperatureUDLabel_,2,2,1,1);
                    recapGrid_.attach(recapTemperatureValueLabel_,1,2,1,1);

                    //Pressure
                    recapPressureLabel_.set_text("Pressure");
                    recapGrid_.attach(recapPressureLabel_,0,3,1,1);
                    recapPressureUDLabel_.set_text("Pa");
                    recapGrid_.attach(recapPressureUDLabel_,2,3,1,1);
                    recapGrid_.attach(recapPressureValueLabel_,1,3,1,1);

                    //Mole/Mass fraction
                    recapGrid_.attach(recapFractionLabel_,0,4,1,1);
                    recapGrid_.attach(recapFractionNameLabel_,1,4,1,1);
                    recapGrid_.attach(recapFractionValueLabel_,2,4,1,1);

                    //Load
                    recapLoadLabel_.set_text("Catalyst load");
                    recapGrid_.attach(recapLoadLabel_,0,5,1,1);
                    recapLoadUDLabel_.set_text("1/m");
                    recapGrid_.attach(recapLoadUDLabel_,2,5,1,1);
                    recapGrid_.attach(recapLoadValueLabel_,1,5,1,1);

                    //Time
                    recapTimeLabel_.set_text("Integration time");
                    recapGrid_.attach(recapTimeLabel_,0,6,1,1);
                    recapTimeUDLabel_.set_text("s");
                    recapGrid_.attach(recapTimeUDLabel_,2,6,1,1);
                    recapGrid_.attach(recapTimeValueLabel_,1,6,1,1);
                    
                    //Save
                    recapSaveLabel_.set_text("Save solution every");
                    recapGrid_.attach(recapSaveLabel_,0,7,1,1);
                    recapSaveUDLabel_.set_text("s");
                    recapGrid_.attach(recapSaveUDLabel_,2,7,1,1);
                    recapGrid_.attach(recapSaveValueLabel_,1,7,1,1);

                    //Points
                    recapPointsLabel_.set_text("Solving with");
                    recapGrid_.attach(recapPointsLabel_,0,8,1,1);
                    recapPointsUDLabel_.set_text("points");
                    recapGrid_.attach(recapPointsUDLabel_,2,8,1,1);
                    recapGrid_.attach(recapPointsValueLabel_,1,8,1,1);

                    //Inert
                    recapInertLabel_.set_text("Inert species is");
                    recapGrid_.attach(recapInertLabel_,0,9,1,1);
                    recapGrid_.attach(recapInertValueLabel_,1,9,1,1);

                    //Resolution type
                    recapResolutionLabel_.set_text("Solver type");
                    recapGrid_.attach(recapResolutionLabel_,0,10,1,1);
                    recapGrid_.attach(recapResolutionValueLabel_,1,10,1,1);

                    //Energy type
                    recapEnergyLabel_.set_text("Energy balance is");
                    recapGrid_.attach(recapEnergyLabel_,0,11,1,1);
                    recapGrid_.attach(recapEnergyValueLabel_,1,11,1,1);

                    //Kinetic type
                    recapKineticLabel_.set_text("Kinetic model from");
                    recapGrid_.attach(recapKineticLabel_,0,12,1,1);
                    recapGrid_.attach(recapKineticValueLabel_,1,12,1,1);

                    //Buttons
                    recapGrid_.attach(backButton3_,0,13,1,1);
                    backButton3_.signal_clicked().connect(sigc::mem_fun(*this,&ph1dReactor::input));
                    recapGrid_.attach(exitButton4_,2,13,1,1);
                    exitButton4_.signal_clicked().connect(sigc::mem_fun(*this,&ph1dReactor::exit));
                }
            }
        }
    }

    ph1dReactor::~ph1dReactor()
    {
    }

    void ph1dReactor::read()
    {
        L_    = Glib::Ascii::strtod(lengthEntry_.get_text());
        v_    = Glib::Ascii::strtod(velocityEntry_.get_text());
        alfa_ = Glib::Ascii::strtod(loadEntry_.get_text());
        tf_   = Glib::Ascii::strtod(timeEntry_.get_text());
        dt_   = Glib::Ascii::strtod(saveEntry_.get_text());
        NP_   = Glib::Ascii::strtod(pointsEntry_.get_text());

        ConvertsToMeter(L_,lengthCombo_.get_active_text());
        ConvertsToMeterPerSecond(v_,velocityCombo_.get_active_text());
        ConvertsToOneOverMeter(alfa_,loadCombo_.get_active_text());
        ConvertsToSecond(tf_,timeCombo_.get_active_text());
        ConvertsToSecond(dt_,saveCombo_.get_active_text());

        resolution_ = resolutionCombo_.get_active_text();
        energy_     = energyCombo_.get_active_text();
        inert_      = inertEntry_.get_text();
        asaliProperties_->convertToCaption(inert_);
    }

    void ph1dReactor::input()
    {
        {
            signal.disconnect();
            signal = nextButton1_.signal_clicked().connect(sigc::mem_fun(*this,&ph1dReactor::kineticShow));
        }
        this->remove();
        this->add(mainBox_);
        this->resize(mainBox_.get_width(),mainBox_.get_height());
        this->show_all_children();
    }

    void ph1dReactor::clean()
    {
        if ( plotButtonBool_ )
        {
            recapButtonBox_.remove(asaliPlotButton_);
            plotButtonBool_ = false;
        }
    }

    void ph1dReactor::recap()
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

            //Length
            {
                std::ostringstream s;
                s << L_;
                recapLengthValueLabel_.set_text(s.str());
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
            
            //Mole/mass fraction
            {
                recapFractionLabel_.set_text(fractionCombo_.get_active_text());
                {
                    std::string s = n_[0];
                    for (unsigned int i=1;i<n_.size();i++)
                    {
                        s = s + "\n" + n_[i];
                    }
                    recapFractionNameLabel_.set_text(s);
                }
                {
                    std::string s;
                    {
                        std::ostringstream so;
                        so << x_[0];
                        s = so.str();
                    }
                    for (unsigned int i=1;i<x_.size();i++)
                    {
                        std::ostringstream so;
                        so << x_[i];
                        s = s + "\n" + so.str();
                    }
                    recapFractionValueLabel_.set_text(s);
                }
            }

            //Load
            {
                std::ostringstream s;
                s << alfa_;
                recapLoadValueLabel_.set_text(s.str());
            }

            if ( resolution_ == "transient" )
            {
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

            }
            else
            {
                recapTimeValueLabel_.set_text("n/a");
                recapSaveValueLabel_.set_text("n/a");
                recapPointsValueLabel_.set_text("n/a");
                recapInertValueLabel_.set_text("n/a");
            }
            //Resolution
            {
                recapResolutionValueLabel_.set_text(resolution_);
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

    void ph1dReactor::run()
    {
        if ( kineticCombo_.get_active_text() == "CANTERA")
        {
            eq_->setCanteraThermo(thermo_);
            eq_->setCanteraTransport(transport_);
            eq_->setCanteraInterface(surface_);
            eq_->setCanteraKinetics(kinetic_);
            eq_->turnOnUserDefined(false);

            if ( kinetic_->nReactions() != 0. )
            {
                Gtk::MessageDialog smallDialog(*this,"We detect that your CANTERA input file has GAS PHASE reactions.\nDo you wonna enable them?",true,Gtk::MESSAGE_QUESTION,Gtk::BUTTONS_YES_NO);
                smallDialog.set_secondary_text(this->getBeerShort(),true);
                int answer = smallDialog.run();

                //Handle the response:
                switch(answer)
                {
                    case(Gtk::RESPONSE_YES):
                    {
                        eq_->setHomogeneousReactions(true);
                        smallDialog.hide();
                        break;
                    }
                    case(Gtk::RESPONSE_NO):
                    {
                        eq_->setHomogeneousReactions(false);
                        smallDialog.hide();
                        break;
                    }
                    default:
                    {
                        smallDialog.hide();
                        break;
                    }
                }
            }
            else
            {
                eq_->setHomogeneousReactions(false);
            }
        }
        else if ( kineticCombo_.get_active_text() == "ASALI")
        {
            if ( kineticType_ == "none" )
            {
                this->compositionReader();
                this->kineticReader();
                eq_->turnOnUserDefined(true);
                eq_->setAsaliKinetic(pi_,canteraIndex_,n_);
                eq_->set_MW(asaliProperties_->get_MW());
                eq_->set_QfromSurface(asaliProperties_->get_Qhet());
                eq_->set_QfromGas(asaliProperties_->get_Qhom());
                eq_->set_cp(asaliProperties_->get_cp());
                eq_->setHomogeneousReactions(true);
            }
            else
            {
                this->compositionReader();
                this->kineticReader();
                eq_->setCanteraThermo(thermo_);
                eq_->setCanteraTransport(transport_);
                eq_->turnOnUserDefined(false);
                eq_->setAsaliKinetic(pi_,canteraIndex_,n_);
                eq_->setHomogeneousReactions(true);
            }
        }

        if ( resolution_ == "steady state" )
        {
            eq_->setKineticType(kineticCombo_.get_active_text());
            eq_->setResolutionType(resolution_);
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
            eq_->setTemperature(T_);
            eq_->setCatalystLoad(alfa_);

            std::vector<double> x0(eq_->NumberOfEquations());

            if ( kineticType_ == "none" )
            {
                double MWmix = 0;
                if ( fractionCombo_.get_active_row_number() == 0 )
                {
                    std::vector<double> y = asaliProperties_->get_mass_fraction(asaliProperties_->get_MW(),x_);
                    
                    for (unsigned int i=0;i<x_.size();i++)
                    {
                        x0[i] = y[i];
                    }
                    
                    MWmix = asaliProperties_->get_MWmix(asaliProperties_->get_MW(),y);
                }
                else if ( fractionCombo_.get_active_row_number() == 1 )
                {
                    for (unsigned int i=0;i<x_.size();i++)
                    {
                        x0[i] = x_[i];
                    }
                    
                    MWmix = asaliProperties_->get_MWmix(asaliProperties_->get_MW(),x_);
                }
     

                x0[x_.size()] = T_;
                
                eq_->setSpecificMassFlowRate(v_*p_*MWmix/(8314.*T_));
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

                    {
                        std::vector<double> y = canteraInterface_->massFractions();
                        
                        for (unsigned int i=0;i<n_.size();i++)
                        {
                            for (unsigned int j=0;j<canteraInterface_->nSpecies();j++)
                            {
                                if ( n_[i] == canteraInterface_->names()[j] )
                                {
                                    x0[i] = y[j];
                                    break;
                                }
                            }
                        }
                    }

                    x0[x_.size()] = T_;

                    eq_->setSpecificMassFlowRate(v_*canteraInterface_->density());
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

                    {
                        std::vector<double> y = canteraInterface_->massFractions();
                        for (unsigned int i=0;i<thermo_->nSpecies();i++)
                        {
                                x0[i] = y[i];
                        }
                    }

                    {
                        for (unsigned int j=0;j<surface_->nSpecies();j++)
                        {
                            x0[j+thermo_->nSpecies()] = 0.;
                        }

                        for (unsigned int i=0;i<nc_.size();i++)
                        {
                            for (unsigned int j=0;j<surface_->nSpecies();j++)
                            {
                                if ( nc_[i] == surface_->speciesName(j) )
                                {
                                    x0[j+thermo_->nSpecies()] = xc_[i];
                                    break;
                                }
                            }
                        }
                    }

                    x0[thermo_->nSpecies() + surface_->nSpecies()] = T_;
                    
                    eq_->setSpecificMassFlowRate(v_*canteraInterface_->density());
                }
            }

            ASALI::odeInterface<ASALI::ph1dEquations> ode;
            ode.setEquations(eq_);
            ode.start();

            this->bar(0.,"Starting...");
            eq_->store(0.,x0);

            //Start solving
            {
                double  ti    = 0.;
                double  tf    = 0.;
                double  tm    = 0.;
                double  timef = 0.;
                double  time0 = double(std::clock()/CLOCKS_PER_SEC);
                for (unsigned int i=0;i<100;i++)
                {
                    tf = ti + L_/100.;

                    ode.setInitialConditions(ti,x0);
                    ode.solve(tf,x0);

                    eq_->store(tf,x0);
                    
                    timef = double(std::clock()/CLOCKS_PER_SEC);
                    tm    = (timef-time0)*(100.-i+1)/(i+1);

                    ti = tf;

                    this->bar(double(i+1)*(L_/100.)/L_,"Remaning time: " + this->convertToTimeFormat(tm));


                    if (!bar_->check() || !ode.check() )
                    {
                        break;
                    }
                }
            }

            bar_->exit();

            if (bar_->check() == true &&
                ode.check()   == true)
            {
                if ( !plotButtonBool_ )
                {
                    recapButtonBox_.pack_start(asaliPlotButton_, Gtk::PACK_SHRINK);
                    plotButtonBool_ = true;
                    this->show_all_children();
                }
                this->save();
            }
        }
        else
        {
            eq_->setKineticType(kineticCombo_.get_active_text());
            eq_->setResolutionType(resolution_);
            eq_->setNumberOfPoints(NP_);
            eq_->setLength(L_);
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
            eq_->setTemperature(T_);
            eq_->setCatalystLoad(alfa_);

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
                    
                    x0[counter++] = T_;
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
                        
                        x0[counter++] = T_;
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

                        for (unsigned int j=0;j<surface_->nSpecies();j++)
                        {
                            x0[counter++] = thetaInlet[j];
                        }
                        
                        x0[counter++] = T_;
                    }

                    eq_->setSpecificMassFlowRate(v_*canteraInterface_->density());
                    eq_->setInletConditions(xInlet,T_);
                }
            }

            ASALI::odeInterface<ASALI::ph1dEquations> ode;
            ASALI::odeInterface<ASALI::ph1dEquations> bvp;

            ode.setEquations(eq_);
            ode.start();
            eq_->setResolutionType("initial");
            this->bar(0.,"Starting...");
            ode.setInitialConditions(0.,x0);
            ode.solve(1e07,x0);

            bvp.setEquations(eq_);
            bvp.start();
            eq_->setResolutionType(resolution_);
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
                double  timef = 0.;
                double  time0 = double(std::clock()/CLOCKS_PER_SEC);
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


                    if (!bar_->check() || !bvp.check() )
                    {
                        break;
                    }
                }
            }

            bar_->exit();

            if (bar_->check() == true &&
                ode.check()   == true &&
                bvp.check()   == true)
            {
                if ( !plotButtonBool_ )
                {
                    recapButtonBox_.pack_start(asaliPlotButton_, Gtk::PACK_SHRINK);
                    plotButtonBool_ = true;
                    this->show_all_children();
                }
                this->save();
            }
        }
    }

    void ph1dReactor::propertiesShow()
    {
        this->compositionReader();
        this->kineticReader();
        asaliProperties_->destroy();
        asaliProperties_->set_type("ph1d");
        asaliProperties_->set_energy(energy_);
        asaliProperties_->set_n(n_);
        asaliProperties_->set_reactions(pi_->getNumberOfHomReactions(),pi_->getNumberOfHetReactions());
        asaliProperties_->build();
        asaliProperties_->show();

        {
            signal.disconnect();
            signal = nextButton1_.signal_clicked().connect(sigc::mem_fun(*this,&ph1dReactor::recap));
        }
    }
    
    void ph1dReactor::save()
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
                
                if ( resolution_ == "steady state" )
                {
                    output << "Solver type:    " << resolution_ << std::endl;
                    output << "Kinetic type:   " << kineticCombo_.get_active_text() << std::endl;
                    output << "Reactor length: " << L_ << " m" << std::endl;
                    output << "Inlet velocity: " << v_ << " m/s" << std::endl;
                    output << "Pressure:       " << p_ << " Pa" << std::endl;
                    
                    if ( kineticCombo_.get_active_text() == "ASALI" )
                    {
                        std::vector<double>               t = eq_->getLength();
                        std::vector<double>               T = eq_->getTemperature();
                        std::vector<std::vector<double> > y = eq_->getSpecie();

                        output << "Mass fraction" << std::endl;
                        output << "Length [m]" << "\t" << "Temperature [K]" << "\t";
                        for (unsigned int i=0;i<n_.size();i++)
                        {
                            output << n_[i] << "\t";
                        }
                        output << std::endl;
                        
                        for (unsigned int j=0;j<t.size();j++)
                        {
                            output << t[j] << "\t" << T[j] << "\t";
                            for (unsigned int i=0;i<(n_.size());i++)
                            {
                                output << y[j][i] << "\t";
                            }
                            output << std::endl;
                        }
                        output << std::endl;
                        
                        output << "Mole fraction" << std::endl;
                        output << "Length [m]" << "\t" << "Temperature [K]" << "\t";
                        for (unsigned int i=0;i<n_.size();i++)
                        {
                            output << n_[i] << "\t";
                        }
                        output << std::endl;
                        
                        for (unsigned int j=0;j<t.size();j++)
                        {
                            output << t[j] << "\t" << T[j] << "\t";

                            std::vector<double> mole(n_.size());
                            if ( kineticType_ == "none" )
                            {
                                mole = asaliProperties_->get_mole_fraction(asaliProperties_->get_MW(),y[j]);
                            }
                            else
                            {
                                canteraInterface_->setTemperature(T[j]);
                                canteraInterface_->setPressure(p_);
                                canteraInterface_->setMassFraction(y[j],n_);

                                for (unsigned int i=0;i<n_.size();i++)
                                {
                                    for (unsigned int k=0;k<canteraInterface_->names().size();k++)
                                    {
                                        if ( n_[i] == canteraInterface_->names()[k] )
                                        {
                                            mole[i] = canteraInterface_->moleFractions()[k];
                                            break;
                                        }
                                    }
                                }
                            }
                        
                            for (unsigned int i=0;i<(n_.size());i++)
                            {
                                output << mole[i] << "\t";
                            }
                            output << std::endl;
                        }
                        output << std::endl;
                    }
                    else if ( kineticCombo_.get_active_text() == "CANTERA" )
                    {
                        std::vector<double>               t = eq_->getLength();
                        std::vector<double>               T = eq_->getTemperature();
                        std::vector<std::vector<double> > y = eq_->getSpecie();
                        std::vector<std::vector<double> > Z = eq_->getSite();
                        std::vector<std::string>          name(thermo_->nSpecies());
                        
                        for (unsigned int i=0;i<thermo_->nSpecies();i++)
                        {
                            name[i] = thermo_->speciesName(i);
                        }

                        output << "Mass fraction" << std::endl;
                        output << "Length [m]" << "\t" << "Temperature [K]" << "\t";
                        for (unsigned int i=0;i<thermo_->nSpecies();i++)
                        {
                            output << thermo_->speciesName(i) << "\t";
                        }
                        for (unsigned int i=0;i<surface_->nSpecies();i++)
                        {
                            output << surface_->speciesName(i) << "\t";
                        }
                        output << std::endl;
                        
                        for (unsigned int j=0;j<t.size();j++)
                        {
                            output << t[j] << "\t" << T[j] << "\t";
                            for (unsigned int i=0;i<thermo_->nSpecies();i++)
                            {
                                output << y[j][i] << "\t";
                            }
                            for (unsigned int i=0;i<surface_->nSpecies();i++)
                            {
                                output << Z[j][i] << "\t";
                            }
                            output << std::endl;
                        }
                        output << std::endl;
                        
                        output << "Mole fraction" << std::endl;
                        output << "Lenght [m]" << "\t" << "Temperature [K]" << "\t";
                        for (unsigned int i=0;i<thermo_->nSpecies();i++)
                        {
                            output << thermo_->speciesName(i) << "\t";
                        }
                        for (unsigned int i=0;i<surface_->nSpecies();i++)
                        {
                            output << surface_->speciesName(i) << "\t";
                        }
                        output << std::endl;
                        
                        for (unsigned int j=0;j<t.size();j++)
                        {
                            output << t[j] << "\t" << T[j] << "\t";

                            std::vector<double> mole(thermo_->nSpecies());
                            {
                                canteraInterface_->setTemperature(T[j]);
                                canteraInterface_->setPressure(p_);
                                canteraInterface_->setMassFraction(y[j],name);
                                mole = canteraInterface_->moleFractions();
                            }
                        
                            for (unsigned int i=0;i<thermo_->nSpecies();i++)
                            {
                                output << mole[i] << "\t";
                            }
                            for (unsigned int i=0;i<surface_->nSpecies();i++)
                            {
                                output << Z[j][i] << "\t";
                            }
                            output << std::endl;
                        }
                        output << std::endl;
                    }
                }
                else if ( resolution_ == "transient" )
                {
                    output << "Solver type:      " << resolution_ << std::endl;
                    output << "Kinetic type:     " << kineticCombo_.get_active_text() << std::endl;
                    output << "Reactor length:   " << L_ << " m" << std::endl;
                    output << "Inlet velocity:   " << v_ << " m/s" << std::endl;
                    output << "Pressure:         " << p_ << " Pa" << std::endl;
                    output << "Integration time: " << tf_ << " s" << std::endl;

                    std::vector<double>                             t  = eq_->getTime();
                    std::vector<std::vector<double> >               T  = eq_->getTemperatureTransient();
                    std::vector<std::vector<std::vector<double> > > y  = eq_->getSpecieTransient();
                    std::vector<std::vector<std::vector<double> > > Z  = eq_->getSiteTransient();
                    double                                          dz = L_/double(NP_- 1);

                    if ( kineticCombo_.get_active_text() == "ASALI" )
                    {
                        //Conversion from mass to mole
                        std::vector<std::vector<std::vector<double> > > mole  = eq_->getSpecieTransient();
                        {
                            if ( kineticType_ == "none" )
                            {
                                for (unsigned int j=0;j<t.size();j++)
                                {
                                    for (unsigned int k=0;k<NP_;k++)
                                    {
                                        std::vector<double> x(n_.size());
                                        for (unsigned int i=0;i<n_.size();i++)
                                        {
                                            x[i] = y[j][k][i];
                                        }
                                        
                                        x = asaliProperties_->get_mole_fraction(asaliProperties_->get_MW(),x);

                                        for (unsigned int i=0;i<n_.size();i++)
                                        {
                                            mole[j][k][i] = x[i];
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
                                        canteraInterface_->setTemperature(T[j][k]);
                                        canteraInterface_->setPressure(p_);
                                        std::vector<double> x(n_.size());
                                        for (unsigned int i=0;i<n_.size();i++)
                                        {
                                            x[i] = y[j][k][i];
                                        }
                                        canteraInterface_->setMassFraction(x,n_);
                                        x = canteraInterface_->moleFractions();

                                        for (unsigned int i=0;i<n_.size();i++)
                                        {
                                            mole[j][k][i] = x[i];
                                        }
                                    }
                                }
                            }
                        }

                        for (unsigned int i=0;i<n_.size();i++)
                        {
                            output << "\nSpecie:           " << n_[i] << std::endl;

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
                                    output << y[j][k][i] << "\t";
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
                                    output << mole[j][k][i] << "\t";
                                }
                                output << std::endl;
                            }
                            output << std::endl;
                        }

                        output << "Temperature [K]" << std::endl;
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
                                output << T[j][k] << "\t";
                            }
                            output << std::endl;
                        }
                        output << std::endl;
                    }
                    else if ( kineticCombo_.get_active_text() == "CANTERA" )
                    {
                        //Conversion from mass to mole
                        std::vector<std::vector<std::vector<double> > > mole  = eq_->getSpecieTransient();
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
                                    canteraInterface_->setTemperature(T[j][k]);
                                    canteraInterface_->setPressure(p_);
                                    std::vector<double> x(thermo_->nSpecies());
                                    for (unsigned int i=0;i<thermo_->nSpecies();i++)
                                    {
                                        x[i] = y[j][k][i];
                                    }
                                    canteraInterface_->setMassFraction(x,n);
                                    x = canteraInterface_->moleFractions();

                                    for (unsigned int i=0;i<thermo_->nSpecies();i++)
                                    {
                                        mole[j][k][i] = x[i];
                                    }
                                }
                            }
                        }

                        for (unsigned int i=0;i<thermo_->nSpecies();i++)
                        {
                            std::string name = thermo_->speciesName(i);
                            output << "\nSpecie:           " << name << std::endl;

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
                                    output << y[j][k][i] << "\t";
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
                                    output << mole[j][k][i] << "\t";
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

                        output << "Temperature [K]" << std::endl;
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
                                output << T[j][k] << "\t";
                            }
                            output << std::endl;
                        }
                        output << std::endl;
                    }
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

    void ph1dReactor::plot()
    {
        if (!asaliPlot_)
        {
            delete asaliPlot_;
        }

        asaliPlot_ = new ASALI::asaliPlot();

        if ( resolution_ == "steady state" )
        {
            asaliPlot_->setResolutionType(resolution_);
            asaliPlot_->setLength(eq_->getLength(),lengthCombo_.get_active_text());
            asaliPlot_->setTemperature(eq_->getTemperature());

            if ( kineticCombo_.get_active_text() == "ASALI" )
            {
                std::vector<double>               L = eq_->getLength();
                std::vector<double>               T = eq_->getTemperature();
                std::vector<std::vector<double> > x = eq_->getSpecie();
                std::vector<std::vector<double> > y = eq_->getSpecie();
                
                for (unsigned int j=0;j<L.size();j++)
                {
                    std::vector<double> mole(n_.size());
                    if ( kineticType_ == "none" )
                    {
                        mole = asaliProperties_->get_mole_fraction(asaliProperties_->get_MW(),y[j]);
                    }
                    else
                    {
                        canteraInterface_->setTemperature(T[j]);
                        canteraInterface_->setPressure(p_);
                        canteraInterface_->setMassFraction(y[j],n_);

                        for (unsigned int i=0;i<n_.size();i++)
                        {
                            for (unsigned int k=0;k<canteraInterface_->names().size();k++)
                            {
                                if ( n_[i] == canteraInterface_->names()[k] )
                                {
                                    mole[i] = canteraInterface_->moleFractions()[k];
                                    break;
                                }
                            }
                        }
                    }
                
                    for (unsigned int i=0;i<(n_.size());i++)
                    {
                        x[j][i] = mole[i];
                    }
                }
                asaliPlot_->setSpecieNames(n_);
                asaliPlot_->setSpecie(y,x);
            }
            else if ( kineticCombo_.get_active_text() == "CANTERA" )
            {
                std::vector<double>               L = eq_->getLength();
                std::vector<double>               T = eq_->getTemperature();
                std::vector<std::vector<double> > y = eq_->getSpecie();
                std::vector<std::vector<double> > x = eq_->getSpecie();

                std::vector<std::string>          name(thermo_->nSpecies());
                
                for (unsigned int i=0;i<thermo_->nSpecies();i++)
                {
                    name[i] = thermo_->speciesName(i);
                }

                for (unsigned int j=0;j<L.size();j++)
                {
                    std::vector<double> mole(thermo_->nSpecies());
                    {
                        canteraInterface_->setTemperature(T[j]);
                        canteraInterface_->setPressure(p_);
                        canteraInterface_->setMassFraction(y[j],name);
                        mole = canteraInterface_->moleFractions();
                    }
                    for (unsigned int i=0;i<thermo_->nSpecies();i++)
                    {
                        x[j][i] = mole[i];
                    }
                }

                asaliPlot_->setSpecieNames(name);
                asaliPlot_->setSpecie(y,x);

                name.resize(surface_->nSpecies());
                for (unsigned int i=0;i<surface_->nSpecies();i++)
                {
                    name[i] = surface_->speciesName(i);
                }
                
                asaliPlot_->setSiteNames(name);
                asaliPlot_->setSite(eq_->getSite());
            }
        }
        else if ( resolution_ == "transient" )
        {
            asaliPlot_->setResolutionType(resolution_);
            asaliPlot_->setTime(eq_->getTime());
            asaliPlot_->setTemperature(eq_->getTemperatureTransient());

            if ( kineticCombo_.get_active_text() == "ASALI" )
            {
                std::vector<double>                             t  = eq_->getTime();
                std::vector<std::vector<double> >               T  = eq_->getTemperatureTransient();
                std::vector<std::vector<std::vector<double> > > y  = eq_->getSpecieTransient();
                std::vector<std::vector<std::vector<double> > > Z  = eq_->getSiteTransient();

                //Conversion from mass to mole
                std::vector<std::vector<std::vector<double> > > mole  = eq_->getSpecieTransient();
                {
                    if ( kineticType_ == "none" )
                    {
                        for (unsigned int j=0;j<t.size();j++)
                        {
                            for (unsigned int k=0;k<NP_;k++)
                            {
                                std::vector<double> x(n_.size());
                                for (unsigned int i=0;i<n_.size();i++)
                                {
                                    x[i] = y[j][k][i];
                                }
                                
                                x = asaliProperties_->get_mole_fraction(asaliProperties_->get_MW(),x);

                                for (unsigned int i=0;i<n_.size();i++)
                                {
                                    mole[j][k][i] = x[i];
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
                                canteraInterface_->setTemperature(T[j][k]);
                                canteraInterface_->setPressure(p_);
                                std::vector<double> x(n_.size());
                                for (unsigned int i=0;i<n_.size();i++)
                                {
                                    x[i] = y[j][k][i];
                                }
                                canteraInterface_->setMassFraction(x,n_);
                                x = canteraInterface_->moleFractions();

                                for (unsigned int i=0;i<n_.size();i++)
                                {
                                    mole[j][k][i] = x[i];
                                }
                            }
                        }
                    }
                }

                asaliPlot_->setSpecieNames(n_);
                asaliPlot_->setSpecie(y,mole);
            }
            else if ( kineticCombo_.get_active_text() == "CANTERA" )
            {
                std::vector<double>                             t  = eq_->getTime();
                std::vector<std::vector<double> >               T  = eq_->getTemperatureTransient();
                std::vector<std::vector<std::vector<double> > > y  = eq_->getSpecieTransient();
                std::vector<std::vector<std::vector<double> > > Z  = eq_->getSiteTransient();
                
                //Conversion from mass to mole
                std::vector<std::vector<std::vector<double> > > mole  = eq_->getSpecieTransient();
                std::vector<std::string> name(thermo_->nSpecies());
                {

                    for (unsigned int i=0;i<thermo_->nSpecies();i++)
                    {
                        name[i] = thermo_->speciesName(i);
                    }
                    for (unsigned int j=0;j<t.size();j++)
                    {
                        for (unsigned int k=0;k<NP_;k++)
                        {
                            canteraInterface_->setTemperature(T[j][k]);
                            canteraInterface_->setPressure(p_);
                            std::vector<double> x(thermo_->nSpecies());
                            for (unsigned int i=0;i<thermo_->nSpecies();i++)
                            {
                                x[i] = y[j][k][i];
                            }
                            canteraInterface_->setMassFraction(x,name);
                            x = canteraInterface_->moleFractions();

                            for (unsigned int i=0;i<thermo_->nSpecies();i++)
                            {
                                mole[j][k][i] = x[i];
                            }
                        }
                    }

                }
                asaliPlot_->setSpecieNames(name);
                asaliPlot_->setSpecie(y,mole);

                name.resize(surface_->nSpecies());
                for (unsigned int i=0;i<surface_->nSpecies();i++)
                {
                    name[i] = surface_->speciesName(i);
                }
                asaliPlot_->setSiteNames(name);
                asaliPlot_->setSite(eq_->getSiteTransient());
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
        }

        asaliPlot_->setType("ph1d");
        asaliPlot_->build();
        asaliPlot_->show();
    }

}
