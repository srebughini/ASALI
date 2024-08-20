from src.frontend.layout.reactors.batch import BatchLayout
from src.frontend.layout.reactors.cstr import CstrLayout
from src.frontend.layout.reactors.ph1d_transient import TransientPseudoHomogeneous1DReactorLayout
from src.frontend.layout.reactors.selection_menu import ReactorSelectionMenuLayout
from src.frontend.layout.reactors.ph1d_steady_state import SteadyStatePseudoHomogeneous1DReactorLayout
from src.frontend.window.basic import BasicMainWindow


class ReactorsMenuWindow(BasicMainWindow):
    def __init__(self, parent=None):
        """
        Reactor selection window
        """
        super().__init__(parent)
        self.set_central_widget_layout(ReactorSelectionMenuLayout(self))

    def update_to_basic(self) -> None:
        """
        Update to BasicReactorLayout
        Returns
        -------
        """
        self.set_central_widget_layout(ReactorSelectionMenuLayout(self))

    def update_to_batch_reactor(self) -> None:
        """
        Update to the BatchReactorLayout
        Returns
        -------
        """
        self.set_central_widget_layout(BatchLayout(self))

    def update_to_cstr_reactor(self) -> None:
        """
        Update to the CstrReactorLayout
        Returns
        -------
        """
        self.set_central_widget_layout(CstrLayout(self))

    def update_to_ph1d_steady_state_reactor(self) -> None:
        """
        Update to the SteadyStatePseudoHomogeneous1DReactorLayout
        Returns
        -------
        """
        self.set_central_widget_layout(SteadyStatePseudoHomogeneous1DReactorLayout(self))

    def update_to_ph1d_transient_reactor(self) -> None:
        """
        Update to the TransientPseudoHomogeneous1DReactorLayout
        Returns
        -------
        """
        self.set_central_widget_layout(TransientPseudoHomogeneous1DReactorLayout(self))