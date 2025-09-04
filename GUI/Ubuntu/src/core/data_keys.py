from enum import Enum

from src.config.app import AppConfig
from src.gui.enums.composition_type import CompositionType
from src.gui.enums.equilibrium_type import EquilibriumType
from src.gui.enums.properties import Properties
from src.gui.enums.regression_method import RegressionMethod


class DataKeys(Enum):
    """
    Class to handle the keys of the data stored in DataStore
    """
    LAST_ACTIVE_WINDOW = (AppConfig.MAIN_INPUT_PAGE, "last_active_window")

    IS_DEFAULT_FILE_PATH = (False, "is_default_file_path")
    CHEMISTRY_FILE_PATH = ("", "chemistry_file_path")

    GAS_PHASE_NAME = ("", "gas_phase_name")
    SURFACE_PHASE_NAME = ("", "surface_phase_name")

    GAS_SPECIES_NAMES = ([], "gas_phase_specie_names")
    IS_GAS_SPECIES_NAMES_UPDATED = (False, "is_gas_phase_specie_names_updated")

    GAS_NS = (-1, "number_of_gas_species")
    TEMPERATURE = ((298.15, "K"), "gas_mixture_temperature")
    PRESSURE = ((101325.0, "Pa"), "gas_mixture_pressure")
    GAS_COMPOSITION = (({}, CompositionType.MASS), "gas_mixture_composition")

    RHO = ((1.0, "kg/m3"), "density")
    MU = ((1.0e-05, "Pas"), "viscosity")
    MW = ((18.0, "g/mol"), "molecular_weight")
    COND = ((2.5, "W/m/K"), "thermal_conductivity")
    DIFF_MIX = ((1.0e-05, "m2/s"), "mixture_diffusivity")
    CP = ((1000.0, "J/kg/K"), "specific_heat")
    H = ((1.0, "J/kg"), "enthalpy")
    S = ((1.0, "J/kg/K"), "entropy")

    VACUUM_LENGTH = ((0.0, "m"), "vacuum_characteristic_length")
    VACUUM_SPECIE = ("", "vacuum_specie")
    VACUUM_MEAN_FREE_PATH = ((0.0, "m"), "mean_free_path")
    VACUUM_VELOCITY = ((0.0, "m/s"), "vacuum_velocity")
    VACUUM_KNUDSEN_NUMBER = (0.0, "knudsen_number")
    VACUUM_DIFF_MIX = ((0.0, "m2/s"), "vacuum_diffusivity")

    MIN_TEMPERATURE = ((298.15, "K"), "minimum_temperature")
    MAX_TEMPERATURE = ((773.15, "K"), "minimum_temperature")
    REGRESSION_METHOD = (RegressionMethod.LINEAR, "regression_method")
    REGRESSION_PROPERTY_TYPE = (Properties.DENSITY, "property_type_to_be_fitted")
    REGRESSION_PROPERTY = (([1.0], 1., 1., "kg/m3"), "property_fitted")
    TEMPERATURE_VECTOR = (([298.15], "K"), "temperature_vector")

    EQ_TEMPERATURE = ((298.15, "K"), "equilibrium_temperature")
    EQ_PRESSURE = ((101325.0, "Pa"), "equilibrium_pressure")
    EQ_MOLE_FRACTION = ([], "equilibrium_mole_fraction")
    EQ_MASS_FRACTION = ([], "equilibrium_mass_fraction")
    EQUILIBRIUM_TYPE = (EquilibriumType.TP, "equilibrium_type")
    EQ_SPECIE_NAMES = ([], "equilibrium_specie_names")

    THERMO_FILE_PATH = ("", "chemkin_thermo_file_path")
    TRANSPORT_FILE_PATH = ("", "chemkin_transport_file_path")
    KINETIC_FILE_PATH = ("", "chemkin_gas_kinetic_file_path")
    SURFACE_FILE_PATH = ("", "chemkin_surface_file_path")

    NE = (-1, "number_of_gas_elements")


    # IS_NEW_CHEMISTRY = "is_the_chemistry_file_new"
    # UDK_FILE_PATH = "udk_file_path"
    # GAS_PHASE_NAME = "gas_phase_name"
    # SURFACE_PHASE_NAME = "surface_phase_name"
    # OUTPUT_FILE_PATH = "output_file_path"
    #
    # INLET_NS = "inlet_number_of_species"
    # INLET_SURF_NS = "inlet_numer_of_coverage_species"
    # INLET_T = "inlet_temperature"
    # INLET_P = "inlet_pressure"
    # INLET_GAS_COMPOSITION = "inlet_gas_composition"
    #
    # INITIAL_NS = "initial_number_of_species"
    # INITIAL_SURF_NS = "initial_number_of_coverage_species"
    # INITIAL_SURF_COMPOSITION = "initial_coverage_composition"
    # INITIAL_GAS_COMPOSITION = "initial_gas_composition"
    # INITIAL_GAS_T = "initial_gas_temperature"
    # INITIAL_SOLID_T = "initial_solid_temperature"
    #
    # INERT_GAS_SPECIE = "inert_gas_specie"
    # INERT_SURFACE_SPECIE = "inert_surface_specie"
    #
    # GAS_SPECIES_NAMES = "gas_phase_specie_names"
    # GAS_SPECIES_NAMES_UPDATE = "gas_phase_specie_names_to_be_updated"
    # SURFACE_SPECIES_NAMES = "surface_phase_specie_names"
    # SURFACE_SPECIES_NAMES_UPDATE = "surface_phase_specie_names_to_be_updated"
    #
    # THERMO_FILE_PATH = "chemkin_thermo_file_path"
    # TRANSPORT_FILE_PATH = "chemkin_transport_file_path"
    # KINETIC_FILE_PATH = "chemkin_gas_kinetic_file_path"
    # SURFACE_FILE_PATH = "chemkin_surface_file_path"
    # USER_DEFINED_KINETIC_FILE_PATH = "asali_user_defined_kinetic_file_path"
    #
    # REACTOR_TYPE = "reactor_type"
    # REACTOR_NAME = "reactor_name"
    # REACTOR_PAGE_NAME = "reactor_page_name"
    # REACTOR_RESOLUTION_METHOD = "reactor_resolution_method"
    # REACTOR_GEOMETRY = "reactor_geometry"
    #
    # VOLUME = "reactor_volume"
    # DIAMETER = "reactor_diameter"
    # LENGTH = "reactor_length"
    # ALFA = "reactor_catalytic_load"
    # MASS_FLOW_RATE = "reactor_mass_flow_rate"
    # PARTICLE_DIAMETER = "particle_diameter"
    # WALL_THICKNESS = "wall_thickness"
    #
    # EPSI = "void_fraction"
    # CPSI = "cpsi"
    #
    # ENERGY_BALANCE = "energy_balance"
    # DIFFUSION = "diffusion"
    #
    # TMAX = "integration_time"
    # TSTEP = "integration_time_step"
    #
    # SOLID_RHO = "solid_density"
    # SOLID_CP = "solid_specific_heat"
    # SOLID_COND = "solid_thermal_conductivity"
    #
    # REACTOR_RESULTS = "reactor_results"
    # TEMPERATURE_TYPES = "reactor_temperature_types"
    # PLOT_AND_SAVE_COMPOSITION_TYPE = "plot_and_save_composition_type"
    # COLORMAP = "plotting_color_map"
    # GAS_SPECIES_NAMES_TO_BE_PLOTTED = "gas_species_names_to_be_plotted"
    # SURFACE_SPECIES_NAMES_TO_BE_PLOTTED = "surface_species_names_to_be_plotted"
    # TEMPERATURE_TO_BE_PLOTTED = "temperature_to_be_plotted"
    #
    #
