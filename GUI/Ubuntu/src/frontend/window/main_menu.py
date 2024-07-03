from src.frontend.layout.calculation_menu import CalculationMenuLayout
from src.frontend.window.basic import BasicMainWindow
from src.frontend.layout.main_menu import MainMenuLayout
from src.frontend.window.utils import Utils


class MainMenuWindow(BasicMainWindow):
    def __init__(self, parent=None):
        """
        Main menu window
        """
        super().__init__(parent)
        self.setCentralWidgetLayout(MainMenuLayout(self))

    def updateToCalculationMenuLayout(self):
        """
        Update to the CalculationMenuLayout
        Returns
        -------
        """
        Utils.cleanLayout(self.grid)
        print("Pulizia finita")
        self.setCentralWidgetLayout(CalculationMenuLayout(self))
