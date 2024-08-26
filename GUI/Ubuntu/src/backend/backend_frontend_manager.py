import os
import yaml

from asali.utils.user_defind_kinetic import UserDefinedKinetic
from cantera import Solution, Interface

from src.backend.reactors.parser import ReactorParser


class BackendFrontendManager:
    def __init__(self):
        """
        Class to handle input data from users
        """
        self._file_path = None
        self._udk_file_path = None
        self._gas_phase_name = None
        self._surface_phase_name = None
        self._reactor_parser = None
        self._temperature = {}
        self._pressure = {}
        self._mole_fraction = {}
        self._mass_fraction = {}

    def get_file_path(self) -> str:
        """
        Get chemistry file path
        Returns
        -------
        file_path: str
            Chemistry file path
        """
        return self._file_path

    def set_file_path(self, value) -> None:
        """
        Set chemistry file path
        Parameters
        ----------
        value: str
            Chemistry file path
        Returns
        -------

        """
        self._file_path = value

    # Creating a property object for chemistry file path
    file_path = property(get_file_path, set_file_path)

    def get_temperature(self) -> dict:
        """
        Get mixture temperature
        Returns
        -------
        temperature: dict
            Mixture temperature
        """
        return self._temperature

    def set_temperature(self, value) -> None:
        """
        Set mixture temperature
        Parameters
        ----------
        value: dict
            Mixture temperature
        Returns
        -------

        """
        self._temperature = value

    # Creating a property object for gas mixture temperature
    temperature = property(get_temperature, set_temperature)

    def get_pressure(self) -> dict:
        """
        Get mixture pressure
        Returns
        -------
        pressure: dict
            Mixture pressure
        """
        return self._pressure

    def set_pressure(self, value) -> None:
        """
        Set mixture pressure
        Parameters
        ----------
        value: dict
            Mixture pressure
        Returns
        -------

        """
        self._pressure = value

    # Creating a property object for gas mixture pressure
    pressure = property(get_pressure, set_pressure)

    def get_mole_fraction(self) -> dict:
        """
        Get mixture mole fraction
        Returns
        -------
        mole_fraction: dict
            Mixture mole fraction
        """
        return self._mole_fraction

    def set_mole_fraction(self, value) -> None:
        """
        Set mixture mole fraction
        Parameters
        ----------
        value: dict
            Mixture mole fraction
        Returns
        -------

        """
        self._mole_fraction = value

    def get_mass_fraction(self) -> dict:
        """
        Get mixture mass fraction
        Returns
        -------
        mass_fraction: dict
            Mixture mass fraction
        """
        return self._mass_fraction

    def set_mass_fraction(self, value) -> None:
        """
        Set mixture mass fraction
        Parameters
        ----------
        value: dict
            Mixture mass fraction
        Returns
        -------

        """
        self._mass_fraction = value

    # Creating a property object for gas mixture mass fraction
    mass_fraction = property(get_mass_fraction, set_mass_fraction)

    # Creating a property object for gas mixture mole fraction
    mole_fraction = property(get_mole_fraction, set_mole_fraction)

    def get_udk_file_path(self) -> str:
        """
        Get chemistry file path
        Returns
        -------
        udk_file_path: str
            Chemistry file path
        """
        return self._udk_file_path

    def set_udk_file_path(self, value) -> None:
        """
        Set chemistry file path
        Parameters
        ----------
        value: str
            Chemistry file path
        Returns
        -------

        """
        self._udk_file_path = value

    # Creating a property object for user define kinetic file path
    udk_file_path = property(get_udk_file_path, set_udk_file_path)

    def get_gas_phase_name(self):
        """
        Get gas phase name
        Returns
        -------
        gas_phase_name: str
            Gas phase name
        """
        if self._file_path is None:
            return None

        if self._gas_phase_name is None:
            self._extract_gas_phase_name()

        return self._gas_phase_name

    def set_gas_phase_name(self, value) -> None:
        """
        Set gas phase name
        Parameters
        ----------
        value: str
            Gas phase name
        Returns
        -------

        """
        self._gas_phase_name = value

    # Creating a property object for gas phase name
    gas_phase_name = property(get_gas_phase_name, set_gas_phase_name)

    def get_surface_phase_name(self):
        """
        Get surface phase name
        Returns
        -------
        surface_phase_name: str
            surface phase name
        """
        if self._file_path is None:
            return None

        if self._surface_phase_name is None:
            self._extract_surface_phase_name()

        return self._surface_phase_name

    def set_surface_phase_name(self, value) -> None:
        """
        Set surface phase name
        Parameters
        ----------
        value: str
            surface phase name
        Returns
        -------

        """
        self._surface_phase_name = value

    # Creating a property object for surface phase name
    surface_phase_name = property(get_surface_phase_name, set_surface_phase_name)

    def get_reactor_parser(self) -> ReactorParser:
        """
        Get reactor parser
        Returns
        -------
        reactor_parser: Derived class of backend/reactors/BasicReactorParser
            Class wrapping ASALIPY reactor class
        """

        return self._reactor_parser

    def set_reactor_parser(self, value) -> None:
        """
        Set reactor model class
        Parameters
        ----------
        value: Derived class of backend/reactors/BasicReactorParser
            Class wrapping ASALIPY reactor class

        Returns
        -------

        """
        self._reactor_parser = value

    # Creating a property object for reactor parser
    reactor_parser = property(get_reactor_parser, set_reactor_parser)

    def _extract_gas_phase_name(self) -> None:
        """
        Extract gas phase name from .yaml file
        Returns
        -------

        """
        with open(self._file_path) as stream:
            yaml_as_dict = yaml.safe_load(stream)
            for p in yaml_as_dict['phases']:
                if p["thermo"] == 'ideal-gas':
                    self._gas_phase_name = p["name"]
                    break

    def _extract_surface_phase_name(self) -> None:
        """
        Extract surface phase name from .yaml file
        Returns
        -------

        """
        with open(self._file_path) as stream:
            yaml_as_dict = yaml.safe_load(stream)
            for p in yaml_as_dict['phases']:
                if p["thermo"] == 'ideal-surface':
                    self._surface_phase_name = p["name"]
                    break

    def check_cantera_input_file(self) -> bool:
        """
        Check .yaml input file of cantera
        Returns
        -------
        check: bool
            If True the file is correct
        """
        if self._file_path is None:
            return False

        self._extract_gas_phase_name()
        self._extract_surface_phase_name()

        gas = Solution(self._file_path)
        if self._surface_phase_name is not None:
            phase = Interface(self._file_path, self._surface_phase_name, [gas])

        return True

    def check_udk_input_file(self) -> bool:
        """
        Check .json input file of user define kinetic model
        Returns
        -------
        check: bool
            If True the file is correct
        """
        udk_model = UserDefinedKinetic()
        udk_model.file_path = self._udk_file_path
        gas = Solution(self._file_path)
        if udk_model.file_path is not None:
            udk_model.load_and_validate(gas)
            return True

        return False

    @staticmethod
    def check_file_extension(file_path, required_extension) -> bool:
        """
        Check the file extension
        Parameters
        ----------
        file_path: str
            File path
        required_extension: str
            Required file extension

        Returns
        -------
        check: bool
            If True the file is correct, if False is not
        """
        _, file_extension = os.path.splitext(file_path)
        return file_extension == required_extension

    @staticmethod
    def replace_file_extension(file_path, target_extension) -> str:
        """
        Check the file extension
        Parameters
        ----------
        file_path: str
            File path
        target_extension: str
            New file extension

        Returns
        -------
        new_file_path: str
            File path with the new extension
        """
        file_name, _ = os.path.splitext(file_path)
        return file_name + target_extension
