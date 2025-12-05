import cantera as ct
import numpy as np

from asali.utils.unit_converter import UnitConverter
from src.gui.enums.composition_type import CompositionType
from src.core.data_keys import DataKeys
from src.core.data_store import DataStore
from src.core.unit_dimension_handler import UnitDimensionHandler
from src.gui.enums.properties import Properties
from src.gui.enums.regression_method import RegressionMethod


def create_gas_object(data_store: DataStore) -> ct.Solution:
    """
    Create a Cantera gas object from input file and phase.

    Returns
    -------
    ct.Solution
        Initialized gas object.
    """
    cantera_input_file_path = data_store.get_data(DataKeys.CHEMISTRY_FILE_PATH)
    gas_phase_name = data_store.get_data(DataKeys.GAS_PHASE_NAME)
    return ct.Solution(cantera_input_file_path, gas_phase_name)


def get_pressure(data_store: DataStore, uc: UnitConverter) -> float:
    """
    Convert input pressure to Pascals.

    Returns
    -------
    float
        Pressure in Pascals.
    """
    pressure_value, pressure_unit = data_store.get_data(DataKeys.PRESSURE)
    return uc.convert_to_pascal(pressure_value, UnitDimensionHandler.from_human_to_code_ud(pressure_unit))


def get_temperature_vector(data_store: DataStore, uc: UnitConverter):
    """
    Generate and return a temperature vector and unit.

    Returns
    -------
    tuple of (np.ndarray, str)
        Temperature vector in user units and its unit.
    """
    min_val, min_unit = data_store.get_data(DataKeys.MIN_TEMPERATURE)
    max_val, max_unit = data_store.get_data(DataKeys.MAX_TEMPERATURE)

    min_K = uc.convert_to_kelvin(min_val, UnitDimensionHandler.from_human_to_code_ud(min_unit))
    max_K = uc.convert_to_kelvin(max_val, UnitDimensionHandler.from_human_to_code_ud(max_unit))

    temp_vector_K = np.linspace(min_K, max_K, num=50, endpoint=True)
    temp_vector = uc.convert_from_kelvin(temp_vector_K, max_unit)

    return temp_vector, max_unit


def set_temperature_vector(data_store: DataStore, temp_vector: np.ndarray, temp_unit: str) -> DataStore:
    """
    Set temperature vector in data store.

    Returns
    -------
    DataStore
        Updated data store.
    """
    ud_code = UnitDimensionHandler.from_human_to_code_ud(temp_unit)
    data_store.update_data(DataKeys.TEMPERATURE_VECTOR, (temp_vector, ud_code))
    return data_store


def set_gas_composition(gas: ct.Solution, data_store: DataStore, temp: float, pressure: float) -> ct.Solution:
    """
    Set the composition of the gas object.

    Returns
    -------
    ct.Solution
        Updated gas object.
    """
    composition, comp_type = data_store.get_data(DataKeys.GAS_COMPOSITION)
    if comp_type == CompositionType.MOLE:
        gas.TPX = temp, pressure, composition
    else:
        gas.TPY = temp, pressure, composition
    return gas


