![logo](https://github.com/srebughini/ASALI/blob/master/Ubuntu/images/Logo.png)

ASALI is an open-source software for solving gas thermodynamic and transport properties, catalytic reactors and chemical equilibrium calculations.
ASALI is based on CANTERA open-source suite and on EIGEN libraries. CANTERA estimates the thermodynamic and transport properties based on the kinetic gas theory and NASA database. EIGEN libraries manage the complex numerical part of ASALI.
ASALI graphical interface is based on GTKMM libraries.

## 1. Ubuntu Version
To install ASALI, CANTERA, EIGEN libraries and GTKMM libraries are required.

### 1.1 How to install CANTERA
CANTERA can be installed with the following commands:  
* <code>sudo apt-get install python-software-properties</code>
* <code>sudo apt-add-repository ppa:speth/cantera</code>
* <code>sudo aptitude update</code>
* <code>sudo aptitude install cantera-python cantera-python3 cantera-dev</code>

More details can be found at: http://www.cantera.org/docs/sphinx/html/install.html

### 1.2 How to install EIGEN libraries
EIGEN libraries can be downloaded from: http://eigen.tuxfamily.org

### 1.3 How to install GTKMM libraries
GTKMM libraries can be installed with the following command:
* <code>sudo apt-get install libgtkmm-3.0-dev</code>

More details can be found at: https://www.gtkmm.org/en/

### 1.4 How to install ASALI
To install ASALI modify the make file as follow:
* change the environmental variable **CANTERA** with the path of you CANTERA installation.
  * E.g. <code>export CANTERA=$HOME/my/cantera/installation</code>
* change the environmental variable **EIGEN** with the path of your EIGEN libraries.
  * E.g. <code>export EIGEN=$HOME/my/eigen/libraries</code>

Once you have changed the environmental variables, run the following commands:

<code>./make.sh</code>

<code>sudo ln -s $HOME/your/asali/folder/Asali /usr/bin/Asali</code>

To run ASALI:

<code>Asali</code>

## 2. Windows Version
To install ASALI on Windows just **double click** on **Asali-Setup** and follow the instructions.

## 3. Matlab/Octave Version
The Matlab/Octave version of ASALI is totally new, so it is not based on CANTERA, EIGEN libraries or GTKMM libraries.
To use ASALI in MATLAB/Octave download **Asali.exe** and **Asali.m** and save them in your working folder.
