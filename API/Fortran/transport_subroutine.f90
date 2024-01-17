!################################################################################################
!#                                                                                              #
!#     #############       #############       #############       ####                ####     #
!#    #             #     #             #     #             #     #    #              #    #    #
!#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #
!#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #
!#    #    #####    #     #    #              #    #####    #     #    #              #    #    #
!#    #             #     #    #########      #             #     #    #              #    #    #
!#    #             #     #             #     #             #     #    #              #    #    #
!#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #
!#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #
!#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #
!#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #
!#     ####     ####       #############       ####     ####       #############       ####     #
!#                                                                                              #
!#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #
!#                                                                                              #
!################################################################################################
!#                                                                                              #
!#   License                                                                                    #
!#                                                                                              #
!#   This file is part of ASALI.                                                                #
!#                                                                                              #
!#   ASALI is free software: you can redistribute it and/or modify                              #
!#   it under the terms of the GNU General Public License as published by                       #
!#   the Free Software Foundation, either version 3 of the License, or                          #
!#   (at your option) any later version.                                                        #
!#                                                                                              #
!#   ASALI is distributed in the hope that it will be useful,                                   #
!#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #
!#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #
!#   GNU General Public License for more details.                                               #
!#                                                                                              #
!#   You should have received a copy of the GNU General Public License                          #
!#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #
!#                                                                                              #
!################################################################################################
 
subroutine transport_update()
 
transport_(1)%nome='AC3H4'
transport_(1)%geometry=1
transport_(1)%LJpotential=252.000
transport_(1)%LJdiameter=  4.760
transport_(1)%dipole=  0.000
transport_(1)%polar=  0.000
transport_(1)%collision=  0.000
transport_(1)%MW= 40.065
 
transport_(2)%nome='CH3COOH'
transport_(2)%geometry=2
transport_(2)%LJpotential=436.000
transport_(2)%LJdiameter=  3.970
transport_(2)%dipole=  0.000
transport_(2)%polar=  0.000
transport_(2)%collision=  2.000
transport_(2)%MW= 60.053
 
transport_(3)%nome='CH3COCH3'
transport_(3)%geometry=2
transport_(3)%LJpotential=411.000
transport_(3)%LJdiameter=  4.820
transport_(3)%dipole=  0.000
transport_(3)%polar=  0.000
transport_(3)%collision=  1.000
transport_(3)%MW= 58.080
 
transport_(4)%nome='C2H3CHO'
transport_(4)%geometry=2
transport_(4)%LJpotential=443.200
transport_(4)%LJdiameter=  4.120
transport_(4)%dipole=  0.000
transport_(4)%polar=  0.000
transport_(4)%collision=  1.000
transport_(4)%MW= 56.064
 
transport_(5)%nome='C2H5CHO'
transport_(5)%geometry=2
transport_(5)%LJpotential=411.000
transport_(5)%LJdiameter=  4.820
transport_(5)%dipole=  0.000
transport_(5)%polar=  0.000
transport_(5)%collision=  1.000
transport_(5)%MW= 58.080
 
transport_(6)%nome='C4H9CHO'
transport_(6)%geometry=2
transport_(6)%LJpotential=500.000
transport_(6)%LJdiameter=  5.640
transport_(6)%dipole=  0.000
transport_(6)%polar=  0.000
transport_(6)%collision=  1.000
transport_(6)%MW= 86.134
 
transport_(7)%nome='AR'
transport_(7)%geometry=0
transport_(7)%LJpotential=136.500
transport_(7)%LJdiameter=  3.330
transport_(7)%dipole=  0.000
transport_(7)%polar=  0.000
transport_(7)%collision=  0.000
transport_(7)%MW= 39.948
 
transport_(8)%nome='C6H5CH2OH'
transport_(8)%geometry=2
transport_(8)%LJpotential=622.400
transport_(8)%LJdiameter=  5.530
transport_(8)%dipole=  0.000
transport_(8)%polar=  0.000
transport_(8)%collision=  1.000
transport_(8)%MW=108.140
 
transport_(9)%nome='C6H4O2'
transport_(9)%geometry=2
transport_(9)%LJpotential=450.000
transport_(9)%LJdiameter=  5.500
transport_(9)%dipole=  0.000
transport_(9)%polar=  0.000
transport_(9)%collision=  1.000
transport_(9)%MW=108.097
 
transport_(10)%nome='C6H6'
transport_(10)%geometry=2
transport_(10)%LJpotential=468.500
transport_(10)%LJdiameter=  5.230
transport_(10)%dipole=  0.000
transport_(10)%polar= 10.300
transport_(10)%collision=  1.000
transport_(10)%MW= 78.114
 
transport_(11)%nome='C6H5CHO'
transport_(11)%geometry=2
transport_(11)%LJpotential=622.400
transport_(11)%LJdiameter=  5.530
transport_(11)%dipole=  0.000
transport_(11)%polar=  0.000
transport_(11)%collision=  1.000
transport_(11)%MW=106.124
 
transport_(12)%nome='C6H5C2H4C6H5'
transport_(12)%geometry=2
transport_(12)%LJpotential=783.800
transport_(12)%LJdiameter=  6.640
transport_(12)%dipole=  0.000
transport_(12)%polar=  0.000
transport_(12)%collision=  1.000
transport_(12)%MW=182.265
 
transport_(13)%nome='NC4H8'
transport_(13)%geometry=2
transport_(13)%LJpotential=355.000
transport_(13)%LJdiameter=  4.650
transport_(13)%dipole=  0.000
transport_(13)%polar=  0.000
transport_(13)%collision=  1.000
transport_(13)%MW= 56.107
 
