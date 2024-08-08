import numpy as np
import matplotlib.pyplot as plt

from asali.plotters.batch import BatchPlotter
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
        if input_dict["udk"] is not None:
            self.reactor_class.set_user_defined_kinetic_model(input_dict["udk"])
        else:
            self.reactor_class.set_initial_coverage(input_dict["z"])
        self.reactor_class.set_volume(input_dict["V"]["value"], input_dict["V"]["ud"])
        self.reactor_class.set_pressure(input_dict["P"]["value"], input_dict["P"]["ud"])
        self.reactor_class.set_catalytic_load(input_dict["alfa"]["value"], input_dict["alfa"]["ud"])

        if input_dict["x"] is not None:
            self.reactor_class.set_initial_mole_fraction(input_dict["x"])

        if input_dict["y"] is not None:
            self.reactor_class.set_initial_mass_fraction(input_dict["y"])

        self.reactor_class.set_initial_temperature(input_dict["T"]["value"], input_dict["T"]["ud"])
        self.reactor_class.set_energy(input_dict["energy"])

        tmax = self._uc.convert_to_seconds(input_dict["time"]["value"],
                                           input_dict["time"]["ud"])

        tstep = self._uc.convert_to_seconds(input_dict["step"]["value"],
                                            input_dict["step"]["ud"])

        num = int(tmax / tstep) + 1

        tspan = np.linspace(0., tmax, num=num, endpoint=True)

        self.reactor_class.solve(tspan, 's')

    def save(self, option_dict) -> None:
        """
        Save the results of the reactor model
        Parameters
        ----------
        option_dict: dict
            Option parameters for saving

        Returns
        -------

        """
        pass

    def plot(self, plot_dict) -> None:
        """
        Plot the results of the reactor model
        Parameters
        ----------
        plot_dict: dict
            Option parameters for plotting

        Returns
        -------

        """
        plotter = BatchPlotter(self.reactor_class, colormap=self.colormap)

        if plot_dict["T"]:
            plotter.plot_temperature(plt)

        if len(plot_dict["x"]) > 0:
            plotter.plot_species_mole_fraction(plt, plot_dict["x"])

        if len(plot_dict["y"]) > 0:
            plotter.plot_species_mass_fraction(plt, plot_dict["y"])

        if len(plot_dict["z"]) > 0:
            plotter.plot_species_mass_fraction(plt, plot_dict["z"])

        plt.show()
