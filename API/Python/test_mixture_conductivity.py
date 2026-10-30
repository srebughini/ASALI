"""Public API call-order regressions; no experimental-accuracy claim.

Run from API/Python: python -m unittest -v test_mixture_conductivity.py
"""
import unittest
import numpy as np
from asali import Asali


def mixture(temperature=373.15):
    gas = Asali(temperature, 4e5)
    gas.mole_composition = {'H2': 0.1, 'O2': 0.2, 'N2': 0.7}
    return gas


def explicit_species_first(gas):
    k = gas.species_thermal_conductivity
    x = gas.mole_fraction
    return 0.5 * (np.sum(x * k) + 1.0 / np.sum(x / k))


class MixtureConductivityTests(unittest.TestCase):
    def assert_conductivity(self, actual, expected):
        self.assertTrue(np.isfinite(actual) and actual > 0)
        np.testing.assert_allclose(actual, expected, rtol=1e-12, atol=0)

    def test_direct_first_read(self):
        self.assert_conductivity(mixture().mixture_thermal_conductivity,
                                 explicit_species_first(mixture()))

    def test_temperature_change(self):
        gas = mixture()
        explicit_species_first(gas)
        _ = gas.mixture_thermal_conductivity
        gas.temperature = 500.0
        self.assert_conductivity(gas.mixture_thermal_conductivity,
                                 explicit_species_first(mixture(500.0)))

    def test_species_order_change(self):
        gas = mixture()
        explicit_species_first(gas)
        _ = gas.mixture_thermal_conductivity
        gas.mole_composition = {'N2': 0.7, 'H2': 0.1, 'O2': 0.2}
        self.assert_conductivity(gas.mixture_thermal_conductivity,
                                 explicit_species_first(mixture()))

    def test_species_count_change(self):
        gas = mixture()
        explicit_species_first(gas)
        _ = gas.mixture_thermal_conductivity
        gas.mole_composition = {'O2': 0.2, 'N2': 0.8}
        fresh = mixture()
        fresh.mole_composition = {'O2': 0.2, 'N2': 0.8}
        self.assert_conductivity(gas.mixture_thermal_conductivity,
                                 explicit_species_first(fresh))

    def test_existing_species_first_path(self):
        gas = mixture()
        expected = explicit_species_first(gas)
        self.assert_conductivity(gas.mixture_thermal_conductivity, expected)
        self.assert_conductivity(gas.mixture_thermal_conductivity, expected)

    def test_fraction_only_change(self):
        gas = mixture()
        explicit_species_first(gas)
        _ = gas.mixture_thermal_conductivity
        gas.mole_fraction = [0.2, 0.2, 0.6]
        fresh = mixture()
        fresh.mole_fraction = [0.2, 0.2, 0.6]
        self.assert_conductivity(gas.mixture_thermal_conductivity,
                                 explicit_species_first(fresh))


if __name__ == '__main__':
    unittest.main()
