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

#include "frontend/constantProperties.hpp"

namespace ASALI
{
    constantProperties::constantProperties()
        : batchLogo_(fileManager_.relative_path_to_absolute_path("images/BatchLogo.png")),
          ph1dLogo_(fileManager_.relative_path_to_absolute_path("images/Ph1DLogo.png")),
          het1dLogo_(fileManager_.relative_path_to_absolute_path("images/Het1DLogo.png")),
          pelletLogo_(fileManager_.relative_path_to_absolute_path("images/PelletLogo.png")),
          mainBox_(Gtk::ORIENTATION_VERTICAL),
          nameLabel_("Name"),
          mwLabel_("Molecular weight"),
          diffLabel_("Diffusion coefficient"),
          reactionLabel_("Reaction"),
          heatLabel_("Heat of reaction"),
          cpLabel_("Specific heat"),
          condLabel_("Thermal conductivity"),
          muLabel_("Viscosity"),
          doneButton_("Done"),
          type_("zero")
    {
        beerQuote_ = new ASALI::beerQuote();
        unitConversion_ = new ASALI::asaliUnitConversionUtils();

        this->set_border_width(15);
        this->set_title("ASALI: properties input");
        this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
        this->set_icon_from_file(fileManager_.relative_path_to_absolute_path("images/Icon.png"));

        //Add background grid
        mainBox_.set_halign(Gtk::ALIGN_START);
        mainBox_.set_spacing(10);
        this->add(mainBox_);

        {
            mainGrid_.set_row_spacing(10);
            mainGrid_.set_column_spacing(10);

            heatBox_.set_halign(Gtk::ALIGN_CENTER);
            heatBox_.set_spacing(10);

            diffBox_.set_halign(Gtk::ALIGN_CENTER);
            diffBox_.set_spacing(10);

            unitConversion_->updateBox(heatCombo_, "heat");
            unitConversion_->updateBox(cpCombo_, "specificheatonlymass");
            unitConversion_->updateBox(condCombo_, "conductivity");
            unitConversion_->updateBox(diffCombo_, "diffusivity");
            unitConversion_->updateBox(muCombo_, "viscosity");

            cpGrid_.set_row_spacing(10);
            cpGrid_.set_column_spacing(10);

            condGrid_.set_row_spacing(10);
            condGrid_.set_column_spacing(10);

            cpEntry_.set_text("1");
            condEntry_.set_text("1");
            muEntry_.set_text("1e-05");
        }
    }

    void constantProperties::setEnergy(const std::string &energy)
    {
        energy_ = energy;
    }

    void constantProperties::setType(const std::string &type)
    {
        type_ = type;
    }

    void constantProperties::setSpeciesNames(const std::vector<std::string> &n)
    {
        n_ = n;
        NC_ = n.size();

        speciesNameLabel_.clear();
        speciesMwEntry_.clear();
        speciesNameLabel_.resize(NC_);
        speciesMwEntry_.resize(NC_);
        speciesDiffEntry_.resize(NC_);
    }

    void constantProperties::setReactions(const unsigned int Nhom, const unsigned int Nhet)
    {
        Nhom_ = Nhom;
        Nhet_ = Nhet;
    }

