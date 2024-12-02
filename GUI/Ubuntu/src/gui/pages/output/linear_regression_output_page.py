from PyQt5 import uic

from src.config.linear_regression_output_page_config import LinearRegressionOutputPageConfig
from src.gui.pages.basic_page import BasicPage


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

        """
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
        """

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.update_grid_layout()

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        pass
