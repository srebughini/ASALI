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

#include "asaliProperties.h"

namespace ASALI
{
    asaliProperties::asaliProperties()
    : batchLogo_("images/BatchLogo.tiff"),
      mainBox_(Gtk::ORIENTATION_VERTICAL),
      nameLabel_("Name"),
      mwLabel_("Molecular weight"),
      reactionLabel_("Reaction"),
      heatLabel_("Heat of reaction"),
      cpLabel_("Mixture specific heat"),
      doneButton_("Done"),
      type_("zero")
    {
        #include "Beer.H"

        this->set_border_width(15);
        this->set_title("ASALI: properties input");
        this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
        this->set_icon_from_file("images/Icon.tiff");

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

        //Batch
        {
            batchGrid_.set_row_spacing(10);
            batchGrid_.set_column_spacing(10);
            batchGrid_.set_column_homogeneous(true);

            heatBox_.set_halign(Gtk::ALIGN_CENTER);
            heatBox_.set_spacing(10);

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

            cpGrid_.set_row_spacing(10);
            cpGrid_.set_column_spacing(10);
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
    }

    void asaliProperties::set_reactions(const std::vector<std::vector<std::string> > name,
                                        const std::vector<std::vector<int> >         stoich)
    {
        name_    = name;
        stoich_ = stoich;
    }

    void asaliProperties::destroy()
    {
        if ( type_ == "batch" )
        {
            if ( energy_ == "on" )
            {
                cpGrid_.remove(cpLabel_);
                cpGrid_.remove(cpCombo_);
                batchGrid_.remove(cpGrid_);
                batchGrid_.remove(cpEntry_);
                batchGrid_.remove(reactionLabel_);
                heatBox_.remove(heatCombo_);
                heatBox_.remove(heatLabel_);
                batchGrid_.remove(heatBox_);
                
                for (unsigned int i=0;i<reactionNumberLabel_.size();i++)
                {
                    batchGrid_.remove(*reactionNumberLabel_[i]);
                    batchGrid_.remove(*speciesHeatEntry_[i]);
                }
            }

            batchGrid_.remove(nameLabel_);
            batchGrid_.remove(mwLabel_);

            for (unsigned int i=0;i<speciesNameLabel_.size();i++)
            {
                batchGrid_.remove(*speciesNameLabel_[i]);
                batchGrid_.remove(*speciesMwEntry_[i]);
            }

            mainBox_.remove(batchLogo_);
            mainBox_.remove(batchGrid_);
            mainBox_.remove(doneButton_);
        }
    }

    void asaliProperties::build()
    {
        NR_ = 0;
        if ( type_ == "batch" )
        {
            mainBox_.pack_start(batchLogo_, Gtk::PACK_SHRINK);
            mainBox_.pack_start(batchGrid_, Gtk::PACK_SHRINK);

            batchGrid_.attach(nameLabel_,0,0,1,1);
            batchGrid_.attach(mwLabel_,1,0,1,1);

            for (unsigned int i=0;i<NC_;i++)
            {
                speciesNameLabel_[i] = new Gtk::Label(n_[i]);
                batchGrid_.attach(*speciesNameLabel_[i],0,1+i,1,1);
                speciesMwEntry_[i] = new Gtk::Entry();
                batchGrid_.attach(*speciesMwEntry_[i],1,1+i,1,1);
                
                if ( MW_.size() != 0 )
                {
                    std::ostringstream s;
                    s << MW_[i];
                    speciesMwEntry_[i]->set_text(s.str());
                }
            }
            
            if ( energy_ == "on" )
            {
                batchGrid_.attach(cpGrid_,0,NC_+1,1,1);
                cpGrid_.attach(cpLabel_,0,0,1,1);
                cpGrid_.attach(cpCombo_,1,0,1,1);
                
                batchGrid_.attach(cpEntry_,1,NC_+1,1,1);

                batchGrid_.attach(reactionLabel_,0,NC_+2,1,1);
                batchGrid_.attach(heatBox_,1,NC_+2,1,1);
                heatBox_.pack_start(heatLabel_, Gtk::PACK_SHRINK);
                heatBox_.pack_start(heatCombo_, Gtk::PACK_SHRINK);

                unsigned int counter = 0;
                for (unsigned int i=0;i<name_.size();i++)
                {
                    std::string reaction = "";
                    
                    if ( name_[i][0] != "none" )
                    {
                        {
                            std::ostringstream s;
                            s << stoich_[i][0]+1;
                            reaction = reaction + s.str();
                        }
                        
                        {
                            reaction = reaction + " " + name_[i][0];
                        }
                    }
                    
                    if ( name_[i][1] != "none" )
                    {
                        {
                            
                            reaction = reaction + " + ";
                        }

                        {
                            std::ostringstream s;
                            s << stoich_[i][1]+1;
                            reaction = reaction + s.str();
                        }

                        {
                            reaction = reaction + " " + name_[i][1];
                        }

                    }

                    if ( reaction != "")
                    {
                        reaction = reaction + " -> ";
                    }
                    
                    if ( name_[i][2] != "none" )
                    {
                        {
                            std::ostringstream s;
                            s << stoich_[i][2]+1;
                            reaction = reaction + s.str();
                        }
                        
                        {
                            reaction = reaction + " " + name_[i][2];
                        }
                    }
                    
                    if ( name_[i][3] != "none" )
                    {
                        {
                            
                            reaction = reaction + " + ";
                        }

                        {
                            std::ostringstream s;
                            s << stoich_[i][3]+1;
                            reaction = reaction + s.str();
                        }

                        {
                            reaction = reaction + " " + name_[i][3];
                        }
                    }
                    
                    if ( reaction != "")
                    {
                        reactionNumberLabel_.push_back(new Gtk::Label(reaction));
                        batchGrid_.attach(*reactionNumberLabel_[counter],0,NC_+3+counter,1,1);
                        speciesHeatEntry_.push_back(new Gtk::Entry());
                        batchGrid_.attach(*speciesHeatEntry_[counter],1,NC_+3+counter,1,1);
                        counter++;
                    }
                    NR_ = counter;
                }
            }
            else
            {
                NR_ = 0;
            }


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

            Q_.clear();
            Q_.resize(NR_);

            for (unsigned int i=0;i<NR_;i++)
            {
                Q_[i] = Glib::Ascii::strtod(speciesHeatEntry_[i]->get_text());
            }

            if ( heatCombo_.get_active_row_number() == 1 )
            {
                for (unsigned int i=0;i<NR_;i++)
                {
                    Q_[i] = Q_[i]/1.e-03; //J/mol -> J/kmol
                }
            }
            else if ( heatCombo_.get_active_row_number() == 2 )
            {
                for (unsigned int i=0;i<NR_;i++)
                {
                    Q_[i] = Q_[i]*1.e03/1.e-03; //kJ/mol -> J/kmol
                }
            }
            else if ( heatCombo_.get_active_row_number() == 3 )
            {
                for (unsigned int i=0;i<NR_;i++)
                {
                    Q_[i] = Q_[i]*4.184; //cal/kmol -> J/kmol
                }
            }
            else if ( heatCombo_.get_active_row_number() == 4 )
            {
                for (unsigned int i=0;i<NR_;i++)
                {
                    Q_[i] = Q_[i]*4.184/1.e-03; //cal/mol -> J/kmol
                }
            }
            else if ( heatCombo_.get_active_row_number() == 5 )
            {
                for (unsigned int i=0;i<NR_;i++)
                {
                    Q_[i] = Q_[i]*1.e03*4.184/1.e-03; //kcal/mol -> J/kmol
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

        this->hide();
    }
 
    asaliProperties::~asaliProperties()
    {
    }
 
    std::string asaliProperties::getBeer()
    {
        srand(time(NULL));
        int i = rand()%beer_.size();
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

        return MWmix;
    }
}
