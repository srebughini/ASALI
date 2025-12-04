# **ASALI: Modeling and beyond**

The Asali version with **Graphical User Interface** is an open-source code developed for engineers, chemists and students working on the modeling of gas phase mixture. From one side, thanks to its user-friendly interface, Asali is very helpful for those approaching the modeling of gas phase mixture for the first time. On the other side, the deep interaction with [Cantera](https://cantera.org/)  allows more expert users in performing detailed simulations without losing time in coding their own models.

## **1. Introduction**
Let's go straight to the point! Asali main features are:
* Estimation of thermodynamic/transport properties of ideal gas mixture
* Regression of thermodynamic/transport properties of ideal gas mixture
* Evaluation of thermodynamic equilibrium of ideal gas mixture
* Estimation of vacuum properties based of gas kinetic theory
* Estimation of pressure drops in chemical reactors
* Conversion of CHEMKIN input files into [Cantera](https://cantera.org/) file.
* Insert new species in CHEMKIN transport and thermodynamic properties files.

If you are interested in  more details regarding models implemented in Asali have a look at the following paragraph; if not, jump to section number 2 for the installation instructions.

### 1.1 Thermodynamic and transport properties
The thermodynamic and transport properties evaluated by Asali are:
* Thermal conductivity
* Viscosity
* Binary and mixture diffusivity
* Enthalpy
* Entropy
* Specific heat at constant pressure
* Density
* Molecular weight

Asali can be considered as a powerful user-friendly interface of  [Cantera](https://cantera.org/), thus all the transport and thermodynamic properties are estimated following the approach implemented in  [Cantera](https://cantera.org/). The transport properties are evaluated with the standard gas kinetic theory *(Curtiss, Charles F., and Joseph O. Hirschfelder. "Transport properties of multicomponent gas mixtures." The Journal of Chemical Physics 17.6 (1949): 550-555.)*. The thermodynamic properties of each species are based on the NASA parameters and calculated according to the approach proposed by Gordon and McBride *(Gordon, S., and B. J. McBride. "Technical Report SP-273." NASA Special Publication (1971))*. Moreover, thermodynamic properties of the gaseous mixture are estimated by applying the Gibbs theorem.

### 1.2 Regression
This feature of Asali applies a least square fit to derive *easy-to-handle* functions of thermodynamic/transport properties. In particular, Asali estimates the thermodynamic/transport properties by using [Cantera](https://cantera.org/) and derives power law, linear or logarithmic functions describing these properties as a function of temperature.

### 1.3 Thermodynamic equilibrium
[Cantera](https://cantera.org/) calculates also the thermodynamic equilibrium of ideal gas mixtures. Therefore, Asali exploits this feature to evaluate the equilibrium at constant temperature or at constant pressure. For more information have a look at [Cantera](https://cantera.org/) user's guide.

### 1.4 Vacuum properties
The vacuum properties estimated by Asali are:
* Knudsen number
* Mean gas velocity
* Mean free path length
* Diffusivity

These properties are estimated according to the standard gas kinetic theory *(Curtiss, Charles F., and Joseph O. Hirschfelder. "Transport properties of multicomponent gas mixtures." The Journal of Chemical Physics 17.6 (1949): 550-555.)*. In particular, the diffusivity value is estimated considering both the viscous regime and the rarefied regime according to the Knudsen number.

### 1.5 Pressure drops
This feature of Asali allows to estimate pressure drops in tubular, honeycomb (both according to *Bird R. B. et al. (1960)*) and packed bed reactors (according to *Ergun S. et al. (1949)*).

### 1.6 CHEMKIN file handler
This feature of Asali allows to handle *CHEMKIN* input files to add new species and to convert them into the more usable [Cantera](https://cantera.org/) format.

# **2. Installation instructions**
Asali is based on different open-source codes:
* [BEERQ](https://srebughini.github.io/BEERQ/): Add beer quotes.
* [Cantera](https://cantera.org/): Software for estimation of thermodynamic and transport properties based on the kinetic gas theory and NASA database.
* [Numpy](https://numpy.org/): Python library for scientific computing.
* [Matplotlib](https://matplotlib.org/): Python library for scientific plotting.
* [Sympy](https://www.sympy.org/en/index.html): Python library for symbolic mathematics.
* [PySide6](https://pypi.org/project/PySide6/): Qt-based package for graphical interface.
* [Anaconda](https://www.anaconda.com/): Python package handler.

Asali has been tested on different Operating System (OS). If it is not working on yours, please send us an [email](ste.rebu@outlook.it).

### 2.1 Linux OS
Asali has been tested on:
* *Ubuntu 24.04 LTS*

To install Asali on Linux:
* download `Asali-Setup.deb` for [here](https://sourceforge.net/projects/asali/files/latest/download?os=ubuntu).
* write on terminal the following instruction: `sudo dpkg -i Asali-setup.deb`

### 2.2 Windows OS
Asali has been tested on:
* *Windows 11*
* *Windows 10*    

To install Asali on Windows:
* download `Asali-Setup.exe` for [here](https://sourceforge.net/projects/asali/files/latest/download?os=windows).
* double click on `Asali-Setup.exe` and follow the instructions

### 2.3 Developers (both on Windows OS and Linux OS)
#### 2.3.1 Requirements installation
Asali is based on [Anaconda](https://www.anaconda.com/), which can be downloaded and installed by following the instruction [here](https://www.anaconda.com/docs/getting-started/anaconda/install).
#### 2.3.2 Installation
To install Asali source code follow these instructions:
```bash
conda env create -f environment.yml
conda activate asaligui
python app.py
```
To create the *.exe* file follow these instructions:
```bash
conda activate asaligui
conda install pyinstaller -c conda-forge
pyinstaller --clean asali.spec
```
To create the *.deb* file follow these instructions:
```bash
conda activate asaligui
conda install pyinstaller -c conda-forge
pyinstaller --clean asali.spec
mkdir Asali-setup
mkdir Asali-setup/bin
cp -r deb/* Asali-setup/.
cp -r dist Asali/* Asali-setup/bin/Asali*
chmod 0775 Asali-setup/DEBIAN/prerm
chmod 0775 Asali-setup/DEBIAN/postinst
dpkg-deb --build Asali-setup
```


