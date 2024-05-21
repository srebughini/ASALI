import os
from types import SimpleNamespace

import numpy as np


class DatabaseReader:
    """
    Class to read the database and convert it into python code
    """

    @staticmethod
    def read_transport_file(input_file_path=os.path.join("..", "database", "transport.asali"),
                            output_file_path=os.path.join("transport.py")):
        """
        Read transport file and convert it into a python file
        :param input_file_path: Transport file path
        :param output_file_path: Transport file path in python format
        :return:
        """
        transport_as_py_list = ["from types import SimpleNamespace", "\n", "transport={"]
        with open(input_file_path) as f:
            for line in f:
                line_list = line.replace("\n", "").split("\t")
                transport_as_py_list.append(f'"{line_list[0]}": SimpleNamespace(geometry={int(line_list[1])},'
                                            f'LJpotential={float(line_list[2])},'
                                            f'LJdiameter={float(line_list[3])},'
                                            f'dipole={float(line_list[4])},'
                                            f'polar={float(line_list[5])},'
                                            f'collision={float(line_list[6])},'
                                            f' MW={float(line_list[7])}),')

        transport_as_py_list.append("}")
        with open(output_file_path, "w") as f:
            f.write("\n".join(transport_as_py_list))

    @staticmethod
    def read_omega_file(input_file_path):
        """
        Extract from Omega file dipole, temperature and collision integral matrix
        :param input_file_path: Omega file path
        :return: dipole array, temperature array and collision integral matrix
        """
        with open(input_file_path) as f:
            line_list = [line.replace("\n", "").split("\t") for line in f]

        line_list = np.asarray(line_list)
        d = line_list[0, 1:].astype(float)
        t = line_list[1:, 0].astype(float)
        s = line_list[1:, 1:].astype(float)

        return d, t, s

    @staticmethod
    def read_omega_files(omega22_file_path=os.path.join("..", "database", "omega22.asali"),
                         astar_file_path=os.path.join("..", "database", "astar.asali"),
                         output_file_path=os.path.join("omega.py")):
        """
        Read omega files and convert them into a python file
        :param omega22_file_path: Omega 22 file path
        :param astar_file_path: A* file path
        :param output_file_path: Omega file path in python format
        :return:
        """
        d22, t22, s22 = DatabaseReader.read_omega_file(omega22_file_path)
        d11, t11, sstar = DatabaseReader.read_omega_file(astar_file_path)

        s11 = s22 / sstar

        omega22_as_py_list = ["omega22 = ", str({"d": d22.tolist(),
                                                 "t": t22.tolist(),
                                                 "s": s22.tolist()}),
                              "\n",
                              "omega11 = ", str({"d": d11.tolist(),
                                                 "t": t11.tolist(),
                                                 "s": s11.tolist()}),
                              ]

        with open(output_file_path, "w") as f:
            f.write("".join(omega22_as_py_list))

    @staticmethod
    def read_thermo_file(input_file_path=os.path.join("..", "database", "thermo.asali"),
                         output_file_path=os.path.join("thermo.py")):
        """
        Read thermo file and convert it into a python file
        :param input_file_path: Thermo file path
        :param output_file_path: Thermo file path in python format
        :return:
        """
        with open(input_file_path) as f:
            line_list = [line.replace("\n", "").strip().split("\t") for line in f]

        thermo_as_py_list = ["from types import SimpleNamespace", "\n", "thermo={"]

        for i in range(0, len(line_list), 4):
            high_list = np.asarray(line_list[i + 1]).astype(float)
            medium_list = np.asarray(line_list[i + 2]).astype(float)
            low_list = np.asarray(line_list[i + 3]).astype(float)

            thermo_as_py_list.append(
                f'"{line_list[i][0]}":SimpleNamespace(high={np.concatenate((high_list, medium_list[:2])).tolist()},'
                f'low={np.concatenate((medium_list[2:], low_list)).tolist()}),')

        thermo_as_py_list.append("}")
        with open(output_file_path, "w") as f:
            f.write("\n".join(thermo_as_py_list))


if __name__ == "__main__":
    DatabaseReader.read_transport_file()
    DatabaseReader.read_omega_files()
    DatabaseReader.read_thermo_file()