    void constantProperties::destroy()
    {
        if (type_ == "batch" || type_ == "cstr")
        {
            if (energy_ == "on")
            {
                cpGrid_.remove(cpLabel_);
                cpGrid_.remove(cpCombo_);
                mainGrid_.remove(cpGrid_);
                mainGrid_.remove(cpEntry_);
                mainGrid_.remove(reactionLabel_);
                heatBox_.remove(heatCombo_);
                heatBox_.remove(heatLabel_);
                mainGrid_.remove(heatBox_);

                for (unsigned int i = 0; i < reactionNumberLabel_.size(); i++)
                {
                    mainGrid_.remove(*reactionNumberLabel_[i]);
                    mainGrid_.remove(*speciesHeatEntry_[i]);
                }

                reactionNumberLabel_.clear();
                speciesHeatEntry_.clear();
            }

            mainGrid_.remove(nameLabel_);
            mainGrid_.remove(mwLabel_);

            for (unsigned int i = 0; i < speciesNameLabel_.size(); i++)
            {
                mainGrid_.remove(*speciesNameLabel_[i]);
                mainGrid_.remove(*speciesMwEntry_[i]);
            }

            speciesNameLabel_.clear();
            speciesMwEntry_.clear();

            mainBox_.remove(batchLogo_);
            mainBox_.remove(mainGrid_);
            mainBox_.remove(doneButton_);
        }
        else if (type_ == "ph1d")
        {
            if (energy_ == "on")
            {
                mainGrid_.remove(cpLabel_);
                mainGrid_.remove(cpCombo_);
                mainGrid_.remove(cpEntry_);
                mainGrid_.remove(condLabel_);
                mainGrid_.remove(condCombo_);
                mainGrid_.remove(condEntry_);
                mainGrid_.remove(reactionLabel_);
                heatBox_.remove(heatCombo_);
                heatBox_.remove(heatLabel_);
                mainGrid_.remove(heatBox_);

                for (unsigned int i = 0; i < reactionNumberLabel_.size(); i++)
                {
                    mainGrid_.remove(*reactionNumberLabel_[i]);
                    mainGrid_.remove(*speciesHeatEntry_[i]);
                }

                reactionNumberLabel_.clear();
                speciesHeatEntry_.clear();
            }

            mainGrid_.remove(nameLabel_);
            mainGrid_.remove(mwLabel_);
            mainGrid_.remove(diffBox_);
            diffBox_.remove(diffLabel_);
            diffBox_.remove(diffCombo_);

            for (unsigned int i = 0; i < speciesNameLabel_.size(); i++)
            {
                mainGrid_.remove(*speciesNameLabel_[i]);
                mainGrid_.remove(*speciesMwEntry_[i]);
                mainGrid_.remove(*speciesDiffEntry_[i]);
            }

            speciesNameLabel_.clear();
            speciesDiffEntry_.clear();
            speciesMwEntry_.clear();

            mainBox_.remove(ph1dLogo_);
            mainBox_.remove(mainGrid_);
            mainBox_.remove(doneButton_);
        }
        else if (type_ == "het1d")
        {
            if (energy_ == "on")
            {
                mainGrid_.remove(cpLabel_);
                mainGrid_.remove(cpCombo_);
                mainGrid_.remove(cpEntry_);
                mainGrid_.remove(condLabel_);
                mainGrid_.remove(condCombo_);
                mainGrid_.remove(condEntry_);
                mainGrid_.remove(reactionLabel_);
                heatBox_.remove(heatCombo_);
                heatBox_.remove(heatLabel_);
                mainGrid_.remove(heatBox_);

                for (unsigned int i = 0; i < reactionNumberLabel_.size(); i++)
                {
                    mainGrid_.remove(*reactionNumberLabel_[i]);
                    mainGrid_.remove(*speciesHeatEntry_[i]);
                }

                reactionNumberLabel_.clear();
                speciesHeatEntry_.clear();
            }

            mainGrid_.remove(nameLabel_);
            mainGrid_.remove(mwLabel_);
            mainGrid_.remove(diffBox_);
            mainGrid_.remove(muLabel_);
            mainGrid_.remove(muCombo_);
            mainGrid_.remove(muEntry_);
            diffBox_.remove(diffLabel_);
            diffBox_.remove(diffCombo_);

            for (unsigned int i = 0; i < speciesNameLabel_.size(); i++)
            {
                mainGrid_.remove(*speciesNameLabel_[i]);
                mainGrid_.remove(*speciesMwEntry_[i]);
                mainGrid_.remove(*speciesDiffEntry_[i]);
            }

            speciesNameLabel_.clear();
            speciesDiffEntry_.clear();
            speciesMwEntry_.clear();

            mainBox_.remove(het1dLogo_);
            mainBox_.remove(mainGrid_);
            mainBox_.remove(doneButton_);
        }
        else if (type_ == "pellet")
        {
            mainGrid_.remove(nameLabel_);
            mainGrid_.remove(mwLabel_);
            mainGrid_.remove(diffBox_);
            diffBox_.remove(diffLabel_);
            diffBox_.remove(diffCombo_);

            for (unsigned int i = 0; i < speciesNameLabel_.size(); i++)
            {
                mainGrid_.remove(*speciesNameLabel_[i]);
                mainGrid_.remove(*speciesMwEntry_[i]);
                mainGrid_.remove(*speciesDiffEntry_[i]);
            }

            speciesNameLabel_.clear();
            speciesDiffEntry_.clear();
            speciesMwEntry_.clear();

            mainBox_.remove(pelletLogo_);
            mainBox_.remove(mainGrid_);
            mainBox_.remove(doneButton_);
        }
    }

