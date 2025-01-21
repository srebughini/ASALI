from PyQt5.QtCore import Qt, pyqtSignal
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import QPushButton, QLineEdit, QComboBox, QLabel, QGridLayout
from PyQt5 import uic

from src.config.app import AppConfig
from src.config.input.batch_input_page import BatchInputPageConfig
from src.config.input.calculation_input_page import CalculationInputPageConfig
from src.config.input.cstr_input_page import CstrInputPageConfig
from src.config.output.equilibrium_output_page import EquilibriumOutputPageConfig
from src.config.input.het_1d_input_page import Het1dInputPageConfig
from src.config.input_composition import InputCompositionConfig
from src.config.output.regression_output_page_config import RegressionOutputPageConfig
from src.config.input.ph_1d_input_page import Ph1dInputPageConfig
from src.config.output.properties_output_page import PropertiesOutputPageConfig
from src.config.output.vacuum_output_page import VacuumOutputPageConfig
from src.controllers.input_file_controller import InputFileController
from src.gui.enums.composition_type import CompositionType
from src.core.data_keys import DataKeys
from src.core.species_names import gas_species_names
from src.gui.enums.database_type import DatabaseType
from src.gui.pages.basic_page import BasicPage
from src.gui.components.input.properties_page import PropertiesInputPageComponents


class PropertiesInputPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Properties input page layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        uic.loadUi(AppConfig.PROPERTIES_INPUT_PAGE.value.path, self)

        self._specie_idx = 0

        self.update_buttons()
        self.update_combo_boxes()
        self.update_edit_lines()
        self.set_custom_dimensions_to_grid_layout(self.find_widget(PropertiesInputPageComponents.GRID))

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        database_box = self.find_widget(PropertiesInputPageComponents.DATABASE_SELECTION)
        database_box.setCurrentText(DatabaseType.NONE.value)
        self.select_database_and_clean_input()

    # def read_data(self) -> None:
    #     """
    #     Update data store with temperature, composition, pressure
    #     Returns
    #     -------
    #
    #     """
    #     # Number of species
    #     self.data_store.update_data(DataKeys.INLET_NS, self.ns)
    #
    #     # Temperature
    #     value = float(self.findChild(QLineEdit, PropertiesInputPageComponents.TEMPERATURE_EDIT_LINE.value).text())
    #     ud = self.findChild(QComboBox, PropertiesInputPageComponents.TEMPERATURE_COMBO_BOX.value).currentText()
    #     self.data_store.update_data(DataKeys.INLET_T, (value, ud))
    #
    #     # Pressure
    #     value = float(self.findChild(QLineEdit, PropertiesInputPageComponents.PRESSURE_EDIT_LINE.value).text())
    #     ud = self.findChild(QComboBox, PropertiesInputPageComponents.PRESSURE_COMBO_BOX.value).currentText()
    #     self.data_store.update_data(DataKeys.INLET_P, (value, ud))
    #
    #     # Composition
    #     value = {}
    #     for i in range(0, int(self.data_store.get_data(DataKeys.INLET_NS) + 1)):
    #         specie_name = self.findChild(QComboBox,
    #                                      InputCompositionConfig.GAS_SPECIE_COMBO_BOX_NAME.value.format(i)).currentText()
    #         specie_value = self.findChild(QLineEdit,
    #                                       InputCompositionConfig.GAS_SPECIE_EDIT_LINE_NAME.value.format(i)).text()
    #         value[specie_name] = float(specie_value)
    #
    #     ud = self.findChild(QComboBox, PropertiesInputPageComponents.COMPOSITION_COMBO_BOX.value).currentText()
    #     if "mol" in ud.lower():
    #         self.data_store.update_data(DataKeys.INLET_GAS_COMPOSITION, (value, CompositionType.MOLE))
    #     else:
    #         self.data_store.update_data(DataKeys.INLET_GAS_COMPOSITION, (value, CompositionType.MASS))
    #
    # def update_temperature_line(self) -> None:
    #     """
    #     Update temperature input line
    #     Returns
    #     -------
    #
    #     """
    #     edit_line = self.findChild(QLineEdit, PropertiesInputPageComponents.TEMPERATURE_EDIT_LINE.value)
    #     edit_line.setValidator(QDoubleValidator(0.0, 3000.0, 2))
    #     edit_line.setAlignment(Qt.AlignRight)

    # def update_pressure_line(self) -> None:
    #     """
    #     Update pressure input line
    #     Returns
    #     -------
    #
    #     """
    #     edit_line = self.findChild(QLineEdit, PropertiesInputPageComponents.PRESSURE_EDIT_LINE.value)
    #     edit_line.setValidator(QDoubleValidator(0.0, 1e09, 2))
    #     edit_line.setAlignment(Qt.AlignRight)

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        next_button = self.find_widget(PropertiesInputPageComponents.NEXT_BUTTON)
        next_button.clicked.connect(self.calculate)

        back_button = self.find_widget(PropertiesInputPageComponents.BACK_BUTTON)
        back_button.clicked.connect(lambda: self.page_switched.emit(AppConfig.MAIN_INPUT_PAGE))

        add_button = self.find_widget(PropertiesInputPageComponents.ADD_GAS_BUTTON)
        add_button.clicked.connect(
            lambda checked, grid_enum=PropertiesInputPageComponents.GAS_SPECIES_LAYOUT: self.add_gas_specie(grid_enum))

        remove_button = self.find_widget(PropertiesInputPageComponents.REMOVE_GAS_BUTTON)
        remove_button.clicked.connect(
            lambda checked, grid_enum=PropertiesInputPageComponents.GAS_SPECIES_LAYOUT: self.remove_gas_species(
                grid_enum))

    def update_combo_boxes(self) -> None:
        """
        Update combo boxes
        Returns
        -------

        """
        composition_box = self.find_widget(PropertiesInputPageComponents.COMPOSITION_SELECTION)
        composition_box.addItems([c.value for c in CompositionType])

        database_box = self.find_widget(PropertiesInputPageComponents.DATABASE_SELECTION)
        database_box.addItems([c.value for c in DatabaseType])
        database_box.currentIndexChanged.connect(self.select_database_and_clean_input)

        pressure_box = self.find_widget(PropertiesInputPageComponents.PRESSURE_UD)
        pressure_box.addItems(self.ud_handler.pressure_ud)

        temperature_box = self.find_widget(PropertiesInputPageComponents.TEMPERATURE_UD)
        temperature_box.addItems(self.ud_handler.temperature_ud)

    def update_edit_lines(self) -> None:
        """
        Update edit lines
        Returns
        -------

        """
        for widget_enum in [PropertiesInputPageComponents.TEMPERATURE_INPUT,
                            PropertiesInputPageComponents.PRESSURE_INPUT]:
            widget = self.find_widget(widget_enum)
            widget.setValidator(widget_enum.value.validator)
            widget.setAlignment(widget_enum.value.align)

    def select_database_and_clean_input(self) -> None:
        """
        Select the database and clean the input
        Returns
        -------

        """
        self.select_database(PropertiesInputPageComponents.DATABASE_SELECTION)

        database_box = self.find_widget(PropertiesInputPageComponents.DATABASE_SELECTION)
        database_type = DatabaseType(database_box.currentText())

        if DatabaseType.NONE == database_type:
            self.disable_widget(self.find_widget(PropertiesInputPageComponents.ADD_GAS_BUTTON))
            self.disable_widget(self.find_widget(PropertiesInputPageComponents.REMOVE_GAS_BUTTON))
        else:
            self.enable_widget(self.find_widget(PropertiesInputPageComponents.ADD_GAS_BUTTON))
            self.enable_widget(self.find_widget(PropertiesInputPageComponents.REMOVE_GAS_BUTTON))

        self.clear_grid_layout(self.find_widget(PropertiesInputPageComponents.GAS_SPECIES_LAYOUT))
        self.data_store.reset_data(DataKeys.GAS_NS)

    #
    # def update_specie_line(self) -> None:
    #     """
    #     Update specie line
    #     Returns
    #     -------
    #
    #     """
    #     edit_line = self.findChild(QLineEdit, InputCompositionConfig.GAS_SPECIE_EDIT_LINE_NAME.value.format(self.ns))
    #     edit_line.setValidator(QDoubleValidator(0.0, 1.0, 4))
    #
    # def add_specie_line(self) -> None:
    #     """
    #     Add specie line to the layout
    #     Returns
    #     -------
    #
    #     """
    #     self.ns = self.ns + 1
    #
    #     self._specie_row_idx = self._specie_row_idx + 1
    #     self.add_gas_specie_input_row_to_grid_layout(PropertiesInputPageComponents.GRID_LAYOUT.value,
    #                                                  self.ns,
    #                                                  self._specie_row_idx,
    #                                                  with_label=True)
    #
    #     if self._specie_row_idx + 1 > self._button_row_idx:
    #         self._button_row_idx = self._specie_row_idx + 1
    #         grid_layout = self.findChild(QGridLayout, PropertiesInputPageComponents.GRID_LAYOUT.value)
    #         button = self.findChild(QPushButton, PropertiesInputPageComponents.NEXT_BUTTON.value)
    #         grid_layout.removeWidget(button)
    #         grid_layout.addWidget(button, self._button_row_idx, 0, 1, -1)
    #         self.update_grid_layout()
    #
    # def remove_specie_line(self):
    #     """
    #     Remove specie line from the layout
    #     Returns
    #     -------
    #
    #     """
    #     if self._specie_row_idx > CalculationInputPageConfig.INITIAL_SPECIE_ROW_IDX.value:
    #         self.ns = self.ns - 1
    #         self.remove_row_from_grid_layout(PropertiesInputPageComponents.GRID_LAYOUT.value, self._specie_row_idx)
    #         self._specie_row_idx = self._specie_row_idx - 1
    #
    # def next_button_action(self) -> pyqtSignal | None:
    #     """
    #     Action related to the next button
    #     Returns
    #     -------
    #     signal: pyqtSignal
    #         Signal with the next page name
    #     """
    #     self.read_data()
    #
    #     combo_box = self.findChild(QComboBox, PropertiesInputPageComponents.CALCULATION_COMBO_BOX.value)
    #     if combo_box.currentIndex() == 0:
    #         # Thermodynamic and transport properties
    #         return self.page_switched.emit(PropertiesOutputPageConfig.NAME.value)
    #     elif combo_box.currentIndex() == 1:
    #         # Linear regression of thermodynamic and transport properties
    #         return self.page_switched.emit(RegressionOutputPageConfig.NAME.value)
    #
    #     elif combo_box.currentIndex() == 2:
    #         # Vacuum properties
    #         return self.page_switched.emit(VacuumOutputPageConfig.NAME.value)
    #
    #     elif combo_box.currentIndex() == 3:
    #         # Chemical equilibrium
    #         return self.page_switched.emit(EquilibriumOutputPageConfig.NAME.value)
    #     elif combo_box.currentIndex() == 4:
    #         # Batch
    #         if self.data_store.get_data(DataKeys.IS_DEFAULT_FILE_PATH):
    #             self.dialog_handler.error_message(
    #                 QLabel('Default Cantera input file cannot be used for reactor modeling!'))
    #             return None
    #
    #         return self.page_switched.emit(BatchInputPageConfig.NAME.value)
    #
    #     elif combo_box.currentIndex() == 5:
    #         # CSTR
    #         if self.data_store.get_data(DataKeys.IS_DEFAULT_FILE_PATH):
    #             self.dialog_handler.error_message(
    #                 QLabel('Default Cantera input file cannot be used for reactor modeling!'))
    #             return None
    #
    #         return self.page_switched.emit(CstrInputPageConfig.NAME.value)
    #     elif combo_box.currentIndex() == 6:
    #         # 1d ph
    #         if self.data_store.get_data(DataKeys.IS_DEFAULT_FILE_PATH):
    #             self.dialog_handler.error_message(
    #                 QLabel('Default Cantera input file cannot be used for reactor modeling!'))
    #             return None
    #
    #         return self.page_switched.emit(Ph1dInputPageConfig.NAME.value)
    #     elif combo_box.currentIndex() == 7:
    #         #1d het
    #         if self.data_store.get_data(DataKeys.IS_DEFAULT_FILE_PATH):
    #             self.dialog_handler.error_message(
    #                 QLabel('Default Cantera input file cannot be used for reactor modeling!'))
    #             return None
    #
    #         return self.page_switched.emit(Het1dInputPageConfig.NAME.value)

    def calculate(self) -> pyqtSignal:
        """
        Calculate thermodynamic and transport properties and open the output window
        Returns
        -------

        """
