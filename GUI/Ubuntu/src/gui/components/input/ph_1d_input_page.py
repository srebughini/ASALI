from enum import Enum


class Ph1dInputPageWidgets(Enum):
    """
    Class to handle pseudo-homogeneous 1D reactor input page components names
    """
    DIAMETER_EDIT_LINE = "diameterEditLine"
    DIAMETER_COMBO_BOX = "diameterComboBox"

    CATALYTIC_LOAD_EDIT_LINE = "alfaEditLine"
    CATALYTIC_LOAD_COMBO_BOX = "alfaComboBox"

    INTEGRATION_TIME_LABEL = "tmaxLabel"
    INTEGRATION_TIME_EDIT_LINE = "tmaxEditLine"
    INTEGRATION_TIME_COMBO_BOX = "tmaxComboBox"

    INTEGRATION_STEP_LABEL = "tstepLabel"
    INTEGRATION_STEP_EDIT_LINE = "tstepEditLine"
    INTEGRATION_STEP_COMBO_BOX = "tstepComboBox"

    LENGTH_EDIT_LINE = "lengthEditLine"
    LENGTH_COMBO_BOX = "lengthComboBox"

    MASS_FLOW_RATE_EDIT_LINE = "qEditLine"
    MASS_FLOW_RATE_COMBO_BOX = "qComboBox"

    TEMPERATURE_EDIT_LINE = "temperatureEditLine"
    TEMPERATURE_COMBO_BOX = "temperatureComboBox"

    ENERGY_CHECK_BOX = "energyCheckBox"
    DIFFUSION_CHECK_BOX = "diffusionCheckBox"


    COMPOSITION_COMBO_BOX = "compositionComboBox"
    INERT_GAS_SPECIE_COMBO_BOX = "inertSpecie"
    INERT_SURFACE_SPECIE_COMBO_BOX = "inertCoverageSpecie"
    RESOLUTION_METHOD_COMBO_BOX = "resolutionComboBox"

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
