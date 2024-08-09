from PyQt5.QtCore import Qt
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import (
    QMainWindow, QLabel
)
from src.frontend.layout.basic import BasicLayout
from src.frontend.utils import Utils
from src.frontend.window.chemical_equilibrium import ChemicalEquilibriumWindow
from src.frontend.window.reactors import ReactorsWindow
from src.frontend.window.transport_and_thermodynamic_properties import TransportAndThermodynamicPropertiesWindow
from src.frontend.window.vacuum_properties import VacuumPropertiesWindow

import numpy as np


class CalculationMainMenuLayout(BasicLayout):
    def __init__(self, main_window):
        """
        Calculation menu layout
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        self._select_calculation_option_list = [Utils.pad_string("...Calculation to be performed..."),
                                                Utils.pad_string("Thermodynamic and transport properties"),
                                                Utils.pad_string("Vacuum properties"),
                                                Utils.pad_string("Chemical equilibrium"),
                                                Utils.pad_string("Reactor modeling")]

        self._specie_names_idx = list()
        self._composition_idx = list()

        super().__init__(main_window)

    def _load_selected_calculation_menu(self) -> None:
        """
        Load select calculation Menu
        Returns
        -------

        """
        if self.selectCalculationDropDown.currentIndex() == 0:
            Utils.error_message(self.main_window,
                                self.title,
                                QLabel("Please, select the calculation method!"))
        elif self.selectCalculationDropDown.currentIndex() == 1:
            if self.get_user_input():
                window = Utils.create_new_window_object(self.main_window, TransportAndThermodynamicPropertiesWindow)
                window.runBackend()
                Utils.open_new_window_from_object(window)
        elif self.selectCalculationDropDown.currentIndex() == 2:
            if self.get_user_input():
                window = Utils.create_new_window_object(self.main_window, VacuumPropertiesWindow)
                window.runBackend()
                Utils.open_new_window_from_object(window)
        elif self.selectCalculationDropDown.currentIndex() == 3:
            if self.get_user_input():
                window = Utils.create_new_window_object(self.main_window, ChemicalEquilibriumWindow)
                window.runBackend()
                Utils.open_new_window_from_object(window)
        elif self.selectCalculationDropDown.currentIndex() == 4:
            if self.get_user_input():
                window = Utils.create_new_window_object(self.main_window, ReactorsWindow)
                window.runBackend()
                Utils.open_new_window_from_object(window)

    def _add_buttons(self, row_idx) -> None:
        """
        Add Next, Back and Add Species buttons
        Parameters
        ----------
        row_idx: int
            Row index where to add the buttons
        Returns
        -------

        """
        self.addWidget(self._create_button(self.backButtonText,
                                           self.main_window.updateToMainMenuLayout,
                                           self.backButtonToolTip), row_idx, 0)
        self.addWidget(self._create_button(Utils.pad_string_center('Add specie'),
                                           self._update_layout_with_specie_line,
                                          'Add input species'), row_idx, 1)
        self.addWidget(self._create_button(Utils.pad_string_center('Calculate'),
                                           self._load_selected_calculation_menu,
                                           self.nextButtonToolTip), row_idx, 2)

    def _add_species_input_line(self, row_idx) -> None:
        """
        Add input species line
        Parameters
        ----------
        row_idx: int
            Row index where to add the input line

        Returns
        -------

        """
        self.addWidget(QLabel(Utils.pad_string(f"Specie #{len(self._specie_names_idx) + 1}")), row_idx, 0)
        self.addWidget(self._create_line_edit("H2", Qt.AlignRight, None), row_idx, 1)
        self._specie_names_idx.append(self.count() - 1)
        self.addWidget(self._create_line_edit("0.5", Qt.AlignRight, QDoubleValidator()), row_idx, 2)
        self._composition_idx.append(self.count() - 1)

    def _update_layout_with_specie_line(self) -> None:
        """
        Update the layout by adding specie input line
        Returns
        -------

        """
        self._remove_last_widgets(3)
        self._add_species_input_line(self.row_idx)
        self.row_idx = self.row_idx + 1
        self._add_buttons(self.row_idx)

    def _extract_species_input_composition(self) -> dict:
        """
        Extract input composition
        Returns
        -------
        composition: dict
            User input composition
        """
        names = [self.itemAt(i).widget().text() for i in self._specie_names_idx]
        composition = [float(self.itemAt(i).widget().text()) for i in self._composition_idx]

        if np.fabs(sum(composition) - 1.0) > 1e-06:
            Utils.error_message(self.main_window,
                                self.title,
                                QLabel("Sum of composition is > 1!!!"))
            return None

        return dict(zip(names, composition))

    def get_user_input(self) -> bool:
        """
        Get temperature, composition and pressure from input
        Returns
        -------
        check: bool
            True if everything is correct
        """
        temperature = {"value": float(self.temperatureLine.text()),
                       "ud": self.temperatureUdDropDown.currentText()}
        pressure = {"value": float(self.pressureLine.text()),
                    "ud": self.pressureUdDropDown.currentText()}

        composition = self._extract_species_input_composition()

        if composition is None:
            return False

        self.main_window.userInput.temperature = temperature
        self.main_window.userInput.pressure = pressure

        if self.compositionUdDropDown.currentIndex() == 0:
            self.main_window.userInput.mass_fraction = composition
            self.main_window.userInput.mole_fraction = {}
        elif self.compositionUdDropDown.currentIndex() == 1:
            self.main_window.userInput.mass_fraction = {}
            self.main_window.userInput.mole_fraction = composition

        return True

    def initialize(self) -> None:
        """
        Initialize the widgets
        Returns
        -------

        """
        self.selectCalculationDropDown = self._create_dropdown(self._select_calculation_option_list,
                                                               function=None)

        self.temperatureUdDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.defaultInput.temperature_ud],
            function=None)

        self.temperatureLine = self._create_line_edit("298.15", Qt.AlignRight, QDoubleValidator())

        self.pressureUdDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.defaultInput.pressure_ud],
            function=None)

        self.pressureLine = self._create_line_edit("101325", Qt.AlignRight, QDoubleValidator())

        self.compositionUdDropDown = self._create_dropdown(self.main_window.defaultInput.composition_ud, function=None)

    def create(self) -> None:
        """
        Update the interface
        Returns
        -------
        """
        self.row_idx = self.row_idx + 1
        self.addWidget(self.selectCalculationDropDown, self.row_idx, 0, 1, -1)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Temperature:")), self.row_idx, 0)
        self.addWidget(self.temperatureLine, self.row_idx, 1)
        self.addWidget(self.temperatureUdDropDown, self.row_idx, 2)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Pressure:")), self.row_idx, 0)
        self.addWidget(self.pressureLine, self.row_idx, 1)
        self.addWidget(self.pressureUdDropDown, self.row_idx, 2)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Composition type:")), self.row_idx, 0)
        self.addWidget(self.compositionUdDropDown, self.row_idx, 1, 1, -1)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Chemical formula")), self.row_idx, 1)
        self.addWidget(QLabel(Utils.pad_string("Composition")), self.row_idx, 2)

        self.row_idx = self.row_idx + 1
        self._add_species_input_line(self.row_idx)

        self.row_idx = self.row_idx + 1
        self._add_buttons(self.row_idx)
