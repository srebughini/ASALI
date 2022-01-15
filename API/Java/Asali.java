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

import java.io.*; 
import java.util.*;
import java.lang.*;

public class Asali 
{
    double T_           = 0.;
    double p_           = 0.;
    double MWmix_       = 0.;
    double rho_         = 0.;
    double pi_          = 3.14159265358979323846;
    double cond_mix_    = 0.;
    double mu_mix_      = 0.;
    double cp_mole_mix_ = 0.;
    double cp_mass_mix_ = 0.;
    double h_mole_mix_  = 0.;
    double h_mass_mix_  = 0.;
    double s_mole_mix_  = 0.;
    double s_mass_mix_  = 0.;

    int NC_ = 0;
    
    boolean mu_updated_       = false;
    boolean rho_updated_      = false;
    boolean diff_updated_     = false;
    boolean cp_updated_       = false;
    boolean h_updated_        = false;
    boolean s_updated_        = false;
    boolean cond_updated_     = false;
    boolean cond_mix_updated_ = false;
    boolean mu_mix_updated_   = false;
    boolean diff_mix_updated_ = false;
    boolean v_updated_        = false;
    boolean l_updated_        = false;
    boolean cp_mix_updated_   = false;
    boolean h_mix_updated_    = false;
    boolean s_mix_updated_    = false;

    String [] names_;

    double [] MW_;
    double [] x_;
    double [] y_;
    double [] mu_;
    double [] cond_;
    double [] cp_mass_;
    double [] cp_mole_;
    double [] h_mass_;
    double [] h_mole_;
    double [] s_mass_;
    double [] s_mole_;
    double [] diff_mix_;
    double [] v_;
    double [] l_;
    
    double [][] diff_;

    int [] index_;

    ThermoDatabase    thermo_    = new ThermoDatabase();
    TransportDatabase transport_ = new TransportDatabase();
    OmegaDatabase     omega_     = new OmegaDatabase();

    void set_temperature(double T)
    {
        if ( T_ != T )
        {
            T_ = T;
            mu_updated_       = false;
            rho_updated_      = false;
            diff_updated_     = false;
            cp_updated_       = false;
            h_updated_        = false;
            s_updated_        = false;
            cond_updated_     = false;
            cond_mix_updated_ = false;
            mu_mix_updated_   = false;
            diff_mix_updated_ = false;
            v_updated_        = false;
            l_updated_        = false;
            cp_mix_updated_   = false;
            h_mix_updated_    = false;
            s_mix_updated_    = false;
        }
    }

    void set_pressure(double p)
    {
        if ( p_ != p )
        {
            p_ = p;
            mu_updated_       = false;
            rho_updated_      = false;
            diff_updated_     = false;
            cp_updated_       = false;
            h_updated_        = false;
            s_updated_        = false;
            cond_updated_     = false;
            cond_mix_updated_ = false;
            mu_mix_updated_   = false;
            diff_mix_updated_ = false;
            v_updated_        = false;
            l_updated_        = false;
            cp_mix_updated_   = false;
            h_mix_updated_    = false;
            s_mix_updated_    = false;
        }
    }
    
    void set_number_of_species(int NC)
    {
        if ( NC_ != NC )
        {
            NC_ = NC;
            this.resize();
            mu_updated_       = false;
            rho_updated_      = false;
            diff_updated_     = false;
            cp_updated_       = false;
            h_updated_        = false;
            s_updated_        = false;
            cond_updated_     = false;
            cond_mix_updated_ = false;
            mu_mix_updated_   = false;
            diff_mix_updated_ = false;
            v_updated_        = false;
            l_updated_        = false;
            cp_mix_updated_   = false;
            h_mix_updated_    = false;
            s_mix_updated_    = false;
        }
    }
    
    void set_species_names(String [] names)
    {
        this.set_species_names_(names);
    }
    
    void set_species_names(ArrayList<String> names)
    {
        this.set_species_names_(Arrays.copyOf(names.toArray(), names.size(), String[].class));
    }

    void set_species_names(Vector<String> names)
    {
        this.set_species_names_(Arrays.copyOf(names.toArray(), names.size(), String[].class));
    }
    
