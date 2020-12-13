---
permalink: /docs/api-javascript/
redirect_from: /docs/index.html
---

# **JavaScript version**
The JavaScript API version of ASALI is called [**J**a**S**ali](https://github.com/srebughini/JASALI) and its [**npm package**](https://www.npmjs.com/package/jasali) can be installed as follow:

```
npm i jasali
```

**J**a**S**ali allows the estimation of thermodynamic and trasport properties of **pure gas species** and **gas mixtures**, as shown in the following examples.

### Pure gas specie: O<sub>2</sub>

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

## Available thermodynamic and transport properties
**J**a**S**ali estimates different thermodynamic and transport properties:

| | |
|:-|:-|
| **`getName()`** | |
| *Estimated property*|Specie name|
| *Method of*         |`GasSpecie`|
| *Unit dimensions*   |n.a|
| | |
| **`getMolecularWeight()`** | |
| *Estimated property*|Molecular weight|
| *Method of*         |`GasSpecie`|
| *Unit dimensions*   |g/mol|
| | |
| **`getDensity()`** | |
| *Estimated property*|Density|
| *Method of*         |`GasSpecie`|
| *Unit dimensions*   |kg/m<sup>3</sup>|
| | |
| **`getMolarSpecificHeat()`** | |
| *Estimated property*|Specific heat|
| *Method of*         |`GasSpecie`|
| *Unit dimensions*   |J/kmol/K|
| | |
| **`getMassSpecificHeat()`** | |
| *Estimated property*|Specific heat|
| *Method of*         |`GasSpecie`|
| *Unit dimensions*   |J/kg/K|
| | |
| **`getMolarEnthalpy()`** | |
| *Estimated property*|Enthalpy|
| *Method of*         |`GasSpecie`|
| *Unit dimensions*   |J/kmol|
| | |
| **`getMassEnthalpy()`** | |
| *Estimated property*|Enthalpy|
| *Method of*         |`GasSpecie`|
| *Unit dimensions*   |J/kg|
| | |
| **`getMolarEntropy()`** | |
| *Estimated property*|Entropy|
| *Method of*         |`GasSpecie`|
| *Unit dimensions*   |J/kmol/K|
| | |
| **`getMassEntropy()`** | |
| *Estimated property*|Entropy|
| *Method of*         |`GasSpecie`|
| *Unit dimensions*   |J/kg/K|
| | |
| **`getViscosity()`** | |
| *Estimated property*|Viscosity|
| *Method of*         |`GasSpecie`|
| *Unit dimensions*   |Pa*s|
| | |
| **`getArithmeticMeanGasVelocity()`** | |
| *Estimated property*|Mean gas velocity|
| *Method of*         |`GasSpecie`|
| *Unit dimensions*   |m/s|
| | |
| **`getMeanFreePath()`** | |
| *Estimated property*|Mean free path|
| *Method of*         |`GasSpecie`|
| *Unit dimensions*   |m|
| | |
| **`getDiffusion()`** | |
| *Estimated property*|Binary diffusivity|
| *Method of*         |`GasSpecie`|
| *Unit dimensions*   |m<sup>2</sup>/s|
| | |
| **`getThermalConductivity()`** | |
| *Estimated property*|Thermal conductivity|
| *Method of*         |`GasSpecie`|
| *Unit dimensions*   |W/m/K|