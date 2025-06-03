from enum import Enum
from types import SimpleNamespace

from PyQt5.QtWidgets import QGridLayout, QComboBox, QPushButton, QWidget

from src.gui.enums.chemkin_editor_action import ChemkinEditorAction


class ChemkinTransportInputPageComponents(Enum):
    """
    Class to handle chemistry input page components names
    """
    ACTION = SimpleNamespace(type=QComboBox,
                             name="actionComboBox",
                             items=[e.value for e in ChemkinEditorAction])

    TRANSPORT_BUTTON = SimpleNamespace(type=QPushButton,
                                       name="transportButton")

    BACK_BUTTON = SimpleNamespace(type=QPushButton,
                                  name="backButton")
    RUN_BUTTON = SimpleNamespace(type=QPushButton,
                                 name="runButton")
