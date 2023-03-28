mod definitions {
    #[derive(Debug, Clone)]
    pub struct Transport {
        nome: String,
        geometry: f32,
        ljpotential: f32,
        ljdiameter: f32,
        dipole: f32,
        polar: f32,
        collision: f32,
        mw: f32
    }

    impl Default for Transport {
        fn default() -> Self {
            Transport {
                nome: String::new(),
                geometry: 0.0,
                ljpotential: 0.0,
                ljdiameter: 0.0,
                dipole: 0.0,
                polar: 0.0,
                collision: 0.0,
                mw: 0.0
            }
        }
    }

    #[derive(Debug, Clone)]
    pub struct Thermo {
        nome: String,
        high: [f32; 7],
        low: [f32; 7],
    }


    impl Default for Thermo {
        fn default() -> Self {
            Thermo {
                nome: String::new(),
                high: [0.0; 7],
                low: [0.0; 7]
            }
        }
    }

    #[derive(Debug, Clone)]
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

    impl Default for Definitions {
        fn default() -> Self {
            Definitions {
                transport_: [Transport::default(); 483],
                thermo_: [Thermo::default(); 483],
                dsigma22_: [0.0; 8],
                tsigma22_: [0.0; 37],
                sigmaMatrix22_: [[0.0; 8]; 37],
                dsigma11_: [0.0; 8],
                tsigma11_: [0.0; 37],
                sigmaMatrix11_: [[0.0; 8]; 37],
            }
        }
    }
}
