from enum import Enum


class RegressionPlotConfig(Enum):
    """
    Class to handle linear regression plotting output page configurations
    """
    TEMPERATURE_LABEL = "Temperature [{}]"

    GENERIC_LINEAR = r"{} = {:.3e}*T + {:.3e}"
    GENERIC_POWER_LAW = r"{} = {:.3e}*T^{:.3e}"
    GENERIC_LOGARITHMIC = r"{} = {:.3e}ln(T) + {:.3e}"
    GENERIC_ERROR = "NOT AVAILABLE"

    RHO_LABEL = "Density [{}]"
    RHO_SYMBOL = r"$\rho$"

    MU_LABEL = "Viscosity [{}]"
    MU_SYMBOL = r"$\mu$"

    COND_LABEL = "Thermal conductivity [{}]"
    COND_SYMBOL = r"$\lambda$"

    CP_LABEL = "Specific heat [{}]"
    CP_SYMBOL = "cp"

    H_LABEL = "Enthalpy [{}]"
    H_SYMBOL = "h"

    S_LABEL = "Entropy [{}]"
    S_SYMBOL = "s"

    AXES_COLOR = "#272C26"
    BACKGROUND_COLOR = "none"
    ADD_AXES_ARG = [0.1, 0.1, 0.8, 0.8]
    SET_POSITION_ARG = [0.15, 0.15, 0.7, 0.7]
    MARGIN = (10, 10, 10, 10)  # Left, Top, Right, Bottom margins
    SOLID_LINE_COLOR = "#67908B"
    DOT_LINE_COLOR = "#E9963D"
    DOT_SHAPE = '--'
    LEGEND_POSITION = "best"
    LEGEND_FRAME = False
    LEGEND_COLOR = "#272C26"
    LEGEND = ["Cantera Model", "Regression"]