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

#include "basicProperties.hpp"

namespace ASALI
{
    basicProperties::basicProperties(ASALI::canteraInterface        *canteraInterface,
                                             ASALI::speciesPopup            *speciesNames,
                                             std::string                     kineticType)
    : helpButton_("Available species"),
      exitButton1_("Exit"),
      doneButton_("Done"),
      tempLabel_("Temperature"),
      pressLabel_("Pressure"),
      NS_(10),
      OP_(3),
      kineticType_(kineticType),
      canteraInterface_(canteraInterface),
      speciesNames_(speciesNames)
    {
        beerQuote_ = new ASALI::beerQuote();
        vectorUtils_ = new ASALI::asaliVectorUtils();

        //Input menu
        {
            inputGrid_.set_column_homogeneous(true);
            inputGrid_.set_column_spacing(10);
            inputGrid_.set_row_homogeneous(true);
            inputGrid_.set_row_spacing(10);

            //Add temperature selector
            inputGrid_.attach(tempLabel_,0,0,1,1);
            inputGrid_.attach(tempEntry_,1,0,1,1);
            tempEntry_.set_max_length(10);
            tempEntry_.set_text("298.15");
            inputGrid_.attach(tempCombo_,2,0,1,1);
            tempCombo_.append("K");
            tempCombo_.append("°C");
            tempCombo_.append("°F");
            tempCombo_.set_active(0);

            //Add temperature selector
            inputGrid_.attach(pressLabel_,0,1,1,1);
            inputGrid_.attach(pressEntry_,1,1,1,1);
            pressEntry_.set_max_length(10);
            pressEntry_.set_text("101325");
            inputGrid_.attach(pressCombo_,2,1,1,1);
            pressCombo_.append("Pa");
            pressCombo_.append("GPa");
            pressCombo_.append("MPa");
            pressCombo_.append("kPa");
            pressCombo_.append("bar");
            pressCombo_.append("torr");
            pressCombo_.append("mmHg");
            pressCombo_.append("atm");
            pressCombo_.set_active(0);
            
            //Add mole or mass fraction selection
            inputGrid_.attach(fractionCombo_,1,2,1,1);
            fractionCombo_.append("Mole fraction");
            fractionCombo_.append("Mass fraction");
            fractionCombo_.set_active(0);
            
            
            nameEntry_.resize(NS_);
            fractionEntry_.resize(NS_);
            for (unsigned int i=0;i<NS_;i++)
            {
                nameEntry_[i]     = new Gtk::Entry();
                fractionEntry_[i] = new Gtk::Entry();

                inputGrid_.attach(*nameEntry_[i],0,3+i,1,1);
                nameEntry_[i]->set_max_length(10);
                inputGrid_.attach(*fractionEntry_[i],1,3+i,1,1);
                fractionEntry_[i]->set_max_length(10);
                if ( i == 0 )
                {
                    nameEntry_[i]->set_text("AR");
                    fractionEntry_[i]->set_text("1");
                }
            }

            //Add help button
            if ( kineticType_ == "default" )
            {
                inputGrid_.attach(helpButton_,1,13,1,1);
                helpButton_.signal_clicked().connect(sigc::mem_fun(*this,&basicProperties::availableSpecies));
            }

            //Add back button
            inputGrid_.attach(exitButton1_,0,13,1,1);
            exitButton1_.signal_clicked().connect(sigc::mem_fun(*this,&basicProperties::exit));

            //Done buttons
            inputGrid_.attach(doneButton_,2,13,1,1);
            doneButton_.signal_clicked().connect(sigc::mem_fun(*this,&basicProperties::results));

            this->show_all_children();
        }
    }

    basicProperties::~basicProperties()
    {
    }

    void basicProperties::save() {}

    void basicProperties::clean() {}

    void basicProperties::results() {}

    void basicProperties::showAtomNames() {}

    void basicProperties::title(std::string title)
    {
        this->set_border_width(15);
        this->set_title(title);
        this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
        this->set_icon_from_file("images/Icon.png");
    }

    void basicProperties::input()
    {
        this->remove();
        this->add(inputGrid_);
        this->resize(inputGrid_.get_width(),inputGrid_.get_height());
        this->show_all_children();
    }

    void basicProperties::availableSpecies()
    {
        speciesNames_->show();
    }

    void basicProperties::exit()
    {
        doneButton_.set_label("Done");
        this->hide();
    }

    void basicProperties::inputReader()
    {
        T_ = Glib::Ascii::strtod(tempEntry_.get_text());
        p_ = Glib::Ascii::strtod(pressEntry_.get_text());

        ConvertsToKelvin(T_,tempCombo_.get_active_text());
        ConvertsToPascal(p_,pressCombo_.get_active_text());

        std::vector<std::string>   n(NS_);
        std::vector<Glib::ustring> x(NS_);
        
        for (unsigned int i=0;i<NS_;i++)
        {
            n[i] = nameEntry_[i]->get_text().c_str();
            x[i] = fractionEntry_[i]->get_text().c_str();
        }

        n_.clear();
        x_.clear();
        for (unsigned int i=0;i<NS_;i++)
        {
            if ( !n[i].empty() )
            {
                n_.push_back(n[i]);
            }
            
            if ( !x[i].empty() )
            {
                x_.push_back(Glib::Ascii::strtod(x[i]));
            }
        }
        
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
                    double sum = SumElements(x_);
                    for(unsigned int i=0;i<x_.size();i++)
                    {
                        x_[i] = x_[i]/sum;
                    }
                    
                    if ( fabs(sum - 1.) > 1e-06 )
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

    void basicProperties::checkInput(unsigned int i)
    {
        if ( i == 4444 )
        {
            Gtk::MessageDialog dialog(*this,"Please, the sum of mass/mole fractions should be 1.",true,Gtk::MESSAGE_WARNING);
            dialog.set_secondary_text(beerQuote_->getShortRandomQuote(),true);
            dialog.run();
        }
        else if ( i == 4445 )
        {
            Gtk::MessageDialog dialog(*this,"Something is wrong in your input, please fix it.",true,Gtk::MESSAGE_WARNING);
            dialog.set_secondary_text(beerQuote_->getShortRandomQuote(),true);
            dialog.run();
        }
        else
        {
            Gtk::MessageDialog dialog(*this,n_[i]+" is missing!!",true,Gtk::MESSAGE_WARNING);
            dialog.set_secondary_text(beerQuote_->getShortRandomQuote(),true);
            dialog.run();
        }
    }

    void basicProperties::savedMessage()
    {
        Gtk::MessageDialog dialog(*this,"Your file has been saved.\nThank you for using ASALI.",true,Gtk::MESSAGE_OTHER);
        dialog.set_secondary_text(beerQuote_->getShortRandomQuote(),true);
        dialog.run();
    }

}
