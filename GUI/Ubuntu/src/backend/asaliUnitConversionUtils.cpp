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

#include "backend/asaliUnitConversionUtils.hpp"

namespace ASALI
{
	asaliUnitConversionUtils::asaliUnitConversionUtils()
	{
	}

	void asaliUnitConversionUtils::toMeter(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "m")
			v = v;
		else if (m == "\u03BCm")
			v *= 0.000001;
		else if (m == "mm")
			v *= 0.001;
		else if (m == "cm")
			v *= 0.01;
		else if (m == "dm")
			v *= 0.1;
		else if (m == "nm")
			v *= 1e-09;
		else if (m == "km")
			v *= 1000.;
	}

	void asaliUnitConversionUtils::fromMeter(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "m")
			v = v;
		else if (m == "\u03BCm")
			v = v / 0.000001;
		else if (m == "mm")
			v = v / 0.001;
		else if (m == "cm")
			v = v / 0.01;
		else if (m == "dm")
			v = v / 0.1;
		else if (m == "nm")
			v = v / 1e-09;
		else if (m == "km")
			v = v / 1000.;
	}

	void asaliUnitConversionUtils::toKg(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "kg")
			v = v;
		else if (m == "g")
			v *= 1.e-03;
		else if (m == "mg")
			v *= 1.e-06;
	}

	void asaliUnitConversionUtils::toWattPerMeterPerKelvin(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "W/m/K")
			v = v;
		else if (m == "kW/m/K")
			v *= 1e03;
	}

	void asaliUnitConversionUtils::toKgPerCubeMeter(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "kg/m\u00b3")
			v = v;
		else if (m == "g/cc")
			v *= 1e03;
	}

	void asaliUnitConversionUtils::toJoulePerKgPerKelvin(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "J/kg/K")
			v = v;
		else if (m == "kJ/kg/K")
			v *= 1e03;
	}

	void asaliUnitConversionUtils::toPascalPerSecond(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "Pas")
			v = v;
		else if (m == "cP")
			v *= 0.001;
		else if (m == "P")
			v *= 0.1;
	}

	void asaliUnitConversionUtils::toSecond(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "s")
			v = v;
		else if (m == "h")
			v *= 3600.;
		else if (m == "min")
			v *= 60.;
		else if (m == "d")
			v = v * 24. * 3600.;
		else if (m == "y")
			v = v * 24. * 365. * 3600.;
		else if (m == "ms")
			v *= 1.e-03;
	}

	void asaliUnitConversionUtils::toPascal(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "Pa")
			v = v;
		else if (m == "bar")
			v *= 1.e05;
		else if (m == "kPa")
			v *= 1.e03;
		else if (m == "MPa")
			v *= 1.e06;
		else if (m == "GPa")
			v *= 1.e09;
		else if (m == "atm")
			v = v * 101325.;
		else if (m == "mmHg")
			v = v * 101325. / 760.;
		else if (m == "torr")
			v = v * 101325. / 760.;
		else if (m == "mbar")
			v = v * 1.e05 * 1e-03;
	}

	void asaliUnitConversionUtils::fromPascal(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "Pa")
			v = v;
		else if (m == "bar")
			v = v / 1.e05;
		else if (m == "atm")
			v = v / 101325.;
		else if (m == "mmHg")
			v = v * 760. / 101325;
		else if (m == "torr")
			v = v * 760. / 101325;
	}

	void asaliUnitConversionUtils::toKelvin(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "K")
			v = v;
		else if (m == "°C")
			v = v + 273.15;
		else if (m == "°F")
			v = (v + 459.67) * 5. / 9.;
	}

	void asaliUnitConversionUtils::toCubeMeter(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "m\u00b3")
			v = v;
		else if (m == "mm\u00b3")
			v *= 1e-09;
		else if (m == "cm\u00b3")
			v *= 1e-06;
		else if (m == "dm\u00b3")
			v *= 1e-03;
		else if (m == "l")
			v *= 1e-03;
		else if (m == "cc")
			v *= 1e-06;
	}

	void asaliUnitConversionUtils::toSquareMeter(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "m\u00b2")
			v = v;
		else if (m == "mm\u00b2")
			v *= 1e-06;
		else if (m == "cm\u00b2")
			v *= 1e-04;
		else if (m == "dm\u00b2")
			v *= 1e-02;
	}

	void asaliUnitConversionUtils::toOneOverMeter(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "1/m")
			v = v;
		else if (m == "1/dm")
			v *= 1e01;
		else if (m == "1/cm")
			v *= 1e02;
		else if (m == "1/mm")
			v *= 1e03;
	}

	void asaliUnitConversionUtils::toMeterPerSecond(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "m/s")
			v = v;
		else if (m == "dm/s")
			v *= 1e-01;
		else if (m == "cm/s")
			v *= 1e-02;
		else if (m == "mm/s")
			v *= 1e-03;
		else if (m == "m/min")
			v *= 1e-01 / 60;
		else if (m == "dm/min")
			v *= 1e-01 / 60;
		else if (m == "cm/min")
			v *= 1e-02 / 60;
		else if (m == "mm/min")
			v *= 1e-03 / 60;
		else if (m == "m/h")
			v *= 1e-01 / 3600;
		else if (m == "dm/h")
			v *= 1e-01 / 3600;
		else if (m == "cm/h")
			v *= 1e-02 / 3600;
		else if (m == "mm/h")
			v *= 1e-03 / 3600;
	}

	void asaliUnitConversionUtils::toCubeMeterPerSecond(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "m\u00b3/s")
			v = v;
		else if (m == "mm\u00b3/s")
			v *= 1e-09;
		else if (m == "cm\u00b3/s")
			v *= 1e-06;
		else if (m == "dm\u00b3/s")
			v *= 1e-03;
		else if (m == "l/s")
			v *= 1e-03;
		else if (m == "cc/s")
			v *= 1e-06;
		else if (m == "m\u00b3/min")
			v = v / 60.;
		else if (m == "mm\u00b3/min")
			v *= 1e-09 / 60.;
		else if (m == "cm\u00b3/min")
			v *= 1e-06 / 60.;
		else if (m == "dm\u00b3/min")
			v *= 1e-03 / 60.;
		else if (m == "l/min")
			v *= 1e-03 / 60.;
		else if (m == "cc/min")
			v *= 1e-06 / 60.;
		else if (m == "m\u00b3/h")
			v = v / 3600.;
		else if (m == "mm\u00b3/h")
			v *= 1e-09 / 3600.;
		else if (m == "cm\u00b3/h")
			v *= 1e-06 / 3600.;
		else if (m == "dm\u00b3/h")
			v *= 1e-03 / 3600.;
		else if (m == "l/h")
			v *= 1e-03 / 3600.;
		else if (m == "cc/h")
			v *= 1e-06 / 3600.;
	}

	asaliUnitConversionUtils::~asaliUnitConversionUtils()
	{
	}
}
