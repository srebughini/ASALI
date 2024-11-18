from enum import Enum


class AppConfig(Enum):
    """
    Class to handle the software configuration
    """
    TITLE = "ASALI"
    MINIMUM_COLUMN_WIDTH = 150
    GRID_VERTICAL_SPACING = 12
    GRID_HORIZONTAL_SPACING = 12
    MATPLOTLIB_TOOLBAR = {'toolbar': 'None'}
    ICON_PATH = ":/images/Icon.png"
    DEFAULT_CHEMISTRY_FILE_PATH = "resources/database/data.yaml"
    BASE_LAYOUT_PATH = "gui/ui/base_layout.ui"
    CANTERA_FILE_TYPE = "Cantera file type (*.yaml);;All Files (*)"
    CANTERA_FILE_OPEN = "Open Cantera Input File"
    CANTERA_FILE_SAVE = "Save Cantera Input File"
    ASALI_FILE_TYPE = "Asali file type (*.json);;All Files (*)"
    ASALI_FILE_OPEN = "Open Asali User Defined Kinetic Input File"
    CHEMKIN_FILE_TYPE = "Chemkin file type (*.kin;*.sur; *.tdc;*.tra;*.ckin);;All Files (*)"
    CHEMKIN_FILE_OPEN = "Open Chemkin File"
    EXCEL_FILE_TYPE = "Excel file type (*.xlsx;*.xls);;All Files (*)"
    EXCEL_FILE_SAVE = "Save Excel Output File"
