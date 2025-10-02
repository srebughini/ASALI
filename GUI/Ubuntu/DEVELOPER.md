# **ASALI: Modeling and beyond**
Here a list of important commands for Asali developers:
### 1. Create executable file
```bash
conda activate asaligui
conda install pyinstaller -c conda-forge
pyinstaller --clean asali.spec
```

### TODO next step
* Try **upx** to improve dimensions of .exe file. 
* Find a way to let the download of only .exe and .deb from github release

#### TODO for future
This is a list of possibile updates
* Create windows .exe package
* Create linux .deb package
* Find a better way to save the .exe and .deb file on github
* Change website logo