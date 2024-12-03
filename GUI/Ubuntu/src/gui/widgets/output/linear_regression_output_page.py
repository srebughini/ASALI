from enum import Enum


class LinearRegressionOutputPageWidgets(Enum):
    """
    Class to handle linear regression output page widgets names
    """
    HEADLINE_LABEL = "regressionLabel"
    MATH_LABEL = "mathLabel"
    TEMPERATURE_COMBO_BOX = "temperatureComboBox"

    DENSITY_A_LABEL = "rhoALabel"
    DENSITY_B_LABEL = "rhoBLabel"
    DENSITY_COMBO_BOX = "rhoComboBox"


    VISCOSITY_COMBO_BOX = "muComboBox"
    THERMAL_CONDUCTIVITY_COMBO_BOX = "condComboBox"
    ENTHALPY_COMBO_BOX = "hComboBox"
    ENTROPY_COMBO_BOX = "sComboBox"
    SPECIFIC_HEAT_COMBO_BOX = "cpComboBox"
    MIN_TEMPERATURE_EDIT_LINE = "minTemperatureEditLine"
    MAX_TEMPERATURE_EDIT_LINE = "maxTemperatureEditLine"
    BACK_BUTTON = "backButton"
    CALCULATE_BUTTON = "calculateButton"
