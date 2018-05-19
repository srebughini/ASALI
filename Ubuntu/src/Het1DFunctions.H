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

void Asali::het1dRecap()
{
    asaliCatalystProperties_->show();

    this->het1dCleanRecap();
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
        this->het1dReader();
        this->kineticReader();
        this->propertiesShow();

        //Clean the window
        this->remove();
        this->set_title("ASALI: 1D HET reactors");
        this->add(het1dRecapMainBox_);

        //Reactor type
        {
            het1dRecapReactorTypeValueLabel_.set_text(reactorType_);
        }

        //Velocity
        {
            std::ostringstream s;
            s << v_;
            het1dRecapVelocityValueLabel_.set_text(s.str());
        }

        //Temperature
        {
            std::ostringstream s;
            s << T_;
            het1dRecapTemperatureValueLabel_.set_text(s.str());
        }
        
        //Pressure
        {
            std::ostringstream s;
            s << p_;
            het1dRecapPressureValueLabel_.set_text(s.str());
        }
        
        int NC = -1;
        //Mole/mass fraction
        {
            het1dRecapFractionLabel_.set_text(fractionCombo_.get_active_text());
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
                het1dRecapFractionNameLabel_.set_text(s1);
                het1dRecapFractionValueLabel_.set_text(s2);
            }

            {
                het1dRecapGrid_.attach(het1dRecapFractionLabel_,3,3,1,NC+1);
                het1dRecapGrid_.attach(het1dRecapFractionNameLabel_,5,3,1,NC+1);
                het1dRecapGrid_.attach(het1dRecapFractionValueLabel_,4,3,1,NC+1);
            }
        }
        
        //Length
        {
            het1dRecapGrid_.attach(het1dRecapLengthLabel_,3,4+NC,1,1);
            het1dRecapGrid_.attach(het1dRecapLengthUDLabel_,5,4+NC,1,1);
            het1dRecapGrid_.attach(het1dRecapLengthValueLabel_,4,4+NC,1,1);
            {
                std::ostringstream s;
                s << L_;
                het1dRecapLengthValueLabel_.set_text(s.str());
            }
        }

        //Time
        {
            std::ostringstream s;
            s << tf_;
            het1dRecapTimeValueLabel_.set_text(s.str());
        }

        //Save
        {
            std::ostringstream s;
            s << dt_;
            het1dRecapSaveValueLabel_.set_text(s.str());
        }

        //Points
        {
            std::ostringstream s;
            s << NP_;
            het1dRecapPointsValueLabel_.set_text(s.str());
        }

        //Inert
        {
            het1dRecapInertValueLabel_.set_text(inert_);
        }

        if ( reactorType_ == "tubular" )
        {
            het1dRecapGrid_.attach(het1dRecapTubularTubeLabel_,3,5+NC,1,1);
            het1dRecapGrid_.attach(het1dRecapTubularTubeUDLabel_,5,5+NC,1,1);
            het1dRecapGrid_.attach(het1dRecapTubularTubeValueLabel_,4,5+NC,1,1);
            {
                std::ostringstream s;
                s << Dt_;
                het1dRecapTubularTubeValueLabel_.set_text(s.str());
            }

            het1dRecapGrid_.attach(het1dRecapTubularWallThicknessLabel_,3,6+NC,1,1);
            het1dRecapGrid_.attach(het1dRecapTubularWallThicknessUDLabel_,5,6+NC,1,1);
            het1dRecapGrid_.attach(het1dRecapTubularWallThicknessValueLabel_,4,6+NC,1,1);
            {
                std::ostringstream s;
                s << tw_;
                het1dRecapTubularWallThicknessValueLabel_.set_text(s.str());
            }
            
            het1dRecapGrid_.attach(het1dRecapTubularDuctLabel_,3,7+NC,1,1);
            het1dRecapGrid_.attach(het1dRecapTubularDuctValueLabel_,4,7+NC,1,1);
            {
                het1dRecapTubularDuctValueLabel_.set_text(section_);
            }
            het1dTubularBool_   = true;
            het1dPackedBedBool_ = false;
            het1dHoneyCombBool_ = false;
        }
        else if ( reactorType_ == "honeycomb" )
        {
            het1dRecapGrid_.attach(het1dRecapHoneyCombCPSILabel_,3,5+NC,1,1);
            het1dRecapGrid_.attach(het1dRecapHoneyCombCPSIValueLabel_,4,5+NC,1,1);
            {
                std::ostringstream s;
                s << cpsi_;
                het1dRecapHoneyCombCPSIValueLabel_.set_text(s.str());
            }

            het1dRecapGrid_.attach(het1dRecapHoneyCombWallThicknessLabel_,3,6+NC,1,1);
            het1dRecapGrid_.attach(het1dRecapHoneyCombWallThicknessUDLabel_,5,6+NC,1,1);
            het1dRecapGrid_.attach(het1dRecapHoneyCombWallThicknessValueLabel_,4,6+NC,1,1);
            {
                std::ostringstream s;
                s << tw_;
                het1dRecapHoneyCombWallThicknessValueLabel_.set_text(s.str());
            }

            het1dRecapGrid_.attach(het1dRecapHoneyCombDuctLabel_,3,7+NC,1,1);
            het1dRecapGrid_.attach(het1dRecapHoneyCombDuctValueLabel_,4,7+NC,1,1);
            {
                het1dRecapHoneyCombDuctValueLabel_.set_text(section_);
            }

            het1dTubularBool_   = false;
            het1dPackedBedBool_ = false;
            het1dHoneyCombBool_ = true;
        }
        else if ( reactorType_ == "packed bed" )
        {
            het1dRecapGrid_.attach(het1dRecapPackedBedTubeLabel_,3,5+NC,1,1);
            het1dRecapGrid_.attach(het1dRecapPackedBedTubeUDLabel_,5,5+NC,1,1);
            het1dRecapGrid_.attach(het1dRecapPackedBedTubeValueLabel_,4,5+NC,1,1);
            {
                std::ostringstream s;
                s << Dt_;
                het1dRecapPackedBedTubeValueLabel_.set_text(s.str());
            }

            het1dRecapGrid_.attach(het1dRecapPackedBedVoidFractionLabel_,3,6+NC,1,1);
            het1dRecapGrid_.attach(het1dRecapPackedBedVoidFractionValueLabel_,4,6+NC,1,1);
            {
                std::ostringstream s;
                s << epsi_;
                het1dRecapPackedBedVoidFractionValueLabel_.set_text(s.str());
            }

            het1dRecapGrid_.attach(het1dRecapPackedBedParticleLabel_,3,7+NC,1,1);
            het1dRecapGrid_.attach(het1dRecapPackedBedParticleUDLabel_,5,7+NC,1,1);
            het1dRecapGrid_.attach(het1dRecapPackedBedParticleValueLabel_,4,7+NC,1,1);
            {
                std::ostringstream s;
                s << Dp_;
                het1dRecapPackedBedParticleValueLabel_.set_text(s.str());
            }

            het1dTubularBool_   = false;
            het1dPackedBedBool_ = true;
            het1dHoneyCombBool_ = false;
        }
        
        //Kinetic
        {
            het1dRecapKineticValueLabel_.set_text(kineticTypeCombo_.get_active_text());
        }

        {
            het1dRecapEnergyValueLabel_.set_text(energy_);
        }

        //Buttons
        if (het1dBool_)
        {
            if ( kineticTypeOld_ == "none" )
            {
                het1dButtonBox_.remove(het1dAsaliKineticButton_);
                het1dButtonBox_.remove(het1dAsaliPropertiesButton_);
            }
            else if ( kineticTypeOld_ == "default" )
            {
                het1dButtonBox_.remove(het1dAsaliKineticButton_);
            }
            
            if ( kineticType_ == "none" )
            {
                het1dButtonBox_.pack_start(het1dAsaliKineticButton_, Gtk::PACK_SHRINK);
                het1dButtonBox_.pack_start(het1dAsaliPropertiesButton_, Gtk::PACK_SHRINK);
                kineticTypeOld_ = kineticType_;
            }
            else if ( kineticType_ == "default" )
            {
                het1dButtonBox_.pack_start(het1dAsaliKineticButton_, Gtk::PACK_SHRINK);
                kineticTypeOld_ = kineticType_;
            }
            else if ( kineticType_ == "load" )
            {
                if ( kineticTypeCombo_.get_active_row_number() == 1 )
                {
                    het1dButtonBox_.pack_start(het1dAsaliKineticButton_, Gtk::PACK_SHRINK);
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
                het1dButtonBox_.pack_start(het1dAsaliKineticButton_, Gtk::PACK_SHRINK);
                het1dButtonBox_.pack_start(het1dAsaliPropertiesButton_, Gtk::PACK_SHRINK);
                kineticTypeOld_ = kineticType_;
            }
            else if ( kineticType_ == "default" )
            {
                het1dButtonBox_.pack_start(het1dAsaliKineticButton_, Gtk::PACK_SHRINK);
                kineticTypeOld_ = kineticType_;
            }
            else if ( kineticType_ == "load" )
            {
                if ( kineticTypeCombo_.get_active_row_number() == 1 )
                {
                    het1dButtonBox_.pack_start(het1dAsaliKineticButton_, Gtk::PACK_SHRINK);
                    kineticTypeOld_ = "default";
                }
                else
                {
                    kineticTypeOld_ = kineticType_;
                }
            }
            het1dBool_ = true;
        }


        this->resize(het1dRecapMainBox_.get_width(),het1dRecapMainBox_.get_height ());
        this->show_all_children();
    }
}

