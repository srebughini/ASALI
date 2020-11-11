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
ASALI estimates different thermodynamic and transport (`asali` is the library object):

<div class="col-md-4 text-justify">
| | |
|:-|:-|
| **`get_density(&asali)`** | |
| *Estimated property*|Mixture density|
| *Return type*       |`double`|
| *Unit dimensions*   |kg/m<sup>3</sup>|
| | |
| **`get_mixture_molecular_weight(&asali)`** | |
| *Estimated property*|Mixture molecular weight |
| *Return type*       |`double`|
| *Unit dimensions*   |g/mol|
| | |
| **`get_mixture_thermal_conductivity(&asali)`** | |
| *Estimated property*|Mixture thermal conductivity |
| *Return type*       |`double`|
| *Unit dimensions*   |W/m/K|
| | |
| **`get_mixture_viscosity(&asali)`** | |
| *Estimated property*|Mixture viscosity |
| *Return type*       |`double`|
| *Unit dimensions*   |Pa*s|
| | |
| **`get_mixture_molar_specific_heat(&asali)`** | |
| *Estimated property*|Mixture specific heat |
| *Return type*       |`double`|
| *Unit dimensions*   |J/kmol/K|
| | |
| **`get_mixture_mass_specific_heat(&asali)`** | |
| *Estimated property*|Mixture specific heat |
| *Return type*       |`double`|
| *Unit dimensions*   |J/kg/K|
| | |
| **`get_mixture_molar_enthalpy(&asali)`** | |
| *Estimated property*|Mixture enthalpy|
| *Return type*       |`double`|
| *Unit dimensions*   |J/kmol|
| | |
| **`get_mixture_mass_enthalpy(&asali)`** | |
| *Estimated property*|Mixture enthalpy|
| *Return type*       |`double`|
| *Unit dimensions*   |J/kg|
| | |
| **`get_mixture_molar_entropy(&asali)`** | |
| *Estimated property*|Mixture entropy|
| *Return type*       |`double`|
| *Unit dimensions*   |J/kmol/K|
| | |
| **`get_mixture_mass_entropy(&asali)`** | |
| *Estimated property*|Mixture entropy|
| *Return type*       |`double`|
| *Unit dimensions*   |J/kg/K|
| | |
| **`get_mixture_diffusion(&asali)`** | |
| *Estimated property*|Mixture diffusivity|
| *Return type*       |`double`|
| *Unit dimensions*   |m<sup>2</sup>/s|
| | |
| **`get_species_thermal_conductivity(&asali)`** | |
| *Estimated property*|Single specie thermal conductivity|
| *Return type*       |`AsaliVector`|
| *Unit dimensions*   |W/m/K|
| | |
| **`get_species_viscosity(&asali)`** | |
| *Estimated property*|Single specie viscosity|
| *Return type*       |`AsaliVector`|
| *Unit dimensions*   |Pa*s|
| | |
| **`get_species_molar_specific_heat(&asali)`** | |
| *Estimated property*|Single specie specific heat|
| *Return type*       |`AsaliVector`|
| *Unit dimensions*   |J/kmol/K|
| | |
| **`get_species_mass_specific_heat(&asali)`** | |
| *Estimated property*|Single specie specific heat|
| *Return type*       |`AsaliVector`|
| *Unit dimensions*   |J/kg/K|
| | |
| **`get_species_molar_enthalpy(&asali)`** | |
| *Estimated property*|Single specie enthalpy|
| *Return type*       |`AsaliVector`|
| *Unit dimensions*   |J/kmol|
| | |
| **`get_species_mass_enthalpy(&asali)`** | |
| *Estimated property*|Single specie enthalpy|
| *Return type*       |`AsaliVector`|
| *Unit dimensions*   |J/kg|
| | |
| **`get_species_molar_entropy(&asali)`** | |
| *Estimated property*|Single specie entropy|
| *Return type*       |`AsaliVector`|
| *Unit dimensions*   |J/kmol/K|
| | |
| **`get_species_mass_entropy(&asali)`** | |
| *Estimated property*|Single specie entropy|
| *Return type*       |`AsaliVector`|
| *Unit dimensions*   |J/kg/K|
| | |
| **`get_aritmetic_mean_gas_velocity(&asali)`** | |
| *Estimated property*|Single gas velocity|
| *Return type*       |`AsaliVector`|
| *Unit dimensions*   |m/s|
| | |
| **`get_mean_free_path(&asali)`** | |
| *Estimated property*|Single mean free path|
| *Return type*       |`AsaliVector`|
| *Unit dimensions*   |m|
| | |
| **`get_binary_diffusion(&asali)`** | |
| *Estimated property*|Single binary diffusion|
| *Return type*       |`AsaliMatrix`|
| *Unit dimensions*   |m<sup>2</sup>/s|
</div>