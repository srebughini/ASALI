from src.core.data_keys import DataKeys


class DataStore:
    def __init__(self):
        """
        Class that handle the data sharing between the GUI and the CORE
        """
        self.data = {k.value: None for k in DataKeys}

    def update_data(self, key, value) -> None:
        """
        Update data in the DataStore class
        Parameters
        ----------
        key: str
            Key for the updated data
        value: object
            Value fot the updated data

        Returns
        -------

        """
        self.data[key] = value

    def get_data(self, key) -> tuple | str | float | dict:
        """
        Returns the requested data from key
        Parameters
        ----------
        key: str
            Key for the updated data

        Returns
        -------
        value: tuple | str | float
            Value for the updated data
        """
        return self.data.get(key, None)

    def check_data(self, key) -> bool:
        """
        Check if the request data exist from key
        Parameters
        ----------
        key: str
            Key for the updated data

        Returns
        -------
        value: bool
            If True the data exist
        """
        return key in self.data.keys()
