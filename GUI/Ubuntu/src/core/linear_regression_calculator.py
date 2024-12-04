import cantera as ct
import numpy as np

from asali.utils.unit_converter import UnitConverter

from src.core.composition_type import CompositionType
from src.core.data_keys import DataKeys
from src.core.data_store import DataStore
from src.core.unit_dimension_handler import UnitDimensionHandler

from scipy import stats


def linear_regression_calculator(data_store) -> DataStore:
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
    pressure_tuple = data_store.get_data(DataKeys.INLET_P)
    pressure = uc.convert_to_pascal(pressure_tuple[0],
                                    UnitDimensionHandler.from_human_to_code_ud(pressure_tuple[1]))

    min_temperature_tuple = data_store.get_data(DataKeys.MIN_TEMPERATURE)
    min_temperature = uc.convert_to_kelvin(min_temperature_tuple[0],
                                           UnitDimensionHandler.from_human_to_code_ud(min_temperature_tuple[1]))

    max_temperature_tuple = data_store.get_data(DataKeys.MAX_TEMPERATURE)
    max_temperature = uc.convert_to_kelvin(max_temperature_tuple[0],
                                           UnitDimensionHandler.from_human_to_code_ud(max_temperature_tuple[1]))

    temperature_vector = np.linspace(min_temperature, max_temperature, num=50, endpoint=True)
    data_store.update_data(DataKeys.TEMPERATURE_VECTOR, temperature_vector)

    rho = np.zeros_like(temperature_vector, dtype=np.float64)
    mu = np.zeros_like(temperature_vector, dtype=np.float64)
    cond = np.zeros_like(temperature_vector, dtype=np.float64)
    cp_mole = np.zeros_like(temperature_vector, dtype=np.float64)
    cp_mass = np.zeros_like(temperature_vector, dtype=np.float64)
    h_mole = np.zeros_like(temperature_vector, dtype=np.float64)
    h_mass = np.zeros_like(temperature_vector, dtype=np.float64)
    s_mole = np.zeros_like(temperature_vector, dtype=np.float64)
    s_mass = np.zeros_like(temperature_vector, dtype=np.float64)

    composition_tuple = data_store.get_data(DataKeys.INLET_GAS_COMPOSITION)
    if composition_tuple[1] == CompositionType.MOLE:
        gas.TPX = temperature_vector[0], pressure, composition_tuple[0]
    else:
        gas.TPY = temperature_vector[0], pressure, composition_tuple[0]

    for i, temperature in enumerate(temperature_vector):
        gas.TP = temperature, pressure
        rho[i] = gas.density
        mu[i] = gas.viscosity
        cond[i] = gas.thermal_conductivity
        cp_mole[i] = gas.cp_mole
        cp_mass[i] = gas.cp_mass
        h_mole[i] = gas.enthalpy_mole
        h_mass[i] = gas.enthalpy_mass
        s_mole[i] = gas.entropy_mole
        s_mass[i] = gas.entropy_mass

    # Density
    ud = data_store.get_data(DataKeys.RHO)[1]
    rho = uc.convert_from_kg_per_cubic_meter(rho, UnitDimensionHandler.from_human_to_code_ud(ud))

    a, b, _, _, _ = stats.linregress(temperature_vector, rho)

    data_store.update_data(DataKeys.RHO_VECTOR, rho)
    data_store.update_data(DataKeys.RHO, (a, b, ud))

    # Viscosity
    ud = data_store.get_data(DataKeys.MU)[1]
    mu = uc.convert_from_pascal_seconds(mu, UnitDimensionHandler.from_human_to_code_ud(ud))

    a, b, _, _, _ = stats.linregress(temperature_vector, mu)

    data_store.update_data(DataKeys.MU_VECTOR, mu)
    data_store.update_data(DataKeys.MU, (a, b, ud))

    # Thermal conductivity
    ud = data_store.get_data(DataKeys.COND)[1]
    cond = uc.convert_from_watt_per_meter_per_kelvin(cond, UnitDimensionHandler.from_human_to_code_ud(ud))

    a, b, _, _, _ = stats.linregress(temperature_vector, cond)

    data_store.update_data(DataKeys.COND_VECTOR, cond)
    data_store.update_data(DataKeys.COND, (a, b, ud))

    # Specific heat
    ud = data_store.get_data(DataKeys.CP)[1]
    if 'mol' in ud.lower():
        cp = uc.convert_from_joule_per_kmol_per_kelvin(cp_mole, UnitDimensionHandler.from_human_to_code_ud(ud))
    else:
        cp = uc.convert_from_joule_per_kg_per_kelvin(cp_mass, UnitDimensionHandler.from_human_to_code_ud(ud))

    a, b, _, _, _ = stats.linregress(temperature_vector, cp)

    data_store.update_data(DataKeys.CP_VECTOR, cp)
    data_store.update_data(DataKeys.CP, (a, b, ud))

    # Enthalpy
    ud = data_store.get_data(DataKeys.H)[1]
    if 'mol' in ud.lower():
        h = uc.convert_from_joule_per_kmol_per_kelvin(h_mole, UnitDimensionHandler.from_human_to_code_ud(ud))
    else:
        h = uc.convert_from_joule_per_kg_per_kelvin(h_mass, UnitDimensionHandler.from_human_to_code_ud(ud))

    a, b, _, _, _ = stats.linregress(temperature_vector, h)

    data_store.update_data(DataKeys.H_VECTOR, h)
    data_store.update_data(DataKeys.H, (a, b, ud))

    # Entropy
    ud = data_store.get_data(DataKeys.S)[1]
    if 'mol' in ud.lower():
        s = uc.convert_from_joule_per_kmol_per_kelvin(s_mole, UnitDimensionHandler.from_human_to_code_ud(ud))
    else:
        s = uc.convert_from_joule_per_kg_per_kelvin(s_mass, UnitDimensionHandler.from_human_to_code_ud(ud))

    a, b, _, _, _ = stats.linregress(temperature_vector, s)

    data_store.update_data(DataKeys.S_VECTOR, s)
    data_store.update_data(DataKeys.S, (a, b, ud))
    return data_store
