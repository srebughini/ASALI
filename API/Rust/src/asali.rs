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
use crate::thermo::thermo_update;
use crate::transport::transport_update;
use crate::omega::omega11_update;
use crate::omega::omega22_update;

use crate::definitions::Transport;
use crate::definitions::Thermo;
use crate::definitions::Omega;

use std::process::exit;
pub struct Asali {
    t_: f64,
    p_: f64,
    mw_mix_: f64,
    rho_: f64,
    mu_mix_: f64,
    cond_mix_: f64,
    cpmole_mix_: f64,
    cpmass_mix_: f64,
    hmole_mix_: f64,
    hmass_mix_: f64,
    smole_mix_: f64,
    smass_mix_: f64,
    mw_: Vec<f64>,
    x_: Vec<f64>,
    y_: Vec<f64>,
    mu_: Vec<f64>,
    diff_: Vec<Vec<f64>>,
    cpmole_: Vec<f64>,
    cpmass_: Vec<f64>,
    hmole_: Vec<f64>,
    hmass_: Vec<f64>,
    smole_: Vec<f64>,
    smass_: Vec<f64>,
    cond_: Vec<f64>,
    diff_mix_: Vec<f64>,
    v_: Vec<f64>,
    l_: Vec<f64>,
    nc_: i32,
    transport_index_: Vec<usize>,
    thermo_index_: Vec<usize>,
    name_: Vec<String>,
    mu_update_: bool,
    diff_update_: bool,
    rho_update_: bool,
    cp_update_: bool,
    h_update_: bool,
    s_update_: bool,
    cond_update_: bool,
    v_update_: bool,
    l_update_: bool,
    mu_mix_update_: bool,
    diff_mix_update_: bool,
    cond_mix_update_: bool,
    cpmole_mix_update_: bool,
    cpmass_mix_update_: bool,
    hmole_mix_update_: bool,
    hmass_mix_update_: bool,
    smole_mix_update_: bool,
    transport_: Vec<Transport>,
    thermo_: Vec<Thermo>,
    omega11_: Omega,
    omega22_: Omega

}

impl Asali{
    pub fn new() -> Asali {
        let mut transport = Vec::<Transport>::new();
        transport_update(&mut transport);

        let mut thermo = Vec::<Thermo>::new();
        thermo_update(&mut thermo);

        let omega11 = omega11_update();
        let omega22 = omega22_update();

        Asali {
            t_: 0.0,
            p_: 0.0,
            mw_mix_: 0.0,
            rho_: 0.0,
            mu_mix_: 0.0,
            cond_mix_: 0.0,
            cpmole_mix_: 0.0,
            cpmass_mix_: 0.0,
            hmole_mix_: 0.0,
            hmass_mix_: 0.0,
            smole_mix_: 0.0,
            smass_mix_: 0.0,
            mw_: Vec::<f64>::new(),
            x_: Vec::<f64>::new(),
            y_: Vec::<f64>::new(),
            mu_: Vec::<f64>::new(),
            diff_: Vec::<Vec::<f64>>::new(),
            cpmole_: Vec::<f64>::new(),
            cpmass_: Vec::<f64>::new(),
            hmole_: Vec::<f64>::new(),
            hmass_: Vec::<f64>::new(),
            smole_: Vec::<f64>::new(),
            smass_: Vec::<f64>::new(),
            cond_: Vec::<f64>::new(),
            diff_mix_: Vec::<f64>::new(),
            v_: Vec::<f64>::new(),
            l_: Vec::<f64>::new(),
            nc_: 0,
            transport_index_: Vec::<usize>::new(),
            thermo_index_: Vec::<usize>::new(),
            name_: Vec::<String>::new(),
            mu_update_: false,
            diff_update_: false,
            rho_update_: false,
            cp_update_: false,
            h_update_: false,
            s_update_: false,
            cond_update_: false,
            v_update_: false,
            l_update_: false,
            mu_mix_update_: false,
            diff_mix_update_: false,
            cond_mix_update_: false,
            cpmole_mix_update_: false,
            cpmass_mix_update_: false,
            hmole_mix_update_: false,
            hmass_mix_update_: false,
            smole_mix_update_: false,
            transport_: transport,
            thermo_: thermo,
            omega11_: omega11,
            omega22_: omega22
        }
    }
    
