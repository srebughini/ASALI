from enum import Enum
from types import SimpleNamespace

from PySide6.QtCore import Qt
from PySide6.QtGui import QIntValidator
from PySide6.QtWidgets import QComboBox, QPushButton, QLineEdit, QVBoxLayout

from src.controllers.edit_lines_validator import EditLinesValidator
from src.gui.enums.chemkin_editor_action import ChemkinEditorAction


class ChemkinTransportInputPageComponents(Enum):
    """
    Class to handle chemistry input page components names
    """
    VBOX = SimpleNamespace(type=QVBoxLayout,
                           name="verticalLayout")
    ACTION = SimpleNamespace(type=QComboBox,
                             name="actionComboBox",
                             items=[e.value for e in ChemkinEditorAction])

    TRANSPORT_BUTTON = SimpleNamespace(type=QPushButton,
                                       name="transportButton")

    BACK_BUTTON = SimpleNamespace(type=QPushButton,
                                  name="backButton")
    RUN_BUTTON = SimpleNamespace(type=QPushButton,
                                 name="runButton")

    NAME_TRANSPORT_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                               name="nameTransportEditLine",
                                               alignment=Qt.AlignRight)

    GEOMETRY_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                         name="geometryEditLine",
                                         alignment=Qt.AlignRight,
                                         text="0",
                                         validator=QIntValidator(0, 3))

    LJ_POTENTIAL_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                             name="ljpotentialEditLine",
                                             alignment=Qt.AlignRight,
                                             text="0.0",
                                             validator=EditLinesValidator.double_validator(0.0, 10000.0, 3))

    LJ_DIAMETER_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                            name="ljdiameterEditLine",
                                            alignment=Qt.AlignRight,
                                            text="0.0",
                                            validator=EditLinesValidator.double_validator(0.0, 10000.0, 3))

    DIPOLE_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                       name="dipoleEditLine",
                                       alignment=Qt.AlignRight,
                                       text="0.0",
                                       validator=EditLinesValidator.double_validator(0.0, 10000.0, 3))

    POLAR_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                      name="polarEditLine",
                                      alignment=Qt.AlignRight,
                                      text="0.0",
                                      validator=EditLinesValidator.double_validator(0.0, 10000.0, 3))

    COLLISION_EDIT_LINE = SimpleNamespace(type=QLineEdit,
                                          name="collisionEditLine",
                                          alignment=Qt.AlignRight,
                                          text="0.0",
                                          validator=EditLinesValidator.double_validator(0.0, 10000.0, 3))
