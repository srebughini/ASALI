from PyQt5 import uic
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QPushButton, QLabel, QComboBox

from src.config.input.calculation_input_page import CalculationInputPageConfig
from src.config.output.equilibrium_output_page import EquilibriumOutputPageConfig
from src.controllers.label_formatter import LabelFormatter
from src.core.data_keys import DataKeys
from src.core.equilibrium_calculator import equilibrium_calculator
from src.gui.pages.basic_page import BasicPage
from src.gui.components.output.equilibrium_output_page import EquilibriumOutputPageWidgets


class EquilibriumOutputPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Equilibrium output layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        uic.loadUi(EquilibriumOutputPageConfig.PATH.value, self)
        self.update_head_lines()
        self.update_property_line(EquilibriumOutputPageWidgets.TEMPERATURE_LABEL.value, 
                                  EquilibriumOutputPageWidgets.TEMPERATURE_COMBO_BOX.value, 
                                  self.ud_handler.temperature_ud)
        self.update_property_line(EquilibriumOutputPageWidgets.PRESSURE_LABEL.value,
                                  EquilibriumOutputPageWidgets.PRESSURE_COMBO_BOX.value,
                                  self.ud_handler.pressure_ud)
        self.update_property_line(EquilibriumOutputPageWidgets.NAMES_LABEL.value, None, None)
        self.update_property_line(EquilibriumOutputPageWidgets.MOLE_FRACTION_LABEL.value, None, None)
        self.update_property_line(EquilibriumOutputPageWidgets.MASS_FRACTION_LABEL.value, None, None)
        self.update_buttons()

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.set_custom_dimensions_to_grid_layout()

    def update_property_line(self, value_label_name, combo_box_name, ud_list) -> None:
        """
        Update property output line
        Parameters
        ----------
        value_label_name: str
            Value label name
        combo_box_name: str | None
            Unit dimension combo box name
        ud_list: list | None
            Unit dimensions

        Returns
        -------

        """
        label = self.findChild(QLabel, value_label_name)
        label.setAlignment(Qt.AlignVCenter)
        label.setTextInteractionFlags(Qt.TextSelectableByMouse)

        if combo_box_name is not None:
            dropdown = self.findChild(QComboBox, combo_box_name)
            dropdown.addItems(ud_list)
            dropdown.currentIndexChanged.connect(self.update_shown_data)

    def update_property_value(self, value_label_name, value):
        """
        Update property value
        Parameters
        ----------
        value_label_name
        value

        Returns
        -------

        """
        if isinstance(value, float):
            label = self.findChild(QLabel, value_label_name)
            label.setText(LabelFormatter.float_to_string(value))

        if isinstance(value, list):
            label = self.findChild(QLabel, value_label_name)
            label.setText(LabelFormatter.list_to_string(value))

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        back_button = self.findChild(QPushButton, EquilibriumOutputPageWidgets.BACK_BUTTON.value)
        back_button.clicked.connect(lambda: self.page_switched.emit(CalculationInputPageConfig.NAME.value))

        calculate_button = self.findChild(QPushButton, EquilibriumOutputPageWidgets.CALCULATE_BUTTON.value)
        calculate_button.clicked.connect(self.update_shown_data)

    def update_head_lines(self) -> None:
        """
        Update head lines
        Returns
        -------

        """
        label = self.findChild(QLabel, EquilibriumOutputPageWidgets.OUTPUT_LABEL.value)
        label.setAlignment(Qt.AlignCenter)
        label.setProperty("class", "highlight")

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        ud = self.findChild(QComboBox, EquilibriumOutputPageWidgets.TEMPERATURE_COMBO_BOX.value).currentText()
        self.data_store.update_data(DataKeys.EQUILIBRIUM_T, (0.0, ud))

        ud = self.findChild(QComboBox, EquilibriumOutputPageWidgets.PRESSURE_COMBO_BOX.value).currentText()
        self.data_store.update_data(DataKeys.EQUILIBRIUM_P, (0.0, ud))

        equilibrium_type = self.findChild(QComboBox,
                                          EquilibriumOutputPageWidgets.EQUILIBRIUM_TYPE_COMBO_BOX.value).currentText()
        self.data_store.update_data(DataKeys.EQUILIBRIUM_TYPE, equilibrium_type)

    def update_shown_data(self) -> None:
        """
        Update shown data
        Returns
        -------

        """
        self.read_data()
        self.data_store = equilibrium_calculator(self.data_store)

        self.update_property_value(EquilibriumOutputPageWidgets.TEMPERATURE_LABEL.value, 
                                   self.data_store.get_data(DataKeys.EQUILIBRIUM_T)[0])
        self.update_property_value(EquilibriumOutputPageWidgets.PRESSURE_LABEL.value,
                                   self.data_store.get_data(DataKeys.EQUILIBRIUM_P)[0])
        self.update_property_value(EquilibriumOutputPageWidgets.NAMES_LABEL.value,
                                   self.data_store.get_data(DataKeys.EQUILIBRIUM_N))
        self.update_property_value(EquilibriumOutputPageWidgets.MOLE_FRACTION_LABEL.value,
                                   self.data_store.get_data(DataKeys.EQUILIBRIUM_X))
        self.update_property_value(EquilibriumOutputPageWidgets.MASS_FRACTION_LABEL.value,
                                   self.data_store.get_data(DataKeys.EQUILIBRIUM_Y))

        self.set_custom_dimensions_to_grid_layout()
