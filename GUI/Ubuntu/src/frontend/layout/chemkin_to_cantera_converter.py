from functools import partial

from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import (
    QMainWindow, QLabel
)

from src.backend.chemkin_to_cantera_converter import ChemkinToCanteraConverter
from src.frontend.layout.basic import BasicLayout
from src.frontend.style import FileType
from src.frontend.window.utils import Utils


class ChemkinToCanteraConverterLayout(BasicLayout):
    def __init__(self, main_window):
        """
        Main menu layout
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        self._clean_label_text = "Not selected"

        super().__init__(main_window)

    def _createEmptyLabel(self):
        """
        Generate empty label
        Returns
        -------
        label: QLabel
            Empty Label
        """
        label = QLabel("Not selected")
        label.setAlignment(Qt.AlignCenter)
        return label

    def _loadFile(self, target_label):
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
        target_label: QLabel
            Target label to be updated
        """
        target_path = Utils.openFile(self.main_window,
                                     file_type=FileType.CHEMKIN.value)
        if target_path is not None:
            target_label.setText(target_path)

        return target_path

    def _clean(self):
        """
        Function to clean the input file paths
        Returns
        -------

        """
        for label in [self.thermoLabel, self.transportLabel, self.kineticLabel, self.surfaceLabel]:
            label.setText(self._clean_label_text)

    def _parsePath(self, label):
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
            Utils.errorMessage(self.main_window,
                               self.title,
                               QLabel("Missing input file"))
            return None

        return label.text()

    def _convert(self):
        """
        Function to convert from CHEMKIN to CANTERA kinetic file
        Returns
        -------
        """
        output_file_path = Utils.saveFile(self.main_window,
                                          "Save file",
                                          file_type=FileType.CANTERA.value)

        kinetic_file_path = self._parsePath(self.kineticLabel)
        thermo_file_path = self._parsePath(self.thermoLabel)
        transport_file_path = self._parsePath(self.transportLabel)
        surface_file_path = None if self.surfaceLabel.text() == self._clean_label_text else self.surfaceLabel.text()

        if output_file_path is not None:
            if self.userInput.check_file_extension(output_file_path, ".yaml"):
                ChemkinToCanteraConverter.convert(kinetic_file_path,
                                                  thermo_file_path,
                                                  transport_file_path,
                                                  surface_file_path,
                                                  output_file_path)

                self.userInput.file_path = output_file_path
                if self.userInput.check_cantera_input_file():
                    Utils.doneMessage(self.main_window,
                                      self.title,
                                      QLabel("CHEMKIN to CANTERA conversion completed!"))
                else:
                    Utils.errorMessage(self.main_window,
                                       self.title,
                                       QLabel("Something is wrong in the generated file!"))

    def initialize(self):
        """
        Initialize the widgets
        Returns
        -------

        """
        self.thermoLabel = self._createEmptyLabel()
        self.transportLabel = self._createEmptyLabel()
        self.kineticLabel = self._createEmptyLabel()
        self.surfaceLabel = self._createEmptyLabel()

        self.convertButton = self._createButton('Convert',
                                                self._convert,
                                                'Run CHEMKIN -> CANTERA converter')
        self.cleanButton = self._createButton('Clean',
                                              self._clean,
                                              'Clean input file path')
        self.loadThermoButton = self._createButton('Select thermo file',
                                                   partial(self._loadFile,
                                                           self.thermoLabel),
                                                   'Load thermo properties file')

        self.loadTransportButton = self._createButton('Select transport file',
                                                      partial(self._loadFile,
                                                              self.transportLabel),
                                                      'Load transport properties file')

        self.loadKineticButton = self._createButton('Select gas kinetic file',
                                                    partial(self._loadFile,
                                                            self.kineticLabel),
                                                    'Load gas kinetic file')

        self.loadSurfaceButton = self._createButton('Select surface kinetic file (optional)',
                                                    partial(self._loadFile,
                                                            self.surfaceLabel),
                                                    'Load surface kinetic file')

    def create(self):
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
