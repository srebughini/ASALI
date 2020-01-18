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
 
transport_(7)%nome='CH2CHCH2'
transport_(7)%geometry=2
transport_(7)%LJpotential=316.000
transport_(7)%LJdiameter=  4.220
transport_(7)%dipole=  0.000
transport_(7)%polar=  0.000
transport_(7)%collision=  1.000
transport_(7)%MW= 41.073
 
transport_(8)%nome='CHCHCH3'
transport_(8)%geometry=2
transport_(8)%LJpotential=316.000
transport_(8)%LJdiameter=  4.220
transport_(8)%dipole=  0.000
transport_(8)%polar=  0.000
transport_(8)%collision=  1.000
transport_(8)%MW= 41.073
 
transport_(9)%nome='CH2CCH3'
transport_(9)%geometry=2
transport_(9)%LJpotential=316.000
transport_(9)%LJdiameter=  4.220
transport_(9)%dipole=  0.000
transport_(9)%polar=  0.000
transport_(9)%collision=  1.000
transport_(9)%MW= 41.073
 
transport_(10)%nome='AR'
transport_(10)%geometry=0
transport_(10)%LJpotential=136.500
transport_(10)%LJdiameter=  3.330
transport_(10)%dipole=  0.000
transport_(10)%polar=  0.000
transport_(10)%collision=  0.000
transport_(10)%MW= 39.948
 
transport_(11)%nome='C6H5CH2OH'
transport_(11)%geometry=2
transport_(11)%LJpotential=622.400
transport_(11)%LJdiameter=  5.530
transport_(11)%dipole=  0.000
transport_(11)%polar=  0.000
transport_(11)%collision=  1.000
transport_(11)%MW=108.140
 
transport_(12)%nome='C6H4O2'
transport_(12)%geometry=2
transport_(12)%LJpotential=450.000
transport_(12)%LJdiameter=  5.500
transport_(12)%dipole=  0.000
transport_(12)%polar=  0.000
transport_(12)%collision=  1.000
transport_(12)%MW=108.097
 
transport_(13)%nome='C6H6'
transport_(13)%geometry=2
transport_(13)%LJpotential=468.500
transport_(13)%LJdiameter=  5.230
transport_(13)%dipole=  0.000
transport_(13)%polar= 10.300
transport_(13)%collision=  1.000
transport_(13)%MW= 78.114
 
transport_(14)%nome='C6H5CHO'
transport_(14)%geometry=2
transport_(14)%LJpotential=622.400
transport_(14)%LJdiameter=  5.530
transport_(14)%dipole=  0.000
transport_(14)%polar=  0.000
transport_(14)%collision=  1.000
transport_(14)%MW=106.124
 
transport_(15)%nome='C6H5C2H4C6H5'
transport_(15)%geometry=2
transport_(15)%LJpotential=783.800
transport_(15)%LJdiameter=  6.640
transport_(15)%dipole=  0.000
transport_(15)%polar=  0.000
transport_(15)%collision=  1.000
transport_(15)%MW=182.265
 
transport_(16)%nome='NC4H8'
transport_(16)%geometry=2
transport_(16)%LJpotential=355.000
transport_(16)%LJdiameter=  4.650
transport_(16)%dipole=  0.000
transport_(16)%polar=  0.000
transport_(16)%collision=  1.000
transport_(16)%MW= 56.107
 
transport_(17)%nome='C4H6'
transport_(17)%geometry=2
transport_(17)%LJpotential=357.000
transport_(17)%LJdiameter=  5.180
transport_(17)%dipole=  0.000
transport_(17)%polar=  0.000
transport_(17)%collision=  1.000
transport_(17)%MW= 54.092
 
transport_(18)%nome='C'
transport_(18)%geometry=0
transport_(18)%LJpotential= 71.400
transport_(18)%LJdiameter=  3.298
transport_(18)%dipole=  0.000
transport_(18)%polar=  0.000
transport_(18)%collision=  0.000
transport_(18)%MW= 12.011
 
transport_(19)%nome='C12H8'
transport_(19)%geometry=2
transport_(19)%LJpotential=689.800
transport_(19)%LJdiameter=  6.500
transport_(19)%dipole=  0.000
transport_(19)%polar=  0.000
transport_(19)%collision=  1.000
transport_(19)%MW=152.196
 
transport_(20)%nome='C2H'
transport_(20)%geometry=1
transport_(20)%LJpotential=209.000
transport_(20)%LJdiameter=  4.100
transport_(20)%dipole=  0.000
transport_(20)%polar=  0.000
transport_(20)%collision=  2.500
transport_(20)%MW= 25.030
 
transport_(21)%nome='C2H2'
transport_(21)%geometry=1
transport_(21)%LJpotential=209.000
transport_(21)%LJdiameter=  4.100
transport_(21)%dipole=  0.000
transport_(21)%polar=  0.000
transport_(21)%collision=  2.500
transport_(21)%MW= 26.038
 
transport_(22)%nome='C2H4'
transport_(22)%geometry=2
transport_(22)%LJpotential=280.800
transport_(22)%LJdiameter=  3.971
transport_(22)%dipole=  0.000
transport_(22)%polar=  0.000
transport_(22)%collision=  1.500
transport_(22)%MW= 28.054
 
transport_(23)%nome='C2H5'
transport_(23)%geometry=2
transport_(23)%LJpotential=252.300
transport_(23)%LJdiameter=  4.302
transport_(23)%dipole=  0.000
transport_(23)%polar=  0.000
transport_(23)%collision=  1.500
transport_(23)%MW= 29.062
 
transport_(24)%nome='C2H6'
transport_(24)%geometry=2
transport_(24)%LJpotential=252.300
transport_(24)%LJdiameter=  4.302
transport_(24)%dipole=  0.000
transport_(24)%polar=  0.000
transport_(24)%collision=  1.500
transport_(24)%MW= 30.070
 
transport_(25)%nome='C3H2'
transport_(25)%geometry=2
transport_(25)%LJpotential=209.000
transport_(25)%LJdiameter=  4.100
transport_(25)%dipole=  0.000
transport_(25)%polar=  0.000
transport_(25)%collision=  1.000
transport_(25)%MW= 38.049
 
transport_(26)%nome='C3H3'
transport_(26)%geometry=2
transport_(26)%LJpotential=252.000
transport_(26)%LJdiameter=  4.760
transport_(26)%dipole=  0.000
transport_(26)%polar=  0.000
transport_(26)%collision=  1.000
transport_(26)%MW= 39.057
 
transport_(27)%nome='C3H6'
transport_(27)%geometry=2
transport_(27)%LJpotential=307.800
transport_(27)%LJdiameter=  4.140
transport_(27)%dipole=  0.000
transport_(27)%polar=  0.000
transport_(27)%collision=  1.000
transport_(27)%MW= 42.081
 
transport_(28)%nome='C3H8'
transport_(28)%geometry=2
transport_(28)%LJpotential=303.400
transport_(28)%LJdiameter=  4.810
transport_(28)%dipole=  0.000
transport_(28)%polar=  0.000
transport_(28)%collision=  1.000
transport_(28)%MW= 44.097
 
transport_(29)%nome='NC3H7O'
transport_(29)%geometry=2
transport_(29)%LJpotential=487.900
transport_(29)%LJdiameter=  4.820
transport_(29)%dipole=  0.000
transport_(29)%polar=  0.000
transport_(29)%collision=  1.000
transport_(29)%MW= 59.088
 
transport_(30)%nome='C3H7OOH'
transport_(30)%geometry=2
transport_(30)%LJpotential=487.900
transport_(30)%LJdiameter=  4.820
transport_(30)%dipole=  0.000
transport_(30)%polar=  0.000
transport_(30)%collision=  1.000
transport_(30)%MW= 76.095
 
transport_(31)%nome='C4H2'
transport_(31)%geometry=1
transport_(31)%LJpotential=357.000
transport_(31)%LJdiameter=  5.180
transport_(31)%dipole=  0.000
transport_(31)%polar=  0.000
transport_(31)%collision=  1.000
transport_(31)%MW= 50.060
 
transport_(32)%nome='C4H3'
transport_(32)%geometry=1
transport_(32)%LJpotential=357.000
transport_(32)%LJdiameter=  5.180
transport_(32)%dipole=  0.000
transport_(32)%polar=  0.000
transport_(32)%collision=  1.000
transport_(32)%MW= 51.068
 
transport_(33)%nome='C4H4'
transport_(33)%geometry=2
transport_(33)%LJpotential=357.000
transport_(33)%LJdiameter=  5.180
transport_(33)%dipole=  0.000
transport_(33)%polar=  0.000
transport_(33)%collision=  1.000
transport_(33)%MW= 52.076
 
transport_(34)%nome='C4H5'
transport_(34)%geometry=2
transport_(34)%LJpotential=357.000
transport_(34)%LJdiameter=  5.180
transport_(34)%dipole=  0.000
transport_(34)%polar=  0.000
transport_(34)%collision=  1.000
transport_(34)%MW= 53.084
 
transport_(35)%nome='CH2C3H5'
transport_(35)%geometry=2
transport_(35)%LJpotential=355.000
transport_(35)%LJdiameter=  4.650
transport_(35)%dipole=  0.000
transport_(35)%polar=  0.000
transport_(35)%collision=  1.000
transport_(35)%MW= 55.100
 
transport_(36)%nome='SC4H7'
transport_(36)%geometry=2
transport_(36)%LJpotential=355.000
transport_(36)%LJdiameter=  4.650
transport_(36)%dipole=  0.000
transport_(36)%polar=  0.000
transport_(36)%collision=  1.000
transport_(36)%MW= 55.100
 
transport_(37)%nome='C4H9OOH'
transport_(37)%geometry=2
transport_(37)%LJpotential=496.000
transport_(37)%LJdiameter=  5.200
transport_(37)%dipole=  0.000
transport_(37)%polar=  0.000
transport_(37)%collision=  1.000
transport_(37)%MW= 90.122
 
transport_(38)%nome='CYC5H4O'
transport_(38)%geometry=2
transport_(38)%LJpotential=450.000
transport_(38)%LJdiameter=  5.500
transport_(38)%dipole=  0.000
transport_(38)%polar=  0.000
transport_(38)%collision=  1.000
transport_(38)%MW= 80.086
 
transport_(39)%nome='C5H7'
transport_(39)%geometry=2
transport_(39)%LJpotential=408.000
transport_(39)%LJdiameter=  5.200
transport_(39)%dipole=  0.000
transport_(39)%polar=  0.000
transport_(39)%collision=  1.000
transport_(39)%MW= 67.111
 
transport_(40)%nome='NC5H11OOH'
transport_(40)%geometry=2
transport_(40)%LJpotential=492.000
transport_(40)%LJdiameter=  5.640
transport_(40)%dipole=  0.000
transport_(40)%polar=  0.000
transport_(40)%collision=  1.000
transport_(40)%MW=104.149
 
transport_(41)%nome='C6H5'
transport_(41)%geometry=2
transport_(41)%LJpotential=468.500
transport_(41)%LJdiameter=  5.230
transport_(41)%dipole=  0.000
transport_(41)%polar= 10.300
transport_(41)%collision=  1.000
transport_(41)%MW= 77.106
 
transport_(42)%nome='C6H5O'
transport_(42)%geometry=2
transport_(42)%LJpotential=450.000
transport_(42)%LJdiameter=  5.500
transport_(42)%dipole=  0.000
transport_(42)%polar=  0.000
transport_(42)%collision=  1.000
transport_(42)%MW= 93.105
 
transport_(43)%nome='LC6H6'
transport_(43)%geometry=2
transport_(43)%LJpotential=412.300
transport_(43)%LJdiameter=  5.349
transport_(43)%dipole=  0.000
transport_(43)%polar=  0.000
transport_(43)%collision=  1.000
transport_(43)%MW= 78.114
 
transport_(44)%nome='CYC6H10-ONE'
transport_(44)%geometry=2
transport_(44)%LJpotential=568.500
transport_(44)%LJdiameter=  5.230
transport_(44)%dipole=  0.000
transport_(44)%polar= 10.300
transport_(44)%collision=  1.000
transport_(44)%MW= 98.145
 
transport_(45)%nome='C7H7'
transport_(45)%geometry=2
transport_(45)%LJpotential=495.300
transport_(45)%LJdiameter=  5.680
transport_(45)%dipole=  0.000
transport_(45)%polar=  0.000
transport_(45)%collision=  1.000
transport_(45)%MW= 91.133
 
transport_(46)%nome='NC7H15OOH'
transport_(46)%geometry=2
transport_(46)%LJpotential=559.980
transport_(46)%LJdiameter=  6.310
transport_(46)%dipole=  0.000
transport_(46)%polar=  0.000
transport_(46)%collision=  1.000
transport_(46)%MW=132.203
 
transport_(47)%nome='CYC5H8'
transport_(47)%geometry=1
transport_(47)%LJpotential=408.000
transport_(47)%LJdiameter=  5.200
transport_(47)%dipole=  0.000
transport_(47)%polar=  0.000
transport_(47)%collision=  1.000
transport_(47)%MW= 68.118
 
transport_(48)%nome='CYC6H8'
transport_(48)%geometry=2
transport_(48)%LJpotential=468.500
transport_(48)%LJdiameter=  5.230
transport_(48)%dipole=  0.000
transport_(48)%polar= 10.300
transport_(48)%collision=  1.000
transport_(48)%MW= 80.130
 
transport_(49)%nome='CYC6H12'
transport_(49)%geometry=2
transport_(49)%LJpotential=468.500
transport_(49)%LJdiameter=  5.230
transport_(49)%dipole=  0.000
transport_(49)%polar= 10.300
transport_(49)%collision=  1.000
transport_(49)%MW= 84.161
 
transport_(50)%nome='CYC6H10'
transport_(50)%geometry=2
transport_(50)%LJpotential=468.500
transport_(50)%LJdiameter=  5.230
transport_(50)%dipole=  0.000
transport_(50)%polar= 10.300
transport_(50)%collision=  1.000
transport_(50)%MW= 82.145
 
transport_(51)%nome='CH'
transport_(51)%geometry=1
transport_(51)%LJpotential= 80.000
transport_(51)%LJdiameter=  2.750
transport_(51)%dipole=  0.000
transport_(51)%polar=  0.000
transport_(51)%collision=  0.000
transport_(51)%MW= 13.019
 
transport_(52)%nome='CH2'
transport_(52)%geometry=1
transport_(52)%LJpotential=144.000
transport_(52)%LJdiameter=  3.800
transport_(52)%dipole=  0.000
transport_(52)%polar=  0.000
transport_(52)%collision=  0.000
transport_(52)%MW= 14.027
 
transport_(53)%nome='CH2CO'
transport_(53)%geometry=2
transport_(53)%LJpotential=436.000
transport_(53)%LJdiameter=  3.970
transport_(53)%dipole=  0.000
transport_(53)%polar=  0.000
transport_(53)%collision=  2.000
transport_(53)%MW= 42.037
 
transport_(54)%nome='CH2O'
transport_(54)%geometry=2
transport_(54)%LJpotential=498.000
transport_(54)%LJdiameter=  3.590
transport_(54)%dipole=  0.000
transport_(54)%polar=  0.000
transport_(54)%collision=  2.000
transport_(54)%MW= 30.026
 
transport_(55)%nome='CH2OH'
transport_(55)%geometry=2
transport_(55)%LJpotential=417.000
transport_(55)%LJdiameter=  3.690
transport_(55)%dipole=  1.700
transport_(55)%polar=  0.000
transport_(55)%collision=  2.000
transport_(55)%MW= 31.034
 
transport_(56)%nome='CH2S'
transport_(56)%geometry=1
transport_(56)%LJpotential=144.000
transport_(56)%LJdiameter=  3.800
transport_(56)%dipole=  0.000
transport_(56)%polar=  0.000
transport_(56)%collision=  0.000
transport_(56)%MW= 14.027
 
transport_(57)%nome='CH3'
transport_(57)%geometry=1
transport_(57)%LJpotential=144.000
transport_(57)%LJdiameter=  3.800
transport_(57)%dipole=  0.000
transport_(57)%polar=  0.000
transport_(57)%collision=  0.000
transport_(57)%MW= 15.035
 
transport_(58)%nome='CH3CO'
transport_(58)%geometry=2
transport_(58)%LJpotential=436.000
transport_(58)%LJdiameter=  3.970
transport_(58)%dipole=  0.000
transport_(58)%polar=  0.000
transport_(58)%collision=  2.000
transport_(58)%MW= 43.045
 
transport_(59)%nome='CH3O'
transport_(59)%geometry=2
transport_(59)%LJpotential=417.000
transport_(59)%LJdiameter=  3.690
transport_(59)%dipole=  1.700
transport_(59)%polar=  0.000
transport_(59)%collision=  2.000
transport_(59)%MW= 31.034
 
transport_(60)%nome='CH3OH'
transport_(60)%geometry=2
transport_(60)%LJpotential=481.800
transport_(60)%LJdiameter=  3.626
transport_(60)%dipole=  0.000
transport_(60)%polar=  0.000
transport_(60)%collision=  1.000
transport_(60)%MW= 32.042
 
transport_(61)%nome='CH4'
transport_(61)%geometry=2
transport_(61)%LJpotential=141.400
transport_(61)%LJdiameter=  3.746
transport_(61)%dipole=  0.000
transport_(61)%polar=  2.600
transport_(61)%collision= 13.000
transport_(61)%MW= 16.043
 
transport_(62)%nome='CO'
transport_(62)%geometry=1
transport_(62)%LJpotential= 98.100
transport_(62)%LJdiameter=  3.650
transport_(62)%dipole=  0.000
transport_(62)%polar=  1.950
transport_(62)%collision=  1.800
transport_(62)%MW= 28.010
 
transport_(63)%nome='CO2'
transport_(63)%geometry=1
transport_(63)%LJpotential=244.000
transport_(63)%LJdiameter=  3.763
transport_(63)%dipole=  0.000
transport_(63)%polar=  2.650
transport_(63)%collision=  2.100
transport_(63)%MW= 44.010
 
transport_(64)%nome='CYC5H6'
transport_(64)%geometry=2
transport_(64)%LJpotential=408.000
transport_(64)%LJdiameter=  5.200
transport_(64)%dipole=  0.000
transport_(64)%polar=  0.000
transport_(64)%collision=  1.000
transport_(64)%MW= 66.103
 
transport_(65)%nome='MCPTD'
transport_(65)%geometry=2
transport_(65)%LJpotential=408.000
transport_(65)%LJdiameter=  5.200
transport_(65)%dipole=  0.000
transport_(65)%polar=  0.000
transport_(65)%collision=  1.000
transport_(65)%MW= 80.130
 
transport_(66)%nome='CRESOL'
transport_(66)%geometry=2
transport_(66)%LJpotential=621.100
transport_(66)%LJdiameter=  5.640
transport_(66)%dipole=  0.000
transport_(66)%polar=  0.000
transport_(66)%collision=  1.000
transport_(66)%MW=108.140
 
