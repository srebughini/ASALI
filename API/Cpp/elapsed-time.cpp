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
#include <time.h>
#include <cstdlib>
#include <iomanip> 

int main(int argc, char** argv)
{
    int N = atoi(argv[1]);

    //Set up mixture composition
    std::vector<std::string> names(3);
    std::vector<double> x(3);

    names[0] = "H2";
    names[1] = "O2";
    names[2] = "N2";

    x[0] = 0.1;
    x[1] = 0.2;
    x[2] = 1. - x[0] - x[1];

    //Initialize variables
    clock_t initializationStart = clock();
    for (int i=0;i<N-1;i++)
    {
        ASALI::Asali asali;
    }
    ASALI::Asali asali;
    clock_t initializationEnd = clock();

    std::vector<double> mu, cp, h, s, cond, diff_mix, v, l; 
    std::vector<std::vector<double> > diff;
    double mwmix, rho, mumix, cpmassmix, cpmolemix, hmassmix, hmolemix, condmix, smassmix, smolemix;

    clock_t estimationStart = clock();
    for (int i=0;i<N;i++)
    {
        asali.setSpecies(names);
        asali.setTemperature(393.15); //K
        asali.setPressure(4e05); //Pa
        asali.setMoleFraction(x);

        mu = asali.speciesViscosity();
        diff = asali.binaryDiffusion();
        cp =  asali.speciesMassCp();
        h = asali.speciesMassEnthalpy();
        s = asali.speciesMassEntropy();
        cond = asali.speciesThermalConductivity();
        diff_mix = asali.mixtureDiffusion();
        v = asali.arithmeticMeanGasVelocity();
        l = asali.meanFreePath();
        mwmix = asali.mixtureMolecularWeight();
        rho = asali.density();
        mumix = asali.mixtureViscosity();
        cpmassmix = asali.mixtureMassCp();
        cpmolemix = asali.mixtureMolarCp();
        hmassmix = asali.mixtureMassEnthalpy();
        hmolemix = asali.mixtureMolarEnthalpy();
        condmix = asali.mixtureThermalConductivity();
        smassmix = asali.mixtureMassEntropy();
        smolemix = asali.mixtureMolarEntropy();
    }
    
    clock_t estimationEnd = clock();
    std::cout << "C++ version" << std::endl << std::scientific << std::setprecision(3);
    std::cout << "Initialization (s):  " << ((double)(initializationEnd - initializationStart)/CLOCKS_PER_SEC)/double(N) << std::endl;
    std::cout << "Calculation (s):     " << ((double)(estimationEnd - estimationStart)/CLOCKS_PER_SEC)/double(N) << std::endl;

    return 0;
}
