from enum import Enum


class FileType(Enum):
    CANTERA = "CANTERA file type (*.yaml)"
    ASALI = "ASALI file type (*.json)"
    CHEMKIN = "CHEMIKIN file type (*.kin;*.sur; *.tdc;*.tra;*.ckin)"
    EXCEL = "Excel file type (*.xlsx;*.xls)"


class ColorPalette(Enum):
    BLUE = "#10253F"
    LIGHTBLUE = "#DCE6F2"
    LIGHTORANGE = "#f2e8dc"
    ORANGE = "#DB901F"


class SheetNames(Enum):
    X = "mole_fraction"
    Y = "mass_fraction"
    Z = "coverage"
    T = "temperature"


class ColumnNames(Enum):
    time = "Time [s]"
    temperature = "Temperature [K]"


class WidgetStyle(Enum):
    WINDOW = f"""
            background-color: {ColorPalette.BLUE.value}; 
            color: {ColorPalette.LIGHTBLUE.value};
            """

    LOGO = "padding: 5px;"

    ITALICLABEL = f"""
            font: italic;
            """

    HIGHLIGHTLABEL = f"""
            QLabel {{
                color: {ColorPalette.ORANGE.value};
                padding: 5px;
                font: bold;
            }}
            """

    BUTTON = f"""
            QPushButton {{
                background-color: {ColorPalette.LIGHTBLUE.value};
                border: none;
                color: {ColorPalette.BLUE.value};
                padding: 5px 10px;
                text-align: center;
                border-radius: 5px;
            }}
            QPushButton:hover {{
                background-color: {ColorPalette.LIGHTORANGE.value};
            }}
            QPushButton:pressed {{
                background-color: {ColorPalette.LIGHTORANGE.value};
            }}
        """

    DROPDOWN = f"""
            QComboBox {{
                background-color: {ColorPalette.ORANGE.value};
                color: {ColorPalette.BLUE.value};
            }}
            
            QComboBox QAbstractItemView {{
                background-color: {ColorPalette.LIGHTBLUE.value};
            }}
        """

    LINEEDIT = f"""
            QLineEdit {{
                background-color: {ColorPalette.LIGHTBLUE.value};
                color: {ColorPalette.BLUE.value};
            }}

        """

    CHECKBOX = f"""
            QCheckBox::indicator {{
                border-radius: 10px; /* Makes the indicator circular */
                background-color: {ColorPalette.LIGHTBLUE.value};
            }}
            
            QCheckBox::indicator:checked {{
                    background-color: {ColorPalette.ORANGE.value};
            }}
            
            QCheckBox::indicator:pressed {{
                    background-color: {ColorPalette.ORANGE.value}; /* Optional: Change color when pressed */
            }}
        """
