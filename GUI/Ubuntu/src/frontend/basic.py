from PyQt5.QtWidgets import (
    QMainWindow, QVBoxLayout, QWidget,
    QToolBar, QAction, QStatusBar
)
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import QSize

from GUI.Ubuntu.src.frontend.palette import ColorPalette


class AbstractStyledMainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Modern PyQt Application")
        self.setGeometry(100, 100, 800, 600)

        print()

        self.setStyleSheet(f"background-color: {ColorPalette.BLUE.value}; color: {ColorPalette.LIGHTBLUE.value};")

        # Create a toolbar
        toolbar = QToolBar("Main Toolbar")
        toolbar.setIconSize(QSize(24, 24))
        self.addToolBar(toolbar)

        # Add actions to the toolbar
        exit_action = QAction(QIcon.fromTheme("application-exit"), "Exit", self)
        exit_action.setStatusTip("Exit the application")
        exit_action.triggered.connect(self.close)
        toolbar.addAction(exit_action)

        # Central widget and layout
        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)
        self.layout = QVBoxLayout()
        self.central_widget.setLayout(self.layout)

        # Status bar
        self.status_bar = QStatusBar()
        self.setStatusBar(self.status_bar)
        self.status_bar.showMessage("Ready")

        # Initialize the UI
        self.initUI()

    def initUI(self):
        """
        Initialize the UI components. This method should be implemented by derived classes.
        """
        pass
