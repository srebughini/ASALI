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

#include "frontend/transportProperties.hpp"

namespace ASALI
{
    transportProperties::transportProperties(ASALI::speciesPopup *speciesNames, const std::string &kineticType)
        : thermoTransportProperties(speciesNames, kineticType)
    {
        // Input menu
        {
            this->set_border_width(15);
            this->set_title("ASALI: Transport properties");
            this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
            this->set_icon_from_file(fileManager_.relative_path_to_absolute_path("images/Icon.png"));
            this->input();
        }
    }

    void transportProperties::clean()
    {
        resultsGrid_.remove(backButton_);
        resultsGrid_.remove(saveButton_);
        resultsGrid_.remove(exitButton2_);

        if (condVector_.size() != 0)
        {
            for (unsigned int i = 0; i < condVector_.size(); i++)
            {
                resultsGrid_.remove(*condVector_[i]);
            }
        }

        if (muVector_.size() != 0)
        {
            for (unsigned int i = 0; i < muVector_.size(); i++)
            {
                resultsGrid_.remove(*muVector_[i]);
            }
        }

        if (diffBoxVector_.size() != 0)
        {
            for (unsigned int i = 0; i < diffBoxVector_.size(); i++)
            {
                resultsGrid_.remove(*diffBoxVector_[i]);
            }
        }
    }

    void transportProperties::results()
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
				chemistryInterface_->setMassFraction(x_, n_);
			}
			else if (fractionCombo_.get_active_row_number() == 1)
			{
				chemistryInterface_->setMoleFraction(x_, n_);
			}


            chemistryInterface_->transportCalculate();
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

            mu_.clear();
            cond_.clear();
            diff_.clear();
            MW_.clear();
            mu_.resize(n_.size());
            cond_.resize(n_.size());
            diff_.resize(n_.size());
            MW_.resize(n_.size());
            for (unsigned int i = 0; i < n_.size(); i++)
            {
                diff_[i].resize(n_.size());
            }

            for (unsigned int i = 0; i < n_.size(); i++)
            {
                for (unsigned int j = 0; j < chemistryInterface_->mixtureNames().size(); j++)
                {
                    if (n_[i] == chemistryInterface_->mixtureNames()[j])
                    {
                        mu_[i] = chemistryInterface_->mu()[j];
                        cond_[i] = chemistryInterface_->cond()[j];
                        MW_[i] = chemistryInterface_->MW()[j];
                        for (unsigned int k = 0; k < n_.size(); k++)
                        {
                            for (unsigned int h = 0; h < chemistryInterface_->mixtureNames().size(); h++)
                            {
                                if (n_[k] == chemistryInterface_->mixtureNames()[h])
                                {
                                    diff_[i][k] = chemistryInterface_->diff()[j][h];
                                    break;
                                }
                            }
                        }
                        break;
                    }
                }
            }

            // Add back button
            resultsGrid_.attach(backButton_, 0, n_.size() + 2, 1, 1);

            // Add print on file
            resultsGrid_.attach(saveButton_, 1, n_.size() + 2, 1, 1);

            // Add exit button
            resultsGrid_.attach(exitButton2_, 3, n_.size() + 2, 1, 1);

            this->remove();
            this->add(resultsGrid_);
            this->resize(resultsGrid_.get_width(), resultsGrid_.get_height());
            this->showAtomNames();
            this->condUnitConversion(false, 1);
            this->muUnitConversion(false, 2);
            this->diffUnitConversion(false, 3);
        }
    }

    void transportProperties::update()
    {
        resultsGrid_.set_column_homogeneous(true);
        resultsGrid_.set_column_spacing(10);
        resultsGrid_.set_row_spacing(10);

        // Thermal conductivity
        condBox_.pack_start(condLabel_, Gtk::PACK_SHRINK);
        condBox_.pack_start(condCombo_, Gtk::PACK_SHRINK);
        condBox_.set_spacing(5);
        condBox_.set_halign(Gtk::ALIGN_CENTER);
        condCombo_.append("W/m/K");
        condCombo_.append("cal/m/s/k");
        condCombo_.set_active(0);
        condCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this, &transportProperties::condUnitConversion), true, 1));

        // Viscosity
        muBox_.pack_start(muLabel_, Gtk::PACK_SHRINK);
        muBox_.pack_start(muCombo_, Gtk::PACK_SHRINK);
        muBox_.set_spacing(5);
        muBox_.set_halign(Gtk::ALIGN_CENTER);
        muCombo_.append("Pas");
        muCombo_.append("cP");
        muCombo_.set_active(0);
        muCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this, &transportProperties::muUnitConversion), true, 2));

        // Diffusivity
        diffBox_.pack_start(diffLabel_, Gtk::PACK_SHRINK);
        diffBox_.pack_start(diffCombo_, Gtk::PACK_SHRINK);
        diffBox_.set_spacing(5);
        diffBox_.set_halign(Gtk::ALIGN_CENTER);
        diffCombo_.append("m\u00b2/s");
        diffCombo_.set_active(0);
        diffCombo_.signal_changed().connect(sigc::bind<bool>(sigc::mem_fun(*this, &transportProperties::diffUnitConversion), true, 3));

        // Add heading
        resultsGrid_.attach(condBox_, 1, 0, 1, 1);
        resultsGrid_.attach(muBox_, 2, 0, 1, 1);
        resultsGrid_.attach(diffBox_, 3, 0, 1, 1);

        // Add back button
        resultsGrid_.attach(backButton_, 0, n_.size() + 2, 1, 1);
        backButton_.signal_clicked().connect(sigc::mem_fun(*this, &transportProperties::input));

        // Add print on file
        resultsGrid_.attach(saveButton_, 1, n_.size() + 2, 1, 1);
        saveButton_.signal_clicked().connect(sigc::mem_fun(*this, &transportProperties::save));

        // Add exit button
        resultsGrid_.attach(exitButton2_, 3, n_.size() + 2, 1, 1);
        exitButton2_.signal_clicked().connect(sigc::mem_fun(*this, &transportProperties::exit));
    }

    void transportProperties::save()
    {
        std::string filename = fileManager_.saveFile(this->get_toplevel()->gobj(), "transport.asali");
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
                   << "x           \ty           \t\u03BB           \t\u03BC           \t\u0393           " << std::endl;
            for (unsigned int i = 0; i < n_.size(); i++)
            {
                for (unsigned int j = i; j < n_.size(); j++)
                {
                    if (i == n_.size() - 1)
                    {
                        output << n_[i] << " "
                               << "  "
                               << "\t"
                               << "             "
                               << "\t"
                               << "             "
                               << "\t" << cond_[i] << "\t" << mu_[i] << std::endl;
                    }
                    else
                    {
                        if (j == i)
                        {
                            output << n_[i] << " " << n_[j] << "\t" << x_[i] << "\t" << y_[i] << "\t" << cond_[i] << "\t" << mu_[i] << "\t" << diff_[i][j] << std::endl;
                        }
                        else
                        {
                            output << n_[i] << " " << n_[j] << "\t"
                                   << "           "
                                   << "\t"
                                   << "           "
                                   << "\t"
                                   << "           "
                                   << "\t"
                                   << "           "
                                   << "\t" << diff_[i][j] << std::endl;
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
            this->savedMessage();
        }
    }
}
