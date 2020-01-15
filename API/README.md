# **ASALI: Modeling and beyond**
The Asali version with **Application Programming Interface** is an open-source code developed for engineers, chemists and students working on the modeling of gas phase mixture. This version of Asali is very helpful for those who need a reliable, simple and perfoming library for the estimation of thermodynamic and transport properties of ideal gas mixture. 
## **1. Thermodynamic and transport properties**
Let's go straight to the point! Asali library can estimate:
* Thermal conductivity
* Viscosity
* Density
* Binary and mixture diffusivity
* Enthalpy
* Entropy
* Specific heat at constant pressure
Asali estimates the transport properties with the standard gas kinetic theory *(Curtiss, Charles F., and Joseph O. Hirschfelder. "Transport properties of multicomponent gas mixtures." The Journal of Chemical Physics 17.6 (1949): 550-555.)*. The thermodynamic properties of each species are based on the NASA parameters and calculated according to the approach proposed by Gordon and McBride *(Gordon, S., and B. J. McBride. "Technical Report SP-273." NASA Special Publication (1971))*. Moreover, thermodynamic properties of the gaseous mixture are estimated by applying the Gibbs theorem.
## **2. Matlab and Octave version**
The [Matlab](https://it.mathworks.com/campaigns/products/trials.html?s_eid=ppc_29775072802&q=matlab) and [Octave](https://www.gnu.org/software/octave/) API can be used as follow:
```Matlab
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
## **3. Fortran version**