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

#ifndef CHEMKINCONVERTER_H
#define CHEMKINCONVERTER_H

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

#if ASALI_ON_WINDOW == 1
#include <windows.h>
#endif

namespace ASALI
{
    class chemkinConverter : public Gtk::Window
    {
        public:
            chemkinConverter();
            
            virtual ~chemkinConverter();
            
        private:
        
            void exit();
            void clean();
            void load(int index);
            void savedMessage();
            void notSavedMessage();
            void run();
            void help();
            void error(std::string type);
            void eraseSubString(std::string &mainStr, const std::string toErase);
            bool checkConvertedFile(std::string filename);

            std::string getBeer();
            std::string getBeerShort();

            Gtk::Box         mainBox_;
            Gtk::Box         buttonBox_;
            
            Gtk::Grid        endGrid_;

            Gtk::Button      kinetic_;
            Gtk::Button      thermo_;
            Gtk::Button      transport_;
            Gtk::Button      surface_;
            Gtk::Button      output_;
            Gtk::Button      help_;
            Gtk::Button      exit_;
           
            
            Gtk::Image       logo_;
            
            std::vector<std::string>  files_;
            std::vector<std::string>  beer_;
            std::vector<std::string>  beerShort_;
        
    };
}

#endif