void Asali::het1dCleanRecap()
{
    het1dRecapGrid_.remove(het1dRecapFractionLabel_);
    het1dRecapGrid_.remove(het1dRecapFractionNameLabel_);
    het1dRecapGrid_.remove(het1dRecapFractionValueLabel_);
    het1dRecapGrid_.remove(het1dRecapLengthLabel_);
    het1dRecapGrid_.remove(het1dRecapLengthUDLabel_);
    het1dRecapGrid_.remove(het1dRecapLengthValueLabel_);

    if (het1dTubularBool_)
    {
        het1dRecapGrid_.remove(het1dRecapTubularTubeLabel_);
        het1dRecapGrid_.remove(het1dRecapTubularTubeUDLabel_);
        het1dRecapGrid_.remove(het1dRecapTubularTubeValueLabel_);
        het1dRecapGrid_.remove(het1dRecapTubularDuctLabel_);
        het1dRecapGrid_.remove(het1dRecapTubularDuctValueLabel_);
        het1dRecapGrid_.remove(het1dRecapTubularWallThicknessLabel_);
        het1dRecapGrid_.remove(het1dRecapTubularWallThicknessUDLabel_);
        het1dRecapGrid_.remove(het1dRecapTubularWallThicknessValueLabel_);
    }
    else if (het1dPackedBedBool_)
    {
        het1dRecapGrid_.remove(het1dRecapPackedBedTubeLabel_);
        het1dRecapGrid_.remove(het1dRecapPackedBedTubeUDLabel_);
        het1dRecapGrid_.remove(het1dRecapPackedBedTubeValueLabel_);
        het1dRecapGrid_.remove(het1dRecapPackedBedVoidFractionLabel_);
        het1dRecapGrid_.remove(het1dRecapPackedBedVoidFractionValueLabel_);
        het1dRecapGrid_.remove(het1dRecapPackedBedParticleLabel_);
        het1dRecapGrid_.remove(het1dRecapPackedBedParticleUDLabel_);
        het1dRecapGrid_.remove(het1dRecapPackedBedParticleValueLabel_);
    }
    else if (het1dHoneyCombBool_)
    {
        het1dRecapGrid_.remove(het1dRecapHoneyCombCPSILabel_);
        het1dRecapGrid_.remove(het1dRecapHoneyCombCPSIValueLabel_);
        het1dRecapGrid_.remove(het1dRecapHoneyCombWallThicknessLabel_);
        het1dRecapGrid_.remove(het1dRecapHoneyCombWallThicknessUDLabel_);
        het1dRecapGrid_.remove(het1dRecapHoneyCombWallThicknessValueLabel_);
        het1dRecapGrid_.remove(het1dRecapHoneyCombDuctLabel_);
        het1dRecapGrid_.remove(het1dRecapHoneyCombDuctValueLabel_);
    }
}

