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

#include "odeSolver.h"

namespace ASALI
{
    odeSolver::odeSolver()
    {
        NE_     = 0;
    }
    
    void odeSolver::setInitialConditions(const std::vector<double> y,const double t)
    {
        NE_ = y.size();
        y_  = y;
        t_  = t;

        dy_.resize(NE_);
        this->equations(dy_,y_,t_);
    }
    
    void odeSolver::solve(std::vector<double> &yEnd,const double tEnd)
    {
        while ( t_ < tEnd )
        {
            if (this->eigenValue(y_) == 0.)
            {
                h_ = tEnd/100.;
            }
            else
            {
                h_ = -1./this->eigenValue(y_);
            }

            t_ = t_ + h_;

            for (unsigned int i=0;i<NE_;i++)
            {
                y_[i] = y_[i] + h_*dy_[i];
            }

            this->equations(dy_,y_,t_);

            this->print(dy_,y_,t_);
        }
        yEnd = y_;
    }
    
    
    double odeSolver::eigenValue(const std::vector<double> y)
    {
        const double ZERO_DER = std::sqrt(FLT_EPSILON);
        const double ETA2     = std::sqrt(DBL_EPSILON);
        const double TOLR     = 1.e-7;
        const double TOLA     = 1.e-12;

        std::vector<double> y_plus(NE_);
        std::vector<double> dy_plus(NE_);
        std::vector<double> dy_original(NE_);
        Eigen::MatrixXd     J(NE_,NE_);

        y_plus = y;

        this->equations(dy_original,y,0.);     

        for(unsigned int i=0;i<NE_;i++)
        {
            double hf           = 1.e0;
            double error_weight = 1./(TOLA+TOLR*fabs(y[i]));
            double hJ           = ETA2 * fabs(std::max(y[i], 1./error_weight));
            double hJf          = hf/error_weight;
            hJ = std::max(hJ, hJf);
            hJ = std::max(hJ, ZERO_DER);

            double dy  = std::min(hJ, 1.e-3 + 1e-3*fabs(y[i]));
            double udy = 1. / dy;
            y_plus[i] += dy;

            this->equations(dy_plus,y_plus,0.);

            for(unsigned int j=0;j<NE_;j++)
            {
                J(j,i) = (dy_plus[j]-dy_original[j]) * udy;
            }

            y_plus[i] = y[i];
        }

        
        Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> es(J);
        Eigen::VectorXd                                eig = es.eigenvalues();

        return eig.minCoeff();
    }


    odeSolver::~odeSolver()
    {
    }
}
