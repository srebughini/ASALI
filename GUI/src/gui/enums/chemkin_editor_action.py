from enum import Enum


class ChemkinEditorAction(Enum):
    """
    Enum describing the regression method
    """
    CONVERTER = "Convert CHEMKIN to CANTERA file"
    THERMO = "Add specie to CHEMKIN THERMO file"
    TRANSPORT = "Add specie to CHEMKIN TRANSPORT file"
