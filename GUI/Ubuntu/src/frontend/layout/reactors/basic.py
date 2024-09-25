from abc import abstractmethod

from PyQt5.QtCore import Qt
from PyQt5.QtGui import QDoubleValidator, QIntValidator
from PyQt5.QtWidgets import (
    QMainWindow, QLabel
)

from src.backend.reactors.parser import ReactorParser
from src.frontend.layout.basic import BasicLayout
from src.frontend.style import FileType, WidgetStyle
from src.frontend.utils import Utils

import numpy as np


class BasicReactorLayout(BasicLayout):
    def __init__(self, main_window):
        """
        Reactor selection layout
        Parameters
        ----------
        main_window: QMainWindow
            Window where the layout should be applied
        """
        self._empty_label = Utils.pad_string("")

        self._select_reactor_list = [
            Utils.pad_string("...Select reactor model..."),
            Utils.pad_string("Batch reactor"),  # 1
            Utils.pad_string("Continuous stirred tank reactor"),  # 2
            Utils.pad_string("Steady state 1D pseudo-homogeneous reactor"),  # 3
            Utils.pad_string("Transient 1D pseudo-homogeneous reactor"),  # 4
            Utils.pad_string("Steady state 1D heterogeneous reactor"),  # 5
            Utils.pad_string("Transient 1D heterogeneous reactor")]  # 6

        self._reactor_type_list = [
            Utils.pad_string("...Select reactor type..."),
            Utils.pad_string("Packed bed reactor"),  # 1
            Utils.pad_string("Honeycomb reactor"),  # 2
            Utils.pad_string("Tubular reactor")]  # 3

        self._on_off_list = [Utils.pad_string("ON"), Utils.pad_string("OFF")]

        self.runButtonText = Utils.pad_string_center("Run model")
        self.runButtonToolTip = "Run reactor model"

        self.udkButtonText = Utils.pad_string_center("Load")
        self.udkButtonToolTip = "Load ASALI kinetic model"

        self.addCoverageButtonText = Utils.pad_string_center("Add coverage")
        self.addCoverageToolTip = "Add coverage specie input"

        self.addSpecieButtonText = Utils.pad_string_center("Add specie")
        self.addSpecieToolTip = "Add initial specie input"

        self._coverage_names_idx = list()
        self._coverage_composition_idx = list()

        self._specie_names_idx = list()
        self._specie_composition_idx = list()

        self._sub_grid_width = 3

        self._reactor_properties_col_idx = 0
        self._solving_options_col_idx = 0
        self._coverage_col_idx = 0
        self._initial_conditions_col_idx = 0
        self._solid_properties_col_idx = 0
        self._coverage_row_idx = 0
        self._initial_species_row_idx = 0
        self._reactor_type_first_row_idx = 0
        self._reactor_type_final_row_idx = 0
        self.reactor_model_function = None
        self.reactor_model_class = None

        super().__init__(main_window)
        self.main_window.backend_frontend_manager.reactor_parser = ReactorParser()

    def _update_layout(self) -> None:
        """
        Update layout based on reactor selection
        Returns
        -------

        """
        if self.reactorDropDown.currentIndex() == 0:
            self.main_window.update_to_basic()
        elif self.reactorDropDown.currentIndex() == 1:
            self.main_window.update_to_batch_reactor()
        elif self.reactorDropDown.currentIndex() == 2:
            self.main_window.update_to_cstr_reactor()
        elif self.reactorDropDown.currentIndex() == 3:
            self.main_window.update_to_ph1d_steady_state_reactor()
        elif self.reactorDropDown.currentIndex() == 4:
            self.main_window.update_to_ph1d_transient_reactor()
        elif self.reactorDropDown.currentIndex() == 5:
            self.main_window.update_to_het1d_steady_state_reactor()
        elif self.reactorDropDown.currentIndex() == 6:
            pass
            # self.main_window.updateToTransientHet1dReactor()

    def _update_layout_with_coverage_line(self) -> None:
        """
        Update the layout by adding coverage input line
        Returns
        -------

        """
        if self._coverage_row_idx < self.row_idx:
            self._add_coverage_input_line()
        else:
            self._remove_buttons(self.row_idx)
            self._add_coverage_input_line()
            self.row_idx = self.row_idx + 1
            self._add_buttons(self.row_idx)

    def _update_layout_with_specie_line(self) -> None:
        """
        Update the layout by adding specie input line
        Returns
        -------

        """
        if self._initial_species_row_idx < self.row_idx:
            self._add_initial_species_input_line()
        else:
            self._remove_buttons(self.row_idx)
            self._add_initial_species_input_line()
            self.row_idx = self.row_idx + 1
            self._add_buttons(self.row_idx)

    def _update_layout_with_reactor_type_line(self) -> None:
        """
        Update the layout by adding reactor type layout
        Returns
        -------

        """
        self._remove_buttons(self.row_idx)

        if self._reactor_type_first_row_idx < self._reactor_type_final_row_idx:
            # TODO - Remove specif widget of the reactor type (known the previous option)
            for row_idx in range(self._reactor_type_first_row_idx, self._reactor_type_final_row_idx + 1):
                self._remove_widget(row_idx, self._reactor_properties_col_idx)

        self._add_reactor_type_input_lines()
        self.row_idx = max(self.row_idx, self._reactor_type_final_row_idx) + 1
        self._add_buttons(self.row_idx)




    def _create_reactor_selection_dropdown(self) -> None:
        """
        Create reactor selection drop down menu
        Returns
        -------

        """
        self.reactorDropDown = self._create_dropdown(self._select_reactor_list,
                                                     function=self._update_layout)

    def _create_udk_label(self) -> None:
        """
        Create user defined kinetic label
        Returns
        -------

        """
        self.udkLoadLabel = QLabel(Utils.pad_string("Not loaded"))
        self.udkLoadLabel.setStyleSheet(WidgetStyle.ITALICLABEL.value)
        self.udkLoadLabel.setAlignment(Qt.AlignCenter)

    def _create_options_labels(self) -> None:
        """
        Create options labels
        Returns
        -------
        """
        self.solvingOptionLabel = QLabel(Utils.pad_string("Solving options"))
        self.solvingOptionLabel.setStyleSheet(WidgetStyle.ITALICLABEL.value)
        self.solvingOptionLabel.setAlignment(Qt.AlignCenter)

        self.reactorPropertiesLabel = QLabel(Utils.pad_string("Reactor properties"))
        self.reactorPropertiesLabel.setStyleSheet(WidgetStyle.ITALICLABEL.value)
        self.reactorPropertiesLabel.setAlignment(Qt.AlignCenter)

        self.initialConditionsLabel = QLabel(Utils.pad_string("Initial conditions"))
        self.initialConditionsLabel.setStyleSheet(WidgetStyle.ITALICLABEL.value)
        self.initialConditionsLabel.setAlignment(Qt.AlignCenter)

        self.coverageLabel = QLabel(Utils.pad_string("Coverage composition"))
        self.coverageLabel.setStyleSheet(WidgetStyle.ITALICLABEL.value)
        self.coverageLabel.setAlignment(Qt.AlignCenter)

    def _create_volume_input_line(self) -> None:
        """
        Create volume widgets
        Returns
        -------

        """
        self.volumeDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.ud_handler.volume_ud])
        self.volumeEditLine = self._create_line_edit("10.0", Qt.AlignRight, QDoubleValidator())

    def _create_diameter_input_line(self) -> None:
        """
        Create diameter widgets
        Returns
        -------

        """
        self.diameterDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.ud_handler.length_ud])
        self.diameterEditLine = self._create_line_edit("0.01", Qt.AlignRight, QDoubleValidator())

    def _create_particle_diameter_input_line(self) -> None:
        """
        Create particle diameter widgets
        Returns
        -------

        """
        self.particleDiameterDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.ud_handler.length_ud])
        self.particleDiameterEditLine = self._create_line_edit("0.01", Qt.AlignRight, QDoubleValidator())

    def _create_wall_thickness_input_line(self) -> None:
        """
        Create wall thickness widgets
        Returns
        -------

        """
        self.wallThicknessDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.ud_handler.length_ud])
        self.wallThicknessEditLine = self._create_line_edit("0.01", Qt.AlignRight, QDoubleValidator())

    def _create_reactor_length_input_line(self) -> None:
        """
        Create length widgets
        Returns
        -------

        """
        self.lengthDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.ud_handler.length_ud])
        self.lengthEditLine = self._create_line_edit("2.5", Qt.AlignRight, QDoubleValidator())

    def _create_reactor_type_dropdown(self) -> None:
        """
        Create reactor type drop down menu
        Returns
        -------

        """
        self.reactorTypeDropDown = self._create_dropdown(self._reactor_type_list,
                                                         function=self._update_layout_with_reactor_type_line)

    def _create_catalytic_load_input_line(self) -> None:
        """
        Create catalytic load widgets
        Returns
        -------

        """
        self.alfaDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.ud_handler.one_over_length_ud])
        self.alfaEditLine = self._create_line_edit("15.0", Qt.AlignRight, QDoubleValidator())

    def _create_energy_balance_input_line(self) -> None:
        """
        Create energy balance widgets
        Returns
        -------

        """
        self.energyDropDown = self._create_dropdown(self._on_off_list)

    def _create_diffusion_input_line(self) -> None:
        """
        Create diffusion widgets
        Returns
        -------

        """
        self.diffusionDropDown = self._create_dropdown(self._on_off_list)

    def _create_void_fraction_input_line(self) -> None:
        """
        Create void fraction widgets
        Returns
        -------

        """
        self.voidFractionEditLine = self._create_line_edit("0.42", Qt.AlignRight, QDoubleValidator())

    def _create_cpsi_input_line(self) -> None:
        """
        Create cpsi widgets
        Returns
        -------

        """
        self.cpsiEditLine = self._create_line_edit("400", Qt.AlignRight, QIntValidator())

    def _create_inert_specie_input_line(self) -> None:
        """
        Create inert specie widgets
        Returns
        -------

        """
        self.inertSpecieEditLine = self._create_line_edit("AR", Qt.AlignRight, None)

    def _create_inert_coverage_input_line(self) -> None:
        """
        Create inert coverage widgets
        Returns
        -------

        """
        self.inertCoverageEditLine = self._create_line_edit("Rh(s)", Qt.AlignRight, None)

    def _create_integration_time_input_line(self) -> None:
        """
        Create integration time widgets
        Returns
        -------

        """
        self.timeDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.ud_handler.time_ud])
        self.timeEditLine = self._create_line_edit("5", Qt.AlignRight, QDoubleValidator())

    def _create_time_step_input_line(self) -> None:
        """
        Create time step widgets
        Returns
        -------

        """
        self.timeStepDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.ud_handler.time_ud])
        self.timeStepEditLine = self._create_line_edit("0.5", Qt.AlignRight, QDoubleValidator())

    def _create_reactor_length_step_input_line(self) -> None:
        """
        Create length step widgets
        Returns
        -------

        """
        self.lengthStepDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.ud_handler.length_ud])
        self.lengthStepEditLine = self._create_line_edit("0.005", Qt.AlignRight, QDoubleValidator())

    def _create_mass_flow_rate_input_line(self) -> None:
        """
        Create mass flow rate widgets
        Returns
        -------

        """
        self.massFlowRateDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.ud_handler.mass_flow_rate_ud])
        self.massFlowRateEditLine = self._create_line_edit("1.0", Qt.AlignRight, QDoubleValidator())

    def _create_initial_temperature_input_line(self) -> None:
        """
        Create initial temperature widgets
        Returns
        -------

        """
        self.initialTemperatureDropDown = self._create_dropdown(
            [Utils.pad_string(ud) for ud in self.main_window.ud_handler.temperature_ud])
        self.initialTemperatureEditLine = self._create_line_edit("298.15", Qt.AlignRight, QDoubleValidator())

    def _create_composition_type_input_line(self) -> None:
        """
        Create composition type widgets
        Returns
        -------

        """
        self.compositionUdDropDown = self._create_dropdown(self.main_window.ud_handler.composition_ud, function=None)

    def _create_headline_label(self, text) -> None:
        """
        Create headline lable
        Parameters
        ----------
        text: str
            Text to be added to the label

        Returns
        -------

        """
        self.headlineLabel = QLabel(text)
        self.headlineLabel.setStyleSheet(WidgetStyle.HIGHLIGHTLABEL.value)
        self.headlineLabel.setAlignment(Qt.AlignCenter)

    def _add_volume_input_line(self, row_idx, col_idx) -> None:
        """
        Add volume input line
        Parameters
        ----------
        row_idx: int
            Row index
        col_idx: int
            Col index

        Returns
        -------
        """
        self.addWidget(QLabel(Utils.pad_string("Volume:")), row_idx, col_idx)
        self.addWidget(self.volumeEditLine, row_idx, col_idx + 1)
        self.addWidget(self.volumeDropDown, row_idx, col_idx + 2)

    def _add_diameter_input_line(self, row_idx, col_idx) -> None:
        """
        Add diameter input line
        Parameters
        ----------
        row_idx: int
            Row index
        col_idx: int
            Col index

        Returns
        -------
        """
        self.addWidget(QLabel(Utils.pad_string("Diameter:")), row_idx, col_idx)
        self.addWidget(self.diameterEditLine, row_idx, col_idx + 1)
        self.addWidget(self.diameterDropDown, row_idx, col_idx + 2)

    def _add_reactor_length_input_line(self, row_idx, col_idx) -> None:
        """
        Add reactor length input line
        Parameters
        ----------
        row_idx: int
            Row index
        col_idx: int
            Col index

        Returns
        -------
        """
        self.addWidget(QLabel(Utils.pad_string("Length:")), row_idx, col_idx)
        self.addWidget(self.lengthEditLine, row_idx, col_idx + 1)
        self.addWidget(self.lengthDropDown, row_idx, col_idx + 2)

    def _add_particle_diameter_input_line(self, row_idx, col_idx) -> None:
        """
        Add particle diameter input line
        Parameters
        ----------
        row_idx: int
            Row index
        col_idx: int
            Col index

        Returns
        -------
        """
        self.addWidget(QLabel(Utils.pad_string("Particle diameter:")), row_idx, col_idx)
        self.addWidget(self.particleDiameterEditLine, row_idx, col_idx + 1)
        self.addWidget(self.particleDiameterDropDown, row_idx, col_idx + 2)

    def _add_wall_thickness_input_line(self, row_idx, col_idx) -> None:
        """
        Add wall thickness input line
        Parameters
        ----------
        row_idx: int
            Row index
        col_idx: int
            Col index

        Returns
        -------
        """
        self.addWidget(QLabel(Utils.pad_string("Wall thickness:")), row_idx, col_idx)
        self.addWidget(self.wallThicknessEditLine, row_idx, col_idx + 1)
        self.addWidget(self.wallThicknessDropDown, row_idx, col_idx + 2)

    def _add_reactor_type_dropdown(self, row_idx, col_idx) -> None:
        """
        Add reactor type drop down
        Parameters
        ----------
        row_idx: int
            Row index
        col_idx: int
            Col index

        Returns
        -------
        """
        self.addWidget(QLabel(Utils.pad_string("Reactor type:")), row_idx, col_idx)
        self.addWidget(self.reactorTypeDropDown, row_idx, col_idx + 1, 1, 2)

    def _add_udk_input_line(self, row_idx, col_idx) -> None:
        """
        Add user defined kinetic input line
        Parameters
        ----------
        row_idx: int
            Row index
        col_idx: int
            Col index

        Returns
        -------

        """
        self.addWidget(QLabel("ASALI kinetic model:"), row_idx, col_idx)
        self.addWidget(self.udkLoadLabel, row_idx, col_idx + 1)
        self.addWidget(self._create_button(self.udkButtonText,
                                           self._load_udk_model,
                                           self.udkButtonToolTip), row_idx, col_idx + 2)

    def _add_input_composition_label_line(self, row_idx, col_idx) -> None:
        """
        Add input composition species/coverage label line
        Parameters
        ----------
        row_idx: int
            Row index
        col_idx: int
            Col index

        Returns
        -------

        """
        self.addWidget(QLabel(Utils.pad_string("Chemical formula")), row_idx, col_idx + 1)
        self.addWidget(QLabel(Utils.pad_string("Composition")), row_idx, col_idx + 2)

    def _add_catalytic_load_input_line(self, row_idx, col_idx) -> None:
        """
        Add catalytic input line
        Parameters
        ----------
        row_idx: int
            Row index
        col_idx: int
            Col index

        Returns
        -------
        """
        self.addWidget(QLabel(Utils.pad_string("Catalytic load:")), row_idx, col_idx)
        self.addWidget(self.alfaEditLine, row_idx, col_idx + 1)
        self.addWidget(self.alfaDropDown, row_idx, col_idx + 2)

    def _add_energy_balance_input_line(self, row_idx, col_idx) -> None:
        """
        Add energy balance input line
        Parameters
        ----------
        row_idx: int
            Row index
        col_idx: int
            Col index

        Returns
        -------

        """
        self.addWidget(QLabel(Utils.pad_string("Energy balance:")), row_idx, col_idx)
        self.addWidget(self.energyDropDown, row_idx, col_idx + 1, 1, 2)

    def _add_diffusion_input_line(self, row_idx, col_idx) -> None:
        """
        Add diffusion input line
        Parameters
        ----------
        row_idx: int
            Row index
        col_idx: int
            Col index

        Returns
        -------

        """
        self.addWidget(QLabel(Utils.pad_string("Diffusion:")), row_idx, col_idx)
        self.addWidget(self.diffusionDropDown, row_idx, col_idx + 1, 1, 2)

    def _add_void_fraction_input_line(self, row_idx, col_idx) -> None:
        """
        Add void fraction input line
        Parameters
        ----------
        row_idx: int
            Row index
        col_idx: int
            Col index

        Returns
        -------

        """
        self.addWidget(QLabel(Utils.pad_string("Void fraction:")), row_idx, col_idx)
        self.addWidget(self.voidFractionEditLine, row_idx, col_idx + 1, 1, 2)

    def _add_cpsi_input_line(self, row_idx, col_idx) -> None:
        """
        Add cpsi input line
        Parameters
        ----------
        row_idx: int
            Row index
        col_idx: int
            Col index

        Returns
        -------

        """
        self.addWidget(QLabel(Utils.pad_string("CPSI:")), row_idx, col_idx)
        self.addWidget(self.cpsiEditLine, row_idx, col_idx + 1, 1, 2)

    def _add_integration_time_input_line(self, row_idx, col_idx) -> None:
        """
        Add integration time input line
        Parameters
        ----------
        row_idx: int
            Row index
        col_idx: int
            Col index

        Returns
        -------
        """
        self.addWidget(QLabel(Utils.pad_string("Integration time:")), row_idx, col_idx)
        self.addWidget(self.timeEditLine, row_idx, col_idx + 1)
        self.addWidget(self.timeDropDown, row_idx, col_idx + 2)

    def _add_inert_specie_input_line(self, row_idx, col_idx) -> None:
        """
        Add inert specie input line
        Parameters
        ----------
        row_idx: int
            Row index
        col_idx: int
            Col index

        Returns
        -------
        """
        self.addWidget(QLabel(Utils.pad_string("Inert specie:")), row_idx, col_idx)
        self.addWidget(self.inertSpecieEditLine, row_idx, col_idx + 1, 1, 2)

    def _add_inert_coverage_input_line(self, row_idx, col_idx) -> None:
        """
        Add inert coverage input line
        Parameters
        ----------
        row_idx: int
            Row index
        col_idx: int
            Col index

        Returns
        -------
        """
        self.addWidget(QLabel(Utils.pad_string("Inert coverage:")), row_idx, col_idx)
        self.addWidget(self.inertCoverageEditLine, row_idx, col_idx + 1, 1, 2)

    def _add_time_step_input_line(self, row_idx, col_idx) -> None:
        """
        Add integration time step input line
        Parameters
        ----------
        row_idx: int
            Row index
        col_idx: int
            Col index

        Returns
        -------
        """
        self.addWidget(QLabel(Utils.pad_string("Integration time step:")), row_idx, col_idx)
        self.addWidget(self.timeStepEditLine, row_idx, col_idx + 1)
        self.addWidget(self.timeStepDropDown, row_idx, col_idx + 2)

    def _add_reactor_length_step_input_line(self, row_idx, col_idx) -> None:
        """
        Add reactor length step input line
        Parameters
        ----------
        row_idx: int
            Row index
        col_idx: int
            Col index

        Returns
        -------
        """
        self.addWidget(QLabel(Utils.pad_string("Reactor length step:")), row_idx, col_idx)
        self.addWidget(self.lengthStepEditLine, row_idx, col_idx + 1)
        self.addWidget(self.lengthStepDropDown, row_idx, col_idx + 2)

    def _add_mass_flow_rate_input_line(self, row_idx, col_idx) -> None:
        """
        Add mass flow rate input line
        Parameters
        ----------
        row_idx: int
            Row index
        col_idx: int
            Col index

        Returns
        -------
        """
        self.addWidget(QLabel(Utils.pad_string("Mass flow rate:")), row_idx, col_idx)
        self.addWidget(self.massFlowRateEditLine, row_idx, col_idx + 1)
        self.addWidget(self.massFlowRateDropDown, row_idx, col_idx + 2)

    def _add_initial_temperature_input_line(self, row_idx, col_idx) -> None:
        """
        Add initial temperature input line
        Parameters
        ----------
        row_idx: int
            Row index
        col_idx: int
            Col index

        Returns
        -------
        """
        self.addWidget(QLabel("Temperature:"), row_idx, col_idx)
        self.addWidget(self.initialTemperatureEditLine, row_idx, col_idx + 1)
        self.addWidget(self.initialTemperatureDropDown, row_idx, col_idx + 2)

    def _add_initial_composition_type_input_line(self, row_idx, col_idx) -> None:
        """
        Add initial composition type input line
        Parameters
        ----------
        row_idx: int
            Row index
        col_idx: int
            Col index

        Returns
        -------
        """
        self.addWidget(QLabel("Composition type:"), row_idx, col_idx)
        self.addWidget(self.compositionUdDropDown, row_idx, col_idx + 1, 1, 2)

    def _add_coverage_input_line(self) -> None:
        """
        Add input coverage line
        Returns
        -------

        """
        self.addWidget(QLabel(Utils.pad_string(f"Coverage #{len(self._coverage_names_idx) + 1}")),
                       self._coverage_row_idx,
                       self._coverage_col_idx + 0)
        self.addWidget(self._create_line_edit("Rh(s)", Qt.AlignRight, None),
                       self._coverage_row_idx,
                       self._coverage_col_idx + 1)
        self._coverage_names_idx.append(self.count() - 1)
        self.addWidget(self._create_line_edit("1", Qt.AlignRight, QDoubleValidator()),
                       self._coverage_row_idx,
                       self._coverage_col_idx + 2)
        self._coverage_composition_idx.append(self.count() - 1)

        self._coverage_row_idx = self._coverage_row_idx + 1

    def _add_initial_species_input_line(self) -> None:
        """
        Add initial species line
        Returns
        -------

        """
        self.addWidget(QLabel(Utils.pad_string(f"Specie #{len(self._specie_names_idx) + 1}")),
                       self._initial_species_row_idx,
                       self._initial_conditions_col_idx + 0)
        self.addWidget(self._create_line_edit("H2", Qt.AlignRight, None),
                       self._initial_species_row_idx,
                       self._initial_conditions_col_idx + 1)
        self._specie_names_idx.append(self.count() - 1)
        self.addWidget(self._create_line_edit("0.5", Qt.AlignRight, QDoubleValidator()),
                       self._initial_species_row_idx,
                       self._initial_conditions_col_idx + 2)
        self._specie_composition_idx.append(self.count() - 1)

        self._initial_species_row_idx = self._initial_species_row_idx + 1

    def _add_reactor_type_input_lines(self) -> None:
        """
        Add reactor type input line
        Returns
        -------

        """
        self._reactor_type_final_row_idx = self._reactor_type_first_row_idx
        if self.reactorTypeDropDown.currentIndex() == 1:  # Packed bed reactor
            self._add_diameter_input_line(self._reactor_type_final_row_idx, self._reactor_properties_col_idx)
            self._reactor_type_final_row_idx = self._reactor_type_final_row_idx + 1
            self._add_particle_diameter_input_line(self._reactor_type_final_row_idx, self._reactor_properties_col_idx)
            self._reactor_type_final_row_idx = self._reactor_type_final_row_idx + 1
            self._add_void_fraction_input_line(self._reactor_type_final_row_idx, self._reactor_properties_col_idx)
        elif self.reactorTypeDropDown.currentIndex() == 2:  # Honeycomb reactor
            self._add_cpsi_input_line(self._reactor_type_final_row_idx, self._reactor_properties_col_idx)
            self._reactor_type_final_row_idx = self._reactor_type_final_row_idx + 1
            self._add_wall_thickness_input_line(self._reactor_type_final_row_idx, self._reactor_properties_col_idx)
        elif self.reactorTypeDropDown.currentIndex() == 3:  # Tubular reactor
            self._add_diameter_input_line(self._reactor_type_final_row_idx, self._reactor_properties_col_idx)
            self._reactor_type_final_row_idx = self._reactor_type_final_row_idx + 1
            self._add_wall_thickness_input_line(self._reactor_type_final_row_idx, self._reactor_properties_col_idx)

    def _load_udk_model(self) -> None:
        """
        Load ASALI user defined kinetic model
        Returns
        -------

        """
        self.main_window.backend_frontend_manager.udk_file_path = Utils.open_file(self.main_window,
                                                                                  file_type=FileType.ASALI.value)

        self.udkLoadLabel.setText(Utils.pad_string("Not loaded"))

        if self.main_window.backend_frontend_manager.udk_file_path is not None:
            if self.main_window.backend_frontend_manager.check_udk_input_file():
                self.udkLoadLabel.setText(Utils.pad_string("Loaded"))
            else:
                Utils.error_message(self.main_window,
                                    self.title,
                                    QLabel("Wrong ASALI input file."))

    def _check_input_files(self) -> bool:
        """
        Check the input files to be used for reactor simulation
        Returns
        -------
        check: bool
            Results of the check
        """
        if not self.main_window.backend_frontend_manager.check_cantera_input_file():
            Utils.error_message(self.main_window,
                                self.title,
                                QLabel("Wrong CANTERA input file."))
            return False

        if self.main_window.backend_frontend_manager.surface_phase_name is None:
            if self.main_window.backend_frontend_manager.udk_file_path is None:
                Utils.error_message(self.main_window,
                                    self.title,
                                    QLabel("""The provided CANTERA file does not have surface reactions."""))
                return False

        if self.main_window.backend_frontend_manager.udk_file_path is not None:
            if not self.main_window.backend_frontend_manager.check_udk_input_file():
                Utils.error_message(self.main_window,
                                    self.title,
                                    QLabel("Wrong ASALI input file."))
                return False

        return True

    def _extract_coverage_input_composition(self) -> dict | None:
        """
        Extract coverage input composition
        Returns
        -------
        composition: dict
            User input composition
        """
        names = [self.itemAt(i).widget().text() for i in self._coverage_names_idx]
        composition = [float(self.itemAt(i).widget().text()) for i in self._coverage_composition_idx]

        if np.fabs(sum(composition) - 1.0) > 1e-06:
            Utils.error_message(self.main_window,
                                self.title,
                                QLabel("Sum of coverage composition is > 1!!!"))
            return None

        return dict(zip(names, composition))

    def _extract_initial_species_composition(self) -> dict | None:
        """
        Extract initial species composition
        Returns
        -------
        composition: dict
            User input composition
        """
        names = [self.itemAt(i).widget().text() for i in self._specie_names_idx]
        composition = [float(self.itemAt(i).widget().text()) for i in self._specie_composition_idx]

        if np.fabs(sum(composition) - 1.0) > 1e-06:
            Utils.error_message(self.main_window,
                                self.title,
                                QLabel("Sum of initial composition composition is not 1!!!"))
            return None

        return dict(zip(names, composition))

    def run_reactor_model(self) -> None:
        """
        Function to run the reactor model
        Returns
        -------

        """
        input_dict = self.read_input()

        if len(input_dict) > 0:
            self.main_window.worker.task_function = self.reactor_model_function
            self.main_window.worker.args = (self.main_window.backend_frontend_manager.file_path,
                                            self.main_window.backend_frontend_manager.gas_phase_name,
                                            self.main_window.backend_frontend_manager.surface_phase_name,
                                            input_dict)
            self.main_window.runBar.worker = self.main_window.worker

            self.main_window.setEnabled(False)

            self.main_window.runBar.reset_run_bar()
            self.main_window.runBar.show()

            self.main_window.worker.start()

    def run_backend(self) -> None:
        """
        Run backend to update frontend
        Returns
        -------

        """
        pass

    @abstractmethod
    def _update_column_indexes(self) -> None:
        """
        Class to update the column indexes for the reactor window layout
        Returns
        -------

        """
        pass

    @abstractmethod
    def _add_buttons(self, row_idx) -> None:
        """
        Add buttons
        Parameters
        ----------
        row_idx: int
            Row index where to add the buttons
        Returns
        -------

        """
        pass

    @abstractmethod
    def _remove_buttons(self, row_idx) -> None:
        """
        Remove buttons
        Parameters
        ----------
        row_idx: int
            Row index where to add the buttons
        Returns
        -------

        """
        pass

    @abstractmethod
    def _add_headlines(self, row_idx) -> None:
        """
        Add headlines for user input
        Parameters
        ----------
        row_idx: int
            Row index where to add the buttons
        Returns
        -------

        """
        pass

    @abstractmethod
    def _check_all_inputs(self, variables_dict) -> bool:
        """
        Perform check on the user input
        Parameters
        ----------
        variables_dict: dict
            Dictionary of variables {ReactorVariablesName: QEditLine}

        Returns
        -------
        check: bool
            Results of the performed check
        """
        pass

    @abstractmethod
    def read_input(self) -> dict:
        """
        Function to read user input
        Returns
        -------
        input_dict: dict
            User input
        """
        return {}

    @abstractmethod
    def create_layout_components(self) -> None:
        """
        Initialize the widgets
        Returns
        -------
        """
        pass

    @abstractmethod
    def generate_layout(self) -> None:
        """
        Update the interface
        Returns
        -------
        """
        pass
