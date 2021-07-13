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

#include "frontend/kineticMaker.hpp"

namespace ASALI
{
    kineticMaker::kineticMaker()
        : reactionNumberBox_(Gtk::ORIENTATION_VERTICAL),
          speciesBox_(Gtk::ORIENTATION_VERTICAL),
          reactionBox_(Gtk::ORIENTATION_VERTICAL),
          equationBox_(Gtk::ORIENTATION_VERTICAL),
          recapBox_(Gtk::ORIENTATION_VERTICAL),
          exitButton1_("Exit"),
          exitButton2_("Exit"),
          nextButton1_("Next"),
          nextButton2_("Next"),
          nextButton3_("Next"),
          nextButton4_("Next"),
          backButton1_("Back"),
          backButton2_("Back"),
          backButton3_("Back"),
          backButton4_("Back"),
          saveButton_("Save"),
          reactionHelpButton_("Help"),
          equationHelpButton_("Help"),
          reactionNumberLabel_("Number of reactions: "),
          speciesLabel_("Please, insert the name of the species involved in the kinetic scheme"),
          numberLabel1_("Reaction number"),
          numberLabel2_("Reaction number"),
          expressionLabel1_("Reaction"),
          expressionLabel2_("Reaction"),
          typeLabel1_("Type"),
          recapSpeciesLabel_("Species"),
          recapReactionLabel_("Reactions"),
          logo1_(this->relative_path_to_absolute_path("images/KineticSchemeLogo.png")),
          logo2_(this->relative_path_to_absolute_path("images/KineticSchemeLogo.png")),
          logo3_(this->relative_path_to_absolute_path("images/KineticSchemeLogo.png")),
          logo4_(this->relative_path_to_absolute_path("images/KineticSchemeLogo.png")),
          logo5_(this->relative_path_to_absolute_path("images/KineticSchemeLogo.png")),
          NR_(0),
          NC_(0),
          restart_(true)
    {
        {
            op_.push_back("+");
            op_.push_back("-");
            op_.push_back("/");
            op_.push_back("*");
            op_.push_back(")");
            op_.push_back("(");
            op_.push_back(",");
            op_.push_back(".");
        }

        #include "shared/Beer.H"
        #include "shared/BeerShort.H"

        //Reaction number
        {
            this->set_border_width(15);
            this->set_title("ASALI: Kinetic scheme");
            this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
            this->set_icon_from_file(this->relative_path_to_absolute_path("images/Icon.png"));

            //Add background grid
            this->add(reactionNumberBox_);

            reactionNumberBox_.set_halign(Gtk::ALIGN_START);
            reactionNumberBox_.set_spacing(10);
            reactionNumberBox_.pack_start(logo1_, Gtk::PACK_SHRINK);
            reactionNumberBox_.pack_start(reactionNumberGrid_, Gtk::PACK_SHRINK);
            {
                reactionNumberGrid_.set_column_spacing(10);
                reactionNumberGrid_.set_row_spacing(10);
                reactionNumberGrid_.set_column_homogeneous(true);

                reactionNumberGrid_.attach(reactionNumberLabel_, 0, 0, 1, 1);
                reactionNumberGrid_.attach(reactionNumberCombo_, 1, 0, 1, 1);
                for (unsigned int i = 0; i < 10; i++)
                {
                    {
                        std::ostringstream s;
                        s << double(i + 1);
                        reactionNumberCombo_.append(s.str());
                    }
                }
                reactionNumberCombo_.set_active(0);

                reactionNumberGrid_.attach(exitButton1_, 0, 1, 1, 1);
                exitButton1_.signal_clicked().connect(sigc::mem_fun(*this, &kineticMaker::exit));
                reactionNumberGrid_.attach(nextButton1_, 1, 1, 1, 1);
                nextButton1_.signal_clicked().connect(sigc::mem_fun(*this, &kineticMaker::species));
            }
            this->show_all_children();
        }

        //Species
        {
            speciesBox_.set_halign(Gtk::ALIGN_START);
            speciesBox_.set_spacing(10);
            speciesBox_.pack_start(logo2_, Gtk::PACK_SHRINK);
            speciesBox_.pack_start(speciesLabel_, Gtk::PACK_SHRINK);
            speciesBox_.pack_start(speciesGrid_, Gtk::PACK_SHRINK);
            {
                speciesGrid_.set_column_spacing(10);
                speciesGrid_.set_row_spacing(10);
                speciesGrid_.set_column_homogeneous(true);

                for (unsigned int i = 0; i < 20; i++)
                {
                    speciesEntry_.push_back(new Gtk::Entry());
                }

                speciesEntry_[0]->set_text("AR");

                unsigned int counter = 0;
                for (unsigned int i = 0; i < 4; i++)
                {
                    for (unsigned int j = 0; j < 5; j++)
                    {
                        speciesGrid_.attach(*speciesEntry_[counter++], i, j, 1, 1);
                    }
                }

                speciesGrid_.attach(backButton1_, 0, 5, 1, 1);
                backButton1_.signal_clicked().connect(sigc::mem_fun(*this, &kineticMaker::reactionNumber));
                speciesGrid_.attach(nextButton2_, 3, 5, 1, 1);
                nextButton2_.signal_clicked().connect(sigc::mem_fun(*this, &kineticMaker::reaction));
            }
        }

        //Reaction
        {
            reactionBox_.set_halign(Gtk::ALIGN_START);
            reactionBox_.set_spacing(10);
            reactionBox_.pack_start(logo3_, Gtk::PACK_SHRINK);
            reactionBox_.pack_start(reactionGrid_, Gtk::PACK_SHRINK);
            {
                reactionGrid_.set_column_spacing(10);
                reactionGrid_.set_row_spacing(10);
                reactionGrid_.set_column_homogeneous(true);

                reactionGrid_.attach(numberLabel1_, 0, 0, 1, 1);
                reactionGrid_.attach(expressionLabel1_, 1, 0, 1, 1);
                reactionGrid_.attach(typeLabel1_, 2, 0, 1, 1);
            }

            reactionGrid_.attach(backButton2_, 0, 5, 1, 1);
            backButton2_.signal_clicked().connect(sigc::mem_fun(*this, &kineticMaker::species));
            reactionGrid_.attach(reactionHelpButton_, 0, 5, 1, 1);
            reactionHelpButton_.signal_clicked().connect(sigc::mem_fun(*this, &kineticMaker::helpReaction));
            reactionGrid_.attach(nextButton3_, 2, 5, 1, 1);
            nextButton3_.signal_clicked().connect(sigc::mem_fun(*this, &kineticMaker::equation));

            reactionLabel_.clear();
            reactionCombo_.clear();
            reactionEntry_.clear();
        }

        //Equation
        {
            equationBox_.set_halign(Gtk::ALIGN_START);
            equationBox_.set_spacing(10);
            equationBox_.pack_start(logo4_, Gtk::PACK_SHRINK);
            equationBox_.pack_start(equationGrid_, Gtk::PACK_SHRINK);
            {
                equationGrid_.set_column_spacing(10);
                equationGrid_.set_row_spacing(10);
                equationGrid_.set_column_homogeneous(true);

                equationGrid_.attach(numberLabel2_, 0, 0, 1, 1);
                equationGrid_.attach(expressionLabel2_, 1, 0, 2, 1);
            }

            equationGrid_.attach(backButton3_, 0, 5, 1, 1);
            backButton3_.signal_clicked().connect(sigc::mem_fun(*this, &kineticMaker::reaction));
            equationGrid_.attach(equationHelpButton_, 0, 5, 1, 1);
            equationHelpButton_.signal_clicked().connect(sigc::mem_fun(*this, &kineticMaker::helpEquation));
            equationGrid_.attach(nextButton4_, 2, 5, 1, 1);
            nextButton4_.signal_clicked().connect(sigc::mem_fun(*this, &kineticMaker::recap));

            equationLabel_.clear();
            equationEntry_.clear();
        }

        //Recap
        {
            recapBox_.set_halign(Gtk::ALIGN_START);
            recapBox_.set_spacing(10);
            recapBox_.pack_start(logo5_, Gtk::PACK_SHRINK);
            recapBox_.pack_start(recapSpeciesLabel_, Gtk::PACK_SHRINK);
            recapBox_.pack_start(recapSpeciesGrid_, Gtk::PACK_SHRINK);
            {
                recapSpeciesGrid_.set_column_spacing(10);
                recapSpeciesGrid_.set_row_spacing(10);
                recapSpeciesGrid_.set_column_homogeneous(true);
            }
            recapBox_.pack_start(recapReactionLabel_, Gtk::PACK_SHRINK);
            recapBox_.pack_start(recapReactionGrid_, Gtk::PACK_SHRINK);
            {
                recapReactionGrid_.set_column_spacing(10);
                recapReactionGrid_.set_row_spacing(10);
                recapReactionGrid_.set_column_homogeneous(true);
            }

            backButton4_.signal_clicked().connect(sigc::mem_fun(*this, &kineticMaker::equation));
            saveButton_.signal_clicked().connect(sigc::mem_fun(*this, &kineticMaker::save));
            exitButton2_.signal_clicked().connect(sigc::mem_fun(*this, &kineticMaker::exit));
        }
    }

