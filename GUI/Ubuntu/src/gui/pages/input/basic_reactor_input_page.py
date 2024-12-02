from abc import abstractmethod

from PyQt5.QtCore import Qt
from PyQt5.QtGui import QDoubleValidator
from PyQt5.QtWidgets import QLineEdit, QComboBox, QLabel, QTabWidget

from src.config.plot_and_save_output_page_config import PlotAndSaveOutputPageConfig
from src.config.reactor_config import ReactorConfig
from src.controllers.thread_handler import ThreadHandler
from src.core.data_keys import DataKeys
from src.config.app_config import AppConfig
from src.gui.pages.basic_page import BasicPage


class BasicReactorInputPage(BasicPage):
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
        self.tab_name_to_row_idx_dict = {}
        self.surf_ns = None
        self.ns = None

    @property
    @abstractmethod
    def number_of_gas_species_to_row_idx(self) -> int:
        """
        Property that returns the number of gas species to row index value
        Returns
        -------
        row_idx: int
            Row index
        """
        return 0

    @property
    @abstractmethod
    def number_of_surface_species_to_row_idx(self) -> int:
        """
        Property that returns the number of surface species to row index value
        Returns
        -------
        row_idx: int
            Row index
        """
        return 0

    @property
    @abstractmethod
    def tab_names(self) -> list:
        """
        Property that return the tab name list
        Returns
        -------
        tab_names: list
            List of tab names
        """
        return []

    @property
    @abstractmethod
    def tab_name_to_grid_layout_name_dict(self) -> dict:
        """
        Property that return the grid layout name for each tab name
        Returns
        -------
        tab_name_to_grid_layout_name: dict
            Tab name to grid layout name
        """
        return {}

    @property
    @abstractmethod
    def tab_name_to_minimum_row_idx_dict(self) -> dict:
        """
        Property that return the minimum row idx for each tab name
        Returns
        -------
        tab_name_to_minimum_row_idx: dict
            Tab name to minimum row idx
        """
        return {}

    @abstractmethod
    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        pass

    @abstractmethod
    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        pass

    def from_ns_to_row_idx(self, ns) -> int:
        """
        Convert the number of species to row idx
        Parameters
        ----------
        ns: int
            Number of species

        Returns
        -------
        row_idx: int
            Row index corresponding to the number of species based on the layout
        """
        return ns + self.number_of_gas_species_to_row_idx

    def from_surf_ns_to_row_idx(self, surf_ns) -> int:
        """
        Convert the number of surface species to row idx
        Parameters
        ----------
        surf_ns: int
            Number of species

        Returns
        -------
        row_idx: int
            Row index corresponding to the number of species based on the layout
        """
        return surf_ns + self.number_of_surface_species_to_row_idx

    def update_tab_names(self, tab_widget_name) -> None:
        """
        Update tab names
        Parameters
        ----------
        tab_widget_name: str
            Tab widget name

        Returns
        -------

        """
        tab_widget = self.findChild(QTabWidget, tab_widget_name)

        for i, n in enumerate(self.tab_names):
            tab_widget.setTabText(i, n)

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
        file_path = self.dialog_handler.load_file(AppConfig.ASALI_FILE_OPEN.value,
                                                  AppConfig.ASALI_FILE_TYPE.value)

        if file_path:
            self.data_store.update_data(DataKeys.USER_DEFINED_KINETIC_FILE_PATH.value, file_path)

    def add_coverage_line(self) -> None:
        """
        Add coverage line to the layout
        Returns
        -------

        """
        self.surf_ns = self.surf_ns + 1
        surf_ns_row_idx = self.from_surf_ns_to_row_idx(self.surf_ns)

        # Coverage tab
        tab_name = ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value
        layout_name = self.tab_name_to_grid_layout_name_dict[tab_name]

        if surf_ns_row_idx > self.tab_name_to_row_idx_dict[tab_name]:
            row_idx = self.tab_name_to_row_idx_dict[tab_name] + 1
            self.add_surface_specie_input_row_to_grid_layout(layout_name,
                                                             self.surf_ns,
                                                             row_idx,
                                                             with_label=True)
            self.update_grid_layout(layout_name)
            self.tab_name_to_row_idx_dict[tab_name] = row_idx
        else:
            self.remove_row_from_grid_layout(layout_name, surf_ns_row_idx)
            self.add_surface_specie_input_row_to_grid_layout(layout_name,
                                                             self.surf_ns,
                                                             surf_ns_row_idx,
                                                             with_label=True)
            self.update_grid_layout(layout_name)

        # Other tabs
        for tab_name in self.tab_names:
            if tab_name != ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value:
                if surf_ns_row_idx > self.tab_name_to_row_idx_dict[tab_name]:
                    row_idx = self.tab_name_to_row_idx_dict[tab_name] + 1
                    layout_name = self.tab_name_to_grid_layout_name_dict[tab_name]
                    self.add_dummy_row_to_grid_layout(layout_name, row_idx)
                    self.tab_name_to_row_idx_dict[tab_name] = row_idx

    def remove_coverage_line(self) -> None:
        """
        Remove coverage line to the layout
        Returns
        -------

        """
        if self.surf_ns > 0:
            surf_ns_row_idx = self.from_surf_ns_to_row_idx(self.surf_ns)
            ns_row_idx = self.from_ns_to_row_idx(self.ns)

            if ns_row_idx >= surf_ns_row_idx:
                tab_name = ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value
                layout_name = self.tab_name_to_grid_layout_name_dict[tab_name]
                self.remove_row_from_grid_layout(layout_name, surf_ns_row_idx)
                self.add_dummy_row_to_grid_layout(layout_name, surf_ns_row_idx)
            else:
                for tab_name in self.tab_names:
                    if tab_name != ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value:
                        row_idx = self.tab_name_to_row_idx_dict[tab_name]
                        if row_idx > self.tab_name_to_minimum_row_idx_dict[tab_name]:
                            layout_name = self.tab_name_to_grid_layout_name_dict[tab_name]
                            self.remove_row_from_grid_layout(layout_name, row_idx)
                            self.tab_name_to_row_idx_dict[tab_name] = row_idx - 1

                # Initial conditions tab
                tab_name = ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value
                if tab_name in self.tab_names:
                    if ns_row_idx < self.tab_name_to_row_idx_dict[tab_name]:
                        row_idx = self.tab_name_to_row_idx_dict[tab_name]
                        layout_name = self.tab_name_to_grid_layout_name_dict[tab_name]
                        self.remove_row_from_grid_layout(layout_name, row_idx)
                        self.tab_name_to_row_idx_dict[tab_name] = row_idx - 1

                # Coverage tab
                tab_name = ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value
                layout_name = self.tab_name_to_grid_layout_name_dict[tab_name]
                if surf_ns_row_idx <= self.tab_name_to_minimum_row_idx_dict[tab_name]:
                    self.remove_row_from_grid_layout(layout_name, surf_ns_row_idx)

            self.surf_ns = self.surf_ns - 1

    def add_initial_specie_line(self) -> None:
        """
        Add specie line to the layout
        Returns
        -------

        """
        self.ns = self.ns + 1
        ns_row_idx = self.from_ns_to_row_idx(self.ns)

        # Coverage tab
        tab_name = ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value
        row_idx = self.tab_name_to_row_idx_dict[tab_name]
        layout_name = self.tab_name_to_grid_layout_name_dict[tab_name]

        if ns_row_idx > self.tab_name_to_row_idx_dict[tab_name]:
            row_idx = row_idx + 1
            self.add_gas_specie_input_row_to_grid_layout(layout_name,
                                                         self.ns,
                                                         row_idx,
                                                         with_label=True)
            self.update_grid_layout(layout_name)
            self.tab_name_to_row_idx_dict[tab_name] = row_idx
        else:
            self.remove_row_from_grid_layout(layout_name, ns_row_idx)
            self.add_gas_specie_input_row_to_grid_layout(layout_name,
                                                         self.ns,
                                                         ns_row_idx,
                                                         with_label=True)
            self.update_grid_layout(layout_name)

        # Other tabs
        for tab_name in self.tab_names:
            if tab_name != ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value:
                if ns_row_idx > self.tab_name_to_row_idx_dict[tab_name]:
                    row_idx = self.tab_name_to_row_idx_dict[tab_name] + 1
                    layout_name = self.tab_name_to_grid_layout_name_dict[tab_name]
                    self.add_dummy_row_to_grid_layout(layout_name, row_idx)
                    self.tab_name_to_row_idx_dict[tab_name] = row_idx

    def remove_initial_specie_line(self) -> None:
        """
        Remove specie line to the layout
        Returns
        -------

        """
        if self.ns > 0:
            surf_ns_row_idx = self.from_surf_ns_to_row_idx(self.surf_ns)
            ns_row_idx = self.from_ns_to_row_idx(self.ns)

            if surf_ns_row_idx >= ns_row_idx:
                tab_name = ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value
                layout_name = self.tab_name_to_grid_layout_name_dict[tab_name]
                self.remove_row_from_grid_layout(layout_name, ns_row_idx)
                self.add_dummy_row_to_grid_layout(layout_name, ns_row_idx)
            else:
                for tab_name in [ReactorConfig.SOLVING_OPTION_TAB_NAME.value,
                                 ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value,
                                 ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value]:
                    row_idx = self.tab_name_to_row_idx_dict[tab_name]
                    if row_idx > self.tab_name_to_minimum_row_idx_dict[tab_name]:
                        layout_name = self.tab_name_to_grid_layout_name_dict[tab_name]
                        self.remove_row_from_grid_layout(layout_name, row_idx)
                        self.tab_name_to_row_idx_dict[tab_name] = row_idx - 1

                tab_name = ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value
                if surf_ns_row_idx < self.tab_name_to_row_idx_dict[tab_name]:
                    layout_name = self.tab_name_to_grid_layout_name_dict[tab_name]
                    self.remove_row_from_grid_layout(layout_name, row_idx)
                    self.tab_name_to_row_idx_dict[tab_name] = row_idx - 1
            
            self.ns = self.ns - 1

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
            if results[0] is None:
                self.data_store.update_data(DataKeys.REACTOR_RESULTS.value, (results[1], results[2], results[3]))

                if self.dialog_handler.question_message("Run completed!\nDo you want to plot the results?"):
                    return self.page_switched.emit(PlotAndSaveOutputPageConfig.NAME.value)
            else:
                raise Exception(results[0])

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
