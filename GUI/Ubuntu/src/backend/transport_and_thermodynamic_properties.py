from src.backend.basic_calculation import BasicCalculation
from src.backend.default_input_handler import DefaultInputHandler


class TransportAndThermodynamicProperties(BasicCalculation):
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
        super().__init__(cantera_input_file, gas_phase_name)

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

        diff_mix = total_diff_mix[self._species_mask]

        return dict(zip(self._species_names,
                        [self._uc.convert_from_square_meter_per_seconds(d,
                                                                        DefaultInputHandler.from_human_to_code_ud(ud))
                         for d in diff_mix]))

    def specific_heat(self, ud):
        """
        Return specific heat of mixture
        Parameters
        ----------
        ud: str
            Unit dimensions in human format
        Returns
        -------
        cp: float
            Gas mixture specific heat
        """
        if 'mol' in ud.lower():
            return self._uc.convert_from_joule_per_kmol_per_kelvin(self._gas.cp_mole,
                                                                   DefaultInputHandler.from_human_to_code_ud(ud))

        return self._uc.convert_from_joule_per_kg_per_kelvin(self._gas.cp_mass,
                                                             DefaultInputHandler.from_human_to_code_ud(ud))

    def enthalpy(self, ud):
        """
        Return enthalpy of mixture
        Parameters
        ----------
        ud: str
            Unit dimensions in human format
        Returns
        -------
        cp: float
            Gas mixture enthalpy
        """
        if 'mol' in ud.lower():
            return self._uc.convert_from_joule_per_kmol_per_kelvin(self._gas.enthalpy_mole,
                                                                   DefaultInputHandler.from_human_to_code_ud(ud))

        return self._uc.convert_from_joule_per_kg_per_kelvin(self._gas.enthalpy_mass,
                                                             DefaultInputHandler.from_human_to_code_ud(ud))

    def entropy(self, ud):
        """
        Return entropy of mixture
        Parameters
        ----------
        ud: str
            Unit dimensions in human format
        Returns
        -------
        cp: float
            Gas mixture entropy
        """
        if 'mol' in ud.lower():
            return self._uc.convert_from_joule_per_kmol_per_kelvin(self._gas.entropy_mole,
                                                                   DefaultInputHandler.from_human_to_code_ud(ud))

        return self._uc.convert_from_joule_per_kg_per_kelvin(self._gas.entropy_mass,
                                                             DefaultInputHandler.from_human_to_code_ud(ud))
