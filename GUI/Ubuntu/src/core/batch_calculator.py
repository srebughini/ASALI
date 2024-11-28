from asali.reactors.batch import BatchReactor
from asali.utils.unit_converter import UnitConverter

from src.core.composition_type import CompositionType
from src.core.data_keys import DataKeys
from src.core.data_store import DataStore
from src.core.unit_dimension_handler import UnitDimensionHandler

import numpy as np


def batch_calculator(data_store, results) -> None:
    """
    Function to run the batch reactor model
    Parameters
    ----------
    data_store: DataStore
        Class to handle the user input
    results: multiprocessing.Queue()
        Results to be saved

    Returns
    -------
    """
    # Input files
    cantera_input_file_path = data_store.get_data(DataKeys.CHEMISTRY_FILE_PATH.value)
    gas_phase_name = data_store.get_data(DataKeys.GAS_PHASE_NAME.value)
    surface_phase_name = data_store.get_data(DataKeys.SURFACE_PHASE_NAME.value)
    udk_file_path = data_store.get_data(DataKeys.UDK_FILE_PATH.value)

    reactor_class = BatchReactor(cantera_input_file_path, gas_phase_name, surface_phase_name)
    uc = UnitConverter()

    # Coverage
    initial_coverage = data_store.get_data(DataKeys.INITIAL_SURF_COMPOSITION.value)

    if udk_file_path is not None:
        reactor_class.set_user_defined_kinetic_model(udk_file_path)
    else:
        reactor_class.set_initial_coverage(initial_coverage)

    # Volume
    volume_tuple = data_store.get_data(DataKeys.VOLUME.value)
    reactor_class.set_volume(volume_tuple[0],
                             UnitDimensionHandler.from_human_to_code_ud(volume_tuple[1]))

    # Pressure
    pressure_tuple = data_store.get_data(DataKeys.INLET_P.value)
    reactor_class.set_pressure(pressure_tuple[0],
                               UnitDimensionHandler.from_human_to_code_ud(pressure_tuple[1]))

    # Catalytic load
    alfa_tuple = data_store.get_data(DataKeys.ALFA.value)
    reactor_class.set_catalytic_load(alfa_tuple[0],
                                     UnitDimensionHandler.from_human_to_code_ud(alfa_tuple[1]))

    # Initial composition
    composition_tuple = data_store.get_data(DataKeys.INITIAL_GAS_COMPOSITION.value)

    if composition_tuple[1] == CompositionType.MOLE:
        reactor_class.set_initial_mole_fraction(composition_tuple[0])
    else:
        reactor_class.set_initial_mass_fraction(composition_tuple[0])

    # Temperature
    temperature_tuple = data_store.get_data(DataKeys.INITIAL_GAS_T.value)
    reactor_class.set_initial_temperature(temperature_tuple[0],
                                          UnitDimensionHandler.from_human_to_code_ud(temperature_tuple[1]))

    # Energy balance
    energy_bool = data_store.get_data(DataKeys.ENERGY_BALANCE.value)
    reactor_class.set_energy(energy_bool)

    # Integration time
    tmax_tuple = data_store.get_data(DataKeys.TMAX.value)
    tmax = uc.convert_to_seconds(tmax_tuple[0],
                                 UnitDimensionHandler.from_human_to_code_ud(tmax_tuple[1]))

    tstep_tuple = data_store.get_data(DataKeys.TSTEP.value)
    tstep = uc.convert_to_seconds(tstep_tuple[0],
                                  UnitDimensionHandler.from_human_to_code_ud(tstep_tuple[1]))

    num = int(tmax / tstep) + 1

    tspan = np.linspace(0., tmax, num=num, endpoint=True)

    reactor_class.solve(tspan, "s")

    results.put((reactor_class.get_time("s"),
                 reactor_class.get_results(),
                 None))
