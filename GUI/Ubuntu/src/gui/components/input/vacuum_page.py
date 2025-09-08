from enum import Enum
from types import SimpleNamespace

from PyQt5.QtCore import Qt
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import QComboBox, QPushButton, QGridLayout, QLineEdit

from src.controllers.edit_lines_validator import EditLinesValidator
from src.core.unit_dimension_handler import UnitDimensionHandler
from src.gui.enums.database_type import DatabaseType

ud_handler = UnitDimensionHandler()


class VacuumInputPageComponents(Enum):
    """
    Class to handle calculation input page components names
    """
    GRID = SimpleNamespace(type=QGridLayout,
                           name="gridLayout")

    DATABASE_SELECTION = SimpleNamespace(type=QComboBox,
                                         name="databaseComboBox",
                                         items=[c.value for c in DatabaseType])

    SPECIE_SELECTION = SimpleNamespace(type=QComboBox,
                                       name="specieComboBox")

    PRESSURE_UD = SimpleNamespace(type=QComboBox,
                                  name="pressureComboBox",
                                  items=ud_handler.pressure_ud)

    TEMPERATURE_UD = SimpleNamespace(type=QComboBox,
                                     name="temperatureComboBox",
                                     items=ud_handler.temperature_ud)

    GEOMETRY_UD = SimpleNamespace(type=QComboBox,
                                  name="geometryComboBox",
                                  items=ud_handler.length_ud)

    NEXT_BUTTON = SimpleNamespace(type=QPushButton,
                                  name="nextButton")

    BACK_BUTTON = SimpleNamespace(type=QPushButton,
                                  name="backButton")

    TEMPERATURE_INPUT = SimpleNamespace(type=QLineEdit,
                                        name="temperatureEditLine",
                                        validator=EditLinesValidator.double_validator(0.0, 3000.0, 2),
                                        align=Qt.AlignRight)

    PRESSURE_INPUT = SimpleNamespace(type=QLineEdit,
                                     name="pressureEditLine",
                                     validator=EditLinesValidator.double_validator(0.0, 1e09, 2),
                                     align=Qt.AlignRight)

    GEOMETRY_INPUT = SimpleNamespace(type=QLineEdit,
                                     name="geometryEditLine",
                                     validator=EditLinesValidator.double_validator(0.0, 1e09, 4),
                                     align=Qt.AlignRight)
