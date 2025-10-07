from enum import Enum


class Properties(Enum):
    """
    Enum describing the properties
    """
    DENSITY = "Density"
    VISCOSITY = "Viscosity"
    THERMAL_CONDUCTIVITY = "Thermal conductivity"
    SPECIFIC_HEAT = "Specific heat"
    ENTHALPY = "Enthalpy"
    ENTROPY = "Entropy"
