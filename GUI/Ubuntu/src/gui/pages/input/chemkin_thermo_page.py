from PySide6.QtWidgets import QLabel, QLineEdit

from src.config.app import AppConfig
from src.config.input_composition import InputCompositionConfig
from src.controllers.chemkin_file_controller import ThermoPhases, ChemkinFileController
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
        self.load_ui(AppConfig.CHEMKIN_THERMO_INPUT_PAGE.value.path)
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
        self.set_custom_dimensions_to_vertical_layout(self.find_widget(ChemkinThermoInputPageComponents.VBOX))

        action_box = self.find_widget(ChemkinThermoInputPageComponents.ACTION)
        action_box.setCurrentText(ChemkinEditorAction.THERMO.value)

        if self.data_store.get_data(DataKeys.NE) < 0:
            self.add_element(ChemkinThermoInputPageComponents.ELEMENT_LAYOUT)

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        back_button = self.find_widget(ChemkinThermoInputPageComponents.BACK_BUTTON)
        back_button.clicked.connect(lambda: self.switch_to_page.emit(AppConfig.MAIN_INPUT_PAGE))

        calculate_button = self.find_widget(ChemkinThermoInputPageComponents.RUN_BUTTON)
        calculate_button.clicked.connect(self.save_file)

        thermo_button = self.find_widget(ChemkinThermoInputPageComponents.THERMO_BUTTON)
        thermo_button.clicked.connect(self.load_thermo_file)

        add_button = self.find_widget(ChemkinThermoInputPageComponents.ADD_ELEMENT_BUTTON)
        add_button.clicked.connect(
            lambda checked, grid_enum=ChemkinThermoInputPageComponents.ELEMENT_LAYOUT: self.add_element(grid_enum))

        remove_button = self.find_widget(ChemkinThermoInputPageComponents.REMOVE_ELEMENT_BUTTON)
        remove_button.clicked.connect(
            lambda checked, grid_enum=ChemkinThermoInputPageComponents.ELEMENT_LAYOUT: self.remove_element(grid_enum))

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
            return self.switch_to_page.emit(AppConfig.CHEMKIN_CONVERTER_INPUT_PAGE)

        if ChemkinEditorAction.TRANSPORT == selected_action:
            return self.switch_to_page.emit(AppConfig.CHEMKIN_TRANSPORT_INPUT_PAGE)

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

    def add_element(self, grid_enum) -> None:
        """
        Add gas species widgets to the grid layout
        Parameters
        ----------
        grid_enum: Enum
            Enum describing the layout where to add the gas specie row
        Returns
        -------
        """
        grid = self.find_widget(grid_enum)
        idx = self.data_store.get_data(DataKeys.NE) + 1
        self.data_store.update_data(DataKeys.NE, idx)

        label = self.findChild(QLabel, InputCompositionConfig.ELEMENT_LABEL_NAME.value.format(idx))
        if label is None:
            label = QLabel(InputCompositionConfig.ELEMENT_LABEL_TEXT.value.format(idx))
            label.setObjectName(InputCompositionConfig.ELEMENT_LABEL_NAME.value.format(idx))
            grid.addWidget(label, idx, 0)
        else:
            label.setVisible(True)

        name_edit_line = self.findChild(QLineEdit, InputCompositionConfig.ELEMENT_EDIT_LINE_NAME.value.format(idx))
        if name_edit_line is None:
            name_edit_line = QLineEdit()
            name_edit_line.setObjectName(InputCompositionConfig.ELEMENT_EDIT_LINE_NAME.value.format(idx))
            name_edit_line.setValidator(InputCompositionConfig.ELEMENT_NAME_VALIDATOR.value)
            name_edit_line.setAlignment(InputCompositionConfig.EDIT_LINE_ALIGN.value)
            name_edit_line.setText(InputCompositionConfig.EDIT_LINE_LETTER_TEXT.value)
            grid.addWidget(name_edit_line, idx, 1)
        else:
            name_edit_line.setVisible(True)

        composition_edit_line = self.findChild(QLineEdit,
                                               InputCompositionConfig.ELEMENT_EDIT_LINE_COMPOSITION.value.format(idx))
        if composition_edit_line is None:
            composition_edit_line = QLineEdit()
            composition_edit_line.setObjectName(InputCompositionConfig.ELEMENT_EDIT_LINE_COMPOSITION.value.format(idx))
            composition_edit_line.setValidator(InputCompositionConfig.ELEMENT_COMPOSITION_VALIDATOR.value)
            composition_edit_line.setAlignment(InputCompositionConfig.EDIT_LINE_ALIGN.value)
            composition_edit_line.setText(InputCompositionConfig.EDIT_LINE_INT_TEXT.value)
            grid.addWidget(composition_edit_line, idx, 2)
        else:
            composition_edit_line.setVisible(True)

        self.set_custom_dimensions_to_grid_layout(grid)

    def remove_element(self, grid_enum) -> None:
        """
        Remove gas species widgets to the grid layout
        Parameters
        ----------
        grid_enum: Enum
            Enum describing the layout where to add the gas specie row
        Returns
        -------
        """
        grid = self.find_widget(grid_enum)
        idx = self.data_store.get_data(DataKeys.NE)
        if idx > 0:
            label = self.findChild(QLabel, InputCompositionConfig.ELEMENT_LABEL_NAME.value.format(idx))
            name_edit_line = self.findChild(QLineEdit, InputCompositionConfig.ELEMENT_EDIT_LINE_NAME.value.format(idx))
            composition_edit_line = self.findChild(QLineEdit,
                                                   InputCompositionConfig.ELEMENT_EDIT_LINE_COMPOSITION.value.format(
                                                       idx))

            label.setVisible(False)
            name_edit_line.setVisible(False)
            composition_edit_line.setVisible(False)

            self.set_custom_dimensions_to_grid_layout(grid)
            self.data_store.update_data(DataKeys.NE, idx - 1)

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
        common_temperature = float(
            self.find_widget(ChemkinThermoInputPageComponents.COMMON_TEMPERATURE_EDIT_LINE).text())
        upper_coefficient_list = [float(self.find_widget(w).text()) for w in
                                  [ChemkinThermoInputPageComponents.A1_UPPER_EDIT_LINE,
                                   ChemkinThermoInputPageComponents.A2_UPPER_EDIT_LINE,
                                   ChemkinThermoInputPageComponents.A3_UPPER_EDIT_LINE,
                                   ChemkinThermoInputPageComponents.A4_UPPER_EDIT_LINE,
                                   ChemkinThermoInputPageComponents.A5_UPPER_EDIT_LINE,
                                   ChemkinThermoInputPageComponents.A6_UPPER_EDIT_LINE,
                                   ChemkinThermoInputPageComponents.A7_UPPER_EDIT_LINE]]
        lower_coefficient_list = [float(self.find_widget(w).text()) for w in
                                  [ChemkinThermoInputPageComponents.A1_LOWER_EDIT_LINE,
                                   ChemkinThermoInputPageComponents.A2_LOWER_EDIT_LINE,
                                   ChemkinThermoInputPageComponents.A3_LOWER_EDIT_LINE,
                                   ChemkinThermoInputPageComponents.A4_LOWER_EDIT_LINE,
                                   ChemkinThermoInputPageComponents.A5_LOWER_EDIT_LINE,
                                   ChemkinThermoInputPageComponents.A6_LOWER_EDIT_LINE,
                                   ChemkinThermoInputPageComponents.A7_LOWER_EDIT_LINE]]

        atomic_symbols_and_formula = {
            self.findChild(QLineEdit, InputCompositionConfig.ELEMENT_EDIT_LINE_NAME.value.format(idx)).text():
                int(self.findChild(QLineEdit,
                                   InputCompositionConfig.ELEMENT_EDIT_LINE_COMPOSITION.value.format(idx)).text()) for
            idx in range(0, self.data_store.get_data(DataKeys.NE)+1)}

        print(atomic_symbols_and_formula)

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
        data_list = self.read_data()

        output_file_path = self.data_store.get_data(DataKeys.THERMO_FILE_PATH)

        if len(output_file_path) == 0:
            answer = self.dialog_handler.question_message(QLabel("Thermo file is missing!\nDo you want to load it?"))
            if answer:
                self.load_transport_file()
                output_file_path = self.data_store.get_data(DataKeys.THERMO_FILE_PATH)
            else:
                return None

        if output_file_path is not None:
            try:
                ChemkinFileController.update_thermo_file(output_file_path, data_list)
            except Exception as e:
                raise Exception(e)
            else:
                self.dialog_handler.done_message(QLabel("Thermo file updated!"))

        return None
