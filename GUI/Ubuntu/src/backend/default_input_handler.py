import os


class DefaultInputHandler:
    def __init__(self):
        """
        Class to handle the default input
        """
        self._imagePath = os.path.join("images")
        self._databasePath = os.path.join("database")
        self._defaultChemistryPath = os.path.join(self._databasePath, "data.yaml")
        self._temperatureUd = ["°C",
                               "K"]
        self._pressureUd = ['Pa',
                            'MPa',
                            'kPa',
                            'torr',
                            'atm',
                            'mmHg',
                            'bar',
                            'mbar']

        self._compositionUd = ['Mass fraction',
                               'Mole fraction']

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

    @property
    def temperatureUd(self):
        """
        Access to the temperature unit dimensions
        Returns
        -------
        temperatureUd: list
            Temperature unit dimensions
        """
        return self._temperatureUd

    @property
    def pressureUd(self):
        """
        Access to the pressure unit dimensions
        Returns
        -------
        pressureUd: list
            Pressure unit dimensions
        """
        return self._pressureUd

    @property
    def compositionUd(self):
        """
        Access to the composition unit dimensions
        Returns
        -------
        compositionUd: list
            Composition unit dimensions
        """
        return self._compositionUd