import cantera as ct
import numpy as np

from asali.utils.unit_converter import UnitConverter

from src.gui.enums.composition_type import CompositionType
from src.core.data_keys import DataKeys
from src.core.data_store import DataStore
from src.core.unit_dimension_handler import UnitDimensionHandler
from src.gui.enums.reactor_type import ReactorType


def pressure_drops_calculator(data_store) -> DataStore:
    """
    Function to estimate pressure drops
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
    reactor_type = data_store.get_data(DataKeys.REACTOR_TYPE)

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

    length_tuple = data_store.get_data(DataKeys.DP_LENGTH)
    length = uc.convert_to_meter(length_tuple[0],
                                 UnitDimensionHandler.from_human_to_code_ud(length_tuple[1]))

    if ReactorType.HONEYCOMB == reactor_type:
        cpsi = data_store.get_data(DataKeys.DP_CPSI)

        tw_tuple = data_store.get_data(DataKeys.DP_WALL_THICKNESS)
        tw = uc.convert_to_meter(tw_tuple[0],
                                 UnitDimensionHandler.from_human_to_code_ud(tw_tuple[1]))

        v_tuple = data_store.get_data(DataKeys.DP_VELOCITY)
        v = uc.convert_to_meter_per_seconds(v_tuple[0],
                                            UnitDimensionHandler.from_human_to_code_ud(v_tuple[1]))

        dc = np.sqrt(1. / cpsi) * 2.54 * 1e-02 - tw  # m
        epsi = np.square(dc) / np.square(dc + tw)
        v = v / epsi
        reynolds = v * gas.density * dc / gas.viscosity

        if reynolds < 2100.:
            f = 16. / reynolds
        else:
            f = 0.0791 / np.power(reynolds, 0.25)

        ud = data_store.get_data(DataKeys.PRESSURE_DROPS)[1]
        value = uc.convert_from_pascal(2.0 * f * gas.density * v * v * length / dc,
                                       UnitDimensionHandler.from_human_to_code_ud(ud))

        data_store.update_data(DataKeys.PRESSURE_DROPS, (value, ud))
        return data_store

    if ReactorType.PACKED_BED == reactor_type:
        v_tuple = data_store.get_data(DataKeys.DP_VELOCITY)
        v = uc.convert_to_meter_per_seconds(v_tuple[0],
                                            UnitDimensionHandler.from_human_to_code_ud(v_tuple[1]))

        dp_tuple = data_store.get_data(DataKeys.DP_PARTICLE_DIAMETER)
        dp = uc.convert_to_meter(dp_tuple[0], UnitDimensionHandler.from_human_to_code_ud(dp_tuple[1]))

        epsi = data_store.get_data(DataKeys.DP_VOID_FRACTION)

        G = gas.density * v

        # Ergun
        pressure_drops = (150. * (1. - epsi) / (dp * G / gas.viscosity) + 7. / 4.) * (1. - epsi) * np.square(G) / (
                    np.power(epsi, 3.) * gas.density * dp)

        ud = data_store.get_data(DataKeys.PRESSURE_DROPS)[1]
        value = uc.convert_from_pascal(pressure_drops,
                                       UnitDimensionHandler.from_human_to_code_ud(ud))

        data_store.update_data(DataKeys.PRESSURE_DROPS, (value, ud))
        return data_store

    if ReactorType.TUBULAR == reactor_type:
        tw_tuple = data_store.get_data(DataKeys.DP_WALL_THICKNESS)
        tw = uc.convert_to_meter(tw_tuple[0],
                                 UnitDimensionHandler.from_human_to_code_ud(tw_tuple[1]))

        v_tuple = data_store.get_data(DataKeys.DP_VELOCITY)
        v = uc.convert_to_meter_per_seconds(v_tuple[0],
                                            UnitDimensionHandler.from_human_to_code_ud(v_tuple[1]))

        dt_tuple = data_store.get_data(DataKeys.DP_TUBE_DIAMETER)
        dt = uc.convert_to_meter(dt_tuple[0], UnitDimensionHandler.from_human_to_code_ud(dt_tuple[1]))

        reynolds = v * gas.density * (dt - 2.0 * tw) / gas.viscosity

        if reynolds < 2100:
            f = 16. / reynolds
        else:
            f = 0.0791 / np.power(reynolds, 0.25)

        ud = data_store.get_data(DataKeys.PRESSURE_DROPS)[1]
        value = uc.convert_from_pascal(2.0 * f * gas.density * v * v * length / (dt - 2.0 * tw),
                                       UnitDimensionHandler.from_human_to_code_ud(ud))

        data_store.update_data(DataKeys.PRESSURE_DROPS, (value, ud))
        return data_store

    return data_store
