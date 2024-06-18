import sys

from PyQt5.QtWidgets import QApplication, QMainWindow

from GUI.Ubuntu.src.frontend.chemkin_to_cantera_converter_window import ChemkinToCanteraConverterWindow
from GUI.Ubuntu.src.frontend.select_chemistry_window import SelectChemistryWindow


def main():
    app = QApplication(sys.argv)
    app.setStyle("Fusion")

    # Create and show the main window
    mainWindow = QMainWindow()
    window = SelectChemistryWindow(mainWindow)
    #window = ChemkinToCanteraConverterWindow(mainWindow)
    mainWindow.show()

    sys.exit(app.exec_())


if __name__ == "__main__":
    main()
