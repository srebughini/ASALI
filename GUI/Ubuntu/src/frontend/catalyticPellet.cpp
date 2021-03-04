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

#include "frontend/catalyticPellet.hpp"

namespace ASALI
{
    catalyticPellet::catalyticPellet(std::string kineticType)
        : catalyticReactors(kineticType),
          mainBox_(Gtk::ORIENTATION_VERTICAL),
          recapMainBox_(Gtk::ORIENTATION_VERTICAL),
          exitButton3_("Exit"),
          exitButton4_("Exit"),
          nextButton3_("Next"),
          backButton3_("Back"),
          recapButtonBox_(Gtk::ORIENTATION_VERTICAL),
          loadLabel_("Catalyst load"),
          timeLabel_("Integration time"),
          saveLabel_("Save solution every"),
          pointsLabel_("Number of points"),
          inertLabel_("Inert specie"),
          epsiLabel_("Void fraction"),
          tauLabel_("Tortuosity"),
          pelletTypeLabel_("Pellet shape"),
          modelTypeLabel_("Diffusion model"),
          poreLabel_("Pore diameter"),
          logo1_(this->relative_path_to_absolute_path("images/PelletLogo.png")),
          logo2_(this->relative_path_to_absolute_path("images/PelletLogo.png")),
          pelletType_("none"),
          modelType_("none"),
          modelBool_(false),
          recapModelBool_(false),
          plotButtonBool_(false)
    {
        eq_ = new ASALI::catalyticPelletEquations();

        //Input
        {
            this->set_border_width(15);
            this->set_title("ASALI: Catalytic pellets");
            this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
            this->set_icon_from_file(this->relative_path_to_absolute_path("images/Icon.png"));

            //Add background grid
            this->add(mainBox_);

            mainBox_.set_halign(Gtk::ALIGN_START);
            mainBox_.set_spacing(10);
            mainBox_.pack_start(logo1_, Gtk::PACK_SHRINK);
            mainBox_.pack_start(secondBox_, Gtk::PACK_SHRINK);

            secondBox_.set_halign(Gtk::ALIGN_START);
            secondBox_.set_spacing(10);
            secondBox_.pack_start(propertiesGrid_, Gtk::PACK_SHRINK);
            {
                propertiesGrid_.set_column_spacing(10);
                propertiesGrid_.set_row_spacing(10);
                propertiesGrid_.set_column_homogeneous(true);

                //Catalytic load
                propertiesGrid_.attach(loadLabel_, 0, 0, 1, 1);
                propertiesGrid_.attach(loadEntry_, 1, 0, 1, 1);
                loadEntry_.set_text("1");
                propertiesGrid_.attach(loadCombo_, 2, 0, 1, 1);
                loadCombo_.append("1/m");
                loadCombo_.append("1/dm");
                loadCombo_.append("1/cm");
                loadCombo_.append("1/mm");
                loadCombo_.set_active(0);

                //Time
                propertiesGrid_.attach(timeLabel_, 0, 1, 1, 1);
                propertiesGrid_.attach(timeEntry_, 1, 1, 1, 1);
                timeEntry_.set_text("1");
                propertiesGrid_.attach(timeCombo_, 2, 1, 1, 1);
                timeCombo_.append("s");
                timeCombo_.append("min");
                timeCombo_.append("h");
                timeCombo_.append("d");
                timeCombo_.set_active(0);

                //Save options
                propertiesGrid_.attach(saveLabel_, 0, 2, 1, 1);
                propertiesGrid_.attach(saveEntry_, 1, 2, 1, 1);
                saveEntry_.set_text("0.1");
                propertiesGrid_.attach(saveCombo_, 2, 2, 1, 1);
                saveCombo_.append("s");
                saveCombo_.append("min");
                saveCombo_.append("h");
                saveCombo_.append("d");
                saveCombo_.set_active(0);

                //Number of points
                propertiesGrid_.attach(pointsLabel_, 3, 0, 1, 1);
                propertiesGrid_.attach(pointsEntry_, 4, 0, 1, 1);
                pointsEntry_.set_text("10");

                //Inert species
                propertiesGrid_.attach(inertLabel_, 3, 1, 1, 1);
                propertiesGrid_.attach(inertEntry_, 4, 1, 1, 1);
                inertEntry_.set_text("AR");

                //Beer
                propertiesGrid_.attach(beerLabel_, 0, 4, 3, 2);
                beerLabel_.set_text(this->getBeerShort());
                beerLabel_.set_use_markup(true);
                beerLabel_.set_justify(Gtk::JUSTIFY_CENTER);

                //Model
                propertiesGrid_.attach(modelTypeLabel_, 3, 2, 1, 1);
                propertiesGrid_.attach(modelTypeCombo_, 4, 2, 1, 1);
                modelTypeCombo_.append("\u03B5-\u03C4 model");
                modelTypeCombo_.append("Dusty Gas Model");
                modelTypeCombo_.signal_changed().connect(sigc::mem_fun(*this, &catalyticPellet::modelOptions));
                modelTypeCombo_.set_active(0);

                //Void fractoin
                propertiesGrid_.attach(epsiLabel_, 3, 3, 1, 1);
                propertiesGrid_.attach(epsiEntry_, 4, 3, 1, 1);
                epsiEntry_.set_text("0.75");

                //Tortuosity
                propertiesGrid_.attach(tauLabel_, 3, 4, 1, 1);
                propertiesGrid_.attach(tauEntry_, 4, 4, 1, 1);
                tauEntry_.set_text("7");

                //Type
                propertiesGrid_.attach(pelletTypeLabel_, 3, 5, 1, 1);
                propertiesGrid_.attach(pelletTypeCombo_, 4, 5, 1, 1);
                pelletTypeCombo_.append("slab");
                pelletTypeCombo_.append("sphere");
                pelletTypeCombo_.append("cylinder");
                pelletTypeCombo_.signal_changed().connect(sigc::mem_fun(*this, &catalyticPellet::pelletOptions));
                pelletTypeCombo_.set_active(0);

                //Length
                propertiesGrid_.attach(lengthLabel_, 0, 3, 1, 1);
                lengthLabel_.set_text("Thickness");
                propertiesGrid_.attach(lengthEntry_, 1, 3, 1, 1);
                lengthEntry_.set_text("1");
                propertiesGrid_.attach(lengthCombo_, 2, 3, 1, 1);
                lengthCombo_.append("m");
                lengthCombo_.append("dm");
                lengthCombo_.append("cm");
                lengthCombo_.append("mm");
                lengthCombo_.append("\u03BCm");
                lengthCombo_.set_active(2);

                //Pore
                poreEntry_.set_text("1");
                poreCombo_.append("cm");
                poreCombo_.append("mm");
                poreCombo_.append("\u03BCm");
                poreCombo_.set_active(2);

                //Buttons
                propertiesGrid_.attach(exitButton3_, 0, 11, 2, 1);
                exitButton3_.signal_clicked().connect(sigc::mem_fun(*this, &catalyticPellet::exit));
                propertiesGrid_.attach(nextButton3_, 3, 11, 2, 1);
                nextButton3_.signal_clicked().connect(sigc::mem_fun(*this, &catalyticPellet::composition));

                this->show_all_children();
            }
        }

        //Recap
        {
            recapMainBox_.set_halign(Gtk::ALIGN_CENTER);
            recapMainBox_.set_spacing(10);
            recapMainBox_.pack_start(logoBox_, Gtk::PACK_SHRINK);
            {
                logoBox_.set_halign(Gtk::ALIGN_CENTER);
                logoBox_.set_spacing(10);
                logoBox_.pack_start(logo2_, Gtk::PACK_SHRINK);
                logoBox_.pack_start(recapButtonBox_, Gtk::PACK_SHRINK);
                {
                    recapButtonBox_.set_layout(Gtk::BUTTONBOX_CENTER);
                    recapButtonBox_.set_spacing(10);
                    recapButtonBox_.set_homogeneous(true);
                    recapButtonBox_.pack_start(runButton_, Gtk::PACK_SHRINK);
                    runButton_.signal_clicked().connect(sigc::mem_fun(*this, &catalyticPellet::run));
                    recapButtonBox_.pack_start(saveButton_, Gtk::PACK_SHRINK);
                    saveButton_.signal_clicked().connect(sigc::mem_fun(*this, &catalyticPellet::save));
                    asaliPlotButton_.signal_clicked().connect(sigc::mem_fun(*this, &catalyticPellet::plot));

                    asaliKineticButton_.signal_clicked().connect(sigc::mem_fun(*this, &catalyticPellet::kineticShow));
                    asaliPropertiesButton_.signal_clicked().connect(sigc::mem_fun(*this, &catalyticPellet::propertiesShow));

                    {
                        if (kineticType_ == "none")
                        {
                            recapButtonBox_.pack_start(asaliKineticButton_, Gtk::PACK_SHRINK);
                            recapButtonBox_.pack_start(asaliPropertiesButton_, Gtk::PACK_SHRINK);
                        }
                        else if (kineticType_ == "default")
                        {
                            recapButtonBox_.pack_start(asaliKineticButton_, Gtk::PACK_SHRINK);
                        }
                        else if (kineticType_ == "nokinetic")
                        {
                            recapButtonBox_.pack_start(asaliKineticButton_, Gtk::PACK_SHRINK);
                        }
                        else if (kineticType_ == "load")
                        {
                        }
                    }
                }
            }

            recapMainBox_.pack_start(recapBox_, Gtk::PACK_SHRINK);
            {
                recapBox_.set_halign(Gtk::ALIGN_START);
                recapBox_.set_spacing(10);
                recapBox_.pack_start(recapGrid_, Gtk::PACK_SHRINK);
                {
                    recapGrid_.set_column_spacing(10);
                    recapGrid_.set_row_spacing(10);
                    recapGrid_.set_column_homogeneous(true);

                    //Reactor type
                    recapPelletTypeLabel_.set_text("Pellet type");
                    recapGrid_.attach(recapPelletTypeLabel_, 0, 0, 1, 1);
                    recapGrid_.attach(recapPelletTypeValueLabel_, 1, 0, 1, 1);

                    //Kinetic type
                    recapKineticLabel_.set_text("Kinetic model from");
                    recapGrid_.attach(recapKineticLabel_, 0, 1, 1, 1);
                    recapGrid_.attach(recapKineticValueLabel_, 1, 1, 1, 1);

                    //Time
                    recapTimeLabel_.set_text("Integration time");
                    recapTimeUDLabel_.set_text("s");
                    recapGrid_.attach(recapTimeLabel_, 0, 2, 1, 1);
                    recapGrid_.attach(recapTimeUDLabel_, 2, 2, 1, 1);
                    recapGrid_.attach(recapTimeValueLabel_, 1, 2, 1, 1);

                    //Save
                    recapSaveLabel_.set_text("Save solution every");
                    recapSaveUDLabel_.set_text("s");
                    recapGrid_.attach(recapSaveLabel_, 0, 3, 1, 1);
                    recapGrid_.attach(recapSaveUDLabel_, 2, 3, 1, 1);
                    recapGrid_.attach(recapSaveValueLabel_, 1, 3, 1, 1);

                    //Points
                    recapPointsLabel_.set_text("Solving with");
                    recapPointsUDLabel_.set_text("points");
                    recapGrid_.attach(recapPointsLabel_, 0, 4, 1, 1);
                    recapGrid_.attach(recapPointsUDLabel_, 2, 4, 1, 1);
                    recapGrid_.attach(recapPointsValueLabel_, 1, 4, 1, 1);

                    //Inert
                    recapInertLabel_.set_text("Inert species is");
                    recapGrid_.attach(recapInertLabel_, 0, 5, 1, 1);
                    recapGrid_.attach(recapInertValueLabel_, 1, 5, 1, 1);

                    //Load
                    recapLoadLabel_.set_text("Catalytic load");
                    recapGrid_.attach(recapLoadLabel_, 0, 6, 1, 1);
                    recapLoadUDLabel_.set_text("1/m");
                    recapGrid_.attach(recapLoadUDLabel_, 2, 6, 1, 1);
                    recapGrid_.attach(recapLoadValueLabel_, 1, 6, 1, 1);

                    //Epsi
                    recapEpsiLabel_.set_text("Void fraction");
                    recapGrid_.attach(recapEpsiLabel_, 0, 7, 1, 1);
                    recapGrid_.attach(recapEpsiValueLabel_, 1, 7, 1, 1);

                    //Tau
                    recapTauLabel_.set_text("Tortuosity");
                    recapGrid_.attach(recapTauLabel_, 0, 8, 1, 1);
                    recapGrid_.attach(recapTauValueLabel_, 1, 8, 1, 1);

                    //Model
                    recapModelTypeLabel_.set_text("Diffusion model");
                    recapGrid_.attach(recapModelTypeLabel_, 0, 9, 1, 1);
                    recapGrid_.attach(recapModelTypeValueLabel_, 1, 9, 1, 1);
                    recapPoreLabel_.set_text("Pore diameter");
                    recapPoreUDLabel_.set_text("m");

                    //Temperature
                    recapTemperatureLabel_.set_text("Temperature");
                    recapGrid_.attach(recapTemperatureLabel_, 3, 1, 1, 1);
                    recapGrid_.attach(recapTemperatureUDLabel_, 5, 1, 1, 1);
                    recapTemperatureUDLabel_.set_text("K");
                    recapGrid_.attach(recapTemperatureValueLabel_, 4, 1, 1, 1);

                    //Pressure
                    recapPressureLabel_.set_text("Pressure");
                    recapGrid_.attach(recapPressureLabel_, 3, 2, 1, 1);
                    recapGrid_.attach(recapPressureUDLabel_, 5, 2, 1, 1);
                    recapPressureUDLabel_.set_text("Pa");
                    recapGrid_.attach(recapPressureValueLabel_, 4, 2, 1, 1);

                    //Length
                    recapGrid_.attach(recapLengthLabel_, 3, 0, 1, 1);
                    recapGrid_.attach(recapLengthUDLabel_, 5, 0, 1, 1);
                    recapLengthUDLabel_.set_text("m");
                    recapGrid_.attach(recapLengthValueLabel_, 4, 0, 1, 1);

                    //Fraction
                    recapGrid_.attach(recapFractionLabel_, 3, 3, 1, 1);
                    recapGrid_.attach(recapFractionNameLabel_, 5, 3, 1, 1);
                    recapGrid_.attach(recapFractionValueLabel_, 4, 3, 1, 1);

                    //Buttons
                    recapGrid_.attach(backButton3_, 0, 13, 3, 1);
                    backButton3_.signal_clicked().connect(sigc::mem_fun(*this, &catalyticPellet::input));
                    recapGrid_.attach(exitButton4_, 3, 13, 3, 1);
                    exitButton4_.signal_clicked().connect(sigc::mem_fun(*this, &catalyticPellet::exit));
                }
            }
        }
    }

