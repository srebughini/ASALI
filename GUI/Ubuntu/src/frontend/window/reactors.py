from src.frontend.layout.basic_reactor import BasicReactorLayout
from src.frontend.layout.batch import BatchLayout
from src.frontend.window.basic import BasicMainWindow


class ReactorsWindow(BasicMainWindow):
    def __init__(self, parent=None):
        """
        Reactor selection window
        """
        super().__init__(parent)
        self.setCentralWidgetLayout(BasicReactorLayout(self))

    def updateToBasic(self):
        """
        Update to BasicReactorLayout
        Returns
        -------
        """
        self.setCentralWidgetLayout(BasicReactorLayout(self))

    def updateToBatchReactor(self):
        """
        Update to the BatchReactorLayout
        Returns
        -------
        """
        self.setCentralWidgetLayout(BatchLayout(self))

    def updateToCstrReactor(self):
        """
        Update to the CstrReactorLayout
        Returns
        -------
        """
        pass