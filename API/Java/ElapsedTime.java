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

import java.io.*; 
import java.util.*;
import java.lang.*;
import java.text.*;

class ElapsedTime 
{
    public static void main(String args[])  throws Exception 
    { 
		int N = Integer.valueOf(args[0]);

        //Set up mixture composition
        ArrayList<String> names = new ArrayList<String>();
		names.add("H2");
		names.add("O2");
		names.add("C3H8");
		names.add("C2H6");
		names.add("CH4");
		names.add("CO2");
		names.add("HE");
		names.add("N2");
		names.add("NH3");
        
        Vector<Double> x = new Vector<Double>();
        x.add(0.1);
        x.add(0.1);
        x.add(0.1);
        x.add(0.1);
        x.add(0.1);
        x.add(0.1);
        x.add(0.1);
        x.add(0.1);
        x.add(0.2);

		//Initialize variables
		double initializationStart = System.nanoTime();
		for (int i=0;i<N-1;i++)
		{
			Asali asali_ = new Asali();
		}
		Asali asali_ = new Asali();
		double initializationEnd = System.nanoTime();
		
		double []  mu, cp, h, s, cond, diff_mix, v, l;
		double [][] diff;
		double MWmix, rho, mumix, cpmassmix, cpmolemix, condmix, hmassmix, hmolemix, smolemix, smassmix;


		double estimationStart = System.nanoTime();
		for (int i=0;i<N;i++)
		{
			asali_.set_pressure(4e05);
			asali_.set_temperature(393.15);
			asali_.set_number_of_species(9);
			asali_.set_species_names(names);
			asali_.set_mole_fraction(x);

			mu        = asali_.get_species_viscosity();
			cp        = asali_.get_species_mass_specific_heat();
			h         = asali_.get_species_mass_enthalpy();
			s         = asali_.get_species_mass_entropy();
			cond      = asali_.get_species_thermal_conductivity();
			diff_mix  = asali_.get_mixture_diffusion();
			v         = asali_.get_aritmetic_mean_gas_velocity();
			l         = asali_.get_mean_free_path();
			diff      = asali_.get_binary_diffusion();
			MWmix     = asali_.get_mixture_molecular_weight();
			rho       = asali_.get_density();
			mumix     = asali_.get_mixture_viscosity();
			cpmassmix = asali_.get_mixture_mass_specific_heat();
			cpmolemix = asali_.get_mixture_molar_specific_heat();
			condmix   = asali_.get_mixture_thermal_conductivity();
			hmassmix  = asali_.get_mixture_mass_enthalpy();
			hmolemix  = asali_.get_mixture_molar_enthalpy();
			smolemix  = asali_.get_mixture_molar_entropy();
			smassmix  = asali_.get_mixture_molar_entropy();
		}
		double estimationEnd = System.nanoTime();
		double estimationTime = (estimationEnd - estimationStart)/(1.0e09*(double)N);
		double initializationTime = (initializationEnd - initializationStart)/(1.0e09*(double)N);
		
		System.out.println("Java version");
		System.out.printf("Initialization (s):  %.3e\n", initializationTime);
		System.out.printf("Calculation (s):     %.3e\n", estimationTime);
    }
}
