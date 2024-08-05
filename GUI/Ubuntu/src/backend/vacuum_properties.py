from src.backend.basic_calculation import BasicCalculation

import numpy as np

from src.backend.default_input_handler import DefaultInputHandler


class VacuumProperties(BasicCalculation):
    def __init__(self, cantera_input_file, gas_phase_name):
        """
        Class to get vacuum properties from Cantera files
        Parameters
        ----------
        cantera_input_file: str
            Cantera input file path
        gas_phase_name: str
            Gas phase name
        """
        super().__init__(cantera_input_file, gas_phase_name)

    @staticmethod
    def calculate_mean_gas_velocity(temp, mw):
        """
        Calculate mean gas velocity
        Parameters
        ----------
        temp: float
            Temperature in K
        mw: float
            Molecular weight

        Returns
        -------
        v: float
            Mean gas velocity in m/s
        """
        return np.sqrt(8. * 8314. * temp / (np.pi * mw))

    @staticmethod
    def calculate_mean_free_path(temp, press, ljdiameter):
        """
        Calculate mean free path
        Parameters
        ----------
        temp: float
            Temperature in K
        press: float
            Pressure in Pa
        ljdiameter: float
            Lennard-Jones diameter

        Returns
        -------
        l: float
            Mean free path in m
        """
        return 1.38064852 * 1e-03 * temp / (np.sqrt(2) * press * np.square(ljdiameter))

    @staticmethod
    def calculate_knudsen_number(temp, press, ljdiameter, length):
        """
        Calculate mean free path
        Parameters
        ----------
        temp: float
            Temperature in K
        press: float
            Pressure in Pa
        ljdiameter: float
            Lennard-Jones diameter
        length: float
            Characteristic length in m

        Returns
        -------
        kn: float
            Knudsen number
        """
        return length / VacuumProperties.calculate_mean_free_path(temp, press, ljdiameter)

    def mean_gas_velocity(self, specie_name, ud):
        """
        Return mean gas velocity of the single specie
        Parameters
        ----------
        specie_name: str
            Specie name
        ud: str
            Unit dimensions in human format
        Returns
        -------
        v: float
            Mean gas velocity
        """
        idx = self.specie_index(specie_name)
        v = VacuumProperties.calculate_mean_gas_velocity(self._gas.T, self._gas.molecular_weights[idx])

        return self._uc.convert_from_meter_per_seconds(v,
                                                       DefaultInputHandler.from_human_to_code_ud(ud))

    def mean_free_path(self, specie_name, ud):
        """
        Return mean free path of the single specie
        Parameters
        ----------
        specie_name: str
            Specie name
        ud: str
            Unit dimensions in human format
        Returns
        -------
        l: float
            Mean free path
        """
        idx = self.specie_index(specie_name)
        l = VacuumProperties.calculate_mean_free_path(self._gas.T, self._gas.P, 10.)  # TODO

        return self._uc.convert_from_meter(l,
                                           DefaultInputHandler.from_human_to_code_ud(ud))

    def knudsen_number(self, specie_name, length, length_ud):
        """
        Return Knudsen number of the single specie
        Parameters
        ----------
        specie_name: str
            Specie name
        length: float
            Characteristic length
        length_ud: str
            Characteristic length unit dimensions in human format
        Returns
        -------
        kn: float
            Knudsen number
        """
        idx = self.specie_index(specie_name)
        kn = VacuumProperties.calculate_knudsen_number(self._gas.T,
                                                       self._gas.P,
                                                       10.,  # TODO
                                                       self._uc.convert_to_meter(length,
                                                                                 DefaultInputHandler.from_human_to_code_ud(
                                                                                     length_ud)))

        return kn

    def diffusivity(self, specie_name, ud, length, length_ud):
        """
        Return diffusivity single specie
        Parameters
        ----------
        specie_name: str
            Specie name
        ud: str
            Unit dimensions in human format
        length: float
            Characteristic length
        length_ud: str
            Characteristic length unit dimensions in human format
        Returns
        -------
        diff: float
            Diffusivity
        """
        idx = self.specie_index(specie_name)
        d = self._uc.convert_to_meter(length, DefaultInputHandler.from_human_to_code_ud(length_ud))
        kn = VacuumProperties.calculate_knudsen_number(self._gas.T,
                                                       self._gas.P,
                                                       10.,
                                                       d)

        if kn < 1:
            v = VacuumProperties.calculate_mean_gas_velocity(self._gas.T, self._gas.molecular_weights[idx])
            return v * d / 3.0

        total_diff_mix = self._gas.mix_diff_coeffs_mass
        diff_mix_zero = total_diff_mix == 0
        total_diff_mix[diff_mix_zero] = self._gas.binary_diff_coeffs[diff_mix_zero, diff_mix_zero]
        diff_mix = total_diff_mix[self._species_mask]

        return self._uc.convert_from_square_meter_per_seconds(diff_mix[idx],
                                                              DefaultInputHandler.from_human_to_code_ud(ud))
