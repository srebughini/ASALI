from PyQt5.QtCore import Qt
from PyQt5.QtGui import QIcon
from PyQt5.QtWidgets import QWidget, QProgressBar, QLabel, QVBoxLayout, QPushButton

from src.backend.utils import DefaultPath
from src.frontend.style import WidgetStyle
from src.frontend.utils import Utils
from src.frontend.worker import Worker


class RunBarWindow(QWidget):
    def __init__(self, parent=None):
        """
        Class to handle the run bar during running reactor models
        """
        super().__init__(parent)
        self._worker = None

        self.setWindowTitle(Utils.window_title())
        self.setStyleSheet(WidgetStyle.WINDOW.value)

        self.icon = QIcon(DefaultPath.icon.value)
        self.setWindowIcon(self.icon)
        self.setStyleSheet(WidgetStyle.WINDOW.value)
        self.setWindowFlags(
            Qt.Window |
            Qt.CustomizeWindowHint |
            Qt.WindowTitleHint |
            Qt.WindowMinimizeButtonHint
        )

        layout = QVBoxLayout()

        self.label = QLabel("Model is running, it might take several minutes. \nPlease wait.", self)
        self.label.setAlignment(Qt.AlignCenter)
        self.label.setStyleSheet(WidgetStyle.ITALICLABEL.value)
        layout.addWidget(self.label)

        self.progressBar = QProgressBar(self)
        self.progressBar.setMaximum(0)  # Indeterminate mode
        self.progressBar.setStyleSheet(WidgetStyle.PROGRESSBAR.value)
        layout.addWidget(self.progressBar)

        # Add a Stop button
        self.stopButton = QPushButton("Stop", self)
        self.stopButton.setStyleSheet(WidgetStyle.BUTTON.value)
        self.stopButton.clicked.connect(self.on_stop_button_clicked)
        layout.addWidget(self.stopButton)

        self.setLayout(layout)

    def get_worker(self) -> Worker:
        """
        Get worker
        Returns
        -------
        worker: Worker
            Worker class
        """

        return self._worker

    def set_worker(self, value) -> None:
        """
        Set worker
        Parameters
        ----------
        value: Worker
            Worker class

        Returns
        -------

        """
        self._worker = value

    # Creating a property object for worker
    worker = property(get_worker, set_worker)

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
        self._worker.stop()
