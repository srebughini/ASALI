import os

from PyQt5.QtWidgets import (
    QMainWindow, QVBoxLayout, QToolBar, QAction, QDialog, QLabel, QPushButton, QWidget, QGridLayout,
    QFileDialog, QMessageBox
)
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import Qt

from functools import partial

from src.backend.default_input_handler import DefaultInputHandler
from src.backend.user_input_handler import UserInputHandler
from src.frontend.style import WidgetStyle, ColorPalette
from src.frontend.window.utils import Utils


class BasicMainWindow(QMainWindow):
    def __init__(self, parent=None):
        """
        Basic class to setup all windows structures
        Parameters
        ----------
        layout: QGridLayout
            Layout to be used
        """
        # Set backend variables
        super().__init__(parent)
        self.userInput = UserInputHandler()
        self.defaultInput = DefaultInputHandler()
        self.title = "ASALI"

        self.setWindowTitle(self.title)

        # self.setGeometry(100, 100, 800, 600)
        self.icon = QIcon(os.path.join(self.defaultInput.imagePath, "Icon.png"))
        self.setWindowIcon(self.icon)
        self.setStyleSheet(WidgetStyle.WINDOW.value)
        self.setWindowFlags(
            Qt.Window |
            Qt.CustomizeWindowHint |
            Qt.WindowTitleHint |
            Qt.WindowMinimizeButtonHint |
            Qt.WindowCloseButtonHint
        )

        # Create tool bar
        self._createToolBar()
        self._createActions()
        self.optionToolBar.addAction(self.contactAction)
        self.optionToolBar.addAction(self.disclaimerAction)
        self.optionToolBar.addAction(self.exitAction)
        self._connectActions()

        # Central widget and layout
        self.central_widget = QWidget(self)
        self.setCentralWidget(self.central_widget)

    def _createToolBar(self):
        """
        Create QToolBar
        Returns
        -------
        """
        self.optionToolBar = QToolBar("Options Toolbar", self)
        self.optionToolBar.setMovable(False)
        self.addToolBar(self.optionToolBar)

    def _createActions(self):
        """
        Create QAction for QToolBar
        Returns
        -------

        """
        self.contactAction = QAction("&Contact", self)
        self.disclaimerAction = QAction("&Disclaimer", self)
        self.exitAction = QAction("&Exit", self)

    def _connectActions(self):
        """
        Connect QAction to class functions
        Returns
        -------
        """
        self.contactAction.triggered.connect(partial(Utils.contactMessage, self))
        self.disclaimerAction.triggered.connect(partial(Utils.disclaimerMessage, self))
        self.exitAction.triggered.connect(self.close)

    def setCentralWidgetLayout(self, layout):
        """
        Set layout for the windows
        Parameters
        ----------
        layout: QGridLayout
            Layout to be used in the central widge

        Returns
        -------
        """
        self.grid = layout
        self.central_widget.setLayout(self.grid)