    void set_mass_fraction(double [] y)
    {
        this.set_mass_fraction_(y);
    }

    void set_mass_fraction(List<Double> y)
    {
        double[] y_new = new double[y.size()];
        for (int i = 0; i < y_new.length; i++)
        {
            y_new[i] = y.get(i);
        }
        this.set_mass_fraction_(y_new);
    }

    void set_mass_fraction(Vector<Double> y)
    {
        double[] y_new = new double[y.size()];
        for (int i = 0; i < y_new.length; i++)
        {
            y_new[i] = y.get(i);
        }
        this.set_mass_fraction_(y_new);
    }

    void set_mole_fraction(double [] x)
    {
        this.set_mole_fraction_(x);
    }

    void set_mole_fraction(List<Double> x)
    {
        double[] x_new = new double[x.size()];
        for (int i = 0; i < x_new.length; i++)
        {
            x_new[i] = x.get(i);
        }
        this.set_mole_fraction_(x_new);
    }

    void set_mole_fraction(Vector<Double> x)
    {
        double[] x_new = new double[x.size()];
        for (int i = 0; i < x_new.length; i++)
        {
            x_new[i] = x.get(i);
        }
        this.set_mole_fraction_(x_new);
    }
    
    double [] get_mass_fraction()
    {
        return y_;
    }
    
    double [] get_mole_fraction()
    {
        return x_;
    }
    
    double [] get_species_viscosity()
    {
        this.species_viscosity_();
        return mu_;
    }
    
    double get_mixture_molecular_weight()
    {
        return MWmix_;
    }
    
    double get_density()
    {
        this.density_();
        return rho_;
    }
    
    double [][] get_binary_diffusion()
    {
        this.binary_diffusion_();
        return diff_;
    }
    
    double [] get_species_mass_specific_heat()
    {
        this.species_cp_();
        return cp_mass_;
    }

    double [] get_species_molar_specific_heat()
    {
        this.species_cp_();
        return cp_mole_;
    }

    double [] get_species_mass_enthalpy()
    {
        this.species_h_();
        return h_mass_;
    }

    double [] get_species_molar_enthalpy()
    {
        this.species_h_();
        return h_mole_;
    }

    double [] get_species_mass_entropy()
    {
        this.species_s_();
        return s_mass_;
    }

    double [] get_species_molar_entropy()
    {
        this.species_s_();
        return s_mole_;
    }
    
    double [] get_species_thermal_conductivity()
    {
        this.species_thermal_conductivity_();
        return cond_;
    }

    double get_mixture_thermal_conductivity() //[W/m/K]
    {
        if ( !cond_mix_updated_ )
        {
            this.species_thermal_conductivity_();
            double A = 0.;
            double B = 0.;
            for (int i=0;i<NC_;i++)
            {
                A = A + x_[i]*cond_[i];
                B = B + x_[i]/cond_[i];
            }
            
            cond_mix_ = 0.5*(A + 1./B);
            cond_mix_updated_ = true;
        }
        return cond_mix_;
    }

    double get_mixture_viscosity() //[Pa*s]
    {
        if ( !mu_mix_updated_ )
        {
            this.species_viscosity_();
            mu_mix_ = 0.;
            double sum   = 0.;
            for(int k=0;k<NC_;k++)
            {
                sum = 0.;
                for(int j=0;j<NC_;j++)
                {
                    double phi = (1./Math.sqrt(8.))*(1./Math.sqrt(1. + MW_[k]/MW_[j]))*Math.pow((1. + Math.sqrt(mu_[k]/mu_[j])*Math.pow(MW_[j]/MW_[k],(1./4.))),2.);
                           sum = sum + x_[j]*phi;
                }
                mu_mix_ = mu_mix_ + x_[k]*mu_[k]/sum;
            }
            mu_mix_updated_ = true;
        }

        return mu_mix_;
    }

    double [] get_mixture_diffusion()  //[m2/s]
    {
        if ( !diff_mix_updated_ )
        {
            this.binary_diffusion_();
            for (int k=0;k<NC_;k++)
            {
                double A = 0;
                double B = 0;
                for (int j=0;j<NC_;j++)
                {
                    if ( j != k )
                    {
                        A = A + x_[j]*MW_[j];
                        B = B + x_[j]/diff_[j][k];
                    }
                }
                diff_mix_[k] = A/(MWmix_*B);
            }
            diff_mix_updated_ = true;
        }

        return diff_mix_;
    }

