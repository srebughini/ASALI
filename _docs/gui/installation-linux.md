---
permalink: /docs/gui-installation-linux/
redirect_from: /docs/index.html
---
<h1 class="text-rigth"><b>Installation instructions - Linux OS</b></h1>
Asali is based on different open-source codes:
* [Cantera](https://cantera.org/): estimation of thermodynamic and transport properties based on the kinetic gas theory and NASA database
* [Eigen libraries](http://eigen.tuxfamily.org/index.php?title=Main_Page): linear system solver and handling of numerical issues
* [Sundials libraries](https://computation.llnl.gov/projects/sundials): IDA and CVODE solvers for Ordinay Differentional Equation (ODE) and Differential and Algebraic Equation (DAE) systems
* [Gtkmm](https://www.gtkmm.org/en/): gnome based graphical interface
* [PLplot](http://plplot.org/): a cross-platform software package for creating scientific plots

Asali has been tested on Ubuntu 16.04 LTS, Ubuntu 18.04 LTS, Ubuntu 20.04 LTS, Ubuntu 22.04 LTS and Debian Wheezy. If your Operating System (OS) is not one of them, please send us an [email](ste.rebu@outlook.it).

<h2 class="text-rigth"><b>Requirements installation</b></h2>
The Linux based external libraries can be installed by typing these commands:  
<h3 class="text-rigth"><b>Ubuntu 16.04/Ubuntu 18.04/Ubuntu 20.04/Debian Wheezy</b></h3>
```bash
sudo apt-get update  
sudo apt-get install build-essential scons git python3-ruamel.yaml python3-yaml g++ gfortran python libboost-dev cython python-dev python-numpy python-numpy-dev python-setuptools python3 python3-dev python3-setuptools python3-numpy cython3 libyaml-cpp-dev  
sudo update-alternatives --install /usr/bin/python python /usr/bin/python3 1  
```
<h3 class="text-rigth"><b>Ubuntu 22.04</b></h3>
```bash
sudo apt-get update  
sudo apt-get install build-essential scons git python3-ruamel.yaml python3-yaml g++ gfortran libboost-dev python3 python3-dev python3-setuptools python3-numpy cython3 libyaml-cpp-dev
```

<h2 class="text-rigth"><b>How to install Gtkmm libraries</b></h2>
[Gtkmm](https://www.gtkmm.org/en/) can be downloaded with the following command:  
```bash
sudo apt-get install libgtkmm-3.0-dev  
```
More details can be found at: https://www.gtkmm.org/en/  

<h2 class="text-rigth"><b>How to install PLplot</b></h2>
[PLplot](http://plplot.org/) can be installed with the following command:  
```bash
sudo apt-get install libplplot-dev plplot-driver-cairo  
```
Details can be found at: http://plplot.org/  

<h2 class="text-rigth"><b>How to install Cantera</b></h2>
[Cantera](https://cantera.org/) can be downloaded with the following command:    
```bash
git clone https://github.com/Cantera/cantera.git -b 2.6 --depth=1  
```
To install [Cantera](https://cantera.org/) type the following commands from the cantera folder:  
```bash
scons build system_sundials=n python_package=minimal  
sudo scons install  
```
More details can be found at: https://cantera.org/install/compiling-install.html   

<h2 class="text-rigth"><b>How to install ASALI</b></h2>
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