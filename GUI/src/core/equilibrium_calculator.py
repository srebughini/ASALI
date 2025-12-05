import cantera as ct
import numpy as np

from asali.utils.unit_converter import UnitConverter

from src.gui.enums.composition_type import CompositionType
from src.core.data_keys import DataKeys
from src.core.data_store import DataStore
from src.core.unit_dimension_handler import UnitDimensionHandler
from src.gui.enums.equilibrium_type import EquilibriumType

equilibrium_parser = {EquilibriumType.TP: "TP",
                      EquilibriumType.HP: "HP",
                      EquilibriumType.UV: "UV",
                      EquilibriumType.SV: "SV",
                      EquilibriumType.SP: "SP"}


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
    cantera_input_file_path = data_store.get_data(DataKeys.CHEMISTRY_FILE_PATH)
    gas_phase_name = data_store.get_data(DataKeys.GAS_PHASE_NAME)
    gas = ct.Solution(cantera_input_file_path, gas_phase_name)

    uc = UnitConverter()

    temperature_tuple = data_store.get_data(DataKeys.TEMPERATURE)
    temperature = uc.convert_to_kelvin(temperature_tuple[0],
                                       UnitDimensionHandler.from_human_to_code_ud(temperature_tuple[1]))

    pressure_tuple = data_store.get_data(DataKeys.PRESSURE)
    pressure = uc.convert_to_pascal(pressure_tuple[0],
                                    UnitDimensionHandler.from_human_to_code_ud(pressure_tuple[1]))

    composition_tuple = data_store.get_data(DataKeys.GAS_COMPOSITION)

    if CompositionType.MOLE == composition_tuple[1]:
        gas.TPX = temperature, pressure, composition_tuple[0]
    else:
        gas.TPY = temperature, pressure, composition_tuple[0]

    equilibrium_type = equilibrium_parser[data_store.get_data(DataKeys.EQUILIBRIUM_TYPE)]
    gas.equilibrate(equilibrium_type)

    # Temperature
    ud = data_store.get_data(DataKeys.EQ_TEMPERATURE)[1]
    value = uc.convert_from_kelvin(gas.T,
                                   UnitDimensionHandler.from_human_to_code_ud(ud))
    data_store.update_data(DataKeys.EQ_TEMPERATURE, (value, ud))

    # Pressure
    ud = data_store.get_data(DataKeys.EQ_PRESSURE)[1]
    value = uc.convert_from_pascal(gas.P,
                                   UnitDimensionHandler.from_human_to_code_ud(ud))
    data_store.update_data(DataKeys.EQ_PRESSURE, (value, ud))

    # Composition
    species_names = list(composition_tuple[0].keys())
    data_store.update_data(DataKeys.EQ_SPECIE_NAMES, species_names)

    species_mask = np.asarray([True if s in species_names else False for s in gas.species_names])

    # Mass fraction
    y = np.asarray(gas.Y)

    data_store.update_data(DataKeys.EQ_MASS_FRACTION, y[species_mask])

    # Mole fraction
    x = np.asarray(gas.X)
    data_store.update_data(DataKeys.EQ_MOLE_FRACTION, x[species_mask])
    return data_store
