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
 
{
    dsigma22_.push_back(0);
    dsigma22_.push_back(0.25);
    dsigma22_.push_back(0.5);
    dsigma22_.push_back(0.75);
    dsigma22_.push_back(1);
    dsigma22_.push_back(1.5);
    dsigma22_.push_back(2);
    dsigma22_.push_back(2.5);
}
 
{
    Tsigma22_.push_back(0.1);
    Tsigma22_.push_back(0.2);
    Tsigma22_.push_back(0.3);
    Tsigma22_.push_back(0.4);
    Tsigma22_.push_back(0.5);
    Tsigma22_.push_back(0.6);
    Tsigma22_.push_back(0.7);
    Tsigma22_.push_back(0.8);
    Tsigma22_.push_back(0.9);
    Tsigma22_.push_back(1);
    Tsigma22_.push_back(1.2);
    Tsigma22_.push_back(1.4);
    Tsigma22_.push_back(1.6);
    Tsigma22_.push_back(1.8);
    Tsigma22_.push_back(2);
    Tsigma22_.push_back(2.5);
    Tsigma22_.push_back(3);
    Tsigma22_.push_back(3.5);
    Tsigma22_.push_back(4);
    Tsigma22_.push_back(5);
    Tsigma22_.push_back(6);
    Tsigma22_.push_back(7);
    Tsigma22_.push_back(8);
    Tsigma22_.push_back(9);
    Tsigma22_.push_back(10);
    Tsigma22_.push_back(12);
    Tsigma22_.push_back(14);
    Tsigma22_.push_back(16);
    Tsigma22_.push_back(18);
    Tsigma22_.push_back(20);
    Tsigma22_.push_back(25);
    Tsigma22_.push_back(30);
    Tsigma22_.push_back(35);
    Tsigma22_.push_back(40);
    Tsigma22_.push_back(50);
    Tsigma22_.push_back(75);
    Tsigma22_.push_back(100);
}
 
 
sigmaMatrix22_.resize(37);
{
    sigmaMatrix22_[0].push_back(4.1005);
    sigmaMatrix22_[0].push_back(4.266);
    sigmaMatrix22_[0].push_back(4.833);
    sigmaMatrix22_[0].push_back(5.742);
    sigmaMatrix22_[0].push_back(6.729);
    sigmaMatrix22_[0].push_back(8.624);
    sigmaMatrix22_[0].push_back(10.34);
    sigmaMatrix22_[0].push_back(11.89);
 
    sigmaMatrix22_[1].push_back(3.2626);
    sigmaMatrix22_[1].push_back(3.305);
    sigmaMatrix22_[1].push_back(3.516);
    sigmaMatrix22_[1].push_back(3.914);
    sigmaMatrix22_[1].push_back(4.433);
    sigmaMatrix22_[1].push_back(5.57);
    sigmaMatrix22_[1].push_back(6.637);
    sigmaMatrix22_[1].push_back(7.618);
 
    sigmaMatrix22_[2].push_back(2.8399);
    sigmaMatrix22_[2].push_back(2.836);
    sigmaMatrix22_[2].push_back(2.936);
    sigmaMatrix22_[2].push_back(3.168);
    sigmaMatrix22_[2].push_back(3.511);
    sigmaMatrix22_[2].push_back(4.329);
    sigmaMatrix22_[2].push_back(5.126);
    sigmaMatrix22_[2].push_back(5.874);
 
    sigmaMatrix22_[3].push_back(2.531);
    sigmaMatrix22_[3].push_back(2.522);
    sigmaMatrix22_[3].push_back(2.586);
    sigmaMatrix22_[3].push_back(2.749);
    sigmaMatrix22_[3].push_back(3.004);
    sigmaMatrix22_[3].push_back(3.64);
    sigmaMatrix22_[3].push_back(4.282);
    sigmaMatrix22_[3].push_back(4.895);
 
    sigmaMatrix22_[4].push_back(2.2837);
    sigmaMatrix22_[4].push_back(2.277);
    sigmaMatrix22_[4].push_back(2.329);
    sigmaMatrix22_[4].push_back(2.46);
    sigmaMatrix22_[4].push_back(2.665);
    sigmaMatrix22_[4].push_back(3.187);
    sigmaMatrix22_[4].push_back(3.727);
    sigmaMatrix22_[4].push_back(4.249);
 
    sigmaMatrix22_[5].push_back(2.0838);
    sigmaMatrix22_[5].push_back(2.081);
    sigmaMatrix22_[5].push_back(2.13);
    sigmaMatrix22_[5].push_back(2.243);
    sigmaMatrix22_[5].push_back(2.417);
    sigmaMatrix22_[5].push_back(2.862);
    sigmaMatrix22_[5].push_back(3.329);
    sigmaMatrix22_[5].push_back(3.786);
 
    sigmaMatrix22_[6].push_back(1.922);
    sigmaMatrix22_[6].push_back(1.924);
    sigmaMatrix22_[6].push_back(1.97);
    sigmaMatrix22_[6].push_back(2.072);
    sigmaMatrix22_[6].push_back(2.225);
    sigmaMatrix22_[6].push_back(2.614);
    sigmaMatrix22_[6].push_back(3.028);
    sigmaMatrix22_[6].push_back(3.435);
 
    sigmaMatrix22_[7].push_back(1.7902);
    sigmaMatrix22_[7].push_back(1.795);
    sigmaMatrix22_[7].push_back(1.84);
    sigmaMatrix22_[7].push_back(1.934);
    sigmaMatrix22_[7].push_back(2.07);
    sigmaMatrix22_[7].push_back(2.417);
    sigmaMatrix22_[7].push_back(2.788);
    sigmaMatrix22_[7].push_back(3.156);
 
    sigmaMatrix22_[8].push_back(1.6823);
    sigmaMatrix22_[8].push_back(1.689);
    sigmaMatrix22_[8].push_back(1.733);
    sigmaMatrix22_[8].push_back(1.82);
    sigmaMatrix22_[8].push_back(1.944);
    sigmaMatrix22_[8].push_back(2.258);
    sigmaMatrix22_[8].push_back(2.596);
    sigmaMatrix22_[8].push_back(2.933);
 
    sigmaMatrix22_[9].push_back(1.5929);
    sigmaMatrix22_[9].push_back(1.601);
    sigmaMatrix22_[9].push_back(1.644);
    sigmaMatrix22_[9].push_back(1.725);
    sigmaMatrix22_[9].push_back(1.838);
    sigmaMatrix22_[9].push_back(2.124);
    sigmaMatrix22_[9].push_back(2.435);
    sigmaMatrix22_[9].push_back(2.746);
 
    sigmaMatrix22_[10].push_back(1.4551);
    sigmaMatrix22_[10].push_back(1.465);
    sigmaMatrix22_[10].push_back(1.504);
    sigmaMatrix22_[10].push_back(1.574);
    sigmaMatrix22_[10].push_back(1.67);
    sigmaMatrix22_[10].push_back(1.913);
    sigmaMatrix22_[10].push_back(2.181);
    sigmaMatrix22_[10].push_back(2.451);
 
    sigmaMatrix22_[11].push_back(1.3551);
    sigmaMatrix22_[11].push_back(1.365);
    sigmaMatrix22_[11].push_back(1.4);
    sigmaMatrix22_[11].push_back(1.461);
    sigmaMatrix22_[11].push_back(1.544);
    sigmaMatrix22_[11].push_back(1.754);
    sigmaMatrix22_[11].push_back(1.989);
    sigmaMatrix22_[11].push_back(2.228);
 
    sigmaMatrix22_[12].push_back(1.28);
    sigmaMatrix22_[12].push_back(1.289);
    sigmaMatrix22_[12].push_back(1.321);
    sigmaMatrix22_[12].push_back(1.374);
    sigmaMatrix22_[12].push_back(1.447);
    sigmaMatrix22_[12].push_back(1.63);
    sigmaMatrix22_[12].push_back(1.838);
    sigmaMatrix22_[12].push_back(2.053);
 
    sigmaMatrix22_[13].push_back(1.2219);
    sigmaMatrix22_[13].push_back(1.231);
    sigmaMatrix22_[13].push_back(1.259);
    sigmaMatrix22_[13].push_back(1.306);
    sigmaMatrix22_[13].push_back(1.37);
    sigmaMatrix22_[13].push_back(1.532);
    sigmaMatrix22_[13].push_back(1.718);
    sigmaMatrix22_[13].push_back(1.912);
 
    sigmaMatrix22_[14].push_back(1.1757);
    sigmaMatrix22_[14].push_back(1.184);
    sigmaMatrix22_[14].push_back(1.209);
    sigmaMatrix22_[14].push_back(1.251);
    sigmaMatrix22_[14].push_back(1.307);
    sigmaMatrix22_[14].push_back(1.451);
    sigmaMatrix22_[14].push_back(1.618);
    sigmaMatrix22_[14].push_back(1.795);
 
    sigmaMatrix22_[15].push_back(1.0933);
    sigmaMatrix22_[15].push_back(1.1);
    sigmaMatrix22_[15].push_back(1.119);
    sigmaMatrix22_[15].push_back(1.15);
    sigmaMatrix22_[15].push_back(1.193);
    sigmaMatrix22_[15].push_back(1.304);
    sigmaMatrix22_[15].push_back(1.435);
    sigmaMatrix22_[15].push_back(1.578);
 
    sigmaMatrix22_[16].push_back(1.0388);
    sigmaMatrix22_[16].push_back(1.044);
    sigmaMatrix22_[16].push_back(1.059);
    sigmaMatrix22_[16].push_back(1.083);
    sigmaMatrix22_[16].push_back(1.117);
    sigmaMatrix22_[16].push_back(1.204);
    sigmaMatrix22_[16].push_back(1.31);
    sigmaMatrix22_[16].push_back(1.428);
 
    sigmaMatrix22_[17].push_back(0.99963);
    sigmaMatrix22_[17].push_back(1.004);
    sigmaMatrix22_[17].push_back(1.016);
    sigmaMatrix22_[17].push_back(1.035);
    sigmaMatrix22_[17].push_back(1.062);
    sigmaMatrix22_[17].push_back(1.133);
    sigmaMatrix22_[17].push_back(1.22);
    sigmaMatrix22_[17].push_back(1.319);
 
    sigmaMatrix22_[18].push_back(0.96988);
    sigmaMatrix22_[18].push_back(0.9732);
    sigmaMatrix22_[18].push_back(0.983);
    sigmaMatrix22_[18].push_back(0.9991);
    sigmaMatrix22_[18].push_back(1.021);
    sigmaMatrix22_[18].push_back(1.079);
    sigmaMatrix22_[18].push_back(1.153);
    sigmaMatrix22_[18].push_back(1.236);
 
    sigmaMatrix22_[19].push_back(0.92676);
    sigmaMatrix22_[19].push_back(0.9291);
    sigmaMatrix22_[19].push_back(0.936);
    sigmaMatrix22_[19].push_back(0.9473);
    sigmaMatrix22_[19].push_back(0.9628);
    sigmaMatrix22_[19].push_back(1.005);
    sigmaMatrix22_[19].push_back(1.058);
    sigmaMatrix22_[19].push_back(1.121);
 
    sigmaMatrix22_[20].push_back(0.89616);
    sigmaMatrix22_[20].push_back(0.8979);
    sigmaMatrix22_[20].push_back(0.903);
    sigmaMatrix22_[20].push_back(0.9114);
    sigmaMatrix22_[20].push_back(0.923);
    sigmaMatrix22_[20].push_back(0.9545);
    sigmaMatrix22_[20].push_back(0.9955);
    sigmaMatrix22_[20].push_back(1.044);
 
    sigmaMatrix22_[21].push_back(0.87272);
    sigmaMatrix22_[21].push_back(0.8741);
    sigmaMatrix22_[21].push_back(0.878);
    sigmaMatrix22_[21].push_back(0.8845);
    sigmaMatrix22_[21].push_back(0.8935);
    sigmaMatrix22_[21].push_back(0.9181);
    sigmaMatrix22_[21].push_back(0.9505);
    sigmaMatrix22_[21].push_back(0.9893);
 
    sigmaMatrix22_[22].push_back(0.85379);
    sigmaMatrix22_[22].push_back(0.8549);
    sigmaMatrix22_[22].push_back(0.858);
    sigmaMatrix22_[22].push_back(0.8632);
    sigmaMatrix22_[22].push_back(0.8703);
    sigmaMatrix22_[22].push_back(0.8901);
    sigmaMatrix22_[22].push_back(0.9164);
    sigmaMatrix22_[22].push_back(0.9482);
 
    sigmaMatrix22_[23].push_back(0.83795);
    sigmaMatrix22_[23].push_back(0.8388);
    sigmaMatrix22_[23].push_back(0.8414);
    sigmaMatrix22_[23].push_back(0.8456);
    sigmaMatrix22_[23].push_back(0.8515);
    sigmaMatrix22_[23].push_back(0.8678);
    sigmaMatrix22_[23].push_back(0.8895);
    sigmaMatrix22_[23].push_back(0.916);
 
    sigmaMatrix22_[24].push_back(0.82435);
    sigmaMatrix22_[24].push_back(0.8251);
    sigmaMatrix22_[24].push_back(0.8273);
    sigmaMatrix22_[24].push_back(0.8308);
    sigmaMatrix22_[24].push_back(0.8356);
    sigmaMatrix22_[24].push_back(0.8493);
    sigmaMatrix22_[24].push_back(0.8676);
    sigmaMatrix22_[24].push_back(0.8901);
 
    sigmaMatrix22_[25].push_back(0.80184);
    sigmaMatrix22_[25].push_back(0.8024);
    sigmaMatrix22_[25].push_back(0.8039);
    sigmaMatrix22_[25].push_back(0.8065);
    sigmaMatrix22_[25].push_back(0.8101);
    sigmaMatrix22_[25].push_back(0.8201);
    sigmaMatrix22_[25].push_back(0.8337);
    sigmaMatrix22_[25].push_back(0.8504);
 
    sigmaMatrix22_[26].push_back(0.78363);
    sigmaMatrix22_[26].push_back(0.784);
    sigmaMatrix22_[26].push_back(0.7852);
    sigmaMatrix22_[26].push_back(0.7872);
    sigmaMatrix22_[26].push_back(0.7899);
    sigmaMatrix22_[26].push_back(0.7976);
    sigmaMatrix22_[26].push_back(0.8081);
    sigmaMatrix22_[26].push_back(0.8212);
 
    sigmaMatrix22_[27].push_back(0.76834);
    sigmaMatrix22_[27].push_back(0.7687);
    sigmaMatrix22_[27].push_back(0.7696);
    sigmaMatrix22_[27].push_back(0.7712);
    sigmaMatrix22_[27].push_back(0.7733);
    sigmaMatrix22_[27].push_back(0.7794);
    sigmaMatrix22_[27].push_back(0.7878);
    sigmaMatrix22_[27].push_back(0.7983);
 
    sigmaMatrix22_[28].push_back(0.75518);
    sigmaMatrix22_[28].push_back(0.7554);
    sigmaMatrix22_[28].push_back(0.7562);
    sigmaMatrix22_[28].push_back(0.7575);
    sigmaMatrix22_[28].push_back(0.7592);
    sigmaMatrix22_[28].push_back(0.7642);
    sigmaMatrix22_[28].push_back(0.7711);
    sigmaMatrix22_[28].push_back(0.7797);
 
    sigmaMatrix22_[29].push_back(0.74364);
    sigmaMatrix22_[29].push_back(0.7438);
    sigmaMatrix22_[29].push_back(0.7445);
    sigmaMatrix22_[29].push_back(0.7455);
    sigmaMatrix22_[29].push_back(0.747);
    sigmaMatrix22_[29].push_back(0.7512);
    sigmaMatrix22_[29].push_back(0.7569);
    sigmaMatrix22_[29].push_back(0.7642);
 
    sigmaMatrix22_[30].push_back(0.71982);
    sigmaMatrix22_[30].push_back(0.72);
    sigmaMatrix22_[30].push_back(0.7204);
    sigmaMatrix22_[30].push_back(0.1211);
    sigmaMatrix22_[30].push_back(0.7221);
    sigmaMatrix22_[30].push_back(0.725);
    sigmaMatrix22_[30].push_back(0.7289);
    sigmaMatrix22_[30].push_back(0.7339);
 
    sigmaMatrix22_[31].push_back(0.70097);
    sigmaMatrix22_[31].push_back(0.7011);
    sigmaMatrix22_[31].push_back(0.7014);
    sigmaMatrix22_[31].push_back(0.7019);
    sigmaMatrix22_[31].push_back(0.7026);
    sigmaMatrix22_[31].push_back(0.7047);
    sigmaMatrix22_[31].push_back(0.7076);
    sigmaMatrix22_[31].push_back(0.7112);
 
    sigmaMatrix22_[32].push_back(0.68545);
    sigmaMatrix22_[32].push_back(0.6855);
    sigmaMatrix22_[32].push_back(0.6858);
    sigmaMatrix22_[32].push_back(0.6861);
    sigmaMatrix22_[32].push_back(0.6867);
    sigmaMatrix22_[32].push_back(0.6883);
    sigmaMatrix22_[32].push_back(0.6905);
    sigmaMatrix22_[32].push_back(0.6932);
 
    sigmaMatrix22_[33].push_back(0.67232);
    sigmaMatrix22_[33].push_back(0.6724);
    sigmaMatrix22_[33].push_back(0.6726);
    sigmaMatrix22_[33].push_back(0.6728);
    sigmaMatrix22_[33].push_back(0.6733);
    sigmaMatrix22_[33].push_back(0.6745);
    sigmaMatrix22_[33].push_back(0.6762);
    sigmaMatrix22_[33].push_back(0.6784);
 
    sigmaMatrix22_[34].push_back(0.65099);
    sigmaMatrix22_[34].push_back(0.651);
    sigmaMatrix22_[34].push_back(0.6512);
    sigmaMatrix22_[34].push_back(0.6513);
    sigmaMatrix22_[34].push_back(0.6516);
    sigmaMatrix22_[34].push_back(0.6524);
    sigmaMatrix22_[34].push_back(0.6534);
    sigmaMatrix22_[34].push_back(0.6546);
 
    sigmaMatrix22_[35].push_back(0.61397);
    sigmaMatrix22_[35].push_back(0.6141);
    sigmaMatrix22_[35].push_back(0.6143);
    sigmaMatrix22_[35].push_back(0.6145);
    sigmaMatrix22_[35].push_back(0.6147);
    sigmaMatrix22_[35].push_back(0.6148);
    sigmaMatrix22_[35].push_back(0.6148);
    sigmaMatrix22_[35].push_back(0.6147);
 
    sigmaMatrix22_[36].push_back(0.5887);
    sigmaMatrix22_[36].push_back(0.5889);
    sigmaMatrix22_[36].push_back(0.5894);
    sigmaMatrix22_[36].push_back(0.59);
    sigmaMatrix22_[36].push_back(0.5903);
    sigmaMatrix22_[36].push_back(0.5901);
    sigmaMatrix22_[36].push_back(0.5895);
    sigmaMatrix22_[36].push_back(0.5885);
 
}
 