    pub fn set_temperature(&mut self, t: f64) {
        if t != self.t_ {
            self.t_ = t;
            self.mu_update_ = false;
            self.diff_update_ = false;
            self.rho_update_ = false;
            self.cp_update_ = false;
            self.h_update_ = false;
            self.s_update_ = false;
            self.cond_update_ = false;
            self.v_update_ = false;
            self.l_update_ = false;
            self.mu_mix_update_ = false;
            self.diff_mix_update_ = false;
            self.cond_mix_update_ = false;
            self.cpmole_mix_update_ = false;
            self.cpmass_mix_update_ = false;
            self.hmole_mix_update_ = false;
            self.hmass_mix_update_ = false;
            self.smole_mix_update_ = false;
        }
    }

    pub fn get_temperature(&self) -> f64 {
        self.t_
    }

    pub fn set_pressure(&mut self, p: f64) {
        if p != self.p_ {
            self.p_ = p;
            self.mu_update_ = false;
            self.diff_update_ = false;
            self.rho_update_ = false;
            self.cp_update_ = false;
            self.h_update_ = false;
            self.s_update_ = false;
            self.cond_update_ = false;
            self.v_update_ = false;
            self.l_update_ = false;
            self.mu_mix_update_ = false;
            self.diff_mix_update_ = false;
            self.cond_mix_update_ = false;
            self.cpmole_mix_update_ = false;
            self.cpmass_mix_update_ = false;
            self.hmole_mix_update_ = false;
            self.hmass_mix_update_ = false;
            self.smole_mix_update_ = false;
        }
    }

    pub fn get_pressure(&self) -> f64 {
        self.p_
    }

    pub fn set_number_of_species(&mut self, nc: i32) {
        if nc != self.nc_ {
            self.nc_ = nc;
            self.resize(nc);
        }
    }

    pub fn get_number_of_species(&self) -> i32 {
        self.nc_
    }

    pub fn set_species_names(&mut self, names: Vec<String>) {
        if names.len() == self.nc_ as usize {
            for j in 0..self.nc_ as usize {
                self.transport_index_[j] = usize::MAX;
                self.thermo_index_[j] = usize::MAX;
                self.name_[j] = names[j].to_string();
                
                for i in 0..self.transport_.len() as usize {
                    if self.name_[j].trim() == self.transport_[i].name.trim() {
                        self.transport_index_[j] = i;
                        self.mw_[j] = self.transport_[i].mw;
                        break;
                    }
                }
                if self.transport_index_[j] == usize::MAX {
                    println!("ASALI::ERROR-->{} is missing in ASALI database.", self.name_[j]);
                    exit(-1);
                }

                for i in 0..self.thermo_.len() as usize {
                    if self.name_[j].trim() == self.thermo_[i].name.trim() {
                        self.thermo_index_[j] = i;
                        break;
                    }
                }
                if self.thermo_index_[j] == usize::MAX {
                    println!("ASALI::ERROR-->{} is missing in ASALI database.", self.name_[j]);
                    exit(-1);
                }

            }
        } else {
            println!("ASALI::ERROR-->Wrong number of species names");
            exit(-1);
        }
        self.reset_bool();
    }

    pub fn get_species_names(&self) -> Vec<String> {
        self.name_.clone()
    }

    pub fn set_mass_fraction(&mut self, y: Vec<f64>) {
        if y.len() == self.nc_ as usize {
            self.mw_mix_ = 0.0;
            for i in 0..self.nc_ as usize {
                self.y_[i] = y[i];
                self.mw_mix_ += self.y_[i] / self.mw_[i];
            }
            for i in 0..self.nc_ as usize {
                self.x_[i] = (self.y_[i] / self.mw_[i]) / self.mw_mix_;
            }
            self.mw_mix_ = 1.0 / self.mw_mix_;
            self.reset_bool();
        } else {
            println!("ASALI::ERROR-->Wrong number of mass fraction");
            exit(-1);
        }
    }

    pub fn get_mass_fraction(&self) -> Vec<f64> {
        self.y_.clone()
    }

