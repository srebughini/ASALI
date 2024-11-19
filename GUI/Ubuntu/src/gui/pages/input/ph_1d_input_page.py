from PyQt5 import uic
from PyQt5.QtWidgets import QPushButton, QLineEdit, QGridLayout, QCheckBox, QTabWidget, QComboBox

from src.config.calculation_input_page_config import CalculationInputPageConfig
from src.config.input_composition_config import InputCompositionConfig
from src.config.ph_1d_input_page_config import Ph1dInputPageConfig
from src.core.data_keys import DataKeys
from src.core.species_names import surface_species_names, gas_species_names

from src.gui.pages.input.basic_reactor_input_page import BasicReactorInputPage
from src.config.reactor_config import ReactorConfig
from src.gui.widgets.input.ph_1d_input_page import Ph1dInputPageWidgets


class Ph1dInputPage(BasicReactorInputPage):
    def __init__(self, data_store, dialog_handler, run_bar):
        """
        Pseudo-homogenous 1D reactor input page layout
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

        # TODO - Add hide for integration time and step when steady state is selected
        # TODO - Add action when Steady State or Transient is selected
        # TODO - Add update properties for length
        # TODO - Check add and remove of specie and coverage

        # Load the UI from the .ui file
        uic.loadUi(Ph1dInputPageConfig.PATH.value, self)

        self.data_store.update_data(DataKeys.INITIAL_SURF_NS.value, 0)
        self.data_store.update_data(DataKeys.INITIAL_NS.value, 0)

        # self.task_function = cstr_calculator

        self.update_head_lines()

        self.update_property_line(Ph1dInputPageWidgets.DIAMETER_EDIT_LINE.value,
                                  Ph1dInputPageWidgets.DIAMETER_COMBO_BOX.value,
                                  self.ud_handler.length_ud)
        self.update_property_line(Ph1dInputPageWidgets.CATALYTIC_LOAD_EDIT_LINE.value,
                                  Ph1dInputPageWidgets.CATALYTIC_LOAD_COMBO_BOX.value,
                                  self.ud_handler.one_over_length_ud)
        self.update_property_line(Ph1dInputPageWidgets.MASS_FLOW_RATE_EDIT_LINE.value,
                                  Ph1dInputPageWidgets.MASS_FLOW_RATE_COMBO_BOX.value,
                                  self.ud_handler.mass_flow_rate_ud)
        self.update_property_line(Ph1dInputPageWidgets.INTEGRATION_TIME_EDIT_LINE.value,
                                  Ph1dInputPageWidgets.INTEGRATION_TIME_COMBO_BOX.value,
                                  self.ud_handler.time_ud)
        self.update_property_line(Ph1dInputPageWidgets.INTEGRATION_STEP_EDIT_LINE.value,
                                  Ph1dInputPageWidgets.INTEGRATION_STEP_COMBO_BOX.value,
                                  self.ud_handler.time_ud)
        self.update_property_line(Ph1dInputPageWidgets.TEMPERATURE_EDIT_LINE.value,
                                  Ph1dInputPageWidgets.TEMPERATURE_COMBO_BOX.value,
                                  self.ud_handler.temperature_ud)

        self.update_buttons()

        self._minimum_row_idx_dict, self._tab_name_to_grid_layout_dict = self.get_initial_layout_info()
        self._dynamic_row_idx_dict = self._minimum_row_idx_dict.copy()

    #
    # @staticmethod
    # def from_ns_to_row_idx(ns) -> int:
    #     """
    #     Convert the number of species to row idx
    #     Parameters
    #     ----------
    #     ns: int
    #         Number of species
    #
    #     Returns
    #     -------
    #     row_idx: int
    #         Row index corresponding to the number of species based on the layout
    #     """
    #     return ns + 3
    #
    # @staticmethod
    # def from_surf_ns_to_row_idx(surf_ns) -> int:
    #     """
    #     Convert the number of surface species to row idx
    #     Parameters
    #     ----------
    #     surf_ns: int
    #         Number of species
    #
    #     Returns
    #     -------
    #     row_idx: int
    #         Row index corresponding to the number of species based on the layout
    #     """
    #     return surf_ns + 1
    #
    def get_initial_layout_info(self) -> tuple:
        """
        Extract info of the layout before applying any change
        Returns
        -------
        output_tuple: tuple
            Tuple of dictionary describing the minimum row idx and tab name to grid layout dictionary
        """
        tab_name_to_grid_layout_dict = {ReactorConfig.SOLVING_OPTION_TAB_NAME.value:
                                        Ph1dInputPageWidgets.SOLVING_OPTION_LAYOUT.value,
                                        ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value:
                                        Ph1dInputPageWidgets.REACTOR_PROPERTIES_LAYOUT.value,
                                        ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value:
                                        Ph1dInputPageWidgets.COVERAGE_COMPOSITION_LAYOUT.value,
                                        ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value:
                                        Ph1dInputPageWidgets.INITIAL_CONDITIONS_LAYOUT.value}

        minimum_row_idx_dict = {k: self.findChild(QGridLayout, n).rowCount() - 1 for k, n in
                                tab_name_to_grid_layout_dict.items()}

        return minimum_row_idx_dict, tab_name_to_grid_layout_dict

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.data_store.update_data(DataKeys.REACTOR_NAME.value, Ph1dInputPageConfig.REACTOR_NAME.value)
        self.data_store.update_data(DataKeys.TEMPERATURE_TYPES.value, Ph1dInputPageConfig.TEMPERATURES.value)
        self.data_store.update_data(DataKeys.REACTOR_PAGE_NAME.value, Ph1dInputPageConfig.NAME.value)

        # TODO - Set to steady state and update when option is changed
        #self.data_store.update_data(DataKeys.REACTOR_TYPE.value, CstrReactor)

        self.data_store = surface_species_names(self.data_store)
        self.update_composition_names(0,
                                      self.data_store.get_data(DataKeys.SURFACE_SPECIES_NAMES.value),
                                      InputCompositionConfig.SURFACE_SPECIE_COMBO_BOX_NAME.value,
                                      InputCompositionConfig.SURFACE_SPECIE_EDIT_LINE_NAME.value)

        self.data_store = gas_species_names(self.data_store)
        self.update_composition_names(0,
                                      self.data_store.get_data(DataKeys.GAS_SPECIES_NAMES.value),
                                      InputCompositionConfig.GAS_SPECIE_COMBO_BOX_NAME.value,
                                      InputCompositionConfig.GAS_SPECIE_EDIT_LINE_NAME.value)

        for tab_name in Ph1dInputPageConfig.TABS_NAMES.value:
            layout_name = self._tab_name_to_grid_layout_dict[tab_name]
            self.update_grid_layout(grid_layout_name=layout_name)

    def update_head_lines(self) -> None:
        """
        Update head lines
        Returns
        -------

        """
        tab_widget = self.findChild(QTabWidget, Ph1dInputPageWidgets.TAB_WIDGET.value)

        for i, n in enumerate(Ph1dInputPageConfig.TABS_NAMES.value):
            tab_widget.setTabText(i, n)

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        udk_button = self.findChild(QPushButton, Ph1dInputPageWidgets.USER_DEFINED_KINETIC_BUTTON.value)
        udk_button.clicked.connect(self.load_udk_file)

        back_button = self.findChild(QPushButton, Ph1dInputPageWidgets.BACK_BUTTON.value)
        back_button.clicked.connect(lambda: self.page_switched.emit(CalculationInputPageConfig.NAME.value))

        add_coverage_button = self.findChild(QPushButton, Ph1dInputPageWidgets.ADD_SURF_SPECIE_BUTTON.value)
        #add_coverage_button.clicked.connect(self.add_coverage_line)

        remove_coverage_button = self.findChild(QPushButton, Ph1dInputPageWidgets.REMOVE_SURF_SPECIE_BUTTON.value)
        #remove_coverage_button.clicked.connect(self.remove_coverage_line)

        add_specie_button = self.findChild(QPushButton, Ph1dInputPageWidgets.ADD_GAS_SPECIE_BUTTON.value)
        #add_specie_button.clicked.connect(self.add_specie_line)

        remove_specie_button = self.findChild(QPushButton, Ph1dInputPageWidgets.REMOVE_GAS_SPECIE_BUTTON.value)
        #remove_specie_button.clicked.connect(self.remove_specie_line)

        run_button = self.findChild(QPushButton, Ph1dInputPageWidgets.RUN_BUTTON.value)
        run_button.clicked.connect(self.run_button_action)
    #
    # def add_coverage_line(self) -> None:
    #     """
    #     Add coverage line to the layout
    #     Returns
    #     -------
    #
    #     """
    #     surf_ns = int(self.data_store.get_data(DataKeys.INITIAL_SURF_NS.value) + 1)
    #     self.data_store.update_data(DataKeys.INITIAL_SURF_NS.value, surf_ns)
    #     surf_ns_row_idx = self.from_surf_ns_to_row_idx(surf_ns)
    #
    #     # Coverage tab
    #     tab_name = ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value
    #     row_idx = self._dynamic_row_idx_dict[tab_name]
    #     layout_name = self._tab_name_to_grid_layout_dict[tab_name]
    #
    #     if surf_ns_row_idx > self._dynamic_row_idx_dict[tab_name]:
    #         row_idx = row_idx + 1
    #         self.add_surface_specie_input_row_to_grid_layout(layout_name,
    #                                                          surf_ns,
    #                                                          row_idx,
    #                                                          with_label=True)
    #         self.update_grid_layout(layout_name)
    #         self._dynamic_row_idx_dict[tab_name] = row_idx
    #     else:
    #         self.remove_row_from_grid_layout(layout_name, surf_ns_row_idx)
    #         self.add_surface_specie_input_row_to_grid_layout(layout_name,
    #                                                          surf_ns,
    #                                                          surf_ns_row_idx,
    #                                                          with_label=True)
    #         self.update_grid_layout(layout_name)
    #
    #     # Other tabs
    #     for tab_name in [ReactorConfig.SOLVING_OPTION_TAB_NAME.value,
    #                      ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value,
    #                      ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value]:
    #         if surf_ns_row_idx > self._dynamic_row_idx_dict[tab_name]:
    #             row_idx = self._dynamic_row_idx_dict[tab_name] + 1
    #             layout_name = self._tab_name_to_grid_layout_dict[tab_name]
    #             self.add_dummy_row_to_grid_layout(layout_name, row_idx)
    #             self._dynamic_row_idx_dict[tab_name] = row_idx
    #
    # def remove_coverage_line(self) -> None:
    #     """
    #     Remove coverage line to the layout
    #     Returns
    #     -------
    #
    #     """
    #     surf_ns = int(self.data_store.get_data(DataKeys.INITIAL_SURF_NS.value))
    #
    #     if surf_ns > 0:
    #         self.data_store.update_data(DataKeys.INITIAL_SURF_NS.value, surf_ns - 1)
    #         ns = int(self.data_store.get_data(DataKeys.INITIAL_NS.value))
    #         surf_ns_row_idx = self.from_surf_ns_to_row_idx(surf_ns)
    #         ns_row_idx = self.from_ns_to_row_idx(ns)
    #
    #         if ns_row_idx >= surf_ns_row_idx:
    #             tab_name = ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value
    #             layout_name = self._tab_name_to_grid_layout_dict[tab_name]
    #             self.remove_row_from_grid_layout(layout_name, surf_ns_row_idx)
    #             self.add_dummy_row_to_grid_layout(layout_name, surf_ns_row_idx)
    #         else:
    #             for tab_name in [ReactorConfig.SOLVING_OPTION_TAB_NAME.value,
    #                              ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value,
    #                              ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value]:
    #                 row_idx = self._dynamic_row_idx_dict[tab_name]
    #                 if row_idx > self._minimum_row_idx_dict[tab_name]:
    #                     layout_name = self._tab_name_to_grid_layout_dict[tab_name]
    #                     self.remove_row_from_grid_layout(layout_name, row_idx)
    #                     self._dynamic_row_idx_dict[tab_name] = row_idx - 1
    #
    #             tab_name = ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value
    #             if ns_row_idx < self._dynamic_row_idx_dict[tab_name]:
    #                 layout_name = self._tab_name_to_grid_layout_dict[tab_name]
    #                 self.remove_row_from_grid_layout(layout_name, row_idx)
    #                 self._dynamic_row_idx_dict[tab_name] = row_idx - 1
    #
    # def add_specie_line(self) -> None:
    #     """
    #     Add specie line to the layout
    #     Returns
    #     -------
    #
    #     """
    #     ns = int(self.data_store.get_data(DataKeys.INITIAL_NS.value) + 1)
    #     self.data_store.update_data(DataKeys.INITIAL_NS.value, ns)
    #     ns_row_idx = self.from_ns_to_row_idx(ns)
    #
    #     # Coverage tab
    #     tab_name = ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value
    #     row_idx = self._dynamic_row_idx_dict[tab_name]
    #     layout_name = self._tab_name_to_grid_layout_dict[tab_name]
    #
    #     if ns_row_idx > self._dynamic_row_idx_dict[tab_name]:
    #         row_idx = row_idx + 1
    #         self.add_gas_specie_input_row_to_grid_layout(layout_name,
    #                                                      ns,
    #                                                      row_idx,
    #                                                      with_label=True)
    #         self.update_grid_layout(layout_name)
    #         self._dynamic_row_idx_dict[tab_name] = row_idx
    #     else:
    #         self.remove_row_from_grid_layout(layout_name, ns_row_idx)
    #         self.add_gas_specie_input_row_to_grid_layout(layout_name,
    #                                                      ns,
    #                                                      ns_row_idx,
    #                                                      with_label=True)
    #         self.update_grid_layout(layout_name)
    #
    #     # Other tabs
    #     for tab_name in [ReactorConfig.SOLVING_OPTION_TAB_NAME.value,
    #                      ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value,
    #                      ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value]:
    #         if ns_row_idx > self._dynamic_row_idx_dict[tab_name]:
    #             row_idx = self._dynamic_row_idx_dict[tab_name] + 1
    #             layout_name = self._tab_name_to_grid_layout_dict[tab_name]
    #             self.add_dummy_row_to_grid_layout(layout_name, row_idx)
    #             self._dynamic_row_idx_dict[tab_name] = row_idx
    #
    # def remove_specie_line(self) -> None:
    #     """
    #     Remove specie line to the layout
    #     Returns
    #     -------
    #
    #     """
    #     ns = int(self.data_store.get_data(DataKeys.INITIAL_NS.value))
    #
    #     if ns > 0:
    #         self.data_store.update_data(DataKeys.INITIAL_NS.value, ns - 1)
    #         surf_ns = int(self.data_store.get_data(DataKeys.INITIAL_SURF_NS.value))
    #         surf_ns_row_idx = self.from_surf_ns_to_row_idx(surf_ns)
    #         ns_row_idx = self.from_ns_to_row_idx(ns)
    #
    #         if surf_ns_row_idx >= ns_row_idx:
    #             tab_name = ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value
    #             layout_name = self._tab_name_to_grid_layout_dict[tab_name]
    #             self.remove_row_from_grid_layout(layout_name, ns_row_idx)
    #             self.add_dummy_row_to_grid_layout(layout_name, ns_row_idx)
    #         else:
    #             for tab_name in [ReactorConfig.SOLVING_OPTION_TAB_NAME.value,
    #                              ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value,
    #                              ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value]:
    #                 row_idx = self._dynamic_row_idx_dict[tab_name]
    #                 if row_idx > self._minimum_row_idx_dict[tab_name]:
    #                     layout_name = self._tab_name_to_grid_layout_dict[tab_name]
    #                     self.remove_row_from_grid_layout(layout_name, row_idx)
    #                     self._dynamic_row_idx_dict[tab_name] = row_idx - 1
    #
    #             tab_name = ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value
    #             if surf_ns_row_idx < self._dynamic_row_idx_dict[tab_name]:
    #                 layout_name = self._tab_name_to_grid_layout_dict[tab_name]
    #                 self.remove_row_from_grid_layout(layout_name, row_idx)
    #                 self._dynamic_row_idx_dict[tab_name] = row_idx - 1
    #
    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        pass
        # TODO - Set class of reactor based on selection

        """
        # Volume
        self.read_data_from_property_line(Ph1dInputPageWidgets.VOLUME_EDIT_LINE.value,
                                          Ph1dInputPageWidgets.VOLUME_COMBO_BOX.value,
                                          DataKeys.VOLUME)

        # Catalytic load
        self.read_data_from_property_line(Ph1dInputPageWidgets.CATALYTIC_LOAD_EDIT_LINE.value,
                                          Ph1dInputPageWidgets.CATALYTIC_LOAD_COMBO_BOX.value, DataKeys.ALFA)

        # Mass flow rate
        self.read_data_from_property_line(Ph1dInputPageWidgets.MASS_FLOW_RATE_EDIT_LINE.value,
                                          Ph1dInputPageWidgets.MASS_FLOW_RATE_COMBO_BOX.value,
                                          DataKeys.MASS_FLOW_RATE)

        # Coverage
        value = {}
        for i in range(0, int(self.data_store.get_data(DataKeys.INITIAL_SURF_NS.value) + 1)):
            specie_name = self.findChild(QComboBox,
                                         InputCompositionConfig.SURFACE_SPECIE_COMBO_BOX_NAME.value.format(i)).currentText()
            specie_value = self.findChild(QLineEdit,
                                          InputCompositionConfig.SURFACE_SPECIE_EDIT_LINE_NAME.value.format(i)).text()
            value[specie_name] = float(specie_value)
        self.data_store.update_data(DataKeys.INITIAL_SURF_COMPOSITION.value, value)

        # Initial composition
        value = {}
        for i in range(0, int(self.data_store.get_data(DataKeys.INITIAL_NS.value) + 1)):
            specie_name = self.findChild(QComboBox,
                                         InputCompositionConfig.GAS_SPECIE_COMBO_BOX_NAME.value.format(i)).currentText()
            specie_value = self.findChild(QLineEdit,
                                          InputCompositionConfig.GAS_SPECIE_EDIT_LINE_NAME.value.format(i)).text()
            value[specie_name] = float(specie_value)
        ud = self.findChild(QComboBox, Ph1dInputPageWidgets.COMPOSITION_COMBO_BOX.value).currentText()
        self.data_store.update_data(DataKeys.INITIAL_GAS_COMPOSITION.value, (value, ud))

        # Initial temperature
        self.read_data_from_property_line(Ph1dInputPageWidgets.TEMPERATURE_EDIT_LINE.value,
                                          Ph1dInputPageWidgets.TEMPERATURE_COMBO_BOX.value,
                                          DataKeys.INITIAL_GAS_T)

        # Energy balance
        checkbox = self.findChild(QCheckBox, Ph1dInputPageWidgets.ENERGY_CHECK_BOX.value)
        self.data_store.update_data(DataKeys.ENERGY_BALANCE.value, checkbox.isChecked())

        # Integration time
        self.read_data_from_property_line(Ph1dInputPageWidgets.INTEGRATION_TIME_EDIT_LINE.value,
                                          Ph1dInputPageWidgets.INTEGRATION_TIME_COMBO_BOX.value,
                                          DataKeys.TMAX)

        # Integration time step
        self.read_data_from_property_line(Ph1dInputPageWidgets.INTEGRATION_STEP_EDIT_LINE.value,
                                          Ph1dInputPageWidgets.INTEGRATION_STEP_COMBO_BOX.value,
                                          DataKeys.TSTEP)
        """