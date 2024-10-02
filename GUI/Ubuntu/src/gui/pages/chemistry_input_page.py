import beerpy
from PyQt5.QtCore import Qt, pyqtSignal
from PyQt5.QtWidgets import QWidget, QVBoxLayout, QLabel
from PyQt5 import uic

from src.gui.config import Config


class ChemistryInputPage(QWidget):
    page_switched = pyqtSignal(str)  # Signal to switch pages

    def __init__(self):
        """
        Chemistry input page layout
        """
        super().__init__()
        # Load the UI from the .ui file
        uic.loadUi(Config.CHEMISTRY_INPUT_PAGE_PATH.value, self)


