import sys
import os


class PathHandler:
    """
    Class to handle relative path for executable version
    """

    @staticmethod
    def to_resource_path(relative_path) -> str:
        """
        Get absolute path to resource, works for dev and for PyInstaller
        Parameters
        ----------
        relative_path: str
            Relative path

        Returns
        -------
        resource_path: str
            Resource path
        """
        try:
            # PyInstaller creates a temp folder and stores path in _MEIPASS
            base_path = sys._MEIPASS
        except AttributeError:
            base_path = os.path.abspath(".")

        return os.path.join(base_path, relative_path)
