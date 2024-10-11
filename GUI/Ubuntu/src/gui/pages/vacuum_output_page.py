from PyQt5 import uic
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import QPushButton, QSizePolicy, QLabel, QComboBox, QLineEdit

from src.controllers.label_formatter import LabelFormatter
from src.core.data_keys import DataKeys
from src.core.vacuum_calculator import vacuum_calculator
from src.gui.config import Config
from src.gui.pages.basic_page import BasicPage


class VacuumOutputPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Vacuum properties output layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        uic.loadUi(Config.VACUUM_OUTPUT_PAGE_PATH.value, self)
        self.update_head_lines()
        self.update_geometry_line()
        self.update_property_line("vValueLabel", "vComboBox", self.ud_handler.velocity_ud)
        self.update_property_line("lValueLabel", "lComboBox", self.ud_handler.length_ud)
        self.update_property_line("diffValueLabel", "diffComboBox", self.ud_handler.diffusivity_ud)
        self.update_property_line("knValueLabel", None, None)
        self.update_buttons()

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.update_specie_line()
        self.update_grid_layout()

    def update_property_line(self, value_label_name, combo_box_name, ud_list) -> None:
        """
        Update property output line
        Parameters
        ----------
        value_label_name: str
            Value label name
        combo_box_name: str | None
            Unit dimension combo box name
        ud_list: list | None
            Unit dimensions

        Returns
        -------

        """
        label = self.findChild(QLabel, value_label_name)
        label.setText(LabelFormatter.pad_string("0.0"))
        label.setAlignment(Qt.AlignVCenter)
        label.setTextInteractionFlags(Qt.TextSelectableByMouse)

        if combo_box_name is not None:
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

    def update_geometry_line(self) -> None:
        """
        Update geometry input line
        Returns
        -------

        """
        edit_line = self.findChild(QLineEdit, 'geometryEditLine')
        edit_line.setValidator(QDoubleValidator(0.0, 1e09, 20))
        edit_line.setAlignment(Qt.AlignRight)

        dropdown = self.findChild(QComboBox, 'geometryComboBox')
        dropdown.addItems(self.ud_handler.length_ud)

    def update_specie_line(self) -> None:
        """
        Update specie input line
        Returns
        -------

        """
        dropdown = self.findChild(QComboBox, 'specieComboBox')
        specie_list = list(self.data_store.get_data(DataKeys.INLET_COMPOSITION.value)[0].keys())
        dropdown.clear()
        dropdown.addItems(specie_list)

    def update_head_lines(self) -> None:
        """
        Update head lines
        Returns
        -------

        """
        label = self.findChild(QLabel, 'inputLabel')
        label.setAlignment(Qt.AlignCenter)
        label.setProperty("class", "highlight")

        label = self.findChild(QLabel, 'outputLabel')
        label.setAlignment(Qt.AlignCenter)
        label.setProperty("class", "highlight")

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        value = float(self.findChild(QLineEdit, 'geometryEditLine').text())
        ud = self.findChild(QComboBox, 'geometryComboBox').currentText()
        self.data_store.update_data(DataKeys.GEOMETRY.value, (value, ud))

        self.data_store.update_data(DataKeys.VACUUM_SPECIE.value,
                                    self.findChild(QComboBox, "specieComboBox").currentText())

        self.data_store.update_data(DataKeys.L.value,
                                    (0.0, self.findChild(QComboBox, 'lComboBox').currentText()))

        self.data_store.update_data(DataKeys.V.value,
                                    (0.0, self.findChild(QComboBox, 'vComboBox').currentText()))

        self.data_store.update_data(DataKeys.DIFF_MIX.value,
                                    (0.0, self.findChild(QComboBox, 'diffComboBox').currentText()))

        self.data_store.update_data(DataKeys.KN.value, 0.0)

    def update_shown_data(self) -> None:
        """
        Update shown data
        Returns
        -------

        """
        self.read_data()
        self.data_store = vacuum_calculator(self.data_store)

        self.update_property_value('lValueLabel', self.data_store.get_data(DataKeys.L.value)[0])
        self.update_property_value('vValueLabel', self.data_store.get_data(DataKeys.V.value)[0])
        self.update_property_value('diffValueLabel', self.data_store.get_data(DataKeys.DIFF_MIX.value)[0])
        self.update_property_value('knValueLabel', self.data_store.get_data(DataKeys.KN.value))

        self.update_grid_layout()
