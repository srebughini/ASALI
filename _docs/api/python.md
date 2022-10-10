---
title: Python version
permalink: /docs/api-python/
---
The python API version of ASALI is called [ASALIPY](https://github.com/srebughini/ASALIPY) and its [conda package](https://anaconda.org/ASALIcode/asali) can be installed as follow:

```bash
conda install -c conda-forge asalicode::asali
```

Asalipy *does not* estimate thermodynamic and transport properties (if you are looking for a python package to do so, have a look to [Cantera](https://cantera.org/)). Asalipy is a python package to simulate catalytic reactors with the following models:
* Batch Reactor
* Continuous Stirred Tank Reactor
* 1-Dimensional Pseudo-Homogeneous Plug Flow Reactor (Steady State/Transient)
* 1-Dimensional Heterogeneous Plug Flow Reactor (Steady State/Transient)

The following examples show how to use Asalipy to simulate catalytic reactors and how to plot the results using [matplotlib](https://matplotlib.org/).

### **Batch Reactor**

This [example](https://github.com/srebughini/ASALIPY/blob/main/examples/batch.py) show how to solve a **batch reactor** for the [catalytic combustion of hydrogen over rhodium](https://www.detchem.com/mechanisms).

```python
from asali.reactors.batch import BatchReactor

if __name__ == "__main__":
    # Initialize reactor class
    b = BatchReactor('H2-O2-Rh.xml', 'gas', 'Rh_surface')
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
from asali.reactors.cstr import CstrReactor

if __name__ == "__main__":
    # Initialize reactor class
    c = CstrReactor('H2-O2-Rh.xml', 'gas', 'Rh_surface')
    # Set reactor volume in [m3]  
    c.set_volume(5., 'm3')  
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
    c.set_initial_temperature(25, 'degC')
    # Set reactor initial coverage  
    c.set_initial_coverage({'Rh(s)': 1}) 
    # Enable energy balance 
    c.set_energy(1)  
    # Solve for different time steps in [min]
    c.solve([0, 0.1, 0.5, 1, 2, 5], 'min')  
```

### **1-D Pseudo-Homogeneous Plug Flow Reactor**
#### **Transient**

This [example](https://github.com/srebughini/ASALIPY/blob/main/examples/ph1d_transient.py) show how to solve a **transient 1-D pseudo-homogeneous plug flow reactor** for the [catalytic combustion of hydrogen over rhodium](https://www.detchem.com/mechanisms).

```python
import os
from asali.reactors.ph1d import PseudoHomogeneous1DReactor

if __name__ == "__main__":
    # Initialize reactor class
    p = PseudoHomogeneous1DReactor(os.path.join('files', 'H2-O2-Rh.xml'), 'gas', 'Rh_surface')
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
    p.set_initial_mass_fraction( {'O2': 0.4, 'AR': 0.5, 'H2': 0.1})  
    # Set inert specie
    p.set_inert_specie('AR')  
    # Set inert coverage
    p.set_inert_coverage('Rh(s)')  
    # Set reactor initial temperature in [°C]
    p.set_initial_temperature(240, 'degC')  
    # Set resolution method
    p.set_resolution_method("TRANSIENT")  
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
from asali.reactors.ph1d import PseudoHomogeneous1DReactor

if __name__ == "__main__":
    # Initialize reactor class
    p = PseudoHomogeneous1DReactor(os.path.join('files', 'H2-O2-Rh.xml'), 'gas', 'Rh_surface')  
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
    # Set resolution method
    p.set_resolution_method("STEADYSTATE")  
    # Disable gas diffusion
    p.set_gas_diffusion(False)  
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
from asali.reactors.het1d import Heterogeneous1DReactor

if __name__ == "__main__":
    # Initialize reactor class
    h = Heterogeneous1DReactor(os.path.join('files', 'H2-O2-Rh.xml'), 'gas', 'Rh_surface')  
    # Set reactor length in [m]
    h.set_length([0, 0.05, 0.1, 0.15, 0.2, 0.6, 0.65], 'm')  
    # Set reactor pressure in [bar]
    h.set_pressure(5, 'bar')  
    # Set catalytic load in [1/m]
    h.set_catalytic_load(10, '1/m')  
    # Set volumetric flow rate in [m3/h]
    h.set_volumetric_flow_rate(1., 'm3/h')  
    # Set inlet gas temperature in [°C]
    h.set_inlet_temperature(250, 'degC')  
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
    h.set_initial_solid_temperature(250, 'degC')  
    # Enable energy balance
    h.set_energy(True)  
    # Set reactor initial composition using mass fraction
    h.set_initial_mass_fraction({'O2': 0.4, 'AR': 0.5, 'H2': 0.1})  
    # Set reactor initial temperature in [°C]
    h.set_initial_temperature(250, 'degC')  
    # Set packed bed reactor properties
    h.set_packed_bed_reactor(0.3, 'mm', 1, 'cm', 0.75)  
    # Solve for different time steps in [s]
    h.solve([0, 0.1, 0.2, 0.3, 0.5, 0.75, 1.0, 2.0, 4.0, 10., 20.], 's')  
```
#### **Steady State**
This [example](https://github.com/srebughini/ASALIPY/blob/main/examples/het1d_steady_state.py) show how to solve a **steady state 1-D
heterogeneous plug flow reactor** for the [catalytic combustion of hydrogen over rhodium](https://www.detchem.com/mechanisms).

```python
import os
from asali.reactors.het1d import Heterogeneous1DReactor

if __name__ == "__main__":
    # Initialize reactor class
    h = Heterogeneous1DReactor(os.path.join('files', 'H2-O2-Rh.xml'), 'gas', 'Rh_surface')  
    # Set reactor length in [m]
    h.set_length([0, 0.05, 0.1, 0.15, 0.2, 0.6, 0.65], 'm')  
     # Set reactor pressure in [bar]
    h.set_pressure(5, 'bar') 
    # Set catalytic load in [1/m]
    h.set_catalytic_load(10, '1/m')  
    # Set volumetric flow rate in [m3/h]
    h.set_volumetric_flow_rate(1., 'm3/h')  
     # Set inlet gas temperature in [°C]
    h.set_inlet_temperature(250, 'degC') 
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
    h.set_initial_solid_temperature(250, 'degC')  
    # Enable energy balance
    h.set_energy(True)  
    # Set packed bed reactor properties
    h.set_packed_bed_reactor(0.3, 'mm', 1, 'cm', 0.75)
    # Solve
    h.solve()
```


### **Reactor Plotter**

This [example](https://github.com/srebughini/ASALIPY/blob/main/examples/het1d_transient.py) show how to **solve and plot** 1-D heterogeneous plug flow reactor for the [catalytic combustion of hydrogen over rhodium](https://www.detchem.com/mechanisms).

```python
from asali.reactors.het1d import Heterogeneous1DReactor
from asali.plotters.reactor import ReactorPlotter

if __name__ == "__main__":
    h = Heterogeneous1DReactor(os.path.join('files', 'H2-O2-Rh.xml'), 'gas', 'Rh_surface')  
    h.set_length([0, 0.05, 0.1, 0.15, 0.2, 0.6, 0.65], 'm')  
    h.set_pressure(5, 'bar')  
    h.set_catalytic_load(10, '1/m')  
    h.set_volumetric_flow_rate(1., 'm3/h')  
    h.set_inlet_temperature(250, 'degC')  
    h.set_inlet_mass_fraction({'O2': 0.4, 'AR': 0.5, 'H2': 0.1})  
    h.set_initial_coverage({'Rh(s)': 1})  
    h.set_solid_density(2300, 'kg/m3')  
    h.set_solid_specific_heat(750, 'J/kg/degK')  
    h.set_solid_thermal_conductivity(2.5, 'W/m/degK')  
    h.set_initial_solid_temperature(250, 'degC')  
    h.set_energy(True)  
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