transport_(14)%nome='C4H6'
transport_(14)%geometry=2
transport_(14)%LJpotential=357.000
transport_(14)%LJdiameter=  5.180
transport_(14)%dipole=  0.000
transport_(14)%polar=  0.000
transport_(14)%collision=  1.000
transport_(14)%MW= 54.092
 
transport_(15)%nome='C12H8'
transport_(15)%geometry=2
transport_(15)%LJpotential=689.800
transport_(15)%LJdiameter=  6.500
transport_(15)%dipole=  0.000
transport_(15)%polar=  0.000
transport_(15)%collision=  1.000
transport_(15)%MW=152.196
 
transport_(16)%nome='C2H2'
transport_(16)%geometry=1
transport_(16)%LJpotential=209.000
transport_(16)%LJdiameter=  4.100
transport_(16)%dipole=  0.000
transport_(16)%polar=  0.000
transport_(16)%collision=  2.500
transport_(16)%MW= 26.038
 
transport_(17)%nome='C2H4'
transport_(17)%geometry=2
transport_(17)%LJpotential=280.800
transport_(17)%LJdiameter=  3.971
transport_(17)%dipole=  0.000
transport_(17)%polar=  0.000
transport_(17)%collision=  1.500
transport_(17)%MW= 28.054
 
transport_(18)%nome='C2H6'
transport_(18)%geometry=2
transport_(18)%LJpotential=252.300
transport_(18)%LJdiameter=  4.302
transport_(18)%dipole=  0.000
transport_(18)%polar=  0.000
transport_(18)%collision=  1.500
transport_(18)%MW= 30.070
 
transport_(19)%nome='C3H6'
transport_(19)%geometry=2
transport_(19)%LJpotential=307.800
transport_(19)%LJdiameter=  4.140
transport_(19)%dipole=  0.000
transport_(19)%polar=  0.000
transport_(19)%collision=  1.000
transport_(19)%MW= 42.081
 
transport_(20)%nome='C3H8'
transport_(20)%geometry=2
transport_(20)%LJpotential=303.400
transport_(20)%LJdiameter=  4.810
transport_(20)%dipole=  0.000
transport_(20)%polar=  0.000
transport_(20)%collision=  1.000
transport_(20)%MW= 44.097
 
transport_(21)%nome='C4H2'
transport_(21)%geometry=1
transport_(21)%LJpotential=357.000
transport_(21)%LJdiameter=  5.180
transport_(21)%dipole=  0.000
transport_(21)%polar=  0.000
transport_(21)%collision=  1.000
transport_(21)%MW= 50.060
 
transport_(22)%nome='C4H4'
transport_(22)%geometry=2
transport_(22)%LJpotential=357.000
transport_(22)%LJdiameter=  5.180
transport_(22)%dipole=  0.000
transport_(22)%polar=  0.000
transport_(22)%collision=  1.000
transport_(22)%MW= 52.076
 
transport_(23)%nome='CYC5H4O'
transport_(23)%geometry=2
transport_(23)%LJpotential=450.000
transport_(23)%LJdiameter=  5.500
transport_(23)%dipole=  0.000
transport_(23)%polar=  0.000
transport_(23)%collision=  1.000
transport_(23)%MW= 80.086
 
transport_(24)%nome='C6H5O'
transport_(24)%geometry=2
transport_(24)%LJpotential=450.000
transport_(24)%LJdiameter=  5.500
transport_(24)%dipole=  0.000
transport_(24)%polar=  0.000
transport_(24)%collision=  1.000
transport_(24)%MW= 93.105
 
transport_(25)%nome='CYC6H10-ONE'
transport_(25)%geometry=2
transport_(25)%LJpotential=568.500
transport_(25)%LJdiameter=  5.230
transport_(25)%dipole=  0.000
transport_(25)%polar= 10.300
transport_(25)%collision=  1.000
transport_(25)%MW= 98.145
 
transport_(26)%nome='CYC5H8'
transport_(26)%geometry=1
transport_(26)%LJpotential=408.000
transport_(26)%LJdiameter=  5.200
transport_(26)%dipole=  0.000
transport_(26)%polar=  0.000
transport_(26)%collision=  1.000
transport_(26)%MW= 68.118
 
transport_(27)%nome='CYC6H8'
transport_(27)%geometry=2
transport_(27)%LJpotential=468.500
transport_(27)%LJdiameter=  5.230
transport_(27)%dipole=  0.000
transport_(27)%polar= 10.300
transport_(27)%collision=  1.000
transport_(27)%MW= 80.130
 
transport_(28)%nome='CYC6H12'
transport_(28)%geometry=2
transport_(28)%LJpotential=468.500
transport_(28)%LJdiameter=  5.230
transport_(28)%dipole=  0.000
transport_(28)%polar= 10.300
transport_(28)%collision=  1.000
transport_(28)%MW= 84.161
 
transport_(29)%nome='CYC6H10'
transport_(29)%geometry=2
transport_(29)%LJpotential=468.500
transport_(29)%LJdiameter=  5.230
transport_(29)%dipole=  0.000
transport_(29)%polar= 10.300
transport_(29)%collision=  1.000
transport_(29)%MW= 82.145
 
transport_(30)%nome='CH2CO'
transport_(30)%geometry=2
transport_(30)%LJpotential=436.000
transport_(30)%LJdiameter=  3.970
transport_(30)%dipole=  0.000
transport_(30)%polar=  0.000
transport_(30)%collision=  2.000
transport_(30)%MW= 42.037
 
