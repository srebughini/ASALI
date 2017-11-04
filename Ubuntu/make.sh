rm -f Asali-*

export EIGEN=$HOME/my/eigen/libraries

g++ -std=c++11 -Wall -Wextra src/main.cpp src/odeSolver.C src/IdealReactors.C src/Chini.C src/speciesPopup.C src/Properties.C src/propertiesInterface.C -Isrc/ -I$EIGEN -o Asali-Chini `pkg-config gtkmm-3.0 --cflags --libs`

