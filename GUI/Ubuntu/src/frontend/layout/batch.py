from PyQt5.QtCore import Qt
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import (
    QMainWindow, QLabel
)

from src.backend.batch import BatchModel
from src.frontend.layout.basic_reactor import BasicReactorLayout
from src.frontend.style import WidgetStyle
from src.frontend.utils import Utils


class BatchLayout(BasicReactorLayout):
    def __init__(self, main_window):
        """
        Batch reactor layout
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        super().__init__(main_window)

    def _checkEditLineFloatInput(self, editLine, variableName):
        """
        Check single edit line input
        Parameters
        ----------
        editLine: QLineEdit
            Edit line object
        variableName: str
            Variable name

        Returns
        -------
        """
        if not Utils.isFloat(editLine.text()):
            Utils.errorMessage(self.main_window,
                               self.title,
                               QLabel(f"Wrong {variableName} value."))

    def _checkEditLineInputs(self):
        """
        Check all the input in edit line format
        Returns
        -------

        """
        self._checkEditLineFloatInput(self.vEditLine, "volume")
        self._checkEditLineFloatInput(self.alfaEditLine, "catalytic load")
        self._checkEditLineFloatInput(self.tEditLine, "integration time")
        self._checkEditLineFloatInput(self.tsEditLine, "time step")

    def _runModel(self):
        """
        Function to run the reactor model
        Returns
        -------

        """
        self._checkInputFiles()
        self._checkEditLineInputs()

        b = BatchModel(self.main_window.userInput.file_path,
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
                      "energy": self.energyDropDown.currentText().strip()}

        if len(self.main_window.userInput.mole_fraction) > 0:
            input_dict.update({"x": self.main_window.userInput.mole_fraction,
                               "y": None})

        if len(self.main_window.userInput.mass_fraction) > 0:
            input_dict.update({"x": None,
                               "y": self.main_window.userInput.mass_fraction})

        b.run(input_dict)

    def initialize(self):
        """
        Initialize the widgets
        Returns
        -------
        """
        self._createReactorSelectionDropDown()
        self._createRunButton()

        # Headline
        self.headlineLabel = QLabel(self._select_reactor_list[1])
        self.headlineLabel.setStyleSheet(WidgetStyle.HIGHLIGHTLABEL.value)
        self.headlineLabel.setAlignment(Qt.AlignCenter)

        # Volume
        self.vDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.volumeUd])
        self.vEditLine = self._createLineEdit("10.0", Qt.AlignRight, QDoubleValidator())

        # Catalytic load
        self.alfaDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.oneOverLengthUd])
        self.alfaEditLine = self._createLineEdit("15.0", Qt.AlignRight, QDoubleValidator())

        # Energy
        self.energyDropDown = self._createDropdown(self._on_off_list)

        # Time
        self.tDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.timeUd])
        self.tEditLine = self._createLineEdit("5", Qt.AlignRight, QDoubleValidator())

        # Time step
        self.tsDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.timeUd])
        self.tsEditLine = self._createLineEdit("0.5", Qt.AlignRight, QDoubleValidator())

    def create(self):
        """
        Update the interface
        Returns
        -------
        """
        self.row_idx = self.row_idx + 1
        self.addWidget(self.reactorDropDown, self.row_idx, 0, 1, -1)

        self.row_idx = self.row_idx + 1
        self.addWidget(self.headlineLabel, self.row_idx, 0, 1, -1)

        # Volume
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Volume:")), self.row_idx, 0)
        self.addWidget(self.vEditLine, self.row_idx, 1)
        self.addWidget(self.vDropDown, self.row_idx, 2)

        # Catalytic load
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Catalytic load:")), self.row_idx, 0)
        self.addWidget(self.alfaEditLine, self.row_idx, 1)
        self.addWidget(self.alfaDropDown, self.row_idx, 2)

        # Energy
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Energy balance:")), self.row_idx, 0)
        self.addWidget(self.energyDropDown, self.row_idx, 1, 1, -1)

        # Time
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Integration time:")), self.row_idx, 0)
        self.addWidget(self.tEditLine, self.row_idx, 1)
        self.addWidget(self.tDropDown, self.row_idx, 2)

        # Time step
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Integration time step:")), self.row_idx, 0)
        self.addWidget(self.tsEditLine, self.row_idx, 1)
        self.addWidget(self.tsDropDown, self.row_idx, 2)

        # Run
        self.row_idx = self.row_idx + 1
        self.addWidget(self.runButton, self.row_idx, 0, 1, -1)
