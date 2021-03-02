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

#include "frontend/equilibriumCalculator.hpp"

namespace ASALI
{
    equilibriumCalculator::equilibriumCalculator(ASALI::speciesPopup            *speciesNames,
                                                 std::string                     kineticType)
    : transportProperties(speciesNames,kineticType),
      exitButton2_("Exit"),
      saveButton_("Save"),
      backButton_("Back"),
      initialStateLabel_("Initial state"),
      finalStateLabel_("Final state")
    {

        //Input
        {
            this->remove();
            this->set_border_width(15);
            this->set_title("ASALI: Equilibrium calculator");
            this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
            this->set_icon_from_file(this->relative_path_to_absolute_path("images/Icon.png"));
            this->input();
        }

        {
            resultsGrid_.set_column_homogeneous(true);
            resultsGrid_.set_column_spacing(10);
            resultsGrid_.set_row_homogeneous(true);
            resultsGrid_.set_row_spacing(10);
            
            resultsGrid_.attach(equilibriumCombo_,0,1,1,1);
            equilibriumCombo_.append("Constant Pressure-Temperature");
            equilibriumCombo_.append("Constant Pressure-Enthalpy");
            equilibriumCombo_.set_active(0);
            equilibriumCombo_.signal_changed().connect(sigc::mem_fun(*this,&equilibriumCalculator::results));
            
            resultsGrid_.attach(initialStateLabel_,1,0,1,1);
            
            resultsGrid_.attach(finalStateLabel_,2,0,1,1);

            resultsGrid_.attach(initialFractionCombo_,1,1,1,1);
            initialFractionCombo_.append("Mole fraction");
            initialFractionCombo_.append("Mass fraction");
            initialFractionCombo_.set_active(0);
            initialFractionCombo_.signal_changed().connect(sigc::mem_fun(*this,&equilibriumCalculator::initialFractionUnitConversion));

            resultsGrid_.attach(finalFractionCombo_,2,1,1,1);
            finalFractionCombo_.append("Mole fraction");
            finalFractionCombo_.append("Mass fraction");
            finalFractionCombo_.set_active(0);
            finalFractionCombo_.signal_changed().connect(sigc::mem_fun(*this,&equilibriumCalculator::finalFractionUnitConversion));


            //Add back button
            resultsGrid_.attach(backButton_,0,n_.size()+3,1,1);
            backButton_.signal_clicked().connect(sigc::mem_fun(*this,&equilibriumCalculator::input));
            
            //Add print on file
            resultsGrid_.attach(saveButton_,1,n_.size()+3,1,1);
            saveButton_.signal_clicked().connect(sigc::mem_fun(*this,&equilibriumCalculator::save));

            //Add exit button
            resultsGrid_.attach(exitButton2_,2,n_.size()+3,1,1);
            exitButton2_.signal_clicked().connect(sigc::mem_fun(*this,&equilibriumCalculator::exit));
        }
        
    }

    equilibriumCalculator::~equilibriumCalculator()
    {
    }

    void equilibriumCalculator::clean()
    {
        resultsGrid_.remove(backButton_);
        resultsGrid_.remove(saveButton_);
        resultsGrid_.remove(exitButton2_);
    }

    void equilibriumCalculator::showAtomNames()
    {
        if ( nameVector_.size() != 0)
        {
            for (unsigned int i=0;i<nameVector_.size();i++)
            {
                resultsGrid_.remove(*nameVector_[i]);
            }
        }

        nameVector_.clear();
        nameVector_.resize(n_.size()+1);

        for (unsigned int i=0;i<n_.size();i++)
        { 
            nameVector_[i] = new Gtk::Label(n_[i]);
            resultsGrid_.attach(*nameVector_[i],0,i+2,1,1);
        }
        
        nameVector_[n_.size()] = new Gtk::Label("Temperature [K]");
        resultsGrid_.attach(*nameVector_[n_.size()],0,n_.size()+2,1,1);
    }

    void equilibriumCalculator::results()
    {
        this->inputReader();

        if ( checkInput_.second == false )
        {
            this->checkInput(checkInput_.first);
        }
        else
        {
            this->clean();
            chemistryInterface_->setTemperature(T_);
            chemistryInterface_->setPressure(p_);
            if ( fractionCombo_.get_active_row_number() == 0 )
            {
                chemistryInterface_->setMoleFraction(x_,n_);
            }
            else if ( fractionCombo_.get_active_row_number() == 1 )
            {
                chemistryInterface_->setMassFraction(x_,n_);
            }

            x_.clear();
            y_.clear();
            x_.resize(n_.size());
            y_.resize(n_.size());
            {
                std::vector<double> x = chemistryInterface_->mole();
                std::vector<double> y = chemistryInterface_->mass();
                
                for (unsigned int i=0;i<n_.size();i++)
                {
                    for (unsigned int j=0;j<chemistryInterface_->numberOfGasSpecies();j++)
                    {
                        if ( n_[i] == chemistryInterface_->names()[j] )
                        {
                            x_[i] = x[j];
                            y_[i] = y[j];
                            break;
                        }
                    }
                }
            }

            if ( equilibriumCombo_.get_active_row_number() == 0 )
            {
                chemistryInterface_->equilibriumCalculate("TP");
            }
            else if ( equilibriumCombo_.get_active_row_number() == 1 )
            {
                chemistryInterface_->equilibriumCalculate("HP");
            }

            xeq_.clear();
            yeq_.clear();
            xeq_.resize(n_.size());
            yeq_.resize(n_.size());
            {
                std::vector<double> x = chemistryInterface_->mole();
                std::vector<double> y = chemistryInterface_->mass();
                
                for (unsigned int i=0;i<n_.size();i++)
                {
                    for (unsigned int j=0;j<chemistryInterface_->numberOfGasSpecies();j++)
                    {
                        if ( n_[i] == chemistryInterface_->names()[j] )
                        {
                            xeq_[i] = x[j];
                            yeq_[i] = y[j];
                            break;
                        }
                    }
                }
            }

            Teq_ = chemistryInterface_->getTemperature();

            {
                resultsGrid_.attach(backButton_,0,n_.size()+3,1,1);
                resultsGrid_.attach(saveButton_,1,n_.size()+3,1,1);
                resultsGrid_.attach(exitButton2_,2,n_.size()+3,1,1);
            }

            this->remove();
            this->add(resultsGrid_);
            this->showAtomNames();
            this->initialFractionUnitConversion();
            this->finalFractionUnitConversion();
            this->resize(resultsGrid_.get_width(),resultsGrid_.get_height());
            this->show_all_children();
        }
    }

