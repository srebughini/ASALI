mod definitions;

use definitions::Definitions;
use crate::omega::omega_update;
use crate::thermo::thermo_update;
use crate::transport::transport_update;

mod asali {
    pub struct Asali {
        pub(crate) T_: f64,
        pub(crate) P_: f64,
        pub(crate) MWmix_: f64,
        pub(crate) rho_: f64,
        pub(crate) mu_mix_: f64,
        pub(crate) cond_mix_: f64,
        pub(crate) cpmole_mix_: f64,
        pub(crate) cpmass_mix_: f64,
        pub(crate) hmole_mix_: f64,
        pub(crate) hmass_mix_: f64,
        pub(crate) smole_mix_: f64,
        pub(crate) smass_mix_: f64,
        pub(crate) pi_: f64,
        pub(crate) MW_: Vec<f64>,
        pub(crate) x_: Vec<f64>,
        pub(crate) y_: Vec<f64>,
        pub(crate) mu_: Vec<f64>,
        pub(crate) diff_: Vec<Vec<f64>>,
        pub(crate) cpmole_: Vec<f64>,
        pub(crate) cpmass_: Vec<f64>,
        pub(crate) hmole_: Vec<f64>,
        pub(crate) hmass_: Vec<f64>,
        pub(crate) smole_: Vec<f64>,
        pub(crate) smass_: Vec<f64>,
        pub(crate) cond_: Vec<f64>,
        pub(crate) diff_mix_: Vec<f64>,
        pub(crate) v_: Vec<f64>,
        pub(crate) l_: Vec<f64>,
        pub(crate) NC_: i32,
        pub(crate) index_: Vec<i32>,
        pub(crate) name_: Vec<String>,
        pub(crate) error_: String,
        pub(crate) mu_update_: bool,
        pub(crate) diff_update_: bool,
        pub(crate) rho_update_: bool,
        pub(crate) cp_update_: bool,
        pub(crate) h_update_: bool,
        pub(crate) s_update_: bool,
        pub(crate) cond_update_: bool,
        pub(crate) v_update_: bool,
        pub(crate) l_update_: bool,
        pub(crate) mu_mix_update_: bool,
        pub(crate) diff_mix_update_: bool,
        pub(crate) cond_mix_update_: bool,
        pub(crate) cpmole_mix_update_: bool,
        pub(crate) cpmass_mix_update_: bool,
        pub(crate) hmole_mix_update_: bool,
        pub(crate) hmass_mix_update_: bool,
        pub(crate) smole_mix_update_: bool,
        pub(crate) definitions_: Definitions,
    }

    impl Asali {
        pub fn new() -> Self {
            let mut definitions = Definitions::default();
            omega_update(&mut definitions);
            transport_update(&mut definitions);
            thermo_update(&mut definitions);
            Self { definitions_: definitions }
        }

