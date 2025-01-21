from PyQt5 import uic
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QLabel, QComboBox, QPushButton

from src.config.app import AppConfig
from src.config.input.calculation_input_page import CalculationInputPageConfig
from src.config.output.properties_output_page import PropertiesOutputPageConfig
from src.controllers.label_formatter import LabelFormatter
from src.core.data_keys import DataKeys
from src.core.properties_calculator import properties_calculator
from src.gui.pages.basic_page import BasicPage
from src.gui.components.output.properties_page import PropertiesOutputPageComponents


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

        self.update_buttons()
        self.update_head_lines()
        self.update_combo_boxes()
        self.update_edit_lines()
        self.set_custom_dimensions_to_grid_layout(self.find_widget(PropertiesOutputPageComponents.GRID))

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.set_custom_dimensions_to_grid_layout(self.find_widget(PropertiesOutputPageComponents.GRID))
        self.data_store.update_data(DataKeys.LAST_ACTIVE_WINDOW, AppConfig.PROPERTIES_OUTPUT_PAGE)

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        back_button = self.find_widget(PropertiesOutputPageComponents.BACK_BUTTON)
        back_button.clicked.connect(lambda: self.page_switched.emit(AppConfig.PROPERTIES_INPUT_PAGE))

        calculate_button = self.find_widget(PropertiesOutputPageComponents.UPDATE_BUTTON)
        calculate_button.clicked.connect(self.show_data)

    def update_head_lines(self) -> None:
        """
        Update head lines
        Returns
        -------

        """
        for widget_enum in [PropertiesOutputPageComponents.TRANSPORT_HEADLINE,
                            PropertiesOutputPageComponents.THERMODYNAMIC_HEADLINE]:
            label = self.find_widget(widget_enum)
            label.setAlignment(widget_enum.value.align)
            label.setProperty("class", widget_enum.value.style)

    def update_combo_boxes(self) -> None:
        """
        Update combo boxes
        Returns
        -------

        """
        for widget_enum, ud in {PropertiesOutputPageComponents.DENSITY_UD: self.ud_handler.density_ud,
                                PropertiesOutputPageComponents.VISCOSITY_UD: self.ud_handler.viscosity_ud,
                                PropertiesOutputPageComponents.SPECIFIC_HEAT_UD: self.ud_handler.specific_heat_ud,
                                PropertiesOutputPageComponents.ENTHALPY_UD: self.ud_handler.enthalpy_ud,
                                PropertiesOutputPageComponents.ENTROPY_UD: self.ud_handler.entropy_ud,
                                PropertiesOutputPageComponents.MOLECULAR_WEIGHT_UD: self.ud_handler.molecular_weight_ud,
                                PropertiesOutputPageComponents.THERMAL_CONDUCTIVITY_UD: self.ud_handler.thermal_conductivity_ud,
                                PropertiesOutputPageComponents.DIFFUSIVITY_UD: self.ud_handler.diffusivity_ud}.items():
            widget = self.find_widget(widget_enum)
            widget.clear()
            widget.addItems(ud)

    def update_edit_lines(self) -> None:
        """
        Update edit lines
        Returns
        -------

        """
        for widget_enum in [PropertiesOutputPageComponents.DENSITY_VALUE,
                            PropertiesOutputPageComponents.VISCOSITY_VALUE,
                            PropertiesOutputPageComponents.SPECIFIC_HEAT_VALUE,
                            PropertiesOutputPageComponents.ENTHALPY_VALUE,
                            PropertiesOutputPageComponents.ENTROPY_VALUE,
                            PropertiesOutputPageComponents.MOLECULAR_WEIGHT_VALUE,
                            PropertiesOutputPageComponents.THERMAL_CONDUCTIVITY_VALUE,
                            PropertiesOutputPageComponents.DIFFUSIVITY_VALUE]:
            widget = self.find_widget(widget_enum)
            widget.setText(widget_enum.value.text)
            widget.setAlignment(widget_enum.value.align)
            widget.setTextInteractionFlags(widget_enum.value.text_interaction)

    def read_data(self) -> None:
        """
        Update data store with properties unit dimensions
        Returns
        -------

        """
        for data_key, widget_enum in {DataKeys.RHO: PropertiesOutputPageComponents.DENSITY_UD,
                                      DataKeys.COND: PropertiesOutputPageComponents.THERMAL_CONDUCTIVITY_UD,
                                      DataKeys.MW: PropertiesOutputPageComponents.MOLECULAR_WEIGHT_UD,
                                      DataKeys.DIFF_MIX: PropertiesOutputPageComponents.DIFFUSIVITY_UD,
                                      DataKeys.MU: PropertiesOutputPageComponents.VISCOSITY_UD,
                                      DataKeys.H: PropertiesOutputPageComponents.ENTHALPY_UD,
                                      DataKeys.S: PropertiesOutputPageComponents.ENTROPY_UD,
                                      DataKeys.CP: PropertiesOutputPageComponents.SPECIFIC_HEAT_UD}.items():
            widget = self.find_widget(widget_enum)
            ud = widget.currentText()
            self.data_store.update_data(data_key, (0.0, ud))

    def show_data(self) -> None:
        """
        Update shown data
        Returns
        -------

        """
        self.read_data()
        self.data_store = properties_calculator(self.data_store)

        for data_key, widget_enum in {DataKeys.RHO: PropertiesOutputPageComponents.DENSITY_VALUE,
                                      DataKeys.COND: PropertiesOutputPageComponents.THERMAL_CONDUCTIVITY_VALUE,
                                      DataKeys.MW: PropertiesOutputPageComponents.MOLECULAR_WEIGHT_VALUE,
                                      DataKeys.DIFF_MIX: PropertiesOutputPageComponents.DIFFUSIVITY_VALUE,
                                      DataKeys.MU: PropertiesOutputPageComponents.VISCOSITY_VALUE,
                                      DataKeys.H: PropertiesOutputPageComponents.ENTHALPY_VALUE,
                                      DataKeys.S: PropertiesOutputPageComponents.ENTROPY_VALUE,
                                      DataKeys.CP: PropertiesOutputPageComponents.SPECIFIC_HEAT_VALUE}.items():
            text = self.data_store.get_data(data_key)[0]
            self.set_formatted_text_to_label(widget_enum, text)

        self.set_custom_dimensions_to_grid_layout(self.find_widget(PropertiesOutputPageComponents.GRID))
