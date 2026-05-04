from enum import Enum


class EquilibriumType(Enum):
    """
    Enum describing the equilibrium type
    """
    TP = "Fixed temperature and pressure"
    HP = "Fixed specific enthalpy and pressure"
    UV = "Fixed specific internal energy and specific volume"
    SV = "Fixed specific entropy and specific volume"
    SP = "Fixed specific entropy and pressure"
