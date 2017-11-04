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

#include "Properties.h"

namespace ASALI
{
    
    Properties::Properties()
    {
        #include "transport.H"
        #include "thermo.H"
        #include "omega11.H"
        #include "omega22.H"

        T_ = 0.;
        p_ = 0.;
    }

    //- Return functions
    std::vector<std::string>           Properties::speciesName()                {return name_;}
    std::vector<std::string>           Properties::allSpeciesName()             {return transport_.name;}
    std::vector<double>                Properties::speciesMolecularWeight()     {return MW_;}
    std::vector<double>                Properties::moleFraction()               {return x_;}
    std::vector<double>                Properties::massFraction()               {return y_;}
    std::vector<double>                Properties::speciesViscosity()           {speciesViscosity_();           return mu_;}
    std::vector<double>                Properties::speciesMolarCp()             {speciesCp_();                  return cpmole_;}
    std::vector<double>                Properties::speciesMassCp()              {speciesCp_();                  return cpmass_;}
    std::vector<double>                Properties::speciesMolarEnthalpy()       {speciesH_();                   return hmole_;}
    std::vector<double>                Properties::speciesMassEnthalpy()        {speciesH_();                   return hmass_;}
    std::vector<double>                Properties::speciesMolarEntropy()        {speciesS_();                   return smole_;}
    std::vector<double>                Properties::speciesMassEntropy()         {speciesS_();                   return smass_;}
    std::vector<double>                Properties::speciesThermalConductivity() {speciesThermalConductivity_(); return cond_;}
    std::vector<std::vector<double> >  Properties::binaryDiffusion()            {binaryDiffusion_();            return diff_;}
    unsigned int                       Properties::numberOfSpecies()            {return NC_;}
    unsigned int                       Properties::numberOfAllSpecies()         {return transport_.name.size();}
    double                             Properties::mixtureMolecularWeight()     {return MWmix_;}
    double                             Properties::density()                    {density_();                    return rho_;}

    void Properties::setTemperature(const double T) {T_ = T;}
    void Properties::setPressure(const double p)    {p_ = p;}

