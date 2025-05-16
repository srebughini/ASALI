from PyQt5.QtCore import Qt
from PyQt5.QtGui import QIcon
from PyQt5.QtWidgets import QMainWindow, QToolBar, QAction

from src.core.data_store import DataStore
from src.config.app import AppConfig
from src.gui.pages.base_layout import BaseLayout
from src.gui.pages.input.equilibrium_page import EquilibriumInputPage
from src.gui.pages.input.properties_page import PropertiesInputPage
from src.gui.pages.input.main_page import MainInputPage
from src.gui.pages.dialog_pages_handler import DialogPagesHandler
from src.gui.pages.input.regression_page import RegressionInputPage
from src.gui.pages.input.vacuum_page import VacuumInputPage
from src.gui.pages.output.equilibrium_page import EquilibriumOutputPage
from src.gui.pages.output.regression_page import RegressionOutputPage
from src.gui.pages.output.properties_page import PropertiesOutputPage
from src.gui.pages.output.vacuum_page import VacuumOutputPage
from src.gui.pages.run_bar import RunBar


class MainWindow(QMainWindow):
    def __init__(self):
        """
        Main class to orchestrate the switching between different pages
        """
        super().__init__()
        self.data_store = DataStore()
        self.dialog_handler = DialogPagesHandler(self, self.data_store)
        self.exit_action = None
        self.disclaimer_action = None
        self.contact_action = None
        self.toolbar = None

        # Add title
        self.setWindowTitle(AppConfig.TITLE.value)

        # Add icons
        self.setWindowIcon(QIcon(AppConfig.ICON_PATH.value))

        # Disable user resize
        # self.setFixedSize(self.sizeHint())

        # Set flags
        self.setWindowFlags(
            Qt.Window |
            Qt.CustomizeWindowHint |
            Qt.WindowTitleHint |
            Qt.WindowMinimizeButtonHint |
            Qt.WindowCloseButtonHint
        )

        # Create run bar
        self.run_bar = RunBar()

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
            AppConfig.MAIN_INPUT_PAGE: MainInputPage(self.data_store,
                                                     self.dialog_handler),
            AppConfig.PROPERTIES_INPUT_PAGE: PropertiesInputPage(self.data_store,
                                                                 self.dialog_handler),
            AppConfig.PROPERTIES_OUTPUT_PAGE: PropertiesOutputPage(self.data_store,
                                                                   self.dialog_handler),
            AppConfig.VACUUM_INPUT_PAGE: VacuumInputPage(self.data_store,
                                                         self.dialog_handler),
            AppConfig.VACUUM_OUTPUT_PAGE: VacuumOutputPage(self.data_store,
                                                           self.dialog_handler),
            AppConfig.REGRESSION_INPUT_PAGE: RegressionInputPage(self.data_store,
                                                                 self.dialog_handler),
            AppConfig.REGRESSION_OUTPUT_PAGE: RegressionOutputPage(self.data_store,
                                                                   self.dialog_handler),
            AppConfig.EQUILIBRIUM_INPUT_PAGE: EquilibriumInputPage(self.data_store,
                                                                   self.dialog_handler),
            AppConfig.EQUILIBRIUM_OUTPUT_PAGE: EquilibriumOutputPage(self.data_store,
                                                                     self.dialog_handler)
        }

        #     ChemkinToCanteraPageConfig.NAME.value: ChemkinToCanteraPage(self.data_store,
        #                                                                 self.dialog_handler),
        #     UserDefinedKineticPageConfig.NAME.value: UserDefinedKineticPage(self.data_store,
        #                                                                     self.dialog_handler),
        #     EquilibriumOutputPageConfig.NAME.value: EquilibriumOutputPage(self.data_store,
        #                                                                   self.dialog_handler),
        #     ReactorPlotAndSaveOutputPageConfig.NAME.value: ReactorPlotAndSaveOutputPage(self.data_store,
        #                                                                                 self.dialog_handler),
        #     BatchInputPageConfig.NAME.value: BatchInputPage(self.data_store,
        #                                                     self.dialog_handler,
        #                                                     self.run_bar),
        #     CstrInputPageConfig.NAME.value: CstrInputPage(self.data_store,
        #                                                   self.dialog_handler,
        #                                                   self.run_bar),
        #     Ph1dInputPageConfig.NAME.value: Ph1dInputPage(self.data_store,
        #                                                   self.dialog_handler,
        #                                                   self.run_bar),
        #     Het1dInputPageConfig.NAME.value: Het1dInputPage(self.data_store,
        #                                                     self.dialog_handler,
        #                                                     self.run_bar),
        #     RegressionOutputPageConfig.NAME.value: RegressionOutputPage(self.data_store,
        #                                                                 self.dialog_handler),
        #     RegressionPlotOutputPageConfig.NAME.value: RegressionPlotOutputPage(self.data_store,
        #                                                                         self.dialog_handler)
        # }

        for page in self.pages.values():
            self.base_layout.add_page(page)

        # Show the Starting Page
        self.switch_page(AppConfig.MAIN_INPUT_PAGE)

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

    def switch_page(self, page_config) -> None:
        """
        Switches the content of the base layout to the specified page.
        Parameters
        ----------
        page_config: Enum
            Page name

        Returns
        -------

        """

        if page_config in self.pages.keys():
            # Instantiate the new page
            new_page = self.pages[page_config]

            # Switch to the new page in the QStackedWidget
            self.base_layout.switch_page(page_config.value.layout_name)

            # Connect the page's `page_switched` signal to the `switch_page` method
            new_page.page_switched.connect(self.switch_page)

            self.adjustSize()
        else:
            raise Exception(f"{page_config.value.layout_name} not found!")

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
