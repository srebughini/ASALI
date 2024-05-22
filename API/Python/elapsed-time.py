################################################################################################
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
################################################################################################

from asali import Asali
import argparse
import time

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='')
    parser.add_argument('--number-of-runs', dest='n', help='Number of runs')
    args = parser.parse_args()
    n = int(args.n)

    composition_dict = {
        "H2": 0.1,
        "O2": 0.1,
        "C3H8": 0.1,
        "C2H6": 0.1,
        "CH4": 0.1,
        "CO2": 0.1,
        "HE": 0.1,
        "N2": 0.1,
        "NH3": 0.2
    }

    # Initialize variables
    initialization_start = time.time_ns()
    for i in range(0, n - 1):
        asali = Asali(393.15, 4e05)
    asali = Asali(393.15, 4e05)
    initialization_end = time.time_ns()

    # Estimate properties
    estimation_start = time.time_ns()
    for i in range(0, n):
        asali.temperature = 393.15
        asali.pressure = 4e05
        asali.mole_composition = composition_dict

        mu = asali.species_viscosity
        diff = asali.species_binary_diffusion
        cp = asali.species_mass_specific_heat
        h = asali.species_mass_enthalpy
        s = asali.species_mass_entropy
        cond = asali.species_thermal_conductivity
        diff_mix = asali.mixture_diffusion
        v = asali.arithmetic_mean_gas_velocity
        f_path = asali.mean_free_path
        mwmix = asali.mixture_molecular_weight
        rho = asali.density
        mumix = asali.mixture_viscosity
        cpmassmix = asali.mixture_mass_specific_heat
        cpmolemix = asali.mixture_molar_specific_heat
        hmassmix = asali.mixture_mass_enthalpy
        hmolemix = asali.mixture_molar_enthalpy
        condmix = asali.mixture_thermal_conductivity
        smassmix = asali.mixture_mass_entropy
        smolemix = asali.mixture_molar_entropy

    estimation_end = time.time_ns()

    print("Python version")
    print("Initialization (s):  {:.3e}".format((initialization_end - initialization_start)*1e-09/float(n)))
    print("Calculation (s):     {:.3e}".format((estimation_end - estimation_start)*1e-09/float(n)))