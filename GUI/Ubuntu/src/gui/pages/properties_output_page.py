from PyQt5 import uic
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QLabel, QComboBox, QPushButton, QSizePolicy

from src.controllers.label_formatter import LabelFormatter
from src.core.data_keys import DataKeys
from src.core.properties_calculator import properties_calculator
from src.gui.config import Config
from src.gui.pages.basic_page import BasicPage


class PropertiesOutputPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Thermodynamic and transport properties output layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        uic.loadUi(Config.PROPERTIES_OUTPUT_PAGE_PATH.value, self)

        self.update_head_lines()
        self.update_property_line("rhoValueLabel", "rhoComboBox", self.ud_handler.density_ud)
        self.update_property_line("muValueLabel", "muComboBox", self.ud_handler.viscosity_ud)
        self.update_property_line("condValueLabel", "condComboBox", self.ud_handler.thermal_conductivity_ud)
        self.update_property_line("diffValueLabel", "diffComboBox", self.ud_handler.diffusivity_ud)
        self.update_property_line("mwValueLabel", "mwComboBox", self.ud_handler.molecular_weight_ud)
        self.update_property_line("hValueLabel", "hComboBox", self.ud_handler.enthalpy_ud)
        self.update_property_line("sValueLabel", "sComboBox", self.ud_handler.entropy_ud)
        self.update_property_line("cpValueLabel", "cpComboBox", self.ud_handler.specific_heat_ud)
        self.update_buttons()

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.update_grid_layout()

    def update_property_line(self, value_label_name, combo_box_name, ud_list) -> None:
        """
        Update property output line
        Parameters
        ----------
        value_label_name: str
            Value label name
        combo_box_name: str
            Unit dimension combo box name
        ud_list: list
            Unit dimensions

        Returns
        -------

        """
        label = self.findChild(QLabel, value_label_name)
        label.setText(LabelFormatter.pad_string("0.0"))
        label.setAlignment(Qt.AlignVCenter)
        label.setTextInteractionFlags(Qt.TextSelectableByMouse)

        dropdown = self.findChild(QComboBox, combo_box_name)
        dropdown.addItems(ud_list)
        dropdown.currentIndexChanged.connect(self.update_shown_data)

    def update_property_value(self, value_label_name, value):
        """
        Update property value
        Parameters
        ----------
        value_label_name
        value

        Returns
        -------

        """
        if isinstance(value, float):
            label = self.findChild(QLabel, value_label_name)
            label.setText(LabelFormatter.float_to_string(value))

        if isinstance(value, dict):
            label = self.findChild(QLabel, value_label_name)
            label.setText(LabelFormatter.dict_to_string(value))

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

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        self.data_store.update_data(DataKeys.RHO.value,
                                    (0.0, self.findChild(QComboBox, 'rhoComboBox').currentText()))
        self.data_store.update_data(DataKeys.MU.value,
                                    (0.0, self.findChild(QComboBox, 'muComboBox').currentText()))
        self.data_store.update_data(DataKeys.MW.value,
                                    (0.0, self.findChild(QComboBox, 'mwComboBox').currentText()))
        self.data_store.update_data(DataKeys.COND.value,
                                    (0.0, self.findChild(QComboBox, 'condComboBox').currentText()))
        self.data_store.update_data(DataKeys.DIFF_MIX.value,
                                    (0.0, self.findChild(QComboBox, 'diffComboBox').currentText()))
        self.data_store.update_data(DataKeys.H.value,
                                    (0.0, self.findChild(QComboBox, 'hComboBox').currentText()))
        self.data_store.update_data(DataKeys.S.value,
                                    (0.0, self.findChild(QComboBox, 'sComboBox').currentText()))
        self.data_store.update_data(DataKeys.CP.value,
                                    (0.0, self.findChild(QComboBox, 'cpComboBox').currentText()))

    def update_shown_data(self) -> None:
        """
        Update shown data
        Returns
        -------

        """
        self.read_data()
        self.data_store = properties_calculator(self.data_store)

        self.update_property_value('rhoValueLabel', self.data_store.get_data(DataKeys.RHO.value)[0])
        self.update_property_value('condValueLabel', self.data_store.get_data(DataKeys.COND.value)[0])
        self.update_property_value('mwValueLabel', self.data_store.get_data(DataKeys.MW.value)[0])
        self.update_property_value('muValueLabel', self.data_store.get_data(DataKeys.MU.value)[0])
        self.update_property_value('diffValueLabel', self.data_store.get_data(DataKeys.DIFF_MIX.value)[0])
        self.update_property_value('hValueLabel', self.data_store.get_data(DataKeys.H.value)[0])
        self.update_property_value('sValueLabel', self.data_store.get_data(DataKeys.S.value)[0])
        self.update_property_value('cpValueLabel', self.data_store.get_data(DataKeys.CP.value)[0])

        self.update_grid_layout()
