from abc import abstractmethod

from PyQt5.QtCore import pyqtSignal
from PyQt5.QtWidgets import QWidget, QGridLayout

from src.core.unit_dimension_handler import UnitDimensionHandler
from src.gui.config import Config
from src.gui.pages.dialog_pages_handler import DialogPagesHandler


class BasicPage(QWidget):
    page_switched = pyqtSignal(str)  # Signal to switch pages

    def __init__(self, data_store, dialog_handler):
        """
        Chemistry input page layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__()
        # Load the UI from the .ui file
        self.data_store = data_store
        self.dialog_handler = dialog_handler
        self.ud_handler = UnitDimensionHandler()

    def update_grid_layout(self, grid_layout_name='gridLayout') -> None:
        """
        Update grid layout
        Parameters
        ----------
        grid_layout_name: str (optional)
            Grid layout widget name


        Returns
        -------

        """
        grid = self.findChild(QGridLayout, grid_layout_name)
        grid.setVerticalSpacing(Config.GRID_VERTICAL_SPACING.value)
        grid.setHorizontalSpacing(Config.GRID_HORIZONTAL_SPACING.value)

        for col in range(grid.columnCount()):
            grid.setColumnMinimumWidth(col, Config.MINIMUM_COLUMN_WIDTH.value)  # Set minimum width for columns
            grid.setColumnStretch(col, 1)  # or any desired stretch factor

        for row in range(grid.rowCount()):
            grid.setRowStretch(row, 1)  # or any desired stretch factor

    @abstractmethod
    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        pass
