import os

import beerpy

from PyQt5.QtWidgets import (
    QMainWindow, QLabel, QGridLayout, QPushButton, QComboBox
)
from PyQt5.QtGui import QPixmap
from PyQt5.QtCore import Qt

from src.frontend.style import WidgetStyle


class BasicLayout(QGridLayout):
    def __init__(self, main_window):
        """
        Basic grid layout
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        # Set backend variables
        super().__init__()
        self.main_window = main_window
        self.userInput = self.main_window.userInput
        self.defaultInput = self.main_window.defaultInput
        self.title = self.main_window.title

        self.setVerticalSpacing(25)

        # Create logo
        self.row_idx = 0
        self.addWidget(self._createLogo(os.path.join(self.defaultInput.imagePath, "BigLogo.png")),
                       self.row_idx, 0, 1, -1)

        # Create beer quote
        self.row_idx = self.row_idx + 1
        self.addWidget(self._createBeerLabel(), self.row_idx, 0, 1, -1)

        self.initialize()
        self.create()

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

        label = QLabel(self.main_window)
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

    def _createButton(self, title, function, tooltip):
        """
        Create generic button
        Parameters
        ----------
        title: str
            Button title
        function: function
            Function to be called on click
        tooltip: str
            Tool tips

        Returns
        -------
        button: QPushButton
            Load button
        """
        button = QPushButton(title,
                             self.main_window,
                             clicked=function)
        button.setToolTip(tooltip)
        button.setStyleSheet(WidgetStyle.BUTTON.value)
        return button

    def _createDropdown(self, option_list, function=None):
        """
        Create generic dropdown menu
        Parameters
        ----------
        option_list: List
            List of options
        function: Function (optional)
            Function to be called when dropdown changed

        Returns
        -------
        dropdown: QComboBox
            Dropdown menu
        """
        dropdown = QComboBox(self.main_window)
        dropdown.addItems(option_list)
        dropdown.setStyleSheet(WidgetStyle.DROPDOWN.value)
        if function is not None:
            dropdown.currentIndexChanged.connect(function)
        return dropdown

    def initialize(self):
        """
        Initialize the widgets
        Returns
        -------

        """
        pass

    def create(self):
        """
        Update the interface
        Returns
        -------
        """
        pass
