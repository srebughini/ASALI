from PyQt5 import uic
from PyQt5.QtWidgets import QPushButton, QComboBox, QSizePolicy

from src.config.linear_regression_output_page_config import LinearRegressionOutputPageConfig
from src.config.linear_regression_plot_output_page_config import LinearRegressionPlotOutputPageConfig
from src.controllers.label_formatter import LabelFormatter
from src.core.data_keys import DataKeys
from src.gui.pages.basic_page import BasicPage
from src.gui.widgets.output.linear_regression_plot_output_page import LinearRegressionPlotOutputPageWidgets
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure


class LinearRegressionPlotOutputPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Linear regression output layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        uic.loadUi(LinearRegressionPlotOutputPageConfig.PATH.value, self)

        # Initialize Matplotlib figure
        self.figure = Figure(
            facecolor=LinearRegressionPlotOutputPageConfig.PLOT_BACKGROUND_COLOR.value)  # Set figure background to transparent
        self.canvas = FigureCanvas(self.figure)

        # Ensure the canvas expands with the layout
        self.canvas.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        self.canvas.updateGeometry()

        # Add padding around the canvas
        self.plotWidget.layout().addWidget(self.canvas)
        self.plotWidget.layout().setContentsMargins(10, 10, 10, 10)  # Left, Top, Right, Bottom margins

        self.update_combo_box()
        self.update_buttons()

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.update_shown_data()

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        back_button = self.findChild(QPushButton, LinearRegressionPlotOutputPageWidgets.BACK_BUTTON.value)
        back_button.clicked.connect(lambda: self.page_switched.emit(LinearRegressionOutputPageConfig.NAME.value))

    def update_combo_box(self) -> None:
        """
        Update combo box
        Returns
        -------

        """
        dropdown = self.findChild(QComboBox, LinearRegressionPlotOutputPageWidgets.PROPERTY_COMBO_BOX.value)
        dropdown.currentIndexChanged.connect(self.update_shown_data)

    def read_data(self) -> tuple:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------
        extracted_data: tuple
            Extracted that: x value, x unit dimensions, y values, y unit dimensions, slope, intercept, title, y label
        """
        x = self.data_store.get_data(DataKeys.TEMPERATURE_VECTOR)
        x_ud = self.data_store.get_data(DataKeys.MIN_TEMPERATURE)[-1]

        dropdown = self.findChild(QComboBox, LinearRegressionPlotOutputPageWidgets.PROPERTY_COMBO_BOX.value)
        if dropdown.currentIndex() == 0:
            y = self.data_store.get_data(DataKeys.RHO_VECTOR)
            a, b, y_ud = self.data_store.get_data(DataKeys.RHO)
            title = LinearRegressionPlotOutputPageConfig.PLOT_RHO_TITLE.value.format(
                LabelFormatter.float_to_string_no_pad(a),
                LabelFormatter.float_to_string_no_pad(b))
            y_label = LinearRegressionPlotOutputPageConfig.PLOT_RHO_LABEL.value.format(y_ud)
            return x, x_ud, y, y_ud, a, b, title, y_label

        if dropdown.currentIndex() == 1:
            y = self.data_store.get_data(DataKeys.MU_VECTOR)
            a, b, y_ud = self.data_store.get_data(DataKeys.MU)
            title = LinearRegressionPlotOutputPageConfig.PLOT_MU_TITLE.value.format(
                LabelFormatter.float_to_string_no_pad(a),
                LabelFormatter.float_to_string_no_pad(b))
            y_label = LinearRegressionPlotOutputPageConfig.PLOT_MU_LABEL.value.format(y_ud)
            return x, x_ud, y, y_ud, a, b, title, y_label

        if dropdown.currentIndex() == 2:
            y = self.data_store.get_data(DataKeys.COND_VECTOR)
            a, b, y_ud = self.data_store.get_data(DataKeys.COND)
            title = LinearRegressionPlotOutputPageConfig.PLOT_COND_TITLE.value.format(
                LabelFormatter.float_to_string_no_pad(a),
                LabelFormatter.float_to_string_no_pad(b))
            y_label = LinearRegressionPlotOutputPageConfig.PLOT_COND_LABEL.value.format(y_ud)
            return x, x_ud, y, y_ud, a, b, title, y_label

        if dropdown.currentIndex() == 3:
            y = self.data_store.get_data(DataKeys.CP_VECTOR)
            a, b, y_ud = self.data_store.get_data(DataKeys.CP)
            title = LinearRegressionPlotOutputPageConfig.PLOT_CP_TITLE.value.format(
                LabelFormatter.float_to_string_no_pad(a),
                LabelFormatter.float_to_string_no_pad(b))
            y_label = LinearRegressionPlotOutputPageConfig.PLOT_CP_LABEL.value.format(y_ud)
            return x, x_ud, y, y_ud, a, b, title, y_label

        if dropdown.currentIndex() == 4:
            y = self.data_store.get_data(DataKeys.H_VECTOR)
            a, b, y_ud = self.data_store.get_data(DataKeys.H)
            title = LinearRegressionPlotOutputPageConfig.PLOT_H_TITLE.value.format(
                LabelFormatter.float_to_string_no_pad(a),
                LabelFormatter.float_to_string_no_pad(b))
            y_label = LinearRegressionPlotOutputPageConfig.PLOT_H_LABEL.value.format(y_ud)
            return x, x_ud, y, y_ud, a, b, title, y_label

        if dropdown.currentIndex() == 5:
            y = self.data_store.get_data(DataKeys.S_VECTOR)
            a, b, y_ud = self.data_store.get_data(DataKeys.S)
            title = LinearRegressionPlotOutputPageConfig.PLOT_S_TITLE.value.format(
                LabelFormatter.float_to_string_no_pad(a),
                LabelFormatter.float_to_string_no_pad(b))
            y_label = LinearRegressionPlotOutputPageConfig.PLOT_S_LABEL.value.format(y_ud)
            return x, x_ud, y, y_ud, a, b, title, y_label

    def update_shown_data(self) -> None:
        """
        Update shown data
        Returns
        -------

        """
        x, x_ud, y, y_ud, a, b, title, y_label = self.read_data()

        self.figure.clear()

        # Add centered axes
        ax = self.figure.add_axes(LinearRegressionPlotOutputPageConfig.PLOT_ADD_AXES_ARG.value)

        # Set up background colors
        ax.set_facecolor(LinearRegressionPlotOutputPageConfig.PLOT_BACKGROUND_COLOR.value)
        ax.tick_params(colors=LinearRegressionPlotOutputPageConfig.PLOT_AXES_COLOR.value, which='both')
        ax.xaxis.label.set_color(LinearRegressionPlotOutputPageConfig.PLOT_AXES_COLOR.value)
        ax.yaxis.label.set_color(LinearRegressionPlotOutputPageConfig.PLOT_AXES_COLOR.value)
        ax.title.set_color(LinearRegressionPlotOutputPageConfig.PLOT_AXES_COLOR.value)

        # Set tick counter (numbers) to white
        ax.spines['bottom'].set_color(LinearRegressionPlotOutputPageConfig.PLOT_AXES_COLOR.value)
        ax.spines['left'].set_color(LinearRegressionPlotOutputPageConfig.PLOT_AXES_COLOR.value)
        ax.spines['top'].set_color(LinearRegressionPlotOutputPageConfig.PLOT_AXES_COLOR.value)
        ax.spines['right'].set_color(LinearRegressionPlotOutputPageConfig.PLOT_AXES_COLOR.value)

        ax.plot(x,
                y,
                LinearRegressionPlotOutputPageConfig.PLOT_DOT_SHAPE.value,
                color=LinearRegressionPlotOutputPageConfig.PLOT_DOT_LINE_COLOR.value)

        ax.plot(x,
                a * x + b,
                color=LinearRegressionPlotOutputPageConfig.PLOT_SOLID_LINE_COLOR.value)

        ax.legend(LinearRegressionPlotOutputPageConfig.PLOT_LEGEND.value,
                  loc=LinearRegressionPlotOutputPageConfig.PLOT_LEGEND_POSITION.value,
                  frameon=LinearRegressionPlotOutputPageConfig.PLOT_LEGEND_FRAME.value,
                  labelcolor=LinearRegressionPlotOutputPageConfig.PLOT_LEGEND_COLOR.value)

        ax.set_title(title)
        ax.set_xlabel(LinearRegressionPlotOutputPageConfig.PLOT_TEMPERATURE_LABEL.value.format(x_ud))
        ax.set_ylabel(y_label)

        # Set properties for centering
        ax.set_position(LinearRegressionPlotOutputPageConfig.PLOT_SET_POSITION_ARG.value)

        self.canvas.draw()
