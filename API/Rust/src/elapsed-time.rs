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
#![allow(unused)]

mod definitions;
mod omega;
mod thermo;
mod transport;
mod asali;
use std::time::Instant;

fn main() {
    let args: Vec<String> = std::env::args().collect();
    let n: i32 = args[1].parse().unwrap();

    //Set up mixture composition
    let names: Vec<String> = vec!["H2".to_string(), "O2".to_string(), "N2".to_string()];
    let x : Vec<f64> = vec![0.1,0.2,0.7];

    //Initialize variables
    let initialization_start = Instant::now();
    for _i in 0..(n-1) as usize {
        let mut asali_obj = asali::Asali::new();
    }
    let mut asali_obj = asali::Asali::new();
    let initialization_duration = (initialization_start.elapsed().as_nanos() as f64)/1e09;

    let mut mu: Vec<f64>; 
    let mut diff: Vec<Vec<f64>>;
    let mut cp: Vec<f64>; 
    let mut h: Vec<f64>; 
    let mut s: Vec<f64>; 
    let mut cond: Vec<f64>; 
    let mut diff_mix: Vec<f64>; 
    let mut v: Vec<f64>; 
    let mut l: Vec<f64>; 
    let mut mwmix: f64;
    let mut rho: f64;
    let mut mumix: f64;
    let mut cpmassmix: f64;
    let mut cpmolemix: f64;
    let mut hmassmix: f64;
    let mut hmolemix: f64;
    let mut smassmix: f64;
    let mut smolemix: f64;
    let mut condmix: f64;

    let estimation_start = Instant::now();
    for _i in 0..n as usize {
        asali_obj.set_temperature(393.15);
        asali_obj.set_pressure(4.0e5);
        asali_obj.set_number_of_species(3);
        asali_obj.set_species_names(names.clone());
        asali_obj.set_mole_fraction(x.clone());

        mu = asali_obj.get_species_viscosity();
        diff = asali_obj.get_binary_diffusion();
        cp = asali_obj.get_species_mass_specific_heat();
        h = asali_obj.get_species_mass_enthalpy();
        s = asali_obj.get_species_mass_entropy();
        cond = asali_obj.get_species_thermal_conductivity();
        diff_mix = asali_obj.get_mixture_diffusion();
        v = asali_obj.get_arithmetic_mean_gas_velocity();
        l = asali_obj.get_mean_free_path();
        mwmix = asali_obj.get_mixture_molecular_weight();
        rho = asali_obj.get_density();
        mumix = asali_obj.get_mixture_viscosity();
        cpmassmix = asali_obj.get_mixture_mass_specific_heat();
        cpmolemix = asali_obj.get_mixture_molar_specific_heat();
        hmassmix = asali_obj.get_mixture_mass_enthalpy();
        hmolemix = asali_obj.get_mixture_molar_enthalpy();
        smassmix = asali_obj.get_mixture_mass_entropy();
        smolemix = asali_obj.get_mixture_molar_entropy();
        condmix = asali_obj.get_mixture_thermal_conductivity();
    }
    let estimation_duration = (estimation_start.elapsed().as_nanos() as f64)/1e09;
  
    println!("Rust version");
    println!("Initialization (s):  {:.3e}", initialization_duration/(n as f64));
    println!("Calculation (s):     {:.3e}", estimation_duration/(n as f64));
}