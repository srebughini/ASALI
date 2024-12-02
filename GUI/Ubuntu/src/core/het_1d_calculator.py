from asali.reactors.het1d_steady_state import SteadyStateHeterogeneous1DReactor
from asali.reactors.het1d_transient import TransientHeterogeneous1DReactor
from asali.utils.unit_converter import UnitConverter

from src.core.composition_type import CompositionType
from src.core.data_keys import DataKeys
from src.core.data_store import DataStore
from src.core.reactor_geometry import ReactorGeometry
from src.core.reactor_resolution_method import ReactorResolutionMethod
from src.core.unit_dimension_handler import UnitDimensionHandler

import numpy as np
import traceback as tb


def heterogeneous_1d_reactor_calculator(data_store, results) -> None:
    """
    Function to run the heterogeneous 1D reactor model
    Parameters
    ----------
    data_store: DataStore
        Class to handle the user input
    results: multiprocessing.Queue()
        Results to be saved

    Returns
    -------
    """
    try:
        # Input files
        cantera_input_file_path = data_store.get_data(DataKeys.CHEMISTRY_FILE_PATH)
        gas_phase_name = data_store.get_data(DataKeys.GAS_PHASE_NAME)
        surface_phase_name = data_store.get_data(DataKeys.SURFACE_PHASE_NAME)
        udk_file_path = data_store.get_data(DataKeys.UDK_FILE_PATH)

        resolution_method = data_store.get_data(DataKeys.REACTOR_RESOLUTION_METHOD)

        if resolution_method == ReactorResolutionMethod.TRANSIENT:
            reactor_class = TransientHeterogeneous1DReactor(cantera_input_file_path, gas_phase_name,
                                                            surface_phase_name)
        else:
            reactor_class = SteadyStateHeterogeneous1DReactor(cantera_input_file_path, gas_phase_name,
                                                              surface_phase_name)

        uc = UnitConverter()

        # Coverage
        initial_coverage = data_store.get_data(DataKeys.INITIAL_SURF_COMPOSITION)

        if udk_file_path is not None:
            reactor_class.set_user_defined_kinetic_model(udk_file_path)
        else:
            reactor_class.set_initial_coverage(initial_coverage)

        # Length
        length_tuple = data_store.get_data(DataKeys.LENGTH)
        reactor_class.set_length(length_tuple[0],
                                 UnitDimensionHandler.from_human_to_code_ud(length_tuple[1]))

        # Pressure
        pressure_tuple = data_store.get_data(DataKeys.INLET_P)
        reactor_class.set_pressure(pressure_tuple[0],
                                   UnitDimensionHandler.from_human_to_code_ud(pressure_tuple[1]))

        # Catalytic load
        alfa_tuple = data_store.get_data(DataKeys.ALFA)
        reactor_class.set_catalytic_load(alfa_tuple[0],
                                         UnitDimensionHandler.from_human_to_code_ud(alfa_tuple[1]))

        # Mass flow rate
        q_tuple = data_store.get_data(DataKeys.MASS_FLOW_RATE)
        reactor_class.set_mass_flow_rate(q_tuple[0],
                                         UnitDimensionHandler.from_human_to_code_ud(q_tuple[1]))

        # Inlet composition
        composition_tuple = data_store.get_data(DataKeys.INLET_GAS_COMPOSITION)

        if composition_tuple[1] == CompositionType.MOLE:
            reactor_class.set_inlet_mole_fraction(composition_tuple[0])
        else:
            reactor_class.set_inlet_mass_fraction(composition_tuple[0])

        # Inlet temperature
        temperature_tuple = data_store.get_data(DataKeys.INLET_T)
        reactor_class.set_inlet_temperature(temperature_tuple[0],
                                            UnitDimensionHandler.from_human_to_code_ud(temperature_tuple[1]))

        # Energy balance
        energy_bool = data_store.get_data(DataKeys.ENERGY_BALANCE)
        reactor_class.set_energy(energy_bool)

        # Inert gas specie
        inert_specie_name = data_store.get_data(DataKeys.INERT_GAS_SPECIE)
        reactor_class.set_inert_specie(inert_specie_name)

        # Inert coverage specie
        inert_coverage_name = data_store.get_data(DataKeys.INERT_SURFACE_SPECIE)
        reactor_class.set_inert_coverage(inert_coverage_name)

        # Diffusion
        diffusion = data_store.get_data(DataKeys.DIFFUSION)
        reactor_class.set_gas_diffusion(diffusion)

        # Solid density
        rho_tuple = data_store.get_data(DataKeys.SOLID_RHO)
        reactor_class.set_solid_density(rho_tuple[0],
                                        UnitDimensionHandler.from_human_to_code_ud(rho_tuple[1]))

        # Solid specific heat
        cp_tuple = data_store.get_data(DataKeys.SOLID_CP)
        reactor_class.set_solid_specific_heat(cp_tuple[0],
                                              UnitDimensionHandler.from_human_to_code_ud(cp_tuple[1]))

        # Solid thermal conductivity
        cond_tuple = data_store.get_data(DataKeys.SOLID_COND)
        reactor_class.set_solid_thermal_conductivity(cond_tuple[0],
                                                     UnitDimensionHandler.from_human_to_code_ud(cond_tuple[1]))

        # Solid initial temperature
        temperature_tuple = data_store.get_data(DataKeys.INITIAL_SOLID_T)
        reactor_class.set_initial_solid_temperature(temperature_tuple[0],
                                                    UnitDimensionHandler.from_human_to_code_ud(temperature_tuple[1]))

        reactor_geometry = data_store.get_data(DataKeys.REACTOR_GEOMETRY)
        if reactor_geometry == ReactorGeometry.PACKED_BED:
            # Tube diameter
            diameter_tuple = data_store.get_data(DataKeys.DIAMETER)

            # Particle diameter
            particle_diameter_tuple = data_store.get_data(DataKeys.PARTICLE_DIAMETER)

            # Void fraction
            epsi = data_store.get_data(DataKeys.EPSI)

            reactor_class.set_packed_bed_reactor(particle_diameter_tuple[0],
                                                 UnitDimensionHandler.from_human_to_code_ud(particle_diameter_tuple[1]),
                                                 diameter_tuple[0],
                                                 UnitDimensionHandler.from_human_to_code_ud(diameter_tuple[1]),
                                                 epsi)
        elif reactor_geometry == ReactorGeometry.HONEYCOMB:
            # CPSI
            cpsi = data_store.get_data(DataKeys.CPSI)

            # Wall thickness
            wall_tuple = data_store.get_data(DataKeys.WALL_THICKNESS)

            reactor_class.set_honeycomb_reactor(cpsi,
                                                wall_tuple[0],
                                                UnitDimensionHandler.from_human_to_code_ud(wall_tuple[1]))

        else:
            # Tube diameter
            diameter_tuple = data_store.get_data(DataKeys.DIAMETER)

            # Wall thickness
            wall_tuple = data_store.get_data(DataKeys.WALL_THICKNESS)

            reactor_class.set_tubular_reactor(diameter_tuple[0],
                                              UnitDimensionHandler.from_human_to_code_ud(diameter_tuple[1]),
                                              wall_tuple[0],
                                              UnitDimensionHandler.from_human_to_code_ud(wall_tuple[1]))


        if resolution_method == ReactorResolutionMethod.TRANSIENT:
            # Initial composition
            composition_tuple = data_store.get_data(DataKeys.INITIAL_GAS_COMPOSITION)

            if composition_tuple[1] == CompositionType.MOLE:
                reactor_class.set_initial_mole_fraction(composition_tuple[0])
            else:
                reactor_class.set_initial_mass_fraction(composition_tuple[0])

            # Initial temperature
            temperature_tuple = data_store.get_data(DataKeys.INITIAL_GAS_T)
            reactor_class.set_initial_temperature(temperature_tuple[0],
                                                  UnitDimensionHandler.from_human_to_code_ud(temperature_tuple[1]))

            # Integration time
            tmax_tuple = data_store.get_data(DataKeys.TMAX)
            tmax = uc.convert_to_seconds(tmax_tuple[0],
                                         UnitDimensionHandler.from_human_to_code_ud(tmax_tuple[1]))

            tstep_tuple = data_store.get_data(DataKeys.TSTEP)
            tstep = uc.convert_to_seconds(tstep_tuple[0],
                                          UnitDimensionHandler.from_human_to_code_ud(tstep_tuple[1]))

            num = int(tmax / tstep) + 1

            tspan = np.linspace(0., tmax, num=num, endpoint=True)

            reactor_class.solve(tspan, "s")

            results.put((None,
                         reactor_class.get_time("s"),
                         reactor_class.get_results(),
                         reactor_class.get_length("m")))

        else:
            reactor_class.solve()
            results.put((None,
                         reactor_class.get_time("s"),
                         reactor_class.get_results(),
                         None))
    except Exception as e:
        results.put((''.join(tb.format_exception(None, e, e.__traceback__)),
                     None,
                     None,
                     None))
