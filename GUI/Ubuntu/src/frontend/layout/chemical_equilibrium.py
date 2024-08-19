from PyQt5.QtWidgets import (
    QMainWindow, QLabel
)

from src.backend.chemical_equilibrium import ChemicalEquilibrium
from src.frontend.layout.basic_calculation import BasicCalculationLayout
from src.frontend.utils import Utils


class ChemicalEquilibriumLayout(BasicCalculationLayout):
    def __init__(self, main_window):
        """
        Transport and thermodynamic properties
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        self.eqDropDown = None
        self.temperatureUdDropDown = None
        self.pressureUdDropDown = None
        self.temperatureLabel = None
        self.pressureLabel = None
        self.xLabel = None
        self.yLabel =None
        self.nLabel = None
        self.cl = None

        self._empty_label = Utils.pad_string("")
        super().__init__(main_window)

    def _update_properties(self) -> None:
        """
        Update estimated properties
        Returns
        -------
        """
        self.cl.equilibrate(self.main_window.defaultInput.from_human_eq_to_code_eq(self.eqDropDown.currentText()))

        T = self.cl.temperature(self.temperatureUdDropDown.currentText())
        P = self.cl.pressure(self.pressureUdDropDown.currentText())
        x = list(self.cl.mole_fraction().values())
        y = list(self.cl.mass_fraction().values())
        n = self.cl.species_names()

        self.temperatureLabel.setText(Utils.pad_string(Utils.from_number_to_string(T)))
        self.pressureLabel.setText(Utils.pad_string(Utils.from_number_to_string(P)))
        self.nLabel.setText("\n".join(n))
        self.xLabel.setText(Utils.from_list_to_string(x))
        self.yLabel.setText(Utils.from_list_to_string(y))

    def run_backend(self) -> None:
        """
        Run backend to update frontend
        Returns
        -------

        """
        self.cl = self._set_gas_mixture_user_input(ChemicalEquilibrium(self.main_window.userInput.file_path,
                                                                       self.main_window.userInput.gas_phase_name))
        self._update_properties()

    def create_layout_components(self) -> None:
        """
        Initialize the widgets
        Returns
        -------

        """
        self.eqDropDown = self._create_dropdown(
            [Utils.pad_string(op) for op in self.main_window.defaultInput.human_chemical_equilibrium_options],
            function=self._update_properties)

        self.temperatureUdDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.defaultInput.temperature_ud],
            function=None)

        self.pressureUdDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.defaultInput.pressure_ud],
            function=None)

        self.temperatureLabel = QLabel(self._empty_label)
        self.pressureLabel = QLabel(self._empty_label)
        self.xLabel = QLabel(self._empty_label)
        self.yLabel = QLabel(self._empty_label)
        self.nLabel = QLabel(self._empty_label)

    def generate_layout(self) -> None:
        """
        Update the interface
        Returns
        -------
        """
        self.row_idx = self.row_idx + 1
        self.addWidget(self.eqDropDown, self.row_idx, 0, 1, -1)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Temperature:")), self.row_idx, 0)
        self.addWidget(self.temperatureLabel, self.row_idx, 1)
        self.addWidget(self.temperatureUdDropDown, self.row_idx, 2)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Pressure:")), self.row_idx, 0)
        self.addWidget(self.pressureLabel, self.row_idx, 1)
        self.addWidget(self.pressureUdDropDown, self.row_idx, 2)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel(Utils.pad_string("Mass fraction")), self.row_idx, 1)
        self.addWidget(QLabel(Utils.pad_string("Mole fraction")), self.row_idx, 2)

        self.row_idx = self.row_idx + 1
        self.addWidget(self.nLabel, self.row_idx, 0)
        self.addWidget(self.yLabel, self.row_idx, 1)
        self.addWidget(self.xLabel, self.row_idx, 2)
