from PyQt5.QtCore import pyqtSignal
from PyQt5 import uic

from src.config.app import AppConfig
from src.core.species_names import gas_species_names
from src.gui.components.input.vacuum_page import VacuumInputPageComponents
from src.core.data_keys import DataKeys
from src.gui.enums.database_type import DatabaseType
from src.gui.pages.basic_page import BasicPage


class VacuumInputPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Vacuum input page layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        uic.loadUi(AppConfig.VACUUM_INPUT_PAGE.value.path, self)

        self.update_buttons()
        self.update_combo_boxes()
        self.update_edit_lines()
        self.set_custom_dimensions_to_grid_layout(self.find_widget(VacuumInputPageComponents.GRID))

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        last_active_window = self.data_store.get_data(DataKeys.LAST_ACTIVE_WINDOW)

        if AppConfig.VACUUM_OUTPUT_PAGE == last_active_window:
            self.data_store.update_data(DataKeys.LAST_ACTIVE_WINDOW, AppConfig.VACUUM_INPUT_PAGE)
        else:
            database_box = self.find_widget(VacuumInputPageComponents.DATABASE_SELECTION)
            database_box.setCurrentText(DatabaseType.NONE.value)
            self.select_database_and_clean_input()
            self.data_store.update_data(DataKeys.LAST_ACTIVE_WINDOW, AppConfig.VACUUM_INPUT_PAGE)

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        next_button = self.find_widget(VacuumInputPageComponents.NEXT_BUTTON)
        next_button.clicked.connect(self.calculate)

        back_button = self.find_widget(VacuumInputPageComponents.BACK_BUTTON)
        back_button.clicked.connect(lambda: self.page_switched.emit(AppConfig.MAIN_INPUT_PAGE))

    def update_combo_boxes(self) -> None:
        """
        Update combo boxes
        Returns
        -------

        """
        database_box = self.find_widget(VacuumInputPageComponents.DATABASE_SELECTION)
        database_box.addItems(VacuumInputPageComponents.DATABASE_SELECTION.value.items)
        database_box.currentIndexChanged.connect(self.select_database_and_clean_input)

        for widget_enum in [VacuumInputPageComponents.PRESSURE_UD,
                            VacuumInputPageComponents.TEMPERATURE_UD,
                            VacuumInputPageComponents.GEOMETRY_UD]:
            widget = self.find_widget(widget_enum)
            widget.addItems(widget_enum.value.items)

    def update_edit_lines(self) -> None:
        """
        Update edit lines
        Returns
        -------

        """
        for widget_enum in [VacuumInputPageComponents.TEMPERATURE_INPUT,
                            VacuumInputPageComponents.PRESSURE_INPUT,
                            VacuumInputPageComponents.GEOMETRY_INPUT]:
            widget = self.find_widget(widget_enum)
            widget.setValidator(widget_enum.value.validator)
            widget.setAlignment(widget_enum.value.align)

    def select_database_and_clean_input(self) -> None:
        """
        Select the database and clean the input
        Returns
        -------

        """
        self.select_database(VacuumInputPageComponents.DATABASE_SELECTION)

        database_box = self.find_widget(VacuumInputPageComponents.DATABASE_SELECTION)
        database_type = DatabaseType(database_box.currentText())

        species_box = self.find_widget(VacuumInputPageComponents.SPECIE_SELECTION)
        species_box.clear()

        if DatabaseType.NONE == database_type:
            self.disable_widget(self.find_widget(VacuumInputPageComponents.SPECIE_SELECTION))
            self.disable_widget(self.find_widget(VacuumInputPageComponents.NEXT_BUTTON))
        else:
            self.data_store = gas_species_names(self.data_store)
            species_box.addItems(self.data_store.get_data(DataKeys.GAS_SPECIES_NAMES))
            self.enable_widget(self.find_widget(VacuumInputPageComponents.SPECIE_SELECTION))
            self.enable_widget(self.find_widget(VacuumInputPageComponents.NEXT_BUTTON))

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        # Temperature
        value = float(self.find_widget(VacuumInputPageComponents.TEMPERATURE_INPUT).text())
        ud = self.find_widget(VacuumInputPageComponents.TEMPERATURE_UD).currentText()
        self.data_store.update_data(DataKeys.TEMPERATURE, (value, ud))

        # Pressure
        value = float(self.find_widget(VacuumInputPageComponents.PRESSURE_INPUT).text())
        ud = self.find_widget(VacuumInputPageComponents.PRESSURE_UD).currentText()
        self.data_store.update_data(DataKeys.PRESSURE, (value, ud))

        # Specie
        specie_name = self.find_widget(VacuumInputPageComponents.SPECIE_SELECTION).currentText()
        self.data_store.update_data(DataKeys.VACUUM_SPECIE, specie_name)

        # Geometry
        value = float(self.find_widget(VacuumInputPageComponents.GEOMETRY_INPUT).text())
        ud = self.find_widget(VacuumInputPageComponents.GEOMETRY_UD).currentText()
        self.data_store.update_data(DataKeys.VACUUM_LENGTH, (value, ud))

    def calculate(self) -> pyqtSignal:
        """
        Calculate vacuum properties and open the output window
        Returns
        -------

        """
        self.read_data()
        return self.page_switched.emit(AppConfig.VACUUM_OUTPUT_PAGE)
