from types import SimpleNamespace

from PyQt5.QtWidgets import QMainWindow

from src.backend.reactors.runners import run_steady_state_heterogeneous_reactor_model
from src.frontend.layout.reactors.basic_steady_state import BasicSteadyStateReactorLayout
from src.frontend.utils import ReactorVariablesName


class SteadyStateHeterogeneous1DReactorLayout(BasicSteadyStateReactorLayout):
    def __init__(self, main_window):
        """
        Steady state 1D heterogeneous reactor layout
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        super().__init__(main_window)
        self.reactor_model_function = run_steady_state_heterogeneous_reactor_model

    def read_input(self) -> dict:
        """
        Function to read user input
        Returns
        -------
        input_dict: dict
            User input
        """

        """
        if not self._check_all_inputs({ReactorVariablesName.diameter: self.diameterEditLine,
                                       ReactorVariablesName.length: self.lengthEditLine,
                                       ReactorVariablesName.lengthStep: self.lengthStepEditLine,
                                       ReactorVariablesName.alfa: self.alfaEditLine,
                                       ReactorVariablesName.massFlowRate: self.massFlowRateEditLine}):
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
                      ReactorVariablesName.inertSpecie: self.inertSpecieEditLine.text().strip()}

        if len(self.main_window.backend_frontend_manager.mole_fraction) > 0:
            input_dict.update({ReactorVariablesName.x: self.main_window.backend_frontend_manager.mole_fraction,
                               ReactorVariablesName.y: None})

        if len(self.main_window.backend_frontend_manager.mass_fraction) > 0:
            input_dict.update({ReactorVariablesName.x: None,
                               ReactorVariablesName.y: self.main_window.backend_frontend_manager.mass_fraction})

        return input_dict
        """
        return {}

    def _update_column_indexes(self) -> None:
        """
        Class to update the column indexes for the reactor window layout
        Returns
        -------

        """
        self._reactor_properties_col_idx = 0
        self._solving_options_col_idx = self._reactor_properties_col_idx + self._sub_grid_width
        self._coverage_col_idx = self._solving_options_col_idx + self._sub_grid_width
        self._solid_properties_col_idx = self._coverage_col_idx + self._sub_grid_width

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
        self._create_headline_label(self._select_reactor_list[5])

        # Reactor properties
        self._create_reactor_length_input_line()
        self._create_catalytic_load_input_line()
        self._create_mass_flow_rate_input_line()
        self._create_diameter_input_line()
        self._create_particle_diameter_input_line()
        self._create_wall_thickness_input_line()
        self._create_void_fraction_input_line()
        self._create_cpsi_input_line()
        self._create_reactor_type_dropdown()

        # Solving options
        self._create_udk_label()
        self._create_energy_balance_input_line()
        self._create_reactor_length_step_input_line()
        self._create_diffusion_input_line()
        self._create_inert_coverage_input_line()
        self._create_inert_specie_input_line()

        # Solid properties

    def generate_layout(self) -> None:
        """
        Update the interface
        Returns
        -------
        """
        # TODO - Add solid options column

        self.row_idx = self.row_idx + 1
        self.addWidget(self.headlineLabel, self.row_idx, 0, 1, -1)

        # 1 row
        self.row_idx = self.row_idx + 1
        self._add_headlines(self.row_idx)

        # 2 row
        self.row_idx = self.row_idx + 1
        self._add_reactor_length_input_line(self.row_idx, self._reactor_properties_col_idx)
        self._add_udk_input_line(self.row_idx, self._solving_options_col_idx)
        self._add_input_composition_label_line(self.row_idx, self._coverage_col_idx)

        # 3 row
        self.row_idx = self.row_idx + 1
        self._add_catalytic_load_input_line(self.row_idx, self._reactor_properties_col_idx)
        self._add_reactor_length_step_input_line(self.row_idx, self._solving_options_col_idx)
        self._coverage_row_idx = self.row_idx
        self._add_coverage_input_line()

        # 4 row
        self.row_idx = self.row_idx + 1
        self._add_mass_flow_rate_input_line(self.row_idx, self._reactor_properties_col_idx)
        self._add_energy_balance_input_line(self.row_idx, self._solving_options_col_idx)

        # 5 row
        self.row_idx = self.row_idx + 1
        self._add_reactor_type_dropdown(self.row_idx, self._reactor_properties_col_idx)
        self._add_diffusion_input_line(self.row_idx, self._solving_options_col_idx)

        # 6 row
        self.row_idx = self.row_idx + 1
        self._reactor_type_first_row_idx = self.row_idx
        self._add_reactor_type_input_lines()
        self._add_inert_specie_input_line(self.row_idx, self._solving_options_col_idx)

        # 7 row
        self.row_idx = self.row_idx + 1
        self._add_inert_coverage_input_line(self.row_idx, self._solving_options_col_idx)

        # Add reactor types
        self.row_idx = max(self.row_idx, self._reactor_type_final_row_idx)

        # 8 row
        self.row_idx = self.row_idx + 1
        self._add_buttons(self.row_idx)
