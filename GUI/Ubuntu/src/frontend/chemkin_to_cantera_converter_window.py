from PyQt5.QtWidgets import QLabel, QComboBox, QPushButton
from GUI.Ubuntu.src.frontend.basic import BasicMainWindow

# Example derived class
from GUI.Ubuntu.src.frontend.style import WidgetStyle


class ChemkinToCanteraConverterWindow(BasicMainWindow):
    def __init__(self, mainWindowObject):
        """
        CHEMKIN -> CANTERA converter window
        Parameters
        ----------
        mainWindowObject: QMainWindow
            QMainWindow object
        """
        super().__init__(mainWindowObject)

    def _createConvertButton(self):
        """
        Generate convert button
        Returns
        -------
        button: QPushButton
            Next page button
        """
        button = QPushButton('Convert', self.mainWindowObject)
        button.setToolTip('Run CHEMKIN -> CANTERA converter')
        button.setStyleSheet(WidgetStyle.BUTTON.value)
        # button.clicked.connect(self._nextWindows)
        return button

    def initWidget(self):
        """
        Initialize the widgets
        Returns
        -------

        """
        self.convertButton = self._createConvertButton()

    def initUI(self):
        """
        Run the User Interface
        Returns
        -------

        """
        # Add a dropdown menu for chemistry option
        self.row_idx = self.row_idx + 1
        self.grid.addWidget(self.convertButton, self.row_idx, 0, 1, -1)
