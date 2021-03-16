/*##############################################################################################
#                                                                                              #
#     #############       #############       #############       ####                ####     #
#    #             #     #             #     #             #     #    #              #    #    #
#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #
#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #
#    #    #####    #     #    #              #    #####    #     #    #              #    #    #
#    #             #     #    #########      #             #     #    #              #    #    #
#    #             #     #             #     #             #     #    #              #    #    #
#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #
#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #
#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #
#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #
#     ####     ####       #############       ####     ####       #############       ####     #
#                                                                                              #
#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #
#                                                                                              #
################################################################################################
#                                                                                              #
#   License                                                                                    #
#                                                                                              #
#   This file is part of ASALI.                                                                #
#                                                                                              #
#   ASALI is free software: you can redistribute it and/or modify                              #
#   it under the terms of the GNU General Public License as published by                       #
#   the Free Software Foundation, either version 3 of the License, or                          #
#   (at your option) any later version.                                                        #
#                                                                                              #
#   ASALI is distributed in the hope that it will be useful,                                   #
#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #
#   GNU General Public License for more details.                                               #
#                                                                                              #
#   You should have received a copy of the GNU General Public License                          #
#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #
#                                                                                              #
##############################################################################################*/

#include "frontend/mainGui.hpp"

int main(int argc, char *argv[])
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "ASALI.CODE");

  ASALI::mainGui asali;

  return app->run(asali);
}

/*
#include "cantera/thermo.h"
#include "cantera/transport.h"
#include "cantera/kinetics.h"
#include "cantera/thermo/SurfPhase.h"
#include "cantera/kinetics/InterfaceKinetics.h"

int main(int argc, char** argv) {
    std::string filepath = "H2-O2-Rh.xml";
    std::string gasPhase = "gas";
    std::string surfPhase = "Rh_surface";

    // Create gas phase as ThermoPhase
    Cantera::ThermoPhase *thermo;
    thermo = Cantera::newPhase(filepath, gasPhase);

    // Create gas Transport from thermo
    Cantera::Transport *transport;
    {
        transport = Cantera::newDefaultTransportMgr(thermo);
    }

    // Create gas kinetic reactions as Kinetics from thermo
    Cantera::Kinetics *kinetic;
    {
        std::vector<Cantera::ThermoPhase *> gas_phases{thermo};
        kinetic = Cantera::newKineticsMgr(thermo->xml(), gas_phases);
    }

    // Create surface phase as SurfPhase and surface kinetic as InterfaceKinetics
    Cantera::SurfPhase *surface;
    Cantera::InterfaceKinetics *surface_kinetic;
    if (surfPhase != "none")
    {
        std::shared_ptr<Cantera::ThermoPhase> surface_as_thermo(Cantera::newPhase(filepath, surfPhase));
        std::vector<Cantera::ThermoPhase *> gas_and_surface_phases{thermo, surface_as_thermo.get()};
        std::shared_ptr<Cantera::Kinetics> surface_as_kinetic(Cantera::newKinetics(gas_and_surface_phases, filepath, surfPhase));

        std::shared_ptr<Cantera::SurfPhase>         surface_ptr         = std::dynamic_pointer_cast<Cantera::SurfPhase>(surface_as_thermo);
        std::shared_ptr<Cantera::InterfaceKinetics> surface_kinetic_ptr = std::dynamic_pointer_cast<Cantera::InterfaceKinetics>(surface_as_kinetic);
        surface = surface_ptr.get();
        surface_kinetic = surface_kinetic_ptr.get();

        for (auto& name : surface->speciesNames()) {
            Cantera::writelog("{}\n", name);
        }
    }
  return 0;
}
*/
