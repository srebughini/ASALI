from abc import abstractmethod

from PyQt5.QtWidgets import (
    QMainWindow
)

from src.frontend.layout.reactors.basic import BasicReactorLayout


class BasicTransientReactorLayout(BasicReactorLayout):
    def __init__(self, main_window):
        """
        Reactor selection layout
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        super().__init__(main_window)

    def _add_buttons(self, row_idx) -> None:
        """
        Add Back, Run model, Add Coverage and Add Specie buttons
        Parameters
        ----------
        row_idx: int
            Row index where to add the buttons
        Returns
        -------

        """
        self.addWidget(self._create_button(self.backButtonText,
                                           self.main_window.update_to_basic,
                                           self.backButtonToolTip),
                       row_idx,
                       self._reactor_properties_col_idx,
                       1,
                       self._sub_grid_width)
        self.addWidget(self._create_button(self.runButtonText,
                                           self.run_reactor_model,
                                           self.runButtonToolTip),
                       row_idx,
                       self._solving_options_col_idx,
                       1,
                       self._sub_grid_width)
        self.addWidget(self._create_button(self.addCoverageButtonText,
                                           self._update_layout_with_coverage_line,
                                           self.addCoverageToolTip),
                       row_idx,
                       self._coverage_col_idx,
                       1,
                       self._sub_grid_width)
        self.addWidget(self._create_button(self.addSpecieButtonText,
                                           self._update_layout_with_specie_line,
                                           self.addSpecieToolTip),
                       row_idx,
                       self._initial_conditions_col_idx,
                       1,
                       self._sub_grid_width)

    def _remove_buttons(self, row_idx) -> None:
        """
        Remove Back, Run model, Add Coverage and Add Specie buttons
        Parameters
        ----------
        row_idx: int
            Row index where to remove the buttons
        Returns
        -------

        """
        self._remove_widget(row_idx, self._reactor_properties_col_idx)
        self._remove_widget(row_idx, self._coverage_col_idx)
        self._remove_widget(row_idx, self._solving_options_col_idx)
        self._remove_widget(row_idx, self._initial_conditions_col_idx)

    def _add_headlines(self, row_idx) -> None:
        """
        Add headlines for user input
        Parameters
        ----------
        row_idx: int
            Row index where to add the buttons
        Returns
        -------

        """
        self.addWidget(self.reactorPropertiesLabel,
                       row_idx,
                       self._reactor_properties_col_idx,
                       1,
                       self._sub_grid_width)
        self.addWidget(self.solvingOptionLabel,
                       row_idx,
                       self._solving_options_col_idx,
                       1,
                       self._sub_grid_width)
        self.addWidget(self.coverageLabel,
                       row_idx,
                       self._coverage_col_idx,
                       1,
                       self._sub_grid_width)
        self.addWidget(self.initialConditionsLabel,
                       row_idx,
                       self._initial_conditions_col_idx,
                       1,
                       self._sub_grid_width)

    @abstractmethod
    def read_input(self) -> dict:
        """
        Function to read user input
        Returns
        -------
        input_dict: dict
            User input
        """
        return {}

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