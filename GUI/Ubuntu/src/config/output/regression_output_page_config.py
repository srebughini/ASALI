import os
from enum import Enum


class RegressionOutputPageConfig(Enum):
    """
    Class to handle linear regression output page configurations
    """
    PATH = os.path.join("gui", "ui", "output", "regression_output_page.ui")
    NAME = "RegressionOutputPage"
