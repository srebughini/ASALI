from src.config.app import AppConfig
from src.controllers.label_formatter import LabelFormatter
from src.core.data_keys import DataKeys
from src.core.pressure_drops_calculator import pressure_drops_calculator
from src.gui.components.output.pressure_drops_page import PressureDropsOutputPageComponents
from src.gui.enums.reactor_type import ReactorType
from src.gui.pages.basic_page import BasicPage


class PressureDropsOutputPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Pressure drops output layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        self.load_ui(AppConfig.PRESSURE_DROPS_OUTPUT_PAGE.value.path)
        self.update_head_lines()
        self.update_combo_boxes()
        self.update_buttons()
        self.update_edit_lines()

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.set_custom_dimensions_to_grid_layout(self.find_widget(PressureDropsOutputPageComponents.GRID))
        self.data_store.update_data(DataKeys.LAST_ACTIVE_WINDOW, AppConfig.PRESSURE_DROPS_OUTPUT_PAGE)
        self.reactor_selection_handler()

    def update_combo_boxes(self) -> None:
        """
        Update combo boxes
        Returns
        -------

        """
        for widget_enum in [PressureDropsOutputPageComponents.VELOCITY_UD,
                            PressureDropsOutputPageComponents.LENGTH_UD,
                            PressureDropsOutputPageComponents.WALL_THICKNESS_UD,
                            PressureDropsOutputPageComponents.TUBE_DIAMETER_UD,
                            PressureDropsOutputPageComponents.PARTICLE_DIAMETER_UD,
                            PressureDropsOutputPageComponents.PRESSURE_DROPS_UD,
                            PressureDropsOutputPageComponents.REACTOR_TYPE]:
            widget = self.find_widget(widget_enum)
            widget.addItems(widget_enum.value.items)
            if PressureDropsOutputPageComponents.REACTOR_TYPE == widget_enum:
                widget.currentIndexChanged.connect(self.reactor_selection_handler)

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        back_button = self.find_widget(PressureDropsOutputPageComponents.BACK_BUTTON)
        back_button.clicked.connect(lambda: self.switch_to_page.emit(AppConfig.PRESSURE_DROPS_INPUT_PAGE))

        calculate_button = self.find_widget(PressureDropsOutputPageComponents.UPDATE_BUTTON)
        calculate_button.clicked.connect(self.show_data)

    def update_head_lines(self) -> None:
        """
        Update head lines
        Returns
        -------

        """
        for widget_enum in [PressureDropsOutputPageComponents.HEADLINE]:
            label = self.find_widget(widget_enum)
            label.setAlignment(widget_enum.value.align)
            label.setProperty("class", widget_enum.value.style)

    def update_edit_lines(self) -> None:
        """
        Update edit lines
        Returns
        -------

        """
        for widget_enum in [PressureDropsOutputPageComponents.LENGTH,
                            PressureDropsOutputPageComponents.VELOCITY,
                            PressureDropsOutputPageComponents.TUBE_DIAMETER,
                            PressureDropsOutputPageComponents.PARTICLE_DIAMETER,
                            PressureDropsOutputPageComponents.CPSI,
                            PressureDropsOutputPageComponents.VOID_FRACTION,
                            PressureDropsOutputPageComponents.WALL_THICKNESS]:
            widget = self.find_widget(widget_enum)
            widget.setValidator(widget_enum.value.validator)
            widget.setAlignment(widget_enum.value.align)

    def wall_thickness_handler(self, reactor_type) -> None:
        """
        Disable/enable wall thickness based on reactor selection
        Returns
        -------

        """
        label = self.find_widget(PressureDropsOutputPageComponents.WALL_THICKNESS_LABEL)
        value = self.find_widget(PressureDropsOutputPageComponents.WALL_THICKNESS)
        ud = self.find_widget(PressureDropsOutputPageComponents.WALL_THICKNESS_UD)
        if ReactorType.PACKED_BED == reactor_type:
            self.disable_widget(label)
            self.disable_widget(value)
            self.disable_widget(ud)
        else:
            self.enable_widget(label)
            self.enable_widget(value)
            self.enable_widget(ud)

    def cpsi_handler(self, reactor_type) -> None:
        """
        Disable/enable CPSI based on reactor selection
        Returns
        -------

        """
        label = self.find_widget(PressureDropsOutputPageComponents.CPSI_LABEL)
        value = self.find_widget(PressureDropsOutputPageComponents.CPSI)
        if ReactorType.HONEYCOMB == reactor_type:
            self.enable_widget(label)
            self.enable_widget(value)
        else:
            self.disable_widget(label)
            self.disable_widget(value)

    def void_fraction_handler(self, reactor_type) -> None:
        """
        Disable/enable void fraction based on reactor selection
        Returns
        -------

        """
        label = self.find_widget(PressureDropsOutputPageComponents.VOID_FRACTION_LABEL)
        value = self.find_widget(PressureDropsOutputPageComponents.VOID_FRACTION)
        if ReactorType.PACKED_BED == reactor_type:
            self.enable_widget(label)
            self.enable_widget(value)
        else:
            self.disable_widget(label)
            self.disable_widget(value)

    def tube_diameter_handler(self, reactor_type) -> None:
        """
        Disable/enable tube diameter based on reactor selection
        Returns
        -------

        """
        label = self.find_widget(PressureDropsOutputPageComponents.TUBE_DIAMETER_LABEL)
        value = self.find_widget(PressureDropsOutputPageComponents.TUBE_DIAMETER)
        ud = self.find_widget(PressureDropsOutputPageComponents.TUBE_DIAMETER_UD)
        if ReactorType.HONEYCOMB == reactor_type:
            self.disable_widget(label)
            self.disable_widget(value)
            self.disable_widget(ud)
        else:
            self.enable_widget(label)
            self.enable_widget(value)
            self.enable_widget(ud)

    def particle_diameter_handler(self, reactor_type) -> None:
        """
        Disable/enable tube diameter based on reactor selection
        Returns
        -------

        """
        label = self.find_widget(PressureDropsOutputPageComponents.PARTICLE_DIAMETER_LABEL)
        value = self.find_widget(PressureDropsOutputPageComponents.PARTICLE_DIAMETER)
        ud = self.find_widget(PressureDropsOutputPageComponents.PARTICLE_DIAMETER_UD)
        if ReactorType.PACKED_BED == reactor_type:
            self.enable_widget(label)
            self.enable_widget(value)
            self.enable_widget(ud)
        else:
            self.disable_widget(label)
            self.disable_widget(value)
            self.disable_widget(ud)

    def reactor_selection_handler(self) -> None:
        """
        Disable or enable widgets based on reactor selection
        Returns
        -------

        """
        reactor_type = ReactorType(self.find_widget(PressureDropsOutputPageComponents.REACTOR_TYPE).currentText())
        self.wall_thickness_handler(reactor_type)
        self.tube_diameter_handler(reactor_type)
        self.particle_diameter_handler(reactor_type)
        self.cpsi_handler(reactor_type)
        self.void_fraction_handler(reactor_type)

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        reactor_type = ReactorType(self.find_widget(PressureDropsOutputPageComponents.REACTOR_TYPE).currentText())

        self.data_store.update_data(DataKeys.REACTOR_TYPE, reactor_type)

        for key, (w_value, w_ud) in {DataKeys.DP_WALL_THICKNESS: (PressureDropsOutputPageComponents.WALL_THICKNESS,
                                                                  PressureDropsOutputPageComponents.WALL_THICKNESS_UD),
                                     DataKeys.DP_LENGTH: (PressureDropsOutputPageComponents.LENGTH,
                                                          PressureDropsOutputPageComponents.LENGTH_UD),
                                     DataKeys.DP_VELOCITY: (PressureDropsOutputPageComponents.VELOCITY,
                                                            PressureDropsOutputPageComponents.VELOCITY_UD),
                                     DataKeys.DP_TUBE_DIAMETER: (PressureDropsOutputPageComponents.TUBE_DIAMETER,
                                                                 PressureDropsOutputPageComponents.TUBE_DIAMETER_UD),
                                     DataKeys.DP_PARTICLE_DIAMETER: (
                                             PressureDropsOutputPageComponents.PARTICLE_DIAMETER,
                                             PressureDropsOutputPageComponents.PARTICLE_DIAMETER_UD)}.items():
            value = self.find_widget(w_value).text()
            ud = self.find_widget(w_ud).currentText()
            self.data_store.update_data(key, (float(value), ud))

        self.data_store.update_data(DataKeys.DP_CPSI,
                                    int(self.find_widget(PressureDropsOutputPageComponents.CPSI).text()))
        self.data_store.update_data(DataKeys.DP_VOID_FRACTION,
                                    float(self.find_widget(PressureDropsOutputPageComponents.VOID_FRACTION).text()))

        ud = self.find_widget(PressureDropsOutputPageComponents.PRESSURE_DROPS_UD).currentText()
        self.data_store.update_data(DataKeys.PRESSURE_DROPS, (0.0, ud))

    def show_data(self) -> None:
        """
        Update shown data
        Returns
        -------

        """
        self.read_data()
        self.data_store = pressure_drops_calculator(self.data_store)

        widget = self.find_widget(PressureDropsOutputPageComponents.PRESSURE_DROPS)
        widget.setText(LabelFormatter.float_to_string(self.data_store.get_data(DataKeys.PRESSURE_DROPS)[0]))

        self.set_custom_dimensions_to_grid_layout(self.find_widget(PressureDropsOutputPageComponents.GRID))
