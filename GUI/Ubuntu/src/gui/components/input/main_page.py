from enum import Enum
from types import SimpleNamespace

from PyQt5.QtWidgets import QPushButton, QGridLayout


class MainInputPageComponents(Enum):
    """
    Class to handle chemistry input page components names
    """
    GRID = SimpleNamespace(type=QGridLayout,
                           name="gridLayout")

    PROPERTIES_BUTTON = SimpleNamespace(type=QPushButton,
                                        name="propertiesButton")

    VACUUM_BUTTON = SimpleNamespace(type=QPushButton,
                                    name="vacuumButton")

    REGRESSION_BUTTON = SimpleNamespace(type=QPushButton,
                                        name="regressionButton")

    EQUILIBRIUM_BUTTON = SimpleNamespace(type=QPushButton,
                                         name="equilibriumButton")

    PRESSURE_DROPS_BUTTON = SimpleNamespace(type=QPushButton,
                                            name="pressureDropsButton")

    CHEMKIN_BUTTON = SimpleNamespace(type=QPushButton,
                                     name="chemkinButton")
