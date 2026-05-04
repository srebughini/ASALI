from enum import Enum


class RegressionMethod(Enum):
    """
    Enum describing the regression method
    """
    LINEAR = "Linear"
    POWER_LAW = "Power Law"
    LOGARITHMIC = "Logarithmic"
