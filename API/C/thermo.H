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

void thermo_update(Asali* asali_)
{
	if ( !asali_->thermo_updated_ )
	{
		asali_->thermo_ = (struct thermoParameters*) malloc(483 * sizeof(struct thermoParameters));
		
		asali_->thermo_[0].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[0].name,"AC3H4");

		asali_->thermo_[0].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[0].high[0] = 6.6443023682e+00;
		asali_->thermo_[0].high[1] = 1.1498782784e-02;
		asali_->thermo_[0].high[2] = -4.6809959713e-06;
		asali_->thermo_[0].high[3] = 9.6233421232e-10;
		asali_->thermo_[0].high[4] = -8.2436004366e-14;
		asali_->thermo_[0].high[5] = 2.0713119141e+04;
		asali_->thermo_[0].high[6] = -1.3574454308e+01;

		asali_->thermo_[0].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[0].low[0] = 1.2156292200e+00;
		asali_->thermo_[0].low[1] = 2.3562500253e-02;
		asali_->thermo_[0].low[2] = -1.4734094293e-05;
		asali_->thermo_[0].low[3] = 4.6857038249e-09;
		asali_->thermo_[0].low[4] = -5.9957068607e-13;
		asali_->thermo_[0].low[5] = 2.2667441406e+04;
		asali_->thermo_[0].low[6] = 1.5806657791e+01;
		
		asali_->thermo_[1].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[1].name,"CH3COOH");

		asali_->thermo_[1].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[1].high[0] = 7.8349161148e+00;
		asali_->thermo_[1].high[1] = 1.1235706508e-02;
		asali_->thermo_[1].high[2] = -3.1355807550e-06;
		asali_->thermo_[1].high[3] = 1.5950281373e-10;
		asali_->thermo_[1].high[4] = 3.0135755138e-14;
		asali_->thermo_[1].high[5] = -5.5741500000e+04;
		asali_->thermo_[1].high[6] = -1.5380991936e+01;

		asali_->thermo_[1].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[1].low[0] = 3.1316855550e-01;
		asali_->thermo_[1].low[1] = 3.2573997974e-02;
		asali_->thermo_[1].low[2] = -2.5835890483e-05;
		asali_->thermo_[1].low[3] = 1.0892510005e-08;
		asali_->thermo_[1].low[4] = -1.8728796725e-12;
		asali_->thermo_[1].low[5] = -5.3620367188e+04;
		asali_->thermo_[1].low[6] = 2.3491487503e+01;
		
		asali_->thermo_[2].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[2].name,"CH3COCH3");

		asali_->thermo_[2].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[2].high[0] = 8.2215738297e-01;
		asali_->thermo_[2].high[1] = 3.1896464527e-02;
		asali_->thermo_[2].high[2] = -1.6832405890e-05;
		asali_->thermo_[2].high[3] = 4.2070604778e-09;
		asali_->thermo_[2].high[4] = -4.0412492146e-13;
		asali_->thermo_[2].high[5] = -2.7473726562e+04;
		asali_->thermo_[2].high[6] = 2.1787355423e+01;

		asali_->thermo_[2].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[2].low[0] = 1.0365401506e+00;
		asali_->thermo_[2].low[1] = 3.0671417713e-02;
		asali_->thermo_[2].low[2] = -1.4207309505e-05;
		asali_->thermo_[2].low[3] = 1.7069693437e-09;
		asali_->thermo_[2].low[4] = 4.8876479036e-13;
		asali_->thermo_[2].low[5] = -2.7503740234e+04;
		asali_->thermo_[2].low[6] = 2.0829545975e+01;
		
		asali_->thermo_[3].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[3].name,"C2H3CHO");

		asali_->thermo_[3].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[3].high[0] = 6.7051777840e+00;
		asali_->thermo_[3].high[1] = 1.6122244298e-02;
		asali_->thermo_[3].high[2] = -7.5729885793e-06;
		asali_->thermo_[3].high[3] = 1.7030723498e-09;
		asali_->thermo_[3].high[4] = -1.4992484522e-13;
		asali_->thermo_[3].high[5] = -1.3361859375e+04;
		asali_->thermo_[3].high[6] = -9.8861370087e+00;

		asali_->thermo_[3].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[3].low[0] = 3.4091767669e-01;
		asali_->thermo_[3].low[1] = 3.5120036453e-02;
		asali_->thermo_[3].low[2] = -2.8839172955e-05;
		asali_->thermo_[3].low[3] = 1.2283263295e-08;
		asali_->thermo_[3].low[4] = -2.1238410336e-12;
		asali_->thermo_[3].low[5] = -1.1656237305e+04;
		asali_->thermo_[3].low[6] = 2.2680364609e+01;
		
		asali_->thermo_[4].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[4].name,"C2H5CHO");

		asali_->thermo_[4].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[4].high[0] = -3.1979615688e+00;
		asali_->thermo_[4].high[1] = 4.1740134358e-02;
		asali_->thermo_[4].high[2] = -2.2215695935e-05;
		asali_->thermo_[4].high[3] = 5.3759645624e-09;
		asali_->thermo_[4].high[4] = -4.9560122716e-13;
		asali_->thermo_[4].high[5] = -2.3145765625e+04;
		asali_->thermo_[4].high[6] = 4.4338539124e+01;

		asali_->thermo_[4].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[4].low[0] = 4.6596760750e+00;
		asali_->thermo_[4].low[1] = 1.4169476926e-02;
		asali_->thermo_[4].low[2] = 1.4061485672e-05;
		asali_->thermo_[4].low[3] = -1.5838761414e-08;
		asali_->thermo_[4].low[4] = 4.1567508983e-12;
		asali_->thermo_[4].low[5] = -2.4937306641e+04;
		asali_->thermo_[4].low[6] = 5.4004096985e+00;
		
		asali_->thermo_[5].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[5].name,"C4H9CHO");

		asali_->thermo_[5].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[5].high[0] = -1.7843317986e+00;
		asali_->thermo_[5].high[1] = 6.3120439649e-02;
		asali_->thermo_[5].high[2] = -3.6083620216e-05;
		asali_->thermo_[5].high[3] = 9.4832195430e-09;
		asali_->thermo_[5].high[4] = -9.3952254830e-13;
		asali_->thermo_[5].high[5] = -2.9711351562e+04;
		asali_->thermo_[5].high[6] = 3.9247871399e+01;

		asali_->thermo_[5].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[5].low[0] = 5.5329899788e+00;
		asali_->thermo_[5].low[1] = 2.4608217180e-02;
		asali_->thermo_[5].low[2] = 3.9927341277e-05;
		asali_->thermo_[5].low[3] = -5.7193062730e-08;
		asali_->thermo_[5].low[4] = 2.0993465646e-11;
		asali_->thermo_[5].low[5] = -3.0823583984e+04;
		asali_->thermo_[5].low[6] = 5.9541654587e+00;
		
		asali_->thermo_[6].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[6].name,"CH2CHCH2");

		asali_->thermo_[6].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[6].high[0] = 1.3127011299e+01;
		asali_->thermo_[6].high[1] = 3.3781263046e-03;
		asali_->thermo_[6].high[2] = 1.3078795291e-06;
		asali_->thermo_[6].high[3] = -8.7250207059e-10;
		asali_->thermo_[6].high[4] = 1.1377986227e-13;
		asali_->thermo_[6].high[5] = 1.3856911133e+04;
		asali_->thermo_[6].high[6] = -4.7198570251e+01;

		asali_->thermo_[6].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[6].low[0] = 1.4578819275e-01;
		asali_->thermo_[6].low[1] = 3.2225288451e-02;
		asali_->thermo_[6].low[2] = -2.2731423087e-05;
		asali_->thermo_[6].low[3] = 8.0309430217e-09;
		asali_->thermo_[6].low[4] = -1.1228097445e-12;
		asali_->thermo_[6].low[5] = 1.8530150391e+04;
		asali_->thermo_[6].low[6] = 2.3058517456e+01;
		
		asali_->thermo_[7].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[7].name,"CHCHCH3");

		asali_->thermo_[7].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[7].high[0] = 1.0012436867e+01;
		asali_->thermo_[7].high[1] = 7.5581581332e-03;
		asali_->thermo_[7].high[2] = -1.1709696537e-06;
		asali_->thermo_[7].high[3] = -2.0179481697e-10;
		asali_->thermo_[7].high[4] = 4.7298797501e-14;
		asali_->thermo_[7].high[5] = 2.7864195312e+04;
		asali_->thermo_[7].high[6] = -2.7516983032e+01;

		asali_->thermo_[7].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[7].low[0] = 6.1051201820e-01;
		asali_->thermo_[7].low[1] = 2.8451325372e-02;
		asali_->thermo_[7].low[2] = -1.8581942641e-05;
		asali_->thermo_[7].low[3] = 6.2467133688e-09;
		asali_->thermo_[7].low[4] = -8.4832737623e-13;
		asali_->thermo_[7].low[5] = 3.1248888672e+04;
		asali_->thermo_[7].low[6] = 2.3368198395e+01;
		
		asali_->thermo_[8].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[8].name,"CH2CCH3");

		asali_->thermo_[8].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[8].high[0] = 1.0012436867e+01;
		asali_->thermo_[8].high[1] = 7.5581581332e-03;
		asali_->thermo_[8].high[2] = -1.1709696537e-06;
		asali_->thermo_[8].high[3] = -2.0179481697e-10;
		asali_->thermo_[8].high[4] = 4.7298797501e-14;
		asali_->thermo_[8].high[5] = 2.7864195312e+04;
		asali_->thermo_[8].high[6] = -2.7516983032e+01;

		asali_->thermo_[8].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[8].low[0] = 6.1051201820e-01;
		asali_->thermo_[8].low[1] = 2.8451325372e-02;
		asali_->thermo_[8].low[2] = -1.8581942641e-05;
		asali_->thermo_[8].low[3] = 6.2467133688e-09;
		asali_->thermo_[8].low[4] = -8.4832737623e-13;
		asali_->thermo_[8].low[5] = 3.1248888672e+04;
		asali_->thermo_[8].low[6] = 2.3368198395e+01;
		
		
		asali_->thermo_[10].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[10].name,"C6H5CH2OH");

		asali_->thermo_[10].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[10].high[0] = 1.2581844330e+01;
		asali_->thermo_[10].high[1] = 2.6413451880e-02;
		asali_->thermo_[10].high[2] = -7.9379988165e-06;
		asali_->thermo_[10].high[3] = 4.3836823060e-10;
		asali_->thermo_[10].high[4] = 8.6407897710e-14;
		asali_->thermo_[10].high[5] = -1.8782896484e+04;
		asali_->thermo_[10].high[6] = -3.8133232117e+01;

		asali_->thermo_[10].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[10].low[0] = -6.0288496017e+00;
		asali_->thermo_[10].low[1] = 7.7753297985e-02;
		asali_->thermo_[10].low[2] = -6.1048187490e-05;
		asali_->thermo_[10].low[3] = 2.4856843694e-08;
		asali_->thermo_[10].low[4] = -4.1236740585e-12;
		asali_->thermo_[10].low[5] = -1.3385794922e+04;
		asali_->thermo_[10].low[6] = 5.8567665100e+01;
		
		asali_->thermo_[11].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[11].name,"C6H4O2");

		asali_->thermo_[11].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[11].high[0] = 1.7492958069e+01;
		asali_->thermo_[11].high[1] = 1.2902128510e-02;
		asali_->thermo_[11].high[2] = -2.0297663923e-06;
		asali_->thermo_[11].high[3] = -3.7241784656e-10;
		asali_->thermo_[11].high[4] = 8.5974575983e-14;
		asali_->thermo_[11].high[5] = -2.2210046875e+04;
		asali_->thermo_[11].high[6] = -6.4901580811e+01;

		asali_->thermo_[11].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[11].low[0] = -5.2344655991e+00;
		asali_->thermo_[11].low[1] = 7.7377088368e-02;
		asali_->thermo_[11].low[2] = -7.0620146289e-05;
		asali_->thermo_[11].low[3] = 3.2058022015e-08;
		asali_->thermo_[11].low[4] = -5.6641037346e-12;
		asali_->thermo_[11].low[5] = -1.5800912109e+04;
		asali_->thermo_[11].low[6] = 5.2554004669e+01;
		
		asali_->thermo_[12].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[12].name,"C6H6");

		asali_->thermo_[12].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[12].high[0] = 1.5736582756e+01;
		asali_->thermo_[12].high[1] = 1.2444414198e-02;
		asali_->thermo_[12].high[2] = -2.0824247713e-06;
		asali_->thermo_[12].high[3] = -1.9055516887e-10;
		asali_->thermo_[12].high[4] = 5.6093865853e-14;
		asali_->thermo_[12].high[5] = 2.3753884277e+03;
		asali_->thermo_[12].high[6] = -6.6038093567e+01;

		asali_->thermo_[12].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[12].low[0] = -6.3336114883e+00;
		asali_->thermo_[12].low[1] = 6.9399751723e-02;
		asali_->thermo_[12].low[2] = -5.7200497395e-05;
		asali_->thermo_[12].low[3] = 2.3516141923e-08;
		asali_->thermo_[12].low[4] = -3.7675669876e-12;
		asali_->thermo_[12].low[5] = 9.2171484375e+03;
		asali_->thermo_[12].low[6] = 5.0110206604e+01;
		
		asali_->thermo_[13].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[13].name,"C6H5CHO");

		asali_->thermo_[13].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[13].high[0] = 2.7358848572e+01;
		asali_->thermo_[13].high[1] = 2.4572545663e-03;
		asali_->thermo_[13].high[2] = 5.4113033912e-06;
		asali_->thermo_[13].high[3] = -2.5853170715e-09;
		asali_->thermo_[13].high[4] = 3.2164987904e-13;
		asali_->thermo_[13].high[5] = -1.7642955078e+04;
		asali_->thermo_[13].high[6] = -1.2360829163e+02;

		asali_->thermo_[13].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[13].low[0] = -6.5570597649e+00;
		asali_->thermo_[13].low[1] = 7.9103372991e-02;
		asali_->thermo_[13].low[2] = -5.9543035604e-05;
		asali_->thermo_[13].low[3] = 2.1879593248e-08;
		asali_->thermo_[13].low[4] = -3.1338460472e-12;
		asali_->thermo_[13].low[5] = -5.6367226562e+03;
		asali_->thermo_[13].low[6] = 5.9381649017e+01;
		
		asali_->thermo_[14].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->thermo_[14].name,"C6H5C2H4C6H5");

		asali_->thermo_[14].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[14].high[0] = 2.2999992371e+01;
		asali_->thermo_[14].high[1] = 5.2355147898e-02;
		asali_->thermo_[14].high[2] = -1.6202304323e-05;
		asali_->thermo_[14].high[3] = 1.0634692016e-09;
		asali_->thermo_[14].high[4] = 1.4874756429e-13;
		asali_->thermo_[14].high[5] = 3.2013186035e+03;
		asali_->thermo_[14].high[6] = -9.1870422363e+01;

		asali_->thermo_[14].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[14].low[0] = -1.0558960915e+01;
		asali_->thermo_[14].low[1] = 1.4557446539e-01;
		asali_->thermo_[14].low[2] = -1.1330575944e-04;
		asali_->thermo_[14].low[3] = 4.6018772792e-08;
		asali_->thermo_[14].low[4] = -7.6559921597e-12;
		asali_->thermo_[14].low[5] = 1.2866297852e+04;
		asali_->thermo_[14].low[6] = 8.2269172668e+01;
		
		asali_->thermo_[15].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[15].name,"NC4H8");

		asali_->thermo_[15].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[15].high[0] = 2.9870982170e+00;
		asali_->thermo_[15].high[1] = 3.2528255135e-02;
		asali_->thermo_[15].high[2] = -1.4625047697e-05;
		asali_->thermo_[15].high[3] = 2.9413638192e-09;
		asali_->thermo_[15].high[4] = -2.1496080740e-13;
		asali_->thermo_[15].high[5] = -2.5011188965e+03;
		asali_->thermo_[15].high[6] = 1.0397191048e+01;

		asali_->thermo_[15].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[15].low[0] = -1.0570777655e+00;
		asali_->thermo_[15].low[1] = 4.6354494989e-02;
		asali_->thermo_[15].low[2] = -3.2350999390e-05;
		asali_->thermo_[15].low[3] = 1.3041621116e-08;
		asali_->thermo_[15].low[4] = -2.3731355422e-12;
		asali_->thermo_[15].low[5] = -1.5547818604e+03;
		asali_->thermo_[15].low[6] = 3.0542951584e+01;
		
		asali_->thermo_[16].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[16].name,"C4H6");

		asali_->thermo_[16].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[16].high[0] = 9.5539531708e+00;
		asali_->thermo_[16].high[1] = 1.5136481263e-02;
		asali_->thermo_[16].high[2] = -4.7850944611e-06;
		asali_->thermo_[16].high[3] = 6.1495536441e-10;
		asali_->thermo_[16].high[4] = -2.2380994017e-14;
		asali_->thermo_[16].high[5] = 8.6328466797e+03;
		asali_->thermo_[16].high[6] = -2.7796669006e+01;

		asali_->thermo_[16].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[16].low[0] = -1.0453385115e+00;
		asali_->thermo_[16].low[1] = 4.2489491403e-02;
		asali_->thermo_[16].low[2] = -3.1255749491e-05;
		asali_->thermo_[16].low[3] = 1.2000183958e-08;
		asali_->thermo_[16].low[4] = -1.8587082828e-12;
		asali_->thermo_[16].low[5] = 1.1918627930e+04;
		asali_->thermo_[16].low[6] = 2.7983980179e+01;
		
		asali_->thermo_[17].name = (char*) malloc(1 * sizeof(char));
		strcpy(asali_->thermo_[17].name,"C");

		asali_->thermo_[17].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[17].high[0] = 2.4898967743e+00;
		asali_->thermo_[17].high[1] = 5.1496568631e-05;
		asali_->thermo_[17].high[2] = -7.3791241562e-08;
		asali_->thermo_[17].high[3] = 3.7572167599e-11;
		asali_->thermo_[17].high[4] = -4.8658375167e-15;
		asali_->thermo_[17].high[5] = 8.5452781250e+04;
		asali_->thermo_[17].high[6] = 4.8178324699e+00;

		asali_->thermo_[17].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[17].low[0] = 2.5508840084e+00;
		asali_->thermo_[17].low[1] = -2.9700165032e-04;
		asali_->thermo_[17].low[2] = 6.7299060902e-07;
		asali_->thermo_[17].low[3] = -6.7364863687e-10;
		asali_->thermo_[17].low[4] = 2.4914160904e-13;
		asali_->thermo_[17].low[5] = 8.5444242188e+04;
		asali_->thermo_[17].low[6] = 4.5453572273e+00;
		
		asali_->thermo_[18].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[18].name,"C12H8");

		asali_->thermo_[18].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[18].high[0] = 2.5965219498e+01;
		asali_->thermo_[18].high[1] = 2.4250119925e-02;
		asali_->thermo_[18].high[2] = -4.8141287152e-06;
		asali_->thermo_[18].high[3] = -4.2107872744e-10;
		asali_->thermo_[18].high[4] = 1.4744710444e-13;
		asali_->thermo_[18].high[5] = 1.9077857422e+04;
		asali_->thermo_[18].high[6] = -1.1825495148e+02;

		asali_->thermo_[18].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[18].low[0] = -9.2819910049e+00;
		asali_->thermo_[18].low[1] = 1.2284371257e-01;
		asali_->thermo_[18].low[2] = -1.0823398043e-04;
		asali_->thermo_[18].low[3] = 4.7793303537e-08;
		asali_->thermo_[18].low[4] = -8.2816409980e-12;
		asali_->thermo_[18].low[5] = 2.9158558594e+04;
		asali_->thermo_[18].low[6] = 6.4399482727e+01;
		
		asali_->thermo_[19].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[19].name,"C2H");

		asali_->thermo_[19].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[19].high[0] = 2.6270606518e+00;
		asali_->thermo_[19].high[1] = 5.6143915281e-03;
		asali_->thermo_[19].high[2] = -2.3373836484e-06;
		asali_->thermo_[19].high[3] = 4.2943376632e-10;
		asali_->thermo_[19].high[4] = -2.9235247307e-14;
		asali_->thermo_[19].high[5] = 6.7383617188e+04;
		asali_->thermo_[19].high[6] = 9.7331523895e+00;

		asali_->thermo_[19].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[19].low[0] = 4.7115182877e+00;
		asali_->thermo_[19].low[1] = 9.0375245782e-04;
		asali_->thermo_[19].low[2] = 1.6546833876e-06;
		asali_->thermo_[19].low[3] = -1.0741696421e-09;
		asali_->thermo_[19].low[4] = 1.8313811839e-13;
		asali_->thermo_[19].low[5] = 6.6645718750e+04;
		asali_->thermo_[19].low[6] = -1.5133345127e+00;
		
		asali_->thermo_[20].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[20].name,"C2H2");

		asali_->thermo_[20].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[20].high[0] = 4.6119360924e+00;
		asali_->thermo_[20].high[1] = 5.0149820745e-03;
		asali_->thermo_[20].high[2] = -1.6525369801e-06;
		asali_->thermo_[20].high[3] = 2.4992252712e-10;
		asali_->thermo_[20].high[4] = -1.3056863804e-14;
		asali_->thermo_[20].high[5] = 2.5604384766e+04;
		asali_->thermo_[20].high[6] = -3.7551710606e+00;

		asali_->thermo_[20].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[20].low[0] = 1.8381215334e+00;
		asali_->thermo_[20].low[1] = 1.6453392804e-02;
		asali_->thermo_[20].low[2] = -1.9340801373e-05;
		asali_->thermo_[20].low[3] = 1.2406804473e-08;
		asali_->thermo_[20].low[4] = -3.1462738231e-12;
		asali_->thermo_[20].low[5] = 2.6142503906e+04;
		asali_->thermo_[20].low[6] = 9.5423927307e+00;
		
		asali_->thermo_[21].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[21].name,"C2H4");

		asali_->thermo_[21].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[21].high[0] = 4.4933366776e+00;
		asali_->thermo_[21].high[1] = 1.0033510625e-02;
		asali_->thermo_[21].high[2] = -3.6260139495e-06;
		asali_->thermo_[21].high[3] = 5.9761351423e-10;
		asali_->thermo_[21].high[4] = -3.6548126586e-14;
		asali_->thermo_[21].high[5] = 3.9322082520e+03;
		asali_->thermo_[21].high[6] = -3.3519201279e+00;

		asali_->thermo_[21].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[21].low[0] = 2.6616171002e-01;
		asali_->thermo_[21].low[1] = 1.9427232444e-02;
		asali_->thermo_[21].low[2] = -1.1454116247e-05;
		asali_->thermo_[21].low[3] = 3.4969105389e-09;
		asali_->thermo_[21].low[4] = -4.3922827072e-13;
		asali_->thermo_[21].low[5] = 5.4539912109e+03;
		asali_->thermo_[21].low[6] = 1.9526432037e+01;
		
		asali_->thermo_[22].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[22].name,"C2H5");

		asali_->thermo_[22].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[22].high[0] = -1.1048935652e+00;
		asali_->thermo_[22].high[1] = 2.4351190776e-02;
		asali_->thermo_[22].high[2] = -1.3961314835e-05;
		asali_->thermo_[22].high[3] = 3.8987031381e-09;
		asali_->thermo_[22].high[4] = -4.1728513006e-13;
		asali_->thermo_[22].high[5] = 1.3503075195e+04;
		asali_->thermo_[22].high[6] = 3.0014690399e+01;

		asali_->thermo_[22].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[22].low[0] = 4.9950184822e+00;
		asali_->thermo_[22].low[1] = -1.0505448096e-02;
		asali_->thermo_[22].low[2] = 6.0731483245e-05;
		asali_->thermo_[22].low[3] = -6.7237294843e-08;
		asali_->thermo_[22].low[4] = 2.4988427993e-11;
		asali_->thermo_[22].low[5] = 1.2649086914e+04;
		asali_->thermo_[22].low[6] = 2.7618277073e+00;
		
		asali_->thermo_[23].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[23].name,"C2H6");

		asali_->thermo_[23].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[23].high[0] = 4.3937349319e+00;
		asali_->thermo_[23].high[1] = 1.5268472955e-02;
		asali_->thermo_[23].high[2] = -5.8272503338e-06;
		asali_->thermo_[23].high[3] = 1.1037708525e-09;
		asali_->thermo_[23].high[4] = -8.6048654096e-14;
		asali_->thermo_[23].high[5] = -1.2726986328e+04;
		asali_->thermo_[23].high[6] = -3.2199749947e+00;

		asali_->thermo_[23].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[23].low[0] = -2.7446129918e-01;
		asali_->thermo_[23].low[1] = 2.5642242283e-02;
		asali_->thermo_[23].low[2] = -1.4472058865e-05;
		asali_->thermo_[23].low[3] = 4.3055514709e-09;
		asali_->thermo_[23].low[4] = -5.3074043641e-13;
		asali_->thermo_[23].low[5] = -1.1046435547e+04;
		asali_->thermo_[23].low[6] = 2.2045276642e+01;
		
		asali_->thermo_[24].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[24].name,"C3H2");

		asali_->thermo_[24].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[24].high[0] = 6.2766590118e+00;
		asali_->thermo_[24].high[1] = 5.5843312293e-03;
		asali_->thermo_[24].high[2] = -2.4585747269e-06;
		asali_->thermo_[24].high[3] = 5.4122301085e-10;
		asali_->thermo_[24].high[4] = -4.8360810799e-14;
		asali_->thermo_[24].high[5] = 6.3105519531e+04;
		asali_->thermo_[24].high[6] = -4.7511115074e+00;

		asali_->thermo_[24].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[24].low[0] = 4.2605533600e+00;
		asali_->thermo_[24].low[1] = 1.7104934901e-02;
		asali_->thermo_[24].low[2] = -2.7145581043e-05;
		asali_->thermo_[24].low[3] = 2.4052658532e-08;
		asali_->thermo_[24].low[4] = -8.4453017496e-12;
		asali_->thermo_[24].low[5] = 6.3387777344e+04;
		asali_->thermo_[24].low[6] = 4.2563381195e+00;
		
		asali_->thermo_[25].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[25].name,"C3H3");

		asali_->thermo_[25].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[25].high[0] = 1.0993046761e+01;
		asali_->thermo_[25].high[1] = 7.7971484279e-04;
		asali_->thermo_[25].high[2] = 1.7395738041e-06;
		asali_->thermo_[25].high[3] = -7.9586492951e-10;
		asali_->thermo_[25].high[4] = 9.6973217488e-14;
		asali_->thermo_[25].high[5] = 3.7462722656e+04;
		asali_->thermo_[25].high[6] = -3.4082275391e+01;

		asali_->thermo_[25].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[25].low[0] = 3.5603971481e+00;
		asali_->thermo_[25].low[1] = 1.8064947799e-02;
		asali_->thermo_[25].low[2] = -1.3334756659e-05;
		asali_->thermo_[25].low[3] = 5.0468988988e-09;
		asali_->thermo_[25].low[4] = -7.5226570849e-13;
		asali_->thermo_[25].low[5] = 4.0019554688e+04;
		asali_->thermo_[25].low[6] = 5.8068728447e+00;
		
		asali_->thermo_[26].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[26].name,"C3H6");

		asali_->thermo_[26].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[26].high[0] = 9.2154922485e+00;
		asali_->thermo_[26].high[1] = 1.1009614915e-02;
		asali_->thermo_[26].high[2] = -2.7216588023e-06;
		asali_->thermo_[26].high[3] = 1.6930111479e-10;
		asali_->thermo_[26].high[4] = 1.2505884119e-14;
		asali_->thermo_[26].high[5] = -2.1502854004e+03;
		asali_->thermo_[26].high[6] = -2.7577322006e+01;

		asali_->thermo_[26].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[26].low[0] = -2.6188677549e-01;
		asali_->thermo_[26].low[1] = 3.2070457935e-02;
		asali_->thermo_[26].low[2] = -2.0272360416e-05;
		asali_->thermo_[26].low[3] = 6.6695609036e-09;
		asali_->thermo_[26].low[4] = -8.9030795540e-13;
		asali_->thermo_[26].low[5] = 1.2615710449e+03;
		asali_->thermo_[26].low[6] = 2.3716228485e+01;
		
		asali_->thermo_[27].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[27].name,"C3H8");

		asali_->thermo_[27].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[27].high[0] = 1.0859636307e+01;
		asali_->thermo_[27].high[1] = 1.3576656580e-02;
		asali_->thermo_[27].high[2] = -3.1992624372e-06;
		asali_->thermo_[27].high[3] = 1.4161580242e-10;
		asali_->thermo_[27].high[4] = 2.3589855723e-14;
		asali_->thermo_[27].high[5] = -1.8088470703e+04;
		asali_->thermo_[27].high[6] = -3.6948692322e+01;

		asali_->thermo_[27].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[27].low[0] = -1.2551271915e+00;
		asali_->thermo_[27].low[1] = 4.0498353541e-02;
		asali_->thermo_[27].low[2] = -2.5634009944e-05;
		asali_->thermo_[27].low[3] = 8.4507814080e-09;
		asali_->thermo_[27].low[4] = -1.1304609592e-12;
		asali_->thermo_[27].low[5] = -1.3727155273e+04;
		asali_->thermo_[27].low[6] = 2.8618936539e+01;
		
		asali_->thermo_[28].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[28].name,"NC3H7O");

		asali_->thermo_[28].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[28].high[0] = 9.6622648239e+00;
		asali_->thermo_[28].high[1] = 1.8058300018e-02;
		asali_->thermo_[28].high[2] = -6.8075260060e-06;
		asali_->thermo_[28].high[3] = 1.2263421389e-09;
		asali_->thermo_[28].high[4] = -8.7955210064e-14;
		asali_->thermo_[28].high[5] = -9.7294277344e+03;
		asali_->thermo_[28].high[6] = -2.5536588669e+01;

		asali_->thermo_[28].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[28].low[0] = -5.5212140083e-01;
		asali_->thermo_[28].low[1] = 4.0756933391e-02;
		asali_->thermo_[28].low[2] = -2.5723054932e-05;
		asali_->thermo_[28].low[3] = 8.2320941175e-09;
		asali_->thermo_[28].low[4] = -1.0609762851e-12;
		asali_->thermo_[28].low[5] = -6.0522485352e+03;
		asali_->thermo_[28].low[6] = 2.9745798111e+01;
		
		asali_->thermo_[29].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[29].name,"C3H7OOH");

		asali_->thermo_[29].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[29].high[0] = 1.2027302742e+01;
		asali_->thermo_[29].high[1] = 2.2366933525e-02;
		asali_->thermo_[29].high[2] = -9.2551063062e-06;
		asali_->thermo_[29].high[3] = 1.8313465189e-09;
		asali_->thermo_[29].high[4] = -1.4351056964e-13;
		asali_->thermo_[29].high[5] = -2.8787808594e+04;
		asali_->thermo_[29].high[6] = -3.4369800568e+01;

		asali_->thermo_[29].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[29].low[0] = 1.1402956247e+00;
		asali_->thermo_[29].low[1] = 4.8443596810e-02;
		asali_->thermo_[29].low[2] = -3.2677256968e-05;
		asali_->thermo_[29].low[3] = 1.1181507276e-08;
		asali_->thermo_[29].low[4] = -1.5432352661e-12;
		asali_->thermo_[29].low[5] = -2.5151546875e+04;
		asali_->thermo_[29].low[6] = 2.3736827850e+01;
		
		asali_->thermo_[30].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[30].name,"C4H2");

		asali_->thermo_[30].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[30].high[0] = 8.5027580261e+00;
		asali_->thermo_[30].high[1] = 6.9744503126e-03;
		asali_->thermo_[30].high[2] = -2.5329711661e-06;
		asali_->thermo_[30].high[3] = 4.3328776678e-10;
		asali_->thermo_[30].high[4] = -2.9361146896e-14;
		asali_->thermo_[30].high[5] = 5.3172753906e+04;
		asali_->thermo_[30].high[6] = -2.0880794525e+01;

		asali_->thermo_[30].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[30].low[0] = 2.9090785980e+00;
		asali_->thermo_[30].low[1] = 2.8283704072e-02;
		asali_->thermo_[30].low[2] = -3.2974763599e-05;
		asali_->thermo_[30].low[3] = 1.9761410286e-08;
		asali_->thermo_[30].low[4] = -4.6312949135e-12;
		asali_->thermo_[30].low[5] = 5.4347429688e+04;
		asali_->thermo_[30].low[6] = 6.3783917427e+00;
		
		asali_->thermo_[31].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[31].name,"C4H3");

		asali_->thermo_[31].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[31].high[0] = 1.3020896912e+01;
		asali_->thermo_[31].high[1] = 1.5359036624e-03;
		asali_->thermo_[31].high[2] = 1.8056820181e-06;
		asali_->thermo_[31].high[3] = -9.3023722059e-10;
		asali_->thermo_[31].high[4] = 1.1807719245e-13;
		asali_->thermo_[31].high[5] = 6.0181175781e+04;
		asali_->thermo_[31].high[6] = -4.2579151154e+01;

		asali_->thermo_[31].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[31].low[0] = 2.3466267586e+00;
		asali_->thermo_[31].low[1] = 2.8389412910e-02;
		asali_->thermo_[31].low[2] = -2.3527818485e-05;
		asali_->thermo_[31].low[3] = 9.6917753822e-09;
		asali_->thermo_[31].low[4] = -1.5520505887e-12;
		asali_->thermo_[31].low[5] = 6.3575593750e+04;
		asali_->thermo_[31].low[6] = 1.3868056297e+01;
		
		asali_->thermo_[32].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[32].name,"C4H4");

		asali_->thermo_[32].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[32].high[0] = 6.3629360199e+00;
		asali_->thermo_[32].high[1] = 1.6660999507e-02;
		asali_->thermo_[32].high[2] = -7.5422085501e-06;
		asali_->thermo_[32].high[3] = 1.5952142940e-09;
		asali_->thermo_[32].high[4] = -1.2841583266e-13;
		asali_->thermo_[32].high[5] = 3.1313724609e+04;
		asali_->thermo_[32].high[6] = -8.1925525665e+00;

		asali_->thermo_[32].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[32].low[0] = 4.0318486094e-01;
		asali_->thermo_[32].low[1] = 3.6693777889e-02;
		asali_->thermo_[32].low[2] = -3.2793606806e-05;
		asali_->thermo_[32].low[3] = 1.5741656867e-08;
		asali_->thermo_[32].low[4] = -3.1003574274e-12;
		asali_->thermo_[32].low[5] = 3.2732144531e+04;
		asali_->thermo_[32].low[6] = 2.1596519470e+01;
		
		asali_->thermo_[33].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[33].name,"C4H5");

		asali_->thermo_[33].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[33].high[0] = 1.9019266129e+01;
		asali_->thermo_[33].high[1] = -1.9179438241e-03;
		asali_->thermo_[33].high[2] = 4.8881452130e-06;
		asali_->thermo_[33].high[3] = -1.9183394873e-09;
		asali_->thermo_[33].high[4] = 2.2413924286e-13;
		asali_->thermo_[33].high[5] = 3.4859273438e+04;
		asali_->thermo_[33].high[6] = -7.7042335510e+01;

		asali_->thermo_[33].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[33].low[0] = -2.0174230635e-01;
		asali_->thermo_[33].low[1] = 4.0795408189e-02;
		asali_->thermo_[33].low[2] = -3.0706312828e-05;
		asali_->thermo_[33].low[3] = 1.1264793542e-08;
		asali_->thermo_[33].low[4] = -1.6068514791e-12;
		asali_->thermo_[33].low[5] = 4.1778835938e+04;
		asali_->thermo_[33].low[6] = 2.6985767365e+01;
		
		asali_->thermo_[34].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[34].name,"CH2C3H5");

		asali_->thermo_[34].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[34].high[0] = 8.4591703415e+00;
		asali_->thermo_[34].high[1] = 1.9396854565e-02;
		asali_->thermo_[34].high[2] = -5.9907561081e-06;
		asali_->thermo_[34].high[3] = 3.8214797993e-10;
		asali_->thermo_[34].high[4] = 5.7399479050e-14;
		asali_->thermo_[34].high[5] = 1.9898832031e+04;
		asali_->thermo_[34].high[6] = -1.8021278381e+01;

		asali_->thermo_[34].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[34].low[0] = -3.2932904363e-01;
		asali_->thermo_[34].low[1] = 4.2373321950e-02;
		asali_->thermo_[34].low[2] = -2.8516704333e-05;
		asali_->thermo_[34].low[3] = 1.0197376277e-08;
		asali_->thermo_[34].low[4] = -1.5463960407e-12;
		asali_->thermo_[34].low[5] = 2.2588113281e+04;
		asali_->thermo_[34].low[6] = 2.8115613937e+01;
		
		asali_->thermo_[35].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[35].name,"SC4H7");

		asali_->thermo_[35].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[35].high[0] = 8.3301773071e+00;
		asali_->thermo_[35].high[1] = 1.9846649840e-02;
		asali_->thermo_[35].high[2] = -6.3761408455e-06;
		asali_->thermo_[35].high[3] = 5.2865278821e-10;
		asali_->thermo_[35].high[4] = 3.8110373825e-14;
		asali_->thermo_[35].high[5] = 1.1953384766e+04;
		asali_->thermo_[35].high[6] = -1.8376710892e+01;

		asali_->thermo_[35].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[35].low[0] = -1.1255012751e+00;
		asali_->thermo_[35].low[1] = 4.6482365578e-02;
		asali_->thermo_[35].low[2] = -3.4512460843e-05;
		asali_->thermo_[35].low[3] = 1.3738191917e-08;
		asali_->thermo_[35].low[4] = -2.2875126272e-12;
		asali_->thermo_[35].low[5] = 1.4638797852e+04;
		asali_->thermo_[35].low[6] = 3.0557170868e+01;
		
		asali_->thermo_[36].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[36].name,"C4H9OOH");

		asali_->thermo_[36].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[36].high[0] = 1.7396694183e+01;
		asali_->thermo_[36].high[1] = 2.3008869961e-02;
		asali_->thermo_[36].high[2] = -8.3464692580e-06;
		asali_->thermo_[36].high[3] = 1.3988319392e-09;
		asali_->thermo_[36].high[4] = -9.0167754990e-14;
		asali_->thermo_[36].high[5] = -3.3861402344e+04;
		asali_->thermo_[36].high[6] = -6.2362895966e+01;

		asali_->thermo_[36].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[36].low[0] = 1.1289511919e+00;
		asali_->thermo_[36].low[1] = 5.9565596282e-02;
		asali_->thermo_[36].low[2] = -3.9152699173e-05;
		asali_->thermo_[36].low[3] = 1.2936745897e-08;
		asali_->thermo_[36].low[4] = -1.7106613435e-12;
		asali_->thermo_[36].low[5] = -2.8070087891e+04;
		asali_->thermo_[36].low[6] = 2.5499763489e+01;
		
		asali_->thermo_[37].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[37].name,"CYC5H4O");

		asali_->thermo_[37].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[37].high[0] = 6.3445959091e+00;
		asali_->thermo_[37].high[1] = 2.3984158412e-02;
		asali_->thermo_[37].high[2] = -8.3275535872e-06;
		asali_->thermo_[37].high[3] = 8.4712764581e-10;
		asali_->thermo_[37].high[4] = 2.8624949904e-14;
		asali_->thermo_[37].high[5] = 3.0865930176e+03;
		asali_->thermo_[37].high[6] = -9.7318153381e+00;

		asali_->thermo_[37].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[37].low[0] = -5.1437935829e+00;
		asali_->thermo_[37].low[1] = 6.0455232859e-02;
		asali_->thermo_[37].low[2] = -5.1745500969e-05;
		asali_->thermo_[37].low[3] = 2.3819588080e-08;
		asali_->thermo_[37].low[4] = -4.5294028944e-12;
		asali_->thermo_[37].low[5] = 5.9816669922e+03;
		asali_->thermo_[37].low[6] = 4.8348121643e+01;
		
		asali_->thermo_[38].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[38].name,"C5H7");

		asali_->thermo_[38].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[38].high[0] = 7.7240452766e+00;
		asali_->thermo_[38].high[1] = 2.5607218966e-02;
		asali_->thermo_[38].high[2] = -8.7635035015e-06;
		asali_->thermo_[38].high[3] = 8.6619394990e-10;
		asali_->thermo_[38].high[4] = 3.3041664294e-14;
		asali_->thermo_[38].high[5] = 2.3080814453e+04;
		asali_->thermo_[38].high[6] = -1.6935293198e+01;

		asali_->thermo_[38].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[38].low[0] = 2.3176504672e-01;
		asali_->thermo_[38].low[1] = 4.6564646065e-02;
		asali_->thermo_[38].low[2] = -3.0746818084e-05;
		asali_->thermo_[38].low[3] = 1.1114825504e-08;
		asali_->thermo_[38].low[4] = -1.7586771883e-12;
		asali_->thermo_[38].low[5] = 2.5223605469e+04;
		asali_->thermo_[38].low[6] = 2.1890424728e+01;
		
		asali_->thermo_[39].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[39].name,"NC5H11OOH");

		asali_->thermo_[39].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[39].high[0] = 1.6698818207e+01;
		asali_->thermo_[39].high[1] = 3.4417271614e-02;
		asali_->thermo_[39].high[2] = -1.4313975953e-05;
		asali_->thermo_[39].high[3] = 2.8530084961e-09;
		asali_->thermo_[39].high[4] = -2.2535087945e-13;
		asali_->thermo_[39].high[5] = -3.7375578125e+04;
		asali_->thermo_[39].high[6] = -5.7577529907e+01;

		asali_->thermo_[39].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[39].low[0] = 6.2428936362e-02;
		asali_->thermo_[39].low[1] = 7.5242765248e-02;
		asali_->thermo_[39].low[2] = -5.1883449487e-05;
		asali_->thermo_[39].low[3] = 1.8218846876e-08;
		asali_->thermo_[39].low[4] = -2.5820745281e-12;
		asali_->thermo_[39].low[5] = -3.1952113281e+04;
		asali_->thermo_[39].low[6] = 3.0811639786e+01;
		
		asali_->thermo_[40].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[40].name,"C6H5");

		asali_->thermo_[40].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[40].high[0] = 2.3749488831e+01;
		asali_->thermo_[40].high[1] = -3.7482627667e-03;
		asali_->thermo_[40].high[2] = 7.2282900874e-06;
		asali_->thermo_[40].high[3] = -2.6992770241e-09;
		asali_->thermo_[40].high[4] = 3.1003267987e-13;
		asali_->thermo_[40].high[5] = 2.9357171875e+04;
		asali_->thermo_[40].high[6] = -1.0701034546e+02;

		asali_->thermo_[40].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[40].low[0] = -4.3097209930e+00;
		asali_->thermo_[40].low[1] = 6.2664069235e-02;
		asali_->thermo_[40].low[2] = -5.1717564929e-05;
		asali_->thermo_[40].low[3] = 2.0553526880e-08;
		asali_->thermo_[40].low[4] = -3.1297310663e-12;
		asali_->thermo_[40].low[5] = 3.8841183594e+04;
		asali_->thermo_[40].low[6] = 4.3082592010e+01;
		
		asali_->thermo_[41].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[41].name,"C6H5O");

		asali_->thermo_[41].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[41].high[0] = 1.3442816734e+01;
		asali_->thermo_[41].high[1] = 1.7965873703e-02;
		asali_->thermo_[41].high[2] = -6.6733277890e-06;
		asali_->thermo_[41].high[3] = 1.1223751928e-09;
		asali_->thermo_[41].high[4] = -7.1080951726e-14;
		asali_->thermo_[41].high[5] = 4.0768380737e+02;
		asali_->thermo_[41].high[6] = -4.7250053406e+01;

		asali_->thermo_[41].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[41].low[0] = -4.8070707321e+00;
		asali_->thermo_[41].low[1] = 7.3268562555e-02;
		asali_->thermo_[41].low[2] = -6.9517293014e-05;
		asali_->thermo_[41].low[3] = 3.2861752430e-08;
		asali_->thermo_[41].low[4] = -6.0823264827e-12;
		asali_->thermo_[41].low[5] = 5.2256542969e+03;
		asali_->thermo_[41].low[6] = 4.5861854553e+01;
		
		asali_->thermo_[42].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[42].name,"LC6H6");

		asali_->thermo_[42].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[42].high[0] = 1.2886387825e+01;
		asali_->thermo_[42].high[1] = 1.9007246941e-02;
		asali_->thermo_[42].high[2] = -7.3099254223e-06;
		asali_->thermo_[42].high[3] = 1.3148249156e-09;
		asali_->thermo_[42].high[4] = -9.2138577041e-14;
		asali_->thermo_[42].high[5] = 3.5536484375e+04;
		asali_->thermo_[42].high[6] = -4.0902194977e+01;

		asali_->thermo_[42].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[42].low[0] = -1.0588937998e+00;
		asali_->thermo_[42].low[1] = 6.3632145524e-02;
		asali_->thermo_[42].low[2] = -6.0859805671e-05;
		asali_->thermo_[42].low[3] = 2.9874762220e-08;
		asali_->thermo_[42].low[4] = -5.8041258431e-12;
		asali_->thermo_[42].low[5] = 3.9022804688e+04;
		asali_->thermo_[42].low[6] = 2.9487527847e+01;
		
		asali_->thermo_[43].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[43].name,"CYC6H10-ONE");

		asali_->thermo_[43].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[43].high[0] = 1.1596542358e+01;
		asali_->thermo_[43].high[1] = 4.0288794786e-02;
		asali_->thermo_[43].high[2] = -1.8668584744e-05;
		asali_->thermo_[43].high[3] = 4.1556842412e-09;
		asali_->thermo_[43].high[4] = -3.6403071855e-13;
		asali_->thermo_[43].high[5] = -3.6222148438e+04;
		asali_->thermo_[43].high[6] = -4.2746845245e+01;

		asali_->thermo_[43].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[43].low[0] = -6.4649038315e+00;
		asali_->thermo_[43].low[1] = 8.0425344408e-02;
		asali_->thermo_[43].low[2] = -5.2115708968e-05;
		asali_->thermo_[43].low[3] = 1.6543507897e-08;
		asali_->thermo_[43].low[4] = -2.0845616899e-12;
		asali_->thermo_[43].low[5] = -2.9720029297e+04;
		asali_->thermo_[43].low[6] = 5.5005474091e+01;
		
		asali_->thermo_[44].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[44].name,"C7H7");

		asali_->thermo_[44].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[44].high[0] = 1.5556403160e+01;
		asali_->thermo_[44].high[1] = 1.9746797159e-02;
		asali_->thermo_[44].high[2] = -4.9010250223e-06;
		asali_->thermo_[44].high[3] = -1.0674605297e-11;
		asali_->thermo_[44].high[4] = 9.1651302704e-14;
		asali_->thermo_[44].high[5] = 1.6709873047e+04;
		asali_->thermo_[44].high[6] = -6.1508666992e+01;

		asali_->thermo_[44].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[44].low[0] = -4.4017233849e+00;
		asali_->thermo_[44].low[1] = 7.4803695083e-02;
		asali_->thermo_[44].low[2] = -6.1856437242e-05;
		asali_->thermo_[44].low[3] = 2.6175722923e-08;
		asali_->thermo_[44].low[4] = -4.4232447566e-12;
		asali_->thermo_[44].low[5] = 2.2497728516e+04;
		asali_->thermo_[44].low[6] = 4.2193466187e+01;
		
		asali_->thermo_[45].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[45].name,"NC7H15OOH");

		asali_->thermo_[45].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[45].high[0] = 2.7321958542e+01;
		asali_->thermo_[45].high[1] = 3.5587098449e-02;
		asali_->thermo_[45].high[2] = -1.2465077816e-05;
		asali_->thermo_[45].high[3] = 2.0008925627e-09;
		asali_->thermo_[45].high[4] = -1.2199768105e-13;
		asali_->thermo_[45].high[5] = -4.8463417969e+04;
		asali_->thermo_[45].high[6] = -1.1226205444e+02;

		asali_->thermo_[45].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[45].low[0] = 1.1621515751e+00;
		asali_->thermo_[45].low[1] = 9.4044767320e-02;
		asali_->thermo_[45].low[2] = -6.1451952206e-05;
		asali_->thermo_[45].low[3] = 2.0245538579e-08;
		asali_->thermo_[45].low[4] = -2.6701325612e-12;
		asali_->thermo_[45].low[5] = -3.9098207031e+04;
		asali_->thermo_[45].low[6] = 2.9174539566e+01;
		
		asali_->thermo_[46].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[46].name,"CYC5H8");

		asali_->thermo_[46].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[46].high[0] = 8.4309988022e+00;
		asali_->thermo_[46].high[1] = 2.7108270675e-02;
		asali_->thermo_[46].high[2] = -1.0793286492e-05;
		asali_->thermo_[46].high[3] = 1.9538766161e-09;
		asali_->thermo_[46].high[4] = -1.3111117281e-13;
		asali_->thermo_[46].high[5] = -1.0986253662e+03;
		asali_->thermo_[46].high[6] = -2.3760845184e+01;

		asali_->thermo_[46].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[46].low[0] = -6.5686397552e+00;
		asali_->thermo_[46].low[1] = 6.8203173578e-02;
		asali_->thermo_[46].low[2] = -5.3014075093e-05;
		asali_->thermo_[46].low[3] = 2.1232775538e-08;
		asali_->thermo_[46].low[4] = -3.4322924277e-12;
		asali_->thermo_[46].low[5] = 3.2812692871e+03;
		asali_->thermo_[46].low[6] = 5.4280151367e+01;
		
		asali_->thermo_[47].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[47].name,"CYC6H8");

		asali_->thermo_[47].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[47].high[0] = 8.6677227020e+00;
		asali_->thermo_[47].high[1] = 3.4507486969e-02;
		asali_->thermo_[47].high[2] = -1.6384678020e-05;
		asali_->thermo_[47].high[3] = 3.6926097735e-09;
		asali_->thermo_[47].high[4] = -3.2442101848e-13;
		asali_->thermo_[47].high[5] = 5.7402211914e+03;
		asali_->thermo_[47].high[6] = -2.7356620789e+01;

		asali_->thermo_[47].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[47].low[0] = -6.9135813713e+00;
		asali_->thermo_[47].low[1] = 7.6336488128e-02;
		asali_->thermo_[47].low[2] = -5.8494413679e-05;
		asali_->thermo_[47].low[3] = 2.2533654942e-08;
		asali_->thermo_[47].low[4] = -3.4856700859e-12;
		asali_->thermo_[47].low[5] = 1.0383450195e+04;
		asali_->thermo_[47].low[6] = 5.4027614594e+01;
		
		asali_->thermo_[48].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[48].name,"CYC6H12");

		asali_->thermo_[48].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[48].high[0] = 1.1257809639e+01;
		asali_->thermo_[48].high[1] = 4.3435409665e-02;
		asali_->thermo_[48].high[2] = -2.0245577616e-05;
		asali_->thermo_[48].high[3] = 4.5424530803e-09;
		asali_->thermo_[48].high[4] = -4.0119516325e-13;
		asali_->thermo_[48].high[5] = -2.3043996094e+04;
		asali_->thermo_[48].high[6] = -4.4786338806e+01;

		asali_->thermo_[48].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[48].low[0] = -9.4336309433e+00;
		asali_->thermo_[48].low[1] = 8.9416392148e-02;
		asali_->thermo_[48].low[2] = -5.8563062339e-05;
		asali_->thermo_[48].low[3] = 1.8734112928e-08;
		asali_->thermo_[48].low[4] = -2.3722590732e-12;
		asali_->thermo_[48].low[5] = -1.5595077148e+04;
		asali_->thermo_[48].low[6] = 6.7200057983e+01;
		
		asali_->thermo_[49].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[49].name,"CYC6H10");

		asali_->thermo_[49].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[49].high[0] = 1.5162486076e+01;
		asali_->thermo_[49].high[1] = 2.7636000887e-02;
		asali_->thermo_[49].high[2] = -1.0525985999e-05;
		asali_->thermo_[49].high[3] = 1.8958636883e-09;
		asali_->thermo_[49].high[4] = -1.3505476848e-13;
		asali_->thermo_[49].high[5] = -9.2998525391e+03;
		asali_->thermo_[49].high[6] = -6.2506454468e+01;

		asali_->thermo_[49].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[49].low[0] = -6.0151767731e+00;
		asali_->thermo_[49].low[1] = 7.4697472155e-02;
		asali_->thermo_[49].low[2] = -4.9743877753e-05;
		asali_->thermo_[49].low[3] = 1.6421008553e-08;
		asali_->thermo_[49].low[4] = -2.1524362154e-12;
		asali_->thermo_[49].low[5] = -1.6758940430e+03;
		asali_->thermo_[49].low[6] = 5.2111469269e+01;
		
		asali_->thermo_[50].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->thermo_[50].name,"CH");

		asali_->thermo_[50].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[50].high[0] = 1.5676234961e+00;
		asali_->thermo_[50].high[1] = 3.3544120379e-03;
		asali_->thermo_[50].high[2] = -1.2997159047e-06;
		asali_->thermo_[50].high[3] = 2.4050089698e-10;
		asali_->thermo_[50].high[4] = -1.7814115932e-14;
		asali_->thermo_[50].high[5] = 7.1168671875e+04;
		asali_->thermo_[50].high[6] = 1.2771240234e+01;

		asali_->thermo_[50].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[50].low[0] = 3.8590126038e+00;
		asali_->thermo_[50].low[1] = -1.9743999001e-03;
		asali_->thermo_[50].low[2] = 3.3475039345e-06;
		asali_->thermo_[50].low[3] = -1.5607470871e-09;
		asali_->thermo_[50].low[4] = 2.4399517237e-13;
		asali_->thermo_[50].low[5] = 7.0380437500e+04;
		asali_->thermo_[50].low[6] = 4.7393620014e-01;
		
		asali_->thermo_[51].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[51].name,"CH2");

		asali_->thermo_[51].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[51].high[0] = 3.2450587749e+00;
		asali_->thermo_[51].high[1] = 2.7539506555e-03;
		asali_->thermo_[51].high[2] = -7.6847135233e-07;
		asali_->thermo_[51].high[3] = 8.2304003890e-11;
		asali_->thermo_[51].high[4] = -1.8990025515e-15;
		asali_->thermo_[51].high[5] = 4.5479457031e+04;
		asali_->thermo_[51].high[6] = 4.2818698883e+00;

		asali_->thermo_[51].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[51].low[0] = 3.9971792698e+00;
		asali_->thermo_[51].low[1] = -5.8880681172e-04;
		asali_->thermo_[51].low[2] = 4.8027914090e-06;
		asali_->thermo_[51].low[3] = -4.0445571337e-09;
		asali_->thermo_[51].low[4] = 1.1444512872e-12;
		asali_->thermo_[51].low[5] = 4.5344078125e+04;
		asali_->thermo_[51].low[6] = 7.3256742954e-01;
		
		asali_->thermo_[52].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[52].name,"CH2CO");

		asali_->thermo_[52].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[52].high[0] = 6.0357880592e+00;
		asali_->thermo_[52].high[1] = 5.8172242716e-03;
		asali_->thermo_[52].high[2] = -1.9320650608e-06;
		asali_->thermo_[52].high[3] = 2.8314006695e-10;
		asali_->thermo_[52].high[4] = -1.5005161556e-14;
		asali_->thermo_[52].high[5] = -8.5842236328e+03;
		asali_->thermo_[52].high[6] = -7.6450505257e+00;

		asali_->thermo_[52].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[52].low[0] = 2.4919705391e+00;
		asali_->thermo_[52].low[1] = 1.5870606527e-02;
		asali_->thermo_[52].low[2] = -1.2627152500e-05;
		asali_->thermo_[52].low[3] = 5.3399191735e-09;
		asali_->thermo_[52].low[4] = -9.1159718663e-13;
		asali_->thermo_[52].low[5] = -7.5848671875e+03;
		asali_->thermo_[52].low[6] = 1.0669438362e+01;
		
		asali_->thermo_[53].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[53].name,"CH2O");

		asali_->thermo_[53].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[53].high[0] = 1.0663925409e+00;
		asali_->thermo_[53].high[1] = 1.0696033947e-02;
		asali_->thermo_[53].high[2] = -5.5444738791e-06;
		asali_->thermo_[53].high[3] = 1.3605369054e-09;
		asali_->thermo_[53].high[4] = -1.2844255824e-13;
		asali_->thermo_[53].high[5] = -1.4632437500e+04;
		asali_->thermo_[53].high[6] = 1.7407176971e+01;

		asali_->thermo_[53].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[53].low[0] = 3.1346333027e+00;
		asali_->thermo_[53].low[1] = 1.8003748264e-03;
		asali_->thermo_[53].low[2] = 8.8033630163e-06;
		asali_->thermo_[53].low[3] = -8.9246503521e-09;
		asali_->thermo_[53].low[4] = 2.6363928401e-12;
		asali_->thermo_[53].low[5] = -1.5017129883e+04;
		asali_->thermo_[53].low[6] = 7.5792059898e+00;
		
		asali_->thermo_[54].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[54].name,"CH2OH");

		asali_->thermo_[54].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[54].high[0] = 7.6100416183e+00;
		asali_->thermo_[54].high[1] = 1.4023901895e-03;
		asali_->thermo_[54].high[2] = 1.0526541701e-06;
		asali_->thermo_[54].high[3] = -5.6197230203e-10;
		asali_->thermo_[54].high[4] = 7.1120904576e-14;
		asali_->thermo_[54].high[5] = -5.0498564453e+03;
		asali_->thermo_[54].high[6] = -1.5575758934e+01;

		asali_->thermo_[54].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[54].low[0] = 1.9585713148e+00;
		asali_->thermo_[54].low[1] = 1.5619925223e-02;
		asali_->thermo_[54].low[2] = -1.2360114852e-05;
		asali_->thermo_[54].low[3] = 5.0618300662e-09;
		asali_->thermo_[54].low[4] = -8.1312479536e-13;
		asali_->thermo_[54].low[5] = -3.2526887207e+03;
		asali_->thermo_[54].low[6] = 1.4310097694e+01;
		
		asali_->thermo_[55].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[55].name,"CH2S");

		asali_->thermo_[55].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[55].high[0] = 2.5751826763e+00;
		asali_->thermo_[55].high[1] = 4.1117966175e-03;
		asali_->thermo_[55].high[2] = -1.6823242959e-06;
		asali_->thermo_[55].high[3] = 3.4440494900e-10;
		asali_->thermo_[55].high[4] = -2.9308596972e-14;
		asali_->thermo_[55].high[5] = 5.0195851562e+04;
		asali_->thermo_[55].high[6] = 6.9991450310e+00;

		asali_->thermo_[55].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[55].low[0] = 4.6257266998e+00;
		asali_->thermo_[55].low[1] = -5.0017312169e-03;
		asali_->thermo_[55].low[2] = 1.3506889445e-05;
		asali_->thermo_[55].low[3] = -1.0906863857e-08;
		asali_->thermo_[55].low[4] = 3.0960440375e-12;
		asali_->thermo_[55].low[5] = 4.9826753906e+04;
		asali_->thermo_[55].low[6] = -2.6774971485e+00;
		
		asali_->thermo_[56].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[56].name,"CH3");

		asali_->thermo_[56].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[56].high[0] = 2.5772397518e+00;
		asali_->thermo_[56].high[1] = 6.6260118037e-03;
		asali_->thermo_[56].high[2] = -2.5490639928e-06;
		asali_->thermo_[56].high[3] = 4.6732012704e-10;
		asali_->thermo_[56].high[4] = -3.3486766555e-14;
		asali_->thermo_[56].high[5] = 1.6548869141e+04;
		asali_->thermo_[56].high[6] = 6.9419598579e+00;

		asali_->thermo_[56].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[56].low[0] = 3.5332739353e+00;
		asali_->thermo_[56].low[1] = 3.6148801446e-03;
		asali_->thermo_[56].low[2] = 1.0073906651e-06;
		asali_->thermo_[56].low[3] = -1.3995851145e-09;
		asali_->thermo_[56].low[4] = 3.3401428325e-13;
		asali_->thermo_[56].low[5] = 1.6306036133e+04;
		asali_->thermo_[56].low[6] = 2.1011385918e+00;
		
		asali_->thermo_[57].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[57].name,"CH3CO");

		asali_->thermo_[57].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[57].high[0] = 5.5944900513e+00;
		asali_->thermo_[57].high[1] = 8.9506367221e-03;
		asali_->thermo_[57].high[2] = -3.4270656215e-06;
		asali_->thermo_[57].high[3] = 6.3955440943e-10;
		asali_->thermo_[57].high[4] = -4.9168097572e-14;
		asali_->thermo_[57].high[5] = -5.3193120117e+03;
		asali_->thermo_[57].high[6] = -3.4646615982e+00;

		asali_->thermo_[57].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[57].low[0] = 1.8318916559e+00;
		asali_->thermo_[57].low[1] = 1.7311966047e-02;
		asali_->thermo_[57].low[2] = -1.0394840501e-05;
		asali_->thermo_[57].low[3] = 3.2202116529e-09;
		asali_->thermo_[57].low[4] = -4.0759271500e-13;
		asali_->thermo_[57].low[5] = -3.9647768555e+03;
		asali_->thermo_[57].low[6] = 1.6899305344e+01;
		
		asali_->thermo_[58].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[58].name,"CH3O");

		asali_->thermo_[58].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[58].high[0] = 6.8842059374e-01;
		asali_->thermo_[58].high[1] = 1.4497130178e-02;
		asali_->thermo_[58].high[2] = -7.5906805250e-06;
		asali_->thermo_[58].high[3] = 1.9252239802e-09;
		asali_->thermo_[58].high[4] = -1.9001111990e-13;
		asali_->thermo_[58].high[5] = 1.1833040771e+03;
		asali_->thermo_[58].high[6] = 1.9583827972e+01;

		asali_->thermo_[58].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[58].low[0] = 2.1396253109e+00;
		asali_->thermo_[58].low[1] = 6.2045315281e-03;
		asali_->thermo_[58].low[2] = 1.0179173842e-05;
		asali_->thermo_[58].low[3] = -1.4998446929e-08;
		asali_->thermo_[58].low[4] = 5.8541570029e-12;
		asali_->thermo_[58].low[5] = 9.8013537598e+02;
		asali_->thermo_[58].low[6] = 1.3100212097e+01;
		
		asali_->thermo_[59].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[59].name,"CH3OH");

		asali_->thermo_[59].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[59].high[0] = 9.3419301510e-01;
		asali_->thermo_[59].high[1] = 1.6026655212e-02;
		asali_->thermo_[59].high[2] = -8.0010149759e-06;
		asali_->thermo_[59].high[3] = 1.9712971255e-09;
		asali_->thermo_[59].high[4] = -1.9159948964e-13;
		asali_->thermo_[59].high[5] = -2.5097978516e+04;
		asali_->thermo_[59].high[6] = 1.9100845337e+01;

		asali_->thermo_[59].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[59].low[0] = 2.8889577389e+00;
		asali_->thermo_[59].low[1] = 4.8565706238e-03;
		asali_->thermo_[59].low[2] = 1.5934881958e-05;
		asali_->thermo_[59].low[3] = -2.0824794333e-08;
		asali_->thermo_[59].low[4] = 7.9498621228e-12;
		asali_->thermo_[59].low[5] = -2.5371646484e+04;
		asali_->thermo_[59].low[6] = 1.0367450714e+01;
		
		asali_->thermo_[60].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[60].name,"CH4");

		asali_->thermo_[60].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[60].high[0] = -2.8232142329e-01;
		asali_->thermo_[60].high[1] = 1.4273933135e-02;
		asali_->thermo_[60].high[2] = -6.7762889557e-06;
		asali_->thermo_[60].high[3] = 1.5538095255e-09;
		asali_->thermo_[60].high[4] = -1.3947384101e-13;
		asali_->thermo_[60].high[5] = -9.3638359375e+03;
		asali_->thermo_[60].high[6] = 2.0350702286e+01;

		asali_->thermo_[60].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[60].low[0] = 2.8576531410e+00;
		asali_->thermo_[60].low[1] = 2.5357110426e-03;
		asali_->thermo_[60].low[2] = 9.6791636679e-06;
		asali_->thermo_[60].low[3] = -8.6988087844e-09;
		asali_->thermo_[60].low[4] = 2.2559976890e-12;
		asali_->thermo_[60].low[5] = -1.0035790039e+04;
		asali_->thermo_[60].low[6] = 4.9896941185e+00;
		
		asali_->thermo_[61].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->thermo_[61].name,"CO");

		asali_->thermo_[61].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[61].high[0] = 2.6859500408e+00;
		asali_->thermo_[61].high[1] = 2.1248636767e-03;
		asali_->thermo_[61].high[2] = -1.0454861012e-06;
		asali_->thermo_[61].high[3] = 2.4553886702e-10;
		asali_->thermo_[61].high[4] = -2.2255097816e-14;
		asali_->thermo_[61].high[5] = -1.4142361328e+04;
		asali_->thermo_[61].high[6] = 7.9657940865e+00;

		asali_->thermo_[61].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[61].low[0] = 3.8189094067e+00;
		asali_->thermo_[61].low[1] = -2.4069733918e-03;
		asali_->thermo_[61].low[2] = 5.7522697716e-06;
		asali_->thermo_[61].low[3] = -4.2862984273e-09;
		asali_->thermo_[61].low[4] = 1.1107041935e-12;
		asali_->thermo_[61].low[5] = -1.4368953125e+04;
		asali_->thermo_[61].low[6] = 2.4999206066e+00;
		
		asali_->thermo_[62].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[62].name,"CO2");

		asali_->thermo_[62].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[62].high[0] = 5.0783100128e+00;
		asali_->thermo_[62].high[1] = 2.0536603406e-03;
		asali_->thermo_[62].high[2] = -5.9431124555e-07;
		asali_->thermo_[62].high[3] = 5.3867514616e-11;
		asali_->thermo_[62].high[4] = 1.6634685234e-15;
		asali_->thermo_[62].high[5] = -4.9244210938e+04;
		asali_->thermo_[62].high[6] = -4.4781527519e+00;

		asali_->thermo_[62].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[62].low[0] = 2.4489278793e+00;
		asali_->thermo_[62].low[1] = 8.5459612310e-03;
		asali_->thermo_[62].low[2] = -6.6057009462e-06;
		asali_->thermo_[62].low[3] = 2.5276905014e-09;
		asali_->thermo_[62].low[4] = -3.8009932658e-13;
		asali_->thermo_[62].low[5] = -4.8392289062e+04;
		asali_->thermo_[62].low[6] = 9.4755773544e+00;
		
		asali_->thermo_[63].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[63].name,"CYC5H6");

		asali_->thermo_[63].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[63].high[0] = 1.7014155388e+00;
		asali_->thermo_[63].high[1] = 3.7906594574e-02;
		asali_->thermo_[63].high[2] = -2.1949525035e-05;
		asali_->thermo_[63].high[3] = 6.1270650775e-09;
		asali_->thermo_[63].high[4] = -6.6367251321e-13;
		asali_->thermo_[63].high[5] = 1.3848440430e+04;
		asali_->thermo_[63].high[6] = 1.2245345116e+01;

		asali_->thermo_[63].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[63].low[0] = -6.3292288780e+00;
		asali_->thermo_[63].low[1] = 6.9399319589e-02;
		asali_->thermo_[63].low[2] = -6.8262350396e-05;
		asali_->thermo_[63].low[3] = 3.6396887282e-08;
		asali_->thermo_[63].low[4] = -8.0827462778e-12;
		asali_->thermo_[63].low[5] = 1.5486691406e+04;
		asali_->thermo_[63].low[6] = 5.1147590637e+01;
		
		asali_->thermo_[64].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[64].name,"MCPTD");

		asali_->thermo_[64].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[64].high[0] = 1.1415410042e+01;
		asali_->thermo_[64].high[1] = 2.7083026245e-02;
		asali_->thermo_[64].high[2] = -1.1341949175e-05;
		asali_->thermo_[64].high[3] = 2.3015782613e-09;
		asali_->thermo_[64].high[4] = -1.8605666866e-13;
		asali_->thermo_[64].high[5] = 6.2304077148e+03;
		asali_->thermo_[64].high[6] = -4.1034748077e+01;

		asali_->thermo_[64].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[64].low[0] = -6.5221977234e+00;
		asali_->thermo_[64].low[1] = 7.3674216866e-02;
		asali_->thermo_[64].low[2] = -5.6722976296e-05;
		asali_->thermo_[64].low[3] = 2.1947045070e-08;
		asali_->thermo_[64].low[4] = -3.3752558040e-12;
		asali_->thermo_[64].low[5] = 1.1755190430e+04;
		asali_->thermo_[64].low[6] = 5.3248985291e+01;
		
		asali_->thermo_[65].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[65].name,"CRESOL");

		asali_->thermo_[65].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[65].high[0] = 1.2267368317e+01;
		asali_->thermo_[65].high[1] = 3.3415529877e-02;
		asali_->thermo_[65].high[2] = -1.3894987205e-05;
		asali_->thermo_[65].high[3] = 2.5676816229e-09;
		asali_->thermo_[65].high[4] = -1.7151956396e-13;
		asali_->thermo_[65].high[5] = -2.1718724609e+04;
		asali_->thermo_[65].high[6] = -3.9571514130e+01;

		asali_->thermo_[65].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[65].low[0] = -4.4184393883e+00;
		asali_->thermo_[65].low[1] = 8.4364563227e-02;
		asali_->thermo_[65].low[2] = -7.2233575338e-05;
		asali_->thermo_[65].low[3] = 3.2256529892e-08;
		asali_->thermo_[65].low[4] = -5.8373301852e-12;
		asali_->thermo_[65].low[5] = -1.7347042969e+04;
		asali_->thermo_[65].low[6] = 4.5433486938e+01;
		
		asali_->thermo_[66].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[66].name,"NC10H20");

		asali_->thermo_[66].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[66].high[0] = 2.8297178268e+01;
		asali_->thermo_[66].high[1] = 4.8947893083e-02;
		asali_->thermo_[66].high[2] = -1.8273705791e-05;
		asali_->thermo_[66].high[3] = 3.2357521107e-09;
		asali_->thermo_[66].high[4] = -2.2681184188e-13;
		asali_->thermo_[66].high[5] = -3.1253458984e+04;
		asali_->thermo_[66].high[6] = -1.1678405762e+02;

		asali_->thermo_[66].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[66].low[0] = -2.3141770363e+00;
		asali_->thermo_[66].low[1] = 1.1697313190e-01;
		asali_->thermo_[66].low[2] = -7.4961404607e-05;
		asali_->thermo_[66].low[3] = 2.4231194828e-08;
		asali_->thermo_[66].low[4] = -3.1428455758e-12;
		asali_->thermo_[66].low[5] = -2.0233369141e+04;
		asali_->thermo_[66].low[6] = 4.8890987396e+01;
		
		asali_->thermo_[67].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[67].name,"C6H5CH2C6H5");

		asali_->thermo_[67].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[67].high[0] = 2.3660026550e+01;
		asali_->thermo_[67].high[1] = 4.2096108198e-02;
		asali_->thermo_[67].high[2] = -1.1875675227e-05;
		asali_->thermo_[67].high[3] = 4.0236997068e-10;
		asali_->thermo_[67].high[4] = 1.6853144856e-13;
		asali_->thermo_[67].high[5] = 4.5089775391e+03;
		asali_->thermo_[67].high[6] = -9.7668807983e+01;

		asali_->thermo_[67].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[67].low[0] = -1.1861348152e+01;
		asali_->thermo_[67].low[1] = 1.4076659083e-01;
		asali_->thermo_[67].low[2] = -1.1465742864e-04;
		asali_->thermo_[67].low[3] = 4.7986514318e-08;
		asali_->thermo_[67].low[4] = -8.0926047114e-12;
		asali_->thermo_[67].low[5] = 1.4739132812e+04;
		asali_->thermo_[67].low[6] = 8.6653915405e+01;
		
		asali_->thermo_[68].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[68].name,"DIPE");

		asali_->thermo_[68].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[68].high[0] = 1.1157392502e+01;
		asali_->thermo_[68].high[1] = 4.9917567521e-02;
		asali_->thermo_[68].high[2] = -2.2556137992e-05;
		asali_->thermo_[68].high[3] = 4.3844483599e-09;
		asali_->thermo_[68].high[4] = -3.0654935513e-13;
		asali_->thermo_[68].high[5] = -4.5935792969e+04;
		asali_->thermo_[68].high[6] = -3.0611776352e+01;

		asali_->thermo_[68].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[68].low[0] = -2.5074527264e+00;
		asali_->thermo_[68].low[1] = 8.9525811374e-02;
		asali_->thermo_[68].low[2] = -6.5608583100e-05;
		asali_->thermo_[68].low[3] = 2.5182730568e-08;
		asali_->thermo_[68].low[4] = -4.0743541353e-12;
		asali_->thermo_[68].low[5] = -4.2164296875e+04;
		asali_->thermo_[68].low[6] = 3.9714424133e+01;
		
		asali_->thermo_[69].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[69].name,"MTBE-O");

		asali_->thermo_[69].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[69].high[0] = 1.5138875961e+01;
		asali_->thermo_[69].high[1] = 2.9997937381e-02;
		asali_->thermo_[69].high[2] = -1.2279921975e-05;
		asali_->thermo_[69].high[3] = 2.4610080640e-09;
		asali_->thermo_[69].high[4] = -1.9769079494e-13;
		asali_->thermo_[69].high[5] = -5.3987992188e+04;
		asali_->thermo_[69].high[6] = -5.5711322784e+01;

		asali_->thermo_[69].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[69].low[0] = -5.0371751785e+00;
		asali_->thermo_[69].low[1] = 8.3092808723e-02;
		asali_->thermo_[69].low[2] = -6.4676176407e-05;
		asali_->thermo_[69].low[3] = 2.5441821094e-08;
		asali_->thermo_[69].low[4] = -3.9774299306e-12;
		asali_->thermo_[69].low[5] = -4.7854472656e+04;
		asali_->thermo_[69].low[6] = 5.0074382782e+01;
		
		asali_->thermo_[70].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[70].name,"CH3OCH3");

		asali_->thermo_[70].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[70].high[0] = 8.1538945436e-01;
		asali_->thermo_[70].high[1] = 2.7267539874e-02;
		asali_->thermo_[70].high[2] = -1.4018142792e-05;
		asali_->thermo_[70].high[3] = 3.4368539126e-09;
		asali_->thermo_[70].high[4] = -3.2554235458e-13;
		asali_->thermo_[70].high[5] = -2.3174589844e+04;
		asali_->thermo_[70].high[6] = 1.9923925400e+01;

		asali_->thermo_[70].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[70].low[0] = 1.7409732342e+00;
		asali_->thermo_[70].low[1] = 2.1978490055e-02;
		asali_->thermo_[70].low[2] = -2.6844641070e-06;
		asali_->thermo_[70].low[3] = -7.3571260195e-09;
		asali_->thermo_[70].low[4] = 3.5294503865e-12;
		asali_->thermo_[70].low[5] = -2.3304171875e+04;
		asali_->thermo_[70].low[6] = 1.5788651466e+01;
		
		asali_->thermo_[71].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[71].name,"CH3CH3-C5H6");

		asali_->thermo_[71].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[71].high[0] = 1.5375555038e+01;
		asali_->thermo_[71].high[1] = 3.2731827348e-02;
		asali_->thermo_[71].high[2] = -1.0595570529e-05;
		asali_->thermo_[71].high[3] = 1.5210263049e-09;
		asali_->thermo_[71].high[4] = -7.6941593017e-14;
		asali_->thermo_[71].high[5] = -6.1968291016e+03;
		asali_->thermo_[71].high[6] = -5.3722602844e+01;

		asali_->thermo_[71].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[71].low[0] = -1.2924780846e+00;
		asali_->thermo_[71].low[1] = 8.3626583219e-02;
		asali_->thermo_[71].low[2] = -6.8872010161e-05;
		asali_->thermo_[71].low[3] = 3.1178245763e-08;
		asali_->thermo_[71].low[4] = -5.7367166573e-12;
		asali_->thermo_[71].low[5] = -1.8298046875e+03;
		asali_->thermo_[71].low[6] = 3.1191839218e+01;
		
		asali_->thermo_[72].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[72].name,"C6H5C2H5");

		asali_->thermo_[72].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[72].high[0] = 1.5399243355e+01;
		asali_->thermo_[72].high[1] = 3.1128443778e-02;
		asali_->thermo_[72].high[2] = -9.3292001111e-06;
		asali_->thermo_[72].high[3] = 5.2965493103e-10;
		asali_->thermo_[72].high[4] = 9.7160994528e-14;
		asali_->thermo_[72].high[5] = -4.3272578125e+03;
		asali_->thermo_[72].high[6] = -5.7749172211e+01;

		asali_->thermo_[72].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[72].low[0] = -6.1178631783e+00;
		asali_->thermo_[72].low[1] = 9.0898185968e-02;
		asali_->thermo_[72].low[2] = -7.1589347499e-05;
		asali_->thermo_[72].low[3] = 2.9353795838e-08;
		asali_->thermo_[72].low[4] = -4.9070300774e-12;
		asali_->thermo_[72].low[5] = 1.8696690674e+03;
		asali_->thermo_[72].low[6] = 5.3904491425e+01;
		
		asali_->thermo_[73].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[73].name,"NC7H14");

		asali_->thermo_[73].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[73].high[0] = 1.8266811371e+01;
		asali_->thermo_[73].high[1] = 3.5960789770e-02;
		asali_->thermo_[73].high[2] = -1.3734640561e-05;
		asali_->thermo_[73].high[3] = 2.5222905986e-09;
		asali_->thermo_[73].high[4] = -1.8524823331e-13;
		asali_->thermo_[73].high[5] = -1.8749734375e+04;
		asali_->thermo_[73].high[6] = -6.9230926514e+01;

		asali_->thermo_[73].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[73].low[0] = -1.2279731035e+00;
		asali_->thermo_[73].low[1] = 7.9282529652e-02;
		asali_->thermo_[73].low[2] = -4.9836089602e-05;
		asali_->thermo_[73].low[3] = 1.5893197869e-08;
		asali_->thermo_[73].low[4] = -2.0423187880e-12;
		asali_->thermo_[73].low[5] = -1.1731612305e+04;
		asali_->thermo_[73].low[6] = 3.6278907776e+01;
		
		asali_->thermo_[74].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[74].name,"NC6H12");

		asali_->thermo_[74].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[74].high[0] = 2.8095165253e+01;
		asali_->thermo_[74].high[1] = 5.2463593893e-03;
		asali_->thermo_[74].high[2] = 6.4320815909e-06;
		asali_->thermo_[74].high[3] = -3.1913138798e-09;
		asali_->thermo_[74].high[4] = 4.0109370903e-13;
		asali_->thermo_[74].high[5] = -1.7976785156e+04;
		asali_->thermo_[74].high[6] = -1.2449729156e+02;

		asali_->thermo_[74].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[74].low[0] = -1.8535830975e+00;
		asali_->thermo_[74].low[1] = 7.2546921670e-02;
		asali_->thermo_[74].low[2] = -5.0281872973e-05;
		asali_->thermo_[74].low[3] = 1.8049867379e-08;
		asali_->thermo_[74].low[4] = -2.5822182934e-12;
		asali_->thermo_[74].low[5] = -7.3150302734e+03;
		asali_->thermo_[74].low[6] = 3.7256958008e+01;
		
		asali_->thermo_[75].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[75].name,"C5H9CHO");

		asali_->thermo_[75].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[75].high[0] = 1.0841624260e+01;
		asali_->thermo_[75].high[1] = 4.2029667646e-02;
		asali_->thermo_[75].high[2] = -2.0074299755e-05;
		asali_->thermo_[75].high[3] = 4.5792738490e-09;
		asali_->thermo_[75].high[4] = -4.0851903024e-13;
		asali_->thermo_[75].high[5] = -3.5963171875e+04;
		asali_->thermo_[75].high[6] = -3.8001781464e+01;

		asali_->thermo_[75].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[75].low[0] = -6.5136365891e+00;
		asali_->thermo_[75].low[1] = 8.0596916378e-02;
		asali_->thermo_[75].low[2] = -5.2213668823e-05;
		asali_->thermo_[75].low[3] = 1.6482744059e-08;
		asali_->thermo_[75].low[4] = -2.0617789160e-12;
		asali_->thermo_[75].low[5] = -2.9715277344e+04;
		asali_->thermo_[75].low[6] = 5.5928508759e+01;
		
		asali_->thermo_[76].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[76].name,"ETBE");

		asali_->thermo_[76].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[76].high[0] = 1.1655913353e+01;
		asali_->thermo_[76].high[1] = 4.6793397516e-02;
		asali_->thermo_[76].high[2] = -1.9334202079e-05;
		asali_->thermo_[76].high[3] = 3.5918514829e-09;
		asali_->thermo_[76].high[4] = -2.4556496159e-13;
		asali_->thermo_[76].high[5] = -4.6032210938e+04;
		asali_->thermo_[76].high[6] = -3.3808494568e+01;

		asali_->thermo_[76].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[76].low[0] = -3.4800560474e+00;
		asali_->thermo_[76].low[1] = 9.4093300402e-02;
		asali_->thermo_[76].low[2] = -7.4763775046e-05;
		asali_->thermo_[76].low[3] = 3.2461421995e-08;
		asali_->thermo_[76].low[4] = -5.8841529739e-12;
		asali_->thermo_[76].low[5] = -4.2157402344e+04;
		asali_->thermo_[76].low[6] = 4.2950275421e+01;
		
		asali_->thermo_[77].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[77].name,"NEOC5H10-O");

		asali_->thermo_[77].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[77].high[0] = 1.2929610252e+01;
		asali_->thermo_[77].high[1] = 3.1615059823e-02;
		asali_->thermo_[77].high[2] = -1.3558497812e-05;
		asali_->thermo_[77].high[3] = 2.8175317635e-09;
		asali_->thermo_[77].high[4] = -2.3268629319e-13;
		asali_->thermo_[77].high[5] = -2.3793392578e+04;
		asali_->thermo_[77].high[6] = -4.8896854401e+01;

		asali_->thermo_[77].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[77].low[0] = -6.9146265984e+00;
		asali_->thermo_[77].low[1] = 8.5612982512e-02;
		asali_->thermo_[77].low[2] = -6.8658417149e-05;
		asali_->thermo_[77].low[3] = 2.7806159153e-08;
		asali_->thermo_[77].low[4] = -4.4824526035e-12;
		asali_->thermo_[77].low[5] = -1.7959187500e+04;
		asali_->thermo_[77].low[6] = 5.4485355377e+01;
		
		asali_->thermo_[78].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[78].name,"C4H8O");

		asali_->thermo_[78].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[78].high[0] = 1.1281599998e+01;
		asali_->thermo_[78].high[1] = 2.4846369401e-02;
		asali_->thermo_[78].high[2] = -1.1323470062e-05;
		asali_->thermo_[78].high[3] = 2.4706994228e-09;
		asali_->thermo_[78].high[4] = -2.1241350150e-13;
		asali_->thermo_[78].high[5] = -2.0375667969e+04;
		asali_->thermo_[78].high[6] = -3.8426738739e+01;

		asali_->thermo_[78].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[78].low[0] = -2.9484512806e+00;
		asali_->thermo_[78].low[1] = 5.6468706578e-02;
		asali_->thermo_[78].low[2] = -3.7675414205e-05;
		asali_->thermo_[78].low[3] = 1.2230679580e-08;
		asali_->thermo_[78].low[4] = -1.5679662430e-12;
		asali_->thermo_[78].low[5] = -1.5252850586e+04;
		asali_->thermo_[78].low[6] = 3.8589267731e+01;
		
		asali_->thermo_[79].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[79].name,"NC5H10-O");

		asali_->thermo_[79].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[79].high[0] = 1.4007309914e+01;
		asali_->thermo_[79].high[1] = 3.0440527946e-02;
		asali_->thermo_[79].high[2] = -1.3585452507e-05;
		asali_->thermo_[79].high[3] = 2.9030535753e-09;
		asali_->thermo_[79].high[4] = -2.4498583500e-13;
		asali_->thermo_[79].high[5] = -2.5545585938e+04;
		asali_->thermo_[79].high[6] = -5.2523937225e+01;

		asali_->thermo_[79].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[79].low[0] = -3.7926309109e+00;
		asali_->thermo_[79].low[1] = 6.9995954633e-02;
		asali_->thermo_[79].low[2] = -4.6548306273e-05;
		asali_->thermo_[79].low[3] = 1.5111517371e-08;
		asali_->thermo_[79].low[4] = -1.9406058791e-12;
		asali_->thermo_[79].low[5] = -1.9137607422e+04;
		asali_->thermo_[79].low[6] = 4.3813056946e+01;
		
		asali_->thermo_[80].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[80].name,"NC7H14O");

		asali_->thermo_[80].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[80].high[0] = 1.3760931969e+01;
		asali_->thermo_[80].high[1] = 4.9937937409e-02;
		asali_->thermo_[80].high[2] = -2.2115234970e-05;
		asali_->thermo_[80].high[3] = 4.7201034192e-09;
		asali_->thermo_[80].high[4] = -3.9816002058e-13;
		asali_->thermo_[80].high[5] = -3.9791792969e+04;
		asali_->thermo_[80].high[6] = -4.6790859222e+01;

		asali_->thermo_[80].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[80].low[0] = -7.3918175697e+00;
		asali_->thermo_[80].low[1] = 1.0672384501e-01;
		asali_->thermo_[80].low[2] = -7.9282253864e-05;
		asali_->thermo_[80].low[3] = 3.0298188847e-08;
		asali_->thermo_[80].low[4] = -4.6897850187e-12;
		asali_->thermo_[80].low[5] = -3.3488273438e+04;
		asali_->thermo_[80].low[6] = 6.3694141388e+01;
		
		asali_->thermo_[81].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[81].name,"IC8H16O");

		asali_->thermo_[81].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[81].high[0] = 2.9252544403e+01;
		asali_->thermo_[81].high[1] = 3.4283522516e-02;
		asali_->thermo_[81].high[2] = -1.1602405721e-05;
		asali_->thermo_[81].high[3] = 1.7729187007e-09;
		asali_->thermo_[81].high[4] = -1.0040181035e-13;
		asali_->thermo_[81].high[5] = -4.9282410156e+04;
		asali_->thermo_[81].high[6] = -1.3381884766e+02;

		asali_->thermo_[81].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[81].low[0] = -8.0523586273e+00;
		asali_->thermo_[81].low[1] = 1.2053763866e-01;
		asali_->thermo_[81].low[2] = -8.6389205535e-05;
		asali_->thermo_[81].low[3] = 3.0592495648e-08;
		asali_->thermo_[81].low[4] = -4.2650804763e-12;
		asali_->thermo_[81].low[5] = -3.6374914062e+04;
		asali_->thermo_[81].low[6] = 6.6603370667e+01;
		
		asali_->thermo_[82].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[82].name,"C2H5OH");

		asali_->thermo_[82].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[82].high[0] = 4.8295946121e+00;
		asali_->thermo_[82].high[1] = 1.7755212262e-02;
		asali_->thermo_[82].high[2] = -6.2111212173e-06;
		asali_->thermo_[82].high[3] = 6.5826522011e-10;
		asali_->thermo_[82].high[4] = 1.6013669476e-14;
		asali_->thermo_[82].high[5] = -3.0865849609e+04;
		asali_->thermo_[82].high[6] = 5.4318040609e-01;

		asali_->thermo_[82].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[82].low[0] = 2.4892158806e-01;
		asali_->thermo_[82].low[1] = 3.1032525003e-02;
		asali_->thermo_[82].low[2] = -2.0642983145e-05;
		asali_->thermo_[82].low[3] = 7.6301791552e-09;
		asali_->thermo_[82].low[4] = -1.2470142106e-12;
		asali_->thermo_[82].low[5] = -2.9601583984e+04;
		asali_->thermo_[82].low[6] = 2.4117639542e+01;
		
		asali_->thermo_[83].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[83].name,"C2H5OO");

		asali_->thermo_[83].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[83].high[0] = 4.8233566284e+00;
		asali_->thermo_[83].high[1] = 2.0681919530e-02;
		asali_->thermo_[83].high[2] = -9.6761186796e-06;
		asali_->thermo_[83].high[3] = 2.1758952418e-09;
		asali_->thermo_[83].high[4] = -1.9191481629e-13;
		asali_->thermo_[83].high[5] = -4.7515634766e+03;
		asali_->thermo_[83].high[6] = 3.9376509190e+00;

		asali_->thermo_[83].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[83].low[0] = 1.8211998940e+00;
		asali_->thermo_[83].low[1] = 3.0212575570e-02;
		asali_->thermo_[83].low[2] = -2.1022136934e-05;
		asali_->thermo_[83].low[3] = 8.1790796358e-09;
		asali_->thermo_[83].low[4] = -1.3830229280e-12;
		asali_->thermo_[83].low[5] = -3.9950197754e+03;
		asali_->thermo_[83].low[6] = 1.9115154266e+01;
		
		asali_->thermo_[84].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[84].name,"C2H5OOH");

		asali_->thermo_[84].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[84].high[0] = 1.1565219879e+01;
		asali_->thermo_[84].high[1] = 1.0221647099e-02;
		asali_->thermo_[84].high[2] = -1.8663005221e-06;
		asali_->thermo_[84].high[3] = -2.5569205087e-10;
		asali_->thermo_[84].high[4] = 7.2621128674e-14;
		asali_->thermo_[84].high[5] = -2.4732814453e+04;
		asali_->thermo_[84].high[6] = -3.4211296082e+01;

		asali_->thermo_[84].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[84].low[0] = 1.4629422426e+00;
		asali_->thermo_[84].low[1] = 3.5636182874e-02;
		asali_->thermo_[84].low[2] = -2.5842276955e-05;
		asali_->thermo_[84].low[3] = 9.7971284418e-09;
		asali_->thermo_[84].low[4] = -1.5080109470e-12;
		asali_->thermo_[84].low[5] = -2.1520289062e+04;
		asali_->thermo_[84].low[6] = 1.9211122513e+01;
		
		asali_->thermo_[85].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[85].name,"C2H4O");

		asali_->thermo_[85].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[85].high[0] = 4.7721753120e+00;
		asali_->thermo_[85].high[1] = 1.2960888445e-02;
		asali_->thermo_[85].high[2] = -4.1960802264e-06;
		asali_->thermo_[85].high[3] = 3.3285946222e-10;
		asali_->thermo_[85].high[4] = 2.9742850435e-14;
		asali_->thermo_[85].high[5] = -8.9105488281e+03;
		asali_->thermo_[85].high[6] = -2.9956827164e+00;

		asali_->thermo_[85].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[85].low[0] = -1.7668315172e+00;
		asali_->thermo_[85].low[1] = 3.1124796718e-02;
		asali_->thermo_[85].low[2] = -2.3116817829e-05;
		asali_->thermo_[85].low[3] = 9.0924601182e-09;
		asali_->thermo_[85].low[4] = -1.4910211737e-12;
		asali_->thermo_[85].low[5] = -7.0273149414e+03;
		asali_->thermo_[85].low[6] = 3.0935647964e+01;
		
		asali_->thermo_[86].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[86].name,"C6H5C2H");

		asali_->thermo_[86].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[86].high[0] = 1.3630162239e+01;
		asali_->thermo_[86].high[1] = 2.6782613248e-02;
		asali_->thermo_[86].high[2] = -1.1827697563e-05;
		asali_->thermo_[86].high[3] = 2.5680724214e-09;
		asali_->thermo_[86].high[4] = -2.2161664322e-13;
		asali_->thermo_[86].high[5] = 3.0438148438e+04;
		asali_->thermo_[86].high[6] = -4.8343486786e+01;

		asali_->thermo_[86].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[86].low[0] = -3.7308592796e+00;
		asali_->thermo_[86].low[1] = 7.8996211290e-02;
		asali_->thermo_[86].low[2] = -7.0715213951e-05;
		asali_->thermo_[86].low[3] = 3.2085626600e-08;
		asali_->thermo_[86].low[4] = -5.7700289859e-12;
		asali_->thermo_[86].low[5] = 3.5056179688e+04;
		asali_->thermo_[86].low[6] = 4.0364406586e+01;
		
		asali_->thermo_[87].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[87].name,"BIPHENYL");

		asali_->thermo_[87].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[87].high[0] = 2.6769207001e+01;
		asali_->thermo_[87].high[1] = 2.8161142021e-02;
		asali_->thermo_[87].high[2] = -6.0566771936e-06;
		asali_->thermo_[87].high[3] = -3.6937841674e-10;
		asali_->thermo_[87].high[4] = 1.6724937949e-13;
		asali_->thermo_[87].high[5] = 9.2669248047e+03;
		asali_->thermo_[87].high[6] = -1.2130641174e+02;

		asali_->thermo_[87].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[87].low[0] = -1.0562510490e+01;
		asali_->thermo_[87].low[1] = 1.3114519417e-01;
		asali_->thermo_[87].low[2] = -1.1259190069e-04;
		asali_->thermo_[87].low[3] = 4.8612335490e-08;
		asali_->thermo_[87].low[4] = -8.2778731786e-12;
		asali_->thermo_[87].low[5] = 2.0093123047e+04;
		asali_->thermo_[87].low[6] = 7.2668655396e+01;
		
		asali_->thermo_[88].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[88].name,"C14H10");

		asali_->thermo_[88].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[88].high[0] = 3.1314125061e+01;
		asali_->thermo_[88].high[1] = 2.8952870518e-02;
		asali_->thermo_[88].high[2] = -5.5767100093e-06;
		asali_->thermo_[88].high[3] = -5.8966292960e-10;
		asali_->thermo_[88].high[4] = 1.8820294173e-13;
		asali_->thermo_[88].high[5] = 1.0646019531e+04;
		asali_->thermo_[88].high[6] = -1.4810102844e+02;

		asali_->thermo_[88].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[88].low[0] = -1.2190587044e+01;
		asali_->thermo_[88].low[1] = 1.5064437687e-01;
		asali_->thermo_[88].low[2] = -1.3322514133e-04;
		asali_->thermo_[88].low[3] = 5.8920093693e-08;
		asali_->thermo_[88].low[4] = -1.0215600935e-11;
		asali_->thermo_[88].low[5] = 2.3088367188e+04;
		asali_->thermo_[88].low[6] = 7.7344589233e+01;
		
		asali_->thermo_[89].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[89].name,"C6H5OH");

		asali_->thermo_[89].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[89].high[0] = 1.3986771584e+01;
		asali_->thermo_[89].high[1] = 2.0227763802e-02;
		asali_->thermo_[89].high[2] = -7.3659948612e-06;
		asali_->thermo_[89].high[3] = 1.2119628634e-09;
		asali_->thermo_[89].high[4] = -7.4610504136e-14;
		asali_->thermo_[89].high[5] = -1.8054226562e+04;
		asali_->thermo_[89].high[6] = -5.0848579407e+01;

		asali_->thermo_[89].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[89].low[0] = -5.4732542038e+00;
		asali_->thermo_[89].low[1] = 7.8754156828e-02;
		asali_->thermo_[89].low[2] = -7.3373201303e-05;
		asali_->thermo_[89].low[3] = 3.4298285101e-08;
		asali_->thermo_[89].low[4] = -6.2938439183e-12;
		asali_->thermo_[89].low[5] = -1.2877859375e+04;
		asali_->thermo_[89].low[6] = 4.8584381104e+01;
		
		asali_->thermo_[90].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[90].name,"FLUORENE");

		asali_->thermo_[90].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[90].high[0] = 2.9124887466e+01;
		asali_->thermo_[90].high[1] = 2.8536202386e-02;
		asali_->thermo_[90].high[2] = -5.6619974202e-06;
		asali_->thermo_[90].high[3] = -5.6702670337e-10;
		asali_->thermo_[90].high[4] = 1.9113497677e-13;
		asali_->thermo_[90].high[5] = 9.7511933594e+03;
		asali_->thermo_[90].high[6] = -1.3715922546e+02;

		asali_->thermo_[90].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[90].low[0] = -1.4346511841e+01;
		asali_->thermo_[90].low[1] = 1.4929008484e-01;
		asali_->thermo_[90].low[2] = -1.3144729019e-04;
		asali_->thermo_[90].low[3] = 5.7666909470e-08;
		asali_->thermo_[90].low[4] = -9.9189233216e-12;
		asali_->thermo_[90].low[5] = 2.2270957031e+04;
		asali_->thermo_[90].low[6] = 8.8416702271e+01;
		
		asali_->thermo_[91].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[91].name,"C10H8");

		asali_->thermo_[91].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[91].high[0] = 1.5118482590e+01;
		asali_->thermo_[91].high[1] = 3.8967557251e-02;
		asali_->thermo_[91].high[2] = -1.7824866518e-05;
		asali_->thermo_[91].high[3] = 3.9209226976e-09;
		asali_->thermo_[91].high[4] = -3.3921568896e-13;
		asali_->thermo_[91].high[5] = 1.0112156250e+04;
		asali_->thermo_[91].high[6] = -6.0904109955e+01;

		asali_->thermo_[91].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[91].low[0] = -8.7183246613e+00;
		asali_->thermo_[91].low[1] = 1.0856407136e-01;
		asali_->thermo_[91].low[2] = -9.4025432190e-05;
		asali_->thermo_[91].low[3] = 4.1001488427e-08;
		asali_->thermo_[91].low[4] = -7.1057426436e-12;
		asali_->thermo_[91].low[5] = 1.6643441406e+04;
		asali_->thermo_[91].low[6] = 6.1598789215e+01;
		
		asali_->thermo_[92].name = (char*) malloc(1 * sizeof(char));
		strcpy(asali_->thermo_[92].name,"H");

		asali_->thermo_[92].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[92].high[0] = 2.5000000000e+00;
		asali_->thermo_[92].high[1] = 7.4033618794e-15;
		asali_->thermo_[92].high[2] = -5.5696742437e-18;
		asali_->thermo_[92].high[3] = 1.7392488179e-21;
		asali_->thermo_[92].high[4] = -1.9267370477e-25;
		asali_->thermo_[92].high[5] = 2.5471619141e+04;
		asali_->thermo_[92].high[6] = -4.6011760831e-01;

		asali_->thermo_[92].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[92].low[0] = 2.5000000000e+00;
		asali_->thermo_[92].low[1] = -4.0745516194e-15;
		asali_->thermo_[92].low[2] = 5.9852725309e-18;
		asali_->thermo_[92].low[3] = -3.4307497659e-21;
		asali_->thermo_[92].low[4] = 6.7477569320e-25;
		asali_->thermo_[92].low[5] = 2.5471619141e+04;
		asali_->thermo_[92].low[6] = -4.6011760831e-01;
		
		asali_->thermo_[93].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->thermo_[93].name,"H2");

		asali_->thermo_[93].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[93].high[0] = 3.7311089039e+00;
		asali_->thermo_[93].high[1] = -8.8670622790e-04;
		asali_->thermo_[93].high[2] = 1.1228689800e-06;
		asali_->thermo_[93].high[3] = -3.7434977340e-10;
		asali_->thermo_[93].high[4] = 4.1796366444e-14;
		asali_->thermo_[93].high[5] = -1.0885155029e+03;
		asali_->thermo_[93].high[6] = -5.3528585434e+00;

		asali_->thermo_[93].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[93].low[0] = 3.0886600018e+00;
		asali_->thermo_[93].low[1] = 2.5396884885e-03;
		asali_->thermo_[93].low[2] = -5.7299203036e-06;
		asali_->thermo_[93].low[3] = 5.7170184142e-09;
		asali_->thermo_[93].low[4] = -1.9886596710e-12;
		asali_->thermo_[93].low[5] = -9.9214813232e+02;
		asali_->thermo_[93].low[6] = -2.4382345676e+00;
		
		asali_->thermo_[94].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[94].name,"H2O");

		asali_->thermo_[94].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[94].high[0] = 2.3094046116e+00;
		asali_->thermo_[94].high[1] = 3.6543388851e-03;
		asali_->thermo_[94].high[2] = -1.2298387446e-06;
		asali_->thermo_[94].high[3] = 2.1193168054e-10;
		asali_->thermo_[94].high[4] = -1.5033349118e-14;
		asali_->thermo_[94].high[5] = -2.9729490234e+04;
		asali_->thermo_[94].high[6] = 8.9276514053e+00;

		asali_->thermo_[94].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[94].low[0] = 4.0353093147e+00;
		asali_->thermo_[94].low[1] = -6.8755983375e-04;
		asali_->thermo_[94].low[2] = 2.8662921068e-06;
		asali_->thermo_[94].low[3] = -1.5055235947e-09;
		asali_->thermo_[94].low[4] = 2.5500679042e-13;
		asali_->thermo_[94].low[5] = -3.0278328125e+04;
		asali_->thermo_[94].low[6] = -1.9920164347e-01;
		
		asali_->thermo_[95].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[95].name,"H2O2");

		asali_->thermo_[95].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[95].high[0] = 4.5616307259e+00;
		asali_->thermo_[95].high[1] = 4.3556098826e-03;
		asali_->thermo_[95].high[2] = -1.4869463030e-06;
		asali_->thermo_[95].high[3] = 2.3827542717e-10;
		asali_->thermo_[95].high[4] = -1.4661035786e-14;
		asali_->thermo_[95].high[5] = -1.8001669922e+04;
		asali_->thermo_[95].high[6] = 5.6659710407e-01;

		asali_->thermo_[95].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[95].low[0] = 2.9189634323e+00;
		asali_->thermo_[95].low[1] = 9.9239731207e-03;
		asali_->thermo_[95].low[2] = -8.5653746282e-06;
		asali_->thermo_[95].low[3] = 4.2373873299e-09;
		asali_->thermo_[95].low[4] = -8.6193048142e-13;
		asali_->thermo_[95].low[5] = -1.7614000000e+04;
		asali_->thermo_[95].low[6] = 8.7634019852e+00;
		
		asali_->thermo_[96].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[96].name,"HCCO");

		asali_->thermo_[96].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[96].high[0] = 7.4490032196e+00;
		asali_->thermo_[96].high[1] = 1.0117782513e-03;
		asali_->thermo_[96].high[2] = 3.0291815278e-07;
		asali_->thermo_[96].high[3] = -2.1390939020e-10;
		asali_->thermo_[96].high[4] = 2.8181521380e-14;
		asali_->thermo_[96].high[5] = 1.8645894531e+04;
		asali_->thermo_[96].high[6] = -1.3098773003e+01;

		asali_->thermo_[96].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[96].low[0] = 4.4451417923e+00;
		asali_->thermo_[96].low[1] = 7.6870261692e-03;
		asali_->thermo_[96].low[2] = -5.2597883951e-06;
		asali_->thermo_[96].low[3] = 1.8463522933e-09;
		asali_->thermo_[96].low[4] = -2.5796593052e-13;
		asali_->thermo_[96].low[5] = 1.9727285156e+04;
		asali_->thermo_[96].low[6] = 3.1587517262e+00;
		
		asali_->thermo_[97].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[97].name,"HCO");

		asali_->thermo_[97].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[97].high[0] = 2.4477207661e+00;
		asali_->thermo_[97].high[1] = 5.6557054631e-03;
		asali_->thermo_[97].high[2] = -3.0132955544e-06;
		asali_->thermo_[97].high[3] = 7.5770251184e-10;
		asali_->thermo_[97].high[4] = -7.2612963277e-14;
		asali_->thermo_[97].high[5] = 4.3114916992e+03;
		asali_->thermo_[97].high[6] = 1.1587195396e+01;

		asali_->thermo_[97].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[97].low[0] = 3.7421886921e+00;
		asali_->thermo_[97].low[1] = 2.7584406780e-05;
		asali_->thermo_[97].low[2] = 6.1629889387e-06;
		asali_->thermo_[97].low[3] = -5.8917790646e-09;
		asali_->thermo_[97].low[4] = 1.7343113707e-12;
		asali_->thermo_[97].low[5] = 4.0733095703e+03;
		asali_->thermo_[97].low[6] = 5.4500708580e+00;
		
		asali_->thermo_[98].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[98].name,"HCO3");

		asali_->thermo_[98].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[98].high[0] = 5.0406770706e+00;
		asali_->thermo_[98].high[1] = 8.6665609851e-03;
		asali_->thermo_[98].high[2] = -4.2895826482e-06;
		asali_->thermo_[98].high[3] = 1.0056337985e-09;
		asali_->thermo_[98].high[4] = -9.1359991133e-14;
		asali_->thermo_[98].high[5] = -1.7790212891e+04;
		asali_->thermo_[98].high[6] = 5.7819151878e+00;

		asali_->thermo_[98].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[98].low[0] = 3.7930066586e+00;
		asali_->thermo_[98].low[1] = 1.1439162306e-02;
		asali_->thermo_[98].low[2] = -6.6000834522e-06;
		asali_->thermo_[98].low[3] = 1.8613748320e-09;
		asali_->thermo_[98].low[4] = -2.1021290990e-13;
		asali_->thermo_[98].low[5] = -1.7341052734e+04;
		asali_->thermo_[98].low[6] = 1.2534567833e+01;
		
		asali_->thermo_[99].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->thermo_[99].name,"HE");

		asali_->thermo_[99].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[99].high[0] = 2.5000000000e+00;
		asali_->thermo_[99].high[1] = 7.4033618794e-15;
		asali_->thermo_[99].high[2] = -5.5696742437e-18;
		asali_->thermo_[99].high[3] = 1.7392488179e-21;
		asali_->thermo_[99].high[4] = -1.9267370477e-25;
		asali_->thermo_[99].high[5] = -7.4537500000e+02;
		asali_->thermo_[99].high[6] = 9.2872399092e-01;

		asali_->thermo_[99].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[99].low[0] = 2.5000000000e+00;
		asali_->thermo_[99].low[1] = -4.0745516194e-15;
		asali_->thermo_[99].low[2] = 5.9852725309e-18;
		asali_->thermo_[99].low[3] = -3.4307497659e-21;
		asali_->thermo_[99].low[4] = 6.7477569320e-25;
		asali_->thermo_[99].low[5] = -7.4537500000e+02;
		asali_->thermo_[99].low[6] = 9.2872399092e-01;
		
		asali_->thermo_[100].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[100].name,"HO2");

		asali_->thermo_[100].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[100].high[0] = 4.1631808281e+00;
		asali_->thermo_[100].high[1] = 1.9979826175e-03;
		asali_->thermo_[100].high[2] = -4.8919207529e-07;
		asali_->thermo_[100].high[3] = 7.7115314134e-11;
		asali_->thermo_[100].high[4] = -7.3077208483e-15;
		asali_->thermo_[100].high[5] = 4.4134895325e+01;
		asali_->thermo_[100].high[6] = 2.9551799297e+00;

		asali_->thermo_[100].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[100].low[0] = 2.8524138927e+00;
		asali_->thermo_[100].low[1] = 5.4025719874e-03;
		asali_->thermo_[100].low[2] = -3.8053503886e-06;
		asali_->thermo_[100].low[3] = 1.5126816466e-09;
		asali_->thermo_[100].low[4] = -2.4035420464e-13;
		asali_->thermo_[100].low[5] = 4.4785107422e+02;
		asali_->thermo_[100].low[6] = 9.8448381424e+00;
		
		asali_->thermo_[101].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[101].name,"IC4H8");

		asali_->thermo_[101].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[101].high[0] = 7.6343398094e+00;
		asali_->thermo_[101].high[1] = 2.4772269651e-02;
		asali_->thermo_[101].high[2] = -1.0541582924e-05;
		asali_->thermo_[101].high[3] = 2.1815236284e-09;
		asali_->thermo_[101].high[4] = -1.8011959112e-13;
		asali_->thermo_[101].high[5] = -6.2138579102e+03;
		asali_->thermo_[101].high[6] = -1.7294937134e+01;

		asali_->thermo_[101].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[101].low[0] = 7.1730160713e-01;
		asali_->thermo_[101].low[1] = 4.0143463761e-02;
		asali_->thermo_[101].low[2] = -2.3350912670e-05;
		asali_->thermo_[101].low[3] = 6.9257199975e-09;
		asali_->thermo_[101].low[4] = -8.3903570940e-13;
		asali_->thermo_[101].low[5] = -3.7237238770e+03;
		asali_->thermo_[101].low[6] = 2.0141515732e+01;
		
		asali_->thermo_[102].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[102].name,"IC3H7CHO");

		asali_->thermo_[102].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[102].high[0] = 1.2537504196e+01;
		asali_->thermo_[102].high[1] = 2.0675983280e-02;
		asali_->thermo_[102].high[2] = -7.9060664575e-06;
		asali_->thermo_[102].high[3] = 1.4476160271e-09;
		asali_->thermo_[102].high[4] = -1.0577657999e-13;
		asali_->thermo_[102].high[5] = -3.2236363281e+04;
		asali_->thermo_[102].high[6] = -4.1050521851e+01;

		asali_->thermo_[102].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[102].low[0] = -3.4473210573e-01;
		asali_->thermo_[102].low[1] = 4.9303174019e-02;
		asali_->thermo_[102].low[2] = -3.1762057915e-05;
		asali_->thermo_[102].low[3] = 1.0283168983e-08;
		asali_->thermo_[102].low[4] = -1.3329366907e-12;
		asali_->thermo_[102].low[5] = -2.7598757812e+04;
		asali_->thermo_[102].low[6] = 2.8670827866e+01;
		
		asali_->thermo_[103].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[103].name,"IC4H9P");

		asali_->thermo_[103].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[103].high[0] = 7.9588050842e+00;
		asali_->thermo_[103].high[1] = 2.5508828461e-02;
		asali_->thermo_[103].high[2] = -8.6222153186e-06;
		asali_->thermo_[103].high[3] = 8.0964890348e-10;
		asali_->thermo_[103].high[4] = 4.0203321087e-14;
		asali_->thermo_[103].high[5] = 3.3775930176e+03;
		asali_->thermo_[103].high[6] = -1.6108404160e+01;

		asali_->thermo_[103].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[103].low[0] = -1.1558237076e+00;
		asali_->thermo_[103].low[1] = 5.1004294306e-02;
		asali_->thermo_[103].low[2] = -3.5365708754e-05;
		asali_->thermo_[103].low[3] = 1.3277478672e-08;
		asali_->thermo_[103].low[4] = -2.1394871551e-12;
		asali_->thermo_[103].low[5] = 5.9843769531e+03;
		asali_->thermo_[103].low[6] = 3.1124481201e+01;
		
		asali_->thermo_[104].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[104].name,"IC4H9P-OO");

		asali_->thermo_[104].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[104].high[0] = 8.5429582596e+00;
		asali_->thermo_[104].high[1] = 3.4522078931e-02;
		asali_->thermo_[104].high[2] = -1.5931194866e-05;
		asali_->thermo_[104].high[3] = 3.5385268049e-09;
		asali_->thermo_[104].high[4] = -3.0895004979e-13;
		asali_->thermo_[104].high[5] = -1.2953217773e+04;
		asali_->thermo_[104].high[6] = -1.3982506752e+01;

		asali_->thermo_[104].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[104].low[0] = 7.0055520535e-01;
		asali_->thermo_[104].low[1] = 5.7253681123e-02;
		asali_->thermo_[104].low[2] = -4.0639457438e-05;
		asali_->thermo_[104].low[3] = 1.5474885373e-08;
		asali_->thermo_[104].low[4] = -2.4713341183e-12;
		asali_->thermo_[104].low[5] = -1.0788713867e+04;
		asali_->thermo_[104].low[6] = 2.6378463745e+01;
		
		asali_->thermo_[105].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[105].name,"IC4H9T");

		asali_->thermo_[105].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[105].high[0] = 7.9087166786e+00;
		asali_->thermo_[105].high[1] = 2.5526445359e-02;
		asali_->thermo_[105].high[2] = -8.6528407337e-06;
		asali_->thermo_[105].high[3] = 8.2441969917e-10;
		asali_->thermo_[105].high[4] = 3.8055065962e-14;
		asali_->thermo_[105].high[5] = 8.3547058105e+02;
		asali_->thermo_[105].high[6] = -1.7329927444e+01;

		asali_->thermo_[105].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[105].low[0] = -1.2990022898e+00;
		asali_->thermo_[105].low[1] = 5.1834214479e-02;
		asali_->thermo_[105].low[2] = -3.6839737731e-05;
		asali_->thermo_[105].low[3] = 1.4246751334e-08;
		asali_->thermo_[105].low[4] = -2.3587898128e-12;
		asali_->thermo_[105].low[5] = 3.4136320801e+03;
		asali_->thermo_[105].low[6] = 3.0190137863e+01;
		
		asali_->thermo_[106].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[106].name,"IC4H9T-OO");

		asali_->thermo_[106].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[106].high[0] = 9.1166763306e+00;
		asali_->thermo_[106].high[1] = 3.4175727516e-02;
		asali_->thermo_[106].high[2] = -1.5879733837e-05;
		asali_->thermo_[106].high[3] = 3.5468645798e-09;
		asali_->thermo_[106].high[4] = -3.1097655917e-13;
		asali_->thermo_[106].high[5] = -1.6459164062e+04;
		asali_->thermo_[106].high[6] = -1.9656402588e+01;

		asali_->thermo_[106].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[106].low[0] = 4.8406901956e-01;
		asali_->thermo_[106].low[1] = 6.1580829322e-02;
		asali_->thermo_[106].low[2] = -4.8504854931e-05;
		asali_->thermo_[106].low[3] = 2.0808833767e-08;
		asali_->thermo_[106].low[4] = -3.7359703005e-12;
		asali_->thermo_[106].low[5] = -1.4283748047e+04;
		asali_->thermo_[106].low[6] = 2.3986032486e+01;
		
		asali_->thermo_[107].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[107].name,"IC4H10");

		asali_->thermo_[107].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[107].high[0] = 5.5195579529e+00;
		asali_->thermo_[107].high[1] = 3.2374724746e-02;
		asali_->thermo_[107].high[2] = -1.1865543456e-05;
		asali_->thermo_[107].high[3] = 1.3745518057e-09;
		asali_->thermo_[107].high[4] = 1.5707346787e-14;
		asali_->thermo_[107].high[5] = -1.9702580078e+04;
		asali_->thermo_[107].high[6] = -6.3448343277e+00;

		asali_->thermo_[107].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[107].low[0] = -1.8596532345e+00;
		asali_->thermo_[107].low[1] = 5.5800795555e-02;
		asali_->thermo_[107].low[2] = -3.9753718738e-05;
		asali_->thermo_[107].low[3] = 1.6130199398e-08;
		asali_->thermo_[107].low[4] = -2.9120007187e-12;
		asali_->thermo_[107].low[5] = -1.7843019531e+04;
		asali_->thermo_[107].low[6] = 3.0961015701e+01;
		
		asali_->thermo_[108].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[108].name,"IC16H34");

		asali_->thermo_[108].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[108].high[0] = 4.7252460480e+01;
		asali_->thermo_[108].high[1] = 8.5468076169e-02;
		asali_->thermo_[108].high[2] = -3.3661272028e-05;
		asali_->thermo_[108].high[3] = 6.3820202456e-09;
		asali_->thermo_[108].high[4] = -4.8209488701e-13;
		asali_->thermo_[108].high[5] = -7.7874414062e+04;
		asali_->thermo_[108].high[6] = -2.2418295288e+02;

		asali_->thermo_[108].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[108].low[0] = -9.9361228943e+00;
		asali_->thermo_[108].low[1] = 2.2933872044e-01;
		asali_->thermo_[108].low[2] = -1.6938829503e-04;
		asali_->thermo_[108].low[3] = 6.3290627850e-08;
		asali_->thermo_[108].low[4] = -9.4299889078e-12;
		asali_->thermo_[108].low[5] = -5.9688445312e+04;
		asali_->thermo_[108].low[6] = 7.8239196777e+01;
		
		asali_->thermo_[109].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[109].name,"IC4H7");

		asali_->thermo_[109].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[109].high[0] = 1.1817711592e+00;
		asali_->thermo_[109].high[1] = 3.6776904017e-02;
		asali_->thermo_[109].high[2] = -1.7703134290e-05;
		asali_->thermo_[109].high[3] = 3.7478624648e-09;
		asali_->thermo_[109].high[4] = -2.9219129286e-13;
		asali_->thermo_[109].high[5] = 1.3121423828e+04;
		asali_->thermo_[109].high[6] = 2.0012054443e+01;

		asali_->thermo_[109].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[109].low[0] = 3.8612999916e+00;
		asali_->thermo_[109].low[1] = 2.1465310827e-02;
		asali_->thermo_[109].low[2] = 1.5107421859e-05;
		asali_->thermo_[109].low[3] = -2.7500284716e-08;
		asali_->thermo_[109].low[4] = 1.0867861298e-11;
		asali_->thermo_[109].low[5] = 1.2746290039e+04;
		asali_->thermo_[109].low[6] = 8.0405979156e+00;
		
		asali_->thermo_[110].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[110].name,"IC8H18");

		asali_->thermo_[110].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[110].high[0] = 2.0615589142e+01;
		asali_->thermo_[110].high[1] = 4.4369410723e-02;
		asali_->thermo_[110].high[2] = -1.3596885765e-05;
		asali_->thermo_[110].high[3] = 1.7532761909e-09;
		asali_->thermo_[110].high[4] = -6.8309087228e-14;
		asali_->thermo_[110].high[5] = -3.7658062500e+04;
		asali_->thermo_[110].high[6] = -8.4214881897e+01;

		asali_->thermo_[110].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[110].low[0] = -5.9691209793e+00;
		asali_->thermo_[110].low[1] = 1.2087216973e-01;
		asali_->thermo_[110].low[2] = -9.6153824416e-05;
		asali_->thermo_[110].low[3] = 4.1348929614e-08;
		asali_->thermo_[110].low[4] = -7.1898294610e-12;
		asali_->thermo_[110].low[5] = -3.0267511719e+04;
		asali_->thermo_[110].low[6] = 5.2795421600e+01;
		
		asali_->thermo_[111].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[111].name,"INDENE");

		asali_->thermo_[111].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[111].high[0] = 1.6534870148e+01;
		asali_->thermo_[111].high[1] = 2.8136143461e-02;
		asali_->thermo_[111].high[2] = -7.8267457866e-06;
		asali_->thermo_[111].high[3] = 2.3393639803e-10;
		asali_->thermo_[111].high[4] = 1.1523444146e-13;
		asali_->thermo_[111].high[5] = 1.1327866211e+04;
		asali_->thermo_[111].high[6] = -6.6647804260e+01;

		asali_->thermo_[111].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[111].low[0] = -7.3259220123e+00;
		asali_->thermo_[111].low[1] = 9.3959018588e-02;
		asali_->thermo_[111].low[2] = -7.5919371739e-05;
		asali_->thermo_[111].low[3] = 3.1540892564e-08;
		asali_->thermo_[111].low[4] = -5.2825161780e-12;
		asali_->thermo_[111].low[5] = 1.8247496094e+04;
		asali_->thermo_[111].low[6] = 5.7332519531e+01;
		
		asali_->thermo_[112].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[112].name,"IC3H7");

		asali_->thermo_[112].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[112].high[0] = 8.4877977371e+00;
		asali_->thermo_[112].high[1] = 1.5325925313e-02;
		asali_->thermo_[112].high[2] = -4.7647440624e-06;
		asali_->thermo_[112].high[3] = 3.9206526914e-10;
		asali_->thermo_[112].high[4] = 2.4711151162e-14;
		asali_->thermo_[112].high[5] = 5.5050742188e+03;
		asali_->thermo_[112].high[6] = -2.1271961212e+01;

		asali_->thermo_[112].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[112].low[0] = 2.7372524142e-01;
		asali_->thermo_[112].low[1] = 3.5483159125e-02;
		asali_->thermo_[112].low[2] = -2.3314345526e-05;
		asali_->thermo_[112].low[3] = 7.9788140539e-09;
		asali_->thermo_[112].low[4] = -1.1389007142e-12;
		asali_->thermo_[112].low[5] = 8.1828618164e+03;
		asali_->thermo_[112].low[6] = 2.2369422913e+01;
		
		asali_->thermo_[113].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[113].name,"IC3H7OH");

		asali_->thermo_[113].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[113].high[0] = 6.2806959152e+00;
		asali_->thermo_[113].high[1] = 2.5937004015e-02;
		asali_->thermo_[113].high[2] = -1.0535074580e-05;
		asali_->thermo_[113].high[3] = 1.9292136777e-09;
		asali_->thermo_[113].high[4] = -1.3018399022e-13;
		asali_->thermo_[113].high[5] = -3.6376863281e+04;
		asali_->thermo_[113].high[6] = -6.6634187698e+00;

		asali_->thermo_[113].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[113].low[0] = -3.0057406425e-01;
		asali_->thermo_[113].low[1] = 4.6032484621e-02;
		asali_->thermo_[113].low[2] = -3.3545169572e-05;
		asali_->thermo_[113].low[3] = 1.3639184893e-08;
		asali_->thermo_[113].low[4] = -2.3649112182e-12;
		asali_->thermo_[113].low[5] = -3.4652570312e+04;
		asali_->thermo_[113].low[6] = 2.6864526749e+01;
		
		asali_->thermo_[114].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[114].name,"IC3H7OO");

		asali_->thermo_[114].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[114].high[0] = 7.3473868370e+00;
		asali_->thermo_[114].high[1] = 2.6825232431e-02;
		asali_->thermo_[114].high[2] = -1.2417968719e-05;
		asali_->thermo_[114].high[3] = 2.7664586177e-09;
		asali_->thermo_[114].high[4] = -2.4214733951e-13;
		asali_->thermo_[114].high[5] = -1.0648485352e+04;
		asali_->thermo_[114].high[6] = -8.9258718491e+00;

		asali_->thermo_[114].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[114].low[0] = 1.0734126568e+00;
		asali_->thermo_[114].low[1] = 4.6742610633e-02;
		asali_->thermo_[114].low[2] = -3.6129134969e-05;
		asali_->thermo_[114].low[3] = 1.5312048518e-08;
		asali_->thermo_[114].low[4] = -2.7313518201e-12;
		asali_->thermo_[114].low[5] = -9.0674443359e+03;
		asali_->thermo_[114].low[6] = 2.2792415619e+01;
		
		asali_->thermo_[115].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[115].name,"IC3-QOOH");

		asali_->thermo_[115].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[115].high[0] = 1.0449804306e+01;
		asali_->thermo_[115].high[1] = 2.2949097678e-02;
		asali_->thermo_[115].high[2] = -1.0575776287e-05;
		asali_->thermo_[115].high[3] = 2.3417268125e-09;
		asali_->thermo_[115].high[4] = -2.0366915348e-13;
		asali_->thermo_[115].high[5] = -5.2229941406e+03;
		asali_->thermo_[115].high[6] = -2.4000869751e+01;

		asali_->thermo_[115].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[115].low[0] = -1.7111088336e-01;
		asali_->thermo_[115].low[1] = 5.6400798261e-02;
		asali_->thermo_[115].low[2] = -5.0085658586e-05;
		asali_->thermo_[115].low[3] = 2.3081822675e-08;
		asali_->thermo_[115].low[4] = -4.2863650997e-12;
		asali_->thermo_[115].low[5] = -2.5252817383e+03;
		asali_->thermo_[115].low[6] = 2.9777484894e+01;
		
		asali_->thermo_[116].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[116].name,"IC3-OOQOOH");

		asali_->thermo_[116].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[116].high[0] = 1.2303562164e+01;
		asali_->thermo_[116].high[1] = 2.7996487916e-02;
		asali_->thermo_[116].high[2] = -1.3348290850e-05;
		asali_->thermo_[116].high[3] = 3.0352407254e-09;
		asali_->thermo_[116].high[4] = -2.6927115052e-13;
		asali_->thermo_[116].high[5] = -2.2578482422e+04;
		asali_->thermo_[116].high[6] = -2.7855079651e+01;

		asali_->thermo_[116].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[116].low[0] = 1.7314383984e+00;
		asali_->thermo_[116].low[1] = 6.2659189105e-02;
		asali_->thermo_[116].low[2] = -5.5966367654e-05;
		asali_->thermo_[116].low[3] = 2.6323807134e-08;
		asali_->thermo_[116].low[4] = -5.0415184180e-12;
		asali_->thermo_[116].low[5] = -1.9998884766e+04;
		asali_->thermo_[116].low[6] = 2.5251583099e+01;
		
		asali_->thermo_[117].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[117].name,"IC5H10");

		asali_->thermo_[117].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[117].high[0] = 2.1345983505e+01;
		asali_->thermo_[117].high[1] = 8.8836718351e-03;
		asali_->thermo_[117].high[2] = 1.5964841396e-06;
		asali_->thermo_[117].high[3] = -1.3180819769e-09;
		asali_->thermo_[117].high[4] = 1.7460085298e-13;
		asali_->thermo_[117].high[5] = -1.2662007812e+04;
		asali_->thermo_[117].high[6] = -8.9469985962e+01;

		asali_->thermo_[117].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[117].low[0] = -1.5963453054e+00;
		asali_->thermo_[117].low[1] = 5.9866625816e-02;
		asali_->thermo_[117].low[2] = -4.0889310185e-05;
		asali_->thermo_[117].low[3] = 1.4417397942e-08;
		asali_->thermo_[117].low[4] = -2.0108823461e-12;
		asali_->thermo_[117].low[5] = -4.4027690430e+03;
		asali_->thermo_[117].low[6] = 3.4698684692e+01;
		
		asali_->thermo_[118].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[118].name,"NEOC5-OQOOH");

		asali_->thermo_[118].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[118].high[0] = 2.2445993423e+01;
		asali_->thermo_[118].high[1] = 2.3762127385e-02;
		asali_->thermo_[118].high[2] = -8.8388151198e-06;
		asali_->thermo_[118].high[3] = 1.5383007090e-09;
		asali_->thermo_[118].high[4] = -1.0451481260e-13;
		asali_->thermo_[118].high[5] = -5.0388023438e+04;
		asali_->thermo_[118].high[6] = -8.7740562439e+01;

		asali_->thermo_[118].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[118].low[0] = 1.2728356123e+00;
		asali_->thermo_[118].low[1] = 7.3876112700e-02;
		asali_->thermo_[118].low[2] = -5.3318683058e-05;
		asali_->thermo_[118].low[3] = 1.9084598790e-08;
		asali_->thermo_[118].low[4] = -2.7001211596e-12;
		asali_->thermo_[118].low[5] = -4.3231496094e+04;
		asali_->thermo_[118].low[6] = 2.5517845154e+01;
		
		asali_->thermo_[119].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[119].name,"IC4-OQOOH");

		asali_->thermo_[119].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[119].high[0] = 1.5156787872e+01;
		asali_->thermo_[119].high[1] = 2.5722773746e-02;
		asali_->thermo_[119].high[2] = -1.1102045391e-05;
		asali_->thermo_[119].high[3] = 2.2894350860e-09;
		asali_->thermo_[119].high[4] = -1.8626952465e-13;
		asali_->thermo_[119].high[5] = -4.3065839844e+04;
		asali_->thermo_[119].high[6] = -4.5984500885e+01;

		asali_->thermo_[119].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[119].low[0] = 9.6927934885e-01;
		asali_->thermo_[119].low[1] = 6.1869293451e-02;
		asali_->thermo_[119].low[2] = -4.5636934374e-05;
		asali_->thermo_[119].low[3] = 1.6953931592e-08;
		asali_->thermo_[119].low[4] = -2.5213804569e-12;
		asali_->thermo_[119].low[5] = -3.8610964844e+04;
		asali_->thermo_[119].low[6] = 2.8861665726e+01;
		
		asali_->thermo_[120].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[120].name,"C3-OQOOH");

		asali_->thermo_[120].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[120].high[0] = 1.1213253975e+01;
		asali_->thermo_[120].high[1] = 2.3470900953e-02;
		asali_->thermo_[120].high[2] = -1.1309831280e-05;
		asali_->thermo_[120].high[3] = 2.5900808165e-09;
		asali_->thermo_[120].high[4] = -2.3088527075e-13;
		asali_->thermo_[120].high[5] = -3.9128988281e+04;
		asali_->thermo_[120].high[6] = -2.6626003265e+01;

		asali_->thermo_[120].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[120].low[0] = 8.4622043371e-01;
		asali_->thermo_[120].low[1] = 5.4188039154e-02;
		asali_->thermo_[120].low[2] = -4.5439981477e-05;
		asali_->thermo_[120].low[3] = 1.9444476251e-08;
		asali_->thermo_[120].low[4] = -3.3520697069e-12;
		asali_->thermo_[120].low[5] = -3.6329890625e+04;
		asali_->thermo_[120].low[6] = 2.6500133514e+01;
		
		asali_->thermo_[121].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[121].name,"NC4-OQOOH");

		asali_->thermo_[121].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[121].high[0] = 1.1815344810e+01;
		asali_->thermo_[121].high[1] = 3.2009374350e-02;
		asali_->thermo_[121].high[2] = -1.5333498595e-05;
		asali_->thermo_[121].high[3] = 3.5031639811e-09;
		asali_->thermo_[121].high[4] = -3.1213654708e-13;
		asali_->thermo_[121].high[5] = -4.2766054688e+04;
		asali_->thermo_[121].high[6] = -2.7308320999e+01;

		asali_->thermo_[121].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[121].low[0] = 2.5194659233e+00;
		asali_->thermo_[121].low[1] = 5.9966903180e-02;
		asali_->thermo_[121].low[2] = -4.6864544856e-05;
		asali_->thermo_[121].low[3] = 1.9308201260e-08;
		asali_->thermo_[121].low[4] = -3.2830079801e-12;
		asali_->thermo_[121].low[5] = -4.0293351562e+04;
		asali_->thermo_[121].low[6] = 2.0189907074e+01;
		
		asali_->thermo_[122].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[122].name,"NC5-OQOOH");

		asali_->thermo_[122].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[122].high[0] = 1.4217263222e+01;
		asali_->thermo_[122].high[1] = 3.7770766765e-02;
		asali_->thermo_[122].high[2] = -1.7625794499e-05;
		asali_->thermo_[122].high[3] = 3.9344305591e-09;
		asali_->thermo_[122].high[4] = -3.4395424876e-13;
		asali_->thermo_[122].high[5] = -4.6506105469e+04;
		asali_->thermo_[122].high[6] = -3.8536918640e+01;

		asali_->thermo_[122].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[122].low[0] = 2.5274991989e+00;
		asali_->thermo_[122].low[1] = 7.0933215320e-02;
		asali_->thermo_[122].low[2] = -5.2904997574e-05;
		asali_->thermo_[122].low[3] = 2.0614903562e-08;
		asali_->thermo_[122].low[4] = -3.3014851703e-12;
		asali_->thermo_[122].low[5] = -4.3209589844e+04;
		asali_->thermo_[122].low[6] = 2.1875915527e+01;
		
		asali_->thermo_[123].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[123].name,"NC7-OQOOH");

		asali_->thermo_[123].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[123].high[0] = 2.2758411407e+01;
		asali_->thermo_[123].high[1] = 4.2574126273e-02;
		asali_->thermo_[123].high[2] = -1.7795000531e-05;
		asali_->thermo_[123].high[3] = 3.5539873267e-09;
		asali_->thermo_[123].high[4] = -2.8079180149e-13;
		asali_->thermo_[123].high[5] = -5.9532964844e+04;
		asali_->thermo_[123].high[6] = -8.1925163269e+01;

		asali_->thermo_[123].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[123].low[0] = 2.2499732971e+00;
		asali_->thermo_[123].low[1] = 9.1696135700e-02;
		asali_->thermo_[123].low[2] = -6.1916565755e-05;
		asali_->thermo_[123].low[3] = 2.1167386066e-08;
		asali_->thermo_[123].low[4] = -2.9175281982e-12;
		asali_->thermo_[123].low[5] = -5.2683148438e+04;
		asali_->thermo_[123].low[6] = 2.7533409119e+01;
		
		asali_->thermo_[124].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[124].name,"IC8-OQOOH");

		asali_->thermo_[124].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[124].high[0] = 3.3314090729e+01;
		asali_->thermo_[124].high[1] = 3.4830447286e-02;
		asali_->thermo_[124].high[2] = -1.1963218640e-05;
		asali_->thermo_[124].high[3] = 1.8571167937e-09;
		asali_->thermo_[124].high[4] = -1.0730943179e-13;
		asali_->thermo_[124].high[5] = -6.8827664062e+04;
		asali_->thermo_[124].high[6] = -1.4083409119e+02;

		asali_->thermo_[124].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[124].low[0] = 5.5514895916e-01;
		asali_->thermo_[124].low[1] = 1.0886196047e-01;
		asali_->thermo_[124].low[2] = -7.4701783888e-05;
		asali_->thermo_[124].low[3] = 2.5487462807e-08;
		asali_->thermo_[124].low[4] = -3.4449290209e-12;
		asali_->thermo_[124].low[5] = -5.7231000000e+04;
		asali_->thermo_[124].low[6] = 3.5913555145e+01;
		
		asali_->thermo_[125].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[125].name,"DME-OQOOH");

		asali_->thermo_[125].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[125].high[0] = 1.5496086121e+01;
		asali_->thermo_[125].high[1] = 1.5875810059e-03;
		asali_->thermo_[125].high[2] = 2.2442591217e-06;
		asali_->thermo_[125].high[3] = -9.7423724643e-10;
		asali_->thermo_[125].high[4] = 1.0377306246e-13;
		asali_->thermo_[125].high[5] = -4.6965542969e+04;
		asali_->thermo_[125].high[6] = -5.1840114594e+01;

		asali_->thermo_[125].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[125].low[0] = 3.6238896847e+00;
		asali_->thermo_[125].low[1] = 2.8569847345e-02;
		asali_->thermo_[125].low[2] = -2.0751989723e-05;
		asali_->thermo_[125].low[3] = 7.7364630258e-09;
		asali_->thermo_[125].low[4] = -1.1335423702e-12;
		asali_->thermo_[125].low[5] = -4.2786531250e+04;
		asali_->thermo_[125].low[6] = 1.2147887230e+01;
		
		asali_->thermo_[126].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[126].name,"NC10-OQOOH");

		asali_->thermo_[126].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[126].high[0] = 2.9908927917e+01;
		asali_->thermo_[126].high[1] = 5.8701638132e-02;
		asali_->thermo_[126].high[2] = -2.3795952075e-05;
		asali_->thermo_[126].high[3] = 4.6391481767e-09;
		asali_->thermo_[126].high[4] = -3.5965910697e-13;
		asali_->thermo_[126].high[5] = -7.0724648438e+04;
		asali_->thermo_[126].high[6] = -1.1460234070e+02;

		asali_->thermo_[126].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[126].low[0] = 2.8786551952e+00;
		asali_->thermo_[126].low[1] = 1.2422957271e-01;
		asali_->thermo_[126].low[2] = -8.3366801846e-05;
		asali_->thermo_[126].low[3] = 2.8708177169e-08;
		asali_->thermo_[126].low[4] = -4.0064817783e-12;
		asali_->thermo_[126].low[5] = -6.1804656250e+04;
		asali_->thermo_[126].low[6] = 2.9339187622e+01;
		
		asali_->thermo_[127].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[127].name,"NC12-OQOOH");

		asali_->thermo_[127].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[127].high[0] = 2.8976253510e+01;
		asali_->thermo_[127].high[1] = 8.5193507373e-02;
		asali_->thermo_[127].high[2] = -4.3222204113e-05;
		asali_->thermo_[127].high[3] = 1.0318489174e-08;
		asali_->thermo_[127].high[4] = -9.5287363069e-13;
		asali_->thermo_[127].high[5] = -7.6678445312e+04;
		asali_->thermo_[127].high[6] = -1.0715130615e+02;

		asali_->thermo_[127].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[127].low[0] = 4.9572339058e+00;
		asali_->thermo_[127].low[1] = 1.3856910169e-01;
		asali_->thermo_[127].low[2] = -8.7701868324e-05;
		asali_->thermo_[127].low[3] = 2.6792440266e-08;
		asali_->thermo_[127].low[4] = -3.2409222875e-12;
		asali_->thermo_[127].low[5] = -6.8031601562e+04;
		asali_->thermo_[127].low[6] = 2.2844644547e+01;
		
		asali_->thermo_[128].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[128].name,"IC16-OQOOH");

		asali_->thermo_[128].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[128].high[0] = 5.0310588837e+01;
		asali_->thermo_[128].high[1] = 8.8553503156e-02;
		asali_->thermo_[128].high[2] = -3.6307767004e-05;
		asali_->thermo_[128].high[3] = 7.1374719468e-09;
		asali_->thermo_[128].high[4] = -5.5669217066e-13;
		asali_->thermo_[128].high[5] = -1.0197807031e+05;
		asali_->thermo_[128].high[6] = -2.3034124756e+02;

		asali_->thermo_[128].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[128].low[0] = -5.9366865158e+00;
		asali_->thermo_[128].low[1] = 2.3005609214e-01;
		asali_->thermo_[128].low[2] = -1.6980076907e-04;
		asali_->thermo_[128].low[3] = 6.3109382609e-08;
		asali_->thermo_[128].low[4] = -9.3573065962e-12;
		asali_->thermo_[128].low[5] = -8.4091437500e+04;
		asali_->thermo_[128].low[6] = 6.7103118896e+01;
		
		asali_->thermo_[129].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[129].name,"MCYC6-OQOOH");

		asali_->thermo_[129].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[129].high[0] = 2.8924583435e+01;
		asali_->thermo_[129].high[1] = 2.8970263898e-02;
		asali_->thermo_[129].high[2] = -1.0080741049e-05;
		asali_->thermo_[129].high[3] = 1.6086134647e-09;
		asali_->thermo_[129].high[4] = -9.8137698055e-14;
		asali_->thermo_[129].high[5] = -5.9285808594e+04;
		asali_->thermo_[129].high[6] = -1.2960548401e+02;

		asali_->thermo_[129].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[129].low[0] = -5.1435852051e+00;
		asali_->thermo_[129].low[1] = 1.0467730463e-01;
		asali_->thermo_[129].low[2] = -7.3169940151e-05;
		asali_->thermo_[129].low[3] = 2.4974983859e-08;
		asali_->thermo_[129].low[4] = -3.3434669963e-12;
		asali_->thermo_[129].low[5] = -4.7021269531e+04;
		asali_->thermo_[129].low[6] = 5.4778545380e+01;
		
		asali_->thermo_[130].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[130].name,"MTBE-OQOOH");

		asali_->thermo_[130].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[130].high[0] = 2.6072757721e+01;
		asali_->thermo_[130].high[1] = 2.1656174213e-02;
		asali_->thermo_[130].high[2] = -7.5083703450e-06;
		asali_->thermo_[130].high[3] = 1.1809418998e-09;
		asali_->thermo_[130].high[4] = -6.9594666401e-14;
		asali_->thermo_[130].high[5] = -6.6076218750e+04;
		asali_->thermo_[130].high[6] = -1.0302058411e+02;

		asali_->thermo_[130].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[130].low[0] = 2.3924870491e+00;
		asali_->thermo_[130].low[1] = 7.5782507658e-02;
		asali_->thermo_[130].low[2] = -5.3902367654e-05;
		asali_->thermo_[130].low[3] = 1.8854846573e-08;
		asali_->thermo_[130].low[4] = -2.5944381192e-12;
		asali_->thermo_[130].low[5] = -5.7788121094e+04;
		asali_->thermo_[130].low[6] = 2.4474887848e+01;
		
		asali_->thermo_[131].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[131].name,"IC3H5CHO");

		asali_->thermo_[131].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[131].high[0] = 8.9660577774e+00;
		asali_->thermo_[131].high[1] = 2.2096239030e-02;
		asali_->thermo_[131].high[2] = -1.0090114301e-05;
		asali_->thermo_[131].high[3] = 2.2213928474e-09;
		asali_->thermo_[131].high[4] = -1.9179226078e-13;
		asali_->thermo_[131].high[5] = -1.7992009766e+04;
		asali_->thermo_[131].high[6] = -2.1193923950e+01;

		asali_->thermo_[131].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[131].low[0] = 6.9294196367e-01;
		asali_->thermo_[131].low[1] = 4.6251319349e-02;
		asali_->thermo_[131].low[2] = -3.6537283449e-05;
		asali_->thermo_[131].low[3] = 1.5091062622e-08;
		asali_->thermo_[131].low[4] = -2.5402720292e-12;
		asali_->thermo_[131].low[5] = -1.5725176758e+04;
		asali_->thermo_[131].low[6] = 2.1323541641e+01;
		
		asali_->thermo_[132].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[132].name,"MCYC6");

		asali_->thermo_[132].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[132].high[0] = 1.6719457626e+01;
		asali_->thermo_[132].high[1] = 4.3618064374e-02;
		asali_->thermo_[132].high[2] = -1.8777336663e-05;
		asali_->thermo_[132].high[3] = 3.9205900748e-09;
		asali_->thermo_[132].high[4] = -3.2670299300e-13;
		asali_->thermo_[132].high[5] = -2.9186630859e+04;
		asali_->thermo_[132].high[6] = -7.4061187744e+01;

		asali_->thermo_[132].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[132].low[0] = -1.0100635529e+01;
		asali_->thermo_[132].low[1] = 1.0321827233e-01;
		asali_->thermo_[132].low[2] = -6.8444176577e-05;
		asali_->thermo_[132].low[3] = 2.2315715498e-08;
		asali_->thermo_[132].low[4] = -2.8815814752e-12;
		asali_->thermo_[132].low[5] = -1.9531396484e+04;
		asali_->thermo_[132].low[6] = 7.1094749451e+01;
		
		asali_->thermo_[133].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[133].name,"CH3CHO");

		asali_->thermo_[133].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[133].high[0] = 6.2701811790e+00;
		asali_->thermo_[133].high[1] = 1.0620187037e-02;
		asali_->thermo_[133].high[2] = -3.8226467041e-06;
		asali_->thermo_[133].high[3] = 6.5634081503e-10;
		asali_->thermo_[133].high[4] = -4.6054956723e-14;
		asali_->thermo_[133].high[5] = -2.2979478516e+04;
		asali_->thermo_[133].high[6] = -8.6011924744e+00;

		asali_->thermo_[133].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[133].low[0] = 9.9175137281e-01;
		asali_->thermo_[133].low[1] = 2.2350031883e-02;
		asali_->thermo_[133].low[2] = -1.3597516954e-05;
		asali_->thermo_[133].low[3] = 4.2766630237e-09;
		asali_->thermo_[133].low[4] = -5.4887751245e-13;
		asali_->thermo_[133].low[5] = -2.1079244141e+04;
		asali_->thermo_[133].low[6] = 1.9966770172e+01;
		
		asali_->thermo_[134].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[134].name,"CH3CO3");

		asali_->thermo_[134].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[134].high[0] = 1.4046937943e+01;
		asali_->thermo_[134].high[1] = 2.4848342873e-03;
		asali_->thermo_[134].high[2] = 1.6590043970e-06;
		asali_->thermo_[134].high[3] = -8.5513396364e-10;
		asali_->thermo_[134].high[4] = 9.8228723603e-14;
		asali_->thermo_[134].high[5] = -2.7375681641e+04;
		asali_->thermo_[134].high[6] = -4.3681697845e+01;

		asali_->thermo_[134].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[134].low[0] = 2.6489255428e+00;
		asali_->thermo_[134].low[1] = 2.8389409184e-02;
		asali_->thermo_[134].low[2] = -2.0418758140e-05;
		asali_->thermo_[134].low[3] = 7.5076549422e-09;
		asali_->thermo_[134].low[4] = -1.0896674188e-12;
		asali_->thermo_[134].low[5] = -2.3363582031e+04;
		asali_->thermo_[134].low[6] = 1.7750577927e+01;
		
		asali_->thermo_[135].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[135].name,"C10H7CH3");

		asali_->thermo_[135].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[135].high[0] = 1.5971863747e+01;
		asali_->thermo_[135].high[1] = 4.8465609550e-02;
		asali_->thermo_[135].high[2] = -2.2712321879e-05;
		asali_->thermo_[135].high[3] = 5.0943733676e-09;
		asali_->thermo_[135].high[4] = -4.4743280803e-13;
		asali_->thermo_[135].high[5] = 5.3241201172e+03;
		asali_->thermo_[135].high[6] = -6.3541725159e+01;

		asali_->thermo_[135].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[135].low[0] = -7.8550591469e+00;
		asali_->thermo_[135].low[1] = 1.1654253304e-01;
		asali_->thermo_[135].low[2] = -9.5651877928e-05;
		asali_->thermo_[135].low[3] = 3.9827497744e-08;
		asali_->thermo_[135].low[4] = -6.6497762158e-12;
		asali_->thermo_[135].low[5] = 1.1995658203e+04;
		asali_->thermo_[135].low[6] = 5.9426498413e+01;
		
		asali_->thermo_[136].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[136].name,"CH3OO");

		asali_->thermo_[136].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[136].high[0] = 3.4652197361e+00;
		asali_->thermo_[136].high[1] = 1.2393851765e-02;
		asali_->thermo_[136].high[2] = -5.5961468206e-06;
		asali_->thermo_[136].high[3] = 1.2261671678e-09;
		asali_->thermo_[136].high[4] = -1.0623881603e-13;
		asali_->thermo_[136].high[5] = 6.8698229980e+02;
		asali_->thermo_[136].high[6] = 1.0429893494e+01;

		asali_->thermo_[136].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[136].low[0] = 4.3011722565e+00;
		asali_->thermo_[136].low[1] = 9.8216896877e-03;
		asali_->thermo_[136].low[2] = -2.6282673389e-06;
		asali_->thermo_[136].low[3] = -2.9582233885e-10;
		asali_->thermo_[136].low[4] = 1.8645148088e-13;
		asali_->thermo_[136].low[5] = 4.6963458252e+02;
		asali_->thermo_[136].low[6] = 6.1775803566e+00;
		
		asali_->thermo_[137].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[137].name,"CH3OOH");

		asali_->thermo_[137].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[137].high[0] = 5.5014653206e+00;
		asali_->thermo_[137].high[1] = 1.1397542432e-02;
		asali_->thermo_[137].high[2] = -3.8213083826e-06;
		asali_->thermo_[137].high[3] = 4.3870490574e-10;
		asali_->thermo_[137].high[4] = -2.9061747007e-15;
		asali_->thermo_[137].high[5] = -1.7978423828e+04;
		asali_->thermo_[137].high[6] = -4.6558141708e-01;

		asali_->thermo_[137].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[137].low[0] = 5.9343085289e+00;
		asali_->thermo_[137].low[1] = 1.0435667820e-02;
		asali_->thermo_[137].low[2] = -3.0197461456e-06;
		asali_->thermo_[137].low[3] = 1.4183000607e-10;
		asali_->thermo_[137].low[4] = 3.8326451930e-14;
		asali_->thermo_[137].low[5] = -1.8134248047e+04;
		asali_->thermo_[137].low[6] = -2.8082213402e+00;
		
		asali_->thermo_[138].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[138].name,"MTBE");

		asali_->thermo_[138].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[138].high[0] = 9.8525085449e+00;
		asali_->thermo_[138].high[1] = 4.0189620107e-02;
		asali_->thermo_[138].high[2] = -1.6670421246e-05;
		asali_->thermo_[138].high[3] = 3.1015894297e-09;
		asali_->thermo_[138].high[4] = -2.1153780496e-13;
		asali_->thermo_[138].high[5] = -4.0927421875e+04;
		asali_->thermo_[138].high[6] = -2.6194110870e+01;

		asali_->thermo_[138].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[138].low[0] = -1.8585642576e+00;
		asali_->thermo_[138].low[1] = 7.5677715242e-02;
		asali_->thermo_[138].low[2] = -5.6997807405e-05;
		asali_->thermo_[138].low[3] = 2.3468956556e-08;
		asali_->thermo_[138].low[4] = -4.0689934061e-12;
		asali_->thermo_[138].low[5] = -3.7835699219e+04;
		asali_->thermo_[138].low[6] = 3.3556411743e+01;
		
		asali_->thermo_[139].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->thermo_[139].name,"N2");

		asali_->thermo_[139].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[139].high[0] = 2.7128789425e+00;
		asali_->thermo_[139].high[1] = 1.9035974983e-03;
		asali_->thermo_[139].high[2] = -8.5429758201e-07;
		asali_->thermo_[139].high[3] = 1.8417094239e-10;
		asali_->thermo_[139].high[4] = -1.5471598883e-14;
		asali_->thermo_[139].high[5] = -8.4022528076e+02;
		asali_->thermo_[139].high[6] = 7.1592655182e+00;

		asali_->thermo_[139].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[139].low[0] = 3.8532133102e+00;
		asali_->thermo_[139].low[1] = -2.4405336007e-03;
		asali_->thermo_[139].low[2] = 5.3516037042e-06;
		asali_->thermo_[139].low[3] = -3.7560838884e-09;
		asali_->thermo_[139].low[4] = 9.2268434646e-13;
		asali_->thermo_[139].low[5] = -1.0796955566e+03;
		asali_->thermo_[139].low[6] = 1.6021741629e+00;
		
		asali_->thermo_[140].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[140].name,"C10H7OH");

		asali_->thermo_[140].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[140].high[0] = 2.6181821823e+01;
		asali_->thermo_[140].high[1] = 2.4707922712e-02;
		asali_->thermo_[140].high[2] = -8.7547296062e-06;
		asali_->thermo_[140].high[3] = 1.4121320779e-09;
		asali_->thermo_[140].high[4] = -8.6158036543e-14;
		asali_->thermo_[140].high[5] = -1.5833869141e+04;
		asali_->thermo_[140].high[6] = -1.1931431580e+02;

		asali_->thermo_[140].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[140].low[0] = -3.0919461250e+00;
		asali_->thermo_[140].low[1] = 9.2392936349e-02;
		asali_->thermo_[140].low[2] = -6.7441156716e-05;
		asali_->thermo_[140].low[3] = 2.4027325907e-08;
		asali_->thermo_[140].low[4] = -3.3542496038e-12;
		asali_->thermo_[140].low[5] = -5.7051450195e+03;
		asali_->thermo_[140].low[6] = 3.7960273743e+01;
		
		asali_->thermo_[141].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[141].name,"C10H7CHO");

		asali_->thermo_[141].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[141].high[0] = 2.7687387466e+01;
		asali_->thermo_[141].high[1] = 2.6515355334e-02;
		asali_->thermo_[141].high[2] = -9.8523069028e-06;
		asali_->thermo_[141].high[3] = 1.7349205406e-09;
		asali_->thermo_[141].high[4] = -1.2169994559e-13;
		asali_->thermo_[141].high[5] = -1.0892626953e+04;
		asali_->thermo_[141].high[6] = -1.2564569855e+02;

		asali_->thermo_[141].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[141].low[0] = -1.8064520359e+00;
		asali_->thermo_[141].low[1] = 9.2057220638e-02;
		asali_->thermo_[141].low[2] = -6.4470528741e-05;
		asali_->thermo_[141].low[3] = 2.1963890262e-08;
		asali_->thermo_[141].low[4] = -2.9312791344e-12;
		asali_->thermo_[141].low[5] = -2.7484497070e+02;
		asali_->thermo_[141].low[6] = 3.3981105804e+01;
		
		asali_->thermo_[142].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[142].name,"CH3C10H6OH");

		asali_->thermo_[142].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[142].high[0] = 2.9119186401e+01;
		asali_->thermo_[142].high[1] = 2.8645129874e-02;
		asali_->thermo_[142].high[2] = -9.8009822977e-06;
		asali_->thermo_[142].high[3] = 1.5137407994e-09;
		asali_->thermo_[142].high[4] = -8.7223793726e-14;
		asali_->thermo_[142].high[5] = -2.1362671875e+04;
		asali_->thermo_[142].high[6] = -1.3266011047e+02;

		asali_->thermo_[142].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[142].low[0] = -1.7684181929e+00;
		asali_->thermo_[142].low[1] = 9.7284249961e-02;
		asali_->thermo_[142].low[2] = -6.7000248237e-05;
		asali_->thermo_[142].low[3] = 2.2698655400e-08;
		asali_->thermo_[142].low[4] = -3.0295729033e-12;
		asali_->thermo_[142].low[5] = -1.0243132812e+04;
		asali_->thermo_[142].low[6] = 3.4510047913e+01;
		
		asali_->thermo_[143].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[143].name,"CH3C10H6O");

		asali_->thermo_[143].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[143].high[0] = 2.6093662262e+01;
		asali_->thermo_[143].high[1] = 3.2495498657e-02;
		asali_->thermo_[143].high[2] = -1.3048062101e-05;
		asali_->thermo_[143].high[3] = 2.5226090106e-09;
		asali_->thermo_[143].high[4] = -1.9549239885e-13;
		asali_->thermo_[143].high[5] = -2.8739699707e+03;
		asali_->thermo_[143].high[6] = -1.1490513611e+02;

		asali_->thermo_[143].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[143].low[0] = -1.8505948782e+00;
		asali_->thermo_[143].low[1] = 9.4593845308e-02;
		asali_->thermo_[143].low[2] = -6.4796688093e-05;
		asali_->thermo_[143].low[3] = 2.1688766338e-08;
		asali_->thermo_[143].low[4] = -2.8574586274e-12;
		asali_->thermo_[143].low[5] = 7.1859628906e+03;
		asali_->thermo_[143].low[6] = 3.6335010529e+01;
		
		asali_->thermo_[144].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[144].name,"NC4H9P");

		asali_->thermo_[144].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[144].high[0] = 3.9476301670e+00;
		asali_->thermo_[144].high[1] = 3.1628638506e-02;
		asali_->thermo_[144].high[2] = -1.1298487152e-05;
		asali_->thermo_[144].high[3] = 1.1163745484e-09;
		asali_->thermo_[144].high[4] = 5.5403157919e-14;
		asali_->thermo_[144].high[5] = 6.0555473633e+03;
		asali_->thermo_[144].high[6] = 7.7635006905e+00;

		asali_->thermo_[144].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[144].low[0] = -2.7618837357e-01;
		asali_->thermo_[144].low[1] = 4.9413137138e-02;
		asali_->thermo_[144].low[2] = -3.9379272494e-05;
		asali_->thermo_[144].low[3] = 2.0822190194e-08;
		asali_->thermo_[144].low[4] = -5.1303379947e-12;
		asali_->thermo_[144].low[5] = 6.8580727539e+03;
		asali_->thermo_[144].low[6] = 2.7924329758e+01;
		
		asali_->thermo_[145].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[145].name,"NC4H9S");

		asali_->thermo_[145].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[145].high[0] = 3.4012291431e+00;
		asali_->thermo_[145].high[1] = 3.2090187073e-02;
		asali_->thermo_[145].high[2] = -1.1225547496e-05;
		asali_->thermo_[145].high[3] = 9.7171215518e-10;
		asali_->thermo_[145].high[4] = 8.3072627553e-14;
		asali_->thermo_[145].high[5] = 4.6628310547e+03;
		asali_->thermo_[145].high[6] = 1.0529164314e+01;

		asali_->thermo_[145].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[145].low[0] = 2.3633646965e-01;
		asali_->thermo_[145].low[1] = 4.6983800828e-02;
		asali_->thermo_[145].low[2] = -3.7508394598e-05;
		asali_->thermo_[145].low[3] = 2.1585709220e-08;
		asali_->thermo_[145].low[4] = -5.9798676427e-12;
		asali_->thermo_[145].low[5] = 5.2008627930e+03;
		asali_->thermo_[145].low[6] = 2.5283586502e+01;
		
		asali_->thermo_[146].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[146].name,"NC4H10");

		asali_->thermo_[146].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[146].high[0] = 1.5435536385e+01;
		asali_->thermo_[146].high[1] = 1.5627255663e-02;
		asali_->thermo_[146].high[2] = -3.1485199088e-06;
		asali_->thermo_[146].high[3] = -5.9442416267e-11;
		asali_->thermo_[146].high[4] = 5.3296465006e-14;
		asali_->thermo_[146].high[5] = -2.2845525391e+04;
		asali_->thermo_[146].high[6] = -6.0241783142e+01;

		asali_->thermo_[146].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[146].low[0] = -1.2083675861e+00;
		asali_->thermo_[146].low[1] = 5.2613709122e-02;
		asali_->thermo_[146].low[2] = -3.3970565710e-05;
		asali_->thermo_[146].low[3] = 1.1356129370e-08;
		asali_->thermo_[146].low[4] = -1.5321996059e-12;
		asali_->thermo_[146].low[5] = -1.6853720703e+04;
		asali_->thermo_[146].low[6] = 2.9838495255e+01;
		
		asali_->thermo_[147].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[147].name,"NC10H22");

		asali_->thermo_[147].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[147].high[0] = 2.9287891388e+01;
		asali_->thermo_[147].high[1] = 5.2992098033e-02;
		asali_->thermo_[147].high[2] = -1.9840455934e-05;
		asali_->thermo_[147].high[3] = 3.5561638079e-09;
		asali_->thermo_[147].high[4] = -2.5428118812e-13;
		asali_->thermo_[147].high[5] = -4.5623238281e+04;
		asali_->thermo_[147].high[6] = -1.2275204468e+02;

		asali_->thermo_[147].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[147].low[0] = -2.1787014008e+00;
		asali_->thermo_[147].low[1] = 1.2291786075e-01;
		asali_->thermo_[147].low[2] = -7.8111923358e-05;
		asali_->thermo_[147].low[3] = 2.5138188420e-08;
		asali_->thermo_[147].low[4] = -3.2517846922e-12;
		asali_->thermo_[147].low[5] = -3.4295265625e+04;
		asali_->thermo_[147].low[6] = 4.7551719666e+01;
		
		asali_->thermo_[148].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[148].name,"NC12H26");

		asali_->thermo_[148].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[148].high[0] = 3.6141410828e+01;
		asali_->thermo_[148].high[1] = 6.1104588211e-02;
		asali_->thermo_[148].high[2] = -2.2464108042e-05;
		asali_->thermo_[148].high[3] = 3.9318241996e-09;
		asali_->thermo_[148].high[4] = -2.7334934988e-13;
		asali_->thermo_[148].high[5] = -5.4035917969e+04;
		asali_->thermo_[148].high[6] = -1.5683195496e+02;

		asali_->thermo_[148].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[148].low[0] = -2.6662769318e+00;
		asali_->thermo_[148].low[1] = 1.4734388888e-01;
		asali_->thermo_[148].low[2] = -9.4330192951e-05;
		asali_->thermo_[148].low[3] = 3.0548893193e-08;
		asali_->thermo_[148].low[4] = -3.9701644750e-12;
		asali_->thermo_[148].low[5] = -4.0065152344e+04;
		asali_->thermo_[148].low[6] = 5.3203334808e+01;
		
		asali_->thermo_[149].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[149].name,"NC5H12");

		asali_->thermo_[149].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[149].high[0] = 2.1255908966e+01;
		asali_->thermo_[149].high[1] = 1.4986637048e-02;
		asali_->thermo_[149].high[2] = -1.5673831513e-06;
		asali_->thermo_[149].high[3] = -4.8451842538e-10;
		asali_->thermo_[149].high[4] = 9.0043647722e-14;
		asali_->thermo_[149].high[5] = -2.8066871094e+04;
		asali_->thermo_[149].high[6] = -9.0549766541e+01;

		asali_->thermo_[149].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[149].low[0] = -1.9700086117e+00;
		asali_->thermo_[149].low[1] = 6.6599786282e-02;
		asali_->thermo_[149].low[2] = -4.4578340749e-05;
		asali_->thermo_[149].low[3] = 1.5445465351e-08;
		asali_->thermo_[149].low[4] = -2.1224541222e-12;
		asali_->thermo_[149].low[5] = -1.9705541016e+04;
		asali_->thermo_[149].low[6] = 3.5153739929e+01;
		
		asali_->thermo_[150].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[150].name,"NC7H16");

		asali_->thermo_[150].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[150].high[0] = 3.1069612503e+01;
		asali_->thermo_[150].high[1] = 1.7345886678e-02;
		asali_->thermo_[150].high[2] = -4.5766387302e-07;
		asali_->thermo_[150].high[3] = -1.0628096181e-09;
		asali_->thermo_[150].high[4] = 1.5909886256e-13;
		asali_->thermo_[150].high[5] = -3.7654160156e+04;
		asali_->thermo_[150].high[6] = -1.4092050171e+02;

		asali_->thermo_[150].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[150].low[0] = -2.7691280842e+00;
		asali_->thermo_[150].low[1] = 9.2543087900e-02;
		asali_->thermo_[150].low[2] = -6.3121995481e-05;
		asali_->thermo_[150].low[3] = 2.2146203094e-08;
		asali_->thermo_[150].low[4] = -3.0643751425e-12;
		asali_->thermo_[150].low[5] = -2.5472212891e+04;
		asali_->thermo_[150].low[6] = 4.2221824646e+01;
		
		asali_->thermo_[151].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[151].name,"NEOC5H12");

		asali_->thermo_[151].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[151].high[0] = 1.5822081566e+01;
		asali_->thermo_[151].high[1] = 2.7382407337e-02;
		asali_->thermo_[151].high[2] = -1.0139257938e-05;
		asali_->thermo_[151].high[3] = 1.7770700467e-09;
		asali_->thermo_[151].high[4] = -1.2275697494e-13;
		asali_->thermo_[151].high[5] = -2.8519701172e+04;
		asali_->thermo_[151].high[6] = -6.6248855591e+01;

		asali_->thermo_[151].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[151].low[0] = -2.6246345043e+00;
		asali_->thermo_[151].low[1] = 7.0786446333e-02;
		asali_->thermo_[151].low[2] = -4.8436937504e-05;
		asali_->thermo_[151].low[3] = 1.6795768332e-08;
		asali_->thermo_[151].low[4] = -2.3313889881e-12;
		asali_->thermo_[151].low[5] = -2.2247818359e+04;
		asali_->thermo_[151].low[6] = 3.2534236908e+01;
		
		asali_->thermo_[152].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[152].name,"NC3H7");

		asali_->thermo_[152].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[152].high[0] = 8.4469299316e+00;
		asali_->thermo_[152].high[1] = 1.5288101509e-02;
		asali_->thermo_[152].high[2] = -4.7239423111e-06;
		asali_->thermo_[152].high[3] = 3.7205377668e-10;
		asali_->thermo_[152].high[4] = 2.7782540062e-14;
		asali_->thermo_[152].high[5] = 7.2449946289e+03;
		asali_->thermo_[152].high[6] = -1.9765207291e+01;

		asali_->thermo_[152].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[152].low[0] = 5.4013025761e-01;
		asali_->thermo_[152].low[1] = 3.4456100315e-02;
		asali_->thermo_[152].low[2] = -2.2149395591e-05;
		asali_->thermo_[152].low[3] = 7.4126407235e-09;
		asali_->thermo_[152].low[4] = -1.0389730526e-12;
		asali_->thermo_[152].low[5] = 9.8542382812e+03;
		asali_->thermo_[152].low[6] = 2.2340059280e+01;
		
		asali_->thermo_[153].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[153].name,"NC3H7OO");

		asali_->thermo_[153].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[153].high[0] = 9.2559185028e+00;
		asali_->thermo_[153].high[1] = 2.2756380960e-02;
		asali_->thermo_[153].high[2] = -9.5493442132e-06;
		asali_->thermo_[153].high[3] = 1.9255945727e-09;
		asali_->thermo_[153].high[4] = -1.5394666607e-13;
		asali_->thermo_[153].high[5] = -9.3400507812e+03;
		asali_->thermo_[153].high[6] = -1.8638807297e+01;

		asali_->thermo_[153].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[153].low[0] = 1.9296439886e+00;
		asali_->thermo_[153].low[1] = 4.0517047048e-02;
		asali_->thermo_[153].low[2] = -2.5695404474e-05;
		asali_->thermo_[153].low[3] = 8.4492555175e-09;
		asali_->thermo_[153].low[4] = -1.1423800274e-12;
		asali_->thermo_[153].low[5] = -6.9223803711e+03;
		asali_->thermo_[153].low[6] = 2.0375049591e+01;
		
		asali_->thermo_[154].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[154].name,"NC3-QOOH");

		asali_->thermo_[154].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[154].high[0] = 1.2974862099e+01;
		asali_->thermo_[154].high[1] = 1.7643386498e-02;
		asali_->thermo_[154].high[2] = -7.1693539212e-06;
		asali_->thermo_[154].high[3] = 1.4269615489e-09;
		asali_->thermo_[154].high[4] = -1.1447704492e-13;
		asali_->thermo_[154].high[5] = -5.8641181641e+03;
		asali_->thermo_[154].high[6] = -3.6769050598e+01;

		asali_->thermo_[154].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[154].low[0] = 1.5564329624e+00;
		asali_->thermo_[154].low[1] = 4.3017674237e-02;
		asali_->thermo_[154].low[2] = -2.8314592782e-05;
		asali_->thermo_[154].low[3] = 9.2585317191e-09;
		asali_->thermo_[154].low[4] = -1.2021950276e-12;
		asali_->thermo_[154].low[5] = -1.7534838867e+03;
		asali_->thermo_[154].low[6] = 2.5029869080e+01;
		
		asali_->thermo_[155].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[155].name,"NC3-OOQOOH");

		asali_->thermo_[155].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[155].high[0] = 1.1168355942e+01;
		asali_->thermo_[155].high[1] = 2.9582213610e-02;
		asali_->thermo_[155].high[2] = -1.4252630535e-05;
		asali_->thermo_[155].high[3] = 3.2712685893e-09;
		asali_->thermo_[155].high[4] = -2.9247681750e-13;
		asali_->thermo_[155].high[5] = -2.0028121094e+04;
		asali_->thermo_[155].high[6] = -2.0628984451e+01;

		asali_->thermo_[155].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[155].low[0] = 2.5758869648e+00;
		asali_->thermo_[155].low[1] = 5.6859895587e-02;
		asali_->thermo_[155].low[2] = -4.6726057917e-05;
		asali_->thermo_[155].low[3] = 2.0452976202e-08;
		asali_->thermo_[155].low[4] = -3.7015460141e-12;
		asali_->thermo_[155].low[5] = -1.7862820312e+04;
		asali_->thermo_[155].low[6] = 2.2810533524e+01;
		
		asali_->thermo_[156].name = (char*) malloc(1 * sizeof(char));
		strcpy(asali_->thermo_[156].name,"O");

		asali_->thermo_[156].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[156].high[0] = 2.5731835365e+00;
		asali_->thermo_[156].high[1] = -8.9560999186e-05;
		asali_->thermo_[156].high[2] = 4.0509629429e-08;
		asali_->thermo_[156].high[3] = -8.3981268120e-12;
		asali_->thermo_[156].high[4] = 9.4362202005e-16;
		asali_->thermo_[156].high[5] = 2.9219140625e+04;
		asali_->thermo_[156].high[6] = 4.7495203018e+00;

		asali_->thermo_[156].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[156].low[0] = 2.9520032406e+00;
		asali_->thermo_[156].low[1] = -1.6845912905e-03;
		asali_->thermo_[156].low[2] = 2.5589786219e-06;
		asali_->thermo_[156].low[3] = -1.7757447734e-09;
		asali_->thermo_[156].low[4] = 4.6603481707e-13;
		asali_->thermo_[156].low[5] = 2.9147166016e+04;
		asali_->thermo_[156].low[6] = 2.9413650036e+00;
		
		asali_->thermo_[157].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->thermo_[157].name,"O2");

		asali_->thermo_[157].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[157].high[0] = 2.8175065517e+00;
		asali_->thermo_[157].high[1] = 2.4983801413e-03;
		asali_->thermo_[157].high[2] = -1.5249352145e-06;
		asali_->thermo_[157].high[3] = 4.5054759923e-10;
		asali_->thermo_[157].high[4] = -4.8770280078e-14;
		asali_->thermo_[157].high[5] = -9.3171337891e+02;
		asali_->thermo_[157].high[6] = 7.9472932816e+00;

		asali_->thermo_[157].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[157].low[0] = 3.4603507519e+00;
		asali_->thermo_[157].low[1] = -8.8501110440e-04;
		asali_->thermo_[157].low[2] = 5.1528104450e-06;
		asali_->thermo_[157].low[3] = -5.4071240818e-09;
		asali_->thermo_[157].low[4] = 1.8780953355e-12;
		asali_->thermo_[157].low[5] = -1.0294257812e+03;
		asali_->thermo_[157].low[6] = 5.0223612785e+00;
		
		asali_->thermo_[158].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->thermo_[158].name,"OH");

		asali_->thermo_[158].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[158].high[0] = 3.6253843307e+00;
		asali_->thermo_[158].high[1] = -5.0216529053e-04;
		asali_->thermo_[158].high[2] = 8.3695846342e-07;
		asali_->thermo_[158].high[3] = -2.9571453619e-10;
		asali_->thermo_[158].high[4] = 3.3035047273e-14;
		asali_->thermo_[158].high[5] = 3.4138010254e+03;
		asali_->thermo_[158].high[6] = 1.5541944504e+00;

		asali_->thermo_[158].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[158].low[0] = 3.3799510002e+00;
		asali_->thermo_[158].low[1] = 6.1344052665e-04;
		asali_->thermo_[158].low[2] = -1.0646423334e-06;
		asali_->thermo_[158].low[3] = 1.1448921811e-09;
		asali_->thermo_[158].low[4] = -3.7622820983e-13;
		asali_->thermo_[158].low[5] = 3.4569973145e+03;
		asali_->thermo_[158].low[6] = 2.7068934441e+00;
		
		asali_->thermo_[159].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[159].name,"IC8H16");

		asali_->thermo_[159].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[159].high[0] = 1.8861606598e+01;
		asali_->thermo_[159].high[1] = 4.1429281235e-02;
		asali_->thermo_[159].high[2] = -1.2817054085e-05;
		asali_->thermo_[159].high[3] = 1.6680673509e-09;
		asali_->thermo_[159].high[4] = -6.5896168188e-14;
		asali_->thermo_[159].high[5] = -2.2468406250e+04;
		asali_->thermo_[159].high[6] = -7.3851432800e+01;

		asali_->thermo_[159].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[159].low[0] = -5.3558659554e+00;
		asali_->thermo_[159].low[1] = 1.1062205583e-01;
		asali_->thermo_[159].low[2] = -8.6952175479e-05;
		asali_->thermo_[159].low[3] = 3.6970504880e-08;
		asali_->thermo_[159].low[4] = -6.3699028691e-12;
		asali_->thermo_[159].low[5] = -1.5687514648e+04;
		asali_->thermo_[159].low[6] = 5.1132381439e+01;
		
		asali_->thermo_[160].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[160].name,"NC5H10");

		asali_->thermo_[160].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[160].high[0] = 1.1192973137e+01;
		asali_->thermo_[160].high[1] = 2.8258223087e-02;
		asali_->thermo_[160].high[2] = -1.1386384358e-05;
		asali_->thermo_[160].high[3] = 2.2252648613e-09;
		asali_->thermo_[160].high[4] = -1.7428098624e-13;
		asali_->thermo_[160].high[5] = -1.0248344727e+04;
		asali_->thermo_[160].high[6] = -3.3925354004e+01;

		asali_->thermo_[160].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[160].low[0] = -6.8955194950e-01;
		asali_->thermo_[160].low[1] = 5.4663833231e-02;
		asali_->thermo_[160].low[2] = -3.3391061152e-05;
		asali_->thermo_[160].low[3] = 1.0375145187e-08;
		asali_->thermo_[160].low[4] = -1.3062088303e-12;
		asali_->thermo_[160].low[5] = -5.9706352539e+03;
		asali_->thermo_[160].low[6] = 3.0385354996e+01;
		
		asali_->thermo_[161].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[161].name,"PC3H4");

		asali_->thermo_[161].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[161].high[0] = 3.0415658951e+00;
		asali_->thermo_[161].high[1] = 1.8073292449e-02;
		asali_->thermo_[161].high[2] = -9.1984948085e-06;
		asali_->thermo_[161].high[3] = 2.2916157860e-09;
		asali_->thermo_[161].high[4] = -2.2568944868e-13;
		asali_->thermo_[161].high[5] = 2.0621425781e+04;
		asali_->thermo_[161].high[6] = 7.3749389648e+00;

		asali_->thermo_[161].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[161].low[0] = 1.3594318628e+00;
		asali_->thermo_[161].low[1] = 2.5386918336e-02;
		asali_->thermo_[161].low[2] = -2.1122885300e-05;
		asali_->thermo_[161].low[3] = 1.0932478922e-08;
		asali_->thermo_[161].low[4] = -2.5737500239e-12;
		asali_->thermo_[161].low[5] = 2.0930937500e+04;
		asali_->thermo_[161].low[6] = 1.5350004196e+01;
		
		asali_->thermo_[162].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[162].name,"CH3CO3H");

		asali_->thermo_[162].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[162].high[0] = 1.5496086121e+01;
		asali_->thermo_[162].high[1] = 1.5875810059e-03;
		asali_->thermo_[162].high[2] = 2.2442591217e-06;
		asali_->thermo_[162].high[3] = -9.7423724643e-10;
		asali_->thermo_[162].high[4] = 1.0377306246e-13;
		asali_->thermo_[162].high[5] = -4.6965542969e+04;
		asali_->thermo_[162].high[6] = -5.1840114594e+01;

		asali_->thermo_[162].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[162].low[0] = 3.6238896847e+00;
		asali_->thermo_[162].low[1] = 2.8569847345e-02;
		asali_->thermo_[162].low[2] = -2.0751989723e-05;
		asali_->thermo_[162].low[3] = 7.7364630258e-09;
		asali_->thermo_[162].low[4] = -1.1335423702e-12;
		asali_->thermo_[162].low[5] = -4.2786531250e+04;
		asali_->thermo_[162].low[6] = 1.2147887230e+01;
		
		asali_->thermo_[163].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[163].name,"HCO3H");

		asali_->thermo_[163].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[163].high[0] = 1.0023066521e+01;
		asali_->thermo_[163].high[1] = 4.4356323779e-03;
		asali_->thermo_[163].high[2] = -1.5618851421e-06;
		asali_->thermo_[163].high[3] = 2.4342439175e-10;
		asali_->thermo_[163].high[4] = -1.3839137694e-14;
		asali_->thermo_[163].high[5] = -3.8131332031e+04;
		asali_->thermo_[163].high[6] = -2.3359071732e+01;

		asali_->thermo_[163].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[163].low[0] = 2.4743421078e+00;
		asali_->thermo_[163].low[1] = 2.1689860150e-02;
		asali_->thermo_[163].low[2] = -1.6351223167e-05;
		asali_->thermo_[163].low[3] = 5.8774580758e-09;
		asali_->thermo_[163].low[4] = -8.1870106397e-13;
		asali_->thermo_[163].low[5] = -3.5489281250e+04;
		asali_->thermo_[163].low[6] = 1.7283546448e+01;
		
		asali_->thermo_[164].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[164].name,"C3H6O");

		asali_->thermo_[164].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[164].high[0] = 6.4275488853e+00;
		asali_->thermo_[164].high[1] = 2.0081851631e-02;
		asali_->thermo_[164].high[2] = -6.5546469159e-06;
		asali_->thermo_[164].high[3] = 4.8430681687e-10;
		asali_->thermo_[164].high[4] = 5.6889368704e-14;
		asali_->thermo_[164].high[5] = -1.4803572266e+04;
		asali_->thermo_[164].high[6] = -9.7199506760e+00;

		asali_->thermo_[164].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[164].low[0] = -9.9978081882e-02;
		asali_->thermo_[164].low[1] = 3.5262148827e-02;
		asali_->thermo_[164].low[2] = -1.9793276806e-05;
		asali_->thermo_[164].low[3] = 5.6155586847e-09;
		asali_->thermo_[164].low[4] = -6.8893214701e-13;
		asali_->thermo_[164].low[5] = -1.2558103516e+04;
		asali_->thermo_[164].low[6] = 2.5311632156e+01;
		
		asali_->thermo_[165].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[165].name,"C5H8");

		asali_->thermo_[165].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[165].high[0] = 8.9582920074e+00;
		asali_->thermo_[165].high[1] = 2.5103300810e-02;
		asali_->thermo_[165].high[2] = -8.4367920863e-06;
		asali_->thermo_[165].high[3] = 8.1990564338e-10;
		asali_->thermo_[165].high[4] = 3.1142650308e-14;
		asali_->thermo_[165].high[5] = 4.6795332031e+03;
		asali_->thermo_[165].high[6] = -2.4043962479e+01;

		asali_->thermo_[165].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[165].low[0] = 1.1918350458e+00;
		asali_->thermo_[165].low[1] = 4.6827655286e-02;
		asali_->thermo_[165].low[2] = -3.1224575650e-05;
		asali_->thermo_[165].low[3] = 1.1443581194e-08;
		asali_->thermo_[165].low[4] = -1.8261431863e-12;
		asali_->thermo_[165].low[5] = 6.9007397461e+03;
		asali_->thermo_[165].low[6] = 1.6202564240e+01;
		
		asali_->thermo_[166].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[166].name,"C16H10");

		asali_->thermo_[166].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[166].high[0] = 3.5520595551e+01;
		asali_->thermo_[166].high[1] = 2.9705923051e-02;
		asali_->thermo_[166].high[2] = -5.1857741710e-06;
		asali_->thermo_[166].high[3] = -7.7497658291e-10;
		asali_->thermo_[166].high[4] = 2.0576430642e-13;
		asali_->thermo_[166].high[5] = 1.1399803711e+04;
		asali_->thermo_[166].high[6] = -1.7258465576e+02;

		asali_->thermo_[166].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[166].low[0] = -1.4314951897e+01;
		asali_->thermo_[166].low[1] = 1.6910605133e-01;
		asali_->thermo_[166].low[2] = -1.5140969481e-04;
		asali_->thermo_[166].low[3] = 6.7394680059e-08;
		asali_->thermo_[166].low[4] = -1.1712008099e-11;
		asali_->thermo_[166].low[5] = 2.5652769531e+04;
		asali_->thermo_[166].low[6] = 8.5667961121e+01;
		
		asali_->thermo_[167].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[167].name,"NC10-QOOH");

		asali_->thermo_[167].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[167].high[0] = 3.6771453857e+01;
		asali_->thermo_[167].high[1] = 4.5678719878e-02;
		asali_->thermo_[167].high[2] = -1.5692925444e-05;
		asali_->thermo_[167].high[3] = 2.4997925951e-09;
		asali_->thermo_[167].high[4] = -1.5346729963e-13;
		asali_->thermo_[167].high[5] = -3.7289742188e+04;
		asali_->thermo_[167].high[6] = -1.5470898438e+02;

		asali_->thermo_[167].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[167].low[0] = 8.4653365612e-01;
		asali_->thermo_[167].low[1] = 1.2551186979e-01;
		asali_->thermo_[167].low[2] = -8.2220554759e-05;
		asali_->thermo_[167].low[3] = 2.7139655856e-08;
		asali_->thermo_[167].low[4] = -3.5756705756e-12;
		asali_->thermo_[167].low[5] = -2.4356769531e+04;
		asali_->thermo_[167].low[6] = 3.9724178314e+01;
		
		asali_->thermo_[168].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[168].name,"NC12-QOOH");

		asali_->thermo_[168].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[168].high[0] = 4.2876373291e+01;
		asali_->thermo_[168].high[1] = 5.5101163685e-02;
		asali_->thermo_[168].high[2] = -1.9060256818e-05;
		asali_->thermo_[168].high[3] = 3.0579150323e-09;
		asali_->thermo_[168].high[4] = -1.8921748391e-13;
		asali_->thermo_[168].high[5] = -4.5397398438e+04;
		asali_->thermo_[168].high[6] = -1.8460646057e+02;

		asali_->thermo_[168].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[168].low[0] = 5.2738934755e-01;
		asali_->thermo_[168].low[1] = 1.4921002090e-01;
		asali_->thermo_[168].low[2] = -9.7484298749e-05;
		asali_->thermo_[168].low[3] = 3.2103859127e-08;
		asali_->thermo_[168].low[4] = -4.2233759892e-12;
		asali_->thermo_[168].low[5] = -3.0151763672e+04;
		asali_->thermo_[168].low[6] = 4.4595081329e+01;
		
		asali_->thermo_[169].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[169].name,"C2-QOOH");

		asali_->thermo_[169].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[169].high[0] = 7.8568577766e+00;
		asali_->thermo_[169].high[1] = 1.6791122034e-02;
		asali_->thermo_[169].high[2] = -7.7962167779e-06;
		asali_->thermo_[169].high[3] = 1.7378246620e-09;
		asali_->thermo_[169].high[4] = -1.5198294554e-13;
		asali_->thermo_[169].high[5] = 7.2024884033e+02;
		asali_->thermo_[169].high[6] = -1.0688718796e+01;

		asali_->thermo_[169].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[169].low[0] = 8.2429581881e-01;
		asali_->thermo_[169].low[1] = 3.8940921426e-02;
		asali_->thermo_[169].low[2] = -3.3957399864e-05;
		asali_->thermo_[169].low[3] = 1.5470728698e-08;
		asali_->thermo_[169].low[4] = -2.8553106060e-12;
		asali_->thermo_[169].low[5] = 2.5065195312e+03;
		asali_->thermo_[169].low[6] = 2.4920228958e+01;
		
		asali_->thermo_[170].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[170].name,"C2-OOQOOH");

		asali_->thermo_[170].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[170].high[0] = 1.2432324409e+01;
		asali_->thermo_[170].high[1] = 1.6235893592e-02;
		asali_->thermo_[170].high[2] = -6.8426033977e-06;
		asali_->thermo_[170].high[3] = 1.3926743092e-09;
		asali_->thermo_[170].high[4] = -1.1291112495e-13;
		asali_->thermo_[170].high[5] = -1.8764111328e+04;
		asali_->thermo_[170].high[6] = -2.9090677261e+01;

		asali_->thermo_[170].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[170].low[0] = 5.8191151619e+00;
		asali_->thermo_[170].low[1] = 3.0931912363e-02;
		asali_->thermo_[170].low[2] = -1.9089286070e-05;
		asali_->thermo_[170].low[3] = 5.9284830378e-09;
		asali_->thermo_[170].low[4] = -7.4288454078e-13;
		asali_->thermo_[170].low[5] = -1.6383355469e+04;
		asali_->thermo_[170].low[6] = 6.7013902664e+00;
		
		asali_->thermo_[171].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[171].name,"C2-OQOOH");

		asali_->thermo_[171].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[171].high[0] = 1.0696166992e+01;
		asali_->thermo_[171].high[1] = 1.2593401596e-02;
		asali_->thermo_[171].high[2] = -5.3239182307e-06;
		asali_->thermo_[171].high[3] = 1.0856505694e-09;
		asali_->thermo_[171].high[4] = -8.8067120057e-14;
		asali_->thermo_[171].high[5] = -3.4200023438e+04;
		asali_->thermo_[171].high[6] = -2.4396429062e+01;

		asali_->thermo_[171].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[171].low[0] = 5.5394129753e+00;
		asali_->thermo_[171].low[1] = 2.4052854627e-02;
		asali_->thermo_[171].low[2] = -1.4873462533e-05;
		asali_->thermo_[171].low[3] = 4.6225188122e-09;
		asali_->thermo_[171].low[4] = -5.7929881595e-13;
		asali_->thermo_[171].low[5] = -3.2343591797e+04;
		asali_->thermo_[171].low[6] = 3.5129973888e+00;
		
		asali_->thermo_[172].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[172].name,"NC4-QOOH");

		asali_->thermo_[172].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[172].high[0] = 1.8377456665e+01;
		asali_->thermo_[172].high[1] = 1.8335472792e-02;
		asali_->thermo_[172].high[2] = -6.2392336986e-06;
		asali_->thermo_[172].high[3] = 9.6679741990e-10;
		asali_->thermo_[172].high[4] = -5.6128194405e-14;
		asali_->thermo_[172].high[5] = -1.2913548828e+04;
		asali_->thermo_[172].high[6] = -6.5598663330e+01;

		asali_->thermo_[172].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[172].low[0] = 1.1997658014e+00;
		asali_->thermo_[172].low[1] = 5.7375680655e-02;
		asali_->thermo_[172].low[2] = -3.9512138756e-05;
		asali_->thermo_[172].low[3] = 1.3570169877e-08;
		asali_->thermo_[172].low[4] = -1.8463800367e-12;
		asali_->thermo_[172].low[5] = -6.8670019531e+03;
		asali_->thermo_[172].low[6] = 2.6984552383e+01;
		
		asali_->thermo_[173].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[173].name,"NC5-QOOH");

		asali_->thermo_[173].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[173].high[0] = 1.3653819084e+01;
		asali_->thermo_[173].high[1] = 3.7786003202e-02;
		asali_->thermo_[173].high[2] = -1.7515108993e-05;
		asali_->thermo_[173].high[3] = 3.9039442790e-09;
		asali_->thermo_[173].high[4] = -3.4170856791e-13;
		asali_->thermo_[173].high[5] = -1.4387986328e+04;
		asali_->thermo_[173].high[6] = -3.9467880249e+01;

		asali_->thermo_[173].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[173].low[0] = -5.7428306341e-01;
		asali_->thermo_[173].low[1] = 8.1564776599e-02;
		asali_->thermo_[173].low[2] = -6.8029083195e-05;
		asali_->thermo_[173].low[3] = 2.9808546742e-08;
		asali_->thermo_[173].low[4] = -5.3233628443e-12;
		asali_->thermo_[173].low[5] = -1.0688679688e+04;
		asali_->thermo_[173].low[6] = 3.2907432556e+01;
		
		asali_->thermo_[174].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[174].name,"NC7-QOOH");

		asali_->thermo_[174].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[174].high[0] = 3.6777751923e+01;
		asali_->thermo_[174].high[1] = 2.4346539751e-02;
		asali_->thermo_[174].high[2] = -1.6537882402e-05;
		asali_->thermo_[174].high[3] = 5.2286988073e-09;
		asali_->thermo_[174].high[4] = -5.8510737488e-13;
		asali_->thermo_[174].high[5] = -2.8454978516e+04;
		asali_->thermo_[174].high[6] = -1.6505964661e+02;

		asali_->thermo_[174].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[174].low[0] = -2.8735878468e+00;
		asali_->thermo_[174].low[1] = 1.1246062070e-01;
		asali_->thermo_[174].low[2] = -8.9966284577e-05;
		asali_->thermo_[174].low[3] = 3.2424402718e-08;
		asali_->thermo_[174].low[4] = -4.3622887420e-12;
		asali_->thermo_[174].low[5] = -1.4180498047e+04;
		asali_->thermo_[174].low[6] = 4.9541671753e+01;
		
		asali_->thermo_[175].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[175].name,"DME-QOOH");

		asali_->thermo_[175].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[175].high[0] = 9.5255146027e+00;
		asali_->thermo_[175].high[1] = 1.8956284970e-02;
		asali_->thermo_[175].high[2] = -9.2755735750e-06;
		asali_->thermo_[175].high[3] = 2.1519275251e-09;
		asali_->thermo_[175].high[4] = -1.9390568253e-13;
		asali_->thermo_[175].high[5] = -1.7253751953e+04;
		asali_->thermo_[175].high[6] = -1.7469852448e+01;

		asali_->thermo_[175].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[175].low[0] = 5.1225261688e+00;
		asali_->thermo_[175].low[1] = 2.8740705922e-02;
		asali_->thermo_[175].low[2] = -1.7429256332e-05;
		asali_->thermo_[175].low[3] = 5.1718100913e-09;
		asali_->thermo_[175].low[4] = -6.1333381950e-13;
		asali_->thermo_[175].low[5] = -1.5668676758e+04;
		asali_->thermo_[175].low[6] = 6.3600425720e+00;
		
		asali_->thermo_[176].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[176].name,"IC16-QOOH");

		asali_->thermo_[176].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[176].high[0] = 4.2243972778e+01;
		asali_->thermo_[176].high[1] = 1.0258974135e-01;
		asali_->thermo_[176].high[2] = -4.5445962314e-05;
		asali_->thermo_[176].high[3] = 9.7090948614e-09;
		asali_->thermo_[176].high[4] = -8.1991125044e-13;
		asali_->thermo_[176].high[5] = -6.2665460938e+04;
		asali_->thermo_[176].high[6] = -1.8628311157e+02;

		asali_->thermo_[176].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[176].low[0] = -7.7932333946e+00;
		asali_->thermo_[176].low[1] = 2.3967798054e-01;
		asali_->thermo_[176].low[2] = -1.8629005353e-04;
		asali_->thermo_[176].low[3] = 7.4021464513e-08;
		asali_->thermo_[176].low[4] = -1.1832302499e-11;
		asali_->thermo_[176].low[5] = -4.8054597656e+04;
		asali_->thermo_[176].low[6] = 7.4053390503e+01;
		
		asali_->thermo_[177].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[177].name,"IC16T-QOOH");

		asali_->thermo_[177].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[177].high[0] = 5.0353752136e+01;
		asali_->thermo_[177].high[1] = 8.7253473699e-02;
		asali_->thermo_[177].high[2] = -3.5584955185e-05;
		asali_->thermo_[177].high[3] = 6.9964363192e-09;
		asali_->thermo_[177].high[4] = -5.4740592484e-13;
		asali_->thermo_[177].high[5] = -6.8613398438e+04;
		asali_->thermo_[177].high[6] = -2.3222715759e+02;

		asali_->thermo_[177].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[177].low[0] = -7.3374333382e+00;
		asali_->thermo_[177].low[1] = 2.3517958820e-01;
		asali_->thermo_[177].low[2] = -1.7782161012e-04;
		asali_->thermo_[177].low[3] = 6.7781328994e-08;
		asali_->thermo_[177].low[4] = -1.0288574680e-11;
		asali_->thermo_[177].low[5] = -5.0613750000e+04;
		asali_->thermo_[177].low[6] = 7.1753913879e+01;
		
		asali_->thermo_[178].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[178].name,"IC8-QOOH");

		asali_->thermo_[178].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[178].high[0] = 2.5920257568e+01;
		asali_->thermo_[178].high[1] = 4.6557426453e-02;
		asali_->thermo_[178].high[2] = -1.9147882995e-05;
		asali_->thermo_[178].high[3] = 3.7886129789e-09;
		asali_->thermo_[178].high[4] = -2.9786202259e-13;
		asali_->thermo_[178].high[5] = -2.9133193359e+04;
		asali_->thermo_[178].high[6] = -1.0045533752e+02;

		asali_->thermo_[178].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[178].low[0] = -9.9241125584e-01;
		asali_->thermo_[178].low[1] = 1.1556427181e-01;
		asali_->thermo_[178].low[2] = -8.5500621935e-05;
		asali_->thermo_[178].low[3] = 3.2144484408e-08;
		asali_->thermo_[178].low[4] = -4.8420720558e-12;
		asali_->thermo_[178].low[5] = -2.0736439453e+04;
		asali_->thermo_[178].low[6] = 4.1350418091e+01;
		
		asali_->thermo_[179].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[179].name,"IC4P-QOOH");

		asali_->thermo_[179].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[179].high[0] = 1.1480946541e+01;
		asali_->thermo_[179].high[1] = 3.0809560791e-02;
		asali_->thermo_[179].high[2] = -1.4193936295e-05;
		asali_->thermo_[179].high[3] = 3.1475544393e-09;
		asali_->thermo_[179].high[4] = -2.7442216793e-13;
		asali_->thermo_[179].high[5] = -7.4526821289e+03;
		asali_->thermo_[179].high[6] = -2.8087923050e+01;

		asali_->thermo_[179].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[179].low[0] = -1.9328156114e-01;
		asali_->thermo_[179].low[1] = 6.5399870276e-02;
		asali_->thermo_[179].low[2] = -5.2627608966e-05;
		asali_->thermo_[179].low[3] = 2.2127146337e-08;
		asali_->thermo_[179].low[4] = -3.7891612591e-12;
		asali_->thermo_[179].low[5] = -4.3006406250e+03;
		asali_->thermo_[179].low[6] = 3.1736968994e+01;
		
		asali_->thermo_[180].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[180].name,"IC4T-QOOH");

		asali_->thermo_[180].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[180].high[0] = 1.2089074135e+01;
		asali_->thermo_[180].high[1] = 3.0395418406e-02;
		asali_->thermo_[180].high[2] = -1.4088398530e-05;
		asali_->thermo_[180].high[3] = 3.1382212384e-09;
		asali_->thermo_[180].high[4] = -2.7443775334e-13;
		asali_->thermo_[180].high[5] = -1.0970555664e+04;
		asali_->thermo_[180].high[6] = -3.2853733063e+01;

		asali_->thermo_[180].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[180].low[0] = -4.2630213499e-01;
		asali_->thermo_[180].low[1] = 6.9813922048e-02;
		asali_->thermo_[180].low[2] = -6.0645692429e-05;
		asali_->thermo_[180].low[3] = 2.7577744532e-08;
		asali_->thermo_[180].low[4] = -5.0853674570e-12;
		asali_->thermo_[180].low[5] = -7.7916499023e+03;
		asali_->thermo_[180].low[6] = 3.0517108917e+01;
		
		asali_->thermo_[181].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[181].name,"MCYC6-QOOH");

		asali_->thermo_[181].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[181].high[0] = 2.9365989685e+01;
		asali_->thermo_[181].high[1] = 2.6537427679e-02;
		asali_->thermo_[181].high[2] = -8.3052200353e-06;
		asali_->thermo_[181].high[3] = 1.1215317564e-09;
		asali_->thermo_[181].high[4] = -5.2334892876e-14;
		asali_->thermo_[181].high[5] = -2.2859919922e+04;
		asali_->thermo_[181].high[6] = -1.3386770630e+02;

		asali_->thermo_[181].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[181].low[0] = -7.8216967583e+00;
		asali_->thermo_[181].low[1] = 1.0917673260e-01;
		asali_->thermo_[181].low[2] = -7.7171302109e-05;
		asali_->thermo_[181].low[3] = 2.6627489547e-08;
		asali_->thermo_[181].low[4] = -3.5948288617e-12;
		asali_->thermo_[181].low[5] = -9.4723535156e+03;
		asali_->thermo_[181].low[6] = 6.7399810791e+01;
		
		asali_->thermo_[182].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[182].name,"MTBE-QOOH");

		asali_->thermo_[182].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[182].high[0] = 1.5443616867e+01;
		asali_->thermo_[182].high[1] = 3.6662045866e-02;
		asali_->thermo_[182].high[2] = -1.5396470189e-05;
		asali_->thermo_[182].high[3] = 3.1886666640e-09;
		asali_->thermo_[182].high[4] = -2.6482621976e-13;
		asali_->thermo_[182].high[5] = -2.8618707031e+04;
		asali_->thermo_[182].high[6] = -4.2544532776e+01;

		asali_->thermo_[182].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[182].low[0] = 1.3986673355e+00;
		asali_->thermo_[182].low[1] = 7.9222500324e-02;
		asali_->thermo_[182].low[2] = -6.3760620833e-05;
		asali_->thermo_[182].low[3] = 2.7615005393e-08;
		asali_->thermo_[182].low[4] = -4.8910268197e-12;
		asali_->thermo_[182].low[5] = -2.4910839844e+04;
		asali_->thermo_[182].low[6] = 2.9113555908e+01;
		
		asali_->thermo_[183].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[183].name,"NEOC5-QOOH");

		asali_->thermo_[183].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[183].high[0] = 1.8619752884e+01;
		asali_->thermo_[183].high[1] = 2.8511142358e-02;
		asali_->thermo_[183].high[2] = -1.1396933587e-05;
		asali_->thermo_[183].high[3] = 2.1813726381e-09;
		asali_->thermo_[183].high[4] = -1.6576894208e-13;
		asali_->thermo_[183].high[5] = -1.5039144531e+04;
		asali_->thermo_[183].high[6] = -6.7488372803e+01;

		asali_->thermo_[183].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[183].low[0] = 1.4807031155e+00;
		asali_->thermo_[183].low[1] = 7.0570163429e-02;
		asali_->thermo_[183].low[2] = -5.0101552915e-05;
		asali_->thermo_[183].low[3] = 1.8011482084e-08;
		asali_->thermo_[183].low[4] = -2.5936997775e-12;
		asali_->thermo_[183].low[5] = -9.4518144531e+03;
		asali_->thermo_[183].low[6] = 2.3571432114e+01;
		
		asali_->thermo_[184].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[184].name,"IC8T-QOOH");

		asali_->thermo_[184].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[184].high[0] = 2.5920257568e+01;
		asali_->thermo_[184].high[1] = 4.6557426453e-02;
		asali_->thermo_[184].high[2] = -1.9147882995e-05;
		asali_->thermo_[184].high[3] = 3.7886129789e-09;
		asali_->thermo_[184].high[4] = -2.9786202259e-13;
		asali_->thermo_[184].high[5] = -2.9133193359e+04;
		asali_->thermo_[184].high[6] = -1.0045533752e+02;

		asali_->thermo_[184].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[184].low[0] = -9.9241125584e-01;
		asali_->thermo_[184].low[1] = 1.1556427181e-01;
		asali_->thermo_[184].low[2] = -8.5500621935e-05;
		asali_->thermo_[184].low[3] = 3.2144484408e-08;
		asali_->thermo_[184].low[4] = -4.8420720558e-12;
		asali_->thermo_[184].low[5] = -2.0736439453e+04;
		asali_->thermo_[184].low[6] = 4.1350418091e+01;
		
		asali_->thermo_[185].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[185].name,"MCYC6T-QOOH");

		asali_->thermo_[185].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[185].high[0] = 2.9365989685e+01;
		asali_->thermo_[185].high[1] = 2.6537427679e-02;
		asali_->thermo_[185].high[2] = -8.3052200353e-06;
		asali_->thermo_[185].high[3] = 1.1215317564e-09;
		asali_->thermo_[185].high[4] = -5.2334892876e-14;
		asali_->thermo_[185].high[5] = -2.2859919922e+04;
		asali_->thermo_[185].high[6] = -1.3386770630e+02;

		asali_->thermo_[185].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[185].low[0] = -7.8216967583e+00;
		asali_->thermo_[185].low[1] = 1.0917673260e-01;
		asali_->thermo_[185].low[2] = -7.7171302109e-05;
		asali_->thermo_[185].low[3] = 2.6627489547e-08;
		asali_->thermo_[185].low[4] = -3.5948288617e-12;
		asali_->thermo_[185].low[5] = -9.4723535156e+03;
		asali_->thermo_[185].low[6] = 6.7399810791e+01;
		
		asali_->thermo_[186].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[186].name,"NC10H21");

		asali_->thermo_[186].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[186].high[0] = 2.6321269989e+01;
		asali_->thermo_[186].high[1] = 5.5221974850e-02;
		asali_->thermo_[186].high[2] = -2.2126652766e-05;
		asali_->thermo_[186].high[3] = 4.3349888124e-09;
		asali_->thermo_[186].high[4] = -3.4231650717e-13;
		asali_->thermo_[186].high[5] = -2.1017517578e+04;
		asali_->thermo_[186].high[6] = -1.0319297791e+02;

		asali_->thermo_[186].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[186].low[0] = -1.8105727434e+00;
		asali_->thermo_[186].low[1] = 1.1773718148e-01;
		asali_->thermo_[186].low[2] = -7.4222654803e-05;
		asali_->thermo_[186].low[3] = 2.3629805668e-08;
		asali_->thermo_[186].low[4] = -3.0221519731e-12;
		asali_->thermo_[186].low[5] = -1.0890053711e+04;
		asali_->thermo_[186].low[6] = 4.9062419891e+01;
		
		asali_->thermo_[187].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[187].name,"NC10H21-OO");

		asali_->thermo_[187].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[187].high[0] = 3.2377983093e+01;
		asali_->thermo_[187].high[1] = 5.2488535643e-02;
		asali_->thermo_[187].high[2] = -1.9337012418e-05;
		asali_->thermo_[187].high[3] = 3.3536966537e-09;
		asali_->thermo_[187].high[4] = -2.2844879742e-13;
		asali_->thermo_[187].high[5] = -4.0644726562e+04;
		asali_->thermo_[187].high[6] = -1.3209896851e+02;

		asali_->thermo_[187].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[187].low[0] = 1.6747819185e+00;
		asali_->thermo_[187].low[1] = 1.2071787566e-01;
		asali_->thermo_[187].low[2] = -7.6194795838e-05;
		asali_->thermo_[187].low[3] = 2.4412134536e-08;
		asali_->thermo_[187].low[4] = -3.1532317989e-12;
		asali_->thermo_[187].low[5] = -2.9591576172e+04;
		asali_->thermo_[187].low[6] = 3.4073169708e+01;
		
		asali_->thermo_[188].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[188].name,"NC12H25");

		asali_->thermo_[188].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[188].high[0] = 3.1700557709e+01;
		asali_->thermo_[188].high[1] = 6.6154435277e-02;
		asali_->thermo_[188].high[2] = -2.6629522836e-05;
		asali_->thermo_[188].high[3] = 5.2180451071e-09;
		asali_->thermo_[188].high[4] = -4.1099851929e-13;
		asali_->thermo_[188].high[5] = -2.8852589844e+04;
		asali_->thermo_[188].high[6] = -1.3160762024e+02;

		asali_->thermo_[188].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[188].low[0] = -2.0608513355e+00;
		asali_->thermo_[188].low[1] = 1.4117978513e-01;
		asali_->thermo_[188].low[2] = -8.9150649728e-05;
		asali_->thermo_[188].low[3] = 2.8374017802e-08;
		asali_->thermo_[188].low[4] = -3.6271059940e-12;
		asali_->thermo_[188].low[5] = -1.6698482422e+04;
		asali_->thermo_[188].low[6] = 5.1116165161e+01;
		
		asali_->thermo_[189].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[189].name,"NC12H25-OO");

		asali_->thermo_[189].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[189].high[0] = 3.8275417328e+01;
		asali_->thermo_[189].high[1] = 6.2304601073e-02;
		asali_->thermo_[189].high[2] = -2.2978578272e-05;
		asali_->thermo_[189].high[3] = 3.9922043449e-09;
		asali_->thermo_[189].high[4] = -2.7263041542e-13;
		asali_->thermo_[189].high[5] = -4.8670304688e+04;
		asali_->thermo_[189].high[6] = -1.6084613037e+02;

		asali_->thermo_[189].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[189].low[0] = 1.3966929913e+00;
		asali_->thermo_[189].low[1] = 1.4425732195e-01;
		asali_->thermo_[189].low[2] = -9.1272515419e-05;
		asali_->thermo_[189].low[3] = 2.9286253422e-08;
		asali_->thermo_[189].low[4] = -3.7856926795e-12;
		asali_->thermo_[189].low[5] = -3.5393960938e+04;
		asali_->thermo_[189].low[6] = 3.8749214172e+01;
		
		asali_->thermo_[190].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[190].name,"C2H4OH");

		asali_->thermo_[190].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[190].high[0] = 6.4307184219e+00;
		asali_->thermo_[190].high[1] = 1.3052903116e-02;
		asali_->thermo_[190].high[2] = -5.0423404900e-06;
		asali_->thermo_[190].high[3] = 9.4242191828e-10;
		asali_->thermo_[190].high[4] = -7.0619237454e-14;
		asali_->thermo_[190].high[5] = -6.8425419922e+03;
		asali_->thermo_[190].high[6] = -6.4064397812e+00;

		asali_->thermo_[190].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[190].low[0] = 1.1905840635e+00;
		asali_->thermo_[190].low[1] = 2.4697646499e-02;
		asali_->thermo_[190].low[2] = -1.4746292436e-05;
		asali_->thermo_[190].low[3] = 4.5364783041e-09;
		asali_->thermo_[190].low[4] = -5.6979372392e-13;
		asali_->thermo_[190].low[5] = -4.9560932617e+03;
		asali_->thermo_[190].low[6] = 2.1954259872e+01;
		
		asali_->thermo_[191].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[191].name,"CH2CHO");

		asali_->thermo_[191].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[191].high[0] = 3.6650252342e+00;
		asali_->thermo_[191].high[1] = 1.4476824552e-02;
		asali_->thermo_[191].high[2] = -7.2326638474e-06;
		asali_->thermo_[191].high[3] = 1.7058046087e-09;
		asali_->thermo_[191].high[4] = -1.5634585640e-13;
		asali_->thermo_[191].high[5] = -3.6857917786e+01;
		asali_->thermo_[191].high[6] = 5.9234185219e+00;

		asali_->thermo_[191].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[191].low[0] = 2.1574206650e-01;
		asali_->thermo_[191].low[1] = 2.7872098610e-02;
		asali_->thermo_[191].low[2] = -2.6740344765e-05;
		asali_->thermo_[191].low[3] = 1.4332135478e-08;
		asali_->thermo_[191].low[4] = -3.2209892305e-12;
		asali_->thermo_[191].low[5] = 6.7369439697e+02;
		asali_->thermo_[191].low[6] = 2.2666172028e+01;
		
		asali_->thermo_[192].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[192].name,"CH3CHOH");

		asali_->thermo_[192].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[192].high[0] = 1.0030369759e+00;
		asali_->thermo_[192].high[1] = 2.3023735732e-02;
		asali_->thermo_[192].high[2] = -1.1937274394e-05;
		asali_->thermo_[192].high[3] = 2.9827447179e-09;
		asali_->thermo_[192].high[4] = -2.8818375637e-13;
		asali_->thermo_[192].high[5] = -6.1775102539e+03;
		asali_->thermo_[192].high[6] = 2.3940160751e+01;

		asali_->thermo_[192].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[192].low[0] = 1.8391553164e+00;
		asali_->thermo_[192].low[1] = 1.8245916814e-02;
		asali_->thermo_[192].low[2] = -1.6990917402e-06;
		asali_->thermo_[192].low[3] = -6.7679053473e-09;
		asali_->thermo_[192].low[4] = 3.1941912223e-12;
		asali_->thermo_[192].low[5] = -6.2945668945e+03;
		asali_->thermo_[192].low[6] = 2.0204595566e+01;
		
		asali_->thermo_[193].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[193].name,"NC4H9-OO");

		asali_->thermo_[193].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[193].high[0] = 8.9663009644e+00;
		asali_->thermo_[193].high[1] = 3.4107465297e-02;
		asali_->thermo_[193].high[2] = -1.5764100681e-05;
		asali_->thermo_[193].high[3] = 3.5071578974e-09;
		asali_->thermo_[193].high[4] = -3.0666292531e-13;
		asali_->thermo_[193].high[5] = -1.4084739258e+04;
		asali_->thermo_[193].high[6] = -1.5834744453e+01;

		asali_->thermo_[193].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[193].low[0] = 9.4428163767e-01;
		asali_->thermo_[193].low[1] = 5.8416616172e-02;
		asali_->thermo_[193].low[2] = -4.3388132326e-05;
		asali_->thermo_[193].low[3] = 1.7458690493e-08;
		asali_->thermo_[193].low[4] = -2.9489986841e-12;
		asali_->thermo_[193].low[5] = -1.1966926758e+04;
		asali_->thermo_[193].low[6] = 2.5094028473e+01;
		
		asali_->thermo_[194].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[194].name,"NC5H11");

		asali_->thermo_[194].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[194].high[0] = 6.9319376945e+00;
		asali_->thermo_[194].high[1] = 3.7544097751e-02;
		asali_->thermo_[194].high[2] = -1.6547855921e-05;
		asali_->thermo_[194].high[3] = 3.5363363349e-09;
		asali_->thermo_[194].high[4] = -2.9997670472e-13;
		asali_->thermo_[194].high[5] = -1.7308707275e+03;
		asali_->thermo_[194].high[6] = -8.8871068954e+00;

		asali_->thermo_[194].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[194].low[0] = -3.5752043724e+00;
		asali_->thermo_[194].low[1] = 6.0893304646e-02;
		asali_->thermo_[194].low[2] = -3.6005527363e-05;
		asali_->thermo_[194].low[3] = 1.0742881251e-08;
		asali_->thermo_[194].low[4] = -1.3008857229e-12;
		asali_->thermo_[194].low[5] = 2.0517004395e+03;
		asali_->thermo_[194].low[6] = 4.7979740143e+01;
		
		asali_->thermo_[195].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[195].name,"NC5H12OO");

		asali_->thermo_[195].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[195].high[0] = 1.0654484749e+01;
		asali_->thermo_[195].high[1] = 4.1617054492e-02;
		asali_->thermo_[195].high[2] = -1.9338287530e-05;
		asali_->thermo_[195].high[3] = 4.3211394463e-09;
		asali_->thermo_[195].high[4] = -3.7908822674e-13;
		asali_->thermo_[195].high[5] = -1.9865203125e+04;
		asali_->thermo_[195].high[6] = -2.5023458481e+01;

		asali_->thermo_[195].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[195].low[0] = 3.1966486573e-01;
		asali_->thermo_[195].low[1] = 7.3416501284e-02;
		asali_->thermo_[195].low[2] = -5.6029955886e-05;
		asali_->thermo_[195].low[3] = 2.3137380012e-08;
		asali_->thermo_[195].low[4] = -3.9975960910e-12;
		asali_->thermo_[195].low[5] = -1.7178150391e+04;
		asali_->thermo_[195].low[6] = 2.7547561646e+01;
		
		asali_->thermo_[196].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[196].name,"NC7H15");

		asali_->thermo_[196].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[196].high[0] = 1.5893829346e+01;
		asali_->thermo_[196].high[1] = 4.3285120279e-02;
		asali_->thermo_[196].high[2] = -1.8342960175e-05;
		asali_->thermo_[196].high[3] = 3.8152463411e-09;
		asali_->thermo_[196].high[4] = -3.1829196939e-13;
		asali_->thermo_[196].high[5] = -8.3358916016e+03;
		asali_->thermo_[196].high[6] = -5.3438789368e+01;

		asali_->thermo_[196].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[196].low[0] = -1.0321360826e+00;
		asali_->thermo_[196].low[1] = 8.0898374319e-02;
		asali_->thermo_[196].low[2] = -4.9687339924e-05;
		asali_->thermo_[196].low[3] = 1.5424276967e-08;
		asali_->thermo_[196].low[4] = -1.9306572400e-12;
		asali_->thermo_[196].low[5] = -2.2425444336e+03;
		asali_->thermo_[196].low[6] = 3.8168071747e+01;
		
		asali_->thermo_[197].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[197].name,"NC7H15-OO");

		asali_->thermo_[197].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[197].high[0] = 2.6800615311e+01;
		asali_->thermo_[197].high[1] = 3.3578086644e-02;
		asali_->thermo_[197].high[2] = -1.1798218111e-05;
		asali_->thermo_[197].high[3] = 1.8999222196e-09;
		asali_->thermo_[197].high[4] = -1.1621873440e-13;
		asali_->thermo_[197].high[5] = -2.3338892578e+04;
		asali_->thermo_[197].high[6] = -1.0655043793e+02;

		asali_->thermo_[197].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[197].low[0] = 1.9233399630e+00;
		asali_->thermo_[197].low[1] = 8.9482076466e-02;
		asali_->thermo_[197].low[2] = -5.8908321080e-05;
		asali_->thermo_[197].low[3] = 1.9544154739e-08;
		asali_->thermo_[197].low[4] = -2.5943414084e-12;
		asali_->thermo_[197].low[5] = -1.4482582031e+04;
		asali_->thermo_[197].low[6] = 2.7812602997e+01;
		
		asali_->thermo_[198].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[198].name,"C12H7");

		asali_->thermo_[198].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[198].high[0] = 1.2334980965e+01;
		asali_->thermo_[198].high[1] = 5.1690768450e-02;
		asali_->thermo_[198].high[2] = -2.7240481359e-05;
		asali_->thermo_[198].high[3] = 6.8585817026e-09;
		asali_->thermo_[198].high[4] = -6.7201891838e-13;
		asali_->thermo_[198].high[5] = 5.3039500000e+04;
		asali_->thermo_[198].high[6] = -4.2524497986e+01;

		asali_->thermo_[198].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[198].low[0] = -8.0296840668e+00;
		asali_->thermo_[198].low[1] = 1.1685769260e-01;
		asali_->thermo_[198].low[2] = -1.0544079851e-04;
		asali_->thermo_[198].low[3] = 4.8565414801e-08;
		asali_->thermo_[198].low[4] = -9.0133855241e-12;
		asali_->thermo_[198].low[5] = 5.8130664062e+04;
		asali_->thermo_[198].low[6] = 6.0267482758e+01;
		
		asali_->thermo_[199].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[199].name,"CH3COCH2");

		asali_->thermo_[199].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[199].high[0] = 9.2418708801e+00;
		asali_->thermo_[199].high[1] = 1.3494678773e-02;
		asali_->thermo_[199].high[2] = -5.2372265600e-06;
		asali_->thermo_[199].high[3] = 9.7274888144e-10;
		asali_->thermo_[199].high[4] = -7.1983441614e-14;
		asali_->thermo_[199].high[5] = -8.0457109375e+03;
		asali_->thermo_[199].high[6] = -2.2425825119e+01;

		asali_->thermo_[199].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[199].low[0] = 1.8262085915e+00;
		asali_->thermo_[199].low[1] = 2.9973927885e-02;
		asali_->thermo_[199].low[2] = -1.8969934899e-05;
		asali_->thermo_[199].low[3] = 6.0589369077e-09;
		asali_->thermo_[199].low[4] = -7.7839845030e-13;
		asali_->thermo_[199].low[5] = -5.3760722656e+03;
		asali_->thermo_[199].low[6] = 1.7709285736e+01;
		
		asali_->thermo_[200].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[200].name,"C2H4CHO");

		asali_->thermo_[200].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[200].high[0] = 2.1557943821e+00;
		asali_->thermo_[200].high[1] = 2.5753140450e-02;
		asali_->thermo_[200].high[2] = -1.3306938854e-05;
		asali_->thermo_[200].high[3] = 3.2812286221e-09;
		asali_->thermo_[200].high[4] = -3.1282818675e-13;
		asali_->thermo_[200].high[5] = -7.3145947266e+02;
		asali_->thermo_[200].high[6] = 1.9481681824e+01;

		asali_->thermo_[200].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[200].low[0] = 3.5864162445e+00;
		asali_->thermo_[200].low[1] = 1.8223552033e-02;
		asali_->thermo_[200].low[2] = 1.5540914546e-06;
		asali_->thermo_[200].low[3] = -9.7547623312e-09;
		asali_->thermo_[200].low[4] = 3.9753270120e-12;
		asali_->thermo_[200].low[5] = -9.4891400146e+02;
		asali_->thermo_[200].low[6] = 1.2972373962e+01;
		
		asali_->thermo_[201].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[201].name,"CYC6-OO");

		asali_->thermo_[201].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[201].high[0] = 1.8781461716e+01;
		asali_->thermo_[201].high[1] = 3.5436194390e-02;
		asali_->thermo_[201].high[2] = -1.4971878045e-05;
		asali_->thermo_[201].high[3] = 3.0432829590e-09;
		asali_->thermo_[201].high[4] = -2.4647832061e-13;
		asali_->thermo_[201].high[5] = -1.9525283203e+04;
		asali_->thermo_[201].high[6] = -7.8724090576e+01;

		asali_->thermo_[201].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[201].low[0] = -6.5062355995e+00;
		asali_->thermo_[201].low[1] = 9.1631077230e-02;
		asali_->thermo_[201].low[2] = -6.1800950789e-05;
		asali_->thermo_[201].low[3] = 2.0387382449e-08;
		asali_->thermo_[201].low[4] = -2.6553811233e-12;
		asali_->thermo_[201].low[5] = -1.0421711914e+04;
		asali_->thermo_[201].low[6] = 5.8138206482e+01;
		
		asali_->thermo_[202].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[202].name,"CYC6H11");

		asali_->thermo_[202].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[202].high[0] = 1.1287919044e+01;
		asali_->thermo_[202].high[1] = 3.9479836822e-02;
		asali_->thermo_[202].high[2] = -1.8047474441e-05;
		asali_->thermo_[202].high[3] = 3.9797698470e-09;
		asali_->thermo_[202].high[4] = -3.4793356889e-13;
		asali_->thermo_[202].high[5] = 4.6993441772e+02;
		asali_->thermo_[202].high[6] = -4.1574363708e+01;

		asali_->thermo_[202].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[202].low[0] = -9.2020034790e+00;
		asali_->thermo_[202].low[1] = 8.5012994707e-02;
		asali_->thermo_[202].low[2] = -5.5991775298e-05;
		asali_->thermo_[202].low[3] = 1.8033215810e-08;
		asali_->thermo_[202].low[4] = -2.2998009747e-12;
		asali_->thermo_[202].low[5] = 7.8463066406e+03;
		asali_->thermo_[202].low[6] = 6.9321372986e+01;
		
		asali_->thermo_[203].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[203].name,"CYC6H9");

		asali_->thermo_[203].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[203].high[0] = 1.4167046547e+01;
		asali_->thermo_[203].high[1] = 2.7565134689e-02;
		asali_->thermo_[203].high[2] = -1.1333761904e-05;
		asali_->thermo_[203].high[3] = 2.2302164560e-09;
		asali_->thermo_[203].high[4] = -1.7468344208e-13;
		asali_->thermo_[203].high[5] = 7.9386630859e+03;
		asali_->thermo_[203].high[6] = -5.8544197083e+01;

		asali_->thermo_[203].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[203].low[0] = -6.4863934517e+00;
		asali_->thermo_[203].low[1] = 7.3461666703e-02;
		asali_->thermo_[203].low[2] = -4.9580870837e-05;
		asali_->thermo_[203].low[3] = 1.6395812708e-08;
		asali_->thermo_[203].low[4] = -2.1421274043e-12;
		asali_->thermo_[203].low[5] = 1.5373901367e+04;
		asali_->thermo_[203].low[6] = 5.3236526489e+01;
		
		asali_->thermo_[204].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[204].name,"CYC5H5");

		asali_->thermo_[204].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[204].high[0] = 4.0165257454e+00;
		asali_->thermo_[204].high[1] = 2.6845188811e-02;
		asali_->thermo_[204].high[2] = -1.2642301954e-05;
		asali_->thermo_[204].high[3] = 2.7809232694e-09;
		asali_->thermo_[204].high[4] = -2.3529943727e-13;
		asali_->thermo_[204].high[5] = 2.9111015625e+04;
		asali_->thermo_[204].high[6] = 1.4402579069e+00;

		asali_->thermo_[204].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[204].low[0] = -2.5873739719e+00;
		asali_->thermo_[204].low[1] = 6.4581759274e-02;
		asali_->thermo_[204].low[2] = -9.3506379926e-05;
		asali_->thermo_[204].low[3] = 7.9794332919e-08;
		asali_->thermo_[204].low[4] = -2.7740088004e-11;
		asali_->thermo_[204].low[5] = 3.0035562500e+04;
		asali_->thermo_[204].low[6] = 3.0944810867e+01;
		
		asali_->thermo_[205].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[205].name,"RDIPE");

		asali_->thermo_[205].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[205].high[0] = 1.6954950333e+01;
		asali_->thermo_[205].high[1] = 3.4511841834e-02;
		asali_->thermo_[205].high[2] = -1.3134273104e-05;
		asali_->thermo_[205].high[3] = 2.3615021050e-09;
		asali_->thermo_[205].high[4] = -1.6713312592e-13;
		asali_->thermo_[205].high[5] = -2.7814748047e+04;
		asali_->thermo_[205].high[6] = -5.5460796356e+01;

		asali_->thermo_[205].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[205].low[0] = 6.9178718328e-01;
		asali_->thermo_[205].low[1] = 7.0652201772e-02;
		asali_->thermo_[205].low[2] = -4.3251238822e-05;
		asali_->thermo_[205].low[3] = 1.3515934150e-08;
		asali_->thermo_[205].low[4] = -1.7163598017e-12;
		asali_->thermo_[205].low[5] = -2.1960009766e+04;
		asali_->thermo_[205].low[6] = 3.2558830261e+01;
		
		asali_->thermo_[206].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[206].name,"CH3OCH2");

		asali_->thermo_[206].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[206].high[0] = 2.7637343407e+00;
		asali_->thermo_[206].high[1] = 2.0942777395e-02;
		asali_->thermo_[206].high[2] = -1.0390631360e-05;
		asali_->thermo_[206].high[3] = 2.4585384839e-09;
		asali_->thermo_[206].high[4] = -2.2593582007e-13;
		asali_->thermo_[206].high[5] = -6.5971887207e+02;
		asali_->thermo_[206].high[6] = 1.2315439224e+01;

		asali_->thermo_[206].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[206].low[0] = 2.9872417450e+00;
		asali_->thermo_[206].low[1] = 1.9750738516e-02;
		asali_->thermo_[206].low[2] = -8.0065519796e-06;
		asali_->thermo_[206].low[3] = 3.3935737553e-10;
		asali_->thermo_[206].low[4] = 4.8045790436e-13;
		asali_->thermo_[206].low[5] = -6.9324499512e+02;
		asali_->thermo_[206].low[6] = 1.1301445007e+01;
		
		asali_->thermo_[207].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[207].name,"DME-OO");

		asali_->thermo_[207].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[207].high[0] = 3.5897457600e+00;
		asali_->thermo_[207].high[1] = 2.8096012771e-02;
		asali_->thermo_[207].high[2] = -1.4922420633e-05;
		asali_->thermo_[207].high[3] = 3.7135554631e-09;
		asali_->thermo_[207].high[4] = -3.5370371996e-13;
		asali_->thermo_[207].high[5] = -1.9335228516e+04;
		asali_->thermo_[207].high[6] = 1.4727829933e+01;

		asali_->thermo_[207].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[207].low[0] = 5.4134545326e+00;
		asali_->thermo_[207].low[1] = 1.9711144269e-02;
		asali_->thermo_[207].low[2] = -4.6575038937e-07;
		asali_->thermo_[207].low[3] = -7.3643526832e-09;
		asali_->thermo_[207].low[4] = 2.8296033051e-12;
		asali_->thermo_[207].low[5] = -1.9652554688e+04;
		asali_->thermo_[207].low[6] = 6.1834626198e+00;
		
		asali_->thermo_[208].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[208].name,"C6H4C2H");

		asali_->thermo_[208].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[208].high[0] = 3.2141567230e+01;
		asali_->thermo_[208].high[1] = -1.9816840068e-02;
		asali_->thermo_[208].high[2] = 2.6428253477e-05;
		asali_->thermo_[208].high[3] = -1.0984347654e-08;
		asali_->thermo_[208].high[4] = 1.5063059307e-12;
		asali_->thermo_[208].high[5] = 5.4496410156e+04;
		asali_->thermo_[208].high[6] = -1.4702644348e+02;

		asali_->thermo_[208].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[208].low[0] = -4.7825260162e+00;
		asali_->thermo_[208].low[1] = 7.9308249056e-02;
		asali_->thermo_[208].low[2] = -7.3362105468e-05;
		asali_->thermo_[208].low[3] = 3.3664580457e-08;
		asali_->thermo_[208].low[4] = -5.9851251559e-12;
		asali_->thermo_[208].low[5] = 6.5499789062e+04;
		asali_->thermo_[208].low[6] = 4.5835422516e+01;
		
		asali_->thermo_[209].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[209].name,"RBIPHENYL");

		asali_->thermo_[209].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[209].high[0] = 2.6769207001e+01;
		asali_->thermo_[209].high[1] = 2.8161142021e-02;
		asali_->thermo_[209].high[2] = -6.0566771936e-06;
		asali_->thermo_[209].high[3] = -3.6937841674e-10;
		asali_->thermo_[209].high[4] = 1.6724937949e-13;
		asali_->thermo_[209].high[5] = 3.9276996094e+04;
		asali_->thermo_[209].high[6] = -1.2130641174e+02;

		asali_->thermo_[209].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[209].low[0] = -1.0562510490e+01;
		asali_->thermo_[209].low[1] = 1.3114519417e-01;
		asali_->thermo_[209].low[2] = -1.1259190069e-04;
		asali_->thermo_[209].low[3] = 4.8612335490e-08;
		asali_->thermo_[209].low[4] = -8.2778731786e-12;
		asali_->thermo_[209].low[5] = 5.0103191406e+04;
		asali_->thermo_[209].low[6] = 7.2668655396e+01;
		
		asali_->thermo_[210].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[210].name,"C14H9");

		asali_->thermo_[210].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[210].high[0] = 3.1314125061e+01;
		asali_->thermo_[210].high[1] = 2.8952870518e-02;
		asali_->thermo_[210].high[2] = -5.5767100093e-06;
		asali_->thermo_[210].high[3] = -5.8966292960e-10;
		asali_->thermo_[210].high[4] = 1.8820294173e-13;
		asali_->thermo_[210].high[5] = 4.0656089844e+04;
		asali_->thermo_[210].high[6] = -1.4810102844e+02;

		asali_->thermo_[210].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[210].low[0] = -1.2190587044e+01;
		asali_->thermo_[210].low[1] = 1.5064437687e-01;
		asali_->thermo_[210].low[2] = -1.3322514133e-04;
		asali_->thermo_[210].low[3] = 5.8920093693e-08;
		asali_->thermo_[210].low[4] = -1.0215600935e-11;
		asali_->thermo_[210].low[5] = 5.3098437500e+04;
		asali_->thermo_[210].low[6] = 7.7344589233e+01;
		
		asali_->thermo_[211].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[211].name,"C10H7");

		asali_->thermo_[211].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[211].high[0] = 1.8603490829e+01;
		asali_->thermo_[211].high[1] = 2.8455745429e-02;
		asali_->thermo_[211].high[2] = -7.5149209806e-06;
		asali_->thermo_[211].high[3] = 8.5984393217e-11;
		asali_->thermo_[211].high[4] = 1.3184353782e-13;
		asali_->thermo_[211].high[5] = 3.8917531250e+04;
		asali_->thermo_[211].high[6] = -7.9667160034e+01;

		asali_->thermo_[211].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[211].low[0] = -8.1160173416e+00;
		asali_->thermo_[211].low[1] = 1.0267660767e-01;
		asali_->thermo_[211].low[2] = -8.4828316176e-05;
		asali_->thermo_[211].low[3] = 3.5879221372e-08;
		asali_->thermo_[211].low[4] = -6.0822601296e-12;
		asali_->thermo_[211].low[5] = 4.6612750000e+04;
		asali_->thermo_[211].low[6] = 5.8982109070e+01;
		
		asali_->thermo_[212].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[212].name,"IC16H33-OO");

		asali_->thermo_[212].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[212].high[0] = 3.9474975586e+01;
		asali_->thermo_[212].high[1] = 1.0621148348e-01;
		asali_->thermo_[212].high[2] = -4.7410845582e-05;
		asali_->thermo_[212].high[3] = 1.0202937162e-08;
		asali_->thermo_[212].high[4] = -8.6710738416e-13;
		asali_->thermo_[212].high[5] = -6.8195445312e+04;
		asali_->thermo_[212].high[6] = -1.7318270874e+02;

		asali_->thermo_[212].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[212].low[0] = -7.5551576614e+00;
		asali_->thermo_[212].low[1] = 2.3506116867e-01;
		asali_->thermo_[212].low[2] = -1.7979065888e-04;
		asali_->thermo_[212].low[3] = 7.0650337136e-08;
		asali_->thermo_[212].low[4] = -1.1217689971e-11;
		asali_->thermo_[212].low[5] = -5.4462648438e+04;
		asali_->thermo_[212].low[6] = 7.1508422852e+01;
		
		asali_->thermo_[213].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[213].name,"IC16H33");

		asali_->thermo_[213].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[213].high[0] = 5.1145359039e+01;
		asali_->thermo_[213].high[1] = 7.5329676270e-02;
		asali_->thermo_[213].high[2] = -2.7926324037e-05;
		asali_->thermo_[213].high[3] = 4.9290820314e-09;
		asali_->thermo_[213].high[4] = -3.4436440245e-13;
		asali_->thermo_[213].high[5] = -5.6193886719e+04;
		asali_->thermo_[213].high[6] = -2.4304823303e+02;

		asali_->thermo_[213].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[213].low[0] = -8.9521617889e+00;
		asali_->thermo_[213].low[1] = 2.2102063894e-01;
		asali_->thermo_[213].low[2] = -1.6037265596e-04;
		asali_->thermo_[213].low[3] = 5.8442747530e-08;
		asali_->thermo_[213].low[4] = -8.4524956478e-12;
		asali_->thermo_[213].low[5] = -3.6361707031e+04;
		asali_->thermo_[213].low[6] = 7.6982917786e+01;
		
		asali_->thermo_[214].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[214].name,"IC8H17");

		asali_->thermo_[214].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[214].high[0] = 2.6510423660e+01;
		asali_->thermo_[214].high[1] = 3.0179681256e-02;
		asali_->thermo_[214].high[2] = -5.8218497543e-06;
		asali_->thermo_[214].high[3] = 1.4208585697e-11;
		asali_->thermo_[214].high[4] = 7.6011076502e-14;
		asali_->thermo_[214].high[5] = -1.8037302734e+04;
		asali_->thermo_[214].high[6] = -1.1498119354e+02;

		asali_->thermo_[214].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[214].low[0] = -3.3296120167e+00;
		asali_->thermo_[214].low[1] = 1.0819284618e-01;
		asali_->thermo_[214].low[2] = -8.2305341493e-05;
		asali_->thermo_[214].low[3] = 3.3340349148e-08;
		asali_->thermo_[214].low[4] = -5.3694366661e-12;
		asali_->thermo_[214].low[5] = -8.9062519531e+03;
		asali_->thermo_[214].low[6] = 4.1669727325e+01;
		
		asali_->thermo_[215].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[215].name,"IC8H17-OO");

		asali_->thermo_[215].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[215].high[0] = 2.4386322021e+01;
		asali_->thermo_[215].high[1] = 4.7909185290e-02;
		asali_->thermo_[215].high[2] = -1.9611616153e-05;
		asali_->thermo_[215].high[3] = 3.8575915795e-09;
		asali_->thermo_[215].high[4] = -3.0144604261e-13;
		asali_->thermo_[215].high[5] = -3.5180902344e+04;
		asali_->thermo_[215].high[6] = -9.3149200439e+01;

		asali_->thermo_[215].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[215].low[0] = -7.1050691605e-01;
		asali_->thermo_[215].low[1] = 1.1065126210e-01;
		asali_->thermo_[215].low[2] = -7.8432312876e-05;
		asali_->thermo_[215].low[3] = 2.8366214266e-08;
		asali_->thermo_[215].low[4] = -4.1309182637e-12;
		asali_->thermo_[215].low[5] = -2.7149917969e+04;
		asali_->thermo_[215].low[6] = 3.9724094391e+01;
		
		asali_->thermo_[216].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[216].name,"INDENYL");

		asali_->thermo_[216].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[216].high[0] = 1.6341260910e+01;
		asali_->thermo_[216].high[1] = 3.0121063814e-02;
		asali_->thermo_[216].high[2] = -1.2906793927e-05;
		asali_->thermo_[216].high[3] = 2.6318762725e-09;
		asali_->thermo_[216].high[4] = -2.1155431194e-13;
		asali_->thermo_[216].high[5] = 2.9105410156e+04;
		asali_->thermo_[216].high[6] = -6.8151000977e+01;

		asali_->thermo_[216].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[216].low[0] = -5.8171482086e+00;
		asali_->thermo_[216].low[1] = 8.5517086089e-02;
		asali_->thermo_[216].low[2] = -6.4840569394e-05;
		asali_->thermo_[216].low[3] = 2.4270947918e-08;
		asali_->thermo_[216].low[4] = -3.5926593731e-12;
		asali_->thermo_[216].low[5] = 3.6196101562e+04;
		asali_->thermo_[216].low[6] = 4.9165046692e+01;
		
		asali_->thermo_[217].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[217].name,"RMCYC6-OO");

		asali_->thermo_[217].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[217].high[0] = 2.2762430191e+01;
		asali_->thermo_[217].high[1] = 3.7729065865e-02;
		asali_->thermo_[217].high[2] = -1.5051207811e-05;
		asali_->thermo_[217].high[3] = 2.8893494264e-09;
		asali_->thermo_[217].high[4] = -2.2214039419e-13;
		asali_->thermo_[217].high[5] = -2.5374082031e+04;
		asali_->thermo_[217].high[6] = -9.9098320007e+01;

		asali_->thermo_[217].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[217].low[0] = -6.7169880867e+00;
		asali_->thermo_[217].low[1] = 1.0323888808e-01;
		asali_->thermo_[217].low[2] = -6.9642723247e-05;
		asali_->thermo_[217].low[3] = 2.3108428948e-08;
		asali_->thermo_[217].low[4] = -3.0303459395e-12;
		asali_->thermo_[217].low[5] = -1.4761491211e+04;
		asali_->thermo_[217].low[6] = 6.0450443268e+01;
		
		asali_->thermo_[218].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[218].name,"RMCYC6");

		asali_->thermo_[218].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[218].high[0] = 1.7333906174e+01;
		asali_->thermo_[218].high[1] = 3.8526080549e-02;
		asali_->thermo_[218].high[2] = -1.5831081328e-05;
		asali_->thermo_[218].high[3] = 3.1519145072e-09;
		asali_->thermo_[218].high[4] = -2.5316378226e-13;
		asali_->thermo_[218].high[5] = -5.8995795898e+03;
		asali_->thermo_[218].high[6] = -7.3383644104e+01;

		asali_->thermo_[218].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[218].low[0] = -9.9579029083e+00;
		asali_->thermo_[218].low[1] = 9.9174544215e-02;
		asali_->thermo_[218].low[2] = -6.6371467256e-05;
		asali_->thermo_[218].low[3] = 2.1870576461e-08;
		asali_->thermo_[218].low[4] = -2.8529780535e-12;
		asali_->thermo_[218].low[5] = 3.9254716797e+03;
		asali_->thermo_[218].low[6] = 7.4325325012e+01;
		
		asali_->thermo_[219].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[219].name,"C10H7CH2");

		asali_->thermo_[219].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[219].high[0] = 1.6295877457e+01;
		asali_->thermo_[219].high[1] = 4.5429673046e-02;
		asali_->thermo_[219].high[2] = -2.1352936528e-05;
		asali_->thermo_[219].high[3] = 4.7793489166e-09;
		asali_->thermo_[219].high[4] = -4.1801051552e-13;
		asali_->thermo_[219].high[5] = 2.5510082031e+04;
		asali_->thermo_[219].high[6] = -6.4773910522e+01;

		asali_->thermo_[219].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[219].low[0] = -5.2058362961e+00;
		asali_->thermo_[219].low[1] = 1.0433847457e-01;
		asali_->thermo_[219].low[2] = -8.1875681644e-05;
		asali_->thermo_[219].low[3] = 3.2415304219e-08;
		asali_->thermo_[219].low[4] = -5.1501945070e-12;
		asali_->thermo_[219].low[5] = 3.1788582031e+04;
		asali_->thermo_[219].low[6] = 4.7096454620e+01;
		
		asali_->thermo_[220].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[220].name,"C10H6CH3");

		asali_->thermo_[220].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[220].high[0] = 2.1265987396e+01;
		asali_->thermo_[220].high[1] = 3.4442942590e-02;
		asali_->thermo_[220].high[2] = -1.3960569049e-05;
		asali_->thermo_[220].high[3] = 2.7249615897e-09;
		asali_->thermo_[220].high[4] = -2.1267497041e-13;
		asali_->thermo_[220].high[5] = 3.2850753906e+04;
		asali_->thermo_[220].high[6] = -9.1152908325e+01;

		asali_->thermo_[220].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[220].low[0] = -1.9267303944e+00;
		asali_->thermo_[220].low[1] = 8.5982315242e-02;
		asali_->thermo_[220].low[2] = -5.6910048443e-05;
		asali_->thermo_[220].low[3] = 1.8632174914e-08;
		asali_->thermo_[220].low[4] = -2.4220102920e-12;
		asali_->thermo_[220].low[5] = 4.1200128906e+04;
		asali_->thermo_[220].low[6] = 3.4370922089e+01;
		
		asali_->thermo_[221].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[221].name,"C6H4CH3");

		asali_->thermo_[221].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[221].high[0] = 1.2334495544e+01;
		asali_->thermo_[221].high[1] = 2.3814707994e-02;
		asali_->thermo_[221].high[2] = -7.0172195592e-06;
		asali_->thermo_[221].high[3] = 3.5862210424e-10;
		asali_->thermo_[221].high[4] = 7.9284242203e-14;
		asali_->thermo_[221].high[5] = 2.9709169922e+04;
		asali_->thermo_[221].high[6] = -3.9424076080e+01;

		asali_->thermo_[221].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[221].low[0] = -4.1438779831e+00;
		asali_->thermo_[221].low[1] = 6.9272287190e-02;
		asali_->thermo_[221].low[2] = -5.4042306147e-05;
		asali_->thermo_[221].low[3] = 2.1979351672e-08;
		asali_->thermo_[221].low[4] = -3.6484274803e-12;
		asali_->thermo_[221].low[5] = 3.4487898438e+04;
		asali_->thermo_[221].low[6] = 4.6197315216e+01;
		
		asali_->thermo_[222].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[222].name,"RMTBE");

		asali_->thermo_[222].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[222].high[0] = 1.0926922798e+01;
		asali_->thermo_[222].high[1] = 3.7476625293e-02;
		asali_->thermo_[222].high[2] = -1.7306247173e-05;
		asali_->thermo_[222].high[3] = 3.8624139442e-09;
		asali_->thermo_[222].high[4] = -3.3911973707e-13;
		asali_->thermo_[222].high[5] = -1.8800783203e+04;
		asali_->thermo_[222].high[6] = -2.5356367111e+01;

		asali_->thermo_[222].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[222].low[0] = -1.8106944859e-01;
		asali_->thermo_[222].low[1] = 6.9908723235e-02;
		asali_->thermo_[222].low[2] = -5.2815841627e-05;
		asali_->thermo_[222].low[3] = 2.1142021467e-08;
		asali_->thermo_[222].low[4] = -3.4923327251e-12;
		asali_->thermo_[222].low[5] = -1.5757192383e+04;
		asali_->thermo_[222].low[6] = 3.1730190277e+01;
		
		asali_->thermo_[223].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[223].name,"MTBE-OO");

		asali_->thermo_[223].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[223].high[0] = 1.6480640411e+01;
		asali_->thermo_[223].high[1] = 3.4814797342e-02;
		asali_->thermo_[223].high[2] = -1.4768871551e-05;
		asali_->thermo_[223].high[3] = 3.0016553687e-09;
		asali_->thermo_[223].high[4] = -2.4135213142e-13;
		asali_->thermo_[223].high[5] = -3.5967855469e+04;
		asali_->thermo_[223].high[6] = -5.0287490845e+01;

		asali_->thermo_[223].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[223].low[0] = 2.8493034840e+00;
		asali_->thermo_[223].low[1] = 6.7860461771e-02;
		asali_->thermo_[223].low[2] = -4.4810385589e-05;
		asali_->thermo_[223].low[3] = 1.5139640652e-08;
		asali_->thermo_[223].low[4] = -2.0804408543e-12;
		asali_->thermo_[223].low[5] = -3.1469513672e+04;
		asali_->thermo_[223].low[6] = 2.2302064896e+01;
		
		asali_->thermo_[224].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[224].name,"C10H7O");

		asali_->thermo_[224].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[224].high[0] = 2.6084577560e+01;
		asali_->thermo_[224].high[1] = 2.2448880598e-02;
		asali_->thermo_[224].high[2] = -7.8624480011e-06;
		asali_->thermo_[224].high[3] = 1.2514714820e-09;
		asali_->thermo_[224].high[4] = -7.5545201605e-14;
		asali_->thermo_[224].high[5] = 1.3616839600e+03;
		asali_->thermo_[224].high[6] = -1.1783477020e+02;

		asali_->thermo_[224].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[224].low[0] = -2.5398528576e+00;
		asali_->thermo_[224].low[1] = 8.6058728397e-02;
		asali_->thermo_[224].low[2] = -6.0870654124e-05;
		asali_->thermo_[224].low[3] = 2.0884140639e-08;
		asali_->thermo_[224].low[4] = -2.8023048292e-12;
		asali_->thermo_[224].low[5] = 1.1666479492e+04;
		asali_->thermo_[224].low[6] = 3.7086624146e+01;
		
		asali_->thermo_[225].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[225].name,"NEOC5H11");

		asali_->thermo_[225].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[225].high[0] = 1.4327629089e+01;
		asali_->thermo_[225].high[1] = 2.6684558019e-02;
		asali_->thermo_[225].high[2] = -1.0215826478e-05;
		asali_->thermo_[225].high[3] = 1.8692909443e-09;
		asali_->thermo_[225].high[4] = -1.3580331521e-13;
		asali_->thermo_[225].high[5] = -2.9421643066e+03;
		asali_->thermo_[225].high[6] = -5.1514575958e+01;

		asali_->thermo_[225].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[225].low[0] = -1.2968970537e+00;
		asali_->thermo_[225].low[1] = 6.4108572900e-02;
		asali_->thermo_[225].low[2] = -4.3830212235e-05;
		asali_->thermo_[225].low[3] = 1.5288206257e-08;
		asali_->thermo_[225].low[4] = -2.1446230208e-12;
		asali_->thermo_[225].low[5] = 2.2764274902e+03;
		asali_->thermo_[225].low[6] = 3.1877355576e+01;
		
		asali_->thermo_[226].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[226].name,"NEOC5H11-OO");

		asali_->thermo_[226].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[226].high[0] = 1.6998973846e+01;
		asali_->thermo_[226].high[1] = 3.0160149559e-02;
		asali_->thermo_[226].high[2] = -1.1925489162e-05;
		asali_->thermo_[226].high[3] = 2.2582236081e-09;
		asali_->thermo_[226].high[4] = -1.6987894923e-13;
		asali_->thermo_[226].high[5] = -2.1046457031e+04;
		asali_->thermo_[226].high[6] = -6.1461772919e+01;

		asali_->thermo_[226].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[226].low[0] = 1.0791094303e+00;
		asali_->thermo_[226].low[1] = 6.8521268666e-02;
		asali_->thermo_[226].low[2] = -4.6589149861e-05;
		asali_->thermo_[226].low[3] = 1.6179372508e-08;
		asali_->thermo_[226].low[4] = -2.2664374717e-12;
		asali_->thermo_[226].low[5] = -1.5761062500e+04;
		asali_->thermo_[226].low[6] = 2.3410833359e+01;
		
		asali_->thermo_[227].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[227].name,"C16H9");

		asali_->thermo_[227].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[227].high[0] = 1.6193397522e+01;
		asali_->thermo_[227].high[1] = 6.9611713290e-02;
		asali_->thermo_[227].high[2] = -3.7105412048e-05;
		asali_->thermo_[227].high[3] = 9.4382599514e-09;
		asali_->thermo_[227].high[4] = -9.3251589176e-13;
		asali_->thermo_[227].high[5] = 4.6100835938e+04;
		asali_->thermo_[227].high[6] = -6.5425621033e+01;

		asali_->thermo_[227].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[227].low[0] = -1.3338268280e+01;
		asali_->thermo_[227].low[1] = 1.6487514973e-01;
		asali_->thermo_[227].low[2] = -1.5234344755e-04;
		asali_->thermo_[227].low[3] = 7.1394190115e-08;
		asali_->thermo_[227].low[4] = -1.3423631130e-11;
		asali_->thermo_[227].low[5] = 5.3424687500e+04;
		asali_->thermo_[227].low[6] = 8.3400192261e+01;
		
		asali_->thermo_[228].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[228].name,"C6H5C2H2");

		asali_->thermo_[228].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[228].high[0] = 1.7715560913e+01;
		asali_->thermo_[228].high[1] = 2.1904317662e-02;
		asali_->thermo_[228].high[2] = -8.0739127952e-06;
		asali_->thermo_[228].high[3] = 1.3947419886e-09;
		asali_->thermo_[228].high[4] = -9.4152435143e-14;
		asali_->thermo_[228].high[5] = 3.8139449219e+04;
		asali_->thermo_[228].high[6] = -7.0111419678e+01;

		asali_->thermo_[228].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[228].low[0] = -2.5084877014e+00;
		asali_->thermo_[228].low[1] = 6.9771885872e-02;
		asali_->thermo_[228].low[2] = -5.0559920055e-05;
		asali_->thermo_[228].low[3] = 1.8154509007e-08;
		asali_->thermo_[228].low[4] = -2.5734078497e-12;
		asali_->thermo_[228].low[5] = 4.4975175781e+04;
		asali_->thermo_[228].low[6] = 3.8070053101e+01;
		
		asali_->thermo_[229].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[229].name,"RXYLENE");

		asali_->thermo_[229].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[229].high[0] = 9.5060615540e+00;
		asali_->thermo_[229].high[1] = 4.1593931615e-02;
		asali_->thermo_[229].high[2] = -1.7947177184e-05;
		asali_->thermo_[229].high[3] = 3.4186198317e-09;
		asali_->thermo_[229].high[4] = -2.3602043171e-13;
		asali_->thermo_[229].high[5] = 1.4696906250e+04;
		asali_->thermo_[229].high[6] = -2.5956739426e+01;

		asali_->thermo_[229].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[229].low[0] = -2.8092045784e+00;
		asali_->thermo_[229].low[1] = 7.7290356159e-02;
		asali_->thermo_[229].low[2] = -5.6747638155e-05;
		asali_->thermo_[229].low[3] = 2.2162804925e-08;
		asali_->thermo_[229].low[4] = -3.6317060470e-12;
		asali_->thermo_[229].low[5] = 1.8095919922e+04;
		asali_->thermo_[229].low[6] = 3.7423847198e+01;
		
		asali_->thermo_[230].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[230].name,"C6H5C2H3");

		asali_->thermo_[230].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[230].high[0] = 1.5761212349e+01;
		asali_->thermo_[230].high[1] = 2.5134472176e-02;
		asali_->thermo_[230].high[2] = -7.0834894359e-06;
		asali_->thermo_[230].high[3] = 3.1235583564e-10;
		asali_->thermo_[230].high[4] = 8.2298581741e-14;
		asali_->thermo_[230].high[5] = 1.0134689453e+04;
		asali_->thermo_[230].high[6] = -5.9585994720e+01;

		asali_->thermo_[230].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[230].low[0] = -4.6189041138e+00;
		asali_->thermo_[230].low[1] = 8.2543253899e-02;
		asali_->thermo_[230].low[2] = -6.7726563429e-05;
		asali_->thermo_[230].low[3] = 2.8783283312e-08;
		asali_->thermo_[230].low[4] = -4.9301886358e-12;
		asali_->thermo_[230].low[5] = 1.5922642578e+04;
		asali_->thermo_[230].low[6] = 4.5882713318e+01;
		
		asali_->thermo_[231].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[231].name,"TAME");

		asali_->thermo_[231].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[231].high[0] = 1.1330976486e+01;
		asali_->thermo_[231].high[1] = 4.7428093851e-02;
		asali_->thermo_[231].high[2] = -1.9695749870e-05;
		asali_->thermo_[231].high[3] = 3.6686074179e-09;
		asali_->thermo_[231].high[4] = -2.5068822344e-13;
		asali_->thermo_[231].high[5] = -4.4274519531e+04;
		asali_->thermo_[231].high[6] = -3.1795238495e+01;

		asali_->thermo_[231].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[231].low[0] = -2.1283671856e+00;
		asali_->thermo_[231].low[1] = 8.8213980198e-02;
		asali_->thermo_[231].low[2] = -6.6043350671e-05;
		asali_->thermo_[231].low[3] = 2.7076486830e-08;
		asali_->thermo_[231].low[4] = -4.6839988485e-12;
		asali_->thermo_[231].low[5] = -4.0721253906e+04;
		asali_->thermo_[231].low[6] = 3.6875053406e+01;
		
		asali_->thermo_[232].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[232].name,"TETRALIN");

		asali_->thermo_[232].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[232].high[0] = 2.4025068283e+01;
		asali_->thermo_[232].high[1] = 3.4503169358e-02;
		asali_->thermo_[232].high[2] = -1.2656553736e-05;
		asali_->thermo_[232].high[3] = 2.2063246785e-09;
		asali_->thermo_[232].high[4] = -1.5194120376e-13;
		asali_->thermo_[232].high[5] = -9.8531435547e+03;
		asali_->thermo_[232].high[6] = -1.1116176605e+02;

		asali_->thermo_[232].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[232].low[0] = -1.0080733299e+01;
		asali_->thermo_[232].low[1] = 1.1718390137e-01;
		asali_->thermo_[232].low[2] = -8.7820852059e-05;
		asali_->thermo_[232].low[3] = 3.2575737663e-08;
		asali_->thermo_[232].low[4] = -4.7533678382e-12;
		asali_->thermo_[232].low[5] = 1.4017711182e+03;
		asali_->thermo_[232].low[6] = 7.0458351135e+01;
		
		asali_->thermo_[233].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[233].name,"DECALIN");

		asali_->thermo_[233].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[233].high[0] = 2.7011030197e+01;
		asali_->thermo_[233].high[1] = 4.6874817461e-02;
		asali_->thermo_[233].high[2] = -1.6389549273e-05;
		asali_->thermo_[233].high[3] = 2.6256368191e-09;
		asali_->thermo_[233].high[4] = -1.5978972973e-13;
		asali_->thermo_[233].high[5] = -3.7922628906e+04;
		asali_->thermo_[233].high[6] = -1.3516773987e+02;

		asali_->thermo_[233].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[233].low[0] = -1.4587078094e+01;
		asali_->thermo_[233].low[1] = 1.4195621014e-01;
		asali_->thermo_[233].low[2] = -9.7887881566e-05;
		asali_->thermo_[233].low[3] = 3.3672620248e-08;
		asali_->thermo_[233].low[4] = -4.5950730200e-12;
		asali_->thermo_[233].low[5] = -2.3363291016e+04;
		asali_->thermo_[233].low[6] = 8.8798034668e+01;
		
		asali_->thermo_[234].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[234].name,"RDECALIN");

		asali_->thermo_[234].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[234].high[0] = 2.8562032700e+01;
		asali_->thermo_[234].high[1] = 4.1136641055e-02;
		asali_->thermo_[234].high[2] = -1.3602410945e-05;
		asali_->thermo_[234].high[3] = 2.0159278691e-09;
		asali_->thermo_[234].high[4] = -1.0937662587e-13;
		asali_->thermo_[234].high[5] = -1.5302505859e+04;
		asali_->thermo_[234].high[6] = -1.3964169312e+02;

		asali_->thermo_[234].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[234].low[0] = -1.3960130692e+01;
		asali_->thermo_[234].low[1] = 1.3563033938e-01;
		asali_->thermo_[234].low[2] = -9.2347159807e-05;
		asali_->thermo_[234].low[3] = 3.1180650950e-08;
		asali_->thermo_[234].low[4] = -4.1600325615e-12;
		asali_->thermo_[234].low[5] = 5.4727807045e+00;
		asali_->thermo_[234].low[6] = 9.0497138977e+01;
		
		asali_->thermo_[235].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[235].name,"C7H8");

		asali_->thermo_[235].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[235].high[0] = 1.2581844330e+01;
		asali_->thermo_[235].high[1] = 2.6413451880e-02;
		asali_->thermo_[235].high[2] = -7.9379988165e-06;
		asali_->thermo_[235].high[3] = 4.3836823060e-10;
		asali_->thermo_[235].high[4] = 8.6407897710e-14;
		asali_->thermo_[235].high[5] = -5.6447131348e+02;
		asali_->thermo_[235].high[6] = -4.4524784088e+01;

		asali_->thermo_[235].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[235].low[0] = -6.0288496017e+00;
		asali_->thermo_[235].low[1] = 7.7753297985e-02;
		asali_->thermo_[235].low[2] = -6.1048187490e-05;
		asali_->thermo_[235].low[3] = 2.4856843694e-08;
		asali_->thermo_[235].low[4] = -4.1236740585e-12;
		asali_->thermo_[235].low[5] = 4.8326298828e+03;
		asali_->thermo_[235].low[6] = 5.2176113129e+01;
		
		asali_->thermo_[236].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[236].name,"C2H3");

		asali_->thermo_[236].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[236].high[0] = 7.0509421825e-01;
		asali_->thermo_[236].high[1] = 1.5376115218e-02;
		asali_->thermo_[236].high[2] = -8.9178820417e-06;
		asali_->thermo_[236].high[3] = 2.5134090365e-09;
		asali_->thermo_[236].high[4] = -2.7056164926e-13;
		asali_->thermo_[236].high[5] = 3.3618949219e+04;
		asali_->thermo_[236].high[6] = 1.9653188705e+01;

		asali_->thermo_[236].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[236].low[0] = 2.7460670471e+00;
		asali_->thermo_[236].low[1] = 3.7134126760e-03;
		asali_->thermo_[236].low[2] = 1.6073621737e-05;
		asali_->thermo_[236].low[3] = -2.1288023788e-08;
		asali_->thermo_[236].low[4] = 8.2299497078e-12;
		asali_->thermo_[236].low[5] = 3.3333214844e+04;
		asali_->thermo_[236].low[6] = 1.0534637451e+01;
		
		asali_->thermo_[237].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[237].name,"XYLENE");

		asali_->thermo_[237].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[237].high[0] = 1.7225624084e+01;
		asali_->thermo_[237].high[1] = 2.8356559575e-02;
		asali_->thermo_[237].high[2] = -6.9068996709e-06;
		asali_->thermo_[237].high[3] = -3.5709141200e-10;
		asali_->thermo_[237].high[4] = 2.0941962628e-13;
		asali_->thermo_[237].high[5] = -6.8723935547e+03;
		asali_->thermo_[237].high[6] = -6.9734161377e+01;

		asali_->thermo_[237].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[237].low[0] = -5.1230397224e+00;
		asali_->thermo_[237].low[1] = 8.2865498960e-02;
		asali_->thermo_[237].low[2] = -5.6762633903e-05;
		asali_->thermo_[237].low[3] = 1.9909467852e-08;
		asali_->thermo_[237].low[4] = -2.8799948537e-12;
		asali_->thermo_[237].low[5] = 4.5796841431e+02;
		asali_->thermo_[237].low[6] = 4.9141025543e+01;
		
		asali_->thermo_[238].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[238].name,"NC10-OOQOOH");

		asali_->thermo_[238].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[238].high[0] = 4.0808773041e+01;
		asali_->thermo_[238].high[1] = 4.9633953720e-02;
		asali_->thermo_[238].high[2] = -1.8142012777e-05;
		asali_->thermo_[238].high[3] = 3.1200673156e-09;
		asali_->thermo_[238].high[4] = -2.1117564078e-13;
		asali_->thermo_[238].high[5] = -5.6543296875e+04;
		asali_->thermo_[238].high[6] = -1.7381101990e+02;

		asali_->thermo_[238].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[238].low[0] = 2.6270132065e+00;
		asali_->thermo_[238].low[1] = 1.3448230922e-01;
		asali_->thermo_[238].low[2] = -8.8848973974e-05;
		asali_->thermo_[238].low[3] = 2.9307830829e-08;
		asali_->thermo_[238].low[4] = -3.8483652029e-12;
		asali_->thermo_[238].low[5] = -4.2797863281e+04;
		asali_->thermo_[238].low[6] = 3.2836624146e+01;
		
		asali_->thermo_[239].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[239].name,"NC12-OOQOOH");

		asali_->thermo_[239].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[239].high[0] = 4.6888965607e+01;
		asali_->thermo_[239].high[1] = 5.8443967253e-02;
		asali_->thermo_[239].high[2] = -2.0949157260e-05;
		asali_->thermo_[239].high[3] = 3.4989759978e-09;
		asali_->thermo_[239].high[4] = -2.2732494056e-13;
		asali_->thermo_[239].high[5] = -6.4548789062e+04;
		asali_->thermo_[239].high[6] = -2.0326210022e+02;

		asali_->thermo_[239].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[239].low[0] = 2.7593235970e+00;
		asali_->thermo_[239].low[1] = 1.5650984645e-01;
		asali_->thermo_[239].low[2] = -1.0267071775e-04;
		asali_->thermo_[239].low[3] = 3.3766220042e-08;
		asali_->thermo_[239].low[4] = -4.4311091255e-12;
		asali_->thermo_[239].low[5] = -4.8662117188e+04;
		asali_->thermo_[239].low[6] = 3.5576728821e+01;
		
		asali_->thermo_[240].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[240].name,"NC4-OOQOOH");

		asali_->thermo_[240].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[240].high[0] = 1.5147411346e+01;
		asali_->thermo_[240].high[1] = 3.3781282604e-02;
		asali_->thermo_[240].high[2] = -1.5899682694e-05;
		asali_->thermo_[240].high[3] = 3.5760878703e-09;
		asali_->thermo_[240].high[4] = -3.1448652818e-13;
		asali_->thermo_[240].high[5] = -2.8569886719e+04;
		asali_->thermo_[240].high[6] = -4.2473220825e+01;

		asali_->thermo_[240].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[240].low[0] = 1.1012347937e+00;
		asali_->thermo_[240].low[1] = 7.9459905624e-02;
		asali_->thermo_[240].low[2] = -7.1605318226e-05;
		asali_->thermo_[240].low[3] = 3.3768845498e-08;
		asali_->thermo_[240].low[4] = -6.4512258383e-12;
		asali_->thermo_[240].low[5] = -2.5114527344e+04;
		asali_->thermo_[240].low[6] = 2.8199218750e+01;
		
		asali_->thermo_[241].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[241].name,"NC5-OOQOOH");

		asali_->thermo_[241].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[241].high[0] = 1.5463847160e+01;
		asali_->thermo_[241].high[1] = 4.3053198606e-02;
		asali_->thermo_[241].high[2] = -2.0428473363e-05;
		asali_->thermo_[241].high[3] = 4.6317474300e-09;
		asali_->thermo_[241].high[4] = -4.1027199541e-13;
		asali_->thermo_[241].high[5] = -3.1741335938e+04;
		asali_->thermo_[241].high[6] = -4.3140689850e+01;

		asali_->thermo_[241].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[241].low[0] = 1.4326556921e+00;
		asali_->thermo_[241].low[1] = 8.7245926261e-02;
		asali_->thermo_[241].low[2] = -7.2624614404e-05;
		asali_->thermo_[241].low[3] = 3.2031294950e-08;
		asali_->thermo_[241].low[4] = -5.8038838492e-12;
		asali_->thermo_[241].low[5] = -2.8177414062e+04;
		asali_->thermo_[241].low[6] = 2.7905389786e+01;
		
		asali_->thermo_[242].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[242].name,"NC7-OOQOOH");

		asali_->thermo_[242].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[242].high[0] = 2.2469406128e+01;
		asali_->thermo_[242].high[1] = 4.2930707335e-02;
		asali_->thermo_[242].high[2] = -1.6891015548e-05;
		asali_->thermo_[242].high[3] = 3.1843108150e-09;
		asali_->thermo_[242].high[4] = -2.3859245742e-13;
		asali_->thermo_[242].high[5] = -4.5896292969e+04;
		asali_->thermo_[242].high[6] = -7.9347236633e+01;

		asali_->thermo_[242].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[242].low[0] = 2.8743050098e+00;
		asali_->thermo_[242].low[1] = 8.9309647679e-02;
		asali_->thermo_[242].low[2] = -5.8055753470e-05;
		asali_->thermo_[242].low[3] = 1.9422866870e-08;
		asali_->thermo_[242].low[4] = -2.6407456950e-12;
		asali_->thermo_[242].low[5] = -3.9273148438e+04;
		asali_->thermo_[242].low[6] = 2.5469907761e+01;
		
		asali_->thermo_[243].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[243].name,"DME-OOQOOH");

		asali_->thermo_[243].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[243].high[0] = 9.5798912048e+00;
		asali_->thermo_[243].high[1] = 2.5336032733e-02;
		asali_->thermo_[243].high[2] = -1.1370688298e-05;
		asali_->thermo_[243].high[3] = 2.4569069002e-09;
		asali_->thermo_[243].high[4] = -2.0929570197e-13;
		asali_->thermo_[243].high[5] = -3.4819964844e+04;
		asali_->thermo_[243].high[6] = -1.1603190422e+01;

		asali_->thermo_[243].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[243].low[0] = 7.8548774719e+00;
		asali_->thermo_[243].low[1] = 2.9169397429e-02;
		asali_->thermo_[243].low[2] = -1.4565159290e-05;
		asali_->thermo_[243].low[3] = 3.6400440440e-09;
		asali_->thermo_[243].low[4] = -3.7362029703e-13;
		asali_->thermo_[243].low[5] = -3.4198960938e+04;
		asali_->thermo_[243].low[6] = -2.2670550346e+00;
		
		asali_->thermo_[244].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[244].name,"IC16-OOQOOH");

		asali_->thermo_[244].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[244].high[0] = 4.2112209320e+01;
		asali_->thermo_[244].high[1] = 1.1183412373e-01;
		asali_->thermo_[244].high[2] = -5.1197846915e-05;
		asali_->thermo_[244].high[3] = 1.1254146060e-08;
		asali_->thermo_[244].high[4] = -9.7253401079e-13;
		asali_->thermo_[244].high[5] = -7.8934351562e+04;
		asali_->thermo_[244].high[6] = -1.8049557495e+02;

		asali_->thermo_[244].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[244].low[0] = -6.5428981781e+00;
		asali_->thermo_[244].low[1] = 2.4889077246e-01;
		asali_->thermo_[244].low[2] = -1.9597599749e-04;
		asali_->thermo_[244].low[3] = 7.9225110028e-08;
		asali_->thermo_[244].low[4] = -1.2939252100e-11;
		asali_->thermo_[244].low[5] = -6.5116296875e+04;
		asali_->thermo_[244].low[6] = 7.1298454285e+01;
		
		asali_->thermo_[245].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->thermo_[245].name,"IC16T-OOQOOH");

		asali_->thermo_[245].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[245].high[0] = 4.0776912689e+01;
		asali_->thermo_[245].high[1] = 1.1513596773e-01;
		asali_->thermo_[245].high[2] = -5.3631913033e-05;
		asali_->thermo_[245].high[3] = 1.1982691284e-08;
		asali_->thermo_[245].high[4] = -1.0498988831e-12;
		asali_->thermo_[245].high[5] = -8.1682125000e+04;
		asali_->thermo_[245].high[6] = -1.7450932312e+02;

		asali_->thermo_[245].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[245].low[0] = -7.0878119469e+00;
		asali_->thermo_[245].low[1] = 2.5488698483e-01;
		asali_->thermo_[245].low[2] = -2.0664397744e-04;
		asali_->thermo_[245].low[3] = 8.6441112046e-08;
		asali_->thermo_[245].low[4] = -1.4637202908e-11;
		asali_->thermo_[245].low[5] = -6.8567187500e+04;
		asali_->thermo_[245].low[6] = 7.1478630066e+01;
		
		asali_->thermo_[246].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[246].name,"IC8-OOQOOH");

		asali_->thermo_[246].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[246].high[0] = 3.4831420898e+01;
		asali_->thermo_[246].high[1] = 3.9814610034e-02;
		asali_->thermo_[246].high[2] = -1.4397834093e-05;
		asali_->thermo_[246].high[3] = 2.4227357898e-09;
		asali_->thermo_[246].high[4] = -1.5798811098e-13;
		asali_->thermo_[246].high[5] = -5.0122738281e+04;
		asali_->thermo_[246].high[6] = -1.4533451843e+02;

		asali_->thermo_[246].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[246].low[0] = 1.7639132738e+00;
		asali_->thermo_[246].low[1] = 1.1716550589e-01;
		asali_->thermo_[246].low[2] = -8.2249498519e-05;
		asali_->thermo_[246].low[3] = 2.8875627223e-08;
		asali_->thermo_[246].low[4] = -4.0253698812e-12;
		asali_->thermo_[246].low[5] = -3.8813648438e+04;
		asali_->thermo_[246].low[6] = 3.1937599182e+01;
		
		asali_->thermo_[247].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[247].name,"IC4P-OOQOOH");

		asali_->thermo_[247].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[247].high[0] = 1.3051844597e+01;
		asali_->thermo_[247].high[1] = 3.6548480392e-02;
		asali_->thermo_[247].high[2] = -1.7427477360e-05;
		asali_->thermo_[247].high[3] = 3.9674197261e-09;
		asali_->thermo_[247].high[4] = -3.5255202620e-13;
		asali_->thermo_[247].high[5] = -2.4709613281e+04;
		asali_->thermo_[247].high[6] = -3.0433469772e+01;

		asali_->thermo_[247].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[247].low[0] = 1.6451178789e+00;
		asali_->thermo_[247].low[1] = 7.1918174624e-02;
		asali_->thermo_[247].low[2] = -5.8555029682e-05;
		asali_->thermo_[247].low[3] = 2.5221968514e-08;
		asali_->thermo_[247].low[4] = -4.4716509141e-12;
		asali_->thermo_[247].low[5] = -2.1766677734e+04;
		asali_->thermo_[247].low[6] = 2.7502027512e+01;
		
		asali_->thermo_[248].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[248].name,"IC4T-OOQOOH");

		asali_->thermo_[248].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[248].high[0] = 1.3993978500e+01;
		asali_->thermo_[248].high[1] = 3.5484522581e-02;
		asali_->thermo_[248].high[2] = -1.6891506675e-05;
		asali_->thermo_[248].high[3] = 3.8367109489e-09;
		asali_->thermo_[248].high[4] = -3.4013162295e-13;
		asali_->thermo_[248].high[5] = -2.8361451172e+04;
		asali_->thermo_[248].high[6] = -3.7053108215e+01;

		asali_->thermo_[248].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[248].low[0] = 1.5509439707e+00;
		asali_->thermo_[248].low[1] = 7.5623340905e-02;
		asali_->thermo_[248].low[2] = -6.5446532972e-05;
		asali_->thermo_[248].low[3] = 2.9941563895e-08;
		asali_->thermo_[248].low[4] = -5.6032067007e-12;
		asali_->thermo_[248].low[5] = -2.5275580078e+04;
		asali_->thermo_[248].low[6] = 2.5653976440e+01;
		
		asali_->thermo_[249].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->thermo_[249].name,"MCYC6-OOQOOH");

		asali_->thermo_[249].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[249].high[0] = 3.1458761215e+01;
		asali_->thermo_[249].high[1] = 3.1296148896e-02;
		asali_->thermo_[249].high[2] = -1.0660421140e-05;
		asali_->thermo_[249].high[3] = 1.6276945347e-09;
		asali_->thermo_[249].high[4] = -9.1507361313e-14;
		asali_->thermo_[249].high[5] = -4.0852667969e+04;
		asali_->thermo_[249].high[6] = -1.4071832275e+02;

		asali_->thermo_[249].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[249].low[0] = -4.2931709290e+00;
		asali_->thermo_[249].low[1] = 1.1209147424e-01;
		asali_->thermo_[249].low[2] = -7.9131037637e-05;
		asali_->thermo_[249].low[3] = 2.7417003778e-08;
		asali_->thermo_[249].low[4] = -3.7340651404e-12;
		asali_->thermo_[249].low[5] = -2.8196482422e+04;
		asali_->thermo_[249].low[6] = 5.2177711487e+01;
		
		asali_->thermo_[250].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[250].name,"MTBE-OOQOOH");

		asali_->thermo_[250].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[250].high[0] = 1.7005329132e+01;
		asali_->thermo_[250].high[1] = 4.3126046658e-02;
		asali_->thermo_[250].high[2] = -1.9957315089e-05;
		asali_->thermo_[250].high[3] = 4.4465857663e-09;
		asali_->thermo_[250].high[4] = -3.8931485531e-13;
		asali_->thermo_[250].high[5] = -4.6430296875e+04;
		asali_->thermo_[250].high[6] = -4.6132820129e+01;

		asali_->thermo_[250].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[250].low[0] = 4.6546916962e+00;
		asali_->thermo_[250].low[1] = 7.9451449215e-02;
		asali_->thermo_[250].low[2] = -6.0022099206e-05;
		asali_->thermo_[250].low[3] = 2.4086185491e-08;
		asali_->thermo_[250].low[4] = -3.9995355118e-12;
		asali_->thermo_[250].low[5] = -4.3070921875e+04;
		asali_->thermo_[250].low[6] = 1.7249498367e+01;
		
		asali_->thermo_[251].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->thermo_[251].name,"NEOC5-OOQOOH");

		asali_->thermo_[251].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[251].high[0] = 2.5308828354e+01;
		asali_->thermo_[251].high[1] = 2.4600846693e-02;
		asali_->thermo_[251].high[2] = -8.3858485596e-06;
		asali_->thermo_[251].high[3] = 1.2844622033e-09;
		asali_->thermo_[251].high[4] = -7.2549198636e-14;
		asali_->thermo_[251].high[5] = -3.5266210938e+04;
		asali_->thermo_[251].high[6] = -9.8869316101e+01;

		asali_->thermo_[251].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[251].low[0] = 2.9399299622e+00;
		asali_->thermo_[251].low[1] = 7.4309505522e-02;
		asali_->thermo_[251].low[2] = -4.9809732445e-05;
		asali_->thermo_[251].low[3] = 1.6626641397e-08;
		asali_->thermo_[251].low[4] = -2.2034075953e-12;
		asali_->thermo_[251].low[5] = -2.7213408203e+04;
		asali_->thermo_[251].low[6] = 2.2195827484e+01;
		
		asali_->thermo_[252].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->thermo_[252].name,"MCYC6T-OOQOOH");

		asali_->thermo_[252].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[252].high[0] = 3.1458761215e+01;
		asali_->thermo_[252].high[1] = 3.1296148896e-02;
		asali_->thermo_[252].high[2] = -1.0660421140e-05;
		asali_->thermo_[252].high[3] = 1.6276945347e-09;
		asali_->thermo_[252].high[4] = -9.1507361313e-14;
		asali_->thermo_[252].high[5] = -4.0852667969e+04;
		asali_->thermo_[252].high[6] = -1.4071832275e+02;

		asali_->thermo_[252].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[252].low[0] = -4.2931709290e+00;
		asali_->thermo_[252].low[1] = 1.1209147424e-01;
		asali_->thermo_[252].low[2] = -7.9131037637e-05;
		asali_->thermo_[252].low[3] = 2.7417003778e-08;
		asali_->thermo_[252].low[4] = -3.7340651404e-12;
		asali_->thermo_[252].low[5] = -2.8196482422e+04;
		asali_->thermo_[252].low[6] = 5.2177711487e+01;
		
		asali_->thermo_[253].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[253].name,"NC16H34");

		asali_->thermo_[253].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[253].high[0] = 4.9821022034e+01;
		asali_->thermo_[253].high[1] = 7.7388167381e-02;
		asali_->thermo_[253].high[2] = -2.7755790143e-05;
		asali_->thermo_[253].high[3] = 4.6967811862e-09;
		asali_->thermo_[253].high[4] = -3.1295923969e-13;
		asali_->thermo_[253].high[5] = -7.0851468750e+04;
		asali_->thermo_[253].high[6] = -2.2484284973e+02;

		asali_->thermo_[253].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[253].low[0] = -3.6405797005e+00;
		asali_->thermo_[253].low[1] = 1.9619172812e-01;
		asali_->thermo_[253].low[2] = -1.2675876496e-04;
		asali_->thermo_[253].low[3] = 4.1364547343e-08;
		asali_->thermo_[253].low[4] = -5.4057045298e-12;
		asali_->thermo_[253].low[5] = -5.1605289062e+04;
		asali_->thermo_[253].low[6] = 6.4502494812e+01;
		
		asali_->thermo_[254].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[254].name,"NC16H33");

		asali_->thermo_[254].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[254].high[0] = 4.6627838135e+01;
		asali_->thermo_[254].high[1] = 8.0021224916e-02;
		asali_->thermo_[254].high[2] = -3.0323633837e-05;
		asali_->thermo_[254].high[3] = 5.5590363424e-09;
		asali_->thermo_[254].high[4] = -4.0982256651e-13;
		asali_->thermo_[254].high[5] = -4.6154519531e+04;
		asali_->thermo_[254].high[6] = -2.0401948547e+02;

		asali_->thermo_[254].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[254].low[0] = -3.2241337299e+00;
		asali_->thermo_[254].low[1] = 1.9080337882e-01;
		asali_->thermo_[254].low[2] = -1.2264210091e-04;
		asali_->thermo_[254].low[3] = 3.9751061109e-08;
		asali_->thermo_[254].low[4] = -5.1587146013e-12;
		asali_->thermo_[254].low[5] = -2.8207810547e+04;
		asali_->thermo_[254].low[6] = 6.5789787292e+01;
		
		asali_->thermo_[255].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[255].name,"NC16H33-OO");

		asali_->thermo_[255].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[255].high[0] = 5.0034446716e+01;
		asali_->thermo_[255].high[1] = 8.2007013261e-02;
		asali_->thermo_[255].high[2] = -3.0304299798e-05;
		asali_->thermo_[255].high[3] = 5.2801669703e-09;
		asali_->thermo_[255].high[4] = -3.6202283033e-13;
		asali_->thermo_[255].high[5] = -6.4704585938e+04;
		asali_->thermo_[255].high[6] = -2.1813720703e+02;

		asali_->thermo_[255].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[255].low[0] = 8.6509668827e-01;
		asali_->thermo_[255].low[1] = 1.9127224386e-01;
		asali_->thermo_[255].low[2] = -1.2135865109e-04;
		asali_->thermo_[255].low[3] = 3.9004003582e-08;
		asali_->thermo_[255].low[4] = -5.0458890538e-12;
		asali_->thermo_[255].low[5] = -4.7003621094e+04;
		asali_->thermo_[255].low[6] = 4.7977584839e+01;
		
		asali_->thermo_[256].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[256].name,"NC16-QOOH");

		asali_->thermo_[256].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[256].high[0] = 5.4963470459e+01;
		asali_->thermo_[256].high[1] = 7.7466219664e-02;
		asali_->thermo_[256].high[2] = -2.7126590794e-05;
		asali_->thermo_[256].high[3] = 4.3695389529e-09;
		asali_->thermo_[256].high[4] = -2.6871961687e-13;
		asali_->thermo_[256].high[5] = -8.4994921875e+04;
		asali_->thermo_[256].high[6] = -2.4682595825e+02;

		asali_->thermo_[256].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[256].low[0] = 8.0284260213e-02;
		asali_->thermo_[256].low[1] = 1.9942885637e-01;
		asali_->thermo_[256].low[2] = -1.2876211258e-04;
		asali_->thermo_[256].low[3] = 4.2012327839e-08;
		asali_->thermo_[256].low[4] = -5.4968846315e-12;
		asali_->thermo_[256].low[5] = -6.5236976562e+04;
		asali_->thermo_[256].low[6] = 5.0213283539e+01;
		
		asali_->thermo_[257].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[257].name,"NC16-OOQOOH");

		asali_->thermo_[257].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[257].high[0] = 5.8392593384e+01;
		asali_->thermo_[257].high[1] = 7.8749030828e-02;
		asali_->thermo_[257].high[2] = -2.8698723327e-05;
		asali_->thermo_[257].high[3] = 4.9094399657e-09;
		asali_->thermo_[257].high[4] = -3.2940330693e-13;
		asali_->thermo_[257].high[5] = -8.0506156250e+04;
		asali_->thermo_[257].high[6] = -2.5920901489e+02;

		asali_->thermo_[257].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[257].low[0] = 2.1451902390e+00;
		asali_->thermo_[257].low[1] = 2.0374324918e-01;
		asali_->thermo_[257].low[2] = -1.3286057219e-04;
		asali_->thermo_[257].low[3] = 4.3487904833e-08;
		asali_->thermo_[257].low[4] = -5.6875233689e-12;
		asali_->thermo_[257].low[5] = -6.0257089844e+04;
		asali_->thermo_[257].low[6] = 4.5213649750e+01;
		
		asali_->thermo_[258].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[258].name,"NC16-OQOOH");

		asali_->thermo_[258].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[258].high[0] = 4.8844131470e+01;
		asali_->thermo_[258].high[1] = 8.4783315659e-02;
		asali_->thermo_[258].high[2] = -3.1757750548e-05;
		asali_->thermo_[258].high[3] = 5.5670272836e-09;
		asali_->thermo_[258].high[4] = -3.8233148201e-13;
		asali_->thermo_[258].high[5] = -9.5080890625e+04;
		asali_->thermo_[258].high[6] = -2.0720263672e+02;

		asali_->thermo_[258].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[258].low[0] = 1.7504069805e+00;
		asali_->thermo_[258].low[1] = 1.9624774158e-01;
		asali_->thermo_[258].low[2] = -1.3069067791e-04;
		asali_->thermo_[258].low[3] = 4.4593821968e-08;
		asali_->thermo_[258].low[4] = -6.1555261756e-12;
		asali_->thermo_[258].low[5] = -7.9163210938e+04;
		asali_->thermo_[258].low[6] = 4.4708778381e+01;
		
		asali_->thermo_[259].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->thermo_[259].name,"CN");

		asali_->thermo_[259].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[259].high[0] = 2.7385959625e+00;
		asali_->thermo_[259].high[1] = 2.2358095739e-03;
		asali_->thermo_[259].high[2] = -1.3379702750e-06;
		asali_->thermo_[259].high[3] = 4.3499642777e-10;
		asali_->thermo_[259].high[4] = -5.0522262697e-14;
		asali_->thermo_[259].high[5] = 5.1456882812e+04;
		asali_->thermo_[259].high[6] = 8.2048006058e+00;

		asali_->thermo_[259].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[259].low[0] = 4.0853266716e+00;
		asali_->thermo_[259].low[1] = -4.4147130102e-03;
		asali_->thermo_[259].low[2] = 1.0977812053e-05;
		asali_->thermo_[259].low[3] = -9.7014503098e-09;
		asali_->thermo_[259].low[4] = 3.0780105027e-12;
		asali_->thermo_[259].low[5] = 5.1238714844e+04;
		asali_->thermo_[259].low[6] = 1.9913876057e+00;
		
		asali_->thermo_[260].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[260].name,"H2CN");

		asali_->thermo_[260].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[260].high[0] = 5.2211132050e+00;
		asali_->thermo_[260].high[1] = 3.4264749847e-03;
		asali_->thermo_[260].high[2] = -8.3613781499e-07;
		asali_->thermo_[260].high[3] = 4.7483302013e-11;
		asali_->thermo_[260].high[4] = 4.2815334374e-15;
		asali_->thermo_[260].high[5] = 2.7531236328e+04;
		asali_->thermo_[260].high[6] = -4.8026223183e+00;

		asali_->thermo_[260].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[260].low[0] = 1.8135457039e+00;
		asali_->thermo_[260].low[1] = 1.0998846963e-02;
		asali_->thermo_[260].low[2] = -7.1464478424e-06;
		asali_->thermo_[260].low[3] = 2.3846351560e-09;
		asali_->thermo_[260].low[4] = -3.2032289690e-13;
		asali_->thermo_[260].low[5] = 2.8757960938e+04;
		asali_->thermo_[260].low[6] = 1.3639843941e+01;
		
		asali_->thermo_[261].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[261].name,"H2NO");

		asali_->thermo_[261].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[261].high[0] = 1.4340581894e+00;
		asali_->thermo_[261].high[1] = 9.0133389458e-03;
		asali_->thermo_[261].high[2] = -3.3882831758e-06;
		asali_->thermo_[261].high[3] = 4.2865586081e-10;
		asali_->thermo_[261].high[4] = -2.3693607941e-15;
		asali_->thermo_[261].high[5] = 7.2734165039e+03;
		asali_->thermo_[261].high[6] = 1.7934186935e+01;

		asali_->thermo_[261].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[261].low[0] = 2.7893588543e+00;
		asali_->thermo_[261].low[1] = 4.4956696220e-03;
		asali_->thermo_[261].low[2] = 2.2588030788e-06;
		asali_->thermo_[261].low[3] = -2.7086144438e-09;
		asali_->thermo_[261].low[4] = 6.5122858278e-13;
		asali_->thermo_[261].low[5] = 6.9481445312e+03;
		asali_->thermo_[261].low[6] = 1.1148543358e+01;
		
		asali_->thermo_[262].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[262].name,"HCN");

		asali_->thermo_[262].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[262].high[0] = 3.4815208912e+00;
		asali_->thermo_[262].high[1] = 3.8174840156e-03;
		asali_->thermo_[262].high[2] = -1.5364292949e-06;
		asali_->thermo_[262].high[3] = 3.0229113657e-10;
		asali_->thermo_[262].high[4] = -2.3586147412e-14;
		asali_->thermo_[262].high[5] = 1.5042783203e+04;
		asali_->thermo_[262].high[6] = 3.3070230484e+00;

		asali_->thermo_[262].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[262].low[0] = 2.5313966274e+00;
		asali_->thermo_[262].low[1] = 8.2886572927e-03;
		asali_->thermo_[262].low[2] = -9.4267352324e-06;
		asali_->thermo_[262].low[3] = 6.4907665909e-09;
		asali_->thermo_[262].low[4] = -1.8437259098e-12;
		asali_->thermo_[262].low[5] = 1.5204304688e+04;
		asali_->thermo_[262].low[6] = 7.7364106178e+00;
		
		asali_->thermo_[263].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[263].name,"HCNO");

		asali_->thermo_[263].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[263].high[0] = 7.1242399216e+00;
		asali_->thermo_[263].high[1] = 1.6185337445e-03;
		asali_->thermo_[263].high[2] = 2.3133944183e-07;
		asali_->thermo_[263].high[3] = -2.5321192365e-10;
		asali_->thermo_[263].high[4] = 3.6345380779e-14;
		asali_->thermo_[263].high[5] = 1.6756792969e+04;
		asali_->thermo_[263].high[6] = -1.4888686180e+01;

		asali_->thermo_[263].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[263].low[0] = 2.2095401287e+00;
		asali_->thermo_[263].low[1] = 1.6180606559e-02;
		asali_->thermo_[263].low[2] = -1.5948740838e-05;
		asali_->thermo_[263].low[3] = 7.7369515239e-09;
		asali_->thermo_[263].low[4] = -1.4433145434e-12;
		asali_->thermo_[263].low[5] = 1.8083761719e+04;
		asali_->thermo_[263].low[6] = 1.0296821594e+01;
		
		asali_->thermo_[264].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[264].name,"HOCN");

		asali_->thermo_[264].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[264].high[0] = 6.9228677750e+00;
		asali_->thermo_[264].high[1] = 1.7708368250e-04;
		asali_->thermo_[264].high[2] = 1.0641783774e-06;
		asali_->thermo_[264].high[3] = -4.5581943775e-10;
		asali_->thermo_[264].high[4] = 5.4356397991e-14;
		asali_->thermo_[264].high[5] = -3.7737563477e+03;
		asali_->thermo_[264].high[6] = -1.0854404449e+01;

		asali_->thermo_[264].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[264].low[0] = 3.0578877926e+00;
		asali_->thermo_[264].low[1] = 8.9611280710e-03;
		asali_->thermo_[264].low[2] = -6.4222235778e-06;
		asali_->thermo_[264].low[3] = 2.3799389126e-09;
		asali_->thermo_[264].low[4] = -3.4845016412e-13;
		asali_->thermo_[264].low[5] = -2.4132834473e+03;
		asali_->thermo_[264].low[6] = 9.9768152237e+00;
		
		asali_->thermo_[265].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[265].name,"HNCO");

		asali_->thermo_[265].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[265].high[0] = 7.2950243950e+00;
		asali_->thermo_[265].high[1] = 4.8803284881e-04;
		asali_->thermo_[265].high[2] = 8.7456834308e-07;
		asali_->thermo_[265].high[3] = -4.0910569377e-10;
		asali_->thermo_[265].high[4] = 5.0195934784e-14;
		asali_->thermo_[265].high[5] = -1.5272229492e+04;
		asali_->thermo_[265].high[6] = -1.4169689178e+01;

		asali_->thermo_[265].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[265].low[0] = 2.9912796021e+00;
		asali_->thermo_[265].low[1] = 1.0858502239e-02;
		asali_->thermo_[265].low[2] = -8.4963385234e-06;
		asali_->thermo_[265].low[3] = 3.3543106071e-09;
		asali_->thermo_[265].low[4] = -5.1658362917e-13;
		asali_->thermo_[265].low[5] = -1.3843386719e+04;
		asali_->thermo_[265].low[6] = 8.7746067047e+00;
		
		asali_->thermo_[266].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[266].name,"HNNO");

		asali_->thermo_[266].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[266].high[0] = 4.8850030899e+00;
		asali_->thermo_[266].high[1] = 5.6093689054e-03;
		asali_->thermo_[266].high[2] = -2.6071782031e-06;
		asali_->thermo_[266].high[3] = 5.9383903350e-10;
		asali_->thermo_[266].high[4] = -5.4149511887e-14;
		asali_->thermo_[266].high[5] = 2.5892673828e+04;
		asali_->thermo_[266].high[6] = 6.0198003054e-01;

		asali_->thermo_[266].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[266].low[0] = 2.2934482098e+00;
		asali_->thermo_[266].low[1] = 1.3231589459e-02;
		asali_->thermo_[266].low[2] = -1.1014039046e-05;
		asali_->thermo_[266].low[3] = 4.7148489557e-09;
		asali_->thermo_[266].low[4] = -8.1168811906e-13;
		asali_->thermo_[266].low[5] = 2.6597576172e+04;
		asali_->thermo_[266].low[6] = 1.3901597023e+01;
		
		asali_->thermo_[267].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[267].name,"HNO");

		asali_->thermo_[267].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[267].high[0] = 2.7267365456e+00;
		asali_->thermo_[267].high[1] = 5.0677047111e-03;
		asali_->thermo_[267].high[2] = -2.6112275009e-06;
		asali_->thermo_[267].high[3] = 6.3849353582e-10;
		asali_->thermo_[267].high[4] = -6.0158102729e-14;
		asali_->thermo_[267].high[5] = 1.0976940430e+04;
		asali_->thermo_[267].high[6] = 9.6391286850e+00;

		asali_->thermo_[267].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[267].low[0] = 3.4020476341e+00;
		asali_->thermo_[267].low[1] = 2.0663233008e-03;
		asali_->thermo_[267].low[2] = 2.3910749860e-06;
		asali_->thermo_[267].low[3] = -3.0669158324e-09;
		asali_->thermo_[267].low[4] = 9.6912224339e-13;
		asali_->thermo_[267].low[5] = 1.0855384766e+04;
		asali_->thermo_[267].low[6] = 6.4522948265e+00;
		
		asali_->thermo_[268].name = (char*) malloc(1 * sizeof(char));
		strcpy(asali_->thermo_[268].name,"N");

		asali_->thermo_[268].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[268].high[0] = 2.4358367920e+00;
		asali_->thermo_[268].high[1] = 1.2774336210e-04;
		asali_->thermo_[268].high[2] = -8.5813233852e-08;
		asali_->thermo_[268].high[3] = 2.1326813579e-11;
		asali_->thermo_[268].high[4] = -1.2343351625e-15;
		asali_->thermo_[268].high[5] = 5.6123613281e+04;
		asali_->thermo_[268].high[6] = 4.5325908661e+00;

		asali_->thermo_[268].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[268].low[0] = 2.5051555634e+00;
		asali_->thermo_[268].low[1] = -2.6298233934e-05;
		asali_->thermo_[268].low[2] = 4.2554766821e-08;
		asali_->thermo_[268].low[3] = -2.6216891505e-11;
		asali_->thermo_[268].low[4] = 5.3689572997e-15;
		asali_->thermo_[268].low[5] = 5.6098660156e+04;
		asali_->thermo_[268].low[6] = 4.1574234962e+00;
		
		asali_->thermo_[269].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[269].name,"N2H2");

		asali_->thermo_[269].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[269].high[0] = 1.9487257004e+00;
		asali_->thermo_[269].high[1] = 9.0220654383e-03;
		asali_->thermo_[269].high[2] = -4.4816792979e-06;
		asali_->thermo_[269].high[3] = 1.0715962562e-09;
		asali_->thermo_[269].high[4] = -9.9638728529e-14;
		asali_->thermo_[269].high[5] = 2.4685017578e+04;
		asali_->thermo_[269].high[6] = 1.2707455635e+01;

		asali_->thermo_[269].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[269].low[0] = 2.4474577904e+00;
		asali_->thermo_[269].low[1] = 6.8769813515e-03;
		asali_->thermo_[269].low[2] = -1.0218657280e-06;
		asali_->thermo_[269].low[3] = -1.4085567157e-09;
		asali_->thermo_[269].low[4] = 5.6706906965e-13;
		asali_->thermo_[269].low[5] = 2.4592253906e+04;
		asali_->thermo_[269].low[6] = 1.0337554932e+01;
		
		asali_->thermo_[270].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[270].name,"N2H3");

		asali_->thermo_[270].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[270].high[0] = 5.0696177483e+00;
		asali_->thermo_[270].high[1] = 6.1806184240e-03;
		asali_->thermo_[270].high[2] = -1.8790901777e-06;
		asali_->thermo_[270].high[3] = 2.3327365040e-10;
		asali_->thermo_[270].high[4] = -8.0311005377e-15;
		asali_->thermo_[270].high[5] = 1.6347773438e+04;
		asali_->thermo_[270].high[6] = -4.0021848679e+00;

		asali_->thermo_[270].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[270].low[0] = 1.7141524553e+00;
		asali_->thermo_[270].low[1] = 1.4517178759e-02;
		asali_->thermo_[270].low[2] = -9.6460717032e-06;
		asali_->thermo_[270].low[3] = 3.4494149759e-09;
		asali_->thermo_[270].low[4] = -5.0743193284e-13;
		asali_->thermo_[270].low[5] = 1.7428232422e+04;
		asali_->thermo_[270].low[6] = 1.3783984184e+01;
		
		asali_->thermo_[271].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[271].name,"N2H4");

		asali_->thermo_[271].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[271].high[0] = 4.9191436768e+00;
		asali_->thermo_[271].high[1] = 9.7118793055e-03;
		asali_->thermo_[271].high[2] = -3.6292535697e-06;
		asali_->thermo_[271].high[3] = 6.3653093907e-10;
		asali_->thermo_[271].high[4] = -4.2850895358e-14;
		asali_->thermo_[271].high[5] = 9.3630458984e+03;
		asali_->thermo_[271].high[6] = -2.6439564228e+00;

		asali_->thermo_[271].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[271].low[0] = 3.6042565107e-01;
		asali_->thermo_[271].low[1] = 2.5431597605e-02;
		asali_->thermo_[271].low[2] = -2.3956474251e-05;
		asali_->thermo_[271].low[3] = 1.2318841947e-08;
		asali_->thermo_[271].low[4] = -2.5605904116e-12;
		asali_->thermo_[271].low[5] = 1.0420668945e+04;
		asali_->thermo_[271].low[6] = 2.0025827408e+01;
		
		asali_->thermo_[272].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[272].name,"N2O");

		asali_->thermo_[272].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[272].high[0] = 5.5212912560e+00;
		asali_->thermo_[272].high[1] = 1.4664595947e-03;
		asali_->thermo_[272].high[2] = -3.0469408330e-07;
		asali_->thermo_[272].high[3] = -1.8710685779e-11;
		asali_->thermo_[272].high[4] = 8.5038906120e-15;
		asali_->thermo_[272].high[5] = 7.8131225586e+03;
		asali_->thermo_[272].high[6] = -6.1745166779e+00;

		asali_->thermo_[272].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[272].low[0] = 2.6852197647e+00;
		asali_->thermo_[272].low[1] = 8.3417855203e-03;
		asali_->thermo_[272].low[2] = -6.5549897954e-06;
		asali_->thermo_[272].low[3] = 2.5066613230e-09;
		asali_->thermo_[272].low[4] = -3.7412824574e-13;
		asali_->thermo_[272].low[5] = 8.7490263672e+03;
		asali_->thermo_[272].low[6] = 8.9281244278e+00;
		
		asali_->thermo_[273].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[273].name,"NCO");

		asali_->thermo_[273].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[273].high[0] = 5.8061285019e+00;
		asali_->thermo_[273].high[1] = 1.2945740018e-03;
		asali_->thermo_[273].high[2] = -2.9638715660e-07;
		asali_->thermo_[273].high[3] = -4.4566906589e-12;
		asali_->thermo_[273].high[4] = 6.0080652577e-15;
		asali_->thermo_[273].high[5] = 1.7005371094e+04;
		asali_->thermo_[273].high[6] = -6.3380017281e+00;

		asali_->thermo_[273].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[273].low[0] = 2.8796958923e+00;
		asali_->thermo_[273].low[1] = 8.1802979112e-03;
		asali_->thermo_[273].low[2] = -6.3720258368e-06;
		asali_->thermo_[273].low[3] = 2.3781467906e-09;
		asali_->thermo_[273].low[4] = -3.4437481079e-13;
		asali_->thermo_[273].low[5] = 1.8000357422e+04;
		asali_->thermo_[273].low[6] = 9.3331928253e+00;
		
		asali_->thermo_[274].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->thermo_[274].name,"NH");

		asali_->thermo_[274].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[274].high[0] = 2.5369145870e+00;
		asali_->thermo_[274].high[1] = 1.7453270266e-03;
		asali_->thermo_[274].high[2] = -6.6681815269e-07;
		asali_->thermo_[274].high[3] = 1.3416065481e-10;
		asali_->thermo_[274].high[4] = -1.0419003307e-14;
		asali_->thermo_[274].high[5] = 4.2182187500e+04;
		asali_->thermo_[274].high[6] = 7.1273279190e+00;

		asali_->thermo_[274].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[274].low[0] = 3.7500767708e+00;
		asali_->thermo_[274].low[1] = -1.3854141580e-03;
		asali_->thermo_[274].low[2] = 2.3629315820e-06;
		asali_->thermo_[274].low[3] = -1.1689574864e-09;
		asali_->thermo_[274].low[4] = 1.9976133649e-13;
		asali_->thermo_[274].low[5] = 4.1806109375e+04;
		asali_->thermo_[274].low[6] = 7.4284720421e-01;
		
		asali_->thermo_[275].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[275].name,"NH2");

		asali_->thermo_[275].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[275].high[0] = 2.6768777370e+00;
		asali_->thermo_[275].high[1] = 3.4848407377e-03;
		asali_->thermo_[275].high[2] = -1.2857082083e-06;
		asali_->thermo_[275].high[3] = 2.7209162701e-10;
		asali_->thermo_[275].high[4] = -2.3603428579e-14;
		asali_->thermo_[275].high[5] = 2.2030337891e+04;
		asali_->thermo_[275].high[6] = 7.3473014832e+00;

		asali_->thermo_[275].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[275].low[0] = 4.1831307411e+00;
		asali_->thermo_[275].low[1] = -1.8946341006e-03;
		asali_->thermo_[275].low[2] = 5.9189455897e-06;
		asali_->thermo_[275].low[3] = -4.0163929960e-09;
		asali_->thermo_[275].low[4] = 9.3364758199e-13;
		asali_->thermo_[275].low[5] = 2.1692935547e+04;
		asali_->thermo_[275].low[6] = -9.0199872851e-02;
		
		asali_->thermo_[276].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[276].name,"NH3");

		asali_->thermo_[276].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[276].high[0] = 2.2111797333e+00;
		asali_->thermo_[276].high[1] = 6.5218247473e-03;
		asali_->thermo_[276].high[2] = -2.3093152777e-06;
		asali_->thermo_[276].high[3] = 3.9890712955e-10;
		asali_->thermo_[276].high[4] = -2.8038564241e-14;
		asali_->thermo_[276].high[5] = -6.3900961914e+03;
		asali_->thermo_[276].high[6] = 8.8690557480e+00;

		asali_->thermo_[276].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[276].low[0] = 3.2168917656e+00;
		asali_->thermo_[276].low[1] = 3.1971565913e-03;
		asali_->thermo_[276].low[2] = 1.8121737639e-06;
		asali_->thermo_[276].low[3] = -1.8718857575e-09;
		asali_->thermo_[276].low[4] = 4.4113351210e-13;
		asali_->thermo_[276].low[5] = -6.6334785156e+03;
		asali_->thermo_[276].low[6] = 3.8253676891e+00;
		
		asali_->thermo_[277].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[277].name,"NNH");

		asali_->thermo_[277].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[277].high[0] = 2.6754012108e+00;
		asali_->thermo_[277].high[1] = 5.3566866554e-03;
		asali_->thermo_[277].high[2] = -2.9499044558e-06;
		asali_->thermo_[277].high[3] = 7.7854123148e-10;
		asali_->thermo_[277].high[4] = -7.9141385014e-14;
		asali_->thermo_[277].high[5] = 2.8474605469e+04;
		asali_->thermo_[277].high[6] = 1.0302870750e+01;

		asali_->thermo_[277].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[277].low[0] = 3.9682359695e+00;
		asali_->thermo_[277].low[1] = -1.8257279880e-03;
		asali_->thermo_[277].low[2] = 1.2013459127e-05;
		asali_->thermo_[277].low[3] = -1.3076425276e-08;
		asali_->thermo_[277].low[4] = 4.7316109364e-12;
		asali_->thermo_[277].low[5] = 2.8288437500e+04;
		asali_->thermo_[277].low[6] = 4.4903922081e+00;
		
		asali_->thermo_[278].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->thermo_[278].name,"NO");

		asali_->thermo_[278].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[278].high[0] = 2.6977500916e+00;
		asali_->thermo_[278].high[1] = 2.3988713510e-03;
		asali_->thermo_[278].high[2] = -1.3164469692e-06;
		asali_->thermo_[278].high[3] = 3.3823580048e-10;
		asali_->thermo_[278].high[4] = -3.2939488404e-14;
		asali_->thermo_[278].high[5] = 9.9985439453e+03;
		asali_->thermo_[278].high[6] = 9.4023084641e+00;

		asali_->thermo_[278].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[278].low[0] = 3.9129018784e+00;
		asali_->thermo_[278].low[1] = -2.6120636612e-03;
		asali_->thermo_[278].low[2] = 6.4324217419e-06;
		asali_->thermo_[278].low[3] = -4.9874468999e-09;
		asali_->thermo_[278].low[4] = 1.3396591779e-12;
		asali_->thermo_[278].low[5] = 9.7628037109e+03;
		asali_->thermo_[278].low[6] = 3.5769159794e+00;
		
		asali_->thermo_[279].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[279].name,"NO2");

		asali_->thermo_[279].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[279].high[0] = 5.2567367554e+00;
		asali_->thermo_[279].high[1] = 1.6434331192e-03;
		asali_->thermo_[279].high[2] = -6.2419792357e-07;
		asali_->thermo_[279].high[3] = 1.0706514841e-10;
		asali_->thermo_[279].high[4] = -6.8858476186e-15;
		asali_->thermo_[279].high[5] = 1.9536356201e+03;
		asali_->thermo_[279].high[6] = -2.3582756519e+00;

		asali_->thermo_[279].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[279].low[0] = 2.6140959263e+00;
		asali_->thermo_[279].low[1] = 7.5159682892e-03;
		asali_->thermo_[279].low[2] = -5.5179775700e-06;
		asali_->thermo_[279].low[3] = 1.9195760537e-09;
		asali_->thermo_[279].low[4] = -2.5862347203e-13;
		asali_->thermo_[279].low[5] = 2.9049863281e+03;
		asali_->thermo_[279].low[6] = 1.1944248199e+01;
		
		asali_->thermo_[280].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[280].name,"HONO");

		asali_->thermo_[280].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[280].high[0] = 5.8874211311e+00;
		asali_->thermo_[280].high[1] = 3.4932910930e-03;
		asali_->thermo_[280].high[2] = -1.1773080359e-06;
		asali_->thermo_[280].high[3] = 1.6556937765e-10;
		asali_->thermo_[280].high[4] = -6.8771519783e-15;
		asali_->thermo_[280].high[5] = -1.1438630859e+04;
		asali_->thermo_[280].high[6] = -5.2386655807e+00;

		asali_->thermo_[280].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[280].low[0] = 2.3788318634e+00;
		asali_->thermo_[280].low[1] = 1.3376641087e-02;
		asali_->thermo_[280].low[2] = -1.1617466953e-05;
		asali_->thermo_[280].low[3] = 5.0670521112e-09;
		asali_->thermo_[280].low[4] = -8.6981425751e-13;
		asali_->thermo_[280].low[5] = -1.0442191406e+04;
		asali_->thermo_[280].low[6] = 1.2918560982e+01;
		
		asali_->thermo_[281].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[281].name,"HNO2");

		asali_->thermo_[281].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[281].high[0] = 3.3035941124e+00;
		asali_->thermo_[281].high[1] = 7.7400663868e-03;
		asali_->thermo_[281].high[2] = -3.9147435018e-06;
		asali_->thermo_[281].high[3] = 9.4711216647e-10;
		asali_->thermo_[281].high[4] = -8.8849453240e-14;
		asali_->thermo_[281].high[5] = -8.6570253906e+03;
		asali_->thermo_[281].high[6] = 7.1007251740e+00;

		asali_->thermo_[281].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[281].low[0] = 1.6889071465e+00;
		asali_->thermo_[281].low[1] = 1.1328259483e-02;
		asali_->thermo_[281].low[2] = -6.9049042395e-06;
		asali_->thermo_[281].low[3] = 2.0545791735e-09;
		asali_->thermo_[281].low[4] = -2.4266431421e-13;
		asali_->thermo_[281].low[5] = -8.0757382812e+03;
		asali_->thermo_[281].low[6] = 1.5839747429e+01;
		
		asali_->thermo_[282].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[282].name,"NO3");

		asali_->thermo_[282].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[282].high[0] = 7.6639194489e+00;
		asali_->thermo_[282].high[1] = 2.2816597484e-03;
		asali_->thermo_[282].high[2] = -8.1624153836e-07;
		asali_->thermo_[282].high[3] = 1.1136786632e-10;
		asali_->thermo_[282].high[4] = -3.3842970591e-15;
		asali_->thermo_[282].high[5] = 5.6297500000e+03;
		asali_->thermo_[282].high[6] = -1.5189944267e+01;

		asali_->thermo_[282].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[282].low[0] = 4.0654194355e-01;
		asali_->thermo_[282].low[1] = 2.4108357728e-02;
		asali_->thermo_[282].low[2] = -2.5432818802e-05;
		asali_->thermo_[282].low[3] = 1.2450504627e-08;
		asali_->thermo_[282].low[4] = -2.3227708819e-12;
		asali_->thermo_[282].low[5] = 7.5602124023e+03;
		asali_->thermo_[282].low[6] = 2.1892356873e+01;
		
		asali_->thermo_[283].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[283].name,"HONO2");

		asali_->thermo_[283].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[283].high[0] = 5.2094907761e+00;
		asali_->thermo_[283].high[1] = 9.9712340161e-03;
		asali_->thermo_[283].high[2] = -5.5072541727e-06;
		asali_->thermo_[283].high[3] = 1.3925069986e-09;
		asali_->thermo_[283].high[4] = -1.3315746888e-13;
		asali_->thermo_[283].high[5] = -1.7446429688e+04;
		asali_->thermo_[283].high[6] = -1.3543078899e+00;

		asali_->thermo_[283].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[283].low[0] = 8.8570606709e-01;
		asali_->thermo_[283].low[1] = 2.3173630238e-02;
		asali_->thermo_[283].low[2] = -2.0624502213e-05;
		asali_->thermo_[283].low[3] = 9.0857632529e-09;
		asali_->thermo_[283].low[4] = -1.6013361427e-12;
		asali_->thermo_[283].low[5] = -1.6313596680e+04;
		asali_->thermo_[283].low[6] = 2.0672994614e+01;
		
		asali_->thermo_[284].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[284].name,"CH3CN");

		asali_->thermo_[284].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[284].high[0] = 2.0266091824e+00;
		asali_->thermo_[284].high[1] = 1.6440253705e-02;
		asali_->thermo_[284].high[2] = -8.5429091996e-06;
		asali_->thermo_[284].high[3] = 2.1374031434e-09;
		asali_->thermo_[284].high[4] = -2.0858159221e-13;
		asali_->thermo_[284].high[5] = 8.6182304688e+03;
		asali_->thermo_[284].high[6] = 1.3103064537e+01;

		asali_->thermo_[284].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[284].low[0] = 2.3662161827e+00;
		asali_->thermo_[284].low[1] = 1.4499643818e-02;
		asali_->thermo_[284].low[2] = -4.3844579523e-06;
		asali_->thermo_[284].low[3] = -1.8230263965e-09;
		asali_->thermo_[284].low[4] = 1.2058575709e-12;
		asali_->thermo_[284].low[5] = 8.5706855469e+03;
		asali_->thermo_[284].low[6] = 1.1585786819e+01;
		
		asali_->thermo_[285].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[285].name,"CH3NO2");

		asali_->thermo_[285].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[285].high[0] = 5.9477138519e+00;
		asali_->thermo_[285].high[1] = 1.2231907807e-02;
		asali_->thermo_[285].high[2] = -4.9871637202e-06;
		asali_->thermo_[285].high[3] = 9.7317753855e-10;
		asali_->thermo_[285].high[4] = -7.5487352643e-14;
		asali_->thermo_[285].high[5] = -1.1469124023e+04;
		asali_->thermo_[285].high[6] = -2.7341504097e+00;

		asali_->thermo_[285].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[285].low[0] = -2.0595227182e-01;
		asali_->thermo_[285].low[1] = 2.7426145971e-02;
		asali_->thermo_[285].low[2] = -1.9055902158e-05;
		asali_->thermo_[285].low[3] = 6.7627818900e-09;
		asali_->thermo_[285].low[4] = -9.6894475950e-13;
		asali_->thermo_[285].low[5] = -9.4753359375e+03;
		asali_->thermo_[285].low[6] = 2.9922420502e+01;
		
		asali_->thermo_[286].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[286].name,"CH3ONO");

		asali_->thermo_[286].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[286].high[0] = 8.5803451538e+00;
		asali_->thermo_[286].high[1] = 8.9095411822e-03;
		asali_->thermo_[286].high[2] = -3.3592209547e-06;
		asali_->thermo_[286].high[3] = 6.1858812517e-10;
		asali_->thermo_[286].high[4] = -4.6809696961e-14;
		asali_->thermo_[286].high[5] = -1.1556961914e+04;
		asali_->thermo_[286].high[6] = -1.9719406128e+01;

		asali_->thermo_[286].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[286].low[0] = 1.9924957752e+00;
		asali_->thermo_[286].low[1] = 2.3549206555e-02;
		asali_->thermo_[286].low[2] = -1.5558942323e-05;
		asali_->thermo_[286].low[3] = 5.1370032672e-09;
		asali_->thermo_[286].low[4] = -6.7436735449e-13;
		asali_->thermo_[286].low[5] = -9.1853369141e+03;
		asali_->thermo_[286].low[6] = 1.5935409546e+01;
		
		asali_->thermo_[287].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[287].name,"CH3NO");

		asali_->thermo_[287].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[287].high[0] = 1.7382823229e+00;
		asali_->thermo_[287].high[1] = 1.6547949985e-02;
		asali_->thermo_[287].high[2] = -8.6927166194e-06;
		asali_->thermo_[287].high[3] = 2.1700274910e-09;
		asali_->thermo_[287].high[4] = -2.0846344128e-13;
		asali_->thermo_[287].high[5] = 8.3647353516e+03;
		asali_->thermo_[287].high[6] = 1.7496601105e+01;

		asali_->thermo_[287].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[287].low[0] = 2.2345168591e+00;
		asali_->thermo_[287].low[1] = 1.4239882119e-02;
		asali_->thermo_[287].low[2] = -4.6670174925e-06;
		asali_->thermo_[287].low[3] = -9.5066954309e-10;
		asali_->thermo_[287].low[4] = 6.9871598741e-13;
		asali_->thermo_[287].low[5] = 8.2793828125e+03;
		asali_->thermo_[287].low[6] = 1.5177399635e+01;
		
		asali_->thermo_[288].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[288].name,"CH3ONO2");

		asali_->thermo_[288].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[288].high[0] = 1.0745779991e+01;
		asali_->thermo_[288].high[1] = 1.0336202569e-02;
		asali_->thermo_[288].high[2] = -4.3953978093e-06;
		asali_->thermo_[288].high[3] = 8.9595980635e-10;
		asali_->thermo_[288].high[4] = -7.2686201134e-14;
		asali_->thermo_[288].high[5] = -1.8103109375e+04;
		asali_->thermo_[288].high[6] = -3.0887500763e+01;

		asali_->thermo_[288].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[288].low[0] = 1.3515539169e+00;
		asali_->thermo_[288].low[1] = 3.1212259084e-02;
		asali_->thermo_[288].low[2] = -2.1792113330e-05;
		asali_->thermo_[288].low[3] = 7.3391874800e-09;
		asali_->thermo_[288].low[4] = -9.6757888160e-13;
		asali_->thermo_[288].low[5] = -1.4721187500e+04;
		asali_->thermo_[288].low[6] = 1.9956008911e+01;
		
		asali_->thermo_[289].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[289].name,"CH2CN");

		asali_->thermo_[289].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[289].high[0] = 4.4188098907e+00;
		asali_->thermo_[289].high[1] = 9.8343035206e-03;
		asali_->thermo_[289].high[2] = -4.9899181249e-06;
		asali_->thermo_[289].high[3] = 1.2231987645e-09;
		asali_->thermo_[289].high[4] = -1.1739655743e-13;
		asali_->thermo_[289].high[5] = 2.9239035156e+04;
		asali_->thermo_[289].high[6] = 2.0276925564e+00;

		asali_->thermo_[289].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[289].low[0] = 2.7116298676e+00;
		asali_->thermo_[289].low[1] = 1.6802385449e-02;
		asali_->thermo_[289].low[2] = -1.5655348761e-05;
		asali_->thermo_[289].low[3] = 8.4785938270e-09;
		asali_->thermo_[289].low[4] = -1.9682625755e-12;
		asali_->thermo_[289].low[5] = 2.9573640625e+04;
		asali_->thermo_[289].low[6] = 1.0229359627e+01;
		
		asali_->thermo_[290].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[290].name,"BIN1A");

		asali_->thermo_[290].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[290].high[0] = -3.2417359352e+00;
		asali_->thermo_[290].high[1] = 1.5822289884e-01;
		asali_->thermo_[290].high[2] = -9.4618349976e-05;
		asali_->thermo_[290].high[3] = 2.8184309997e-08;
		asali_->thermo_[290].high[4] = -3.5613101010e-12;
		asali_->thermo_[290].high[5] = 2.1786990234e+04;
		asali_->thermo_[290].high[6] = 3.0082529068e+01;

		asali_->thermo_[290].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[290].low[0] = -3.2417359352e+00;
		asali_->thermo_[290].low[1] = 1.5822289884e-01;
		asali_->thermo_[290].low[2] = -9.4618349976e-05;
		asali_->thermo_[290].low[3] = 2.8184309997e-08;
		asali_->thermo_[290].low[4] = -3.5613101010e-12;
		asali_->thermo_[290].low[5] = 2.1786990234e+04;
		asali_->thermo_[290].low[6] = 3.0082529068e+01;
		
		asali_->thermo_[291].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[291].name,"BIN1B");

		asali_->thermo_[291].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[291].high[0] = -5.7025671005e+00;
		asali_->thermo_[291].high[1] = 1.4343230426e-01;
		asali_->thermo_[291].high[2] = -8.8072469225e-05;
		asali_->thermo_[291].high[3] = 2.7679920578e-08;
		asali_->thermo_[291].high[4] = -3.5228989864e-12;
		asali_->thermo_[291].high[5] = 2.7780890625e+04;
		asali_->thermo_[291].high[6] = 4.3448120117e+01;

		asali_->thermo_[291].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[291].low[0] = -5.7025671005e+00;
		asali_->thermo_[291].low[1] = 1.4343230426e-01;
		asali_->thermo_[291].low[2] = -8.8072469225e-05;
		asali_->thermo_[291].low[3] = 2.7679920578e-08;
		asali_->thermo_[291].low[4] = -3.5228989864e-12;
		asali_->thermo_[291].low[5] = 2.7780890625e+04;
		asali_->thermo_[291].low[6] = 4.3448120117e+01;
		
		asali_->thermo_[292].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[292].name,"CYC6-QOOH-2");

		asali_->thermo_[292].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[292].high[0] = 1.9138414383e+01;
		asali_->thermo_[292].high[1] = 3.6487307400e-02;
		asali_->thermo_[292].high[2] = -1.6361296730e-05;
		asali_->thermo_[292].high[3] = 3.5326455095e-09;
		asali_->thermo_[292].high[4] = -3.0211168853e-13;
		asali_->thermo_[292].high[5] = -1.4329435547e+04;
		asali_->thermo_[292].high[6] = -7.8638366699e+01;

		asali_->thermo_[292].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[292].low[0] = -4.8701539040e+00;
		asali_->thermo_[292].low[1] = 8.9839681983e-02;
		asali_->thermo_[292].low[2] = -6.0821610532e-05;
		asali_->thermo_[292].low[3] = 1.9999427892e-08;
		asali_->thermo_[292].low[4] = -2.5891647767e-12;
		asali_->thermo_[292].low[5] = -5.6863505859e+03;
		asali_->thermo_[292].low[6] = 5.1301017761e+01;
		
		asali_->thermo_[293].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[293].name,"CYC6-QOOH-3");

		asali_->thermo_[293].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[293].high[0] = 2.0930072784e+01;
		asali_->thermo_[293].high[1] = 3.2871980220e-02;
		asali_->thermo_[293].high[2] = -1.4016078239e-05;
		asali_->thermo_[293].high[3] = 2.8919364681e-09;
		asali_->thermo_[293].high[4] = -2.3853984651e-13;
		asali_->thermo_[293].high[5] = -1.5299454102e+04;
		asali_->thermo_[293].high[6] = -8.8934967041e+01;

		asali_->thermo_[293].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[293].low[0] = -7.0491423607e+00;
		asali_->thermo_[293].low[1] = 9.5048010349e-02;
		asali_->thermo_[293].low[2] = -6.5829437517e-05;
		asali_->thermo_[293].low[3] = 2.2082069506e-08;
		asali_->thermo_[293].low[4] = -2.9038362426e-12;
		asali_->thermo_[293].low[5] = -5.2269370117e+03;
		asali_->thermo_[293].low[6] = 6.2494380951e+01;
		
		asali_->thermo_[294].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[294].name,"CYC6-QOOH-4");

		asali_->thermo_[294].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[294].high[0] = 2.0930072784e+01;
		asali_->thermo_[294].high[1] = 3.2871980220e-02;
		asali_->thermo_[294].high[2] = -1.4016078239e-05;
		asali_->thermo_[294].high[3] = 2.8919364681e-09;
		asali_->thermo_[294].high[4] = -2.3853984651e-13;
		asali_->thermo_[294].high[5] = -1.5299454102e+04;
		asali_->thermo_[294].high[6] = -8.8934967041e+01;

		asali_->thermo_[294].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[294].low[0] = -7.0491423607e+00;
		asali_->thermo_[294].low[1] = 9.5048010349e-02;
		asali_->thermo_[294].low[2] = -6.5829437517e-05;
		asali_->thermo_[294].low[3] = 2.2082069506e-08;
		asali_->thermo_[294].low[4] = -2.9038362426e-12;
		asali_->thermo_[294].low[5] = -5.2269370117e+03;
		asali_->thermo_[294].low[6] = 6.2494380951e+01;
		
		asali_->thermo_[295].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->thermo_[295].name,"CYC6-OOQOOH-2");

		asali_->thermo_[295].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[295].high[0] = 2.9374221802e+01;
		asali_->thermo_[295].high[1] = 2.6785880327e-02;
		asali_->thermo_[295].high[2] = -9.5634595709e-06;
		asali_->thermo_[295].high[3] = 1.5408567755e-09;
		asali_->thermo_[295].high[4] = -9.3128379086e-14;
		asali_->thermo_[295].high[5] = -3.5549906250e+04;
		asali_->thermo_[295].high[6] = -1.2975277710e+02;

		asali_->thermo_[295].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[295].low[0] = -4.9906196594e+00;
		asali_->thermo_[295].low[1] = 1.0444653779e-01;
		asali_->thermo_[295].low[2] = -7.5377574831e-05;
		asali_->thermo_[295].low[3] = 2.6329601610e-08;
		asali_->thermo_[295].low[4] = -3.5943635221e-12;
		asali_->thermo_[295].low[5] = -2.3384751953e+04;
		asali_->thermo_[295].low[6] = 5.5659332275e+01;
		
		asali_->thermo_[296].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->thermo_[296].name,"CYC6-OOQOOH-3");

		asali_->thermo_[296].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[296].high[0] = 2.9374221802e+01;
		asali_->thermo_[296].high[1] = 2.6785880327e-02;
		asali_->thermo_[296].high[2] = -9.5634595709e-06;
		asali_->thermo_[296].high[3] = 1.5408567755e-09;
		asali_->thermo_[296].high[4] = -9.3128379086e-14;
		asali_->thermo_[296].high[5] = -3.5549906250e+04;
		asali_->thermo_[296].high[6] = -1.2975277710e+02;

		asali_->thermo_[296].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[296].low[0] = -4.9906196594e+00;
		asali_->thermo_[296].low[1] = 1.0444653779e-01;
		asali_->thermo_[296].low[2] = -7.5377574831e-05;
		asali_->thermo_[296].low[3] = 2.6329601610e-08;
		asali_->thermo_[296].low[4] = -3.5943635221e-12;
		asali_->thermo_[296].low[5] = -2.3384751953e+04;
		asali_->thermo_[296].low[6] = 5.5659332275e+01;
		
		asali_->thermo_[297].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->thermo_[297].name,"CYC6-OOQOOH-4");

		asali_->thermo_[297].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[297].high[0] = 2.9374221802e+01;
		asali_->thermo_[297].high[1] = 2.6785880327e-02;
		asali_->thermo_[297].high[2] = -9.5634595709e-06;
		asali_->thermo_[297].high[3] = 1.5408567755e-09;
		asali_->thermo_[297].high[4] = -9.3128379086e-14;
		asali_->thermo_[297].high[5] = -3.5549906250e+04;
		asali_->thermo_[297].high[6] = -1.3044729614e+02;

		asali_->thermo_[297].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[297].low[0] = -4.9906196594e+00;
		asali_->thermo_[297].low[1] = 1.0444653779e-01;
		asali_->thermo_[297].low[2] = -7.5377574831e-05;
		asali_->thermo_[297].low[3] = 2.6329601610e-08;
		asali_->thermo_[297].low[4] = -3.5943635221e-12;
		asali_->thermo_[297].low[5] = -2.3384751953e+04;
		asali_->thermo_[297].low[6] = 5.4964817047e+01;
		
		asali_->thermo_[298].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->thermo_[298].name,"CYC6-OQOOH-2");

		asali_->thermo_[298].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[298].high[0] = 1.1765523911e+01;
		asali_->thermo_[298].high[1] = 3.6745142192e-02;
		asali_->thermo_[298].high[2] = -1.4271744476e-05;
		asali_->thermo_[298].high[3] = 2.7414044368e-09;
		asali_->thermo_[298].high[4] = -2.1313551239e-13;
		asali_->thermo_[298].high[5] = -3.5990339844e+04;
		asali_->thermo_[298].high[6] = -5.1081249237e+01;

		asali_->thermo_[298].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[298].low[0] = -1.0669644356e+01;
		asali_->thermo_[298].low[1] = 9.8211355507e-02;
		asali_->thermo_[298].low[2] = -7.7421966125e-05;
		asali_->thermo_[298].low[3] = 3.1577123139e-08;
		asali_->thermo_[298].low[4] = -5.1507582921e-12;
		asali_->thermo_[298].low[5] = -2.9439269531e+04;
		asali_->thermo_[298].low[6] = 6.5645751953e+01;
		
		asali_->thermo_[299].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->thermo_[299].name,"CYC6-OQOOH-3");

		asali_->thermo_[299].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[299].high[0] = 1.1602241516e+01;
		asali_->thermo_[299].high[1] = 3.5730365664e-02;
		asali_->thermo_[299].high[2] = -1.3441588635e-05;
		asali_->thermo_[299].high[3] = 2.5043744856e-09;
		asali_->thermo_[299].high[4] = -1.8951028626e-13;
		asali_->thermo_[299].high[5] = -3.6382156250e+04;
		asali_->thermo_[299].high[6] = -4.9158782959e+01;

		asali_->thermo_[299].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[299].low[0] = -8.0240211487e+00;
		asali_->thermo_[299].low[1] = 8.9500948787e-02;
		asali_->thermo_[299].low[2] = -6.8685338192e-05;
		asali_->thermo_[299].low[3] = 2.7729832652e-08;
		asali_->thermo_[299].low[4] = -4.5089379279e-12;
		asali_->thermo_[299].low[5] = -3.0651287109e+04;
		asali_->thermo_[299].low[6] = 5.2953887939e+01;
		
		asali_->thermo_[300].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->thermo_[300].name,"CYC6-OQOOH-4");

		asali_->thermo_[300].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[300].high[0] = 1.1602241516e+01;
		asali_->thermo_[300].high[1] = 3.5730365664e-02;
		asali_->thermo_[300].high[2] = -1.3441588635e-05;
		asali_->thermo_[300].high[3] = 2.5043744856e-09;
		asali_->thermo_[300].high[4] = -1.8951028626e-13;
		asali_->thermo_[300].high[5] = -3.6382156250e+04;
		asali_->thermo_[300].high[6] = -4.9853294373e+01;

		asali_->thermo_[300].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[300].low[0] = -8.0240211487e+00;
		asali_->thermo_[300].low[1] = 8.9500948787e-02;
		asali_->thermo_[300].low[2] = -6.8685338192e-05;
		asali_->thermo_[300].low[3] = 2.7729832652e-08;
		asali_->thermo_[300].low[4] = -4.5089379279e-12;
		asali_->thermo_[300].low[5] = -3.0651287109e+04;
		asali_->thermo_[300].low[6] = 5.2259372711e+01;
		
		asali_->thermo_[301].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->thermo_[301].name,"CYC6H10-O-12");

		asali_->thermo_[301].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[301].high[0] = 2.2932317734e+01;
		asali_->thermo_[301].high[1] = 2.2005654871e-02;
		asali_->thermo_[301].high[2] = -7.3524233812e-06;
		asali_->thermo_[301].high[3] = 1.0781641135e-09;
		asali_->thermo_[301].high[4] = -5.6463592347e-14;
		asali_->thermo_[301].high[5] = -2.7980619141e+04;
		asali_->thermo_[301].high[6] = -1.1052520752e+02;

		asali_->thermo_[301].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[301].low[0] = -1.0562925339e+01;
		asali_->thermo_[301].low[1] = 9.6439532936e-02;
		asali_->thermo_[301].low[2] = -6.9380650530e-05;
		asali_->thermo_[301].low[3] = 2.4051582059e-08;
		asali_->thermo_[301].low[4] = -3.2472160811e-12;
		asali_->thermo_[301].low[5] = -1.5922332031e+04;
		asali_->thermo_[301].low[6] = 7.0758041382e+01;
		
		asali_->thermo_[302].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->thermo_[302].name,"CYC6H10-O-13");

		asali_->thermo_[302].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[302].high[0] = 2.1802860260e+01;
		asali_->thermo_[302].high[1] = 2.4137742817e-02;
		asali_->thermo_[302].high[2] = -8.7311827883e-06;
		asali_->thermo_[302].high[3] = 1.4603560583e-09;
		asali_->thermo_[302].high[4] = -9.5186689477e-14;
		asali_->thermo_[302].high[5] = -2.8738746094e+04;
		asali_->thermo_[302].high[6] = -1.0621752167e+02;

		asali_->thermo_[302].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[302].low[0] = -1.2599009514e+01;
		asali_->thermo_[302].low[1] = 1.0058634728e-01;
		asali_->thermo_[302].low[2] = -7.2438349889e-05;
		asali_->thermo_[302].low[3] = 2.5055603814e-08;
		asali_->thermo_[302].low[4] = -3.3723043889e-12;
		asali_->thermo_[302].low[5] = -1.6354072266e+04;
		asali_->thermo_[302].low[6] = 7.9972572327e+01;
		
		asali_->thermo_[303].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->thermo_[303].name,"CYC6H10-O-14");

		asali_->thermo_[303].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[303].high[0] = 2.1407958984e+01;
		asali_->thermo_[303].high[1] = 2.5082545355e-02;
		asali_->thermo_[303].high[2] = -9.3803964774e-06;
		asali_->thermo_[303].high[3] = 1.6452542662e-09;
		asali_->thermo_[303].high[4] = -1.1424764130e-13;
		asali_->thermo_[303].high[5] = -3.8974183594e+04;
		asali_->thermo_[303].high[6] = -1.0572823334e+02;

		asali_->thermo_[303].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[303].low[0] = -1.4596052170e+01;
		asali_->thermo_[303].low[1] = 1.0509146005e-01;
		asali_->thermo_[303].low[2] = -7.6054493547e-05;
		asali_->thermo_[303].low[3] = 2.6339362691e-08;
		asali_->thermo_[303].low[4] = -3.5439849840e-12;
		asali_->thermo_[303].low[5] = -2.6012738281e+04;
		asali_->thermo_[303].low[6] = 8.9132987976e+01;
		
		asali_->thermo_[304].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[304].name,"C3H5OOH");

		asali_->thermo_[304].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[304].high[0] = 1.2137720108e+01;
		asali_->thermo_[304].high[1] = 1.6858547926e-02;
		asali_->thermo_[304].high[2] = -6.9427510425e-06;
		asali_->thermo_[304].high[3] = 1.3695889978e-09;
		asali_->thermo_[304].high[4] = -1.0742746075e-13;
		asali_->thermo_[304].high[5] = -1.2526590820e+04;
		asali_->thermo_[304].high[6] = -3.5719470978e+01;

		asali_->thermo_[304].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[304].low[0] = 2.2465109825e+00;
		asali_->thermo_[304].low[1] = 3.8839012384e-02;
		asali_->thermo_[304].low[2] = -2.5259803806e-05;
		asali_->thermo_[304].low[3] = 8.1536830621e-09;
		asali_->thermo_[304].low[4] = -1.0496627439e-12;
		asali_->thermo_[304].low[5] = -8.9657548828e+03;
		asali_->thermo_[304].low[6] = 1.7813814163e+01;
		
		asali_->thermo_[305].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->thermo_[305].name,"C5EN-OQOOH-35");

		asali_->thermo_[305].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[305].high[0] = 1.6983314514e+01;
		asali_->thermo_[305].high[1] = 2.7309503406e-02;
		asali_->thermo_[305].high[2] = -1.1922685189e-05;
		asali_->thermo_[305].high[3] = 2.4816693145e-09;
		asali_->thermo_[305].high[4] = -2.0342039685e-13;
		asali_->thermo_[305].high[5] = -3.5123453125e+04;
		asali_->thermo_[305].high[6] = -5.5804176331e+01;

		asali_->thermo_[305].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[305].low[0] = 1.4456132650e+00;
		asali_->thermo_[305].low[1] = 6.6645458341e-02;
		asali_->thermo_[305].low[2] = -4.9266946007e-05;
		asali_->thermo_[305].low[3] = 1.8238740296e-08;
		asali_->thermo_[305].low[4] = -2.6966278602e-12;
		asali_->thermo_[305].low[5] = -3.0213539062e+04;
		asali_->thermo_[305].low[6] = 2.6263580322e+01;
		
		asali_->thermo_[306].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[306].name,"C5H8O");

		asali_->thermo_[306].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[306].high[0] = 6.7080068588e+00;
		asali_->thermo_[306].high[1] = 3.6524377763e-02;
		asali_->thermo_[306].high[2] = -1.7776581444e-05;
		asali_->thermo_[306].high[3] = 4.1563916753e-09;
		asali_->thermo_[306].high[4] = -3.7916330774e-13;
		asali_->thermo_[306].high[5] = -5.5277177734e+03;
		asali_->thermo_[306].high[6] = -9.6791839600e+00;

		asali_->thermo_[306].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[306].low[0] = -5.1264014244e+00;
		asali_->thermo_[306].low[1] = 7.2116583586e-02;
		asali_->thermo_[306].low[2] = -5.7918168750e-05;
		asali_->thermo_[306].low[3] = 2.4277486688e-08;
		asali_->thermo_[306].low[4] = -4.1613240631e-12;
		asali_->thermo_[306].low[5] = -2.3797651367e+03;
		asali_->thermo_[306].low[6] = 5.0789920807e+01;
		
		asali_->thermo_[307].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[307].name,"NC5H9-3");

		asali_->thermo_[307].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[307].high[0] = 9.8828735352e+00;
		asali_->thermo_[307].high[1] = 2.8627535328e-02;
		asali_->thermo_[307].high[2] = -1.2366243027e-05;
		asali_->thermo_[307].high[3] = 2.5830850792e-09;
		asali_->thermo_[307].high[4] = -2.1452096013e-13;
		asali_->thermo_[307].high[5] = 7.1421162109e+03;
		asali_->thermo_[307].high[6] = -2.8137975693e+01;

		asali_->thermo_[307].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[307].low[0] = -9.6136063337e-01;
		asali_->thermo_[307].low[1] = 5.2725832909e-02;
		asali_->thermo_[307].low[2] = -3.2448158890e-05;
		asali_->thermo_[307].low[3] = 1.0020831276e-08;
		asali_->thermo_[307].low[4] = -1.2475413497e-12;
		asali_->thermo_[307].low[5] = 1.1046041016e+04;
		asali_->thermo_[307].low[6] = 3.0553283691e+01;
		
		asali_->thermo_[308].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[308].name,"C3H5OO");

		asali_->thermo_[308].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[308].high[0] = 7.6923012733e+00;
		asali_->thermo_[308].high[1] = 2.0536107942e-02;
		asali_->thermo_[308].high[2] = -9.6158983069e-06;
		asali_->thermo_[308].high[3] = 2.1533208550e-09;
		asali_->thermo_[308].high[4] = -1.8890948918e-13;
		asali_->thermo_[308].high[5] = 6.2148422852e+03;
		asali_->thermo_[308].high[6] = -1.0405375481e+01;

		asali_->thermo_[308].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[308].low[0] = 2.9642422199e+00;
		asali_->thermo_[308].low[1] = 3.1042905524e-02;
		asali_->thermo_[308].low[2] = -1.8371563783e-05;
		asali_->thermo_[308].low[3] = 5.3961595192e-09;
		asali_->thermo_[308].low[4] = -6.3930376834e-13;
		asali_->thermo_[308].low[5] = 7.9169433594e+03;
		asali_->thermo_[308].low[6] = 1.5183865547e+01;
		
		asali_->thermo_[309].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[309].name,"C5EN-OO");

		asali_->thermo_[309].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[309].high[0] = 1.0084032059e+01;
		asali_->thermo_[309].high[1] = 3.6991301924e-02;
		asali_->thermo_[309].high[2] = -1.7421618395e-05;
		asali_->thermo_[309].high[3] = 3.9313072797e-09;
		asali_->thermo_[309].high[4] = -3.4725740621e-13;
		asali_->thermo_[309].high[5] = -8.9841516113e+02;
		asali_->thermo_[309].high[6] = -1.9651363373e+01;

		asali_->thermo_[309].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[309].low[0] = 4.0989726782e-01;
		asali_->thermo_[309].low[1] = 6.7222975194e-02;
		asali_->thermo_[309].low[2] = -5.2849358326e-05;
		asali_->thermo_[309].low[3] = 2.2383256137e-08;
		asali_->thermo_[309].low[4] = -3.9511536404e-12;
		asali_->thermo_[309].low[5] = 1.5781633301e+03;
		asali_->thermo_[309].low[6] = 2.9408903122e+01;
		
		asali_->thermo_[310].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[310].name,"C5EN-QOOH");

		asali_->thermo_[310].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[310].high[0] = 1.2879127502e+01;
		asali_->thermo_[310].high[1] = 3.3293046057e-02;
		asali_->thermo_[310].high[2] = -1.5537892978e-05;
		asali_->thermo_[310].high[3] = 3.4667440030e-09;
		asali_->thermo_[310].high[4] = -3.0286978979e-13;
		asali_->thermo_[310].high[5] = 3.2301171875e+03;
		asali_->thermo_[310].high[6] = -3.3850719452e+01;

		asali_->thermo_[310].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[310].low[0] = 1.3440440893e+00;
		asali_->thermo_[310].low[1] = 6.5786235034e-02;
		asali_->thermo_[310].low[2] = -4.9861686421e-05;
		asali_->thermo_[310].low[3] = 1.9581202437e-08;
		asali_->thermo_[310].low[4] = -3.1399221331e-12;
		asali_->thermo_[310].low[5] = 6.5060810547e+03;
		asali_->thermo_[310].low[6] = 2.5844247818e+01;
		
		asali_->thermo_[311].name = (char*) malloc(14 * sizeof(char));
		strcpy(asali_->thermo_[311].name,"C5EN-OOQOOH-35");

		asali_->thermo_[311].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[311].high[0] = 1.3669976234e+01;
		asali_->thermo_[311].high[1] = 4.2123194784e-02;
		asali_->thermo_[311].high[2] = -2.1550371457e-05;
		asali_->thermo_[311].high[3] = 5.2180633148e-09;
		asali_->thermo_[311].high[4] = -4.8729304012e-13;
		asali_->thermo_[311].high[5] = -1.4235480469e+04;
		asali_->thermo_[311].high[6] = -3.3588336945e+01;

		asali_->thermo_[311].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[311].low[0] = 5.2457857132e-01;
		asali_->thermo_[311].low[1] = 8.7452150881e-02;
		asali_->thermo_[311].low[2] = -8.0165402323e-05;
		asali_->thermo_[311].low[3] = 3.8904865107e-08;
		asali_->thermo_[311].low[4] = -7.7473791271e-12;
		asali_->thermo_[311].low[5] = -1.1185748047e+04;
		asali_->thermo_[311].low[6] = 3.1781650543e+01;
		
		asali_->thermo_[312].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[312].name,"NC3H7OH");

		asali_->thermo_[312].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[312].high[0] = 1.0357866287e+01;
		asali_->thermo_[312].high[1] = 1.8783450127e-02;
		asali_->thermo_[312].high[2] = -6.5415511017e-06;
		asali_->thermo_[312].high[3] = 1.0679269691e-09;
		asali_->thermo_[312].high[4] = -6.7910155038e-14;
		asali_->thermo_[312].high[5] = -3.6005445312e+04;
		asali_->thermo_[312].high[6] = -2.8922452927e+01;

		asali_->thermo_[312].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[312].low[0] = 2.3463635147e-01;
		asali_->thermo_[312].low[1] = 4.1279517114e-02;
		asali_->thermo_[312].low[2] = -2.5288274628e-05;
		asali_->thermo_[312].low[3] = 8.0111570711e-09;
		asali_->thermo_[312].low[4] = -1.0322477465e-12;
		asali_->thermo_[312].low[5] = -3.2361082031e+04;
		asali_->thermo_[312].low[6] = 2.5866580963e+01;
		
		asali_->thermo_[313].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[313].name,"N1C4H9OH");

		asali_->thermo_[313].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[313].high[0] = 1.1907866478e+01;
		asali_->thermo_[313].high[1] = 2.6795992628e-02;
		asali_->thermo_[313].high[2] = -1.0794484297e-05;
		asali_->thermo_[313].high[3] = 2.1010615470e-09;
		asali_->thermo_[313].high[4] = -1.6353661047e-13;
		asali_->thermo_[313].high[5] = -3.9522117188e+04;
		asali_->thermo_[313].high[6] = -3.5738986969e+01;

		asali_->thermo_[313].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[313].low[0] = 7.7336005867e-02;
		asali_->thermo_[313].low[1] = 5.3086061031e-02;
		asali_->thermo_[313].low[2] = -3.2702871977e-05;
		asali_->thermo_[313].low[3] = 1.0215279289e-08;
		asali_->thermo_[313].low[4] = -1.2905113176e-12;
		asali_->thermo_[313].low[5] = -3.5263128906e+04;
		asali_->thermo_[313].low[6] = 2.8290309906e+01;
		
		asali_->thermo_[314].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[314].name,"N2C4H9OH");

		asali_->thermo_[314].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[314].high[0] = 1.3985007286e+01;
		asali_->thermo_[314].high[1] = 2.3576822132e-02;
		asali_->thermo_[314].high[2] = -8.7310609160e-06;
		asali_->thermo_[314].high[3] = 1.5154616451e-09;
		asali_->thermo_[314].high[4] = -1.0284745874e-13;
		asali_->thermo_[314].high[5] = -4.2405398438e+04;
		asali_->thermo_[314].high[6] = -4.8370285034e+01;

		asali_->thermo_[314].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[314].low[0] = 1.1191295087e-01;
		asali_->thermo_[314].low[1] = 5.4405920208e-02;
		asali_->thermo_[314].low[2] = -3.4421977034e-05;
		asali_->thermo_[314].low[3] = 1.1030615532e-08;
		asali_->thermo_[314].low[4] = -1.4243966250e-12;
		asali_->thermo_[314].low[5] = -3.7411085938e+04;
		asali_->thermo_[314].low[6] = 2.6713796616e+01;
		
		asali_->thermo_[315].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->thermo_[315].name,"CH3CH2CHOHCH2");

		asali_->thermo_[315].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[315].high[0] = 1.3933309555e+01;
		asali_->thermo_[315].high[1] = 2.0759977400e-02;
		asali_->thermo_[315].high[2] = -7.5609714258e-06;
		asali_->thermo_[315].high[3] = 1.2790011272e-09;
		asali_->thermo_[315].high[4] = -8.3723853588e-14;
		asali_->thermo_[315].high[5] = -1.7489744141e+04;
		asali_->thermo_[315].high[6] = -4.4613491058e+01;

		asali_->thermo_[315].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[315].low[0] = 9.1173303127e-01;
		asali_->thermo_[315].low[1] = 4.9696814269e-02;
		asali_->thermo_[315].low[2] = -3.1675001082e-05;
		asali_->thermo_[315].low[3] = 1.0210123413e-08;
		asali_->thermo_[315].low[4] = -1.3241574720e-12;
		asali_->thermo_[315].low[5] = -1.2801975586e+04;
		asali_->thermo_[315].low[6] = 2.5861997604e+01;
		
		asali_->thermo_[316].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->thermo_[316].name,"CH3CH2CHOCH3");

		asali_->thermo_[316].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[316].high[0] = 1.3043436050e+01;
		asali_->thermo_[316].high[1] = 2.3816477507e-02;
		asali_->thermo_[316].high[2] = -9.8255241028e-06;
		asali_->thermo_[316].high[3] = 1.9389754247e-09;
		asali_->thermo_[316].high[4] = -1.5191899117e-13;
		asali_->thermo_[316].high[5] = -1.5853833984e+04;
		asali_->thermo_[316].high[6] = -4.3508838654e+01;

		asali_->thermo_[316].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[316].low[0] = 4.1773173958e-02;
		asali_->thermo_[316].low[1] = 5.2709061652e-02;
		asali_->thermo_[316].low[2] = -3.3902677387e-05;
		asali_->thermo_[316].low[3] = 1.0856439303e-08;
		asali_->thermo_[316].low[4] = -1.3904556759e-12;
		asali_->thermo_[316].low[5] = -1.1173235352e+04;
		asali_->thermo_[316].low[6] = 2.6858873367e+01;
		
		asali_->thermo_[317].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->thermo_[317].name,"CH3CH2COHCH3");

		asali_->thermo_[317].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[317].high[0] = 8.7238225937e+00;
		asali_->thermo_[317].high[1] = 3.0434282497e-02;
		asali_->thermo_[317].high[2] = -1.3918554941e-05;
		asali_->thermo_[317].high[3] = 3.0604385692e-09;
		asali_->thermo_[317].high[4] = -2.6468923082e-13;
		asali_->thermo_[317].high[5] = -1.8066126953e+04;
		asali_->thermo_[317].high[6] = -1.7143508911e+01;

		asali_->thermo_[317].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[317].low[0] = 1.2739583254e+00;
		asali_->thermo_[317].low[1] = 5.1273062825e-02;
		asali_->thermo_[317].low[2] = -3.5777415178e-05;
		asali_->thermo_[317].low[3] = 1.3251050035e-08;
		asali_->thermo_[317].low[4] = -2.0462646334e-12;
		asali_->thermo_[317].low[5] = -1.5935465820e+04;
		asali_->thermo_[317].low[6] = 2.1462406158e+01;
		
		asali_->thermo_[318].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->thermo_[318].name,"CH3CHCHOHCH3");

		asali_->thermo_[318].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[318].high[0] = 1.1152401924e+01;
		asali_->thermo_[318].high[1] = 2.5291237980e-02;
		asali_->thermo_[318].high[2] = -1.0517948795e-05;
		asali_->thermo_[318].high[3] = 2.1239265902e-09;
		asali_->thermo_[318].high[4] = -1.7155301160e-13;
		asali_->thermo_[318].high[5] = -1.7809541016e+04;
		asali_->thermo_[318].high[6] = -2.9420972824e+01;

		asali_->thermo_[318].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[318].low[0] = 6.7690235376e-01;
		asali_->thermo_[318].low[1] = 4.8570126295e-02;
		asali_->thermo_[318].low[2] = -2.9917020584e-05;
		asali_->thermo_[318].low[3] = 9.3087679787e-09;
		asali_->thermo_[318].low[4] = -1.1694476767e-12;
		asali_->thermo_[318].low[5] = -1.4038361328e+04;
		asali_->thermo_[318].low[6] = 2.7274616241e+01;
		
		asali_->thermo_[319].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->thermo_[319].name,"CH2CH2CHOHCH3");

		asali_->thermo_[319].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[319].high[0] = 1.3933309555e+01;
		asali_->thermo_[319].high[1] = 2.0759977400e-02;
		asali_->thermo_[319].high[2] = -7.5609714258e-06;
		asali_->thermo_[319].high[3] = 1.2790011272e-09;
		asali_->thermo_[319].high[4] = -8.3723853588e-14;
		asali_->thermo_[319].high[5] = -1.7489744141e+04;
		asali_->thermo_[319].high[6] = -4.4613491058e+01;

		asali_->thermo_[319].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[319].low[0] = 9.1173303127e-01;
		asali_->thermo_[319].low[1] = 4.9696814269e-02;
		asali_->thermo_[319].low[2] = -3.1675001082e-05;
		asali_->thermo_[319].low[3] = 1.0210123413e-08;
		asali_->thermo_[319].low[4] = -1.3241574720e-12;
		asali_->thermo_[319].low[5] = -1.2801975586e+04;
		asali_->thermo_[319].low[6] = 2.5861997604e+01;
		
		asali_->thermo_[320].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[320].name,"MEK");

		asali_->thermo_[320].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[320].high[0] = 1.0099667549e+01;
		asali_->thermo_[320].high[1] = 2.2285092622e-02;
		asali_->thermo_[320].high[2] = -8.2411279436e-06;
		asali_->thermo_[320].high[3] = 1.4276037019e-09;
		asali_->thermo_[320].high[4] = -9.7765491449e-14;
		asali_->thermo_[320].high[5] = -3.4027093750e+04;
		asali_->thermo_[320].high[6] = -2.5500280380e+01;

		asali_->thermo_[320].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[320].low[0] = 1.6713862419e+00;
		asali_->thermo_[320].low[1] = 4.1014607996e-02;
		asali_->thermo_[320].low[2] = -2.3849055651e-05;
		asali_->thermo_[320].low[3] = 7.2083179425e-09;
		asali_->thermo_[320].low[4] = -9.0064246209e-13;
		asali_->thermo_[320].low[5] = -3.0992914062e+04;
		asali_->thermo_[320].low[6] = 2.0115335464e+01;
		
		asali_->thermo_[321].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[321].name,"TC4H9OH");

		asali_->thermo_[321].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[321].high[0] = 9.0815038681e+00;
		asali_->thermo_[321].high[1] = 3.2220184803e-02;
		asali_->thermo_[321].high[2] = -1.4197935343e-05;
		asali_->thermo_[321].high[3] = 3.0324927014e-09;
		asali_->thermo_[321].high[4] = -2.5665835559e-13;
		asali_->thermo_[321].high[5] = -4.2391722656e+04;
		asali_->thermo_[321].high[6] = -2.3626321793e+01;

		asali_->thermo_[321].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[321].low[0] = -6.9999957085e-01;
		asali_->thermo_[321].low[1] = 5.9391025454e-02;
		asali_->thermo_[321].low[2] = -4.2500898417e-05;
		asali_->thermo_[321].low[3] = 1.6135714986e-08;
		asali_->thermo_[321].low[4] = -2.5315233850e-12;
		asali_->thermo_[321].low[5] = -3.9574648438e+04;
		asali_->thermo_[321].low[6] = 2.7130535126e+01;
		
		asali_->thermo_[322].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[322].name,"IC4H9OH");

		asali_->thermo_[322].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[322].high[0] = 1.4453751564e+01;
		asali_->thermo_[322].high[1] = 2.2081069648e-02;
		asali_->thermo_[322].high[2] = -7.5795928751e-06;
		asali_->thermo_[322].high[3] = 1.1953367185e-09;
		asali_->thermo_[322].high[4] = -7.1616757663e-14;
		asali_->thermo_[322].high[5] = -4.1582281250e+04;
		asali_->thermo_[322].high[6] = -5.1331550598e+01;

		asali_->thermo_[322].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[322].low[0] = -5.4547947645e-01;
		asali_->thermo_[322].low[1] = 5.5412694812e-02;
		asali_->thermo_[322].low[2] = -3.5355948057e-05;
		asali_->thermo_[322].low[3] = 1.1482875095e-08;
		asali_->thermo_[322].low[4] = -1.5004415896e-12;
		asali_->thermo_[322].low[5] = -3.6182558594e+04;
		asali_->thermo_[322].low[6] = 2.9847417831e+01;
		
		asali_->thermo_[323].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->thermo_[323].name,"CH3CH2CH2CH2O");

		asali_->thermo_[323].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[323].high[0] = 1.1609337807e+01;
		asali_->thermo_[323].high[1] = 2.5698179379e-02;
		asali_->thermo_[323].high[2] = -1.0967655726e-05;
		asali_->thermo_[323].high[3] = 2.2599309091e-09;
		asali_->thermo_[323].high[4] = -1.8531397662e-13;
		asali_->thermo_[323].high[5] = -1.3194814453e+04;
		asali_->thermo_[323].high[6] = -3.4357391357e+01;

		asali_->thermo_[323].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[323].low[0] = 5.9054937214e-02;
		asali_->thermo_[323].low[1] = 5.1365476102e-02;
		asali_->thermo_[323].low[2] = -3.2357067539e-05;
		asali_->thermo_[323].low[3] = 1.0181936183e-08;
		asali_->thermo_[323].low[4] = -1.2855924008e-12;
		asali_->thermo_[323].low[5] = -9.0367128906e+03;
		asali_->thermo_[323].low[6] = 2.8155151367e+01;
		
		asali_->thermo_[324].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[324].name,"C3H7CHO");

		asali_->thermo_[324].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[324].high[0] = -9.7727942467e-01;
		asali_->thermo_[324].high[1] = 5.2498374134e-02;
		asali_->thermo_[324].high[2] = -3.0976232665e-05;
		asali_->thermo_[324].high[3] = 8.3268023587e-09;
		asali_->thermo_[324].high[4] = -8.3815652986e-13;
		asali_->thermo_[324].high[5] = -2.7076771484e+04;
		asali_->thermo_[324].high[6] = 3.2719490051e+01;

		asali_->thermo_[324].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[324].low[0] = 3.7155449390e+00;
		asali_->thermo_[324].low[1] = 2.5682235137e-02;
		asali_->thermo_[324].low[2] = 2.6486921342e-05;
		asali_->thermo_[324].low[3] = -4.6400010945e-08;
		asali_->thermo_[324].low[4] = 1.8707134800e-11;
		asali_->thermo_[324].low[5] = -2.7733765625e+04;
		asali_->thermo_[324].low[6] = 1.1753139496e+01;
		
		asali_->thermo_[325].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[325].name,"CH3CH2CHOH");

		asali_->thermo_[325].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[325].high[0] = 8.2818098068e+00;
		asali_->thermo_[325].high[1] = 2.0074496046e-02;
		asali_->thermo_[325].high[2] = -8.2104161265e-06;
		asali_->thermo_[325].high[3] = 1.6234933398e-09;
		asali_->thermo_[325].high[4] = -1.2791776373e-13;
		asali_->thermo_[325].high[5] = -1.3049283203e+04;
		asali_->thermo_[325].high[6] = -1.5617909431e+01;

		asali_->thermo_[325].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[325].low[0] = 1.7383540869e+00;
		asali_->thermo_[325].low[1] = 3.6231178790e-02;
		asali_->thermo_[325].low[2] = -2.3170307031e-05;
		asali_->thermo_[325].low[3] = 7.7798265607e-09;
		asali_->thermo_[325].low[4] = -1.0779692026e-12;
		asali_->thermo_[325].low[5] = -1.0929203125e+04;
		asali_->thermo_[325].low[6] = 1.9107217789e+01;
		
		asali_->thermo_[326].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[326].name,"CH3CHCH2OH");

		asali_->thermo_[326].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[326].high[0] = 7.6450195312e+00;
		asali_->thermo_[326].high[1] = 2.0699692890e-02;
		asali_->thermo_[326].high[2] = -8.7782464107e-06;
		asali_->thermo_[326].high[3] = 1.8424535231e-09;
		asali_->thermo_[326].high[4] = -1.5599232518e-13;
		asali_->thermo_[326].high[5] = -1.1505042969e+04;
		asali_->thermo_[326].high[6] = -1.0813188553e+01;

		asali_->thermo_[326].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[326].low[0] = 5.3903520107e-01;
		asali_->thermo_[326].low[1] = 3.6490768194e-02;
		asali_->thermo_[326].low[2] = -2.1937476049e-05;
		asali_->thermo_[326].low[3] = 6.7162422290e-09;
		asali_->thermo_[326].low[4] = -8.3290747346e-13;
		asali_->thermo_[326].low[5] = -8.9468886719e+03;
		asali_->thermo_[326].low[6] = 2.7645879745e+01;
		
		asali_->thermo_[327].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[327].name,"CH2CH2CH2OH");

		asali_->thermo_[327].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[327].high[0] = 9.4977035522e+00;
		asali_->thermo_[327].high[1] = 1.7706109211e-02;
		asali_->thermo_[327].high[2] = -6.6845695983e-06;
		asali_->thermo_[327].high[3] = 1.2098199109e-09;
		asali_->thermo_[327].high[4] = -8.7317956685e-14;
		asali_->thermo_[327].high[5] = -1.0797620117e+04;
		asali_->thermo_[327].high[6] = -2.0782924652e+01;

		asali_->thermo_[327].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[327].low[0] = 1.0462905169e+00;
		asali_->thermo_[327].low[1] = 3.6487028003e-02;
		asali_->thermo_[327].low[2] = -2.2335334506e-05;
		asali_->thermo_[327].low[3] = 7.0063999047e-09;
		asali_->thermo_[327].low[4] = -8.9239845982e-13;
		asali_->thermo_[327].low[5] = -7.7551113281e+03;
		asali_->thermo_[327].low[6] = 2.4957885742e+01;
		
		asali_->thermo_[328].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[328].name,"CH3CH2CH2O");

		asali_->thermo_[328].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[328].high[0] = 9.0774955750e+00;
		asali_->thermo_[328].high[1] = 1.9697545096e-02;
		asali_->thermo_[328].high[2] = -8.1808902905e-06;
		asali_->thermo_[328].high[3] = 1.6432897265e-09;
		asali_->thermo_[328].high[4] = -1.3178615642e-13;
		asali_->thermo_[328].high[5] = -9.3106113281e+03;
		asali_->thermo_[328].high[6] = -2.2168727875e+01;

		asali_->thermo_[328].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[328].low[0] = 2.9195886850e-01;
		asali_->thermo_[328].low[1] = 3.9220962673e-02;
		asali_->thermo_[328].low[2] = -2.4450404453e-05;
		asali_->thermo_[328].low[3] = 7.6690351847e-09;
		asali_->thermo_[328].low[4] = -9.6869528458e-13;
		asali_->thermo_[328].low[5] = -6.1478178711e+03;
		asali_->thermo_[328].low[6] = 2.5380432129e+01;
		
		asali_->thermo_[329].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[329].name,"CH3COHCH3");

		asali_->thermo_[329].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[329].high[0] = 6.7165255547e+00;
		asali_->thermo_[329].high[1] = 2.3530649021e-02;
		asali_->thermo_[329].high[2] = -1.0614474377e-05;
		asali_->thermo_[329].high[3] = 2.3176163211e-09;
		asali_->thermo_[329].high[4] = -1.9988631789e-13;
		asali_->thermo_[329].high[5] = -1.4417508789e+04;
		asali_->thermo_[329].high[6] = -7.9047632217e+00;

		asali_->thermo_[329].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[329].low[0] = 1.2164982557e+00;
		asali_->thermo_[329].low[1] = 4.0853571147e-02;
		asali_->thermo_[329].low[2] = -3.1074618164e-05;
		asali_->thermo_[329].low[3] = 1.3057849024e-08;
		asali_->thermo_[329].low[4] = -2.3141052876e-12;
		asali_->thermo_[329].low[5] = -1.3020501953e+04;
		asali_->thermo_[329].low[6] = 1.9944290161e+01;
		
		asali_->thermo_[330].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[330].name,"CH2CHOHCH3");

		asali_->thermo_[330].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[330].high[0] = 6.3269443512e+00;
		asali_->thermo_[330].high[1] = 2.3876249790e-02;
		asali_->thermo_[330].high[2] = -1.0737618140e-05;
		asali_->thermo_[330].high[3] = 2.3373702973e-09;
		asali_->thermo_[330].high[4] = -2.0106946707e-13;
		asali_->thermo_[330].high[5] = -1.1421737305e+04;
		asali_->thermo_[330].high[6] = -3.9569048882e+00;

		asali_->thermo_[330].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[330].low[0] = 6.4075696468e-01;
		asali_->thermo_[330].low[1] = 4.0357951075e-02;
		asali_->thermo_[330].low[2] = -2.8652511901e-05;
		asali_->thermo_[330].low[3] = 1.0991908717e-08;
		asali_->thermo_[330].low[4] = -1.7689206220e-12;
		asali_->thermo_[330].low[5] = -9.8523496094e+03;
		asali_->thermo_[330].low[6] = 2.5307088852e+01;
		
		asali_->thermo_[331].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->thermo_[331].name,"CH3CH2CH2CHOH");

		asali_->thermo_[331].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[331].high[0] = 1.3015166283e+01;
		asali_->thermo_[331].high[1] = 2.2175000980e-02;
		asali_->thermo_[331].high[2] = -8.4915654952e-06;
		asali_->thermo_[331].high[3] = 1.5486036897e-09;
		asali_->thermo_[331].high[4] = -1.1201367660e-13;
		asali_->thermo_[331].high[5] = -1.7908121094e+04;
		asali_->thermo_[331].high[6] = -4.0199443817e+01;

		asali_->thermo_[331].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[331].low[0] = 1.7548933029e+00;
		asali_->thermo_[331].low[1] = 4.7197829932e-02;
		asali_->thermo_[331].low[2] = -2.9343922506e-05;
		asali_->thermo_[331].low[3] = 9.2716989641e-09;
		asali_->thermo_[331].low[4] = -1.1846657553e-12;
		asali_->thermo_[331].low[5] = -1.3854423828e+04;
		asali_->thermo_[331].low[6] = 2.0743501663e+01;
		
		asali_->thermo_[332].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->thermo_[332].name,"CH3CH2CHCH2OH");

		asali_->thermo_[332].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[332].high[0] = 1.1512477875e+01;
		asali_->thermo_[332].high[1] = 2.4107260630e-02;
		asali_->thermo_[332].high[2] = -9.8640202850e-06;
		asali_->thermo_[332].high[3] = 1.9867469891e-09;
		asali_->thermo_[332].high[4] = -1.6211989704e-13;
		asali_->thermo_[332].high[5] = -1.5899163086e+04;
		asali_->thermo_[332].high[6] = -3.0357999802e+01;

		asali_->thermo_[332].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[332].low[0] = 1.5345734358e-01;
		asali_->thermo_[332].low[1] = 4.9349527806e-02;
		asali_->thermo_[332].low[2] = -3.0899242120e-05;
		asali_->thermo_[332].low[3] = 9.7775698649e-09;
		asali_->thermo_[332].low[4] = -1.2441786967e-12;
		asali_->thermo_[332].low[5] = -1.1809916016e+04;
		asali_->thermo_[332].low[6] = 3.1119386673e+01;
		
		asali_->thermo_[333].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->thermo_[333].name,"CH3CHCH2CH2OH");

		asali_->thermo_[333].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[333].high[0] = 1.1512477875e+01;
		asali_->thermo_[333].high[1] = 2.4107260630e-02;
		asali_->thermo_[333].high[2] = -9.8640202850e-06;
		asali_->thermo_[333].high[3] = 1.9867469891e-09;
		asali_->thermo_[333].high[4] = -1.6211989704e-13;
		asali_->thermo_[333].high[5] = -1.5899163086e+04;
		asali_->thermo_[333].high[6] = -3.0357999802e+01;

		asali_->thermo_[333].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[333].low[0] = 1.5345734358e-01;
		asali_->thermo_[333].low[1] = 4.9349527806e-02;
		asali_->thermo_[333].low[2] = -3.0899242120e-05;
		asali_->thermo_[333].low[3] = 9.7775698649e-09;
		asali_->thermo_[333].low[4] = -1.2441786967e-12;
		asali_->thermo_[333].low[5] = -1.1809916016e+04;
		asali_->thermo_[333].low[6] = 3.1119386673e+01;
		
		asali_->thermo_[334].name = (char*) malloc(14 * sizeof(char));
		strcpy(asali_->thermo_[334].name,"CH2CH2CH2CH2OH");

		asali_->thermo_[334].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[334].high[0] = 1.1757286072e+01;
		asali_->thermo_[334].high[1] = 2.4157427251e-02;
		asali_->thermo_[334].high[2] = -9.7297688626e-06;
		asali_->thermo_[334].high[3] = 1.8914387834e-09;
		asali_->thermo_[334].high[4] = -1.4694529502e-13;
		asali_->thermo_[334].high[5] = -1.4567215820e+04;
		asali_->thermo_[334].high[6] = -3.1437793732e+01;

		asali_->thermo_[334].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[334].low[0] = 8.9376413822e-01;
		asali_->thermo_[334].low[1] = 4.8298586160e-02;
		asali_->thermo_[334].low[2] = -2.9847400583e-05;
		asali_->thermo_[334].low[3] = 9.3424139536e-09;
		asali_->thermo_[334].low[4] = -1.1818029194e-12;
		asali_->thermo_[334].low[5] = -1.0656348633e+04;
		asali_->thermo_[334].low[6] = 2.7357851028e+01;
		
		asali_->thermo_[335].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[335].name,"RTC4H8OH");

		asali_->thermo_[335].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[335].high[0] = 8.6682348251e+00;
		asali_->thermo_[335].high[1] = 3.0127173290e-02;
		asali_->thermo_[335].high[2] = -1.3525625036e-05;
		asali_->thermo_[335].high[3] = 2.9411728608e-09;
		asali_->thermo_[335].high[4] = -2.5282217726e-13;
		asali_->thermo_[335].high[5] = -1.7347896484e+04;
		asali_->thermo_[335].high[6] = -1.6802371979e+01;

		asali_->thermo_[335].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[335].low[0] = 1.3990132138e-03;
		asali_->thermo_[335].low[1] = 5.5248435587e-02;
		asali_->thermo_[335].low[2] = -4.0831346269e-05;
		asali_->thermo_[335].low[3] = 1.6132341685e-08;
		asali_->thermo_[335].low[4] = -2.6425268224e-12;
		asali_->thermo_[335].low[5] = -1.4955849609e+04;
		asali_->thermo_[335].low[6] = 2.7801546097e+01;
		
		asali_->thermo_[336].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[336].name,"RTC4H9O");

		asali_->thermo_[336].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[336].high[0] = 1.1685253143e+01;
		asali_->thermo_[336].high[1] = 2.5715537369e-02;
		asali_->thermo_[336].high[2] = -1.0753956303e-05;
		asali_->thermo_[336].high[3] = 2.1592461152e-09;
		asali_->thermo_[336].high[4] = -1.7189701539e-13;
		asali_->thermo_[336].high[5] = -1.7260759766e+04;
		asali_->thermo_[336].high[6] = -3.7308563232e+01;

		asali_->thermo_[336].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[336].low[0] = -2.9443597794e-01;
		asali_->thermo_[336].low[1] = 5.5478740484e-02;
		asali_->thermo_[336].low[2] = -3.8483645767e-05;
		asali_->thermo_[336].low[3] = 1.3641519914e-08;
		asali_->thermo_[336].low[4] = -1.9548588009e-12;
		asali_->thermo_[336].low[5] = -1.3403299805e+04;
		asali_->thermo_[336].low[6] = 2.6191646576e+01;
		
		asali_->thermo_[337].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->thermo_[337].name,"CH3CHCH2OCH3");

		asali_->thermo_[337].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[337].high[0] = 1.3848838806e+01;
		asali_->thermo_[337].high[1] = 2.1483484656e-02;
		asali_->thermo_[337].high[2] = -8.0302888819e-06;
		asali_->thermo_[337].high[3] = 1.4216705591e-09;
		asali_->thermo_[337].high[4] = -9.9543704985e-14;
		asali_->thermo_[337].high[5] = -1.5124944336e+04;
		asali_->thermo_[337].high[6] = -4.8220954895e+01;

		asali_->thermo_[337].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[337].low[0] = -4.6902638674e-01;
		asali_->thermo_[337].low[1] = 5.3300961852e-02;
		asali_->thermo_[337].low[2] = -3.4544853406e-05;
		asali_->thermo_[337].low[3] = 1.1241879427e-08;
		asali_->thermo_[337].low[4] = -1.4634616219e-12;
		asali_->thermo_[337].low[5] = -9.9705126953e+03;
		asali_->thermo_[337].low[6] = 2.9270317078e+01;
		
		asali_->thermo_[338].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->thermo_[338].name,"CH3CHCH3CHOH");

		asali_->thermo_[338].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[338].high[0] = 8.9141187668e+00;
		asali_->thermo_[338].high[1] = 2.9418483377e-02;
		asali_->thermo_[338].high[2] = -1.3048850633e-05;
		asali_->thermo_[338].high[3] = 2.8102096206e-09;
		asali_->thermo_[338].high[4] = -2.3974981614e-13;
		asali_->thermo_[338].high[5] = -1.7114533203e+04;
		asali_->thermo_[338].high[6] = -1.8525569916e+01;

		asali_->thermo_[338].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[338].low[0] = 6.1610633135e-01;
		asali_->thermo_[338].low[1] = 5.2309554070e-02;
		asali_->thermo_[338].low[2] = -3.6729266867e-05;
		asali_->thermo_[338].low[3] = 1.3697757595e-08;
		asali_->thermo_[338].low[4] = -2.1169131986e-12;
		asali_->thermo_[338].low[5] = -1.4708110352e+04;
		asali_->thermo_[338].low[6] = 2.4590782166e+01;
		
		asali_->thermo_[339].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->thermo_[339].name,"CH3CCH2OHCH3");

		asali_->thermo_[339].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[339].high[0] = 2.0207667351e+00;
		asali_->thermo_[339].high[1] = 4.0990367532e-02;
		asali_->thermo_[339].high[2] = -2.0648687496e-05;
		asali_->thermo_[339].high[3] = 5.0050763534e-09;
		asali_->thermo_[339].high[4] = -4.7152342794e-13;
		asali_->thermo_[339].high[5] = -1.4071836914e+04;
		asali_->thermo_[339].high[6] = 2.1588098526e+01;

		asali_->thermo_[339].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[339].low[0] = 3.5344793797e+00;
		asali_->thermo_[339].low[1] = 3.2340582460e-02;
		asali_->thermo_[339].low[2] = -2.1134285362e-06;
		asali_->thermo_[339].low[3] = -1.2647550562e-08;
		asali_->thermo_[339].low[4] = 5.8329860039e-12;
		asali_->thermo_[339].low[5] = -1.4283756836e+04;
		asali_->thermo_[339].low[6] = 1.4825213432e+01;
		
		asali_->thermo_[340].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->thermo_[340].name,"CH2CHCH2OHCH3");

		asali_->thermo_[340].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[340].high[0] = 1.3812992096e+01;
		asali_->thermo_[340].high[1] = 2.0281903446e-02;
		asali_->thermo_[340].high[2] = -7.0337277975e-06;
		asali_->thermo_[340].high[3] = 1.1243985742e-09;
		asali_->thermo_[340].high[4] = -6.8600290379e-14;
		asali_->thermo_[340].high[5] = -1.6404558594e+04;
		asali_->thermo_[340].high[6] = -4.4251708984e+01;

		asali_->thermo_[340].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[340].low[0] = 2.3245260119e-01;
		asali_->thermo_[340].low[1] = 5.0799969584e-02;
		asali_->thermo_[340].low[2] = -3.2751198887e-05;
		asali_->thermo_[340].low[3] = 1.0756409985e-08;
		asali_->thermo_[340].low[4] = -1.4214109490e-12;
		asali_->thermo_[340].low[5] = -1.1569885742e+04;
		asali_->thermo_[340].low[6] = 2.9097263336e+01;
		
		asali_->thermo_[341].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[341].name,"C4H7OH");

		asali_->thermo_[341].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[341].high[0] = 1.0098166466e+01;
		asali_->thermo_[341].high[1] = 2.1573493257e-02;
		asali_->thermo_[341].high[2] = -6.7400842454e-06;
		asali_->thermo_[341].high[3] = 9.1682594849e-10;
		asali_->thermo_[341].high[4] = -4.1620017572e-14;
		asali_->thermo_[341].high[5] = -2.3729091797e+04;
		asali_->thermo_[341].high[6] = -2.4574159622e+01;

		asali_->thermo_[341].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[341].low[0] = -2.5553134084e-01;
		asali_->thermo_[341].low[1] = 4.9939788878e-02;
		asali_->thermo_[341].low[2] = -3.5883538658e-05;
		asali_->thermo_[341].low[3] = 1.4224339040e-08;
		asali_->thermo_[341].low[4] = -2.3203038883e-12;
		asali_->thermo_[341].low[5] = -2.0705810547e+04;
		asali_->thermo_[341].low[6] = 2.9294664383e+01;
		
		asali_->thermo_[342].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[342].name,"C3H5OH");

		asali_->thermo_[342].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[342].high[0] = 2.4586317539e+00;
		asali_->thermo_[342].high[1] = 2.6644645259e-02;
		asali_->thermo_[342].high[2] = -1.2487976164e-05;
		asali_->thermo_[342].high[3] = 2.9219879849e-09;
		asali_->thermo_[342].high[4] = -2.7187269363e-13;
		asali_->thermo_[342].high[5] = -1.7224000000e+04;
		asali_->thermo_[342].high[6] = 1.8383033752e+01;

		asali_->thermo_[342].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[342].low[0] = 4.2499928474e+00;
		asali_->thermo_[342].low[1] = 1.7906298861e-02;
		asali_->thermo_[342].low[2] = 3.4968049931e-06;
		asali_->thermo_[342].low[3] = -1.0073768486e-08;
		asali_->thermo_[342].low[4] = 3.6902481938e-12;
		asali_->thermo_[342].low[5] = -1.7517783203e+04;
		asali_->thermo_[342].low[6] = 1.0096249580e+01;
		
		asali_->thermo_[343].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[343].name,"RCRESOLO");

		asali_->thermo_[343].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[343].high[0] = 1.2782481194e+01;
		asali_->thermo_[343].high[1] = 2.4079641327e-02;
		asali_->thermo_[343].high[2] = -4.5134793254e-06;
		asali_->thermo_[343].high[3] = -4.2507633524e-10;
		asali_->thermo_[343].high[4] = 1.4498848628e-13;
		asali_->thermo_[343].high[5] = -3.9770476074e+03;
		asali_->thermo_[343].high[6] = -4.0054378510e+01;

		asali_->thermo_[343].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[343].low[0] = -6.6075720787e+00;
		asali_->thermo_[343].low[1] = 9.1523304582e-02;
		asali_->thermo_[343].low[2] = -9.2483474873e-05;
		asali_->thermo_[343].low[3] = 5.0572023014e-08;
		asali_->thermo_[343].low[4] = -1.0941337246e-11;
		asali_->thermo_[343].low[5] = 4.8266470337e+02;
		asali_->thermo_[343].low[6] = 5.6201412201e+01;
		
		asali_->thermo_[344].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[344].name,"RCRESOLC");

		asali_->thermo_[344].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[344].high[0] = 1.3154170990e+01;
		asali_->thermo_[344].high[1] = 2.5065718219e-02;
		asali_->thermo_[344].high[2] = -5.3235389714e-06;
		asali_->thermo_[344].high[3] = -2.1268758976e-10;
		asali_->thermo_[344].high[4] = 1.2584045947e-13;
		asali_->thermo_[344].high[5] = -3.3808642578e+03;
		asali_->thermo_[344].high[6] = -4.2233955383e+01;

		asali_->thermo_[344].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[344].low[0] = -6.4295678139e+00;
		asali_->thermo_[344].low[1] = 9.3183070421e-02;
		asali_->thermo_[344].low[2] = -9.4172261015e-05;
		asali_->thermo_[344].low[3] = 5.1293817194e-08;
		asali_->thermo_[344].low[4] = -1.1071225534e-11;
		asali_->thermo_[344].low[5] = 1.1233957520e+03;
		asali_->thermo_[344].low[6] = 5.4983325958e+01;
		
		asali_->thermo_[345].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[345].name,"C10H10");

		asali_->thermo_[345].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[345].high[0] = 1.8259269714e+01;
		asali_->thermo_[345].high[1] = 4.1593421251e-02;
		asali_->thermo_[345].high[2] = -1.8363183699e-05;
		asali_->thermo_[345].high[3] = 3.8849115036e-09;
		asali_->thermo_[345].high[4] = -3.2742081615e-13;
		asali_->thermo_[345].high[5] = 4.3968784180e+03;
		asali_->thermo_[345].high[6] = -8.2392318726e+01;

		asali_->thermo_[345].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[345].low[0] = -1.1458896637e+01;
		asali_->thermo_[345].low[1] = 1.0763379186e-01;
		asali_->thermo_[345].low[2] = -7.3396826338e-05;
		asali_->thermo_[345].low[3] = 2.4267741594e-08;
		asali_->thermo_[345].low[4] = -3.1583693993e-12;
		asali_->thermo_[345].low[5] = 1.5095417969e+04;
		asali_->thermo_[345].low[6] = 7.8448593140e+01;
		
		asali_->thermo_[346].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[346].name,"BZFUR");

		asali_->thermo_[346].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[346].high[0] = 1.6457834244e+01;
		asali_->thermo_[346].high[1] = 2.3762356490e-02;
		asali_->thermo_[346].high[2] = -8.5221863628e-06;
		asali_->thermo_[346].high[3] = 1.3612371230e-09;
		asali_->thermo_[346].high[4] = -7.9715991837e-14;
		asali_->thermo_[346].high[5] = -5.9059697266e+03;
		asali_->thermo_[346].high[6] = -6.5948036194e+01;

		asali_->thermo_[346].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[346].low[0] = -8.7013692856e+00;
		asali_->thermo_[346].low[1] = 9.6687585115e-02;
		asali_->thermo_[346].low[2] = -8.7788735982e-05;
		asali_->thermo_[346].low[3] = 3.9654256767e-08;
		asali_->thermo_[346].low[4] = -7.0168571474e-12;
		asali_->thermo_[346].low[5] = 1.0379702148e+03;
		asali_->thermo_[346].low[6] = 6.3533935547e+01;
		
		asali_->thermo_[347].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[347].name,"ODECAL");

		asali_->thermo_[347].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[347].high[0] = 2.8210994720e+01;
		asali_->thermo_[347].high[1] = 4.7410838306e-02;
		asali_->thermo_[347].high[2] = -1.8296384951e-05;
		asali_->thermo_[347].high[3] = 3.4208416100e-09;
		asali_->thermo_[347].high[4] = -2.5781712377e-13;
		asali_->thermo_[347].high[5] = -2.6835523438e+04;
		asali_->thermo_[347].high[6] = -1.3141020203e+02;

		asali_->thermo_[347].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[347].low[0] = -1.0271077156e+01;
		asali_->thermo_[347].low[1] = 1.3292655349e-01;
		asali_->thermo_[347].low[2] = -8.9559478511e-05;
		asali_->thermo_[347].low[3] = 2.9814579250e-08;
		asali_->thermo_[347].low[4] = -3.9236140378e-12;
		asali_->thermo_[347].low[5] = -1.2981977539e+04;
		asali_->thermo_[347].low[6] = 7.6862792969e+01;
		
		asali_->thermo_[348].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[348].name,"RTETRALIN");

		asali_->thermo_[348].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[348].high[0] = 2.9242805481e+01;
		asali_->thermo_[348].high[1] = 2.6783592999e-02;
		asali_->thermo_[348].high[2] = -9.1724950835e-06;
		asali_->thermo_[348].high[3] = 1.4295253870e-09;
		asali_->thermo_[348].high[4] = -8.4646618057e-14;
		asali_->thermo_[348].high[5] = 3.9564650879e+03;
		asali_->thermo_[348].high[6] = -1.4454060364e+02;

		asali_->thermo_[348].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[348].low[0] = -1.0933157921e+01;
		asali_->thermo_[348].low[1] = 1.1606351286e-01;
		asali_->thermo_[348].low[2] = -8.3572427684e-05;
		asali_->thermo_[348].low[3] = 2.8985056133e-08;
		asali_->thermo_[348].low[4] = -3.9118036067e-12;
		asali_->thermo_[348].low[5] = 1.8419812500e+04;
		asali_->thermo_[348].low[6] = 7.2900085449e+01;
		
		asali_->thermo_[349].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[349].name,"RTETRAOO");

		asali_->thermo_[349].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[349].high[0] = 5.3461902618e+01;
		asali_->thermo_[349].high[1] = -7.8928312287e-03;
		asali_->thermo_[349].high[2] = 1.0969720279e-05;
		asali_->thermo_[349].high[3] = -3.8948981818e-09;
		asali_->thermo_[349].high[4] = 4.3858628751e-13;
		asali_->thermo_[349].high[5] = -1.7692416016e+04;
		asali_->thermo_[349].high[6] = -2.7182342529e+02;

		asali_->thermo_[349].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[349].low[0] = -1.3634392738e+01;
		asali_->thermo_[349].low[1] = 1.4121004939e-01;
		asali_->thermo_[349].low[2] = -1.1328268010e-04;
		asali_->thermo_[349].low[3] = 4.2124508326e-08;
		asali_->thermo_[349].low[4] = -5.9529980771e-12;
		asali_->thermo_[349].low[5] = 6.4622504883e+03;
		asali_->thermo_[349].low[6] = 9.1315727234e+01;
		
		asali_->thermo_[350].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[350].name,"TMBENZ");

		asali_->thermo_[350].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[350].high[0] = 1.4757685661e+01;
		asali_->thermo_[350].high[1] = 4.5031581074e-02;
		asali_->thermo_[350].high[2] = -1.9755419999e-05;
		asali_->thermo_[350].high[3] = 4.2119783217e-09;
		asali_->thermo_[350].high[4] = -3.5731492634e-13;
		asali_->thermo_[350].high[5] = -1.0902583984e+04;
		asali_->thermo_[350].high[6] = -5.3537837982e+01;

		asali_->thermo_[350].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[350].low[0] = -2.7552278042e+00;
		asali_->thermo_[350].low[1] = 8.3949171007e-02;
		asali_->thermo_[350].low[2] = -5.2186740504e-05;
		asali_->thermo_[350].low[3] = 1.6223578925e-08;
		asali_->thermo_[350].low[4] = -2.0255928011e-12;
		asali_->thermo_[350].low[5] = -4.5979350586e+03;
		asali_->thermo_[350].low[6] = 4.1245704651e+01;
		
		asali_->thermo_[351].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[351].name,"NPBENZ");

		asali_->thermo_[351].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[351].high[0] = 1.8896337509e+01;
		asali_->thermo_[351].high[1] = 3.8009028882e-02;
		asali_->thermo_[351].high[2] = -1.5278938008e-05;
		asali_->thermo_[351].high[3] = 2.9563009818e-09;
		asali_->thermo_[351].high[4] = -2.2769920715e-13;
		asali_->thermo_[351].high[5] = -8.9660527344e+03;
		asali_->thermo_[351].high[6] = -7.6271125793e+01;

		asali_->thermo_[351].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[351].low[0] = -5.5865015984e+00;
		asali_->thermo_[351].low[1] = 9.9216125906e-02;
		asali_->thermo_[351].low[2] = -7.2660594014e-05;
		asali_->thermo_[351].low[3] = 2.6865322411e-08;
		asali_->thermo_[351].low[4] = -3.9634840548e-12;
		asali_->thermo_[351].low[5] = -1.1315444336e+03;
		asali_->thermo_[351].low[6] = 5.3351440430e+01;
		
		asali_->thermo_[352].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[352].name,"RC9H11");

		asali_->thermo_[352].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[352].high[0] = 1.9477767944e+01;
		asali_->thermo_[352].high[1] = 3.5255890340e-02;
		asali_->thermo_[352].high[2] = -1.4249322703e-05;
		asali_->thermo_[352].high[3] = 2.7605835395e-09;
		asali_->thermo_[352].high[4] = -2.1304517124e-13;
		asali_->thermo_[352].high[5] = 6.1093881836e+03;
		asali_->thermo_[352].high[6] = -7.9471374512e+01;

		asali_->thermo_[352].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[352].low[0] = -1.8352299929e+00;
		asali_->thermo_[352].low[1] = 8.2618109882e-02;
		asali_->thermo_[352].low[2] = -5.3717834817e-05;
		asali_->thermo_[352].low[3] = 1.7378551931e-08;
		asali_->thermo_[352].low[4] = -2.2433183783e-12;
		asali_->thermo_[352].low[5] = 1.3782067383e+04;
		asali_->thermo_[352].low[6] = 3.5879013062e+01;
		
		asali_->thermo_[353].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[353].name,"C6H5OCH3");

		asali_->thermo_[353].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[353].high[0] = 1.2508513451e+01;
		asali_->thermo_[353].high[1] = 3.4990612417e-02;
		asali_->thermo_[353].high[2] = -1.6309608327e-05;
		asali_->thermo_[353].high[3] = 3.6483682742e-09;
		asali_->thermo_[353].high[4] = -3.1998839342e-13;
		asali_->thermo_[353].high[5] = -1.5203879883e+04;
		asali_->thermo_[353].high[6] = -4.2040649414e+01;

		asali_->thermo_[353].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[353].low[0] = -5.2946157455e+00;
		asali_->thermo_[353].low[1] = 8.6593888700e-02;
		asali_->thermo_[353].low[2] = -7.2400122008e-05;
		asali_->thermo_[353].low[3] = 3.0745233914e-08;
		asali_->thermo_[353].low[4] = -5.2288412315e-12;
		asali_->thermo_[353].low[5] = -1.0290215820e+04;
		asali_->thermo_[353].low[6] = 4.9583251953e+01;
		
		asali_->thermo_[354].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->thermo_[354].name,"MB");

		asali_->thermo_[354].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[354].high[0] = 1.2428421974e+01;
		asali_->thermo_[354].high[1] = 3.5713344812e-02;
		asali_->thermo_[354].high[2] = -1.6159288862e-05;
		asali_->thermo_[354].high[3] = 3.5209410942e-09;
		asali_->thermo_[354].high[4] = -3.0269352563e-13;
		asali_->thermo_[354].high[5] = -6.0770234375e+04;
		asali_->thermo_[354].high[6] = -3.6522068024e+01;

		asali_->thermo_[354].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[354].low[0] = 2.7783131599e+00;
		asali_->thermo_[354].low[1] = 5.7158030570e-02;
		asali_->thermo_[354].low[2] = -3.4029861126e-05;
		asali_->thermo_[354].low[3] = 1.0139671325e-08;
		asali_->thermo_[354].low[4] = -1.2219616595e-12;
		asali_->thermo_[354].low[5] = -5.7296195312e+04;
		asali_->thermo_[354].low[6] = 1.5706335068e+01;
		
		asali_->thermo_[355].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[355].name,"RMBX");

		asali_->thermo_[355].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[355].high[0] = 1.5492469788e+01;
		asali_->thermo_[355].high[1] = 2.8079411015e-02;
		asali_->thermo_[355].high[2] = -1.2057324966e-05;
		asali_->thermo_[355].high[3] = 2.4932240716e-09;
		asali_->thermo_[355].high[4] = -2.0481272928e-13;
		asali_->thermo_[355].high[5] = -3.9720187500e+04;
		asali_->thermo_[355].high[6] = -5.4181045532e+01;

		asali_->thermo_[355].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[355].low[0] = 2.1357331276e+00;
		asali_->thermo_[355].low[1] = 5.7761047035e-02;
		asali_->thermo_[355].low[2] = -3.6792022001e-05;
		asali_->thermo_[355].low[3] = 1.1654223364e-08;
		asali_->thermo_[355].low[4] = -1.4771737436e-12;
		asali_->thermo_[355].low[5] = -3.4911761719e+04;
		asali_->thermo_[355].low[6] = 1.8108402252e+01;
		
		asali_->thermo_[356].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[356].name,"MCROT");

		asali_->thermo_[356].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[356].high[0] = 1.1373885155e+01;
		asali_->thermo_[356].high[1] = 2.6131803170e-02;
		asali_->thermo_[356].high[2] = -8.7485514086e-06;
		asali_->thermo_[356].high[3] = 1.3583151270e-09;
		asali_->thermo_[356].high[4] = -8.0017501685e-14;
		asali_->thermo_[356].high[5] = -4.6306214844e+04;
		asali_->thermo_[356].high[6] = -2.5480146408e+01;

		asali_->thermo_[356].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[356].low[0] = 2.7206471562e-01;
		asali_->thermo_[356].low[1] = 6.1098165810e-02;
		asali_->thermo_[356].low[2] = -5.0047405239e-05;
		asali_->thermo_[356].low[3] = 2.3037502572e-08;
		asali_->thermo_[356].low[4] = -4.3475743838e-12;
		asali_->thermo_[356].low[5] = -4.3486351562e+04;
		asali_->thermo_[356].low[6] = 3.0733240128e+01;
		
		asali_->thermo_[357].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[357].name,"MACRIL");

		asali_->thermo_[357].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[357].high[0] = 9.1403417587e+00;
		asali_->thermo_[357].high[1] = 2.1087048575e-02;
		asali_->thermo_[357].high[2] = -7.4225922617e-06;
		asali_->thermo_[357].high[3] = 1.2504433045e-09;
		asali_->thermo_[357].high[4] = -8.3306408646e-14;
		asali_->thermo_[357].high[5] = -4.1282777344e+04;
		asali_->thermo_[357].high[6] = -1.5026798248e+01;

		asali_->thermo_[357].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[357].low[0] = -1.1313576698e+00;
		asali_->thermo_[357].low[1] = 5.8102183044e-02;
		asali_->thermo_[357].low[2] = -5.7443041442e-05;
		asali_->thermo_[357].low[3] = 3.1292756830e-08;
		asali_->thermo_[357].low[4] = -6.8495929414e-12;
		asali_->thermo_[357].low[5] = -3.9002460938e+04;
		asali_->thermo_[357].low[6] = 3.5600170135e+01;
		
		asali_->thermo_[358].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[358].name,"RMP3");

		asali_->thermo_[358].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[358].high[0] = 9.4673118591e+00;
		asali_->thermo_[358].high[1] = 2.7890339494e-02;
		asali_->thermo_[358].high[2] = -1.3107985978e-05;
		asali_->thermo_[358].high[3] = 2.9499831466e-09;
		asali_->thermo_[358].high[4] = -2.6007554400e-13;
		asali_->thermo_[358].high[5] = -3.1826455078e+04;
		asali_->thermo_[358].high[6] = -1.9308130264e+01;

		asali_->thermo_[358].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[358].low[0] = 3.6747286320e+00;
		asali_->thermo_[358].low[1] = 4.0762744844e-02;
		asali_->thermo_[358].low[2] = -2.3834991225e-05;
		asali_->thermo_[358].low[3] = 6.9229479926e-09;
		asali_->thermo_[358].low[4] = -8.1187622814e-13;
		asali_->thermo_[358].low[5] = -2.9741125000e+04;
		asali_->thermo_[358].low[6] = 1.2042536736e+01;
		
		asali_->thermo_[359].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[359].name,"CH3OCO");

		asali_->thermo_[359].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[359].high[0] = 2.5752732754e+00;
		asali_->thermo_[359].high[1] = 2.1116668358e-02;
		asali_->thermo_[359].high[2] = -1.2014982531e-05;
		asali_->thermo_[359].high[3] = 3.1484939100e-09;
		asali_->thermo_[359].high[4] = -3.1141102609e-13;
		asali_->thermo_[359].high[5] = -2.0708550781e+04;
		asali_->thermo_[359].high[6] = 1.5911768913e+01;

		asali_->thermo_[359].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[359].low[0] = 4.6612687111e+00;
		asali_->thermo_[359].low[1] = 9.6865557134e-03;
		asali_->thermo_[359].low[2] = 1.1471553080e-05;
		asali_->thermo_[359].low[3] = -1.8300395865e-08;
		asali_->thermo_[359].low[4] = 7.0340994314e-12;
		asali_->thermo_[359].low[5] = -2.1013105469e+04;
		asali_->thermo_[359].low[6] = 6.5045309067e+00;
		
		asali_->thermo_[360].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[360].name,"ETMB583");

		asali_->thermo_[360].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[360].high[0] = 1.7563035965e+01;
		asali_->thermo_[360].high[1] = 2.3538386449e-02;
		asali_->thermo_[360].high[2] = -7.5691318671e-06;
		asali_->thermo_[360].high[3] = 1.0583746102e-09;
		asali_->thermo_[360].high[4] = -4.9569828358e-14;
		asali_->thermo_[360].high[5] = -6.2736964844e+04;
		asali_->thermo_[360].high[6] = -6.1505424500e+01;

		asali_->thermo_[360].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[360].low[0] = -4.6016569138e+00;
		asali_->thermo_[360].low[1] = 9.3348443508e-02;
		asali_->thermo_[360].low[2] = -9.0021952929e-05;
		asali_->thermo_[360].low[3] = 4.4340698224e-08;
		asali_->thermo_[360].low[4] = -8.5697117805e-12;
		asali_->thermo_[360].low[5] = -5.7107132812e+04;
		asali_->thermo_[360].low[6] = 5.0724143982e+01;
		
		asali_->thermo_[361].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[361].name,"KEHYMB");

		asali_->thermo_[361].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[361].high[0] = 1.2858585358e+01;
		asali_->thermo_[361].high[1] = 3.0526770279e-02;
		asali_->thermo_[361].high[2] = -1.0526377991e-05;
		asali_->thermo_[361].high[3] = 1.7028773946e-09;
		asali_->thermo_[361].high[4] = -1.0641127871e-13;
		asali_->thermo_[361].high[5] = -6.0491527344e+04;
		asali_->thermo_[361].high[6] = -3.4245948792e+01;

		asali_->thermo_[361].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[361].low[0] = -2.2835216522e+00;
		asali_->thermo_[361].low[1] = 8.1000462174e-02;
		asali_->thermo_[361].low[2] = -7.3618488386e-05;
		asali_->thermo_[361].low[3] = 3.6754052246e-08;
		asali_->thermo_[361].low[4] = -7.4087394206e-12;
		asali_->thermo_[361].low[5] = -5.6857421875e+04;
		asali_->thermo_[361].low[6] = 4.1566699982e+01;
		
		asali_->thermo_[362].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[362].name,"DIBZFUR");

		asali_->thermo_[362].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[362].high[0] = 2.4952526093e+01;
		asali_->thermo_[362].high[1] = 3.2473072410e-02;
		asali_->thermo_[362].high[2] = -1.1545937014e-05;
		asali_->thermo_[362].high[3] = 1.7967904942e-09;
		asali_->thermo_[362].high[4] = -9.9783367875e-14;
		asali_->thermo_[362].high[5] = -5.3075366211e+03;
		asali_->thermo_[362].high[6] = -1.1335589600e+02;

		asali_->thermo_[362].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[362].low[0] = -1.1697090149e+01;
		asali_->thermo_[362].low[1] = 1.3644361496e-01;
		asali_->thermo_[362].low[2] = -1.2215289462e-04;
		asali_->thermo_[362].low[3] = 5.4093224122e-08;
		asali_->thermo_[362].low[4] = -9.3722009320e-12;
		asali_->thermo_[362].low[5] = 5.0276552734e+03;
		asali_->thermo_[362].low[6] = 7.6049751282e+01;
		
		asali_->thermo_[363].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[363].name,"DIFENET");

		asali_->thermo_[363].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[363].high[0] = 1.7154809952e+01;
		asali_->thermo_[363].high[1] = 5.2537418902e-02;
		asali_->thermo_[363].high[2] = -2.4565722924e-05;
		asali_->thermo_[363].high[3] = 5.5824478373e-09;
		asali_->thermo_[363].high[4] = -4.9940992097e-13;
		asali_->thermo_[363].high[5] = -3.2970439453e+03;
		asali_->thermo_[363].high[6] = -6.4998565674e+01;

		asali_->thermo_[363].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[363].low[0] = -8.5745811462e+00;
		asali_->thermo_[363].low[1] = 1.2450774759e-01;
		asali_->thermo_[363].low[2] = -1.0005907097e-04;
		asali_->thermo_[363].low[3] = 4.0777482724e-08;
		asali_->thermo_[363].low[4] = -6.6523878420e-12;
		asali_->thermo_[363].low[5] = 4.0615620117e+03;
		asali_->thermo_[363].low[6] = 6.8333618164e+01;
		
		asali_->thermo_[364].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[364].name,"RMBOOX");

		asali_->thermo_[364].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[364].high[0] = 2.4655706406e+01;
		asali_->thermo_[364].high[1] = 1.6020324081e-02;
		asali_->thermo_[364].high[2] = -2.3301802230e-06;
		asali_->thermo_[364].high[3] = -2.0943279055e-10;
		asali_->thermo_[364].high[4] = 5.9625657818e-14;
		asali_->thermo_[364].high[5] = -5.8731886719e+04;
		asali_->thermo_[364].high[6] = -9.2819786072e+01;

		asali_->thermo_[364].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[364].low[0] = -3.0257754326e+00;
		asali_->thermo_[364].low[1] = 9.8039530218e-02;
		asali_->thermo_[364].low[2] = -9.3462629593e-05;
		asali_->thermo_[364].low[3] = 4.4794248311e-08;
		asali_->thermo_[364].low[4] = -8.2743889865e-12;
		asali_->thermo_[364].low[5] = -5.1257886719e+04;
		asali_->thermo_[364].low[6] = 4.9034706116e+01;
		
		asali_->thermo_[365].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[365].name,"QMBOOX");

		asali_->thermo_[365].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[365].high[0] = 2.4655706406e+01;
		asali_->thermo_[365].high[1] = 1.6020324081e-02;
		asali_->thermo_[365].high[2] = -2.3301802230e-06;
		asali_->thermo_[365].high[3] = -2.0943279055e-10;
		asali_->thermo_[365].high[4] = 5.9625657818e-14;
		asali_->thermo_[365].high[5] = -5.8731886719e+04;
		asali_->thermo_[365].high[6] = -9.2819786072e+01;

		asali_->thermo_[365].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[365].low[0] = -3.0257754326e+00;
		asali_->thermo_[365].low[1] = 9.8039530218e-02;
		asali_->thermo_[365].low[2] = -9.3462629593e-05;
		asali_->thermo_[365].low[3] = 4.4794248311e-08;
		asali_->thermo_[365].low[4] = -8.2743889865e-12;
		asali_->thermo_[365].low[5] = -5.1257886719e+04;
		asali_->thermo_[365].low[6] = 4.9034706116e+01;
		
		asali_->thermo_[366].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[366].name,"ZMBOOX");

		asali_->thermo_[366].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[366].high[0] = 2.9401693344e+01;
		asali_->thermo_[366].high[1] = 1.5734644607e-02;
		asali_->thermo_[366].high[2] = -2.1056566766e-06;
		asali_->thermo_[366].high[3] = -2.3031017371e-10;
		asali_->thermo_[366].high[4] = 5.8052866713e-14;
		asali_->thermo_[366].high[5] = -7.0363710938e+04;
		asali_->thermo_[366].high[6] = -1.0959683990e+02;

		asali_->thermo_[366].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[366].low[0] = -1.6657086611e+00;
		asali_->thermo_[366].low[1] = 1.1059694737e-01;
		asali_->thermo_[366].low[2] = -1.1072660709e-04;
		asali_->thermo_[366].low[3] = 5.5047529202e-08;
		asali_->thermo_[366].low[4] = -1.0491153085e-11;
		asali_->thermo_[366].low[5] = -6.2224050781e+04;
		asali_->thermo_[366].low[6] = 4.8674461365e+01;
		
		asali_->thermo_[367].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[367].name,"KHDECA");

		asali_->thermo_[367].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[367].high[0] = 1.1602241516e+01;
		asali_->thermo_[367].high[1] = 3.5730365664e-02;
		asali_->thermo_[367].high[2] = -1.3441588635e-05;
		asali_->thermo_[367].high[3] = 2.5043744856e-09;
		asali_->thermo_[367].high[4] = -1.8951028626e-13;
		asali_->thermo_[367].high[5] = -3.6382156250e+04;
		asali_->thermo_[367].high[6] = -4.9853294373e+01;

		asali_->thermo_[367].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[367].low[0] = -8.0240211487e+00;
		asali_->thermo_[367].low[1] = 8.9500948787e-02;
		asali_->thermo_[367].low[2] = -6.8685338192e-05;
		asali_->thermo_[367].low[3] = 2.7729832652e-08;
		asali_->thermo_[367].low[4] = -4.5089379279e-12;
		asali_->thermo_[367].low[5] = -3.0651287109e+04;
		asali_->thermo_[367].low[6] = 5.2259372711e+01;
		
		asali_->thermo_[368].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[368].name,"QDECOOH");

		asali_->thermo_[368].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[368].high[0] = 1.7237916946e+01;
		asali_->thermo_[368].high[1] = 3.7697874010e-02;
		asali_->thermo_[368].high[2] = -1.6633131963e-05;
		asali_->thermo_[368].high[3] = 3.5455518521e-09;
		asali_->thermo_[368].high[4] = -3.0028499761e-13;
		asali_->thermo_[368].high[5] = -1.9202748047e+04;
		asali_->thermo_[368].high[6] = -7.0167648315e+01;

		asali_->thermo_[368].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[368].low[0] = -6.0036754608e+00;
		asali_->thermo_[368].low[1] = 8.9345857501e-02;
		asali_->thermo_[368].low[2] = -5.9673118812e-05;
		asali_->thermo_[368].low[3] = 1.9486288139e-08;
		asali_->thermo_[368].low[4] = -2.5142761137e-12;
		asali_->thermo_[368].low[5] = -1.0835773438e+04;
		asali_->thermo_[368].low[6] = 5.5620700836e+01;
		
		asali_->thermo_[369].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[369].name,"RDECOO");

		asali_->thermo_[369].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[369].high[0] = 1.7237916946e+01;
		asali_->thermo_[369].high[1] = 3.7697874010e-02;
		asali_->thermo_[369].high[2] = -1.6633131963e-05;
		asali_->thermo_[369].high[3] = 3.5455518521e-09;
		asali_->thermo_[369].high[4] = -3.0028499761e-13;
		asali_->thermo_[369].high[5] = -1.9202748047e+04;
		asali_->thermo_[369].high[6] = -7.0167648315e+01;

		asali_->thermo_[369].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[369].low[0] = -6.0036754608e+00;
		asali_->thermo_[369].low[1] = 8.9345857501e-02;
		asali_->thermo_[369].low[2] = -5.9673118812e-05;
		asali_->thermo_[369].low[3] = 1.9486288139e-08;
		asali_->thermo_[369].low[4] = -2.5142761137e-12;
		asali_->thermo_[369].low[5] = -1.0835773438e+04;
		asali_->thermo_[369].low[6] = 5.5620700836e+01;
		
		asali_->thermo_[370].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[370].name,"ZDECA");

		asali_->thermo_[370].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[370].high[0] = 1.7237916946e+01;
		asali_->thermo_[370].high[1] = 3.7697874010e-02;
		asali_->thermo_[370].high[2] = -1.6633131963e-05;
		asali_->thermo_[370].high[3] = 3.5455518521e-09;
		asali_->thermo_[370].high[4] = -3.0028499761e-13;
		asali_->thermo_[370].high[5] = -1.9202748047e+04;
		asali_->thermo_[370].high[6] = -7.0167648315e+01;

		asali_->thermo_[370].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[370].low[0] = -6.0036754608e+00;
		asali_->thermo_[370].low[1] = 8.9345857501e-02;
		asali_->thermo_[370].low[2] = -5.9673118812e-05;
		asali_->thermo_[370].low[3] = 1.9486288139e-08;
		asali_->thermo_[370].low[4] = -2.5142761137e-12;
		asali_->thermo_[370].low[5] = -1.0835773438e+04;
		asali_->thermo_[370].low[6] = 5.5620700836e+01;
		
		asali_->thermo_[371].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[371].name,"RMCROTA");

		asali_->thermo_[371].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[371].high[0] = 1.5718928337e+01;
		asali_->thermo_[371].high[1] = 1.6946334392e-02;
		asali_->thermo_[371].high[2] = -4.4670823627e-06;
		asali_->thermo_[371].high[3] = 5.6663129744e-10;
		asali_->thermo_[371].high[4] = -2.7662149576e-14;
		asali_->thermo_[371].high[5] = -3.2321958984e+04;
		asali_->thermo_[371].high[6] = -4.9450874329e+01;

		asali_->thermo_[371].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[371].low[0] = 1.4758147299e-01;
		asali_->thermo_[371].low[1] = 6.0502547771e-02;
		asali_->thermo_[371].low[2] = -5.0155420467e-05;
		asali_->thermo_[371].low[3] = 2.1866554789e-08;
		asali_->thermo_[371].low[4] = -3.7514249519e-12;
		asali_->thermo_[371].low[5] = -2.7868552734e+04;
		asali_->thermo_[371].low[6] = 3.1241346359e+01;
		
		asali_->thermo_[372].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->thermo_[372].name,"MD");

		asali_->thermo_[372].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[372].high[0] = 3.3294292450e+01;
		asali_->thermo_[372].high[1] = 6.0227803886e-02;
		asali_->thermo_[372].high[2] = -2.4343371479e-05;
		asali_->thermo_[372].high[3] = 4.7752344301e-09;
		asali_->thermo_[372].high[4] = -3.7562986575e-13;
		asali_->thermo_[372].high[5] = -8.6153820312e+04;
		asali_->thermo_[372].high[6] = -1.4050852966e+02;

		asali_->thermo_[372].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[372].low[0] = 1.4026327133e+00;
		asali_->thermo_[372].low[1] = 1.3109815121e-01;
		asali_->thermo_[372].low[2] = -8.3401995653e-05;
		asali_->thermo_[372].low[3] = 2.6648798723e-08;
		asali_->thermo_[372].low[4] = -3.4136250684e-12;
		asali_->thermo_[372].low[5] = -7.4672820312e+04;
		asali_->thermo_[372].low[6] = 3.2095775604e+01;
		
		asali_->thermo_[373].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[373].name,"RMDX");

		asali_->thermo_[373].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[373].high[0] = 2.5162086487e+01;
		asali_->thermo_[373].high[1] = 7.1415461600e-02;
		asali_->thermo_[373].high[2] = -3.2825097151e-05;
		asali_->thermo_[373].high[3] = 7.2750201419e-09;
		asali_->thermo_[373].high[4] = -6.3522272295e-13;
		asali_->thermo_[373].high[5] = -5.9598726562e+04;
		asali_->thermo_[373].high[6] = -9.2357261658e+01;

		asali_->thermo_[373].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[373].low[0] = 1.8544001579e+00;
		asali_->thermo_[373].low[1] = 1.2321031839e-01;
		asali_->thermo_[373].low[2] = -7.5987481978e-05;
		asali_->thermo_[373].low[3] = 2.3261087279e-08;
		asali_->thermo_[373].low[4] = -2.8555098824e-12;
		asali_->thermo_[373].low[5] = -5.1207957031e+04;
		asali_->thermo_[373].low[6] = 3.3788803101e+01;
		
		asali_->thermo_[374].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[374].name,"CH3OCHO");

		asali_->thermo_[374].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[374].high[0] = 2.1476974487e+00;
		asali_->thermo_[374].high[1] = 2.4674052373e-02;
		asali_->thermo_[374].high[2] = -1.3523809685e-05;
		asali_->thermo_[374].high[3] = 3.4478206956e-09;
		asali_->thermo_[374].high[4] = -3.3498047001e-13;
		asali_->thermo_[374].high[5] = -4.4037261719e+04;
		asali_->thermo_[374].high[6] = 1.6902463913e+01;

		asali_->thermo_[374].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[374].low[0] = 3.5119233131e+00;
		asali_->thermo_[374].low[1] = 1.6878476366e-02;
		asali_->thermo_[374].low[2] = 3.1809984193e-06;
		asali_->thermo_[374].low[3] = -1.2461519816e-08;
		asali_->thermo_[374].low[4] = 5.3469268943e-12;
		asali_->thermo_[374].low[5] = -4.4228253906e+04;
		asali_->thermo_[374].low[6] = 1.0807448387e+01;
		
		asali_->thermo_[375].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[375].name,"ETEROMD");

		asali_->thermo_[375].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[375].high[0] = 4.1424922943e+01;
		asali_->thermo_[375].high[1] = 4.5112203807e-02;
		asali_->thermo_[375].high[2] = -1.5653009541e-05;
		asali_->thermo_[375].high[3] = 2.4921407160e-09;
		asali_->thermo_[375].high[4] = -1.5032473964e-13;
		asali_->thermo_[375].high[5] = -8.9558125000e+04;
		asali_->thermo_[375].high[6] = -1.8429653931e+02;

		asali_->thermo_[375].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[375].low[0] = -1.2432796508e-01;
		asali_->thermo_[375].low[1] = 1.3954231143e-01;
		asali_->thermo_[375].low[2] = -9.6133218904e-05;
		asali_->thermo_[375].low[3] = 3.2977069964e-08;
		asali_->thermo_[375].low[4] = -4.4805699949e-12;
		asali_->thermo_[375].low[5] = -7.4932789062e+04;
		asali_->thermo_[375].low[6] = 3.9642929077e+01;
		
		asali_->thermo_[376].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[376].name,"MDKETO");

		asali_->thermo_[376].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[376].high[0] = 2.9841186523e+01;
		asali_->thermo_[376].high[1] = 7.1659572423e-02;
		asali_->thermo_[376].high[2] = -3.1259558455e-05;
		asali_->thermo_[376].high[3] = 6.7120460301e-09;
		asali_->thermo_[376].high[4] = -5.7352213256e-13;
		asali_->thermo_[376].high[5] = -1.0820734375e+05;
		asali_->thermo_[376].high[6] = -1.0778404236e+02;

		asali_->thermo_[376].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[376].low[0] = 3.7229626179e+00;
		asali_->thermo_[376].low[1] = 1.4523203671e-01;
		asali_->thermo_[376].low[2] = -1.0897695029e-04;
		asali_->thermo_[376].low[3] = 4.3199083422e-08;
		asali_->thermo_[376].low[4] = -6.9972964055e-12;
		asali_->thermo_[376].low[5] = -1.0078976562e+05;
		asali_->thermo_[376].low[6] = 2.7379829407e+01;
		
		asali_->thermo_[377].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[377].name,"C7H15COCHO");

		asali_->thermo_[377].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[377].high[0] = 3.0205099106e+01;
		asali_->thermo_[377].high[1] = 3.8410760462e-02;
		asali_->thermo_[377].high[2] = -1.3045411833e-05;
		asali_->thermo_[377].high[3] = 2.0288168923e-09;
		asali_->thermo_[377].high[4] = -1.1934835173e-13;
		asali_->thermo_[377].high[5] = -6.6795648438e+04;
		asali_->thermo_[377].high[6] = -1.2574704742e+02;

		asali_->thermo_[377].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[377].low[0] = 3.5904160142e-01;
		asali_->thermo_[377].low[1] = 1.0548055172e-01;
		asali_->thermo_[377].low[2] = -6.9564899604e-05;
		asali_->thermo_[377].low[3] = 2.3197163301e-08;
		asali_->thermo_[377].low[4] = -3.0924308253e-12;
		asali_->thermo_[377].low[5] = -5.6170449219e+04;
		asali_->thermo_[377].low[6] = 3.5452556610e+01;
		
		asali_->thermo_[378].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[378].name,"RMDOOX");

		asali_->thermo_[378].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[378].high[0] = 3.9689403534e+01;
		asali_->thermo_[378].high[1] = 5.3822506219e-02;
		asali_->thermo_[378].high[2] = -2.0277500880e-05;
		asali_->thermo_[378].high[3] = 3.6479388399e-09;
		asali_->thermo_[378].high[4] = -2.6121634153e-13;
		asali_->thermo_[378].high[5] = -8.3847234375e+04;
		asali_->thermo_[378].high[6] = -1.6754673767e+02;

		asali_->thermo_[378].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[378].low[0] = 4.7046675682e+00;
		asali_->thermo_[378].low[1] = 1.3156636059e-01;
		asali_->thermo_[378].low[2] = -8.5064049927e-05;
		asali_->thermo_[378].low[3] = 2.7642956368e-08;
		asali_->thermo_[378].low[4] = -3.5938576334e-12;
		asali_->thermo_[378].low[5] = -7.1252726562e+04;
		asali_->thermo_[378].low[6] = 2.1797952652e+01;
		
		asali_->thermo_[379].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[379].name,"QMDOOH");

		asali_->thermo_[379].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[379].high[0] = 3.7768177032e+01;
		asali_->thermo_[379].high[1] = 6.0558483005e-02;
		asali_->thermo_[379].high[2] = -2.6637733754e-05;
		asali_->thermo_[379].high[3] = 5.6313922414e-09;
		asali_->thermo_[379].high[4] = -4.7138362007e-13;
		asali_->thermo_[379].high[5] = -7.6826328125e+04;
		asali_->thermo_[379].high[6] = -1.5514337158e+02;

		asali_->thermo_[379].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[379].low[0] = 4.1286687851e+00;
		asali_->thermo_[379].low[1] = 1.3531294465e-01;
		asali_->thermo_[379].low[2] = -8.8933120423e-05;
		asali_->thermo_[379].low[3] = 2.8703759369e-08;
		asali_->thermo_[379].low[4] = -3.6758790456e-12;
		asali_->thermo_[379].low[5] = -6.4716105469e+04;
		asali_->thermo_[379].low[6] = 2.6920671463e+01;
		
		asali_->thermo_[380].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[380].name,"ZMDOOH");

		asali_->thermo_[380].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[380].high[0] = 4.8960113525e+01;
		asali_->thermo_[380].high[1] = 4.6964660287e-02;
		asali_->thermo_[380].high[2] = -1.6147776478e-05;
		asali_->thermo_[380].high[3] = 2.5875734888e-09;
		asali_->thermo_[380].high[4] = -1.5808002422e-13;
		asali_->thermo_[380].high[5] = -9.9631367188e+04;
		asali_->thermo_[380].high[6] = -2.1122653198e+02;

		asali_->thermo_[380].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[380].low[0] = 6.9149503708e+00;
		asali_->thermo_[380].low[1] = 1.4144816995e-01;
		asali_->thermo_[380].low[2] = -9.5768715255e-05;
		asali_->thermo_[380].low[3] = 3.2408149053e-08;
		asali_->thermo_[380].low[4] = -4.3463631132e-12;
		asali_->thermo_[380].low[5] = -8.4663289062e+04;
		asali_->thermo_[380].low[6] = 1.5860872269e+01;
		
		asali_->thermo_[381].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[381].name,"U2ME10");

		asali_->thermo_[381].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[381].high[0] = 2.3678865433e+01;
		asali_->thermo_[381].high[1] = 6.4063206315e-02;
		asali_->thermo_[381].high[2] = -2.7602138289e-05;
		asali_->thermo_[381].high[3] = 5.8327036534e-09;
		asali_->thermo_[381].high[4] = -4.9195267001e-13;
		asali_->thermo_[381].high[5] = -5.3911859375e+04;
		asali_->thermo_[381].high[6] = -8.5754867554e+01;

		asali_->thermo_[381].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[381].low[0] = 3.2283934951e-01;
		asali_->thermo_[381].low[1] = 1.2894105911e-01;
		asali_->thermo_[381].low[2] = -9.5183233498e-05;
		asali_->thermo_[381].low[3] = 3.7120248209e-08;
		asali_->thermo_[381].low[4] = -5.9238178599e-12;
		asali_->thermo_[381].low[5] = -4.7185324219e+04;
		asali_->thermo_[381].low[6] = 3.5441070557e+01;
		
		asali_->thermo_[382].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[382].name,"UME10");

		asali_->thermo_[382].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[382].high[0] = 3.4856674194e+01;
		asali_->thermo_[382].high[1] = 5.0863161683e-02;
		asali_->thermo_[382].high[2] = -1.9002740373e-05;
		asali_->thermo_[382].high[3] = 3.3943210465e-09;
		asali_->thermo_[382].high[4] = -2.4166405639e-13;
		asali_->thermo_[382].high[5] = -7.2733460938e+04;
		asali_->thermo_[382].high[6] = -1.4847738647e+02;

		asali_->thermo_[382].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[382].low[0] = 1.0870003700e+00;
		asali_->thermo_[382].low[1] = 1.2590688467e-01;
		asali_->thermo_[382].low[2] = -8.1539175881e-05;
		asali_->thermo_[382].low[3] = 2.6555962762e-08;
		asali_->thermo_[382].low[4] = -3.4585587432e-12;
		asali_->thermo_[382].low[5] = -6.0576378906e+04;
		asali_->thermo_[382].low[6] = 3.4291122437e+01;
		
		asali_->thermo_[383].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[383].name,"UME7");

		asali_->thermo_[383].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[383].high[0] = 2.5847383499e+01;
		asali_->thermo_[383].high[1] = 3.6211334169e-02;
		asali_->thermo_[383].high[2] = -1.3312403098e-05;
		asali_->thermo_[383].high[3] = 2.3293753593e-09;
		asali_->thermo_[383].high[4] = -1.6194456800e-13;
		asali_->thermo_[383].high[5] = -5.9127417969e+04;
		asali_->thermo_[383].high[6] = -1.0396006775e+02;

		asali_->thermo_[383].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[383].low[0] = 2.2197780609e+00;
		asali_->thermo_[383].low[1] = 8.8717125356e-02;
		asali_->thermo_[383].low[2] = -5.7067230955e-05;
		asali_->thermo_[383].low[3] = 1.8534866086e-08;
		asali_->thermo_[383].low[4] = -2.4127071868e-12;
		asali_->thermo_[383].low[5] = -5.0621480469e+04;
		asali_->thermo_[383].low[6] = 2.3917469025e+01;
		
		asali_->thermo_[384].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[384].name,"C12H22");

		asali_->thermo_[384].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[384].high[0] = 3.6068786621e+01;
		asali_->thermo_[384].high[1] = 4.9353178591e-02;
		asali_->thermo_[384].high[2] = -1.6893278371e-05;
		asali_->thermo_[384].high[3] = 2.6486688398e-09;
		asali_->thermo_[384].high[4] = -1.5693474081e-13;
		asali_->thermo_[384].high[5] = -2.2929115234e+04;
		asali_->thermo_[384].high[6] = -1.5868997192e+02;

		asali_->thermo_[384].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[384].low[0] = -2.7185525894e+00;
		asali_->thermo_[384].low[1] = 1.3750621676e-01;
		asali_->thermo_[384].low[2] = -9.2023707111e-05;
		asali_->thermo_[384].low[3] = 3.1107166620e-08;
		asali_->thermo_[384].low[4] = -4.1993348902e-12;
		asali_->thermo_[384].low[5] = -9.2759716797e+03;
		asali_->thermo_[384].low[6] = 5.0363533020e+01;
		
		asali_->thermo_[385].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[385].name,"DCYC5");

		asali_->thermo_[385].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[385].high[0] = 2.7011030197e+01;
		asali_->thermo_[385].high[1] = 4.6874817461e-02;
		asali_->thermo_[385].high[2] = -1.6389549273e-05;
		asali_->thermo_[385].high[3] = 2.6256368191e-09;
		asali_->thermo_[385].high[4] = -1.5978972973e-13;
		asali_->thermo_[385].high[5] = -3.7922628906e+04;
		asali_->thermo_[385].high[6] = -1.3516773987e+02;

		asali_->thermo_[385].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[385].low[0] = -1.4587078094e+01;
		asali_->thermo_[385].low[1] = 1.4195621014e-01;
		asali_->thermo_[385].low[2] = -9.7887881566e-05;
		asali_->thermo_[385].low[3] = 3.3672620248e-08;
		asali_->thermo_[385].low[4] = -4.5950730200e-12;
		asali_->thermo_[385].low[5] = -2.3363291016e+04;
		asali_->thermo_[385].low[6] = 8.8798034668e+01;
		
		asali_->thermo_[386].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[386].name,"UME16");

		asali_->thermo_[386].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[386].high[0] = 4.5233970642e+01;
		asali_->thermo_[386].high[1] = 8.6515232921e-02;
		asali_->thermo_[386].high[2] = -3.0515333492e-05;
		asali_->thermo_[386].high[3] = 4.6067438753e-09;
		asali_->thermo_[386].high[4] = -2.2675221076e-13;
		asali_->thermo_[386].high[5] = -9.2204687500e+04;
		asali_->thermo_[386].high[6] = -1.9402688599e+02;

		asali_->thermo_[386].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[386].low[0] = -6.3489584923e+00;
		asali_->thermo_[386].low[1] = 2.1710492671e-01;
		asali_->thermo_[386].low[2] = -1.5449289640e-04;
		asali_->thermo_[386].low[3] = 5.6917947688e-08;
		asali_->thermo_[386].low[4] = -8.5038417280e-12;
		asali_->thermo_[386].low[5] = -7.5904476562e+04;
		asali_->thermo_[386].low[6] = 7.8426231384e+01;
		
		asali_->thermo_[387].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[387].name,"ETEROMPA");

		asali_->thermo_[387].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[387].high[0] = 4.3212669373e+01;
		asali_->thermo_[387].high[1] = 9.1725647449e-02;
		asali_->thermo_[387].high[2] = -3.0278810300e-05;
		asali_->thermo_[387].high[3] = 4.5388248715e-09;
		asali_->thermo_[387].high[4] = -2.5004502050e-13;
		asali_->thermo_[387].high[5] = -1.0611774219e+05;
		asali_->thermo_[387].high[6] = -1.7561761475e+02;

		asali_->thermo_[387].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[387].low[0] = -8.7301168442e+00;
		asali_->thermo_[387].low[1] = 2.5032958388e-01;
		asali_->thermo_[387].low[2] = -2.1188636310e-04;
		asali_->thermo_[387].low[3] = 9.6959972495e-08;
		asali_->thermo_[387].low[4] = -1.7887668777e-11;
		asali_->thermo_[387].low[5] = -9.2508734375e+04;
		asali_->thermo_[387].low[6] = 8.9002258301e+01;
		
		asali_->thermo_[388].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[388].name,"MPA");

		asali_->thermo_[388].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[388].high[0] = 4.7634777069e+01;
		asali_->thermo_[388].high[1] = 8.9136324823e-02;
		asali_->thermo_[388].high[2] = -3.1408093491e-05;
		asali_->thermo_[388].high[3] = 4.7391606195e-09;
		asali_->thermo_[388].high[4] = -2.3337939654e-13;
		asali_->thermo_[388].high[5] = -1.0840490625e+05;
		asali_->thermo_[388].high[6] = -2.1380044556e+02;

		asali_->thermo_[388].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[388].low[0] = -6.7121291161e+00;
		asali_->thermo_[388].low[1] = 2.2759978473e-01;
		asali_->thermo_[388].low[2] = -1.6369801597e-04;
		asali_->thermo_[388].low[3] = 6.0913222910e-08;
		asali_->thermo_[388].low[4] = -9.1782944092e-12;
		asali_->thermo_[388].low[5] = -9.1339976562e+04;
		asali_->thermo_[388].low[6] = 7.2906517029e+01;
		
		asali_->thermo_[389].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[389].name,"KHMLIN1");

		asali_->thermo_[389].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[389].high[0] = 6.1894199371e+01;
		asali_->thermo_[389].high[1] = 8.2299470901e-02;
		asali_->thermo_[389].high[2] = -3.1018065783e-05;
		asali_->thermo_[389].high[3] = 5.3891304752e-09;
		asali_->thermo_[389].high[4] = -3.6260686294e-13;
		asali_->thermo_[389].high[5] = -9.7997468750e+04;
		asali_->thermo_[389].high[6] = -2.7227749634e+02;

		asali_->thermo_[389].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[389].low[0] = -3.0926873684e+00;
		asali_->thermo_[389].low[1] = 2.3611459136e-01;
		asali_->thermo_[389].low[2] = -1.6754036187e-04;
		asali_->thermo_[389].low[3] = 5.9244076311e-08;
		asali_->thermo_[389].low[4] = -8.3293146685e-12;
		asali_->thermo_[389].low[5] = -7.6031898438e+04;
		asali_->thermo_[389].low[6] = 7.5347129822e+01;
		
		asali_->thermo_[390].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[390].name,"MLIN1");

		asali_->thermo_[390].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[390].high[0] = 6.0239627838e+01;
		asali_->thermo_[390].high[1] = 7.5894497335e-02;
		asali_->thermo_[390].high[2] = -2.5764524253e-05;
		asali_->thermo_[390].high[3] = 3.8344905029e-09;
		asali_->thermo_[390].high[4] = -2.0341818778e-13;
		asali_->thermo_[390].high[5] = -7.7446867188e+04;
		asali_->thermo_[390].high[6] = -2.7509683228e+02;

		asali_->thermo_[390].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[390].low[0] = -2.5350110531e+00;
		asali_->thermo_[390].low[1] = 2.1617302299e-01;
		asali_->thermo_[390].low[2] = -1.4331635612e-04;
		asali_->thermo_[390].low[3] = 4.7615433374e-08;
		asali_->thermo_[390].low[4] = -6.3180749695e-12;
		asali_->thermo_[390].low[5] = -5.4973546875e+04;
		asali_->thermo_[390].low[6] = 6.4302902222e+01;
		
		asali_->thermo_[391].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[391].name,"MLINO");

		asali_->thermo_[391].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[391].high[0] = 6.0595565796e+01;
		asali_->thermo_[391].high[1] = 8.0018505454e-02;
		asali_->thermo_[391].high[2] = -2.7221922210e-05;
		asali_->thermo_[391].high[3] = 4.0905798748e-09;
		asali_->thermo_[391].high[4] = -2.2203654117e-13;
		asali_->thermo_[391].high[5] = -9.1617539062e+04;
		asali_->thermo_[391].high[6] = -2.7606591797e+02;

		asali_->thermo_[391].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[391].low[0] = -1.2214274406e+00;
		asali_->thermo_[391].low[1] = 2.1738961339e-01;
		asali_->thermo_[391].low[2] = -1.4169783390e-04;
		asali_->thermo_[391].low[3] = 4.6489066818e-08;
		asali_->thermo_[391].low[4] = -6.1107152324e-12;
		asali_->thermo_[391].low[5] = -6.9363421875e+04;
		asali_->thermo_[391].low[6] = 5.8500568390e+01;
		
		asali_->thermo_[392].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[392].name,"MEOLE");

		asali_->thermo_[392].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[392].high[0] = 5.9943099976e+01;
		asali_->thermo_[392].high[1] = 8.5869856179e-02;
		asali_->thermo_[392].high[2] = -2.9767597880e-05;
		asali_->thermo_[392].high[3] = 4.6426795741e-09;
		asali_->thermo_[392].high[4] = -2.7002141842e-13;
		asali_->thermo_[392].high[5] = -1.0532385938e+05;
		asali_->thermo_[392].high[6] = -2.7132138062e+02;

		asali_->thermo_[392].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[392].low[0] = -2.4034261703e-02;
		asali_->thermo_[392].low[1] = 2.1913015842e-01;
		asali_->thermo_[392].low[2] = -1.4081785048e-04;
		asali_->thermo_[392].low[3] = 4.5772402757e-08;
		asali_->thermo_[392].low[4] = -5.9824827384e-12;
		asali_->thermo_[392].low[5] = -8.3735687500e+04;
		asali_->thermo_[392].low[6] = 5.3233268738e+01;
		
		asali_->thermo_[393].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[393].name,"MSTEA");

		asali_->thermo_[393].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[393].high[0] = 5.5752189636e+01;
		asali_->thermo_[393].high[1] = 9.4409286976e-02;
		asali_->thermo_[393].high[2] = -3.2119798561e-05;
		asali_->thermo_[393].high[3] = 4.6529664566e-09;
		asali_->thermo_[393].high[4] = -2.1292218206e-13;
		asali_->thermo_[393].high[5] = -1.1722583594e+05;
		asali_->thermo_[393].high[6] = -2.5457946777e+02;

		asali_->thermo_[393].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[393].low[0] = -7.5235357285e+00;
		asali_->thermo_[393].low[1] = 2.5359350443e-01;
		asali_->thermo_[393].low[2] = -1.8229358830e-04;
		asali_->thermo_[393].low[3] = 6.7618913135e-08;
		asali_->thermo_[393].low[4] = -1.0113228831e-11;
		asali_->thermo_[393].low[5] = -9.7104156250e+04;
		asali_->thermo_[393].low[6] = 8.0032440186e+01;
		
		asali_->thermo_[394].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[394].name,"RUME7");

		asali_->thermo_[394].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[394].high[0] = 1.8590343475e+01;
		asali_->thermo_[394].high[1] = 4.6319965273e-02;
		asali_->thermo_[394].high[2] = -2.1207633836e-05;
		asali_->thermo_[394].high[3] = 4.6791961417e-09;
		asali_->thermo_[394].high[4] = -4.0699466909e-13;
		asali_->thermo_[394].high[5] = -3.2918394531e+04;
		asali_->thermo_[394].high[6] = -6.0763782501e+01;

		asali_->thermo_[394].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[394].low[0] = 2.6615872383e+00;
		asali_->thermo_[394].low[1] = 8.1717200577e-02;
		asali_->thermo_[394].low[2] = -5.0705330068e-05;
		asali_->thermo_[394].low[3] = 1.5604268100e-08;
		asali_->thermo_[394].low[4] = -1.9243658316e-12;
		asali_->thermo_[394].low[5] = -2.7184044922e+04;
		asali_->thermo_[394].low[6] = 2.5445966721e+01;
		
		asali_->thermo_[395].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[395].name,"RME7");

		asali_->thermo_[395].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[395].high[0] = 2.4041038513e+01;
		asali_->thermo_[395].high[1] = 4.2605388910e-02;
		asali_->thermo_[395].high[2] = -1.7137199393e-05;
		asali_->thermo_[395].high[3] = 3.3444056413e-09;
		asali_->thermo_[395].high[4] = -2.6190974303e-13;
		asali_->thermo_[395].high[5] = -4.8992972656e+04;
		asali_->thermo_[395].high[6] = -9.2093185425e+01;

		asali_->thermo_[395].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[395].low[0] = 2.9389207363e+00;
		asali_->thermo_[395].low[1] = 8.9498989284e-02;
		asali_->thermo_[395].low[2] = -5.6215198128e-05;
		asali_->thermo_[395].low[3] = 1.7817738396e-08;
		asali_->thermo_[395].low[4] = -2.2720948387e-12;
		asali_->thermo_[395].low[5] = -4.1396210938e+04;
		asali_->thermo_[395].low[6] = 2.2115879059e+01;
		
		asali_->thermo_[396].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[396].name,"RUME10");

		asali_->thermo_[396].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[396].high[0] = 2.3591636658e+01;
		asali_->thermo_[396].high[1] = 6.5204173326e-02;
		asali_->thermo_[396].high[2] = -2.6846753826e-05;
		asali_->thermo_[396].high[3] = 5.4403495042e-09;
		asali_->thermo_[396].high[4] = -4.4286473902e-13;
		asali_->thermo_[396].high[5] = -3.5867269531e+04;
		asali_->thermo_[396].high[6] = -8.2743003845e+01;

		asali_->thermo_[396].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[396].low[0] = 1.6440081596e+00;
		asali_->thermo_[396].low[1] = 1.2574934959e-01;
		asali_->thermo_[396].low[2] = -8.9479704911e-05;
		asali_->thermo_[396].low[3] = 3.4237107371e-08;
		asali_->thermo_[396].low[4] = -5.4078230609e-12;
		asali_->thermo_[396].low[5] = -2.9502458984e+04;
		asali_->thermo_[396].low[6] = 3.1296558380e+01;
		
		asali_->thermo_[397].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[397].name,"RMPAX");

		asali_->thermo_[397].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[397].high[0] = 4.6599193573e+01;
		asali_->thermo_[397].high[1] = 8.7995857000e-02;
		asali_->thermo_[397].high[2] = -3.1181814848e-05;
		asali_->thermo_[397].high[3] = 4.7286703442e-09;
		asali_->thermo_[397].high[4] = -2.3413391993e-13;
		asali_->thermo_[397].high[5] = -8.8675054688e+04;
		asali_->thermo_[397].high[6] = -2.0346049500e+02;

		asali_->thermo_[397].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[397].low[0] = -5.5300140381e+00;
		asali_->thermo_[397].low[1] = 2.2080913186e-01;
		asali_->thermo_[397].low[2] = -1.5807346790e-04;
		asali_->thermo_[397].low[3] = 5.8610478249e-08;
		asali_->thermo_[397].low[4] = -8.8140397758e-12;
		asali_->thermo_[397].low[5] = -7.2306484375e+04;
		asali_->thermo_[397].low[6] = 7.1547027588e+01;
		
		asali_->thermo_[398].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[398].name,"QMPAOOH");

		asali_->thermo_[398].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[398].high[0] = 3.7768177032e+01;
		asali_->thermo_[398].high[1] = 6.0558483005e-02;
		asali_->thermo_[398].high[2] = -2.6637733754e-05;
		asali_->thermo_[398].high[3] = 5.6313922414e-09;
		asali_->thermo_[398].high[4] = -4.7138362007e-13;
		asali_->thermo_[398].high[5] = -7.6826328125e+04;
		asali_->thermo_[398].high[6] = -1.5514337158e+02;

		asali_->thermo_[398].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[398].low[0] = 4.1286687851e+00;
		asali_->thermo_[398].low[1] = 1.3531294465e-01;
		asali_->thermo_[398].low[2] = -8.8933120423e-05;
		asali_->thermo_[398].low[3] = 2.8703759369e-08;
		asali_->thermo_[398].low[4] = -3.6758790456e-12;
		asali_->thermo_[398].low[5] = -6.4716105469e+04;
		asali_->thermo_[398].low[6] = 2.6920671463e+01;
		
		asali_->thermo_[399].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[399].name,"RMPAOOX");

		asali_->thermo_[399].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[399].high[0] = 3.9689403534e+01;
		asali_->thermo_[399].high[1] = 5.3822506219e-02;
		asali_->thermo_[399].high[2] = -2.0277500880e-05;
		asali_->thermo_[399].high[3] = 3.6479388399e-09;
		asali_->thermo_[399].high[4] = -2.6121634153e-13;
		asali_->thermo_[399].high[5] = -8.3847234375e+04;
		asali_->thermo_[399].high[6] = -1.6754673767e+02;

		asali_->thermo_[399].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[399].low[0] = 4.7046675682e+00;
		asali_->thermo_[399].low[1] = 1.3156636059e-01;
		asali_->thermo_[399].low[2] = -8.5064049927e-05;
		asali_->thermo_[399].low[3] = 2.7642956368e-08;
		asali_->thermo_[399].low[4] = -3.5938576334e-12;
		asali_->thermo_[399].low[5] = -7.1252726562e+04;
		asali_->thermo_[399].low[6] = 2.1797952652e+01;
		
		asali_->thermo_[400].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[400].name,"ZMPAOOH");

		asali_->thermo_[400].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[400].high[0] = 4.8960113525e+01;
		asali_->thermo_[400].high[1] = 4.6964660287e-02;
		asali_->thermo_[400].high[2] = -1.6147776478e-05;
		asali_->thermo_[400].high[3] = 2.5875734888e-09;
		asali_->thermo_[400].high[4] = -1.5808002422e-13;
		asali_->thermo_[400].high[5] = -9.9631367188e+04;
		asali_->thermo_[400].high[6] = -2.1122653198e+02;

		asali_->thermo_[400].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[400].low[0] = 6.9149503708e+00;
		asali_->thermo_[400].low[1] = 1.4144816995e-01;
		asali_->thermo_[400].low[2] = -9.5768715255e-05;
		asali_->thermo_[400].low[3] = 3.2408149053e-08;
		asali_->thermo_[400].low[4] = -4.3463631132e-12;
		asali_->thermo_[400].low[5] = -8.4663289062e+04;
		asali_->thermo_[400].low[6] = 1.5860872269e+01;
		
		asali_->thermo_[401].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[401].name,"RMLIN1A");

		asali_->thermo_[401].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[401].high[0] = 5.9515068054e+01;
		asali_->thermo_[401].high[1] = 7.4246108532e-02;
		asali_->thermo_[401].high[2] = -2.5382483727e-05;
		asali_->thermo_[401].high[3] = 3.8283372028e-09;
		asali_->thermo_[401].high[4] = -2.0861464682e-13;
		asali_->thermo_[401].high[5] = -4.8286375000e+04;
		asali_->thermo_[401].high[6] = -2.6904882812e+02;

		asali_->thermo_[401].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[401].low[0] = -9.1252422333e-01;
		asali_->thermo_[401].low[1] = 2.0852965117e-01;
		asali_->thermo_[401].low[2] = -1.3728543126e-04;
		asali_->thermo_[401].low[3] = 4.5273875315e-08;
		asali_->thermo_[401].low[4] = -5.9649390462e-12;
		asali_->thermo_[401].low[5] = -2.6532441406e+04;
		asali_->thermo_[401].low[6] = 5.7997917175e+01;
		
		asali_->thermo_[402].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[402].name,"RMLIN1X");

		asali_->thermo_[402].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[402].high[0] = 5.9515068054e+01;
		asali_->thermo_[402].high[1] = 7.4246108532e-02;
		asali_->thermo_[402].high[2] = -2.5382483727e-05;
		asali_->thermo_[402].high[3] = 3.8283372028e-09;
		asali_->thermo_[402].high[4] = -2.0861464682e-13;
		asali_->thermo_[402].high[5] = -4.8286375000e+04;
		asali_->thermo_[402].high[6] = -2.6904882812e+02;

		asali_->thermo_[402].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[402].low[0] = -9.1252422333e-01;
		asali_->thermo_[402].low[1] = 2.0852965117e-01;
		asali_->thermo_[402].low[2] = -1.3728543126e-04;
		asali_->thermo_[402].low[3] = 4.5273875315e-08;
		asali_->thermo_[402].low[4] = -5.9649390462e-12;
		asali_->thermo_[402].low[5] = -2.6532441406e+04;
		asali_->thermo_[402].low[6] = 5.7997917175e+01;
		
		asali_->thermo_[403].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[403].name,"RMLIN1OOX");

		asali_->thermo_[403].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[403].high[0] = 5.4879886627e+01;
		asali_->thermo_[403].high[1] = 9.0584382415e-02;
		asali_->thermo_[403].high[2] = -3.5432120058e-05;
		asali_->thermo_[403].high[3] = 6.5017604634e-09;
		asali_->thermo_[403].high[4] = -4.6904900753e-13;
		asali_->thermo_[403].high[5] = -7.1322937500e+04;
		asali_->thermo_[403].high[6] = -2.3480903625e+02;

		asali_->thermo_[403].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[403].low[0] = -1.4749755859e+00;
		asali_->thermo_[403].low[1] = 2.2720223665e-01;
		asali_->thermo_[403].low[2] = -1.5963015903e-04;
		asali_->thermo_[403].low[3] = 5.6682786465e-08;
		asali_->thermo_[403].low[4] = -8.0722347209e-12;
		asali_->thermo_[403].low[5] = -5.2725835938e+04;
		asali_->thermo_[403].low[6] = 6.5291717529e+01;
		
		asali_->thermo_[404].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[404].name,"QMLIN1OOX");

		asali_->thermo_[404].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[404].high[0] = 5.6682552338e+01;
		asali_->thermo_[404].high[1] = 9.0304918587e-02;
		asali_->thermo_[404].high[2] = -3.5943481635e-05;
		asali_->thermo_[404].high[3] = 6.7261090031e-09;
		asali_->thermo_[404].high[4] = -4.9550679315e-13;
		asali_->thermo_[404].high[5] = -6.7492367188e+04;
		asali_->thermo_[404].high[6] = -2.4460177612e+02;

		asali_->thermo_[404].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[404].low[0] = -2.7182891369e+00;
		asali_->thermo_[404].low[1] = 2.3788465559e-01;
		asali_->thermo_[404].low[2] = -1.7344013031e-04;
		asali_->thermo_[404].low[3] = 6.3660536398e-08;
		asali_->thermo_[404].low[4] = -9.3362565942e-12;
		asali_->thermo_[404].low[5] = -4.8365296875e+04;
		asali_->thermo_[404].low[6] = 7.0261665344e+01;
		
		asali_->thermo_[405].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[405].name,"ZMLIN1OOX");

		asali_->thermo_[405].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[405].high[0] = 6.6192008972e+01;
		asali_->thermo_[405].high[1] = 8.1844411790e-02;
		asali_->thermo_[405].high[2] = -3.0370605600e-05;
		asali_->thermo_[405].high[3] = 5.1717115035e-09;
		asali_->thermo_[405].high[4] = -3.3900063746e-13;
		asali_->thermo_[405].high[5] = -8.8310429688e+04;
		asali_->thermo_[405].high[6] = -2.9313824463e+02;

		asali_->thermo_[405].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[405].low[0] = 7.9544717073e-01;
		asali_->thermo_[405].low[1] = 2.3662917316e-01;
		asali_->thermo_[405].low[2] = -1.6775353288e-04;
		asali_->thermo_[405].low[3] = 5.9366158212e-08;
		asali_->thermo_[405].low[4] = -8.3559305308e-12;
		asali_->thermo_[405].low[5] = -6.6206390625e+04;
		asali_->thermo_[405].low[6] = 5.6677783966e+01;
		
		asali_->thermo_[406].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[406].name,"RMLINA");

		asali_->thermo_[406].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[406].high[0] = 5.7195472717e+01;
		asali_->thermo_[406].high[1] = 8.4002226591e-02;
		asali_->thermo_[406].high[2] = -3.1564541132e-05;
		asali_->thermo_[406].high[3] = 5.6401976423e-09;
		asali_->thermo_[406].high[4] = -4.0009689355e-13;
		asali_->thermo_[406].high[5] = -6.6957484375e+04;
		asali_->thermo_[406].high[6] = -2.5448559570e+02;

		asali_->thermo_[406].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[406].low[0] = -1.3085613251e+00;
		asali_->thermo_[406].low[1] = 2.1401119232e-01;
		asali_->thermo_[406].low[2] = -1.3990534353e-04;
		asali_->thermo_[406].low[3] = 4.5766419987e-08;
		asali_->thermo_[406].low[4] = -5.9731833195e-12;
		asali_->thermo_[406].low[5] = -4.5896031250e+04;
		asali_->thermo_[406].low[6] = 6.2150428772e+01;
		
		asali_->thermo_[407].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[407].name,"RMLINX");

		asali_->thermo_[407].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[407].high[0] = 5.7195472717e+01;
		asali_->thermo_[407].high[1] = 8.4002226591e-02;
		asali_->thermo_[407].high[2] = -3.1564541132e-05;
		asali_->thermo_[407].high[3] = 5.6401976423e-09;
		asali_->thermo_[407].high[4] = -4.0009689355e-13;
		asali_->thermo_[407].high[5] = -6.6957484375e+04;
		asali_->thermo_[407].high[6] = -2.5448559570e+02;

		asali_->thermo_[407].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[407].low[0] = -1.3085613251e+00;
		asali_->thermo_[407].low[1] = 2.1401119232e-01;
		asali_->thermo_[407].low[2] = -1.3990534353e-04;
		asali_->thermo_[407].low[3] = 4.5766419987e-08;
		asali_->thermo_[407].low[4] = -5.9731833195e-12;
		asali_->thermo_[407].low[5] = -4.5896031250e+04;
		asali_->thermo_[407].low[6] = 6.2150428772e+01;
		
		asali_->thermo_[408].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[408].name,"RMLINOOX");

		asali_->thermo_[408].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[408].high[0] = 6.3213245392e+01;
		asali_->thermo_[408].high[1] = 8.0523937941e-02;
		asali_->thermo_[408].high[2] = -2.7819774914e-05;
		asali_->thermo_[408].high[3] = 4.2720071924e-09;
		asali_->thermo_[408].high[4] = -2.3992781503e-13;
		asali_->thermo_[408].high[5] = -8.7723890625e+04;
		asali_->thermo_[408].high[6] = -2.8270040894e+02;

		asali_->thermo_[408].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[408].low[0] = 1.9966132641e+00;
		asali_->thermo_[408].low[1] = 2.1808940172e-01;
		asali_->thermo_[408].low[2] = -1.4374572493e-04;
		asali_->thermo_[408].low[3] = 4.7689965754e-08;
		asali_->thermo_[408].low[4] = -6.3379557678e-12;
		asali_->thermo_[408].low[5] = -6.5930773438e+04;
		asali_->thermo_[408].low[6] = 4.7932773590e+01;
		
		asali_->thermo_[409].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[409].name,"QMLINOOX");

		asali_->thermo_[409].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[409].high[0] = 6.8130996704e+01;
		asali_->thermo_[409].high[1] = 7.4537992477e-02;
		asali_->thermo_[409].high[2] = -2.4787801522e-05;
		asali_->thermo_[409].high[3] = 3.5569356349e-09;
		asali_->thermo_[409].high[4] = -1.7530712938e-13;
		asali_->thermo_[409].high[5] = -8.2947445312e+04;
		asali_->thermo_[409].high[6] = -3.0887854004e+02;

		asali_->thermo_[409].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[409].low[0] = 1.7645809799e-02;
		asali_->thermo_[409].low[1] = 2.2934105992e-01;
		asali_->thermo_[409].low[2] = -1.5672223526e-04;
		asali_->thermo_[409].low[3] = 5.3532097866e-08;
		asali_->thermo_[409].low[4] = -7.2740520204e-12;
		asali_->thermo_[409].low[5] = -5.8971546875e+04;
		asali_->thermo_[409].low[6] = 5.8234413147e+01;
		
		asali_->thermo_[410].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[410].name,"ZMLINOOX");

		asali_->thermo_[410].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[410].high[0] = 6.1408706665e+01;
		asali_->thermo_[410].high[1] = 8.5833184421e-02;
		asali_->thermo_[410].high[2] = -2.9801760320e-05;
		asali_->thermo_[410].high[3] = 4.6393973108e-09;
		asali_->thermo_[410].high[4] = -2.6566102833e-13;
		asali_->thermo_[410].high[5] = -9.6591421875e+04;
		asali_->thermo_[410].high[6] = -2.8117395020e+02;

		asali_->thermo_[410].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[410].low[0] = 1.3118665218e+00;
		asali_->thermo_[410].low[1] = 2.4294911325e-01;
		asali_->thermo_[410].low[2] = -1.8383697898e-04;
		asali_->thermo_[410].low[3] = 7.1757142450e-08;
		asali_->thermo_[410].low[4] = -1.1232612930e-11;
		asali_->thermo_[410].low[5] = -7.8201789062e+04;
		asali_->thermo_[410].low[6] = 3.4315807343e+01;
		
		asali_->thermo_[411].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[411].name,"RMEOLEA");

		asali_->thermo_[411].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[411].high[0] = 5.6577224731e+01;
		asali_->thermo_[411].high[1] = 8.9880600572e-02;
		asali_->thermo_[411].high[2] = -3.4228814911e-05;
		asali_->thermo_[411].high[3] = 6.2473581863e-09;
		asali_->thermo_[411].high[4] = -4.5521610570e-13;
		asali_->thermo_[411].high[5] = -8.0688546875e+04;
		asali_->thermo_[411].high[6] = -2.4996537781e+02;

		asali_->thermo_[411].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[411].low[0] = -1.5710628033e-01;
		asali_->thermo_[411].low[1] = 2.1595688164e-01;
		asali_->thermo_[411].low[2] = -1.3929238776e-04;
		asali_->thermo_[411].low[3] = 4.5159794126e-08;
		asali_->thermo_[411].low[4] = -5.8597211285e-12;
		asali_->thermo_[411].low[5] = -6.0264187500e+04;
		asali_->thermo_[411].low[6] = 5.7092655182e+01;
		
		asali_->thermo_[412].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[412].name,"RMEOLES");

		asali_->thermo_[412].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[412].high[0] = 5.6577224731e+01;
		asali_->thermo_[412].high[1] = 8.9880600572e-02;
		asali_->thermo_[412].high[2] = -3.4228814911e-05;
		asali_->thermo_[412].high[3] = 6.2473581863e-09;
		asali_->thermo_[412].high[4] = -4.5521610570e-13;
		asali_->thermo_[412].high[5] = -8.0688546875e+04;
		asali_->thermo_[412].high[6] = -2.4996537781e+02;

		asali_->thermo_[412].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[412].low[0] = -1.5710628033e-01;
		asali_->thermo_[412].low[1] = 2.1595688164e-01;
		asali_->thermo_[412].low[2] = -1.3929238776e-04;
		asali_->thermo_[412].low[3] = 4.5159794126e-08;
		asali_->thermo_[412].low[4] = -5.8597211285e-12;
		asali_->thermo_[412].low[5] = -6.0264187500e+04;
		asali_->thermo_[412].low[6] = 5.7092655182e+01;
		
		asali_->thermo_[413].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[413].name,"RMEOLEOOX");

		asali_->thermo_[413].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[413].high[0] = 5.6828842163e+01;
		asali_->thermo_[413].high[1] = 9.8702460527e-02;
		asali_->thermo_[413].high[2] = -3.8723625039e-05;
		asali_->thermo_[413].high[3] = 7.1953145664e-09;
		asali_->thermo_[413].high[4] = -5.3127977278e-13;
		asali_->thermo_[413].high[5] = -1.2328098438e+05;
		asali_->thermo_[413].high[6] = -2.4495675659e+02;

		asali_->thermo_[413].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[413].low[0] = 2.2971394062e+00;
		asali_->thermo_[413].low[1] = 2.1988402307e-01;
		asali_->thermo_[413].low[2] = -1.3970826694e-04;
		asali_->thermo_[413].low[3] = 4.4597030069e-08;
		asali_->thermo_[413].low[4] = -5.7259626728e-12;
		asali_->thermo_[413].low[5] = -1.0364957031e+05;
		asali_->thermo_[413].low[6] = 5.0180202484e+01;
		
		asali_->thermo_[414].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[414].name,"QMEOLEOOH");

		asali_->thermo_[414].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[414].high[0] = 6.6628845215e+01;
		asali_->thermo_[414].high[1] = 8.4446623921e-02;
		asali_->thermo_[414].high[2] = -2.8970014682e-05;
		asali_->thermo_[414].high[3] = 4.4090051610e-09;
		asali_->thermo_[414].high[4] = -2.4493230252e-13;
		asali_->thermo_[414].high[5] = -1.5087798438e+05;
		asali_->thermo_[414].high[6] = -3.0044201660e+02;

		asali_->thermo_[414].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[414].low[0] = -9.9879020452e-01;
		asali_->thermo_[414].low[1] = 2.3473025858e-01;
		asali_->thermo_[414].low[2] = -1.5420636919e-04;
		asali_->thermo_[414].low[3] = 5.0792841932e-08;
		asali_->thermo_[414].low[4] = -6.6871317511e-12;
		asali_->thermo_[414].low[5] = -1.2653203906e+05;
		asali_->thermo_[414].low[6] = 6.5572837830e+01;
		
		asali_->thermo_[415].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[415].name,"ZMEOLEOOX");

		asali_->thermo_[415].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[415].high[0] = 5.7495010376e+01;
		asali_->thermo_[415].high[1] = 9.9260643125e-02;
		asali_->thermo_[415].high[2] = -3.3500407881e-05;
		asali_->thermo_[415].high[3] = 5.0806368002e-09;
		asali_->thermo_[415].high[4] = -2.8224029559e-13;
		asali_->thermo_[415].high[5] = -1.0964846875e+05;
		asali_->thermo_[415].high[6] = -2.3831535339e+02;

		asali_->thermo_[415].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[415].low[0] = 2.3845183849e+00;
		asali_->thermo_[415].low[1] = 2.4240477383e-01;
		asali_->thermo_[415].low[2] = -1.7292652046e-04;
		asali_->thermo_[415].low[3] = 6.5438257479e-08;
		asali_->thermo_[415].low[4] = -1.0080555314e-11;
		asali_->thermo_[415].low[5] = -9.2674429688e+04;
		asali_->thermo_[415].low[6] = 5.1356658936e+01;
		
		asali_->thermo_[416].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[416].name,"RSTEAX");

		asali_->thermo_[416].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[416].high[0] = 5.4633579254e+01;
		asali_->thermo_[416].high[1] = 9.3423068523e-02;
		asali_->thermo_[416].high[2] = -3.1996431062e-05;
		asali_->thermo_[416].high[3] = 4.6718180435e-09;
		asali_->thermo_[416].high[4] = -2.1670694210e-13;
		asali_->thermo_[416].high[5] = -9.7461726562e+04;
		asali_->thermo_[416].high[6] = -2.4377708435e+02;

		asali_->thermo_[416].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[416].low[0] = -6.3470931053e+00;
		asali_->thermo_[416].low[1] = 2.4683357775e-01;
		asali_->thermo_[416].low[2] = -1.7672331887e-04;
		asali_->thermo_[416].low[3] = 6.5353951584e-08;
		asali_->thermo_[416].low[4] = -9.7579227684e-12;
		asali_->thermo_[416].low[5] = -7.8069875000e+04;
		asali_->thermo_[416].low[6] = 7.8698226929e+01;
		
		asali_->thermo_[417].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[417].name,"RMSTEAOOX");

		asali_->thermo_[417].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[417].high[0] = -1.2070082855e+02;
		asali_->thermo_[417].high[1] = 5.6773662567e-01;
		asali_->thermo_[417].high[2] = -4.5275059529e-04;
		asali_->thermo_[417].high[3] = 1.4731772069e-07;
		asali_->thermo_[417].high[4] = -1.6752875129e-11;
		asali_->thermo_[417].high[5] = 1.0203972656e+04;
		asali_->thermo_[417].high[6] = 6.6002398682e+02;

		asali_->thermo_[417].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[417].low[0] = 1.9117095947e+01;
		asali_->thermo_[417].low[1] = 1.2031929940e-01;
		asali_->thermo_[417].low[2] = 8.4150218754e-05;
		asali_->thermo_[417].low[3] = -1.3902938178e-07;
		asali_->thermo_[417].low[4] = 4.0516544980e-11;
		asali_->thermo_[417].low[5] = -2.4750507812e+04;
		asali_->thermo_[417].low[6] = -4.5716110229e+01;
		
		asali_->thermo_[418].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[418].name,"QMSTEAOOH");

		asali_->thermo_[418].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[418].high[0] = -1.3061212158e+02;
		asali_->thermo_[418].high[1] = 6.0036540031e-01;
		asali_->thermo_[418].high[2] = -4.8519752454e-04;
		asali_->thermo_[418].high[3] = 1.5869069614e-07;
		asali_->thermo_[418].high[4] = -1.8091828383e-11;
		asali_->thermo_[418].high[5] = 1.2404572266e+04;
		asali_->thermo_[418].high[6] = 7.1208374023e+02;

		asali_->thermo_[418].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[418].low[0] = 2.1555452347e+01;
		asali_->thermo_[418].low[1] = 1.0551153868e-01;
		asali_->thermo_[418].low[2] = 1.1828283459e-04;
		asali_->thermo_[418].low[3] = -1.6839892680e-07;
		asali_->thermo_[418].low[4] = 4.8389802582e-11;
		asali_->thermo_[418].low[5] = -2.5028650391e+04;
		asali_->thermo_[418].low[6] = -5.3537647247e+01;
		
		asali_->thermo_[419].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[419].name,"ZMSTEAOOH");

		asali_->thermo_[419].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[419].high[0] = -6.2299530029e+01;
		asali_->thermo_[419].high[1] = 3.4157595038e-01;
		asali_->thermo_[419].high[2] = -2.6970700128e-04;
		asali_->thermo_[419].high[3] = 8.7196916354e-08;
		asali_->thermo_[419].high[4] = -9.8743548060e-12;
		asali_->thermo_[419].high[5] = 1.5716004883e+04;
		asali_->thermo_[419].high[6] = 3.5702038574e+02;

		asali_->thermo_[419].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[419].low[0] = 1.6195426941e+01;
		asali_->thermo_[419].low[1] = 9.0392082930e-02;
		asali_->thermo_[419].low[2] = 3.1713636417e-05;
		asali_->thermo_[419].low[3] = -7.3560755709e-08;
		asali_->thermo_[419].low[4] = 2.2277180101e-11;
		asali_->thermo_[419].low[5] = -3.9077338867e+03;
		asali_->thermo_[419].low[6] = -3.9188034058e+01;
		
		asali_->thermo_[420].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[420].name,"U2ME12");

		asali_->thermo_[420].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[420].high[0] = 3.1279945374e+01;
		asali_->thermo_[420].high[1] = 7.1541585028e-02;
		asali_->thermo_[420].high[2] = -3.0118153518e-05;
		asali_->thermo_[420].high[3] = 6.0864318030e-09;
		asali_->thermo_[420].high[4] = -4.8733489032e-13;
		asali_->thermo_[420].high[5] = -6.2826808594e+04;
		asali_->thermo_[420].high[6] = -1.2447859192e+02;

		asali_->thermo_[420].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[420].low[0] = 1.1265071630e+00;
		asali_->thermo_[420].low[1] = 1.4645695686e-01;
		asali_->thermo_[420].low[2] = -9.9915087048e-05;
		asali_->thermo_[420].low[3] = 3.4987852615e-08;
		asali_->thermo_[420].low[4] = -4.9751331527e-12;
		asali_->thermo_[420].low[5] = -5.3117402344e+04;
		asali_->thermo_[420].low[6] = 3.5354412079e+01;
		
		asali_->thermo_[421].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[421].name,"ALDEST");

		asali_->thermo_[421].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[421].high[0] = 1.7960880280e+01;
		asali_->thermo_[421].high[1] = 3.2757729292e-02;
		asali_->thermo_[421].high[2] = -1.2990481082e-05;
		asali_->thermo_[421].high[3] = 2.5001367643e-09;
		asali_->thermo_[421].high[4] = -1.9343138473e-13;
		asali_->thermo_[421].high[5] = -7.4898320312e+04;
		asali_->thermo_[421].high[6] = -5.9917144775e+01;

		asali_->thermo_[421].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[421].low[0] = 5.2413783073e+00;
		asali_->thermo_[421].low[1] = 6.1023291200e-02;
		asali_->thermo_[421].low[2] = -3.6545116018e-05;
		asali_->thermo_[421].low[3] = 1.1224075003e-08;
		asali_->thermo_[421].low[4] = -1.4050894779e-12;
		asali_->thermo_[421].low[5] = -7.0319296875e+04;
		asali_->thermo_[421].low[6] = 8.9234542847e+00;
		
		asali_->thermo_[422].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[422].name,"RALDEST");

		asali_->thermo_[422].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[422].high[0] = 1.1768862724e+01;
		asali_->thermo_[422].high[1] = 4.1658632457e-02;
		asali_->thermo_[422].high[2] = -2.0233062969e-05;
		asali_->thermo_[422].high[3] = 4.6812673737e-09;
		asali_->thermo_[422].high[4] = -4.2194107366e-13;
		asali_->thermo_[422].high[5] = -4.9100718750e+04;
		asali_->thermo_[422].high[6] = -2.2750774384e+01;

		asali_->thermo_[422].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[422].low[0] = 5.7664504051e+00;
		asali_->thermo_[422].low[1] = 5.4997324944e-02;
		asali_->thermo_[422].low[2] = -3.1348641642e-05;
		asali_->thermo_[422].low[3] = 8.7981479879e-09;
		asali_->thermo_[422].low[4] = -9.9373005484e-13;
		asali_->thermo_[422].low[5] = -4.6939847656e+04;
		asali_->thermo_[422].low[6] = 9.7355318069e+00;
		
		asali_->thermo_[423].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[423].name,"C12H18");

		asali_->thermo_[423].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[423].high[0] = 8.4429588318e+01;
		asali_->thermo_[423].high[1] = 4.9317039549e-02;
		asali_->thermo_[423].high[2] = -2.8626835046e-05;
		asali_->thermo_[423].high[3] = 8.8697991174e-09;
		asali_->thermo_[423].high[4] = -1.0037361567e-12;
		asali_->thermo_[423].high[5] = -8.9426531250e+04;
		asali_->thermo_[423].high[6] = -4.1206576538e+02;

		asali_->thermo_[423].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[423].low[0] = -1.1802491188e+01;
		asali_->thermo_[423].low[1] = 2.6316609979e-01;
		asali_->thermo_[423].low[2] = -2.0683438925e-04;
		asali_->thermo_[423].low[3] = 7.4872595235e-08;
		asali_->thermo_[423].low[4] = -1.0170791293e-11;
		asali_->thermo_[423].low[5] = -5.4782980469e+04;
		asali_->thermo_[423].low[6] = 1.0876231384e+02;
		
		asali_->thermo_[424].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[424].name,"RODECA");

		asali_->thermo_[424].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[424].high[0] = 2.8562032700e+01;
		asali_->thermo_[424].high[1] = 4.1136641055e-02;
		asali_->thermo_[424].high[2] = -1.3602410945e-05;
		asali_->thermo_[424].high[3] = 2.0159278691e-09;
		asali_->thermo_[424].high[4] = -1.0937662587e-13;
		asali_->thermo_[424].high[5] = -1.5302505859e+04;
		asali_->thermo_[424].high[6] = -1.3964169312e+02;

		asali_->thermo_[424].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[424].low[0] = -1.3960130692e+01;
		asali_->thermo_[424].low[1] = 1.3563033938e-01;
		asali_->thermo_[424].low[2] = -9.2347159807e-05;
		asali_->thermo_[424].low[3] = 3.1180650950e-08;
		asali_->thermo_[424].low[4] = -4.1600325615e-12;
		asali_->thermo_[424].low[5] = 5.4727807045e+00;
		asali_->thermo_[424].low[6] = 9.0497138977e+01;
		
		asali_->thermo_[425].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[425].name,"ALDINS");

		asali_->thermo_[425].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[425].high[0] = 8.4429588318e+01;
		asali_->thermo_[425].high[1] = 4.9317039549e-02;
		asali_->thermo_[425].high[2] = -2.8626835046e-05;
		asali_->thermo_[425].high[3] = 8.8697991174e-09;
		asali_->thermo_[425].high[4] = -1.0037361567e-12;
		asali_->thermo_[425].high[5] = -8.9426531250e+04;
		asali_->thermo_[425].high[6] = -4.1206576538e+02;

		asali_->thermo_[425].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[425].low[0] = -1.1802491188e+01;
		asali_->thermo_[425].low[1] = 2.6316609979e-01;
		asali_->thermo_[425].low[2] = -2.0683438925e-04;
		asali_->thermo_[425].low[3] = 7.4872595235e-08;
		asali_->thermo_[425].low[4] = -1.0170791293e-11;
		asali_->thermo_[425].low[5] = -5.4782980469e+04;
		asali_->thermo_[425].low[6] = 1.0876231384e+02;
		
		asali_->thermo_[426].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[426].name,"RUME16");

		asali_->thermo_[426].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[426].high[0] = 5.6281600952e+01;
		asali_->thermo_[426].high[1] = 7.1435555816e-02;
		asali_->thermo_[426].high[2] = -2.4327213396e-05;
		asali_->thermo_[426].high[3] = 3.6569938189e-09;
		asali_->thermo_[426].high[4] = -1.9826055673e-13;
		asali_->thermo_[426].high[5] = -7.5340992188e+04;
		asali_->thermo_[426].high[6] = -2.5392437744e+02;

		asali_->thermo_[426].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[426].low[0] = 9.9452459812e-01;
		asali_->thermo_[426].low[1] = 1.9498209655e-01;
		asali_->thermo_[426].low[2] = -1.2785782747e-04;
		asali_->thermo_[426].low[3] = 4.2215884122e-08;
		asali_->thermo_[426].low[4] = -5.5835804730e-12;
		asali_->thermo_[426].low[5] = -5.5548222656e+04;
		asali_->thermo_[426].low[6] = 4.4992797852e+01;
		
		asali_->thermo_[427].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[427].name,"NC10H19");

		asali_->thermo_[427].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[427].high[0] = 9.8828735352e+00;
		asali_->thermo_[427].high[1] = 2.8627535328e-02;
		asali_->thermo_[427].high[2] = -1.2366243027e-05;
		asali_->thermo_[427].high[3] = 2.5830850792e-09;
		asali_->thermo_[427].high[4] = -2.1452096013e-13;
		asali_->thermo_[427].high[5] = 7.1421162109e+03;
		asali_->thermo_[427].high[6] = -2.8137975693e+01;

		asali_->thermo_[427].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[427].low[0] = -9.6136063337e-01;
		asali_->thermo_[427].low[1] = 5.2725832909e-02;
		asali_->thermo_[427].low[2] = -3.2448158890e-05;
		asali_->thermo_[427].low[3] = 1.0020831276e-08;
		asali_->thermo_[427].low[4] = -1.2475413497e-12;
		asali_->thermo_[427].low[5] = 1.1046041016e+04;
		asali_->thermo_[427].low[6] = 3.0553283691e+01;
		
		asali_->thermo_[428].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[428].name,"C8H9");

		asali_->thermo_[428].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[428].high[0] = 2.4597391129e+01;
		asali_->thermo_[428].high[1] = 1.2050396763e-02;
		asali_->thermo_[428].high[2] = 5.6675412452e-07;
		asali_->thermo_[428].high[3] = -1.1095531161e-09;
		asali_->thermo_[428].high[4] = 1.5730831622e-13;
		asali_->thermo_[428].high[5] = 1.6594873047e+04;
		asali_->thermo_[428].high[6] = -1.0644212341e+02;

		asali_->thermo_[428].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[428].low[0] = -5.1260461807e+00;
		asali_->thermo_[428].low[1] = 8.7778903544e-02;
		asali_->thermo_[428].low[2] = -7.1785318141e-05;
		asali_->thermo_[428].low[3] = 2.9613195451e-08;
		asali_->thermo_[428].low[4] = -4.7348492314e-12;
		asali_->thermo_[428].low[5] = 2.5928033203e+04;
		asali_->thermo_[428].low[6] = 5.0363796234e+01;
		
		asali_->thermo_[429].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[429].name,"NC7H13OOH");

		asali_->thermo_[429].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[429].high[0] = 2.7321958542e+01;
		asali_->thermo_[429].high[1] = 3.5587098449e-02;
		asali_->thermo_[429].high[2] = -1.2465077816e-05;
		asali_->thermo_[429].high[3] = 2.0008925627e-09;
		asali_->thermo_[429].high[4] = -1.2199768105e-13;
		asali_->thermo_[429].high[5] = -4.8463417969e+04;
		asali_->thermo_[429].high[6] = -1.1226205444e+02;

		asali_->thermo_[429].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[429].low[0] = 1.1621515751e+00;
		asali_->thermo_[429].low[1] = 9.4044767320e-02;
		asali_->thermo_[429].low[2] = -6.1451952206e-05;
		asali_->thermo_[429].low[3] = 2.0245538579e-08;
		asali_->thermo_[429].low[4] = -2.6701325612e-12;
		asali_->thermo_[429].low[5] = -3.9098207031e+04;
		asali_->thermo_[429].low[6] = 2.9174539566e+01;
		
		asali_->thermo_[430].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[430].name,"NC7H13");

		asali_->thermo_[430].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[430].high[0] = 9.8828735352e+00;
		asali_->thermo_[430].high[1] = 2.8627535328e-02;
		asali_->thermo_[430].high[2] = -1.2366243027e-05;
		asali_->thermo_[430].high[3] = 2.5830850792e-09;
		asali_->thermo_[430].high[4] = -2.1452096013e-13;
		asali_->thermo_[430].high[5] = 7.1421162109e+03;
		asali_->thermo_[430].high[6] = -2.8137975693e+01;

		asali_->thermo_[430].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[430].low[0] = -9.6136063337e-01;
		asali_->thermo_[430].low[1] = 5.2725832909e-02;
		asali_->thermo_[430].low[2] = -3.2448158890e-05;
		asali_->thermo_[430].low[3] = 1.0020831276e-08;
		asali_->thermo_[430].low[4] = -1.2475413497e-12;
		asali_->thermo_[430].low[5] = 1.1046041016e+04;
		asali_->thermo_[430].low[6] = 3.0553283691e+01;
		
		asali_->thermo_[431].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[431].name,"LC6H5");

		asali_->thermo_[431].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[431].high[0] = 1.2307607651e+01;
		asali_->thermo_[431].high[1] = 1.6826195642e-02;
		asali_->thermo_[431].high[2] = -6.5118138082e-06;
		asali_->thermo_[431].high[3] = 1.2115889403e-09;
		asali_->thermo_[431].high[4] = -8.9942823697e-14;
		asali_->thermo_[431].high[5] = 5.8942507812e+04;
		asali_->thermo_[431].high[6] = -3.5537322998e+01;

		asali_->thermo_[431].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[431].low[0] = 1.6761417687e-01;
		asali_->thermo_[431].low[1] = 5.9422664344e-02;
		asali_->thermo_[431].low[2] = -6.2559796788e-05;
		asali_->thermo_[431].low[3] = 3.3988186487e-08;
		asali_->thermo_[431].low[4] = -7.2777938190e-12;
		asali_->thermo_[431].low[5] = 6.1710425781e+04;
		asali_->thermo_[431].low[6] = 2.4621807098e+01;
		
		asali_->thermo_[432].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[432].name,"C6H2");

		asali_->thermo_[432].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[432].high[0] = 1.2000706673e+01;
		asali_->thermo_[432].high[1] = 9.3574719504e-03;
		asali_->thermo_[432].high[2] = -3.4503927964e-06;
		asali_->thermo_[432].high[3] = 5.9693194832e-10;
		asali_->thermo_[432].high[4] = -4.0806740582e-14;
		asali_->thermo_[432].high[5] = 8.1079773438e+04;
		asali_->thermo_[432].high[6] = -3.6163059235e+01;

		asali_->thermo_[432].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[432].low[0] = 4.4020638466e+00;
		asali_->thermo_[432].low[1] = 3.6988902837e-02;
		asali_->thermo_[432].low[2] = -4.1129613237e-05;
		asali_->thermo_[432].low[3] = 2.3432823681e-08;
		asali_->thermo_[432].low[4] = -5.2307823871e-12;
		asali_->thermo_[432].low[5] = 8.2751468750e+04;
		asali_->thermo_[432].low[6] = 1.2202272415e+00;
		
		asali_->thermo_[433].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[433].name,"C8H2");

		asali_->thermo_[433].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[433].high[0] = 1.6271934509e+01;
		asali_->thermo_[433].high[1] = 9.9987452850e-03;
		asali_->thermo_[433].high[2] = -2.9303707834e-06;
		asali_->thermo_[433].high[3] = 2.8953733855e-10;
		asali_->thermo_[433].high[4] = 2.5240589211e-16;
		asali_->thermo_[433].high[5] = 1.0788546094e+05;
		asali_->thermo_[433].high[6] = -5.8973361969e+01;

		asali_->thermo_[433].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[433].low[0] = 1.8736171722e-01;
		asali_->thermo_[433].low[1] = 7.0695251226e-02;
		asali_->thermo_[433].low[2] = -8.8821652753e-05;
		asali_->thermo_[433].low[3] = 5.4309207798e-08;
		asali_->thermo_[433].low[4] = -1.2740235950e-11;
		asali_->thermo_[433].low[5] = 1.1129539062e+05;
		asali_->thermo_[433].low[6] = 1.9562637329e+01;
		
		asali_->thermo_[434].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[434].name,"C6H3");

		asali_->thermo_[434].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[434].high[0] = 1.1919452667e+01;
		asali_->thermo_[434].high[1] = 1.1613783427e-02;
		asali_->thermo_[434].high[2] = -4.1926450649e-06;
		asali_->thermo_[434].high[3] = 6.8469308001e-10;
		asali_->thermo_[434].high[4] = -4.1788756700e-14;
		asali_->thermo_[434].high[5] = 8.2628078125e+04;
		asali_->thermo_[434].high[6] = -3.2987655640e+01;

		asali_->thermo_[434].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[434].low[0] = 4.4660143852e+00;
		asali_->thermo_[434].low[1] = 3.4199956805e-02;
		asali_->thermo_[434].low[2] = -2.9858752896e-05;
		asali_->thermo_[434].low[3] = 1.3647373898e-08;
		asali_->thermo_[434].low[4] = -2.4968419259e-12;
		asali_->thermo_[434].low[5] = 8.4595781250e+04;
		asali_->thermo_[434].low[6] = 5.0401854515e+00;
		
		asali_->thermo_[435].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[435].name,"C6H4");

		asali_->thermo_[435].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[435].high[0] = 1.7444766998e+01;
		asali_->thermo_[435].high[1] = 6.2130670995e-03;
		asali_->thermo_[435].high[2] = -9.8096381862e-07;
		asali_->thermo_[435].high[3] = 8.0059466001e-11;
		asali_->thermo_[435].high[4] = -2.8832076141e-15;
		asali_->thermo_[435].high[5] = 5.4956890625e+04;
		asali_->thermo_[435].high[6] = -6.5920806885e+01;

		asali_->thermo_[435].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[435].low[0] = -1.1730561256e+00;
		asali_->thermo_[435].low[1] = 6.0971371830e-02;
		asali_->thermo_[435].low[2] = -6.1376151280e-05;
		asali_->thermo_[435].low[3] = 2.9685544689e-08;
		asali_->thermo_[435].low[4] = -5.4450680076e-12;
		asali_->thermo_[435].low[5] = 6.0020937500e+04;
		asali_->thermo_[435].low[6] = 2.9624124527e+01;
		
		asali_->thermo_[436].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[436].name,"BENZYNE");

		asali_->thermo_[436].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[436].high[0] = 1.0946581841e+01;
		asali_->thermo_[436].high[1] = 1.5037324280e-02;
		asali_->thermo_[436].high[2] = -5.2784494073e-06;
		asali_->thermo_[436].high[3] = 8.1460760359e-10;
		asali_->thermo_[436].high[4] = -4.4907335500e-14;
		asali_->thermo_[436].high[5] = 5.0330140625e+04;
		asali_->thermo_[436].high[6] = -3.5378292084e+01;

		asali_->thermo_[436].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[436].low[0] = -3.7379617691e+00;
		asali_->thermo_[436].low[1] = 5.6993164122e-02;
		asali_->thermo_[436].low[2] = -5.0231134082e-05;
		asali_->thermo_[436].low[3] = 2.2220648432e-08;
		asali_->thermo_[436].low[4] = -3.8674146351e-12;
		asali_->thermo_[436].low[5] = 5.4441812500e+04;
		asali_->thermo_[436].low[6] = 4.0407081604e+01;
		
		asali_->thermo_[437].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[437].name,"NC10MOOH");

		asali_->thermo_[437].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[437].high[0] = 2.7321958542e+01;
		asali_->thermo_[437].high[1] = 3.5587098449e-02;
		asali_->thermo_[437].high[2] = -1.2465077816e-05;
		asali_->thermo_[437].high[3] = 2.0008925627e-09;
		asali_->thermo_[437].high[4] = -1.2199768105e-13;
		asali_->thermo_[437].high[5] = -4.8463417969e+04;
		asali_->thermo_[437].high[6] = -1.1226205444e+02;

		asali_->thermo_[437].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[437].low[0] = 1.1621515751e+00;
		asali_->thermo_[437].low[1] = 9.4044767320e-02;
		asali_->thermo_[437].low[2] = -6.1451952206e-05;
		asali_->thermo_[437].low[3] = 2.0245538579e-08;
		asali_->thermo_[437].low[4] = -2.6701325612e-12;
		asali_->thermo_[437].low[5] = -3.9098207031e+04;
		asali_->thermo_[437].low[6] = 2.9174539566e+01;
		
		asali_->thermo_[438].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[438].name,"MSTEAKETO");

		asali_->thermo_[438].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[438].high[0] = 6.1334823608e+01;
		asali_->thermo_[438].high[1] = 9.8043695092e-02;
		asali_->thermo_[438].high[2] = -3.7703372072e-05;
		asali_->thermo_[438].high[3] = 6.8081726923e-09;
		asali_->thermo_[438].high[4] = -4.8338844863e-13;
		asali_->thermo_[438].high[5] = -1.4287018750e+05;
		asali_->thermo_[438].high[6] = -2.7083435059e+02;

		asali_->thermo_[438].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[438].low[0] = -4.1772246361e-01;
		asali_->thermo_[438].low[1] = 2.4958367646e-01;
		asali_->thermo_[438].low[2] = -1.7715734430e-04;
		asali_->thermo_[438].low[3] = 6.3844566967e-08;
		asali_->thermo_[438].low[4] = -9.2313014871e-12;
		asali_->thermo_[438].low[5] = -1.2273885156e+05;
		asali_->thermo_[438].low[6] = 5.7257041931e+01;
		
		asali_->thermo_[439].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[439].name,"C5H5O");

		asali_->thermo_[439].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[439].high[0] = 1.0580139160e+01;
		asali_->thermo_[439].high[1] = 2.1312877536e-02;
		asali_->thermo_[439].high[2] = -9.6305293482e-06;
		asali_->thermo_[439].high[3] = 2.0938479839e-09;
		asali_->thermo_[439].high[4] = -1.7932119819e-13;
		asali_->thermo_[439].high[5] = 1.6254340820e+04;
		asali_->thermo_[439].high[6] = -3.2615474701e+01;

		asali_->thermo_[439].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[439].low[0] = -4.0197939873e+00;
		asali_->thermo_[439].low[1] = 6.1588555574e-02;
		asali_->thermo_[439].low[2] = -5.1295024605e-05;
		asali_->thermo_[439].low[3] = 2.1249936921e-08;
		asali_->thermo_[439].low[4] = -3.4820952545e-12;
		asali_->thermo_[439].low[5] = 2.0488322266e+04;
		asali_->thermo_[439].low[6] = 4.3245567322e+01;
		
		asali_->thermo_[440].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[440].name,"C2H2O2");

		asali_->thermo_[440].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[440].high[0] = 9.8311653137e+00;
		asali_->thermo_[440].high[1] = 4.8736054450e-03;
		asali_->thermo_[440].high[2] = -1.6944329673e-06;
		asali_->thermo_[440].high[3] = 2.6536106645e-10;
		asali_->thermo_[440].high[4] = -1.5443983915e-14;
		asali_->thermo_[440].high[5] = -2.9627324219e+04;
		asali_->thermo_[440].high[6] = -2.6640703201e+01;

		asali_->thermo_[440].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[440].low[0] = 1.8994796276e+00;
		asali_->thermo_[440].low[1] = 2.3536395282e-02;
		asali_->thermo_[440].low[2] = -1.8161601474e-05;
		asali_->thermo_[440].low[3] = 6.7230740974e-09;
		asali_->thermo_[440].low[4] = -9.6510765959e-13;
		asali_->thermo_[440].low[5] = -2.6930550781e+04;
		asali_->thermo_[440].low[6] = 1.5833874702e+01;
		
		asali_->thermo_[441].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[441].name,"C2H4O2");

		asali_->thermo_[441].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[441].high[0] = 3.4061400890e+00;
		asali_->thermo_[441].high[1] = 2.0261304453e-02;
		asali_->thermo_[441].high[2] = -1.0346346244e-05;
		asali_->thermo_[441].high[3] = 2.5349711219e-09;
		asali_->thermo_[441].high[4] = -2.4043690216e-13;
		asali_->thermo_[441].high[5] = -3.8806035156e+04;
		asali_->thermo_[441].high[6] = 1.2056921959e+01;

		asali_->thermo_[441].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[441].low[0] = 4.6440353394e+00;
		asali_->thermo_[441].low[1] = 1.3830680400e-02;
		asali_->thermo_[441].low[2] = 2.1808439215e-06;
		asali_->thermo_[441].low[3] = -8.3110807125e-09;
		asali_->thermo_[441].low[4] = 3.2810084944e-12;
		asali_->thermo_[441].low[5] = -3.8996671875e+04;
		asali_->thermo_[441].low[6] = 6.4083352089e+00;
		
		asali_->thermo_[442].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[442].name,"GLIET");

		asali_->thermo_[442].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[442].high[0] = 6.6662144661e+00;
		asali_->thermo_[442].high[1] = 1.8745930865e-02;
		asali_->thermo_[442].high[2] = -7.6603919297e-06;
		asali_->thermo_[442].high[3] = 1.5387484620e-09;
		asali_->thermo_[442].high[4] = -1.2420324643e-13;
		asali_->thermo_[442].high[5] = -4.9595910156e+04;
		asali_->thermo_[442].high[6] = -6.0167188644e+00;

		asali_->thermo_[442].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[442].low[0] = 9.4622051716e-01;
		asali_->thermo_[442].low[1] = 3.4310542047e-02;
		asali_->thermo_[442].low[2] = -2.3542646886e-05;
		asali_->thermo_[442].low[3] = 8.7415852335e-09;
		asali_->thermo_[442].low[4] = -1.3491754372e-12;
		asali_->thermo_[442].low[5] = -4.7914234375e+04;
		asali_->thermo_[442].low[6] = 2.3782644272e+01;
		
		asali_->thermo_[443].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[443].name,"C3H4O2");

		asali_->thermo_[443].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[443].high[0] = 1.0292042732e+01;
		asali_->thermo_[443].high[1] = 1.3887129724e-02;
		asali_->thermo_[443].high[2] = -6.1256200752e-06;
		asali_->thermo_[443].high[3] = 1.3054884951e-09;
		asali_->thermo_[443].high[4] = -1.0996576777e-13;
		asali_->thermo_[443].high[5] = -3.5702699219e+04;
		asali_->thermo_[443].high[6] = -2.6935003281e+01;

		asali_->thermo_[443].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[443].low[0] = 1.1737804860e-01;
		asali_->thermo_[443].low[1] = 4.6708628535e-02;
		asali_->thermo_[443].low[2] = -4.5829045121e-05;
		asali_->thermo_[443].low[3] = 2.2651416742e-08;
		asali_->thermo_[443].low[4] = -4.4135801784e-12;
		asali_->thermo_[443].low[5] = -3.3179382812e+04;
		asali_->thermo_[443].low[6] = 2.4340559006e+01;
		
		asali_->thermo_[444].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[444].name,"C3H4O3");

		asali_->thermo_[444].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[444].high[0] = 1.3724281311e+01;
		asali_->thermo_[444].high[1] = 1.0881111026e-02;
		asali_->thermo_[444].high[2] = -3.7012484881e-06;
		asali_->thermo_[444].high[3] = 5.7890142680e-10;
		asali_->thermo_[444].high[4] = -3.4320582400e-14;
		asali_->thermo_[444].high[5] = -5.7780281250e+04;
		asali_->thermo_[444].high[6] = -3.9957008362e+01;

		asali_->thermo_[444].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[444].low[0] = 2.1756310463e+00;
		asali_->thermo_[444].low[1] = 3.7895496935e-02;
		asali_->thermo_[444].low[2] = -2.7398078601e-05;
		asali_->thermo_[444].low[3] = 9.8174313123e-09;
		asali_->thermo_[444].low[4] = -1.3849828402e-12;
		asali_->thermo_[444].low[5] = -5.3830640625e+04;
		asali_->thermo_[444].low[6] = 2.1954326630e+01;
		
		asali_->thermo_[445].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[445].name,"C3H6O2");

		asali_->thermo_[445].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[445].high[0] = 1.0872165680e+01;
		asali_->thermo_[445].high[1] = 1.6359321773e-02;
		asali_->thermo_[445].high[2] = -6.0863785620e-06;
		asali_->thermo_[445].high[3] = 1.1013084888e-09;
		asali_->thermo_[445].high[4] = -8.0291133985e-14;
		asali_->thermo_[445].high[5] = -4.5527296875e+04;
		asali_->thermo_[445].high[6] = -2.7074851990e+01;

		asali_->thermo_[445].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[445].low[0] = 2.6610593796e+00;
		asali_->thermo_[445].low[1] = 3.4606225789e-02;
		asali_->thermo_[445].low[2] = -2.1292131350e-05;
		asali_->thermo_[445].low[3] = 6.7330683251e-09;
		asali_->thermo_[445].low[4] = -8.6248000929e-13;
		asali_->thermo_[445].low[5] = -4.2571296875e+04;
		asali_->thermo_[445].low[6] = 1.7365367889e+01;
		
		asali_->thermo_[446].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[446].name,"C4H6O2");

		asali_->thermo_[446].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[446].high[0] = 7.0191960335e+00;
		asali_->thermo_[446].high[1] = 2.8991995379e-02;
		asali_->thermo_[446].high[2] = -1.3981116354e-05;
		asali_->thermo_[446].high[3] = 3.2275047079e-09;
		asali_->thermo_[446].high[4] = -2.9088881369e-13;
		asali_->thermo_[446].high[5] = -4.3605570312e+04;
		asali_->thermo_[446].high[6] = -7.4784693718e+00;

		asali_->thermo_[446].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[446].low[0] = 9.1515827179e-01;
		asali_->thermo_[446].low[1] = 4.2556524277e-02;
		asali_->thermo_[446].low[2] = -2.5284889489e-05;
		asali_->thermo_[446].low[3] = 7.4140875661e-09;
		asali_->thermo_[446].low[4] = -8.7235860896e-13;
		asali_->thermo_[446].low[5] = -4.1408117188e+04;
		asali_->thermo_[446].low[6] = 2.5557855606e+01;
		
		asali_->thermo_[447].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[447].name,"C5H4O2");

		asali_->thermo_[447].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[447].high[0] = 1.0515895844e+01;
		asali_->thermo_[447].high[1] = 2.2322423756e-02;
		asali_->thermo_[447].high[2] = -1.0926709365e-05;
		asali_->thermo_[447].high[3] = 2.5668323023e-09;
		asali_->thermo_[447].high[4] = -2.3484499393e-13;
		asali_->thermo_[447].high[5] = -2.3330322266e+04;
		asali_->thermo_[447].high[6] = -2.9400037766e+01;

		asali_->thermo_[447].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[447].low[0] = -1.8199664354e+00;
		asali_->thermo_[447].low[1] = 5.6828331202e-02;
		asali_->thermo_[447].low[2] = -4.7121720854e-05;
		asali_->thermo_[447].low[3] = 1.9440962618e-08;
		asali_->thermo_[447].low[4] = -3.1848677341e-12;
		asali_->thermo_[447].low[5] = -1.9802265625e+04;
		asali_->thermo_[447].low[6] = 3.4525592804e+01;
		
		asali_->thermo_[448].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[448].name,"C5H8O4");

		asali_->thermo_[448].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[448].high[0] = 1.1960153580e+01;
		asali_->thermo_[448].high[1] = 3.9945084602e-02;
		asali_->thermo_[448].high[2] = -1.9594737751e-05;
		asali_->thermo_[448].high[3] = 4.6094013051e-09;
		asali_->thermo_[448].high[4] = -4.2230230272e-13;
		asali_->thermo_[448].high[5] = -8.2638585938e+04;
		asali_->thermo_[448].high[6] = -2.9187520981e+01;

		asali_->thermo_[448].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[448].low[0] = -6.9568324089e+00;
		asali_->thermo_[448].low[1] = 1.0146373510e-01;
		asali_->thermo_[448].low[2] = -9.4617484137e-05;
		asali_->thermo_[448].low[3] = 4.5272138038e-08;
		asali_->thermo_[448].low[4] = -8.6870857730e-12;
		asali_->thermo_[448].low[5] = -7.7985007812e+04;
		asali_->thermo_[448].low[6] = 6.5992088318e+01;
		
		asali_->thermo_[449].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[449].name,"C6H6O3");

		asali_->thermo_[449].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[449].high[0] = 1.9863807678e+01;
		asali_->thermo_[449].high[1] = 1.7933500931e-02;
		asali_->thermo_[449].high[2] = -5.9540884649e-06;
		asali_->thermo_[449].high[3] = 8.9359392108e-10;
		asali_->thermo_[449].high[4] = -4.9545989463e-14;
		asali_->thermo_[449].high[5] = -4.9526484375e+04;
		asali_->thermo_[449].high[6] = -7.4449668884e+01;

		asali_->thermo_[449].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[449].low[0] = 7.1071857214e-01;
		asali_->thermo_[449].low[1] = 6.1217319220e-02;
		asali_->thermo_[449].low[2] = -4.2635288992e-05;
		asali_->thermo_[449].low[3] = 1.4709488738e-08;
		asali_->thermo_[449].low[4] = -2.0009434647e-12;
		asali_->thermo_[449].low[5] = -4.2746289062e+04;
		asali_->thermo_[449].low[6] = 2.8888935089e+01;
		
		asali_->thermo_[450].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[450].name,"C6H8O4");

		asali_->thermo_[450].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[450].high[0] = 1.5807371140e+01;
		asali_->thermo_[450].high[1] = 3.7799887359e-02;
		asali_->thermo_[450].high[2] = -1.7724130885e-05;
		asali_->thermo_[450].high[3] = 3.9756011816e-09;
		asali_->thermo_[450].high[4] = -3.4900985639e-13;
		asali_->thermo_[450].high[5] = -7.7878843750e+04;
		asali_->thermo_[450].high[6] = -5.1512832642e+01;

		asali_->thermo_[450].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[450].low[0] = -4.5549383163e+00;
		asali_->thermo_[450].low[1] = 1.0045314580e-01;
		asali_->thermo_[450].low[2] = -9.0016350441e-05;
		asali_->thermo_[450].low[3] = 4.1048537014e-08;
		asali_->thermo_[450].low[4] = -7.4784206605e-12;
		asali_->thermo_[450].low[5] = -7.2584648438e+04;
		asali_->thermo_[450].low[6] = 5.2065879822e+01;
		
		asali_->thermo_[451].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[451].name,"C6H10O5");

		asali_->thermo_[451].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[451].high[0] = 1.5488971710e+01;
		asali_->thermo_[451].high[1] = 4.9635440111e-02;
		asali_->thermo_[451].high[2] = -2.4594450224e-05;
		asali_->thermo_[451].high[3] = 5.8233258216e-09;
		asali_->thermo_[451].high[4] = -5.3566585846e-13;
		asali_->thermo_[451].high[5] = -1.0918050781e+05;
		asali_->thermo_[451].high[6] = -4.8181983948e+01;

		asali_->thermo_[451].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[451].low[0] = -7.9511647224e+00;
		asali_->thermo_[451].low[1] = 1.2648834288e-01;
		asali_->thermo_[451].low[2] = -1.1908572924e-04;
		asali_->thermo_[451].low[3] = 5.7457903324e-08;
		asali_->thermo_[451].low[4] = -1.1116521766e-11;
		asali_->thermo_[451].low[5] = -1.0346111719e+05;
		asali_->thermo_[451].low[6] = 6.9564216614e+01;
		
		asali_->thermo_[452].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[452].name,"C8H10O3");

		asali_->thermo_[452].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[452].high[0] = 2.9895751953e+01;
		asali_->thermo_[452].high[1] = 4.7387052327e-02;
		asali_->thermo_[452].high[2] = -2.1160321921e-05;
		asali_->thermo_[452].high[3] = 4.6035038004e-09;
		asali_->thermo_[452].high[4] = -3.9634910480e-13;
		asali_->thermo_[452].high[5] = -7.0211945312e+04;
		asali_->thermo_[452].high[6] = -1.2116068268e+02;

		asali_->thermo_[452].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[452].low[0] = -3.0934867859e+00;
		asali_->thermo_[452].low[1] = 1.5047842264e-01;
		asali_->thermo_[452].low[2] = -1.4197052224e-04;
		asali_->thermo_[452].low[3] = 6.7525483871e-08;
		asali_->thermo_[452].low[4] = -1.2685798592e-11;
		asali_->thermo_[452].low[5] = -6.1766703125e+04;
		asali_->thermo_[452].low[6] = 4.6137050629e+01;
		
		asali_->thermo_[453].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[453].name,"C9H10O2");

		asali_->thermo_[453].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[453].high[0] = 2.6404878616e+01;
		asali_->thermo_[453].high[1] = 2.8490312397e-02;
		asali_->thermo_[453].high[2] = -1.0328936696e-05;
		asali_->thermo_[453].high[3] = 1.7860761758e-09;
		asali_->thermo_[453].high[4] = -1.2228042743e-13;
		asali_->thermo_[453].high[5] = -3.7143949219e+04;
		asali_->thermo_[453].high[6] = -1.1077056122e+02;

		asali_->thermo_[453].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[453].low[0] = -2.0433101654e+00;
		asali_->thermo_[453].low[1] = 9.8732754588e-02;
		asali_->thermo_[453].low[2] = -7.5368232501e-05;
		asali_->thermo_[453].low[3] = 2.8551218278e-08;
		asali_->thermo_[453].low[4] = -4.2527036580e-12;
		asali_->thermo_[453].low[5] = -2.7926738281e+04;
		asali_->thermo_[453].low[6] = 4.0199649811e+01;
		
		asali_->thermo_[454].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[454].name,"C11H12O4");

		asali_->thermo_[454].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[454].high[0] = 2.9895751953e+01;
		asali_->thermo_[454].high[1] = 4.7387052327e-02;
		asali_->thermo_[454].high[2] = -2.1160321921e-05;
		asali_->thermo_[454].high[3] = 4.6035038004e-09;
		asali_->thermo_[454].high[4] = -3.9634910480e-13;
		asali_->thermo_[454].high[5] = -7.0211945312e+04;
		asali_->thermo_[454].high[6] = -1.2116068268e+02;

		asali_->thermo_[454].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[454].low[0] = -3.0934867859e+00;
		asali_->thermo_[454].low[1] = 1.5047842264e-01;
		asali_->thermo_[454].low[2] = -1.4197052224e-04;
		asali_->thermo_[454].low[3] = 6.7525483871e-08;
		asali_->thermo_[454].low[4] = -1.2685798592e-11;
		asali_->thermo_[454].low[5] = -6.1766703125e+04;
		asali_->thermo_[454].low[6] = 4.6137050629e+01;
		
		asali_->thermo_[455].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[455].name,"C4H3O");

		asali_->thermo_[455].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[455].high[0] = 8.4412593842e+00;
		asali_->thermo_[455].high[1] = 1.6291113570e-02;
		asali_->thermo_[455].high[2] = -8.3412642198e-06;
		asali_->thermo_[455].high[3] = 2.0143675616e-09;
		asali_->thermo_[455].high[4] = -1.8739460125e-13;
		asali_->thermo_[455].high[5] = 1.9453578125e+04;
		asali_->thermo_[455].high[6] = -2.2785507202e+01;

		asali_->thermo_[455].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[455].low[0] = -5.9087224007e+00;
		asali_->thermo_[455].low[1] = 6.2581375241e-02;
		asali_->thermo_[455].low[2] = -6.4337553340e-05;
		asali_->thermo_[455].low[3] = 3.2119896076e-08;
		asali_->thermo_[455].low[4] = -6.2570578059e-12;
		asali_->thermo_[455].low[5] = 2.3012373047e+04;
		asali_->thermo_[455].low[6] = 4.9531703949e+01;
		
		asali_->thermo_[456].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[456].name,"HCOOH");

		asali_->thermo_[456].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[456].high[0] = 5.8057332039e+00;
		asali_->thermo_[456].high[1] = 6.8201739341e-03;
		asali_->thermo_[456].high[2] = -2.9548061775e-06;
		asali_->thermo_[456].high[3] = 6.1434007881e-10;
		asali_->thermo_[456].high[4] = -5.0675314775e-14;
		asali_->thermo_[456].high[5] = -4.8053441406e+04;
		asali_->thermo_[456].high[6] = -6.4299340248e+00;

		asali_->thermo_[456].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[456].low[0] = 1.3625650406e+00;
		asali_->thermo_[456].low[1] = 1.6693880782e-02;
		asali_->thermo_[456].low[2] = -1.1182894923e-05;
		asali_->thermo_[456].low[3] = 3.6617804344e-09;
		asali_->thermo_[456].low[4] = -4.7393089887e-13;
		asali_->thermo_[456].low[5] = -4.6453902344e+04;
		asali_->thermo_[456].low[6] = 1.7617418289e+01;
		
		asali_->thermo_[457].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[457].name,"ACETOL");

		asali_->thermo_[457].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[457].high[0] = 9.4310655594e+00;
		asali_->thermo_[457].high[1] = 1.8687929958e-02;
		asali_->thermo_[457].high[2] = -7.2928396548e-06;
		asali_->thermo_[457].high[3] = 1.3993257664e-09;
		asali_->thermo_[457].high[4] = -1.0873616731e-13;
		asali_->thermo_[457].high[5] = -4.8739000000e+04;
		asali_->thermo_[457].high[6] = -2.0836048126e+01;

		asali_->thermo_[457].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[457].low[0] = 1.4155313969e+00;
		asali_->thermo_[457].low[1] = 3.6500226706e-02;
		asali_->thermo_[457].low[2] = -2.2136420739e-05;
		asali_->thermo_[457].low[3] = 6.8969487899e-09;
		asali_->thermo_[457].low[4] = -8.7229491208e-13;
		asali_->thermo_[457].low[5] = -4.5853406250e+04;
		asali_->thermo_[457].low[6] = 2.2545694351e+01;
		
		asali_->thermo_[458].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[458].name,"GLYCEROL");

		asali_->thermo_[458].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[458].high[0] = 1.1479648590e+01;
		asali_->thermo_[458].high[1] = 2.3629246280e-02;
		asali_->thermo_[458].high[2] = -8.9838440545e-06;
		asali_->thermo_[458].high[3] = 1.7035514110e-09;
		asali_->thermo_[458].high[4] = -1.3152726250e-13;
		asali_->thermo_[458].high[5] = -7.4178109375e+04;
		asali_->thermo_[458].high[6] = -2.5670728683e+01;

		asali_->thermo_[458].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[458].low[0] = 1.9785080850e-01;
		asali_->thermo_[458].low[1] = 5.8611564338e-02;
		asali_->thermo_[458].low[2] = -4.9660960940e-05;
		asali_->thermo_[458].low[3] = 2.2725316740e-08;
		asali_->thermo_[458].low[4] = -4.2055126742e-12;
		asali_->thermo_[458].low[5] = -7.1267406250e+04;
		asali_->thermo_[458].low[6] = 3.1630247116e+01;
		
		asali_->thermo_[459].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[459].name,"CH2CCHCHO");

		asali_->thermo_[459].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[459].high[0] = 1.0585854530e+01;
		asali_->thermo_[459].high[1] = 1.2995601632e-02;
		asali_->thermo_[459].high[2] = -4.7636126510e-06;
		asali_->thermo_[459].high[3] = 7.4944983552e-10;
		asali_->thermo_[459].high[4] = -3.9684781069e-14;
		asali_->thermo_[459].high[5] = 3.1051335449e+03;
		asali_->thermo_[459].high[6] = -2.9326236725e+01;

		asali_->thermo_[459].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[459].low[0] = 1.0597203970e+00;
		asali_->thermo_[459].low[1] = 3.6960721016e-02;
		asali_->thermo_[459].low[2] = -2.7372214390e-05;
		asali_->thermo_[459].low[3] = 1.0228947467e-08;
		asali_->thermo_[459].low[4] = -1.5301718226e-12;
		asali_->thermo_[459].low[5] = 6.1344443359e+03;
		asali_->thermo_[459].low[6] = 2.1049448013e+01;
		
		asali_->thermo_[460].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[460].name,"KEHYBU1");

		asali_->thermo_[460].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[460].high[0] = 1.5081200600e+01;
		asali_->thermo_[460].high[1] = 2.9974663630e-02;
		asali_->thermo_[460].high[2] = -1.3794408915e-05;
		asali_->thermo_[460].high[3] = 3.0317137689e-09;
		asali_->thermo_[460].high[4] = -2.6093520790e-13;
		asali_->thermo_[460].high[5] = -6.3417808594e+04;
		asali_->thermo_[460].high[6] = -4.2705108643e+01;

		asali_->thermo_[460].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[460].low[0] = -4.5352177620e+00;
		asali_->thermo_[460].low[1] = 9.5362722874e-02;
		asali_->thermo_[460].low[2] = -9.5529481769e-05;
		asali_->thermo_[460].low[3] = 4.8440089273e-08;
		asali_->thermo_[460].low[4] = -9.7210130570e-12;
		asali_->thermo_[460].low[5] = -5.8709871094e+04;
		asali_->thermo_[460].low[6] = 5.5509265900e+01;
		
		asali_->thermo_[461].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[461].name,"RBU1OOX");

		asali_->thermo_[461].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[461].high[0] = 1.4539031982e+01;
		asali_->thermo_[461].high[1] = 2.6979733258e-02;
		asali_->thermo_[461].high[2] = -1.0931248653e-05;
		asali_->thermo_[461].high[3] = 2.1260229133e-09;
		asali_->thermo_[461].high[4] = -1.6428466931e-13;
		asali_->thermo_[461].high[5] = -3.5689335938e+04;
		asali_->thermo_[461].high[6] = -4.2261363983e+01;

		asali_->thermo_[461].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[461].low[0] = 3.2623755932e+00;
		asali_->thermo_[461].low[1] = 5.3989689797e-02;
		asali_->thermo_[461].low[2] = -3.5191686038e-05;
		asali_->thermo_[461].low[3] = 1.1810828759e-08;
		asali_->thermo_[461].low[4] = -1.6141058759e-12;
		asali_->thermo_[461].low[5] = -3.1922933594e+04;
		asali_->thermo_[461].low[6] = 1.7924921036e+01;
		
		asali_->thermo_[462].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[462].name,"QBU1OOX");

		asali_->thermo_[462].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[462].high[0] = 9.4468050003e+00;
		asali_->thermo_[462].high[1] = 1.4089082368e-02;
		asali_->thermo_[462].high[2] = -6.7066857810e-06;
		asali_->thermo_[462].high[3] = 1.5128868158e-09;
		asali_->thermo_[462].high[4] = -1.3281857439e-13;
		asali_->thermo_[462].high[5] = 1.9133291016e+04;
		asali_->thermo_[462].high[6] = -2.8181293488e+01;

		asali_->thermo_[462].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[462].low[0] = -5.8886189461e+00;
		asali_->thermo_[462].low[1] = 6.2389627099e-02;
		asali_->thermo_[462].low[2] = -6.3754574512e-05;
		asali_->thermo_[462].low[3] = 3.1459286731e-08;
		asali_->thermo_[462].low[4] = -6.0277789704e-12;
		asali_->thermo_[462].low[5] = 2.3028488281e+04;
		asali_->thermo_[462].low[6] = 4.9468685150e+01;
		
		asali_->thermo_[463].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[463].name,"ZBU1OOX");

		asali_->thermo_[463].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[463].high[0] = 1.7150997162e+01;
		asali_->thermo_[463].high[1] = 3.2164297998e-02;
		asali_->thermo_[463].high[2] = -1.4526524865e-05;
		asali_->thermo_[463].high[3] = 3.1605598139e-09;
		asali_->thermo_[463].high[4] = -2.7108989966e-13;
		asali_->thermo_[463].high[5] = -4.8716796875e+04;
		asali_->thermo_[463].high[6] = -4.9452167511e+01;

		asali_->thermo_[463].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[463].low[0] = 4.9092903137e+00;
		asali_->thermo_[463].low[1] = 6.6892549396e-02;
		asali_->thermo_[463].low[2] = -5.1471466577e-05;
		asali_->thermo_[463].low[3] = 2.0628618813e-08;
		asali_->thermo_[463].low[4] = -3.3682633505e-12;
		asali_->thermo_[463].low[5] = -4.5264636719e+04;
		asali_->thermo_[463].low[6] = 1.3813116074e+01;
		
		asali_->thermo_[464].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[464].name,"DMF");

		asali_->thermo_[464].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[464].high[0] = 1.3888950348e+01;
		asali_->thermo_[464].high[1] = 2.4973692372e-02;
		asali_->thermo_[464].high[2] = -8.9842105808e-06;
		asali_->thermo_[464].high[3] = 1.4273824345e-09;
		asali_->thermo_[464].high[4] = -7.9771794368e-14;
		asali_->thermo_[464].high[5] = -2.2087203125e+04;
		asali_->thermo_[464].high[6] = -4.9404109955e+01;

		asali_->thermo_[464].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[464].low[0] = -2.3153316975e+00;
		asali_->thermo_[464].low[1] = 6.5739184618e-02;
		asali_->thermo_[464].low[2] = -4.7442219511e-05;
		asali_->thermo_[464].low[3] = 1.7552334697e-08;
		asali_->thermo_[464].low[4] = -2.6151416102e-12;
		asali_->thermo_[464].low[5] = -1.6934242188e+04;
		asali_->thermo_[464].low[6] = 3.6286663055e+01;
		
		asali_->thermo_[465].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[465].name,"DMF-3YL");

		asali_->thermo_[465].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[465].high[0] = 1.4170339584e+01;
		asali_->thermo_[465].high[1] = 2.1823009476e-02;
		asali_->thermo_[465].high[2] = -7.6951137089e-06;
		asali_->thermo_[465].high[3] = 1.1789129672e-09;
		asali_->thermo_[465].high[4] = -6.1237663161e-14;
		asali_->thermo_[465].high[5] = 1.1955779297e+04;
		asali_->thermo_[465].high[6] = -4.8658348083e+01;

		asali_->thermo_[465].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[465].low[0] = -1.1230798960e+00;
		asali_->thermo_[465].low[1] = 5.9584539384e-02;
		asali_->thermo_[465].low[2] = -4.2659492465e-05;
		asali_->thermo_[465].low[3] = 1.5567545475e-08;
		asali_->thermo_[465].low[4] = -2.2817058572e-12;
		asali_->thermo_[465].low[5] = 1.6910847656e+04;
		asali_->thermo_[465].low[6] = 3.2501502991e+01;
		
		asali_->thermo_[466].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[466].name,"MEFU2");

		asali_->thermo_[466].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[466].high[0] = 5.1639819145e+00;
		asali_->thermo_[466].high[1] = 3.2952908427e-02;
		asali_->thermo_[466].high[2] = -1.6820918972e-05;
		asali_->thermo_[466].high[3] = 4.0371603838e-09;
		asali_->thermo_[466].high[4] = -3.5551135603e-13;
		asali_->thermo_[466].high[5] = -1.3184166992e+04;
		asali_->thermo_[466].high[6] = -2.6761670113e+00;

		asali_->thermo_[466].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[466].low[0] = -3.7414979935e+00;
		asali_->thermo_[466].low[1] = 6.1224270612e-02;
		asali_->thermo_[466].low[2] = -5.0477305194e-05;
		asali_->thermo_[466].low[3] = 2.1844771325e-08;
		asali_->thermo_[466].low[4] = -3.8887677800e-12;
		asali_->thermo_[466].low[5] = -1.0939986328e+04;
		asali_->thermo_[466].low[6] = 4.2345787048e+01;
		
		asali_->thermo_[467].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[467].name,"C4H4O");

		asali_->thermo_[467].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[467].high[0] = 8.3748645782e+00;
		asali_->thermo_[467].high[1] = 1.9563445821e-02;
		asali_->thermo_[467].high[2] = -9.9016715467e-06;
		asali_->thermo_[467].high[3] = 2.3769437529e-09;
		asali_->thermo_[467].high[4] = -2.2051769590e-13;
		asali_->thermo_[467].high[5] = -9.4181757812e+03;
		asali_->thermo_[467].high[6] = -2.5205337524e+01;

		asali_->thermo_[467].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[467].low[0] = -7.5950779915e+00;
		asali_->thermo_[467].low[1] = 7.0667259395e-02;
		asali_->thermo_[467].low[2] = -7.1226248110e-05;
		asali_->thermo_[467].low[3] = 3.5083385086e-08;
		asali_->thermo_[467].low[4] = -6.7618059589e-12;
		asali_->thermo_[467].low[5] = -5.4256899414e+03;
		asali_->thermo_[467].low[6] = 5.5403991699e+01;
		
		asali_->thermo_[468].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[468].name,"ETC3H4O2");

		asali_->thermo_[468].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[468].high[0] = 1.0292042732e+01;
		asali_->thermo_[468].high[1] = 1.3887129724e-02;
		asali_->thermo_[468].high[2] = -6.1256200752e-06;
		asali_->thermo_[468].high[3] = 1.3054884951e-09;
		asali_->thermo_[468].high[4] = -1.0996576777e-13;
		asali_->thermo_[468].high[5] = -3.5702699219e+04;
		asali_->thermo_[468].high[6] = -2.6935003281e+01;

		asali_->thermo_[468].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[468].low[0] = 1.1737804860e-01;
		asali_->thermo_[468].low[1] = 4.6708628535e-02;
		asali_->thermo_[468].low[2] = -4.5829045121e-05;
		asali_->thermo_[468].low[3] = 2.2651416742e-08;
		asali_->thermo_[468].low[4] = -4.4135801784e-12;
		asali_->thermo_[468].low[5] = -3.3179382812e+04;
		asali_->thermo_[468].low[6] = 2.4340559006e+01;
		
		asali_->thermo_[469].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[469].name,"KEA3B3");

		asali_->thermo_[469].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[469].high[0] = 1.5649549484e+01;
		asali_->thermo_[469].high[1] = 1.4790471643e-02;
		asali_->thermo_[469].high[2] = -6.8403242039e-06;
		asali_->thermo_[469].high[3] = 1.4916714530e-09;
		asali_->thermo_[469].high[4] = -1.2683037671e-13;
		asali_->thermo_[469].high[5] = -4.7421312500e+04;
		asali_->thermo_[469].high[6] = -4.9248271942e+01;

		asali_->thermo_[469].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[469].low[0] = 1.4190566540e+00;
		asali_->thermo_[469].low[1] = 5.2738454193e-02;
		asali_->thermo_[469].low[2] = -4.4788306695e-05;
		asali_->thermo_[469].low[3] = 1.8357441789e-08;
		asali_->thermo_[469].low[4] = -2.9377919368e-12;
		asali_->thermo_[469].low[5] = -4.3152164062e+04;
		asali_->thermo_[469].low[6] = 2.5175598145e+01;
		
		asali_->thermo_[470].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[470].name,"KEA3G2");

		asali_->thermo_[470].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[470].high[0] = 1.5297293663e+01;
		asali_->thermo_[470].high[1] = 1.4750747941e-02;
		asali_->thermo_[470].high[2] = -6.6590760071e-06;
		asali_->thermo_[470].high[3] = 1.4229176726e-09;
		asali_->thermo_[470].high[4] = -1.1902750920e-13;
		asali_->thermo_[470].high[5] = -5.0322894531e+04;
		asali_->thermo_[470].high[6] = -4.7189266205e+01;

		asali_->thermo_[470].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[470].low[0] = 2.7651686668e+00;
		asali_->thermo_[470].low[1] = 4.7301720828e-02;
		asali_->thermo_[470].low[2] = -3.8364571083e-05;
		asali_->thermo_[470].low[3] = 1.5148239996e-08;
		asali_->thermo_[470].low[4] = -2.3471643466e-12;
		asali_->thermo_[470].low[5] = -4.6463000000e+04;
		asali_->thermo_[470].low[6] = 1.8682142258e+01;
		
		asali_->thermo_[471].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[471].name,"RALD3G");

		asali_->thermo_[471].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[471].high[0] = -2.9641218185e+00;
		asali_->thermo_[471].high[1] = 3.8357939571e-02;
		asali_->thermo_[471].high[2] = -2.0858171411e-05;
		asali_->thermo_[471].high[3] = 5.1259356759e-09;
		asali_->thermo_[471].high[4] = -4.7757159555e-13;
		asali_->thermo_[471].high[5] = 1.7202813721e+03;
		asali_->thermo_[471].high[6] = 4.5863491058e+01;

		asali_->thermo_[471].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[471].low[0] = 6.3482651711e+00;
		asali_->thermo_[471].low[1] = 6.2462589704e-03;
		asali_->thermo_[471].low[2] = 2.0665551347e-05;
		asali_->thermo_[471].low[3] = -1.8738273155e-08;
		asali_->thermo_[471].low[4] = 4.6655769526e-12;
		asali_->thermo_[471].low[5] = -4.4019244385e+02;
		asali_->thermo_[471].low[6] = -4.4553717971e-01;
		
		asali_->thermo_[472].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[472].name,"RALD3B");

		asali_->thermo_[472].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[472].high[0] = -6.0801377296e+00;
		asali_->thermo_[472].high[1] = 4.6018008143e-02;
		asali_->thermo_[472].high[2] = -2.6169671401e-05;
		asali_->thermo_[472].high[3] = 6.6538214938e-09;
		asali_->thermo_[472].high[4] = -6.3530533915e-13;
		asali_->thermo_[472].high[5] = -2.1496599121e+03;
		asali_->thermo_[472].high[6] = 5.9095985413e+01;

		asali_->thermo_[472].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[472].low[0] = 7.0407290459e+00;
		asali_->thermo_[472].low[1] = -2.0120427507e-05;
		asali_->thermo_[472].low[2] = 3.4406813938e-05;
		asali_->thermo_[472].low[3] = -2.8771022897e-08;
		asali_->thermo_[472].low[4] = 7.1333008944e-12;
		asali_->thermo_[472].low[5] = -5.1412177734e+03;
		asali_->thermo_[472].low[6] = -5.9238166809e+00;
		
		asali_->thermo_[473].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[473].name,"C3H5CHO");

		asali_->thermo_[473].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[473].high[0] = 9.3656425476e+00;
		asali_->thermo_[473].high[1] = 1.9939469174e-02;
		asali_->thermo_[473].high[2] = -8.2471424321e-06;
		asali_->thermo_[473].high[3] = 1.6384090751e-09;
		asali_->thermo_[473].high[4] = -1.2918188925e-13;
		asali_->thermo_[473].high[5] = -1.4429366211e+04;
		asali_->thermo_[473].high[6] = -2.0705400467e+01;

		asali_->thermo_[473].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[473].low[0] = 2.4047477543e-01;
		asali_->thermo_[473].low[1] = 4.2610693723e-02;
		asali_->thermo_[473].low[2] = -2.9369401091e-05;
		asali_->thermo_[473].low[3] = 1.0384686000e-08;
		asali_->thermo_[473].low[4] = -1.4872994329e-12;
		asali_->thermo_[473].low[5] = -1.1491062500e+04;
		asali_->thermo_[473].low[6] = 2.7663976669e+01;
		
		asali_->thermo_[474].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[474].name,"C7DIONE");

		asali_->thermo_[474].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[474].high[0] = -7.5585359335e-01;
		asali_->thermo_[474].high[1] = 8.2453608513e-02;
		asali_->thermo_[474].high[2] = -4.5882465201e-05;
		asali_->thermo_[474].high[3] = 1.1827499868e-08;
		asali_->thermo_[474].high[4] = -1.1580793833e-12;
		asali_->thermo_[474].high[5] = -3.6754679688e+04;
		asali_->thermo_[474].high[6] = 2.6472248077e+01;

		asali_->thermo_[474].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[474].low[0] = 3.5218038559e+00;
		asali_->thermo_[474].low[1] = 5.8009855449e-02;
		asali_->thermo_[474].low[2] = 6.4970136009e-06;
		asali_->thermo_[474].low[3] = -3.8057720531e-08;
		asali_->thermo_[474].low[4] = 1.6658070756e-11;
		asali_->thermo_[474].low[5] = -3.7353550781e+04;
		asali_->thermo_[474].low[6] = 7.3607559204e+00;
		
		asali_->thermo_[475].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[475].name,"C7KETONE");

		asali_->thermo_[475].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[475].high[0] = 1.8299427032e+01;
		asali_->thermo_[475].high[1] = 4.1439358145e-02;
		asali_->thermo_[475].high[2] = -1.7183416276e-05;
		asali_->thermo_[475].high[3] = 3.4271427918e-09;
		asali_->thermo_[475].high[4] = -2.7203735683e-13;
		asali_->thermo_[475].high[5] = -4.2784878906e+04;
		asali_->thermo_[475].high[6] = -6.5978584290e+01;

		asali_->thermo_[475].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[475].low[0] = -2.2923627496e-01;
		asali_->thermo_[475].low[1] = 8.2614168525e-02;
		asali_->thermo_[475].low[2] = -5.1495757361e-05;
		asali_->thermo_[475].low[3] = 1.6135416558e-08;
		asali_->thermo_[475].low[4] = -2.0370753695e-12;
		asali_->thermo_[475].low[5] = -3.6114562500e+04;
		asali_->thermo_[475].low[6] = 3.4302410126e+01;
		
		asali_->thermo_[476].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[476].name,"CH2OOHCHCHO");

		asali_->thermo_[476].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[476].high[0] = 1.8481669426e+00;
		asali_->thermo_[476].high[1] = 3.9904262871e-02;
		asali_->thermo_[476].high[2] = -2.3894770493e-05;
		asali_->thermo_[476].high[3] = 6.4885008477e-09;
		asali_->thermo_[476].high[4] = -6.5762830294e-13;
		asali_->thermo_[476].high[5] = -1.4899197266e+04;
		asali_->thermo_[476].high[6] = 2.1534049988e+01;

		asali_->thermo_[476].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[476].low[0] = 5.4432668686e+00;
		asali_->thermo_[476].low[1] = 1.9360834733e-02;
		asali_->thermo_[476].low[2] = 2.0126859454e-05;
		asali_->thermo_[476].low[3] = -3.5436858781e-08;
		asali_->thermo_[476].low[4] = 1.4315715280e-11;
		asali_->thermo_[476].low[5] = -1.5402511719e+04;
		asali_->thermo_[476].low[6] = 5.4720540047e+00;
		
		asali_->thermo_[477].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[477].name,"CH2OOCH2CHO");

		asali_->thermo_[477].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[477].high[0] = 1.0699853897e+01;
		asali_->thermo_[477].high[1] = 2.4279309437e-02;
		asali_->thermo_[477].high[2] = -1.3409721760e-05;
		asali_->thermo_[477].high[3] = 3.4267397808e-09;
		asali_->thermo_[477].high[4] = -3.3215953859e-13;
		asali_->thermo_[477].high[5] = -2.1412666016e+04;
		asali_->thermo_[477].high[6] = -2.4850879669e+01;

		asali_->thermo_[477].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[477].low[0] = 2.9300925732e+00;
		asali_->thermo_[477].low[1] = 4.1545446962e-02;
		asali_->thermo_[477].low[2] = -2.7798168958e-05;
		asali_->thermo_[477].low[3] = 8.7557943118e-09;
		asali_->thermo_[477].low[4] = -1.0723059810e-12;
		asali_->thermo_[477].low[5] = -1.8615550781e+04;
		asali_->thermo_[477].low[6] = 1.7200689316e+01;
		
		asali_->thermo_[478].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[478].name,"CH2CHOOHCHO");

		asali_->thermo_[478].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[478].high[0] = 1.0915441513e+01;
		asali_->thermo_[478].high[1] = 2.1106926724e-02;
		asali_->thermo_[478].high[2] = -1.0434790056e-05;
		asali_->thermo_[478].high[3] = 2.4363315809e-09;
		asali_->thermo_[478].high[4] = -2.2022494776e-13;
		asali_->thermo_[478].high[5] = -1.3544634766e+04;
		asali_->thermo_[478].high[6] = -2.4246845245e+01;

		asali_->thermo_[478].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[478].low[0] = 1.8110135794e+00;
		asali_->thermo_[478].low[1] = 4.9120549113e-02;
		asali_->thermo_[478].low[2] = -4.2758201744e-05;
		asali_->thermo_[478].low[3] = 1.9012439623e-08;
		asali_->thermo_[478].low[4] = -3.4079379943e-12;
		asali_->thermo_[478].low[5] = -1.1177484375e+04;
		asali_->thermo_[478].low[6] = 2.2065431595e+01;
		
		asali_->thermo_[479].name = (char*) malloc(10 * sizeof(char));
		strcpy(asali_->thermo_[479].name,"CH3CHOOCHO");

		asali_->thermo_[479].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[479].high[0] = 1.5877165794e+01;
		asali_->thermo_[479].high[1] = 1.2869961560e-02;
		asali_->thermo_[479].high[2] = -5.2970340221e-06;
		asali_->thermo_[479].high[3] = 1.0400195150e-09;
		asali_->thermo_[479].high[4] = -8.1248714896e-14;
		asali_->thermo_[479].high[5] = -2.3888763672e+04;
		asali_->thermo_[479].high[6] = -5.4466659546e+01;

		asali_->thermo_[479].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[479].low[0] = 3.3830120564e+00;
		asali_->thermo_[479].low[1] = 4.0634747595e-02;
		asali_->thermo_[479].low[2] = -2.8434355045e-05;
		asali_->thermo_[479].low[3] = 9.6093977220e-09;
		asali_->thermo_[479].low[4] = -1.2714402014e-12;
		asali_->thermo_[479].low[5] = -1.9390867188e+04;
		asali_->thermo_[479].low[6] = 1.3154307365e+01;
		
		asali_->thermo_[480].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->thermo_[480].name,"CH2OOHCHOOCHO");

		asali_->thermo_[480].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[480].high[0] = 2.1454919815e+01;
		asali_->thermo_[480].high[1] = 1.0825640522e-02;
		asali_->thermo_[480].high[2] = -3.7539327877e-06;
		asali_->thermo_[480].high[3] = 5.8801402636e-10;
		asali_->thermo_[480].high[4] = -3.4728296627e-14;
		asali_->thermo_[480].high[5] = -3.5990019531e+04;
		asali_->thermo_[480].high[6] = -7.9355987549e+01;

		asali_->thermo_[480].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[480].low[0] = 5.4119167328e+00;
		asali_->thermo_[480].low[1] = 4.6476759017e-02;
		asali_->thermo_[480].low[2] = -3.3463194995e-05;
		asali_->thermo_[480].low[3] = 1.1591445137e-08;
		asali_->thermo_[480].low[4] = -1.5629825992e-12;
		asali_->thermo_[480].low[5] = -3.0214541016e+04;
		asali_->thermo_[480].low[6] = 7.4720883369e+00;
		
		asali_->thermo_[481].name = (char*) malloc(13 * sizeof(char));
		strcpy(asali_->thermo_[481].name,"CH2OOCHOOHCHO");

		asali_->thermo_[481].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[481].high[0] = 2.1454919815e+01;
		asali_->thermo_[481].high[1] = 1.0825640522e-02;
		asali_->thermo_[481].high[2] = -3.7539327877e-06;
		asali_->thermo_[481].high[3] = 5.8801402636e-10;
		asali_->thermo_[481].high[4] = -3.4728296627e-14;
		asali_->thermo_[481].high[5] = -3.5990019531e+04;
		asali_->thermo_[481].high[6] = -7.9355987549e+01;

		asali_->thermo_[481].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[481].low[0] = 5.4119167328e+00;
		asali_->thermo_[481].low[1] = 4.6476759017e-02;
		asali_->thermo_[481].low[2] = -3.3463194995e-05;
		asali_->thermo_[481].low[3] = 1.1591445137e-08;
		asali_->thermo_[481].low[4] = -1.5629825992e-12;
		asali_->thermo_[481].low[5] = -3.0214541016e+04;
		asali_->thermo_[481].low[6] = 7.4720883369e+00;
		
		asali_->thermo_[482].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[482].name,"ERC4H8CHO");

		asali_->thermo_[482].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[482].high[0] = -3.0481305718e-01;
		asali_->thermo_[482].high[1] = 5.6797750294e-02;
		asali_->thermo_[482].high[2] = -3.2405765523e-05;
		asali_->thermo_[482].high[3] = 8.5047195952e-09;
		asali_->thermo_[482].high[4] = -8.4176329102e-13;
		asali_->thermo_[482].high[5] = -5.2142050781e+03;
		asali_->thermo_[482].high[6] = 3.4193325043e+01;

		asali_->thermo_[482].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[482].low[0] = 6.2252531052e+00;
		asali_->thermo_[482].low[1] = 2.1970730275e-02;
		asali_->thermo_[482].low[2] = 3.7248275476e-05;
		asali_->thermo_[482].low[3] = -5.3409983991e-08;
		asali_->thermo_[482].low[4] = 1.9796471754e-11;
		asali_->thermo_[482].low[5] = -6.1937148438e+03;
		asali_->thermo_[482].low[6] = 4.5681133270e+00;
	}
}
