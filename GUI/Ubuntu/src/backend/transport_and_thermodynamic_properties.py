import cantera as ct


class TransportAndThermodynamicProperties:
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
        self.gas = ct.Solution(cantera_input_file, gas_phase_name)

