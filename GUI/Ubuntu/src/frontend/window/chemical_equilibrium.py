from src.frontend.layout.chemical_equilibrium import ChemicalEquilibriumLayout
from src.frontend.window.basic import BasicMainWindow


class ChemicalEquilibriumWindow(BasicMainWindow):
    def __init__(self, parent=None):
        """
        Main menu window
        """
        super().__init__(parent)
        self.set_central_widget_layout(ChemicalEquilibriumLayout(self))