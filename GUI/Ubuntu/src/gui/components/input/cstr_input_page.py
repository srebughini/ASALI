from enum import Enum


class CstrInputPageWidgets(Enum):
    """
    Class to handle continuous stirred tank reactor input page components names
    """
    VOLUME_EDIT_LINE = "volumeEditLine"
    CATALYTIC_LOAD_EDIT_LINE = "alfaEditLine"
    INTEGRATION_TIME_EDIT_LINE = "tmaxEditLine"
    INTEGRATION_STEP_EDIT_LINE = "tstepEditLine"
    VOLUME_COMBO_BOX = "volumeComboBox"
    CATALYTIC_LOAD_COMBO_BOX = "alfaComboBox"
    INTEGRATION_TIME_COMBO_BOX = "tmaxComboBox"
    INTEGRATION_STEP_COMBO_BOX = "tstepComboBox"
    MASS_FLOW_RATE_EDIT_LINE = "qEditLine"
    MASS_FLOW_RATE_COMBO_BOX = "qComboBox"
    TEMPERATURE_EDIT_LINE = "temperatureEditLine"
    TEMPERATURE_COMBO_BOX = "temperatureComboBox"
    ENERGY_CHECK_BOX = "energyCheckBox"
    COMPOSITION_COMBO_BOX = "compositionComboBox"
    SOLVING_OPTION_LAYOUT = "optionsLayout"
    REACTOR_PROPERTIES_LAYOUT = "propertiesLayout"
    COVERAGE_COMPOSITION_LAYOUT = "coverageLayout"
    INITIAL_CONDITIONS_LAYOUT = "initialLayout"
    TAB_WIDGET = "tabWidget"
    USER_DEFINED_KINETIC_BUTTON = "udkButton"
    BACK_BUTTON = "backButton"
    ADD_SURF_SPECIE_BUTTON = "addCoverageButton"
    REMOVE_SURF_SPECIE_BUTTON = "removeCoverageButton"
    ADD_GAS_SPECIE_BUTTON = "addSpecieButton"
    REMOVE_GAS_SPECIE_BUTTON = "removeSpecieButton"
    RUN_BUTTON = "runButton"



