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

#include "catalyticReactors.h"

namespace ASALI
{
    catalyticReactors::catalyticReactors(Cantera::ThermoPhase *thermo,
                                         Cantera::Transport   *transport,
                                         Cantera::Kinetics    *kinetic,
                                         Cantera::Interface   *surface,
                                         std::string           kineticType)
    : coverageBox_(Gtk::ORIENTATION_VERTICAL),
      helpButton_("Available species"),
      nextButton1_("Next"),
      backButton1_("Back"),
      nextButton2_("Next"),
      backButton2_("Back"),
      runButton_("Run"),
      saveButton_("Save"),
      asaliPropertiesButton_("Properties"),
      asaliKineticButton_("Kinetic"),
      asaliPlotButton_("Plot"),
      tempLabel_("Temperature"),
      pressLabel_("Pressure"),
      kineticLabel_("Kinetic type"),
      coverageLabel_("<b>Please, insert the initial coverage composition</b>"),
      OP_(3),
      NS_(10),
      SURF_NS_(5),
      thermo_(thermo),
      transport_(transport),
      kinetic_(kinetic),
      surface_(surface),
      kineticType_(kineticType),
      inert_("NONE")
    {
        #include "Beer.H"
        #include "BeerShort.H"


        if ( kineticType_ != "none" )
        {
            canteraInterface_    = new ASALI::canteraInterface(thermo_,transport_);
        }

        speciesNames_            = new ASALI::speciesPopup();
        asaliKinetic_            = new ASALI::asaliKinetic();
        asaliProperties_         = new ASALI::asaliProperties();
        asaliCatalystProperties_ = new ASALI::asaliCatalystProperties();
        asaliPlot_               = new ASALI::asaliPlot();
        bar_                     = new ASALI::runBar();

        {
            this->set_border_width(15);
            this->set_title("ASALI: Catalytic reactors");
            this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
            this->set_icon_from_file("images/Icon.tiff");
        }
        
        //Species input menu
        {
            inputGrid_.set_column_homogeneous(true);
            inputGrid_.set_column_spacing(10);
            inputGrid_.set_row_homogeneous(true);
            inputGrid_.set_row_spacing(10);

            //Add kinetic selection
            inputGrid_.attach(kineticLabel_,0,0,1,1);
            inputGrid_.attach(kineticCombo_,1,0,1,1);
            kineticCombo_.append("ASALI");
            kineticCombo_.append("CANTERA");
            kineticCombo_.set_active(0);
            kineticCombo_.signal_changed().connect(sigc::mem_fun(*this,&catalyticReactors::switchTo));

            //Add temperature selector
            inputGrid_.attach(tempLabel_,0,1,1,1);
            inputGrid_.attach(tempEntry_,1,1,1,1);
            tempEntry_.set_max_length(10);
            tempEntry_.set_text("298.15");
            inputGrid_.attach(tempCombo_,2,1,1,1);
            tempCombo_.append("K");
            tempCombo_.append("°C");
            tempCombo_.append("°F");
            tempCombo_.set_active(0);

            //Add temperature selector
            inputGrid_.attach(pressLabel_,0,2,1,1);
            inputGrid_.attach(pressEntry_,1,2,1,1);
            pressEntry_.set_max_length(10);
            pressEntry_.set_text("101325");
            inputGrid_.attach(pressCombo_,2,2,1,1);
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
            inputGrid_.attach(fractionCombo_,1,3,1,1);
            fractionCombo_.append("Mole fraction");
            fractionCombo_.append("Mass fraction");
            fractionCombo_.set_active(0);

            nameEntry_.resize(NS_);
            fractionEntry_.resize(NS_);
            for (unsigned int i=0;i<NS_;i++)
            {
                nameEntry_[i]     = new Gtk::Entry();
                fractionEntry_[i] = new Gtk::Entry();

                inputGrid_.attach(*nameEntry_[i],0,4+i,1,1);
                nameEntry_[i]->set_max_length(10);
                inputGrid_.attach(*fractionEntry_[i],1,4+i,1,1);
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
                inputGrid_.attach(helpButton_,1,NS_+5,1,1);
                helpButton_.signal_clicked().connect(sigc::mem_fun(*this,&catalyticReactors::availableSpecies));
            }

            //Add back button
            inputGrid_.attach(backButton1_,0,NS_+5,1,1);
            backButton1_.signal_clicked().connect(sigc::mem_fun(*this,&catalyticReactors::input));

            inputGrid_.attach(nextButton1_,2,NS_+5,1,1);
            signal = nextButton1_.signal_clicked().connect(sigc::mem_fun(*this,&catalyticReactors::kineticShow));

        }

        //Coverage input menu
        {
            coverageBox_.set_halign(Gtk::ALIGN_START);
            coverageBox_.set_spacing(10);
            coverageBox_.pack_start(coverageLabel_, Gtk::PACK_SHRINK);
            coverageLabel_.set_use_markup(true);
            coverageBox_.pack_start(coverageGrid_, Gtk::PACK_SHRINK);
            
            coverageGrid_.set_column_homogeneous(true);
            coverageGrid_.set_column_spacing(10);
            coverageGrid_.set_row_spacing(10);

            coverageNameEntry_.resize(SURF_NS_);
            coverageFractionEntry_.resize(SURF_NS_);
            for (unsigned int i=0;i<SURF_NS_;i++)
            {
                coverageNameEntry_[i]     = new Gtk::Entry();
                coverageFractionEntry_[i] = new Gtk::Entry();

                coverageGrid_.attach(*coverageNameEntry_[i],0,i,1,1);
                coverageNameEntry_[i]->set_max_length(10);
                coverageGrid_.attach(*coverageFractionEntry_[i],1,i,1,1);
                coverageFractionEntry_[i]->set_max_length(10);
                if ( i == 0 )
                {
                    coverageNameEntry_[i]->set_text("Pt(s)");
                    coverageFractionEntry_[i]->set_text("1");
                }
            }

            //Add back button
            coverageGrid_.attach(backButton2_,0,SURF_NS_+5,1,1);
            backButton2_.signal_clicked().connect(sigc::mem_fun(*this,&catalyticReactors::composition));

            //Done buttons
            coverageGrid_.attach(nextButton2_,1,SURF_NS_+5,1,1);
            nextButton2_.signal_clicked().connect(sigc::mem_fun(*this,&catalyticReactors::recap));
        }



    }

