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
		asali_->thermo_ = (struct thermoParameters*) malloc(134 * sizeof(struct thermoParameters));
		
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
		
		
		asali_->thermo_[7].name = (char*) malloc(9 * sizeof(char));
		strcpy(asali_->thermo_[7].name,"C6H5CH2OH");

		asali_->thermo_[7].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[7].high[0] = 1.2581844330e+01;
		asali_->thermo_[7].high[1] = 2.6413451880e-02;
		asali_->thermo_[7].high[2] = -7.9379988165e-06;
		asali_->thermo_[7].high[3] = 4.3836823060e-10;
		asali_->thermo_[7].high[4] = 8.6407897710e-14;
		asali_->thermo_[7].high[5] = -1.8782896484e+04;
		asali_->thermo_[7].high[6] = -3.8133232117e+01;

		asali_->thermo_[7].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[7].low[0] = -6.0288496017e+00;
		asali_->thermo_[7].low[1] = 7.7753297985e-02;
		asali_->thermo_[7].low[2] = -6.1048187490e-05;
		asali_->thermo_[7].low[3] = 2.4856843694e-08;
		asali_->thermo_[7].low[4] = -4.1236740585e-12;
		asali_->thermo_[7].low[5] = -1.3385794922e+04;
		asali_->thermo_[7].low[6] = 5.8567665100e+01;
		
		asali_->thermo_[8].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[8].name,"C6H4O2");

		asali_->thermo_[8].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[8].high[0] = 1.7492958069e+01;
		asali_->thermo_[8].high[1] = 1.2902128510e-02;
		asali_->thermo_[8].high[2] = -2.0297663923e-06;
		asali_->thermo_[8].high[3] = -3.7241784656e-10;
		asali_->thermo_[8].high[4] = 8.5974575983e-14;
		asali_->thermo_[8].high[5] = -2.2210046875e+04;
		asali_->thermo_[8].high[6] = -6.4901580811e+01;

		asali_->thermo_[8].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[8].low[0] = -5.2344655991e+00;
		asali_->thermo_[8].low[1] = 7.7377088368e-02;
		asali_->thermo_[8].low[2] = -7.0620146289e-05;
		asali_->thermo_[8].low[3] = 3.2058022015e-08;
		asali_->thermo_[8].low[4] = -5.6641037346e-12;
		asali_->thermo_[8].low[5] = -1.5800912109e+04;
		asali_->thermo_[8].low[6] = 5.2554004669e+01;
		
		asali_->thermo_[9].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[9].name,"C6H6");

		asali_->thermo_[9].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[9].high[0] = 1.5736582756e+01;
		asali_->thermo_[9].high[1] = 1.2444414198e-02;
		asali_->thermo_[9].high[2] = -2.0824247713e-06;
		asali_->thermo_[9].high[3] = -1.9055516887e-10;
		asali_->thermo_[9].high[4] = 5.6093865853e-14;
		asali_->thermo_[9].high[5] = 2.3753884277e+03;
		asali_->thermo_[9].high[6] = -6.6038093567e+01;

		asali_->thermo_[9].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[9].low[0] = -6.3336114883e+00;
		asali_->thermo_[9].low[1] = 6.9399751723e-02;
		asali_->thermo_[9].low[2] = -5.7200497395e-05;
		asali_->thermo_[9].low[3] = 2.3516141923e-08;
		asali_->thermo_[9].low[4] = -3.7675669876e-12;
		asali_->thermo_[9].low[5] = 9.2171484375e+03;
		asali_->thermo_[9].low[6] = 5.0110206604e+01;
		
		asali_->thermo_[10].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[10].name,"C6H5CHO");

		asali_->thermo_[10].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[10].high[0] = 2.7358848572e+01;
		asali_->thermo_[10].high[1] = 2.4572545663e-03;
		asali_->thermo_[10].high[2] = 5.4113033912e-06;
		asali_->thermo_[10].high[3] = -2.5853170715e-09;
		asali_->thermo_[10].high[4] = 3.2164987904e-13;
		asali_->thermo_[10].high[5] = -1.7642955078e+04;
		asali_->thermo_[10].high[6] = -1.2360829163e+02;

		asali_->thermo_[10].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[10].low[0] = -6.5570597649e+00;
		asali_->thermo_[10].low[1] = 7.9103372991e-02;
		asali_->thermo_[10].low[2] = -5.9543035604e-05;
		asali_->thermo_[10].low[3] = 2.1879593248e-08;
		asali_->thermo_[10].low[4] = -3.1338460472e-12;
		asali_->thermo_[10].low[5] = -5.6367226562e+03;
		asali_->thermo_[10].low[6] = 5.9381649017e+01;
		
		asali_->thermo_[11].name = (char*) malloc(12 * sizeof(char));
		strcpy(asali_->thermo_[11].name,"C6H5C2H4C6H5");

		asali_->thermo_[11].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[11].high[0] = 2.2999992371e+01;
		asali_->thermo_[11].high[1] = 5.2355147898e-02;
		asali_->thermo_[11].high[2] = -1.6202304323e-05;
		asali_->thermo_[11].high[3] = 1.0634692016e-09;
		asali_->thermo_[11].high[4] = 1.4874756429e-13;
		asali_->thermo_[11].high[5] = 3.2013186035e+03;
		asali_->thermo_[11].high[6] = -9.1870422363e+01;

		asali_->thermo_[11].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[11].low[0] = -1.0558960915e+01;
		asali_->thermo_[11].low[1] = 1.4557446539e-01;
		asali_->thermo_[11].low[2] = -1.1330575944e-04;
		asali_->thermo_[11].low[3] = 4.6018772792e-08;
		asali_->thermo_[11].low[4] = -7.6559921597e-12;
		asali_->thermo_[11].low[5] = 1.2866297852e+04;
		asali_->thermo_[11].low[6] = 8.2269172668e+01;
		
		asali_->thermo_[12].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[12].name,"NC4H8");

		asali_->thermo_[12].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[12].high[0] = 2.9870982170e+00;
		asali_->thermo_[12].high[1] = 3.2528255135e-02;
		asali_->thermo_[12].high[2] = -1.4625047697e-05;
		asali_->thermo_[12].high[3] = 2.9413638192e-09;
		asali_->thermo_[12].high[4] = -2.1496080740e-13;
		asali_->thermo_[12].high[5] = -2.5011188965e+03;
		asali_->thermo_[12].high[6] = 1.0397191048e+01;

		asali_->thermo_[12].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[12].low[0] = -1.0570777655e+00;
		asali_->thermo_[12].low[1] = 4.6354494989e-02;
		asali_->thermo_[12].low[2] = -3.2350999390e-05;
		asali_->thermo_[12].low[3] = 1.3041621116e-08;
		asali_->thermo_[12].low[4] = -2.3731355422e-12;
		asali_->thermo_[12].low[5] = -1.5547818604e+03;
		asali_->thermo_[12].low[6] = 3.0542951584e+01;
		
		asali_->thermo_[13].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[13].name,"C4H6");

		asali_->thermo_[13].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[13].high[0] = 9.5539531708e+00;
		asali_->thermo_[13].high[1] = 1.5136481263e-02;
		asali_->thermo_[13].high[2] = -4.7850944611e-06;
		asali_->thermo_[13].high[3] = 6.1495536441e-10;
		asali_->thermo_[13].high[4] = -2.2380994017e-14;
		asali_->thermo_[13].high[5] = 8.6328466797e+03;
		asali_->thermo_[13].high[6] = -2.7796669006e+01;

		asali_->thermo_[13].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[13].low[0] = -1.0453385115e+00;
		asali_->thermo_[13].low[1] = 4.2489491403e-02;
		asali_->thermo_[13].low[2] = -3.1255749491e-05;
		asali_->thermo_[13].low[3] = 1.2000183958e-08;
		asali_->thermo_[13].low[4] = -1.8587082828e-12;
		asali_->thermo_[13].low[5] = 1.1918627930e+04;
		asali_->thermo_[13].low[6] = 2.7983980179e+01;
		
		asali_->thermo_[14].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[14].name,"C12H8");

		asali_->thermo_[14].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[14].high[0] = 2.5965219498e+01;
		asali_->thermo_[14].high[1] = 2.4250119925e-02;
		asali_->thermo_[14].high[2] = -4.8141287152e-06;
		asali_->thermo_[14].high[3] = -4.2107872744e-10;
		asali_->thermo_[14].high[4] = 1.4744710444e-13;
		asali_->thermo_[14].high[5] = 1.9077857422e+04;
		asali_->thermo_[14].high[6] = -1.1825495148e+02;

		asali_->thermo_[14].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[14].low[0] = -9.2819910049e+00;
		asali_->thermo_[14].low[1] = 1.2284371257e-01;
		asali_->thermo_[14].low[2] = -1.0823398043e-04;
		asali_->thermo_[14].low[3] = 4.7793303537e-08;
		asali_->thermo_[14].low[4] = -8.2816409980e-12;
		asali_->thermo_[14].low[5] = 2.9158558594e+04;
		asali_->thermo_[14].low[6] = 6.4399482727e+01;
		
		asali_->thermo_[15].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[15].name,"C2H2");

		asali_->thermo_[15].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[15].high[0] = 4.6119360924e+00;
		asali_->thermo_[15].high[1] = 5.0149820745e-03;
		asali_->thermo_[15].high[2] = -1.6525369801e-06;
		asali_->thermo_[15].high[3] = 2.4992252712e-10;
		asali_->thermo_[15].high[4] = -1.3056863804e-14;
		asali_->thermo_[15].high[5] = 2.5604384766e+04;
		asali_->thermo_[15].high[6] = -3.7551710606e+00;

		asali_->thermo_[15].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[15].low[0] = 1.8381215334e+00;
		asali_->thermo_[15].low[1] = 1.6453392804e-02;
		asali_->thermo_[15].low[2] = -1.9340801373e-05;
		asali_->thermo_[15].low[3] = 1.2406804473e-08;
		asali_->thermo_[15].low[4] = -3.1462738231e-12;
		asali_->thermo_[15].low[5] = 2.6142503906e+04;
		asali_->thermo_[15].low[6] = 9.5423927307e+00;
		
		asali_->thermo_[16].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[16].name,"C2H4");

		asali_->thermo_[16].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[16].high[0] = 4.4933366776e+00;
		asali_->thermo_[16].high[1] = 1.0033510625e-02;
		asali_->thermo_[16].high[2] = -3.6260139495e-06;
		asali_->thermo_[16].high[3] = 5.9761351423e-10;
		asali_->thermo_[16].high[4] = -3.6548126586e-14;
		asali_->thermo_[16].high[5] = 3.9322082520e+03;
		asali_->thermo_[16].high[6] = -3.3519201279e+00;

		asali_->thermo_[16].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[16].low[0] = 2.6616171002e-01;
		asali_->thermo_[16].low[1] = 1.9427232444e-02;
		asali_->thermo_[16].low[2] = -1.1454116247e-05;
		asali_->thermo_[16].low[3] = 3.4969105389e-09;
		asali_->thermo_[16].low[4] = -4.3922827072e-13;
		asali_->thermo_[16].low[5] = 5.4539912109e+03;
		asali_->thermo_[16].low[6] = 1.9526432037e+01;
		
		asali_->thermo_[17].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[17].name,"C2H6");

		asali_->thermo_[17].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[17].high[0] = 4.3937349319e+00;
		asali_->thermo_[17].high[1] = 1.5268472955e-02;
		asali_->thermo_[17].high[2] = -5.8272503338e-06;
		asali_->thermo_[17].high[3] = 1.1037708525e-09;
		asali_->thermo_[17].high[4] = -8.6048654096e-14;
		asali_->thermo_[17].high[5] = -1.2726986328e+04;
		asali_->thermo_[17].high[6] = -3.2199749947e+00;

		asali_->thermo_[17].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[17].low[0] = -2.7446129918e-01;
		asali_->thermo_[17].low[1] = 2.5642242283e-02;
		asali_->thermo_[17].low[2] = -1.4472058865e-05;
		asali_->thermo_[17].low[3] = 4.3055514709e-09;
		asali_->thermo_[17].low[4] = -5.3074043641e-13;
		asali_->thermo_[17].low[5] = -1.1046435547e+04;
		asali_->thermo_[17].low[6] = 2.2045276642e+01;
		
		asali_->thermo_[18].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[18].name,"C3H6");

		asali_->thermo_[18].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[18].high[0] = 9.2154922485e+00;
		asali_->thermo_[18].high[1] = 1.1009614915e-02;
		asali_->thermo_[18].high[2] = -2.7216588023e-06;
		asali_->thermo_[18].high[3] = 1.6930111479e-10;
		asali_->thermo_[18].high[4] = 1.2505884119e-14;
		asali_->thermo_[18].high[5] = -2.1502854004e+03;
		asali_->thermo_[18].high[6] = -2.7577322006e+01;

		asali_->thermo_[18].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[18].low[0] = -2.6188677549e-01;
		asali_->thermo_[18].low[1] = 3.2070457935e-02;
		asali_->thermo_[18].low[2] = -2.0272360416e-05;
		asali_->thermo_[18].low[3] = 6.6695609036e-09;
		asali_->thermo_[18].low[4] = -8.9030795540e-13;
		asali_->thermo_[18].low[5] = 1.2615710449e+03;
		asali_->thermo_[18].low[6] = 2.3716228485e+01;
		
		asali_->thermo_[19].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[19].name,"C3H8");

		asali_->thermo_[19].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[19].high[0] = 1.0859636307e+01;
		asali_->thermo_[19].high[1] = 1.3576656580e-02;
		asali_->thermo_[19].high[2] = -3.1992624372e-06;
		asali_->thermo_[19].high[3] = 1.4161580242e-10;
		asali_->thermo_[19].high[4] = 2.3589855723e-14;
		asali_->thermo_[19].high[5] = -1.8088470703e+04;
		asali_->thermo_[19].high[6] = -3.6948692322e+01;

		asali_->thermo_[19].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[19].low[0] = -1.2551271915e+00;
		asali_->thermo_[19].low[1] = 4.0498353541e-02;
		asali_->thermo_[19].low[2] = -2.5634009944e-05;
		asali_->thermo_[19].low[3] = 8.4507814080e-09;
		asali_->thermo_[19].low[4] = -1.1304609592e-12;
		asali_->thermo_[19].low[5] = -1.3727155273e+04;
		asali_->thermo_[19].low[6] = 2.8618936539e+01;
		
		asali_->thermo_[20].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[20].name,"C4H2");

		asali_->thermo_[20].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[20].high[0] = 8.5027580261e+00;
		asali_->thermo_[20].high[1] = 6.9744503126e-03;
		asali_->thermo_[20].high[2] = -2.5329711661e-06;
		asali_->thermo_[20].high[3] = 4.3328776678e-10;
		asali_->thermo_[20].high[4] = -2.9361146896e-14;
		asali_->thermo_[20].high[5] = 5.3172753906e+04;
		asali_->thermo_[20].high[6] = -2.0880794525e+01;

		asali_->thermo_[20].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[20].low[0] = 2.9090785980e+00;
		asali_->thermo_[20].low[1] = 2.8283704072e-02;
		asali_->thermo_[20].low[2] = -3.2974763599e-05;
		asali_->thermo_[20].low[3] = 1.9761410286e-08;
		asali_->thermo_[20].low[4] = -4.6312949135e-12;
		asali_->thermo_[20].low[5] = 5.4347429688e+04;
		asali_->thermo_[20].low[6] = 6.3783917427e+00;
		
		asali_->thermo_[21].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[21].name,"C4H4");

		asali_->thermo_[21].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[21].high[0] = 6.3629360199e+00;
		asali_->thermo_[21].high[1] = 1.6660999507e-02;
		asali_->thermo_[21].high[2] = -7.5422085501e-06;
		asali_->thermo_[21].high[3] = 1.5952142940e-09;
		asali_->thermo_[21].high[4] = -1.2841583266e-13;
		asali_->thermo_[21].high[5] = 3.1313724609e+04;
		asali_->thermo_[21].high[6] = -8.1925525665e+00;

		asali_->thermo_[21].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[21].low[0] = 4.0318486094e-01;
		asali_->thermo_[21].low[1] = 3.6693777889e-02;
		asali_->thermo_[21].low[2] = -3.2793606806e-05;
		asali_->thermo_[21].low[3] = 1.5741656867e-08;
		asali_->thermo_[21].low[4] = -3.1003574274e-12;
		asali_->thermo_[21].low[5] = 3.2732144531e+04;
		asali_->thermo_[21].low[6] = 2.1596519470e+01;
		
		asali_->thermo_[22].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[22].name,"CYC5H4O");

		asali_->thermo_[22].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[22].high[0] = 6.3445959091e+00;
		asali_->thermo_[22].high[1] = 2.3984158412e-02;
		asali_->thermo_[22].high[2] = -8.3275535872e-06;
		asali_->thermo_[22].high[3] = 8.4712764581e-10;
		asali_->thermo_[22].high[4] = 2.8624949904e-14;
		asali_->thermo_[22].high[5] = 3.0865930176e+03;
		asali_->thermo_[22].high[6] = -9.7318153381e+00;

		asali_->thermo_[22].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[22].low[0] = -5.1437935829e+00;
		asali_->thermo_[22].low[1] = 6.0455232859e-02;
		asali_->thermo_[22].low[2] = -5.1745500969e-05;
		asali_->thermo_[22].low[3] = 2.3819588080e-08;
		asali_->thermo_[22].low[4] = -4.5294028944e-12;
		asali_->thermo_[22].low[5] = 5.9816669922e+03;
		asali_->thermo_[22].low[6] = 4.8348121643e+01;
		
		asali_->thermo_[23].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[23].name,"C6H5O");

		asali_->thermo_[23].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[23].high[0] = 1.3442816734e+01;
		asali_->thermo_[23].high[1] = 1.7965873703e-02;
		asali_->thermo_[23].high[2] = -6.6733277890e-06;
		asali_->thermo_[23].high[3] = 1.1223751928e-09;
		asali_->thermo_[23].high[4] = -7.1080951726e-14;
		asali_->thermo_[23].high[5] = 4.0768380737e+02;
		asali_->thermo_[23].high[6] = -4.7250053406e+01;

		asali_->thermo_[23].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[23].low[0] = -4.8070707321e+00;
		asali_->thermo_[23].low[1] = 7.3268562555e-02;
		asali_->thermo_[23].low[2] = -6.9517293014e-05;
		asali_->thermo_[23].low[3] = 3.2861752430e-08;
		asali_->thermo_[23].low[4] = -6.0823264827e-12;
		asali_->thermo_[23].low[5] = 5.2256542969e+03;
		asali_->thermo_[23].low[6] = 4.5861854553e+01;
		
		asali_->thermo_[24].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[24].name,"CYC6H10-ONE");

		asali_->thermo_[24].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[24].high[0] = 1.1596542358e+01;
		asali_->thermo_[24].high[1] = 4.0288794786e-02;
		asali_->thermo_[24].high[2] = -1.8668584744e-05;
		asali_->thermo_[24].high[3] = 4.1556842412e-09;
		asali_->thermo_[24].high[4] = -3.6403071855e-13;
		asali_->thermo_[24].high[5] = -3.6222148438e+04;
		asali_->thermo_[24].high[6] = -4.2746845245e+01;

		asali_->thermo_[24].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[24].low[0] = -6.4649038315e+00;
		asali_->thermo_[24].low[1] = 8.0425344408e-02;
		asali_->thermo_[24].low[2] = -5.2115708968e-05;
		asali_->thermo_[24].low[3] = 1.6543507897e-08;
		asali_->thermo_[24].low[4] = -2.0845616899e-12;
		asali_->thermo_[24].low[5] = -2.9720029297e+04;
		asali_->thermo_[24].low[6] = 5.5005474091e+01;
		
		asali_->thermo_[25].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[25].name,"CYC5H8");

		asali_->thermo_[25].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[25].high[0] = 8.4309988022e+00;
		asali_->thermo_[25].high[1] = 2.7108270675e-02;
		asali_->thermo_[25].high[2] = -1.0793286492e-05;
		asali_->thermo_[25].high[3] = 1.9538766161e-09;
		asali_->thermo_[25].high[4] = -1.3111117281e-13;
		asali_->thermo_[25].high[5] = -1.0986253662e+03;
		asali_->thermo_[25].high[6] = -2.3760845184e+01;

		asali_->thermo_[25].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[25].low[0] = -6.5686397552e+00;
		asali_->thermo_[25].low[1] = 6.8203173578e-02;
		asali_->thermo_[25].low[2] = -5.3014075093e-05;
		asali_->thermo_[25].low[3] = 2.1232775538e-08;
		asali_->thermo_[25].low[4] = -3.4322924277e-12;
		asali_->thermo_[25].low[5] = 3.2812692871e+03;
		asali_->thermo_[25].low[6] = 5.4280151367e+01;
		
		asali_->thermo_[26].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[26].name,"CYC6H8");

		asali_->thermo_[26].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[26].high[0] = 8.6677227020e+00;
		asali_->thermo_[26].high[1] = 3.4507486969e-02;
		asali_->thermo_[26].high[2] = -1.6384678020e-05;
		asali_->thermo_[26].high[3] = 3.6926097735e-09;
		asali_->thermo_[26].high[4] = -3.2442101848e-13;
		asali_->thermo_[26].high[5] = 5.7402211914e+03;
		asali_->thermo_[26].high[6] = -2.7356620789e+01;

		asali_->thermo_[26].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[26].low[0] = -6.9135813713e+00;
		asali_->thermo_[26].low[1] = 7.6336488128e-02;
		asali_->thermo_[26].low[2] = -5.8494413679e-05;
		asali_->thermo_[26].low[3] = 2.2533654942e-08;
		asali_->thermo_[26].low[4] = -3.4856700859e-12;
		asali_->thermo_[26].low[5] = 1.0383450195e+04;
		asali_->thermo_[26].low[6] = 5.4027614594e+01;
		
		asali_->thermo_[27].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[27].name,"CYC6H12");

		asali_->thermo_[27].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[27].high[0] = 1.1257809639e+01;
		asali_->thermo_[27].high[1] = 4.3435409665e-02;
		asali_->thermo_[27].high[2] = -2.0245577616e-05;
		asali_->thermo_[27].high[3] = 4.5424530803e-09;
		asali_->thermo_[27].high[4] = -4.0119516325e-13;
		asali_->thermo_[27].high[5] = -2.3043996094e+04;
		asali_->thermo_[27].high[6] = -4.4786338806e+01;

		asali_->thermo_[27].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[27].low[0] = -9.4336309433e+00;
		asali_->thermo_[27].low[1] = 8.9416392148e-02;
		asali_->thermo_[27].low[2] = -5.8563062339e-05;
		asali_->thermo_[27].low[3] = 1.8734112928e-08;
		asali_->thermo_[27].low[4] = -2.3722590732e-12;
		asali_->thermo_[27].low[5] = -1.5595077148e+04;
		asali_->thermo_[27].low[6] = 6.7200057983e+01;
		
		asali_->thermo_[28].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[28].name,"CYC6H10");

		asali_->thermo_[28].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[28].high[0] = 1.5162486076e+01;
		asali_->thermo_[28].high[1] = 2.7636000887e-02;
		asali_->thermo_[28].high[2] = -1.0525985999e-05;
		asali_->thermo_[28].high[3] = 1.8958636883e-09;
		asali_->thermo_[28].high[4] = -1.3505476848e-13;
		asali_->thermo_[28].high[5] = -9.2998525391e+03;
		asali_->thermo_[28].high[6] = -6.2506454468e+01;

		asali_->thermo_[28].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[28].low[0] = -6.0151767731e+00;
		asali_->thermo_[28].low[1] = 7.4697472155e-02;
		asali_->thermo_[28].low[2] = -4.9743877753e-05;
		asali_->thermo_[28].low[3] = 1.6421008553e-08;
		asali_->thermo_[28].low[4] = -2.1524362154e-12;
		asali_->thermo_[28].low[5] = -1.6758940430e+03;
		asali_->thermo_[28].low[6] = 5.2111469269e+01;
		
		asali_->thermo_[29].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[29].name,"CH2CO");

		asali_->thermo_[29].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[29].high[0] = 6.0357880592e+00;
		asali_->thermo_[29].high[1] = 5.8172242716e-03;
		asali_->thermo_[29].high[2] = -1.9320650608e-06;
		asali_->thermo_[29].high[3] = 2.8314006695e-10;
		asali_->thermo_[29].high[4] = -1.5005161556e-14;
		asali_->thermo_[29].high[5] = -8.5842236328e+03;
		asali_->thermo_[29].high[6] = -7.6450505257e+00;

		asali_->thermo_[29].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[29].low[0] = 2.4919705391e+00;
		asali_->thermo_[29].low[1] = 1.5870606527e-02;
		asali_->thermo_[29].low[2] = -1.2627152500e-05;
		asali_->thermo_[29].low[3] = 5.3399191735e-09;
		asali_->thermo_[29].low[4] = -9.1159718663e-13;
		asali_->thermo_[29].low[5] = -7.5848671875e+03;
		asali_->thermo_[29].low[6] = 1.0669438362e+01;
		
		asali_->thermo_[30].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[30].name,"CH2O");

		asali_->thermo_[30].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[30].high[0] = 1.0663925409e+00;
		asali_->thermo_[30].high[1] = 1.0696033947e-02;
		asali_->thermo_[30].high[2] = -5.5444738791e-06;
		asali_->thermo_[30].high[3] = 1.3605369054e-09;
		asali_->thermo_[30].high[4] = -1.2844255824e-13;
		asali_->thermo_[30].high[5] = -1.4632437500e+04;
		asali_->thermo_[30].high[6] = 1.7407176971e+01;

		asali_->thermo_[30].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[30].low[0] = 3.1346333027e+00;
		asali_->thermo_[30].low[1] = 1.8003748264e-03;
		asali_->thermo_[30].low[2] = 8.8033630163e-06;
		asali_->thermo_[30].low[3] = -8.9246503521e-09;
		asali_->thermo_[30].low[4] = 2.6363928401e-12;
		asali_->thermo_[30].low[5] = -1.5017129883e+04;
		asali_->thermo_[30].low[6] = 7.5792059898e+00;
		
		asali_->thermo_[31].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[31].name,"CH3OH");

		asali_->thermo_[31].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[31].high[0] = 9.3419301510e-01;
		asali_->thermo_[31].high[1] = 1.6026655212e-02;
		asali_->thermo_[31].high[2] = -8.0010149759e-06;
		asali_->thermo_[31].high[3] = 1.9712971255e-09;
		asali_->thermo_[31].high[4] = -1.9159948964e-13;
		asali_->thermo_[31].high[5] = -2.5097978516e+04;
		asali_->thermo_[31].high[6] = 1.9100845337e+01;

		asali_->thermo_[31].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[31].low[0] = 2.8889577389e+00;
		asali_->thermo_[31].low[1] = 4.8565706238e-03;
		asali_->thermo_[31].low[2] = 1.5934881958e-05;
		asali_->thermo_[31].low[3] = -2.0824794333e-08;
		asali_->thermo_[31].low[4] = 7.9498621228e-12;
		asali_->thermo_[31].low[5] = -2.5371646484e+04;
		asali_->thermo_[31].low[6] = 1.0367450714e+01;
		
		asali_->thermo_[32].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[32].name,"CH4");

		asali_->thermo_[32].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[32].high[0] = -2.8232142329e-01;
		asali_->thermo_[32].high[1] = 1.4273933135e-02;
		asali_->thermo_[32].high[2] = -6.7762889557e-06;
		asali_->thermo_[32].high[3] = 1.5538095255e-09;
		asali_->thermo_[32].high[4] = -1.3947384101e-13;
		asali_->thermo_[32].high[5] = -9.3638359375e+03;
		asali_->thermo_[32].high[6] = 2.0350702286e+01;

		asali_->thermo_[32].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[32].low[0] = 2.8576531410e+00;
		asali_->thermo_[32].low[1] = 2.5357110426e-03;
		asali_->thermo_[32].low[2] = 9.6791636679e-06;
		asali_->thermo_[32].low[3] = -8.6988087844e-09;
		asali_->thermo_[32].low[4] = 2.2559976890e-12;
		asali_->thermo_[32].low[5] = -1.0035790039e+04;
		asali_->thermo_[32].low[6] = 4.9896941185e+00;
		
		asali_->thermo_[33].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->thermo_[33].name,"CO");

		asali_->thermo_[33].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[33].high[0] = 2.6859500408e+00;
		asali_->thermo_[33].high[1] = 2.1248636767e-03;
		asali_->thermo_[33].high[2] = -1.0454861012e-06;
		asali_->thermo_[33].high[3] = 2.4553886702e-10;
		asali_->thermo_[33].high[4] = -2.2255097816e-14;
		asali_->thermo_[33].high[5] = -1.4142361328e+04;
		asali_->thermo_[33].high[6] = 7.9657940865e+00;

		asali_->thermo_[33].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[33].low[0] = 3.8189094067e+00;
		asali_->thermo_[33].low[1] = -2.4069733918e-03;
		asali_->thermo_[33].low[2] = 5.7522697716e-06;
		asali_->thermo_[33].low[3] = -4.2862984273e-09;
		asali_->thermo_[33].low[4] = 1.1107041935e-12;
		asali_->thermo_[33].low[5] = -1.4368953125e+04;
		asali_->thermo_[33].low[6] = 2.4999206066e+00;
		
		asali_->thermo_[34].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[34].name,"CO2");

		asali_->thermo_[34].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[34].high[0] = 5.0783100128e+00;
		asali_->thermo_[34].high[1] = 2.0536603406e-03;
		asali_->thermo_[34].high[2] = -5.9431124555e-07;
		asali_->thermo_[34].high[3] = 5.3867514616e-11;
		asali_->thermo_[34].high[4] = 1.6634685234e-15;
		asali_->thermo_[34].high[5] = -4.9244210938e+04;
		asali_->thermo_[34].high[6] = -4.4781527519e+00;

		asali_->thermo_[34].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[34].low[0] = 2.4489278793e+00;
		asali_->thermo_[34].low[1] = 8.5459612310e-03;
		asali_->thermo_[34].low[2] = -6.6057009462e-06;
		asali_->thermo_[34].low[3] = 2.5276905014e-09;
		asali_->thermo_[34].low[4] = -3.8009932658e-13;
		asali_->thermo_[34].low[5] = -4.8392289062e+04;
		asali_->thermo_[34].low[6] = 9.4755773544e+00;
		
		asali_->thermo_[35].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[35].name,"CYC5H6");

		asali_->thermo_[35].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[35].high[0] = 1.7014155388e+00;
		asali_->thermo_[35].high[1] = 3.7906594574e-02;
		asali_->thermo_[35].high[2] = -2.1949525035e-05;
		asali_->thermo_[35].high[3] = 6.1270650775e-09;
		asali_->thermo_[35].high[4] = -6.6367251321e-13;
		asali_->thermo_[35].high[5] = 1.3848440430e+04;
		asali_->thermo_[35].high[6] = 1.2245345116e+01;

		asali_->thermo_[35].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[35].low[0] = -6.3292288780e+00;
		asali_->thermo_[35].low[1] = 6.9399319589e-02;
		asali_->thermo_[35].low[2] = -6.8262350396e-05;
		asali_->thermo_[35].low[3] = 3.6396887282e-08;
		asali_->thermo_[35].low[4] = -8.0827462778e-12;
		asali_->thermo_[35].low[5] = 1.5486691406e+04;
		asali_->thermo_[35].low[6] = 5.1147590637e+01;
		
		asali_->thermo_[36].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[36].name,"MCPTD");

		asali_->thermo_[36].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[36].high[0] = 1.1415410042e+01;
		asali_->thermo_[36].high[1] = 2.7083026245e-02;
		asali_->thermo_[36].high[2] = -1.1341949175e-05;
		asali_->thermo_[36].high[3] = 2.3015782613e-09;
		asali_->thermo_[36].high[4] = -1.8605666866e-13;
		asali_->thermo_[36].high[5] = 6.2304077148e+03;
		asali_->thermo_[36].high[6] = -4.1034748077e+01;

		asali_->thermo_[36].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[36].low[0] = -6.5221977234e+00;
		asali_->thermo_[36].low[1] = 7.3674216866e-02;
		asali_->thermo_[36].low[2] = -5.6722976296e-05;
		asali_->thermo_[36].low[3] = 2.1947045070e-08;
		asali_->thermo_[36].low[4] = -3.3752558040e-12;
		asali_->thermo_[36].low[5] = 1.1755190430e+04;
		asali_->thermo_[36].low[6] = 5.3248985291e+01;
		
		asali_->thermo_[37].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[37].name,"CRESOL");

		asali_->thermo_[37].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[37].high[0] = 1.2267368317e+01;
		asali_->thermo_[37].high[1] = 3.3415529877e-02;
		asali_->thermo_[37].high[2] = -1.3894987205e-05;
		asali_->thermo_[37].high[3] = 2.5676816229e-09;
		asali_->thermo_[37].high[4] = -1.7151956396e-13;
		asali_->thermo_[37].high[5] = -2.1718724609e+04;
		asali_->thermo_[37].high[6] = -3.9571514130e+01;

		asali_->thermo_[37].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[37].low[0] = -4.4184393883e+00;
		asali_->thermo_[37].low[1] = 8.4364563227e-02;
		asali_->thermo_[37].low[2] = -7.2233575338e-05;
		asali_->thermo_[37].low[3] = 3.2256529892e-08;
		asali_->thermo_[37].low[4] = -5.8373301852e-12;
		asali_->thermo_[37].low[5] = -1.7347042969e+04;
		asali_->thermo_[37].low[6] = 4.5433486938e+01;
		
		asali_->thermo_[38].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[38].name,"NC10H20");

		asali_->thermo_[38].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[38].high[0] = 2.8297178268e+01;
		asali_->thermo_[38].high[1] = 4.8947893083e-02;
		asali_->thermo_[38].high[2] = -1.8273705791e-05;
		asali_->thermo_[38].high[3] = 3.2357521107e-09;
		asali_->thermo_[38].high[4] = -2.2681184188e-13;
		asali_->thermo_[38].high[5] = -3.1253458984e+04;
		asali_->thermo_[38].high[6] = -1.1678405762e+02;

		asali_->thermo_[38].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[38].low[0] = -2.3141770363e+00;
		asali_->thermo_[38].low[1] = 1.1697313190e-01;
		asali_->thermo_[38].low[2] = -7.4961404607e-05;
		asali_->thermo_[38].low[3] = 2.4231194828e-08;
		asali_->thermo_[38].low[4] = -3.1428455758e-12;
		asali_->thermo_[38].low[5] = -2.0233369141e+04;
		asali_->thermo_[38].low[6] = 4.8890987396e+01;
		
		asali_->thermo_[39].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[39].name,"C6H5CH2C6H5");

		asali_->thermo_[39].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[39].high[0] = 2.3660026550e+01;
		asali_->thermo_[39].high[1] = 4.2096108198e-02;
		asali_->thermo_[39].high[2] = -1.1875675227e-05;
		asali_->thermo_[39].high[3] = 4.0236997068e-10;
		asali_->thermo_[39].high[4] = 1.6853144856e-13;
		asali_->thermo_[39].high[5] = 4.5089775391e+03;
		asali_->thermo_[39].high[6] = -9.7668807983e+01;

		asali_->thermo_[39].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[39].low[0] = -1.1861348152e+01;
		asali_->thermo_[39].low[1] = 1.4076659083e-01;
		asali_->thermo_[39].low[2] = -1.1465742864e-04;
		asali_->thermo_[39].low[3] = 4.7986514318e-08;
		asali_->thermo_[39].low[4] = -8.0926047114e-12;
		asali_->thermo_[39].low[5] = 1.4739132812e+04;
		asali_->thermo_[39].low[6] = 8.6653915405e+01;
		
		asali_->thermo_[40].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[40].name,"DIPE");

		asali_->thermo_[40].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[40].high[0] = 1.1157392502e+01;
		asali_->thermo_[40].high[1] = 4.9917567521e-02;
		asali_->thermo_[40].high[2] = -2.2556137992e-05;
		asali_->thermo_[40].high[3] = 4.3844483599e-09;
		asali_->thermo_[40].high[4] = -3.0654935513e-13;
		asali_->thermo_[40].high[5] = -4.5935792969e+04;
		asali_->thermo_[40].high[6] = -3.0611776352e+01;

		asali_->thermo_[40].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[40].low[0] = -2.5074527264e+00;
		asali_->thermo_[40].low[1] = 8.9525811374e-02;
		asali_->thermo_[40].low[2] = -6.5608583100e-05;
		asali_->thermo_[40].low[3] = 2.5182730568e-08;
		asali_->thermo_[40].low[4] = -4.0743541353e-12;
		asali_->thermo_[40].low[5] = -4.2164296875e+04;
		asali_->thermo_[40].low[6] = 3.9714424133e+01;
		
		asali_->thermo_[41].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[41].name,"CH3OCH3");

		asali_->thermo_[41].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[41].high[0] = 8.1538945436e-01;
		asali_->thermo_[41].high[1] = 2.7267539874e-02;
		asali_->thermo_[41].high[2] = -1.4018142792e-05;
		asali_->thermo_[41].high[3] = 3.4368539126e-09;
		asali_->thermo_[41].high[4] = -3.2554235458e-13;
		asali_->thermo_[41].high[5] = -2.3174589844e+04;
		asali_->thermo_[41].high[6] = 1.9923925400e+01;

		asali_->thermo_[41].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[41].low[0] = 1.7409732342e+00;
		asali_->thermo_[41].low[1] = 2.1978490055e-02;
		asali_->thermo_[41].low[2] = -2.6844641070e-06;
		asali_->thermo_[41].low[3] = -7.3571260195e-09;
		asali_->thermo_[41].low[4] = 3.5294503865e-12;
		asali_->thermo_[41].low[5] = -2.3304171875e+04;
		asali_->thermo_[41].low[6] = 1.5788651466e+01;
		
		asali_->thermo_[42].name = (char*) malloc(11 * sizeof(char));
		strcpy(asali_->thermo_[42].name,"CH3CH3-C5H6");

		asali_->thermo_[42].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[42].high[0] = 1.5375555038e+01;
		asali_->thermo_[42].high[1] = 3.2731827348e-02;
		asali_->thermo_[42].high[2] = -1.0595570529e-05;
		asali_->thermo_[42].high[3] = 1.5210263049e-09;
		asali_->thermo_[42].high[4] = -7.6941593017e-14;
		asali_->thermo_[42].high[5] = -6.1968291016e+03;
		asali_->thermo_[42].high[6] = -5.3722602844e+01;

		asali_->thermo_[42].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[42].low[0] = -1.2924780846e+00;
		asali_->thermo_[42].low[1] = 8.3626583219e-02;
		asali_->thermo_[42].low[2] = -6.8872010161e-05;
		asali_->thermo_[42].low[3] = 3.1178245763e-08;
		asali_->thermo_[42].low[4] = -5.7367166573e-12;
		asali_->thermo_[42].low[5] = -1.8298046875e+03;
		asali_->thermo_[42].low[6] = 3.1191839218e+01;
		
		asali_->thermo_[43].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[43].name,"C6H5C2H5");

		asali_->thermo_[43].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[43].high[0] = 1.5399243355e+01;
		asali_->thermo_[43].high[1] = 3.1128443778e-02;
		asali_->thermo_[43].high[2] = -9.3292001111e-06;
		asali_->thermo_[43].high[3] = 5.2965493103e-10;
		asali_->thermo_[43].high[4] = 9.7160994528e-14;
		asali_->thermo_[43].high[5] = -4.3272578125e+03;
		asali_->thermo_[43].high[6] = -5.7749172211e+01;

		asali_->thermo_[43].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[43].low[0] = -6.1178631783e+00;
		asali_->thermo_[43].low[1] = 9.0898185968e-02;
		asali_->thermo_[43].low[2] = -7.1589347499e-05;
		asali_->thermo_[43].low[3] = 2.9353795838e-08;
		asali_->thermo_[43].low[4] = -4.9070300774e-12;
		asali_->thermo_[43].low[5] = 1.8696690674e+03;
		asali_->thermo_[43].low[6] = 5.3904491425e+01;
		
		asali_->thermo_[44].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[44].name,"NC7H14");

		asali_->thermo_[44].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[44].high[0] = 1.8266811371e+01;
		asali_->thermo_[44].high[1] = 3.5960789770e-02;
		asali_->thermo_[44].high[2] = -1.3734640561e-05;
		asali_->thermo_[44].high[3] = 2.5222905986e-09;
		asali_->thermo_[44].high[4] = -1.8524823331e-13;
		asali_->thermo_[44].high[5] = -1.8749734375e+04;
		asali_->thermo_[44].high[6] = -6.9230926514e+01;

		asali_->thermo_[44].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[44].low[0] = -1.2279731035e+00;
		asali_->thermo_[44].low[1] = 7.9282529652e-02;
		asali_->thermo_[44].low[2] = -4.9836089602e-05;
		asali_->thermo_[44].low[3] = 1.5893197869e-08;
		asali_->thermo_[44].low[4] = -2.0423187880e-12;
		asali_->thermo_[44].low[5] = -1.1731612305e+04;
		asali_->thermo_[44].low[6] = 3.6278907776e+01;
		
		asali_->thermo_[45].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[45].name,"NC6H12");

		asali_->thermo_[45].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[45].high[0] = 2.8095165253e+01;
		asali_->thermo_[45].high[1] = 5.2463593893e-03;
		asali_->thermo_[45].high[2] = 6.4320815909e-06;
		asali_->thermo_[45].high[3] = -3.1913138798e-09;
		asali_->thermo_[45].high[4] = 4.0109370903e-13;
		asali_->thermo_[45].high[5] = -1.7976785156e+04;
		asali_->thermo_[45].high[6] = -1.2449729156e+02;

		asali_->thermo_[45].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[45].low[0] = -1.8535830975e+00;
		asali_->thermo_[45].low[1] = 7.2546921670e-02;
		asali_->thermo_[45].low[2] = -5.0281872973e-05;
		asali_->thermo_[45].low[3] = 1.8049867379e-08;
		asali_->thermo_[45].low[4] = -2.5822182934e-12;
		asali_->thermo_[45].low[5] = -7.3150302734e+03;
		asali_->thermo_[45].low[6] = 3.7256958008e+01;
		
		asali_->thermo_[46].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[46].name,"C5H9CHO");

		asali_->thermo_[46].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[46].high[0] = 1.0841624260e+01;
		asali_->thermo_[46].high[1] = 4.2029667646e-02;
		asali_->thermo_[46].high[2] = -2.0074299755e-05;
		asali_->thermo_[46].high[3] = 4.5792738490e-09;
		asali_->thermo_[46].high[4] = -4.0851903024e-13;
		asali_->thermo_[46].high[5] = -3.5963171875e+04;
		asali_->thermo_[46].high[6] = -3.8001781464e+01;

		asali_->thermo_[46].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[46].low[0] = -6.5136365891e+00;
		asali_->thermo_[46].low[1] = 8.0596916378e-02;
		asali_->thermo_[46].low[2] = -5.2213668823e-05;
		asali_->thermo_[46].low[3] = 1.6482744059e-08;
		asali_->thermo_[46].low[4] = -2.0617789160e-12;
		asali_->thermo_[46].low[5] = -2.9715277344e+04;
		asali_->thermo_[46].low[6] = 5.5928508759e+01;
		
		asali_->thermo_[47].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[47].name,"ETBE");

		asali_->thermo_[47].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[47].high[0] = 1.1655913353e+01;
		asali_->thermo_[47].high[1] = 4.6793397516e-02;
		asali_->thermo_[47].high[2] = -1.9334202079e-05;
		asali_->thermo_[47].high[3] = 3.5918514829e-09;
		asali_->thermo_[47].high[4] = -2.4556496159e-13;
		asali_->thermo_[47].high[5] = -4.6032210938e+04;
		asali_->thermo_[47].high[6] = -3.3808494568e+01;

		asali_->thermo_[47].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[47].low[0] = -3.4800560474e+00;
		asali_->thermo_[47].low[1] = 9.4093300402e-02;
		asali_->thermo_[47].low[2] = -7.4763775046e-05;
		asali_->thermo_[47].low[3] = 3.2461421995e-08;
		asali_->thermo_[47].low[4] = -5.8841529739e-12;
		asali_->thermo_[47].low[5] = -4.2157402344e+04;
		asali_->thermo_[47].low[6] = 4.2950275421e+01;
		
		asali_->thermo_[48].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[48].name,"C2H5OH");

		asali_->thermo_[48].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[48].high[0] = 4.8295946121e+00;
		asali_->thermo_[48].high[1] = 1.7755212262e-02;
		asali_->thermo_[48].high[2] = -6.2111212173e-06;
		asali_->thermo_[48].high[3] = 6.5826522011e-10;
		asali_->thermo_[48].high[4] = 1.6013669476e-14;
		asali_->thermo_[48].high[5] = -3.0865849609e+04;
		asali_->thermo_[48].high[6] = 5.4318040609e-01;

		asali_->thermo_[48].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[48].low[0] = 2.4892158806e-01;
		asali_->thermo_[48].low[1] = 3.1032525003e-02;
		asali_->thermo_[48].low[2] = -2.0642983145e-05;
		asali_->thermo_[48].low[3] = 7.6301791552e-09;
		asali_->thermo_[48].low[4] = -1.2470142106e-12;
		asali_->thermo_[48].low[5] = -2.9601583984e+04;
		asali_->thermo_[48].low[6] = 2.4117639542e+01;
		
		asali_->thermo_[49].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[49].name,"C2H5OOH");

		asali_->thermo_[49].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[49].high[0] = 1.1565219879e+01;
		asali_->thermo_[49].high[1] = 1.0221647099e-02;
		asali_->thermo_[49].high[2] = -1.8663005221e-06;
		asali_->thermo_[49].high[3] = -2.5569205087e-10;
		asali_->thermo_[49].high[4] = 7.2621128674e-14;
		asali_->thermo_[49].high[5] = -2.4732814453e+04;
		asali_->thermo_[49].high[6] = -3.4211296082e+01;

		asali_->thermo_[49].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[49].low[0] = 1.4629422426e+00;
		asali_->thermo_[49].low[1] = 3.5636182874e-02;
		asali_->thermo_[49].low[2] = -2.5842276955e-05;
		asali_->thermo_[49].low[3] = 9.7971284418e-09;
		asali_->thermo_[49].low[4] = -1.5080109470e-12;
		asali_->thermo_[49].low[5] = -2.1520289062e+04;
		asali_->thermo_[49].low[6] = 1.9211122513e+01;
		
		asali_->thermo_[50].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[50].name,"C2H4O");

		asali_->thermo_[50].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[50].high[0] = 4.7721753120e+00;
		asali_->thermo_[50].high[1] = 1.2960888445e-02;
		asali_->thermo_[50].high[2] = -4.1960802264e-06;
		asali_->thermo_[50].high[3] = 3.3285946222e-10;
		asali_->thermo_[50].high[4] = 2.9742850435e-14;
		asali_->thermo_[50].high[5] = -8.9105488281e+03;
		asali_->thermo_[50].high[6] = -2.9956827164e+00;

		asali_->thermo_[50].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[50].low[0] = -1.7668315172e+00;
		asali_->thermo_[50].low[1] = 3.1124796718e-02;
		asali_->thermo_[50].low[2] = -2.3116817829e-05;
		asali_->thermo_[50].low[3] = 9.0924601182e-09;
		asali_->thermo_[50].low[4] = -1.4910211737e-12;
		asali_->thermo_[50].low[5] = -7.0273149414e+03;
		asali_->thermo_[50].low[6] = 3.0935647964e+01;
		
		asali_->thermo_[51].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[51].name,"C6H5C2H");

		asali_->thermo_[51].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[51].high[0] = 1.3630162239e+01;
		asali_->thermo_[51].high[1] = 2.6782613248e-02;
		asali_->thermo_[51].high[2] = -1.1827697563e-05;
		asali_->thermo_[51].high[3] = 2.5680724214e-09;
		asali_->thermo_[51].high[4] = -2.2161664322e-13;
		asali_->thermo_[51].high[5] = 3.0438148438e+04;
		asali_->thermo_[51].high[6] = -4.8343486786e+01;

		asali_->thermo_[51].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[51].low[0] = -3.7308592796e+00;
		asali_->thermo_[51].low[1] = 7.8996211290e-02;
		asali_->thermo_[51].low[2] = -7.0715213951e-05;
		asali_->thermo_[51].low[3] = 3.2085626600e-08;
		asali_->thermo_[51].low[4] = -5.7700289859e-12;
		asali_->thermo_[51].low[5] = 3.5056179688e+04;
		asali_->thermo_[51].low[6] = 4.0364406586e+01;
		
		
		asali_->thermo_[53].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[53].name,"C14H10");

		asali_->thermo_[53].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[53].high[0] = 3.1314125061e+01;
		asali_->thermo_[53].high[1] = 2.8952870518e-02;
		asali_->thermo_[53].high[2] = -5.5767100093e-06;
		asali_->thermo_[53].high[3] = -5.8966292960e-10;
		asali_->thermo_[53].high[4] = 1.8820294173e-13;
		asali_->thermo_[53].high[5] = 1.0646019531e+04;
		asali_->thermo_[53].high[6] = -1.4810102844e+02;

		asali_->thermo_[53].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[53].low[0] = -1.2190587044e+01;
		asali_->thermo_[53].low[1] = 1.5064437687e-01;
		asali_->thermo_[53].low[2] = -1.3322514133e-04;
		asali_->thermo_[53].low[3] = 5.8920093693e-08;
		asali_->thermo_[53].low[4] = -1.0215600935e-11;
		asali_->thermo_[53].low[5] = 2.3088367188e+04;
		asali_->thermo_[53].low[6] = 7.7344589233e+01;
		
		asali_->thermo_[54].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[54].name,"C6H5OH");

		asali_->thermo_[54].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[54].high[0] = 1.3986771584e+01;
		asali_->thermo_[54].high[1] = 2.0227763802e-02;
		asali_->thermo_[54].high[2] = -7.3659948612e-06;
		asali_->thermo_[54].high[3] = 1.2119628634e-09;
		asali_->thermo_[54].high[4] = -7.4610504136e-14;
		asali_->thermo_[54].high[5] = -1.8054226562e+04;
		asali_->thermo_[54].high[6] = -5.0848579407e+01;

		asali_->thermo_[54].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[54].low[0] = -5.4732542038e+00;
		asali_->thermo_[54].low[1] = 7.8754156828e-02;
		asali_->thermo_[54].low[2] = -7.3373201303e-05;
		asali_->thermo_[54].low[3] = 3.4298285101e-08;
		asali_->thermo_[54].low[4] = -6.2938439183e-12;
		asali_->thermo_[54].low[5] = -1.2877859375e+04;
		asali_->thermo_[54].low[6] = 4.8584381104e+01;
		
		asali_->thermo_[55].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[55].name,"FLUORENE");

		asali_->thermo_[55].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[55].high[0] = 2.9124887466e+01;
		asali_->thermo_[55].high[1] = 2.8536202386e-02;
		asali_->thermo_[55].high[2] = -5.6619974202e-06;
		asali_->thermo_[55].high[3] = -5.6702670337e-10;
		asali_->thermo_[55].high[4] = 1.9113497677e-13;
		asali_->thermo_[55].high[5] = 9.7511933594e+03;
		asali_->thermo_[55].high[6] = -1.3715922546e+02;

		asali_->thermo_[55].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[55].low[0] = -1.4346511841e+01;
		asali_->thermo_[55].low[1] = 1.4929008484e-01;
		asali_->thermo_[55].low[2] = -1.3144729019e-04;
		asali_->thermo_[55].low[3] = 5.7666909470e-08;
		asali_->thermo_[55].low[4] = -9.9189233216e-12;
		asali_->thermo_[55].low[5] = 2.2270957031e+04;
		asali_->thermo_[55].low[6] = 8.8416702271e+01;
		
		asali_->thermo_[56].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[56].name,"C10H8");

		asali_->thermo_[56].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[56].high[0] = 1.5118482590e+01;
		asali_->thermo_[56].high[1] = 3.8967557251e-02;
		asali_->thermo_[56].high[2] = -1.7824866518e-05;
		asali_->thermo_[56].high[3] = 3.9209226976e-09;
		asali_->thermo_[56].high[4] = -3.3921568896e-13;
		asali_->thermo_[56].high[5] = 1.0112156250e+04;
		asali_->thermo_[56].high[6] = -6.0904109955e+01;

		asali_->thermo_[56].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[56].low[0] = -8.7183246613e+00;
		asali_->thermo_[56].low[1] = 1.0856407136e-01;
		asali_->thermo_[56].low[2] = -9.4025432190e-05;
		asali_->thermo_[56].low[3] = 4.1001488427e-08;
		asali_->thermo_[56].low[4] = -7.1057426436e-12;
		asali_->thermo_[56].low[5] = 1.6643441406e+04;
		asali_->thermo_[56].low[6] = 6.1598789215e+01;
		
		asali_->thermo_[57].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->thermo_[57].name,"H2");

		asali_->thermo_[57].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[57].high[0] = 3.7311089039e+00;
		asali_->thermo_[57].high[1] = -8.8670622790e-04;
		asali_->thermo_[57].high[2] = 1.1228689800e-06;
		asali_->thermo_[57].high[3] = -3.7434977340e-10;
		asali_->thermo_[57].high[4] = 4.1796366444e-14;
		asali_->thermo_[57].high[5] = -1.0885155029e+03;
		asali_->thermo_[57].high[6] = -5.3528585434e+00;

		asali_->thermo_[57].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[57].low[0] = 3.0886600018e+00;
		asali_->thermo_[57].low[1] = 2.5396884885e-03;
		asali_->thermo_[57].low[2] = -5.7299203036e-06;
		asali_->thermo_[57].low[3] = 5.7170184142e-09;
		asali_->thermo_[57].low[4] = -1.9886596710e-12;
		asali_->thermo_[57].low[5] = -9.9214813232e+02;
		asali_->thermo_[57].low[6] = -2.4382345676e+00;
		
		asali_->thermo_[58].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[58].name,"H2O");

		asali_->thermo_[58].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[58].high[0] = 2.3094046116e+00;
		asali_->thermo_[58].high[1] = 3.6543388851e-03;
		asali_->thermo_[58].high[2] = -1.2298387446e-06;
		asali_->thermo_[58].high[3] = 2.1193168054e-10;
		asali_->thermo_[58].high[4] = -1.5033349118e-14;
		asali_->thermo_[58].high[5] = -2.9729490234e+04;
		asali_->thermo_[58].high[6] = 8.9276514053e+00;

		asali_->thermo_[58].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[58].low[0] = 4.0353093147e+00;
		asali_->thermo_[58].low[1] = -6.8755983375e-04;
		asali_->thermo_[58].low[2] = 2.8662921068e-06;
		asali_->thermo_[58].low[3] = -1.5055235947e-09;
		asali_->thermo_[58].low[4] = 2.5500679042e-13;
		asali_->thermo_[58].low[5] = -3.0278328125e+04;
		asali_->thermo_[58].low[6] = -1.9920164347e-01;
		
		asali_->thermo_[59].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[59].name,"H2O2");

		asali_->thermo_[59].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[59].high[0] = 4.5616307259e+00;
		asali_->thermo_[59].high[1] = 4.3556098826e-03;
		asali_->thermo_[59].high[2] = -1.4869463030e-06;
		asali_->thermo_[59].high[3] = 2.3827542717e-10;
		asali_->thermo_[59].high[4] = -1.4661035786e-14;
		asali_->thermo_[59].high[5] = -1.8001669922e+04;
		asali_->thermo_[59].high[6] = 5.6659710407e-01;

		asali_->thermo_[59].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[59].low[0] = 2.9189634323e+00;
		asali_->thermo_[59].low[1] = 9.9239731207e-03;
		asali_->thermo_[59].low[2] = -8.5653746282e-06;
		asali_->thermo_[59].low[3] = 4.2373873299e-09;
		asali_->thermo_[59].low[4] = -8.6193048142e-13;
		asali_->thermo_[59].low[5] = -1.7614000000e+04;
		asali_->thermo_[59].low[6] = 8.7634019852e+00;
		
		asali_->thermo_[60].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->thermo_[60].name,"HE");

		asali_->thermo_[60].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[60].high[0] = 2.5000000000e+00;
		asali_->thermo_[60].high[1] = 7.4033618794e-15;
		asali_->thermo_[60].high[2] = -5.5696742437e-18;
		asali_->thermo_[60].high[3] = 1.7392488179e-21;
		asali_->thermo_[60].high[4] = -1.9267370477e-25;
		asali_->thermo_[60].high[5] = -7.4537500000e+02;
		asali_->thermo_[60].high[6] = 9.2872399092e-01;

		asali_->thermo_[60].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[60].low[0] = 2.5000000000e+00;
		asali_->thermo_[60].low[1] = -4.0745516194e-15;
		asali_->thermo_[60].low[2] = 5.9852725309e-18;
		asali_->thermo_[60].low[3] = -3.4307497659e-21;
		asali_->thermo_[60].low[4] = 6.7477569320e-25;
		asali_->thermo_[60].low[5] = -7.4537500000e+02;
		asali_->thermo_[60].low[6] = 9.2872399092e-01;
		
		asali_->thermo_[61].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[61].name,"IC4H8");

		asali_->thermo_[61].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[61].high[0] = 7.6343398094e+00;
		asali_->thermo_[61].high[1] = 2.4772269651e-02;
		asali_->thermo_[61].high[2] = -1.0541582924e-05;
		asali_->thermo_[61].high[3] = 2.1815236284e-09;
		asali_->thermo_[61].high[4] = -1.8011959112e-13;
		asali_->thermo_[61].high[5] = -6.2138579102e+03;
		asali_->thermo_[61].high[6] = -1.7294937134e+01;

		asali_->thermo_[61].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[61].low[0] = 7.1730160713e-01;
		asali_->thermo_[61].low[1] = 4.0143463761e-02;
		asali_->thermo_[61].low[2] = -2.3350912670e-05;
		asali_->thermo_[61].low[3] = 6.9257199975e-09;
		asali_->thermo_[61].low[4] = -8.3903570940e-13;
		asali_->thermo_[61].low[5] = -3.7237238770e+03;
		asali_->thermo_[61].low[6] = 2.0141515732e+01;
		
		asali_->thermo_[62].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[62].name,"IC3H7CHO");

		asali_->thermo_[62].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[62].high[0] = 1.2537504196e+01;
		asali_->thermo_[62].high[1] = 2.0675983280e-02;
		asali_->thermo_[62].high[2] = -7.9060664575e-06;
		asali_->thermo_[62].high[3] = 1.4476160271e-09;
		asali_->thermo_[62].high[4] = -1.0577657999e-13;
		asali_->thermo_[62].high[5] = -3.2236363281e+04;
		asali_->thermo_[62].high[6] = -4.1050521851e+01;

		asali_->thermo_[62].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[62].low[0] = -3.4473210573e-01;
		asali_->thermo_[62].low[1] = 4.9303174019e-02;
		asali_->thermo_[62].low[2] = -3.1762057915e-05;
		asali_->thermo_[62].low[3] = 1.0283168983e-08;
		asali_->thermo_[62].low[4] = -1.3329366907e-12;
		asali_->thermo_[62].low[5] = -2.7598757812e+04;
		asali_->thermo_[62].low[6] = 2.8670827866e+01;
		
		asali_->thermo_[63].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[63].name,"IC4H10");

		asali_->thermo_[63].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[63].high[0] = 5.5195579529e+00;
		asali_->thermo_[63].high[1] = 3.2374724746e-02;
		asali_->thermo_[63].high[2] = -1.1865543456e-05;
		asali_->thermo_[63].high[3] = 1.3745518057e-09;
		asali_->thermo_[63].high[4] = 1.5707346787e-14;
		asali_->thermo_[63].high[5] = -1.9702580078e+04;
		asali_->thermo_[63].high[6] = -6.3448343277e+00;

		asali_->thermo_[63].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[63].low[0] = -1.8596532345e+00;
		asali_->thermo_[63].low[1] = 5.5800795555e-02;
		asali_->thermo_[63].low[2] = -3.9753718738e-05;
		asali_->thermo_[63].low[3] = 1.6130199398e-08;
		asali_->thermo_[63].low[4] = -2.9120007187e-12;
		asali_->thermo_[63].low[5] = -1.7843019531e+04;
		asali_->thermo_[63].low[6] = 3.0961015701e+01;
		
		asali_->thermo_[64].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[64].name,"IC8H18");

		asali_->thermo_[64].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[64].high[0] = 2.0615589142e+01;
		asali_->thermo_[64].high[1] = 4.4369410723e-02;
		asali_->thermo_[64].high[2] = -1.3596885765e-05;
		asali_->thermo_[64].high[3] = 1.7532761909e-09;
		asali_->thermo_[64].high[4] = -6.8309087228e-14;
		asali_->thermo_[64].high[5] = -3.7658062500e+04;
		asali_->thermo_[64].high[6] = -8.4214881897e+01;

		asali_->thermo_[64].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[64].low[0] = -5.9691209793e+00;
		asali_->thermo_[64].low[1] = 1.2087216973e-01;
		asali_->thermo_[64].low[2] = -9.6153824416e-05;
		asali_->thermo_[64].low[3] = 4.1348929614e-08;
		asali_->thermo_[64].low[4] = -7.1898294610e-12;
		asali_->thermo_[64].low[5] = -3.0267511719e+04;
		asali_->thermo_[64].low[6] = 5.2795421600e+01;
		
		asali_->thermo_[65].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[65].name,"INDENE");

		asali_->thermo_[65].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[65].high[0] = 1.6534870148e+01;
		asali_->thermo_[65].high[1] = 2.8136143461e-02;
		asali_->thermo_[65].high[2] = -7.8267457866e-06;
		asali_->thermo_[65].high[3] = 2.3393639803e-10;
		asali_->thermo_[65].high[4] = 1.1523444146e-13;
		asali_->thermo_[65].high[5] = 1.1327866211e+04;
		asali_->thermo_[65].high[6] = -6.6647804260e+01;

		asali_->thermo_[65].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[65].low[0] = -7.3259220123e+00;
		asali_->thermo_[65].low[1] = 9.3959018588e-02;
		asali_->thermo_[65].low[2] = -7.5919371739e-05;
		asali_->thermo_[65].low[3] = 3.1540892564e-08;
		asali_->thermo_[65].low[4] = -5.2825161780e-12;
		asali_->thermo_[65].low[5] = 1.8247496094e+04;
		asali_->thermo_[65].low[6] = 5.7332519531e+01;
		
		asali_->thermo_[66].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[66].name,"IC3H7OH");

		asali_->thermo_[66].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[66].high[0] = 6.2806959152e+00;
		asali_->thermo_[66].high[1] = 2.5937004015e-02;
		asali_->thermo_[66].high[2] = -1.0535074580e-05;
		asali_->thermo_[66].high[3] = 1.9292136777e-09;
		asali_->thermo_[66].high[4] = -1.3018399022e-13;
		asali_->thermo_[66].high[5] = -3.6376863281e+04;
		asali_->thermo_[66].high[6] = -6.6634187698e+00;

		asali_->thermo_[66].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[66].low[0] = -3.0057406425e-01;
		asali_->thermo_[66].low[1] = 4.6032484621e-02;
		asali_->thermo_[66].low[2] = -3.3545169572e-05;
		asali_->thermo_[66].low[3] = 1.3639184893e-08;
		asali_->thermo_[66].low[4] = -2.3649112182e-12;
		asali_->thermo_[66].low[5] = -3.4652570312e+04;
		asali_->thermo_[66].low[6] = 2.6864526749e+01;
		
		asali_->thermo_[67].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[67].name,"IC5H10");

		asali_->thermo_[67].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[67].high[0] = 2.1345983505e+01;
		asali_->thermo_[67].high[1] = 8.8836718351e-03;
		asali_->thermo_[67].high[2] = 1.5964841396e-06;
		asali_->thermo_[67].high[3] = -1.3180819769e-09;
		asali_->thermo_[67].high[4] = 1.7460085298e-13;
		asali_->thermo_[67].high[5] = -1.2662007812e+04;
		asali_->thermo_[67].high[6] = -8.9469985962e+01;

		asali_->thermo_[67].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[67].low[0] = -1.5963453054e+00;
		asali_->thermo_[67].low[1] = 5.9866625816e-02;
		asali_->thermo_[67].low[2] = -4.0889310185e-05;
		asali_->thermo_[67].low[3] = 1.4417397942e-08;
		asali_->thermo_[67].low[4] = -2.0108823461e-12;
		asali_->thermo_[67].low[5] = -4.4027690430e+03;
		asali_->thermo_[67].low[6] = 3.4698684692e+01;
		
		asali_->thermo_[68].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[68].name,"IC3H5CHO");

		asali_->thermo_[68].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[68].high[0] = 8.9660577774e+00;
		asali_->thermo_[68].high[1] = 2.2096239030e-02;
		asali_->thermo_[68].high[2] = -1.0090114301e-05;
		asali_->thermo_[68].high[3] = 2.2213928474e-09;
		asali_->thermo_[68].high[4] = -1.9179226078e-13;
		asali_->thermo_[68].high[5] = -1.7992009766e+04;
		asali_->thermo_[68].high[6] = -2.1193923950e+01;

		asali_->thermo_[68].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[68].low[0] = 6.9294196367e-01;
		asali_->thermo_[68].low[1] = 4.6251319349e-02;
		asali_->thermo_[68].low[2] = -3.6537283449e-05;
		asali_->thermo_[68].low[3] = 1.5091062622e-08;
		asali_->thermo_[68].low[4] = -2.5402720292e-12;
		asali_->thermo_[68].low[5] = -1.5725176758e+04;
		asali_->thermo_[68].low[6] = 2.1323541641e+01;
		
		asali_->thermo_[69].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[69].name,"MCYC6");

		asali_->thermo_[69].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[69].high[0] = 1.6719457626e+01;
		asali_->thermo_[69].high[1] = 4.3618064374e-02;
		asali_->thermo_[69].high[2] = -1.8777336663e-05;
		asali_->thermo_[69].high[3] = 3.9205900748e-09;
		asali_->thermo_[69].high[4] = -3.2670299300e-13;
		asali_->thermo_[69].high[5] = -2.9186630859e+04;
		asali_->thermo_[69].high[6] = -7.4061187744e+01;

		asali_->thermo_[69].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[69].low[0] = -1.0100635529e+01;
		asali_->thermo_[69].low[1] = 1.0321827233e-01;
		asali_->thermo_[69].low[2] = -6.8444176577e-05;
		asali_->thermo_[69].low[3] = 2.2315715498e-08;
		asali_->thermo_[69].low[4] = -2.8815814752e-12;
		asali_->thermo_[69].low[5] = -1.9531396484e+04;
		asali_->thermo_[69].low[6] = 7.1094749451e+01;
		
		asali_->thermo_[70].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[70].name,"CH3CHO");

		asali_->thermo_[70].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[70].high[0] = 6.2701811790e+00;
		asali_->thermo_[70].high[1] = 1.0620187037e-02;
		asali_->thermo_[70].high[2] = -3.8226467041e-06;
		asali_->thermo_[70].high[3] = 6.5634081503e-10;
		asali_->thermo_[70].high[4] = -4.6054956723e-14;
		asali_->thermo_[70].high[5] = -2.2979478516e+04;
		asali_->thermo_[70].high[6] = -8.6011924744e+00;

		asali_->thermo_[70].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[70].low[0] = 9.9175137281e-01;
		asali_->thermo_[70].low[1] = 2.2350031883e-02;
		asali_->thermo_[70].low[2] = -1.3597516954e-05;
		asali_->thermo_[70].low[3] = 4.2766630237e-09;
		asali_->thermo_[70].low[4] = -5.4887751245e-13;
		asali_->thermo_[70].low[5] = -2.1079244141e+04;
		asali_->thermo_[70].low[6] = 1.9966770172e+01;
		
		
		asali_->thermo_[72].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[72].name,"CH3OOH");

		asali_->thermo_[72].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[72].high[0] = 5.5014653206e+00;
		asali_->thermo_[72].high[1] = 1.1397542432e-02;
		asali_->thermo_[72].high[2] = -3.8213083826e-06;
		asali_->thermo_[72].high[3] = 4.3870490574e-10;
		asali_->thermo_[72].high[4] = -2.9061747007e-15;
		asali_->thermo_[72].high[5] = -1.7978423828e+04;
		asali_->thermo_[72].high[6] = -4.6558141708e-01;

		asali_->thermo_[72].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[72].low[0] = 5.9343085289e+00;
		asali_->thermo_[72].low[1] = 1.0435667820e-02;
		asali_->thermo_[72].low[2] = -3.0197461456e-06;
		asali_->thermo_[72].low[3] = 1.4183000607e-10;
		asali_->thermo_[72].low[4] = 3.8326451930e-14;
		asali_->thermo_[72].low[5] = -1.8134248047e+04;
		asali_->thermo_[72].low[6] = -2.8082213402e+00;
		
		asali_->thermo_[73].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[73].name,"MTBE");

		asali_->thermo_[73].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[73].high[0] = 9.8525085449e+00;
		asali_->thermo_[73].high[1] = 4.0189620107e-02;
		asali_->thermo_[73].high[2] = -1.6670421246e-05;
		asali_->thermo_[73].high[3] = 3.1015894297e-09;
		asali_->thermo_[73].high[4] = -2.1153780496e-13;
		asali_->thermo_[73].high[5] = -4.0927421875e+04;
		asali_->thermo_[73].high[6] = -2.6194110870e+01;

		asali_->thermo_[73].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[73].low[0] = -1.8585642576e+00;
		asali_->thermo_[73].low[1] = 7.5677715242e-02;
		asali_->thermo_[73].low[2] = -5.6997807405e-05;
		asali_->thermo_[73].low[3] = 2.3468956556e-08;
		asali_->thermo_[73].low[4] = -4.0689934061e-12;
		asali_->thermo_[73].low[5] = -3.7835699219e+04;
		asali_->thermo_[73].low[6] = 3.3556411743e+01;
		
		asali_->thermo_[74].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->thermo_[74].name,"N2");

		asali_->thermo_[74].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[74].high[0] = 2.7128789425e+00;
		asali_->thermo_[74].high[1] = 1.9035974983e-03;
		asali_->thermo_[74].high[2] = -8.5429758201e-07;
		asali_->thermo_[74].high[3] = 1.8417094239e-10;
		asali_->thermo_[74].high[4] = -1.5471598883e-14;
		asali_->thermo_[74].high[5] = -8.4022528076e+02;
		asali_->thermo_[74].high[6] = 7.1592655182e+00;

		asali_->thermo_[74].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[74].low[0] = 3.8532133102e+00;
		asali_->thermo_[74].low[1] = -2.4405336007e-03;
		asali_->thermo_[74].low[2] = 5.3516037042e-06;
		asali_->thermo_[74].low[3] = -3.7560838884e-09;
		asali_->thermo_[74].low[4] = 9.2268434646e-13;
		asali_->thermo_[74].low[5] = -1.0796955566e+03;
		asali_->thermo_[74].low[6] = 1.6021741629e+00;
		
		asali_->thermo_[75].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[75].name,"C10H7OH");

		asali_->thermo_[75].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[75].high[0] = 2.6181821823e+01;
		asali_->thermo_[75].high[1] = 2.4707922712e-02;
		asali_->thermo_[75].high[2] = -8.7547296062e-06;
		asali_->thermo_[75].high[3] = 1.4121320779e-09;
		asali_->thermo_[75].high[4] = -8.6158036543e-14;
		asali_->thermo_[75].high[5] = -1.5833869141e+04;
		asali_->thermo_[75].high[6] = -1.1931431580e+02;

		asali_->thermo_[75].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[75].low[0] = -3.0919461250e+00;
		asali_->thermo_[75].low[1] = 9.2392936349e-02;
		asali_->thermo_[75].low[2] = -6.7441156716e-05;
		asali_->thermo_[75].low[3] = 2.4027325907e-08;
		asali_->thermo_[75].low[4] = -3.3542496038e-12;
		asali_->thermo_[75].low[5] = -5.7051450195e+03;
		asali_->thermo_[75].low[6] = 3.7960273743e+01;
		
		
		asali_->thermo_[77].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[77].name,"NC4H10");

		asali_->thermo_[77].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[77].high[0] = 1.5435536385e+01;
		asali_->thermo_[77].high[1] = 1.5627255663e-02;
		asali_->thermo_[77].high[2] = -3.1485199088e-06;
		asali_->thermo_[77].high[3] = -5.9442416267e-11;
		asali_->thermo_[77].high[4] = 5.3296465006e-14;
		asali_->thermo_[77].high[5] = -2.2845525391e+04;
		asali_->thermo_[77].high[6] = -6.0241783142e+01;

		asali_->thermo_[77].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[77].low[0] = -1.2083675861e+00;
		asali_->thermo_[77].low[1] = 5.2613709122e-02;
		asali_->thermo_[77].low[2] = -3.3970565710e-05;
		asali_->thermo_[77].low[3] = 1.1356129370e-08;
		asali_->thermo_[77].low[4] = -1.5321996059e-12;
		asali_->thermo_[77].low[5] = -1.6853720703e+04;
		asali_->thermo_[77].low[6] = 2.9838495255e+01;
		
		asali_->thermo_[78].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[78].name,"NC10H22");

		asali_->thermo_[78].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[78].high[0] = 2.9287891388e+01;
		asali_->thermo_[78].high[1] = 5.2992098033e-02;
		asali_->thermo_[78].high[2] = -1.9840455934e-05;
		asali_->thermo_[78].high[3] = 3.5561638079e-09;
		asali_->thermo_[78].high[4] = -2.5428118812e-13;
		asali_->thermo_[78].high[5] = -4.5623238281e+04;
		asali_->thermo_[78].high[6] = -1.2275204468e+02;

		asali_->thermo_[78].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[78].low[0] = -2.1787014008e+00;
		asali_->thermo_[78].low[1] = 1.2291786075e-01;
		asali_->thermo_[78].low[2] = -7.8111923358e-05;
		asali_->thermo_[78].low[3] = 2.5138188420e-08;
		asali_->thermo_[78].low[4] = -3.2517846922e-12;
		asali_->thermo_[78].low[5] = -3.4295265625e+04;
		asali_->thermo_[78].low[6] = 4.7551719666e+01;
		
		asali_->thermo_[79].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[79].name,"NC12H26");

		asali_->thermo_[79].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[79].high[0] = 3.6141410828e+01;
		asali_->thermo_[79].high[1] = 6.1104588211e-02;
		asali_->thermo_[79].high[2] = -2.2464108042e-05;
		asali_->thermo_[79].high[3] = 3.9318241996e-09;
		asali_->thermo_[79].high[4] = -2.7334934988e-13;
		asali_->thermo_[79].high[5] = -5.4035917969e+04;
		asali_->thermo_[79].high[6] = -1.5683195496e+02;

		asali_->thermo_[79].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[79].low[0] = -2.6662769318e+00;
		asali_->thermo_[79].low[1] = 1.4734388888e-01;
		asali_->thermo_[79].low[2] = -9.4330192951e-05;
		asali_->thermo_[79].low[3] = 3.0548893193e-08;
		asali_->thermo_[79].low[4] = -3.9701644750e-12;
		asali_->thermo_[79].low[5] = -4.0065152344e+04;
		asali_->thermo_[79].low[6] = 5.3203334808e+01;
		
		asali_->thermo_[80].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[80].name,"NC5H12");

		asali_->thermo_[80].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[80].high[0] = 2.1255908966e+01;
		asali_->thermo_[80].high[1] = 1.4986637048e-02;
		asali_->thermo_[80].high[2] = -1.5673831513e-06;
		asali_->thermo_[80].high[3] = -4.8451842538e-10;
		asali_->thermo_[80].high[4] = 9.0043647722e-14;
		asali_->thermo_[80].high[5] = -2.8066871094e+04;
		asali_->thermo_[80].high[6] = -9.0549766541e+01;

		asali_->thermo_[80].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[80].low[0] = -1.9700086117e+00;
		asali_->thermo_[80].low[1] = 6.6599786282e-02;
		asali_->thermo_[80].low[2] = -4.4578340749e-05;
		asali_->thermo_[80].low[3] = 1.5445465351e-08;
		asali_->thermo_[80].low[4] = -2.1224541222e-12;
		asali_->thermo_[80].low[5] = -1.9705541016e+04;
		asali_->thermo_[80].low[6] = 3.5153739929e+01;
		
		asali_->thermo_[81].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[81].name,"NC7H16");

		asali_->thermo_[81].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[81].high[0] = 3.1069612503e+01;
		asali_->thermo_[81].high[1] = 1.7345886678e-02;
		asali_->thermo_[81].high[2] = -4.5766387302e-07;
		asali_->thermo_[81].high[3] = -1.0628096181e-09;
		asali_->thermo_[81].high[4] = 1.5909886256e-13;
		asali_->thermo_[81].high[5] = -3.7654160156e+04;
		asali_->thermo_[81].high[6] = -1.4092050171e+02;

		asali_->thermo_[81].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[81].low[0] = -2.7691280842e+00;
		asali_->thermo_[81].low[1] = 9.2543087900e-02;
		asali_->thermo_[81].low[2] = -6.3121995481e-05;
		asali_->thermo_[81].low[3] = 2.2146203094e-08;
		asali_->thermo_[81].low[4] = -3.0643751425e-12;
		asali_->thermo_[81].low[5] = -2.5472212891e+04;
		asali_->thermo_[81].low[6] = 4.2221824646e+01;
		
		asali_->thermo_[82].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[82].name,"NEOC5H12");

		asali_->thermo_[82].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[82].high[0] = 1.5822081566e+01;
		asali_->thermo_[82].high[1] = 2.7382407337e-02;
		asali_->thermo_[82].high[2] = -1.0139257938e-05;
		asali_->thermo_[82].high[3] = 1.7770700467e-09;
		asali_->thermo_[82].high[4] = -1.2275697494e-13;
		asali_->thermo_[82].high[5] = -2.8519701172e+04;
		asali_->thermo_[82].high[6] = -6.6248855591e+01;

		asali_->thermo_[82].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[82].low[0] = -2.6246345043e+00;
		asali_->thermo_[82].low[1] = 7.0786446333e-02;
		asali_->thermo_[82].low[2] = -4.8436937504e-05;
		asali_->thermo_[82].low[3] = 1.6795768332e-08;
		asali_->thermo_[82].low[4] = -2.3313889881e-12;
		asali_->thermo_[82].low[5] = -2.2247818359e+04;
		asali_->thermo_[82].low[6] = 3.2534236908e+01;
		
		asali_->thermo_[83].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->thermo_[83].name,"O2");

		asali_->thermo_[83].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[83].high[0] = 2.8175065517e+00;
		asali_->thermo_[83].high[1] = 2.4983801413e-03;
		asali_->thermo_[83].high[2] = -1.5249352145e-06;
		asali_->thermo_[83].high[3] = 4.5054759923e-10;
		asali_->thermo_[83].high[4] = -4.8770280078e-14;
		asali_->thermo_[83].high[5] = -9.3171337891e+02;
		asali_->thermo_[83].high[6] = 7.9472932816e+00;

		asali_->thermo_[83].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[83].low[0] = 3.4603507519e+00;
		asali_->thermo_[83].low[1] = -8.8501110440e-04;
		asali_->thermo_[83].low[2] = 5.1528104450e-06;
		asali_->thermo_[83].low[3] = -5.4071240818e-09;
		asali_->thermo_[83].low[4] = 1.8780953355e-12;
		asali_->thermo_[83].low[5] = -1.0294257812e+03;
		asali_->thermo_[83].low[6] = 5.0223612785e+00;
		
		asali_->thermo_[84].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[84].name,"IC8H16");

		asali_->thermo_[84].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[84].high[0] = 1.8861606598e+01;
		asali_->thermo_[84].high[1] = 4.1429281235e-02;
		asali_->thermo_[84].high[2] = -1.2817054085e-05;
		asali_->thermo_[84].high[3] = 1.6680673509e-09;
		asali_->thermo_[84].high[4] = -6.5896168188e-14;
		asali_->thermo_[84].high[5] = -2.2468406250e+04;
		asali_->thermo_[84].high[6] = -7.3851432800e+01;

		asali_->thermo_[84].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[84].low[0] = -5.3558659554e+00;
		asali_->thermo_[84].low[1] = 1.1062205583e-01;
		asali_->thermo_[84].low[2] = -8.6952175479e-05;
		asali_->thermo_[84].low[3] = 3.6970504880e-08;
		asali_->thermo_[84].low[4] = -6.3699028691e-12;
		asali_->thermo_[84].low[5] = -1.5687514648e+04;
		asali_->thermo_[84].low[6] = 5.1132381439e+01;
		
		asali_->thermo_[85].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[85].name,"NC5H10");

		asali_->thermo_[85].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[85].high[0] = 1.1192973137e+01;
		asali_->thermo_[85].high[1] = 2.8258223087e-02;
		asali_->thermo_[85].high[2] = -1.1386384358e-05;
		asali_->thermo_[85].high[3] = 2.2252648613e-09;
		asali_->thermo_[85].high[4] = -1.7428098624e-13;
		asali_->thermo_[85].high[5] = -1.0248344727e+04;
		asali_->thermo_[85].high[6] = -3.3925354004e+01;

		asali_->thermo_[85].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[85].low[0] = -6.8955194950e-01;
		asali_->thermo_[85].low[1] = 5.4663833231e-02;
		asali_->thermo_[85].low[2] = -3.3391061152e-05;
		asali_->thermo_[85].low[3] = 1.0375145187e-08;
		asali_->thermo_[85].low[4] = -1.3062088303e-12;
		asali_->thermo_[85].low[5] = -5.9706352539e+03;
		asali_->thermo_[85].low[6] = 3.0385354996e+01;
		
		asali_->thermo_[86].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[86].name,"PC3H4");

		asali_->thermo_[86].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[86].high[0] = 3.0415658951e+00;
		asali_->thermo_[86].high[1] = 1.8073292449e-02;
		asali_->thermo_[86].high[2] = -9.1984948085e-06;
		asali_->thermo_[86].high[3] = 2.2916157860e-09;
		asali_->thermo_[86].high[4] = -2.2568944868e-13;
		asali_->thermo_[86].high[5] = 2.0621425781e+04;
		asali_->thermo_[86].high[6] = 7.3749389648e+00;

		asali_->thermo_[86].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[86].low[0] = 1.3594318628e+00;
		asali_->thermo_[86].low[1] = 2.5386918336e-02;
		asali_->thermo_[86].low[2] = -2.1122885300e-05;
		asali_->thermo_[86].low[3] = 1.0932478922e-08;
		asali_->thermo_[86].low[4] = -2.5737500239e-12;
		asali_->thermo_[86].low[5] = 2.0930937500e+04;
		asali_->thermo_[86].low[6] = 1.5350004196e+01;
		
		asali_->thermo_[87].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[87].name,"CH3CO3H");

		asali_->thermo_[87].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[87].high[0] = 1.5496086121e+01;
		asali_->thermo_[87].high[1] = 1.5875810059e-03;
		asali_->thermo_[87].high[2] = 2.2442591217e-06;
		asali_->thermo_[87].high[3] = -9.7423724643e-10;
		asali_->thermo_[87].high[4] = 1.0377306246e-13;
		asali_->thermo_[87].high[5] = -4.6965542969e+04;
		asali_->thermo_[87].high[6] = -5.1840114594e+01;

		asali_->thermo_[87].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[87].low[0] = 3.6238896847e+00;
		asali_->thermo_[87].low[1] = 2.8569847345e-02;
		asali_->thermo_[87].low[2] = -2.0751989723e-05;
		asali_->thermo_[87].low[3] = 7.7364630258e-09;
		asali_->thermo_[87].low[4] = -1.1335423702e-12;
		asali_->thermo_[87].low[5] = -4.2786531250e+04;
		asali_->thermo_[87].low[6] = 1.2147887230e+01;
		
		asali_->thermo_[88].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[88].name,"HCO3H");

		asali_->thermo_[88].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[88].high[0] = 1.0023066521e+01;
		asali_->thermo_[88].high[1] = 4.4356323779e-03;
		asali_->thermo_[88].high[2] = -1.5618851421e-06;
		asali_->thermo_[88].high[3] = 2.4342439175e-10;
		asali_->thermo_[88].high[4] = -1.3839137694e-14;
		asali_->thermo_[88].high[5] = -3.8131332031e+04;
		asali_->thermo_[88].high[6] = -2.3359071732e+01;

		asali_->thermo_[88].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[88].low[0] = 2.4743421078e+00;
		asali_->thermo_[88].low[1] = 2.1689860150e-02;
		asali_->thermo_[88].low[2] = -1.6351223167e-05;
		asali_->thermo_[88].low[3] = 5.8774580758e-09;
		asali_->thermo_[88].low[4] = -8.1870106397e-13;
		asali_->thermo_[88].low[5] = -3.5489281250e+04;
		asali_->thermo_[88].low[6] = 1.7283546448e+01;
		
		asali_->thermo_[89].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[89].name,"C3H6O");

		asali_->thermo_[89].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[89].high[0] = 6.4275488853e+00;
		asali_->thermo_[89].high[1] = 2.0081851631e-02;
		asali_->thermo_[89].high[2] = -6.5546469159e-06;
		asali_->thermo_[89].high[3] = 4.8430681687e-10;
		asali_->thermo_[89].high[4] = 5.6889368704e-14;
		asali_->thermo_[89].high[5] = -1.4803572266e+04;
		asali_->thermo_[89].high[6] = -9.7199506760e+00;

		asali_->thermo_[89].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[89].low[0] = -9.9978081882e-02;
		asali_->thermo_[89].low[1] = 3.5262148827e-02;
		asali_->thermo_[89].low[2] = -1.9793276806e-05;
		asali_->thermo_[89].low[3] = 5.6155586847e-09;
		asali_->thermo_[89].low[4] = -6.8893214701e-13;
		asali_->thermo_[89].low[5] = -1.2558103516e+04;
		asali_->thermo_[89].low[6] = 2.5311632156e+01;
		
		asali_->thermo_[90].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[90].name,"C5H8");

		asali_->thermo_[90].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[90].high[0] = 8.9582920074e+00;
		asali_->thermo_[90].high[1] = 2.5103300810e-02;
		asali_->thermo_[90].high[2] = -8.4367920863e-06;
		asali_->thermo_[90].high[3] = 8.1990564338e-10;
		asali_->thermo_[90].high[4] = 3.1142650308e-14;
		asali_->thermo_[90].high[5] = 4.6795332031e+03;
		asali_->thermo_[90].high[6] = -2.4043962479e+01;

		asali_->thermo_[90].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[90].low[0] = 1.1918350458e+00;
		asali_->thermo_[90].low[1] = 4.6827655286e-02;
		asali_->thermo_[90].low[2] = -3.1224575650e-05;
		asali_->thermo_[90].low[3] = 1.1443581194e-08;
		asali_->thermo_[90].low[4] = -1.8261431863e-12;
		asali_->thermo_[90].low[5] = 6.9007397461e+03;
		asali_->thermo_[90].low[6] = 1.6202564240e+01;
		
		asali_->thermo_[91].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[91].name,"C16H10");

		asali_->thermo_[91].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[91].high[0] = 3.5520595551e+01;
		asali_->thermo_[91].high[1] = 2.9705923051e-02;
		asali_->thermo_[91].high[2] = -5.1857741710e-06;
		asali_->thermo_[91].high[3] = -7.7497658291e-10;
		asali_->thermo_[91].high[4] = 2.0576430642e-13;
		asali_->thermo_[91].high[5] = 1.1399803711e+04;
		asali_->thermo_[91].high[6] = -1.7258465576e+02;

		asali_->thermo_[91].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[91].low[0] = -1.4314951897e+01;
		asali_->thermo_[91].low[1] = 1.6910605133e-01;
		asali_->thermo_[91].low[2] = -1.5140969481e-04;
		asali_->thermo_[91].low[3] = 6.7394680059e-08;
		asali_->thermo_[91].low[4] = -1.1712008099e-11;
		asali_->thermo_[91].low[5] = 2.5652769531e+04;
		asali_->thermo_[91].low[6] = 8.5667961121e+01;
		
		asali_->thermo_[92].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[92].name,"C6H5C2H3");

		asali_->thermo_[92].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[92].high[0] = 1.5761212349e+01;
		asali_->thermo_[92].high[1] = 2.5134472176e-02;
		asali_->thermo_[92].high[2] = -7.0834894359e-06;
		asali_->thermo_[92].high[3] = 3.1235583564e-10;
		asali_->thermo_[92].high[4] = 8.2298581741e-14;
		asali_->thermo_[92].high[5] = 1.0134689453e+04;
		asali_->thermo_[92].high[6] = -5.9585994720e+01;

		asali_->thermo_[92].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[92].low[0] = -4.6189041138e+00;
		asali_->thermo_[92].low[1] = 8.2543253899e-02;
		asali_->thermo_[92].low[2] = -6.7726563429e-05;
		asali_->thermo_[92].low[3] = 2.8783283312e-08;
		asali_->thermo_[92].low[4] = -4.9301886358e-12;
		asali_->thermo_[92].low[5] = 1.5922642578e+04;
		asali_->thermo_[92].low[6] = 4.5882713318e+01;
		
		asali_->thermo_[93].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[93].name,"TAME");

		asali_->thermo_[93].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[93].high[0] = 1.1330976486e+01;
		asali_->thermo_[93].high[1] = 4.7428093851e-02;
		asali_->thermo_[93].high[2] = -1.9695749870e-05;
		asali_->thermo_[93].high[3] = 3.6686074179e-09;
		asali_->thermo_[93].high[4] = -2.5068822344e-13;
		asali_->thermo_[93].high[5] = -4.4274519531e+04;
		asali_->thermo_[93].high[6] = -3.1795238495e+01;

		asali_->thermo_[93].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[93].low[0] = -2.1283671856e+00;
		asali_->thermo_[93].low[1] = 8.8213980198e-02;
		asali_->thermo_[93].low[2] = -6.6043350671e-05;
		asali_->thermo_[93].low[3] = 2.7076486830e-08;
		asali_->thermo_[93].low[4] = -4.6839988485e-12;
		asali_->thermo_[93].low[5] = -4.0721253906e+04;
		asali_->thermo_[93].low[6] = 3.6875053406e+01;
		
		asali_->thermo_[94].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[94].name,"TETRALIN");

		asali_->thermo_[94].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[94].high[0] = 2.4025068283e+01;
		asali_->thermo_[94].high[1] = 3.4503169358e-02;
		asali_->thermo_[94].high[2] = -1.2656553736e-05;
		asali_->thermo_[94].high[3] = 2.2063246785e-09;
		asali_->thermo_[94].high[4] = -1.5194120376e-13;
		asali_->thermo_[94].high[5] = -9.8531435547e+03;
		asali_->thermo_[94].high[6] = -1.1116176605e+02;

		asali_->thermo_[94].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[94].low[0] = -1.0080733299e+01;
		asali_->thermo_[94].low[1] = 1.1718390137e-01;
		asali_->thermo_[94].low[2] = -8.7820852059e-05;
		asali_->thermo_[94].low[3] = 3.2575737663e-08;
		asali_->thermo_[94].low[4] = -4.7533678382e-12;
		asali_->thermo_[94].low[5] = 1.4017711182e+03;
		asali_->thermo_[94].low[6] = 7.0458351135e+01;
		
		asali_->thermo_[95].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[95].name,"DECALIN");

		asali_->thermo_[95].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[95].high[0] = 2.7011030197e+01;
		asali_->thermo_[95].high[1] = 4.6874817461e-02;
		asali_->thermo_[95].high[2] = -1.6389549273e-05;
		asali_->thermo_[95].high[3] = 2.6256368191e-09;
		asali_->thermo_[95].high[4] = -1.5978972973e-13;
		asali_->thermo_[95].high[5] = -3.7922628906e+04;
		asali_->thermo_[95].high[6] = -1.3516773987e+02;

		asali_->thermo_[95].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[95].low[0] = -1.4587078094e+01;
		asali_->thermo_[95].low[1] = 1.4195621014e-01;
		asali_->thermo_[95].low[2] = -9.7887881566e-05;
		asali_->thermo_[95].low[3] = 3.3672620248e-08;
		asali_->thermo_[95].low[4] = -4.5950730200e-12;
		asali_->thermo_[95].low[5] = -2.3363291016e+04;
		asali_->thermo_[95].low[6] = 8.8798034668e+01;
		
		asali_->thermo_[96].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[96].name,"C7H8");

		asali_->thermo_[96].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[96].high[0] = 1.2581844330e+01;
		asali_->thermo_[96].high[1] = 2.6413451880e-02;
		asali_->thermo_[96].high[2] = -7.9379988165e-06;
		asali_->thermo_[96].high[3] = 4.3836823060e-10;
		asali_->thermo_[96].high[4] = 8.6407897710e-14;
		asali_->thermo_[96].high[5] = -5.6447131348e+02;
		asali_->thermo_[96].high[6] = -4.4524784088e+01;

		asali_->thermo_[96].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[96].low[0] = -6.0288496017e+00;
		asali_->thermo_[96].low[1] = 7.7753297985e-02;
		asali_->thermo_[96].low[2] = -6.1048187490e-05;
		asali_->thermo_[96].low[3] = 2.4856843694e-08;
		asali_->thermo_[96].low[4] = -4.1236740585e-12;
		asali_->thermo_[96].low[5] = 4.8326298828e+03;
		asali_->thermo_[96].low[6] = 5.2176113129e+01;
		
		asali_->thermo_[97].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[97].name,"XYLENE");

		asali_->thermo_[97].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[97].high[0] = 1.7225624084e+01;
		asali_->thermo_[97].high[1] = 2.8356559575e-02;
		asali_->thermo_[97].high[2] = -6.9068996709e-06;
		asali_->thermo_[97].high[3] = -3.5709141200e-10;
		asali_->thermo_[97].high[4] = 2.0941962628e-13;
		asali_->thermo_[97].high[5] = -6.8723935547e+03;
		asali_->thermo_[97].high[6] = -6.9734161377e+01;

		asali_->thermo_[97].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[97].low[0] = -5.1230397224e+00;
		asali_->thermo_[97].low[1] = 8.2865498960e-02;
		asali_->thermo_[97].low[2] = -5.6762633903e-05;
		asali_->thermo_[97].low[3] = 1.9909467852e-08;
		asali_->thermo_[97].low[4] = -2.8799948537e-12;
		asali_->thermo_[97].low[5] = 4.5796841431e+02;
		asali_->thermo_[97].low[6] = 4.9141025543e+00;
		
		asali_->thermo_[98].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[98].name,"NC16H34");

		asali_->thermo_[98].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[98].high[0] = 4.9821022034e+01;
		asali_->thermo_[98].high[1] = 7.7388167381e-02;
		asali_->thermo_[98].high[2] = -2.7755790143e-05;
		asali_->thermo_[98].high[3] = 4.6967811862e-09;
		asali_->thermo_[98].high[4] = -3.1295923969e-13;
		asali_->thermo_[98].high[5] = -7.0851468750e+04;
		asali_->thermo_[98].high[6] = -2.2484284973e+02;

		asali_->thermo_[98].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[98].low[0] = -3.6405797005e+00;
		asali_->thermo_[98].low[1] = 1.9619172812e-01;
		asali_->thermo_[98].low[2] = -1.2675876496e-04;
		asali_->thermo_[98].low[3] = 4.1364547343e-08;
		asali_->thermo_[98].low[4] = -5.4057045298e-12;
		asali_->thermo_[98].low[5] = -5.1605289062e+04;
		asali_->thermo_[98].low[6] = 6.4502494812e+01;
		
		asali_->thermo_[99].name = (char*) malloc(4 * sizeof(char));
		strcpy(asali_->thermo_[99].name,"N2H4");

		asali_->thermo_[99].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[99].high[0] = 4.9191436768e+00;
		asali_->thermo_[99].high[1] = 9.7118793055e-03;
		asali_->thermo_[99].high[2] = -3.6292535697e-06;
		asali_->thermo_[99].high[3] = 6.3653093907e-10;
		asali_->thermo_[99].high[4] = -4.2850895358e-14;
		asali_->thermo_[99].high[5] = 9.3630458984e+03;
		asali_->thermo_[99].high[6] = -2.6439564228e+00;

		asali_->thermo_[99].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[99].low[0] = 3.6042565107e-01;
		asali_->thermo_[99].low[1] = 2.5431597605e-02;
		asali_->thermo_[99].low[2] = -2.3956474251e-05;
		asali_->thermo_[99].low[3] = 1.2318841947e-08;
		asali_->thermo_[99].low[4] = -2.5605904116e-12;
		asali_->thermo_[99].low[5] = 1.0420668945e+04;
		asali_->thermo_[99].low[6] = 2.0025827408e+01;
		
		asali_->thermo_[100].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[100].name,"N2O");

		asali_->thermo_[100].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[100].high[0] = 5.5212912560e+00;
		asali_->thermo_[100].high[1] = 1.4664595947e-03;
		asali_->thermo_[100].high[2] = -3.0469408330e-07;
		asali_->thermo_[100].high[3] = -1.8710685779e-11;
		asali_->thermo_[100].high[4] = 8.5038906120e-15;
		asali_->thermo_[100].high[5] = 7.8131225586e+03;
		asali_->thermo_[100].high[6] = -6.1745166779e+00;

		asali_->thermo_[100].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[100].low[0] = 2.6852197647e+00;
		asali_->thermo_[100].low[1] = 8.3417855203e-03;
		asali_->thermo_[100].low[2] = -6.5549897954e-06;
		asali_->thermo_[100].low[3] = 2.5066613230e-09;
		asali_->thermo_[100].low[4] = -3.7412824574e-13;
		asali_->thermo_[100].low[5] = 8.7490263672e+03;
		asali_->thermo_[100].low[6] = 8.9281244278e+00;
		
		asali_->thermo_[101].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[101].name,"NH3");

		asali_->thermo_[101].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[101].high[0] = 2.2111797333e+00;
		asali_->thermo_[101].high[1] = 6.5218247473e-03;
		asali_->thermo_[101].high[2] = -2.3093152777e-06;
		asali_->thermo_[101].high[3] = 3.9890712955e-10;
		asali_->thermo_[101].high[4] = -2.8038564241e-14;
		asali_->thermo_[101].high[5] = -6.3900961914e+03;
		asali_->thermo_[101].high[6] = 8.8690557480e+00;

		asali_->thermo_[101].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[101].low[0] = 3.2168917656e+00;
		asali_->thermo_[101].low[1] = 3.1971565913e-03;
		asali_->thermo_[101].low[2] = 1.8121737639e-06;
		asali_->thermo_[101].low[3] = -1.8718857575e-09;
		asali_->thermo_[101].low[4] = 4.4113351210e-13;
		asali_->thermo_[101].low[5] = -6.6334785156e+03;
		asali_->thermo_[101].low[6] = 3.8253676891e+00;
		
		asali_->thermo_[102].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->thermo_[102].name,"NO");

		asali_->thermo_[102].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[102].high[0] = 2.6977500916e+00;
		asali_->thermo_[102].high[1] = 2.3988713510e-03;
		asali_->thermo_[102].high[2] = -1.3164469692e-06;
		asali_->thermo_[102].high[3] = 3.3823580048e-10;
		asali_->thermo_[102].high[4] = -3.2939488404e-14;
		asali_->thermo_[102].high[5] = 9.9985439453e+03;
		asali_->thermo_[102].high[6] = 9.4023084641e+00;

		asali_->thermo_[102].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[102].low[0] = 3.9129018784e+00;
		asali_->thermo_[102].low[1] = -2.6120636612e-03;
		asali_->thermo_[102].low[2] = 6.4324217419e-06;
		asali_->thermo_[102].low[3] = -4.9874468999e-09;
		asali_->thermo_[102].low[4] = 1.3396591779e-12;
		asali_->thermo_[102].low[5] = 9.7628037109e+03;
		asali_->thermo_[102].low[6] = 3.5769159794e+00;
		
		asali_->thermo_[103].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[103].name,"NO2");

		asali_->thermo_[103].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[103].high[0] = 5.2567367554e+00;
		asali_->thermo_[103].high[1] = 1.6434331192e-03;
		asali_->thermo_[103].high[2] = -6.2419792357e-07;
		asali_->thermo_[103].high[3] = 1.0706514841e-10;
		asali_->thermo_[103].high[4] = -6.8858476186e-15;
		asali_->thermo_[103].high[5] = 1.9536356201e+03;
		asali_->thermo_[103].high[6] = -2.3582756519e+00;

		asali_->thermo_[103].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[103].low[0] = 2.6140959263e+00;
		asali_->thermo_[103].low[1] = 7.5159682892e-03;
		asali_->thermo_[103].low[2] = -5.5179775700e-06;
		asali_->thermo_[103].low[3] = 1.9195760537e-09;
		asali_->thermo_[103].low[4] = -2.5862347203e-13;
		asali_->thermo_[103].low[5] = 2.9049863281e+03;
		asali_->thermo_[103].low[6] = 1.1944248199e+01;
		
		asali_->thermo_[104].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[104].name,"C3H5OOH");

		asali_->thermo_[104].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[104].high[0] = 1.2137720108e+01;
		asali_->thermo_[104].high[1] = 1.6858547926e-02;
		asali_->thermo_[104].high[2] = -6.9427510425e-06;
		asali_->thermo_[104].high[3] = 1.3695889978e-09;
		asali_->thermo_[104].high[4] = -1.0742746075e-13;
		asali_->thermo_[104].high[5] = -1.2526590820e+04;
		asali_->thermo_[104].high[6] = -3.5719470978e+01;

		asali_->thermo_[104].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[104].low[0] = 2.2465109825e+00;
		asali_->thermo_[104].low[1] = 3.8839012384e-02;
		asali_->thermo_[104].low[2] = -2.5259803806e-05;
		asali_->thermo_[104].low[3] = 8.1536830621e-09;
		asali_->thermo_[104].low[4] = -1.0496627439e-12;
		asali_->thermo_[104].low[5] = -8.9657548828e+03;
		asali_->thermo_[104].low[6] = 1.7813814163e+01;
		
		asali_->thermo_[105].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[105].name,"NC3H7OH");

		asali_->thermo_[105].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[105].high[0] = 1.0357866287e+01;
		asali_->thermo_[105].high[1] = 1.8783450127e-02;
		asali_->thermo_[105].high[2] = -6.5415511017e-06;
		asali_->thermo_[105].high[3] = 1.0679269691e-09;
		asali_->thermo_[105].high[4] = -6.7910155038e-14;
		asali_->thermo_[105].high[5] = -3.6005445312e+04;
		asali_->thermo_[105].high[6] = -2.8922452927e+01;

		asali_->thermo_[105].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[105].low[0] = 2.3463635147e-01;
		asali_->thermo_[105].low[1] = 4.1279517114e-02;
		asali_->thermo_[105].low[2] = -2.5288274628e-05;
		asali_->thermo_[105].low[3] = 8.0111570711e-09;
		asali_->thermo_[105].low[4] = -1.0322477465e-12;
		asali_->thermo_[105].low[5] = -3.2361082031e+04;
		asali_->thermo_[105].low[6] = 2.5866580963e+01;
		
		asali_->thermo_[106].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[106].name,"N1C4H9OH");

		asali_->thermo_[106].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[106].high[0] = 1.1907866478e+01;
		asali_->thermo_[106].high[1] = 2.6795992628e-02;
		asali_->thermo_[106].high[2] = -1.0794484297e-05;
		asali_->thermo_[106].high[3] = 2.1010615470e-09;
		asali_->thermo_[106].high[4] = -1.6353661047e-13;
		asali_->thermo_[106].high[5] = -3.9522117188e+04;
		asali_->thermo_[106].high[6] = -3.5738986969e+01;

		asali_->thermo_[106].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[106].low[0] = 7.7336005867e-02;
		asali_->thermo_[106].low[1] = 5.3086061031e-02;
		asali_->thermo_[106].low[2] = -3.2702871977e-05;
		asali_->thermo_[106].low[3] = 1.0215279289e-08;
		asali_->thermo_[106].low[4] = -1.2905113176e-12;
		asali_->thermo_[106].low[5] = -3.5263128906e+04;
		asali_->thermo_[106].low[6] = 2.8290309906e+01;
		
		asali_->thermo_[107].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[107].name,"N2C4H9OH");

		asali_->thermo_[107].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[107].high[0] = 1.3985007286e+01;
		asali_->thermo_[107].high[1] = 2.3576822132e-02;
		asali_->thermo_[107].high[2] = -8.7310609160e-06;
		asali_->thermo_[107].high[3] = 1.5154616451e-09;
		asali_->thermo_[107].high[4] = -1.0284745874e-13;
		asali_->thermo_[107].high[5] = -4.2405398438e+04;
		asali_->thermo_[107].high[6] = -4.8370285034e+01;

		asali_->thermo_[107].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[107].low[0] = 1.1191295087e-01;
		asali_->thermo_[107].low[1] = 5.4405920208e-02;
		asali_->thermo_[107].low[2] = -3.4421977034e-05;
		asali_->thermo_[107].low[3] = 1.1030615532e-08;
		asali_->thermo_[107].low[4] = -1.4243966250e-12;
		asali_->thermo_[107].low[5] = -3.7411085938e+04;
		asali_->thermo_[107].low[6] = 2.6713796616e+01;
		
		asali_->thermo_[108].name = (char*) malloc(3 * sizeof(char));
		strcpy(asali_->thermo_[108].name,"MEK");

		asali_->thermo_[108].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[108].high[0] = 1.0099667549e+01;
		asali_->thermo_[108].high[1] = 2.2285092622e-02;
		asali_->thermo_[108].high[2] = -8.2411279436e-06;
		asali_->thermo_[108].high[3] = 1.4276037019e-09;
		asali_->thermo_[108].high[4] = -9.7765491449e-14;
		asali_->thermo_[108].high[5] = -3.4027093750e+04;
		asali_->thermo_[108].high[6] = -2.5500280380e+01;

		asali_->thermo_[108].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[108].low[0] = 1.6713862419e+00;
		asali_->thermo_[108].low[1] = 4.1014607996e-02;
		asali_->thermo_[108].low[2] = -2.3849055651e-05;
		asali_->thermo_[108].low[3] = 7.2083179425e-09;
		asali_->thermo_[108].low[4] = -9.0064246209e-13;
		asali_->thermo_[108].low[5] = -3.0992914062e+04;
		asali_->thermo_[108].low[6] = 2.0115335464e+01;
		
		asali_->thermo_[109].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[109].name,"TC4H9OH");

		asali_->thermo_[109].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[109].high[0] = 9.0815038681e+00;
		asali_->thermo_[109].high[1] = 3.2220184803e-02;
		asali_->thermo_[109].high[2] = -1.4197935343e-05;
		asali_->thermo_[109].high[3] = 3.0324927014e-09;
		asali_->thermo_[109].high[4] = -2.5665835559e-13;
		asali_->thermo_[109].high[5] = -4.2391722656e+04;
		asali_->thermo_[109].high[6] = -2.3626321793e+01;

		asali_->thermo_[109].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[109].low[0] = -6.9999957085e-01;
		asali_->thermo_[109].low[1] = 5.9391025454e-02;
		asali_->thermo_[109].low[2] = -4.2500898417e-05;
		asali_->thermo_[109].low[3] = 1.6135714986e-08;
		asali_->thermo_[109].low[4] = -2.5315233850e-12;
		asali_->thermo_[109].low[5] = -3.9574648438e+04;
		asali_->thermo_[109].low[6] = 2.7130535126e+01;
		
		asali_->thermo_[110].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[110].name,"IC4H9OH");

		asali_->thermo_[110].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[110].high[0] = 1.4453751564e+01;
		asali_->thermo_[110].high[1] = 2.2081069648e-02;
		asali_->thermo_[110].high[2] = -7.5795928751e-06;
		asali_->thermo_[110].high[3] = 1.1953367185e-09;
		asali_->thermo_[110].high[4] = -7.1616757663e-14;
		asali_->thermo_[110].high[5] = -4.1582281250e+04;
		asali_->thermo_[110].high[6] = -5.1331550598e+01;

		asali_->thermo_[110].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[110].low[0] = -5.4547947645e-01;
		asali_->thermo_[110].low[1] = 5.5412694812e-02;
		asali_->thermo_[110].low[2] = -3.5355948057e-05;
		asali_->thermo_[110].low[3] = 1.1482875095e-08;
		asali_->thermo_[110].low[4] = -1.5004415896e-12;
		asali_->thermo_[110].low[5] = -3.6182558594e+04;
		asali_->thermo_[110].low[6] = 2.9847417831e+01;
		
		asali_->thermo_[111].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[111].name,"C4H7OH");

		asali_->thermo_[111].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[111].high[0] = 1.0098166466e+01;
		asali_->thermo_[111].high[1] = 2.1573493257e-02;
		asali_->thermo_[111].high[2] = -6.7400842454e-06;
		asali_->thermo_[111].high[3] = 9.1682594849e-10;
		asali_->thermo_[111].high[4] = -4.1620017572e-14;
		asali_->thermo_[111].high[5] = -2.3729091797e+04;
		asali_->thermo_[111].high[6] = -2.4574159622e+01;

		asali_->thermo_[111].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[111].low[0] = -2.5553134084e-01;
		asali_->thermo_[111].low[1] = 4.9939788878e-02;
		asali_->thermo_[111].low[2] = -3.5883538658e-05;
		asali_->thermo_[111].low[3] = 1.4224339040e-08;
		asali_->thermo_[111].low[4] = -2.3203038883e-12;
		asali_->thermo_[111].low[5] = -2.0705810547e+04;
		asali_->thermo_[111].low[6] = 2.9294664383e+01;
		
		asali_->thermo_[112].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[112].name,"C3H5OH");

		asali_->thermo_[112].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[112].high[0] = 2.4586317539e+00;
		asali_->thermo_[112].high[1] = 2.6644645259e-02;
		asali_->thermo_[112].high[2] = -1.2487976164e-05;
		asali_->thermo_[112].high[3] = 2.9219879849e-09;
		asali_->thermo_[112].high[4] = -2.7187269363e-13;
		asali_->thermo_[112].high[5] = -1.7224000000e+04;
		asali_->thermo_[112].high[6] = 1.8383033752e+01;

		asali_->thermo_[112].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[112].low[0] = 4.2499928474e+00;
		asali_->thermo_[112].low[1] = 1.7906298861e-02;
		asali_->thermo_[112].low[2] = 3.4968049931e-06;
		asali_->thermo_[112].low[3] = -1.0073768486e-08;
		asali_->thermo_[112].low[4] = 3.6902481938e-12;
		asali_->thermo_[112].low[5] = -1.7517783203e+04;
		asali_->thermo_[112].low[6] = 1.0096249580e+01;
		
		asali_->thermo_[113].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[113].name,"C10H10");

		asali_->thermo_[113].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[113].high[0] = 1.8259269714e+01;
		asali_->thermo_[113].high[1] = 4.1593421251e-02;
		asali_->thermo_[113].high[2] = -1.8363183699e-05;
		asali_->thermo_[113].high[3] = 3.8849115036e-09;
		asali_->thermo_[113].high[4] = -3.2742081615e-13;
		asali_->thermo_[113].high[5] = 4.3968784180e+03;
		asali_->thermo_[113].high[6] = -8.2392318726e+01;

		asali_->thermo_[113].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[113].low[0] = -1.1458896637e+01;
		asali_->thermo_[113].low[1] = 1.0763379186e-01;
		asali_->thermo_[113].low[2] = -7.3396826338e-05;
		asali_->thermo_[113].low[3] = 2.4267741594e-08;
		asali_->thermo_[113].low[4] = -3.1583693993e-12;
		asali_->thermo_[113].low[5] = 1.5095417969e+04;
		asali_->thermo_[113].low[6] = 7.8448593140e+01;
		
		asali_->thermo_[114].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[114].name,"BZFUR");

		asali_->thermo_[114].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[114].high[0] = 1.6457834244e+01;
		asali_->thermo_[114].high[1] = 2.3762356490e-02;
		asali_->thermo_[114].high[2] = -8.5221863628e-06;
		asali_->thermo_[114].high[3] = 1.3612371230e-09;
		asali_->thermo_[114].high[4] = -7.9715991837e-14;
		asali_->thermo_[114].high[5] = -5.9059697266e+03;
		asali_->thermo_[114].high[6] = -6.5948036194e+01;

		asali_->thermo_[114].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[114].low[0] = -8.7013692856e+00;
		asali_->thermo_[114].low[1] = 9.6687585115e-02;
		asali_->thermo_[114].low[2] = -8.7788735982e-05;
		asali_->thermo_[114].low[3] = 3.9654256767e-08;
		asali_->thermo_[114].low[4] = -7.0168571474e-12;
		asali_->thermo_[114].low[5] = 1.0379702148e+03;
		asali_->thermo_[114].low[6] = 6.3533935547e+01;
		
		asali_->thermo_[115].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[115].name,"TMBENZ");

		asali_->thermo_[115].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[115].high[0] = 1.4757685661e+01;
		asali_->thermo_[115].high[1] = 4.5031581074e-02;
		asali_->thermo_[115].high[2] = -1.9755419999e-05;
		asali_->thermo_[115].high[3] = 4.2119783217e-09;
		asali_->thermo_[115].high[4] = -3.5731492634e-13;
		asali_->thermo_[115].high[5] = -1.0902583984e+04;
		asali_->thermo_[115].high[6] = -5.3537837982e+01;

		asali_->thermo_[115].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[115].low[0] = -2.7552278042e+00;
		asali_->thermo_[115].low[1] = 8.3949171007e-02;
		asali_->thermo_[115].low[2] = -5.2186740504e-05;
		asali_->thermo_[115].low[3] = 1.6223578925e-08;
		asali_->thermo_[115].low[4] = -2.0255928011e-12;
		asali_->thermo_[115].low[5] = -4.5979350586e+03;
		asali_->thermo_[115].low[6] = 4.1245704651e+01;
		
		asali_->thermo_[116].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[116].name,"NPBENZ");

		asali_->thermo_[116].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[116].high[0] = 1.8896337509e+01;
		asali_->thermo_[116].high[1] = 3.8009028882e-02;
		asali_->thermo_[116].high[2] = -1.5278938008e-05;
		asali_->thermo_[116].high[3] = 2.9563009818e-09;
		asali_->thermo_[116].high[4] = -2.2769920715e-13;
		asali_->thermo_[116].high[5] = -8.9660527344e+03;
		asali_->thermo_[116].high[6] = -7.6271125793e+01;

		asali_->thermo_[116].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[116].low[0] = -5.5865015984e+00;
		asali_->thermo_[116].low[1] = 9.9216125906e-02;
		asali_->thermo_[116].low[2] = -7.2660594014e-05;
		asali_->thermo_[116].low[3] = 2.6865322411e-08;
		asali_->thermo_[116].low[4] = -3.9634840548e-12;
		asali_->thermo_[116].low[5] = -1.1315444336e+03;
		asali_->thermo_[116].low[6] = 5.3351440430e+01;
		
		asali_->thermo_[117].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[117].name,"C6H5OCH3");

		asali_->thermo_[117].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[117].high[0] = 1.2508513451e+01;
		asali_->thermo_[117].high[1] = 3.4990612417e-02;
		asali_->thermo_[117].high[2] = -1.6309608327e-05;
		asali_->thermo_[117].high[3] = 3.6483682742e-09;
		asali_->thermo_[117].high[4] = -3.1998839342e-13;
		asali_->thermo_[117].high[5] = -1.5203879883e+04;
		asali_->thermo_[117].high[6] = -4.2040649414e+01;

		asali_->thermo_[117].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[117].low[0] = -5.2946157455e+00;
		asali_->thermo_[117].low[1] = 8.6593888700e-02;
		asali_->thermo_[117].low[2] = -7.2400122008e-05;
		asali_->thermo_[117].low[3] = 3.0745233914e-08;
		asali_->thermo_[117].low[4] = -5.2288412315e-12;
		asali_->thermo_[117].low[5] = -1.0290215820e+04;
		asali_->thermo_[117].low[6] = 4.9583251953e+01;
		
		asali_->thermo_[118].name = (char*) malloc(2 * sizeof(char));
		strcpy(asali_->thermo_[118].name,"MB");

		asali_->thermo_[118].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[118].high[0] = 1.2428421974e+01;
		asali_->thermo_[118].high[1] = 3.5713344812e-02;
		asali_->thermo_[118].high[2] = -1.6159288862e-05;
		asali_->thermo_[118].high[3] = 3.5209410942e-09;
		asali_->thermo_[118].high[4] = -3.0269352563e-13;
		asali_->thermo_[118].high[5] = -6.0770234375e+04;
		asali_->thermo_[118].high[6] = -3.6522068024e+01;

		asali_->thermo_[118].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[118].low[0] = 2.7783131599e+00;
		asali_->thermo_[118].low[1] = 5.7158030570e-02;
		asali_->thermo_[118].low[2] = -3.4029861126e-05;
		asali_->thermo_[118].low[3] = 1.0139671325e-08;
		asali_->thermo_[118].low[4] = -1.2219616595e-12;
		asali_->thermo_[118].low[5] = -5.7296195312e+04;
		asali_->thermo_[118].low[6] = 1.5706335068e+01;
		
		asali_->thermo_[119].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[119].name,"MCROT");

		asali_->thermo_[119].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[119].high[0] = 1.1373885155e+01;
		asali_->thermo_[119].high[1] = 2.6131803170e-02;
		asali_->thermo_[119].high[2] = -8.7485514086e-06;
		asali_->thermo_[119].high[3] = 1.3583151270e-09;
		asali_->thermo_[119].high[4] = -8.0017501685e-14;
		asali_->thermo_[119].high[5] = -4.6306214844e+04;
		asali_->thermo_[119].high[6] = -2.5480146408e+01;

		asali_->thermo_[119].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[119].low[0] = 2.7206471562e-01;
		asali_->thermo_[119].low[1] = 6.1098165810e-02;
		asali_->thermo_[119].low[2] = -5.0047405239e-05;
		asali_->thermo_[119].low[3] = 2.3037502572e-08;
		asali_->thermo_[119].low[4] = -4.3475743838e-12;
		asali_->thermo_[119].low[5] = -4.3486351562e+04;
		asali_->thermo_[119].low[6] = 3.0733240128e+01;
		
		asali_->thermo_[120].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[120].name,"MACRIL");

		asali_->thermo_[120].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[120].high[0] = 9.1403417587e+00;
		asali_->thermo_[120].high[1] = 2.1087048575e-02;
		asali_->thermo_[120].high[2] = -7.4225922617e-06;
		asali_->thermo_[120].high[3] = 1.2504433045e-09;
		asali_->thermo_[120].high[4] = -8.3306408646e-14;
		asali_->thermo_[120].high[5] = -4.1282777344e+04;
		asali_->thermo_[120].high[6] = -1.5026798248e+01;

		asali_->thermo_[120].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[120].low[0] = -1.1313576698e+00;
		asali_->thermo_[120].low[1] = 5.8102183044e-02;
		asali_->thermo_[120].low[2] = -5.7443041442e-05;
		asali_->thermo_[120].low[3] = 3.1292756830e-08;
		asali_->thermo_[120].low[4] = -6.8495929414e-12;
		asali_->thermo_[120].low[5] = -3.9002460938e+04;
		asali_->thermo_[120].low[6] = 3.5600170135e+01;
		
		asali_->thermo_[121].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[121].name,"DIBZFUR");

		asali_->thermo_[121].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[121].high[0] = 2.4952526093e+01;
		asali_->thermo_[121].high[1] = 3.2473072410e-02;
		asali_->thermo_[121].high[2] = -1.1545937014e-05;
		asali_->thermo_[121].high[3] = 1.7967904942e-09;
		asali_->thermo_[121].high[4] = -9.9783367875e-14;
		asali_->thermo_[121].high[5] = -5.3075366211e+03;
		asali_->thermo_[121].high[6] = -1.1335589600e+02;

		asali_->thermo_[121].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[121].low[0] = -1.1697090149e+01;
		asali_->thermo_[121].low[1] = 1.3644361496e-01;
		asali_->thermo_[121].low[2] = -1.2215289462e-04;
		asali_->thermo_[121].low[3] = 5.4093224122e-08;
		asali_->thermo_[121].low[4] = -9.3722009320e-12;
		asali_->thermo_[121].low[5] = 5.0276552734e+03;
		asali_->thermo_[121].low[6] = 7.6049751282e+01;
		
		asali_->thermo_[122].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[122].name,"DIFENET");

		asali_->thermo_[122].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[122].high[0] = 1.7154809952e+01;
		asali_->thermo_[122].high[1] = 5.2537418902e-02;
		asali_->thermo_[122].high[2] = -2.4565722924e-05;
		asali_->thermo_[122].high[3] = 5.5824478373e-09;
		asali_->thermo_[122].high[4] = -4.9940992097e-13;
		asali_->thermo_[122].high[5] = -3.2970439453e+03;
		asali_->thermo_[122].high[6] = -6.4998565674e+01;

		asali_->thermo_[122].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[122].low[0] = -8.5745811462e+00;
		asali_->thermo_[122].low[1] = 1.2450774759e-01;
		asali_->thermo_[122].low[2] = -1.0005907097e-04;
		asali_->thermo_[122].low[3] = 4.0777482724e-08;
		asali_->thermo_[122].low[4] = -6.6523878420e-12;
		asali_->thermo_[122].low[5] = 4.0615620117e+03;
		asali_->thermo_[122].low[6] = 6.8333618164e+01;
		
		asali_->thermo_[123].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[123].name,"C12H22");

		asali_->thermo_[123].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[123].high[0] = 3.6068786621e+01;
		asali_->thermo_[123].high[1] = 4.9353178591e-02;
		asali_->thermo_[123].high[2] = -1.6893278371e-05;
		asali_->thermo_[123].high[3] = 2.6486688398e-09;
		asali_->thermo_[123].high[4] = -1.5693474081e-13;
		asali_->thermo_[123].high[5] = -2.2929115234e+04;
		asali_->thermo_[123].high[6] = -1.5868997192e+02;

		asali_->thermo_[123].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[123].low[0] = -2.7185525894e+00;
		asali_->thermo_[123].low[1] = 1.3750621676e-01;
		asali_->thermo_[123].low[2] = -9.2023707111e-05;
		asali_->thermo_[123].low[3] = 3.1107166620e-08;
		asali_->thermo_[123].low[4] = -4.1993348902e-12;
		asali_->thermo_[123].low[5] = -9.2759716797e+03;
		asali_->thermo_[123].low[6] = 5.0363533020e+01;
		
		
		asali_->thermo_[125].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[125].name,"C2H2O2");

		asali_->thermo_[125].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[125].high[0] = 9.8311653137e+00;
		asali_->thermo_[125].high[1] = 4.8736054450e-03;
		asali_->thermo_[125].high[2] = -1.6944329673e-06;
		asali_->thermo_[125].high[3] = 2.6536106645e-10;
		asali_->thermo_[125].high[4] = -1.5443983915e-14;
		asali_->thermo_[125].high[5] = -2.9627324219e+04;
		asali_->thermo_[125].high[6] = -2.6640703201e+01;

		asali_->thermo_[125].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[125].low[0] = 1.8994796276e+00;
		asali_->thermo_[125].low[1] = 2.3536395282e-02;
		asali_->thermo_[125].low[2] = -1.8161601474e-05;
		asali_->thermo_[125].low[3] = 6.7230740974e-09;
		asali_->thermo_[125].low[4] = -9.6510765959e-13;
		asali_->thermo_[125].low[5] = -2.6930550781e+04;
		asali_->thermo_[125].low[6] = 1.5833874702e+01;
		
		asali_->thermo_[126].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[126].name,"C4H6O2");

		asali_->thermo_[126].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[126].high[0] = 7.0191960335e+00;
		asali_->thermo_[126].high[1] = 2.8991995379e-02;
		asali_->thermo_[126].high[2] = -1.3981116354e-05;
		asali_->thermo_[126].high[3] = 3.2275047079e-09;
		asali_->thermo_[126].high[4] = -2.9088881369e-13;
		asali_->thermo_[126].high[5] = -4.3605570312e+04;
		asali_->thermo_[126].high[6] = -7.4784693718e+00;

		asali_->thermo_[126].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[126].low[0] = 9.1515827179e-01;
		asali_->thermo_[126].low[1] = 4.2556524277e-02;
		asali_->thermo_[126].low[2] = -2.5284889489e-05;
		asali_->thermo_[126].low[3] = 7.4140875661e-09;
		asali_->thermo_[126].low[4] = -8.7235860896e-13;
		asali_->thermo_[126].low[5] = -4.1408117188e+04;
		asali_->thermo_[126].low[6] = 2.5557855606e+01;
		
		asali_->thermo_[127].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[127].name,"C5H4O2");

		asali_->thermo_[127].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[127].high[0] = 1.0515895844e+01;
		asali_->thermo_[127].high[1] = 2.2322423756e-02;
		asali_->thermo_[127].high[2] = -1.0926709365e-05;
		asali_->thermo_[127].high[3] = 2.5668323023e-09;
		asali_->thermo_[127].high[4] = -2.3484499393e-13;
		asali_->thermo_[127].high[5] = -2.3330322266e+04;
		asali_->thermo_[127].high[6] = -2.9400037766e+01;

		asali_->thermo_[127].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[127].low[0] = -1.8199664354e+00;
		asali_->thermo_[127].low[1] = 5.6828331202e-02;
		asali_->thermo_[127].low[2] = -4.7121720854e-05;
		asali_->thermo_[127].low[3] = 1.9440962618e-08;
		asali_->thermo_[127].low[4] = -3.1848677341e-12;
		asali_->thermo_[127].low[5] = -1.9802265625e+04;
		asali_->thermo_[127].low[6] = 3.4525592804e+01;
		
		asali_->thermo_[128].name = (char*) malloc(6 * sizeof(char));
		strcpy(asali_->thermo_[128].name,"C5H8O4");

		asali_->thermo_[128].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[128].high[0] = 1.1960153580e+01;
		asali_->thermo_[128].high[1] = 3.9945084602e-02;
		asali_->thermo_[128].high[2] = -1.9594737751e-05;
		asali_->thermo_[128].high[3] = 4.6094013051e-09;
		asali_->thermo_[128].high[4] = -4.2230230272e-13;
		asali_->thermo_[128].high[5] = -8.2638585938e+04;
		asali_->thermo_[128].high[6] = -2.9187520981e+01;

		asali_->thermo_[128].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[128].low[0] = -6.9568324089e+00;
		asali_->thermo_[128].low[1] = 1.0146373510e-01;
		asali_->thermo_[128].low[2] = -9.4617484137e-05;
		asali_->thermo_[128].low[3] = 4.5272138038e-08;
		asali_->thermo_[128].low[4] = -8.6870857730e-12;
		asali_->thermo_[128].low[5] = -7.7985007812e+04;
		asali_->thermo_[128].low[6] = 6.5992088318e+01;
		
		asali_->thermo_[129].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[129].name,"C6H10O5");

		asali_->thermo_[129].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[129].high[0] = 1.5488971710e+01;
		asali_->thermo_[129].high[1] = 4.9635440111e-02;
		asali_->thermo_[129].high[2] = -2.4594450224e-05;
		asali_->thermo_[129].high[3] = 5.8233258216e-09;
		asali_->thermo_[129].high[4] = -5.3566585846e-13;
		asali_->thermo_[129].high[5] = -1.0918050781e+05;
		asali_->thermo_[129].high[6] = -4.8181983948e+01;

		asali_->thermo_[129].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[129].low[0] = -7.9511647224e+00;
		asali_->thermo_[129].low[1] = 1.2648834288e-01;
		asali_->thermo_[129].low[2] = -1.1908572924e-04;
		asali_->thermo_[129].low[3] = 5.7457903324e-08;
		asali_->thermo_[129].low[4] = -1.1116521766e-11;
		asali_->thermo_[129].low[5] = -1.0346111719e+05;
		asali_->thermo_[129].low[6] = 6.9564216614e+01;
		
		asali_->thermo_[130].name = (char*) malloc(7 * sizeof(char));
		strcpy(asali_->thermo_[130].name,"C8H10O3");

		asali_->thermo_[130].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[130].high[0] = 2.9895751953e+01;
		asali_->thermo_[130].high[1] = 4.7387052327e-02;
		asali_->thermo_[130].high[2] = -2.1160321921e-05;
		asali_->thermo_[130].high[3] = 4.6035038004e-09;
		asali_->thermo_[130].high[4] = -3.9634910480e-13;
		asali_->thermo_[130].high[5] = -7.0211945312e+04;
		asali_->thermo_[130].high[6] = -1.2116068268e+02;

		asali_->thermo_[130].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[130].low[0] = -3.0934867859e+00;
		asali_->thermo_[130].low[1] = 1.5047842264e-01;
		asali_->thermo_[130].low[2] = -1.4197052224e-04;
		asali_->thermo_[130].low[3] = 6.7525483871e-08;
		asali_->thermo_[130].low[4] = -1.2685798592e-11;
		asali_->thermo_[130].low[5] = -6.1766703125e+04;
		asali_->thermo_[130].low[6] = 4.6137050629e+01;
		
		asali_->thermo_[131].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[131].name,"HCOOH");

		asali_->thermo_[131].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[131].high[0] = 5.8057332039e+00;
		asali_->thermo_[131].high[1] = 6.8201739341e-03;
		asali_->thermo_[131].high[2] = -2.9548061775e-06;
		asali_->thermo_[131].high[3] = 6.1434007881e-10;
		asali_->thermo_[131].high[4] = -5.0675314775e-14;
		asali_->thermo_[131].high[5] = -4.8053441406e+04;
		asali_->thermo_[131].high[6] = -6.4299340248e+00;

		asali_->thermo_[131].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[131].low[0] = 1.3625650406e+00;
		asali_->thermo_[131].low[1] = 1.6693880782e-02;
		asali_->thermo_[131].low[2] = -1.1182894923e-05;
		asali_->thermo_[131].low[3] = 3.6617804344e-09;
		asali_->thermo_[131].low[4] = -4.7393089887e-13;
		asali_->thermo_[131].low[5] = -4.6453902344e+04;
		asali_->thermo_[131].low[6] = 1.7617418289e+01;
		
		asali_->thermo_[132].name = (char*) malloc(8 * sizeof(char));
		strcpy(asali_->thermo_[132].name,"GLYCEROL");

		asali_->thermo_[132].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[132].high[0] = 1.1479648590e+01;
		asali_->thermo_[132].high[1] = 2.3629246280e-02;
		asali_->thermo_[132].high[2] = -8.9838440545e-06;
		asali_->thermo_[132].high[3] = 1.7035514110e-09;
		asali_->thermo_[132].high[4] = -1.3152726250e-13;
		asali_->thermo_[132].high[5] = -7.4178109375e+04;
		asali_->thermo_[132].high[6] = -2.5670728683e+01;

		asali_->thermo_[132].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[132].low[0] = 1.9785080850e-01;
		asali_->thermo_[132].low[1] = 5.8611564338e-02;
		asali_->thermo_[132].low[2] = -4.9660960940e-05;
		asali_->thermo_[132].low[3] = 2.2725316740e-08;
		asali_->thermo_[132].low[4] = -4.2055126742e-12;
		asali_->thermo_[132].low[5] = -7.1267406250e+04;
		asali_->thermo_[132].low[6] = 3.1630247116e+01;
		
		asali_->thermo_[133].name = (char*) malloc(5 * sizeof(char));
		strcpy(asali_->thermo_[133].name,"C4H4O");

		asali_->thermo_[133].high = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[133].high[0] = 8.3748645782e+00;
		asali_->thermo_[133].high[1] = 1.9563445821e-02;
		asali_->thermo_[133].high[2] = -9.9016715467e-06;
		asali_->thermo_[133].high[3] = 2.3769437529e-09;
		asali_->thermo_[133].high[4] = -2.2051769590e-13;
		asali_->thermo_[133].high[5] = -9.4181757812e+03;
		asali_->thermo_[133].high[6] = -2.5205337524e+01;

		asali_->thermo_[133].low = (float*) malloc(7 * sizeof(float));
		asali_->thermo_[133].low[0] = -7.5950779915e+00;
		asali_->thermo_[133].low[1] = 7.0667259395e-02;
		asali_->thermo_[133].low[2] = -7.1226248110e-05;
		asali_->thermo_[133].low[3] = 3.5083385086e-08;
		asali_->thermo_[133].low[4] = -6.7618059589e-12;
		asali_->thermo_[133].low[5] = -5.4256899414e+03;
		asali_->thermo_[133].low[6] = 5.5403991699e+01;
	}
}
