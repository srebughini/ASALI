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

#include "frontend/catalystProperties.hpp"

namespace ASALI
{
    catalystProperties::catalystProperties()
    : het1dLogo_(this->relative_path_to_absolute_path("images/Het1DLogo.png")),
      mainBox_(Gtk::ORIENTATION_VERTICAL),
      rhoLabel_("Density"),
      condLabel_("Thermal conductivity"),
      cpLabel_("Specific heat"),
      loadLabel_("Load"),
      TLabel_("Temperature"),
      doneButton_("Done")
    {
        this->set_border_width(15);
        this->set_title("ASALI: catalyst input");
        this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
        this->set_icon_from_file(this->relative_path_to_absolute_path("images/Icon.png"));

        //Add background grid
        mainBox_.set_halign(Gtk::ALIGN_START);
        mainBox_.set_spacing(10);
        this->add(mainBox_);

        mainBox_.pack_start(het1dLogo_, Gtk::PACK_SHRINK);
        mainBox_.pack_start(mainGrid_, Gtk::PACK_SHRINK);

        mainGrid_.attach(rhoLabel_,0,0,1,1);
        mainGrid_.attach(condLabel_,0,1,1,1);
        mainGrid_.attach(cpLabel_,0,2,1,1);
        mainGrid_.attach(loadLabel_,0,3,1,1);
        mainGrid_.attach(TLabel_,0,4,1,1);

        mainGrid_.attach(rhoEntry_,1,0,1,1);
        mainGrid_.attach(condEntry_,1,1,1,1);
        mainGrid_.attach(cpEntry_,1,2,1,1);
        mainGrid_.attach(loadEntry_,1,3,1,1);
        mainGrid_.attach(TEntry_,1,4,1,1);

        mainGrid_.attach(rhoCombo_,2,0,1,1);
        mainGrid_.attach(condCombo_,2,1,1,1);
        mainGrid_.attach(cpCombo_,2,2,1,1);
        mainGrid_.attach(loadCombo_,2,3,1,1);
        mainGrid_.attach(TCombo_,2,4,1,1);

        {
            mainGrid_.set_column_homogeneous(true);
            mainGrid_.set_row_spacing(10);
            mainGrid_.set_column_spacing(10);

            rhoCombo_.append("kg/m\u00b3");
            rhoCombo_.append("g/cc");
            rhoCombo_.set_active(0);

            loadCombo_.append("1/m");
            loadCombo_.append("1/dm");
            loadCombo_.append("1/cm");
            loadCombo_.append("1/mm");
            loadCombo_.set_active(0);

            cpCombo_.append("J/kg/K");
            cpCombo_.append("kJ/kg/K");
            cpCombo_.set_active(0);

            condCombo_.append("W/m/K");
            condCombo_.append("kW/m/K");
            condCombo_.set_active(0);

            TCombo_.append("K");
            TCombo_.append("°C");
            TCombo_.append("°F");
            TCombo_.set_active(0);

            rhoEntry_.set_text("2700");
            cpEntry_.set_text("400");
            condEntry_.set_text("2.5");
            loadEntry_.set_text("1");
            TEntry_.set_text("298.15");
        }

        {
            mainBox_.pack_end(doneButton_,Gtk::PACK_SHRINK);
            doneButton_.signal_clicked().connect(sigc::mem_fun(*this,&catalystProperties::doneInput));
        }

        this->resize(mainBox_.get_width(),mainBox_.get_height ());
        this->show_all_children();
    }

    void catalystProperties::doneInput()
    {
        cp_   = Glib::Ascii::strtod(cpEntry_.get_text());
        rho_  = Glib::Ascii::strtod(rhoEntry_.get_text());
        cond_ = Glib::Ascii::strtod(condEntry_.get_text());
        alfa_ = Glib::Ascii::strtod(loadEntry_.get_text());
        T_    = Glib::Ascii::strtod(TEntry_.get_text());

        ConvertsToOneOverMeter(alfa_,loadCombo_.get_active_text());
        ConvertsToJoulePerKgPerKelvin(cp_,cpCombo_.get_active_text());
        ConvertsToKgPerCubeMeter(rho_,rhoCombo_.get_active_text());
        ConvertsToKelvin(T_,TCombo_.get_active_text());
        ConvertsToWattPerMeterPerKelving(cond_,condCombo_.get_active_text());

        this->hide();
    }
 
    catalystProperties::~catalystProperties()
    {
    }
}
