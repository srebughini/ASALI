from asali.reactors.batch import BatchReactor
from asali.reactors.cstr import CstrReactor
from asali.reactors.ph1d_steady_state import SteadyStatePseudoHomogeneous1DReactor
from asali.reactors.ph1d_transient import TransientPseudoHomogeneous1DReactor
from asali.utils.unit_converter import UnitConverter

from src.backend.utils import ReactorResultsFormat
from src.frontend.utils import ReactorVariablesName, BasicUnitDimension
import numpy as np


def run_batch_reactor_model(cantera_input_file,
                            gas_phase_name,
                            surface_phase_name,
                            input_dict,
                            results) -> None:
    """
    Run BatchReactor model
    Parameters
    ----------
    cantera_input_file: str
        Cantera input file path
    gas_phase_name: str
        Gas phase name
    surface_phase_name: str
        Surface phase name
    input_dict: dict
        Input dict from user input
    results: multiprocessing.Queue()
        Results to be saved

    Returns
    -------
    """
    reactor_class = BatchReactor(cantera_input_file, gas_phase_name, surface_phase_name)
    unit_converter = UnitConverter()

    if input_dict[ReactorVariablesName.udk] is not None:
        reactor_class.set_user_defined_kinetic_model(input_dict[ReactorVariablesName.udk])
    else:
        reactor_class.set_initial_coverage(input_dict[ReactorVariablesName.z])

    reactor_class.set_volume(input_dict[ReactorVariablesName.volume].value,
                             input_dict[ReactorVariablesName.volume].ud)
    reactor_class.set_pressure(input_dict[ReactorVariablesName.pressure].value,
                               input_dict[ReactorVariablesName.pressure].ud)
    reactor_class.set_catalytic_load(input_dict[ReactorVariablesName.alfa].value,
                                     input_dict[ReactorVariablesName.alfa].ud)

    if input_dict[ReactorVariablesName.initialX] is not None:
        reactor_class.set_initial_mole_fraction(input_dict[ReactorVariablesName.initialX])

    if input_dict[ReactorVariablesName.initialY] is not None:
        reactor_class.set_initial_mass_fraction(input_dict[ReactorVariablesName.initialY])

    reactor_class.set_initial_temperature(input_dict[ReactorVariablesName.initialTemperature].value,
                                          input_dict[ReactorVariablesName.initialTemperature].ud)
    reactor_class.set_energy(input_dict[ReactorVariablesName.energy])

    tmax = unit_converter.convert_to_seconds(input_dict[ReactorVariablesName.time].value,
                                             input_dict[ReactorVariablesName.time].ud)

    tstep = unit_converter.convert_to_seconds(input_dict[ReactorVariablesName.timeStep].value,
                                              input_dict[ReactorVariablesName.timeStep].ud)

    num = int(tmax / tstep) + 1

    tspan = np.linspace(0., tmax, num=num, endpoint=True)

    reactor_class.solve(tspan, BasicUnitDimension.time.value)

    results.put({ReactorResultsFormat.x: reactor_class.get_time(BasicUnitDimension.time.value),
                 ReactorResultsFormat.y: reactor_class.get_results()})


