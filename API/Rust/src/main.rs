mod definitions;
mod omega;
mod thermo;
mod transport;
mod asali;


fn main() {
    let mut asali_obj = asali::Asali::new();
    
    asali_obj.set_temperature(393.15);
    println!("Temperature: {} K", asali_obj.get_temperature());
    
    asali_obj.set_pressure(4.0e5);
    println!("Pressure: {} Pa", asali_obj.get_pressure());
    
    asali_obj.set_number_of_species(3);
    println!("Number of species: {}", asali_obj.get_number_of_species());
    
    asali_obj.set_species_names(vec!["H2".to_string(), "O2".to_string(), "N2".to_string()]);
    asali_obj.set_mole_fraction(vec![0.1,0.2,0.7]);
    let names = asali_obj.get_species_names();
    let mu = asali_obj.get_species_viscosity();
    let cp = asali_obj.get_species_mass_specific_heat();
    let h = asali_obj.get_species_mass_enthalpy();
    let s = asali_obj.get_species_mass_entropy();
    let cond = asali_obj.get_species_thermal_conductivity();
    let diff = asali_obj.get_binary_diffusion();
    let diff_mix = asali_obj.get_mixture_diffusion();
    let v = asali_obj.get_arithmetic_mean_gas_velocity();
    let l = asali_obj.get_mean_free_path();

    println!("Mixture molecular weight:     {:.3e}  [kmol/kg]",asali_obj.get_mixture_molecular_weight());
    println!("Density:                      {:.3e}  [kg/m3]",asali_obj.get_density());
    println!("Mixture viscosity:            {:.3e}  [Pas]",asali_obj.get_mixture_viscosity());
    println!("Mixture specific heat:        {:.3e}  [J/kg/K]",asali_obj.get_mixture_mass_specific_heat());
    println!("Mixture specific heat:        {:.3e}  [J/kmol/K]",asali_obj.get_mixture_molar_specific_heat());
    println!("Mixture thermal conductivity: {:.3e}  [W/m/K]",asali_obj.get_mixture_thermal_conductivity());
    println!("Mixture enthalpy:             {:.3e}  [J/kg]",asali_obj.get_mixture_mass_enthalpy());
    println!("Mixture enthalpy:             {:.3e}  [J/kmol]",asali_obj.get_mixture_molar_enthalpy());
    println!("Mixture entropy:              {:.3e}  [J/kg/K]",asali_obj.get_mixture_mass_entropy());
    println!("Mixture entropy:              {:.3e}  [J/kmol/K]",asali_obj.get_mixture_molar_entropy());

    println!("\nSpecies viscosity [Pas]");
    for j in 0..asali_obj.get_number_of_species() as usize {
        println!("{}\t{:.3e}",names[j],mu[j]);
    }

    println!("\nSpecies binary diffusion coefficient [m2/s]");
    for j in 0..asali_obj.get_number_of_species() as usize {
        println!("{}:\t{:.3e}\t{:.3e}\t{:.3e}",names[j],diff[j][0], diff[j][1], diff[j][2]);
    }

    println!("\nSpecies specific heat [J/kg/K]");
    for j in 0..asali_obj.get_number_of_species() as usize {
        println!("{}\t{:.3e}",names[j],cp[j]);
    }

    println!("\nSpecies enthalpy [J/kg]");
    for j in 0..asali_obj.get_number_of_species() as usize {
        println!("{}\t{:.3e}",names[j],h[j]);
    }

    println!("\nSpecies entropy [J/kg/K]");
    for j in 0..asali_obj.get_number_of_species() as usize {
        println!("{}\t{:.3e}",names[j],s[j]);
    }

    println!("\nSpecies thermal conductivity [W/m/K]");
    for j in 0..asali_obj.get_number_of_species() as usize {
        println!("{}\t{:.3e}",names[j],cond[j]);
    }

    println!("\nMixture diffusion coefficient [m2/s]");
    for j in 0..asali_obj.get_number_of_species() as usize {
        println!("{}\t{:.3e}",names[j],diff_mix[j]);
    }

    println!("\nMean gas velocity [m/s]");
    for j in 0..asali_obj.get_number_of_species() as usize {
        println!("{}\t{:.3e}",names[j],v[j]);
    }

    println!("\nMean free path [m]");
    for j in 0..asali_obj.get_number_of_species() as usize {
        println!("{}\t{:.3e}",names[j],l[j]);
    }
}