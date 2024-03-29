/*##############################################################################################
#                                                                                              #
#     #############       #############       #############       ####                ####     #
#    #             #     #             #     #             #     #    #              #    #    #
#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #
#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #
#    #    #####    #     #    #              #    #####    #     #    #              #    #    #
#    #             #     #    #########      #             #     #    #              #    #    #
#    #             #     #             #     #             #     #    #              #    #    #
#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #
#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #
#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #
#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #
#     ####     ####       #############       ####     ####       #############       ####     #
#                                                                                              #
#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #
#                                                                                              #
################################################################################################
#                                                                                              #
#   License                                                                                    #
#                                                                                              #
#   This file is part of ASALI.                                                                #
#                                                                                              #
#   ASALI is free software: you can redistribute it and/or modify                              #
#   it under the terms of the GNU General Public License as published by                       #
#   the Free Software Foundation, either version 3 of the License, or                          #
#   (at your option) any later version.                                                        #
#                                                                                              #
#   ASALI is distributed in the hope that it will be useful,                                   #
#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #
#   GNU General Public License for more details.                                               #
#                                                                                              #
#   You should have received a copy of the GNU General Public License                          #
#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #
#                                                                                              #
##############################################################################################*/

public class TransportDatabase
{

	String [] names_ = {"AC3H4",
                        "CH3COOH",
                        "CH3COCH3",
                        "C2H3CHO",
                        "C2H5CHO",
                        "C4H9CHO",
                        "AR",
                        "C6H5CH2OH",
                        "C6H4O2",
                        "C6H6",
                        "C6H5CHO",
                        "C6H5C2H4C6H5",
                        "NC4H8",
                        "C4H6",
                        "C12H8",
                        "C2H2",
                        "C2H4",
                        "C2H6",
                        "C3H6",
                        "C3H8",
                        "C4H2",
                        "C4H4",
                        "CYC5H4O",
                        "C6H5O",
                        "CYC6H10-ONE",
                        "CYC5H8",
                        "CYC6H8",
                        "CYC6H12",
                        "CYC6H10",
                        "CH2CO",
                        "CH2O",
                        "CH3OH",
                        "CH4",
                        "CO",
                        "CO2",
                        "CYC5H6",
                        "MCPTD",
                        "CRESOL",
                        "NC10H20",
                        "C6H5CH2C6H5",
                        "DIPE",
                        "CH3OCH3",
                        "CH3CH3-C5H6",
                        "C6H5C2H5",
                        "NC7H14",
                        "NC6H12",
                        "C5H9CHO",
                        "ETBE",
                        "C2H5OH",
                        "C2H5OOH",
                        "C2H4O",
                        "C6H5C2H",
                        "BIPHENYL",
                        "C14H10",
                        "C6H5OH",
                        "FLUORENE",
                        "C10H8",
                        "H2",
                        "H2O",
                        "H2O2",
                        "HE",
                        "IC4H8",
                        "IC3H7CHO",
                        "IC4H10",
                        "IC8H18",
                        "INDENE",
                        "IC3H7OH",
                        "IC5H10",
                        "IC3H5CHO",
                        "MCYC6",
                        "CH3CHO",
                        "C10H7CH3",
                        "CH3OOH",
                        "MTBE",
                        "N2",
                        "C10H7OH",
                        "C10H7CHO",
                        "NC4H10",
                        "NC10H22",
                        "NC12H26",
                        "NC5H12",
                        "NC7H16",
                        "NEOC5H12",
                        "O2",
                        "IC8H16",
                        "NC5H10",
                        "PC3H4",
                        "CH3CO3H",
                        "HCO3H",
                        "C3H6O",
                        "C5H8",
                        "C16H10",
                        "C6H5C2H3",
                        "TAME",
                        "TETRALIN",
                        "DECALIN",
                        "C7H8",
                        "XYLENE",
                        "NC16H34",
                        "N2H4",
                        "N2O",
                        "NH3",
                        "NO",
                        "NO2",
                        "C3H5OOH",
                        "NC3H7OH",
                        "N1C4H9OH",
                        "N2C4H9OH",
                        "MEK",
                        "TC4H9OH",
                        "IC4H9OH",
                        "C4H7OH",
                        "C3H5OH",
                        "C10H10",
                        "BZFUR",
                        "TMBENZ",
                        "NPBENZ",
                        "C6H5OCH3",
                        "MB",
                        "MCROT",
                        "MACRIL",
                        "DIBZFUR",
                        "DIFENET",
                        "C12H22",
                        "BENZYNE",
                        "C2H2O2",
                        "C4H6O2",
                        "C5H4O2",
                        "C5H8O4",
                        "C6H10O5",
                        "C8H10O3",
                        "HCOOH",
                        "GLYCEROL",
                        "C4H4O"};

	int    [] geometry_ = {1,
                        2,
                        2,
                        2,
                        2,
                        2,
                        0,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        1,
                        2,
                        2,
                        2,
                        2,
                        1,
                        2,
                        2,
                        2,
                        2,
                        1,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        1,
                        1,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        1,
                        2,
                        2,
                        0,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        1,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        1,
                        2,
                        2,
                        1,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        1,
                        2,
                        1,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2,
                        2};

