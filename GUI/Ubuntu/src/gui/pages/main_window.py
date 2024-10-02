from PyQt5.QtCore import Qt
from PyQt5.QtGui import QIcon
from PyQt5.QtWidgets import QMainWindow, QToolBar, QAction

from src.core.data_store import DataStore
from src.gui.config import Config
from src.gui.pages.base_layout import BaseLayout
from src.gui.pages.calculation_input_page import CalculationInputPage
from src.gui.pages.chemistry_input_page import ChemistryInputPage
from src.gui.pages.dialog_pages_handler import DialogPagesHandler
from src.gui.pages.file_handler_pages import FileHandlerPages


class MainWindow(QMainWindow):
    def __init__(self):
        """
        Main class to orchestrate the switching between different pages
        """
        super().__init__()
        self.data_store = DataStore()

        self.dialog_handler = DialogPagesHandler(self)
        self.file_handler = FileHandlerPages(self, self.data_store)

        # Add title
        self.setWindowTitle(Config.TITLE.value)

        # Add icons
        self.setWindowIcon(QIcon(Config.ICON_PATH.value))

        # Set flags
        self.setWindowFlags(
            Qt.Window |
            Qt.CustomizeWindowHint |
            Qt.WindowTitleHint |
            Qt.WindowMinimizeButtonHint |
            Qt.WindowCloseButtonHint
        )

        # Create tool bar
        self.create_tool_bar()
        self.create_actions()
        self.optionToolBar.addAction(self.contactAction)
        self.optionToolBar.addAction(self.disclaimerAction)
        self.optionToolBar.addAction(self.exitAction)
        self.connect_actions()

        # Create the base layout widget
        self.base_layout = BaseLayout()

        # Set the base layout widget as the central widget of the main window
        self.setCentralWidget(self.base_layout)

        # Define available pages
        self.pages = {
            Config.CHEMISTRY_INPUT_PAGE_NAME.value: ChemistryInputPage,
            Config.CALCULATION_INPUT_PAGE_NAME.value: CalculationInputPage
        }

        # Show the Starting Page
        self.switch_page(Config.CHEMISTRY_INPUT_PAGE_NAME.value)

        # Show the window
        self.show()

    def create_tool_bar(self) -> None:
        """
        Create QToolBar
        Returns
        -------
        """
        self.optionToolBar = QToolBar("Options Toolbar", self)
        self.optionToolBar.setMovable(False)
        self.addToolBar(self.optionToolBar)

    def create_actions(self) -> None:
        """
        Create QAction for QToolBar
        Returns
        -------

        """
        self.contactAction = QAction("&Contact us", self)
        self.disclaimerAction = QAction("&Disclaimer", self)
        self.exitAction = QAction("&Exit", self)

    def connect_actions(self) -> None:
        """
        Connect QAction to class functions
        Returns
        -------
        """
        self.contactAction.triggered.connect(self.dialog_handler.contact_message)
        self.disclaimerAction.triggered.connect(self.dialog_handler.disclaimer_message)
        self.exitAction.triggered.connect(self.close)

    def switch_page(self, page_name) -> None:
        """
        Switches the content of the base layout to the specified page.
        Parameters
        ----------
        page_name: str
            Page name

        Returns
        -------

        """
        if page_name in self.pages.keys():
            # Instantiate the new page
            new_page = self.pages[page_name](self.data_store)

            # Check if the page has already been added to the QStackedWidget
            page_index = self.base_layout.content_area.indexOf(new_page)

            if page_index == -1:  # Page not in the stack yet
                # Add the new page to the QStackedWidget
                self.base_layout.add_content(new_page)
                page_index = self.base_layout.content_area.indexOf(new_page)

            # Switch to the new page in the QStackedWidget
            self.base_layout.switch_content(page_index)

            # Connect the page's `page_switched` signal to the `switch_page` method
            new_page.page_switched.connect(self.switch_page)
