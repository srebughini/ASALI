import os

from asali.utils.unit_converter import UnitConverter


class DefaultInputHandler:
    def __init__(self):
        """
        Class to handle the default input
        """
        self._imagePath = os.path.join("images")
        self._databasePath = os.path.join("database")
        self._defaultChemistryPath = os.path.join(self._databasePath, "data.yaml")
        self._uc = UnitConverter()
        self._temperatureUd = [DefaultInputHandler.from_code_to_code_human(ud) for ud in
                               self._uc.temperature_ud().keys()]
        self._pressureUd = ['Pa',
                            'kPa',
                            'MPa',
                            'torr',
                            'atm',
                            'mmHg',
                            'bar',
                            'mbar', ]

        self._compositionUd = ['Mass fraction',
                               'Mole fraction']

        self._massUd = [DefaultInputHandler.from_code_to_code_human(ud) for ud in self._uc.mass_ud().keys()]
        self._lengthUd = [DefaultInputHandler.from_code_to_code_human(ud) for ud in ["m", "cm", "mm"]]
        self._areaUd = [DefaultInputHandler.from_code_to_code_human(ud) for ud in ["m**2", "cm**2", "mm**2"]]
        self._volumeUd = [DefaultInputHandler.from_code_to_code_human(ud) for ud in ["m**3", "cm**3", "mm**3"]]
        self._moleUd = [DefaultInputHandler.from_code_to_code_human(ud) for ud in self._uc.mole_ud().keys()]
        self._viscosityUd = [DefaultInputHandler.from_code_to_code_human(ud) for ud in self._uc.viscosity_ud().keys()]
        self._powerUd = [DefaultInputHandler.from_code_to_code_human(ud) for ud in ["W", "kW", "cal/s", "kcal/s"]]
        self._timeUd = [DefaultInputHandler.from_code_to_code_human(ud) for ud in ['s', 'min', 'h']]
        self._energyUd = [DefaultInputHandler.from_code_to_code_human(ud) for ud in ['J', 'kJ', 'cal', 'kcal']]

        self._thermalConductivityUd = [f"{ud}/K" for ud in DefaultInputHandler.create_fractional_ud(self._powerUd,
                                                                                                    self._lengthUd)]

        self._densityUd = DefaultInputHandler.create_fractional_ud(self._massUd, self._volumeUd)
        self._molecularWeightUd = DefaultInputHandler.create_fractional_ud(self._massUd, self._moleUd)
        self._diffusivityUd = DefaultInputHandler.create_fractional_ud(self._areaUd, self._timeUd)

        self._enthalpyUd = DefaultInputHandler.create_fractional_ud(self._energyUd,
                                                                    ["kg", "g", "kmol", "mol"])

        self._entropyUd = [f"{ud}/K" for ud in self._enthalpyUd]
        self._entropyUd.extend([f"{ud}/°C" for ud in self._enthalpyUd])
        self._specificHeatUd = self._entropyUd

    @staticmethod
    def create_fractional_ud(numerator, denominator):
        """
        Create fractional unit dimensions
        Parameters
        ----------
        numerator: list
            Numerator unit dimensions
        denominator: list
            Denominator unit dimensions

        Returns
        -------
        fraction: list
            Fractional unit dimenions list
        """
        f = list()
        for n in numerator:
            for d in denominator:
                f.append(f"{n}/{d}")

        return f

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
        return cud.strip()

    @staticmethod
    def from_code_to_code_human(ud):
        """
        Convert from code to human unit dimensions
        Parameters
        ----------
        ud: str
            Unit dimension in code format

        Returns
        -------
        ud: str
            Unit dimension in human format
        """
        cud = ud.replace("deg", "°")
        cud = cud.replace("**3", "\u00b3")
        cud = cud.replace("**2", "\u00b2")
        return cud.strip()

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

    @property
    def densityUd(self):
        """
        Access to the density unit dimensions
        Returns
        -------
        densityUd: list
            Density unit dimensions
        """
        return self._densityUd

    @property
    def molecularWeigthUd(self):
        """
        Access to the molecular weight unit dimensions
        Returns
        -------
        molecularWeightUd: list
            Molecular weight unit dimensions
        """
        return self._molecularWeightUd

    @property
    def viscosityUd(self):
        """
        Access to the viscosity unit dimensions
        Returns
        -------
        viscosityUd: list
            Viscosity unit dimensions
        """
        return self._viscosityUd

    @property
    def thermalConductivityUd(self):
        """
        Access to the thermal conductivity unit dimensions
        Returns
        -------
        thermalConductivityUd: list
            Thermal conductivity unit dimensions
        """
        return self._thermalConductivityUd

    @property
    def diffusivityUd(self):
        """
        Access to the diffusivity unit dimensions
        Returns
        -------
        diffusivityUd: list
            Thermal diffusivity unit dimensions
        """
        return self._diffusivityUd

    @property
    def enthalpyUd(self):
        """
        Access to the enthalpy unit dimensions
        Returns
        -------
        enthalpyUd: list
            Enthalpy unit dimensions
        """
        return self._enthalpyUd

    @property
    def entropyUd(self):
        """
        Access to the entropy unit dimensions
        Returns
        -------
        entropyUd: list
            Entropy unit dimensions
        """
        return self._entropyUd

    @property
    def specificHeatUd(self):
        """
        Access to the specific heat unit dimensions
        Returns
        -------
        specificHeatUd: list
            Specific heat unit dimensions
        """
        return self._specificHeatUd

