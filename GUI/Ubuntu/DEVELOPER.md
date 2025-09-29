# **ASALI: Modeling and beyond**

Here a list of important commands for Asali developers:

#### Create resources
To convert from qrc to resources_rc.py:
```bash
cd resources
pyside6-rcc -o resources_rc.py resources.qrc
```

### Create executable file
```bash
conda activate asaligui
conda install pyinstaller -c conda-forge
pyinstaller --clean asali.spec
cp -r src/gui/ui dist/src/gui/ui
cp -r src/resources dist/src/resources
```

### TODO next step
* Try **upx** to improve dimensions of .exe file. 
* Find a way to let the download of only .exe and .deb from github release
* Fix project folder to not having structure that is not nested and compatible with pyinstaller


#### TODO for future
This is a list of possibile updates
* Create linux installation instructions
* Create docker distribution
* Create windows distribution
* Create linux .deb package
* Find a better way to save the .exe file on github
* Change logo of ASALIPY and JASALI with new color palette
* Change website logo