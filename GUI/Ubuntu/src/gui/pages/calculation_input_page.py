from PyQt5.QtCore import pyqtSignal, Qt
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import QWidget, QPushButton, QGridLayout, QLineEdit, QComboBox
from PyQt5 import uic, QtWidgets

from src.gui.config import Config
from src.gui.pages.basic_page import BasicPage


class CalculationInputPage(BasicPage):
    def __init__(self, data_store):
        """
        Calculation input page layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        """
        super().__init__(data_store)
        # Load the UI from the .ui file
        uic.loadUi(Config.CALCULATION_INPUT_PAGE_PATH.value, self)
        self.update_temperature_line()
        self.update_pressure_line()
        self.update_buttons()
        self.update_grid_layout()

    def update_temperature_line(self):
        """
        Update temperature input line
        Returns
        -------

        """
        edit_line = self.findChild(QLineEdit, 'temperatureEditLine')
        edit_line.setValidator(QDoubleValidator(0.0, 3000.0, 2))
        edit_line.setAlignment(Qt.AlignRight)

        dropdown = self.findChild(QComboBox, 'temperatureComboBox')
        dropdown.addItems(self.ud_handler.temperature_ud)

    def update_pressure_line(self):
        """
        Update pressure input line
        Returns
        -------

        """
        edit_line = self.findChild(QLineEdit, 'pressureEditLine')
        edit_line.setValidator(QDoubleValidator(0.0, 1e09, 2))
        edit_line.setAlignment(Qt.AlignRight)

        dropdown = self.findChild(QComboBox, 'pressureComboBox')
        dropdown.addItems(self.ud_handler.pressure_ud)

    def update_buttons(self):
        """
        Update buttons
        Returns
        -------

        """
        backButton = self.findChild(QPushButton, 'backButton')

        # Emit signal to switch pages
        backButton.clicked.connect(lambda: self.page_switched.emit(Config.CHEMISTRY_INPUT_PAGE_NAME.value))
