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
#include <thread>
#include "chemkinConverter.h"
#include "canteraInterface.h"
#include "speciesPopup.h"
#include "transportProperties.h"
#include "thermoProperties.h"
#include "thermoTransportProperties.h"
#include "vacuumProperties.h"
#include "equilibriumCalculator.h"
#include "batchReactor.h"
#include "cstrReactor.h"
#include "ph1dReactor.h"
#include "het1dReactor.h"
#include "pressureDrops.h"

namespace ASALI
{
    class Asali : public Gtk::Window
    {
        public:
            Asali();
            
            virtual ~Asali();
            
            #include "UnitConversion.H"
            
        private:

            void exit();
            void discrimer();
            void mainMenu();
            void noneInputError();
            void changeCursor();
            void loadCanteraInput();
            void defaultCanteraInput();
            void noneInput();
            void chemkin();
            void chemistryMenu2();
            void transport();
            void thermo();
            void thermoTransport();
            void vacuum();
            void equilibrium();
            void reactors();
            void batch();
            void cstr();
            void ph1d();
            void het1d();
            void dp();
            bool chemistryMenu1(GdkEventButton*);

            std::string       getBeer();
            std::string       getBeerShort();

            Gtk::Button       discrimerButton_;
            Gtk::Button       exitButton1_;
            Gtk::Button       exitButton2_;
            Gtk::Button       exitButton3_;
            Gtk::Button       exitButton4_;
            Gtk::Button       backButton_;
            Gtk::Button       startButton_;
            Gtk::Button       defaultCanteraInputButton_;
            Gtk::Button       loadCanteraInputButton_;
            Gtk::Button       noneInputButton_;
            Gtk::Button       conversionButton_;
            Gtk::Button       canteraInputButton_;
            Gtk::Button       transportButton_;
            Gtk::Button       thermoButton_;
            Gtk::Button       thermoTransportButton_;
            Gtk::Button       equilibriumButton_;
            Gtk::Button       reactorsButton_;
            Gtk::Button       vacuumButton_;
            Gtk::Button       batchButton_;
            Gtk::Button       cstrButton_;
            Gtk::Button       ph1dButton_;
            Gtk::Button       het1dButton_;
            Gtk::Button       dpButton_;
            
            Gtk::Box          menuBox_;
            Gtk::Box          chemistryBox_;
            Gtk::Box          reactorBox_;

            
            Gtk::ButtonBox    linkButtonBox_;
            Gtk::ButtonBox    exitButtonBox_;
            Gtk::ButtonBox    discrimerButtonBox_;
            Gtk::ButtonBox    startButtonBox_;
            Gtk::ButtonBox    chemistryButtonBox_;
            Gtk::ButtonBox    menuButtonBox_;
            Gtk::ButtonBox    reactorButtonBox_;

            Gtk::EventBox     logoEventBox_;

            Gtk::Label        heading_;
            Gtk::Label        kineticLabel_;
            Gtk::Label        beerLabel_;

            Gtk::Grid         grid_;
            Gtk::Grid         reactorButtonGrid_;

            Gtk::Image        bigLogo_;
            Gtk::Image        smallLogo1_;
            Gtk::Image        smallLogo2_;
            Gtk::Image        smallLogo3_;
            
            Gtk::LinkButton   gitButton_;
            Gtk::LinkButton   forgeButton_;
            
            std::string       kineticType_;

            std::vector<std::string>  beer_;
            std::vector<std::string>  beerShort_;

            Cantera::ThermoPhase              *thermo_;
            Cantera::Transport                *transport_;
            Cantera::Kinetics                 *kinetic_;
            Cantera::Interface                *surface_;
            ASALI::chemkinConverter           *converter_;
            ASALI::canteraInterface           *canteraInterface_;
            ASALI::speciesPopup               *speciesNames_;
            ASALI::transportProperties        *transportMenu_;
            ASALI::thermoProperties           *thermoMenu_;
            ASALI::thermoTransportProperties  *thermoTransportMenu_;
            ASALI::vacuumProperties           *vacuumMenu_;
            ASALI::equilibriumCalculator      *equilibriumMenu_;
            ASALI::batchReactor               *batchMenu_;
            ASALI::cstrReactor                *cstrMenu_;
            ASALI::ph1dReactor                *ph1dMenu_;
            ASALI::het1dReactor               *het1dMenu_;
            ASALI::pressureDrops              *dpMenu_;
    };
}
