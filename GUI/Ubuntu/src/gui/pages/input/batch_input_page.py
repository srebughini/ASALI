from PyQt5 import uic
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import QLabel, QPushButton, QLineEdit, QGridLayout, QCheckBox, QComboBox, QWidget, QTabWidget
from asali.reactors.batch import BatchReactor

from src.core.batch_calculator import batch_calculator
from src.core.data_keys import DataKeys
from src.core.species_names import get_random_coverage_name
from src.gui.config import Config

from src.gui.pages.input.basic_reactor_input_page import BatchReactorInputPage
from src.gui.reactor_config import ReactorConfig


class BatchInputPage(BatchReactorInputPage):
    def __init__(self, data_store, dialog_handler, run_bar):
        """
        Batch reactor input page layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        run_bar: RunBarWindow
            Class to handle the run bar
        """
        super().__init__(data_store, dialog_handler, run_bar)

        # TODO - Check how coverage are added and removed and the number of rows

        # Load the UI from the .ui file
        uic.loadUi(Config.BATCH_INPUT_PAGE_PATH.value, self)

        self.data_store.update_data(DataKeys.INLET_SURF_NS.value, ReactorConfig.BATCH_INITIAL_SURF_NS.value)
        self.task_function = batch_calculator

        self.update_head_lines()
        self.update_property_line("volumeEditLine", "volumeComboBox", self.ud_handler.volume_ud)
        self.update_property_line("alfaEditLine", "alfaComboBox", self.ud_handler.one_over_length_ud)
        self.update_property_line("tmaxEditLine", "tmaxComboBox", self.ud_handler.time_ud)
        self.update_property_line("tstepEditLine", "tstepComboBox", self.ud_handler.time_ud)
        self.update_buttons()

        self.update_grid_layout(grid_layout_name='optionsLayout')
        self.update_grid_layout(grid_layout_name='propertiesLayout')
        self.update_grid_layout(grid_layout_name='coverageLayout')

        self._n_rows = ReactorConfig.BATCH_N_ROWS.value

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.data_store.update_data(DataKeys.REACTOR_NAME.value, ReactorConfig.BATCH_NAME.value)
        self.data_store.update_data(DataKeys.TEMPERATURE_TYPES.value, ReactorConfig.BATCH_TEMPERATURES.value)
        self.data_store.update_data(DataKeys.REACTOR_PAGE_NAME.value, Config.BATCH_INPUT_PAGE_NAME.value)
        self.data_store.update_data(DataKeys.REACTOR_TYPE.value, BatchReactor)
        self.update_grid_layout(grid_layout_name='optionsLayout')
        self.update_grid_layout(grid_layout_name='propertiesLayout')
        self.update_grid_layout(grid_layout_name='coverageLayout')

    def update_head_lines(self) -> None:
        """
        Update head lines
        Returns
        -------

        """
        tab_widget = self.findChild(QTabWidget, 'tabWidget')

        for i, n in enumerate(['Solving options', 'Reactor properties', 'Coverage composition']):
            tab_widget.setTabText(i, n)

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        udk_button = self.findChild(QPushButton, 'udkButton')
        udk_button.clicked.connect(self.load_udk_file)

        back_button = self.findChild(QPushButton, 'backButton')
        back_button.clicked.connect(lambda: self.page_switched.emit(Config.CALCULATION_INPUT_PAGE_NAME.value))

        add_specie_button = self.findChild(QPushButton, 'addCoverageButton')
        add_specie_button.clicked.connect(self.add_coverage_line)

        remove_specie_button = self.findChild(QPushButton, 'removeCoverageButton')
        remove_specie_button.clicked.connect(self.remove_coverage_line)

        run_button = self.findChild(QPushButton, 'runButton')
        run_button.clicked.connect(self.run_button_action)

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
        add_coverage_button = self.findChild(QPushButton, 'addCoverageButton')
        remove_coverage_button = self.findChild(QPushButton, 'removeCoverageButton')

        # Remove buttons from the old row
        grid_layout.removeWidget(add_coverage_button)
        grid_layout.removeWidget(remove_coverage_button)

        # Add buttons to the new row
        grid_layout.addWidget(add_coverage_button, new_row, 0)
        grid_layout.addWidget(remove_coverage_button, new_row, 2)

    def add_coverage_line(self) -> None:
        """
        Add coverage line to the layout
        Returns
        -------

        """
        ns = self.data_store.get_data(DataKeys.INLET_SURF_NS.value) + 1
        self.data_store.update_data(DataKeys.INLET_SURF_NS.value, ns)

        label = QLabel(f'Coverage #{ns}')
        label.setObjectName(f"l{ns}")

        formula_edit_line = QLineEdit()
        formula_edit_line.setObjectName(f"n{ns}")
        formula_edit_line.setText(get_random_coverage_name(self.data_store))

        composition_edit_line = QLineEdit()
        composition_edit_line.setObjectName(f"x{ns}")
        composition_edit_line.setValidator(QDoubleValidator(0.0, 1.0, 4))
        composition_edit_line.setText("0.0")

        grid_layout = self.findChild(QGridLayout, "coverageLayout")
        specie_row = grid_layout.rowCount() - 1

        grid_layout.addWidget(label, specie_row, 0)
        grid_layout.addWidget(formula_edit_line, specie_row, 1)
        grid_layout.addWidget(composition_edit_line, specie_row, 2)

        button_row = specie_row + 1
        self.move_buttons(grid_layout, button_row)
        self.update_grid_layout("coverageLayout")

        self._n_rows = self._n_rows + 1
        self.add_dummy_row_to_grid_layout("optionsLayout", self._n_rows)
        self.add_dummy_row_to_grid_layout("propertiesLayout", self._n_rows)

    def remove_coverage_line(self) -> None:
        """
        Remove coverage line to the layout
        Returns
        -------

        """
        ns = self.data_store.get_data(DataKeys.INLET_SURF_NS.value)
        if ns > ReactorConfig.BATCH_INITIAL_SURF_NS.value:
            label = self.findChild(QLabel, f'l{ns}')
            formula_edit_line = self.findChild(QLineEdit, f'n{ns}')
            composition_edit_line = self.findChild(QLineEdit, f'x{ns}')

            grid_layout = self.findChild(QGridLayout, "coverageLayout")

            grid_layout.removeWidget(label)
            grid_layout.removeWidget(formula_edit_line)
            grid_layout.removeWidget(composition_edit_line)

            label.deleteLater()  # Properly clean up the widget
            formula_edit_line.deleteLater()  # Properly clean up the widget
            composition_edit_line.deleteLater()  # Properly clean up the widget

            button_row = ns + 1 + 1
            self.move_buttons(grid_layout, button_row)

            self.data_store.update_data(DataKeys.INLET_SURF_NS.value, ns - 1)

            self.remove_row_from_grid_layout("optionsLayout", self._n_rows)
            self.remove_row_from_grid_layout("propertiesLayout", self._n_rows)

            self._n_rows = self._n_rows - 1

        self.update_grid_layout("coverageLayout")

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        # Volume
        self.read_data_from_property_line('volumeEditLine', 'volumeComboBox', DataKeys.VOLUME)

        # Catalytic load
        self.read_data_from_property_line('alfaEditLine', 'alfaComboBox', DataKeys.ALFA)

        # Coverage
        value = {self.findChild(QLineEdit, f"n{i}").text(): float(self.findChild(QLineEdit, f"x{i}").text()) for i in
                 range(0, self.data_store.get_data(DataKeys.INLET_SURF_NS.value) + 1)}
        self.data_store.update_data(DataKeys.INITIAL_COVERAGE_COMPOSITION.value, value)

        # Energy balance
        checkbox = self.findChild(QCheckBox, "energyCheckBox")
        self.data_store.update_data(DataKeys.ENERGY_BALANCE.value, checkbox.isChecked())

        # Integration time
        self.read_data_from_property_line('tmaxEditLine', 'tmaxComboBox', DataKeys.TMAX)

        # Integration time step
        self.read_data_from_property_line('tstepEditLine', 'tstepComboBox', DataKeys.TSTEP)

        # Temperature
        self.data_store.update_data(DataKeys.INITIAL_T.value,
                                    self.data_store.get_data(DataKeys.INLET_T.value))

        # Composition
        self.data_store.update_data(DataKeys.INITIAL_GAS_COMPOSITION.value,
                                    self.data_store.get_data(DataKeys.INLET_GAS_COMPOSITION.value))
