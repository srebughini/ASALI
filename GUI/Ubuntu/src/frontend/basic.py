import os

from PyQt5.QtWidgets import (
    QMainWindow, QVBoxLayout, QToolBar, QAction, QDialog, QLabel, QPushButton, QWidget, QStatusBar, QGridLayout
)
from PyQt5.QtGui import QIcon, QPixmap
from PyQt5.QtCore import Qt

from GUI.Ubuntu.src.frontend.style import WidgetStyle, ColorPalette


class BasicMainWindow(QMainWindow):
    def __init__(self):
        """
        Basic class to setup all windows structures
        """
        super().__init__()
        # Set up windows
        self.setWindowTitle("ASALI")

        self.mainPath = os.path.join("..", "images")

        #self.setGeometry(100, 100, 800, 600)
        self.icon = QIcon(os.path.join(self.mainPath, "Icon.png"))
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
        self._connectActions()
        self.optionToolBar.addAction(self.contactAction)
        self.optionToolBar.addAction(self.disclaimerAction)
        self.optionToolBar.addAction(self.exitAction)

        # Central widget and layout
        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)
        self.grid = QGridLayout()
        self.central_widget.setLayout(self.grid)

        self.logo = self._createLogo(os.path.join(self.mainPath, "BigLogo.png"))
        self.img_row_idx = 0
        self.img_col_idx = 0
        self.grid.addWidget(self.logo, self.img_col_idx, self.img_row_idx, -1, -1)



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

        label = QLabel(self)
        pixmap = QPixmap(logo_path)
        label.setPixmap(pixmap)
        label.setAlignment(Qt.AlignCenter)
        label.setStyleSheet(WidgetStyle.LOGO.value)
        return label

    def _createToolBar(self):
        """
        Create QToolBar
        Returns
        -------

        """
        self.optionToolBar = QToolBar("Options Toolbar", self)
        self.addToolBar(Qt.LeftToolBarArea, self.optionToolBar)

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
        self.contactAction.triggered.connect(self._contactMessage)
        self.disclaimerAction.triggered.connect(self._disclaimerMessage)
        self.exitAction.triggered.connect(self.close)

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
        dialog = QDialog(self, Qt.WindowCloseButtonHint)
        dialog.setWindowTitle(title)

        # Add a button
        button = QPushButton("Close")
        button.setStyleSheet(WidgetStyle.BUTTON.value)
        button.clicked.connect(dialog.close)

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

    def initUI(self):
        """
        Run the User Interface
        Returns
        -------

        """
        pass