    pub fn set_mole_fraction(&mut self, x: Vec<f64>) {
        if x.len() == self.nc_ as usize {
            self.mw_mix_ = 0.;
            for i in 0..self.nc_ as usize {
                self.x_[i] = x[i];
                self.mw_mix_ += self.x_[i] * self.mw_[i];
            }
            for i in 0..self.nc_ as usize {
                self.y_[i] = self.x_[i] * self.mw_[i] / self.mw_mix_;
            }
            self.reset_bool();
        } else {
            println!("ASALI::ERROR-->Wrong number of mass fraction");
            exit(-1);
        }
    }

    pub fn get_mole_fraction(&self) -> Vec<f64> {
        self.x_.clone()
    }

    pub fn get_species_viscosity(&mut self) -> Vec<f64> {
        self.species_viscosity_();
        self.mu_.clone()
    }

    pub fn get_density(&mut self) -> f64 {
        self.density_();
        self.rho_
    }

    pub fn get_mixture_molecular_weight(&self) -> f64 {
        self.mw_mix_
    }

    pub fn get_species_molar_specific_heat(&mut self) -> Vec<f64> {
        self.species_cp_();
        self.cpmole_.clone()
    }
    
    pub fn get_species_mass_specific_heat(&mut self) -> Vec<f64> {
        self.species_cp_();
        self.cpmass_.clone()
    }

    pub fn get_species_molar_enthalpy(&mut self) -> Vec<f64> {
        self.species_h_();
        self.hmole_.clone()
    }

    pub fn get_species_mass_enthalpy(&mut self) -> Vec<f64> {
        self.species_h_();
        self.hmass_.clone()
    }

    pub fn get_species_molar_entropy(&mut self) -> Vec<f64> {
        self.species_s_();
        self.smole_.clone()
    }

    pub fn get_species_mass_entropy(&mut self) -> Vec<f64> {
        self.species_s_();
        self.smass_.clone()
    }

    pub fn get_species_thermal_conductivity(&mut self) -> Vec<f64> {
        self.species_thermal_conductivity_();
        self.cond_.clone()
    }

    pub fn get_binary_diffusion(&mut self) -> Vec<Vec<f64>> {
        self.binary_diffusion_();
        self.diff_.clone()
    }

    pub fn get_mixture_viscosity(&mut self) -> f64 {
        if !self.mu_mix_update_ {
            self.species_viscosity_();
            self.mu_mix_ = 0.0;
            for i in 0..self.nc_ as usize {
                let mut somma: f64 = 0.0;
                for j in 0..self.nc_ as usize {
                    let mut phi: f64 = (1./(8.0_f64).sqrt())*(1./(1. + self.mw_[i]/self.mw_[j]).sqrt());
                    phi = phi*(1. + (self.mu_[i]/self.mu_[j]).sqrt()*(self.mw_[j]/self.mw_[j]).powf(1./4.)).powi(2);
                    somma = somma + self.x_[j]*phi;
                }
                self.mu_mix_ = self.mu_mix_ + self.x_[i]*self.mu_[i]/somma;
            }
            self.mu_mix_update_ = true;
        }
        self.mu_mix_
    }

    pub fn get_mixture_mass_specific_heat(&mut self) -> f64 {
        if !self.cpmass_mix_update_ {
            self.species_cp_();
            self.cpmass_mix_ = self.estimate_mixture_property(self.cpmass_.clone(), self.y_.clone());
        }
        self.cpmass_mix_
    }

    pub fn get_mixture_molar_specific_heat(&mut self) -> f64 {
        if !self.cpmole_mix_update_ {
            self.species_cp_();
            self.cpmole_mix_ = self.estimate_mixture_property(self.cpmole_.clone(), self.x_.clone());
        }
        self.cpmole_mix_
    }

    pub fn get_mixture_mass_enthalpy(&mut self) -> f64 {
        if !self.hmass_mix_update_ {
            self.species_h_();
            self.hmass_mix_ = self.estimate_mixture_property(self.hmass_.clone(), self.y_.clone());
        }
        self.hmass_mix_
    }

