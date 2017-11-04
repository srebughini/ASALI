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

#ifndef IDEALREACTORS_H
#define IDEALREACTORS_H

#include "odeSolver.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctime>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <limits>

namespace ASALI
{
    class IdealReactors: public ASALI::odeSolver
    {
        public:

            IdealReactors(unsigned int NC,
                          unsigned int NR);

            void set_T(const double T);
            void set_p(const double p);
            
            void set_k(const std::vector<double> k);
            void set_Eatt(const std::vector<double> Eatt);
            void set_n(const std::vector<double> n);
            void set_a(const std::vector<double> a);
            void set_b(const std::vector<double> b);
            void set_index(const std::vector<unsigned int> index1,const std::vector<unsigned int> index2);
            void set_MW(const std::vector<double> MW);
            void set_stoich(const std::vector<std::vector<int> > stoich);
            void set_converter(const double converter);
            void set_reactor(const std::string reactor);
            void set_residence_time(const double tau);
            void set_inlet(const std::vector<double> rho0);

            void equations(std::vector<double> &dy, const std::vector<double> y,const double t);
            
            void print(std::vector<double> &dy, const std::vector<double> y,const double t);

            std::vector<double>               getTime()      {return t_;};
            std::vector<std::vector<double> > getResults()   {return r_;};


            virtual ~IdealReactors();
            
        private:
        
            unsigned int        NC_;
            unsigned int        NR_;
            unsigned int        iteration_;

            double              T_;
            double              p_;
            double              converter_;
            double              tau_;
            double              dt_;

            std::vector<double> dy_;
            std::vector<double> y_;
            std::vector<double> k_;
            std::vector<double> n_;
            std::vector<double> Eatt_;
            std::vector<double> a_;
            std::vector<double> b_;
            std::vector<double> MW_;
            std::vector<double> R_;
            std::vector<double> rho0_;
            std::vector<double> t_;
            
            std::vector<std::string> names_;
            
            std::vector<std::vector<int> > stoich_;
            
            std::vector<unsigned int> index1_;
            std::vector<unsigned int> index2_;
            
            std::vector<double> reactionRate(std::vector<double> rho);

            std::string  reactor_;
            
            std::vector<std::vector<double> > r_;
    };
}
#endif
