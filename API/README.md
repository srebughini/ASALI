# **ASALI: Modeling and beyond**
The Asali version with **Application Programming Interface** is an open-source code developed for engineers, chemists and students working on the modeling of gas phase mixture. This version of Asali is very helpful for those who need a reliable, simple and perfoming library for the estimation of thermodynamic and transport properties of ideal gas mixture.  
If you are looking for something more advance and with higher performance, we suggest [OpenSMOKE++](https://www.opensmokepp.polimi.it/) and [Cantera](https://cantera.org/).

## **1. Thermodynamic and transport properties**
Let's go straight to the point! Asali library can estimate:
* Thermal conductivity
* Viscosity
* Density
* Binary and mixture diffusivity
* Enthalpy
* Entropy
* Specific heat at constant pressure

Asali estimates the transport properties with the standard gas kinetic theory *(Curtiss, Charles F., and Joseph O. Hirschfelder. "Transport properties of multicomponent gas mixtures." The Journal of Chemical Physics 17.6 (1949): 550-555.)*. The thermodynamic properties of each species are based on the NASA parameters and calculated according to the approach proposed by Gordon and McBride *(Gordon, S., and B. J. McBride. "Technical Report SP-273." NASA Special Publication (1971))*. Moreover, thermodynamic properties of the gaseous mixture are estimated by applying the Gibbs theorem.
## **2. Matlab and Octave version**
The [Matlab](https://it.mathworks.com/campaigns/products/trials.html?s_eid=ppc_29775072802&q=matlab) and [Octave](https://www.gnu.org/software/octave/) API can be inlcuded in your code as follow:
```Matlab
%Class generation
p = Asali('database.mat');

%Set up composition/pressure and temperature
p.Pressure     = 4e05;
p.Temperature  = 393.15;
p.Names        = {'H2' 'O2' 'N2'};
p.MoleFraction = [0.1 0.2 0.7];

%Properties evaluation
cp = p.SpeciesMassSpecificHeat;
```
To create the file *database.mat* run the file `database-generator.m`
## **3. Fortran version**
The Fortran API requires the [Lapack libraries](http://www.netlib.org/lapack/) and it can be compiled with the following commands:  

`sudo apt-get install liblapack-dev`  
`./compile.sh`  

This version can be included in your code as follow:  
```fortran
!Include library
include "Asali.f90"

!Main
program example
    use asali
    implicit none

    character(len=200), dimension(3) :: names
    
    real, dimension(3) :: x, cp
    
    names(1) = 'H2'
    names(2) = 'O2'
    names(3) = 'N2'
    
    x(1) = 0.1
    x(2) = 0.2
    x(3) = 1 - x(1) - x(2)
    
    !Set up composition/pressure and temperature
    call set_temperature(393.15)
    call set_pressure(4e05)
    call set_number_of_species(3)
    call set_species_names(names)
    call set_mole_fraction(x)
    
    !Properties evaluation
    p = get_species_mass_specific_heat()
```
To convert the Asali database into Fortran code run:  

`./database-generator`
