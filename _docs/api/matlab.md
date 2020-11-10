---
permalink: /docs/api-matlab/
redirect_from: /docs/index.html
---

# **Matlab and Octave version**
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

| | |
|:-|:-|
| **`p.Density`** | |
| *Estimated property*|Mixture density|
| *Return type*       |`float`|
| *Unit dimensions*   |kg/m<sup>3</sup>|
| | |
| **`p.MixtureMolecularWeight`** | |
| *Estimated property*|Mixture molecular weight |
| *Return type*       |`float`|
| *Unit dimensions*   |g/mol|
| | |
| **`p.MixtureThermalConductivity`** | |
| *Estimated property*|Mixture thermal conductivity |
| *Return type*       |`float`|
| *Unit dimensions*   |W/m/K|
| | |
| **`p.MixtureViscosity`** | |
| *Estimated property*|Mixture viscosity |
| *Return type*       |`float`|
| *Unit dimensions*   |Pa*s|
| | |
| **`p.MixtureMolarSpecificHeat`** | |
| *Estimated property*|Mixture specific heat |
| *Return type*       |`float`|
| *Unit dimensions*   |J/kmol/K|
 | | |
| **`p.MixtureMassSpecificHeat`** | |
| *Estimated property*|Mixture specific heat |
| *Return type*       |`float`|
| *Unit dimensions*   |J/kg/K|
| | |
| **`p.MixtureMolarEnthalpy`** | |
| *Estimated property*|Mixture enthalpy|
| *Return type*       |`float`|
| *Unit dimensions*   |J/kmol|
| | |
| **`p.MixtureMassEnthalpy`** | |
| *Estimated property*|Mixture enthalpy|
| *Return type*       |`float`|
| *Unit dimensions*   |J/kg|
| | |
| **`p.MixtureMolarEntropy`** | |
| *Estimated property*|Mixture entropy|
| *Return type*       |`float`|
| *Unit dimensions*   |J/kmol/K|
| | |
| **`p.MixtureMassEntropy`** | |
| *Estimated property*|Mixture entropy|
| *Return type*       |`float`|
| *Unit dimensions*   |J/kg/K|
| | |
| **`p.MixtureDiffusion`** | |
| *Estimated property*|Mixture diffusivity|
| *Return type*       |`float`|
| *Unit dimensions*   |m<sup>2</sup>/s|
| | |
| **`p.SpecieThermalConductivity`** | |
| *Estimated property*|Single specie thermal conductivity|
| *Return type*       |`1D array`|
| *Unit dimensions*   |W/m/K|
| | |
| **`p.SpecieViscosity`** | |
| *Estimated property*|Single specie viscosity|
| *Return type*       |`1D array`|
| *Unit dimensions*   |Pa*s|
| | |
| **`p.SpeciesMolarSpecificHeat`** | |
| *Estimated property*|Single specie specific heat|
| *Return type*       |`1D array`|
| *Unit dimensions*   |J/kmol/K|
| | |
| **`p.SpeciesMassSpecificHeat`** | |
| *Estimated property*|Single specie specific heat|
| *Return type*       |`1D array`|
| *Unit dimensions*   |J/kg/K|
| | |
| **`p.SpecieMolarEnthalpy`** | |
| *Estimated property*|Single specie enthalpy|
| *Return type*       |`1D array`|
| *Unit dimensions*   |J/kmol|
| | |
| **`p.SpecieMassEnthalpy`** | |
| *Estimated property*|Single specie enthalpy|
| *Return type*       |`1D array`|
| *Unit dimensions*   |J/kg|
| | |
| **`p.SpecieMolarEntropy`** | |
| *Estimated property*|Single specie entropy|
| *Return type*       |`1D array`|
| *Unit dimensions*   |J/kmol/K|
| | |
| **`p.SpecieMassEntropy`** | |
| *Estimated property*|Single specie entropy|
| *Return type*       |`1D array`|
| *Unit dimensions*   |J/kg/K|
| | |
| **`p.MeanGasVelocity`** | |
| *Estimated property*|Single gas velocity|
| *Return type*       |`1D array`|
| *Unit dimensions*   |m/s|
| | |
| **`p.MeanFreePath`** | |
| *Estimated property*|Single mean free path|
| *Return type*       |`1D array`|
| *Unit dimensions*   |m|
| | |
| **`p.BinaryDiffusion`** | |
| *Estimated property*|Single binary diffusion|
| *Return type*       |`2D array`|
| *Unit dimensions*   |m<sup>2</sup>/s|