transport_(67)%nome='NC10H20'
transport_(67)%geometry=2
transport_(67)%LJpotential=540.980
transport_(67)%LJdiameter=  7.150
transport_(67)%dipole=  0.000
transport_(67)%polar=  0.000
transport_(67)%collision=  1.000
transport_(67)%MW=140.269
 
transport_(68)%nome='C6H5CH2C6H5'
transport_(68)%geometry=2
transport_(68)%LJpotential=712.600
transport_(68)%LJdiameter=  6.890
transport_(68)%dipole=  0.000
transport_(68)%polar=  0.000
transport_(68)%collision=  1.000
transport_(68)%MW=168.238
 
transport_(69)%nome='DIPE'
transport_(69)%geometry=2
transport_(69)%LJpotential=432.000
transport_(69)%LJdiameter=  6.000
transport_(69)%dipole=  0.000
transport_(69)%polar=  0.000
transport_(69)%collision=  1.000
transport_(69)%MW=102.177
 
transport_(70)%nome='MTBE-O'
transport_(70)%geometry=2
transport_(70)%LJpotential=492.000
transport_(70)%LJdiameter=  5.640
transport_(70)%dipole=  0.000
transport_(70)%polar=  0.000
transport_(70)%collision=  1.000
transport_(70)%MW=102.133
 
transport_(71)%nome='CH3OCH3'
transport_(71)%geometry=2
transport_(71)%LJpotential=303.400
transport_(71)%LJdiameter=  4.810
transport_(71)%dipole=  0.000
transport_(71)%polar=  0.000
transport_(71)%collision=  1.000
transport_(71)%MW= 46.069
 
transport_(72)%nome='CH3CH3-C5H6'
transport_(72)%geometry=2
transport_(72)%LJpotential=450.000
transport_(72)%LJdiameter=  5.500
transport_(72)%dipole=  0.000
transport_(72)%polar=  0.000
transport_(72)%collision=  1.000
transport_(72)%MW= 96.172
 
transport_(73)%nome='C6H5C2H5'
transport_(73)%geometry=2
transport_(73)%LJpotential=523.600
transport_(73)%LJdiameter=  5.960
transport_(73)%dipole=  0.000
transport_(73)%polar=  0.000
transport_(73)%collision=  1.000
transport_(73)%MW=106.167
 
transport_(74)%nome='NC7H14'
transport_(74)%geometry=2
transport_(74)%LJpotential=459.980
transport_(74)%LJdiameter=  6.310
transport_(74)%dipole=  0.000
transport_(74)%polar=  0.000
transport_(74)%collision=  1.000
transport_(74)%MW= 98.188
 
transport_(75)%nome='NC6H12'
transport_(75)%geometry=2
transport_(75)%LJpotential=412.300
transport_(75)%LJdiameter=  5.349
transport_(75)%dipole=  0.000
transport_(75)%polar=  0.000
transport_(75)%collision=  1.000
transport_(75)%MW= 84.161
 
transport_(76)%nome='C5H9CHO'
transport_(76)%geometry=2
transport_(76)%LJpotential=568.500
transport_(76)%LJdiameter=  5.230
transport_(76)%dipole=  0.000
transport_(76)%polar= 10.300
transport_(76)%collision=  1.000
transport_(76)%MW= 98.145
 
transport_(77)%nome='ETBE'
transport_(77)%geometry=2
transport_(77)%LJpotential=432.000
transport_(77)%LJdiameter=  6.000
transport_(77)%dipole=  0.000
transport_(77)%polar=  0.000
transport_(77)%collision=  1.000
transport_(77)%MW=102.177
 
transport_(78)%nome='NEOC5H10-O'
transport_(78)%geometry=2
transport_(78)%LJpotential=492.000
transport_(78)%LJdiameter=  5.640
transport_(78)%dipole=  0.000
transport_(78)%polar=  0.000
transport_(78)%collision=  1.000
transport_(78)%MW= 86.134
 
transport_(79)%nome='C4H8O'
transport_(79)%geometry=2
transport_(79)%LJpotential=496.000
transport_(79)%LJdiameter=  5.200
transport_(79)%dipole=  0.000
transport_(79)%polar=  0.000
transport_(79)%collision=  1.000
transport_(79)%MW= 72.107
 
transport_(80)%nome='NC5H10-O'
transport_(80)%geometry=2
transport_(80)%LJpotential=492.000
transport_(80)%LJdiameter=  5.640
transport_(80)%dipole=  0.000
transport_(80)%polar=  0.000
transport_(80)%collision=  1.000
transport_(80)%MW= 86.134
 
transport_(81)%nome='NC7H14O'
transport_(81)%geometry=2
transport_(81)%LJpotential=559.980
transport_(81)%LJdiameter=  6.310
transport_(81)%dipole=  0.000
transport_(81)%polar=  0.000
transport_(81)%collision=  1.000
transport_(81)%MW=114.188
 
transport_(82)%nome='IC8H16O'
transport_(82)%geometry=2
transport_(82)%LJpotential=594.000
transport_(82)%LJdiameter=  6.170
transport_(82)%dipole=  0.000
transport_(82)%polar=  0.000
transport_(82)%collision=  1.000
transport_(82)%MW=128.214
 
transport_(83)%nome='C2H5OH'
transport_(83)%geometry=2
transport_(83)%LJpotential=362.600
transport_(83)%LJdiameter=  4.530
transport_(83)%dipole=  0.000
transport_(83)%polar=  0.000
transport_(83)%collision=  1.500
transport_(83)%MW= 46.069
 
transport_(84)%nome='C2H5OO'
transport_(84)%geometry=2
transport_(84)%LJpotential=362.600
transport_(84)%LJdiameter=  4.530
transport_(84)%dipole=  0.000
transport_(84)%polar=  0.000
transport_(84)%collision=  1.500
transport_(84)%MW= 61.061
 
transport_(85)%nome='C2H5OOH'
transport_(85)%geometry=2
transport_(85)%LJpotential=362.600
transport_(85)%LJdiameter=  4.530
transport_(85)%dipole=  0.000
transport_(85)%polar=  0.000
transport_(85)%collision=  1.500
transport_(85)%MW= 62.068
 
transport_(86)%nome='C2H4O'
transport_(86)%geometry=2
transport_(86)%LJpotential=362.600
transport_(86)%LJdiameter=  4.530
transport_(86)%dipole=  0.000
transport_(86)%polar=  0.000
transport_(86)%collision=  1.500
transport_(86)%MW= 44.053
 
transport_(87)%nome='C6H5C2H'
transport_(87)%geometry=2
transport_(87)%LJpotential=534.300
transport_(87)%LJdiameter=  5.710
transport_(87)%dipole=  0.770
transport_(87)%polar=  0.000
transport_(87)%collision=  1.000
transport_(87)%MW=102.136
 
transport_(88)%nome='BIPHENYL'
transport_(88)%geometry=2
transport_(88)%LJpotential=676.500
transport_(88)%LJdiameter=  6.310
transport_(88)%dipole=  0.000
transport_(88)%polar=  0.000
transport_(88)%collision=  1.000
transport_(88)%MW=154.211
 
transport_(89)%nome='C14H10'
transport_(89)%geometry=2
transport_(89)%LJpotential=772.000
transport_(89)%LJdiameter=  6.960
transport_(89)%dipole=  0.000
transport_(89)%polar= 38.800
transport_(89)%collision=  1.000
transport_(89)%MW=178.233
 
transport_(90)%nome='C6H5OH'
transport_(90)%geometry=2
transport_(90)%LJpotential=450.000
transport_(90)%LJdiameter=  5.500
transport_(90)%dipole=  0.000
transport_(90)%polar=  0.000
transport_(90)%collision=  1.000
transport_(90)%MW= 94.113
 
transport_(91)%nome='FLUORENE'
transport_(91)%geometry=2
transport_(91)%LJpotential=712.600
transport_(91)%LJdiameter=  6.890
transport_(91)%dipole=  0.000
transport_(91)%polar=  0.000
transport_(91)%collision=  1.000
transport_(91)%MW=166.222
 
transport_(92)%nome='C10H8'
transport_(92)%geometry=2
transport_(92)%LJpotential=630.400
transport_(92)%LJdiameter=  6.180
transport_(92)%dipole=  0.000
transport_(92)%polar= 16.500
transport_(92)%collision=  1.000
transport_(92)%MW=128.174
 
transport_(93)%nome='H'
transport_(93)%geometry=0
transport_(93)%LJpotential=145.000
transport_(93)%LJdiameter=  2.050
transport_(93)%dipole=  0.000
transport_(93)%polar=  0.000
transport_(93)%collision=  0.000
transport_(93)%MW=  1.008
 
transport_(94)%nome='H2'
transport_(94)%geometry=1
transport_(94)%LJpotential= 38.000
transport_(94)%LJdiameter=  2.920
transport_(94)%dipole=  0.000
transport_(94)%polar=  0.790
transport_(94)%collision=280.000
transport_(94)%MW=  2.016
 
transport_(95)%nome='H2O'
transport_(95)%geometry=2
transport_(95)%LJpotential=572.400
transport_(95)%LJdiameter=  2.605
transport_(95)%dipole=  1.844
transport_(95)%polar=  0.000
transport_(95)%collision=  4.000
transport_(95)%MW= 18.015
 
transport_(96)%nome='H2O2'
transport_(96)%geometry=2
transport_(96)%LJpotential=107.400
transport_(96)%LJdiameter=  3.458
transport_(96)%dipole=  0.000
transport_(96)%polar=  0.000
transport_(96)%collision=  3.800
transport_(96)%MW= 34.015
 
transport_(97)%nome='HCCO'
transport_(97)%geometry=2
transport_(97)%LJpotential=150.000
transport_(97)%LJdiameter=  2.500
transport_(97)%dipole=  0.000
transport_(97)%polar=  0.000
transport_(97)%collision=  1.000
transport_(97)%MW= 41.029
 
transport_(98)%nome='HCO'
transport_(98)%geometry=2
transport_(98)%LJpotential=498.000
transport_(98)%LJdiameter=  3.590
transport_(98)%dipole=  0.000
transport_(98)%polar=  0.000
transport_(98)%collision=  0.000
transport_(98)%MW= 29.018
 
transport_(99)%nome='HCO3'
transport_(99)%geometry=2
transport_(99)%LJpotential=498.000
transport_(99)%LJdiameter=  3.590
transport_(99)%dipole=  0.000
transport_(99)%polar=  0.000
transport_(99)%collision=  0.000
transport_(99)%MW= 61.017
 
transport_(100)%nome='HE'
transport_(100)%geometry=0
transport_(100)%LJpotential= 10.200
transport_(100)%LJdiameter=  2.576
transport_(100)%dipole=  0.000
transport_(100)%polar=  0.000
transport_(100)%collision=  0.000
transport_(100)%MW=  4.003
 
transport_(101)%nome='HO2'
transport_(101)%geometry=2
transport_(101)%LJpotential=107.400
transport_(101)%LJdiameter=  3.458
transport_(101)%dipole=  0.000
transport_(101)%polar=  0.000
transport_(101)%collision=  1.000
transport_(101)%MW= 33.007
 
transport_(102)%nome='IC4H8'
transport_(102)%geometry=2
transport_(102)%LJpotential=355.000
transport_(102)%LJdiameter=  4.650
transport_(102)%dipole=  0.000
transport_(102)%polar=  0.000
transport_(102)%collision=  1.000
transport_(102)%MW= 56.107
 
transport_(103)%nome='IC3H7CHO'
transport_(103)%geometry=2
transport_(103)%LJpotential=455.000
transport_(103)%LJdiameter=  4.650
transport_(103)%dipole=  0.000
transport_(103)%polar=  0.000
transport_(103)%collision=  1.000
transport_(103)%MW= 72.107
 
transport_(104)%nome='IC4H9P'
transport_(104)%geometry=2
transport_(104)%LJpotential=352.000
transport_(104)%LJdiameter=  5.240
transport_(104)%dipole=  0.000
transport_(104)%polar=  0.000
transport_(104)%collision=  1.000
transport_(104)%MW= 57.116
 
transport_(105)%nome='IC4H9P-OO'
transport_(105)%geometry=2
transport_(105)%LJpotential=496.000
transport_(105)%LJdiameter=  5.200
transport_(105)%dipole=  0.000
transport_(105)%polar=  0.000
transport_(105)%collision=  1.000
transport_(105)%MW= 89.114
 
transport_(106)%nome='IC4H9T'
transport_(106)%geometry=2
transport_(106)%LJpotential=352.000
transport_(106)%LJdiameter=  5.240
transport_(106)%dipole=  0.000
transport_(106)%polar=  0.000
transport_(106)%collision=  1.000
transport_(106)%MW= 57.116
 
transport_(107)%nome='IC4H9T-OO'
transport_(107)%geometry=2
transport_(107)%LJpotential=496.000
transport_(107)%LJdiameter=  5.200
transport_(107)%dipole=  0.000
transport_(107)%polar=  0.000
transport_(107)%collision=  1.000
transport_(107)%MW= 89.114
 
transport_(108)%nome='IC4H10'
transport_(108)%geometry=2
transport_(108)%LJpotential=352.000
transport_(108)%LJdiameter=  5.240
transport_(108)%dipole=  0.000
transport_(108)%polar=  0.000
transport_(108)%collision=  1.000
transport_(108)%MW= 58.123
 
transport_(109)%nome='IC16H34'
transport_(109)%geometry=2
transport_(109)%LJpotential=650.000
transport_(109)%LJdiameter=  8.350
transport_(109)%dipole=  0.000
transport_(109)%polar=  0.000
transport_(109)%collision=  1.000
transport_(109)%MW=226.446
 
transport_(110)%nome='IC4H7'
transport_(110)%geometry=2
transport_(110)%LJpotential=355.000
transport_(110)%LJdiameter=  4.650
transport_(110)%dipole=  0.000
transport_(110)%polar=  0.000
transport_(110)%collision=  1.000
transport_(110)%MW= 55.100
 
transport_(111)%nome='IC8H18'
transport_(111)%geometry=2
transport_(111)%LJpotential=494.000
transport_(111)%LJdiameter=  6.170
transport_(111)%dipole=  0.000
transport_(111)%polar=  0.000
transport_(111)%collision=  1.000
transport_(111)%MW=114.231
 
transport_(112)%nome='INDENE'
transport_(112)%geometry=2
transport_(112)%LJpotential=588.600
transport_(112)%LJdiameter=  5.960
transport_(112)%dipole=  0.650
transport_(112)%polar=  0.000
transport_(112)%collision=  1.000
transport_(112)%MW=116.163
 
transport_(113)%nome='IC3H7'
transport_(113)%geometry=2
transport_(113)%LJpotential=303.400
transport_(113)%LJdiameter=  4.810
transport_(113)%dipole=  0.000
transport_(113)%polar=  0.000
transport_(113)%collision=  1.000
transport_(113)%MW= 43.089
 
transport_(114)%nome='IC3H7OH'
transport_(114)%geometry=2
transport_(114)%LJpotential=482.147
transport_(114)%LJdiameter=  5.009
transport_(114)%dipole=  1.660
transport_(114)%polar=  6.740
transport_(114)%collision=  1.000
transport_(114)%MW= 60.096
 
transport_(115)%nome='IC3H7OO'
transport_(115)%geometry=2
transport_(115)%LJpotential=468.300
transport_(115)%LJdiameter=  4.760
transport_(115)%dipole=  0.000
transport_(115)%polar=  0.000
transport_(115)%collision=  1.000
transport_(115)%MW= 75.087
 
transport_(116)%nome='IC3-QOOH'
transport_(116)%geometry=2
transport_(116)%LJpotential=468.300
transport_(116)%LJdiameter=  4.760
transport_(116)%dipole=  0.000
transport_(116)%polar=  0.000
transport_(116)%collision=  1.000
transport_(116)%MW= 75.087
 
transport_(117)%nome='IC3-OOQOOH'
transport_(117)%geometry=2
transport_(117)%LJpotential=468.300
transport_(117)%LJdiameter=  4.760
transport_(117)%dipole=  0.000
transport_(117)%polar=  0.000
transport_(117)%collision=  1.000
transport_(117)%MW=107.086
 
transport_(118)%nome='IC5H10'
transport_(118)%geometry=2
transport_(118)%LJpotential=408.000
transport_(118)%LJdiameter=  5.200
transport_(118)%dipole=  0.000
transport_(118)%polar=  0.000
transport_(118)%collision=  1.000
transport_(118)%MW= 70.134
 
transport_(119)%nome='NEOC5-OQOOH'
transport_(119)%geometry=2
transport_(119)%LJpotential=492.000
transport_(119)%LJdiameter=  5.640
transport_(119)%dipole=  0.000
transport_(119)%polar=  0.000
transport_(119)%collision=  1.000
transport_(119)%MW=118.133
 
transport_(120)%nome='IC4-OQOOH'
transport_(120)%geometry=2
transport_(120)%LJpotential=496.000
transport_(120)%LJdiameter=  5.200
transport_(120)%dipole=  0.000
transport_(120)%polar=  0.000
transport_(120)%collision=  1.000
transport_(120)%MW=104.106
 
transport_(121)%nome='C3-OQOOH'
transport_(121)%geometry=2
transport_(121)%LJpotential=487.900
transport_(121)%LJdiameter=  4.820
transport_(121)%dipole=  0.000
transport_(121)%polar=  0.000
transport_(121)%collision=  1.000
transport_(121)%MW= 90.079
 
transport_(122)%nome='NC4-OQOOH'
transport_(122)%geometry=2
transport_(122)%LJpotential=496.000
transport_(122)%LJdiameter=  5.200
transport_(122)%dipole=  0.000
transport_(122)%polar=  0.000
transport_(122)%collision=  1.000
transport_(122)%MW=104.106
 
transport_(123)%nome='NC5-OQOOH'
transport_(123)%geometry=2
transport_(123)%LJpotential=492.000
transport_(123)%LJdiameter=  5.640
transport_(123)%dipole=  0.000
transport_(123)%polar=  0.000
transport_(123)%collision=  1.000
transport_(123)%MW=118.133
 
transport_(124)%nome='NC7-OQOOH'
transport_(124)%geometry=2
transport_(124)%LJpotential=559.980
transport_(124)%LJdiameter=  6.310
transport_(124)%dipole=  0.000
transport_(124)%polar=  0.000
transport_(124)%collision=  1.000
transport_(124)%MW=146.186
 
transport_(125)%nome='IC8-OQOOH'
transport_(125)%geometry=2
transport_(125)%LJpotential=594.000
transport_(125)%LJdiameter=  6.170
transport_(125)%dipole=  0.000
transport_(125)%polar=  0.000
transport_(125)%collision=  1.000
transport_(125)%MW=160.213
 
transport_(126)%nome='DME-OQOOH'
transport_(126)%geometry=2
transport_(126)%LJpotential=403.400
transport_(126)%LJdiameter=  4.810
transport_(126)%dipole=  0.000
transport_(126)%polar=  0.000
transport_(126)%collision=  1.000
transport_(126)%MW= 92.051
 
