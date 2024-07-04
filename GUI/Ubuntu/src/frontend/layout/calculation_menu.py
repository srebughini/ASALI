from PyQt5.QtWidgets import (
    QMainWindow, QLabel
)

from src.frontend.layout.basic import BasicLayout


class CalculationMenuLayout(BasicLayout):
    def __init__(self, main_window):
        """
        Calculation menu layout
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        self._select_calculation_option_list = ["...",
                                                "Thermodynamic and transport properties",
                                                "Vacuum properties",
                                                "Chemical equilibrium",
                                                "Reactor modeling"]

        super().__init__(main_window)

    def _loadSelectCalculationMenu(self):
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

        self.backButton = self._createButton('Back',
                                             self.main_window.updateToMainMenuLayout,
                                             'Go back to main menu')

        self.selectCalculationDropDown = self._createDropdown(self._select_calculation_option_list,
                                                              function=None)

    def create(self):
        """
        Update the interface
        Returns
        -------
        """
        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel("Select the calculation to perform: "), self.row_idx, 0)
        self.addWidget(self.selectCalculationDropDown, self.row_idx, 1)

        self.row_idx = self.row_idx + 1
        self.addWidget(self.backButton, self.row_idx, 0)
        self.addWidget(self.nextButton, self.row_idx, 1)
