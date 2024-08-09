from abc import ABC, abstractmethod

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

    @abstractmethod
    def plot(self, plot_dict) -> None:
        """
        Abstract method to plot the results of the reactor model
        Parameters
        ----------
        plot_dict: dict
            Option parameters for plotting

        Returns
        -------

        """
        pass

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
