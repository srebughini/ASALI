from enum import Enum
from types import SimpleNamespace

from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QPushButton, QGridLayout, QLabel, QComboBox

from src.controllers.label_formatter import LabelFormatter


class PropertiesOutputPageComponents(Enum):
    """
    Class to handle properties output page components names
    """
    GRID = SimpleNamespace(type=QGridLayout,
                           name="gridLayout")

    BACK_BUTTON = SimpleNamespace(type=QPushButton,
                                  name="backButton")

    UPDATE_BUTTON = SimpleNamespace(type=QPushButton,
                                    name="updateButton")

    TRANSPORT_HEADLINE = SimpleNamespace(type=QLabel,
                                         name="transportLabel",
                                         align=Qt.AlignCenter,
                                         style="highlight")

    THERMODYNAMIC_HEADLINE = SimpleNamespace(type=QLabel,
                                             name="thermodynamicLabel",
                                             align=Qt.AlignCenter,
                                             style="highlight")

    DENSITY_VALUE = SimpleNamespace(type=QLabel,
                                    name="rhoValueLabel",
                                    text=LabelFormatter.pad_string("0.0"),
                                    align=Qt.AlignVCenter,
                                    text_interaction=Qt.TextSelectableByMouse)

    VISCOSITY_VALUE = SimpleNamespace(type=QLabel,
                                      name="muValueLabel",
                                      text=LabelFormatter.pad_string("0.0"),
                                      align=Qt.AlignVCenter,
                                      text_interaction=Qt.TextSelectableByMouse)

    THERMAL_CONDUCTIVITY_VALUE = SimpleNamespace(type=QLabel,
                                                 name="condValueLabel",
                                                 text=LabelFormatter.pad_string("0.0"),
                                                 align=Qt.AlignVCenter,
                                                 text_interaction=Qt.TextSelectableByMouse)

    DIFFUSIVITY_VALUE = SimpleNamespace(type=QLabel,
                                        name="diffValueLabel",
                                        text=LabelFormatter.pad_string("0.0"),
                                        align=Qt.AlignVCenter,
                                        text_interaction=Qt.TextSelectableByMouse)

    MOLECULAR_WEIGHT_VALUE = SimpleNamespace(type=QLabel,
                                             name="mwValueLabel",
                                             text=LabelFormatter.pad_string("0.0"),
                                             align=Qt.AlignVCenter,
                                             text_interaction=Qt.TextSelectableByMouse)

    ENTHALPY_VALUE = SimpleNamespace(type=QLabel,
                                     name="hValueLabel",
                                     text=LabelFormatter.pad_string("0.0"),
                                     align=Qt.AlignVCenter,
                                     text_interaction=Qt.TextSelectableByMouse)

    ENTROPY_VALUE = SimpleNamespace(type=QLabel,
                                    name="sValueLabel",
                                    text=LabelFormatter.pad_string("0.0"),
                                    align=Qt.AlignVCenter,
                                    text_interaction=Qt.TextSelectableByMouse)

    SPECIFIC_HEAT_VALUE = SimpleNamespace(type=QLabel,
                                          name="cpValueLabel",
                                          text=LabelFormatter.pad_string("0.0"),
                                          align=Qt.AlignVCenter,
                                          text_interaction=Qt.TextSelectableByMouse)

    DENSITY_UD = SimpleNamespace(type=QComboBox,
                                 name="rhoComboBox")

    VISCOSITY_UD = SimpleNamespace(type=QComboBox,
                                   name="muComboBox")

    THERMAL_CONDUCTIVITY_UD = SimpleNamespace(type=QComboBox,
                                              name="condComboBox")

    DIFFUSIVITY_UD = SimpleNamespace(type=QComboBox,
                                     name="diffComboBox")

    MOLECULAR_WEIGHT_UD = SimpleNamespace(type=QComboBox,
                                          name="mwComboBox")

    ENTHALPY_UD = SimpleNamespace(type=QComboBox,
                                  name="hComboBox")

    ENTROPY_UD = SimpleNamespace(type=QComboBox,
                                 name="sComboBox")

    SPECIFIC_HEAT_UD = SimpleNamespace(type=QComboBox,
                                       name="cpComboBox")
