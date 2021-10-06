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
	asaliUnitConversionUtils::asaliUnitConversionUtils() : lengthUd_({"m", "\u03BCm", "mm", "cm", "dm", "nm", "km", "pm"}),
														   weigthUd_({"kg", "g", "mg"}),
														   condUd_({"W/m/K", "kW/m/K", "cal/m/s/K"}),
														   densityUd_({"kg/m\u00b3", "g/cc"}),
														   cpUd_({"J/kg/K", "kJ/kg/K", "J/kmol/K", "J/mol/K", "cal/mol/K", "cal/kmol/K", "cal/kg/K"}),
														   cpMassUd_({"J/kg/K", "kJ/kg/K", "cal/kg/K"}),
														   muUd_({"Pas", "cP", "P"}),
														   timeUd_({"s", "h", "min", "d", "y", "ms"}),
														   pressUd_({"Pa", "bar", "kPa", "MPa", "GPa", "atm", "mmHg", "torr", "mbar"}),
														   tempUd_({"K", "°C", "F"}),
														   volumeUd_({"m\u00b3", "mm\u00b3", "cm\u00b3", "dm\u00b3", "l", "cc"}),
														   areaUd_({"m\u00b2", "mm\u00b2", "cm\u00b2", "dm\u00b2"}),
														   inverseLengthUd_({"1/m", "1/cm", "1/dm"}),
														   speedUd_({"m/s", "dm/s", "cm/s", "mm/s", "m/min", "dm/min", "cm/min", "mm/min", "m/h", "dm/h", "cm/h", "mm/h"}),
														   flowUd_({"m\u00b3/s", "mm\u00b3/s", "cm\u00b3/s", "dm\u00b3/s", "l/s", "cc/s", "m\u00b3/min", "mm\u00b3/min", "cm\u00b3/min", "dm\u00b3/min", "l/min", "cc/min", "m\u00b3/h", "mm\u00b3/h", "cm\u00b3/h", "dm\u00b3/h", "l/h", "cc/h"}),
														   fractionUd_({"Mass fraction", "Mole fraction"}),
														   diffUd_({"m\u00b2/s", "dm\u00b2/s", "cm\u00b2/s", "mm\u00b2/s"}),
														   hUd_({"J/kmol", "J/mol", "J/kg", "cal/kmol", "cal/mol", "cal/kg"}),
														   sUd_({"J/kmol/K", "J/mol/K", "J/kg/K", "cal/kmol/K", "cal/mol/K", "cal/kg/K"}),
														   heatUd_({"J/kmol", "J/mol", "kJ/mol", "cal/kmol", "cal/mol", "kcal/mol"})
	{
	}

	void asaliUnitConversionUtils::toMeter(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "\u03BCm")
			v *= 0.000001;
		else if (m == "mm")
			v *= 0.001;
		else if (m == "cm")
			v *= 0.01;
		else if (m == "dm")
			v *= 0.1;
		else if (m == "nm")
			v *= 1e-09;
		else if (m == "pm")
			v *= 1e-12;
		else if (m == "km")
			v *= 1000.;
	}

	void asaliUnitConversionUtils::fromMeter(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "\u03BCm")
			v = v / 0.000001;
		else if (m == "mm")
			v = v / 0.001;
		else if (m == "cm")
			v = v / 0.01;
		else if (m == "dm")
			v = v / 0.1;
		else if (m == "nm")
			v = v / 1e-09;
		else if (m == "pm")
			v = v / 1e-12;
		else if (m == "km")
			v = v / 1000.;
	}

	void asaliUnitConversionUtils::toKg(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "g")
			v *= 1.e-03;
		else if (m == "mg")
			v *= 1.e-06;
	}

	void asaliUnitConversionUtils::toWattPerMeterPerKelvin(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "kW/m/K")
			v *= 1e03;
		else if (m == "cal/m/s/K")
			v *= 4.186;
	}

	void asaliUnitConversionUtils::fromWattPerMeterPerKelvin(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "kW/m/K")
			v = v / 1e03;
		else if (m == "cal/m/s/K")
			v = v / 4.186;
	}

	void asaliUnitConversionUtils::toKgPerCubeMeter(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "g/cc")
			v *= 1e03;
	}

	void asaliUnitConversionUtils::toJoulePerKgPerKelvin(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "kJ/kg/K")
			v *= 1e03;
	}

	void asaliUnitConversionUtils::fromJoulePerKmolePerKelvin(double &v, std::string m, double mw)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "J/mol/K")
			v = v / 1e03;
		else if (m == "cal/kmol/K")
			v = v / 4.186;
		else if (m == "cal/mol/K")
			v = v / (1e03 * 4.186);
		else if (m == "J/kg/K")
			v = v / mw;
		else if (m == "KJ/kg/K")
			v = v * 1e-03 / mw;
		else if (m == "cal/kg/K")
			v = v / (mw * 4.186);
	}

	void asaliUnitConversionUtils::toPascalPerSecond(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "cP")
			v *= 0.001;
		else if (m == "P")
			v *= 0.1;
	}

	void asaliUnitConversionUtils::fromPascalPerSecond(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "cP")
			v = v / 0.001;
		else if (m == "P")
			v = v / 0.1;
	}

	void asaliUnitConversionUtils::toSecond(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "h")
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

		if (m == "bar")
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

		if (m == "bar")
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

		if (m == "°C")
			v = v + 273.15;
		else if (m == "°F")
			v = (v + 459.67) * 5. / 9.;
	}

	void asaliUnitConversionUtils::toCubeMeter(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "mm\u00b3")
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

		if (m == "mm\u00b2")
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

		if (m == "1/dm")
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

		if (m == "dm/s")
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

	void asaliUnitConversionUtils::fromMeterPerSecond(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "dm/s")
			v = v / 1e-01;
		else if (m == "cm/s")
			v = v / 1e-02;
		else if (m == "mm/s")
			v = v / 1e-03;
		else if (m == "m/min")
			v = v * 60;
		else if (m == "dm/min")
			v = v * 60 / 1e-01;
		else if (m == "cm/min")
			v = v * 60 / 1e-02;
		else if (m == "mm/min")
			v = v * 60 / 1e-03;
		else if (m == "m/h")
			v = v * 3600;
		else if (m == "dm/h")
			v = v * 3600 / 1e-01;
		else if (m == "cm/h")
			v = v * 3600 / 1e-02;
		else if (m == "mm/h")
			v = v * 3600 / 1e-03;
	}

	void asaliUnitConversionUtils::toCubeMeterPerSecond(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "mm\u00b3/s")
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

	void asaliUnitConversionUtils::toSquareMeterPerSecond(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "mm\u00b2/s")
			v *= 1e-06;
		else if (m == "cm\u00b2/s")
			v *= 1e-04;
		else if (m == "dm\u00b2/s")
			v *= 1e-02;
	}

	void asaliUnitConversionUtils::fromSquareMeterPerSecond(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "mm\u00b2/s")
			v = v / 1e-06;
		else if (m == "cm\u00b2/s")
			v = v / 1e-04;
		else if (m == "dm\u00b2/s")
			v = v / 1e-02;
	}

	void asaliUnitConversionUtils::fromJoulePerKmole(double &v, std::string m, double mw)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "J/mol")
			v = v / 1e03;
		else if (m == "cal/kmol")
			v = v / 4.186;
		else if (m == "cal/mol")
			v = v / (1e03 * 4.186);
		else if (m == "J/kg")
			v = v / mw;
		else if (m == "KJ/kg")
			v = v * 1e-03 / mw;
		else if (m == "cal/kg")
			v = v / (mw * 4.186);
	}

	void asaliUnitConversionUtils::toJoulePerKmole(double &v, std::string m, double mw)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "J/mol")
			v = v * 1e03;
		else if (m == "cal/kmol")
			v = v * 4.186;
		else if (m == "cal/mol")
			v = v * (1e03 * 4.186);
		else if (m == "J/kg")
			v = v * mw;
		else if (m == "KJ/kg")
			v = v * mw / 1e-03;
		else if (m == "cal/kg")
			v = v * (mw * 4.186);
	}

	void asaliUnitConversionUtils::toJoulePerKmole(double &v, std::string m)
	{
		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

		if (m == "J/mol")
			v = v * 1e03;
		else if (m == "cal/kmol")
			v = v * 4.186;
		else if (m == "cal/mol")
			v = v * (1e03 * 4.186);
	}

	void asaliUnitConversionUtils::updateBox(Gtk::ComboBoxText &box, const std::string &variable)
	{
		std::vector<std::string> ud;
		if (variable == "temperature")
			ud = tempUd_;
		else if (variable == "pressure")
			ud = pressUd_;
		else if (variable == "fraction")
			ud = fractionUd_;
		else if (variable == "length")
			ud = lengthUd_;
		else if (variable == "speed")
			ud = speedUd_;
		else if (variable == "diffusion")
			ud = diffUd_;
		else if (variable == "conductivity")
			ud = condUd_;
		else if (variable == "viscosity")
			ud = muUd_;
		else if (variable == "enthalpy")
			ud = hUd_;
		else if (variable == "entropy")
			ud = sUd_;
		else if (variable == "specificheat")
			ud = cpUd_;
		else if (variable == "specificheatonlymass")
			ud = cpMassUd_;
		else if (variable == "volume")
			ud = volumeUd_;
		else if (variable == "inverselength")
			ud = inverseLengthUd_;
		else if (variable == "time")
			ud = timeUd_;
		else if (variable == "density")
			ud = densityUd_;
		else if (variable == "heat")
			ud = heatUd_;

		box.remove_all();
		for (unsigned int i = 0; i < ud.size(); i++)
		{
			box.append(ud[i]);
		}
		box.set_active(0);
	}
}
