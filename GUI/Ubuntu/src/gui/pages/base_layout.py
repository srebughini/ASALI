import beerpy
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QWidget, QVBoxLayout, QLabel
from PyQt5 import uic

from src.config.app import AppConfig


class BaseLayout(QWidget):
    def __init__(self):
        """
        Base layout for all pages
        """
        super().__init__()
        # Load the UI from the .ui file
        uic.loadUi(AppConfig.BASE_LAYOUT_PATH.value, self)

        self.update_beer_label()
        self.update_logo()

        self.container_layout = self.findChild(QVBoxLayout, 'containerLayout')

        self.pages = {}

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

    def update_beer_quote(self) -> None:
        """
        Update beer quote
        Returns
        -------

        """
        q = beerpy.get_random_quote(language="eng")
        label = self.findChild(QLabel, 'beerQuoteLabel')
        label.setText(f'{q["quote"]}\n[{q["author"]}]')

    def hide_page(self, page_name) -> None:
        """
        Hide a specific page by its object name.

        Parameters
        ----------
        page_name : str
            Name of the page to hide
        """
        page_as_widget = self.findChild(QWidget, page_name)
        if page_as_widget is None:
            raise ValueError(f"Page '{page_name}' not found in BaseLayout")

        page_as_widget.setParent(None)
        self.pages.update({page_name: page_as_widget})

    def add_page(self, page_as_widget, page_name) -> None:
        """
        Add a new widget to the QStackedWidget and set it as the current widget.
        Parameters
        ----------
        page_as_widget: QWidget
            Widget to be added to the content area
        page_name : str
            Name of the page to hide
        Returns
        -------

        """
        self.pages.update({page_name: page_as_widget})

    def switch_page(self, page_to_show_name, page_to_hide_name) -> None:
        """
        Switch to a different widget in the container layout.
        Hides the specified page before showing the new page.

        Parameters
        ----------
        page_to_show_name : str
            Name of the page to be shown
        page_to_hide_name : str | None
            Name of the page to hide
        """
        # If the new page is the same as the current page → no switch, no quote update
        if page_to_show_name == page_to_hide_name:
            return

        # Hide the previous page
        if page_to_hide_name is not None:
            self.hide_page(page_to_hide_name)

        page_as_widget = self.pages[page_to_show_name]
        self.container_layout.addWidget(page_as_widget)
        page_as_widget.show()
        page_as_widget.update()
        page_as_widget.update_page_after_switch()

        self.update_beer_quote()

