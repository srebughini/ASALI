---
permalink: /docs/api-matlab/
redirect_from: /docs/index.html
---

## **Matlab and Octave version**
The [Matlab](https://it.mathworks.com/campaigns/products/trials.html?s_eid=ppc_29775072802&q=matlab) and [Octave](https://www.gnu.org/software/octave/) API can be inlcuded in your code as follow:
```matlab
%Class generation
p = Asali('database.mat');

%Set up composition/pressure and temperature
p.Pressure     = 4e05;
p.Temperature  = 393.15;
p.Names        = {'H2' 'O2' 'N2'};
p.MoleFraction = [0.1 0.2 0.7];

%Properties evaluation
cp = p.SpeciesMassSpecificHeat;
```
To create the file *database.mat* run the file `database-generator.m`
## Available thermodynamic and transport properties
ASALI estimates different thermodynamic and transport properties (`p` is the Asali object):
<p>&nbsp;</p>
* `p.Density`
    * Mixture density in kg/m3
    * The return value is a `float`.
<p>&nbsp;</p>
* `p.MixtureMolecularWeight`
    * Mixture molecular weight in g/mol
    * The return value is a `float`.  
<p>&nbsp;</p>
* `p.MixtureThermalConductivity`
    * Mixture thermal conductivity in W/m/K
    * The return value is a `float`.  
<p>&nbsp;</p>
* `p.MixtureViscosity`
    * Mixture viscosity in Pa*s.
    * The return value is a `float`.  
<p>&nbsp;</p>
* `p.MixtureMolarSpecificHeat`
    * Mixture specific heat in J/kmol/K.
    * The return value is a `float`.  
<p>&nbsp;</p>
* `p.MixtureMassSpecificHeat`
    * Mixture specific heat in J/kg/K.
    * The return value is a `float`.  
<p>&nbsp;</p>
* `p.MixtureMolarEnthalpy`
    * Mixture enthalpy in J/kmol.
    * The return value is a `float`.  
<p>&nbsp;</p>
* `p.MixtureMassEnthalpy`
    * Mixture enthalpy in J/kg.
    * The return value is a `float`.  
<p>&nbsp;</p>
* `p.MixtureMolarEntropy`
    * Mixture entropy in J/kmol/K.
    * The return value is a `float`.  
<p>&nbsp;</p>
* `p.MixtureMassEntropy`
    * Mixture entropy in J/kg/K.
    * The return value is a `float`.  
<p>&nbsp;</p>
* `p.MixtureDiffusion`
    * Mixture diffusivity in m2/s. 
    * The return value is a `1D array`.  
<p>&nbsp;</p>
* `p.SpecieThermalConductivity()`
    * Single species viscosity in W/m/K
    * The return value is a `1D array`.  
<p>&nbsp;</p>
* `p.SpecieViscosity`
    * Single species viscosity in Pa*s.
    * The return value is a `1D array`. 
<p>&nbsp;</p>
* `p.SpeciesMolarSpecificHeat`
    * Single species specific heat in J/kmol/K.
    * The return value is a `1D array`. 
<p>&nbsp;</p>
* `p.SpeciesMassSpecificHeat`
    * Single species specific heat in J/kg/K.
    * The return value is a `1D array`. 
<p>&nbsp;</p>
* `p.SpecieMolarEnthalpy`
    * Single species enthalpy in J/kmol.
    * The return value is a `1D array`.   
<p>&nbsp;</p>
* `p.SpecieMassEnthalpy`
    * Single species enthalpy in J/kg. 
    * The return value is a `1D array`. 
<p>&nbsp;</p>
* `p.SpecieMolarEntropy`
    * Single species entropy in J/kmol/K.
    * The return value is a `1D array`. 
<p>&nbsp;</p>
* `p.SpecieMassEntropy`
    * Single species entropy in J/kg/K.
    * The return value is a `1D array`.  
<p>&nbsp;</p>
* `p.MeanGasVelocity`
    * Single gas velocity in m/s. 
    * The return value is a `1D array`. 
<p>&nbsp;</p>
* `p.MeanFreePath`
    * Single species mean free path in m.
    * The return value is a `1D array`. 
<p>&nbsp;</p>
* `p.BinaryDiffusion`
    * Single species binary diffusion in m2/s.
    * The return value is a `2D array`. 
