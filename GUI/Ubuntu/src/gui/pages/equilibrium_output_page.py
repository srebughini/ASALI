from PyQt5 import uic
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import QPushButton, QLabel, QComboBox, QLineEdit

from src.controllers.label_formatter import LabelFormatter
from src.core.data_keys import DataKeys
from src.core.equilibrium_calculator import equilibrium_calculator
from src.gui.config import Config
from src.gui.pages.basic_page import BasicPage


class EquilibriumOutputPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Vacuum properties output layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        uic.loadUi(Config.EQUILIBRIUM_OUTPUT_PAGE_PATH.value, self)
        self.update_head_lines()
        self.update_property_line("temperatureValueLabel", "temperatureOutputComboBox", self.ud_handler.temperature_ud)
        self.update_property_line("pressureValueLabel", "pressureOutputComboBox", self.ud_handler.pressure_ud)
        self.update_property_line("nLabel", None, None)
        self.update_property_line("xLabel", None, None)
        self.update_property_line("yLabel", None, None)
        self.update_buttons()

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.update_grid_layout()

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
        back_button = self.findChild(QPushButton, 'backButton')
        back_button.clicked.connect(lambda: self.page_switched.emit(Config.CALCULATION_INPUT_PAGE_NAME.value))

        calculate_button = self.findChild(QPushButton, 'calculateButton')
        calculate_button.clicked.connect(self.update_shown_data)

    def update_head_lines(self) -> None:
        """
        Update head lines
        Returns
        -------

        """
        label = self.findChild(QLabel, 'outputLabel')
        label.setAlignment(Qt.AlignCenter)
        label.setProperty("class", "highlight")

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        ud = self.findChild(QComboBox, 'temperatureOutputComboBox').currentText()
        self.data_store.update_data(DataKeys.EQUILIBRIUM_T.value, (0.0, ud))

        ud = self.findChild(QComboBox, 'pressureOutputComboBox').currentText()
        self.data_store.update_data(DataKeys.EQUILIBRIUM_P.value, (0.0, ud))

        equilibrium_type = self.findChild(QComboBox, 'typeComboBox').currentText()
        self.data_store.update_data(DataKeys.EQUILIBRIUM_TYPE.value, equilibrium_type)

    def update_shown_data(self) -> None:
        """
        Update shown data
        Returns
        -------

        """
        self.read_data()
        self.data_store = equilibrium_calculator(self.data_store)

        self.update_property_value('temperatureValueLabel', self.data_store.get_data(DataKeys.EQUILIBRIUM_T.value)[0])
        self.update_property_value('pressureValueLabel', self.data_store.get_data(DataKeys.EQUILIBRIUM_P.value)[0])
        self.update_property_value('nLabel', self.data_store.get_data(DataKeys.EQUILIBRIUM_N.value))
        self.update_property_value('xLabel', self.data_store.get_data(DataKeys.EQUILIBRIUM_X.value))
        self.update_property_value('yLabel', self.data_store.get_data(DataKeys.EQUILIBRIUM_Y.value))

        self.update_grid_layout()
