from PyQt5.QtWidgets import (
    QMainWindow
)

from src.backend.transport_and_thermodynamic_properties import TransportAndThermodynamicProperties
from src.frontend.layout.calculated_basic_layout import CalculatedBasicLayout


class TransportAndThermodynamicPropertiesLayout(CalculatedBasicLayout):
    def __init__(self, main_window):
        """
        Transport and thermodynamic properties
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        super().__init__(main_window)

    def run_backend(self):
        """
        Run backend to update frontend
        Returns
        -------

        """
        self.properties = TransportAndThermodynamicProperties(self.main_window.userInput.file_path,
                                                              self.main_window.userInput.gas_phase_name)

    def initialize(self):
        """
        Initialize the widgets
        Returns
        -------

        """

    def create(self):
        """
        Update the interface
        Returns
        -------
        """
        pass