    catalyticReactors::~catalyticReactors()
    {
    }

    void catalyticReactors::coverage()
    {
        this->compositionReader();
        if ( checkComposition_.second == false )
        {
            this->checkComposition(checkComposition_.first);
        }
        else
        {
            this->remove();
            this->add(coverageBox_);
            this->resize(coverageBox_.get_width(),coverageBox_.get_height());
            this->show_all_children();
        }
    }

    void catalyticReactors::composition()
    {
        this->remove();
        this->add(inputGrid_);
        this->resize(inputGrid_.get_width(),inputGrid_.get_height());
        this->show_all_children();
    }

    void catalyticReactors::switchTo()
    {
        signal.disconnect();
        if ( kineticCombo_.get_active_text() == "ASALI" && kineticType_ == "none")
        {
            signal = nextButton1_.signal_clicked().connect(sigc::mem_fun(*this,&catalyticReactors::propertiesShow));
        }
        else if ( kineticCombo_.get_active_text() == "ASALI" && kineticType_ == "default")
        {
            signal = nextButton1_.signal_clicked().connect(sigc::mem_fun(*this,&catalyticReactors::kineticShow));
        }
        else if ( kineticCombo_.get_active_text() == "ASALI" && kineticType_ == "load")
        {
            signal = nextButton1_.signal_clicked().connect(sigc::mem_fun(*this,&catalyticReactors::kineticShow));
        }
        else if ( kineticCombo_.get_active_text() == "CANTERA" && kineticType_ == "load")
        {
            signal = nextButton1_.signal_clicked().connect(sigc::mem_fun(*this,&catalyticReactors::coverage));
        }
        else
        {
            Gtk::MessageDialog dialog(*this,"No kinetic scheme implemented in database/data.xml,\nplease select ASALI kinetic type.",true,Gtk::MESSAGE_WARNING);
            dialog.set_secondary_text(this->getBeer(),true);
            dialog.run();
        }
    }

    std::string catalyticReactors::getBeer()
    {
        srand(time(NULL));
        int i = rand()%beer_.size();
        return beer_[i];
    }

    std::string catalyticReactors::getBeerShort()
    {
        srand(time(NULL));
        int i = rand()%beerShort_.size();
        return beerShort_[i];
    }

