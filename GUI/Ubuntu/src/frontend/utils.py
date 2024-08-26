from enum import Enum

from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import (QFileDialog, QDialog, QPushButton, QVBoxLayout, QMessageBox, QLabel, QGridLayout, QWidget,
                             QMainWindow, QHBoxLayout)

from src.frontend.style import WidgetStyle, ColorPalette

import os


class SheetNames(Enum):
    X = "mole_fraction"
    Y = "mass_fraction"
    Z = "coverage"
    T = "temperature"
    SPECIE = "{}_{}"
    COVERAGE = "{}_{}"


class ReactorVariablesName(Enum):
    volume = "volume"
    alfa = "catalytic load"
    time = "integration time"
    timeStep = "time step"
    massFlowRate = "mass flow rate"
    initialTemperature = "initial temperature"
    diameter = "diameter"
    length = "length"
    lengthStep = "length step"
    udk = "user defined kinetic"
    temperature = "inlet temperature"
    pressure = "pressure"
    energy = "energy"
    z = "initial coverage"
    initialX = "initial mole fraction"
    initialY = "initial mass fraction"
    x = "inlet mole fraction"
    y = "inlet mass fraction"
    diffusion = "diffusion"
    inertCoverage = "inert coverage"
    inertSpecie = "inert specie"


class BasicUnitDimension(Enum):
    time = "s"
    temperature = "K"
    length = "m"


class ColumnNames(Enum):
    time = f"Time [{BasicUnitDimension.time.value}]"
    temperature = f"Temperature [{BasicUnitDimension.temperature.value}]"
    length = f"Length [{BasicUnitDimension.length.value}]"
    length_time = f"{length}/{time}"


class Utils:
    """
    Class to handle utilities functions
    """

    @staticmethod
    def window_title() -> str:
        """
        Get window title
        Returns
        -------
        title: str
            Window title
        """
        return "ASALI"

    @staticmethod
    def is_float(element) -> bool:
        """
        Function to check if str can be parsed to float
        Parameters
        ----------
        element: str
            Element to be parsed

        Returns
        -------
        check: bool
            True is can be parsed to float, False if not
        """
        if element is None:
            return False
        try:
            float(element)
            return True
        except ValueError:
            return False

    @staticmethod
    def string_length() -> int:
        """
        Return maximum string length
        Returns
        -------
        length: int
            String length
        """
        return 20

    @staticmethod
    def clean_layout(layout) -> QVBoxLayout | QGridLayout | QHBoxLayout:
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
                    Utils.clean_layout(item.layout())

        return layout

    @staticmethod
    def clean_widget(widget) -> QWidget:
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
    def open_new_window_from_layout(main_window, new_window_class, new_layout_class) -> None:
        """
        Open a new window
        Parameters
        ----------
        main_window: QMainWindow
            Main window that is hosting the new window
        new_window_class: BasicMainWindow derived class
            New window class to be opened
        new_layout_class: BasicLayout derived class
            New layout set to the window
        Returns
        -------
        """
        new_window = new_window_class(main_window)
        new_window.update_layout(new_layout_class)
        new_window.userInput = main_window.userInput
        new_window.run_backend()
        new_window.show()

    @staticmethod
    def open_new_window_from_window(main_window, new_window_class) -> None:
        """
        Open a new window
        Parameters
        ----------
        main_window: QMainWindow
            Main window that is hosting the new window
        new_window_class: BasicMainWindow derived class
            New window class to be opened
        Returns
        -------
        """
        new_window = new_window_class(main_window)
        new_window.userInput = main_window.userInput
        new_window.run_backend()
        new_window.show()

    @staticmethod
    def open_file(main_window, title="Load file", file_type="All Files (*)") -> str | None:
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
    def save_file(main_window, title="Save file", file_type="All Files (*)", default_extension=None) -> str | None:
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
        default_extension: str
            Default extension

        Returns
        -------
        file_path: str
            File path
        """
        file_path, selected_filter = QFileDialog.getSaveFileName(main_window, title, "", file_type)

        if not file_path:
            return None

        if default_extension is None:
            return file_path

        file_path_split = os.path.splitext(file_path)

        if len(file_path_split) == 2:
            return "{}{}".format(file_path_split[0], default_extension)

        if file_path_split[1] == ".*":
            return "{}{}".format(file_path_split[0], default_extension)

        return file_path

    @staticmethod
    def dialog_message(main_window, title, msg) -> None:
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
        button = QPushButton(Utils.pad_string_center("Close"), clicked=dialog.close)
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
    def question_message(main_window, title, msg) -> bool:
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
    def disclaimer_message(main_window) -> None:
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
        Utils.dialog_message(main_window, "Disclaimer", msg)

    @staticmethod
    def contact_message(main_window) -> None:
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
        Utils.dialog_message(main_window, "Contacts", msg)

    @staticmethod
    def something_went_wrong_message(main_window, title) -> None:
        """
        Show something went wrong message with QDialog
        Parameters
        ----------
        main_window: QMainWindow
            Main window that is hosting the new window
        Returns
        -------
        """
        Utils.dialog_message(main_window, title, QLabel("Something went wrong!"))

    @staticmethod
    def done_message(main_window, title, msg) -> None:
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
        button = QPushButton(Utils.pad_string_center("Close"), clicked=dialog.close)
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
    def error_message(main_window, title, msg) -> None:
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
        button = QPushButton(Utils.pad_string_center("Close"), clicked=dialog.close)
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

    @staticmethod
    def pad_string(original_str) -> str:
        """
        Pad a string to fixed length
        Parameters
        ----------
        original_str: str
            Original string

        Returns
        -------
        new_str: str
            New string of fixed length
        """
        new_str = f"{original_str:<{Utils.string_length()}}"
        if len(new_str) < len(original_str):
            print("Error in length str", original_str)
        return new_str

    @staticmethod
    def pad_string_center(original_str) -> str:
        """
        Pad a string to fixed length with text at the center
        Parameters
        ----------
        original_str: str
            Original string

        Returns
        -------
        new_str: str
            New string of fixed length
        """
        new_str = f"{original_str:^{Utils.string_length()}}"
        if len(new_str) < len(original_str):
            print("Error in length str", original_str)
        return new_str

    @staticmethod
    def from_number_to_string(number) -> str:
        """
        Convert number to string
        Parameters
        ----------
        number: float
            Number to be converted

        Returns
        -------
        number_as_str: str
            Number as string
        """
        return f"{number:.2E}"

    @staticmethod
    def from_dict_to_string(dictionary) -> str:
        """
        Convert dict to table like string
        Parameters
        ----------
        dictionary: dict
            Dictionary to be converted

        Returns
        -------
        dictionary_as_table: str
            Dictionary as string

        """
        return "\n".join([Utils.pad_string(f"{k}:\t{Utils.from_number_to_string(v)}") for k, v in dictionary.items()])

    @staticmethod
    def from_list_to_string(vector, horizontal=False) -> str:
        """
        Convert list to table like string
        Parameters
        ----------
        vector: list
            List to be converted
        horizontal: bool (optional)
            Enable/Disable the horizontal orientation

        Returns
        -------
        vector_as_string: str
            Vector as string

        """
        if horizontal:
            return "\t".join([Utils.pad_string(f"{Utils.from_number_to_string(v)}") for v in vector])

        return "\n".join([Utils.pad_string(f"{Utils.from_number_to_string(v)}") for v in vector])
