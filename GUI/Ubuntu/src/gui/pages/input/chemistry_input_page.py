from PyQt5.QtCore import pyqtSignal
from PyQt5.QtWidgets import QPushButton, QComboBox, QFileDialog, QSizePolicy
from PyQt5 import uic

from src.controllers.input_file_controller import InputFileController
from src.core.data_keys import DataKeys
from src.gui.config import Config
from src.gui.pages.basic_page import BasicPage


class ChemistryInputPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Chemistry input page layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        uic.loadUi(Config.CHEMISTRY_INPUT_PAGE_PATH.value, self)
        self.update_buttons()
        self.update_grid_layout()

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.update_grid_layout()

    def update_data_store(self, file_path, is_default) -> None:
        """
        Update data store with file path, gas phase name and surface phase name
        Parameters
        ----------
        file_path: str
            Cantera file path
        is_default: bool
            If True the file path is the default one, if False is a user one

        Returns
        -------

        """
        # Save file path in the DataStore
        self.data_store.update_data(DataKeys.CHEMISTRY_FILE_PATH.value,
                                    file_path)

        # Save check in the DataStore
        self.data_store.update_data(DataKeys.IS_DEFAULT_FILE_PATH.value, is_default)

        # Save the gas phase name in the DataStore
        self.data_store.update_data(DataKeys.GAS_PHASE_NAME.value,
                                    InputFileController.extract_gas_phase_name_from_cantera(file_path))

        # Save the gas phase name in the DataStore
        self.data_store.update_data(DataKeys.SURFACE_PHASE_NAME.value,
                                    InputFileController.extract_surface_phase_name_from_cantera(file_path))

        # Set bools for properties evaluation
        self.data_store.update_data(DataKeys.GAS_SPECIES_NAMES_UPDATE.value, True)
        self.data_store.update_data(DataKeys.SURFACE_SPECIES_NAMES_UPDATE.value, True)

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        next_button = self.findChild(QPushButton, 'nextButton')
        next_button.clicked.connect(self.next_button_action)

    def next_button_action(self) -> pyqtSignal:
        """
        Action related to the next button
        Returns
        -------
        signal: pyqtSignal
            Signal with the next page name
        """
        combo_box = self.findChild(QComboBox, 'chemistryComboBox')

        if combo_box.currentIndex() == 0:
            # Load Cantera
            file_path = self.dialog_handler.load_file("Open Cantera Input File", Config.CANTERA_FILE_TYPE.value)
            if file_path:  # Check if a file was selected
                if InputFileController.check_cantera_input_file(file_path):
                    # Save data in DataStore
                    self.update_data_store(file_path, False)
                    return self.page_switched.emit(Config.CALCULATION_INPUT_PAGE_NAME.value)

        elif combo_box.currentIndex() == 1:
            # Save data in DataStore
            self.update_data_store(Config.DEFAULT_CHEMISTRY_FILE_PATH.value, True)
            return self.page_switched.emit(Config.CALCULATION_INPUT_PAGE_NAME.value)

        elif combo_box.currentIndex() == 2:
            # Chemikin to Cantera
            return self.page_switched.emit(Config.CHEMKIN_TO_CANTERA_PAGE_NAME.value)
        elif combo_box.currentIndex() == 3:
            # Asali user-defined kinetic model check
            return self.page_switched.emit(Config.USER_DEFINED_KINETIC_PAGE_NAME.value)
