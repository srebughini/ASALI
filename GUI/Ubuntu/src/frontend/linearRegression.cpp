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

#include "frontend/linearRegression.hpp"

namespace ASALI
{
    linearRegression::linearRegression(ASALI::speciesPopup *speciesNames,
                                       const std::string &kineticType)
        : basicProperties(speciesNames, kineticType),
          tempBox_(Gtk::ORIENTATION_VERTICAL),
          exitButton2_("Exit"),
          backButton_("Back"),
          calculateButton_("Calculate"),
          tempRangeLabel_("Temperature range"),
          propertyLabel_("Property"),
          mLabel_("m:\t"),
          mValueLabel_("n.a."),
          qLabel_("q:\t"),
          qValueLabel_("n.a."),
          rLabel_("R\u00b2:\t"),
          rValueLabel_("n.a."),
          logo_(fileManager_.relative_path_to_absolute_path("images/RegressionLogo.png")),
          diffCheck_(false)
    {
        {
            Tv_.resize(10);
            pv_.resize(10);
        }

        // Input menu
        {
            this->set_border_width(15);
            this->set_title("ASALI: Linear regression");
            this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
            this->set_icon_from_file(fileManager_.relative_path_to_absolute_path("images/Icon.png"));
            this->createInputGrid();
            this->cleanInput();
        }

        // Results
        {
            resultsGrid_.set_column_homogeneous(true);
            resultsGrid_.set_column_spacing(10);
            resultsGrid_.set_row_spacing(10);

            // Add logo
            resultsGrid_.attach(logo_, 0, 0, 4, 1);

            // Add temperature range
            resultsGrid_.attach(tempRangeLabel_, 0, 1, 1, 1);
            resultsGrid_.attach(tempEntry1_, 1, 1, 1, 1);
            tempEntry1_.set_text("298.15");
            resultsGrid_.attach(tempEntry2_, 2, 1, 1, 1);
            tempEntry2_.set_text("398.15");
            resultsGrid_.attach(tempRangeCombo_, 3, 1, 1, 1);
            unitConversion_->updateBox(tempRangeCombo_, "temperature");

            // Add properties selector
            resultsGrid_.attach(propertyLabel_, 0, 2, 1, 1);
            resultsGrid_.attach(propertyCombo_, 1, 2, 2, 1);
            propertyCombo_.append("Thermal conductivity"); // 0
            propertyCombo_.append("Viscosity");            // 1
            propertyCombo_.append("Specific heat");        // 2
            propertyCombo_.append("Enthalpy");             // 3
            propertyCombo_.append("Entropy");              // 4
            propertyCombo_.append("Diffusivity");          // 5
            propertyCombo_.set_active(0);
            propertyCombo_.signal_changed().connect(sigc::mem_fun(*this, &linearRegression::uploadLayout));
            resultsGrid_.attach(unitDimensionCombo_, 3, 2, 1, 1);

            // Add regression image
            resultsGrid_.attach(regressionImage_, 0, 3, 4, 1);

            // Add value
            resultsGrid_.attach(mLabel_, 0, 4, 1, 1);
            resultsGrid_.attach(mValueLabel_, 1, 4, 1, 1);
            resultsGrid_.attach(qLabel_, 0, 5, 1, 1);
            resultsGrid_.attach(qValueLabel_, 1, 5, 1, 1);
            resultsGrid_.attach(rLabel_, 2, 4, 1, 2);
            resultsGrid_.attach(rValueLabel_, 3, 4, 1, 2);

            // Add buttons
            resultsGrid_.attach(backButton_, 0, 6, 1, 1);
            backButton_.signal_clicked().connect(sigc::mem_fun(*this, &linearRegression::cleanInput));
            resultsGrid_.attach(calculateButton_, 2, 6, 1, 1);
            calculateButton_.signal_clicked().connect(sigc::mem_fun(*this, &linearRegression::run));
            resultsGrid_.attach(exitButton2_, 3, 6, 1, 1);
            exitButton2_.signal_clicked().connect(sigc::mem_fun(*this, &linearRegression::exit));
        }
    }

    void linearRegression::cleanInput()
    {
        // Remove temperature selector
        inputGrid_.remove(tempLabel_);
        inputGrid_.remove(tempEntry_);
        inputGrid_.remove(tempCombo_);
        doneButton_.set_label("Next");
        this->input();
    }

