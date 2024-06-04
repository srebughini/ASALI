from PyQt5.QtWidgets import QPushButton, QLabel
from PyQt5.QtCore import Qt
from GUI.Ubuntu.src.frontend.basic import AbstractStyledMainWindow


# Example derived class


class MainWindow(AbstractStyledMainWindow):
    def initUI(self):
        # Add a label
        label = QLabel("Welcome to the Modern PyQt Application!", self)
        label.setAlignment(Qt.AlignCenter)
        label.setStyleSheet("font-size: 24px; margin: 20px;")
        self.layout.addWidget(label)

        # Add a button
        button = QPushButton("Click Me")
        button.setStyleSheet("""
            QPushButton {
                background-color: #88C0D0;
                border: none;
                color: #2E3440;
                padding: 10px 20px;
                text-align: center;
                font-size: 16px;
                margin: 20px;
                border-radius: 10px;
            }
            QPushButton:hover {
                background-color: #81A1C1;
            }
            QPushButton:pressed {
                background-color: #5E81AC;
            }
        """)
        button.clicked.connect(self.on_button_click)
        self.layout.addWidget(button)

    def on_button_click(self):
        self.status_bar.showMessage("Button clicked!")
