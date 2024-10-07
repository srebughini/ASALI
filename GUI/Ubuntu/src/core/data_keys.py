from enum import Enum


class DataKeys(Enum):
    """
    Class to handle the keys of the data stored in DataStore
    """
    CHEMISTRY_FILE_PATH = "chemistry_file_path"
    INLET_NS = "inlet_number_of_species"
    INLET_T = "inlet_temperature"
    INLET_P = "inlet_pressure"
    INLET_X = "inlet_mole_fraction"
    INLET_Y = "inlet_mass_fraction"
