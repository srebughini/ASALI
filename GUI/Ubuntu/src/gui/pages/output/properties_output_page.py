from PyQt5 import uic
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QLabel, QComboBox, QPushButton

from src.config.calculation_input_page_config import CalculationInputPageConfig
from src.config.properties_output_page_config import PropertiesOutputPageConfig
from src.controllers.label_formatter import LabelFormatter
from src.core.data_keys import DataKeys
from src.core.properties_calculator import properties_calculator
from src.config.app_config import AppConfig
from src.gui.pages.basic_page import BasicPage
from src.gui.widgets.output.properties_output_page import PropertiesOutputPageWidgets


class PropertiesOutputPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Thermodynamic and transport properties output layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        uic.loadUi(PropertiesOutputPageConfig.PATH.value, self)

        self.update_head_lines()
        self.update_property_line(PropertiesOutputPageWidgets.DENSITY_LABEL.value,
                                  PropertiesOutputPageWidgets.DENSITY_COMBO_BOX.value,
                                  self.ud_handler.density_ud)
        self.update_property_line(PropertiesOutputPageWidgets.VISCOSITY_LABEL.value,
                                  PropertiesOutputPageWidgets.VISCOSITY_COMBO_BOX.value,
                                  self.ud_handler.viscosity_ud)
        self.update_property_line(PropertiesOutputPageWidgets.THERMAL_CONDUCTIVITY_LABEL.value,
                                  PropertiesOutputPageWidgets.THERMAL_CONDUCTIVITY_COMBO_BOX.value,
                                  self.ud_handler.thermal_conductivity_ud)
        self.update_property_line(PropertiesOutputPageWidgets.DIFFUSIVITY_LABEL.value,
                                  PropertiesOutputPageWidgets.DIFFUSIVITY_COMBO_BOX.value,
                                  self.ud_handler.diffusivity_ud)
        self.update_property_line(PropertiesOutputPageWidgets.MOLECULAR_WEIGHT_LABEL.value,
                                  PropertiesOutputPageWidgets.MOLECULAR_WEIGHT_COMBO_BOX.value,
                                  self.ud_handler.molecular_weight_ud)
        self.update_property_line(PropertiesOutputPageWidgets.ENTHALPY_LABEL.value,
                                  PropertiesOutputPageWidgets.ENTHALPY_COMBO_BOX.value,
                                  self.ud_handler.enthalpy_ud)
        self.update_property_line(PropertiesOutputPageWidgets.ENTROPY_LABEL.value,
                                  PropertiesOutputPageWidgets.ENTROPY_COMBO_BOX.value,
                                  self.ud_handler.entropy_ud)
        self.update_property_line(PropertiesOutputPageWidgets.SPECIFIC_HEAT_LABEL.value,
                                  PropertiesOutputPageWidgets.SPECIFIC_HEAT_COMBO_BOX.value,
                                  self.ud_handler.specific_heat_ud)
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
        combo_box_name: str
            Unit dimension combo box name
        ud_list: list
            Unit dimensions

        Returns
        -------

        """
        label = self.findChild(QLabel, value_label_name)
        label.setText(LabelFormatter.pad_string("0.0"))
        label.setAlignment(Qt.AlignVCenter)
        label.setTextInteractionFlags(Qt.TextSelectableByMouse)

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

        if isinstance(value, dict):
            label = self.findChild(QLabel, value_label_name)
            label.setText(LabelFormatter.dict_to_string(value))

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        back_button = self.findChild(QPushButton, PropertiesOutputPageWidgets.BACK_BUTTON.value)
        back_button.clicked.connect(lambda: self.page_switched.emit(CalculationInputPageConfig.NAME.value))

        calculate_button = self.findChild(QPushButton, PropertiesOutputPageWidgets.CALCULATE_BUTTON.value)
        calculate_button.clicked.connect(self.update_shown_data)

    def update_head_lines(self) -> None:
        """
        Update head lines
        Returns
        -------

        """
        for n in [PropertiesOutputPageWidgets.TRANSPORT_LABEL,
                  PropertiesOutputPageWidgets.THERMODYNAMIC_LABEL]:
            label = self.findChild(QLabel, n.value)
            label.setAlignment(Qt.AlignCenter)
            label.setProperty("class", "highlight")

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        self.data_store.update_data(DataKeys.RHO,
                                    (0.0,
                                     self.findChild(QComboBox,
                                                    PropertiesOutputPageWidgets.DENSITY_COMBO_BOX.value).currentText()))
        self.data_store.update_data(DataKeys.MU,
                                    (0.0,
                                     self.findChild(QComboBox,
                                                    PropertiesOutputPageWidgets.VISCOSITY_COMBO_BOX.value).currentText()))
        self.data_store.update_data(DataKeys.MW,
                                    (0.0,
                                     self.findChild(QComboBox,
                                                    PropertiesOutputPageWidgets.MOLECULAR_WEIGHT_COMBO_BOX.value).currentText()))
        self.data_store.update_data(DataKeys.COND,
                                    (0.0,
                                     self.findChild(QComboBox,
                                                    PropertiesOutputPageWidgets.THERMAL_CONDUCTIVITY_COMBO_BOX.value).currentText()))
        self.data_store.update_data(DataKeys.DIFF_MIX,
                                    (0.0,
                                     self.findChild(QComboBox,
                                                    PropertiesOutputPageWidgets.DIFFUSIVITY_COMBO_BOX.value).currentText()))
        self.data_store.update_data(DataKeys.H,
                                    (0.0,
                                     self.findChild(QComboBox,
                                                    PropertiesOutputPageWidgets.ENTHALPY_COMBO_BOX.value).currentText()))
        self.data_store.update_data(DataKeys.S,
                                    (0.0,
                                     self.findChild(QComboBox,
                                                    PropertiesOutputPageWidgets.ENTROPY_COMBO_BOX.value).currentText()))
        self.data_store.update_data(DataKeys.CP,
                                    (0.0,
                                     self.findChild(QComboBox,
                                                    PropertiesOutputPageWidgets.SPECIFIC_HEAT_COMBO_BOX.value).currentText()))

    def update_shown_data(self) -> None:
        """
        Update shown data
        Returns
        -------

        """
        self.read_data()
        self.data_store = properties_calculator(self.data_store)

        self.update_property_value(PropertiesOutputPageWidgets.DENSITY_LABEL.value,
                                   self.data_store.get_data(DataKeys.RHO)[0])
        self.update_property_value(PropertiesOutputPageWidgets.THERMAL_CONDUCTIVITY_LABEL.value,
                                   self.data_store.get_data(DataKeys.COND)[0])
        self.update_property_value(PropertiesOutputPageWidgets.MOLECULAR_WEIGHT_LABEL.value,
                                   self.data_store.get_data(DataKeys.MW)[0])
        self.update_property_value(PropertiesOutputPageWidgets.VISCOSITY_LABEL.value,
                                   self.data_store.get_data(DataKeys.MU)[0])
        self.update_property_value(PropertiesOutputPageWidgets.DIFFUSIVITY_LABEL.value,
                                   self.data_store.get_data(DataKeys.DIFF_MIX)[0])
        self.update_property_value(PropertiesOutputPageWidgets.ENTHALPY_LABEL.value,
                                   self.data_store.get_data(DataKeys.H)[0])
        self.update_property_value(PropertiesOutputPageWidgets.ENTROPY_LABEL.value,
                                   self.data_store.get_data(DataKeys.S)[0])
        self.update_property_value(PropertiesOutputPageWidgets.SPECIFIC_HEAT_LABEL.value,
                                   self.data_store.get_data(DataKeys.CP)[0])

        self.update_grid_layout()
