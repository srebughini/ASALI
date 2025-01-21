from enum import Enum


class BatchInputPageWidgets(Enum):
    """
    Class to handle batch reactor input page components names
    """
    VOLUME_EDIT_LINE = "volumeEditLine"
    CATALYTIC_LOAD_EDIT_LINE = "alfaEditLine"
    INTEGRATION_TIME_EDIT_LINE = "tmaxEditLine"
    INTEGRATION_STEP_EDIT_LINE = "tstepEditLine"
    VOLUME_COMBO_BOX = "volumeComboBox"
    CATALYTIC_LOAD_COMBO_BOX = "alfaComboBox"
    INTEGRATION_TIME_COMBO_BOX = "tmaxComboBox"
    INTEGRATION_STEP_COMBO_BOX = "tstepComboBox"
    ENERGY_CHECK_BOX = "energyCheckBox"

    SOLVING_OPTION_LAYOUT = "optionsLayout"
    REACTOR_PROPERTIES_LAYOUT = "propertiesLayout"
    COVERAGE_COMPOSITION_LAYOUT = "coverageLayout"

    TAB_WIDGET = "tabWidget"
    USER_DEFINED_KINETIC_BUTTON = "udkButton"
    BACK_BUTTON = "backButton"
    ADD_SURF_SPECIE_BUTTON = "addCoverageButton"
    REMOVE_SURF_SPECIE_BUTTON = "removeCoverageButton"
    RUN_BUTTON = "runButton"



