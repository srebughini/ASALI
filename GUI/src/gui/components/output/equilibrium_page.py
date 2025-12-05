from enum import Enum
from types import SimpleNamespace

from PySide6.QtCore import Qt
from PySide6.QtWidgets import QGridLayout, QPushButton, QLabel, QComboBox

from src.controllers.label_formatter import LabelFormatter
from src.core.data_keys import DataKeys
from src.core.unit_dimension_handler import UnitDimensionHandler
from src.gui.enums.equilibrium_type import EquilibriumType

ud_handler = UnitDimensionHandler()


class EquilibriumOutputPageComponents(Enum):
    """
    Class to handle equilibrium output page components names
    """
    GRID = SimpleNamespace(type=QGridLayout,
                           name="gridLayout")

    BACK_BUTTON = SimpleNamespace(type=QPushButton,
                                  name="backButton")

    UPDATE_BUTTON = SimpleNamespace(type=QPushButton,
                                    name="updateButton")

    TEMPERATURE = SimpleNamespace(type=QLabel,
                                  name="temperatureValueLabel",
                                  text=LabelFormatter.pad_string("0.0"),
                                  align=Qt.AlignVCenter,
                                  text_interaction=Qt.TextSelectableByMouse,
                                  data_key=DataKeys.EQ_TEMPERATURE)

    PRESSURE = SimpleNamespace(type=QLabel,
                               name="pressureValueLabel",
                               text=LabelFormatter.pad_string("0.0"),
                               align=Qt.AlignVCenter,
                               text_interaction=Qt.TextSelectableByMouse,
                               data_key=DataKeys.EQ_PRESSURE)

    TEMPERATURE_UD = SimpleNamespace(type=QComboBox,
                                     name="temperatureOutputComboBox",
                                     items=ud_handler.temperature_ud)

    PRESSURE_UD = SimpleNamespace(type=QComboBox,
                                  name="pressureOutputComboBox",
                                  items=ud_handler.pressure_ud)

    HEADLINE = SimpleNamespace(type=QLabel,
                               name="outputLabel",
                               align=Qt.AlignCenter,
                               style="highlight")

    MOLE_FRACTION = SimpleNamespace(type=QLabel,
                                    name="xLabel",
                                    text=LabelFormatter.pad_string(""),
                                    align=Qt.AlignVCenter,
                                    text_interaction=Qt.TextSelectableByMouse,
                                    data_key=DataKeys.EQ_MOLE_FRACTION)

    MASS_FRACTION = SimpleNamespace(type=QLabel,
                                    name="yLabel",
                                    text=LabelFormatter.pad_string(""),
                                    align=Qt.AlignVCenter,
                                    text_interaction=Qt.TextSelectableByMouse,
                                    data_key=DataKeys.EQ_MASS_FRACTION)

    NAMES = SimpleNamespace(type=QLabel,
                            name="nLabel",
                            text=LabelFormatter.pad_string(""),
                            align=Qt.AlignVCenter,
                            text_interaction=Qt.TextSelectableByMouse,
                            data_key=DataKeys.EQ_SPECIE_NAMES)

    EQUILIBRIUM_TYPE = SimpleNamespace(type=QComboBox,
                                       name="typeComboBox",
                                       items=[e.value for e in EquilibriumType])
