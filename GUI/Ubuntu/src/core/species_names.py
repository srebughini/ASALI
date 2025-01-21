import cantera as ct
from src.core.data_keys import DataKeys
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
    if not data_store.get_data(DataKeys.IS_GAS_SPECIES_NAMES_UPDATED):
        cantera_input_file_path = data_store.get_data(DataKeys.CHEMISTRY_FILE_PATH)
        gas_phase_name = data_store.get_data(DataKeys.GAS_PHASE_NAME)
        gas = ct.Solution(cantera_input_file_path, gas_phase_name)

        data_store.update_data(DataKeys.GAS_SPECIES_NAMES, gas.species_names)
        data_store.update_data(DataKeys.IS_GAS_SPECIES_NAMES_UPDATED, True)

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
    if data_store.get_data(DataKeys.SURFACE_SPECIES_NAMES_UPDATE):
        cantera_input_file_path = data_store.get_data(DataKeys.CHEMISTRY_FILE_PATH)
        gas_phase_name = data_store.get_data(DataKeys.GAS_PHASE_NAME)
        surface_phase_name = data_store.get_data(DataKeys.SURFACE_PHASE_NAME)

        if surface_phase_name is None:
            data_store.update_data(DataKeys.SURFACE_SPECIES_NAMES, [])
            data_store.update_data(DataKeys.SURFACE_SPECIES_NAMES_UPDATE, False)
            return data_store

        gas = ct.Solution(cantera_input_file_path, gas_phase_name)
        surface = ct.Interface(cantera_input_file_path, surface_phase_name, [gas])

        data_store.update_data(DataKeys.SURFACE_SPECIES_NAMES, surface.species_names)
        data_store.update_data(DataKeys.SURFACE_SPECIES_NAMES_UPDATE, False)

    return data_store
