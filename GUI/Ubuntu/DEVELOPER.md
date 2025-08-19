# **ASALI: Modeling and beyond**

Here a list of important commands for Asali developers:

#### Create resources
To convert from qrc to resources_rc.py:
```bash
cd resources
pyrcc5 -o resources_rc.py resources.qrc
```

### Function to be added
* Solve the problem when changing layout - Right now is slow, maybe QStackedWidget is an option but you need to wrap layouts inside widgets
* Pressure loss calculation - To be implemented
* Chemkin to cantera conversion - Need the reading and the saving

#### TODO for future
This is a list of possibile updates
* Add action to thermo, transport, converter of the chemkin editor
* Create conda package for the gui
* Create linux installation instructions
* Create docker distribution
* Create windows distribution
* Find a better way to save the .exe file on github
* Find a way to create a file for installation on linux
* Improve the handling of the options using Enum in a smarter way
* Move to pyqt6
* Create chemkin to cantera page