    double get_mixture_molar_specific_heat()
    {
        this.mixture_cp_();
        return cp_mole_mix_;
    }

    double get_mixture_mass_specific_heat()
    {
        this.mixture_cp_();
        return cp_mass_mix_;
    }

    double get_mixture_molar_enthalpy()
    {
        this.mixture_h_();
        return h_mole_mix_;
    }

    double get_mixture_mass_enthalpy()
    {
        this.mixture_h_();
        return h_mass_mix_;
    }

    double get_mixture_molar_entropy()
    {
        this.mixture_s_();
        return s_mole_mix_;
    }

    double get_mixture_mass_entropy()
    {
        this.mixture_s_();
        return s_mass_mix_;
    }

    double [] get_aritmetic_mean_gas_velocity()
    {
        if ( !v_updated_ )
        {
            for (int i=0;i<NC_;i++)
            {
                v_[i] = Math.sqrt(8*8314*T_/(pi_*MW_[i]));
            }
            v_updated_ = true;
        }
        return v_;
    }

    double [] get_mean_free_path()
    {
        if ( !l_updated_ )
        {
            for (int i=0;i<NC_;i++)
            {
                l_[i] = 1.38064852*1e-03*T_/(Math.sqrt(2)*p_*Math.pow(transport_.LJdiameter()[index_[i]],2.));
            }
            l_updated_ = true;
        }
        return l_;
    }


    private void set_species_names_(String [] names)
    {
        if ( !Arrays.equals(names_, names) )
        {
            if  ( names.length == NC_ )
            {
                for (int i=0;i<NC_;i++)
                {
                    index_[i] = -1;
                    names_[i] = names[i];
                    for (int j=0;j<transport_.names().length;j++)
                    {
                        if ( Objects.equals(names_[i], transport_.names()[j]) )
                        {
                            index_[i] = j;
                            MW_[i] = transport_.MW()[j];
                            break;
                        }
                    }

                    if ( index_[i] == -1 )
                    {
                        System.out.println("ASALI::ERROR --> " + names[i] + " is missing in ASALI database.");
                        System.exit(0);
                    }
                }
                mu_updated_       = false;
                rho_updated_      = false;
                diff_updated_     = false;
                cp_updated_       = false;
                h_updated_        = false;
                s_updated_        = false;
                cond_updated_     = false;
                cond_mix_updated_ = false;
                mu_mix_updated_   = false;
                diff_mix_updated_ = false;
                v_updated_        = false;
                l_updated_        = false;
                cp_mix_updated_   = false;
                h_mix_updated_    = false;
                s_mix_updated_    = false;
            }
            else
            {
                System.out.println("ASALI::ERROR --> Wrong number of species names");
                System.exit(0);
            }
        }
    }
    
    private void set_mass_fraction_(double [] y)
    {
        if ( !Arrays.equals(y_, y) )
        {
            if  ( y.length == NC_ )
            {
                y_ = y;
                MWmix_ = 0.;
                for (int i=0;i<NC_;i++)
                {
                    MWmix_ = MWmix_ + y_[i]/MW_[i];
                }

                for (int i=0;i<NC_;i++)
                {
                    x_[i] = (y_[i]/MW_[i])/MWmix_;
                }
                mu_updated_       = false;
                rho_updated_      = false;
                diff_updated_     = false;
                cp_updated_       = false;
                h_updated_        = false;
                s_updated_        = false;
                cond_updated_     = false;
                cond_mix_updated_ = false;
                mu_mix_updated_   = false;
                diff_mix_updated_ = false;
                v_updated_        = false;
                l_updated_        = false;
                cp_mix_updated_   = false;
                h_mix_updated_    = false;
                s_mix_updated_    = false;
            }
            else
            {
                System.out.println("ASALI::ERROR --> Wrong number of mass fractions");
                System.exit(0);
            }
        }
    }