    #if ASALI_USING_CANTERA == 1
    void kineticMaker::setChemistryInterface(ASALI::canteraInterface *chemistryInterface)
    {
        chemistryInterface_ = chemistryInterface;
    }
    #else
    void kineticMaker::setChemistryInterface(ASALI::asaliInterface *chemistryInterface)
    {
        chemistryInterface_ = chemistryInterface;
    }
    #endif

    void kineticMaker::species()
    {
        restart_ = true;
        this->remove();
        this->add(speciesBox_);
        this->resize(speciesBox_.get_width(), speciesBox_.get_height());
        this->show_all_children();
    }

    void kineticMaker::reactionNumber()
    {
        this->remove();
        this->add(reactionNumberBox_);
        this->resize(reactionNumberBox_.get_width(), reactionNumberBox_.get_height());
        this->show_all_children();
    }

    void kineticMaker::reaction()
    {
        if (this->checkSpecies())
        {
            if (restart_)
            {
                this->updateLayout();
            }
            this->remove();
            this->add(reactionBox_);
            this->resize(reactionBox_.get_width(), reactionBox_.get_height());
            this->show_all_children();
        }
    }

    void kineticMaker::equation()
    {
        if (this->checkReaction())
        {
            this->remove();
            this->add(equationBox_);
            this->resize(equationBox_.get_width(), equationBox_.get_height());
            this->show_all_children();
        }
    }

