import numpy as np
from PyQt5 import uic
from PyQt5.QtWidgets import QPushButton, QComboBox, QSizePolicy

from src.config.output.regression_output_page_config import RegressionOutputPageConfig
from src.config.output.regression_plot_output_page_config import RegressionPlotOutputPageConfig
from src.controllers.label_formatter import LabelFormatter
from src.core.data_keys import DataKeys
from src.gui.pages.basic_page import BasicPage
from src.gui.widgets.output.regression_plot_output_page import RegressionPlotOutputPageWidgets
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure


class RegressionPlotOutputPage(BasicPage):
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
        uic.loadUi(RegressionPlotOutputPageConfig.PATH.value, self)

        # Initialize Matplotlib figure
        self.figure = Figure(
            facecolor=RegressionPlotOutputPageConfig.PLOT_BACKGROUND_COLOR.value)  # Set figure background to transparent
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
        back_button = self.findChild(QPushButton, RegressionPlotOutputPageWidgets.BACK_BUTTON.value)
        back_button.clicked.connect(lambda: self.page_switched.emit(RegressionOutputPageConfig.NAME.value))

    def update_combo_box(self) -> None:
        """
        Update combo box
        Returns
        -------

        """
        dropdown = self.findChild(QComboBox, RegressionPlotOutputPageWidgets.PROPERTY_COMBO_BOX.value)
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

        dropdown = self.findChild(QComboBox, RegressionPlotOutputPageWidgets.PROPERTY_COMBO_BOX.value)

        regression_method = self.data_store.get_data(DataKeys.REGRESSION_METHOD)

        if dropdown.currentIndex() == 0:
            y = self.data_store.get_data(DataKeys.RHO_VECTOR)
            a, b, y_ud = self.data_store.get_data(DataKeys.RHO)
            if "linear" in regression_method.lower():
                title = RegressionPlotOutputPageConfig.PLOT_RHO_LINEAR.value.format(
                    LabelFormatter.float_to_string_no_pad(a),
                    LabelFormatter.float_to_string_no_pad(b))
            else:
                title = RegressionPlotOutputPageConfig.PLOT_RHO_POWER_LAW.value.format(
                    LabelFormatter.float_to_string_no_pad(a),
                    LabelFormatter.float_to_string_no_pad(b))

            y_label = RegressionPlotOutputPageConfig.PLOT_RHO_LABEL.value.format(y_ud)
            return x, x_ud, y, y_ud, a, b, title, y_label

        if dropdown.currentIndex() == 1:
            y = self.data_store.get_data(DataKeys.MU_VECTOR)
            a, b, y_ud = self.data_store.get_data(DataKeys.MU)
            if "linear" in regression_method.lower():
                title = RegressionPlotOutputPageConfig.PLOT_MU_LINEAR.value.format(
                    LabelFormatter.float_to_string_no_pad(a),
                    LabelFormatter.float_to_string_no_pad(b))
            else:
                title = RegressionPlotOutputPageConfig.PLOT_MU_POWER_LAW.value.format(
                    LabelFormatter.float_to_string_no_pad(a),
                    LabelFormatter.float_to_string_no_pad(b))

            y_label = RegressionPlotOutputPageConfig.PLOT_MU_LABEL.value.format(y_ud)
            return x, x_ud, y, y_ud, a, b, title, y_label

        if dropdown.currentIndex() == 2:
            y = self.data_store.get_data(DataKeys.COND_VECTOR)
            a, b, y_ud = self.data_store.get_data(DataKeys.COND)
            if "linear" in regression_method.lower():
                title = RegressionPlotOutputPageConfig.PLOT_COND_LINEAR.value.format(
                    LabelFormatter.float_to_string_no_pad(a),
                    LabelFormatter.float_to_string_no_pad(b))
            else:
                title = RegressionPlotOutputPageConfig.PLOT_COND_POWER_LAW.value.format(
                    LabelFormatter.float_to_string_no_pad(a),
                    LabelFormatter.float_to_string_no_pad(b))
            y_label = RegressionPlotOutputPageConfig.PLOT_COND_LABEL.value.format(y_ud)
            return x, x_ud, y, y_ud, a, b, title, y_label

        if dropdown.currentIndex() == 3:
            y = self.data_store.get_data(DataKeys.CP_VECTOR)
            a, b, y_ud = self.data_store.get_data(DataKeys.CP)
            if "linear" in regression_method.lower():
                title = RegressionPlotOutputPageConfig.PLOT_CP_LINEAR.value.format(
                    LabelFormatter.float_to_string_no_pad(a),
                    LabelFormatter.float_to_string_no_pad(b))
            else:
                title = RegressionPlotOutputPageConfig.PLOT_CP_POWER_LAW.value.format(
                    LabelFormatter.float_to_string_no_pad(a),
                    LabelFormatter.float_to_string_no_pad(b))
            y_label = RegressionPlotOutputPageConfig.PLOT_CP_LABEL.value.format(y_ud)
            return x, x_ud, y, y_ud, a, b, title, y_label

        if dropdown.currentIndex() == 4:
            y = self.data_store.get_data(DataKeys.H_VECTOR)
            a, b, y_ud = self.data_store.get_data(DataKeys.H)
            if "linear" in regression_method.lower():
                title = RegressionPlotOutputPageConfig.PLOT_H_LINEAR.value.format(
                    LabelFormatter.float_to_string_no_pad(a),
                    LabelFormatter.float_to_string_no_pad(b))
            else:
                title = RegressionPlotOutputPageConfig.PLOT_H_POWER_LAW.value.format(
                    LabelFormatter.float_to_string_no_pad(a),
                    LabelFormatter.float_to_string_no_pad(b))
            y_label = RegressionPlotOutputPageConfig.PLOT_H_LABEL.value.format(y_ud)
            return x, x_ud, y, y_ud, a, b, title, y_label

        if dropdown.currentIndex() == 5:
            y = self.data_store.get_data(DataKeys.S_VECTOR)
            a, b, y_ud = self.data_store.get_data(DataKeys.S)
            if "linear" in regression_method.lower():
                title = RegressionPlotOutputPageConfig.PLOT_S_LINEAR.value.format(
                    LabelFormatter.float_to_string_no_pad(a),
                    LabelFormatter.float_to_string_no_pad(b))
            else:
                title = RegressionPlotOutputPageConfig.PLOT_S_POWER_LAW.value.format(
                    LabelFormatter.float_to_string_no_pad(a),
                    LabelFormatter.float_to_string_no_pad(b))
            y_label = RegressionPlotOutputPageConfig.PLOT_S_LABEL.value.format(y_ud)
            return x, x_ud, y, y_ud, a, b, title, y_label

    def update_shown_data(self) -> None:
        """
        Update shown data
        Returns
        -------

        """
        x, x_ud, y, y_ud, a, b, title, y_label = self.read_data()

        regression_method = self.data_store.get_data(DataKeys.REGRESSION_METHOD)

        self.figure.clear()

        # Add centered axes
        ax = self.figure.add_axes(RegressionPlotOutputPageConfig.PLOT_ADD_AXES_ARG.value)

        # Set up background colors
        ax.set_facecolor(RegressionPlotOutputPageConfig.PLOT_BACKGROUND_COLOR.value)
        ax.tick_params(colors=RegressionPlotOutputPageConfig.PLOT_AXES_COLOR.value, which='both')
        ax.xaxis.label.set_color(RegressionPlotOutputPageConfig.PLOT_AXES_COLOR.value)
        ax.yaxis.label.set_color(RegressionPlotOutputPageConfig.PLOT_AXES_COLOR.value)
        ax.title.set_color(RegressionPlotOutputPageConfig.PLOT_AXES_COLOR.value)

        # Set tick counter (numbers) to white
        ax.spines['bottom'].set_color(RegressionPlotOutputPageConfig.PLOT_AXES_COLOR.value)
        ax.spines['left'].set_color(RegressionPlotOutputPageConfig.PLOT_AXES_COLOR.value)
        ax.spines['top'].set_color(RegressionPlotOutputPageConfig.PLOT_AXES_COLOR.value)
        ax.spines['right'].set_color(RegressionPlotOutputPageConfig.PLOT_AXES_COLOR.value)

        ax.plot(x,
                y,
                RegressionPlotOutputPageConfig.PLOT_DOT_SHAPE.value,
                color=RegressionPlotOutputPageConfig.PLOT_DOT_LINE_COLOR.value)

        if "linear" in regression_method.lower():
            ax.plot(x,
                    a * x + b,
                    color=RegressionPlotOutputPageConfig.PLOT_SOLID_LINE_COLOR.value)
        else:
            ax.plot(x,
                    a * np.power(x, b),
                    color=RegressionPlotOutputPageConfig.PLOT_SOLID_LINE_COLOR.value)

        ax.legend(RegressionPlotOutputPageConfig.PLOT_LEGEND.value,
                  loc=RegressionPlotOutputPageConfig.PLOT_LEGEND_POSITION.value,
                  frameon=RegressionPlotOutputPageConfig.PLOT_LEGEND_FRAME.value,
                  labelcolor=RegressionPlotOutputPageConfig.PLOT_LEGEND_COLOR.value)

        ax.set_title(title)
        ax.set_xlabel(RegressionPlotOutputPageConfig.PLOT_TEMPERATURE_LABEL.value.format(x_ud))
        ax.set_ylabel(y_label)

        # Set properties for centering
        ax.set_position(RegressionPlotOutputPageConfig.PLOT_SET_POSITION_ARG.value)

        self.canvas.draw()