    void linearRegression::results()
    {
        this->inputReader();
        if (checkInput_.second == false)
        {
            this->checkInput(checkInput_.first);
        }
        else
        {
            this->remove();
            this->add(resultsGrid_);
            this->uploadLayout();
            this->resize(resultsGrid_.get_width(), resultsGrid_.get_height());
            this->show_all_children();

            // Add temperature selector
            inputGrid_.attach(tempLabel_, 0, 0, 1, 1);
            inputGrid_.attach(tempEntry_, 1, 0, 1, 1);
            tempEntry_.set_max_length(10);
            tempEntry_.set_text("298.15");
            inputGrid_.attach(tempCombo_, 2, 0, 1, 1);
            unitConversion_->updateBox(tempCombo_, "temperature");
            doneButton_.set_label("Done");
        }
    }

    void linearRegression::uploadLayout()
    {
        std::string property;
        if (propertyCombo_.get_active_row_number() == 0)
        {
            property = "conductivity";
        }
        else if (propertyCombo_.get_active_row_number() == 1)
        {
            property = "viscosity";
        }
        else if (propertyCombo_.get_active_row_number() == 2)
        {
            property = "specificheat";
        }
        else if (propertyCombo_.get_active_row_number() == 3)
        {
            property = "enthalpy";
        }
        else if (propertyCombo_.get_active_row_number() == 4)
        {
            property = "entropy";
        }
        else if (propertyCombo_.get_active_row_number() == 5)
        {
            property = "diffusivity";
        }

        unitConversion_->updateBox(unitDimensionCombo_, property);
        regressionImage_.set(fileManager_.relative_path_to_absolute_path("images/RegressionExponential.png"));

        if (diffCheck_)
        {
            resultsGrid_.remove(specieCombo_);
            diffCheck_ = false;
        }

        if (propertyCombo_.get_active_row_number() == 5)
        {
            specieCombo_.remove_all();
            for (unsigned int i = 0; i < n_.size(); i++)
            {
                specieCombo_.append(n_[i]);
            }

            resultsGrid_.attach(specieCombo_, 1, 6, 1, 1);
            specieCombo_.set_active(0);

            diffCheck_ = true;
        }
    }

    void linearRegression::run()
    {
        this->inputReader();
        if (checkInput_.second == false)
        {
            this->checkInput(checkInput_.first);
        }
        else
        {
            // Make temperature vector
            {
                double T1 = Glib::Ascii::strtod(tempEntry1_.get_text());
                double T2 = Glib::Ascii::strtod(tempEntry2_.get_text());
                unitConversion_->toKelvin(T1, tempCombo_.get_active_text());
                unitConversion_->toKelvin(T2, tempCombo_.get_active_text());

                double Tmax = std::max(T1, T2);
                double Tmin = std::min(T1, T2);
                double dT = double(Tmax - Tmin) / (Tv_.size() - 1);

                Tv_[0] = Tmin;
                for (unsigned int i = 1; i < Tv_.size(); i++)
                {
                    Tv_[i] = Tv_[i - 1] + dT;
                }
            }

            // Set CANTERA
            {
                if (n_.size() > 1)
                {
                    name_ = "mix";
                }
                else
                {
                    name_ = n_[0];
                }
            }

            // Property evaluation
            for (unsigned int i = 0; i < Tv_.size(); i++)
            {
                chemistryInterface_->setTemperature(Tv_[i]);

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
                chemistryInterface_->thermoCalculate();

                if (propertyCombo_.get_active_row_number() == 0)
                {
                    pv_[i] = chemistryInterface_->specieProperty("cond", name_);

                    // Convert unit
                    this->condUnitDimensions(pv_[i]);

                    Tv_[i] = std::log(Tv_[i]);
                    pv_[i] = std::log(pv_[i]);
                }
                else if (propertyCombo_.get_active_row_number() == 1)
                {
                    pv_[i] = chemistryInterface_->specieProperty("mu", name_);

                    // Convert unit
                    this->muUnitDimensions(pv_[i]);

                    Tv_[i] = std::log(Tv_[i]);
                    pv_[i] = std::log(pv_[i]);
                }
                else if (propertyCombo_.get_active_row_number() == 2)
                {
                    pv_[i] = chemistryInterface_->specieProperty("cp", name_);

                    // Convert unit
                    this->cpUnitDimensions(pv_[i]);
                }
                else if (propertyCombo_.get_active_row_number() == 3)
                {
                    pv_[i] = chemistryInterface_->specieProperty("h", name_);

                    // Convert unit
                    this->hUnitDimensions(pv_[i]);
                }
                else if (propertyCombo_.get_active_row_number() == 4)
                {
                    pv_[i] = chemistryInterface_->specieProperty("s", name_);

                    // Convert unit
                    this->sUnitDimensions(pv_[i]);

                    Tv_[i] = std::log(Tv_[i]);
                    pv_[i] = std::log(pv_[i]);
                }
                else if (propertyCombo_.get_active_row_number() == 5)
                {
                    name_ = specieCombo_.get_active_text();
                    pv_[i] = chemistryInterface_->specieProperty("s", name_);

                    // Convert unit
                    this->diffUnitDimensions(pv_[i]);

                    Tv_[i] = std::log(Tv_[i]);
                    pv_[i] = std::log(pv_[i]);
                }
            }

            // Least square regression
            {
                this->leastSquareFitting(Tv_, pv_, m_, q_, r2_);

                if (propertyCombo_.get_active_row_number() == 0)
                {
                    q_ = std::exp(q_);
                }
                else if (propertyCombo_.get_active_row_number() == 1)
                {
                    q_ = std::exp(q_);
                }
                else if (propertyCombo_.get_active_row_number() == 4)
                {
                    q_ = std::exp(q_);
                }
                else if (propertyCombo_.get_active_row_number() == 5)
                {
                    q_ = std::exp(q_);
                }
            }

            // Show m_
            {
                std::stringstream s;
                s << std::scientific << std::setprecision(OP_) << std::setprecision(OP_) << m_;
                mValueLabel_.set_text(s.str());
            }

            // Show q_
            {
                std::stringstream s;
                s << std::scientific << std::setprecision(OP_) << std::setprecision(OP_) << q_;
                qValueLabel_.set_text(s.str());
            }

            // Show r2_
            {
                std::stringstream s;
                s << std::scientific << std::setprecision(OP_) << std::setprecision(OP_) << r2_;
                rValueLabel_.set_text(s.str());
            }
        }

        this->show_all_children();
    }

