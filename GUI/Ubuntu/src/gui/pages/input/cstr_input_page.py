from PyQt5 import uic
from PyQt5.QtWidgets import QPushButton, QLineEdit, QGridLayout, QCheckBox, QTabWidget, QComboBox
from asali.reactors.cstr import CstrReactor

from src.config.calculation_input_page_config import CalculationInputPageConfig
from src.config.cstr_input_page_config import CstrInputPageConfig
from src.config.input_composition_config import InputCompositionConfig
from src.core.composition_type import CompositionType
from src.core.cstr_calculator import cstr_calculator
from src.core.data_keys import DataKeys
from src.core.species_names import surface_species_names, gas_species_names

from src.config.reactor_config import ReactorConfig
from src.gui.pages.input.advanced_reactor_input_page import AdvancedReactorInputPage
from src.gui.widgets.input.cstr_input_page import CstrInputPageWidgets


class CstrInputPage(AdvancedReactorInputPage):
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
        self.update_property_line(CstrInputPageWidgets.VOLUME_EDIT_LINE.value,
                                  CstrInputPageWidgets.VOLUME_COMBO_BOX.value,
                                  self.ud_handler.volume_ud)
        self.update_property_line(CstrInputPageWidgets.CATALYTIC_LOAD_EDIT_LINE.value,
                                  CstrInputPageWidgets.CATALYTIC_LOAD_COMBO_BOX.value,
                                  self.ud_handler.one_over_length_ud)
        self.update_property_line(CstrInputPageWidgets.MASS_FLOW_RATE_EDIT_LINE.value,
                                  CstrInputPageWidgets.MASS_FLOW_RATE_COMBO_BOX.value,
                                  self.ud_handler.mass_flow_rate_ud)
        self.update_property_line(CstrInputPageWidgets.INTEGRATION_TIME_EDIT_LINE.value,
                                  CstrInputPageWidgets.INTEGRATION_TIME_COMBO_BOX.value,
                                  self.ud_handler.time_ud)
        self.update_property_line(CstrInputPageWidgets.INTEGRATION_STEP_EDIT_LINE.value,
                                  CstrInputPageWidgets.INTEGRATION_STEP_COMBO_BOX.value,
                                  self.ud_handler.time_ud)
        self.update_property_line(CstrInputPageWidgets.TEMPERATURE_EDIT_LINE.value,
                                  CstrInputPageWidgets.TEMPERATURE_COMBO_BOX.value,
                                  self.ud_handler.temperature_ud)
        self.update_buttons()

        self._minimum_row_idx_dict, self._tab_name_to_grid_layout_dict = self.get_initial_layout_info()
        self._dynamic_row_idx_dict = self._minimum_row_idx_dict.copy()

    @property
    def number_of_gas_species_to_row_idx(self) -> int:
        """
        Property that returns the number of gas species to row index value
        Returns
        -------

        """
        return CstrInputPageConfig.GAS_SPECIE_TO_ROW_INDEX.value

    @property
    def number_of_surface_species_to_row_idx(self) -> int:
        """
        Property that returns the number of surface species to row index value
        Returns
        -------

        """
        return CstrInputPageConfig.SURFACE_SPECIE_TO_ROW_INDEX.value

    def get_initial_layout_info(self) -> tuple:
        """
        Extract info of the layout before applying any change
        Returns
        -------
        output_tuple: tuple
            Tuple of dictionary describing the minimum row idx and tab name to grid layout dictionary
        """
        tab_name_to_grid_layout_dict = {ReactorConfig.SOLVING_OPTION_TAB_NAME.value:
                                            CstrInputPageWidgets.SOLVING_OPTION_LAYOUT.value,
                                        ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value:
                                            CstrInputPageWidgets.REACTOR_PROPERTIES_LAYOUT.value,
                                        ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value:
                                            CstrInputPageWidgets.COVERAGE_COMPOSITION_LAYOUT.value,
                                        ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value:
                                            CstrInputPageWidgets.INITIAL_CONDITIONS_LAYOUT.value}

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
                                      InputCompositionConfig.SURFACE_SPECIE_COMBO_BOX_NAME.value,
                                      InputCompositionConfig.SURFACE_SPECIE_EDIT_LINE_NAME.value)

        self.data_store = gas_species_names(self.data_store)
        self.update_composition_names(0,
                                      self.data_store.get_data(DataKeys.GAS_SPECIES_NAMES.value),
                                      InputCompositionConfig.GAS_SPECIE_COMBO_BOX_NAME.value,
                                      InputCompositionConfig.GAS_SPECIE_EDIT_LINE_NAME.value)

        for tab_name in CstrInputPageConfig.TABS_NAMES.value:
            layout_name = self._tab_name_to_grid_layout_dict[tab_name]
            self.update_grid_layout(grid_layout_name=layout_name)

    def update_head_lines(self) -> None:
        """
        Update head lines
        Returns
        -------

        """
        tab_widget = self.findChild(QTabWidget, CstrInputPageWidgets.TAB_WIDGET.value)

        for i, n in enumerate(CstrInputPageConfig.TABS_NAMES.value):
            tab_widget.setTabText(i, n)

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        udk_button = self.findChild(QPushButton, CstrInputPageWidgets.USER_DEFINED_KINETIC_BUTTON.value)
        udk_button.clicked.connect(self.load_udk_file)

        back_button = self.findChild(QPushButton, CstrInputPageWidgets.BACK_BUTTON.value)
        back_button.clicked.connect(lambda: self.page_switched.emit(CalculationInputPageConfig.NAME.value))

        add_coverage_button = self.findChild(QPushButton, CstrInputPageWidgets.ADD_SURF_SPECIE_BUTTON.value)
        add_coverage_button.clicked.connect(self.add_coverage_line)

        remove_coverage_button = self.findChild(QPushButton, CstrInputPageWidgets.REMOVE_SURF_SPECIE_BUTTON.value)
        remove_coverage_button.clicked.connect(self.remove_coverage_line)

        add_specie_button = self.findChild(QPushButton, CstrInputPageWidgets.ADD_GAS_SPECIE_BUTTON.value)
        add_specie_button.clicked.connect(self.add_specie_line)

        remove_specie_button = self.findChild(QPushButton, CstrInputPageWidgets.REMOVE_GAS_SPECIE_BUTTON.value)
        remove_specie_button.clicked.connect(self.remove_specie_line)

        run_button = self.findChild(QPushButton, CstrInputPageWidgets.RUN_BUTTON.value)
        run_button.clicked.connect(self.run_button_action)

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        # Volume
        self.read_data_from_property_line(CstrInputPageWidgets.VOLUME_EDIT_LINE.value,
                                          CstrInputPageWidgets.VOLUME_COMBO_BOX.value,
                                          DataKeys.VOLUME)

        # Catalytic load
        self.read_data_from_property_line(CstrInputPageWidgets.CATALYTIC_LOAD_EDIT_LINE.value,
                                          CstrInputPageWidgets.CATALYTIC_LOAD_COMBO_BOX.value, DataKeys.ALFA)

        # Mass flow rate
        self.read_data_from_property_line(CstrInputPageWidgets.MASS_FLOW_RATE_EDIT_LINE.value,
                                          CstrInputPageWidgets.MASS_FLOW_RATE_COMBO_BOX.value,
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

        ud = self.findChild(QComboBox, CstrInputPageWidgets.COMPOSITION_COMBO_BOX.value).currentText()
        if "mol" in ud.lower():
            self.data_store.update_data(DataKeys.INITIAL_GAS_COMPOSITION.value, (value, CompositionType.MOLE))
        else:
            self.data_store.update_data(DataKeys.INITIAL_GAS_COMPOSITION.value, (value, CompositionType.MASS))

        # Initial temperature
        self.read_data_from_property_line(CstrInputPageWidgets.TEMPERATURE_EDIT_LINE.value,
                                          CstrInputPageWidgets.TEMPERATURE_COMBO_BOX.value,
                                          DataKeys.INITIAL_GAS_T)

        # Energy balance
        checkbox = self.findChild(QCheckBox, CstrInputPageWidgets.ENERGY_CHECK_BOX.value)
        self.data_store.update_data(DataKeys.ENERGY_BALANCE.value, checkbox.isChecked())

        # Integration time
        self.read_data_from_property_line(CstrInputPageWidgets.INTEGRATION_TIME_EDIT_LINE.value,
                                          CstrInputPageWidgets.INTEGRATION_TIME_COMBO_BOX.value,
                                          DataKeys.TMAX)

        # Integration time step
        self.read_data_from_property_line(CstrInputPageWidgets.INTEGRATION_STEP_EDIT_LINE.value,
                                          CstrInputPageWidgets.INTEGRATION_STEP_COMBO_BOX.value,
                                          DataKeys.TSTEP)
