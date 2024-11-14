from PyQt5 import uic
from PyQt5.QtWidgets import QPushButton, QLineEdit, QGridLayout, QCheckBox, QTabWidget, QComboBox
from asali.reactors.cstr import CstrReactor

from src.config.calculation_input_page_config import CalculationInputPageConfig
from src.config.cstr_input_page_config import CstrInputPageConfig
from src.core.cstr_calculator import cstr_calculator
from src.core.data_keys import DataKeys
from src.core.species_names import surface_species_names, gas_species_names
from src.config.app_config import AppConfig

from src.gui.pages.input.basic_reactor_input_page import BatchReactorInputPage
from src.config.reactor_config import ReactorConfig


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
        uic.loadUi(CstrInputPageConfig.PATH.value, self)

        self.data_store.update_data(DataKeys.INITIAL_SURF_NS.value, 0)
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

        self._minimum_row_idx_dict, self._tab_name_to_grid_layout_dict = self.get_initial_layout_info()
        self._dynamic_row_idx_dict = self._minimum_row_idx_dict.copy()

    @staticmethod
    def from_ns_to_row_idx(ns) -> int:
        """
        Convert the number of species to row idx
        Parameters
        ----------
        ns: int
            Number of species

        Returns
        -------
        row_idx: int
            Row index corresponding to the number of species based on the layout
        """
        return ns + 3

    @staticmethod
    def from_surf_ns_to_row_idx(surf_ns) -> int:
        """
        Convert the number of surface species to row idx
        Parameters
        ----------
        surf_ns: int
            Number of species

        Returns
        -------
        row_idx: int
            Row index corresponding to the number of species based on the layout
        """
        return surf_ns + 1

    def get_initial_layout_info(self) -> tuple:
        """
        Extract info of the layout before applying any change
        Returns
        -------
        output_tuple: tuple
            Tuple of dictionary describing the minimum row idx and tab name to grid layout dictionary
        """
        tab_name_to_grid_layout_dict = {ReactorConfig.SOLVING_OPTION_TAB_NAME.value: 'optionsLayout',
                                        ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value: 'propertiesLayout',
                                        ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value: 'coverageLayout',
                                        ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value: 'initialLayout'}

        minimum_row_idx_dict = {k: self.findChild(QGridLayout, n).rowCount() - 1 for k, n in
                                tab_name_to_grid_layout_dict.items()}

        return minimum_row_idx_dict, tab_name_to_grid_layout_dict

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.data_store.update_data(DataKeys.REACTOR_NAME.value, CstrInputPageConfig.REACTOR_NAME.value)
        self.data_store.update_data(DataKeys.TEMPERATURE_TYPES.value, CstrInputPageConfig.TEMPERATURES.value)
        self.data_store.update_data(DataKeys.REACTOR_PAGE_NAME.value, CstrInputPageConfig.NAME.value)
        self.data_store.update_data(DataKeys.REACTOR_TYPE.value, CstrReactor)

        self.data_store = surface_species_names(self.data_store)
        self.update_composition_names(0,
                                      self.data_store.get_data(DataKeys.SURFACE_SPECIES_NAMES.value),
                                      AppConfig.SURFACE_SPECIE_COMBO_BOX_NAME.value,
                                      AppConfig.SURFACE_SPECIE_EDIT_LINE_NAME.value)

        self.data_store = gas_species_names(self.data_store)
        self.update_composition_names(0,
                                      self.data_store.get_data(DataKeys.GAS_SPECIES_NAMES.value),
                                      AppConfig.GAS_SPECIE_COMBO_BOX_NAME.value,
                                      AppConfig.GAS_SPECIE_EDIT_LINE_NAME.value)

        for tab_name in CstrInputPageConfig.TABS_NAMES.value:
            layout_name = self._tab_name_to_grid_layout_dict[tab_name]
            self.update_grid_layout(grid_layout_name=layout_name)

    def update_head_lines(self) -> None:
        """
        Update head lines
        Returns
        -------

        """
        tab_widget = self.findChild(QTabWidget, 'tabWidget')

        for i, n in enumerate(CstrInputPageConfig.TABS_NAMES.value):
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
        back_button.clicked.connect(lambda: self.page_switched.emit(CalculationInputPageConfig.NAME.value))

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
        surf_ns = int(self.data_store.get_data(DataKeys.INITIAL_SURF_NS.value) + 1)
        self.data_store.update_data(DataKeys.INITIAL_SURF_NS.value, surf_ns)
        surf_ns_row_idx = self.from_surf_ns_to_row_idx(surf_ns)

        # Coverage tab
        tab_name = ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value
        row_idx = self._dynamic_row_idx_dict[tab_name]
        layout_name = self._tab_name_to_grid_layout_dict[tab_name]

        if surf_ns_row_idx > self._dynamic_row_idx_dict[tab_name]:
            row_idx = row_idx + 1
            self.add_surface_specie_input_row_to_grid_layout(layout_name,
                                                             surf_ns,
                                                             row_idx,
                                                             with_label=True)
            self.update_grid_layout(layout_name)
            self._dynamic_row_idx_dict[tab_name] = row_idx
        else:
            self.remove_row_from_grid_layout(layout_name, surf_ns_row_idx)
            self.add_surface_specie_input_row_to_grid_layout(layout_name,
                                                             surf_ns,
                                                             surf_ns_row_idx,
                                                             with_label=True)
            self.update_grid_layout(layout_name)

        # Other tabs
        for tab_name in [ReactorConfig.SOLVING_OPTION_TAB_NAME.value,
                         ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value,
                         ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value]:
            if surf_ns_row_idx > self._dynamic_row_idx_dict[tab_name]:
                row_idx = self._dynamic_row_idx_dict[tab_name] + 1
                layout_name = self._tab_name_to_grid_layout_dict[tab_name]
                self.add_dummy_row_to_grid_layout(layout_name, row_idx)
                self._dynamic_row_idx_dict[tab_name] = row_idx

    def remove_coverage_line(self) -> None:
        """
        Remove coverage line to the layout
        Returns
        -------

        """
        surf_ns = int(self.data_store.get_data(DataKeys.INITIAL_SURF_NS.value))

        if surf_ns > 0:
            self.data_store.update_data(DataKeys.INITIAL_SURF_NS.value, surf_ns - 1)
            ns = int(self.data_store.get_data(DataKeys.INITIAL_NS.value))
            surf_ns_row_idx = self.from_surf_ns_to_row_idx(surf_ns)
            ns_row_idx = self.from_ns_to_row_idx(ns)

            if ns_row_idx >= surf_ns_row_idx:
                tab_name = ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value
                layout_name = self._tab_name_to_grid_layout_dict[tab_name]
                self.remove_row_from_grid_layout(layout_name, surf_ns_row_idx)
                self.add_dummy_row_to_grid_layout(layout_name, surf_ns_row_idx)
            else:
                for tab_name in [ReactorConfig.SOLVING_OPTION_TAB_NAME.value,
                                 ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value,
                                 ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value]:
                    row_idx = self._dynamic_row_idx_dict[tab_name]
                    if row_idx > self._minimum_row_idx_dict[tab_name]:
                        layout_name = self._tab_name_to_grid_layout_dict[tab_name]
                        self.remove_row_from_grid_layout(layout_name, row_idx)
                        self._dynamic_row_idx_dict[tab_name] = row_idx - 1

                tab_name = ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value
                if ns_row_idx < self._dynamic_row_idx_dict[tab_name]:
                    layout_name = self._tab_name_to_grid_layout_dict[tab_name]
                    self.remove_row_from_grid_layout(layout_name, row_idx)
                    self._dynamic_row_idx_dict[tab_name] = row_idx - 1

    def add_specie_line(self) -> None:
        """
        Add specie line to the layout
        Returns
        -------

        """
        ns = int(self.data_store.get_data(DataKeys.INITIAL_NS.value) + 1)
        self.data_store.update_data(DataKeys.INITIAL_NS.value, ns)
        ns_row_idx = self.from_ns_to_row_idx(ns)

        # Coverage tab
        tab_name = ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value
        row_idx = self._dynamic_row_idx_dict[tab_name]
        layout_name = self._tab_name_to_grid_layout_dict[tab_name]

        if ns_row_idx > self._dynamic_row_idx_dict[tab_name]:
            row_idx = row_idx + 1
            self.add_gas_specie_input_row_to_grid_layout(layout_name,
                                                         ns,
                                                         row_idx,
                                                         with_label=True)
            self.update_grid_layout(layout_name)
            self._dynamic_row_idx_dict[tab_name] = row_idx
        else:
            self.remove_row_from_grid_layout(layout_name, ns_row_idx)
            self.add_gas_specie_input_row_to_grid_layout(layout_name,
                                                         ns,
                                                         ns_row_idx,
                                                         with_label=True)
            self.update_grid_layout(layout_name)

        # Other tabs
        for tab_name in [ReactorConfig.SOLVING_OPTION_TAB_NAME.value,
                         ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value,
                         ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value]:
            if ns_row_idx > self._dynamic_row_idx_dict[tab_name]:
                row_idx = self._dynamic_row_idx_dict[tab_name] + 1
                layout_name = self._tab_name_to_grid_layout_dict[tab_name]
                self.add_dummy_row_to_grid_layout(layout_name, row_idx)
                self._dynamic_row_idx_dict[tab_name] = row_idx

    def remove_specie_line(self) -> None:
        """
        Remove specie line to the layout
        Returns
        -------

        """
        ns = int(self.data_store.get_data(DataKeys.INITIAL_NS.value))

        if ns > 0:
            self.data_store.update_data(DataKeys.INITIAL_NS.value, ns - 1)
            surf_ns = int(self.data_store.get_data(DataKeys.INITIAL_SURF_NS.value))
            surf_ns_row_idx = self.from_surf_ns_to_row_idx(surf_ns)
            ns_row_idx = self.from_ns_to_row_idx(ns)

            if surf_ns_row_idx >= ns_row_idx:
                tab_name = ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value
                layout_name = self._tab_name_to_grid_layout_dict[tab_name]
                self.remove_row_from_grid_layout(layout_name, ns_row_idx)
                self.add_dummy_row_to_grid_layout(layout_name, ns_row_idx)
            else:
                for tab_name in [ReactorConfig.SOLVING_OPTION_TAB_NAME.value,
                                 ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value,
                                 ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value]:
                    row_idx = self._dynamic_row_idx_dict[tab_name]
                    if row_idx > self._minimum_row_idx_dict[tab_name]:
                        layout_name = self._tab_name_to_grid_layout_dict[tab_name]
                        self.remove_row_from_grid_layout(layout_name, row_idx)
                        self._dynamic_row_idx_dict[tab_name] = row_idx - 1

                tab_name = ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value
                if surf_ns_row_idx < self._dynamic_row_idx_dict[tab_name]:
                    layout_name = self._tab_name_to_grid_layout_dict[tab_name]
                    self.remove_row_from_grid_layout(layout_name, row_idx)
                    self._dynamic_row_idx_dict[tab_name] = row_idx - 1

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

        # Mass flow rate
        self.read_data_from_property_line("qEditLine", "qComboBox", DataKeys.MASS_FLOW_RATE)

        # Coverage
        value = {}
        for i in range(0, int(self.data_store.get_data(DataKeys.INITIAL_SURF_NS.value) + 1)):
            specie_name = self.findChild(QComboBox, AppConfig.SURFACE_SPECIE_COMBO_BOX_NAME.value.format(i)).currentText()
            specie_value = self.findChild(QLineEdit, AppConfig.SURFACE_SPECIE_EDIT_LINE_NAME.value.format(i)).text()
            value[specie_name] = float(specie_value)
        self.data_store.update_data(DataKeys.INITIAL_SURF_COMPOSITION.value, value)

        # Initial composition
        value = {}
        for i in range(0, int(self.data_store.get_data(DataKeys.INITIAL_NS.value) + 1)):
            specie_name = self.findChild(QComboBox, AppConfig.GAS_SPECIE_COMBO_BOX_NAME.value.format(i)).currentText()
            specie_value = self.findChild(QLineEdit, AppConfig.GAS_SPECIE_EDIT_LINE_NAME.value.format(i)).text()
            value[specie_name] = float(specie_value)
        ud = self.findChild(QComboBox, 'compositionComboBox').currentText()
        self.data_store.update_data(DataKeys.INITIAL_GAS_COMPOSITION.value, (value, ud))

        # Initial temperature
        self.read_data_from_property_line("temperatureEditLine", "temperatureComboBox", DataKeys.INITIAL_GAS_T)

        # Energy balance
        checkbox = self.findChild(QCheckBox, "energyCheckBox")
        self.data_store.update_data(DataKeys.ENERGY_BALANCE.value, checkbox.isChecked())

        # Integration time
        self.read_data_from_property_line('tmaxEditLine', 'tmaxComboBox', DataKeys.TMAX)

        # Integration time step
        self.read_data_from_property_line('tstepEditLine', 'tstepComboBox', DataKeys.TSTEP)
