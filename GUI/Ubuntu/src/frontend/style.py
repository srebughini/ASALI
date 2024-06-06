from enum import Enum


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
    BUTTON = f"""
            QPushButton {{
                background-color: {ColorPalette.LIGHTBLUE.value};
                border: none;
                color: #2E3440;
                padding: 10px 20px;
                text-align: center;
                font-size: 16px;
                margin: 20px;
                border-radius: 10px;
            }}
            QPushButton:hover {{
                background-color: {ColorPalette.LIGHTORANGE.value};
            }}
            QPushButton:pressed {{
                background-color: {ColorPalette.LIGHTORANGE.value};
            }}
        """
