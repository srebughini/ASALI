from PyQt5.QtWidgets import (
    QMainWindow, QLabel, QComboBox
)

from src.frontend.layout.basic import BasicLayout
from src.frontend.style import WidgetStyle, FileType
from src.frontend.window.chemkin_to_cantera_converter import ChemkinToCanteraConverterWindow
from src.frontend.window.utils import Utils


class MainMenuLayout(BasicLayout):
    def __init__(self, main_window):
        """
        Main menu layout
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        super().__init__(main_window)

    def _createSelectChemistryDropDownMenu(self):
        """
        Create chemistry drop down menu for selection the files to be used
        Returns
        -------
        dropdown: QComboBox
            Chemistry dropdown
        """
        dropdown = QComboBox(self.main_window)
        dropdown.addItems(["...",
                           "Default (only transport/thermodynamic)",
                           "Load CANTERA kinetic/properties file",
                           "Load ASALI kinetic file"])
        dropdown.setStyleSheet(WidgetStyle.DROPDOWN.value)
        dropdown.currentIndexChanged.connect(self._dropdownSelectChemistryMenuAction)
        return dropdown

    def _createMakeChemistryDropDownMenu(self):
        """
        Create chemistry drop down menu to make the chemistry files
        Returns
        -------
        dropdown: QComboBox
            Chemistry dropdown
        """
        dropdown = QComboBox(self.main_window)
        dropdown.addItems(["...",
                           "CHEMKIN -> CANTERA converter",
                           "Check ASALI kinetic scheme"])
        dropdown.setStyleSheet(WidgetStyle.DROPDOWN.value)
        dropdown.currentIndexChanged.connect(self._dropdownMakeChemistryMenuAction)
        return dropdown

    def _dropdownSelectChemistryMenuAction(self):
        """
        Action of the select chemistry dropdown menu
        Returns
        -------
        """
        if self.selectChemistryDropDown.currentIndex() == 1:
            self.userInput.file_path = self.defaultInput.defaultChemistryPath
        elif self.selectChemistryDropDown.currentIndex() == 2:
            self.userInput.file_path = Utils.openFile(self.main_window,
                                                      file_type=FileType.CANTERA.value)
        elif self.selectChemistryDropDown.currentIndex() == 3:
            self.userInput.file_path = self.defaultInput.defaultChemistryPath
            self.userInput.udk_file_path = Utils.openFile(self.main_window,
                                                          file_type=FileType.ASALI.value)

    def _dropdownMakeChemistryMenuAction(self):
        """
        Action of the make chemistry dropdown menu
        Returns
        -------
        """
        if self.makeChemistryDropDown.currentIndex() == 1:
            Utils.openNewWindow(self.main_window, ChemkinToCanteraConverterWindow)
        elif self.makeChemistryDropDown.currentIndex() == 2:
            self.userInput.file_path = self.defaultInput.defaultChemistryPath
            self.userInput.udk_file_path = Utils.openFile(self.main_window,
                                                          file_type=FileType.ASALI.value)
            if self.userInput.check_udk_input_file():
                Utils.doneMessage(self.main_window,
                                  self.title,
                                  QLabel("ASALI user defined kinetic file is correct!"))

    def initialize(self):
        """
        Initialize the widgets
        Returns
        -------

        """
        self.nextButton = self._createButton('Next',
                                             self.main_window.updateToCalculationMenuLayout,
                                             'Go to next step')
        self.selectChemistryDropDown = self._createSelectChemistryDropDownMenu()
        self.makeChemistryDropDown = self._createMakeChemistryDropDownMenu()

    def create(self):
        """
        Update the interface
        Returns
        -------
        """
        self.row_idx = self.row_idx + 1

        self.addWidget(QLabel("Select the chemistry file: "), self.row_idx, 0)
        self.addWidget(self.selectChemistryDropDown, self.row_idx, 1)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel('<p style="text-align: center"><b>or</b></p>'), self.row_idx, 0, 1, -1)

        self.row_idx = self.row_idx + 1
        self.addWidget(QLabel("Select how to make the chemistry file: "), self.row_idx, 0)
        self.addWidget(self.makeChemistryDropDown, self.row_idx, 1)

        self.row_idx = self.row_idx + 1
        self.addWidget(self.nextButton, self.row_idx, 0, 1, -1)
