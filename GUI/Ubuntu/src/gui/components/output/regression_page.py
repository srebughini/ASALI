from enum import Enum
from types import SimpleNamespace

from PyQt5.QtCore import Qt
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import QLineEdit, QComboBox, QPushButton, QGridLayout, QVBoxLayout

from src.core.unit_dimension_handler import UnitDimensionHandler
from src.gui.enums.properties import Properties
from src.gui.enums.regression_method import RegressionMethod

ud_handler = UnitDimensionHandler()


class RegressionOutputPageComponents(Enum):
    """
    Class to handle linear regression output page components names
    """
    GRID = SimpleNamespace(type=QGridLayout,
                           name="gridLayout")

    PLOT_LAYOUT = SimpleNamespace(type=QVBoxLayout,
                                  name="plotLayout")

    BACK_BUTTON = SimpleNamespace(type=QPushButton,
                                  name="backButton")

    UPDATE_BUTTON = SimpleNamespace(type=QPushButton,
                                    name="updateButton")

    TEMPERATURE_UD = SimpleNamespace(type=QComboBox,
                                     name="temperatureUdComboBox",
                                     items=ud_handler.temperature_ud)

    PROPERTY_UD = SimpleNamespace(type=QComboBox,
                                  name="propertyUdComboBox",
                                  items={Properties.DENSITY: ud_handler.density_ud,
                                         Properties.VISCOSITY: ud_handler.viscosity_ud,
                                         Properties.SPECIFIC_HEAT: ud_handler.specific_heat_ud,
                                         Properties.THERMAL_CONDUCTIVITY: ud_handler.thermal_conductivity_ud,
                                         Properties.ENTROPY: ud_handler.entropy_ud,
                                         Properties.ENTHALPY: ud_handler.enthalpy_ud})

    MAX_TEMPERATURE_INPUT = SimpleNamespace(type=QLineEdit,
                                            name="maxTemperatureEditLine",
                                            validator=QDoubleValidator(0.0, 3000.0, 2),
                                            align=Qt.AlignRight)

    MIN_TEMPERATURE_INPUT = SimpleNamespace(type=QLineEdit,
                                            name="minTemperatureEditLine",
                                            validator=QDoubleValidator(0.0, 3000.0, 2),
                                            align=Qt.AlignRight)

    REGRESSION_METHOD = SimpleNamespace(type=QComboBox,
                                        name="regressionComboBox",
                                        items=[e.value for e in RegressionMethod])

    PROPERTY = SimpleNamespace(type=QComboBox,
                               name="propertyComboBox",
                               items=[e.value for e in Properties])