    void kineticMaker::recap()
    {
        if (this->checkEquation())
        {
            Rhom_.clear();
            Rhet_.clear();

            for (unsigned int i = 0; i < NR_; i++)
            {
                std::string r1 = Rtot_[i];

                //Replace mass fraction
                for (unsigned int j = 0; j < NC_; j++)
                {
                    std::size_t sp = r1.find(n_[j]);

                    if (sp != std::string::npos)
                    {
                        std::string r2 = r1.substr(sp, n_[j].length());

                        if (r2 == n_[j])
                        {
                            if (sp + n_[j].length() < r1.length())
                            {
                                if (r1.at(sp + n_[j].length()) == '*' ||
                                    r1.at(sp + n_[j].length()) == '/' ||
                                    r1.at(sp + n_[j].length()) == '(' ||
                                    r1.at(sp + n_[j].length()) == ')' ||
                                    r1.at(sp + n_[j].length()) == '+' ||
                                    r1.at(sp + n_[j].length()) == '-' ||
                                    r1.at(sp + n_[j].length()) == ',')
                                {
                                    r1.erase(sp, n_[j].length());
                                    std::ostringstream strs;
                                    strs << j;
                                    r1.insert(sp, "x[" + strs.str() + "]");
                                }
                                else if (sp + n_[j].length() + 2 <= r1.length() &&
                                         r1.at(sp + n_[j].length()) == 'e' &&
                                         r1.at(sp + n_[j].length() + 1) == 'x' &&
                                         r1.at(sp + n_[j].length() + 2) == 'p')
                                {
                                    r1.erase(sp, n_[j].length());
                                    std::ostringstream strs;
                                    strs << j;
                                    r1.insert(sp, "x[" + strs.str() + "]");
                                }
                                else if (sp + n_[j].length() + 2 <= r1.length() &&
                                         r1.at(sp + n_[j].length()) == 'p' &&
                                         r1.at(sp + n_[j].length() + 1) == 'o' &&
                                         r1.at(sp + n_[j].length() + 2) == 'w')
                                {
                                    r1.erase(sp, n_[j].length());
                                    std::ostringstream strs;
                                    strs << j;
                                    r1.insert(sp, "x[" + strs.str() + "]");
                                }
                            }
                            else if (sp + n_[j].length() == r1.length())
                            {
                                r1.erase(sp, n_[j].length());
                                std::ostringstream strs;
                                strs << j;
                                r1.insert(sp, "x[" + strs.str() + "]");
                            }
                        }
                    }
                }

                if (reactionCombo_[i]->get_active_row_number() == 0)
                {
                    Rhet_.push_back(r1);
                }
                else if (reactionCombo_[i]->get_active_row_number() == 1)
                {
                    Rhom_.push_back(r1);
                }
            }

            for (unsigned int i = 0; i < NC_; i++)
            {
                chemistryInterface_->convertToCaption(n_[i]);
                recapSpeciesVectorLabel_[i]->set_text(n_[i]);
            }

            r_.resize(NR_);
            t_.resize(NR_);
            for (unsigned int i = 0; i < NR_; i++)
            {
                std::string r = reactionEntry_[i]->get_text();
                std::string t = reactionCombo_[i]->get_active_text();

                chemistryInterface_->convertToCaption(r);
                chemistryInterface_->convertToCaption(Rtot_[i]);
                this->replaceString(Rtot_[i], "EXP", "exp");
                this->replaceString(Rtot_[i], "POW", "pow");

                r_[i] = r;
                t_[i] = t;
                recapReactionVectorLabel_[i]->set_text(r);
                recapEquationVectorLabel_[i]->set_text(Rtot_[i]);
                recapTypeVectorLabel_[i]->set_text(t);
            }

            this->remove();
            this->add(recapBox_);
            this->resize(recapBox_.get_width(), recapBox_.get_height());
            this->show_all_children();
        }
    }

