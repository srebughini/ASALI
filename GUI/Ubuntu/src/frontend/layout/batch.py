from PyQt5.QtCore import Qt
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import (
    QMainWindow, QLabel
)

from src.backend.batch import BatchModel
from src.frontend.layout.basic_reactor import BasicReactorLayout
from src.frontend.layout.plot_and_save import PlotAndSaveLayout
from src.frontend.style import WidgetStyle
from src.frontend.utils import Utils
from src.frontend.window.basic import BasicMainWindow
from src.frontend.window._plot_and_save import PlotAndSaveWindow


class BatchLayout(BasicReactorLayout):
    def __init__(self, main_window):
        """
        Batch reactor layout
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        self.headlineLabel = None
        self.vDropDown = None
        self.vEditLine = None
        self.alfaDropDown = None
        self.alfaEditLine = None
        self.energyDropDown = None
        self.tDropDown = None
        self.tEditLine = None
        self.tsDropDown = None
        self.tsEditLine = None

        super().__init__(main_window)

    def _check_edit_line_inputs(self) -> None:
        """
        Check all the input in edit line format
        Returns
        -------

        """
        self._check_edit_line_float_input(self.vEditLine, "volume")
        self._check_edit_line_float_input(self.alfaEditLine, "catalytic load")
        self._check_edit_line_float_input(self.tEditLine, "integration time")
        self._check_edit_line_float_input(self.tsEditLine, "time step")

    def run_reactor_model(self) -> None:
        """
        Function to run the reactor model
        Returns
        -------

        """
        self._check_input_files()
        self._check_edit_line_inputs()

        self.main_window.userInput.reactor_model_backend = BatchModel(self.main_window.userInput.file_path,
                                                                      self.main_window.userInput.gas_phase_name,
                                                                      self.main_window.userInput.surface_phase_name)

        input_dict = {"udk": self.main_window.userInput.udk_file_path,
                      "T": {"value": self.main_window.userInput.temperature["value"],
                            "ud": self.main_window.defaultInput.from_human_to_code_ud(
                                self.main_window.userInput.temperature["ud"])},
                      "P": {"value": self.main_window.userInput.pressure["value"],
                            "ud": self.main_window.defaultInput.from_human_to_code_ud(
                                self.main_window.userInput.pressure["ud"])},
                      "V": {"value": float(self.vEditLine.text()),
                            "ud": self.main_window.defaultInput.from_human_to_code_ud(self.vDropDown.currentText())},
                      "alfa": {"value": float(self.alfaEditLine.text()),
                               "ud": self.main_window.defaultInput.from_human_to_code_ud(
                                   self.alfaDropDown.currentText())},
                      "time": {"value": float(self.tEditLine.text()),
                               "ud": self.main_window.defaultInput.from_human_to_code_ud(
                                   self.tDropDown.currentText())},
                      "step": {"value": float(self.tsEditLine.text()),
                               "ud": self.main_window.defaultInput.from_human_to_code_ud(
                                   self.tsDropDown.currentText())},
                      "energy": self.energyDropDown.currentText().strip(),
                      "z": self._extract_coverage_input_composition()}

        if len(self.main_window.userInput.mole_fraction) > 0:
            input_dict.update({"x": self.main_window.userInput.mole_fraction,
                               "y": None})

        if len(self.main_window.userInput.mass_fraction) > 0:
            input_dict.update({"x": None,
                               "y": self.main_window.userInput.mass_fraction})

        self.main_window.userInput.reactor_model_backend.run(input_dict)

        Utils.open_new_window_from_layout(self.main_window, BasicMainWindow, PlotAndSaveLayout)

    def initialize(self) -> None:
        """
        Initialize the widgets
        Returns
        -------
        """
        self._create_udk_label()

        # Headline
        self.headlineLabel = QLabel(self._select_reactor_list[1])
        self.headlineLabel.setStyleSheet(WidgetStyle.HIGHLIGHTLABEL.value)
        self.headlineLabel.setAlignment(Qt.AlignCenter)

        # Volume
        self.vDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.defaultInput.volume_ud])
        self.vEditLine = self._create_line_edit("10.0", Qt.AlignRight, QDoubleValidator())

        # Catalytic load
        self.alfaDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.defaultInput.one_over_length_ud])
        self.alfaEditLine = self._create_line_edit("15.0", Qt.AlignRight, QDoubleValidator())

        # Energy
        self.energyDropDown = self._create_dropdown(self._on_off_list)

        # Time
        self.tDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.defaultInput.time_ud])
        self.tEditLine = self._create_line_edit("5", Qt.AlignRight, QDoubleValidator())

        # Time step
        self.tsDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.defaultInput.time_ud])
        self.tsEditLine = self._create_line_edit("0.5", Qt.AlignRight, QDoubleValidator())

    def create(self) -> None:
        """
        Update the interface
        Returns
        -------
        """
        self.row_idx = self.row_idx + 1
        self.addWidget(self.headlineLabel, self.row_idx, 0, 1, -1)

        self.row_idx = self.row_idx + 1
        self._add_udk(self.row_idx)

        # Volume
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Volume:")), self.row_idx, 0)
        self.addWidget(self.vEditLine, self.row_idx, 1)
        self.addWidget(self.vDropDown, self.row_idx, 2)

        # Catalytic load
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Catalytic load:")), self.row_idx, 0)
        self.addWidget(self.alfaEditLine, self.row_idx, 1)
        self.addWidget(self.alfaDropDown, self.row_idx, 2)

        # Energy
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Energy balance:")), self.row_idx, 0)
        self.addWidget(self.energyDropDown, self.row_idx, 1, 1, -1)

        # Time
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Integration time:")), self.row_idx, 0)
        self.addWidget(self.tEditLine, self.row_idx, 1)
        self.addWidget(self.tDropDown, self.row_idx, 2)

        # Time step
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Integration time step:")), self.row_idx, 0)
        self.addWidget(self.tsEditLine, self.row_idx, 1)
        self.addWidget(self.tsDropDown, self.row_idx, 2)

        # Coverage composition
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Chemical formula")), self.row_idx, 1)
        self.addWidget(QLabel(Utils.pad_string("Composition")), self.row_idx, 2)

        self.row_idx = self.row_idx + 1
        self._add_coverage_input_line(self.row_idx)

        # Run
        self.row_idx = self.row_idx + 1
        self._add_buttons(self.row_idx)
