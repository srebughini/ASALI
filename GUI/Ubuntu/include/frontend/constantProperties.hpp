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

#ifndef CONSTANTPROPERTIES_H
#define CONSTANTPROPERTIES_H

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
#include <random>

namespace ASALI
{
    class constantProperties : public Gtk::Window
    {
    public:
        #include "shared/UnitConversion.H"
        #include "shared/FileManager.H"

        constantProperties();

        void destroy();
        void build();
        void savedMessage();
        void setType(const std::string type);
        void setSpeciesNames(const std::vector<std::string> n);
        void setReactions(const unsigned int Nhom, const unsigned int Nhet);
        void setEnergy(const std::string energy);

        void doneInput();
        void convertToCaption(std::string &n);

        std::vector<double> getMassFraction(const std::vector<double> MW, const std::vector<double> x);
        std::vector<double> getMoleFraction(const std::vector<double> MW, const std::vector<double> y);
        double getMWmix(const std::vector<double> MW, const std::vector<double> x);

        inline std::vector<double> getMW() { return MW_; };
        inline std::vector<double> getDiffMix() { return diff_; };
        inline std::vector<double> getHomogeneousHeatOfReaction() { return Qhom_; };
        inline std::vector<double> getHeterogeneousHeatOfReaction() { return Qhet_; };

        inline std::vector<std::string> names() { return n_; };

        inline double getCpMassMix() { return cp_; };
        inline double getCondMix() { return cond_; };
        inline double getMuMix() { return mu_; };

        inline unsigned int numberOfGasSpecies() { return n_.size(); }

        inline std::string get_type() { return type_; };

        virtual ~constantProperties();

    private:
        std::string getBeer();

        Gtk::Image batchLogo_;
        Gtk::Image ph1dLogo_;
        Gtk::Image het1dLogo_;
        Gtk::Image pelletLogo_;

        Gtk::Box mainBox_;
        Gtk::Box heatBox_;
        Gtk::Box diffBox_;

        Gtk::Grid mainGrid_;
        Gtk::Grid cpGrid_;
        Gtk::Grid condGrid_;

        Gtk::Label nameLabel_;
        Gtk::Label mwLabel_;
        Gtk::Label diffLabel_;
        Gtk::Label reactionLabel_;
        Gtk::Label heatLabel_;
        Gtk::Label cpLabel_;
        Gtk::Label condLabel_;
        Gtk::Label muLabel_;

        Gtk::Button doneButton_;

        Gtk::ComboBoxText heatCombo_;
        Gtk::ComboBoxText cpCombo_;
        Gtk::ComboBoxText condCombo_;
        Gtk::ComboBoxText diffCombo_;
        Gtk::ComboBoxText muCombo_;

        Gtk::Entry cpEntry_;
        Gtk::Entry condEntry_;
        Gtk::Entry muEntry_;

        std::vector<Gtk::Label *> speciesNameLabel_;
        std::vector<Gtk::Label *> reactionNumberLabel_;

        std::vector<Gtk::Entry *> speciesMwEntry_;
        std::vector<Gtk::Entry *> speciesDiffEntry_;
        std::vector<Gtk::Entry *> speciesHeatEntry_;

        unsigned int NR_;
        unsigned int Nhom_;
        unsigned int Nhet_;
        unsigned int NC_;

        std::vector<std::string> n_;
        std::vector<std::string> beer_;
        std::vector<std::string> small;
        std::vector<std::string> big;

        std::vector<double> MW_;
        std::vector<double> diff_;
        std::vector<double> Qhom_;
        std::vector<double> Qhet_;

        std::string type_;
        std::string energy_;

        double cp_;
        double cond_;
        double mu_;
    };
}
#endif
