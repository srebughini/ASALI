from enum import Enum

from src.config.reactor_config import ReactorConfig


class Ph1dInputPageConfig(Enum):
    """
    Class to handle pseudo-homogeneous 1d input page configurations
    """
    PATH = "gui/ui/input/ph_1d_input_page.ui"
    NAME = "Ph1dInputPage"
    REACTOR_NAME = "Pseudo-homogeneous 1D reactor"
    TEMPERATURES = ["Gas"]
    TABS_NAMES = [ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value,
                  ReactorConfig.SOLVING_OPTION_TAB_NAME.value,
                  ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value,
                  ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value]
