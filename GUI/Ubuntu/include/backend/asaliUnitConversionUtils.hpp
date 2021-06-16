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

#ifndef ASALIUNITCONVERSIONUTILS_H
#define ASALIUNITCONVERSIONUTILS_H

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
#include <numeric>
#include <functional>


namespace ASALI
{
    class asaliUnitConversionUtils
    {
        public:
            asaliUnitConversionUtils();

			void toMeter(double &v, std::string m);
			void toKg(double &v, std::string m);
			void toWattPerMeterPerKelvin(double &v, std::string m);
			void toKgPerCubeMeter(double &v, std::string m);
			void toJoulePerKgPerKelvin(double &v, std::string m);
			void toPascalPerSecond(double &v, std::string m);
			void toSecond(double &v, std::string m);
			void toPascal(double &v, std::string m);
			void toKelvin(double &v, std::string m);
			void toCubeMeter(double &v, std::string m);
			void toSquareMeter(double &v, std::string m);
			void toOneOverMeter(double &v, std::string m);
			void toMeterPerSecond(double &v, std::string m);
			void toCubeMeterPerSecond(double &v, std::string m);

			void fromPascal(double &v, std::string m);
			void fromMeter(double &v, std::string m);

            virtual ~asaliUnitConversionUtils();
    };
}

#endif
