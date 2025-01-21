from enum import Enum


class RegressionOutputPageWidgets(Enum):
    """
    Class to handle linear regression output page components names
    """
    MATH_LABEL = "mathLabel"

    TEMPERATURE_COMBO_BOX = "temperatureComboBox"
    REGRESSION_COMBO_BOX = "regressionComboBox"

    DENSITY_A_LABEL = "rhoALabel"
    DENSITY_B_LABEL = "rhoBLabel"
    DENSITY_COMBO_BOX = "rhoComboBox"

    VISCOSITY_A_LABEL = "muALabel"
    VISCOSITY_B_LABEL = "muBLabel"
    VISCOSITY_COMBO_BOX = "muComboBox"

    THERMAL_CONDUCTIVITY_A_LABEL = "condALabel"
    THERMAL_CONDUCTIVITY_B_LABEL = "condBLabel"
    THERMAL_CONDUCTIVITY_COMBO_BOX = "condComboBox"

    ENTHALPY_A_LABEL = "hALabel"
    ENTHALPY_B_LABEL = "hBLabel"
    ENTHALPY_COMBO_BOX = "hComboBox"

    ENTROPY_A_LABEL = "sALabel"
    ENTROPY_B_LABEL = "sBLabel"
    ENTROPY_COMBO_BOX = "sComboBox"

    SPECIFIC_HEAT_A_LABEL = "cpALabel"
    SPECIFIC_HEAT_B_LABEL = "cpBLabel"
    SPECIFIC_HEAT_COMBO_BOX = "cpComboBox"

    MIN_TEMPERATURE_EDIT_LINE = "minTemperatureEditLine"
    MAX_TEMPERATURE_EDIT_LINE = "maxTemperatureEditLine"

    BACK_BUTTON = "backButton"
    CALCULATE_BUTTON = "calculateButton"
    PLOT_BUTTON = "plotButton"
