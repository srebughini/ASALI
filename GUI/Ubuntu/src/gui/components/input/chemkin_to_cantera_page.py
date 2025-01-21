from enum import Enum


class ChemkinToCanteraPageWidgets(Enum):
    """
    Class to handle chemkin to cantera page components names
    """
    THERMO_LABEL = "thermoLabel"
    TRANSPORT_LABEL = "transportLabel"
    KINETIC_LABEL = "kineticLabel"
    SURFACE_LABEL = "surfaceLabel"
    FILES_LABELS = [THERMO_LABEL, TRANSPORT_LABEL, KINETIC_LABEL, SURFACE_LABEL]
    BACK_BUTTON = "backButton"
    CLEAN_BUTTON = "cleanButton"
    CONVERT_BUTTON = "convertButton"
    THERMO_BUTTON = "thermoButton"
    TRANSPORT_BUTTON = "transportButton"
    KINETIC_BUTTON = "kineticButton"
    SURFACE_BUTTON = "surfaceButton"
