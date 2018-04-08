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

void Asali::batchRecap()
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
        this->batchReader();
        this->kineticReader();
        this->propertiesShow();

        //Clean the window
        this->remove();
        this->set_title("ASALI: Batch reactors");
        this->add(batchRecapMainBox_);

        //Volume
        {
            std::ostringstream s;
            s << V_;
            batchRecapVolumeValueLabel_.set_text(s.str());
        }

        //Temperature
        {
            std::ostringstream s;
            s << T_;
            batchRecapTemperatureValueLabel_.set_text(s.str());
        }
        
        //Pressure
        {
            std::ostringstream s;
            s << p_;
            batchRecapPressureValueLabel_.set_text(s.str());
        }
        
        //Mole/mass fraction
        {
            batchRecapFractionLabel_.set_text(fractionCombo_.get_active_text());
            {
                std::string s = n_[0];
                for (unsigned int i=1;i<n_.size();i++)
                {
                    s = s + "\n" + n_[i];
                }
                batchRecapFractionNameLabel_.set_text(s);
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
                batchRecapFractionValueLabel_.set_text(s);
            }
        }

        //Load
        {
            std::ostringstream s;
            s << alfa_;
            batchRecapLoadValueLabel_.set_text(s.str());
        }

        //Time
        {
            std::ostringstream s;
            s << tf_;
            batchRecapTimeValueLabel_.set_text(s.str());
        }

        //Save
        {
            std::ostringstream s;
            s << dt_;
            batchRecapSaveValueLabel_.set_text(s.str());
        }

        //Kinetic
        {
            batchRecapKineticValueLabel_.set_text(kineticTypeCombo_.get_active_text());
        }

        {
            batchRecapEnergyValueLabel_.set_text(energy_);
        }

        //Buttons
        if (batchBool_)
        {
            if ( kineticTypeOld_ == "none" )
            {
                batchButtonBox_.remove(batchAsaliKineticButton_);
                batchButtonBox_.remove(batchAsaliPropertiesButton_);
            }
            else if ( kineticTypeOld_ == "default" )
            {
                batchButtonBox_.remove(batchAsaliKineticButton_);
            }
            
            if ( kineticType_ == "none" )
            {
                batchButtonBox_.pack_start(batchAsaliKineticButton_, Gtk::PACK_SHRINK);
                batchButtonBox_.pack_start(batchAsaliPropertiesButton_, Gtk::PACK_SHRINK);
                kineticTypeOld_ = kineticType_;
            }
            else if ( kineticType_ == "default" )
            {
                batchButtonBox_.pack_start(batchAsaliKineticButton_, Gtk::PACK_SHRINK);
                kineticTypeOld_ = kineticType_;
            }
            else if ( kineticType_ == "load" )
            {
                if ( kineticTypeCombo_.get_active_row_number() == 1 )
                {
                    batchButtonBox_.pack_start(batchAsaliKineticButton_, Gtk::PACK_SHRINK);
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
                batchButtonBox_.pack_start(batchAsaliKineticButton_, Gtk::PACK_SHRINK);
                batchButtonBox_.pack_start(batchAsaliPropertiesButton_, Gtk::PACK_SHRINK);
                kineticTypeOld_ = kineticType_;
            }
            else if ( kineticType_ == "default" )
            {
                batchButtonBox_.pack_start(batchAsaliKineticButton_, Gtk::PACK_SHRINK);
                kineticTypeOld_ = kineticType_;
            }
            else if ( kineticType_ == "load" )
            {
                if ( kineticTypeCombo_.get_active_row_number() == 1 )
                {
                    batchButtonBox_.pack_start(batchAsaliKineticButton_, Gtk::PACK_SHRINK);
                    kineticTypeOld_ = "default";
                }
                else
                {
                    kineticTypeOld_ = kineticType_;
                }
            }
            batchBool_ = true;
        }

        this->resize(batchRecapMainBox_.get_width(),batchRecapMainBox_.get_height ());
        this->show_all_children();
    }
}

