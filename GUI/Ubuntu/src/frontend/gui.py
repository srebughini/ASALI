from PyQt5.QtWidgets import QPushButton, QLabel
from PyQt5.QtCore import Qt
from GUI.Ubuntu.src.frontend.basic import BasicMainWindow


# Example derived class
from GUI.Ubuntu.src.frontend.style import WidgetStyle


class MainWindow(BasicMainWindow):
    def initUI(self):
        # Add a label
        #label = QLabel("Welcome to the Modern PyQt Application!", self)
        #label.setAlignment(Qt.AlignCenter)
        #label.setStyleSheet("font-size: 24px; margin: 20px;")
        #self.layout.addWidget(label)

        # Add a button
        button = QPushButton("Click Me")
        button.setStyleSheet(WidgetStyle.BUTTON.value)
        button.clicked.connect(self.on_button_click)
        self.layout.addWidget(button)

    def on_button_click(self):
        self.status_bar.showMessage("Button clicked!")
