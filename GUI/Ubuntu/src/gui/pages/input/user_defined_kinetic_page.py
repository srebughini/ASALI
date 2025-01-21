import os

from PyQt5 import uic
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QLabel, QPushButton

from src.config.input.user_defined_kinetic_page import UserDefinedKineticPageConfig
from src.controllers.input_file_controller import InputFileController
from src.core.data_keys import DataKeys
from src.config.app import AppConfig
from src.gui.pages.basic_page import BasicPage
from src.gui.components.input.user_defined_kinetic_page import UserDefinedKineticPageWidgets


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
        uic.loadUi(UserDefinedKineticPageConfig.PATH.value, self)

        self.update_buttons()
        self.update_labels()
        self.set_custom_dimensions_to_grid_layout()

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.clean()
        self.set_custom_dimensions_to_grid_layout()

    def update_labels(self) -> None:
        """
        Update labels
        Returns
        -------

        """
        for n in UserDefinedKineticPageWidgets.FILES_LABELS.value:
            label = self.findChild(QLabel, n)
            label.setAlignment(Qt.AlignCenter)
            label.setProperty("class", "italic")

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        back_button = self.findChild(QPushButton, UserDefinedKineticPageWidgets.BACK_BUTTON.value)
        back_button.clicked.connect(lambda: self.page_switched.emit(AppConfig.MAIN_INPUT_PAGE))

        check_button = self.findChild(QPushButton, UserDefinedKineticPageWidgets.CHECK_BUTTON.value)
        check_button.clicked.connect(self.check)

        udk_button = self.findChild(QPushButton, UserDefinedKineticPageWidgets.USER_DEFINED_KINETIC_BUTTON.value)
        udk_button.clicked.connect(self.load_udk_file)

        cantera_button = self.findChild(QPushButton, UserDefinedKineticPageWidgets.CANTERA_BUTTON.value)
        cantera_button.clicked.connect(self.load_cantera_file)

    def clean(self) -> None:
        """
        Clean the labels
        Returns
        -------

        """

        for n in UserDefinedKineticPageWidgets.FILES_LABELS.value:
            label = self.findChild(QLabel, n)
            label.setText("Not selected")

        for k in [DataKeys.USER_DEFINED_KINETIC_FILE_PATH,
                  DataKeys.CHEMISTRY_FILE_PATH]:
            self.data_store.update_data(k, None)

    def load_udk_file(self) -> None:
        """
        Load Asali user defined kinetic model
        Returns
        -------

        """
        file_path = self.dialog_handler.load_file(AppConfig.ASALI_FILE_OPEN.value,
                                                  AppConfig.ASALI_FILE_TYPE.value)

        if file_path:
            label = self.findChild(QLabel, UserDefinedKineticPageWidgets.UDK_LABEL.value)
            label.setText(os.path.basename(file_path))
            self.data_store.update_data(DataKeys.USER_DEFINED_KINETIC_FILE_PATH, file_path)

    def load_cantera_file(self) -> None:
        """
        Load Cantera chemistry file
        Returns
        -------

        """
        file_path = self.dialog_handler.load_file(AppConfig.CANTERA_FILE_OPEN.value,
                                                  AppConfig.CANTERA_FILE_TYPE.value)

        if file_path:
            label = self.findChild(QLabel, UserDefinedKineticPageWidgets.CANTERA_LABEL.value)
            label.setText(os.path.basename(file_path))
            self.data_store.update_data(DataKeys.CHEMISTRY_FILE_PATH, file_path)

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
