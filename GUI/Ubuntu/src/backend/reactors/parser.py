from asali.plotters.reactor import ReactorPlotter
from asali.reactors.basic import BasicReactor
from asali.savers.reactor import ReactorSaver
from asali.utils.unit_converter import UnitConverter

from src.frontend.utils import BasicUnitDimension


class ReactorParser:
    def __init__(self):
        """
        Basic class to parse reactor results
        """
        super().__init__()
        self._uc = UnitConverter()
        self._reactor_model = None
        self.timeUd = BasicUnitDimension.time.value
        self.lengthUd = BasicUnitDimension.length.value

    def get_reactor_model(self) -> BasicReactor:
        """
        Get reactor model
        Returns
        -------
        reactor_model: Derived class of BasicReactor
            ASALIPY reactor class
        """

        return self._reactor_model

    def set_reactor_model(self, value) -> None:
        """
        Set reactor model
        Parameters
        ----------
        value: Derived class of BasicReactor
            ASALIPY reactor class

        Returns
        -------

        """
        self._reactor_model = value

    # Creating a property object for reactor parser
    reactor_model = property(get_reactor_model, set_reactor_model)

    def plot(self, plot_dict) -> None:
        """
        Plot the results of the reactor model
        Parameters
        ----------
        plot_dict: dict
            Option parameters for plotting

        Returns
        -------

        """
        plotter = ReactorPlotter(self._reactor_model, colormap=plot_dict["colormap"])

        if plot_dict["T"]:
            plotter.plot_temperature()

        if len(plot_dict["x"]) > 0:
            plotter.plot_species_mole_fraction(plot_dict["x"])

        if len(plot_dict["y"]) > 0:
            plotter.plot_species_mass_fraction(plot_dict["y"])

        if len(plot_dict["z"]) > 0:
            plotter.plot_coverage(plot_dict["z"])

        plotter.show()

    def save(self, save_dict) -> None:
        """
        Save the results of the reactor model
        Parameters
        ----------
        save_dict: dict
            Option parameters for plotting

        Returns
        -------

        """
        saver = ReactorSaver(self._reactor_model)

        if save_dict["x"]:
            saver.save_using_mole_fraction(save_dict["file_path"])

        if save_dict["y"]:
            saver.save_using_mass_fraction(save_dict["file_path"])

    def gas_species_list(self) -> list:
        """
        Return gas species list
        Returns
        -------
        gas_species_names: list
            List of gas species names
        """
        return self._reactor_model.gas.species_names

    def coverage_list(self) -> list:
        """
        Return coverage list
        Returns
        -------
        coverage_names: list
            List of coverage names
        """
        return self._reactor_model.surf.species_names
