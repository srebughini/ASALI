from PyQt5 import uic

from src.config.app import AppConfig
from src.core.data_keys import DataKeys
from src.core.vacuum_calculator import vacuum_calculator
from src.gui.pages.basic_page import BasicPage
from src.gui.components.output.vacuum_page import VacuumOutputPageComponents


class VacuumOutputPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Vacuum properties output layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        uic.loadUi(AppConfig.VACUUM_OUTPUT_PAGE.value.path, self)

        self.update_buttons()
        self.update_head_lines()
        self.update_combo_boxes()
        self.update_edit_lines()
        self.set_custom_dimensions_to_grid_layout(self.find_widget(VacuumOutputPageComponents.GRID))

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.set_custom_dimensions_to_grid_layout(self.find_widget(VacuumOutputPageComponents.GRID))
        self.data_store.update_data(DataKeys.LAST_ACTIVE_WINDOW, AppConfig.VACUUM_OUTPUT_PAGE)

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        back_button = self.find_widget(VacuumOutputPageComponents.BACK_BUTTON)
        back_button.clicked.connect(lambda: self.page_switched.emit(AppConfig.VACUUM_INPUT_PAGE))

        calculate_button = self.find_widget(VacuumOutputPageComponents.UPDATE_BUTTON)
        calculate_button.clicked.connect(self.show_data)

    def update_head_lines(self) -> None:
        """
        Update head lines
        Returns
        -------

        """
        widget_enum = VacuumOutputPageComponents.HEADLINE
        label = self.find_widget(widget_enum)
        label.setAlignment(widget_enum.value.align)
        label.setProperty("class", widget_enum.value.style)

    def update_combo_boxes(self) -> None:
        """
        Update combo boxes
        Returns
        -------

        """
        for widget_enum in [VacuumOutputPageComponents.VELOCITY_UD,
                            VacuumOutputPageComponents.DIFFUSIVITY_UD,
                            VacuumOutputPageComponents.MEAN_FREE_PATH_UD]:
            widget = self.find_widget(widget_enum)
            widget.clear()
            widget.addItems(widget_enum.value.items)

    def update_edit_lines(self) -> None:
        """
        Update edit lines
        Returns
        -------

        """
        for widget_enum in [VacuumOutputPageComponents.VELOCITY_VALUE,
                            VacuumOutputPageComponents.DIFFUSIVITY_VALUE,
                            VacuumOutputPageComponents.MEAN_FREE_PATH_VALUE,
                            VacuumOutputPageComponents.KNUDSEN_VALUE]:
            widget = self.find_widget(widget_enum)
            widget.setText(widget_enum.value.text)
            widget.setAlignment(widget_enum.value.align)
            widget.setTextInteractionFlags(widget_enum.value.text_interaction)

    def read_data(self) -> None:
        """
        Update data store with properties unit dimensions
        Returns
        -------

        """
        for widget_enum in [VacuumOutputPageComponents.VELOCITY_UD,
                            VacuumOutputPageComponents.DIFFUSIVITY_UD,
                            VacuumOutputPageComponents.MEAN_FREE_PATH_UD]:
            widget = self.find_widget(widget_enum)
            ud = widget.currentText()
            self.data_store.update_data(widget_enum.value.data_key, (0.0, ud))

    def show_data(self) -> None:
        """
        Update shown data
        Returns
        -------

        """
        self.read_data()
        self.data_store = vacuum_calculator(self.data_store)

        for widget_enum in [VacuumOutputPageComponents.VELOCITY_VALUE,
                            VacuumOutputPageComponents.DIFFUSIVITY_VALUE,
                            VacuumOutputPageComponents.MEAN_FREE_PATH_VALUE]:
            text = self.data_store.get_data(widget_enum.value.data_key)[0]
            self.set_formatted_text_to_label(widget_enum, text)

        widget_enum = VacuumOutputPageComponents.KNUDSEN_VALUE
        text = self.data_store.get_data(widget_enum.value.data_key)
        self.set_formatted_text_to_label(widget_enum, text)

        self.set_custom_dimensions_to_grid_layout(self.find_widget(VacuumOutputPageComponents.GRID))

    # def update_property_line(self, value_label_name, combo_box_name, ud_list) -> None:
    #     """
    #     Update property output line
    #     Parameters
    #     ----------
    #     value_label_name: str
    #         Value label name
    #     combo_box_name: str | None
    #         Unit dimension combo box name
    #     ud_list: list | None
    #         Unit dimensions
    #
    #     Returns
    #     -------
    #
    #     """
    #     label = self.findChild(QLabel, value_label_name)
    #     label.setText(LabelFormatter.pad_string("0.0"))
    #     label.setAlignment(Qt.AlignVCenter)
    #     label.setTextInteractionFlags(Qt.TextSelectableByMouse)
    #
    #     if combo_box_name is not None:
    #         dropdown = self.findChild(QComboBox, combo_box_name)
    #         dropdown.addItems(ud_list)
    #         dropdown.currentIndexChanged.connect(self.update_shown_data)
    #
    # def update_property_value(self, value_label_name, value):
    #     """
    #     Update property value
    #     Parameters
    #     ----------
    #     value_label_name
    #     value
    #
    #     Returns
    #     -------
    #
    #     """
    #     if isinstance(value, float):
    #         label = self.findChild(QLabel, value_label_name)
    #         label.setText(LabelFormatter.float_to_string(value))
    #
    #     if isinstance(value, dict):
    #         label = self.findChild(QLabel, value_label_name)
    #         label.setText(LabelFormatter.dict_to_string(value))
    #
    # def update_buttons(self) -> None:
    #     """
    #     Update buttons
    #     Returns
    #     -------
    #
    #     """
    #     back_button = self.findChild(QPushButton, VacuumOutputPageWidgets.BACK_BUTTON.value)
    #     back_button.clicked.connect(lambda: self.page_switched.emit(CalculationInputPageConfig.NAME.value))
    #
    #     calculate_button = self.findChild(QPushButton, VacuumOutputPageWidgets.CALCULATE_BUTTON.value)
    #     calculate_button.clicked.connect(self.update_shown_data)
    #
    # def update_geometry_line(self) -> None:
    #     """
    #     Update geometry input line
    #     Returns
    #     -------
    #
    #     """
    #     edit_line = self.findChild(QLineEdit, VacuumOutputPageWidgets.GEOMETRY_EDIT_LINE.value)
    #     edit_line.setValidator(QDoubleValidator(0.0, 1e09, 20))
    #     edit_line.setAlignment(Qt.AlignRight)
    #
    #     dropdown = self.findChild(QComboBox, VacuumOutputPageWidgets.GEOMETRY_COMBO_BOX.value)
    #     dropdown.addItems(self.ud_handler.length_ud)
    #
    # def update_specie_line(self) -> None:
    #     """
    #     Update specie input line
    #     Returns
    #     -------
    #
    #     """
    #     dropdown = self.findChild(QComboBox, VacuumOutputPageWidgets.SPECIE_COMBO_BOX.value)
    #     specie_list = list(self.data_store.get_data(DataKeys.INLET_GAS_COMPOSITION)[0].keys())
    #     dropdown.clear()
    #     dropdown.addItems(specie_list)
    #
    # def update_head_lines(self) -> None:
    #     """
    #     Update head lines
    #     Returns
    #     -------
    #
    #     """
    #     for n in [VacuumOutputPageWidgets.INPUT_LABEL, VacuumOutputPageWidgets.OUTPUT_LABEL]:
    #         label = self.findChild(QLabel, n.value)
    #         label.setAlignment(Qt.AlignCenter)
    #         label.setProperty("class", "highlight")
    #
    # def read_data(self) -> None:
    #     """
    #     Update data store with temperature, composition, pressure
    #     Returns
    #     -------
    #
    #     """
    #     value = float(self.findChild(QLineEdit, VacuumOutputPageWidgets.GEOMETRY_EDIT_LINE.value).text())
    #     ud = self.findChild(QComboBox, VacuumOutputPageWidgets.GEOMETRY_COMBO_BOX.value).currentText()
    #     self.data_store.update_data(DataKeys.GEOMETRY, (value, ud))
    #
    #     self.data_store.update_data(DataKeys.VACUUM_SPECIE,
    #                                 self.findChild(QComboBox,
    #                                                VacuumOutputPageWidgets.SPECIE_COMBO_BOX.value).currentText())
    #
    #     self.data_store.update_data(DataKeys.L,
    #                                 (0.0, self.findChild(QComboBox,
    #                                                      VacuumOutputPageWidgets.LENGTH_COMBO_BOX.value).currentText()))
    #
    #     self.data_store.update_data(DataKeys.V,
    #                                 (0.0,
    #                                  self.findChild(QComboBox,
    #                                                 VacuumOutputPageWidgets.VELOCITY_COMBO_BOX.value).currentText()))
    #
    #     self.data_store.update_data(DataKeys.DIFF_MIX,
    #                                 (0.0,
    #                                  self.findChild(QComboBox,
    #                                                 VacuumOutputPageWidgets.DIFFUSIVITY_COMBO_BOX.value).currentText()))
    #
    #     self.data_store.update_data(DataKeys.KN, 0.0)
    #
    # def update_shown_data(self) -> None:
    #     """
    #     Update shown data
    #     Returns
    #     -------
    #
    #     """
    #     self.read_data()
    #     self.data_store = vacuum_calculator(self.data_store)
    #
    #     self.update_property_value(VacuumOutputPageWidgets.LENGTH_LABEL.value,
    #                                self.data_store.get_data(DataKeys.L)[0])
    #     self.update_property_value(VacuumOutputPageWidgets.VELOCITY_LABEL.value,
    #                                self.data_store.get_data(DataKeys.V)[0])
    #     self.update_property_value(VacuumOutputPageWidgets.DIFFUSIVITY_LABEL.value,
    #                                self.data_store.get_data(DataKeys.DIFF_MIX)[0])
    #     self.update_property_value(VacuumOutputPageWidgets.KNUDSEN_LABEL.value,
    #                                self.data_store.get_data(DataKeys.KN))
    #
    #     self.set_custom_dimensions_to_grid_layout()
