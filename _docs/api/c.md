---
permalink: /docs/api-c/
redirect_from: /docs/index.html
---

# **C version**
The C API can be included in your code as follow:  
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
## **Available thermodynamic and transport properties**
ASALI estimates different thermodynamic and transport (`asali` is the library object):
<table class="table table-striped text-right">
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
            <th scope="row"><b><i>get_density(&asali)</i></b></th>
            <td>Mixture density</td>
            <td><i>double</i></td>
            <td>kg/m<sup>3</sup></td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mixture_molecular_weight(&asali)</i></b></th>
            <td>Mixture molecular weight</td>
            <td><i>double</i></td>
            <td>g/mol</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mixture_thermal_conductivity(&asali)</i></b></th>
            <td>Mixture thermal conductivity</td>
            <td><i>double</i></td>
            <td>W/m/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mixture_viscosity(&asali)</i></b></th>
            <td>Mixture viscosity</td>
            <td><i>double</i></td>
            <td>Pa*s</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mixture_molar_specific_heat(&asali)</i></b></th>
            <td>Mixture specific heat</td>
            <td><i>double</i></td>
            <td>J/kmol/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mixture_mass_specific_heat(&asali)</i></b></th>
            <td>Mixture specific heat</td>
            <td><i>double</i></td>
            <td>J/kg/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mixture_molar_enthalpy(&asali)</i></b></th>
            <td>Mixture enthalpy</td>
            <td><i>double</i></td>
            <td>J/kmol</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mixture_mass_enthalpy(&asali)</i></b></th>
            <td>Mixture enthalpy</td>
            <td><i>double</i></td>
            <td>J/kg</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mixture_molar_entropy(&asali)</i></b></th>
            <td>Mixture entropy</td>
            <td><i>double</i></td>
            <td>J/kmol/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mixture_mass_entropy(&asali)</i></b></th>
            <td>Mixture entropy</td>
            <td><i>double</i></td>
            <td>J/kg/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mixture_diffusion(&asali)</i></b></th>
            <td>Mixture diffusivity</td>
            <td><i>AsaliVector</i></td>
            <td>m<sup>2</sup>/s</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_species_thermal_conductivity(&asali)</i></b></th>
            <td>Single specie thermal conductivity</td>
            <td><i>AsaliVector</i></td>
            <td>W/m/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_species_viscosity(&asali)</i></b></th>
            <td>Single specie viscosity</td>
            <td><i>AsaliVector</i></td>
            <td>Pa*s</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_species_molar_specific_heat(&asali)</i></b></th>
            <td>Single specie specific heat</td>
            <td><i>AsaliVector</i></td>
            <td>J/kmol/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_species_mass_specific_heat(&asali)</i></b></th>
            <td>Single specie specific heat</td>
            <td><i>AsaliVector</i></td>
            <td>J/kg/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_species_molar_enthalpy(&asali)</i></b></th>
            <td>Single specie enthalpy</td>
            <td><i>AsaliVector</i></td>
            <td>J/kmol</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_species_mass_enthalpy(&asali)</i></b></th>
            <td>Single specie enthalpy</td>
            <td><i>AsaliVector</i></td>
            <td>J/kg</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_species_molar_entropy(&asali)</i></b></th>
            <td>Single specie entropy</td>
            <td><i>AsaliVector</i></td>
            <td>J/kmol/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_species_mass_entropy(&asali)</i></b></th>
            <td>Single specie entropy</td>
            <td><i>AsaliVector</i></td>
            <td>J/kg/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_arithmetic_mean_gas_velocity(&asali)</i></b></th>
            <td>Single gas velocity</td>
            <td><i>AsaliVector</i></td>
            <td>m/s</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mean_free_path(&asali)</i></b></th>
            <td>Single mean free path</td>
            <td><i>AsaliVector</i></td>
            <td>m</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_binary_diffusion(&asali)</i></b></th>
            <td>Single binary diffusion</td>
            <td><i>AsaliMatrix</i></td>
            <td>m<sup>2</sup>/s</td>
        </tr>
    </tbody>
</table>