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

void Asali::equilibriumMenu()
{
    if ( kineticType_ == "none" )
    {
        this->noneInputError();
    }
    else
    {
        //Clean the window
        this->remove();
        this->set_title("ASALI: Thermodynamic equilibrium");
        
        //Add thermo menu grid
        this->add(inputGrid_);
        
        if ( window_ == "transport" )
        {
            this->cleanTransport();
            inputGrid_.remove(doneTransportButton_);
            inputGrid_.attach(*nextButton_[2],2,13,1,1);
            window_ = "equilibriumMenu";
        }
        else if ( window_ == "thermo" )
        {
            this->cleanThermo();
            inputGrid_.remove(doneThermoButton_);
            inputGrid_.attach(*nextButton_[2],2,13,1,1);
            window_ = "equilibriumMenu";
        }
        else if ( window_ == "all" )
        {
            this->cleanAll();
            inputGrid_.remove(doneAllButton_);
            inputGrid_.attach(*nextButton_[2],2,13,1,1);
            window_ = "equilibriumMenu";
        }
        else if ( window_ == "transportMenu" )
        {
            inputGrid_.remove(doneTransportButton_);
            inputGrid_.attach(*nextButton_[2],2,13,1,1);
            window_ = "equilibriumMenu";
        }
        else if ( window_ == "allMenu" )
        {
            inputGrid_.remove(doneAllButton_);
            inputGrid_.attach(*nextButton_[2],2,13,1,1);
            window_ = "equilibriumMenu";
        }
        else if ( window_ == "thermoMenu" )
        {
            inputGrid_.remove(doneThermoButton_);
            inputGrid_.attach(*nextButton_[2],2,13,1,1);
            window_ = "equilibriumMenu";
        }
        else if ( window_ == "equilibriumMenu" )
        {
            inputGrid_.remove(*nextButton_[2]);
            inputGrid_.attach(*nextButton_[2],2,13,1,1);
            window_ = "equilibriumMenu";
        }
        else if ( window_ == "equilibrium" )
        {
            equilibriumGrid_.remove(*backButton_[8]);
            equilibriumGrid_.remove(*exitButton_[8]);
            equilibriumGrid_.remove(equilibriumSaveButton_);
            inputGrid_.remove(*nextButton_[2]);
            inputGrid_.attach(*nextButton_[2],2,13,1,1);
            window_ = "equilibriumMenu";
        }
        else if ( window_ == "batchMenu" )
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
            window_ = "equilibriumMenu";
        }
        else
        {
            inputGrid_.attach(*nextButton_[2],2,13,1,1);
            window_ = "equilibriumMenu";
        }

        //Resize
        this->resize(inputGrid_.get_width(),inputGrid_.get_height ());
        this->show_all_children();
    }
}

void Asali::equilibriumResults()
{
    window_ = "equilibrium";
    this->inputReader();

    if ( checkInput_.second == false )
    {
        this->checkInput(checkInput_.first);
    }
    else
    {
       
        this->equilibriumRun();

        equilibriumGrid_.attach(*backButton_[8],0,n_.size()+3,1,1);
        equilibriumGrid_.attach(equilibriumSaveButton_,1,n_.size()+3,1,1);
        equilibriumGrid_.attach(*exitButton_[8],2,n_.size()+3,1,1);

        this->remove();
        this->add(equilibriumGrid_);
        this->showAtomNames();
        this->initialFractionUnitConversion();
        this->finalFractionUnitConversion();
        this->resize(equilibriumGrid_.get_width(),equilibriumGrid_.get_height());
        this->show_all_children();
    }
}

void Asali::equilibriumRun()
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

    if ( equilibriumCombo_.get_active_row_number() == 0 )
    {
        canteraInterface_->equilibriumCalculate("TP");
    }
    else if ( equilibriumCombo_.get_active_row_number() == 1 )
    {
        canteraInterface_->equilibriumCalculate("HP");
    }

    xeq_.clear();
    yeq_.clear();
    xeq_.resize(n_.size());
    yeq_.resize(n_.size());
    {
        std::vector<double> x = canteraInterface_->moleFractions();
        std::vector<double> y = canteraInterface_->massFractions();
        
        for (unsigned int i=0;i<n_.size();i++)
        {
            for (unsigned int j=0;j<canteraInterface_->nSpecies();j++)
            {
                if ( n_[i] == canteraInterface_->names()[j] )
                {
                    xeq_[i] = x[j];
                    yeq_[i] = y[j];
                    break;
                }
            }
        }
    }

    Teq_ = canteraInterface_->Temperature();

    this->initialFractionUnitConversion();
    this->finalFractionUnitConversion();
    this->show_all_children();

}

