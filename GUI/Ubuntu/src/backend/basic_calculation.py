from abc import ABC

import cantera as ct
from asali.utils.unit_converter import UnitConverter

from src.backend.default_input_handler import DefaultInputHandler


class BasicCalculation(ABC):
    def __init__(self, cantera_input_file, gas_phase_name):
        """
        Basic class for those classes for calculations
        Parameters
        ----------
        cantera_input_file: str
            Cantera input file path
        gas_phase_name: str
            Gas phase name
        """
        self._gas = ct.Solution(cantera_input_file, gas_phase_name)
        self._uc = UnitConverter()

    def set_temperature_pressure_and_mass_fraction(self,
                                                   temperature,
                                                   temperature_ud,
                                                   pressure,
                                                   pressure_ud,
                                                   mass_fraction):
        """
        Set temperature, pressure and mass fraction of the gas mixture
        Parameters
        ----------
        temperature: float
            Temperature
        temperature_ud: str
            Temperature unit dimensions
        pressure: float
            Pressure
        pressure_ud: str
            Pressure unit dimensions
        mass_fraction: dict
            mass fraction

        Returns
        -------
        """
        T = self._uc.convert_to_kelvin(temperature, DefaultInputHandler.from_human_to_code_ud(temperature_ud))
        P = self._uc.convert_to_pascal(pressure, DefaultInputHandler.from_human_to_code_ud(pressure_ud))
        self._gas.TPY = T, P, mass_fraction

    def set_temperature_pressure_and_mole_fraction(self,
                                                   temperature,
                                                   temperature_ud,
                                                   pressure,
                                                   pressure_ud,
                                                   mole_fraction):
        """
        Set temperature, pressure and mole fraction of the gas mixture
        Parameters
        ----------
        temperature: float
            Temperature
        temperature_ud: str
            Temperature unit dimensions
        pressure: float
            Pressure
        pressure_ud: str
            Pressure unit dimensions
        mole_fraction: dict
            mole fraction

        Returns
        -------
        """
        T = self._uc.convert_to_kelvin(temperature, DefaultInputHandler.from_human_to_code_ud(temperature_ud))
        P = self._uc.convert_to_pascal(pressure, DefaultInputHandler.from_human_to_code_ud(pressure_ud))
        self._gas.TPX = T, P, mole_fraction