    pub fn get_mixture_molar_enthalpy(&mut self) -> f64 {
        if !self.hmole_mix_update_ {
            self.species_h_();
            self.hmole_mix_ = self.estimate_mixture_property(self.hmole_.clone(), self.x_.clone());
        }
        self.hmole_mix_
    }

    pub fn get_mixture_molar_entropy(&mut self) -> f64 {
        if !self.smole_mix_update_ {
            self.species_s_();
            self.smole_mix_ = self.estimate_mixture_property(self.smole_.clone(), self.x_.clone());
        }
        self.smole_mix_
    }

    pub fn get_mixture_mass_entropy(&mut self) -> f64 {
        self.smass_mix_ = self.get_mixture_molar_entropy()/self.mw_mix_;
        self.smass_mix_
    }

    pub fn get_mixture_thermal_conductivity(&mut self) -> f64 {
        if !self.cond_mix_update_{
            self.species_thermal_conductivity_();
            let mut a: f64 = 0.0;
            let mut b: f64 = 0.0;
            for i in 0..self.nc_ as usize {
                a = a + self.x_[i]*self.cond_[i];
                b = b + self.x_[i]/self.cond_[i];
            }
            self.cond_mix_ = 0.5*(a + 1.0/b);
            self.cond_mix_update_ = true;
        }
        self.cond_mix_
    }

    pub fn get_mixture_diffusion(&mut self) -> Vec<f64> {
        if !self.diff_mix_update_{
            self.binary_diffusion_();
            for i in 0..self.nc_ as usize {
                let mut a: f64 = 0.0;
                let mut b: f64 = 0.0;
                for j in 0..self.nc_ as usize {
                    if j != i {
                        a = a + self.x_[j]*self.mw_[j];
                        b = b + self.x_[j]/self.diff_[j][i];
                    }
                }
                self.diff_mix_[i] = a/(self.mw_mix_*b);
            }
            self.diff_mix_update_ = true;
        }
        self.diff_mix_.clone()
    }

    pub fn get_arithmetic_mean_gas_velocity(&mut self) -> Vec<f64> {
        if !self.v_update_{
            for i in 0..self.nc_ as usize {
                self.v_[i] = (8.0*8314.0*self.t_/(std::f64::consts::PI*self.mw_[i])).sqrt();
            }
            self.v_update_ = true;
        }
        self.v_.clone()
    }

    pub fn get_mean_free_path(&mut self) -> Vec<f64> {
        if !self.l_update_{
            for i in 0..self.nc_ as usize {
                let idx = self.transport_index_[i];
                self.l_[i] = 1.38064852*1e-03*self.t_/((2.0_f64).sqrt()*self.p_*(self.transport_[idx].ljdiameter).powi(2));
            }
            self.l_update_ = true;
        }
        self.l_.clone()
    }

    fn resize(&mut self, nc: i32) {
        self.x_.resize(nc as usize, 0.0);
        self.y_.resize(nc as usize, 0.0);
        self.mu_.resize(nc as usize, 0.0);
        self.diff_.resize(nc as usize, vec![0.0; nc as usize]);
        self.cpmole_.resize(nc as usize, 0.0);
        self.cpmass_.resize(nc as usize, 0.0);
        self.hmole_.resize(nc as usize, 0.0);
        self.hmass_.resize(nc as usize, 0.0);
        self.smole_.resize(nc as usize, 0.0);
        self.smass_.resize(nc as usize, 0.0);
        self.cond_.resize(nc as usize, 0.0);
        self.diff_mix_.resize(nc as usize, 0.0);
        self.mw_.resize(nc as usize, 0.0);
        self.transport_index_.resize(nc as usize, usize::MAX);
        self.thermo_index_.resize(nc as usize, usize::MAX);
        self.name_.resize(nc as usize, String::new());
        self.v_.resize(nc as usize, 0.0);
        self.l_.resize(nc as usize, 0.0);
        self.nc_ = nc;
    }

    fn reset_bool(&mut self) {
        self.mu_update_ = false;
        self.diff_update_ = false;
        self.rho_update_ = false;
        self.cp_update_ = false;
        self.h_update_ = false;
        self.s_update_ = false;
        self.cond_update_ = false;
        self.v_update_ = false;
        self.l_update_ = false;
        self.mu_mix_update_ = false;
        self.diff_mix_update_ = false;
        self.cond_mix_update_ = false;
        self.cpmole_mix_update_ = false;
        self.cpmass_mix_update_ = false;
        self.hmole_mix_update_ = false;
        self.hmass_mix_update_ = false;
        self.smole_mix_update_ = false;
    }

