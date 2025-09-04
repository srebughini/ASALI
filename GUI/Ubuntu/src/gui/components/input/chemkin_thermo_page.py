from enum import Enum
from types import SimpleNamespace

from PyQt5.QtCore import Qt
from PyQt5.QtGui import QIntValidator
from PyQt5.QtWidgets import QComboBox, QPushButton, QLineEdit, QGridLayout

from src.controllers.chemkin_file_controller import ThermoPhases
from src.controllers.edit_lines_validators import EditLinesValidator
from src.gui.enums.chemkin_editor_action import ChemkinEditorAction


class ChemkinThermoInputPageComponents(Enum):
    """
    Class to handle chemistry input page components names
    """
    ACTION = SimpleNamespace(type=QComboBox,
                             name="actionComboBox",
                             items=[e.value for e in ChemkinEditorAction])

    THERMO_BUTTON = SimpleNamespace(type=QPushButton,
                                    name="thermoButton")

    BACK_BUTTON = SimpleNamespace(type=QPushButton,
                                  name="backButton")
    RUN_BUTTON = SimpleNamespace(type=QPushButton,
                                 name="runButton")

    ADD_ELEMENT_BUTTON = SimpleNamespace(type=QPushButton,
                                         name="addElementButton")

    REMOVE_ELEMENT_BUTTON = SimpleNamespace(type=QPushButton,
                                            name="removeElementButton")

    ELEMENT_LAYOUT = SimpleNamespace(type=QGridLayout,
                                     name="elementLayout")

    NAME_THERMO_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                            name="nameThermoEditLine",
                                            alignment=Qt.AlignRight)

    HIGH_TEMPERATURE_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                                 name="highTemperatureEditLine",
                                                 alignment=Qt.AlignRight,
                                                 text="0.0",
                                                 validator=EditLinesValidator.double_validator(0.0, 10000.0, 3))

    LOW_TEMPERATURE_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                                name="lowTemperatureEditLine",
                                                alignment=Qt.AlignRight,
                                                text="0.0",
                                                validator=EditLinesValidator.double_validator(0.0, 10000.0, 3))

    COMMON_TEMPERATURE_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                                   name="commonTemperatureEditLine",
                                                   alignment=Qt.AlignRight,
                                                   text="0.0",
                                                   validator=EditLinesValidator.double_validator(0.0, 10000.0, 3))

    A1_UPPER_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                         name="a1upperEditLine",
                                         alignment=Qt.AlignRight,
                                         text="0.0",
                                         validator=EditLinesValidator.double_validator(-1.0e30, 1.0e30, 12))

    A2_UPPER_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                         name="a2upperEditLine",
                                         alignment=Qt.AlignRight,
                                         text="0.0",
                                         validator=EditLinesValidator.double_validator(-1.0e30, 1.0e30, 12))

    A3_UPPER_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                         name="a3upperEditLine",
                                         alignment=Qt.AlignRight,
                                         text="0.0",
                                         validator=EditLinesValidator.double_validator(-1.0e30, 1.0e30, 12))

    A4_UPPER_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                         name="a4upperEditLine",
                                         alignment=Qt.AlignRight,
                                         text="0.0",
                                         validator=EditLinesValidator.double_validator(-1.0e30, 1.0e30, 12))

    A5_UPPER_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                         name="a5upperEditLine",
                                         alignment=Qt.AlignRight,
                                         text="0.0",
                                         validator=EditLinesValidator.double_validator(-1.0e30, 1.0e30, 12))

    A6_UPPER_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                         name="a6upperEditLine",
                                         alignment=Qt.AlignRight,
                                         text="0.0",
                                         validator=EditLinesValidator.double_validator(-1.0e30, 1.0e30, 12))

    A7_UPPER_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                         name="a7upperEditLine",
                                         alignment=Qt.AlignRight,
                                         text="0.0",
                                         validator=EditLinesValidator.double_validator(-1.0e30, 1.0e30, 12))

    A1_LOWER_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                         name="a1lowerEditLine",
                                         alignment=Qt.AlignRight,
                                         text="0.0",
                                         validator=EditLinesValidator.double_validator(-1.0e30, 1.0e30, 12))

    A2_LOWER_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                         name="a2lowerEditLine",
                                         alignment=Qt.AlignRight,
                                         text="0.0",
                                         validator=EditLinesValidator.double_validator(-1.0e30, 1.0e30, 12))

    A3_LOWER_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                         name="a3lowerEditLine",
                                         alignment=Qt.AlignRight,
                                         text="0.0",
                                         validator=EditLinesValidator.double_validator(-1.0e30, 1.0e30, 12))

    A4_LOWER_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                         name="a4lowerEditLine",
                                         alignment=Qt.AlignRight,
                                         text="0.0",
                                         validator=EditLinesValidator.double_validator(-1.0e30, 1.0e30, 12))

    A5_LOWER_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                         name="a5lowerEditLine",
                                         alignment=Qt.AlignRight,
                                         text="0.0",
                                         validator=EditLinesValidator.double_validator(-1.0e30, 1.0e30, 12))

    A6_LOWER_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                         name="a6lowerEditLine",
                                         alignment=Qt.AlignRight,
                                         text="0.0",
                                         validator=EditLinesValidator.double_validator(-1.0e30, 1.0e30, 12))

    A7_LOWER_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                         name="a7lowerEditLine",
                                         alignment=Qt.AlignRight,
                                         text="0.0",
                                         validator=EditLinesValidator.double_validator(-1.0e30, 1.0e30, 12))

    PHASE_COMBO_BOX = SimpleNamespace(type=QComboBox,
                                      name="phaseComboBox",
                                      items_enum=ThermoPhases)