transport_(31)%nome='CH2O'
transport_(31)%geometry=2
transport_(31)%LJpotential=498.000
transport_(31)%LJdiameter=  3.590
transport_(31)%dipole=  0.000
transport_(31)%polar=  0.000
transport_(31)%collision=  2.000
transport_(31)%MW= 30.026
 
transport_(32)%nome='CH3OH'
transport_(32)%geometry=2
transport_(32)%LJpotential=481.800
transport_(32)%LJdiameter=  3.626
transport_(32)%dipole=  0.000
transport_(32)%polar=  0.000
transport_(32)%collision=  1.000
transport_(32)%MW= 32.042
 
transport_(33)%nome='CH4'
transport_(33)%geometry=2
transport_(33)%LJpotential=141.400
transport_(33)%LJdiameter=  3.746
transport_(33)%dipole=  0.000
transport_(33)%polar=  2.600
transport_(33)%collision= 13.000
transport_(33)%MW= 16.043
 
transport_(34)%nome='CO'
transport_(34)%geometry=1
transport_(34)%LJpotential= 98.100
transport_(34)%LJdiameter=  3.650
transport_(34)%dipole=  0.000
transport_(34)%polar=  1.950
transport_(34)%collision=  1.800
transport_(34)%MW= 28.010
 
transport_(35)%nome='CO2'
transport_(35)%geometry=1
transport_(35)%LJpotential=244.000
transport_(35)%LJdiameter=  3.763
transport_(35)%dipole=  0.000
transport_(35)%polar=  2.650
transport_(35)%collision=  2.100
transport_(35)%MW= 44.010
 
transport_(36)%nome='CYC5H6'
transport_(36)%geometry=2
transport_(36)%LJpotential=408.000
transport_(36)%LJdiameter=  5.200
transport_(36)%dipole=  0.000
transport_(36)%polar=  0.000
transport_(36)%collision=  1.000
transport_(36)%MW= 66.103
 
transport_(37)%nome='MCPTD'
transport_(37)%geometry=2
transport_(37)%LJpotential=408.000
transport_(37)%LJdiameter=  5.200
transport_(37)%dipole=  0.000
transport_(37)%polar=  0.000
transport_(37)%collision=  1.000
transport_(37)%MW= 80.130
 
transport_(38)%nome='CRESOL'
transport_(38)%geometry=2
transport_(38)%LJpotential=621.100
transport_(38)%LJdiameter=  5.640
transport_(38)%dipole=  0.000
transport_(38)%polar=  0.000
transport_(38)%collision=  1.000
transport_(38)%MW=108.140
 
transport_(39)%nome='NC10H20'
transport_(39)%geometry=2
transport_(39)%LJpotential=540.980
transport_(39)%LJdiameter=  7.150
transport_(39)%dipole=  0.000
transport_(39)%polar=  0.000
transport_(39)%collision=  1.000
transport_(39)%MW=140.269
 
transport_(40)%nome='C6H5CH2C6H5'
transport_(40)%geometry=2
transport_(40)%LJpotential=712.600
transport_(40)%LJdiameter=  6.890
transport_(40)%dipole=  0.000
transport_(40)%polar=  0.000
transport_(40)%collision=  1.000
transport_(40)%MW=168.238
 
transport_(41)%nome='DIPE'
transport_(41)%geometry=2
transport_(41)%LJpotential=432.000
transport_(41)%LJdiameter=  6.000
transport_(41)%dipole=  0.000
transport_(41)%polar=  0.000
transport_(41)%collision=  1.000
transport_(41)%MW=102.177
 
transport_(42)%nome='CH3OCH3'
transport_(42)%geometry=2
transport_(42)%LJpotential=303.400
transport_(42)%LJdiameter=  4.810
transport_(42)%dipole=  0.000
transport_(42)%polar=  0.000
transport_(42)%collision=  1.000
transport_(42)%MW= 46.069
 
transport_(43)%nome='CH3CH3-C5H6'
transport_(43)%geometry=2
transport_(43)%LJpotential=450.000
transport_(43)%LJdiameter=  5.500
transport_(43)%dipole=  0.000
transport_(43)%polar=  0.000
transport_(43)%collision=  1.000
transport_(43)%MW= 96.172
 
transport_(44)%nome='C6H5C2H5'
transport_(44)%geometry=2
transport_(44)%LJpotential=523.600
transport_(44)%LJdiameter=  5.960
transport_(44)%dipole=  0.000
transport_(44)%polar=  0.000
transport_(44)%collision=  1.000
transport_(44)%MW=106.167
 
transport_(45)%nome='NC7H14'
transport_(45)%geometry=2
transport_(45)%LJpotential=459.980
transport_(45)%LJdiameter=  6.310
transport_(45)%dipole=  0.000
transport_(45)%polar=  0.000
transport_(45)%collision=  1.000
transport_(45)%MW= 98.188
 
transport_(46)%nome='NC6H12'
transport_(46)%geometry=2
transport_(46)%LJpotential=412.300
transport_(46)%LJdiameter=  5.349
transport_(46)%dipole=  0.000
transport_(46)%polar=  0.000
transport_(46)%collision=  1.000
transport_(46)%MW= 84.161
 
transport_(47)%nome='C5H9CHO'
transport_(47)%geometry=2
transport_(47)%LJpotential=568.500
transport_(47)%LJdiameter=  5.230
transport_(47)%dipole=  0.000
transport_(47)%polar= 10.300
transport_(47)%collision=  1.000
transport_(47)%MW= 98.145
 