    void equilibriumCalculator::finalFractionUnitConversion()
    {
        if ( finalFractionVector_.size() != 0 )
        {
            for (unsigned int i=0;i<finalFractionVector_.size();i++)
            {
                resultsGrid_.remove(*finalFractionVector_[i]);
            }
        }
        
        finalFractionVector_.clear();
        finalFractionVector_.resize(n_.size()+1);

        if ( finalFractionCombo_.get_active_row_number() == 0 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                std::stringstream mole;
                mole << std::scientific << std::setprecision(OP_) << xeq_[i];
                finalFractionVector_[i] = new Gtk::Label(mole.str());
                resultsGrid_.attach(*finalFractionVector_[i],2,i+2,1,1);
            }
        }
        else if ( finalFractionCombo_.get_active_row_number() == 1 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                std::stringstream mass;
                mass << std::scientific << std::setprecision(OP_) << yeq_[i];
                finalFractionVector_[i] = new Gtk::Label(mass.str());
                resultsGrid_.attach(*finalFractionVector_[i],2,i+2,1,1);
            }
        }

        std::stringstream T;
        T << std::scientific << std::setprecision(OP_) << Teq_;
        finalFractionVector_[n_.size()] = new Gtk::Label(T.str());
        resultsGrid_.attach(*finalFractionVector_[n_.size()],2,n_.size()+2,1,1);
        
        this->show_all_children();
    }

    void equilibriumCalculator::initialFractionUnitConversion()
    {
        if ( initialFractionVector_.size() != 0 )
        {
            for (unsigned int i=0;i<initialFractionVector_.size();i++)
            {
                resultsGrid_.remove(*initialFractionVector_[i]);
            }
        }
        
        initialFractionVector_.clear();
        initialFractionVector_.resize(n_.size()+1);

        if ( initialFractionCombo_.get_active_row_number() == 0 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                std::stringstream mole;
                mole << std::scientific << std::setprecision(OP_) << x_[i];
                initialFractionVector_[i] = new Gtk::Label(mole.str());
                resultsGrid_.attach(*initialFractionVector_[i],1,i+2,1,1);
            }
        }
        else if ( initialFractionCombo_.get_active_row_number() == 1 )
        {
            for (unsigned int i=0;i<n_.size();i++)
            {
                std::stringstream mass;
                mass << std::scientific << std::setprecision(OP_) << y_[i];
                initialFractionVector_[i] = new Gtk::Label(mass.str());
                resultsGrid_.attach(*initialFractionVector_[i],1,i+2,1,1);
            }
        }
        
        std::stringstream T;
        T << std::scientific << std::setprecision(OP_) << T_;
        initialFractionVector_[n_.size()] = new Gtk::Label(T.str());
        resultsGrid_.attach(*initialFractionVector_[n_.size()] ,1,n_.size()+2,1,1);

        this->show_all_children();
    }

    void equilibriumCalculator::save()
    {
        std::string filename = this->save_file(this->get_toplevel()->gobj(), "equilibrium.asali");
        if ( filename != "" )
        {
            std::ofstream output;
            const char *path = filename.c_str();
            output.open(path,std::ios::out);
            
            output << "Pressure:        " << p_ << " Pa" << std::endl;
            output << std::endl;
            output.setf(std::ios::scientific);
            output.precision(6);

            output << "Mole fraction" << std::endl;
            output << "Species\tInitial\tEquilibrium" << std::endl;
            for (unsigned int i=0;i<n_.size();i++)
            {
                output << n_[i] << "\t" << x_[i] << "\t" << xeq_[i] << std::endl;
            }
            output << "Temperature[K]" << "\t" << T_ << "\t" << Teq_ << std::endl;
            output << std::endl;
            output << "Mass fraction" << std::endl;
            output << "Species\tInitial\tEquilibrium" << std::endl;
            for (unsigned int i=0;i<n_.size();i++)
            {
                output << n_[i] << "\t" << y_[i] << "\t" << yeq_[i] << std::endl;
            }
            output << "Temperature[K]" << "\t" << T_ << "\t" << Teq_ << std::endl;
            output.close();
            this->savedMessage();
        }
    }
}
