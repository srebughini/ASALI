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
		asali_->transport_ = (struct transportParameters*) malloc(483 * sizeof(struct transportParameters));
		asali_->number_of_species = 483;
		
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
		
		asali_->transport_[6].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[6].name,"CH2CHCH2");
		asali_->transport_[6].geometry = 2;
		asali_->transport_[6].LJpotential = 316.000;
		asali_->transport_[6].LJdiameter =  4.220;
		asali_->transport_[6].dipole =  0.000;
		asali_->transport_[6].polar =  0.000;
		asali_->transport_[6].collision =  1.000;
		asali_->transport_[6].MW = 41.073;
		
		asali_->transport_[7].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[7].name,"CHCHCH3");
		asali_->transport_[7].geometry = 2;
		asali_->transport_[7].LJpotential = 316.000;
		asali_->transport_[7].LJdiameter =  4.220;
		asali_->transport_[7].dipole =  0.000;
		asali_->transport_[7].polar =  0.000;
		asali_->transport_[7].collision =  1.000;
		asali_->transport_[7].MW = 41.073;
		
		asali_->transport_[8].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[8].name,"CH2CCH3");
		asali_->transport_[8].geometry = 2;
		asali_->transport_[8].LJpotential = 316.000;
		asali_->transport_[8].LJdiameter =  4.220;
		asali_->transport_[8].dipole =  0.000;
		asali_->transport_[8].polar =  0.000;
		asali_->transport_[8].collision =  1.000;
		asali_->transport_[8].MW = 41.073;
		
		asali_->transport_[9].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->transport_[9].name,"AR");
		asali_->transport_[9].geometry = 0;
		asali_->transport_[9].LJpotential = 136.500;
		asali_->transport_[9].LJdiameter =  3.330;
		asali_->transport_[9].dipole =  0.000;
		asali_->transport_[9].polar =  0.000;
		asali_->transport_[9].collision =  0.000;
		asali_->transport_[9].MW = 39.948;
		
		asali_->transport_[10].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[10].name,"C6H5CH2OH");
		asali_->transport_[10].geometry = 2;
		asali_->transport_[10].LJpotential = 622.400;
		asali_->transport_[10].LJdiameter =  5.530;
		asali_->transport_[10].dipole =  0.000;
		asali_->transport_[10].polar =  0.000;
		asali_->transport_[10].collision =  1.000;
		asali_->transport_[10].MW = 108.140;
		
		asali_->transport_[11].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[11].name,"C6H4O2");
		asali_->transport_[11].geometry = 2;
		asali_->transport_[11].LJpotential = 450.000;
		asali_->transport_[11].LJdiameter =  5.500;
		asali_->transport_[11].dipole =  0.000;
		asali_->transport_[11].polar =  0.000;
		asali_->transport_[11].collision =  1.000;
		asali_->transport_[11].MW = 108.097;
		
		asali_->transport_[12].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[12].name,"C6H6");
		asali_->transport_[12].geometry = 2;
		asali_->transport_[12].LJpotential = 468.500;
		asali_->transport_[12].LJdiameter =  5.230;
		asali_->transport_[12].dipole =  0.000;
		asali_->transport_[12].polar = 10.300;
		asali_->transport_[12].collision =  1.000;
		asali_->transport_[12].MW = 78.114;
		
		asali_->transport_[13].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[13].name,"C6H5CHO");
		asali_->transport_[13].geometry = 2;
		asali_->transport_[13].LJpotential = 622.400;
		asali_->transport_[13].LJdiameter =  5.530;
		asali_->transport_[13].dipole =  0.000;
		asali_->transport_[13].polar =  0.000;
		asali_->transport_[13].collision =  1.000;
		asali_->transport_[13].MW = 106.124;
		
		asali_->transport_[14].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->transport_[14].name,"C6H5C2H4C6H5");
		asali_->transport_[14].geometry = 2;
		asali_->transport_[14].LJpotential = 783.800;
		asali_->transport_[14].LJdiameter =  6.640;
		asali_->transport_[14].dipole =  0.000;
		asali_->transport_[14].polar =  0.000;
		asali_->transport_[14].collision =  1.000;
		asali_->transport_[14].MW = 182.265;
		
		asali_->transport_[15].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[15].name,"NC4H8");
		asali_->transport_[15].geometry = 2;
		asali_->transport_[15].LJpotential = 355.000;
		asali_->transport_[15].LJdiameter =  4.650;
		asali_->transport_[15].dipole =  0.000;
		asali_->transport_[15].polar =  0.000;
		asali_->transport_[15].collision =  1.000;
		asali_->transport_[15].MW = 56.107;
		
		asali_->transport_[16].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[16].name,"C4H6");
		asali_->transport_[16].geometry = 2;
		asali_->transport_[16].LJpotential = 357.000;
		asali_->transport_[16].LJdiameter =  5.180;
		asali_->transport_[16].dipole =  0.000;
		asali_->transport_[16].polar =  0.000;
		asali_->transport_[16].collision =  1.000;
		asali_->transport_[16].MW = 54.092;
		
		asali_->transport_[17].name = (char*) malloc(1 * sizeof(char));
		strcpy(asali_->transport_[17].name,"C");
		asali_->transport_[17].geometry = 0;
		asali_->transport_[17].LJpotential = 71.400;
		asali_->transport_[17].LJdiameter =  3.298;
		asali_->transport_[17].dipole =  0.000;
		asali_->transport_[17].polar =  0.000;
		asali_->transport_[17].collision =  0.000;
		asali_->transport_[17].MW = 12.011;
		
		asali_->transport_[18].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[18].name,"C12H8");
		asali_->transport_[18].geometry = 2;
		asali_->transport_[18].LJpotential = 689.800;
		asali_->transport_[18].LJdiameter =  6.500;
		asali_->transport_[18].dipole =  0.000;
		asali_->transport_[18].polar =  0.000;
		asali_->transport_[18].collision =  1.000;
		asali_->transport_[18].MW = 152.196;
		
		asali_->transport_[19].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[19].name,"C2H");
		asali_->transport_[19].geometry = 1;
		asali_->transport_[19].LJpotential = 209.000;
		asali_->transport_[19].LJdiameter =  4.100;
		asali_->transport_[19].dipole =  0.000;
		asali_->transport_[19].polar =  0.000;
		asali_->transport_[19].collision =  2.500;
		asali_->transport_[19].MW = 25.030;
		
		asali_->transport_[20].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[20].name,"C2H2");
		asali_->transport_[20].geometry = 1;
		asali_->transport_[20].LJpotential = 209.000;
		asali_->transport_[20].LJdiameter =  4.100;
		asali_->transport_[20].dipole =  0.000;
		asali_->transport_[20].polar =  0.000;
		asali_->transport_[20].collision =  2.500;
		asali_->transport_[20].MW = 26.038;
		
		asali_->transport_[21].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[21].name,"C2H4");
		asali_->transport_[21].geometry = 2;
		asali_->transport_[21].LJpotential = 280.800;
		asali_->transport_[21].LJdiameter =  3.971;
		asali_->transport_[21].dipole =  0.000;
		asali_->transport_[21].polar =  0.000;
		asali_->transport_[21].collision =  1.500;
		asali_->transport_[21].MW = 28.054;
		
		asali_->transport_[22].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[22].name,"C2H5");
		asali_->transport_[22].geometry = 2;
		asali_->transport_[22].LJpotential = 252.300;
		asali_->transport_[22].LJdiameter =  4.302;
		asali_->transport_[22].dipole =  0.000;
		asali_->transport_[22].polar =  0.000;
		asali_->transport_[22].collision =  1.500;
		asali_->transport_[22].MW = 29.062;
		
		asali_->transport_[23].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[23].name,"C2H6");
		asali_->transport_[23].geometry = 2;
		asali_->transport_[23].LJpotential = 252.300;
		asali_->transport_[23].LJdiameter =  4.302;
		asali_->transport_[23].dipole =  0.000;
		asali_->transport_[23].polar =  0.000;
		asali_->transport_[23].collision =  1.500;
		asali_->transport_[23].MW = 30.070;
		
		asali_->transport_[24].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[24].name,"C3H2");
		asali_->transport_[24].geometry = 2;
		asali_->transport_[24].LJpotential = 209.000;
		asali_->transport_[24].LJdiameter =  4.100;
		asali_->transport_[24].dipole =  0.000;
		asali_->transport_[24].polar =  0.000;
		asali_->transport_[24].collision =  1.000;
		asali_->transport_[24].MW = 38.049;
		
		asali_->transport_[25].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[25].name,"C3H3");
		asali_->transport_[25].geometry = 2;
		asali_->transport_[25].LJpotential = 252.000;
		asali_->transport_[25].LJdiameter =  4.760;
		asali_->transport_[25].dipole =  0.000;
		asali_->transport_[25].polar =  0.000;
		asali_->transport_[25].collision =  1.000;
		asali_->transport_[25].MW = 39.057;
		
		asali_->transport_[26].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[26].name,"C3H6");
		asali_->transport_[26].geometry = 2;
		asali_->transport_[26].LJpotential = 307.800;
		asali_->transport_[26].LJdiameter =  4.140;
		asali_->transport_[26].dipole =  0.000;
		asali_->transport_[26].polar =  0.000;
		asali_->transport_[26].collision =  1.000;
		asali_->transport_[26].MW = 42.081;
		
		asali_->transport_[27].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[27].name,"C3H8");
		asali_->transport_[27].geometry = 2;
		asali_->transport_[27].LJpotential = 303.400;
		asali_->transport_[27].LJdiameter =  4.810;
		asali_->transport_[27].dipole =  0.000;
		asali_->transport_[27].polar =  0.000;
		asali_->transport_[27].collision =  1.000;
		asali_->transport_[27].MW = 44.097;
		
		asali_->transport_[28].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[28].name,"NC3H7O");
		asali_->transport_[28].geometry = 2;
		asali_->transport_[28].LJpotential = 487.900;
		asali_->transport_[28].LJdiameter =  4.820;
		asali_->transport_[28].dipole =  0.000;
		asali_->transport_[28].polar =  0.000;
		asali_->transport_[28].collision =  1.000;
		asali_->transport_[28].MW = 59.088;
		
		asali_->transport_[29].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[29].name,"C3H7OOH");
		asali_->transport_[29].geometry = 2;
		asali_->transport_[29].LJpotential = 487.900;
		asali_->transport_[29].LJdiameter =  4.820;
		asali_->transport_[29].dipole =  0.000;
		asali_->transport_[29].polar =  0.000;
		asali_->transport_[29].collision =  1.000;
		asali_->transport_[29].MW = 76.095;
		
		asali_->transport_[30].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[30].name,"C4H2");
		asali_->transport_[30].geometry = 1;
		asali_->transport_[30].LJpotential = 357.000;
		asali_->transport_[30].LJdiameter =  5.180;
		asali_->transport_[30].dipole =  0.000;
		asali_->transport_[30].polar =  0.000;
		asali_->transport_[30].collision =  1.000;
		asali_->transport_[30].MW = 50.060;
		
		asali_->transport_[31].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[31].name,"C4H3");
		asali_->transport_[31].geometry = 1;
		asali_->transport_[31].LJpotential = 357.000;
		asali_->transport_[31].LJdiameter =  5.180;
		asali_->transport_[31].dipole =  0.000;
		asali_->transport_[31].polar =  0.000;
		asali_->transport_[31].collision =  1.000;
		asali_->transport_[31].MW = 51.068;
		
		asali_->transport_[32].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[32].name,"C4H4");
		asali_->transport_[32].geometry = 2;
		asali_->transport_[32].LJpotential = 357.000;
		asali_->transport_[32].LJdiameter =  5.180;
		asali_->transport_[32].dipole =  0.000;
		asali_->transport_[32].polar =  0.000;
		asali_->transport_[32].collision =  1.000;
		asali_->transport_[32].MW = 52.076;
		
		asali_->transport_[33].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[33].name,"C4H5");
		asali_->transport_[33].geometry = 2;
		asali_->transport_[33].LJpotential = 357.000;
		asali_->transport_[33].LJdiameter =  5.180;
		asali_->transport_[33].dipole =  0.000;
		asali_->transport_[33].polar =  0.000;
		asali_->transport_[33].collision =  1.000;
		asali_->transport_[33].MW = 53.084;
		
		asali_->transport_[34].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[34].name,"CH2C3H5");
		asali_->transport_[34].geometry = 2;
		asali_->transport_[34].LJpotential = 355.000;
		asali_->transport_[34].LJdiameter =  4.650;
		asali_->transport_[34].dipole =  0.000;
		asali_->transport_[34].polar =  0.000;
		asali_->transport_[34].collision =  1.000;
		asali_->transport_[34].MW = 55.100;
		
		asali_->transport_[35].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[35].name,"SC4H7");
		asali_->transport_[35].geometry = 2;
		asali_->transport_[35].LJpotential = 355.000;
		asali_->transport_[35].LJdiameter =  4.650;
		asali_->transport_[35].dipole =  0.000;
		asali_->transport_[35].polar =  0.000;
		asali_->transport_[35].collision =  1.000;
		asali_->transport_[35].MW = 55.100;
		
		asali_->transport_[36].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[36].name,"C4H9OOH");
		asali_->transport_[36].geometry = 2;
		asali_->transport_[36].LJpotential = 496.000;
		asali_->transport_[36].LJdiameter =  5.200;
		asali_->transport_[36].dipole =  0.000;
		asali_->transport_[36].polar =  0.000;
		asali_->transport_[36].collision =  1.000;
		asali_->transport_[36].MW = 90.122;
		
		asali_->transport_[37].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[37].name,"CYC5H4O");
		asali_->transport_[37].geometry = 2;
		asali_->transport_[37].LJpotential = 450.000;
		asali_->transport_[37].LJdiameter =  5.500;
		asali_->transport_[37].dipole =  0.000;
		asali_->transport_[37].polar =  0.000;
		asali_->transport_[37].collision =  1.000;
		asali_->transport_[37].MW = 80.086;
		
		asali_->transport_[38].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[38].name,"C5H7");
		asali_->transport_[38].geometry = 2;
		asali_->transport_[38].LJpotential = 408.000;
		asali_->transport_[38].LJdiameter =  5.200;
		asali_->transport_[38].dipole =  0.000;
		asali_->transport_[38].polar =  0.000;
		asali_->transport_[38].collision =  1.000;
		asali_->transport_[38].MW = 67.111;
		
		asali_->transport_[39].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[39].name,"NC5H11OOH");
		asali_->transport_[39].geometry = 2;
		asali_->transport_[39].LJpotential = 492.000;
		asali_->transport_[39].LJdiameter =  5.640;
		asali_->transport_[39].dipole =  0.000;
		asali_->transport_[39].polar =  0.000;
		asali_->transport_[39].collision =  1.000;
		asali_->transport_[39].MW = 104.149;
		
		asali_->transport_[40].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[40].name,"C6H5");
		asali_->transport_[40].geometry = 2;
		asali_->transport_[40].LJpotential = 468.500;
		asali_->transport_[40].LJdiameter =  5.230;
		asali_->transport_[40].dipole =  0.000;
		asali_->transport_[40].polar = 10.300;
		asali_->transport_[40].collision =  1.000;
		asali_->transport_[40].MW = 77.106;
		
		asali_->transport_[41].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[41].name,"C6H5O");
		asali_->transport_[41].geometry = 2;
		asali_->transport_[41].LJpotential = 450.000;
		asali_->transport_[41].LJdiameter =  5.500;
		asali_->transport_[41].dipole =  0.000;
		asali_->transport_[41].polar =  0.000;
		asali_->transport_[41].collision =  1.000;
		asali_->transport_[41].MW = 93.105;
		
		asali_->transport_[42].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[42].name,"LC6H6");
		asali_->transport_[42].geometry = 2;
		asali_->transport_[42].LJpotential = 412.300;
		asali_->transport_[42].LJdiameter =  5.349;
		asali_->transport_[42].dipole =  0.000;
		asali_->transport_[42].polar =  0.000;
		asali_->transport_[42].collision =  1.000;
		asali_->transport_[42].MW = 78.114;
		
		asali_->transport_[43].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[43].name,"CYC6H10-ONE");
		asali_->transport_[43].geometry = 2;
		asali_->transport_[43].LJpotential = 568.500;
		asali_->transport_[43].LJdiameter =  5.230;
		asali_->transport_[43].dipole =  0.000;
		asali_->transport_[43].polar = 10.300;
		asali_->transport_[43].collision =  1.000;
		asali_->transport_[43].MW = 98.145;
		
		asali_->transport_[44].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[44].name,"C7H7");
		asali_->transport_[44].geometry = 2;
		asali_->transport_[44].LJpotential = 495.300;
		asali_->transport_[44].LJdiameter =  5.680;
		asali_->transport_[44].dipole =  0.000;
		asali_->transport_[44].polar =  0.000;
		asali_->transport_[44].collision =  1.000;
		asali_->transport_[44].MW = 91.133;
		
		asali_->transport_[45].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[45].name,"NC7H15OOH");
		asali_->transport_[45].geometry = 2;
		asali_->transport_[45].LJpotential = 559.980;
		asali_->transport_[45].LJdiameter =  6.310;
		asali_->transport_[45].dipole =  0.000;
		asali_->transport_[45].polar =  0.000;
		asali_->transport_[45].collision =  1.000;
		asali_->transport_[45].MW = 132.203;
		
		asali_->transport_[46].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[46].name,"CYC5H8");
		asali_->transport_[46].geometry = 1;
		asali_->transport_[46].LJpotential = 408.000;
		asali_->transport_[46].LJdiameter =  5.200;
		asali_->transport_[46].dipole =  0.000;
		asali_->transport_[46].polar =  0.000;
		asali_->transport_[46].collision =  1.000;
		asali_->transport_[46].MW = 68.118;
		
		asali_->transport_[47].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[47].name,"CYC6H8");
		asali_->transport_[47].geometry = 2;
		asali_->transport_[47].LJpotential = 468.500;
		asali_->transport_[47].LJdiameter =  5.230;
		asali_->transport_[47].dipole =  0.000;
		asali_->transport_[47].polar = 10.300;
		asali_->transport_[47].collision =  1.000;
		asali_->transport_[47].MW = 80.130;
		
		asali_->transport_[48].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[48].name,"CYC6H12");
		asali_->transport_[48].geometry = 2;
		asali_->transport_[48].LJpotential = 468.500;
		asali_->transport_[48].LJdiameter =  5.230;
		asali_->transport_[48].dipole =  0.000;
		asali_->transport_[48].polar = 10.300;
		asali_->transport_[48].collision =  1.000;
		asali_->transport_[48].MW = 84.161;
		
		asali_->transport_[49].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[49].name,"CYC6H10");
		asali_->transport_[49].geometry = 2;
		asali_->transport_[49].LJpotential = 468.500;
		asali_->transport_[49].LJdiameter =  5.230;
		asali_->transport_[49].dipole =  0.000;
		asali_->transport_[49].polar = 10.300;
		asali_->transport_[49].collision =  1.000;
		asali_->transport_[49].MW = 82.145;
		
		asali_->transport_[50].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->transport_[50].name,"CH");
		asali_->transport_[50].geometry = 1;
		asali_->transport_[50].LJpotential = 80.000;
		asali_->transport_[50].LJdiameter =  2.750;
		asali_->transport_[50].dipole =  0.000;
		asali_->transport_[50].polar =  0.000;
		asali_->transport_[50].collision =  0.000;
		asali_->transport_[50].MW = 13.019;
		
		asali_->transport_[51].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[51].name,"CH2");
		asali_->transport_[51].geometry = 1;
		asali_->transport_[51].LJpotential = 144.000;
		asali_->transport_[51].LJdiameter =  3.800;
		asali_->transport_[51].dipole =  0.000;
		asali_->transport_[51].polar =  0.000;
		asali_->transport_[51].collision =  0.000;
		asali_->transport_[51].MW = 14.027;
		
		asali_->transport_[52].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[52].name,"CH2CO");
		asali_->transport_[52].geometry = 2;
		asali_->transport_[52].LJpotential = 436.000;
		asali_->transport_[52].LJdiameter =  3.970;
		asali_->transport_[52].dipole =  0.000;
		asali_->transport_[52].polar =  0.000;
		asali_->transport_[52].collision =  2.000;
		asali_->transport_[52].MW = 42.037;
		
		asali_->transport_[53].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[53].name,"CH2O");
		asali_->transport_[53].geometry = 2;
		asali_->transport_[53].LJpotential = 498.000;
		asali_->transport_[53].LJdiameter =  3.590;
		asali_->transport_[53].dipole =  0.000;
		asali_->transport_[53].polar =  0.000;
		asali_->transport_[53].collision =  2.000;
		asali_->transport_[53].MW = 30.026;
		
		asali_->transport_[54].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[54].name,"CH2OH");
		asali_->transport_[54].geometry = 2;
		asali_->transport_[54].LJpotential = 417.000;
		asali_->transport_[54].LJdiameter =  3.690;
		asali_->transport_[54].dipole =  1.700;
		asali_->transport_[54].polar =  0.000;
		asali_->transport_[54].collision =  2.000;
		asali_->transport_[54].MW = 31.034;
		
		asali_->transport_[55].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[55].name,"CH2S");
		asali_->transport_[55].geometry = 1;
		asali_->transport_[55].LJpotential = 144.000;
		asali_->transport_[55].LJdiameter =  3.800;
		asali_->transport_[55].dipole =  0.000;
		asali_->transport_[55].polar =  0.000;
		asali_->transport_[55].collision =  0.000;
		asali_->transport_[55].MW = 14.027;
		
		asali_->transport_[56].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[56].name,"CH3");
		asali_->transport_[56].geometry = 1;
		asali_->transport_[56].LJpotential = 144.000;
		asali_->transport_[56].LJdiameter =  3.800;
		asali_->transport_[56].dipole =  0.000;
		asali_->transport_[56].polar =  0.000;
		asali_->transport_[56].collision =  0.000;
		asali_->transport_[56].MW = 15.035;
		
		asali_->transport_[57].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[57].name,"CH3CO");
		asali_->transport_[57].geometry = 2;
		asali_->transport_[57].LJpotential = 436.000;
		asali_->transport_[57].LJdiameter =  3.970;
		asali_->transport_[57].dipole =  0.000;
		asali_->transport_[57].polar =  0.000;
		asali_->transport_[57].collision =  2.000;
		asali_->transport_[57].MW = 43.045;
		
		asali_->transport_[58].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[58].name,"CH3O");
		asali_->transport_[58].geometry = 2;
		asali_->transport_[58].LJpotential = 417.000;
		asali_->transport_[58].LJdiameter =  3.690;
		asali_->transport_[58].dipole =  1.700;
		asali_->transport_[58].polar =  0.000;
		asali_->transport_[58].collision =  2.000;
		asali_->transport_[58].MW = 31.034;
		
		asali_->transport_[59].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[59].name,"CH3OH");
		asali_->transport_[59].geometry = 2;
		asali_->transport_[59].LJpotential = 481.800;
		asali_->transport_[59].LJdiameter =  3.626;
		asali_->transport_[59].dipole =  0.000;
		asali_->transport_[59].polar =  0.000;
		asali_->transport_[59].collision =  1.000;
		asali_->transport_[59].MW = 32.042;
		
		asali_->transport_[60].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[60].name,"CH4");
		asali_->transport_[60].geometry = 2;
		asali_->transport_[60].LJpotential = 141.400;
		asali_->transport_[60].LJdiameter =  3.746;
		asali_->transport_[60].dipole =  0.000;
		asali_->transport_[60].polar =  2.600;
		asali_->transport_[60].collision = 13.000;
		asali_->transport_[60].MW = 16.043;
		
		asali_->transport_[61].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->transport_[61].name,"CO");
		asali_->transport_[61].geometry = 1;
		asali_->transport_[61].LJpotential = 98.100;
		asali_->transport_[61].LJdiameter =  3.650;
		asali_->transport_[61].dipole =  0.000;
		asali_->transport_[61].polar =  1.950;
		asali_->transport_[61].collision =  1.800;
		asali_->transport_[61].MW = 28.010;
		
		asali_->transport_[62].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[62].name,"CO2");
		asali_->transport_[62].geometry = 1;
		asali_->transport_[62].LJpotential = 244.000;
		asali_->transport_[62].LJdiameter =  3.763;
		asali_->transport_[62].dipole =  0.000;
		asali_->transport_[62].polar =  2.650;
		asali_->transport_[62].collision =  2.100;
		asali_->transport_[62].MW = 44.010;
		
		asali_->transport_[63].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[63].name,"CYC5H6");
		asali_->transport_[63].geometry = 2;
		asali_->transport_[63].LJpotential = 408.000;
		asali_->transport_[63].LJdiameter =  5.200;
		asali_->transport_[63].dipole =  0.000;
		asali_->transport_[63].polar =  0.000;
		asali_->transport_[63].collision =  1.000;
		asali_->transport_[63].MW = 66.103;
		
		asali_->transport_[64].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[64].name,"MCPTD");
		asali_->transport_[64].geometry = 2;
		asali_->transport_[64].LJpotential = 408.000;
		asali_->transport_[64].LJdiameter =  5.200;
		asali_->transport_[64].dipole =  0.000;
		asali_->transport_[64].polar =  0.000;
		asali_->transport_[64].collision =  1.000;
		asali_->transport_[64].MW = 80.130;
		
		asali_->transport_[65].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[65].name,"CRESOL");
		asali_->transport_[65].geometry = 2;
		asali_->transport_[65].LJpotential = 621.100;
		asali_->transport_[65].LJdiameter =  5.640;
		asali_->transport_[65].dipole =  0.000;
		asali_->transport_[65].polar =  0.000;
		asali_->transport_[65].collision =  1.000;
		asali_->transport_[65].MW = 108.140;
		
		asali_->transport_[66].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[66].name,"NC10H20");
		asali_->transport_[66].geometry = 2;
		asali_->transport_[66].LJpotential = 540.980;
		asali_->transport_[66].LJdiameter =  7.150;
		asali_->transport_[66].dipole =  0.000;
		asali_->transport_[66].polar =  0.000;
		asali_->transport_[66].collision =  1.000;
		asali_->transport_[66].MW = 140.269;
		
		asali_->transport_[67].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[67].name,"C6H5CH2C6H5");
		asali_->transport_[67].geometry = 2;
		asali_->transport_[67].LJpotential = 712.600;
		asali_->transport_[67].LJdiameter =  6.890;
		asali_->transport_[67].dipole =  0.000;
		asali_->transport_[67].polar =  0.000;
		asali_->transport_[67].collision =  1.000;
		asali_->transport_[67].MW = 168.238;
		
		asali_->transport_[68].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[68].name,"DIPE");
		asali_->transport_[68].geometry = 2;
		asali_->transport_[68].LJpotential = 432.000;
		asali_->transport_[68].LJdiameter =  6.000;
		asali_->transport_[68].dipole =  0.000;
		asali_->transport_[68].polar =  0.000;
		asali_->transport_[68].collision =  1.000;
		asali_->transport_[68].MW = 102.177;
		
		asali_->transport_[69].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[69].name,"MTBE-O");
		asali_->transport_[69].geometry = 2;
		asali_->transport_[69].LJpotential = 492.000;
		asali_->transport_[69].LJdiameter =  5.640;
		asali_->transport_[69].dipole =  0.000;
		asali_->transport_[69].polar =  0.000;
		asali_->transport_[69].collision =  1.000;
		asali_->transport_[69].MW = 102.133;
		
		asali_->transport_[70].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[70].name,"CH3OCH3");
		asali_->transport_[70].geometry = 2;
		asali_->transport_[70].LJpotential = 303.400;
		asali_->transport_[70].LJdiameter =  4.810;
		asali_->transport_[70].dipole =  0.000;
		asali_->transport_[70].polar =  0.000;
		asali_->transport_[70].collision =  1.000;
		asali_->transport_[70].MW = 46.069;
		
		asali_->transport_[71].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[71].name,"CH3CH3-C5H6");
		asali_->transport_[71].geometry = 2;
		asali_->transport_[71].LJpotential = 450.000;
		asali_->transport_[71].LJdiameter =  5.500;
		asali_->transport_[71].dipole =  0.000;
		asali_->transport_[71].polar =  0.000;
		asali_->transport_[71].collision =  1.000;
		asali_->transport_[71].MW = 96.172;
		
		asali_->transport_[72].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[72].name,"C6H5C2H5");
		asali_->transport_[72].geometry = 2;
		asali_->transport_[72].LJpotential = 523.600;
		asali_->transport_[72].LJdiameter =  5.960;
		asali_->transport_[72].dipole =  0.000;
		asali_->transport_[72].polar =  0.000;
		asali_->transport_[72].collision =  1.000;
		asali_->transport_[72].MW = 106.167;
		
		asali_->transport_[73].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[73].name,"NC7H14");
		asali_->transport_[73].geometry = 2;
		asali_->transport_[73].LJpotential = 459.980;
		asali_->transport_[73].LJdiameter =  6.310;
		asali_->transport_[73].dipole =  0.000;
		asali_->transport_[73].polar =  0.000;
		asali_->transport_[73].collision =  1.000;
		asali_->transport_[73].MW = 98.188;
		
		asali_->transport_[74].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[74].name,"NC6H12");
		asali_->transport_[74].geometry = 2;
		asali_->transport_[74].LJpotential = 412.300;
		asali_->transport_[74].LJdiameter =  5.349;
		asali_->transport_[74].dipole =  0.000;
		asali_->transport_[74].polar =  0.000;
		asali_->transport_[74].collision =  1.000;
		asali_->transport_[74].MW = 84.161;
		
		asali_->transport_[75].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[75].name,"C5H9CHO");
		asali_->transport_[75].geometry = 2;
		asali_->transport_[75].LJpotential = 568.500;
		asali_->transport_[75].LJdiameter =  5.230;
		asali_->transport_[75].dipole =  0.000;
		asali_->transport_[75].polar = 10.300;
		asali_->transport_[75].collision =  1.000;
		asali_->transport_[75].MW = 98.145;
		
		asali_->transport_[76].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[76].name,"ETBE");
		asali_->transport_[76].geometry = 2;
		asali_->transport_[76].LJpotential = 432.000;
		asali_->transport_[76].LJdiameter =  6.000;
		asali_->transport_[76].dipole =  0.000;
		asali_->transport_[76].polar =  0.000;
		asali_->transport_[76].collision =  1.000;
		asali_->transport_[76].MW = 102.177;
		
		asali_->transport_[77].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[77].name,"NEOC5H10-O");
		asali_->transport_[77].geometry = 2;
		asali_->transport_[77].LJpotential = 492.000;
		asali_->transport_[77].LJdiameter =  5.640;
		asali_->transport_[77].dipole =  0.000;
		asali_->transport_[77].polar =  0.000;
		asali_->transport_[77].collision =  1.000;
		asali_->transport_[77].MW = 86.134;
		
		asali_->transport_[78].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[78].name,"C4H8O");
		asali_->transport_[78].geometry = 2;
		asali_->transport_[78].LJpotential = 496.000;
		asali_->transport_[78].LJdiameter =  5.200;
		asali_->transport_[78].dipole =  0.000;
		asali_->transport_[78].polar =  0.000;
		asali_->transport_[78].collision =  1.000;
		asali_->transport_[78].MW = 72.107;
		
		asali_->transport_[79].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[79].name,"NC5H10-O");
		asali_->transport_[79].geometry = 2;
		asali_->transport_[79].LJpotential = 492.000;
		asali_->transport_[79].LJdiameter =  5.640;
		asali_->transport_[79].dipole =  0.000;
		asali_->transport_[79].polar =  0.000;
		asali_->transport_[79].collision =  1.000;
		asali_->transport_[79].MW = 86.134;
		
		asali_->transport_[80].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[80].name,"NC7H14O");
		asali_->transport_[80].geometry = 2;
		asali_->transport_[80].LJpotential = 559.980;
		asali_->transport_[80].LJdiameter =  6.310;
		asali_->transport_[80].dipole =  0.000;
		asali_->transport_[80].polar =  0.000;
		asali_->transport_[80].collision =  1.000;
		asali_->transport_[80].MW = 114.188;
		
		asali_->transport_[81].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[81].name,"IC8H16O");
		asali_->transport_[81].geometry = 2;
		asali_->transport_[81].LJpotential = 594.000;
		asali_->transport_[81].LJdiameter =  6.170;
		asali_->transport_[81].dipole =  0.000;
		asali_->transport_[81].polar =  0.000;
		asali_->transport_[81].collision =  1.000;
		asali_->transport_[81].MW = 128.214;
		
		asali_->transport_[82].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[82].name,"C2H5OH");
		asali_->transport_[82].geometry = 2;
		asali_->transport_[82].LJpotential = 362.600;
		asali_->transport_[82].LJdiameter =  4.530;
		asali_->transport_[82].dipole =  0.000;
		asali_->transport_[82].polar =  0.000;
		asali_->transport_[82].collision =  1.500;
		asali_->transport_[82].MW = 46.069;
		
		asali_->transport_[83].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[83].name,"C2H5OO");
		asali_->transport_[83].geometry = 2;
		asali_->transport_[83].LJpotential = 362.600;
		asali_->transport_[83].LJdiameter =  4.530;
		asali_->transport_[83].dipole =  0.000;
		asali_->transport_[83].polar =  0.000;
		asali_->transport_[83].collision =  1.500;
		asali_->transport_[83].MW = 61.061;
		
		asali_->transport_[84].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[84].name,"C2H5OOH");
		asali_->transport_[84].geometry = 2;
		asali_->transport_[84].LJpotential = 362.600;
		asali_->transport_[84].LJdiameter =  4.530;
		asali_->transport_[84].dipole =  0.000;
		asali_->transport_[84].polar =  0.000;
		asali_->transport_[84].collision =  1.500;
		asali_->transport_[84].MW = 62.068;
		
		asali_->transport_[85].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[85].name,"C2H4O");
		asali_->transport_[85].geometry = 2;
		asali_->transport_[85].LJpotential = 362.600;
		asali_->transport_[85].LJdiameter =  4.530;
		asali_->transport_[85].dipole =  0.000;
		asali_->transport_[85].polar =  0.000;
		asali_->transport_[85].collision =  1.500;
		asali_->transport_[85].MW = 44.053;
		
		asali_->transport_[86].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[86].name,"C6H5C2H");
		asali_->transport_[86].geometry = 2;
		asali_->transport_[86].LJpotential = 534.300;
		asali_->transport_[86].LJdiameter =  5.710;
		asali_->transport_[86].dipole =  0.770;
		asali_->transport_[86].polar =  0.000;
		asali_->transport_[86].collision =  1.000;
		asali_->transport_[86].MW = 102.136;
		
		asali_->transport_[87].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[87].name,"BIPHENYL");
		asali_->transport_[87].geometry = 2;
		asali_->transport_[87].LJpotential = 676.500;
		asali_->transport_[87].LJdiameter =  6.310;
		asali_->transport_[87].dipole =  0.000;
		asali_->transport_[87].polar =  0.000;
		asali_->transport_[87].collision =  1.000;
		asali_->transport_[87].MW = 154.211;
		
		asali_->transport_[88].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[88].name,"C14H10");
		asali_->transport_[88].geometry = 2;
		asali_->transport_[88].LJpotential = 772.000;
		asali_->transport_[88].LJdiameter =  6.960;
		asali_->transport_[88].dipole =  0.000;
		asali_->transport_[88].polar = 38.800;
		asali_->transport_[88].collision =  1.000;
		asali_->transport_[88].MW = 178.233;
		
		asali_->transport_[89].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[89].name,"C6H5OH");
		asali_->transport_[89].geometry = 2;
		asali_->transport_[89].LJpotential = 450.000;
		asali_->transport_[89].LJdiameter =  5.500;
		asali_->transport_[89].dipole =  0.000;
		asali_->transport_[89].polar =  0.000;
		asali_->transport_[89].collision =  1.000;
		asali_->transport_[89].MW = 94.113;
		
		asali_->transport_[90].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[90].name,"FLUORENE");
		asali_->transport_[90].geometry = 2;
		asali_->transport_[90].LJpotential = 712.600;
		asali_->transport_[90].LJdiameter =  6.890;
		asali_->transport_[90].dipole =  0.000;
		asali_->transport_[90].polar =  0.000;
		asali_->transport_[90].collision =  1.000;
		asali_->transport_[90].MW = 166.222;
		
		asali_->transport_[91].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[91].name,"C10H8");
		asali_->transport_[91].geometry = 2;
		asali_->transport_[91].LJpotential = 630.400;
		asali_->transport_[91].LJdiameter =  6.180;
		asali_->transport_[91].dipole =  0.000;
		asali_->transport_[91].polar = 16.500;
		asali_->transport_[91].collision =  1.000;
		asali_->transport_[91].MW = 128.174;
		
		asali_->transport_[92].name = (char*) malloc(1 * sizeof(char));
		strcpy(asali_->transport_[92].name,"H");
		asali_->transport_[92].geometry = 0;
		asali_->transport_[92].LJpotential = 145.000;
		asali_->transport_[92].LJdiameter =  2.050;
		asali_->transport_[92].dipole =  0.000;
		asali_->transport_[92].polar =  0.000;
		asali_->transport_[92].collision =  0.000;
		asali_->transport_[92].MW =  1.008;
		
		asali_->transport_[93].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->transport_[93].name,"H2");
		asali_->transport_[93].geometry = 1;
		asali_->transport_[93].LJpotential = 38.000;
		asali_->transport_[93].LJdiameter =  2.920;
		asali_->transport_[93].dipole =  0.000;
		asali_->transport_[93].polar =  0.790;
		asali_->transport_[93].collision = 280.000;
		asali_->transport_[93].MW =  2.016;
		
		asali_->transport_[94].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[94].name,"H2O");
		asali_->transport_[94].geometry = 2;
		asali_->transport_[94].LJpotential = 572.400;
		asali_->transport_[94].LJdiameter =  2.605;
		asali_->transport_[94].dipole =  1.844;
		asali_->transport_[94].polar =  0.000;
		asali_->transport_[94].collision =  4.000;
		asali_->transport_[94].MW = 18.015;
		
		asali_->transport_[95].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[95].name,"H2O2");
		asali_->transport_[95].geometry = 2;
		asali_->transport_[95].LJpotential = 107.400;
		asali_->transport_[95].LJdiameter =  3.458;
		asali_->transport_[95].dipole =  0.000;
		asali_->transport_[95].polar =  0.000;
		asali_->transport_[95].collision =  3.800;
		asali_->transport_[95].MW = 34.015;
		
		asali_->transport_[96].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[96].name,"HCCO");
		asali_->transport_[96].geometry = 2;
		asali_->transport_[96].LJpotential = 150.000;
		asali_->transport_[96].LJdiameter =  2.500;
		asali_->transport_[96].dipole =  0.000;
		asali_->transport_[96].polar =  0.000;
		asali_->transport_[96].collision =  1.000;
		asali_->transport_[96].MW = 41.029;
		
		asali_->transport_[97].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[97].name,"HCO");
		asali_->transport_[97].geometry = 2;
		asali_->transport_[97].LJpotential = 498.000;
		asali_->transport_[97].LJdiameter =  3.590;
		asali_->transport_[97].dipole =  0.000;
		asali_->transport_[97].polar =  0.000;
		asali_->transport_[97].collision =  0.000;
		asali_->transport_[97].MW = 29.018;
		
		asali_->transport_[98].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[98].name,"HCO3");
		asali_->transport_[98].geometry = 2;
		asali_->transport_[98].LJpotential = 498.000;
		asali_->transport_[98].LJdiameter =  3.590;
		asali_->transport_[98].dipole =  0.000;
		asali_->transport_[98].polar =  0.000;
		asali_->transport_[98].collision =  0.000;
		asali_->transport_[98].MW = 61.017;
		
		asali_->transport_[99].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->transport_[99].name,"HE");
		asali_->transport_[99].geometry = 0;
		asali_->transport_[99].LJpotential = 10.200;
		asali_->transport_[99].LJdiameter =  2.576;
		asali_->transport_[99].dipole =  0.000;
		asali_->transport_[99].polar =  0.000;
		asali_->transport_[99].collision =  0.000;
		asali_->transport_[99].MW =  4.003;
		
		asali_->transport_[100].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[100].name,"HO2");
		asali_->transport_[100].geometry = 2;
		asali_->transport_[100].LJpotential = 107.400;
		asali_->transport_[100].LJdiameter =  3.458;
		asali_->transport_[100].dipole =  0.000;
		asali_->transport_[100].polar =  0.000;
		asali_->transport_[100].collision =  1.000;
		asali_->transport_[100].MW = 33.007;
		
		asali_->transport_[101].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[101].name,"IC4H8");
		asali_->transport_[101].geometry = 2;
		asali_->transport_[101].LJpotential = 355.000;
		asali_->transport_[101].LJdiameter =  4.650;
		asali_->transport_[101].dipole =  0.000;
		asali_->transport_[101].polar =  0.000;
		asali_->transport_[101].collision =  1.000;
		asali_->transport_[101].MW = 56.107;
		
		asali_->transport_[102].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[102].name,"IC3H7CHO");
		asali_->transport_[102].geometry = 2;
		asali_->transport_[102].LJpotential = 455.000;
		asali_->transport_[102].LJdiameter =  4.650;
		asali_->transport_[102].dipole =  0.000;
		asali_->transport_[102].polar =  0.000;
		asali_->transport_[102].collision =  1.000;
		asali_->transport_[102].MW = 72.107;
		
		asali_->transport_[103].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[103].name,"IC4H9P");
		asali_->transport_[103].geometry = 2;
		asali_->transport_[103].LJpotential = 352.000;
		asali_->transport_[103].LJdiameter =  5.240;
		asali_->transport_[103].dipole =  0.000;
		asali_->transport_[103].polar =  0.000;
		asali_->transport_[103].collision =  1.000;
		asali_->transport_[103].MW = 57.116;
		
		asali_->transport_[104].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[104].name,"IC4H9P-OO");
		asali_->transport_[104].geometry = 2;
		asali_->transport_[104].LJpotential = 496.000;
		asali_->transport_[104].LJdiameter =  5.200;
		asali_->transport_[104].dipole =  0.000;
		asali_->transport_[104].polar =  0.000;
		asali_->transport_[104].collision =  1.000;
		asali_->transport_[104].MW = 89.114;
		
		asali_->transport_[105].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[105].name,"IC4H9T");
		asali_->transport_[105].geometry = 2;
		asali_->transport_[105].LJpotential = 352.000;
		asali_->transport_[105].LJdiameter =  5.240;
		asali_->transport_[105].dipole =  0.000;
		asali_->transport_[105].polar =  0.000;
		asali_->transport_[105].collision =  1.000;
		asali_->transport_[105].MW = 57.116;
		
		asali_->transport_[106].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[106].name,"IC4H9T-OO");
		asali_->transport_[106].geometry = 2;
		asali_->transport_[106].LJpotential = 496.000;
		asali_->transport_[106].LJdiameter =  5.200;
		asali_->transport_[106].dipole =  0.000;
		asali_->transport_[106].polar =  0.000;
		asali_->transport_[106].collision =  1.000;
		asali_->transport_[106].MW = 89.114;
		
		asali_->transport_[107].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[107].name,"IC4H10");
		asali_->transport_[107].geometry = 2;
		asali_->transport_[107].LJpotential = 352.000;
		asali_->transport_[107].LJdiameter =  5.240;
		asali_->transport_[107].dipole =  0.000;
		asali_->transport_[107].polar =  0.000;
		asali_->transport_[107].collision =  1.000;
		asali_->transport_[107].MW = 58.123;
		
		asali_->transport_[108].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[108].name,"IC16H34");
		asali_->transport_[108].geometry = 2;
		asali_->transport_[108].LJpotential = 650.000;
		asali_->transport_[108].LJdiameter =  8.350;
		asali_->transport_[108].dipole =  0.000;
		asali_->transport_[108].polar =  0.000;
		asali_->transport_[108].collision =  1.000;
		asali_->transport_[108].MW = 226.446;
		
		asali_->transport_[109].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[109].name,"IC4H7");
		asali_->transport_[109].geometry = 2;
		asali_->transport_[109].LJpotential = 355.000;
		asali_->transport_[109].LJdiameter =  4.650;
		asali_->transport_[109].dipole =  0.000;
		asali_->transport_[109].polar =  0.000;
		asali_->transport_[109].collision =  1.000;
		asali_->transport_[109].MW = 55.100;
		
		asali_->transport_[110].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[110].name,"IC8H18");
		asali_->transport_[110].geometry = 2;
		asali_->transport_[110].LJpotential = 494.000;
		asali_->transport_[110].LJdiameter =  6.170;
		asali_->transport_[110].dipole =  0.000;
		asali_->transport_[110].polar =  0.000;
		asali_->transport_[110].collision =  1.000;
		asali_->transport_[110].MW = 114.231;
		
		asali_->transport_[111].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[111].name,"INDENE");
		asali_->transport_[111].geometry = 2;
		asali_->transport_[111].LJpotential = 588.600;
		asali_->transport_[111].LJdiameter =  5.960;
		asali_->transport_[111].dipole =  0.650;
		asali_->transport_[111].polar =  0.000;
		asali_->transport_[111].collision =  1.000;
		asali_->transport_[111].MW = 116.163;
		
		asali_->transport_[112].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[112].name,"IC3H7");
		asali_->transport_[112].geometry = 2;
		asali_->transport_[112].LJpotential = 303.400;
		asali_->transport_[112].LJdiameter =  4.810;
		asali_->transport_[112].dipole =  0.000;
		asali_->transport_[112].polar =  0.000;
		asali_->transport_[112].collision =  1.000;
		asali_->transport_[112].MW = 43.089;
		
		asali_->transport_[113].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[113].name,"IC3H7OH");
		asali_->transport_[113].geometry = 2;
		asali_->transport_[113].LJpotential = 482.147;
		asali_->transport_[113].LJdiameter =  5.009;
		asali_->transport_[113].dipole =  1.660;
		asali_->transport_[113].polar =  6.740;
		asali_->transport_[113].collision =  1.000;
		asali_->transport_[113].MW = 60.096;
		
		asali_->transport_[114].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[114].name,"IC3H7OO");
		asali_->transport_[114].geometry = 2;
		asali_->transport_[114].LJpotential = 468.300;
		asali_->transport_[114].LJdiameter =  4.760;
		asali_->transport_[114].dipole =  0.000;
		asali_->transport_[114].polar =  0.000;
		asali_->transport_[114].collision =  1.000;
		asali_->transport_[114].MW = 75.087;
		
		asali_->transport_[115].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[115].name,"IC3-QOOH");
		asali_->transport_[115].geometry = 2;
		asali_->transport_[115].LJpotential = 468.300;
		asali_->transport_[115].LJdiameter =  4.760;
		asali_->transport_[115].dipole =  0.000;
		asali_->transport_[115].polar =  0.000;
		asali_->transport_[115].collision =  1.000;
		asali_->transport_[115].MW = 75.087;
		
		asali_->transport_[116].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[116].name,"IC3-OOQOOH");
		asali_->transport_[116].geometry = 2;
		asali_->transport_[116].LJpotential = 468.300;
		asali_->transport_[116].LJdiameter =  4.760;
		asali_->transport_[116].dipole =  0.000;
		asali_->transport_[116].polar =  0.000;
		asali_->transport_[116].collision =  1.000;
		asali_->transport_[116].MW = 107.086;
		
		asali_->transport_[117].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[117].name,"IC5H10");
		asali_->transport_[117].geometry = 2;
		asali_->transport_[117].LJpotential = 408.000;
		asali_->transport_[117].LJdiameter =  5.200;
		asali_->transport_[117].dipole =  0.000;
		asali_->transport_[117].polar =  0.000;
		asali_->transport_[117].collision =  1.000;
		asali_->transport_[117].MW = 70.134;
		
		asali_->transport_[118].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[118].name,"NEOC5-OQOOH");
		asali_->transport_[118].geometry = 2;
		asali_->transport_[118].LJpotential = 492.000;
		asali_->transport_[118].LJdiameter =  5.640;
		asali_->transport_[118].dipole =  0.000;
		asali_->transport_[118].polar =  0.000;
		asali_->transport_[118].collision =  1.000;
		asali_->transport_[118].MW = 118.133;
		
		asali_->transport_[119].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[119].name,"IC4-OQOOH");
		asali_->transport_[119].geometry = 2;
		asali_->transport_[119].LJpotential = 496.000;
		asali_->transport_[119].LJdiameter =  5.200;
		asali_->transport_[119].dipole =  0.000;
		asali_->transport_[119].polar =  0.000;
		asali_->transport_[119].collision =  1.000;
		asali_->transport_[119].MW = 104.106;
		
		asali_->transport_[120].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[120].name,"C3-OQOOH");
		asali_->transport_[120].geometry = 2;
		asali_->transport_[120].LJpotential = 487.900;
		asali_->transport_[120].LJdiameter =  4.820;
		asali_->transport_[120].dipole =  0.000;
		asali_->transport_[120].polar =  0.000;
		asali_->transport_[120].collision =  1.000;
		asali_->transport_[120].MW = 90.079;
		
		asali_->transport_[121].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[121].name,"NC4-OQOOH");
		asali_->transport_[121].geometry = 2;
		asali_->transport_[121].LJpotential = 496.000;
		asali_->transport_[121].LJdiameter =  5.200;
		asali_->transport_[121].dipole =  0.000;
		asali_->transport_[121].polar =  0.000;
		asali_->transport_[121].collision =  1.000;
		asali_->transport_[121].MW = 104.106;
		
		asali_->transport_[122].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[122].name,"NC5-OQOOH");
		asali_->transport_[122].geometry = 2;
		asali_->transport_[122].LJpotential = 492.000;
		asali_->transport_[122].LJdiameter =  5.640;
		asali_->transport_[122].dipole =  0.000;
		asali_->transport_[122].polar =  0.000;
		asali_->transport_[122].collision =  1.000;
		asali_->transport_[122].MW = 118.133;
		
		asali_->transport_[123].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[123].name,"NC7-OQOOH");
		asali_->transport_[123].geometry = 2;
		asali_->transport_[123].LJpotential = 559.980;
		asali_->transport_[123].LJdiameter =  6.310;
		asali_->transport_[123].dipole =  0.000;
		asali_->transport_[123].polar =  0.000;
		asali_->transport_[123].collision =  1.000;
		asali_->transport_[123].MW = 146.186;
		
		asali_->transport_[124].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[124].name,"IC8-OQOOH");
		asali_->transport_[124].geometry = 2;
		asali_->transport_[124].LJpotential = 594.000;
		asali_->transport_[124].LJdiameter =  6.170;
		asali_->transport_[124].dipole =  0.000;
		asali_->transport_[124].polar =  0.000;
		asali_->transport_[124].collision =  1.000;
		asali_->transport_[124].MW = 160.213;
		
		asali_->transport_[125].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[125].name,"DME-OQOOH");
		asali_->transport_[125].geometry = 2;
		asali_->transport_[125].LJpotential = 403.400;
		asali_->transport_[125].LJdiameter =  4.810;
		asali_->transport_[125].dipole =  0.000;
		asali_->transport_[125].polar =  0.000;
		asali_->transport_[125].collision =  1.000;
		asali_->transport_[125].MW = 92.051;
		
		asali_->transport_[126].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[126].name,"NC10-OQOOH");
		asali_->transport_[126].geometry = 2;
		asali_->transport_[126].LJpotential = 640.980;
		asali_->transport_[126].LJdiameter =  7.150;
		asali_->transport_[126].dipole =  0.000;
		asali_->transport_[126].polar =  0.000;
		asali_->transport_[126].collision =  1.000;
		asali_->transport_[126].MW = 188.267;
		
		asali_->transport_[127].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[127].name,"NC12-OQOOH");
		asali_->transport_[127].geometry = 2;
		asali_->transport_[127].LJpotential = 680.000;
		asali_->transport_[127].LJdiameter =  7.600;
		asali_->transport_[127].dipole =  0.000;
		asali_->transport_[127].polar =  0.000;
		asali_->transport_[127].collision =  1.000;
		asali_->transport_[127].MW = 216.321;
		
		asali_->transport_[128].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[128].name,"IC16-OQOOH");
		asali_->transport_[128].geometry = 2;
		asali_->transport_[128].LJpotential = 750.000;
		asali_->transport_[128].LJdiameter =  8.350;
		asali_->transport_[128].dipole =  0.000;
		asali_->transport_[128].polar =  0.000;
		asali_->transport_[128].collision =  1.000;
		asali_->transport_[128].MW = 272.428;
		
		asali_->transport_[129].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[129].name,"MCYC6-OQOOH");
		asali_->transport_[129].geometry = 2;
		asali_->transport_[129].LJpotential = 595.300;
		asali_->transport_[129].LJdiameter =  5.680;
		asali_->transport_[129].dipole =  0.430;
		asali_->transport_[129].polar = 12.300;
		asali_->transport_[129].collision =  1.000;
		asali_->transport_[129].MW = 144.170;
		
		asali_->transport_[130].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[130].name,"MTBE-OQOOH");
		asali_->transport_[130].geometry = 2;
		asali_->transport_[130].LJpotential = 492.000;
		asali_->transport_[130].LJdiameter =  5.640;
		asali_->transport_[130].dipole =  0.000;
		asali_->transport_[130].polar =  0.000;
		asali_->transport_[130].collision =  1.000;
		asali_->transport_[130].MW = 134.132;
		
		asali_->transport_[131].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[131].name,"IC3H5CHO");
		asali_->transport_[131].geometry = 2;
		asali_->transport_[131].LJpotential = 357.000;
		asali_->transport_[131].LJdiameter =  5.180;
		asali_->transport_[131].dipole =  0.000;
		asali_->transport_[131].polar =  0.000;
		asali_->transport_[131].collision =  1.000;
		asali_->transport_[131].MW = 70.091;
		
		asali_->transport_[132].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[132].name,"MCYC6");
		asali_->transport_[132].geometry = 2;
		asali_->transport_[132].LJpotential = 495.300;
		asali_->transport_[132].LJdiameter =  5.680;
		asali_->transport_[132].dipole =  0.430;
		asali_->transport_[132].polar = 12.300;
		asali_->transport_[132].collision =  1.000;
		asali_->transport_[132].MW = 98.188;
		
		asali_->transport_[133].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[133].name,"CH3CHO");
		asali_->transport_[133].geometry = 2;
		asali_->transport_[133].LJpotential = 436.000;
		asali_->transport_[133].LJdiameter =  3.970;
		asali_->transport_[133].dipole =  0.000;
		asali_->transport_[133].polar =  0.000;
		asali_->transport_[133].collision =  2.000;
		asali_->transport_[133].MW = 44.053;
		
		asali_->transport_[134].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[134].name,"CH3CO3");
		asali_->transport_[134].geometry = 2;
		asali_->transport_[134].LJpotential = 436.000;
		asali_->transport_[134].LJdiameter =  3.970;
		asali_->transport_[134].dipole =  0.000;
		asali_->transport_[134].polar =  0.000;
		asali_->transport_[134].collision =  2.000;
		asali_->transport_[134].MW = 75.044;
		
		asali_->transport_[135].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[135].name,"C10H7CH3");
		asali_->transport_[135].geometry = 2;
		asali_->transport_[135].LJpotential = 660.000;
		asali_->transport_[135].LJdiameter =  6.350;
		asali_->transport_[135].dipole =  0.000;
		asali_->transport_[135].polar =  0.000;
		asali_->transport_[135].collision =  1.000;
		asali_->transport_[135].MW = 142.200;
		
		asali_->transport_[136].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[136].name,"CH3OO");
		asali_->transport_[136].geometry = 2;
		asali_->transport_[136].LJpotential = 417.000;
		asali_->transport_[136].LJdiameter =  3.690;
		asali_->transport_[136].dipole =  1.700;
		asali_->transport_[136].polar =  0.000;
		asali_->transport_[136].collision =  2.000;
		asali_->transport_[136].MW = 47.034;
		
		asali_->transport_[137].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[137].name,"CH3OOH");
		asali_->transport_[137].geometry = 2;
		asali_->transport_[137].LJpotential = 481.800;
		asali_->transport_[137].LJdiameter =  3.626;
		asali_->transport_[137].dipole =  0.000;
		asali_->transport_[137].polar =  0.000;
		asali_->transport_[137].collision =  1.000;
		asali_->transport_[137].MW = 48.042;
		
		asali_->transport_[138].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[138].name,"MTBE");
		asali_->transport_[138].geometry = 2;
		asali_->transport_[138].LJpotential = 392.000;
		asali_->transport_[138].LJdiameter =  5.640;
		asali_->transport_[138].dipole =  0.000;
		asali_->transport_[138].polar =  0.000;
		asali_->transport_[138].collision =  1.000;
		asali_->transport_[138].MW = 88.150;
		
		asali_->transport_[139].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->transport_[139].name,"N2");
		asali_->transport_[139].geometry = 1;
		asali_->transport_[139].LJpotential = 97.530;
		asali_->transport_[139].LJdiameter =  3.621;
		asali_->transport_[139].dipole =  0.000;
		asali_->transport_[139].polar =  1.760;
		asali_->transport_[139].collision =  4.000;
		asali_->transport_[139].MW = 28.014;
		
		asali_->transport_[140].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[140].name,"C10H7OH");
		asali_->transport_[140].geometry = 2;
		asali_->transport_[140].LJpotential = 663.450;
		asali_->transport_[140].LJdiameter =  6.362;
		asali_->transport_[140].dipole =  0.000;
		asali_->transport_[140].polar =  0.000;
		asali_->transport_[140].collision =  1.000;
		asali_->transport_[140].MW = 144.173;
		
		asali_->transport_[141].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[141].name,"C10H7CHO");
		asali_->transport_[141].geometry = 2;
		asali_->transport_[141].LJpotential = 663.450;
		asali_->transport_[141].LJdiameter =  6.362;
		asali_->transport_[141].dipole =  0.000;
		asali_->transport_[141].polar =  0.000;
		asali_->transport_[141].collision =  1.000;
		asali_->transport_[141].MW = 156.184;
		
		asali_->transport_[142].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[142].name,"CH3C10H6OH");
		asali_->transport_[142].geometry = 2;
		asali_->transport_[142].LJpotential = 663.450;
		asali_->transport_[142].LJdiameter =  6.362;
		asali_->transport_[142].dipole =  0.000;
		asali_->transport_[142].polar =  0.000;
		asali_->transport_[142].collision =  1.000;
		asali_->transport_[142].MW = 158.200;
		
		asali_->transport_[143].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[143].name,"CH3C10H6O");
		asali_->transport_[143].geometry = 2;
		asali_->transport_[143].LJpotential = 663.450;
		asali_->transport_[143].LJdiameter =  6.362;
		asali_->transport_[143].dipole =  0.000;
		asali_->transport_[143].polar =  0.000;
		asali_->transport_[143].collision =  1.000;
		asali_->transport_[143].MW = 157.192;
		
		asali_->transport_[144].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[144].name,"NC4H9P");
		asali_->transport_[144].geometry = 2;
		asali_->transport_[144].LJpotential = 352.000;
		asali_->transport_[144].LJdiameter =  5.240;
		asali_->transport_[144].dipole =  0.000;
		asali_->transport_[144].polar =  0.000;
		asali_->transport_[144].collision =  1.000;
		asali_->transport_[144].MW = 57.116;
		
		asali_->transport_[145].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[145].name,"NC4H9S");
		asali_->transport_[145].geometry = 2;
		asali_->transport_[145].LJpotential = 352.000;
		asali_->transport_[145].LJdiameter =  5.240;
		asali_->transport_[145].dipole =  0.000;
		asali_->transport_[145].polar =  0.000;
		asali_->transport_[145].collision =  1.000;
		asali_->transport_[145].MW = 57.116;
		
		asali_->transport_[146].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[146].name,"NC4H10");
		asali_->transport_[146].geometry = 2;
		asali_->transport_[146].LJpotential = 352.000;
		asali_->transport_[146].LJdiameter =  5.240;
		asali_->transport_[146].dipole =  0.000;
		asali_->transport_[146].polar =  0.000;
		asali_->transport_[146].collision =  1.000;
		asali_->transport_[146].MW = 58.123;
		
		asali_->transport_[147].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[147].name,"NC10H22");
		asali_->transport_[147].geometry = 2;
		asali_->transport_[147].LJpotential = 540.980;
		asali_->transport_[147].LJdiameter =  7.150;
		asali_->transport_[147].dipole =  0.000;
		asali_->transport_[147].polar =  0.000;
		asali_->transport_[147].collision =  1.000;
		asali_->transport_[147].MW = 142.285;
		
		asali_->transport_[148].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[148].name,"NC12H26");
		asali_->transport_[148].geometry = 2;
		asali_->transport_[148].LJpotential = 580.000;
		asali_->transport_[148].LJdiameter =  7.600;
		asali_->transport_[148].dipole =  0.000;
		asali_->transport_[148].polar =  0.000;
		asali_->transport_[148].collision =  1.000;
		asali_->transport_[148].MW = 170.338;
		
		asali_->transport_[149].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[149].name,"NC5H12");
		asali_->transport_[149].geometry = 2;
		asali_->transport_[149].LJpotential = 392.000;
		asali_->transport_[149].LJdiameter =  5.640;
		asali_->transport_[149].dipole =  0.000;
		asali_->transport_[149].polar =  0.000;
		asali_->transport_[149].collision =  1.000;
		asali_->transport_[149].MW = 72.150;
		
		asali_->transport_[150].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[150].name,"NC7H16");
		asali_->transport_[150].geometry = 2;
		asali_->transport_[150].LJpotential = 459.980;
		asali_->transport_[150].LJdiameter =  6.310;
		asali_->transport_[150].dipole =  0.000;
		asali_->transport_[150].polar =  0.000;
		asali_->transport_[150].collision =  1.000;
		asali_->transport_[150].MW = 100.204;
		
		asali_->transport_[151].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[151].name,"NEOC5H12");
		asali_->transport_[151].geometry = 2;
		asali_->transport_[151].LJpotential = 392.000;
		asali_->transport_[151].LJdiameter =  5.640;
		asali_->transport_[151].dipole =  0.000;
		asali_->transport_[151].polar =  0.000;
		asali_->transport_[151].collision =  1.000;
		asali_->transport_[151].MW = 72.150;
		
		asali_->transport_[152].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[152].name,"NC3H7");
		asali_->transport_[152].geometry = 2;
		asali_->transport_[152].LJpotential = 303.400;
		asali_->transport_[152].LJdiameter =  4.810;
		asali_->transport_[152].dipole =  0.000;
		asali_->transport_[152].polar =  0.000;
		asali_->transport_[152].collision =  1.000;
		asali_->transport_[152].MW = 43.089;
		
		asali_->transport_[153].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[153].name,"NC3H7OO");
		asali_->transport_[153].geometry = 2;
		asali_->transport_[153].LJpotential = 487.900;
		asali_->transport_[153].LJdiameter =  4.820;
		asali_->transport_[153].dipole =  0.000;
		asali_->transport_[153].polar =  0.000;
		asali_->transport_[153].collision =  1.000;
		asali_->transport_[153].MW = 75.087;
		
		asali_->transport_[154].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[154].name,"NC3-QOOH");
		asali_->transport_[154].geometry = 2;
		asali_->transport_[154].LJpotential = 487.900;
		asali_->transport_[154].LJdiameter =  4.820;
		asali_->transport_[154].dipole =  0.000;
		asali_->transport_[154].polar =  0.000;
		asali_->transport_[154].collision =  1.000;
		asali_->transport_[154].MW = 75.087;
		
		asali_->transport_[155].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[155].name,"NC3-OOQOOH");
		asali_->transport_[155].geometry = 2;
		asali_->transport_[155].LJpotential = 487.900;
		asali_->transport_[155].LJdiameter =  4.820;
		asali_->transport_[155].dipole =  0.000;
		asali_->transport_[155].polar =  0.000;
		asali_->transport_[155].collision =  1.000;
		asali_->transport_[155].MW = 107.086;
		
		asali_->transport_[156].name = (char*) malloc(1 * sizeof(char));
		strcpy(asali_->transport_[156].name,"O");
		asali_->transport_[156].geometry = 0;
		asali_->transport_[156].LJpotential = 80.000;
		asali_->transport_[156].LJdiameter =  2.750;
		asali_->transport_[156].dipole =  0.000;
		asali_->transport_[156].polar =  0.000;
		asali_->transport_[156].collision =  0.000;
		asali_->transport_[156].MW = 15.999;
		
		asali_->transport_[157].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->transport_[157].name,"O2");
		asali_->transport_[157].geometry = 1;
		asali_->transport_[157].LJpotential = 107.400;
		asali_->transport_[157].LJdiameter =  3.458;
		asali_->transport_[157].dipole =  0.000;
		asali_->transport_[157].polar =  1.600;
		asali_->transport_[157].collision =  3.800;
		asali_->transport_[157].MW = 31.999;
		
		asali_->transport_[158].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->transport_[158].name,"OH");
		asali_->transport_[158].geometry = 1;
		asali_->transport_[158].LJpotential = 80.000;
		asali_->transport_[158].LJdiameter =  2.750;
		asali_->transport_[158].dipole =  0.000;
		asali_->transport_[158].polar =  0.000;
		asali_->transport_[158].collision =  0.000;
		asali_->transport_[158].MW = 17.007;
		
		asali_->transport_[159].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[159].name,"IC8H16");
		asali_->transport_[159].geometry = 2;
		asali_->transport_[159].LJpotential = 494.000;
		asali_->transport_[159].LJdiameter =  6.170;
		asali_->transport_[159].dipole =  0.000;
		asali_->transport_[159].polar =  0.000;
		asali_->transport_[159].collision =  1.000;
		asali_->transport_[159].MW = 112.215;
		
		asali_->transport_[160].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[160].name,"NC5H10");
		asali_->transport_[160].geometry = 2;
		asali_->transport_[160].LJpotential = 408.000;
		asali_->transport_[160].LJdiameter =  5.200;
		asali_->transport_[160].dipole =  0.000;
		asali_->transport_[160].polar =  0.000;
		asali_->transport_[160].collision =  1.000;
		asali_->transport_[160].MW = 70.134;
		
		asali_->transport_[161].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[161].name,"PC3H4");
		asali_->transport_[161].geometry = 1;
		asali_->transport_[161].LJpotential = 252.000;
		asali_->transport_[161].LJdiameter =  4.760;
		asali_->transport_[161].dipole =  0.000;
		asali_->transport_[161].polar =  0.000;
		asali_->transport_[161].collision =  1.000;
		asali_->transport_[161].MW = 40.065;
		
		asali_->transport_[162].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[162].name,"CH3CO3H");
		asali_->transport_[162].geometry = 2;
		asali_->transport_[162].LJpotential = 443.200;
		asali_->transport_[162].LJdiameter =  4.120;
		asali_->transport_[162].dipole =  0.000;
		asali_->transport_[162].polar =  0.000;
		asali_->transport_[162].collision =  1.000;
		asali_->transport_[162].MW = 76.052;
		
		asali_->transport_[163].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[163].name,"HCO3H");
		asali_->transport_[163].geometry = 2;
		asali_->transport_[163].LJpotential = 443.200;
		asali_->transport_[163].LJdiameter =  4.120;
		asali_->transport_[163].dipole =  0.000;
		asali_->transport_[163].polar =  0.000;
		asali_->transport_[163].collision =  1.000;
		asali_->transport_[163].MW = 62.025;
		
		asali_->transport_[164].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[164].name,"C3H6O");
		asali_->transport_[164].geometry = 2;
		asali_->transport_[164].LJpotential = 411.000;
		asali_->transport_[164].LJdiameter =  4.820;
		asali_->transport_[164].dipole =  0.000;
		asali_->transport_[164].polar =  0.000;
		asali_->transport_[164].collision =  1.000;
		asali_->transport_[164].MW = 58.080;
		
		asali_->transport_[165].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[165].name,"C5H8");
		asali_->transport_[165].geometry = 2;
		asali_->transport_[165].LJpotential = 408.000;
		asali_->transport_[165].LJdiameter =  5.200;
		asali_->transport_[165].dipole =  0.000;
		asali_->transport_[165].polar =  0.000;
		asali_->transport_[165].collision =  1.000;
		asali_->transport_[165].MW = 68.118;
		
		asali_->transport_[166].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[166].name,"C16H10");
		asali_->transport_[166].geometry = 2;
		asali_->transport_[166].LJpotential = 834.900;
		asali_->transport_[166].LJdiameter =  7.240;
		asali_->transport_[166].dipole =  0.000;
		asali_->transport_[166].polar = 45.000;
		asali_->transport_[166].collision =  1.000;
		asali_->transport_[166].MW = 202.255;
		
		asali_->transport_[167].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[167].name,"NC10-QOOH");
		asali_->transport_[167].geometry = 2;
		asali_->transport_[167].LJpotential = 640.980;
		asali_->transport_[167].LJdiameter =  7.150;
		asali_->transport_[167].dipole =  0.000;
		asali_->transport_[167].polar =  0.000;
		asali_->transport_[167].collision =  1.000;
		asali_->transport_[167].MW = 173.276;
		
		asali_->transport_[168].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[168].name,"NC12-QOOH");
		asali_->transport_[168].geometry = 2;
		asali_->transport_[168].LJpotential = 680.000;
		asali_->transport_[168].LJdiameter =  7.600;
		asali_->transport_[168].dipole =  0.000;
		asali_->transport_[168].polar =  0.000;
		asali_->transport_[168].collision =  1.000;
		asali_->transport_[168].MW = 201.329;
		
		asali_->transport_[169].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[169].name,"C2-QOOH");
		asali_->transport_[169].geometry = 2;
		asali_->transport_[169].LJpotential = 470.600;
		asali_->transport_[169].LJdiameter =  4.410;
		asali_->transport_[169].dipole =  0.000;
		asali_->transport_[169].polar =  0.000;
		asali_->transport_[169].collision =  1.500;
		asali_->transport_[169].MW = 61.061;
		
		asali_->transport_[170].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[170].name,"C2-OOQOOH");
		asali_->transport_[170].geometry = 2;
		asali_->transport_[170].LJpotential = 470.600;
		asali_->transport_[170].LJdiameter =  4.410;
		asali_->transport_[170].dipole =  0.000;
		asali_->transport_[170].polar =  0.000;
		asali_->transport_[170].collision =  1.500;
		asali_->transport_[170].MW = 93.059;
		
		asali_->transport_[171].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[171].name,"C2-OQOOH");
		asali_->transport_[171].geometry = 2;
		asali_->transport_[171].LJpotential = 470.600;
		asali_->transport_[171].LJdiameter =  4.410;
		asali_->transport_[171].dipole =  0.000;
		asali_->transport_[171].polar =  0.000;
		asali_->transport_[171].collision =  1.500;
		asali_->transport_[171].MW = 76.052;
		
		asali_->transport_[172].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[172].name,"NC4-QOOH");
		asali_->transport_[172].geometry = 2;
		asali_->transport_[172].LJpotential = 496.000;
		asali_->transport_[172].LJdiameter =  5.200;
		asali_->transport_[172].dipole =  0.000;
		asali_->transport_[172].polar =  0.000;
		asali_->transport_[172].collision =  1.000;
		asali_->transport_[172].MW = 89.114;
		
		asali_->transport_[173].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[173].name,"NC5-QOOH");
		asali_->transport_[173].geometry = 2;
		asali_->transport_[173].LJpotential = 492.000;
		asali_->transport_[173].LJdiameter =  5.640;
		asali_->transport_[173].dipole =  0.000;
		asali_->transport_[173].polar =  0.000;
		asali_->transport_[173].collision =  1.000;
		asali_->transport_[173].MW = 103.141;
		
		asali_->transport_[174].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[174].name,"NC7-QOOH");
		asali_->transport_[174].geometry = 2;
		asali_->transport_[174].LJpotential = 559.980;
		asali_->transport_[174].LJdiameter =  6.310;
		asali_->transport_[174].dipole =  0.000;
		asali_->transport_[174].polar =  0.000;
		asali_->transport_[174].collision =  1.000;
		asali_->transport_[174].MW = 131.195;
		
		asali_->transport_[175].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[175].name,"DME-QOOH");
		asali_->transport_[175].geometry = 2;
		asali_->transport_[175].LJpotential = 403.400;
		asali_->transport_[175].LJdiameter =  4.810;
		asali_->transport_[175].dipole =  0.000;
		asali_->transport_[175].polar =  0.000;
		asali_->transport_[175].collision =  1.000;
		asali_->transport_[175].MW = 77.060;
		
		asali_->transport_[176].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[176].name,"IC16-QOOH");
		asali_->transport_[176].geometry = 2;
		asali_->transport_[176].LJpotential = 750.000;
		asali_->transport_[176].LJdiameter =  8.350;
		asali_->transport_[176].dipole =  0.000;
		asali_->transport_[176].polar =  0.000;
		asali_->transport_[176].collision =  1.000;
		asali_->transport_[176].MW = 257.437;
		
		asali_->transport_[177].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[177].name,"IC16T-QOOH");
		asali_->transport_[177].geometry = 2;
		asali_->transport_[177].LJpotential = 750.000;
		asali_->transport_[177].LJdiameter =  8.350;
		asali_->transport_[177].dipole =  0.000;
		asali_->transport_[177].polar =  0.000;
		asali_->transport_[177].collision =  1.000;
		asali_->transport_[177].MW = 257.437;
		
		asali_->transport_[178].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[178].name,"IC8-QOOH");
		asali_->transport_[178].geometry = 2;
		asali_->transport_[178].LJpotential = 594.000;
		asali_->transport_[178].LJdiameter =  6.170;
		asali_->transport_[178].dipole =  0.000;
		asali_->transport_[178].polar =  0.000;
		asali_->transport_[178].collision =  1.000;
		asali_->transport_[178].MW = 145.222;
		
		asali_->transport_[179].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[179].name,"IC4P-QOOH");
		asali_->transport_[179].geometry = 2;
		asali_->transport_[179].LJpotential = 496.000;
		asali_->transport_[179].LJdiameter =  5.200;
		asali_->transport_[179].dipole =  0.000;
		asali_->transport_[179].polar =  0.000;
		asali_->transport_[179].collision =  1.000;
		asali_->transport_[179].MW = 89.114;
		
		asali_->transport_[180].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[180].name,"IC4T-QOOH");
		asali_->transport_[180].geometry = 2;
		asali_->transport_[180].LJpotential = 496.000;
		asali_->transport_[180].LJdiameter =  5.200;
		asali_->transport_[180].dipole =  0.000;
		asali_->transport_[180].polar =  0.000;
		asali_->transport_[180].collision =  1.000;
		asali_->transport_[180].MW = 89.114;
		
		asali_->transport_[181].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[181].name,"MCYC6-QOOH");
		asali_->transport_[181].geometry = 2;
		asali_->transport_[181].LJpotential = 595.300;
		asali_->transport_[181].LJdiameter =  5.680;
		asali_->transport_[181].dipole =  0.430;
		asali_->transport_[181].polar = 12.300;
		asali_->transport_[181].collision =  1.000;
		asali_->transport_[181].MW = 129.179;
		
		asali_->transport_[182].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[182].name,"MTBE-QOOH");
		asali_->transport_[182].geometry = 2;
		asali_->transport_[182].LJpotential = 492.000;
		asali_->transport_[182].LJdiameter =  5.640;
		asali_->transport_[182].dipole =  0.000;
		asali_->transport_[182].polar =  0.000;
		asali_->transport_[182].collision =  1.000;
		asali_->transport_[182].MW = 119.141;
		
		asali_->transport_[183].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[183].name,"NEOC5-QOOH");
		asali_->transport_[183].geometry = 2;
		asali_->transport_[183].LJpotential = 492.000;
		asali_->transport_[183].LJdiameter =  5.640;
		asali_->transport_[183].dipole =  0.000;
		asali_->transport_[183].polar =  0.000;
		asali_->transport_[183].collision =  1.000;
		asali_->transport_[183].MW = 103.141;
		
		asali_->transport_[184].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[184].name,"IC8T-QOOH");
		asali_->transport_[184].geometry = 2;
		asali_->transport_[184].LJpotential = 594.000;
		asali_->transport_[184].LJdiameter =  6.170;
		asali_->transport_[184].dipole =  0.000;
		asali_->transport_[184].polar =  0.000;
		asali_->transport_[184].collision =  1.000;
		asali_->transport_[184].MW = 145.222;
		
		asali_->transport_[185].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[185].name,"MCYC6T-QOOH");
		asali_->transport_[185].geometry = 2;
		asali_->transport_[185].LJpotential = 595.300;
		asali_->transport_[185].LJdiameter =  5.680;
		asali_->transport_[185].dipole =  0.430;
		asali_->transport_[185].polar = 12.300;
		asali_->transport_[185].collision =  1.000;
		asali_->transport_[185].MW = 129.179;
		
		asali_->transport_[186].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[186].name,"NC10H21");
		asali_->transport_[186].geometry = 2;
		asali_->transport_[186].LJpotential = 540.980;
		asali_->transport_[186].LJdiameter =  7.150;
		asali_->transport_[186].dipole =  0.000;
		asali_->transport_[186].polar =  0.000;
		asali_->transport_[186].collision =  1.000;
		asali_->transport_[186].MW = 141.277;
		
		asali_->transport_[187].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[187].name,"NC10H21-OO");
		asali_->transport_[187].geometry = 2;
		asali_->transport_[187].LJpotential = 640.980;
		asali_->transport_[187].LJdiameter =  7.150;
		asali_->transport_[187].dipole =  0.000;
		asali_->transport_[187].polar =  0.000;
		asali_->transport_[187].collision =  1.000;
		asali_->transport_[187].MW = 173.276;
		
		asali_->transport_[188].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[188].name,"NC12H25");
		asali_->transport_[188].geometry = 2;
		asali_->transport_[188].LJpotential = 580.000;
		asali_->transport_[188].LJdiameter =  7.600;
		asali_->transport_[188].dipole =  0.000;
		asali_->transport_[188].polar =  0.000;
		asali_->transport_[188].collision =  1.000;
		asali_->transport_[188].MW = 169.331;
		
		asali_->transport_[189].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[189].name,"NC12H25-OO");
		asali_->transport_[189].geometry = 2;
		asali_->transport_[189].LJpotential = 680.000;
		asali_->transport_[189].LJdiameter =  7.600;
		asali_->transport_[189].dipole =  0.000;
		asali_->transport_[189].polar =  0.000;
		asali_->transport_[189].collision =  1.000;
		asali_->transport_[189].MW = 201.329;
		
		asali_->transport_[190].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[190].name,"C2H4OH");
		asali_->transport_[190].geometry = 2;
		asali_->transport_[190].LJpotential = 362.600;
		asali_->transport_[190].LJdiameter =  4.530;
		asali_->transport_[190].dipole =  0.000;
		asali_->transport_[190].polar =  0.000;
		asali_->transport_[190].collision =  1.500;
		asali_->transport_[190].MW = 45.061;
		
		asali_->transport_[191].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[191].name,"CH2CHO");
		asali_->transport_[191].geometry = 2;
		asali_->transport_[191].LJpotential = 436.000;
		asali_->transport_[191].LJdiameter =  3.970;
		asali_->transport_[191].dipole =  0.000;
		asali_->transport_[191].polar =  0.000;
		asali_->transport_[191].collision =  2.000;
		asali_->transport_[191].MW = 43.045;
		
		asali_->transport_[192].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[192].name,"CH3CHOH");
		asali_->transport_[192].geometry = 2;
		asali_->transport_[192].LJpotential = 362.600;
		asali_->transport_[192].LJdiameter =  4.530;
		asali_->transport_[192].dipole =  0.000;
		asali_->transport_[192].polar =  0.000;
		asali_->transport_[192].collision =  1.500;
		asali_->transport_[192].MW = 45.061;
		
		asali_->transport_[193].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[193].name,"NC4H9-OO");
		asali_->transport_[193].geometry = 2;
		asali_->transport_[193].LJpotential = 496.000;
		asali_->transport_[193].LJdiameter =  5.200;
		asali_->transport_[193].dipole =  0.000;
		asali_->transport_[193].polar =  0.000;
		asali_->transport_[193].collision =  1.000;
		asali_->transport_[193].MW = 89.114;
		
		asali_->transport_[194].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[194].name,"NC5H11");
		asali_->transport_[194].geometry = 2;
		asali_->transport_[194].LJpotential = 392.000;
		asali_->transport_[194].LJdiameter =  5.640;
		asali_->transport_[194].dipole =  0.000;
		asali_->transport_[194].polar =  0.000;
		asali_->transport_[194].collision =  1.000;
		asali_->transport_[194].MW = 71.142;
		
		asali_->transport_[195].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[195].name,"NC5H12OO");
		asali_->transport_[195].geometry = 2;
		asali_->transport_[195].LJpotential = 492.000;
		asali_->transport_[195].LJdiameter =  5.640;
		asali_->transport_[195].dipole =  0.000;
		asali_->transport_[195].polar =  0.000;
		asali_->transport_[195].collision =  1.000;
		asali_->transport_[195].MW = 103.141;
		
		asali_->transport_[196].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[196].name,"NC7H15");
		asali_->transport_[196].geometry = 2;
		asali_->transport_[196].LJpotential = 459.980;
		asali_->transport_[196].LJdiameter =  6.310;
		asali_->transport_[196].dipole =  0.000;
		asali_->transport_[196].polar =  0.000;
		asali_->transport_[196].collision =  1.000;
		asali_->transport_[196].MW = 99.196;
		
		asali_->transport_[197].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[197].name,"NC7H15-OO");
		asali_->transport_[197].geometry = 2;
		asali_->transport_[197].LJpotential = 559.980;
		asali_->transport_[197].LJdiameter =  6.310;
		asali_->transport_[197].dipole =  0.000;
		asali_->transport_[197].polar =  0.000;
		asali_->transport_[197].collision =  1.000;
		asali_->transport_[197].MW = 131.195;
		
		asali_->transport_[198].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[198].name,"C12H7");
		asali_->transport_[198].geometry = 2;
		asali_->transport_[198].LJpotential = 693.100;
		asali_->transport_[198].LJdiameter =  6.470;
		asali_->transport_[198].dipole =  0.000;
		asali_->transport_[198].polar = 18.000;
		asali_->transport_[198].collision =  1.000;
		asali_->transport_[198].MW = 151.188;
		
		asali_->transport_[199].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[199].name,"CH3COCH2");
		asali_->transport_[199].geometry = 2;
		asali_->transport_[199].LJpotential = 424.600;
		asali_->transport_[199].LJdiameter =  4.820;
		asali_->transport_[199].dipole =  0.000;
		asali_->transport_[199].polar =  0.000;
		asali_->transport_[199].collision =  1.000;
		asali_->transport_[199].MW = 57.072;
		
		asali_->transport_[200].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[200].name,"C2H4CHO");
		asali_->transport_[200].geometry = 2;
		asali_->transport_[200].LJpotential = 424.600;
		asali_->transport_[200].LJdiameter =  4.820;
		asali_->transport_[200].dipole =  0.000;
		asali_->transport_[200].polar =  0.000;
		asali_->transport_[200].collision =  1.000;
		asali_->transport_[200].MW = 57.072;
		
		asali_->transport_[201].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[201].name,"CYC6-OO");
		asali_->transport_[201].geometry = 2;
		asali_->transport_[201].LJpotential = 568.500;
		asali_->transport_[201].LJdiameter =  5.230;
		asali_->transport_[201].dipole =  0.000;
		asali_->transport_[201].polar = 10.300;
		asali_->transport_[201].collision =  1.000;
		asali_->transport_[201].MW = 115.152;
		
		asali_->transport_[202].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[202].name,"CYC6H11");
		asali_->transport_[202].geometry = 2;
		asali_->transport_[202].LJpotential = 468.500;
		asali_->transport_[202].LJdiameter =  5.230;
		asali_->transport_[202].dipole =  0.000;
		asali_->transport_[202].polar = 10.300;
		asali_->transport_[202].collision =  1.000;
		asali_->transport_[202].MW = 83.153;
		
		asali_->transport_[203].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[203].name,"CYC6H9");
		asali_->transport_[203].geometry = 2;
		asali_->transport_[203].LJpotential = 468.500;
		asali_->transport_[203].LJdiameter =  5.230;
		asali_->transport_[203].dipole =  0.000;
		asali_->transport_[203].polar = 10.300;
		asali_->transport_[203].collision =  1.000;
		asali_->transport_[203].MW = 81.137;
		
		asali_->transport_[204].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[204].name,"CYC5H5");
		asali_->transport_[204].geometry = 2;
		asali_->transport_[204].LJpotential = 408.000;
		asali_->transport_[204].LJdiameter =  5.200;
		asali_->transport_[204].dipole =  0.000;
		asali_->transport_[204].polar =  0.000;
		asali_->transport_[204].collision =  1.000;
		asali_->transport_[204].MW = 65.095;
		
		asali_->transport_[205].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[205].name,"RDIPE");
		asali_->transport_[205].geometry = 2;
		asali_->transport_[205].LJpotential = 432.000;
		asali_->transport_[205].LJdiameter =  6.000;
		asali_->transport_[205].dipole =  0.000;
		asali_->transport_[205].polar =  0.000;
		asali_->transport_[205].collision =  1.000;
		asali_->transport_[205].MW = 101.169;
		
		asali_->transport_[206].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[206].name,"CH3OCH2");
		asali_->transport_[206].geometry = 2;
		asali_->transport_[206].LJpotential = 303.400;
		asali_->transport_[206].LJdiameter =  4.810;
		asali_->transport_[206].dipole =  0.000;
		asali_->transport_[206].polar =  0.000;
		asali_->transport_[206].collision =  1.000;
		asali_->transport_[206].MW = 45.061;
		
		asali_->transport_[207].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[207].name,"DME-OO");
		asali_->transport_[207].geometry = 2;
		asali_->transport_[207].LJpotential = 403.400;
		asali_->transport_[207].LJdiameter =  4.810;
		asali_->transport_[207].dipole =  0.000;
		asali_->transport_[207].polar =  0.000;
		asali_->transport_[207].collision =  1.000;
		asali_->transport_[207].MW = 77.060;
		
		asali_->transport_[208].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[208].name,"C6H4C2H");
		asali_->transport_[208].geometry = 2;
		asali_->transport_[208].LJpotential = 535.600;
		asali_->transport_[208].LJdiameter =  5.720;
		asali_->transport_[208].dipole =  0.770;
		asali_->transport_[208].polar = 12.000;
		asali_->transport_[208].collision =  1.000;
		asali_->transport_[208].MW = 101.128;
		
		asali_->transport_[209].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[209].name,"RBIPHENYL");
		asali_->transport_[209].geometry = 2;
		asali_->transport_[209].LJpotential = 676.500;
		asali_->transport_[209].LJdiameter =  6.310;
		asali_->transport_[209].dipole =  0.000;
		asali_->transport_[209].polar =  0.000;
		asali_->transport_[209].collision =  1.000;
		asali_->transport_[209].MW = 153.203;
		
		asali_->transport_[210].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[210].name,"C14H9");
		asali_->transport_[210].geometry = 2;
		asali_->transport_[210].LJpotential = 772.000;
		asali_->transport_[210].LJdiameter =  6.960;
		asali_->transport_[210].dipole =  0.000;
		asali_->transport_[210].polar = 38.800;
		asali_->transport_[210].collision =  1.000;
		asali_->transport_[210].MW = 177.225;
		
		asali_->transport_[211].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[211].name,"C10H7");
		asali_->transport_[211].geometry = 2;
		asali_->transport_[211].LJpotential = 630.400;
		asali_->transport_[211].LJdiameter =  6.180;
		asali_->transport_[211].dipole =  0.000;
		asali_->transport_[211].polar = 16.500;
		asali_->transport_[211].collision =  1.000;
		asali_->transport_[211].MW = 127.166;
		
		asali_->transport_[212].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[212].name,"IC16H33-OO");
		asali_->transport_[212].geometry = 2;
		asali_->transport_[212].LJpotential = 750.000;
		asali_->transport_[212].LJdiameter =  8.350;
		asali_->transport_[212].dipole =  0.000;
		asali_->transport_[212].polar =  0.000;
		asali_->transport_[212].collision =  1.000;
		asali_->transport_[212].MW = 257.437;
		
		asali_->transport_[213].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[213].name,"IC16H33");
		asali_->transport_[213].geometry = 2;
		asali_->transport_[213].LJpotential = 650.000;
		asali_->transport_[213].LJdiameter =  8.350;
		asali_->transport_[213].dipole =  0.000;
		asali_->transport_[213].polar =  0.000;
		asali_->transport_[213].collision =  1.000;
		asali_->transport_[213].MW = 225.438;
		
		asali_->transport_[214].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[214].name,"IC8H17");
		asali_->transport_[214].geometry = 2;
		asali_->transport_[214].LJpotential = 494.000;
		asali_->transport_[214].LJdiameter =  6.170;
		asali_->transport_[214].dipole =  0.000;
		asali_->transport_[214].polar =  0.000;
		asali_->transport_[214].collision =  1.000;
		asali_->transport_[214].MW = 113.223;
		
		asali_->transport_[215].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[215].name,"IC8H17-OO");
		asali_->transport_[215].geometry = 2;
		asali_->transport_[215].LJpotential = 594.000;
		asali_->transport_[215].LJdiameter =  6.170;
		asali_->transport_[215].dipole =  0.000;
		asali_->transport_[215].polar =  0.000;
		asali_->transport_[215].collision =  1.000;
		asali_->transport_[215].MW = 145.222;
		
		asali_->transport_[216].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[216].name,"INDENYL");
		asali_->transport_[216].geometry = 2;
		asali_->transport_[216].LJpotential = 588.600;
		asali_->transport_[216].LJdiameter =  5.960;
		asali_->transport_[216].dipole =  0.000;
		asali_->transport_[216].polar =  0.000;
		asali_->transport_[216].collision =  1.000;
		asali_->transport_[216].MW = 115.155;
		
		asali_->transport_[217].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[217].name,"RMCYC6-OO");
		asali_->transport_[217].geometry = 2;
		asali_->transport_[217].LJpotential = 595.300;
		asali_->transport_[217].LJdiameter =  5.680;
		asali_->transport_[217].dipole =  0.430;
		asali_->transport_[217].polar = 12.300;
		asali_->transport_[217].collision =  1.000;
		asali_->transport_[217].MW = 129.179;
		
		asali_->transport_[218].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[218].name,"RMCYC6");
		asali_->transport_[218].geometry = 2;
		asali_->transport_[218].LJpotential = 495.300;
		asali_->transport_[218].LJdiameter =  5.680;
		asali_->transport_[218].dipole =  0.430;
		asali_->transport_[218].polar = 12.300;
		asali_->transport_[218].collision =  1.000;
		asali_->transport_[218].MW = 97.180;
		
		asali_->transport_[219].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[219].name,"C10H7CH2");
		asali_->transport_[219].geometry = 2;
		asali_->transport_[219].LJpotential = 660.000;
		asali_->transport_[219].LJdiameter =  6.350;
		asali_->transport_[219].dipole =  0.000;
		asali_->transport_[219].polar =  0.000;
		asali_->transport_[219].collision =  1.000;
		asali_->transport_[219].MW = 141.192;
		
		asali_->transport_[220].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[220].name,"C10H6CH3");
		asali_->transport_[220].geometry = 2;
		asali_->transport_[220].LJpotential = 660.000;
		asali_->transport_[220].LJdiameter =  6.350;
		asali_->transport_[220].dipole =  0.000;
		asali_->transport_[220].polar =  0.000;
		asali_->transport_[220].collision =  1.000;
		asali_->transport_[220].MW = 141.192;
		
		asali_->transport_[221].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[221].name,"C6H4CH3");
		asali_->transport_[221].geometry = 2;
		asali_->transport_[221].LJpotential = 495.300;
		asali_->transport_[221].LJdiameter =  5.680;
		asali_->transport_[221].dipole =  0.000;
		asali_->transport_[221].polar =  0.000;
		asali_->transport_[221].collision =  1.000;
		asali_->transport_[221].MW = 91.133;
		
		asali_->transport_[222].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[222].name,"RMTBE");
		asali_->transport_[222].geometry = 2;
		asali_->transport_[222].LJpotential = 392.000;
		asali_->transport_[222].LJdiameter =  5.640;
		asali_->transport_[222].dipole =  0.000;
		asali_->transport_[222].polar =  0.000;
		asali_->transport_[222].collision =  1.000;
		asali_->transport_[222].MW = 87.142;
		
		asali_->transport_[223].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[223].name,"MTBE-OO");
		asali_->transport_[223].geometry = 2;
		asali_->transport_[223].LJpotential = 492.000;
		asali_->transport_[223].LJdiameter =  5.640;
		asali_->transport_[223].dipole =  0.000;
		asali_->transport_[223].polar =  0.000;
		asali_->transport_[223].collision =  1.000;
		asali_->transport_[223].MW = 119.141;
		
		asali_->transport_[224].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[224].name,"C10H7O");
		asali_->transport_[224].geometry = 2;
		asali_->transport_[224].LJpotential = 630.400;
		asali_->transport_[224].LJdiameter =  6.180;
		asali_->transport_[224].dipole =  0.000;
		asali_->transport_[224].polar =  0.000;
		asali_->transport_[224].collision =  1.000;
		asali_->transport_[224].MW = 143.165;
		
		asali_->transport_[225].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[225].name,"NEOC5H11");
		asali_->transport_[225].geometry = 2;
		asali_->transport_[225].LJpotential = 392.000;
		asali_->transport_[225].LJdiameter =  5.640;
		asali_->transport_[225].dipole =  0.000;
		asali_->transport_[225].polar =  0.000;
		asali_->transport_[225].collision =  1.000;
		asali_->transport_[225].MW = 71.142;
		
		asali_->transport_[226].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[226].name,"NEOC5H11-OO");
		asali_->transport_[226].geometry = 2;
		asali_->transport_[226].LJpotential = 492.000;
		asali_->transport_[226].LJdiameter =  5.640;
		asali_->transport_[226].dipole =  0.000;
		asali_->transport_[226].polar =  0.000;
		asali_->transport_[226].collision =  1.000;
		asali_->transport_[226].MW = 103.141;
		
		asali_->transport_[227].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[227].name,"C16H9");
		asali_->transport_[227].geometry = 2;
		asali_->transport_[227].LJpotential = 834.900;
		asali_->transport_[227].LJdiameter =  7.240;
		asali_->transport_[227].dipole =  0.000;
		asali_->transport_[227].polar = 45.000;
		asali_->transport_[227].collision =  1.000;
		asali_->transport_[227].MW = 201.247;
		
		asali_->transport_[228].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[228].name,"C6H5C2H2");
		asali_->transport_[228].geometry = 2;
		asali_->transport_[228].LJpotential = 546.200;
		asali_->transport_[228].LJdiameter =  6.000;
		asali_->transport_[228].dipole =  0.000;
		asali_->transport_[228].polar =  0.000;
		asali_->transport_[228].collision =  1.000;
		asali_->transport_[228].MW = 103.144;
		
		asali_->transport_[229].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[229].name,"RXYLENE");
		asali_->transport_[229].geometry = 2;
		asali_->transport_[229].LJpotential = 523.600;
		asali_->transport_[229].LJdiameter =  5.960;
		asali_->transport_[229].dipole =  0.000;
		asali_->transport_[229].polar =  0.000;
		asali_->transport_[229].collision =  1.000;
		asali_->transport_[229].MW = 105.159;
		
		asali_->transport_[230].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[230].name,"C6H5C2H3");
		asali_->transport_[230].geometry = 2;
		asali_->transport_[230].LJpotential = 546.200;
		asali_->transport_[230].LJdiameter =  6.000;
		asali_->transport_[230].dipole =  0.130;
		asali_->transport_[230].polar = 15.000;
		asali_->transport_[230].collision =  1.000;
		asali_->transport_[230].MW = 104.152;
		
		asali_->transport_[231].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[231].name,"TAME");
		asali_->transport_[231].geometry = 2;
		asali_->transport_[231].LJpotential = 432.000;
		asali_->transport_[231].LJdiameter =  6.000;
		asali_->transport_[231].dipole =  0.000;
		asali_->transport_[231].polar =  0.000;
		asali_->transport_[231].collision =  1.000;
		asali_->transport_[231].MW = 102.177;
		
		asali_->transport_[232].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[232].name,"TETRALIN");
		asali_->transport_[232].geometry = 2;
		asali_->transport_[232].LJpotential = 630.400;
		asali_->transport_[232].LJdiameter =  6.180;
		asali_->transport_[232].dipole =  0.000;
		asali_->transport_[232].polar = 16.500;
		asali_->transport_[232].collision =  1.000;
		asali_->transport_[232].MW = 132.205;
		
		asali_->transport_[233].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[233].name,"DECALIN");
		asali_->transport_[233].geometry = 2;
		asali_->transport_[233].LJpotential = 630.400;
		asali_->transport_[233].LJdiameter =  6.180;
		asali_->transport_[233].dipole =  0.000;
		asali_->transport_[233].polar = 16.500;
		asali_->transport_[233].collision =  1.000;
		asali_->transport_[233].MW = 138.253;
		
		asali_->transport_[234].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[234].name,"RDECALIN");
		asali_->transport_[234].geometry = 2;
		asali_->transport_[234].LJpotential = 630.400;
		asali_->transport_[234].LJdiameter =  6.180;
		asali_->transport_[234].dipole =  0.000;
		asali_->transport_[234].polar = 16.500;
		asali_->transport_[234].collision =  1.000;
		asali_->transport_[234].MW = 137.245;
		
		asali_->transport_[235].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[235].name,"C7H8");
		asali_->transport_[235].geometry = 2;
		asali_->transport_[235].LJpotential = 495.300;
		asali_->transport_[235].LJdiameter =  5.680;
		asali_->transport_[235].dipole =  0.430;
		asali_->transport_[235].polar = 12.300;
		asali_->transport_[235].collision =  1.000;
		asali_->transport_[235].MW = 92.141;
		
		asali_->transport_[236].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[236].name,"C2H3");
		asali_->transport_[236].geometry = 2;
		asali_->transport_[236].LJpotential = 209.000;
		asali_->transport_[236].LJdiameter =  4.100;
		asali_->transport_[236].dipole =  0.000;
		asali_->transport_[236].polar =  0.000;
		asali_->transport_[236].collision =  1.000;
		asali_->transport_[236].MW = 27.046;
		
		asali_->transport_[237].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[237].name,"XYLENE");
		asali_->transport_[237].geometry = 2;
		asali_->transport_[237].LJpotential = 523.600;
		asali_->transport_[237].LJdiameter =  5.960;
		asali_->transport_[237].dipole =  0.000;
		asali_->transport_[237].polar =  0.000;
		asali_->transport_[237].collision =  1.000;
		asali_->transport_[237].MW = 106.167;
		
		asali_->transport_[238].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[238].name,"NC10-OOQOOH");
		asali_->transport_[238].geometry = 2;
		asali_->transport_[238].LJpotential = 640.980;
		asali_->transport_[238].LJdiameter =  7.150;
		asali_->transport_[238].dipole =  0.000;
		asali_->transport_[238].polar =  0.000;
		asali_->transport_[238].collision =  1.000;
		asali_->transport_[238].MW = 205.274;
		
		asali_->transport_[239].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[239].name,"NC12-OOQOOH");
		asali_->transport_[239].geometry = 2;
		asali_->transport_[239].LJpotential = 680.000;
		asali_->transport_[239].LJdiameter =  7.600;
		asali_->transport_[239].dipole =  0.000;
		asali_->transport_[239].polar =  0.000;
		asali_->transport_[239].collision =  1.000;
		asali_->transport_[239].MW = 233.328;
		
		asali_->transport_[240].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[240].name,"NC4-OOQOOH");
		asali_->transport_[240].geometry = 2;
		asali_->transport_[240].LJpotential = 496.000;
		asali_->transport_[240].LJdiameter =  5.200;
		asali_->transport_[240].dipole =  0.000;
		asali_->transport_[240].polar =  0.000;
		asali_->transport_[240].collision =  1.000;
		asali_->transport_[240].MW = 121.113;
		
		asali_->transport_[241].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[241].name,"NC5-OOQOOH");
		asali_->transport_[241].geometry = 2;
		asali_->transport_[241].LJpotential = 492.000;
		asali_->transport_[241].LJdiameter =  5.640;
		asali_->transport_[241].dipole =  0.000;
		asali_->transport_[241].polar =  0.000;
		asali_->transport_[241].collision =  1.000;
		asali_->transport_[241].MW = 135.140;
		
		asali_->transport_[242].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[242].name,"NC7-OOQOOH");
		asali_->transport_[242].geometry = 2;
		asali_->transport_[242].LJpotential = 559.980;
		asali_->transport_[242].LJdiameter =  6.310;
		asali_->transport_[242].dipole =  0.000;
		asali_->transport_[242].polar =  0.000;
		asali_->transport_[242].collision =  1.000;
		asali_->transport_[242].MW = 163.194;
		
		asali_->transport_[243].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[243].name,"DME-OOQOOH");
		asali_->transport_[243].geometry = 2;
		asali_->transport_[243].LJpotential = 403.400;
		asali_->transport_[243].LJdiameter =  4.810;
		asali_->transport_[243].dipole =  0.000;
		asali_->transport_[243].polar =  0.000;
		asali_->transport_[243].collision =  1.000;
		asali_->transport_[243].MW = 109.059;
		
		asali_->transport_[244].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[244].name,"IC16-OOQOOH");
		asali_->transport_[244].geometry = 2;
		asali_->transport_[244].LJpotential = 750.000;
		asali_->transport_[244].LJdiameter =  8.350;
		asali_->transport_[244].dipole =  0.000;
		asali_->transport_[244].polar =  0.000;
		asali_->transport_[244].collision =  1.000;
		asali_->transport_[244].MW = 289.436;
		
		asali_->transport_[245].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->transport_[245].name,"IC16T-OOQOOH");
		asali_->transport_[245].geometry = 2;
		asali_->transport_[245].LJpotential = 750.000;
		asali_->transport_[245].LJdiameter =  8.350;
		asali_->transport_[245].dipole =  0.000;
		asali_->transport_[245].polar =  0.000;
		asali_->transport_[245].collision =  1.000;
		asali_->transport_[245].MW = 289.436;
		
		asali_->transport_[246].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[246].name,"IC8-OOQOOH");
		asali_->transport_[246].geometry = 2;
		asali_->transport_[246].LJpotential = 594.000;
		asali_->transport_[246].LJdiameter =  6.170;
		asali_->transport_[246].dipole =  0.000;
		asali_->transport_[246].polar =  0.000;
		asali_->transport_[246].collision =  1.000;
		asali_->transport_[246].MW = 177.221;
		
		asali_->transport_[247].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[247].name,"IC4P-OOQOOH");
		asali_->transport_[247].geometry = 2;
		asali_->transport_[247].LJpotential = 496.000;
		asali_->transport_[247].LJdiameter =  5.200;
		asali_->transport_[247].dipole =  0.000;
		asali_->transport_[247].polar =  0.000;
		asali_->transport_[247].collision =  1.000;
		asali_->transport_[247].MW = 121.113;
		
		asali_->transport_[248].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[248].name,"IC4T-OOQOOH");
		asali_->transport_[248].geometry = 2;
		asali_->transport_[248].LJpotential = 496.000;
		asali_->transport_[248].LJdiameter =  5.200;
		asali_->transport_[248].dipole =  0.000;
		asali_->transport_[248].polar =  0.000;
		asali_->transport_[248].collision =  1.000;
		asali_->transport_[248].MW = 121.113;
		
		asali_->transport_[249].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->transport_[249].name,"MCYC6-OOQOOH");
		asali_->transport_[249].geometry = 2;
		asali_->transport_[249].LJpotential = 595.300;
		asali_->transport_[249].LJdiameter =  5.680;
		asali_->transport_[249].dipole =  0.430;
		asali_->transport_[249].polar = 12.300;
		asali_->transport_[249].collision =  1.000;
		asali_->transport_[249].MW = 161.178;
		
		asali_->transport_[250].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[250].name,"MTBE-OOQOOH");
		asali_->transport_[250].geometry = 2;
		asali_->transport_[250].LJpotential = 492.000;
		asali_->transport_[250].LJdiameter =  5.640;
		asali_->transport_[250].dipole =  0.000;
		asali_->transport_[250].polar =  0.000;
		asali_->transport_[250].collision =  1.000;
		asali_->transport_[250].MW = 151.139;
		
		asali_->transport_[251].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->transport_[251].name,"NEOC5-OOQOOH");
		asali_->transport_[251].geometry = 2;
		asali_->transport_[251].LJpotential = 492.000;
		asali_->transport_[251].LJdiameter =  5.640;
		asali_->transport_[251].dipole =  0.000;
		asali_->transport_[251].polar =  0.000;
		asali_->transport_[251].collision =  1.000;
		asali_->transport_[251].MW = 135.140;
		
		asali_->transport_[252].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->transport_[252].name,"MCYC6T-OOQOOH");
		asali_->transport_[252].geometry = 2;
		asali_->transport_[252].LJpotential = 595.300;
		asali_->transport_[252].LJdiameter =  5.680;
		asali_->transport_[252].dipole =  0.430;
		asali_->transport_[252].polar = 12.300;
		asali_->transport_[252].collision =  1.000;
		asali_->transport_[252].MW = 161.178;
		
		asali_->transport_[253].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[253].name,"NC16H34");
		asali_->transport_[253].geometry = 2;
		asali_->transport_[253].LJpotential = 650.000;
		asali_->transport_[253].LJdiameter =  8.350;
		asali_->transport_[253].dipole =  0.000;
		asali_->transport_[253].polar =  0.000;
		asali_->transport_[253].collision =  1.000;
		asali_->transport_[253].MW = 226.446;
		
		asali_->transport_[254].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[254].name,"NC16H33");
		asali_->transport_[254].geometry = 2;
		asali_->transport_[254].LJpotential = 650.000;
		asali_->transport_[254].LJdiameter =  8.350;
		asali_->transport_[254].dipole =  0.000;
		asali_->transport_[254].polar =  0.000;
		asali_->transport_[254].collision =  1.000;
		asali_->transport_[254].MW = 225.438;
		
		asali_->transport_[255].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[255].name,"NC16H33-OO");
		asali_->transport_[255].geometry = 2;
		asali_->transport_[255].LJpotential = 750.000;
		asali_->transport_[255].LJdiameter =  8.350;
		asali_->transport_[255].dipole =  0.000;
		asali_->transport_[255].polar =  0.000;
		asali_->transport_[255].collision =  1.000;
		asali_->transport_[255].MW = 257.437;
		
		asali_->transport_[256].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[256].name,"NC16-QOOH");
		asali_->transport_[256].geometry = 2;
		asali_->transport_[256].LJpotential = 750.000;
		asali_->transport_[256].LJdiameter =  8.350;
		asali_->transport_[256].dipole =  0.000;
		asali_->transport_[256].polar =  0.000;
		asali_->transport_[256].collision =  1.000;
		asali_->transport_[256].MW = 257.437;
		
		asali_->transport_[257].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[257].name,"NC16-OOQOOH");
		asali_->transport_[257].geometry = 2;
		asali_->transport_[257].LJpotential = 750.000;
		asali_->transport_[257].LJdiameter =  8.350;
		asali_->transport_[257].dipole =  0.000;
		asali_->transport_[257].polar =  0.000;
		asali_->transport_[257].collision =  1.000;
		asali_->transport_[257].MW = 289.436;
		
		asali_->transport_[258].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[258].name,"NC16-OQOOH");
		asali_->transport_[258].geometry = 2;
		asali_->transport_[258].LJpotential = 750.000;
		asali_->transport_[258].LJdiameter =  8.350;
		asali_->transport_[258].dipole =  0.000;
		asali_->transport_[258].polar =  0.000;
		asali_->transport_[258].collision =  1.000;
		asali_->transport_[258].MW = 272.428;
		
		asali_->transport_[259].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->transport_[259].name,"CN");
		asali_->transport_[259].geometry = 1;
		asali_->transport_[259].LJpotential = 75.000;
		asali_->transport_[259].LJdiameter =  3.856;
		asali_->transport_[259].dipole =  0.000;
		asali_->transport_[259].polar =  0.000;
		asali_->transport_[259].collision =  1.000;
		asali_->transport_[259].MW = 26.018;
		
		asali_->transport_[260].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[260].name,"H2CN");
		asali_->transport_[260].geometry = 1;
		asali_->transport_[260].LJpotential = 569.000;
		asali_->transport_[260].LJdiameter =  3.630;
		asali_->transport_[260].dipole =  0.000;
		asali_->transport_[260].polar =  0.000;
		asali_->transport_[260].collision =  1.000;
		asali_->transport_[260].MW = 28.034;
		
		asali_->transport_[261].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[261].name,"H2NO");
		asali_->transport_[261].geometry = 2;
		asali_->transport_[261].LJpotential = 116.700;
		asali_->transport_[261].LJdiameter =  3.492;
		asali_->transport_[261].dipole =  0.000;
		asali_->transport_[261].polar =  0.000;
		asali_->transport_[261].collision =  1.000;
		asali_->transport_[261].MW = 32.022;
		
		asali_->transport_[262].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[262].name,"HCN");
		asali_->transport_[262].geometry = 1;
		asali_->transport_[262].LJpotential = 569.000;
		asali_->transport_[262].LJdiameter =  3.630;
		asali_->transport_[262].dipole =  0.000;
		asali_->transport_[262].polar =  0.000;
		asali_->transport_[262].collision =  1.000;
		asali_->transport_[262].MW = 27.026;
		
		asali_->transport_[263].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[263].name,"HCNO");
		asali_->transport_[263].geometry = 2;
		asali_->transport_[263].LJpotential = 232.400;
		asali_->transport_[263].LJdiameter =  3.828;
		asali_->transport_[263].dipole =  0.000;
		asali_->transport_[263].polar =  0.000;
		asali_->transport_[263].collision =  1.000;
		asali_->transport_[263].MW = 43.025;
		
		asali_->transport_[264].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[264].name,"HOCN");
		asali_->transport_[264].geometry = 2;
		asali_->transport_[264].LJpotential = 232.400;
		asali_->transport_[264].LJdiameter =  3.828;
		asali_->transport_[264].dipole =  0.000;
		asali_->transport_[264].polar =  0.000;
		asali_->transport_[264].collision =  1.000;
		asali_->transport_[264].MW = 43.025;
		
		asali_->transport_[265].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[265].name,"HNCO");
		asali_->transport_[265].geometry = 2;
		asali_->transport_[265].LJpotential = 232.400;
		asali_->transport_[265].LJdiameter =  3.828;
		asali_->transport_[265].dipole =  0.000;
		asali_->transport_[265].polar =  0.000;
		asali_->transport_[265].collision =  1.000;
		asali_->transport_[265].MW = 43.025;
		
		asali_->transport_[266].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[266].name,"HNNO");
		asali_->transport_[266].geometry = 2;
		asali_->transport_[266].LJpotential = 232.400;
		asali_->transport_[266].LJdiameter =  3.828;
		asali_->transport_[266].dipole =  0.000;
		asali_->transport_[266].polar =  0.000;
		asali_->transport_[266].collision =  1.000;
		asali_->transport_[266].MW = 45.021;
		
		asali_->transport_[267].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[267].name,"HNO");
		asali_->transport_[267].geometry = 2;
		asali_->transport_[267].LJpotential = 116.700;
		asali_->transport_[267].LJdiameter =  3.492;
		asali_->transport_[267].dipole =  0.000;
		asali_->transport_[267].polar =  0.000;
		asali_->transport_[267].collision =  1.000;
		asali_->transport_[267].MW = 31.014;
		
		asali_->transport_[268].name = (char*) malloc(1 * sizeof(char));
		strcpy(asali_->transport_[268].name,"N");
		asali_->transport_[268].geometry = 0;
		asali_->transport_[268].LJpotential = 71.400;
		asali_->transport_[268].LJdiameter =  3.298;
		asali_->transport_[268].dipole =  0.000;
		asali_->transport_[268].polar =  0.000;
		asali_->transport_[268].collision =  0.000;
		asali_->transport_[268].MW = 14.007;
		
		asali_->transport_[269].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[269].name,"N2H2");
		asali_->transport_[269].geometry = 2;
		asali_->transport_[269].LJpotential = 71.400;
		asali_->transport_[269].LJdiameter =  3.798;
		asali_->transport_[269].dipole =  0.000;
		asali_->transport_[269].polar =  0.000;
		asali_->transport_[269].collision =  1.000;
		asali_->transport_[269].MW = 30.029;
		
		asali_->transport_[270].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[270].name,"N2H3");
		asali_->transport_[270].geometry = 2;
		asali_->transport_[270].LJpotential = 200.000;
		asali_->transport_[270].LJdiameter =  3.900;
		asali_->transport_[270].dipole =  0.000;
		asali_->transport_[270].polar =  0.000;
		asali_->transport_[270].collision =  1.000;
		asali_->transport_[270].MW = 31.037;
		
		asali_->transport_[271].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[271].name,"N2H4");
		asali_->transport_[271].geometry = 2;
		asali_->transport_[271].LJpotential = 205.000;
		asali_->transport_[271].LJdiameter =  4.230;
		asali_->transport_[271].dipole =  0.000;
		asali_->transport_[271].polar =  4.260;
		asali_->transport_[271].collision =  1.500;
		asali_->transport_[271].MW = 32.045;
		
		asali_->transport_[272].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[272].name,"N2O");
		asali_->transport_[272].geometry = 1;
		asali_->transport_[272].LJpotential = 232.400;
		asali_->transport_[272].LJdiameter =  3.828;
		asali_->transport_[272].dipole =  0.000;
		asali_->transport_[272].polar =  0.000;
		asali_->transport_[272].collision =  1.000;
		asali_->transport_[272].MW = 44.013;
		
		asali_->transport_[273].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[273].name,"NCO");
		asali_->transport_[273].geometry = 1;
		asali_->transport_[273].LJpotential = 232.400;
		asali_->transport_[273].LJdiameter =  3.828;
		asali_->transport_[273].dipole =  0.000;
		asali_->transport_[273].polar =  0.000;
		asali_->transport_[273].collision =  1.000;
		asali_->transport_[273].MW = 42.017;
		
		asali_->transport_[274].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->transport_[274].name,"NH");
		asali_->transport_[274].geometry = 1;
		asali_->transport_[274].LJpotential = 80.000;
		asali_->transport_[274].LJdiameter =  2.650;
		asali_->transport_[274].dipole =  0.000;
		asali_->transport_[274].polar =  0.000;
		asali_->transport_[274].collision =  4.000;
		asali_->transport_[274].MW = 15.015;
		
		asali_->transport_[275].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[275].name,"NH2");
		asali_->transport_[275].geometry = 2;
		asali_->transport_[275].LJpotential = 80.000;
		asali_->transport_[275].LJdiameter =  2.650;
		asali_->transport_[275].dipole =  0.000;
		asali_->transport_[275].polar =  2.260;
		asali_->transport_[275].collision =  4.000;
		asali_->transport_[275].MW = 16.023;
		
		asali_->transport_[276].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[276].name,"NH3");
		asali_->transport_[276].geometry = 2;
		asali_->transport_[276].LJpotential = 481.000;
		asali_->transport_[276].LJdiameter =  2.920;
		asali_->transport_[276].dipole =  1.470;
		asali_->transport_[276].polar =  0.000;
		asali_->transport_[276].collision = 10.000;
		asali_->transport_[276].MW = 17.031;
		
		asali_->transport_[277].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[277].name,"NNH");
		asali_->transport_[277].geometry = 2;
		asali_->transport_[277].LJpotential = 71.400;
		asali_->transport_[277].LJdiameter =  3.798;
		asali_->transport_[277].dipole =  0.000;
		asali_->transport_[277].polar =  0.000;
		asali_->transport_[277].collision =  1.000;
		asali_->transport_[277].MW = 29.021;
		
		asali_->transport_[278].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->transport_[278].name,"NO");
		asali_->transport_[278].geometry = 1;
		asali_->transport_[278].LJpotential = 97.500;
		asali_->transport_[278].LJdiameter =  3.621;
		asali_->transport_[278].dipole =  0.000;
		asali_->transport_[278].polar =  1.760;
		asali_->transport_[278].collision =  4.000;
		asali_->transport_[278].MW = 30.006;
		
		asali_->transport_[279].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[279].name,"NO2");
		asali_->transport_[279].geometry = 2;
		asali_->transport_[279].LJpotential = 200.000;
		asali_->transport_[279].LJdiameter =  3.500;
		asali_->transport_[279].dipole =  0.000;
		asali_->transport_[279].polar =  0.000;
		asali_->transport_[279].collision =  1.000;
		asali_->transport_[279].MW = 46.006;
		
		asali_->transport_[280].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[280].name,"HONO");
		asali_->transport_[280].geometry = 2;
		asali_->transport_[280].LJpotential = 200.000;
		asali_->transport_[280].LJdiameter =  3.500;
		asali_->transport_[280].dipole =  0.000;
		asali_->transport_[280].polar =  0.000;
		asali_->transport_[280].collision =  1.000;
		asali_->transport_[280].MW = 47.014;
		
		asali_->transport_[281].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[281].name,"HNO2");
		asali_->transport_[281].geometry = 2;
		asali_->transport_[281].LJpotential = 200.000;
		asali_->transport_[281].LJdiameter =  3.500;
		asali_->transport_[281].dipole =  0.000;
		asali_->transport_[281].polar =  0.000;
		asali_->transport_[281].collision =  1.000;
		asali_->transport_[281].MW = 47.014;
		
		asali_->transport_[282].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[282].name,"NO3");
		asali_->transport_[282].geometry = 2;
		asali_->transport_[282].LJpotential = 300.000;
		asali_->transport_[282].LJdiameter =  3.500;
		asali_->transport_[282].dipole =  0.000;
		asali_->transport_[282].polar =  0.000;
		asali_->transport_[282].collision =  1.000;
		asali_->transport_[282].MW = 62.005;
		
		asali_->transport_[283].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[283].name,"HONO2");
		asali_->transport_[283].geometry = 2;
		asali_->transport_[283].LJpotential = 300.000;
		asali_->transport_[283].LJdiameter =  3.500;
		asali_->transport_[283].dipole =  0.000;
		asali_->transport_[283].polar =  0.000;
		asali_->transport_[283].collision =  1.000;
		asali_->transport_[283].MW = 63.013;
		
		asali_->transport_[284].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[284].name,"CH3CN");
		asali_->transport_[284].geometry = 1;
		asali_->transport_[284].LJpotential = 500.000;
		asali_->transport_[284].LJdiameter =  4.630;
		asali_->transport_[284].dipole =  0.000;
		asali_->transport_[284].polar =  0.000;
		asali_->transport_[284].collision =  1.000;
		asali_->transport_[284].MW = 41.053;
		
		asali_->transport_[285].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[285].name,"CH3NO2");
		asali_->transport_[285].geometry = 2;
		asali_->transport_[285].LJpotential = 200.000;
		asali_->transport_[285].LJdiameter =  4.500;
		asali_->transport_[285].dipole =  0.000;
		asali_->transport_[285].polar =  0.000;
		asali_->transport_[285].collision =  1.000;
		asali_->transport_[285].MW = 61.040;
		
		asali_->transport_[286].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[286].name,"CH3ONO");
		asali_->transport_[286].geometry = 2;
		asali_->transport_[286].LJpotential = 200.000;
		asali_->transport_[286].LJdiameter =  4.500;
		asali_->transport_[286].dipole =  0.000;
		asali_->transport_[286].polar =  0.000;
		asali_->transport_[286].collision =  1.000;
		asali_->transport_[286].MW = 61.040;
		
		asali_->transport_[287].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[287].name,"CH3NO");
		asali_->transport_[287].geometry = 1;
		asali_->transport_[287].LJpotential = 97.500;
		asali_->transport_[287].LJdiameter =  3.621;
		asali_->transport_[287].dipole =  0.000;
		asali_->transport_[287].polar =  1.760;
		asali_->transport_[287].collision =  4.000;
		asali_->transport_[287].MW = 45.041;
		
		asali_->transport_[288].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[288].name,"CH3ONO2");
		asali_->transport_[288].geometry = 2;
		asali_->transport_[288].LJpotential = 300.000;
		asali_->transport_[288].LJdiameter =  4.500;
		asali_->transport_[288].dipole =  0.000;
		asali_->transport_[288].polar =  0.000;
		asali_->transport_[288].collision =  1.000;
		asali_->transport_[288].MW = 77.040;
		
		asali_->transport_[289].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[289].name,"CH2CN");
		asali_->transport_[289].geometry = 1;
		asali_->transport_[289].LJpotential = 232.400;
		asali_->transport_[289].LJdiameter =  3.828;
		asali_->transport_[289].dipole =  0.000;
		asali_->transport_[289].polar =  0.000;
		asali_->transport_[289].collision =  1.000;
		asali_->transport_[289].MW = 40.045;
		
		asali_->transport_[290].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[290].name,"BIN1A");
		asali_->transport_[290].geometry = 2;
		asali_->transport_[290].LJpotential = 951.685;
		asali_->transport_[290].LJdiameter =  8.471;
		asali_->transport_[290].dipole =  0.000;
		asali_->transport_[290].polar =  0.000;
		asali_->transport_[290].collision =  1.000;
		asali_->transport_[290].MW = 256.347;
		
		asali_->transport_[291].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[291].name,"BIN1B");
		asali_->transport_[291].geometry = 2;
		asali_->transport_[291].LJpotential = 951.685;
		asali_->transport_[291].LJdiameter =  8.471;
		asali_->transport_[291].dipole =  0.000;
		asali_->transport_[291].polar =  0.000;
		asali_->transport_[291].collision =  1.000;
		asali_->transport_[291].MW = 250.299;
		
		asali_->transport_[292].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[292].name,"CYC6-QOOH-2");
		asali_->transport_[292].geometry = 2;
		asali_->transport_[292].LJpotential = 568.500;
		asali_->transport_[292].LJdiameter =  5.230;
		asali_->transport_[292].dipole =  0.000;
		asali_->transport_[292].polar = 10.300;
		asali_->transport_[292].collision =  1.000;
		asali_->transport_[292].MW = 115.152;
		
		asali_->transport_[293].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[293].name,"CYC6-QOOH-3");
		asali_->transport_[293].geometry = 2;
		asali_->transport_[293].LJpotential = 568.500;
		asali_->transport_[293].LJdiameter =  5.230;
		asali_->transport_[293].dipole =  0.000;
		asali_->transport_[293].polar = 10.300;
		asali_->transport_[293].collision =  1.000;
		asali_->transport_[293].MW = 115.152;
		
		asali_->transport_[294].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[294].name,"CYC6-QOOH-4");
		asali_->transport_[294].geometry = 2;
		asali_->transport_[294].LJpotential = 568.500;
		asali_->transport_[294].LJdiameter =  5.230;
		asali_->transport_[294].dipole =  0.000;
		asali_->transport_[294].polar = 10.300;
		asali_->transport_[294].collision =  1.000;
		asali_->transport_[294].MW = 115.152;
		
		asali_->transport_[295].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->transport_[295].name,"CYC6-OOQOOH-2");
		asali_->transport_[295].geometry = 2;
		asali_->transport_[295].LJpotential = 568.500;
		asali_->transport_[295].LJdiameter =  5.230;
		asali_->transport_[295].dipole =  0.000;
		asali_->transport_[295].polar = 10.300;
		asali_->transport_[295].collision =  1.000;
		asali_->transport_[295].MW = 147.151;
		
		asali_->transport_[296].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->transport_[296].name,"CYC6-OOQOOH-3");
		asali_->transport_[296].geometry = 2;
		asali_->transport_[296].LJpotential = 568.500;
		asali_->transport_[296].LJdiameter =  5.230;
		asali_->transport_[296].dipole =  0.000;
		asali_->transport_[296].polar = 10.300;
		asali_->transport_[296].collision =  1.000;
		asali_->transport_[296].MW = 147.151;
		
		asali_->transport_[297].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->transport_[297].name,"CYC6-OOQOOH-4");
		asali_->transport_[297].geometry = 2;
		asali_->transport_[297].LJpotential = 568.500;
		asali_->transport_[297].LJdiameter =  5.230;
		asali_->transport_[297].dipole =  0.000;
		asali_->transport_[297].polar = 10.300;
		asali_->transport_[297].collision =  1.000;
		asali_->transport_[297].MW = 147.151;
		
		asali_->transport_[298].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->transport_[298].name,"CYC6-OQOOH-2");
		asali_->transport_[298].geometry = 2;
		asali_->transport_[298].LJpotential = 568.500;
		asali_->transport_[298].LJdiameter =  5.230;
		asali_->transport_[298].dipole =  0.000;
		asali_->transport_[298].polar = 10.300;
		asali_->transport_[298].collision =  1.000;
		asali_->transport_[298].MW = 130.144;
		
		asali_->transport_[299].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->transport_[299].name,"CYC6-OQOOH-3");
		asali_->transport_[299].geometry = 2;
		asali_->transport_[299].LJpotential = 568.500;
		asali_->transport_[299].LJdiameter =  5.230;
		asali_->transport_[299].dipole =  0.000;
		asali_->transport_[299].polar = 10.300;
		asali_->transport_[299].collision =  1.000;
		asali_->transport_[299].MW = 130.144;
		
		asali_->transport_[300].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->transport_[300].name,"CYC6-OQOOH-4");
		asali_->transport_[300].geometry = 2;
		asali_->transport_[300].LJpotential = 568.500;
		asali_->transport_[300].LJdiameter =  5.230;
		asali_->transport_[300].dipole =  0.000;
		asali_->transport_[300].polar = 10.300;
		asali_->transport_[300].collision =  1.000;
		asali_->transport_[300].MW = 130.144;
		
		asali_->transport_[301].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->transport_[301].name,"CYC6H10-O-12");
		asali_->transport_[301].geometry = 2;
		asali_->transport_[301].LJpotential = 568.500;
		asali_->transport_[301].LJdiameter =  5.230;
		asali_->transport_[301].dipole =  0.000;
		asali_->transport_[301].polar = 10.300;
		asali_->transport_[301].collision =  1.000;
		asali_->transport_[301].MW = 98.145;
		
		asali_->transport_[302].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->transport_[302].name,"CYC6H10-O-13");
		asali_->transport_[302].geometry = 2;
		asali_->transport_[302].LJpotential = 568.500;
		asali_->transport_[302].LJdiameter =  5.230;
		asali_->transport_[302].dipole =  0.000;
		asali_->transport_[302].polar = 10.300;
		asali_->transport_[302].collision =  1.000;
		asali_->transport_[302].MW = 98.145;
		
		asali_->transport_[303].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->transport_[303].name,"CYC6H10-O-14");
		asali_->transport_[303].geometry = 2;
		asali_->transport_[303].LJpotential = 568.500;
		asali_->transport_[303].LJdiameter =  5.230;
		asali_->transport_[303].dipole =  0.000;
		asali_->transport_[303].polar = 10.300;
		asali_->transport_[303].collision =  1.000;
		asali_->transport_[303].MW = 98.145;
		
		asali_->transport_[304].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[304].name,"C3H5OOH");
		asali_->transport_[304].geometry = 2;
		asali_->transport_[304].LJpotential = 407.800;
		asali_->transport_[304].LJdiameter =  4.140;
		asali_->transport_[304].dipole =  0.000;
		asali_->transport_[304].polar =  0.000;
		asali_->transport_[304].collision =  1.000;
		asali_->transport_[304].MW = 74.079;
		
		asali_->transport_[305].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->transport_[305].name,"C5EN-OQOOH-35");
		asali_->transport_[305].geometry = 2;
		asali_->transport_[305].LJpotential = 508.000;
		asali_->transport_[305].LJdiameter =  5.200;
		asali_->transport_[305].dipole =  0.000;
		asali_->transport_[305].polar =  0.000;
		asali_->transport_[305].collision =  1.000;
		asali_->transport_[305].MW = 116.117;
		
		asali_->transport_[306].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[306].name,"C5H8O");
		asali_->transport_[306].geometry = 2;
		asali_->transport_[306].LJpotential = 508.000;
		asali_->transport_[306].LJdiameter =  5.200;
		asali_->transport_[306].dipole =  0.000;
		asali_->transport_[306].polar =  0.000;
		asali_->transport_[306].collision =  1.000;
		asali_->transport_[306].MW = 84.118;
		
		asali_->transport_[307].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[307].name,"NC5H9-3");
		asali_->transport_[307].geometry = 2;
		asali_->transport_[307].LJpotential = 408.000;
		asali_->transport_[307].LJdiameter =  5.200;
		asali_->transport_[307].dipole =  0.000;
		asali_->transport_[307].polar =  0.000;
		asali_->transport_[307].collision =  1.000;
		asali_->transport_[307].MW = 69.127;
		
		asali_->transport_[308].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[308].name,"C3H5OO");
		asali_->transport_[308].geometry = 2;
		asali_->transport_[308].LJpotential = 407.800;
		asali_->transport_[308].LJdiameter =  4.140;
		asali_->transport_[308].dipole =  0.000;
		asali_->transport_[308].polar =  0.000;
		asali_->transport_[308].collision =  1.000;
		asali_->transport_[308].MW = 73.072;
		
		asali_->transport_[309].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[309].name,"C5EN-OO");
		asali_->transport_[309].geometry = 2;
		asali_->transport_[309].LJpotential = 508.000;
		asali_->transport_[309].LJdiameter =  5.200;
		asali_->transport_[309].dipole =  0.000;
		asali_->transport_[309].polar =  0.000;
		asali_->transport_[309].collision =  1.000;
		asali_->transport_[309].MW = 101.125;
		
		asali_->transport_[310].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[310].name,"C5EN-QOOH");
		asali_->transport_[310].geometry = 2;
		asali_->transport_[310].LJpotential = 508.000;
		asali_->transport_[310].LJdiameter =  5.200;
		asali_->transport_[310].dipole =  0.000;
		asali_->transport_[310].polar =  0.000;
		asali_->transport_[310].collision =  1.000;
		asali_->transport_[310].MW = 101.125;
		
		asali_->transport_[311].name = (char*) malloc(14 * sizeof(char));
		strcpy(asali_->transport_[311].name,"C5EN-OOQOOH-35");
		asali_->transport_[311].geometry = 2;
		asali_->transport_[311].LJpotential = 508.000;
		asali_->transport_[311].LJdiameter =  5.200;
		asali_->transport_[311].dipole =  0.000;
		asali_->transport_[311].polar =  0.000;
		asali_->transport_[311].collision =  1.000;
		asali_->transport_[311].MW = 133.124;
		
		asali_->transport_[312].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[312].name,"NC3H7OH");
		asali_->transport_[312].geometry = 2;
		asali_->transport_[312].LJpotential = 482.147;
		asali_->transport_[312].LJdiameter =  5.009;
		asali_->transport_[312].dipole =  1.660;
		asali_->transport_[312].polar =  6.740;
		asali_->transport_[312].collision =  1.000;
		asali_->transport_[312].MW = 60.096;
		
		asali_->transport_[313].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[313].name,"N1C4H9OH");
		asali_->transport_[313].geometry = 2;
		asali_->transport_[313].LJpotential = 503.072;
		asali_->transport_[313].LJdiameter =  5.340;
		asali_->transport_[313].dipole =  1.670;
		asali_->transport_[313].polar =  8.880;
		asali_->transport_[313].collision =  1.000;
		asali_->transport_[313].MW = 74.123;
		
		asali_->transport_[314].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[314].name,"N2C4H9OH");
		asali_->transport_[314].geometry = 2;
		asali_->transport_[314].LJpotential = 503.072;
		asali_->transport_[314].LJdiameter =  5.340;
		asali_->transport_[314].dipole =  1.670;
		asali_->transport_[314].polar =  8.880;
		asali_->transport_[314].collision =  1.000;
		asali_->transport_[314].MW = 74.123;
		
		asali_->transport_[315].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->transport_[315].name,"CH3CH2CHOHCH2");
		asali_->transport_[315].geometry = 2;
		asali_->transport_[315].LJpotential = 503.072;
		asali_->transport_[315].LJdiameter =  5.340;
		asali_->transport_[315].dipole =  1.670;
		asali_->transport_[315].polar =  8.880;
		asali_->transport_[315].collision =  1.000;
		asali_->transport_[315].MW = 73.115;
		
		asali_->transport_[316].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->transport_[316].name,"CH3CH2CHOCH3");
		asali_->transport_[316].geometry = 2;
		asali_->transport_[316].LJpotential = 503.072;
		asali_->transport_[316].LJdiameter =  5.340;
		asali_->transport_[316].dipole =  1.670;
		asali_->transport_[316].polar =  8.880;
		asali_->transport_[316].collision =  1.000;
		asali_->transport_[316].MW = 73.115;
		
		asali_->transport_[317].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->transport_[317].name,"CH3CH2COHCH3");
		asali_->transport_[317].geometry = 2;
		asali_->transport_[317].LJpotential = 503.072;
		asali_->transport_[317].LJdiameter =  5.340;
		asali_->transport_[317].dipole =  1.670;
		asali_->transport_[317].polar =  8.880;
		asali_->transport_[317].collision =  1.000;
		asali_->transport_[317].MW = 73.115;
		
		asali_->transport_[318].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->transport_[318].name,"CH3CHCHOHCH3");
		asali_->transport_[318].geometry = 2;
		asali_->transport_[318].LJpotential = 503.072;
		asali_->transport_[318].LJdiameter =  5.340;
		asali_->transport_[318].dipole =  1.670;
		asali_->transport_[318].polar =  8.880;
		asali_->transport_[318].collision =  1.000;
		asali_->transport_[318].MW = 73.115;
		
		asali_->transport_[319].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->transport_[319].name,"CH2CH2CHOHCH3");
		asali_->transport_[319].geometry = 2;
		asali_->transport_[319].LJpotential = 503.072;
		asali_->transport_[319].LJdiameter =  5.340;
		asali_->transport_[319].dipole =  1.670;
		asali_->transport_[319].polar =  8.880;
		asali_->transport_[319].collision =  1.000;
		asali_->transport_[319].MW = 73.115;
		
		asali_->transport_[320].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[320].name,"MEK");
		asali_->transport_[320].geometry = 2;
		asali_->transport_[320].LJpotential = 454.000;
		asali_->transport_[320].LJdiameter =  5.413;
		asali_->transport_[320].dipole =  3.300;
		asali_->transport_[320].polar =  0.000;
		asali_->transport_[320].collision =  1.000;
		asali_->transport_[320].MW = 72.107;
		
		asali_->transport_[321].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[321].name,"TC4H9OH");
		asali_->transport_[321].geometry = 2;
		asali_->transport_[321].LJpotential = 503.072;
		asali_->transport_[321].LJdiameter =  5.340;
		asali_->transport_[321].dipole =  1.670;
		asali_->transport_[321].polar =  8.880;
		asali_->transport_[321].collision =  1.000;
		asali_->transport_[321].MW = 74.123;
		
		asali_->transport_[322].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[322].name,"IC4H9OH");
		asali_->transport_[322].geometry = 2;
		asali_->transport_[322].LJpotential = 503.072;
		asali_->transport_[322].LJdiameter =  5.340;
		asali_->transport_[322].dipole =  1.670;
		asali_->transport_[322].polar =  8.880;
		asali_->transport_[322].collision =  1.000;
		asali_->transport_[322].MW = 74.123;
		
		asali_->transport_[323].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->transport_[323].name,"CH3CH2CH2CH2O");
		asali_->transport_[323].geometry = 2;
		asali_->transport_[323].LJpotential = 503.072;
		asali_->transport_[323].LJdiameter =  5.340;
		asali_->transport_[323].dipole =  1.670;
		asali_->transport_[323].polar =  8.880;
		asali_->transport_[323].collision =  1.000;
		asali_->transport_[323].MW = 73.115;
		
		asali_->transport_[324].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[324].name,"C3H7CHO");
		asali_->transport_[324].geometry = 2;
		asali_->transport_[324].LJpotential = 503.072;
		asali_->transport_[324].LJdiameter =  5.340;
		asali_->transport_[324].dipole =  1.670;
		asali_->transport_[324].polar =  8.880;
		asali_->transport_[324].collision =  1.000;
		asali_->transport_[324].MW = 72.107;
		
		asali_->transport_[325].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[325].name,"CH3CH2CHOH");
		asali_->transport_[325].geometry = 2;
		asali_->transport_[325].LJpotential = 482.147;
		asali_->transport_[325].LJdiameter =  5.009;
		asali_->transport_[325].dipole =  1.660;
		asali_->transport_[325].polar =  6.740;
		asali_->transport_[325].collision =  1.000;
		asali_->transport_[325].MW = 59.088;
		
		asali_->transport_[326].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[326].name,"CH3CHCH2OH");
		asali_->transport_[326].geometry = 2;
		asali_->transport_[326].LJpotential = 482.147;
		asali_->transport_[326].LJdiameter =  5.009;
		asali_->transport_[326].dipole =  1.660;
		asali_->transport_[326].polar =  6.740;
		asali_->transport_[326].collision =  1.000;
		asali_->transport_[326].MW = 59.088;
		
		asali_->transport_[327].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[327].name,"CH2CH2CH2OH");
		asali_->transport_[327].geometry = 2;
		asali_->transport_[327].LJpotential = 482.147;
		asali_->transport_[327].LJdiameter =  5.009;
		asali_->transport_[327].dipole =  1.660;
		asali_->transport_[327].polar =  6.740;
		asali_->transport_[327].collision =  1.000;
		asali_->transport_[327].MW = 59.088;
		
		asali_->transport_[328].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[328].name,"CH3CH2CH2O");
		asali_->transport_[328].geometry = 2;
		asali_->transport_[328].LJpotential = 482.147;
		asali_->transport_[328].LJdiameter =  5.009;
		asali_->transport_[328].dipole =  1.660;
		asali_->transport_[328].polar =  6.740;
		asali_->transport_[328].collision =  1.000;
		asali_->transport_[328].MW = 59.088;
		
		asali_->transport_[329].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[329].name,"CH3COHCH3");
		asali_->transport_[329].geometry = 2;
		asali_->transport_[329].LJpotential = 468.300;
		asali_->transport_[329].LJdiameter =  4.760;
		asali_->transport_[329].dipole =  0.000;
		asali_->transport_[329].polar =  0.000;
		asali_->transport_[329].collision =  1.000;
		asali_->transport_[329].MW = 59.088;
		
		asali_->transport_[330].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[330].name,"CH2CHOHCH3");
		asali_->transport_[330].geometry = 2;
		asali_->transport_[330].LJpotential = 468.300;
		asali_->transport_[330].LJdiameter =  4.760;
		asali_->transport_[330].dipole =  0.000;
		asali_->transport_[330].polar =  0.000;
		asali_->transport_[330].collision =  1.000;
		asali_->transport_[330].MW = 59.088;
		
		asali_->transport_[331].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->transport_[331].name,"CH3CH2CH2CHOH");
		asali_->transport_[331].geometry = 2;
		asali_->transport_[331].LJpotential = 503.072;
		asali_->transport_[331].LJdiameter =  5.340;
		asali_->transport_[331].dipole =  1.670;
		asali_->transport_[331].polar =  8.880;
		asali_->transport_[331].collision =  1.000;
		asali_->transport_[331].MW = 73.115;
		
		asali_->transport_[332].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->transport_[332].name,"CH3CH2CHCH2OH");
		asali_->transport_[332].geometry = 2;
		asali_->transport_[332].LJpotential = 503.072;
		asali_->transport_[332].LJdiameter =  5.340;
		asali_->transport_[332].dipole =  1.670;
		asali_->transport_[332].polar =  8.880;
		asali_->transport_[332].collision =  1.000;
		asali_->transport_[332].MW = 73.115;
		
		asali_->transport_[333].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->transport_[333].name,"CH3CHCH2CH2OH");
		asali_->transport_[333].geometry = 2;
		asali_->transport_[333].LJpotential = 503.072;
		asali_->transport_[333].LJdiameter =  5.340;
		asali_->transport_[333].dipole =  1.670;
		asali_->transport_[333].polar =  8.880;
		asali_->transport_[333].collision =  1.000;
		asali_->transport_[333].MW = 73.115;
		
		asali_->transport_[334].name = (char*) malloc(14 * sizeof(char));
		strcpy(asali_->transport_[334].name,"CH2CH2CH2CH2OH");
		asali_->transport_[334].geometry = 2;
		asali_->transport_[334].LJpotential = 503.072;
		asali_->transport_[334].LJdiameter =  5.340;
		asali_->transport_[334].dipole =  1.670;
		asali_->transport_[334].polar =  8.880;
		asali_->transport_[334].collision =  1.000;
		asali_->transport_[334].MW = 73.115;
		
		asali_->transport_[335].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[335].name,"RTC4H8OH");
		asali_->transport_[335].geometry = 2;
		asali_->transport_[335].LJpotential = 503.072;
		asali_->transport_[335].LJdiameter =  5.340;
		asali_->transport_[335].dipole =  1.670;
		asali_->transport_[335].polar =  8.880;
		asali_->transport_[335].collision =  1.000;
		asali_->transport_[335].MW = 73.115;
		
		asali_->transport_[336].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[336].name,"RTC4H9O");
		asali_->transport_[336].geometry = 2;
		asali_->transport_[336].LJpotential = 503.072;
		asali_->transport_[336].LJdiameter =  5.340;
		asali_->transport_[336].dipole =  1.670;
		asali_->transport_[336].polar =  8.880;
		asali_->transport_[336].collision =  1.000;
		asali_->transport_[336].MW = 73.115;
		
		asali_->transport_[337].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->transport_[337].name,"CH3CHCH2OCH3");
		asali_->transport_[337].geometry = 2;
		asali_->transport_[337].LJpotential = 503.072;
		asali_->transport_[337].LJdiameter =  5.340;
		asali_->transport_[337].dipole =  1.670;
		asali_->transport_[337].polar =  8.880;
		asali_->transport_[337].collision =  1.000;
		asali_->transport_[337].MW = 73.115;
		
		asali_->transport_[338].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->transport_[338].name,"CH3CHCH3CHOH");
		asali_->transport_[338].geometry = 2;
		asali_->transport_[338].LJpotential = 503.072;
		asali_->transport_[338].LJdiameter =  5.340;
		asali_->transport_[338].dipole =  1.670;
		asali_->transport_[338].polar =  8.880;
		asali_->transport_[338].collision =  1.000;
		asali_->transport_[338].MW = 73.115;
		
		asali_->transport_[339].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->transport_[339].name,"CH3CCH2OHCH3");
		asali_->transport_[339].geometry = 2;
		asali_->transport_[339].LJpotential = 503.072;
		asali_->transport_[339].LJdiameter =  5.340;
		asali_->transport_[339].dipole =  1.670;
		asali_->transport_[339].polar =  8.880;
		asali_->transport_[339].collision =  1.000;
		asali_->transport_[339].MW = 73.115;
		
		asali_->transport_[340].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->transport_[340].name,"CH2CHCH2OHCH3");
		asali_->transport_[340].geometry = 2;
		asali_->transport_[340].LJpotential = 503.072;
		asali_->transport_[340].LJdiameter =  5.340;
		asali_->transport_[340].dipole =  1.670;
		asali_->transport_[340].polar =  8.880;
		asali_->transport_[340].collision =  1.000;
		asali_->transport_[340].MW = 73.115;
		
		asali_->transport_[341].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[341].name,"C4H7OH");
		asali_->transport_[341].geometry = 2;
		asali_->transport_[341].LJpotential = 503.072;
		asali_->transport_[341].LJdiameter =  5.340;
		asali_->transport_[341].dipole =  1.670;
		asali_->transport_[341].polar =  8.880;
		asali_->transport_[341].collision =  1.000;
		asali_->transport_[341].MW = 72.107;
		
		asali_->transport_[342].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[342].name,"C3H5OH");
		asali_->transport_[342].geometry = 2;
		asali_->transport_[342].LJpotential = 411.000;
		asali_->transport_[342].LJdiameter =  4.820;
		asali_->transport_[342].dipole =  0.000;
		asali_->transport_[342].polar =  0.000;
		asali_->transport_[342].collision =  1.000;
		asali_->transport_[342].MW = 58.080;
		
		asali_->transport_[343].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[343].name,"RCRESOLO");
		asali_->transport_[343].geometry = 2;
		asali_->transport_[343].LJpotential = 621.100;
		asali_->transport_[343].LJdiameter =  5.640;
		asali_->transport_[343].dipole =  0.000;
		asali_->transport_[343].polar =  0.000;
		asali_->transport_[343].collision =  1.000;
		asali_->transport_[343].MW = 107.132;
		
		asali_->transport_[344].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[344].name,"RCRESOLC");
		asali_->transport_[344].geometry = 2;
		asali_->transport_[344].LJpotential = 621.100;
		asali_->transport_[344].LJdiameter =  5.640;
		asali_->transport_[344].dipole =  0.000;
		asali_->transport_[344].polar =  0.000;
		asali_->transport_[344].collision =  1.000;
		asali_->transport_[344].MW = 107.132;
		
		asali_->transport_[345].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[345].name,"C10H10");
		asali_->transport_[345].geometry = 2;
		asali_->transport_[345].LJpotential = 630.400;
		asali_->transport_[345].LJdiameter =  6.180;
		asali_->transport_[345].dipole =  0.000;
		asali_->transport_[345].polar = 16.500;
		asali_->transport_[345].collision =  1.000;
		asali_->transport_[345].MW = 130.189;
		
		asali_->transport_[346].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[346].name,"BZFUR");
		asali_->transport_[346].geometry = 2;
		asali_->transport_[346].LJpotential = 630.400;
		asali_->transport_[346].LJdiameter =  6.180;
		asali_->transport_[346].dipole =  0.000;
		asali_->transport_[346].polar = 16.500;
		asali_->transport_[346].collision =  1.000;
		asali_->transport_[346].MW = 118.135;
		
		asali_->transport_[347].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[347].name,"ODECAL");
		asali_->transport_[347].geometry = 2;
		asali_->transport_[347].LJpotential = 630.400;
		asali_->transport_[347].LJdiameter =  6.180;
		asali_->transport_[347].dipole =  0.000;
		asali_->transport_[347].polar = 16.500;
		asali_->transport_[347].collision =  1.000;
		asali_->transport_[347].MW = 138.253;
		
		asali_->transport_[348].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[348].name,"RTETRALIN");
		asali_->transport_[348].geometry = 2;
		asali_->transport_[348].LJpotential = 630.400;
		asali_->transport_[348].LJdiameter =  6.180;
		asali_->transport_[348].dipole =  0.000;
		asali_->transport_[348].polar = 16.500;
		asali_->transport_[348].collision =  1.000;
		asali_->transport_[348].MW = 131.197;
		
		asali_->transport_[349].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[349].name,"RTETRAOO");
		asali_->transport_[349].geometry = 2;
		asali_->transport_[349].LJpotential = 630.400;
		asali_->transport_[349].LJdiameter =  6.180;
		asali_->transport_[349].dipole =  0.000;
		asali_->transport_[349].polar = 16.500;
		asali_->transport_[349].collision =  1.000;
		asali_->transport_[349].MW = 163.196;
		
		asali_->transport_[350].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[350].name,"TMBENZ");
		asali_->transport_[350].geometry = 2;
		asali_->transport_[350].LJpotential = 523.600;
		asali_->transport_[350].LJdiameter =  5.960;
		asali_->transport_[350].dipole =  0.000;
		asali_->transport_[350].polar =  0.000;
		asali_->transport_[350].collision =  1.000;
		asali_->transport_[350].MW = 120.194;
		
		asali_->transport_[351].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[351].name,"NPBENZ");
		asali_->transport_[351].geometry = 2;
		asali_->transport_[351].LJpotential = 495.300;
		asali_->transport_[351].LJdiameter =  5.680;
		asali_->transport_[351].dipole =  0.430;
		asali_->transport_[351].polar = 12.300;
		asali_->transport_[351].collision =  1.000;
		asali_->transport_[351].MW = 120.194;
		
		asali_->transport_[352].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[352].name,"RC9H11");
		asali_->transport_[352].geometry = 2;
		asali_->transport_[352].LJpotential = 523.600;
		asali_->transport_[352].LJdiameter =  5.960;
		asali_->transport_[352].dipole =  0.000;
		asali_->transport_[352].polar =  0.000;
		asali_->transport_[352].collision =  1.000;
		asali_->transport_[352].MW = 119.186;
		
		asali_->transport_[353].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[353].name,"C6H5OCH3");
		asali_->transport_[353].geometry = 2;
		asali_->transport_[353].LJpotential = 450.000;
		asali_->transport_[353].LJdiameter =  5.500;
		asali_->transport_[353].dipole =  0.000;
		asali_->transport_[353].polar =  0.000;
		asali_->transport_[353].collision =  1.000;
		asali_->transport_[353].MW = 108.140;
		
		asali_->transport_[354].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->transport_[354].name,"MB");
		asali_->transport_[354].geometry = 2;
		asali_->transport_[354].LJpotential = 468.000;
		asali_->transport_[354].LJdiameter =  5.850;
		asali_->transport_[354].dipole =  0.000;
		asali_->transport_[354].polar =  0.000;
		asali_->transport_[354].collision =  0.000;
		asali_->transport_[354].MW = 102.133;
		
		asali_->transport_[355].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[355].name,"RMBX");
		asali_->transport_[355].geometry = 2;
		asali_->transport_[355].LJpotential = 468.500;
		asali_->transport_[355].LJdiameter =  5.230;
		asali_->transport_[355].dipole =  0.000;
		asali_->transport_[355].polar =  0.000;
		asali_->transport_[355].collision =  1.000;
		asali_->transport_[355].MW = 101.125;
		
		asali_->transport_[356].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[356].name,"MCROT");
		asali_->transport_[356].geometry = 2;
		asali_->transport_[356].LJpotential = 468.500;
		asali_->transport_[356].LJdiameter =  5.230;
		asali_->transport_[356].dipole =  0.000;
		asali_->transport_[356].polar =  0.000;
		asali_->transport_[356].collision =  1.000;
		asali_->transport_[356].MW = 100.117;
		
		asali_->transport_[357].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[357].name,"MACRIL");
		asali_->transport_[357].geometry = 2;
		asali_->transport_[357].LJpotential = 430.100;
		asali_->transport_[357].LJdiameter =  5.833;
		asali_->transport_[357].dipole =  0.000;
		asali_->transport_[357].polar =  0.000;
		asali_->transport_[357].collision =  1.000;
		asali_->transport_[357].MW = 86.090;
		
		asali_->transport_[358].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[358].name,"RMP3");
		asali_->transport_[358].geometry = 2;
		asali_->transport_[358].LJpotential = 430.100;
		asali_->transport_[358].LJdiameter =  5.833;
		asali_->transport_[358].dipole =  0.000;
		asali_->transport_[358].polar =  0.000;
		asali_->transport_[358].collision =  1.000;
		asali_->transport_[358].MW = 87.098;
		
		asali_->transport_[359].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[359].name,"CH3OCO");
		asali_->transport_[359].geometry = 2;
		asali_->transport_[359].LJpotential = 395.000;
		asali_->transport_[359].LJdiameter =  4.037;
		asali_->transport_[359].dipole =  1.300;
		asali_->transport_[359].polar =  0.000;
		asali_->transport_[359].collision =  1.000;
		asali_->transport_[359].MW = 59.045;
		
		asali_->transport_[360].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[360].name,"ETMB583");
		asali_->transport_[360].geometry = 2;
		asali_->transport_[360].LJpotential = 508.000;
		asali_->transport_[360].LJdiameter =  5.200;
		asali_->transport_[360].dipole =  0.000;
		asali_->transport_[360].polar =  0.000;
		asali_->transport_[360].collision =  1.000;
		asali_->transport_[360].MW = 116.117;
		
		asali_->transport_[361].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[361].name,"KEHYMB");
		asali_->transport_[361].geometry = 2;
		asali_->transport_[361].LJpotential = 508.000;
		asali_->transport_[361].LJdiameter =  5.200;
		asali_->transport_[361].dipole =  0.000;
		asali_->transport_[361].polar =  0.000;
		asali_->transport_[361].collision =  1.000;
		asali_->transport_[361].MW = 148.116;
		
		asali_->transport_[362].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[362].name,"DIBZFUR");
		asali_->transport_[362].geometry = 2;
		asali_->transport_[362].LJpotential = 676.500;
		asali_->transport_[362].LJdiameter =  6.310;
		asali_->transport_[362].dipole =  0.000;
		asali_->transport_[362].polar =  0.000;
		asali_->transport_[362].collision =  1.000;
		asali_->transport_[362].MW = 168.195;
		
		asali_->transport_[363].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[363].name,"DIFENET");
		asali_->transport_[363].geometry = 2;
		asali_->transport_[363].LJpotential = 676.500;
		asali_->transport_[363].LJdiameter =  6.310;
		asali_->transport_[363].dipole =  0.000;
		asali_->transport_[363].polar =  0.000;
		asali_->transport_[363].collision =  1.000;
		asali_->transport_[363].MW = 170.211;
		
		asali_->transport_[364].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[364].name,"RMBOOX");
		asali_->transport_[364].geometry = 2;
		asali_->transport_[364].LJpotential = 508.000;
		asali_->transport_[364].LJdiameter =  5.200;
		asali_->transport_[364].dipole =  0.000;
		asali_->transport_[364].polar =  0.000;
		asali_->transport_[364].collision =  1.000;
		asali_->transport_[364].MW = 133.124;
		
		asali_->transport_[365].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[365].name,"QMBOOX");
		asali_->transport_[365].geometry = 2;
		asali_->transport_[365].LJpotential = 508.000;
		asali_->transport_[365].LJdiameter =  5.200;
		asali_->transport_[365].dipole =  0.000;
		asali_->transport_[365].polar =  0.000;
		asali_->transport_[365].collision =  1.000;
		asali_->transport_[365].MW = 133.124;
		
		asali_->transport_[366].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[366].name,"ZMBOOX");
		asali_->transport_[366].geometry = 2;
		asali_->transport_[366].LJpotential = 508.000;
		asali_->transport_[366].LJdiameter =  5.200;
		asali_->transport_[366].dipole =  0.000;
		asali_->transport_[366].polar =  0.000;
		asali_->transport_[366].collision =  1.000;
		asali_->transport_[366].MW = 165.123;
		
		asali_->transport_[367].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[367].name,"KHDECA");
		asali_->transport_[367].geometry = 2;
		asali_->transport_[367].LJpotential = 630.400;
		asali_->transport_[367].LJdiameter =  6.180;
		asali_->transport_[367].dipole =  0.000;
		asali_->transport_[367].polar = 16.500;
		asali_->transport_[367].collision =  1.000;
		asali_->transport_[367].MW = 184.235;
		
		asali_->transport_[368].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[368].name,"QDECOOH");
		asali_->transport_[368].geometry = 2;
		asali_->transport_[368].LJpotential = 630.400;
		asali_->transport_[368].LJdiameter =  6.180;
		asali_->transport_[368].dipole =  0.000;
		asali_->transport_[368].polar = 16.500;
		asali_->transport_[368].collision =  1.000;
		asali_->transport_[368].MW = 169.244;
		
		asali_->transport_[369].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[369].name,"RDECOO");
		asali_->transport_[369].geometry = 2;
		asali_->transport_[369].LJpotential = 630.400;
		asali_->transport_[369].LJdiameter =  6.180;
		asali_->transport_[369].dipole =  0.000;
		asali_->transport_[369].polar = 16.500;
		asali_->transport_[369].collision =  1.000;
		asali_->transport_[369].MW = 169.244;
		
		asali_->transport_[370].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[370].name,"ZDECA");
		asali_->transport_[370].geometry = 2;
		asali_->transport_[370].LJpotential = 630.400;
		asali_->transport_[370].LJdiameter =  6.180;
		asali_->transport_[370].dipole =  0.000;
		asali_->transport_[370].polar = 16.500;
		asali_->transport_[370].collision =  1.000;
		asali_->transport_[370].MW = 201.243;
		
		asali_->transport_[371].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[371].name,"RMCROTA");
		asali_->transport_[371].geometry = 2;
		asali_->transport_[371].LJpotential = 468.500;
		asali_->transport_[371].LJdiameter =  5.230;
		asali_->transport_[371].dipole =  0.000;
		asali_->transport_[371].polar =  0.000;
		asali_->transport_[371].collision =  1.000;
		asali_->transport_[371].MW = 99.109;
		
		asali_->transport_[372].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->transport_[372].name,"MD");
		asali_->transport_[372].geometry = 2;
		asali_->transport_[372].LJpotential = 604.400;
		asali_->transport_[372].LJdiameter =  7.305;
		asali_->transport_[372].dipole =  1.700;
		asali_->transport_[372].polar =  0.000;
		asali_->transport_[372].collision =  1.000;
		asali_->transport_[372].MW = 186.294;
		
		asali_->transport_[373].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[373].name,"RMDX");
		asali_->transport_[373].geometry = 2;
		asali_->transport_[373].LJpotential = 604.400;
		asali_->transport_[373].LJdiameter =  7.305;
		asali_->transport_[373].dipole =  1.700;
		asali_->transport_[373].polar =  0.000;
		asali_->transport_[373].collision =  1.000;
		asali_->transport_[373].MW = 185.287;
		
		asali_->transport_[374].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[374].name,"CH3OCHO");
		asali_->transport_[374].geometry = 2;
		asali_->transport_[374].LJpotential = 395.000;
		asali_->transport_[374].LJdiameter =  4.037;
		asali_->transport_[374].dipole =  1.300;
		asali_->transport_[374].polar =  0.000;
		asali_->transport_[374].collision =  1.000;
		asali_->transport_[374].MW = 60.053;
		
		asali_->transport_[375].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[375].name,"ETEROMD");
		asali_->transport_[375].geometry = 2;
		asali_->transport_[375].LJpotential = 680.000;
		asali_->transport_[375].LJdiameter =  7.600;
		asali_->transport_[375].dipole =  0.000;
		asali_->transport_[375].polar =  0.000;
		asali_->transport_[375].collision =  1.000;
		asali_->transport_[375].MW = 200.278;
		
		asali_->transport_[376].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[376].name,"MDKETO");
		asali_->transport_[376].geometry = 2;
		asali_->transport_[376].LJpotential = 680.000;
		asali_->transport_[376].LJdiameter =  7.600;
		asali_->transport_[376].dipole =  0.000;
		asali_->transport_[376].polar =  0.000;
		asali_->transport_[376].collision =  1.000;
		asali_->transport_[376].MW = 232.277;
		
		asali_->transport_[377].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[377].name,"C7H15COCHO");
		asali_->transport_[377].geometry = 2;
		asali_->transport_[377].LJpotential = 594.000;
		asali_->transport_[377].LJdiameter =  6.170;
		asali_->transport_[377].dipole =  0.000;
		asali_->transport_[377].polar =  0.000;
		asali_->transport_[377].collision =  1.000;
		asali_->transport_[377].MW = 156.225;
		
		asali_->transport_[378].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[378].name,"RMDOOX");
		asali_->transport_[378].geometry = 2;
		asali_->transport_[378].LJpotential = 750.000;
		asali_->transport_[378].LJdiameter =  8.350;
		asali_->transport_[378].dipole =  0.000;
		asali_->transport_[378].polar =  0.000;
		asali_->transport_[378].collision =  1.000;
		asali_->transport_[378].MW = 217.285;
		
		asali_->transport_[379].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[379].name,"QMDOOH");
		asali_->transport_[379].geometry = 2;
		asali_->transport_[379].LJpotential = 750.000;
		asali_->transport_[379].LJdiameter =  8.350;
		asali_->transport_[379].dipole =  0.000;
		asali_->transport_[379].polar =  0.000;
		asali_->transport_[379].collision =  1.000;
		asali_->transport_[379].MW = 217.285;
		
		asali_->transport_[380].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[380].name,"ZMDOOH");
		asali_->transport_[380].geometry = 2;
		asali_->transport_[380].LJpotential = 750.000;
		asali_->transport_[380].LJdiameter =  8.350;
		asali_->transport_[380].dipole =  0.000;
		asali_->transport_[380].polar =  0.000;
		asali_->transport_[380].collision =  1.000;
		asali_->transport_[380].MW = 249.284;
		
		asali_->transport_[381].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[381].name,"U2ME10");
		asali_->transport_[381].geometry = 2;
		asali_->transport_[381].LJpotential = 604.400;
		asali_->transport_[381].LJdiameter =  7.305;
		asali_->transport_[381].dipole =  2.000;
		asali_->transport_[381].polar =  0.000;
		asali_->transport_[381].collision =  1.000;
		asali_->transport_[381].MW = 182.263;
		
		asali_->transport_[382].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[382].name,"UME10");
		asali_->transport_[382].geometry = 2;
		asali_->transport_[382].LJpotential = 604.400;
		asali_->transport_[382].LJdiameter =  7.305;
		asali_->transport_[382].dipole =  2.000;
		asali_->transport_[382].polar =  0.000;
		asali_->transport_[382].collision =  1.000;
		asali_->transport_[382].MW = 184.279;
		
		asali_->transport_[383].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[383].name,"UME7");
		asali_->transport_[383].geometry = 2;
		asali_->transport_[383].LJpotential = 556.820;
		asali_->transport_[383].LJdiameter =  6.410;
		asali_->transport_[383].dipole =  1.700;
		asali_->transport_[383].polar = 16.140;
		asali_->transport_[383].collision =  1.000;
		asali_->transport_[383].MW = 142.198;
		
		asali_->transport_[384].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[384].name,"C12H22");
		asali_->transport_[384].geometry = 2;
		asali_->transport_[384].LJpotential = 580.000;
		asali_->transport_[384].LJdiameter =  7.600;
		asali_->transport_[384].dipole =  0.000;
		asali_->transport_[384].polar =  0.000;
		asali_->transport_[384].collision =  1.000;
		asali_->transport_[384].MW = 166.307;
		
		asali_->transport_[385].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[385].name,"DCYC5");
		asali_->transport_[385].geometry = 2;
		asali_->transport_[385].LJpotential = 630.400;
		asali_->transport_[385].LJdiameter =  6.180;
		asali_->transport_[385].dipole =  0.000;
		asali_->transport_[385].polar = 16.500;
		asali_->transport_[385].collision =  1.000;
		asali_->transport_[385].MW = 136.237;
		
		asali_->transport_[386].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[386].name,"UME16");
		asali_->transport_[386].geometry = 2;
		asali_->transport_[386].LJpotential = 750.000;
		asali_->transport_[386].LJdiameter =  8.350;
		asali_->transport_[386].dipole =  0.000;
		asali_->transport_[386].polar =  0.000;
		asali_->transport_[386].collision =  1.000;
		asali_->transport_[386].MW = 268.440;
		
		asali_->transport_[387].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[387].name,"ETEROMPA");
		asali_->transport_[387].geometry = 2;
		asali_->transport_[387].LJpotential = 750.000;
		asali_->transport_[387].LJdiameter =  8.350;
		asali_->transport_[387].dipole =  0.000;
		asali_->transport_[387].polar =  0.000;
		asali_->transport_[387].collision =  1.000;
		asali_->transport_[387].MW = 284.439;
		
		asali_->transport_[388].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[388].name,"MPA");
		asali_->transport_[388].geometry = 2;
		asali_->transport_[388].LJpotential = 750.000;
		asali_->transport_[388].LJdiameter =  8.350;
		asali_->transport_[388].dipole =  0.000;
		asali_->transport_[388].polar =  0.000;
		asali_->transport_[388].collision =  1.000;
		asali_->transport_[388].MW = 270.456;
		
		asali_->transport_[389].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[389].name,"KHMLIN1");
		asali_->transport_[389].geometry = 2;
		asali_->transport_[389].LJpotential = 750.000;
		asali_->transport_[389].LJdiameter =  8.350;
		asali_->transport_[389].dipole =  0.000;
		asali_->transport_[389].polar =  0.000;
		asali_->transport_[389].collision =  1.000;
		asali_->transport_[389].MW = 338.444;
		
		asali_->transport_[390].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[390].name,"MLIN1");
		asali_->transport_[390].geometry = 2;
		asali_->transport_[390].LJpotential = 750.000;
		asali_->transport_[390].LJdiameter =  8.350;
		asali_->transport_[390].dipole =  0.000;
		asali_->transport_[390].polar =  0.000;
		asali_->transport_[390].collision =  1.000;
		asali_->transport_[390].MW = 292.462;
		
		asali_->transport_[391].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[391].name,"MLINO");
		asali_->transport_[391].geometry = 2;
		asali_->transport_[391].LJpotential = 750.000;
		asali_->transport_[391].LJdiameter =  8.350;
		asali_->transport_[391].dipole =  0.000;
		asali_->transport_[391].polar =  0.000;
		asali_->transport_[391].collision =  1.000;
		asali_->transport_[391].MW = 294.478;
		
		asali_->transport_[392].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[392].name,"MEOLE");
		asali_->transport_[392].geometry = 2;
		asali_->transport_[392].LJpotential = 750.000;
		asali_->transport_[392].LJdiameter =  8.350;
		asali_->transport_[392].dipole =  0.000;
		asali_->transport_[392].polar =  0.000;
		asali_->transport_[392].collision =  1.000;
		asali_->transport_[392].MW = 296.494;
		
		asali_->transport_[393].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[393].name,"MSTEA");
		asali_->transport_[393].geometry = 2;
		asali_->transport_[393].LJpotential = 750.000;
		asali_->transport_[393].LJdiameter =  8.350;
		asali_->transport_[393].dipole =  0.000;
		asali_->transport_[393].polar =  0.000;
		asali_->transport_[393].collision =  1.000;
		asali_->transport_[393].MW = 298.510;
		
		asali_->transport_[394].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[394].name,"RUME7");
		asali_->transport_[394].geometry = 2;
		asali_->transport_[394].LJpotential = 556.820;
		asali_->transport_[394].LJdiameter =  6.410;
		asali_->transport_[394].dipole =  1.700;
		asali_->transport_[394].polar = 16.140;
		asali_->transport_[394].collision =  1.000;
		asali_->transport_[394].MW = 141.190;
		
		asali_->transport_[395].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[395].name,"RME7");
		asali_->transport_[395].geometry = 2;
		asali_->transport_[395].LJpotential = 556.820;
		asali_->transport_[395].LJdiameter =  6.410;
		asali_->transport_[395].dipole =  1.700;
		asali_->transport_[395].polar = 16.140;
		asali_->transport_[395].collision =  1.000;
		asali_->transport_[395].MW = 143.206;
		
		asali_->transport_[396].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[396].name,"RUME10");
		asali_->transport_[396].geometry = 2;
		asali_->transport_[396].LJpotential = 604.400;
		asali_->transport_[396].LJdiameter =  7.305;
		asali_->transport_[396].dipole =  2.000;
		asali_->transport_[396].polar =  0.000;
		asali_->transport_[396].collision =  1.000;
		asali_->transport_[396].MW = 183.271;
		
		asali_->transport_[397].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[397].name,"RMPAX");
		asali_->transport_[397].geometry = 2;
		asali_->transport_[397].LJpotential = 750.000;
		asali_->transport_[397].LJdiameter =  8.350;
		asali_->transport_[397].dipole =  0.000;
		asali_->transport_[397].polar =  0.000;
		asali_->transport_[397].collision =  1.000;
		asali_->transport_[397].MW = 269.448;
		
		asali_->transport_[398].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[398].name,"QMPAOOH");
		asali_->transport_[398].geometry = 2;
		asali_->transport_[398].LJpotential = 750.000;
		asali_->transport_[398].LJdiameter =  8.350;
		asali_->transport_[398].dipole =  0.000;
		asali_->transport_[398].polar =  0.000;
		asali_->transport_[398].collision =  1.000;
		asali_->transport_[398].MW = 301.447;
		
		asali_->transport_[399].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[399].name,"RMPAOOX");
		asali_->transport_[399].geometry = 2;
		asali_->transport_[399].LJpotential = 750.000;
		asali_->transport_[399].LJdiameter =  8.350;
		asali_->transport_[399].dipole =  0.000;
		asali_->transport_[399].polar =  0.000;
		asali_->transport_[399].collision =  1.000;
		asali_->transport_[399].MW = 301.447;
		
		asali_->transport_[400].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[400].name,"ZMPAOOH");
		asali_->transport_[400].geometry = 2;
		asali_->transport_[400].LJpotential = 750.000;
		asali_->transport_[400].LJdiameter =  8.350;
		asali_->transport_[400].dipole =  0.000;
		asali_->transport_[400].polar =  0.000;
		asali_->transport_[400].collision =  1.000;
		asali_->transport_[400].MW = 333.445;
		
		asali_->transport_[401].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[401].name,"RMLIN1A");
		asali_->transport_[401].geometry = 2;
		asali_->transport_[401].LJpotential = 750.000;
		asali_->transport_[401].LJdiameter =  8.350;
		asali_->transport_[401].dipole =  0.000;
		asali_->transport_[401].polar =  0.000;
		asali_->transport_[401].collision =  1.000;
		asali_->transport_[401].MW = 291.454;
		
		asali_->transport_[402].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[402].name,"RMLIN1X");
		asali_->transport_[402].geometry = 2;
		asali_->transport_[402].LJpotential = 750.000;
		asali_->transport_[402].LJdiameter =  8.350;
		asali_->transport_[402].dipole =  0.000;
		asali_->transport_[402].polar =  0.000;
		asali_->transport_[402].collision =  1.000;
		asali_->transport_[402].MW = 291.454;
		
		asali_->transport_[403].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[403].name,"RMLIN1OOX");
		asali_->transport_[403].geometry = 2;
		asali_->transport_[403].LJpotential = 750.000;
		asali_->transport_[403].LJdiameter =  8.350;
		asali_->transport_[403].dipole =  0.000;
		asali_->transport_[403].polar =  0.000;
		asali_->transport_[403].collision =  1.000;
		asali_->transport_[403].MW = 323.453;
		
		asali_->transport_[404].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[404].name,"QMLIN1OOX");
		asali_->transport_[404].geometry = 2;
		asali_->transport_[404].LJpotential = 750.000;
		asali_->transport_[404].LJdiameter =  8.350;
		asali_->transport_[404].dipole =  0.000;
		asali_->transport_[404].polar =  0.000;
		asali_->transport_[404].collision =  1.000;
		asali_->transport_[404].MW = 323.453;
		
		asali_->transport_[405].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[405].name,"ZMLIN1OOX");
		asali_->transport_[405].geometry = 2;
		asali_->transport_[405].LJpotential = 750.000;
		asali_->transport_[405].LJdiameter =  8.350;
		asali_->transport_[405].dipole =  0.000;
		asali_->transport_[405].polar =  0.000;
		asali_->transport_[405].collision =  1.000;
		asali_->transport_[405].MW = 355.452;
		
		asali_->transport_[406].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[406].name,"RMLINA");
		asali_->transport_[406].geometry = 2;
		asali_->transport_[406].LJpotential = 750.000;
		asali_->transport_[406].LJdiameter =  8.350;
		asali_->transport_[406].dipole =  0.000;
		asali_->transport_[406].polar =  0.000;
		asali_->transport_[406].collision =  1.000;
		asali_->transport_[406].MW = 293.470;
		
		asali_->transport_[407].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[407].name,"RMLINX");
		asali_->transport_[407].geometry = 2;
		asali_->transport_[407].LJpotential = 750.000;
		asali_->transport_[407].LJdiameter =  8.350;
		asali_->transport_[407].dipole =  0.000;
		asali_->transport_[407].polar =  0.000;
		asali_->transport_[407].collision =  1.000;
		asali_->transport_[407].MW = 293.470;
		
		asali_->transport_[408].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[408].name,"RMLINOOX");
		asali_->transport_[408].geometry = 2;
		asali_->transport_[408].LJpotential = 750.000;
		asali_->transport_[408].LJdiameter =  8.350;
		asali_->transport_[408].dipole =  0.000;
		asali_->transport_[408].polar =  0.000;
		asali_->transport_[408].collision =  1.000;
		asali_->transport_[408].MW = 325.469;
		
		asali_->transport_[409].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[409].name,"QMLINOOX");
		asali_->transport_[409].geometry = 2;
		asali_->transport_[409].LJpotential = 750.000;
		asali_->transport_[409].LJdiameter =  8.350;
		asali_->transport_[409].dipole =  0.000;
		asali_->transport_[409].polar =  0.000;
		asali_->transport_[409].collision =  1.000;
		asali_->transport_[409].MW = 325.469;
		
		asali_->transport_[410].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[410].name,"ZMLINOOX");
		asali_->transport_[410].geometry = 2;
		asali_->transport_[410].LJpotential = 750.000;
		asali_->transport_[410].LJdiameter =  8.350;
		asali_->transport_[410].dipole =  0.000;
		asali_->transport_[410].polar =  0.000;
		asali_->transport_[410].collision =  1.000;
		asali_->transport_[410].MW = 357.467;
		
		asali_->transport_[411].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[411].name,"RMEOLEA");
		asali_->transport_[411].geometry = 2;
		asali_->transport_[411].LJpotential = 750.000;
		asali_->transport_[411].LJdiameter =  8.350;
		asali_->transport_[411].dipole =  0.000;
		asali_->transport_[411].polar =  0.000;
		asali_->transport_[411].collision =  1.000;
		asali_->transport_[411].MW = 295.486;
		
		asali_->transport_[412].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[412].name,"RMEOLES");
		asali_->transport_[412].geometry = 2;
		asali_->transport_[412].LJpotential = 750.000;
		asali_->transport_[412].LJdiameter =  8.350;
		asali_->transport_[412].dipole =  0.000;
		asali_->transport_[412].polar =  0.000;
		asali_->transport_[412].collision =  1.000;
		asali_->transport_[412].MW = 295.486;
		
		asali_->transport_[413].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[413].name,"RMEOLEOOX");
		asali_->transport_[413].geometry = 2;
		asali_->transport_[413].LJpotential = 750.000;
		asali_->transport_[413].LJdiameter =  8.350;
		asali_->transport_[413].dipole =  0.000;
		asali_->transport_[413].polar =  0.000;
		asali_->transport_[413].collision =  1.000;
		asali_->transport_[413].MW = 327.484;
		
		asali_->transport_[414].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[414].name,"QMEOLEOOH");
		asali_->transport_[414].geometry = 2;
		asali_->transport_[414].LJpotential = 750.000;
		asali_->transport_[414].LJdiameter =  8.350;
		asali_->transport_[414].dipole =  0.000;
		asali_->transport_[414].polar =  0.000;
		asali_->transport_[414].collision =  1.000;
		asali_->transport_[414].MW = 327.484;
		
		asali_->transport_[415].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[415].name,"ZMEOLEOOX");
		asali_->transport_[415].geometry = 2;
		asali_->transport_[415].LJpotential = 750.000;
		asali_->transport_[415].LJdiameter =  8.350;
		asali_->transport_[415].dipole =  0.000;
		asali_->transport_[415].polar =  0.000;
		asali_->transport_[415].collision =  1.000;
		asali_->transport_[415].MW = 359.483;
		
		asali_->transport_[416].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[416].name,"RSTEAX");
		asali_->transport_[416].geometry = 2;
		asali_->transport_[416].LJpotential = 750.000;
		asali_->transport_[416].LJdiameter =  8.350;
		asali_->transport_[416].dipole =  0.000;
		asali_->transport_[416].polar =  0.000;
		asali_->transport_[416].collision =  1.000;
		asali_->transport_[416].MW = 297.502;
		
		asali_->transport_[417].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[417].name,"RMSTEAOOX");
		asali_->transport_[417].geometry = 2;
		asali_->transport_[417].LJpotential = 750.000;
		asali_->transport_[417].LJdiameter =  8.350;
		asali_->transport_[417].dipole =  0.000;
		asali_->transport_[417].polar =  0.000;
		asali_->transport_[417].collision =  1.000;
		asali_->transport_[417].MW = 329.500;
		
		asali_->transport_[418].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[418].name,"QMSTEAOOH");
		asali_->transport_[418].geometry = 2;
		asali_->transport_[418].LJpotential = 750.000;
		asali_->transport_[418].LJdiameter =  8.350;
		asali_->transport_[418].dipole =  0.000;
		asali_->transport_[418].polar =  0.000;
		asali_->transport_[418].collision =  1.000;
		asali_->transport_[418].MW = 329.500;
		
		asali_->transport_[419].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[419].name,"ZMSTEAOOH");
		asali_->transport_[419].geometry = 2;
		asali_->transport_[419].LJpotential = 750.000;
		asali_->transport_[419].LJdiameter =  8.350;
		asali_->transport_[419].dipole =  0.000;
		asali_->transport_[419].polar =  0.000;
		asali_->transport_[419].collision =  1.000;
		asali_->transport_[419].MW = 361.499;
		
		asali_->transport_[420].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[420].name,"U2ME12");
		asali_->transport_[420].geometry = 2;
		asali_->transport_[420].LJpotential = 620.000;
		asali_->transport_[420].LJdiameter =  8.000;
		asali_->transport_[420].dipole =  0.000;
		asali_->transport_[420].polar =  0.000;
		asali_->transport_[420].collision =  1.000;
		asali_->transport_[420].MW = 210.316;
		
		asali_->transport_[421].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[421].name,"ALDEST");
		asali_->transport_[421].geometry = 2;
		asali_->transport_[421].LJpotential = 568.500;
		asali_->transport_[421].LJdiameter =  5.230;
		asali_->transport_[421].dipole =  0.000;
		asali_->transport_[421].polar = 10.300;
		asali_->transport_[421].collision =  1.000;
		asali_->transport_[421].MW = 130.144;
		
		asali_->transport_[422].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[422].name,"RALDEST");
		asali_->transport_[422].geometry = 2;
		asali_->transport_[422].LJpotential = 568.500;
		asali_->transport_[422].LJdiameter =  5.230;
		asali_->transport_[422].dipole =  0.000;
		asali_->transport_[422].polar = 10.300;
		asali_->transport_[422].collision =  1.000;
		asali_->transport_[422].MW = 129.136;
		
		asali_->transport_[423].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[423].name,"C12H18");
		asali_->transport_[423].geometry = 2;
		asali_->transport_[423].LJpotential = 620.000;
		asali_->transport_[423].LJdiameter =  8.000;
		asali_->transport_[423].dipole =  0.000;
		asali_->transport_[423].polar =  0.000;
		asali_->transport_[423].collision =  1.000;
		asali_->transport_[423].MW = 162.275;
		
		asali_->transport_[424].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[424].name,"RODECA");
		asali_->transport_[424].geometry = 2;
		asali_->transport_[424].LJpotential = 630.400;
		asali_->transport_[424].LJdiameter =  6.180;
		asali_->transport_[424].dipole =  0.000;
		asali_->transport_[424].polar = 16.500;
		asali_->transport_[424].collision =  1.000;
		asali_->transport_[424].MW = 137.245;
		
		asali_->transport_[425].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[425].name,"ALDINS");
		asali_->transport_[425].geometry = 2;
		asali_->transport_[425].LJpotential = 620.000;
		asali_->transport_[425].LJdiameter =  8.000;
		asali_->transport_[425].dipole =  0.000;
		asali_->transport_[425].polar =  0.000;
		asali_->transport_[425].collision =  1.000;
		asali_->transport_[425].MW = 192.301;
		
		asali_->transport_[426].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[426].name,"RUME16");
		asali_->transport_[426].geometry = 2;
		asali_->transport_[426].LJpotential = 750.000;
		asali_->transport_[426].LJdiameter =  8.350;
		asali_->transport_[426].dipole =  0.000;
		asali_->transport_[426].polar =  0.000;
		asali_->transport_[426].collision =  1.000;
		asali_->transport_[426].MW = 267.432;
		
		asali_->transport_[427].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[427].name,"NC10H19");
		asali_->transport_[427].geometry = 2;
		asali_->transport_[427].LJpotential = 540.980;
		asali_->transport_[427].LJdiameter =  7.150;
		asali_->transport_[427].dipole =  0.000;
		asali_->transport_[427].polar =  0.000;
		asali_->transport_[427].collision =  1.000;
		asali_->transport_[427].MW = 139.261;
		
		asali_->transport_[428].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[428].name,"C8H9");
		asali_->transport_[428].geometry = 2;
		asali_->transport_[428].LJpotential = 546.200;
		asali_->transport_[428].LJdiameter =  6.000;
		asali_->transport_[428].dipole =  0.000;
		asali_->transport_[428].polar =  0.000;
		asali_->transport_[428].collision =  1.000;
		asali_->transport_[428].MW = 105.159;
		
		asali_->transport_[429].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[429].name,"NC7H13OOH");
		asali_->transport_[429].geometry = 2;
		asali_->transport_[429].LJpotential = 559.980;
		asali_->transport_[429].LJdiameter =  6.310;
		asali_->transport_[429].dipole =  0.000;
		asali_->transport_[429].polar =  0.000;
		asali_->transport_[429].collision =  1.000;
		asali_->transport_[429].MW = 130.187;
		
		asali_->transport_[430].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[430].name,"NC7H13");
		asali_->transport_[430].geometry = 2;
		asali_->transport_[430].LJpotential = 559.980;
		asali_->transport_[430].LJdiameter =  6.310;
		asali_->transport_[430].dipole =  0.000;
		asali_->transport_[430].polar =  0.000;
		asali_->transport_[430].collision =  1.000;
		asali_->transport_[430].MW = 97.180;
		
		asali_->transport_[431].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[431].name,"LC6H5");
		asali_->transport_[431].geometry = 2;
		asali_->transport_[431].LJpotential = 412.300;
		asali_->transport_[431].LJdiameter =  5.349;
		asali_->transport_[431].dipole =  0.000;
		asali_->transport_[431].polar =  0.000;
		asali_->transport_[431].collision =  1.000;
		asali_->transport_[431].MW = 77.106;
		
		asali_->transport_[432].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[432].name,"C6H2");
		asali_->transport_[432].geometry = 1;
		asali_->transport_[432].LJpotential = 357.000;
		asali_->transport_[432].LJdiameter =  5.180;
		asali_->transport_[432].dipole =  0.000;
		asali_->transport_[432].polar =  0.000;
		asali_->transport_[432].collision =  1.000;
		asali_->transport_[432].MW = 74.082;
		
		asali_->transport_[433].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[433].name,"C8H2");
		asali_->transport_[433].geometry = 1;
		asali_->transport_[433].LJpotential = 495.300;
		asali_->transport_[433].LJdiameter =  5.680;
		asali_->transport_[433].dipole =  0.430;
		asali_->transport_[433].polar = 12.300;
		asali_->transport_[433].collision =  1.000;
		asali_->transport_[433].MW = 98.104;
		
		asali_->transport_[434].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[434].name,"C6H3");
		asali_->transport_[434].geometry = 1;
		asali_->transport_[434].LJpotential = 357.000;
		asali_->transport_[434].LJdiameter =  5.180;
		asali_->transport_[434].dipole =  0.000;
		asali_->transport_[434].polar =  0.000;
		asali_->transport_[434].collision =  1.000;
		asali_->transport_[434].MW = 75.090;
		
		asali_->transport_[435].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->transport_[435].name,"C6H4");
		asali_->transport_[435].geometry = 2;
		asali_->transport_[435].LJpotential = 412.300;
		asali_->transport_[435].LJdiameter =  5.349;
		asali_->transport_[435].dipole =  0.000;
		asali_->transport_[435].polar =  0.000;
		asali_->transport_[435].collision =  1.000;
		asali_->transport_[435].MW = 76.098;
		
		asali_->transport_[436].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[436].name,"BENZYNE");
		asali_->transport_[436].geometry = 2;
		asali_->transport_[436].LJpotential = 468.500;
		asali_->transport_[436].LJdiameter =  5.230;
		asali_->transport_[436].dipole =  0.000;
		asali_->transport_[436].polar = 10.300;
		asali_->transport_[436].collision =  1.000;
		asali_->transport_[436].MW = 76.098;
		
		asali_->transport_[437].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[437].name,"NC10MOOH");
		asali_->transport_[437].geometry = 2;
		asali_->transport_[437].LJpotential = 640.980;
		asali_->transport_[437].LJdiameter =  7.150;
		asali_->transport_[437].dipole =  0.000;
		asali_->transport_[437].polar =  0.000;
		asali_->transport_[437].collision =  1.000;
		asali_->transport_[437].MW = 172.268;
		
		asali_->transport_[438].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[438].name,"MSTEAKETO");
		asali_->transport_[438].geometry = 2;
		asali_->transport_[438].LJpotential = 750.000;
		asali_->transport_[438].LJdiameter =  8.350;
		asali_->transport_[438].dipole =  0.000;
		asali_->transport_[438].polar =  0.000;
		asali_->transport_[438].collision =  1.000;
		asali_->transport_[438].MW = 344.492;
		
		asali_->transport_[439].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[439].name,"C5H5O");
		asali_->transport_[439].geometry = 2;
		asali_->transport_[439].LJpotential = 450.000;
		asali_->transport_[439].LJdiameter =  5.500;
		asali_->transport_[439].dipole =  0.000;
		asali_->transport_[439].polar =  0.000;
		asali_->transport_[439].collision =  1.000;
		asali_->transport_[439].MW = 81.094;
		
		asali_->transport_[440].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[440].name,"C2H2O2");
		asali_->transport_[440].geometry = 2;
		asali_->transport_[440].LJpotential = 470.600;
		asali_->transport_[440].LJdiameter =  4.410;
		asali_->transport_[440].dipole =  0.000;
		asali_->transport_[440].polar =  0.000;
		asali_->transport_[440].collision =  1.500;
		asali_->transport_[440].MW = 58.037;
		
		asali_->transport_[441].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[441].name,"C2H4O2");
		asali_->transport_[441].geometry = 2;
		asali_->transport_[441].LJpotential = 496.000;
		asali_->transport_[441].LJdiameter =  5.200;
		asali_->transport_[441].dipole =  0.000;
		asali_->transport_[441].polar =  0.000;
		asali_->transport_[441].collision =  1.000;
		asali_->transport_[441].MW = 60.053;
		
		asali_->transport_[442].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[442].name,"GLIET");
		asali_->transport_[442].geometry = 2;
		asali_->transport_[442].LJpotential = 470.600;
		asali_->transport_[442].LJdiameter =  4.410;
		asali_->transport_[442].dipole =  0.000;
		asali_->transport_[442].polar =  0.000;
		asali_->transport_[442].collision =  1.500;
		asali_->transport_[442].MW = 62.068;
		
		asali_->transport_[443].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[443].name,"C3H4O2");
		asali_->transport_[443].geometry = 2;
		asali_->transport_[443].LJpotential = 435.200;
		asali_->transport_[443].LJdiameter =  4.662;
		asali_->transport_[443].dipole =  2.700;
		asali_->transport_[443].polar =  0.000;
		asali_->transport_[443].collision =  1.000;
		asali_->transport_[443].MW = 72.064;
		
		asali_->transport_[444].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[444].name,"C3H4O3");
		asali_->transport_[444].geometry = 2;
		asali_->transport_[444].LJpotential = 435.200;
		asali_->transport_[444].LJdiameter =  4.662;
		asali_->transport_[444].dipole =  2.700;
		asali_->transport_[444].polar =  0.000;
		asali_->transport_[444].collision =  1.000;
		asali_->transport_[444].MW = 88.063;
		
		asali_->transport_[445].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[445].name,"C3H6O2");
		asali_->transport_[445].geometry = 2;
		asali_->transport_[445].LJpotential = 503.072;
		asali_->transport_[445].LJdiameter =  5.339;
		asali_->transport_[445].dipole =  1.670;
		asali_->transport_[445].polar =  7.016;
		asali_->transport_[445].collision =  1.000;
		asali_->transport_[445].MW = 74.079;
		
		asali_->transport_[446].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[446].name,"C4H6O2");
		asali_->transport_[446].geometry = 2;
		asali_->transport_[446].LJpotential = 496.000;
		asali_->transport_[446].LJdiameter =  5.200;
		asali_->transport_[446].dipole =  0.000;
		asali_->transport_[446].polar =  0.000;
		asali_->transport_[446].collision =  1.000;
		asali_->transport_[446].MW = 86.090;
		
		asali_->transport_[447].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[447].name,"C5H4O2");
		asali_->transport_[447].geometry = 2;
		asali_->transport_[447].LJpotential = 524.690;
		asali_->transport_[447].LJdiameter =  5.653;
		asali_->transport_[447].dipole =  0.000;
		asali_->transport_[447].polar =  0.000;
		asali_->transport_[447].collision =  1.000;
		asali_->transport_[447].MW = 96.086;
		
		asali_->transport_[448].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[448].name,"C5H8O4");
		asali_->transport_[448].geometry = 2;
		asali_->transport_[448].LJpotential = 568.500;
		asali_->transport_[448].LJdiameter =  5.230;
		asali_->transport_[448].dipole =  0.000;
		asali_->transport_[448].polar = 10.300;
		asali_->transport_[448].collision =  1.000;
		asali_->transport_[448].MW = 132.116;
		
		asali_->transport_[449].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[449].name,"C6H6O3");
		asali_->transport_[449].geometry = 2;
		asali_->transport_[449].LJpotential = 567.841;
		asali_->transport_[449].LJdiameter =  5.915;
		asali_->transport_[449].dipole =  0.000;
		asali_->transport_[449].polar =  0.000;
		asali_->transport_[449].collision =  1.000;
		asali_->transport_[449].MW = 126.112;
		
		asali_->transport_[450].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[450].name,"C6H8O4");
		asali_->transport_[450].geometry = 2;
		asali_->transport_[450].LJpotential = 568.500;
		asali_->transport_[450].LJdiameter =  5.230;
		asali_->transport_[450].dipole =  0.000;
		asali_->transport_[450].polar = 10.300;
		asali_->transport_[450].collision =  1.000;
		asali_->transport_[450].MW = 144.127;
		
		asali_->transport_[451].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[451].name,"C6H10O5");
		asali_->transport_[451].geometry = 2;
		asali_->transport_[451].LJpotential = 568.500;
		asali_->transport_[451].LJdiameter =  5.230;
		asali_->transport_[451].dipole =  0.000;
		asali_->transport_[451].polar = 10.300;
		asali_->transport_[451].collision =  1.000;
		asali_->transport_[451].MW = 162.142;
		
		asali_->transport_[452].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[452].name,"C8H10O3");
		asali_->transport_[452].geometry = 2;
		asali_->transport_[452].LJpotential = 621.100;
		asali_->transport_[452].LJdiameter =  5.640;
		asali_->transport_[452].dipole =  0.000;
		asali_->transport_[452].polar =  0.000;
		asali_->transport_[452].collision =  1.000;
		asali_->transport_[452].MW = 154.166;
		
		asali_->transport_[453].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[453].name,"C9H10O2");
		asali_->transport_[453].geometry = 2;
		asali_->transport_[453].LJpotential = 663.450;
		asali_->transport_[453].LJdiameter =  6.362;
		asali_->transport_[453].dipole =  0.000;
		asali_->transport_[453].polar =  0.000;
		asali_->transport_[453].collision =  1.000;
		asali_->transport_[453].MW = 150.177;
		
		asali_->transport_[454].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[454].name,"C11H12O4");
		asali_->transport_[454].geometry = 2;
		asali_->transport_[454].LJpotential = 663.450;
		asali_->transport_[454].LJdiameter =  6.362;
		asali_->transport_[454].dipole =  0.000;
		asali_->transport_[454].polar =  0.000;
		asali_->transport_[454].collision =  1.000;
		asali_->transport_[454].MW = 208.214;
		
		asali_->transport_[455].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[455].name,"C4H3O");
		asali_->transport_[455].geometry = 2;
		asali_->transport_[455].LJpotential = 425.929;
		asali_->transport_[455].LJdiameter =  5.015;
		asali_->transport_[455].dipole =  0.000;
		asali_->transport_[455].polar =  0.000;
		asali_->transport_[455].collision =  1.000;
		asali_->transport_[455].MW = 67.067;
		
		asali_->transport_[456].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[456].name,"HCOOH");
		asali_->transport_[456].geometry = 2;
		asali_->transport_[456].LJpotential = 470.600;
		asali_->transport_[456].LJdiameter =  3.855;
		asali_->transport_[456].dipole =  0.000;
		asali_->transport_[456].polar =  0.000;
		asali_->transport_[456].collision =  1.000;
		asali_->transport_[456].MW = 46.026;
		
		asali_->transport_[457].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[457].name,"ACETOL");
		asali_->transport_[457].geometry = 2;
		asali_->transport_[457].LJpotential = 503.072;
		asali_->transport_[457].LJdiameter =  5.339;
		asali_->transport_[457].dipole =  1.670;
		asali_->transport_[457].polar =  7.016;
		asali_->transport_[457].collision =  1.000;
		asali_->transport_[457].MW = 74.079;
		
		asali_->transport_[458].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[458].name,"GLYCEROL");
		asali_->transport_[458].geometry = 2;
		asali_->transport_[458].LJpotential = 748.365;
		asali_->transport_[458].LJdiameter =  5.200;
		asali_->transport_[458].dipole =  1.930;
		asali_->transport_[458].polar =  9.430;
		asali_->transport_[458].collision =  1.000;
		asali_->transport_[458].MW = 92.095;
		
		asali_->transport_[459].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[459].name,"CH2CCHCHO");
		asali_->transport_[459].geometry = 2;
		asali_->transport_[459].LJpotential = 362.600;
		asali_->transport_[459].LJdiameter =  4.530;
		asali_->transport_[459].dipole =  0.000;
		asali_->transport_[459].polar =  0.000;
		asali_->transport_[459].collision =  1.500;
		asali_->transport_[459].MW = 68.075;
		
		asali_->transport_[460].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[460].name,"KEHYBU1");
		asali_->transport_[460].geometry = 2;
		asali_->transport_[460].LJpotential = 496.000;
		asali_->transport_[460].LJdiameter =  5.200;
		asali_->transport_[460].dipole =  0.000;
		asali_->transport_[460].polar =  0.000;
		asali_->transport_[460].collision =  1.000;
		asali_->transport_[460].MW = 120.105;
		
		asali_->transport_[461].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[461].name,"RBU1OOX");
		asali_->transport_[461].geometry = 2;
		asali_->transport_[461].LJpotential = 496.000;
		asali_->transport_[461].LJdiameter =  5.200;
		asali_->transport_[461].dipole =  0.000;
		asali_->transport_[461].polar =  0.000;
		asali_->transport_[461].collision =  1.000;
		asali_->transport_[461].MW = 105.114;
		
		asali_->transport_[462].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[462].name,"QBU1OOX");
		asali_->transport_[462].geometry = 2;
		asali_->transport_[462].LJpotential = 496.000;
		asali_->transport_[462].LJdiameter =  5.200;
		asali_->transport_[462].dipole =  0.000;
		asali_->transport_[462].polar =  0.000;
		asali_->transport_[462].collision =  1.000;
		asali_->transport_[462].MW = 105.114;
		
		asali_->transport_[463].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[463].name,"ZBU1OOX");
		asali_->transport_[463].geometry = 2;
		asali_->transport_[463].LJpotential = 496.000;
		asali_->transport_[463].LJdiameter =  5.200;
		asali_->transport_[463].dipole =  0.000;
		asali_->transport_[463].polar =  0.000;
		asali_->transport_[463].collision =  1.000;
		asali_->transport_[463].MW = 137.112;
		
		asali_->transport_[464].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->transport_[464].name,"DMF");
		asali_->transport_[464].geometry = 2;
		asali_->transport_[464].LJpotential = 524.828;
		asali_->transport_[464].LJdiameter =  5.653;
		asali_->transport_[464].dipole =  0.000;
		asali_->transport_[464].polar =  0.000;
		asali_->transport_[464].collision =  1.000;
		asali_->transport_[464].MW = 96.129;
		
		asali_->transport_[465].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[465].name,"DMF-3YL");
		asali_->transport_[465].geometry = 2;
		asali_->transport_[465].LJpotential = 521.629;
		asali_->transport_[465].LJdiameter =  5.634;
		asali_->transport_[465].dipole =  0.000;
		asali_->transport_[465].polar =  0.000;
		asali_->transport_[465].collision =  1.000;
		asali_->transport_[465].MW = 95.121;
		
		asali_->transport_[466].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[466].name,"MEFU2");
		asali_->transport_[466].geometry = 2;
		asali_->transport_[466].LJpotential = 478.946;
		asali_->transport_[466].LJdiameter =  5.364;
		asali_->transport_[466].dipole =  0.000;
		asali_->transport_[466].polar =  0.000;
		asali_->transport_[466].collision =  1.000;
		asali_->transport_[466].MW = 82.102;
		
		asali_->transport_[467].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->transport_[467].name,"C4H4O");
		asali_->transport_[467].geometry = 2;
		asali_->transport_[467].LJpotential = 429.630;
		asali_->transport_[467].LJdiameter =  5.040;
		asali_->transport_[467].dipole =  0.000;
		asali_->transport_[467].polar =  0.000;
		asali_->transport_[467].collision =  1.000;
		asali_->transport_[467].MW = 68.075;
		
		asali_->transport_[468].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[468].name,"ETC3H4O2");
		asali_->transport_[468].geometry = 2;
		asali_->transport_[468].LJpotential = 411.000;
		asali_->transport_[468].LJdiameter =  4.820;
		asali_->transport_[468].dipole =  0.000;
		asali_->transport_[468].polar =  0.000;
		asali_->transport_[468].collision =  1.000;
		asali_->transport_[468].MW = 72.064;
		
		asali_->transport_[469].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[469].name,"KEA3B3");
		asali_->transport_[469].geometry = 2;
		asali_->transport_[469].LJpotential = 411.000;
		asali_->transport_[469].LJdiameter =  4.820;
		asali_->transport_[469].dipole =  0.000;
		asali_->transport_[469].polar =  0.000;
		asali_->transport_[469].collision =  1.000;
		asali_->transport_[469].MW = 104.062;
		
		asali_->transport_[470].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[470].name,"KEA3G2");
		asali_->transport_[470].geometry = 2;
		asali_->transport_[470].LJpotential = 411.000;
		asali_->transport_[470].LJdiameter =  4.820;
		asali_->transport_[470].dipole =  0.000;
		asali_->transport_[470].polar =  0.000;
		asali_->transport_[470].collision =  1.000;
		asali_->transport_[470].MW = 104.062;
		
		asali_->transport_[471].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[471].name,"RALD3G");
		asali_->transport_[471].geometry = 2;
		asali_->transport_[471].LJpotential = 411.000;
		asali_->transport_[471].LJdiameter =  4.820;
		asali_->transport_[471].dipole =  0.000;
		asali_->transport_[471].polar =  0.000;
		asali_->transport_[471].collision =  1.000;
		asali_->transport_[471].MW = 57.072;
		
		asali_->transport_[472].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->transport_[472].name,"RALD3B");
		asali_->transport_[472].geometry = 2;
		asali_->transport_[472].LJpotential = 411.000;
		asali_->transport_[472].LJdiameter =  4.820;
		asali_->transport_[472].dipole =  0.000;
		asali_->transport_[472].polar =  0.000;
		asali_->transport_[472].collision =  1.000;
		asali_->transport_[472].MW = 57.072;
		
		asali_->transport_[473].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[473].name,"C3H5CHO");
		asali_->transport_[473].geometry = 2;
		asali_->transport_[473].LJpotential = 357.000;
		asali_->transport_[473].LJdiameter =  5.180;
		asali_->transport_[473].dipole =  0.000;
		asali_->transport_[473].polar =  0.000;
		asali_->transport_[473].collision =  1.000;
		asali_->transport_[473].MW = 70.091;
		
		asali_->transport_[474].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->transport_[474].name,"C7DIONE");
		asali_->transport_[474].geometry = 2;
		asali_->transport_[474].LJpotential = 559.980;
		asali_->transport_[474].LJdiameter =  6.310;
		asali_->transport_[474].dipole =  0.000;
		asali_->transport_[474].polar =  0.000;
		asali_->transport_[474].collision =  1.000;
		asali_->transport_[474].MW = 128.171;
		
		asali_->transport_[475].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->transport_[475].name,"C7KETONE");
		asali_->transport_[475].geometry = 2;
		asali_->transport_[475].LJpotential = 559.980;
		asali_->transport_[475].LJdiameter =  6.310;
		asali_->transport_[475].dipole =  0.000;
		asali_->transport_[475].polar =  0.000;
		asali_->transport_[475].collision =  1.000;
		asali_->transport_[475].MW = 114.188;
		
		asali_->transport_[476].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[476].name,"CH2OOHCHCHO");
		asali_->transport_[476].geometry = 2;
		asali_->transport_[476].LJpotential = 407.800;
		asali_->transport_[476].LJdiameter =  4.140;
		asali_->transport_[476].dipole =  0.000;
		asali_->transport_[476].polar =  0.000;
		asali_->transport_[476].collision =  1.000;
		asali_->transport_[476].MW = 89.071;
		
		asali_->transport_[477].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[477].name,"CH2OOCH2CHO");
		asali_->transport_[477].geometry = 2;
		asali_->transport_[477].LJpotential = 407.800;
		asali_->transport_[477].LJdiameter =  4.140;
		asali_->transport_[477].dipole =  0.000;
		asali_->transport_[477].polar =  0.000;
		asali_->transport_[477].collision =  1.000;
		asali_->transport_[477].MW = 89.071;
		
		asali_->transport_[478].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->transport_[478].name,"CH2CHOOHCHO");
		asali_->transport_[478].geometry = 2;
		asali_->transport_[478].LJpotential = 407.800;
		asali_->transport_[478].LJdiameter =  4.140;
		asali_->transport_[478].dipole =  0.000;
		asali_->transport_[478].polar =  0.000;
		asali_->transport_[478].collision =  1.000;
		asali_->transport_[478].MW = 89.071;
		
		asali_->transport_[479].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->transport_[479].name,"CH3CHOOCHO");
		asali_->transport_[479].geometry = 2;
		asali_->transport_[479].LJpotential = 407.800;
		asali_->transport_[479].LJdiameter =  4.140;
		asali_->transport_[479].dipole =  0.000;
		asali_->transport_[479].polar =  0.000;
		asali_->transport_[479].collision =  1.000;
		asali_->transport_[479].MW = 89.071;
		
		asali_->transport_[480].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->transport_[480].name,"CH2OOHCHOOCHO");
		asali_->transport_[480].geometry = 2;
		asali_->transport_[480].LJpotential = 407.800;
		asali_->transport_[480].LJdiameter =  4.140;
		asali_->transport_[480].dipole =  0.000;
		asali_->transport_[480].polar =  0.000;
		asali_->transport_[480].collision =  1.000;
		asali_->transport_[480].MW = 121.070;
		
		asali_->transport_[481].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->transport_[481].name,"CH2OOCHOOHCHO");
		asali_->transport_[481].geometry = 2;
		asali_->transport_[481].LJpotential = 407.800;
		asali_->transport_[481].LJdiameter =  4.140;
		asali_->transport_[481].dipole =  0.000;
		asali_->transport_[481].polar =  0.000;
		asali_->transport_[481].collision =  1.000;
		asali_->transport_[481].MW = 121.070;
		
		asali_->transport_[482].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->transport_[482].name,"ERC4H8CHO");
		asali_->transport_[482].geometry = 2;
		asali_->transport_[482].LJpotential = 408.000;
		asali_->transport_[482].LJdiameter =  5.200;
		asali_->transport_[482].dipole =  0.000;
		asali_->transport_[482].polar =  0.000;
		asali_->transport_[482].collision =  1.000;
		asali_->transport_[482].MW = 85.126;
	}
}
