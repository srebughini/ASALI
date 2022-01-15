---
permalink: /docs/api-java/
redirect_from: /docs/index.html
---

# **Java version**
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

| | |
|:-|:-|
| **`asali.get_density()`** | |
| *Estimated property*|Mixture density|
| *Return type*       |`double`|
| *Unit dimensions*   |kg/m<sup>3</sup>|
| **`asali.get_mixture_molecular_weight()`** | |
| *Estimated property*|Mixture molecular weight |
| *Return type*       |`double`|
| *Unit dimensions*   |g/mol|
| **`asali.get_mixture_thermal_conductivity()`** | |
| *Estimated property*|Mixture thermal conductivity |
| *Return type*       |`double`|
| *Unit dimensions*   |W/m/K|
| **`asali.get_mixture_viscosity()`** | |
| *Estimated property*|Mixture viscosity |
| *Return type*       |`double`|
| *Unit dimensions*   |Pa*s|
| **`asali.get_mixture_molar_cp()`** | |
| *Estimated property*|Mixture specific heat |
| *Return type*       |`double`|
| *Unit dimensions*   |J/kmol/K|
| **`asali.get_mixture_mass_cp()`** | |
| *Estimated property*|Mixture specific heat |
| *Return type*       |`double`|
| *Unit dimensions*   |J/kg/K|
| **`asali.get_mixture_molar_enthalpy()`** | |
| *Estimated property*|Mixture enthalpy|
| *Return type*       |`double`|
| *Unit dimensions*   |J/kmol|
| **`asali.get_mixture_mass_enthalpy()`** | |
| *Estimated property*|Mixture enthalpy|
| *Return type*       |`double`|
| *Unit dimensions*   |J/kg|
| **`asali.get_mixture_molar_entropy()`** | |
| *Estimated property*|Mixture entropy|
| *Return type*       |`double`|
| *Unit dimensions*   |J/kmol/K|
| **`asali.get_mixture_mass_entropy()`** | |
| *Estimated property*|Mixture entropy|
| *Return type*       |`double`|
| *Unit dimensions*   |J/kg/K|
| **`asali.get_mixture_diffusion()`** | |
| *Estimated property*|Mixture diffusivity|
| *Return type*       |`double []`|
| *Unit dimensions*   |m<sup>2</sup>/s|
| **`asali.get_species_thermal_conductivity()`** | |
| *Estimated property*|Single specie thermal conductivity|
| *Return type*       |`double []`|
| *Unit dimensions*   |W/m/K|
| **`asali.get_species_viscosity()`** | |
| *Estimated property*|Single specie viscosity|
| *Return type*       |`double []`|
| *Unit dimensions*   |Pa*s|
| **`asali.get_species_molar_cp()`** | |
| *Estimated property*|Single specie specific heat|
| *Return type*       |`double []`|
| *Unit dimensions*   |J/kmol/K|
| **`asali.get_species_mass_cp()`** | |
| *Estimated property*|Single specie specific heat|
| *Return type*       |`double []`|
| *Unit dimensions*   |J/kg/K|
| **`asali.get_species_molar_enthalpy()`** | |
| *Estimated property*|Single specie enthalpy|
| *Return type*       |`double []`|
| *Unit dimensions*   |J/kmol|
| **`asali.get_species_mass_enthalpy()`** | |
| *Estimated property*|Single specie enthalpy|
| *Return type*       |`double []`|
| *Unit dimensions*   |J/kg|
| **`asali.get_species_molar_entropy()`** | |
| *Estimated property*|Single specie entropy|
| *Return type*       |`double []`|
| *Unit dimensions*   |J/kmol/K|
| **`asali.get_species_mass_entropy()`** | |
| *Estimated property*|Single specie entropy|
| *Return type*       |`double []`|
| *Unit dimensions*   |J/kg/K|
| **`asali.get_arithmetic_mean_gas_velocity()`** | |
| *Estimated property*|Single gas velocity|
| *Return type*       |`double []`|
| *Unit dimensions*   |m/s|
| **`asali.get_mean_free_path()`** | |
| *Estimated property*|Single mean free path|
| *Return type*       |`double []`|
| *Unit dimensions*   |m|
| **`asali.get_binary_diffusion()`** | |
| *Estimated property*|Single binary diffusion|
| *Return type*       |`double [][]`|
| *Unit dimensions*   |m<sup>2</sup>/s|