	double [] LJpotential_ = {252.0,
                        436.0,
                        411.0,
                        443.2,
                        411.0,
                        500.0,
                        136.5,
                        622.4,
                        450.0,
                        468.5,
                        622.4,
                        783.8,
                        355.0,
                        357.0,
                        689.8,
                        209.0,
                        280.8,
                        252.3,
                        307.8,
                        303.4,
                        357.0,
                        357.0,
                        450.0,
                        450.0,
                        568.5,
                        408.0,
                        468.5,
                        468.5,
                        468.5,
                        436.0,
                        498.0,
                        481.8,
                        141.4,
                        98.1,
                        244.0,
                        408.0,
                        408.0,
                        621.1,
                        540.98,
                        712.6,
                        432.0,
                        303.4,
                        450.0,
                        523.6,
                        459.98,
                        412.3,
                        568.5,
                        432.0,
                        362.6,
                        362.6,
                        362.6,
                        534.3,
                        676.5,
                        772.0,
                        450.0,
                        712.6,
                        630.4,
                        38.0,
                        572.4,
                        107.4,
                        10.2,
                        355.0,
                        455.0,
                        352.0,
                        494.0,
                        588.6,
                        482.146548,
                        408.0,
                        357.0,
                        495.3,
                        436.0,
                        660.0,
                        481.8,
                        392.0,
                        97.53,
                        663.45,
                        663.45,
                        352.0,
                        540.98,
                        580.0,
                        392.0,
                        459.98,
                        392.0,
                        107.4,
                        494.0,
                        408.0,
                        252.0,
                        443.2,
                        443.2,
                        411.0,
                        408.0,
                        834.9,
                        546.2,
                        432.0,
                        630.4,
                        630.4,
                        495.3,
                        523.6,
                        650.0,
                        205.0,
                        232.4,
                        481.0,
                        97.5,
                        200.0,
                        407.8,
                        482.146548,
                        503.0722524,
                        503.0722524,
                        454.0,
                        503.0722524,
                        503.0722524,
                        503.0722524,
                        411.0,
                        630.4,
                        630.4,
                        523.6,
                        495.3,
                        450.0,
                        468.0,
                        468.5,
                        430.1,
                        676.5,
                        676.5,
                        580.0,
                        468.5,
                        470.6,
                        496.0,
                        524.69,
                        568.5,
                        568.5,
                        621.1,
                        470.6,
                        748.365,
                        429.63};

	double [] LJdiameter_ = {4.76,
                        3.97,
                        4.82,
                        4.12,
                        4.82,
                        5.64,
                        3.33,
                        5.53,
                        5.5,
                        5.23,
                        5.53,
                        6.64,
                        4.65,
                        5.18,
                        6.5,
                        4.1,
                        3.971,
                        4.302,
                        4.14,
                        4.81,
                        5.18,
                        5.18,
                        5.5,
                        5.5,
                        5.23,
                        5.2,
                        5.23,
                        5.23,
                        5.23,
                        3.97,
                        3.59,
                        3.626,
                        3.746,
                        3.65,
                        3.763,
                        5.2,
                        5.2,
                        5.64,
                        7.15,
                        6.89,
                        6.0,
                        4.81,
                        5.5,
                        5.96,
                        6.31,
                        5.349,
                        5.23,
                        6.0,
                        4.53,
                        4.53,
                        4.53,
                        5.71,
                        6.31,
                        6.96,
                        5.5,
                        6.89,
                        6.18,
                        2.92,
                        2.605,
                        3.458,
                        2.576,
                        4.65,
                        4.65,
                        5.24,
                        6.17,
                        5.96,
                        5.008549665,
                        5.2,
                        5.18,
                        5.68,
                        3.97,
                        6.35,
                        3.626,
                        5.64,
                        3.621,
                        6.362,
                        6.362,
                        5.24,
                        7.15,
                        7.6,
                        5.64,
                        6.31,
                        5.64,
                        3.458,
                        6.17,
                        5.2,
                        4.76,
                        4.12,
                        4.12,
                        4.82,
                        5.2,
                        7.24,
                        6.0,
                        6.0,
                        6.18,
                        6.18,
                        5.68,
                        5.96,
                        8.35,
                        4.23,
                        3.828,
                        2.92,
                        3.621,
                        3.5,
                        4.14,
                        5.008549665,
                        5.339941638,
                        5.339941638,
                        5.413,
                        5.339941638,
                        5.339941638,
                        5.339941638,
                        4.82,
                        6.18,
                        6.18,
                        5.96,
                        5.68,
                        5.5,
                        5.85,
                        5.23,
                        5.833,
                        6.31,
                        6.31,
                        7.6,
                        5.23,
                        4.41,
                        5.2,
                        5.653,
                        5.23,
                        5.23,
                        5.64,
                        3.855,
                        5.2,
                        5.04};

