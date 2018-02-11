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

#include "asaliKinetic.h"

namespace ASALI
{
    asaliKinetic::asaliKinetic()
    : smallLogo_("images/KineticLogo.tiff"),
      reactionImage_("images/Reaction.tiff"),
      saveButton_("Save"),
      loadButton_("Load"),
      doneButton_("Done"),
      reactionTitleLabel_("Reactions"),
      kLabel_("k"),
      nLabel_("n"),
      EattLabel_("Eatt"),
      aLabel_("a"),
      bLabel_("b"),
      kBox_(Gtk::ORIENTATION_VERTICAL),
      EattBox_(Gtk::ORIENTATION_VERTICAL),
      NR_(6)
    {
        #include "Beer.H"

        this->set_border_width(15);
        this->set_title("ASALI: kinetic input");
        this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
        this->set_icon_from_file("images/Icon.tiff");

        //Add background grid
        this->add(mainGrid_);
        
        mainGrid_.set_row_spacing(10);
        mainGrid_.set_column_spacing(10);
        mainGrid_.attach(smallLogo_,0,0,1,1);
        mainGrid_.attach(reactionImage_,1,0,1,1);
        mainGrid_.attach(reactionTitleLabel_,0,1,1,1);


        //Reactions
        {
            reactionBox_.resize(NR_+1);
            reactionNumbers_.resize(NR_);
            stoichCombo_.resize(NR_);
            reactionEntry_.resize(NR_);
            reactionLabel_.resize(NR_);

            for (unsigned int i=0;i<NR_;i++)
            {
                reactionBox_[i] = new Gtk::Box();
                mainGrid_.attach(*reactionBox_[i],0,2+i,1,1);
                reactionBox_[i]->set_halign(Gtk::ALIGN_START);
                reactionBox_[i]->set_spacing(10);
                
                reactionNumbers_[i]    = new Gtk::Label(Glib::Ascii::dtostr(i+1) + ":");
                reactionBox_[i]->pack_start(*reactionNumbers_[i], Gtk::PACK_SHRINK);

                stoichCombo_[i].resize(4);
                reactionEntry_[i].resize(4);
                reactionLabel_[i].resize(3);
                for (unsigned int j=0;j<4;j++)
                {
                    stoichCombo_[i][j]  = new Gtk::ComboBoxText();
                    reactionEntry_[i][j] = new Gtk::Entry();
                    
                    for (unsigned int k=1;k<10;k++)
                    {
                        stoichCombo_[i][j]->append(Glib::Ascii::dtostr(k));
                    }
                    stoichCombo_[i][j]->set_active(0);
                    reactionEntry_[i][j]->set_max_length(5);
                    reactionEntry_[i][j]->set_width_chars(5);
                    reactionBox_[i]->pack_start(*stoichCombo_[i][j], Gtk::PACK_SHRINK);
                    reactionBox_[i]->pack_start(*reactionEntry_[i][j], Gtk::PACK_SHRINK);
                    
                    if ( j == 0 )
                    {
                        reactionLabel_[i][j] = new Gtk::Label("+");
                        reactionBox_[i]->pack_start(*reactionLabel_[i][j], Gtk::PACK_SHRINK);
                    }
                    else if ( j == 1 )
                    {
                        reactionLabel_[i][j] = new Gtk::Label("---->");
                        reactionBox_[i]->pack_start(*reactionLabel_[i][j], Gtk::PACK_SHRINK);
                    }
                    else if ( j == 2 )
                    {
                        reactionLabel_[i][j] = new Gtk::Label("+");
                        reactionBox_[i]->pack_start(*reactionLabel_[i][j], Gtk::PACK_SHRINK);
                    }
                }
            }

            {
                stoichCombo_[0][0]->set_active(1);
                reactionEntry_[0][0]->set_text("H2");
                
                stoichCombo_[0][1]->set_active(0);
                reactionEntry_[0][1]->set_text("O2");
                
                stoichCombo_[0][2]->set_active(1);
                reactionEntry_[0][2]->set_text("H2O");
            }
        }

        //Reaction parameters
        mainGrid_.attach(reactionParameterGridLabels_,1,1,1,1);
        {
            reactionParameterGridLabels_.set_column_homogeneous(true);
            reactionParameterGridLabels_.set_column_spacing(10);
            reactionParameterGridLabels_.set_row_homogeneous(true);
            reactionParameterGridLabels_.set_row_spacing(10);
            reactionParameterGridLabels_.attach(kBox_,0,0,1,1);
            kBox_.set_spacing(10);
            kBox_.pack_start(kLabel_,Gtk::PACK_SHRINK);
            kBox_.pack_start(kCombo_, Gtk::PACK_SHRINK);
            kCombo_.append("m\u00b3/s/K/mol");
            kCombo_.append("L/s/K/mol");
            kCombo_.append("cc/s/K/mol");
            kCombo_.append("m\u00b3/s/K/kmol");
            kCombo_.append("L/s/K/kmol");
            kCombo_.append("cc/s/K/kmol");
            kCombo_.set_active(0);

            reactionParameterGridLabels_.attach(nLabel_,1,0,1,1);
            reactionParameterGridLabels_.attach(EattBox_,2,0,1,1);
            EattBox_.set_spacing(10);
            EattBox_.pack_start(EattLabel_,Gtk::PACK_SHRINK);
            EattBox_.pack_start(EattCombo_, Gtk::PACK_SHRINK);
            EattCombo_.append("J/mol");
            EattCombo_.append("J/kmol");
            EattCombo_.append("cal/mol");
            EattCombo_.append("cal/kmol");
            EattCombo_.set_active(0);
            reactionParameterGridLabels_.attach(aLabel_,3,0,1,1);
            reactionParameterGridLabels_.attach(bLabel_,4,0,1,1);
            
            reactionParameterGrid_.resize(NR_);
            kEntry_.resize(NR_);
            nEntry_.resize(NR_);
            EattEntry_.resize(NR_);
            aEntry_.resize(NR_);
            bEntry_.resize(NR_);
            for (unsigned int i=0;i<NR_;i++)
            {
                reactionParameterGrid_[i] = new Gtk::Grid();
                mainGrid_.attach(*reactionParameterGrid_[i],1,2+i,1,1);
                reactionParameterGrid_[i]->set_column_homogeneous(true);
                reactionParameterGrid_[i]->set_column_spacing(10);
                reactionParameterGrid_[i]->set_row_homogeneous(true);
                reactionParameterGrid_[i]->set_row_spacing(10);
            
                kEntry_[i]    = new Gtk::Entry();
                kEntry_[i]->set_max_length(10);
                kEntry_[i]->set_width_chars(8);
                nEntry_[i]    = new Gtk::Entry();
                nEntry_[i]->set_max_length(10);
                nEntry_[i]->set_width_chars(8);
                EattEntry_[i] = new Gtk::Entry();
                EattEntry_[i]->set_max_length(10);
                EattEntry_[i]->set_width_chars(8);
                aEntry_[i]    = new Gtk::Entry();
                aEntry_[i]->set_max_length(10);
                aEntry_[i]->set_width_chars(8);
                bEntry_[i]    = new Gtk::Entry();
                bEntry_[i]->set_max_length(10);
                bEntry_[i]->set_width_chars(8);

                reactionParameterGrid_[i]->attach(*kEntry_[i]   ,0,0+i,1,1);
                reactionParameterGrid_[i]->attach(*nEntry_[i]   ,1,0+i,1,1);
                reactionParameterGrid_[i]->attach(*EattEntry_[i],2,0+i,1,1);
                reactionParameterGrid_[i]->attach(*aEntry_[i]   ,3,0+i,1,1);
                reactionParameterGrid_[i]->attach(*bEntry_[i]   ,4,0+i,1,1);
                
                if ( i == 0 )
                {
                    kEntry_[i]->set_text("100");
                    nEntry_[i]->set_text("0");
                    EattEntry_[i]->set_text("0");
                    aEntry_[i]->set_text("1");
                    bEntry_[i]->set_text("0");
                }

            }
        }

        //Buttons
        {
            buttonGrid_.resize(2);
            for (unsigned int i=0;i<2;i++)
            {
                buttonGrid_[i] = new Gtk::Grid();
                buttonGrid_[i]->set_column_homogeneous(true);
                buttonGrid_[i]->set_column_spacing(10);
                buttonGrid_[i]->set_row_homogeneous(true);
                buttonGrid_[i]->set_row_spacing(10);
            }

            mainGrid_.attach(*buttonGrid_[0],0,2+NR_,1,1);
            mainGrid_.attach(*buttonGrid_[1],1,2+NR_,1,1);

            buttonGrid_[0]->attach(saveButton_,0,0,1,1);
            buttonGrid_[0]->attach(loadButton_,1,0,1,1);

            buttonGrid_[1]->attach(doneButton_,0,0,1,1);

            saveButton_.signal_clicked().connect(sigc::mem_fun(*this,&asaliKinetic::saveKineticInput));
            loadButton_.signal_clicked().connect(sigc::mem_fun(*this,&asaliKinetic::loadKineticInput));
            doneButton_.signal_clicked().connect(sigc::mem_fun(*this,&asaliKinetic::doneKineticInput));
        }

        this->show_all_children();
    }

