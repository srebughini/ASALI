from src.backend.basic_calculation import BasicCalculation


class ChemicalEquilibrium(BasicCalculation):
    def __init__(self, cantera_input_file, gas_phase_name):
        """
        Class to get thermodynamic and transport properties from Cantera files
        Parameters
        ----------
        cantera_input_file: str
            Cantera input file path
        gas_phase_name: str
            Gas phase name
        """
        super().__init__(cantera_input_file, gas_phase_name)
