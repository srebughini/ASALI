import os
from abc import ABC, abstractmethod

import beerpy

from PyQt5.QtWidgets import (
    QMainWindow, QVBoxLayout, QToolBar, QAction, QDialog, QLabel, QPushButton, QWidget, QStatusBar, QGridLayout,
    QFileDialog
)
from PyQt5.QtGui import QIcon, QPixmap
from PyQt5.QtCore import Qt

from GUI.Ubuntu.src.backend.input_data_handler import InputDataHandler
from GUI.Ubuntu.src.frontend.style import WidgetStyle, ColorPalette


class BasicMainWindow(ABC):
    def __init__(self, mainWindowObject):
        """
        Basic class to setup all windows structures
        Parameters
        ----------
        mainWindowObject: QMainWindow
            QMainWindow object
        """
        super().__init__()
        # Set backend variables
        self.imagePath = os.path.join("..", "images")
        self.databasePath = os.path.join("..", "database")
        self.defaultChemistryPath = os.path.join(self.databasePath, "data.xml")
        self.inputHandler = InputDataHandler()

        # Set up windows
        self.mainWindowObject = mainWindowObject
        self.mainWindowObject.setWindowTitle("ASALI")

        # self.setGeometry(100, 100, 800, 600)
        self.icon = QIcon(os.path.join(self.imagePath, "Icon.png"))
        self.mainWindowObject.setWindowIcon(self.icon)
        self.mainWindowObject.setStyleSheet(WidgetStyle.WINDOW.value)
        self.mainWindowObject.setWindowFlags(
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
        self.central_widget = QWidget(self.mainWindowObject)
        self.mainWindowObject.setCentralWidget(self.central_widget)
        self.grid = QGridLayout()
        self.grid.setVerticalSpacing(25)
        self.central_widget.setLayout(self.grid)

        # Create logo
        self.logo = self._createLogo(os.path.join(self.imagePath, "BigLogo.png"))
        self.row_idx = 0
        self.grid.addWidget(self.logo, self.row_idx, 0, 1, -1)

        # Create beer quote
        self.beerLabel = self._createBeerLabel()
        self.row_idx = self.row_idx + 1
        self.grid.addWidget(self.beerLabel, self.row_idx, 0, 1, -1)

        # Initialize the widgets
        self.initWidget()

        # Initialize the UI
        self.initUI()

    def _createLogo(self, logo_path):
        """
        Create img from path
        Parameters
        ----------
        logo_path: str
            Logo image path

        Returns
        -------
        label: QLabel
            Image as label
        """

        label = QLabel(self.mainWindowObject)
        pixmap = QPixmap(logo_path)
        label.setPixmap(pixmap)
        label.setAlignment(Qt.AlignCenter)
        label.setStyleSheet(WidgetStyle.LOGO.value)
        return label

    def _createBeerLabel(self):
        """
        Create beer quote label
        Returns
        -------
        label: QLabel
            Image as label
        """
        q = beerpy.get_random_quote(language="eng")
        label = QLabel(f'{q["quote"]}\n[{q["author"]}]')
        label.setAlignment(Qt.AlignCenter)
        label.setWordWrap(True)
        label.setStyleSheet(WidgetStyle.ITALICLABEL.value)
        return label

    def _createToolBar(self):
        """
        Create QToolBar
        Returns
        -------
        """
        self.optionToolBar = QToolBar("Options Toolbar", self.mainWindowObject)
        self.optionToolBar.setMovable(False)
        self.mainWindowObject.addToolBar(self.optionToolBar)

    def _createActions(self):
        """
        Create QAction for QToolBar
        Returns
        -------

        """
        self.contactAction = QAction("&Contact", self.mainWindowObject)
        self.disclaimerAction = QAction("&Disclaimer", self.mainWindowObject)
        self.exitAction = QAction("&Exit", self.mainWindowObject)

    def _connectActions(self):
        """
        Connect QAction to class functions
        Returns
        -------
        """
        self.contactAction.triggered.connect(self._contactMessage)
        self.disclaimerAction.triggered.connect(self._disclaimerMessage)
        self.exitAction.triggered.connect(self.mainWindowObject.close)

    def _dialogMessage(self, title, msg):
        """
        Show message with QDialog
        Parameters
        ----------
        title: str
            QDialog title
        msg: QLabel
            QDialog message

        Returns
        -------
        """
        # Create a QDialog instance
        dialog = QDialog(self.mainWindowObject, Qt.WindowCloseButtonHint)
        dialog.setWindowTitle(title)

        # Add a button
        button = QPushButton("Close", clicked=dialog.close)
        button.setStyleSheet(WidgetStyle.BUTTON.value)

        # Create a layout for the dialog
        dialog_layout = QVBoxLayout()
        dialog_layout.addWidget(msg)
        dialog_layout.addWidget(button)

        # Set the layout for the dialog
        dialog.setLayout(dialog_layout)

        # Show the dialog as a modal dialog (blocks the main window)
        dialog.exec_()

    def _disclaimerMessage(self):
        """
        Show disclaimer with QDialog
        Returns
        -------
        """
        msg = QLabel("""
        ASALI is free software.
        
        You can redistribute it and/or modify it the terms of the GNU General Public License as 
        published by the Free Software Foundation, either version 3 of the License, or (at your 
        option) any later version.
        
        ASALI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
        without even the implied warranty of MERCHANTABILITY or FITNESS FOR A 
        PARTICULAR PURPOSE.
        
        See the GNU General Public License for more details. You should have received a copy 
        of the GNU General Public License along with ASALI. If not, see 
        http://www.gnu.org/licenses/.
        """)
        self._dialogMessage("Disclaimer", msg)

    def _contactMessage(self):
        """
        Show contact with QDialog
        Returns
        -------
        """
        msg = QLabel(f"""<p style="text-align: center">
        <a href='https://srebughini.github.io/ASALI/' style='color:{ColorPalette.LIGHTORANGE.value}'>Website</a>
        <br>
        <br>
        <a href='ste.rebu@outlook.it' style='color:{ColorPalette.LIGHTORANGE.value}'>E-mail</a>
        <br>
        <br>
        <a href='https://github.com/srebughini/ASALI/tree/master' style='color:{ColorPalette.LIGHTORANGE.value}'>Github</a>
        <br>
        <br>
        <a href='https://www.facebook.com/ASALIcode/' style='color:{ColorPalette.LIGHTORANGE.value}'>Facebook</a>
        <br>
        <br>
        <a href='https://www.linkedin.com/company/asalicode' style='color:{ColorPalette.LIGHTORANGE.value}'>LinkedIn</a>
        </p>
        <br>
        <br>
        <a href='https://sourceforge.net/projects/asali' style='color:{ColorPalette.LIGHTORANGE.value}'>SourceForge</a>
        </p>
        """)
        msg.setOpenExternalLinks(True)
        self._dialogMessage("Contacts", msg)

    def _openFile(self):
        """
        Dialog window to open file
        Returns
        -------
        file_path: str
            File path
        """
        fileTuple = QFileDialog.getOpenFileName(self.mainWindowObject, 'OpenFile')

        if len(fileTuple[0]) == 0:
            return None

        return fileTuple[0]

    @abstractmethod
    def initWidget(self):
        """
        Initialize the widgets
        Returns
        -------

        """
        pass

    @abstractmethod
    def initUI(self):
        """
        Run the User Interface
        Returns
        -------

        """
        pass
