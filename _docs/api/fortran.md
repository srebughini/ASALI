---
permalink: /docs/api-fortran/
redirect_from: /docs/index.html
---

## **Fortran version**
The Fortran API requires the [Lapack libraries](http://www.netlib.org/lapack/) which can be install with the following command:

```
sudo apt-get install liblapack-dev
``` 

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
    cp = get_species_mass_specific_heat()
```

Example and database generator can be compiled by typing:
```
./compile.sh
```

To convert the Asali database into Fortran code run:
```
./database-generator
```
