import os


class InputDataHandler:
    """
    Class to handle input data from users
    """

    def __init__(self):
        self._file_path = None

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

    def check_cantera_input_file(self):
        """
        Check .yaml input file of cantera
        Returns
        -------
        check: bool
            If True the file is correct, if False is not
        """

        """
        gas = Solution(self._file_path)
        for surf_name in surfaces:
            phase = Interface(out_name, surf_name, [gas])
        """

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
