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

#include "backend/pythonInterface.hpp"
#include "backend/asaliUnitConversionUtils.hpp"
#include "backend/asaliVectorUtils.hpp"
#include "backend/asaliFileManager.hpp"
#include "backend/beerQuote.hpp"
#include "frontend/speciesPopup.hpp"
#include "frontend/constantProperties.hpp"
#include "frontend/catalystProperties.hpp"
#include "frontend/plot.hpp"
#include "frontend/runBar.hpp"
#include <random>

#if ASALI_USING_CANTERA == 1
#include "backend/canteraInterface.hpp"
#else
#include "backend/asaliInterface.hpp"
#endif

namespace ASALI
{
        class catalyticReactors : public Gtk::Window
        {
        public:
                explicit catalyticReactors(const std::string &kineticType);

                virtual ~catalyticReactors();

                virtual void input() = 0;
                virtual void read() = 0;
                virtual void recap() = 0;
                virtual void propertiesShow() = 0;
                virtual void save() = 0;
                virtual void run() = 0;
                virtual void plot() = 0;

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

                void bar(const double &fraction, const std::string &tm);

#if ASALI_USING_CANTERA == 1
                void setChemistryInterface(ASALI::canteraInterface *chemistryInterface);
#else
                void setChemistryInterface(ASALI::asaliInterface *chemistryInterface);
#endif

                unsigned int specieIndex(const std::string &n, const std::vector<std::string> &v);
                unsigned int numberOfGasSpecies();

                std::string getBeer();
                std::string getBeerShort();
                std::string convertToTimeFormat(double t);

                std::vector<std::string> gasSpeciesNames();

                Gtk::Box coverageBox_;

                Gtk::Button helpButton_;
                Gtk::Button nextButton1_;
                Gtk::Button backButton1_;
                Gtk::Button nextButton2_;
                Gtk::Button backButton2_;
                Gtk::Button runButton_;
                Gtk::Button saveButton_;
                Gtk::Button asaliPropertiesButton_;
                Gtk::Button asaliKineticButton_;
                Gtk::Button asaliPlotButton_;

                Gtk::Grid inputGrid_;
                Gtk::Grid coverageGrid_;

                Gtk::Label tempLabel_;
                Gtk::Label pressLabel_;
                Gtk::Label fractionLabel_;
                Gtk::Label kineticLabel_;
                Gtk::Label coverageLabel_;

                Gtk::Entry tempEntry_;
                Gtk::Entry pressEntry_;

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

                double T_;
                double p_;

                std::pair<unsigned int, bool> checkComposition_;
                std::pair<unsigned int, bool> checkCoverage_;

                std::vector<double> x_;
                std::vector<double> xc_;

                std::vector<int> index1_;
                std::vector<int> index2_;
                std::vector<int> canteraIndex_;

                std::vector<std::vector<int>> stoich_;

                std::vector<std::string> n_;
                std::vector<std::string> nc_;
                std::vector<std::string> beer_;
                std::vector<std::string> beerShort_;

#if ASALI_USING_CANTERA == 1
                ASALI::canteraInterface *chemistryInterface_;
#else
                ASALI::asaliInterface *chemistryInterface_;
#endif

                ASALI::speciesPopup *speciesNames_;
                ASALI::constantProperties *constantProperties_;
                ASALI::catalystProperties *catalystProperties_;
                ASALI::plot *plot_;
                ASALI::runBar *bar_;
                ASALI::pythonInterface *pi_;
                ASALI::beerQuote *beerQuote_;
                ASALI::asaliUnitConversionUtils *unitConversion_;
                ASALI::asaliVectorUtils *vectorUtils_;

                ASALI::asaliFileManager fileManager_;

                std::string kineticType_;
                std::string inert_;

                sigc::connection signal;

        private:
        };
}
#endif
