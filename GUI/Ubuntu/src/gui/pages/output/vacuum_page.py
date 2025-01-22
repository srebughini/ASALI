from PyQt5 import uic

from src.config.app import AppConfig
from src.core.data_keys import DataKeys
from src.core.vacuum_calculator import vacuum_calculator
from src.gui.pages.basic_page import BasicPage
from src.gui.components.output.vacuum_page import VacuumOutputPageComponents


class VacuumOutputPage(BasicPage):
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
        uic.loadUi(AppConfig.VACUUM_OUTPUT_PAGE.value.path, self)

        self.update_buttons()
        self.update_head_lines()
        self.update_combo_boxes()
        self.update_edit_lines()
        self.set_custom_dimensions_to_grid_layout(self.find_widget(VacuumOutputPageComponents.GRID))

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.set_custom_dimensions_to_grid_layout(self.find_widget(VacuumOutputPageComponents.GRID))
        self.data_store.update_data(DataKeys.LAST_ACTIVE_WINDOW, AppConfig.VACUUM_OUTPUT_PAGE)

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        back_button = self.find_widget(VacuumOutputPageComponents.BACK_BUTTON)
        back_button.clicked.connect(lambda: self.page_switched.emit(AppConfig.VACUUM_INPUT_PAGE))

        calculate_button = self.find_widget(VacuumOutputPageComponents.UPDATE_BUTTON)
        calculate_button.clicked.connect(self.show_data)

    def update_head_lines(self) -> None:
        """
        Update head lines
        Returns
        -------

        """
        widget_enum = VacuumOutputPageComponents.HEADLINE
        label = self.find_widget(widget_enum)
        label.setAlignment(widget_enum.value.align)
        label.setProperty("class", widget_enum.value.style)

    def update_combo_boxes(self) -> None:
        """
        Update combo boxes
        Returns
        -------

        """
        for widget_enum in [VacuumOutputPageComponents.VELOCITY_UD,
                            VacuumOutputPageComponents.DIFFUSIVITY_UD,
                            VacuumOutputPageComponents.MEAN_FREE_PATH_UD]:
            widget = self.find_widget(widget_enum)
            widget.clear()
            widget.addItems(widget_enum.value.items)

    def update_edit_lines(self) -> None:
        """
        Update edit lines
        Returns
        -------

        """
        for widget_enum in [VacuumOutputPageComponents.VELOCITY_VALUE,
                            VacuumOutputPageComponents.DIFFUSIVITY_VALUE,
                            VacuumOutputPageComponents.MEAN_FREE_PATH_VALUE,
                            VacuumOutputPageComponents.KNUDSEN_VALUE]:
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
        for widget_enum in [VacuumOutputPageComponents.VELOCITY_UD,
                            VacuumOutputPageComponents.DIFFUSIVITY_UD,
                            VacuumOutputPageComponents.MEAN_FREE_PATH_UD]:
            widget = self.find_widget(widget_enum)
            ud = widget.currentText()
            self.data_store.update_data(widget_enum.value.data_key, (0.0, ud))

    def show_data(self) -> None:
        """
        Update shown data
        Returns
        -------

        """
        self.read_data()
        self.data_store = vacuum_calculator(self.data_store)

        for widget_enum in [VacuumOutputPageComponents.VELOCITY_VALUE,
                            VacuumOutputPageComponents.DIFFUSIVITY_VALUE,
                            VacuumOutputPageComponents.MEAN_FREE_PATH_VALUE]:
            text = self.data_store.get_data(widget_enum.value.data_key)[0]
            self.set_formatted_text_to_label(widget_enum, text)

        widget_enum = VacuumOutputPageComponents.KNUDSEN_VALUE
        text = self.data_store.get_data(widget_enum.value.data_key)
        self.set_formatted_text_to_label(widget_enum, text)

        self.set_custom_dimensions_to_grid_layout(self.find_widget(VacuumOutputPageComponents.GRID))