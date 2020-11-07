---
permalink: /docs/api-fortran/
redirect_from: /docs/index.html
---

## **Fortran version**
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
ASALI estimates different thermodynamic and transport properties with the following functions:
* `get_density()`
    * Mixture density in kg/m3
    * The return value is a `real`.


* `get_mixture_molecular_weight()`
    * Mixture molecular weight in g/mol
    * The return value is a `real`.


* `get_mixture_thermal_conductivity()`
    * Mixture thermal conductivity in W/m/K
    * The return value is a `real`.


* `get_mixture_viscosity()`
    * Mixture viscosity in Pas*s.
    * The return value is a `real`.


* `get_mixture_molar_specific_heat()`
    * Mixture specific heat in J/kmol/K.
    * The return value is a `real`.


* `get_mixture_mass_specific_heat()`
    * Mixture specific heat in J/kg/K.
    * The return value is a `real`.


* `get_mixture_molar_enthalpy()`
    * Mixture enthalpy in J/kmol.
    * The return value is a `real`.


* `get_mixture_mass_enthalpy()`
    * Mixture enthalpy in J/kg.
    * The return value is a `real`.


* `get_mixture_molar_entropy()`
    * Mixture entropy in J/kmol/K.
    * The return value is a `real`.


* `get_mixture_mass_entropy()`
    * Mixture entropy in J/kg/K.
    * The return value is a `real`.


* `get_mixture_diffusion()`
    * Mixture diffusivity in m2/s. 
    * The return value is a `real, dimension(N)`, where `N` is the number of species.


* `get_species_thermal_conductivity()`
    * Single species viscosity in W/m/K
    * The return value is a `real, dimension(N)`, where `N` is the number of species.


* `get_species_viscosity()`
    * Single species viscosity in Pa*s.
    * The return value is a `real, dimension(N)`, where `N` is the number of species.


* `get_species_molar_specific_heat()`
    * Single species specific heat in J/kmol/K.
    * The return value is a `real, dimension(N)`, where `N` is the number of species.


* `get_species_mass_specific_heat()`
    * Single species specific heat in J/kg/K.
    * The return value is a `real, dimension(N)`, where `N` is the number of species.


* `get_species_molar_enthalpy()`
    * Single species enthalpy in J/kmol.
    * The return value is a `real, dimension(N)`, where `N` is the number of species.


* `get_species_mass_enthalpy()`
    * Single species enthalpy in J/kg. 
    * The return value is a `real, dimension(N)`, where `N` is the number of species.


* `get_species_molar_entropy()`
    * Single species entropy in J/kmol/K.
    * The return value is a `real, dimension(N)`, where `N` is the number of species.


* `get_species_mass_entropy()`
    * Single species entropy in J/kg/K.
    * The return value is a `real, dimension(N)`, where `N` is the number of species.


* `get_aritmetic_mean_gas_velocity()`
    * Single gas velocity in m/s. 
    * The return value is a `real, dimension(N)`, where `N` is the number of species.


* `get_mean_free_path()`
    * Single species mean free path in m.
    * The return value is a `real, dimension(N)`, where `N` is the number of species.


* `get_binary_diffusion()`
    * Single species binary diffusion in m2/s.
    * The return value is a `real, dimension(N,N)`, where `N` is the number of species.