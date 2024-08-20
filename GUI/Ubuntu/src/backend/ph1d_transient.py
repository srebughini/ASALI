import numpy as np
import pandas as pd

from asali.reactors.ph1d_transient import TransientPseudoHomogeneous1DReactor

from src.backend.basic_reactor import BasicReactor
from src.frontend.style import SheetNames, ColumnNames


class TransientPseudoHomogeneous1DReactorModel(BasicReactor):
    def __init__(self, cantera_input_file, gas_phase_name, surface_phase_name):
        """
        Steady state pseudo-homogeneous 1D reactor model
        Parameters
        ----------
        cantera_input_file: str
            Cantera input file path
        gas_phase_name: str
            Gas phase name
        surface_phase_name: str
            Surface phase name
        """
        super().__init__(cantera_input_file, gas_phase_name, surface_phase_name)

    def initialize_reactor_class(self,
                                 cantera_input_file,
                                 gas_phase_name,
                                 surface_phase_name) -> TransientPseudoHomogeneous1DReactor:
        """
        Initialize TransientPseudoHomogeneous1DReactor class
        Parameters
        ----------
        cantera_input_file: str
            Cantera input file path
        gas_phase_name: str
            Gas phase name
        surface_phase_name: str
            Surface phase name

        Returns
        -------
        r: object
            ASALI reactor class
        """
        return TransientPseudoHomogeneous1DReactor(cantera_input_file, gas_phase_name, surface_phase_name)

    def run(self, input_dict) -> None:
        """
        Run CstrReactor model
        Parameters
        ----------
        input_dict: dict
            Input parameters
        Returns
        -------

        """

        pass

        """
        if input_dict["udk"] is not None:
            self.reactor_class.set_user_defined_kinetic_model(input_dict["udk"])
        else:
            self.reactor_class.set_initial_coverage(input_dict["theta"])

        L = self._uc.convert_to_meter(input_dict["L"]["value"],
                                      input_dict["L"]["ud"])

        dL = self._uc.convert_to_meter(input_dict["dL"]["value"],
                                       input_dict["dL"]["ud"])

        num = int(L / dL) + 1

        length = np.linspace(0., L, num=num, endpoint=True)

        self.reactor_class.set_length(length, 'm')

        self.reactor_class.set_diameter(input_dict["D"]["value"], input_dict["D"]["ud"])
        self.reactor_class.set_pressure(input_dict["P"]["value"], input_dict["P"]["ud"])
        self.reactor_class.set_catalytic_load(input_dict["alfa"]["value"], input_dict["alfa"]["ud"])
        self.reactor_class.set_mass_flow_rate(input_dict["q"]["value"], input_dict["q"]["ud"])

        if input_dict["x"] is not None:
            self.reactor_class.set_initial_mole_fraction(input_dict["x"])

        if input_dict["y"] is not None:
            self.reactor_class.set_initial_mass_fraction(input_dict["y"])

        if input_dict["x_in"] is not None:
            self.reactor_class.set_inlet_mole_fraction(input_dict["x_in"])

        if input_dict["y_in"] is not None:
            self.reactor_class.set_inlet_mass_fraction(input_dict["y_in"])

        self.reactor_class.set_initial_temperature(input_dict["T"]["value"], input_dict["T"]["ud"])
        self.reactor_class.set_inlet_temperature(input_dict["T_in"]["value"], input_dict["T_in"]["ud"])
        self.reactor_class.set_energy(input_dict["energy"])
        self.reactor_class.set_inert_specie(input_dict["inert"]["specie"])
        self.reactor_class.set_inert_coverage(input_dict["inert"]["coverage"])
        self.reactor_class.set_gas_diffusion(input_dict["diffusion"])

        tmax = self._uc.convert_to_seconds(input_dict["time"]["value"],
                                           input_dict["time"]["ud"])

        tstep = self._uc.convert_to_seconds(input_dict["step"]["value"],
                                            input_dict["step"]["ud"])

        num = int(tmax / tstep) + 1

        tspan = np.linspace(0., tmax, num=num, endpoint=True)

        self.reactor_class.solve(tspan, 's')
        """

    def get_results(self) -> dict:
        """
        Save the results of the reactor model
        Returns
        -------
        output_dict: dict
            Dict of Pandas DataFrame to be plotted
        """

        """
        x = self.reactor_class.get_mole_fraction()
        y = self.reactor_class.get_mass_fraction()
        z = self.reactor_class.get_coverage()
        l = self.reactor_class.get_length(self.lengthUd)

        output_dict = {SheetNames.X.value: pd.DataFrame({ColumnNames.length.value: l}),
                       SheetNames.Y.value: pd.DataFrame({ColumnNames.length.value: l}),
                       SheetNames.Z.value: pd.DataFrame({ColumnNames.length.value: l}),
                       SheetNames.T.value: pd.DataFrame({ColumnNames.length.value: l})}

        for i, n in enumerate(self.gas_species_list()):
            output_dict[SheetNames.X.value][n] = x[:, i]
            output_dict[SheetNames.Y.value][n] = y[:, i]

        for i, n in enumerate(self.coverage_list()):
            output_dict[SheetNames.Z.value][n] = z[:, i]

        output_dict[SheetNames.T.value][ColumnNames.temperature.value] = self.reactor_class.get_temperature()

        return output_dict
        """
        return {}
