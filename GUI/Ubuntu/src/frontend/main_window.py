from PyQt5.QtWidgets import QPushButton, QLabel, QComboBox
from PyQt5.QtCore import Qt
from GUI.Ubuntu.src.frontend.basic import BasicMainWindow

# Example derived class
from GUI.Ubuntu.src.frontend.style import WidgetStyle


class MainWindow(BasicMainWindow):
    def initUI(self):
        """
        Run the User Interface
        Returns
        -------

        """
        # Add a dropdown menu for chemistry option
        self.row_idx = self.row_idx + 1
        dropdown = QComboBox()
        dropdown.addItems(["Default (only transport/thermodynamic)",
                           "Load CANTERA kinetic/properties file",
                           "User defined constant properties",
                           "CHEMKIN -> CANTERA converter",
                           "Make/Check ASALI kinetic scheme"])
        dropdown.setStyleSheet(WidgetStyle.DROPDOWN.value)
        #dropdown.currentIndexChanged.connect(self.on_dropdown_changed)

        self.col_idx = self.col_idx + 1
        self.grid.addWidget(QLabel("Create/Select the chemistry file: "), self.row_idx, self.col_idx)

        self.col_idx = self.col_idx + 1
        self.grid.addWidget(dropdown, self.row_idx, self.col_idx)

        """
        # Add a button
        defaultCanteraInputButton = QPushButton("Default (only transport/thermodynamic)")
        defaultCanteraInputButton.setStyleSheet(WidgetStyle.BUTTON.value)
        # button.clicked.connect(self.on_button_click)
        self.layout.addWidget(defaultCanteraInputButton)

        # Add a button
        loadCanteraInputButton = QPushButton("Load CANTERA kinetic/properties file")
        loadCanteraInputButton.setStyleSheet(WidgetStyle.BUTTON.value)
        # button.clicked.connect(self.on_button_click)
        self.layout.addWidget(loadCanteraInputButton)

        # Add a button
        noneInputButton = QPushButton("User defined constant properties")
        noneInputButton.setStyleSheet(WidgetStyle.BUTTON.value)
        # button.clicked.connect(self.on_button_click)
        self.layout.addWidget(noneInputButton)

        # Add a button
        conversionButton = QPushButton("CHEMKIN -> CANTERA converter")
        conversionButton.setStyleSheet(WidgetStyle.BUTTON.value)
        # button.clicked.connect(self.on_button_click)
        self.layout.addWidget(conversionButton)

        # Add a button
        asaliKineticButton = QPushButton("Make/Check ASALI kinetic scheme")
        asaliKineticButton.setStyleSheet(WidgetStyle.BUTTON.value)
        # button.clicked.connect(self.on_button_click)
        self.layout.addWidget(asaliKineticButton)
        """
