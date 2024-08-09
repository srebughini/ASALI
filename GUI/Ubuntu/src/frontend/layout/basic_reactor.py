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
        self._empty_label = Utils.pad_string("")

        self._select_reactor_list = [
            Utils.pad_string("...Select reactor model..."),
            Utils.pad_string("Batch reactor"),  # 1
            Utils.pad_string("Continuous stirred tank reactor"),  # 2
            Utils.pad_string("Steady state 1D pseudo-homogeneous reactor"),  # 3
            Utils.pad_string("Transient 1D pseudo-homogeneous reactor"),  # 4
            Utils.pad_string("Steady state 1D heterogeneous reactor"),  # 5
            Utils.pad_string("Transient 1D heterogeneous reactor")]  # 6

        self._on_off_list = [Utils.pad_string("ON"), Utils.pad_string("OFF")]

        self.runButtonText = Utils.pad_string_center("Run model")
        self.runButtonToolTip = "Run reactor model"

        self.udkButtonText = Utils.pad_string_center("Load")
        self.udkButtonToolTip = "Load ASALI kinetic model"

        self._coverage_names_idx = list()
        self._coverage_composition_idx = list()

        super().__init__(main_window)

    def _update_layout(self) -> None:
        """
        Update layout based on reactor selection
        Returns
        -------

        """
        if self.reactorDropDown.currentIndex() == 0:
            self.main_window.update_to_basic()
        elif self.reactorDropDown.currentIndex() == 1:
            self.main_window.update_to_batch_reactor()
        elif self.reactorDropDown.currentIndex() == 2:
            self.main_window.update_to_cstr_reactor()
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

    def _update_layout_with_coverage_line(self) -> None:
        """
        Update the layout by adding specie input line
        Returns
        -------

        """
        self._remove_last_widgets(3)
        self._add_coverage_input_line(self.row_idx)
        self.row_idx = self.row_idx + 1
        self._add_buttons(self.row_idx)

    def _create_reactor_selection_dropdown(self) -> None:
        """
        Create reactor selection drop down menu
        Returns
        -------

        """
        self.reactorDropDown = self._create_dropdown(self._select_reactor_list,
                                                     function=self._update_layout)

    def _create_udk_label(self) -> None:
        """
        Create user defined kinetic label
        Returns
        -------

        """
        self.udkLoadLabel = QLabel(Utils.pad_string("Not loaded"))
        self.udkLoadLabel.setStyleSheet(WidgetStyle.HIGHLIGHTLABEL.value)
        self.udkLoadLabel.setAlignment(Qt.AlignCenter)

    def _add_coverage_input_line(self, row_idx) -> None:
        """
        Add input coverage line
        Parameters
        ----------
        row_idx: int
            Row index where to add the input line

        Returns
        -------

        """
        self.addWidget(QLabel(Utils.pad_string(f"Coverage #{len(self._coverage_names_idx) + 1}")), row_idx, 0)
        self.addWidget(self._create_line_edit("Rh(s)", Qt.AlignRight, None), row_idx, 1)
        self._coverage_names_idx.append(self.count() - 1)
        self.addWidget(self._create_line_edit("1", Qt.AlignRight, QDoubleValidator()), row_idx, 2)
        self._coverage_composition_idx.append(self.count() - 1)

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
        self.addWidget(self._create_button(self.backButtonText,
                                           self.main_window.update_to_basic,
                                           self.backButtonToolTip), row_idx, 0)
        self.addWidget(self._create_button(Utils.pad_string_center('Add coverage'),
                                           self._update_layout_with_coverage_line,
                                           'Add input coverage specie'), row_idx, 1)
        self.addWidget(self._create_button(self.runButtonText,
                                           self.run_reactor_model,
                                           self.runButtonToolTip), row_idx, 2)

    def _add_udk(self, row_idx) -> None:
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
        self.addWidget(self._create_button(self.udkButtonText,
                                           self._load_udk_model,
                                           self.udkButtonToolTip), row_idx, 2)

    def _load_udk_model(self) -> None:
        """
        Load ASALI user defined kinetic model
        Returns
        -------

        """
        self.main_window.userInput.udk_file_path = Utils.open_file(self.main_window,
                                                                   file_type=FileType.ASALI.value)

        self.udkLoadLabel.setText(Utils.pad_string("Not loaded"))

        if self.main_window.userInput.udk_file_path is not None:
            if self.main_window.userInput.check_udk_input_file():
                self.udkLoadLabel.setText(Utils.pad_string("Loaded"))
            else:
                Utils.error_message(self.main_window,
                                    self.title,
                                    QLabel("Wrong ASALI input file."))

    def _check_input_files(self) -> None:
        """
        Check the input files to be used for reactor simulation
        Returns
        -------

        """
        if not self.main_window.userInput.check_cantera_input_file():
            Utils.error_message(self.main_window,
                                self.title,
                                QLabel("Wrong CANTERA input file."))

        if self.main_window.userInput.surface_phase_name is None:
            if self.main_window.userInput.udk_file_path is None:
                Utils.error_message(self.main_window,
                                    self.title,
                                    QLabel("""The provided CANTERA file does not have surface reactions."""))

        if self.main_window.userInput.udk_file_path is not None:
            if not self.main_window.userInput.check_udk_input_file():
                Utils.error_message(self.main_window,
                                    self.title,
                                    QLabel("Wrong ASALI input file."))

    def _extract_coverage_input_composition(self) -> dict | None:
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
            Utils.error_message(self.main_window,
                                self.title,
                                QLabel("Sum of coverage composition is > 1!!!"))
            return None

        return dict(zip(names, composition))

    def run_reactor_model(self) -> None:
        """
        Function to run the reactor model
        Returns
        -------

        """
        pass

    def run_backend(self) -> None:
        """
        Run backend to update frontend
        Returns
        -------

        """
        pass

    def initialize(self) -> None:
        """
        Initialize the widgets
        Returns
        -------
        """
        self._create_reactor_selection_dropdown()

    def create(self) -> None:
        """
        Update the interface
        Returns
        -------
        """
        self.row_idx = self.row_idx + 1
        self.addWidget(self.reactorDropDown, self.row_idx, 0, 1, -1)