transport_(127)%nome='NC10-OQOOH'
transport_(127)%geometry=2
transport_(127)%LJpotential=640.980
transport_(127)%LJdiameter=  7.150
transport_(127)%dipole=  0.000
transport_(127)%polar=  0.000
transport_(127)%collision=  1.000
transport_(127)%MW=188.267
 
transport_(128)%nome='NC12-OQOOH'
transport_(128)%geometry=2
transport_(128)%LJpotential=680.000
transport_(128)%LJdiameter=  7.600
transport_(128)%dipole=  0.000
transport_(128)%polar=  0.000
transport_(128)%collision=  1.000
transport_(128)%MW=216.321
 
transport_(129)%nome='IC16-OQOOH'
transport_(129)%geometry=2
transport_(129)%LJpotential=750.000
transport_(129)%LJdiameter=  8.350
transport_(129)%dipole=  0.000
transport_(129)%polar=  0.000
transport_(129)%collision=  1.000
transport_(129)%MW=272.428
 
transport_(130)%nome='MCYC6-OQOOH'
transport_(130)%geometry=2
transport_(130)%LJpotential=595.300
transport_(130)%LJdiameter=  5.680
transport_(130)%dipole=  0.430
transport_(130)%polar= 12.300
transport_(130)%collision=  1.000
transport_(130)%MW=144.170
 
transport_(131)%nome='MTBE-OQOOH'
transport_(131)%geometry=2
transport_(131)%LJpotential=492.000
transport_(131)%LJdiameter=  5.640
transport_(131)%dipole=  0.000
transport_(131)%polar=  0.000
transport_(131)%collision=  1.000
transport_(131)%MW=134.132
 
transport_(132)%nome='IC3H5CHO'
transport_(132)%geometry=2
transport_(132)%LJpotential=357.000
transport_(132)%LJdiameter=  5.180
transport_(132)%dipole=  0.000
transport_(132)%polar=  0.000
transport_(132)%collision=  1.000
transport_(132)%MW= 70.091
 
transport_(133)%nome='MCYC6'
transport_(133)%geometry=2
transport_(133)%LJpotential=495.300
transport_(133)%LJdiameter=  5.680
transport_(133)%dipole=  0.430
transport_(133)%polar= 12.300
transport_(133)%collision=  1.000
transport_(133)%MW= 98.188
 
transport_(134)%nome='CH3CHO'
transport_(134)%geometry=2
transport_(134)%LJpotential=436.000
transport_(134)%LJdiameter=  3.970
transport_(134)%dipole=  0.000
transport_(134)%polar=  0.000
transport_(134)%collision=  2.000
transport_(134)%MW= 44.053
 
transport_(135)%nome='CH3CO3'
transport_(135)%geometry=2
transport_(135)%LJpotential=436.000
transport_(135)%LJdiameter=  3.970
transport_(135)%dipole=  0.000
transport_(135)%polar=  0.000
transport_(135)%collision=  2.000
transport_(135)%MW= 75.044
 
transport_(136)%nome='C10H7CH3'
transport_(136)%geometry=2
transport_(136)%LJpotential=660.000
transport_(136)%LJdiameter=  6.350
transport_(136)%dipole=  0.000
transport_(136)%polar=  0.000
transport_(136)%collision=  1.000
transport_(136)%MW=142.200
 
transport_(137)%nome='CH3OO'
transport_(137)%geometry=2
transport_(137)%LJpotential=417.000
transport_(137)%LJdiameter=  3.690
transport_(137)%dipole=  1.700
transport_(137)%polar=  0.000
transport_(137)%collision=  2.000
transport_(137)%MW= 47.034
 
transport_(138)%nome='CH3OOH'
transport_(138)%geometry=2
transport_(138)%LJpotential=481.800
transport_(138)%LJdiameter=  3.626
transport_(138)%dipole=  0.000
transport_(138)%polar=  0.000
transport_(138)%collision=  1.000
transport_(138)%MW= 48.042
 
transport_(139)%nome='MTBE'
transport_(139)%geometry=2
transport_(139)%LJpotential=392.000
transport_(139)%LJdiameter=  5.640
transport_(139)%dipole=  0.000
transport_(139)%polar=  0.000
transport_(139)%collision=  1.000
transport_(139)%MW= 88.150
 
transport_(140)%nome='N2'
transport_(140)%geometry=1
transport_(140)%LJpotential= 97.530
transport_(140)%LJdiameter=  3.621
transport_(140)%dipole=  0.000
transport_(140)%polar=  1.760
transport_(140)%collision=  4.000
transport_(140)%MW= 28.014
 
transport_(141)%nome='C10H7OH'
transport_(141)%geometry=2
transport_(141)%LJpotential=663.450
transport_(141)%LJdiameter=  6.362
transport_(141)%dipole=  0.000
transport_(141)%polar=  0.000
transport_(141)%collision=  1.000
transport_(141)%MW=144.173
 
transport_(142)%nome='C10H7CHO'
transport_(142)%geometry=2
transport_(142)%LJpotential=663.450
transport_(142)%LJdiameter=  6.362
transport_(142)%dipole=  0.000
transport_(142)%polar=  0.000
transport_(142)%collision=  1.000
transport_(142)%MW=156.184
 
transport_(143)%nome='CH3C10H6OH'
transport_(143)%geometry=2
transport_(143)%LJpotential=663.450
transport_(143)%LJdiameter=  6.362
transport_(143)%dipole=  0.000
transport_(143)%polar=  0.000
transport_(143)%collision=  1.000
transport_(143)%MW=158.200
 
transport_(144)%nome='CH3C10H6O'
transport_(144)%geometry=2
transport_(144)%LJpotential=663.450
transport_(144)%LJdiameter=  6.362
transport_(144)%dipole=  0.000
transport_(144)%polar=  0.000
transport_(144)%collision=  1.000
transport_(144)%MW=157.192
 
transport_(145)%nome='NC4H9P'
transport_(145)%geometry=2
transport_(145)%LJpotential=352.000
transport_(145)%LJdiameter=  5.240
transport_(145)%dipole=  0.000
transport_(145)%polar=  0.000
transport_(145)%collision=  1.000
transport_(145)%MW= 57.116
 
transport_(146)%nome='NC4H9S'
transport_(146)%geometry=2
transport_(146)%LJpotential=352.000
transport_(146)%LJdiameter=  5.240
transport_(146)%dipole=  0.000
transport_(146)%polar=  0.000
transport_(146)%collision=  1.000
transport_(146)%MW= 57.116
 
transport_(147)%nome='NC4H10'
transport_(147)%geometry=2
transport_(147)%LJpotential=352.000
transport_(147)%LJdiameter=  5.240
transport_(147)%dipole=  0.000
transport_(147)%polar=  0.000
transport_(147)%collision=  1.000
transport_(147)%MW= 58.123
 
transport_(148)%nome='NC10H22'
transport_(148)%geometry=2
transport_(148)%LJpotential=540.980
transport_(148)%LJdiameter=  7.150
transport_(148)%dipole=  0.000
transport_(148)%polar=  0.000
transport_(148)%collision=  1.000
transport_(148)%MW=142.285
 
transport_(149)%nome='NC12H26'
transport_(149)%geometry=2
transport_(149)%LJpotential=580.000
transport_(149)%LJdiameter=  7.600
transport_(149)%dipole=  0.000
transport_(149)%polar=  0.000
transport_(149)%collision=  1.000
transport_(149)%MW=170.338
 
transport_(150)%nome='NC5H12'
transport_(150)%geometry=2
transport_(150)%LJpotential=392.000
transport_(150)%LJdiameter=  5.640
transport_(150)%dipole=  0.000
transport_(150)%polar=  0.000
transport_(150)%collision=  1.000
transport_(150)%MW= 72.150
 
transport_(151)%nome='NC7H16'
transport_(151)%geometry=2
transport_(151)%LJpotential=459.980
transport_(151)%LJdiameter=  6.310
transport_(151)%dipole=  0.000
transport_(151)%polar=  0.000
transport_(151)%collision=  1.000
transport_(151)%MW=100.204
 
transport_(152)%nome='NEOC5H12'
transport_(152)%geometry=2
transport_(152)%LJpotential=392.000
transport_(152)%LJdiameter=  5.640
transport_(152)%dipole=  0.000
transport_(152)%polar=  0.000
transport_(152)%collision=  1.000
transport_(152)%MW= 72.150
 
transport_(153)%nome='NC3H7'
transport_(153)%geometry=2
transport_(153)%LJpotential=303.400
transport_(153)%LJdiameter=  4.810
transport_(153)%dipole=  0.000
transport_(153)%polar=  0.000
transport_(153)%collision=  1.000
transport_(153)%MW= 43.089
 
transport_(154)%nome='NC3H7OO'
transport_(154)%geometry=2
transport_(154)%LJpotential=487.900
transport_(154)%LJdiameter=  4.820
transport_(154)%dipole=  0.000
transport_(154)%polar=  0.000
transport_(154)%collision=  1.000
transport_(154)%MW= 75.087
 
transport_(155)%nome='NC3-QOOH'
transport_(155)%geometry=2
transport_(155)%LJpotential=487.900
transport_(155)%LJdiameter=  4.820
transport_(155)%dipole=  0.000
transport_(155)%polar=  0.000
transport_(155)%collision=  1.000
transport_(155)%MW= 75.087
 
transport_(156)%nome='NC3-OOQOOH'
transport_(156)%geometry=2
transport_(156)%LJpotential=487.900
transport_(156)%LJdiameter=  4.820
transport_(156)%dipole=  0.000
transport_(156)%polar=  0.000
transport_(156)%collision=  1.000
transport_(156)%MW=107.086
 
transport_(157)%nome='O'
transport_(157)%geometry=0
transport_(157)%LJpotential= 80.000
transport_(157)%LJdiameter=  2.750
transport_(157)%dipole=  0.000
transport_(157)%polar=  0.000
transport_(157)%collision=  0.000
transport_(157)%MW= 15.999
 
transport_(158)%nome='O2'
transport_(158)%geometry=1
transport_(158)%LJpotential=107.400
transport_(158)%LJdiameter=  3.458
transport_(158)%dipole=  0.000
transport_(158)%polar=  1.600
transport_(158)%collision=  3.800
transport_(158)%MW= 31.999
 
transport_(159)%nome='OH'
transport_(159)%geometry=1
transport_(159)%LJpotential= 80.000
transport_(159)%LJdiameter=  2.750
transport_(159)%dipole=  0.000
transport_(159)%polar=  0.000
transport_(159)%collision=  0.000
transport_(159)%MW= 17.007
 
transport_(160)%nome='IC8H16'
transport_(160)%geometry=2
transport_(160)%LJpotential=494.000
transport_(160)%LJdiameter=  6.170
transport_(160)%dipole=  0.000
transport_(160)%polar=  0.000
transport_(160)%collision=  1.000
transport_(160)%MW=112.215
 
transport_(161)%nome='NC5H10'
transport_(161)%geometry=2
transport_(161)%LJpotential=408.000
transport_(161)%LJdiameter=  5.200
transport_(161)%dipole=  0.000
transport_(161)%polar=  0.000
transport_(161)%collision=  1.000
transport_(161)%MW= 70.134
 
transport_(162)%nome='PC3H4'
transport_(162)%geometry=1
transport_(162)%LJpotential=252.000
transport_(162)%LJdiameter=  4.760
transport_(162)%dipole=  0.000
transport_(162)%polar=  0.000
transport_(162)%collision=  1.000
transport_(162)%MW= 40.065
 
transport_(163)%nome='CH3CO3H'
transport_(163)%geometry=2
transport_(163)%LJpotential=443.200
transport_(163)%LJdiameter=  4.120
transport_(163)%dipole=  0.000
transport_(163)%polar=  0.000
transport_(163)%collision=  1.000
transport_(163)%MW= 76.052
 
transport_(164)%nome='HCO3H'
transport_(164)%geometry=2
transport_(164)%LJpotential=443.200
transport_(164)%LJdiameter=  4.120
transport_(164)%dipole=  0.000
transport_(164)%polar=  0.000
transport_(164)%collision=  1.000
transport_(164)%MW= 62.025
 
transport_(165)%nome='C3H6O'
transport_(165)%geometry=2
transport_(165)%LJpotential=411.000
transport_(165)%LJdiameter=  4.820
transport_(165)%dipole=  0.000
transport_(165)%polar=  0.000
transport_(165)%collision=  1.000
transport_(165)%MW= 58.080
 
transport_(166)%nome='C5H8'
transport_(166)%geometry=2
transport_(166)%LJpotential=408.000
transport_(166)%LJdiameter=  5.200
transport_(166)%dipole=  0.000
transport_(166)%polar=  0.000
transport_(166)%collision=  1.000
transport_(166)%MW= 68.118
 
transport_(167)%nome='C16H10'
transport_(167)%geometry=2
transport_(167)%LJpotential=834.900
transport_(167)%LJdiameter=  7.240
transport_(167)%dipole=  0.000
transport_(167)%polar= 45.000
transport_(167)%collision=  1.000
transport_(167)%MW=202.255
 
transport_(168)%nome='NC10-QOOH'
transport_(168)%geometry=2
transport_(168)%LJpotential=640.980
transport_(168)%LJdiameter=  7.150
transport_(168)%dipole=  0.000
transport_(168)%polar=  0.000
transport_(168)%collision=  1.000
transport_(168)%MW=173.276
 
transport_(169)%nome='NC12-QOOH'
transport_(169)%geometry=2
transport_(169)%LJpotential=680.000
transport_(169)%LJdiameter=  7.600
transport_(169)%dipole=  0.000
transport_(169)%polar=  0.000
transport_(169)%collision=  1.000
transport_(169)%MW=201.329
 
transport_(170)%nome='C2-QOOH'
transport_(170)%geometry=2
transport_(170)%LJpotential=470.600
transport_(170)%LJdiameter=  4.410
transport_(170)%dipole=  0.000
transport_(170)%polar=  0.000
transport_(170)%collision=  1.500
transport_(170)%MW= 61.061
 
transport_(171)%nome='C2-OOQOOH'
transport_(171)%geometry=2
transport_(171)%LJpotential=470.600
transport_(171)%LJdiameter=  4.410
transport_(171)%dipole=  0.000
transport_(171)%polar=  0.000
transport_(171)%collision=  1.500
transport_(171)%MW= 93.059
 
transport_(172)%nome='C2-OQOOH'
transport_(172)%geometry=2
transport_(172)%LJpotential=470.600
transport_(172)%LJdiameter=  4.410
transport_(172)%dipole=  0.000
transport_(172)%polar=  0.000
transport_(172)%collision=  1.500
transport_(172)%MW= 76.052
 
transport_(173)%nome='NC4-QOOH'
transport_(173)%geometry=2
transport_(173)%LJpotential=496.000
transport_(173)%LJdiameter=  5.200
transport_(173)%dipole=  0.000
transport_(173)%polar=  0.000
transport_(173)%collision=  1.000
transport_(173)%MW= 89.114
 
transport_(174)%nome='NC5-QOOH'
transport_(174)%geometry=2
transport_(174)%LJpotential=492.000
transport_(174)%LJdiameter=  5.640
transport_(174)%dipole=  0.000
transport_(174)%polar=  0.000
transport_(174)%collision=  1.000
transport_(174)%MW=103.141
 
transport_(175)%nome='NC7-QOOH'
transport_(175)%geometry=2
transport_(175)%LJpotential=559.980
transport_(175)%LJdiameter=  6.310
transport_(175)%dipole=  0.000
transport_(175)%polar=  0.000
transport_(175)%collision=  1.000
transport_(175)%MW=131.195
 
transport_(176)%nome='DME-QOOH'
transport_(176)%geometry=2
transport_(176)%LJpotential=403.400
transport_(176)%LJdiameter=  4.810
transport_(176)%dipole=  0.000
transport_(176)%polar=  0.000
transport_(176)%collision=  1.000
transport_(176)%MW= 77.060
 
transport_(177)%nome='IC16-QOOH'
transport_(177)%geometry=2
transport_(177)%LJpotential=750.000
transport_(177)%LJdiameter=  8.350
transport_(177)%dipole=  0.000
transport_(177)%polar=  0.000
transport_(177)%collision=  1.000
transport_(177)%MW=257.437
 
transport_(178)%nome='IC16T-QOOH'
transport_(178)%geometry=2
transport_(178)%LJpotential=750.000
transport_(178)%LJdiameter=  8.350
transport_(178)%dipole=  0.000
transport_(178)%polar=  0.000
transport_(178)%collision=  1.000
transport_(178)%MW=257.437
 
transport_(179)%nome='IC8-QOOH'
transport_(179)%geometry=2
transport_(179)%LJpotential=594.000
transport_(179)%LJdiameter=  6.170
transport_(179)%dipole=  0.000
transport_(179)%polar=  0.000
transport_(179)%collision=  1.000
transport_(179)%MW=145.222
 
transport_(180)%nome='IC4P-QOOH'
transport_(180)%geometry=2
transport_(180)%LJpotential=496.000
transport_(180)%LJdiameter=  5.200
transport_(180)%dipole=  0.000
transport_(180)%polar=  0.000
transport_(180)%collision=  1.000
transport_(180)%MW= 89.114
 
transport_(181)%nome='IC4T-QOOH'
transport_(181)%geometry=2
transport_(181)%LJpotential=496.000
transport_(181)%LJdiameter=  5.200
transport_(181)%dipole=  0.000
transport_(181)%polar=  0.000
transport_(181)%collision=  1.000
transport_(181)%MW= 89.114
 
transport_(182)%nome='MCYC6-QOOH'
transport_(182)%geometry=2
transport_(182)%LJpotential=595.300
transport_(182)%LJdiameter=  5.680
transport_(182)%dipole=  0.430
transport_(182)%polar= 12.300
transport_(182)%collision=  1.000
transport_(182)%MW=129.179
 
transport_(183)%nome='MTBE-QOOH'
transport_(183)%geometry=2
transport_(183)%LJpotential=492.000
transport_(183)%LJdiameter=  5.640
transport_(183)%dipole=  0.000
transport_(183)%polar=  0.000
transport_(183)%collision=  1.000
transport_(183)%MW=119.141
 
transport_(184)%nome='NEOC5-QOOH'
transport_(184)%geometry=2
transport_(184)%LJpotential=492.000
transport_(184)%LJdiameter=  5.640
transport_(184)%dipole=  0.000
transport_(184)%polar=  0.000
transport_(184)%collision=  1.000
transport_(184)%MW=103.141
 
transport_(185)%nome='IC8T-QOOH'
transport_(185)%geometry=2
transport_(185)%LJpotential=594.000
transport_(185)%LJdiameter=  6.170
transport_(185)%dipole=  0.000
transport_(185)%polar=  0.000
transport_(185)%collision=  1.000
transport_(185)%MW=145.222
 
