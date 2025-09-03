from enum import Enum


class ThermoPhases(Enum):
    """
    Enum to handle phase
    """
    GAS = 'Gas'
    LIQUID = 'Liquid'
    SOLID = 'Solid'


class ChemkinFileController:
    """
    Class collecting function to handle the saving of file
    """

    @staticmethod
    def transport_data_list_to_str(data_list) -> str:
        """
        Convert transport data list into a str in the correct file format
        Parameters
        ----------
        data_list: list
            Data as list [name,geometry,LJpotential, LJdiameter, dipole, polar, collision]

        Returns
        -------
        data_as_str: str
            Data converted into string format
        """
        formatted_string = (
            f"{data_list[0]:<{9}}"
            f"{int(data_list[1]):>{10}}"
            f"{float(data_list[2]):>{10}.3f}"
            f"{float(data_list[3]):>{10}.3f}"
            f"{float(data_list[4]):>{10}.3f}"
            f"{float(data_list[5]):>{10}.3f}"
            f"{float(data_list[6]):>{10}.3f}"
        )

        return formatted_string

    @staticmethod
    def thermo_number_to_str(num, digits=9):
        """
        Thermo number into string format
        Parameters
        ----------
        num: float
            Number
        digits: int (.opt)
            Number of digits

        Returns
        -------
        num_str: str
            Number in string format
        """
        base, exp = f"{num:.{digits}E}".split("E")

        if base.startswith("0.") or base.startswith("-0."):
            exp_desired = int(exp)
        else:
            exp_desired = int(exp) + 1

        mantissa = num / (10 ** exp_desired)  # Adjust mantissa
        num_str = f"{mantissa:.{digits}f}E{exp_desired:+03d}"  # Format with fixed exponent
        return num_str.replace("-0.", "-.").replace("0.", " .")

    @staticmethod
    def thermo_molecule_data_to_str(name,
                                    atomic_symbols_and_formula,
                                    phase,
                                    low_temperature,
                                    high_temperature,
                                    common_temperature) -> str:
        """
        Convert thermo molecule data into a string
        Parameters
        ----------
        name: str
            Specie name
        atomic_symbols_and_formula: dict
            Specie formula
        phase: Enum
            Phase as enum
        low_temperature: float
            Lower temperature
        high_temperature: float
            Upper temperature
        common_temperature: float
            Common temperature

        Returns
        -------
        data_as_str: str
            All data in string format
        """
        # Format the species name (1-18)
        species_name = name[:18].ljust(18)

        # Format the date (19-24)
        date = ' ' * 6

        # Format atomic symbols and formula (25-44)
        formula = ' '.join([f"{k} {v}" for k, v in atomic_symbols_and_formula.items()])[:20].ljust(20)

        # Format the phase (45)
        phase_dict = {ThermoPhases.SOLID: "S",
                      ThermoPhases.LIQUID: "L",
                      ThermoPhases.GAS: "G", }
        phase_str = phase_dict[phase].ljust(1)

        # Format temperatures (46-78) - convert float to string with one decimal place
        low_temp = f"{low_temperature:.2f}".rjust(9)
        high_temp = f"{high_temperature:.2f}".rjust(9)
        common_temp = f"{common_temperature:.2f}".rjust(9)

        # Format additional atomic symbols (74-78)
        additional_symbols = ' ' * 5

        # Concatenate all fields into one string
        data_s_str = (
                             species_name + date + formula + phase_str + low_temp + high_temp + common_temp + additional_symbols).ljust(
            79) + "1"

        return data_s_str

    @staticmethod
    def thermo_temperature_coefficients_to_str(upper_coefficient_list, lower_coefficient_list):
        """
        Convert thermo temperature coefficients into a string in file format
        Parameters
        ----------
        upper_coefficient_list: list
            Upper temperature coefficients
        lower_coefficient_list: list
            Lower temperature coefficients

        Returns
        -------
        coefficient_as_str: str
            Coefficient as string
        """
        line_2_list = [ChemkinFileController.thermo_number_to_str(n) for n in upper_coefficient_list[:5]]

        list_2_str = "".join(line_2_list).ljust(79) + "2"

        line_3_list = [ChemkinFileController.thermo_number_to_str(n) for n in upper_coefficient_list[-2:]]
        line_3_list.extend([ChemkinFileController.thermo_number_to_str(n) for n in lower_coefficient_list[:3]])

        list_3_str = "".join(line_3_list).ljust(79) + "3"

        line_4_list = [ChemkinFileController.thermo_number_to_str(n) for n in lower_coefficient_list[-4:]]
        list_4_str = "".join(line_4_list).ljust(79) + "4"

        return "\n".join([list_2_str, list_3_str, list_4_str])

    @staticmethod
    def thermo_data_list_to_str(data_list) -> str:
        """
        Convert thermo data list into a str in the correct file format
        Parameters
        ----------
        data_list: list
            Data as list [name,
                          atomic_symbols_and_formula,
                          phase,
                          low_temperature,
                          high_temperature,
                          common_temperature,
                          upper_coefficient_list,
                          lower_coefficient_list]

        Returns
        -------
        data_as_str: str
            Data converted into string format
        """

        line_1 = ChemkinFileController.thermo_molecule_data_to_str(*data_list[:-2])
        line_2_3_4 = ChemkinFileController.thermo_temperature_coefficients_to_str(data_list[-2], data_list[-1])
        return "\n".join([line_1, line_2_3_4])

    @staticmethod
    def update_transport_file(file_path, data_list) -> None:
        """
        Save transport data in transport CHEMKIN file
        Parameters
        ----------
        file_path: str | os.path
            File path
        data_list: list
            Data as list [name,geometry,LJpotential, LJdiameter, dipole, polar, collision]

        Returns
        -------

        """
        with open(file_path, 'r') as file:
            file_as_list = [line.rstrip() for line in file if line.rstrip()]

        formatted_string = ChemkinFileController.transport_data_list_to_str(data_list)

        if "end" in file_as_list[-1].lower():
            file_as_list = file_as_list[:-1]

        file_as_list.append(formatted_string)
        file_as_list.append("END")

        with open(file_path, 'w') as file:
            file.write("\n".join(file_as_list))
