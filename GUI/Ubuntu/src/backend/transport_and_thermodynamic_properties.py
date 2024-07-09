import cantera as ct
import numpy as np
from asali.utils.unit_converter import UnitConverter

from src.backend.default_input_handler import DefaultInputHandler


class TransportAndThermodynamicProperties:
    def __init__(self, cantera_input_file, gas_phase_name):
        """
        Class to get thermodynamic and transport properties from Cantera files
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

    def density(self, ud):
        """
        Return density of the mixture
        Parameters
        ----------
        ud: str
            Unit dimensions in human format
        Returns
        -------
        rho: float
            Gas mixture density
        """
        return self._uc.convert_from_kg_per_cubic_meter(self._gas.density,
                                                        DefaultInputHandler.from_human_to_code_ud(ud))

    def viscosity(self, ud):
        """
        Return viscosity of mixture
        Parameters
        ----------
        ud: str
            Unit dimensions in human format
        Returns
        -------
        mu: float
            Gas mixture viscosity
        """
        return self._uc.convert_from_pascal_seconds(self._gas.viscosity,
                                                    DefaultInputHandler.from_human_to_code_ud(ud))

    def molecular_weight(self, ud):
        """
        Return molecular weight of mixture
        Parameters
        ----------
        ud: str
            Unit dimensions in human format
        Returns
        -------
        mw: float
            Gas mixture molecular weight
        """
        return self._uc.convert_from_kg_per_kmol(self._gas.mean_molecular_weight,
                                                 DefaultInputHandler.from_human_to_code_ud(ud))

    def thermal_conductivity(self, ud):
        """
        Return thermal conductivity of mixture
        Parameters
        ----------
        ud: str
            Unit dimensions in human format
        Returns
        -------
        cond: float
            Gas mixture thermal conductivity
        """
        return self._uc.convert_from_watt_per_meter_per_kelvin(self._gas.thermal_conductivity,
                                                               DefaultInputHandler.from_human_to_code_ud(ud))

    def mixture_diffusivity(self, ud):
        """
        Return species mixture diffusivity of mixture
        Parameters
        ----------
        ud: str
            Unit dimensions in human format
        Returns
        -------
        diff_mix: dict
            Species mixture diffusivity
        """
        total_diff_mix = self._gas.mix_diff_coeffs_mass
        diff_mix_zero = total_diff_mix == 0
        total_diff_mix[diff_mix_zero] = self._gas.binary_diff_coeffs[diff_mix_zero, diff_mix_zero]

        diff_mask = np.logical_not(np.fabs(total_diff_mix * np.asarray(self._gas.Y)) < 1e-16)

        names = np.asarray(self._gas.species_names)[diff_mask]
        diff_mix = total_diff_mix[diff_mask]

        return dict(
            zip(names, [self._uc.convert_from_square_meter_per_seconds(d, DefaultInputHandler.from_human_to_code_ud(ud))
                        for d in diff_mix]))
