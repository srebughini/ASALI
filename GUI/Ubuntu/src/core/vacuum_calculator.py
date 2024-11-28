import cantera as ct
import numpy as np

from asali.utils.unit_converter import UnitConverter

from src.core.composition_type import CompositionType
from src.core.data_keys import DataKeys
from src.core.data_store import DataStore
from src.core.unit_dimension_handler import UnitDimensionHandler


def vacuum_calculator(data_store) -> DataStore:
    """
    Function to estimate vacuum properties
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

    if composition_tuple[1] == CompositionType.MOLE:
        gas.TPX = temperature, pressure, composition_tuple[0]
    else:
        gas.TPY = temperature, pressure, composition_tuple[0]

    sp = gas.species(data_store.get_data(DataKeys.VACUUM_SPECIE.value))
    sp_idx = gas.species_names.index(data_store.get_data(DataKeys.VACUUM_SPECIE.value))

    # Mean free path
    mfp = 1.38064852 * 1e-23 * gas.T / (np.sqrt(2) * gas.P * np.square(sp.transport.diameter))
    ud = data_store.get_data(DataKeys.L.value)[1]
    value = uc.convert_from_meter(mfp,
                                  UnitDimensionHandler.from_human_to_code_ud(ud))

    data_store.update_data(DataKeys.L.value, (value, ud))

    # Mean gas velocity
    mgv = np.sqrt(8. * 8314. * gas.T / (np.pi * gas.molecular_weights[sp_idx]))
    ud = data_store.get_data(DataKeys.V.value)[1]
    value = uc.convert_from_meter_per_seconds(mgv,
                                              UnitDimensionHandler.from_human_to_code_ud(ud))

    data_store.update_data(DataKeys.V.value, (value, ud))

    # Knudsen number
    geometry_tuple = data_store.get_data(DataKeys.GEOMETRY.value)
    geometry = uc.convert_to_meter(geometry_tuple[0],
                                   UnitDimensionHandler.from_human_to_code_ud(geometry_tuple[1]))
    kn = mfp/geometry
    data_store.update_data(DataKeys.KN.value, kn)

    # Diffusivity
    ud = data_store.get_data(DataKeys.DIFF_MIX.value)[1]
    if kn > 1:
        value = mgv * geometry / 3.0
    else:
        total_diff_mix = gas.mix_diff_coeffs_mass
        diff_mix_zero = total_diff_mix == 0
        total_diff_mix[diff_mix_zero] = gas.binary_diff_coeffs[diff_mix_zero, diff_mix_zero]
        value = total_diff_mix[sp_idx]

    value = uc.convert_from_square_meter_per_seconds(value, UnitDimensionHandler.from_human_to_code_ud(ud))
    data_store.update_data(DataKeys.DIFF_MIX.value, (value, ud))

    return data_store