        pub fn set_temperature(&mut self, T: f64) {
            if T != self.T_ {
                self.T_ = T;
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

        pub fn set_pressure(&mut self, P: f64) {
            if P != self.P_ {
                self.P_ = P;
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

        pub fn set_number_of_species(&mut self, NC: i32) {
            if NC != self.NC_ {
                self.NC_ = NC;
                self.resize(self.NC_);
                transport_update(self.definitions_);
                thermo_update(self.definitions_);
                omega_update(self.definitions_);
            }
        }

        pub fn set_species_names(&mut self, names: &[&str]) {
            if names.iter().all(|&name| !self.name_.contains(&name.to_string())) {
                if names.len() == self.NC_ {
                    for j in 0..self.NC_ {
                        self.index_[j] = -1;
                        self.name_[j] = names[j].to_string();
                        for i in 0..self.definitions_.transport_.len() {
                            if self.name_[j].trim() == self.definitions_.transport_[i].name.trim() {
                                self.index_[j] = i;
                                self.MW_[j] = self.definitions_.transport_[i].MW;
                                break;
                            }
                        }
                        if self.index_[j] == -1 {
                            let error = format!("ASALI::ERROR-->{} is missing in ASALI database.", self.name_[j]);
                            println!("{}", error);
                            panic!(error);
                        }
                    }
                } else {
                    println!("ASALI::ERROR-->Wrong number of species names");
                    panic!("ASALI::ERROR-->Wrong number of species names");
                }
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

        pub fn set_mass_fraction(&mut self, y: &[f64]) {
            if self.y_ != y {
                self.y_ = y.to_owned();
                if self.y_.len() == NC_ {
                    self.MWmix_ = 0.0;
                    for i in 0..NC_ {
                        self.MWmix_ += self.y_[i] / self.MW_[i];
                    }
        
                    for i in 0..NC_ {
                        self.x_[i] = (self.y_[i] / self.MW_[i]) / self.MWmix_;
                    }
        
                    self.MWmix_ = 1.0 / self.MWmix_;
                } else {
                    panic!("ASALI::ERROR-->Wrong number of mass fractions");
                }
        
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

        pub fn set_mole_fraction(&mut self, x: &[f64]) {
            if x != self.x_ {
                self.x_ = x.to_vec();
                if x.len() == self.NC_ {
                    self.MWmix_ = 0.;
                    for i in 0..self.NC_ {
                        self.MWmix_ += self.x_[i] * self.MW_[i];
                    }
    
                    for i in 0..self.NC_ {
                        self.y_[i] = self.x_[i] * self.MW_[i] / self.MWmix_;
                    }
                } else {
                    println!("ASALI::ERROR-->Wrong number of mole fractions");
                    panic!("Error stop");
                }
                self.mu_update_   = false;
                self.diff_update_ = false;
                self.rho_update_  = false;
                self.cp_update_   = false;
                self.h_update_    = false;
                self.s_update_    = false;
                self.cond_update_ = false;
                self.v_update_    = false;
                self.l_update_    = false;
                self.mu_mix_update_     = false;
                self.diff_mix_update_   = false;
                self.cond_mix_update_   = false;
                self.cpmole_mix_update_ = false;
                self.cpmass_mix_update_ = false;
                self.hmole_mix_update_  = false;
                self.hmass_mix_update_  = false;
                self.smole_mix_update_  = false;
            }
        }

        pub fn get_mass_fraction(&self) -> Vec<f64> {
            self.y_.clone()
        }

        pub fn get_mole_fraction(&self) -> Vec<f64> {
            self.x_.clone()
        }


        fn species_viscosity_(&mut self) {
            let mut Tr: f64;
            let mut dr: f64;
            let mut sigma: f64;
            
            if !self.mu_update_ {
                for i in 0..self.NC_ {
                    Tr = self.T_ / self.definitions_.transport_[self.index_[i]].ljpotential;
                    dr = 0.5 * self.definitions_.transport_[self.index_[i]].dipole.powi(2);
                    dr = dr / (self.definitions_.transport_[self.index_[i]].ljpotential * 1.3806488 *
                                self.definitions_.transport_[self.index_[i]].ljdiameter.powi(3));
                    dr = 1e06 * dr;
                    sigma = self.collision_integrals_22(Tr, dr);
                    self.mu_[i] = (5. / 16.) * (std::f64::consts::PI * 1.3806488 * self.T_ *
                                    self.MW_[i] * 1.66054).sqrt() /
                                    (std::f64::consts::PI * sigma * self.definitions_.transport_[self.index_[i]].ljdiameter.powi(2));
                    self.mu_[i] = self.mu_[i] * 1.e-05;
                }
                self.mu_update_ = true;
            }
        }

        pub fn get_species_viscosity(&mut self) -> Vec<f64> {
            self.species_viscosity_();
            self.mu_.clone()
        }

        fn density_(&mut self) {
            if !self.rho_update_ {
                self.rho_ = self.MWmix_ * self.P_ / (8314. * self.T_);
                self.rho_update_ = true;
            }
        }

        pub fn get_density(&mut self) -> f64 {
            self.density_();
            self.rho_
        }

        fn resize(&mut self, NC: i32) {
            self.x_.resize(NC as usize, 0.0);
            self.y_.resize(NC as usize, 0.0);
            self.mu_.resize(NC as usize, 0.0);
            self.diff_.resize(NC as usize, vec![0.0; NC as usize]);
            self.cpmole_.resize(NC as usize, 0.0);
            self.cpmass_.resize(NC as usize, 0.0);
            self.hmole_.resize(NC as usize, 0.0);
            self.hmass_.resize(NC as usize, 0.0);
            self.smole_.resize(NC as usize, 0.0);
            self.smass_.resize(NC as usize, 0.0);
            self.cond_.resize(NC as usize, 0.0);
            self.diff_mix_.resize(NC as usize, 0.0);
            self.MW_.resize(NC as usize, 0.0);
            self.index_.resize(NC as usize, -1);
            self.name_.resize(NC as usize, String::new());
            self.v_.resize(NC as usize, 0.0);
            self.l_.resize(NC as usize, 0.0);
            self.NC_ = NC;
        }
    }
}

