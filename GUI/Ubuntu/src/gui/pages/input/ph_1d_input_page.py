from PyQt5 import uic
from PyQt5.QtWidgets import QPushButton, QLineEdit, QGridLayout, QCheckBox, QTabWidget, QComboBox, QLabel
from asali.reactors.ph1d_steady_state import SteadyStatePseudoHomogeneous1DReactor
from asali.reactors.ph1d_transient import TransientPseudoHomogeneous1DReactor

from src.config.calculation_input_page_config import CalculationInputPageConfig
from src.config.input_composition_config import InputCompositionConfig
from src.config.ph_1d_input_page_config import Ph1dInputPageConfig
from src.core.composition_type import CompositionType
from src.core.data_keys import DataKeys
from src.core.ph_1d_calculator import pseudo_homogeneous_1d_reactor_calculator
from src.core.reactor_resolution_method import ReactorResolutionMethod
from src.core.species_names import surface_species_names, gas_species_names

from src.config.reactor_config import ReactorConfig
from src.gui.pages.input.basic_reactor_input_page import BasicReactorInputPage
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
        # Load the UI from the .ui file
        uic.loadUi(Ph1dInputPageConfig.PATH.value, self)

        self.data_store.update_data(DataKeys.INITIAL_SURF_NS.value, 0)
        self.data_store.update_data(DataKeys.INITIAL_NS.value, 0)

        self.update_tab_names(Ph1dInputPageWidgets.TAB_WIDGET.value)

        self.update_property_line(Ph1dInputPageWidgets.DIAMETER_EDIT_LINE.value,
                                  Ph1dInputPageWidgets.DIAMETER_COMBO_BOX.value,
                                  self.ud_handler.length_ud)
        self.update_property_line(Ph1dInputPageWidgets.LENGTH_EDIT_LINE.value,
                                  Ph1dInputPageWidgets.LENGTH_COMBO_BOX.value,
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
        self.update_combo_box()

        self.task_function = pseudo_homogeneous_1d_reactor_calculator
        self.tab_name_to_row_idx_dict = self.tab_name_to_minimum_row_idx_dict.copy()
        self.surf_ns = 0
        self.ns = 0

    @property
    def number_of_gas_species_to_row_idx(self) -> int:
        """
        Property that returns the number of gas species to row index value
        Returns
        -------

        """
        return Ph1dInputPageConfig.GAS_SPECIE_TO_ROW_INDEX.value

    @property
    def number_of_surface_species_to_row_idx(self) -> int:
        """
        Property that returns the number of surface species to row index value
        Returns
        -------

        """
        return Ph1dInputPageConfig.SURFACE_SPECIE_TO_ROW_INDEX.value

    @property
    def tab_names(self) -> list:
        """
        Property that return the tab name list
        Returns
        -------
        tab_names: list
            List of tab names
        """
        return Ph1dInputPageConfig.TABS_NAMES.value

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
                    Ph1dInputPageWidgets.SOLVING_OPTION_LAYOUT.value,
                ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value:
                    Ph1dInputPageWidgets.REACTOR_PROPERTIES_LAYOUT.value,
                ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value:
                    Ph1dInputPageWidgets.COVERAGE_COMPOSITION_LAYOUT.value,
                ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value:
                    Ph1dInputPageWidgets.INITIAL_CONDITIONS_LAYOUT.value}

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
                    Ph1dInputPageConfig.SOLVING_OPTION_LAYOUT_MINIMUM_ROW_IDX.value,
                ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value:
                    Ph1dInputPageConfig.REACTOR_PROPERTIES_LAYOUT_MINIMUM_ROW_IDX.value,
                ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value:
                    Ph1dInputPageConfig.COVERAGE_COMPOSITION_LAYOUT_MINIMUM_ROW_IDX.value,
                ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value:
                    Ph1dInputPageConfig.INITIAL_CONDITION_LAYOUT_MINIMUM_ROW_IDX.value}

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.data_store.update_data(DataKeys.REACTOR_NAME.value, Ph1dInputPageConfig.REACTOR_NAME.value)
        self.data_store.update_data(DataKeys.TEMPERATURE_TYPES.value, Ph1dInputPageConfig.TEMPERATURES.value)
        self.data_store.update_data(DataKeys.REACTOR_PAGE_NAME.value, Ph1dInputPageConfig.NAME.value)

        self.set_resolution_method()

        # Update coverage
        self.data_store = surface_species_names(self.data_store)
        self.update_composition_names(0,
                                      self.data_store.get_data(DataKeys.SURFACE_SPECIES_NAMES.value),
                                      InputCompositionConfig.SURFACE_SPECIE_COMBO_BOX_NAME.value,
                                      InputCompositionConfig.SURFACE_SPECIE_EDIT_LINE_NAME.value)

        # Update initial composition
        self.data_store = gas_species_names(self.data_store)
        self.update_composition_names(0,
                                      self.data_store.get_data(DataKeys.GAS_SPECIES_NAMES.value),
                                      InputCompositionConfig.GAS_SPECIE_COMBO_BOX_NAME.value,
                                      InputCompositionConfig.GAS_SPECIE_EDIT_LINE_NAME.value)

        # Update inert gas specie
        dropdown = self.findChild(QComboBox, Ph1dInputPageWidgets.INERT_GAS_SPECIE_COMBO_BOX.value)
        dropdown.clear()
        dropdown.addItems(self.data_store.get_data(DataKeys.GAS_SPECIES_NAMES.value))

        # Update inert surface specie
        dropdown = self.findChild(QComboBox, Ph1dInputPageWidgets.INERT_SURFACE_SPECIE_COMBO_BOX.value)
        dropdown.clear()
        dropdown.addItems(self.data_store.get_data(DataKeys.SURFACE_SPECIES_NAMES.value))

        for tab_name in self.tab_names:
            layout_name = self.tab_name_to_grid_layout_name_dict[tab_name]
            self.update_grid_layout(grid_layout_name=layout_name)

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
        add_coverage_button.clicked.connect(self.add_coverage_line)

        remove_coverage_button = self.findChild(QPushButton, Ph1dInputPageWidgets.REMOVE_SURF_SPECIE_BUTTON.value)
        remove_coverage_button.clicked.connect(self.remove_coverage_line)

        add_specie_button = self.findChild(QPushButton, Ph1dInputPageWidgets.ADD_GAS_SPECIE_BUTTON.value)
        add_specie_button.clicked.connect(self.add_initial_specie_line)

        remove_specie_button = self.findChild(QPushButton, Ph1dInputPageWidgets.REMOVE_GAS_SPECIE_BUTTON.value)
        remove_specie_button.clicked.connect(self.remove_initial_specie_line)

        run_button = self.findChild(QPushButton, Ph1dInputPageWidgets.RUN_BUTTON.value)
        run_button.clicked.connect(self.run_button_action)

    def update_combo_box(self) -> None:
        """
        Update combo boxes
        Returns
        -------

        """
        resolution_method_combo_box = self.findChild(QComboBox, Ph1dInputPageWidgets.RESOLUTION_METHOD_COMBO_BOX.value)
        resolution_method_combo_box.currentTextChanged.connect(self.set_resolution_method)

    def set_resolution_method(self) -> None:
        """
        Set resolution method
        Returns
        -------

        """
        resolution_method_combo_box = self.findChild(QComboBox, Ph1dInputPageWidgets.RESOLUTION_METHOD_COMBO_BOX.value)
        widget_dict = {Ph1dInputPageWidgets.INTEGRATION_STEP_EDIT_LINE.value: QLineEdit,
                       Ph1dInputPageWidgets.INTEGRATION_TIME_EDIT_LINE.value: QLineEdit,
                       Ph1dInputPageWidgets.INTEGRATION_STEP_COMBO_BOX.value: QComboBox,
                       Ph1dInputPageWidgets.INTEGRATION_TIME_COMBO_BOX.value: QComboBox,
                       Ph1dInputPageWidgets.INTEGRATION_STEP_LABEL.value: QLabel,
                       Ph1dInputPageWidgets.INTEGRATION_TIME_LABEL.value: QLabel}

        if resolution_method_combo_box.currentIndex() == 0:
            for n, t in widget_dict.items():
                w = self.findChild(t, n)
                w.hide()
            self.data_store.update_data(DataKeys.REACTOR_TYPE.value,
                                        SteadyStatePseudoHomogeneous1DReactor)
            self.data_store.update_data(DataKeys.REACTOR_RESOLUTION_METHOD.value,
                                        ReactorResolutionMethod.STEADY_STATE)

        else:
            for n, t in widget_dict.items():
                w = self.findChild(t, n)
                w.show()
            self.data_store.update_data(DataKeys.REACTOR_TYPE.value,
                                        TransientPseudoHomogeneous1DReactor)
            self.data_store.update_data(DataKeys.REACTOR_RESOLUTION_METHOD.value,
                                        ReactorResolutionMethod.TRANSIENT)

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        # Initial number of surface species
        self.data_store.update_data(DataKeys.INITIAL_SURF_NS.value, self.surf_ns)

        # Initial number of gas species
        self.data_store.update_data(DataKeys.INITIAL_NS.value, self.ns)

        # Diameter
        self.read_data_from_property_line(Ph1dInputPageWidgets.DIAMETER_EDIT_LINE.value,
                                          Ph1dInputPageWidgets.DIAMETER_COMBO_BOX.value,
                                          DataKeys.DIAMETER)

        # Length
        self.read_data_from_property_line(Ph1dInputPageWidgets.LENGTH_EDIT_LINE.value,
                                          Ph1dInputPageWidgets.LENGTH_COMBO_BOX.value,
                                          DataKeys.LENGTH)

        # Catalytic load
        self.read_data_from_property_line(Ph1dInputPageWidgets.CATALYTIC_LOAD_EDIT_LINE.value,
                                          Ph1dInputPageWidgets.CATALYTIC_LOAD_COMBO_BOX.value,
                                          DataKeys.ALFA)

        # Mass flow rate
        self.read_data_from_property_line(Ph1dInputPageWidgets.MASS_FLOW_RATE_EDIT_LINE.value,
                                          Ph1dInputPageWidgets.MASS_FLOW_RATE_COMBO_BOX.value,
                                          DataKeys.MASS_FLOW_RATE)

        # Coverage
        value = {}
        for i in range(0, int(self.data_store.get_data(DataKeys.INITIAL_SURF_NS.value) + 1)):
            specie_name = self.findChild(QComboBox,
                                         InputCompositionConfig.SURFACE_SPECIE_COMBO_BOX_NAME.value.format(
                                             i)).currentText()
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
        if "mol" in ud.lower():
            self.data_store.update_data(DataKeys.INITIAL_GAS_COMPOSITION.value, (value, CompositionType.MOLE))
        else:
            self.data_store.update_data(DataKeys.INITIAL_GAS_COMPOSITION.value, (value, CompositionType.MASS))

        # Initial temperature
        self.read_data_from_property_line(Ph1dInputPageWidgets.TEMPERATURE_EDIT_LINE.value,
                                          Ph1dInputPageWidgets.TEMPERATURE_COMBO_BOX.value,
                                          DataKeys.INITIAL_GAS_T)

        # Energy balance
        checkbox = self.findChild(QCheckBox, Ph1dInputPageWidgets.ENERGY_CHECK_BOX.value)
        self.data_store.update_data(DataKeys.ENERGY_BALANCE.value, checkbox.isChecked())

        # Diffusion
        checkbox = self.findChild(QCheckBox, Ph1dInputPageWidgets.DIFFUSION_CHECK_BOX.value)
        self.data_store.update_data(DataKeys.DIFFUSION.value, checkbox.isChecked())

        # Inert gas specie
        combo_box = self.findChild(QComboBox, Ph1dInputPageWidgets.INERT_GAS_SPECIE_COMBO_BOX.value)
        self.data_store.update_data(DataKeys.INERT_GAS_SPECIE.value, combo_box.currentText())

        # Inert surface specie
        combo_box = self.findChild(QComboBox, Ph1dInputPageWidgets.INERT_SURFACE_SPECIE_COMBO_BOX.value)
        self.data_store.update_data(DataKeys.INERT_SURFACE_SPECIE.value, combo_box.currentText())

        # Integration time
        self.read_data_from_property_line(Ph1dInputPageWidgets.INTEGRATION_TIME_EDIT_LINE.value,
                                          Ph1dInputPageWidgets.INTEGRATION_TIME_COMBO_BOX.value,
                                          DataKeys.TMAX)

        # Integration time step
        self.read_data_from_property_line(Ph1dInputPageWidgets.INTEGRATION_STEP_EDIT_LINE.value,
                                          Ph1dInputPageWidgets.INTEGRATION_STEP_COMBO_BOX.value,
                                          DataKeys.TSTEP)
