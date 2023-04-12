pub struct Transport {
    pub name: String,
    pub geometry: f64,
    pub ljpotential: f64,
    pub ljdiameter: f64,
    pub dipole: f64,
    pub polar: f64,
    pub collision: f64,
    pub mw: f64
}

pub struct Thermo {
    pub name: String,
    pub high: [f64; 7],
    pub low: [f64; 7],
}

pub struct Omega {
    pub d: [f64; 8],
    pub t: [f64; 37],
    pub sigma: [[f64; 8]; 37],
}