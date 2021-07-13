---
permalink: /docs/gui-installation-linux/
redirect_from: /docs/index.html
---
# **Installation instructions - Linux OS**
Asali is based on different open-source codes:
* [Cantera](https://cantera.org/): estimation of thermodynamic and transport properties based on the kinetic gas theory and NASA database
* [Eigen libraries](http://eigen.tuxfamily.org/index.php?title=Main_Page): linear system solver and handling of numerical issues
* [Sundials libraries](https://computation.llnl.gov/projects/sundials): IDA and CVODE solvers for Ordinay Differentional Equation (ODE) and Differential and Algebraic Equation (DAE) systems
* [Gtkmm](https://www.gtkmm.org/en/): gnome based graphical interface
* [PLplot](http://plplot.org/): a cross-platform software package for creating scientific plots

Asali has been tested on Ubuntu 16.04 LTS, Ubuntu 18.04 LTS, Ubuntu 20.04 LTS and Debian Wheezy. If your Operating System (OS) is not one of them, please send us an [email](ste.rebu@outlook.it).

### 1.1 Requirements installation
The Linux based external libraries can be installed by typing these commands:  
```bash
sudo apt-get update  
sudo apt-get install build-essential scons git python3-ruamel.yaml python3-yaml g++ gfortran python libboost-dev cython python-dev python-numpy python-numpy-dev python-setuptools python3 python3-dev python3-setuptools python3-numpy cython3  
sudo update-alternatives --install /usr/bin/python python /usr/bin/python3 1  
```

### 1.2 How to install Gtkmm libraries
[Gtkmm](https://www.gtkmm.org/en/) can be downloaded with the following command:  
```bash
sudo apt-get install libgtkmm-3.0-dev  
```
More details can be found at: https://www.gtkmm.org/en/  

### 1.3 How to install PLplot
[PLplot](http://plplot.org/) can be installed with the following command:  
```bash
sudo apt-get install libplplot-dev plplot-driver-cairo  
```
Details can be found at: http://plplot.org/  

### 1.4 How to install Cantera
[Cantera](https://cantera.org/) can be downloaded with the following command:    
```bash
git clone https://github.com/Cantera/cantera.git -b 2.5 --depth=1  
```
To install [Cantera](https://cantera.org/) type the following commands from the cantera folder:  
```bash
scons build system_sundials=n  
sudo scons install  
```
More details can be found at: https://cantera.org/install/compiling-install.html   

### 1.5 How to install ASALI
To install Asali run the following command.  
```bash
./build --os ubuntu  
```
The installation can be customized with the following options:  
|Option|Comment|
|--------|-----|
|`--help`|Show help message|
|`--clean`|Clean installation folder|
|`--cantera-path`|Select Cantera path|
|`--os`|Select operating system|
|`--output-folder`|Select target folder|
|`--symbolic-link`|Create symbolic link in `/usr/local/bin/`|
|`--no-interaction`|Disable human interaction|

To run Asali:  
```bash
./Asali  
```