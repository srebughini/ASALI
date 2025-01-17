import os
from enum import Enum


class ChemkinToCanteraPageConfig(Enum):
    """
    Class to handle chemkin to cantera page configurations
    """
    PATH = os.path.join("gui", "ui", "input", "chemkin_to_cantera_page.ui")
    NAME = "ChemkinToCanteraPage"