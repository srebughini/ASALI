import os.path

from PyQt5 import uic
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QPushButton, QSizePolicy, QFileDialog, QLabel
from asali.utils.cantera_file_converter import CanteraFileConverter

from src.core.data_keys import DataKeys
from src.gui.config import Config
from src.gui.pages.basic_page import BasicPage


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
        uic.loadUi(Config.CHEMKIN_TO_CANTERA_PAGE_PATH.value, self)

        self.data_store.update_data(DataKeys.SURFACE_FILE_PATH.value, None)

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
        for n in ["thermoLabel", "transportLabel", "kineticLabel", "surfaceLabel"]:
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

        clean_button = self.findChild(QPushButton, 'cleanButton')
        clean_button.clicked.connect(self.clean)

        convert_button = self.findChild(QPushButton, 'convertButton')
        convert_button.clicked.connect(self.convert)

        thermo_button = self.findChild(QPushButton, 'thermoButton')
        thermo_button.clicked.connect(self.load_thermo_file)

        transport_button = self.findChild(QPushButton, 'transportButton')
        transport_button.clicked.connect(self.load_transport_file)

        kinetic_button = self.findChild(QPushButton, 'kineticButton')
        kinetic_button.clicked.connect(self.load_gas_kinetic_file)

        surface_button = self.findChild(QPushButton, 'surfaceButton')
        surface_button.clicked.connect(self.load_surface_kinetic_file)

    def clean(self) -> None:
        """
        Clean the labels
        Returns
        -------

        """
        for n in ["thermoLabel", "transportLabel", "kineticLabel", "surfaceLabel"]:
            label = self.findChild(QLabel, n)
            label.setText("Not selected")

        for k in [DataKeys.TRANSPORT_FILE_PATH,
                  DataKeys.THERMO_FILE_PATH,
                  DataKeys.KINETIC_FILE_PATH,
                  DataKeys.SURFACE_FILE_PATH]:
            self.data_store.update_data(k.value, None)

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

        output_file_path = self.dialog_handler.save_file("Save Cantera file",
                                                         Config.CANTERA_FILE_TYPE.value)

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
        file_path = self.dialog_handler.load_file("Open Chemkin Thermo file",
                                                  Config.CHEMKIN_FILE_TYPE.value)

        if file_path:
            label = self.findChild(QLabel, "thermoLabel")
            label.setText(os.path.basename(file_path))
            self.data_store.update_data(DataKeys.THERMO_FILE_PATH.value, file_path)

    def load_transport_file(self) -> None:
        """
        Load transport file of Chemkin chemistry model
        Returns
        -------

        """
        file_path = self.dialog_handler.load_file("Open Chemkin Transport file",
                                                  Config.CHEMKIN_FILE_TYPE.value)

        if file_path:
            label = self.findChild(QLabel, "transportLabel")
            label.setText(os.path.basename(file_path))
            self.data_store.update_data(DataKeys.TRANSPORT_FILE_PATH.value, file_path)

    def load_gas_kinetic_file(self) -> None:
        """
        Load gas kinetic file of Chemkin chemistry model
        Returns
        -------

        """
        file_path = self.dialog_handler.load_file("Open Chemkin Gas Kinetic file",
                                                  Config.CHEMKIN_FILE_TYPE.value)

        if file_path:
            label = self.findChild(QLabel, "kineticLabel")
            label.setText(os.path.basename(file_path))
            self.data_store.update_data(DataKeys.KINETIC_FILE_PATH.value, file_path)

    def load_surface_kinetic_file(self) -> None:
        """
        Load surface kinetic file of Chemkin chemistry model
        Returns
        -------

        """
        file_path = self.dialog_handler.load_file("Open Chemkin Surface Kinetic file",
                                                  Config.CHEMKIN_FILE_TYPE.value)

        if file_path:
            label = self.findChild(QLabel, "surfaceLabel")
            label.setText(os.path.basename(file_path))
            self.data_store.update_data(DataKeys.SURFACE_FILE_PATH.value, file_path)