void Asali::batchMenu()
{
    //Clean the window
    this->remove();
    this->set_title("ASALI: Batch reactors");
    
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
            inputGrid_.attach(*backButton_[13],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[13],1,13,1,1);
            inputGrid_.attach(*nextButton_[13],2,13,1,1);
            window_ = "batchMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[11],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[11],1,13,1,1);
            inputGrid_.attach(*nextButton_[11],2,13,1,1);
            window_ = "batchMenuAsali";
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
            inputGrid_.attach(*backButton_[13],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[13],1,13,1,1);
            inputGrid_.attach(*nextButton_[13],2,13,1,1);
            window_ = "batchMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[11],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[11],1,13,1,1);
            inputGrid_.attach(*nextButton_[11],2,13,1,1);
            window_ = "batchMenuAsali";
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
            inputGrid_.attach(*backButton_[13],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[13],1,13,1,1);
            inputGrid_.attach(*nextButton_[13],2,13,1,1);
            window_ = "batchMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[11],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[11],1,13,1,1);
            inputGrid_.attach(*nextButton_[11],2,13,1,1);
            window_ = "batchMenuAsali";
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
            inputGrid_.attach(*backButton_[13],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[13],1,13,1,1);
            inputGrid_.attach(*nextButton_[13],2,13,1,1);
            window_ = "batchMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[11],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[11],1,13,1,1);
            inputGrid_.attach(*nextButton_[11],2,13,1,1);
            window_ = "batchMenuAsali";
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
            inputGrid_.attach(*backButton_[13],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[13],1,13,1,1);
            inputGrid_.attach(*nextButton_[13],2,13,1,1);
            window_ = "batchMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[11],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[11],1,13,1,1);
            inputGrid_.attach(*nextButton_[11],2,13,1,1);
            window_ = "batchMenuAsali";
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
            inputGrid_.attach(*backButton_[13],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[13],1,13,1,1);
            inputGrid_.attach(*nextButton_[13],2,13,1,1);
            window_ = "batchMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[11],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[11],1,13,1,1);
            inputGrid_.attach(*nextButton_[11],2,13,1,1);
            window_ = "batchMenuAsali";
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
            inputGrid_.attach(*backButton_[13],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[13],1,13,1,1);
            inputGrid_.attach(*nextButton_[13],2,13,1,1);
            window_ = "batchMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[11],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[11],1,13,1,1);
            inputGrid_.attach(*nextButton_[11],2,13,1,1);
            window_ = "batchMenuAsali";
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
            inputGrid_.attach(*backButton_[13],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[13],1,13,1,1);
            inputGrid_.attach(*nextButton_[13],2,13,1,1);
            window_ = "batchMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[11],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[11],1,13,1,1);
            inputGrid_.attach(*nextButton_[11],2,13,1,1);
            window_ = "batchMenuAsali";
        }
    }
    else if ( window_ == "batchMenuCantera" )
    {
        inputGrid_.remove(*backButton_[13]);
        inputGrid_.remove(*mainMenuButton_[13]);
        inputGrid_.remove(*nextButton_[13]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[13],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[13],1,13,1,1);
            inputGrid_.attach(*nextButton_[13],2,13,1,1);
            window_ = "batchMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[11],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[11],1,13,1,1);
            inputGrid_.attach(*nextButton_[11],2,13,1,1);
            window_ = "batchMenuAsali";
        }
    }
    else if ( window_ == "batchMenuAsali" )
    {
        inputGrid_.remove(*backButton_[11]);
        inputGrid_.remove(*mainMenuButton_[11]);
        inputGrid_.remove(*nextButton_[11]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[13],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[13],1,13,1,1);
            inputGrid_.attach(*nextButton_[13],2,13,1,1);
            window_ = "batchMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[11],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[11],1,13,1,1);
            inputGrid_.attach(*nextButton_[11],2,13,1,1);
            window_ = "batchMenuAsali";
        }
    }
    else if ( window_ == "ph1dMenuCantera" )
    {
        inputGrid_.remove(*backButton_[17]);
        inputGrid_.remove(*mainMenuButton_[17]);
        inputGrid_.remove(*nextButton_[17]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[13],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[13],1,13,1,1);
            inputGrid_.attach(*nextButton_[13],2,13,1,1);
            window_ = "batchMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[11],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[11],1,13,1,1);
            inputGrid_.attach(*nextButton_[11],2,13,1,1);
            window_ = "batchMenuAsali";
        }
    }
    else if ( window_ == "ph1dMenuAsali" )
    {
        inputGrid_.remove(*backButton_[16]);
        inputGrid_.remove(*mainMenuButton_[16]);
        inputGrid_.remove(*nextButton_[16]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[13],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[13],1,13,1,1);
            inputGrid_.attach(*nextButton_[13],2,13,1,1);
            window_ = "batchMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[11],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[11],1,13,1,1);
            inputGrid_.attach(*nextButton_[11],2,13,1,1);
            window_ = "batchMenuAsali";
        }
    }
    else if ( window_ == "cstrMenuCantera" )
    {
        inputGrid_.remove(*backButton_[23]);
        inputGrid_.remove(*mainMenuButton_[23]);
        inputGrid_.remove(*nextButton_[23]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[13],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[13],1,13,1,1);
            inputGrid_.attach(*nextButton_[13],2,13,1,1);
            window_ = "batchMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[11],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[11],1,13,1,1);
            inputGrid_.attach(*nextButton_[11],2,13,1,1);
            window_ = "batchMenuAsali";
        }
    }
    else if ( window_ == "cstrMenuAsali" )
    {
        inputGrid_.remove(*backButton_[22]);
        inputGrid_.remove(*mainMenuButton_[22]);
        inputGrid_.remove(*nextButton_[22]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[13],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[13],1,13,1,1);
            inputGrid_.attach(*nextButton_[13],2,13,1,1);
            window_ = "batchMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[11],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[11],1,13,1,1);
            inputGrid_.attach(*nextButton_[11],2,13,1,1);
            window_ = "batchMenuAsali";
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
            inputGrid_.attach(*backButton_[13],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[13],1,13,1,1);
            inputGrid_.attach(*nextButton_[13],2,13,1,1);
            window_ = "batchMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[11],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[11],1,13,1,1);
            inputGrid_.attach(*nextButton_[11],2,13,1,1);
            window_ = "batchMenuAsali";
        }
    }

    //Resize
    this->resize(inputGrid_.get_width(),inputGrid_.get_height ());
    this->show_all_children();

}

