---
title: Java version
permalink: /docs/api-java/
---
The Java API can be included in your code as follow:  
```java
//Include library
import java.io.*; 
import java.util.*;
import java.lang.*;
import java.text.*;

class AsaliJava 
{   
    //Main
    public static void main(String args[])  throws Exception 
    { 
		int N = Integer.valueOf(args[0]);

        //Create composition using Vector and ArrayList
        ArrayList<String> names = new ArrayList<String>();
        names.add("H2");
        names.add("O2");
        names.add("N2");
        
        Vector<Double> x = new Vector<Double>();
        x.add(0.1);
        x.add(0.2);
        x.add(0.7);

		//Initialize ASALI
		Asali asali_ = new Asali();

        //Set up composition/pressure and temperature
        asali_.set_number_of_species(3);
        asali_.set_species_names(names);
        asali_.set_mole_fraction(x);
        asali_.set_pressure(4e05); //Pa 
        asali_.set_temperature(393.15); //K

        //Properties evaluation
        double [][] diff;
        diff      = asali_.get_binary_diffusion();

        double [] cp;
        cp = asali_.get_species_mass_specific_heat();
    }
}
```
Example and database generator can be compiled by typing:
```
./compile.sh
```
## **Available thermodynamic and transport properties**
ASALI estimates different thermodynamic and transport (`asali` is the library object):
<table class="table table-striped">
    <thead>
        <tr>
            <th scope="row">Function</th>
            <th>Estimated property</th>
            <th>Return type</th>
            <th>Unit dimension</th>
        </tr>
    </thead>
    <tbody>
        <tr> 
            <th scope="row"><b><i>asali.get_density()</i></b></th>
            <td>Mixture density</td>
            <td><i>double</i></td>
            <td>kg/m<sup>3</sup></td>
        </tr>
        <tr>
            <th scope="row"><b><i>asali.get_mixture_molecular_weight()</i></b></th>
            <td>Mixture molecular weight</td>
            <td><i>double</i></td>
            <td>g/mol</td>
        </tr>
        <tr>
            <th scope="row"><b><i>asali.get_mixture_thermal_conductivity()</i></b></th>
            <td>Mixture thermal conductivity</td>
            <td><i>double</i></td>
            <td>W/m/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>asali.get_mixture_viscosity()</i></b></th>
            <td>Mixture viscosity</td>
            <td><i>double</i></td>
            <td>Pa*s</td>
        </tr>
        <tr>
            <th scope="row"><b><i>asali.get_mixture_molar_cp()</i></b></th>
            <td>Mixture specific heat</td>
            <td><i>double</i></td>
            <td>J/kmol/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>asali.get_mixture_mass_cp()</i></b></th>
            <td>Mixture specific heat</td>
            <td><i>double</i></td>
            <td>J/kg/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>asali.get_mixture_molar_enthalpy()</i></b></th>
            <td>Mixture enthalpy</td>
            <td><i>double</i></td>
            <td>J/kmol</td>
        </tr>
        <tr>
            <th scope="row"><b><i>asali.get_mixture_mass_enthalpy()</i></b></th>
            <td>Mixture enthalpy</td>
            <td><i>double</i></td>
            <td>J/kg</td>
        </tr>
        <tr>
            <th scope="row"><b><i>asali.get_mixture_molar_entropy()</i></b></th>
            <td>Mixture entropy</td>
            <td><i>double</i></td>
            <td>J/kmol/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>asali.get_mixture_mass_entropy()</i></b></th>
            <td>Mixture entropy</td>
            <td><i>double</i></td>
            <td>J/kg/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>asali.get_mixture_diffusion()</i></b></th>
            <td>Mixture diffusivity</td>
            <td><i>double []</i></td>
            <td>m<sup>2</sup>/s</td>
        </tr>
        <tr>
            <th scope="row"><b><i>asali.get_species_thermal_conductivity()</i></b></th>
            <td>Single specie thermal conductivity</td>
            <td><i>double []</i></td>
            <td>W/m/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>asali.get_species_viscosity()</i></b></th>
            <td>Single specie viscosity</td>
            <td><i>double []</i></td>
            <td>Pa*s</td>
        </tr>
        <tr>
            <th scope="row"><b><i>asali.get_species_molar_cp()</i></b></th>
            <td>Single specie specific heat</td>
            <td><i>double []</i></td>
            <td>J/kmol/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>asali.get_species_mass_cp()</i></b></th>
            <td>Single specie specific heat</td>
            <td><i>double []</i></td>
            <td>J/kg/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>asali.get_species_molar_enthalpy()</i></b></th>
            <td>Single specie enthalpy</td>
            <td><i>double []</i></td>
            <td>J/kmol</td>
        </tr>
        <tr>
            <th scope="row"><b><i>asali.get_species_mass_enthalpy()</i></b></th>
            <td>Single specie enthalpy</td>
            <td><i>double []</i></td>
            <td>J/kg</td>
        </tr>
        <tr>
            <th scope="row"><b><i>asali.get_species_molar_entropy()</i></b></th>
            <td>Single specie entropy</td>
            <td><i>double []</i></td>
            <td>J/kmol/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>asali.get_species_mass_entropy()</i></b></th>
            <td>Single specie entropy</td>
            <td><i>double []</i></td>
            <td>J/kg/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>asali.get_arithmetic_mean_gas_velocity()</i></b></th>
            <td>Single gas velocity</td>
            <td><i>double []</i></td>
            <td>m/s</td>
        </tr>
        <tr>
            <th scope="row"><b><i>asali.get_mean_free_path()</i></b></th>
            <td>Single mean free path</td>
            <td><i>double []</i></td>
            <td>m</td>
        </tr>
        <tr>
            <th scope="row"><b><i>asali.get_binary_diffusion()</i></b></th>
            <td>Single binary diffusion</td>
            <td><i>double [][]</i></td>
            <td>m<sup>2</sup>/s</td>
        </tr>
    </tbody>
</table>