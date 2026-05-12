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

using Printf
include("asali.jl")


species = String["H2","O2","C3H8","C2H6","CH4","CO2","HE","N2","NH3"]
x = Float64[0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.2]

n = parse(Int, ARGS[1])

estimation_start = time_ns()
for i in 1:n
    asali.set_temperature(393.15)
    asali.set_pressure(4e05)
    asali.set_number_of_species(9)
    asali.set_species_names(species)
    asali.set_mole_fraction(x)

    mu = asali.get_species_viscosity()
    MWmix = asali.get_mixture_molecular_weight()
    rho = asali.get_density()
    bdiff = asali.get_binary_diffusion()
    cp = asali.get_species_mass_specific_heat()
    h = asali.get_species_mass_enthalpy()
    s = asali.get_species_mass_entropy()
    cond = asali.get_species_thermal_conductivity()
    condmix = asali.get_mixture_thermal_conductivity()
    mumix = asali.get_mixture_viscosity()
    diffmix = asali.get_mixture_diffusion()
    v = asali.get_aritmetic_mean_gas_velocity()
    l = asali.get_mean_free_path()
    cpmolemix = asali.get_mixture_molar_specific_heat()
    cpmassmix = asali.get_mixture_mass_specific_heat()
    hmolemix = asali.get_mixture_molar_enthalpy()
    hmassmix = asali.get_mixture_mass_enthalpy()
    smolemix = asali.get_mixture_molar_entropy()
    smassmix = asali.get_mixture_mass_entropy()
end

estimation_end = time_ns()

calc_time = (estimation_end - estimation_start) * 1e-9 / n

println("Julia version")
println("Initialization (s):  n.a.")
println("Calculation (s):     ", @sprintf("%.3e", calc_time))