---
permalink: /docs/api-python/
---
<h1 class="text-left"><b>Python version</b></h1>
The Python version of ASALI is composed by the **API version** to estimate themodynamic/transport properties and **[ASALIPY](https://github.com/srebughini/ASALIPY)** to model catalytic reactors.

## **API version**
The [Python](https://it.mathworks.com/campaigns/products/trials.html?s_eid=ppc_29775072802&q=matlab) API can be inlcuded in your code as follow:
```python
# Class initialization and set up composition, pressure and temperature
asali = Asali(373.15, 4e05)
asali.mole_composition = {"H2": 0.1, "O2": 0.2, "N2": 0.7}

# Properties evaluation
cp = asali.species_mass_specific_heat
diff = asali.mixture_diffusion
```
To convert the Asali database into Python code run `python database-generator.py`

## **Available thermodynamic and transport properties**
ASALI estimates different thermodynamic and transport properties (`p` is the Asali object):
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
                <th scope="row"><b><i>p.density</i></b></th>
                <td>Mixture density</td>
                <td><i>float</i></td>
                <td>kg/m<sup>3</sup></td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.mixture_molecular_weight</i></b></th>
                <td>Mixture molecular weight </td>
                <td><i>float</i></td>
                <td>g/mol</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.mixture_thermal_conductivity</i></b></th>
                <td>Mixture thermal conductivity </td>
                <td><i>float</i></td>
                <td>W/m/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.mixture_viscosity</i></b></th>
                <td>Mixture viscosity </td>
                <td><i>float</i></td>
                <td>Pa*s</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.mixture_molar_specific_heat</i></b></th>
                <td>Mixture specific heat </td>
                <td><i>float</i></td>
                <td>J/kmol/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.mixture_mass_specific_heat</i></b></th>
                <td>Mixture specific heat </td>
                <td><i>float</i></td>
                <td>J/kg/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.mixture_molar_enthalpy</i></b></th>
                <td>Mixture enthalpy</td>
                <td><i>float</i></td>
                <td>J/kmol</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.mixture_mass_enthalpy</i></b></th>
                <td>Mixture enthalpy</td>
                <td><i>float</i></td>
                <td>J/kg</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.mixture_molar_entropy</i></b></th>
                <td>Mixture entropy</td>
                <td><i>float</i></td>
                <td>J/kmol/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.mixture_mass_entropy</i></b></th>
                <td>Mixture entropy</td>
                <td><i>float</i></td>
                <td>J/kg/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.mixture_diffusion</i></b></th>
                <td>Mixture diffusivity</td>
                <td><i>float</i></td>
                <td>m<sup>2</sup>/s</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.specie_thermal_conductivity</i></b></th>
                <td>Single specie thermal conductivity</td>
                <td><i>1D array</i></td>
                <td>W/m/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.specie_viscosity</i></b></th>
                <td>Single specie viscosity</td>
                <td><i>1D array</i></td>
                <td>Pa*s</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.species_molar_specific_heat</i></b></th>
                <td>Single specie specific heat</td>
                <td><i>1D array</i></td>
                <td>J/kmol/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.species_mass_specific_heat</i></b></th>
                <td>Single specie specific heat</td>
                <td><i>1D array</i></td>
                <td>J/kg/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.specie_molar_enthalpy</i></b></th>
                <td>Single specie enthalpy</td>
                <td><i>1D array</i></td>
                <td>J/kmol</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.specie_mass_enthalpy</i></b></th>
                <td>Single specie enthalpy</td>
                <td><i>1D array</i></td>
                <td>J/kmol</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.specie_molar_entropy</i></b></th>
                <td>Single specie entropy</td>
                <td><i>1D array</i></td>
                <td>J/kmol/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.specie_mass_entropy</i></b></th>
                <td>Single specie entropy</td>
                <td><i>1D array</i></td>
                <td>J/kg/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.mean_gas_velocity</i></b></th>
                <td>Single gas velocity</td>
                <td><i>1D array</i></td>
                <td>m/s</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.mean_free_path</i></b></th>
                <td>Single mean free path</td>
                <td><i>1D array</i></td>
                <td>m</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.binary_diffusion</i></b></th>
                <td>Single binary diffusion</td>
                <td><i>2D array</i></td>
                <td>m<sup>2</sup>/s</td>
            </tr>
        </tbody>
    </table>
</div>

## **ASALIPY: Python package to model catalytic reactors**
[ASALIPY](https://github.com/srebughini/ASALIPY) has its own [conda package](https://anaconda.org/ASALIcode/asali), that can be installed as follow:

```bash
conda install -c conda-forge asalicode::asali
```

ASALIPY *does not* estimate thermodynamic and transport properties. ASALIPY is a python package to simulate catalytic reactors with the following models:
* Batch Reactor
* Continuous Stirred Tank Reactor
* 1-Dimensional Pseudo-Homogeneous Plug Flow Reactor (Steady State/Transient)
* 1-Dimensional Heterogeneous Plug Flow Reactor (Steady State/Transient)

The following examples show how to use Asalipy to simulate catalytic reactors and how to plot the results using [matplotlib](https://matplotlib.org/).

### **Batch Reactor**

This [example](https://github.com/srebughini/ASALIPY/blob/main/examples/batch.py) show how to solve a **batch reactor** for the [catalytic combustion of hydrogen over rhodium](https://www.detchem.com/mechanisms).

```python
import os
from asali.reactors.batch import BatchReactor

if __name__ == "__main__":
    # Initialize reactor class
    b = BatchReactor(os.path.join('examples/files', 'H2-O2-Rh.yaml'), 'gas', 'Rh_surface')  
    # Set reactor volume in [mm3]
    b.set_volume(10., 'mm3')  
    # Set reactor pressure in [bar]
    b.set_pressure(5, 'bar')  
    # Set catalytic load in [1/m]
    b.set_catalytic_load(15, '1/m') 
    # Set reactor initial composition using mole fraction
    b.set_initial_mole_fraction({'O2': 0.4, 'AR': 0.5, 'H2': 0.1})  
    # Set reactor initial temperature in [°C]
    b.set_initial_temperature(120, 'degC')  
    # Set reactor initial coverage
    b.set_initial_coverage({'Rh(s)': 1})  
    # Enable energy balance
    b.set_energy(1)  
    # Solve for different time steps
    b.solve([0, 0.1, 0.5, 5], 's')  
```

### **Continuous Stirred Tank Reactor**

This [example](https://github.com/srebughini/ASALIPY/blob/main/examples/cstr.py) show how to solve a **continuous stirred tank reactor** for the [catalytic combustion of hydrogen over rhodium](https://www.detchem.com/mechanisms).

```python
import os
from asali.reactors.cstr import CstrReactor

if __name__ == "__main__":
    # Initialize reactor class
    c = CstrReactor(os.path.join('files', 'H2-O2-Rh.yaml'), 'gas', 'Rh_surface')
    # Set reactor volume in [dm3]
    c.set_volume(5., 'dm3')  
    # Set reactor pressure in [bar]
    c.set_pressure(5, 'bar')  
     # Set catalytic load in [1/m]
    c.set_catalytic_load(150, '1/m') 
    # Set volumetric flow rate in [m3/h]
    c.set_volumetric_flow_rate(1, 'm3/h')  
    # Set inlet gas temperature in [°C]
    c.set_inlet_temperature(120, 'degC')  
    # Set inlet gas composition using mass fraction
    c.set_inlet_mass_fraction({'O2': 0.4, 'AR': 0.5, 'H2': 0.1})  
    # Set reactor initial composition using mass fraction
    c.set_initial_mass_fraction({'AR': 1})  
    # Set reactor initial temperature in [°C]
    c.set_initial_temperature(50, 'degC')  
    # Set reactor initial coverage
    c.set_initial_coverage({'Rh(s)': 1})  
    # Enable energy balance
    c.set_energy(1)  
    # Solve for different time steps in [s]
    c.solve(list(range(0, 30, 1)), 's')  
```

### **1-D Pseudo-Homogeneous Plug Flow Reactor**
#### **Transient**

This [example](https://github.com/srebughini/ASALIPY/blob/main/examples/ph1d_transient.py) show how to solve a **transient 1-D pseudo-homogeneous plug flow reactor** for the [catalytic combustion of hydrogen over rhodium](https://www.detchem.com/mechanisms).

```python
import os
from asali.reactors.ph1d_transient import TransientPseudoHomogeneous1DReactor

if __name__ == "__main__":
    # Initialize reactor class
    p = TransientPseudoHomogeneous1DReactor(os.path.join('files', 'H2-O2-Rh.yaml'), 'gas', 'Rh_surface')  
    # Set reactor length in [m]
    p.set_length(2.5, 'm')  
    # Set reactor diameter in [mm]
    p.set_diameter(10., 'mm')  
    # Set reactor pressure in [bar]
    p.set_pressure(20, 'bar')  
    # Set catalytic load in [1/m]
    p.set_catalytic_load(75, '1/m')  
    # Set volumetric flow rate in [m3/h]
    p.set_volumetric_flow_rate(10, 'm3/h') 
    # Set inlet gas temperature in [°C]
    p.set_inlet_temperature(240, 'degC')  
    # Set inlet gas composition using mass fraction
    p.set_inlet_mass_fraction({'O2': 0.4, 'AR': 0.5, 'H2': 0.1})  
    # Set reactor initial coverage
    p.set_initial_coverage({'Rh(s)': 1})  
    # Enable energy balance
    p.set_energy(True)  
    # Set reactor initial composition using mass fraction
    p.set_initial_mass_fraction({'O2': 0.4, 'AR': 0.5, 'H2': 0.1})  
    # Set inert specie
    p.set_inert_specie('AR')  
    # Set inert coverage
    p.set_inert_coverage('Rh(s)')  
    # Set reactor initial temperature in [°C]
    p.set_initial_temperature(240, 'degC')  
     # Disable gas diffusion
    p.set_gas_diffusion(False) 
    # Disable solver verbosity
    p.set_verbosity(False)  
    # Set solver relative tolerance
    p.set_relative_tolerance(1.e-04)  
    # Set solver absolute tolerance
    p.set_absolute_tolerance(1.e-04)  
    # Solve for different time steps in [s]
    p.solve([0, 0.005, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06], 's')  
```

#### **Steady State**

This [example](https://github.com/srebughini/ASALIPY/blob/main/examples/ph1d_steady_state.py) show how to solve a **steady state 1-D pseudo-homogeneous plug flow reactor** for the [catalytic combustion of hydrogen over rhodium](https://www.detchem.com/mechanisms).

```python
import os
from asali.reactors.ph1d_steady_state import SteadyStatePseudoHomogeneous1DReactor

if __name__ == "__main__":
    # Initialize reactor class
    p = SteadyStatePseudoHomogeneous1DReactor(os.path.join('files', 'H2-O2-Rh.yaml'), 'gas', 'Rh_surface') 
    # Set reactor length in [m]
    p.set_length(2.5, 'm')  
    # Set reactor diameter in [mm]
    p.set_diameter(10., 'mm')  
    # Set reactor pressure in [bar]
    p.set_pressure(20, 'bar')  
    # Set catalytic load in [1/m]
    p.set_catalytic_load(75, '1/m')  
    # Set volumetric flow rate in [m3/h]
    p.set_volumetric_flow_rate(10, 'm3/h')  
    # Set inlet gas temperature in [°C]
    p.set_inlet_temperature(240, 'degC')  
    # Set inlet gas composition using mass fraction
    p.set_inlet_mass_fraction({'O2': 0.4, 'AR': 0.5, 'H2': 0.1})  
    # Set reactor initial coverage
    p.set_initial_coverage({'Rh(s)': 1}) 
    # Enable energy balance 
    p.set_energy(True)  
    # Set inert specie
    p.set_inert_specie('AR')  
    # Set inert coverage
    p.set_inert_coverage('Rh(s)')  
    # Enable gas diffusion
    p.set_gas_diffusion(True)  
    # Disable solver verbosity
    p.set_verbosity(False)  
    # Solve
    p.solve()  
```

### **1-D Heterogeneous Plug Flow Reactor**
#### **Transient**
This [example](https://github.com/srebughini/ASALIPY/blob/main/examples/het1d_transient.py) show how to solve a **transient 1-D
heterogeneous plug flow reactor** for
the [catalytic combustion of hydrogen over rhodium](https://www.detchem.com/mechanisms).

```python
import os
from asali.reactors.ph1d_transient import TransientPseudoHomogeneous1DReactor

if __name__ == "__main__":
    # Initialize reactor class
    p = TransientPseudoHomogeneous1DReactor(os.path.join('files', 'H2-O2-Rh.yaml'), 'gas', 'Rh_surface')
    # Set reactor length in [m]
    p.set_length(2.5, 'm')  
    # Set reactor diameter in [mm]
    p.set_diameter(10., 'mm')  
    # Set reactor pressure in [bar]
    p.set_pressure(20, 'bar')  
    # Set catalytic load in [1/m]
    p.set_catalytic_load(75, '1/m')  
    # Set volumetric flow rate in [m3/h]
    p.set_volumetric_flow_rate(10, 'm3/h')  
     # Set inlet gas temperature in [°C]
    p.set_inlet_temperature(240, 'degC') 
    # Set inlet gas composition using mass fraction
    p.set_inlet_mass_fraction({'O2': 0.4, 'AR': 0.5, 'H2': 0.1})  
    # Set reactor initial coverage
    p.set_initial_coverage({'Rh(s)': 1})  
    # Enable energy balance
    p.set_energy(True)  
    # Set reactor initial composition using mass fraction
    p.set_initial_mass_fraction({'O2': 0.4, 'AR': 0.5, 'H2': 0.1})  
    # Set inert specie
    p.set_inert_specie('AR') 
    # Set inert coverage 
    p.set_inert_coverage('Rh(s)')  
    # Set reactor initial temperature in [°C]
    p.set_initial_temperature(240, 'degC')  
    # Disable gas diffusion
    p.set_gas_diffusion(False)  
    # Disable solver verbosity
    p.set_verbosity(False)  
    # Set solver relative tolerance
    p.set_relative_tolerance(1.e-04)  
    # Set solver absolute tolerance
    p.set_absolute_tolerance(1.e-04)  
    # Solve for different time steps in [s]
    p.solve([0, 0.005, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06], 's')  
```
#### **Steady State**
This [example](https://github.com/srebughini/ASALIPY/blob/main/examples/het1d_steady_state.py) show how to solve a **steady state 1-D
heterogeneous plug flow reactor** for the [catalytic combustion of hydrogen over rhodium](https://www.detchem.com/mechanisms).

```python
import os
from asali.reactors.het1d_steady_state import SteadyStateHeterogeneous1DReactor

if __name__ == "__main__":
    # Initialize reactor class
    h = SteadyStateHeterogeneous1DReactor(os.path.join('files', 'H2-O2-Rh.yaml'), 'gas', 'Rh_surface')  
    # Set reactor length in [m]
    h.set_length([0, 0.001, 0.025, 0.05, 0.1, 0.15, 0.2, 0.6, 0.65, 1.0, 1.5, 2.0, 3.0], 'm')  
    # Set reactor pressure in [bar]
    h.set_pressure(20, 'bar')  
    # Set catalytic load in [1/m]
    h.set_catalytic_load(150, '1/m')  
    # Set volumetric flow rate in [m3/h]
    h.set_volumetric_flow_rate(10, 'm3/h')  
    # Set inlet gas temperature in [°C]
    h.set_inlet_temperature(300, 'degC')  
    # Set inlet gas composition using mass fraction
    h.set_inlet_mass_fraction({'O2': 0.4, 'AR': 0.5, 'H2': 0.1})  
    # Set reactor initial coverage
    h.set_initial_coverage({'Rh(s)': 1})  
    # Set catalyst density in [kg/m3]
    h.set_solid_density(2300, 'kg/m3')  
    # Set catalyst specific heat in [J/kg/K]
    h.set_solid_specific_heat(750, 'J/kg/degK')  
    # Set catalyst thermal conductivity in [W/m/K]
    h.set_solid_thermal_conductivity(2.5, 'W/m/degK')  
    # Set initial catalyst temperature in [°C]
    h.set_initial_solid_temperature(300, 'degC')  
    # Enable energy balance
    h.set_energy(True)  
    # Enable gas diffusion
    h.set_gas_diffusion(True)  
    # Set packed bed reactor properties
    h.set_packed_bed_reactor(0.3, 'mm', 1, 'cm', 0.75)  
    # Solve
    h.solve()  
```

### **Reactor Plotter**

This [example](https://github.com/srebughini/ASALIPY/blob/main/examples/het1d_transient.py) show how to **solve and plot** 1-D heterogeneous plug flow reactor for the [catalytic combustion of hydrogen over rhodium](https://www.detchem.com/mechanisms).

```python
import os
from asali.reactors.het1d_transient import TransientHeterogeneous1DReactor
from asali.plotters.reactor import ReactorPlotter

if __name__ == "__main__":
    h = TransientHeterogeneous1DReactor(os.path.join('files', 'H2-O2-Rh.yaml'), 'gas', 'Rh_surface')
    h.set_length([0, 0.5, 1.0, 1.5, 2.0], 'm')
    h.set_pressure(5, 'bar')
    h.set_catalytic_load(35, '1/m')
    h.set_volumetric_flow_rate(15., 'm3/h')
    h.set_inlet_temperature(250, 'degC')
    h.set_inlet_mass_fraction({'O2': 0.4, 'AR': 0.5, 'H2': 0.1})
    h.set_initial_coverage({'Rh(s)': 1})
    h.set_solid_density(2300, 'kg/m3')
    h.set_solid_specific_heat(750, 'J/kg/degK')
    h.set_solid_thermal_conductivity(2.5, 'W/m/degK')
    h.set_initial_solid_temperature(250, 'degC')
    h.set_energy(True)
    h.set_gas_diffusion(True)
    h.set_verbosity(False)
    h.set_initial_mass_fraction({'O2': 0.4, 'AR': 0.5, 'H2': 0.1})
    h.set_initial_temperature(250, 'degC')
    h.set_packed_bed_reactor(0.3, 'mm', 1, 'cm', 0.75)
    h.solve([0, 0.1, 0.2, 0.3, 0.5, 0.75, 1.0, 2.0, 4.0, 10., 20.], 's')

    # Initialize plotting object
    plt = ReactorPlotter(h)  
    # Plot mass fraction from species names
    plt.plot_species_mass_fraction(['H2', 'H2O', 'O2'])  
    # Plot mole fraction from species names
    plt.plot_species_mole_fraction(['H2', 'H2O', 'O2'])  
    # Plot coverage from coverage names
    plt.plot_coverage(['Rh(s)', 'H(s)', 'O(s)', 'OH(s)'])  
    # Plot temperature
    plt.plot_temperature()  
    # Show plots
    plt.show()  
```


## **Cantera file converter**

This [example](https://github.com/srebughini/ASALIPY/blob/main/examples/canterafiles.py) show how to **convert** [Cantera](https://cantera.org/) file formats.

```python
import os
from asali.utils.cantera_file_converter import CanteraFileConverter

if __name__ == "__main__":
    # Convert from CHEMKIN format to YAML format
    CanteraFileConverter.from_chemkin_to_yaml(kinetic_file_path=os.path.join("files", "kinetic.kin"),
                                              thermodynamic_file_path=os.path.join("files", "thermo.tdc"),
                                              transport_file_path=os.path.join("files", "transport.tra"),
                                              surface_file_path=os.path.join("files", "surface.sur"),
                                              output_file_path=os.path.join("files", "output_v3.yaml"))
```
## **Reactor Saver**

This [example](https://github.com/srebughini/ASALIPY/blob/main/examples/ph1d_steady_statet.py) show how to **solve and save** 1-D pseudo-homogeneous plug flow reactor for the [catalytic combustion of hydrogen over rhodium](https://www.detchem.com/mechanisms).

```python
import os

from asali.reactors.ph1d_steady_state import SteadyStatePseudoHomogeneous1DReactor
from asali.savers.reactor import ReactorSaver

if __name__ == "__main__":
    p = SteadyStatePseudoHomogeneous1DReactor(os.path.join('files', 'H2-O2-Rh.yaml'), 'gas', 'Rh_surface')
    p.set_length(2.5, 'm')
    p.set_diameter(10., 'mm')
    p.set_pressure(20, 'bar')
    p.set_catalytic_load(75, '1/m')
    p.set_volumetric_flow_rate(10, 'm3/h')
    p.set_inlet_temperature(240, 'degC')
    p.set_inlet_mass_fraction({'O2': 0.4, 'AR': 0.5, 'H2': 0.1})
    p.set_initial_coverage({'Rh(s)': 1})
    p.set_energy(True)
    p.set_inert_specie('AR')
    p.set_inert_coverage('Rh(s)')
    p.set_gas_diffusion(True)
    p.set_verbosity(False)
    p.solve()

    # Initialize the saver object
    svr = ReactorSaver(p)
    #Save results on file
    svr.save_using_mole_fraction(os.path.join('files', 'output_ph1d_steady_state_mole_fraction.xlsx'),
                                 species_names=['H2', 'H2O', 'O2', 'AR'],
                                 coverage_names=['Rh(s)', 'H(s)', 'O(s)', 'OH(s)']) 
```