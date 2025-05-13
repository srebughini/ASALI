import sys

from PyQt5.QtCore import QFile
from PyQt5.QtWidgets import QApplication

from src.config.app import AppConfig
from src.resources import resources_rc

from src.controllers.exception_handler import ExceptionHandler
from src.gui.pages.main_window import MainWindow


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
    ExceptionHandler.show_dialog(main_window, exc_type, exc_value, exc_traceback)


# Override the default exception handler
sys.excepthook = handle_exception

if __name__ == "__main__":
    app = QApplication([])

    # Set Fusion style before loading the window
    app.setStyle('Fusion')

    file = QFile(":/qss/style.qss")
    if file.open(QFile.ReadOnly | QFile.Text):
        stylesheet = file.readAll().data().decode('utf-8')
        app.setStyleSheet(stylesheet)
    else:
        raise Exception("Unable to find style.qss file")

    # Initialize and show the main window
    main_window = MainWindow()
    main_window.move(*AppConfig.SCREEN_LOCATION.value)
    main_window.show()

    app.exec_()
