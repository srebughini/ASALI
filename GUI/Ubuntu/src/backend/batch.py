import numpy as np
import pandas as pd

from asali.reactors.batch import BatchReactor

from src.backend.basic_reactor import BasicReactor
from src.frontend.style import SheetNames, ColumnNames, ReactorVariablesName


class BatchModel(BasicReactor):
    def __init__(self, cantera_input_file, gas_phase_name, surface_phase_name):
        """
        Batch reactor model
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
                                 surface_phase_name) -> BatchReactor:
        """
        Initialize BatchReactor class
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
        return BatchReactor(cantera_input_file, gas_phase_name, surface_phase_name)

    def run(self, input_dict) -> None:
        """
        Run BatchReactor model
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

        self.reactor_class.set_volume(input_dict[ReactorVariablesName.volume].value,
                                      input_dict[ReactorVariablesName.volume].ud)
        self.reactor_class.set_pressure(input_dict[ReactorVariablesName.pressure].value,
                                        input_dict[ReactorVariablesName.pressure].ud)
        self.reactor_class.set_catalytic_load(input_dict[ReactorVariablesName.alfa].value,
                                              input_dict[ReactorVariablesName.alfa].ud)

        if input_dict[ReactorVariablesName.initialX] is not None:
            self.reactor_class.set_initial_mole_fraction(input_dict[ReactorVariablesName.initialX])

        if input_dict[ReactorVariablesName.initialY] is not None:
            self.reactor_class.set_initial_mass_fraction(input_dict[ReactorVariablesName.initialY])

        self.reactor_class.set_initial_temperature(input_dict[ReactorVariablesName.initialTemperature].value,
                                                   input_dict[ReactorVariablesName.initialTemperature].ud)
        self.reactor_class.set_energy(input_dict[ReactorVariablesName.energy])

        tmax = self._uc.convert_to_seconds(input_dict[ReactorVariablesName.time].value,
                                           input_dict[ReactorVariablesName.time].ud)

        tstep = self._uc.convert_to_seconds(input_dict[ReactorVariablesName.timeStep].value,
                                            input_dict[ReactorVariablesName.timeStep].ud)

        num = int(tmax / tstep) + 1

        tspan = np.linspace(0., tmax, num=num, endpoint=True)

        self.reactor_class.solve(tspan, self.timeUd)

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
        t = self.reactor_class.get_time(self.timeUd)

        output_dict = {SheetNames.X.value: pd.DataFrame({ColumnNames.time.value: t}),
                       SheetNames.Y.value: pd.DataFrame({ColumnNames.time.value: t}),
                       SheetNames.Z.value: pd.DataFrame({ColumnNames.time.value: t}),
                       SheetNames.T.value: pd.DataFrame({ColumnNames.time.value: t})}

        for i, n in enumerate(self.gas_species_list()):
            output_dict[SheetNames.X.value][n] = x[:, i]
            output_dict[SheetNames.Y.value][n] = y[:, i]

        for i, n in enumerate(self.coverage_list()):
            output_dict[SheetNames.Z.value][n] = z[:, i]

        output_dict[SheetNames.T.value][ColumnNames.temperature.value] = self.reactor_class.get_temperature()

        return output_dict