void Asali::het1dMenu()
{
    //Clean the window
    this->remove();
    this->set_title("ASALI: 1D HET reactors");
    
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
            inputGrid_.attach(*backButton_[28],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[28],1,13,1,1);
            inputGrid_.attach(*nextButton_[28],2,13,1,1);
            window_ = "het1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[27],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[27],1,13,1,1);
            inputGrid_.attach(*nextButton_[27],2,13,1,1);
            window_ = "het1dMenuAsali";
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
            inputGrid_.attach(*backButton_[28],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[28],1,13,1,1);
            inputGrid_.attach(*nextButton_[28],2,13,1,1);
            window_ = "het1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[27],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[27],1,13,1,1);
            inputGrid_.attach(*nextButton_[27],2,13,1,1);
            window_ = "het1dMenuAsali";
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
            inputGrid_.attach(*backButton_[28],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[28],1,13,1,1);
            inputGrid_.attach(*nextButton_[28],2,13,1,1);
            window_ = "het1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[27],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[27],1,13,1,1);
            inputGrid_.attach(*nextButton_[27],2,13,1,1);
            window_ = "het1dMenuAsali";
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
            inputGrid_.attach(*backButton_[28],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[28],1,13,1,1);
            inputGrid_.attach(*nextButton_[28],2,13,1,1);
            window_ = "het1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[27],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[27],1,13,1,1);
            inputGrid_.attach(*nextButton_[27],2,13,1,1);
            window_ = "het1dMenuAsali";
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
            inputGrid_.attach(*backButton_[28],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[28],1,13,1,1);
            inputGrid_.attach(*nextButton_[28],2,13,1,1);
            window_ = "het1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[27],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[27],1,13,1,1);
            inputGrid_.attach(*nextButton_[27],2,13,1,1);
            window_ = "het1dMenuAsali";
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
            inputGrid_.attach(*backButton_[28],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[28],1,13,1,1);
            inputGrid_.attach(*nextButton_[28],2,13,1,1);
            window_ = "het1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[27],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[27],1,13,1,1);
            inputGrid_.attach(*nextButton_[27],2,13,1,1);
            window_ = "het1dMenuAsali";
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
            inputGrid_.attach(*backButton_[28],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[28],1,13,1,1);
            inputGrid_.attach(*nextButton_[28],2,13,1,1);
            window_ = "het1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[27],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[27],1,13,1,1);
            inputGrid_.attach(*nextButton_[27],2,13,1,1);
            window_ = "het1dMenuAsali";
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
            inputGrid_.attach(*backButton_[28],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[28],1,13,1,1);
            inputGrid_.attach(*nextButton_[28],2,13,1,1);
            window_ = "het1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[27],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[27],1,13,1,1);
            inputGrid_.attach(*nextButton_[27],2,13,1,1);
            window_ = "het1dMenuAsali";
        }
    }
    else if ( window_ == "ph1dMenuCantera" )
    {
        inputGrid_.remove(*backButton_[17]);
        inputGrid_.remove(*mainMenuButton_[17]);
        inputGrid_.remove(*nextButton_[17]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[28],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[28],1,13,1,1);
            inputGrid_.attach(*nextButton_[28],2,13,1,1);
            window_ = "het1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[27],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[27],1,13,1,1);
            inputGrid_.attach(*nextButton_[27],2,13,1,1);
            window_ = "het1dMenuAsali";
        }
    }
    else if ( window_ == "ph1dMenuAsali" )
    {
        inputGrid_.remove(*backButton_[16]);
        inputGrid_.remove(*mainMenuButton_[16]);
        inputGrid_.remove(*nextButton_[16]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[28],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[28],1,13,1,1);
            inputGrid_.attach(*nextButton_[28],2,13,1,1);
            window_ = "het1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[27],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[27],1,13,1,1);
            inputGrid_.attach(*nextButton_[27],2,13,1,1);
            window_ = "het1dMenuAsali";
        }
    }
    else if ( window_ == "batchMenuCantera" )
    {
        inputGrid_.remove(*backButton_[13]);
        inputGrid_.remove(*mainMenuButton_[13]);
        inputGrid_.remove(*nextButton_[13]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[28],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[28],1,13,1,1);
            inputGrid_.attach(*nextButton_[28],2,13,1,1);
            window_ = "het1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[27],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[27],1,13,1,1);
            inputGrid_.attach(*nextButton_[27],2,13,1,1);
            window_ = "het1dMenuAsali";
        }
    }
    else if ( window_ == "batchMenuAsali" )
    {
        inputGrid_.remove(*backButton_[11]);
        inputGrid_.remove(*mainMenuButton_[11]);
        inputGrid_.remove(*nextButton_[11]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[28],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[28],1,13,1,1);
            inputGrid_.attach(*nextButton_[28],2,13,1,1);
            window_ = "het1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[27],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[27],1,13,1,1);
            inputGrid_.attach(*nextButton_[27],2,13,1,1);
            window_ = "het1dMenuAsali";
        }
    }
    else if ( window_ == "cstrMenuCantera" )
    {
        inputGrid_.remove(*backButton_[23]);
        inputGrid_.remove(*mainMenuButton_[23]);
        inputGrid_.remove(*nextButton_[23]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[28],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[28],1,13,1,1);
            inputGrid_.attach(*nextButton_[28],2,13,1,1);
            window_ = "het1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[27],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[27],1,13,1,1);
            inputGrid_.attach(*nextButton_[27],2,13,1,1);
            window_ = "het1dMenuAsali";
        }
    }
    else if ( window_ == "cstrMenuAsali" )
    {
        inputGrid_.remove(*backButton_[22]);
        inputGrid_.remove(*mainMenuButton_[22]);
        inputGrid_.remove(*nextButton_[22]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[28],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[28],1,13,1,1);
            inputGrid_.attach(*nextButton_[28],2,13,1,1);
            window_ = "het1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[27],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[27],1,13,1,1);
            inputGrid_.attach(*nextButton_[27],2,13,1,1);
            window_ = "het1dMenuAsali";
        }
    }
    else if ( window_ == "het1dMenuCantera" )
    {
        inputGrid_.remove(*backButton_[28]);
        inputGrid_.remove(*mainMenuButton_[28]);
        inputGrid_.remove(*nextButton_[28]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[28],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[28],1,13,1,1);
            inputGrid_.attach(*nextButton_[28],2,13,1,1);
            window_ = "het1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[27],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[27],1,13,1,1);
            inputGrid_.attach(*nextButton_[27],2,13,1,1);
            window_ = "het1dMenuAsali";
        }
    }
    else if ( window_ == "het1dMenuAsali" )
    {
        inputGrid_.remove(*backButton_[27]);
        inputGrid_.remove(*mainMenuButton_[27]);
        inputGrid_.remove(*nextButton_[27]);
        if ( kineticTypeCombo_.get_active_row_number() == 0 )
        {
            inputGrid_.attach(*backButton_[28],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[28],1,13,1,1);
            inputGrid_.attach(*nextButton_[28],2,13,1,1);
            window_ = "het1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[27],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[27],1,13,1,1);
            inputGrid_.attach(*nextButton_[27],2,13,1,1);
            window_ = "het1dMenuAsali";
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
            inputGrid_.attach(*backButton_[28],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[28],1,13,1,1);
            inputGrid_.attach(*nextButton_[28],2,13,1,1);
            window_ = "het1dMenuCantera";
        }
        else if ( kineticTypeCombo_.get_active_row_number() == 1 )
        {
            inputGrid_.attach(*backButton_[27],0,13,1,1);
            inputGrid_.attach(*mainMenuButton_[27],1,13,1,1);
            inputGrid_.attach(*nextButton_[27],2,13,1,1);
            window_ = "het1dMenuAsali";
        }
    }

    //Resize
    this->resize(inputGrid_.get_width(),inputGrid_.get_height ());
    this->show_all_children();
}

