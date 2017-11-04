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

#include "IdealReactors.h"

namespace ASALI
{
    IdealReactors::IdealReactors(unsigned int NC,
             unsigned int NR):
    NC_(NC),
    NR_(NR)
    {
        if ( NR_ != 0 )
        {
            k_.resize(NR_);
            n_.resize(NR_);
            a_.resize(NR_);
            b_.resize(NR_);
            Eatt_.resize(NR_);
            index2_.resize(NR_);
            index1_.resize(NR_);
            stoich_.resize(NR_);
            for (unsigned int i=0;i<NR_;i++)
            {
                stoich_[i].resize(NC_);
            }
        }

        dy_.resize(NC_);
        y_.resize(NC_);
        MW_.resize(NC_);
        R_.resize(NC_);
        
        converter_ = 1.;
        iteration_ = 0;
        t_.push_back(0);
    }

    void IdealReactors::set_T(const double T)
    {
        T_ = T;
    }

    void IdealReactors::set_p(const double p)
    {
        p_ = p;
    }

    void IdealReactors::set_k(const std::vector<double> k)
    {
        k_ = k;
    }

    void IdealReactors::set_Eatt(const std::vector<double> Eatt)
    {
        Eatt_ = Eatt;
    }

    void IdealReactors::set_n(const std::vector<double> n)
    {
        n_ = n;
    }

    void IdealReactors::set_a(const std::vector<double> a)
    {
        a_ = a;
    }

    void IdealReactors::set_b(const std::vector<double> b)
    {
        b_ = b;
    }

    void IdealReactors::set_index(const std::vector<unsigned int> index1,const std::vector<unsigned int> index2)
    {
        index1_ = index1;
        index2_ = index2;
    }
    
    void IdealReactors::set_MW(const std::vector<double> MW)
    {
        MW_ = MW;
    }
    
    void IdealReactors::set_stoich(const std::vector<std::vector<int> > stoich)
    {
        for (unsigned int i=0;i<NR_;i++)
        {
            stoich_[i] = stoich[i];
        }
    }

    void IdealReactors::set_converter(const double converter)
    {
        converter_ = converter;
    }

    void IdealReactors::set_reactor(const std::string reactor)
    {
        reactor_ = reactor;
    }

    void IdealReactors::set_residence_time(const double tau)
    {
        tau_ = tau;
        dt_  = tau_/100.;
    }

    void IdealReactors::set_inlet(const std::vector<double> rho0)
    {
        rho0_ = rho0;
        r_.push_back(rho0_);
    }

    std::vector<double> IdealReactors::reactionRate(const std::vector<double> rho)
    {
        std::vector<double> R(NC_);
        for (unsigned int i=0;i<NC_;i++)
        {
            R[i] = 0.;
            if ( NR_ != 0 )
            {
                for (unsigned int j=0;j<NR_;j++)
                {
                    R[i] = R[i] + stoich_[j][i]*k_[j]*std::pow(T_,n_[i])*std::exp(-Eatt_[j]/(8314*T_))*std::pow(rho[index1_[j]]*converter_/MW_[index1_[j]],a_[j])*std::pow(rho[index2_[j]]*converter_/MW_[index2_[j]],b_[j]);
                }
                R[i] = R[i]/converter_;
            }
        }
        return R;
    }

    void IdealReactors::equations(std::vector<double> &dy, const std::vector<double> y,const double t)
    {

        R_ = this->reactionRate(y);

        if ( reactor_ == "PFR" || reactor_ == "BATCH" )
        {
            for (unsigned int i=0;i<NC_;i++)
            {
                dy_[i] = R_[i]*MW_[i];
            }
        }
        else if ( reactor_ == "CSTR" )
        {
            for (unsigned int i=0;i<NC_;i++)
            {
                dy_[i] = (rho0_[i] - y_[i])/tau_ + R_[i]*MW_[i];
            }
        }
        dy = dy_;
    }
    
    
    void IdealReactors::print(std::vector<double> &dy, const std::vector<double> y,const double t)
    {
        if ( t > dt_*iteration_)
        {
            t_.push_back(t);
            r_.push_back(y);
            iteration_++;
        }
        
        if ( t/tau_ < 0.1 )
        {
            std::cout << "\r" << "|                              |" << int(t*100./tau_) << "%" << std::flush;
        }
        else if ( t/tau_ >= 0.1 && t/tau_ < 0.2 )
        {
            std::cout << "\r" << "|===                           |" << int(t*100./tau_) << "%" << std::flush;
        }
        else if ( t/tau_ >= 0.2 && t/tau_ < 0.3 )
        {
            std::cout << "\r" << "|======                        |" << int(t*100./tau_) << "%" << std::flush;
        }
        else if ( t/tau_ >= 0.3 && t/tau_ < 0.4 )
        {
            std::cout << "\r" << "|=========                     |" << int(t*100./tau_) << "%" << std::flush;
        }
        else if ( t/tau_ >= 0.4 && t/tau_ < 0.5 )
        {
            std::cout << "\r" << "|============                  |" << int(t*100./tau_) << "%" << std::flush;
        }
        else if ( t/tau_ >= 0.5 && t/tau_ < 0.6 )
        {
            std::cout << "\r" << "|===============               |" << int(t*100./tau_) << "%" << std::flush;
        }
        else if ( t/tau_ >= 0.6 && t/tau_ < 0.7 )
        {
            std::cout << "\r" << "|==================            |" << int(t*100./tau_) << "%" << std::flush;
        }
        else if ( t/tau_ >= 0.7 && t/tau_ < 0.8 )
        {
            std::cout << "\r" << "|=====================         |" << int(t*100./tau_) << "%" << std::flush;
        }
        else if ( t/tau_ >= 0.8 && t/tau_ < 0.9 )
        {
            std::cout << "\r" << "|========================      |" << int(t*100./tau_) << "%" << std::flush;
        }
        else if ( t/tau_ >= 0.9 && t/tau_ < 1.0 )
        {
            std::cout << "\r" << "|===========================   |" << int(t*100./tau_) << "%" << std::flush;
        }
        else
        {
            std::cout << "\r" << "|==============================|" << "100%" << std::endl;
        }
    }

    IdealReactors::~IdealReactors()
    {
    }
}
