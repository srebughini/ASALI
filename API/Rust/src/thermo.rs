use crate::definitions::Definitions;

pub fn thermo_update(module: &mut Definitions) {
    module.thermo_[0].nome = "H2".to_string();
}
