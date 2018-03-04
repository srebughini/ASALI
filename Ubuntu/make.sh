rm -f Asali*

export CANTERA=/usr/

export EIGEN=/your/eigen/libraries

export ASALI_OS='-DASALI_ON_WINDOW=0'

g++ -std=c++11 -Wall -Wextra  $ASALI_OS -pthread src/main.cpp src/Asali.C src/BatchInterface.C src/BatchEquations.C src/Ph1DodeInterface.C src/Ph1bvpInterface.C src/Ph1DEquations.C src/canteraInterface.C src/speciesPopup.C src/asaliKinetic.C src/asaliProperties.C src/runBar.C -Isrc/ -I$EIGEN -I$CANTERA/include -L$CANTERA/lib `pkg-config gtkmm-3.0 --cflags --libs` -Wl,--start-group -lcantera -lblas -llapack -lcantera_fortran -lsundials_ida -lsundials_cvode -lsundials_cvodes -lsundials_nvecserial -Wl,--end-group -lgfortran -Wl,--no-as-needed -ldl -lpthread -lm -o Asali

