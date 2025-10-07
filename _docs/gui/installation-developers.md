---
permalink: /docs/gui-installation-developers/
---
<h1 class="text-left"><b>Installation instructions</b></h1>
Asali is based on different open-source codes:
* [BEERQ](https://srebughini.github.io/BEERQ/): Add beer quotes.
* [Cantera](https://cantera.org/): Software for estimation of thermodynamic and transport properties based on the kinetic gas theory and NASA database.
* [Numpy](https://numpy.org/): Python library for scientific computing.
* [Matplotlib](https://matplotlib.org/): Python library for scientific plotting.
* [Sympy](https://www.sympy.org/en/index.html): Python library for symbolic mathematics.
* [PySide6](https://pypi.org/project/PySide6/): Qt-based package for graphical interface.
* [Anaconda](https://www.anaconda.com/): Python package handler.

Asali has been tested on different Operating System (OS). If it is not working on yours, please send us an [email](ste.rebu@outlook.it).
<h2 class="text-left"><b>Requirements installation</b></h2>
Asali is based on [Anaconda](https://www.anaconda.com/), which can be downloaded and installed by following the instruction [here](https://www.anaconda.com/docs/getting-started/anaconda/install).

<h2 class="text-left"><b>Installation</b></h2>
To install Asali source code follow these instructions:
```bash
conda env create -f environment.yml
conda activate asaligui
python app.py
```
To create the executable file follow these instructions:
```bash
conda activate asaligui
conda install pyinstaller -c conda-forge
pyinstaller --clean asali.spec
```