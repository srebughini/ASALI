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

#include "asaliProperties.hpp"

namespace ASALI
{
    asaliProperties::asaliProperties()
    : batchLogo_("images/BatchLogo.png"),
      ph1dLogo_("images/Ph1DLogo.png"),
      het1dLogo_("images/Het1DLogo.png"),
      pelletLogo_("images/PelletLogo.png"),
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
        #include "shared/Beer.H"

        this->set_border_width(15);
        this->set_title("ASALI: properties input");
        this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
        this->set_icon_from_file("images/Icon.png");

        //Add background grid
        mainBox_.set_halign(Gtk::ALIGN_START);
        mainBox_.set_spacing(10);
        this->add(mainBox_);

        small.resize(26);    big.resize(26);
        small[0]  = "a";    big[0]  = "A";
        small[1]  = "b";    big[1]  = "B";
        small[2]  = "c";    big[2]  = "C";
        small[3]  = "d";    big[3]  = "D";
        small[4]  = "e";    big[4]  = "E";
        small[5]  = "f";    big[5]  = "F";
        small[6]  = "g";    big[6]  = "G";
        small[7]  = "h";    big[7]  = "H";
        small[8]  = "i";    big[8]  = "I";
        small[9]  = "j";    big[9]  = "J";
        small[10] = "k";    big[10] = "K";
        small[11] = "l";    big[11] = "L";
        small[12] = "m";    big[12] = "M";
        small[13] = "n";    big[13] = "N";
        small[14] = "o";    big[14] = "O";
        small[15] = "p";    big[15] = "P";
        small[16] = "q";    big[16] = "Q";
        small[17] = "r";    big[17] = "R";
        small[18] = "s";    big[18] = "S";
        small[19] = "t";    big[19] = "T";
        small[20] = "u";    big[20] = "U";
        small[21] = "v";    big[21] = "V";
        small[22] = "w";    big[22] = "W";
        small[23] = "x";    big[23] = "X";
        small[24] = "y";    big[24] = "Y";
        small[25] = "z";    big[25] = "Z";

