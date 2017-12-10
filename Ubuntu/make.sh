rm -f Asali*

export CANTERA=/my/cantera/installation/

export EIGEN=/my/eigen/libraries/

export ASALI_OS='-DASALI_ON_WINDOW=0'

g++ -std=c++11 $ASALI_OS -pthread -w src/main.cpp src/odeSolver.C src/IdealReactors.C src/Asali.C src/canteraInterface.C src/speciesPopup.C -Isrc/ -I$EIGEN -I$CANTERA/include -L$CANTERA/lib `pkg-config gtkmm-3.0 --cflags --libs` -Wl,--start-group -lcantera -lblas -llapack -lcantera_fortran -Wl,--end-group -lgfortran -Wl,--no-as-needed -ldl -lpthread -lm -o Asali

