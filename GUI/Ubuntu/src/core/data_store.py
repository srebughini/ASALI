from src.core.data_keys import DataKeys


class DataStore:
    def __init__(self):
        """
        Class that handle the data sharing between the GUI and the CORE
        """
        self.data = {}

    def reset_all_data(self) -> None:
        """
        Reset all data
        Returns
        -------

        """
        for k in DataKeys:
            default_value = k.value[0]
            self.data[k] = default_value

    def update_data(self, key, value) -> None:
        """
        Update data in the DataStore class
        Parameters
        ----------
        key: Enum
            Key for the updated data
        value: object
            Value fot the updated data

        Returns
        -------

        """
        if type(key.value[0]) == type(value):
            self.data[key] = value
        else:
            raise Exception(f"Wrong type for {key.value[1]} data key")

    def get_data(self, key) -> tuple | str | float | dict | object:
        """
        Returns the requested data from key
        Parameters
        ----------
        key: Enum
            Key for the updated data

        Returns
        -------
        value: tuple | str | float | dict | object:
            Value for the updated data
        """
        return self.data[key]

    def reset_data(self, key) -> None:
        """
        Reset data to its default value
        Parameters
        ----------
        key: Enum
            Key for the updated data

        Returns
        -------

        """
        default_value = key.value[0]
        self.update_data(key, default_value)
