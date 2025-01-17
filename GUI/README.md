# **ASALI: Modeling and beyond**

The Asali version with **Graphical User Interface** is an open-source code developed for engineers, chemists and students working on the modeling of gas phase mixture. From one side, thanks to its user-friendly interface, Asali is very helpful for those approaching the modeling of gas phase mixture for the first time. On the other side, the deep interaction with [Cantera](https://cantera.org/)  allows more expert users in performing detailed simulations without losing time in coding their own models.
## **1. Introduction**
Let's go straight to the point! Asali main features are:
* Estimation of thermodynamic/transport properties of ideal gas mixture
* Regression of thermodynamic/transport properties of ideal gas mixture
* Evaluation of thermodynamic equilibrium of ideal gas mixture
* Estimation of vacuum properties based of gas kinetic theory
* Modeling catalytic reactors

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
### 1.2 Regression
This feature of Asali applies a least square fit to derive *easy-to-handle* functions of thermodynamic/transport properties. In particular, Asali estimates the thermodynamic/transport properties by using [Cantera](https://cantera.org/) and derives power law or linear functions describing these properties as a function of temperature.
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

First of all, the transport and thermodynamic properties used by Asali in the reactor models are based on [Cantera](https://cantera.org/). Therefore the user can select either the `Use default input file` or `Load Cantera input file` option to performe a detailed simulations of catalytic reactors. 
Secondly, from a kinetic point of view, all reactor models implemented in Asali handle micro-kinetic, user defined kinetic schemes and homogeneous reactions. In particular, the micro-kinetic or homogeneous schemes must be written in [Cantera](https://cantera.org/) format. 
Finally, due to its deeper interaction with [asalipy](https://srebughini.github.io/ASALI/docs/api-python/), Asali can handle user defined kinetic schemes and modeling all those reactors in transient and steady-state conditions.


# **2. Installation instructions**
Asali is based on different open-source codes:
* [Cantera](https://cantera.org/): to estimate thermodynamic and transport properties based on the kinetic gas theory and NASA database.
* [Asalipy](https://srebughini.github.io/ASALI/docs/api-python/): to model of chemical reactors.
* [Matplotlib](https://matplotlib.org/): to plot results.
* [Pandas](https://pandas.pydata.org/): to save results.

Asali has been tested on different Operating System (OS). If it is not working on yours, please send us an [email](ste.rebu@outlook.it).

### 2.1 Linux OS
Asali can be installed on Linux OS following the instructions reported [here](LINUX.md).

### 2.2 Windows OS
Asali has been tested on:
* *Windows 11*
* *Windows 10*    

To install Asali on Windows just `double click` on `Asali-Setup.exe` and follow the instructions.

### 2.3 Docker
Asali can be installed using [docker](https://docs.docker.com/). Installation instructions can be found [here](DOCKER.md).


