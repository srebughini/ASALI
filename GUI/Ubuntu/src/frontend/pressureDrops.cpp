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

#include "frontend/pressureDrops.hpp"

namespace ASALI
{
    pressureDrops::pressureDrops(ASALI::speciesPopup *speciesNames,
                                 std::string kineticType)
        : basicProperties(speciesNames, kineticType),
          mainBox_(Gtk::ORIENTATION_VERTICAL),
          calculateButton_("Calculate"),
          backButton3_("Back"),
          exitButton3_("Exit"),
          lengthLabel_("Length"),
          velocityLabel_("Velocity"),
          pressureLabel_("<b>Pressure drops</b>"),
          reactorTypeLabel_("Reactor type"),
          packedBedTubeLabel_("Tube diameter"),
          packedBedParticleLabel_("Particle diameter"),
          packedBedVoidFractionLabel_("Void fraction"),
          tubularTubeLabel_("Tube diameter"),
          tubularWallThicknessLabel_("Washcoat thickness"),
          honeyCombCPSILabel_("CPSI"),
          honeyCombWallThicknessLabel_("Wall thickness"),
          tubularDpLabel_("Bird R. B. et al. (1960)"),
          honeyCombDpLabel_("Bird R. B. et al. (1960)"),
          logo1_(this->relative_path_to_absolute_path("images/PressureLogo.png")),
          logo2_(this->relative_path_to_absolute_path("images/PressureLogo.png")),
          reactorType_("none"),
          tubularBool_(false),
          honeyCombBool_(false),
          packedBedBool_(false),
          tubularDpBool_(false),
          honeyCombDpBool_(false),
          packedBedDpBool_(false),
          Ndp_(3)
    {
        //Set up packed bed
        {
            dpPackedBed_.resize(Ndp_);
            packedBedDpLabel_.resize(Ndp_);
            packedBedDpValueLabel_.resize(Ndp_);
            packedBedDpCombo_.resize(Ndp_);

            for (unsigned int i = 0; i < Ndp_; i++)
            {
                packedBedDpCombo_[i] = new Gtk::ComboBoxText();
                packedBedDpValueLabel_[i] = new Gtk::Label("?");
            }

            packedBedDpLabel_[0] = new Gtk::Label("Ergun S. et al.   (1949)");
            packedBedDpLabel_[1] = new Gtk::Label("Tallmadge J. A.   (1970)");
            packedBedDpLabel_[2] = new Gtk::Label("Eisfeld B. et al. (2001)");
        }

        //Input composition
        {
            this->set_border_width(15);
            this->set_title("ASALI: Pressure drops");
            this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
            this->set_icon_from_file(this->relative_path_to_absolute_path("images/Icon.png"));
            doneButton_.set_label("Next");
            this->input();
        }

        //Input reactor
        {
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

                //Type
                propertiesGrid_.attach(reactorTypeLabel_, 0, 0, 1, 1);
                propertiesGrid_.attach(reactorTypeCombo_, 1, 0, 1, 1);
                reactorTypeCombo_.append("tubular");
                reactorTypeCombo_.append("packed bed");
                reactorTypeCombo_.append("honeycomb");
                reactorTypeCombo_.signal_changed().connect(sigc::mem_fun(*this, &pressureDrops::options));
                reactorTypeCombo_.set_active(0);

                //Length
                propertiesGrid_.attach(lengthLabel_, 0, 1, 1, 1);
                propertiesGrid_.attach(lengthEntry_, 1, 1, 1, 1);
                lengthEntry_.set_text("1");
                propertiesGrid_.attach(lengthCombo_, 2, 1, 1, 1);
                lengthCombo_.append("m");
                lengthCombo_.append("dm");
                lengthCombo_.append("cm");
                lengthCombo_.append("mm");
                lengthCombo_.set_active(0);

                //Velocity
                propertiesGrid_.attach(velocityLabel_, 0, 2, 1, 1);
                propertiesGrid_.attach(velocityEntry_, 1, 2, 1, 1);
                velocityEntry_.set_text("1");
                propertiesGrid_.attach(velocityCombo_, 2, 2, 1, 1);
                velocityCombo_.append("m/s");
                velocityCombo_.append("cm/s");
                velocityCombo_.append("m/min");
                velocityCombo_.append("cm/min");
                velocityCombo_.append("m/h");
                velocityCombo_.append("cm/h");
                velocityCombo_.set_active(0);

                //Tubular
                {
                    tubularTubeEntry_.set_text("1");

                    tubularTubeCombo_.append("m");
                    tubularTubeCombo_.append("dm");
                    tubularTubeCombo_.append("cm");
                    tubularTubeCombo_.append("mm");
                    tubularTubeCombo_.set_active(0);

                    tubularWallThicknessEntry_.set_text("1");

                    tubularWallThicknessCombo_.append("cm");
                    tubularWallThicknessCombo_.append("mm");
                    tubularWallThicknessCombo_.append("\u03BCm");
                    tubularWallThicknessCombo_.set_active(2);

                    tubularDpCombo_.append("Pa");
                    tubularDpCombo_.append("bar");
                    tubularDpCombo_.append("mmHg");
                    tubularDpCombo_.append("torr");
                    tubularDpCombo_.append("atm");
                    tubularDpCombo_.set_active(0);
                    tubularDpCombo_.signal_changed().connect(sigc::bind<unsigned int>(sigc::mem_fun(*this, &pressureDrops::dpConversion), 0));
                }

                //Honeycomb
                {
                    honeyCombCPSIEntry_.set_text("400");

                    honeyCombWallThicknessCombo_.append("cm");
                    honeyCombWallThicknessCombo_.append("mm");
                    honeyCombWallThicknessCombo_.append("\u03BCm");
                    honeyCombWallThicknessCombo_.set_active(1);

                    honeyCombWallThicknessEntry_.set_text("1");

                    honeyCombDpCombo_.append("Pa");
                    honeyCombDpCombo_.append("bar");
                    honeyCombDpCombo_.append("mmHg");
                    honeyCombDpCombo_.append("torr");
                    honeyCombDpCombo_.append("atm");
                    honeyCombDpCombo_.set_active(0);
                    honeyCombDpCombo_.signal_changed().connect(sigc::bind<unsigned int>(sigc::mem_fun(*this, &pressureDrops::dpConversion), 0));
                }

                //Packed bed
                {
                    packedBedTubeEntry_.set_text("1");

                    packedBedTubeCombo_.append("m");
                    packedBedTubeCombo_.append("dm");
                    packedBedTubeCombo_.append("cm");
                    packedBedTubeCombo_.append("mm");
                    packedBedTubeCombo_.set_active(0);

                    packedBedParticleEntry_.set_text("1");

                    packedBedParticleCombo_.append("m");
                    packedBedParticleCombo_.append("dm");
                    packedBedParticleCombo_.append("cm");
                    packedBedParticleCombo_.append("mm");
                    packedBedParticleCombo_.set_active(0);

                    packedBedVoidFractionEntry_.set_text("0.42");

                    for (unsigned int i = 0; i < Ndp_; i++)
                    {
                        packedBedDpCombo_[i]->append("Pa");
                        packedBedDpCombo_[i]->append("bar");
                        packedBedDpCombo_[i]->append("mmHg");
                        packedBedDpCombo_[i]->append("torr");
                        packedBedDpCombo_[i]->append("atm");
                        packedBedDpCombo_[i]->set_active(0);
                        packedBedDpCombo_[i]->signal_changed().connect(sigc::bind<unsigned int>(sigc::mem_fun(*this, &pressureDrops::dpConversion), i));
                    }
                }

                //Buttons
                propertiesGrid_.attach(backButton3_, 0, 7, 1, 1);
                backButton3_.signal_clicked().connect(sigc::mem_fun(*this, &pressureDrops::input));
                propertiesGrid_.attach(exitButton3_, 2, 7, 1, 1);
                exitButton3_.signal_clicked().connect(sigc::mem_fun(*this, &pressureDrops::exit));
                propertiesGrid_.attach(calculateButton_, 1, 7, 1, 1);
                calculateButton_.signal_clicked().connect(sigc::mem_fun(*this, &pressureDrops::results));
            }
        }
    }

    pressureDrops::~pressureDrops()
    {
    }

    void pressureDrops::options()
    {
        if (reactorType_ == "honeycomb")
        {
            propertiesGrid_.remove(honeyCombCPSILabel_);
            propertiesGrid_.remove(honeyCombCPSIEntry_);
            propertiesGrid_.remove(honeyCombWallThicknessLabel_);
            propertiesGrid_.remove(honeyCombWallThicknessEntry_);
            propertiesGrid_.remove(honeyCombWallThicknessCombo_);
        }
        else if (reactorType_ == "tubular")
        {
            propertiesGrid_.remove(tubularTubeLabel_);
            propertiesGrid_.remove(tubularTubeEntry_);
            propertiesGrid_.remove(tubularTubeCombo_);
            propertiesGrid_.remove(tubularWallThicknessLabel_);
            propertiesGrid_.remove(tubularWallThicknessEntry_);
            propertiesGrid_.remove(tubularWallThicknessCombo_);
        }
        else if (reactorType_ == "packed bed")
        {
            propertiesGrid_.remove(packedBedTubeLabel_);
            propertiesGrid_.remove(packedBedTubeEntry_);
            propertiesGrid_.remove(packedBedTubeCombo_);
            propertiesGrid_.remove(packedBedParticleLabel_);
            propertiesGrid_.remove(packedBedParticleEntry_);
            propertiesGrid_.remove(packedBedParticleCombo_);
            propertiesGrid_.remove(packedBedVoidFractionLabel_);
            propertiesGrid_.remove(packedBedVoidFractionEntry_);
        }

        if (reactorTypeCombo_.get_active_row_number() == 0)
        {
            propertiesGrid_.attach(tubularTubeLabel_, 0, 4, 1, 1);
            propertiesGrid_.attach(tubularTubeEntry_, 1, 4, 1, 1);
            propertiesGrid_.attach(tubularTubeCombo_, 2, 4, 1, 1);

            propertiesGrid_.attach(tubularWallThicknessLabel_, 0, 5, 1, 1);
            propertiesGrid_.attach(tubularWallThicknessEntry_, 1, 5, 1, 1);
            propertiesGrid_.attach(tubularWallThicknessCombo_, 2, 5, 1, 1);

            reactorType_ = "tubular";
        }
        else if (reactorTypeCombo_.get_active_row_number() == 1)
        {
            propertiesGrid_.attach(packedBedTubeLabel_, 0, 4, 1, 1);
            propertiesGrid_.attach(packedBedTubeEntry_, 1, 4, 1, 1);
            propertiesGrid_.attach(packedBedTubeCombo_, 2, 4, 1, 1);

            propertiesGrid_.attach(packedBedParticleLabel_, 0, 5, 1, 1);
            propertiesGrid_.attach(packedBedParticleEntry_, 1, 5, 1, 1);
            propertiesGrid_.attach(packedBedParticleCombo_, 2, 5, 1, 1);

            propertiesGrid_.attach(packedBedVoidFractionLabel_, 0, 6, 1, 1);
            propertiesGrid_.attach(packedBedVoidFractionEntry_, 1, 6, 1, 1);

            reactorType_ = "packed bed";
        }
        else if (reactorTypeCombo_.get_active_row_number() == 2)
        {
            propertiesGrid_.attach(honeyCombCPSILabel_, 0, 4, 1, 1);
            propertiesGrid_.attach(honeyCombCPSIEntry_, 1, 4, 1, 1);

            propertiesGrid_.attach(honeyCombWallThicknessLabel_, 0, 5, 1, 1);
            propertiesGrid_.attach(honeyCombWallThicknessEntry_, 1, 5, 1, 1);
            propertiesGrid_.attach(honeyCombWallThicknessCombo_, 2, 5, 1, 1);

            reactorType_ = "honeycomb";
        }

        this->resize(mainBox_.get_width(), mainBox_.get_height());
        this->show_all_children();
    }

    void pressureDrops::read()
    {
        L_ = Glib::Ascii::strtod(lengthEntry_.get_text());
        v_ = Glib::Ascii::strtod(velocityEntry_.get_text());

        ConvertsToMeter(L_, lengthCombo_.get_active_text());
        ConvertsToMeterPerSecond(v_, velocityCombo_.get_active_text());

        reactorType_ = reactorTypeCombo_.get_active_text();

        if (reactorTypeCombo_.get_active_text() == "tubular")
        {
            Dt_ = Glib::Ascii::strtod(tubularTubeEntry_.get_text());

            ConvertsToMeter(Dt_, tubularTubeCombo_.get_active_text());

            tw_ = Glib::Ascii::strtod(tubularWallThicknessEntry_.get_text());

            ConvertsToMeter(tw_, tubularWallThicknessCombo_.get_active_text());
        }
        else if (reactorTypeCombo_.get_active_text() == "packed bed")
        {
            Dt_ = Glib::Ascii::strtod(packedBedTubeEntry_.get_text());
            Dp_ = Glib::Ascii::strtod(packedBedParticleEntry_.get_text());
            epsi_ = Glib::Ascii::strtod(packedBedVoidFractionEntry_.get_text());

            ConvertsToMeter(Dt_, packedBedTubeCombo_.get_active_text());
            ConvertsToMeter(Dp_, packedBedParticleCombo_.get_active_text());
        }
        else if (reactorTypeCombo_.get_active_text() == "honeycomb")
        {
            cpsi_ = Glib::Ascii::strtod(honeyCombCPSIEntry_.get_text());
            tw_ = Glib::Ascii::strtod(honeyCombWallThicknessEntry_.get_text());

            ConvertsToMeter(tw_, honeyCombWallThicknessCombo_.get_active_text());
        }
    }

    void pressureDrops::run()
    {
        this->read();

        if (reactorType_ == "tubular")
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

            chemistryInterface_->transportCalculate();

            double Re = v_ * chemistryInterface_->getDensity() * (Dt_ - 2. * tw_) / chemistryInterface_->mu()[chemistryInterface_->mu().size() - 1];
            double f = 0.;

            if (Re < 2100.)
            {
                f = 16. / Re;
            }
            else
            {
                f = 0.0791 / std::pow(Re, 0.25);
            }

            dpTubular_ = 2. * f * chemistryInterface_->getDensity() * v_ * v_ * L_ / (Dt_ - 2. * tw_);
        }
        else if (reactorType_ == "honeycomb")
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

            chemistryInterface_->transportCalculate();

            double Dc = sqrt(1. / cpsi_) * 2.54 * 1e-02 - tw_; //[m]
            double epsi = std::pow(Dc, 2.) / std::pow(Dc + tw_, 2.);
            double v = v_ / epsi;
            double Re = v * chemistryInterface_->getDensity() * Dc / chemistryInterface_->mu()[chemistryInterface_->mu().size() - 1];
            double f = 0.;

            if (Re < 2100.)
            {
                f = 16. / Re;
            }
            else
            {
                f = 0.0791 / std::pow(Re, 0.25);
            }

            dpHoneyComb_ = 2. * f * chemistryInterface_->getDensity() * v * v * L_ / Dc;
        }
        else if (reactorType_ == "packed bed")
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

            chemistryInterface_->transportCalculate();

            double mu = chemistryInterface_->mu()[chemistryInterface_->mu().size() - 1];
            double G = chemistryInterface_->getDensity() * v_;
            double Aw = 1. + 2. / (3. * Dt_ * (1. - epsi_) / Dp_);
            double Bw = std::pow(1.15 * std::pow(Dp_ / Dt_, 2.) + 0.87, 2.);
            dpPackedBed_[0] = (150. * (1. - epsi_) / (Dp_ * G / mu) + 7. / 4.) * (1. - epsi_) * std::pow(G, .2) / (std::pow(epsi_, 3.) * chemistryInterface_->getDensity() * Dp_);                                                //Ergun
            dpPackedBed_[1] = (150. * (1. - epsi_) / (Dp_ * G / mu) + 4.2 * std::pow((1. - epsi_) / (Dp_ * G / mu), 1. / 6.)) * (1. - epsi_) * std::pow(G, .2) / (std::pow(epsi_, 3.) * chemistryInterface_->getDensity() * Dp_); //Tallmadge
            dpPackedBed_[2] = (154. * std::pow(Aw, 2.) * (1. - epsi_) / (Dp_ * G / mu) + Aw / Bw) * (1. - epsi_) * std::pow(G, .2) / (std::pow(epsi_, 3.) * chemistryInterface_->getDensity() * Dp_);                             //Eisfeld
        }
    }

    void pressureDrops::results()
    {
        this->inputReader();
        if (checkInput_.second == false)
        {
            this->checkInput(checkInput_.first);
        }
        else
        {
            this->remove();
            this->add(mainBox_);

            this->run();
            beerLabel_.set_text(this->getBeerShort());
            beerLabel_.set_use_markup(true);
            beerLabel_.set_justify(Gtk::JUSTIFY_CENTER);

            pressureLabel_.set_use_markup(true);
            pressureLabel_.set_justify(Gtk::JUSTIFY_CENTER);

            propertiesGrid_.remove(backButton3_);
            propertiesGrid_.remove(exitButton3_);
            propertiesGrid_.remove(calculateButton_);

            if (tubularDpBool_)
            {
                propertiesGrid_.remove(tubularDpLabel_);
                propertiesGrid_.remove(tubularDpValueLabel_);
                propertiesGrid_.remove(tubularDpCombo_);
                propertiesGrid_.remove(pressureLabel_);
                propertiesGrid_.remove(beerLabel_);
            }

            if (honeyCombDpBool_)
            {
                propertiesGrid_.remove(honeyCombDpLabel_);
                propertiesGrid_.remove(honeyCombDpValueLabel_);
                propertiesGrid_.remove(honeyCombDpCombo_);
                propertiesGrid_.remove(pressureLabel_);
                propertiesGrid_.remove(beerLabel_);
            }

            if (packedBedDpBool_)
            {
                for (unsigned int i = 0; i < Ndp_; i++)
                {
                    propertiesGrid_.remove(*packedBedDpLabel_[i]);
                    propertiesGrid_.remove(*packedBedDpValueLabel_[i]);
                    propertiesGrid_.remove(*packedBedDpCombo_[i]);
                }

                propertiesGrid_.remove(pressureLabel_);
                propertiesGrid_.remove(beerLabel_);
            }

            if (reactorType_ == "tubular")
            {
                tubularDpBool_ = true;
                honeyCombDpBool_ = false;
                packedBedDpBool_ = false;

                {
                    std::ostringstream s;
                    s << dpTubular_;
                    tubularDpValueLabel_.set_text(s.str());
                }

                propertiesGrid_.attach(pressureLabel_, 0, 7, 3, 1);

                propertiesGrid_.attach(beerLabel_, 0, 8, 3, 1);

                propertiesGrid_.attach(tubularDpLabel_, 0, 9, 1, 1);
                propertiesGrid_.attach(tubularDpValueLabel_, 1, 9, 1, 1);
                propertiesGrid_.attach(tubularDpCombo_, 2, 9, 1, 1);

                propertiesGrid_.attach(backButton3_, 0, 10, 1, 1);
                propertiesGrid_.attach(exitButton3_, 2, 10, 1, 1);
                propertiesGrid_.attach(calculateButton_, 1, 10, 1, 1);

                this->dpConversion(0);
            }
            else if (reactorType_ == "honeycomb")
            {
                tubularDpBool_ = false;
                honeyCombDpBool_ = true;
                packedBedDpBool_ = false;

                {
                    std::ostringstream s;
                    s << dpHoneyComb_;
                    honeyCombDpValueLabel_.set_text(s.str());
                }

                propertiesGrid_.attach(pressureLabel_, 0, 7, 3, 1);
                propertiesGrid_.attach(beerLabel_, 0, 8, 3, 1);

                propertiesGrid_.attach(honeyCombDpLabel_, 0, 9, 1, 1);
                propertiesGrid_.attach(honeyCombDpValueLabel_, 1, 9, 1, 1);
                propertiesGrid_.attach(honeyCombDpCombo_, 2, 9, 1, 1);

                propertiesGrid_.attach(backButton3_, 0, 10, 1, 1);
                propertiesGrid_.attach(exitButton3_, 2, 10, 1, 1);
                propertiesGrid_.attach(calculateButton_, 1, 10, 1, 1);

                this->dpConversion(0);
            }
            else if (reactorType_ == "packed bed")
            {
                tubularDpBool_ = false;
                honeyCombDpBool_ = false;
                packedBedDpBool_ = true;

                propertiesGrid_.attach(pressureLabel_, 0, 7, 3, 1);
                propertiesGrid_.attach(beerLabel_, 0, 8, 3, 1);

                for (unsigned int i = 0; i < Ndp_; i++)
                {
                    this->dpConversion(i);
                    propertiesGrid_.attach(*packedBedDpLabel_[i], 0, 9 + i, 1, 1);
                    propertiesGrid_.attach(*packedBedDpValueLabel_[i], 1, 9 + i, 1, 1);
                    propertiesGrid_.attach(*packedBedDpCombo_[i], 2, 9 + i, 1, 1);
                }

                propertiesGrid_.attach(backButton3_, 0, 9 + Ndp_, 1, 1);
                propertiesGrid_.attach(exitButton3_, 2, 9 + Ndp_, 1, 1);
                propertiesGrid_.attach(calculateButton_, 1, 9 + Ndp_, 1, 1);
            }

            this->resize(mainBox_.get_width(), mainBox_.get_height());
            this->show_all_children();
        }
    }

    void pressureDrops::dpConversion(unsigned int i)
    {
        beerLabel_.set_text(this->getBeerShort());
        beerLabel_.set_use_markup(true);
        beerLabel_.set_justify(Gtk::JUSTIFY_CENTER);

        if (reactorType_ == "tubular")
        {
            double dp = dpTubular_;
            ConvertsFromPascal(dp, tubularDpCombo_.get_active_text());
            {
                std::ostringstream s;
                s << dp;
                tubularDpValueLabel_.set_text(s.str());
            }
        }
        else if (reactorType_ == "honeycomb")
        {
            double dp = dpHoneyComb_;
            ConvertsFromPascal(dp, honeyCombDpCombo_.get_active_text());
            {
                std::ostringstream s;
                s << dp;
                honeyCombDpValueLabel_.set_text(s.str());
            }
        }
        else if (reactorType_ == "packed bed")
        {
            double dp = dpPackedBed_[i];
            ConvertsFromPascal(dp, packedBedDpCombo_[i]->get_active_text());
            {
                std::ostringstream s;
                s << dp;
                packedBedDpValueLabel_[i]->set_text(s.str());
            }
        }
    }


    void pressureDrops::save()
    {
        
    }
}