void Asali::finalFractionUnitConversion()
{
    if ( finalFractionVector_.size() != 0 )
    {
        for (unsigned int i=0;i<finalFractionVector_.size();i++)
        {
            equilibriumGrid_.remove(*finalFractionVector_[i]);
        }
    }
    
    finalFractionVector_.clear();
    finalFractionVector_.resize(n_.size()+1);

    if ( finalFractionCombo_.get_active_row_number() == 0 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            std::stringstream mole;
            mole << std::scientific << std::setprecision(OP_) << xeq_[i];
            finalFractionVector_[i] = new Gtk::Label(mole.str());
            equilibriumGrid_.attach(*finalFractionVector_[i],2,i+2,1,1);
        }
    }
    else if ( finalFractionCombo_.get_active_row_number() == 1 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            std::stringstream mass;
            mass << std::scientific << std::setprecision(OP_) << yeq_[i];
            finalFractionVector_[i] = new Gtk::Label(mass.str());
            equilibriumGrid_.attach(*finalFractionVector_[i],2,i+2,1,1);
        }
    }

    std::stringstream T;
    T << std::scientific << std::setprecision(OP_) << Teq_;
    finalFractionVector_[n_.size()] = new Gtk::Label(T.str());
    equilibriumGrid_.attach(*finalFractionVector_[n_.size()],2,n_.size()+2,1,1);
    
    this->show_all_children();
}

void Asali::initialFractionUnitConversion()
{
    if ( initialFractionVector_.size() != 0 )
    {
        for (unsigned int i=0;i<initialFractionVector_.size();i++)
        {
            equilibriumGrid_.remove(*initialFractionVector_[i]);
        }
    }
    
    initialFractionVector_.clear();
    initialFractionVector_.resize(n_.size()+1);

    if ( initialFractionCombo_.get_active_row_number() == 0 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            std::stringstream mole;
            mole << std::scientific << std::setprecision(OP_) << x_[i];
            initialFractionVector_[i] = new Gtk::Label(mole.str());
            equilibriumGrid_.attach(*initialFractionVector_[i],1,i+2,1,1);
        }
    }
    else if ( initialFractionCombo_.get_active_row_number() == 1 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            std::stringstream mass;
            mass << std::scientific << std::setprecision(OP_) << y_[i];
            initialFractionVector_[i] = new Gtk::Label(mass.str());
            equilibriumGrid_.attach(*initialFractionVector_[i],1,i+2,1,1);
        }
    }
    
    std::stringstream T;
    T << std::scientific << std::setprecision(OP_) << T_;
    initialFractionVector_[n_.size()] = new Gtk::Label(T.str());
    equilibriumGrid_.attach(*initialFractionVector_[n_.size()] ,1,n_.size()+2,1,1);

    this->show_all_children();
}

void Asali::equilibriumSave()
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
            
            output << "Pressure:        " << p_ << " Pa" << std::endl;
            output << std::endl;
            output.setf(std::ios::scientific);
            output.precision(6);

            output << "Mole fraction" << std::endl;
            output << "Species\tInitial\tEquilibrium" << std::endl;
            for (unsigned int i=0;i<n_.size();i++)
            {
                output << n_[i] << "\t" << x_[i] << "\t" << xeq_[i] << std::endl;
            }
            output << "Temperature[K]" << "\t" << T_ << "\t" << Teq_ << std::endl;
            output << std::endl;
            output << "Mass fraction" << std::endl;
            output << "Species\tInitial\tEquilibrium" << std::endl;
            for (unsigned int i=0;i<n_.size();i++)
            {
                output << n_[i] << "\t" << y_[i] << "\t" << yeq_[i] << std::endl;
            }
            output << "Temperature[K]" << "\t" << T_ << "\t" << Teq_ << std::endl;
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
