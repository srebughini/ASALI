from PyQt5.QtWidgets import QFileDialog

from src.core.data_keys import DataKeys


class FileHandlerPages:
    def __init__(self, main_window, data_store):
        """
        Class to generate dialog pages
        Parameters
        ----------
        main_window: QMainWindow
            Main window object
        """
        self.main_window = main_window
        self.data_store = data_store

    def open_file(self, title="Load file", file_type="All Files (*)") -> bool:
        """
        Dialog window to open file
        Parameters
        ----------
        title: str
            QFileDialog title
        file_type: str
            QFileDialog message

        Returns
        -------
        check: bool
            If true the file has been opened
        """
        fileTuple = QFileDialog.getOpenFileName(self.main_window,
                                                title,
                                                "",
                                                file_type)

        if len(fileTuple[0]) == 0:
            self.data_store.update_data(self, DataKeys.CHEMISTRY_FILE_PATH.value, None)
            return False

        self.data_store.update_data(self, DataKeys.CHEMISTRY_FILE_PATH.value, fileTuple[0])
        return True
