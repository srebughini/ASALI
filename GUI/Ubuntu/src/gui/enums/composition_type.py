from enum import Enum


class CompositionType(Enum):
    """
    Enum describing the composition type
    """
    MASS = "mass_fraction"
    MOLE = "mole_fraction"
