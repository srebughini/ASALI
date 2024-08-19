from src.frontend.layout.basic_reactor import BasicReactorLayout
from src.frontend.layout.batch import BatchLayout
from src.frontend.window.basic import BasicMainWindow


class ReactorsMenuWindow(BasicMainWindow):
    def __init__(self, parent=None):
        """
        Reactor selection window
        """
        super().__init__(parent)
        self.set_central_widget_layout(BasicReactorLayout(self))

    def update_to_basic(self) -> None:
        """
        Update to BasicReactorLayout
        Returns
        -------
        """
        self.set_central_widget_layout(BasicReactorLayout(self))

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
        pass