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
    GAS_SPECIE_TO_ROW_INDEX = 4
    SURFACE_SPECIE_TO_ROW_INDEX = 2
    SOLVING_OPTION_LAYOUT_MINIMUM_ROW_IDX = 5
    REACTOR_PROPERTIES_LAYOUT_MINIMUM_ROW_IDX = 5
    COVERAGE_COMPOSITION_LAYOUT_MINIMUM_ROW_IDX = 5
    INITIAL_CONDITION_LAYOUT_MINIMUM_ROW_IDX = 5
