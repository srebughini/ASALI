from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import (
    QMainWindow, QLabel, QLineEdit
)
from src.frontend.layout.basic import BasicLayout
from src.frontend.utils import Utils


class CalculationMenuLayout(BasicLayout):
    def __init__(self, main_window):
        """
        Calculation menu layout
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        self._select_calculation_option_list = [Utils.padString("...Calculation to be performed..."),
                                                Utils.padString("Thermodynamic and transport properties"),
                                                Utils.padString("Vacuum properties"),
                                                Utils.padString("Chemical equilibrium"),
                                                Utils.padString("Reactor modeling")]

        super().__init__(main_window)

    def _loadSelectCalculationMenu(self):
        pass

    def initialize(self):
        """
        Initialize the widgets
        Returns
        -------

        """
        self.nextButton = self._createButton('Next',
                                             self._loadSelectCalculationMenu,
                                             'Go to next step')

        self.backButton = self._createButton('Back',
                                             self.main_window.updateToMainMenuLayout,
                                             'Go back to main menu')

        self.selectCalculationDropDown = self._createDropdown(self._select_calculation_option_list,
                                                              function=None)

        self.temperatureUdDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.defaultInput.temperatureUd],
            function=None)

        self.temperatureLine = self._createLineEdit(QDoubleValidator())

        self.pressureUdDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.defaultInput.pressureUd],
            function=None)

        self.pressureLine = self._createLineEdit(QDoubleValidator())

        self.compositionUdDropDown = self._createDropdown(self.defaultInput.compositionUd, function=None)

    def create(self):
        """
        Update the interface
        Returns
        -------
        """
        self.row_idx = self.row_idx + 1
        self.addWidget(self.selectCalculationDropDown, self.row_idx, 0, 1, -1)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Temperature:")), self.row_idx, 0)
        self.addWidget(self.temperatureLine, self.row_idx, 1)
        self.addWidget(self.temperatureUdDropDown, self.row_idx, 2)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Pressure:")), self.row_idx, 0)
        self.addWidget(self.pressureLine, self.row_idx, 1)
        self.addWidget(self.pressureUdDropDown, self.row_idx, 2)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Composition:")), self.row_idx, 0)
        self.addWidget(self.compositionUdDropDown, self.row_idx, 1, 1, -1)

        self.row_idx = self.row_idx + 1
        self.addWidget(self.backButton, self.row_idx, 0)
        self.addWidget(self.nextButton, self.row_idx, 2)
