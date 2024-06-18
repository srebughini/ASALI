from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QLabel, QComboBox, QPushButton
from GUI.Ubuntu.src.frontend.basic import BasicMainWindow

# Example derived class
from GUI.Ubuntu.src.frontend.style import WidgetStyle


class ChemkinToCanteraConverterWindow(BasicMainWindow):
    def __init__(self, mainWindowObject):
        """
        CHEMKIN -> CANTERA converter window
        Parameters
        ----------
        mainWindowObject: QMainWindow
            QMainWindow object
        """
        super().__init__(mainWindowObject)

    def _createConvertButton(self):
        """
        Generate convert button
        Returns
        -------
        button: QPushButton
            Next page button
        """
        button = QPushButton('Convert', self.mainWindowObject)
        button.setToolTip('Run CHEMKIN -> CANTERA converter')
        button.setStyleSheet(WidgetStyle.BUTTON.value)
        # button.clicked.connect(self._nextWindows)
        return button

    def _createLoadThermoButton(self):
        """
        Generate load thermo file button
        Returns
        -------
        button: QPushButton
            Load button
        """
        button = QPushButton('Select thermodynamic file', self.mainWindowObject, clicked=self._loadThermoFile)
        button.setToolTip('Load thermodynamic properties file')
        button.setStyleSheet(WidgetStyle.BUTTON.value)
        return button

    def _createLoadTransportButton(self):
        """
        Generate load transport file button
        Returns
        -------
        button: QPushButton
            Load button
        """
        button = QPushButton('Select transport file', self.mainWindowObject, clicked=self._loadTransportFile)
        button.setToolTip('Load transport properties file')
        button.setStyleSheet(WidgetStyle.BUTTON.value)
        return button

    def _createLoadKineticButton(self):
        """
        Generate load gas kinetic file button
        Returns
        -------
        button: QPushButton
            Load button
        """
        button = QPushButton('Select gas kinetic file', self.mainWindowObject, clicked=self._loadKineticFile)
        button.setToolTip('Load gas kinetic file')
        button.setStyleSheet(WidgetStyle.BUTTON.value)
        return button

    def _createLoadSurfaceButton(self):
        """
        Generate load surface kinetic file button
        Returns
        -------
        button: QPushButton
            Load button
        """
        button = QPushButton('Select surface kinetic file (optional)', self.mainWindowObject, clicked=self._loadSurfaceFile)
        button.setToolTip('Load surface kinetic file')
        button.setStyleSheet(WidgetStyle.BUTTON.value)
        return button

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

    def _loadThermoFile(self):
        """
        Function to load thermo file path
        Returns
        -------

        """
        self._thermo_file_path = self._openFile()
        if self._thermo_file_path is not None:
            self.thermoLabel.setText(self._thermo_file_path)

    def _loadTransportFile(self):
        """
        Function to load transport file path
        Returns
        -------

        """
        self._transport_file_path = self._openFile()
        if self._transport_file_path is not None:
            self.transportLabel.setText(self._transport_file_path)

    def _loadKineticFile(self):
        """
        Function to load gas kinetic file path
        Returns
        -------

        """
        self._kinetic_file_path = self._openFile()
        if self._kinetic_file_path is not None:
            self.kineticLabel.setText(self._kinetic_file_path)

    def _loadSurfaceFile(self):
        """
        Function to load surface kinetic file path
        Returns
        -------

        """
        self._surface_file_path = self._openFile()
        if self._surface_file_path is not None:
            self.surfaceLabel.setText(self._surface_file_path)

    def initWidget(self):
        """
        Initialize the widgets
        Returns
        -------

        """
        self.convertButton = self._createConvertButton()
        self.loadThermoButton = self._createLoadThermoButton()
        self.thermoLabel = self._createEmptyLabel()
        self.loadTransportButton = self._createLoadTransportButton()
        self.transportLabel = self._createEmptyLabel()
        self.loadKineticButton = self._createLoadKineticButton()
        self.kineticLabel = self._createEmptyLabel()
        self.loadSurfaceButton = self._createLoadSurfaceButton()
        self.surfaceLabel = self._createEmptyLabel()

    def initUI(self):
        """
        Run the User Interface
        Returns
        -------

        """
        # Add a dropdown menu for chemistry option
        self.row_idx = self.row_idx + 1
        self.grid.addWidget(self.loadThermoButton, self.row_idx, 0)
        self.grid.addWidget(self.thermoLabel, self.row_idx, 1)

        self.row_idx = self.row_idx + 1
        self.grid.addWidget(self.loadTransportButton, self.row_idx, 0)
        self.grid.addWidget(self.transportLabel, self.row_idx, 1)

        self.row_idx = self.row_idx + 1
        self.grid.addWidget(self.loadKineticButton, self.row_idx, 0)
        self.grid.addWidget(self.kineticLabel, self.row_idx, 1)

        self.row_idx = self.row_idx + 1
        self.grid.addWidget(self.loadSurfaceButton, self.row_idx, 0)
        self.grid.addWidget(self.surfaceLabel, self.row_idx, 1)

        self.row_idx = self.row_idx + 1
        self.grid.addWidget(self.convertButton, self.row_idx, 0, 1, -1)
