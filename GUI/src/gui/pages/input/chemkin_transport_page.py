from PySide6.QtWidgets import QLabel

from src.config.app import AppConfig
from src.controllers.chemkin_file_controller import ChemkinFileController
from src.core.data_keys import DataKeys
from src.gui.components.input.chemkin_transport_page import ChemkinTransportInputPageComponents
from src.gui.enums.chemkin_editor_action import ChemkinEditorAction
from src.gui.pages.basic_page import BasicPage


class ChemkinTransportInputPage(BasicPage):
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
        self.load_ui(AppConfig.CHEMKIN_TRANSPORT_INPUT_PAGE.value.path)
        self.update_combo_boxes()
        self.update_buttons()
        self.update_edit_lines()

    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        self.data_store.update_data(DataKeys.LAST_ACTIVE_WINDOW, AppConfig.MAIN_INPUT_PAGE)
        self.set_custom_dimensions_to_vertical_layout(self.find_widget(ChemkinTransportInputPageComponents.VBOX))

        action_box = self.find_widget(ChemkinTransportInputPageComponents.ACTION)
        action_box.setCurrentText(ChemkinEditorAction.TRANSPORT.value)

        self.data_store.update_data(DataKeys.TRANSPORT_FILE_PATH, "")

    def update_combo_boxes(self) -> None:
        """
        Update combo boxes
        Returns
        -------

        """
        action_box = self.find_widget(ChemkinTransportInputPageComponents.ACTION)
        action_box.addItems(ChemkinTransportInputPageComponents.ACTION.value.items)
        action_box.currentIndexChanged.connect(self.update_page_based_on_action)

    def update_buttons(self) -> None:
        """
        Update buttons
        Returns
        -------

        """
        back_button = self.find_widget(ChemkinTransportInputPageComponents.BACK_BUTTON)
        back_button.clicked.connect(lambda: self.switch_to_page.emit(AppConfig.MAIN_INPUT_PAGE))

        calculate_button = self.find_widget(ChemkinTransportInputPageComponents.RUN_BUTTON)
        calculate_button.clicked.connect(self.save_file)

        transport_button = self.find_widget(ChemkinTransportInputPageComponents.TRANSPORT_BUTTON)
        transport_button.clicked.connect(self.load_transport_file)

    def update_edit_lines(self) -> None:
        """
        Update edit lines
        Returns
        -------

        """
        for w in [ChemkinTransportInputPageComponents.GEOMETRY_EDIT_LINE,
                  ChemkinTransportInputPageComponents.COLLISION_EDIT_LINE,
                  ChemkinTransportInputPageComponents.DIPOLE_EDIT_LINE,
                  ChemkinTransportInputPageComponents.LJ_DIAMETER_EDIT_LINE,
                  ChemkinTransportInputPageComponents.LJ_POTENTIAL_EDIT_LINE,
                  ChemkinTransportInputPageComponents.COLLISION_EDIT_LINE,
                  ChemkinTransportInputPageComponents.POLAR_EDIT_LINE]:
            edit_line = self.find_widget(w)
            edit_line.setValidator(w.value.validator)
            edit_line.setAlignment(w.value.alignment)
            edit_line.setText(w.value.text)

        w = ChemkinTransportInputPageComponents.NAME_TRANSPORT_EDIT_LINE
        edit_line = self.find_widget(w)
        edit_line.setAlignment(w.value.alignment)

    def update_page_based_on_action(self) -> None:
        """
        Update page layout based on the selected action
        Returns
        -------

        """
        action_combo_box = self.find_widget(ChemkinTransportInputPageComponents.ACTION)
        selected_action = ChemkinEditorAction(action_combo_box.currentText())

        if ChemkinEditorAction.CONVERTER == selected_action:
            return self.switch_to_page.emit(AppConfig.CHEMKIN_CONVERTER_INPUT_PAGE)

        if ChemkinEditorAction.THERMO == selected_action:
            return self.switch_to_page.emit(AppConfig.CHEMKIN_THERMO_INPUT_PAGE)

    def load_transport_file(self) -> None:
        """
        Load transport file of Chemkin chemistry model
        Returns
        -------

        """
        file_path = self.dialog_handler.load_file(AppConfig.CHEMKIN_TRANSPORT_FILE_HEADLINE.value,
                                                  AppConfig.CHEMKIN_TRANSPORT_FILE_TYPE.value)

        if file_path:
            self.data_store.update_data(DataKeys.TRANSPORT_FILE_PATH, file_path)
        else:
            self.data_store.update_data(DataKeys.TRANSPORT_FILE_PATH, "")

    def read_data(self) -> list:
        """
        Read transport data
        Returns
        -------
        data_list: list
            Transport data as list [name,geometry,LJpotential, LJdiameter, dipole, polar, collision]
        """
        return [self.find_widget(w).text() for w in [ChemkinTransportInputPageComponents.NAME_TRANSPORT_EDIT_LINE,
                                                     ChemkinTransportInputPageComponents.GEOMETRY_EDIT_LINE,
                                                     ChemkinTransportInputPageComponents.LJ_POTENTIAL_EDIT_LINE,
                                                     ChemkinTransportInputPageComponents.LJ_DIAMETER_EDIT_LINE,
                                                     ChemkinTransportInputPageComponents.DIPOLE_EDIT_LINE,
                                                     ChemkinTransportInputPageComponents.POLAR_EDIT_LINE,
                                                     ChemkinTransportInputPageComponents.COLLISION_EDIT_LINE]]

    def save_file(self) -> None:
        """
        Update shown data
        Returns
        -------

        """
        data_list = self.read_data()

        output_file_path = self.data_store.get_data(DataKeys.TRANSPORT_FILE_PATH)

        if len(output_file_path) == 0:
            answer = self.dialog_handler.question_message(QLabel("Transport file is missing!\nDo you want to load it?"))
            if answer:
                self.load_transport_file()
                output_file_path = self.data_store.get_data(DataKeys.TRANSPORT_FILE_PATH)
            else:
                return None

        if output_file_path is not None:
            try:
                ChemkinFileController.update_transport_file(output_file_path, data_list)
            except Exception as e:
                raise Exception(e)
            else:
                self.dialog_handler.done_message(QLabel("Transport file updated!"))

        return None