transport_(186)%nome='MCYC6T-QOOH'
transport_(186)%geometry=2
transport_(186)%LJpotential=595.300
transport_(186)%LJdiameter=  5.680
transport_(186)%dipole=  0.430
transport_(186)%polar= 12.300
transport_(186)%collision=  1.000
transport_(186)%MW=129.179
 
transport_(187)%nome='NC10H21'
transport_(187)%geometry=2
transport_(187)%LJpotential=540.980
transport_(187)%LJdiameter=  7.150
transport_(187)%dipole=  0.000
transport_(187)%polar=  0.000
transport_(187)%collision=  1.000
transport_(187)%MW=141.277
 
transport_(188)%nome='NC10H21-OO'
transport_(188)%geometry=2
transport_(188)%LJpotential=640.980
transport_(188)%LJdiameter=  7.150
transport_(188)%dipole=  0.000
transport_(188)%polar=  0.000
transport_(188)%collision=  1.000
transport_(188)%MW=173.276
 
transport_(189)%nome='NC12H25'
transport_(189)%geometry=2
transport_(189)%LJpotential=580.000
transport_(189)%LJdiameter=  7.600
transport_(189)%dipole=  0.000
transport_(189)%polar=  0.000
transport_(189)%collision=  1.000
transport_(189)%MW=169.331
 
transport_(190)%nome='NC12H25-OO'
transport_(190)%geometry=2
transport_(190)%LJpotential=680.000
transport_(190)%LJdiameter=  7.600
transport_(190)%dipole=  0.000
transport_(190)%polar=  0.000
transport_(190)%collision=  1.000
transport_(190)%MW=201.329
 
transport_(191)%nome='C2H4OH'
transport_(191)%geometry=2
transport_(191)%LJpotential=362.600
transport_(191)%LJdiameter=  4.530
transport_(191)%dipole=  0.000
transport_(191)%polar=  0.000
transport_(191)%collision=  1.500
transport_(191)%MW= 45.061
 
transport_(192)%nome='CH2CHO'
transport_(192)%geometry=2
transport_(192)%LJpotential=436.000
transport_(192)%LJdiameter=  3.970
transport_(192)%dipole=  0.000
transport_(192)%polar=  0.000
transport_(192)%collision=  2.000
transport_(192)%MW= 43.045
 
transport_(193)%nome='CH3CHOH'
transport_(193)%geometry=2
transport_(193)%LJpotential=362.600
transport_(193)%LJdiameter=  4.530
transport_(193)%dipole=  0.000
transport_(193)%polar=  0.000
transport_(193)%collision=  1.500
transport_(193)%MW= 45.061
 
transport_(194)%nome='NC4H9-OO'
transport_(194)%geometry=2
transport_(194)%LJpotential=496.000
transport_(194)%LJdiameter=  5.200
transport_(194)%dipole=  0.000
transport_(194)%polar=  0.000
transport_(194)%collision=  1.000
transport_(194)%MW= 89.114
 
transport_(195)%nome='NC5H11'
transport_(195)%geometry=2
transport_(195)%LJpotential=392.000
transport_(195)%LJdiameter=  5.640
transport_(195)%dipole=  0.000
transport_(195)%polar=  0.000
transport_(195)%collision=  1.000
transport_(195)%MW= 71.142
 
transport_(196)%nome='NC5H12OO'
transport_(196)%geometry=2
transport_(196)%LJpotential=492.000
transport_(196)%LJdiameter=  5.640
transport_(196)%dipole=  0.000
transport_(196)%polar=  0.000
transport_(196)%collision=  1.000
transport_(196)%MW=103.141
 
transport_(197)%nome='NC7H15'
transport_(197)%geometry=2
transport_(197)%LJpotential=459.980
transport_(197)%LJdiameter=  6.310
transport_(197)%dipole=  0.000
transport_(197)%polar=  0.000
transport_(197)%collision=  1.000
transport_(197)%MW= 99.196
 
transport_(198)%nome='NC7H15-OO'
transport_(198)%geometry=2
transport_(198)%LJpotential=559.980
transport_(198)%LJdiameter=  6.310
transport_(198)%dipole=  0.000
transport_(198)%polar=  0.000
transport_(198)%collision=  1.000
transport_(198)%MW=131.195
 
transport_(199)%nome='C12H7'
transport_(199)%geometry=2
transport_(199)%LJpotential=693.100
transport_(199)%LJdiameter=  6.470
transport_(199)%dipole=  0.000
transport_(199)%polar= 18.000
transport_(199)%collision=  1.000
transport_(199)%MW=151.188
 
transport_(200)%nome='CH3COCH2'
transport_(200)%geometry=2
transport_(200)%LJpotential=424.600
transport_(200)%LJdiameter=  4.820
transport_(200)%dipole=  0.000
transport_(200)%polar=  0.000
transport_(200)%collision=  1.000
transport_(200)%MW= 57.072
 
transport_(201)%nome='C2H4CHO'
transport_(201)%geometry=2
transport_(201)%LJpotential=424.600
transport_(201)%LJdiameter=  4.820
transport_(201)%dipole=  0.000
transport_(201)%polar=  0.000
transport_(201)%collision=  1.000
transport_(201)%MW= 57.072
 
transport_(202)%nome='CYC6-OO'
transport_(202)%geometry=2
transport_(202)%LJpotential=568.500
transport_(202)%LJdiameter=  5.230
transport_(202)%dipole=  0.000
transport_(202)%polar= 10.300
transport_(202)%collision=  1.000
transport_(202)%MW=115.152
 
transport_(203)%nome='CYC6H11'
transport_(203)%geometry=2
transport_(203)%LJpotential=468.500
transport_(203)%LJdiameter=  5.230
transport_(203)%dipole=  0.000
transport_(203)%polar= 10.300
transport_(203)%collision=  1.000
transport_(203)%MW= 83.153
 
transport_(204)%nome='CYC6H9'
transport_(204)%geometry=2
transport_(204)%LJpotential=468.500
transport_(204)%LJdiameter=  5.230
transport_(204)%dipole=  0.000
transport_(204)%polar= 10.300
transport_(204)%collision=  1.000
transport_(204)%MW= 81.137
 
transport_(205)%nome='CYC5H5'
transport_(205)%geometry=2
transport_(205)%LJpotential=408.000
transport_(205)%LJdiameter=  5.200
transport_(205)%dipole=  0.000
transport_(205)%polar=  0.000
transport_(205)%collision=  1.000
transport_(205)%MW= 65.095
 
transport_(206)%nome='RDIPE'
transport_(206)%geometry=2
transport_(206)%LJpotential=432.000
transport_(206)%LJdiameter=  6.000
transport_(206)%dipole=  0.000
transport_(206)%polar=  0.000
transport_(206)%collision=  1.000
transport_(206)%MW=101.169
 
transport_(207)%nome='CH3OCH2'
transport_(207)%geometry=2
transport_(207)%LJpotential=303.400
transport_(207)%LJdiameter=  4.810
transport_(207)%dipole=  0.000
transport_(207)%polar=  0.000
transport_(207)%collision=  1.000
transport_(207)%MW= 45.061
 
transport_(208)%nome='DME-OO'
transport_(208)%geometry=2
transport_(208)%LJpotential=403.400
transport_(208)%LJdiameter=  4.810
transport_(208)%dipole=  0.000
transport_(208)%polar=  0.000
transport_(208)%collision=  1.000
transport_(208)%MW= 77.060
 
transport_(209)%nome='C6H4C2H'
transport_(209)%geometry=2
transport_(209)%LJpotential=535.600
transport_(209)%LJdiameter=  5.720
transport_(209)%dipole=  0.770
transport_(209)%polar= 12.000
transport_(209)%collision=  1.000
transport_(209)%MW=101.128
 
transport_(210)%nome='RBIPHENYL'
transport_(210)%geometry=2
transport_(210)%LJpotential=676.500
transport_(210)%LJdiameter=  6.310
transport_(210)%dipole=  0.000
transport_(210)%polar=  0.000
transport_(210)%collision=  1.000
transport_(210)%MW=153.203
 
transport_(211)%nome='C14H9'
transport_(211)%geometry=2
transport_(211)%LJpotential=772.000
transport_(211)%LJdiameter=  6.960
transport_(211)%dipole=  0.000
transport_(211)%polar= 38.800
transport_(211)%collision=  1.000
transport_(211)%MW=177.225
 
transport_(212)%nome='C10H7'
transport_(212)%geometry=2
transport_(212)%LJpotential=630.400
transport_(212)%LJdiameter=  6.180
transport_(212)%dipole=  0.000
transport_(212)%polar= 16.500
transport_(212)%collision=  1.000
transport_(212)%MW=127.166
 
transport_(213)%nome='IC16H33-OO'
transport_(213)%geometry=2
transport_(213)%LJpotential=750.000
transport_(213)%LJdiameter=  8.350
transport_(213)%dipole=  0.000
transport_(213)%polar=  0.000
transport_(213)%collision=  1.000
transport_(213)%MW=257.437
 
transport_(214)%nome='IC16H33'
transport_(214)%geometry=2
transport_(214)%LJpotential=650.000
transport_(214)%LJdiameter=  8.350
transport_(214)%dipole=  0.000
transport_(214)%polar=  0.000
transport_(214)%collision=  1.000
transport_(214)%MW=225.438
 
transport_(215)%nome='IC8H17'
transport_(215)%geometry=2
transport_(215)%LJpotential=494.000
transport_(215)%LJdiameter=  6.170
transport_(215)%dipole=  0.000
transport_(215)%polar=  0.000
transport_(215)%collision=  1.000
transport_(215)%MW=113.223
 
transport_(216)%nome='IC8H17-OO'
transport_(216)%geometry=2
transport_(216)%LJpotential=594.000
transport_(216)%LJdiameter=  6.170
transport_(216)%dipole=  0.000
transport_(216)%polar=  0.000
transport_(216)%collision=  1.000
transport_(216)%MW=145.222
 
transport_(217)%nome='INDENYL'
transport_(217)%geometry=2
transport_(217)%LJpotential=588.600
transport_(217)%LJdiameter=  5.960
transport_(217)%dipole=  0.000
transport_(217)%polar=  0.000
transport_(217)%collision=  1.000
transport_(217)%MW=115.155
 
transport_(218)%nome='RMCYC6-OO'
transport_(218)%geometry=2
transport_(218)%LJpotential=595.300
transport_(218)%LJdiameter=  5.680
transport_(218)%dipole=  0.430
transport_(218)%polar= 12.300
transport_(218)%collision=  1.000
transport_(218)%MW=129.179
 
transport_(219)%nome='RMCYC6'
transport_(219)%geometry=2
transport_(219)%LJpotential=495.300
transport_(219)%LJdiameter=  5.680
transport_(219)%dipole=  0.430
transport_(219)%polar= 12.300
transport_(219)%collision=  1.000
transport_(219)%MW= 97.180
 
transport_(220)%nome='C10H7CH2'
transport_(220)%geometry=2
transport_(220)%LJpotential=660.000
transport_(220)%LJdiameter=  6.350
transport_(220)%dipole=  0.000
transport_(220)%polar=  0.000
transport_(220)%collision=  1.000
transport_(220)%MW=141.192
 
transport_(221)%nome='C10H6CH3'
transport_(221)%geometry=2
transport_(221)%LJpotential=660.000
transport_(221)%LJdiameter=  6.350
transport_(221)%dipole=  0.000
transport_(221)%polar=  0.000
transport_(221)%collision=  1.000
transport_(221)%MW=141.192
 
transport_(222)%nome='C6H4CH3'
transport_(222)%geometry=2
transport_(222)%LJpotential=495.300
transport_(222)%LJdiameter=  5.680
transport_(222)%dipole=  0.000
transport_(222)%polar=  0.000
transport_(222)%collision=  1.000
transport_(222)%MW= 91.133
 
transport_(223)%nome='RMTBE'
transport_(223)%geometry=2
transport_(223)%LJpotential=392.000
transport_(223)%LJdiameter=  5.640
transport_(223)%dipole=  0.000
transport_(223)%polar=  0.000
transport_(223)%collision=  1.000
transport_(223)%MW= 87.142
 
transport_(224)%nome='MTBE-OO'
transport_(224)%geometry=2
transport_(224)%LJpotential=492.000
transport_(224)%LJdiameter=  5.640
transport_(224)%dipole=  0.000
transport_(224)%polar=  0.000
transport_(224)%collision=  1.000
transport_(224)%MW=119.141
 
transport_(225)%nome='C10H7O'
transport_(225)%geometry=2
transport_(225)%LJpotential=630.400
transport_(225)%LJdiameter=  6.180
transport_(225)%dipole=  0.000
transport_(225)%polar=  0.000
transport_(225)%collision=  1.000
transport_(225)%MW=143.165
 
transport_(226)%nome='NEOC5H11'
transport_(226)%geometry=2
transport_(226)%LJpotential=392.000
transport_(226)%LJdiameter=  5.640
transport_(226)%dipole=  0.000
transport_(226)%polar=  0.000
transport_(226)%collision=  1.000
transport_(226)%MW= 71.142
 
transport_(227)%nome='NEOC5H11-OO'
transport_(227)%geometry=2
transport_(227)%LJpotential=492.000
transport_(227)%LJdiameter=  5.640
transport_(227)%dipole=  0.000
transport_(227)%polar=  0.000
transport_(227)%collision=  1.000
transport_(227)%MW=103.141
 
transport_(228)%nome='C16H9'
transport_(228)%geometry=2
transport_(228)%LJpotential=834.900
transport_(228)%LJdiameter=  7.240
transport_(228)%dipole=  0.000
transport_(228)%polar= 45.000
transport_(228)%collision=  1.000
transport_(228)%MW=201.247
 
transport_(229)%nome='C6H5C2H2'
transport_(229)%geometry=2
transport_(229)%LJpotential=546.200
transport_(229)%LJdiameter=  6.000
transport_(229)%dipole=  0.000
transport_(229)%polar=  0.000
transport_(229)%collision=  1.000
transport_(229)%MW=103.144
 
transport_(230)%nome='RXYLENE'
transport_(230)%geometry=2
transport_(230)%LJpotential=523.600
transport_(230)%LJdiameter=  5.960
transport_(230)%dipole=  0.000
transport_(230)%polar=  0.000
transport_(230)%collision=  1.000
transport_(230)%MW=105.159
 
transport_(231)%nome='C6H5C2H3'
transport_(231)%geometry=2
transport_(231)%LJpotential=546.200
transport_(231)%LJdiameter=  6.000
transport_(231)%dipole=  0.130
transport_(231)%polar= 15.000
transport_(231)%collision=  1.000
transport_(231)%MW=104.152
 
transport_(232)%nome='TAME'
transport_(232)%geometry=2
transport_(232)%LJpotential=432.000
transport_(232)%LJdiameter=  6.000
transport_(232)%dipole=  0.000
transport_(232)%polar=  0.000
transport_(232)%collision=  1.000
transport_(232)%MW=102.177
 
transport_(233)%nome='TETRALIN'
transport_(233)%geometry=2
transport_(233)%LJpotential=630.400
transport_(233)%LJdiameter=  6.180
transport_(233)%dipole=  0.000
transport_(233)%polar= 16.500
transport_(233)%collision=  1.000
transport_(233)%MW=132.205
 
transport_(234)%nome='DECALIN'
transport_(234)%geometry=2
transport_(234)%LJpotential=630.400
transport_(234)%LJdiameter=  6.180
transport_(234)%dipole=  0.000
transport_(234)%polar= 16.500
transport_(234)%collision=  1.000
transport_(234)%MW=138.253
 
transport_(235)%nome='RDECALIN'
transport_(235)%geometry=2
transport_(235)%LJpotential=630.400
transport_(235)%LJdiameter=  6.180
transport_(235)%dipole=  0.000
transport_(235)%polar= 16.500
transport_(235)%collision=  1.000
transport_(235)%MW=137.245
 
transport_(236)%nome='C7H8'
transport_(236)%geometry=2
transport_(236)%LJpotential=495.300
transport_(236)%LJdiameter=  5.680
transport_(236)%dipole=  0.430
transport_(236)%polar= 12.300
transport_(236)%collision=  1.000
transport_(236)%MW= 92.141
 
transport_(237)%nome='C2H3'
transport_(237)%geometry=2
transport_(237)%LJpotential=209.000
transport_(237)%LJdiameter=  4.100
transport_(237)%dipole=  0.000
transport_(237)%polar=  0.000
transport_(237)%collision=  1.000
transport_(237)%MW= 27.046
 
transport_(238)%nome='XYLENE'
transport_(238)%geometry=2
transport_(238)%LJpotential=523.600
transport_(238)%LJdiameter=  5.960
transport_(238)%dipole=  0.000
transport_(238)%polar=  0.000
transport_(238)%collision=  1.000
transport_(238)%MW=106.167
 
transport_(239)%nome='NC10-OOQOOH'
transport_(239)%geometry=2
transport_(239)%LJpotential=640.980
transport_(239)%LJdiameter=  7.150
transport_(239)%dipole=  0.000
transport_(239)%polar=  0.000
transport_(239)%collision=  1.000
transport_(239)%MW=205.274
 
transport_(240)%nome='NC12-OOQOOH'
transport_(240)%geometry=2
transport_(240)%LJpotential=680.000
transport_(240)%LJdiameter=  7.600
transport_(240)%dipole=  0.000
transport_(240)%polar=  0.000
transport_(240)%collision=  1.000
transport_(240)%MW=233.328
 
transport_(241)%nome='NC4-OOQOOH'
transport_(241)%geometry=2
transport_(241)%LJpotential=496.000
transport_(241)%LJdiameter=  5.200
transport_(241)%dipole=  0.000
transport_(241)%polar=  0.000
transport_(241)%collision=  1.000
transport_(241)%MW=121.113
 
transport_(242)%nome='NC5-OOQOOH'
transport_(242)%geometry=2
transport_(242)%LJpotential=492.000
transport_(242)%LJdiameter=  5.640
transport_(242)%dipole=  0.000
transport_(242)%polar=  0.000
transport_(242)%collision=  1.000
transport_(242)%MW=135.140
 
transport_(243)%nome='NC7-OOQOOH'
transport_(243)%geometry=2
transport_(243)%LJpotential=559.980
transport_(243)%LJdiameter=  6.310
transport_(243)%dipole=  0.000
transport_(243)%polar=  0.000
transport_(243)%collision=  1.000
transport_(243)%MW=163.194
 
transport_(244)%nome='DME-OOQOOH'
transport_(244)%geometry=2
transport_(244)%LJpotential=403.400
transport_(244)%LJdiameter=  4.810
transport_(244)%dipole=  0.000
transport_(244)%polar=  0.000
transport_(244)%collision=  1.000
transport_(244)%MW=109.059
 
transport_(245)%nome='IC16-OOQOOH'
transport_(245)%geometry=2
transport_(245)%LJpotential=750.000
transport_(245)%LJdiameter=  8.350
transport_(245)%dipole=  0.000
transport_(245)%polar=  0.000
transport_(245)%collision=  1.000
transport_(245)%MW=289.436
 
