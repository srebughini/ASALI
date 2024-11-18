from enum import Enum


class VacuumOutputPageWidgets(Enum):
    """
    Class to handle vacuum output page widgets names
    """
    VELOCITY_LABEL = "vValueLabel"
    VELOCITY_COMBO_BOX = "vComboBox"
    LENGTH_LABEL = "lValueLabel"
    LENGTH_COMBO_BOX = "lComboBox"
    DIFF_LABEL = "diffValueLabel"
    DIFF_COMBO_BOX = "diffComboBox"
    KNUDSEN_LABEL = "knValueLabel"
    BACK_BUTTON = "backButton"
    CALCULATE_BUTTON = "calculateButton"
    GEOMETRY_EDIT_LINE = "geometryEditLine"
    GEOMETRY_COMBO_BOX = "geometryComboBox"
    SPECIE_COMBO_BOX = "specieComboBox"
    INPUT_LABEL = "inputLabel"
    OUTPUT_LABEL = "outputLabel"
