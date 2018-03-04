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
#   Department of Energy                                                                       #
#   Politecnico di Milano                                                                      #
#   Author: Stefano Rebughini <stefano.rebughini@polimi.it>                                    #
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

#include "BatchFunctions.H"
#include "Ph1DFunctions.H"

void Asali::kineticReader()
{
    if ( kineticType_ == "none" )
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

        canteraIndex_.resize(n_.size());
        for (unsigned int i=0;i<n_.size();i++)
        {
            canteraIndex_[i] = 0;
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
    else
    {
        if ( kineticTypeCombo_.get_active_text() == "ASALI" )
        {
            index1_.clear();
            index2_.clear();

            for (unsigned int i=0;i<asaliKinetic_->get_NR();i++)
            {
                for (unsigned int j=0;j<4;j++)
                {
                    std::string name = asaliKinetic_->get_name()[i][j];
                    canteraInterface_->convertToCaption(name);
                    if ( name != "NONE" )
                    {
                        bool test = false;
                        for (unsigned int k=0;k<n_.size();k++)
                        {
                            if ( i == 0)
                            {
                                canteraInterface_->convertToCaption(n_[k]);
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

            canteraIndex_.resize(n_.size());
            for (unsigned int i=0;i<n_.size();i++)
            {
                canteraIndex_[i] = thermo_->speciesIndex(n_[i]);
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
}

void Asali::kineticShow()
{
    asaliKinetic_->show();
}

void Asali::propertiesShow()
{
    if ( kineticType_ == "none" )
    {
        if ( reactorsTypeCombo_.get_active_row_number() == 3 )
        {
            asaliProperties_->destroy();
            asaliProperties_->set_type("batch");
            asaliProperties_->set_energy(energy_);
            asaliProperties_->set_n(n_);
            asaliProperties_->set_reactions(asaliKinetic_->get_name(),asaliKinetic_->get_stoich());
            asaliProperties_->build();
            asaliProperties_->show();
        }
        else if ( reactorsTypeCombo_.get_active_row_number() == 0 )
        {
            asaliProperties_->destroy();
            asaliProperties_->set_type("ph1d");
            asaliProperties_->set_energy(energy_);
            asaliProperties_->set_n(n_);
            asaliProperties_->set_reactions(asaliKinetic_->get_name(),asaliKinetic_->get_stoich());
            asaliProperties_->build();
            asaliProperties_->show();
        }
    }
}

void Asali::reactorsInput(const bool back)
{
    if ( kineticType_ == "default" && kineticTypeCombo_.get_active_row_number() == 0 )
    {
        Gtk::MessageDialog dialog(*this,"No kinetic scheme implemented in database/data.xml,\nplease select ASALI kinetic type.",true,Gtk::MESSAGE_WARNING);
        dialog.set_secondary_text(this->getBeer(),true);
        dialog.run();
    }
    else if ( kineticType_ == "none" && kineticTypeCombo_.get_active_row_number() == 0 )
    {
        Gtk::MessageDialog dialog(*this,"No kinetic scheme implemented, please, select ASALI kinetic type.",true,Gtk::MESSAGE_WARNING);
        dialog.set_secondary_text(this->getBeer(),true);
        dialog.run();
    }
    else
    {

        if ( kineticTypeCombo_.get_active_row_number() == 1 && back == false)
        {
            asaliKinetic_->show();
        }

        if ( reactorsTypeCombo_.get_active_row_number() == 3 )
        { 
            this->remove();
            this->set_title("ASALI: Batch reactors");
            this->add(batchMainBox_);
            this->resize(batchMainBox_.get_width(),batchMainBox_.get_height());
            this->show_all_children();
        }
        else if ( reactorsTypeCombo_.get_active_row_number() == 0 )
        {
            this->remove();
            this->set_title("ASALI: 1D PH reactors");
            this->add(ph1dMainBox_);
            this->resize(ph1dMainBox_.get_width(),ph1dMainBox_.get_height());
            this->show_all_children();
        }
        else
        {
            Gtk::MessageDialog dialog(*this,"Ops! This reactor type will be implemented soon.",true,Gtk::MESSAGE_WARNING);
            dialog.set_secondary_text(this->getBeer(),true);
            dialog.run();
        }
    }
}

void Asali::reactorKineticMenu()
{
    //Clean the window
    this->remove();
    this->set_title("ASALI: Catalytic reactors");

    //Add menu box
    this->add(reactorsGrid_);

    //Resize
    this->resize(reactorsGrid_.get_width(),reactorsGrid_.get_height());

    this->show_all_children();
}