    private void set_mole_fraction_(double [] x)
    {
        if ( !Arrays.equals(x_, x))
        {
            if  ( x.length == NC_ )
            {
                x_ = x;
                MWmix_ = 0.;
                for (int i=0;i<NC_;i++)
                {
                    MWmix_ = MWmix_ + x_[i]*MW_[i];
                }

                for (int i=0;i<NC_;i++)
                {
                    y_[i] = x_[i]*MW_[i]/MWmix_;
                }
                mu_updated_       = false;
                rho_updated_      = false;
                diff_updated_     = false;
                cp_updated_       = false;
                h_updated_        = false;
                s_updated_        = false;
                cond_updated_     = false;
                cond_mix_updated_ = false;
                mu_mix_updated_   = false;
                diff_mix_updated_ = false;
                v_updated_        = false;
                l_updated_        = false;
                cp_mix_updated_   = false;
                h_mix_updated_    = false;

            }
            else
            {
                System.out.println("ASALI::ERROR --> Wrong number of mole fractions");
                System.exit(0);
            }
        }
    }

    private void density_() //kg/m3
    {
        if ( !rho_updated_ )
        {
            rho_ = MWmix_*p_/(8314*T_);
            rho_updated_ = true;
        }
    }

    private void species_viscosity_() //Pas
    {
        if ( !mu_updated_)
        {
            double Tr    = 0.;
            double dr    = 0.;
            double sigma = 0.;
            for (int i=0;i<NC_;i++)
            {
                Tr     = T_/transport_.LJpotential()[index_[i]];
                dr     = 0.5*Math.pow(transport_.dipole()[index_[i]],2.);
                dr     = dr/(transport_.LJpotential()[index_[i]]*1.3806488*Math.pow(transport_.LJdiameter()[index_[i]],3));
                dr     = 1e06*dr;
                sigma  = this.collision_integrals_22(Tr,dr);
                mu_[i] = (5./16.)*Math.sqrt(pi_*1.3806488*T_*MW_[i]*1.66054)/(pi_*sigma*Math.pow(transport_.LJdiameter()[index_[i]],2.));
                mu_[i] = mu_[i]*1.e-05;
            }
            mu_updated_ = true;
        }
    }

