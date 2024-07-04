from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QFileDialog, QDialog, QPushButton, QVBoxLayout, QMessageBox, QLabel, QGridLayout, QWidget

from src.frontend.style import WidgetStyle, ColorPalette


# from src.frontend.window.chemkin_to_cantera_converter import ChemkinToCanteraConverterWindow


class Utils:
    """
    Class to handle utilities functions
    """

    @staticmethod
    def cleanLayout(layout):
        """
        Clean the whole layout without removing the layout
        Parameters
        ----------
        layout: QVBoxLayout / QGridLayout/ QHBoxLayout
            Layout to be cleaned
        Returns
        -------
        layout: QVBoxLayout / QGridLayout/ QHBoxLayout
            Cleaned layout
        """
        if layout is not None:
            while layout.count():
                item = layout.takeAt(0)
                widget = item.widget()
                if widget is not None:
                    widget.deleteLater()
                else:
                    Utils.cleanLayout(item.layout())

        return layout

    @staticmethod
    def cleanWidget(widget):
        """
        Clean a widget by remove all children
        Parameters
        ----------
        widget: QWidget
            Widget to be cleaned
        Returns
        -------
        widget: QWidget
            Cleaned widget
        """
        # Remove all child widgets of the central widget
        for child in widget.children():
            if isinstance(child, QWidget):
                child.setParent(None)
                child.deleteLater()

        return widget

    @staticmethod
    def openNewWindow(main_window, new_window_class):
        """
        Open a new window
        Parameters
        ----------
        main_window: QMainWindow
            Main window that is hosting the new window
        new_window_class: Callable class
            New window class to be opened

        Returns
        -------
        """
        window = new_window_class(main_window)
        window.show()

    @staticmethod
    def openFile(main_window, title="Load file", file_type="All Files (*)"):
        """
        Dialog window to open file
        Parameters
        ----------
        main_window: QMainWindow
            Main window that is hosting the new window
        title: str
            QFileDialog title
        file_type: str
            QFileDialog message

        Returns
        -------
        file_path: str
            File path
        """
        fileTuple = QFileDialog.getOpenFileName(main_window,
                                                title,
                                                "",
                                                file_type)

        if len(fileTuple[0]) == 0:
            return None

        return fileTuple[0]

    @staticmethod
    def saveFile(main_window, title="Save file", file_type="All Files (*)"):
        """
        Dialog window to save file
        Parameters
        ----------
        main_window: QMainWindow
            Main window that is hosting the new window
        title: str
            QFileDialog title
        file_type: str
            QFileDialog message

        Returns
        -------
        file_path: str
            File path
        """
        fileTuple = QFileDialog.getSaveFileName(main_window,
                                                title,
                                                "",
                                                file_type)
        if len(fileTuple[0]) == 0:
            return None

        return fileTuple[0]

    @staticmethod
    def dialogMessage(main_window, title, msg):
        """
        Show message with QDialog
        Parameters
        ----------
        main_window: QMainWindow
            Main window that is hosting the new window
        title: str
            QDialog title
        msg: QLabel
            QDialog message

        Returns
        -------
        """
        # Create a QDialog instance
        dialog = QDialog(main_window, Qt.WindowCloseButtonHint)
        dialog.setWindowTitle(title)

        # Add a button
        button = QPushButton("Close", clicked=dialog.close)
        button.setStyleSheet(WidgetStyle.BUTTON.value)

        # Create a layout for the dialog
        dialog_layout = QVBoxLayout()
        dialog_layout.addWidget(msg)
        dialog_layout.addWidget(button)

        # Set the layout for the dialog
        dialog.setLayout(dialog_layout)

        # Show the dialog as a modal dialog (blocks the main window)
        dialog.exec_()

    @staticmethod
    def questionMessage(main_window, title, msg):
        """
        Question message box
        Parameters
        ----------
        main_window: QMainWindow
            Main window that is hosting the new window
        title: str
            QDialog title
        msg: str
            QDialog message

        Returns
        -------
        answer: bool
            If yes the answer is true
        """
        box = QMessageBox(main_window)
        box.setIcon(QMessageBox.Question)
        box.setWindowTitle(title)
        box.setText(msg)
        box.setStandardButtons(QMessageBox.Yes | QMessageBox.No)
        button_yes = box.button(QMessageBox.Yes)
        button_yes.setStyleSheet(WidgetStyle.BUTTON.value)
        button_no = box.button(QMessageBox.No)
        button_no.setStyleSheet(WidgetStyle.BUTTON.value)
        box.exec_()

        if box.clickedButton() == button_yes:
            return True
        elif box.clickedButton() == button_no:
            return False

    @staticmethod
    def disclaimerMessage(main_window):
        """
        Show disclaimer with QDialog
        Parameters
        ----------
        main_window: QMainWindow
            Main window that is hosting the new window
        Returns
        -------
        """
        msg = QLabel("""
        ASALI is free software.

        You can redistribute it and/or modify it the terms of the GNU General Public License as 
        published by the Free Software Foundation, either version 3 of the License, or (at your 
        option) any later version.

        ASALI is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
        without even the implied warranty of MERCHANTABILITY or FITNESS FOR A 
        PARTICULAR PURPOSE.

        See the GNU General Public License for more details. You should have received a copy 
        of the GNU General Public License along with ASALI. If not, see 
        http://www.gnu.org/licenses/.
        """)
        Utils.dialogMessage(main_window, "Disclaimer", msg)

    @staticmethod
    def contactMessage(main_window):
        """
        Show contact with QDialog
        Parameters
        ----------
        main_window: QMainWindow
            Main window that is hosting the new window
        Returns
        -------
        """
        msg = QLabel(f"""<p style="text-align: center">
        <a href='https://srebughini.github.io/ASALI/' style='color:{ColorPalette.LIGHTORANGE.value}'>Website</a>
        <br>
        <br>
        <a href='ste.rebu@outlook.it' style='color:{ColorPalette.LIGHTORANGE.value}'>E-mail</a>
        <br>
        <br>
        <a href='https://github.com/srebughini/ASALI/tree/master' style='color:{ColorPalette.LIGHTORANGE.value}'>Github</a>
        <br>
        <br>
        <a href='https://www.facebook.com/ASALIcode/' style='color:{ColorPalette.LIGHTORANGE.value}'>Facebook</a>
        <br>
        <br>
        <a href='https://www.linkedin.com/company/asalicode' style='color:{ColorPalette.LIGHTORANGE.value}'>LinkedIn</a>
        </p>
        <br>
        <br>
        <a href='https://sourceforge.net/projects/asali' style='color:{ColorPalette.LIGHTORANGE.value}'>SourceForge</a>
        </p>
        """)
        msg.setOpenExternalLinks(True)
        Utils.dialogMessage(main_window, "Contacts", msg)

    @staticmethod
    def somethingWentWrongMessage(main_window, title):
        """
        Show something went wrong message with QDialog
        Parameters
        ----------
        main_window: QMainWindow
            Main window that is hosting the new window
        Returns
        -------
        """
        Utils.dialogMessage(main_window, title, "Something went wrong!")

    @staticmethod
    def doneMessage(main_window, title, msg):
        """
        Show message with QDialog
        Parameters
        ----------
        main_window: QMainWindow
            Main window that is hosting the new window
        title: str
            QDialog title
        msg: QLabel
            QDialog message

        Returns
        -------
        """
        # Create the dialog
        dialog = QDialog(main_window, Qt.WindowCloseButtonHint)
        dialog.setWindowTitle(title)

        # Add a button
        button = QPushButton("Close", clicked=dialog.close)
        button.setStyleSheet(WidgetStyle.BUTTON.value)

        # Create the error icon
        icon_label = QLabel()
        icon_pixmap = QMessageBox.standardIcon(QMessageBox.Information)
        icon_label.setPixmap(icon_pixmap)  # Set the size of the icon as needed

        # Setup grid layout
        grid_layout = QGridLayout()
        grid_layout.addWidget(icon_label, 0, 0)
        grid_layout.addWidget(msg, 0, 1, )
        grid_layout.addWidget(button, 1, 0, 1, -1)
        dialog.setLayout(grid_layout)

        # Execute the dialog
        dialog.exec_()

    @staticmethod
    def errorMessage(main_window, title, msg):
        """
        Show message with QDialog
        Parameters
        ----------
        main_window: QMainWindow
            Main window that is hosting the new window
        title: str
            QDialog title
        msg: QLabel
            QDialog message

        Returns
        -------
        """
        # Create the dialog
        dialog = QDialog(main_window, Qt.WindowCloseButtonHint)
        dialog.setWindowTitle(title)

        # Add a button
        button = QPushButton("Close", clicked=dialog.close)
        button.setStyleSheet(WidgetStyle.BUTTON.value)

        # Create the error icon
        icon_label = QLabel()
        icon_pixmap = QMessageBox.standardIcon(QMessageBox.Critical)
        icon_label.setPixmap(icon_pixmap)  # Set the size of the icon as needed

        # Setup grid layout
        grid_layout = QGridLayout()
        grid_layout.addWidget(icon_label, 0, 0)
        grid_layout.addWidget(msg, 0, 1, )
        grid_layout.addWidget(button, 1, 0, 1, -1)
        dialog.setLayout(grid_layout)

        # Execute the dialog
        dialog.exec_()
