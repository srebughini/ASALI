from PyQt5.QtCore import Qt, pyqtSignal
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import QPushButton, QLineEdit, QComboBox, QLabel, QGridLayout
from PyQt5 import uic

from src.config.batch_input_page_config import BatchInputPageConfig
from src.config.calculation_input_page_config import CalculationInputPageConfig
from src.config.cstr_input_page_config import CstrInputPageConfig
from src.config.equilibrium_output_page_config import EquilibriumOutputPageConfig
from src.config.het_1d_input_page_config import Het1dInputPageConfig
from src.config.input_composition_config import InputCompositionConfig
from src.config.ph_1d_input_page_config import Ph1dInputPageConfig
from src.config.properties_output_page_config import PropertiesOutputPageConfig
from src.config.vacuum_output_page_config import VacuumOutputPageConfig
from src.core.composition_type import CompositionType
from src.core.data_keys import DataKeys
from src.core.species_names import gas_species_names
from src.gui.pages.basic_page import BasicPage
from src.gui.widgets.input.calculation_input_page import CalculationInputPageWidgets


class CalculationInputPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Calculation input page layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        uic.loadUi(CalculationInputPageConfig.PATH.value, self)

        self.data_store.update_data(DataKeys.INLET_NS.value, 0)

        self.update_temperature_line()
        self.update_pressure_line()
        self.update_buttons()
        self.update_specie_line()
        self.update_grid_layout()

        self._specie_row_idx = CalculationInputPageConfig.INITIAL_SPECIE_ROW_IDX.value
        self._button_row_idx = self._specie_row_idx + 1

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.data_store = gas_species_names(self.data_store)
        self.update_composition_names(0,
                                      self.data_store.get_data(DataKeys.GAS_SPECIES_NAMES.value),
                                      InputCompositionConfig.GAS_SPECIE_COMBO_BOX_NAME.value,
                                      InputCompositionConfig.GAS_SPECIE_EDIT_LINE_NAME.value)
        self.update_grid_layout()

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        # Temperature
        value = float(self.findChild(QLineEdit, CalculationInputPageWidgets.TEMPERATURE_EDIT_LINE.value).text())
        ud = self.findChild(QComboBox, CalculationInputPageWidgets.TEMPERATURE_COMBO_BOX.value).currentText()
        self.data_store.update_data(DataKeys.INLET_T.value, (value, ud))

        # Pressure
        value = float(self.findChild(QLineEdit, CalculationInputPageWidgets.PRESSURE_EDIT_LINE.value).text())
        ud = self.findChild(QComboBox, CalculationInputPageWidgets.PRESSURE_COMBO_BOX.value).currentText()
        self.data_store.update_data(DataKeys.INLET_P.value, (value, ud))

        # Composition
        value = {}
        for i in range(0, int(self.data_store.get_data(DataKeys.INLET_NS.value) + 1)):
            specie_name = self.findChild(QComboBox,
                                         InputCompositionConfig.GAS_SPECIE_COMBO_BOX_NAME.value.format(i)).currentText()
            specie_value = self.findChild(QLineEdit,
                                          InputCompositionConfig.GAS_SPECIE_EDIT_LINE_NAME.value.format(i)).text()
            value[specie_name] = float(specie_value)

        ud = self.findChild(QComboBox, CalculationInputPageWidgets.COMPOSITION_COMBO_BOX.value).currentText()
        if "mol" in ud.lower():
            self.data_store.update_data(DataKeys.INLET_GAS_COMPOSITION.value, (value, CompositionType.MOLE))
        else:
            self.data_store.update_data(DataKeys.INLET_GAS_COMPOSITION.value, (value, CompositionType.MASS))

    def update_temperature_line(self) -> None:
        """
        Update temperature input line
        Returns
        -------

        """
        edit_line = self.findChild(QLineEdit, CalculationInputPageWidgets.TEMPERATURE_EDIT_LINE.value)
        edit_line.setValidator(QDoubleValidator(0.0, 3000.0, 2))
        edit_line.setAlignment(Qt.AlignRight)

        dropdown = self.findChild(QComboBox, CalculationInputPageWidgets.TEMPERATURE_COMBO_BOX.value)
        dropdown.addItems(self.ud_handler.temperature_ud)

    def update_pressure_line(self) -> None:
        """
        Update pressure input line
        Returns
        -------

        """
        edit_line = self.findChild(QLineEdit, CalculationInputPageWidgets.PRESSURE_EDIT_LINE.value)
        edit_line.setValidator(QDoubleValidator(0.0, 1e09, 2))
        edit_line.setAlignment(Qt.AlignRight)

        dropdown = self.findChild(QComboBox, CalculationInputPageWidgets.PRESSURE_COMBO_BOX.value)
        dropdown.addItems(self.ud_handler.pressure_ud)

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """

        add_specie_button = self.findChild(QPushButton, CalculationInputPageWidgets.ADD_GAS_SPECIE_BUTTON.value)
        add_specie_button.clicked.connect(self.add_specie_line)

        remove_specie_button = self.findChild(QPushButton, CalculationInputPageWidgets.REMOVE_GAS_SPECIE_BUTTON.value)
        remove_specie_button.clicked.connect(self.remove_specie_line)

        next_button = self.findChild(QPushButton, CalculationInputPageWidgets.NEXT_BUTTON.value)
        next_button.clicked.connect(self.next_button_action)

    def update_specie_line(self) -> None:
        """
        Update specie line
        Returns
        -------

        """
        ns = self.data_store.get_data(DataKeys.INLET_NS.value)
        edit_line = self.findChild(QLineEdit, InputCompositionConfig.GAS_SPECIE_EDIT_LINE_NAME.value.format(ns))
        edit_line.setValidator(QDoubleValidator(0.0, 1.0, 4))

    def add_specie_line(self) -> None:
        """
        Add specie line to the layout
        Returns
        -------

        """
        ns = int(self.data_store.get_data(DataKeys.INLET_NS.value) + 1)
        self.data_store.update_data(DataKeys.INLET_NS.value, ns)

        self._specie_row_idx = self._specie_row_idx + 1
        self.add_gas_specie_input_row_to_grid_layout(CalculationInputPageWidgets.GRID_LAYOUT.value,
                                                     ns,
                                                     self._specie_row_idx,
                                                     with_label=True)

        if self._specie_row_idx + 1 > self._button_row_idx:
            self._button_row_idx = self._specie_row_idx + 1
            grid_layout = self.findChild(QGridLayout, CalculationInputPageWidgets.GRID_LAYOUT.value)
            button = self.findChild(QPushButton, CalculationInputPageWidgets.NEXT_BUTTON.value)
            grid_layout.removeWidget(button)
            grid_layout.addWidget(button, self._button_row_idx, 0, 1, -1)
            self.update_grid_layout()

    def remove_specie_line(self):
        """
        Remove specie line from the layout
        Returns
        -------

        """
        if self._specie_row_idx > CalculationInputPageConfig.INITIAL_SPECIE_ROW_IDX.value:
            ns = self.data_store.get_data(DataKeys.INLET_NS.value)
            self.data_store.update_data(DataKeys.INLET_NS.value, ns - 1)

            self.remove_row_from_grid_layout(CalculationInputPageWidgets.GRID_LAYOUT.value, self._specie_row_idx)
            self._specie_row_idx = self._specie_row_idx - 1

    def next_button_action(self) -> pyqtSignal | None:
        """
        Action related to the next button
        Returns
        -------
        signal: pyqtSignal
            Signal with the next page name
        """
        self.read_data()

        combo_box = self.findChild(QComboBox, CalculationInputPageWidgets.CALCULATION_COMBO_BOX.value)
        if combo_box.currentIndex() == 0:
            # Thermodynamic and transport properties
            return self.page_switched.emit(PropertiesOutputPageConfig.NAME.value)

        elif combo_box.currentIndex() == 1:
            # Vacuum properties
            return self.page_switched.emit(VacuumOutputPageConfig.NAME.value)

        elif combo_box.currentIndex() == 2:
            # Chemical equilibrium
            return self.page_switched.emit(EquilibriumOutputPageConfig.NAME.value)
        elif combo_box.currentIndex() == 3:
            # Batch
            if self.data_store.get_data(DataKeys.IS_DEFAULT_FILE_PATH.value):
                self.dialog_handler.error_message(
                    QLabel('Default Cantera input file cannot be used for reactor modeling!'))
                return None

            return self.page_switched.emit(BatchInputPageConfig.NAME.value)

        elif combo_box.currentIndex() == 4:
            # CSTR
            if self.data_store.get_data(DataKeys.IS_DEFAULT_FILE_PATH.value):
                self.dialog_handler.error_message(
                    QLabel('Default Cantera input file cannot be used for reactor modeling!'))
                return None

            return self.page_switched.emit(CstrInputPageConfig.NAME.value)
        elif combo_box.currentIndex() == 5:
            # 1d ph
            if self.data_store.get_data(DataKeys.IS_DEFAULT_FILE_PATH.value):
                self.dialog_handler.error_message(
                    QLabel('Default Cantera input file cannot be used for reactor modeling!'))
                return None

            return self.page_switched.emit(Ph1dInputPageConfig.NAME.value)
        elif combo_box.currentIndex() == 6:
            #1d het
            if self.data_store.get_data(DataKeys.IS_DEFAULT_FILE_PATH.value):
                self.dialog_handler.error_message(
                    QLabel('Default Cantera input file cannot be used for reactor modeling!'))
                return None

            return self.page_switched.emit(Het1dInputPageConfig.NAME.value)
