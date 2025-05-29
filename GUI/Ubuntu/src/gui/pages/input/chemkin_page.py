
from PyQt5 import uic

from src.config.app import AppConfig
from src.core.data_keys import DataKeys
from src.gui.components.input.chemkin_page import ChemkinInputPageComponents
from src.gui.enums.chemkin_editor_action import ChemkinEditorAction
from src.gui.pages.basic_page import BasicPage


class ChemkinInputPage(BasicPage):
    def __init__(self, data_store, dialog_handler):
        """
        Chemkin layout
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        """
        super().__init__(data_store, dialog_handler)
        # Load the UI from the .ui file
        uic.loadUi(AppConfig.CHEMKIN_INPUT_PAGE.value.path, self)
        #self.update_head_lines()
        self.update_combo_boxes()
        #self.update_buttons()
        #self.update_edit_lines()

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.set_custom_dimensions_to_grid_layout(self.find_widget(ChemkinInputPageComponents.GRID))
        self.data_store.update_data(DataKeys.LAST_ACTIVE_WINDOW, AppConfig.MAIN_INPUT_PAGE)
        self.update_page_based_on_action()

    def update_combo_boxes(self) -> None:
        """
        Update combo boxes
        Returns
        -------

        """
        action_box = self.find_widget(ChemkinInputPageComponents.ACTION)
        action_box.addItems(ChemkinInputPageComponents.ACTION.value.items)
        action_box.currentIndexChanged.connect(self.update_page_based_on_action)

    def update_page_based_on_action(self) -> None:
        """
        Update page layout based on the selected action
        Returns
        -------

        """
        action_combo_box = self.find_widget(ChemkinInputPageComponents.ACTION)
        selected_action = ChemkinEditorAction(action_combo_box.currentText())

        if ChemkinEditorAction.NONE == selected_action:
            for widget_enum in [ChemkinInputPageComponents.TRANSPORT_BUTTON,
                                ChemkinInputPageComponents.THERMO_BUTTON,
                                ChemkinInputPageComponents.SURFACE_BUTTON,
                                ChemkinInputPageComponents.KINETIC_BUTTON,
                                ChemkinInputPageComponents.THERMO_WIDGET,
                                ChemkinInputPageComponents.TRANSPORT_WIDGET]:
                widget = self.find_widget(widget_enum)
                widget.setVisible(False)
        elif ChemkinEditorAction.TO_CANTERA == selected_action:
            for widget_enum in [ChemkinInputPageComponents.THERMO_WIDGET,
                                ChemkinInputPageComponents.TRANSPORT_WIDGET]:
                widget = self.find_widget(widget_enum)
                widget.setVisible(False)

            for widget_enum in [ChemkinInputPageComponents.TRANSPORT_BUTTON,
                                ChemkinInputPageComponents.THERMO_BUTTON,
                                ChemkinInputPageComponents.SURFACE_BUTTON,
                                ChemkinInputPageComponents.KINETIC_BUTTON]:
                widget = self.find_widget(widget_enum)
                widget.setVisible(True)
        elif ChemkinEditorAction.ADD_THERMO == selected_action:
            for widget_enum in [ChemkinInputPageComponents.TRANSPORT_BUTTON,
                                ChemkinInputPageComponents.SURFACE_BUTTON,
                                ChemkinInputPageComponents.KINETIC_BUTTON,
                                ChemkinInputPageComponents.TRANSPORT_WIDGET]:
                widget = self.find_widget(widget_enum)
                widget.setVisible(False)

            for widget_enum in [ChemkinInputPageComponents.THERMO_BUTTON,
                                ChemkinInputPageComponents.THERMO_WIDGET]:
                widget = self.find_widget(widget_enum)
                widget.setVisible(True)
        elif ChemkinEditorAction.ADD_TRANSPORT == selected_action:
            for widget_enum in [ChemkinInputPageComponents.THERMO_BUTTON,
                                ChemkinInputPageComponents.SURFACE_BUTTON,
                                ChemkinInputPageComponents.KINETIC_BUTTON,
                                ChemkinInputPageComponents.THERMO_WIDGET]:
                widget = self.find_widget(widget_enum)
                widget.setVisible(False)

            for widget_enum in [ChemkinInputPageComponents.TRANSPORT_BUTTON,
                                ChemkinInputPageComponents.TRANSPORT_WIDGET]:
                widget = self.find_widget(widget_enum)
                widget.setVisible(True)


    #
    # def update_buttons(self) -> None:
    #     """
    #     Update buttons
    #     Returns
    #     -------
    #
    #     """
    #     back_button = self.find_widget(EquilibriumOutputPageComponents.BACK_BUTTON)
    #     back_button.clicked.connect(lambda: self.page_switched.emit(AppConfig.EQUILIBRIUM_INPUT_PAGE))
    #
    #     calculate_button = self.find_widget(EquilibriumOutputPageComponents.UPDATE_BUTTON)
    #     calculate_button.clicked.connect(self.show_data)
    #
    # def update_head_lines(self) -> None:
    #     """
    #     Update head lines
    #     Returns
    #     -------
    #
    #     """
    #     for widget_enum in [EquilibriumOutputPageComponents.HEADLINE]:
    #         label = self.find_widget(widget_enum)
    #         label.setAlignment(widget_enum.value.align)
    #         label.setProperty("class", widget_enum.value.style)
    #
    # def update_edit_lines(self) -> None:
    #     """
    #     Update edit lines
    #     Returns
    #     -------
    #
    #     """
    #     for widget_enum in [EquilibriumOutputPageComponents.TEMPERATURE,
    #                         EquilibriumOutputPageComponents.PRESSURE,
    #                         EquilibriumOutputPageComponents.MASS_FRACTION,
    #                         EquilibriumOutputPageComponents.MOLE_FRACTION,
    #                         EquilibriumOutputPageComponents.NAMES]:
    #         widget = self.find_widget(widget_enum)
    #         widget.setText(widget_enum.value.text)
    #         widget.setAlignment(widget_enum.value.align)
    #         widget.setTextInteractionFlags(widget_enum.value.text_interaction)

    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        pass
        """
        ud = self.find_widget(EquilibriumOutputPageComponents.TEMPERATURE_UD).currentText()
        self.data_store.update_data(DataKeys.EQ_TEMPERATURE, (0.0, ud))

        ud = self.find_widget(EquilibriumOutputPageComponents.PRESSURE_UD).currentText()
        self.data_store.update_data(DataKeys.EQ_PRESSURE, (0.0, ud))

        equilibrium_type = self.find_widget(EquilibriumOutputPageComponents.EQUILIBRIUM_TYPE).currentText()
        self.data_store.update_data(DataKeys.EQUILIBRIUM_TYPE, EquilibriumType(equilibrium_type))
        """

    def show_data(self) -> None:
        """
        Update shown data
        Returns
        -------

        """
        pass
        """
        self.read_data()
        self.data_store = equilibrium_calculator(self.data_store)

        for widget_enum, key in {EquilibriumOutputPageComponents.TEMPERATURE: DataKeys.EQ_TEMPERATURE,
                                 EquilibriumOutputPageComponents.PRESSURE: DataKeys.EQ_PRESSURE,
                                 EquilibriumOutputPageComponents.MOLE_FRACTION: DataKeys.EQ_MOLE_FRACTION,
                                 EquilibriumOutputPageComponents.MASS_FRACTION: DataKeys.EQ_MASS_FRACTION,
                                 EquilibriumOutputPageComponents.NAMES: DataKeys.EQ_SPECIE_NAMES}.items():
            widget = self.find_widget(widget_enum)
            data = self.data_store.get_data(key)
            if isinstance(data, list):
                widget.setText(LabelFormatter.list_to_string(data))
            elif isinstance(data, tuple):
                widget.setText(LabelFormatter.float_to_string(data[0]))
            else:
                widget.setText(LabelFormatter.float_to_string(data))

        self.set_custom_dimensions_to_grid_layout(self.find_widget(EquilibriumOutputPageComponents.GRID))
        """