        {
            mainGrid_.set_row_spacing(10);
            mainGrid_.set_column_spacing(10);

            heatBox_.set_halign(Gtk::ALIGN_CENTER);
            heatBox_.set_spacing(10);

            diffBox_.set_halign(Gtk::ALIGN_CENTER);
            diffBox_.set_spacing(10);

            heatCombo_.append("J/kmol");
            heatCombo_.append("J/mol");
            heatCombo_.append("kJ/mol");
            heatCombo_.append("cal/kmol");
            heatCombo_.append("cal/mol");
            heatCombo_.append("kcal/mol");
            heatCombo_.set_active(0);

            cpCombo_.append("J/kg/K");
            cpCombo_.append("kJ/kg/K");
            cpCombo_.set_active(0);

            condCombo_.append("W/m/K");
            condCombo_.append("kW/m/K");
            condCombo_.set_active(0);

            diffCombo_.append("m\u00b2/s");
            diffCombo_.append("cm\u00b2/s");
            diffCombo_.set_active(0);

            muCombo_.append("cP");
            muCombo_.append("P");
            muCombo_.append("Pas");
            muCombo_.set_active(2);

            cpGrid_.set_row_spacing(10);
            cpGrid_.set_column_spacing(10);

            condGrid_.set_row_spacing(10);
            condGrid_.set_column_spacing(10);
            
            cpEntry_.set_text("1");
            condEntry_.set_text("1");
            muEntry_.set_text("1e-05");
        }

    }
    
    void asaliProperties::set_energy(const std::string energy)
    {
        energy_ = energy;
    }
    
    void asaliProperties::set_type(const std::string type)
    {
        type_ = type;
    }
    
    void asaliProperties::set_n(const std::vector<std::string> n)
    {
        n_  = n;
        NC_ = n.size();

        speciesNameLabel_.clear();
        speciesMwEntry_.clear();
        speciesNameLabel_.resize(NC_);
        speciesMwEntry_.resize(NC_);
        speciesDiffEntry_.resize(NC_);
    }

    void asaliProperties::set_reactions(const unsigned int Nhom, const unsigned int Nhet)
    {
        Nhom_ = Nhom;
        Nhet_ = Nhet;
    }

    void asaliProperties::destroy()
    {
        if ( type_ == "batch")
        {
            if ( energy_ == "on" )
            {
                cpGrid_.remove(cpLabel_);
                cpGrid_.remove(cpCombo_);
                mainGrid_.remove(cpGrid_);
                mainGrid_.remove(cpEntry_);
                mainGrid_.remove(reactionLabel_);
                heatBox_.remove(heatCombo_);
                heatBox_.remove(heatLabel_);
                mainGrid_.remove(heatBox_);
                
                for (unsigned int i=0;i<reactionNumberLabel_.size();i++)
                {
                    mainGrid_.remove(*reactionNumberLabel_[i]);
                    mainGrid_.remove(*speciesHeatEntry_[i]);
                }
                
                reactionNumberLabel_.clear();
                speciesHeatEntry_.clear();
            }

            mainGrid_.remove(nameLabel_);
            mainGrid_.remove(mwLabel_);
            
            for (unsigned int i=0;i<speciesNameLabel_.size();i++)
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
        else if ( type_ == "ph1d" )
        {
            if ( energy_ == "on" )
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

                for (unsigned int i=0;i<reactionNumberLabel_.size();i++)
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

            for (unsigned int i=0;i<speciesNameLabel_.size();i++)
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
        else if ( type_ == "het1d" )
        {
            if ( energy_ == "on" )
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

                for (unsigned int i=0;i<reactionNumberLabel_.size();i++)
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

            for (unsigned int i=0;i<speciesNameLabel_.size();i++)
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
        else if ( type_ == "pellet" )
        {
            mainGrid_.remove(nameLabel_);
            mainGrid_.remove(mwLabel_);
            mainGrid_.remove(diffBox_);
            diffBox_.remove(diffLabel_);
            diffBox_.remove(diffCombo_);

            for (unsigned int i=0;i<speciesNameLabel_.size();i++)
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

    void asaliProperties::build()
    {
        NR_ = 0;
        if ( type_ == "batch" )
        {
            mainGrid_.set_column_homogeneous(true);
            mainBox_.pack_start(batchLogo_, Gtk::PACK_SHRINK);
            mainBox_.pack_start(mainGrid_, Gtk::PACK_SHRINK);

            mainGrid_.attach(nameLabel_,0,0,1,1);
            mainGrid_.attach(mwLabel_,1,0,1,1);

            for (unsigned int i=0;i<NC_;i++)
            {
                speciesNameLabel_[i] = new Gtk::Label(n_[i]);
                mainGrid_.attach(*speciesNameLabel_[i],0,1+i,1,1);
                speciesMwEntry_[i] = new Gtk::Entry();
                mainGrid_.attach(*speciesMwEntry_[i],1,1+i,1,1);
                
                if ( MW_.size() != 0 )
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
            
            if ( energy_ == "on" )
            {
                mainGrid_.attach(cpGrid_,0,NC_+1,1,1);
                cpGrid_.attach(cpLabel_,0,0,1,1);
                cpGrid_.attach(cpCombo_,1,0,1,1);
                
                mainGrid_.attach(cpEntry_,1,NC_+1,1,1);

                mainGrid_.attach(reactionLabel_,0,NC_+2,1,1);
                mainGrid_.attach(heatBox_,1,NC_+2,1,1);
                heatBox_.pack_start(heatLabel_, Gtk::PACK_SHRINK);
                heatBox_.pack_start(heatCombo_, Gtk::PACK_SHRINK);


                NR_ = Nhom_ + Nhet_;
                reactionNumberLabel_.clear();
                speciesHeatEntry_.clear();
                reactionNumberLabel_.resize(NR_);
                speciesHeatEntry_.resize(NR_);
                
                for (unsigned int i=0;i<Nhom_;i++)
                {
                    std::string reaction;
                    {
                        std::ostringstream s;
                        s << double(i+1);
                        reaction = s.str() + " (homogeneous)";
                    }
                    reactionNumberLabel_[i] = new Gtk::Label(reaction);
                    mainGrid_.attach(*reactionNumberLabel_[i],0,NC_+3+i,1,1);
                    speciesHeatEntry_[i] = new Gtk::Entry();    
                    mainGrid_.attach(*speciesHeatEntry_[i],1,NC_+3+i,1,1);
                    speciesHeatEntry_[i]->set_text("1");
                }

                for (unsigned int i=Nhom_;i<NR_;i++)
                {
                    std::string reaction;
                    {
                        std::ostringstream s;
                        s << double(i+1-Nhom_);
                        reaction = s.str() + " (heterogeneous)";
                    }
                    reactionNumberLabel_[i] = new Gtk::Label(reaction);
                    mainGrid_.attach(*reactionNumberLabel_[i],0,NC_+3+i,1,1);
                    speciesHeatEntry_[i] = new Gtk::Entry();    
                    mainGrid_.attach(*speciesHeatEntry_[i],1,NC_+3+i,1,1);
                    speciesHeatEntry_[i]->set_text("1");
                }
            }
            else
            {
                NR_ = 0;
            }
            mainBox_.pack_end(doneButton_,Gtk::PACK_SHRINK);
            doneButton_.signal_clicked().connect(sigc::mem_fun(*this,&asaliProperties::doneInput));
        }
        else if ( type_ == "ph1d" )
        {
            mainGrid_.set_column_homogeneous(false);
            mainBox_.pack_start(ph1dLogo_, Gtk::PACK_SHRINK);
            mainBox_.pack_start(mainGrid_, Gtk::PACK_SHRINK);

            mainGrid_.attach(nameLabel_,0,0,1,1);
            mainGrid_.attach(mwLabel_,1,0,1,1);
            mainGrid_.attach(diffBox_,2,0,1,1);
            diffBox_.pack_start(diffLabel_, Gtk::PACK_SHRINK);
            diffBox_.pack_start(diffCombo_, Gtk::PACK_SHRINK);

            for (unsigned int i=0;i<NC_;i++)
            {
                speciesNameLabel_[i] = new Gtk::Label(n_[i]);
                mainGrid_.attach(*speciesNameLabel_[i],0,1+i,1,1);
                speciesMwEntry_[i] = new Gtk::Entry();
                mainGrid_.attach(*speciesMwEntry_[i],1,1+i,1,1);
                
                if ( MW_.size() != 0 )
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
                mainGrid_.attach(*speciesDiffEntry_[i],2,1+i,1,1);
                
                if ( diff_.size() != 0 )
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

            if ( energy_ == "on" )
            {
                mainGrid_.attach(cpLabel_,0,NC_+1,1,1);
                mainGrid_.attach(cpEntry_,1,NC_+1,1,1);
                mainGrid_.attach(cpCombo_,2,NC_+1,1,1);

                mainGrid_.attach(condLabel_,0,NC_+2,1,1);
                mainGrid_.attach(condEntry_,1,NC_+2,1,1);
                mainGrid_.attach(condCombo_,2,NC_+2,1,1);

                mainGrid_.attach(reactionLabel_,0,NC_+3,1,1);
                mainGrid_.attach(heatBox_,1,NC_+3,1,1);
                heatBox_.pack_start(heatLabel_, Gtk::PACK_SHRINK);
                heatBox_.pack_start(heatCombo_, Gtk::PACK_SHRINK);

                NR_ = Nhom_ + Nhet_;
                reactionNumberLabel_.clear();
                speciesHeatEntry_.clear();
                reactionNumberLabel_.resize(NR_);
                speciesHeatEntry_.resize(NR_);
                
                for (unsigned int i=0;i<Nhom_;i++)
                {
                    std::string reaction;
                    {
                        std::ostringstream s;
                        s << double(i+1);
                        reaction = s.str() + " (homogeneous)";
                    }
                    reactionNumberLabel_[i] = new Gtk::Label(reaction);
                    mainGrid_.attach(*reactionNumberLabel_[i],0,NC_+3+i,1,1);
                    speciesHeatEntry_[i] = new Gtk::Entry();    
                    mainGrid_.attach(*speciesHeatEntry_[i],1,NC_+3+i,1,1);
                    speciesHeatEntry_[i]->set_text("1");
                }
                
                for (unsigned int i=Nhom_;i<NR_;i++)
                {
                    std::string reaction;
                    {
                        std::ostringstream s;
                        s << double(i+1-Nhom_);
                        reaction = s.str() + " (heterogeneous)";
                    }
                    reactionNumberLabel_[i] = new Gtk::Label(reaction);
                    mainGrid_.attach(*reactionNumberLabel_[i],0,NC_+3+i,1,1);
                    speciesHeatEntry_[i] = new Gtk::Entry();    
                    mainGrid_.attach(*speciesHeatEntry_[i],1,NC_+3+i,1,1);
                    speciesHeatEntry_[i]->set_text("1");
                }
            }
            else
            {
                NR_ = 0;
            }
            mainBox_.pack_end(doneButton_,Gtk::PACK_SHRINK);
            doneButton_.signal_clicked().connect(sigc::mem_fun(*this,&asaliProperties::doneInput));
        }
        else if ( type_ == "het1d" )
        {
            mainGrid_.set_column_homogeneous(false);
            mainBox_.pack_start(het1dLogo_, Gtk::PACK_SHRINK);
            mainBox_.pack_start(mainGrid_, Gtk::PACK_SHRINK);

            mainGrid_.attach(nameLabel_,0,0,1,1);
            mainGrid_.attach(mwLabel_,1,0,1,1);
            mainGrid_.attach(diffBox_,2,0,1,1);
            diffBox_.pack_start(diffLabel_, Gtk::PACK_SHRINK);
            diffBox_.pack_start(diffCombo_, Gtk::PACK_SHRINK);

            for (unsigned int i=0;i<NC_;i++)
            {
                speciesNameLabel_[i] = new Gtk::Label(n_[i]);
                mainGrid_.attach(*speciesNameLabel_[i],0,1+i,1,1);
                speciesMwEntry_[i] = new Gtk::Entry();
                mainGrid_.attach(*speciesMwEntry_[i],1,1+i,1,1);
                
                if ( MW_.size() != 0 )
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
                mainGrid_.attach(*speciesDiffEntry_[i],2,1+i,1,1);
                
                if ( diff_.size() != 0 )
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

            mainGrid_.attach(muLabel_,0,NC_+1,1,1);
            mainGrid_.attach(muEntry_,1,NC_+1,1,1);
            mainGrid_.attach(muCombo_,2,NC_+1,1,1);

            if ( energy_ == "on" )
            {
                mainGrid_.attach(cpLabel_,0,NC_+2,1,1);
                mainGrid_.attach(cpEntry_,1,NC_+2,1,1);
                mainGrid_.attach(cpCombo_,2,NC_+2,1,1);

                mainGrid_.attach(condLabel_,0,NC_+3,1,1);
                mainGrid_.attach(condEntry_,1,NC_+3,1,1);
                mainGrid_.attach(condCombo_,2,NC_+3,1,1);

                mainGrid_.attach(reactionLabel_,0,NC_+4,1,1);
                mainGrid_.attach(heatBox_,1,NC_+4,1,1);
                heatBox_.pack_start(heatLabel_, Gtk::PACK_SHRINK);
                heatBox_.pack_start(heatCombo_, Gtk::PACK_SHRINK);

                NR_ = Nhom_ + Nhet_;
                reactionNumberLabel_.clear();
                speciesHeatEntry_.clear();
                reactionNumberLabel_.resize(NR_);
                speciesHeatEntry_.resize(NR_);
                
                for (unsigned int i=0;i<Nhom_;i++)
                {
                    std::string reaction;
                    {
                        std::ostringstream s;
                        s << double(i+1);
                        reaction = s.str() + " (homogeneous)";
                    }
                    reactionNumberLabel_[i] = new Gtk::Label(reaction);
                    mainGrid_.attach(*reactionNumberLabel_[i],0,NC_+3+i,1,1);
                    speciesHeatEntry_[i] = new Gtk::Entry();
                    mainGrid_.attach(*speciesHeatEntry_[i],1,NC_+3+i,1,1);
                    speciesHeatEntry_[i]->set_text("1");
                }
                
                for (unsigned int i=Nhom_;i<NR_;i++)
                {
                    std::string reaction;
                    {
                        std::ostringstream s;
                        s << double(i+1-Nhom_);
                        reaction = s.str() + " (heterogeneous)";
                    }
                    reactionNumberLabel_[i] = new Gtk::Label(reaction);
                    mainGrid_.attach(*reactionNumberLabel_[i],0,NC_+3+i,1,1);
                    speciesHeatEntry_[i] = new Gtk::Entry();    
                    mainGrid_.attach(*speciesHeatEntry_[i],1,NC_+3+i,1,1);
                    speciesHeatEntry_[i]->set_text("1");
                }
            }
            mainBox_.pack_end(doneButton_,Gtk::PACK_SHRINK);
            doneButton_.signal_clicked().connect(sigc::mem_fun(*this,&asaliProperties::doneInput));
        }
        else if ( type_ == "pellet" )
        {
            mainGrid_.set_column_homogeneous(false);
            mainBox_.pack_start(pelletLogo_, Gtk::PACK_SHRINK);
            mainBox_.pack_start(mainGrid_, Gtk::PACK_SHRINK);

            mainGrid_.attach(nameLabel_,0,0,1,1);
            mainGrid_.attach(mwLabel_,1,0,1,1);
            mainGrid_.attach(diffBox_,2,0,1,1);
            diffBox_.pack_start(diffLabel_, Gtk::PACK_SHRINK);
            diffBox_.pack_start(diffCombo_, Gtk::PACK_SHRINK);

            for (unsigned int i=0;i<NC_;i++)
            {
                speciesNameLabel_[i] = new Gtk::Label(n_[i]);
                mainGrid_.attach(*speciesNameLabel_[i],0,1+i,1,1);
                speciesMwEntry_[i] = new Gtk::Entry();
                mainGrid_.attach(*speciesMwEntry_[i],1,1+i,1,1);
                
                if ( MW_.size() != 0 )
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
                mainGrid_.attach(*speciesDiffEntry_[i],2,1+i,1,1);
                
                if ( diff_.size() != 0 )
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

            mainBox_.pack_end(doneButton_,Gtk::PACK_SHRINK);
            doneButton_.signal_clicked().connect(sigc::mem_fun(*this,&asaliProperties::doneInput));
        }

        this->resize(mainBox_.get_width(),mainBox_.get_height ());
        this->show_all_children();
    }

    void asaliProperties::savedMessage()
    {
        Gtk::MessageDialog dialog(*this,"Your file has been saved.\nThank you for using ASALI.",true,Gtk::MESSAGE_OTHER);
        dialog.set_secondary_text(this->getBeer(),true);
        dialog.run();
    }

    void asaliProperties::doneInput()
    {
        if ( type_ == "batch" )
        {
            MW_.clear();
            MW_.resize(NC_);
            for (unsigned int i=0;i<NC_;i++)
            {
                MW_[i] = Glib::Ascii::strtod(speciesMwEntry_[i]->get_text());
            }

            Qhom_.clear();
            Qhom_.resize(Nhom_);

            for (unsigned int i=0;i<Nhom_;i++)
            {
                Qhom_[i] = Glib::Ascii::strtod(speciesHeatEntry_[i]->get_text());
            }

            Qhet_.clear();
            Qhet_.resize(Nhet_);

            for (unsigned int i=Nhom_;i<NR_;i++)
            {
                Qhet_[i-Nhom_] = Glib::Ascii::strtod(speciesHeatEntry_[i]->get_text());
            }

            if ( heatCombo_.get_active_row_number() == 1 )
            {
                for (unsigned int i=0;i<Nhom_;i++)
                {
                    Qhom_[i] = Qhom_[i]/1.e-03; //J/mol -> J/kmol
                }
                for (unsigned int i=0;i<Nhet_;i++)
                {
                    Qhet_[i] = Qhet_[i]/1.e-03; //J/mol -> J/kmol
                }
            }
            else if ( heatCombo_.get_active_row_number() == 2 )
            {
                for (unsigned int i=0;i<Nhom_;i++)
                {
                    Qhom_[i] = Qhom_[i]*1.e03/1.e-03; //kJ/mol -> J/kmol
                }
                for (unsigned int i=0;i<Nhet_;i++)
                {
                    Qhet_[i] = Qhet_[i]*1.e03/1.e-03; //kJ/mol -> J/kmol
                }
            }
            else if ( heatCombo_.get_active_row_number() == 3 )
            {
                for (unsigned int i=0;i<Nhom_;i++)
                {
                    Qhom_[i] = Qhom_[i]*4.184; //cal/kmol -> J/kmol
                }
                for (unsigned int i=0;i<Nhet_;i++)
                {
                    Qhet_[i] = Qhet_[i]*4.184; //cal/kmol -> J/kmol
                }
            }
            else if ( heatCombo_.get_active_row_number() == 4 )
            {
                for (unsigned int i=0;i<Nhom_;i++)
                {
                    Qhom_[i] = Qhom_[i]*4.184/1.e-03; //cal/mol -> J/kmol
                }
                for (unsigned int i=0;i<Nhet_;i++)
                {
                    Qhet_[i] = Qhet_[i]*4.184/1.e-03; //cal/mol -> J/kmol
                }
            }
            else if ( heatCombo_.get_active_row_number() == 5 )
            {
                for (unsigned int i=0;i<Nhom_;i++)
                {
                    Qhom_[i] = Qhom_[i]*1.e03*4.184/1.e-03; //kcal/mol -> J/kmol
                }
                for (unsigned int i=0;i<Nhet_;i++)
                {
                    Qhet_[i] = Qhet_[i]*1.e03*4.184/1.e-03; //kcal/mol -> J/kmol
                }
            }


            if ( energy_ == "on" )
            {
                cp_ = Glib::Ascii::strtod(cpEntry_.get_text());

                if ( cpCombo_.get_active_row_number() == 1 )
                {
                    cp_ = cp_*1.e03; //kJ/kg/K -> J/kg/K
                }
            }
            else
            {
                cp_ = 1.;
            }
        }
        else if ( type_ == "ph1d" )
        {
            MW_.clear();
            diff_.clear();
            MW_.resize(NC_);
            diff_.resize(NC_);
            for (unsigned int i=0;i<NC_;i++)
            {
                MW_[i]   = Glib::Ascii::strtod(speciesMwEntry_[i]->get_text());
                diff_[i] = Glib::Ascii::strtod(speciesDiffEntry_[i]->get_text());
            }
            
            if ( diffCombo_.get_active_row_number() == 1 )
            {
                for (unsigned int i=0;i<NC_;i++)
                {
                    diff_[i] = diff_[i]*1.e-04; //cm2/s->m2
                }
            }

            Qhom_.clear();
            Qhom_.resize(Nhom_);

            for (unsigned int i=0;i<Nhom_;i++)
            {
                Qhom_[i] = Glib::Ascii::strtod(speciesHeatEntry_[i]->get_text());
            }

            Qhet_.clear();
            Qhet_.resize(Nhet_);

            for (unsigned int i=Nhom_;i<NR_;i++)
            {
                Qhet_[i-Nhom_] = Glib::Ascii::strtod(speciesHeatEntry_[i]->get_text());
            }

            if ( heatCombo_.get_active_row_number() == 1 )
            {
                for (unsigned int i=0;i<Nhom_;i++)
                {
                    Qhom_[i] = Qhom_[i]/1.e-03; //J/mol -> J/kmol
                }
                for (unsigned int i=0;i<Nhet_;i++)
                {
                    Qhet_[i] = Qhet_[i]/1.e-03; //J/mol -> J/kmol
                }
            }
            else if ( heatCombo_.get_active_row_number() == 2 )
            {
                for (unsigned int i=0;i<Nhom_;i++)
                {
                    Qhom_[i] = Qhom_[i]*1.e03/1.e-03; //kJ/mol -> J/kmol
                }
                for (unsigned int i=0;i<Nhet_;i++)
                {
                    Qhet_[i] = Qhet_[i]*1.e03/1.e-03; //kJ/mol -> J/kmol
                }
            }
            else if ( heatCombo_.get_active_row_number() == 3 )
            {
                for (unsigned int i=0;i<Nhom_;i++)
                {
                    Qhom_[i] = Qhom_[i]*4.184; //cal/kmol -> J/kmol
                }
                for (unsigned int i=0;i<Nhet_;i++)
                {
                    Qhet_[i] = Qhet_[i]*4.184; //cal/kmol -> J/kmol
                }
            }
            else if ( heatCombo_.get_active_row_number() == 4 )
            {
                for (unsigned int i=0;i<Nhom_;i++)
                {
                    Qhom_[i] = Qhom_[i]*4.184/1.e-03; //cal/mol -> J/kmol
                }
                for (unsigned int i=0;i<Nhet_;i++)
                {
                    Qhet_[i] = Qhet_[i]*4.184/1.e-03; //cal/mol -> J/kmol
                }
            }
            else if ( heatCombo_.get_active_row_number() == 5 )
            {
                for (unsigned int i=0;i<Nhom_;i++)
                {
                    Qhom_[i] = Qhom_[i]*1.e03*4.184/1.e-03; //kcal/mol -> J/kmol
                }
                for (unsigned int i=0;i<Nhet_;i++)
                {
                    Qhet_[i] = Qhet_[i]*1.e03*4.184/1.e-03; //kcal/mol -> J/kmol
                }
            }
            

            if ( energy_ == "on" )
            {
                cp_ = Glib::Ascii::strtod(cpEntry_.get_text());

                if ( cpCombo_.get_active_row_number() == 1 )
                {
                    cp_ = cp_*1.e03; //kJ/kg/K -> J/kg/K
                }

                cond_ = Glib::Ascii::strtod(condEntry_.get_text());

                if ( condCombo_.get_active_row_number() == 1 )
                {
                    cond_ = cond_*1.e03; //W/m/K -> kW/m/K
                }
            }
            else
            {
                cp_   = 1.;
                cond_ = 1.;
            }
        }
        else if ( type_ == "het1d" )
        {
            MW_.clear();
            diff_.clear();
            MW_.resize(NC_);
            diff_.resize(NC_);
            for (unsigned int i=0;i<NC_;i++)
            {
                MW_[i]   = Glib::Ascii::strtod(speciesMwEntry_[i]->get_text());
                diff_[i] = Glib::Ascii::strtod(speciesDiffEntry_[i]->get_text());
            }
            
            if ( diffCombo_.get_active_row_number() == 1 )
            {
                for (unsigned int i=0;i<NC_;i++)
                {
                    diff_[i] = diff_[i]*1.e-04; //cm2/s->m2
                }
            }

            Qhom_.clear();
            Qhom_.resize(Nhom_);

            for (unsigned int i=0;i<Nhom_;i++)
            {
                Qhom_[i] = Glib::Ascii::strtod(speciesHeatEntry_[i]->get_text());
            }

            Qhet_.clear();
            Qhet_.resize(Nhet_);

            for (unsigned int i=Nhom_;i<NR_;i++)
            {
                Qhet_[i-Nhom_] = Glib::Ascii::strtod(speciesHeatEntry_[i]->get_text());
            }

            if ( heatCombo_.get_active_row_number() == 1 )
            {
                for (unsigned int i=0;i<Nhom_;i++)
                {
                    Qhom_[i] = Qhom_[i]/1.e-03; //J/mol -> J/kmol
                }
                for (unsigned int i=0;i<Nhet_;i++)
                {
                    Qhet_[i] = Qhet_[i]/1.e-03; //J/mol -> J/kmol
                }
            }
            else if ( heatCombo_.get_active_row_number() == 2 )
            {
                for (unsigned int i=0;i<Nhom_;i++)
                {
                    Qhom_[i] = Qhom_[i]*1.e03/1.e-03; //kJ/mol -> J/kmol
                }
                for (unsigned int i=0;i<Nhet_;i++)
                {
                    Qhet_[i] = Qhet_[i]*1.e03/1.e-03; //kJ/mol -> J/kmol
                }
            }
            else if ( heatCombo_.get_active_row_number() == 3 )
            {
                for (unsigned int i=0;i<Nhom_;i++)
                {
                    Qhom_[i] = Qhom_[i]*4.184; //cal/kmol -> J/kmol
                }
                for (unsigned int i=0;i<Nhet_;i++)
                {
                    Qhet_[i] = Qhet_[i]*4.184; //cal/kmol -> J/kmol
                }
            }
            else if ( heatCombo_.get_active_row_number() == 4 )
            {
                for (unsigned int i=0;i<Nhom_;i++)
                {
                    Qhom_[i] = Qhom_[i]*4.184/1.e-03; //cal/mol -> J/kmol
                }
                for (unsigned int i=0;i<Nhet_;i++)
                {
                    Qhet_[i] = Qhet_[i]*4.184/1.e-03; //cal/mol -> J/kmol
                }
            }
            else if ( heatCombo_.get_active_row_number() == 5 )
            {
                for (unsigned int i=0;i<Nhom_;i++)
                {
                    Qhom_[i] = Qhom_[i]*1.e03*4.184/1.e-03; //kcal/mol -> J/kmol
                }
                for (unsigned int i=0;i<Nhet_;i++)
                {
                    Qhet_[i] = Qhet_[i]*1.e03*4.184/1.e-03; //kcal/mol -> J/kmol
                }
            }

            mu_ = Glib::Ascii::strtod(muEntry_.get_text());
            ConvertsToPascalPerSecond(mu_,muCombo_.get_active_text());

            if ( energy_ == "on" )
            {
                cp_ = Glib::Ascii::strtod(cpEntry_.get_text());

                if ( cpCombo_.get_active_row_number() == 1 )
                {
                    cp_ = cp_*1.e03; //kJ/kg/K -> J/kg/K
                }

                cond_ = Glib::Ascii::strtod(condEntry_.get_text());

                if ( condCombo_.get_active_row_number() == 1 )
                {
                    cond_ = cond_*1.e03; //W/m/K -> kW/m/K
                }
            }
            else
            {
                cp_   = 1.;
                cond_ = 1.;
            }
        }
        else if ( type_ == "pellet" )
        {
            MW_.clear();
            diff_.clear();
            MW_.resize(NC_);
            diff_.resize(NC_);
            for (unsigned int i=0;i<NC_;i++)
            {
                MW_[i]   = Glib::Ascii::strtod(speciesMwEntry_[i]->get_text());
                diff_[i] = Glib::Ascii::strtod(speciesDiffEntry_[i]->get_text());
            }
            
            if ( diffCombo_.get_active_row_number() == 1 )
            {
                for (unsigned int i=0;i<NC_;i++)
                {
                    diff_[i] = diff_[i]*1.e-04; //cm2/s->m2
                }
            }
        }
        this->hide();
    }
 
    asaliProperties::~asaliProperties()
    {
    }
 
    std::string asaliProperties::getBeer()
    {
        unsigned int seed = time(NULL);
        int i = rand_r(&seed)%beer_.size();
        return beer_[i];
    }

    void asaliProperties::convertToCaption(std::string& n)
    {
        for(unsigned int i=0;i<26;i++)
        {
            std::replace(n.begin(),n.end(),*small[i].c_str(),*big[i].c_str());
        }
    }
    
    std::vector<double> asaliProperties::get_mass_fraction(const std::vector<double> MW, const std::vector<double> x)
    {
        std::vector<double> y(x.size());
        double MWmix = 0.;
        
        for (unsigned int i=0;i<x.size();i++)
        {
            MWmix = MWmix  + x[i]*MW[i];
        }

        for (unsigned int i=0;i<x.size();i++)
        {
            y[i] = x[i]*MW[i]/MWmix;
        }
        return y;
    }

    std::vector<double> asaliProperties::get_mole_fraction(const std::vector<double> MW, const std::vector<double> y)
    {
        std::vector<double> x(y.size());
        double MWmix = 0.;
        
        for (unsigned int i=0;i<y.size();i++)
        {
            MWmix = MWmix  + y[i]/MW[i];
        }
        
        for (unsigned int i=0;i<y.size();i++)
        {
            x[i] = (y[i]/MW[i])/MWmix;
        }
        return x;
    }


    double asaliProperties::get_MWmix(const std::vector<double> MW, const std::vector<double> y)
    {
        double MWmix = 0.;
        
        for (unsigned int i=0;i<y.size();i++)
        {
            MWmix = MWmix  + y[i]/MW[i];
        }

        return 1./MWmix;
    }
}