	double [] dipole_ = {0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.77,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        1.844,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.65,
                        1.66,
                        0.0,
                        0.0,
                        0.43,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.13,
                        0.0,
                        0.0,
                        0.0,
                        0.43,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        1.47,
                        0.0,
                        0.0,
                        0.0,
                        1.66,
                        1.67,
                        1.67,
                        3.3,
                        1.67,
                        1.67,
                        1.67,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.43,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        1.93,
                        0.0};

	double [] polar_ = {0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        10.3,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        10.3,
                        0.0,
                        10.3,
                        10.3,
                        10.3,
                        0.0,
                        0.0,
                        0.0,
                        2.6,
                        1.95,
                        2.65,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        10.3,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        38.8,
                        0.0,
                        0.0,
                        16.5,
                        0.79,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        6.74,
                        0.0,
                        0.0,
                        12.3,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        1.76,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        1.6,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        45.0,
                        15.0,
                        0.0,
                        16.5,
                        16.5,
                        12.3,
                        0.0,
                        0.0,
                        4.26,
                        0.0,
                        0.0,
                        1.76,
                        0.0,
                        0.0,
                        6.74,
                        8.88,
                        8.88,
                        0.0,
                        8.88,
                        8.88,
                        8.88,
                        0.0,
                        16.5,
                        16.5,
                        0.0,
                        12.3,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        0.0,
                        10.3,
                        0.0,
                        0.0,
                        0.0,
                        10.3,
                        10.3,
                        0.0,
                        0.0,
                        9.43,
                        0.0};

	double [] collision_ = {0.0,
                        2.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        0.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        2.5,
                        1.5,
                        1.5,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        2.0,
                        2.0,
                        1.0,
                        13.0,
                        1.8,
                        2.1,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.5,
                        1.5,
                        1.5,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        280.0,
                        4.0,
                        3.8,
                        0.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        2.0,
                        1.0,
                        1.0,
                        1.0,
                        4.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        3.8,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.5,
                        1.0,
                        10.0,
                        4.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        0.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.5,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0,
                        1.0};

	double [] MW_ = {40.0648,
                        60.0526,
                        58.08,
                        56.0642,
                        58.08,
                        86.1338,
                        39.948,
                        108.14,
                        108.097,
                        78.1136,
                        106.124,
                        182.265,
                        56.1075,
                        54.0916,
                        152.196,
                        26.0379,
                        28.0538,
                        30.0696,
                        42.0806,
                        44.0965,
                        50.0599,
                        52.0758,
                        80.0862,
                        93.1051,
                        98.1448,
                        68.1185,
                        80.1295,
                        84.1613,
                        82.1454,
                        42.0373,
                        30.0263,
                        32.0422,
                        16.0428,
                        28.0104,
                        44.0098,
                        66.1026,
                        80.1295,
                        108.14,
                        140.269,
                        168.238,
                        102.177,
                        46.069,
                        96.1723,
                        106.167,
                        98.1882,
                        84.1613,
                        98.1448,
                        102.177,
                        46.069,
                        62.0684,
                        44.0532,
                        102.136,
                        154.211,
                        178.233,
                        94.113,
                        166.222,
                        128.174,
                        2.01588,
                        18.0153,
                        34.0147,
                        4.0026,
                        56.1075,
                        72.1069,
                        58.1234,
                        114.231,
                        116.163,
                        60.0959,
                        70.1344,
                        70.091,
                        98.1882,
                        44.0532,
                        142.2,
                        48.0416,
                        88.1497,
                        28.0135,
                        144.173,
                        156.184,
                        58.1234,
                        142.285,
                        170.338,
                        72.1503,
                        100.204,
                        72.1503,
                        31.9988,
                        112.215,
                        70.1344,
                        40.0648,
                        76.052,
                        62.0251,
                        58.08,
                        68.1185,
                        202.255,
                        104.152,
                        102.177,
                        132.205,
                        138.253,
                        92.1405,
                        106.167,
                        226.446,
                        32.0452,
                        44.0129,
                        17.0306,
                        30.0061,
                        46.0055,
                        74.0794,
                        60.0959,
                        74.1228,
                        74.1228,
                        72.1069,
                        74.1228,
                        74.1228,
                        72.1069,
                        58.08,
                        130.189,
                        118.135,
                        120.194,
                        120.194,
                        108.14,
                        102.133,
                        100.117,
                        86.0904,
                        168.195,
                        170.211,
                        166.307,
                        76.0978,
                        58.0367,
                        86.0904,
                        96.0856,
                        132.116,
                        162.142,
                        154.166,
                        46.0257,
                        92.0947,
                        68.0752};

	String [] names()
	{
		return names_;
	}

	int [] geometry()
	{
		return geometry_;
	}

	double [] LJpotential()
	{
		return LJpotential_;
	}

	double [] LJdiameter()
	{
		return LJdiameter_;
	}

	double [] dipole()
	{
		return dipole_;
	}

	double [] polar()
	{
		return polar_;
	}

	double [] collision()
	{
		return collision_;
	}

	double [] MW()
	{
		return MW_;
	}


}

