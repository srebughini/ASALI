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

#include "vacuumProperties.hpp"

namespace ASALI
{
    vacuumProperties::vacuumProperties(ASALI::canteraInterface        *canteraInterface,
                                       ASALI::speciesPopup            *speciesNames,
                                       std::string                     kineticType)
    : transportProperties(canteraInterface,speciesNames,kineticType),
      exitButton_("Exit"),
      saveButton_("Save"),
      calculateButton_("Calculate"),
      helpButton_("Available species"),
      tempBox_(Gtk::ORIENTATION_VERTICAL),
      pressBox_(Gtk::ORIENTATION_VERTICAL),
      lengthBox_(Gtk::ORIENTATION_VERTICAL),
      diffBox_(Gtk::ORIENTATION_VERTICAL),
      velocityBox_(Gtk::ORIENTATION_VERTICAL),
      pathBox_(Gtk::ORIENTATION_VERTICAL),
      tempLabel_("Temperature"),
      pressLabel_("Pressure"),
      lengthLabel_("Length"),
      diffLabel_("Diffusivity"),
      specieLabel_("Specie"),
      knudsenLabel_("Knudsen number"),
      velocityLabel_("Mean gas velocity"),
      pathLabel_("Mean free path"),
      diffResults_("?"),
      velocityResults_("?"),
      pathResults_("?"),
      knudsenResults_("?"),
      kineticType_(kineticType),
      canteraInterface_(canteraInterface),
      speciesNames_(speciesNames)
    {
        this->remove();
        this->set_border_width(15);
        this->set_title("ASALI: Vacuum properties");
        this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
        this->set_icon_from_file("images/Icon.png");
        
        this->add(grid_);

        grid_.set_column_homogeneous(true);
        grid_.set_column_spacing(10);
        grid_.set_row_spacing(10);

        //Add species
        grid_.attach(specieLabel_,0,0,1,1);
        grid_.attach(specieEntry_,0,1,1,1);
        specieEntry_.set_max_length(10);
        specieEntry_.set_text("AR");

        //Add temperature selector
        grid_.attach(tempBox_,1,0,1,1);
        tempBox_.pack_start(tempLabel_, Gtk::PACK_SHRINK);
        tempBox_.pack_start(tempCombo_, Gtk::PACK_SHRINK);
        tempBox_.set_spacing(5);
        tempBox_.set_halign(Gtk::ALIGN_CENTER);
        tempCombo_.append("K");
        tempCombo_.append("°C");
        tempCombo_.append("°F");
        tempCombo_.set_active(0);
        grid_.attach(tempEntry_,1,1,1,1);
        tempEntry_.set_max_length(10);
        tempEntry_.set_text("298.15");

        //Add temperature selector
        grid_.attach(pressBox_,2,0,1,1);
        pressBox_.pack_start(pressLabel_, Gtk::PACK_SHRINK);
        pressBox_.pack_start(pressCombo_, Gtk::PACK_SHRINK);
        pressBox_.set_spacing(5);
        pressBox_.set_halign(Gtk::ALIGN_CENTER);
        pressCombo_.append("mbar");
        pressCombo_.append("mmHg");
        pressCombo_.append("torr");
        pressCombo_.append("Pa");
        pressCombo_.set_active(0);
        grid_.attach(pressEntry_,2,1,1,1);
        pressEntry_.set_max_length(10);
        pressEntry_.set_text("1");

        //Add length selector
        grid_.attach(lengthBox_,3,0,1,1);
        lengthBox_.pack_start(lengthLabel_, Gtk::PACK_SHRINK);
        lengthBox_.pack_start(lengthCombo_, Gtk::PACK_SHRINK);
        lengthBox_.set_spacing(5);
        lengthBox_.set_halign(Gtk::ALIGN_CENTER);
        lengthCombo_.append("km");
        lengthCombo_.append("m");
        lengthCombo_.append("dm");
        lengthCombo_.append("cm");
        lengthCombo_.append("mm");
        lengthCombo_.append("\u03BCm");
        lengthCombo_.append("nm");
        lengthCombo_.append("pm");
        lengthCombo_.set_active(1);
        grid_.attach(lengthEntry_,3,1,1,1);
        lengthEntry_.set_max_length(10);
        lengthEntry_.set_text("1");

        //Add diffusion selector
        grid_.attach(diffBox_,0,2,1,1);
        diffBox_.pack_start(diffLabel_, Gtk::PACK_SHRINK);
        diffBox_.pack_start(diffCombo_, Gtk::PACK_SHRINK);
        diffBox_.set_spacing(5);
        diffBox_.set_halign(Gtk::ALIGN_CENTER);
        diffCombo_.append("m\u00b2/s");
        diffCombo_.append("cm\u00b2/s");
        diffCombo_.set_active(0);
        diffCombo_.signal_changed().connect(sigc::mem_fun(*this,&vacuumProperties::run));

        //Add velocity selector
        grid_.attach(velocityBox_,1,2,1,1);
        velocityBox_.pack_start(velocityLabel_, Gtk::PACK_SHRINK);
        velocityBox_.pack_start(velocityCombo_, Gtk::PACK_SHRINK);
        velocityBox_.set_spacing(5);
        velocityBox_.set_halign(Gtk::ALIGN_CENTER);
        velocityCombo_.append("km/s");
        velocityCombo_.append("m/s");
        velocityCombo_.append("cm/s");
        velocityCombo_.set_active(1);
        velocityCombo_.signal_changed().connect(sigc::mem_fun(*this,&vacuumProperties::run));

        //Add path selector
        grid_.attach(pathBox_,2,2,1,1);
        pathBox_.pack_start(pathLabel_, Gtk::PACK_SHRINK);
        pathBox_.pack_start(pathCombo_, Gtk::PACK_SHRINK);
        pathBox_.set_spacing(5);
        pathBox_.set_halign(Gtk::ALIGN_CENTER);
        pathCombo_.append("km");
        pathCombo_.append("m");
        pathCombo_.append("dm");
        pathCombo_.append("cm");
        pathCombo_.append("mm");
        pathCombo_.append("\u03BCm");
        pathCombo_.append("nm");
        pathCombo_.append("pm");
        pathCombo_.set_active(1);
        pathCombo_.signal_changed().connect(sigc::mem_fun(*this,&vacuumProperties::run));


        //Add results
        grid_.attach(diffResults_,0,3,1,1);
        grid_.attach(velocityResults_,1,3,1,1);
        grid_.attach(pathResults_,2,3,1,1);
        grid_.attach(knudsenResults_,3,3,1,1);

        //Add Knudsen number
        grid_.attach(knudsenLabel_,3,2,1,1);
        grid_.attach(calculateButton_,0,5,1,1);
        grid_.attach(saveButton_,2,5,1,1);
        calculateButton_.signal_clicked().connect(sigc::mem_fun(*this,&vacuumProperties::run));
        saveButton_.signal_clicked().connect(sigc::mem_fun(*this,&vacuumProperties::save));
        grid_.attach(exitButton_,3,5,1,1);
        exitButton_.signal_clicked().connect(sigc::mem_fun(*this,&vacuumProperties::exit));

        //Add help button
        if ( kineticType_ == "default" )
        {
            grid_.attach(helpButton_,1,5,1,1);
            helpButton_.signal_clicked().connect(sigc::mem_fun(*this,&vacuumProperties::availableSpecies));
        }

        this->show_all_children();
    }

