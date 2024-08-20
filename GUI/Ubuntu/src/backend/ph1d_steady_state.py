import numpy as np
import pandas as pd

from asali.reactors.ph1d_steady_state import SteadyStatePseudoHomogeneous1DReactor

from src.backend.basic_reactor import BasicReactor
from src.frontend.style import SheetNames, ColumnNames, ReactorVariablesName


class SteadyStatePseudoHomogeneous1DReactorModel(BasicReactor):
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
                                 surface_phase_name) -> SteadyStatePseudoHomogeneous1DReactor:
        """
        Initialize SteadyStatePseudoHomogeneous1DReactor class
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
        return SteadyStatePseudoHomogeneous1DReactor(cantera_input_file, gas_phase_name, surface_phase_name)

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
        if input_dict[ReactorVariablesName.udk] is not None:
            self.reactor_class.set_user_defined_kinetic_model(input_dict[ReactorVariablesName.udk])
        else:
            self.reactor_class.set_initial_coverage(input_dict[ReactorVariablesName.z])

        L = self._uc.convert_to_meter(input_dict[ReactorVariablesName.length].value,
                                      input_dict[ReactorVariablesName.length].ud)

        dL = self._uc.convert_to_meter(input_dict[ReactorVariablesName.lengthStep].value,
                                       input_dict[ReactorVariablesName.lengthStep].ud)

        num = int(L / dL) + 1

        length = np.linspace(0., L, num=num, endpoint=True)

        self.reactor_class.set_length(length, self.lengthUd)

        self.reactor_class.set_diameter(input_dict[ReactorVariablesName.diameter].value,
                                        input_dict[ReactorVariablesName.diameter].ud)
        self.reactor_class.set_pressure(input_dict[ReactorVariablesName.pressure].value,
                                        input_dict[ReactorVariablesName.pressure].ud)
        self.reactor_class.set_catalytic_load(input_dict[ReactorVariablesName.alfa].value,
                                              input_dict[ReactorVariablesName.alfa].ud)
        self.reactor_class.set_mass_flow_rate(input_dict[ReactorVariablesName.massFlowRate].value,
                                              input_dict[ReactorVariablesName.massFlowRate].ud)

        if input_dict[ReactorVariablesName.x] is not None:
            self.reactor_class.set_inlet_mole_fraction(input_dict[ReactorVariablesName.x])

        if input_dict[ReactorVariablesName.y] is not None:
            self.reactor_class.set_inlet_mass_fraction(input_dict[ReactorVariablesName.y])

        self.reactor_class.set_inlet_temperature(input_dict[ReactorVariablesName.temperature].value,
                                                 input_dict[ReactorVariablesName.temperature].ud)
        self.reactor_class.set_energy(input_dict[ReactorVariablesName.energy])

        self.reactor_class.set_inert_specie(input_dict[ReactorVariablesName.inertSpecie])
        self.reactor_class.set_inert_coverage(input_dict[ReactorVariablesName.inertCoverage])
        self.reactor_class.set_gas_diffusion(input_dict[ReactorVariablesName.diffusion])

        self.reactor_class.solve()

    def get_results(self) -> dict:
        """
        Save the results of the reactor model
        Returns
        -------
        output_dict: dict
            Dict of Pandas DataFrame to be plotted
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
