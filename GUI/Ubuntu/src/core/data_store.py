class DataStore:
    def __init__(self):
        """
        Class that handle the data sharing between the GUI and the CORE
        """
        self.data = {}

    def update_data(self, key, value):
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

    def get_data(self, key):
        """
        Returns the requested data from key
        Parameters
        ----------
        key: str
            Key for the updated data

        Returns
        -------
        value: object
            Value fot the updated data
        """
        return self.data.get(key, None)