    void constantProperties::build()
    {
        NR_ = 0;
        if (type_ == "batch" || type_ == "cstr")
        {
            mainGrid_.set_column_homogeneous(true);
            mainBox_.pack_start(batchLogo_, Gtk::PACK_SHRINK);
            mainBox_.pack_start(mainGrid_, Gtk::PACK_SHRINK);

            mainGrid_.attach(nameLabel_, 0, 0, 1, 1);
            mainGrid_.attach(mwLabel_, 1, 0, 1, 1);

            for (unsigned int i = 0; i < NC_; i++)
            {
                speciesNameLabel_[i] = new Gtk::Label(n_[i]);
                mainGrid_.attach(*speciesNameLabel_[i], 0, 1 + i, 1, 1);
                speciesMwEntry_[i] = new Gtk::Entry();
                mainGrid_.attach(*speciesMwEntry_[i], 1, 1 + i, 1, 1);

                if (MW_.size() != 0)
                {
                    std::ostringstream s;
                    s << MW_[i];
                    speciesMwEntry_[i]->set_text(s.str());
                }
                else
                {
                    speciesMwEntry_[i]->set_text("14");
                }
            }

            if (energy_ == "on")
            {
                mainGrid_.attach(cpGrid_, 0, NC_ + 1, 1, 1);
                cpGrid_.attach(cpLabel_, 0, 0, 1, 1);
                cpGrid_.attach(cpCombo_, 1, 0, 1, 1);

                mainGrid_.attach(cpEntry_, 1, NC_ + 1, 1, 1);

                mainGrid_.attach(reactionLabel_, 0, NC_ + 2, 1, 1);
                mainGrid_.attach(heatBox_, 1, NC_ + 2, 1, 1);
                heatBox_.pack_start(heatLabel_, Gtk::PACK_SHRINK);
                heatBox_.pack_start(heatCombo_, Gtk::PACK_SHRINK);

                NR_ = Nhom_ + Nhet_;
                reactionNumberLabel_.clear();
                speciesHeatEntry_.clear();
                reactionNumberLabel_.resize(NR_);
                speciesHeatEntry_.resize(NR_);

                for (unsigned int i = 0; i < Nhom_; i++)
                {
                    std::string reaction;
                    {
                        std::ostringstream s;
                        s << double(i + 1);
                        reaction = s.str() + " (homogeneous)";
                    }
                    reactionNumberLabel_[i] = new Gtk::Label(reaction);
                    mainGrid_.attach(*reactionNumberLabel_[i], 0, NC_ + 3 + i, 1, 1);
                    speciesHeatEntry_[i] = new Gtk::Entry();
                    mainGrid_.attach(*speciesHeatEntry_[i], 1, NC_ + 3 + i, 1, 1);
                    speciesHeatEntry_[i]->set_text("1");
                }

                for (unsigned int i = Nhom_; i < NR_; i++)
                {
                    std::string reaction;
                    {
                        std::ostringstream s;
                        s << double(i + 1 - Nhom_);
                        reaction = s.str() + " (heterogeneous)";
                    }
                    reactionNumberLabel_[i] = new Gtk::Label(reaction);
                    mainGrid_.attach(*reactionNumberLabel_[i], 0, NC_ + 3 + i, 1, 1);
                    speciesHeatEntry_[i] = new Gtk::Entry();
                    mainGrid_.attach(*speciesHeatEntry_[i], 1, NC_ + 3 + i, 1, 1);
                    speciesHeatEntry_[i]->set_text("1");
                }
            }
            else
            {
                NR_ = 0;
            }
            mainBox_.pack_end(doneButton_, Gtk::PACK_SHRINK);
            doneButton_.signal_clicked().connect(sigc::mem_fun(*this, &constantProperties::doneInput));
        }
        else if (type_ == "ph1d")
        {
            mainGrid_.set_column_homogeneous(false);
            mainBox_.pack_start(ph1dLogo_, Gtk::PACK_SHRINK);
            mainBox_.pack_start(mainGrid_, Gtk::PACK_SHRINK);

            mainGrid_.attach(nameLabel_, 0, 0, 1, 1);
            mainGrid_.attach(mwLabel_, 1, 0, 1, 1);
            mainGrid_.attach(diffBox_, 2, 0, 1, 1);
            diffBox_.pack_start(diffLabel_, Gtk::PACK_SHRINK);
            diffBox_.pack_start(diffCombo_, Gtk::PACK_SHRINK);

            for (unsigned int i = 0; i < NC_; i++)
            {
                speciesNameLabel_[i] = new Gtk::Label(n_[i]);
                mainGrid_.attach(*speciesNameLabel_[i], 0, 1 + i, 1, 1);
                speciesMwEntry_[i] = new Gtk::Entry();
                mainGrid_.attach(*speciesMwEntry_[i], 1, 1 + i, 1, 1);

                if (MW_.size() != 0)
                {
                    std::ostringstream s;
                    s << MW_[i];
                    speciesMwEntry_[i]->set_text(s.str());
                }
                else
                {
                    speciesMwEntry_[i]->set_text("14");
                }

                speciesDiffEntry_[i] = new Gtk::Entry();
                mainGrid_.attach(*speciesDiffEntry_[i], 2, 1 + i, 1, 1);

                if (diff_.size() != 0)
                {
                    std::ostringstream s;
                    s << diff_[i];
                    speciesDiffEntry_[i]->set_text(s.str());
                }
                else
                {
                    speciesDiffEntry_[i]->set_text("1e-05");
                }
            }

            if (energy_ == "on")
            {
                mainGrid_.attach(cpLabel_, 0, NC_ + 1, 1, 1);
                mainGrid_.attach(cpEntry_, 1, NC_ + 1, 1, 1);
                mainGrid_.attach(cpCombo_, 2, NC_ + 1, 1, 1);

                mainGrid_.attach(condLabel_, 0, NC_ + 2, 1, 1);
                mainGrid_.attach(condEntry_, 1, NC_ + 2, 1, 1);
                mainGrid_.attach(condCombo_, 2, NC_ + 2, 1, 1);

                mainGrid_.attach(reactionLabel_, 0, NC_ + 3, 1, 1);
                mainGrid_.attach(heatBox_, 1, NC_ + 3, 1, 1);
                heatBox_.pack_start(heatLabel_, Gtk::PACK_SHRINK);
                heatBox_.pack_start(heatCombo_, Gtk::PACK_SHRINK);

                NR_ = Nhom_ + Nhet_;
                reactionNumberLabel_.clear();
                speciesHeatEntry_.clear();
                reactionNumberLabel_.resize(NR_);
                speciesHeatEntry_.resize(NR_);

                for (unsigned int i = 0; i < Nhom_; i++)
                {
                    std::string reaction;
                    {
                        std::ostringstream s;
                        s << double(i + 1);
                        reaction = s.str() + " (homogeneous)";
                    }
                    reactionNumberLabel_[i] = new Gtk::Label(reaction);
                    mainGrid_.attach(*reactionNumberLabel_[i], 0, NC_ + 4 + i, 1, 1);
                    speciesHeatEntry_[i] = new Gtk::Entry();
                    mainGrid_.attach(*speciesHeatEntry_[i], 1, NC_ + 4 + i, 1, 1);
                    speciesHeatEntry_[i]->set_text("1");
                }

                for (unsigned int i = Nhom_; i < NR_; i++)
                {
                    std::string reaction;
                    {
                        std::ostringstream s;
                        s << double(i + 1 - Nhom_);
                        reaction = s.str() + " (heterogeneous)";
                    }
                    reactionNumberLabel_[i] = new Gtk::Label(reaction);
                    mainGrid_.attach(*reactionNumberLabel_[i], 0, NC_ + 4 + i, 1, 1);
                    speciesHeatEntry_[i] = new Gtk::Entry();
                    mainGrid_.attach(*speciesHeatEntry_[i], 1, NC_ + 4 + i, 1, 1);
                    speciesHeatEntry_[i]->set_text("1");
                }
            }
            else
            {
                NR_ = 0;
            }
            mainBox_.pack_end(doneButton_, Gtk::PACK_SHRINK);
            doneButton_.signal_clicked().connect(sigc::mem_fun(*this, &constantProperties::doneInput));
        }
        else if (type_ == "het1d")
        {
            mainGrid_.set_column_homogeneous(false);
            mainBox_.pack_start(het1dLogo_, Gtk::PACK_SHRINK);
            mainBox_.pack_start(mainGrid_, Gtk::PACK_SHRINK);

            mainGrid_.attach(nameLabel_, 0, 0, 1, 1);
            mainGrid_.attach(mwLabel_, 1, 0, 1, 1);
            mainGrid_.attach(diffBox_, 2, 0, 1, 1);
            diffBox_.pack_start(diffLabel_, Gtk::PACK_SHRINK);
            diffBox_.pack_start(diffCombo_, Gtk::PACK_SHRINK);

            for (unsigned int i = 0; i < NC_; i++)
            {
                speciesNameLabel_[i] = new Gtk::Label(n_[i]);
                mainGrid_.attach(*speciesNameLabel_[i], 0, 1 + i, 1, 1);
                speciesMwEntry_[i] = new Gtk::Entry();
                mainGrid_.attach(*speciesMwEntry_[i], 1, 1 + i, 1, 1);

                if (MW_.size() != 0)
                {
                    std::ostringstream s;
                    s << MW_[i];
                    speciesMwEntry_[i]->set_text(s.str());
                }
                else
                {
                    speciesMwEntry_[i]->set_text("14");
                }

                speciesDiffEntry_[i] = new Gtk::Entry();
                mainGrid_.attach(*speciesDiffEntry_[i], 2, 1 + i, 1, 1);

                if (diff_.size() != 0)
                {
                    std::ostringstream s;
                    s << diff_[i];
                    speciesDiffEntry_[i]->set_text(s.str());
                }
                else
                {
                    speciesDiffEntry_[i]->set_text("1e-05");
                }
            }

            mainGrid_.attach(muLabel_, 0, NC_ + 1, 1, 1);
            mainGrid_.attach(muEntry_, 1, NC_ + 1, 1, 1);
            mainGrid_.attach(muCombo_, 2, NC_ + 1, 1, 1);

            if (energy_ == "on")
            {
                mainGrid_.attach(cpLabel_, 0, NC_ + 2, 1, 1);
                mainGrid_.attach(cpEntry_, 1, NC_ + 2, 1, 1);
                mainGrid_.attach(cpCombo_, 2, NC_ + 2, 1, 1);

                mainGrid_.attach(condLabel_, 0, NC_ + 3, 1, 1);
                mainGrid_.attach(condEntry_, 1, NC_ + 3, 1, 1);
                mainGrid_.attach(condCombo_, 2, NC_ + 3, 1, 1);

                mainGrid_.attach(reactionLabel_, 0, NC_ + 4, 1, 1);
                mainGrid_.attach(heatBox_, 1, NC_ + 4, 1, 1);
                heatBox_.pack_start(heatLabel_, Gtk::PACK_SHRINK);
                heatBox_.pack_start(heatCombo_, Gtk::PACK_SHRINK);

                NR_ = Nhom_ + Nhet_;
                reactionNumberLabel_.clear();
                speciesHeatEntry_.clear();
                reactionNumberLabel_.resize(NR_);
                speciesHeatEntry_.resize(NR_);

                for (unsigned int i = 0; i < Nhom_; i++)
                {
                    std::string reaction;
                    {
                        std::ostringstream s;
                        s << double(i + 1);
                        reaction = s.str() + " (homogeneous)";
                    }
                    reactionNumberLabel_[i] = new Gtk::Label(reaction);
                    mainGrid_.attach(*reactionNumberLabel_[i], 0, NC_ + 5 + i, 1, 1);
                    speciesHeatEntry_[i] = new Gtk::Entry();
                    mainGrid_.attach(*speciesHeatEntry_[i], 1, NC_ + 5 + i, 1, 1);
                    speciesHeatEntry_[i]->set_text("1");
                }

                for (unsigned int i = Nhom_; i < NR_; i++)
                {
                    std::string reaction;
                    {
                        std::ostringstream s;
                        s << double(i + 1 - Nhom_);
                        reaction = s.str() + " (heterogeneous)";
                    }
                    reactionNumberLabel_[i] = new Gtk::Label(reaction);
                    mainGrid_.attach(*reactionNumberLabel_[i], 0, NC_ + 5 + i, 1, 1);
                    speciesHeatEntry_[i] = new Gtk::Entry();
                    mainGrid_.attach(*speciesHeatEntry_[i], 1, NC_ + 5 + i, 1, 1);
                    speciesHeatEntry_[i]->set_text("1");
                }
            }
            mainBox_.pack_end(doneButton_, Gtk::PACK_SHRINK);
            doneButton_.signal_clicked().connect(sigc::mem_fun(*this, &constantProperties::doneInput));
        }
        else if (type_ == "pellet")
        {
            mainGrid_.set_column_homogeneous(false);
            mainBox_.pack_start(pelletLogo_, Gtk::PACK_SHRINK);
            mainBox_.pack_start(mainGrid_, Gtk::PACK_SHRINK);

            mainGrid_.attach(nameLabel_, 0, 0, 1, 1);
            mainGrid_.attach(mwLabel_, 1, 0, 1, 1);
            mainGrid_.attach(diffBox_, 2, 0, 1, 1);
            diffBox_.pack_start(diffLabel_, Gtk::PACK_SHRINK);
            diffBox_.pack_start(diffCombo_, Gtk::PACK_SHRINK);

            for (unsigned int i = 0; i < NC_; i++)
            {
                speciesNameLabel_[i] = new Gtk::Label(n_[i]);
                mainGrid_.attach(*speciesNameLabel_[i], 0, 1 + i, 1, 1);
                speciesMwEntry_[i] = new Gtk::Entry();
                mainGrid_.attach(*speciesMwEntry_[i], 1, 1 + i, 1, 1);

                if (MW_.size() != 0)
                {
                    std::ostringstream s;
                    s << MW_[i];
                    speciesMwEntry_[i]->set_text(s.str());
                }
                else
                {
                    speciesMwEntry_[i]->set_text("14");
                }

                speciesDiffEntry_[i] = new Gtk::Entry();
                mainGrid_.attach(*speciesDiffEntry_[i], 2, 1 + i, 1, 1);

                if (diff_.size() != 0)
                {
                    std::ostringstream s;
                    s << diff_[i];
                    speciesDiffEntry_[i]->set_text(s.str());
                }
                else
                {
                    speciesDiffEntry_[i]->set_text("1e-05");
                }
            }

            NR_ = 0;

            mainBox_.pack_end(doneButton_, Gtk::PACK_SHRINK);
            doneButton_.signal_clicked().connect(sigc::mem_fun(*this, &constantProperties::doneInput));
        }

        this->resize(mainBox_.get_width(), mainBox_.get_height());
        this->show_all_children();
    }

