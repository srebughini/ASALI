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

#include "Asali.hpp"

namespace ASALI
{
    Asali::Asali()
    :pi_(3.14159265358979323846)
    {
        #include "shared/transport.H"
        #include "shared/thermo.H"
        #include "shared/omega11.H"
        #include "shared/omega22.H"

        T_ = 0.;
        p_ = 0.;
        this->refresh();
    }

    //- Return functions
    std::vector<std::string>           Asali::speciesName()                {return name_;}
    std::vector<std::string>           Asali::allSpeciesName()             {return transport_.name;}
    std::vector<double>                Asali::speciesMolecularWeight()     {return MW_;}
    std::vector<double>                Asali::moleFraction()               {return x_;}
    std::vector<double>                Asali::massFraction()               {return y_;}
    std::vector<double>                Asali::speciesViscosity()           {speciesViscosity_();           return mu_;}
    std::vector<double>                Asali::speciesMolarCp()             {speciesCp_();                  return cpmole_;}
    std::vector<double>                Asali::speciesMassCp()              {speciesCp_();                  return cpmass_;}
    std::vector<double>                Asali::speciesMolarEnthalpy()       {speciesH_();                   return hmole_;}
    std::vector<double>                Asali::speciesMassEnthalpy()        {speciesH_();                   return hmass_;}
    std::vector<double>                Asali::speciesMolarEntropy()        {speciesS_();                   return smole_;}
    std::vector<double>                Asali::speciesMassEntropy()         {speciesS_();                   return smass_;}
    std::vector<double>                Asali::speciesThermalConductivity() {speciesThermalConductivity_(); return cond_;}
    std::vector<std::vector<double> >  Asali::binaryDiffusion()            {binaryDiffusion_();            return diff_;}
    unsigned int                       Asali::numberOfSpecies()            {return NC_;}
    unsigned int                       Asali::numberOfAllSpecies()         {return transport_.name.size();}
    double                             Asali::mixtureMolecularWeight()     {return MWmix_;}
    double                             Asali::density()                    {density_();                    return rho_;}

    void Asali::setTemperature(const double T)
    { 
        if (T != T_)
        {
            T_ = T;
            this->refresh();
        }
    }

    void Asali::setPressure(const double p)
    { 
        if (p != p_)
        {
            p_ = p;
            this->refresh();
        }
    }

    void Asali::setMassFraction(const std::vector<double> y)
    {
        if (y_ != y)
        {
            y_ = y;
            if ( NC_ == y_.size() )
            {
                x_.resize(NC_);
                MWmix_ = 0.;
                for (unsigned int i=0;i<NC_;i++)
                {
                    MWmix_ = MWmix_ + y_[i]/MW_[i];
                }

                for (unsigned int i=0;i<NC_;i++)
                {
                    x_[i] = (y_[i]/MW_[i])/MWmix_;
                }

                MWmix_ = 1./MWmix_;

            }
            else
            {
                std::cout << "\nASALI::ERROR" << std::endl;
                std::cout << "Wrong number of species!\n" << std::endl;
                exit(EXIT_FAILURE);
            }
            this->refresh();
        }
    }

    void Asali::setMoleFraction(const std::vector<double> x)
    {
        if ( x_ != x )
        {
            x_ = x;
            if ( NC_ == x_.size() )
            {
                y_.resize(NC_);
                MWmix_ = 0.;
                for (unsigned int i=0;i<NC_;i++)
                {
                    MWmix_ = MWmix_ + x_[i]*MW_[i];
                }
                
                for (unsigned int i=0;i<NC_;i++)
                {
                    y_[i] = x_[i]*MW_[i]/MWmix_;
                }
            }
            else
            {
                std::cout << "\nASALI::ERROR" << std::endl;
                std::cout << "Wrong number of species!\n" << std::endl;
                exit(EXIT_FAILURE);
            }
            this->refresh();
        }
    }
        
