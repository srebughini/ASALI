
from PyQt5 import uic

from src.config.app import AppConfig
from src.controllers.label_formatter import LabelFormatter
from src.core.data_keys import DataKeys
from src.core.equilibrium_calculator import equilibrium_calculator
from src.gui.enums.equilibrium_type import EquilibriumType
from src.gui.pages.basic_page import BasicPage
from src.gui.components.output.equilibrium_page import EquilibriumOutputPageComponents


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
        uic.loadUi(AppConfig.EQUILIBRIUM_OUTPUT_PAGE.value.path, self)
        self.update_head_lines()
        self.update_combo_boxes()
        self.update_buttons()
        self.update_edit_lines()

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.set_custom_dimensions_to_grid_layout(self.find_widget(EquilibriumOutputPageComponents.GRID))
        self.data_store.update_data(DataKeys.LAST_ACTIVE_WINDOW, AppConfig.EQUILIBRIUM_OUTPUT_PAGE)

    def update_combo_boxes(self) -> None:
        """
        Update combo boxes
        Returns
        -------

        """
        for widget_enum in [EquilibriumOutputPageComponents.TEMPERATURE_UD,
                            EquilibriumOutputPageComponents.PRESSURE_UD,
                            EquilibriumOutputPageComponents.EQUILIBRIUM_TYPE]:
            widget = self.find_widget(widget_enum)
            widget.addItems(widget_enum.value.items)

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        back_button = self.find_widget(EquilibriumOutputPageComponents.BACK_BUTTON)
        back_button.clicked.connect(lambda: self.page_switched.emit(AppConfig.EQUILIBRIUM_INPUT_PAGE))

        calculate_button = self.find_widget(EquilibriumOutputPageComponents.UPDATE_BUTTON)
        calculate_button.clicked.connect(self.show_data)

    def update_head_lines(self) -> None:
        """
        Update head lines
        Returns
        -------

        """
        for widget_enum in [EquilibriumOutputPageComponents.HEADLINE]:
            label = self.find_widget(widget_enum)
            label.setAlignment(widget_enum.value.align)
            label.setProperty("class", widget_enum.value.style)

    def update_edit_lines(self) -> None:
        """
        Update edit lines
        Returns
        -------

        """
        for widget_enum in [EquilibriumOutputPageComponents.TEMPERATURE,
                            EquilibriumOutputPageComponents.PRESSURE,
                            EquilibriumOutputPageComponents.MASS_FRACTION,
                            EquilibriumOutputPageComponents.MOLE_FRACTION,
                            EquilibriumOutputPageComponents.NAMES]:
            widget = self.find_widget(widget_enum)
            widget.setText(widget_enum.value.text)
            widget.setAlignment(widget_enum.value.align)
            widget.setTextInteractionFlags(widget_enum.value.text_interaction)

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        ud = self.find_widget(EquilibriumOutputPageComponents.TEMPERATURE_UD).currentText()
        self.data_store.update_data(DataKeys.EQ_TEMPERATURE, (0.0, ud))

        ud = self.find_widget(EquilibriumOutputPageComponents.PRESSURE_UD).currentText()
        self.data_store.update_data(DataKeys.EQ_PRESSURE, (0.0, ud))

        equilibrium_type = self.find_widget(EquilibriumOutputPageComponents.EQUILIBRIUM_TYPE).currentText()
        self.data_store.update_data(DataKeys.EQUILIBRIUM_TYPE, EquilibriumType(equilibrium_type))

    def show_data(self) -> None:
        """
        Update shown data
        Returns
        -------

        """
        self.read_data()
        self.data_store = equilibrium_calculator(self.data_store)

        for widget_enum, key in {EquilibriumOutputPageComponents.TEMPERATURE: DataKeys.EQ_TEMPERATURE,
                                 EquilibriumOutputPageComponents.PRESSURE: DataKeys.EQ_PRESSURE,
                                 EquilibriumOutputPageComponents.MOLE_FRACTION: DataKeys.EQ_MOLE_FRACTION,
                                 EquilibriumOutputPageComponents.MASS_FRACTION: DataKeys.EQ_MASS_FRACTION,
                                 EquilibriumOutputPageComponents.NAMES: DataKeys.EQ_SPECIE_NAMES}.items():
            widget = self.find_widget(widget_enum)
            data = self.data_store.get_data(key)
            if isinstance(data, list):
                widget.setText(LabelFormatter.list_to_string(data))
            elif isinstance(data, tuple):
                widget.setText(LabelFormatter.float_to_string(data[0]))
            else:
                widget.setText(LabelFormatter.float_to_string(data))

        self.set_custom_dimensions_to_grid_layout(self.find_widget(EquilibriumOutputPageComponents.GRID))
