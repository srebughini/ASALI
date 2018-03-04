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

void ConvertsToMeter(double &v, std::string m)
{
    m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

    m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

    if (m == "m")
        v=v;
    else if(m == "\u03BCm")
        v*=0.000001;
    else if(m == "mm")
        v*=0.001;
    else if(m == "cm")
        v*=0.01;
    else if(m == "dm")
        v*=0.1;
    else if(m == "nm")
        v*=1e-09;
    else if(m == "pm")
        v*=1e-09;
    else if(m == "km")
        v*=1000.;
}


void ConvertsToKg(double &v, std::string m)
{
    m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

    if (m == "kg")
        v=v;
    else if(m == "g")
        v*=1.e-03;
    else if(m == "mg")
        v*=1.e-06;
}


void ConvertsToSecond(double &v, std::string m)
{
    m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

    if (m == "s")
        v=v;
    else if(m == "h")
        v*=3600.;
    else if(m == "min")
        v*=60.;
    else if(m == "d")
        v=v*24.*3600.;
    else if(m == "y")
        v=v*24.*365.*3600.;
    else if(m == "ms")
        v*=1.e-03;
}


void ConvertsToPascal(double &v, std::string m)
{
    m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

    if (m == "Pa")
        v=v;
    else if(m == "bar")
        v*=1.e05;
    else if(m == "kPa")
        v*=1.e03;
    else if(m == "MPa")
        v*=1.e06;
    else if(m == "GPa")
        v*=1.e09;
    else if(m == "atm")
        v=v*101325.;
    else if(m == "mmHg")
        v=v*101325./760.;
    else if(m == "torr")
        v=v*101325./760.;
    else if (m == "mbar")
        v=v*1.e05*1e-03;
}


void ConvertsToKelvin(double &v, std::string m)
{
    m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

    if (m == "K")
        v=v;
    else if (m == "°C")
        v = v + 273.15;
    else if (m == "°F")
        v = (v + 459.67)*5./9.;
}

void ConvertsToCubeMeter(double &v, std::string m)
{
    m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

    m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

    if (m == "m\u00b3")
        v=v;
    else if(m == "mm\u00b3")
        v*=1e-09;
    else if(m == "cm\u00b3")
        v*=1e-06;
    else if(m == "dm\u00b3")
        v*=1e-03;
    else if(m == "l")
        v*=1e-03;
    else if(m == "cc")
        v*=1e-06;
}

void ConvertsToSquareMeter(double &v, std::string m)
{
    m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

    m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

    if (m == "m\u00b2")
        v=v;
    else if(m == "mm\u00b2")
        v*=1e-06;
    else if(m == "cm\u00b2")
        v*=1e-04;
    else if(m == "dm\u00b2")
        v*=1e-02;
}

void ConvertsToOneOverMeter(double &v, std::string m)
{
    m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

    m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

    if (m == "1/m")
        v=v;
    else if(m == "1/dm")
        v*=1e01;
    else if(m == "1/cm")
        v*=1e02;
    else if(m == "1/mm")
        v*=1e03;
}

void ConvertsToMeterPerSecond(double &v, std::string m)
{
    m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

    m.erase(std::remove(m.begin(), m.end(), ' '), m.end());

    if (m == "m/s")
        v=v;
    else if(m == "dm/s")
        v*=1e-01;
    else if(m == "cm/s")
        v*=1e-02;
    else if(m == "mm/s")
        v*=1e-03;
    else if(m == "m/min")
        v*=1e-01/60;
    else if(m == "dm/min")
        v*=1e-01/60;
    else if(m == "cm/min")
        v*=1e-02/60;
    else if(m == "mm/min")
        v*=1e-03/60;
    else if(m == "m/h")
        v*=1e-01/3600;
    else if(m == "dm/h")
        v*=1e-01/3600;
    else if(m == "cm/h")
        v*=1e-02/3600;
    else if(m == "mm/h")
        v*=1e-03/3600;
}
