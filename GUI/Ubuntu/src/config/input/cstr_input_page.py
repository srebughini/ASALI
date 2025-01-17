import os
from enum import Enum

from src.config.reactor import ReactorConfig


class CstrInputPageConfig(Enum):
    """
    Class to handle cstr input page configurations
    """
    PATH = os.path.join("gui", "ui", "input", "cstr_input_page.ui")
    NAME = "CstrInputPage"
    REACTOR_NAME = "Continuous stirred tank reactor"
    TEMPERATURES = ["Gas"]
    TABS_NAMES = [ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value,
                  ReactorConfig.SOLVING_OPTION_TAB_NAME.value,
                  ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value,
                  ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value]
    GAS_SPECIE_TO_ROW_INDEX = 3
    SURFACE_SPECIE_TO_ROW_INDEX = 1
    SOLVING_OPTION_LAYOUT_MINIMUM_ROW_IDX = 3
    REACTOR_PROPERTIES_LAYOUT_MINIMUM_ROW_IDX = 3
    COVERAGE_COMPOSITION_LAYOUT_MINIMUM_ROW_IDX = 3
    INITIAL_CONDITION_LAYOUT_MINIMUM_ROW_IDX = 3
