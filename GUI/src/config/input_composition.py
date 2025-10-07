from enum import Enum

from PySide6.QtCore import Qt
from PySide6.QtGui import QIntValidator

from src.controllers.edit_lines_validator import EditLinesValidator


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
    ELEMENT_LABEL_TEXT = "Element #{:d}"
    ELEMENT_LABEL_NAME = "le{:d}"
    ELEMENT_EDIT_LINE_NAME = "ne{:d}"
    ELEMENT_EDIT_LINE_COMPOSITION = "e{:d}"

    SPECIES_VALIDATOR = EditLinesValidator.double_validator(0.0, 1.0, 5)
    ELEMENT_COMPOSITION_VALIDATOR = QIntValidator(0, 1000)
    ELEMENT_NAME_VALIDATOR = EditLinesValidator.letters_validator()
    EDIT_LINE_ALIGN = Qt.AlignRight
    EDIT_LINE_DOUBLE_TEXT = "0.0"
    EDIT_LINE_INT_TEXT = "0"
    EDIT_LINE_LETTER_TEXT = "A"
