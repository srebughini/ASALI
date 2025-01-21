from enum import Enum

from PyQt5.QtCore import Qt
from PyQt5.QtGui import QDoubleValidator


class InputCompositionConfig(Enum):
    """
    Class to handle the input composition generic configuration
    """
    GAS_SPECIE_LABEL_TEXT = "Specie #{:d}"
    GAS_SPECIE_LABEL_NAME = "l{:d}"
    GAS_SPECIE_COMBO_BOX_NAME = "n{:d}"
    GAS_SPECIE_EDIT_LINE_NAME = "x{:d}"
    SURFACE_SPECIE_LABEL_TEXT = "Coverage #{:d}"
    SURFACE_SPECIE_LABEL_NAME = "lx{:d}"
    SURFACE_SPECIE_COMBO_BOX_NAME = "nc{:d}"
    SURFACE_SPECIE_EDIT_LINE_NAME = "z{:d}"

    EDIT_LINE_VALIDATOR = QDoubleValidator(0.0, 1.0, 5)
    EDIT_LINE_ALIGN = Qt.AlignRight
    EDIT_LINE_TEXT = "0.0"
