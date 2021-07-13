---
permalink: /docs/gui-installation-mingw-w64/
redirect_from: /docs/index.html
---
# **Installation instructions - Windows with Mingw-w64**
Asali is based on different open-source codes:
* [Cantera](https://cantera.org/): estimation of thermodynamic and transport properties based on the kinetic gas theory and NASA database
* [Eigen libraries](http://eigen.tuxfamily.org/index.php?title=Main_Page): linear system solver and handling of numerical issues
* [Sundials libraries](https://computation.llnl.gov/projects/sundials): IDA and CVODE solvers for Ordinay Differentional Equation (ODE) and Differential and Algebraic Equation (DAE) systems
* [Gtkmm](https://www.gtkmm.org/en/): gnome based graphical interface
* [PLplot](http://plplot.org/): a cross-platform software package for creating scientific plots

[Mingw-w64](https://www.msys2.org/) is a collection of tools and libraries providing you with an easy-to-use environment for building, installing and running native Windows software. This tools are those used to compile the Windows version of Asali.

### Requirements installation
The required libraries can be installed by typing these commands:  
```bash
pacman -Syu
pacman -S scons python-setuptools make
pacman -S mingw64/mingw-w64-x86_64-python mingw64/mingw-w64-x86_64-boost mingw64/mingw-w64-x86_64-gcc mingw64/mingw-w64-x86_64-python-setuptools mingw64/mingw-w64-x86_64-libopenmpt mingw64/mingw-w64-x86_64-openmp mingw64/mingw-w64-x86_64-python-ruamel-yaml mingw64/mingw-w64-x86_64-yaml-cpp mingw64/mingw-w64-x86_64-libyaml mingw64/mingw-w64-x86_64-cython mingw-w64-x86_64-gcc-fortran mingw64/mingw-w64-x86_64-libgd git 
```  

### How to install Gtkmm libraries
[Gtkmm](https://www.gtkmm.org/en/) can be downloaded with the following command:  
```bash
pacman -S mingw64/mingw-w64-x86_64-gtkmm3
```
More details can be found at: https://www.gtkmm.org/en/  

### How to install PLplot
[PLplot](http://plplot.org/) can be installed with the following command:  
```bash
pacman -S mingw64/mingw-w64-x86_64-plplot
```
Details can be found at: http://plplot.org/  

### How to install Cantera
[Cantera](https://cantera.org/) can be downloaded with the following command:    
```bash
git clone https://github.com/Cantera/cantera.git -b 2.5 --depth=1  
```
To install [Cantera](https://cantera.org/) type the following commands from the cantera folder:  
```bash
scons build system_sundials=n python_package=minimal cc_flags='-Os' matlab_toolbox=n doxygen_docs=n sphinx_docs=n debug=n python_cmd=/mingw64/bin/python
sudo scons install  
```
More details can be found at: https://cantera.org/install/compiling-install.html   

### How to install ASALI
To install Asali run the following command.  
```bash
./build --os windows  
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
