# **ASALI: Modeling and beyond**

The Asali version with **Graphical User Interface** is an open-source code developed for engineers, chemists and students working on the modeling of gas phase mixture. From one side, thanks to its user-friendly interface, Asali is very helpful for those approaching the modeling of gas phase mixture for the first time. On the other side, the deep interaction with [Cantera](https://cantera.org/)  allows more expert users in performing detailed simulations without losing time in coding their own models.
## **1. Introduction**
Let's go straight to the point! Asali main features are:
* Estimation of thermodynamic/transport properties of ideal gas mixture
* Linear regression of thermodynamic/transport properties of ideal gas mixture
* Evaluation of thermodynamic equilibrium of ideal gas mixture
* Estimation of vacuum properties based of gas kinetic theory
* Modeling catalytic reactors
* Modeling catalytic pellets
* Matlab and Octave interface for thermodynamic and transport properties

If you are interested in  more details regarding models implemented in Asali have a look at the following paragraph; if not, jump to section number 2 for the installation instructions.
### 1.1 Thermodynamic and transport properties
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
### 1.2 Linear regression
This feature of Asali applies a least square fit to derive *easy-to-handle* functions of thermodynamic/transport properties. In particular, Asali estimates the thermodynamic/transport properties by using [Cantera](https://cantera.org/) and derives exponential or linear functions describing these properties as a function of temperature.
### 1.3 Thermodynamic equilibrium
[Cantera](https://cantera.org/) calculates also the thermodynamic equilibrium of ideal gas mixtures. Therefore, Asali exploits this feature to evaluate the equilibrium at constant temperature or at constant pressure. For more information have a look at [Cantera](https://cantera.org/) user's guide.
### 1.4 Vacuum properties
The vacuum properties estimated by Asali are:
* Knudsen number
* Mean gas velocity
* Mean free path length
* Diffusivity

These properties are estimated according to the standard gas kinetic theory *(Curtiss, Charles F., and Joseph O. Hirschfelder. "Transport properties of multicomponent gas mixtures." The Journal of Chemical Physics 17.6 (1949): 550-555.)*. In particular, the diffusivity value is estimated considering both the viscous regime and the rarefied regime according to the Knudsen number.
### 1.5 Catalytic reactors
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
### 1.6 Catalytic pellets
Different catalytic pellet geometries are implemented in ASALI:
* Slab
* Sphere
* Cylinder

These models handle transport and thermodynamic properties from [Cantera](https://cantera.org/) or by using `User defined constant properties`. The diffusion coefficient inside the pellets is described by using a *reduction coefficient* or an *epsi-tau model*. From a kinetic point of view, all pellet models implemented in Asali handle micro-kinetic, user defined kinetic schemes and homogeneous reactions.

# **2. Installation instructions**
Asali is based on different open-source codes:
* [Cantera](https://cantera.org/): estimation of thermodynamic and transport properties based on the kinetic gas theory and NASA database
* [Eigen libraries](http://eigen.tuxfamily.org/index.php?title=Main_Page): linear system solver and handling of numerical issues
* [Sundials libraries](https://computation.llnl.gov/projects/sundials): IDA and CVODE solvers for Ordinay Differentional Equation (ODE) and Differential and Algebraic Equation (DAE) systems
* [Gtkmm](https://www.gtkmm.org/en/): gnome based graphical interface
* [PLplot](http://plplot.org/): a cross-platform software package for creating scientific plots

Asali has been tested on:
* *Ubuntu 16.04 LTS*
* *Ubuntu 18.04 LTS*
* *Ubuntu 20.04 LTS*
* *Ubuntu 22.04 LTS*
* *Windows 10*
* *Windows 8*
* *Debian Wheezy*   

If your Operating System (OS) is not one of them, please send us an [email](ste.rebu@outlook.it).

### 2.1 Linux OS
Asali has been tested on Ubuntu 16.04 LTS, Ubuntu 18.04 LTS, Ubuntu 20.04 LTS and Debian Wheez. Installation instructions can be found [here](LINUX.md).
### 2.3 Mingw-w64 on Windows
[Mingw-w64](https://www.msys2.org/) is a collection of tools and libraries providing you with an easy-to-use environment for building, installing and running native Windows software. This tools are those used to compile the Windows version of Asali.
Installation instructions can be found [here](MINGW64.md).

### 2.2 Windows OS
To install Asali on Windows just `double click` on `Asali-Setup.exe` and follow the instructions.
