from PyQt5.QtWidgets import (
    QMainWindow, QLabel
)

from src.backend.chemical_equilibrium import ChemicalEquilibrium
from src.frontend.layout.calculation_basic_layout import CalculationBasicLayout
from src.frontend.utils import Utils


class ChemicalEquilibriumLayout(CalculationBasicLayout):
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
        self.cl.equilibrate(self.main_window.defaultInput.from_human_eq_to_code_eq(self.eqDropDown.currentText()))

        T = self.cl.temperature(self.temperatureUdDropDown.currentText())
        P = self.cl.pressure(self.pressureUdDropDown.currentText())
        x = list(self.cl.mole_fraction().values())
        y = list(self.cl.mass_fraction().values())
        n = self.cl.species_names()

        self.temperatureLabel.setText(Utils.padString(Utils.fromNumberToString(T)))
        self.pressureLabel.setText(Utils.padString(Utils.fromNumberToString(P)))
        self.nLabel.setText("\n".join(n))
        self.xLabel.setText(Utils.fromListToString(x))
        self.yLabel.setText(Utils.fromListToString(y))

    def runBackend(self):
        """
        Run backend to update frontend
        Returns
        -------

        """
        self.cl = self._setGasMixtureUserInput(ChemicalEquilibrium(self.main_window.userInput.file_path,
                                                                   self.main_window.userInput.gas_phase_name))
        self._updateProperties()

    def initialize(self):
        """
        Initialize the widgets
        Returns
        -------

        """
        self.eqDropDown = self._createDropdown(
            [Utils.padString(op) for op in self.main_window.defaultInput.humanChemicalEquilibriumOptions],
            function=self._updateProperties)

        self.temperatureUdDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.temperatureUd],
            function=None)

        self.pressureUdDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.pressureUd],
            function=None)

        self.temperatureLabel = QLabel(self._empty_label)
        self.pressureLabel = QLabel(self._empty_label)
        self.xLabel = QLabel(self._empty_label)
        self.yLabel = QLabel(self._empty_label)
        self.nLabel = QLabel(self._empty_label)

    def create(self):
        """
        Update the interface
        Returns
        -------
        """
        self.row_idx = self.row_idx + 1
        self.addWidget(self.eqDropDown, self.row_idx, 0, 1, -1)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Temperature:")), self.row_idx, 0)
        self.addWidget(self.temperatureLabel, self.row_idx, 1)
        self.addWidget(self.temperatureUdDropDown, self.row_idx, 2)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Pressure:")), self.row_idx, 0)
        self.addWidget(self.pressureLabel, self.row_idx, 1)
        self.addWidget(self.pressureUdDropDown, self.row_idx, 2)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Mass fraction")), self.row_idx, 1)
        self.addWidget(QLabel(Utils.padString("Mole fraction")), self.row_idx, 2)

        self.row_idx = self.row_idx + 1
        self.addWidget(self.nLabel, self.row_idx, 0)
        self.addWidget(self.yLabel, self.row_idx, 1)
        self.addWidget(self.xLabel, self.row_idx, 2)
