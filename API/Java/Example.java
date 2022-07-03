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

class Example 
{
    public static void main(String args[])  throws Exception 
    { 
        Asali asali_ = new Asali();
        
        ArrayList<String> names = new ArrayList<String>();
        names.add("H2");
        names.add("O2");
        names.add("N2");
        
        Vector<Double> x = new Vector<Double>();
        x.add(0.1);
        x.add(0.2);
        x.add(0.7);
        
        asali_.set_pressure(4e05);
        asali_.set_temperature(393.15);
        asali_.set_number_of_species(3);
        asali_.set_species_names(names);
        asali_.set_mole_fraction(x);
        
        double []   mu       = asali_.get_species_viscosity();
        double []   cp       = asali_.get_species_mass_specific_heat();
        double []   h        = asali_.get_species_mass_enthalpy();
        double []   s        = asali_.get_species_mass_entropy();
        double []   cond     = asali_.get_species_thermal_conductivity();
        double []   diff_mix = asali_.get_mixture_diffusion();
        double []   v        = asali_.get_aritmetic_mean_gas_velocity();
        double []   l        = asali_.get_mean_free_path();
        double [][] diff = asali_.get_binary_diffusion();
        
        
        Locale currentLocale = Locale.getDefault();
        DecimalFormatSymbols symbol = new DecimalFormatSymbols(currentLocale);
        symbol.setDecimalSeparator('.');
        symbol.setGroupingSeparator(','); 
        DecimalFormat df = new DecimalFormat("0.000E00", symbol);

        
        System.out.println("Mixture molecular weight:     " + df.format(asali_.get_mixture_molecular_weight()) + " [kg/kmol]");
        System.out.println("Mixture density:              " + df.format(asali_.get_density()) + " [kg/m3]");
        System.out.println("Mixture viscosity:            " + df.format(asali_.get_mixture_viscosity()) + " [Pas]");
        System.out.println("Mixture specific heat:        " + df.format(asali_.get_mixture_mass_specific_heat()) + " [J/kg/K]");
        System.out.println("Mixture specific heat:        " + df.format(asali_.get_mixture_molar_specific_heat()) + " [J/kmol/K]");
        System.out.println("Mixture thermal conductivity: " + df.format(asali_.get_mixture_thermal_conductivity()) + " [W/m/K]");
        System.out.println("Mixture enthalpy:             " + df.format(asali_.get_mixture_mass_enthalpy()) + " [J/kg]");
        System.out.println("Mixture enthalpy:             " + df.format(asali_.get_mixture_molar_enthalpy()) + " [J/kmol]");
        System.out.println("Mixture entropy:              " + df.format(asali_.get_mixture_mass_entropy()) + " [J/kg/K]");
        System.out.println("Mixture entropy:              " + df.format(asali_.get_mixture_molar_entropy()) + " [J/kmol/K]");
        System.out.println("\nSpecies viscosity [Pas]");
        for (int i=0;i<3;i++)
        {
            System.out.println(names.get(i) + ": " + df.format(mu[i]));
        }
        System.out.println("\nSpecies binary diffusion coefficient [m2/s]");
        for (int i=0;i<3;i++)
        {
            System.out.println(names.get(i) + ": " + df.format(diff[i][0]) + "," + df.format(diff[i][1]) + "," + df.format(diff[i][2]));
        }
        System.out.println("\nSpecies specific heat [J/kg/K]");
        for (int i=0;i<3;i++)
        {
            System.out.println(names.get(i) + ": " + df.format(cp[i]));
        }
        System.out.println("\nSpecies enthalpy [J/kg]");
        for (int i=0;i<3;i++)
        {
            System.out.println(names.get(i) + ": " + df.format(h[i]));
        }
        System.out.println("\nSpecies entropy [J/kg/K]");
        for (int i=0;i<3;i++)
        {
            System.out.println(names.get(i) + ": " + df.format(s[i]));
        }
        System.out.println("\nSpecies thermal conductivity [W/m/K]");
        for (int i=0;i<3;i++)
        {
            System.out.println(names.get(i) + ": " + df.format(cond[i]));
        }
        System.out.println("\nMixture diffusion coefficient [m2/s]");
        for (int i=0;i<3;i++)
        {
            System.out.println(names.get(i) + ": " + df.format(diff_mix[i]));
        }
        System.out.println("\nMean gas velocity [m/s]");
        for (int i=0;i<3;i++)
        {
            System.out.println(names.get(i) + ": " + df.format(v[i]));
        }
        System.out.println("\nMean free path [m]");
        for (int i=0;i<3;i++)
        {
            System.out.println(names.get(i) + ": " + df.format(l[i]));
        }
    } 
}
