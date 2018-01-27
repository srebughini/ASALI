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

void Asali::vacuumMenu()
{
    if ( kineticType_ == "none" )
    {
        this->noneInputError();
    }
    else
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
}

void Asali::vacuumRun()
{
    if ( diffK_ >= 0. )
    {
        vacuumGrid_.remove(*vacuumDiffResults_);
    }

    if ( Kn_ >= 0. )
    {
        vacuumGrid_.remove(*vacuumKnuResults_);
    }
    
    if ( vK_ >= 0. )
    {
        vacuumGrid_.remove(*vacuumVelocityResults_);
    }

    if ( lK_ >= 0. )
    {
        vacuumGrid_.remove(*vacuumPathResults_);
    }

    this->vacuumReader();

    if ( checkInput_.second == false )
    {
        this->checkInput(checkInput_.first);
    }
    else
    {
        canteraInterface_->setTemperature(T_);
        canteraInterface_->setPressure(p_);
        canteraInterface_->setMoleFraction(x_,n_);
        canteraInterface_->vacuumCalculate();
        
        {
            std::vector<double> vm = canteraInterface_->vm();
            std::vector<double> l  = canteraInterface_->l();

            for (unsigned int i=0;i<n_.size();i++)
            {
                for (unsigned int j=0;j<canteraInterface_->nSpecies();j++)
                {
                    if ( n_[i] == canteraInterface_->names()[j] )
                    {
                        lK_ = l[j];
                        vK_ = vm[j];
                        break;
                    }
                }
            }

            Kn_    = d_/lK_;

            if ( Kn_ < 1. ) //molecular
            {
                diffK_ = vK_*d_/3.;
            }
            else //viscous
            {
                canteraInterface_->transportCalculate();
                for (unsigned int i=0;i<n_.size();i++)
                {
                    for (unsigned int j=0;j<canteraInterface_->names().size();j++)
                    {
                        if ( n_[i] == canteraInterface_->names()[j] )
                        {
                            vK_    = vm[j];
                            for (unsigned int k=0;k<n_.size();k++)
                            {
                                for (unsigned int h=0;h<canteraInterface_->names().size();h++)
                                {
                                    if ( n_[k] == canteraInterface_->names()[h] )
                                    {
                                        diffK_ = canteraInterface_->diff()[j][h];
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }

        if ( vacuumDiffCombo_.get_active_row_number() == 1 )
        {
            diffK_ = diffK_*1e04; 
        }
        
        if ( vacuumVelocityCombo_.get_active_row_number() == 0 )
        {
            vK_ = vK_*1e-03;
        }
        else if ( vacuumVelocityCombo_.get_active_row_number() == 1 )
        {
            vK_ = vK_;
        }
        else if ( vacuumVelocityCombo_.get_active_row_number() == 2 )
        {
            vK_ = vK_*1e02;
        }
        

        if ( vacuumPathCombo_.get_active_row_number() == 0 )
        {
            lK_ = lK_*1e-03;
        }
        else if ( vacuumPathCombo_.get_active_row_number() == 1 )
        {
            lK_ = lK_;
        }
        else if ( vacuumPathCombo_.get_active_row_number() == 2 )
        {
            lK_ = lK_*1e01;
        }
        else if ( vacuumPathCombo_.get_active_row_number() == 3 )
        {
            lK_ = lK_*1e02;
        }
        else if ( vacuumPathCombo_.get_active_row_number() == 4 )
        {
            lK_ = lK_*1e03;
        }
        else if ( vacuumPathCombo_.get_active_row_number() == 5 )
        {
            lK_ = lK_*1e06;
        }
        else if ( vacuumPathCombo_.get_active_row_number() == 6 )
        {
            lK_ = lK_*1e09;
        }
        else if ( vacuumPathCombo_.get_active_row_number() == 7 )
        {
            lK_ = lK_*1e12;
        }


        {
            std::stringstream diffK;
            diffK << std::scientific << std::setprecision(OP_) << diffK_;
            vacuumDiffResults_ = new Gtk::Label(diffK.str());
        }
        
        {
            std::stringstream Kn;
            Kn << std::scientific << std::setprecision(OP_) << 1./Kn_;
            
            if ( Kn_ < 1. )
            {              
                vacuumKnuResults_ = new Gtk::Label(Kn.str()+" (molecular)");
            }
            else
            {
                vacuumKnuResults_ = new Gtk::Label(Kn.str()+" (viscous)");
            }
        }

        {
            std::stringstream vK;
            vK << std::scientific << std::setprecision(OP_) << vK_;
            vacuumVelocityResults_ = new Gtk::Label(vK.str());
        }

        {
            std::stringstream lK;
            lK << std::scientific << std::setprecision(OP_) << lK_;
            vacuumPathResults_ = new Gtk::Label(lK.str());
        }

        vacuumGrid_.attach(*vacuumDiffResults_,0,3,1,1);
        vacuumGrid_.attach(*vacuumVelocityResults_,1,3,1,1);
        vacuumGrid_.attach(*vacuumPathResults_,2,3,1,1);
        vacuumGrid_.attach(*vacuumKnuResults_,3,3,1,1);

        this->show_all_children();
    }
}

void Asali::vacuumSave()
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

void Asali::vacuumReader()
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

    std::vector<int> check = canteraInterface_->checkNames(n_);

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