    void Asali::setSpecies(const std::vector<std::string> name)
    {
        if ( name_ != name )
        {
            NC_ = name.size();
            this->resize();
            name_ = name;
            for (unsigned int j=0;j<NC_;j++)
            {
                index_[j] = -1;
                for (unsigned int i=0;i<transport_.name.size();i++)
                {
                    if ( name[j] == transport_.name[i] )
                    {
                        index_[j] = i;
                        MW_[j]    = transport_.MW[i];
                        break;
                    }
                }
                
                if ( index_[j] == -1 )
                {
                    std::cout << "\nASALI::ERROR" << std::endl;
                    std::cout << "Specie " << name[j] << " is missing in Asali database!\n" << std::endl;
                    exit(EXIT_FAILURE);
                }
            }
            this->refresh();
        }
    }

    void Asali::speciesViscosity_()     //[Pa*s]
    {
        if ( !mu_update_ )
        {
            double Tr    = 0.;
            double dr    = 0.;
            double sigma = 0.;
            for (unsigned int i=0;i<NC_;i++)
            {
                Tr     = T_/transport_.LJpotential[index_[i]];
                dr     = 0.5*std::pow(transport_.dipole[index_[i]],2.)/(transport_.LJpotential[index_[i]]*1.3806488*std::pow(transport_.LJdiameter[index_[i]],3.));
                dr     = 1e06*dr;
                sigma  = collisionIntegrals22(Tr,dr);
                mu_[i] = (5./16.)*std::sqrt(pi_*1.3806488*T_*MW_[i]*1.66054)/(pi_*sigma*std::pow(transport_.LJdiameter[index_[i]],2.));
                mu_[i] = mu_[i]*1.e-05;
            }
            mu_update_ = true;
        }
    }

    void Asali::speciesThermalConductivity_() //[W/m/K]
    {
        if ( !cond_update_ )
        {
            this->speciesViscosity_();
            this->binaryDiffusion_();
            this->density_();
            this->speciesCp_();

            double A       = 0.;
            double B       = 0.;
            double Zrot    = 0.;
            double cvtrans = 0.;
            double cvrot   = 0.;
            double cvvib   = 0.;
            double ftrans  = 0.;
            double frot    = 0.;
            double fvib    = 0.;
            double rho     = 0.;
            double R       = 8314; //[J/Kmol/K]
            for (unsigned int i=0;i<NC_;i++)
            {
                if (transport_.geometry[index_[i]] == 0 ) //single atom
                {
                    cvtrans = 3.*R*0.5;
                    cvrot   = 0.;
                    cvvib   = 0.;
                }
                else if (transport_.geometry[index_[i]] == 1 ) //linear
                {
                    cvtrans = 3.*R*0.5;
                    cvrot   = R;
                    cvvib   = cpmole_[i] - R - 5.*R*0.5;
                }
                else //non linear
                {
                    cvtrans = 3.*R*0.5;
                    cvrot   = 3.*R*0.5;
                    cvvib   = cpmole_[i] - R - 3.*R;
                }

                rho = p_*MW_[i]/(R * T_);

                A = (5./2.) - rho*diff_[i][i]/mu_[i];

                {
                    double F_T   = 1. + 0.5*std::sqrt(std::pow(pi_,3.)*transport_.LJpotential[index_[i]]/T_)
                                      + (0.25*std::pow(pi_,2.) + 2.)*(transport_.LJpotential[index_[i]]/T_)
                                      + std::sqrt(std::pow(pi_*transport_.LJpotential[index_[i]]/T_,3.));
                    double F_298 = 1. + 0.5*std::sqrt(std::pow(pi_,3.)*transport_.LJpotential[index_[i]]/298.)
                                      + (0.25*std::pow(pi_,2.) + 2.)*(transport_.LJpotential[index_[i]]/298.)
                                      + std::sqrt(std::pow(pi_*transport_.LJpotential[index_[i]]/298.,3.));
                                      
                    Zrot = transport_.collision[index_[i]]*F_298/F_T;
                }

                B = Zrot + (2./pi_)*((5./3.)*(cvrot/R) + rho*diff_[i][i]/mu_[i]);

                ftrans = (5./2.)*(1. - 2.*cvrot*A/(pi_*cvtrans*B));
                frot   = (rho*diff_[i][i]/mu_[i])*(1. + 2.*A/(pi_*B));
                fvib   = rho*diff_[i][i]/mu_[i];

                cond_[i] = mu_[i]*(ftrans*cvtrans + frot*cvrot + fvib*cvvib)/MW_[i];
            }
            cond_update_ = true;
        }
    }

