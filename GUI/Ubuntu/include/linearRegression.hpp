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


#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H

#include "thermoProperties.hpp"

namespace ASALI
{
    class linearRegression : public ASALI::thermoProperties
    {
        public:
            linearRegression(ASALI::canteraInterface        *canteraInterface,
                             ASALI::speciesPopup            *speciesNames,
                             std::string                     kineticType);
            
            virtual ~linearRegression();

            virtual void results();

        private:
        
        
            void cleanInput();
            void uploadLayout();
            void run();
            void leastSquareFitting(const std::vector<double> x, const std::vector<double> y,double &m, double &q, double &r2);
            void condUnitDimensions(double &p);
            void muUnitDimensions(double &p);
            void cpUnitDimensions(double &p);
            void sUnitDimensions(double &p);
            void hUnitDimensions(double &p);
            void diffUnitDimensions(double &p);

            Gtk::Box          tempBox_;

            Gtk::Button       exitButton2_;
            Gtk::Button       backButton_;
            Gtk::Button       calculateButton_;
            
            Gtk::Grid         resultsGrid_;

            Gtk::Label        tempRangeLabel_;
            Gtk::Label        propertyLabel_;
            Gtk::Label        mLabel_;
            Gtk::Label        mValueLabel_;
            Gtk::Label        qLabel_;
            Gtk::Label        qValueLabel_;
            Gtk::Label        rLabel_;
            Gtk::Label        rValueLabel_;
            
            Gtk::Entry        tempEntry1_;
            Gtk::Entry        tempEntry2_;

            Gtk::ComboBoxText tempRangeCombo_;
            Gtk::ComboBoxText propertyCombo_;
            Gtk::ComboBoxText unitDimensionCombo_;
            Gtk::ComboBoxText specieCombo_;

            Gtk::Image        logo_;
            Gtk::Image        regressionImage_;
            
            std::vector<double> Tv_;
            std::vector<double> pv_;

            std::string name_;
            
            double      m_;
            double      q_;
            double      r2_;

            bool        diffCheck_;
    };
}

#endif
