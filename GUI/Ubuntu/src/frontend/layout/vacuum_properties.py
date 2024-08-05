from PyQt5.QtCore import Qt
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import (
    QMainWindow, QLabel
)

from src.backend.vacuum_properties import VacuumProperties
from src.frontend.layout.calculation_basic_layout import CalculationBasicLayout
from src.frontend.style import WidgetStyle
from src.frontend.utils import Utils


class VacuumPropertiesLayout(CalculationBasicLayout):
    def __init__(self, main_window):
        """
        Transport and thermodynamic properties
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        self._empty_label = Utils.padString("")
        super().__init__(main_window)

    def _updateProperties(self):
        """
        Update estimated properties
        Returns
        -------
        """
        geometryValue = 0.0
        if Utils.isFloat(self.geometryEditLine.text()):
            geometryValue = float(self.geometryEditLine.text())

        v = self.cl.mean_gas_velocity(self.speciesDropDown.currentText(), self.vDropDown.currentText())
        l = self.cl.mean_free_path(self.speciesDropDown.currentText(), self.lDropDown.currentText())
        kn = self.cl.knudsen_number(self.speciesDropDown.currentText(),
                                    geometryValue,
                                    self.geometryDropDown.currentText())
        diff = self.cl.diffusivity(self.speciesDropDown.currentText(),
                                   self.diffDropDown.currentText(),
                                   geometryValue,
                                   self.geometryDropDown.currentText())

        self.vLabel.setText(Utils.padString(Utils.fromNumberToString(v)))
        self.lLabel.setText(Utils.padString(Utils.fromNumberToString(l)))
        self.knLabel.setText(Utils.padString(Utils.fromNumberToString(kn)))
        self.diffLabel.setText(Utils.padString(Utils.fromNumberToString(diff)))

    def runBackend(self):
        """
        Run backend to update frontend
        Returns
        -------

        """

        self.cl = self._setGasMixtureUserInput(VacuumProperties(self.main_window.userInput.file_path,
                                                                self.main_window.userInput.gas_phase_name))

        self.speciesDropDown.addItems(self.cl.species_names())
        self._updateProperties()

    def initialize(self):
        """
        Initialize the widgets
        Returns
        -------
        """
        # Titles label
        self.inputLabel = QLabel("Input parameters of vacuum conditions")
        self.inputLabel.setStyleSheet(WidgetStyle.HIGHLIGHTLABEL.value)
        self.inputLabel.setAlignment(Qt.AlignCenter)

        self.resultLabel = QLabel("Vacuum properties")
        self.resultLabel.setStyleSheet(WidgetStyle.HIGHLIGHTLABEL.value)
        self.resultLabel.setAlignment(Qt.AlignCenter)

        # Length
        self.geometryDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.lengthUd],
            function=self._updateProperties)
        self.geometryEditLine = self._createLineEdit("0.5",
                                                     Qt.AlignRight,
                                                     QDoubleValidator(),
                                                     f=self._updateProperties)

        # Species
        self.speciesDropDown = self._createDropdown(list(), function=self._updateProperties)

        # Mean gas velocity
        self.vDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.velocityUd],
            function=self._updateProperties)
        self.vLabel = QLabel(self._empty_label)

        # Mean free path
        self.lDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.lengthUd],
            function=self._updateProperties)
        self.lLabel = QLabel(self._empty_label)

        # Knudsen number
        self.knLabel = QLabel(self._empty_label)

        # Diffusivity
        self.diffDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.diffusivityUd],
            function=self._updateProperties)
        self.diffLabel = QLabel(self._empty_label)

    def create(self):
        """
        Update the interface
        Returns
        -------
        """
        self.row_idx = self.row_idx + 1
        self.addWidget(self.inputLabel, self.row_idx, 0, 1, -1)

        # Geometry
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Geometry characteristic length:")), self.row_idx, 0)
        self.addWidget(self.geometryEditLine, self.row_idx, 1)
        self.addWidget(self.geometryDropDown, self.row_idx, 2)

        # Species
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Select specie:")), self.row_idx, 0)
        self.addWidget(self.speciesDropDown, self.row_idx, 1, 1, -1)

        self.row_idx = self.row_idx + 1
        self.addWidget(self.resultLabel, self.row_idx, 0, 1, -1)

        # Mean gas velocity
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Mean gas velocity")), self.row_idx, 0)
        self.addWidget(self.vLabel, self.row_idx, 1)
        self.addWidget(self.vDropDown, self.row_idx, 2)

        # Mean free path
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Mean free path")), self.row_idx, 0)
        self.addWidget(self.lLabel, self.row_idx, 1)
        self.addWidget(self.lDropDown, self.row_idx, 2)

        # Mixture diffusivity
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Diffusivity")), self.row_idx, 0)
        self.addWidget(self.diffLabel, self.row_idx, 1)
        self.addWidget(self.diffDropDown, self.row_idx, 2)

        # Mixture diffusivity
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Knudsen number")), self.row_idx, 0)
        self.addWidget(self.knLabel, self.row_idx, 1)