def calculate_property_vector(gas, uc, temps, pressure, prop, prop_unit) -> np.ndarray:
    """
    Compute a thermodynamic or transport property across a range of temperatures.

    Parameters
    ----------
    gas : ct.Solution
        The gas object from Cantera.
    uc : UnitConverter
        Utility class for unit conversions.
    temps : np.ndarray
        Temperatures (in user units).
    pressure : float
        Pressure in Pascals.
    prop : Properties
        The property to compute.
    prop_unit : str
        Target unit for output values.

    Returns
    -------
    np.ndarray
        Computed values of the selected property in user units.
    """
    values = np.zeros_like(temps, dtype=np.float64)
    ud_code = UnitDimensionHandler.from_human_to_code_ud(prop_unit)

    # Transport/standard properties
    simple_property_map = {
        Properties.DENSITY: ("density", uc.convert_from_kg_per_cubic_meter),
        Properties.VISCOSITY: ("viscosity", uc.convert_from_pascal_seconds),
        Properties.THERMAL_CONDUCTIVITY: ("thermal_conductivity", uc.convert_from_watt_per_meter_per_kelvin),
    }

    # Molar vs mass-based thermodynamic properties
    thermodynamic_map = {
        Properties.ENTHALPY: {
            "mol": ("enthalpy_mole", uc.convert_from_joule_per_kmol_per_kelvin),
            "mass": ("enthalpy_mass", uc.convert_from_joule_per_kg_per_kelvin),
        },
        Properties.ENTROPY: {
            "mol": ("entropy_mole", uc.convert_from_joule_per_kmol_per_kelvin),
            "mass": ("entropy_mass", uc.convert_from_joule_per_kg_per_kelvin),
        },
        Properties.SPECIFIC_HEAT: {
            "mol": ("cp_mole", uc.convert_from_joule_per_kmol_per_kelvin),
            "mass": ("cp_mass", uc.convert_from_joule_per_kg_per_kelvin),
        }
    }

    # Direct property computation
    if prop in simple_property_map:
        attr, converter = simple_property_map[prop]
        for i, T in enumerate(temps):
            gas.TP = T, pressure
            values[i] = converter(getattr(gas, attr), ud_code)

    # Thermodynamic property with mol/mass branching
    elif prop in thermodynamic_map:
        mode = "mol" if "mol" in prop_unit.lower() else "mass"
        attr, converter = thermodynamic_map[prop][mode]
        for i, T in enumerate(temps):
            gas.TP = T, pressure
            values[i] = converter(getattr(gas, attr), ud_code)

    else:
        raise ValueError(f"Unsupported property: {prop}")

    return values


def perform_regression(data_store, temps, values, prop_unit) -> DataStore:
    """
    Perform the selected regression method and update the data store.

    Returns
    -------
    DataStore
        Updated data store with regression results.
    """
    method = data_store.get_data(DataKeys.REGRESSION_METHOD)

    if method == RegressionMethod.LINEAR:
        # a, b, *_ = stats.linregress(temps, values)
        z = np.polyfit(temps, values, 1)
        a = z[0]
        b = z[1]

    elif method == RegressionMethod.POWER_LAW:
        if np.max(values) < 0.:
            data_store.update_data(DataKeys.REGRESSION_PROPERTY, (values, None, None, prop_unit))
            return data_store
        # b, e, *_ = stats.linregress(np.log(temps), np.log(values))
        z = np.polyfit(np.log(temps), np.log(values), 1)
        b = z[0]
        e = z[1]
        a = np.exp(e)

    elif method == RegressionMethod.LOGARITHMIC:
        # a, b, *_ = stats.linregress(np.log(temps), values)
        z = np.polyfit(np.log(temps), values, 1)
        a = z[0]
        b = z[1]
    else:
        a = b = None

    data_store.update_data(DataKeys.REGRESSION_PROPERTY, (values, a, b, prop_unit))
    return data_store


def regression_calculator(data_store: DataStore) -> DataStore:
    """
    Main function to compute thermodynamic or transport property values over a temperature range
    and perform regression on the results.

    Parameters
    ----------
    data_store : DataStore
        Contains all user input and stores computed results.

    Returns
    -------
    DataStore
        Updated data store with regression results.
    """
    gas = create_gas_object(data_store)
    uc = UnitConverter()
    pressure = get_pressure(data_store, uc)
    temperature_vector, temperature_ud = get_temperature_vector(data_store, uc)

    data_store = set_temperature_vector(data_store, temperature_vector, temperature_ud)
    gas = set_gas_composition(gas, data_store, temperature_vector[0], pressure)

    current_property = data_store.get_data(DataKeys.REGRESSION_PROPERTY_TYPE)
    property_ud = data_store.get_data(DataKeys.REGRESSION_PROPERTY)[-1]

    values = calculate_property_vector(gas, uc, temperature_vector, pressure, current_property, property_ud)
    data_store = perform_regression(data_store, temperature_vector, values, property_ud)

    return data_store
