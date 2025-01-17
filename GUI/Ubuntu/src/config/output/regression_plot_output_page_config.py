import os
from enum import Enum


class RegressionPlotOutputPageConfig(Enum):
    """
    Class to handle linear regression plotting output page configurations
    """
    PATH = os.path.join("gui", "ui", "output", "regression_plot_output_page.ui")

    NAME = "RegressionPlotOutputPage"
    PLOT_TEMPERATURE_LABEL = "Temperature [{}]"

    PLOT_RHO_LABEL = "Density [{}]"
    PLOT_RHO_LINEAR = r"$\rho$ = {} T + {}"
    PLOT_RHO_POWER_LAW = r"$\rho$ = {} T ^{}"

    PLOT_MU_LABEL = "Viscosity [{}]"
    PLOT_MU_LINEAR = r"$\mu$ = {} T + {}"
    PLOT_MU_POWER_LAW = r"$\mu$ = {} T ^{}"

    PLOT_COND_LABEL = "Thermal conductivity [{}]"
    PLOT_COND_LINEAR = r"$\lambda$ = {} T + {}"
    PLOT_COND_POWER_LAW = r"$\lambda$ = {} T ^{}"

    PLOT_CP_LABEL = "Specific heat [{}]"
    PLOT_CP_LINEAR = "cp = {} T + {}"
    PLOT_CP_POWER_LAW = "cp = {} T ^{}"

    PLOT_H_LABEL = "Enthalpy [{}]"
    PLOT_H_LINEAR = "h = {} T + {}"
    PLOT_H_POWER_LAW = "h = {} T ^{}"

    PLOT_S_LABEL = "Entropy [{}]"
    PLOT_S_LINEAR = "s = {} T + {}"
    PLOT_S_POWER_LAW = "s = {} T ^{}"

    PLOT_AXES_COLOR = "white"
    PLOT_BACKGROUND_COLOR = "none"
    PLOT_ADD_AXES_ARG = [0.1, 0.1, 0.8, 0.8]
    PLOT_SET_POSITION_ARG = [0.15, 0.15, 0.7, 0.7]
    PLOT_SOLID_LINE_COLOR = "#f2e8dc"
    PLOT_DOT_LINE_COLOR = "#DCE6F2"
    PLOT_DOT_SHAPE = '--'
    PLOT_LEGEND_POSITION = "best"
    PLOT_LEGEND_FRAME = False
    PLOT_LEGEND_COLOR = "white"
    PLOT_LEGEND = ["Cantera model", "Linear regression"]


