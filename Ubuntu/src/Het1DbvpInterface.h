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

#ifndef HET1DBVPINTERFACE_H
#define HET1DBVPINTERFACE_H

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

#include <ida/ida.h>
#include <ida/ida_dense.h>
#include <ida/ida_band.h>
#include <nvector/nvector_serial.h>
#include <sundials/sundials_math.h>
#include <sundials/sundials_dense.h>
#include <sundials/sundials_types.h>

#include "Het1DEquations.h"

namespace ASALI
{
    #define Ith(v,i)    NV_Ith_S(v,i-1)

    class Het1DbvpInterface : public Gtk::Window
    {
        public:

            Het1DbvpInterface();

            int solve(const double tf, std::vector<double>& yf);

            void setEquations(ASALI::Het1DEquations* eq);

            void setInitialConditions(double t0, std::vector<double> y0);

            void setAlgebraic(const std::vector<bool> algebraic);

            void setTollerance(const double absTol, const double relTol);

            void setBandDimensions(const double upperBand, const double lowerBand);
            
            void setConstraints(const bool constraints);
            
            bool check()            {return check_;};
            void start()            {check_ = true;};

            ~Het1DbvpInterface(void);

        private:

            void *ida_mem_;

            int NEQ_;

            double relTol_;
            double absTol_;
            double upperBand_;
            double lowerBand_;
            double t0_;
            
            bool   check_;

            std::vector<bool>  algebraic_;
            
            bool constraints_;

            N_Vector yIDA_;
            N_Vector dyIDA_;
            N_Vector y0IDA_;
            N_Vector dy0IDA_;
            N_Vector algebraicIDA_;

            std::vector<std::string> beer_;

            ASALI::Het1DEquations* eq_;

            int         checkFlag(void *flagvalue, const char *funcname, int opt);
            void        error();
            std::string getBeer();
    };
}

#endif
