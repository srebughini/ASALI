from PyQt5.QtWidgets import (
    QMainWindow
)

from src.backend.batch import BatchModel
from src.frontend.layout.reactors.basic_steady_state import BasicSteadyStateReactorLayout
from src.frontend.layout.plot_and_save import PlotAndSaveLayout
from src.frontend.style import ReactorVariablesName
from src.frontend.utils import Utils
from src.frontend.window.basic import BasicMainWindow
from types import SimpleNamespace


class BatchLayout(BasicSteadyStateReactorLayout):
    def __init__(self, main_window):
        """
        Batch reactor layout
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        super().__init__(main_window)

    def run_reactor_model(self) -> None:
        """
        Function to run the reactor model
        Returns
        -------

        """
        self._check_input_files()
        self._check_edit_line_float_input(self.volumeEditLine, ReactorVariablesName.volume.value)
        self._check_edit_line_float_input(self.alfaEditLine, ReactorVariablesName.alfa.value)
        self._check_edit_line_float_input(self.timeEditLine, ReactorVariablesName.time.value)
        self._check_edit_line_float_input(self.timeStepEditLine, ReactorVariablesName.timeStep.value)

        self.main_window.userInput.reactor_model_backend = BatchModel(self.main_window.userInput.file_path,
                                                                      self.main_window.userInput.gas_phase_name,
                                                                      self.main_window.userInput.surface_phase_name)

        input_dict = {ReactorVariablesName.udk: self.main_window.userInput.udk_file_path,
                      ReactorVariablesName.initialTemperature: SimpleNamespace(
                          value=self.main_window.userInput.temperature["value"],
                          ud=self.main_window.defaultInput.from_human_to_code_ud(
                              self.main_window.userInput.temperature["ud"])),
                      ReactorVariablesName.pressure: SimpleNamespace(
                          value=self.main_window.userInput.pressure["value"],
                          ud=self.main_window.defaultInput.from_human_to_code_ud(
                              self.main_window.userInput.pressure["ud"])),
                      ReactorVariablesName.volume: SimpleNamespace(
                          value=float(self.volumeEditLine.text()),
                          ud=self.main_window.defaultInput.from_human_to_code_ud(
                              self.volumeDropDown.currentText())),
                      ReactorVariablesName.alfa: SimpleNamespace(
                          value=float(self.alfaEditLine.text()),
                          ud=self.main_window.defaultInput.from_human_to_code_ud(
                              self.alfaDropDown.currentText())),
                      ReactorVariablesName.time: SimpleNamespace(
                          value=float(self.timeEditLine.text()),
                          ud=self.main_window.defaultInput.from_human_to_code_ud(
                              self.timeDropDown.currentText())),
                      ReactorVariablesName.timeStep: SimpleNamespace(
                          value=float(self.timeStepEditLine.text()),
                          ud=self.main_window.defaultInput.from_human_to_code_ud(
                              self.timeStepDropDown.currentText())),
                      ReactorVariablesName.energy: self.energyDropDown.currentText().strip(),
                      ReactorVariablesName.z: self._extract_coverage_input_composition()}

        if len(self.main_window.userInput.mole_fraction) > 0:
            input_dict.update({ReactorVariablesName.initialX: self.main_window.userInput.mole_fraction,
                               ReactorVariablesName.initialY: None})

        if len(self.main_window.userInput.mass_fraction) > 0:
            input_dict.update({ReactorVariablesName.initialX: None,
                               ReactorVariablesName.initialY: self.main_window.userInput.mass_fraction})

        self.main_window.userInput.reactor_model_backend.run(input_dict)

        Utils.open_new_window_from_layout(self.main_window, BasicMainWindow, PlotAndSaveLayout)

    def create_layout_components(self) -> None:
        """
        Initialize the widgets
        Returns
        -------
        """
        # GUI labels
        self._create_options_labels()
        self._create_headline_label(self._select_reactor_list[1])

        # Reactor properties
        self._create_volume_input_line()
        self._create_catalytic_load_input_line()

        # Solving options
        self._create_udk_label()
        self._create_energy_balance_input_line()
        self._create_integration_time_input_line()
        self._create_time_step_input_line()

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
        self._add_volume_input_line(self.row_idx, self._reactor_properties_col_idx)
        self._add_udk_input_line(self.row_idx, self._solving_options_col_idx)
        self._add_input_composition_label_line(self.row_idx, self._coverage_col_idx)

        # 3 row
        self.row_idx = self.row_idx + 1
        self._add_catalytic_load_input_line(self.row_idx, self._reactor_properties_col_idx)
        self._add_energy_balance_input_line(self.row_idx, self._solving_options_col_idx)
        self._coverage_row_idx = self.row_idx
        self._add_coverage_input_line()

        # 4 row
        self.row_idx = self.row_idx + 1
        self._add_integration_time_input_line(self.row_idx, self._solving_options_col_idx)

        # 5 row
        self.row_idx = self.row_idx + 1
        self._add_time_step_input_line(self.row_idx, self._solving_options_col_idx)

        # 6 row
        self.row_idx = self.row_idx + 1
        self._add_buttons(self.row_idx)