    bool kineticMaker::checkSpecies()
    {
        std::vector<std::string> n(speciesEntry_.size());
        for (unsigned int i = 0; i < speciesEntry_.size(); i++)
        {
            n[i] = speciesEntry_[i]->get_text().c_str();
            n[i].erase(std::remove_if(n[i].begin(), n[i].end(), ::isspace), n[i].end());
        }

        n_.clear();
        for (unsigned int i = 0; i < speciesEntry_.size(); i++)
        {
            if (!n[i].empty())
            {
                n_.push_back(n[i]);
            }
        }

        NC_ = n_.size();

        if (n_.size() != 0)
        {
            //Check Species
            std::string ni = "We detect that ";
            unsigned int counter = 0;
            {
                std::vector<std::string> n = n_;
                std::vector<int> check = chemistryInterface_->checkNames(n);
                std::string ci;

                for (unsigned int i = 0; i < check.size(); i++)
                {
                    if (check[i] == 1)
                    {
                        ci = ci + n_[i] + " ";
                        counter++;
                    }
                }

                if (counter == 1)
                {
                    ni = ni + "this species " + ci + " is not implemented in ASALI database.";
                }
                else
                {
                    ni = ni + "these species\n" + ci + "\nare not implemented in ASALI database.";
                }

                ni = ni + "\nDo you wonna continue anyway?";
            }

            if (counter != 0)
            {
                Gtk::MessageDialog dialog(*this, ni, true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_YES_NO);
                dialog.set_secondary_text(this->getBeerShort(), true);
                int answer = dialog.run();

                //Handle the response:
                switch (answer)
                {
                case (Gtk::RESPONSE_YES):
                {
                    dialog.hide();
                    return true;
                    break;
                }
                case (Gtk::RESPONSE_NO):
                {
                    dialog.hide();
                    return false;
                    break;
                }
                default:
                {
                    dialog.hide();
                    return false;
                    break;
                }
                }
            }
            else
            {
                return true;
            }
        }
        else
        {
            Gtk::MessageDialog dialog(*this, "At least one species is required!", true, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_CLOSE);
            dialog.set_secondary_text(this->getBeerShort(), true);
            dialog.run();
            return false;
        }
    }

    bool kineticMaker::checkReaction()
    {
        bool check = false;
        shet_.clear();
        shom_.clear();
        for (unsigned int i = 0; i < NR_; i++)
        {
            if (!this->readStoichiometryCoefficient(i))
            {
                break;
            }
            else
            {
                equationLabel_[i]->set_text(reactionEntry_[i]->get_text());
            }

            if (i == (NR_ - 1))
            {
                check = true;
            }
        }
        return check;
    }

    bool kineticMaker::checkEquation()
    {
        bool check = true;
        Rtot_.clear();
        for (unsigned int i = 0; i < NR_; i++)
        {
            std::string all = equationEntry_[i]->get_text();
            all.erase(std::remove_if(all.begin(), all.end(), ::isspace), all.end());

            //Check exp
            {
                std::string error;
                {
                    std::ostringstream strs;
                    strs << i + 1;
                    error = "Error in exp function of reaction: " + strs.str();
                }

                std::size_t expPos = all.find("exp");
                bool expBool = false;
                while (expPos != std::string::npos)
                {
                    if (all.at(expPos + 3) == '(')
                    {
                        if (expPos != 0 &&
                            all.at(expPos - 1) != '*' &&
                            all.at(expPos - 1) != '/' &&
                            all.at(expPos - 1) != '-' &&
                            all.at(expPos - 1) != '+')
                        {
                            this->errorEquation(error);
                            i = NR_ - 1;
                            check = false;
                            break;
                        }
                        else
                        {
                            all.erase(expPos + 3, 1);
                            for (std::size_t j = expPos + 3; j < all.length(); j++)
                            {
                                if (all.at(j) == ')')
                                {
                                    all.erase(j, 1);
                                    expBool = true;
                                    break;
                                }
                            }

                            if (expBool)
                            {
                                all.erase(expPos, 3);
                                expPos = all.find("exp", expPos + 1);
                            }
                            else
                            {
                                this->errorEquation(error);
                                i = NR_ - 1;
                                check = false;
                                break;
                            }
                        }
                    }
                    else
                    {
                        this->errorEquation(error);
                        i = NR_ - 1;
                        check = false;
                        break;
                    }
                }
            }

            //Check pow
            {
                std::string error;
                {
                    std::ostringstream strs;
                    strs << i + 1;
                    error = "Error in pow function of reaction: " + strs.str();
                }

                std::size_t powPos = all.find("pow");
                std::size_t comaPos;
                bool powBool = false;
                while (powPos != std::string::npos)
                {
                    if (all.at(powPos + 3) == '(')
                    {
                        all.erase(powPos + 3, 1);
                        for (std::size_t j = powPos + 3; j < all.length(); j++)
                        {
                            if (all.at(j) == ',')
                            {
                                comaPos = j;
                                if (!std::isdigit(all.at(j + 1)))
                                {
                                    this->errorEquation(error);
                                    i = NR_ - 1;
                                    check = false;
                                    break;
                                }
                                else
                                {
                                    all.at(j) = '*';
                                    powBool = true;
                                    break;
                                }
                            }
                        }

                        if (powBool)
                        {
                            powBool = false;
                        }
                        else
                        {
                            this->errorEquation(error);
                            i = NR_ - 1;
                            check = false;
                            break;
                        }

                        for (std::size_t j = comaPos; j < all.length(); j++)
                        {
                            if (all.at(j) == ')')
                            {
                                all.erase(j, 1);
                                powBool = true;
                                break;
                            }
                        }

                        if (powBool)
                        {
                            all.erase(powPos, 3);
                            powPos = all.find("pow", powPos + 1);
                        }
                        else
                        {
                            this->errorEquation(error);
                            i = NR_ - 1;
                            check = false;
                            break;
                        }
                    }
                    else
                    {
                        this->errorEquation(error);
                        i = NR_ - 1;
                        check = false;
                        break;
                    }
                }
            }

            //Check species
            {
                std::string error;
                {
                    std::ostringstream strs;
                    strs << i + 1;
                    error = "Error in species names of reaction: " + strs.str();
                }

                for (unsigned int i = 0; i < op_.size(); i++)
                {
                    std::vector<std::string> allv = this->splitString(all, op_[i]);
                    all.clear();
                    for (unsigned int j = 0; j < allv.size(); j++)
                    {
                        all = all + " " + allv[j];
                    }
                }

                std::vector<std::string> allv;

                std::istringstream iss(all);
                while (iss >> all)
                {
                    allv.push_back(all);
                }

                std::vector<std::string> nv;
                for (unsigned int i = 0; i < allv.size(); i++)
                {
                    if (!std::isdigit(allv[i].at(0)))
                    {
                        nv.push_back(allv[i]);
                    }
                }

                std::vector<bool> cv(nv.size());
                for (unsigned int i = 0; i < nv.size(); i++)
                {
                    cv[i] = false;
                    if (nv[i] == "T")
                    {
                        cv[i] = true;
                    }
                    else
                    {
                        for (unsigned int j = 0; j < NC_; j++)
                        {
                            if (nv[i] == n_[j])
                            {
                                cv[i] = true;
                                break;
                            }
                        }
                    }
                }

                for (unsigned int i = 0; i < cv.size(); i++)
                {
                    if (!cv[i])
                    {
                        this->missingSpecies(nv[i]);
                        i = NR_ - 1;
                        check = false;
                        break;
                    }
                }
            }

            Rtot_.push_back(equationEntry_[i]->get_text());
        }

        return check;
    }