    catalyticPellet::~catalyticPellet()
    {
    }

    void catalyticPellet::pelletOptions()
    {
        {
            beerLabel_.set_text(this->getBeerShort());
            beerLabel_.set_use_markup(true);
            beerLabel_.set_justify(Gtk::JUSTIFY_CENTER);
        }

        if (pelletTypeCombo_.get_active_row_number() == 0)
        {
            lengthLabel_.set_text("Thickness");
            pelletType_ = "slab";
        }
        else if (pelletTypeCombo_.get_active_row_number() == 1)
        {
            lengthLabel_.set_text("Diameter");
            pelletType_ = "sphere";
        }
        else if (pelletTypeCombo_.get_active_row_number() == 2)
        {
            lengthLabel_.set_text("Diameter");
            pelletType_ = "cylinder";
        }
        this->resize(mainBox_.get_width(), mainBox_.get_height());
        this->show_all_children();
    }

    void catalyticPellet::modelOptions()
    {
        {
            beerLabel_.set_text(this->getBeerShort());
            beerLabel_.set_use_markup(true);
            beerLabel_.set_justify(Gtk::JUSTIFY_CENTER);
        }

        if (modelBool_)
        {
            propertiesGrid_.remove(poreLabel_);
            propertiesGrid_.remove(poreEntry_);
            propertiesGrid_.remove(poreCombo_);
        }
        else
        {
            propertiesGrid_.remove(beerLabel_);
        }

        if (modelTypeCombo_.get_active_row_number() == 0)
        {
            propertiesGrid_.attach(beerLabel_, 0, 4, 3, 2);
            modelBool_ = false;
        }
        else if (modelTypeCombo_.get_active_row_number() == 1)
        {
            propertiesGrid_.attach(poreLabel_, 0, 4, 1, 1);
            propertiesGrid_.attach(poreEntry_, 1, 4, 1, 1);
            propertiesGrid_.attach(poreCombo_, 2, 4, 1, 1);
            modelBool_ = true;
        }

        this->resize(mainBox_.get_width(), mainBox_.get_height());
        this->show_all_children();
    }