    void constantProperties::savedMessage()
    {
        Gtk::MessageDialog dialog(*this, "Your file has been saved.\nThank you for using ASALI.", true, Gtk::MESSAGE_OTHER);
        dialog.set_secondary_text(beerQuote_->getRandomQuote(), true);
        dialog.run();
    }

    void constantProperties::doneInput()
    {
        if (type_ == "batch" || type_ == "cstr")
        {
            MW_.clear();
            MW_.resize(NC_);
            for (unsigned int i = 0; i < NC_; i++)
            {
                MW_[i] = Glib::Ascii::strtod(speciesMwEntry_[i]->get_text());
            }

            Qhom_.clear();
            Qhom_.resize(Nhom_);

            for (unsigned int i = 0; i < Nhom_; i++)
            {
                Qhom_[i] = Glib::Ascii::strtod(speciesHeatEntry_[i]->get_text());
                unitConversion_->toJoulePerKmole(Qhom_[i], heatCombo_.get_active_text());
            }

            Qhet_.clear();
            Qhet_.resize(Nhet_);

            for (unsigned int i = Nhom_; i < NR_; i++)
            {
                Qhet_[i - Nhom_] = Glib::Ascii::strtod(speciesHeatEntry_[i]->get_text());
                unitConversion_->toJoulePerKmole(Qhet_[i - Nhom_], heatCombo_.get_active_text());
            }

            if (energy_ == "on")
            {
                cp_ = Glib::Ascii::strtod(cpEntry_.get_text());
                unitConversion_->toJoulePerKgPerKelvin(cp_, cpCombo_.get_active_text());
            }
            else
            {
                cp_ = 1.;
            }
        }
        else if (type_ == "ph1d")
        {
            MW_.clear();
            diff_.clear();
            MW_.resize(NC_);
            diff_.resize(NC_);
            for (unsigned int i = 0; i < NC_; i++)
            {
                MW_[i] = Glib::Ascii::strtod(speciesMwEntry_[i]->get_text());
                diff_[i] = Glib::Ascii::strtod(speciesDiffEntry_[i]->get_text());
                unitConversion_->toSquareMeterPerSecond(diff_[i], diffCombo_.get_active_text());
            }

            Qhom_.clear();
            Qhom_.resize(Nhom_);

            for (unsigned int i = 0; i < Nhom_; i++)
            {
                Qhom_[i] = Glib::Ascii::strtod(speciesHeatEntry_[i]->get_text());
                unitConversion_->toJoulePerKmole(Qhom_[i], heatCombo_.get_active_text());
            }

            Qhet_.clear();
            Qhet_.resize(Nhet_);

            for (unsigned int i = Nhom_; i < NR_; i++)
            {
                Qhet_[i - Nhom_] = Glib::Ascii::strtod(speciesHeatEntry_[i]->get_text());
                unitConversion_->toJoulePerKmole(Qhet_[i - Nhom_], heatCombo_.get_active_text());
            }

            if (energy_ == "on")
            {
                cp_ = Glib::Ascii::strtod(cpEntry_.get_text());
                unitConversion_->toJoulePerKgPerKelvin(cp_, cpCombo_.get_active_text());

                cond_ = Glib::Ascii::strtod(condEntry_.get_text());
                unitConversion_->toWattPerMeterPerKelvin(cond_, condCombo_.get_active_text());
            }
            else
            {
                cp_ = 1.;
                cond_ = 1.;
            }
        }
        else if (type_ == "het1d")
        {
            MW_.clear();
            diff_.clear();
            MW_.resize(NC_);
            diff_.resize(NC_);
            for (unsigned int i = 0; i < NC_; i++)
            {
                MW_[i] = Glib::Ascii::strtod(speciesMwEntry_[i]->get_text());
                diff_[i] = Glib::Ascii::strtod(speciesDiffEntry_[i]->get_text());
                unitConversion_->toSquareMeterPerSecond(diff_[i], diffCombo_.get_active_text());
            }

            Qhom_.clear();
            Qhom_.resize(Nhom_);

            for (unsigned int i = 0; i < Nhom_; i++)
            {
                Qhom_[i] = Glib::Ascii::strtod(speciesHeatEntry_[i]->get_text());
                unitConversion_->toJoulePerKmole(Qhom_[i], heatCombo_.get_active_text());
            }

            Qhet_.clear();
            Qhet_.resize(Nhet_);

            for (unsigned int i = Nhom_; i < NR_; i++)
            {
                Qhet_[i - Nhom_] = Glib::Ascii::strtod(speciesHeatEntry_[i]->get_text());
                unitConversion_->toJoulePerKmole(Qhet_[i - Nhom_], heatCombo_.get_active_text());
            }

            mu_ = Glib::Ascii::strtod(muEntry_.get_text());
            unitConversion_->toPascalPerSecond(mu_, muCombo_.get_active_text());

            if (energy_ == "on")
            {
                cp_ = Glib::Ascii::strtod(cpEntry_.get_text());
                unitConversion_->toJoulePerKgPerKelvin(cp_, cpCombo_.get_active_text());

                cond_ = Glib::Ascii::strtod(condEntry_.get_text());
                unitConversion_->toWattPerMeterPerKelvin(cond_, condCombo_.get_active_text());
            }
            else
            {
                cp_ = 1.;
                cond_ = 1.;
            }
        }
        else if (type_ == "pellet")
        {
            MW_.clear();
            diff_.clear();
            MW_.resize(NC_);
            diff_.resize(NC_);
            for (unsigned int i = 0; i < NC_; i++)
            {
                MW_[i] = Glib::Ascii::strtod(speciesMwEntry_[i]->get_text());
                diff_[i] = Glib::Ascii::strtod(speciesDiffEntry_[i]->get_text());
                unitConversion_->toSquareMeterPerSecond(diff_[i], diffCombo_.get_active_text());
            }
        }
        this->hide();
    }

