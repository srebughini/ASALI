---
title: Thermodynamic and transport properties
permalink: /docs/api-introduction/
---
Let's go straight to the point! Asali library can estimate:
* Thermal conductivity
* Viscosity
* Density
* Binary and mixture diffusivity
* Enthalpy
* Entropy
* Specific heat at constant pressure
* Vacuum speed
* Mean free path length

Asali estimates the transport properties with the standard gas kinetic theory *(Curtiss, Charles F., and Joseph O. Hirschfelder. "Transport properties of multicomponent gas mixtures." The Journal of Chemical Physics 17.6 (1949): 550-555.)*. The thermodynamic properties of each species are based on the NASA parameters and calculated according to the approach proposed by Gordon and McBride *(Gordon, S., and B. J. McBride. "Technical Report SP-273." NASA Special Publication (1971))*. Moreover, thermodynamic properties of the gaseous mixture are estimated by applying the Gibbs theorem.