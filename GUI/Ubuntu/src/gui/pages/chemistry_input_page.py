from PyQt5.QtCore import pyqtSignal
from PyQt5.QtWidgets import QWidget, QPushButton, QComboBox, QFileDialog, QGridLayout
from PyQt5 import uic

from src.core.data_keys import DataKeys
from src.gui.config import Config
from src.gui.pages.basic_page import BasicPage


class ChemistryInputPage(BasicPage):
    def __init__(self, data_store):
        """
        Chemistry input page layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        """
        super().__init__(data_store)
        # Load the UI from the .ui file
        uic.loadUi(Config.CHEMISTRY_INPUT_PAGE_PATH.value, self)
        self.update_buttons()
        self.update_grid_layout()

    def update_buttons(self):
        """
        Update buttons
        Returns
        -------

        """
        nextButton = self.findChild(QPushButton, 'nextButton')

        # Emit signal to switch pages
        nextButton.clicked.connect(self.next_button_action)

    def next_button_action(self):
        """
        Action related to the next button
        Returns
        -------
        signal: pyqtSignal
            Signal with the next page name
        """
        comboBox = self.findChild(QComboBox, 'chemistryComboBox')

        if comboBox.currentIndex() == 0:
            # Load Cantera
            file_path, _ = QFileDialog.getOpenFileName(self,
                                                       "Open Cantera Input File",
                                                       "",
                                                       "Cantera Files (*.yaml);;All Files (*)")
            if file_path:  # Check if a file was selected
                # Save the file path in the DataStore
                self.data_store.update_data(DataKeys.CHEMISTRY_FILE_PATH.value,
                                            file_path)
                return self.page_switched.emit(Config.CALCULATION_INPUT_PAGE_NAME.value)

        elif comboBox.currentIndex() == 1:
            # Use default input file
            # Here you can define the default input file path if needed
            default_file_path = "path/to/default/file"  # Replace with actual path
            self.data_store.update_data(DataKeys.CHEMISTRY_FILE_PATH.value,
                                        Config.DEFAULT_CHEMISTRY_FILE_PATH.value)
            return self.page_switched.emit(Config.CALCULATION_INPUT_PAGE_NAME.value)

        elif comboBox.currentIndex() == 2:
            # Chemikin to Cantera
            return self.page_switched.emit("TO DO")
        elif comboBox.currentIndex() == 3:
            # Asali user-defined kinetic model check
            return self.page_switched.emit("TO DO")
