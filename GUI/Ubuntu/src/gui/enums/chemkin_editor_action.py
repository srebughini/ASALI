from enum import Enum


class ChemkinEditorAction(Enum):
    """
    Enum describing the regression method
    """
    NONE = "...Select action..."
    TO_CANTERA = "Convert CHEMKIN to CANTERA file"
    ADD_THERMO = "Add specie to CHEMKIN THERMO file"
    ADD_TRANSPORT = "Add specie to CHEMKIN TRANSPORT file"
