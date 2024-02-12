---
permalink: /docs/api-c++/
---
<h1 class="text-left"><b>C++ version</b></h1>
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
                <td><i>double</i></td>
                <td>kg/m<sup>3</sup></td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixtureMolecularWeight()</i></b></th>
                <td>Mixture molecular weight</td>
                <td><i>double</i></td>
                <td>g/mol</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixtureThermalConductivity()</i></b></th>
                <td>Mixture thermal conductivity</td>
                <td><i>double</i></td>
                <td>W/m/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixtureViscosity()</i></b></th>
                <td>Mixture viscosity</td>
                <td><i>double</i></td>
                <td>Pa*s</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixtureMolarCp()</i></b></th>
                <td>Mixture specific heat</td>
                <td><i>double</i></td>
                <td>J/kmol/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixtureMassCp()</i></b></th>
                <td>Mixture specific heat</td>
                <td><i>double</i></td>
                <td>J/kg/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixtureMolarEnthalpy()</i></b></th>
                <td>Mixture enthalpy</td>
                <td><i>double</i></td>
                <td>J/kmol</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixtureMassEnthalpy()</i></b></th>
                <td>Mixture enthalpy</td>
                <td><i>double</i></td>
                <td>J/kg</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixtureMolarEntropy()</i></b></th>
                <td>Mixture entropy</td>
                <td><i>double</i></td>
                <td>J/kmol/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixtureMassEntropy()</i></b></th>
                <td>Mixture entropy</td>
                <td><i>double</i></td>
                <td>J/kg/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.mixtureDiffusion()</i></b></th>
                <td>Mixture diffusivity</td>
                <td><i>std::vector&lt;double&gt;</i></td>
                <td>m<sup>2</sup>/s</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.speciesThermalConductivity()</i></b></th>
                <td>Single specie thermal conductivity</td>
                <td><i>std::vector&lt;double&gt;</i></td>
                <td>W/m/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.speciesViscosity()</i></b></th>
                <td>Single specie viscosity</td>
                <td><i>std::vector&lt;double&gt;</i></td>
                <td>Pa*s</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.speciesMolarCp()</i></b></th>
                <td>Single specie specific heat</td>
                <td><i>std::vector&lt;double&gt;</i></td>
                <td>J/kmol/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.speciesMassCp()</i></b></th>
                <td>Single specie specific heat</td>
                <td><i>std::vector&lt;double&gt;</i></td>
                <td>J/kg/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.speciesMolarEnthalpy()</i></b></th>
                <td>Single specie enthalpy</td>
                <td><i>std::vector&lt;double&gt;</i></td>
                <td>J/kmol</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.speciesMassEnthalpy()</i></b></th>
                <td>Single specie enthalpy</td>
                <td><i>std::vector&lt;double&gt;</i></td>
                <td>J/kg</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.speciesMolarEntropy()</i></b></th>
                <td>Single specie entropy</td>
                <td><i>std::vector&lt;double&gt;</i></td>
                <td>J/kmol/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.speciesMassEntropy()</i></b></th>
                <td>Single specie entropy</td>
                <td><i>std::vector&lt;double&gt;</i></td>
                <td>J/kg/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.arithmeticMeanGasVelocity()</i></b></th>
                <td>Single gas velocity</td>
                <td><i>std::vector&lt;double&gt;</i></td>
                <td>m/s</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.meanFreePath()</i></b></th>
                <td>Single mean free path</td>
                <td><i>std::vector&lt;double&gt;</i></td>
                <td>m</td>
            </tr>
            <tr>
                <th scope="row"><b><i>asali.binaryDiffusion()</i></b></th>
                <td>Single binary diffusion</td>
                <td><i>std::vector&lt;std::vector&lt;double&gt;&gt;</i></td>
                <td>m<sup>2</sup>/s</td>
            </tr>
        </tbody>
    </table>
</div>