import os

from PyQt5.QtWidgets import (
    QMainWindow, QToolBar, QAction, QWidget, QGridLayout, QDesktopWidget
)
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import Qt, QTimer

from functools import partial

from src.backend.utils import UnitDimensionHandler, DefaultPath
from src.backend.user_input_handler import UserInputHandler
from src.frontend.layout.reactors.worker import Worker
from src.frontend.style import WidgetStyle
from src.frontend.utils import Utils
from src.frontend.window.run_bar import RunBarWindow


class BasicMainWindow(QMainWindow):
    def __init__(self, parent=None):
        """
        Basic class to setup all windows structures
        """
        # Set backend variables
        super().__init__(parent)
        self._reactor_model_results = None

        self.userInput = UserInputHandler()
        self.ud_handler = UnitDimensionHandler()
        self.title = Utils.window_title()
        self.setWindowTitle(self.title)

        self.icon = QIcon(DefaultPath.icon.value)
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

        self.runBar = RunBarWindow()
        self.worker = Worker()
        self.worker.finished.connect(self.on_finished_for_worker)

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

    def get_reactor_model_results(self) -> dict:
        """
        Get reactor model results
        Returns
        -------
        worker: dict
            Reactor model results
        """

        return self._reactor_model_results

    def set_reactor_model_results(self, value) -> None:
        """
        Set reactor model results
        Parameters
        ----------
        value: dict
            Reactor model results

        Returns
        -------

        """
        self._reactor_model_results = value

    # Creating a property object for surface phase name
    reactor_model_results = property(get_reactor_model_results, set_reactor_model_results)

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
        screen_geometry = QDesktopWidget().availableGeometry(self)
        window_geometry = self.frameGeometry()
        screen_center = screen_geometry.center()
        window_geometry.moveCenter(screen_center)
        self.move(window_geometry.topLeft())

    def update_layout(self, layout_class) -> None:
        """
        Update layout of the window using a layout class
        Parameters
        ----------
        layout_class: Derived class of BasicLayout

        Returns
        -------
        """
        self.set_central_widget_layout(layout_class(self))

    def on_finished_for_worker(self, result) -> None:
        """
        Closes the run bar window
        Returns
        -------

        """
        self.runBar.close_run_bar()
        self._reactor_model_results = result
