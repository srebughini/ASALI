pub struct Transport {
    pub name: String,
    pub geometry: f32,
    pub ljpotential: f32,
    pub ljdiameter: f32,
    pub dipole: f32,
    pub polar: f32,
    pub collision: f32,
    pub mw: f32
}

pub struct Thermo {
    pub name: String,
    pub high: [f32; 7],
    pub low: [f32; 7],
}

pub struct Omega {
    pub d: [f32; 8],
    pub t: [f32; 37],
    pub sigma: [[f32; 8]; 37],
}
