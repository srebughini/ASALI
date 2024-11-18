from enum import Enum


class PlotAndSaveOutputPageWidgets(Enum):
    """
    Class to handle plot and save output page widgets names
    """
    PLOT_BUTTON = "plotButton"
    SAVE_BUTTON = "saveButton"
    BACK_BUTTON = "backButton"
    SELECT_BUTTON = "selectButton"
    GAS_LABEL = "gasLabel"
    SURFACE_LABEL="surfaceLabel"
    TEMPERATURE_LABEL = "temperatureLabel"
    GRID_LAYOUT = "gridLayout"
    COMPOSITION_COMBO_BOX = "compositionComboBox"
    COLOR_COMBO_BOX = "plotColorComboBox"