    void kineticMaker::updateLayout()
    {
        restart_ = false;
        if (NR_ != 0)
        {
            for (unsigned int i = 0; i < NR_; i++)
            {
                reactionGrid_.remove(*reactionLabel_[i]);
                reactionGrid_.remove(*reactionEntry_[i]);
                reactionGrid_.remove(*reactionCombo_[i]);
                equationGrid_.remove(*equationLabel_[i]);
                equationGrid_.remove(*equationEntry_[i]);
            }
        }

        NC_ = n_.size();
        NR_ = reactionNumberCombo_.get_active_row_number() + 1;

        reactionLabel_.clear();
        reactionCombo_.clear();
        reactionEntry_.clear();
        equationLabel_.clear();
        equationEntry_.clear();

        for (unsigned int i = 0; i < NR_; i++)
        {
            {
                std::ostringstream s;
                s << double(i + 1);
                reactionLabel_.push_back(new Gtk::Label(s.str() + ":"));
                equationLabel_.push_back(new Gtk::Label(s.str() + ":"));
            }

            reactionCombo_.push_back(new Gtk::ComboBoxText());
            reactionCombo_[i]->append("heterogeneous");
            reactionCombo_[i]->append("homogeneous");
            reactionCombo_[i]->set_active(0);

            reactionEntry_.push_back(new Gtk::Entry());
            equationEntry_.push_back(new Gtk::Entry());

            reactionGrid_.attach(*reactionLabel_[i], 0, i + 1, 1, 1);
            reactionGrid_.attach(*reactionEntry_[i], 1, i + 1, 1, 1);
            reactionGrid_.attach(*reactionCombo_[i], 2, i + 1, 1, 1);
            equationGrid_.attach(*equationLabel_[i], 0, i + 1, 1, 1);
            equationGrid_.attach(*equationEntry_[i], 1, i + 1, 2, 1);
        }

        {
            reactionGrid_.remove(backButton2_);
            reactionGrid_.remove(reactionHelpButton_);
            reactionGrid_.remove(nextButton3_);
            reactionGrid_.attach(backButton2_, 0, NR_ + 1, 1, 1);
            reactionGrid_.attach(reactionHelpButton_, 1, NR_ + 1, 1, 1);
            reactionGrid_.attach(nextButton3_, 2, NR_ + 1, 1, 1);
            equationGrid_.remove(backButton3_);
            equationGrid_.remove(equationHelpButton_);
            equationGrid_.remove(nextButton4_);
            equationGrid_.attach(backButton3_, 0, NR_ + 1, 1, 1);
            equationGrid_.attach(equationHelpButton_, 1, NR_ + 1, 1, 1);
            equationGrid_.attach(nextButton4_, 2, NR_ + 1, 1, 1);
        }

        //Add recap species
        {
            for (unsigned int i = 0; i < recapSpeciesVectorLabel_.size(); i++)
            {
                recapSpeciesGrid_.remove(*recapSpeciesVectorLabel_[i]);
            }

            recapSpeciesVectorLabel_.resize(NC_);
            unsigned int a = 0;
            unsigned int b = 0;
            for (unsigned int i = 0; i < NC_; i++)
            {
                recapSpeciesVectorLabel_[i] = new Gtk::Label("NONE");
                recapSpeciesGrid_.attach(*recapSpeciesVectorLabel_[i], a++, b, 1, 1);

                if ((i + 1) % 4 == 0)
                {
                    a = 0;
                    b++;
                }
            }
        }

        //Add recap reactions
        {
            for (unsigned int i = 0; i < recapReactionVectorLabel_.size(); i++)
            {
                recapReactionGrid_.remove(*recapReactionVectorLabel_[i]);
                recapReactionGrid_.remove(*recapEquationVectorLabel_[i]);
                recapReactionGrid_.remove(*recapTypeVectorLabel_[i]);

                if (i == 0)
                {
                    recapReactionGrid_.remove(backButton4_);
                    recapReactionGrid_.remove(saveButton_);
                    recapReactionGrid_.remove(exitButton2_);
                }
            }

            recapReactionVectorLabel_.resize(NR_);
            recapEquationVectorLabel_.resize(NR_);
            recapTypeVectorLabel_.resize(NR_);

            for (unsigned int i = 0; i < NR_; i++)
            {
                recapReactionVectorLabel_[i] = new Gtk::Label("NONE");
                recapEquationVectorLabel_[i] = new Gtk::Label("NONE");
                recapTypeVectorLabel_[i] = new Gtk::Label("NONE");
                recapReactionGrid_.attach(*recapReactionVectorLabel_[i], 0, i, 1, 1);
                recapReactionGrid_.attach(*recapEquationVectorLabel_[i], 1, i, 1, 1);
                recapReactionGrid_.attach(*recapTypeVectorLabel_[i], 2, i, 1, 1);
            }

            recapReactionGrid_.attach(backButton4_, 0, NR_, 1, 1);
            recapReactionGrid_.attach(saveButton_, 1, NR_, 1, 1);
            recapReactionGrid_.attach(exitButton2_, 2, NR_, 1, 1);
        }
    }

