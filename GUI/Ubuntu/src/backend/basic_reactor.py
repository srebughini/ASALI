from abc import ABC, abstractmethod

from asali.plotters.reactor import ReactorPlotter
from asali.utils.unit_converter import UnitConverter


class BasicReactor(ABC):
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
        self._uc = UnitConverter()
        self.reactor_class = self.initialize_reactor_class(cantera_input_file,
                                                           gas_phase_name,
                                                           surface_phase_name)
        self.colormap = "Blues"
        self.timeUd = "s"
        self.lengthUd = "m"

    @abstractmethod
    def initialize_reactor_class(self,
                                 cantera_input_file,
                                 gas_phase_name,
                                 surface_phase_name) -> None:
        """
        Abstract method to initialize reactor class
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
        return None

    @abstractmethod
    def run(self, input_dict) -> None:
        """
        Abstract method to run reactor model
        Parameters
        ----------
        input_dict: dict
            Input parameters
        Returns
        -------

        """
        pass

    @abstractmethod
    def get_results(self) -> dict:
        """
        Abstract method to save the results of the reactor model
        Returns
        -------
        output_dict: dict
            Dict of Pandas DataFrame to be plotted
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
        plotter = ReactorPlotter(self.reactor_class, colormap=self.colormap)

        if plot_dict["T"]:
            plotter.plot_temperature()

        if len(plot_dict["x"]) > 0:
            plotter.plot_species_mole_fraction(plot_dict["x"])

        if len(plot_dict["y"]) > 0:
            plotter.plot_species_mass_fraction(plot_dict["y"])

        if len(plot_dict["z"]) > 0:
            plotter.plot_coverage(plot_dict["z"])

        plotter.show()

    def gas_species_list(self) -> list:
        """
        Return gas species list
        Returns
        -------
        gas_species_names: list
            List of gas species names
        """
        return self.reactor_class.gas.species_names

    def coverage_list(self) -> list:
        """
        Return coverage list
        Returns
        -------
        coverage_names: list
            List of coverage names
        """
        return self.reactor_class.surf.species_names
