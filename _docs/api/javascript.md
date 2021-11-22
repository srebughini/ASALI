---
permalink: /docs/api-javascript/
redirect_from: /docs/index.html
---

# **JavaScript version**
The JavaScript API version of ASALI is called [**J**a**S**ali](https://github.com/srebughini/JASALI) and its [npm package](https://www.npmjs.com/package/jasali) can be installed as follow:

```bash
npm i jasali
```

**J**a**S**ali allows the estimation of thermodynamic and trasport properties of **pure gas species** and **gas mixtures**, as shown in the following examples.

### Pure gas specie: O<sub>2</sub>
This example shows how to extract pure **oxygen** properties.

```javascript
import {
  GasState,
  GasSpecie
} from "jasali"

//Generate gas state object
let state = GasState({
  temperature: 393.15,
  pressure: 4e05
})

//Generate specie object
let specie = GasSpecie({
  name: "O2",
  gasState: state
})

//Extract properties from the specie object
let name = specie.getName()
let molecularWeight = specie.getMolecularWeight()
let viscosity = specie.getViscosity()
```

### Gas mixture: AIR
This example shows how to extract **air** properties from its composition.

```javascript
import {
  GasState,
  GasMixture
} from "jasali"

//Generate gas state object
let state = GasState({
  temperature: 298.15,
  pressure: 101325
})

//Generate mixture object
let mixture = GasMixture({
  mixtureComposition: {
    "O2": 0.21,
    "N2": 0.78,
    "AR": 0.01
  },
  gasState: state,
  compositionType: "mole"
})

//Extract properties from the mixture object
let density = mixture.getDensity()
let molecularWeight = mixture.getMolecularWeight()
let viscosity = mixture.getViscosity()
```
### Gas mixture: Chemical equilibrium
This example shows how to estimate the **chemical equilibrium at constant pressure and temperaure** for a gas mixture.

```javascript
import {
  GasState,
  GasMixture
} from "jasali"

//Generate gas state object
let state = GasState({
  temperature: 3000,
  pressure: 4e05
})

//Generate mixture object
let mixture = GasMixture({
  mixtureComposition: {
    "CO": 0.1,
    "CO2": 0.2,
    "O2": 0.7
  },
  gasState: state,
  compositionType: "mole"
})

//Extract chemical equilibrium composition
let x = mixture.calculateChemicalEquilibriumTP()
```

## **Available thermodynamic and transport properties**
**J**a**S**ali objects estimate different thermodynamic and transport properties. Different objects share the same method to extract the same property. The following list reports all the available methods and the related objects:

| | |

### `GasState` methods

| | |
|:-|:-|
| **`getTemperature()`** | |
| *Estimated property*|Temperature|
| *Method of*         |`GasState`|
| *Unit dimensions*   |K|
| **`getPressure()`** | |
| *Estimated property*|Pressure|
| *Method of*         |`GasState`|
| *Unit dimensions*   |Pa|
| | |

### `GasSpecie` methods

| | |
|:-|:-|
| **`updateGasState()`** | |
| *Estimated property*|Update gas state|
| *Method of*         |`GasSpecie`|
| *Unit dimensions*   |n.a|
| **`updateMoleFraction()`** | |
| *Estimated property*|Update mole fraction|
| *Method of*         |`GasSpecie`|
| *Unit dimensions*   |n.a|
| **`getName()`** | |
| *Estimated property*|Specie name|
| *Method of*         |`GasSpecie`|
| *Unit dimensions*   |n.a|
| **`getArithmeticMeanGasVelocity()`** | |
| *Estimated property*|Mean gas velocity|
| *Method of*         |`GasSpecie`|
| *Unit dimensions*   |m/s|
| **`getMeanFreePath()`** | |
| *Estimated property*|Mean free path|
| *Method of*         |`GasSpecie`|
| *Unit dimensions*   |m|
| **`getDiffusion()`** | |
| *Estimated property*|Binary diffusivity|
| *Method of*         |`GasSpecie`|
| *Unit dimensions*   |m<sup>2</sup>/s|
| | |

### `GasMixture` methods

| | |
|:-|:-|
| **`getTemperature()`** | |
| *Estimated property*|Temperature|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |K|
| **`getPressure()`** | |
| *Estimated property*|Pressure|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |Pa|
| **`getMassFraction()`** | |
| *Estimated property*|Mass fraction|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |n.a|
| **`getMoleFraction()`** | |
| *Estimated property*|Mole fraction|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |n.a|
| **`getBinaryDiffusion()`** | |
| *Estimated property*|Binary diffusivity|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |m<sup>2</sup>/s|
| **`getMixtureDiffusion()`** | |
| *Estimated property*|Mixture diffusivity|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |m<sup>2</sup>/s|
| **`getSpeciesName()`** | |
| *Estimated property*|Specie name|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |n.a|
| **`getSpeciesArithmeticMeanGasVelocity()`** | |
| *Estimated property*|Mean gas velocity|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |m/s|
| **`getSpeciesMeanFreePath()`** | |
| *Estimated property*|Mean free path|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |m|
| **`getSpecies()`** | |
| *Estimated property*|Species in the mixture|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |n.a|
| **`getSpecieMolarSpecificHeat()`** | |
| *Estimated property*|Specific heat|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |J/kmol/K|
| **`getSpecieMassSpecificHeat()`** | |
| *Estimated property*|Specific heat|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |J/kg/K|
| **`getSpecieMolarEnthalpy()`** | |
| *Estimated property*|Enthalpy|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |J/kmol|
| **`getSpecieMassEnthalpy()`** | |
| *Estimated property*|Enthalpy|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |J/kg|
| **`getSpecieMolarEntropy()`** | |
| *Estimated property*|Entropy|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |J/kmol/K|
| **`getSpecieMassEntropy()`** | |
| *Estimated property*|Entropy|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |J/kg/K|
| **`getSpecieMolarInternalEnergy()`** | |
| *Estimated property*|Internal energy|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |J/kmol|
| **`getSpecieMassInternalEnergy()`** | |
| *Estimated property*|Internal energy|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |J/kg|
| **`getSpecieMolarGibbsFreeEnergy()`** | |
| *Estimated property*|Gibbs free energy|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |J/kmol|
| **`getSpecieMassGibbsFreeEnergy()`** | |
| *Estimated property*|Gibbs free energy|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |J/kg|
| **`getSpecieViscosity()`** | |
| *Estimated property*|Viscosity|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |Pa*s|
| **`getSpecieThermalConductivity()`** | |
| *Estimated property*|Thermal conductivity|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |W/m/K|
| **`calculateChemicalEquilibriumTP()`** | |
| *Estimated property*|Chemical equilibrium|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |mole fraction|
| | |

### `GasMixture` and `GasSpecie` methods

| | |
|:-|:-|
| **`getMolecularWeight()`** | |
| *Estimated property*|Molecular weight|
| *Method of*         |`GasSpecie`,`GasMixture`|
| *Unit dimensions*   |g/mol|
| **`getDensity()`** | |
| *Estimated property*|Density|
| *Method of*         |`GasSpecie`,`GasMixture`|
| *Unit dimensions*   |kg/m<sup>3</sup>|
| **`getMolarSpecificHeat()`** | |
| *Estimated property*|Specific heat|
| *Method of*         |`GasSpecie`,`GasMixture`|
| *Unit dimensions*   |J/kmol/K|
| **`getMassSpecificHeat()`** | |
| *Estimated property*|Specific heat|
| *Method of*         |`GasSpecie`,`GasMixture`|
| *Unit dimensions*   |J/kg/K|
| **`getMolarEnthalpy()`** | |
| *Estimated property*|Enthalpy|
| *Method of*         |`GasSpecie`,`GasMixture`|
| *Unit dimensions*   |J/kmol|
| **`getMassEnthalpy()`** | |
| *Estimated property*|Enthalpy|
| *Method of*         |`GasSpecie`,`GasMixture`|
| *Unit dimensions*   |J/kg|
| **`getMolarEntropy()`** | |
| *Estimated property*|Entropy|
| *Method of*         |`GasSpecie`,`GasMixture`|
| *Unit dimensions*   |J/kmol/K|
| **`getMassEntropy()`** | |
| *Estimated property*|Entropy|
| *Method of*         |`GasSpecie`,`GasMixture`|
| *Unit dimensions*   |J/kg/K|
| **`getMolarInternalEnergy()`** | |
| *Estimated property*|Internal energy|
| *Method of*         |`GasSpecie`,`GasMixture`|
| *Unit dimensions*   |J/kmol|
| **`getMassInternalEnergy()`** | |
| *Estimated property*|Internal energy|
| *Method of*         |`GasSpecie`,`GasMixture`|
| *Unit dimensions*   |J/kg|
| **`getMolarGibbsFreeEnergy()`** | |
| *Estimated property*|Gibbs free energy|
| *Method of*         |`GasSpecie`,`GasMixture`|
| *Unit dimensions*   |J/kmol|
| **`getMassGibbsFreeEnergy()`** | |
| *Estimated property*|Gibbs free energy|
| *Method of*         |`GasSpecie`,`GasMixture`|
| *Unit dimensions*   |J/kg|
| **`getViscosity()`** | |
| *Estimated property*|Viscosity|
| *Method of*         |`GasSpecie`,`GasMixture`|
| *Unit dimensions*   |Pa*s|
| **`getThermalConductivity()`** | |
| *Estimated property*|Thermal conductivity|
| *Method of*         |`GasSpecie`,`GasMixture`|
| *Unit dimensions*   |W/m/K|
| | |