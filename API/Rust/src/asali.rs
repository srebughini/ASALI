use crate::omega::omega_update;
use crate::thermo::thermo_update;
use crate::transport::transport_update;

use crate::definitions::Transport;
use crate::definitions::Thermo;
use crate::definitions::Omega;


pub struct Asali {
    T_: f64,
    P_: f64,
    MWmix_: f64,
    rho_: f64,
    mu_mix_: f64,
    cond_mix_: f64,
    cpmole_mix_: f64,
    cpmass_mix_: f64,
    hmole_mix_: f64,
    hmass_mix_: f64,
    smole_mix_: f64,
    smass_mix_: f64,
    MW_: Vec<f64>,
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
    NC_: i32,
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
    omega_: Vec<Omega>
}

impl Asali{
    pub fn new() -> Asali {
        let mut transport = Vec::<Transport>::new();
        transport_update(&mut transport);

        let mut thermo = Vec::<Thermo>::new();
        thermo_update(&mut thermo);

        let mut omega = Vec::<Omega>::new();
        omega_update(&mut omega);

        Asali {
            T_: 0.0,
            P_: 0.0,
            MWmix_: 0.0,
            rho_: 0.0,
            mu_mix_: 0.0,
            cond_mix_: 0.0,
            cpmole_mix_: 0.0,
            cpmass_mix_: 0.0,
            hmole_mix_: 0.0,
            hmass_mix_: 0.0,
            smole_mix_: 0.0,
            smass_mix_: 0.0,
            MW::_: Vec::<f64>::new(),
            x_: Vec::<f64>::new(),
            y_: Vec::<f64>::new(),
            mu_: Vec::<f64>::new(),
            diff_: Vec<Vec<::f64>>::new(),
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
            NC_: 0,
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
            omega_: omega
        }
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

    pub fn get_temperature(&self) -> f64 {
        self.T_
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

    pub fn get_pressure(&self) -> f64 {
        self.P_
    }

    pub fn set_number_of_species(&mut self, NC: i32) {
        if NC != self.NC_ {
            self.NC_ = NC;
            self.resize(NC);
        }
    }

    pub fn get_number_of_species(&self) -> i32 {
        self.NC_;
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
        self.index_.resize(NC as usize, usize::MAX);
        self.name_.resize(NC as usize, String::new());
        self.v_.resize(NC as usize, 0.0);
        self.l_.resize(NC as usize, 0.0);
        self.NC_ = NC;
    }

    fn reset_bool(&mu self) {
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




        /*
        pub fn set_species_names(&mut self, names: &[&str]) {
            if names.iter().all(|&name| !self.name_.contains(&name.to_string())) {
                if names.len() == self.NC_ as usize{
                    for j in 0..self.NC_ as uszie {
                        self.index_[j] = usize::MAX;
                        self.name_[j] = names[j].to_string();
                        for i in 0..self.definitions_.transport_.len() {
                            if self.name_[j].trim() == self.definitions_.transport_[i].name.trim() {
                                self.index_[j] = i;
                                self.MW_[j] = self.definitions_.transport_[i].MW;
                                break;
                            }
                        }
                        if self.index_[j] == usize::MAX {
                            let error = format!("ASALI::ERROR-->{} is missing in ASALI database.", self.name_[j]);
                            println!(error);
                            exit(-1);
                        }
                    }
                } else {
                    println!("ASALI::ERROR-->Wrong number of species names");
                    exit(-1);
                }
                self.reset_bool();
            }
        }

        pub fn set_mass_fraction(&mut self, y: &[f64]) {
            if self.y_ != y {
                self.y_ = y.to_owned();
                if self.y_.len() == self.NC_ as usize {
                    self.MWmix_ = 0.0;
                    for i in 0..self.NC_ as usize {
                        self.MWmix_ += self.y_[i] / self.MW_[i];
                    }
        
                    for i in 0..self.NC_ as usize {
                        self.x_[i] = (self.y_[i] / self.MW_[i]) / self.MWmix_;
                    }
        
                    self.MWmix_ = 1.0 / self.MWmix_;
                } else {
                    println!("ASALI::ERROR-->Wrong number of mass fractions");
                    exit(-1);
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
                if x.len() == self.NC_ as usize {
                    self.MWmix_ = 0.;
                    for i in 0..self.NC_ as usize {
                        self.MWmix_ += self.x_[i] * self.MW_[i];
                    }
    
                    for i in 0..self.NC_ as usize {
                        self.y_[i] = self.x_[i] * self.MW_[i] / self.MWmix_;
                    }
                } else {
                    println!("ASALI::ERROR-->Wrong number of mole fractions");
                    exit(-1);
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
                for i in 0..self.NC_ as usize {
                    Tr = self.T_ / self.definitions_.transport_[self.index_[i]].ljpotential;
                    dr = 0.5 * self.definitions_.transport_[self.index_[i]].dipole.powi(2);
                    dr = dr / (self.definitions_.transport_[self.index_[i]].ljpotential * 1.3806488 *
                                self.definitions_.transport_[self.index_[i]].ljdiameter.powi(3));
                    dr = 1e06 * dr;
                    sigma = self.collision_integrals_22(Tr, dr);
                    self.mu_[i] = (5. / 16.) * (std::f64::consts::PI * 1.3806488 * self.T_ *
                                    self.MW_[i] * 1.66054).sqrt() /
                                    (std::f64::consts::PI * sigma * self.definitions_.transport_[self.index_[i]].ljdiameter.powi(2));
                    self.mu_[i] = self.mu_[i] * 1.0e-05;
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

        pub fn get_mixture_molecular_weight(&self) -> f64 {
            self.MWmix_
        }

        pub fn collision_integrals_22(&mut self, Tr, Dr) -> f64 {
            0.0
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
            self.index_.resize(NC as usize, usize::MAX);
            self.name_.resize(NC as usize, String::new());
            self.v_.resize(NC as usize, 0.0);
            self.l_.resize(NC as usize, 0.0);
            self.NC_ = NC;
        }
    }*/
