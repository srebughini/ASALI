from PyQt5.QtWidgets import QLabel

from src.frontend.layout.calculation_main_menu import CalculationMainMenuLayout
from src.frontend.utils import Utils
from src.frontend.window.basic import BasicMainWindow
from src.frontend.layout.main_menu import MainMenuLayout


class MainMenuWindow(BasicMainWindow):
    def __init__(self, parent=None):
        """
        Main menu window
        """
        super().__init__(parent)
        self.update_to_main_menu_layout()

    def update_to_calculation_menu_layout(self) -> None:
        """
        Update to the CalculationMenuLayout
        Returns
        -------
        """
        if self.backend_frontend_manager.udk_file_path is None and self.backend_frontend_manager.file_path is None:
            Utils.error_message(self,
                                Utils.window_title(),
                                QLabel("Chemistry file not selected!"))
        else:
            self.set_central_widget_layout(CalculationMainMenuLayout(self))

    def update_to_main_menu_layout(self) -> None:
        """
        Update to the MainMenuLayout
        Returns
        -------
        """
        self._reset_user_input()
        self.set_central_widget_layout(MainMenuLayout(self))
