from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QDialog, QPushButton, QVBoxLayout, QMessageBox, QLabel, QGridLayout, QWidget

from src.controllers.label_formatter import LabelFormatter
from src.gui.config import Config


class DialogPagesHandler:
    def __init__(self, main_window):
        """
        Class to generate dialog pages
        Parameters
        ----------
        main_window: QMainWindow
            Main window object
        """
        self.main_window = main_window

    def dialog_message(self, msg) -> None:
        """
        Show message with QDialog
        Parameters
        ----------
        msg: QLabel
            QDialog message

        Returns
        -------
        """
        # Create a QDialog instance
        dialog = QDialog(self.main_window, Qt.WindowCloseButtonHint)
        dialog.setWindowTitle(Config.TITLE.value)

        # Create a layout for the dialog
        dialog_layout = QVBoxLayout()
        dialog_layout.addWidget(msg)

        # Set the layout for the dialog
        dialog.setLayout(dialog_layout)

        # Show the dialog as a modal dialog (blocks the main window)
        dialog.exec_()

    def disclaimer_message(self) -> None:
        """
        Show disclaimer with QDialog
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
        self.dialog_message(msg)

    def contact_message(self) -> None:
        """
        Show contact with QDialog
        Returns
        -------
        """

        msg = QLabel(f"""
        <p style="display: flex; align-items: center;">
            <a href="mailto:{Config.EMAIL.value}" style="text-decoration: none;">
                <img src='data:image/svg+xml;utf8,{Config.EMAIL_ICON.value}'>
            </a>
            &nbsp;&nbsp;
            <a href="{Config.SITE.value}" style="text-decoration: none;">
                <img src='data:image/svg+xml;utf8,{Config.SITE_ICON.value}'>
            </a>
            &nbsp;&nbsp;
            <a href="{Config.LINKEDIN.value}" style="text-decoration: none;">
                <img src='data:image/svg+xml;utf8,{Config.LINKEDIN_ICON.value}'>
            </a>
            &nbsp;&nbsp;
            <a href="{Config.GITHUB.value}" style="text-decoration: none;">
                <img src='data:image/svg+xml;utf8,{Config.GITHUB_ICON.value}'>
            </a>
            &nbsp;&nbsp;
            <a href="{Config.FACEBOOK.value}" style="text-decoration: none;">
                <img src='data:image/svg+xml;utf8,{Config.FACEBOOK_ICON.value}'>
            </a>
        </p>
                    """)
        msg.setOpenExternalLinks(True)
        msg.setAlignment(Qt.AlignCenter)
        self.dialog_message(msg)

    def question_message(self, msg) -> bool:
        """
        Question message box
        Parameters
        ----------
        msg: str
            QDialog message

        Returns
        -------
        answer: bool
            If yes the answer is true
        """
        box = QMessageBox(self.main_window)
        box.setIcon(QMessageBox.Question)
        box.setWindowTitle(Config.TITLE.value)
        box.setText(msg)
        box.setStandardButtons(QMessageBox.Yes | QMessageBox.No)
        button_yes = box.button(QMessageBox.Yes)
        button_no = box.button(QMessageBox.No)
        box.exec_()

        if box.clickedButton() == button_yes:
            return True
        elif box.clickedButton() == button_no:
            return False

    def something_went_wrong_message(self) -> None:
        """
        Show something went wrong message with QDialog
        Returns
        -------
        """
        self.dialog_message(QLabel("Something went wrong!"))

    def done_message(self, msg) -> None:
        """
        Show message with QDialog
        Parameters
        ----------
        msg: QLabel
            QDialog message

        Returns
        -------
        """
        # Create the dialog
        dialog = QDialog(self.main_window, Qt.WindowCloseButtonHint)
        dialog.setWindowTitle(Config.TITLE.value)

        # Add a button
        button = QPushButton(LabelFormatter.pad_string_center("Close"), clicked=dialog.close)

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

    def error_message(self, msg) -> None:
        """
        Show message with QDialog
        Parameters
        ----------
        msg: QLabel
            QDialog message

        Returns
        -------
        """
        # Create the dialog
        dialog = QDialog(self.main_window, Qt.WindowCloseButtonHint)
        dialog.setWindowTitle(Config.TITLE.value)

        # Add a button
        button = QPushButton(LabelFormatter.pad_string_center("Close"), clicked=dialog.close)

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
