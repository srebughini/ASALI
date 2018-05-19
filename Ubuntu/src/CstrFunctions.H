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

void Asali::cstrRecap()
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
        this->cstrReader();
        this->kineticReader();
        this->propertiesShow();

        //Clean the window
        this->remove();
        this->set_title("ASALI: CST reactors");
        this->add(cstrRecapMainBox_);

        //Volume
        {
            std::ostringstream s;
            s << V_;
            cstrRecapVolumeValueLabel_.set_text(s.str());
        }

        //Flow rate
        {
            std::ostringstream s;
            s << Q_;
            cstrRecapFlowValueLabel_.set_text(s.str());
        }

        //Temperature
        {
            std::ostringstream s;
            s << T_;
            cstrRecapTemperatureValueLabel_.set_text(s.str());
        }
        
        //Pressure
        {
            std::ostringstream s;
            s << p_;
            cstrRecapPressureValueLabel_.set_text(s.str());
        }
        
        //Mole/mass fraction
        {
            cstrRecapFractionLabel_.set_text(fractionCombo_.get_active_text());
            {
                std::string s = n_[0];
                for (unsigned int i=1;i<n_.size();i++)
                {
                    s = s + "\n" + n_[i];
                }
                cstrRecapFractionNameLabel_.set_text(s);
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
                cstrRecapFractionValueLabel_.set_text(s);
            }
        }

        //Load
        {
            std::ostringstream s;
            s << alfa_;
            cstrRecapLoadValueLabel_.set_text(s.str());
        }

        //Time
        {
            std::ostringstream s;
            s << tf_;
            cstrRecapTimeValueLabel_.set_text(s.str());
        }

        //Save
        {
            std::ostringstream s;
            s << dt_;
            cstrRecapSaveValueLabel_.set_text(s.str());
        }

        //Kinetic
        {
            cstrRecapKineticValueLabel_.set_text(kineticTypeCombo_.get_active_text());
        }

        {
            cstrRecapEnergyValueLabel_.set_text(energy_);
        }

        //Buttons
        if (cstrBool_)
        {
            if ( kineticTypeOld_ == "none" )
            {
                cstrButtonBox_.remove(cstrAsaliKineticButton_);
                cstrButtonBox_.remove(cstrAsaliPropertiesButton_);
            }
            else if ( kineticTypeOld_ == "default" )
            {
                cstrButtonBox_.remove(cstrAsaliKineticButton_);
            }
            
            if ( kineticType_ == "none" )
            {
                cstrButtonBox_.pack_start(cstrAsaliKineticButton_, Gtk::PACK_SHRINK);
                cstrButtonBox_.pack_start(cstrAsaliPropertiesButton_, Gtk::PACK_SHRINK);
                kineticTypeOld_ = kineticType_;
            }
            else if ( kineticType_ == "default" )
            {
                cstrButtonBox_.pack_start(cstrAsaliKineticButton_, Gtk::PACK_SHRINK);
                kineticTypeOld_ = kineticType_;
            }
            else if ( kineticType_ == "load" )
            {
                if ( kineticTypeCombo_.get_active_row_number() == 1 )
                {
                    cstrButtonBox_.pack_start(cstrAsaliKineticButton_, Gtk::PACK_SHRINK);
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
                cstrButtonBox_.pack_start(cstrAsaliKineticButton_, Gtk::PACK_SHRINK);
                cstrButtonBox_.pack_start(cstrAsaliPropertiesButton_, Gtk::PACK_SHRINK);
                kineticTypeOld_ = kineticType_;
            }
            else if ( kineticType_ == "default" )
            {
                cstrButtonBox_.pack_start(cstrAsaliKineticButton_, Gtk::PACK_SHRINK);
                kineticTypeOld_ = kineticType_;
            }
            else if ( kineticType_ == "load" )
            {
                if ( kineticTypeCombo_.get_active_row_number() == 1 )
                {
                    cstrButtonBox_.pack_start(cstrAsaliKineticButton_, Gtk::PACK_SHRINK);
                    kineticTypeOld_ = "default";
                }
                else
                {
                    kineticTypeOld_ = kineticType_;
                }
            }
            cstrBool_ = true;
        }

        this->resize(cstrRecapMainBox_.get_width(),cstrRecapMainBox_.get_height ());
        this->show_all_children();
    }
}