def run_cstr_reactor_model(cantera_input_file,
                           gas_phase_name,
                           surface_phase_name,
                           input_dict,
                           results) -> None:
    """
    Run CstrReactor model
    Parameters
    ----------
    cantera_input_file: str
        Cantera input file path
    gas_phase_name: str
        Gas phase name
    surface_phase_name: str
        Surface phase name
    input_dict: dict
        Input dict from user input
    results: multiprocessing.Queue()
        Results to be saved

    Returns
    -------
    reactor_class: CstrReactor
        Reactor class
    """
    reactor_class = CstrReactor(cantera_input_file, gas_phase_name, surface_phase_name)
    unit_converter = UnitConverter()

    if input_dict[ReactorVariablesName.udk] is not None:
        reactor_class.set_user_defined_kinetic_model(input_dict[ReactorVariablesName.udk])
    else:
        reactor_class.set_initial_coverage(input_dict[ReactorVariablesName.z])

    reactor_class.set_volume(input_dict[ReactorVariablesName.volume].value,
                             input_dict[ReactorVariablesName.volume].ud)
    reactor_class.set_pressure(input_dict[ReactorVariablesName.pressure].value,
                               input_dict[ReactorVariablesName.pressure].ud)
    reactor_class.set_catalytic_load(input_dict[ReactorVariablesName.alfa].value,
                                     input_dict[ReactorVariablesName.alfa].ud)
    reactor_class.set_mass_flow_rate(input_dict[ReactorVariablesName.massFlowRate].value,
                                     input_dict[ReactorVariablesName.massFlowRate].ud)

    if input_dict[ReactorVariablesName.initialX] is not None:
        reactor_class.set_initial_mole_fraction(input_dict[ReactorVariablesName.initialX])

    if input_dict[ReactorVariablesName.initialY] is not None:
        reactor_class.set_initial_mass_fraction(input_dict[ReactorVariablesName.initialY])

    if input_dict[ReactorVariablesName.x] is not None:
        reactor_class.set_inlet_mole_fraction(input_dict[ReactorVariablesName.x])

    if input_dict[ReactorVariablesName.y] is not None:
        reactor_class.set_inlet_mass_fraction(input_dict[ReactorVariablesName.y])

    reactor_class.set_initial_temperature(input_dict[ReactorVariablesName.initialTemperature].value,
                                          input_dict[ReactorVariablesName.initialTemperature].ud)

    reactor_class.set_inlet_temperature(input_dict[ReactorVariablesName.temperature].value,
                                        input_dict[ReactorVariablesName.temperature].ud)
    reactor_class.set_energy(input_dict[ReactorVariablesName.energy])

    tmax = unit_converter.convert_to_seconds(input_dict[ReactorVariablesName.time].value,
                                             input_dict[ReactorVariablesName.time].ud)

    tstep = unit_converter.convert_to_seconds(input_dict[ReactorVariablesName.timeStep].value,
                                              input_dict[ReactorVariablesName.timeStep].ud)

    num = int(tmax / tstep) + 1

    tspan = np.linspace(0., tmax, num=num, endpoint=True)

    reactor_class.solve(tspan, BasicUnitDimension.time.value)

    results.put({ReactorResultsFormat.x: reactor_class.get_time(BasicUnitDimension.time.value),
                 ReactorResultsFormat.y: reactor_class.get_results()})


def run_steady_state_pseudo_homogeneous_reactor_model(cantera_input_file,
                                                      gas_phase_name,
                                                      surface_phase_name,
                                                      input_dict,
                                                      results) -> None:
    """
    Run SteadyStatePseudoHomogeneous1DReactor model
    Parameters
    ----------
    cantera_input_file: str
        Cantera input file path
    gas_phase_name: str
        Gas phase name
    surface_phase_name: str
        Surface phase name
    input_dict: dict
        Input dict from user input
    results: multiprocessing.Queue()
        Results to be saved

    Returns
    -------
    """
    reactor_class = SteadyStatePseudoHomogeneous1DReactor(cantera_input_file, gas_phase_name, surface_phase_name)
    unit_converter = UnitConverter()

    if input_dict[ReactorVariablesName.udk] is not None:
        reactor_class.set_user_defined_kinetic_model(input_dict[ReactorVariablesName.udk])
    else:
        reactor_class.set_initial_coverage(input_dict[ReactorVariablesName.z])

    L = unit_converter.convert_to_meter(input_dict[ReactorVariablesName.length].value,
                                        input_dict[ReactorVariablesName.length].ud)

    dL = unit_converter.convert_to_meter(input_dict[ReactorVariablesName.lengthStep].value,
                                         input_dict[ReactorVariablesName.lengthStep].ud)

    num = int(L / dL) + 1

    length = np.linspace(0., L, num=num, endpoint=True)

    reactor_class.set_length(length, BasicUnitDimension.length.value)

    reactor_class.set_diameter(input_dict[ReactorVariablesName.diameter].value,
                               input_dict[ReactorVariablesName.diameter].ud)
    reactor_class.set_pressure(input_dict[ReactorVariablesName.pressure].value,
                               input_dict[ReactorVariablesName.pressure].ud)
    reactor_class.set_catalytic_load(input_dict[ReactorVariablesName.alfa].value,
                                     input_dict[ReactorVariablesName.alfa].ud)
    reactor_class.set_mass_flow_rate(input_dict[ReactorVariablesName.massFlowRate].value,
                                     input_dict[ReactorVariablesName.massFlowRate].ud)

    if input_dict[ReactorVariablesName.x] is not None:
        reactor_class.set_inlet_mole_fraction(input_dict[ReactorVariablesName.x])

    if input_dict[ReactorVariablesName.y] is not None:
        reactor_class.set_inlet_mass_fraction(input_dict[ReactorVariablesName.y])

    reactor_class.set_inlet_temperature(input_dict[ReactorVariablesName.temperature].value,
                                        input_dict[ReactorVariablesName.temperature].ud)
    reactor_class.set_energy(input_dict[ReactorVariablesName.energy])

    reactor_class.set_inert_specie(input_dict[ReactorVariablesName.inertSpecie])
    reactor_class.set_inert_coverage(input_dict[ReactorVariablesName.inertCoverage])
    reactor_class.set_gas_diffusion(input_dict[ReactorVariablesName.diffusion])

    reactor_class.solve()

    results.put({ReactorResultsFormat.x: reactor_class.get_length(BasicUnitDimension.length.value),
                 ReactorResultsFormat.y: reactor_class.get_results()})


