import yaml
from asali.utils.user_defind_kinetic import UserDefinedKinetic
from cantera import Solution, Interface


class CanteraFileController:
    """
    Class to control input files
    """

    @staticmethod
    def extract_gas_phase_name_from_cantera(file_path) -> str:
        """
        Extract gas phase name from .yaml file
        Parameters
        ----------
        file_path: str
            Cantera input file path

        Returns
        -------
        gas_phase_name: str
            Gas phase name
        """
        with open(file_path) as stream:
            yaml_as_dict = yaml.safe_load(stream)
            for p in yaml_as_dict['phases']:
                if p["thermo"] == 'ideal-gas':
                    return p["name"]

        raise Exception("Cannot find the gas phase name")

    @staticmethod
    def extract_surface_phase_name_from_cantera(file_path) -> str:
        """
        Extract surface phase name from .yaml file
        Parameters
        ----------
        file_path: str
            Cantera input file path
        Returns
        -------
        surface_phase_name: str
            Surface phase name
        """
        with open(file_path) as stream:
            yaml_as_dict = yaml.safe_load(stream)
            for p in yaml_as_dict['phases']:
                if p["thermo"] == 'ideal-surface':
                    return p["name"]

        return ""

    @staticmethod
    def check_cantera_input_file(file_path) -> bool:
        """
        Check .yaml input file of cantera
        Parameters
        ----------
        file_path: str
            Cantera input file path
        Returns
        -------
        check: bool
            If True the file is correct
        """
        if file_path is None:
            return False

        _ = CanteraFileController.extract_gas_phase_name_from_cantera(file_path)
        surface_phase_name = CanteraFileController.extract_surface_phase_name_from_cantera(file_path)

        gas = Solution(file_path)
        if surface_phase_name is not None:
            _ = Interface(file_path, surface_phase_name, [gas])

        return True

    @staticmethod
    def check_udk_input_file(cantera_file_path, udk_file_path) -> bool:
        """
        Check .json input file of user define kinetic model
        Parameters
        ----------
        cantera_file_path: str
            Cantera input file path
        udk_file_path: str
            User defined kinetic input file path

        Returns
        -------
        check: bool
            If True the file is correct
        """
        udk_model = UserDefinedKinetic()
        udk_model.file_path = udk_file_path

        if not CanteraFileController.check_cantera_input_file(cantera_file_path):
            return False

        gas = Solution(cantera_file_path)
        if udk_model.file_path is not None:
            udk_model.load_and_validate(gas)
            return True

        return False
