import cantera as ct
from src.core.data_keys import DataKeys

import random

from src.core.data_store import DataStore


def gas_species_names(data_store) -> DataStore:
    """
    Function to get the specie names in the gas phase
    Parameters
    ----------
    data_store: DataStore
        Class to handle the user input

    Returns
    -------
    data_store: DataStore
        Class to handle the user input & output
    """
    cantera_input_file_path = data_store.get_data(DataKeys.CHEMISTRY_FILE_PATH.value)
    gas_phase_name = data_store.get_data(DataKeys.GAS_PHASE_NAME.value)
    gas = ct.Solution(cantera_input_file_path, gas_phase_name)

    data_store.update_data(DataKeys.GAS_SPECIES_NAMES.value, gas.species_names)

    return data_store


def surface_species_names(data_store) -> DataStore:
    """
    Function to get the specie names in the surface phase
    Parameters
    ----------
    data_store: DataStore
        Class to handle the user input

    Returns
    -------
    data_store: DataStore
        Class to handle the user input & output
    """
    cantera_input_file_path = data_store.get_data(DataKeys.CHEMISTRY_FILE_PATH.value)
    gas_phase_name = data_store.get_data(DataKeys.GAS_PHASE_NAME.value)
    surface_phase_name = data_store.get_data(DataKeys.SURFACE_PHASE_NAME.value)

    if surface_phase_name is None:
        data_store.update_data(DataKeys.SURFACE_SPECIES_NAMES.value, [])
        return data_store

    gas = ct.Solution(cantera_input_file_path, gas_phase_name)
    surface = ct.Interface(cantera_input_file_path, surface_phase_name, [gas])

    data_store.update_data(DataKeys.SURFACE_SPECIES_NAMES.value, surface.species_names)
    return data_store


def get_random_specie_name(data_store) -> str:
    """
    Function to get a random specie name in the gas phase
    Parameters
    ----------
    data_store: DataStore
        Class to handle the user input

    Returns
    -------
    specie_name: str
        Random specie name
    """
    cantera_input_file_path = data_store.get_data(DataKeys.CHEMISTRY_FILE_PATH.value)
    gas_phase_name = data_store.get_data(DataKeys.GAS_PHASE_NAME.value)
    gas = ct.Solution(cantera_input_file_path, gas_phase_name)

    return random.choice(gas.species_names)


def get_random_coverage_name(data_store) -> str:
    """
    Function to get a random specie name in the surface phase
    Parameters
    ----------
    data_store: DataStore
        Class to handle the user input

    Returns
    -------
    specie_name: str
        Random specie name
    """
    cantera_input_file_path = data_store.get_data(DataKeys.CHEMISTRY_FILE_PATH.value)
    gas_phase_name = data_store.get_data(DataKeys.GAS_PHASE_NAME.value)
    surface_phase_name = data_store.get_data(DataKeys.SURFACE_PHASE_NAME.value)

    if surface_phase_name is None:
        return "Not Available"

    gas = ct.Solution(cantera_input_file_path, gas_phase_name)
    surface = ct.Interface(cantera_input_file_path, surface_phase_name, [gas])

    return random.choice(surface.species_names)
