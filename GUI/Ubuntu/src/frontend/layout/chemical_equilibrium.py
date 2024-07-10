from PyQt5.QtWidgets import (
    QMainWindow, QLabel
)

from src.frontend.layout.calculated_basic_layout import CalculatedBasicLayout
from src.frontend.utils import Utils


class ChemicalEquilibriumLayout(CalculatedBasicLayout):
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
        pass

    def runBackend(self):
        """
        Run backend to update frontend
        Returns
        -------

        """
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
        self.addWidget(self.temperatureUdDropDown, self.row_idx, 2)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Pressure:")), self.row_idx, 0)
        self.addWidget(self.pressureUdDropDown, self.row_idx, 2)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Mass fraction")), self.row_idx, 1)
        self.addWidget(QLabel(Utils.padString("Mole fraction")), self.row_idx, 2)
