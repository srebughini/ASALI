import traceback

from PySide6.QtCore import Qt
from PySide6.QtWidgets import QDialog, QLabel, QPushButton, QMessageBox, QGridLayout

from src.controllers.label_formatter import LabelFormatter


class ExceptionHandler:
    """
    Class to handle the exception
    """

    @staticmethod
    def show_dialog(main_window, exc_type, exc_value, exc_traceback) -> None:
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
        main_message = QLabel(LabelFormatter.pad_string_center("Something went wrong!"))

        # Create error label
        error_label = QLabel(error_msg)
        error_label.setWordWrap(True)
        error_label.setProperty("class", "boldItalic")  # Apply the QSS class
        error_label.hide()

        # Create the close button
        show_error_button = QPushButton(LabelFormatter.pad_string_center("Show details"), clicked=error_label.show)

        # Create the close button
        close_button = QPushButton(LabelFormatter.pad_string_center("Close"), clicked=dialog.close)

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

        #if main_window.runBar.isVisible():
        #    main_window.runBar.close_run_bar()
