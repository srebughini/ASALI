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

void transport_update(Asali* asali_)
{
	if ( !asali_->transport_updated_ )
	{
		asali_->transport_ = (struct transportParameters*) malloc(134 * sizeof(struct transportParameters));
		asali_->number_of_species = 134;
		
		asali_->transport_[0].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[0].name,"AC3H4");
		asali_->transport_[0].geometry = 1;
		asali_->transport_[0].LJpotential = 252.000;
		asali_->transport_[0].LJdiameter =  4.760;
		asali_->transport_[0].dipole =  0.000;
		asali_->transport_[0].polar =  0.000;
		asali_->transport_[0].collision =  0.000;
		asali_->transport_[0].MW = 40.065;
		
		asali_->transport_[1].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[1].name,"CH3COOH");
		asali_->transport_[1].geometry = 2;
		asali_->transport_[1].LJpotential = 436.000;
		asali_->transport_[1].LJdiameter =  3.970;
		asali_->transport_[1].dipole =  0.000;
		asali_->transport_[1].polar =  0.000;
		asali_->transport_[1].collision =  2.000;
		asali_->transport_[1].MW = 60.053;
		
		asali_->transport_[2].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[2].name,"CH3COCH3");
		asali_->transport_[2].geometry = 2;
		asali_->transport_[2].LJpotential = 411.000;
		asali_->transport_[2].LJdiameter =  4.820;
		asali_->transport_[2].dipole =  0.000;
		asali_->transport_[2].polar =  0.000;
		asali_->transport_[2].collision =  1.000;
		asali_->transport_[2].MW = 58.080;
		
		asali_->transport_[3].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[3].name,"C2H3CHO");
		asali_->transport_[3].geometry = 2;
		asali_->transport_[3].LJpotential = 443.200;
		asali_->transport_[3].LJdiameter =  4.120;
		asali_->transport_[3].dipole =  0.000;
		asali_->transport_[3].polar =  0.000;
		asali_->transport_[3].collision =  1.000;
		asali_->transport_[3].MW = 56.064;
		
		asali_->transport_[4].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[4].name,"C2H5CHO");
		asali_->transport_[4].geometry = 2;
		asali_->transport_[4].LJpotential = 411.000;
		asali_->transport_[4].LJdiameter =  4.820;
		asali_->transport_[4].dipole =  0.000;
		asali_->transport_[4].polar =  0.000;
		asali_->transport_[4].collision =  1.000;
		asali_->transport_[4].MW = 58.080;
		
		asali_->transport_[5].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[5].name,"C4H9CHO");
		asali_->transport_[5].geometry = 2;
		asali_->transport_[5].LJpotential = 500.000;
		asali_->transport_[5].LJdiameter =  5.640;
		asali_->transport_[5].dipole =  0.000;
		asali_->transport_[5].polar =  0.000;
		asali_->transport_[5].collision =  1.000;
		asali_->transport_[5].MW = 86.134;
		
		asali_->transport_[6].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->transport_[6].name,"AR");
		asali_->transport_[6].geometry = 0;
		asali_->transport_[6].LJpotential = 136.500;
		asali_->transport_[6].LJdiameter =  3.330;
		asali_->transport_[6].dipole =  0.000;
		asali_->transport_[6].polar =  0.000;
		asali_->transport_[6].collision =  0.000;
		asali_->transport_[6].MW = 39.948;
		
		asali_->transport_[7].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[7].name,"C6H5CH2OH");
		asali_->transport_[7].geometry = 2;
		asali_->transport_[7].LJpotential = 622.400;
		asali_->transport_[7].LJdiameter =  5.530;
		asali_->transport_[7].dipole =  0.000;
		asali_->transport_[7].polar =  0.000;
		asali_->transport_[7].collision =  1.000;
		asali_->transport_[7].MW = 108.140;
		
		asali_->transport_[8].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[8].name,"C6H4O2");
		asali_->transport_[8].geometry = 2;
		asali_->transport_[8].LJpotential = 450.000;
		asali_->transport_[8].LJdiameter =  5.500;
		asali_->transport_[8].dipole =  0.000;
		asali_->transport_[8].polar =  0.000;
		asali_->transport_[8].collision =  1.000;
		asali_->transport_[8].MW = 108.097;
		
		asali_->transport_[9].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[9].name,"C6H6");
		asali_->transport_[9].geometry = 2;
		asali_->transport_[9].LJpotential = 468.500;
		asali_->transport_[9].LJdiameter =  5.230;
		asali_->transport_[9].dipole =  0.000;
		asali_->transport_[9].polar = 10.300;
		asali_->transport_[9].collision =  1.000;
		asali_->transport_[9].MW = 78.114;
		
		asali_->transport_[10].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[10].name,"C6H5CHO");
		asali_->transport_[10].geometry = 2;
		asali_->transport_[10].LJpotential = 622.400;
		asali_->transport_[10].LJdiameter =  5.530;
		asali_->transport_[10].dipole =  0.000;
		asali_->transport_[10].polar =  0.000;
		asali_->transport_[10].collision =  1.000;
		asali_->transport_[10].MW = 106.124;
		
		asali_->transport_[11].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->transport_[11].name,"C6H5C2H4C6H5");
		asali_->transport_[11].geometry = 2;
		asali_->transport_[11].LJpotential = 783.800;
		asali_->transport_[11].LJdiameter =  6.640;
		asali_->transport_[11].dipole =  0.000;
		asali_->transport_[11].polar =  0.000;
		asali_->transport_[11].collision =  1.000;
		asali_->transport_[11].MW = 182.265;
		
		asali_->transport_[12].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[12].name,"NC4H8");
		asali_->transport_[12].geometry = 2;
		asali_->transport_[12].LJpotential = 355.000;
		asali_->transport_[12].LJdiameter =  4.650;
		asali_->transport_[12].dipole =  0.000;
		asali_->transport_[12].polar =  0.000;
		asali_->transport_[12].collision =  1.000;
		asali_->transport_[12].MW = 56.107;
		
		asali_->transport_[13].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[13].name,"C4H6");
		asali_->transport_[13].geometry = 2;
		asali_->transport_[13].LJpotential = 357.000;
		asali_->transport_[13].LJdiameter =  5.180;
		asali_->transport_[13].dipole =  0.000;
		asali_->transport_[13].polar =  0.000;
		asali_->transport_[13].collision =  1.000;
		asali_->transport_[13].MW = 54.092;
		
		asali_->transport_[14].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[14].name,"C12H8");
		asali_->transport_[14].geometry = 2;
		asali_->transport_[14].LJpotential = 689.800;
		asali_->transport_[14].LJdiameter =  6.500;
		asali_->transport_[14].dipole =  0.000;
		asali_->transport_[14].polar =  0.000;
		asali_->transport_[14].collision =  1.000;
		asali_->transport_[14].MW = 152.196;
		
		asali_->transport_[15].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[15].name,"C2H2");
		asali_->transport_[15].geometry = 1;
		asali_->transport_[15].LJpotential = 209.000;
		asali_->transport_[15].LJdiameter =  4.100;
		asali_->transport_[15].dipole =  0.000;
		asali_->transport_[15].polar =  0.000;
		asali_->transport_[15].collision =  2.500;
		asali_->transport_[15].MW = 26.038;
		
		asali_->transport_[16].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[16].name,"C2H4");
		asali_->transport_[16].geometry = 2;
		asali_->transport_[16].LJpotential = 280.800;
		asali_->transport_[16].LJdiameter =  3.971;
		asali_->transport_[16].dipole =  0.000;
		asali_->transport_[16].polar =  0.000;
		asali_->transport_[16].collision =  1.500;
		asali_->transport_[16].MW = 28.054;
		
		asali_->transport_[17].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[17].name,"C2H6");
		asali_->transport_[17].geometry = 2;
		asali_->transport_[17].LJpotential = 252.300;
		asali_->transport_[17].LJdiameter =  4.302;
		asali_->transport_[17].dipole =  0.000;
		asali_->transport_[17].polar =  0.000;
		asali_->transport_[17].collision =  1.500;
		asali_->transport_[17].MW = 30.070;
		
		asali_->transport_[18].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[18].name,"C3H6");
		asali_->transport_[18].geometry = 2;
		asali_->transport_[18].LJpotential = 307.800;
		asali_->transport_[18].LJdiameter =  4.140;
		asali_->transport_[18].dipole =  0.000;
		asali_->transport_[18].polar =  0.000;
		asali_->transport_[18].collision =  1.000;
		asali_->transport_[18].MW = 42.081;
		
		asali_->transport_[19].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[19].name,"C3H8");
		asali_->transport_[19].geometry = 2;
		asali_->transport_[19].LJpotential = 303.400;
		asali_->transport_[19].LJdiameter =  4.810;
		asali_->transport_[19].dipole =  0.000;
		asali_->transport_[19].polar =  0.000;
		asali_->transport_[19].collision =  1.000;
		asali_->transport_[19].MW = 44.097;
		
		asali_->transport_[20].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[20].name,"C4H2");
		asali_->transport_[20].geometry = 1;
		asali_->transport_[20].LJpotential = 357.000;
		asali_->transport_[20].LJdiameter =  5.180;
		asali_->transport_[20].dipole =  0.000;
		asali_->transport_[20].polar =  0.000;
		asali_->transport_[20].collision =  1.000;
		asali_->transport_[20].MW = 50.060;
		
		asali_->transport_[21].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[21].name,"C4H4");
		asali_->transport_[21].geometry = 2;
		asali_->transport_[21].LJpotential = 357.000;
		asali_->transport_[21].LJdiameter =  5.180;
		asali_->transport_[21].dipole =  0.000;
		asali_->transport_[21].polar =  0.000;
		asali_->transport_[21].collision =  1.000;
		asali_->transport_[21].MW = 52.076;
		
		asali_->transport_[22].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[22].name,"CYC5H4O");
		asali_->transport_[22].geometry = 2;
		asali_->transport_[22].LJpotential = 450.000;
		asali_->transport_[22].LJdiameter =  5.500;
		asali_->transport_[22].dipole =  0.000;
		asali_->transport_[22].polar =  0.000;
		asali_->transport_[22].collision =  1.000;
		asali_->transport_[22].MW = 80.086;
		
		asali_->transport_[23].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[23].name,"C6H5O");
		asali_->transport_[23].geometry = 2;
		asali_->transport_[23].LJpotential = 450.000;
		asali_->transport_[23].LJdiameter =  5.500;
		asali_->transport_[23].dipole =  0.000;
		asali_->transport_[23].polar =  0.000;
		asali_->transport_[23].collision =  1.000;
		asali_->transport_[23].MW = 93.105;
		
		asali_->transport_[24].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[24].name,"CYC6H10-ONE");
		asali_->transport_[24].geometry = 2;
		asali_->transport_[24].LJpotential = 568.500;
		asali_->transport_[24].LJdiameter =  5.230;
		asali_->transport_[24].dipole =  0.000;
		asali_->transport_[24].polar = 10.300;
		asali_->transport_[24].collision =  1.000;
		asali_->transport_[24].MW = 98.145;
		
		asali_->transport_[25].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[25].name,"CYC5H8");
		asali_->transport_[25].geometry = 1;
		asali_->transport_[25].LJpotential = 408.000;
		asali_->transport_[25].LJdiameter =  5.200;
		asali_->transport_[25].dipole =  0.000;
		asali_->transport_[25].polar =  0.000;
		asali_->transport_[25].collision =  1.000;
		asali_->transport_[25].MW = 68.118;
		
		asali_->transport_[26].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[26].name,"CYC6H8");
		asali_->transport_[26].geometry = 2;
		asali_->transport_[26].LJpotential = 468.500;
		asali_->transport_[26].LJdiameter =  5.230;
		asali_->transport_[26].dipole =  0.000;
		asali_->transport_[26].polar = 10.300;
		asali_->transport_[26].collision =  1.000;
		asali_->transport_[26].MW = 80.130;
		
		asali_->transport_[27].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[27].name,"CYC6H12");
		asali_->transport_[27].geometry = 2;
		asali_->transport_[27].LJpotential = 468.500;
		asali_->transport_[27].LJdiameter =  5.230;
		asali_->transport_[27].dipole =  0.000;
		asali_->transport_[27].polar = 10.300;
		asali_->transport_[27].collision =  1.000;
		asali_->transport_[27].MW = 84.161;
		
		asali_->transport_[28].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[28].name,"CYC6H10");
		asali_->transport_[28].geometry = 2;
		asali_->transport_[28].LJpotential = 468.500;
		asali_->transport_[28].LJdiameter =  5.230;
		asali_->transport_[28].dipole =  0.000;
		asali_->transport_[28].polar = 10.300;
		asali_->transport_[28].collision =  1.000;
		asali_->transport_[28].MW = 82.145;
		
		asali_->transport_[29].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[29].name,"CH2CO");
		asali_->transport_[29].geometry = 2;
		asali_->transport_[29].LJpotential = 436.000;
		asali_->transport_[29].LJdiameter =  3.970;
		asali_->transport_[29].dipole =  0.000;
		asali_->transport_[29].polar =  0.000;
		asali_->transport_[29].collision =  2.000;
		asali_->transport_[29].MW = 42.037;
		
		asali_->transport_[30].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[30].name,"CH2O");
		asali_->transport_[30].geometry = 2;
		asali_->transport_[30].LJpotential = 498.000;
		asali_->transport_[30].LJdiameter =  3.590;
		asali_->transport_[30].dipole =  0.000;
		asali_->transport_[30].polar =  0.000;
		asali_->transport_[30].collision =  2.000;
		asali_->transport_[30].MW = 30.026;
		
		asali_->transport_[31].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[31].name,"CH3OH");
		asali_->transport_[31].geometry = 2;
		asali_->transport_[31].LJpotential = 481.800;
		asali_->transport_[31].LJdiameter =  3.626;
		asali_->transport_[31].dipole =  0.000;
		asali_->transport_[31].polar =  0.000;
		asali_->transport_[31].collision =  1.000;
		asali_->transport_[31].MW = 32.042;
		
		asali_->transport_[32].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[32].name,"CH4");
		asali_->transport_[32].geometry = 2;
		asali_->transport_[32].LJpotential = 141.400;
		asali_->transport_[32].LJdiameter =  3.746;
		asali_->transport_[32].dipole =  0.000;
		asali_->transport_[32].polar =  2.600;
		asali_->transport_[32].collision = 13.000;
		asali_->transport_[32].MW = 16.043;
		
		asali_->transport_[33].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->transport_[33].name,"CO");
		asali_->transport_[33].geometry = 1;
		asali_->transport_[33].LJpotential = 98.100;
		asali_->transport_[33].LJdiameter =  3.650;
		asali_->transport_[33].dipole =  0.000;
		asali_->transport_[33].polar =  1.950;
		asali_->transport_[33].collision =  1.800;
		asali_->transport_[33].MW = 28.010;
		
		asali_->transport_[34].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[34].name,"CO2");
		asali_->transport_[34].geometry = 1;
		asali_->transport_[34].LJpotential = 244.000;
		asali_->transport_[34].LJdiameter =  3.763;
		asali_->transport_[34].dipole =  0.000;
		asali_->transport_[34].polar =  2.650;
		asali_->transport_[34].collision =  2.100;
		asali_->transport_[34].MW = 44.010;
		
		asali_->transport_[35].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[35].name,"CYC5H6");
		asali_->transport_[35].geometry = 2;
		asali_->transport_[35].LJpotential = 408.000;
		asali_->transport_[35].LJdiameter =  5.200;
		asali_->transport_[35].dipole =  0.000;
		asali_->transport_[35].polar =  0.000;
		asali_->transport_[35].collision =  1.000;
		asali_->transport_[35].MW = 66.103;
		
		asali_->transport_[36].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[36].name,"MCPTD");
		asali_->transport_[36].geometry = 2;
		asali_->transport_[36].LJpotential = 408.000;
		asali_->transport_[36].LJdiameter =  5.200;
		asali_->transport_[36].dipole =  0.000;
		asali_->transport_[36].polar =  0.000;
		asali_->transport_[36].collision =  1.000;
		asali_->transport_[36].MW = 80.130;
		
		asali_->transport_[37].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[37].name,"CRESOL");
		asali_->transport_[37].geometry = 2;
		asali_->transport_[37].LJpotential = 621.100;
		asali_->transport_[37].LJdiameter =  5.640;
		asali_->transport_[37].dipole =  0.000;
		asali_->transport_[37].polar =  0.000;
		asali_->transport_[37].collision =  1.000;
		asali_->transport_[37].MW = 108.140;
		
		asali_->transport_[38].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[38].name,"NC10H20");
		asali_->transport_[38].geometry = 2;
		asali_->transport_[38].LJpotential = 540.980;
		asali_->transport_[38].LJdiameter =  7.150;
		asali_->transport_[38].dipole =  0.000;
		asali_->transport_[38].polar =  0.000;
		asali_->transport_[38].collision =  1.000;
		asali_->transport_[38].MW = 140.269;
		
		asali_->transport_[39].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[39].name,"C6H5CH2C6H5");
		asali_->transport_[39].geometry = 2;
		asali_->transport_[39].LJpotential = 712.600;
		asali_->transport_[39].LJdiameter =  6.890;
		asali_->transport_[39].dipole =  0.000;
		asali_->transport_[39].polar =  0.000;
		asali_->transport_[39].collision =  1.000;
		asali_->transport_[39].MW = 168.238;
		
		asali_->transport_[40].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[40].name,"DIPE");
		asali_->transport_[40].geometry = 2;
		asali_->transport_[40].LJpotential = 432.000;
		asali_->transport_[40].LJdiameter =  6.000;
		asali_->transport_[40].dipole =  0.000;
		asali_->transport_[40].polar =  0.000;
		asali_->transport_[40].collision =  1.000;
		asali_->transport_[40].MW = 102.177;
		
		asali_->transport_[41].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[41].name,"CH3OCH3");
		asali_->transport_[41].geometry = 2;
		asali_->transport_[41].LJpotential = 303.400;
		asali_->transport_[41].LJdiameter =  4.810;
		asali_->transport_[41].dipole =  0.000;
		asali_->transport_[41].polar =  0.000;
		asali_->transport_[41].collision =  1.000;
		asali_->transport_[41].MW = 46.069;
		
		asali_->transport_[42].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[42].name,"CH3CH3-C5H6");
		asali_->transport_[42].geometry = 2;
		asali_->transport_[42].LJpotential = 450.000;
		asali_->transport_[42].LJdiameter =  5.500;
		asali_->transport_[42].dipole =  0.000;
		asali_->transport_[42].polar =  0.000;
		asali_->transport_[42].collision =  1.000;
		asali_->transport_[42].MW = 96.172;
		
		asali_->transport_[43].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[43].name,"C6H5C2H5");
		asali_->transport_[43].geometry = 2;
		asali_->transport_[43].LJpotential = 523.600;
		asali_->transport_[43].LJdiameter =  5.960;
		asali_->transport_[43].dipole =  0.000;
		asali_->transport_[43].polar =  0.000;
		asali_->transport_[43].collision =  1.000;
		asali_->transport_[43].MW = 106.167;
		
		asali_->transport_[44].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[44].name,"NC7H14");
		asali_->transport_[44].geometry = 2;
		asali_->transport_[44].LJpotential = 459.980;
		asali_->transport_[44].LJdiameter =  6.310;
		asali_->transport_[44].dipole =  0.000;
		asali_->transport_[44].polar =  0.000;
		asali_->transport_[44].collision =  1.000;
		asali_->transport_[44].MW = 98.188;
		
		asali_->transport_[45].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[45].name,"NC6H12");
		asali_->transport_[45].geometry = 2;
		asali_->transport_[45].LJpotential = 412.300;
		asali_->transport_[45].LJdiameter =  5.349;
		asali_->transport_[45].dipole =  0.000;
		asali_->transport_[45].polar =  0.000;
		asali_->transport_[45].collision =  1.000;
		asali_->transport_[45].MW = 84.161;
		
		asali_->transport_[46].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[46].name,"C5H9CHO");
		asali_->transport_[46].geometry = 2;
		asali_->transport_[46].LJpotential = 568.500;
		asali_->transport_[46].LJdiameter =  5.230;
		asali_->transport_[46].dipole =  0.000;
		asali_->transport_[46].polar = 10.300;
		asali_->transport_[46].collision =  1.000;
		asali_->transport_[46].MW = 98.145;
		
		asali_->transport_[47].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[47].name,"ETBE");
		asali_->transport_[47].geometry = 2;
		asali_->transport_[47].LJpotential = 432.000;
		asali_->transport_[47].LJdiameter =  6.000;
		asali_->transport_[47].dipole =  0.000;
		asali_->transport_[47].polar =  0.000;
		asali_->transport_[47].collision =  1.000;
		asali_->transport_[47].MW = 102.177;
		
		asali_->transport_[48].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[48].name,"C2H5OH");
		asali_->transport_[48].geometry = 2;
		asali_->transport_[48].LJpotential = 362.600;
		asali_->transport_[48].LJdiameter =  4.530;
		asali_->transport_[48].dipole =  0.000;
		asali_->transport_[48].polar =  0.000;
		asali_->transport_[48].collision =  1.500;
		asali_->transport_[48].MW = 46.069;
		
		asali_->transport_[49].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[49].name,"C2H5OOH");
		asali_->transport_[49].geometry = 2;
		asali_->transport_[49].LJpotential = 362.600;
		asali_->transport_[49].LJdiameter =  4.530;
		asali_->transport_[49].dipole =  0.000;
		asali_->transport_[49].polar =  0.000;
		asali_->transport_[49].collision =  1.500;
		asali_->transport_[49].MW = 62.068;
		
		asali_->transport_[50].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[50].name,"C2H4O");
		asali_->transport_[50].geometry = 2;
		asali_->transport_[50].LJpotential = 362.600;
		asali_->transport_[50].LJdiameter =  4.530;
		asali_->transport_[50].dipole =  0.000;
		asali_->transport_[50].polar =  0.000;
		asali_->transport_[50].collision =  1.500;
		asali_->transport_[50].MW = 44.053;
		
		asali_->transport_[51].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[51].name,"C6H5C2H");
		asali_->transport_[51].geometry = 2;
		asali_->transport_[51].LJpotential = 534.300;
		asali_->transport_[51].LJdiameter =  5.710;
		asali_->transport_[51].dipole =  0.770;
		asali_->transport_[51].polar =  0.000;
		asali_->transport_[51].collision =  1.000;
		asali_->transport_[51].MW = 102.136;
		
		asali_->transport_[52].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[52].name,"BIPHENYL");
		asali_->transport_[52].geometry = 2;
		asali_->transport_[52].LJpotential = 676.500;
		asali_->transport_[52].LJdiameter =  6.310;
		asali_->transport_[52].dipole =  0.000;
		asali_->transport_[52].polar =  0.000;
		asali_->transport_[52].collision =  1.000;
		asali_->transport_[52].MW = 154.211;
		
		asali_->transport_[53].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[53].name,"C14H10");
		asali_->transport_[53].geometry = 2;
		asali_->transport_[53].LJpotential = 772.000;
		asali_->transport_[53].LJdiameter =  6.960;
		asali_->transport_[53].dipole =  0.000;
		asali_->transport_[53].polar = 38.800;
		asali_->transport_[53].collision =  1.000;
		asali_->transport_[53].MW = 178.233;
		
		asali_->transport_[54].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[54].name,"C6H5OH");
		asali_->transport_[54].geometry = 2;
		asali_->transport_[54].LJpotential = 450.000;
		asali_->transport_[54].LJdiameter =  5.500;
		asali_->transport_[54].dipole =  0.000;
		asali_->transport_[54].polar =  0.000;
		asali_->transport_[54].collision =  1.000;
		asali_->transport_[54].MW = 94.113;
		
		asali_->transport_[55].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[55].name,"FLUORENE");
		asali_->transport_[55].geometry = 2;
		asali_->transport_[55].LJpotential = 712.600;
		asali_->transport_[55].LJdiameter =  6.890;
		asali_->transport_[55].dipole =  0.000;
		asali_->transport_[55].polar =  0.000;
		asali_->transport_[55].collision =  1.000;
		asali_->transport_[55].MW = 166.222;
		
		asali_->transport_[56].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[56].name,"C10H8");
		asali_->transport_[56].geometry = 2;
		asali_->transport_[56].LJpotential = 630.400;
		asali_->transport_[56].LJdiameter =  6.180;
		asali_->transport_[56].dipole =  0.000;
		asali_->transport_[56].polar = 16.500;
		asali_->transport_[56].collision =  1.000;
		asali_->transport_[56].MW = 128.174;
		
		asali_->transport_[57].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->transport_[57].name,"H2");
		asali_->transport_[57].geometry = 1;
		asali_->transport_[57].LJpotential = 38.000;
		asali_->transport_[57].LJdiameter =  2.920;
		asali_->transport_[57].dipole =  0.000;
		asali_->transport_[57].polar =  0.790;
		asali_->transport_[57].collision = 280.000;
		asali_->transport_[57].MW =  2.016;
		
		asali_->transport_[58].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[58].name,"H2O");
		asali_->transport_[58].geometry = 2;
		asali_->transport_[58].LJpotential = 572.400;
		asali_->transport_[58].LJdiameter =  2.605;
		asali_->transport_[58].dipole =  1.844;
		asali_->transport_[58].polar =  0.000;
		asali_->transport_[58].collision =  4.000;
		asali_->transport_[58].MW = 18.015;
		
		asali_->transport_[59].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[59].name,"H2O2");
		asali_->transport_[59].geometry = 2;
		asali_->transport_[59].LJpotential = 107.400;
		asali_->transport_[59].LJdiameter =  3.458;
		asali_->transport_[59].dipole =  0.000;
		asali_->transport_[59].polar =  0.000;
		asali_->transport_[59].collision =  3.800;
		asali_->transport_[59].MW = 34.015;
		
		asali_->transport_[60].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->transport_[60].name,"HE");
		asali_->transport_[60].geometry = 0;
		asali_->transport_[60].LJpotential = 10.200;
		asali_->transport_[60].LJdiameter =  2.576;
		asali_->transport_[60].dipole =  0.000;
		asali_->transport_[60].polar =  0.000;
		asali_->transport_[60].collision =  0.000;
		asali_->transport_[60].MW =  4.003;
		
		asali_->transport_[61].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[61].name,"IC4H8");
		asali_->transport_[61].geometry = 2;
		asali_->transport_[61].LJpotential = 355.000;
		asali_->transport_[61].LJdiameter =  4.650;
		asali_->transport_[61].dipole =  0.000;
		asali_->transport_[61].polar =  0.000;
		asali_->transport_[61].collision =  1.000;
		asali_->transport_[61].MW = 56.107;
		
		asali_->transport_[62].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[62].name,"IC3H7CHO");
		asali_->transport_[62].geometry = 2;
		asali_->transport_[62].LJpotential = 455.000;
		asali_->transport_[62].LJdiameter =  4.650;
		asali_->transport_[62].dipole =  0.000;
		asali_->transport_[62].polar =  0.000;
		asali_->transport_[62].collision =  1.000;
		asali_->transport_[62].MW = 72.107;
		
		asali_->transport_[63].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[63].name,"IC4H10");
		asali_->transport_[63].geometry = 2;
		asali_->transport_[63].LJpotential = 352.000;
		asali_->transport_[63].LJdiameter =  5.240;
		asali_->transport_[63].dipole =  0.000;
		asali_->transport_[63].polar =  0.000;
		asali_->transport_[63].collision =  1.000;
		asali_->transport_[63].MW = 58.123;
		
		asali_->transport_[64].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[64].name,"IC8H18");
		asali_->transport_[64].geometry = 2;
		asali_->transport_[64].LJpotential = 494.000;
		asali_->transport_[64].LJdiameter =  6.170;
		asali_->transport_[64].dipole =  0.000;
		asali_->transport_[64].polar =  0.000;
		asali_->transport_[64].collision =  1.000;
		asali_->transport_[64].MW = 114.231;
		
		asali_->transport_[65].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[65].name,"INDENE");
		asali_->transport_[65].geometry = 2;
		asali_->transport_[65].LJpotential = 588.600;
		asali_->transport_[65].LJdiameter =  5.960;
		asali_->transport_[65].dipole =  0.650;
		asali_->transport_[65].polar =  0.000;
		asali_->transport_[65].collision =  1.000;
		asali_->transport_[65].MW = 116.163;
		
		asali_->transport_[66].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[66].name,"IC3H7OH");
		asali_->transport_[66].geometry = 2;
		asali_->transport_[66].LJpotential = 482.147;
		asali_->transport_[66].LJdiameter =  5.009;
		asali_->transport_[66].dipole =  1.660;
		asali_->transport_[66].polar =  6.740;
		asali_->transport_[66].collision =  1.000;
		asali_->transport_[66].MW = 60.096;
		
		asali_->transport_[67].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[67].name,"IC5H10");
		asali_->transport_[67].geometry = 2;
		asali_->transport_[67].LJpotential = 408.000;
		asali_->transport_[67].LJdiameter =  5.200;
		asali_->transport_[67].dipole =  0.000;
		asali_->transport_[67].polar =  0.000;
		asali_->transport_[67].collision =  1.000;
		asali_->transport_[67].MW = 70.134;
		
		asali_->transport_[68].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[68].name,"IC3H5CHO");
		asali_->transport_[68].geometry = 2;
		asali_->transport_[68].LJpotential = 357.000;
		asali_->transport_[68].LJdiameter =  5.180;
		asali_->transport_[68].dipole =  0.000;
		asali_->transport_[68].polar =  0.000;
		asali_->transport_[68].collision =  1.000;
		asali_->transport_[68].MW = 70.091;
		
		asali_->transport_[69].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[69].name,"MCYC6");
		asali_->transport_[69].geometry = 2;
		asali_->transport_[69].LJpotential = 495.300;
		asali_->transport_[69].LJdiameter =  5.680;
		asali_->transport_[69].dipole =  0.430;
		asali_->transport_[69].polar = 12.300;
		asali_->transport_[69].collision =  1.000;
		asali_->transport_[69].MW = 98.188;
		
		asali_->transport_[70].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[70].name,"CH3CHO");
		asali_->transport_[70].geometry = 2;
		asali_->transport_[70].LJpotential = 436.000;
		asali_->transport_[70].LJdiameter =  3.970;
		asali_->transport_[70].dipole =  0.000;
		asali_->transport_[70].polar =  0.000;
		asali_->transport_[70].collision =  2.000;
		asali_->transport_[70].MW = 44.053;
		
		asali_->transport_[71].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[71].name,"C10H7CH3");
		asali_->transport_[71].geometry = 2;
		asali_->transport_[71].LJpotential = 660.000;
		asali_->transport_[71].LJdiameter =  6.350;
		asali_->transport_[71].dipole =  0.000;
		asali_->transport_[71].polar =  0.000;
		asali_->transport_[71].collision =  1.000;
		asali_->transport_[71].MW = 142.200;
		
		asali_->transport_[72].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[72].name,"CH3OOH");
		asali_->transport_[72].geometry = 2;
		asali_->transport_[72].LJpotential = 481.800;
		asali_->transport_[72].LJdiameter =  3.626;
		asali_->transport_[72].dipole =  0.000;
		asali_->transport_[72].polar =  0.000;
		asali_->transport_[72].collision =  1.000;
		asali_->transport_[72].MW = 48.042;
		
		asali_->transport_[73].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[73].name,"MTBE");
		asali_->transport_[73].geometry = 2;
		asali_->transport_[73].LJpotential = 392.000;
		asali_->transport_[73].LJdiameter =  5.640;
		asali_->transport_[73].dipole =  0.000;
		asali_->transport_[73].polar =  0.000;
		asali_->transport_[73].collision =  1.000;
		asali_->transport_[73].MW = 88.150;
		
		asali_->transport_[74].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->transport_[74].name,"N2");
		asali_->transport_[74].geometry = 1;
		asali_->transport_[74].LJpotential = 97.530;
		asali_->transport_[74].LJdiameter =  3.621;
		asali_->transport_[74].dipole =  0.000;
		asali_->transport_[74].polar =  1.760;
		asali_->transport_[74].collision =  4.000;
		asali_->transport_[74].MW = 28.014;
		
		asali_->transport_[75].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[75].name,"C10H7OH");
		asali_->transport_[75].geometry = 2;
		asali_->transport_[75].LJpotential = 663.450;
		asali_->transport_[75].LJdiameter =  6.362;
		asali_->transport_[75].dipole =  0.000;
		asali_->transport_[75].polar =  0.000;
		asali_->transport_[75].collision =  1.000;
		asali_->transport_[75].MW = 144.173;
		
		asali_->transport_[76].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[76].name,"C10H7CHO");
		asali_->transport_[76].geometry = 2;
		asali_->transport_[76].LJpotential = 663.450;
		asali_->transport_[76].LJdiameter =  6.362;
		asali_->transport_[76].dipole =  0.000;
		asali_->transport_[76].polar =  0.000;
		asali_->transport_[76].collision =  1.000;
		asali_->transport_[76].MW = 156.184;
		
		asali_->transport_[77].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[77].name,"NC4H10");
		asali_->transport_[77].geometry = 2;
		asali_->transport_[77].LJpotential = 352.000;
		asali_->transport_[77].LJdiameter =  5.240;
		asali_->transport_[77].dipole =  0.000;
		asali_->transport_[77].polar =  0.000;
		asali_->transport_[77].collision =  1.000;
		asali_->transport_[77].MW = 58.123;
		
		asali_->transport_[78].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[78].name,"NC10H22");
		asali_->transport_[78].geometry = 2;
		asali_->transport_[78].LJpotential = 540.980;
		asali_->transport_[78].LJdiameter =  7.150;
		asali_->transport_[78].dipole =  0.000;
		asali_->transport_[78].polar =  0.000;
		asali_->transport_[78].collision =  1.000;
		asali_->transport_[78].MW = 142.285;
		
		asali_->transport_[79].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[79].name,"NC12H26");
		asali_->transport_[79].geometry = 2;
		asali_->transport_[79].LJpotential = 580.000;
		asali_->transport_[79].LJdiameter =  7.600;
		asali_->transport_[79].dipole =  0.000;
		asali_->transport_[79].polar =  0.000;
		asali_->transport_[79].collision =  1.000;
		asali_->transport_[79].MW = 170.338;
		
		asali_->transport_[80].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[80].name,"NC5H12");
		asali_->transport_[80].geometry = 2;
		asali_->transport_[80].LJpotential = 392.000;
		asali_->transport_[80].LJdiameter =  5.640;
		asali_->transport_[80].dipole =  0.000;
		asali_->transport_[80].polar =  0.000;
		asali_->transport_[80].collision =  1.000;
		asali_->transport_[80].MW = 72.150;
		
		asali_->transport_[81].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[81].name,"NC7H16");
		asali_->transport_[81].geometry = 2;
		asali_->transport_[81].LJpotential = 459.980;
		asali_->transport_[81].LJdiameter =  6.310;
		asali_->transport_[81].dipole =  0.000;
		asali_->transport_[81].polar =  0.000;
		asali_->transport_[81].collision =  1.000;
		asali_->transport_[81].MW = 100.204;
		
		asali_->transport_[82].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[82].name,"NEOC5H12");
		asali_->transport_[82].geometry = 2;
		asali_->transport_[82].LJpotential = 392.000;
		asali_->transport_[82].LJdiameter =  5.640;
		asali_->transport_[82].dipole =  0.000;
		asali_->transport_[82].polar =  0.000;
		asali_->transport_[82].collision =  1.000;
		asali_->transport_[82].MW = 72.150;
		
		asali_->transport_[83].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->transport_[83].name,"O2");
		asali_->transport_[83].geometry = 1;
		asali_->transport_[83].LJpotential = 107.400;
		asali_->transport_[83].LJdiameter =  3.458;
		asali_->transport_[83].dipole =  0.000;
		asali_->transport_[83].polar =  1.600;
		asali_->transport_[83].collision =  3.800;
		asali_->transport_[83].MW = 31.999;
		
		asali_->transport_[84].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[84].name,"IC8H16");
		asali_->transport_[84].geometry = 2;
		asali_->transport_[84].LJpotential = 494.000;
		asali_->transport_[84].LJdiameter =  6.170;
		asali_->transport_[84].dipole =  0.000;
		asali_->transport_[84].polar =  0.000;
		asali_->transport_[84].collision =  1.000;
		asali_->transport_[84].MW = 112.215;
		
		asali_->transport_[85].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[85].name,"NC5H10");
		asali_->transport_[85].geometry = 2;
		asali_->transport_[85].LJpotential = 408.000;
		asali_->transport_[85].LJdiameter =  5.200;
		asali_->transport_[85].dipole =  0.000;
		asali_->transport_[85].polar =  0.000;
		asali_->transport_[85].collision =  1.000;
		asali_->transport_[85].MW = 70.134;
		
		asali_->transport_[86].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[86].name,"PC3H4");
		asali_->transport_[86].geometry = 1;
		asali_->transport_[86].LJpotential = 252.000;
		asali_->transport_[86].LJdiameter =  4.760;
		asali_->transport_[86].dipole =  0.000;
		asali_->transport_[86].polar =  0.000;
		asali_->transport_[86].collision =  1.000;
		asali_->transport_[86].MW = 40.065;
		
		asali_->transport_[87].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[87].name,"CH3CO3H");
		asali_->transport_[87].geometry = 2;
		asali_->transport_[87].LJpotential = 443.200;
		asali_->transport_[87].LJdiameter =  4.120;
		asali_->transport_[87].dipole =  0.000;
		asali_->transport_[87].polar =  0.000;
		asali_->transport_[87].collision =  1.000;
		asali_->transport_[87].MW = 76.052;
		
		asali_->transport_[88].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[88].name,"HCO3H");
		asali_->transport_[88].geometry = 2;
		asali_->transport_[88].LJpotential = 443.200;
		asali_->transport_[88].LJdiameter =  4.120;
		asali_->transport_[88].dipole =  0.000;
		asali_->transport_[88].polar =  0.000;
		asali_->transport_[88].collision =  1.000;
		asali_->transport_[88].MW = 62.025;
		
		asali_->transport_[89].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[89].name,"C3H6O");
		asali_->transport_[89].geometry = 2;
		asali_->transport_[89].LJpotential = 411.000;
		asali_->transport_[89].LJdiameter =  4.820;
		asali_->transport_[89].dipole =  0.000;
		asali_->transport_[89].polar =  0.000;
		asali_->transport_[89].collision =  1.000;
		asali_->transport_[89].MW = 58.080;
		
		asali_->transport_[90].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[90].name,"C5H8");
		asali_->transport_[90].geometry = 2;
		asali_->transport_[90].LJpotential = 408.000;
		asali_->transport_[90].LJdiameter =  5.200;
		asali_->transport_[90].dipole =  0.000;
		asali_->transport_[90].polar =  0.000;
		asali_->transport_[90].collision =  1.000;
		asali_->transport_[90].MW = 68.118;
		
		asali_->transport_[91].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[91].name,"C16H10");
		asali_->transport_[91].geometry = 2;
		asali_->transport_[91].LJpotential = 834.900;
		asali_->transport_[91].LJdiameter =  7.240;
		asali_->transport_[91].dipole =  0.000;
		asali_->transport_[91].polar = 45.000;
		asali_->transport_[91].collision =  1.000;
		asali_->transport_[91].MW = 202.255;
		
		asali_->transport_[92].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[92].name,"C6H5C2H3");
		asali_->transport_[92].geometry = 2;
		asali_->transport_[92].LJpotential = 546.200;
		asali_->transport_[92].LJdiameter =  6.000;
		asali_->transport_[92].dipole =  0.130;
		asali_->transport_[92].polar = 15.000;
		asali_->transport_[92].collision =  1.000;
		asali_->transport_[92].MW = 104.152;
		
		asali_->transport_[93].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[93].name,"TAME");
		asali_->transport_[93].geometry = 2;
		asali_->transport_[93].LJpotential = 432.000;
		asali_->transport_[93].LJdiameter =  6.000;
		asali_->transport_[93].dipole =  0.000;
		asali_->transport_[93].polar =  0.000;
		asali_->transport_[93].collision =  1.000;
		asali_->transport_[93].MW = 102.177;
		
		asali_->transport_[94].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[94].name,"TETRALIN");
		asali_->transport_[94].geometry = 2;
		asali_->transport_[94].LJpotential = 630.400;
		asali_->transport_[94].LJdiameter =  6.180;
		asali_->transport_[94].dipole =  0.000;
		asali_->transport_[94].polar = 16.500;
		asali_->transport_[94].collision =  1.000;
		asali_->transport_[94].MW = 132.205;
		
		asali_->transport_[95].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[95].name,"DECALIN");
		asali_->transport_[95].geometry = 2;
		asali_->transport_[95].LJpotential = 630.400;
		asali_->transport_[95].LJdiameter =  6.180;
		asali_->transport_[95].dipole =  0.000;
		asali_->transport_[95].polar = 16.500;
		asali_->transport_[95].collision =  1.000;
		asali_->transport_[95].MW = 138.253;
		
		asali_->transport_[96].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[96].name,"C7H8");
		asali_->transport_[96].geometry = 2;
		asali_->transport_[96].LJpotential = 495.300;
		asali_->transport_[96].LJdiameter =  5.680;
		asali_->transport_[96].dipole =  0.430;
		asali_->transport_[96].polar = 12.300;
		asali_->transport_[96].collision =  1.000;
		asali_->transport_[96].MW = 92.141;
		
		asali_->transport_[97].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[97].name,"XYLENE");
		asali_->transport_[97].geometry = 2;
		asali_->transport_[97].LJpotential = 523.600;
		asali_->transport_[97].LJdiameter =  5.960;
		asali_->transport_[97].dipole =  0.000;
		asali_->transport_[97].polar =  0.000;
		asali_->transport_[97].collision =  1.000;
		asali_->transport_[97].MW = 106.167;
		
		asali_->transport_[98].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[98].name,"NC16H34");
		asali_->transport_[98].geometry = 2;
		asali_->transport_[98].LJpotential = 650.000;
		asali_->transport_[98].LJdiameter =  8.350;
		asali_->transport_[98].dipole =  0.000;
		asali_->transport_[98].polar =  0.000;
		asali_->transport_[98].collision =  1.000;
		asali_->transport_[98].MW = 226.446;
		
		asali_->transport_[99].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[99].name,"N2H4");
		asali_->transport_[99].geometry = 2;
		asali_->transport_[99].LJpotential = 205.000;
		asali_->transport_[99].LJdiameter =  4.230;
		asali_->transport_[99].dipole =  0.000;
		asali_->transport_[99].polar =  4.260;
		asali_->transport_[99].collision =  1.500;
		asali_->transport_[99].MW = 32.045;
		
		asali_->transport_[100].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[100].name,"N2O");
		asali_->transport_[100].geometry = 1;
		asali_->transport_[100].LJpotential = 232.400;
		asali_->transport_[100].LJdiameter =  3.828;
		asali_->transport_[100].dipole =  0.000;
		asali_->transport_[100].polar =  0.000;
		asali_->transport_[100].collision =  1.000;
		asali_->transport_[100].MW = 44.013;
		
		asali_->transport_[101].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[101].name,"NH3");
		asali_->transport_[101].geometry = 2;
		asali_->transport_[101].LJpotential = 481.000;
		asali_->transport_[101].LJdiameter =  2.920;
		asali_->transport_[101].dipole =  1.470;
		asali_->transport_[101].polar =  0.000;
		asali_->transport_[101].collision = 10.000;
		asali_->transport_[101].MW = 17.031;
		
		asali_->transport_[102].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->transport_[102].name,"NO");
		asali_->transport_[102].geometry = 1;
		asali_->transport_[102].LJpotential = 97.500;
		asali_->transport_[102].LJdiameter =  3.621;
		asali_->transport_[102].dipole =  0.000;
		asali_->transport_[102].polar =  1.760;
		asali_->transport_[102].collision =  4.000;
		asali_->transport_[102].MW = 30.006;
		
		asali_->transport_[103].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[103].name,"NO2");
		asali_->transport_[103].geometry = 2;
		asali_->transport_[103].LJpotential = 200.000;
		asali_->transport_[103].LJdiameter =  3.500;
		asali_->transport_[103].dipole =  0.000;
		asali_->transport_[103].polar =  0.000;
		asali_->transport_[103].collision =  1.000;
		asali_->transport_[103].MW = 46.006;
		
		asali_->transport_[104].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[104].name,"C3H5OOH");
		asali_->transport_[104].geometry = 2;
		asali_->transport_[104].LJpotential = 407.800;
		asali_->transport_[104].LJdiameter =  4.140;
		asali_->transport_[104].dipole =  0.000;
		asali_->transport_[104].polar =  0.000;
		asali_->transport_[104].collision =  1.000;
		asali_->transport_[104].MW = 74.079;
		
		asali_->transport_[105].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[105].name,"NC3H7OH");
		asali_->transport_[105].geometry = 2;
		asali_->transport_[105].LJpotential = 482.147;
		asali_->transport_[105].LJdiameter =  5.009;
		asali_->transport_[105].dipole =  1.660;
		asali_->transport_[105].polar =  6.740;
		asali_->transport_[105].collision =  1.000;
		asali_->transport_[105].MW = 60.096;
		
		asali_->transport_[106].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[106].name,"N1C4H9OH");
		asali_->transport_[106].geometry = 2;
		asali_->transport_[106].LJpotential = 503.072;
		asali_->transport_[106].LJdiameter =  5.340;
		asali_->transport_[106].dipole =  1.670;
		asali_->transport_[106].polar =  8.880;
		asali_->transport_[106].collision =  1.000;
		asali_->transport_[106].MW = 74.123;
		
		asali_->transport_[107].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[107].name,"N2C4H9OH");
		asali_->transport_[107].geometry = 2;
		asali_->transport_[107].LJpotential = 503.072;
		asali_->transport_[107].LJdiameter =  5.340;
		asali_->transport_[107].dipole =  1.670;
		asali_->transport_[107].polar =  8.880;
		asali_->transport_[107].collision =  1.000;
		asali_->transport_[107].MW = 74.123;
		
		asali_->transport_[108].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[108].name,"MEK");
		asali_->transport_[108].geometry = 2;
		asali_->transport_[108].LJpotential = 454.000;
		asali_->transport_[108].LJdiameter =  5.413;
		asali_->transport_[108].dipole =  3.300;
		asali_->transport_[108].polar =  0.000;
		asali_->transport_[108].collision =  1.000;
		asali_->transport_[108].MW = 72.107;
		
		asali_->transport_[109].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[109].name,"TC4H9OH");
		asali_->transport_[109].geometry = 2;
		asali_->transport_[109].LJpotential = 503.072;
		asali_->transport_[109].LJdiameter =  5.340;
		asali_->transport_[109].dipole =  1.670;
		asali_->transport_[109].polar =  8.880;
		asali_->transport_[109].collision =  1.000;
		asali_->transport_[109].MW = 74.123;
		
		asali_->transport_[110].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[110].name,"IC4H9OH");
		asali_->transport_[110].geometry = 2;
		asali_->transport_[110].LJpotential = 503.072;
		asali_->transport_[110].LJdiameter =  5.340;
		asali_->transport_[110].dipole =  1.670;
		asali_->transport_[110].polar =  8.880;
		asali_->transport_[110].collision =  1.000;
		asali_->transport_[110].MW = 74.123;
		
		asali_->transport_[111].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[111].name,"C4H7OH");
		asali_->transport_[111].geometry = 2;
		asali_->transport_[111].LJpotential = 503.072;
		asali_->transport_[111].LJdiameter =  5.340;
		asali_->transport_[111].dipole =  1.670;
		asali_->transport_[111].polar =  8.880;
		asali_->transport_[111].collision =  1.000;
		asali_->transport_[111].MW = 72.107;
		
		asali_->transport_[112].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[112].name,"C3H5OH");
		asali_->transport_[112].geometry = 2;
		asali_->transport_[112].LJpotential = 411.000;
		asali_->transport_[112].LJdiameter =  4.820;
		asali_->transport_[112].dipole =  0.000;
		asali_->transport_[112].polar =  0.000;
		asali_->transport_[112].collision =  1.000;
		asali_->transport_[112].MW = 58.080;
		
		asali_->transport_[113].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[113].name,"C10H10");
		asali_->transport_[113].geometry = 2;
		asali_->transport_[113].LJpotential = 630.400;
		asali_->transport_[113].LJdiameter =  6.180;
		asali_->transport_[113].dipole =  0.000;
		asali_->transport_[113].polar = 16.500;
		asali_->transport_[113].collision =  1.000;
		asali_->transport_[113].MW = 130.189;
		
		asali_->transport_[114].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[114].name,"BZFUR");
		asali_->transport_[114].geometry = 2;
		asali_->transport_[114].LJpotential = 630.400;
		asali_->transport_[114].LJdiameter =  6.180;
		asali_->transport_[114].dipole =  0.000;
		asali_->transport_[114].polar = 16.500;
		asali_->transport_[114].collision =  1.000;
		asali_->transport_[114].MW = 118.135;
		
		asali_->transport_[115].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[115].name,"TMBENZ");
		asali_->transport_[115].geometry = 2;
		asali_->transport_[115].LJpotential = 523.600;
		asali_->transport_[115].LJdiameter =  5.960;
		asali_->transport_[115].dipole =  0.000;
		asali_->transport_[115].polar =  0.000;
		asali_->transport_[115].collision =  1.000;
		asali_->transport_[115].MW = 120.194;
		
		asali_->transport_[116].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[116].name,"NPBENZ");
		asali_->transport_[116].geometry = 2;
		asali_->transport_[116].LJpotential = 495.300;
		asali_->transport_[116].LJdiameter =  5.680;
		asali_->transport_[116].dipole =  0.430;
		asali_->transport_[116].polar = 12.300;
		asali_->transport_[116].collision =  1.000;
		asali_->transport_[116].MW = 120.194;
		
		asali_->transport_[117].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[117].name,"C6H5OCH3");
		asali_->transport_[117].geometry = 2;
		asali_->transport_[117].LJpotential = 450.000;
		asali_->transport_[117].LJdiameter =  5.500;
		asali_->transport_[117].dipole =  0.000;
		asali_->transport_[117].polar =  0.000;
		asali_->transport_[117].collision =  1.000;
		asali_->transport_[117].MW = 108.140;
		
		asali_->transport_[118].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->transport_[118].name,"MB");
		asali_->transport_[118].geometry = 2;
		asali_->transport_[118].LJpotential = 468.000;
		asali_->transport_[118].LJdiameter =  5.850;
		asali_->transport_[118].dipole =  0.000;
		asali_->transport_[118].polar =  0.000;
		asali_->transport_[118].collision =  0.000;
		asali_->transport_[118].MW = 102.133;
		
		asali_->transport_[119].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[119].name,"MCROT");
		asali_->transport_[119].geometry = 2;
		asali_->transport_[119].LJpotential = 468.500;
		asali_->transport_[119].LJdiameter =  5.230;
		asali_->transport_[119].dipole =  0.000;
		asali_->transport_[119].polar =  0.000;
		asali_->transport_[119].collision =  1.000;
		asali_->transport_[119].MW = 100.117;
		
		asali_->transport_[120].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[120].name,"MACRIL");
		asali_->transport_[120].geometry = 2;
		asali_->transport_[120].LJpotential = 430.100;
		asali_->transport_[120].LJdiameter =  5.833;
		asali_->transport_[120].dipole =  0.000;
		asali_->transport_[120].polar =  0.000;
		asali_->transport_[120].collision =  1.000;
		asali_->transport_[120].MW = 86.090;
		
		asali_->transport_[121].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[121].name,"DIBZFUR");
		asali_->transport_[121].geometry = 2;
		asali_->transport_[121].LJpotential = 676.500;
		asali_->transport_[121].LJdiameter =  6.310;
		asali_->transport_[121].dipole =  0.000;
		asali_->transport_[121].polar =  0.000;
		asali_->transport_[121].collision =  1.000;
		asali_->transport_[121].MW = 168.195;
		
		asali_->transport_[122].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[122].name,"DIFENET");
		asali_->transport_[122].geometry = 2;
		asali_->transport_[122].LJpotential = 676.500;
		asali_->transport_[122].LJdiameter =  6.310;
		asali_->transport_[122].dipole =  0.000;
		asali_->transport_[122].polar =  0.000;
		asali_->transport_[122].collision =  1.000;
		asali_->transport_[122].MW = 170.211;
		
		asali_->transport_[123].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[123].name,"C12H22");
		asali_->transport_[123].geometry = 2;
		asali_->transport_[123].LJpotential = 580.000;
		asali_->transport_[123].LJdiameter =  7.600;
		asali_->transport_[123].dipole =  0.000;
		asali_->transport_[123].polar =  0.000;
		asali_->transport_[123].collision =  1.000;
		asali_->transport_[123].MW = 166.307;
		
		asali_->transport_[124].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[124].name,"BENZYNE");
		asali_->transport_[124].geometry = 2;
		asali_->transport_[124].LJpotential = 468.500;
		asali_->transport_[124].LJdiameter =  5.230;
		asali_->transport_[124].dipole =  0.000;
		asali_->transport_[124].polar = 10.300;
		asali_->transport_[124].collision =  1.000;
		asali_->transport_[124].MW = 76.098;
		
		asali_->transport_[125].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[125].name,"C2H2O2");
		asali_->transport_[125].geometry = 2;
		asali_->transport_[125].LJpotential = 470.600;
		asali_->transport_[125].LJdiameter =  4.410;
		asali_->transport_[125].dipole =  0.000;
		asali_->transport_[125].polar =  0.000;
		asali_->transport_[125].collision =  1.500;
		asali_->transport_[125].MW = 58.037;
		
		asali_->transport_[126].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[126].name,"C4H6O2");
		asali_->transport_[126].geometry = 2;
		asali_->transport_[126].LJpotential = 496.000;
		asali_->transport_[126].LJdiameter =  5.200;
		asali_->transport_[126].dipole =  0.000;
		asali_->transport_[126].polar =  0.000;
		asali_->transport_[126].collision =  1.000;
		asali_->transport_[126].MW = 86.090;
		
		asali_->transport_[127].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[127].name,"C5H4O2");
		asali_->transport_[127].geometry = 2;
		asali_->transport_[127].LJpotential = 524.690;
		asali_->transport_[127].LJdiameter =  5.653;
		asali_->transport_[127].dipole =  0.000;
		asali_->transport_[127].polar =  0.000;
		asali_->transport_[127].collision =  1.000;
		asali_->transport_[127].MW = 96.086;
		
		asali_->transport_[128].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[128].name,"C5H8O4");
		asali_->transport_[128].geometry = 2;
		asali_->transport_[128].LJpotential = 568.500;
		asali_->transport_[128].LJdiameter =  5.230;
		asali_->transport_[128].dipole =  0.000;
		asali_->transport_[128].polar = 10.300;
		asali_->transport_[128].collision =  1.000;
		asali_->transport_[128].MW = 132.116;
		
		asali_->transport_[129].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[129].name,"C6H10O5");
		asali_->transport_[129].geometry = 2;
		asali_->transport_[129].LJpotential = 568.500;
		asali_->transport_[129].LJdiameter =  5.230;
		asali_->transport_[129].dipole =  0.000;
		asali_->transport_[129].polar = 10.300;
		asali_->transport_[129].collision =  1.000;
		asali_->transport_[129].MW = 162.142;
		
		asali_->transport_[130].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[130].name,"C8H10O3");
		asali_->transport_[130].geometry = 2;
		asali_->transport_[130].LJpotential = 621.100;
		asali_->transport_[130].LJdiameter =  5.640;
		asali_->transport_[130].dipole =  0.000;
		asali_->transport_[130].polar =  0.000;
		asali_->transport_[130].collision =  1.000;
		asali_->transport_[130].MW = 154.166;
		
		asali_->transport_[131].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[131].name,"HCOOH");
		asali_->transport_[131].geometry = 2;
		asali_->transport_[131].LJpotential = 470.600;
		asali_->transport_[131].LJdiameter =  3.855;
		asali_->transport_[131].dipole =  0.000;
		asali_->transport_[131].polar =  0.000;
		asali_->transport_[131].collision =  1.000;
		asali_->transport_[131].MW = 46.026;
		
		asali_->transport_[132].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[132].name,"GLYCEROL");
		asali_->transport_[132].geometry = 2;
		asali_->transport_[132].LJpotential = 748.365;
		asali_->transport_[132].LJdiameter =  5.200;
		asali_->transport_[132].dipole =  1.930;
		asali_->transport_[132].polar =  9.430;
		asali_->transport_[132].collision =  1.000;
		asali_->transport_[132].MW = 92.095;
		
		asali_->transport_[133].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[133].name,"C4H4O");
		asali_->transport_[133].geometry = 2;
		asali_->transport_[133].LJpotential = 429.630;
		asali_->transport_[133].LJdiameter =  5.040;
		asali_->transport_[133].dipole =  0.000;
		asali_->transport_[133].polar =  0.000;
		asali_->transport_[133].collision =  1.000;
		asali_->transport_[133].MW = 68.075;
	}
}
