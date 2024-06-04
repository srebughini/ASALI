import sys

from PyQt5.QtWidgets import QApplication
from GUI.Ubuntu.src.frontend.gui import MainWindow


def main():
    app = QApplication(sys.argv)
    app.setStyle("Fusion")

    # Create and show the main window
    window = MainWindow()
    window.show()

    sys.exit(app.exec_())

if __name__ == "__main__":
    main()