void Asali::batchSave()
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
            
            output << "Residence time:     " << tf_ << " s" << std::endl;
            output << "Kinetic type:       " << kineticTypeCombo_.get_active_text() << std::endl;
            output << "Pressure:           " << p_ << " Pa" << std::endl;

            if ( kineticTypeCombo_.get_active_text() == "ASALI" )
            {
                std::vector<double>               t = batch_->getTime();
                std::vector<double>               T = batch_->getTemperature();
                std::vector<std::vector<double> > y = batch_->getSpecie();
                std::vector<double>               V = batch_->getVolume();

                output << "Mass fraction" << std::endl;
                output << "Time [s]" << "\t" << "Temperature [K]" << "\t" << "Volume [m\u00b3]" << "\t";
                for (unsigned int i=0;i<n_.size();i++)
                {
                    output << n_[i] << "\t";
                }
                output << std::endl;
                
                for (unsigned int j=0;j<t.size();j++)
                {
                    output << t[j] << "\t" << T[j] << "\t" << V[j] << "\t";
                    for (unsigned int i=0;i<(n_.size());i++)
                    {
                        output << y[j][i] << "\t";
                    }
                    output << std::endl;
                }
                output << std::endl;
                
                output << "Mole fraction" << std::endl;
                output << "Time [s]" << "\t" << "Temperature [K]" << "\t" << "Volume [m\u00b3]" << "\t";
                for (unsigned int i=0;i<n_.size();i++)
                {
                    output << n_[i] << "\t";
                }
                output << std::endl;
                
                for (unsigned int j=0;j<t.size();j++)
                {
                    output << t[j] << "\t" << T[j] << "\t" << V[j] << "\t";

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
                std::vector<double>               t = batch_->getTime();
                std::vector<double>               T = batch_->getTemperature();
                std::vector<double>               V = batch_->getVolume();
                std::vector<std::vector<double> > y = batch_->getSpecie();
                std::vector<std::vector<double> > Z = batch_->getSite();

                std::vector<std::string>          name(thermo_->nSpecies());
                
                for (unsigned int i=0;i<thermo_->nSpecies();i++)
                {
                    name[i] = thermo_->speciesName(i);
                }

                output << "Mass fraction" << std::endl;
                output << "Time [s]" << "\t" << "Temperature [K]" << "\t" << "Volume [m\u00b3]" << "\t";
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
                    output << t[j] << "\t" << T[j] << "\t" << V[j] << "\t";
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
                output << "Time [s]" << "\t" << "Temperature [K]" << "\t" << "Volume [m\u00b3]" << "\t";
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
                    output << t[j] << "\t" << T[j] << "\t" << V[j] << "\t";

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

void Asali::batchRun()
{
    if ( kineticTypeCombo_.get_active_row_number() == 0)
    {
        batch_->setCanteraThermo(thermo_);
        batch_->setCanteraTransport(transport_);
        batch_->setCanteraInterface(surface_);
        batch_->setCanteraKinetics(kinetic_);
        batch_->turnOnUserDefined(false);
    }
    else if ( kineticTypeCombo_.get_active_row_number() == 1)
    {
        if ( kineticType_ == "none" )
        {
            batch_->turnOnUserDefined(true);
            batch_->setAsaliKinetic(asaliKinetic_->get_NR(),
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
            batch_->set_MW(asaliProperties_->get_MW());
            batch_->set_QfromSurface(asaliProperties_->get_Q());
            batch_->set_cp(asaliProperties_->get_cp());
        }
        else
        {
            batch_->setCanteraThermo(thermo_);
            batch_->setCanteraTransport(transport_);
            batch_->turnOnUserDefined(false);
            batch_->setAsaliKinetic(asaliKinetic_->get_NR(),
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

    batch_->setKineticType(kineticTypeCombo_.get_active_text());
    batch_->resize();
    batch_->setHomogeneusReactions(false);
    batch_->setHeterogeneusReactions(true);
    
    if ( energy_ == "on" )
    {
        batch_->setEnergy(true);
    }
    else if ( energy_ == "off" )
    {
        batch_->setEnergy(false);
    }
    
    batch_->setVolume(V_);
    batch_->setPressure(p_);
    batch_->setTemperature(T_);
    batch_->setCatalystLoad(alfa_);
    
    ASALI::BatchInterface solver;
    
    solver.setEquations(batch_);

    std::vector<double> x0(batch_->NumberOfEquations());

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

        x0[x_.size()]     = p_*V_*MWmix/(8314.*T_);
        
        x0[x_.size() + 1] = T_;
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

            x0[x_.size()] = canteraInterface_->density()*V_;
            
            x0[x_.size() + 1] = T_;
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

            x0[thermo_->nSpecies()] = canteraInterface_->density()*V_;

            {
                for (unsigned int j=0;j<surface_->nSpecies();j++)
                {
                    x0[j+thermo_->nSpecies()+1] = 0.;
                }

                for (unsigned int i=0;i<nc_.size();i++)
                {
                    for (unsigned int j=0;j<surface_->nSpecies();j++)
                    {
                        if ( nc_[i] == surface_->speciesName(j) )
                        {
                            x0[j+thermo_->nSpecies()+1] = xc_[i];
                            break;
                        }
                    }
                }
            }

            x0[thermo_->nSpecies() + surface_->nSpecies() + 1] = T_;
        }
    }
    
    
    yF_.resize(batch_->NumberOfEquations());
    this->batchBar(0.);
    
    //Start solving
    {
        double ti = 0.;
        double tf = 0.;
        batch_->store(0.,x0);
        for (int i=0;i<int(tf_/dt_);i++)
        {
            tf = ti + dt_;

            solver.setInitialConditions(ti,x0);
            solver.solve(tf,x0);
            
            batch_->store(tf,x0);

            ti = tf;

            this->batchBar(double(i+1)*dt_/tf_);
        }
    }
    
    batchBar_->exit();
    this->batchSave();
}

void Asali::batchBar(const double fraction)
{
    //Update solving bar
    while( Gtk::Main::events_pending() )
    {
        Gtk::Main::iteration();
    }

    batchBar_->update(fraction);
    batchBar_->show();

    //Update solving bar
    while( Gtk::Main::events_pending() )
    {
        Gtk::Main::iteration();
    }
}

void Asali::batchReader()
{
    V_    = Glib::Ascii::strtod(batchVolumeEntry_.get_text());
    alfa_ = Glib::Ascii::strtod(batchLoadEntry_.get_text());
    tf_   = Glib::Ascii::strtod(batchTimeEntry_.get_text());
    dt_   = Glib::Ascii::strtod(batchSaveEntry_.get_text());

    ConvertsToCubeMeter(V_,batchVolumeCombo_.get_active_text());
    ConvertsToOneOverMeter(alfa_,batchLoadCombo_.get_active_text());
    ConvertsToSecond(tf_,batchTimeCombo_.get_active_text());
    ConvertsToSecond(dt_,batchSaveCombo_.get_active_text());

    energy_     = batchEnergyCombo_.get_active_text();
}

void Asali::batchCoverage()
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
        this->set_title("ASALI: Batch reactors");
        
        //Add thermo menu grid
        this->add(coverageBox_);
        
        if ( coverage_ == "batch" )
        {
            coverageInputGrid_.remove(*backButton_[14]);
            coverageInputGrid_.remove(*nextButton_[14]);
            coverageInputGrid_.attach(*backButton_[14],0,SURF_NS_,1,1);
            coverageInputGrid_.attach(*nextButton_[14],1,SURF_NS_,1,1);
            coverage_ = "batch";
        }
        else
        {
            coverageInputGrid_.attach(*backButton_[14],0,SURF_NS_,1,1);
            coverageInputGrid_.attach(*nextButton_[14],1,SURF_NS_,1,1);
            coverage_ = "batch";
        }
        
        //Resize
        this->resize(coverageBox_.get_width(),coverageBox_.get_height());

        this->show_all_children();
    }
}

void Asali::batchPlot()
{
    asaliPlot_->setTime(batch_->getTime());
    asaliPlot_->setTemperature(batch_->getTemperature());
    asaliPlot_->setVolume(batch_->getVolume());

    if ( kineticTypeCombo_.get_active_text() == "ASALI" )
    {
        std::vector<double>               t = batch_->getTime();
        std::vector<double>               T = batch_->getTemperature();
        std::vector<std::vector<double> > x = batch_->getSpecie();
        std::vector<std::vector<double> > y = batch_->getSpecie();
        
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
        std::vector<double>               t = batch_->getTime();
        std::vector<double>               T = batch_->getTemperature();
        std::vector<std::vector<double> > y = batch_->getSpecie();
        std::vector<std::vector<double> > x = batch_->getSpecie();

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
        asaliPlot_->setSite(batch_->getSite());
    }

    asaliPlot_->setType("batch");
    asaliPlot_->build();
    asaliPlot_->show();
}
