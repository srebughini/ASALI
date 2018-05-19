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

#ifndef ASALIPLOT_H
#define ASALIPLOT_H

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
    class asaliPlot : public Gtk::Window
    {
        public:
            asaliPlot();
            
            void setSpecieNames(const std::vector<std::string> n);
            void setSiteNames(const std::vector<std::string> nc);
            
            void setTime(const std::vector<double> t);
            void setVolume(const std::vector<double> V);
            void setLength(const std::vector<double> t);
            
            void setSpecie(const std::vector<std::vector<double> > y,const std::vector<std::vector<double> > x);
            void setSpecie(const std::vector<std::vector<std::vector<double> > > y, const std::vector<std::vector<std::vector<double>> > x);
            void setSpecie(const std::vector<std::vector<std::vector<double> > > yb,const std::vector<std::vector<std::vector<double> > > xb,
                           const std::vector<std::vector<std::vector<double> > > yw,const std::vector<std::vector<std::vector<double> > > xw);

            void setSite(const std::vector<std::vector<double> > z);
            void setSite(const std::vector<std::vector<std::vector<double>> > z);
            
            void setTemperature(const std::vector<double> T);
            void setTemperature(const std::vector<std::vector<double> > T);
            void setTemperature(const std::vector<std::vector<double> > Tb,
                                const std::vector<std::vector<double> > Tw);
                                   
            
            

            void setType(const std::string type);
            void setResolutionType(const std::string resolution);
            
            void build();
            void destroy();
            void plot();
            void exit();

            virtual ~asaliPlot();
            
        private:
        
            Gtk::Button                       plotButton_;
            Gtk::Button                       exitButton_;
            
            Gtk::ButtonBox                    buttonBox_;

            Gtk::Grid                         mainGrid_;
            Gtk::Grid                         moleGrid_;
            Gtk::Grid                         massGrid_;
            Gtk::Grid                         siteGrid_;
            Gtk::Grid                         otherGrid_;
            
            Gtk::Label                        moleLabel_;
            Gtk::Label                        massLabel_;
            Gtk::Label                        siteLabel_;
            Gtk::Label                        otherLabel_;

            std::vector<Gtk::CheckButton *>   moleButton_;
            std::vector<Gtk::CheckButton *>   massButton_;
            std::vector<Gtk::CheckButton *>   siteButton_;
            std::vector<Gtk::CheckButton *>   otherButton_;

            unsigned int NC_;
            unsigned int SURF_NC_;
            unsigned int NP_;

            std::string  type_;
            std::string  resolution_;

            std::vector<double> t_;
            std::vector<double> T_;
            std::vector<double> L_;
            std::vector<double> V_;
            
            std::vector<std::vector<double> > y_;
            std::vector<std::vector<double> > x_;
            std::vector<std::vector<double> > z_;
            std::vector<std::vector<double> > Tt_;
            std::vector<std::vector<double> > Tb_;
            std::vector<std::vector<double> > Tw_;

            std::vector<std::vector<std::vector<double> > > yt_;
            std::vector<std::vector<std::vector<double> > > xt_;
            std::vector<std::vector<std::vector<double> > > zt_;

            std::vector<std::string> n_;
            std::vector<std::string> nc_;


    };
}

#endif
