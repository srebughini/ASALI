from enum import Enum
from types import SimpleNamespace

from PySide6.QtCore import Qt
from PySide6.QtWidgets import QComboBox, QPushButton, QGridLayout, QLineEdit

from src.controllers.edit_lines_validator import EditLinesValidator
from src.core.unit_dimension_handler import UnitDimensionHandler
from src.gui.enums.composition_type import CompositionType
from src.gui.enums.database_type import DatabaseType

ud_handler = UnitDimensionHandler()


class EquilibriumInputPageComponents(Enum):
    """
    Class to handle calculation input page components names
    """
    GRID = SimpleNamespace(type=QGridLayout,
                           name="gridLayout")

    DATABASE_SELECTION = SimpleNamespace(type=QComboBox,
                                         name="databaseComboBox",
                                         items=[c.value for c in DatabaseType])

    COMPOSITION_SELECTION = SimpleNamespace(type=QComboBox,
                                            name="compositionComboBox",
                                            items=[c.value for c in CompositionType])

    PRESSURE_UD = SimpleNamespace(type=QComboBox,
                                  name="pressureComboBox",
                                  items=ud_handler.pressure_ud)

    TEMPERATURE_UD = SimpleNamespace(type=QComboBox,
                                     name="temperatureComboBox",
                                     items=ud_handler.temperature_ud)

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
                                        validator=EditLinesValidator.double_validator(0.0, 3000.0, 2),
                                        align=Qt.AlignRight)

    PRESSURE_INPUT = SimpleNamespace(type=QLineEdit,
                                     name="pressureEditLine",
                                     validator=EditLinesValidator.double_validator(0.0, 1e09, 2),
                                     align=Qt.AlignRight)

    GAS_SPECIES_LAYOUT = SimpleNamespace(type=QGridLayout,
                                         name="speciesLayout")
