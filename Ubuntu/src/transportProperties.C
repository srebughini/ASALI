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

#include "transportProperties.h"

namespace ASALI
{
    transportProperties::transportProperties(ASALI::canteraInterface        *canteraInterface,
                                             ASALI::speciesPopup            *speciesNames,
                                             std::string                     kineticType)
    : helpButton_("Available species"),
      exitButton1_("Exit"),
      doneButton_("Done"),
      tempLabel_("Temperature"),
      pressLabel_("Pressure"),
      NS_(10),
      OP_(3),
      condBox_(Gtk::ORIENTATION_VERTICAL),
      muBox_(Gtk::ORIENTATION_VERTICAL),
      diffBox_(Gtk::ORIENTATION_VERTICAL),
      exitButton2_("Exit"),
      saveButton_("Save"),
      backButton_("Back"),
      condLabel_("Thermal conductivity"),
      muLabel_("Viscosity"),
      diffLabel_("Diffusivity"),
      kineticType_(kineticType),
      canteraInterface_(canteraInterface),
      speciesNames_(speciesNames)
    {
        #include "Beer.H"
        #include "BeerShort.H"

        //Input menu
        {
            this->set_border_width(15);
            this->set_title("ASALI: Transport properties");
            this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
            this->set_icon_from_file("images/Icon.tiff");

            //Add background grid
            this->add(inputGrid_);

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
                helpButton_.signal_clicked().connect(sigc::mem_fun(*this,&transportProperties::availableSpecies));
            }

            //Add back button
            inputGrid_.attach(exitButton1_,0,13,1,1);
            exitButton1_.signal_clicked().connect(sigc::mem_fun(*this,&transportProperties::exit));

            //Done buttons
            inputGrid_.attach(doneButton_,2,13,1,1);
            doneButton_.signal_clicked().connect(sigc::mem_fun(*this,&transportProperties::results));

            this->show_all_children();
        }
        
        
        //Results
        {
            resultsGrid_.set_column_homogeneous(true);
            resultsGrid_.set_column_spacing(10);
            resultsGrid_.set_row_spacing(10);

            //Thermal conductivity
            condBox_.pack_start(condLabel_, Gtk::PACK_SHRINK);
            condBox_.pack_start(condCombo_, Gtk::PACK_SHRINK);
            condBox_.set_spacing(5);
            condBox_.set_halign(Gtk::ALIGN_CENTER);
            condCombo_.append("W/m/K");
            condCombo_.append("cal/m/s/k");
            condCombo_.set_active(0);
            condCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this,&transportProperties::condUnitConversion),true));

            //Viscosity
            muBox_.pack_start(muLabel_, Gtk::PACK_SHRINK);
            muBox_.pack_start(muCombo_, Gtk::PACK_SHRINK);
            muBox_.set_spacing(5);
            muBox_.set_halign(Gtk::ALIGN_CENTER);
            muCombo_.append("Pas");
            muCombo_.append("cP");
            muCombo_.set_active(0);
            muCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this,&transportProperties::muUnitConversion),true));
            
            //Diffusivity
            diffBox_.pack_start(diffLabel_, Gtk::PACK_SHRINK);
            diffBox_.pack_start(diffCombo_, Gtk::PACK_SHRINK);
            diffBox_.set_spacing(5);
            diffBox_.set_halign(Gtk::ALIGN_CENTER);
            diffCombo_.append("m\u00b2/s");
            diffCombo_.set_active(0);
            diffCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this,&transportProperties::diffUnitConversion),true));


            //Add heading
            resultsGrid_.attach(condBox_,1,0,1,1);
            resultsGrid_.attach(muBox_,2,0,1,1);
            resultsGrid_.attach(diffBox_,3,0,1,1);

            //Add back button
            resultsGrid_.attach(backButton_,0,n_.size()+2,1,1);
            backButton_.signal_clicked().connect(sigc::mem_fun(*this,&transportProperties::input));
            
            //Add print on file
            resultsGrid_.attach(saveButton_,1,n_.size()+2,1,1);
            saveButton_.signal_clicked().connect(sigc::mem_fun(*this,&transportProperties::save));

            //Add exit button
            resultsGrid_.attach(exitButton2_,3,n_.size()+2,1,1);
            exitButton2_.signal_clicked().connect(sigc::mem_fun(*this,&transportProperties::exit));
        }


    }

    transportProperties::~transportProperties()
    {
    }
    

    void transportProperties::clean()
    {
        resultsGrid_.remove(backButton_);
        resultsGrid_.remove(saveButton_);
        resultsGrid_.remove(exitButton2_);

        if ( condVector_.size() != 0)
        {
            for (unsigned int i=0;i<condVector_.size();i++)
            {
                resultsGrid_.remove(*condVector_[i]);
            }
        }

        if ( muVector_.size() != 0)
        {
            for (unsigned int i=0;i<muVector_.size();i++)
            {
                resultsGrid_.remove(*muVector_[i]);
            }
        }

        if ( diffBoxVector_.size() != 0)
        {
            for (unsigned int i=0;i<diffBoxVector_.size();i++)
            {
                resultsGrid_.remove(*diffBoxVector_[i]);
            }
        }
    }

    void transportProperties::input()
    {
        this->remove();
        this->add(inputGrid_);
        this->resize(inputGrid_.get_width(),inputGrid_.get_height());
        this->show_all_children();
    }

    void transportProperties::results()
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

            mu_.clear();
            cond_.clear();
            diff_.clear();
            MW_.clear();
            mu_.resize(n_.size());
            cond_.resize(n_.size());
            diff_.resize(n_.size());
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
            this->condUnitConversion(false);
            this->muUnitConversion(false);
            this->diffUnitConversion(false);
        }
    }

    void transportProperties::showAtomNames()
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

    void transportProperties::condUnitConversion(bool check)
    {
        if ( check == true )
        {
            if ( condVector_.size() != 0)
            {
                for (unsigned int i=0;i<condVector_.size();i++)
                {
                    resultsGrid_.remove(*condVector_[i]);
                }
            }
        }

        condVector_.clear();
        condVector_.resize(n_.size());
        std::vector<double> converter(n_.size());

        if ( condCombo_.get_active_row_number() == 0 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1.; //W/m/K
            }
        }
        else if ( condCombo_.get_active_row_number() == 1 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1./4.186; //cal/m/s/K
            }
        }


        for (unsigned int i=0;i<n_.size();i++)
        {
            std::stringstream cond;
            cond << std::scientific << std::setprecision(OP_) << cond_[i]*converter[i];
            condVector_[i] = new Gtk::Label(cond.str());
            resultsGrid_.attach(*condVector_[i],1,i+1,1,1);
        }

        this->show_all_children();
    }

    void transportProperties::muUnitConversion(bool check)
    {
        if ( check == true )
        {
            if ( muVector_.size() != 0)
            {
                for (unsigned int i=0;i<muVector_.size();i++)
                {
                    resultsGrid_.remove(*muVector_[i]);
                }
            }
        }

        muVector_.clear();
        muVector_.resize(n_.size());
        std::vector<double> converter(n_.size());

        if ( muCombo_.get_active_row_number() == 0 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1.; //Pa
            }
        }
        else if ( muCombo_.get_active_row_number() == 1 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                converter[i] = 1e03; //cP
            }
        }

        for (unsigned int i=0;i<n_.size();i++)
        {
            std::stringstream mu;
            mu << std::scientific << std::setprecision(OP_) << mu_[i]*converter[i];
            muVector_[i] = new Gtk::Label(mu.str());
            resultsGrid_.attach(*muVector_[i],2,i+1,1,1);
        }

        this->show_all_children();
    }

    void transportProperties::diffUnitConversion(bool check)
    {
        if ( check == true )
        {
            if ( diffBoxVector_.size() != 0)
            {
                for (unsigned int i=0;i<diffBoxVector_.size();i++)
                {
                    resultsGrid_.remove(*diffBoxVector_[i]);
                }
            }
        }

        speciesCombo_.clear();
        diffBoxVector_.clear();
        diffVector_.clear();
        speciesCombo_.resize(n_.size());
        diffBoxVector_.resize(n_.size());
        diffVector_.resize(n_.size());

        for (unsigned int i=0;i<n_.size();i++)
        { 
            speciesCombo_[i]  = new Gtk::ComboBoxText();
            diffBoxVector_[i] = new Gtk::Box();
            for (unsigned int j=0;j<n_.size();j++)
            {
                speciesCombo_[i]->append(n_[j]);
                speciesCombo_[i]->set_active(j);
            }
            speciesCombo_[i]->signal_changed().connect(sigc::bind<unsigned int>(sigc::mem_fun(*this,&transportProperties::diffSpecies),i));
            diffBoxVector_[i]->pack_end(*speciesCombo_[i]);
        }

        for (unsigned int i=0;i<n_.size();i++)
        {
            this->diffSpecies(i);
            resultsGrid_.attach(*diffBoxVector_[i],3,i+1,1,1);
        }

        this->show_all_children();
    }

    void transportProperties::diffSpecies(unsigned int row)
    {
        double converter = 0.;
        if ( diffCombo_.get_active_row_number() == 0 )
        {
            converter = 1.; //m2/s
        }

        for (unsigned int i=0;i<n_.size();i++)
        {
            if ( speciesCombo_[row]->get_active_row_number() == int(i) )
            {
                std::string diffstr = "";

                if ( diff_[row][i] == -1 )
                {
                    diffstr = "n.a.";
                    if ( diffBoxVector_[row]->get_children().size() == 1 )
                    {
                        diffBoxVector_[row]->remove(*diffBoxVector_[row]->get_children()[0]);
                    }
                    else if ( diffBoxVector_[row]->get_children().size() == 2 )
                    {
                        diffBoxVector_[row]->remove(*diffBoxVector_[row]->get_children()[0]);
                        diffBoxVector_[row]->remove(*diffBoxVector_[row]->get_children()[1]);
                    }
                }
                else
                {
                    std::stringstream diff;
                    diff << std::scientific << std::setprecision(OP_) << diff_[row][i]*converter;
                    diffstr = diffstr + diff.str() + " in ";

                    if ( diffBoxVector_[row]->get_children().size() > 1 )
                    {
                        diffBoxVector_[row]->remove(*diffBoxVector_[row]->get_children()[0]);
                    }
                }
                

                diffVector_[i] = new Gtk::Label(diffstr);
                diffBoxVector_[row]->pack_start(*diffVector_[i]);

                break;
            }
        }

        this->show_all_children();
    }


    void transportProperties::save()
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
                output << "Species\t" << "x           \ty           \t\u03BB           \t\u03BC           \t\u0393           " << std::endl;
                for (unsigned int i=0;i<n_.size();i++)
                {
                    for (unsigned int j=i;j<n_.size();j++)
                    {
                        if ( i == n_.size() - 1 )
                        {
                            output << n_[i] << " " << "  " << "\t" << "             " << "\t" << "             " << "\t" << cond_[i] << "\t" << mu_[i] << std::endl;
                        }
                        else
                        {
                            if ( j == i)
                            {
                                output << n_[i] << " " << n_[j] << "\t" << x_[i] << "\t" << y_[i] << "\t" << cond_[i] << "\t" << mu_[i] << "\t" << diff_[i][j] << std::endl;
                            }
                            else
                            {
                                output << n_[i] << " " << n_[j] << "\t" << "           " << "\t" << "           " << "\t" << "           " << "\t" << "           " << "\t" << diff_[i][j] << std::endl;
                            }
                        }
                    }
                }
                output << std::endl;
                output << std::endl;
                output << "x: mole fraction" << std::endl;
                output << "y: mass fraction" << std::endl;
                output << "\u03BB: thermal conductivity [W/m/K]" << std::endl;
                output << "\u03BC: viscosity            [Pas]" << std::endl;
                output << "\u0393: diffusivity          [m\u00b2/s]" << std::endl;
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

    void transportProperties::availableSpecies()
    {
        speciesNames_->show();
    }

    void transportProperties::exit()
    {
        this->hide();
    }
    
    std::string transportProperties::getBeer()
    {
        srand(time(NULL));
        int i = rand()%beer_.size();
        return beer_[i];
    }

    std::string transportProperties::getBeerShort()
    {
        srand(time(NULL));
        int i = rand()%beerShort_.size();
        return beerShort_[i];
    }

    void transportProperties::inputReader()
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
        for (unsigned int i=0;i<10;i++)
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
                 kineticType_ == "load" )
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

    void transportProperties::checkInput(unsigned int i)
    {
        if ( i == 4444 )
        {
            Gtk::MessageDialog dialog(*this,"Please, the sum of mass/mole fractions should be 1.",true,Gtk::MESSAGE_WARNING);
            dialog.set_secondary_text(this->getBeerShort(),true);
            dialog.run();
        }
        else if ( i == 4445 )
        {
            Gtk::MessageDialog dialog(*this,"Something is wrong in your input, please fix it.",true,Gtk::MESSAGE_WARNING);
            dialog.set_secondary_text(this->getBeerShort(),true);
            dialog.run();
        }
        else
        {
            Gtk::MessageDialog dialog(*this,n_[i]+" is missing!!",true,Gtk::MESSAGE_WARNING);
            dialog.set_secondary_text(this->getBeerShort(),true);
            dialog.run();
        }
    }

    void transportProperties::savedMessage()
    {
        Gtk::MessageDialog dialog(*this,"Your file has been saved.\nThank you for using ASALI.",true,Gtk::MESSAGE_OTHER);
        dialog.set_secondary_text(this->getBeerShort(),true);
        dialog.run();
    }

}
