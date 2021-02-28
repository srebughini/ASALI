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


#ifndef CATALYTICREACTORS_H
#define CATALYTICREACTORS_H

#include "pythonInterface.hpp"
#include "speciesPopup.hpp"
#include "asaliProperties.hpp"
#include "asaliCatalystProperties.hpp"
#include "asaliPlot.hpp"
#include "runBar.hpp"

#if ASALI_USING_CANTERA==1
#include "canteraInterface.hpp"
#else
#include "asaliInterface.hpp"
#endif

namespace ASALI
{
    class catalyticReactors : public Gtk::Window
    {
        public:
            catalyticReactors(std::string kineticType);

            #include "shared/UnitConversion.H"
            #include "shared/Vector.H"
            #include "shared/FileManager.H"

            virtual ~catalyticReactors();

            virtual void input();
            virtual void read();
            virtual void recap();
            virtual void propertiesShow();
            virtual void catalystPropertiesShow();
            virtual void save();
            virtual void run();
            virtual void plot();

            void exit();
            void availableSpecies();
            void savedMessage();
            void composition();
            void coverage();
            void compositionReader();
            void coverageReader();
            void checkComposition(unsigned int i);
            void checkCoverage(unsigned int i);
            void kineticShow();
            void kineticReader();
            void switchTo();

            void bar(const double fraction,const std::string tm);

            #if ASALI_USING_CANTERA==1
            void setChemistryInterface(ASALI::canteraInterface* chemistryInterface);
            #else
            void setChemistryInterface(ASALI::asaliInterface*   chemistryInterface);
            #endif

            unsigned int specieIndex(const std::string n, const std::vector<std::string> v);

            std::string getBeer();
            std::string getBeerShort();
            std::string convertToTimeFormat(double t);
            
            std::vector<std::string> splitString(const std::string txt, std::string ch);
            
            Gtk::Box          coverageBox_;
            
            Gtk::Button       helpButton_;
            Gtk::Button       nextButton1_;
            Gtk::Button       backButton1_;
            Gtk::Button       nextButton2_;
            Gtk::Button       backButton2_;
            Gtk::Button       runButton_;
            Gtk::Button       saveButton_;
            Gtk::Button       asaliPropertiesButton_;
            Gtk::Button       asaliKineticButton_;
            Gtk::Button       asaliPlotButton_;
            
            Gtk::Grid         inputGrid_;
            Gtk::Grid         coverageGrid_;
            
            Gtk::Label        tempLabel_;
            Gtk::Label        pressLabel_;
            Gtk::Label        fractionLabel_;
            Gtk::Label        kineticLabel_;
            Gtk::Label        coverageLabel_;

            Gtk::Entry        tempEntry_;
            Gtk::Entry        pressEntry_;
            
            Gtk::ComboBoxText tempCombo_;
            Gtk::ComboBoxText pressCombo_;
            Gtk::ComboBoxText fractionCombo_;
            Gtk::ComboBoxText kineticCombo_;
            
            std::vector<Gtk::Entry *> nameEntry_;
            std::vector<Gtk::Entry *> fractionEntry_;
            std::vector<Gtk::Entry *> coverageNameEntry_;
            std::vector<Gtk::Entry *> coverageFractionEntry_;
            
            unsigned int OP_;
            unsigned int NS_;
            unsigned int SURF_NS_;
            
            double       T_;
            double       p_;

            std::pair<unsigned int,bool>  checkComposition_;
            std::pair<unsigned int,bool>  checkCoverage_;

            std::vector<double>      x_;
            std::vector<double>      xc_;

            std::vector<int>      index1_;
            std::vector<int>      index2_;
            std::vector<int>      canteraIndex_;
            
            std::vector<std::vector<int> >    stoich_;


            std::vector<std::string>  n_;
            std::vector<std::string>  nc_;
            std::vector<std::string>  beer_;
            std::vector<std::string>  beerShort_;

            #if ASALI_USING_CANTERA==1
            ASALI::canteraInterface        *chemistryInterface_;
            #else
            ASALI::asaliInterface          *chemistryInterface_;
            #endif

            ASALI::speciesPopup            *speciesNames_;
            ASALI::asaliProperties         *asaliProperties_;
            ASALI::asaliCatalystProperties *asaliCatalystProperties_;
            ASALI::asaliPlot               *asaliPlot_;
            ASALI::runBar                  *bar_;
            ASALI::pythonInterface         *pi_;

            std::string kineticType_;
            std::string inert_;

            sigc::connection signal;

        private:


    };
}

#endif
