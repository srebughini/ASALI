################################################################################################
#                                                                                              #
#     #############       #############       #############       ####                ####     #
#    #             #     #             #     #             #     #    #              #    #    #
#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #
#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #
#    #    #####    #     #    #              #    #####    #     #    #              #    #    #
#    #             #     #    #########      #             #     #    #              #    #    #
#    #             #     #             #     #             #     #    #              #    #    #
#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #
#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #
#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #
#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #
#     ####     ####       #############       ####     ####       #############       ####     #
#                                                                                              #
#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #
#                                                                                              #
################################################################################################
#                                                                                              #
#   License                                                                                    #
#                                                                                              #
#   This file is part of ASALI.                                                                #
#                                                                                              #
#   ASALI is free software: you can redistribute it and/or modify                              #
#   it under the terms of the GNU General Public License as published by                       #
#   the Free Software Foundation, either version 3 of the License, or                          #
#   (at your option) any later version.                                                        #
#                                                                                              #
#   ASALI is distributed in the hope that it will be useful,                                   #
#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #
#   GNU General Public License for more details.                                               #
#                                                                                              #
#   You should have received a copy of the GNU General Public License                          #
#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #
#                                                                                              #
################################################################################################

import numpy as np
from transport import transport
from omega import omega11, omega22
from thermo import thermo


