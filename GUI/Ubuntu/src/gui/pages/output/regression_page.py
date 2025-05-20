from PyQt5 import uic
from PyQt5.QtWidgets import QSizePolicy
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure

from src.config.app import AppConfig
from src.config.regression_plot import RegressionPlotConfig
from src.core.data_keys import DataKeys
from src.core.regression_calculator import regression_calculator
from src.gui.enums.properties import Properties
from src.gui.enums.regression_method import RegressionMethod
from src.gui.pages.basic_page import BasicPage
from src.gui.components.output.regression_page import RegressionOutputPageComponents

import numpy as np


class RegressionOutputPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Regression output layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        uic.loadUi(AppConfig.REGRESSION_OUTPUT_PAGE.value.path, self)

        # Initialize Matplotlib figure
        self.figure = Figure(
            facecolor=RegressionPlotConfig.BACKGROUND_COLOR.value)  # Set figure background to transparent
        self.canvas = FigureCanvas(self.figure)

        # Ensure the canvas resizes correctly within the layout
        self.canvas.setSizePolicy(QSizePolicy.MinimumExpanding, QSizePolicy.MinimumExpanding)

        self.plotLayout = self.find_widget(RegressionOutputPageComponents.PLOT_LAYOUT)
        self.plotLayout.addWidget(self.canvas)
        self.plotLayout.setContentsMargins(*RegressionPlotConfig.MARGIN.value)

        self.update_combo_boxes()
        self.update_buttons()
        self.updateGeometry()

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.set_custom_dimensions_to_grid_layout(self.find_widget(RegressionOutputPageComponents.GRID))
        self.data_store.update_data(DataKeys.LAST_ACTIVE_WINDOW, AppConfig.PROPERTIES_OUTPUT_PAGE)
        self.run_regression()

    def update_combo_boxes(self) -> None:
        """
        Update combo boxes
        Returns
        -------

        """
        for widget_enum in [RegressionOutputPageComponents.TEMPERATURE_UD,
                            RegressionOutputPageComponents.REGRESSION_METHOD]:
            widget = self.find_widget(widget_enum)
            widget.addItems(widget_enum.value.items)

        widget_enum = RegressionOutputPageComponents.PROPERTY
        widget = self.find_widget(widget_enum)
        widget.addItems(widget_enum.value.items)
        widget.currentIndexChanged.connect(self.update_unit_dimensions)

        self.update_unit_dimensions()

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        back_button = self.find_widget(RegressionOutputPageComponents.BACK_BUTTON)
        back_button.clicked.connect(lambda: self.page_switched.emit(AppConfig.REGRESSION_INPUT_PAGE))

        update_button = self.find_widget(RegressionOutputPageComponents.UPDATE_BUTTON)
        update_button.clicked.connect(self.run_regression)

    def update_unit_dimensions(self) -> None:
        """
        Update unit dimensions
        Returns
        -------

        """
        property_combo_box = self.find_widget(RegressionOutputPageComponents.PROPERTY)
        current_property = Properties(property_combo_box.currentText())

        property_ud_combo_box = self.find_widget(RegressionOutputPageComponents.PROPERTY_UD)
        property_ud_combo_box.clear()
        property_ud_combo_box.addItems(RegressionOutputPageComponents.PROPERTY_UD.value.items[current_property])

    def extract_data(self) -> tuple:
        """
        Update data store with properties unit dimensions
        Returns
        -------
        data_to_plot: tuple
            Data to be plotted in the following format: independent variable,
                                                        independent variable unit dimensions,
                                                        dependent variable,
                                                        fitted dependent variable,
                                                        dependent variable unit dimensions,
                                                        dependent variable name
                                                        regression formula as title

        """
        current_property = self.data_store.get_data(DataKeys.REGRESSION_PROPERTY_TYPE)

        property_config_map = {
            Properties.DENSITY: (RegressionPlotConfig.RHO_SYMBOL.value, RegressionPlotConfig.RHO_LABEL.value),
            Properties.VISCOSITY: (RegressionPlotConfig.MU_SYMBOL.value, RegressionPlotConfig.MU_LABEL.value),
            Properties.SPECIFIC_HEAT: (RegressionPlotConfig.CP_SYMBOL.value, RegressionPlotConfig.CP_LABEL.value),
            Properties.ENTHALPY: (RegressionPlotConfig.H_SYMBOL.value, RegressionPlotConfig.H_LABEL.value),
            Properties.ENTROPY: (RegressionPlotConfig.S_SYMBOL.value, RegressionPlotConfig.S_LABEL.value),
            Properties.THERMAL_CONDUCTIVITY: (
                RegressionPlotConfig.COND_SYMBOL.value, RegressionPlotConfig.COND_LABEL.value),
        }

        symbol, y_label = property_config_map[current_property]

        regression_method = self.data_store.get_data(DataKeys.REGRESSION_METHOD)

        x, x_ud = self.data_store.get_data(DataKeys.TEMPERATURE_VECTOR)
        y, a, b, y_ud = self.data_store.get_data(DataKeys.REGRESSION_PROPERTY)

        if RegressionMethod.LINEAR == regression_method:
            title = RegressionPlotConfig.GENERIC_LINEAR.value.format(symbol, a, b)
            y_fitted = a * x + b
        elif RegressionMethod.POWER_LAW == regression_method:
            # Ignore when the power law is not working
            if a is None:
                y_fitted = None
                title = RegressionPlotConfig.GENERIC_ERROR.value
            else:
                title = RegressionPlotConfig.GENERIC_POWER_LAW.value.format(symbol, a, b)
                y_fitted = a * np.power(x, b)
        elif RegressionMethod.LOGARITHMIC == regression_method:
            title = RegressionPlotConfig.GENERIC_LOGARITHMIC.value.format(symbol, a, b)
            y_fitted = a*np.log(x) + b
        else:
            title = ""
            y_fitted = np.zeros_like(y)

        return x, x_ud, y, y_fitted, y_label.format(y_ud), title

    def show_data(self) -> None:
        """
        Update shown data
        Returns
        -------

        """
        x, x_ud, y, y_fitted, y_label, title = self.extract_data()

        self.figure.clear()

        # Add centered axes
        ax = self.figure.add_axes(RegressionPlotConfig.ADD_AXES_ARG.value)

        # Set up background colors
        ax.set_facecolor(RegressionPlotConfig.BACKGROUND_COLOR.value)
        ax.tick_params(colors=RegressionPlotConfig.AXES_COLOR.value, which='both')
        ax.xaxis.label.set_color(RegressionPlotConfig.AXES_COLOR.value)
        ax.yaxis.label.set_color(RegressionPlotConfig.AXES_COLOR.value)
        ax.title.set_color(RegressionPlotConfig.AXES_COLOR.value)

        # Set tick counter (numbers) to white
        ax.spines['bottom'].set_color(RegressionPlotConfig.AXES_COLOR.value)
        ax.spines['left'].set_color(RegressionPlotConfig.AXES_COLOR.value)
        ax.spines['top'].set_color(RegressionPlotConfig.AXES_COLOR.value)
        ax.spines['right'].set_color(RegressionPlotConfig.AXES_COLOR.value)

        ax.plot(x,
                y,
                RegressionPlotConfig.DOT_SHAPE.value,
                color=RegressionPlotConfig.DOT_LINE_COLOR.value)

        if y_fitted is not None:
            ax.plot(x,
                    y_fitted,
                    RegressionPlotConfig.DOT_SHAPE.value,
                    color=RegressionPlotConfig.SOLID_LINE_COLOR.value)

        ax.legend(RegressionPlotConfig.LEGEND.value,
                  loc=RegressionPlotConfig.LEGEND_POSITION.value,
                  frameon=RegressionPlotConfig.LEGEND_FRAME.value,
                  labelcolor=RegressionPlotConfig.LEGEND_COLOR.value)

        ax.set_title(title)
        ax.set_xlabel(RegressionPlotConfig.TEMPERATURE_LABEL.value.format(x_ud))
        ax.set_ylabel(y_label)

        # Set properties for centering
        ax.set_position(RegressionPlotConfig.SET_POSITION_ARG.value)

        self.canvas.draw()
        self.canvas.updateGeometry()

    def run_regression(self) -> None:
        """
        Update shown data
        Returns
        -------

        """
        property_combo_box = self.find_widget(RegressionOutputPageComponents.PROPERTY)
        current_property = Properties(property_combo_box.currentText())
        property_ud_combo_box = self.find_widget(RegressionOutputPageComponents.PROPERTY_UD)
        self.data_store.update_data(DataKeys.REGRESSION_PROPERTY_TYPE, current_property)
        self.data_store.update_data(DataKeys.REGRESSION_PROPERTY, ([], property_ud_combo_box.currentText()))

        min_value = float(self.find_widget(RegressionOutputPageComponents.MIN_TEMPERATURE_INPUT).text())
        max_value = float(self.find_widget(RegressionOutputPageComponents.MAX_TEMPERATURE_INPUT).text())
        ud = self.find_widget(RegressionOutputPageComponents.TEMPERATURE_UD).currentText()

        self.data_store.update_data(DataKeys.MIN_TEMPERATURE, (min_value, ud))
        self.data_store.update_data(DataKeys.MAX_TEMPERATURE, (max_value, ud))

        regression_method = RegressionMethod(
            self.find_widget(RegressionOutputPageComponents.REGRESSION_METHOD).currentText())

        self.data_store.update_data(DataKeys.REGRESSION_METHOD, regression_method)
        self.data_store = regression_calculator(self.data_store)
        self.show_data()

        return None
