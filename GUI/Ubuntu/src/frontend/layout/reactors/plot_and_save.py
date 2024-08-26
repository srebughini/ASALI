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
        Plot reactor results
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        self.compositionUdDropDown = None
        self.colormapDropDown = None
        self.headlineLabel = None

        self._empty_label = Utils.pad_string("")

        self._colormap_list = [Utils.pad_string(s) for s in ['Greys', 'Purples', 'Blues', 'Greens', 'Oranges', 'Reds']]

        self.saveButtonText = Utils.pad_string_center("Save")
        self.saveButtonToolTip = "Save data"

        self.selectButtonText = Utils.pad_string_center("Select all")
        self.selectButtonToolTip = "Select All"

        self.plotButtonText = Utils.pad_string_center("Plot")
        self.plotButtonToolTip = "Plot data"

        self.species_names = list()
        self.coverage_names = list()

        super().__init__(main_window)

    def _save_data(self) -> None:
        """
        Save data
        Returns
        -------

        """
        save_dict = {"x": False,
                     "y": False,
                     "file_path": None}

        if 'mole' in self.compositionUdDropDown.currentText().lower():
            save_dict["x"] = True

        if 'mass' in self.compositionUdDropDown.currentText().lower():
            save_dict["y"] = True

        file_path = Utils.save_file(self.main_window,
                                    file_type=FileType.EXCEL.value,
                                    default_extension=".xlsx")

        if file_path is not None:
            save_dict["file_path"] = file_path
            self.main_window.backend_frontend_manager.reactor_parser.save(save_dict)

    def _select_all(self) -> None:
        """
        Select or unselect all check boxs
        Returns
        -------

        """
        for c in self.gasSpeciesCheckBoxList:
            c.setChecked(True)

        for c in self.coverageCheckBoxList:
            c.setChecked(True)

        self.temperatureCheckBox.setChecked(True)

    def _unselect_all(self) -> None:
        """
        Unselect all check boxs
        Returns
        -------

        """
        for c in self.gasSpeciesCheckBoxList:
            c.setChecked(False)

        for c in self.coverageCheckBoxList:
            c.setChecked(False)

        self.temperatureCheckBox.setChecked(False)

    def _select_data(self) -> None:
        """
        Select or unselect all check box
        Returns
        -------

        """
        if not self.temperatureCheckBox.isChecked():
            self._select_all()
            return None

        for c in self.gasSpeciesCheckBoxList:
            if not c.isChecked():
                self._select_all()
                return None

        for c in self.coverageCheckBoxList:
            if not c.isChecked():
                self._select_all()
                return None

        self._unselect_all()

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

        plot_dict["colormap"] = self.colormapDropDown.currentText().strip()

        if self.temperatureCheckBox.isChecked():
            plot_dict["T"] = True

        self.main_window.backend_frontend_manager.reactor_parser.plot(plot_dict)

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
        self.addWidget(self._create_button(self.selectButtonText,
                                           self._select_data,
                                           self.selectButtonToolTip), row_idx, 1)
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
        self.species_names = self.main_window.backend_frontend_manager.reactor_parser.gas_species_list()
        self.coverage_names = self.main_window.backend_frontend_manager.reactor_parser.coverage_list()

        self._update_layout_with_backend_info()

    def create_layout_components(self) -> None:
        """
        Initialize the widgets
        Returns
        -------
        """
        # Headline
        self.headlineLabel = QLabel("Select variables for plotting")
        self.headlineLabel.setStyleSheet(WidgetStyle.ITALICLABEL.value)
        self.headlineLabel.setAlignment(Qt.AlignCenter)

        self.compositionUdDropDown = self._create_dropdown(self.main_window.ud_handler.composition_ud, function=None)
        self.colormapDropDown = self._create_dropdown(self._colormap_list, function=None)

    def generate_layout(self) -> None:
        """
        Update the interface
        Returns
        -------
        """
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Composition type:")), self.row_idx, 0)
        self.addWidget(self.compositionUdDropDown, self.row_idx, 1, 1, -1)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Plotting color map:")), self.row_idx, 0)
        self.addWidget(self.colormapDropDown, self.row_idx, 1, 1, -1)

        self.row_idx = self.row_idx + 1
        self.addWidget(self.headlineLabel, self.row_idx, 0, 1, -1)
