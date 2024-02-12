---
permalink: /docs/api-rust/
---
<h1 class="text-left"><b>Rust version</b></h1>
The Rust API can be included in your code as follow:  
```rust
//Include library
mod definitions;
mod omega;
mod thermo;
mod transport;
mod asali;

fn main() {
    //Create asali object
    let mut asali_obj = asali::Asali::new();
    
    //Set temperature
    asali_obj.set_temperature(393.15);

    //Set pressure
    asali_obj.set_pressure(4.0e5);
    
    //Set number of species
    asali_obj.set_number_of_species(3);
    
    //Set specie names
    asali_obj.set_species_names(vec!["H2".to_string(), "O2".to_string(), "N2".to_string()]);
    
    //Set mole composition
    asali_obj.set_mole_fraction(vec![0.1,0.2,0.7]);

    //Properties evaluation
    let diff = asali_obj.get_binary_diffusion();
    let cp = asali_obj.get_species_mass_specific_heat();
}
```
Example and database generator can be compiled by typing:
```
cargo build
```

To convert the Asali database into C code run:
```
cargo run --bin database-generator
```
## **Available thermodynamic and transport properties**
ASALI estimates different thermodynamic and transport (`asali` is the library object):
<div class="table-responsive">
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
                <th scope="row"><b><i>asali.density()</i></b></th>
                <td>Mixture density</td>
                <td><i>f64</i></td>
                <td>kg/m<sup>3</sup></td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixture_molecular_weight()</i></b></th>
                <td>Mixture molecular weight</td>
                <td><i>f64</i></td>
                <td>g/mol</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixture_thermal_conductivity()</i></b></th>
                <td>Mixture thermal conductivity</td>
                <td><i>f64</i></td>
                <td>W/m/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixture_viscosity()</i></b></th>
                <td>Mixture viscosity</td>
                <td><i>f64</i></td>
                <td>Pa*s</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixture_molar_cp()</i></b></th>
                <td>Mixture specific heat</td>
                <td><i>f64</i></td>
                <td>J/kmol/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixture_mass_cp()</i></b></th>
                <td>Mixture specific heat</td>
                <td><i>f64</i></td>
                <td>J/kg/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixture_molar_enthalpy()</i></b></th>
                <td>Mixture enthalpy</td>
                <td><i>f64</i></td>
                <td>J/kmol</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixture_mass_enthalpy()</i></b></th>
                <td>Mixture enthalpy</td>
                <td><i>f64</i></td>
                <td>J/kg</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixture_molar_entropy()</i></b></th>
                <td>Mixture entropy</td>
                <td><i>f64</i></td>
                <td>J/kmol/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixture_mass_entropy()</i></b></th>
                <td>Mixture entropy</td>
                <td><i>f64</i></td>
                <td>J/kg/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixture_diffusion()</i></b></th>
                <td>Mixture diffusivity</td>
                <td><i>Vec&lt;f64&gt;</i></td>
                <td>m<sup>2</sup>/s</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.species_thermal_conductivity()</i></b></th>
                <td>Single specie thermal conductivity</td>
                <td><i>Vec&lt;f64&gt;</i></td>
                <td>W/m/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.species_viscosity()</i></b></th>
                <td>Single specie viscosity</td>
                <td><i>Vec&lt;f64&gt;</i></td>
                <td>Pa*s</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.species_molar_cp()</i></b></th>
                <td>Single specie specific heat</td>
                <td><i>Vec&lt;f64&gt;</i></td>
                <td>J/kmol/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.species_mass_cp()</i></b></th>
                <td>Single specie specific heat</td>
                <td><i>Vec&lt;f64&gt;</i></td>
                <td>J/kg/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.species_molar_enthalpy()</i></b></th>
                <td>Single specie enthalpy</td>
                <td><i>Vec&lt;f64&gt;</i></td>
                <td>J/kmol</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.species_mass_enthalpy()</i></b></th>
                <td>Single specie enthalpy</td>
                <td><i>Vec&lt;f64&gt;</i></td>
                <td>J/kg</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.species_molar_entropy()</i></b></th>
                <td>Single specie entropy</td>
                <td><i>Vec&lt;f64&gt;</i></td>
                <td>J/kmol/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.species_mass_entropy()</i></b></th>
                <td>Single specie entropy</td>
                <td><i>Vec&lt;f64&gt;</i></td>
                <td>J/kg/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.arithmetic_mean_gas_velocity()</i></b></th>
                <td>Single gas velocity</td>
                <td><i>Vec&lt;f64&gt;</i></td>
                <td>m/s</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mean_free_path()</i></b></th>
                <td>Single mean free path</td>
                <td><i>Vec&lt;f64&gt;</i></td>
                <td>m</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.binary_diffusion()</i></b></th>
                <td>Single binary diffusion</td>
                <td><i>Vec&lt;Vec&lt;f64&gt;&gt;</i></td>
                <td>m<sup>2</sup>/s</td>
            </tr>
        </tbody>
    </table>
</div>