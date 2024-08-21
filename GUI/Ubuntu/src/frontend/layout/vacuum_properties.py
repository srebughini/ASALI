from PyQt5.QtCore import Qt
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import (
    QMainWindow, QLabel
)

from src.frontend.layout.reactors.vacuum_properties import VacuumProperties
from src.frontend.layout.basic_calculation import BasicCalculationLayout
from src.frontend.style import WidgetStyle
from src.frontend.utils import Utils


class VacuumPropertiesLayout(BasicCalculationLayout):
    def __init__(self, main_window):
        """
        Transport and thermodynamic properties
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        self.inputLabel = None
        self.resultLabel = None
        self.geometryDropDown = None
        self.geometryEditLine = None
        self.speciesDropDown = None
        self.vDropDown = None
        self.vLabel = None
        self.lDropDown = None
        self.lLabel = None
        self.knLabel = None
        self.diffDropDown = None
        self.diffLabel = None

        self._empty_label = Utils.pad_string("")
        super().__init__(main_window)

    def _update_properties(self) -> None:
        """
        Update estimated properties
        Returns
        -------
        """
        geometryValue = 0.0
        if Utils.is_float(self.geometryEditLine.text()):
            geometryValue = float(self.geometryEditLine.text())

        v = self.cl.mean_gas_velocity(self.speciesDropDown.currentText(), self.vDropDown.currentText())
        mfp = self.cl.mean_free_path(self.speciesDropDown.currentText(), self.lDropDown.currentText())
        kn = self.cl.knudsen_number(self.speciesDropDown.currentText(),
                                    geometryValue,
                                    self.geometryDropDown.currentText())
        diff = self.cl.diffusivity(self.speciesDropDown.currentText(),
                                   self.diffDropDown.currentText(),
                                   geometryValue,
                                   self.geometryDropDown.currentText())

        self.vLabel.setText(Utils.pad_string(Utils.from_number_to_string(v)))
        self.lLabel.setText(Utils.pad_string(Utils.from_number_to_string(mfp)))
        self.knLabel.setText(Utils.pad_string(Utils.from_number_to_string(kn)))
        self.diffLabel.setText(Utils.pad_string(Utils.from_number_to_string(diff)))

    def run_backend(self) -> None:
        """
        Run backend to update frontend
        Returns
        -------
        """

        self.cl = self._set_gas_mixture_user_input(VacuumProperties(self.main_window.userInput.file_path,
                                                                    self.main_window.userInput.gas_phase_name))

        self.speciesDropDown.addItems(self.cl.species_names())
        self._update_properties()

    def create_layout_components(self) -> None:
        """
        Initialize the widgets
        Returns
        -------
        """
        # Titles label
        self.inputLabel = QLabel("Input parameters of vacuum conditions")
        self.inputLabel.setStyleSheet(WidgetStyle.HIGHLIGHTLABEL.value)
        self.inputLabel.setAlignment(Qt.AlignCenter)

        self.resultLabel = QLabel("Vacuum properties")
        self.resultLabel.setStyleSheet(WidgetStyle.HIGHLIGHTLABEL.value)
        self.resultLabel.setAlignment(Qt.AlignCenter)

        # Geometry
        self.geometryDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.ud_handler.length_ud],
            function=self._update_properties)
        self.geometryEditLine = self._create_line_edit("0.5",
                                                       Qt.AlignRight,
                                                       QDoubleValidator(),
                                                       function=self._update_properties)

        # Species
        self.speciesDropDown = self._create_dropdown(list(), function=self._update_properties)

        # Mean gas velocity
        self.vDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.ud_handler.velocity_ud],
            function=self._update_properties)
        self.vLabel = QLabel(self._empty_label)

        # Mean free path
        self.lDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.ud_handler.length_ud],
            function=self._update_properties)
        self.lLabel = QLabel(self._empty_label)

        # Knudsen number
        self.knLabel = QLabel(self._empty_label)

        # Diffusivity
        self.diffDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.ud_handler.diffusivity_ud],
            function=self._update_properties)
        self.diffLabel = QLabel(self._empty_label)

    def generate_layout(self) -> None:
        """
        Update the interface
        Returns
        -------
        """
        self.row_idx = self.row_idx + 1
        self.addWidget(self.inputLabel, self.row_idx, 0, 1, -1)

        # Geometry
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Geometry characteristic length:")), self.row_idx, 0)
        self.addWidget(self.geometryEditLine, self.row_idx, 1)
        self.addWidget(self.geometryDropDown, self.row_idx, 2)

        # Species
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Select specie:")), self.row_idx, 0)
        self.addWidget(self.speciesDropDown, self.row_idx, 1, 1, -1)

        self.row_idx = self.row_idx + 1
        self.addWidget(self.resultLabel, self.row_idx, 0, 1, -1)

        # Mean gas velocity
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Mean gas velocity")), self.row_idx, 0)
        self.addWidget(self.vLabel, self.row_idx, 1)
        self.addWidget(self.vDropDown, self.row_idx, 2)

        # Mean free path
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Mean free path")), self.row_idx, 0)
        self.addWidget(self.lLabel, self.row_idx, 1)
        self.addWidget(self.lDropDown, self.row_idx, 2)

        # Mixture diffusivity
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Diffusivity")), self.row_idx, 0)
        self.addWidget(self.diffLabel, self.row_idx, 1)
        self.addWidget(self.diffDropDown, self.row_idx, 2)

        # Mixture diffusivity
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Knudsen number")), self.row_idx, 0)
        self.addWidget(self.knLabel, self.row_idx, 1)
