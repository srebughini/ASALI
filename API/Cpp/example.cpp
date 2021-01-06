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

#include "Asali.h"

int main()
{
    ASALI::Asali asali;
    std::vector<std::string> names(3);
    std::vector<double> x(3);

    names[0] = "H2";
    names[1] = "O2";
    names[2] = "N2";

    x[0] = 0.1;
    x[1] = 0.2;
    x[2] = 1. - x[0] - x[1];
    
    asali.setSpecies(names);

    asali.setTemperature(393.15); //K

    asali.setPressure(4e05); //Pa

    asali.setMoleFraction(x);

    std::cout << "Mixture molecular weight:     " << asali.mixtureMolecularWeight() << " [kg/kmol]" << std::endl;
    std::cout << "Density:                      " << asali.density() << " [kg/m3]" << std::endl;
    std::cout << "Mixture viscosity:            " << asali.mixtureViscosity() << " [Pas]" << std::endl;
    std::cout << "Mixture specific heat:        " << asali.mixtureMassCp() << " [J/kg/K]" << std::endl;
    std::cout << "Mixture specific heat:        " << asali.mixtureMolarCp() << " [J/kmol/K]" << std::endl;
    std::cout << "Mixture enthalpy:             " << asali.mixtureMassEnthalpy() << " [J/kg]" << std::endl;
    std::cout << "Mixture enthalpy:             " << asali.mixtureMolarEnthalpy() << " [J/kmol]" << std::endl;
    std::cout << "Mixture thermal conductivity: " << asali.mixtureThermalConductivity() << " [W/m/K]" << std::endl;
    std::cout << "Mixture entropy:              " << asali.mixtureMassEntropy() << " [J/kg/K]" << std::endl;
    std::cout << "Mixture entropy:              " << asali.mixtureMolarEntropy() << " [J/kmol/K]" << std::endl;

    std::cout << "\nSpecies viscosity [Pas]" << std::endl;
    for (unsigned int i=0;i<3;i++)
    {
        std::cout << names[i] << ": " << asali.speciesViscosity()[i] << std::endl;
    }
    
    std::cout << "\nSpecies binary diffusion coefficient [m2/s]" << std::endl;
    for (unsigned int i=0;i<3;i++)
    {
        std::cout << names[i] << ": " << asali.binaryDiffusion()[i][0] << "," << asali.binaryDiffusion()[i][1] << "," << asali.binaryDiffusion()[i][2] << std::endl;
    }

    std::cout << "\nSpecies specific heat [J/kg/K]" << std::endl;
    for (unsigned int i=0;i<3;i++)
    {
        std::cout << names[i] << ": " << asali.speciesMassCp()[i] << std::endl;
    }

    std::cout << "\nSpecies enthalpy [J/kg]" << std::endl;
    for (unsigned int i=0;i<3;i++)
    {
        std::cout << names[i] << ": " << asali.speciesMassEnthalpy()[i] << std::endl;
    }

    std::cout << "\nSpecies entropy [J/kg]" << std::endl;
    for (unsigned int i=0;i<3;i++)
    {
        std::cout << names[i] << ": " << asali.speciesMassEntropy()[i] << std::endl;
    }

    std::cout << "\nSpecies thermal conductivity [W/m/K]" << std::endl;
    for (unsigned int i=0;i<3;i++)
    {
        std::cout << names[i] << ": " << asali.speciesThermalConductivity()[i] << std::endl;
    }

    std::cout << "\nMixture diffusion coefficient [m2/s]" << std::endl;
    for (unsigned int i=0;i<3;i++)
    {
        std::cout << names[i] << ": " << asali.mixtureDiffusion()[i] << std::endl;
    }

    std::cout << "\nMean gas velocity [m/s]" << std::endl;
    for (unsigned int i=0;i<3;i++)
    {
        std::cout << names[i] << ": " << asali.arithmeticMeanGasVelocity()[i] << std::endl;
    }

    std::cout << "\nMean free path [m]" << std::endl;
    for (unsigned int i=0;i<3;i++)
    {
        std::cout << names[i] << ": " << asali.meanFreePath()[i] << std::endl;
    }

    return 0;
}