    bool kineticMaker::readStoichiometryCoefficient(unsigned int index)
    {
        std::string all = reactionEntry_[index]->get_text();
        all.erase(std::remove_if(all.begin(), all.end(), ::isspace), all.end());
        std::vector<double> st(NC_);
        if (!all.empty())
        {
            for (unsigned int k = 0; k < 2; k++)
            {
                std::vector<std::string> r = this->splitString(this->splitString(all, "=")[k], "+");
                for (unsigned int i = 0; i < r.size(); i++)
                {
                    std::vector<std::string> s = this->splitString(r[i], "*");
                    if (s.size() == 1 && !std::isdigit(s[0].at(0)))
                    {
                        int q = this->getSpecieIndex(s[0], n_);

                        if (q != -1)
                        {
                            if (k == 0)
                            {
                                st[q] = -1.;
                            }
                            else
                            {
                                st[q] = 1.;
                            }
                        }
                        else
                        {
                            this->missingSpecies(s[0]);
                            return false;
                        }
                    }
                    else if (s.size() == 1 && std::isdigit(s[0].at(0)))
                    {
                        this->missingSpecies(s[0]);
                        return false;
                    }
                    else if (s.size() == 2)
                    {
                        int q = this->getSpecieIndex(s[1], n_);

                        if (q != -1)
                        {
                            if (k == 0)
                            {
                                st[q] = -std::atof(s[0].c_str());
                            }
                            else
                            {
                                st[q] = std::atof(s[0].c_str());
                            }
                        }
                        else
                        {
                            this->missingSpecies(s[1]);
                            return false;
                        }
                    }
                    else
                    {
                        this->unknownOption(s[0]);
                        return false;
                    }
                }
            }

            if (reactionCombo_[index]->get_active_row_number() == 0)
            {
                shet_.push_back(st);
            }
            else if (reactionCombo_[index]->get_active_row_number() == 1)
            {
                shom_.push_back(st);
            }

            return true;
        }
        else
        {
            std::ostringstream s;
            s << double(index + 1);
            Gtk::MessageDialog dialog(*this, "Reaction number " + s.str() + " is empty!", true, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_CLOSE);
            dialog.set_secondary_text(this->getBeerShort(), true);
            dialog.run();
            return false;
        }
    }

    void kineticMaker::helpReaction()
    {
        Gtk::MessageDialog dialog(*this, "Example:\nH2+0.5*O2=H2O", true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_CLOSE);
        dialog.set_secondary_text(this->getBeerShort(), true);
        dialog.run();
    }

    void kineticMaker::helpEquation()
    {
        Gtk::MessageDialog dialog(*this, "Example:\n100.*pow(H2,2)*exp(-500/T)*O2\nH2 is the mole fraction\nT is temperature in [K]\nThe reaction rate unit dimensions are kmol/m3/s or kmol/m2/s", true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_CLOSE);
        dialog.set_secondary_text(this->getBeerShort(), true);
        dialog.run();
    }

    void kineticMaker::errorEquation(const std::string error)
    {
        Gtk::MessageDialog dialog(*this, error, true, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_CLOSE);
        dialog.set_secondary_text(this->getBeerShort(), true);
        dialog.run();
    }

