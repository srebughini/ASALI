import os

from PyQt5.QtWidgets import (
    QMainWindow, QToolBar, QAction, QWidget, QGridLayout
)
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import Qt

from functools import partial

from src.backend.default_input_handler import DefaultInputHandler
from src.backend.user_input_handler import UserInputHandler
from src.frontend.style import WidgetStyle
from src.frontend.utils import Utils


class BasicMainWindow(QMainWindow):
    def __init__(self, parent=None):
        """
        Basic class to setup all windows structures
        """
        # Set backend variables
        super().__init__(parent)
        self.userInput = UserInputHandler()
        self.defaultInput = DefaultInputHandler()
        self.title = "ASALI"

        self.setWindowTitle(self.title)

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

    def _resetUserInput(self):
        """
        Reset user input values
        Returns
        -------

        """
        self.userInput.udk_file_path = None
        self.userInput.file_path = None

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

    def _cleanCentralWidget(self):
        """
        Clean the central widget by remove all children
        Returns
        -------
        """
        layout = self.central_widget.layout()
        if layout is not None:
            Utils.cleanLayout(layout)
            # Clear the layout from the central widget
            QWidget().setLayout(layout)

        Utils.cleanWidget(self.central_widget)

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
        layout.userInput = self.userInput
        self._cleanCentralWidget()
        self.central_widget.setLayout(layout)
        self.central_widget.adjustSize()
        self.adjustSize()

    def runBackEnd(self):
        """
        Run backend to update frontend
        Returns
        -------

        """
        self.central_widget.layout().run_backend()
