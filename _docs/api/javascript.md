---
permalink: /docs/api-javascript/
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

<table class="table table-striped">
  <thead>
      <tr>
          <th scope="row">Function</th>
          <th>Estimated property</th>
          <th>Method of</th>
          <th>Unit dimension</th>
      </tr>
  </thead>
  <tbody>
    <tr>
      <th scope="row"><b><i>getTemperature()</i></b></th>
      <td>Temperature</td>
      <td><i>GasState</i></td>
      <td>K</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getPressure()</i></b></th>
      <td>Pressure</td>
      <td><i>GasState</i></td>
      <td>Pa</td>
    </tr>
    <tr>
      <th scope="row"><b><i>updateGasState()</i></b></th>
      <td>Update gas state</td>
      <td><i>GasSpecie</i></td>
      <td>n.a</td>
    </tr>
    <tr>
      <th scope="row"><b><i>updateMoleFraction()</i></b></th>
      <td>Update mole fraction</td>
      <td><i>GasSpecie</i></td>
      <td>n.a</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getName()</i></b></th>
      <td>Specie name</td>
      <td><i>GasSpecie</i></td>
      <td>n.a</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getArithmeticMeanGasVelocity()</i></b></th>
      <td>Mean gas velocity</td>
      <td><i>GasSpecie</i></td>
      <td>m/s</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getMeanFreePath()</i></b></th>
      <td>Mean free path</td>
      <td><i>GasSpecie</i></td>
      <td>m</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getDiffusion()</i></b></th>
      <td>Binary diffusivity</td>
      <td><i>GasSpecie</i></td>
      <td>m<sup>2</sup>/s</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getTemperature()</i></b></th>
      <td>Temperature</td>
      <td><i>GasMixture</i></td>
      <td>K</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getPressure()</i></b></th>
      <td>Pressure</td>
      <td><i>GasMixture</i></td>
      <td>Pa</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getMassFraction()</i></b></th>
      <td>Mass fraction</td>
      <td><i>GasMixture</i></td>
      <td>n.a</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getMoleFraction()</i></b></th>
      <td>Mole fraction</td>
      <td><i>GasMixture</i></td>
      <td>n.a</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getBinaryDiffusion()</i></b></th>
      <td>Binary diffusivity</td>
      <td><i>GasMixture</i></td>
      <td>m<sup>2</sup>/s</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getMixtureDiffusion()</i></b></th>
      <td>Mixture diffusivity</td>
      <td><i>GasMixture</i></td>
      <td>m<sup>2</sup>/s</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getSpeciesName()</i></b></th>
      <td>Specie name</td>
      <td><i>GasMixture</i></td>
      <td>n.a</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getSpeciesArithmeticMeanGasVelocity()</i></b></th>
      <td>Mean gas velocity</td>
      <td><i>GasMixture</i></td>
      <td>m/s</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getSpeciesMeanFreePath()</i></b></th>
      <td>Mean free path</td>
      <td><i>GasMixture</i></td>
      <td>m</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getSpecies()</i></b></th>
      <td>Species in the mixture</td>
      <td><i>GasMixture</i></td>
      <td>n.a</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getSpecieMolarSpecificHeat()</i></b></th>
      <td>Specific heat</td>
      <td><i>GasMixture</i></td>
      <td>J/kmol/K</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getSpecieMassSpecificHeat()</i></b></th>
      <td>Specific heat</td>
      <td><i>GasMixture</i></td>
      <td>J/kg/K</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getSpecieMolarEnthalpy()</i></b></th>
      <td>Enthalpy</td>
      <td><i>GasMixture</i></td>
      <td>J/kmol</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getSpecieMassEnthalpy()</i></b></th>
      <td>Enthalpy</td>
      <td><i>GasMixture</i></td>
      <td>J/kg</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getSpecieMolarEntropy()</i></b></th>
      <td>Entropy</td>
      <td><i>GasMixture</i></td>
      <td>J/kmol/K</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getSpecieMassEntropy()</i></b></th>
      <td>Entropy</td>
      <td><i>GasMixture</i></td>
      <td>J/kg/K</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getSpecieMolarInternalEnergy()</i></b></th>
      <td>Internal energy</td>
      <td><i>GasMixture</i></td>
      <td>J/kmol</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getSpecieMassInternalEnergy()</i></b></th>
      <td>Internal energy</td>
      <td><i>GasMixture</i></td>
      <td>J/kg</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getSpecieMolarGibbsFreeEnergy()</i></b></th>
      <td>Gibbs free energy</td>
      <td><i>GasMixture</i></td>
      <td>J/kmol</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getSpecieMassGibbsFreeEnergy()</i></b></th>
      <td>Gibbs free energy</td>
      <td><i>GasMixture</i></td>
      <td>J/kg</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getSpecieViscosity()</i></b></th>
      <td>Viscosity</td>
      <td><i>GasMixture</i></td>
      <td>Pa*s</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getSpecieThermalConductivity()</i></b></th>
      <td>Thermal conductivity</td>
      <td><i>GasMixture</i></td>
      <td>W/m/K</td>
    </tr>
    <tr>
      <th scope="row"><b><i>calculateChemicalEquilibriumTP()</i></b></th>
      <td>Chemical equilibrium</td>
      <td><i>GasMixture</i></td>
      <td>mole fraction</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getMolecularWeight()</i></b></th>
      <td>Molecular weight</td>
      <td><i>GasSpecie/GasMixture</i></td>
      <td>g/mol</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getDensity()</i></b></th>
      <td>Density</td>
      <td><i>GasSpecie/GasMixture</i></td>
      <td>kg/m<sup>3</sup></td>
    </tr>
    <tr>
      <th scope="row"><b><i>getMolarSpecificHeat()</i></b></th>
      <td>Specific heat</td>
      <td><i>GasSpecie/GasMixture</i></td>
      <td>J/kmol/K</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getMassSpecificHeat()</i></b></th>
      <td>Specific heat</td>
      <td><i>GasSpecie/GasMixture</i></td>
      <td>J/kg/K</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getMolarEnthalpy()</i></b></th>
      <td>Enthalpy</td>
      <td><i>GasSpecie/GasMixture</i></td>
      <td>J/kmol</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getMassEnthalpy()</i></b></th>
      <td>Enthalpy</td>
      <td><i>GasSpecie/GasMixture</i></td>
      <td>J/kg</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getMolarEntropy()</i></b></th>
      <td>Entropy</td>
      <td><i>GasSpecie/GasMixture</i></td>
      <td>J/kmol/K</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getMassEntropy()</i></b></th>
      <td>Entropy</td>
      <td><i>GasSpecie/GasMixture</i></td>
      <td>J/kg/K</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getMolarInternalEnergy()</i></b></th>
      <td>Internal energy</td>
      <td><i>GasSpecie/GasMixture</i></td>
      <td>J/kmol</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getMassInternalEnergy()</i></b></th>
      <td>Internal energy</td>
      <td><i>GasSpecie/GasMixture</i></td>
      <td>J/kg</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getMolarGibbsFreeEnergy()</i></b></th>
      <td>Gibbs free energy</td>
      <td><i>GasSpecie/GasMixture</i></td>
      <td>J/kmol</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getMassGibbsFreeEnergy()</i></b></th>
      <td>Gibbs free energy</td>
      <td><i>GasSpecie/GasMixture</i></td>
      <td>J/kg</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getViscosity()</i></b></th>
      <td>Viscosity</td>
      <td><i>GasSpecie/GasMixture</i></td>
      <td>Pa*s</td>
    </tr>
    <tr>
      <th scope="row"><b><i>getThermalConductivity()</i></b></th>
      <td>Thermal conductivity</td>
      <td><i>GasSpecie/GasMixture</i></td>
      <td>W/m/K</td>
    </tr>
  </tbody>
</table>

