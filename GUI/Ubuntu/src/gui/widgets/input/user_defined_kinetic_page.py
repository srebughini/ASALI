from enum import Enum


class UserDefinedKineticPageWidgets(Enum):
    """
    Class to handle user defined kinetic page widgets names
    """
    UDK_LABEL = "udkLabel"
    CANTERA_LABEL = "canteraLabel"
    FILES_LABELS = [UDK_LABEL, CANTERA_LABEL]
    BACK_BUTTON = "backButton"
    CHECK_BUTTON = "checkButton"
    UDK_BUTTON = "udkButton"
    CANTERA_BUTTON = "canteraButton"
