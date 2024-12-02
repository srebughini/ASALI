from enum import Enum

from src.config.reactor_config import ReactorConfig


class Het1dInputPageConfig(Enum):
    """
    Class to handle heterogeneous 1d input page configurations
    """
    PATH = "gui/ui/input/het_1d_input_page.ui"
    NAME = "Het1dInputPage"
    REACTOR_NAME = "Heterogeneous 1D reactor"
    TEMPERATURES = ["Gas", "Solid"]
    TABS_NAMES = [ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value,
                  ReactorConfig.SOLVING_OPTION_TAB_NAME.value,
                  ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value,
                  ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value,
                  ReactorConfig.SOLID_TAB_NAME.value]
    GAS_SPECIE_TO_ROW_INDEX = 3
    SURFACE_SPECIE_TO_ROW_INDEX = 2

    SOLVING_OPTION_LAYOUT_MINIMUM_ROW_IDX = 8
    REACTOR_PROPERTIES_LAYOUT_MINIMUM_ROW_IDX = 8
    COVERAGE_COMPOSITION_LAYOUT_MINIMUM_ROW_IDX = 8
    INITIAL_CONDITION_LAYOUT_MINIMUM_ROW_IDX = 8
    SOLID_LAYOUT_MINIMUM_ROW_IDX = 8
    GEOMETRY_LAYOUT_MINIMUM_ROW_IDX = 8
