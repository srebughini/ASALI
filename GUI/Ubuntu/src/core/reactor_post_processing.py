from asali.plotters.reactor import ReactorPlotter
from asali.savers.reactor import ReactorSaver

from src.core.data_keys import DataKeys
from src.core.data_store import DataStore
from src.config.app_config import AppConfig


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


def reactor_plotter(data_store) -> None:
    """
    Function to plot reactor results
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

    color_map = data_store.get_data(DataKeys.COLORMAP.value)

    plotter = ReactorPlotter(reactor_class, colormap=color_map)

    plotter.set_rc_params(AppConfig.MATPLOTLIB_TOOLBAR.value)

    composition_type = data_store.get_data(DataKeys.PLOT_AND_SAVE_COMPOSITION_TYPE.value)
    species_list = data_store.get_data(DataKeys.GAS_SPECIES_NAMES_TO_BE_PLOTTED.value)
    surface_species_list = data_store.get_data(DataKeys.SURFACE_SPECIES_NAMES_TO_BE_PLOTTED.value)
    temperature_list = data_store.get_data(DataKeys.TEMPERATURE_TO_BE_PLOTTED.value)

    if len(species_list) > 0:
        if 'mol' in composition_type.lower():
            plotter.plot_species_mole_fraction(species_list)
        else:
            plotter.plot_species_mass_fraction(species_list)

    if len(surface_species_list) > 0:
        plotter.plot_coverage(surface_species_list)

    for t in temperature_list:
        if 'gas' == t.lower():
            plotter.plot_temperature()

    plotter.show()