transport_(246)%nome='IC16T-OOQOOH'
transport_(246)%geometry=2
transport_(246)%LJpotential=750.000
transport_(246)%LJdiameter=  8.350
transport_(246)%dipole=  0.000
transport_(246)%polar=  0.000
transport_(246)%collision=  1.000
transport_(246)%MW=289.436
 
transport_(247)%nome='IC8-OOQOOH'
transport_(247)%geometry=2
transport_(247)%LJpotential=594.000
transport_(247)%LJdiameter=  6.170
transport_(247)%dipole=  0.000
transport_(247)%polar=  0.000
transport_(247)%collision=  1.000
transport_(247)%MW=177.221
 
transport_(248)%nome='IC4P-OOQOOH'
transport_(248)%geometry=2
transport_(248)%LJpotential=496.000
transport_(248)%LJdiameter=  5.200
transport_(248)%dipole=  0.000
transport_(248)%polar=  0.000
transport_(248)%collision=  1.000
transport_(248)%MW=121.113
 
transport_(249)%nome='IC4T-OOQOOH'
transport_(249)%geometry=2
transport_(249)%LJpotential=496.000
transport_(249)%LJdiameter=  5.200
transport_(249)%dipole=  0.000
transport_(249)%polar=  0.000
transport_(249)%collision=  1.000
transport_(249)%MW=121.113
 
transport_(250)%nome='MCYC6-OOQOOH'
transport_(250)%geometry=2
transport_(250)%LJpotential=595.300
transport_(250)%LJdiameter=  5.680
transport_(250)%dipole=  0.430
transport_(250)%polar= 12.300
transport_(250)%collision=  1.000
transport_(250)%MW=161.178
 
transport_(251)%nome='MTBE-OOQOOH'
transport_(251)%geometry=2
transport_(251)%LJpotential=492.000
transport_(251)%LJdiameter=  5.640
transport_(251)%dipole=  0.000
transport_(251)%polar=  0.000
transport_(251)%collision=  1.000
transport_(251)%MW=151.139
 
transport_(252)%nome='NEOC5-OOQOOH'
transport_(252)%geometry=2
transport_(252)%LJpotential=492.000
transport_(252)%LJdiameter=  5.640
transport_(252)%dipole=  0.000
transport_(252)%polar=  0.000
transport_(252)%collision=  1.000
transport_(252)%MW=135.140
 
transport_(253)%nome='MCYC6T-OOQOOH'
transport_(253)%geometry=2
transport_(253)%LJpotential=595.300
transport_(253)%LJdiameter=  5.680
transport_(253)%dipole=  0.430
transport_(253)%polar= 12.300
transport_(253)%collision=  1.000
transport_(253)%MW=161.178
 
transport_(254)%nome='NC16H34'
transport_(254)%geometry=2
transport_(254)%LJpotential=650.000
transport_(254)%LJdiameter=  8.350
transport_(254)%dipole=  0.000
transport_(254)%polar=  0.000
transport_(254)%collision=  1.000
transport_(254)%MW=226.446
 
transport_(255)%nome='NC16H33'
transport_(255)%geometry=2
transport_(255)%LJpotential=650.000
transport_(255)%LJdiameter=  8.350
transport_(255)%dipole=  0.000
transport_(255)%polar=  0.000
transport_(255)%collision=  1.000
transport_(255)%MW=225.438
 
transport_(256)%nome='NC16H33-OO'
transport_(256)%geometry=2
transport_(256)%LJpotential=750.000
transport_(256)%LJdiameter=  8.350
transport_(256)%dipole=  0.000
transport_(256)%polar=  0.000
transport_(256)%collision=  1.000
transport_(256)%MW=257.437
 
transport_(257)%nome='NC16-QOOH'
transport_(257)%geometry=2
transport_(257)%LJpotential=750.000
transport_(257)%LJdiameter=  8.350
transport_(257)%dipole=  0.000
transport_(257)%polar=  0.000
transport_(257)%collision=  1.000
transport_(257)%MW=257.437
 
transport_(258)%nome='NC16-OOQOOH'
transport_(258)%geometry=2
transport_(258)%LJpotential=750.000
transport_(258)%LJdiameter=  8.350
transport_(258)%dipole=  0.000
transport_(258)%polar=  0.000
transport_(258)%collision=  1.000
transport_(258)%MW=289.436
 
transport_(259)%nome='NC16-OQOOH'
transport_(259)%geometry=2
transport_(259)%LJpotential=750.000
transport_(259)%LJdiameter=  8.350
transport_(259)%dipole=  0.000
transport_(259)%polar=  0.000
transport_(259)%collision=  1.000
transport_(259)%MW=272.428
 
transport_(260)%nome='CN'
transport_(260)%geometry=1
transport_(260)%LJpotential= 75.000
transport_(260)%LJdiameter=  3.856
transport_(260)%dipole=  0.000
transport_(260)%polar=  0.000
transport_(260)%collision=  1.000
transport_(260)%MW= 26.018
 
transport_(261)%nome='H2CN'
transport_(261)%geometry=1
transport_(261)%LJpotential=569.000
transport_(261)%LJdiameter=  3.630
transport_(261)%dipole=  0.000
transport_(261)%polar=  0.000
transport_(261)%collision=  1.000
transport_(261)%MW= 28.034
 
transport_(262)%nome='H2NO'
transport_(262)%geometry=2
transport_(262)%LJpotential=116.700
transport_(262)%LJdiameter=  3.492
transport_(262)%dipole=  0.000
transport_(262)%polar=  0.000
transport_(262)%collision=  1.000
transport_(262)%MW= 32.022
 
transport_(263)%nome='HCN'
transport_(263)%geometry=1
transport_(263)%LJpotential=569.000
transport_(263)%LJdiameter=  3.630
transport_(263)%dipole=  0.000
transport_(263)%polar=  0.000
transport_(263)%collision=  1.000
transport_(263)%MW= 27.026
 
transport_(264)%nome='HCNO'
transport_(264)%geometry=2
transport_(264)%LJpotential=232.400
transport_(264)%LJdiameter=  3.828
transport_(264)%dipole=  0.000
transport_(264)%polar=  0.000
transport_(264)%collision=  1.000
transport_(264)%MW= 43.025
 
transport_(265)%nome='HOCN'
transport_(265)%geometry=2
transport_(265)%LJpotential=232.400
transport_(265)%LJdiameter=  3.828
transport_(265)%dipole=  0.000
transport_(265)%polar=  0.000
transport_(265)%collision=  1.000
transport_(265)%MW= 43.025
 
transport_(266)%nome='HNCO'
transport_(266)%geometry=2
transport_(266)%LJpotential=232.400
transport_(266)%LJdiameter=  3.828
transport_(266)%dipole=  0.000
transport_(266)%polar=  0.000
transport_(266)%collision=  1.000
transport_(266)%MW= 43.025
 
transport_(267)%nome='HNNO'
transport_(267)%geometry=2
transport_(267)%LJpotential=232.400
transport_(267)%LJdiameter=  3.828
transport_(267)%dipole=  0.000
transport_(267)%polar=  0.000
transport_(267)%collision=  1.000
transport_(267)%MW= 45.021
 
transport_(268)%nome='HNO'
transport_(268)%geometry=2
transport_(268)%LJpotential=116.700
transport_(268)%LJdiameter=  3.492
transport_(268)%dipole=  0.000
transport_(268)%polar=  0.000
transport_(268)%collision=  1.000
transport_(268)%MW= 31.014
 
transport_(269)%nome='N'
transport_(269)%geometry=0
transport_(269)%LJpotential= 71.400
transport_(269)%LJdiameter=  3.298
transport_(269)%dipole=  0.000
transport_(269)%polar=  0.000
transport_(269)%collision=  0.000
transport_(269)%MW= 14.007
 
transport_(270)%nome='N2H2'
transport_(270)%geometry=2
transport_(270)%LJpotential= 71.400
transport_(270)%LJdiameter=  3.798
transport_(270)%dipole=  0.000
transport_(270)%polar=  0.000
transport_(270)%collision=  1.000
transport_(270)%MW= 30.029
 
transport_(271)%nome='N2H3'
transport_(271)%geometry=2
transport_(271)%LJpotential=200.000
transport_(271)%LJdiameter=  3.900
transport_(271)%dipole=  0.000
transport_(271)%polar=  0.000
transport_(271)%collision=  1.000
transport_(271)%MW= 31.037
 
transport_(272)%nome='N2H4'
transport_(272)%geometry=2
transport_(272)%LJpotential=205.000
transport_(272)%LJdiameter=  4.230
transport_(272)%dipole=  0.000
transport_(272)%polar=  4.260
transport_(272)%collision=  1.500
transport_(272)%MW= 32.045
 
transport_(273)%nome='N2O'
transport_(273)%geometry=1
transport_(273)%LJpotential=232.400
transport_(273)%LJdiameter=  3.828
transport_(273)%dipole=  0.000
transport_(273)%polar=  0.000
transport_(273)%collision=  1.000
transport_(273)%MW= 44.013
 
transport_(274)%nome='NCO'
transport_(274)%geometry=1
transport_(274)%LJpotential=232.400
transport_(274)%LJdiameter=  3.828
transport_(274)%dipole=  0.000
transport_(274)%polar=  0.000
transport_(274)%collision=  1.000
transport_(274)%MW= 42.017
 
transport_(275)%nome='NH'
transport_(275)%geometry=1
transport_(275)%LJpotential= 80.000
transport_(275)%LJdiameter=  2.650
transport_(275)%dipole=  0.000
transport_(275)%polar=  0.000
transport_(275)%collision=  4.000
transport_(275)%MW= 15.015
 
transport_(276)%nome='NH2'
transport_(276)%geometry=2
transport_(276)%LJpotential= 80.000
transport_(276)%LJdiameter=  2.650
transport_(276)%dipole=  0.000
transport_(276)%polar=  2.260
transport_(276)%collision=  4.000
transport_(276)%MW= 16.023
 
transport_(277)%nome='NH3'
transport_(277)%geometry=2
transport_(277)%LJpotential=481.000
transport_(277)%LJdiameter=  2.920
transport_(277)%dipole=  1.470
transport_(277)%polar=  0.000
transport_(277)%collision= 10.000
transport_(277)%MW= 17.031
 
transport_(278)%nome='NNH'
transport_(278)%geometry=2
transport_(278)%LJpotential= 71.400
transport_(278)%LJdiameter=  3.798
transport_(278)%dipole=  0.000
transport_(278)%polar=  0.000
transport_(278)%collision=  1.000
transport_(278)%MW= 29.021
 
transport_(279)%nome='NO'
transport_(279)%geometry=1
transport_(279)%LJpotential= 97.500
transport_(279)%LJdiameter=  3.621
transport_(279)%dipole=  0.000
transport_(279)%polar=  1.760
transport_(279)%collision=  4.000
transport_(279)%MW= 30.006
 
transport_(280)%nome='NO2'
transport_(280)%geometry=2
transport_(280)%LJpotential=200.000
transport_(280)%LJdiameter=  3.500
transport_(280)%dipole=  0.000
transport_(280)%polar=  0.000
transport_(280)%collision=  1.000
transport_(280)%MW= 46.006
 
transport_(281)%nome='HONO'
transport_(281)%geometry=2
transport_(281)%LJpotential=200.000
transport_(281)%LJdiameter=  3.500
transport_(281)%dipole=  0.000
transport_(281)%polar=  0.000
transport_(281)%collision=  1.000
transport_(281)%MW= 47.014
 
transport_(282)%nome='HNO2'
transport_(282)%geometry=2
transport_(282)%LJpotential=200.000
transport_(282)%LJdiameter=  3.500
transport_(282)%dipole=  0.000
transport_(282)%polar=  0.000
transport_(282)%collision=  1.000
transport_(282)%MW= 47.014
 
transport_(283)%nome='NO3'
transport_(283)%geometry=2
transport_(283)%LJpotential=300.000
transport_(283)%LJdiameter=  3.500
transport_(283)%dipole=  0.000
transport_(283)%polar=  0.000
transport_(283)%collision=  1.000
transport_(283)%MW= 62.005
 
transport_(284)%nome='HONO2'
transport_(284)%geometry=2
transport_(284)%LJpotential=300.000
transport_(284)%LJdiameter=  3.500
transport_(284)%dipole=  0.000
transport_(284)%polar=  0.000
transport_(284)%collision=  1.000
transport_(284)%MW= 63.013
 
transport_(285)%nome='CH3CN'
transport_(285)%geometry=1
transport_(285)%LJpotential=500.000
transport_(285)%LJdiameter=  4.630
transport_(285)%dipole=  0.000
transport_(285)%polar=  0.000
transport_(285)%collision=  1.000
transport_(285)%MW= 41.053
 
transport_(286)%nome='CH3NO2'
transport_(286)%geometry=2
transport_(286)%LJpotential=200.000
transport_(286)%LJdiameter=  4.500
transport_(286)%dipole=  0.000
transport_(286)%polar=  0.000
transport_(286)%collision=  1.000
transport_(286)%MW= 61.040
 
transport_(287)%nome='CH3ONO'
transport_(287)%geometry=2
transport_(287)%LJpotential=200.000
transport_(287)%LJdiameter=  4.500
transport_(287)%dipole=  0.000
transport_(287)%polar=  0.000
transport_(287)%collision=  1.000
transport_(287)%MW= 61.040
 
transport_(288)%nome='CH3NO'
transport_(288)%geometry=1
transport_(288)%LJpotential= 97.500
transport_(288)%LJdiameter=  3.621
transport_(288)%dipole=  0.000
transport_(288)%polar=  1.760
transport_(288)%collision=  4.000
transport_(288)%MW= 45.041
 
transport_(289)%nome='CH3ONO2'
transport_(289)%geometry=2
transport_(289)%LJpotential=300.000
transport_(289)%LJdiameter=  4.500
transport_(289)%dipole=  0.000
transport_(289)%polar=  0.000
transport_(289)%collision=  1.000
transport_(289)%MW= 77.040
 
transport_(290)%nome='CH2CN'
transport_(290)%geometry=1
transport_(290)%LJpotential=232.400
transport_(290)%LJdiameter=  3.828
transport_(290)%dipole=  0.000
transport_(290)%polar=  0.000
transport_(290)%collision=  1.000
transport_(290)%MW= 40.045
 
transport_(291)%nome='BIN1A'
transport_(291)%geometry=2
transport_(291)%LJpotential=951.685
transport_(291)%LJdiameter=  8.471
transport_(291)%dipole=  0.000
transport_(291)%polar=  0.000
transport_(291)%collision=  1.000
transport_(291)%MW=256.347
 
transport_(292)%nome='BIN1B'
transport_(292)%geometry=2
transport_(292)%LJpotential=951.685
transport_(292)%LJdiameter=  8.471
transport_(292)%dipole=  0.000
transport_(292)%polar=  0.000
transport_(292)%collision=  1.000
transport_(292)%MW=250.299
 
transport_(293)%nome='CYC6-QOOH-2'
transport_(293)%geometry=2
transport_(293)%LJpotential=568.500
transport_(293)%LJdiameter=  5.230
transport_(293)%dipole=  0.000
transport_(293)%polar= 10.300
transport_(293)%collision=  1.000
transport_(293)%MW=115.152
 
transport_(294)%nome='CYC6-QOOH-3'
transport_(294)%geometry=2
transport_(294)%LJpotential=568.500
transport_(294)%LJdiameter=  5.230
transport_(294)%dipole=  0.000
transport_(294)%polar= 10.300
transport_(294)%collision=  1.000
transport_(294)%MW=115.152
 
transport_(295)%nome='CYC6-QOOH-4'
transport_(295)%geometry=2
transport_(295)%LJpotential=568.500
transport_(295)%LJdiameter=  5.230
transport_(295)%dipole=  0.000
transport_(295)%polar= 10.300
transport_(295)%collision=  1.000
transport_(295)%MW=115.152
 
transport_(296)%nome='CYC6-OOQOOH-2'
transport_(296)%geometry=2
transport_(296)%LJpotential=568.500
transport_(296)%LJdiameter=  5.230
transport_(296)%dipole=  0.000
transport_(296)%polar= 10.300
transport_(296)%collision=  1.000
transport_(296)%MW=147.151
 
transport_(297)%nome='CYC6-OOQOOH-3'
transport_(297)%geometry=2
transport_(297)%LJpotential=568.500
transport_(297)%LJdiameter=  5.230
transport_(297)%dipole=  0.000
transport_(297)%polar= 10.300
transport_(297)%collision=  1.000
transport_(297)%MW=147.151
 
transport_(298)%nome='CYC6-OOQOOH-4'
transport_(298)%geometry=2
transport_(298)%LJpotential=568.500
transport_(298)%LJdiameter=  5.230
transport_(298)%dipole=  0.000
transport_(298)%polar= 10.300
transport_(298)%collision=  1.000
transport_(298)%MW=147.151
 
transport_(299)%nome='CYC6-OQOOH-2'
transport_(299)%geometry=2
transport_(299)%LJpotential=568.500
transport_(299)%LJdiameter=  5.230
transport_(299)%dipole=  0.000
transport_(299)%polar= 10.300
transport_(299)%collision=  1.000
transport_(299)%MW=130.144
 
transport_(300)%nome='CYC6-OQOOH-3'
transport_(300)%geometry=2
transport_(300)%LJpotential=568.500
transport_(300)%LJdiameter=  5.230
transport_(300)%dipole=  0.000
transport_(300)%polar= 10.300
transport_(300)%collision=  1.000
transport_(300)%MW=130.144
 
transport_(301)%nome='CYC6-OQOOH-4'
transport_(301)%geometry=2
transport_(301)%LJpotential=568.500
transport_(301)%LJdiameter=  5.230
transport_(301)%dipole=  0.000
transport_(301)%polar= 10.300
transport_(301)%collision=  1.000
transport_(301)%MW=130.144
 
transport_(302)%nome='CYC6H10-O-12'
transport_(302)%geometry=2
transport_(302)%LJpotential=568.500
transport_(302)%LJdiameter=  5.230
transport_(302)%dipole=  0.000
transport_(302)%polar= 10.300
transport_(302)%collision=  1.000
transport_(302)%MW= 98.145
 
transport_(303)%nome='CYC6H10-O-13'
transport_(303)%geometry=2
transport_(303)%LJpotential=568.500
transport_(303)%LJdiameter=  5.230
transport_(303)%dipole=  0.000
transport_(303)%polar= 10.300
transport_(303)%collision=  1.000
transport_(303)%MW= 98.145
 
transport_(304)%nome='CYC6H10-O-14'
transport_(304)%geometry=2
transport_(304)%LJpotential=568.500
transport_(304)%LJdiameter=  5.230
transport_(304)%dipole=  0.000
transport_(304)%polar= 10.300
transport_(304)%collision=  1.000
transport_(304)%MW= 98.145
 
