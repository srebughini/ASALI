from enum import Enum

from src.config.reactor_config import ReactorConfig


class BatchInputPageConfig(Enum):
    """
    Class to handle batch input page configurations
    """
    PATH = "gui/ui/input/batch_input_page.ui"
    NAME = "BatchInputPage"
    REACTOR_NAME = "Batch reactor"
    TEMPERATURES = ["Gas"]
    TABS_NAMES = [ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value,
                  ReactorConfig.SOLVING_OPTION_TAB_NAME.value,
                  ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value]
