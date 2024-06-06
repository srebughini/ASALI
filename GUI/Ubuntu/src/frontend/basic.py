import os

from PyQt5.QtWidgets import (
    QMainWindow, QVBoxLayout, QWidget,
    QToolBar, QAction, QStatusBar, QMenu, QMessageBox, QDialog, QLabel, QHBoxLayout
)
from PyQt5.QtGui import QIcon, QPixmap
from PyQt5.QtCore import QSize, Qt

from GUI.Ubuntu.src.frontend.style import WidgetStyle


class AbstractStyledMainWindow(QMainWindow):
    def __init__(self):
        """
        Basic class to set up all windows structures
        """
        super().__init__()
        # Set up windows
        self.setWindowTitle("ASALI")

        self.mainPath = os.path.join("..", "images")

        # self.setGeometry(100, 100, 800, 600)
        self.icon = QIcon(os.path.join(self.mainPath,"Icon.png"))
        self.setWindowIcon(self.icon)
        self.setStyleSheet(WidgetStyle.WINDOW.value)

        # Create menu bar
        self._createToolBar()
        self._createActions()
        self._connectActions()
        self.optionToolBar.addAction(self.contactAction)
        self.optionToolBar.addAction(self.disclaimerAction)
        self.optionToolBar.addAction(self.exitAction)

        # self.menuBar.addMenu(self.optionMenu)

        # Create a toolbar
        # toolbar = QToolBar("Main Toolbar")
        # toolbar.setIconSize(QSize(24, 24))
        # self.addToolBar(toolbar)

        # Add actions to the toolbar
        # exit_action = QAction(QIcon.fromTheme("application-exit"), "Exit", self)
        # exit_action.setStatusTip("Exit the application")
        # exit_action.triggered.connect(self.close)
        # toolbar.addAction(exit_action)

        # Central widget and layout
        # self.central_widget = QWidget()
        # self.setCentralWidget(self.central_widget)
        self.layout = QVBoxLayout()
        # self.central_widget.setLayout(self.layout)

        # Status bar
        # self.status_bar = QStatusBar()
        # self.setStatusBar(self.status_bar)
        # self.status_bar.showMessage("Ready")

        # Initialize the UI
        self.initUI()

    def _createToolBar(self):
        """
        Create toolbar and its options
        """
        self.optionToolBar = QToolBar("Options Toolbar", self)
        self.addToolBar(Qt.LeftToolBarArea, self.optionToolBar)

    def _createActions(self):
        """
        Create actions to be added to menu bar
        """
        self.contactAction = QAction("&Contact", self)
        self.disclaimerAction = QAction("&Disclaimer", self)
        self.exitAction = QAction("&Exit", self)

    def _connectActions(self):
        """
        Connection actions to functions
        """
        self.disclaimerAction.triggered.connect(self._disclaimerMessage)
        self.exitAction.triggered.connect(self.close)

    def _infoMessage(self, msg):
        """
        Info message box
        :param msg: Message text as str
        """


    def _disclaimerMessage(self):
        """
        Show disclaimer message
        """
        # Create a QDialog instance
        dialog = QDialog(self)
        dialog.setWindowTitle("Disclaimer")

        # Create a label with a message
        msg = QLabel("ASALI is free software.\n\nYou can redistribute it and/or modify it the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.\n\nASALI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n\nSee the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with ASALI. If not, see http://www.gnu.org/licenses/.")

        # Create image
        img = QLabel(self)
        pixmap = QPixmap(os.path.join(self.mainPath,"BigLogo.png"))
        img.setPixmap(pixmap)
        img.resize(pixmap.width(), pixmap.height())

        # Create a layout for the dialog
        dialog_layout = QVBoxLayout()
        dialog_layout.addWidget(img)
        dialog_layout.addWidget(msg)

        # Set the layout for the dialog
        dialog.setLayout(dialog_layout)

        # Show the dialog as a modal dialog (blocks the main window)
        dialog.exec_()



    def initUI(self):
        """
        Initialize the UI components. This method should be implemented by derived classes.
        """
        pass