void Asali::het1dSave()
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
            
            output << "Kinetic type:     " << kineticTypeCombo_.get_active_text() << std::endl;
            output << "Reactor length:   " << L_ << " m" << std::endl;
            output << "Inlet velocity:   " << v_ << " m/s" << std::endl;
            output << "Pressure:         " << p_ << " Pa" << std::endl;
            output << "Integration time: " << tf_ << " s" << std::endl;

            std::vector<double>                             t   = het1d_->getTime();
            std::vector<std::vector<double> >               Tb  = het1d_->getBulkTemperature();
            std::vector<std::vector<double> >               Tw  = het1d_->getWallTemperature();
            std::vector<std::vector<std::vector<double> > > yb  = het1d_->getBulkSpecie();
            std::vector<std::vector<std::vector<double> > > yw  = het1d_->getWallSpecie();
            std::vector<std::vector<std::vector<double> > > Z   = het1d_->getSite();
            double                                          dz  = L_/double(NP_- 1);

            if ( kineticTypeCombo_.get_active_text() == "ASALI" )
            {
                //Conversion from mass to mole
                std::vector<std::vector<std::vector<double> > > moleb = het1d_->getBulkSpecie();
                std::vector<std::vector<std::vector<double> > > molew = het1d_->getWallSpecie();
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
                                    x = canteraInterface_->moleFractions();

                                    for (unsigned int i=0;i<n_.size();i++)
                                    {
                                        moleb[j][k][i] = x[i];
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
                                    x = canteraInterface_->moleFractions();

                                    for (unsigned int i=0;i<n_.size();i++)
                                    {
                                        molew[j][k][i] = x[i];
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
            else if ( kineticTypeCombo_.get_active_text() == "CANTERA" )
            {
                //Conversion from mass to mole
                std::vector<std::vector<std::vector<double> > > moleb = het1d_->getBulkSpecie();
                std::vector<std::vector<std::vector<double> > > molew = het1d_->getWallSpecie();
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
            std::cout << "Unexpected button clicked." << std::endl;
            break;
        }
    }
}

void Asali::het1dRun()
{
    if ( kineticTypeCombo_.get_active_row_number() == 0)
    {
        het1d_->setCanteraThermo(thermo_);
        het1d_->setCanteraTransport(transport_);
        het1d_->setCanteraInterface(surface_);
        het1d_->setCanteraKinetics(kinetic_);
        het1d_->turnOnUserDefined(false);
    }
    else if ( kineticTypeCombo_.get_active_row_number() == 1)
    {
        if ( kineticType_ == "none" )
        {
            het1d_->turnOnUserDefined(true);
            het1d_->setAsaliKinetic(asaliKinetic_->get_NR(),
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
            het1d_->set_MW(asaliProperties_->get_MW());
            het1d_->set_QfromSurface(asaliProperties_->get_Q());
            het1d_->set_cp(asaliProperties_->get_cp());
            het1d_->set_cond(asaliProperties_->get_cond());
            het1d_->set_diff(asaliProperties_->get_diff());
            het1d_->set_mu(asaliProperties_->get_mu());
        }
        else
        {
            het1d_->setCanteraThermo(thermo_);
            het1d_->setCanteraTransport(transport_);
            het1d_->turnOnUserDefined(false);
            het1d_->setAsaliKinetic(asaliKinetic_->get_NR(),
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

    het1d_->setKineticType(kineticTypeCombo_.get_active_text());
    het1d_->setNumberOfPoints(NP_);
    het1d_->setReactorType(reactorType_);
    het1d_->setLength(L_);

    if ( reactorType_ == "tubular" )
    {
        het1d_->setTubular(Dt_,tw_,section_);
    }
    else if ( reactorType_ == "packed bed" )
    {
        het1d_->setPackedBed(Dt_,Dp_,epsi_);
    }
    else if ( reactorType_ == "honeycomb" )
    {
        het1d_->setHoneyComb(cpsi_,tw_,section_);
    }

    het1d_->resize();
    het1d_->setHomogeneusReactions(false);
    het1d_->setHeterogeneusReactions(true);
        
    if ( energy_ == "on" )
    {
        het1d_->setEnergy(true);
    }
    else if ( energy_ == "off" )
    {
        het1d_->setEnergy(false);
    }
        
    het1d_->setPressure(p_);
    het1d_->setCatalystProperties(asaliCatalystProperties_->get_load(),
                                  asaliCatalystProperties_->get_rho(),
                                  asaliCatalystProperties_->get_cp(),
                                  asaliCatalystProperties_->get_cond());

    std::vector<double> x0(het1d_->NumberOfEquations());
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
                het1d_->setInert(i);
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

        het1d_->setSpecificMassFlowRate(v_*p_*MWmix/(8314.*T_));
        het1d_->setInletConditions(xInlet,T_);
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
                if ( n_[i] == inert_ )
                {
                    het1d_->setInert(i);
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
            het1d_->setSpecificMassFlowRate(v_*canteraInterface_->density());
            het1d_->setInletConditions(xInlet,T_);
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
                        het1d_->setInert(i);
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

            het1d_->setSpecificMassFlowRate(v_*canteraInterface_->density());
            het1d_->setInletConditions(xInlet,T_);
        }
    }

    ASALI::Het1DodeInterface ode;
    ode.setEquations(het1d_);

    het1d_->setResolutionType("initial");
    this->het1dBar(0.,"Starting...");

    for (unsigned int i=0;i<2;i++)
    {
        //Update solving bar
        if ( i == 0 )
        {
            ode.setInitialConditions(0.,x0);
            ode.solve(1e-07,x0);
            this->het1dBar(0.,"Starting...");
        }
        else if ( i == 1 )
        {
            ode.setInitialConditions(1e-07,x0);
            ode.solve(1e07,x0);
            this->het1dBar(1e-05,"Starting...");
        }

        if (!ode.check())
        {
            break;
        }
    }

    ASALI::Het1DbvpInterface bvp;
    bvp.setEquations(het1d_);
    bvp.setBandDimensions(het1d_->NumberOfEquations()/NP_ + 1,het1d_->NumberOfEquations()/NP_ + 1);

    het1d_->setResolutionType("model");
    het1d_->store(0.,x0);
    this->het1dBar(1e-05,"Starting...");

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

            bvp.setInitialConditions(ti,x0);
            bvp.solve(tf,x0);

            td += dt;
            
            if ( std::fabs(td - dt_) < dt*0.001 )
            {
                het1d_->store(tf,x0);
                td = 0.;
            }

            tm   = ((std::clock() - t1)/(double)CLOCKS_PER_SEC)*Nt/(i+1) - std::clock()/(double)CLOCKS_PER_SEC;
            hour = tm/3600;
            tm   = tm%3600;
            min  = tm/60;
            tm   = tm%60;
            sec  = tm;

            ti = tf;

            this->het1dBar(double(i+1)*dt/tf_,"Remaning time: " + std::to_string(std::abs(hour))
                                                                + ":" 
                                                                + std::to_string(std::abs(min)) 
                                                                + ":" 
                                                                + std::to_string(std::abs(sec)));

            if (!het1dBar_->check() || !bvp.check())
            {
                break;
            }
        }
    }

    het1dBar_->exit();

    if ( ode.check()        == true &&
         bvp.check()        == true &&
         het1dBar_->check() == true)
    {
        this->het1dSave();
    }
}

void Asali::het1dBar(const double fraction,const std::string tm)
{
    //Update solving bar
    while( Gtk::Main::events_pending() )
    {
        Gtk::Main::iteration();
    }

    het1dBar_->update(fraction,tm);
    het1dBar_->show();

    //Update solving bar
    while( Gtk::Main::events_pending() )
    {
        Gtk::Main::iteration();
    }
}

void Asali::het1dReader()
{
    L_     = Glib::Ascii::strtod(het1dLengthEntry_.get_text());
    v_     = Glib::Ascii::strtod(het1dVelocityEntry_.get_text());
    tf_    = Glib::Ascii::strtod(het1dTimeEntry_.get_text());
    dt_    = Glib::Ascii::strtod(het1dSaveEntry_.get_text());
    NP_    = Glib::Ascii::strtod(het1dPointsEntry_.get_text());

    ConvertsToMeter(L_,het1dLengthCombo_.get_active_text());
    ConvertsToMeterPerSecond(v_,het1dVelocityCombo_.get_active_text());
    ConvertsToSecond(tf_,het1dTimeCombo_.get_active_text());
    ConvertsToSecond(dt_,het1dSaveCombo_.get_active_text());

    reactorType_ = het1dReactorTypeCombo_.get_active_text();
    energy_      = het1dEnergyCombo_.get_active_text();
    inert_       = het1dInertEntry_.get_text();
    asaliProperties_->convertToCaption(inert_);
    
    if ( het1dReactorTypeCombo_.get_active_row_number() == 0 )
    {
        Dt_ = Glib::Ascii::strtod(het1dTubularTubeEntry_.get_text());

        ConvertsToMeter(Dt_,het1dTubularTubeCombo_.get_active_text());

        section_ = het1dTubularDuctCombo_.get_active_text();
        
        tw_      = Glib::Ascii::strtod(het1dTubularWallThicknessEntry_.get_text());

        ConvertsToMeter(tw_,het1dTubularWallThicknessCombo_.get_active_text());
    }
    else if ( het1dReactorTypeCombo_.get_active_row_number() == 1 )
    {
        Dt_   = Glib::Ascii::strtod(het1dPackedBedTubeEntry_.get_text());
        Dp_   = Glib::Ascii::strtod(het1dPackedBedParticleEntry_.get_text());
        epsi_ = Glib::Ascii::strtod(het1dPackedBedVoidFractionEntry_.get_text());

        ConvertsToMeter(Dt_,het1dPackedBedTubeCombo_.get_active_text());
        ConvertsToMeter(Dp_,het1dPackedBedParticleCombo_.get_active_text());
    }
    else if ( het1dReactorTypeCombo_.get_active_row_number() == 2 )
    {
        cpsi_    = Glib::Ascii::strtod(het1dHoneyCombCPSIEntry_.get_text());
        tw_      = Glib::Ascii::strtod(het1dHoneyCombWallThicknessEntry_.get_text());

        ConvertsToMeter(tw_,het1dHoneyCombWallThicknessCombo_.get_active_text());

        section_ = het1dHoneyCombDuctCombo_.get_active_text();
    }
}

void Asali::het1dCoverage()
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
        this->set_title("ASALI: 1D HET reactors");
        
        //Add thermo menu grid
        this->add(coverageBox_);
        
        if ( coverage_ == "het1d" )
        {
            coverageInputGrid_.remove(*backButton_[29]);
            coverageInputGrid_.remove(*nextButton_[29]);
            coverageInputGrid_.attach(*backButton_[29],0,SURF_NS_,1,1);
            coverageInputGrid_.attach(*nextButton_[29],1,SURF_NS_,1,1);
            coverage_ = "het1d";
        }
        else
        {
            coverageInputGrid_.attach(*backButton_[29],0,SURF_NS_,1,1);
            coverageInputGrid_.attach(*nextButton_[29],1,SURF_NS_,1,1);
            coverage_ = "het1d";
        }
        
        //Resize
        this->resize(coverageBox_.get_width(),coverageBox_.get_height());

        this->show_all_children();
    }
}

