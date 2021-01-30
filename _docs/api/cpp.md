---
permalink: /docs/api-cpp/
redirect_from: /docs/index.html
---

# **C++ version**
The C++ API can be included in your code as follow:  
```cpp
//Include library
#include "Asali.h"

//Main
int main()
{
    //Create composition using std vectors
    std::vector<std::string> names(3);
    std::vector<double> x(3);

    names[0] = "H2";
    names[1] = "O2";
    names[2] = "N2";

    x[0] = 0.1;
    x[1] = 0.2;
    x[2] = 1. - x[0] - x[1];

    //Initialize Asali
    ASALI::Asali asali;

    //Set up composition/pressure and temperature
    asali.setSpecies(names);
    asali.setTemperature(393.15); //K
    asali.setPressure(4e05); //Pa
    asali.setMoleFraction(x);

    //Properties evaluation
    std::vector<std::vector<double>> diff = asali.binaryDiffusion();
    std::vector<double>              cp   = asali.speciesMassCp();
    return 0;
}
```
Example and database generator can be compiled by typing:
```
./compile.sh
```

To convert the Asali database into C code run:
```
./database-generator
```
## **Available thermodynamic and transport properties**
ASALI estimates different thermodynamic and transport (`asali` is the library object):

| | |
|:-|:-|
| **`asali.density()`** | |
| *Estimated property*|Mixture density|
| *Return type*       |`double`|
| *Unit dimensions*   |kg/m<sup>3</sup>|
| **`asali.mixtureMolecularWeight()`** | |
| *Estimated property*|Mixture molecular weight |
| *Return type*       |`double`|
| *Unit dimensions*   |g/mol|
| **`asali.mixtureThermalConductivity()`** | |
| *Estimated property*|Mixture thermal conductivity |
| *Return type*       |`double`|
| *Unit dimensions*   |W/m/K|
| **`asali.mixtureViscosity()`** | |
| *Estimated property*|Mixture viscosity |
| *Return type*       |`double`|
| *Unit dimensions*   |Pa*s|
| **`asali.mixtureMolarCp()`** | |
| *Estimated property*|Mixture specific heat |
| *Return type*       |`double`|
| *Unit dimensions*   |J/kmol/K|
| **`asali.mixtureMassCp()`** | |
| *Estimated property*|Mixture specific heat |
| *Return type*       |`double`|
| *Unit dimensions*   |J/kg/K|
| **`asali.mixtureMolarEnthalpy()`** | |
| *Estimated property*|Mixture enthalpy|
| *Return type*       |`double`|
| *Unit dimensions*   |J/kmol|
| **`asali.mixtureMassEnthalpy()`** | |
| *Estimated property*|Mixture enthalpy|
| *Return type*       |`double`|
| *Unit dimensions*   |J/kg|
| **`asali.mixtureMolarEntropy()`** | |
| *Estimated property*|Mixture entropy|
| *Return type*       |`double`|
| *Unit dimensions*   |J/kmol/K|
| **`asali.mixtureMassEntropy()`** | |
| *Estimated property*|Mixture entropy|
| *Return type*       |`double`|
| *Unit dimensions*   |J/kg/K|
| **`asali.mixtureDiffusion()`** | |
| *Estimated property*|Mixture diffusivity|
| *Return type*       |`std::vector<double>`|
| *Unit dimensions*   |m<sup>2</sup>/s|
| **`asali.speciesThermalConductivity()`** | |
| *Estimated property*|Single specie thermal conductivity|
| *Return type*       |`std::vector<double>`|
| *Unit dimensions*   |W/m/K|
| **`asali.speciesViscosity()`** | |
| *Estimated property*|Single specie viscosity|
| *Return type*       |`std::vector<double>`|
| *Unit dimensions*   |Pa*s|
| **`asali.speciesMolarCp()`** | |
| *Estimated property*|Single specie specific heat|
| *Return type*       |`std::vector<double>`|
| *Unit dimensions*   |J/kmol/K|
| **`asali.speciesMassCp()`** | |
| *Estimated property*|Single specie specific heat|
| *Return type*       |`std::vector<double>`|
| *Unit dimensions*   |J/kg/K|
| **`asali.speciesMolarEnthalpy()`** | |
| *Estimated property*|Single specie enthalpy|
| *Return type*       |`std::vector<double>`|
| *Unit dimensions*   |J/kmol|
| **`asali.speciesMassEnthalpy()`** | |
| *Estimated property*|Single specie enthalpy|
| *Return type*       |`std::vector<double>`|
| *Unit dimensions*   |J/kg|
| **`asali.speciesMolarEntropy()`** | |
| *Estimated property*|Single specie entropy|
| *Return type*       |`std::vector<double>`|
| *Unit dimensions*   |J/kmol/K|
| **`asali.speciesMassEntropy()`** | |
| *Estimated property*|Single specie entropy|
| *Return type*       |`std::vector<double>`|
| *Unit dimensions*   |J/kg/K|
| **`asali.arithmeticMeanGasVelocity()`** | |
| *Estimated property*|Single gas velocity|
| *Return type*       |`std::vector<double>`|
| *Unit dimensions*   |m/s|
| **`asali.meanFreePath()`** | |
| *Estimated property*|Single mean free path|
| *Return type*       |`std::vector<double>`|
| *Unit dimensions*   |m|
| **`asali.binaryDiffusion()`** | |
| *Estimated property*|Single binary diffusion|
| *Return type*       |`std::vector<std::vector<double> >`|
| *Unit dimensions*   |m<sup>2</sup>/s|