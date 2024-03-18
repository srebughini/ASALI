from asali import Asali

if __name__ == "__main__":
    asali = Asali(373.15, 4e05)

    asali.mole_composition = {"H2": 0.1, "O2": 0.2, "N2": 0.7}

    mu = asali.species_viscosity
    cp = asali.species_mass_specific_heat
    h = asali.species_mass_enthalpy
    s = asali.species_mass_entropy
    diff = asali.species_binary_diffusion
    diff_mix = asali.mixture_diffusion
    cond = asali.species_thermal_conductivity
    v = asali.arithmetic_mean_gas_velocity
    l = asali.mean_free_path

    print("Mixture molecular weight:     ", asali.mixture_molecular_weight, "[kg/kmol]")
    print("Density:                      ", asali.density, "[kg/m3]")
    print("Mixture viscosity:            ", asali.mixture_viscosity, "[Pas]")
    print("Mixture specific heat:        ", asali.mixture_mass_specific_heat, "[J/kg/K]")
    print("Mixture specific heat:        ", asali.mixture_molar_specific_heat, "[J/kmol/K]")
    print("Mixture enthalpy:             ", asali.mixture_mass_enthalpy, "[J/kg]")
    print("Mixture enthalpy:             ", asali.mixture_molar_enthalpy, "[J/kmol]")
    print("Mixture thermal conductivity: ", asali.mixture_thermal_conductivity, "[W/m/K]")
    print("Mixture entropy:              ", asali.mixture_molar_entropy, "[J/kg/K]")
    print("Mixture entropy:              ", asali.mixture_mass_entropy, "[J/kmol/K]")

    print("\nSpecies viscosity [Pas]")
    for i in range(0, asali.number_of_species):
        print(asali.species_name[i], mu[i])

    print("\nSpecies binary diffusion coefficient [m2/s]")
    for i in range(0, asali.number_of_species):
        print(asali.species_name[i], diff[i][0], diff[i][1], diff[i][2])

    print("\nSpecies specific heat [J/kg/K]")
    for i in range(0, asali.number_of_species):
        print(asali.species_name[i], cp[i])

    print("\nSpecies enthalpy [J/kg]")
    for i in range(0, asali.number_of_species):
        print(asali.species_name[i], h[i])

    print("\nSpecies entropy [J/kg/K]")
    for i in range(0, asali.number_of_species):
        print(asali.species_name[i], s[i])

    print("\nSpecies thermal conductivity [W/m/K]")
    for i in range(0, asali.number_of_species):
        print(asali.species_name[i], cond[i])

    print("\nMixture diffusion coefficient [m2/s]")
    for i in range(0, asali.number_of_species):
        print(asali.species_name[i], diff_mix[i])

    print("\nMean gas velocity [m/s]")
    for i in range(0, asali.number_of_species):
        print(asali.species_name[i], v[i])

    print("\nMean free path [m]")
    for i in range(0, asali.number_of_species):
        print(asali.species_name[i], l[i])