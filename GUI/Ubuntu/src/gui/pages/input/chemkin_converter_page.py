from PyQt5 import uic

from src.config.app import AppConfig
from src.core.data_keys import DataKeys
from src.gui.components.input.chemkin_converter_page import ChemkinConverterInputPageComponents
from src.gui.enums.chemkin_editor_action import ChemkinEditorAction
from src.gui.pages.basic_page import BasicPage


class ChemkinConverterInputPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Chemkin layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        uic.loadUi(AppConfig.CHEMKIN_CONVERTER_INPUT_PAGE.value.path, self)
        self.update_combo_boxes()
        self.update_buttons()

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.data_store.update_data(DataKeys.LAST_ACTIVE_WINDOW, AppConfig.MAIN_INPUT_PAGE)

        action_box = self.find_widget(ChemkinConverterInputPageComponents.ACTION)
        action_box.setCurrentText(ChemkinEditorAction.CONVERTER.value)

    def update_combo_boxes(self) -> None:
        """
        Update combo boxes
        Returns
        -------

        """
        action_box = self.find_widget(ChemkinConverterInputPageComponents.ACTION)
        action_box.addItems(ChemkinConverterInputPageComponents.ACTION.value.items)
        action_box.currentIndexChanged.connect(self.update_page_based_on_action)

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        back_button = self.find_widget(ChemkinConverterInputPageComponents.BACK_BUTTON)
        back_button.clicked.connect(lambda: self.page_switched.emit(AppConfig.MAIN_INPUT_PAGE))

        calculate_button = self.find_widget(ChemkinConverterInputPageComponents.RUN_BUTTON)
        calculate_button.clicked.connect(self.show_data)

        thermo_button = self.find_widget(ChemkinConverterInputPageComponents.THERMO_BUTTON)
        thermo_button.clicked.connect(self.load_thermo_file)

        transport_button = self.find_widget(ChemkinConverterInputPageComponents.TRANSPORT_BUTTON)
        transport_button.clicked.connect(self.load_transport_file)

        kinetic_button = self.find_widget(ChemkinConverterInputPageComponents.KINETIC_BUTTON)
        kinetic_button.clicked.connect(self.load_gas_kinetic_file)

        surface_button = self.find_widget(ChemkinConverterInputPageComponents.SURFACE_BUTTON)
        surface_button.clicked.connect(self.load_surface_kinetic_file)

    def update_page_based_on_action(self) -> None:
        """
        Update page layout based on the selected action
        Returns
        -------

        """
        action_combo_box = self.find_widget(ChemkinConverterInputPageComponents.ACTION)
        selected_action = ChemkinEditorAction(action_combo_box.currentText())

        if ChemkinEditorAction.TRANSPORT == selected_action:
            return self.page_switched.emit(AppConfig.CHEMKIN_TRANSPORT_INPUT_PAGE)

        if ChemkinEditorAction.THERMO == selected_action:
            return self.page_switched.emit(AppConfig.CHEMKIN_THERMO_INPUT_PAGE)

    def load_thermo_file(self) -> None:
        """
        Load thermo file of Chemkin chemistry model
        Returns
        -------

        """
        file_path = self.dialog_handler.load_file(f"{AppConfig.CHEMKIN_FILE_OPEN.value}: Thermo",
                                                  AppConfig.CHEMKIN_FILE_TYPE.value)

        if file_path:
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
            self.data_store.update_data(DataKeys.SURFACE_FILE_PATH, file_path)

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        pass

    def show_data(self) -> None:
        """
        Update shown data
        Returns
        -------

        """
        pass
