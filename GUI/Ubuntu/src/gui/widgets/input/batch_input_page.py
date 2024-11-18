from enum import Enum


class BatchInputPageWidgets(Enum):
    """
    Class to handle batch reactor input page widgets names
    """
    VOLUME_EDIT_LINE = "volumeEditLine"
    ALFA_EDIT_LINE = "alfaEditLine"
    INTEGRATION_TIME_EDIT_LINE = "tmaxEditLine"
    INTEGRATION_STEP_EDIT_LINE = "tstepEditLine"
    VOLUME_COMBO_BOX = "volumeComboBox"
    ALFA_COMBO_BOX = "alfaComboBox"
    INTEGRATION_TIME_COMBO_BOX = "tmaxComboBox"
    INTEGRATION_STEP_COMBO_BOX = "tstepComboBox"
    ENERGY_CHECK_BOX = "energyCheckBox"
    SOLVING_OPTION_LAYOUT = "optionsLayout"
    REACTOR_PROPERTIES_LAYOUT = "propertiesLayout"
    COVERAGE_COMPOSITION_LAYOUT = "coverageLayout"
    TAB_WIDGET = "tabWidget"
    UDK_BUTTON = "udkButton"
    BACK_BUTTON = "backButton"
    ADD_COVERAGE_BUTTON = "addCoverageButton"
    REMOVE_COVERAGE_BUTTON = "removeCoverageButton"
    RUN_BUTTON = "runButton"



