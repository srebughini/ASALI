from enum import Enum

from PySide6 import QtCore


class IconConfig(Enum):
    """
    Class to handle the icons
    """
    FLASK = "fa5s.flask"
    WIND = "fa5s.wind"
    CHART = "fa5s.chart-bar"
    BALANCE = "fa5s.balance-scale"
    ATOM = "fa5s.atom"
    TASKS = "fa5s.tasks"

    SIZE = QtCore.QSize(26, 26)

    COLOR = "#E9963D" # ORANGE

    SCALE_FACTOR = 0.9
