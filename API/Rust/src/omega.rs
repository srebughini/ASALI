use crate::definitions::Definitions;

pub fn omega_update(module: &mut Definitions) {
    module.dsigma22_[0] = 1.0;
}
