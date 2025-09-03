from PyQt5.QtCore import QLocale
from PyQt5.QtGui import QDoubleValidator


class EditLinesValidator:
    """
    Class to generate edit lines validators
    """

    @staticmethod
    def double_validator(min_value, max_value, number_of_digits):
        """
        Edit line double validator
        Parameters
        ----------
        min_value: float
            Min value
        max_value: float
            Max value
        number_of_digits: int
            Number of digits

        Returns
        -------
        validator: QDoubleValidator
        """
        validator = QDoubleValidator(min_value, max_value, number_of_digits)
        validator.setLocale(QLocale(QLocale.C))
        return validator