class Asali:
    def __init__(self, temperature, pressure):
        """
        Class to estimate gas mixture thermodynamic and transport properties
        :param temperature: Temperature of the gas mixture
        :param pressure: Pressure of the gas mixture
        """
        self._p = pressure
        self._T = temperature

        self._x = np.array([])
        self._y = np.array([])
        self._n = np.array([])
        self._mw = np.array([])
        self._mu = np.array([])
        self._cp_mole = np.array([])
        self._cp_mass = np.array([])
        self._h_mole = np.array([])
        self._h_mass = np.array([])
        self._s_mole = np.array([])
        self._s_mass = np.array([])
        self._diff = np.array([])
        self._diff_mix = np.array([])
        self._cond = np.array([])
        self._v = np.array([])
        self._l = np.array([])

        self._mw_mix = 0.0
        self._rho = 0.0
        self._mu_mix = 0.0
        self._cp_mole_mix = 0.0
        self._cp_mass_mix = 0.0
        self._h_mole_mix = 0.0
        self._h_mass_mix = 0.0
        self._s_mole_mix = 0.0
        self._cond_mix = 0.0

        self._mu_update_ = False
        self._diff_update_ = False
        self._rho_update_ = False
        self._cp_update_ = False
        self._h_update_ = False
        self._s_update_ = False
        self._cond_update_ = False
        self._v_update_ = False
        self._l_update_ = False
        self._mu_mix_update_ = False
        self._diff_mix_update_ = False
        self._cond_mix_update_ = False
        self._cp_mole_mix_update_ = False
        self._cp_mass_mix_update_ = False
        self._h_mole_mix_update_ = False
        self._h_mass_mix_update_ = False
        self._s_mole_mix_update_ = False

    def _refresh(self):
        """
        Reset all bools to avoid evaluating the same function multiple times
        :return:
        """
        self._mu_update_ = False
        self._diff_update_ = False
        self._rho_update_ = False
        self._cp_update_ = False
        self._h_update_ = False
        self._s_update_ = False
        self._cond_update_ = False
        self._v_update_ = False
        self._l_update_ = False
        self._mu_mix_update_ = False
        self._diff_mix_update_ = False
        self._cond_mix_update_ = False
        self._cp_mole_mix_update_ = False
        self._cp_mass_mix_update_ = False
        self._h_mole_mix_update_ = False
        self._h_mass_mix_update_ = False
        self._s_mole_mix_update_ = False

    @staticmethod
    def _extract_index_before_and_after(value, vector):
        """
        Extract index from a vector that are before and after the element
        :param value: Value to be searched
        :param vector: Vector
        :return: Index before, index after
        """
        idx_v = np.argmin(np.fabs(vector - value))

        if idx_v == vector.size - 1:
            return vector.size - 2, vector.size - 1

        if value >= vector[idx_v]:
            return idx_v, idx_v + 1

        return idx_v - 1, idx_v

    @staticmethod
    def _collision_integral(tr, dr, d, t, s):
        """
        Estimate the collision integral value
        :param tr: Dimensionless temperature
        :param dr: Dimensionless dipole
        :param d: Dipole range
        :param t: Temperature range
        :param s: Collision integral matrix
        :return: Collision integral value
        """
        da, db = Asali._extract_index_before_and_after(dr, d)
        ta, tb = Asali._extract_index_before_and_after(tr, t)

        b = [s[ta, da],
             s[ta, db],
             s[tb, da],
             s[tb, db]]

        x = [0.0] * 4
        x[3] = (b[0] - b[1] - b[2] + b[3]) / (t[ta] * d[da] - t[ta] * d[db] - t[tb] * d[da] + t[tb] * d[db])
        x[2] = (-x[3] * (t[ta] * d[da] - t[ta] * d[db]) - b[1] + b[0]) / (d[da] - d[db])
        x[1] = (-x[3] * (t[ta] * d[da] - t[tb] * d[da]) - b[2] + b[0]) / (t[ta] - t[tb])
        x[0] = -x[1] * t[ta] - x[2] * d[da] - x[3] * t[ta] * d[da] + b[0]

        return x[0] + x[1] * tr + x[2] * dr + x[3] * tr * dr

    @staticmethod
    def _collision_integral22(tr, dr):
        """
        Estimate the collision integral value
        :param tr: Dimensionless temperature
        :param dr: Dimensionless dipole
        :return: Collision integral value
        """
        return Asali._collision_integral(tr,
                                         dr,
                                         np.asarray(omega22["d"]),
                                         np.asarray(omega22["t"]),
                                         np.asarray(omega22["s"]))

    @staticmethod
    def _collision_integral11(tr, dr):
        """
        Estimate the collision integral value
        :param tr: Dimensionless temperature
        :param dr: Dimensionless dipole
        :return: Collision integral value
        """
        return Asali._collision_integral(tr,
                                         dr,
                                         np.asarray(omega11["d"]),
                                         np.asarray(omega11["t"]),
                                         np.asarray(omega11["s"]))

    def _density(self):
        """
        Estimate gas mixture density
        :return: Density in [kg/m3]
        """
        if not self._rho_update_:
            self._rho = self._mw_mix * self._p / (8314.0 * self._T)
            self._rho_update_ = True
        return self._rho

    def _species_viscosity(self):
        """
        Estimate species viscosity
        :return: Species viscosity in [Pas]
        """
        if not self._mu_update_:
            tp = [[transport[n].LJpotential, transport[n].LJdiameter, transport[n].dipole] for n in self._n]
            tp = np.asarray(tp)
            tr = self._T / tp[:, 0]
            dr = 1.0e06 * 0.5 * np.square(tp[:, 2]) / (tp[:, 0] * 1.3806488 * np.power(tp[:, 1], 3.))
            sigma = np.asarray([Asali._collision_integral22(tr[i], dr[i]) for i in range(0, len(self._n))])
            self._mu = 1.0e-05 * (5. / 16.) * np.sqrt(np.pi * 1.3806488 * self._T * self._mw * 1.66054) / (
                    np.pi * sigma * np.square(tp[:, 1]))
            self._mu_update_ = True
        return self._mu

    def _species_cp(self):
        """
        Estimate species specific heat
        :return: Species specific heat in [J/kmol/K], [J/kg/K]
        """
        if not self._cp_update_:
            if self._T < 1000.0:
                params = [thermo[n].low[:5] for n in self._n]
            else:
                params = [thermo[n].high[:5] for n in self._n]

            params = np.asarray(params)
            values = [params[:, i] * np.power(self._T, i) for i in [1, 2, 3, 4]]
            values = np.asarray(values)

            self._cp_mole = (params[:, 0] + np.sum(values, axis=0)) * 8314.0
            self._cp_mass = self._cp_mole / self._mw

            self._cp_update_ = True
        return self._cp_mole, self._cp_mass

    def _species_h(self):
        """
        Estimate species enthalpy
        :return: Species enthalpy in [J/kmol], [J/kg]
        """
        if not self._h_update_:
            if self._T < 1000.0:
                params = [thermo[n].low[:6] for n in self._n]
            else:
                params = [thermo[n].high[:6] for n in self._n]

            params = np.asarray(params)
            values = [params[:, i] * np.power(self._T, i) / (i + 1) for i in [1, 2, 3, 4]]
            values = np.asarray(values)

            self._h_mole = (params[:, 0] + params[:, 5] / self._T + np.sum(values, axis=0)) * 8314.0 * self._T
            self._h_mass = self._h_mole / self._mw

            self._h_update_ = True
        return self._h_mole, self._h_mass

    def _species_s(self):
        """
        Estimate species entropy
        :return: Species entropy in [J/kmol/K], [J/kg/K]
        """
        if not self._s_update_:
            if self._T < 1000.0:
                params = [thermo[n].low[:7] for n in self._n]
            else:
                params = [thermo[n].high[:7] for n in self._n]

            params = np.asarray(params)
            values = [params[:, i] * np.power(self._T, i) / (i) for i in [1, 2, 3, 4]]
            values = np.asarray(values)

            self._s_mole = 8314.0 * (params[:, 0] * np.log(self._T) + params[:, 6] + np.sum(values, axis=0) - np.log(
                self._p * self._x / 1.0e05))
            self._s_mass = self._s_mole / self._mw

            self._s_update_ = True
        return self._s_mole, self._s_mass

    def _binary_diffusion(self):
        """
        Estimate binary diffusion coefficient
        :return: Species binary diffusion coefficient in [m2/s]
        """
        if not self._diff_update_:
            self._diff = np.zeros([self.number_of_species, self.number_of_species], dtype=float)

            LJpotentialmix = np.zeros_like(self._diff)
            LJdiametermix = np.zeros_like(self._diff)
            dipolemix = np.zeros_like(self._diff)
            mwmix = np.zeros_like(self._diff)
            polarn = np.zeros_like(self._diff)
            dipolep = np.zeros_like(self._diff)
            chi = np.zeros_like(self._diff)

            transport_matrix = [
                [transport[n].polar, transport[n].dipole, transport[n].LJpotential, transport[n].LJdiameter] for n
                in self.species_name]

            transport_matrix = np.asarray(transport_matrix)

            polar_vector = transport_matrix[:, 0]
            dipole_vector = transport_matrix[:, 1]
            LJpotential_vector = transport_matrix[:, 2]
            LJdiameter_vector = transport_matrix[:, 3]

            # Create indices for all elements of the matrices
            row, col = np.indices((self.number_of_species, self.number_of_species))

            # Calculate values based on vectorized operations
            LJpotentialmix[row, col] = np.sqrt(LJpotential_vector[row] * LJpotential_vector[col])
            LJdiametermix[row, col] = 0.5 * (LJdiameter_vector[row] + LJdiameter_vector[col])
            dipolemix[row, col] = np.sqrt(dipole_vector[row] * dipole_vector[col])
            mwmix[row, col] = self._mw[row] * self._mw[col] / (self._mw[row] + self._mw[col])

            # Condition 1
            p_mask_1 = np.logical_and((polar_vector[:, None] == 0.0), (polar_vector[None, :] == 0.0))

            # Condition 2
            p_mask_2 = np.logical_and((polar_vector[:, None] > 0.0), (polar_vector[None, :] > 0.0))

            # Condition 3
            p_mask_3 = np.logical_and((polar_vector[:, None] == 0.0), (polar_vector[None, :] > 0.0))
            polarn[row, col] = polar_vector[row] / np.power(LJdiameter_vector[row], 3.)
            dipolep[row, col] = 1e02 * dipole_vector[col] / np.sqrt(
                LJpotential_vector[col] * 1.3806488 * np.power(LJdiameter_vector[col], 3.))
            chi[row, col] = 1. + 0.25 * polarn[row, col] * dipolep[row, col] * np.sqrt(
                LJpotential_vector[col] / LJpotential_vector[row])
            LJpotentialmix[p_mask_3] = np.square(chi[p_mask_3]) * LJpotentialmix[p_mask_3]
            LJdiametermix[p_mask_3] = LJdiametermix[p_mask_3] * np.power(chi[p_mask_3], -1. / 6.)
            dipolemix[p_mask_3] = 0.0

            # Condition 4
            p_mask_4 = np.logical_not(np.logical_or(p_mask_1, np.logical_or(p_mask_2, p_mask_3)))
            polarn[row, col] = polar_vector[col] / np.power(LJdiameter_vector[col], 3.)
            dipolep[row, col] = 1e02 * dipole_vector[row] / np.sqrt(
                LJpotential_vector[row] * 1.3806488 * np.power(LJdiameter_vector[col], 3.))
            chi[row, col] = 1. + 0.25 * polarn[row, col] * dipolep[row, col] * np.sqrt(
                LJpotential_vector[row] / LJpotential_vector[col])
            LJpotentialmix[p_mask_4] = np.square(chi[p_mask_4]) * LJpotentialmix[p_mask_4]
            LJdiametermix[p_mask_4] = LJdiametermix[p_mask_4] * np.power(chi[p_mask_4], -1. / 6.)
            dipolemix[p_mask_4] = 0.0

            tr = self._T / LJpotentialmix
            dr = 1e06 * 0.5 * np.square(dipolemix) / (LJpotentialmix * 1.3806488 * np.power(LJdiametermix, 3.))

            vectorized_collision_integral11 = np.vectorize(Asali._collision_integral11)

            sigma = vectorized_collision_integral11(tr, dr)

            self._diff = 0.1 * (3. / 16.) * np.sqrt(
                2. * np.pi * np.power(1.3806488 * self._T, 3.) / (mwmix * 1.66054)) / (
                                 self._p * np.pi * np.square(LJdiametermix) * sigma)

            self._diff_update_ = True
        return self._diff

    def _species_cond(self):
        """
        :return: Species thermal conductivity [W/m/K]
        """
        if not self._cond_update_:
            self._species_viscosity()
            self._binary_diffusion()
            self._density()
            self._species_cp()

            r = 8314.  # [J/Kmol/K]

            transport_matrix = [[transport[n].geometry, transport[n].collision, transport[n].LJpotential] for n in
                                self.species_name]

            transport_matrix = np.asarray(transport_matrix)

            geometry_vector = transport_matrix[:, 0]
            collision_vector = transport_matrix[:, 1]
            LJpotential_vector = transport_matrix[:, 2]

            cvtrans = 3. * r * 0.5 * np.ones_like(geometry_vector)
            cvrot = 3. * r * 0.5 * np.ones_like(geometry_vector)
            cvvib = self._cp_mole - r - 3. * r

            single_atom_mask = geometry_vector == 0
            cvtrans[single_atom_mask] = 3. * r * 0.5
            cvrot[single_atom_mask] = 0.0
            cvvib[single_atom_mask] = 0.0

            linear_mask = geometry_vector == 1
            cvtrans[linear_mask] = 3. * r * 0.5
            cvrot[linear_mask] = r
            cvvib[linear_mask] = self._cp_mole[linear_mask] - r - 5. * r * 0.5

            rho = self._p * self._mw / (r * self._T)

            a = (5. / 2.) - rho * self._diff.diagonal() / self._mu

            def f(t):
                return 1. + 0.5 * np.sqrt(np.power(np.pi, 3.) * LJpotential_vector / t) + (
                        0.25 * np.square(np.pi) + 2.) * (LJpotential_vector / t) + np.sqrt(
                    np.power(np.pi * LJpotential_vector / t, 3.))

            z_rot = collision_vector * f(298.0) / f(self._T)

            b = z_rot + (2. / np.pi) * ((5. / 3.) * (cvrot / r) + rho * self._diff.diagonal() / self._mu)

            ftrans = (5. / 2.) * (1. - 2. * cvrot * a / (np.pi * cvtrans * b))
            frot = (rho * self._diff.diagonal() / self._mu) * (1. + 2. * a / (np.pi * b))
            fvib = rho * self._diff.diagonal() / self._mu

            self._cond = self._mu * (ftrans * cvtrans + frot * cvrot + fvib * cvvib) / self._mw
            self._cond_update_ = True

        return self._cond

    @staticmethod
    def _mole_fraction_to_mass_fraction(x, mw):
        """
        Convert mole fraction to mass fraction
        :param x: Mole fraction
        :param mw: Molecular weight
        :return: Mass fraction, Mixture molecular weight
        """
        mw_mix = np.sum(x * mw)
        return x * mw / mw_mix, mw_mix

    @staticmethod
    def _mass_fraction_to_mole_fraction(y, mw):
        """
        Convert mass fraction to mole fraction
        :param x: Mass fraction
        :param mw: Molecular weight
        :return: Mole fraction, Mixture molecular weight
        """
        mw_mix = np.sum(y / mw)
        return (y / mw) / mw_mix, 1. / mw_mix

    @property
    def temperature(self):
        """
        Property function to return the gas mixture temperature
        :return:
        """
        return self._T

    @temperature.setter
    def temperature(self, new_temperature):
        """
        Setter function to set the gas mixture temperature
        :param new_temperature: Temperature of the gas mixture
        :return:
        """
        if new_temperature > 0 and isinstance(new_temperature, float):
            self._refresh()
            self._T = new_temperature
        else:
            raise Exception("ASALI::ERROR::Wrong temperature")

    @property
    def pressure(self):
        """
        Property function to return the gas mixture pressure
        :return:
        """
        return self._p

    @pressure.setter
    def pressure(self, new_pressure):
        """
        Setter function to set the gas mixture pressure
        :param new_pressure: Pressure of the gas mixture
        :return:
        """
        if new_pressure > 0 and isinstance(new_pressure, float):
            self._refresh()
            self._p = new_pressure
        else:
            raise Exception("ASALI::ERROR::Wrong pressure")

    @property
    def species_name(self):
        """
        Property function to return the gas mixture specie names
        :return:
        """
        return self._n

    @species_name.setter
    def species_name(self, new_specie_names):
        """
        Setter function to set the gas mixture specie names
        :param new_specie_names: Species names as list
        :return:
        """
        if isinstance(new_specie_names, list) or isinstance(new_specie_names, np.ndarray):
            self._refresh()
            self._n = np.asarray(new_specie_names)
            self._mw = np.asarray([transport[n].MW for n in self._n])
        else:
            raise Exception("ASALI::ERROR::Wrong specie names")

    @property
    def mass_fraction(self):
        """
        Property function to return the gas mixture mass fraction
        :return:
        """
        return self._y

    @mass_fraction.setter
    def mass_fraction(self, new_mass_fraction):
        """
        Setter function to set the gas mixture mass fraction
        :param new_mass_fraction: Mass fraction of the gas mixture
        :return:
        """
        if np.fabs(np.sum(new_mass_fraction) - 1.0) < 1e-16:
            self._refresh()
            self._y = np.asarray(new_mass_fraction)
            if len(self._y) == len(self._n):
                self._x, self._mw_mix = Asali._mass_fraction_to_mole_fraction(self._y, self._mw)
            else:
                raise Exception("ASALI::ERROR::Wrong number of species in mass fraction")
        else:
            raise Exception("ASALI::ERROR::Mass fraction != 1")

    @property
    def mole_fraction(self):
        """
        Property function to return the gas mixture mass fraction
        :return:
        """
        return self._x

    @mole_fraction.setter
    def mole_fraction(self, new_mole_fraction):
        """
        Setter function to set the gas mixture mass fraction
        :param new_mole_fraction: Mole fraction of the gas mixture
        :return:
        """
        if np.fabs(np.sum(new_mole_fraction) - 1.0) < 1e-16:
            self._refresh()
            self._x = np.asarray(new_mole_fraction)
            if len(self._x) == len(self._n):
                self._y, self._mw_mix = Asali._mole_fraction_to_mass_fraction(self._x, self._mw)
            else:
                raise Exception("ASALI::ERROR::Wrong number of species in mole fraction")
        else:
            raise Exception("ASALI::ERROR::Mole fraction != 1")

    @property
    def mass_composition(self):
        """
        Property function to return the gas mixture mass composition
        :return:
        """
        return dict(zip(self._n, self._y))

    @mass_composition.setter
    def mass_composition(self, new_mass_composition):
        """
        Setter function to set the gas mixture mass composition
        :param new_mass_composition: Mass composition as dict of the gas mixture
        :return:
        """
        n = list(new_mass_composition.keys())
        y = list(new_mass_composition.values())
        self.species_name = n
        self.mass_fraction = y

    @property
    def mole_composition(self):
        """
        Property function to return the gas mixture mole composition
        :return:
        """
        return dict(zip(self._n, self._x))

    @mole_composition.setter
    def mole_composition(self, new_mole_composition):
        """
        Setter function to set the gas mixture mole composition
        :param new_mole_composition: Mole composition as dict of the gas mixture
        :return:
        """
        n = list(new_mole_composition.keys())
        x = list(new_mole_composition.values())
        self.species_name = n
        self.mole_fraction = x

    @property
    def number_of_species(self):
        """
        :return: Number of species
        """
        return len(self._n)

    @property
    def species_molecular_weight(self):
        """
        :return: Species molecular weight [kg/kmol]
        """
        return self._mw

    @property
    def species_viscosity(self):
        """
        :return: Species viscosity [Pas]
        """
        self._species_viscosity()
        return self._mu

    @property
    def species_molar_specific_heat(self):
        """
        :return: Species specific heat [J/kmol/K]
        """
        self._species_cp()
        return self._cp_mole

    @property
    def species_mass_specific_heat(self):
        """
        :return: Species specific heat [J/kg/K]
        """
        self._species_cp()
        return self._cp_mass

    @property
    def species_molar_enthalpy(self):
        """
        :return: Species enthalpy [J/kmol]
        """
        self._species_h()
        return self._h_mole

    @property
    def species_mass_enthalpy(self):
        """
        :return: Species enthalpy [J/kg]
        """
        self._species_h()
        return self._h_mass

    @property
    def species_molar_entropy(self):
        """
        :return: Species entropy [J/kmol/K]
        """
        self._species_s()
        return self._s_mole

    @property
    def species_mass_entropy(self):
        """
        :return: Species entropy [J/kg/K]
        """
        self._species_s()
        return self._s_mass

    @property
    def species_binary_diffusion(self):
        """
        :return: Species binary diffusion [m2/s]
        """
        self._binary_diffusion()
        return self._diff

    @property
    def species_thermal_conductivity(self):
        """
        :return: Species thermal conductivity [W/m/K]
        """
        self._species_cond()
        return self._cond

    @property
    def density(self):
        """
        :return: Mixture density [kg/m3]
        """
        self._density()
        return self._rho

    @property
    def arithmetic_mean_gas_velocity(self):
        """
        :return: Arithmetic mean gas velocity [m/s]
        """
        if not self._v_update_:
            self._v = np.sqrt(8. * 8314. * self._T / (np.pi * self._mw))
            self._v_update_ = True
        return self._v

    @property
    def mean_free_path(self):
        """
        :return: Mean free path [m]
        """
        if not self._l_update_:
            self._l = np.sqrt(8. * 8314. * self._T / (np.pi * self._mw))
            self._l = np.asarray(
                [1.38064852 * 1e-03 * self._T / (np.sqrt(2) * self._p * np.square(transport[n].LJdiameter)) for n in
                 self.species_name])
            self._l_update_ = True
        return self._l

    @property
    def mixture_molecular_weight(self):
        """
        :return: Mixture molecular weight [kg/kmol]
        """
        return self._mw_mix

    @property
    def mixture_viscosity(self):
        """
        :return: Mixture viscosity [Pas]
        """
        if not self._mu_mix_update_:
            self._species_viscosity()

            mw_matrix = np.zeros([self.number_of_species, self.number_of_species], dtype=float)
            mu_matrix = np.zeros([self.number_of_species, self.number_of_species], dtype=float)
            row, col = np.indices((self.number_of_species, self.number_of_species))

            mw_matrix[row, col] = self._mw[row] / self._mw[col]
            mu_matrix[row, col] = self._mu[row] / self._mu[col]

            phi = (1. / np.sqrt(8.)) * (1. / np.sqrt(1. + mw_matrix)) * np.square(
                1. + np.sqrt(mu_matrix) * np.power(mw_matrix.T, (1. / 4.)))

            self._mu_mix = np.sum(self._x * self._mu / np.sum(phi * self._x[np.newaxis, :], axis=1))
            self._mu_mix_update_ = True

        return self._mu_mix

    @property
    def mixture_diffusion(self):
        """
        :return: Mixture diffusion coefficient [m2/s]
        """
        if not self._diff_mix_update_:
            self._binary_diffusion()
            a = np.sum(self._x * self._mw) - self._x * self._mw
            b = np.sum(self._x[:, None] / self._diff, axis=0) - self._x / self._diff.diagonal()
            self._diff_mix = a / (self._mw_mix * b)
            self._diff_mix_update_ = True

        return self._diff_mix

    @property
    def mixture_molar_specific_heat(self):
        """
        :return: Mixture specific heat [J/kmol/K]
        """
        if not self._cp_mole_mix_update_:
            self._species_cp()
            self._cp_mole_mix = np.sum(self._cp_mole * self._x)
            self._cp_mole_mix_update_ = True

        return self._cp_mole_mix

    @property
    def mixture_mass_specific_heat(self):
        """
        :return: Mixture specific heat [J/kg/K]
        """
        if not self._cp_mass_mix_update_:
            self._species_cp()
            self._cp_mass_mix = np.sum(self._cp_mass * self._y)
            self._cp_mass_mix_update_ = True

        return self._cp_mass_mix

    @property
    def mixture_molar_enthalpy(self):
        """
        :return: Mixture enthalpy [J/kmol]
        """
        if not self._h_mole_mix_update_:
            self._species_h()
            self._h_mole_mix = np.sum(self._h_mole * self._x)
            self._h_mole_mix_update_ = True

        return self._h_mole_mix

    @property
    def mixture_mass_enthalpy(self):
        """
        :return: Mixture enthalpy [J/kg]
        """
        if not self._h_mass_mix_update_:
            self._species_h()
            self._h_mass_mix = np.sum(self._h_mass * self._y)
            self._h_mass_mix_update_ = True

        return self._h_mass_mix

    @property
    def mixture_molar_entropy(self):
        """
        :return: Mixture entropy [J/kmol/K]
        """
        if not self._s_mole_mix_update_:
            self._species_s()
            self._s_mole_mix = np.sum(self._s_mole * self._x)
            self._s_mole_mix_update_ = True

        return self._s_mole_mix

    @property
    def mixture_mass_entropy(self):
        """
        :return: Mixture entropy [J/kmol/K]
        """
        return self.mixture_molar_entropy / self._mw_mix

    @property
    def mixture_thermal_conductivity(self):
        """
        :return: Mixture thermal conductivity [W/m/K]
        """
        if not self._cond_mix_update_:
            self._cond_mix = 0.5 * (np.sum(self._x * self._cond) + 1. / np.sum(self._x / self._cond))

        return self._cond_mix
