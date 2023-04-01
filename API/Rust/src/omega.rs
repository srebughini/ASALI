use crate::definitions::Omega;

pub fn omega_update(omega: &mut Vec<Omega>) {
    let o = Omega {
        d: [0.0; 8],
        t: [0.0; 37],
        sigma: [[0.0; 8]; 37]
    };
    omega.push(o);
}
