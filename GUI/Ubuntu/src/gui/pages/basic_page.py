from abc import abstractmethod

from PyQt5.QtCore import pyqtSignal, Qt
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import QWidget, QGridLayout, QComboBox, QLineEdit, QLabel

from src.core.data_keys import DataKeys
from src.core.species_names import surface_species_names, gas_species_names
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

    def update_coverage_composition(self, idx_list) -> None:
        """
        Update coverage composition in all combo boxes
        Parameters
        ----------
        idx_list: list
            List of index to be updated

        Returns
        -------

        """
        self.data_store = surface_species_names(self.data_store)
        coverage_list = self.data_store.get_data(DataKeys.SURFACE_SPECIES_NAMES.value)
        for idx in idx_list:
            dropdown = self.findChild(QComboBox, f"n{idx}")
            dropdown.clear()
            dropdown.addItems(coverage_list)

            edit_line = self.findChild(QLineEdit, f"x{idx}")
            edit_line.setValidator(QDoubleValidator(0.0, 1.0, 5))
            edit_line.setAlignment(Qt.AlignLeft)

    def update_specie_composition(self, idx_list) -> None:
        """
        Update specie composition in all combo boxes
        Parameters
        ----------
        idx_list: list
            List of index to be updated

        Returns
        -------

        """
        self.data_store = gas_species_names(self.data_store)
        specie_list = self.data_store.get_data(DataKeys.GAS_SPECIES_NAMES.value)
        for idx in idx_list:
            dropdown = self.findChild(QComboBox, f"n{idx}")
            dropdown.clear()
            dropdown.addItems(specie_list)

            edit_line = self.findChild(QLineEdit, f"x{idx}")
            edit_line.setValidator(QDoubleValidator(0.0, 1.0, 5))
            edit_line.setAlignment(Qt.AlignLeft)

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

        grid.update()

    def remove_row_from_grid_layout(self, grid_layout_name, row_idx) -> None:
        """
        Remove a row from a grid layout
        Parameters
        ----------
        grid_layout_name: str
            Grid Layout name
        row_idx: int
            Row to be removed

        Returns
        -------

        """
        grid_layout = self.findChild(QGridLayout, grid_layout_name)
        for column in range(grid_layout.columnCount()):
            item = grid_layout.itemAtPosition(row_idx, column)
            if item:
                widget = item.widget()
                grid_layout.removeWidget(widget)
        self.update_grid_layout(grid_layout_name)

    def add_dummy_row_to_grid_layout(self, grid_layout_name, row_idx) -> None:
        """
        Add a dummy row to a grid layout
        Parameters
        ----------
        grid_layout_name: str
            Grid Layout name
        row_idx: int
            Row to be removed

        Returns
        -------

        """
        label = QLabel(" ")
        grid_layout = self.findChild(QGridLayout, grid_layout_name)
        grid_layout.addWidget(label, row_idx, 0, 1, -1)
        self.update_grid_layout(grid_layout_name)

    @abstractmethod
    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        pass
