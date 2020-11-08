---
permalink: /docs/gui-introduction/
redirect_from: /docs/index.html
---

# **Introduction**
Let's go straight to the point! Asali main features are:
* Estimation of thermodynamic/transport properties of ideal gas mixture
* Linear regression of thermodynamic/transport properties of ideal gas mixture
* Evaluation of thermodynamic equilibrium of ideal gas mixture
* Estimation of vacuum properties based of gas kinetic theory
* Modeling catalytic reactors
* Modeling catalytic pellets
* Matlab and Octave interface for thermodynamic and transport properties

If you are interested in  more details regarding models implemented in Asali have a look at the following paragraph; if not, jump to section number 2 for the installation instructions.
## Thermodynamic and transport properties
The thermodynamic and transport properties evaluated by Asali are:
* Thermal conductivity
* Viscosity
* Binary and mixture diffusivity
* Enthalpy
* Entropy
* Specific heat at constant pressure

Asali can be considered as a powerful user-friendly interface of  [Cantera](https://cantera.org/), thus all the transport and thermodynamic properties are estimated following the approach implemented in  [Cantera](https://cantera.org/). The transport properties are evaluated with the standard gas kinetic theory *(Curtiss, Charles F., and Joseph O. Hirschfelder. "Transport properties of multicomponent gas mixtures." The Journal of Chemical Physics 17.6 (1949): 550-555.)*. The thermodynamic properties of each species are based on the NASA parameters and calculated according to the approach proposed by Gordon and McBride *(Gordon, S., and B. J. McBride. "Technical Report SP-273." NASA Special Publication (1971))*. Moreover, thermodynamic properties of the gaseous mixture are estimated by applying the Gibbs theorem.
## Linear regression
This feature of Asali applies a least square fit to derive *easy-to-handle* functions of thermodynamic/transport properties. In particular, Asali estimates the thermodynamic/transport properties by using [Cantera](https://cantera.org/) and derives exponential or linear functions describing these properties as a function of temperature.
## Thermodynamic equilibrium
[Cantera](https://cantera.org/) calculates also the thermodynamic equilibrium of ideal gas mixtures. Therefore, Asali exploits this feature to evaluate the equilibrium at constant temperature or at constant pressure. For more information have a look at [Cantera](https://cantera.org/) user's guide.
## Vacuum properties
The vacuum properties estimated by Asali are:
* Knudsen number
* Mean gas velocity
* Mean free path length
* Diffusivity

These properties are estimated according to the standard gas kinetic theory *(Curtiss, Charles F., and Joseph O. Hirschfelder. "Transport properties of multicomponent gas mixtures." The Journal of Chemical Physics 17.6 (1949): 550-555.)*. In particular, the diffusivity value is estimated considering both the viscous regime and the rarefied regime according to the Knudsen number.
## Catalytic reactors
Different catalytic reactor models are implemented in Asali:
* Batch reactor model
* Continuous stirred tank reactor model (CSTR)
* 1D Pseudo-homogeneous plug flow reactor model (PFR)
* 1D Heterogeneous plug flow reactor model
* Pressure drops

First of all, the transport and thermodynamic properties used by Asali in the reactor models are based on [Cantera](https://cantera.org/). Therefore the user can select either the `Default transport/thermodynamic properties` or `Load CANTERA kinetic/properties file` to performe a detailed simulations of catalytic reactors. However, since in most of the engineering problems, the transport and thermodynamic properties are considered constant, Asali allows users implement their own constant transport and thermodynamic properties. To enable this feature choose `User defined constant properties` option in the kinetic scheme window selection.
Secondly, from a kinetic point of view, all reactor models implemented in Asali handle micro-kinetic, user defined kinetic schemes and homogeneous reactions. In particular, the micro-kinetic or homogeneous schemes must be written in [Cantera](https://cantera.org/) format. Moreover, for those users who want to implement their own reaction rates, Asali has a user-friendly interface allowing them write their own kinetic scheme.
Finally, the 1D Pseudo-homogeneous plug flow reactor model can be solved in transient and steady state mode, allowing a deep understading and analysis of the reactor behaviour.
The `Pressure drops` option is a calculator of pressure drops for different reactor geometries (e.g. honeycomb, packed bed) based on state-of-the-art correlations.
## Catalytic pellets
Different catalytic pellet geometries are implemented in ASALI:
* Slab
* Sphere
* Cylinder

These models handle transport and thermodynamic properties from [Cantera](https://cantera.org/) or by using `User defined constant properties`. The diffusion coefficient inside the pellets is described by using a *reduction coefficient* or an *epsi-tau model*. From a kinetic point of view, all pellet models implemented in Asali handle micro-kinetic, user defined kinetic schemes and homogeneous reactions.