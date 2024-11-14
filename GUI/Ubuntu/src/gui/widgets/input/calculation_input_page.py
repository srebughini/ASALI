from enum import Enum


class CalculationInputPageWidgets(Enum):
    """
    Class to handle calculation input page widgets names
    """
    TEMPERATURE_EDIT_LINE = "temperatureEditLine"
    TEMPERATURE_COMBO_BOX = "temperatureComboBox"
    PRESSURE_EDIT_LINE = "pressureEditLine"
    PRESSURE_COMBO_BOX = "pressureComboBox"
    COMPOSITION_COMBO_BOX = "compositionComboBox"
    ADD_SPECIE_BUTTON = "addSpecieButton"
    REMOVE_SPECIE_BUTTON = "removeSpecieButton"
    NEXT_BUTTON = "nextButton"
    GRID_LAYOUT = "gridLayout"
    CALCULATION_COMBO_BOX = "calculationComboBox"