    fn species_viscosity_(&mut self) {
        let mut tr: f64;
        let mut dr: f64;
        let mut sigma: f64;
        
        if !self.mu_update_ {
            for i in 0..self.nc_ as usize {
                tr = self.t_ / self.transport_[self.transport_index_[i]].ljpotential;
                dr = 0.5 * self.transport_[self.transport_index_[i]].dipole.powi(2);
                dr = dr / (self.transport_[self.transport_index_[i]].ljpotential * 1.3806488 * self.transport_[self.transport_index_[i]].ljdiameter.powi(3));
                dr = 1e06 * dr;
                sigma = self.collision_integrals_22(tr, dr);
                self.mu_[i] = (5. / 16.) * (std::f64::consts::PI * 1.3806488 * self.t_ * self.mw_[i] * 1.66054).sqrt() / (std::f64::consts::PI * sigma * self.transport_[self.transport_index_[i]].ljdiameter.powi(2));
                self.mu_[i] = self.mu_[i] * 1.0e-05;
            }
            self.mu_update_ = true;
        }
    }

    fn density_(&mut self) {
        if !self.rho_update_ {
            self.rho_ = self.mw_mix_ * self.p_ / (8314. * self.t_);
            self.rho_update_ = true;
        }
    }

    fn species_cp_(&mut self){
        if !self.cp_update_{
            for i in 0..self.nc_ as usize {
                let idx: usize = self.thermo_index_[i];
                if self.t_ < 1000.0 {
                    self.cpmole_[i] = self.thermo_[idx].low[0] + self.thermo_[idx].low[1]*self.t_ + self.thermo_[idx].low[2]*(self.t_).powi(2) + self.thermo_[idx].low[3]*(self.t_).powi(3) + self.thermo_[idx].low[4]*(self.t_).powi(4);
                }
                else {
                    self.cpmole_[i] = self.thermo_[idx].high[0] + self.thermo_[idx].high[1]*self.t_ + self.thermo_[idx].high[2]*self.t_.powi(2) + self.thermo_[idx].high[3]*self.t_.powi(3) + self.thermo_[idx].high[4]*self.t_.powi(4);
                }
                self.cpmole_[i] = self.cpmole_[i]*8314.0;
                self.cpmass_[i] = self.cpmole_[i]/self.mw_[i];
            } 
            self.cp_update_ = true;
        }
    }

    fn species_h_(&mut self){
        if !self.h_update_{
            for i in 0..self.nc_ as usize {
                let idx: usize = self.thermo_index_[i];
                if self.t_ < 1000.0 {
                    self.hmole_[i] = self.thermo_[idx].low[0] + self.thermo_[idx].low[1]*self.t_/2. + self.thermo_[idx].low[2]*self.t_.powi(2)/3. + self.thermo_[idx].low[3]*self.t_.powi(3)/4. + self.thermo_[idx].low[4]*self.t_.powi(4)/5. + self.thermo_[idx].low[5]/self.t_;
                }
                else {
                    self.hmole_[i] = self.thermo_[idx].high[0] + self.thermo_[idx].high[1]*self.t_/2. + self.thermo_[idx].high[2]*self.t_.powi(2)/3. + self.thermo_[idx].high[3]*self.t_.powi(3)/4. + self.thermo_[idx].high[4]*self.t_.powi(4)/5. + self.thermo_[idx].high[5]/self.t_;
                }
                self.hmole_[i] = self.hmole_[i]*8314.0*self.t_;
                self.hmass_[i] = self.hmole_[i]/self.mw_[i];
            } 
            self.h_update_ = true;
        }
    }

