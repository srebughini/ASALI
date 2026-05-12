---
permalink: /docs/api-julia/
---
<h1 class="text-left"><b>Julia version</b></h1>
The Julia API can be included in your code as follow:  
```julia
include("asali.jl")

species = String["H2","O2","N2"]
x = Float64[0.1,0.2,0.7]
asali.set_temperature(393.15)
asali.set_pressure(4e05)
asali.set_number_of_species(3)
asali.set_species_names(species)
asali.set_mole_fraction(x)

diff = asali.get_binary_diffusion()
cp = asali.get_species_mass_specific_heat()
```
The example can be run by typing:
```
julia database-generator.jl
julia example.jl
```
## **Available thermodynamic and transport properties**
ASALI estimates different thermodynamic and transport (`asali` is the library object):
<div class="table-responsive">
    <table class="table table-striped">
        <thead>
            <tr>
                <th scope="row">Function</th>
                <th>Estimated property</th>
                <th>Unit dimension</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <th scope="row"><b><i>asali.density()</i></b></th>
                <td>Mixture density</td>
                <td>kg/m<sup>3</sup></td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixture_molecular_weight()</i></b></th>
                <td>Mixture molecular weight</td>
                <td>g/mol</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixture_thermal_conductivity()</i></b></th>
                <td>Mixture thermal conductivity</td>
                <td>W/m/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixture_viscosity()</i></b></th>
                <td>Mixture viscosity</td>
                <td>Pa*s</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixture_molar_cp()</i></b></th>
                <td>Mixture specific heat</td>
                <td>J/kmol/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixture_mass_cp()</i></b></th>
                <td>Mixture specific heat</td>
                <td>J/kg/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixture_molar_enthalpy()</i></b></th>
                <td>Mixture enthalpy</td>
                <td>J/kmol</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixture_mass_enthalpy()</i></b></th>
                <td>Mixture enthalpy</td>
                <td>J/kg</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixture_molar_entropy()</i></b></th>
                <td>Mixture entropy</td>
                <td>J/kmol/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixture_mass_entropy()</i></b></th>
                <td>Mixture entropy</td>
                <td>J/kg/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixture_diffusion()</i></b></th>
                <td>Mixture diffusivity</td>
                <td>m<sup>2</sup>/s</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.species_thermal_conductivity()</i></b></th>
                <td>Single specie thermal conductivity</td>
                <td>W/m/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.species_viscosity()</i></b></th>
                <td>Single specie viscosity</td>
                <td>Pa*s</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.species_molar_cp()</i></b></th>
                <td>Single specie specific heat</td>
                <td>J/kmol/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.species_mass_cp()</i></b></th>
                <td>Single specie specific heat</td>
                <td>J/kg/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.species_molar_enthalpy()</i></b></th>
                <td>Single specie enthalpy</td>
                <td>J/kmol</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.species_mass_enthalpy()</i></b></th>
                <td>Single specie enthalpy</td>
                <td>J/kg</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.species_molar_entropy()</i></b></th>
                <td>Single specie entropy</td>
                <td>J/kmol/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.species_mass_entropy()</i></b></th>
                <td>Single specie entropy</td>
                <td>J/kg/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.arithmetic_mean_gas_velocity()</i></b></th>
                <td>Single gas velocity</td>
                <td>m/s</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mean_free_path()</i></b></th>
                <td>Single mean free path</td>
                <td>m</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.binary_diffusion()</i></b></th>
                <td>Single binary diffusion</td>
                <td>m<sup>2</sup>/s</td>
            </tr>
        </tbody>
    </table>
</div>