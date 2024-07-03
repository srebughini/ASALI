import os


class DefaultInputHandler:
    def __init__(self):
        """
        Class to handle the default input
        """
        self._imagePath = os.path.join("images")
        self._databasePath = os.path.join("database")
        self._defaultChemistryPath = os.path.join(self._databasePath, "data.yaml")

    @property
    def imagePath(self):
        """
        Access to the image path
        Returns
        -------
        imagePath: str
            Default image path
        """
        return self._imagePath

    @property
    def databasePath(self):
        """
        Access to the database path
        Returns
        -------
        databasePath: str
            Default database path
        """
        return self._databasePath

    @property
    def defaultChemistryPath(self):
        """
        Access to the chemistry path
        Returns
        -------
        defaultChemistryPath: str
            Default chemistry path
        """
        return self._defaultChemistryPath
