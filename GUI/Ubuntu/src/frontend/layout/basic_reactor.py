from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import (
    QMainWindow, QLabel
)

from src.frontend.layout.basic import BasicLayout
from src.frontend.style import FileType, WidgetStyle
from src.frontend.utils import Utils


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
        super().__init__(main_window)

    def _loadAsaliKineitcModel(self):
        """
        Load Asali kinetic model
        Returns
        -------

        """
        self.main_window.userInput.udk_file_path = Utils.openFile(self.main_window,
                                                                  file_type=FileType.ASALI.value)

        if self.main_window.userInput.udk_file_path is None:
            self.udkLoadLabel.setText(Utils.padString("Not loaded"))
        else:
            self.udkLoadLabel.setText(Utils.padString("Loaded"))

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

    def _runModel(self):
        """
        Function to run the reactor model
        Returns
        -------

        """
        pass

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

    def _createReactorSelectionDropDown(self):
        """
        Create reactor selection drop down menu
        Returns
        -------

        """
        self.reactorDropDown = self._createDropdown(self._select_reactor_list,
                                                    function=self._updateLayout)

    def _createRunButton(self):
        """
        Create run button
        Returns
        -------

        """
        self.runButton = self._createButton(self.runButtonText,
                                            self._runModel,
                                            self.runButtonToolTip)

    def _createBackButton(self):
        """
        Create back button
        Returns
        -------

        """
        self.backButton = self._createButton(self.backButtonText,
                                             self.main_window.updateToBasic,
                                             self.backButtonToolTip)

    def _createAsaliKineticObjects(self):
        """
        Create ASALI kinetic button
        Returns
        -------

        """
        self.udkButton = self._createButton(self.udkButtonText,
                                            self._loadAsaliKineitcModel,
                                            self.udkButtonToolTip)

        self.udkLabel = QLabel("ASALI kinetic model:")
        self.udkLoadLabel = QLabel(Utils.padString("Not loaded"))
        self.udkLoadLabel.setStyleSheet(WidgetStyle.HIGHLIGHTLABEL.value)
        self.udkLoadLabel.setAlignment(Qt.AlignCenter)

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
