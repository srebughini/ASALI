import os
from enum import Enum


class UserDefinedKineticPageConfig(Enum):
    """
    Class to handle user defined kinetic page page configurations
    """
    PATH = os.path.join("gui", "ui", "input", "user_defined_kinetic_page.ui")
    NAME = "UserDefinedKineticPage"