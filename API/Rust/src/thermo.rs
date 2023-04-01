use crate::definitions::Thermo;

pub fn thermo_update(thermo: &mut Vec<Thermo>) {
    let t = Thermo{
        name: "H2".to_string(),
        high: [0.0; 7],
        low:  [0.0; 7]
    };
    thermo.push(t);
}
