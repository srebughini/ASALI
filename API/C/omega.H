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

void omega_update(Asali* asali_)
{
	if ( !asali_->omega11_updated_ )
	{
		asali_->omega11_.size = 37;
		asali_->omega11_.d = (float*) malloc(8 * sizeof(float));
		asali_->omega11_.d[0] = 0.00;
		asali_->omega11_.d[1] = 0.25;
		asali_->omega11_.d[2] = 0.50;
		asali_->omega11_.d[3] = 0.75;
		asali_->omega11_.d[4] = 1.00;
		asali_->omega11_.d[5] = 1.50;
		asali_->omega11_.d[6] = 2.00;
		asali_->omega11_.d[7] = 2.50;

		asali_->omega11_.T = (float*) malloc(37 * sizeof(float));
		asali_->omega11_.T[0] = 0.10;
		asali_->omega11_.T[1] = 0.20;
		asali_->omega11_.T[2] = 0.30;
		asali_->omega11_.T[3] = 0.40;
		asali_->omega11_.T[4] = 0.50;
		asali_->omega11_.T[5] = 0.60;
		asali_->omega11_.T[6] = 0.70;
		asali_->omega11_.T[7] = 0.80;
		asali_->omega11_.T[8] = 0.90;
		asali_->omega11_.T[9] = 1.00;
		asali_->omega11_.T[10] = 1.20;
		asali_->omega11_.T[11] = 1.40;
		asali_->omega11_.T[12] = 1.60;
		asali_->omega11_.T[13] = 1.80;
		asali_->omega11_.T[14] = 2.00;
		asali_->omega11_.T[15] = 2.50;
		asali_->omega11_.T[16] = 3.00;
		asali_->omega11_.T[17] = 3.50;
		asali_->omega11_.T[18] = 4.00;
		asali_->omega11_.T[19] = 5.00;
		asali_->omega11_.T[20] = 6.00;
		asali_->omega11_.T[21] = 7.00;
		asali_->omega11_.T[22] = 8.00;
		asali_->omega11_.T[23] = 9.00;
		asali_->omega11_.T[24] = 10.00;
		asali_->omega11_.T[25] = 12.00;
		asali_->omega11_.T[26] = 14.00;
		asali_->omega11_.T[27] = 16.00;
		asali_->omega11_.T[28] = 18.00;
		asali_->omega11_.T[29] = 20.00;
		asali_->omega11_.T[30] = 25.00;
		asali_->omega11_.T[31] = 30.00;
		asali_->omega11_.T[32] = 35.00;
		asali_->omega11_.T[33] = 40.00;
		asali_->omega11_.T[34] = 50.00;
		asali_->omega11_.T[35] = 75.00;
		asali_->omega11_.T[36] = 100.00;

		asali_->omega11_.sigma = (float**) malloc(37 * sizeof(int));

		asali_->omega11_.sigma[0] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[0][0] = 4.0079;
		asali_->omega11_.sigma[0][1] = 4.0019;
		asali_->omega11_.sigma[0][2] = 4.6561;
		asali_->omega11_.sigma[0][3] = 5.5212;
		asali_->omega11_.sigma[0][4] = 6.4516;
		asali_->omega11_.sigma[0][5] = 8.2133;
		asali_->omega11_.sigma[0][6] = 9.8289;
		asali_->omega11_.sigma[0][7] = 11.3130;

		asali_->omega11_.sigma[1] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[1][0] = 3.1299;
		asali_->omega11_.sigma[1][1] = 3.1627;
		asali_->omega11_.sigma[1][2] = 3.3550;
		asali_->omega11_.sigma[1][3] = 3.7205;
		asali_->omega11_.sigma[1][4] = 4.1979;
		asali_->omega11_.sigma[1][5] = 5.2300;
		asali_->omega11_.sigma[1][6] = 6.2261;
		asali_->omega11_.sigma[1][7] = 7.1598;

		asali_->omega11_.sigma[2] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[2][0] = 2.6494;
		asali_->omega11_.sigma[2][1] = 2.6579;
		asali_->omega11_.sigma[2][2] = 2.7698;
		asali_->omega11_.sigma[2][3] = 3.0028;
		asali_->omega11_.sigma[2][4] = 3.3185;
		asali_->omega11_.sigma[2][5] = 4.0534;
		asali_->omega11_.sigma[2][6] = 4.7862;
		asali_->omega11_.sigma[2][7] = 5.4846;

		asali_->omega11_.sigma[3] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[3][0] = 2.3144;
		asali_->omega11_.sigma[3][1] = 2.3201;
		asali_->omega11_.sigma[3][2] = 2.4011;
		asali_->omega11_.sigma[3][3] = 2.5716;
		asali_->omega11_.sigma[3][4] = 2.8127;
		asali_->omega11_.sigma[3][5] = 3.3860;
		asali_->omega11_.sigma[3][6] = 3.9722;
		asali_->omega11_.sigma[3][7] = 4.5408;

		asali_->omega11_.sigma[4] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[4][0] = 2.0661;
		asali_->omega11_.sigma[4][1] = 2.0738;
		asali_->omega11_.sigma[4][2] = 2.1406;
		asali_->omega11_.sigma[4][3] = 2.2778;
		asali_->omega11_.sigma[4][4] = 2.4722;
		asali_->omega11_.sigma[4][5] = 2.9455;
		asali_->omega11_.sigma[4][6] = 3.4382;
		asali_->omega11_.sigma[4][7] = 3.9197;

		asali_->omega11_.sigma[5] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[5][0] = 1.8766;
		asali_->omega11_.sigma[5][1] = 1.8850;
		asali_->omega11_.sigma[5][2] = 1.9434;
		asali_->omega11_.sigma[5][3] = 2.0597;
		asali_->omega11_.sigma[5][4] = 2.2256;
		asali_->omega11_.sigma[5][5] = 2.6281;
		asali_->omega11_.sigma[5][6] = 3.0541;
		asali_->omega11_.sigma[5][7] = 3.4734;

		asali_->omega11_.sigma[6] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[6][0] = 1.7294;
		asali_->omega11_.sigma[6][1] = 1.7380;
		asali_->omega11_.sigma[6][2] = 1.7909;
		asali_->omega11_.sigma[6][3] = 1.8922;
		asali_->omega11_.sigma[6][4] = 2.0357;
		asali_->omega11_.sigma[6][5] = 2.3872;
		asali_->omega11_.sigma[6][6] = 2.7628;
		asali_->omega11_.sigma[6][7] = 3.1370;

		asali_->omega11_.sigma[7] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[7][0] = 1.6122;
		asali_->omega11_.sigma[7][1] = 1.6215;
		asali_->omega11_.sigma[7][2] = 1.6697;
		asali_->omega11_.sigma[7][3] = 1.7598;
		asali_->omega11_.sigma[7][4] = 1.8852;
		asali_->omega11_.sigma[7][5] = 2.1973;
		asali_->omega11_.sigma[7][6] = 2.5345;
		asali_->omega11_.sigma[7][7] = 2.8717;

		asali_->omega11_.sigma[8] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[8][0] = 1.5175;
		asali_->omega11_.sigma[8][1] = 1.5271;
		asali_->omega11_.sigma[8][2] = 1.5726;
		asali_->omega11_.sigma[8][3] = 1.6530;
		asali_->omega11_.sigma[8][4] = 1.7657;
		asali_->omega11_.sigma[8][5] = 2.0434;
		asali_->omega11_.sigma[8][6] = 2.3493;
		asali_->omega11_.sigma[8][7] = 2.6567;

		asali_->omega11_.sigma[9] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[9][0] = 1.4398;
		asali_->omega11_.sigma[9][1] = 1.4502;
		asali_->omega11_.sigma[9][2] = 1.4905;
		asali_->omega11_.sigma[9][3] = 1.5639;
		asali_->omega11_.sigma[9][4] = 1.6649;
		asali_->omega11_.sigma[9][5] = 1.9170;
		asali_->omega11_.sigma[9][6] = 2.1957;
		asali_->omega11_.sigma[9][7] = 2.4783;

		asali_->omega11_.sigma[10] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[10][0] = 1.3204;
		asali_->omega11_.sigma[10][1] = 1.3294;
		asali_->omega11_.sigma[10][2] = 1.3636;
		asali_->omega11_.sigma[10][3] = 1.4244;
		asali_->omega11_.sigma[10][4] = 1.5086;
		asali_->omega11_.sigma[10][5] = 1.7203;
		asali_->omega11_.sigma[10][6] = 1.9561;
		asali_->omega11_.sigma[10][7] = 2.1982;

		asali_->omega11_.sigma[11] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[11][0] = 1.2336;
		asali_->omega11_.sigma[11][1] = 1.2420;
		asali_->omega11_.sigma[11][2] = 1.2716;
		asali_->omega11_.sigma[11][3] = 1.3234;
		asali_->omega11_.sigma[11][4] = 1.3935;
		asali_->omega11_.sigma[11][5] = 1.5731;
		asali_->omega11_.sigma[11][6] = 1.7775;
		asali_->omega11_.sigma[11][7] = 1.9893;

		asali_->omega11_.sigma[12] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[12][0] = 1.1679;
		asali_->omega11_.sigma[12][1] = 1.1761;
		asali_->omega11_.sigma[12][2] = 1.2020;
		asali_->omega11_.sigma[12][3] = 1.2457;
		asali_->omega11_.sigma[12][4] = 1.3060;
		asali_->omega11_.sigma[12][5] = 1.4606;
		asali_->omega11_.sigma[12][6] = 1.6396;
		asali_->omega11_.sigma[12][7] = 1.8265;

		asali_->omega11_.sigma[13] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[13][0] = 1.1166;
		asali_->omega11_.sigma[13][1] = 1.1242;
		asali_->omega11_.sigma[13][2] = 1.1456;
		asali_->omega11_.sigma[13][3] = 1.1851;
		asali_->omega11_.sigma[13][4] = 1.2365;
		asali_->omega11_.sigma[13][5] = 1.3715;
		asali_->omega11_.sigma[13][6] = 1.5298;
		asali_->omega11_.sigma[13][7] = 1.6980;

		asali_->omega11_.sigma[14] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[14][0] = 1.0753;
		asali_->omega11_.sigma[14][1] = 1.0823;
		asali_->omega11_.sigma[14][2] = 1.1021;
		asali_->omega11_.sigma[14][3] = 1.1352;
		asali_->omega11_.sigma[14][4] = 1.1807;
		asali_->omega11_.sigma[14][5] = 1.3002;
		asali_->omega11_.sigma[14][6] = 1.4408;
		asali_->omega11_.sigma[14][7] = 1.5913;

		asali_->omega11_.sigma[15] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[15][0] = 1.0006;
		asali_->omega11_.sigma[15][1] = 1.0055;
		asali_->omega11_.sigma[15][2] = 1.0201;
		asali_->omega11_.sigma[15][3] = 1.0464;
		asali_->omega11_.sigma[15][4] = 1.0796;
		asali_->omega11_.sigma[15][5] = 1.1695;
		asali_->omega11_.sigma[15][6] = 1.2778;
		asali_->omega11_.sigma[15][7] = 1.3965;

		asali_->omega11_.sigma[16] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[16][0] = 0.9501;
		asali_->omega11_.sigma[16][1] = 0.9534;
		asali_->omega11_.sigma[16][2] = 0.9654;
		asali_->omega11_.sigma[16][3] = 0.9854;
		asali_->omega11_.sigma[16][4] = 1.0118;
		asali_->omega11_.sigma[16][5] = 1.0818;
		asali_->omega11_.sigma[16][6] = 1.1676;
		asali_->omega11_.sigma[16][7] = 1.2648;

		asali_->omega11_.sigma[17] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[17][0] = 0.9131;
		asali_->omega11_.sigma[17][1] = 0.9161;
		asali_->omega11_.sigma[17][2] = 0.9253;
		asali_->omega11_.sigma[17][3] = 0.9409;
		asali_->omega11_.sigma[17][4] = 0.9628;
		asali_->omega11_.sigma[17][5] = 1.0189;
		asali_->omega11_.sigma[17][6] = 1.0903;
		asali_->omega11_.sigma[17][7] = 1.1704;

		asali_->omega11_.sigma[18] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[18][0] = 0.8845;
		asali_->omega11_.sigma[18][1] = 0.8871;
		asali_->omega11_.sigma[18][2] = 0.8944;
		asali_->omega11_.sigma[18][3] = 0.9074;
		asali_->omega11_.sigma[18][4] = 0.9248;
		asali_->omega11_.sigma[18][5] = 0.9721;
		asali_->omega11_.sigma[18][6] = 1.0313;
		asali_->omega11_.sigma[18][7] = 1.0977;

		asali_->omega11_.sigma[19] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[19][0] = 0.8427;
		asali_->omega11_.sigma[19][1] = 0.8446;
		asali_->omega11_.sigma[19][2] = 0.8501;
		asali_->omega11_.sigma[19][3] = 0.8596;
		asali_->omega11_.sigma[19][4] = 0.8713;
		asali_->omega11_.sigma[19][5] = 0.9054;
		asali_->omega11_.sigma[19][6] = 0.9480;
		asali_->omega11_.sigma[19][7] = 0.9982;

		asali_->omega11_.sigma[20] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[20][0] = 0.8128;
		asali_->omega11_.sigma[20][1] = 0.8141;
		asali_->omega11_.sigma[20][2] = 0.8179;
		asali_->omega11_.sigma[20][3] = 0.8248;
		asali_->omega11_.sigma[20][4] = 0.8345;
		asali_->omega11_.sigma[20][5] = 0.8599;
		asali_->omega11_.sigma[20][6] = 0.8928;
		asali_->omega11_.sigma[20][7] = 0.9313;

		asali_->omega11_.sigma[21] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[21][0] = 0.7898;
		asali_->omega11_.sigma[21][1] = 0.7910;
		asali_->omega11_.sigma[21][2] = 0.7939;
		asali_->omega11_.sigma[21][3] = 0.7990;
		asali_->omega11_.sigma[21][4] = 0.8064;
		asali_->omega11_.sigma[21][5] = 0.8264;
		asali_->omega11_.sigma[21][6] = 0.8525;
		asali_->omega11_.sigma[21][7] = 0.8833;

		asali_->omega11_.sigma[22] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[22][0] = 0.7711;
		asali_->omega11_.sigma[22][1] = 0.7723;
		asali_->omega11_.sigma[22][2] = 0.7744;
		asali_->omega11_.sigma[22][3] = 0.7791;
		asali_->omega11_.sigma[22][4] = 0.7848;
		asali_->omega11_.sigma[22][5] = 0.8004;
		asali_->omega11_.sigma[22][6] = 0.8219;
		asali_->omega11_.sigma[22][7] = 0.8474;

		asali_->omega11_.sigma[23] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[23][0] = 0.7555;
		asali_->omega11_.sigma[23][1] = 0.7564;
		asali_->omega11_.sigma[23][2] = 0.7587;
		asali_->omega11_.sigma[23][3] = 0.7618;
		asali_->omega11_.sigma[23][4] = 0.7664;
		asali_->omega11_.sigma[23][5] = 0.7797;
		asali_->omega11_.sigma[23][6] = 0.7978;
		asali_->omega11_.sigma[23][7] = 0.8186;

		asali_->omega11_.sigma[24] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[24][0] = 0.7422;
		asali_->omega11_.sigma[24][1] = 0.7427;
		asali_->omega11_.sigma[24][2] = 0.7446;
		asali_->omega11_.sigma[24][3] = 0.7478;
		asali_->omega11_.sigma[24][4] = 0.7514;
		asali_->omega11_.sigma[24][5] = 0.7624;
		asali_->omega11_.sigma[24][6] = 0.7774;
		asali_->omega11_.sigma[24][7] = 0.7954;

		asali_->omega11_.sigma[25] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[25][0] = 0.7202;
		asali_->omega11_.sigma[25][1] = 0.7203;
		asali_->omega11_.sigma[25][2] = 0.7223;
		asali_->omega11_.sigma[25][3] = 0.7240;
		asali_->omega11_.sigma[25][4] = 0.7272;
		asali_->omega11_.sigma[25][5] = 0.7355;
		asali_->omega11_.sigma[25][6] = 0.7464;
		asali_->omega11_.sigma[25][7] = 0.7600;

		asali_->omega11_.sigma[26] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[26][0] = 0.7026;
		asali_->omega11_.sigma[26][1] = 0.7031;
		asali_->omega11_.sigma[26][2] = 0.7036;
		asali_->omega11_.sigma[26][3] = 0.7054;
		asali_->omega11_.sigma[26][4] = 0.7078;
		asali_->omega11_.sigma[26][5] = 0.7141;
		asali_->omega11_.sigma[26][6] = 0.7228;
		asali_->omega11_.sigma[26][7] = 0.7332;

		asali_->omega11_.sigma[27] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[27][0] = 0.6877;
		asali_->omega11_.sigma[27][1] = 0.6882;
		asali_->omega11_.sigma[27][2] = 0.6890;
		asali_->omega11_.sigma[27][3] = 0.6898;
		asali_->omega11_.sigma[27][4] = 0.6917;
		asali_->omega11_.sigma[27][5] = 0.6971;
		asali_->omega11_.sigma[27][6] = 0.7040;
		asali_->omega11_.sigma[27][7] = 0.7128;

		asali_->omega11_.sigma[28] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[28][0] = 0.6751;
		asali_->omega11_.sigma[28][1] = 0.6751;
		asali_->omega11_.sigma[28][2] = 0.6758;
		asali_->omega11_.sigma[28][3] = 0.6769;
		asali_->omega11_.sigma[28][4] = 0.6785;
		asali_->omega11_.sigma[28][5] = 0.6829;
		asali_->omega11_.sigma[28][6] = 0.6885;
		asali_->omega11_.sigma[28][7] = 0.6955;

		asali_->omega11_.sigma[29] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[29][0] = 0.6640;
		asali_->omega11_.sigma[29][1] = 0.6641;
		asali_->omega11_.sigma[29][2] = 0.6647;
		asali_->omega11_.sigma[29][3] = 0.6656;
		asali_->omega11_.sigma[29][4] = 0.6670;
		asali_->omega11_.sigma[29][5] = 0.6701;
		asali_->omega11_.sigma[29][6] = 0.6752;
		asali_->omega11_.sigma[29][7] = 0.6811;

		asali_->omega11_.sigma[30] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[30][0] = 0.6414;
		asali_->omega11_.sigma[30][1] = 0.6417;
		asali_->omega11_.sigma[30][2] = 0.6421;
		asali_->omega11_.sigma[30][3] = 0.1079;
		asali_->omega11_.sigma[30][4] = 0.6436;
		asali_->omega11_.sigma[30][5] = 0.6456;
		asali_->omega11_.sigma[30][6] = 0.6491;
		asali_->omega11_.sigma[30][7] = 0.6529;

		asali_->omega11_.sigma[31] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[31][0] = 0.6235;
		asali_->omega11_.sigma[31][1] = 0.6238;
		asali_->omega11_.sigma[31][2] = 0.6240;
		asali_->omega11_.sigma[31][3] = 0.6245;
		asali_->omega11_.sigma[31][4] = 0.6251;
		asali_->omega11_.sigma[31][5] = 0.6270;
		asali_->omega11_.sigma[31][6] = 0.6290;
		asali_->omega11_.sigma[31][7] = 0.6322;

		asali_->omega11_.sigma[32] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[32][0] = 0.6088;
		asali_->omega11_.sigma[32][1] = 0.6088;
		asali_->omega11_.sigma[32][2] = 0.6091;
		asali_->omega11_.sigma[32][3] = 0.6093;
		asali_->omega11_.sigma[32][4] = 0.6099;
		asali_->omega11_.sigma[32][5] = 0.6113;
		asali_->omega11_.sigma[32][6] = 0.6132;
		asali_->omega11_.sigma[32][7] = 0.6156;

		asali_->omega11_.sigma[33] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[33][0] = 0.5964;
		asali_->omega11_.sigma[33][1] = 0.5966;
		asali_->omega11_.sigma[33][2] = 0.5968;
		asali_->omega11_.sigma[33][3] = 0.5970;
		asali_->omega11_.sigma[33][4] = 0.5974;
		asali_->omega11_.sigma[33][5] = 0.5985;
		asali_->omega11_.sigma[33][6] = 0.6000;
		asali_->omega11_.sigma[33][7] = 0.6014;

		asali_->omega11_.sigma[34] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[34][0] = 0.5763;
		asali_->omega11_.sigma[34][1] = 0.5761;
		asali_->omega11_.sigma[34][2] = 0.5763;
		asali_->omega11_.sigma[34][3] = 0.5764;
		asali_->omega11_.sigma[34][4] = 0.5766;
		asali_->omega11_.sigma[34][5] = 0.5773;
		asali_->omega11_.sigma[34][6] = 0.5782;
		asali_->omega11_.sigma[34][7] = 0.5798;

		asali_->omega11_.sigma[35] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[35][0] = 0.5415;
		asali_->omega11_.sigma[35][1] = 0.5415;
		asali_->omega11_.sigma[35][2] = 0.5417;
		asali_->omega11_.sigma[35][3] = 0.5414;
		asali_->omega11_.sigma[35][4] = 0.5416;
		asali_->omega11_.sigma[35][5] = 0.5422;
		asali_->omega11_.sigma[35][6] = 0.5422;
		asali_->omega11_.sigma[35][7] = 0.5430;

		asali_->omega11_.sigma[36] = (float*) malloc(8 * sizeof(int));
		asali_->omega11_.sigma[36][0] = 0.5180;
		asali_->omega11_.sigma[36][1] = 0.5179;
		asali_->omega11_.sigma[36][2] = 0.5184;
		asali_->omega11_.sigma[36][3] = 0.5185;
		asali_->omega11_.sigma[36][4] = 0.5183;
		asali_->omega11_.sigma[36][5] = 0.5185;
		asali_->omega11_.sigma[36][6] = 0.5185;
		asali_->omega11_.sigma[36][7] = 0.5185;
	}

	if ( !asali_->omega22_updated_ )
	{
		asali_->omega22_.size = 37;
		asali_->omega22_.d = (float*) malloc(8 * sizeof(float));
		asali_->omega22_.d[0] = 0.00;
		asali_->omega22_.d[1] = 0.25;
		asali_->omega22_.d[2] = 0.50;
		asali_->omega22_.d[3] = 0.75;
		asali_->omega22_.d[4] = 1.00;
		asali_->omega22_.d[5] = 1.50;
		asali_->omega22_.d[6] = 2.00;
		asali_->omega22_.d[7] = 2.50;

		asali_->omega22_.T = (float*) malloc(37 * sizeof(float));
		asali_->omega22_.T[0] = 0.10;
		asali_->omega22_.T[1] = 0.20;
		asali_->omega22_.T[2] = 0.30;
		asali_->omega22_.T[3] = 0.40;
		asali_->omega22_.T[4] = 0.50;
		asali_->omega22_.T[5] = 0.60;
		asali_->omega22_.T[6] = 0.70;
		asali_->omega22_.T[7] = 0.80;
		asali_->omega22_.T[8] = 0.90;
		asali_->omega22_.T[9] = 1.00;
		asali_->omega22_.T[10] = 1.20;
		asali_->omega22_.T[11] = 1.40;
		asali_->omega22_.T[12] = 1.60;
		asali_->omega22_.T[13] = 1.80;
		asali_->omega22_.T[14] = 2.00;
		asali_->omega22_.T[15] = 2.50;
		asali_->omega22_.T[16] = 3.00;
		asali_->omega22_.T[17] = 3.50;
		asali_->omega22_.T[18] = 4.00;
		asali_->omega22_.T[19] = 5.00;
		asali_->omega22_.T[20] = 6.00;
		asali_->omega22_.T[21] = 7.00;
		asali_->omega22_.T[22] = 8.00;
		asali_->omega22_.T[23] = 9.00;
		asali_->omega22_.T[24] = 10.00;
		asali_->omega22_.T[25] = 12.00;
		asali_->omega22_.T[26] = 14.00;
		asali_->omega22_.T[27] = 16.00;
		asali_->omega22_.T[28] = 18.00;
		asali_->omega22_.T[29] = 20.00;
		asali_->omega22_.T[30] = 25.00;
		asali_->omega22_.T[31] = 30.00;
		asali_->omega22_.T[32] = 35.00;
		asali_->omega22_.T[33] = 40.00;
		asali_->omega22_.T[34] = 50.00;
		asali_->omega22_.T[35] = 75.00;
		asali_->omega22_.T[36] = 100.00;

		asali_->omega22_.sigma = (float**) malloc(37 * sizeof(float));

		asali_->omega22_.sigma[0] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[0][0] = 4.1005;
		asali_->omega22_.sigma[0][1] = 4.2660;
		asali_->omega22_.sigma[0][2] = 4.8330;
		asali_->omega22_.sigma[0][3] = 5.7420;
		asali_->omega22_.sigma[0][4] = 6.7290;
		asali_->omega22_.sigma[0][5] = 8.6240;
		asali_->omega22_.sigma[0][6] = 10.3400;
		asali_->omega22_.sigma[0][7] = 11.8900;

		asali_->omega22_.sigma[1] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[1][0] = 3.2626;
		asali_->omega22_.sigma[1][1] = 3.3050;
		asali_->omega22_.sigma[1][2] = 3.5160;
		asali_->omega22_.sigma[1][3] = 3.9140;
		asali_->omega22_.sigma[1][4] = 4.4330;
		asali_->omega22_.sigma[1][5] = 5.5700;
		asali_->omega22_.sigma[1][6] = 6.6370;
		asali_->omega22_.sigma[1][7] = 7.6180;

		asali_->omega22_.sigma[2] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[2][0] = 2.8399;
		asali_->omega22_.sigma[2][1] = 2.8360;
		asali_->omega22_.sigma[2][2] = 2.9360;
		asali_->omega22_.sigma[2][3] = 3.1680;
		asali_->omega22_.sigma[2][4] = 3.5110;
		asali_->omega22_.sigma[2][5] = 4.3290;
		asali_->omega22_.sigma[2][6] = 5.1260;
		asali_->omega22_.sigma[2][7] = 5.8740;

		asali_->omega22_.sigma[3] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[3][0] = 2.5310;
		asali_->omega22_.sigma[3][1] = 2.5220;
		asali_->omega22_.sigma[3][2] = 2.5860;
		asali_->omega22_.sigma[3][3] = 2.7490;
		asali_->omega22_.sigma[3][4] = 3.0040;
		asali_->omega22_.sigma[3][5] = 3.6400;
		asali_->omega22_.sigma[3][6] = 4.2820;
		asali_->omega22_.sigma[3][7] = 4.8950;

		asali_->omega22_.sigma[4] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[4][0] = 2.2837;
		asali_->omega22_.sigma[4][1] = 2.2770;
		asali_->omega22_.sigma[4][2] = 2.3290;
		asali_->omega22_.sigma[4][3] = 2.4600;
		asali_->omega22_.sigma[4][4] = 2.6650;
		asali_->omega22_.sigma[4][5] = 3.1870;
		asali_->omega22_.sigma[4][6] = 3.7270;
		asali_->omega22_.sigma[4][7] = 4.2490;

		asali_->omega22_.sigma[5] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[5][0] = 2.0838;
		asali_->omega22_.sigma[5][1] = 2.0810;
		asali_->omega22_.sigma[5][2] = 2.1300;
		asali_->omega22_.sigma[5][3] = 2.2430;
		asali_->omega22_.sigma[5][4] = 2.4170;
		asali_->omega22_.sigma[5][5] = 2.8620;
		asali_->omega22_.sigma[5][6] = 3.3290;
		asali_->omega22_.sigma[5][7] = 3.7860;

		asali_->omega22_.sigma[6] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[6][0] = 1.9220;
		asali_->omega22_.sigma[6][1] = 1.9240;
		asali_->omega22_.sigma[6][2] = 1.9700;
		asali_->omega22_.sigma[6][3] = 2.0720;
		asali_->omega22_.sigma[6][4] = 2.2250;
		asali_->omega22_.sigma[6][5] = 2.6140;
		asali_->omega22_.sigma[6][6] = 3.0280;
		asali_->omega22_.sigma[6][7] = 3.4350;

		asali_->omega22_.sigma[7] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[7][0] = 1.7902;
		asali_->omega22_.sigma[7][1] = 1.7950;
		asali_->omega22_.sigma[7][2] = 1.8400;
		asali_->omega22_.sigma[7][3] = 1.9340;
		asali_->omega22_.sigma[7][4] = 2.0700;
		asali_->omega22_.sigma[7][5] = 2.4170;
		asali_->omega22_.sigma[7][6] = 2.7880;
		asali_->omega22_.sigma[7][7] = 3.1560;

		asali_->omega22_.sigma[8] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[8][0] = 1.6823;
		asali_->omega22_.sigma[8][1] = 1.6890;
		asali_->omega22_.sigma[8][2] = 1.7330;
		asali_->omega22_.sigma[8][3] = 1.8200;
		asali_->omega22_.sigma[8][4] = 1.9440;
		asali_->omega22_.sigma[8][5] = 2.2580;
		asali_->omega22_.sigma[8][6] = 2.5960;
		asali_->omega22_.sigma[8][7] = 2.9330;

		asali_->omega22_.sigma[9] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[9][0] = 1.5929;
		asali_->omega22_.sigma[9][1] = 1.6010;
		asali_->omega22_.sigma[9][2] = 1.6440;
		asali_->omega22_.sigma[9][3] = 1.7250;
		asali_->omega22_.sigma[9][4] = 1.8380;
		asali_->omega22_.sigma[9][5] = 2.1240;
		asali_->omega22_.sigma[9][6] = 2.4350;
		asali_->omega22_.sigma[9][7] = 2.7460;

		asali_->omega22_.sigma[10] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[10][0] = 1.4551;
		asali_->omega22_.sigma[10][1] = 1.4650;
		asali_->omega22_.sigma[10][2] = 1.5040;
		asali_->omega22_.sigma[10][3] = 1.5740;
		asali_->omega22_.sigma[10][4] = 1.6700;
		asali_->omega22_.sigma[10][5] = 1.9130;
		asali_->omega22_.sigma[10][6] = 2.1810;
		asali_->omega22_.sigma[10][7] = 2.4510;

		asali_->omega22_.sigma[11] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[11][0] = 1.3551;
		asali_->omega22_.sigma[11][1] = 1.3650;
		asali_->omega22_.sigma[11][2] = 1.4000;
		asali_->omega22_.sigma[11][3] = 1.4610;
		asali_->omega22_.sigma[11][4] = 1.5440;
		asali_->omega22_.sigma[11][5] = 1.7540;
		asali_->omega22_.sigma[11][6] = 1.9890;
		asali_->omega22_.sigma[11][7] = 2.2280;

		asali_->omega22_.sigma[12] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[12][0] = 1.2800;
		asali_->omega22_.sigma[12][1] = 1.2890;
		asali_->omega22_.sigma[12][2] = 1.3210;
		asali_->omega22_.sigma[12][3] = 1.3740;
		asali_->omega22_.sigma[12][4] = 1.4470;
		asali_->omega22_.sigma[12][5] = 1.6300;
		asali_->omega22_.sigma[12][6] = 1.8380;
		asali_->omega22_.sigma[12][7] = 2.0530;

		asali_->omega22_.sigma[13] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[13][0] = 1.2219;
		asali_->omega22_.sigma[13][1] = 1.2310;
		asali_->omega22_.sigma[13][2] = 1.2590;
		asali_->omega22_.sigma[13][3] = 1.3060;
		asali_->omega22_.sigma[13][4] = 1.3700;
		asali_->omega22_.sigma[13][5] = 1.5320;
		asali_->omega22_.sigma[13][6] = 1.7180;
		asali_->omega22_.sigma[13][7] = 1.9120;

		asali_->omega22_.sigma[14] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[14][0] = 1.1757;
		asali_->omega22_.sigma[14][1] = 1.1840;
		asali_->omega22_.sigma[14][2] = 1.2090;
		asali_->omega22_.sigma[14][3] = 1.2510;
		asali_->omega22_.sigma[14][4] = 1.3070;
		asali_->omega22_.sigma[14][5] = 1.4510;
		asali_->omega22_.sigma[14][6] = 1.6180;
		asali_->omega22_.sigma[14][7] = 1.7950;

		asali_->omega22_.sigma[15] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[15][0] = 1.0933;
		asali_->omega22_.sigma[15][1] = 1.1000;
		asali_->omega22_.sigma[15][2] = 1.1190;
		asali_->omega22_.sigma[15][3] = 1.1500;
		asali_->omega22_.sigma[15][4] = 1.1930;
		asali_->omega22_.sigma[15][5] = 1.3040;
		asali_->omega22_.sigma[15][6] = 1.4350;
		asali_->omega22_.sigma[15][7] = 1.5780;

		asali_->omega22_.sigma[16] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[16][0] = 1.0388;
		asali_->omega22_.sigma[16][1] = 1.0440;
		asali_->omega22_.sigma[16][2] = 1.0590;
		asali_->omega22_.sigma[16][3] = 1.0830;
		asali_->omega22_.sigma[16][4] = 1.1170;
		asali_->omega22_.sigma[16][5] = 1.2040;
		asali_->omega22_.sigma[16][6] = 1.3100;
		asali_->omega22_.sigma[16][7] = 1.4280;

		asali_->omega22_.sigma[17] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[17][0] = 0.9996;
		asali_->omega22_.sigma[17][1] = 1.0040;
		asali_->omega22_.sigma[17][2] = 1.0160;
		asali_->omega22_.sigma[17][3] = 1.0350;
		asali_->omega22_.sigma[17][4] = 1.0620;
		asali_->omega22_.sigma[17][5] = 1.1330;
		asali_->omega22_.sigma[17][6] = 1.2200;
		asali_->omega22_.sigma[17][7] = 1.3190;

		asali_->omega22_.sigma[18] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[18][0] = 0.9699;
		asali_->omega22_.sigma[18][1] = 0.9732;
		asali_->omega22_.sigma[18][2] = 0.9830;
		asali_->omega22_.sigma[18][3] = 0.9991;
		asali_->omega22_.sigma[18][4] = 1.0210;
		asali_->omega22_.sigma[18][5] = 1.0790;
		asali_->omega22_.sigma[18][6] = 1.1530;
		asali_->omega22_.sigma[18][7] = 1.2360;

		asali_->omega22_.sigma[19] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[19][0] = 0.9268;
		asali_->omega22_.sigma[19][1] = 0.9291;
		asali_->omega22_.sigma[19][2] = 0.9360;
		asali_->omega22_.sigma[19][3] = 0.9473;
		asali_->omega22_.sigma[19][4] = 0.9628;
		asali_->omega22_.sigma[19][5] = 1.0050;
		asali_->omega22_.sigma[19][6] = 1.0580;
		asali_->omega22_.sigma[19][7] = 1.1210;

		asali_->omega22_.sigma[20] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[20][0] = 0.8962;
		asali_->omega22_.sigma[20][1] = 0.8979;
		asali_->omega22_.sigma[20][2] = 0.9030;
		asali_->omega22_.sigma[20][3] = 0.9114;
		asali_->omega22_.sigma[20][4] = 0.9230;
		asali_->omega22_.sigma[20][5] = 0.9545;
		asali_->omega22_.sigma[20][6] = 0.9955;
		asali_->omega22_.sigma[20][7] = 1.0440;

		asali_->omega22_.sigma[21] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[21][0] = 0.8727;
		asali_->omega22_.sigma[21][1] = 0.8741;
		asali_->omega22_.sigma[21][2] = 0.8780;
		asali_->omega22_.sigma[21][3] = 0.8845;
		asali_->omega22_.sigma[21][4] = 0.8935;
		asali_->omega22_.sigma[21][5] = 0.9181;
		asali_->omega22_.sigma[21][6] = 0.9505;
		asali_->omega22_.sigma[21][7] = 0.9893;

		asali_->omega22_.sigma[22] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[22][0] = 0.8538;
		asali_->omega22_.sigma[22][1] = 0.8549;
		asali_->omega22_.sigma[22][2] = 0.8580;
		asali_->omega22_.sigma[22][3] = 0.8632;
		asali_->omega22_.sigma[22][4] = 0.8703;
		asali_->omega22_.sigma[22][5] = 0.8901;
		asali_->omega22_.sigma[22][6] = 0.9164;
		asali_->omega22_.sigma[22][7] = 0.9482;

		asali_->omega22_.sigma[23] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[23][0] = 0.8379;
		asali_->omega22_.sigma[23][1] = 0.8388;
		asali_->omega22_.sigma[23][2] = 0.8414;
		asali_->omega22_.sigma[23][3] = 0.8456;
		asali_->omega22_.sigma[23][4] = 0.8515;
		asali_->omega22_.sigma[23][5] = 0.8678;
		asali_->omega22_.sigma[23][6] = 0.8895;
		asali_->omega22_.sigma[23][7] = 0.9160;

		asali_->omega22_.sigma[24] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[24][0] = 0.8243;
		asali_->omega22_.sigma[24][1] = 0.8251;
		asali_->omega22_.sigma[24][2] = 0.8273;
		asali_->omega22_.sigma[24][3] = 0.8308;
		asali_->omega22_.sigma[24][4] = 0.8356;
		asali_->omega22_.sigma[24][5] = 0.8493;
		asali_->omega22_.sigma[24][6] = 0.8676;
		asali_->omega22_.sigma[24][7] = 0.8901;

		asali_->omega22_.sigma[25] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[25][0] = 0.8018;
		asali_->omega22_.sigma[25][1] = 0.8024;
		asali_->omega22_.sigma[25][2] = 0.8039;
		asali_->omega22_.sigma[25][3] = 0.8065;
		asali_->omega22_.sigma[25][4] = 0.8101;
		asali_->omega22_.sigma[25][5] = 0.8201;
		asali_->omega22_.sigma[25][6] = 0.8337;
		asali_->omega22_.sigma[25][7] = 0.8504;

		asali_->omega22_.sigma[26] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[26][0] = 0.7836;
		asali_->omega22_.sigma[26][1] = 0.7840;
		asali_->omega22_.sigma[26][2] = 0.7852;
		asali_->omega22_.sigma[26][3] = 0.7872;
		asali_->omega22_.sigma[26][4] = 0.7899;
		asali_->omega22_.sigma[26][5] = 0.7976;
		asali_->omega22_.sigma[26][6] = 0.8081;
		asali_->omega22_.sigma[26][7] = 0.8212;

		asali_->omega22_.sigma[27] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[27][0] = 0.7683;
		asali_->omega22_.sigma[27][1] = 0.7687;
		asali_->omega22_.sigma[27][2] = 0.7696;
		asali_->omega22_.sigma[27][3] = 0.7712;
		asali_->omega22_.sigma[27][4] = 0.7733;
		asali_->omega22_.sigma[27][5] = 0.7794;
		asali_->omega22_.sigma[27][6] = 0.7878;
		asali_->omega22_.sigma[27][7] = 0.7983;

		asali_->omega22_.sigma[28] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[28][0] = 0.7552;
		asali_->omega22_.sigma[28][1] = 0.7554;
		asali_->omega22_.sigma[28][2] = 0.7562;
		asali_->omega22_.sigma[28][3] = 0.7575;
		asali_->omega22_.sigma[28][4] = 0.7592;
		asali_->omega22_.sigma[28][5] = 0.7642;
		asali_->omega22_.sigma[28][6] = 0.7711;
		asali_->omega22_.sigma[28][7] = 0.7797;

		asali_->omega22_.sigma[29] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[29][0] = 0.7436;
		asali_->omega22_.sigma[29][1] = 0.7438;
		asali_->omega22_.sigma[29][2] = 0.7445;
		asali_->omega22_.sigma[29][3] = 0.7455;
		asali_->omega22_.sigma[29][4] = 0.7470;
		asali_->omega22_.sigma[29][5] = 0.7512;
		asali_->omega22_.sigma[29][6] = 0.7569;
		asali_->omega22_.sigma[29][7] = 0.7642;

		asali_->omega22_.sigma[30] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[30][0] = 0.7198;
		asali_->omega22_.sigma[30][1] = 0.7200;
		asali_->omega22_.sigma[30][2] = 0.7204;
		asali_->omega22_.sigma[30][3] = 0.1211;
		asali_->omega22_.sigma[30][4] = 0.7221;
		asali_->omega22_.sigma[30][5] = 0.7250;
		asali_->omega22_.sigma[30][6] = 0.7289;
		asali_->omega22_.sigma[30][7] = 0.7339;

		asali_->omega22_.sigma[31] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[31][0] = 0.7010;
		asali_->omega22_.sigma[31][1] = 0.7011;
		asali_->omega22_.sigma[31][2] = 0.7014;
		asali_->omega22_.sigma[31][3] = 0.7019;
		asali_->omega22_.sigma[31][4] = 0.7026;
		asali_->omega22_.sigma[31][5] = 0.7047;
		asali_->omega22_.sigma[31][6] = 0.7076;
		asali_->omega22_.sigma[31][7] = 0.7112;

		asali_->omega22_.sigma[32] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[32][0] = 0.6855;
		asali_->omega22_.sigma[32][1] = 0.6855;
		asali_->omega22_.sigma[32][2] = 0.6858;
		asali_->omega22_.sigma[32][3] = 0.6861;
		asali_->omega22_.sigma[32][4] = 0.6867;
		asali_->omega22_.sigma[32][5] = 0.6883;
		asali_->omega22_.sigma[32][6] = 0.6905;
		asali_->omega22_.sigma[32][7] = 0.6932;

		asali_->omega22_.sigma[33] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[33][0] = 0.6723;
		asali_->omega22_.sigma[33][1] = 0.6724;
		asali_->omega22_.sigma[33][2] = 0.6726;
		asali_->omega22_.sigma[33][3] = 0.6728;
		asali_->omega22_.sigma[33][4] = 0.6733;
		asali_->omega22_.sigma[33][5] = 0.6745;
		asali_->omega22_.sigma[33][6] = 0.6762;
		asali_->omega22_.sigma[33][7] = 0.6784;

		asali_->omega22_.sigma[34] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[34][0] = 0.6510;
		asali_->omega22_.sigma[34][1] = 0.6510;
		asali_->omega22_.sigma[34][2] = 0.6512;
		asali_->omega22_.sigma[34][3] = 0.6513;
		asali_->omega22_.sigma[34][4] = 0.6516;
		asali_->omega22_.sigma[34][5] = 0.6524;
		asali_->omega22_.sigma[34][6] = 0.6534;
		asali_->omega22_.sigma[34][7] = 0.6546;

		asali_->omega22_.sigma[35] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[35][0] = 0.6140;
		asali_->omega22_.sigma[35][1] = 0.6141;
		asali_->omega22_.sigma[35][2] = 0.6143;
		asali_->omega22_.sigma[35][3] = 0.6145;
		asali_->omega22_.sigma[35][4] = 0.6147;
		asali_->omega22_.sigma[35][5] = 0.6148;
		asali_->omega22_.sigma[35][6] = 0.6148;
		asali_->omega22_.sigma[35][7] = 0.6147;

		asali_->omega22_.sigma[36] = (float*) malloc(8 * sizeof(int));
		asali_->omega22_.sigma[36][0] = 0.5887;
		asali_->omega22_.sigma[36][1] = 0.5889;
		asali_->omega22_.sigma[36][2] = 0.5894;
		asali_->omega22_.sigma[36][3] = 0.5900;
		asali_->omega22_.sigma[36][4] = 0.5903;
		asali_->omega22_.sigma[36][5] = 0.5901;
		asali_->omega22_.sigma[36][6] = 0.5895;
		asali_->omega22_.sigma[36][7] = 0.5885;
	}
}
