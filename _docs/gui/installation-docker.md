---
permalink: /docs/gui-installation-docker/
---
<h1 class="text-left"><b>Installation instructions</b></h1>
Asali is based on different open-source codes:
* [Cantera](https://cantera.org/): estimation of thermodynamic and transport properties based on the kinetic gas theory and NASA database
* [Eigen libraries](http://eigen.tuxfamily.org/index.php?title=Main_Page): linear system solver and handling of numerical issues
* [Sundials libraries](https://computation.llnl.gov/projects/sundials): IDA and CVODE solvers for Ordinay Differentional Equation (ODE) and Differential and Algebraic Equation (DAE) systems
* [Gtkmm](https://www.gtkmm.org/en/): gnome based graphical interface
* [PLplot](http://plplot.org/): a cross-platform software package for creating scientific plots

Asali has been tested on Ubuntu 16.04 LTS, Ubuntu 18.04 LTS, Ubuntu 20.04 LTS, Ubuntu 22.04 LTS and Debian Wheezy. If your Operating System (OS) is not one of them, please send us an [email](ste.rebu@outlook.it).

<h2 class="text-left"><b>Requirements installation</b></h2>
The docker version of Asali requires [docker](https://docs.docker.com/), whose installation instruction can be found [here](https://docs.docker.com/engine/install/).  
Due to the graphical interface libraries, this version of Asali requires **2GB** of free disk.

<h2 class="text-left"><b>How to build and run the container</b></h2>
The following command builds the Asali container:  
```bash
cd Docker  
sudo docker-compose build
```
Type the following commmand to run the container: 
```bash
cd Docker  
sudo docker-compose up
```