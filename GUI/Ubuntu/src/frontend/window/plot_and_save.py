from src.frontend.layout.plot_and_save import PlotAndSaveLayout
from src.frontend.window.basic import BasicMainWindow


class PlotAndSaveWindow(BasicMainWindow):
    def __init__(self, parent=None):
        """
        Main menu window
        """
        super().__init__(parent)
        self.setCentralWidgetLayout(PlotAndSaveLayout(self))