void Asali::cstrMenu()
{
    //Clean the window
    this->remove();
    this->set_title("ASALI: CST reactors");
    
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
            inputGrid_.attach(*backButton_[23],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[23],1,13,1,1);
            inputGrid_.attach(*nextButton_[23],2,13,1,1);
            window_ = "cstrMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[22],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[22],1,13,1,1);
            inputGrid_.attach(*nextButton_[22],2,13,1,1);
            window_ = "cstrMenuAsali";
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
            inputGrid_.attach(*backButton_[23],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[23],1,13,1,1);
            inputGrid_.attach(*nextButton_[23],2,13,1,1);
            window_ = "cstrMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[22],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[22],1,13,1,1);
            inputGrid_.attach(*nextButton_[22],2,13,1,1);
            window_ = "cstrMenuAsali";
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
            inputGrid_.attach(*backButton_[23],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[23],1,13,1,1);
            inputGrid_.attach(*nextButton_[23],2,13,1,1);
            window_ = "cstrMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[22],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[22],1,13,1,1);
            inputGrid_.attach(*nextButton_[22],2,13,1,1);
            window_ = "cstrMenuAsali";
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
            inputGrid_.attach(*backButton_[23],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[23],1,13,1,1);
            inputGrid_.attach(*nextButton_[23],2,13,1,1);
            window_ = "cstrMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[22],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[22],1,13,1,1);
            inputGrid_.attach(*nextButton_[22],2,13,1,1);
            window_ = "cstrMenuAsali";
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
            inputGrid_.attach(*backButton_[23],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[23],1,13,1,1);
            inputGrid_.attach(*nextButton_[23],2,13,1,1);
            window_ = "cstrMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[22],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[22],1,13,1,1);
            inputGrid_.attach(*nextButton_[22],2,13,1,1);
            window_ = "cstrMenuAsali";
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
            inputGrid_.attach(*backButton_[23],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[23],1,13,1,1);
            inputGrid_.attach(*nextButton_[23],2,13,1,1);
            window_ = "cstrMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[22],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[22],1,13,1,1);
            inputGrid_.attach(*nextButton_[22],2,13,1,1);
            window_ = "cstrMenuAsali";
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
            inputGrid_.attach(*backButton_[23],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[23],1,13,1,1);
            inputGrid_.attach(*nextButton_[23],2,13,1,1);
            window_ = "cstrMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[22],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[22],1,13,1,1);
            inputGrid_.attach(*nextButton_[22],2,13,1,1);
            window_ = "cstrMenuAsali";
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
            inputGrid_.attach(*backButton_[23],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[23],1,13,1,1);
            inputGrid_.attach(*nextButton_[23],2,13,1,1);
            window_ = "cstrMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[22],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[22],1,13,1,1);
            inputGrid_.attach(*nextButton_[22],2,13,1,1);
            window_ = "cstrMenuAsali";
        }
    }
    else if ( window_ == "batchMenuCantera" )
    {
        inputGrid_.remove(*backButton_[13]);
        inputGrid_.remove(*mainMenuButton_[13]);
        inputGrid_.remove(*nextButton_[13]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[23],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[23],1,13,1,1);
            inputGrid_.attach(*nextButton_[23],2,13,1,1);
            window_ = "cstrMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[22],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[22],1,13,1,1);
            inputGrid_.attach(*nextButton_[22],2,13,1,1);
            window_ = "cstrMenuAsali";
        }
    }
    else if ( window_ == "batchMenuAsali" )
    {
        inputGrid_.remove(*backButton_[11]);
        inputGrid_.remove(*mainMenuButton_[11]);
        inputGrid_.remove(*nextButton_[11]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[23],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[23],1,13,1,1);
            inputGrid_.attach(*nextButton_[23],2,13,1,1);
            window_ = "cstrMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[22],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[22],1,13,1,1);
            inputGrid_.attach(*nextButton_[22],2,13,1,1);
            window_ = "cstrMenuAsali";
        }
    }
    else if ( window_ == "ph1dMenuCantera" )
    {
        inputGrid_.remove(*backButton_[17]);
        inputGrid_.remove(*mainMenuButton_[17]);
        inputGrid_.remove(*nextButton_[17]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[23],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[23],1,13,1,1);
            inputGrid_.attach(*nextButton_[23],2,13,1,1);
            window_ = "cstrMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[22],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[22],1,13,1,1);
            inputGrid_.attach(*nextButton_[22],2,13,1,1);
            window_ = "cstrMenuAsali";
        }
    }
    else if ( window_ == "ph1dMenuAsali" )
    {
        inputGrid_.remove(*backButton_[16]);
        inputGrid_.remove(*mainMenuButton_[16]);
        inputGrid_.remove(*nextButton_[16]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[23],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[23],1,13,1,1);
            inputGrid_.attach(*nextButton_[23],2,13,1,1);
            window_ = "cstrMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[22],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[22],1,13,1,1);
            inputGrid_.attach(*nextButton_[22],2,13,1,1);
            window_ = "cstrMenuAsali";
        }
    }
    else if ( window_ == "cstrMenuCantera" )
    {
        inputGrid_.remove(*backButton_[23]);
        inputGrid_.remove(*mainMenuButton_[23]);
        inputGrid_.remove(*nextButton_[23]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[23],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[23],1,13,1,1);
            inputGrid_.attach(*nextButton_[23],2,13,1,1);
            window_ = "cstrMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[22],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[22],1,13,1,1);
            inputGrid_.attach(*nextButton_[22],2,13,1,1);
            window_ = "cstrMenuAsali";
        }
    }
    else if ( window_ == "cstrMenuAsali" )
    {
        inputGrid_.remove(*backButton_[22]);
        inputGrid_.remove(*mainMenuButton_[22]);
        inputGrid_.remove(*nextButton_[22]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[23],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[23],1,13,1,1);
            inputGrid_.attach(*nextButton_[23],2,13,1,1);
            window_ = "cstrMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[22],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[22],1,13,1,1);
            inputGrid_.attach(*nextButton_[22],2,13,1,1);
            window_ = "cstrMenuAsali";
        }
    }
    else if ( window_ == "het1dMenuAsali" )
    {
        inputGrid_.remove(*backButton_[27]);
        inputGrid_.remove(*nextButton_[27]);
        inputGrid_.remove(*mainMenuButton_[27]);
        inputGrid_.attach(*backButton_[0],0,13,1,1);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[23],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[23],1,13,1,1);
            inputGrid_.attach(*nextButton_[23],2,13,1,1);
            window_ = "cstrMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[22],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[22],1,13,1,1);
            inputGrid_.attach(*nextButton_[22],2,13,1,1);
            window_ = "cstrMenuAsali";
        }
    }
    else if ( window_ == "het1dMenuCantera" )
    {
        inputGrid_.remove(*backButton_[28]);
        inputGrid_.remove(*nextButton_[28]);
        inputGrid_.remove(*mainMenuButton_[28]);
        inputGrid_.attach(*backButton_[0],0,13,1,1);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[23],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[23],1,13,1,1);
            inputGrid_.attach(*nextButton_[23],2,13,1,1);
            window_ = "cstrMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[22],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[22],1,13,1,1);
            inputGrid_.attach(*nextButton_[22],2,13,1,1);
            window_ = "cstrMenuAsali";
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
            inputGrid_.attach(*backButton_[23],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[23],1,13,1,1);
            inputGrid_.attach(*nextButton_[23],2,13,1,1);
            window_ = "cstrMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[22],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[22],1,13,1,1);
            inputGrid_.attach(*nextButton_[22],2,13,1,1);
            window_ = "cstrMenuAsali";
        }
    }

    //Resize
    this->resize(inputGrid_.get_width(),inputGrid_.get_height ());
    this->show_all_children();

}

