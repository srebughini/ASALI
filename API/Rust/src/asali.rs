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
    index_: Vec<usize>,
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
            index_: Vec::<usize>::new(),
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
                self.index_[j] = usize::MAX;
                self.name_[j] = names[j].to_string();
                for i in 0..self.transport_.len() as usize {
                    if self.name_[j].trim() == self.transport_[i].name.trim() {
                        self.index_[j] = i;
                        self.mw_[j] = self.transport_[i].mw;
                        break;
                    }
                }
                if self.index_[j] == usize::MAX {
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
        self.cp_mole_.clone()
    }
    
    pub fn get_species_mass_specific_heat(&mut self) -> Vec<f64> {
        self.species_cp_();
        self.cp_mass_.clone()
    }


    pub fn get_species_molar_enthalpy(&mut self) -> Vec<f64> {
        self.species_h_();
        self.h_mole_.clone()
    }

    pub fn get_species_mass_enthalpy(&mut self) -> Vec<f64> {
        self.species_h_();
        self.h_mass_.clone()
    }


    pub fn get_species_molar_entropy(&mut self) -> Vec<f64> {
        self.species_s_();
        self.s_mole_.clone()
    }

    pub fn get_species_mass_entropy(&mut self) -> Vec<f64> {
        self.species_s_();
        self.s_mass_.clone()
    }

    pub fn get_species_thermal_conductivity(&mut self) -> Vec<f64> {
        self.species_thermal_conductivity_();
        self.cond_.clone()
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
        self.index_.resize(nc as usize, usize::MAX);
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
                tr = self.t_ / self.transport_[self.index_[i]].ljpotential;
                dr = 0.5 * self.transport_[self.index_[i]].dipole.powi(2);
                dr = dr / (self.transport_[self.index_[i]].ljpotential * 1.3806488 * self.transport_[self.index_[i]].ljdiameter.powi(3));
                dr = 1e06 * dr;
                sigma = self.collision_integrals_22(tr, dr);
                self.mu_[i] = (5. / 16.) * (std::f64::consts::PI * 1.3806488 * self.t_ * self.mw_[i] * 1.66054).sqrt() / (std::f64::consts::PI * sigma * self.transport_[self.index_[i]].ljdiameter.powi(2));
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
                if self.t_ < 1000 {
                    self.cp_mole_[i] = self.thermo_[self.index_[i]].low[0] + self.thermo_[self.index_[i]].low[1]*self.t_ + self.thermo_[self.index_[i]].low[2]*self.t_.powi(2) + self.thermo_[self.index_[i]].low[3]*self.t_.powi(3) + self.thermo_[self.index_[i]].low[4]*self.t_.powi(4);
                }
                else {
                    self.cp_mole_[i] = self.thermo_[self.index_[i]].high[0] + self.thermo_[self.index_[i]].high[1]*self.t_ + self.thermo_[self.index_[i]].high[2]*self.t_.powi(2) + self.thermo_[self.index_[i]].high[3]*self.t_.powi(3) + self.thermo_[self.index_[i]].high[4]*self.t_.powi(4);
                }
                self.cp_mole_[i] = self.cp_mole_[i]*8.314;
                self.cp_mass_[i] = self.cp_mole_[i]/self.mw_[i];
            } 
            self.cp_update_ = true;
        }
    }

    fn species_h_(&mut self){
        if !self.h_update_{
            for i in 0..self.nc_ as usize {
                if self.t_ < 1000 {
                    self.h_mole_[i] = self.thermo_[self.index_[i]].low[0] + self.thermo_[self.index_[i]].low[1]*self.t_/2. + self.thermo_[self.index_[i]].low[2]*self.t_.powi(2)/3. + self.thermo_[self.index_[i]].low[3]*self.t_.powi(3)/4. + self.thermo_[self.index_[i]].low[4]*self.t_.powi(4)/5. + self.thermo_[self.index_[i]].low[5]/self.t_;
                }
                else {
                    self.h_mole_[i] = self.thermo_[self.index_[i]].high[0] + self.thermo_[self.index_[i]].high[1]*self.t_/2. + self.thermo_[self.index_[i]].high[2]*self.t_.powi(2)/3. + self.thermo_[self.index_[i]].high[3]*self.t_.powi(3)/4. + self.thermo_[self.index_[i]].high[4]*self.t_.powi(4)/5. + self.thermo_[self.index_[i]].high[5]/self.t_;
                }
                self.h_mole_[i] = self.h_mole_[i]*8.314*self.t_;
                self.h_mass_[i] = self.h_mole_[i]/self.mw_[i];
            } 
            self.h_update_ = true;
        }
    }

    fn species_s_(&mut self){
        if !self.s_update_{
            let mut v: f64;
            for i in 0..self.nc_ as usize {
                if self.t_ < 1000 {
                    self.s_mole_[i] = self.thermo_[self.index_[i]].low[0]*self.t_.log() + self.thermo_[self.index_[i]].low[1]*self.t_ + self.thermo_[self.index_[i]].low[2]*self.t_.powi(2)/2. + self.thermo_[self.index_[i]].low[3]*self.t_.powi(3)/3. + self.thermo_[self.index_[i]].low[4]*self.t_.powi(4)/4. + self.thermo_[self.index_[i]].low[6];
                }
                else {
                    self.s_mole_[i] = self.thermo_[self.index_[i]].high[0]*self.t_.log() + self.thermo_[self.index_[i]].high[1]*self.t_ + self.thermo_[self.index_[i]].high[2]*self.t_.powi(2)/2. + self.thermo_[self.index_[i]].high[3]*self.t_.powi(3)/3. + self.thermo_[self.index_[i]].high[4]*self.t_.powi(4)/4. + self.thermo_[self.index_[i]].high[6];
                }
                v = self.p_*self.x_[i]/1.0e05;
                self.s_mole_[i] = 8314.*(self.s_mole_[i] - v.log());
                self.s_mass_[i] = self.s_mole_[i]/self.mw_[i];
            } 
            self.s_update_ = true;
        }
    }

    fn binary_diffusion_(&mut self){
        //TODO
    }

    fn species_thermal_conductivity_(&mut self){
        if !self.cond_update_{
            let mut a: f64 = 0.0;
            let mut b: f64 = 0.0;
            let mut zrot: f64 = 0.0;
            let mut cvtrans: f64 = 0.0;
            let mut cvrot: f64 = 0.0;
            let mut cvvib: f64 = 0.0;
            let mut ftrans: f64 = 0.0;
            let mut frot: f64 = 0.0;
            let mut fvib: f64 = 0.0;
            let mut r: f64 = 8314.0; //[J/kmol/K]
            let mut f_t: f64 = 0.0;
            let mut f_298: f64 = 0.0;
            let mut rho: f64 = 0.0;
            let mut diff: f64 = 0.0;
            let mut mu: f64 = 0.0;

            self.species_viscosity_();
            self.binary_diffusion_();
            self.density_();
            self.species_cp_();
            for i in 0..self.nc_ as usize {
                let mut idx: usize = self.index_[i];
                if self.transport_[idx].geometry == 0 {
                    cvtrans = 3.*r*0.5;
                    cvrot   = 0.;
                    cvvib   = 0.;
                }
                else if self.transport_[idx]. geometry == 1 {
                    cvtrans = 3.*r*0.5;
                    cvrot   = r;
                    cvvib   = self.cp_mole_[i] - r - 5.*r*0.5;
                }
                else
                {
                    cvtrans = 3.*r*0.5;
                    cvrot   = 3.*r*0.5;
                    cvvib   = self.cp_mole_[i] - r - 3.*r;
                }

                rho  = self.p_*self.mw_[i]/(r*self.t_);
                diff = self.diff_[i][i];
                mu = self.mu_[i];

                a = (5./2.) - rho*diff/mu;

                f_t = 1. + 0.5*(std::f64::consts::PI.powi(3)*self.transport_[idx].ljpotential/self.t_).sqrt() + (0.25*std::f64::consts::PI.powi(2) + 2.)*(self.transport_[idx].ljpotential/self.t_) + (self.pi_*self.transport_[idx].ljpotential/self.t_).powi(3).sqrt();
                f_298 = 1. + 0.5*(std::f64::consts::PI.powi(3)*self.transport_[idx].ljpotential/298.0).sqrt() + (0.25*std::f64::consts::PI.powi(2) + 2.)*(self.transport_[idx].ljpotential/298.0) + (self.pi_*self.transport_[idx].ljpotential/298.0).powi(3).sqrt();

                zrot = self.transport_[idx].collision*f_298/f_t;
                
                b = zrot + (2./std::f64::consts::PI)*((5./3.)*(cvrot/r) + rho*diff/mu);

                ftrans = (5./2.)*(1. - 2.*cvrot*a/(std::f64::consts::PI*cvtrans*b));
                frot   = (rho*diff/mu)*(1. + 2.*a/(std::f64::consts::PI*b));
                fvib   = rho*diff/mu;
                
                self.cond[i] = mu*(ftrans*cvtrans + frot*cvrot + fvib*cvvib)/self.mw_[i];
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
}

