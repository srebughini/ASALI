from PyQt5 import uic
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import QLabel, QPushButton, QComboBox, QLineEdit

from src.config.calculation_input_page_config import CalculationInputPageConfig
from src.config.linear_regression_output_page_config import LinearRegressionOutputPageConfig
from src.controllers.label_formatter import LabelFormatter
from src.core.data_keys import DataKeys
from src.core.linear_regression_calculator import linear_regression_calculator
from src.gui.pages.basic_page import BasicPage
from src.gui.widgets.output.linear_regression_output_page import LinearRegressionOutputPageWidgets


class LinearRegressionOutputPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Linear regression output layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        uic.loadUi(LinearRegressionOutputPageConfig.PATH.value, self)

        self.update_head_lines()
        self.update_unit_dimensions(LinearRegressionOutputPageWidgets.TEMPERATURE_COMBO_BOX.value,
                                    self.ud_handler.temperature_ud)
        self.update_unit_dimensions(LinearRegressionOutputPageWidgets.DENSITY_COMBO_BOX.value,
                                    self.ud_handler.density_ud)
        self.update_unit_dimensions(LinearRegressionOutputPageWidgets.VISCOSITY_COMBO_BOX.value,
                                    self.ud_handler.viscosity_ud)
        self.update_unit_dimensions(LinearRegressionOutputPageWidgets.THERMAL_CONDUCTIVITY_COMBO_BOX.value,
                                    self.ud_handler.thermal_conductivity_ud)
        self.update_unit_dimensions(LinearRegressionOutputPageWidgets.ENTHALPY_COMBO_BOX.value,
                                    self.ud_handler.enthalpy_ud)
        self.update_unit_dimensions(LinearRegressionOutputPageWidgets.ENTROPY_COMBO_BOX.value,
                                    self.ud_handler.entropy_ud)
        self.update_unit_dimensions(LinearRegressionOutputPageWidgets.SPECIFIC_HEAT_COMBO_BOX.value,
                                    self.ud_handler.specific_heat_ud)
        self.update_temperature()
        self.update_buttons()

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.update_grid_layout()

    def update_head_lines(self) -> None:
        """
        Update head lines
        Returns
        -------

        """
        label = self.findChild(QLabel, LinearRegressionOutputPageWidgets.HEADLINE_LABEL.value)
        label.setAlignment(Qt.AlignCenter)
        label.setProperty("class", "highlight")

        label = self.findChild(QLabel, LinearRegressionOutputPageWidgets.MATH_LABEL.value)
        label.setAlignment(Qt.AlignCenter)
        label.setProperty("class", "italic")

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        back_button = self.findChild(QPushButton, LinearRegressionOutputPageWidgets.BACK_BUTTON.value)
        back_button.clicked.connect(lambda: self.page_switched.emit(CalculationInputPageConfig.NAME.value))

        calculate_button = self.findChild(QPushButton, LinearRegressionOutputPageWidgets.CALCULATE_BUTTON.value)
        calculate_button.clicked.connect(self.update_shown_data)

    def update_unit_dimensions(self, combo_box_name, item_list) -> None:
        """
        Update combo box with unit dimensions
        Parameters
        ----------
        combo_box_name: str
            QComboBox widget name
        item_list: list
            Unit dimensions

        Returns
        -------

        """
        dropdown = self.findChild(QComboBox, combo_box_name)
        dropdown.addItems(item_list)
        dropdown.currentIndexChanged.connect(self.update_shown_data)

    def update_temperature(self) -> None:
        """
        Update specie line
        Returns
        -------

        """
        edit_line = self.findChild(QLineEdit, LinearRegressionOutputPageWidgets.MIN_TEMPERATURE_EDIT_LINE.value)
        edit_line.setValidator(QDoubleValidator(0.0, 3000.0, 2))
        edit_line.setAlignment(Qt.AlignRight)

        edit_line = self.findChild(QLineEdit, LinearRegressionOutputPageWidgets.MAX_TEMPERATURE_EDIT_LINE.value)
        edit_line.setValidator(QDoubleValidator(0.0, 3000.0, 2))
        edit_line.setAlignment(Qt.AlignRight)

    def update_property_values(self, a_label_name, b_label_name, a_value, b_value) -> None:
        """
        Update property linear coefficient values
        Parameters
        ----------
        a_label_name: str
            Slope label name
        b_label_name: str
            Intercept label name
        a_value: float
            Slope
        b_value: float
            Intercept

        Returns
        -------

        """
        label = self.findChild(QLabel, a_label_name)
        label.setText(LabelFormatter.float_to_string(a_value))

        label = self.findChild(QLabel, b_label_name)
        label.setText(LabelFormatter.float_to_string(b_value))

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        min_value = float(
            self.findChild(QLineEdit, LinearRegressionOutputPageWidgets.MIN_TEMPERATURE_EDIT_LINE.value).text())
        max_value = float(
            self.findChild(QLineEdit, LinearRegressionOutputPageWidgets.MAX_TEMPERATURE_EDIT_LINE.value).text())
        ud = self.findChild(QComboBox, LinearRegressionOutputPageWidgets.TEMPERATURE_COMBO_BOX.value).currentText()

        self.data_store.update_data(DataKeys.MIN_TEMPERATURE, (min_value, ud))
        self.data_store.update_data(DataKeys.MAX_TEMPERATURE, (max_value, ud))

        self.data_store.update_data(DataKeys.RHO,
                                    ((0.0, 0.0),
                                     self.findChild(QComboBox,
                                                    LinearRegressionOutputPageWidgets.DENSITY_COMBO_BOX.value).currentText()))
        self.data_store.update_data(DataKeys.MU,
                                    ((0.0, 0.0),
                                     self.findChild(QComboBox,
                                                    LinearRegressionOutputPageWidgets.VISCOSITY_COMBO_BOX.value).currentText()))
        self.data_store.update_data(DataKeys.COND,
                                    ((0.0, 0.0),
                                     self.findChild(QComboBox,
                                                    LinearRegressionOutputPageWidgets.THERMAL_CONDUCTIVITY_COMBO_BOX.value).currentText()))
        self.data_store.update_data(DataKeys.H,
                                    ((0.0, 0.0),
                                     self.findChild(QComboBox,
                                                    LinearRegressionOutputPageWidgets.ENTHALPY_COMBO_BOX.value).currentText()))
        self.data_store.update_data(DataKeys.S,
                                    ((0.0, 0.0),
                                     self.findChild(QComboBox,
                                                    LinearRegressionOutputPageWidgets.ENTROPY_COMBO_BOX.value).currentText()))
        self.data_store.update_data(DataKeys.CP,
                                    ((0.0, 0.0),
                                     self.findChild(QComboBox,
                                                    LinearRegressionOutputPageWidgets.SPECIFIC_HEAT_COMBO_BOX.value).currentText()))

    def update_shown_data(self) -> None:
        """
        Update shown data
        Returns
        -------

        """
        self.read_data()
        self.data_store = linear_regression_calculator(self.data_store)

        values = self.data_store.get_data(DataKeys.RHO)
        self.update_property_values(LinearRegressionOutputPageWidgets.DENSITY_A_LABEL.value,
                                    LinearRegressionOutputPageWidgets.DENSITY_B_LABEL.value,
                                    values[0],
                                    values[1])
