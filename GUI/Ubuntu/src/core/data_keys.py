from enum import Enum


class DataKeys(Enum):
    """
    Class to handle the keys of the data stored in DataStore
    """
    IS_DEFAULT_FILE_PATH = (False, "is_default_file_path")
    CHEMISTRY_FILE_PATH = ("", "chemistry_file_path")

    GAS_PHASE_NAME = ("", "gas_phase_name")
    SURFACE_PHASE_NAME = ("", "surface_phase_name")

    GAS_SPECIES_NAMES = ([], "gas_phase_specie_names")
    IS_GAS_SPECIES_NAMES_UPDATED = (False, "is_gas_phase_specie_names_updated")

    GAS_NS = (-1, "number_of_gas_species")

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
    # EQUILIBRIUM_T = "equilibrium_temperature"
    # EQUILIBRIUM_P = "equilibrium_pressure"
    # EQUILIBRIUM_X = "equilibrium_mole_fraction"
    # EQUILIBRIUM_Y = "equilibrium_mass_fraction"
    # EQUILIBRIUM_TYPE = "equilibrium_type"
    # EQUILIBRIUM_N = "equilibrium_specie_names"
    #
    # GAS_SPECIES_NAMES = "gas_phase_specie_names"
    # GAS_SPECIES_NAMES_UPDATE = "gas_phase_specie_names_to_be_updated"
    # SURFACE_SPECIES_NAMES = "surface_phase_specie_names"
    # SURFACE_SPECIES_NAMES_UPDATE = "surface_phase_specie_names_to_be_updated"
    #
    # MIN_TEMPERATURE = "minimum_temperature"
    # MAX_TEMPERATURE = "maximum_temperature"
    # TEMPERATURE_VECTOR = "temperature_vector"
    # RHO_VECTOR = "density_vector"
    # MU_VECTOR = "viscosity_vector"
    # COND_VECTOR = "thermal_conductivity_vector"
    # CP_VECTOR = "specific_heat_vector"
    # H_VECTOR = "enthalpy_vector"
    # S_VECTOR = "entropy_vector"
    #
    # RHO = "density"
    # MU = "viscosity"
    # MW = "molecular_weight"
    # COND = "thermal_conductivity"
    # DIFF_MIX = "mixture_diffusivity"
    # CP = "specific_heat"
    # H = "enthalpy"
    # S = "entropy"
    # GEOMETRY = "geometry"
    # V = "velocity"
    # L = "length"
    # KN = "knudsen_number"
    # VACUUM_SPECIE = "vacuum_specie"
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
    # REGRESSION_METHOD = "regression_method"
