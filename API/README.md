# **ASALI: Modeling and beyond**
The Asali version with **Application Programming Interface** is an open-source code developed for engineers, chemists and students working on the modeling of gas phase mixture. This version of Asali is very helpful for those who need a reliable, simple and perfoming library for the estimation of thermodynamic and transport properties of ideal gas mixture. Moreover, the [elapsed time comparison](https://github.com/srebughini/ASALI/tree/api/API/elapsedTimeComparison) can be helpful to select the correct programming language based on its performance.  
However, if you are looking for something more advanced and more stable, we suggest [OpenSMOKE++](https://www.opensmokepp.polimi.it/) and [Cantera](https://cantera.org/).

## **1. Thermodynamic and transport properties**
Let's go straight to the point! Asali library can estimate:
* Thermal conductivity
* Viscosity
* Density
* Binary and mixture diffusivity
* Enthalpy
* Entropy
* Specific heat at constant pressure

Asali estimates the transport properties with the standard gas kinetic theory *(Curtiss, Charles F., and Joseph O. Hirschfelder. "Transport properties of multicomponent gas mixtures." The Journal of Chemical Physics 17.6 (1949): 550-555.)*. The thermodynamic properties of each species are based on the NASA parameters and calculated according to the approach proposed by Gordon and McBride *(Gordon, S., and B. J. McBride. "Technical Report SP-273." NASA Special Publication (1971))*. Moreover, thermodynamic properties of the gaseous mixture are estimated by applying the Gibbs theorem. The list of available species can be found [here](SPECIES.md)

## **2. Python version**
Interested in the python version? Check this: [ASALIPY](https://github.com/srebughini/ASALIPY)

## **3. Javascript version**
Interested in the Javascript version? Check this: [JaSali](https://github.com/srebughini/JASALI)

## **4. Matlab and Octave version**
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

## **5. Fortran version**
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

Example and database generator can be compiled by typing `./compile.sh`

To convert the Asali database into Fortran code run `./database-generator`

## **6. C version**
This version can be included in your code as follow:  
```c
//Include library
#include "Asali.h"

//Main
int main()
{
    //Create composition using Asali vectors format
    AsaliVector x,names;
    double X[3] = {0.1, 0.2, 0.7};
    empty_vector_of_char(&names,3);
    set_vector_element_from_char(&names,0,"H2");
    set_vector_element_from_char(&names,1,"O2");
    set_vector_element_from_char(&names,2,"N2");
    vector_from_double_array(&x,3,X);

    //Initialize Asali
    Asali asali;
    initialize(&asali);

    //Set up composition/pressure and temperature
    set_temperature(&asali,393.15);
    set_pressure(&asali,4e05);
    set_number_of_species(&asali,get_vector_size(&x));
    set_species_names(&asali,names);
    set_mole_fraction(&asali,x);

    //Properties evaluation
    AsaliVector cp;
    AsaliMatrix diff;

    diff = get_binary_diffusion(&asali);
    cp = get_species_mass_specific_heat(&asali);
    return 0;
}
```
Example and database generator can be compiled by typing `./compile.sh`

To convert the Asali database into C code run `./database-generator`

## **7. C++ version**
This version can be included in your code as follow:  
```cpp
//Include library
#include "Asali.h"

//Main
int main()
{
    //Create composition using std vectors
    std::vector<std::string> names(3);
    std::vector<double> x(3);

    names[0] = "H2";
    names[1] = "O2";
    names[2] = "N2";

    x[0] = 0.1;
    x[1] = 0.2;
    x[2] = 1. - x[0] - x[1];

    //Initialize Asali
    ASALI::Asali asali;

    //Set up composition/pressure and temperature
    asali.setSpecies(names);
    asali.setTemperature(393.15); //K
    asali.setPressure(4e05); //Pa
    asali.setMoleFraction(x);

    //Properties evaluation
    std::vector<std::vector<double>> diff = asali.binaryDiffusion();
    std::vector<double>              cp   = asali.speciesMassCp();
    return 0;
}
```
Example and database generator can be compiled by typing `./compile.sh`

To convert the Asali database into C++ code run `./database-generator`

## **8. Java version**
This version can be included in your code as follow:  
```java
//Include library
import java.io.*; 
import java.util.*;
import java.lang.*;
import java.text.*;

class AsaliJava 
{   
    //Main
    public static void main(String args[])  throws Exception 
    { 
		int N = Integer.valueOf(args[0]);

        //Create composition using Vector and ArrayList
        ArrayList<String> names = new ArrayList<String>();
        names.add("H2");
        names.add("O2");
        names.add("N2");
        
        Vector<Double> x = new Vector<Double>();
        x.add(0.1);
        x.add(0.2);
        x.add(0.7);

		//Initialize ASALI
		Asali asali_ = new Asali();

        //Set up composition/pressure and temperature
        asali_.set_number_of_species(3);
        asali_.set_species_names(names);
        asali_.set_mole_fraction(x);
        asali_.set_pressure(4e05); //Pa 
        asali_.set_temperature(393.15); //K

        //Properties evaluation
        double [][] diff;
        diff      = asali_.get_binary_diffusion();

        double [] cp;
        cp = asali_.get_species_mass_specific_heat();
    }
}
```
Example can be compiled by typing `./compile.sh`

## **9. Rust version**
This version can be included in your code as follow:  
```rust
//Include library
mod definitions;
mod omega;
mod thermo;
mod transport;
mod asali;

fn main() {
    //Create asali object
    let mut asali_obj = asali::Asali::new();
    
    //Set temperature
    asali_obj.set_temperature(393.15);

    //Set pressure
    asali_obj.set_pressure(4.0e5);
    
    //Set number of species
    asali_obj.set_number_of_species(3);
    
    //Set specie names
    asali_obj.set_species_names(vec!["H2".to_string(), "O2".to_string(), "N2".to_string()]);
    
    //Set mole composition
    asali_obj.set_mole_fraction(vec![0.1,0.2,0.7]);

    //Properties evaluation
    let diff = asali_obj.get_binary_diffusion();
    let cp = asali_obj.get_species_mass_specific_heat();
}
```
Example can be compiled by typing `cargo build`

To convert the Asali database into Rust code run `cargo run --bin database-generator`


