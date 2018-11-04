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

#ifndef ASALIKINETIC_H
#define ASALIKINETIC_H

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
    class asaliKinetic : public Gtk::Window
    {
        public:
            asaliKinetic();
            
            void exit();
            void saveKineticInput();
            void loadKineticInput();
            void doneKineticInput();
            void savedMessage();

            std::vector<double>  get_k()    {return kr_;};
            std::vector<double>  get_n()    {return nr_;};
            std::vector<double>  get_Eatt() {return Eattr_;};
            std::vector<double>  get_a()    {return ar_;};
            std::vector<double>  get_b()    {return br_;};
            
            std::vector<std::vector<int> >         get_stoich()  {return stoich_;};
            std::vector<std::vector<std::string> > get_name()    {return name_;};
            
            unsigned int         get_NR()        {return NR_;};
            
            double               get_converter() {return specieConverter_;};

            virtual ~asaliKinetic();
            
        private:
        
            std::string       getBeer();

            bool              reactionInputCheck(bool test);

            Gtk::Image        smallLogo_;
            Gtk::Image        reactionImage_;

            Gtk::Button       saveButton_;
            Gtk::Button       loadButton_;
            Gtk::Button       doneButton_;
            
            Gtk::Label        reactionTitleLabel_;
            Gtk::Label        kLabel_;
            Gtk::Label        nLabel_;
            Gtk::Label        EattLabel_;
            Gtk::Label        aLabel_;
            Gtk::Label        bLabel_; 

            Gtk::Box          kBox_;
            Gtk::Box          EattBox_;

            Gtk::Grid         mainGrid_;
            Gtk::Grid         reactionParameterGridLabels_;
 
            Gtk::ComboBoxText  kCombo_;
            Gtk::ComboBoxText  EattCombo_;

            std::vector<Gtk::Box *>          reactionBox_;
            std::vector<Gtk::Label *>        reactionNumbers_;
            std::vector<Gtk::Grid *>         reactionParameterGrid_;
            std::vector<Gtk::Grid *>         buttonGrid_;
            std::vector<Gtk::Entry *>        kEntry_;
            std::vector<Gtk::Entry *>        nEntry_;
            std::vector<Gtk::Entry *>        EattEntry_;
            std::vector<Gtk::Entry *>        aEntry_;
            std::vector<Gtk::Entry *>        bEntry_; 

            std::vector<std::vector<Gtk::ComboBoxText *> >  stoichCombo_;
            std::vector<std::vector<Gtk::Label *> >         reactionLabel_;
            std::vector<std::vector<Gtk::Entry *> >         reactionEntry_;
            
            
            unsigned int             NR_;
            
            std::vector<double>      kr_;
            std::vector<double>      nr_;
            std::vector<double>      Eattr_;
            std::vector<double>      ar_;
            std::vector<double>      br_;
            
            std::vector<std::vector<int> >         stoich_;
            std::vector<std::vector<std::string> > name_;
            
            std::vector<std::string>               beer_;
            
            
            double                   specieConverter_;
    };
}

#endif
