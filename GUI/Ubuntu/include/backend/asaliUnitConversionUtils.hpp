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
	/// Class to convert unit dimensions
	class asaliUnitConversionUtils
	{
	public:
		/// Class constructor
		asaliUnitConversionUtils();

		/// Convert length to [m]
		void toMeter(double &v, std::string m);

		/// Convert weight to [kg]
		void toKg(double &v, std::string m);

		/// Convert to [W/m/K]
		void toWattPerMeterPerKelvin(double &v, std::string m);

		/// Convert to [kg/m3]
		void toKgPerCubeMeter(double &v, std::string m);

		/// Convert to [J/kg/K]
		void toJoulePerKgPerKelvin(double &v, std::string m);

		/// Convert to [Pa/s]
		void toPascalPerSecond(double &v, std::string m);

		/// Convert time to [s]
		void toSecond(double &v, std::string m);

		/// Convert pressure to [Pa]
		void toPascal(double &v, std::string m);

		/// Convert temperature to [K]
		void toKelvin(double &v, std::string m);

		/// Convert volume to [m3]
		void toCubeMeter(double &v, std::string m);

		/// Convert volume to [Sm3]
		void toSquareMeter(double &v, std::string m);

		/// Convert to [1/m]
		void toOneOverMeter(double &v, std::string m);

		/// Convert speed to [m/s]
		void toMeterPerSecond(double &v, std::string m);

		/// Convert flow rate to [m3/s]
		void toCubeMeterPerSecond(double &v, std::string m);

		/// Convert pressure from [Pa] to another unit dimension
		void fromPascal(double &v, std::string m);

		/// Convert length from [m] to another unit dimension
		void fromMeter(double &v, std::string m);

		/// Class destructor
		virtual ~asaliUnitConversionUtils();
	};
}

#endif
