from enum import Enum


class ReactorConfig(Enum):
    """
    Class to handle the configuration of the reactors
    """
    BATCH_NAME = "Batch reactor"
    BATCH_TEMPERATURES = ["Gas"]
    BATCH_INITIAL_SURFACE_SPECIE_ROW_IDX = 0
    BATCH_MINIMUM_ROW_IDX = 3
    BATCH_SURFACE_BUTTON_DICT = {'addCoverageButton': 0, 'removeCoverageButton': 1}
    CSTR_NAME = "Continuous stirred tank reactor"
    CSTR_TEMPERATURES = ["Gas"]
    CSTR_INITIAL_GAS_SPECIE_ROW_IDX = 0
    CSTR_INITIAL_SURFACE_SPECIE_ROW_IDX = 0
    CSTR_MINIMUM_ROW_IDX = 3
    CSTR_GAS_BUTTON_DICT = {'addSpecieButton': 0, 'removeSpecieButton': 1}
    CSTR_SURFACE_BUTTON_DICT = {'addCoverageButton': 0, 'removeCoverageButton': 1}
    STEADY_STATE_PH_1D_NAME = "Steady state pseudo-homogeneous 1D reactor"
    TRANSIENT_PH_1D_NAME = "Transient pseudo-homogeneous 1D reactor"
    STEADY_STATE_HET_1D_NAME = "Steady state heterogeneous 1D reactor"
    TRANSIENT_HET_1D_NAME = "Transient heterogeneous 1D reactor"
