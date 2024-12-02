from PyQt5 import uic
from PyQt5.QtWidgets import QPushButton, QLineEdit, QCheckBox, QComboBox
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

import copy

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
        # Load the UI from the .ui file
        super().__init__(data_store, dialog_handler, run_bar)
        uic.loadUi(BatchInputPageConfig.PATH.value, self)

        self.update_tab_names(BatchInputPageWidgets.TAB_WIDGET.value)
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

        self.task_function = batch_calculator

        self.tab_name_to_row_idx_dict = self.tab_name_to_minimum_row_idx_dict.copy()
        self.surf_ns = 0
        self.ns = -1

    @property
    def number_of_gas_species_to_row_idx(self) -> int:
        """
        Property that returns the number of gas species to row index value
        Returns
        -------
        row_idx: int
            Row index
        """
        return 0

    @property
    def number_of_surface_species_to_row_idx(self) -> int:
        """
        Property that returns the number of surface species to row index value
        Returns
        -------

        """
        return BatchInputPageConfig.SURFACE_SPECIE_TO_ROW_INDEX.value

    @property
    def tab_names(self) -> list:
        """
        Property that return the tab name list
        Returns
        -------
        tab_names: list
            List of tab names
        """
        return BatchInputPageConfig.TABS_NAMES.value

    @property
    def tab_name_to_grid_layout_name_dict(self) -> dict:
        """
        Property that return the grid layout name for each tab name
        Returns
        -------
        tab_name_to_grid_layout_name: dict
            Tab name to grid layout name
        """
        return {ReactorConfig.SOLVING_OPTION_TAB_NAME.value:
                    BatchInputPageWidgets.SOLVING_OPTION_LAYOUT.value,
                ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value:
                    BatchInputPageWidgets.REACTOR_PROPERTIES_LAYOUT.value,
                ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value:
                    BatchInputPageWidgets.COVERAGE_COMPOSITION_LAYOUT.value}

    @property
    def tab_name_to_minimum_row_idx_dict(self) -> dict:
        """
        Property that return the minimum row idx for each tab name
        Returns
        -------
        tab_name_to_minimum_row_idx: dict
            Tab name to minimum row idx
        """
        return {ReactorConfig.SOLVING_OPTION_TAB_NAME.value:
                    BatchInputPageConfig.SOLVING_OPTION_LAYOUT_MINIMUM_ROW_IDX.value,
                ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value:
                    BatchInputPageConfig.REACTOR_PROPERTIES_LAYOUT_MINIMUM_ROW_IDX.value,
                ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value:
                    BatchInputPageConfig.COVERAGE_COMPOSITION_LAYOUT_MINIMUM_ROW_IDX.value}

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.data_store.update_data(DataKeys.REACTOR_NAME, BatchInputPageConfig.REACTOR_NAME.value)
        self.data_store.update_data(DataKeys.TEMPERATURE_TYPES, BatchInputPageConfig.TEMPERATURES.value)
        self.data_store.update_data(DataKeys.REACTOR_PAGE_NAME, BatchInputPageConfig.NAME.value)
        self.data_store.update_data(DataKeys.REACTOR_TYPE, BatchReactor)

        self.data_store = surface_species_names(self.data_store)
        self.update_composition_names(0,
                                      self.data_store.get_data(DataKeys.SURFACE_SPECIES_NAMES),
                                      InputCompositionConfig.SURFACE_SPECIE_COMBO_BOX_NAME.value,
                                      InputCompositionConfig.SURFACE_SPECIE_EDIT_LINE_NAME.value)

        for tab_name in self.tab_names:
            layout_name = self.tab_name_to_grid_layout_name_dict[tab_name]
            self.update_grid_layout(grid_layout_name=layout_name)

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

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        # Initial number of surface species
        self.data_store.update_data(DataKeys.INITIAL_SURF_NS, self.surf_ns)

        # Initial number of gas species
        self.data_store.update_data(DataKeys.INITIAL_NS, self.ns)

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
        for i in range(0, int(self.data_store.get_data(DataKeys.INITIAL_SURF_NS) + 1)):
            specie_name = self.findChild(QComboBox, InputCompositionConfig.SURFACE_SPECIE_COMBO_BOX_NAME.value.format(
                i)).currentText()
            specie_value = self.findChild(QLineEdit,
                                          InputCompositionConfig.SURFACE_SPECIE_EDIT_LINE_NAME.value.format(i)).text()
            value[specie_name] = float(specie_value)

        self.data_store.update_data(DataKeys.INITIAL_SURF_COMPOSITION, value)

        # Energy balance
        checkbox = self.findChild(QCheckBox, BatchInputPageWidgets.ENERGY_CHECK_BOX.value)
        self.data_store.update_data(DataKeys.ENERGY_BALANCE, checkbox.isChecked())

        # Integration time
        self.read_data_from_property_line(BatchInputPageWidgets.INTEGRATION_TIME_EDIT_LINE.value,
                                          BatchInputPageWidgets.INTEGRATION_TIME_COMBO_BOX.value,
                                          DataKeys.TMAX)

        # Integration time step
        self.read_data_from_property_line(BatchInputPageWidgets.INTEGRATION_STEP_EDIT_LINE.value,
                                          BatchInputPageWidgets.INTEGRATION_STEP_COMBO_BOX.value,
                                          DataKeys.TSTEP)

        # Temperature
        self.data_store.update_data(DataKeys.INITIAL_GAS_T,
                                    self.data_store.get_data(DataKeys.INLET_T.value))

        # Composition
        self.data_store.update_data(DataKeys.INITIAL_GAS_COMPOSITION,
                                    self.data_store.get_data(DataKeys.INLET_GAS_COMPOSITION.value))
