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
                border-bottom: 1px solid {ColorPalette.ORANGE.value};
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
