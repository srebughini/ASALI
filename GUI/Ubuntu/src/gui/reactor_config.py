from enum import Enum


class ReactorConfig(Enum):
    """
    Class to handle the configuration of the reactors
    """
    SOLVING_OPTION_TAB_NAME = 'Solving options'
    REACTOR_PROPERTIES_TAB_NAME = 'Reactor properties'
    COVERAGE_COMPOSITION_TAB_NAME = 'Coverage compositions'
    INITIAL_CONDITIONS_TAB_NAME = 'Initial conditions'

    BATCH_NAME = "Batch reactor"
    BATCH_TEMPERATURES = ["Gas"]
    BATCH_TABS_NAMES = [REACTOR_PROPERTIES_TAB_NAME,
                        SOLVING_OPTION_TAB_NAME,
                        COVERAGE_COMPOSITION_TAB_NAME]
    BATCH_COVERAGE_DYNAMIC_ROW_IDX = 1

    CSTR_NAME = "Continuous stirred tank reactor"
    CSTR_TEMPERATURES = ["Gas"]
    CSTR_TABS_NAMES = [REACTOR_PROPERTIES_TAB_NAME,
                       SOLVING_OPTION_TAB_NAME,
                       COVERAGE_COMPOSITION_TAB_NAME,
                       INITIAL_CONDITIONS_TAB_NAME]

    STEADY_STATE_PH_1D_NAME = "Steady state pseudo-homogeneous 1D reactor"
    TRANSIENT_PH_1D_NAME = "Transient pseudo-homogeneous 1D reactor"
    STEADY_STATE_HET_1D_NAME = "Steady state heterogeneous 1D reactor"
    TRANSIENT_HET_1D_NAME = "Transient heterogeneous 1D reactor"
