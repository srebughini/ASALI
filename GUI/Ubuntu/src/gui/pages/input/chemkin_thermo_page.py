from PyQt5 import uic

from src.config.app import AppConfig
from src.controllers.chemkin_file_controller import ThermoPhases
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
        self.update_edit_lines()

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
        calculate_button.clicked.connect(self.save_file)

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

        phase_box = self.find_widget(ChemkinThermoInputPageComponents.PHASE_COMBO_BOX)
        phase_box.addItems([p.value for p in ChemkinThermoInputPageComponents.PHASE_COMBO_BOX.value.items_enum])

    def update_edit_lines(self) -> None:
        """
        Update edit lines
        Returns
        -------

        """
        for w in [ChemkinThermoInputPageComponents.A1_LOWER_EDIT_LINE,
                  ChemkinThermoInputPageComponents.A1_UPPER_EDIT_LINE,
                  ChemkinThermoInputPageComponents.A2_LOWER_EDIT_LINE,
                  ChemkinThermoInputPageComponents.A2_UPPER_EDIT_LINE,
                  ChemkinThermoInputPageComponents.A3_LOWER_EDIT_LINE,
                  ChemkinThermoInputPageComponents.A3_UPPER_EDIT_LINE,
                  ChemkinThermoInputPageComponents.A4_LOWER_EDIT_LINE,
                  ChemkinThermoInputPageComponents.A4_UPPER_EDIT_LINE,
                  ChemkinThermoInputPageComponents.A5_LOWER_EDIT_LINE,
                  ChemkinThermoInputPageComponents.A5_UPPER_EDIT_LINE,
                  ChemkinThermoInputPageComponents.A6_LOWER_EDIT_LINE,
                  ChemkinThermoInputPageComponents.A6_UPPER_EDIT_LINE,
                  ChemkinThermoInputPageComponents.A7_LOWER_EDIT_LINE,
                  ChemkinThermoInputPageComponents.A7_UPPER_EDIT_LINE,
                  ChemkinThermoInputPageComponents.HIGH_TEMPERATURE_EDIT_LINE,
                  ChemkinThermoInputPageComponents.COMMON_TEMPERATURE_EDIT_LINE,
                  ChemkinThermoInputPageComponents.LOW_TEMPERATURE_EDIT_LINE]:
            edit_line = self.find_widget(w)
            edit_line.setValidator(w.value.validator)
            edit_line.setAlignment(w.value.alignment)
            edit_line.setText(w.value.text)

        w = ChemkinThermoInputPageComponents.NAME_THERMO_EDIT_LINE
        edit_line = self.find_widget(w)
        edit_line.setAlignment(w.value.alignment)

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

    def read_data(self) -> None | list:
        """
        Read transport data
        Returns
        -------
        data_list: list
            Thermo data as list [name,
                          atomic_symbols_and_formula,
                          phase,
                          low_temperature,
                          high_temperature,
                          common_temperature,
                          upper_coefficient_list,
                          lower_coefficient_list]
        """
        name = self.find_widget(ChemkinThermoInputPageComponents.NAME_THERMO_EDIT_LINE).text()
        phase = ThermoPhases(self.find_widget(ChemkinThermoInputPageComponents.PHASE_COMBO_BOX).currentText())
        low_temperature = float(self.find_widget(ChemkinThermoInputPageComponents.LOW_TEMPERATURE_EDIT_LINE).text())
        high_temperature = float(self.find_widget(ChemkinThermoInputPageComponents.HIGH_TEMPERATURE_EDIT_LINE).text())
        common_temperature = float(self.find_widget(ChemkinThermoInputPageComponents.COMMON_TEMPERATURE_EDIT_LINE).text())
        upper_coefficient_list = [float(self.find_widget(w).text()) for w in [ChemkinThermoInputPageComponents.A1_UPPER_EDIT_LINE,
                                                                              ChemkinThermoInputPageComponents.A2_UPPER_EDIT_LINE,
                                                                              ChemkinThermoInputPageComponents.A3_UPPER_EDIT_LINE,
                                                                              ChemkinThermoInputPageComponents.A4_UPPER_EDIT_LINE,
                                                                              ChemkinThermoInputPageComponents.A5_UPPER_EDIT_LINE,
                                                                              ChemkinThermoInputPageComponents.A6_UPPER_EDIT_LINE,
                                                                              ChemkinThermoInputPageComponents.A7_UPPER_EDIT_LINE]]
        lower_coefficient_list = [float(self.find_widget(w).text()) for w in [ChemkinThermoInputPageComponents.A1_LOWER_EDIT_LINE,
                                                                              ChemkinThermoInputPageComponents.A2_LOWER_EDIT_LINE,
                                                                              ChemkinThermoInputPageComponents.A3_LOWER_EDIT_LINE,
                                                                              ChemkinThermoInputPageComponents.A4_LOWER_EDIT_LINE,
                                                                              ChemkinThermoInputPageComponents.A5_LOWER_EDIT_LINE,
                                                                              ChemkinThermoInputPageComponents.A6_LOWER_EDIT_LINE,
                                                                              ChemkinThermoInputPageComponents.A7_LOWER_EDIT_LINE]]

        atomic_symbols_and_formula = self.data_store.get_data_value(DataKeys.ATOM_DICT)

        if len(atomic_symbols_and_formula) < 1:
            self.dialog_handler.error_message("Missing atomic composition!")
            return None

        return [name,
                atomic_symbols_and_formula,
                phase,
                low_temperature,
                high_temperature,
                common_temperature,
                upper_coefficient_list,
                lower_coefficient_list]

    def save_file(self) -> None:
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
