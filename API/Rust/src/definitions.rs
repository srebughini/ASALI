mod definitions {
    #[derive(Default)]
    pub struct Transport {
        nome: String,
        geometry: f32,
        ljpotential: f32,
        ljdiameter: f32,
        dipole: f32,
        polar: f32,
        collision: f32,
        mw: f32,
    }

    #[derive(Default)]
    pub struct Thermo {
        nome: String,
        high: [f32; 7],
        low: [f32; 7],
    }

    #[derive(Default)]
    pub struct Definitions {
        pub transport_: [Transport; 483],
        pub thermo_: [Thermo; 483],
        pub dsigma22_: [f32; 8],
        pub tsigma22_: [f32; 37],
        pub sigmaMatrix22_: [[f32; 8]; 37],
        pub dsigma11_: [f32; 8],
        pub tsigma11_: [f32; 37],
        pub sigmaMatrix11_: [[f32; 8]; 37],
    }
}

