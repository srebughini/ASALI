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

void Asali::ph1dRecap()
{
    this->inputReader();
    this->coverageReader();
    if ( checkInput_.second == false )
    {
        this->checkInput(checkInput_.first);
    }
    else if ( checkCoverage_.second == false )
    {
        this->checkCoverage(checkCoverage_.first);
    }
    else
    {
        this->ph1dReader();
        this->kineticReader();
        this->propertiesShow();

        //Clean the window
        this->remove();
        this->set_title("ASALI: 1D PH reactors");
        this->add(ph1dRecapMainBox_);

        //Length
        {
            std::ostringstream s;
            s << L_;
            ph1dRecapLengthValueLabel_.set_text(s.str());
        }

        //Velocity
        {
            std::ostringstream s;
            s << v_;
            ph1dRecapVelocityValueLabel_.set_text(s.str());
        }

        //Temperature
        {
            std::ostringstream s;
            s << T_;
            ph1dRecapTemperatureValueLabel_.set_text(s.str());
        }
        
        //Pressure
        {
            std::ostringstream s;
            s << p_;
            ph1dRecapPressureValueLabel_.set_text(s.str());
        }
        
        //Mole/mass fraction
        {
            ph1dRecapFractionLabel_.set_text(fractionCombo_.get_active_text());
            {
                std::string s = n_[0];
                for (unsigned int i=1;i<n_.size();i++)
                {
                    s = s + "\n" + n_[i];
                }
                ph1dRecapFractionNameLabel_.set_text(s);
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
                ph1dRecapFractionValueLabel_.set_text(s);
            }
        }

        //Load
        {
            std::ostringstream s;
            s << alfa_;
            ph1dRecapLoadValueLabel_.set_text(s.str());
        }

        if ( resolution_ == "transient" )
        {
            //Time
            {
                std::ostringstream s;
                s << tf_;
                ph1dRecapTimeValueLabel_.set_text(s.str());
            }

            //Save
            {
                std::ostringstream s;
                s << dt_;
                ph1dRecapSaveValueLabel_.set_text(s.str());
            }

            //Points
            {
                std::ostringstream s;
                s << NP_;
                ph1dRecapPointsValueLabel_.set_text(s.str());
            }

            //Inert
            {
                ph1dRecapInertValueLabel_.set_text(inert_);
            }

        }
        else
        {
            ph1dRecapTimeValueLabel_.set_text("n/a");
            ph1dRecapSaveValueLabel_.set_text("n/a");
            ph1dRecapPointsValueLabel_.set_text("n/a");
            ph1dRecapInertValueLabel_.set_text("n/a");
        }
        //Resolution
        {
            ph1dRecapResolutionValueLabel_.set_text(resolution_);
        }
        
        //Kinetic
        {
            ph1dRecapKineticValueLabel_.set_text(kineticTypeCombo_.get_active_text());
        }

        {
            ph1dRecapEnergyValueLabel_.set_text(energy_);
        }

        //Buttons
        if (ph1dBool_)
        {
            if ( kineticTypeOld_ == "none" )
            {
                ph1dButtonBox_.remove(ph1dAsaliKineticButton_);
                ph1dButtonBox_.remove(ph1dAsaliPropertiesButton_);
            }
            else if ( kineticTypeOld_ == "default" )
            {
                ph1dButtonBox_.remove(ph1dAsaliKineticButton_);
            }
            
            if ( kineticType_ == "none" )
            {
                ph1dButtonBox_.pack_start(ph1dAsaliKineticButton_, Gtk::PACK_SHRINK);
                ph1dButtonBox_.pack_start(ph1dAsaliPropertiesButton_, Gtk::PACK_SHRINK);
                kineticTypeOld_ = kineticType_;
            }
            else if ( kineticType_ == "default" )
            {
                ph1dButtonBox_.pack_start(ph1dAsaliKineticButton_, Gtk::PACK_SHRINK);
                kineticTypeOld_ = kineticType_;
            }
            else if ( kineticType_ == "load" )
            {
                if ( kineticTypeCombo_.get_active_row_number() == 1 )
                {
                    ph1dButtonBox_.pack_start(ph1dAsaliKineticButton_, Gtk::PACK_SHRINK);
                    kineticTypeOld_ = "default";
                }
                else
                {
                    kineticTypeOld_ = kineticType_;
                }
            }
        }
        else
        {
            if ( kineticType_ == "none" )
            {
                ph1dButtonBox_.pack_start(ph1dAsaliKineticButton_, Gtk::PACK_SHRINK);
                ph1dButtonBox_.pack_start(ph1dAsaliPropertiesButton_, Gtk::PACK_SHRINK);
                kineticTypeOld_ = kineticType_;
            }
            else if ( kineticType_ == "default" )
            {
                ph1dButtonBox_.pack_start(ph1dAsaliKineticButton_, Gtk::PACK_SHRINK);
                kineticTypeOld_ = kineticType_;
            }
            else if ( kineticType_ == "load" )
            {
                if ( kineticTypeCombo_.get_active_row_number() == 1 )
                {
                    ph1dButtonBox_.pack_start(ph1dAsaliKineticButton_, Gtk::PACK_SHRINK);
                    kineticTypeOld_ = "default";
                }
                else
                {
                    kineticTypeOld_ = kineticType_;
                }
            }
            ph1dBool_ = true;
        }


        this->resize(ph1dRecapMainBox_.get_width(),ph1dRecapMainBox_.get_height ());
        this->show_all_children();
    }
}

