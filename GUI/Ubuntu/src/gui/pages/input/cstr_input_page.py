from PyQt5 import uic
from PyQt5.QtWidgets import QPushButton, QLineEdit, QGridLayout, QCheckBox, QTabWidget, QComboBox
from asali.reactors.cstr import CstrReactor

from src.core.cstr_calculator import cstr_calculator
from src.core.data_keys import DataKeys
from src.core.species_names import surface_species_names, gas_species_names
from src.gui.config import Config

from src.gui.pages.input.basic_reactor_input_page import BatchReactorInputPage
from src.gui.reactor_config import ReactorConfig


class CstrInputPage(BatchReactorInputPage):
    def __init__(self, data_store, dialog_handler, run_bar):
        """
        Continuous stirred tank reactor input page layout
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
        # Load the UI from the .ui file
        uic.loadUi(Config.CSTR_INPUT_PAGE_PATH.value, self)

        self.data_store.update_data(DataKeys.INLET_SURF_NS.value, 0)
        self.data_store.update_data(DataKeys.INITIAL_NS.value, 0)
        self.task_function = cstr_calculator

        self.update_head_lines()
        self.update_property_line("volumeEditLine", "volumeComboBox", self.ud_handler.volume_ud)
        self.update_property_line("alfaEditLine", "alfaComboBox", self.ud_handler.one_over_length_ud)
        self.update_property_line("qEditLine", "qComboBox", self.ud_handler.mass_flow_rate_ud)
        self.update_property_line("tmaxEditLine", "tmaxComboBox", self.ud_handler.time_ud)
        self.update_property_line("tstepEditLine", "tstepComboBox", self.ud_handler.time_ud)
        self.update_property_line("temperatureEditLine", "temperatureComboBox", self.ud_handler.temperature_ud)
        self.update_buttons()

        self.update_grid_layout(grid_layout_name='optionsLayout')
        self.update_grid_layout(grid_layout_name='propertiesLayout')
        self.update_grid_layout(grid_layout_name='coverageLayout')
        self.update_grid_layout(grid_layout_name='initialLayout')
        self.update_grid_layout(grid_layout_name='initialCompositionLayout')


        # TODO - Creare logica degli if usando i due aumenti di dimensioni

        self._surf_specie_row_idx = ReactorConfig.CSTR_INITIAL_SURFACE_SPECIE_ROW_IDX.value

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.data_store.update_data(DataKeys.REACTOR_NAME.value, ReactorConfig.CSTR_NAME.value)
        self.data_store.update_data(DataKeys.TEMPERATURE_TYPES.value, ReactorConfig.CSTR_TEMPERATURES.value)
        self.data_store.update_data(DataKeys.REACTOR_PAGE_NAME.value, Config.CSTR_INPUT_PAGE_NAME.value)
        self.data_store.update_data(DataKeys.REACTOR_TYPE.value, CstrReactor)

        self.data_store = surface_species_names(self.data_store)
        self.update_composition_names(0,
                                      self.data_store.get_data(DataKeys.SURFACE_SPECIES_NAMES.value),
                                      Config.SURFACE_SPECIE_COMBO_BOX_NAME.value,
                                      Config.SURFACE_SPECIE_EDIT_LINE_NAME.value)

        self.data_store = gas_species_names(self.data_store)
        self.update_composition_names(0,
                                      self.data_store.get_data(DataKeys.GAS_SPECIES_NAMES.value),
                                      Config.GAS_SPECIE_COMBO_BOX_NAME.value,
                                      Config.GAS_SPECIE_EDIT_LINE_NAME.value)

        self.update_grid_layout(grid_layout_name='optionsLayout')
        self.update_grid_layout(grid_layout_name='propertiesLayout')
        self.update_grid_layout(grid_layout_name='coverageLayout')
        self.update_grid_layout(grid_layout_name='initialLayout')
        self.update_grid_layout(grid_layout_name='initialCompositionLayout')

    def update_head_lines(self) -> None:
        """
        Update head lines
        Returns
        -------

        """
        tab_widget = self.findChild(QTabWidget, 'tabWidget')

        for i, n in enumerate(['Solving options',
                               'Reactor properties',
                               'Coverage composition',
                               'Initial conditions']):
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

        add_coverage_button = self.findChild(QPushButton, 'addCoverageButton')
        add_coverage_button.clicked.connect(self.add_coverage_line)

        remove_coverage_button = self.findChild(QPushButton, 'removeCoverageButton')
        remove_coverage_button.clicked.connect(self.remove_coverage_line)

        add_specie_button = self.findChild(QPushButton, 'addSpecieButton')
        add_specie_button.clicked.connect(self.add_specie_line)

        remove_specie_button = self.findChild(QPushButton, 'removeSpecieButton')
        remove_specie_button.clicked.connect(self.remove_specie_line)

        run_button = self.findChild(QPushButton, 'runButton')
        run_button.clicked.connect(self.run_button_action)

    def add_coverage_line(self) -> None:
        """
        Add coverage line to the layout
        Returns
        -------

        """
        ns = int(self.data_store.get_data(DataKeys.INLET_SURF_NS.value) + 1)
        self.data_store.update_data(DataKeys.INLET_SURF_NS.value, ns)

        self._surf_specie_row_idx = self._surf_specie_row_idx + 1

        if self._surf_specie_row_idx >= ReactorConfig.CSTR_MINIMUM_ROW_IDX.value:
            self.move_buttons_in_grid_layout("coverageLayout",
                                             self._surf_specie_row_idx + 1,
                                             ReactorConfig.CSTR_SURFACE_BUTTON_DICT.value)

            self.add_dummy_row_to_grid_layout("optionsLayout", self._surf_specie_row_idx + 1)
            self.add_dummy_row_to_grid_layout("propertiesLayout", self._surf_specie_row_idx + 1)

            self.add_dummy_row_to_grid_layout("initialCompositionLayout", self._surf_specie_row_idx - 1)

        self.add_surface_specie_input_row_to_grid_layout("coverageLayout",
                                                         ns,
                                                         self._surf_specie_row_idx,
                                                         with_label=False)

        self.update_grid_layout("coverageLayout")

    def remove_coverage_line(self) -> None:
        """
        Remove coverage line to the layout
        Returns
        -------

        """
        pass
        """
        ns = self.data_store.get_data(DataKeys.INLET_SURF_NS.value)
        self.data_store.update_data(DataKeys.INLET_SURF_NS.value, ns - 1)

        if self._specie_row_idx > ReactorConfig.BATCH_INITIAL_SURF_SPECIE_ROW_IDX.value:
            if self._specie_row_idx >= ReactorConfig.BATCH_MINIMUM_ROW_IDX.value:
                self.remove_row_from_grid_layout("coverageLayout", self._specie_row_idx)
                self.remove_row_from_grid_layout("optionsLayout", self._specie_row_idx + 1)
                self.remove_row_from_grid_layout("propertiesLayout", self._specie_row_idx + 1)
                self._specie_row_idx = self._specie_row_idx - 1
            else:
                self.remove_row_from_grid_layout("coverageLayout", self._specie_row_idx)
                self._specie_row_idx = self._specie_row_idx - 1
        """

    def add_specie_line(self) -> None:
        """
        Add specie line to the layout
        Returns
        -------

        """
        pass

    def remove_specie_line(self) -> None:
        """
        Remove specie line to the layout
        Returns
        -------

        """
        pass

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        pass

        """
        # Volume
        self.read_data_from_property_line('volumeEditLine', 'volumeComboBox', DataKeys.VOLUME)

        # Catalytic load
        self.read_data_from_property_line('alfaEditLine', 'alfaComboBox', DataKeys.ALFA)

        # Coverage
        value = {self.findChild(QComboBox, f"n{i}").currentText(): float(self.findChild(QLineEdit, f"x{i}").text()) for
                 i in range(0, self.data_store.get_data(DataKeys.INLET_SURF_NS.value) + 1)}
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
        """
