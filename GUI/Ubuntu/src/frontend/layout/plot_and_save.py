import pandas as pd

from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import (
    QMainWindow, QLabel
)

from src.frontend.layout.basic import BasicLayout
from src.frontend.style import WidgetStyle, FileType
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
        self.saveFormatDropDown = None
        self.compositionUdDropDown = None
        self.headlineLabel = None

        self._empty_label = Utils.pad_string("")

        self._save_format_list = [Utils.pad_string(".xlsx")]  # 0

        self.saveButtonText = Utils.pad_string_center("Save")
        self.saveButtonToolTip = "Save data"

        self.plotButtonText = Utils.pad_string_center("Plot")
        self.plotButtonToolTip = "Plot data"

        self.species_names = list()
        self.coverage_names = list()

        super().__init__(main_window)

    def _save_to_excel(self, file_path, output_dict) -> bool:
        """
        Save results into excel format
        Parameters
        ----------
        file_path: str
            File path
        output_dict: dict
            Results in dict format. Dictionary of Pandas Dataframe

        Returns
        -------
        check: bool
            If True the saving is successfully
        """
        try:
            with pd.ExcelWriter(file_path) as writer:
                for sheet_name, df in output_dict.items():
                    df.to_excel(writer, sheet_name=sheet_name, index=False)

            # If saving is successful, show a success message
            Utils.dialog_message(self.main_window,
                                 self.title,
                                 QLabel("File saved successfully!"))

        except Exception as e:
            # If an error occurs, show an error message
            Utils.error_message(self.main_window,
                                self.title,
                                QLabel(f"Failed to save file: {str(e)}"))
            return False

        return True

    def _save_data(self) -> None:
        """
        Save data
        Returns
        -------

        """
        if self.saveFormatDropDown.currentIndex() == 0:
            file_path = Utils.save_file(self.main_window,
                                        file_type=FileType.EXCEL.value,
                                        default_extension=self.saveFormatDropDown.currentText().strip())

            if file_path is not None:
                self._save_to_excel(file_path,
                                    self.main_window.userInput.reactor_model_backend.get_results())

    def _plot_data(self) -> None:
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

    def _add_buttons(self, row_idx) -> None:
        """
        Add Back, Add Species and Run model buttons
        Parameters
        ----------
        row_idx: int
            Row index where to add the buttons
        Returns
        -------

        """

        self.addWidget(self._create_button(self.saveButtonText,
                                           self._save_data,
                                           self.saveButtonToolTip), row_idx, 0)
        self.addWidget(self._create_button(self.plotButtonText,
                                           self._plot_data,
                                           self.plotButtonToolTip), row_idx, 2)

    def _update_layout_with_backend_info(self) -> None:
        """
        Update the layout with the info coming from backend
        Returns
        -------

        """
        self.gasSpeciesCheckBoxList = [self._create_check_box(s) for s in self.species_names]
        self.coverageCheckBoxList = [self._create_check_box(c) for c in self.coverage_names]
        self.temperatureCheckBox = self._create_check_box("Temperature")

        self.row_idx = self.row_idx + 1
        for i, check in enumerate(self.gasSpeciesCheckBoxList):
            self.addWidget(check, self.row_idx + i + 1, 0)

        for i, check in enumerate(self.coverageCheckBoxList):
            self.addWidget(check, self.row_idx + i + 1, 1)

        self.addWidget(self.temperatureCheckBox, self.row_idx + 1, 2)

        self.row_idx = self.row_idx + max([len(self.species_names),
                                           len(self.coverage_names)])

        self.row_idx = self.row_idx + 1
        self._add_buttons(self.row_idx)

    def run_backend(self) -> None:
        """
        Run backend to extract information from the reactor model
        Returns
        -------
        """
        self.species_names = self.main_window.userInput.reactor_model_backend.gas_species_list()
        self.coverage_names = self.main_window.userInput.reactor_model_backend.coverage_list()

        self._update_layout_with_backend_info()

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

        self.compositionUdDropDown = self._create_dropdown(self.main_window.defaultInput.composition_ud, function=None)
        self.saveFormatDropDown = self._create_dropdown(self._save_format_list, function=None)

    def create(self) -> None:
        """
        Update the interface
        Returns
        -------
        """
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Composition type:")), self.row_idx, 0)
        self.addWidget(self.compositionUdDropDown, self.row_idx, 1, 1, -1)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Saving format:")), self.row_idx, 0)
        self.addWidget(self.saveFormatDropDown, self.row_idx, 1, 1, -1)

        self.row_idx = self.row_idx + 1
        self.addWidget(self.headlineLabel, self.row_idx, 0, 1, -1)
