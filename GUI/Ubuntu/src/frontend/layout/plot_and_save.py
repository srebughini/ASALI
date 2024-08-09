import pandas as pd

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

        self._save_format_list = [Utils.padString(".xlsx")]  # 0

        self.saveButtonText = Utils.padStringCenter("Save")
        self.saveButtonToolTip = "Save data"

        self.plotButtonText = Utils.padStringCenter("Plot")
        self.plotButtonToolTip = "Plot data"

        self.species_names = list()
        self.coverage_names = list()

        super().__init__(main_window)

    def _saveToExcel(self, file_path, output_dict):
        try:
            with pd.ExcelWriter(file_path) as writer:
                for sheet_name, df in output_dict.items():
                    df.to_excel(writer, sheet_name=sheet_name, index=False)

            # If saving is successful, show a success message
            Utils.dialogMessage(self.main_window,
                                self.title,
                                QLabel("File saved successfully!"))

        except Exception as e:
            # If an error occurs, show an error message
            Utils.errorMessage(self.main_window,
                               self.title,
                               QLabel(f"Failed to save file:\n{str(e)}"))
            return False

        return True

    def _saveData(self):
        """
        Save data
        Returns
        -------

        """
        file_path = Utils.saveFile(self.main_window,
                                   file_type=self.saveFormatDropDown.currentText().strip(),
                                   default_extension=self.saveFormatDropDown.currentText().strip())

        if file_path is not None:
            results_dict = self.main_window.userInput.reactor_model_backend.get_results()

            if self.saveFormatDropDown.currentIndex() == 0:
                self._saveToExcel(file_path, results_dict)

    def _plotData(self):
        """
        Plot data
        Returns
        -------

        """
        plot_dict = {"T": False,
                     "x": list(),
                     "y": list(),
                     "z": list()}

        if 'mole' in self.compositionUdDropDown.currentText().lower():
            plot_dict["x"] = [c.text() for c in self.gasSpeciesCheckBoxList if c.isChecked()]
        elif 'mass' in self.compositionUdDropDown.currentText().lower():
            plot_dict["y"] = [c.text() for c in self.gasSpeciesCheckBoxList if c.isChecked()]

        plot_dict["z"] = [c.text() for c in self.coverageCheckBoxList if c.isChecked()]

        if self.temperatureCheckBox.isChecked():
            plot_dict["T"] = True

        self.main_window.userInput.reactor_model_backend.plot(plot_dict)

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
        self.temperatureCheckBox = self._createCheckBox("Temperature")

        self.row_idx = self.row_idx + 1
        for i, check in enumerate(self.gasSpeciesCheckBoxList):
            self.addWidget(check, self.row_idx + i + 1, 0)

        for i, check in enumerate(self.coverageCheckBoxList):
            self.addWidget(check, self.row_idx + i + 1, 1)

        self.addWidget(self.temperatureCheckBox, self.row_idx + 1, 2)

        self.row_idx = self.row_idx + max([len(self.species_names),
                                           len(self.coverage_names)])

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
        self.saveFormatDropDown = self._createDropdown(self._save_format_list, function=None)

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
        self.addWidget(QLabel(Utils.padString("Saving format:")), self.row_idx, 0)
        self.addWidget(self.saveFormatDropDown, self.row_idx, 1, 1, -1)

        self.row_idx = self.row_idx + 1
        self.addWidget(self.headlineLabel, self.row_idx, 0, 1, -1)