    void linearRegression::leastSquareFitting(const std::vector<double> &x, const std::vector<double> &y, double &m, double &q, double &r2)
    {
        m = (x.size() * vectorUtils_->SumElements(vectorUtils_->ElementByElementProduct(x, y)) - vectorUtils_->SumElements(x) * vectorUtils_->SumElements(y)) / (x.size() * vectorUtils_->SumElements(vectorUtils_->ElementByElementProduct(x, x)) - std::pow(vectorUtils_->SumElements(x), 2.));
        q = (vectorUtils_->SumElements(y) * vectorUtils_->SumElements(vectorUtils_->ElementByElementProduct(x, x)) - vectorUtils_->SumElements(x) * vectorUtils_->SumElements(vectorUtils_->ElementByElementProduct(x, y))) / (x.size() * vectorUtils_->SumElements(vectorUtils_->ElementByElementProduct(x, x)) - std::pow(vectorUtils_->SumElements(x), 2.));

        double tss = 0.;
        double rss = 0.;
        for (unsigned int i = 0; i < x.size(); i++)
        {
            tss = tss + std::pow((y[i] - vectorUtils_->MeanValue(y)), 2.);
            rss = rss + std::pow((y[i] - m * x[i] - q), 2.);
        }

        r2 = 1. - rss / tss;
    }

    void linearRegression::condUnitDimensions(double &p)
    {
        unitConversion_->fromWattPerMeterPerKelvin(p, unitDimensionCombo_.get_active_text());
    }

    void linearRegression::muUnitDimensions(double &p)
    {
        unitConversion_->fromPascalPerSecond(p, unitDimensionCombo_.get_active_text());
    }

    void linearRegression::cpUnitDimensions(double &p)
    {
        unitConversion_->fromJoulePerKmolePerKelvin(p, unitDimensionCombo_.get_active_text(), chemistryInterface_->specieProperty("MW", name_));
    }

    void linearRegression::hUnitDimensions(double &p)
    {
        unitConversion_->fromJoulePerKmole(p, unitDimensionCombo_.get_active_text(), chemistryInterface_->specieProperty("MW", name_));
    }

    void linearRegression::sUnitDimensions(double &p)
    {
        unitConversion_->fromJoulePerKmolePerKelvin(p, unitDimensionCombo_.get_active_text(), chemistryInterface_->specieProperty("MW", name_));
    }

    void linearRegression::diffUnitDimensions(double &p)
    {
        unitConversion_->fromSquareMeterPerSecond(p, unitDimensionCombo_.get_active_text());
    }

    void linearRegression::save() {}
}
