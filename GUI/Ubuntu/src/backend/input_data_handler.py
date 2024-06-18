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
        return True
