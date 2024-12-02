from enum import Enum


class Het1dInputPageWidgets(Enum):
    """
    Class to handle heterogeneous 1D reactor input page widgets names
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

    SPECIFIC_HEAT_EDIT_LINE = "cpEditLine"
    SPECIFIC_HEAT_COMBO_BOX = "cpComboBox"

    DENSITY_EDIT_LINE = "rhoEditLine"
    DENSITY_COMBO_BOX = "rhoComboBox"

    THERMAL_CONDUCTIVITY_EDIT_LINE = "condEditLine"
    THERMAL_CONDUCTIVITY_COMBO_BOX = "condComboBox"

    PARTICLE_DIAMETER_LABEL = "dpLabel"
    PARTICLE_DIAMETER_EDIT_LINE = "dpEditLine"
    PARTICLE_DIAMETER_COMBO_BOX = "dpComboBox"

    WALL_THICKNESS_LABEL = "wallThicknessLabel"
    WALL_THICKNESS_EDIT_LINE = "wallThicknessEditLine"
    WALL_THICKNESS_COMBO_BOX = "wallThicknessComboBox"

    CPSI_LABEL = "cpsiLabel"
    CPSI_EDIT_LINE = "cpsiEditLine"

    VOID_FRACTION_LABEL = "epsiLabel"
    VOID_FRACTION_EDIT_LINE = "epsiEditLine"

    ENERGY_CHECK_BOX = "energyCheckBox"
    DIFFUSION_CHECK_BOX = "diffusionCheckBox"

    COMPOSITION_COMBO_BOX = "compositionComboBox"
    INERT_GAS_SPECIE_COMBO_BOX = "inertSpecie"
    INERT_SURFACE_SPECIE_COMBO_BOX = "inertCoverageSpecie"
    RESOLUTION_METHOD_COMBO_BOX = "resolutionComboBox"
    GEOMETRY_COMBO_BOX = "geometryComboBox"

    SOLVING_OPTION_LAYOUT = "optionsLayout"
    REACTOR_PROPERTIES_LAYOUT = "propertiesLayout"
    COVERAGE_COMPOSITION_LAYOUT = "coverageLayout"
    INITIAL_CONDITIONS_LAYOUT = "initialLayout"
    SOLID_LAYOUT = "solidLayout"
    GEOMETRY_LAYOUT = "geometryLayout"

    TAB_WIDGET = "tabWidget"

    USER_DEFINED_KINETIC_BUTTON = "udkButton"
    BACK_BUTTON = "backButton"
    ADD_SURF_SPECIE_BUTTON = "addCoverageButton"
    REMOVE_SURF_SPECIE_BUTTON = "removeCoverageButton"
    ADD_GAS_SPECIE_BUTTON = "addSpecieButton"
    REMOVE_GAS_SPECIE_BUTTON = "removeSpecieButton"
    RUN_BUTTON = "runButton"
