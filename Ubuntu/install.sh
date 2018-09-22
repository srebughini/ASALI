sudo apt-get update
sudo apt-get install git
sudo apt-get install python-software-properties g++ gfortran python scons libboost-dev cython python-dev python-numpy python-numpy-dev python-setuptools cython python3 python3-dev python3-setuptools python3-numpy -y
sudo apt-add-repository ppa:speth/cantera -y
sudo apt-get update
sudo apt-get install cantera-python cantera-python3 cantera-dev libgtkmm-3.0-dev gnuplot -y

git clone https://github.com/eigenteam/eigen-git-mirror.git

export EIGEN=$PWD/eigen-git-mirror
export CANTERA=/usr/
export ASALI_OS='-DASALI_ON_WINDOW=0'

g++ -std=c++11 -Wall -Wextra  $ASALI_OS -pthread src/main.cpp src/Asali.C src/transportProperties.C src/thermoProperties.C src/thermoTransportProperties.C src/vacuumProperties.C src/equilibriumCalculator.C src/catalyticReactors.C src/batchInterface.C src/batchEquations.C src/batchReactor.C src/ph1dBvpInterface.C src/ph1dOdeInterface.C src/ph1dEquations.C src/ph1dReactor.C src/het1dBvpInterface.C src/het1dOdeInterface.C src/het1dEquations.C src/het1dReactor.C src/cstrInterface.C src/cstrEquations.C src/cstrReactor.C src/canteraInterface.C src/speciesPopup.C src/asaliKinetic.C src/asaliProperties.C src/asaliCatalystProperties.C src/runBar.C src/asaliPlot.C src/chemkinConverter.C src/pressureDrops.C -Isrc/ -I$EIGEN -I$CANTERA/include -L$CANTERA/lib `pkg-config gtkmm-3.0 --cflags --libs` -Wl,--start-group -lcantera -lblas -llapack -lcantera_fortran -lsundials_ida -lsundials_cvode -lsundials_cvodes -lsundials_nvecserial -Wl,--end-group -lgfortran -Wl,--no-as-needed -ldl -lpthread -lm -o Asali

sudo ln -s $PWD/Asali /usr/bin/Asali
