import cantera as ct
import numpy as np

from asali.utils.unit_converter import UnitConverter

from src.gui.enums.composition_type import CompositionType
from src.core.data_keys import DataKeys
from src.core.data_store import DataStore
from src.core.unit_dimension_handler import UnitDimensionHandler

from scipy import stats

from src.gui.enums.properties import Properties
from src.gui.enums.regression_method import RegressionMethod


def regression_calculator(data_store) -> DataStore:
    """
    Function to estimate thermodynamic and transport properties linear regression
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
    pressure_tuple = data_store.get_data(DataKeys.PRESSURE)
    pressure = uc.convert_to_pascal(pressure_tuple[0],
                                    UnitDimensionHandler.from_human_to_code_ud(pressure_tuple[1]))

    min_temperature_tuple = data_store.get_data(DataKeys.MIN_TEMPERATURE)
    min_temperature = uc.convert_to_kelvin(min_temperature_tuple[0],
                                           UnitDimensionHandler.from_human_to_code_ud(min_temperature_tuple[1]))

    max_temperature_tuple = data_store.get_data(DataKeys.MAX_TEMPERATURE)
    max_temperature = uc.convert_to_kelvin(max_temperature_tuple[0],
                                           UnitDimensionHandler.from_human_to_code_ud(max_temperature_tuple[1]))

    temperature_ud = max_temperature_tuple[1]
    temperature_vector = uc.convert_from_kelvin(np.linspace(min_temperature, max_temperature, num=50, endpoint=True),
                                                temperature_ud)

    data_store.update_data(DataKeys.TEMPERATURE_VECTOR,
                           (temperature_vector, UnitDimensionHandler.from_human_to_code_ud(temperature_ud)))

    current_property = data_store.get_data(DataKeys.REGRESSION_PROPERTY_TYPE)
    property_ud = data_store.get_data(DataKeys.REGRESSION_PROPERTY)[-1]

    composition_tuple = data_store.get_data(DataKeys.GAS_COMPOSITION)
    if composition_tuple[1] == CompositionType.MOLE:
        gas.TPX = temperature_vector[0], pressure, composition_tuple[0]
    else:
        gas.TPY = temperature_vector[0], pressure, composition_tuple[0]

    values = np.zeros_like(temperature_vector, dtype=np.float64)

    if Properties.DENSITY == current_property:
        for i, temperature in enumerate(temperature_vector):
            gas.TP = temperature, pressure
            values[i] = uc.convert_from_kg_per_cubic_meter(gas.density,
                                                           UnitDimensionHandler.from_human_to_code_ud(property_ud))
    elif Properties.VISCOSITY == current_property:
        for i, temperature in enumerate(temperature_vector):
            gas.TP = temperature, pressure
            values[i] = uc.convert_from_pascal_seconds(gas.viscosity,
                                                       UnitDimensionHandler.from_human_to_code_ud(property_ud))
    elif Properties.THERMAL_CONDUCTIVITY == current_property:
        for i, temperature in enumerate(temperature_vector):
            gas.TP = temperature, pressure
            values[i] = uc.convert_from_watt_per_meter_per_kelvin(gas.thermal_conductivity,
                                                                  UnitDimensionHandler.from_human_to_code_ud(
                                                                      property_ud))
    elif Properties.ENTROPY == current_property:
        if 'mol' in property_ud.lower():
            for i, temperature in enumerate(temperature_vector):
                gas.TP = temperature, pressure
                values[i] = uc.convert_from_joule_per_kmol_per_kelvin(gas.entropy_mole,
                                                                      UnitDimensionHandler.from_human_to_code_ud(
                                                                          property_ud))

        else:
            for i, temperature in enumerate(temperature_vector):
                gas.TP = temperature, pressure
                values[i] = uc.convert_from_joule_per_kg_per_kelvin(gas.entropy_mass,
                                                                    UnitDimensionHandler.from_human_to_code_ud(
                                                                        property_ud))
    elif Properties.ENTHALPY == current_property:
        if 'mol' in property_ud.lower():
            for i, temperature in enumerate(temperature_vector):
                gas.TP = temperature, pressure
                values[i] = uc.convert_from_joule_per_kmol_per_kelvin(gas.enthalpy_mole,
                                                                      UnitDimensionHandler.from_human_to_code_ud(
                                                                          property_ud))

        else:
            for i, temperature in enumerate(temperature_vector):
                gas.TP = temperature, pressure
                values[i] = uc.convert_from_joule_per_kg_per_kelvin(gas.enthalpy_mass,
                                                                    UnitDimensionHandler.from_human_to_code_ud(
                                                                        property_ud))
    elif Properties.SPECIFIC_HEAT == current_property:
        if 'mol' in property_ud.lower():
            for i, temperature in enumerate(temperature_vector):
                gas.TP = temperature, pressure
                values[i] = uc.convert_from_joule_per_kmol_per_kelvin(gas.cp_mole,
                                                                      UnitDimensionHandler.from_human_to_code_ud(
                                                                          property_ud))

        else:
            for i, temperature in enumerate(temperature_vector):
                gas.TP = temperature, pressure
                values[i] = uc.convert_from_joule_per_kg_per_kelvin(gas.cp_mass,
                                                                    UnitDimensionHandler.from_human_to_code_ud(
                                                                        property_ud))

    regression_method = data_store.get_data(DataKeys.REGRESSION_METHOD)

    if RegressionMethod.LINEAR == regression_method:
        a, b, _, _, _ = stats.linregress(temperature_vector, values)
        data_store.update_data(DataKeys.REGRESSION_PROPERTY, (values, a, b, property_ud))
    elif RegressionMethod.POWER_LAW == regression_method:
        if np.max(values) < 0.:
            data_store.update_data(DataKeys.REGRESSION_PROPERTY, (values, None, None, property_ud))
        else:
            b, e, _, _, _ = stats.linregress(np.log(temperature_vector), np.log(values))
            a = np.exp(e)
            data_store.update_data(DataKeys.REGRESSION_PROPERTY, (values, a, b, property_ud))
    elif RegressionMethod.LOGARITHMIC == regression_method:
        a, b, _, _, _ = stats.linregress(np.log(temperature_vector), values)
        data_store.update_data(DataKeys.REGRESSION_PROPERTY, (values, a, b, property_ud))

    return data_store
