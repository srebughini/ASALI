from enum import Enum
from types import SimpleNamespace

from PyQt5.QtWidgets import QGridLayout, QComboBox, QPushButton, QWidget

from src.gui.enums.chemkin_editor_action import ChemkinEditorAction


class ChemkinInputPageComponents(Enum):
    """
    Class to handle chemistry input page components names
    """
    GRID = SimpleNamespace(type=QGridLayout,
                           name="gridLayout")

    ACTION = SimpleNamespace(type=QComboBox,
                             name="actionComboBox",
                             items=[e.value for e in ChemkinEditorAction])

    TRANSPORT_BUTTON = SimpleNamespace(type=QPushButton,
                                       name="transportButton")
    THERMO_BUTTON = SimpleNamespace(type=QPushButton,
                                    name="thermoButton")
    SURFACE_BUTTON = SimpleNamespace(type=QPushButton,
                                     name="surfaceButton")
    KINETIC_BUTTON = SimpleNamespace(type=QPushButton,
                                     name="kineticButton")

    TRANSPORT_WIDGET = SimpleNamespace(type=QWidget,
                                       name="transportWidget")

    THERMO_WIDGET = SimpleNamespace(type=QWidget,
                                    name="thermoWidget")