    void Asali::density_() //[kg/m3]
    {
        if ( !rho_update_)
        {
            rho_ = MWmix_*p_/(8314*T_);
            rho_update_ = true;
        }
    }

    void Asali::binaryDiffusion_()  //[m2/s]
    {
        if ( !diff_update_ )
        {
            double MWmix          = 0.;
            double LJpotentialmix = 0.;
            double LJdiametermix  = 0.;
            double dipolemix      = 0.;
            double polarn         = 0.;
            double dipolep        = 0.;
            double chi            = 0.;
            double sigma          = 0.;
            double Tr             = 0.;
            double dr             = 0.;
            for (unsigned int i=0;i<NC_;i++)
            {
                for (unsigned int j=0;j<i;j++)
                {
                    diff_[i][j] = diff_[j][i];
                }

                for (unsigned int j=i;j<NC_;j++)
                {
                    MWmix = MW_[i]*MW_[j]/(MW_[i] + MW_[j]);

                    if ( transport_.polar[index_[i]] == 0. && transport_.polar[index_[j]] == 0. )
                    {
                        LJpotentialmix = std::sqrt(transport_.LJpotential[index_[i]]*transport_.LJpotential[index_[j]]);
                        LJdiametermix  = 0.5*(transport_.LJdiameter[index_[i]] + transport_.LJdiameter[index_[j]]);
                        dipolemix      = std::sqrt(transport_.dipole[index_[i]]*transport_.dipole[index_[j]]);
                    }
                    else if ( transport_.polar[index_[i]] > 0. && transport_.polar[index_[j]] > 0. )
                    {
                        LJpotentialmix = std::sqrt(transport_.LJpotential[index_[i]]*transport_.LJpotential[index_[j]]);
                        LJdiametermix  = 0.5*(transport_.LJdiameter[index_[i]] + transport_.LJdiameter[index_[j]]);
                        dipolemix      = std::sqrt(transport_.dipole[index_[i]]*transport_.dipole[index_[j]]);
                    }
                    else
                    {
                        polarn  = 0.;
                        dipolep = 0.;
                        if ( transport_.polar[index_[i]] == 0. )
                        {
                            polarn  = transport_.polar[index_[i]]/std::pow(transport_.LJdiameter[index_[i]],3.);
                            dipolep = 1e02*transport_.dipole[index_[j]]/std::sqrt(transport_.LJpotential[index_[j]]*1.3806488*std::pow(transport_.LJdiameter[index_[j]],3.));
                            chi     = 1. + 0.25*polarn*dipolep*std::sqrt(transport_.LJpotential[index_[j]]/transport_.LJpotential[index_[i]]);
                        }
                        else
                        {
                            polarn  = transport_.polar[index_[j]]/std::pow(transport_.LJdiameter[index_[j]],3.);
                            dipolep = 1e02*transport_.dipole[index_[i]]/std::sqrt(transport_.LJpotential[index_[i]]*1.3806488*std::pow(transport_.LJdiameter[index_[i]],3.));
                            chi     = 1. + 0.25*polarn*dipolep*std::sqrt(transport_.LJpotential[index_[i]]/transport_.LJpotential[index_[j]]);
                        }
                        LJpotentialmix = std::pow(chi,2.)*std::sqrt(transport_.LJpotential[index_[i]]*transport_.LJpotential[index_[j]]);
                        LJdiametermix  = 0.5*(transport_.LJdiameter[index_[i]] + transport_.LJdiameter[index_[j]])*std::pow(chi,-1./6.);
                        dipolemix      = 0.;
                    }
                
                    Tr          = T_/LJpotentialmix;
                    dr          = 0.5*std::pow(dipolemix,2.)/(LJpotentialmix*1.3806488*std::pow(LJdiametermix,3.));
                    dr          = 1e06*dr;
                    sigma       = collisionIntegrals11(Tr,dr);
                    diff_[i][j] = (3./16.)*std::sqrt(2.*pi_*std::pow(1.3806488*T_,3.)/(MWmix*1.66054))/(p_*pi_*std::pow(LJdiametermix,2.)*sigma);
                    diff_[i][j] = diff_[i][j]*0.1;
                }
            }
            diff_update_ = true;
        }
    }

