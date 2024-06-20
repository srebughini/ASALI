from PyQt5.QtWidgets import QLabel, QComboBox, QPushButton, QMainWindow
from GUI.Ubuntu.src.frontend.basic import BasicMainWindow

# Example derived class
from GUI.Ubuntu.src.frontend.chemkin_to_cantera_converter import ChemkinToCanteraConverterWindow
from GUI.Ubuntu.src.frontend.style import WidgetStyle


class SelectChemistryWindow(BasicMainWindow):
    def __init__(self, mainWindowObject):
        """
        Select chemistry main window
        Parameters
        ----------
        mainWindowObject: QMainWindow
            QMainWindow object
        """
        super().__init__(mainWindowObject)

    def _createNextButton(self):
        """
        Generate next button
        Returns
        -------
        button: QPushButton
            Next page button
        """
        button = QPushButton('Next', self.mainWindowObject)
        button.setToolTip('Go to next step')
        button.setStyleSheet(WidgetStyle.BUTTON.value)
        # button.clicked.connect(self._nextWindows)
        return button

    def _createSelectChemistryDropDownMenu(self):
        """
        Create chemistry drop down menu for selection the files to be used
        Returns
        -------
        dropdown: QComboBox
            Chemistry dropdown
        """
        dropdown = QComboBox(self.mainWindowObject)
        dropdown.addItems(["...",
                           "Default (only transport/thermodynamic)",
                           "Load CANTERA kinetic/properties file"])
        dropdown.setStyleSheet(WidgetStyle.DROPDOWN.value)
        dropdown.currentIndexChanged.connect(self.on_dropdown_select_chemistry_menu_changed)
        return dropdown

    def _createMakeChemistryDropDownMenu(self):
        """
        Create chemistry drop down menu to make the chemistry files
        Returns
        -------
        dropdown: QComboBox
            Chemistry dropdown
        """
        dropdown = QComboBox(self.mainWindowObject)
        dropdown.addItems(["...",
                           "CHEMKIN -> CANTERA converter",
                           "Make/Check ASALI kinetic scheme"])
        dropdown.setStyleSheet(WidgetStyle.DROPDOWN.value)
        dropdown.currentIndexChanged.connect(self.on_dropdown_make_chemistry_menu_changed)
        return dropdown

    def initWidget(self):
        """
        Initialize the widgets
        Returns
        -------

        """
        self.nextButton = self._createNextButton()
        self.selectChemistryDropDown = self._createSelectChemistryDropDownMenu()
        self.makeChemistryDropDown = self._createMakeChemistryDropDownMenu()

    def initUI(self):
        """
        Run the User Interface
        Returns
        -------

        """
        # self.grid.setColumnStretch(0, 1)
        # self.grid.setColumnStretch(1, 1)

        # Add a dropdown menu for chemistry option
        self.row_idx = self.row_idx + 1

        self.grid.addWidget(QLabel("Select the chemistry file: "), self.row_idx, 0)
        self.grid.addWidget(self.selectChemistryDropDown, self.row_idx, 1)

        self.row_idx = self.row_idx + 1
        self.grid.addWidget(QLabel('<p style="text-align: center"><b>or</b></p>'), self.row_idx, 0, 1, -1)

        self.row_idx = self.row_idx + 1
        self.grid.addWidget(QLabel("Select how to make the chemistry file: "), self.row_idx, 0)
        self.grid.addWidget(self.makeChemistryDropDown, self.row_idx, 1)

        self.row_idx = self.row_idx + 1
        self.grid.addWidget(self.nextButton, self.row_idx, 0, 1, -1)

    def on_dropdown_select_chemistry_menu_changed(self):
        """
        Action of the select chemistry dropdown menu
        Returns
        -------
        """
        file_path = None
        if self.selectChemistryDropDown.currentIndex() == 1:
            self.inputHandler.file_path = self.defaultChemistryPath
        elif self.selectChemistryDropDown.currentIndex() == 2:
            self.inputHandler.file_path = self._openFile()

    def on_dropdown_make_chemistry_menu_changed(self):
        """
        Action of the make chemistry dropdown menu
        Returns
        -------
        """
        if self.makeChemistryDropDown.currentIndex() == 1:
            self.secondWindowObject = QMainWindow()
            window = ChemkinToCanteraConverterWindow(self.secondWindowObject)
            self.secondWindowObject.show()
