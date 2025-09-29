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
pyinstaller --clean one_file.spec
cp src/gui/ui/output/*.ui dist/src/gui/ui/output
cp src/resources/database/*.yaml dist/src/resources/database
cp src/resources/database/*.yaml dist/src/resources/database
cp src/resources/images/*.png dist/src/resources/images
cp src/resources/qss/*.qss dist/src/resources/qss
```

### TODO next step
* Try **upx** to improve dimensions of .exe file. 
* Find a way to let the download of only .exe and .deb from github release


#### TODO for future
This is a list of possibile updates
* Create linux installation instructions
* Create docker distribution
* Create windows distribution
* Create linux .deb package
* Find a better way to save the .exe file on github
* Change logo of ASALIPY and JASALI with new color palette
* Change website logo