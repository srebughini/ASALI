# **ASALI: Modeling and beyond**
Asali is an open-source code developed for engineers, chemists and students working on the modeling of gas phase mixture. From one side, thanks to its user-friendly interface, Asali is very helpful for those approaching the modeling of gas phase mixture for the first time. On the other side, the deep interaction with [Cantera](https://cantera.org/)  allows more expert users in performing detailed simulations without losing time in coding their own models.
## **1. Introduction**
Let's go straight to the point! Asali main features are:
* Estimation of thermodynamic/transport properties of ideal gas mixture
* Evaluation of thermodynamic equilibrium of ideal gas mixture
* Estimation of vacuum properties based of gas kinetic theory
* Modeling catalytic reactors
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

Asali can be considered as a powerful user-friendly interface of  [Cantera](https://cantera.org/), thus all the transport and thermodynamic properties are estimated following the approach implemented in  [Cantera](https://cantera.org/). The transport properties are evaluated with the standard gas kinetic theory *(Curtiss, Charles F., and Joseph O. Hirschfelder. "Transport properties of multicomponent gas mixtures." The Journal of Chemical Physics 17.6 (1949): 550-555.)*. The thermodynamic properties of each species are based on the NASA parameters and calculated according to the approach proposed by Gordon and McBride *(Gordon, S., and B. J. McBride. "Technical Report SP-273." NASA Special Publication (1971))*. Moreover, thermodynamic properties of the gaseous mixture are estimated by applying the Gibbs theorem.
### 1.2 Thermodynamic equilibrium
[Cantera](https://cantera.org/) calculates also the thermodynamic equilibrium of ideal gas mixtures. Therefore, Asali exploits this feature to evaluate the equilibrium at constant temperature or at constant pressure. For more information have a look at [Cantera](https://cantera.org/) user's guide.
### 1.3 Vacuum properties
The vacuum properties estimated by Asali are:
* Knudsen number
* Mean gas velocity
* Mean free path length
* Diffusivity

These properties are estimated according to the standard gas kinetic theory *(Curtiss, Charles F., and Joseph O. Hirschfelder. "Transport properties of multicomponent gas mixtures." The Journal of Chemical Physics 17.6 (1949): 550-555.)*. In particular, the diffusivity value is estimated considering both the viscous regime and the rarefied regime according to the Knudsen number.
### 1.4 Catalytic reactors
Different catalytic reactor models are implemented in Asali:
* Batch reactor model
* Continuous stirred tank reactor model (CSTR)
* 1D Pseudo-homogeneous plug flow reactor model (PFR)
* 1D Heterogeneous plug flow reactor model
* Pressure drops

First of all, the transport and thermodynamic properties used by Asali in the reactor models are based on [Cantera](https://cantera.org/). Therefore the user can select either the `Default transport/thermodynamic properties` or `Load CANTERA kinetic/properties file` to performe a detailed simulations of catalytic reactors. However, since in most of the engineering problems, the transport and thermodynamic properties are considered constant, Asali allows users implement their own constant transport and thermodynamic properties. To enable this feature choose `User defined constant properties` option in the kinetic scheme window selection.
Secondly, from a kinetic point of view, all reactor models implemented in Asali handle micro-kinetic or user defined kinetic schemes. In particular, the micro-kinetic schemes must be written in [Cantera](https://cantera.org/) format. Moreover, for those users who want to implement their own reaction rates, Asali has a user-friendly interface allowing them write their own kinetic scheme.
Finally, the 1D Pseudo-homogeneous plug flow reactor model can be solved in transient and steady state mode, allowing a deep understading and analysis of the reactor behaviour.
The `Pressure drops` option is a calculator of pressure drops for different reactor geometries (e.g. honeycomb, packed bed) based on state-of-the-art correlations.
### 1.5 Matlab and Octave version
Despite [Matlab](https://it.mathworks.com/campaigns/products/trials.html?s_eid=ppc_29775072802&q=matlab) has become one of the most used tool at engineering classes (along with its open-source version: [Octave](https://www.gnu.org/software/octave/)), not so many thermodynamic and transport properties database are available for these softwares. One of the most popular is [Cantera](https://cantera.org/). However, coupling [Cantera](https://cantera.org/) with [Matlab](https://it.mathworks.com/campaigns/products/trials.html?s_eid=ppc_29775072802&q=matlab) is quite challenging for not expert coders and it requires lots of effort. For this reason, Asali has its own [Matlab](https://it.mathworks.com/campaigns/products/trials.html?s_eid=ppc_29775072802&q=matlab) interface, which is more user-friendly than [Cantera](https://cantera.org/)'s one.
# **2. Installation instructions**
Asali is based on different open-source codes:
* [Cantera](https://cantera.org/): estimation of thermodynamic and transport properties based on the kinetic gas theory and NASA database
* [Eigen libraries](http://eigen.tuxfamily.org/index.php?title=Main_Page): linear system solver and handling of numerical issues
* [Sundials libraries](https://computation.llnl.gov/projects/sundials): IDA and CVODE solvers for Ordinay Differentional Equation (ODE) and Differential and Algebraic Equation (DAE) systems
* [Gtkmm](https://www.gtkmm.org/en/): gnome based graphical interface
* [Gnuplot](http://www.gnuplot.info/): command-line driven graphing utility

Asali has been tested on Ubunut 16.04 LTS, Windows 10, Windows 8 and Debian Wheezy. If your Operating System (OS) is not one of them, please send us an email: ste.rebu@outlook.it

### 2.1 Linux OS
##### 2.1.1 Pre-requisites installation
The Linux based external libraries can be installed by typing these commands:  
`sudo apt-get update`  
`sudo apt-get install git g++ gfortran python scons libboost-dev cython python-dev python-numpy python-numpy-dev python-setuptools cython python3 python3-dev python3-setuptools python3-numpy python-software-properties`  

##### 2.1.2 How to install Gtkmm libraries
[Gtkmm](https://www.gtkmm.org/en/) can be downloaded with the following command:  
`sudo apt-get install libgtkmm-3.0-dev`  
More details can be found at: https://www.gtkmm.org/en/  

##### 2.1.3 How to install Gnuplot
[Gnuplot](http://www.gnuplot.info/) can be installed with the following command:  
`sudo apt-get install gnuplot`  
Details can be found at: http://gnuplot.info/  

##### 2.1.4 How to install Cantera
[Cantera](https://cantera.org/) can be downloaded with the following command:    
`git clone https://github.com/Cantera/cantera.git`   
To install [Cantera](https://cantera.org/) type the following commands from the cantera folder:  
`scons build system_sundials=n`   
`sudo scons install`    
More details can be found at: https://cantera.org/install/compiling-install.html 

##### 2.1.5 How to install ASALI
To install Asali modify the `compiled.sh` file by changing the environmental variable `CANTERA` with the path of you [Cantera](https://cantera.org/) installation (usually `/usr/local/`). Once you have changed the environmental variable, run the following commands:  
`./compile.sh`  
To create a symbolic link:  
`sudo ln -s $HOME/your/asali/folder/Asali /usr/bin/Asali`  
To run Asali:  
`Asali`  
### 2.2 Windows OS
To install Asali on Windows just `double click` on `Asali-Setup.exe` and follow the instructions.  

### 2.3 Matlab and Octave
The [Matlab](https://it.mathworks.com/campaigns/products/trials.html?s_eid=ppc_29775072802&q=matlab) and [Octave](https://www.gnu.org/software/octave/) version of Asali does not need installation. Just download `database.mat` and `Asali.m` and save them in your working folder. An example, showing how to access the thermodynamic and transport properties, is represented in `example.m`.
# 3. Contacts
For any question/issue contact us:  
E-mail: ste.rebu@outlook.it  
Facebook: [Asali](https://www.facebook.com/ASALIcode/)  
Twitter: [@ASALIcode](https://twitter.com/ASALIcode)  
LinkedIn: [Asalicode](https://www.linkedin.com/company/asalicode)  
