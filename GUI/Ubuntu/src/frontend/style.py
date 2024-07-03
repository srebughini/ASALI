from enum import Enum


class FileType(Enum):
    CANTERA = "CANTERA file type (*.yaml)"
    ASALI = "ASALI file type (*.json)"
    CHEMKIN = "CHEMIKIN file type (*.kin;*.sur; *.tdc;*.tra;*.ckin)"


class ColorPalette(Enum):
    BLUE = "#10253F"
    LIGHTBLUE = "#DCE6F2"
    LIGHTORANGE = "#f2e8dc"
    ORANGE = "#DB901F"


class WidgetStyle(Enum):
    WINDOW = f"""
            background-color: {ColorPalette.BLUE.value}; 
            color: {ColorPalette.LIGHTBLUE.value};
            """

    LOGO = "padding: 5px;"

    ITALICLABEL = f"""
            font: italic;
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
