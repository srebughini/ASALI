---
permalink: /docs/gui-introduction/
---
<h1 class="text-left"><b>Introduction</b></h1>
Let's go straight to the point! Asali main features are:
* Estimation of thermodynamic/transport properties of ideal gas mixture
* Regression of thermodynamic/transport properties of ideal gas mixture
* Evaluation of thermodynamic equilibrium of ideal gas mixture
* Estimation of vacuum properties based of gas kinetic theory
* Estimation of pressure drops in chemical reactors
* Conversion of CHEMKIN input files into [Cantera](https://cantera.org/) file.
* Insert new species in CHEMKIN transport and thermodynamic properties files.

If you are interested in  more details regarding models implemented in Asali have a look at the following paragraph; if not, jump to section number 2 for the installation instructions.
<h2 class="text-left"><b>Thermodynamic/Transport properties</b></h2>
The thermodynamic and transport properties evaluated by Asali are:
* Thermal conductivity
* Viscosity
* Binary and mixture diffusivity
* Enthalpy
* Entropy
* Specific heat at constant pressure
* Density
* Molecular weight

Asali can be considered as a powerful user-friendly interface of  [Cantera](https://cantera.org/), thus all the transport and thermodynamic properties are estimated following the approach implemented in  [Cantera](https://cantera.org/). The transport properties are evaluated with the standard gas kinetic theory *(Curtiss, Charles F., and Joseph O. Hirschfelder. "Transport properties of multicomponent gas mixtures." The Journal of Chemical Physics 17.6 (1949): 550-555.)*. The thermodynamic properties of each species are based on the NASA parameters and calculated according to the approach proposed by Gordon and McBride *(Gordon, S., and B. J. McBride. "Technical Report SP-273." NASA Special Publication (1971))*. Moreover, thermodynamic properties of the gaseous mixture are estimated by applying the Gibbs theorem.
<h2 class="text-left"><b>Regression</b></h2>
This feature of Asali applies a least square fit to derive *easy-to-handle* functions of thermodynamic/transport properties. In particular, Asali estimates the thermodynamic/transport properties by using [Cantera](https://cantera.org/) and derives power law, linear or logarithmic functions describing these properties as a function of temperature.
<h2 class="text-left"><b>Thermodynamic equilibrium</b></h2>
[Cantera](https://cantera.org/) calculates also the thermodynamic equilibrium of ideal gas mixtures. Therefore, Asali exploits this feature to evaluate the equilibrium at constant temperature or at constant pressure. For more information have a look at [Cantera](https://cantera.org/) user's guide.
<h2 class="text-left"><b>Vacuum properties</b></h2>
The vacuum properties estimated by Asali are:
* Knudsen number
* Mean gas velocity
* Mean free path length
* Diffusivity

These properties are estimated according to the standard gas kinetic theory *(Curtiss, Charles F., and Joseph O. Hirschfelder. "Transport properties of multicomponent gas mixtures." The Journal of Chemical Physics 17.6 (1949): 550-555.)*. In particular, the diffusivity value is estimated considering both the viscous regime and the rarefied regime according to the Knudsen number.
<h2 class="text-left"><b>Pressure drops</b></h2>
This feature of Asali allows to estimate pressure drops in tubular, honeycomb (both according to *Bird R. B. et al. (1960)*) and packed bed reactors (according to *Ergun S. et al. (1949)*).

<h2 class="text-left"><b>CHEMKIN file handler</b></h2>
This feature of Asali allows to handle *CHEMKIN* input files to add new species and to convert them into the more usable [Cantera](https://cantera.org/) format.
