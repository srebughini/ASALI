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
        self.thermoLabel = None
        self.transportLabel = None
        self.rhoDropDown = None
        self.rhoLabel = None
        self.mwDropDown = None
        self.mwLabel = None
        self.muDropDown = None
        self.muLabel = None
        self.condDropDown = None
        self.condLabel = None
        self.diffMixDropDown = None
        self.diffMixLabel = None
        self.enthalpyDropDown = None
        self.enthalpyLabel = None
        self.entropyDropDown = None
        self.entropyLabel = None
        self.specificHeatDropDown = None
        self.specificHeatLabel = None

        self._empty_label = Utils.pad_string("")
        super().__init__(main_window)

    def _update_properties(self) -> None:
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

        self.rhoLabel.setText(Utils.pad_string(Utils.from_number_to_string(rho)))
        self.mwLabel.setText(Utils.pad_string(Utils.from_number_to_string(mw)))
        self.muLabel.setText(Utils.pad_string(Utils.from_number_to_string(mu)))
        self.condLabel.setText(Utils.pad_string(Utils.from_number_to_string(cond)))
        self.diffMixLabel.setText(Utils.from_dict_to_string(diff_mix))

        # Thermodynamic properties
        h = self.cl.enthalpy(self.enthalpyDropDown.currentText())
        s = self.cl.entropy(self.entropyDropDown.currentText())
        cp = self.cl.specific_heat(self.specificHeatDropDown.currentText())

        self.enthalpyLabel.setText(Utils.pad_string(Utils.from_number_to_string(h)))
        self.entropyLabel.setText(Utils.pad_string(Utils.from_number_to_string(s)))
        self.specificHeatLabel.setText(Utils.pad_string(Utils.from_number_to_string(cp)))

    def run_backend(self) -> None:
        """
        Run backend to update frontend
        Returns
        -------

        """
        self.cl = self._set_gas_mixture_user_input(TransportAndThermodynamicProperties(self.main_window.userInput.file_path,
                                                                                       self.main_window.userInput.gas_phase_name))
        self._update_properties()

    def create_layout_components(self) -> None:
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
        self.rhoDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.defaultInput.density_ud],
            function=self._update_properties)
        self.rhoLabel = QLabel(self._empty_label)

        # Molecular weight
        self.mwDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.defaultInput.molecular_weight_ud],
            function=self._update_properties)
        self.mwLabel = QLabel(self._empty_label)

        # Viscosity
        self.muDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.defaultInput.viscosity_ud],
            function=self._update_properties)
        self.muLabel = QLabel(self._empty_label)

        # Thermal conductivity
        self.condDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.defaultInput.thermal_conductivity_ud],
            function=self._update_properties)
        self.condLabel = QLabel(self._empty_label)

        # Mixture diffusivity
        self.diffMixDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.defaultInput.diffusivity_ud],
            function=self._update_properties)
        self.diffMixLabel = QLabel(self._empty_label)

        # Enthalpy
        self.enthalpyDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.defaultInput.enthalpy_ud],
            function=self._update_properties)
        self.enthalpyLabel = QLabel(self._empty_label)

        # Entropy
        self.entropyDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.defaultInput.entropy_ud],
            function=self._update_properties)
        self.entropyLabel = QLabel(self._empty_label)

        # Specific heat
        self.specificHeatDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.defaultInput.specific_heat_ud],
            function=self._update_properties)
        self.specificHeatLabel = QLabel(self._empty_label)

    def generate_layout(self) -> None:
        """
        Update the interface
        Returns
        -------
        """

        self.row_idx = self.row_idx + 1
        self.addWidget(self.transportLabel, self.row_idx, 0, 1, -1)

        # Density
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Density")), self.row_idx, 0)
        self.addWidget(self.rhoLabel, self.row_idx, 1)
        self.addWidget(self.rhoDropDown, self.row_idx, 2)

        # Molecular weight
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Molecular weight")), self.row_idx, 0)
        self.addWidget(self.mwLabel, self.row_idx, 1)
        self.addWidget(self.mwDropDown, self.row_idx, 2)

        # Viscosity
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Viscosity")), self.row_idx, 0)
        self.addWidget(self.muLabel, self.row_idx, 1)
        self.addWidget(self.muDropDown, self.row_idx, 2)

        # Thermal conductivity
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Thermal conductivity")), self.row_idx, 0)
        self.addWidget(self.condLabel, self.row_idx, 1)
        self.addWidget(self.condDropDown, self.row_idx, 2)

        # Mixture diffusivity
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Mixture diffusivity")), self.row_idx, 0)
        self.addWidget(self.diffMixLabel, self.row_idx, 1)
        self.addWidget(self.diffMixDropDown, self.row_idx, 2)

        self.row_idx = self.row_idx + 1
        self.addWidget(self.thermoLabel, self.row_idx, 0, 1, -1)

        # Enthalpy
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Enthalpy")), self.row_idx, 0)
        self.addWidget(self.enthalpyLabel, self.row_idx, 1)
        self.addWidget(self.enthalpyDropDown, self.row_idx, 2)

        # Entropy
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Entropy")), self.row_idx, 0)
        self.addWidget(self.entropyLabel, self.row_idx, 1)
        self.addWidget(self.entropyDropDown, self.row_idx, 2)

        # Specific heat
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Specific heat")), self.row_idx, 0)
        self.addWidget(self.specificHeatLabel, self.row_idx, 1)
        self.addWidget(self.specificHeatDropDown, self.row_idx, 2)
