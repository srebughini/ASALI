from PyQt5.QtCore import pyqtSignal
from PyQt5.QtWidgets import QWidget, QGridLayout, QSizePolicy

from src.core.unit_dimension_handler import UnitDimensionHandler
from src.gui.config import Config


class BasicPage(QWidget):
    page_switched = pyqtSignal(str)  # Signal to switch pages

    def __init__(self, data_store):
        """
        Chemistry input page layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        """
        super().__init__()
        # Load the UI from the .ui file
        self.data_store = data_store
        self.ud_handler = UnitDimensionHandler()

    def update_grid_layout(self):
        """
        Update grid layout
        Returns
        -------

        """
        grid = self.findChild(QGridLayout, 'gridLayout')

        for j in range(grid.columnCount()):
            grid.setColumnMinimumWidth(j, Config.MINIMUM_COLUMN_WIDTH.value)  # Set minimum width for columns