transport_(48)%nome='ETBE'
transport_(48)%geometry=2
transport_(48)%LJpotential=432.000
transport_(48)%LJdiameter=  6.000
transport_(48)%dipole=  0.000
transport_(48)%polar=  0.000
transport_(48)%collision=  1.000
transport_(48)%MW=102.177
 
transport_(49)%nome='C2H5OH'
transport_(49)%geometry=2
transport_(49)%LJpotential=362.600
transport_(49)%LJdiameter=  4.530
transport_(49)%dipole=  0.000
transport_(49)%polar=  0.000
transport_(49)%collision=  1.500
transport_(49)%MW= 46.069
 
transport_(50)%nome='C2H5OOH'
transport_(50)%geometry=2
transport_(50)%LJpotential=362.600
transport_(50)%LJdiameter=  4.530
transport_(50)%dipole=  0.000
transport_(50)%polar=  0.000
transport_(50)%collision=  1.500
transport_(50)%MW= 62.068
 
transport_(51)%nome='C2H4O'
transport_(51)%geometry=2
transport_(51)%LJpotential=362.600
transport_(51)%LJdiameter=  4.530
transport_(51)%dipole=  0.000
transport_(51)%polar=  0.000
transport_(51)%collision=  1.500
transport_(51)%MW= 44.053
 
transport_(52)%nome='C6H5C2H'
transport_(52)%geometry=2
transport_(52)%LJpotential=534.300
transport_(52)%LJdiameter=  5.710
transport_(52)%dipole=  0.770
transport_(52)%polar=  0.000
transport_(52)%collision=  1.000
transport_(52)%MW=102.136
 
transport_(53)%nome='BIPHENYL'
transport_(53)%geometry=2
transport_(53)%LJpotential=676.500
transport_(53)%LJdiameter=  6.310
transport_(53)%dipole=  0.000
transport_(53)%polar=  0.000
transport_(53)%collision=  1.000
transport_(53)%MW=154.211
 
transport_(54)%nome='C14H10'
transport_(54)%geometry=2
transport_(54)%LJpotential=772.000
transport_(54)%LJdiameter=  6.960
transport_(54)%dipole=  0.000
transport_(54)%polar= 38.800
transport_(54)%collision=  1.000
transport_(54)%MW=178.233
 
transport_(55)%nome='C6H5OH'
transport_(55)%geometry=2
transport_(55)%LJpotential=450.000
transport_(55)%LJdiameter=  5.500
transport_(55)%dipole=  0.000
transport_(55)%polar=  0.000
transport_(55)%collision=  1.000
transport_(55)%MW= 94.113
 
transport_(56)%nome='FLUORENE'
transport_(56)%geometry=2
transport_(56)%LJpotential=712.600
transport_(56)%LJdiameter=  6.890
transport_(56)%dipole=  0.000
transport_(56)%polar=  0.000
transport_(56)%collision=  1.000
transport_(56)%MW=166.222
 
transport_(57)%nome='C10H8'
transport_(57)%geometry=2
transport_(57)%LJpotential=630.400
transport_(57)%LJdiameter=  6.180
transport_(57)%dipole=  0.000
transport_(57)%polar= 16.500
transport_(57)%collision=  1.000
transport_(57)%MW=128.174
 
transport_(58)%nome='H2'
transport_(58)%geometry=1
transport_(58)%LJpotential= 38.000
transport_(58)%LJdiameter=  2.920
transport_(58)%dipole=  0.000
transport_(58)%polar=  0.790
transport_(58)%collision=280.000
transport_(58)%MW=  2.016
 
transport_(59)%nome='H2O'
transport_(59)%geometry=2
transport_(59)%LJpotential=572.400
transport_(59)%LJdiameter=  2.605
transport_(59)%dipole=  1.844
transport_(59)%polar=  0.000
transport_(59)%collision=  4.000
transport_(59)%MW= 18.015
 
transport_(60)%nome='H2O2'
transport_(60)%geometry=2
transport_(60)%LJpotential=107.400
transport_(60)%LJdiameter=  3.458
transport_(60)%dipole=  0.000
transport_(60)%polar=  0.000
transport_(60)%collision=  3.800
transport_(60)%MW= 34.015
 
transport_(61)%nome='HE'
transport_(61)%geometry=0
transport_(61)%LJpotential= 10.200
transport_(61)%LJdiameter=  2.576
transport_(61)%dipole=  0.000
transport_(61)%polar=  0.000
transport_(61)%collision=  0.000
transport_(61)%MW=  4.003
 
transport_(62)%nome='IC4H8'
transport_(62)%geometry=2
transport_(62)%LJpotential=355.000
transport_(62)%LJdiameter=  4.650
transport_(62)%dipole=  0.000
transport_(62)%polar=  0.000
transport_(62)%collision=  1.000
transport_(62)%MW= 56.107
 
transport_(63)%nome='IC3H7CHO'
transport_(63)%geometry=2
transport_(63)%LJpotential=455.000
transport_(63)%LJdiameter=  4.650
transport_(63)%dipole=  0.000
transport_(63)%polar=  0.000
transport_(63)%collision=  1.000
transport_(63)%MW= 72.107
 
transport_(64)%nome='IC4H10'
transport_(64)%geometry=2
transport_(64)%LJpotential=352.000
transport_(64)%LJdiameter=  5.240
transport_(64)%dipole=  0.000
transport_(64)%polar=  0.000
transport_(64)%collision=  1.000
transport_(64)%MW= 58.123
 
transport_(65)%nome='IC8H18'
transport_(65)%geometry=2
transport_(65)%LJpotential=494.000
transport_(65)%LJdiameter=  6.170
transport_(65)%dipole=  0.000
transport_(65)%polar=  0.000
transport_(65)%collision=  1.000
transport_(65)%MW=114.231
 
