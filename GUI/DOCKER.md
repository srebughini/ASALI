# **ASALI: Modeling and beyond**

## **1. Installation instructions - DOCKER**
Asali is based on different open-source codes:
* [Cantera](https://cantera.org/): estimation of thermodynamic and transport properties based on the kinetic gas theory and NASA database
* [Eigen libraries](http://eigen.tuxfamily.org/index.php?title=Main_Page): linear system solver and handling of numerical issues
* [Sundials libraries](https://computation.llnl.gov/projects/sundials): IDA and CVODE solvers for Ordinay Differentional Equation (ODE) and Differential and Algebraic Equation (DAE) systems
* [Gtkmm](https://www.gtkmm.org/en/): gnome based graphical interface
* [PLplot](http://plplot.org/): a cross-platform software package for creating scientific plots
All these codes will be automatically installed while building the container

### 1.1 Requirements installation
The docker version of Asali requires [docker](https://docs.docker.com/), whose installation instruction can be found [here](https://docs.docker.com/engine/install/). 

### 1.2 How to build and run the container
The Asali container can be build with the following command:  
```bash
cd Docker  
sudo docker-compose build
sudo docker-compose up
```
