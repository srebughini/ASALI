import beerpy
from PyQt5.QtCore import Qt, QTimer
from PyQt5.QtWidgets import QWidget, QVBoxLayout, QLabel, QStackedWidget, QStackedLayout
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

        self.main_layout = self.findChild(QVBoxLayout, 'verticalLayout')

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

    def hide_all_pages(self):
        """
        Hide all layouts
        Returns
        -------

        """
        for i in range(self.main_layout.count()):
            widget_item = self.main_layout.itemAt(i)  # Get the QLayoutItem
            widget = widget_item.widget()  # Extract the widget
            if widget is not None:  # Check if the item is a valid widget
                widget.hide()  # Hide the widget

    def add_page(self, widget) -> None:
        """
        Add a new widget to the QStackedWidget and set it as the current widget.
        Parameters
        ----------
        widget: QWidget
            Widget to be added to the content area

        Returns
        -------

        """
        self.main_layout.addWidget(widget)

    def switch_page(self, page_name):
        """
        Switch to a different widget in the QStackedWidget.
        Parameters
        ----------
        page_name: str
            Name of the page to be shown

        Returns
        -------

        """
        self.hide_all_pages()

        label = self.findChild(QLabel, 'logoLabel')
        label.show()

        label = self.findChild(QLabel, 'beerQuoteLabel')
        label.show()

        layout = self.findChild(QWidget, page_name)
        layout.show()

        self.update_beer_label()
