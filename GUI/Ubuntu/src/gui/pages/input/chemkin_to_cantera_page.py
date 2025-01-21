import os.path

from PyQt5 import uic
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QPushButton, QLabel
from asali.utils.cantera_file_converter import CanteraFileConverter

from src.config.input.chemkin_to_cantera_page import ChemkinToCanteraPageConfig
from src.core.data_keys import DataKeys
from src.config.app import AppConfig
from src.gui.pages.basic_page import BasicPage
from src.gui.components.input.chemkin_to_cantera_page import ChemkinToCanteraPageWidgets


class ChemkinToCanteraPage(BasicPage):
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
        uic.loadUi(ChemkinToCanteraPageConfig.PATH.value, self)

        self.data_store.update_data(DataKeys.SURFACE_FILE_PATH, None)

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
        for n in ChemkinToCanteraPageWidgets.FILES_LABELS.value:
            label = self.findChild(QLabel, n)
            label.setAlignment(Qt.AlignCenter)
            label.setProperty("class", "italic")

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        back_button = self.findChild(QPushButton, ChemkinToCanteraPageWidgets.BACK_BUTTON.value)
        back_button.clicked.connect(lambda: self.page_switched.emit(AppConfig.MAIN_INPUT_PAGE))

        clean_button = self.findChild(QPushButton, ChemkinToCanteraPageWidgets.CLEAN_BUTTON.value)
        clean_button.clicked.connect(self.clean)

        convert_button = self.findChild(QPushButton, ChemkinToCanteraPageWidgets.CONVERT_BUTTON.value)
        convert_button.clicked.connect(self.convert)

        thermo_button = self.findChild(QPushButton, ChemkinToCanteraPageWidgets.THERMO_BUTTON.value)
        thermo_button.clicked.connect(self.load_thermo_file)

        transport_button = self.findChild(QPushButton, ChemkinToCanteraPageWidgets.TRANSPORT_BUTTON.value)
        transport_button.clicked.connect(self.load_transport_file)

        kinetic_button = self.findChild(QPushButton, ChemkinToCanteraPageWidgets.KINETIC_BUTTON.value)
        kinetic_button.clicked.connect(self.load_gas_kinetic_file)

        surface_button = self.findChild(QPushButton, ChemkinToCanteraPageWidgets.SURFACE_BUTTON.value)
        surface_button.clicked.connect(self.load_surface_kinetic_file)

    def clean(self) -> None:
        """
        Clean the labels
        Returns
        -------

        """
        for n in ChemkinToCanteraPageWidgets.FILES_LABELS.value:
            label = self.findChild(QLabel, n)
            label.setText("Not selected")

        for k in [DataKeys.TRANSPORT_FILE_PATH,
                  DataKeys.THERMO_FILE_PATH,
                  DataKeys.KINETIC_FILE_PATH,
                  DataKeys.SURFACE_FILE_PATH]:
            self.data_store.update_data(k, None)

    def convert(self) -> None:
        """
        Convert Chemkin file to Cantera file
        Returns
        -------

        """
        kinetic_file_path = self.data_store.get_data(DataKeys.KINETIC_FILE_PATH.value)
        thermo_file_path = self.data_store.get_data(DataKeys.THERMO_FILE_PATH.value)
        transport_file_path = self.data_store.get_data(DataKeys.TRANSPORT_FILE_PATH.value)
        surface_file_path = self.data_store.get_data(DataKeys.SURFACE_FILE_PATH.value)

        if thermo_file_path is None:
            self.dialog_handler.error_message(QLabel("Missing Chemkin thermodynamic file"))
            return None

        if transport_file_path is None:
            self.dialog_handler.error_message(QLabel("Missing Chemkin transport file"))
            return None

        if kinetic_file_path is None:
            self.dialog_handler.error_message(QLabel("Missing Chemkin kinetic file"))
            return None

        output_file_path = self.dialog_handler.save_file(AppConfig.CANTERA_FILE_SAVE.value,
                                                         AppConfig.CANTERA_FILE_TYPE.value)

        if output_file_path:
            try:
                CanteraFileConverter.from_chemkin_to_yaml(kinetic_file_path=kinetic_file_path,
                                                          thermodynamic_file_path=thermo_file_path,
                                                          transport_file_path=transport_file_path,
                                                          surface_file_path=surface_file_path,
                                                          output_file_path=output_file_path,
                                                          validation=False)
            except Exception as e:
                raise Exception(e)
            else:
                self.dialog_handler.done_message(QLabel("Cantera file saved!"))

    def load_thermo_file(self) -> None:
        """
        Load thermo file of Chemkin chemistry model
        Returns
        -------

        """
        file_path = self.dialog_handler.load_file(f"{AppConfig.CHEMKIN_FILE_OPEN.value}: Thermo",
                                                  AppConfig.CHEMKIN_FILE_TYPE.value)

        if file_path:
            label = self.findChild(QLabel, ChemkinToCanteraPageWidgets.THERMO_LABEL.value)
            label.setText(os.path.basename(file_path))
            self.data_store.update_data(DataKeys.THERMO_FILE_PATH, file_path)

    def load_transport_file(self) -> None:
        """
        Load transport file of Chemkin chemistry model
        Returns
        -------

        """
        file_path = self.dialog_handler.load_file(f"{AppConfig.CHEMKIN_FILE_OPEN.value}: Transport",
                                                  AppConfig.CHEMKIN_FILE_TYPE.value)

        if file_path:
            label = self.findChild(QLabel, ChemkinToCanteraPageWidgets.TRANSPORT_LABEL.value)
            label.setText(os.path.basename(file_path))
            self.data_store.update_data(DataKeys.TRANSPORT_FILE_PATH, file_path)

    def load_gas_kinetic_file(self) -> None:
        """
        Load gas kinetic file of Chemkin chemistry model
        Returns
        -------

        """
        file_path = self.dialog_handler.load_file(f"{AppConfig.CHEMKIN_FILE_OPEN.value}: Gas Kinetic",
                                                  AppConfig.CHEMKIN_FILE_TYPE.value)

        if file_path:
            label = self.findChild(QLabel, ChemkinToCanteraPageWidgets.KINETIC_LABEL.value)
            label.setText(os.path.basename(file_path))
            self.data_store.update_data(DataKeys.KINETIC_FILE_PATH, file_path)

    def load_surface_kinetic_file(self) -> None:
        """
        Load surface kinetic file of Chemkin chemistry model
        Returns
        -------

        """
        file_path = self.dialog_handler.load_file(f"{AppConfig.CHEMKIN_FILE_OPEN.value}: Surface Kinetic",
                                                  AppConfig.CHEMKIN_FILE_TYPE.value)

        if file_path:
            label = self.findChild(QLabel, ChemkinToCanteraPageWidgets.SURFACE_LABEL.value)
            label.setText(os.path.basename(file_path))
            self.data_store.update_data(DataKeys.SURFACE_FILE_PATH, file_path)