    void catalyticPellet::clean()
    {
        recapGrid_.remove(recapFractionLabel_);
        recapGrid_.remove(recapFractionNameLabel_);
        recapGrid_.remove(recapFractionValueLabel_);

        if (recapModelBool_)
        {
            recapGrid_.remove(recapPoreLabel_);
            recapGrid_.remove(recapPoreUDLabel_);
            recapGrid_.remove(recapPoreValueLabel_);
        }

        if (plotButtonBool_)
        {
            recapButtonBox_.remove(asaliPlotButton_);
            plotButtonBool_ = false;
        }
    }

    void catalyticPellet::read()
    {
        tf_ = Glib::Ascii::strtod(timeEntry_.get_text());
        dt_ = Glib::Ascii::strtod(saveEntry_.get_text());
        NP_ = Glib::Ascii::strtod(pointsEntry_.get_text());
        alfa_ = Glib::Ascii::strtod(loadEntry_.get_text());
        epsi_ = Glib::Ascii::strtod(epsiEntry_.get_text());
        tau_ = Glib::Ascii::strtod(tauEntry_.get_text());
        L_ = Glib::Ascii::strtod(lengthEntry_.get_text());

        ConvertsToSecond(tf_, timeCombo_.get_active_text());
        ConvertsToSecond(dt_, saveCombo_.get_active_text());
        ConvertsToOneOverMeter(alfa_, loadCombo_.get_active_text());
        ConvertsToMeter(L_, lengthCombo_.get_active_text());

        pelletType_ = pelletTypeCombo_.get_active_text();
        modelType_ = modelTypeCombo_.get_active_text();
        inert_ = inertEntry_.get_text();
        constantProperties_->convertToCaption(inert_);

        if (modelTypeCombo_.get_active_row_number() == 0)
        {
            dp_ = 0.;
        }
        else if (modelTypeCombo_.get_active_row_number() == 1)
        {
            dp_ = Glib::Ascii::strtod(poreEntry_.get_text());
            ConvertsToMeter(dp_, poreCombo_.get_active_text());
        }
    }

