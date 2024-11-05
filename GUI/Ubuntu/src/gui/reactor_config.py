from enum import Enum


class ReactorConfig(Enum):
    """
    Class to handle the configuration of the reactors
    """
    BATCH_NAME = "Batch reactor"
    BATCH_TEMPERATURES = ["Gas"]
    BATCH_INITIAL_SURF_NS = 1
    BATCH_N_ROWS = 4
    CSTR_NAME = "Continuous stirred tank reactor"
    STEADY_STATE_PH_1D_NAME = "Steady state pseudo-homogeneous 1D reactor"
    TRANSIENT_PH_1D_NAME = "Transient pseudo-homogeneous 1D reactor"
    STEADY_STATE_HET_1D_NAME = "Steady state heterogeneous 1D reactor"
    TRANSIENT_HET_1D_NAME = "Transient heterogeneous 1D reactor"
