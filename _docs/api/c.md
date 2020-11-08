---
permalink: /docs/api-c/
redirect_from: /docs/index.html
---

# **C version**
The C API requires the [Lapack libraries](http://www.netlib.org/lapack/) which can be install with the following command:

```
sudo apt-get install liblapack-dev
```  

This version can be included in your code as follow:  
```c
//Include library
#include "Asali.h"

//Main
int main()
{
    //Create composition using Asali vectors format
    AsaliVector x,names;
    double X[3] = {0.1, 0.2, 0.7};
    empty_vector_of_char(&names,3);
    set_vector_element_from_char(&names,0,"H2");
    set_vector_element_from_char(&names,1,"O2");
    set_vector_element_from_char(&names,2,"N2");
    vector_from_double_array(&x,3,X);

    //Initialize Asali
    Asali asali;
    initialize(&asali);

    //Set up composition/pressure and temperature
    set_temperature(&asali,393.15);
    set_pressure(&asali,4e05);
    set_number_of_species(&asali,get_vector_size(&x));
    set_species_names(&asali,names);
    set_mole_fraction(&asali,x);

    //Properties evaluation
    AsaliVector cp;
    AsaliMatrix diff;

    diff = get_binary_diffusion(&asali);
    cp = get_species_mass_specific_heat(&asali);
    return 0;
}
```
Example and database generator can be compiled by typing:
```
./compile.sh
```

To convert the Asali database into C code run:
```
./database-generator
```
## Available thermodynamic and transport properties
ASALI estimates different thermodynamic and transport:
<p>&nbsp;</p>
* `get_density(&asali)`
    * Mixture density in kg/m3
    * The return value is a `double`.
<p>&nbsp;</p>
* `get_mixture_molecular_weight(&asali)`
    * Mixture molecular weight in g/mol
    * The return value is a `double`.  
<p>&nbsp;</p>
* `get_mixture_thermal_conductivity(&asali)`
    * Mixture thermal conductivity in W/m/K
    * The return value is a `double`.  
<p>&nbsp;</p>
* `get_mixture_viscosity(&asali)`
    * Mixture viscosity in Pa*s.
    * The return value is a `double`.  
<p>&nbsp;</p>
* `get_mixture_molar_specific_heat(&asali)`
    * Mixture specific heat in J/kmol/K.
    * The return value is a `double`.  
<p>&nbsp;</p>
* `get_mixture_mass_specific_heat(&asali)`
    * Mixture specific heat in J/kg/K.
    * The return value is a `double`.  
<p>&nbsp;</p>
* `get_mixture_molar_enthalpy(&asali)`
    * Mixture enthalpy in J/kmol.
    * The return value is a `double`.  
<p>&nbsp;</p>
* `get_mixture_mass_enthalpy(&asali)`
    * Mixture enthalpy in J/kg.
    * The return value is a `double`.  
<p>&nbsp;</p>
* `get_mixture_molar_entropy(&asali)`
    * Mixture entropy in J/kmol/K.
    * The return value is a `double`.  
<p>&nbsp;</p>
* `get_mixture_mass_entropy(&asali)`
    * Mixture entropy in J/kg/K.
    * The return value is a `double`.  
<p>&nbsp;</p>
* `get_mixture_diffusion(&asali)`
    * Mixture diffusivity in m2/s. 
    * The return value is a `AsaliVector`.  
<p>&nbsp;</p>
* `get_species_thermal_conductivity(&asali)`
    * Single species viscosity in W/m/K
    * The return value is a `AsaliVector`.  
<p>&nbsp;</p>
* `get_species_viscosity(&asali)`
    * Single species viscosity in Pa*s.
    * The return value is a `AsaliVector`. 
<p>&nbsp;</p>
* `get_species_molar_specific_heat(&asali)`
    * Single species specific heat in J/kmol/K.
    * The return value is a `AsaliVector`. 
<p>&nbsp;</p>
* `get_species_mass_specific_heat(&asali)`
    * Single species specific heat in J/kg/K.
    * The return value is a `AsaliVector`. 
<p>&nbsp;</p>
* `get_species_molar_enthalpy(&asali)`
    * Single species enthalpy in J/kmol.
    * The return value is a `AsaliVector`.   
<p>&nbsp;</p>
* `get_species_mass_enthalpy(&asali)`
    * Single species enthalpy in J/kg. 
    * The return value is a `AsaliVector`. 
<p>&nbsp;</p>
* `get_species_molar_entropy(&asali)`
    * Single species entropy in J/kmol/K.
    * The return value is a `AsaliVector`. 
<p>&nbsp;</p>
* `get_species_mass_entropy(&asali)`
    * Single species entropy in J/kg/K.
    * The return value is a `AsaliVector`.  
<p>&nbsp;</p>
* `get_aritmetic_mean_gas_velocity(&asali)`
    * Single gas velocity in m/s. 
    * The return value is a `AsaliVector`. 
<p>&nbsp;</p>
* `get_mean_free_path(&asali)`
    * Single species mean free path in m.
    * The return value is a `AsaliVector`. 
<p>&nbsp;</p>
* `get_binary_diffusion(&asali)`
    * Single species binary diffusion in m2/s.
    * The return value is a `AsaliMatrix`. 