transport_(66)%nome='INDENE'
transport_(66)%geometry=2
transport_(66)%LJpotential=588.600
transport_(66)%LJdiameter=  5.960
transport_(66)%dipole=  0.650
transport_(66)%polar=  0.000
transport_(66)%collision=  1.000
transport_(66)%MW=116.163
 
transport_(67)%nome='IC3H7OH'
transport_(67)%geometry=2
transport_(67)%LJpotential=482.147
transport_(67)%LJdiameter=  5.009
transport_(67)%dipole=  1.660
transport_(67)%polar=  6.740
transport_(67)%collision=  1.000
transport_(67)%MW= 60.096
 
transport_(68)%nome='IC5H10'
transport_(68)%geometry=2
transport_(68)%LJpotential=408.000
transport_(68)%LJdiameter=  5.200
transport_(68)%dipole=  0.000
transport_(68)%polar=  0.000
transport_(68)%collision=  1.000
transport_(68)%MW= 70.134
 
transport_(69)%nome='IC3H5CHO'
transport_(69)%geometry=2
transport_(69)%LJpotential=357.000
transport_(69)%LJdiameter=  5.180
transport_(69)%dipole=  0.000
transport_(69)%polar=  0.000
transport_(69)%collision=  1.000
transport_(69)%MW= 70.091
 
transport_(70)%nome='MCYC6'
transport_(70)%geometry=2
transport_(70)%LJpotential=495.300
transport_(70)%LJdiameter=  5.680
transport_(70)%dipole=  0.430
transport_(70)%polar= 12.300
transport_(70)%collision=  1.000
transport_(70)%MW= 98.188
 
transport_(71)%nome='CH3CHO'
transport_(71)%geometry=2
transport_(71)%LJpotential=436.000
transport_(71)%LJdiameter=  3.970
transport_(71)%dipole=  0.000
transport_(71)%polar=  0.000
transport_(71)%collision=  2.000
transport_(71)%MW= 44.053
 
transport_(72)%nome='C10H7CH3'
transport_(72)%geometry=2
transport_(72)%LJpotential=660.000
transport_(72)%LJdiameter=  6.350
transport_(72)%dipole=  0.000
transport_(72)%polar=  0.000
transport_(72)%collision=  1.000
transport_(72)%MW=142.200
 
transport_(73)%nome='CH3OOH'
transport_(73)%geometry=2
transport_(73)%LJpotential=481.800
transport_(73)%LJdiameter=  3.626
transport_(73)%dipole=  0.000
transport_(73)%polar=  0.000
transport_(73)%collision=  1.000
transport_(73)%MW= 48.042
 
transport_(74)%nome='MTBE'
transport_(74)%geometry=2
transport_(74)%LJpotential=392.000
transport_(74)%LJdiameter=  5.640
transport_(74)%dipole=  0.000
transport_(74)%polar=  0.000
transport_(74)%collision=  1.000
transport_(74)%MW= 88.150
 
transport_(75)%nome='N2'
transport_(75)%geometry=1
transport_(75)%LJpotential= 97.530
transport_(75)%LJdiameter=  3.621
transport_(75)%dipole=  0.000
transport_(75)%polar=  1.760
transport_(75)%collision=  4.000
transport_(75)%MW= 28.014
 
transport_(76)%nome='C10H7OH'
transport_(76)%geometry=2
transport_(76)%LJpotential=663.450
transport_(76)%LJdiameter=  6.362
transport_(76)%dipole=  0.000
transport_(76)%polar=  0.000
transport_(76)%collision=  1.000
transport_(76)%MW=144.173
 
transport_(77)%nome='C10H7CHO'
transport_(77)%geometry=2
transport_(77)%LJpotential=663.450
transport_(77)%LJdiameter=  6.362
transport_(77)%dipole=  0.000
transport_(77)%polar=  0.000
transport_(77)%collision=  1.000
transport_(77)%MW=156.184
 
transport_(78)%nome='NC4H10'
transport_(78)%geometry=2
transport_(78)%LJpotential=352.000
transport_(78)%LJdiameter=  5.240
transport_(78)%dipole=  0.000
transport_(78)%polar=  0.000
transport_(78)%collision=  1.000
transport_(78)%MW= 58.123
 
transport_(79)%nome='NC10H22'
transport_(79)%geometry=2
transport_(79)%LJpotential=540.980
transport_(79)%LJdiameter=  7.150
transport_(79)%dipole=  0.000
transport_(79)%polar=  0.000
transport_(79)%collision=  1.000
transport_(79)%MW=142.285
 
transport_(80)%nome='NC12H26'
transport_(80)%geometry=2
transport_(80)%LJpotential=580.000
transport_(80)%LJdiameter=  7.600
transport_(80)%dipole=  0.000
transport_(80)%polar=  0.000
transport_(80)%collision=  1.000
transport_(80)%MW=170.338
 
transport_(81)%nome='NC5H12'
transport_(81)%geometry=2
transport_(81)%LJpotential=392.000
transport_(81)%LJdiameter=  5.640
transport_(81)%dipole=  0.000
transport_(81)%polar=  0.000
transport_(81)%collision=  1.000
transport_(81)%MW= 72.150
 
transport_(82)%nome='NC7H16'
transport_(82)%geometry=2
transport_(82)%LJpotential=459.980
transport_(82)%LJdiameter=  6.310
transport_(82)%dipole=  0.000
transport_(82)%polar=  0.000
transport_(82)%collision=  1.000
transport_(82)%MW=100.204
 
