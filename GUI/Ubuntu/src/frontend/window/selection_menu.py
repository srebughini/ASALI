from PyQt5.QtWidgets import QLabel

from src.frontend.layout.calculation_menu import CalculationMenuLayout
from src.frontend.utils import Utils
from src.frontend.window.basic import BasicMainWindow
from src.frontend.layout.main_menu import MainMenuLayout


class SelectionMenuWindow(BasicMainWindow):
    def __init__(self, parent=None):
        """
        Main menu window
        """
        super().__init__(parent)
        self.updateToMainMenuLayout()

    def updateToCalculationMenuLayout(self):
        """
        Update to the CalculationMenuLayout
        Returns
        -------
        """
        if self.userInput.udk_file_path is None and self.userInput.file_path is None:
            Utils.errorMessage(self,
                               self.title,
                               QLabel("Chemistry file not selected!"))
        else:
            self.setCentralWidgetLayout(CalculationMenuLayout(self))

    def updateToMainMenuLayout(self):
        """
        Update to the MainMenuLayout
        Returns
        -------
        """
        self._resetUserInput()
        self.setCentralWidgetLayout(MainMenuLayout(self))
