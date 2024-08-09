from abc import abstractmethod
from PyQt5.QtWidgets import QMainWindow, QLabel
from src.frontend.layout.basic import BasicLayout
from src.frontend.utils import Utils


class BasicCalculationLayout(BasicLayout):
    def __init__(self, main_window):
        """
        Abstract class for properties and reactors layouts
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        super().__init__(main_window)

    def _set_gas_mixture_user_input(self, cl):
        """
        Set gas mixture input composition, temperature and pressure
        Returns
        -------
        """
        temperature_value = self.main_window.userInput.temperature["value"]
        temperature_ud = self.main_window.userInput.temperature["ud"]
        pressure_value = self.main_window.userInput.pressure["value"]
        pressure_ud = self.main_window.userInput.pressure["ud"]

        if len(self.main_window.userInput.mole_fraction) > 0:
            cl.set_temperature_pressure_and_mole_fraction(temperature_value,
                                                          temperature_ud,
                                                          pressure_value,
                                                          pressure_ud,
                                                          self.main_window.userInput.mole_fraction)

        if len(self.main_window.userInput.mass_fraction) > 0:
            cl.set_temperature_pressure_and_mass_fraction(temperature_value,
                                                          temperature_ud,
                                                          pressure_value,
                                                          pressure_ud,
                                                          self.main_window.userInput.mass_fraction)

        return cl

    @abstractmethod
    def run_backend(self):
        """
        Run backend to update frontend
        Returns
        -------

        """
        pass

    @abstractmethod
    def initialize(self):
        """
        Initialize the widgets
        Returns
        -------

        """
        pass

    @abstractmethod
    def create(self):
        """
        Update the interface
        Returns
        -------
        """
        pass