transport_(83)%nome='NEOC5H12'
transport_(83)%geometry=2
transport_(83)%LJpotential=392.000
transport_(83)%LJdiameter=  5.640
transport_(83)%dipole=  0.000
transport_(83)%polar=  0.000
transport_(83)%collision=  1.000
transport_(83)%MW= 72.150
 
transport_(84)%nome='O2'
transport_(84)%geometry=1
transport_(84)%LJpotential=107.400
transport_(84)%LJdiameter=  3.458
transport_(84)%dipole=  0.000
transport_(84)%polar=  1.600
transport_(84)%collision=  3.800
transport_(84)%MW= 31.999
 
transport_(85)%nome='IC8H16'
transport_(85)%geometry=2
transport_(85)%LJpotential=494.000
transport_(85)%LJdiameter=  6.170
transport_(85)%dipole=  0.000
transport_(85)%polar=  0.000
transport_(85)%collision=  1.000
transport_(85)%MW=112.215
 
transport_(86)%nome='NC5H10'
transport_(86)%geometry=2
transport_(86)%LJpotential=408.000
transport_(86)%LJdiameter=  5.200
transport_(86)%dipole=  0.000
transport_(86)%polar=  0.000
transport_(86)%collision=  1.000
transport_(86)%MW= 70.134
 
transport_(87)%nome='PC3H4'
transport_(87)%geometry=1
transport_(87)%LJpotential=252.000
transport_(87)%LJdiameter=  4.760
transport_(87)%dipole=  0.000
transport_(87)%polar=  0.000
transport_(87)%collision=  1.000
transport_(87)%MW= 40.065
 
transport_(88)%nome='CH3CO3H'
transport_(88)%geometry=2
transport_(88)%LJpotential=443.200
transport_(88)%LJdiameter=  4.120
transport_(88)%dipole=  0.000
transport_(88)%polar=  0.000
transport_(88)%collision=  1.000
transport_(88)%MW= 76.052
 
transport_(89)%nome='HCO3H'
transport_(89)%geometry=2
transport_(89)%LJpotential=443.200
transport_(89)%LJdiameter=  4.120
transport_(89)%dipole=  0.000
transport_(89)%polar=  0.000
transport_(89)%collision=  1.000
transport_(89)%MW= 62.025
 
transport_(90)%nome='C3H6O'
transport_(90)%geometry=2
transport_(90)%LJpotential=411.000
transport_(90)%LJdiameter=  4.820
transport_(90)%dipole=  0.000
transport_(90)%polar=  0.000
transport_(90)%collision=  1.000
transport_(90)%MW= 58.080
 
transport_(91)%nome='C5H8'
transport_(91)%geometry=2
transport_(91)%LJpotential=408.000
transport_(91)%LJdiameter=  5.200
transport_(91)%dipole=  0.000
transport_(91)%polar=  0.000
transport_(91)%collision=  1.000
transport_(91)%MW= 68.118
 
transport_(92)%nome='C16H10'
transport_(92)%geometry=2
transport_(92)%LJpotential=834.900
transport_(92)%LJdiameter=  7.240
transport_(92)%dipole=  0.000
transport_(92)%polar= 45.000
transport_(92)%collision=  1.000
transport_(92)%MW=202.255
 
transport_(93)%nome='C6H5C2H3'
transport_(93)%geometry=2
transport_(93)%LJpotential=546.200
transport_(93)%LJdiameter=  6.000
transport_(93)%dipole=  0.130
transport_(93)%polar= 15.000
transport_(93)%collision=  1.000
transport_(93)%MW=104.152
 
transport_(94)%nome='TAME'
transport_(94)%geometry=2
transport_(94)%LJpotential=432.000
transport_(94)%LJdiameter=  6.000
transport_(94)%dipole=  0.000
transport_(94)%polar=  0.000
transport_(94)%collision=  1.000
transport_(94)%MW=102.177
 
transport_(95)%nome='TETRALIN'
transport_(95)%geometry=2
transport_(95)%LJpotential=630.400
transport_(95)%LJdiameter=  6.180
transport_(95)%dipole=  0.000
transport_(95)%polar= 16.500
transport_(95)%collision=  1.000
transport_(95)%MW=132.205
 
transport_(96)%nome='DECALIN'
transport_(96)%geometry=2
transport_(96)%LJpotential=630.400
transport_(96)%LJdiameter=  6.180
transport_(96)%dipole=  0.000
transport_(96)%polar= 16.500
transport_(96)%collision=  1.000
transport_(96)%MW=138.253
 
transport_(97)%nome='C7H8'
transport_(97)%geometry=2
transport_(97)%LJpotential=495.300
transport_(97)%LJdiameter=  5.680
transport_(97)%dipole=  0.430
transport_(97)%polar= 12.300
transport_(97)%collision=  1.000
transport_(97)%MW= 92.141
 
transport_(98)%nome='XYLENE'
transport_(98)%geometry=2
transport_(98)%LJpotential=523.600
transport_(98)%LJdiameter=  5.960
transport_(98)%dipole=  0.000
transport_(98)%polar=  0.000
transport_(98)%collision=  1.000
transport_(98)%MW=106.167
 
transport_(99)%nome='NC16H34'
transport_(99)%geometry=2
transport_(99)%LJpotential=650.000
transport_(99)%LJdiameter=  8.350
transport_(99)%dipole=  0.000
transport_(99)%polar=  0.000
transport_(99)%collision=  1.000
transport_(99)%MW=226.446
 
