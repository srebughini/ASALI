import os
from enum import Enum


class VacuumOutputPageConfig(Enum):
    """
    Class to handle vacuum output page configurations
    """
    PATH = os.path.join("gui", "ui", "output", "vacuum_output_page.ui")
    NAME = "VacuumOutputPage"