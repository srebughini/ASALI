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

    println!("Mixture molecular weight:     {:.3e}  [kmol/kg]",asali_obj.get_mixture_molecular_weight());
    println!("Density:                      {:.3e}  [kg/m3]",asali_obj.get_density());

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
}