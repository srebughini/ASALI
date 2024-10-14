from PyQt5.QtCore import Qt
from PyQt5.QtGui import QIcon
from PyQt5.QtWidgets import QMainWindow, QToolBar, QAction

from src.core.data_store import DataStore
from src.gui.config import Config
from src.gui.pages.base_layout import BaseLayout
from src.gui.pages.calculation_input_page import CalculationInputPage
from src.gui.pages.chemistry_input_page import ChemistryInputPage
from src.gui.pages.chemkin_to_cantera_page import ChemkinToCanteraPage
from src.gui.pages.dialog_pages_handler import DialogPagesHandler
from src.gui.pages.properties_output_page import PropertiesOutputPage
from src.gui.pages.user_defined_kinetic_page import UserDefinedKineticPage
from src.gui.pages.vacuum_output_page import VacuumOutputPage


class MainWindow(QMainWindow):
    def __init__(self):
        """
        Main class to orchestrate the switching between different pages
        """
        super().__init__()
        self.data_store = DataStore()
        self.dialog_handler = DialogPagesHandler(self)

        self.exit_action = None
        self.disclaimer_action = None
        self.contact_action = None
        self.toolbar = None

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
        self.connect_actions()

        # Create the base layout widget
        self.base_layout = BaseLayout()

        # Set the base layout widget as the central widget of the main window
        self.setCentralWidget(self.base_layout)

        # Define available pages
        self.pages = {
            Config.CHEMISTRY_INPUT_PAGE_NAME.value: ChemistryInputPage(self.data_store,
                                                                       self.dialog_handler),
            Config.CALCULATION_INPUT_PAGE_NAME.value: CalculationInputPage(self.data_store,
                                                                           self.dialog_handler),
            Config.PROPERTIES_OUTPUT_PAGE_NAME.value: PropertiesOutputPage(self.data_store,
                                                                           self.dialog_handler),
            Config.VACUUM_OUTPUT_PAGE_NAME.value: VacuumOutputPage(self.data_store,
                                                                   self.dialog_handler),
            Config.CHEMKIN_TO_CANTERA_PAGE_NAME.value: ChemkinToCanteraPage(self.data_store,
                                                                            self.dialog_handler),
            Config.USER_DEFINED_KINETIC_PAGE_NAME.value: UserDefinedKineticPage(self.data_store,
                                                                                self.dialog_handler)
        }

        for page in self.pages.values():
            self.base_layout.add_page(page)

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
        self.toolbar = QToolBar("Options Toolbar", self)
        self.toolbar.setMovable(False)
        self.addToolBar(self.toolbar)

    def create_actions(self) -> None:
        """
        Create QAction for QToolBar
        Returns
        -------

        """
        self.contact_action = QAction("&Contact us", self)
        self.disclaimer_action = QAction("&Disclaimer", self)
        self.exit_action = QAction("&Exit", self)
        self.toolbar.addAction(self.contact_action)
        self.toolbar.addAction(self.disclaimer_action)
        self.toolbar.addAction(self.exit_action)

    def connect_actions(self) -> None:
        """
        Connect QAction to class functions
        Returns
        -------
        """
        self.contact_action.triggered.connect(self.dialog_handler.contact_message)
        self.disclaimer_action.triggered.connect(self.dialog_handler.disclaimer_message)
        self.exit_action.triggered.connect(self.close)

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
            new_page = self.pages[page_name]

            # Switch to the new page in the QStackedWidget
            self.base_layout.switch_page(page_name)

            # Connect the page's `page_switched` signal to the `switch_page` method
            new_page.page_switched.connect(self.switch_page)

            self.adjustSize()
        else:
            raise Exception(f"{page_name} not found!")

    def closeEvent(self, event) -> None:
        """
        Override the closeEvent method to prompt the user for confirmation
        before closing the application.

        Parameters
        ----------
        event : QCloseEvent
            The event that triggered the close request.
        """
        exit_message = self.dialog_handler.question_message("Are you sure you want to quit?")

        if exit_message:
            event.accept()
        else:
            event.ignore()