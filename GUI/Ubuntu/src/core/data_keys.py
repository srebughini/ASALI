from enum import Enum


class DataKeys(Enum):
    """
    Class to handle the keys of the data stored in DataStore
    """
    CHEMISTRY_FILE_PATH = "chemistry_file_path"
    UDK_FILE_PATH = "udk_file_path"
    GAS_PHASE_NAME = "gas_phase_name"
    SURFACE_PHASE_NAME = "surface_phase_name"
    INLET_NS = "inlet_number_of_species"
    INLET_T = "inlet_temperature"
    INLET_P = "inlet_pressure"
    INLET_COMPOSITION = "inlet_composition"
    RHO = "density"
    MU = "viscosity"
    MW = "molecular_weight"
    COND = "thermal_conductivity"
    DIFF_MIX = "mixture_diffusivity"

