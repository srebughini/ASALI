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

void Asali::allMenu()
{
    if ( kineticType_ == "none" )
    {
        this->noneInputError();
    }
    else
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
        else if ( window_ == "equilibriumMenu" )
        {
            inputGrid_.remove(*nextButton_[2]);
            inputGrid_.attach(doneAllButton_,2,13,1,1);
            window_ = "allMenu";
        }
        else if ( window_ == "equilibrium" )
        {
            equilibriumGrid_.remove(*backButton_[8]);
            equilibriumGrid_.remove(*exitButton_[8]);
            equilibriumGrid_.remove(equilibriumSaveButton_);
            inputGrid_.remove(*nextButton_[2]);
            inputGrid_.attach(doneAllButton_,2,13,1,1);
            window_ = "allMenu";
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
            inputGrid_.attach(doneAllButton_,2,13,1,1);
            window_ = "allMenu";
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
}

void Asali::cleanAll()
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

void Asali::allResults()
{
    window_ = "all";
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
        canteraInterface_->transportCalculate();

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


        //Transport/Thermo
        {
            mu_.clear();
            cond_.clear();
            diff_.clear();
            cp_.clear();
            h_.clear();
            s_.clear();
            MW_.clear();

            mu_.resize(n_.size());
            cond_.resize(n_.size());
            diff_.resize(n_.size());
            cp_.resize(n_.size());
            s_.resize(n_.size());
            h_.resize(n_.size());
            MW_.resize(n_.size());

            for (unsigned int i=0;i<n_.size();i++)
            {
                diff_[i].resize(n_.size());
            }
            
            for (unsigned int i=0;i<n_.size();i++)
            {
                for (unsigned int j=0;j<canteraInterface_->names().size();j++)
                {
                    if ( n_[i] == canteraInterface_->names()[j] )
                    {
                        mu_[i]    = canteraInterface_->mu()[j];
                        cond_[i]  = canteraInterface_->cond()[j];
                        MW_[i]    = canteraInterface_->MW()[j];
                        h_[i]     = canteraInterface_->h()[j];
                        s_[i]     = canteraInterface_->s()[j];
                        cp_[i]    = canteraInterface_->cp()[j];
                        for (unsigned int k=0;k<n_.size();k++)
                        {
                            for (unsigned int h=0;h<canteraInterface_->names().size();h++)
                            {
                                if ( n_[k] == canteraInterface_->names()[h] )
                                {
                                    diff_[i][k] = canteraInterface_->diff()[j][h];
                                    break;
                                }
                            }
                        }
                        break;
                    }
                }
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

void Asali::allSave()
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
