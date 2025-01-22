from enum import Enum
from types import SimpleNamespace

from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QPushButton, QGridLayout, QLabel, QComboBox

from src.controllers.label_formatter import LabelFormatter
from src.core.data_keys import DataKeys
from src.core.unit_dimension_handler import UnitDimensionHandler

ud_handler = UnitDimensionHandler()


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
                                    text_interaction=Qt.TextSelectableByMouse,
                                    data_key=DataKeys.RHO)

    VISCOSITY_VALUE = SimpleNamespace(type=QLabel,
                                      name="muValueLabel",
                                      text=LabelFormatter.pad_string("0.0"),
                                      align=Qt.AlignVCenter,
                                      text_interaction=Qt.TextSelectableByMouse,
                                      data_key=DataKeys.MU)

    THERMAL_CONDUCTIVITY_VALUE = SimpleNamespace(type=QLabel,
                                                 name="condValueLabel",
                                                 text=LabelFormatter.pad_string("0.0"),
                                                 align=Qt.AlignVCenter,
                                                 text_interaction=Qt.TextSelectableByMouse,
                                                 data_key=DataKeys.COND)

    DIFFUSIVITY_VALUE = SimpleNamespace(type=QLabel,
                                        name="diffValueLabel",
                                        text=LabelFormatter.pad_string("0.0"),
                                        align=Qt.AlignVCenter,
                                        text_interaction=Qt.TextSelectableByMouse,
                                        data_key=DataKeys.DIFF_MIX)

    MOLECULAR_WEIGHT_VALUE = SimpleNamespace(type=QLabel,
                                             name="mwValueLabel",
                                             text=LabelFormatter.pad_string("0.0"),
                                             align=Qt.AlignVCenter,
                                             text_interaction=Qt.TextSelectableByMouse,
                                             data_key=DataKeys.MW)

    ENTHALPY_VALUE = SimpleNamespace(type=QLabel,
                                     name="hValueLabel",
                                     text=LabelFormatter.pad_string("0.0"),
                                     align=Qt.AlignVCenter,
                                     text_interaction=Qt.TextSelectableByMouse,
                                     data_key=DataKeys.H)

    ENTROPY_VALUE = SimpleNamespace(type=QLabel,
                                    name="sValueLabel",
                                    text=LabelFormatter.pad_string("0.0"),
                                    align=Qt.AlignVCenter,
                                    text_interaction=Qt.TextSelectableByMouse,
                                    data_key=DataKeys.S)

    SPECIFIC_HEAT_VALUE = SimpleNamespace(type=QLabel,
                                          name="cpValueLabel",
                                          text=LabelFormatter.pad_string("0.0"),
                                          align=Qt.AlignVCenter,
                                          text_interaction=Qt.TextSelectableByMouse,
                                          data_key=DataKeys.CP)

    DENSITY_UD = SimpleNamespace(type=QComboBox,
                                 name="rhoComboBox",
                                 items=ud_handler.density_ud,
                                 data_key=DataKeys.RHO)

    VISCOSITY_UD = SimpleNamespace(type=QComboBox,
                                   name="muComboBox",
                                   items=ud_handler.viscosity_ud,
                                   data_key=DataKeys.MU)

    THERMAL_CONDUCTIVITY_UD = SimpleNamespace(type=QComboBox,
                                              name="condComboBox",
                                              items=ud_handler.thermal_conductivity_ud,
                                              data_key=DataKeys.COND)

    DIFFUSIVITY_UD = SimpleNamespace(type=QComboBox,
                                     name="diffComboBox",
                                     items=ud_handler.diffusivity_ud,
                                     data_key=DataKeys.DIFF_MIX)

    MOLECULAR_WEIGHT_UD = SimpleNamespace(type=QComboBox,
                                          name="mwComboBox",
                                          items=ud_handler.molecular_weight_ud,
                                          data_key=DataKeys.MW)

    ENTHALPY_UD = SimpleNamespace(type=QComboBox,
                                  name="hComboBox",
                                  items=ud_handler.enthalpy_ud,
                                  data_key=DataKeys.H)

    ENTROPY_UD = SimpleNamespace(type=QComboBox,
                                 name="sComboBox",
                                 items=ud_handler.entropy_ud,
                                 data_key=DataKeys.S)

    SPECIFIC_HEAT_UD = SimpleNamespace(type=QComboBox,
                                       name="cpComboBox",
                                       items=ud_handler.specific_heat_ud,
                                       data_key=DataKeys.CP)