    double Asali::collisionIntegrals11(const double Tr,const double dr)
    {
        std::vector<double> b(4);
        std::vector<double> x(4);
        int Ta = -1;
        int Tb = -1;

        for (unsigned int j=0;j<(Tsigma11_.size()-1);j++)
        {
            if ( Tr >= Tsigma11_[j] && Tr < Tsigma11_[j+1])
            {
                Ta = j;
                Tb = j + 1;
                break;
            }
        }

        if ( Ta == -1 )
        {
            if ( Tr <= Tsigma11_[0] )
            {
                Ta = 0;
                Tb = 1;
            }
            else if ( Tr >= Tsigma11_[Tsigma11_.size()-1] ) 
            {
                Ta = Tsigma11_.size() - 2;
                Tb = Tsigma11_.size() - 1;
            }
        }

        int da = -1;
        int db = -1;

        for (unsigned int j=0;j<dsigma11_.size();j++)
        {
            if ( dr >= dsigma11_[j] && dr < dsigma11_[j+1])
            {
                da = j;
                db = j + 1;
                break;
            }
        }

        if ( da == -1 )
        {
            if ( dr <= dsigma11_[0] )
            {
                da = 0;
                db = 1;
            }
            else if ( dr >= dsigma11_[dsigma11_.size()-1] ) 
            {
                da = dsigma11_.size() - 2;
                db = dsigma11_.size() - 1;
            }
        }

        b[0] = sigmaMatrix11_[Ta][da];
        b[1] = sigmaMatrix11_[Ta][db];
        b[2] = sigmaMatrix11_[Tb][da];
        b[3] = sigmaMatrix11_[Tb][db];

        x[3] = (b[0] - b[1]- b[2] + b[3])/(Tsigma11_[Ta]*dsigma11_[da] - Tsigma11_[Ta]*dsigma11_[db] - Tsigma11_[Tb]*dsigma11_[da] + Tsigma11_[Tb]*dsigma11_[db]);

        x[2] = (-x[3]*(Tsigma11_[Ta]*dsigma11_[da] - Tsigma11_[Ta]*dsigma11_[db]) - b[1] + b[0])/(dsigma11_[da] - dsigma11_[db]);

        x[1] = (-x[3]*(Tsigma11_[Ta]*dsigma11_[da] - Tsigma11_[Tb]*dsigma11_[da]) - b[2] + b[0])/(Tsigma11_[Ta] - Tsigma11_[Tb]);

        x[0] = -x[1]*Tsigma11_[Ta] - x[2]*dsigma11_[da] - x[3]*Tsigma11_[Ta]*dsigma11_[da] + b[0];

        return x[0] + x[1]*Tr + x[2]*dr + x[3]*Tr*dr;
    }

