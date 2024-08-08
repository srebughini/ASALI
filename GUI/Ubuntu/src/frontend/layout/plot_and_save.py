from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import (
    QMainWindow, QLabel
)

from src.frontend.layout.basic import BasicLayout
from src.frontend.style import WidgetStyle
from src.frontend.utils import Utils


class PlotAndSaveLayout(BasicLayout):
    def __init__(self, main_window):
        """
        Reactor selection layout
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        self._empty_label = Utils.padString("")

        self._save_format_list = [Utils.padString(".xlsx"),  # 0
                                  Utils.padString(".csv")]  # 1

        self.saveButtonText = Utils.padStringCenter("Save")
        self.saveButtonToolTip = "Save data"

        self.plotButtonText = Utils.padStringCenter("Plot")
        self.plotButtonToolTip = "Plot data"

        self.species_names = list()
        self.coverage_names = list()
        self.variables = list()

        super().__init__(main_window)

    def _saveData(self):
        """
        Save data
        Returns
        -------

        """
        pass

    def _plotData(self):
        """
        Plot data
        Returns
        -------

        """
        pass

    def _removeButtons(self) -> None:
        """
        Remove Next, Back and Species buttons
        Returns
        -------

        """
        n_widget = self.count()
        self.itemAt(n_widget - 1).widget().setParent(None)
        self.itemAt(n_widget - 2).widget().setParent(None)

    def _addButtons(self, row_idx) -> None:
        """
        Add Back, Add Species and Run model buttons
        Parameters
        ----------
        row_idx: int
            Row index where to add the buttons
        Returns
        -------

        """

        self.addWidget(self._createButton(self.saveButtonText,
                                          self._saveData,
                                          self.saveButtonToolTip), row_idx, 0)
        self.addWidget(self._createButton(self.plotButtonText,
                                          self._plotData,
                                          self.plotButtonToolTip), row_idx, 2)

    def _updateLayoutWithBackendInfo(self) -> None:
        """
        Update the layout with the info coming from backend
        Returns
        -------

        """
        self.gasSpeciesCheckBoxList = [self._createCheckBox(s) for s in self.species_names]
        self.coverageCheckBoxList = [self._createCheckBox(c) for c in self.coverage_names]
        self.variablesCheckBoxList = [self._createCheckBox(v) for v in self.variables]

        self.row_idx = self.row_idx + 1
        for i, check in enumerate(self.gasSpeciesCheckBoxList):
            self.addWidget(check, self.row_idx + i + 1, 0)

        for i, check in enumerate(self.coverageCheckBoxList):
            self.addWidget(check, self.row_idx + i + 1, 1)

        for i, check in enumerate(self.variablesCheckBoxList):
            self.addWidget(check, self.row_idx + i + 1, 2)

        self.row_idx = self.row_idx + max([len(self.species_names),
                                           len(self.coverage_names),
                                           len(self.variables)])

        self.row_idx = self.row_idx + 1
        self._addButtons(self.row_idx)

    def runBackend(self) -> None:
        """
        Run backend to extract information from the reactor model
        Returns
        -------
        """
        self.species_names = self.main_window.userInput.reactor_model_backend.gas_species_list()
        self.coverage_names = self.main_window.userInput.reactor_model_backend.coverage_list()
        self.variables = self.main_window.userInput.reactor_model_backend.variables_list()

        self._updateLayoutWithBackendInfo()

    def initialize(self) -> None:
        """
        Initialize the widgets
        Returns
        -------
        """
        # Headline
        self.headlineLabel = QLabel("Select variables for plotting")
        self.headlineLabel.setStyleSheet(WidgetStyle.ITALICLABEL.value)
        self.headlineLabel.setAlignment(Qt.AlignCenter)

        self.compositionUdDropDown = self._createDropdown(self.main_window.defaultInput.compositionUd, function=None)

    def create(self) -> None:
        """
        Update the interface
        Returns
        -------
        """
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Composition type:")), self.row_idx, 0)
        self.addWidget(self.compositionUdDropDown, self.row_idx, 1, 1, -1)

        self.row_idx = self.row_idx + 1
        self.addWidget(self.headlineLabel, self.row_idx, 0, 1, -1)
