from src.frontend.layout.vacuum_properties import VacuumPropertiesLayout
from src.frontend.window.basic import BasicMainWindow


class VacuumPropertiesWindow(BasicMainWindow):
    def __init__(self, parent=None):
        """
        Main menu window
        """
        super().__init__(parent)
        self.setCentralWidgetLayout(VacuumPropertiesLayout(self))