import cantera as ct
import numpy as np

from asali.utils.unit_converter import UnitConverter

from src.core.data_keys import DataKeys
from src.core.unit_dimension_handler import UnitDimensionHandler


def properties_calculator(data_store):
    """
    Function to estimate thermodynamic and transport properties
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

    composition_tuple = data_store.get_data(DataKeys.INLET_COMPOSITION.value)

    if "mole" in composition_tuple[1].lower():
        gas.TPX = temperature, pressure, composition_tuple[0]
    else:
        gas.TPY = temperature, pressure, composition_tuple[0]

    # Density
    ud = data_store.get_data(DataKeys.RHO.value)[1]
    value = uc.convert_from_kg_per_cubic_meter(gas.density,
                                               UnitDimensionHandler.from_human_to_code_ud(ud))
    data_store.update_data(DataKeys.RHO.value, (value, ud))

    # Viscosity
    ud = data_store.get_data(DataKeys.MU.value)[1]
    value = uc.convert_from_pascal_seconds(gas.viscosity,
                                           UnitDimensionHandler.from_human_to_code_ud(ud))
    data_store.update_data(DataKeys.MU.value, (value, ud))

    # Molecular weight
    ud = data_store.get_data(DataKeys.MW.value)[1]
    value = uc.convert_from_kg_per_kmol(gas.mean_molecular_weight,
                                        UnitDimensionHandler.from_human_to_code_ud(ud))
    data_store.update_data(DataKeys.MW.value, (value, ud))

    # Thermal conductivity
    ud = data_store.get_data(DataKeys.COND.value)[1]
    value = uc.convert_from_watt_per_meter_per_kelvin(gas.thermal_conductivity,
                                                      UnitDimensionHandler.from_human_to_code_ud(ud))
    data_store.update_data(DataKeys.COND.value, (value, ud))

    # Mixture diffusivity
    ud = data_store.get_data(DataKeys.DIFF_MIX.value)[1]
    total_diff_mix = gas.mix_diff_coeffs_mass
    diff_mix_zero = total_diff_mix == 0
    total_diff_mix[diff_mix_zero] = gas.binary_diff_coeffs[diff_mix_zero, diff_mix_zero]
    species_names = list(composition_tuple[0].keys())
    species_mask = np.asarray([True if s in species_names else False for s in gas.species_names])
    diff_mix = total_diff_mix[species_mask]
    value = dict(zip(species_names,
                     [uc.convert_from_square_meter_per_seconds(d, UnitDimensionHandler.from_human_to_code_ud(ud)) for d
                      in diff_mix]))
    data_store.update_data(DataKeys.DIFF_MIX.value, (value, ud))

    return data_store
