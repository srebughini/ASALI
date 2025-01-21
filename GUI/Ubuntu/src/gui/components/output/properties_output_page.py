from enum import Enum


class PropertiesOutputPageWidgets(Enum):
    """
    Class to handle properties output page components names
    """
    BACK_BUTTON = "backButton"
    CALCULATE_BUTTON = "calculateButton"
    DENSITY_LABEL = "rhoValueLabel"
    VISCOSITY_LABEL = "muValueLabel"
    THERMAL_CONDUCTIVITY_LABEL = "condValueLabel"
    DIFFUSIVITY_LABEL = "diffValueLabel"
    MOLECULAR_WEIGHT_LABEL = "mwValueLabel"
    ENTHALPY_LABEL = "hValueLabel"
    ENTROPY_LABEL = "sValueLabel"
    SPECIFIC_HEAT_LABEL = "cpValueLabel"
    TRANSPORT_LABEL = "transportLabel"
    THERMODYNAMIC_LABEL = "thermodynamicLabel"
    DENSITY_COMBO_BOX = "rhoComboBox"
    VISCOSITY_COMBO_BOX = "muComboBox"
    THERMAL_CONDUCTIVITY_COMBO_BOX = "condComboBox"
    DIFFUSIVITY_COMBO_BOX = "diffComboBox"
    MOLECULAR_WEIGHT_COMBO_BOX = "mwComboBox"
    ENTHALPY_COMBO_BOX = "hComboBox"
    ENTROPY_COMBO_BOX = "sComboBox"
    SPECIFIC_HEAT_COMBO_BOX = "cpComboBox"
