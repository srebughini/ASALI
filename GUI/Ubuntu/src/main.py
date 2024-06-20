import sys

from PyQt5.QtWidgets import QApplication, QMainWindow

from GUI.Ubuntu.src.frontend.chemkin_to_cantera_converter import ChemkinToCanteraConverterWindow
from GUI.Ubuntu.src.frontend.exception_handler import ExceptionHandler
from GUI.Ubuntu.src.frontend.select_chemistry import SelectChemistryWindow


def handle_exception(exc_type, exc_value, exc_traceback):
    """
    Function to replace system exception handler
    Parameters
    ----------
    exc_type : type
        The exception type.
    exc_value : BaseException
        The exception instance.
    exc_traceback : traceback
        The traceback object associated with the exception.
    Returns
    -------

    """
    ExceptionHandler.showDialog(mainWindow, exc_type, exc_value, exc_traceback)


# Override the default exception handler
sys.excepthook = handle_exception

if __name__ == "__main__":
    app = QApplication(sys.argv)
    app.setStyle("Fusion")

    # Create and show the main window
    mainWindow = QMainWindow()
    # window = SelectChemistryWindow(mainWindow)
    window = ChemkinToCanteraConverterWindow(mainWindow)
    mainWindow.show()

    sys.exit(app.exec_())
