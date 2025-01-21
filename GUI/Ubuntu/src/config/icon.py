from enum import Enum

from PyQt5 import QtCore


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
    EMAIL = "fa5s.envelope"
    FACEBOOK = "fa5s.facebook"
    LINKEDIN = "fa5s.linkedin"
    SITE = "fa5s.globe"
    GITHUB = "fa5s.github"

    SIZE = QtCore.QSize(26, 26)

    BLUE_COLOR = "#10253F"

    SCALE_FACTOR = 0.9
