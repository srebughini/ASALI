from PyQt5.QtCore import pyqtSignal
from PyQt5 import uic

from src.config.icon import IconConfig
from src.config.app import AppConfig
from src.core.data_keys import DataKeys
from src.gui.pages.basic_page import BasicPage
from src.gui.components.input.main_page import MainInputPageComponents
import qtawesome as qta


class MainInputPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Main input page layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        uic.loadUi(AppConfig.MAIN_INPUT_PAGE.value.path, self)
        self.update_buttons()
        self.set_custom_dimensions_to_grid_layout(self.find_widget(MainInputPageComponents.GRID))

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.data_store.reset_all_data()
        self.set_custom_dimensions_to_grid_layout(self.find_widget(MainInputPageComponents.GRID))
        self.data_store.update_data(DataKeys.LAST_ACTIVE_WINDOW, AppConfig.MAIN_INPUT_PAGE)

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        for widget_enum, icon in {MainInputPageComponents.PROPERTIES_BUTTON: IconConfig.FLASK,
                                  MainInputPageComponents.VACUUM_BUTTON: IconConfig.ATOM,
                                  MainInputPageComponents.EQUILIBRIUM_BUTTON: IconConfig.BALANCE,
                                  MainInputPageComponents.REGRESSION_BUTTON: IconConfig.CHART,
                                  MainInputPageComponents.CHEMKIN_BUTTON: IconConfig.TASKS,
                                  MainInputPageComponents.PRESSURE_DROPS_BUTTON: IconConfig.WIND}.items():
            widget = self.find_widget(widget_enum)
            widget.setIcon(qta.icon(icon.value,
                                    color=IconConfig.COLOR.value,
                                    scale_factor=IconConfig.SCALE_FACTOR.value))  # Set the icon with blue color
            widget.setIconSize(IconConfig.SIZE.value)  # Set the icon size
            widget.setProperty("class", "icon")
            widget.clicked.connect(
                lambda checked, button_enum=widget_enum: self.open_selected_page(button_enum))

    def open_selected_page(self, button_enum) -> pyqtSignal:
        """
        Open the selected page
        Parameters
        ----------
        button_enum: Enum
            Button that has been clicked by the user

        Returns
        -------
        signal: pyqtSignal
            Signal with the next page name
        """
        if MainInputPageComponents.PROPERTIES_BUTTON == button_enum:
            return self.page_switched.emit(AppConfig.PROPERTIES_INPUT_PAGE)

        if MainInputPageComponents.VACUUM_BUTTON == button_enum:
            return self.page_switched.emit(AppConfig.VACUUM_INPUT_PAGE)

        if MainInputPageComponents.REGRESSION_BUTTON == button_enum:
            return self.page_switched.emit(AppConfig.REGRESSION_INPUT_PAGE)

        if MainInputPageComponents.EQUILIBRIUM_BUTTON == button_enum:
            return self.page_switched.emit(AppConfig.EQUILIBRIUM_INPUT_PAGE)

        if MainInputPageComponents.CHEMKIN_BUTTON == button_enum:
            return self.page_switched.emit(AppConfig.CHEMKIN_CONVERTER_INPUT_PAGE)
