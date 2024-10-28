from asali.savers.reactor import ReactorSaver

from src.core.data_keys import DataKeys
from src.core.data_store import DataStore


def reactor_saver(data_store) -> None:
    """
    Function to save reactor results on file
    Parameters
    ----------
    data_store: DataStore
        Class to handle the user input

    Returns
    -------
    """
    cantera_input_file_path = data_store.get_data(DataKeys.CHEMISTRY_FILE_PATH.value)
    gas_phase_name = data_store.get_data(DataKeys.GAS_PHASE_NAME.value)
    surface_phase_name = data_store.get_data(DataKeys.SURFACE_PHASE_NAME.value)
    reactor_model = data_store.get_data(DataKeys.REACTOR_TYPE.value)

    reactor_class = reactor_model(cantera_input_file_path, gas_phase_name, surface_phase_name)

    results = data_store.get_data(DataKeys.REACTOR_RESULTS.value)
    reactor_class.set_results(*results)

    saver = ReactorSaver(reactor_class)

    composition_type = data_store.get_data(DataKeys.PLOT_AND_SAVE_COMPOSITION_TYPE.value)
    output_file_path = data_store.get_data(DataKeys.OUTPUT_FILE_PATH.value)

    if 'mol' in composition_type.lower():
        saver.save_using_mole_fraction(output_file_path)
    else:
        saver.save_using_mass_fraction(output_file_path)
