from enum import Enum


class ReactorConfig(Enum):
    """
    Class to handle generic reactors configuration
    """
    SOLVING_OPTION_TAB_NAME = 'Solving options'
    REACTOR_PROPERTIES_TAB_NAME = 'Reactor properties'
    COVERAGE_COMPOSITION_TAB_NAME = 'Coverage'
    INITIAL_CONDITIONS_TAB_NAME = 'Initial conditions'
    SOLID_TAB_NAME = 'Solid properties'