    fn species_s_(&mut self){
        if !self.s_update_{
            let mut v: f64;
            for i in 0..self.nc_ as usize {
                let idx: usize = self.thermo_index_[i];
                if self.t_ < 1000.0 {
                    self.smole_[i] = self.thermo_[idx].low[0]*(self.t_).ln() + self.thermo_[idx].low[1]*self.t_ + self.thermo_[idx].low[2]*self.t_.powi(2)/2. + self.thermo_[idx].low[3]*self.t_.powi(3)/3. + self.thermo_[idx].low[4]*self.t_.powi(4)/4. + self.thermo_[idx].low[6];
                }
                else {
                    self.smole_[i] = self.thermo_[idx].high[0]*(self.t_).ln() + self.thermo_[idx].high[1]*self.t_ + self.thermo_[idx].high[2]*self.t_.powi(2)/2. + self.thermo_[idx].high[3]*self.t_.powi(3)/3. + self.thermo_[idx].high[4]*self.t_.powi(4)/4. + self.thermo_[idx].high[6];
                }
                v = self.p_*self.x_[i]/1.0e05;
                self.smole_[i] = 8314.0*(self.smole_[i] - v.ln());
                self.smass_[i] = self.smole_[i]/self.mw_[i];
            } 
            self.s_update_ = true;
        }
    }

    fn binary_diffusion_(&mut self){
        if !self.diff_update_{
            let mut polarn: f64;
            let mut dipolep: f64;
            let mut chi: f64;
            let mut ljpotentialmix: f64;
            let mut ljdiametermix: f64;
            let mut dipolemix: f64;

            for i in 0..self.nc_ as usize {
                let idx: usize = self.transport_index_[i];
                for j in i..self.nc_ as usize {
                    let jdx: usize = self.transport_index_[j];
                    let mw_mix: f64 = self.mw_[i]*self.mw_[j]/(self.mw_[i] + self.mw_[j]);

                    if self.transport_[idx].polar == 0.0 && self.transport_[jdx].polar == 0.0 {
                        ljpotentialmix = (self.transport_[idx].ljpotential*self.transport_[jdx].ljpotential).sqrt();
                        ljdiametermix  = 0.5*(self.transport_[idx].ljdiameter + self.transport_[jdx].ljdiameter);
                        dipolemix      = (self.transport_[idx].dipole*self.transport_[jdx].dipole).sqrt();
                    }
                    else if self.transport_[idx].polar > 0.0 && self.transport_[jdx].polar > 0.0 {
                        ljpotentialmix = (self.transport_[idx].ljpotential*self.transport_[jdx].ljpotential).sqrt();
                        ljdiametermix  = 0.5*(self.transport_[idx].ljdiameter + self.transport_[jdx].ljdiameter);
                        dipolemix      = (self.transport_[idx].dipole*self.transport_[jdx].dipole).sqrt();
                    }
                    else {                       
                        if self.transport_[idx].polar == 0.0 {
                            polarn  = self.transport_[idx].polar/self.transport_[idx].ljdiameter.powi(3);
                            dipolep = 1e02*self.transport_[jdx].dipole;
                            dipolep = dipolep/(self.transport_[jdx].ljpotential*1.3806488*self.transport_[jdx].ljdiameter.powi(3)).sqrt();
                            chi     = 0.25*polarn*dipolep;
                            chi     = chi*(self.transport_[jdx].ljpotential/self.transport_[idx].ljpotential).sqrt();
                            chi     = 1. + chi ;
                        }
                        else {
                            polarn  = self.transport_[jdx].polar/self.transport_[jdx].ljdiameter.powi(3);
                            dipolep = 1e02*self.transport_[idx].dipole;
                            dipolep = dipolep/(self.transport_[idx].ljpotential*1.3806488*self.transport_[idx].ljdiameter.powi(3)).sqrt();
                            chi     = 0.25*polarn*dipolep;
                            chi     = chi*(self.transport_[idx].ljpotential/self.transport_[jdx].ljpotential).sqrt();
                            chi     = 1. + chi;
                        }

                        ljpotentialmix = chi.powi(2) * (self.transport_[idx].ljpotential * self.transport_[jdx].ljpotential).sqrt();
                        ljdiametermix = 0.5 * (self.transport_[idx].ljdiameter + self.transport_[jdx].ljdiameter) * chi.powf(-1. / 6.);
                        dipolemix = 0.;

                    }

                    let tr: f64 = self.t_/ljpotentialmix;
                    let dr: f64 = 1e06*0.5*dipolemix.powi(2)/(ljpotentialmix*1.3806488*ljpotentialmix.powi(3));
                    let sigma: f64 = self.collision_integrals_11(tr,dr);
                    let diff: f64 = 0.1*(3./16.)*(2.*std::f64::consts::PI*(1.3806488*self.t_).powi(3)/(mw_mix*1.66054)).sqrt()/(self.p_*std::f64::consts::PI*ljdiametermix.powi(2)*sigma);
                    self.diff_[i][j] = diff;
                    self.diff_[j][i] = diff;                
                }
            }
            self.diff_update_ = true;
        }
    }

