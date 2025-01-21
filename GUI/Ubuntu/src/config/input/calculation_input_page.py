import os
from enum import Enum


class CalculationInputPageConfig(Enum):
    """
    Class to handle calculation input page configurations
    """
    PATH = os.path.join("gui", "ui", "input", "properties_page.ui")
    NAME = "CalculationInputPage"
    INITIAL_SPECIE_ROW_IDX = 5
