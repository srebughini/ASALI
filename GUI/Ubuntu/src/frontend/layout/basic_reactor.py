from PyQt5.QtCore import Qt
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import (
    QMainWindow, QLabel
)

from src.frontend.layout.basic import BasicLayout
from src.frontend.style import FileType, WidgetStyle
from src.frontend.utils import Utils

import numpy as np

class BasicReactorLayout(BasicLayout):
    def __init__(self, main_window):
        """
        Reactor selection layout
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        self._empty_label = Utils.padString("")

        self._select_reactor_list = [
            Utils.padString("...Select reactor model..."),
            Utils.padString("Batch reactor"),  # 1
            Utils.padString("Continuous stirred tank reactor"),  # 2
            Utils.padString("Steady state 1D pseudo-homogeneous reactor"),  # 3
            Utils.padString("Transient 1D pseudo-homogeneous reactor"),  # 4
            Utils.padString("Steady state 1D heterogeneous reactor"),  # 5
            Utils.padString("Transient 1D heterogeneous reactor")]  # 6

        self._on_off_list = [Utils.padString("ON"), Utils.padString("OFF")]

        self.runButtonText = Utils.padStringCenter("Run model")
        self.runButtonToolTip = "Run reactor model"

        self.udkButtonText = Utils.padStringCenter("Load")
        self.udkButtonToolTip = "Load ASALI kinetic model"

        self._coverage_names_idx = list()
        self._coverage_composition_idx = list()

        super().__init__(main_window)

    def _updateLayout(self):
        """
        Update layout based on reactor selection
        Returns
        -------

        """
        if self.reactorDropDown.currentIndex() == 0:
            self.main_window.updateToBasic()
        elif self.reactorDropDown.currentIndex() == 1:
            self.main_window.updateToBatchReactor()
        elif self.reactorDropDown.currentIndex() == 2:
            self.main_window.updateToCstrReactor()
        elif self.reactorDropDown.currentIndex() == 3:
            pass
            # self.main_window.updateToSteadyPh1dReactor()
        elif self.reactorDropDown.currentIndex() == 4:
            pass
            # self.main_window.updateToTransientPh1dReactor()
        elif self.reactorDropDown.currentIndex() == 5:
            pass
            # self.main_window.updateToSteadyHet1dReactor()
        elif self.reactorDropDown.currentIndex() == 6:
            pass
            # self.main_window.updateToTransientHet1dReactor()

    def _updateLayoutWithCoverageLine(self):
        """
        Update the layout by adding specie input line
        Returns
        -------

        """
        self._removeButtons()
        self._addCoverageInputLine(self.row_idx)
        self.row_idx = self.row_idx + 1
        self._addButtons(self.row_idx)

    def _createReactorSelectionDropDown(self):
        """
        Create reactor selection drop down menu
        Returns
        -------

        """
        self.reactorDropDown = self._createDropdown(self._select_reactor_list,
                                                    function=self._updateLayout)

    def _createUdkLabel(self):
        """
        Create user defined kinetic label
        Returns
        -------

        """
        self.udkLoadLabel = QLabel(Utils.padString("Not loaded"))
        self.udkLoadLabel.setStyleSheet(WidgetStyle.HIGHLIGHTLABEL.value)
        self.udkLoadLabel.setAlignment(Qt.AlignCenter)

    def _addCoverageInputLine(self, row_idx):
        """
        Add input coverage line
        Parameters
        ----------
        row_idx: int
            Row index where to add the input line

        Returns
        -------

        """
        self.addWidget(QLabel(Utils.padString(f"Coverage #{len(self._coverage_names_idx) + 1}")), row_idx, 0)
        self.addWidget(self._createLineEdit("Rh(s)", Qt.AlignRight, None), row_idx, 1)
        self._coverage_names_idx.append(self.count() - 1)
        self.addWidget(self._createLineEdit("1", Qt.AlignRight, QDoubleValidator()), row_idx, 2)
        self._coverage_composition_idx.append(self.count() - 1)

    def _addButtons(self, row_idx):
        """
        Add Back, Add Species and Run model buttons
        Parameters
        ----------
        row_idx: int
            Row index where to add the buttons
        Returns
        -------

        """
        self.addWidget(self._createButton(self.backButtonText,
                                          self.main_window.updateToBasic,
                                          self.backButtonToolTip), row_idx, 0)
        self.addWidget(self._createButton(Utils.padStringCenter('Add coverage'),
                                          self._updateLayoutWithCoverageLine,
                                          'Add input coverage specie'), row_idx, 1)
        self.addWidget(self._createButton(self.runButtonText,
                                          self.runModel,
                                          self.runButtonToolTip), row_idx, 2)

    def _addUdk(self, row_idx):
        """
        Create ASALI user defined kinetic objects
        Parameters
        ----------
        row_idx: int
            Row index where to add the buttons
        Returns
        -------

        """
        self.addWidget(QLabel("ASALI kinetic model:"), row_idx, 0)
        self.addWidget(self.udkLoadLabel, row_idx, 1)
        self.addWidget(self._createButton(self.udkButtonText,
                                          self._loadUdkModel,
                                          self.udkButtonToolTip), row_idx, 2)

    def _loadUdkModel(self):
        """
        Load Asali kinetic model
        Returns
        -------

        """
        self.main_window.userInput.udk_file_path = Utils.openFile(self.main_window,
                                                                  file_type=FileType.ASALI.value)

        self.udkLoadLabel.setText(Utils.padString("Not loaded"))

        if self.main_window.userInput.udk_file_path is not None:
            if self.main_window.userInput.check_udk_input_file():
                self.udkLoadLabel.setText(Utils.padString("Loaded"))
            else:
                Utils.errorMessage(self.main_window,
                                   self.title,
                                   QLabel("Wrong ASALI input file."))

    def _checkInputFiles(self):
        """
        Check the input files to be used for reactor simulation
        Returns
        -------

        """
        if not self.main_window.userInput.check_cantera_input_file():
            Utils.errorMessage(self.main_window,
                               self.title,
                               QLabel("Wrong CANTERA input file."))

        if self.main_window.userInput.surface_phase_name is None:
            if self.main_window.userInput.udk_file_path is None:
                Utils.errorMessage(self.main_window,
                                   self.title,
                                   QLabel("""The provided CANTERA file does not have surface reactions."""))

        if self.main_window.userInput.udk_file_path is not None:
            if not self.main_window.userInput.check_udk_input_file():
                Utils.errorMessage(self.main_window,
                                   self.title,
                                   QLabel("Wrong ASALI input file."))

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

    def _extractInputComposition(self):
        """
        Extract input composition
        Returns
        -------
        composition: dict
            User input composition
        """
        names = [self.itemAt(i).widget().text() for i in self._coverage_names_idx]
        composition = [float(self.itemAt(i).widget().text()) for i in self._coverage_composition_idx]

        if np.fabs(sum(composition) - 1.0) > 1e-06:
            Utils.errorMessage(self.main_window,
                               self.title,
                               QLabel("Sum of coverage composition is > 1!!!"))
            return None

        return dict(zip(names, composition))

    def runModel(self):
        """
        Function to run the reactor model
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
        pass

    def initialize(self):
        """
        Initialize the widgets
        Returns
        -------
        """
        self._createReactorSelectionDropDown()

    def create(self):
        """
        Update the interface
        Returns
        -------
        """
        self.row_idx = self.row_idx + 1
        self.addWidget(self.reactorDropDown, self.row_idx, 0, 1, -1)
