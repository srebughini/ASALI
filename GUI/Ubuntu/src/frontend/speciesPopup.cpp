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

#include "frontend/speciesPopup.hpp"

namespace ASALI
{
    speciesPopup::speciesPopup()
        : closeButton_("Close"),
          mainBox_(Gtk::ORIENTATION_VERTICAL),
          formulaHeading_("<b>Formula</b>"),
          descriptionHeading_("<b>Description</b>"),
          nameHeading_("<b>ASALI name</b>")
    {
		{
			this->set_default_size(600, 400);
            this->set_border_width(15);
            this->set_title("ASALI: species names");
            this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
            this->set_icon_from_file(fileManager_.relative_path_to_absolute_path("images/Icon.png"));
        }

		grid_.set_column_homogeneous(true);
		grid_.set_column_spacing(10);
		grid_.set_row_homogeneous(true);
		grid_.set_row_spacing(10);
        
        //Adding headlines - Formula
		formulaHeading_.set_use_markup(true);
		formulaHeading_.set_justify(Gtk::JUSTIFY_CENTER);
		grid_.attach(formulaHeading_, 0, 0, 1, 1);
		
		//Adding headlines - Description
		descriptionHeading_.set_use_markup(true);
		descriptionHeading_.set_justify(Gtk::JUSTIFY_CENTER);
		grid_.attach(descriptionHeading_, 1, 0, 1, 1);
		
		//Adding headlines - ASALI name
		nameHeading_.set_use_markup(true);
		nameHeading_.set_justify(Gtk::JUSTIFY_CENTER);
		grid_.attach(nameHeading_, 2, 0, 1, 1);
        
        //Adding species names
        std::vector<std::vector<std::string>> fileToMatrix = fileManager_.readSpeciesPopupFile();
       
        for (unsigned int i=0;i<fileToMatrix[0].size();i++)
		{
			formulaLabel_.push_back(Gtk::Label(fileToMatrix[0][i]));
			descriptionLabel_.push_back(Gtk::Label(fileToMatrix[1][i]));
			nameLabel_.push_back(Gtk::Label(fileToMatrix[2][i]));
			
			formulaLabel_[i].set_justify(Gtk::JUSTIFY_CENTER);
			descriptionLabel_[i].set_justify(Gtk::JUSTIFY_CENTER);
			nameLabel_[i].set_justify(Gtk::JUSTIFY_CENTER);
			
			grid_.attach(formulaLabel_[i], 0,i+1,1,1);
			grid_.attach(descriptionLabel_[i], 1,i+1,1,1);
			grid_.attach(nameLabel_[i], 2,i+1,1,1);
		}

		this->add(mainBox_);
        mainBox_.pack_start(scrolledWindow_);
        scrolledWindow_.add(grid_);
        scrolledWindow_.set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_AUTOMATIC);
        mainBox_.pack_end(closeButton_, Gtk::PACK_SHRINK);
        closeButton_.signal_clicked().connect(sigc::mem_fun(*this, &speciesPopup::exit));
        this->show_all_children();
    }

    void speciesPopup::exit()
    {
        this->hide();
    }
}
