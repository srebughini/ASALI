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

#ifndef ASALIVECTORUTILS_H
#define ASALIVECTORUTILS_H

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
#include <climits>
#include <numeric>
#include <functional>
#include <float.h>

namespace ASALI
{
    /// Class to handle vectors
    class asaliVectorUtils
    {
    public:
        /// Class constructor
        asaliVectorUtils();

        /// Get maximum value of std::vector<double>
        static double MaxElement(const std::vector<double> v);

        /// Get minimum value of std::vector<double>
        static double MinElement(const std::vector<double> v);

        /// Get the sum of all elements of std::vector<double>
        static double SumElements(const std::vector<double> v);

        /// Get dot product of two std::vector<double> vectors
        static double DotProduct(const std::vector<double> a, const std::vector<double> b);

        /// Get mean value of std::vector<double>
        double MeanValue(const std::vector<double> v);

        /// Get maximum value of std::vector<int>
        static int MaxElement(const std::vector<int> v);

        /// Get minimum value of std::vector<int>
        static int MinElement(const std::vector<int> v);

        /// Get element by element product of two std::vector<double> vectors
        static std::vector<double> ElementByElementProduct(const std::vector<double> a, const std::vector<double> b);

        /// Class destructor
        virtual ~asaliVectorUtils();
    };
}

#endif