void Asali::ph1dMenu()
{
    //Clean the window
    this->remove();
    this->set_title("ASALI: 1D PH reactors");
    
    //Add thermo menu grid
    this->add(inputGrid_);
    
    if ( window_ == "transport" )
    {
        this->cleanTransport();
        inputGrid_.remove(doneTransportButton_);
        inputGrid_.remove(*backButton_[0]);
        if ( kineticType_ == "default" )
        {
            inputGrid_.remove(helpButton_);
        }
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[17],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[17],1,13,1,1);
            inputGrid_.attach(*nextButton_[17],2,13,1,1);
            window_ = "ph1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[16],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[16],1,13,1,1);
            inputGrid_.attach(*nextButton_[16],2,13,1,1);
            window_ = "ph1dMenuAsali";
        }
    }
    else if ( window_ == "thermo" )
    {
        this->cleanThermo();
        inputGrid_.remove(doneThermoButton_);
        inputGrid_.remove(*backButton_[0]);
        if ( kineticType_ == "default" )
        {
            inputGrid_.remove(helpButton_);
        }
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[17],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[17],1,13,1,1);
            inputGrid_.attach(*nextButton_[17],2,13,1,1);
            window_ = "ph1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[16],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[16],1,13,1,1);
            inputGrid_.attach(*nextButton_[16],2,13,1,1);
            window_ = "ph1dMenuAsali";
        }
    }
    else if ( window_ == "all" )
    {
        this->cleanAll();
        inputGrid_.remove(doneAllButton_);
        inputGrid_.remove(*backButton_[0]);
        if ( kineticType_ == "default" )
        {
            inputGrid_.remove(helpButton_);
        }
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[17],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[17],1,13,1,1);
            inputGrid_.attach(*nextButton_[17],2,13,1,1);
            window_ = "ph1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[16],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[16],1,13,1,1);
            inputGrid_.attach(*nextButton_[16],2,13,1,1);
            window_ = "ph1dMenuAsali";
        }
    }
    else if ( window_ == "transportMenu" )
    {
        inputGrid_.remove(doneTransportButton_);
        inputGrid_.remove(*backButton_[0]);
        if ( kineticType_ == "default" )
        {
            inputGrid_.remove(helpButton_);
        }
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[17],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[17],1,13,1,1);
            inputGrid_.attach(*nextButton_[17],2,13,1,1);
            window_ = "ph1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[16],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[16],1,13,1,1);
            inputGrid_.attach(*nextButton_[16],2,13,1,1);
            window_ = "ph1dMenuAsali";
        }
    }
    else if ( window_ == "allMenu" )
    {
        inputGrid_.remove(doneAllButton_);
        inputGrid_.remove(*backButton_[0]);
        if ( kineticType_ == "default" )
        {
            inputGrid_.remove(helpButton_);
        }
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[17],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[17],1,13,1,1);
            inputGrid_.attach(*nextButton_[17],2,13,1,1);
            window_ = "ph1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[16],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[16],1,13,1,1);
            inputGrid_.attach(*nextButton_[16],2,13,1,1);
            window_ = "ph1dMenuAsali";
        }
    }
    else if ( window_ == "thermoMenu" )
    {
        inputGrid_.remove(doneThermoButton_);
        inputGrid_.remove(*backButton_[0]);
        if ( kineticType_ == "default" )
        {
            inputGrid_.remove(helpButton_);
        }
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[17],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[17],1,13,1,1);
            inputGrid_.attach(*nextButton_[17],2,13,1,1);
            window_ = "ph1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[16],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[16],1,13,1,1);
            inputGrid_.attach(*nextButton_[16],2,13,1,1);
            window_ = "ph1dMenuAsali";
        }
    }
    else if ( window_ == "equilibriumMenu" )
    {
        inputGrid_.remove(*nextButton_[2]);
        inputGrid_.remove(*backButton_[0]);
        if ( kineticType_ == "default" )
        {
            inputGrid_.remove(helpButton_);
        }
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[17],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[17],1,13,1,1);
            inputGrid_.attach(*nextButton_[17],2,13,1,1);
            window_ = "ph1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[16],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[16],1,13,1,1);
            inputGrid_.attach(*nextButton_[16],2,13,1,1);
            window_ = "ph1dMenuAsali";
        }
    }
    else if ( window_ == "equilibrium" )
    {
        equilibriumGrid_.remove(*backButton_[8]);
        equilibriumGrid_.remove(*exitButton_[8]);
        equilibriumGrid_.remove(equilibriumSaveButton_);
        inputGrid_.remove(*nextButton_[2]);
        inputGrid_.remove(*backButton_[0]);
        if ( kineticType_ == "default" )
        {
            inputGrid_.remove(helpButton_);
        }
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[17],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[17],1,13,1,1);
            inputGrid_.attach(*nextButton_[17],2,13,1,1);
            window_ = "ph1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[16],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[16],1,13,1,1);
            inputGrid_.attach(*nextButton_[16],2,13,1,1);
            window_ = "ph1dMenuAsali";
        }
    }
    else if ( window_ == "ph1dMenuCantera" )
    {
        inputGrid_.remove(*backButton_[17]);
        inputGrid_.remove(*mainMenuButton_[17]);
        inputGrid_.remove(*nextButton_[17]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[17],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[17],1,13,1,1);
            inputGrid_.attach(*nextButton_[17],2,13,1,1);
            window_ = "ph1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[16],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[16],1,13,1,1);
            inputGrid_.attach(*nextButton_[16],2,13,1,1);
            window_ = "ph1dMenuAsali";
        }
    }
    else if ( window_ == "ph1dMenuAsali" )
    {
        inputGrid_.remove(*backButton_[16]);
        inputGrid_.remove(*mainMenuButton_[16]);
        inputGrid_.remove(*nextButton_[16]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[17],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[17],1,13,1,1);
            inputGrid_.attach(*nextButton_[17],2,13,1,1);
            window_ = "ph1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[16],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[16],1,13,1,1);
            inputGrid_.attach(*nextButton_[16],2,13,1,1);
            window_ = "ph1dMenuAsali";
        }
    }
    else if ( window_ == "batchMenuCantera" )
    {
        inputGrid_.remove(*backButton_[13]);
        inputGrid_.remove(*mainMenuButton_[13]);
        inputGrid_.remove(*nextButton_[13]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[17],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[17],1,13,1,1);
            inputGrid_.attach(*nextButton_[17],2,13,1,1);
            window_ = "ph1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[16],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[16],1,13,1,1);
            inputGrid_.attach(*nextButton_[16],2,13,1,1);
            window_ = "ph1dMenuAsali";
        }
    }
    else if ( window_ == "batchMenuAsali" )
    {
        inputGrid_.remove(*backButton_[11]);
        inputGrid_.remove(*mainMenuButton_[11]);
        inputGrid_.remove(*nextButton_[11]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[17],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[17],1,13,1,1);
            inputGrid_.attach(*nextButton_[17],2,13,1,1);
            window_ = "ph1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[16],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[16],1,13,1,1);
            inputGrid_.attach(*nextButton_[16],2,13,1,1);
            window_ = "ph1dMenuAsali";
        }
    }
    else
    {
        inputGrid_.remove(*backButton_[0]);
        if ( kineticType_ == "default" )
        {
            inputGrid_.remove(helpButton_);
        }
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[17],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[17],1,13,1,1);
            inputGrid_.attach(*nextButton_[17],2,13,1,1);
            window_ = "ph1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[16],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[16],1,13,1,1);
            inputGrid_.attach(*nextButton_[16],2,13,1,1);
            window_ = "ph1dMenuAsali";
        }
    }

    //Resize
    this->resize(inputGrid_.get_width(),inputGrid_.get_height ());
    this->show_all_children();
}

