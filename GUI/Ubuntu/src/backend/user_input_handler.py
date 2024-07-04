import os
import yaml

from asali.utils.user_defind_kinetic import UserDefinedKinetic
from cantera import Solution, Interface


class UserInputHandler:
    """
    Class to handle input data from users
    """

    def __init__(self):
        self._file_path = None
        self._udk_file_path = None
        self._gas_phase_name = None
        self._surface_phase_name = None

    def get_file_path(self):
        """
        Get chemistry file path
        Returns
        -------
        file_path: str
            Chemistry file path
        """
        return self._file_path

    def set_file_path(self, value):
        """
        Set chemistry file path
        Returns
        -------

        """
        self._file_path = value

    # Creating a property object for chemistry file path
    file_path = property(get_file_path, set_file_path)

    def get_udk_file_path(self):
        """
        Get chemistry file path
        Returns
        -------
        udk_file_path: str
            Chemistry file path
        """
        return self._udk_file_path

    def set_udk_file_path(self, value):
        """
        Set chemistry file path
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
        return self._gas_phase_name

    def set_gas_phase_name(self, value):
        """
        Set gas phase name
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
        return self._surface_phase_name

    def set_surface_phase_name(self, value):
        """
        Set surface phase name
        Returns
        -------

        """
        self._surface_phase_name = value

    # Creating a property object for surface phase name
    surface_phase_name = property(get_surface_phase_name, set_surface_phase_name)

    def _extract_gas_phase_name(self):
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

    def _extract_surface_phase_name(self):
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

    def check_cantera_input_file(self):
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

    def check_udk_input_file(self):
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
    def check_file_extension(file_path, required_extension):
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
    def replace_file_extension(file_path, target_extension):
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

    @staticmethod
    def from_human_to_code_ud(ud):
        """
        Convert from human to code unit dimensions
        Parameters
        ----------
        ud: str
            Unit dimension in human format

        Returns
        -------
        ud: str
            Unit dimension in code format
        """
        cud = ud.replace("°", "deg")
        cud = cud.replace("\u00b3", "**3")
        cud = cud.replace("\u00b2", "**2")
        return cud