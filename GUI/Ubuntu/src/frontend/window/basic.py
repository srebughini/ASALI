import os

from PyQt5.QtWidgets import (
    QMainWindow, QToolBar, QAction, QWidget, QGridLayout, QDesktopWidget
)
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import Qt, QTimer

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

        self.icon = QIcon(os.path.join(self.defaultInput.image_path, "Icon.png"))
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
        self._create_tool_bar()
        self._create_actions()
        self.optionToolBar.addAction(self.contactAction)
        self.optionToolBar.addAction(self.disclaimerAction)
        self.optionToolBar.addAction(self.exitAction)
        self._connect_actions()

        # Central widget and layout
        self.central_widget = QWidget(self)
        self.setCentralWidget(self.central_widget)

    def _reset_user_input(self) -> None:
        """
        Reset user input values
        Returns
        -------

        """
        self.userInput.udk_file_path = None
        self.userInput.file_path = None

    def _create_tool_bar(self) -> None:
        """
        Create QToolBar
        Returns
        -------
        """
        self.optionToolBar = QToolBar("Options Toolbar", self)
        self.optionToolBar.setMovable(False)
        self.addToolBar(self.optionToolBar)

    def _create_actions(self) -> None:
        """
        Create QAction for QToolBar
        Returns
        -------

        """
        self.contactAction = QAction("&Contact", self)
        self.disclaimerAction = QAction("&Disclaimer", self)
        self.exitAction = QAction("&Exit", self)

    def _connect_actions(self) -> None:
        """
        Connect QAction to class functions
        Returns
        -------
        """
        self.contactAction.triggered.connect(partial(Utils.contact_message, self))
        self.disclaimerAction.triggered.connect(partial(Utils.disclaimer_message, self))
        self.exitAction.triggered.connect(self.close)

    def _clean_central_widget(self) -> None:
        """
        Clean the central widget by remove all children
        Returns
        -------
        """
        layout = self.central_widget.layout()
        if layout is not None:
            Utils.clean_layout(layout)
            # Clear the layout from the central widget
            QWidget().setLayout(layout)

        Utils.clean_widget(self.central_widget)

    def set_central_widget_layout(self, layout) -> None:
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
        self._clean_central_widget()
        self.central_widget.setLayout(layout)
        self.central_widget.adjustSize()
        self.adjustSize()
        self.updateGeometry()
        QTimer.singleShot(0, self.center_window_on_active_screen)

    def run_backend(self) -> None:
        """
        Run backend to update frontend
        Returns
        -------

        """
        self.central_widget.layout().run_backend()

    def center_window_on_active_screen(self) -> None:
        """
        Center the window on the active screen
        Returns
        -------

        """
        # Get the screen's available geometry (excluding taskbars, etc.)
        screen_geometry = QDesktopWidget().availableGeometry(self)

        # Get the geometry of the window (including its frame)
        window_geometry = self.frameGeometry()

        # Calculate the center point of the screen
        screen_center = screen_geometry.center()

        # Move the window's center to the center of the screen
        window_geometry.moveCenter(screen_center)

        # Move the window to the calculated top-left point
        self.move(window_geometry.topLeft())
