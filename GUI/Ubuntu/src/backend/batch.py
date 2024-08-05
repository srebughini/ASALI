import numpy as np
from asali.plotters.reactor import ReactorPlotter
from asali.reactors.batch import BatchReactor

from src.backend.basic_reactor import BasicReactor


class BatchModel(BasicReactor):
    def __init__(self, cantera_input_file, gas_phase_name, surface_phase_name):
        """
        Basic class for reactor calculation
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
                                 surface_phase_name):
        """
        Method to initialize BatchReactor class
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

    def run(self, input_dict):
        """
        Run BatchReactor model
        Parameters
        ----------
        input_dict: dict
            Input parameters
        Returns
        -------

        """

        print(input_dict)

        if input_dict["udk"] is not None:
            self.r.set_user_defined_kinetic_model(input_dict["udk_file_path"])
        self.r.set_volume(input_dict["V"]["value"], input_dict["V"]["ud"])
        self.r.set_pressure(input_dict["P"]["value"], input_dict["P"]["ud"])
        self.r.set_catalytic_load(input_dict["alfa"]["value"], input_dict["alfa"]["ud"])

        if input_dict["x"] is not None:
            self.r.set_initial_mole_fraction(input_dict["x"])

        if input_dict["y"] is not None:
            self.r.set_initial_mass_fraction(input_dict["y"])

        self.r.set_initial_temperature(input_dict["T"]["value"], input_dict["T"]["ud"])
        self.r.set_energy(input_dict["energy"])

        tmax = self._uc.convert_to_seconds(input_dict["time"]["value"],
                                           input_dict["time"]["ud"])

        tstep = self._uc.convert_to_seconds(input_dict["step"]["value"],
                                            input_dict["step"]["ud"])

        num = int(tmax/tstep) + 1

        tspan = np.linspace(0., tmax, num=num, endpoint=True)

        self.r.solve(tspan, 's')

        plt = ReactorPlotter(self.r)
        plt.plot_species_mass_fraction(['H2', 'H2O', 'O2'])
        plt.plot_species_mole_fraction(['H2', 'H2O', 'O2'])
        plt.plot_temperature()
        plt.show()
