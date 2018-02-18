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

#include "runBar.h"

namespace ASALI
{
    runBar::runBar()
    : mainBox_(Gtk::ORIENTATION_VERTICAL),
      solvingLabel_("ASALI is solving...please wait!")
    {
        #include "Beer.H"

        this->set_border_width(15);
        this->set_title("ASALI: resolution progress");
        this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
        this->set_icon_from_file("images/Icon.tiff");
        this->add(mainBox_);
        mainBox_.pack_start(solvingLabel_,Gtk::PACK_SHRINK);
        mainBox_.pack_start(runBar_, Gtk::PACK_SHRINK);
        mainBox_.pack_start(beerLabel_, Gtk::PACK_SHRINK);
        this->resize(mainBox_.get_width(),mainBox_.get_height());
        this->show_all_children();
    }
    
    void runBar::update(const double fraction)
    {
        runBar_.set_fraction(fraction);
        {
            std::ostringstream s;
            s << fraction;
            runBar_.set_text(s.str());
        }
        beerLabel_.set_text(this->getBeer());
        beerLabel_.set_use_markup(true);
        beerLabel_.set_justify(Gtk::JUSTIFY_CENTER);
    }

    void runBar::exit()
    {
        this->hide();
    }

    std::string runBar::getBeer()
    {
        srand(time(NULL));
        int i = rand()%beer_.size();
        return beer_[i];
    }

    runBar::~runBar()
    {
    }
}
