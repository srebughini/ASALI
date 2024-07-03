from PyQt5.QtWidgets import (
    QMainWindow, QLabel, QComboBox
)

from src.frontend.layout.basic import BasicLayout
from src.frontend.style import WidgetStyle, FileType
from src.frontend.window.chemkin_to_cantera_converter import ChemkinToCanteraConverterWindow
from src.frontend.window.utils import Utils


class CalculationMenuLayout(BasicLayout):
    def __init__(self, main_window):
        """
        Calculation menu layout
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        super().__init__(main_window)

    def _loadSelectCalculationMenu(self):
        """
        Load a new window with the selected calculation menu
        Returns
        -------
        """
        pass

    def initialize(self):
        """
        Initialize the widgets
        Returns
        -------

        """
        self.nextButton = self._createButton('Next',
                                             self._loadSelectCalculationMenu,
                                             'Go to next step')

    def create(self):
        """
        Update the interface
        Returns
        -------
        """
        self.row_idx = self.row_idx + 1

        self.addWidget(self.nextButton, self.row_idx, 0, 1, -1)