void Asali::cstrSave()
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
            
            output << "Kinetic type:       " << kineticTypeCombo_.get_active_text() << std::endl;
            output << "Pressure:           " << p_ << " Pa" << std::endl;
            output << "Flow rate:          " << Q_ << " m\u00b3/s" << std::endl;
            output << "Volume:             " << V_ << " m\u00b3" << std::endl;
            output << "Integration time:   " << tf_ << " s" << std::endl;

            if ( kineticTypeCombo_.get_active_text() == "ASALI" )
            {
                std::vector<double>               t = cstr_->getTime();
                std::vector<double>               T = cstr_->getTemperature();
                std::vector<std::vector<double> > y = cstr_->getSpecie();

                output << "Mass fraction" << std::endl;
                output << "Time [s]" << "\t" << "Temperature [K]" << "\t";
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
                output << "Time [s]" << "\t" << "Temperature [K]" << "\t";
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
                std::vector<double>               t = cstr_->getTime();
                std::vector<double>               T = cstr_->getTemperature();
                std::vector<std::vector<double> > y = cstr_->getSpecie();
                std::vector<std::vector<double> > Z = cstr_->getSite();

                std::vector<std::string>          name(thermo_->nSpecies());
                
                for (unsigned int i=0;i<thermo_->nSpecies();i++)
                {
                    name[i] = thermo_->speciesName(i);
                }

                output << "Mass fraction" << std::endl;
                output << "Time [s]" << "\t" << "Temperature [K]" << "\t";
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
                output << "Time [s]" << "\t" << "Temperature [K]" << "\t";
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

void Asali::cstrRun()
{
    if ( kineticTypeCombo_.get_active_row_number() == 0)
    {
        cstr_->setCanteraThermo(thermo_);
        cstr_->setCanteraTransport(transport_);
        cstr_->setCanteraInterface(surface_);
        cstr_->setCanteraKinetics(kinetic_);
        cstr_->turnOnUserDefined(false);
    }
    else if ( kineticTypeCombo_.get_active_row_number() == 1)
    {
        if ( kineticType_ == "none" )
        {
            cstr_->turnOnUserDefined(true);
            cstr_->setAsaliKinetic(asaliKinetic_->get_NR(),
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
            cstr_->set_MW(asaliProperties_->get_MW());
            cstr_->set_QfromSurface(asaliProperties_->get_Q());
            cstr_->set_cp(asaliProperties_->get_cp());
        }
        else
        {
            cstr_->setCanteraThermo(thermo_);
            cstr_->setCanteraTransport(transport_);
            cstr_->turnOnUserDefined(false);
            cstr_->setAsaliKinetic(asaliKinetic_->get_NR(),
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

    cstr_->setKineticType(kineticTypeCombo_.get_active_text());
    cstr_->resize();
    cstr_->setHomogeneusReactions(false);
    cstr_->setHeterogeneusReactions(true);
    
    if ( energy_ == "on" )
    {
        cstr_->setEnergy(true);
    }
    else if ( energy_ == "off" )
    {
        cstr_->setEnergy(false);
    }
    
    cstr_->setVolume(V_);
    cstr_->setFlow(Q_);
    cstr_->setPressure(p_);
    cstr_->setTemperature(T_);
    cstr_->setCatalystLoad(alfa_);
    
    ASALI::CstrInterface solver;
    solver.setEquations(cstr_);
    solver.start();

    std::vector<double> x0(cstr_->NumberOfEquations());

    if ( kineticType_ == "none" )
    {
        if ( fractionCombo_.get_active_row_number() == 0 )
        {
            std::vector<double> y = asaliProperties_->get_mass_fraction(asaliProperties_->get_MW(),x_);
            
            for (unsigned int i=0;i<x_.size();i++)
            {
                x0[i] = y[i];
            }
            cstr_->setInletConditions(y,T_);
        }
        else if ( fractionCombo_.get_active_row_number() == 1 )
        {
            for (unsigned int i=0;i<x_.size();i++)
            {
                x0[i] = x_[i];
            }
            cstr_->setInletConditions(x_,T_);
        }

        x0[x_.size()] = T_;
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
                std::vector<double> y0(cstr_->NumberOfEquations()-1);
                
                for (unsigned int i=0;i<n_.size();i++)
                {
                    for (unsigned int j=0;j<canteraInterface_->nSpecies();j++)
                    {
                        if ( n_[i] == canteraInterface_->names()[j] )
                        {
                            x0[i] = y[j];
                            y0[i] = y[j];
                            break;
                        }
                    }
                }
                cstr_->setInletConditions(y0,T_);
            }

            x0[x_.size()] = T_;
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
                cstr_->setInletConditions(y,T_);
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
        }
    }

    this->cstrBar(0.,"Starting...");
    cstr_->store(0.,x0);
    
    //Start solving
    {
        clock_t t1   = std::clock();
        double  ti   = 0.;
        double  tf   = 0.;
        double  dt   = dt_/100.;
        double  td   = 0;
        int     tm   = 0;
        int     hour = 0;
        int     min  = 0;
        int     sec  = 0;
        int     Nt = int(tf_/dt) + 1;
        for (int i=0;i<Nt;i++)
        {
            tf = ti + dt;

            solver.setInitialConditions(ti,x0);
            solver.solve(tf,x0);

            td += dt;
            
            if ( std::fabs(td - dt_) < dt*0.001 )
            {
                cstr_->store(tf,x0);
                td = 0.;
            }

            tm   = ((std::clock() - t1)/(double)CLOCKS_PER_SEC)*Nt/(i+1) - std::clock()/(double)CLOCKS_PER_SEC;
            hour = tm/3600;
            tm   = tm%3600;
            min  = tm/60;
            tm   = tm%60;
            sec  = tm;

            ti = tf;

            this->cstrBar(double(i+1)*dt/tf_,"Remaning time: " + std::to_string(std::abs(hour))
                                                               + ":" 
                                                               + std::to_string(std::abs(min)) 
                                                               + ":" 
                                                               + std::to_string(std::abs(sec)));
                                                               
                                                               
            if (!cstrBar_->check() ||
                !solver.check())
            {
                break;
            }
        }
    }
    
    cstrBar_->exit();

    if ( solver.check()    == true &&
         cstrBar_->check() == true)
    {
        this->cstrSave();
    }
}

void Asali::cstrBar(const double fraction,const std::string tm)
{
    //Update solving bar
    while( Gtk::Main::events_pending() )
    {
        Gtk::Main::iteration();
    }

    cstrBar_->update(fraction,tm);
    cstrBar_->show();

    //Update solving bar
    while( Gtk::Main::events_pending() )
    {
        Gtk::Main::iteration();
    }
}

void Asali::cstrReader()
{
    V_    = Glib::Ascii::strtod(cstrVolumeEntry_.get_text());
    Q_    = Glib::Ascii::strtod(cstrFlowEntry_.get_text());
    alfa_ = Glib::Ascii::strtod(cstrLoadEntry_.get_text());
    tf_   = Glib::Ascii::strtod(cstrTimeEntry_.get_text());
    dt_   = Glib::Ascii::strtod(cstrSaveEntry_.get_text());

    ConvertsToCubeMeter(V_,cstrVolumeCombo_.get_active_text());
    ConvertsToCubeMeterPerSecond(Q_,cstrVolumeCombo_.get_active_text());
    ConvertsToOneOverMeter(alfa_,cstrLoadCombo_.get_active_text());
    ConvertsToSecond(tf_,cstrTimeCombo_.get_active_text());
    ConvertsToSecond(dt_,cstrSaveCombo_.get_active_text());

    energy_     = cstrEnergyCombo_.get_active_text();
}

void Asali::cstrCoverage()
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
        this->set_title("ASALI: CST reactors");
        
        //Add thermo menu grid
        this->add(coverageBox_);
        
        if ( coverage_ == "cstr" )
        {
            coverageInputGrid_.remove(*backButton_[24]);
            coverageInputGrid_.remove(*nextButton_[24]);
            coverageInputGrid_.attach(*backButton_[24],0,SURF_NS_,1,1);
            coverageInputGrid_.attach(*nextButton_[24],1,SURF_NS_,1,1);
            coverage_ = "cstr";
        }
        else
        {
            coverageInputGrid_.attach(*backButton_[24],0,SURF_NS_,1,1);
            coverageInputGrid_.attach(*nextButton_[24],1,SURF_NS_,1,1);
            coverage_ = "cstr";
        }
        
        //Resize
        this->resize(coverageBox_.get_width(),coverageBox_.get_height());

        this->show_all_children();
    }
}

void Asali::cstrPlot()
{
    asaliPlot_->destroy();
    asaliPlot_->setTime(cstr_->getTime());
    asaliPlot_->setTemperature(cstr_->getTemperature());

    if ( kineticTypeCombo_.get_active_text() == "ASALI" )
    {
        std::vector<double>               t = cstr_->getTime();
        std::vector<double>               T = cstr_->getTemperature();
        std::vector<std::vector<double> > x = cstr_->getSpecie();
        std::vector<std::vector<double> > y = cstr_->getSpecie();
        
        for (unsigned int j=0;j<t.size();j++)
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
        std::vector<double>               t = cstr_->getTime();
        std::vector<double>               T = cstr_->getTemperature();
        std::vector<std::vector<double> > y = cstr_->getSpecie();
        std::vector<std::vector<double> > x = cstr_->getSpecie();

        std::vector<std::string>          name(thermo_->nSpecies());
        
        for (unsigned int i=0;i<thermo_->nSpecies();i++)
        {
            name[i] = thermo_->speciesName(i);
        }

        for (unsigned int j=0;j<t.size();j++)
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
        asaliPlot_->setSite(cstr_->getSite());
    }

    asaliPlot_->setType("cstr");
    asaliPlot_->build();
    asaliPlot_->show();
}