    void catalyticPellet::input()
    {
        {
            signal.disconnect();
            signal = nextButton1_.signal_clicked().connect(sigc::mem_fun(*this, &catalyticPellet::kineticShow));
        }
        this->switchTo();
        this->remove();
        this->add(mainBox_);
        this->resize(mainBox_.get_width(), mainBox_.get_height());
        this->show_all_children();
    }

    void catalyticPellet::recap()
    {
        this->compositionReader();
        this->coverageReader();
        if (checkComposition_.second == false)
        {
            this->checkComposition(checkComposition_.first);
        }
        else if (checkCoverage_.second == false)
        {
            this->checkCoverage(checkCoverage_.first);
        }
        else
        {
            this->read();
            this->kineticReader();
            this->clean();
            this->remove();
            this->add(recapMainBox_);

            //Pellet type
            {
                recapPelletTypeValueLabel_.set_text(pelletType_);
            }

            //Model type
            {
                recapModelTypeValueLabel_.set_text(modelType_);
            }

            if (modelTypeCombo_.get_active_row_number() == 0)
            {
                recapModelBool_ = false;
            }
            else if (modelTypeCombo_.get_active_row_number() == 1)
            {
                //Temperature
                {
                    std::ostringstream s;
                    s << dp_;
                    recapPoreValueLabel_.set_text(s.str());
                }
                recapGrid_.attach(recapPoreLabel_, 0, 10, 1, 1);
                recapGrid_.attach(recapPoreUDLabel_, 2, 10, 1, 1);
                recapGrid_.attach(recapPoreValueLabel_, 1, 10, 1, 1);
                recapModelBool_ = true;
            }

            //Temperature
            {
                std::ostringstream s;
                s << T_;
                recapTemperatureValueLabel_.set_text(s.str());
            }

            //Pressure
            {
                std::ostringstream s;
                s << p_;
                recapPressureValueLabel_.set_text(s.str());
            }

            int NC = -1;
            //Mole/mass fraction
            {
                recapFractionLabel_.set_text(fractionCombo_.get_active_text());
                {
                    std::string s1;
                    std::string s2;
                    for (unsigned int i = 0; i < n_.size(); i++)
                    {
                        if (x_[i] != 0 && NC == -1)
                        {
                            s1 = n_[i];
                            std::ostringstream so;
                            so << x_[i];
                            s2 = so.str();
                            NC++;
                        }
                        else if (x_[i] != 0 && NC != -1)
                        {
                            s1 = s1 + "\n" + n_[i];
                            std::ostringstream so;
                            so << x_[i];
                            s2 = s2 + "\n" + so.str();
                            NC++;
                        }
                    }
                    recapFractionNameLabel_.set_text(s1);
                    recapFractionValueLabel_.set_text(s2);
                }

                {
                }
            }

            //Time
            {
                std::ostringstream s;
                s << tf_;
                recapTimeValueLabel_.set_text(s.str());
            }

            //Save
            {
                std::ostringstream s;
                s << dt_;
                recapSaveValueLabel_.set_text(s.str());
            }

            //Points
            {
                std::ostringstream s;
                s << NP_;
                recapPointsValueLabel_.set_text(s.str());
            }

            //Inert
            {
                recapInertValueLabel_.set_text(inert_);
            }

            //Load
            {
                std::ostringstream s;
                s << alfa_;
                recapLoadValueLabel_.set_text(s.str());
            }

            //Epsi
            {
                std::ostringstream s;
                s << epsi_;
                recapEpsiValueLabel_.set_text(s.str());
            }

            //Tau
            {
                std::ostringstream s;
                s << tau_;
                recapTauValueLabel_.set_text(s.str());
            }

            if (pelletType_ == "slab")
            {
                recapLengthLabel_.set_text("Thickness");
                {
                    std::ostringstream s;
                    s << L_;
                    recapLengthValueLabel_.set_text(s.str());
                }
            }
            else if (pelletType_ == "sphere")
            {
                recapLengthLabel_.set_text("Diameter");
                {
                    std::ostringstream s;
                    s << L_;
                    recapLengthValueLabel_.set_text(s.str());
                }
            }
            else if (pelletType_ == "cylinder")
            {
                recapLengthLabel_.set_text("Diameter");
                {
                    std::ostringstream s;
                    s << L_;
                    recapLengthValueLabel_.set_text(s.str());
                }
            }

            //Fractions
            {
                recapGrid_.attach(recapFractionLabel_, 3, 3, 1, NC + 1);
                recapGrid_.attach(recapFractionNameLabel_, 5, 3, 1, NC + 1);
                recapGrid_.attach(recapFractionValueLabel_, 4, 3, 1, NC + 1);
            }

            //Kinetic
            {
                recapKineticValueLabel_.set_text(kineticCombo_.get_active_text());
            }

            if (kineticType_ == "load" && kineticCombo_.get_active_text() == "ASALI")
            {
                if (asaliKineticButton_.get_parent() != nullptr)
                {
                    recapButtonBox_.remove(asaliKineticButton_);
                }
                recapButtonBox_.pack_start(asaliKineticButton_, Gtk::PACK_SHRINK);
            }
        }
        this->resize(recapMainBox_.get_width(), recapMainBox_.get_height());
        this->show_all_children();
    }