transport_(100)%nome='N2H4'
transport_(100)%geometry=2
transport_(100)%LJpotential=205.000
transport_(100)%LJdiameter=  4.230
transport_(100)%dipole=  0.000
transport_(100)%polar=  4.260
transport_(100)%collision=  1.500
transport_(100)%MW= 32.045
 
transport_(101)%nome='N2O'
transport_(101)%geometry=1
transport_(101)%LJpotential=232.400
transport_(101)%LJdiameter=  3.828
transport_(101)%dipole=  0.000
transport_(101)%polar=  0.000
transport_(101)%collision=  1.000
transport_(101)%MW= 44.013
 
transport_(102)%nome='NH3'
transport_(102)%geometry=2
transport_(102)%LJpotential=481.000
transport_(102)%LJdiameter=  2.920
transport_(102)%dipole=  1.470
transport_(102)%polar=  0.000
transport_(102)%collision= 10.000
transport_(102)%MW= 17.031
 
transport_(103)%nome='NO'
transport_(103)%geometry=1
transport_(103)%LJpotential= 97.500
transport_(103)%LJdiameter=  3.621
transport_(103)%dipole=  0.000
transport_(103)%polar=  1.760
transport_(103)%collision=  4.000
transport_(103)%MW= 30.006
 
transport_(104)%nome='NO2'
transport_(104)%geometry=2
transport_(104)%LJpotential=200.000
transport_(104)%LJdiameter=  3.500
transport_(104)%dipole=  0.000
transport_(104)%polar=  0.000
transport_(104)%collision=  1.000
transport_(104)%MW= 46.006
 
transport_(105)%nome='C3H5OOH'
transport_(105)%geometry=2
transport_(105)%LJpotential=407.800
transport_(105)%LJdiameter=  4.140
transport_(105)%dipole=  0.000
transport_(105)%polar=  0.000
transport_(105)%collision=  1.000
transport_(105)%MW= 74.079
 
transport_(106)%nome='NC3H7OH'
transport_(106)%geometry=2
transport_(106)%LJpotential=482.147
transport_(106)%LJdiameter=  5.009
transport_(106)%dipole=  1.660
transport_(106)%polar=  6.740
transport_(106)%collision=  1.000
transport_(106)%MW= 60.096
 
transport_(107)%nome='N1C4H9OH'
transport_(107)%geometry=2
transport_(107)%LJpotential=503.072
transport_(107)%LJdiameter=  5.340
transport_(107)%dipole=  1.670
transport_(107)%polar=  8.880
transport_(107)%collision=  1.000
transport_(107)%MW= 74.123
 
transport_(108)%nome='N2C4H9OH'
transport_(108)%geometry=2
transport_(108)%LJpotential=503.072
transport_(108)%LJdiameter=  5.340
transport_(108)%dipole=  1.670
transport_(108)%polar=  8.880
transport_(108)%collision=  1.000
transport_(108)%MW= 74.123
 
transport_(109)%nome='MEK'
transport_(109)%geometry=2
transport_(109)%LJpotential=454.000
transport_(109)%LJdiameter=  5.413
transport_(109)%dipole=  3.300
transport_(109)%polar=  0.000
transport_(109)%collision=  1.000
transport_(109)%MW= 72.107
 
transport_(110)%nome='TC4H9OH'
transport_(110)%geometry=2
transport_(110)%LJpotential=503.072
transport_(110)%LJdiameter=  5.340
transport_(110)%dipole=  1.670
transport_(110)%polar=  8.880
transport_(110)%collision=  1.000
transport_(110)%MW= 74.123
 
transport_(111)%nome='IC4H9OH'
transport_(111)%geometry=2
transport_(111)%LJpotential=503.072
transport_(111)%LJdiameter=  5.340
transport_(111)%dipole=  1.670
transport_(111)%polar=  8.880
transport_(111)%collision=  1.000
transport_(111)%MW= 74.123
 
transport_(112)%nome='C4H7OH'
transport_(112)%geometry=2
transport_(112)%LJpotential=503.072
transport_(112)%LJdiameter=  5.340
transport_(112)%dipole=  1.670
transport_(112)%polar=  8.880
transport_(112)%collision=  1.000
transport_(112)%MW= 72.107
 
transport_(113)%nome='C3H5OH'
transport_(113)%geometry=2
transport_(113)%LJpotential=411.000
transport_(113)%LJdiameter=  4.820
transport_(113)%dipole=  0.000
transport_(113)%polar=  0.000
transport_(113)%collision=  1.000
transport_(113)%MW= 58.080
 
transport_(114)%nome='C10H10'
transport_(114)%geometry=2
transport_(114)%LJpotential=630.400
transport_(114)%LJdiameter=  6.180
transport_(114)%dipole=  0.000
transport_(114)%polar= 16.500
transport_(114)%collision=  1.000
transport_(114)%MW=130.189
 
transport_(115)%nome='BZFUR'
transport_(115)%geometry=2
transport_(115)%LJpotential=630.400
transport_(115)%LJdiameter=  6.180
transport_(115)%dipole=  0.000
transport_(115)%polar= 16.500
transport_(115)%collision=  1.000
transport_(115)%MW=118.135
 
transport_(116)%nome='TMBENZ'
transport_(116)%geometry=2
transport_(116)%LJpotential=523.600
transport_(116)%LJdiameter=  5.960
transport_(116)%dipole=  0.000
transport_(116)%polar=  0.000
transport_(116)%collision=  1.000
transport_(116)%MW=120.194
 
transport_(117)%nome='NPBENZ'
transport_(117)%geometry=2
transport_(117)%LJpotential=495.300
transport_(117)%LJdiameter=  5.680
transport_(117)%dipole=  0.430
transport_(117)%polar= 12.300
transport_(117)%collision=  1.000
transport_(117)%MW=120.194
 
