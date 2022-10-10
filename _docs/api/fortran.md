---
title: Fortran version
permalink: /docs/api-fortran/
---

The Fortran API can be included in your code as follow:  
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
## **Available thermodynamic and transport properties**
ASALI estimates different thermodynamic and transport properties (`N` is the number of species):
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
            <th scope="row"><b><i>get_density()</i></b></th>
            <td>Mixture density</td>
            <td><i>real</i></td>
            <td>kg/m<sup>3</sup></td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mixture_molecular_weight()</i></b></th>
            <td>Mixture molecular weight</td>
            <td><i>real</i></td>
            <td>g/mol</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mixture_thermal_conductivity()</i></b></th>
            <td>Mixture thermal conductivity</td>
            <td><i>real</i></td>
            <td>W/m/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mixture_viscosity()</i></b></th>
            <td>Mixture viscosity</td>
            <td><i>real</i></td>
            <td>Pa*s</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mixture_molar_specific_heat()</i></b></th>
            <td>Mixture specific heat</td>
            <td><i>real</i></td>
            <td>J/kmol/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mixture_mass_specific_heat()</i></b></th>
            <td>Mixture specific heat</td>
            <td><i>real</i></td>
            <td>J/kg/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mixture_molar_enthalpy()</i></b></th>
            <td>Mixture enthalpy</td>
            <td><i>real</i></td>
            <td>J/kmol</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mixture_mass_enthalpy()</i></b></th>
            <td>Mixture enthalpy</td>
            <td><i>real</i></td>
            <td>J/kg</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mixture_molar_entropy()</i></b></th>
            <td>Mixture entropy</td>
            <td><i>real</i></td>
            <td>J/kmol/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mixture_mass_entropy()</i></b></th>
            <td>Mixture entropy</td>
            <td><i>real</i></td>
            <td>J/kg/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mixture_diffusion()</i></b></th>
            <td>Mixture diffusivity</td>
            <td><i>real</i></td>
            <td>m<sup>2</sup>/s</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_species_thermal_conductivity()</i></b></th>
            <td>Single specie thermal conductivity</td>
            <td><i>real, dimension(N)</i></td>
            <td>W/m/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_species_viscosity()</i></b></th>
            <td>Single specie viscosity</td>
            <td><i>real, dimension(N)</i></td>
            <td>Pa*s</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_species_molar_specific_heat()</i></b></th>
            <td>Single specie specific heat</td>
            <td><i>real, dimension(N)</i></td>
            <td>J/kmol/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_species_mass_specific_heat()</i></b></th>
            <td>Single specie specific heat</td>
            <td><i>real, dimension(N)</i></td>
            <td>J/kg/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_species_molar_enthalpy()</i></b></th>
            <td>Single specie enthalpy</td>
            <td><i>real, dimension(N)</i></td>
            <td>J/kmol</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_species_mass_enthalpy()</i></b></th>
            <td>Single specie enthalpy</td>
            <td><i>real, dimension(N)</i></td>
            <td>J/kg</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_species_molar_entropy()</i></b></th>
            <td>Single specie entropy</td>
            <td><i>real, dimension(N)</i></td>
            <td>J/kmol/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_species_mass_entropy()</i></b></th>
            <td>Single specie entropy</td>
            <td><i>real, dimension(N)</i></td>
            <td>J/kg/K</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_aritmetic_mean_gas_velocity()</i></b></th>
            <td>Single gas velocity</td>
            <td><i>real, dimension(N)</i></td>
            <td>m/s</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_mean_free_path()</i></b></th>
            <td>Single mean free path</td>
            <td><i>real, dimension(N)</i></td>
            <td>m</td>
        </tr>
        <tr>
            <th scope="row"><b><i>get_binary_diffusion()</i></b></th>
            <td>Single binary diffusion</td>
            <td><i>real, dimension(N,N)</i></td>
            <td>m<sup>2</sup>/s</td>
        </tr>
    </tbody>
</table>

