use crate::definitions::Transport;

pub fn transport_update(transport: &mut Vec<Transport>) {
    let t = Transport {
        name: "H2".to_string(),
        geometry: 0.0,
        ljpotential: 0.0,
        ljdiameter: 0.0,
        dipole: 0.0,
        polar: 0.0,
        collision: 0.0,
        mw: 0.0
    };
    transport.push(t);
}
