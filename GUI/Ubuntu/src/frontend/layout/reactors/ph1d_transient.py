from types import SimpleNamespace
from PyQt5.QtWidgets import QMainWindow

from src.backend.reactors.runners import run_transient_pseudo_homogeneous_reactor_model
from src.frontend.layout.reactors.basic_transient import BasicTransientReactorLayout
from src.frontend.utils import ReactorVariablesName


class TransientPseudoHomogeneous1DReactorLayout(BasicTransientReactorLayout):
    def __init__(self, main_window):
        """
        Transient state 1D pseudo-homogeneous reactor layout
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        super().__init__(main_window)
        self.reactor_model_function = run_transient_pseudo_homogeneous_reactor_model

    def read_input(self) -> dict:
        """
        Run the model with the run bar
        Returns
        -------
        input_dict: dict
            Dictionary with the user inputs
        """
        if not self._check_all_inputs({ReactorVariablesName.diameter: self.diameterEditLine,
                                       ReactorVariablesName.length: self.lengthEditLine,
                                       ReactorVariablesName.lengthStep: self.lengthStepEditLine,
                                       ReactorVariablesName.alfa: self.alfaEditLine,
                                       ReactorVariablesName.massFlowRate: self.massFlowRateEditLine,
                                       ReactorVariablesName.initialTemperature: self.initialTemperatureEditLine}):
            return {}

        input_dict = {ReactorVariablesName.udk: self.main_window.backend_frontend_manager.udk_file_path,
                      ReactorVariablesName.temperature: SimpleNamespace(
                          value=self.main_window.backend_frontend_manager.temperature["value"],
                          ud=self.main_window.ud_handler.from_human_to_code_ud(
                              self.main_window.backend_frontend_manager.temperature["ud"])),
                      ReactorVariablesName.pressure: SimpleNamespace(
                          value=self.main_window.backend_frontend_manager.pressure["value"],
                          ud=self.main_window.ud_handler.from_human_to_code_ud(
                              self.main_window.backend_frontend_manager.pressure["ud"])),
                      ReactorVariablesName.diameter: SimpleNamespace(
                          value=float(self.diameterEditLine.text()),
                          ud=self.main_window.ud_handler.from_human_to_code_ud(
                              self.diameterDropDown.currentText())),
                      ReactorVariablesName.alfa: SimpleNamespace(
                          value=float(self.alfaEditLine.text()),
                          ud=self.main_window.ud_handler.from_human_to_code_ud(
                              self.alfaDropDown.currentText())),
                      ReactorVariablesName.length: SimpleNamespace(
                          value=float(self.lengthEditLine.text()),
                          ud=self.main_window.ud_handler.from_human_to_code_ud(
                              self.lengthDropDown.currentText())),
                      ReactorVariablesName.lengthStep: SimpleNamespace(
                          value=float(self.lengthStepEditLine.text()),
                          ud=self.main_window.ud_handler.from_human_to_code_ud(
                              self.lengthStepDropDown.currentText())),
                      ReactorVariablesName.energy: self.energyDropDown.currentText().strip(),
                      ReactorVariablesName.diffusion: self.diffusionDropDown.currentText().strip(),
                      ReactorVariablesName.z: self._extract_coverage_input_composition(),
                      ReactorVariablesName.massFlowRate: SimpleNamespace(
                          value=float(self.massFlowRateEditLine.text()),
                          ud=self.main_window.ud_handler.from_human_to_code_ud(
                              self.massFlowRateDropDown.currentText())),
                      ReactorVariablesName.inertCoverage: self.inertCoverageEditLine.text().strip(),
                      ReactorVariablesName.inertSpecie: self.inertSpecieEditLine.text().strip(),
                      ReactorVariablesName.initialTemperature: SimpleNamespace(
                          value=float(self.initialTemperatureEditLine.text()),
                          ud=self.main_window.ud_handler.from_human_to_code_ud(
                              self.initialTemperatureDropDown.currentText())),
                      ReactorVariablesName.time: SimpleNamespace(
                          value=float(self.timeEditLine.text()),
                          ud=self.main_window.ud_handler.from_human_to_code_ud(
                              self.timeDropDown.currentText())),
                      ReactorVariablesName.timeStep: SimpleNamespace(
                          value=float(self.timeStepEditLine.text()),
                          ud=self.main_window.ud_handler.from_human_to_code_ud(
                              self.timeStepDropDown.currentText()))}

        if len(self.main_window.backend_frontend_manager.mole_fraction) > 0:
            input_dict.update({ReactorVariablesName.x: self.main_window.backend_frontend_manager.mole_fraction,
                               ReactorVariablesName.y: None})

        if len(self.main_window.backend_frontend_manager.mass_fraction) > 0:
            input_dict.update({ReactorVariablesName.x: None,
                               ReactorVariablesName.y: self.main_window.backend_frontend_manager.mass_fraction})

        if "mole" in self.compositionUdDropDown.currentText().lower():
            input_dict.update({ReactorVariablesName.initialX: self._extract_initial_species_composition(),
                               ReactorVariablesName.initialY: None})

        if "mass" in self.compositionUdDropDown.currentText().lower():
            input_dict.update({ReactorVariablesName.initialX: None,
                               ReactorVariablesName.initialY: self._extract_initial_species_composition()})
        return input_dict

    def _update_column_indexes(self) -> None:
        """
        Class to update the column indexes for the reactor window layout
        Returns
        -------

        """
        self._reactor_properties_col_idx = 0
        self._solving_options_col_idx = self._reactor_properties_col_idx + self._sub_grid_width
        self._coverage_col_idx = self._solving_options_col_idx + self._sub_grid_width
        self._initial_conditions_col_idx = self._coverage_col_idx + self._sub_grid_width

    def create_layout_components(self) -> None:
        """
        Initialize the widgets
        Returns
        -------
        """
        # Update column indexes
        self._update_column_indexes()

        # GUI labels
        self._create_options_labels()
        self._create_headline_label(self._select_reactor_list[4])

        # Reactor properties
        self._create_diameter_input_line()
        self._create_reactor_length_input_line()
        self._create_catalytic_load_input_line()
        self._create_mass_flow_rate_input_line()

        # Solving options
        self._create_udk_label()
        self._create_energy_balance_input_line()
        self._create_reactor_length_step_input_line()
        self._create_diffusion_input_line()
        self._create_inert_coverage_input_line()
        self._create_inert_specie_input_line()
        self._create_integration_time_input_line()
        self._create_time_step_input_line()

        # Initial conditions
        self._create_initial_temperature_input_line()
        self._create_composition_type_input_line()

    def generate_layout(self) -> None:
        """
        Update the interface
        Returns
        -------
        """
        self.row_idx = self.row_idx + 1
        self.addWidget(self.headlineLabel, self.row_idx, 0, 1, -1)

        # 1 row
        self.row_idx = self.row_idx + 1
        self._add_headlines(self.row_idx)

        # 2 row
        self.row_idx = self.row_idx + 1
        self._add_diameter_input_line(self.row_idx, self._reactor_properties_col_idx)
        self._add_udk_input_line(self.row_idx, self._solving_options_col_idx)
        self._add_input_composition_label_line(self.row_idx, self._coverage_col_idx)
        self._add_initial_temperature_input_line(self.row_idx, self._initial_conditions_col_idx)

        # 3 row
        self.row_idx = self.row_idx + 1
        self._add_reactor_length_input_line(self.row_idx, self._reactor_properties_col_idx)
        self._add_reactor_length_step_input_line(self.row_idx, self._solving_options_col_idx)
        self._coverage_row_idx = self.row_idx
        self._add_coverage_input_line()
        self._add_initial_composition_type_input_line(self.row_idx, self._initial_conditions_col_idx)

        # 4 row
        self.row_idx = self.row_idx + 1
        self._add_catalytic_load_input_line(self.row_idx, self._reactor_properties_col_idx)
        self._add_energy_balance_input_line(self.row_idx, self._solving_options_col_idx)
        self._add_input_composition_label_line(self.row_idx, self._initial_conditions_col_idx)

        # 5 row
        self.row_idx = self.row_idx + 1
        self._add_mass_flow_rate_input_line(self.row_idx, self._reactor_properties_col_idx)
        self._add_diffusion_input_line(self.row_idx, self._solving_options_col_idx)
        self._initial_species_row_idx = self.row_idx
        self._add_initial_species_input_line()

        # 6 row
        self.row_idx = self.row_idx + 1
        self._add_inert_specie_input_line(self.row_idx, self._solving_options_col_idx)

        # 7 row
        self.row_idx = self.row_idx + 1
        self._add_inert_coverage_input_line(self.row_idx, self._solving_options_col_idx)

        # 8 row
        self.row_idx = self.row_idx + 1
        self._add_integration_time_input_line(self.row_idx, self._solving_options_col_idx)

        # 9 row
        self.row_idx = self.row_idx + 1
        self._add_time_step_input_line(self.row_idx, self._solving_options_col_idx)

        # 10 row
        self.row_idx = self.row_idx + 1
        self._add_buttons(self.row_idx)