    void Properties::setMassFraction(const std::vector<double> y)
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
    }

    void Properties::setMoleFraction(const std::vector<double> x)
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
    }
        
    void Properties::setSpecies(const std::vector<std::string> name)
    {
        NC_ = name.size();

        resize();

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
                std::cout << "Specie " << name[j] << " is missing in Properties database!\n" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    void Properties::speciesViscosity_()     //[Pa*s]
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
    }

    void Properties::speciesThermalConductivity_() //[W/m/K]
    {
        speciesViscosity_();
        binaryDiffusion_();
        density_();
        speciesCp_();

        double A       = 0.;
        double B       = 0.;
        double Zrot    = 0.;
        double cvtrans = 0.;
        double cvrot   = 0.;
        double cvvib   = 0.;
        double ftrans  = 0.;
        double frot    = 0.;
        double fvib    = 0.;
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
                cvrot   = R*0.5;
                cvvib   = cpmole_[i] - R - 5.*R*0.5;
            }
            else //non linear
            {
                cvtrans = 3.*R*0.5;
                cvrot   = 3.*R*0.5;
                cvvib   = cpmole_[i] - R - 3.*R;
            }

            A = (5./2.) - rho_*diff_[i][i]/mu_[i];

            {
                double F_T   = 1. + 0.5*std::sqrt(std::pow(pi_,3.)*transport_.LJpotential[index_[i]]/T_)
                                  + (0.25*std::pow(pi_,2.) + 2.)*(transport_.LJpotential[index_[i]]/T_)
                                  + std::sqrt(std::pow(pi_*transport_.LJpotential[index_[i]]/T_,3.));
                double F_298 = 1. + 0.5*std::sqrt(std::pow(pi_,3.)*transport_.LJpotential[index_[i]]/298.)
                                  + (0.25*std::pow(pi_,2.) + 2.)*(transport_.LJpotential[index_[i]]/298.)
                                  + std::sqrt(std::pow(pi_*transport_.LJpotential[index_[i]]/298.,3.));
                                  
                Zrot = transport_.collision[index_[i]]*F_298/F_T;
            }

            B = Zrot + (2./pi_)*((5./3.)*(cvrot/R) + rho_*diff_[i][i]/mu_[i]);
            
            ftrans = (5./2.)*(1. - 2.*cvrot*A/(pi_*cvtrans*B));
            frot   = (rho_*diff_[i][i]/mu_[i])*(1. + 2.*A/(pi_*B));
            fvib   = rho_*diff_[i][i]/mu_[i];

            cond_[i] = mu_[i]*(ftrans*cvtrans + frot*cvrot + fvib*cvvib)/MW_[i];
        }
    }

    void Properties::density_() //[kg/m3]
    {
        rho_ = MWmix_*p_/(8314*T_);
    }

    void Properties::binaryDiffusion_()  //[m2/s]
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
    }

    double Properties::collisionIntegrals11(const double Tr,const double dr)
    {
        Eigen::VectorXd b(4);
        Eigen::VectorXd x(4);
        Eigen::MatrixXd A(4,4);
        {
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
                    Ta = Tsigma11_.size() - 1;
                    Tb = Tsigma11_.size();
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
                    da = dsigma11_.size() - 1;
                    db = dsigma11_.size();
                }
            }

            A << 1.,Tsigma11_[Ta],dsigma11_[da],Tsigma11_[Ta]*dsigma11_[da],
                 1.,Tsigma11_[Ta],dsigma11_[db],Tsigma11_[Ta]*dsigma11_[db],
                 1.,Tsigma11_[Tb],dsigma11_[da],Tsigma11_[Tb]*dsigma11_[da],
                 1.,Tsigma11_[Tb],dsigma11_[db],Tsigma11_[Tb]*dsigma11_[db];


            b(0) = sigmaMatrix11_[Ta][da];
            b(1) = sigmaMatrix11_[Ta][db];
            b(2) = sigmaMatrix11_[Tb][da];
            b(3) = sigmaMatrix11_[Tb][db];


            x = A.fullPivLu().solve(b);

        }

        return x(0) + x(1)*Tr + x(2)*dr + x(3)*Tr*dr;
    }

    double Properties::collisionIntegrals22(const double Tr,const double dr)
    {
        Eigen::VectorXd b(4);
        Eigen::VectorXd x(4);
        Eigen::MatrixXd A(4,4);
        {
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
                    Ta = Tsigma22_.size() - 1;
                    Tb = Tsigma22_.size();
                }
            }

            int da = -1;
            int db = -1;

            for (unsigned int j=0;j<dsigma22_.size();j++)
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
                    da = dsigma22_.size() - 1;
                    db = dsigma22_.size();
                }
            }

            A << 1.,Tsigma22_[Ta],dsigma22_[da],Tsigma22_[Ta]*dsigma22_[da],
                 1.,Tsigma22_[Ta],dsigma22_[db],Tsigma22_[Ta]*dsigma22_[db],
                 1.,Tsigma22_[Tb],dsigma22_[da],Tsigma22_[Tb]*dsigma22_[da],
                 1.,Tsigma22_[Tb],dsigma22_[db],Tsigma22_[Tb]*dsigma22_[db];


            b(0) = sigmaMatrix22_[Ta][da];
            b(1) = sigmaMatrix22_[Ta][db];
            b(2) = sigmaMatrix22_[Tb][da];
            b(3) = sigmaMatrix22_[Tb][db];


            x = A.fullPivLu().solve(b);

        }

        return x(0) + x(1)*Tr + x(2)*dr + x(3)*Tr*dr;
    }

    void Properties::speciesCp_()
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
            cpmass_[i] = cpmole_[i]*MW_[i]; //J/Kg/K
        }
    }

    void Properties::speciesH_()
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
            hmass_[i] = hmole_[i]*MW_[i]; //J/Kg
        }
    }

    void Properties::speciesS_()
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

            smole_[i] = smole_[i]*8314.;  //J/Kmol/K
            smass_[i] = smole_[i]*MW_[i]; //J/Kg/K
        }
    }

    void Properties::resize()
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

        for (unsigned int i=0;i<NC_;i++)
        {
            diff_[i].resize(NC_);
        }
    }

    double Properties::mixtureThermalConductivity() //[W/m/K]
    {
        speciesThermalConductivity_();
        double A = 0.;
        double B = 0.;
        for (unsigned int i=0;i<NC_;i++)
        {
            A = A + x_[i]*cond_[i];
            B = B + x_[i]/cond_[i];
        }
        
        return 0.5*(A + 1./B);
    }
    
    double Properties::mixtureViscosity()     //[Pa*s]
    {
        speciesViscosity_();
        double mumix = 0.;
        double sum   = 0.;
        for(unsigned int k=0;k<NC_;k++)
        {
            sum = 0.;
            for(unsigned int j=0;j<NC_;j++)
            {
                double phi = (1./std::sqrt(8.))*(1./std::sqrt(1. + MW_[k]/MW_[j]))*std::pow((1. + std::sqrt(mu_[k]/mu_[j])*std::pow(MW_[j]/MW_[k],(1./4.))),2.);
                       sum = sum + x_[j]*phi;
            }
            mumix = mumix + x_[k]*mu_[k]/sum;
        }

        return mumix;
    }
    
    std::vector<double> Properties::mixtureDiffusion()  //[m2/s]
    {
        std::vector<double> diffmix(NC_);
        binaryDiffusion_();
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
            diffmix[k] = A/(MWmix_*B);
        }

        return diffmix;
    }


    std::vector<double> Properties::aritmeticMeanGasVelocity()
    {
        std::vector<double> v(NC_);

        for (unsigned int i=0;i<NC_;i++)
        {
            v[i] = std::sqrt(8*8314*T_/(pi_*MW_[i]));
        }

        return v;
    }
    
    std::vector<double> Properties::meanFreePath()
    {
        std::vector<double> l(NC_);

        for (unsigned int i=0;i<NC_;i++)
        {
            l[i] = 1.38064852*1e-03*T_/(std::sqrt(2)*p_*std::pow(transport_.LJdiameter[index_[i]],2.));
        }

        return l;
    }

    double Properties::mixtureMolarCp()
    {
        speciesCp_();
        double cpmix = 0;
        
        for(unsigned int i=0;i<NC_;i++)
        {
            cpmix = cpmix + x_[i]*cpmole_[i];
        }

        return cpmix;
    }

    double Properties::mixtureMassCp()
    {
        speciesCp_();
        double cpmix = 0;
        
        for(unsigned int i=0;i<NC_;i++)
        {
            cpmix = cpmix + y_[i]*cpmass_[i];
        }

        return cpmix;
    }

    double Properties::mixtureMolarEnthalpy()
    {
        speciesH_();
        double hmix = 0;
        
        for(unsigned int i=0;i<NC_;i++)
        {
            hmix = hmix + x_[i]*hmole_[i];
        }

        return hmix;
    }

    double Properties::mixtureMassEnthalpy()
    {
        speciesH_();
        double hmix = 0;
        
        for(unsigned int i=0;i<NC_;i++)
        {
            hmix = hmix + y_[i]*hmass_[i];
        }

        return hmix;
    }

    double Properties::mixtureMolarEntropy()
    {
        speciesS_();
        double smix = 0;
        
        for(unsigned int i=0;i<NC_;i++)
        {
            smix = smix + x_[i]*smole_[i];
        }

        return smix;
    }

    double Properties::mixtureMassEntropy()
    {
        speciesS_();
        double smix = 0;
        
        for(unsigned int i=0;i<NC_;i++)
        {
            smix = smix + y_[i]*smass_[i];
        }

        return smix;
    }

    Properties::~Properties(void)
    {

    }
}
