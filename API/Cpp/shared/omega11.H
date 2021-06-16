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
	dsigma11_.push_back(0);
	dsigma11_.push_back(0.25);
	dsigma11_.push_back(0.5);
	dsigma11_.push_back(0.75);
	dsigma11_.push_back(1);
	dsigma11_.push_back(1.5);
	dsigma11_.push_back(2);
	dsigma11_.push_back(2.5);
}
 
{
	Tsigma11_.push_back(0.1);
	Tsigma11_.push_back(0.2);
	Tsigma11_.push_back(0.3);
	Tsigma11_.push_back(0.4);
	Tsigma11_.push_back(0.5);
	Tsigma11_.push_back(0.6);
	Tsigma11_.push_back(0.7);
	Tsigma11_.push_back(0.8);
	Tsigma11_.push_back(0.9);
	Tsigma11_.push_back(1);
	Tsigma11_.push_back(1.2);
	Tsigma11_.push_back(1.4);
	Tsigma11_.push_back(1.6);
	Tsigma11_.push_back(1.8);
	Tsigma11_.push_back(2);
	Tsigma11_.push_back(2.5);
	Tsigma11_.push_back(3);
	Tsigma11_.push_back(3.5);
	Tsigma11_.push_back(4);
	Tsigma11_.push_back(5);
	Tsigma11_.push_back(6);
	Tsigma11_.push_back(7);
	Tsigma11_.push_back(8);
	Tsigma11_.push_back(9);
	Tsigma11_.push_back(10);
	Tsigma11_.push_back(12);
	Tsigma11_.push_back(14);
	Tsigma11_.push_back(16);
	Tsigma11_.push_back(18);
	Tsigma11_.push_back(20);
	Tsigma11_.push_back(25);
	Tsigma11_.push_back(30);
	Tsigma11_.push_back(35);
	Tsigma11_.push_back(40);
	Tsigma11_.push_back(50);
	Tsigma11_.push_back(75);
	Tsigma11_.push_back(100);
}
 
