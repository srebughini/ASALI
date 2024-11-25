from PyQt5 import uic
from PyQt5.QtWidgets import QPushButton, QLineEdit, QGridLayout, QCheckBox, QTabWidget, QComboBox
from asali.reactors.batch import BatchReactor

from src.config.batch_input_page_config import BatchInputPageConfig
from src.config.calculation_input_page_config import CalculationInputPageConfig
from src.config.input_composition_config import InputCompositionConfig
from src.core.batch_calculator import batch_calculator
from src.core.data_keys import DataKeys
from src.core.species_names import surface_species_names

from src.gui.pages.input.basic_reactor_input_page import BasicReactorInputPage
from src.config.reactor_config import ReactorConfig
from src.gui.widgets.input.batch_input_page import BatchInputPageWidgets


class BatchInputPage(BasicReactorInputPage):
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
        # Load the UI from the .ui file
        uic.loadUi(BatchInputPageConfig.PATH.value, self)

        # TODO - Fix composition when running using Enum for composition as done for Resolution method

        self.data_store.update_data(DataKeys.INITIAL_SURF_NS.value, 0)
        self.task_function = batch_calculator

        self.update_head_lines()
        self.update_property_line(BatchInputPageWidgets.VOLUME_EDIT_LINE.value,
                                  BatchInputPageWidgets.VOLUME_COMBO_BOX.value,
                                  self.ud_handler.volume_ud)
        self.update_property_line(BatchInputPageWidgets.CATALYTIC_LOAD_EDIT_LINE.value,
                                  BatchInputPageWidgets.CATALYTIC_LOAD_COMBO_BOX.value,
                                  self.ud_handler.one_over_length_ud)
        self.update_property_line(BatchInputPageWidgets.INTEGRATION_TIME_EDIT_LINE.value,
                                  BatchInputPageWidgets.INTEGRATION_TIME_COMBO_BOX.value,
                                  self.ud_handler.time_ud)
        self.update_property_line(BatchInputPageWidgets.INTEGRATION_STEP_EDIT_LINE.value,
                                  BatchInputPageWidgets.INTEGRATION_STEP_COMBO_BOX.value,
                                  self.ud_handler.time_ud)
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
        return ns + 1

    def get_initial_layout_info(self) -> tuple:
        """
        Extract info of the layout before applying any change
        Returns
        -------
        output_tuple: tuple
            Tuple of dictionary describing the minimum row idx and tab name to grid layout dictionary
        """
        tab_name_to_grid_layout_dict = {ReactorConfig.SOLVING_OPTION_TAB_NAME.value:
                                        BatchInputPageWidgets.SOLVING_OPTION_LAYOUT.value,
                                        ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value:
                                        BatchInputPageWidgets.REACTOR_PROPERTIES_LAYOUT.value,
                                        ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value:
                                        BatchInputPageWidgets.COVERAGE_COMPOSITION_LAYOUT.value}

        minimum_row_idx_dict = {k: self.findChild(QGridLayout, n).rowCount() - 1 for k, n in
                                tab_name_to_grid_layout_dict.items()}

        return minimum_row_idx_dict, tab_name_to_grid_layout_dict

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.data_store.update_data(DataKeys.REACTOR_NAME.value, BatchInputPageConfig.REACTOR_NAME.value)
        self.data_store.update_data(DataKeys.TEMPERATURE_TYPES.value, BatchInputPageConfig.TEMPERATURES.value)
        self.data_store.update_data(DataKeys.REACTOR_PAGE_NAME.value, BatchInputPageConfig.NAME.value)
        self.data_store.update_data(DataKeys.REACTOR_TYPE.value, BatchReactor)

        self.data_store = surface_species_names(self.data_store)
        self.update_composition_names(0,
                                      self.data_store.get_data(DataKeys.SURFACE_SPECIES_NAMES.value),
                                      InputCompositionConfig.SURFACE_SPECIE_COMBO_BOX_NAME.value,
                                      InputCompositionConfig.SURFACE_SPECIE_EDIT_LINE_NAME.value)

        for tab_name in BatchInputPageConfig.TABS_NAMES.value:
            layout_name = self._tab_name_to_grid_layout_dict[tab_name]
            self.update_grid_layout(grid_layout_name=layout_name)

    def update_head_lines(self) -> None:
        """
        Update head lines
        Returns
        -------

        """
        tab_widget = self.findChild(QTabWidget, BatchInputPageWidgets.TAB_WIDGET.value)

        for i, n in enumerate(BatchInputPageConfig.TABS_NAMES.value):
            tab_widget.setTabText(i, n)

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        udk_button = self.findChild(QPushButton, BatchInputPageWidgets.USER_DEFINED_KINETIC_BUTTON.value)
        udk_button.clicked.connect(self.load_udk_file)

        back_button = self.findChild(QPushButton, BatchInputPageWidgets.BACK_BUTTON.value)
        back_button.clicked.connect(lambda: self.page_switched.emit(CalculationInputPageConfig.NAME.value))

        add_specie_button = self.findChild(QPushButton, BatchInputPageWidgets.ADD_SURF_SPECIE_BUTTON.value)
        add_specie_button.clicked.connect(self.add_coverage_line)

        remove_specie_button = self.findChild(QPushButton, BatchInputPageWidgets.REMOVE_SURF_SPECIE_BUTTON.value)
        remove_specie_button.clicked.connect(self.remove_coverage_line)

        run_button = self.findChild(QPushButton, BatchInputPageWidgets.RUN_BUTTON.value)
        run_button.clicked.connect(self.run_button_action)

    def add_coverage_line(self) -> None:
        """
        Add coverage line to the layout
        Returns
        -------

        """
        ns = int(self.data_store.get_data(DataKeys.INITIAL_SURF_NS.value) + 1)
        self.data_store.update_data(DataKeys.INITIAL_SURF_NS.value, ns)
        ns_row_idx = self.from_ns_to_row_idx(ns)

        # Coverage tab
        tab_name = ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value
        row_idx = self._dynamic_row_idx_dict[tab_name]
        layout_name = self._tab_name_to_grid_layout_dict[tab_name]

        if ns_row_idx > row_idx:
            row_idx = row_idx + 1
            self.add_surface_specie_input_row_to_grid_layout(layout_name,
                                                             ns,
                                                             row_idx,
                                                             with_label=True)
            self.update_grid_layout(layout_name)
            self._dynamic_row_idx_dict[tab_name] = row_idx
        else:
            self.remove_row_from_grid_layout(layout_name, ns_row_idx)
            self.add_surface_specie_input_row_to_grid_layout(layout_name,
                                                             ns,
                                                             ns_row_idx,
                                                             with_label=True)
            self.update_grid_layout(layout_name)

        # Other tabs
        for tab_name in [ReactorConfig.SOLVING_OPTION_TAB_NAME.value,
                         ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value]:
            row_idx = self._dynamic_row_idx_dict[tab_name]
            if ns_row_idx > row_idx:
                row_idx = row_idx + 1
                layout_name = self._tab_name_to_grid_layout_dict[tab_name]
                self.add_dummy_row_to_grid_layout(layout_name, row_idx)
                self._dynamic_row_idx_dict[tab_name] = row_idx

    def remove_coverage_line(self) -> None:
        """
        Remove coverage line to the layout
        Returns
        -------

        """
        ns = int(self.data_store.get_data(DataKeys.INITIAL_SURF_NS.value))

        if ns > 0:
            self.data_store.update_data(DataKeys.INITIAL_SURF_NS.value, ns - 1)

            # All tabs
            for tab_name in BatchInputPageConfig.TABS_NAMES.value:
                row_idx = self._dynamic_row_idx_dict[tab_name]
                if row_idx > self._minimum_row_idx_dict[tab_name]:
                    layout_name = self._tab_name_to_grid_layout_dict[tab_name]
                    self.remove_row_from_grid_layout(layout_name, row_idx)
                    self._dynamic_row_idx_dict[tab_name] = row_idx - 1

            # Coverage tab
            tab_name = ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value
            ns_row_idx = self.from_ns_to_row_idx(ns)
            layout_name = self._tab_name_to_grid_layout_dict[tab_name]
            if ns_row_idx <= self._minimum_row_idx_dict[tab_name]:
                self.remove_row_from_grid_layout(layout_name, ns_row_idx)

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        # Volume
        self.read_data_from_property_line(BatchInputPageWidgets.VOLUME_EDIT_LINE.value,
                                          BatchInputPageWidgets.VOLUME_COMBO_BOX.value,
                                          DataKeys.VOLUME)

        # Catalytic load
        self.read_data_from_property_line(BatchInputPageWidgets.CATALYTIC_LOAD_EDIT_LINE.value,
                                          BatchInputPageWidgets.CATALYTIC_LOAD_COMBO_BOX.value,
                                          DataKeys.ALFA)

        # Coverage
        value = {}
        for i in range(0, int(self.data_store.get_data(DataKeys.INITIAL_SURF_NS.value) + 1)):
            specie_name = self.findChild(QComboBox, InputCompositionConfig.SURFACE_SPECIE_COMBO_BOX_NAME.value.format(i)).currentText()
            specie_value = self.findChild(QLineEdit, InputCompositionConfig.SURFACE_SPECIE_EDIT_LINE_NAME.value.format(i)).text()
            value[specie_name] = float(specie_value)

        self.data_store.update_data(DataKeys.INITIAL_SURF_COMPOSITION.value, value)

        # Energy balance
        checkbox = self.findChild(QCheckBox, BatchInputPageWidgets.ENERGY_CHECK_BOX.value)
        self.data_store.update_data(DataKeys.ENERGY_BALANCE.value, checkbox.isChecked())

        # Integration time
        self.read_data_from_property_line(BatchInputPageWidgets.INTEGRATION_TIME_EDIT_LINE.value,
                                          BatchInputPageWidgets.INTEGRATION_TIME_COMBO_BOX.value,
                                          DataKeys.TMAX)

        # Integration time step
        self.read_data_from_property_line(BatchInputPageWidgets.INTEGRATION_STEP_EDIT_LINE.value,
                                          BatchInputPageWidgets.INTEGRATION_STEP_COMBO_BOX.value,
                                          DataKeys.TSTEP)

        # Temperature
        self.data_store.update_data(DataKeys.INITIAL_GAS_T.value,
                                    self.data_store.get_data(DataKeys.INLET_T.value))

        # Composition
        self.data_store.update_data(DataKeys.INITIAL_GAS_COMPOSITION.value,
                                    self.data_store.get_data(DataKeys.INLET_GAS_COMPOSITION.value))