    std::string catalyticReactors::convertToTimeFormat(double t)
    {
        double h,m,s;
        t = modf(t/3600.,&h);
        t = t*3600.;
        t = modf(t/60,&m);
        t = t*60.;
        t = modf(t,&s);

        std::string ts;
        {
            std::ostringstream strs;
            strs << std::max(0.,h);
            ts = strs.str() + ":";
        }

        if (m > 9)
        {
            std::ostringstream strs;
            strs << std::max(0.,m);
            ts = ts + strs.str() + ":";
        }
        else
        {
            std::ostringstream strs;
            strs << std::max(0.,m);
            ts = ts + "0" + strs.str() + ":";
        }
        
        if (s > 9)
        {
            std::ostringstream strs;
            strs << std::max(0.,s);
            ts = ts + strs.str();
        }
        else
        {
            std::ostringstream strs;
            strs << std::max(0.,s);
            ts = ts + "0" + strs.str();
        }
        
        return ts;
    }

    void catalyticReactors::compositionReader()
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
            checkComposition_.first  = 4445;
            checkComposition_.second = false;
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
                        checkComposition_.first  = i;
                        checkComposition_.second = false;
                        break;
                    }
                    else
                    {
                        checkComposition_.first  = i;
                        checkComposition_.second = true;
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
                        checkComposition_.first  = 4444;
                        checkComposition_.second = false;
                    }
                }
            }
            else
            {
                checkComposition_.first  = 0;
                checkComposition_.second = true;
            }
        }
        
    }
    
    void catalyticReactors::coverageReader()
    {
        if ( kineticCombo_.get_active_text() == "CANTERA" )
        {
            std::vector<std::string>   n(SURF_NS_);
            std::vector<Glib::ustring> x(SURF_NS_);
            
            for (unsigned int i=0;i<SURF_NS_;i++)
            {
                n[i] = coverageNameEntry_[i]->get_text().c_str();
                x[i] = coverageFractionEntry_[i]->get_text().c_str();
            }

            nc_.clear();
            xc_.clear();
            for (unsigned int i=0;i<SURF_NS_;i++)
            {
                if ( !n[i].empty() )
                {
                    nc_.push_back(n[i]);
                }
                
                if ( !x[i].empty() )
                {
                    xc_.push_back(Glib::Ascii::strtod(x[i]));
                } 
            }
            
            if ( xc_.size() != nc_.size() )
            {
                checkCoverage_.first  = 4445;
                checkCoverage_.second = false;
            }
            else
            {
                std::vector<int> check(nc_.size());
                {
                    for (unsigned int i=0;i<nc_.size();i++)
                    {
                        check[i] = 1;
                        for (unsigned int j=0;j<surface_->nSpecies();j++)
                        {
                            if ( nc_[i] == surface_->speciesName(j) )
                            {
                                check[i] = 0;
                                break;
                            }
                        }
                    }

                    for (unsigned int i=0;i<check.size();i++)
                    {
                        if (check[i] == 1 )
                        {
                            checkCoverage_.first  = i;
                            checkCoverage_.second = false;
                            break;
                        }
                        else
                        {
                            checkCoverage_.first  = i;
                            checkCoverage_.second = true;
                        }
                    }

                    {
                        double sum = 0.;
                        for(unsigned int i=0;i<xc_.size();i++)
                        {
                            sum = sum + xc_[i];
                        }
                        
                        if ( sum != 1. )
                        {
                            checkCoverage_.first  = 4444;
                            checkCoverage_.second = false;
                        }
                    }
                }
            }
        }
        else
        {
            checkCoverage_.first  = 0;
            checkCoverage_.second = true;
        }
    }

    void catalyticReactors::checkComposition(unsigned int i)
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

    void catalyticReactors::checkCoverage(unsigned int i)
    {
        if ( i == 4444 )
        {
            Gtk::MessageDialog dialog(*this,"Please, the sum of mass/mole fractions should be 1.",true,Gtk::MESSAGE_WARNING);
            dialog.set_secondary_text(this->getBeer(),true);
            dialog.run();
        }
        else if ( i == 4445 )
        {
            Gtk::MessageDialog dialog(*this,"Something is wrong in your input, please fix it.",true,Gtk::MESSAGE_WARNING);
            dialog.set_secondary_text(this->getBeer(),true);
            dialog.run();
        }
        else
        {
            Gtk::MessageDialog dialog(*this,nc_[i]+" is missing!!",true,Gtk::MESSAGE_WARNING);
            dialog.set_secondary_text(this->getBeer(),true);
            dialog.run();
        }
    }

    void catalyticReactors::savedMessage()
    {
        Gtk::MessageDialog dialog(*this,"Your file has been saved.\nThank you for using ASALI.",true,Gtk::MESSAGE_OTHER);
        dialog.set_secondary_text(this->getBeerShort(),true);
        dialog.run();
    }

    void catalyticReactors::availableSpecies()
    {
        speciesNames_->show();
    }

    void catalyticReactors::kineticReader()
    {
        if ( kineticCombo_.get_active_text() == "ASALI")
        {
            index1_.clear();
            index2_.clear();

            for (unsigned int i=0;i<asaliKinetic_->get_NR();i++)
            {
                for (unsigned int j=0;j<4;j++)
                {
                    std::string name = asaliKinetic_->get_name()[i][j];
                    asaliProperties_->convertToCaption(name);
                    if ( name != "NONE" )
                    {
                        bool test = false;
                        for (unsigned int k=0;k<n_.size();k++)
                        {
                            if ( i == 0)
                            {
                                asaliProperties_->convertToCaption(n_[k]);
                            }

                            if ( name == n_[k] )
                            {
                                test = true;
                                break;
                            }
                        }

                        if ( test == false )
                        {
                            n_.push_back(name);
                            x_.push_back(0.0);
                        }
                        
                        if ( j == 0 )
                        {
                            index1_.push_back(this->specieIndex(name,n_));
                        }
                        else if ( j == 1 )
                        {
                            index2_.push_back(this->specieIndex(name,n_));
                        }
                    }
                    else
                    {
                        if ( j == 0 )
                        {
                            index1_.push_back(0);
                        }
                        else if ( j == 1 )
                        {
                            index2_.push_back(0);
                        }
                    }
                }
            }

            if ( inert_ != "NONE")
            {
                bool check = false;
                for (unsigned int i=0;i<n_.size();i++)
                {
                    if (n_[i] == inert_ )
                    {
                        check = true;
                        break;
                    }
                }

                if ( !check )
                {
                    n_.push_back(inert_);
                    x_.push_back(0.0);
                }
            }

            if ( kineticType_ == "none" )
            {
                canteraIndex_.resize(n_.size());
                for (unsigned int i=0;i<n_.size();i++)
                {
                    canteraIndex_[i] = 0;
                }
            }
            else
            {
                canteraIndex_.resize(n_.size());
                for (unsigned int i=0;i<n_.size();i++)
                {
                    canteraIndex_[i] = thermo_->speciesIndex(n_[i]);
                }
            }

            stoich_.resize(asaliKinetic_->get_NR());
            for (unsigned int i=0;i<asaliKinetic_->get_NR();i++)
            {
                stoich_[i].resize(n_.size());
                for (unsigned int j=0;j<asaliKinetic_->get_stoich()[i].size();j++)
                {
                    std::string name = asaliKinetic_->get_name()[i][j];
                    asaliProperties_->convertToCaption(name);
                    for (unsigned int k=0;k<n_.size();k++)
                    {
                        asaliProperties_->convertToCaption(n_[k]);
                        if ( name == n_[k] )
                        {
                            stoich_[i][k] = asaliKinetic_->get_stoich()[i][j];
                            break;
                        }
                    }
                }
            }
        }
    }

    void catalyticReactors::kineticShow()
    {
        asaliKinetic_->show();
        if ( kineticType_ == "none" )
        {
            signal.disconnect();
            signal = nextButton1_.signal_clicked().connect(sigc::mem_fun(*this,&catalyticReactors::propertiesShow));
        }
        else
        {
            signal.disconnect();
            signal = nextButton1_.signal_clicked().connect(sigc::mem_fun(*this,&catalyticReactors::recap));
        }
    }

    unsigned int catalyticReactors::specieIndex(const std::string n, const std::vector<std::string> v)
    {
        unsigned int id = 0;
        for(unsigned int i=0;i<v.size();i++)
        {
            if ( n == v[i] )
            {
                id = i;
                break;
            }
        }
        return id;
    }

    void catalyticReactors::bar(const double fraction,const std::string tm)
    {
        //Update solving bar
        while( Gtk::Main::events_pending() )
        {
            Gtk::Main::iteration();
        }


        bar_->update(fraction,tm);

        bar_->show();

        //Update solving bar
        while( Gtk::Main::events_pending() )
        {
            Gtk::Main::iteration();
        }
    }

    void catalyticReactors::exit()
    {
        this->hide();
    }

    void catalyticReactors::input() {}
    
    void catalyticReactors::recap() {}

    void catalyticReactors::propertiesShow() {}

    void catalyticReactors::catalystPropertiesShow() {}

    void catalyticReactors::save() {}
    
    void catalyticReactors::run() {}
    
    void catalyticReactors::plot() {}
}
