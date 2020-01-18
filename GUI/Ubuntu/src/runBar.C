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
      closeButton_("Cancel"),
      solvingLabel_("ASALI is solving...please wait!")
    {
        this->set_border_width(15);
        this->set_title("ASALI");
        this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
        this->set_icon_from_file("images/Icon.png");
        this->add(mainBox_);
        mainBox_.set_spacing(10);
        mainBox_.pack_start(solvingLabel_,Gtk::PACK_SHRINK);
        mainBox_.pack_start(timeLabel_, Gtk::PACK_SHRINK);
        mainBox_.pack_start(runBar_, Gtk::PACK_SHRINK);
        mainBox_.pack_start(closeButton_, Gtk::PACK_SHRINK);
        closeButton_.signal_clicked().connect(sigc::mem_fun(*this,&runBar::close));
        this->resize(mainBox_.get_width(),mainBox_.get_height());
        this->show_all_children();
    }
    
    void runBar::update(const double fraction,const std::string tm)
    {
        if ( fraction == 0 )
        {
            close_ = true;
        }
        
        runBar_.set_fraction(fraction);
        {
            std::ostringstream s;
            s << fraction;
            runBar_.set_text(s.str());
        }
        
        timeLabel_.set_text(tm);
    }


    void runBar::close()
    {
        close_ = false;
        this->hide();
    }

    void runBar::exit()
    {
        this->hide();
    }

    runBar::~runBar()
    {
    }
}
