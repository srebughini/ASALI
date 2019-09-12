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

#include "thermoProperties.h"

namespace ASALI
{
    thermoProperties::thermoProperties(ASALI::canteraInterface        *canteraInterface,
                                       ASALI::speciesPopup            *speciesNames,
                                       std::string                     kineticType)
    : transportProperties(canteraInterface,speciesNames,kineticType),
      cpBox_(Gtk::ORIENTATION_VERTICAL),
      hBox_(Gtk::ORIENTATION_VERTICAL),
      sBox_(Gtk::ORIENTATION_VERTICAL),
      exitButton2_("Exit"),
      saveButton_("Save"),
      backButton_("Back"),
      cpLabel_("Specific Heat"),
      hLabel_("Enthalpy"),
      sLabel_("Entropy"),
      kineticType_(kineticType),
      canteraInterface_(canteraInterface),
      speciesNames_(speciesNames)
    {

        //Input menu
        {
            this->set_border_width(15);
            this->set_title("ASALI: Thermodynamic properties");
            this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
            this->set_icon_from_file("images/Icon.tiff");
            this->input();
        }
        
        //Results
        {
            resultsGrid_.set_column_homogeneous(true);
            resultsGrid_.set_column_spacing(10);
            resultsGrid_.set_row_spacing(10);

            //Specific heat
            cpBox_.pack_start(cpLabel_, Gtk::PACK_SHRINK);
            cpBox_.pack_start(cpCombo_, Gtk::PACK_SHRINK);
            cpBox_.set_spacing(5);
            cpBox_.set_halign(Gtk::ALIGN_CENTER);
            cpCombo_.append("J/kmol/K");
            cpCombo_.append("J/mol/K");
            cpCombo_.append("J/kg/K");
            cpCombo_.append("cal/mol/K");
            cpCombo_.append("cal/kmol/K");
            cpCombo_.append("cal/kg/K");
            cpCombo_.set_active(0);
            cpCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this,&thermoProperties::cpUnitConversion),true));

            //Entropy
            sBox_.pack_start(sLabel_, Gtk::PACK_SHRINK);
            sBox_.pack_start(sCombo_, Gtk::PACK_SHRINK);
            sBox_.set_spacing(5);
            sBox_.set_halign(Gtk::ALIGN_CENTER);
            sCombo_.append("J/kmol/K");
            sCombo_.append("J/mol/K");
            sCombo_.append("J/kg/K");
            sCombo_.append("cal/mol/K");
            sCombo_.append("cal/kmol/K");
            sCombo_.append("cal/kg/K");
            sCombo_.set_active(0);
            sCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this,&thermoProperties::sUnitConversion),true));

            //Enthalpy
            hBox_.pack_start(hLabel_, Gtk::PACK_SHRINK);
            hBox_.pack_start(hCombo_, Gtk::PACK_SHRINK);
            hBox_.set_spacing(5);
            hBox_.set_halign(Gtk::ALIGN_CENTER);
            hCombo_.append("J/kmol");
            hCombo_.append("J/mol");
            hCombo_.append("J/kg");
            hCombo_.append("cal/kmol");
            hCombo_.append("cal/mol");
            hCombo_.append("cal/kg");
            hCombo_.set_active(0);
            hCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this,&thermoProperties::hUnitConversion),true));


            //Add heading
            resultsGrid_.attach(cpBox_,1,0,1,1);
            resultsGrid_.attach(hBox_,2,0,1,1);
            resultsGrid_.attach(sBox_,3,0,1,1);

            //Add back button
            resultsGrid_.attach(backButton_,0,n_.size()+2,1,1);
            backButton_.signal_clicked().connect(sigc::mem_fun(*this,&thermoProperties::input));
            
            //Add print on file
            resultsGrid_.attach(saveButton_,1,n_.size()+2,1,1);
            saveButton_.signal_clicked().connect(sigc::mem_fun(*this,&thermoProperties::save));

            //Add exit button
            resultsGrid_.attach(exitButton2_,3,n_.size()+2,1,1);
            exitButton2_.signal_clicked().connect(sigc::mem_fun(*this,&thermoProperties::exit));
        }


    }

    thermoProperties::~thermoProperties()
    {
    }
    

    void thermoProperties::clean()
    {
        resultsGrid_.remove(backButton_);
        resultsGrid_.remove(saveButton_);
        resultsGrid_.remove(exitButton2_);

        if ( cpVector_.size() != 0)
        {
            for (unsigned int i=0;i<cpVector_.size();i++)
            {
                resultsGrid_.remove(*cpVector_[i]);
            }
        }

        if ( sVector_.size() != 0)
        {
            for (unsigned int i=0;i<sVector_.size();i++)
            {
                resultsGrid_.remove(*sVector_[i]);
            }
        }

        if ( hVector_.size() != 0)
        {
            for (unsigned int i=0;i<hVector_.size();i++)
            {
                resultsGrid_.remove(*hVector_[i]);
            }
        }
    }

    void thermoProperties::results()
    {
        this->inputReader();
        if ( checkInput_.second == false )
        {
            this->checkInput(checkInput_.first);
        }
        else
        {
            this->clean();
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
                //Add back button
                resultsGrid_.attach(backButton_,0,n_.size()+2,1,1);
                
                //Add print on file
                resultsGrid_.attach(saveButton_,1,n_.size()+2,1,1);

                //Add exit button
                resultsGrid_.attach(exitButton2_,3,n_.size()+2,1,1);

                this->remove();
                this->add(resultsGrid_);
                this->resize(resultsGrid_.get_width(),resultsGrid_.get_height());
                this->showAtomNames();
                this->cpUnitConversion(false);
                this->hUnitConversion(false);
                this->sUnitConversion(false);
            }
        }
    }

    void thermoProperties::showAtomNames()
    {
        if ( nameVector_.size() != 0)
        {
            for (unsigned int i=0;i<nameVector_.size();i++)
            {
                resultsGrid_.remove(*nameVector_[i]);
            }
        }

        nameVector_.clear();
        nameVector_.resize(n_.size());

        for (unsigned int i=0;i<n_.size();i++)
        { 
            nameVector_[i] = new Gtk::Label(n_[i]);
            resultsGrid_.attach(*nameVector_[i],0,i+1,1,1);
        }
    }

    void thermoProperties::cpUnitConversion(bool check)
    {
        if ( check == true )
        {
            if ( cpVector_.size() != 0)
            {
                for (unsigned int i=0;i<cpVector_.size();i++)
                {
                    resultsGrid_.remove(*cpVector_[i]);
                }
            }

        }

        cpVector_.clear();
        cpVector_.resize(n_.size());
        std::vector<double> converter(n_.size());

        if ( cpCombo_.get_active_row_number() == 0 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1.; //J/kmol/K
            }
        }
        else if ( cpCombo_.get_active_row_number() == 1 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./1.e03; //J/mol/K
            }
        }
        else if ( cpCombo_.get_active_row_number() == 2 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./MW_[i]; //J/kg/K
            }
        }
        else if ( cpCombo_.get_active_row_number() == 3 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./4.186; //cal/kmol/K
            }
        }
        else if ( cpCombo_.get_active_row_number() == 4 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./(1.e03*4.186); //cal/mol/K
            }
        }
        else if ( cpCombo_.get_active_row_number() == 5 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./(MW_[i]*4.186); //cal/kg/K
            }
        }

        for (unsigned int i=0;i<n_.size();i++)
        {
            std::stringstream cp;
            cp << std::scientific << std::setprecision(OP_) << cp_[i]*converter[i];
            cpVector_[i] = new Gtk::Label(cp.str());
            resultsGrid_.attach(*cpVector_[i],1,i+1,1,1);
        }

        this->show_all_children();
    }

    void thermoProperties::hUnitConversion(bool check)
    {
        if ( check == true )
        {
            if ( hVector_.size() != 0)
            {
                for (unsigned int i=0;i<hVector_.size();i++)
                {
                    resultsGrid_.remove(*hVector_[i]);
                }
            }
        }

        hVector_.clear();
        hVector_.resize(n_.size());
        std::vector<double> converter(n_.size());

        if ( hCombo_.get_active_row_number() == 0 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1.; //J/kmol
            }
        }
        else if ( hCombo_.get_active_row_number() == 1 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./1.e03; //J/mol
            }
        }
        else if ( hCombo_.get_active_row_number() == 2 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./MW_[i]; //J/kg
            }
        }
        else if ( hCombo_.get_active_row_number() == 3 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./4.186; //cal/kmol
            }
        }
        else if ( hCombo_.get_active_row_number() == 4 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./(1.e03*4.186); //cal/mol
            }
        }
        else if ( hCombo_.get_active_row_number() == 5 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./(MW_[i]*4.186); //cal/kg
            }
        }

        for (unsigned int i=0;i<n_.size();i++)
        {
            std::stringstream h;
            h << std::scientific << std::setprecision(OP_) << h_[i]*converter[i];
            hVector_[i] = new Gtk::Label(h.str());
            resultsGrid_.attach(*hVector_[i],2,i+1,1,1);
        }

        this->show_all_children();
    }

    void thermoProperties::sUnitConversion(bool check)
    {
        if ( check == true )
        {
            if ( sVector_.size() != 0)
            {
                for (unsigned int i=0;i<sVector_.size();i++)
                {
                    resultsGrid_.remove(*sVector_[i]);
                }
            }
        }

        sVector_.clear();
        sVector_.resize(n_.size());
        std::vector<double> converter(n_.size());

        if ( sCombo_.get_active_row_number() == 0 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1.; //J/kmol/K
            }
        }
        else if ( sCombo_.get_active_row_number() == 1 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./1.e03; //J/mol/K
            }
        }
        else if ( sCombo_.get_active_row_number() == 2 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./MW_[i]; //J/kg/K
            }
        }
        else if ( sCombo_.get_active_row_number() == 3 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./4.186; //cal/kmol/K
            }
        }
        else if ( sCombo_.get_active_row_number() == 4 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./(1.e03*4.186); //cal/mol/K
            }
        }
        else if ( sCombo_.get_active_row_number() == 5 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./(MW_[i]*4.186); //cal/kg/K
            }
        }

        for (unsigned int i=0;i<n_.size();i++)
        {
            std::stringstream s;
            s << std::scientific << std::setprecision(OP_) << std::setprecision(OP_) << s_[i]*converter[i];
            sVector_[i] = new Gtk::Label(s.str());
            resultsGrid_.attach(*sVector_[i],3,i+1,1,1);
        }

        this->show_all_children();
    }

    void thermoProperties::save()
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

}
