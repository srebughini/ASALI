import os
from enum import Enum
from types import SimpleNamespace


class AppConfig(Enum):
    """
    Class to handle the software configuration
    """
    TITLE = "ASALI"

    MINIMUM_COLUMN_WIDTH = 150
    GRID_VERTICAL_SPACING = 12
    GRID_HORIZONTAL_SPACING = 12
    GRID_MARGIN = (10, 10, 10, 10)
    VBOX_MARGIN = (10, 10, 10, 10)
    SCREEN_LOCATION = (50, 20)
    BEER_QUOTE_MAX_CHARACTERS = 45

    MATPLOTLIB_TOOLBAR = {'toolbar': 'None'}

    ICON_PATH = ":/images/Icon.png"
    DEFAULT_DATABASE_FILE_PATH = os.path.join("resources", "database", "data.yaml")

    BASE_LAYOUT_PATH = os.path.join("gui", "ui", "base_layout.ui")
    MAIN_INPUT_PAGE = SimpleNamespace(page_name="MainInputPage",
                                      path=os.path.join("gui", "ui", "input", "main_page.ui"))

    PROPERTIES_INPUT_PAGE = SimpleNamespace(page_name="PropertiesInputPage",
                                            path=os.path.join("gui", "ui", "input", "properties_page.ui"))
    PROPERTIES_OUTPUT_PAGE = SimpleNamespace(page_name="PropertiesOutputPage",
                                             path=os.path.join("gui", "ui", "output", "properties_page.ui"))

    VACUUM_INPUT_PAGE = SimpleNamespace(page_name="VacuumInputPage",
                                        path=os.path.join("gui", "ui", "input", "vacuum_page.ui"))
    VACUUM_OUTPUT_PAGE = SimpleNamespace(page_name="VacuumOutputPage",
                                         path=os.path.join("gui", "ui", "output", "vacuum_page.ui"))

    REGRESSION_INPUT_PAGE = SimpleNamespace(page_name="RegressionInputPage",
                                            path=os.path.join("gui", "ui", "input", "regression_page.ui"))
    REGRESSION_OUTPUT_PAGE = SimpleNamespace(page_name="RegressionOutputPage",
                                             path=os.path.join("gui", "ui", "output", "regression_page.ui"))

    EQUILIBRIUM_INPUT_PAGE = SimpleNamespace(page_name="EquilibriumInputPage",
                                             path=os.path.join("gui", "ui", "input", "equilibrium_page.ui"))
    EQUILIBRIUM_OUTPUT_PAGE = SimpleNamespace(page_name="EquilibriumOutputPage",
                                              path=os.path.join("gui", "ui", "output", "equilibrium_page.ui"))

    CHEMKIN_CONVERTER_INPUT_PAGE = SimpleNamespace(page_name="ChemkinConverterInputPage",
                                                   path=os.path.join("gui", "ui", "input", "chemkin_converter_page.ui"))

    CHEMKIN_TRANSPORT_INPUT_PAGE = SimpleNamespace(page_name="ChemkinTransportInputPage",
                                                   path=os.path.join("gui", "ui", "input", "chemkin_transport_page.ui"))

    CHEMKIN_THERMO_INPUT_PAGE = SimpleNamespace(page_name="ChemkinThermoInputPage",
                                                path=os.path.join("gui", "ui", "input", "chemkin_thermo_page.ui"))

    PRESSURE_DROPS_INPUT_PAGE = SimpleNamespace(page_name="PressureDropsInputPage",
                                                path=os.path.join("gui", "ui", "input", "pressure_drops_page.ui"))

    PRESSURE_DROPS_OUTPUT_PAGE = SimpleNamespace(page_name="PressureDropsOutputPage",
                                                 path=os.path.join("gui", "ui", "output", "pressure_drops_page.ui"))

    CANTERA_FILE_TYPE = "Cantera file type (*.yaml);;All Files (*)"
    CANTERA_FILE_OPEN = "Open Cantera Input File"
    CANTERA_FILE_SAVE = "Save Cantera Input File"
    ASALI_FILE_TYPE = "Asali file type (*.json);;All Files (*)"
    ASALI_FILE_OPEN = "Open Asali User Defined Kinetic Input File"
    CHEMKIN_FILE_TYPE = "Chemkin file type (*.kin *.sur *.tdc *.tra *.ckin);;All Files (*)"
    CHEMKIN_FILE_OPEN = "Open Chemkin File"
    EXCEL_FILE_TYPE = "Excel file type (*.xlsx *.xls);;All Files (*)"
    EXCEL_FILE_SAVE = "Save Excel Output File"
    CHEMKIN_TRANSPORT_FILE_TYPE = "Chemkin file type (*.tra);;All Files (*)"
    CHEMKIN_TRANSPORT_FILE_HEADLINE = "Chemkin Transport File"
    CHEMKIN_THERMO_FILE_TYPE = "Chemkin file type (*.tdc);;All Files (*)"
    CHEMKIN_THERMO_FILE_HEADLINE = "Chemkin Thermo File"
