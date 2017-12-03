![logo](https://github.com/srebughini/ASALI-CHINI/blob/master/Ubuntu/images/Logo.png)

ASALI is an open-source software for solving gas thermodynamic and transport properties, catalytic reactors and chemical equilibrium calculations.

## 1. Ubuntu Version
ASALI-CHINI is based on EIGEN libraries, which manage the complex numerical part of ASALI-CHINI.

### 1.1 How to install EIGEN libraries
EIGEN libraries can be downloaded from: http://eigen.tuxfamily.org

### 1.2 How to install ASALI-CHINI
To install ASALI-CHINI modify the make file as follow:
* change the environmental variable **EIGEN** with the path of your EIGEN libraries.
  * E.g. <code>export EIGEN=$HOME/my/eigen/libraries</code>

Once you have changed the environmental variables, run the following commands:

<code>sudo apt-get install libgtkmm-3.0-dev</code>

<code>./make.sh</code>

<code>sudo ln -s $HOME/your/asali/folder/Asali-Chini /usr/bin/Asali-Chini</code>

To run ASALI-CHINI:

<code>Asali-Chini</code>

## 2. Windows Version
To install ASALI-CHINI on Windows just **double click** on **Asali-Chini-Setup** and follow the instructions.

## 3. Matlab/Octave Version
To use ASALI-CHINI in MATLAB/Octave download **Asali.exe** and **Asali.m** and save them in your working folder.
