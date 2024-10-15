class LabelFormatter:
    """
    Class to formatting the string to be used inside a label
    """

    @staticmethod
    def float_to_string(n) -> str:
        """
        Convert float to string
        Parameters
        ----------
        n: float
            Number as float

        Returns
        -------
        n_str: str
            Number as str
        """
        return LabelFormatter.pad_string("{:.2e}".format(n))

    @staticmethod
    def dict_to_string(d) -> str:
        """
        Convert dict to string
        Parameters
        ----------
        d: dict
            Data as dict

        Returns
        -------
        d_str: str
            Data as str
        """
        return "\n".join(
            [LabelFormatter.pad_string(f"{k}: \t{LabelFormatter.float_to_string(v)}") for k, v in d.items()])

    @staticmethod
    def list_to_string(d) -> str:
        """
        Convert list to string
        Parameters
        ----------
        d: list
            Data as list

        Returns
        -------
        d_str: str
            Data as str
        """
        return "\n".join([LabelFormatter.float_to_string(v) if isinstance(v, float) else v for v in d])

    @staticmethod
    def string_length() -> int:
        """
        Return maximum string length
        Returns
        -------
        length: int
            String length
        """
        return 20

    @staticmethod
    def pad_string(original_str) -> str:
        """
        Pad a string to fixed length
        Parameters
        ----------
        original_str: str
            Original string

        Returns
        -------
        new_str: str
            New string of fixed length
        """
        new_str = f"{original_str:<{LabelFormatter.string_length()}}"
        if len(new_str) < len(original_str):
            print("Error in length str", original_str)
        return new_str

    @staticmethod
    def pad_string_center(original_str) -> str:
        """
        Pad a string to fixed length with text at the center
        Parameters
        ----------
        original_str: str
            Original string

        Returns
        -------
        new_str: str
            New string of fixed length
        """
        new_str = f"{original_str:^{LabelFormatter.string_length()}}"
        if len(new_str) < len(original_str):
            print("Error in length str", original_str)
        return new_str
