from PyQt5.QtCore import Qt
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import QLineEdit, QComboBox, QLabel, QTabWidget, QGridLayout

from src.controllers.thread_handler import ThreadHandler
from src.core.data_keys import DataKeys
from src.gui.config import Config
from src.gui.pages.basic_page import BasicPage


class BatchReactorInputPage(BasicPage):
    def __init__(self, data_store, dialog_handler, run_bar):
        """
        Basic reactor input page layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        run_bar: RunBarWindow
            Class to handle the run bar
        """
        super().__init__(data_store, dialog_handler)
        self.run_bar = run_bar  # Run bar window instance passed from MainWindow

        self.thread_handler = ThreadHandler()
        self.thread_handler.finished.connect(self.on_run_completed)
        self.thread_handler.error.connect(self.on_run_error)
        self.thread_handler.stopped.connect(self.on_run_stopped)

        self.task_function = None

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        pass

    def update_property_line(self, edit_line_name, combo_box_name, ud_list) -> None:
        """
        Update properties input line
        Parameters
        ----------
        edit_line_name: str
            Edit line name
        combo_box_name: str | None
            Unit dimension combo box name
        ud_list: list | None
            Unit dimensions

        Returns
        -------

        """
        edit_line = self.findChild(QLineEdit, edit_line_name)
        edit_line.setValidator(QDoubleValidator(0.0, 1.0e64, 4))
        edit_line.setAlignment(Qt.AlignRight)

        dropdown = self.findChild(QComboBox, combo_box_name)
        dropdown.addItems(ud_list)

    def remove_row_from_grid_layout(self, grid_layout_name, row_idx) -> None:
        """
        Remove a row from a grid layout
        Parameters
        ----------
        grid_layout_name: str
            Grid Layout name
        row_idx: int
            Row to be removed

        Returns
        -------

        """
        grid_layout = self.findChild(QGridLayout, grid_layout_name)
        for column in range(grid_layout.columnCount()):
            item = grid_layout.itemAtPosition(row_idx, column)
            if item:
                widget = item.widget()
                grid_layout.removeWidget(widget)
        self.update_grid_layout(grid_layout_name)

    def add_dummy_row_to_grid_layout(self, grid_layout_name, row_idx) -> None:
        """
        Add a dummy row to a grid layout
        Parameters
        ----------
        grid_layout_name: str
            Grid Layout name
        row_idx: int
            Row to be removed

        Returns
        -------

        """
        label = QLabel(" ")
        grid_layout = self.findChild(QGridLayout, grid_layout_name)
        grid_layout.addWidget(label, row_idx, 0, 1, -1)
        self.update_grid_layout(grid_layout_name)

    def read_data_from_property_line(self, edit_line_name, combo_box_name, data_key) -> None:
        """
        Read data from property line
        Parameters
        ----------
        edit_line_name: str
            Edit line name
        combo_box_name: str | None
            Unit dimension combo box name
        data_key: DataKeys
            Key to save data

        Returns
        -------

        """
        value = float(self.findChild(QLineEdit, edit_line_name).text())
        ud = self.findChild(QComboBox, combo_box_name).currentText()
        self.data_store.update_data(data_key.value, (value, ud))

    def load_udk_file(self) -> None:
        """
        Load Asali user defined kinetic model
        Returns
        -------

        """
        file_path = self.dialog_handler.load_file("Open Asali User Defined Kinetic file",
                                                  Config.ASALI_FILE_TYPE.value)

        if file_path:
            self.data_store.update_data(DataKeys.USER_DEFINED_KINETIC_FILE_PATH.value, file_path)

    def run_button_action(self) -> None:
        """
        Function to run the reactor model
        Returns
        -------

        """
        self.read_data()

        self.thread_handler.task_function = self.task_function
        self.thread_handler.args = (self.data_store,)

        # Show run bar and disable page inputs
        self.run_bar.reset_run_bar()
        self.run_bar.thread_handler = self.thread_handler
        self.run_bar.show()
        self.setEnabled(False)

        # Start the worker thread
        self.thread_handler.start()

    def on_run_completed(self, results) -> None:
        """
        Function to handle run bar and window when the run is completed
        Parameters
        ----------
        results: multiprocessing.Queue()
            Results extracted from the Worker
        Returns
        -------

        """
        self.run_bar.close_run_bar()
        self.setEnabled(True)

        if results is not None:
            self.data_store.update_data(DataKeys.REACTOR_RESULTS.value, results)

            if self.dialog_handler.question_message("Run completed!\nDo you want to plot the results?"):
                return self.page_switched.emit(Config.PLOT_AND_SAVE_OUTPUT_PAGE_NAME.value)

    def on_run_error(self, error_message) -> None:
        """
        Function to handle run bar and window when the run creates an error
        Parameters
        ----------
        error_message: str
            Error message

        Returns
        -------

        """
        self.run_bar.close_run_bar()
        self.setEnabled(True)
        self.dialog_handler.error_message(QLabel(error_message))

    def on_run_stopped(self) -> None:
        """
        Function to handle run bar and window when the run is stopped
        Returns
        -------

        """
        self.run_bar.close_run_bar()
        self.setEnabled(True)
        self.dialog_handler.done_message(QLabel("Run stopped!"))
