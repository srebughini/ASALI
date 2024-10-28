from PyQt5 import uic

from src.gui.config import Config
from src.gui.pages.basic_page import BasicPage


class PlotAndSaveOutputPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Plot and save output layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        uic.loadUi(Config.PLOT_AND_SAVE_OUTPUT_PAGE_PATH.value, self)

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.update_grid_layout()