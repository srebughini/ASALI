from functools import partial

from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import (
    QMainWindow, QLabel
)

from src.backend.chemkin_to_cantera_converter import ChemkinToCanteraConverter
from src.frontend.layout.basic import BasicLayout
from src.frontend.style import FileType
from src.frontend.utils import Utils


class ChemkinToCanteraConverterLayout(BasicLayout):
    def __init__(self, main_window):
        """
        Main menu layout
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        self.thermoLabel = None
        self.transportLabel = None
        self.kineticLabel = None
        self.surfaceLabel = None
        self.convertButton = None
        self.cleanButton = None
        self.loadThermoButton = None
        self.loadTransportButton = None
        self.loadKineticButton = None
        self.loadSurfaceButton = None

        self._clean_label_text = Utils.pad_string_center("Not selected")
        super().__init__(main_window)

    def _create_empty_label(self) -> QLabel:
        """
        Generate empty label
        Returns
        -------
        label: QLabel
            Empty Label
        """
        label = QLabel(self._clean_label_text)
        label.setAlignment(Qt.AlignCenter)
        return label

    def _load_file(self, target_label) -> str:
        """
        Function to load file path
        Parameters
        ----------
        target_label: QLabel
            Target label to be updated

        Returns
        -------
        target_path: str
            Target file path
        """
        target_path = Utils.open_file(self.main_window,
                                      file_type=FileType.CHEMKIN.value)
        if target_path is not None:
            target_label.setText(target_path)

        return target_path

    def _clean(self) -> None:
        """
        Function to clean the input file paths
        Returns
        -------

        """
        for label in [self.thermoLabel, self.transportLabel, self.kineticLabel, self.surfaceLabel]:
            label.setText(self._clean_label_text)

    def _parse_path(self, label) -> str | None:
        """
        Function to parse the file path
        Parameters
        ----------
        label: QLabel
            Label with the saved file path

        Returns
        -------
        path: str
            Path of the file
        """
        if label.text() == self._clean_label_text:
            Utils.error_message(self.main_window,
                                self.title,
                                QLabel("Missing input file"))
            return None

        return label.text()

    def _convert(self) -> None:
        """
        Function to convert from CHEMKIN to CANTERA kinetic file
        Returns
        -------
        """
        output_file_path = Utils.save_file(self.main_window,
                                           "Save file",
                                           file_type=FileType.CANTERA.value)

        kinetic_file_path = self._parse_path(self.kineticLabel)
        thermo_file_path = self._parse_path(self.thermoLabel)
        transport_file_path = self._parse_path(self.transportLabel)
        surface_file_path = None if self.surfaceLabel.text() == self._clean_label_text else self.surfaceLabel.text()

        if output_file_path is not None:
            if self.main_window.backend_frontend_manager.check_file_extension(output_file_path, ".yaml"):
                ChemkinToCanteraConverter.convert(kinetic_file_path,
                                                  thermo_file_path,
                                                  transport_file_path,
                                                  surface_file_path,
                                                  output_file_path)

                self.main_window.backend_frontend_manager.file_path = output_file_path
                if self.main_window.backend_frontend_manager.check_cantera_input_file():
                    Utils.done_message(self.main_window,
                                       self.title,
                                       QLabel("CHEMKIN to CANTERA conversion completed!"))
                else:
                    Utils.error_message(self.main_window,
                                        self.title,
                                        QLabel("Something is wrong in the generated file!"))

    def run_backend(self) -> None:
        """
        Run backend to update frontend
        Returns
        -------

        """
        pass

    def create_layout_components(self) -> None:
        """
        Initialize the widgets
        Returns
        -------

        """
        self.thermoLabel = self._create_empty_label()
        self.transportLabel = self._create_empty_label()
        self.kineticLabel = self._create_empty_label()
        self.surfaceLabel = self._create_empty_label()

        self.convertButton = self._create_button(Utils.pad_string_center('Convert'),
                                                 self._convert,
                                                 'Run CHEMKIN -> CANTERA converter')
        self.cleanButton = self._create_button(Utils.pad_string_center('Clean'),
                                               self._clean,
                                               'Clean input file path')
        self.loadThermoButton = self._create_button(Utils.pad_string_center('Select thermo file'),
                                                    partial(self._load_file,
                                                            self.thermoLabel),
                                                    'Load thermo properties file')

        self.loadTransportButton = self._create_button(Utils.pad_string_center('Select transport file'),
                                                       partial(self._load_file,
                                                               self.transportLabel),
                                                       'Load transport properties file')

        self.loadKineticButton = self._create_button(Utils.pad_string_center('Select gas kinetic file'),
                                                     partial(self._load_file,
                                                             self.kineticLabel),
                                                     'Load gas kinetic file')

        self.loadSurfaceButton = self._create_button(Utils.pad_string('Select surface kinetic file (optional)'),
                                                     partial(self._load_file,
                                                             self.surfaceLabel),
                                                     'Load surface kinetic file')

    def generate_layout(self) -> None:
        """
         Update the interface
         Returns
         -------
         """
        self.row_idx = self.row_idx + 1
        self.addWidget(self.loadThermoButton, self.row_idx, 0)
        self.addWidget(self.thermoLabel, self.row_idx, 1)

        self.row_idx = self.row_idx + 1
        self.addWidget(self.loadTransportButton, self.row_idx, 0)
        self.addWidget(self.transportLabel, self.row_idx, 1)

        self.row_idx = self.row_idx + 1
        self.addWidget(self.loadKineticButton, self.row_idx, 0)
        self.addWidget(self.kineticLabel, self.row_idx, 1)

        self.row_idx = self.row_idx + 1
        self.addWidget(self.loadSurfaceButton, self.row_idx, 0)
        self.addWidget(self.surfaceLabel, self.row_idx, 1)

        self.row_idx = self.row_idx + 1
        self.addWidget(self.cleanButton, self.row_idx, 0, )
        self.addWidget(self.convertButton, self.row_idx, 1)
