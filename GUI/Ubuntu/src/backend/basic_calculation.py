from abc import ABC

import cantera as ct
import numpy as np

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
        self._species_names = list()

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
        self._species_names = list(mass_fraction.keys())
        self._gas.TPY = T, P, mass_fraction
        self._species_mask = np.asarray([True if s in self._species_names else False for s in self._gas.species_names])

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
        self._species_names = list(mole_fraction.keys())
        self._gas.TPX = T, P, mole_fraction
        self._species_mask = np.asarray([True if s in self._species_names else False for s in self._gas.species_names])

    def species_names(self):
        """
        Return species names
        Returns
        -------
        n: list
            Species names
        """
        return self._species_names

    def mole_fraction(self):
        """
        Return mole Fraction
        Returns
        -------
        x: dict
            Mole Fraction
        """
        x = np.asarray(self._gas.X)
        return dict(zip(self._species_names, x[self._species_mask]))

    def mass_fraction(self):
        """
        Return mass Fraction
        Returns
        -------
        y: dict
            Mass Fraction
        """
        y = np.asarray(self._gas.Y)
        return dict(zip(self._species_names, y[self._species_mask]))

    def temperature(self, ud):
        """
        Return temperature
        Parameters
        ----------
        ud: str
            Unit dimensions in human format
        Returns
        -------
        T: float
            Temperature
        """
        return self._uc.convert_to_kelvin(self._gas.T, DefaultInputHandler.from_human_to_code_ud(ud))

    def pressure(self, ud):
        """
        Return pressure
        Parameters
        ----------
        ud: str
            Unit dimensions in human format
        Returns
        -------
        P: float
            Pressure
        """
        return self._uc.convert_to_pascal(self._gas.P, DefaultInputHandler.from_human_to_code_ud(ud))

    def specie_index(self, specie_name):
        """
        Return specie index from specie name
        Parameters
        ----------
        specie_name: str
            Single specie name

        Returns
        -------
        specie_idx: int
            Single specie index
        """
        return self._species_names.index(specie_name)
