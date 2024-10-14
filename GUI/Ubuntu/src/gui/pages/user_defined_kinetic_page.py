import os

from PyQt5 import uic
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QLabel, QPushButton, QSizePolicy

from src.controllers.input_file_controller import InputFileController
from src.core.data_keys import DataKeys
from src.gui.config import Config
from src.gui.pages.basic_page import BasicPage


class UserDefinedKineticPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Vacuum properties output layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        uic.loadUi(Config.USER_DEFINED_KINETIC_PAGE_PATH.value, self)

        self.update_buttons()
        self.update_labels()
        self.update_grid_layout()

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.clean()
        self.update_grid_layout()

    def update_labels(self) -> None:
        """
        Update labels
        Returns
        -------

        """
        for n in ["udkLabel", "canteraLabel"]:
            label = self.findChild(QLabel, n)
            label.setAlignment(Qt.AlignCenter)
            label.setProperty("class", "italic")

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        back_button = self.findChild(QPushButton, 'backButton')
        back_button.clicked.connect(lambda: self.page_switched.emit(Config.CHEMISTRY_INPUT_PAGE_NAME.value))
        back_button.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)

        check_button = self.findChild(QPushButton, 'checkButton')
        check_button.clicked.connect(self.check)
        check_button.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)

        udk_button = self.findChild(QPushButton, 'udkButton')
        udk_button.clicked.connect(self.load_udk_file)
        udk_button.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)

        cantera_button = self.findChild(QPushButton, 'canteraButton')
        cantera_button.clicked.connect(self.load_cantera_file)
        cantera_button.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)

    def clean(self) -> None:
        """
        Clean the labels
        Returns
        -------

        """

        for n in ["udkLabel", "canteraLabel"]:
            label = self.findChild(QLabel, n)
            label.setText("Not selected")

        for k in [DataKeys.USER_DEFINED_KINETIC_FILE_PATH,
                  DataKeys.CHEMISTRY_FILE_PATH]:
            self.data_store.update_data(k.value, None)

    def load_udk_file(self) -> None:
        """
        Load Asali user defined kinetic model
        Returns
        -------

        """
        file_path = self.dialog_handler.load_file("Open Asali User Defined Kinetic file",
                                                  Config.ASALI_FILE_TYPE.value)

        if file_path:
            label = self.findChild(QLabel, "udkLabel")
            label.setText(os.path.basename(file_path))
            self.data_store.update_data(DataKeys.USER_DEFINED_KINETIC_FILE_PATH.value, file_path)

    def load_cantera_file(self) -> None:
        """
        Load Cantera chemistry file
        Returns
        -------

        """
        file_path = self.dialog_handler.load_file("Open Cantera chemistry file",
                                                  Config.CANTERA_FILE_TYPE.value)

        if file_path:
            label = self.findChild(QLabel, "canteraLabel")
            label.setText(os.path.basename(file_path))
            self.data_store.update_data(DataKeys.CHEMISTRY_FILE_PATH.value, file_path)

    def check(self) -> None:
        """
        Check Asali User Defined Kinetic file
        Returns
        -------

        """
        udk_path = self.data_store.get_data(DataKeys.USER_DEFINED_KINETIC_FILE_PATH.value)
        if udk_path is None:
            self.dialog_handler.error_message(QLabel("Missing Asali user defined kinetic file"))
            return None

        cantera_path = self.data_store.get_data(DataKeys.CHEMISTRY_FILE_PATH.value)
        if cantera_path is None:
            self.dialog_handler.error_message(QLabel("Missing Cantera chemistry file"))
            return None

        if InputFileController.check_udk_input_file(cantera_path, udk_path):
            self.dialog_handler.done_message(QLabel("Your file is correct!"))
        else:
            self.dialog_handler.error_message(QLabel("Your file is NOT correct!"))
