import os
from enum import Enum


class PropertiesOutputPageConfig(Enum):
    """
    Class to handle properties output page configurations
    """
    PATH = os.path.join("gui", "ui", "output", "properties_output_page.ui")
    NAME = "PropertiesOutputPage"