void Asali::ph1dSave()
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
                output << "Kinetic type:   " << kineticTypeCombo_.get_active_text() << std::endl;
                output << "Reactor length: " << L_ << " m" << std::endl;
                output << "Inlet velocity: " << v_ << " m/s" << std::endl;
                output << "Pressure:       " << p_ << " Pa" << std::endl;
                
                if ( kineticTypeCombo_.get_active_text() == "ASALI" )
                {
                    std::vector<double>               t = ph1d_->getLength();
                    std::vector<double>               T = ph1d_->getTemperature();
                    std::vector<std::vector<double> > y = ph1d_->getSpecie();

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
                else if ( kineticTypeCombo_.get_active_text() == "CANTERA" )
                {
                    std::vector<double>               t = ph1d_->getLength();
                    std::vector<double>               T = ph1d_->getTemperature();
                    std::vector<std::vector<double> > y = ph1d_->getSpecie();
                    std::vector<std::vector<double> > Z = ph1d_->getSite();
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
                output << "Kinetic type:     " << kineticTypeCombo_.get_active_text() << std::endl;
                output << "Reactor length:   " << L_ << " m" << std::endl;
                output << "Inlet velocity:   " << v_ << " m/s" << std::endl;
                output << "Pressure:         " << p_ << " Pa" << std::endl;
                output << "Integration time: " << tf_ << " s" << std::endl;

                std::vector<double>                             t  = ph1d_->getTime();
                std::vector<std::vector<double> >               T  = ph1d_->getTemperatureTransient();
                std::vector<std::vector<std::vector<double> > > y  = ph1d_->getSpecieTransient();
                std::vector<std::vector<std::vector<double> > > Z  = ph1d_->getSiteTransient();
                double                                          dz = L_/double(NP_- 1);

                if ( kineticTypeCombo_.get_active_text() == "ASALI" )
                {
                    //Conversion from mass to mole
                    std::vector<std::vector<std::vector<double> > > mole  = ph1d_->getSpecieTransient();
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
                else if ( kineticTypeCombo_.get_active_text() == "CANTERA" )
                {
                    //Conversion from mass to mole
                    std::vector<std::vector<std::vector<double> > > mole  = ph1d_->getSpecieTransient();
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

void Asali::ph1dRun()
{
    if ( resolution_ == "steady state" )
    {
        if ( kineticTypeCombo_.get_active_row_number() == 0)
        {
            ph1d_->setCanteraThermo(thermo_);
            ph1d_->setCanteraTransport(transport_);
            ph1d_->setCanteraInterface(surface_);
            ph1d_->setCanteraKinetics(kinetic_);
            ph1d_->turnOnUserDefined(false);
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1)
        {
            if ( kineticType_ == "none" )
            {
                ph1d_->turnOnUserDefined(true);
                ph1d_->setAsaliKinetic(asaliKinetic_->get_NR(),
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
                ph1d_->set_MW(asaliProperties_->get_MW());
                ph1d_->set_QfromSurface(asaliProperties_->get_Q());
                ph1d_->set_cp(asaliProperties_->get_cp());
                ph1d_->set_cond(asaliProperties_->get_cond());
                ph1d_->set_diff(asaliProperties_->get_diff());
            }
            else
            {
                ph1d_->setCanteraThermo(thermo_);
                ph1d_->setCanteraTransport(transport_);
                ph1d_->turnOnUserDefined(false);
                ph1d_->setAsaliKinetic(asaliKinetic_->get_NR(),
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
            }
        }

        ph1d_->setKineticType(kineticTypeCombo_.get_active_text());
        ph1d_->setResolutionType(resolution_);
        ph1d_->resize();
        ph1d_->setHomogeneusReactions(false);
        ph1d_->setHeterogeneusReactions(true);
        
        if ( energy_ == "on" )
        {
            ph1d_->setEnergy(true);
        }
        else if ( energy_ == "off" )
        {
            ph1d_->setEnergy(false);
        }
        
        ph1d_->setPressure(p_);
        ph1d_->setTemperature(T_);
        ph1d_->setCatalystLoad(alfa_);

        ASALI::Ph1DodeInterface solver;
        
        solver.setEquations(ph1d_);

        std::vector<double> x0(ph1d_->NumberOfEquations());

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
            
            ph1d_->setSpecificMassFlowRate(v_*p_*MWmix/(8314.*T_));
        }
        else
        {
            if ( kineticTypeCombo_.get_active_text() == "ASALI" )
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

                ph1d_->setSpecificMassFlowRate(v_*canteraInterface_->density());
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
                
                ph1d_->setSpecificMassFlowRate(v_*canteraInterface_->density());
            }

        }
        yF_.resize(ph1d_->NumberOfEquations());
        
        this->ph1dBar(0.);
        //Start solving
        {
            double ti = 0.;
            double tf = 0.;
            ph1d_->store(0.,x0);
            for (unsigned int i=0;i<100;i++)
            {
                tf = ti + L_/100.;

                solver.setInitialConditions(ti,x0);
                solver.solve(tf,x0);
                
                ph1d_->store(tf,x0);

                ti = tf;

                this->ph1dBar(double(i+1)*(L_/100.)/L_);
            }
        }

        ph1dBar_->exit();
    }
    else if ( resolution_ == "transient" )
    {
        if ( kineticTypeCombo_.get_active_row_number() == 0)
        {
            ph1d_->setCanteraThermo(thermo_);
            ph1d_->setCanteraTransport(transport_);
            ph1d_->setCanteraInterface(surface_);
            ph1d_->setCanteraKinetics(kinetic_);
            ph1d_->turnOnUserDefined(false);
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1)
        {
            if ( kineticType_ == "none" )
            {
                ph1d_->turnOnUserDefined(true);
                ph1d_->setAsaliKinetic(asaliKinetic_->get_NR(),
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
                ph1d_->set_MW(asaliProperties_->get_MW());
                ph1d_->set_QfromSurface(asaliProperties_->get_Q());
                ph1d_->set_cp(asaliProperties_->get_cp());
                ph1d_->set_cond(asaliProperties_->get_cond());
                ph1d_->set_diff(asaliProperties_->get_diff());
            }
            else
            {
                ph1d_->setCanteraThermo(thermo_);
                ph1d_->setCanteraTransport(transport_);
                ph1d_->turnOnUserDefined(false);
                ph1d_->setAsaliKinetic(asaliKinetic_->get_NR(),
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
            }
        }

        ph1d_->setKineticType(kineticTypeCombo_.get_active_text());
        ph1d_->setResolutionType(resolution_);
        ph1d_->setNumberOfPoints(NP_);
        ph1d_->setLength(L_);
        ph1d_->resize();
        ph1d_->setHomogeneusReactions(false);
        ph1d_->setHeterogeneusReactions(true);
        
        if ( energy_ == "on" )
        {
            ph1d_->setEnergy(true);
        }
        else if ( energy_ == "off" )
        {
            ph1d_->setEnergy(false);
        }
        
        ph1d_->setPressure(p_);
        ph1d_->setTemperature(T_);
        ph1d_->setCatalystLoad(alfa_);

        std::vector<double> x0(ph1d_->NumberOfEquations());

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

            ph1d_->setSpecificMassFlowRate(v_*p_*MWmix/(8314.*T_));
            ph1d_->setInletConditions(xInlet,T_);
        }
        else
        {
            if ( kineticTypeCombo_.get_active_text() == "ASALI" )
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
                    if ( canteraInterface_->names()[i] == inert_ )
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

                ph1d_->setSpecificMassFlowRate(v_*canteraInterface_->density());
                ph1d_->setInletConditions(xInlet,T_);
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
                            
                            std::cout << thetaInlet[j] << std::endl;
                            
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

                ph1d_->setSpecificMassFlowRate(v_*canteraInterface_->density());
                ph1d_->setInletConditions(xInlet,T_);
            }

        }

        yF_.resize(ph1d_->NumberOfEquations());

        ASALI::Ph1DodeInterface ode;
        ode.setEquations(ph1d_);

        ph1d_->setResolutionType("initial");
        this->ph1dBar(0.);
            
        for (unsigned int i=0;i<2;i++)
        {
            //Update solving bar
            if ( i == 0 )
            {
                ode.setInitialConditions(0.,x0);
                ode.solve(1e-07,x0);
                this->ph1dBar(0.);
            }
            else if ( i == 1 )
            {
                ode.setInitialConditions(1e-07,x0);
                ode.solve(1e07,x0);
                this->ph1dBar(1e-05);
            }
        }

        ASALI::Ph1DbvpInterface bvp;
        bvp.setEquations(ph1d_);
        ph1d_->setResolutionType(resolution_);
        ph1d_->store(0.,x0);
        this->ph1dBar(1e-05);

        //Start solving
        {
            double       ti = 0.;
            double       tf = 0.;
            unsigned int Nt = tf_/dt_ + 1;
            for (unsigned int i=0;i<Nt;i++)
            {
                tf = ti + dt_;

                bvp.setInitialConditions(ti,x0);
                bvp.solve(tf,x0);

                ph1d_->store(tf,x0);

                ti = tf;

                this->ph1dBar(double(i+1)*dt_/tf_);
            }
        }

        ph1dBar_->exit();
    }
    this->ph1dSave();
}

void Asali::ph1dBar(const double fraction)
{
    //Update solving bar
    while( Gtk::Main::events_pending() )
    {
        Gtk::Main::iteration();
    }

    ph1dBar_->update(fraction);
    ph1dBar_->show();

    //Update solving bar
    while( Gtk::Main::events_pending() )
    {
        Gtk::Main::iteration();
    }
}

void Asali::ph1dReader()
{
    L_    = Glib::Ascii::strtod(ph1dLengthEntry_.get_text());
    v_    = Glib::Ascii::strtod(ph1dVelocityEntry_.get_text());
    alfa_ = Glib::Ascii::strtod(ph1dLoadEntry_.get_text());
    tf_   = Glib::Ascii::strtod(ph1dTimeEntry_.get_text());
    dt_   = Glib::Ascii::strtod(ph1dSaveEntry_.get_text());
    NP_   = Glib::Ascii::strtod(ph1dPointsEntry_.get_text());

    ConvertsToMeter(L_,ph1dLengthCombo_.get_active_text());
    ConvertsToMeterPerSecond(v_,ph1dVelocityCombo_.get_active_text());
    ConvertsToOneOverMeter(alfa_,ph1dLoadCombo_.get_active_text());
    ConvertsToSecond(tf_,ph1dTimeCombo_.get_active_text());
    ConvertsToSecond(dt_,ph1dSaveCombo_.get_active_text());

    resolution_ = ph1dResolutionCombo_.get_active_text();
    energy_     = ph1dEnergyCombo_.get_active_text();
    inert_      = ph1dInertEntry_.get_text();
    asaliProperties_->convertToCaption(inert_);
}

void Asali::ph1dCoverage()
{
    this->inputReader();
    if ( checkInput_.second == false )
    {
        this->checkInput(checkInput_.first);
    }
    else
    {
        //Clean the window
        this->remove();
        this->set_title("ASALI: 1D PH reactors");
        
        //Add thermo menu grid
        this->add(coverageBox_);
        
        if ( coverage_ == "ph1d" )
        {
            coverageInputGrid_.remove(*backButton_[19]);
            coverageInputGrid_.remove(*nextButton_[19]);
            coverageInputGrid_.attach(*backButton_[19],0,SURF_NS_,1,1);
            coverageInputGrid_.attach(*nextButton_[19],1,SURF_NS_,1,1);
            coverage_ = "ph1d";
        }
        else
        {
            coverageInputGrid_.attach(*backButton_[19],0,SURF_NS_,1,1);
            coverageInputGrid_.attach(*nextButton_[19],1,SURF_NS_,1,1);
            coverage_ = "ph1d";
        }
        
        //Resize
        this->resize(coverageBox_.get_width(),coverageBox_.get_height());

        this->show_all_children();
    }
}

void Asali::ph1dPlot()
{
    if ( resolution_ == "steady state" )
    {
        asaliPlot_->setResolutionType(resolution_);
        asaliPlot_->setLength(ph1d_->getLength());
        asaliPlot_->setTemperature(ph1d_->getTemperature());

        if ( kineticTypeCombo_.get_active_text() == "ASALI" )
        {
            std::vector<double>               L = ph1d_->getLength();
            std::vector<double>               T = ph1d_->getTemperature();
            std::vector<std::vector<double> > x = ph1d_->getSpecie();
            std::vector<std::vector<double> > y = ph1d_->getSpecie();
            
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
        else if ( kineticTypeCombo_.get_active_text() == "CANTERA" )
        {
            std::vector<double>               L = ph1d_->getLength();
            std::vector<double>               T = ph1d_->getTemperature();
            std::vector<std::vector<double> > y = ph1d_->getSpecie();
            std::vector<std::vector<double> > x = ph1d_->getSpecie();

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
            asaliPlot_->setSite(ph1d_->getSite());
        }
    }
    else if ( resolution_ == "transient" )
    {
        asaliPlot_->setResolutionType(resolution_);
        asaliPlot_->setTime(ph1d_->getTime());
        asaliPlot_->setTemperature(ph1d_->getTemperatureTransient());

        if ( kineticTypeCombo_.get_active_text() == "ASALI" )
        {
            std::vector<double>                             t  = ph1d_->getTime();
            std::vector<std::vector<double> >               T  = ph1d_->getTemperatureTransient();
            std::vector<std::vector<std::vector<double> > > y  = ph1d_->getSpecieTransient();
            std::vector<std::vector<std::vector<double> > > Z  = ph1d_->getSiteTransient();

            //Conversion from mass to mole
            std::vector<std::vector<std::vector<double> > > mole  = ph1d_->getSpecieTransient();
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
        else if ( kineticTypeCombo_.get_active_text() == "CANTERA" )
        {
            std::vector<double>                             t  = ph1d_->getTime();
            std::vector<std::vector<double> >               T  = ph1d_->getTemperatureTransient();
            std::vector<std::vector<std::vector<double> > > y  = ph1d_->getSpecieTransient();
            std::vector<std::vector<std::vector<double> > > Z  = ph1d_->getSiteTransient();
            
            //Conversion from mass to mole
            std::vector<std::vector<std::vector<double> > > mole  = ph1d_->getSpecieTransient();
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
            asaliPlot_->setSite(ph1d_->getSiteTransient());
        }
        
        
        //Length
        {
            double dz = L_/double(NP_- 1); 
            std::vector<double> l(NP_);
            for (unsigned int k=0;k<NP_;k++)
            {
                l[k] = k*dz;
            }
            asaliPlot_->setLength(l);
        }
    }

    asaliPlot_->setType("ph1d");
    asaliPlot_->build();
    asaliPlot_->show();
}
