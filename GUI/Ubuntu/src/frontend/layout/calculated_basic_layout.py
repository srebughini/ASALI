from abc import abstractmethod
from PyQt5.QtWidgets import QMainWindow
from src.frontend.layout.basic import BasicLayout


class CalculatedBasicLayout(BasicLayout):
    def __init__(self, main_window):
        """
        Abstract class for properties and reactors layouts
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        super().__init__(main_window)

    @abstractmethod
    def runBackend(self):
        """
        Run backend to update frontend
        Returns
        -------

        """
        pass

    @abstractmethod
    def initialize(self):
        """
        Initialize the widgets
        Returns
        -------

        """
        pass

    @abstractmethod
    def create(self):
        """
        Update the interface
        Returns
        -------
        """
        pass