    void catalyticPellet::run()
    {
        if (kineticCombo_.get_active_text() == "CANTERA")
        {
            eq_->setInterface(chemistryInterface_);
            eq_->turnOnUserDefined(false);

            if (chemistryInterface_->numberOfHomogeneousReactions() != 0.)
            {
                Gtk::MessageDialog smallDialog(*this, "We detect that your CANTERA input file has GAS PHASE reactions.\nDo you wonna enable them?", true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_YES_NO);
                smallDialog.set_secondary_text(this->getBeerShort(), true);
                int answer = smallDialog.run();

                //Handle the response:
                switch (answer)
                {
                case (Gtk::RESPONSE_YES):
                {
                    eq_->setHomogeneousReactions(true);
                    smallDialog.hide();
                    break;
                }
                case (Gtk::RESPONSE_NO):
                {
                    eq_->setHomogeneousReactions(false);
                    smallDialog.hide();
                    break;
                }
                default:
                {
                    smallDialog.hide();
                    break;
                }
                }
            }
            else
            {
                eq_->setHomogeneousReactions(false);
            }
        }
        else if (kineticCombo_.get_active_text() == "ASALI")
        {
            if (kineticType_ == "none")
            {
                this->compositionReader();
                this->kineticReader();
                eq_->turnOnUserDefined(true);
                eq_->setAsaliKinetic(pi_, canteraIndex_, n_);
                eq_->set_MW(constantProperties_->get_MW());
                eq_->setHomogeneousReactions(true);
            }
            else
            {
                this->compositionReader();
                this->kineticReader();
                eq_->setInterface(chemistryInterface_);
                eq_->turnOnUserDefined(false);
                eq_->setAsaliKinetic(pi_, canteraIndex_, n_);
                eq_->setHomogeneousReactions(true);
            }
        }

        eq_->setKineticType(kineticCombo_.get_active_text());
        eq_->setNumberOfPoints(NP_);
        eq_->setPelletType(pelletType_);
        eq_->setDiffusionModel(modelType_);
        eq_->resize();

        if (pelletType_ == "slab")
        {
            eq_->setSlab(L_);
        }
        else if (pelletType_ == "sphere")
        {
            eq_->setSphere(L_);
        }
        else if (pelletType_ == "cylinder")
        {
            eq_->setCylinder(L_);
        }

        eq_->setHeterogeneusReactions(true);
        eq_->setPressure(p_);
        eq_->setTemperature(T_);
        eq_->setCatalystProperties(alfa_, tau_, epsi_);
        eq_->setPoreDiameter(dp_);

        std::vector<double> x0(eq_->NumberOfEquations());
        if (kineticType_ == "none")
        {
            std::vector<double> xInlet(x_.size());
            if (fractionCombo_.get_active_row_number() == 0)
            {
                xInlet = constantProperties_->get_mass_fraction(constantProperties_->get_MW(), x_);
            }
            else if (fractionCombo_.get_active_row_number() == 1)
            {
                for (unsigned int i = 0; i < x_.size(); i++)
                {
                    xInlet[i] = x_[i];
                }
            }

            std::vector<double> xInside(x_.size());
            for (unsigned int i = 0; i < x_.size(); i++)
            {
                if (n_[i] == inert_)
                {
                    eq_->setInert(i);
                    xInside[i] = 1.;
                }
                else
                {
                    xInside[i] = 0.;
                }
            }

            unsigned int counter = 0;
            for (unsigned int i = 0; i < NP_; i++)
            {
                for (unsigned int j = 0; j < x_.size(); j++)
                {
                    if (i == 0)
                    {
                        if (pelletType_ == "slab")
                        {
                            x0[counter++] = xInlet[j];
                        }
                        else if (pelletType_ == "sphere")
                        {
                            x0[counter++] = xInside[j];
                        }
                        else if (pelletType_ == "cylinder")
                        {
                            x0[counter++] = xInlet[j];
                        }
                    }
                    else if (i == (NP_ - 1))
                    {
                        x0[counter++] = xInlet[j];
                    }
                    else
                    {
                        x0[counter++] = xInside[j];
                    }
                }
            }
            eq_->setInletConditions(xInlet);
        }
        else
        {
            if (kineticCombo_.get_active_text() == "ASALI")
            {
                chemistryInterface_->setTemperature(T_);
                chemistryInterface_->setPressure(p_);
                if (fractionCombo_.get_active_row_number() == 0)
                {
                    chemistryInterface_->setMoleFraction(x_, n_);
                }
                else if (fractionCombo_.get_active_row_number() == 1)
                {
                    chemistryInterface_->setMassFraction(x_, n_);
                }

                std::vector<double> xInlet(x_.size());
                {
                    std::vector<double> y = chemistryInterface_->mass();
                    for (unsigned int i = 0; i < n_.size(); i++)
                    {
                        for (unsigned int j = 0; j < chemistryInterface_->numberOfGasSpecies(); j++)
                        {
                            if (n_[i] == chemistryInterface_->names()[j])
                            {
                                xInlet[i] = y[j];
                                break;
                            }
                        }
                    }
                }

                std::vector<double> xInside(x_.size());
                for (unsigned int i = 0; i < x_.size(); i++)
                {
                    if (n_[i] == inert_)
                    {
                        eq_->setInert(i);
                        xInside[i] = 1.;
                    }
                    else
                    {
                        xInside[i] = 0.;
                    }
                }
                unsigned int counter = 0;
                for (unsigned int i = 0; i < NP_; i++)
                {
                    for (unsigned int j = 0; j < x_.size(); j++)
                    {
                        if (i == 0)
                        {
                            if (pelletType_ == "slab")
                            {
                                x0[counter++] = xInlet[j];
                            }
                            else if (pelletType_ == "sphere")
                            {
                                x0[counter++] = xInside[j];
                            }
                            else if (pelletType_ == "cylinder")
                            {
                                x0[counter++] = xInlet[j];
                            }
                        }
                        else if (i == (NP_ - 1))
                        {
                            x0[counter++] = xInlet[j];
                        }
                        else
                        {
                            x0[counter++] = xInside[j];
                        }
                    }
                }
                eq_->setInletConditions(xInlet);
            }
            else
            {
                chemistryInterface_->setTemperature(T_);
                chemistryInterface_->setPressure(p_);
                if (fractionCombo_.get_active_row_number() == 0)
                {
                    chemistryInterface_->setMoleFraction(x_, n_);
                }
                else if (fractionCombo_.get_active_row_number() == 1)
                {
                    chemistryInterface_->setMassFraction(x_, n_);
                }

                std::vector<double> xInlet(chemistryInterface_->numberOfGasSpecies());
                std::vector<double> xInside(chemistryInterface_->numberOfGasSpecies());
                {
                    std::vector<double> y = chemistryInterface_->mass();
                    std::vector<std::string> names = chemistryInterface_->names();
                    for (unsigned int i = 0; i < chemistryInterface_->numberOfGasSpecies(); i++)
                    {
                        if (names[i] == inert_)
                        {
                            eq_->setInert(i);
                            xInlet[i] = y[i];
                            xInside[i] = 1.;
                        }
                        else
                        {
                            xInlet[i] = y[i];
                            xInside[i] = 0.;
                        }
                    }
                }

                std::vector<double> thetaInlet(chemistryInterface_->numberOfSurfaceSpecies());
                {
                    std::vector<std::string> coverageNames = chemistryInterface_->coverageNames();
                    for (unsigned int i = 0; i < nc_.size(); i++)
                    {
                        for (unsigned int j = 0; j < chemistryInterface_->numberOfSurfaceSpecies(); j++)
                        {
                            if (nc_[i] == coverageNames[j])
                            {
                                thetaInlet[j] = xc_[i];
                                break;
                            }
                        }
                    }
                }

                unsigned int counter = 0;
                for (unsigned int i = 0; i < NP_; i++)
                {
                    for (unsigned int j = 0; j < chemistryInterface_->numberOfGasSpecies(); j++)
                    {
                        if (i == 0)
                        {
                            if (pelletType_ == "slab")
                            {
                                x0[counter++] = xInlet[j];
                            }
                            else if (pelletType_ == "sphere")
                            {
                                x0[counter++] = xInside[j];
                            }
                            else if (pelletType_ == "cylinder")
                            {
                                x0[counter++] = xInlet[j];
                            }
                        }
                        else if (i == (NP_ - 1))
                        {
                            x0[counter++] = xInlet[j];
                        }
                        else
                        {
                            x0[counter++] = xInside[j];
                        }
                    }
                    for (unsigned int j = 0; j < chemistryInterface_->numberOfSurfaceSpecies(); j++)
                    {
                        x0[counter++] = thetaInlet[j];
                    }
                }
                eq_->setInletConditions(xInlet);
            }
        }

        ASALI::odeInterface<ASALI::catalyticPelletEquations> ode;
        ASALI::bvpInterface<ASALI::catalyticPelletEquations> bvp;

        eq_->setResolutionType("initial");
        this->bar(0., "Starting...");
        ode.setEquations(eq_);
        ode.setInitialConditions(0., x0);
        ode.solve(1e07, x0);

        bvp.setEquations(eq_);
        bvp.setBandDimensions(eq_->NumberOfEquations() / NP_ + 1, eq_->NumberOfEquations() / NP_ + 1);
        eq_->setResolutionType("model");
        eq_->store(0., x0);
        this->bar(1e-05, "Starting...");

        //Start solving
        {
            double ti = 0.;
            double tf = 0.;
            double dt = 0.;

            if (alfa_ != 0.)
            {
                dt = dt_ / (eq_->NumberOfEquations() * 5.);
            }
            else
            {
                dt = dt_ / 100.;
            }

            double td = 0;
            double time0 = double(std::clock() / CLOCKS_PER_SEC);
            double timef = 0.;
            double tm = 0;
            int Nt = int(tf_ / dt) + 1;
            for (int i = 0; i < Nt; i++)
            {
                tf = ti + dt;

                bvp.setInitialConditions(ti, x0);
                bvp.solve(tf, x0);

                td += dt;

                if (std::fabs(td - dt_) < dt * 0.001)
                {
                    eq_->store(tf, x0);
                    td = 0.;
                }

                timef = double(std::clock() / CLOCKS_PER_SEC);
                tm = (timef - time0) * (Nt - i + 1) / (i + 1);

                ti = tf;

                this->bar(double(i + 1) * dt / tf_, "Remaning time: " + this->convertToTimeFormat(tm));

                if (!bar_->check() || !bvp.check())
                {
                    break;
                }
            }
        }

        bar_->exit();

        if (ode.check() == true &&
            bvp.check() == true &&
            bar_->check() == true)
        {
            if (!plotButtonBool_)
            {
                recapButtonBox_.pack_start(asaliPlotButton_, Gtk::PACK_SHRINK);
                plotButtonBool_ = true;
                this->show_all_children();
            }
            this->save();
        }
    }

