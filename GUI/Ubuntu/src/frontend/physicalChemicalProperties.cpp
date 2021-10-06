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

#include "frontend/physicalChemicalProperties.hpp"

namespace ASALI
{
    physicalChemicalProperties::physicalChemicalProperties(ASALI::speciesPopup *speciesNames,
                                                           const std::string &kineticType)
        : basicProperties(speciesNames, kineticType),
          rhoBox_(Gtk::ORIENTATION_VERTICAL),
          mwBox_(Gtk::ORIENTATION_VERTICAL),
          exitButton2_("Exit"),
          saveButton_("Save"),
          backButton_("Back"),
          rhoLabel_("Density"),
          mwLabel_("Molecular weight")
    {
        this->createInputGrid();
        this->set_border_width(15);
        this->set_title("ASALI: Physical and chemical properties");
        this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
        this->set_icon_from_file(fileManager_.relative_path_to_absolute_path("images/Icon.png"));
        this->input();

        {
            resultsGrid_.set_column_homogeneous(true);
            resultsGrid_.set_column_spacing(10);
            resultsGrid_.set_row_spacing(10);

            //Molecular weight
            mwBox_.pack_start(mwLabel_, Gtk::PACK_SHRINK);
            mwBox_.pack_start(mwCombo_, Gtk::PACK_SHRINK);
            mwBox_.set_spacing(5);
            mwBox_.set_halign(Gtk::ALIGN_CENTER);
            mwCombo_.append("g/mol");
            mwCombo_.append("kg/mol");
            mwCombo_.append("g/kmol");
            mwCombo_.append("kg/kmol");
            mwCombo_.set_active(0);
            mwCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this, &physicalChemicalProperties::mwUnitConversion), true));

            //Density
            rhoBox_.pack_start(rhoLabel_, Gtk::PACK_SHRINK);
            rhoBox_.pack_start(rhoCombo_, Gtk::PACK_SHRINK);
            rhoBox_.set_spacing(5);
            rhoBox_.set_halign(Gtk::ALIGN_CENTER);
            rhoCombo_.append("kg/m\u00b3");
            rhoCombo_.append("g/cm\u00b3");
            rhoCombo_.set_active(0);
            rhoCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this, &physicalChemicalProperties::rhoUnitConversion), true));

            //Add heading
            resultsGrid_.attach(mwBox_, 1, 0, 1, 1);
            resultsGrid_.attach(rhoBox_, 2, 0, 1, 1);

            //Add back button
            resultsGrid_.attach(backButton_, 0, n_.size() + 2, 1, 1);
            backButton_.signal_clicked().connect(sigc::mem_fun(*this, &physicalChemicalProperties::input));

            //Add print on file
            resultsGrid_.attach(saveButton_, 1, n_.size() + 2, 1, 1);
            saveButton_.signal_clicked().connect(sigc::mem_fun(*this, &physicalChemicalProperties::save));

            //Add exit button
            resultsGrid_.attach(exitButton2_, 2, n_.size() + 2, 1, 1);
            exitButton2_.signal_clicked().connect(sigc::mem_fun(*this, &physicalChemicalProperties::exit));
        }
    }

    void physicalChemicalProperties::clean()
    {
        resultsGrid_.remove(backButton_);
        resultsGrid_.remove(saveButton_);
        resultsGrid_.remove(exitButton2_);

        if (mwVector_.size() != 0)
        {
            for (unsigned int i = 0; i < mwVector_.size(); i++)
            {
                resultsGrid_.remove(*mwVector_[i]);
            }
        }

        if (rhoVector_.size() != 0)
        {
            for (unsigned int i = 0; i < rhoVector_.size(); i++)
            {
                resultsGrid_.remove(*rhoVector_[i]);
            }
        }
    }

    void physicalChemicalProperties::results()
    {
        this->inputReader();
        if (checkInput_.second == false)
        {
            this->checkInput(checkInput_.first);
        }
        else
        {
            this->clean();
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
            x_.clear();
            y_.clear();
            x_.resize(n_.size());
            y_.resize(n_.size());
            {
                x_ = chemistryInterface_->getMoleFractionFromNames(n_);
                y_ = chemistryInterface_->getMassFractionFromNames(n_);
            }

            MW_.clear();
            rho_.clear();
            MW_.resize(n_.size());
            rho_.resize(n_.size());

            for (unsigned int i = 0; i < n_.size(); i++)
            {
                for (unsigned int j = 0; j < chemistryInterface_->names().size(); j++)
                {
                    if (n_[i] == chemistryInterface_->names()[j])
                    {
                        MW_[i] = chemistryInterface_->MW()[j];
                        rho_[i] = MW_[i] * p_ / (8314. * T_);
                        break;
                    }
                }
            }

            if (n_.size() > 1)
            {
                n_.push_back("mix");
            }

            MW_.push_back(chemistryInterface_->getMWmix());
            rho_.push_back(chemistryInterface_->getMWmix() * p_ / (8314. * T_));

            //Add back button
            resultsGrid_.attach(backButton_, 0, n_.size() + 2, 1, 1);

            //Add print on file
            resultsGrid_.attach(saveButton_, 1, n_.size() + 2, 1, 1);

            //Add exit button
            resultsGrid_.attach(exitButton2_, 2, n_.size() + 2, 1, 1);

            this->remove();
            this->add(resultsGrid_);
            this->resize(resultsGrid_.get_width(), resultsGrid_.get_height());
            this->showAtomNames();
            this->rhoUnitConversion(false);
            this->mwUnitConversion(false);
        }
    }

    void physicalChemicalProperties::showAtomNames()
    {
        if (nameVector_.size() != 0)
        {
            for (unsigned int i = 0; i < nameVector_.size(); i++)
            {
                resultsGrid_.remove(*nameVector_[i]);
            }
        }

        nameVector_.clear();
        nameVector_.resize(n_.size());

        for (unsigned int i = 0; i < n_.size(); i++)
        {
            nameVector_[i] = new Gtk::Label(n_[i]);
            resultsGrid_.attach(*nameVector_[i], 0, i + 1, 1, 1);
        }
    }

    void physicalChemicalProperties::mwUnitConversion(bool check)
    {
        if (check == true)
        {
            if (mwVector_.size() != 0)
            {
                for (unsigned int i = 0; i < mwVector_.size(); i++)
                {
                    resultsGrid_.remove(*mwVector_[i]);
                }
            }
        }

        mwVector_.clear();
        mwVector_.resize(n_.size());
        std::vector<double> converter(n_.size());

        if (mwCombo_.get_active_row_number() == 0)
        {
            for (unsigned int i = 0; i < n_.size(); i++)
            {
                converter[i] = 1.; //g/mol
            }
        }
        else if (mwCombo_.get_active_row_number() == 1)
        {
            for (unsigned int i = 0; i < n_.size(); i++)
            {
                converter[i] = 1.e-03; //kg/mol
            }
        }
        else if (mwCombo_.get_active_row_number() == 2)
        {
            for (unsigned int i = 0; i < n_.size(); i++)
            {
                converter[i] = 1. / 1.e-03; //g/kmol
            }
        }
        else if (mwCombo_.get_active_row_number() == 3)
        {
            for (unsigned int i = 0; i < n_.size(); i++)
            {
                converter[i] = 1.; //kg/kmol
            }
        }

        for (unsigned int i = 0; i < n_.size(); i++)
        {
            std::stringstream mw;
            mw << std::scientific << std::setprecision(OP_) << MW_[i] * converter[i];
            mwVector_[i] = new Gtk::Label(mw.str());
            resultsGrid_.attach(*mwVector_[i], 1, i + 1, 1, 1);
        }

        this->show_all_children();
    }

    void physicalChemicalProperties::rhoUnitConversion(bool check)
    {
        if (check == true)
        {
            if (rhoVector_.size() != 0)
            {
                for (unsigned int i = 0; i < rhoVector_.size(); i++)
                {
                    resultsGrid_.remove(*rhoVector_[i]);
                }
            }
        }

        rhoVector_.clear();
        rhoVector_.resize(n_.size());
        std::vector<double> converter(n_.size());

        if (rhoCombo_.get_active_row_number() == 0)
        {
            for (unsigned int i = 0; i < n_.size(); i++)
            {
                converter[i] = 1.; //kg/m3
            }
        }
        else if (rhoCombo_.get_active_row_number() == 1)
        {
            for (unsigned int i = 0; i < n_.size(); i++)
            {
                converter[i] = 1.e03 / 1.e06; //g/cm3
            }
        }

        for (unsigned int i = 0; i < n_.size(); i++)
        {
            std::stringstream rho;
            rho << std::scientific << std::setprecision(OP_) << rho_[i] * converter[i];
            rhoVector_[i] = new Gtk::Label(rho.str());
            resultsGrid_.attach(*rhoVector_[i], 2, i + 1, 1, 1);
        }

        this->show_all_children();
    }

    void physicalChemicalProperties::save()
    {
        std::string filename = fileManager_.saveFile(this->get_toplevel()->gobj(), "properties.asali");
        if (filename != "")
        {
            std::ofstream output;
            const char *path = filename.c_str();
            output.open(path, std::ios::out);

            output << "Temperature:     " << T_ << " K" << std::endl;
            output << "Pressure:        " << p_ << " Pa" << std::endl;
            output << std::endl;
            output.setf(std::ios::scientific);
            output.precision(6);

            output << "Species\t"
                   << "x            \ty            \tMW           \t\u03C1" << std::endl;
            for (unsigned int i = 0; i < n_.size(); i++)
            {
                if (i == n_.size() - 1)
                {
                    output << n_[i] << "\t"
                           << "            "
                           << "\t"
                           << "            "
                           << "\t" << MW_[i] << "\t" << rho_[i] << std::endl;
                }
                else
                {
                    output << n_[i] << "\t" << x_[i] << "\t" << y_[i] << "\t" << MW_[i] << "\t" << rho_[i] << std::endl;
                }
            }

            output << std::endl;
            output << "x : mole fraction" << std::endl;
            output << "y : mass fraction" << std::endl;
            output << "MW: molecular weight [g/mol]" << std::endl;
            output << "\u03C1 : density          [kg/m\u00b3]" << std::endl;
            output.close();
            this->savedMessage();
        }
    }
}
