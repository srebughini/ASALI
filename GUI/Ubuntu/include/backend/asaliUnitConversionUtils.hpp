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
#include <gtkmm.h>

namespace ASALI
{
	/// Class to convert unit dimensions
	class asaliUnitConversionUtils
	{
	public:
		/// Class constructor
		asaliUnitConversionUtils();

		/// Convert length to [m]
		static void toMeter(double &v, std::string m);

		/// Convert length from [m] to another unit dimension
		static void fromMeter(double &v, std::string m);

		/// Convert weight to [kg]
		static void toKg(double &v, std::string m);

		/// Convert to [W/m/K]
		static void toWattPerMeterPerKelvin(double &v, std::string m);

		/// Convert from [W/m/K] to another unit dimension
		static void fromWattPerMeterPerKelvin(double &v, std::string m);

		/// Convert to [kg/m3]
		static void toKgPerCubeMeter(double &v, std::string m);

		/// Convert to [J/kg/K]
		static void toJoulePerKgPerKelvin(double &v, std::string m);

		/// Convert from [J/kmol/K] to another unit dimension
		static void fromJoulePerKmolePerKelvin(double &v, std::string m, double mw);

		/// Convert to [Pa/s]
		static void toPascalPerSecond(double &v, std::string m);

		/// Convert from [Pa/s] to another unit dimension
		static void fromPascalPerSecond(double &v, std::string m);

		/// Convert time to [s]
		static void toSecond(double &v, std::string m);

		/// Convert pressure to [Pa]
		static void toPascal(double &v, std::string m);

		/// Convert pressure from [Pa] to another unit dimension
		static void fromPascal(double &v, std::string m);

		/// Convert temperature to [K]
		static void toKelvin(double &v, std::string m);

		/// Convert volume to [m3]
		static void toCubeMeter(double &v, std::string m);

		/// Convert volume to [Sm3]
		static void toSquareMeter(double &v, std::string m);

		/// Convert to [1/m]
		static void toOneOverMeter(double &v, std::string m);

		/// Convert speed to [m/s] to another unit dimension
		static void toMeterPerSecond(double &v, std::string m);

		/// Convert speed from [m/s]
		static void fromMeterPerSecond(double &v, std::string m);

		/// Convert flow rate to [m3/s]
		static void toCubeMeterPerSecond(double &v, std::string m);

		/// Convert diffusion to [m2/s]
		static void toSquareMeterPerSecond(double &v, std::string m);

		/// Convert diffusion from [m2/s] to another unit dimension
		static void fromSquareMeterPerSecond(double &v, std::string m);

		/// Convert to [J/kmol]
		static void toJoulePerKmole(double &v, std::string m, double mw);

		/// Convert to [J/kmol]
		static void toJoulePerKmole(double &v, std::string m);

		/// Convert from [J/kmol] to another unit dimension
		static void fromJoulePerKmole(double &v, std::string m, double mw);

		/// Update unit dimensions box
		void updateBox(Gtk::ComboBoxText &box, std::string variable);

		/// Class destructor
		virtual ~asaliUnitConversionUtils();

	private:
		std::vector<std::string> lengthUd_;		   /// Length unit dimensions vector
		std::vector<std::string> weigthUd_;		   /// Weigth unit dimensions vector
		std::vector<std::string> condUd_;		   /// Thermal conductivity unit dimensions vector
		std::vector<std::string> densityUd_;	   /// Density unit dimensions vector
		std::vector<std::string> cpUd_;			   /// Specific heat unit dimensions vector
		std::vector<std::string> cpMassUd_;		   /// Specific heat only mass unit dimensions vector
		std::vector<std::string> muUd_;			   /// Viscosity unit dimensions vector
		std::vector<std::string> timeUd_;		   /// Time unit dimensions vector
		std::vector<std::string> pressUd_;		   /// Pressure unit dimensions vector
		std::vector<std::string> tempUd_;		   /// Temperature unit dimensions vector
		std::vector<std::string> volumeUd_;		   /// Volume unit dimensions vector
		std::vector<std::string> areaUd_;		   /// Area unit dimensions vector
		std::vector<std::string> inverseLengthUd_; /// Inverse length unit dimensions vector
		std::vector<std::string> speedUd_;		   /// Speed unit dimensions vector
		std::vector<std::string> flowUd_;		   /// Flow rate unit dimensions vector
		std::vector<std::string> fractionUd_;	   /// Mass/mole fraction unit dimensions
		std::vector<std::string> diffUd_;		   /// Diffusion unit dimensions vector
		std::vector<std::string> hUd_;			   /// Enthalpy unit dimensions vector
		std::vector<std::string> sUd_;			   /// Entropy unit dimensions vector
		std::vector<std::string> heatUd_;		   /// Heat unit dimensions vector
	};
}

#endif
