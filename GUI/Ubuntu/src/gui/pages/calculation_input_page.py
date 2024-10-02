from PyQt5.QtCore import pyqtSignal
from PyQt5.QtWidgets import QWidget, QLabel, QPushButton
from PyQt5 import uic

from src.core.data_keys import DataKeys
from src.gui.config import Config


class CalculationInputPage(QWidget):
    page_switched = pyqtSignal(str)  # Signal to switch pages

    def __init__(self, data_store):
        """
        Calculation input page layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        """
        super().__init__()
        # Load the UI from the .ui file
        uic.loadUi(Config.CALCULATION_INPUT_PAGE_PATH.value, self)

        self.data_store = data_store

        label = self.findChild(QLabel, "testLabel")
        label.setText(self.data_store.get_data(DataKeys.CHEMISTRY_FILE_PATH.value))

        self.update_buttons()

    def update_buttons(self):
        """
        Update buttons
        Returns
        -------

        """
        backButton = self.findChild(QPushButton, 'backButton')

        # Emit signal to switch pages
        backButton.clicked.connect(lambda: self.page_switched.emit(Config.CHEMISTRY_INPUT_PAGE_NAME.value))
