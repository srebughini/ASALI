from abc import abstractmethod

from src.core.data_keys import DataKeys
from src.gui.pages.input.basic_reactor_input_page import BasicReactorInputPage
from src.config.reactor_config import ReactorConfig


class AdvancedInputPage(BasicReactorInputPage):
    def __init__(self, data_store, dialog_handler, run_bar):
        """
        Advanced reactor input page layout (Cstr, Ph1D, Het1D)
        Parameters
        ----------
        data_store: DataStore
            Class to handle the user input
        dialog_handler: DialogPagesHandler
            Class to handle all dialog pages
        run_bar: RunBarWindow
            Class to handle the run bar
        """
        super().__init__(data_store, dialog_handler, run_bar)

    @abstractmethod
    def update_page_after_switch(self) -> None:
        """
        Update the whole page
        Returns
        -------

        """
        pass

    @abstractmethod
    def get_initial_layout_info(self) -> tuple:
        """
        Extract info of the layout before applying any change
        Returns
        -------
        output_tuple: tuple
            Tuple of dictionary describing the minimum row idx and tab name to grid layout dictionary
        """
        pass

    @abstractmethod
    def read_data(self) -> None:
        """
        Update data store with temperature, composition, pressure
        Returns
        -------

        """
        pass

    @property
    @abstractmethod
    def number_of_gas_species_to_row_idx(self) -> int:
        """
        Property that returns the number of gas species to row index value
        Returns
        -------

        """
        return 0

    @property
    @abstractmethod
    def number_of_surface_species_to_row_idx(self) -> int:
        """
        Property that returns the number of surface species to row index value
        Returns
        -------

        """
        return 0

    def from_ns_to_row_idx(self, ns) -> int:
        """
        Convert the number of species to row idx
        Parameters
        ----------
        ns: int
            Number of species

        Returns
        -------
        row_idx: int
            Row index corresponding to the number of species based on the layout
        """
        return ns + self.number_of_gas_species_to_row_idx

    def from_surf_ns_to_row_idx(self, surf_ns) -> int:
        """
        Convert the number of surface species to row idx
        Parameters
        ----------
        surf_ns: int
            Number of species

        Returns
        -------
        row_idx: int
            Row index corresponding to the number of species based on the layout
        """
        return surf_ns + self.number_of_surface_species_to_row_idx

    def add_coverage_line(self) -> None:
        """
        Add coverage line to the layout
        Returns
        -------

        """
        surf_ns = int(self.data_store.get_data(DataKeys.INITIAL_SURF_NS.value) + 1)
        self.data_store.update_data(DataKeys.INITIAL_SURF_NS.value, surf_ns)
        surf_ns_row_idx = self.from_surf_ns_to_row_idx(surf_ns)

        # Coverage tab
        tab_name = ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value
        row_idx = self._dynamic_row_idx_dict[tab_name]
        layout_name = self._tab_name_to_grid_layout_dict[tab_name]

        if surf_ns_row_idx > self._dynamic_row_idx_dict[tab_name]:
            row_idx = row_idx + 1
            self.add_surface_specie_input_row_to_grid_layout(layout_name,
                                                             surf_ns,
                                                             row_idx,
                                                             with_label=True)
            self.update_grid_layout(layout_name)
            self._dynamic_row_idx_dict[tab_name] = row_idx
        else:
            self.remove_row_from_grid_layout(layout_name, surf_ns_row_idx)
            self.add_surface_specie_input_row_to_grid_layout(layout_name,
                                                             surf_ns,
                                                             surf_ns_row_idx,
                                                             with_label=True)
            self.update_grid_layout(layout_name)

        # Other tabs
        for tab_name in [ReactorConfig.SOLVING_OPTION_TAB_NAME.value,
                         ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value,
                         ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value]:
            if surf_ns_row_idx > self._dynamic_row_idx_dict[tab_name]:
                row_idx = self._dynamic_row_idx_dict[tab_name] + 1
                layout_name = self._tab_name_to_grid_layout_dict[tab_name]
                self.add_dummy_row_to_grid_layout(layout_name, row_idx)
                self._dynamic_row_idx_dict[tab_name] = row_idx

    def remove_coverage_line(self) -> None:
        """
        Remove coverage line to the layout
        Returns
        -------

        """
        surf_ns = int(self.data_store.get_data(DataKeys.INITIAL_SURF_NS.value))

        if surf_ns > 0:
            self.data_store.update_data(DataKeys.INITIAL_SURF_NS.value, surf_ns - 1)
            ns = int(self.data_store.get_data(DataKeys.INITIAL_NS.value))
            surf_ns_row_idx = self.from_surf_ns_to_row_idx(surf_ns)
            ns_row_idx = self.from_ns_to_row_idx(ns)

            if ns_row_idx >= surf_ns_row_idx:
                tab_name = ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value
                layout_name = self._tab_name_to_grid_layout_dict[tab_name]
                self.remove_row_from_grid_layout(layout_name, surf_ns_row_idx)
                self.add_dummy_row_to_grid_layout(layout_name, surf_ns_row_idx)
            else:
                for tab_name in [ReactorConfig.SOLVING_OPTION_TAB_NAME.value,
                                 ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value,
                                 ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value]:
                    row_idx = self._dynamic_row_idx_dict[tab_name]
                    if row_idx > self._minimum_row_idx_dict[tab_name]:
                        layout_name = self._tab_name_to_grid_layout_dict[tab_name]
                        self.remove_row_from_grid_layout(layout_name, row_idx)
                        self._dynamic_row_idx_dict[tab_name] = row_idx - 1

                tab_name = ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value
                if ns_row_idx < self._dynamic_row_idx_dict[tab_name]:
                    layout_name = self._tab_name_to_grid_layout_dict[tab_name]
                    self.remove_row_from_grid_layout(layout_name, row_idx)
                    self._dynamic_row_idx_dict[tab_name] = row_idx - 1

    def add_specie_line(self) -> None:
        """
        Add specie line to the layout
        Returns
        -------

        """
        ns = int(self.data_store.get_data(DataKeys.INITIAL_NS.value) + 1)
        self.data_store.update_data(DataKeys.INITIAL_NS.value, ns)
        ns_row_idx = self.from_ns_to_row_idx(ns)

        # Coverage tab
        tab_name = ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value
        row_idx = self._dynamic_row_idx_dict[tab_name]
        layout_name = self._tab_name_to_grid_layout_dict[tab_name]

        if ns_row_idx > self._dynamic_row_idx_dict[tab_name]:
            row_idx = row_idx + 1
            self.add_gas_specie_input_row_to_grid_layout(layout_name,
                                                         ns,
                                                         row_idx,
                                                         with_label=True)
            self.update_grid_layout(layout_name)
            self._dynamic_row_idx_dict[tab_name] = row_idx
        else:
            self.remove_row_from_grid_layout(layout_name, ns_row_idx)
            self.add_gas_specie_input_row_to_grid_layout(layout_name,
                                                         ns,
                                                         ns_row_idx,
                                                         with_label=True)
            self.update_grid_layout(layout_name)

        # Other tabs
        for tab_name in [ReactorConfig.SOLVING_OPTION_TAB_NAME.value,
                         ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value,
                         ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value]:
            if ns_row_idx > self._dynamic_row_idx_dict[tab_name]:
                row_idx = self._dynamic_row_idx_dict[tab_name] + 1
                layout_name = self._tab_name_to_grid_layout_dict[tab_name]
                self.add_dummy_row_to_grid_layout(layout_name, row_idx)
                self._dynamic_row_idx_dict[tab_name] = row_idx

    def remove_specie_line(self) -> None:
        """
        Remove specie line to the layout
        Returns
        -------

        """
        ns = int(self.data_store.get_data(DataKeys.INITIAL_NS.value))

        if ns > 0:
            self.data_store.update_data(DataKeys.INITIAL_NS.value, ns - 1)
            surf_ns = int(self.data_store.get_data(DataKeys.INITIAL_SURF_NS.value))
            surf_ns_row_idx = self.from_surf_ns_to_row_idx(surf_ns)
            ns_row_idx = self.from_ns_to_row_idx(ns)

            if surf_ns_row_idx >= ns_row_idx:
                tab_name = ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value
                layout_name = self._tab_name_to_grid_layout_dict[tab_name]
                self.remove_row_from_grid_layout(layout_name, ns_row_idx)
                self.add_dummy_row_to_grid_layout(layout_name, ns_row_idx)
            else:
                for tab_name in [ReactorConfig.SOLVING_OPTION_TAB_NAME.value,
                                 ReactorConfig.REACTOR_PROPERTIES_TAB_NAME.value,
                                 ReactorConfig.INITIAL_CONDITIONS_TAB_NAME.value]:
                    row_idx = self._dynamic_row_idx_dict[tab_name]
                    if row_idx > self._minimum_row_idx_dict[tab_name]:
                        layout_name = self._tab_name_to_grid_layout_dict[tab_name]
                        self.remove_row_from_grid_layout(layout_name, row_idx)
                        self._dynamic_row_idx_dict[tab_name] = row_idx - 1

                tab_name = ReactorConfig.COVERAGE_COMPOSITION_TAB_NAME.value
                if surf_ns_row_idx < self._dynamic_row_idx_dict[tab_name]:
                    layout_name = self._tab_name_to_grid_layout_dict[tab_name]
                    self.remove_row_from_grid_layout(layout_name, row_idx)
                    self._dynamic_row_idx_dict[tab_name] = row_idx - 1