    double Asali::collisionIntegrals22(const double Tr,const double dr)
    {
        std::vector<double> b(4);
        std::vector<double> x(4);
        int Ta = -1;
        int Tb = -1;

        for (unsigned int j=0;j<(Tsigma22_.size()-1);j++)
        {
            if ( Tr >= Tsigma22_[j] && Tr < Tsigma22_[j+1])
            {
                Ta = j;
                Tb = j + 1;
                break;
            }
        }

        if ( Ta == -1 )
        {
            if ( Tr <= Tsigma22_[0] )
            {
                Ta = 0;
                Tb = 1;
            }
            else if ( Tr >= Tsigma22_[Tsigma22_.size()-1] ) 
            {
                Ta = Tsigma22_.size() - 2;
                Tb = Tsigma22_.size() - 1;
            }
        }

        int da = -1;
        int db = -1;

        for (unsigned int j=0;j<dsigma22_.size()-1;j++)
        {
            if ( dr >= dsigma22_[j] && dr < dsigma22_[j+1])
            {
                da = j;
                db = j + 1;
                break;
            }
        }

        if ( da == -1 )
        {
            if ( dr <= dsigma22_[0] )
            {
                da = 0;
                db = 1;
            }
            else if ( dr >= dsigma22_[dsigma22_.size()-1] ) 
            {
                da = dsigma22_.size() - 2;
                db = dsigma22_.size() - 1;
            }
        }

        b[0] = sigmaMatrix22_[Ta][da];
        b[1] = sigmaMatrix22_[Ta][db];
        b[2] = sigmaMatrix22_[Tb][da];
        b[3] = sigmaMatrix22_[Tb][db];

        x[3] = (b[0] - b[1]- b[2] + b[3])/(Tsigma22_[Ta]*dsigma22_[da] - Tsigma22_[Ta]*dsigma22_[db] - Tsigma22_[Tb]*dsigma22_[da] + Tsigma22_[Tb]*dsigma22_[db]);

        x[2] = (-x[3]*(Tsigma22_[Ta]*dsigma22_[da] - Tsigma22_[Ta]*dsigma22_[db]) - b[1] + b[0])/(dsigma22_[da] - dsigma22_[db]);

        x[1] = (-x[3]*(Tsigma22_[Ta]*dsigma22_[da] - Tsigma22_[Tb]*dsigma22_[da]) - b[2] + b[0])/(Tsigma22_[Ta] - Tsigma22_[Tb]);

        x[0] = -x[1]*Tsigma22_[Ta] - x[2]*dsigma22_[da] - x[3]*Tsigma22_[Ta]*dsigma22_[da] + b[0];

        return x[0] + x[1]*Tr + x[2]*dr + x[3]*Tr*dr;
    }

    void Asali::speciesCp_()
    {
        if ( !cp_update_ )
        {
            for(unsigned int i=0;i<NC_;i++)
            {
                if ( T_ < 1000. )
                {
                    cpmole_[i] = thermo_.low[index_[i]][0]
                               + thermo_.low[index_[i]][1]*T_ 
                               + thermo_.low[index_[i]][2]*std::pow(T_,2.)
                               + thermo_.low[index_[i]][3]*std::pow(T_,3.)
                               + thermo_.low[index_[i]][4]*std::pow(T_,4.);
                }
                else
                {
                    cpmole_[i] = thermo_.high[index_[i]][0]
                               + thermo_.high[index_[i]][1]*T_ 
                               + thermo_.high[index_[i]][2]*std::pow(T_,2.)
                               + thermo_.high[index_[i]][3]*std::pow(T_,3.)
                               + thermo_.high[index_[i]][4]*std::pow(T_,4.);
                }
                
                cpmole_[i] = cpmole_[i]*8314.;  //J/Kmol/K
                cpmass_[i] = cpmole_[i]/MW_[i]; //J/Kg/K
            }
            cp_update_ = true;
        }
    }

    void Asali::speciesH_()
    {
        if ( !h_update_ )
        {
            for(unsigned int i=0;i<NC_;i++)
            {
                if ( T_ < 1000. )
                {
                    hmole_[i] = thermo_.low[index_[i]][0]
                              + thermo_.low[index_[i]][1]*T_/2.
                              + thermo_.low[index_[i]][2]*std::pow(T_,2.)/3.
                              + thermo_.low[index_[i]][3]*std::pow(T_,3.)/4.
                              + thermo_.low[index_[i]][4]*std::pow(T_,4.)/5.
                              + thermo_.low[index_[i]][5]/T_;
                }
                else
                {
                    hmole_[i] = thermo_.high[index_[i]][0]
                              + thermo_.high[index_[i]][1]*T_/2.
                              + thermo_.high[index_[i]][2]*std::pow(T_,2.)/3.
                              + thermo_.high[index_[i]][3]*std::pow(T_,3.)/4.
                              + thermo_.high[index_[i]][4]*std::pow(T_,4.)/5.
                              + thermo_.high[index_[i]][5]/T_;
                }

                hmole_[i] = hmole_[i]*8314.*T_;  //J/Kmol
                hmass_[i] = hmole_[i]/MW_[i]; //J/Kg
            }
            h_update_ = true;
        }
    }

