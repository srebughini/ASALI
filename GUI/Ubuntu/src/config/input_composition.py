from enum import Enum


class InputCompositionConfig(Enum):
    """
    Class to handle the input composition generic configuration
    """
    GAS_SPECIE_LABEL_NAME = "Specie #{:d}"
    GAS_SPECIE_COMBO_BOX_NAME = "n{:d}"
    GAS_SPECIE_EDIT_LINE_NAME = "x{:d}"
    SURFACE_SPECIE_LABEL_NAME = "Coverage #{:d}"
    SURFACE_SPECIE_COMBO_BOX_NAME = "nc{:d}"
    SURFACE_SPECIE_EDIT_LINE_NAME = "z{:d}"
