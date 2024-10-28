from PyQt5.QtCore import Qt, pyqtSignal
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import QPushButton, QGridLayout, QLineEdit, QComboBox, QLabel, QSizePolicy
from PyQt5 import uic

from src.core.data_keys import DataKeys
from src.core.properties_calculator import properties_calculator
from src.core.species_names import get_random_specie_name
from src.gui.config import Config
from src.gui.pages.basic_page import BasicPage


class CalculationInputPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Calculation input page layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        uic.loadUi(Config.CALCULATION_INPUT_PAGE_PATH.value, self)

        self.data_store.update_data(DataKeys.INLET_NS.value, 0)

        self.update_temperature_line()
        self.update_pressure_line()
        self.update_buttons()
        self.update_specie_line()
        self.update_grid_layout()

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.update_grid_layout()

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        # Temperature
        value = float(self.findChild(QLineEdit, 'temperatureEditLine').text())
        ud = self.findChild(QComboBox, 'temperatureComboBox').currentText()
        self.data_store.update_data(DataKeys.INLET_T.value, (value, ud))

        # Pressure
        value = float(self.findChild(QLineEdit, 'pressureEditLine').text())
        ud = self.findChild(QComboBox, 'pressureComboBox').currentText()
        self.data_store.update_data(DataKeys.INLET_P.value, (value, ud))

        # Composition
        value = {self.findChild(QLineEdit, f"n{i}").text(): float(self.findChild(QLineEdit, f"x{i}").text()) for i in
                 range(0, self.data_store.get_data(DataKeys.INLET_NS.value) + 1)}
        ud = self.findChild(QComboBox, 'compositionComboBox').currentText()
        self.data_store.update_data(DataKeys.INLET_GAS_COMPOSITION.value, (value, ud))

    def update_temperature_line(self) -> None:
        """
        Update temperature input line
        Returns
        -------

        """
        edit_line = self.findChild(QLineEdit, 'temperatureEditLine')
        edit_line.setValidator(QDoubleValidator(0.0, 3000.0, 2))
        edit_line.setAlignment(Qt.AlignRight)

        dropdown = self.findChild(QComboBox, 'temperatureComboBox')
        dropdown.addItems(self.ud_handler.temperature_ud)

    def update_pressure_line(self) -> None:
        """
        Update pressure input line
        Returns
        -------

        """
        edit_line = self.findChild(QLineEdit, 'pressureEditLine')
        edit_line.setValidator(QDoubleValidator(0.0, 1e09, 2))
        edit_line.setAlignment(Qt.AlignRight)

        dropdown = self.findChild(QComboBox, 'pressureComboBox')
        dropdown.addItems(self.ud_handler.pressure_ud)

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        back_button = self.findChild(QPushButton, 'backButton')
        back_button.clicked.connect(lambda: self.page_switched.emit(Config.CHEMISTRY_INPUT_PAGE_NAME.value))

        add_specie_button = self.findChild(QPushButton, 'addSpecieButton')
        add_specie_button.clicked.connect(self.add_specie_line)

        next_button = self.findChild(QPushButton, 'nextButton')
        next_button.clicked.connect(self.next_button_action)

    def update_specie_line(self) -> None:
        """
        Update specie line
        Returns
        -------

        """
        ns = self.data_store.get_data(DataKeys.INLET_NS.value)
        edit_line = self.findChild(QLineEdit, f"x{ns}")
        edit_line.setValidator(QDoubleValidator(0.0, 1.0, 4))

    def move_buttons(self, grid_layout, new_row) -> None:
        """
        Move the buttons from their current row to a new row.
        Parameters
        ----------
        grid_layout: QGridLayout
            Grid Layout
        new_row : int
            The new row to place the buttons in.
        """
        # Find the buttons in the old row
        back_button = self.findChild(QPushButton, 'backButton')
        add_specie_button = self.findChild(QPushButton, 'addSpecieButton')
        next_button = self.findChild(QPushButton, 'nextButton')

        # Remove buttons from the old row
        grid_layout.removeWidget(back_button)
        grid_layout.removeWidget(add_specie_button)
        grid_layout.removeWidget(next_button)

        # Add buttons to the new row
        grid_layout.addWidget(back_button, new_row, 0)
        grid_layout.addWidget(add_specie_button, new_row, 1)
        grid_layout.addWidget(next_button, new_row, 2)

    def add_specie_line(self) -> None:
        """
        Add specie line to the layout
        Returns
        -------

        """
        ns = self.data_store.get_data(DataKeys.INLET_NS.value) + 1
        self.data_store.update_data(DataKeys.INLET_NS.value, ns)

        label = QLabel(f'Specie #{ns}')
        formula_edit_line = QLineEdit()
        formula_edit_line.setObjectName(f"n{ns}")
        formula_edit_line.setText(get_random_specie_name(self.data_store))

        composition_edit_line = QLineEdit()
        composition_edit_line.setObjectName(f"x{ns}")
        composition_edit_line.setValidator(QDoubleValidator(0.0, 1.0, 4))
        composition_edit_line.setText("0.0")

        grid_layout = self.findChild(QGridLayout, "gridLayout")
        specie_row = grid_layout.rowCount()

        grid_layout.addWidget(label, specie_row, 0)
        grid_layout.addWidget(formula_edit_line, specie_row, 1)
        grid_layout.addWidget(composition_edit_line, specie_row, 2)

        button_row = specie_row + 1
        self.move_buttons(grid_layout, button_row)

        self.update_grid_layout()

    def next_button_action(self) -> pyqtSignal:
        """
        Action related to the next button
        Returns
        -------
        signal: pyqtSignal
            Signal with the next page name
        """
        self.read_data()

        combo_box = self.findChild(QComboBox, 'chemistryComboBox')
        if combo_box.currentIndex() == 0:
            # Thermodynamic and transport properties
            return self.page_switched.emit(Config.PROPERTIES_OUTPUT_PAGE_NAME.value)

        elif combo_box.currentIndex() == 1:
            # Vacuum properties
            return self.page_switched.emit(Config.VACUUM_OUTPUT_PAGE_NAME.value)

        elif combo_box.currentIndex() == 2:
            # Chemical equilibrium
            return self.page_switched.emit(Config.EQUILIBRIUM_OUTPUT_PAGE_NAME.value)
        elif combo_box.currentIndex() == 3:
            # Batch
            return self.page_switched.emit(Config.BATCH_INPUT_PAGE_NAME.value)
        elif combo_box.currentIndex() == 4:
            # CSTR
            pass
        elif combo_box.currentIndex() == 5:
            # SS 1d ph
            pass
        elif combo_box.currentIndex() == 6:
            # Transient 1d ph
            pass
        elif combo_box.currentIndex() == 7:
            # SS 1d het
            pass
        elif combo_box.currentIndex() == 8:
            # Transient 1d het
            pass
