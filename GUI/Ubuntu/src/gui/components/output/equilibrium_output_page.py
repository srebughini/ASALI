from enum import Enum


class EquilibriumOutputPageWidgets(Enum):
    """
    Class to handle equilibrium output page components names
    """
    TEMPERATURE_LABEL = "temperatureValueLabel"
    TEMPERATURE_COMBO_BOX = "temperatureOutputComboBox"
    PRESSURE_LABEL = "pressureValueLabel"
    PRESSURE_COMBO_BOX = "pressureOutputComboBox"
    NAMES_LABEL = "nLabel"
    MOLE_FRACTION_LABEL = "xLabel"
    MASS_FRACTION_LABEL = "yLabel"
    OUTPUT_LABEL = "outputLabel"
    BACK_BUTTON = "backButton"
    CALCULATE_BUTTON = "calculateButton"
    EQUILIBRIUM_TYPE_COMBO_BOX = "typeComboBox"
    CANTERA_BUTTON = "canteraButton"
