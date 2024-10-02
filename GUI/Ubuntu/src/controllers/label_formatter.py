class LabelFormatter:
    """
    Class to formatting the string to be used inside a label
    """

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