    void constantProperties::convertToCaption(std::string &n)
    {
        std::transform(n.begin(), n.end(), n.begin(), ::toupper);
    }

    std::vector<double> constantProperties::getMassFraction(const std::vector<double> &MW, const std::vector<double> &x)
    {
        std::vector<double> y(x.size());
        double MWmix = 0.;

        for (unsigned int i = 0; i < x.size(); i++)
        {
            MWmix = MWmix + x[i] * MW[i];
        }

        for (unsigned int i = 0; i < x.size(); i++)
        {
            y[i] = x[i] * MW[i] / MWmix;
        }
        return y;
    }

    std::vector<double> constantProperties::getMoleFraction(const std::vector<double> &MW, const std::vector<double> &y)
    {
        std::vector<double> x(y.size());
        double MWmix = 0.;

        for (unsigned int i = 0; i < y.size(); i++)
        {
            MWmix = MWmix + y[i] / MW[i];
        }

        for (unsigned int i = 0; i < y.size(); i++)
        {
            x[i] = (y[i] / MW[i]) / MWmix;
        }
        return x;
    }

    double constantProperties::getMWmix(const std::vector<double> &MW, const std::vector<double> &y)
    {
        double MWmix = 0.;

        for (unsigned int i = 0; i < y.size(); i++)
        {
            MWmix = MWmix + y[i] / MW[i];
        }

        return 1. / MWmix;
    }

    constantProperties::~constantProperties()
    {
        delete beerQuote_;
        delete unitConversion_;
    }
}
