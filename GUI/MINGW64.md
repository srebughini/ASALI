# **ASALI: Modeling and beyond**

## **1. Installation instructions - Mingw-w64**
Asali is based on different open-source codes:
* [Cantera](https://cantera.org/): estimation of thermodynamic and transport properties based on the kinetic gas theory and NASA database
* [Eigen libraries](http://eigen.tuxfamily.org/index.php?title=Main_Page): linear system solver and handling of numerical issues
* [Sundials libraries](https://computation.llnl.gov/projects/sundials): IDA and CVODE solvers for Ordinay Differentional Equation (ODE) and Differential and Algebraic Equation (DAE) systems
* [Gtkmm](https://www.gtkmm.org/en/): gnome based graphical interface
* [PLplot](http://plplot.org/): a cross-platform software package for creating scientific plots

### 1.1 Requirements installation
The required libraries can be installed by typing these commands:  
```bash
pacman -Syu
pacman -S scons python-setuptools make
pacman -S mingw64/mingw-w64-x86_64-python mingw64/mingw-w64-x86_64-boost mingw64/mingw-w64-x86_64-gcc mingw64/mingw-w64-x86_64-python-setuptools mingw64/mingw-w64-x86_64-libopenmpt mingw64/mingw-w64-x86_64-openmp mingw64/mingw-w64-x86_64-python-ruamel-yaml mingw64/mingw-w64-x86_64-yaml-cpp mingw64/mingw-w64-x86_64-libyaml mingw64/mingw-w64-x86_64-cython mingw-w64-x86_64-gcc-fortran mingw64/mingw-w64-x86_64-libgd git 
```
### 1.2 How to install Gtkmm libraries
[Gtkmm](https://www.gtkmm.org/en/) can be downloaded with the following command:  
```bash
pacman -S mingw64/mingw-w64-x86_64-gtkmm3
```
More details can be found at: https://www.gtkmm.org/en/  
### 1.3 How to install PLplot
[PLplot](http://plplot.org/) can be installed with the following command:  
```bash
pacman -S mingw64/mingw-w64-x86_64-plplot
```
Details can be found at: http://plplot.org/
### 1.4 How to install Cantera
[Cantera](https://cantera.org/) can be downloaded with the following command:    
```bash
git clone https://github.com/Cantera/cantera.git -b 2.6 --depth=1  
```
  
  
***Due to an issue related to `os.system` on [Mingw-w64](https://www.msys2.org/), before installing [Cantera](https://cantera.org/) type the following command:***
```bash
cd ASALI/GUI/Windows/SConstruct cantera/.
```
   
To install [Cantera](https://cantera.org/) type the following commands from the cantera folder:  
```bash
scons build system_sundials=n python_package=minimal cc_flags='-Os' matlab_toolbox=n doxygen_docs=n sphinx_docs=n debug=n optimize=yes prefix=/mingw64/
sudo scons install  
```
More details can be found at: https://cantera.org/install/compiling-install.html 
### 1.5 How to install ASALI
To install Asali run the following command.  
```bash
cd ASALI/GUI/Ubuntu
./build.sh --os windows  
```
The installation can be customized with the following options:  
|Option|Comment|
|--------|-----|
|`--help`|Show help message|
|`--clean`|Clean installation folder|
|`--os`|Select operating system|
|`--output-folder`|Select target folder|
|`--symbolic-link`|Create symbolic link in `/usr/local/bin/`|
|`--no-interaction`|Disable human interaction|
