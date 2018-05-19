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
#   ASALI is free software you can redistribute it and/or modify                               #
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

#ifndef PH1DODEINTERFACE_H
#define PH1DODEINTERFACE_H

#include <gtkmm.h>
#include <string>
#include <iostream>
#include <math.h>
#include <ctime>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#include <cvode/cvode.h>
#include <cvode/cvode_dense.h>
#include <cvode/cvode_band.h>
#include <nvector/nvector_serial.h>
#include <sundials/sundials_math.h>
#include <sundials/sundials_dense.h>
#include <sundials/sundials_types.h>

#include "Ph1DEquations.h"

namespace ASALI
{
    #define Ith(v,i)    NV_Ith_S(v,i-1)

    class Ph1DodeInterface  : public Gtk::Window
    {
        public:

            Ph1DodeInterface();

            int solve(const double tf, std::vector<double>& yf);

            void setEquations(ASALI::Ph1DEquations* eq);

            void setInitialConditions(double t0, std::vector<double> y0);

            void setTollerance(const double absTol, const double relTol);

            void setBandDimensions(const double upperBand, const double lowerBand);
            
            void setConstraints(const bool constraints);

            bool check()            {return check_;};
            void start()            {check_ = true;};

            ~Ph1DodeInterface(void);

        private:

            void *cvode_mem_;

            int NEQ_;

            double relTol_;
            double absTol_;
            double upperBand_;
            double lowerBand_;
            double t0_;

            bool constraints_;
            bool   check_;

            N_Vector yCVODE_;
            N_Vector dyCVODE_;
            N_Vector y0CVODE_;
            N_Vector dy0CVODE_;
            
            std::vector<std::string> beer_;

            ASALI::Ph1DEquations* eq_;

            int checkFlag(void *flagvalue, const char *funcname, int opt);
            void        error();
            std::string getBeer();
    };
}

#endif
