import os
from abc import abstractmethod

import beerpy

from PyQt5.QtWidgets import (
    QMainWindow, QLabel, QGridLayout, QPushButton, QComboBox, QLineEdit, QSizePolicy, QCheckBox, QLayout
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

        self.nextButtonText = Utils.pad_string_center("Next \u2B9E")
        self.nextButtonToolTip = "Go to the next step"
        self.backButtonText = Utils.pad_string_center("\u2B9C Back")
        self.backButtonToolTip = "Go to the previous step"

        self.setVerticalSpacing(15)
        self.setHorizontalSpacing(12)

        # Create logo
        self.row_idx = 0
        self.addWidget(self._create_logo(os.path.join(self.main_window.defaultInput.image_path, "BigLogo.png")),
                       self.row_idx, 0, 1, -1)

        # Create beer quote
        self.row_idx = self.row_idx + 1
        self.addWidget(self._create_beer_label(), self.row_idx, 0, 1, -1)

        self.create_layout_components()
        self.generate_layout()

    def _create_logo(self, logo_path) -> QLabel:
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

    def _create_beer_label(self) -> QLabel:
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

    def _create_button(self, title, function, tooltip) -> QPushButton:
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

    def _create_dropdown(self, option_list, function=None) -> QComboBox:
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

    def _create_line_edit(self, text, alignment, validator, function=None) -> QLineEdit:
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
        function: func
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
        line_edit.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Fixed)

        font_metrics = line_edit.fontMetrics()
        text_width = font_metrics.horizontalAdvance(Utils.pad_string(text))
        line_edit.setMinimumWidth(text_width)

        if function is not None:
            line_edit.textChanged.connect(function)

        return line_edit

    def _create_check_box(self, text) -> QCheckBox:
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

    def _remove_last_widgets(self, n) -> None:
        """
        Remove last widgets
        Parameters
        ----------
        n: int
            Number of widget to be removed
        Returns
        -------

        """
        n_widget = self.count()
        for i in range(0, n):
            self.itemAt(n_widget - (i + 1)).widget().setParent(None)

    def _remove_widget(self, row_idx, col_idx) -> None:
        """
        Remove last widgets
        Parameters
        ----------
        row_idx: int
            Row position of the widget to be removed
        col_idx: int
            Col position of the widget to be remove

        Returns
        -------

        """
        self.itemAtPosition(row_idx, col_idx).widget().setParent(None)

    def _check_edit_line_float_input(self, edit_line, variable_name) -> None:
        """
        Check single edit line input
        Parameters
        ----------
        edit_line: QLineEdit
            Edit line object
        variable_name: str
            Variable name

        Returns
        -------
        """
        if not Utils.is_float(edit_line.text()):
            Utils.error_message(self.main_window,
                                self.title,
                                QLabel(f"Wrong {variable_name} value."))

    @abstractmethod
    def create_layout_components(self) -> None:
        """
        Initialize the widgets
        Returns
        -------

        """
        pass

    @abstractmethod
    def generate_layout(self) -> None:
        """
        Update the interface
        Returns
        -------
        """
        pass

    @abstractmethod
    def run_backend(self) -> None:
        """
        Run backend to update frontend
        Returns
        -------

        """
        pass
