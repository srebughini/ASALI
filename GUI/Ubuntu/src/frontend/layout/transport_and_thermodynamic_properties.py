from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import (
    QMainWindow, QLabel
)

from src.backend.transport_and_thermodynamic_properties import TransportAndThermodynamicProperties
from src.frontend.layout.basic_calculation import BasicCalculationLayout
from src.frontend.style import WidgetStyle
from src.frontend.utils import Utils


class TransportAndThermodynamicPropertiesLayout(BasicCalculationLayout):
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

    def _updateProperties(self):
        """
        Update estimated properties
        Returns
        -------
        """
        # Transport properties
        rho = self.cl.density(self.rhoDropDown.currentText())
        mw = self.cl.molecular_weight(self.mwDropDown.currentText())
        mu = self.cl.viscosity(self.muDropDown.currentText())
        cond = self.cl.thermal_conductivity(self.condDropDown.currentText())
        diff_mix = self.cl.mixture_diffusivity(self.diffMixDropDown.currentText())

        self.rhoLabel.setText(Utils.padString(Utils.fromNumberToString(rho)))
        self.mwLabel.setText(Utils.padString(Utils.fromNumberToString(mw)))
        self.muLabel.setText(Utils.padString(Utils.fromNumberToString(mu)))
        self.condLabel.setText(Utils.padString(Utils.fromNumberToString(cond)))
        self.diffMixLabel.setText(Utils.fromDictToString(diff_mix))

        # Thermodynamic properties
        h = self.cl.enthalpy(self.enthalpyDropDown.currentText())
        s = self.cl.entropy(self.entropyDropDown.currentText())
        cp = self.cl.specific_heat(self.specificHeatDropDown.currentText())

        self.enthalpyLabel.setText(Utils.padString(Utils.fromNumberToString(h)))
        self.entropyLabel.setText(Utils.padString(Utils.fromNumberToString(s)))
        self.specificHeatLabel.setText(Utils.padString(Utils.fromNumberToString(cp)))

    def runBackend(self):
        """
        Run backend to update frontend
        Returns
        -------

        """
        self.cl = self._setGasMixtureUserInput(TransportAndThermodynamicProperties(self.main_window.userInput.file_path,
                                                                                   self.main_window.userInput.gas_phase_name))
        self._updateProperties()

    def initialize(self):
        """
        Initialize the widgets
        Returns
        -------

        """
        # Titles label
        self.thermoLabel = QLabel("Thermodynamic properties")
        self.thermoLabel.setStyleSheet(WidgetStyle.HIGHLIGHTLABEL.value)
        self.thermoLabel.setAlignment(Qt.AlignCenter)

        self.transportLabel = QLabel("Transport properties")
        self.transportLabel.setStyleSheet(WidgetStyle.HIGHLIGHTLABEL.value)
        self.transportLabel.setAlignment(Qt.AlignCenter)

        # Density
        self.rhoDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.densityUd],
            function=self._updateProperties)
        self.rhoLabel = QLabel(self._empty_label)

        # Molecular weight
        self.mwDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.molecularWeigthUd],
            function=self._updateProperties)
        self.mwLabel = QLabel(self._empty_label)

        # Viscosity
        self.muDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.viscosityUd],
            function=self._updateProperties)
        self.muLabel = QLabel(self._empty_label)

        # Thermal conductivity
        self.condDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.thermalConductivityUd],
            function=self._updateProperties)
        self.condLabel = QLabel(self._empty_label)

        # Mixture diffusivity
        self.diffMixDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.diffusivityUd],
            function=self._updateProperties)
        self.diffMixLabel = QLabel(self._empty_label)

        # Enthalpy
        self.enthalpyDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.enthalpyUd],
            function=self._updateProperties)
        self.enthalpyLabel = QLabel(self._empty_label)

        # Entropy
        self.entropyDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.entropyUd],
            function=self._updateProperties)
        self.entropyLabel = QLabel(self._empty_label)

        # Specific heat
        self.specificHeatDropDown = self._createDropdown(
            [Utils.padString(ud) for ud in self.main_window.defaultInput.specificHeatUd],
            function=self._updateProperties)
        self.specificHeatLabel = QLabel(self._empty_label)

    def create(self):
        """
        Update the interface
        Returns
        -------
        """

        self.row_idx = self.row_idx + 1
        self.addWidget(self.transportLabel, self.row_idx, 0, 1, -1)

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
        self.addWidget(self.thermoLabel, self.row_idx, 0, 1, -1)

        # Enthalpy
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Enthalpy")), self.row_idx, 0)
        self.addWidget(self.enthalpyLabel, self.row_idx, 1)
        self.addWidget(self.enthalpyDropDown, self.row_idx, 2)

        # Entropy
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Entropy")), self.row_idx, 0)
        self.addWidget(self.entropyLabel, self.row_idx, 1)
        self.addWidget(self.entropyDropDown, self.row_idx, 2)

        # Specific heat
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.padString("Specific heat")), self.row_idx, 0)
        self.addWidget(self.specificHeatLabel, self.row_idx, 1)
        self.addWidget(self.specificHeatDropDown, self.row_idx, 2)