    void catalyticPellet::propertiesShow()
    {
        this->read();
        this->compositionReader();
        this->kineticReader();
        constantProperties_->destroy();
        constantProperties_->set_type("pellet");
        constantProperties_->set_energy("off");
        constantProperties_->set_n(n_);
        constantProperties_->set_reactions(pi_->getNumberOfHomReactions(), pi_->getNumberOfHetReactions());
        constantProperties_->build();
        constantProperties_->show();

        {
            signal.disconnect();
            signal = nextButton1_.signal_clicked().connect(sigc::mem_fun(*this, &catalyticPellet::recap));
        }
    }

    void catalyticPellet::save()
    {
        std::string filename = this->save_file(this->get_toplevel()->gobj(), "pellet.asali");
        if (filename != "")
        {
            std::ofstream output;
            const char *path = filename.c_str();
            output.open(path, std::ios::out);
            output.setf(std::ios::scientific);
            output.precision(6);

            output << "Kinetic type:     " << kineticCombo_.get_active_text() << std::endl;
            output << "Model   type:     " << std::string(modelTypeCombo_.get_active_text()) << std::endl;
            output << "Pellet shape:     " << std::string(pelletTypeCombo_.get_active_text()) << std::endl;
            output << "Pressure:         " << p_ << " Pa" << std::endl;
            output << "Temperature:      " << T_ << " K" << std::endl;
            output << "Integration time: " << tf_ << " s" << std::endl;

            std::vector<double> t = eq_->getTime();
            std::vector<std::vector<std::vector<double>>> y = eq_->getSpecie();
            std::vector<std::vector<std::vector<double>>> Z = eq_->getSite();
            double dz = eq_->getLength() / double(NP_ - 1);

            if (kineticCombo_.get_active_text() == "ASALI")
            {
                //Conversion from mass to mole
                std::vector<std::vector<std::vector<double>>> mole = eq_->getSpecie();
                {
                    if (kineticType_ == "none")
                    {
                        for (unsigned int j = 0; j < t.size(); j++)
                        {
                            for (unsigned int k = 0; k < NP_; k++)
                            {
                                std::vector<double> x(n_.size());
                                for (unsigned int i = 0; i < n_.size(); i++)
                                {
                                    x[i] = y[j][k][i];
                                }

                                x = constantProperties_->get_mole_fraction(constantProperties_->get_MW(), x);

                                for (unsigned int i = 0; i < n_.size(); i++)
                                {
                                    mole[j][k][i] = x[i];
                                }
                            }
                        }
                    }
                    else
                    {
                        for (unsigned int j = 0; j < t.size(); j++)
                        {
                            for (unsigned int k = 0; k < NP_; k++)
                            {
                                chemistryInterface_->setTemperature(T_);
                                chemistryInterface_->setPressure(p_);
                                std::vector<double> x(n_.size());

                                for (unsigned int i = 0; i < n_.size(); i++)
                                {
                                    x[i] = y[j][k][i];
                                }
                                chemistryInterface_->setMassFraction(x, n_);

                                for (unsigned int i = 0; i < n_.size(); i++)
                                {
                                    for (unsigned int q = 0; q < chemistryInterface_->names().size(); q++)
                                    {
                                        if (n_[i] == chemistryInterface_->names()[q])
                                        {
                                            mole[j][k][i] = chemistryInterface_->mole()[q];
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                for (unsigned int i = 0; i < n_.size(); i++)
                {
                    output << "\nSpecie:           " << n_[i] << std::endl;

                    output << "Mass fraction" << std::endl;
                    output << "Length [m]/Time [s]"
                           << "\t";
                    for (unsigned int j = 0; j < t.size(); j++)
                    {
                        output << t[j] << "\t";
                    }

                    output << std::endl;

                    for (unsigned int k = 0; k < NP_; k++)
                    {
                        output << k * dz << "\t";
                        for (unsigned int j = 0; j < t.size(); j++)
                        {
                            output << y[j][k][i] << "\t";
                        }
                        output << std::endl;
                    }
                    output << std::endl;
                    output << "Mole fraction" << std::endl;
                    output << "Length [m]/Time [s]"
                           << "\t";
                    for (unsigned int j = 0; j < t.size(); j++)
                    {
                        output << t[j] << "\t";
                    }

                    output << std::endl;

                    for (unsigned int k = 0; k < NP_; k++)
                    {
                        output << k * dz << "\t";
                        for (unsigned int j = 0; j < t.size(); j++)
                        {
                            output << mole[j][k][i] << "\t";
                        }
                        output << std::endl;
                    }
                    output << std::endl;
                }
            }
            else if (kineticCombo_.get_active_text() == "CANTERA")
            {
                //Conversion from mass to mole
                std::vector<std::vector<std::vector<double>>> mole = eq_->getSpecie();
                std::vector<std::string> n = chemistryInterface_->names();
                {
                    for (unsigned int j = 0; j < t.size(); j++)
                    {
                        for (unsigned int k = 0; k < NP_; k++)
                        {
                            chemistryInterface_->setTemperature(T_);
                            chemistryInterface_->setPressure(p_);
                            std::vector<double> x(chemistryInterface_->numberOfGasSpecies());
                            for (unsigned int i = 0; i < chemistryInterface_->numberOfGasSpecies(); i++)
                            {
                                x[i] = y[j][k][i];
                            }
                            chemistryInterface_->setMassFraction(x, n);
                            x = chemistryInterface_->mole();

                            for (unsigned int i = 0; i < chemistryInterface_->numberOfGasSpecies(); i++)
                            {
                                mole[j][k][i] = x[i];
                            }
                        }
                    }
                }

                for (unsigned int i = 0; i < chemistryInterface_->numberOfGasSpecies(); i++)
                {
                    std::string name = n[i];
                    output << "\nSpecie:           " << name << std::endl;

                    output << "Mass fraction" << std::endl;
                    output << "Length [m]/Time [s]"
                           << "\t";
                    for (unsigned int j = 0; j < t.size(); j++)
                    {
                        output << t[j] << "\t";
                    }

                    output << std::endl;

                    for (unsigned int k = 0; k < NP_; k++)
                    {
                        output << k * dz << "\t";
                        for (unsigned int j = 0; j < t.size(); j++)
                        {
                            output << y[j][k][i] << "\t";
                        }
                        output << std::endl;
                    }
                    output << std::endl;
                    output << "Mole fraction" << std::endl;
                    output << "Length [m]/Time [s]"
                           << "\t";
                    for (unsigned int j = 0; j < t.size(); j++)
                    {
                        output << t[j] << "\t";
                    }

                    output << std::endl;

                    for (unsigned int k = 0; k < NP_; k++)
                    {
                        output << k * dz << "\t";
                        for (unsigned int j = 0; j < t.size(); j++)
                        {
                            output << mole[j][k][i] << "\t";
                        }
                        output << std::endl;
                    }
                    output << std::endl;
                }
            }
            output.close();
            this->savedMessage();
        }
    }

    void catalyticPellet::plot()
    {
        if (!plot_)
        {
            delete plot_;
        }

        plot_ = new ASALI::plot();
        plot_->setTime(eq_->getTime());

        if (kineticCombo_.get_active_text() == "ASALI")
        {
            std::vector<double> t = eq_->getTime();
            std::vector<std::vector<std::vector<double>>> y = eq_->getSpecie();

            //Conversion from mass to mole
            std::vector<std::vector<std::vector<double>>> mole = eq_->getSpecie();
            {
                if (kineticType_ == "none")
                {
                    for (unsigned int j = 0; j < t.size(); j++)
                    {
                        for (unsigned int k = 0; k < NP_; k++)
                        {
                            std::vector<double> x(n_.size());
                            for (unsigned int i = 0; i < n_.size(); i++)
                            {
                                x[i] = y[j][k][i];
                            }

                            x = constantProperties_->get_mole_fraction(constantProperties_->get_MW(), x);

                            for (unsigned int i = 0; i < n_.size(); i++)
                            {
                                mole[j][k][i] = x[i];
                            }
                        }
                    }
                }
                else
                {
                    for (unsigned int j = 0; j < t.size(); j++)
                    {
                        for (unsigned int k = 0; k < NP_; k++)
                        {
                            chemistryInterface_->setTemperature(T_);
                            chemistryInterface_->setPressure(p_);
                            std::vector<double> x(n_.size());

                            for (unsigned int i = 0; i < n_.size(); i++)
                            {
                                x[i] = y[j][k][i];
                            }
                            chemistryInterface_->setMassFraction(x, n_);

                            for (unsigned int i = 0; i < n_.size(); i++)
                            {
                                for (unsigned int q = 0; q < chemistryInterface_->names().size(); q++)
                                {
                                    if (n_[i] == chemistryInterface_->names()[q])
                                    {
                                        mole[j][k][i] = chemistryInterface_->mole()[q];
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            plot_->setSpecieNames(n_);
            plot_->setSpecie(y, mole);
        }
        else if (kineticCombo_.get_active_text() == "CANTERA")
        {
            std::vector<double> t = eq_->getTime();
            std::vector<std::vector<std::vector<double>>> y = eq_->getSpecie();

            //Conversion from mass to mole
            std::vector<std::vector<std::vector<double>>> mole = eq_->getSpecie();
            {
                std::vector<std::string> n = chemistryInterface_->names();
                for (unsigned int j = 0; j < t.size(); j++)
                {
                    for (unsigned int k = 0; k < NP_; k++)
                    {
                        chemistryInterface_->setTemperature(T_);
                        chemistryInterface_->setPressure(p_);
                        std::vector<double> x(chemistryInterface_->numberOfGasSpecies());
                        for (unsigned int i = 0; i < chemistryInterface_->numberOfGasSpecies(); i++)
                        {
                            x[i] = y[j][k][i];
                        }
                        chemistryInterface_->setMassFraction(x, n);
                        x = chemistryInterface_->mole();

                        for (unsigned int i = 0; i < chemistryInterface_->numberOfGasSpecies(); i++)
                        {
                            mole[j][k][i] = x[i];
                        }
                    }
                }
            }

            plot_->setSpecieNames(chemistryInterface_->names());
            plot_->setSpecie(y, mole);
            plot_->setSiteNames(chemistryInterface_->coverageNames());
            plot_->setSite(eq_->getSite());
        }

        //Length
        {
            double dz = eq_->getLength() / double(NP_ - 1);
            std::vector<double> l(NP_);
            for (unsigned int k = 0; k < NP_; k++)
            {
                l[k] = k * dz;
            }
            plot_->setLength(l, lengthCombo_.get_active_text());
        }

        plot_->setType("pellet");
        plot_->build();
        plot_->show();
    }
}
