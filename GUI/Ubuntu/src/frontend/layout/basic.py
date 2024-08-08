import os
from abc import abstractmethod

import beerpy

from PyQt5.QtWidgets import (
    QMainWindow, QLabel, QGridLayout, QPushButton, QComboBox, QLineEdit, QSizePolicy, QCheckBox
)
from PyQt5.QtGui import QPixmap
from PyQt5.QtCore import Qt

from src.frontend.style import WidgetStyle
from src.frontend.utils import Utils


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
        self.title = self.main_window.title

        self.nextButtonText = Utils.padStringCenter("Next \u2B9E")
        self.nextButtonToolTip = "Go to the next step"
        self.backButtonText = Utils.padStringCenter("\u2B9C Back")
        self.backButtonToolTip = "Go to the previous step"

        self.setVerticalSpacing(15)

        # Create logo
        self.row_idx = 0
        self.addWidget(self._createLogo(os.path.join(self.main_window.defaultInput.imagePath, "BigLogo.png")),
                       self.row_idx, 0, 1, -1)

        # Create beer quote
        self.row_idx = self.row_idx + 1
        self.addWidget(self._createBeerLabel(), self.row_idx, 0, 1, -1)

        self.initialize()
        self.create()

    def _createLogo(self, logo_path) -> QLabel:
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

    def _createBeerLabel(self) -> QLabel:
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

    def _createButton(self, title, function, tooltip) -> QPushButton:
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

    def _createDropdown(self, option_list, function=None) -> QComboBox:
        """
        Create generic dropdown menu
        Parameters
        ----------
        option_list: list
            Dictionary with option as key and style as value
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

    def _createLineEdit(self, text, alignment, validator, f=None) -> QLineEdit:
        """
        Create Qline for input
        Parameters
        ----------
        text: str
            Text to be added as example
        alignment: Qt.Alignment
            Alignment of the text
        validator: QValidator
            Validator for format
        f: func
            Function to be run when text is changed

        Returns
        -------
        line: QLineEdit
            Edit line for input
        """
        line_edit = QLineEdit(self.main_window)
        if validator is not None:
            line_edit.setValidator(validator)
        line_edit.setText(text)
        line_edit.setStyleSheet(WidgetStyle.LINEEDIT.value)
        line_edit.setAlignment(alignment)
        line_edit.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)

        if f is not None:
            line_edit.textChanged.connect(f)

        return line_edit

    def _createCheckBox(self, text) -> QCheckBox:
        """
        Create check box
        Parameters
        ----------
        text: str
            Text to be added

        Returns
        -------
        checkbox: QCheckBox
            Check box for input
        """
        checkbox = QCheckBox(text, self.main_window)
        checkbox.setStyleSheet(WidgetStyle.CHECKBOX.value)
        return checkbox

    @abstractmethod
    def initialize(self) -> None:
        """
        Initialize the widgets
        Returns
        -------

        """
        pass

    @abstractmethod
    def create(self) -> None:
        """
        Update the interface
        Returns
        -------
        """
        pass
