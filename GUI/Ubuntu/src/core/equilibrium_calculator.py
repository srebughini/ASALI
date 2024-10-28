import cantera as ct
import numpy as np

from asali.utils.unit_converter import UnitConverter

from src.core.data_keys import DataKeys
from src.core.data_store import DataStore
from src.core.unit_dimension_handler import UnitDimensionHandler

equilibrium_parser = {"Fixed temperature and pressure": "TP",
                      "Fixed specific enthalpy and pressure": "HP",
                      "Fixed specific internal energy and specific volume": "UV",
                      "Fixed specific entropy and specific volume": "SV",
                      "Fixed specific entropy and pressure": "SP"}


def equilibrium_calculator(data_store) -> DataStore:
    """
    Function to estimate equilibrium composition, temperature and pressure
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

    uc = UnitConverter()

    temperature_tuple = data_store.get_data(DataKeys.INLET_T.value)
    temperature = uc.convert_to_kelvin(temperature_tuple[0],
                                       UnitDimensionHandler.from_human_to_code_ud(temperature_tuple[1]))

    pressure_tuple = data_store.get_data(DataKeys.INLET_P.value)
    pressure = uc.convert_to_pascal(pressure_tuple[0],
                                    UnitDimensionHandler.from_human_to_code_ud(pressure_tuple[1]))

    composition_tuple = data_store.get_data(DataKeys.INLET_GAS_COMPOSITION.value)

    if "mole" in composition_tuple[1].lower():
        gas.TPX = temperature, pressure, composition_tuple[0]
    else:
        gas.TPY = temperature, pressure, composition_tuple[0]

    equilibrium_type = equilibrium_parser[data_store.get_data(DataKeys.EQUILIBRIUM_TYPE.value)]
    gas.equilibrate(equilibrium_type)

    # Temperature
    ud = data_store.get_data(DataKeys.EQUILIBRIUM_T.value)[1]
    value = uc.convert_from_kelvin(gas.T,
                                   UnitDimensionHandler.from_human_to_code_ud(ud))
    data_store.update_data(DataKeys.EQUILIBRIUM_T.value, (value, ud))

    # Pressure
    ud = data_store.get_data(DataKeys.EQUILIBRIUM_P.value)[1]
    value = uc.convert_from_pascal(gas.P,
                                   UnitDimensionHandler.from_human_to_code_ud(ud))
    data_store.update_data(DataKeys.EQUILIBRIUM_P.value, (value, ud))

    # Composition
    species_names = list(composition_tuple[0].keys())
    data_store.update_data(DataKeys.EQUILIBRIUM_N.value, species_names)

    species_mask = np.asarray([True if s in species_names else False for s in gas.species_names])

    # Mass fraction
    y = np.asarray(gas.Y)

    data_store.update_data(DataKeys.EQUILIBRIUM_Y.value, y[species_mask].tolist())

    # Mole fraction
    x = np.asarray(gas.X)
    data_store.update_data(DataKeys.EQUILIBRIUM_X.value, x[species_mask].tolist())
    return data_store