transport_(118)%nome='C6H5OCH3'
transport_(118)%geometry=2
transport_(118)%LJpotential=450.000
transport_(118)%LJdiameter=  5.500
transport_(118)%dipole=  0.000
transport_(118)%polar=  0.000
transport_(118)%collision=  1.000
transport_(118)%MW=108.140
 
transport_(119)%nome='MB'
transport_(119)%geometry=2
transport_(119)%LJpotential=468.000
transport_(119)%LJdiameter=  5.850
transport_(119)%dipole=  0.000
transport_(119)%polar=  0.000
transport_(119)%collision=  0.000
transport_(119)%MW=102.133
 
transport_(120)%nome='MCROT'
transport_(120)%geometry=2
transport_(120)%LJpotential=468.500
transport_(120)%LJdiameter=  5.230
transport_(120)%dipole=  0.000
transport_(120)%polar=  0.000
transport_(120)%collision=  1.000
transport_(120)%MW=100.117
 
transport_(121)%nome='MACRIL'
transport_(121)%geometry=2
transport_(121)%LJpotential=430.100
transport_(121)%LJdiameter=  5.833
transport_(121)%dipole=  0.000
transport_(121)%polar=  0.000
transport_(121)%collision=  1.000
transport_(121)%MW= 86.090
 
transport_(122)%nome='DIBZFUR'
transport_(122)%geometry=2
transport_(122)%LJpotential=676.500
transport_(122)%LJdiameter=  6.310
transport_(122)%dipole=  0.000
transport_(122)%polar=  0.000
transport_(122)%collision=  1.000
transport_(122)%MW=168.195
 
transport_(123)%nome='DIFENET'
transport_(123)%geometry=2
transport_(123)%LJpotential=676.500
transport_(123)%LJdiameter=  6.310
transport_(123)%dipole=  0.000
transport_(123)%polar=  0.000
transport_(123)%collision=  1.000
transport_(123)%MW=170.211
 
transport_(124)%nome='C12H22'
transport_(124)%geometry=2
transport_(124)%LJpotential=580.000
transport_(124)%LJdiameter=  7.600
transport_(124)%dipole=  0.000
transport_(124)%polar=  0.000
transport_(124)%collision=  1.000
transport_(124)%MW=166.307
 
transport_(125)%nome='BENZYNE'
transport_(125)%geometry=2
transport_(125)%LJpotential=468.500
transport_(125)%LJdiameter=  5.230
transport_(125)%dipole=  0.000
transport_(125)%polar= 10.300
transport_(125)%collision=  1.000
transport_(125)%MW= 76.098
 
transport_(126)%nome='C2H2O2'
transport_(126)%geometry=2
transport_(126)%LJpotential=470.600
transport_(126)%LJdiameter=  4.410
transport_(126)%dipole=  0.000
transport_(126)%polar=  0.000
transport_(126)%collision=  1.500
transport_(126)%MW= 58.037
 
transport_(127)%nome='C4H6O2'
transport_(127)%geometry=2
transport_(127)%LJpotential=496.000
transport_(127)%LJdiameter=  5.200
transport_(127)%dipole=  0.000
transport_(127)%polar=  0.000
transport_(127)%collision=  1.000
transport_(127)%MW= 86.090
 
transport_(128)%nome='C5H4O2'
transport_(128)%geometry=2
transport_(128)%LJpotential=524.690
transport_(128)%LJdiameter=  5.653
transport_(128)%dipole=  0.000
transport_(128)%polar=  0.000
transport_(128)%collision=  1.000
transport_(128)%MW= 96.086
 
transport_(129)%nome='C5H8O4'
transport_(129)%geometry=2
transport_(129)%LJpotential=568.500
transport_(129)%LJdiameter=  5.230
transport_(129)%dipole=  0.000
transport_(129)%polar= 10.300
transport_(129)%collision=  1.000
transport_(129)%MW=132.116
 
transport_(130)%nome='C6H10O5'
transport_(130)%geometry=2
transport_(130)%LJpotential=568.500
transport_(130)%LJdiameter=  5.230
transport_(130)%dipole=  0.000
transport_(130)%polar= 10.300
transport_(130)%collision=  1.000
transport_(130)%MW=162.142
 
transport_(131)%nome='C8H10O3'
transport_(131)%geometry=2
transport_(131)%LJpotential=621.100
transport_(131)%LJdiameter=  5.640
transport_(131)%dipole=  0.000
transport_(131)%polar=  0.000
transport_(131)%collision=  1.000
transport_(131)%MW=154.166
 
transport_(132)%nome='HCOOH'
transport_(132)%geometry=2
transport_(132)%LJpotential=470.600
transport_(132)%LJdiameter=  3.855
transport_(132)%dipole=  0.000
transport_(132)%polar=  0.000
transport_(132)%collision=  1.000
transport_(132)%MW= 46.026
 
transport_(133)%nome='GLYCEROL'
transport_(133)%geometry=2
transport_(133)%LJpotential=748.365
transport_(133)%LJdiameter=  5.200
transport_(133)%dipole=  1.930
transport_(133)%polar=  9.430
transport_(133)%collision=  1.000
transport_(133)%MW= 92.095
 
transport_(134)%nome='C4H4O'
transport_(134)%geometry=2
transport_(134)%LJpotential=429.630
transport_(134)%LJdiameter=  5.040
transport_(134)%dipole=  0.000
transport_(134)%polar=  0.000
transport_(134)%collision=  1.000
transport_(134)%MW= 68.075
end subroutine transport_update
