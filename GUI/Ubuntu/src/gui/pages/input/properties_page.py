from PyQt5.QtCore import pyqtSignal
from PyQt5.QtWidgets import QLineEdit, QComboBox
from PyQt5 import uic

from src.config.app import AppConfig
from src.config.input_composition import InputCompositionConfig
from src.core.properties_calculator import properties_calculator
from src.gui.enums.composition_type import CompositionType
from src.core.data_keys import DataKeys
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
        last_active_window = self.data_store.get_data(DataKeys.LAST_ACTIVE_WINDOW)

        if AppConfig.PROPERTIES_OUTPUT_PAGE == last_active_window:
            self.data_store.update_data(DataKeys.LAST_ACTIVE_WINDOW, AppConfig.PROPERTIES_INPUT_PAGE)
        else:
            database_box = self.find_widget(PropertiesInputPageComponents.DATABASE_SELECTION)
            database_box.setCurrentText(DatabaseType.NONE.value)
            self.select_database_and_clean_input()
            self.data_store.update_data(DataKeys.LAST_ACTIVE_WINDOW, AppConfig.PROPERTIES_INPUT_PAGE)

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

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        # Temperature
        value = float(self.find_widget(PropertiesInputPageComponents.TEMPERATURE_INPUT).text())
        ud = self.find_widget(PropertiesInputPageComponents.TEMPERATURE_UD).currentText()
        self.data_store.update_data(DataKeys.TEMPERATURE, (value, ud))

        # Pressure
        value = float(self.find_widget(PropertiesInputPageComponents.PRESSURE_INPUT).text())
        ud = self.find_widget(PropertiesInputPageComponents.PRESSURE_UD).currentText()
        self.data_store.update_data(DataKeys.PRESSURE, (value, ud))

        # Composition
        value = {}
        for i in range(0, int(self.data_store.get_data(DataKeys.GAS_NS) + 1)):
            specie_name = self.findChild(QComboBox,
                                         InputCompositionConfig.GAS_SPECIE_COMBO_BOX_NAME.value.format(i)).currentText()
            specie_value = self.findChild(QLineEdit,
                                          InputCompositionConfig.GAS_SPECIE_EDIT_LINE_NAME.value.format(i)).text()
            value[specie_name] = float(specie_value)

        composition_type = CompositionType(
            self.find_widget(PropertiesInputPageComponents.COMPOSITION_SELECTION).currentText())
        self.data_store.update_data(DataKeys.GAS_COMPOSITION, (value, composition_type))

    def calculate(self) -> pyqtSignal:
        """
        Calculate thermodynamic and transport properties and open the output window
        Returns
        -------

        """
        self.read_data()
        return self.page_switched.emit(AppConfig.PROPERTIES_OUTPUT_PAGE)