    void asaliKinetic::doneKineticInput()
    {
        stoich_.clear();
        name_.clear();
        kr_.clear();
        Eattr_.clear();
        nr_.clear();
        ar_.clear();
        br_.clear();
        for (unsigned int i=0;i<NR_;i++)
        {
            std::vector<int>         s(4);
            std::vector<std::string> n(4);
            for (unsigned int j=0;j<2;j++)
            {
                std::string name = reactionEntry_[i][j]->get_text().c_str();
                if ( !name.empty() )
                {
                    s[j] = -stoichCombo_[i][j]->get_active_row_number()-1;
                    n[j] = reactionEntry_[i][j]->get_text();
                }
                else
                {
                    s[j] = 0;
                    n[j] = "none";
                }
            }
            
            for (unsigned int j=2;j<4;j++)
            {
                std::string name = reactionEntry_[i][j]->get_text().c_str();
                if ( !name.empty() )
                {
                    s[j] = stoichCombo_[i][j]->get_active_row_number()+1;
                    n[j] = reactionEntry_[i][j]->get_text();
                }
                else
                {
                    s[j] = 0;
                    n[j] = "none";
                }
            }
            //stoich and names
            {
                stoich_.push_back(s);
                name_.push_back(n);
            }

            //k
            {
                std::string value = kEntry_[i]->get_text().c_str();
                if (!value.empty())
                {
                    kr_.push_back(Glib::Ascii::strtod(kEntry_[i]->get_text()));
                }
                else
                {
                    kr_.push_back(0.);
                }
            }

            //n
            {
                std::string value = nEntry_[i]->get_text().c_str();
                if (!value.empty())
                {
                    nr_.push_back(Glib::Ascii::strtod(nEntry_[i]->get_text()));
                }
                else
                {
                    nr_.push_back(0.);
                }
            }

            //Eatt
            {
                std::string value = EattEntry_[i]->get_text().c_str();
                if (!value.empty())
                {
                    Eattr_.push_back(Glib::Ascii::strtod(EattEntry_[i]->get_text()));
                }
                else
                {
                    Eattr_.push_back(0.);
                }
            }

            //a
            {
                std::string value = aEntry_[i]->get_text().c_str();
                if (!value.empty())
                {
                    ar_.push_back(Glib::Ascii::strtod(aEntry_[i]->get_text()));
                }
                else
                {
                    ar_.push_back(0.);
                }
            }

            //b
            {
                std::string value = bEntry_[i]->get_text().c_str();
                if (!value.empty())
                {
                    br_.push_back(Glib::Ascii::strtod(bEntry_[i]->get_text()));
                }
                else
                {
                    br_.push_back(0.);
                }
            }

            //Conversion of Eatt to J/Kmol
            {
                double converter = 1.;
                if (EattCombo_.get_active_row_number() == 0)
                {
                    converter = 1./1e-03;
                }
                else if (EattCombo_.get_active_row_number() == 1)
                {
                    converter = 1.;
                }
                else if (EattCombo_.get_active_row_number() == 2)
                {
                    converter = 4186./1e-03;
                }
                else if (EattCombo_.get_active_row_number() == 3)
                {
                    converter = 4186.;
                }

                Eattr_[i] = Eattr_[i]*converter;
            }

            //Conversion of k
            {
                if (kCombo_.get_active_row_number() == 0)
                {
                    specieConverter_ = 1e03;
                }
                else if (kCombo_.get_active_row_number() == 1)
                {
                    specieConverter_ = 1e03/1e03;
                }
                else if (kCombo_.get_active_row_number() == 2)
                {
                    specieConverter_ = 1e03/1e06;
                }
                else if (kCombo_.get_active_row_number() == 3)
                {
                    specieConverter_ = 1.;
                }
                else if (kCombo_.get_active_row_number() == 4)
                {
                    specieConverter_ = 1./1e03;
                }
                else if (kCombo_.get_active_row_number() == 5)
                {
                    specieConverter_ = 1./1e06;
                }
            }
        }
        this->hide();
    }