    fn species_thermal_conductivity_(&mut self){
        if !self.cond_update_{
            let mut a: f64;
            let mut b: f64;
            let mut zrot: f64;
            let mut cvtrans: f64;
            let mut cvrot: f64;
            let mut cvvib: f64;
            let mut ftrans: f64;
            let mut frot: f64;
            let mut fvib: f64;
            let mut f_t: f64;
            let mut f_298: f64;
            let mut rho: f64;
            let mut diff: f64;
            let mut mu: f64;

            let r: f64 = 8314.0; //[J/kmol/K]

            self.species_viscosity_();
            self.binary_diffusion_();
            self.density_();
            self.species_cp_();
            for i in 0..self.nc_ as usize {
                let idx: usize = self.transport_index_[i];
                if self.transport_[idx].geometry == 0 {
                    cvtrans = 3.*r*0.5;
                    cvrot   = 0.;
                    cvvib   = 0.;
                }
                else if self.transport_[idx]. geometry == 1 {
                    cvtrans = 3.*r*0.5;
                    cvrot   = r;
                    cvvib   = self.cpmole_[i] - r - 5.*r*0.5;
                }
                else
                {
                    cvtrans = 3.*r*0.5;
                    cvrot   = 3.*r*0.5;
                    cvvib   = self.cpmole_[i] - r - 3.*r;
                }

                rho  = self.p_*self.mw_[i]/(r*self.t_);
                diff = self.diff_[i][i];
                mu = self.mu_[i];

                a = (5./2.) - rho*diff/mu;

                f_t = 1. + 0.5*(std::f64::consts::PI.powi(3)*self.transport_[idx].ljpotential/self.t_).sqrt() + (0.25*std::f64::consts::PI.powi(2) + 2.)*(self.transport_[idx].ljpotential/self.t_) + (std::f64::consts::PI*self.transport_[idx].ljpotential/self.t_).powi(3).sqrt();
                f_298 = 1. + 0.5*(std::f64::consts::PI.powi(3)*self.transport_[idx].ljpotential/298.0).sqrt() + (0.25*std::f64::consts::PI.powi(2) + 2.)*(self.transport_[idx].ljpotential/298.0) + (std::f64::consts::PI*self.transport_[idx].ljpotential/298.0).powi(3).sqrt();

                zrot = self.transport_[idx].collision*f_298/f_t;
                
                b = zrot + (2./std::f64::consts::PI)*((5./3.)*(cvrot/r) + rho*diff/mu);

                ftrans = (5./2.)*(1. - 2.*cvrot*a/(std::f64::consts::PI*cvtrans*b));
                frot   = (rho*diff/mu)*(1. + 2.*a/(std::f64::consts::PI*b));
                fvib   = rho*diff/mu;
                
                self.cond_[i] = mu*(ftrans*cvtrans + frot*cvrot + fvib*cvvib)/self.mw_[i];
            }       
            self.cond_update_;
        }
    }

    fn extract_index_from_vector(&mut self, vector: Vec<f64>, v: f64) -> (usize, usize){   
        let mut ia: usize;
        let mut ib: usize;
        ia = usize::MAX;
        ib = usize::MAX;
        for j in 0..vector.len()-1 as usize {
            if v >= vector[j] && v < vector[j+1] {
                ia = j;
                ib = j+1;
                break;
            }

        }
        if ia == usize::MAX{
            if v <= vector[0]{
                ia = 0;
                ib = 1
            }
            else if v >= vector[vector.len()-1]{
                ia = vector.len()-2;
                ib = vector.len()-1;
            }
        }
        (ia, ib)
    }

