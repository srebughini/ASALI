from enum import Enum
from types import SimpleNamespace

from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QGridLayout, QPushButton, QLabel, QComboBox, QLineEdit

from src.controllers.edit_lines_validator import EditLinesValidator
from src.controllers.label_formatter import LabelFormatter
from src.core.data_keys import DataKeys
from src.core.unit_dimension_handler import UnitDimensionHandler
from src.gui.enums.reactor_type import ReactorType

ud_handler = UnitDimensionHandler()


class PressureDropsOutputPageComponents(Enum):
    """
    Class to handle pressure drops output page components names
    """
    GRID = SimpleNamespace(type=QGridLayout,
                           name="gridLayout")

    BACK_BUTTON = SimpleNamespace(type=QPushButton,
                                  name="backButton")

    UPDATE_BUTTON = SimpleNamespace(type=QPushButton,
                                    name="updateButton")

    PRESSURE_DROPS = SimpleNamespace(type=QLabel,
                                     name="pressureDropsValueLabel",
                                     text=LabelFormatter.pad_string("0.0"),
                                     align=Qt.AlignVCenter,
                                     text_interaction=Qt.TextSelectableByMouse,
                                     data_key=DataKeys.PRESSURE_DROPS)

    TUBE_DIAMETER_LABEL = SimpleNamespace(type=QLabel,
                                          name="dtLabel")

    WALL_THICKNESS_LABEL = SimpleNamespace(type=QLabel,
                                           name="wtLabel")

    PARTICLE_DIAMETER_LABEL = SimpleNamespace(type=QLabel,
                                              name="dpLabel")

    CPSI_LABEL = SimpleNamespace(type=QLabel,
                                 name="cpsiLabel")

    VOID_FRACTION_LABEL = SimpleNamespace(type=QLabel,
                                          name="epsiLabel")

    LENGTH_UD = SimpleNamespace(type=QComboBox,
                                name="lengthComboBox",
                                items=ud_handler.length_ud)

    VELOCITY_UD = SimpleNamespace(type=QComboBox,
                                  name="velocityComboBox",
                                  items=ud_handler.velocity_ud)

    TUBE_DIAMETER_UD = SimpleNamespace(type=QComboBox,
                                       name="dtComboBox",
                                       items=ud_handler.length_ud)

    WALL_THICKNESS_UD = SimpleNamespace(type=QComboBox,
                                        name="wtComboBox",
                                        items=ud_handler.length_ud)

    PARTICLE_DIAMETER_UD = SimpleNamespace(type=QComboBox,
                                           name="dpComboBox",
                                           items=ud_handler.length_ud)

    PRESSURE_DROPS_UD = SimpleNamespace(type=QComboBox,
                                        name="pressureDropsOutputComboBox",
                                        items=ud_handler.pressure_ud)

    LENGTH = SimpleNamespace(type=QLineEdit,
                             name="lengthValue",
                             validator=EditLinesValidator.double_validator(0.0, 1e09, 4),
                             align=Qt.AlignRight)

    VELOCITY = SimpleNamespace(type=QLineEdit,
                               name="velocityValue",
                               validator=EditLinesValidator.double_validator(0.0, 1e09, 4),
                               align=Qt.AlignRight)

    TUBE_DIAMETER = SimpleNamespace(type=QLineEdit,
                                    name="dtValue",
                                    validator=EditLinesValidator.double_validator(0.0, 1e09, 4),
                                    align=Qt.AlignRight)

    WALL_THICKNESS = SimpleNamespace(type=QLineEdit,
                                     name="wtValue",
                                     validator=EditLinesValidator.double_validator(0.0, 1e09, 4),
                                     align=Qt.AlignRight)

    PARTICLE_DIAMETER = SimpleNamespace(type=QLineEdit,
                                        name="dpValue",
                                        validator=EditLinesValidator.double_validator(0.0, 1e09, 4),
                                        align=Qt.AlignRight)

    CPSI = SimpleNamespace(type=QLineEdit,
                           name="cpsiValue",
                           validator=EditLinesValidator.int_validator(0, 10000000),
                           align=Qt.AlignRight)

    VOID_FRACTION = SimpleNamespace(type=QLineEdit,
                                    name="epsiValue",
                                    validator=EditLinesValidator.double_validator(0.0, 1.0, 5),
                                    align=Qt.AlignRight)

    HEADLINE = SimpleNamespace(type=QLabel,
                               name="outputLabel",
                               align=Qt.AlignCenter,
                               style="highlight")

    REACTOR_TYPE = SimpleNamespace(type=QComboBox,
                                   name="typeComboBox",
                                   items=[e.value for e in ReactorType])

    # MOLE_FRACTION = SimpleNamespace(type=QLabel,
    #                                 name="xLabel",
    #                                 text=LabelFormatter.pad_string(""),
    #                                 align=Qt.AlignVCenter,
    #                                 text_interaction=Qt.TextSelectableByMouse,
    #                                 data_key=DataKeys.EQ_MOLE_FRACTION)
    #
    # MASS_FRACTION = SimpleNamespace(type=QLabel,
    #                                 name="yLabel",
    #                                 text=LabelFormatter.pad_string(""),
    #                                 align=Qt.AlignVCenter,
    #                                 text_interaction=Qt.TextSelectableByMouse,
    #                                 data_key=DataKeys.EQ_MASS_FRACTION)
    #
    # NAMES = SimpleNamespace(type=QLabel,
    #                         name="nLabel",
    #                         text=LabelFormatter.pad_string(""),
    #                         align=Qt.AlignVCenter,
    #                         text_interaction=Qt.TextSelectableByMouse,
    #                         data_key=DataKeys.EQ_SPECIE_NAMES)
    #
    # EQUILIBRIUM_TYPE = SimpleNamespace(type=QComboBox,
    #                                    name="typeComboBox",
    #                                    items=[e.value for e in EquilibriumType])
