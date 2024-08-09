from asali.utils.cantera_file_converter import CanteraFileConverter


class ChemkinToCanteraConverter:
    """
    CHEMKIN -> CANTERA converter class
    """

    @staticmethod
    def convert(kinetic_file_path,
                thermodynamic_file_path,
                transport_file_path,
                surface_file_path,
                output_file_path) -> None:
        """
        Convert from CHEMKIN input files to Cantera .yaml file
        Parameters
        ----------
        kinetic_file_path: str
            CHEMKIN kinetic file path
        thermodynamic_file_path: str
            CHEMKIN thermodynamic file path
        transport_file_path: str
            CHEMKIN transport file path
        surface_file_path: str
            CHEMKIN surface kinetic file path
        output_file_path: str
            Cantera .yaml output file path
        Returns
        -------

        """
        CanteraFileConverter.from_chemkin_to_yaml(kinetic_file_path=kinetic_file_path,
                                                  thermodynamic_file_path=thermodynamic_file_path,
                                                  transport_file_path=transport_file_path,
                                                  surface_file_path=surface_file_path,
                                                  output_file_path=output_file_path,
                                                  validation=False)