    void Asali::speciesS_()
    {
        if ( !s_update_ )
        {
            for(unsigned int i=0;i<NC_;i++)
            {
                if ( T_ < 1000. )
                {
                    smole_[i] = thermo_.low[index_[i]][0]*std::log(T_)
                              + thermo_.low[index_[i]][1]*T_
                              + thermo_.low[index_[i]][2]*std::pow(T_,2.)/2.
                              + thermo_.low[index_[i]][3]*std::pow(T_,3.)/3.
                              + thermo_.low[index_[i]][4]*std::pow(T_,4.)/4.
                              + thermo_.low[index_[i]][6];
                }
                else
                {
                    smole_[i] = thermo_.high[index_[i]][0]*std::log(T_)
                              + thermo_.high[index_[i]][1]*T_
                              + thermo_.high[index_[i]][2]*std::pow(T_,2.)/2.
                              + thermo_.high[index_[i]][3]*std::pow(T_,3.)/3.
                              + thermo_.high[index_[i]][4]*std::pow(T_,4.)/4.
                              + thermo_.high[index_[i]][6];
                }

                smole_[i] = 8314.*(smole_[i] - std::log(p_*x_[i]/1.e05));  //J/Kmol/K
                smass_[i] = smole_[i]/MW_[i]; //J/Kg/K
            }
            s_update_ = true;
        }
    }

    void Asali::resize()
    {
        index_.resize(NC_);
        y_.resize(NC_);
        x_.resize(NC_);
        name_.resize(NC_);
        MW_.resize(NC_);
        mu_.resize(NC_);
        cond_.resize(NC_);
        cpmole_.resize(NC_);
        cpmass_.resize(NC_);
        hmole_.resize(NC_);
        hmass_.resize(NC_);
        smole_.resize(NC_);
        smass_.resize(NC_);
        diff_.resize(NC_);
        v_.resize(NC_);
        l_.resize(NC_);
        diff_mix_.resize(NC_);

        for (unsigned int i=0;i<NC_;i++)
        {
            diff_[i].resize(NC_);
        }
    }
    
    void Asali::refresh()
    {
        mu_update_   = false;
        diff_update_ = false;
        rho_update_  = false;
        cp_update_   = false;
        h_update_    = false;
        s_update_    = false;
        cond_update_ = false;
        v_update_    = false;
        l_update_    = false;
        mu_mix_update_     = false;
        diff_mix_update_   = false;
        cond_mix_update_   = false;
        cpmole_mix_update_ = false;
        cpmass_mix_update_ = false;
        hmole_mix_update_  = false;
        hmass_mix_update_  = false;
        smole_mix_update_  = false;
    }

    double Asali::mixtureThermalConductivity() //[W/m/K]
    {
        if ( !cond_mix_update_ )
        {
            this->speciesThermalConductivity_();
            double A = 0.;
            double B = 0.;
            for (unsigned int i=0;i<NC_;i++)
            {
                A = A + x_[i]*cond_[i];
                B = B + x_[i]/cond_[i];
            }
            
            cond_mix_ = 0.5*(A + 1./B);
            cond_mix_update_ = true;
        }
        return cond_mix_;
    }
    
