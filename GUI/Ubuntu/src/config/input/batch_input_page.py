from enum import Enum

from src.config.reactor import ReactorConfig

import os

class BatchInputPageConfig(Enum):
    """
    Class to handle batch input page configurations
    """
    PATH = os.path.join("gui", "ui", "input", "batch_input_page.ui")
    NAME = "BatchInputPage"
    REACTOR_NAME = "Batch reactor"
    TEMPERATURES = ["Gas"]
    TABS_NAMES = [ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value,
                  ReactorConfig.SOLVING_OPTION_TAB_NAME.value,
                  ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value]
    SURFACE_SPECIE_TO_ROW_INDEX = 1
    SOLVING_OPTION_LAYOUT_MINIMUM_ROW_IDX = 3
    REACTOR_PROPERTIES_LAYOUT_MINIMUM_ROW_IDX = 3
    COVERAGE_COMPOSITION_LAYOUT_MINIMUM_ROW_IDX = 3