transport_(305)%nome='C3H5OOH'
transport_(305)%geometry=2
transport_(305)%LJpotential=407.800
transport_(305)%LJdiameter=  4.140
transport_(305)%dipole=  0.000
transport_(305)%polar=  0.000
transport_(305)%collision=  1.000
transport_(305)%MW= 74.079
 
transport_(306)%nome='C5EN-OQOOH-35'
transport_(306)%geometry=2
transport_(306)%LJpotential=508.000
transport_(306)%LJdiameter=  5.200
transport_(306)%dipole=  0.000
transport_(306)%polar=  0.000
transport_(306)%collision=  1.000
transport_(306)%MW=116.117
 
transport_(307)%nome='C5H8O'
transport_(307)%geometry=2
transport_(307)%LJpotential=508.000
transport_(307)%LJdiameter=  5.200
transport_(307)%dipole=  0.000
transport_(307)%polar=  0.000
transport_(307)%collision=  1.000
transport_(307)%MW= 84.118
 
transport_(308)%nome='NC5H9-3'
transport_(308)%geometry=2
transport_(308)%LJpotential=408.000
transport_(308)%LJdiameter=  5.200
transport_(308)%dipole=  0.000
transport_(308)%polar=  0.000
transport_(308)%collision=  1.000
transport_(308)%MW= 69.127
 
transport_(309)%nome='C3H5OO'
transport_(309)%geometry=2
transport_(309)%LJpotential=407.800
transport_(309)%LJdiameter=  4.140
transport_(309)%dipole=  0.000
transport_(309)%polar=  0.000
transport_(309)%collision=  1.000
transport_(309)%MW= 73.072
 
transport_(310)%nome='C5EN-OO'
transport_(310)%geometry=2
transport_(310)%LJpotential=508.000
transport_(310)%LJdiameter=  5.200
transport_(310)%dipole=  0.000
transport_(310)%polar=  0.000
transport_(310)%collision=  1.000
transport_(310)%MW=101.125
 
transport_(311)%nome='C5EN-QOOH'
transport_(311)%geometry=2
transport_(311)%LJpotential=508.000
transport_(311)%LJdiameter=  5.200
transport_(311)%dipole=  0.000
transport_(311)%polar=  0.000
transport_(311)%collision=  1.000
transport_(311)%MW=101.125
 
transport_(312)%nome='C5EN-OOQOOH-35'
transport_(312)%geometry=2
transport_(312)%LJpotential=508.000
transport_(312)%LJdiameter=  5.200
transport_(312)%dipole=  0.000
transport_(312)%polar=  0.000
transport_(312)%collision=  1.000
transport_(312)%MW=133.124
 
transport_(313)%nome='NC3H7OH'
transport_(313)%geometry=2
transport_(313)%LJpotential=482.147
transport_(313)%LJdiameter=  5.009
transport_(313)%dipole=  1.660
transport_(313)%polar=  6.740
transport_(313)%collision=  1.000
transport_(313)%MW= 60.096
 
transport_(314)%nome='N1C4H9OH'
transport_(314)%geometry=2
transport_(314)%LJpotential=503.072
transport_(314)%LJdiameter=  5.340
transport_(314)%dipole=  1.670
transport_(314)%polar=  8.880
transport_(314)%collision=  1.000
transport_(314)%MW= 74.123
 
transport_(315)%nome='N2C4H9OH'
transport_(315)%geometry=2
transport_(315)%LJpotential=503.072
transport_(315)%LJdiameter=  5.340
transport_(315)%dipole=  1.670
transport_(315)%polar=  8.880
transport_(315)%collision=  1.000
transport_(315)%MW= 74.123
 
transport_(316)%nome='CH3CH2CHOHCH2'
transport_(316)%geometry=2
transport_(316)%LJpotential=503.072
transport_(316)%LJdiameter=  5.340
transport_(316)%dipole=  1.670
transport_(316)%polar=  8.880
transport_(316)%collision=  1.000
transport_(316)%MW= 73.115
 
transport_(317)%nome='CH3CH2CHOCH3'
transport_(317)%geometry=2
transport_(317)%LJpotential=503.072
transport_(317)%LJdiameter=  5.340
transport_(317)%dipole=  1.670
transport_(317)%polar=  8.880
transport_(317)%collision=  1.000
transport_(317)%MW= 73.115
 
transport_(318)%nome='CH3CH2COHCH3'
transport_(318)%geometry=2
transport_(318)%LJpotential=503.072
transport_(318)%LJdiameter=  5.340
transport_(318)%dipole=  1.670
transport_(318)%polar=  8.880
transport_(318)%collision=  1.000
transport_(318)%MW= 73.115
 
transport_(319)%nome='CH3CHCHOHCH3'
transport_(319)%geometry=2
transport_(319)%LJpotential=503.072
transport_(319)%LJdiameter=  5.340
transport_(319)%dipole=  1.670
transport_(319)%polar=  8.880
transport_(319)%collision=  1.000
transport_(319)%MW= 73.115
 
transport_(320)%nome='CH2CH2CHOHCH3'
transport_(320)%geometry=2
transport_(320)%LJpotential=503.072
transport_(320)%LJdiameter=  5.340
transport_(320)%dipole=  1.670
transport_(320)%polar=  8.880
transport_(320)%collision=  1.000
transport_(320)%MW= 73.115
 
transport_(321)%nome='MEK'
transport_(321)%geometry=2
transport_(321)%LJpotential=454.000
transport_(321)%LJdiameter=  5.413
transport_(321)%dipole=  3.300
transport_(321)%polar=  0.000
transport_(321)%collision=  1.000
transport_(321)%MW= 72.107
 
transport_(322)%nome='TC4H9OH'
transport_(322)%geometry=2
transport_(322)%LJpotential=503.072
transport_(322)%LJdiameter=  5.340
transport_(322)%dipole=  1.670
transport_(322)%polar=  8.880
transport_(322)%collision=  1.000
transport_(322)%MW= 74.123
 
transport_(323)%nome='IC4H9OH'
transport_(323)%geometry=2
transport_(323)%LJpotential=503.072
transport_(323)%LJdiameter=  5.340
transport_(323)%dipole=  1.670
transport_(323)%polar=  8.880
transport_(323)%collision=  1.000
transport_(323)%MW= 74.123
 
transport_(324)%nome='CH3CH2CH2CH2O'
transport_(324)%geometry=2
transport_(324)%LJpotential=503.072
transport_(324)%LJdiameter=  5.340
transport_(324)%dipole=  1.670
transport_(324)%polar=  8.880
transport_(324)%collision=  1.000
transport_(324)%MW= 73.115
 
transport_(325)%nome='C3H7CHO'
transport_(325)%geometry=2
transport_(325)%LJpotential=503.072
transport_(325)%LJdiameter=  5.340
transport_(325)%dipole=  1.670
transport_(325)%polar=  8.880
transport_(325)%collision=  1.000
transport_(325)%MW= 72.107
 
transport_(326)%nome='CH3CH2CHOH'
transport_(326)%geometry=2
transport_(326)%LJpotential=482.147
transport_(326)%LJdiameter=  5.009
transport_(326)%dipole=  1.660
transport_(326)%polar=  6.740
transport_(326)%collision=  1.000
transport_(326)%MW= 59.088
 
transport_(327)%nome='CH3CHCH2OH'
transport_(327)%geometry=2
transport_(327)%LJpotential=482.147
transport_(327)%LJdiameter=  5.009
transport_(327)%dipole=  1.660
transport_(327)%polar=  6.740
transport_(327)%collision=  1.000
transport_(327)%MW= 59.088
 
transport_(328)%nome='CH2CH2CH2OH'
transport_(328)%geometry=2
transport_(328)%LJpotential=482.147
transport_(328)%LJdiameter=  5.009
transport_(328)%dipole=  1.660
transport_(328)%polar=  6.740
transport_(328)%collision=  1.000
transport_(328)%MW= 59.088
 
transport_(329)%nome='CH3CH2CH2O'
transport_(329)%geometry=2
transport_(329)%LJpotential=482.147
transport_(329)%LJdiameter=  5.009
transport_(329)%dipole=  1.660
transport_(329)%polar=  6.740
transport_(329)%collision=  1.000
transport_(329)%MW= 59.088
 
transport_(330)%nome='CH3COHCH3'
transport_(330)%geometry=2
transport_(330)%LJpotential=468.300
transport_(330)%LJdiameter=  4.760
transport_(330)%dipole=  0.000
transport_(330)%polar=  0.000
transport_(330)%collision=  1.000
transport_(330)%MW= 59.088
 
transport_(331)%nome='CH2CHOHCH3'
transport_(331)%geometry=2
transport_(331)%LJpotential=468.300
transport_(331)%LJdiameter=  4.760
transport_(331)%dipole=  0.000
transport_(331)%polar=  0.000
transport_(331)%collision=  1.000
transport_(331)%MW= 59.088
 
transport_(332)%nome='CH3CH2CH2CHOH'
transport_(332)%geometry=2
transport_(332)%LJpotential=503.072
transport_(332)%LJdiameter=  5.340
transport_(332)%dipole=  1.670
transport_(332)%polar=  8.880
transport_(332)%collision=  1.000
transport_(332)%MW= 73.115
 
transport_(333)%nome='CH3CH2CHCH2OH'
transport_(333)%geometry=2
transport_(333)%LJpotential=503.072
transport_(333)%LJdiameter=  5.340
transport_(333)%dipole=  1.670
transport_(333)%polar=  8.880
transport_(333)%collision=  1.000
transport_(333)%MW= 73.115
 
transport_(334)%nome='CH3CHCH2CH2OH'
transport_(334)%geometry=2
transport_(334)%LJpotential=503.072
transport_(334)%LJdiameter=  5.340
transport_(334)%dipole=  1.670
transport_(334)%polar=  8.880
transport_(334)%collision=  1.000
transport_(334)%MW= 73.115
 
transport_(335)%nome='CH2CH2CH2CH2OH'
transport_(335)%geometry=2
transport_(335)%LJpotential=503.072
transport_(335)%LJdiameter=  5.340
transport_(335)%dipole=  1.670
transport_(335)%polar=  8.880
transport_(335)%collision=  1.000
transport_(335)%MW= 73.115
 
transport_(336)%nome='RTC4H8OH'
transport_(336)%geometry=2
transport_(336)%LJpotential=503.072
transport_(336)%LJdiameter=  5.340
transport_(336)%dipole=  1.670
transport_(336)%polar=  8.880
transport_(336)%collision=  1.000
transport_(336)%MW= 73.115
 
transport_(337)%nome='RTC4H9O'
transport_(337)%geometry=2
transport_(337)%LJpotential=503.072
transport_(337)%LJdiameter=  5.340
transport_(337)%dipole=  1.670
transport_(337)%polar=  8.880
transport_(337)%collision=  1.000
transport_(337)%MW= 73.115
 
transport_(338)%nome='CH3CHCH2OCH3'
transport_(338)%geometry=2
transport_(338)%LJpotential=503.072
transport_(338)%LJdiameter=  5.340
transport_(338)%dipole=  1.670
transport_(338)%polar=  8.880
transport_(338)%collision=  1.000
transport_(338)%MW= 73.115
 
transport_(339)%nome='CH3CHCH3CHOH'
transport_(339)%geometry=2
transport_(339)%LJpotential=503.072
transport_(339)%LJdiameter=  5.340
transport_(339)%dipole=  1.670
transport_(339)%polar=  8.880
transport_(339)%collision=  1.000
transport_(339)%MW= 73.115
 
transport_(340)%nome='CH3CCH2OHCH3'
transport_(340)%geometry=2
transport_(340)%LJpotential=503.072
transport_(340)%LJdiameter=  5.340
transport_(340)%dipole=  1.670
transport_(340)%polar=  8.880
transport_(340)%collision=  1.000
transport_(340)%MW= 73.115
 
transport_(341)%nome='CH2CHCH2OHCH3'
transport_(341)%geometry=2
transport_(341)%LJpotential=503.072
transport_(341)%LJdiameter=  5.340
transport_(341)%dipole=  1.670
transport_(341)%polar=  8.880
transport_(341)%collision=  1.000
transport_(341)%MW= 73.115
 
transport_(342)%nome='C4H7OH'
transport_(342)%geometry=2
transport_(342)%LJpotential=503.072
transport_(342)%LJdiameter=  5.340
transport_(342)%dipole=  1.670
transport_(342)%polar=  8.880
transport_(342)%collision=  1.000
transport_(342)%MW= 72.107
 
transport_(343)%nome='C3H5OH'
transport_(343)%geometry=2
transport_(343)%LJpotential=411.000
transport_(343)%LJdiameter=  4.820
transport_(343)%dipole=  0.000
transport_(343)%polar=  0.000
transport_(343)%collision=  1.000
transport_(343)%MW= 58.080
 
transport_(344)%nome='RCRESOLO'
transport_(344)%geometry=2
transport_(344)%LJpotential=621.100
transport_(344)%LJdiameter=  5.640
transport_(344)%dipole=  0.000
transport_(344)%polar=  0.000
transport_(344)%collision=  1.000
transport_(344)%MW=107.132
 
transport_(345)%nome='RCRESOLC'
transport_(345)%geometry=2
transport_(345)%LJpotential=621.100
transport_(345)%LJdiameter=  5.640
transport_(345)%dipole=  0.000
transport_(345)%polar=  0.000
transport_(345)%collision=  1.000
transport_(345)%MW=107.132
 
transport_(346)%nome='C10H10'
transport_(346)%geometry=2
transport_(346)%LJpotential=630.400
transport_(346)%LJdiameter=  6.180
transport_(346)%dipole=  0.000
transport_(346)%polar= 16.500
transport_(346)%collision=  1.000
transport_(346)%MW=130.189
 
transport_(347)%nome='BZFUR'
transport_(347)%geometry=2
transport_(347)%LJpotential=630.400
transport_(347)%LJdiameter=  6.180
transport_(347)%dipole=  0.000
transport_(347)%polar= 16.500
transport_(347)%collision=  1.000
transport_(347)%MW=118.135
 
transport_(348)%nome='ODECAL'
transport_(348)%geometry=2
transport_(348)%LJpotential=630.400
transport_(348)%LJdiameter=  6.180
transport_(348)%dipole=  0.000
transport_(348)%polar= 16.500
transport_(348)%collision=  1.000
transport_(348)%MW=138.253
 
transport_(349)%nome='RTETRALIN'
transport_(349)%geometry=2
transport_(349)%LJpotential=630.400
transport_(349)%LJdiameter=  6.180
transport_(349)%dipole=  0.000
transport_(349)%polar= 16.500
transport_(349)%collision=  1.000
transport_(349)%MW=131.197
 
transport_(350)%nome='RTETRAOO'
transport_(350)%geometry=2
transport_(350)%LJpotential=630.400
transport_(350)%LJdiameter=  6.180
transport_(350)%dipole=  0.000
transport_(350)%polar= 16.500
transport_(350)%collision=  1.000
transport_(350)%MW=163.196
 
transport_(351)%nome='TMBENZ'
transport_(351)%geometry=2
transport_(351)%LJpotential=523.600
transport_(351)%LJdiameter=  5.960
transport_(351)%dipole=  0.000
transport_(351)%polar=  0.000
transport_(351)%collision=  1.000
transport_(351)%MW=120.194
 
transport_(352)%nome='NPBENZ'
transport_(352)%geometry=2
transport_(352)%LJpotential=495.300
transport_(352)%LJdiameter=  5.680
transport_(352)%dipole=  0.430
transport_(352)%polar= 12.300
transport_(352)%collision=  1.000
transport_(352)%MW=120.194
 
transport_(353)%nome='RC9H11'
transport_(353)%geometry=2
transport_(353)%LJpotential=523.600
transport_(353)%LJdiameter=  5.960
transport_(353)%dipole=  0.000
transport_(353)%polar=  0.000
transport_(353)%collision=  1.000
transport_(353)%MW=119.186
 
transport_(354)%nome='C6H5OCH3'
transport_(354)%geometry=2
transport_(354)%LJpotential=450.000
transport_(354)%LJdiameter=  5.500
transport_(354)%dipole=  0.000
transport_(354)%polar=  0.000
transport_(354)%collision=  1.000
transport_(354)%MW=108.140
 
transport_(355)%nome='MB'
transport_(355)%geometry=2
transport_(355)%LJpotential=468.000
transport_(355)%LJdiameter=  5.850
transport_(355)%dipole=  0.000
transport_(355)%polar=  0.000
transport_(355)%collision=  0.000
transport_(355)%MW=102.133
 
transport_(356)%nome='RMBX'
transport_(356)%geometry=2
transport_(356)%LJpotential=468.500
transport_(356)%LJdiameter=  5.230
transport_(356)%dipole=  0.000
transport_(356)%polar=  0.000
transport_(356)%collision=  1.000
transport_(356)%MW=101.125
 
transport_(357)%nome='MCROT'
transport_(357)%geometry=2
transport_(357)%LJpotential=468.500
transport_(357)%LJdiameter=  5.230
transport_(357)%dipole=  0.000
transport_(357)%polar=  0.000
transport_(357)%collision=  1.000
transport_(357)%MW=100.117
 
transport_(358)%nome='MACRIL'
transport_(358)%geometry=2
transport_(358)%LJpotential=430.100
transport_(358)%LJdiameter=  5.833
transport_(358)%dipole=  0.000
transport_(358)%polar=  0.000
transport_(358)%collision=  1.000
transport_(358)%MW= 86.090
 
transport_(359)%nome='RMP3'
transport_(359)%geometry=2
transport_(359)%LJpotential=430.100
transport_(359)%LJdiameter=  5.833
transport_(359)%dipole=  0.000
transport_(359)%polar=  0.000
transport_(359)%collision=  1.000
transport_(359)%MW= 87.098
 
transport_(360)%nome='CH3OCO'
transport_(360)%geometry=2
transport_(360)%LJpotential=395.000
transport_(360)%LJdiameter=  4.037
transport_(360)%dipole=  1.300
transport_(360)%polar=  0.000
transport_(360)%collision=  1.000
transport_(360)%MW= 59.045
 
transport_(361)%nome='ETMB583'
transport_(361)%geometry=2
transport_(361)%LJpotential=508.000
transport_(361)%LJdiameter=  5.200
transport_(361)%dipole=  0.000
transport_(361)%polar=  0.000
transport_(361)%collision=  1.000
transport_(361)%MW=116.117
 
transport_(362)%nome='KEHYMB'
transport_(362)%geometry=2
transport_(362)%LJpotential=508.000
transport_(362)%LJdiameter=  5.200
transport_(362)%dipole=  0.000
transport_(362)%polar=  0.000
transport_(362)%collision=  1.000
transport_(362)%MW=148.116
 
transport_(363)%nome='DIBZFUR'
transport_(363)%geometry=2
transport_(363)%LJpotential=676.500
transport_(363)%LJdiameter=  6.310
transport_(363)%dipole=  0.000
transport_(363)%polar=  0.000
transport_(363)%collision=  1.000
transport_(363)%MW=168.195
 
