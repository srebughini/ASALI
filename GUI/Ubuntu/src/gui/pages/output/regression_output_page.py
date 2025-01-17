from PyQt5 import uic
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import QLabel, QPushButton, QComboBox, QLineEdit

from src.config.input.calculation_input_page import CalculationInputPageConfig
from src.config.output.regression_output_page_config import RegressionOutputPageConfig
from src.config.output.regression_plot_output_page_config import RegressionPlotOutputPageConfig
from src.controllers.label_formatter import LabelFormatter
from src.core.data_keys import DataKeys
from src.core.power_law_regression_calculator import power_law_regression_calculator
from src.core.linear_regression_calculator import linear_regression_calculator
from src.gui.pages.basic_page import BasicPage
from src.gui.widgets.output.regression_output_page import RegressionOutputPageWidgets


class RegressionOutputPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Regression output layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        uic.loadUi(RegressionOutputPageConfig.PATH.value, self)

        self.update_head_lines()
        self.update_unit_dimensions(RegressionOutputPageWidgets.TEMPERATURE_COMBO_BOX.value,
                                    self.ud_handler.temperature_ud)
        self.update_unit_dimensions(RegressionOutputPageWidgets.DENSITY_COMBO_BOX.value,
                                    self.ud_handler.density_ud)
        self.update_unit_dimensions(RegressionOutputPageWidgets.VISCOSITY_COMBO_BOX.value,
                                    self.ud_handler.viscosity_ud)
        self.update_unit_dimensions(RegressionOutputPageWidgets.THERMAL_CONDUCTIVITY_COMBO_BOX.value,
                                    self.ud_handler.thermal_conductivity_ud)
        self.update_unit_dimensions(RegressionOutputPageWidgets.ENTHALPY_COMBO_BOX.value,
                                    self.ud_handler.enthalpy_ud)
        self.update_unit_dimensions(RegressionOutputPageWidgets.ENTROPY_COMBO_BOX.value,
                                    self.ud_handler.entropy_ud)
        self.update_unit_dimensions(RegressionOutputPageWidgets.SPECIFIC_HEAT_COMBO_BOX.value,
                                    self.ud_handler.specific_heat_ud)
        self.update_temperature()
        self.update_buttons()
        self.update_regression_method()

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
        label = self.findChild(QLabel, RegressionOutputPageWidgets.MATH_LABEL.value)
        label.setAlignment(Qt.AlignCenter)
        label.setProperty("class", "italic")

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        back_button = self.findChild(QPushButton, RegressionOutputPageWidgets.BACK_BUTTON.value)
        back_button.clicked.connect(lambda: self.page_switched.emit(CalculationInputPageConfig.NAME.value))

        calculate_button = self.findChild(QPushButton, RegressionOutputPageWidgets.CALCULATE_BUTTON.value)
        calculate_button.clicked.connect(self.run_regression)

        plot_button = self.findChild(QPushButton, RegressionOutputPageWidgets.PLOT_BUTTON.value)
        plot_button.clicked.connect(lambda: self.page_switched.emit(RegressionPlotOutputPageConfig.NAME.value))
        self.disable_widget(plot_button)

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
        dropdown.currentIndexChanged.connect(self.run_regression)

    def update_temperature(self) -> None:
        """
        Update specie line
        Returns
        -------

        """
        edit_line = self.findChild(QLineEdit, RegressionOutputPageWidgets.MIN_TEMPERATURE_EDIT_LINE.value)
        edit_line.setValidator(QDoubleValidator(0.0, 3000.0, 2))
        edit_line.setAlignment(Qt.AlignRight)

        edit_line = self.findChild(QLineEdit, RegressionOutputPageWidgets.MAX_TEMPERATURE_EDIT_LINE.value)
        edit_line.setValidator(QDoubleValidator(0.0, 3000.0, 2))
        edit_line.setAlignment(Qt.AlignRight)

    def update_regression_method(self) -> None:
        """
        Update regression method
        Returns
        -------

        """
        combo_box = self.findChild(QComboBox, RegressionOutputPageWidgets.REGRESSION_COMBO_BOX.value)
        combo_box.currentTextChanged.connect(self.update_shown_data)

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
            self.findChild(QLineEdit, RegressionOutputPageWidgets.MIN_TEMPERATURE_EDIT_LINE.value).text())
        max_value = float(
            self.findChild(QLineEdit, RegressionOutputPageWidgets.MAX_TEMPERATURE_EDIT_LINE.value).text())
        ud = self.findChild(QComboBox, RegressionOutputPageWidgets.TEMPERATURE_COMBO_BOX.value).currentText()

        self.data_store.update_data(DataKeys.MIN_TEMPERATURE, (min_value, ud))
        self.data_store.update_data(DataKeys.MAX_TEMPERATURE, (max_value, ud))

        self.data_store.update_data(DataKeys.RHO,
                                    ((0.0, 0.0),
                                     self.findChild(QComboBox,
                                                    RegressionOutputPageWidgets.DENSITY_COMBO_BOX.value).currentText()))
        self.data_store.update_data(DataKeys.MU,
                                    ((0.0, 0.0),
                                     self.findChild(QComboBox,
                                                    RegressionOutputPageWidgets.VISCOSITY_COMBO_BOX.value).currentText()))
        self.data_store.update_data(DataKeys.COND,
                                    ((0.0, 0.0),
                                     self.findChild(QComboBox,
                                                    RegressionOutputPageWidgets.THERMAL_CONDUCTIVITY_COMBO_BOX.value).currentText()))
        self.data_store.update_data(DataKeys.H,
                                    ((0.0, 0.0),
                                     self.findChild(QComboBox,
                                                    RegressionOutputPageWidgets.ENTHALPY_COMBO_BOX.value).currentText()))
        self.data_store.update_data(DataKeys.S,
                                    ((0.0, 0.0),
                                     self.findChild(QComboBox,
                                                    RegressionOutputPageWidgets.ENTROPY_COMBO_BOX.value).currentText()))
        self.data_store.update_data(DataKeys.CP,
                                    ((0.0, 0.0),
                                     self.findChild(QComboBox,
                                                    RegressionOutputPageWidgets.SPECIFIC_HEAT_COMBO_BOX.value).currentText()))

    def update_shown_data(self) -> None:
        """
        Update data based on selected regression method
        Returns
        -------

        """
        regression_method = self.findChild(QComboBox,
                                           RegressionOutputPageWidgets.REGRESSION_COMBO_BOX.value).currentIndex()

        math_label = self.findChild(QLabel, RegressionOutputPageWidgets.MATH_LABEL.value)

        if regression_method == 0:
            math_label.setText("a*T + b")
        elif regression_method == 1:
            math_label.setText("a*T^b")

    def run_regression(self) -> None:
        """
        Update shown data
        Returns
        -------

        """
        self.read_data()

        regression_method = self.findChild(QComboBox,
                                           RegressionOutputPageWidgets.REGRESSION_COMBO_BOX.value)

        self.data_store.update_data(DataKeys.REGRESSION_METHOD, regression_method.currentText())

        if regression_method.currentIndex() == 0:
            self.data_store = linear_regression_calculator(self.data_store)
        elif regression_method.currentIndex() == 1:
            self.data_store = power_law_regression_calculator(self.data_store)

        self.enable_widget(self.findChild(QPushButton, RegressionOutputPageWidgets.PLOT_BUTTON.value))

        a, b, _ = self.data_store.get_data(DataKeys.RHO)
        self.update_property_values(RegressionOutputPageWidgets.DENSITY_A_LABEL.value,
                                    RegressionOutputPageWidgets.DENSITY_B_LABEL.value,
                                    a,
                                    b)

        a, b, _ = self.data_store.get_data(DataKeys.MU)
        self.update_property_values(RegressionOutputPageWidgets.VISCOSITY_A_LABEL.value,
                                    RegressionOutputPageWidgets.VISCOSITY_B_LABEL.value,
                                    a,
                                    b)

        a, b, _ = self.data_store.get_data(DataKeys.COND)
        self.update_property_values(RegressionOutputPageWidgets.THERMAL_CONDUCTIVITY_A_LABEL.value,
                                    RegressionOutputPageWidgets.THERMAL_CONDUCTIVITY_B_LABEL.value,
                                    a,
                                    b)

        a, b, _ = self.data_store.get_data(DataKeys.CP)
        self.update_property_values(RegressionOutputPageWidgets.SPECIFIC_HEAT_A_LABEL.value,
                                    RegressionOutputPageWidgets.SPECIFIC_HEAT_B_LABEL.value,
                                    a,
                                    b)

        a, b, _ = self.data_store.get_data(DataKeys.H)
        self.update_property_values(RegressionOutputPageWidgets.ENTHALPY_A_LABEL.value,
                                    RegressionOutputPageWidgets.ENTHALPY_B_LABEL.value,
                                    a,
                                    b)

        a, b, _ = self.data_store.get_data(DataKeys.S)
        self.update_property_values(RegressionOutputPageWidgets.ENTROPY_A_LABEL.value,
                                    RegressionOutputPageWidgets.ENTROPY_B_LABEL.value,
                                    a,
                                    b)
