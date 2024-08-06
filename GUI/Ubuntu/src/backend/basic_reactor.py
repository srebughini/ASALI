from abc import ABC, abstractmethod

from asali.utils.unit_converter import UnitConverter
from asali.plotters.reactor import ReactorPlotter


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
    @abstractmethod
    def initialize_reactor_class(self,
                                 cantera_input_file,
                                 gas_phase_name,
                                 surface_phase_name):
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
    def run(self, input_dict):
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
    def save(self, option_dict):
        """
        Abstract method to save the results of the reactor model
        Parameters
        ----------
        option_dict: dict
            Option parameters for saving

        Returns
        -------

        """
        pass

    @abstractmethod
    def plot(self, plot_dict):
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
