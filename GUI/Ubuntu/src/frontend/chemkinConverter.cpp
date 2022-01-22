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

#include "frontend/chemkinConverter.hpp"

namespace ASALI
{
    chemkinConverter::chemkinConverter()
        : buttonBox_(Gtk::ORIENTATION_VERTICAL),
          output_("Convert"),
          help_("Help"),
          exit_("Exit"),
          logo_(fileManager_.relative_path_to_absolute_path("images/SmallLogo.png"))
    {
        beerQuote_ = new ASALI::beerQuote();

        files_.resize(5);

        this->set_default_size(600, 400);
        this->set_border_width(15);
        this->set_title("ASALI: CHEMKIN converter");
        this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
        this->set_icon_from_file(fileManager_.relative_path_to_absolute_path("images/Icon.png"));

        //Adding logo
        mainBox_.set_halign(Gtk::ALIGN_START);
        mainBox_.set_spacing(10);
        mainBox_.pack_start(logo_, Gtk::PACK_SHRINK);

        //Adding thermo and transport buttons
        mainBox_.pack_start(buttonBox_, Gtk::PACK_SHRINK);
        buttonBox_.set_valign(Gtk::ALIGN_CENTER);
        buttonBox_.set_spacing(10);
        buttonBox_.set_homogeneous(true);
        buttonBox_.pack_start(kinetic_, Gtk::PACK_SHRINK);
        kinetic_.signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &chemkinConverter::load), 0));
        buttonBox_.pack_start(thermo_, Gtk::PACK_SHRINK);
        thermo_.signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &chemkinConverter::load), 1));
        buttonBox_.pack_start(transport_, Gtk::PACK_SHRINK);
        transport_.signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &chemkinConverter::load), 2));
        buttonBox_.pack_start(surface_, Gtk::PACK_SHRINK);
        surface_.signal_clicked().connect(sigc::bind<int>(sigc::mem_fun(*this, &chemkinConverter::load), 3));
        buttonBox_.pack_start(endGrid_, Gtk::PACK_SHRINK);

        endGrid_.set_column_homogeneous(true);
        endGrid_.set_column_spacing(10);
        endGrid_.set_row_spacing(10);
        endGrid_.attach(output_, 0, 0, 1, 1);
        endGrid_.attach(help_, 1, 0, 1, 1);
        endGrid_.attach(exit_, 2, 0, 1, 1);

        output_.signal_clicked().connect(sigc::mem_fun(*this, &chemkinConverter::run));
        help_.signal_clicked().connect(sigc::mem_fun(*this, &chemkinConverter::help));
        exit_.signal_clicked().connect(sigc::mem_fun(*this, &chemkinConverter::exit));

        this->clean();
    }

    void chemkinConverter::clean()
    {
        this->remove();
        this->add(mainBox_);
        kinetic_.set_label("Gas phase chemistry file");
        thermo_.set_label("Thermodynamic coefficient file");
        transport_.set_label("Transport coefficient file");
        surface_.set_label("Surface chemistry file");

        for (unsigned int i = 0; i < 5; i++)
        {
            files_[i] = "";
        }

        this->resize(mainBox_.get_width(), mainBox_.get_height());
        this->show_all_children();
    }

    void chemkinConverter::exit()
    {
        this->hide();
    }

    void chemkinConverter::run()
    {
        if (files_[0] == "")
        {
            this->error(kinetic_.get_label());
        }
        else if (files_[1] == "")
        {
            this->error(thermo_.get_label());
        }
        else if (files_[2] == "")
        {
            this->error(transport_.get_label());
        }
        else if (files_[3] == "")
        {
            this->error(surface_.get_label());
        }
        else
        {
            std::string dialogname = fileManager_.saveFile(this->get_toplevel()->gobj(), "*.cti");
            if (dialogname != "")
            {
                fileManager_.removeFileExtension(dialogname, ".xml");
                fileManager_.removeFileExtension(dialogname, ".cti");
                std::string filename = dialogname + ".cti";
                {
                    files_[4] = "--output=" + filename;
                }

                {
                    fileManager_.fromCkToCti(files_);
                }

                if (bool(std::ifstream(filename)))
                {
                    fileManager_.fromCtiToXml(filename);                    
                    std::remove(filename.c_str());
                    this->savedMessage();
                }
                else
                {
                    this->notSavedMessage();
                }
            }
        }
    }

    void chemkinConverter::load(const int index)
    {
        std::string filename = fileManager_.openFile(this->get_toplevel()->gobj());
        if (filename != "")
        {
            std::string command;
            if (index == 0)
            {
                kinetic_.set_label(filename);
                command = "--input=" + filename;
            }
            else if (index == 1)
            {
                thermo_.set_label(filename);
                command = "--thermo=" + filename;
            }
            else if (index == 2)
            {
                transport_.set_label(filename);
                command = "--transport=" + filename;
            }
            else if (index == 3)
            {
                surface_.set_label(filename);
                command = "--surface=" + filename;
            }

            files_[index] = command;
            this->resize(mainBox_.get_width(), mainBox_.get_height());
            this->show_all_children();
        }
    }

    void chemkinConverter::savedMessage()
    {
        Gtk::MessageDialog dialog(*this, "Conversion completed. Your file as been saved.\nThank you for using ASALI.", true, Gtk::MESSAGE_OTHER);
        dialog.set_secondary_text(beerQuote_->getShortRandomQuote(), true);
        dialog.run();
    }

    void chemkinConverter::help()
    {
        Gtk::MessageDialog dialog(*this, "Problem in converting your scheme into CANTERA format?\nSend it to: ste.rebu@outlook.it\nWe will be glad to help you!", true, Gtk::MESSAGE_OTHER);
        dialog.set_secondary_text(beerQuote_->getShortRandomQuote(), true);
        dialog.run();
    }

    void chemkinConverter::error(const std::string &type)
    {
        Gtk::MessageDialog dialog(*this, type + " is missing!!", true, Gtk::MESSAGE_ERROR);
        dialog.set_secondary_text(beerQuote_->getShortRandomQuote(), true);
        dialog.run();
    }

    void chemkinConverter::notSavedMessage()
    {
        Gtk::MessageDialog dialog(*this, "Conversion stopped! The most common reasons for that are:\n1/Something is wrong with your input files.\n2/You have not load CANTERA enviornment", true, Gtk::MESSAGE_ERROR);
        dialog.set_secondary_text(beerQuote_->getShortRandomQuote(), true);
        dialog.run();
    }

    bool chemkinConverter::checkConvertedFile(const std::string &filename)
    {
        std::ifstream input;
        const char *path = filename.c_str();
        input.open(path);
        std::vector<std::string> interfaces = fileManager_.getCanteraInterfaces(filename);

        if (interfaces[0] == "none" ||
            interfaces[1] == "none")
        {
            std::string type = "none";
            for (unsigned int i = 0; i < interfaces.size(); i++)
            {
                if (interfaces[i] != "none")
                {
                    type = fileManager_.getCanteraPhaseName(interfaces[i]);
                }
            }
            if (type == "none")
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            std::vector<std::string> type(2);
            type[0] = "none";
            type[1] = "none";
            for (unsigned int i = 0; i < interfaces.size(); i++)
            {
                type[i] = fileManager_.getCanteraPhaseName(interfaces[i]);

                if (type[0] != "none" && type[1] != "none")
                {
                    break;
                }
            }

            if (type[0] == "none" ||
                type[1] == "none")
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }

    chemkinConverter::~chemkinConverter()
    {
        delete beerQuote_;
    }
}
