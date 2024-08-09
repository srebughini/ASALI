from src.frontend.layout.chemkin_to_cantera_converter import ChemkinToCanteraConverterLayout
from src.frontend.window.basic import BasicMainWindow


class ChemkinToCanteraConverterWindow(BasicMainWindow):
    def __init__(self, parent=None):
        """
        CHEMKIN -> CANTERA converter window
        """
        super().__init__(parent)
        self.set_central_widget_layout(ChemkinToCanteraConverterLayout(self))
