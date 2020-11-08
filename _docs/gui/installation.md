---
permalink: /docs/gui-installation/
redirect_from: /docs/index.html
---
# **Installation instructions**
Asali is based on different open-source codes:
* [Cantera](https://cantera.org/): estimation of thermodynamic and transport properties based on the kinetic gas theory and NASA database
* [Eigen libraries](http://eigen.tuxfamily.org/index.php?title=Main_Page): linear system solver and handling of numerical issues
* [Sundials libraries](https://computation.llnl.gov/projects/sundials): IDA and CVODE solvers for Ordinay Differentional Equation (ODE) and Differential and Algebraic Equation (DAE) systems
* [Gtkmm](https://www.gtkmm.org/en/): gnome based graphical interface
* [Matplotlib](https://matplotlib.org/): a comprehensive library for creating static, animated, and interactive visualizations in Python

Asali has been tested on Ubuntu 16.04 LTS, Ubuntu 18.04 LTS, Windows 10, Windows 8 and Debian Wheezy. If your Operating System (OS) is not one of them, please send us an email: ste.rebu@outlook.it

## Linux OS
### Pre-requisites installation
The Linux based external libraries can be installed by typing these commands:  
```
sudo apt-get update  
sudo apt-get install build-essential scons git python3-ruamel.yaml python3-yaml g++ gfortran python libboost-dev cython python-dev python-numpy python-numpy-dev python-setuptools python3 python3-dev python3-setuptools python3-numpy cython3`  
sudo update-alternatives --install /usr/bin/python python /usr/bin/python3 1
```

### How to install Gtkmm libraries
[Gtkmm](https://www.gtkmm.org/en/) can be downloaded with the following command:  
```
sudo apt-get install libgtkmm-3.0-dev
```  
More details can be found at: [https://www.gtkmm.org/en/](https://www.gtkmm.org/en/) 

### How to install Matplotlib
[Matplotlib](https://matplotlib.org/) can be installed with the following command:  
```
sudo apt-get install python3-matplotlib  
```
Details can be found at: [https://matplotlib.org/](https://matplotlib.org/)

### How to install Cantera
[Cantera](https://cantera.org/) can be downloaded with the following command:    
```
git clone https://github.com/Cantera/cantera.git
```  
To install [Cantera](https://cantera.org/) type the following commands from the cantera folder:  
```
scons build system_sundials=n   
sudo scons install
```    
More details can be found at: [https://cantera.org/install/compiling-install.html](https://cantera.org/install/compiling-install.html) 

### How to install ASALI
To install Asali run the following command, where `CANTERA_PREFIX` is the path of your [Cantera](https://cantera.org/) installation (usually `/usr/local/`).  
```
make all CANTERA_PREFIX=/usr/local/
./Asali
```  

## Windows OS
To install Asali on Windows just `double click` on `Asali-Setup.exe` and follow the instructions.