    void asaliKinetic::saveKineticInput()
    {
        Gtk::FileChooserDialog dialog("",Gtk::FILE_CHOOSER_ACTION_SAVE);
        dialog.set_transient_for(*this);

        //Add response buttons
        dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
        dialog.add_button("_Save", Gtk::RESPONSE_OK);

        //Show the dialog and wait for a user response
        int result = dialog.run();

        //Handle the response
        switch(result)
        {
            case(Gtk::RESPONSE_OK):
            {
                std::string filename = dialog.get_filename();
                std::ofstream output;
                const char *path = filename.c_str();
                output.open(path,std::ios::out);
                
                output << "#Asali kinetic file" << std::endl;
                for (unsigned int i=0;i<NR_;i++)
                {
                    output << "#Reaction " << i + 1 << std::endl;
                    for (unsigned int j=0;j<4;j++)
                    {
                        std::string name = reactionEntry_[i][j]->get_text().c_str();
                        if ( !name.empty() )
                        {
                            output << stoichCombo_[i][j]->get_active_row_number() << std::endl;
                            output << reactionEntry_[i][j]->get_text() << std::endl;
                        }
                        else
                        {
                            output << 0. << std::endl;
                            output << "none" << std::endl;
                        }
                    }

                    //k
                    {
                        std::string value = kEntry_[i]->get_text().c_str();
                        if (!value.empty())
                        {
                            output << kEntry_[i]->get_text() << std::endl;
                        }
                        else
                        {
                            output << "none" << std::endl;
                        }
                    }

                    //n
                    {
                        std::string value = nEntry_[i]->get_text().c_str();
                        if (!value.empty())
                        {
                            output << nEntry_[i]->get_text() << std::endl;
                        }
                        else
                        {
                            output << "none" << std::endl;
                        }
                    }

                    //Eatt
                    {
                        std::string value = EattEntry_[i]->get_text().c_str();
                        if (!value.empty())
                        {
                            output << EattEntry_[i]->get_text() << std::endl;
                        }
                        else
                        {
                            output << "none" << std::endl;
                        }
                    }

                    //a
                    {
                        std::string value = aEntry_[i]->get_text().c_str();
                        if (!value.empty())
                        {
                            output << aEntry_[i]->get_text() << std::endl;
                        }
                        else
                        {
                            output << "none" << std::endl;
                        }
                    }

                    //b
                    {
                        std::string value = bEntry_[i]->get_text().c_str();
                        if (!value.empty())
                        {
                            output << bEntry_[i]->get_text() << std::endl;
                        }
                        else
                        {
                            output << "none" << std::endl;
                        }
                    }
                    
                    output << kCombo_.get_active_row_number() << std::endl;
                    output << EattCombo_.get_active_row_number() << std::endl;
                }

                output.close();
                dialog.hide();
                this->savedMessage();
                break;
            }
            case(Gtk::RESPONSE_CANCEL):
            {
                dialog.hide();
                break;
            }
            default:
            {
                std::cout << "Unexpected button clicked." << std::endl;
                break;
            }
        }
    }

