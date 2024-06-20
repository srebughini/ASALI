import traceback

from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QDialog, QLabel, QPushButton, QVBoxLayout, QComboBox, QMessageBox, QHBoxLayout, QGridLayout

from GUI.Ubuntu.src.frontend.style import WidgetStyle


class ExceptionHandler:
    """
    Class to handle the exception
    """

    @staticmethod
    def showDialog(main_window, exc_type, exc_value, exc_traceback):
        """
        Displays an exception dialog with the error details.

        Parameters
        ----------
        main_window : QMainWindow
            The main window of the application where the dialog will be displayed.
        exc_type : type
            The exception type.
        exc_value : BaseException
            The exception instance.
        exc_traceback : traceback
            The traceback object associated with the exception.

        Returns
        -------
        """
        # Format the exception
        error_msg = "".join(traceback.format_exception(exc_type, exc_value, exc_traceback))

        # Create the dialog
        dialog = QDialog(main_window, Qt.WindowCloseButtonHint)
        dialog.setWindowTitle("Error")

        # Create the main message label
        main_message = QLabel("Something went wrong!")

        # Create error label
        error_label = QLabel(error_msg)
        error_label.setWordWrap(True)
        error_label.setStyleSheet(WidgetStyle.ITALICLABEL.value)
        error_label.hide()

        # Create the close button
        show_error_button = QPushButton("Show details", clicked=error_label.show)
        show_error_button.setStyleSheet(WidgetStyle.BUTTON.value)

        # Create the close button
        close_button = QPushButton("Close", clicked=dialog.close)
        close_button.setStyleSheet(WidgetStyle.BUTTON.value)

        # Create the error icon
        icon_label = QLabel()
        icon_pixmap = QMessageBox.standardIcon(QMessageBox.Critical)
        icon_label.setPixmap(icon_pixmap)  # Set the size of the icon as needed

        # Setup grid layout
        grid_layout = QGridLayout()
        grid_layout.addWidget(icon_label, 0, 0)
        grid_layout.addWidget(main_message, 0, 1, )
        grid_layout.addWidget(error_label, 1, 0, 1, -1)
        grid_layout.addWidget(show_error_button, 2, 0)
        grid_layout.addWidget(close_button, 2, 1)
        dialog.setLayout(grid_layout)

        # Execute the dialog
        dialog.exec_()
