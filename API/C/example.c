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
    AsaliVector x,names;
    double X[3] = {0.1, 0.2, 0.7};
    empty_vector_of_char(&names,3);
    set_vector_element_from_char(&names,0,"H2");
    set_vector_element_from_char(&names,1,"O2");
    set_vector_element_from_char(&names,2,"N2");
    vector_from_double_array(&x,3,X);

    Asali asali;
    initialize(&asali);

    set_temperature(&asali,393.15);
    set_pressure(&asali,4e05);
    set_number_of_species(&asali,get_vector_size(&x));
    set_species_names(&asali,names);
    set_mole_fraction(&asali,x);
    
    AsaliVector mu,cp,h,s,cond,diff_mix,v,l;
    AsaliMatrix diff;
    mu = get_species_viscosity(&asali);
    diff = get_binary_diffusion(&asali);
    cp = get_species_mass_specific_heat(&asali);
    h = get_species_mass_enthalpy(&asali);
    s = get_species_mass_entropy(&asali);
    cond = get_species_thermal_conductivity(&asali);
    diff_mix = get_mixture_diffusion(&asali);
    v = get_aritmetic_mean_gas_velocity(&asali);
    l = get_mean_free_path(&asali);

    printf("Mixture molecular weight:     %.3e  [kmol/kg]\n",get_mixture_molecular_weight(&asali));
    printf("Density:                      %.3e  [kg/m3]\n",get_density(&asali));
    printf("Mixture viscosity:            %.3e  [Pas]\n",get_mixture_viscosity(&asali));
    printf("Mixture specific heat:        %.3e  [J/kg/K]\n",get_mixture_mass_specific_heat(&asali));
    printf("Mixture specific heat:        %.3e  [J/kmol/K]\n",get_mixture_molar_specific_heat(&asali));
    printf("Mixture thermal conductivity: %.3e  [W/m/K]\n",get_mixture_thermal_conductivity(&asali));
    printf("Mixture enthalpy:             %.3e  [J/kg]\n",get_mixture_mass_enthalpy(&asali));
    printf("Mixture enthalpy:             %.3e  [J/kmol]\n",get_mixture_molar_enthalpy(&asali));
    printf("Mixture entropy:              %.3e  [J/kg/K]\n",get_mixture_mass_entropy(&asali));
    printf("Mixture entropy:              %.3e  [J/kmol/K]\n",get_mixture_molar_entropy(&asali));
    printf("\nSpecies viscosity [Pas]\n");
    for (unsigned int i=0;i<3;i++)
    {
        printf("%s: %.3e\n",get_vector_element_as_char(&names,i),get_vector_element_as_double(&mu,i));
    }
    
    printf("\nSpecies binary diffusion coefficient [m2/s]\n");
    for (unsigned int i=0;i<3;i++)
    {
        printf("%s: %.3e %.3e %.3e\n",get_vector_element_as_char(&names,i),get_matrix_element_as_double(&diff,i,0),get_matrix_element_as_double(&diff,i,1),get_matrix_element_as_double(&diff,i,2));
    }

    printf("\nSpecies specific heat [J/kg/K]\n");
    for (unsigned int i=0;i<3;i++)
    {
        printf("%s: %.3e\n",get_vector_element_as_char(&names,i),get_vector_element_as_double(&cp,i));
    }

    printf("\nSpecies enthalpy [J/kg]\n");
    for (unsigned int i=0;i<3;i++)
    {
        printf("%s: %.3e\n",get_vector_element_as_char(&names,i),get_vector_element_as_double(&h,i));
    }

    printf("\nSpecies entropy [J/kg/K]\n");
    for (unsigned int i=0;i<3;i++)
    {
        printf("%s: %.3e\n",get_vector_element_as_char(&names,i),get_vector_element_as_double(&s,i));
    }

    printf("\nSpecies thermal conductivity [W/m/K]\n");
    for (unsigned int i=0;i<3;i++)
    {
        printf("%s: %.3e\n",get_vector_element_as_char(&names,i),get_vector_element_as_double(&cond,i));
    }

    printf("\nMixture diffusion coefficient [m2/s]\n");
    for (unsigned int i=0;i<3;i++)
    {
        printf("%s: %.3e\n",get_vector_element_as_char(&names,i),get_vector_element_as_double(&diff_mix,i));
    }

    printf("\nMean gas velocity [m/s]\n");
    for (unsigned int i=0;i<3;i++)
    {
        printf("%s: %.3e\n",get_vector_element_as_char(&names,i),get_vector_element_as_double(&v,i));
    }

    printf("\nMean free path [m]\n");
    for (unsigned int i=0;i<3;i++)
    {
        printf("%s: %.3e\n",get_vector_element_as_char(&names,i),get_vector_element_as_double(&l,i));
    }

    return 0;
}
