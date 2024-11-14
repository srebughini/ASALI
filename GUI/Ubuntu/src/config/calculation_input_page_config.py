from enum import Enum


class CalculationInputPageConfig(Enum):
    """
    Class to handle calculation input page configurations
    """
    BACK_BUTTON_NAME = 'backButton'
    NEXT_BUTTON_NAME = 'nextButton'
    BACK_BUTTON_COL_IDX = 0
    NEXT_BUTTON_COL_IDX = 2
    PATH = "gui/ui/input/calculation_input_page.ui"
    NAME = "CalculationInputPage"
    INITIAL_SPECIE_ROW_IDX = 5
    BUTTON_DICT = {BACK_BUTTON_NAME: BACK_BUTTON_COL_IDX, NEXT_BUTTON_NAME: NEXT_BUTTON_COL_IDX}