    vacuumProperties::~vacuumProperties()
    {
    }
    
    void vacuumProperties::read()
    {
        T_ = Glib::Ascii::strtod(tempEntry_.get_text());
        p_ = Glib::Ascii::strtod(pressEntry_.get_text());
        d_ = Glib::Ascii::strtod(lengthEntry_.get_text());

        ConvertsToKelvin(T_,tempCombo_.get_active_text());
        ConvertsToPascal(p_,pressCombo_.get_active_text());
        ConvertsToMeter(d_,lengthCombo_.get_active_text());
        
        n_.resize(1);
        x_.resize(1);
        
        n_[0] = specieEntry_.get_text().c_str();
        x_[0] = 1.;

        if ( x_.size() != n_.size() )
        {
            checkInput_.first  = 4445;
            checkInput_.second = false;
        }
        else
        {
            if ( kineticType_ == "default" ||
                 kineticType_ == "load"    ||
                 kineticType_ == "nokinetic")
            {
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
            else
            {
                checkInput_.first  = 0;
                checkInput_.second = true;
            }
        }
    }

    void vacuumProperties::run()
    {
        this->read();
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

            if ( diffCombo_.get_active_row_number() == 1 )
            {
                diffK_ = diffK_*1e04; 
            }
            
            if ( velocityCombo_.get_active_row_number() == 0 )
            {
                vK_ = vK_*1e-03;
            }
            else if ( velocityCombo_.get_active_row_number() == 1 )
            {
                vK_ = vK_;
            }
            else if ( velocityCombo_.get_active_row_number() == 2 )
            {
                vK_ = vK_*1e02;
            }
            

            if ( pathCombo_.get_active_row_number() == 0 )
            {
                lK_ = lK_*1e-03;
            }
            else if ( pathCombo_.get_active_row_number() == 1 )
            {
                lK_ = lK_;
            }
            else if ( pathCombo_.get_active_row_number() == 2 )
            {
                lK_ = lK_*1e01;
            }
            else if ( pathCombo_.get_active_row_number() == 3 )
            {
                lK_ = lK_*1e02;
            }
            else if ( pathCombo_.get_active_row_number() == 4 )
            {
                lK_ = lK_*1e03;
            }
            else if ( pathCombo_.get_active_row_number() == 5 )
            {
                lK_ = lK_*1e06;
            }
            else if ( pathCombo_.get_active_row_number() == 6 )
            {
                lK_ = lK_*1e09;
            }
            else if ( pathCombo_.get_active_row_number() == 7 )
            {
                lK_ = lK_*1e12;
            }


            {
                std::stringstream diffK;
                diffK << std::scientific << std::setprecision(OP_) << diffK_;
                diffResults_.set_text(diffK.str());
            }
            
            {
                std::stringstream Kn;
                Kn << std::scientific << std::setprecision(OP_) << 1./Kn_;
                
                if ( Kn_ < 1. )
                {              
                    knudsenResults_.set_text(Kn.str()+" (molecular)");
                }
                else
                {
                    knudsenResults_ .set_text(Kn.str()+" (viscous)");
                }
            }

            {
                std::stringstream vK;
                vK << std::scientific << std::setprecision(OP_) << vK_;
                velocityResults_.set_text(vK.str());
            }

            {
                std::stringstream lK;
                lK << std::scientific << std::setprecision(OP_) << lK_;
                pathResults_.set_text(lK.str());
            }

            this->show_all_children();
        }
    }

    void vacuumProperties::save()
    {
        if ( diffResults_.get_text() == "?" )
        {
            this->run();
        }

        std::string filename = this->save_file(this->get_toplevel()->gobj(), "vacuum.asali");
        if ( filename != "" )
        {
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
            output << "Diffusivity:       " << diffK_ << " " << diffCombo_.get_active_text() << std::endl;
            output << "Knudsen number:    " << Kn_ << std::endl;
            output << "Mean gas velocity: " << vK_ << " " << velocityCombo_.get_active_text() << std::endl;
            output << "Mean free path:    " << lK_ << " " << pathCombo_.get_active_text() << std::endl;
            output.close();
            this->savedMessage();
        }
    }
}
