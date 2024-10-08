from PyQt5 import uic
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QLabel, QComboBox, QPushButton, QSizePolicy

from src.controllers.label_formatter import LabelFormatter
from src.core.data_keys import DataKeys
from src.core.properties_calculator import properties_calculator
from src.gui.config import Config
from src.gui.pages.basic_page import BasicPage


class PropertiesOutputPage(BasicPage):
    def __init__(self, data_store):
        """
        Thermodynamic and transport properties output layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        """
        super().__init__(data_store)
        # Load the UI from the .ui file
        uic.loadUi(Config.PROPERTIES_OUTPUT_PAGE_PATH.value, self)

        self.update_head_lines()
        self.update_density_line()
        self.update_viscosity_line()
        self.update_molecular_weight_line()
        self.update_thermal_conductivity_line()
        self.update_mixture_diffusivity_line()
        self.update_entropy_line()
        self.update_enthalpy_line()
        self.update_specific_heat_line()
        self.update_buttons()
        self.update_grid_layout()

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        back_button = self.findChild(QPushButton, 'backButton')
        back_button.clicked.connect(lambda: self.page_switched.emit(Config.CALCULATION_INPUT_PAGE_NAME.value))
        back_button.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)

        calculate_button = self.findChild(QPushButton, 'calculateButton')
        calculate_button.clicked.connect(self.update_shown_data)
        calculate_button.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)

    def update_data_store(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        # Density
        ud = self.findChild(QComboBox, 'rhoComboBox').currentText()
        self.data_store.update_data(DataKeys.RHO.value, (0.0, ud))

        # Viscosity
        ud = self.findChild(QComboBox, 'muComboBox').currentText()
        self.data_store.update_data(DataKeys.MU.value, (0.0, ud))

        # Molecular weight
        ud = self.findChild(QComboBox, 'mwComboBox').currentText()
        self.data_store.update_data(DataKeys.MW.value, (0.0, ud))

        # Thermal conductivity
        ud = self.findChild(QComboBox, 'condComboBox').currentText()
        self.data_store.update_data(DataKeys.COND.value, (0.0, ud))

        # Mixture diffusivity
        ud = self.findChild(QComboBox, 'diffComboBox').currentText()
        self.data_store.update_data(DataKeys.DIFF_MIX.value, (0.0, ud))

        # Enthalpy
        ud = self.findChild(QComboBox, 'hComboBox').currentText()
        self.data_store.update_data(DataKeys.H.value, (0.0, ud))

        # Entropy
        ud = self.findChild(QComboBox, 'sComboBox').currentText()
        self.data_store.update_data(DataKeys.S.value, (0.0, ud))

        # Specific heat
        ud = self.findChild(QComboBox, 'cpComboBox').currentText()
        self.data_store.update_data(DataKeys.CP.value, (0.0, ud))

    def update_head_lines(self) -> None:
        """
        Update head lines
        Returns
        -------

        """
        label = self.findChild(QLabel, 'transportLabel')
        label.setAlignment(Qt.AlignCenter)
        label.setProperty("class", "highlight")

        label = self.findChild(QLabel, 'thermodynamicLabel')
        label.setAlignment(Qt.AlignCenter)
        label.setProperty("class", "highlight")

    def update_density_line(self) -> None:
        """
        Update density line
        Returns
        -------

        """
        label = self.findChild(QLabel, 'rhoValueLabel')
        label.setText(LabelFormatter.pad_string("0.0"))
        label.setAlignment(Qt.AlignVCenter)
        label.setTextInteractionFlags(Qt.TextSelectableByMouse)

        dropdown = self.findChild(QComboBox, 'rhoComboBox')
        dropdown.addItems(self.ud_handler.density_ud)
        dropdown.currentIndexChanged.connect(self.update_shown_data)

    def update_viscosity_line(self) -> None:
        """
        Update viscosity line
        Returns
        -------

        """
        label = self.findChild(QLabel, 'muValueLabel')
        label.setText(LabelFormatter.pad_string("0.0"))
        label.setAlignment(Qt.AlignVCenter)
        label.setTextInteractionFlags(Qt.TextSelectableByMouse)

        dropdown = self.findChild(QComboBox, 'muComboBox')
        dropdown.addItems(self.ud_handler.viscosity_ud)
        dropdown.currentIndexChanged.connect(self.update_shown_data)

    def update_thermal_conductivity_line(self) -> None:
        """
        Update thermal conductivity line
        Returns
        -------

        """
        label = self.findChild(QLabel, 'condValueLabel')
        label.setText(LabelFormatter.pad_string("0.0"))
        label.setAlignment(Qt.AlignVCenter)
        label.setTextInteractionFlags(Qt.TextSelectableByMouse)

        dropdown = self.findChild(QComboBox, 'condComboBox')
        dropdown.addItems(self.ud_handler.thermal_conductivity_ud)
        dropdown.currentIndexChanged.connect(self.update_shown_data)

    def update_molecular_weight_line(self) -> None:
        """
        Update molecular weight line
        Returns
        -------

        """
        label = self.findChild(QLabel, 'mwValueLabel')
        label.setText(LabelFormatter.pad_string("0.0"))
        label.setAlignment(Qt.AlignVCenter)
        label.setTextInteractionFlags(Qt.TextSelectableByMouse)

        dropdown = self.findChild(QComboBox, 'mwComboBox')
        dropdown.addItems(self.ud_handler.molecular_weight_ud)
        dropdown.currentIndexChanged.connect(self.update_shown_data)

    def update_mixture_diffusivity_line(self) -> None:
        """
        Update mixture diffusivity line
        Returns
        -------

        """
        label = self.findChild(QLabel, 'diffValueLabel')
        label.setText(LabelFormatter.pad_string("0.0"))
        label.setAlignment(Qt.AlignVCenter)
        label.setTextInteractionFlags(Qt.TextSelectableByMouse)

        dropdown = self.findChild(QComboBox, 'diffComboBox')
        dropdown.addItems(self.ud_handler.diffusivity_ud)
        dropdown.currentIndexChanged.connect(self.update_shown_data)

    def update_enthalpy_line(self) -> None:
        """
        Update enthalpy line
        Returns
        -------

        """
        label = self.findChild(QLabel, 'hValueLabel')
        label.setText(LabelFormatter.pad_string("0.0"))
        label.setAlignment(Qt.AlignVCenter)
        label.setTextInteractionFlags(Qt.TextSelectableByMouse)

        dropdown = self.findChild(QComboBox, 'hComboBox')
        dropdown.addItems(self.ud_handler.enthalpy_ud)
        dropdown.currentIndexChanged.connect(self.update_shown_data)

    def update_entropy_line(self) -> None:
        """
        Update entropy line
        Returns
        -------

        """
        label = self.findChild(QLabel, 'sValueLabel')
        label.setText(LabelFormatter.pad_string("0.0"))
        label.setAlignment(Qt.AlignVCenter)
        label.setTextInteractionFlags(Qt.TextSelectableByMouse)

        dropdown = self.findChild(QComboBox, 'sComboBox')
        dropdown.addItems(self.ud_handler.entropy_ud)
        dropdown.currentIndexChanged.connect(self.update_shown_data)

    def update_specific_heat_line(self) -> None:
        """
        Update specific heat line
        Returns
        -------

        """
        label = self.findChild(QLabel, 'cpValueLabel')
        label.setText(LabelFormatter.pad_string("0.0"))
        label.setAlignment(Qt.AlignVCenter)
        label.setTextInteractionFlags(Qt.TextSelectableByMouse)

        dropdown = self.findChild(QComboBox, 'cpComboBox')
        dropdown.addItems(self.ud_handler.specific_heat_ud)
        dropdown.currentIndexChanged.connect(self.update_shown_data)

    def update_shown_data(self) -> None:
        """
        Update shown data
        Returns
        -------

        """
        self.update_data_store()
        self.data_store = properties_calculator(self.data_store)

        value = self.data_store.get_data(DataKeys.RHO.value)[0]
        self.findChild(QLabel, 'rhoValueLabel').setText(LabelFormatter.float_to_string(value))

        value = self.data_store.get_data(DataKeys.COND.value)[0]
        self.findChild(QLabel, 'condValueLabel').setText(LabelFormatter.float_to_string(value))

        value = self.data_store.get_data(DataKeys.MW.value)[0]
        self.findChild(QLabel, 'mwValueLabel').setText(LabelFormatter.float_to_string(value))

        value = self.data_store.get_data(DataKeys.MU.value)[0]
        self.findChild(QLabel, 'muValueLabel').setText(LabelFormatter.float_to_string(value))

        value = self.data_store.get_data(DataKeys.DIFF_MIX.value)[0]
        self.findChild(QLabel, 'diffValueLabel').setText(LabelFormatter.dict_to_string(value))

        value = self.data_store.get_data(DataKeys.H.value)[0]
        self.findChild(QLabel, 'hValueLabel').setText(LabelFormatter.float_to_string(value))

        value = self.data_store.get_data(DataKeys.S.value)[0]
        self.findChild(QLabel, 'sValueLabel').setText(LabelFormatter.float_to_string(value))

        value = self.data_store.get_data(DataKeys.CP.value)[0]
        self.findChild(QLabel, 'cpValueLabel').setText(LabelFormatter.float_to_string(value))

        self.update_grid_layout()
