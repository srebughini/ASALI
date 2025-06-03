from enum import Enum
from types import SimpleNamespace

from PyQt5.QtWidgets import QGridLayout, QComboBox, QPushButton, QWidget

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
