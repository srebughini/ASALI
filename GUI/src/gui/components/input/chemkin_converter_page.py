from enum import Enum
from types import SimpleNamespace

from PySide6.QtWidgets import QComboBox, QPushButton, QVBoxLayout

from src.gui.enums.chemkin_editor_action import ChemkinEditorAction


class ChemkinConverterInputPageComponents(Enum):
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
    THERMO_BUTTON = SimpleNamespace(type=QPushButton,
                                    name="thermoButton")
    SURFACE_BUTTON = SimpleNamespace(type=QPushButton,
                                     name="surfaceButton")
    KINETIC_BUTTON = SimpleNamespace(type=QPushButton,
                                     name="kineticButton")

    BACK_BUTTON = SimpleNamespace(type=QPushButton,
                                  name="backButton")
    RUN_BUTTON = SimpleNamespace(type=QPushButton,
                                 name="runButton")