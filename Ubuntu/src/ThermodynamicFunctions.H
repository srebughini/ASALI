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
#   Department of Energy                                                                       #
#   Politecnico di Milano                                                                      #
#   Author: Stefano Rebughini <stefano.rebughini@polimi.it>                                    #
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

void Asali::thermoMenu()
{
    if ( kineticType_ == "none" )
    {
        this->noneInputError();
    }
    else
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
        else if ( window_ == "equilibriumMenu" )
        {
            inputGrid_.remove(*nextButton_[2]);
            inputGrid_.attach(doneThermoButton_,2,13,1,1);
            window_ = "thermoMenu";
        }
        else if ( window_ == "equilibrium" )
        {
            equilibriumGrid_.remove(*backButton_[8]);
            equilibriumGrid_.remove(*exitButton_[8]);
            equilibriumGrid_.remove(equilibriumSaveButton_);
            inputGrid_.remove(*nextButton_[2]);
            inputGrid_.attach(doneThermoButton_,2,13,1,1);
            window_ = "thermoMenu";
        }
        else if ( window_ == "batchMenuAsali" )
        {
            inputGrid_.remove(*backButton_[11]);
            inputGrid_.remove(*nextButton_[11]);
            inputGrid_.remove(*mainMenuButton_[11]);
            inputGrid_.attach(*backButton_[0],0,13,1,1);
            if ( kineticType_ == "default" )
            {
                inputGrid_.attach(helpButton_,1,13,1,1);
            }
            inputGrid_.attach(doneThermoButton_,2,13,1,1);
            window_ = "thermoMenu";
        }
        else if ( window_ == "batchMenuCantera" )
        {
            inputGrid_.remove(*backButton_[13]);
            inputGrid_.remove(*nextButton_[13]);
            inputGrid_.remove(*mainMenuButton_[13]);
            inputGrid_.attach(*backButton_[0],0,13,1,1);
            if ( kineticType_ == "default" )
            {
                inputGrid_.attach(helpButton_,1,13,1,1);
            }
            inputGrid_.attach(doneThermoButton_,2,13,1,1);
            window_ = "thermoMenu";
        }
        else if ( window_ == "ph1dMenuAsali" )
        {
            inputGrid_.remove(*backButton_[16]);
            inputGrid_.remove(*nextButton_[16]);
            inputGrid_.remove(*mainMenuButton_[16]);
            inputGrid_.attach(*backButton_[0],0,13,1,1);
            if ( kineticType_ == "default" )
            {
                inputGrid_.attach(helpButton_,1,13,1,1);
            }
            inputGrid_.attach(doneThermoButton_,2,13,1,1);
            window_ = "thermoMenu";
        }
        else if ( window_ == "ph1dMenuCantera" )
        {
            inputGrid_.remove(*backButton_[17]);
            inputGrid_.remove(*nextButton_[17]);
            inputGrid_.remove(*mainMenuButton_[17]);
            inputGrid_.attach(*backButton_[0],0,13,1,1);
            if ( kineticType_ == "default" )
            {
                inputGrid_.attach(helpButton_,1,13,1,1);
            }
            inputGrid_.attach(doneThermoButton_,2,13,1,1);
            window_ = "thermoMenu";
        }
        else if ( window_ == "cstrMenuCantera" )
        {
            inputGrid_.remove(*backButton_[23]);
            inputGrid_.remove(*mainMenuButton_[23]);
            inputGrid_.remove(*nextButton_[23]);
            inputGrid_.attach(*backButton_[0],0,13,1,1);
            if ( kineticType_ == "default" )
            {
                inputGrid_.attach(helpButton_,1,13,1,1);
            }
            inputGrid_.attach(doneThermoButton_,2,13,1,1);
            window_ = "thermoMenu";
        }
        else if ( window_ == "cstrMenuAsali" )
        {
            inputGrid_.remove(*backButton_[22]);
            inputGrid_.remove(*mainMenuButton_[22]);
            inputGrid_.remove(*nextButton_[22]);
            inputGrid_.attach(*backButton_[0],0,13,1,1);
            if ( kineticType_ == "default" )
            {
                inputGrid_.attach(helpButton_,1,13,1,1);
            }
            inputGrid_.attach(doneThermoButton_,2,13,1,1);
            window_ = "thermoMenu";
        }
        else if ( window_ == "het1dMenuAsali" )
        {
            inputGrid_.remove(*backButton_[27]);
            inputGrid_.remove(*nextButton_[27]);
            inputGrid_.remove(*mainMenuButton_[27]);
            inputGrid_.attach(*backButton_[0],0,13,1,1);
            if ( kineticType_ == "default" )
            {
                inputGrid_.attach(helpButton_,1,13,1,1);
            }
            inputGrid_.attach(doneThermoButton_,2,13,1,1);
            window_ = "thermoMenu";
        }
        else if ( window_ == "het1dMenuCantera" )
        {
            inputGrid_.remove(*backButton_[28]);
            inputGrid_.remove(*nextButton_[28]);
            inputGrid_.remove(*mainMenuButton_[28]);
            inputGrid_.attach(*backButton_[0],0,13,1,1);
            if ( kineticType_ == "default" )
            {
                inputGrid_.attach(helpButton_,1,13,1,1);
            }
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
}

void Asali::thermoResults()
{
    window_ = "thermo";
    this->inputReader();
    if ( checkInput_.second == false )
    {
        this->checkInput(checkInput_.first);
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

        canteraInterface_->thermoCalculate();

        x_.clear();
        y_.clear();
        x_.resize(n_.size());
        y_.resize(n_.size());
        {
            std::vector<double> x = canteraInterface_->moleFractions();
            std::vector<double> y = canteraInterface_->massFractions();
            
            for (unsigned int i=0;i<n_.size();i++)
            {
                for (unsigned int j=0;j<canteraInterface_->nSpecies();j++)
                {
                    if ( n_[i] == canteraInterface_->names()[j] )
                    {
                        x_[i] = x[j];
                        y_[i] = y[j];
                        break;
                    }
                }
            }
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
        
        
        for (unsigned int i=0;i<n_.size();i++)
        {
            for (unsigned int j=0;j<canteraInterface_->names().size();j++)
            {
                if ( n_[i] == canteraInterface_->names()[j] )
                {
                    h_[i]  = canteraInterface_->h()[j];
                    s_[i]  = canteraInterface_->s()[j];
                    cp_[i] = canteraInterface_->cp()[j];
                    MW_[i] = canteraInterface_->MW()[j];
                    break;
                }
            }
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

void Asali::cleanThermo()
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

void Asali::thermoSave()
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


