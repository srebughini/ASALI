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
    CP = "specific_heat"
    H = "enthalpy"
    S = "entropy"
    GEOMETRY = "geometry"
    V = "velocity"
    L = "length"
    KN = "knudsen_number"
    VACUUM_SPECIE = "vacuum_specie"
    THERMO_FILE_PATH = "chemkin_thermo_file_path"
    TRANSPORT_FILE_PATH = "chemkin_transport_file_path"
    KINETIC_FILE_PATH = "chemkin_gas_kinetic_file_path"
    SURFACE_FILE_PATH = "chemkin_surface_file_path"
    USER_DEFINED_KINETIC_FILE_PATH = "asali_user_defined_kinetic_file_path"

