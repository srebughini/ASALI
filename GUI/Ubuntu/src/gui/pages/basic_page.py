from abc import abstractmethod
from enum import Enum

import beerpy
from PySide6.QtCore import Signal, QFile, Qt
from PySide6.QtGui import QPixmap
from PySide6.QtUiTools import QUiLoader
from PySide6.QtWidgets import QWidget, QGridLayout, QComboBox, QLineEdit, QLabel, QGraphicsBlurEffect, QSizePolicy

from src.config.input_composition import InputCompositionConfig
from src.controllers.cantera_file_controller import CanteraFileController
from src.controllers.label_formatter import LabelFormatter
from src.core.data_keys import DataKeys
from src.core.species_names import surface_species_names, gas_species_names
from src.core.unit_dimension_handler import UnitDimensionHandler
from src.config.app import AppConfig
from src.gui.enums.database_type import DatabaseType
from src.gui.pages.dialog_pages_handler import DialogPagesHandler


class BasicPage(QWidget):
    switch_to_page = Signal(Enum)  # Signal to switch pages

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
        self.data_store = data_store
        self.dialog_handler = dialog_handler
        self.ud_handler = UnitDimensionHandler()

    @abstractmethod
    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        pass

    @staticmethod
    def disable_widget(widget, blur_level=2) -> QWidget:
        """
        Disable a QWidget by adding also blur effect
        Parameters
        ----------
        widget: QWidget
            Widget to be disabled
        blur_level: int
            Level of blur (0 weal, 5 strong)

        Returns
        -------
        widget: QWidget
            Widget disabled
        """
        # Create and configure blur effect
        blur_effect = QGraphicsBlurEffect(widget)
        blur_effect.setBlurRadius(blur_level)

        # Apply effect
        widget.setGraphicsEffect(blur_effect)
        widget.setEnabled(False)

        # Force repaint to ensure blur is visible
        widget.update()
        return widget

    @staticmethod
    def enable_widget(widget) -> QWidget:
        """
        Enable a QWidget by removing also blur effect
        Parameters
        ----------
        widget: QWidget
            Widget to be disabled

        Returns
        -------
        widget: QWidget
            Widget disabled
        """
        # Remove effect
        widget.setGraphicsEffect(None)
        widget.setEnabled(True)

        # Force repaint
        widget.update()
        return widget

    @staticmethod
    def set_custom_dimensions_to_grid_layout(grid) -> None:
        """
        Set custom dimensions to grid layout
        Parameters
        ----------
        grid: QGridLayout
            Grid layout to be resize


        Returns
        -------

        """
        grid.setVerticalSpacing(AppConfig.GRID_VERTICAL_SPACING.value)
        grid.setHorizontalSpacing(AppConfig.GRID_HORIZONTAL_SPACING.value)

        grid.setContentsMargins(*AppConfig.GRID_MARGIN.value)

        for col in range(grid.columnCount()):
            grid.setColumnMinimumWidth(col, AppConfig.MINIMUM_COLUMN_WIDTH.value)  # Set minimum width for columns
            grid.setColumnStretch(col, 1)  # or any desired stretch factor

        for row in range(grid.rowCount()):
            grid.setRowStretch(row, 1)  # or any desired stretch factor

        grid.update()

    @staticmethod
    def set_custom_dimensions_to_vertical_layout(vbox) -> None:
        """
        Set custom dimensions to a vertical layout.

        Parameters
        ----------
        vbox: QVBoxLayout
            Vertical layout to be resized
        """
        # Set margins (left, top, right, bottom)
        vbox.setContentsMargins(*AppConfig.VBOX_MARGIN.value)

        # Set stretch factor for each widget in the layout
        for i in range(vbox.count()):
            vbox.setStretch(i, 1)  # You can adjust the stretch factor if needed

        # Force layout update
        vbox.update()

    @staticmethod
    def clear_grid_layout(grid) -> None:
        """
        Clear a grid layout from widgets.

        Parameters
        ----------
        grid: QGridLayout
            Grid layout

        Returns
        -------
        """
        # Iterate over all items in the grid layout
        for row in range(grid.rowCount()):
            for col in range(grid.columnCount()):
                item = grid.itemAtPosition(row, col)
                if item:
                    widget = item.widget()
                    if widget:
                        # Remove the widget from the layout
                        grid.removeWidget(widget)
                        widget.deleteLater()  # Ensure widget cleanup

        # Remove all items and reset the layout
        while grid.count():
            item = grid.takeAt(0)
            if item:
                widget = item.widget()
                if widget:
                    widget.deleteLater()

    def load_ui(self, ui_file_path) -> None:
        """
        Load the .ui file and set it as the layout of this widget.
        Parameters
        ----------
        ui_file_path: str | os.path
            Path of the .ui file

        Returns
        -------

        """
        """Load the .ui file and set it as the layout of this widget."""
        loader = QUiLoader()
        ui_file = QFile(ui_file_path)
        ui_file.open(QFile.ReadOnly)
        loaded_widget = loader.load(ui_file, self)
        ui_file.close()

        # Set the layout or components from the loaded .ui
        layout = loaded_widget.layout()
        self.setLayout(layout)

    def update_beer_label(self) -> None:
        """
        Update the beer quote label
        Returns
        -------

        """
        q = beerpy.get_random_quote(language="eng")
        label = self.findChild(QLabel, 'beerQuoteLabel')
        quote = LabelFormatter.wrap_string(q["quote"], AppConfig.BEER_QUOTE_MAX_CHARACTERS.value)
        label.setText(f'{quote}\n[{q["author"]}]')
        label.setAlignment(Qt.AlignCenter)
        label.setWordWrap(True)
        label.setProperty("class", "italic")

    def update_logo(self) -> None:
        """
        Update the logo
        Returns
        -------

        """
        label = self.findChild(QLabel, 'logoLabel')
        pixmap = QPixmap(AppConfig.LOGO_PATH.value)
        label.setPixmap(pixmap)
        label.setAlignment(Qt.AlignCenter)
        label.setProperty("class", "logo")

    def set_formatted_text_to_label(self, label_as_enum, text) -> None:
        """
        Set formatted text to label
        Parameters
        ----------
        label_as_enum: Enum
            Enum describing the QLabel
        text: float | dict | str | list
            Value to be formatted and converted to thext

        Returns
        -------

        """
        label = self.find_widget(label_as_enum)

        if isinstance(text, float):
            label.setText(LabelFormatter.float_to_string(text))
        elif isinstance(text, dict):
            label.setText(LabelFormatter.dict_to_string(text))
        elif isinstance(text, list):
            label.setText(LabelFormatter.list_to_string(text))
        elif isinstance(text, str):
            label.setText(LabelFormatter.pad_string(text))
        else:
            raise Exception(f"Unknown type to be formatted: {type(text)}")

    def find_widget(self, widget_as_enum) -> QWidget | QComboBox | QLabel | QLineEdit | QGridLayout:
        """
        Find and select the widget from a layout
        Parameters
        ----------
        widget_as_enum: Enum
            Widget as enum with name and type

        Returns
        -------
        widget: QWidget | QComboBox | QLabel | QLineEdit | QGridLayout
            Desired widget
        """
        widget_name = widget_as_enum.value.name
        widget_type = widget_as_enum.value.type

        return self.findChild(widget_type, widget_name)

    def add_gas_specie(self, grid_enum) -> None:
        """
        Add gas species widgets to the grid layout
        Parameters
        ----------
        grid_enum: Enum
            Enum describing the layout where to add the gas specie row
        Returns
        -------
        """
        grid = self.find_widget(grid_enum)
        idx = self.data_store.get_data(DataKeys.GAS_NS) + 1
        self.data_store.update_data(DataKeys.GAS_NS, idx)

        self.data_store = gas_species_names(self.data_store)
        species_names = self.data_store.get_data(DataKeys.GAS_SPECIES_NAMES)

        label = self.findChild(QLabel, InputCompositionConfig.GAS_SPECIE_LABEL_NAME.value.format(idx))
        if label is None:
            label = QLabel(InputCompositionConfig.GAS_SPECIE_LABEL_TEXT.value.format(idx))
            label.setObjectName(InputCompositionConfig.GAS_SPECIE_LABEL_NAME.value.format(idx))
            grid.addWidget(label, idx, 0)
        else:
            label.setVisible(True)

        combo_box = self.findChild(QComboBox, InputCompositionConfig.GAS_SPECIE_COMBO_BOX_NAME.value.format(idx))
        if combo_box is None:
            combo_box = QComboBox()
            combo_box.setObjectName(InputCompositionConfig.GAS_SPECIE_COMBO_BOX_NAME.value.format(idx))
            combo_box.addItems(species_names)
            grid.addWidget(combo_box, idx, 1)
        else:
            combo_box.addItems(species_names)
            combo_box.setVisible(True)

        edit_line = self.findChild(QLineEdit, InputCompositionConfig.GAS_SPECIE_EDIT_LINE_NAME.value.format(idx))
        if edit_line is None:
            edit_line = QLineEdit()
            edit_line.setObjectName(InputCompositionConfig.GAS_SPECIE_EDIT_LINE_NAME.value.format(idx))
            edit_line.setValidator(InputCompositionConfig.SPECIES_VALIDATOR.value)
            edit_line.setAlignment(InputCompositionConfig.EDIT_LINE_ALIGN.value)
            edit_line.setText(InputCompositionConfig.EDIT_LINE_DOUBLE_TEXT.value)
            grid.addWidget(edit_line, idx, 2)
        else:
            edit_line.setVisible(True)

        self.set_custom_dimensions_to_grid_layout(grid)

    def remove_gas_species(self, grid_enum) -> None:
        """
        Remove gas species widgets to the grid layout
        Parameters
        ----------
        grid_enum: Enum
            Enum describing the layout where to add the gas specie row
        Returns
        -------
        """
        grid = self.find_widget(grid_enum)
        idx = self.data_store.get_data(DataKeys.GAS_NS)
        if idx > 0:
            label = self.findChild(QLabel, InputCompositionConfig.GAS_SPECIE_LABEL_NAME.value.format(idx))
            combo_box = self.findChild(QComboBox, InputCompositionConfig.GAS_SPECIE_COMBO_BOX_NAME.value.format(idx))
            edit_line = self.findChild(QLineEdit, InputCompositionConfig.GAS_SPECIE_EDIT_LINE_NAME.value.format(idx))

            label.setVisible(False)
            combo_box.clear()
            combo_box.setVisible(False)

            edit_line.clear()
            edit_line.setVisible(False)

            self.set_custom_dimensions_to_grid_layout(grid)
            self.data_store.update_data(DataKeys.GAS_NS, idx - 1)

    def select_database(self, database_enum) -> None:
        """
        Select database to be used
        Parameters
        ----------
        database_enum: Enum
            Database combo box enum

        Returns
        -------

        """
        database_box = self.find_widget(database_enum)
        database_type = DatabaseType(database_box.currentText())

        self.data_store.update_data(DataKeys.IS_GAS_SPECIES_NAMES_UPDATED, False)

        if DatabaseType.NONE == database_type:
            self.data_store.reset_data(DataKeys.IS_DEFAULT_FILE_PATH)
            self.data_store.reset_data(DataKeys.CHEMISTRY_FILE_PATH)
            self.data_store.reset_data(DataKeys.GAS_PHASE_NAME)
            self.data_store.reset_data(DataKeys.SURFACE_PHASE_NAME)
            return None

        if DatabaseType.DEFAULT == database_type:
            self.data_store.update_data(DataKeys.IS_DEFAULT_FILE_PATH, True)
            file_path = AppConfig.DEFAULT_DATABASE_FILE_PATH.value
            self.data_store.update_data(DataKeys.CHEMISTRY_FILE_PATH,
                                        file_path)
            self.data_store.update_data(DataKeys.GAS_PHASE_NAME,
                                        CanteraFileController.extract_gas_phase_name_from_cantera(file_path))
            self.data_store.update_data(DataKeys.SURFACE_PHASE_NAME,
                                        CanteraFileController.extract_gas_phase_name_from_cantera(file_path))
            return None

        if DatabaseType.CUSTOM == database_type:
            file_path = self.dialog_handler.load_file(AppConfig.CANTERA_FILE_OPEN.value,
                                                      AppConfig.CANTERA_FILE_TYPE.value)
            if file_path:  # Check if a file was selected
                if CanteraFileController.check_cantera_input_file(file_path):
                    self.data_store.update_data(DataKeys.IS_DEFAULT_FILE_PATH, False)
                    self.data_store.update_data(DataKeys.CHEMISTRY_FILE_PATH,
                                                file_path)
                    self.data_store.update_data(DataKeys.GAS_PHASE_NAME,
                                                CanteraFileController.extract_gas_phase_name_from_cantera(file_path))
                    self.data_store.update_data(DataKeys.SURFACE_PHASE_NAME,
                                                CanteraFileController.extract_gas_phase_name_from_cantera(file_path))
                    self.dialog_handler.done_message(QLabel("Cantera file loaded!"))
                else:
                    database_box.setCurrentTexT(DatabaseType.NONE.value)
            else:
                database_box.setCurrentTexT(DatabaseType.NONE.value)
            return None

        return None
