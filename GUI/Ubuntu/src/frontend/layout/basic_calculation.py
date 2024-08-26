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
        temperature_value = self.main_window.backend_frontend_manager.temperature["value"]
        temperature_ud = self.main_window.backend_frontend_manager.temperature["ud"]
        pressure_value = self.main_window.backend_frontend_manager.pressure["value"]
        pressure_ud = self.main_window.backend_frontend_manager.pressure["ud"]

        if len(self.main_window.backend_frontend_manager.mole_fraction) > 0:
            cl.set_temperature_pressure_and_mole_fraction(temperature_value,
                                                          temperature_ud,
                                                          pressure_value,
                                                          pressure_ud,
                                                          self.main_window.backend_frontend_manager.mole_fraction)

        if len(self.main_window.backend_frontend_manager.mass_fraction) > 0:
            cl.set_temperature_pressure_and_mass_fraction(temperature_value,
                                                          temperature_ud,
                                                          pressure_value,
                                                          pressure_ud,
                                                          self.main_window.backend_frontend_manager.mass_fraction)

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
    def create_layout_components(self):
        """
        Initialize the widgets
        Returns
        -------

        """
        pass

    @abstractmethod
    def generate_layout(self):
        """
        Update the interface
        Returns
        -------
        """
        pass
