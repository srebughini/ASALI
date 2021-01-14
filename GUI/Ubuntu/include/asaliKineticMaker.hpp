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

#ifndef ASALIKINETICMAKER_H
#define ASALIKINETICMAKER_H

#include <gtkmm.h>
#include "canteraInterface.hpp"
#include "beerQuote.hpp"
#include "asaliVectorUtils.hpp"
#include "asaliFileManager.hpp"

namespace ASALI
{
    class asaliKineticMaker : public Gtk::Window
    {
        public:
            asaliKineticMaker();

            void species();
            void reactionNumber();
            void reaction();
            void equation();
            void recap();
            void save();
            void exit();

            virtual ~asaliKineticMaker();
            
        private:
            Gtk::Box          reactionNumberBox_;
            Gtk::Box          speciesBox_;
            Gtk::Box          reactionBox_;
            Gtk::Box          equationBox_;
            Gtk::Box          recapBox_;
            
            Gtk::Button       exitButton1_;
            Gtk::Button       exitButton2_;
            Gtk::Button       nextButton1_;
            Gtk::Button       nextButton2_;
            Gtk::Button       nextButton3_;
            Gtk::Button       nextButton4_;
            Gtk::Button       backButton1_;
            Gtk::Button       backButton2_;
            Gtk::Button       backButton3_;
            Gtk::Button       backButton4_;
            Gtk::Button       saveButton_;
            Gtk::Button       reactionHelpButton_;
            Gtk::Button       equationHelpButton_;
            
            Gtk::Grid         reactionNumberGrid_;
            Gtk::Grid         speciesGrid_;
            Gtk::Grid         reactionGrid_;
            Gtk::Grid         equationGrid_;
            Gtk::Grid         recapSpeciesGrid_;
            Gtk::Grid         recapReactionGrid_;
            
            Gtk::Label        reactionNumberLabel_;
            Gtk::Label        speciesLabel_;
            Gtk::Label        numberLabel1_;
            Gtk::Label        numberLabel2_;
            Gtk::Label        expressionLabel1_;
            Gtk::Label        expressionLabel2_;
            Gtk::Label        typeLabel1_;
            Gtk::Label        recapSpeciesLabel_;
            Gtk::Label        recapReactionLabel_;

            Gtk::ComboBoxText reactionNumberCombo_;
        
            Gtk::Image        logo1_;
            Gtk::Image        logo2_;
            Gtk::Image        logo3_;
            Gtk::Image        logo4_;
            Gtk::Image        logo5_;
            
            std::vector<Gtk::Label *>         reactionLabel_;
            std::vector<Gtk::Label *>         equationLabel_;
            std::vector<Gtk::Label *>         recapSpeciesVectorLabel_;
            std::vector<Gtk::Label *>         recapReactionVectorLabel_;
            std::vector<Gtk::Label *>         recapEquationVectorLabel_;
            std::vector<Gtk::Label *>         recapTypeVectorLabel_;

            std::vector<Gtk::ComboBoxText *>  reactionCombo_;
            

            std::vector<Gtk::Entry *>         speciesEntry_;
            std::vector<Gtk::Entry *>         reactionEntry_;
            std::vector<Gtk::Entry *>         equationEntry_;

            std::vector<std::string>  n_;
            std::vector<std::string>  Rhet_;
            std::vector<std::string>  Rhom_;
            std::vector<std::string>  Rtot_;
            std::vector<std::string>  r_;
            std::vector<std::string>  t_;
            std::vector<std::string>  op_;

            Cantera::ThermoPhase      *thermo_;
            Cantera::Transport        *transport_;
            ASALI::canteraInterface   *canteraInterface_;
            ASALI::beerQuote          *beerQuote_;
            ASALI::asaliVectorUtils   *vectorUtils_;
            ASALI::asaliFileManager   *fileManager_;

            unsigned int NR_;
            unsigned int NC_;
            
            
            bool restart_;
            
            
            std::vector<std::vector<double> > shet_;
            std::vector<std::vector<double> > shom_;

            void updateLayout();
            void savedMessage();
            void missingSpecies(const std::string n);
            void unknownOption(const std::string n);
            void errorEquation(const std::string error);
            void helpReaction();
            void helpEquation();
            void replaceString(std::string& str, const std::string from, const std::string to);

            bool readStoichiometryCoefficient(unsigned int index);
            bool checkReaction();
            bool checkEquation();
            bool checkSpecies();
            
            std::vector<std::string> splitString(const std::string txt, std::string ch);

            int getSpecieIndex(std::string n, std::vector<std::string> nv);
    };
}

#endif