transport_(364)%nome='DIFENET'
transport_(364)%geometry=2
transport_(364)%LJpotential=676.500
transport_(364)%LJdiameter=  6.310
transport_(364)%dipole=  0.000
transport_(364)%polar=  0.000
transport_(364)%collision=  1.000
transport_(364)%MW=170.211
 
transport_(365)%nome='RMBOOX'
transport_(365)%geometry=2
transport_(365)%LJpotential=508.000
transport_(365)%LJdiameter=  5.200
transport_(365)%dipole=  0.000
transport_(365)%polar=  0.000
transport_(365)%collision=  1.000
transport_(365)%MW=133.124
 
transport_(366)%nome='QMBOOX'
transport_(366)%geometry=2
transport_(366)%LJpotential=508.000
transport_(366)%LJdiameter=  5.200
transport_(366)%dipole=  0.000
transport_(366)%polar=  0.000
transport_(366)%collision=  1.000
transport_(366)%MW=133.124
 
transport_(367)%nome='ZMBOOX'
transport_(367)%geometry=2
transport_(367)%LJpotential=508.000
transport_(367)%LJdiameter=  5.200
transport_(367)%dipole=  0.000
transport_(367)%polar=  0.000
transport_(367)%collision=  1.000
transport_(367)%MW=165.123
 
transport_(368)%nome='KHDECA'
transport_(368)%geometry=2
transport_(368)%LJpotential=630.400
transport_(368)%LJdiameter=  6.180
transport_(368)%dipole=  0.000
transport_(368)%polar= 16.500
transport_(368)%collision=  1.000
transport_(368)%MW=184.235
 
transport_(369)%nome='QDECOOH'
transport_(369)%geometry=2
transport_(369)%LJpotential=630.400
transport_(369)%LJdiameter=  6.180
transport_(369)%dipole=  0.000
transport_(369)%polar= 16.500
transport_(369)%collision=  1.000
transport_(369)%MW=169.244
 
transport_(370)%nome='RDECOO'
transport_(370)%geometry=2
transport_(370)%LJpotential=630.400
transport_(370)%LJdiameter=  6.180
transport_(370)%dipole=  0.000
transport_(370)%polar= 16.500
transport_(370)%collision=  1.000
transport_(370)%MW=169.244
 
transport_(371)%nome='ZDECA'
transport_(371)%geometry=2
transport_(371)%LJpotential=630.400
transport_(371)%LJdiameter=  6.180
transport_(371)%dipole=  0.000
transport_(371)%polar= 16.500
transport_(371)%collision=  1.000
transport_(371)%MW=201.243
 
transport_(372)%nome='RMCROTA'
transport_(372)%geometry=2
transport_(372)%LJpotential=468.500
transport_(372)%LJdiameter=  5.230
transport_(372)%dipole=  0.000
transport_(372)%polar=  0.000
transport_(372)%collision=  1.000
transport_(372)%MW= 99.109
 
transport_(373)%nome='MD'
transport_(373)%geometry=2
transport_(373)%LJpotential=604.400
transport_(373)%LJdiameter=  7.305
transport_(373)%dipole=  1.700
transport_(373)%polar=  0.000
transport_(373)%collision=  1.000
transport_(373)%MW=186.294
 
transport_(374)%nome='RMDX'
transport_(374)%geometry=2
transport_(374)%LJpotential=604.400
transport_(374)%LJdiameter=  7.305
transport_(374)%dipole=  1.700
transport_(374)%polar=  0.000
transport_(374)%collision=  1.000
transport_(374)%MW=185.287
 
transport_(375)%nome='CH3OCHO'
transport_(375)%geometry=2
transport_(375)%LJpotential=395.000
transport_(375)%LJdiameter=  4.037
transport_(375)%dipole=  1.300
transport_(375)%polar=  0.000
transport_(375)%collision=  1.000
transport_(375)%MW= 60.053
 
transport_(376)%nome='ETEROMD'
transport_(376)%geometry=2
transport_(376)%LJpotential=680.000
transport_(376)%LJdiameter=  7.600
transport_(376)%dipole=  0.000
transport_(376)%polar=  0.000
transport_(376)%collision=  1.000
transport_(376)%MW=200.278
 
transport_(377)%nome='MDKETO'
transport_(377)%geometry=2
transport_(377)%LJpotential=680.000
transport_(377)%LJdiameter=  7.600
transport_(377)%dipole=  0.000
transport_(377)%polar=  0.000
transport_(377)%collision=  1.000
transport_(377)%MW=232.277
 
transport_(378)%nome='C7H15COCHO'
transport_(378)%geometry=2
transport_(378)%LJpotential=594.000
transport_(378)%LJdiameter=  6.170
transport_(378)%dipole=  0.000
transport_(378)%polar=  0.000
transport_(378)%collision=  1.000
transport_(378)%MW=156.225
 
transport_(379)%nome='RMDOOX'
transport_(379)%geometry=2
transport_(379)%LJpotential=750.000
transport_(379)%LJdiameter=  8.350
transport_(379)%dipole=  0.000
transport_(379)%polar=  0.000
transport_(379)%collision=  1.000
transport_(379)%MW=217.285
 
transport_(380)%nome='QMDOOH'
transport_(380)%geometry=2
transport_(380)%LJpotential=750.000
transport_(380)%LJdiameter=  8.350
transport_(380)%dipole=  0.000
transport_(380)%polar=  0.000
transport_(380)%collision=  1.000
transport_(380)%MW=217.285
 
transport_(381)%nome='ZMDOOH'
transport_(381)%geometry=2
transport_(381)%LJpotential=750.000
transport_(381)%LJdiameter=  8.350
transport_(381)%dipole=  0.000
transport_(381)%polar=  0.000
transport_(381)%collision=  1.000
transport_(381)%MW=249.284
 
transport_(382)%nome='U2ME10'
transport_(382)%geometry=2
transport_(382)%LJpotential=604.400
transport_(382)%LJdiameter=  7.305
transport_(382)%dipole=  2.000
transport_(382)%polar=  0.000
transport_(382)%collision=  1.000
transport_(382)%MW=182.263
 
transport_(383)%nome='UME10'
transport_(383)%geometry=2
transport_(383)%LJpotential=604.400
transport_(383)%LJdiameter=  7.305
transport_(383)%dipole=  2.000
transport_(383)%polar=  0.000
transport_(383)%collision=  1.000
transport_(383)%MW=184.279
 
transport_(384)%nome='UME7'
transport_(384)%geometry=2
transport_(384)%LJpotential=556.820
transport_(384)%LJdiameter=  6.410
transport_(384)%dipole=  1.700
transport_(384)%polar= 16.140
transport_(384)%collision=  1.000
transport_(384)%MW=142.198
 
transport_(385)%nome='C12H22'
transport_(385)%geometry=2
transport_(385)%LJpotential=580.000
transport_(385)%LJdiameter=  7.600
transport_(385)%dipole=  0.000
transport_(385)%polar=  0.000
transport_(385)%collision=  1.000
transport_(385)%MW=166.307
 
transport_(386)%nome='DCYC5'
transport_(386)%geometry=2
transport_(386)%LJpotential=630.400
transport_(386)%LJdiameter=  6.180
transport_(386)%dipole=  0.000
transport_(386)%polar= 16.500
transport_(386)%collision=  1.000
transport_(386)%MW=136.237
 
transport_(387)%nome='UME16'
transport_(387)%geometry=2
transport_(387)%LJpotential=750.000
transport_(387)%LJdiameter=  8.350
transport_(387)%dipole=  0.000
transport_(387)%polar=  0.000
transport_(387)%collision=  1.000
transport_(387)%MW=268.440
 
transport_(388)%nome='ETEROMPA'
transport_(388)%geometry=2
transport_(388)%LJpotential=750.000
transport_(388)%LJdiameter=  8.350
transport_(388)%dipole=  0.000
transport_(388)%polar=  0.000
transport_(388)%collision=  1.000
transport_(388)%MW=284.439
 
transport_(389)%nome='MPA'
transport_(389)%geometry=2
transport_(389)%LJpotential=750.000
transport_(389)%LJdiameter=  8.350
transport_(389)%dipole=  0.000
transport_(389)%polar=  0.000
transport_(389)%collision=  1.000
transport_(389)%MW=270.456
 
transport_(390)%nome='KHMLIN1'
transport_(390)%geometry=2
transport_(390)%LJpotential=750.000
transport_(390)%LJdiameter=  8.350
transport_(390)%dipole=  0.000
transport_(390)%polar=  0.000
transport_(390)%collision=  1.000
transport_(390)%MW=338.444
 
transport_(391)%nome='MLIN1'
transport_(391)%geometry=2
transport_(391)%LJpotential=750.000
transport_(391)%LJdiameter=  8.350
transport_(391)%dipole=  0.000
transport_(391)%polar=  0.000
transport_(391)%collision=  1.000
transport_(391)%MW=292.462
 
transport_(392)%nome='MLINO'
transport_(392)%geometry=2
transport_(392)%LJpotential=750.000
transport_(392)%LJdiameter=  8.350
transport_(392)%dipole=  0.000
transport_(392)%polar=  0.000
transport_(392)%collision=  1.000
transport_(392)%MW=294.478
 
transport_(393)%nome='MEOLE'
transport_(393)%geometry=2
transport_(393)%LJpotential=750.000
transport_(393)%LJdiameter=  8.350
transport_(393)%dipole=  0.000
transport_(393)%polar=  0.000
transport_(393)%collision=  1.000
transport_(393)%MW=296.494
 
transport_(394)%nome='MSTEA'
transport_(394)%geometry=2
transport_(394)%LJpotential=750.000
transport_(394)%LJdiameter=  8.350
transport_(394)%dipole=  0.000
transport_(394)%polar=  0.000
transport_(394)%collision=  1.000
transport_(394)%MW=298.510
 
transport_(395)%nome='RUME7'
transport_(395)%geometry=2
transport_(395)%LJpotential=556.820
transport_(395)%LJdiameter=  6.410
transport_(395)%dipole=  1.700
transport_(395)%polar= 16.140
transport_(395)%collision=  1.000
transport_(395)%MW=141.190
 
transport_(396)%nome='RME7'
transport_(396)%geometry=2
transport_(396)%LJpotential=556.820
transport_(396)%LJdiameter=  6.410
transport_(396)%dipole=  1.700
transport_(396)%polar= 16.140
transport_(396)%collision=  1.000
transport_(396)%MW=143.206
 
transport_(397)%nome='RUME10'
transport_(397)%geometry=2
transport_(397)%LJpotential=604.400
transport_(397)%LJdiameter=  7.305
transport_(397)%dipole=  2.000
transport_(397)%polar=  0.000
transport_(397)%collision=  1.000
transport_(397)%MW=183.271
 
transport_(398)%nome='RMPAX'
transport_(398)%geometry=2
transport_(398)%LJpotential=750.000
transport_(398)%LJdiameter=  8.350
transport_(398)%dipole=  0.000
transport_(398)%polar=  0.000
transport_(398)%collision=  1.000
transport_(398)%MW=269.448
 
transport_(399)%nome='QMPAOOH'
transport_(399)%geometry=2
transport_(399)%LJpotential=750.000
transport_(399)%LJdiameter=  8.350
transport_(399)%dipole=  0.000
transport_(399)%polar=  0.000
transport_(399)%collision=  1.000
transport_(399)%MW=301.447
 
transport_(400)%nome='RMPAOOX'
transport_(400)%geometry=2
transport_(400)%LJpotential=750.000
transport_(400)%LJdiameter=  8.350
transport_(400)%dipole=  0.000
transport_(400)%polar=  0.000
transport_(400)%collision=  1.000
transport_(400)%MW=301.447
 
transport_(401)%nome='ZMPAOOH'
transport_(401)%geometry=2
transport_(401)%LJpotential=750.000
transport_(401)%LJdiameter=  8.350
transport_(401)%dipole=  0.000
transport_(401)%polar=  0.000
transport_(401)%collision=  1.000
transport_(401)%MW=333.445
 
transport_(402)%nome='RMLIN1A'
transport_(402)%geometry=2
transport_(402)%LJpotential=750.000
transport_(402)%LJdiameter=  8.350
transport_(402)%dipole=  0.000
transport_(402)%polar=  0.000
transport_(402)%collision=  1.000
transport_(402)%MW=291.454
 
transport_(403)%nome='RMLIN1X'
transport_(403)%geometry=2
transport_(403)%LJpotential=750.000
transport_(403)%LJdiameter=  8.350
transport_(403)%dipole=  0.000
transport_(403)%polar=  0.000
transport_(403)%collision=  1.000
transport_(403)%MW=291.454
 
transport_(404)%nome='RMLIN1OOX'
transport_(404)%geometry=2
transport_(404)%LJpotential=750.000
transport_(404)%LJdiameter=  8.350
transport_(404)%dipole=  0.000
transport_(404)%polar=  0.000
transport_(404)%collision=  1.000
transport_(404)%MW=323.453
 
transport_(405)%nome='QMLIN1OOX'
transport_(405)%geometry=2
transport_(405)%LJpotential=750.000
transport_(405)%LJdiameter=  8.350
transport_(405)%dipole=  0.000
transport_(405)%polar=  0.000
transport_(405)%collision=  1.000
transport_(405)%MW=323.453
 
transport_(406)%nome='ZMLIN1OOX'
transport_(406)%geometry=2
transport_(406)%LJpotential=750.000
transport_(406)%LJdiameter=  8.350
transport_(406)%dipole=  0.000
transport_(406)%polar=  0.000
transport_(406)%collision=  1.000
transport_(406)%MW=355.452
 
transport_(407)%nome='RMLINA'
transport_(407)%geometry=2
transport_(407)%LJpotential=750.000
transport_(407)%LJdiameter=  8.350
transport_(407)%dipole=  0.000
transport_(407)%polar=  0.000
transport_(407)%collision=  1.000
transport_(407)%MW=293.470
 
transport_(408)%nome='RMLINX'
transport_(408)%geometry=2
transport_(408)%LJpotential=750.000
transport_(408)%LJdiameter=  8.350
transport_(408)%dipole=  0.000
transport_(408)%polar=  0.000
transport_(408)%collision=  1.000
transport_(408)%MW=293.470
 
transport_(409)%nome='RMLINOOX'
transport_(409)%geometry=2
transport_(409)%LJpotential=750.000
transport_(409)%LJdiameter=  8.350
transport_(409)%dipole=  0.000
transport_(409)%polar=  0.000
transport_(409)%collision=  1.000
transport_(409)%MW=325.469
 
transport_(410)%nome='QMLINOOX'
transport_(410)%geometry=2
transport_(410)%LJpotential=750.000
transport_(410)%LJdiameter=  8.350
transport_(410)%dipole=  0.000
transport_(410)%polar=  0.000
transport_(410)%collision=  1.000
transport_(410)%MW=325.469
 
transport_(411)%nome='ZMLINOOX'
transport_(411)%geometry=2
transport_(411)%LJpotential=750.000
transport_(411)%LJdiameter=  8.350
transport_(411)%dipole=  0.000
transport_(411)%polar=  0.000
transport_(411)%collision=  1.000
transport_(411)%MW=357.467
 
transport_(412)%nome='RMEOLEA'
transport_(412)%geometry=2
transport_(412)%LJpotential=750.000
transport_(412)%LJdiameter=  8.350
transport_(412)%dipole=  0.000
transport_(412)%polar=  0.000
transport_(412)%collision=  1.000
transport_(412)%MW=295.486
 
transport_(413)%nome='RMEOLES'
transport_(413)%geometry=2
transport_(413)%LJpotential=750.000
transport_(413)%LJdiameter=  8.350
transport_(413)%dipole=  0.000
transport_(413)%polar=  0.000
transport_(413)%collision=  1.000
transport_(413)%MW=295.486
 
transport_(414)%nome='RMEOLEOOX'
transport_(414)%geometry=2
transport_(414)%LJpotential=750.000
transport_(414)%LJdiameter=  8.350
transport_(414)%dipole=  0.000
transport_(414)%polar=  0.000
transport_(414)%collision=  1.000
transport_(414)%MW=327.484
 
transport_(415)%nome='QMEOLEOOH'
transport_(415)%geometry=2
transport_(415)%LJpotential=750.000
transport_(415)%LJdiameter=  8.350
transport_(415)%dipole=  0.000
transport_(415)%polar=  0.000
transport_(415)%collision=  1.000
transport_(415)%MW=327.484
 
transport_(416)%nome='ZMEOLEOOX'
transport_(416)%geometry=2
transport_(416)%LJpotential=750.000
transport_(416)%LJdiameter=  8.350
transport_(416)%dipole=  0.000
transport_(416)%polar=  0.000
transport_(416)%collision=  1.000
transport_(416)%MW=359.483
 
transport_(417)%nome='RSTEAX'
transport_(417)%geometry=2
transport_(417)%LJpotential=750.000
transport_(417)%LJdiameter=  8.350
transport_(417)%dipole=  0.000
transport_(417)%polar=  0.000
transport_(417)%collision=  1.000
transport_(417)%MW=297.502
 
transport_(418)%nome='RMSTEAOOX'
transport_(418)%geometry=2
transport_(418)%LJpotential=750.000
transport_(418)%LJdiameter=  8.350
transport_(418)%dipole=  0.000
transport_(418)%polar=  0.000
transport_(418)%collision=  1.000
transport_(418)%MW=329.500
 
transport_(419)%nome='QMSTEAOOH'
transport_(419)%geometry=2
transport_(419)%LJpotential=750.000
transport_(419)%LJdiameter=  8.350
transport_(419)%dipole=  0.000
transport_(419)%polar=  0.000
transport_(419)%collision=  1.000
transport_(419)%MW=329.500
 
transport_(420)%nome='ZMSTEAOOH'
transport_(420)%geometry=2
transport_(420)%LJpotential=750.000
transport_(420)%LJdiameter=  8.350
transport_(420)%dipole=  0.000
transport_(420)%polar=  0.000
transport_(420)%collision=  1.000
transport_(420)%MW=361.499
 
transport_(421)%nome='U2ME12'
transport_(421)%geometry=2
transport_(421)%LJpotential=620.000
transport_(421)%LJdiameter=  8.000
transport_(421)%dipole=  0.000
transport_(421)%polar=  0.000
transport_(421)%collision=  1.000
transport_(421)%MW=210.316
 
transport_(422)%nome='ALDEST'
transport_(422)%geometry=2
transport_(422)%LJpotential=568.500
transport_(422)%LJdiameter=  5.230
transport_(422)%dipole=  0.000
transport_(422)%polar= 10.300
transport_(422)%collision=  1.000
transport_(422)%MW=130.144
 
transport_(423)%nome='RALDEST'
transport_(423)%geometry=2
transport_(423)%LJpotential=568.500
transport_(423)%LJdiameter=  5.230
transport_(423)%dipole=  0.000
transport_(423)%polar= 10.300
transport_(423)%collision=  1.000
transport_(423)%MW=129.136
 
