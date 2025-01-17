import os
from enum import Enum


class ChemistryInputPageConfig(Enum):
    """
    Class to handle chemistry input page configurations
    """
    PATH = os.path.join("gui", "ui", "input", "chemistry_input_page.ui")
    NAME = "ChemistryInputPage"