    fn collision_integrals_22(&mut self, tr: f64, dr: f64)->f64{
        let ta: usize;
        let tb: usize;
        let da: usize;
        let db: usize;
        let mut x: [f64;4] = [0.0,0.0,0.0,0.0];
        let mut b: [f64;4] = [0.0,0.0,0.0,0.0];

        (ta, tb) = self.extract_index_from_vector((&self.omega22_.t).to_vec(), tr);
        (da, db) = self.extract_index_from_vector((&self.omega22_.d).to_vec(), dr);

        b[0] = self.omega22_.sigma[ta][da];
        b[1] = self.omega22_.sigma[ta][db];
        b[2] = self.omega22_.sigma[tb][da];
        b[3] = self.omega22_.sigma[tb][db];

        x[3] = (b[0] - b[1]- b[2] + b[3])/(self.omega22_.t[ta]*self.omega22_.d[da] - self.omega22_.t[ta]*self.omega22_.d[db] - self.omega22_.t[tb]*self.omega22_.d[da] + self.omega22_.t[tb]*self.omega22_.d[db]);
    
        x[2] = (-x[3]*(self.omega22_.t[ta]*self.omega22_.d[da] - self.omega22_.t[ta]*self.omega22_.d[db]) - b[1] + b[0])/(self.omega22_.d[da] - self.omega22_.d[db]);
    
        x[1] = (-x[3]*(self.omega22_.t[ta]*self.omega22_.d[da] - self.omega22_.t[tb]*self.omega22_.d[da]) - b[2] + b[0])/(self.omega22_.t[ta] - self.omega22_.t[tb]);
        
        x[0] = -x[1]*self.omega22_.t[ta] - x[2]*self.omega22_.d[da] - x[3]*self.omega22_.t[ta]*self.omega22_.d[da] + b[0];
    
        x[0] + x[1]*tr + x[2]*dr + x[3]*tr*dr
    }

    fn collision_integrals_11(&mut self, tr: f64, dr: f64)->f64{
        let ta: usize;
        let tb: usize;
        let da: usize;
        let db: usize;
        let mut x: [f64;4] = [0.0,0.0,0.0,0.0];
        let mut b: [f64;4] = [0.0,0.0,0.0,0.0];

        (ta, tb) = self.extract_index_from_vector((&self.omega11_.t).to_vec(), tr);
        (da, db) = self.extract_index_from_vector((&self.omega11_.d).to_vec(), dr);

        b[0] = self.omega11_.sigma[ta][da];
        b[1] = self.omega11_.sigma[ta][db];
        b[2] = self.omega11_.sigma[tb][da];
        b[3] = self.omega11_.sigma[tb][db];

        x[3] = (b[0] - b[1]- b[2] + b[3])/(self.omega11_.t[ta]*self.omega11_.d[da] - self.omega11_.t[ta]*self.omega11_.d[db] - self.omega11_.t[tb]*self.omega11_.d[da] + self.omega11_.t[tb]*self.omega11_.d[db]);
    
        x[2] = (-x[3]*(self.omega11_.t[ta]*self.omega11_.d[da] - self.omega11_.t[ta]*self.omega11_.d[db]) - b[1] + b[0])/(self.omega11_.d[da] - self.omega11_.d[db]);
    
        x[1] = (-x[3]*(self.omega11_.t[ta]*self.omega11_.d[da] - self.omega11_.t[tb]*self.omega11_.d[da]) - b[2] + b[0])/(self.omega11_.t[ta] - self.omega11_.t[tb]);
        
        x[0] = -x[1]*self.omega11_.t[ta] - x[2]*self.omega11_.d[da] - x[3]*self.omega11_.t[ta]*self.omega11_.d[da] + b[0];
    
        x[0] + x[1]*tr + x[2]*dr + x[3]*tr*dr
    }

    fn estimate_mixture_property(&mut self, property_vector: Vec<f64>, composition_vector: Vec<f64>) -> f64 {
        let mut mixture_property: f64 = 0.0;
        for i in 0..self.nc_ as usize {
            mixture_property = mixture_property + composition_vector[i]*property_vector[i];
        }
        mixture_property
    }

}

