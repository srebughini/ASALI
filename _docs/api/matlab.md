---
permalink: /docs/api-matlab/
---
<h1 class="text-left"><b>Matlab and Octave version</b></h1>
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
                <th scope="row"><b><i>p.Density</i></b></th>
                <td>Mixture density</td>
                <td><i>float</i></td>
                <td>kg/m<sup>3</sup></td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.MixtureMolecularWeight</i></b></th>
                <td>Mixture molecular weight </td>
                <td><i>float</i></td>
                <td>g/mol</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.MixtureThermalConductivity</i></b></th>
                <td>Mixture thermal conductivity </td>
                <td><i>float</i></td>
                <td>W/m/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.MixtureViscosity</i></b></th>
                <td>Mixture viscosity </td>
                <td><i>float</i></td>
                <td>Pa*s</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.MixtureMolarSpecificHeat</i></b></th>
                <td>Mixture specific heat </td>
                <td><i>float</i></td>
                <td>J/kmol/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.MixtureMassSpecificHeat</i></b></th>
                <td>Mixture specific heat </td>
                <td><i>float</i></td>
                <td>J/kg/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.MixtureMolarEnthalpy</i></b></th>
                <td>Mixture enthalpy</td>
                <td><i>float</i></td>
                <td>J/kmol</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.MixtureMassEnthalpy</i></b></th>
                <td>Mixture enthalpy</td>
                <td><i>float</i></td>
                <td>J/kg</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.MixtureMolarEntropy</i></b></th>
                <td>Mixture entropy</td>
                <td><i>float</i></td>
                <td>J/kmol/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.MixtureMassEntropy</i></b></th>
                <td>Mixture entropy</td>
                <td><i>float</i></td>
                <td>J/kg/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.MixtureDiffusion</i></b></th>
                <td>Mixture diffusivity</td>
                <td><i>float</i></td>
                <td>m<sup>2</sup>/s</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.SpecieThermalConductivity</i></b></th>
                <td>Single specie thermal conductivity</td>
                <td><i>1D array</i></td>
                <td>W/m/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.SpecieViscosity</i></b></th>
                <td>Single specie viscosity</td>
                <td><i>1D array</i></td>
                <td>Pa*s</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.SpeciesMolarSpecificHeat</i></b></th>
                <td>Single specie specific heat</td>
                <td><i>1D array</i></td>
                <td>J/kmol/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.SpeciesMassSpecificHeat</i></b></th>
                <td>Single specie specific heat</td>
                <td><i>1D array</i></td>
                <td>J/kg/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.SpecieMolarEnthalpy</i></b></th>
                <td>Single specie enthalpy</td>
                <td><i>1D array</i></td>
                <td>J/kmol</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.SpecieMassEnthalpy</i></b></th>
                <td>Single specie enthalpy</td>
                <td><i>1D array</i></td>
                <td>J/kmol</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.SpecieMolarEntropy</i></b></th>
                <td>Single specie entropy</td>
                <td><i>1D array</i></td>
                <td>J/kmol/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.SpecieMassEntropy</i></b></th>
                <td>Single specie entropy</td>
                <td><i>1D array</i></td>
                <td>J/kg/K</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.MeanGasVelocity</i></b></th>
                <td>Single gas velocity</td>
                <td><i>1D array</i></td>
                <td>m/s</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.MeanFreePath</i></b></th>
                <td>Single mean free path</td>
                <td><i>1D array</i></td>
                <td>m</td>
            </tr>
            <tr>
                <th scope="row"><b><i>p.BinaryDiffusion</i></b></th>
                <td>Single binary diffusion</td>
                <td><i>2D array</i></td>
                <td>m<sup>2</sup>/s</td>
            </tr>
        </tbody>
    </table>
</div>