    void asaliKinetic::loadKineticInput()
    {
        Gtk::FileChooserDialog dialog("",Gtk::FILE_CHOOSER_ACTION_OPEN);
        dialog.set_transient_for(*this);

        //Add response buttons
        dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
        dialog.add_button("_Open", Gtk::RESPONSE_OK);

        //Show the dialog and wait for a user response
        int result = dialog.run();

        //Handle the response
        switch(result)
        {
            case(Gtk::RESPONSE_OK):
            {
                std::string filename = dialog.get_filename();
                std::ifstream input;
                const char *path = filename.c_str();
                input.open(path);

                std::vector<std::string> readed;
                
                while (!input.eof()) 
                {
                    std::string line;
                    getline(input,line);
                    if (line.find("#"))
                    {
                        readed.push_back(line);
                    }
                }

                unsigned int counter = 0;

                for (unsigned int i=0;i<NR_;i++)
                {
                    for (unsigned int j=0;j<4;j++)
                    {
                        stoichCombo_[i][j]->set_active(Glib::Ascii::strtod(readed[counter++]));

                        if ( readed[counter] != "none" )
                        {
                            reactionEntry_[i][j]->set_text(readed[counter]);
                        }
                        counter++;
                    }

                    //k
                    {
                        if ( readed[counter] != "none" )
                        {
                            kEntry_[i]->set_text(readed[counter]);
                        }
                        counter++;
                    }

                    //n
                    {
                        if ( readed[counter] != "none" )
                        {
                            nEntry_[i]->set_text(readed[counter]);
                        }
                        counter++;
                    }

                    //Eatt
                    {
                        if ( readed[counter] != "none" )
                        {
                            EattEntry_[i]->set_text(readed[counter]);
                        }
                        counter++;
                    }

                    //a
                    {
                        if ( readed[counter] != "none" )
                        {
                            aEntry_[i]->set_text(readed[counter]);
                        }
                        counter++;
                    }

                    //b
                    {
                        if ( readed[counter] != "none" )
                        {
                            bEntry_[i]->set_text(readed[counter]);
                        }
                        counter++;
                    }
                    
                    kCombo_.set_active(Glib::Ascii::strtod(readed[counter++]));
                    EattCombo_.set_active(Glib::Ascii::strtod(readed[counter++]));
                }

                dialog.hide();
                this->show_all_children();
                break;
            }
            case(Gtk::RESPONSE_CANCEL):
            {
                dialog.hide();
                break;
            }
            default:
            {
                std::cout << "Unexpected button clicked." << std::endl;
                break;
            }
        }
    }

    bool asaliKinetic::reactionInputCheck(bool test)
    {
        bool check = false;
        
        if (test)
        {
            if ( kr_.size() == Eattr_.size() )
            {
                if ( Eattr_.size() == nr_.size() )
                {
                    if ( nr_.size() == ar_.size() )
                    {
                        if ( ar_.size() == br_.size() )
                        {
                            if ( br_.size() != 0 )
                            {
                                check = true;
                            }
                        }
                    }
                }
            }
        }
        return check;
    }

    void asaliKinetic::savedMessage()
    {
        Gtk::MessageDialog dialog(*this,"Your file has been saved.\nThank you for using ASALI.",true,Gtk::MESSAGE_OTHER);
        dialog.set_secondary_text(this->getBeer(),true);
        dialog.run();
    }

    asaliKinetic::~asaliKinetic()
    {
    }
    
    std::string asaliKinetic::getBeer()
    {
        srand(time(NULL));
        int i = rand()%beer_.size();
        return beer_[i];
    }
}