sigmaMatrix11_.resize(38);
{
	sigmaMatrix11_[0].push_back(4.1005/1.0231);
	sigmaMatrix11_[0].push_back(4.266/1.066);
	sigmaMatrix11_[0].push_back(4.833/1.038);
	sigmaMatrix11_[0].push_back(5.742/1.04);
	sigmaMatrix11_[0].push_back(6.729/1.043);
	sigmaMatrix11_[0].push_back(8.624/1.05);
	sigmaMatrix11_[0].push_back(10.34/1.052);
	sigmaMatrix11_[0].push_back(11.89/1.051);
 
	sigmaMatrix11_[1].push_back(3.2626/1.0424);
	sigmaMatrix11_[1].push_back(3.305/1.045);
	sigmaMatrix11_[1].push_back(3.516/1.048);
	sigmaMatrix11_[1].push_back(3.914/1.052);
	sigmaMatrix11_[1].push_back(4.433/1.056);
	sigmaMatrix11_[1].push_back(5.57/1.065);
	sigmaMatrix11_[1].push_back(6.637/1.066);
	sigmaMatrix11_[1].push_back(7.618/1.064);
 
	sigmaMatrix11_[2].push_back(2.8399/1.0719);
	sigmaMatrix11_[2].push_back(2.836/1.067);
	sigmaMatrix11_[2].push_back(2.936/1.06);
	sigmaMatrix11_[2].push_back(3.168/1.055);
	sigmaMatrix11_[2].push_back(3.511/1.058);
	sigmaMatrix11_[2].push_back(4.329/1.068);
	sigmaMatrix11_[2].push_back(5.126/1.071);
	sigmaMatrix11_[2].push_back(5.874/1.071);
 
	sigmaMatrix11_[3].push_back(2.531/1.0936);
	sigmaMatrix11_[3].push_back(2.522/1.087);
	sigmaMatrix11_[3].push_back(2.586/1.077);
	sigmaMatrix11_[3].push_back(2.749/1.069);
	sigmaMatrix11_[3].push_back(3.004/1.068);
	sigmaMatrix11_[3].push_back(3.64/1.075);
	sigmaMatrix11_[3].push_back(4.282/1.078);
	sigmaMatrix11_[3].push_back(4.895/1.078);
 
	sigmaMatrix11_[4].push_back(2.2837/1.1053);
	sigmaMatrix11_[4].push_back(2.277/1.098);
	sigmaMatrix11_[4].push_back(2.329/1.088);
	sigmaMatrix11_[4].push_back(2.46/1.08);
	sigmaMatrix11_[4].push_back(2.665/1.078);
	sigmaMatrix11_[4].push_back(3.187/1.082);
	sigmaMatrix11_[4].push_back(3.727/1.084);
	sigmaMatrix11_[4].push_back(4.249/1.084);
 
	sigmaMatrix11_[5].push_back(2.0838/1.1104);
	sigmaMatrix11_[5].push_back(2.081/1.104);
	sigmaMatrix11_[5].push_back(2.13/1.096);
	sigmaMatrix11_[5].push_back(2.243/1.089);
	sigmaMatrix11_[5].push_back(2.417/1.086);
	sigmaMatrix11_[5].push_back(2.862/1.089);
	sigmaMatrix11_[5].push_back(3.329/1.09);
	sigmaMatrix11_[5].push_back(3.786/1.09);
 
	sigmaMatrix11_[6].push_back(1.922/1.1114);
	sigmaMatrix11_[6].push_back(1.924/1.107);
	sigmaMatrix11_[6].push_back(1.97/1.1);
	sigmaMatrix11_[6].push_back(2.072/1.095);
	sigmaMatrix11_[6].push_back(2.225/1.093);
	sigmaMatrix11_[6].push_back(2.614/1.095);
	sigmaMatrix11_[6].push_back(3.028/1.096);
	sigmaMatrix11_[6].push_back(3.435/1.095);
 
	sigmaMatrix11_[7].push_back(1.7902/1.1104);
	sigmaMatrix11_[7].push_back(1.795/1.107);
	sigmaMatrix11_[7].push_back(1.84/1.102);
	sigmaMatrix11_[7].push_back(1.934/1.099);
	sigmaMatrix11_[7].push_back(2.07/1.098);
	sigmaMatrix11_[7].push_back(2.417/1.1);
	sigmaMatrix11_[7].push_back(2.788/1.1);
	sigmaMatrix11_[7].push_back(3.156/1.099);
 
	sigmaMatrix11_[8].push_back(1.6823/1.1086);
	sigmaMatrix11_[8].push_back(1.689/1.106);
	sigmaMatrix11_[8].push_back(1.733/1.102);
	sigmaMatrix11_[8].push_back(1.82/1.101);
	sigmaMatrix11_[8].push_back(1.944/1.101);
	sigmaMatrix11_[8].push_back(2.258/1.105);
	sigmaMatrix11_[8].push_back(2.596/1.105);
	sigmaMatrix11_[8].push_back(2.933/1.104);
 
	sigmaMatrix11_[9].push_back(1.5929/1.1063);
	sigmaMatrix11_[9].push_back(1.601/1.104);
	sigmaMatrix11_[9].push_back(1.644/1.103);
	sigmaMatrix11_[9].push_back(1.725/1.103);
	sigmaMatrix11_[9].push_back(1.838/1.104);
	sigmaMatrix11_[9].push_back(2.124/1.108);
	sigmaMatrix11_[9].push_back(2.435/1.109);
	sigmaMatrix11_[9].push_back(2.746/1.108);
 
	sigmaMatrix11_[10].push_back(1.4551/1.102);
	sigmaMatrix11_[10].push_back(1.465/1.102);
	sigmaMatrix11_[10].push_back(1.504/1.103);
	sigmaMatrix11_[10].push_back(1.574/1.105);
	sigmaMatrix11_[10].push_back(1.67/1.107);
	sigmaMatrix11_[10].push_back(1.913/1.112);
	sigmaMatrix11_[10].push_back(2.181/1.115);
	sigmaMatrix11_[10].push_back(2.451/1.115);
 
	sigmaMatrix11_[11].push_back(1.3551/1.0985);
	sigmaMatrix11_[11].push_back(1.365/1.099);
	sigmaMatrix11_[11].push_back(1.4/1.101);
	sigmaMatrix11_[11].push_back(1.461/1.104);
	sigmaMatrix11_[11].push_back(1.544/1.108);
	sigmaMatrix11_[11].push_back(1.754/1.115);
	sigmaMatrix11_[11].push_back(1.989/1.119);
	sigmaMatrix11_[11].push_back(2.228/1.12);
 
	sigmaMatrix11_[12].push_back(1.28/1.096);
	sigmaMatrix11_[12].push_back(1.289/1.096);
	sigmaMatrix11_[12].push_back(1.321/1.099);
	sigmaMatrix11_[12].push_back(1.374/1.103);
	sigmaMatrix11_[12].push_back(1.447/1.108);
	sigmaMatrix11_[12].push_back(1.63/1.116);
	sigmaMatrix11_[12].push_back(1.838/1.121);
	sigmaMatrix11_[12].push_back(2.053/1.124);
 
	sigmaMatrix11_[13].push_back(1.2219/1.0943);
	sigmaMatrix11_[13].push_back(1.231/1.095);
	sigmaMatrix11_[13].push_back(1.259/1.099);
	sigmaMatrix11_[13].push_back(1.306/1.102);
	sigmaMatrix11_[13].push_back(1.37/1.108);
	sigmaMatrix11_[13].push_back(1.532/1.117);
	sigmaMatrix11_[13].push_back(1.718/1.123);
	sigmaMatrix11_[13].push_back(1.912/1.126);
 
	sigmaMatrix11_[14].push_back(1.1757/1.0934);
	sigmaMatrix11_[14].push_back(1.184/1.094);
	sigmaMatrix11_[14].push_back(1.209/1.097);
	sigmaMatrix11_[14].push_back(1.251/1.102);
	sigmaMatrix11_[14].push_back(1.307/1.107);
	sigmaMatrix11_[14].push_back(1.451/1.116);
	sigmaMatrix11_[14].push_back(1.618/1.123);
	sigmaMatrix11_[14].push_back(1.795/1.128);
 
	sigmaMatrix11_[15].push_back(1.0933/1.0926);
	sigmaMatrix11_[15].push_back(1.1/1.094);
	sigmaMatrix11_[15].push_back(1.119/1.097);
	sigmaMatrix11_[15].push_back(1.15/1.099);
	sigmaMatrix11_[15].push_back(1.193/1.105);
	sigmaMatrix11_[15].push_back(1.304/1.115);
	sigmaMatrix11_[15].push_back(1.435/1.123);
	sigmaMatrix11_[15].push_back(1.578/1.13);
 
	sigmaMatrix11_[16].push_back(1.0388/1.0934);
	sigmaMatrix11_[16].push_back(1.044/1.095);
	sigmaMatrix11_[16].push_back(1.059/1.097);
	sigmaMatrix11_[16].push_back(1.083/1.099);
	sigmaMatrix11_[16].push_back(1.117/1.104);
	sigmaMatrix11_[16].push_back(1.204/1.113);
	sigmaMatrix11_[16].push_back(1.31/1.122);
	sigmaMatrix11_[16].push_back(1.428/1.129);
 
	sigmaMatrix11_[17].push_back(0.99963/1.0948);
	sigmaMatrix11_[17].push_back(1.004/1.096);
	sigmaMatrix11_[17].push_back(1.016/1.098);
	sigmaMatrix11_[17].push_back(1.035/1.1);
	sigmaMatrix11_[17].push_back(1.062/1.103);
	sigmaMatrix11_[17].push_back(1.133/1.112);
	sigmaMatrix11_[17].push_back(1.22/1.119);
	sigmaMatrix11_[17].push_back(1.319/1.127);
 
	sigmaMatrix11_[18].push_back(0.96988/1.0965);
	sigmaMatrix11_[18].push_back(0.9732/1.097);
	sigmaMatrix11_[18].push_back(0.983/1.099);
	sigmaMatrix11_[18].push_back(0.9991/1.101);
	sigmaMatrix11_[18].push_back(1.021/1.104);
	sigmaMatrix11_[18].push_back(1.079/1.11);
	sigmaMatrix11_[18].push_back(1.153/1.118);
	sigmaMatrix11_[18].push_back(1.236/1.126);
 
	sigmaMatrix11_[19].push_back(0.92676/1.0997);
	sigmaMatrix11_[19].push_back(0.9291/1.1);
	sigmaMatrix11_[19].push_back(0.936/1.101);
	sigmaMatrix11_[19].push_back(0.9473/1.102);
	sigmaMatrix11_[19].push_back(0.9628/1.105);
	sigmaMatrix11_[19].push_back(1.005/1.11);
	sigmaMatrix11_[19].push_back(1.058/1.116);
	sigmaMatrix11_[19].push_back(1.121/1.123);
 
	sigmaMatrix11_[20].push_back(0.89616/1.1025);
	sigmaMatrix11_[20].push_back(0.8979/1.103);
	sigmaMatrix11_[20].push_back(0.903/1.104);
	sigmaMatrix11_[20].push_back(0.9114/1.105);
	sigmaMatrix11_[20].push_back(0.923/1.106);
	sigmaMatrix11_[20].push_back(0.9545/1.11);
	sigmaMatrix11_[20].push_back(0.9955/1.115);
	sigmaMatrix11_[20].push_back(1.044/1.121);
 
	sigmaMatrix11_[21].push_back(0.87272/1.105);
	sigmaMatrix11_[21].push_back(0.8741/1.105);
	sigmaMatrix11_[21].push_back(0.878/1.106);
	sigmaMatrix11_[21].push_back(0.8845/1.107);
	sigmaMatrix11_[21].push_back(0.8935/1.108);
	sigmaMatrix11_[21].push_back(0.9181/1.111);
	sigmaMatrix11_[21].push_back(0.9505/1.115);
	sigmaMatrix11_[21].push_back(0.9893/1.12);
 
	sigmaMatrix11_[22].push_back(0.85379/1.1072);
	sigmaMatrix11_[22].push_back(0.8549/1.107);
	sigmaMatrix11_[22].push_back(0.858/1.108);
	sigmaMatrix11_[22].push_back(0.8632/1.108);
	sigmaMatrix11_[22].push_back(0.8703/1.109);
	sigmaMatrix11_[22].push_back(0.8901/1.112);
	sigmaMatrix11_[22].push_back(0.9164/1.115);
	sigmaMatrix11_[22].push_back(0.9482/1.119);
 
	sigmaMatrix11_[23].push_back(0.83795/1.1091);
	sigmaMatrix11_[23].push_back(0.8388/1.109);
	sigmaMatrix11_[23].push_back(0.8414/1.109);
	sigmaMatrix11_[23].push_back(0.8456/1.11);
	sigmaMatrix11_[23].push_back(0.8515/1.111);
	sigmaMatrix11_[23].push_back(0.8678/1.113);
	sigmaMatrix11_[23].push_back(0.8895/1.115);
	sigmaMatrix11_[23].push_back(0.916/1.119);
 
	sigmaMatrix11_[24].push_back(0.82435/1.1107);
	sigmaMatrix11_[24].push_back(0.8251/1.111);
	sigmaMatrix11_[24].push_back(0.8273/1.111);
	sigmaMatrix11_[24].push_back(0.8308/1.111);
	sigmaMatrix11_[24].push_back(0.8356/1.112);
	sigmaMatrix11_[24].push_back(0.8493/1.114);
	sigmaMatrix11_[24].push_back(0.8676/1.116);
	sigmaMatrix11_[24].push_back(0.8901/1.119);
 
	sigmaMatrix11_[25].push_back(0.80184/1.1133);
	sigmaMatrix11_[25].push_back(0.8024/1.114);
	sigmaMatrix11_[25].push_back(0.8039/1.113);
	sigmaMatrix11_[25].push_back(0.8065/1.114);
	sigmaMatrix11_[25].push_back(0.8101/1.114);
	sigmaMatrix11_[25].push_back(0.8201/1.115);
	sigmaMatrix11_[25].push_back(0.8337/1.117);
	sigmaMatrix11_[25].push_back(0.8504/1.119);
 
	sigmaMatrix11_[26].push_back(0.78363/1.1154);
	sigmaMatrix11_[26].push_back(0.784/1.115);
	sigmaMatrix11_[26].push_back(0.7852/1.116);
	sigmaMatrix11_[26].push_back(0.7872/1.116);
	sigmaMatrix11_[26].push_back(0.7899/1.116);
	sigmaMatrix11_[26].push_back(0.7976/1.117);
	sigmaMatrix11_[26].push_back(0.8081/1.118);
	sigmaMatrix11_[26].push_back(0.8212/1.12);
 
	sigmaMatrix11_[27].push_back(0.76834/1.1172);
	sigmaMatrix11_[27].push_back(0.7687/1.117);
	sigmaMatrix11_[27].push_back(0.7696/1.117);
	sigmaMatrix11_[27].push_back(0.7712/1.118);
	sigmaMatrix11_[27].push_back(0.7733/1.118);
	sigmaMatrix11_[27].push_back(0.7794/1.118);
	sigmaMatrix11_[27].push_back(0.7878/1.119);
	sigmaMatrix11_[27].push_back(0.7983/1.12);
 
	sigmaMatrix11_[28].push_back(0.75518/1.1186);
	sigmaMatrix11_[28].push_back(0.7554/1.119);
	sigmaMatrix11_[28].push_back(0.7562/1.119);
	sigmaMatrix11_[28].push_back(0.7575/1.119);
	sigmaMatrix11_[28].push_back(0.7592/1.119);
	sigmaMatrix11_[28].push_back(0.7642/1.119);
	sigmaMatrix11_[28].push_back(0.7711/1.12);
	sigmaMatrix11_[28].push_back(0.7797/1.121);
 
	sigmaMatrix11_[29].push_back(0.74364/1.1199);
	sigmaMatrix11_[29].push_back(0.7438/1.12);
	sigmaMatrix11_[29].push_back(0.7445/1.12);
	sigmaMatrix11_[29].push_back(0.7455/1.12);
	sigmaMatrix11_[29].push_back(0.747/1.12);
	sigmaMatrix11_[29].push_back(0.7512/1.121);
	sigmaMatrix11_[29].push_back(0.7569/1.121);
	sigmaMatrix11_[29].push_back(0.7642/1.122);
 
	sigmaMatrix11_[30].push_back(0.71982/1.1223);
	sigmaMatrix11_[30].push_back(0.72/1.122);
	sigmaMatrix11_[30].push_back(0.7204/1.122);
	sigmaMatrix11_[30].push_back(0.1211/1.122);
	sigmaMatrix11_[30].push_back(0.7221/1.122);
	sigmaMatrix11_[30].push_back(0.725/1.123);
	sigmaMatrix11_[30].push_back(0.7289/1.123);
	sigmaMatrix11_[30].push_back(0.7339/1.124);
 
	sigmaMatrix11_[31].push_back(0.70097/1.1243);
	sigmaMatrix11_[31].push_back(0.7011/1.124);
	sigmaMatrix11_[31].push_back(0.7014/1.124);
	sigmaMatrix11_[31].push_back(0.7019/1.124);
	sigmaMatrix11_[31].push_back(0.7026/1.124);
	sigmaMatrix11_[31].push_back(0.7047/1.124);
	sigmaMatrix11_[31].push_back(0.7076/1.125);
	sigmaMatrix11_[31].push_back(0.7112/1.125);
 
	sigmaMatrix11_[32].push_back(0.68545/1.1259);
	sigmaMatrix11_[32].push_back(0.6855/1.126);
	sigmaMatrix11_[32].push_back(0.6858/1.126);
	sigmaMatrix11_[32].push_back(0.6861/1.126);
	sigmaMatrix11_[32].push_back(0.6867/1.126);
	sigmaMatrix11_[32].push_back(0.6883/1.126);
	sigmaMatrix11_[32].push_back(0.6905/1.126);
	sigmaMatrix11_[32].push_back(0.6932/1.126);
 
	sigmaMatrix11_[33].push_back(0.67232/1.1273);
	sigmaMatrix11_[33].push_back(0.6724/1.127);
	sigmaMatrix11_[33].push_back(0.6726/1.127);
	sigmaMatrix11_[33].push_back(0.6728/1.127);
	sigmaMatrix11_[33].push_back(0.6733/1.127);
	sigmaMatrix11_[33].push_back(0.6745/1.127);
	sigmaMatrix11_[33].push_back(0.6762/1.127);
	sigmaMatrix11_[33].push_back(0.6784/1.128);
 
	sigmaMatrix11_[34].push_back(0.65099/1.1297);
	sigmaMatrix11_[34].push_back(0.651/1.13);
	sigmaMatrix11_[34].push_back(0.6512/1.13);
	sigmaMatrix11_[34].push_back(0.6513/1.13);
	sigmaMatrix11_[34].push_back(0.6516/1.13);
	sigmaMatrix11_[34].push_back(0.6524/1.13);
	sigmaMatrix11_[34].push_back(0.6534/1.13);
	sigmaMatrix11_[34].push_back(0.6546/1.129);
 
	sigmaMatrix11_[35].push_back(0.61397/1.1339);
	sigmaMatrix11_[35].push_back(0.6141/1.134);
	sigmaMatrix11_[35].push_back(0.6143/1.134);
	sigmaMatrix11_[35].push_back(0.6145/1.135);
	sigmaMatrix11_[35].push_back(0.6147/1.135);
	sigmaMatrix11_[35].push_back(0.6148/1.134);
	sigmaMatrix11_[35].push_back(0.6148/1.134);
	sigmaMatrix11_[35].push_back(0.6147/1.132);
 
	sigmaMatrix11_[36].push_back(0.5887/1.1364);
	sigmaMatrix11_[36].push_back(0.5889/1.137);
	sigmaMatrix11_[36].push_back(0.5894/1.137);
	sigmaMatrix11_[36].push_back(0.59/1.138);
	sigmaMatrix11_[36].push_back(0.5903/1.139);
	sigmaMatrix11_[36].push_back(0.5901/1.138);
	sigmaMatrix11_[36].push_back(0.5895/1.137);
	sigmaMatrix11_[36].push_back(0.5885/1.135);
 
}
 
