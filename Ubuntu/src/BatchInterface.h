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

#ifndef BATCHINTERFACE_H
#define BATCHINTERFACE_H

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

#include "BatchEquations.h"

namespace ASALI
{
    #define Ith(v,i)    NV_Ith_S(v,i-1)

    class BatchInterface 
    {
        public:

            BatchInterface();

            int solve(const double tf, std::vector<double>& yf);

            void setEquations(ASALI::BatchEquations* eq);

            void setInitialConditions(double t0, std::vector<double> y0);

            void setTollerance(const double absTol, const double relTol);

            void setBandDimensions(const double upperBand, const double lowerBand);
            
            void setConstraints(const bool constraints);

            ~BatchInterface(void);

        private:

            void *cvode_mem_;

            int NEQ_;

            double relTol_;
            double absTol_;
            double upperBand_;
            double lowerBand_;
            double t0_;

            bool constraints_;

            N_Vector yCVODE_;
            N_Vector dyCVODE_;
            N_Vector y0CVODE_;
            N_Vector dy0CVODE_;

            ASALI::BatchEquations* eq_;

            int checkFlag(void *flagvalue, const char *funcname, int opt);

    };
}

#endif
