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
#   ASALI is free software you can redistribute it and/or modify                               #
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

double MaxElement(const std::vector<double> v)
{
    double max = 0.;
    
    for (unsigned int i=0;i<v.size();i++)
        max = std::max(v[i],max);
        
    return max;
}

double MinElement(const std::vector<double> v)
{
    double min = 1e64;
    
    for (unsigned int i=0;i<v.size();i++)
        min = std::min(v[i],min);
        
    return min;
}

double SumElements(const std::vector<double> v)
{
    double sum = 0.;
    
    for (unsigned int i=0;i<v.size();i++)
        sum = sum + v[i];
        
    return sum;
}

double MeanValue(const std::vector<double> v)
{
    return SumElements(v)/v.size();
}

double DotProduct(const std::vector<double> a,const std::vector<double> b)
{
    return std::inner_product(a.begin(), a.end(), b.begin(),0);
}

std::vector<double> ElementByElementProduct(const std::vector<double> a,const std::vector<double> b)
{
    std::vector<double> c(a.size());

    for (unsigned int i=0;i<a.size();i++)
        c[i] = a[i]*b[i];

    return c;
}
