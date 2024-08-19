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
