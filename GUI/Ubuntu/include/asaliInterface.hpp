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

#ifndef ASALIINTERFACE_H
#define ASALIINTERFACE_H
#include "basicInterface.hpp"
#include "Asali.hpp"

namespace ASALI
{
    class asaliInterface : public ASALI::basicInterface
    {
        public:
            asaliInterface();

            virtual void setTemperature(const double T);
            virtual void setPressure(const double p);
            virtual void setMoleFraction(const std::vector<double> x,const std::vector<std::string> name);
            virtual void setMassFraction(const std::vector<double> y,const std::vector<std::string> name);
            virtual void setStateFromMassFraction(const double* y, const double T, const double p);
            virtual void setStateFromMoleFraction(const double* x, const double T, const double p);

            virtual void thermoCalculate();
            virtual void transportCalculate();
            virtual void vacuumCalculate();

            virtual double getTemperature();
            virtual double getDensity();
            virtual double getCpMassMix();
            virtual double getCpMoleMix();
            virtual double getMWmix();

            virtual std::vector<double> getMW();
            virtual std::vector<double> getHmole();
            virtual std::vector<double> getSmole();
            virtual std::vector<double> getCpMole();

            virtual std::vector<int>  checkNames(std::vector<std::string>& name);
            virtual int               checkNames(std::string name);
            virtual unsigned int      numberOfGasSpecies();
            virtual unsigned int      numberOfSurfaceSpecies();

            virtual ~asaliInterface();
            
        private:

            ASALI::Asali *asali_;
            
            std::vector<std::string> names_;
    };
}

#endif
