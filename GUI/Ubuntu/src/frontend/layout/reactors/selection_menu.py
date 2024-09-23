from PyQt5.QtWidgets import (
    QMainWindow
)

from src.frontend.layout.reactors.basic import BasicReactorLayout


class ReactorSelectionMenuLayout(BasicReactorLayout):
    def __init__(self, main_window):
        """
        Reactor selection layout
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        super().__init__(main_window)

    def _check_all_inputs(self, variables_dict) -> bool:
        """
        Perform check on the user input
        Parameters
        ----------
        variables_dict: dict
            Dictionary of variables {ReactorVariablesName: QEditLine}

        Returns
        -------
        check: bool
            Results of the performed check
        """
        return True

    def read_input(self) -> dict:
        """
        Function to read user input
        Returns
        -------
        input_dict: dict
            User input
        """
        return {}

    def _add_buttons(self, row_idx) -> None:
        """
        Add buttons
        Parameters
        ----------
        row_idx: int
            Row index where to add the buttons
        Returns
        -------

        """
        pass

    def _remove_buttons(self, row_idx) -> None:
        """
        Remove buttons
        Parameters
        ----------
        row_idx: int
            Row index where to add the buttons
        Returns
        -------

        """
        pass

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
        pass

    def run_reactor_model(self) -> None:
        """
        Function to run the reactor model
        Returns
        -------

        """
        pass

    def create_layout_components(self) -> None:
        """
        Initialize the widgets
        Returns
        -------
        """
        self._create_reactor_selection_dropdown()

    def generate_layout(self) -> None:
        """
        Update the interface
        Returns
        -------
        """
        self.row_idx = self.row_idx + 1
        self.addWidget(self.reactorDropDown, self.row_idx, 0, 1, -1)
