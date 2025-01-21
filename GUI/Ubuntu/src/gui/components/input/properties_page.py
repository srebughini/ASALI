from enum import Enum
from types import SimpleNamespace

from PyQt5.QtCore import Qt
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import QComboBox, QPushButton, QGridLayout, QLineEdit, QHBoxLayout


class PropertiesInputPageComponents(Enum):
    """
    Class to handle calculation input page components names
    """
    GRID = SimpleNamespace(type=QGridLayout,
                           name="gridLayout")

    DATABASE_SELECTION = SimpleNamespace(type=QComboBox,
                                         name="databaseComboBox")

    COMPOSITION_SELECTION = SimpleNamespace(type=QComboBox,
                                            name="compositionComboBox")

    PRESSURE_UD = SimpleNamespace(type=QComboBox,
                                  name="pressureComboBox")

    TEMPERATURE_UD = SimpleNamespace(type=QComboBox,
                                     name="temperatureComboBox")

    NEXT_BUTTON = SimpleNamespace(type=QPushButton,
                                  name="nextButton")

    BACK_BUTTON = SimpleNamespace(type=QPushButton,
                                  name="backButton")

    ADD_GAS_BUTTON = SimpleNamespace(type=QPushButton,
                                     name="addSpecieButton")

    REMOVE_GAS_BUTTON = SimpleNamespace(type=QPushButton,
                                        name="removeSpecieButton")

    TEMPERATURE_INPUT = SimpleNamespace(type=QLineEdit,
                                        name="temperatureEditLine",
                                        validator=QDoubleValidator(0.0, 3000.0, 2),
                                        align=Qt.AlignRight)

    PRESSURE_INPUT = SimpleNamespace(type=QLineEdit,
                                     name="pressureEditLine",
                                     validator=QDoubleValidator(0.0, 1e09, 2),
                                     align=Qt.AlignRight)

    BUTTON_LAYOUT = SimpleNamespace(type=QHBoxLayout,
                                    name="buttonLayout")

    GAS_SPECIES_LAYOUT = SimpleNamespace(type=QGridLayout,
                                         name="speciesLayout")
