from enum import Enum
from types import SimpleNamespace

from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QGridLayout, QComboBox, QLabel, QPushButton

from src.controllers.label_formatter import LabelFormatter
from src.core.data_keys import DataKeys
from src.core.unit_dimension_handler import UnitDimensionHandler

ud_handler = UnitDimensionHandler()


class VacuumOutputPageComponents(Enum):
    """
    Class to handle vacuum output page components names
    """
    GRID = SimpleNamespace(type=QGridLayout,
                           name="gridLayout")

    BACK_BUTTON = SimpleNamespace(type=QPushButton,
                                  name="backButton")

    UPDATE_BUTTON = SimpleNamespace(type=QPushButton,
                                    name="updateButton")

    HEADLINE = SimpleNamespace(type=QLabel,
                               name="headlineLabel",
                               align=Qt.AlignCenter,
                               style="highlight")

    VELOCITY_UD = SimpleNamespace(type=QComboBox,
                                  name="vComboBox",
                                  items=ud_handler.velocity_ud,
                                  data_key=DataKeys.VACUUM_VELOCITY)

    MEAN_FREE_PATH_UD = SimpleNamespace(type=QComboBox,
                                        name="lComboBox",
                                        items=ud_handler.length_ud,
                                        data_key=DataKeys.VACUUM_MEAN_FREE_PATH)

    DIFFUSIVITY_UD = SimpleNamespace(type=QComboBox,
                                     name="diffComboBox",
                                     items=ud_handler.diffusivity_ud,
                                     data_key=DataKeys.VACUUM_DIFF_MIX)

    VELOCITY_VALUE = SimpleNamespace(type=QLabel,
                                     name="vValueLabel",
                                     text=LabelFormatter.pad_string("0.0"),
                                     align=Qt.AlignVCenter,
                                     text_interaction=Qt.TextSelectableByMouse,
                                     data_key=DataKeys.VACUUM_VELOCITY)

    MEAN_FREE_PATH_VALUE = SimpleNamespace(type=QLabel,
                                           name="lValueLabel",
                                           text=LabelFormatter.pad_string("0.0"),
                                           align=Qt.AlignVCenter,
                                           text_interaction=Qt.TextSelectableByMouse,
                                           data_key=DataKeys.VACUUM_MEAN_FREE_PATH)

    DIFFUSIVITY_VALUE = SimpleNamespace(type=QLabel,
                                        name="diffValueLabel",
                                        text=LabelFormatter.pad_string("0.0"),
                                        align=Qt.AlignVCenter,
                                        text_interaction=Qt.TextSelectableByMouse,
                                        data_key=DataKeys.VACUUM_DIFF_MIX)

    KNUDSEN_VALUE = SimpleNamespace(type=QLabel,
                                    name="knValueLabel",
                                    text=LabelFormatter.pad_string("0.0"),
                                    align=Qt.AlignVCenter,
                                    text_interaction=Qt.TextSelectableByMouse,
                                    data_key=DataKeys.VACUUM_KNUDSEN_NUMBER)
