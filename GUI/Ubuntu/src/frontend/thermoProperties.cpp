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

#include "frontend/thermoProperties.hpp"

namespace ASALI
{
    thermoProperties::thermoProperties(ASALI::speciesPopup *speciesNames, std::string kineticType)
        : thermoTransportProperties(speciesNames, kineticType)
    {
        //Input menu
        {
            this->set_border_width(15);
            this->set_title("ASALI: Thermodynamic properties");
            this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
            this->set_icon_from_file(fileManager_.relative_path_to_absolute_path("images/Icon.png"));
            this->input();
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

        if (cpVector_.size() != 0)
        {
            for (unsigned int i = 0; i < cpVector_.size(); i++)
            {
                resultsGrid_.remove(*cpVector_[i]);
            }
        }

        if (sVector_.size() != 0)
        {
            for (unsigned int i = 0; i < sVector_.size(); i++)
            {
                resultsGrid_.remove(*sVector_[i]);
            }
        }

        if (hVector_.size() != 0)
        {
            for (unsigned int i = 0; i < hVector_.size(); i++)
            {
                resultsGrid_.remove(*hVector_[i]);
            }
        }
    }

    void thermoProperties::results()
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

            chemistryInterface_->thermoCalculate();

            x_.clear();
            y_.clear();
            x_.resize(n_.size());
            y_.resize(n_.size());
            {
                std::vector<double> x = chemistryInterface_->mole();
                std::vector<double> y = chemistryInterface_->mass();

                for (unsigned int i = 0; i < n_.size(); i++)
                {
                    for (unsigned int j = 0; j < chemistryInterface_->numberOfGasSpecies(); j++)
                    {
                        if (n_[i] == chemistryInterface_->names()[j])
                        {
                            x_[i] = x[j];
                            y_[i] = y[j];
                            break;
                        }
                    }
                }
            }

            if (n_.size() > 1)
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

            for (unsigned int i = 0; i < n_.size(); i++)
            {
                for (unsigned int j = 0; j < chemistryInterface_->mixtureNames().size(); j++)
                {
                    if (n_[i] == chemistryInterface_->mixtureNames()[j])
                    {
                        h_[i] = chemistryInterface_->h()[j];
                        s_[i] = chemistryInterface_->s()[j];
                        cp_[i] = chemistryInterface_->cp()[j];
                        MW_[i] = chemistryInterface_->MW()[j];
                        break;
                    }
                }
            }

            //Thermo grid menu
            {
                //Add back button
                resultsGrid_.attach(backButton_, 0, n_.size() + 2, 1, 1);

                //Add print on file
                resultsGrid_.attach(saveButton_, 1, n_.size() + 2, 1, 1);

                //Add exit button
                resultsGrid_.attach(exitButton2_, 3, n_.size() + 2, 1, 1);

                this->remove();
                this->add(resultsGrid_);
                this->resize(resultsGrid_.get_width(), resultsGrid_.get_height());
                this->showAtomNames();
                this->cpUnitConversion(false, 1);
                this->hUnitConversion(false, 2);
                this->sUnitConversion(false, 3);
            }
        }
    }

    void thermoProperties::update()
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
        cpCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this, &thermoProperties::cpUnitConversion), true, 1));

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
        hCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this, &thermoProperties::hUnitConversion), true, 2));

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
        sCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this, &thermoProperties::sUnitConversion), true, 3));

        //Add heading
        resultsGrid_.attach(cpBox_, 1, 0, 1, 1);
        resultsGrid_.attach(hBox_, 2, 0, 1, 1);
        resultsGrid_.attach(sBox_, 3, 0, 1, 1);

        //Add back button
        resultsGrid_.attach(backButton_, 0, n_.size() + 2, 1, 1);
        backButton_.signal_clicked().connect(sigc::mem_fun(*this, &thermoProperties::input));

        //Add print on file
        resultsGrid_.attach(saveButton_, 1, n_.size() + 2, 1, 1);
        saveButton_.signal_clicked().connect(sigc::mem_fun(*this, &thermoProperties::save));

        //Add exit button
        resultsGrid_.attach(exitButton2_, 3, n_.size() + 2, 1, 1);
        exitButton2_.signal_clicked().connect(sigc::mem_fun(*this, &thermoProperties::exit));
    }

    void thermoProperties::save()
    {
        std::string filename = fileManager_.saveFile(this->get_toplevel()->gobj(), "thermo.asali");
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
                   << "x            \ty            \tCp           \tH            \tS            \t" << std::endl;
            for (unsigned int i = 0; i < n_.size(); i++)
            {
                if (i == n_.size() - 1)
                {
                    output << n_[i] << "\t"
                           << "           "
                           << "\t"
                           << "           "
                           << "\t" << cp_[i] / 1e03 << "\t" << h_[i] / 1e03 << "\t" << s_[i] / 1e03 << std::endl;
                }
                else
                {
                    output << n_[i] << "\t" << x_[i] << "\t" << y_[i] << "\t" << cp_[i] / 1e03 << "\t" << h_[i] / 1e03 << "\t" << s_[i] / 1e03 << std::endl;
                }
            }

            output << std::endl;
            output << "x : mole fraction" << std::endl;
            output << "y : mass fraction" << std::endl;
            output << "Cp: specific heat  [J/mol/K]" << std::endl;
            output << "H : enthalpy       [J/mol]" << std::endl;
            output << "S : entropy        [J/mol/K]" << std::endl;
            output.close();
            this->savedMessage();
        }
    }

}