    void kineticMaker::exit()
    {
        this->hide();
    }

    std::string kineticMaker::getBeer()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<const unsigned int> distribution(0, beer_.size()-1);
        int i = distribution(gen);
        return beer_[i];
    }

    std::string kineticMaker::getBeerShort()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<const unsigned int> distribution(0, beerShort_.size()-1);
        int i = distribution(gen);
        return beerShort_[i];
    }

    std::vector<std::string> kineticMaker::splitString(const std::string txt, std::string ch)
    {
        std::vector<std::string> strs;
        std::size_t pos = txt.find(ch);
        std::size_t initialPos = 0;

        strs.clear();

        while (pos != std::string::npos)
        {
            strs.push_back(txt.substr(initialPos, pos - initialPos));
            initialPos = pos + 1;

            pos = txt.find(ch, initialPos);
        }

        strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));

        return strs;
    }

    void kineticMaker::replaceString(std::string &str, const std::string from, const std::string to)
    {
        std::size_t pos = str.find(from);

        while (pos != std::string::npos)
        {
            str.replace(pos, from.length(), to);

            pos = str.find(from);
        }
    }

    int kineticMaker::getSpecieIndex(std::string n, std::vector<std::string> nv)
    {
        int q = -1;
        for (unsigned int i = 0; i < nv.size(); i++)
        {
            if (n == nv[i])
            {
                q = i;
                break;
            }
        }

        return q;
    }

    void kineticMaker::missingSpecies(const std::string n)
    {
        Gtk::MessageDialog dialog(*this, n + " is missing!!", true, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_CLOSE);
        dialog.set_secondary_text(this->getBeerShort(), true);
        dialog.run();
    }

    void kineticMaker::unknownOption(const std::string n)
    {
        Gtk::MessageDialog dialog(*this, n + " uknown option!!", true, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_CLOSE);
        dialog.set_secondary_text(this->getBeerShort(), true);
        dialog.run();
    }

    void kineticMaker::save()
    {
        std::string filename = this->save_file(this->get_toplevel()->gobj(), "kinetic.py");
        if (filename != "")
        {
            if (filename.substr(filename.length() - 3, filename.length()) != ".py")
            {
                filename = filename + ".py";
            }

            std::ofstream output;
            const char *path = filename.c_str();
            output.open(path, std::ios::out);

            for (unsigned int i = 0; i < NR_; i++)
            {
                output << "#\t" << r_[i] << "\tr=" << Rtot_[i] << "\t(" << t_[i] << ")" << std::endl;
            }
            output << std::endl;

            output << "from math import exp, pow" << std::endl;
            output << "class kinetic:" << std::endl;
            output << std::endl;
            output << "\tn = [";

            for (unsigned int i = 0; i < NC_ - 1; i++)
            {
                output << "\"" << n_[i] << "\",";
            }

            output << "\"" << n_.back() << "\"]" << std::endl;

            if (Rhet_.size() != 0)
            {
                output << std::endl;
                output << "\tshet = [";

                for (unsigned int i = 0; i < Rhet_.size(); i++)
                {
                    output << "[";
                    for (unsigned int j = 0; j < NC_ - 1; j++)
                    {
                        output << shet_[i][j] << ",";
                    }

                    if (i != (Rhet_.size() - 1))
                    {
                        output << shet_[i].back() << "],";
                    }
                    else
                    {
                        output << shet_[i].back() << "]";
                    }
                }

                output << "]" << std::endl;
            }

            if (Rhom_.size() != 0)
            {
                output << std::endl;
                output << "\tshom = [";

                for (unsigned int i = 0; i < Rhom_.size(); i++)
                {
                    output << "[";
                    for (unsigned int j = 0; j < NC_ - 1; j++)
                    {
                        output << shom_[i][j] << ",";
                    }

                    if (i != (Rhom_.size() - 1))
                    {
                        output << shom_[i].back() << "],";
                    }
                    else
                    {
                        output << shom_[i].back() << "]";
                    }
                }

                output << "]" << std::endl;
            }

            output << std::endl;
            output << "\tNhet = " << Rhet_.size() << std::endl;
            output << "\tNhom = " << Rhom_.size() << std::endl;

            output << std::endl;
            output << "\t#Unit dimensions: kmol/m2/s" << std::endl;
            output << "\tdef heterogeneous(self,T,x):" << std::endl;
            if (Rhet_.size() != 0)
            {
                output << "\t\tr = [";
                for (unsigned int i = 0; i < Rhet_.size() - 1; i++)
                {
                    output << Rhet_[i] << ",";
                }
                output << Rhet_.back() << "]" << std::endl;
            }
            output << "\t\tR = [0.]*" << NC_ << std::endl;
            if (Rhet_.size() != 0)
            {
                output << "\t\tfor i in range(0," << NC_ << "):" << std::endl;
                output << "\t\t\tfor j in range(0," << Rhet_.size() << "):" << std::endl;
                output << "\t\t\t\tR[i]=R[i]+self.shet[j][i]*r[j]" << std::endl;
            }
            output << "\t\treturn R" << std::endl;

            output << std::endl;
            output << "\t#Unit dimensions: kmol/m3/s" << std::endl;
            output << "\tdef homogeneous(self,T,x):" << std::endl;
            if (Rhom_.size() != 0)
            {
                output << "\t\tr = [";
                for (unsigned int i = 0; i < Rhom_.size() - 1; i++)
                {
                    output << Rhom_[i] << ",";
                }
                output << Rhom_.back() << "]" << std::endl;
            }
            output << "\t\tR = [0.]*" << NC_ << std::endl;
            if (Rhom_.size() != 0)
            {
                output << "\t\tfor i in range(0," << NC_ << "):" << std::endl;
                output << "\t\t\tfor j in range(0," << Rhom_.size() << "):" << std::endl;
                output << "\t\t\t\tR[i]=R[i]+self.shom[j][i]*r[j]" << std::endl;
            }
            output << "\t\treturn R" << std::endl;

            output << std::endl;
            output << "\t#Unit dimensions: kmol/m3/s" << std::endl;
            output << "\tdef allHomogeneous(self,T,x):" << std::endl;
            if (Rhom_.size() != 0)
            {
                output << "\t\tr = [";
                for (unsigned int i = 0; i < Rhom_.size() - 1; i++)
                {
                    output << Rhom_[i] << ",";
                }
                output << Rhom_.back() << "]" << std::endl;
            }
            output << "\t\tR = [0]*" << Rhom_.size() << "*" << NC_ << std::endl;
            output << "\t\tc = 0" << std::endl;
            if (Rhom_.size() != 0)
            {
                output << "\t\tfor i in range(0," << NC_ << "):" << std::endl;
                output << "\t\t\tfor j in range(0," << Rhom_.size() << "):" << std::endl;
                output << "\t\t\t\tR[c]=self.shom[j][i]*r[j]" << std::endl;
                output << "\t\t\t\tc = c + 1" << std::endl;
            }
            output << "\t\treturn R" << std::endl;

            output << std::endl;
            output << "\t#Unit dimensions: kmol/m2/s" << std::endl;
            output << "\tdef allHeterogeneous(self,T,x):" << std::endl;
            if (Rhet_.size() != 0)
            {
                output << "\t\tr = [";
                for (unsigned int i = 0; i < Rhet_.size() - 1; i++)
                {
                    output << Rhet_[i] << ",";
                }
                output << Rhet_.back() << "]" << std::endl;
            }
            output << "\t\tR = [0]*" << Rhet_.size() << "*" << NC_ << std::endl;
            output << "\t\tc = 0" << std::endl;
            if (Rhet_.size() != 0)
            {
                output << "\t\tfor i in range(0," << NC_ << "):" << std::endl;
                output << "\t\t\tfor j in range(0," << Rhet_.size() << "):" << std::endl;
                output << "\t\t\t\tR[c] = self.shet[j][i]*r[j]" << std::endl;
                output << "\t\t\t\tc = c + 1" << std::endl;
            }
            output << "\t\treturn R" << std::endl;

            output << std::endl;
            output << "\t#Unit dimensions: kmol/m3/s" << std::endl;
            output << "\tdef netHom(self,T,x):" << std::endl;
            if (Rhom_.size() != 0)
            {
                output << "\t\tr = [";
                for (unsigned int i = 0; i < Rhom_.size() - 1; i++)
                {
                    output << Rhom_[i] << ",";
                }
                output << Rhom_.back() << "]" << std::endl;
            }
            else
            {
                output << "\t\tr = [0]" << std::endl;
            }
            output << "\t\treturn r" << std::endl;

            output << std::endl;
            output << "\t#Unit dimensions: kmol/m2/s" << std::endl;
            output << "\tdef netHet(self,T,x):" << std::endl;
            if (Rhet_.size() != 0)
            {
                output << "\t\tr = [";
                for (unsigned int i = 0; i < Rhet_.size() - 1; i++)
                {
                    output << Rhet_[i] << ",";
                }
                output << Rhet_.back() << "]" << std::endl;
            }
            else
            {
                output << "\t\tr = [0]" << std::endl;
            }
            output << "\t\treturn r" << std::endl;

            output << std::endl;
            output << "\tdef name(self):" << std::endl;
            output << "\t\treturn self.n" << std::endl;

            output << std::endl;
            output << "\tdef NRhom(self):" << std::endl;
            output << "\t\treturn self.Nhom" << std::endl;

            output << std::endl;
            output << "\tdef NRhet(self):" << std::endl;
            output << "\t\treturn self.Nhet" << std::endl;

            output.close();
            this->savedMessage();
        }
    }

    void kineticMaker::savedMessage()
    {
        Gtk::MessageDialog dialog(*this, "Your kinetic scheme has been saved.\nThank you for using ASALI.", true, Gtk::MESSAGE_OTHER);
        dialog.set_secondary_text(this->getBeerShort(), true);
        dialog.run();
    }

    kineticMaker::~kineticMaker()
    {
    }
}
