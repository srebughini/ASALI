import sys

from PyQt5.QtWidgets import QApplication

from src.frontend.exception_handler import ExceptionHandler
from src.frontend.window.main_menu import MainMenuWindow


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
    mainWindow = MainMenuWindow()
    mainWindow.show()

    sys.exit(app.exec_())
