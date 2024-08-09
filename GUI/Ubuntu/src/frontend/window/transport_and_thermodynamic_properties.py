from src.frontend.layout.transport_and_thermodynamic_properties import TransportAndThermodynamicPropertiesLayout
from src.frontend.window.basic import BasicMainWindow


class TransportAndThermodynamicPropertiesWindow(BasicMainWindow):
    def __init__(self, parent=None):
        """
        Main menu window
        """
        super().__init__(parent)
        self.set_central_widget_layout(TransportAndThermodynamicPropertiesLayout(self))