    private void binary_diffusion_()  //[m2/s]
    {
        if ( !diff_updated_ )
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
            for (int i=0;i<NC_;i++)
            {
                for (int j=0;j<i;j++)
                {
                    diff_[i][j] = diff_[j][i];
                }

                for (int j=i;j<NC_;j++)
                {
                    MWmix = MW_[i]*MW_[j]/(MW_[i] + MW_[j]);

                    if ( transport_.polar()[index_[i]] == 0. && transport_.polar()[index_[j]] == 0. )
                    {
                        LJpotentialmix = Math.sqrt(transport_.LJpotential()[index_[i]]*transport_.LJpotential()[index_[j]]);
                        LJdiametermix  = 0.5*(transport_.LJdiameter()[index_[i]] + transport_.LJdiameter()[index_[j]]);
                        dipolemix      = Math.sqrt(transport_.dipole()[index_[i]]*transport_.dipole()[index_[j]]);
                    }
                    else if ( transport_.polar()[index_[i]] > 0. && transport_.polar()[index_[j]] > 0. )
                    {
                        LJpotentialmix = Math.sqrt(transport_.LJpotential()[index_[i]]*transport_.LJpotential()[index_[j]]);
                        LJdiametermix  = 0.5*(transport_.LJdiameter()[index_[i]] + transport_.LJdiameter()[index_[j]]);
                        dipolemix      = Math.sqrt(transport_.dipole()[index_[i]]*transport_.dipole()[index_[j]]);
                    }
                    else
                    {
                        polarn  = 0.;
                        dipolep = 0.;
                        if ( transport_.polar()[index_[i]] == 0. )
                        {
                            polarn  = transport_.polar()[index_[i]]/Math.pow(transport_.LJdiameter()[index_[i]],3.);
                            dipolep = 1e02*transport_.dipole()[index_[j]]/Math.sqrt(transport_.LJpotential()[index_[j]]*1.3806488*Math.pow(transport_.LJdiameter()[index_[j]],3.));
                            chi     = 1. + 0.25*polarn*dipolep*Math.sqrt(transport_.LJpotential()[index_[j]]/transport_.LJpotential()[index_[i]]);
                        }
                        else
                        {
                            polarn  = transport_.polar()[index_[j]]/Math.pow(transport_.LJdiameter()[index_[j]],3.);
                            dipolep = 1e02*transport_.dipole()[index_[i]]/Math.sqrt(transport_.LJpotential()[index_[i]]*1.3806488*Math.pow(transport_.LJdiameter()[index_[i]],3.));
                            chi     = 1. + 0.25*polarn*dipolep*Math.sqrt(transport_.LJpotential()[index_[i]]/transport_.LJpotential()[index_[j]]);
                        }
                        LJpotentialmix = Math.pow(chi,2.)*Math.sqrt(transport_.LJpotential()[index_[i]]*transport_.LJpotential()[index_[j]]);
                        LJdiametermix  = 0.5*(transport_.LJdiameter()[index_[i]] + transport_.LJdiameter()[index_[j]])*Math.pow(chi,-1./6.);
                        dipolemix      = 0.;
                    }
                
                    Tr          = T_/LJpotentialmix;
                    dr          = 0.5*Math.pow(dipolemix,2.)/(LJpotentialmix*1.3806488*Math.pow(LJdiametermix,3.));
                    dr          = 1e06*dr;
                    sigma       = this.collision_integrals_11(Tr,dr);
                    diff_[i][j] = (3./16.)*Math.sqrt(2.*pi_*Math.pow(1.3806488*T_,3.)/(MWmix*1.66054))/(p_*pi_*Math.pow(LJdiametermix,2.)*sigma);
                    diff_[i][j] = diff_[i][j]*0.1;
                }
            }
            diff_updated_ = true;
        }
    }
    
    private void species_thermal_conductivity_() //[W/m/K]
    {
        if ( !cond_updated_ )
        {
            this.species_viscosity_();
            this.binary_diffusion_();
            this.density_();
            this.species_cp_();

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
            double R       = 8314.; //[J/Kmol/K]
            for (int i=0;i<NC_;i++)
            {
                if (transport_.geometry()[index_[i]] == 0 ) //single atom
                {
                    cvtrans = 3.*R*0.5;
                    cvrot   = 0.;
                    cvvib   = 0.;
                }
                else if (transport_.geometry()[index_[i]] == 1 ) //linear
                {
                    cvtrans = 3.*R*0.5;
                    cvrot   = R;
                    cvvib   = cp_mole_[i] - R - 5.*R*0.5;
                }
                else //non linear
                {
                    cvtrans = 3.*R*0.5;
                    cvrot   = 3.*R*0.5;
                    cvvib   = cp_mole_[i] - R - 3.*R;
                }


                rho = p_*MW_[i]/(R*T_);
                A = (5./2.) - rho*diff_[i][i]/mu_[i];

                {
                    double F_T   = 1. + 0.5*Math.sqrt(Math.pow(pi_,3.)*transport_.LJpotential()[index_[i]]/T_)
                                      + (0.25*Math.pow(pi_,2.) + 2.)*(transport_.LJpotential()[index_[i]]/T_)
                                      + Math.sqrt(Math.pow(pi_*transport_.LJpotential()[index_[i]]/T_,3.));
                    double F_298 = 1. + 0.5*Math.sqrt(Math.pow(pi_,3.)*transport_.LJpotential()[index_[i]]/298.)
                                      + (0.25*Math.pow(pi_,2.) + 2.)*(transport_.LJpotential()[index_[i]]/298.)
                                      + Math.sqrt(Math.pow(pi_*transport_.LJpotential()[index_[i]]/298.,3.));
                                      
                    Zrot = transport_.collision()[index_[i]]*F_298/F_T;
                }

                B = Zrot + (2./pi_)*((5./3.)*(cvrot/R) + rho*diff_[i][i]/mu_[i]);
                
                ftrans = (5./2.)*(1. - 2.*cvrot*A/(pi_*cvtrans*B));
                frot   = (rho*diff_[i][i]/mu_[i])*(1. + 2.*A/(pi_*B));
                fvib   = rho*diff_[i][i]/mu_[i];

                cond_[i] = mu_[i]*(ftrans*cvtrans + frot*cvrot + fvib*cvvib)/MW_[i];
            }
            cond_updated_ = true;
        }
    }

    private void species_cp_()
    {
        if ( !cp_updated_ )
        {
            for(int i=0;i<NC_;i++)
            {
                if ( T_ < 1000. )
                {
                    cp_mole_[i] = thermo_.lowA()[index_[i]]
                                + thermo_.lowB()[index_[i]]*T_ 
                                + thermo_.lowC()[index_[i]]*Math.pow(T_,2.)
                                + thermo_.lowD()[index_[i]]*Math.pow(T_,3.)
                                + thermo_.lowE()[index_[i]]*Math.pow(T_,4.);
                }
                else
                {
                    cp_mole_[i] = thermo_.highA()[index_[i]]
                                + thermo_.highB()[index_[i]]*T_ 
                                + thermo_.highC()[index_[i]]*Math.pow(T_,2.)
                                + thermo_.highD()[index_[i]]*Math.pow(T_,3.)
                                + thermo_.highE()[index_[i]]*Math.pow(T_,4.);
                }
                
                cp_mole_[i] = cp_mole_[i]*8314.;  //J/Kmol/K
                cp_mass_[i] = cp_mole_[i]/MW_[i]; //J/Kg/K
            }
            cp_updated_ = true;
        }
    }

    private void species_h_()
    {
        if ( !h_updated_ )
        {
            for(int i=0;i<NC_;i++)
            {
                if ( T_ < 1000. )
                {
                    h_mole_[i] = thermo_.lowA()[index_[i]]
                               + thermo_.lowB()[index_[i]]*T_/2.
                               + thermo_.lowC()[index_[i]]*Math.pow(T_,2.)/3.
                               + thermo_.lowD()[index_[i]]*Math.pow(T_,3.)/4.
                               + thermo_.lowE()[index_[i]]*Math.pow(T_,4.)/5.
                               + thermo_.lowF()[index_[i]]/T_;
                }
                else
                {
                    h_mole_[i] = thermo_.highA()[index_[i]]
                               + thermo_.highB()[index_[i]]*T_/2.
                               + thermo_.highC()[index_[i]]*Math.pow(T_,2.)/3.
                               + thermo_.highD()[index_[i]]*Math.pow(T_,3.)/4.
                               + thermo_.highE()[index_[i]]*Math.pow(T_,4.)/5.
                               + thermo_.highF()[index_[i]]/T_;
                }

                h_mole_[i] = h_mole_[i]*8314.*T_;  //J/Kmol
                h_mass_[i] = h_mole_[i]/MW_[i]; //J/Kg
            }
            h_updated_ = true;
        }
    }

    private void species_s_()
    {
        if ( !s_updated_ )
        {
            for(int i=0;i<NC_;i++)
            {
                if ( T_ < 1000. )
                {
                    s_mole_[i] = thermo_.lowA()[index_[i]]*Math.log(T_)
                               + thermo_.lowB()[index_[i]]*T_
                               + thermo_.lowC()[index_[i]]*Math.pow(T_,2.)/2.
                               + thermo_.lowD()[index_[i]]*Math.pow(T_,3.)/3.
                               + thermo_.lowE()[index_[i]]*Math.pow(T_,4.)/4.
                               + thermo_.lowG()[index_[i]];
                }
                else
                {
                    s_mole_[i] = thermo_.highA()[index_[i]]*Math.log(T_)
                               + thermo_.highB()[index_[i]]*T_
                               + thermo_.highC()[index_[i]]*Math.pow(T_,2.)/2.
                               + thermo_.highD()[index_[i]]*Math.pow(T_,3.)/3.
                               + thermo_.highE()[index_[i]]*Math.pow(T_,4.)/4.
                               + thermo_.highG()[index_[i]];
                }

                s_mole_[i] = 8314.*(s_mole_[i] - Math.log(x_[i]*p_/1.e05));  //J/Kmol/K
                s_mass_[i] = s_mole_[i]/MW_[i]; //J/Kg/K
            }
            s_updated_ = true;
        }
    }

    private void mixture_cp_()
    {
        if ( !cp_mix_updated_ )
        {
            this.species_cp_();
            cp_mole_mix_ = 0;
            cp_mass_mix_ = 0;
            for(int i=0;i<NC_;i++)
            {
                cp_mole_mix_ = cp_mole_mix_ + x_[i]*cp_mole_[i];
                cp_mass_mix_ = cp_mass_mix_ + y_[i]*cp_mass_[i];
            }
            cp_mix_updated_ = true;
        }
    }

    private void mixture_h_()
    {
        if ( !h_mix_updated_ )
        {
            this.species_h_();
            h_mole_mix_ = 0;
            h_mass_mix_ = 0;
            for(int i=0;i<NC_;i++)
            {
                h_mole_mix_ = h_mole_mix_ + x_[i]*h_mole_[i];
                h_mass_mix_ = h_mass_mix_ + y_[i]*h_mass_[i];
            }
            h_mix_updated_ = true;
        }
    }

    private void mixture_s_()
    {
        if ( !s_mix_updated_ )
        {
            this.species_s_();
            s_mole_mix_ = 0;
            s_mass_mix_ = 0;
            for(int i=0;i<NC_;i++)
            {
                s_mole_mix_ = s_mole_mix_ + x_[i]*s_mole_[i];
            }
            s_mass_mix_ = s_mole_mix_/MWmix_;
            s_mix_updated_ = true;
        }
    }

    private void resize()
    {
        names_    = new String[NC_];
        index_    = new int[NC_];
        MW_       = new double[NC_];
        y_        = new double[NC_];
        x_        = new double[NC_];
        mu_       = new double[NC_];
        cond_     = new double[NC_];
        cp_mole_  = new double[NC_];
        cp_mass_  = new double[NC_];
        h_mole_   = new double[NC_];
        h_mass_   = new double[NC_];
        s_mole_   = new double[NC_];
        s_mass_   = new double[NC_];
        diff_mix_ = new double[NC_];
        v_        = new double[NC_];
        l_        = new double[NC_];

        diff_  = new double[NC_][NC_];
    }
    
    private double collision_integrals_22(double Tr,double dr)
    {
        int Ta = -1;
        int Tb = -1;

        for (int j=0;j<(omega_.Tsigma22().length-1);j++)
        {
            if ( Tr >= omega_.Tsigma22()[j] && Tr < omega_.Tsigma22()[j+1])
            {
                Ta = j;
                Tb = j + 1;
                break;
            }
        }

        if ( Ta == -1 )
        {
            if ( Tr <= omega_.Tsigma22()[0] )
            {
                Ta = 0;
                Tb = 1;
            }
            else if ( Tr >= omega_.Tsigma22()[omega_.Tsigma22().length-1] ) 
            {
                Ta = omega_.Tsigma22().length - 2;
                Tb = omega_.Tsigma22().length - 1;
            }
        }

        int da = -1;
        int db = -1;

        for (int j=0;j<omega_.dsigma22().length-1;j++)
        {
            if ( dr >= omega_.dsigma22()[j] && dr < omega_.dsigma22()[j+1])
            {
                da = j;
                db = j + 1;
                break;
            }
        }

        if ( da == -1 )
        {
            if ( dr <= omega_.dsigma22()[0] )
            {
                da = 0;
                db = 1;
            }
            else if ( dr >= omega_.dsigma22()[omega_.dsigma22().length-1] ) 
            {
                da = omega_.dsigma22().length - 2;
                db = omega_.dsigma22().length - 1;
            }
        }

                        
        double [] b = {omega_.sigmaMatrix22()[Ta][da],
                       omega_.sigmaMatrix22()[Ta][db],
                       omega_.sigmaMatrix22()[Tb][da],
                       omega_.sigmaMatrix22()[Tb][db]};

        double [] x = new double[4];
        
        x[3] = (b[0] - b[1]- b[2] + b[3])/(omega_.Tsigma22()[Ta]*omega_.dsigma22()[da] - omega_.Tsigma22()[Ta]*omega_.dsigma22()[db] - omega_.Tsigma22()[Tb]*omega_.dsigma22()[da] + omega_.Tsigma22()[Tb]*omega_.dsigma22()[db]);
        
        x[2] = (-x[3]*(omega_.Tsigma22()[Ta]*omega_.dsigma22()[da] - omega_.Tsigma22()[Ta]*omega_.dsigma22()[db]) - b[1] + b[0])/(omega_.dsigma22()[da] - omega_.dsigma22()[db]);
        
        x[1] = (-x[3]*(omega_.Tsigma22()[Ta]*omega_.dsigma22()[da] - omega_.Tsigma22()[Tb]*omega_.dsigma22()[da]) - b[2] + b[0])/(omega_.Tsigma22()[Ta] - omega_.Tsigma22()[Tb]);
        
        x[0] = -x[1]*omega_.Tsigma22()[Ta] - x[2]*omega_.dsigma22()[da] - x[3]*omega_.Tsigma22()[Ta]*omega_.dsigma22()[da] + b[0];
        
        return x[0] + x[1]*Tr + x[2]*dr + x[3]*Tr*dr;
    }

    private double collision_integrals_11(double Tr,double dr)
    {
        int Ta = -1;
        int Tb = -1;

        for (int j=0;j<(omega_.Tsigma11().length-1);j++)
        {
            if ( Tr >= omega_.Tsigma11()[j] && Tr < omega_.Tsigma11()[j+1])
            {
                Ta = j;
                Tb = j + 1;
                break;
            }
        }

        if ( Ta == -1 )
        {
            if ( Tr <= omega_.Tsigma11()[0] )
            {
                Ta = 0;
                Tb = 1;
            }
            else if ( Tr >= omega_.Tsigma11()[omega_.Tsigma11().length-1] ) 
            {
                Ta = omega_.Tsigma11().length - 2;
                Tb = omega_.Tsigma11().length - 1;
            }
        }

        int da = -1;
        int db = -1;

        for (int j=0;j<omega_.dsigma11().length-1;j++)
        {
            if ( dr >= omega_.dsigma11()[j] && dr < omega_.dsigma11()[j+1])
            {
                da = j;
                db = j + 1;
                break;
            }
        }

        if ( da == -1 )
        {
            if ( dr <= omega_.dsigma11()[0] )
            {
                da = 0;
                db = 1;
            }
            else if ( dr >= omega_.dsigma11()[omega_.dsigma11().length-1] ) 
            {
                da = omega_.dsigma11().length - 2;
                db = omega_.dsigma11().length - 1;
            }
        }


        double [] b = {omega_.sigmaMatrix11()[Ta][da],
                       omega_.sigmaMatrix11()[Ta][db],
                       omega_.sigmaMatrix11()[Tb][da],
                       omega_.sigmaMatrix11()[Tb][db]};

        double [] x = new double[4];

        x[3] = (b[0] - b[1]- b[2] + b[3])/(omega_.Tsigma11()[Ta]*omega_.dsigma11()[da] - omega_.Tsigma11()[Ta]*omega_.dsigma11()[db] - omega_.Tsigma11()[Tb]*omega_.dsigma11()[da] + omega_.Tsigma11()[Tb]*omega_.dsigma11()[db]);
        
        x[2] = (-x[3]*(omega_.Tsigma11()[Ta]*omega_.dsigma11()[da] - omega_.Tsigma11()[Ta]*omega_.dsigma11()[db]) - b[1] + b[0])/(omega_.dsigma11()[da] - omega_.dsigma11()[db]);
        
        x[1] = (-x[3]*(omega_.Tsigma11()[Ta]*omega_.dsigma11()[da] - omega_.Tsigma11()[Tb]*omega_.dsigma11()[da]) - b[2] + b[0])/(omega_.Tsigma11()[Ta] - omega_.Tsigma11()[Tb]);
        
        x[0] = -x[1]*omega_.Tsigma11()[Ta] - x[2]*omega_.dsigma11()[da] - x[3]*omega_.Tsigma11()[Ta]*omega_.dsigma11()[da] + b[0];

        return x[0] + x[1]*Tr + x[2]*dr + x[3]*Tr*dr;
    }

}
