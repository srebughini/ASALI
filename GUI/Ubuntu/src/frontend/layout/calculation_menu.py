from PyQt5.QtCore import Qt
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

        self._n_input_specie = 0

        super().__init__(main_window)

    def _loadSelectedCalculationMenu(self):
        """
        Load select calculation Menu
        Returns
        -------

        """
        if self.makeChemistryDropDown.currentIndex() == 0:
            Utils.errorMessage(self.main_window,
                               self.title,
                               QLabel("Please, select the calculation method!"))
        elif self.makeChemistryDropDown.currentIndex() == 1:
            #Utils.openNewWindow(self.main_window, ThermodynamicAndTransportWindow)
            pass
        elif self.makeChemistryDropDown.currentIndex() == 2:
            #Utils.openNewWindow(self.main_window, VacuumWindow)
            pass
        elif self.makeChemistryDropDown.currentIndex() == 3:
            #Utils.openNewWindow(self.main_window, ChemicalEquilibriumWindow)
            pass
        elif self.makeChemistryDropDown.currentIndex() == 4:
            #Utils.openNewWindow(self.main_window, ReactorWindow)
            pass

    def _addButtons(self, row_idx):
        """
        Add Next, Back and Add Species buttons
        Parameters
        ----------
        row_idx: int
            Row index where to add the buttons
        Returns
        -------

        """
        self.row_idx = self.row_idx + 1
        self.addWidget(self._createButton(self.backButtonText,
                                          self.main_window.updateToMainMenuLayout,
                                          self.backButtonToolTip), row_idx, 0)
        self.addWidget(self._createButton(Utils.padStringCenter('Add specie'),
                                          self._updateLayoutWithSpecieLine,
                                          'Add input species'), row_idx, 1)
        self.addWidget(self._createButton(self.nextButtonText,
                                          self._loadSelectedCalculationMenu,
                                          self.nextButtonToolTip), row_idx, 2)

    def _removeButtons(self):
        """
        Remove Next, Back and Species buttons
        Returns
        -------

        """
        n_widget = self.count()
        self.itemAt(n_widget - 1).widget().setParent(None)
        self.itemAt(n_widget - 2).widget().setParent(None)
        self.itemAt(n_widget - 3).widget().setParent(None)

    def _addSpeciesInputLine(self, row_idx):
        """
        Add input species line
        Parameters
        ----------
        row_idx: int
            Row index where to add the input line

        Returns
        -------

        """
        self._n_input_specie = self._n_input_specie + 1
        self.addWidget(QLabel(Utils.padString(f"Specie #{self._n_input_specie}")), row_idx, 0)
        self.addWidget(self._createLineEdit("H2", Qt.AlignRight, None), row_idx, 1)
        self.addWidget(self._createLineEdit("0.5", Qt.AlignRight, QDoubleValidator()), row_idx, 2)

    def _updateLayoutWithSpecieLine(self):
        """
        Update the layout by adding specie input line
        Returns
        -------

        """
        self._removeButtons()
        self._addSpeciesInputLine(self.row_idx)
        self.row_idx = self.row_idx + 1
        self._addButtons(self.row_idx)

    def initialize(self):
        """
        Initialize the widgets
        Returns
        -------

        """
        self.selectCalculationDropDown = self._createDropdown(self._select_calculation_option_list,
                                                              function=None)

        self.temperatureUdDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.defaultInput.temperatureUd],
            function=None)

        self.temperatureLine = self._createLineEdit("25", Qt.AlignRight, QDoubleValidator())

        self.pressureUdDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.defaultInput.pressureUd],
            function=None)

        self.pressureLine = self._createLineEdit("101325", Qt.AlignRight, QDoubleValidator())

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
        self.addWidget(QLabel(Utils.padString("Composition type:")), self.row_idx, 0)
        self.addWidget(self.compositionUdDropDown, self.row_idx, 1, 1, -1)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Chemical formula")), self.row_idx, 1)
        self.addWidget(QLabel(Utils.padString("Composition")), self.row_idx, 2)

        self.row_idx = self.row_idx + 1
        self._addSpeciesInputLine(self.row_idx)

        self.row_idx = self.row_idx + 1
        self._addButtons(self.row_idx)
