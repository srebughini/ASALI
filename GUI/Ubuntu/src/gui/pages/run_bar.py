from PyQt5.QtCore import Qt
from PyQt5.QtGui import QIcon
from PyQt5.QtWidgets import QWidget, QProgressBar, QLabel, QVBoxLayout, QPushButton

from src.controllers.thread_handler import ThreadHandler
from src.config.app_config import AppConfig


class RunBar(QWidget):
    def __init__(self, parent=None):
        """
        Class to handle the run bar during running reactor models
        """
        super().__init__(parent)
        self._thread_handler = None

        # Add title
        self.setWindowTitle(AppConfig.TITLE.value)

        # Add icons
        self.setWindowIcon(QIcon(AppConfig.ICON_PATH.value))

        self.setWindowFlags(
            Qt.Window |
            Qt.CustomizeWindowHint |
            Qt.WindowTitleHint |
            Qt.WindowMinimizeButtonHint
        )

        layout = QVBoxLayout()

        self.label = QLabel("Model is running, it might take several minutes. \nPlease wait.", self)
        self.label.setAlignment(Qt.AlignCenter)
        self.label.setProperty("class", "italic")
        layout.addWidget(self.label)

        self.progressBar = QProgressBar(self)
        self.progressBar.setMaximum(0)  # Indeterminate mode
        layout.addWidget(self.progressBar)

        # Add a Stop button
        self.stopButton = QPushButton("Stop", self)
        self.stopButton.clicked.connect(self.on_stop_button_clicked)
        layout.addWidget(self.stopButton)

        self.setLayout(layout)

    def get_thread_handler(self) -> ThreadHandler:
        """
        Get thread handler
        Returns
        -------
        thread_handler: ThreadHandler
            Thread handler class
        """

        return self._thread_handler

    def set_thread_handler(self, value) -> None:
        """
        Set thread handler
        Parameters
        ----------
        value: ThreadHandler
            Thread handler class

        Returns
        -------

        """
        self._thread_handler = value

    # Creating a property object for worker
    thread_handler = property(get_thread_handler, set_thread_handler)

    def close_run_bar(self) -> None:
        """
        Close the progress bar
        Returns
        -------

        """
        self.progressBar.setMaximum(100)  # Set back to normal mode
        self.progressBar.setValue(100)  # Set progress to 100% on completion
        self.close()

    def reset_run_bar(self) -> None:
        """
        Reset the progress bar
        Returns
        -------

        """
        self.progressBar.setMaximum(0)  # Reset to indeterminate mode
        self.progressBar.setValue(0)  # Reset value to 0

    def on_stop_button_clicked(self):
        """
        Function to stop the running process
        Returns
        -------

        """
        self._thread_handler.stop()
