from PyQt5.QtWidgets import (
    QMainWindow, QLabel
)

from src.frontend.layout.basic import BasicLayout
from src.frontend.style import FileType
from src.frontend.window.chemkin_to_cantera_converter import ChemkinToCanteraConverterWindow
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
        self._select_chemistry_option_list = [
            Utils.padString("...Select chemistry file..."),
            Utils.padString("Default (no kinetic model)"),
            Utils.padString("Load CANTERA kinetic/properties file"),
            Utils.padString("Load ASALI kinetic file")]

        self._make_chemistry_option_list = [
            Utils.padString("...Make/Check the chemistry file..."),
            Utils.padString("CHEMKIN -> CANTERA converter"),
            Utils.padString("Check ASALI kinetic scheme")]

        super().__init__(main_window)

    def _dropdownSelectChemistryMenuAction(self):
        """
        Action of the select chemistry dropdown menu
        Returns
        -------
        """
        if self.selectChemistryDropDown.currentIndex() == 0:
            self.main_window.userInput.file_path = None
            self.main_window.userInput.udk_file_path = None
        elif self.selectChemistryDropDown.currentIndex() == 1:
            self.main_window.userInput.file_path = self.main_window.defaultInput.defaultChemistryPath
        elif self.selectChemistryDropDown.currentIndex() == 2:
            self.main_window.userInput.file_path = Utils.openFile(self.main_window,
                                                                  file_type=FileType.CANTERA.value)
        elif self.selectChemistryDropDown.currentIndex() == 3:
            self.main_window.userInput.file_path = self.main_window.defaultInput.defaultChemistryPath
            self.main_window.userInput.udk_file_path = Utils.openFile(self.main_window,
                                                                      file_type=FileType.ASALI.value)

    def _dropdownMakeChemistryMenuAction(self):
        """
        Action of the make chemistry dropdown menu
        Returns
        -------
        """
        if self.makeChemistryDropDown.currentIndex() == 1:
            Utils.openNewWindowFromClass(self.main_window, ChemkinToCanteraConverterWindow)
        elif self.makeChemistryDropDown.currentIndex() == 2:
            self.main_window.userInput.file_path = self.main_window.defaultInput.defaultChemistryPath
            self.main_window.userInput.udk_file_path = Utils.openFile(self.main_window,
                                                                      file_type=FileType.ASALI.value)
            if self.main_window.userInput.check_udk_input_file():
                Utils.doneMessage(self.main_window,
                                  self.title,
                                  QLabel("ASALI user defined kinetic file is correct!"))

    def initialize(self):
        """
        Initialize the widgets
        Returns
        -------

        """
        self.nextButton = self._createButton(self.nextButtonText,
                                             self.main_window.updateToCalculationMenuLayout,
                                             self.nextButtonToolTip)
        self.selectChemistryDropDown = self._createDropdown(self._select_chemistry_option_list,
                                                            function=self._dropdownSelectChemistryMenuAction)
        self.makeChemistryDropDown = self._createDropdown(self._make_chemistry_option_list,
                                                          function=self._dropdownMakeChemistryMenuAction)

    def create(self):
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