transport_(424)%nome='C12H18'
transport_(424)%geometry=2
transport_(424)%LJpotential=620.000
transport_(424)%LJdiameter=  8.000
transport_(424)%dipole=  0.000
transport_(424)%polar=  0.000
transport_(424)%collision=  1.000
transport_(424)%MW=162.275
 
transport_(425)%nome='RODECA'
transport_(425)%geometry=2
transport_(425)%LJpotential=630.400
transport_(425)%LJdiameter=  6.180
transport_(425)%dipole=  0.000
transport_(425)%polar= 16.500
transport_(425)%collision=  1.000
transport_(425)%MW=137.245
 
transport_(426)%nome='ALDINS'
transport_(426)%geometry=2
transport_(426)%LJpotential=620.000
transport_(426)%LJdiameter=  8.000
transport_(426)%dipole=  0.000
transport_(426)%polar=  0.000
transport_(426)%collision=  1.000
transport_(426)%MW=192.301
 
transport_(427)%nome='RUME16'
transport_(427)%geometry=2
transport_(427)%LJpotential=750.000
transport_(427)%LJdiameter=  8.350
transport_(427)%dipole=  0.000
transport_(427)%polar=  0.000
transport_(427)%collision=  1.000
transport_(427)%MW=267.432
 
transport_(428)%nome='NC10H19'
transport_(428)%geometry=2
transport_(428)%LJpotential=540.980
transport_(428)%LJdiameter=  7.150
transport_(428)%dipole=  0.000
transport_(428)%polar=  0.000
transport_(428)%collision=  1.000
transport_(428)%MW=139.261
 
transport_(429)%nome='C8H9'
transport_(429)%geometry=2
transport_(429)%LJpotential=546.200
transport_(429)%LJdiameter=  6.000
transport_(429)%dipole=  0.000
transport_(429)%polar=  0.000
transport_(429)%collision=  1.000
transport_(429)%MW=105.159
 
transport_(430)%nome='NC7H13OOH'
transport_(430)%geometry=2
transport_(430)%LJpotential=559.980
transport_(430)%LJdiameter=  6.310
transport_(430)%dipole=  0.000
transport_(430)%polar=  0.000
transport_(430)%collision=  1.000
transport_(430)%MW=130.187
 
transport_(431)%nome='NC7H13'
transport_(431)%geometry=2
transport_(431)%LJpotential=559.980
transport_(431)%LJdiameter=  6.310
transport_(431)%dipole=  0.000
transport_(431)%polar=  0.000
transport_(431)%collision=  1.000
transport_(431)%MW= 97.180
 
transport_(432)%nome='LC6H5'
transport_(432)%geometry=2
transport_(432)%LJpotential=412.300
transport_(432)%LJdiameter=  5.349
transport_(432)%dipole=  0.000
transport_(432)%polar=  0.000
transport_(432)%collision=  1.000
transport_(432)%MW= 77.106
 
transport_(433)%nome='C6H2'
transport_(433)%geometry=1
transport_(433)%LJpotential=357.000
transport_(433)%LJdiameter=  5.180
transport_(433)%dipole=  0.000
transport_(433)%polar=  0.000
transport_(433)%collision=  1.000
transport_(433)%MW= 74.082
 
transport_(434)%nome='C8H2'
transport_(434)%geometry=1
transport_(434)%LJpotential=495.300
transport_(434)%LJdiameter=  5.680
transport_(434)%dipole=  0.430
transport_(434)%polar= 12.300
transport_(434)%collision=  1.000
transport_(434)%MW= 98.104
 
transport_(435)%nome='C6H3'
transport_(435)%geometry=1
transport_(435)%LJpotential=357.000
transport_(435)%LJdiameter=  5.180
transport_(435)%dipole=  0.000
transport_(435)%polar=  0.000
transport_(435)%collision=  1.000
transport_(435)%MW= 75.090
 
transport_(436)%nome='C6H4'
transport_(436)%geometry=2
transport_(436)%LJpotential=412.300
transport_(436)%LJdiameter=  5.349
transport_(436)%dipole=  0.000
transport_(436)%polar=  0.000
transport_(436)%collision=  1.000
transport_(436)%MW= 76.098
 
transport_(437)%nome='BENZYNE'
transport_(437)%geometry=2
transport_(437)%LJpotential=468.500
transport_(437)%LJdiameter=  5.230
transport_(437)%dipole=  0.000
transport_(437)%polar= 10.300
transport_(437)%collision=  1.000
transport_(437)%MW= 76.098
 
transport_(438)%nome='NC10MOOH'
transport_(438)%geometry=2
transport_(438)%LJpotential=640.980
transport_(438)%LJdiameter=  7.150
transport_(438)%dipole=  0.000
transport_(438)%polar=  0.000
transport_(438)%collision=  1.000
transport_(438)%MW=172.268
 
transport_(439)%nome='MSTEAKETO'
transport_(439)%geometry=2
transport_(439)%LJpotential=750.000
transport_(439)%LJdiameter=  8.350
transport_(439)%dipole=  0.000
transport_(439)%polar=  0.000
transport_(439)%collision=  1.000
transport_(439)%MW=344.492
 
transport_(440)%nome='C5H5O'
transport_(440)%geometry=2
transport_(440)%LJpotential=450.000
transport_(440)%LJdiameter=  5.500
transport_(440)%dipole=  0.000
transport_(440)%polar=  0.000
transport_(440)%collision=  1.000
transport_(440)%MW= 81.094
 
transport_(441)%nome='C2H2O2'
transport_(441)%geometry=2
transport_(441)%LJpotential=470.600
transport_(441)%LJdiameter=  4.410
transport_(441)%dipole=  0.000
transport_(441)%polar=  0.000
transport_(441)%collision=  1.500
transport_(441)%MW= 58.037
 
transport_(442)%nome='C2H4O2'
transport_(442)%geometry=2
transport_(442)%LJpotential=496.000
transport_(442)%LJdiameter=  5.200
transport_(442)%dipole=  0.000
transport_(442)%polar=  0.000
transport_(442)%collision=  1.000
transport_(442)%MW= 60.053
 
transport_(443)%nome='GLIET'
transport_(443)%geometry=2
transport_(443)%LJpotential=470.600
transport_(443)%LJdiameter=  4.410
transport_(443)%dipole=  0.000
transport_(443)%polar=  0.000
transport_(443)%collision=  1.500
transport_(443)%MW= 62.068
 
transport_(444)%nome='C3H4O2'
transport_(444)%geometry=2
transport_(444)%LJpotential=435.200
transport_(444)%LJdiameter=  4.662
transport_(444)%dipole=  2.700
transport_(444)%polar=  0.000
transport_(444)%collision=  1.000
transport_(444)%MW= 72.064
 
transport_(445)%nome='C3H4O3'
transport_(445)%geometry=2
transport_(445)%LJpotential=435.200
transport_(445)%LJdiameter=  4.662
transport_(445)%dipole=  2.700
transport_(445)%polar=  0.000
transport_(445)%collision=  1.000
transport_(445)%MW= 88.063
 
transport_(446)%nome='C3H6O2'
transport_(446)%geometry=2
transport_(446)%LJpotential=503.072
transport_(446)%LJdiameter=  5.339
transport_(446)%dipole=  1.670
transport_(446)%polar=  7.016
transport_(446)%collision=  1.000
transport_(446)%MW= 74.079
 
transport_(447)%nome='C4H6O2'
transport_(447)%geometry=2
transport_(447)%LJpotential=496.000
transport_(447)%LJdiameter=  5.200
transport_(447)%dipole=  0.000
transport_(447)%polar=  0.000
transport_(447)%collision=  1.000
transport_(447)%MW= 86.090
 
transport_(448)%nome='C5H4O2'
transport_(448)%geometry=2
transport_(448)%LJpotential=524.690
transport_(448)%LJdiameter=  5.653
transport_(448)%dipole=  0.000
transport_(448)%polar=  0.000
transport_(448)%collision=  1.000
transport_(448)%MW= 96.086
 
transport_(449)%nome='C5H8O4'
transport_(449)%geometry=2
transport_(449)%LJpotential=568.500
transport_(449)%LJdiameter=  5.230
transport_(449)%dipole=  0.000
transport_(449)%polar= 10.300
transport_(449)%collision=  1.000
transport_(449)%MW=132.116
 
transport_(450)%nome='C6H6O3'
transport_(450)%geometry=2
transport_(450)%LJpotential=567.841
transport_(450)%LJdiameter=  5.915
transport_(450)%dipole=  0.000
transport_(450)%polar=  0.000
transport_(450)%collision=  1.000
transport_(450)%MW=126.112
 
transport_(451)%nome='C6H8O4'
transport_(451)%geometry=2
transport_(451)%LJpotential=568.500
transport_(451)%LJdiameter=  5.230
transport_(451)%dipole=  0.000
transport_(451)%polar= 10.300
transport_(451)%collision=  1.000
transport_(451)%MW=144.127
 
transport_(452)%nome='C6H10O5'
transport_(452)%geometry=2
transport_(452)%LJpotential=568.500
transport_(452)%LJdiameter=  5.230
transport_(452)%dipole=  0.000
transport_(452)%polar= 10.300
transport_(452)%collision=  1.000
transport_(452)%MW=162.142
 
transport_(453)%nome='C8H10O3'
transport_(453)%geometry=2
transport_(453)%LJpotential=621.100
transport_(453)%LJdiameter=  5.640
transport_(453)%dipole=  0.000
transport_(453)%polar=  0.000
transport_(453)%collision=  1.000
transport_(453)%MW=154.166
 
transport_(454)%nome='C9H10O2'
transport_(454)%geometry=2
transport_(454)%LJpotential=663.450
transport_(454)%LJdiameter=  6.362
transport_(454)%dipole=  0.000
transport_(454)%polar=  0.000
transport_(454)%collision=  1.000
transport_(454)%MW=150.177
 
transport_(455)%nome='C11H12O4'
transport_(455)%geometry=2
transport_(455)%LJpotential=663.450
transport_(455)%LJdiameter=  6.362
transport_(455)%dipole=  0.000
transport_(455)%polar=  0.000
transport_(455)%collision=  1.000
transport_(455)%MW=208.214
 
transport_(456)%nome='C4H3O'
transport_(456)%geometry=2
transport_(456)%LJpotential=425.929
transport_(456)%LJdiameter=  5.015
transport_(456)%dipole=  0.000
transport_(456)%polar=  0.000
transport_(456)%collision=  1.000
transport_(456)%MW= 67.067
 
transport_(457)%nome='HCOOH'
transport_(457)%geometry=2
transport_(457)%LJpotential=470.600
transport_(457)%LJdiameter=  3.855
transport_(457)%dipole=  0.000
transport_(457)%polar=  0.000
transport_(457)%collision=  1.000
transport_(457)%MW= 46.026
 
transport_(458)%nome='ACETOL'
transport_(458)%geometry=2
transport_(458)%LJpotential=503.072
transport_(458)%LJdiameter=  5.339
transport_(458)%dipole=  1.670
transport_(458)%polar=  7.016
transport_(458)%collision=  1.000
transport_(458)%MW= 74.079
 
transport_(459)%nome='GLYCEROL'
transport_(459)%geometry=2
transport_(459)%LJpotential=748.365
transport_(459)%LJdiameter=  5.200
transport_(459)%dipole=  1.930
transport_(459)%polar=  9.430
transport_(459)%collision=  1.000
transport_(459)%MW= 92.095
 
transport_(460)%nome='CH2CCHCHO'
transport_(460)%geometry=2
transport_(460)%LJpotential=362.600
transport_(460)%LJdiameter=  4.530
transport_(460)%dipole=  0.000
transport_(460)%polar=  0.000
transport_(460)%collision=  1.500
transport_(460)%MW= 68.075
 
transport_(461)%nome='KEHYBU1'
transport_(461)%geometry=2
transport_(461)%LJpotential=496.000
transport_(461)%LJdiameter=  5.200
transport_(461)%dipole=  0.000
transport_(461)%polar=  0.000
transport_(461)%collision=  1.000
transport_(461)%MW=120.105
 
transport_(462)%nome='RBU1OOX'
transport_(462)%geometry=2
transport_(462)%LJpotential=496.000
transport_(462)%LJdiameter=  5.200
transport_(462)%dipole=  0.000
transport_(462)%polar=  0.000
transport_(462)%collision=  1.000
transport_(462)%MW=105.114
 
transport_(463)%nome='QBU1OOX'
transport_(463)%geometry=2
transport_(463)%LJpotential=496.000
transport_(463)%LJdiameter=  5.200
transport_(463)%dipole=  0.000
transport_(463)%polar=  0.000
transport_(463)%collision=  1.000
transport_(463)%MW=105.114
 
transport_(464)%nome='ZBU1OOX'
transport_(464)%geometry=2
transport_(464)%LJpotential=496.000
transport_(464)%LJdiameter=  5.200
transport_(464)%dipole=  0.000
transport_(464)%polar=  0.000
transport_(464)%collision=  1.000
transport_(464)%MW=137.112
 
transport_(465)%nome='DMF'
transport_(465)%geometry=2
transport_(465)%LJpotential=524.828
transport_(465)%LJdiameter=  5.653
transport_(465)%dipole=  0.000
transport_(465)%polar=  0.000
transport_(465)%collision=  1.000
transport_(465)%MW= 96.129
 
transport_(466)%nome='DMF-3YL'
transport_(466)%geometry=2
transport_(466)%LJpotential=521.629
transport_(466)%LJdiameter=  5.634
transport_(466)%dipole=  0.000
transport_(466)%polar=  0.000
transport_(466)%collision=  1.000
transport_(466)%MW= 95.121
 
transport_(467)%nome='MEFU2'
transport_(467)%geometry=2
transport_(467)%LJpotential=478.946
transport_(467)%LJdiameter=  5.364
transport_(467)%dipole=  0.000
transport_(467)%polar=  0.000
transport_(467)%collision=  1.000
transport_(467)%MW= 82.102
 
transport_(468)%nome='C4H4O'
transport_(468)%geometry=2
transport_(468)%LJpotential=429.630
transport_(468)%LJdiameter=  5.040
transport_(468)%dipole=  0.000
transport_(468)%polar=  0.000
transport_(468)%collision=  1.000
transport_(468)%MW= 68.075
 
transport_(469)%nome='ETC3H4O2'
transport_(469)%geometry=2
transport_(469)%LJpotential=411.000
transport_(469)%LJdiameter=  4.820
transport_(469)%dipole=  0.000
transport_(469)%polar=  0.000
transport_(469)%collision=  1.000
transport_(469)%MW= 72.064
 
transport_(470)%nome='KEA3B3'
transport_(470)%geometry=2
transport_(470)%LJpotential=411.000
transport_(470)%LJdiameter=  4.820
transport_(470)%dipole=  0.000
transport_(470)%polar=  0.000
transport_(470)%collision=  1.000
transport_(470)%MW=104.062
 
transport_(471)%nome='KEA3G2'
transport_(471)%geometry=2
transport_(471)%LJpotential=411.000
transport_(471)%LJdiameter=  4.820
transport_(471)%dipole=  0.000
transport_(471)%polar=  0.000
transport_(471)%collision=  1.000
transport_(471)%MW=104.062
 
transport_(472)%nome='RALD3G'
transport_(472)%geometry=2
transport_(472)%LJpotential=411.000
transport_(472)%LJdiameter=  4.820
transport_(472)%dipole=  0.000
transport_(472)%polar=  0.000
transport_(472)%collision=  1.000
transport_(472)%MW= 57.072
 
transport_(473)%nome='RALD3B'
transport_(473)%geometry=2
transport_(473)%LJpotential=411.000
transport_(473)%LJdiameter=  4.820
transport_(473)%dipole=  0.000
transport_(473)%polar=  0.000
transport_(473)%collision=  1.000
transport_(473)%MW= 57.072
 
transport_(474)%nome='C3H5CHO'
transport_(474)%geometry=2
transport_(474)%LJpotential=357.000
transport_(474)%LJdiameter=  5.180
transport_(474)%dipole=  0.000
transport_(474)%polar=  0.000
transport_(474)%collision=  1.000
transport_(474)%MW= 70.091
 
transport_(475)%nome='C7DIONE'
transport_(475)%geometry=2
transport_(475)%LJpotential=559.980
transport_(475)%LJdiameter=  6.310
transport_(475)%dipole=  0.000
transport_(475)%polar=  0.000
transport_(475)%collision=  1.000
transport_(475)%MW=128.171
 
transport_(476)%nome='C7KETONE'
transport_(476)%geometry=2
transport_(476)%LJpotential=559.980
transport_(476)%LJdiameter=  6.310
transport_(476)%dipole=  0.000
transport_(476)%polar=  0.000
transport_(476)%collision=  1.000
transport_(476)%MW=114.188
 
transport_(477)%nome='CH2OOHCHCHO'
transport_(477)%geometry=2
transport_(477)%LJpotential=407.800
transport_(477)%LJdiameter=  4.140
transport_(477)%dipole=  0.000
transport_(477)%polar=  0.000
transport_(477)%collision=  1.000
transport_(477)%MW= 89.071
 
transport_(478)%nome='CH2OOCH2CHO'
transport_(478)%geometry=2
transport_(478)%LJpotential=407.800
transport_(478)%LJdiameter=  4.140
transport_(478)%dipole=  0.000
transport_(478)%polar=  0.000
transport_(478)%collision=  1.000
transport_(478)%MW= 89.071
 
transport_(479)%nome='CH2CHOOHCHO'
transport_(479)%geometry=2
transport_(479)%LJpotential=407.800
transport_(479)%LJdiameter=  4.140
transport_(479)%dipole=  0.000
transport_(479)%polar=  0.000
transport_(479)%collision=  1.000
transport_(479)%MW= 89.071
 
transport_(480)%nome='CH3CHOOCHO'
transport_(480)%geometry=2
transport_(480)%LJpotential=407.800
transport_(480)%LJdiameter=  4.140
transport_(480)%dipole=  0.000
transport_(480)%polar=  0.000
transport_(480)%collision=  1.000
transport_(480)%MW= 89.071
 
transport_(481)%nome='CH2OOHCHOOCHO'
transport_(481)%geometry=2
transport_(481)%LJpotential=407.800
transport_(481)%LJdiameter=  4.140
transport_(481)%dipole=  0.000
transport_(481)%polar=  0.000
transport_(481)%collision=  1.000
transport_(481)%MW=121.070
 
transport_(482)%nome='CH2OOCHOOHCHO'
transport_(482)%geometry=2
transport_(482)%LJpotential=407.800
transport_(482)%LJdiameter=  4.140
transport_(482)%dipole=  0.000
transport_(482)%polar=  0.000
transport_(482)%collision=  1.000
transport_(482)%MW=121.070
 
transport_(483)%nome='ERC4H8CHO'
transport_(483)%geometry=2
transport_(483)%LJpotential=408.000
transport_(483)%LJdiameter=  5.200
transport_(483)%dipole=  0.000
transport_(483)%polar=  0.000
transport_(483)%collision=  1.000
transport_(483)%MW= 85.126
end subroutine transport_update
