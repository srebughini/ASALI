from abc import abstractmethod

from PyQt5.QtCore import pyqtSignal, Qt
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import QWidget, QGridLayout, QComboBox, QLineEdit, QLabel, QPushButton

from src.core.data_keys import DataKeys
from src.core.species_names import surface_species_names, gas_species_names
from src.core.unit_dimension_handler import UnitDimensionHandler
from src.config.app_config import AppConfig
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

    def update_composition_names(self,
                                 specie_idx,
                                 specie_list,
                                 combo_box_name,
                                 edit_line_name) -> None:
        """
        Update specie composition in all combo boxes
        Parameters
        ----------
        specie_idx: int
            List of index to be update
        specie_list: list
            Gas or coverage species names
        combo_box_name: str
            Combo box name
        edit_line_name: str
            Edit line name

        Returns
        -------

        """
        dropdown = self.findChild(QComboBox, combo_box_name.format(specie_idx))
        dropdown.clear()
        dropdown.addItems(specie_list)

        edit_line = self.findChild(QLineEdit, edit_line_name.format(specie_idx))
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
        grid.setVerticalSpacing(AppConfig.GRID_VERTICAL_SPACING.value)
        grid.setHorizontalSpacing(AppConfig.GRID_HORIZONTAL_SPACING.value)

        for col in range(grid.columnCount()):
            grid.setColumnMinimumWidth(col, AppConfig.MINIMUM_COLUMN_WIDTH.value)  # Set minimum width for columns
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

    def add_specie_input_row_to_grid_layout(self,
                                            grid_layout_name,
                                            specie_idx,
                                            row_idx,
                                            label_name,
                                            combo_box_name,
                                            edit_line_name,
                                            specie_list):
        """
        Add a gas or surface specie row to a grid layout
        Parameters
        ----------
        grid_layout_name: str
            Grid layout name
        specie_idx: int
            Specie index to be added
        row_idx: int
            Row to be added
        label_name: str | None
            Label name
        combo_box_name: str
            Combo box name
        edit_line_name: str
            Edit line name
        specie_list: list
            Gas or coverage species names to be added

        Returns
        -------

        """
        grid_layout = self.findChild(QGridLayout, grid_layout_name)

        combo_box = QComboBox()
        combo_box.setObjectName(combo_box_name.format(specie_idx))

        edit_line = QLineEdit()
        edit_line.setObjectName(edit_line_name.format(specie_idx))
        edit_line.setText("0.0")

        if label_name is None:
            grid_layout.addWidget(combo_box, row_idx, 0)
            grid_layout.addWidget(edit_line, row_idx, 1)
        else:
            label = QLabel(label_name.format(specie_idx))
            grid_layout.addWidget(label, row_idx, 0)
            grid_layout.addWidget(combo_box, row_idx, 1)
            grid_layout.addWidget(edit_line, row_idx, 2)

        self.update_composition_names(specie_idx,
                                      specie_list,
                                      combo_box_name,
                                      edit_line_name)

    def add_gas_specie_input_row_to_grid_layout(self,
                                                grid_layout_name,
                                                specie_idx,
                                                row_idx,
                                                with_label) -> None:
        """
        Add a specie row to a grid layout
        Parameters
        ----------
        grid_layout_name: str
            Grid layout name
        specie_idx: int
            Specie index to be added
        row_idx: int
            Row to be added
        with_label: bool
            Enable/Disable the label

        Returns
        -------

        """
        label_name = None
        combo_box_name = AppConfig.GAS_SPECIE_COMBO_BOX_NAME.value
        edit_line_name = AppConfig.GAS_SPECIE_EDIT_LINE_NAME.value

        self.data_store = gas_species_names(self.data_store)
        specie_list = self.data_store.get_data(DataKeys.GAS_SPECIES_NAMES.value)

        if with_label:
            label_name = AppConfig.GAS_SPECIE_LABEL_NAME.value

        self.add_specie_input_row_to_grid_layout(grid_layout_name,
                                                 specie_idx,
                                                 row_idx,
                                                 label_name,
                                                 combo_box_name,
                                                 edit_line_name,
                                                 specie_list)

    def add_surface_specie_input_row_to_grid_layout(self,
                                                    grid_layout_name,
                                                    specie_idx,
                                                    row_idx,
                                                    with_label) -> None:
        """
        Add a specie row to a grid layout
        Parameters
        ----------
        grid_layout_name: str
            Grid layout name
        specie_idx: int
            Specie index to be added
        row_idx: int
            Row to be added
        with_label: bool
            Enable/Disable the label

        Returns
        -------

        """
        label_name = None
        combo_box_name = AppConfig.SURFACE_SPECIE_COMBO_BOX_NAME.value
        edit_line_name = AppConfig.SURFACE_SPECIE_EDIT_LINE_NAME.value

        self.data_store = surface_species_names(self.data_store)
        specie_list = self.data_store.get_data(DataKeys.SURFACE_SPECIES_NAMES.value)

        if with_label:
            label_name = AppConfig.SURFACE_SPECIE_LABEL_NAME.value

        self.add_specie_input_row_to_grid_layout(grid_layout_name,
                                                 specie_idx,
                                                 row_idx,
                                                 label_name,
                                                 combo_box_name,
                                                 edit_line_name,
                                                 specie_list)

    def move_buttons_in_grid_layout(self, grid_layout_name, new_row, buttons_dict) -> None:
        """
        Move the buttons from their current row to a new row.
        Parameters
        ----------
        grid_layout_name: str
            Grid layout name
        new_row : int
            The new row to place the buttons in.
        buttons_dict: dict
            Dictionary with button name as key (str) and button column as value (int)
        """
        grid_layout = self.findChild(QGridLayout, grid_layout_name)
        for n, col_idx in buttons_dict.items():
            button = self.findChild(QPushButton, n)
            grid_layout.removeWidget(button)
            grid_layout.addWidget(button, new_row, col_idx)

    @abstractmethod
    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        pass
