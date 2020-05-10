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

#ifndef ASALIPROPERTIES_H
#define ASALIPROPERTIES_H

#include <gtkmm.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctime>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <limits>

namespace ASALI
{
    class asaliProperties : public Gtk::Window
    {
        public:
        
            #include "shared/UnitConversion.H"
        
            asaliProperties();
            
            void destroy();
            void build();
            void savedMessage();
            void set_type(const std::string type);
            void set_n(const std::vector<std::string> n);
            void set_reactions(const unsigned int Nhom, const unsigned int Nhet);
            void set_energy(const std::string energy);
                               

            void doneInput();
            void convertToCaption(std::string& n);

            std::vector<double>  get_MW()   {return MW_;};
            std::vector<double>  get_diff() {return diff_;};
            std::vector<double>  get_Qhom() {return Qhom_;};
            std::vector<double>  get_Qhet() {return Qhet_;};
            
            double               get_cp()   {return cp_;};
            double               get_cond() {return cond_;};
            double               get_mu()   {return mu_;};
            
            std::vector<double>  get_mass_fraction(const std::vector<double> MW, const std::vector<double> x);
            std::vector<double>  get_mole_fraction(const std::vector<double> MW, const std::vector<double> y);
            double               get_MWmix(const std::vector<double> MW, const std::vector<double> x);
            
            std::string          get_type() {return type_;};


            virtual ~asaliProperties();
            
        private:
        
            std::string       getBeer();
        
            Gtk::Image        batchLogo_;
            Gtk::Image        ph1dLogo_;
            Gtk::Image        het1dLogo_;
            Gtk::Image        pelletLogo_;

            Gtk::Box          mainBox_;
            Gtk::Box          heatBox_;
            Gtk::Box          diffBox_;

            Gtk::Grid         mainGrid_;
            Gtk::Grid         cpGrid_;
            Gtk::Grid         condGrid_;

            Gtk::Label        nameLabel_;
            Gtk::Label        mwLabel_;
            Gtk::Label        diffLabel_;
            Gtk::Label        reactionLabel_;
            Gtk::Label        heatLabel_;
            Gtk::Label        cpLabel_;
            Gtk::Label        condLabel_;
            Gtk::Label        muLabel_;
            
            Gtk::Button       doneButton_;
            
            Gtk::ComboBoxText heatCombo_;
            Gtk::ComboBoxText cpCombo_;
            Gtk::ComboBoxText condCombo_;
            Gtk::ComboBoxText diffCombo_;
            Gtk::ComboBoxText muCombo_;

            Gtk::Entry          cpEntry_;
            Gtk::Entry          condEntry_;
            Gtk::Entry          muEntry_;
            
            std::vector<Gtk::Label *>   speciesNameLabel_;
            std::vector<Gtk::Label *>   reactionNumberLabel_;

            std::vector<Gtk::Entry *>   speciesMwEntry_;
            std::vector<Gtk::Entry *>   speciesDiffEntry_;
            std::vector<Gtk::Entry *>   speciesHeatEntry_;
            
            
            unsigned int              NR_;
            unsigned int              Nhom_;
            unsigned int              Nhet_;
            unsigned int              NC_;
            
            std::vector<std::string>  n_;
            std::vector<std::string>  beer_;
            std::vector<std::string>  small;
            std::vector<std::string>  big;
            
            std::vector<double>       MW_;
            std::vector<double>       diff_;
            std::vector<double>       Qhom_;
            std::vector<double>       Qhet_;
            

            std::string               type_;
            std::string               energy_;
            
            double                    cp_;
            double                    cond_;
            double                    mu_;
    };
}

#endif
