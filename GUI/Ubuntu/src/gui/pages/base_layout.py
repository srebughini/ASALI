import beerpy
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QWidget, QVBoxLayout, QLabel, QStackedWidget
from PyQt5 import uic

from src.gui.config import Config


class BaseLayout(QWidget):
    def __init__(self):
        """
        Base layout for all pages
        """
        super().__init__()
        # Load the UI from the .ui file
        uic.loadUi(Config.BASE_LAYOUT_PATH.value, self)

        self.update_beer_label()
        self.update_logo()

        # Initialize QStackedWidget for dynamic page switching
        self.content_area = QStackedWidget(self)
        self.findChild(QWidget, 'contentArea').layout().addWidget(self.content_area)

    def update_beer_label(self) -> None:
        """
        Update the beer quote label
        Returns
        -------

        """
        q = beerpy.get_random_quote(language="eng")
        label = self.findChild(QLabel, 'beerQuoteLabel')
        label.setText(f'{q["quote"]}\n[{q["author"]}]')
        label.setAlignment(Qt.AlignCenter)
        label.setWordWrap(True)
        label.setProperty("class", "italic")

    def update_logo(self) -> None:
        """
        Update the logo
        Returns
        -------

        """
        label = self.findChild(QLabel, 'logoLabel')
        label.setAlignment(Qt.AlignCenter)
        label.setProperty("class", "logo")

    def add_content(self, widget):
        """
        Add a new widget to the QStackedWidget and set it as the current widget.
        Parameters
        ----------
        widget: QWidget
            Widget to be added to the content area

        Returns
        -------

        """
        self.content_area.addWidget(widget)
        self.content_area.setCurrentWidget(widget)

    def switch_content(self, index):
        """
        Switch to a different widget in the QStackedWidget.
        Parameters
        ----------
        index: int
            Index of the widget to be displayed.

        Returns
        -------

        """
        self.content_area.setCurrentIndex(index)
