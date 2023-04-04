mod definitions;
mod omega;
mod thermo;
mod transport;
mod asali;


fn main() {
    let mut asali = asali::Asali::new();
    asali.set_temperature(393.15);
    println!("Temperature: {} K", asali.get_temperature());
    asali.set_pressure(4.0e5);
    println!("Pressure: {} Pa", asali.get_pressure());
    asali.set_number_of_species(3);
    println!("Number of species: {}", asali.get_number_of_species());
    //asali.resize(3);
    
    //asali.set_mole_fraction(&[0.1, 0.2, 0.7]);
}