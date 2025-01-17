from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QDialog, QPushButton, QVBoxLayout, QMessageBox, QLabel, QGridLayout, QSizePolicy, \
    QFileDialog, QTableWidget, QScrollBar, QHeaderView, QTableWidgetItem

from src.config.contact import ContactConfig
from src.controllers.label_formatter import LabelFormatter
from src.core.data_keys import DataKeys
from src.core.species_names import gas_species_names, surface_species_names
from src.config.app import AppConfig


class DialogPagesHandler:
    def __init__(self, main_window, data_store):
        """
        Class to generate dialog pages
        Parameters
        ----------
        main_window: QMainWindow
            Main window object
        data_store: DataStore
            Class to handle the user input
        """
        self.main_window = main_window
        self.data_store = data_store

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
        dialog.setWindowTitle(AppConfig.TITLE.value)

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
            <a href="mailto:{ContactConfig.EMAIL.value}" style="text-decoration: none;">
                <img src='data:image/svg+xml;utf8,{ContactConfig.EMAIL_ICON.value}'>
            </a>
            &nbsp;&nbsp;
            <a href="{ContactConfig.SITE.value}" style="text-decoration: none;">
                <img src='data:image/svg+xml;utf8,{ContactConfig.SITE_ICON.value}'>
            </a>
            &nbsp;&nbsp;
            <a href="{ContactConfig.LINKEDIN.value}" style="text-decoration: none;">
                <img src='data:image/svg+xml;utf8,{ContactConfig.LINKEDIN_ICON.value}'>
            </a>
            &nbsp;&nbsp;
            <a href="{ContactConfig.GITHUB.value}" style="text-decoration: none;">
                <img src='data:image/svg+xml;utf8,{ContactConfig.GITHUB_ICON.value}'>
            </a>
            &nbsp;&nbsp;
            <a href="{ContactConfig.FACEBOOK.value}" style="text-decoration: none;">
                <img src='data:image/svg+xml;utf8,{ContactConfig.FACEBOOK_ICON.value}'>
            </a>
        </p>
                    """)
        msg.setOpenExternalLinks(True)
        msg.setAlignment(Qt.AlignCenter)
        self.dialog_message(msg)

    def info_message(self) -> None:
        """
        Show help message QDialog
        Returns
        -------
        """
        # Create the dialog
        dialog = QDialog(self.main_window, Qt.WindowCloseButtonHint)
        dialog.setWindowTitle(AppConfig.TITLE.value)

        # Setup grid layout
        grid_layout = QGridLayout()
        grid_layout.setVerticalSpacing(AppConfig.GRID_VERTICAL_SPACING.value)
        grid_layout.setHorizontalSpacing(AppConfig.GRID_HORIZONTAL_SPACING.value)

        for i, label_as_str in enumerate(["Cantera file path:",
                                          "Asali user defined kinetic file path:",
                                          "Reactor model:",
                                          "Gas phase name:",
                                          "Surface phase name:"]):
            label = QLabel(label_as_str)
            label.setProperty("class", "orange")
            grid_layout.addWidget(label, i, 0)

        for i, k in enumerate([DataKeys.CHEMISTRY_FILE_PATH,
                               DataKeys.USER_DEFINED_KINETIC_FILE_PATH,
                               DataKeys.REACTOR_NAME,
                               DataKeys.GAS_PHASE_NAME,
                               DataKeys.SURFACE_PHASE_NAME]):
            file_path = self.data_store.get_data(k)
            label = QLabel("Not selected") if file_path is None else QLabel(file_path)
            label.setProperty("class", "italic")
            label.setTextInteractionFlags(Qt.TextSelectableByMouse)
            grid_layout.addWidget(label, i, 1)

        self.data_store = gas_species_names(self.data_store)
        self.data_store = surface_species_names(self.data_store)

        gas_names = self.data_store.get_data(DataKeys.GAS_SPECIES_NAMES)
        surf_names = self.data_store.get_data(DataKeys.SURFACE_SPECIES_NAMES)

        if gas_names is None:
            gas_names = list()

        if surf_names is None:
            surf_names = list()

        # Create a QTableView and set the proxy model
        table = QTableWidget()

        # Set row and column count
        n_row = max(len(gas_names), len(surf_names))

        table.setRowCount(n_row)  # For testing, create 100 rows
        table.setColumnCount(2)  # Set 5 columns

        for i, n in enumerate(gas_names):
            table.setItem(i, 0, QTableWidgetItem(f"{n}"))

        for i, n in enumerate(surf_names):
            table.setItem(i, 1, QTableWidgetItem(f"{n}"))

        # Set column headers
        table.setHorizontalHeaderLabels(["Gas phase", "Surface phase"])

        # Disable index
        table.verticalHeader().setVisible(False)

        # Enable scrolling
        table.setVerticalScrollBar(QScrollBar())  # Vertical scrollbar for scrolling through rows

        # Resize columns to fit content
        table.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)

        # Create the headline label
        headline_label = QLabel("Species names in your file")
        headline_label.setAlignment(Qt.AlignCenter)
        headline_label.setProperty("class", "highlight")

        layout = QVBoxLayout()
        layout.addLayout(grid_layout)
        layout.addWidget(headline_label)
        layout.addWidget(table)

        dialog.setLayout(layout)

        # Execute the dialog
        dialog.exec_()

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
        box.setWindowTitle(AppConfig.TITLE.value)
        box.setText(msg)
        box.setStandardButtons(QMessageBox.Yes | QMessageBox.No)
        button_yes = box.button(QMessageBox.Yes)
        button_no = box.button(QMessageBox.No)

        # Access the buttons and set their size policy
        for button in box.buttons():
            button.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)

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
        dialog.setWindowTitle(AppConfig.TITLE.value)

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
        dialog.setWindowTitle(AppConfig.TITLE.value)

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

    def load_file(self, title, file_format) -> str | None:
        """
        Load a generic file
        Parameters
        ----------
        title: str
            Dialog window title
        file_format: str
            File format

        Returns
        -------
        file_path: str | None
            File path selected
        """
        file_path, _ = QFileDialog.getOpenFileName(self.main_window,
                                                   title,
                                                   "",
                                                   file_format)
        return file_path

    def save_file(self, title, file_format) -> str | None:
        """
        Save a generic file
        Parameters
        ----------
        title: str
            Dialog window title
        file_format: str
            File format

        Returns
        -------
        file_path: str | None
            File path selected
        """
        file_path, _ = QFileDialog.getSaveFileName(self.main_window,
                                                   title,
                                                   "",
                                                   file_format)

        if len(file_path) == 0:
            return None

        return file_path
