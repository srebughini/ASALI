from PyQt5.QtWidgets import (
    QMainWindow, QLabel
)

from src.backend.utils import DefaultPath
from src.frontend.layout.basic import BasicLayout
from src.frontend.layout.chemkin_to_cantera_converter import ChemkinToCanteraConverterLayout
from src.frontend.style import FileType
from src.frontend.window.basic import BasicMainWindow
from src.frontend.utils import Utils


class MainMenuLayout(BasicLayout):
    def __init__(self, main_window):
        """
        Main menu layout
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        self.nextButton = None
        self.selectChemistryDropDown = None
        self.makeChemistryDropDown = None

        self._select_chemistry_option_list = [
            Utils.pad_string("...Select chemistry file..."),
            Utils.pad_string("Default (no kinetic model)"),
            Utils.pad_string("Load CANTERA kinetic/properties file")]

        self._make_chemistry_option_list = [
            Utils.pad_string("...Make/Check the chemistry file..."),
            Utils.pad_string("CHEMKIN -> CANTERA converter"),
            Utils.pad_string("Check ASALI kinetic scheme")]

        super().__init__(main_window)

    def _dropdown_select_chemistry_menu_action(self) -> None:
        """
        Action of the select chemistry dropdown menu
        Returns
        -------
        """
        if self.selectChemistryDropDown.currentIndex() == 0:
            self.main_window.userInput.file_path = None
            self.main_window.userInput.udk_file_path = None
        elif self.selectChemistryDropDown.currentIndex() == 1:
            self.main_window.userInput.file_path = DefaultPath.defaultChemistry.value
            self.main_window.userInput.udk_file_path = None
        elif self.selectChemistryDropDown.currentIndex() == 2:
            self.main_window.userInput.file_path = Utils.open_file(self.main_window,
                                                                   file_type=FileType.CANTERA.value)
            self.main_window.userInput.udk_file_path = None

    def _dropdown_make_chemistry_menu_action(self) -> None:
        """
        Action of the make chemistry dropdown menu
        Returns
        -------
        """
        if self.makeChemistryDropDown.currentIndex() == 1:
            Utils.open_new_window_from_layout(self.main_window, BasicMainWindow, ChemkinToCanteraConverterLayout)
        elif self.makeChemistryDropDown.currentIndex() == 2:
            self.main_window.userInput.file_path = self.main_window.ud_handler.default_chemistry_path
            self.main_window.userInput.udk_file_path = Utils.open_file(self.main_window,
                                                                       file_type=FileType.ASALI.value)
            if self.main_window.userInput.check_udk_input_file():
                Utils.done_message(self.main_window,
                                   self.title,
                                   QLabel("ASALI user defined kinetic file is correct!"))

    def run_backend(self) -> None:
        """
        Run backend to update frontend
        Returns
        -------

        """
        pass

    def create_layout_components(self) -> None:
        """
        Initialize the widgets
        Returns
        -------

        """
        self.nextButton = self._create_button(self.nextButtonText,
                                              self.main_window.update_to_calculation_menu_layout,
                                              self.nextButtonToolTip)
        self.selectChemistryDropDown = self._create_dropdown(self._select_chemistry_option_list,
                                                             function=self._dropdown_select_chemistry_menu_action)
        self.makeChemistryDropDown = self._create_dropdown(self._make_chemistry_option_list,
                                                           function=self._dropdown_make_chemistry_menu_action)

    def generate_layout(self) -> None:
        """
        Update the interface
        Returns
        -------
        """
        self.row_idx = self.row_idx + 1
        self.addWidget(self.selectChemistryDropDown, self.row_idx, 0)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel('<p style="text-align: center"><b>or</b></p>'), self.row_idx, 0, 1, -1)

        self.row_idx = self.row_idx + 1
        self.addWidget(self.makeChemistryDropDown, self.row_idx, 0)

        self.row_idx = self.row_idx + 1
        self.addWidget(self.nextButton, self.row_idx, 0, 1, -1)
