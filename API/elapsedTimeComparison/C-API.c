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
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *a = argv[1];
    int N = atoi(a);

    //Set up mixture composition
    AsaliVector x,names;
    double X[3] = {0.1, 0.2, 0.7};
    empty_vector_of_char(&names,3);
    set_vector_element_from_char(&names,0,"H2");
    set_vector_element_from_char(&names,1,"O2");
    set_vector_element_from_char(&names,2,"N2");
    vector_from_double_array(&x,3,X);

    //Initialize variables
    clock_t initializationStart = clock();
    for (int i=0;i<N-1;i++)
    {
        Asali asali;
        initialize(&asali);
    }
    Asali asali;
    initialize(&asali);
    clock_t initializationEnd = clock();
    
    AsaliVector mu,cp,h,s,cond,diff_mix,v,l;
    AsaliMatrix diff;
    double MWmix, rho, mumix, cpmassmix, cpmolemix, hmassmix, hmolemix, smassmix, smolemix, condmix;

    clock_t estimationStart = clock();
    for (int i=0;i<N;i++)
    {
        set_temperature(&asali,393.15);
        set_pressure(&asali,4e05);
        set_number_of_species(&asali,get_vector_size(&x));
        set_species_names(&asali,names);
        set_mole_fraction(&asali,x);

        mu = get_species_viscosity(&asali);
        diff = get_binary_diffusion(&asali);
        cp = get_species_mass_specific_heat(&asali);
        h = get_species_mass_enthalpy(&asali);
        s = get_species_mass_entropy(&asali);
        cond = get_species_thermal_conductivity(&asali);
        diff_mix = get_mixture_diffusion(&asali);
        v = get_arithmetic_mean_gas_velocity(&asali);
        l = get_mean_free_path(&asali);
        MWmix = get_mixture_molecular_weight(&asali);
        rho = get_density(&asali);
        mumix = get_mixture_viscosity(&asali);
        cpmassmix = get_mixture_mass_specific_heat(&asali);
        cpmolemix = get_mixture_molar_specific_heat(&asali);
        hmassmix = get_mixture_mass_enthalpy(&asali);
        hmolemix = get_mixture_molar_enthalpy(&asali);
        smassmix = get_mixture_mass_entropy(&asali);
        smolemix = get_mixture_molar_entropy(&asali);
        condmix = get_mixture_thermal_conductivity(&asali);
    }
    clock_t estimationEnd = clock();
    printf("C version\n");
    printf("Initialization (s):  %.3e\n",((double)(initializationEnd - initializationStart)/CLOCKS_PER_SEC)/N);
    printf("Estimation (s):      %.3e\n",((double)(estimationEnd - estimationStart)/CLOCKS_PER_SEC)/N);
    
    return 0;
}
