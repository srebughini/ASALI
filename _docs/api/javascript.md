---
permalink: /docs/api-javascript/
redirect_from: /docs/index.html
---

# **JavaScript version**
The JavaScript API version of ASALI is called [**J**a**S**ali](https://github.com/srebughini/JASALI) and its [npm package](https://www.npmjs.com/package/jasali) can be installed as follow:

```
npm i jasali
```

**J**a**S**ali allows the estimation of thermodynamic and trasport properties of **pure gas species** and **gas mixtures**, as shown in the following examples.

### Pure gas specie: O<sub>2</sub>
This example shows how to extract pure **oxygen** properties.

```javascript
import { GasSpecie, GasState } from "jasali"

//Generate gas state object
let state = GasState({ temperature: 393.15, pressure: 4e05 })

//Generate specie object
let specie = GasSpecie({ name: "O2", gasState: state })

//Extract properties from the specie object
let name = specie.getName()
let molecularWeight = specie.getMolecularWeight()
let viscosity = specie.getViscosity()
```
### Gas mixture: AIR
This example shows how to extract **air** properties from its composition.

```javascript
import { GasSpecie, GasState, GasMixtureComposition, GasMixture } from "jasali"

//Generate gas state object
let state = GasState({ temperature: 298.15, pressure: 101325 })

//Generate pure gas specie objects
let o2 = GasSpecie({ name: "O2", gasState: state })
let n2 = GasSpecie({ name: "N2", gasState: state })
let ar = GasSpecie({ name: "AR", gasState: state })

//Generate mixture list
let speciesList = [{ "specie": o2, "value": 0.21 }, { "specie": n2, "value": 0.78 }, { "specie": ar, "value": 0.01 }]

//Generate mixture composition object
let compositions = GasMixtureComposition(speciesList, "mole")

//Generate mixture object
let mixture = GasMixture({ gasState: state, mixtureComposition: compositions })

//Extract properties from the mixture object
let density = mixture.getDensity()
let molecularWeight = mixture.getMolecularWeight()
let viscosity = mixture.getViscosity()
```

## **Available thermodynamic and transport properties**
**J**a**S**ali objects estimate different thermodynamic and transport properties. Different objects share the same method to extract the same property. The following list reports all the available methods and the related objects:

| | |

### `GasSpecie` methods

| | |
|:-|:-|
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
| **`getSpecies()`** | |
| *Estimated property*|Species in the mixture|
| *Method of*         |`GasMixture`|
| *Unit dimensions*   |n.a|
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