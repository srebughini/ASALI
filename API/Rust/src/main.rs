mod definitions;
mod omega;
mod thermo;
mod transport;
mod asali;


fn main() {
    let asali = asali::Asali::new();
    //asali.set_temperature(393.15);
    //asali.set_pressure(4.0e5);
    //asali.resize(3);
    //asali.set_number_of_species(&["H2", "O2", "N2"]);
    //asali.set_mole_fraction(&[0.1, 0.2, 0.7]);
}