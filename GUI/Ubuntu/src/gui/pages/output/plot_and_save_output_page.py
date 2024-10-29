from PyQt5 import uic
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QPushButton, QLabel, QGridLayout, QCheckBox, QComboBox

from src.core.data_keys import DataKeys
from src.core.reactor_post_processing import reactor_saver, reactor_plotter
from src.core.species_names import gas_species_names, surface_species_names
from src.gui.config import Config
from src.gui.pages.basic_page import BasicPage


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
        uic.loadUi(Config.PLOT_AND_SAVE_OUTPUT_PAGE_PATH.value, self)

        self.update_head_lines()
        self.update_buttons()
        self.update_grid_layout()

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.update_check_box()
        self.update_grid_layout()

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        plot_button = self.findChild(QPushButton, 'plotButton')
        plot_button.clicked.connect(self.plot_reactor_data)

        save_button = self.findChild(QPushButton, 'saveButton')
        save_button.clicked.connect(self.save_reactor_data)

        back_button = self.findChild(QPushButton, 'backButton')
        reactor_page_name = self.data_store.get_data(DataKeys.REACTOR_PAGE_NAME.value)
        back_button.clicked.connect(lambda: self.page_switched.emit(reactor_page_name))

        select_button = self.findChild(QPushButton, 'selectButton')
        select_button.clicked.connect(self.on_select_button_click_data)

    def update_head_lines(self) -> None:
        """
        Update head lines
        Returns
        -------

        """
        for n in ['gasLabel', 'surfaceLabel', 'temperatureLabel']:
            label = self.findChild(QLabel, n)
            label.setAlignment(Qt.AlignCenter)
            label.setProperty("class", "italic")

    def move_buttons(self, grid_layout, new_row) -> None:
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
        back_button = self.findChild(QPushButton, 'backButton')
        plot_button = self.findChild(QPushButton, 'plotButton')
        save_button = self.findChild(QPushButton, 'saveButton')

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
        grid_layout = self.findChild(QGridLayout, "gridLayout")
        row_idx = grid_layout.rowCount()

        self.data_store = gas_species_names(self.data_store)
        self.data_store = surface_species_names(self.data_store)

        for i, n in enumerate(self.data_store.get_data(DataKeys.GAS_SPECIES_NAMES.value)):
            check_box = self.findChild(QCheckBox, f"{n}")
            if check_box is None:
                check_box = QCheckBox(n)
                check_box.setObjectName(f"{n}")
                grid_layout.addWidget(check_box, row_idx + i + 1, 0)

        for i, n in enumerate(self.data_store.get_data(DataKeys.SURFACE_SPECIES_NAMES.value)):
            check_box = self.findChild(QCheckBox, f"{n}")
            if check_box is None:
                check_box = QCheckBox(n)
                check_box.setObjectName(f"{n}")
                grid_layout.addWidget(check_box, row_idx + i + 1, 1)

        for i, n in enumerate(self.data_store.get_data(DataKeys.TEMPERATURE_TYPES.value)):
            check_box = self.findChild(QCheckBox, f"{n}")
            if check_box is None:
                check_box = QCheckBox(n)
                check_box.setObjectName(f"{n}")
                grid_layout.addWidget(check_box, row_idx + i + 1, 2)

        row_idx = row_idx + max([len(self.data_store.get_data(DataKeys.GAS_SPECIES_NAMES.value)),
                                 len(self.data_store.get_data(DataKeys.SURFACE_SPECIES_NAMES.value))])

        button_row = row_idx + 1
        self.move_buttons(grid_layout, button_row)

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

        select_button = self.findChild(QPushButton, 'selectButton')
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

        select_button = self.findChild(QPushButton, 'selectButton')
        select_button.setText("Select all")

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

    def plot_reactor_data(self):
        """
        Function to plot reactor data
        Returns
        -------

        """
        self.data_store.update_data(DataKeys.PLOT_AND_SAVE_COMPOSITION_TYPE.value,
                                    self.findChild(QComboBox, 'compositionComboBox').currentText())

        self.data_store.update_data(DataKeys.COLORMAP.value,
                                    self.findChild(QComboBox, 'plotColorComboBox').currentText())

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

    def save_reactor_data(self):
        """
        Function to save reactor data
        Returns
        -------

        """
        self.data_store.update_data(DataKeys.PLOT_AND_SAVE_COMPOSITION_TYPE.value,
                                    self.findChild(QComboBox, 'compositionComboBox').currentText())

        output_file_path = self.dialog_handler.save_file('Save reactor data',
                                                         Config.EXCEL_FILE_TYPE.value)

        self.data_store.update_data(DataKeys.OUTPUT_FILE_PATH.value, output_file_path)

        try:
            reactor_saver(self.data_store)
        except OSError as e:
            self.dialog_handler.error_message(QLabel(str(e)))
        else:
            self.dialog_handler.done_message(QLabel("Successfully saved!"))
