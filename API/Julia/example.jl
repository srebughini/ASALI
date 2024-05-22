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


species = String["H2","O2","N2"]
x = Float64[0.1,0.2,0.7]
asali.set_temperature(393.15)
asali.set_pressure(4e05)
asali.set_number_of_species(3)
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

print(string("\nMixture molecular weigth:     ",@sprintf("%.3E", MWmix)," [kg/kmol]"))
print(string("\nDensity:                      ",@sprintf("%.3E", rho)," [kg/m3]"))
print(string("\nMixture viscosity:            ",@sprintf("%.3E", mumix)," [Pas]"))
print(string("\nMixture thermal conductivity: ",@sprintf("%.3E", condmix)," [W/m/K]"))
print(string("\nMixture specific heat:        ",@sprintf("%.3E", cpmassmix)," [J/kg/K]"))
print(string("\nMixture specific heat:        ",@sprintf("%.3E", cpmolemix)," [J/kmol/K]"))
print(string("\nMixture enthalpy:             ",@sprintf("%.3E", hmassmix)," [J/kg]"))
print(string("\nMixture enthalpy:             ",@sprintf("%.3E", hmolemix)," [J/kmol]"))
print(string("\nMixture entropy:              ",@sprintf("%.3E", smassmix)," [J/kg/K]"))
print(string("\nMixture entropy:              ",@sprintf("%.3E", smolemix)," [J/kmol/K]"))
print("\n")
print("\nSpecies viscosity [Pas]\n")
for i in 1:3
    print(string(species[i],": ",@sprintf("%.3E", mu[i]),"\n"))
end

print("\nSpecies binary diffusion coefficient [m2/s]\n")
for i in 1:3
    print(string(species[i],": ",@sprintf("%.3E", bdiff[i,1]),", ",@sprintf("%.3E", bdiff[i,2]),", ",@sprintf("%.3E", bdiff[i,3]),"\n"))
end

print("\nSpecies specific heat [J/kg/K]\n")
for i in 1:3
    print(string(species[i],": ",@sprintf("%.3E", cp[i]),"\n"))
end

print("\nSpecies enthalpy [J/kg]\n")
for i in 1:3
    print(string(species[i],": ",@sprintf("%.3E", h[i]),"\n"))
end

print("\nSpecies entropy [J/kg/K]\n")
for i in 1:3
    print(string(species[i],": ",@sprintf("%.3E", s[i]),"\n"))
end

print("\nSpecies thermal conductiviy [W/m/K]\n")
for i in 1:3
    print(string(species[i],": ",@sprintf("%.3E", cond[i]),"\n"))
end

print("\nMixture diffusion coefficient [m2/s]\n")
for i in 1:3
    print(string(species[i],": ",@sprintf("%.3E", diffmix[i]),"\n"))
end

print("\nMean gas velocity [m/s]\n")
for i in 1:3
    print(string(species[i],": ",@sprintf("%.3E", v[i]),"\n"))
end

print("\nMean free path [m]\n")
for i in 1:3
    print(string(species[i],": ",@sprintf("%.3E", l[i]),"\n"))
end
