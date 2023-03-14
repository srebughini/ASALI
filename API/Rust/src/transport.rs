use crate::definitions::Definitions;

pub fn transport_update(module: &mut Definitions) {
    module.transport_[0].nome = "H2".to_string();
}