    double Asali::mixtureViscosity()     //[Pa*s]
    {
        if ( !mu_mix_update_ )
        {
            this->speciesViscosity_();
            mu_mix_ = 0.;
            double sum   = 0.;
            for(unsigned int k=0;k<NC_;k++)
            {
                sum = 0.;
                for(unsigned int j=0;j<NC_;j++)
                {
                    double phi = (1./std::sqrt(8.))*(1./std::sqrt(1. + MW_[k]/MW_[j]))*std::pow((1. + std::sqrt(mu_[k]/mu_[j])*std::pow(MW_[j]/MW_[k],(1./4.))),2.);
                           sum = sum + x_[j]*phi;
                }
                mu_mix_ = mu_mix_ + x_[k]*mu_[k]/sum;
            }
            mu_mix_update_ = true;
        }

        return mu_mix_;
    }
    
    std::vector<double> Asali::mixtureDiffusion()  //[m2/s]
    {
        if ( !diff_mix_update_ )
        {
            this->binaryDiffusion_();
            for (unsigned int k=0;k<NC_;k++)
            {
                double A = 0;
                double B = 0;
                for (unsigned int j=0;j<NC_;j++)
                {
                    if ( j != k )
                    {
                        A = A + x_[j]*MW_[j];
                        B = B + x_[j]/diff_[j][k];
                    }
                }
                diff_mix_[k] = A/(MWmix_*B);
            }
            diff_mix_update_ = true;
        }

        return diff_mix_;
    }

    std::vector<double> Asali::arithmeticMeanGasVelocity()
    {
        if ( !v_update_ )
        {
            for (unsigned int i=0;i<NC_;i++)
            {
                v_[i] = std::sqrt(8*8314*T_/(pi_*MW_[i]));
            }
            v_update_ = true;
        }
        return v_;
    }
    
    std::vector<double> Asali::meanFreePath()
    {
        if ( !l_update_ )
        {
            for (unsigned int i=0;i<NC_;i++)
            {
                l_[i] = 1.38064852*1e-03*T_/(std::sqrt(2)*p_*std::pow(transport_.LJdiameter[index_[i]],2.));
            }
            l_update_ = true;
        }

        return l_;
    }

    double Asali::mixtureMolarCp()
    {
        if ( !cpmole_mix_update_ )
        {
            this->speciesCp_();
            cpmole_mix_ = 0;
            
            for(unsigned int i=0;i<NC_;i++)
            {
                cpmole_mix_ = cpmole_mix_ + x_[i]*cpmole_[i];
            }
            cpmole_mix_update_ = true;
        }

        return cpmole_mix_;
    }

    double Asali::mixtureMassCp()
    {
        if ( !cpmass_mix_update_ )
        {
            this->speciesCp_();
            cpmass_mix_ = 0;
            
            for(unsigned int i=0;i<NC_;i++)
            {
                cpmass_mix_ = cpmass_mix_ + y_[i]*cpmass_[i];
            }
            cpmass_mix_update_ = true;
        }

        return cpmass_mix_;
    }

    double Asali::mixtureMolarEnthalpy()
    {
        if ( !hmole_mix_update_ )
        {
            speciesH_();
            hmole_mix_ = 0;
            
            for(unsigned int i=0;i<NC_;i++)
            {
                hmole_mix_ = hmole_mix_ + x_[i]*hmole_[i];
            }
            hmole_mix_update_ = true;
        }
        return hmole_mix_;
    }

    double Asali::mixtureMassEnthalpy()
    {
        if ( !hmass_mix_update_ )
        {
            speciesH_();
            hmass_mix_ = 0;
            
            for(unsigned int i=0;i<NC_;i++)
            {
                hmass_mix_ = hmass_mix_ + y_[i]*hmass_[i];
            }
            hmass_mix_update_ = true;
        }
        return hmass_mix_;
    }

    double Asali::mixtureMolarEntropy()
    {
        if ( !smole_mix_update_ )
        {
            speciesS_();
            smole_mix_= 0;
            for(unsigned int i=0;i<NC_;i++)
            {
                smole_mix_ = smole_mix_ + x_[i]*smole_[i];
            }
            smole_mix_update_ = true;
        }
        return smole_mix_;
    }

    double Asali::mixtureMassEntropy()
    {
        smass_mix_ = this->mixtureMolarEntropy()/MWmix_;
        return smass_mix_;
    }

    Asali::~Asali(void)
    {

    }
}
