from PyQt5 import uic
from PyQt5.QtCore import Qt, pyqtSignal
from PyQt5.QtWidgets import QPushButton, QLabel, QGridLayout, QCheckBox, QComboBox

from src.config.plot_and_save_output_page_config import PlotAndSaveOutputPageConfig
from src.core.data_keys import DataKeys
from src.core.reactor_post_processing import reactor_saver, reactor_plotter
from src.core.species_names import gas_species_names, surface_species_names
from src.config.app_config import AppConfig
from src.gui.pages.basic_page import BasicPage
from src.gui.widgets.output.plot_and_save_output_page import PlotAndSaveOutputPageWidgets


class PlotAndSaveOutputPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Plot and save output layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        uic.loadUi(PlotAndSaveOutputPageConfig.PATH.value, self)

        self.update_head_lines()
        self.update_buttons()
        self.update_grid_layout()

        self._button_row_idx = PlotAndSaveOutputPageConfig.BUTTON_ROW_IDX.value

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.update_check_box()
        self.update_grid_layout()
        self.unselect_all()

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        plot_button = self.findChild(QPushButton, PlotAndSaveOutputPageWidgets.PLOT_BUTTON.value)
        plot_button.clicked.connect(self.plot_reactor_data)

        save_button = self.findChild(QPushButton, PlotAndSaveOutputPageWidgets.SAVE_BUTTON.value)
        save_button.clicked.connect(self.save_reactor_data)

        back_button = self.findChild(QPushButton, PlotAndSaveOutputPageWidgets.BACK_BUTTON.value)
        back_button.clicked.connect(self.back_button_action)

        select_button = self.findChild(QPushButton, PlotAndSaveOutputPageWidgets.SELECT_BUTTON.value)
        select_button.clicked.connect(self.on_select_button_click_data)

    def update_head_lines(self) -> None:
        """
        Update head lines
        Returns
        -------

        """
        for n in [PlotAndSaveOutputPageWidgets.GAS_LABEL,
                  PlotAndSaveOutputPageWidgets.SURFACE_LABEL,
                  PlotAndSaveOutputPageWidgets.TEMPERATURE_LABEL]:
            label = self.findChild(QLabel, n.value)
            label.setAlignment(Qt.AlignCenter)
            label.setProperty("class", "italic")

    def move_buttons_in_grid_layout(self, grid_layout, new_row) -> None:
        """
        Move the buttons from their current row to a new row.
        Parameters
        ----------
        grid_layout: QGridLayout
            Grid Layout
        new_row : int
            The new row to place the buttons in.
        """
        # Find the buttons in the old row
        back_button = self.findChild(QPushButton, PlotAndSaveOutputPageWidgets.BACK_BUTTON.value)
        plot_button = self.findChild(QPushButton, PlotAndSaveOutputPageWidgets.PLOT_BUTTON.value)
        save_button = self.findChild(QPushButton, PlotAndSaveOutputPageWidgets.SAVE_BUTTON.value)

        # Remove buttons from the old row
        grid_layout.removeWidget(back_button)
        grid_layout.removeWidget(plot_button)
        grid_layout.removeWidget(save_button)

        # Add buttons to the new row
        grid_layout.addWidget(back_button, new_row, 0)
        grid_layout.addWidget(save_button, new_row, 1)
        grid_layout.addWidget(plot_button, new_row, 2)

    def update_check_box(self) -> None:
        """
        Update the layout check boxes
        Returns
        -------

        """
        grid_layout = self.findChild(QGridLayout, PlotAndSaveOutputPageWidgets.GRID_LAYOUT.value)

        if self._button_row_idx > PlotAndSaveOutputPageConfig.INITIAL_CHECK_BOX_ROW_IDX.value:
            for row_idx in range(PlotAndSaveOutputPageConfig.INITIAL_CHECK_BOX_ROW_IDX.value,
                                 self._button_row_idx):
                self.remove_row_from_grid_layout(PlotAndSaveOutputPageWidgets.GRID_LAYOUT.value, row_idx)

        row_idx = PlotAndSaveOutputPageConfig.INITIAL_CHECK_BOX_ROW_IDX.value
        self.data_store = gas_species_names(self.data_store)
        self.data_store = surface_species_names(self.data_store)

        for i, n in enumerate(self.data_store.get_data(DataKeys.GAS_SPECIES_NAMES.value)):
            check_box = QCheckBox(n)
            check_box.setObjectName(f"{n}")
            grid_layout.addWidget(check_box, row_idx + i + 1, 0)

        for i, n in enumerate(self.data_store.get_data(DataKeys.SURFACE_SPECIES_NAMES.value)):
            check_box = QCheckBox(n)
            check_box.setObjectName(f"{n}")
            grid_layout.addWidget(check_box, row_idx + i + 1, 1)

        for i, n in enumerate(self.data_store.get_data(DataKeys.TEMPERATURE_TYPES.value)):
            check_box = QCheckBox(n)
            check_box.setObjectName(f"{n}")
            grid_layout.addWidget(check_box, row_idx + i + 1, 2)

        row_idx = row_idx + max([len(self.data_store.get_data(DataKeys.GAS_SPECIES_NAMES.value)),
                                 len(self.data_store.get_data(DataKeys.SURFACE_SPECIES_NAMES.value))])

        self._button_row_idx = row_idx + 1
        self.move_buttons_in_grid_layout(grid_layout, self._button_row_idx)

    def select_all(self) -> None:
        """
        Select all variables
        Returns
        -------

        """
        for n in self.data_store.get_data(DataKeys.GAS_SPECIES_NAMES.value):
            check_box = self.findChild(QCheckBox, n)
            check_box.setChecked(True)

        for n in self.data_store.get_data(DataKeys.SURFACE_SPECIES_NAMES.value):
            check_box = self.findChild(QCheckBox, n)
            check_box.setChecked(True)

        for n in self.data_store.get_data(DataKeys.TEMPERATURE_TYPES.value):
            check_box = self.findChild(QCheckBox, n)
            check_box.setChecked(True)

        select_button = self.findChild(QPushButton, PlotAndSaveOutputPageWidgets.SELECT_BUTTON.value)
        select_button.setText("Unselect all")

    def unselect_all(self) -> None:
        """
        Unselect all variables
        Returns
        -------

        """
        for n in self.data_store.get_data(DataKeys.GAS_SPECIES_NAMES.value):
            check_box = self.findChild(QCheckBox, n)
            check_box.setChecked(False)

        for n in self.data_store.get_data(DataKeys.SURFACE_SPECIES_NAMES.value):
            check_box = self.findChild(QCheckBox, n)
            check_box.setChecked(False)

        for n in self.data_store.get_data(DataKeys.TEMPERATURE_TYPES.value):
            check_box = self.findChild(QCheckBox, n)
            check_box.setChecked(False)

        select_button = self.findChild(QPushButton, PlotAndSaveOutputPageWidgets.SELECT_BUTTON.value)
        select_button.setText("Select all")

    def back_button_action(self) -> pyqtSignal:
        """
        Action related to the next button
        Returns
        -------
        signal: pyqtSignal
            Signal with the next page name
        """
        reactor_page_name = self.data_store.get_data(DataKeys.REACTOR_PAGE_NAME.value)
        return self.page_switched.emit(reactor_page_name)

    def on_select_button_click_data(self) -> None:
        """
        Select or unselect all check box
        Returns
        -------

        """
        for n in self.data_store.get_data(DataKeys.GAS_SPECIES_NAMES.value):
            check_box = self.findChild(QCheckBox, n)
            if not check_box.isChecked():
                self.select_all()
                return None

        for n in self.data_store.get_data(DataKeys.SURFACE_SPECIES_NAMES.value):
            check_box = self.findChild(QCheckBox, n)
            if not check_box.isChecked():
                self.select_all()
                return None

        for n in self.data_store.get_data(DataKeys.TEMPERATURE_TYPES.value):
            check_box = self.findChild(QCheckBox, n)
            if not check_box.isChecked():
                self.select_all()
                return None

        self.unselect_all()

    def plot_reactor_data(self) -> None:
        """
        Function to plot reactor data
        Returns
        -------

        """
        self.data_store.update_data(DataKeys.PLOT_AND_SAVE_COMPOSITION_TYPE.value,
                                    self.findChild(QComboBox,
                                                   PlotAndSaveOutputPageWidgets.COMPOSITION_COMBO_BOX.value).currentText())

        self.data_store.update_data(DataKeys.COLORMAP.value,
                                    self.findChild(QComboBox,
                                                   PlotAndSaveOutputPageWidgets.COLOR_COMBO_BOX.value).currentText())

        species_list = [n for n in self.data_store.get_data(DataKeys.GAS_SPECIES_NAMES.value) if
                        self.findChild(QCheckBox, n).isChecked()]

        self.data_store.update_data(DataKeys.GAS_SPECIES_NAMES_TO_BE_PLOTTED.value, species_list)

        surface_species_list = [n for n in self.data_store.get_data(DataKeys.SURFACE_SPECIES_NAMES.value) if
                                self.findChild(QCheckBox, n).isChecked()]

        self.data_store.update_data(DataKeys.SURFACE_SPECIES_NAMES_TO_BE_PLOTTED.value, surface_species_list)

        temperature_list = [n for n in self.data_store.get_data(DataKeys.TEMPERATURE_TYPES.value) if
                            self.findChild(QCheckBox, n).isChecked()]

        self.data_store.update_data(DataKeys.TEMPERATURE_TO_BE_PLOTTED.value, temperature_list)

        reactor_plotter(self.data_store)

    def save_reactor_data(self) -> None:
        """
        Function to save reactor data
        Returns
        -------

        """
        self.data_store.update_data(DataKeys.PLOT_AND_SAVE_COMPOSITION_TYPE.value,
                                    self.findChild(QComboBox,
                                                   PlotAndSaveOutputPageWidgets.COMPOSITION_COMBO_BOX.value).currentText())

        output_file_path = self.dialog_handler.save_file(AppConfig.EXCEL_FILE_SAVE.value,
                                                         AppConfig.EXCEL_FILE_TYPE.value)

        if output_file_path is not None:
            self.data_store.update_data(DataKeys.OUTPUT_FILE_PATH.value, output_file_path)

            try:
                reactor_saver(self.data_store)
            except OSError as e:
                self.dialog_handler.error_message(QLabel(str(e)))
            else:
                self.dialog_handler.done_message(QLabel("Successfully saved!"))
