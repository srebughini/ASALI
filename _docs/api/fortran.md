---
permalink: /docs/api-fortran/
redirect_from: /docs/index.html
---

# **Fortran version**
The Fortran API requires the [Lapack libraries](http://www.netlib.org/lapack/) which can be install with the following command:

```
sudo apt-get install liblapack-dev
``` 
This version can be included in your code as follow:  
```fortran
!Include library
include "Asali.f90"

!Main
program example
    use asali
    implicit none

    character(len=200), dimension(3) :: names
    
    real, dimension(3) :: x, cp
    
    names(1) = 'H2'
    names(2) = 'O2'
    names(3) = 'N2'
    
    x(1) = 0.1
    x(2) = 0.2
    x(3) = 1 - x(1) - x(2)
    
    !Set up composition/pressure and temperature
    call set_temperature(393.15)
    call set_pressure(4e05)
    call set_number_of_species(3)
    call set_species_names(names)
    call set_mole_fraction(x)
    
    !Properties evaluation
    cp = get_species_mass_specific_heat()
```

Example and database generator can be compiled by typing:
```
./compile.sh
```

To convert the Asali database into Fortran code run:
```
./database-generator
```
## Available thermodynamic and transport properties
ASALI estimates different thermodynamic and transport properties (`N` is the number of species):

**`get_density()`**
| | |
|:-|:-|
| *Estimated property*|Mixture density|
| *Return type*       |`real`|
| *Unit dimensions*   |kg/m<sup>3</sup>|
| | |
**`get_mixture_molecular_weight()`**
| | |
|:-|:-|
| *Estimated property*|Mixture molecular weight |
| *Return type*       |`real`|
| *Unit dimensions*   |g/mol|
| | |
| **`get_mixture_thermal_conductivity()`** | |
| *Estimated property*|Mixture thermal conductivity |
| *Return type*       |`real`|
| *Unit dimensions*   |W/m/K|
| | |
| **`get_mixture_viscosity()`** | |
| *Estimated property*|Mixture viscosity |
| *Return type*       |`real`|
| *Unit dimensions*   |Pa*s|
| | |
| **`get_mixture_molar_specific_heat()`** | |
| *Estimated property*|Mixture specific heat |
| *Return type*       |`real`|
| *Unit dimensions*   |J/kmol/K|
 | | |
| **`get_mixture_mass_specific_heat()`** | |
| *Estimated property*|Mixture specific heat |
| *Return type*       |`real`|
| *Unit dimensions*   |J/kg/K|
| | |
| **`get_mixture_molar_enthalpy()`** | |
| *Estimated property*|Mixture enthalpy|
| *Return type*       |`real`|
| *Unit dimensions*   |J/kmol|
| | |
| **`get_mixture_mass_enthalpy()`** | |
| *Estimated property*|Mixture enthalpy|
| *Return type*       |`real`|
| *Unit dimensions*   |J/kg|
| | |
| **`get_mixture_molar_entropy()`** | |
| *Estimated property*|Mixture entropy|
| *Return type*       |`real`|
| *Unit dimensions*   |J/kmol/K|
| | |
| **`get_mixture_mass_entropy()`** | |
| *Estimated property*|Mixture entropy|
| *Return type*       |`real`|
| *Unit dimensions*   |J/kg/K|
| | |
| **`get_mixture_diffusion()`** | |
| *Estimated property*|Mixture diffusivity|
| *Return type*       |`real`|
| *Unit dimensions*   |m<sup>2</sup>/s|
| | |
| **`get_species_thermal_conductivity()`** | |
| *Estimated property*|Single specie thermal conductivity|
| *Return type*       |`real, dimension(N)`|
| *Unit dimensions*   |W/m/K|
| | |
| **`get_species_viscosity()`** | |
| *Estimated property*|Single specie viscosity|
| *Return type*       |`real, dimension(N)`|
| *Unit dimensions*   |Pa*s|
| | |
| **`get_species_molar_specific_heat()`** | |
| *Estimated property*|Single specie specific heat|
| *Return type*       |`real, dimension(N)`|
| *Unit dimensions*   |J/kmol/K|
| | |
| **`get_species_mass_specific_heat()`** | |
| *Estimated property*|Single specie specific heat|
| *Return type*       |`real, dimension(N)`|
| *Unit dimensions*   |J/kg/K|
| | |
| **`get_species_molar_enthalpy()`** | |
| *Estimated property*|Single specie enthalpy|
| *Return type*       |`real, dimension(N)`|
| *Unit dimensions*   |J/kmol|
| | |
| **`get_species_mass_enthalpy()`** | |
| *Estimated property*|Single specie enthalpy|
| *Return type*       |`real, dimension(N)`|
| *Unit dimensions*   |J/kg|
| | |
| **`get_species_molar_entropy()`** | |
| *Estimated property*|Single specie entropy|
| *Return type*       |`real, dimension(N)`|
| *Unit dimensions*   |J/kmol/K|
| | |
| **`get_species_mass_entropy()`** | |
| *Estimated property*|Single specie entropy|
| *Return type*       |`real, dimension(N)`|
| *Unit dimensions*   |J/kg/K|
| | |
| **`get_aritmetic_mean_gas_velocity()`** | |
| *Estimated property*|Single gas velocity|
| *Return type*       |`real, dimension(N)`|
| *Unit dimensions*   |m/s|
| | |
| **`get_mean_free_path()`** | |
| *Estimated property*|Single mean free path|
| *Return type*       |`real, dimension(N)`|
| *Unit dimensions*   |m|
| | |
| **`get_binary_diffusion()`** | |
| *Estimated property*|Single binary diffusion|
| *Return type*       |`real, dimension(N,N)`|
| *Unit dimensions*   |m<sup>2</sup>/s|
