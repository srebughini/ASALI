from PyQt5 import uic
from PySide6.QtWidgets import QLabel
from asali.utils.cantera_file_converter import CanteraFileConverter

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
        self.load_ui(AppConfig.CHEMKIN_CONVERTER_INPUT_PAGE.value.path)
        self.update_combo_boxes()
        self.update_buttons()

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.data_store.update_data(DataKeys.LAST_ACTIVE_WINDOW, AppConfig.MAIN_INPUT_PAGE)
        self.set_custom_dimensions_to_vertical_layout(self.find_widget(ChemkinConverterInputPageComponents.VBOX))


        action_box = self.find_widget(ChemkinConverterInputPageComponents.ACTION)
        action_box.setCurrentText(ChemkinEditorAction.CONVERTER.value)

        for widget_enum in [ChemkinConverterInputPageComponents.THERMO_BUTTON,
                            ChemkinConverterInputPageComponents.TRANSPORT_BUTTON,
                            ChemkinConverterInputPageComponents.KINETIC_BUTTON,
                            ChemkinConverterInputPageComponents.SURFACE_BUTTON]:
            widget = self.find_widget(widget_enum)
            widget_text = widget.text().replace("\u2714 ", "")
            widget.setText(widget_text)

        for key in [DataKeys.TRANSPORT_FILE_PATH,
                    DataKeys.THERMO_FILE_PATH,
                    DataKeys.KINETIC_FILE_PATH,
                    DataKeys.SURFACE_FILE_PATH]:
            self.data_store.reset_data(key)

    def add_tick_to_button(self, button_enum) -> None:
        """
        Add tick to the button text
        Parameters
        ----------
        button_enum: Enum
            Button text

        Returns
        -------

        """
        button = self.find_widget(button_enum)
        button_text = button.text().replace("\u2714 ", "")
        button.setText(f"\u2714 {button_text}")

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
        back_button.clicked.connect(lambda: self.switch_to_page.emit(AppConfig.MAIN_INPUT_PAGE))

        calculate_button = self.find_widget(ChemkinConverterInputPageComponents.RUN_BUTTON)
        calculate_button.clicked.connect(self.convert)

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
            return self.switch_to_page.emit(AppConfig.CHEMKIN_TRANSPORT_INPUT_PAGE)

        if ChemkinEditorAction.THERMO == selected_action:
            return self.switch_to_page.emit(AppConfig.CHEMKIN_THERMO_INPUT_PAGE)

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
            self.add_tick_to_button(ChemkinConverterInputPageComponents.THERMO_BUTTON)

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
            self.add_tick_to_button(ChemkinConverterInputPageComponents.TRANSPORT_BUTTON)

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
            self.add_tick_to_button(ChemkinConverterInputPageComponents.KINETIC_BUTTON)

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
            self.add_tick_to_button(ChemkinConverterInputPageComponents.SURFACE_BUTTON)

    def convert(self) -> None:
        """
        Convert Chemkin file to Cantera file
        Returns
        -------

        """
        kinetic_file_path = self.data_store.get_data(DataKeys.KINETIC_FILE_PATH)
        thermo_file_path = self.data_store.get_data(DataKeys.THERMO_FILE_PATH)
        transport_file_path = self.data_store.get_data(DataKeys.TRANSPORT_FILE_PATH)
        surface_file_path = self.data_store.get_data(DataKeys.SURFACE_FILE_PATH)

        if len(thermo_file_path) < 1:
            self.dialog_handler.error_message(QLabel("Missing Chemkin thermodynamic file"))
            return None

        if len(transport_file_path) < 1:
            self.dialog_handler.error_message(QLabel("Missing Chemkin transport file"))
            return None

        if len(kinetic_file_path) < 1:
            self.dialog_handler.error_message(QLabel("Missing Chemkin kinetic file"))
            return None

        if len(surface_file_path) < 1:
            surface_file_path = None

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