void Asali::het1dReactorOptions(bool check)
{
    if ( het1dReactor_ == "honeycomb" )
    {
        het1dPropertiesGrid_.remove(het1dHoneyCombCPSILabel_);
        het1dPropertiesGrid_.remove(het1dHoneyCombCPSIEntry_);
        het1dPropertiesGrid_.remove(het1dHoneyCombWallThicknessLabel_);
        het1dPropertiesGrid_.remove(het1dHoneyCombWallThicknessEntry_);
        het1dPropertiesGrid_.remove(het1dHoneyCombWallThicknessCombo_);
        het1dPropertiesGrid_.remove(het1dHoneyCombDuctLabel_);
        het1dPropertiesGrid_.remove(het1dHoneyCombDuctCombo_);

    }
    else if ( het1dReactor_ == "tubular" )
    {
        het1dPropertiesGrid_.remove(het1dTubularTubeLabel_);
        het1dPropertiesGrid_.remove(het1dTubularTubeEntry_);
        het1dPropertiesGrid_.remove(het1dTubularTubeCombo_);

        het1dPropertiesGrid_.remove(het1dTubularDuctLabel_);
        het1dPropertiesGrid_.remove(het1dTubularDuctCombo_);
        
        het1dPropertiesGrid_.remove(het1dTubularWallThicknessLabel_);
        het1dPropertiesGrid_.remove(het1dTubularWallThicknessEntry_);
        het1dPropertiesGrid_.remove(het1dTubularWallThicknessCombo_);

    }
    else if ( het1dReactor_ == "packedBed" )
    {
        het1dPropertiesGrid_.remove(het1dPackedBedTubeLabel_);
        het1dPropertiesGrid_.remove(het1dPackedBedTubeEntry_);
        het1dPropertiesGrid_.remove(het1dPackedBedTubeCombo_);
        het1dPropertiesGrid_.remove(het1dPackedBedParticleLabel_);
        het1dPropertiesGrid_.remove(het1dPackedBedParticleEntry_);
        het1dPropertiesGrid_.remove(het1dPackedBedParticleCombo_);
        het1dPropertiesGrid_.remove(het1dPackedBedVoidFractionLabel_);
        het1dPropertiesGrid_.remove(het1dPackedBedVoidFractionEntry_);
    }

    het1dBeerLabel_.set_text(this->getBeerShort());
    het1dBeerLabel_.set_use_markup(true);
    het1dBeerLabel_.set_justify(Gtk::JUSTIFY_CENTER);

    if ( het1dReactorTypeCombo_.get_active_row_number() == 0 )
    {
        het1dPropertiesGrid_.attach(het1dTubularTubeLabel_,0,4,1,1);
        het1dPropertiesGrid_.attach(het1dTubularTubeEntry_,1,4,1,1);
        het1dPropertiesGrid_.attach(het1dTubularTubeCombo_,2,4,1,1);

        het1dPropertiesGrid_.attach(het1dTubularWallThicknessLabel_,0,5,1,1);
        het1dPropertiesGrid_.attach(het1dTubularWallThicknessEntry_,1,5,1,1);
        het1dPropertiesGrid_.attach(het1dTubularWallThicknessCombo_,2,5,1,1);


        het1dPropertiesGrid_.attach(het1dTubularDuctLabel_,0,6,1,1);
        het1dPropertiesGrid_.attach(het1dTubularDuctCombo_,1,6,1,1);

        het1dReactor_ = "tubular";
    }
    else if ( het1dReactorTypeCombo_.get_active_row_number() == 1 )
    {
        het1dPropertiesGrid_.attach(het1dPackedBedTubeLabel_,0,4,1,1);
        het1dPropertiesGrid_.attach(het1dPackedBedTubeEntry_,1,4,1,1);
        het1dPropertiesGrid_.attach(het1dPackedBedTubeCombo_,2,4,1,1);

        het1dPropertiesGrid_.attach(het1dPackedBedParticleLabel_,0,5,1,1);
        het1dPropertiesGrid_.attach(het1dPackedBedParticleEntry_,1,5,1,1);
        het1dPropertiesGrid_.attach(het1dPackedBedParticleCombo_,2,5,1,1);

        het1dPropertiesGrid_.attach(het1dPackedBedVoidFractionLabel_,0,6,1,1);
        het1dPropertiesGrid_.attach(het1dPackedBedVoidFractionEntry_,1,6,1,1);

        het1dReactor_ = "packedBed";
    }
    else if ( het1dReactorTypeCombo_.get_active_row_number() == 2 )
    {

        het1dPropertiesGrid_.attach(het1dHoneyCombCPSILabel_,0,4,1,1);
        het1dPropertiesGrid_.attach(het1dHoneyCombCPSIEntry_,1,4,1,1);

        het1dPropertiesGrid_.attach(het1dHoneyCombWallThicknessLabel_,0,5,1,1);
        het1dPropertiesGrid_.attach(het1dHoneyCombWallThicknessEntry_,1,5,1,1);
        het1dPropertiesGrid_.attach(het1dHoneyCombWallThicknessCombo_,2,5,1,1);

        het1dPropertiesGrid_.attach(het1dHoneyCombDuctLabel_,0,6,1,1);
        het1dPropertiesGrid_.attach(het1dHoneyCombDuctCombo_,1,6,1,1);

        het1dReactor_ = "honeycomb";
    }
    
    this->resize(het1dMainBox_.get_width(),het1dMainBox_.get_height());
    this->show_all_children();
}

