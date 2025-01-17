import os
from enum import Enum


class EquilibriumOutputPageConfig(Enum):
    """
    Class to handle equilibrium output page configurations
    """
    PATH = os.path.join("gui", "ui", "output", "equilibrium_output_page.ui")
    NAME = "EquilibriumOutputPage"