from PyQt5.QtWidgets import (
    QMainWindow, QLabel
)

from src.backend.transport_and_thermodynamic_properties import TransportAndThermodynamicProperties
from src.frontend.layout.calculated_basic_layout import CalculatedBasicLayout
from src.frontend.utils import Utils


class TransportAndThermodynamicPropertiesLayout(CalculatedBasicLayout):
    def __init__(self, main_window):
        """
        Transport and thermodynamic properties
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        self._empty_label = Utils.padString("")
        super().__init__(main_window)

    def run_backend(self):
        """
        Run backend to update frontend
        Returns
        -------

        """
        self.properties = TransportAndThermodynamicProperties(self.main_window.userInput.file_path,
                                                              self.main_window.userInput.gas_phase_name)

        temperature_value = self.main_window.userInput.temperature["value"]
        temperature_ud = self.main_window.userInput.temperature["ud"]
        pressure_value = self.main_window.userInput.pressure["value"]
        pressure_ud = self.main_window.userInput.pressure["ud"]

        if len(self.main_window.userInput.mole_fraction) > 0:
            self.properties.set_temperature_pressure_and_mole_fraction(temperature_value,
                                                                       temperature_ud,
                                                                       pressure_value,
                                                                       pressure_ud,
                                                                       self.main_window.userInput.mole_fraction)

        if len(self.main_window.userInput.mass_fraction) > 0:
            self.properties.set_temperature_pressure_and_mass_fraction(temperature_value,
                                                                       temperature_ud,
                                                                       pressure_value,
                                                                       pressure_ud,
                                                                       self.main_window.userInput.mass_fraction)

        rho = self.properties.density(self.rhoDropDown.currentText())
        mw = self.properties.molecular_weight(self.mwDropDown.currentText())
        mu = self.properties.viscosity(self.muDropDown.currentText())
        cond = self.properties.thermal_conductivity(self.condDropDown.currentText())
        diff_mix = self.properties.mixture_diffusivity(self.diffMixDropDown.currentText())

        self.rhoLabel.setText(Utils.padString(Utils.fromNumberToString(rho)))
        self.mwLabel.setText(Utils.padString(Utils.fromNumberToString(mw)))
        self.muLabel.setText(Utils.padString(Utils.fromNumberToString(mu)))
        self.condLabel.setText(Utils.padString(Utils.fromNumberToString(cond)))
        self.diffMixLabel.setText(Utils.fromDictToString(diff_mix))

    def initialize(self):
        """
        Initialize the widgets
        Returns
        -------

        """
        # Density
        self.rhoDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.densityUd],
            function=None)
        self.rhoLabel = QLabel(self._empty_label)

        # Molecular weight
        self.mwDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.molecularWeigthUd],
            function=None)
        self.mwLabel = QLabel(self._empty_label)

        # Viscosity
        self.muDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.viscosityUd],
            function=None)
        self.muLabel = QLabel(self._empty_label)

        # Thermal conductivity
        self.condDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.thermalConductivityUd],
            function=None)
        self.condLabel = QLabel(self._empty_label)

        # Mixture diffusivity
        self.diffMixDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.diffusivityUd],
            function=None)
        self.diffMixLabel = QLabel(self._empty_label)

    def create(self):
        """
        Update the interface
        Returns
        -------
        """

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel('<p style="text-align: center"><b>Transport properties</b></p>'), self.row_idx, 0, 1, -1)

        # Density
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Density")), self.row_idx, 0)
        self.addWidget(self.rhoLabel, self.row_idx, 1)
        self.addWidget(self.rhoDropDown, self.row_idx, 2)

        # Molecular weight
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Molecular weight")), self.row_idx, 0)
        self.addWidget(self.mwLabel, self.row_idx, 1)
        self.addWidget(self.mwDropDown, self.row_idx, 2)

        # Viscosity
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Viscosity")), self.row_idx, 0)
        self.addWidget(self.muLabel, self.row_idx, 1)
        self.addWidget(self.muDropDown, self.row_idx, 2)

        # Thermal conductivity
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Thermal conductivity")), self.row_idx, 0)
        self.addWidget(self.condLabel, self.row_idx, 1)
        self.addWidget(self.condDropDown, self.row_idx, 2)

        # Mixture diffusivity
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Mixture diffusivity")), self.row_idx, 0)
        self.addWidget(self.diffMixLabel, self.row_idx, 1)
        self.addWidget(self.diffMixDropDown, self.row_idx, 2)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel('<p style="text-align: center"><b>Thermodynamic properties</b></p>'), self.row_idx, 0, 1,
                       -1)