def run_transient_pseudo_homogeneous_reactor_model(cantera_input_file,
                                                   gas_phase_name,
                                                   surface_phase_name,
                                                   input_dict,
                                                   results) -> None:
    """
    Run TransientPseudoHomogeneous1DReactor model
    Parameters
    ----------
    cantera_input_file: str
        Cantera input file path
    gas_phase_name: str
        Gas phase name
    surface_phase_name: str
        Surface phase name
    input_dict: dict
        Input dict from user input
    results: multiprocessing.Queue()
        Results to be saved

    Returns
    -------
    """

    reactor_class = TransientPseudoHomogeneous1DReactor(cantera_input_file, gas_phase_name, surface_phase_name)
    unit_converter = UnitConverter()

    if input_dict[ReactorVariablesName.udk] is not None:
        reactor_class.set_user_defined_kinetic_model(input_dict[ReactorVariablesName.udk])
    else:
        reactor_class.set_initial_coverage(input_dict[ReactorVariablesName.z])

    L = unit_converter.convert_to_meter(input_dict[ReactorVariablesName.length].value,
                                        input_dict[ReactorVariablesName.length].ud)

    dL = unit_converter.convert_to_meter(input_dict[ReactorVariablesName.lengthStep].value,
                                         input_dict[ReactorVariablesName.lengthStep].ud)

    num = int(L / dL) + 1

    length = np.linspace(0., L, num=num, endpoint=True)

    reactor_class.set_length(length, BasicUnitDimension.length.value)

    reactor_class.set_diameter(input_dict[ReactorVariablesName.diameter].value,
                               input_dict[ReactorVariablesName.diameter].ud)
    reactor_class.set_pressure(input_dict[ReactorVariablesName.pressure].value,
                               input_dict[ReactorVariablesName.pressure].ud)
    reactor_class.set_catalytic_load(input_dict[ReactorVariablesName.alfa].value,
                                     input_dict[ReactorVariablesName.alfa].ud)
    reactor_class.set_mass_flow_rate(input_dict[ReactorVariablesName.massFlowRate].value,
                                     input_dict[ReactorVariablesName.massFlowRate].ud)

    if input_dict[ReactorVariablesName.x] is not None:
        reactor_class.set_inlet_mole_fraction(input_dict[ReactorVariablesName.x])

    if input_dict[ReactorVariablesName.y] is not None:
        reactor_class.set_inlet_mass_fraction(input_dict[ReactorVariablesName.y])

    reactor_class.set_inlet_temperature(input_dict[ReactorVariablesName.temperature].value,
                                        input_dict[ReactorVariablesName.temperature].ud)

    if input_dict[ReactorVariablesName.initialX] is not None:
        reactor_class.set_initial_mole_fraction(input_dict[ReactorVariablesName.initialX])

    if input_dict[ReactorVariablesName.initialY] is not None:
        reactor_class.set_initial_mass_fraction(input_dict[ReactorVariablesName.initialY])

    reactor_class.set_initial_temperature(input_dict[ReactorVariablesName.initialTemperature].value,
                                          input_dict[ReactorVariablesName.initialTemperature].ud)

    reactor_class.set_energy(input_dict[ReactorVariablesName.energy])
    reactor_class.set_inert_specie(input_dict[ReactorVariablesName.inertSpecie])
    reactor_class.set_inert_coverage(input_dict[ReactorVariablesName.inertCoverage])
    reactor_class.set_gas_diffusion(input_dict[ReactorVariablesName.diffusion])

    tmax = unit_converter.convert_to_seconds(input_dict[ReactorVariablesName.time].value,
                                             input_dict[ReactorVariablesName.time].ud)

    tstep = unit_converter.convert_to_seconds(input_dict[ReactorVariablesName.timeStep].value,
                                              input_dict[ReactorVariablesName.timeStep].ud)

    num = int(tmax / tstep) + 1

    tspan = np.linspace(0., tmax, num=num, endpoint=True)

    reactor_class.solve(tspan, BasicUnitDimension.time.value)

    results.put({ReactorResultsFormat.x: reactor_class.get_time(BasicUnitDimension.time.value),
                 ReactorResultsFormat.y: reactor_class.get_results()})