void Asali::het1dPlot()
{
    asaliPlot_->setTime(het1d_->getTime());

    if ( kineticTypeCombo_.get_active_text() == "ASALI" )
    {
        std::vector<double>                             t   = het1d_->getTime();
        std::vector<std::vector<double> >               Tb  = het1d_->getBulkTemperature();
        std::vector<std::vector<double> >               Tw  = het1d_->getWallTemperature();
        std::vector<std::vector<std::vector<double> > > yb  = het1d_->getBulkSpecie();
        std::vector<std::vector<std::vector<double> > > yw  = het1d_->getWallSpecie();

        //Conversion from mass to mole
        std::vector<std::vector<std::vector<double> > > moleb = het1d_->getBulkSpecie();
        std::vector<std::vector<std::vector<double> > > molew = het1d_->getWallSpecie();
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
                            x = canteraInterface_->moleFractions();

                            for (unsigned int i=0;i<n_.size();i++)
                            {
                                moleb[j][k][i] = x[i];
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
                            x = canteraInterface_->moleFractions();

                            for (unsigned int i=0;i<n_.size();i++)
                            {
                                molew[j][k][i] = x[i];
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
    else if ( kineticTypeCombo_.get_active_text() == "CANTERA" )
    {
        std::vector<double>                             t   = het1d_->getTime();
        std::vector<std::vector<double> >               Tb  = het1d_->getBulkTemperature();
        std::vector<std::vector<double> >               Tw  = het1d_->getWallTemperature();
        std::vector<std::vector<std::vector<double> > > yb  = het1d_->getBulkSpecie();
        std::vector<std::vector<std::vector<double> > > yw  = het1d_->getWallSpecie();

        //Conversion from mass to mole
        std::vector<std::vector<std::vector<double> > > moleb = het1d_->getBulkSpecie();
        std::vector<std::vector<std::vector<double> > > molew = het1d_->getWallSpecie();
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
        asaliPlot_->setSite(het1d_->getSite());
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
        asaliPlot_->setLength(l);
    }

    asaliPlot_->setType("het1d");
    asaliPlot_->build();
    asaliPlot_->show();
}
