from PyQt5 import uic

from src.gui.config import Config
from src.gui.pages.basic_page import BasicPage


class ChemkinToCanteraPage(BasicPage):
    def __init__(self, data_store):
        """
        Vacuum properties output layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        """
        super().__init__(data_store)
        # Load the UI from the .ui file
        uic.loadUi(Config.CHEMKIN_TO_CANTERA_PAGE_PATH.value, self)

        self.update_grid_layout()

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        pass