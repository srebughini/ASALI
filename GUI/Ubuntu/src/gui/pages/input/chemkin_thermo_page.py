from PyQt5 import uic

from src.config.app import AppConfig
from src.core.data_keys import DataKeys
from src.gui.components.input.chemkin_thermo_page import ChemkinThermoInputPageComponents
from src.gui.enums.chemkin_editor_action import ChemkinEditorAction
from src.gui.pages.basic_page import BasicPage


class ChemkinThermoInputPage(BasicPage):
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
        uic.loadUi(AppConfig.CHEMKIN_THERMO_INPUT_PAGE.value.path, self)
        self.update_combo_boxes()
        self.update_buttons()

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.data_store.update_data(DataKeys.LAST_ACTIVE_WINDOW, AppConfig.MAIN_INPUT_PAGE)

        action_box = self.find_widget(ChemkinThermoInputPageComponents.ACTION)
        action_box.setCurrentText(ChemkinEditorAction.THERMO.value)

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        back_button = self.find_widget(ChemkinThermoInputPageComponents.BACK_BUTTON)
        back_button.clicked.connect(lambda: self.page_switched.emit(AppConfig.MAIN_INPUT_PAGE))

        calculate_button = self.find_widget(ChemkinThermoInputPageComponents.RUN_BUTTON)
        calculate_button.clicked.connect(self.show_data)

        thermo_button = self.find_widget(ChemkinThermoInputPageComponents.THERMO_BUTTON)
        thermo_button.clicked.connect(self.load_thermo_file)

    def update_combo_boxes(self) -> None:
        """
        Update combo boxes
        Returns
        -------

        """
        action_box = self.find_widget(ChemkinThermoInputPageComponents.ACTION)
        action_box.addItems(ChemkinThermoInputPageComponents.ACTION.value.items)
        action_box.currentIndexChanged.connect(self.update_page_based_on_action)

    def update_page_based_on_action(self) -> None:
        """
        Update page layout based on the selected action
        Returns
        -------

        """
        action_combo_box = self.find_widget(ChemkinThermoInputPageComponents.ACTION)
        selected_action = ChemkinEditorAction(action_combo_box.currentText())

        if ChemkinEditorAction.CONVERTER == selected_action:
            return self.page_switched.emit(AppConfig.CHEMKIN_CONVERTER_INPUT_PAGE)

        if ChemkinEditorAction.TRANSPORT == selected_action:
            return self.page_switched.emit(AppConfig.CHEMKIN_TRANSPORT_INPUT_PAGE)

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

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        pass
        """
        ud = self.find_widget(EquilibriumOutputPageComponents.TEMPERATURE_UD).currentText()
        self.data_store.update_data(DataKeys.EQ_TEMPERATURE, (0.0, ud))

        ud = self.find_widget(EquilibriumOutputPageComponents.PRESSURE_UD).currentText()
        self.data_store.update_data(DataKeys.EQ_PRESSURE, (0.0, ud))

        equilibrium_type = self.find_widget(EquilibriumOutputPageComponents.EQUILIBRIUM_TYPE).currentText()
        self.data_store.update_data(DataKeys.EQUILIBRIUM_TYPE, EquilibriumType(equilibrium_type))
        """

    def show_data(self) -> None:
        """
        Update shown data
        Returns
        -------

        """
        pass
        """
        self.read_data()
        self.data_store = equilibrium_calculator(self.data_store)

        for widget_enum, key in {EquilibriumOutputPageComponents.TEMPERATURE: DataKeys.EQ_TEMPERATURE,
                                 EquilibriumOutputPageComponents.PRESSURE: DataKeys.EQ_PRESSURE,
                                 EquilibriumOutputPageComponents.MOLE_FRACTION: DataKeys.EQ_MOLE_FRACTION,
                                 EquilibriumOutputPageComponents.MASS_FRACTION: DataKeys.EQ_MASS_FRACTION,
                                 EquilibriumOutputPageComponents.NAMES: DataKeys.EQ_SPECIE_NAMES}.items():
            widget = self.find_widget(widget_enum)
            data = self.data_store.get_data(key)
            if isinstance(data, list):
                widget.setText(LabelFormatter.list_to_string(data))
            elif isinstance(data, tuple):
                widget.setText(LabelFormatter.float_to_string(data[0]))
            else:
                widget.setText(LabelFormatter.float_to_string(data))

        self.set_custom_dimensions_to_grid_layout(self.find_widget(EquilibriumOutputPageComponents.GRID))
        """
