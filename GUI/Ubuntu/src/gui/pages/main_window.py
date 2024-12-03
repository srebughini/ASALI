from PyQt5.QtCore import Qt
from PyQt5.QtGui import QIcon
from PyQt5.QtWidgets import QMainWindow, QToolBar, QAction

from src.config.batch_input_page_config import BatchInputPageConfig
from src.config.calculation_input_page_config import CalculationInputPageConfig
from src.config.chemistry_input_page_config import ChemistryInputPageConfig
from src.config.chemkin_to_cantera_page_config import ChemkinToCanteraPageConfig
from src.config.cstr_input_page_config import CstrInputPageConfig
from src.config.equilibrium_output_page_config import EquilibriumOutputPageConfig
from src.config.het_1d_input_page_config import Het1dInputPageConfig
from src.config.linear_regression_output_page_config import LinearRegressionOutputPageConfig
from src.config.ph_1d_input_page_config import Ph1dInputPageConfig
from src.config.reactor_plot_and_save_output_page_config import ReactorPlotAndSaveOutputPageConfig
from src.config.properties_output_page_config import PropertiesOutputPageConfig
from src.config.user_defined_kinetic_page_config import UserDefinedKineticPageConfig
from src.config.vacuum_output_page_config import VacuumOutputPageConfig
from src.core.data_store import DataStore
from src.config.app_config import AppConfig
from src.gui.pages.base_layout import BaseLayout
from src.gui.pages.input.batch_input_page import BatchInputPage
from src.gui.pages.input.calculation_input_page import CalculationInputPage
from src.gui.pages.input.chemistry_input_page import ChemistryInputPage
from src.gui.pages.input.chemkin_to_cantera_page import ChemkinToCanteraPage
from src.gui.pages.dialog_pages_handler import DialogPagesHandler
from src.gui.pages.input.cstr_input_page import CstrInputPage
from src.gui.pages.input.het_1d_input_page import Het1dInputPage
from src.gui.pages.input.ph_1d_input_page import Ph1dInputPage
from src.gui.pages.output.equilibrium_output_page import EquilibriumOutputPage
from src.gui.pages.output.linear_regression_output_page import LinearRegressionOutputPage
from src.gui.pages.output.reactor_plot_and_save_output_page import ReactorPlotAndSaveOutputPage
from src.gui.pages.output.properties_output_page import PropertiesOutputPage
from src.gui.pages.input.user_defined_kinetic_page import UserDefinedKineticPage
from src.gui.pages.output.vacuum_output_page import VacuumOutputPage
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
        self.info_action = None
        self.toolbar = None

        # Add title
        self.setWindowTitle(AppConfig.TITLE.value)

        # Add icons
        self.setWindowIcon(QIcon(AppConfig.ICON_PATH.value))

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
            ChemistryInputPageConfig.NAME.value: ChemistryInputPage(self.data_store,
                                                                    self.dialog_handler),
            CalculationInputPageConfig.NAME.value: CalculationInputPage(self.data_store,
                                                                        self.dialog_handler),
            PropertiesOutputPageConfig.NAME.value: PropertiesOutputPage(self.data_store,
                                                                        self.dialog_handler),
            VacuumOutputPageConfig.NAME.value: VacuumOutputPage(self.data_store,
                                                                self.dialog_handler),
            ChemkinToCanteraPageConfig.NAME.value: ChemkinToCanteraPage(self.data_store,
                                                                        self.dialog_handler),
            UserDefinedKineticPageConfig.NAME.value: UserDefinedKineticPage(self.data_store,
                                                                            self.dialog_handler),
            EquilibriumOutputPageConfig.NAME.value: EquilibriumOutputPage(self.data_store,
                                                                          self.dialog_handler),
            ReactorPlotAndSaveOutputPageConfig.NAME.value: ReactorPlotAndSaveOutputPage(self.data_store,
                                                                                        self.dialog_handler),
            BatchInputPageConfig.NAME.value: BatchInputPage(self.data_store,
                                                            self.dialog_handler,
                                                            self.run_bar),
            CstrInputPageConfig.NAME.value: CstrInputPage(self.data_store,
                                                          self.dialog_handler,
                                                          self.run_bar),
            Ph1dInputPageConfig.NAME.value: Ph1dInputPage(self.data_store,
                                                          self.dialog_handler,
                                                          self.run_bar),
            Het1dInputPageConfig.NAME.value: Het1dInputPage(self.data_store,
                                                            self.dialog_handler,
                                                            self.run_bar),
            LinearRegressionOutputPageConfig.NAME.value: LinearRegressionOutputPage(self.data_store,
                                                                                    self.dialog_handler)
        }

        for page in self.pages.values():
            self.base_layout.add_page(page)

        # Show the Starting Page
        self.switch_page(ChemistryInputPageConfig.NAME.value)

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
        self.info_action = QAction("&Info", self)
        self.contact_action = QAction("&Contact us", self)
        self.disclaimer_action = QAction("&Disclaimer", self)
        self.exit_action = QAction("&Exit", self)
        self.toolbar.addAction(self.info_action)
        self.toolbar.addAction(self.contact_action)
        self.toolbar.addAction(self.disclaimer_action)
        self.toolbar.addAction(self.exit_action)

    def connect_actions(self) -> None:
        """
        Connect QAction to class functions
        Returns
        -------
        """
        self.info_action.triggered.connect(self.dialog_handler.info_message)
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
