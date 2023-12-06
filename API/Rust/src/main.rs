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

    println!("\nSpecies viscosity [Pas]");
    for j in 0..asali_obj.get_number_of_species() as usize {
        println!("{}\t{:.5e}", names[j],mu[j]);
    }
    

    //asali.resize(3);
    
    //asali.set_mole_fraction(&[0.1, 0.2, 0.7]);
}