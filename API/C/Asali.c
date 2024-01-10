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

#include "Asali.h"

#include "transport.H"
#include "thermo.H"
#include "omega.H"

void set_temperature(Asali* asali_, double T)
{
    if ( asali_->T_ != T )
    {
        asali_->T_ = T;
        asali_->mu_updated_         = false;
        asali_->rho_updated_        = false;
        asali_->diff_updated_       = false;
        asali_->cp_updated_         = false;
        asali_->h_updated_          = false;
        asali_->s_updated_          = false;
        asali_->cond_updated_       = false;
        asali_->cond_mix_updated_   = false;
        asali_->mu_mix_updated_     = false;
        asali_->diff_mix_updated_   = false;
        asali_->v_updated_          = false;
        asali_->l_updated_          = false;
        asali_->cpmole_mix_updated_ = false;
        asali_->cpmass_mix_updated_ = false;
        asali_->hmole_mix_updated_  = false;
        asali_->hmass_mix_updated_  = false;
        asali_->smole_mix_updated_  = false;
    }
}

void set_pressure(Asali* asali_, double P)
{
    if ( asali_->P_ != P)
    {
        asali_->P_ = P;
        asali_->mu_updated_         = false;
        asali_->rho_updated_        = false;
        asali_->diff_updated_       = false;
        asali_->cp_updated_         = false;
        asali_->h_updated_          = false;
        asali_->s_updated_          = false;
        asali_->cond_updated_       = false;
        asali_->cond_mix_updated_   = false;
        asali_->mu_mix_updated_     = false;
        asali_->diff_mix_updated_   = false;
        asali_->v_updated_          = false;
        asali_->l_updated_          = false;
        asali_->cpmole_mix_updated_ = false;
        asali_->cpmass_mix_updated_ = false;
        asali_->hmole_mix_updated_  = false;
        asali_->hmass_mix_updated_  = false;
        asali_->smole_mix_updated_  = false;
    }
}

void set_number_of_species(Asali* asali_,int NC)
{
    if ( asali_->NC_ != NC )
    {
        asali_->NC_ = NC;
        asali_->mu_updated_         = false;
        asali_->rho_updated_        = false;
        asali_->diff_updated_       = false;
        asali_->cp_updated_         = false;
        asali_->h_updated_          = false;
        asali_->s_updated_          = false;
        asali_->cond_updated_       = false;
        asali_->cond_mix_updated_   = false;
        asali_->mu_mix_updated_     = false;
        asali_->diff_mix_updated_   = false;
        asali_->v_updated_          = false;
        asali_->l_updated_          = false;
        asali_->cpmole_mix_updated_ = false;
        asali_->cpmass_mix_updated_ = false;
        asali_->hmole_mix_updated_  = false;
        asali_->hmass_mix_updated_  = false;
        asali_->smole_mix_updated_  = false;
        resize(asali_,NC);
    }
}

void set_species_names(Asali* asali_,AsaliVector names)
{
    if ( get_vector_size(&names) == asali_->NC_ )
    {
        for (int j=0;j<asali_->NC_;j++)
        {
            set_vector_element_from_char(&asali_->name_,j,get_vector_element_as_char(&names,j));
            for (int i=0;i<asali_->number_of_species;i++)
            {
                if ( strcmp(get_vector_element_as_char(&names,j),asali_->transport_[i].name) == 0 )
                {
                    set_vector_element_from_int(&asali_->index_,j,i);
                    set_vector_element_from_double(&asali_->MW_,j,asali_->transport_[i].MW);
                    break;
                }
            }

            if (get_vector_element_as_int(&asali_->index_,j) == -1)
            {
                printf("\nASALI::ERROR--> %s is missing in ASALI databse.\n",get_vector_element_as_char(&asali_->name_,j));
                exit(-1);
            }
        }
        asali_->mu_updated_         = false;
        asali_->rho_updated_        = false;
        asali_->diff_updated_       = false;
        asali_->cp_updated_         = false;
        asali_->h_updated_          = false;
        asali_->s_updated_          = false;
        asali_->cond_updated_       = false;
        asali_->cond_mix_updated_   = false;
        asali_->mu_mix_updated_     = false;
        asali_->diff_mix_updated_   = false;
        asali_->v_updated_          = false;
        asali_->l_updated_          = false;
        asali_->cpmole_mix_updated_ = false;
        asali_->cpmass_mix_updated_ = false;
        asali_->hmole_mix_updated_  = false;
        asali_->hmass_mix_updated_  = false;
        asali_->smole_mix_updated_  = false;
    }
    else
    {
        printf("\nASALI::ERROR-->Wrong number of species names\n");
        exit(-1);
    }
}


void set_mass_fraction(Asali* asali_,AsaliVector y)
{
    if ( get_vector_size(&y) == asali_->NC_ )
    {
        asali_->MWmix_ = 0.;
        for (int j=0;j<asali_->NC_;j++)
        {
            set_vector_element_from_double(&asali_->y_,j,get_vector_element_as_double(&y,j));
            asali_->MWmix_ = asali_->MWmix_ + get_vector_element_as_double(&y,j)/get_vector_element_as_double(&asali_->MW_,j);
        }
        
        for (int j=0;j<asali_->NC_;j++)
        {
            set_vector_element_from_double(&asali_->x_,j,(get_vector_element_as_double(&y,j)/get_vector_element_as_double(&asali_->MW_,j))/asali_->MWmix_);
        }
        asali_->mu_updated_         = false;
        asali_->rho_updated_        = false;
        asali_->diff_updated_       = false;
        asali_->cp_updated_         = false;
        asali_->h_updated_          = false;
        asali_->s_updated_          = false;
        asali_->cond_updated_       = false;
        asali_->cond_mix_updated_   = false;
        asali_->mu_mix_updated_     = false;
        asali_->diff_mix_updated_   = false;
        asali_->v_updated_          = false;
        asali_->l_updated_          = false;
        asali_->cpmole_mix_updated_ = false;
        asali_->cpmass_mix_updated_ = false;
        asali_->hmole_mix_updated_  = false;
        asali_->hmass_mix_updated_  = false;
        asali_->smole_mix_updated_  = false;
    }
    else
    {
        printf("\nASALI::ERROR-->Wrong number of mole fractions\n");
        exit(-1);
    }
}

void set_mole_fraction(Asali* asali_,AsaliVector x)
{
    if ( get_vector_size(&x) == asali_->NC_ )
    {
        asali_->MWmix_ = 0.;
        for (int j=0;j<asali_->NC_;j++)
        {
            set_vector_element_from_double(&asali_->x_,j,get_vector_element_as_double(&x,j));
            asali_->MWmix_ = asali_->MWmix_ + get_vector_element_as_double(&x,j)*get_vector_element_as_double(&asali_->MW_,j);
        }
        
        for (int j=0;j<asali_->NC_;j++)
        {
            set_vector_element_from_double(&asali_->y_,j,get_vector_element_as_double(&x,j)*get_vector_element_as_double(&asali_->MW_,j)/asali_->MWmix_);
        }
        asali_->mu_updated_         = false;
        asali_->rho_updated_        = false;
        asali_->diff_updated_       = false;
        asali_->cp_updated_         = false;
        asali_->h_updated_          = false;
        asali_->s_updated_          = false;
        asali_->cond_updated_       = false;
        asali_->cond_mix_updated_   = false;
        asali_->mu_mix_updated_     = false;
        asali_->diff_mix_updated_   = false;
        asali_->v_updated_          = false;
        asali_->l_updated_          = false;
        asali_->cpmole_mix_updated_ = false;
        asali_->cpmass_mix_updated_ = false;
        asali_->hmole_mix_updated_  = false;
        asali_->hmass_mix_updated_  = false;
        asali_->smole_mix_updated_  = false;
    }
    else
    {
        printf("\nASALI::ERROR-->Wrong number of mole fractions\n");
        exit(-1);
    }
}


void species_viscosity_(Asali* asali_)  //[Pa*s]
{
    if ( ! asali_->mu_updated_ )
    {
        double Tr    = 0.;
        double dr    = 0.;
        double sigma = 0.;
        double mu    = 0.;
        double MW    = 0.;
        int    idx   = 0.;
        for (unsigned int i=0;i<asali_->NC_;i++)
        {
            idx    = get_vector_element_as_int(&asali_->index_,i);
            MW     = get_vector_element_as_double(&asali_->MW_,i);
            Tr     = asali_->T_/asali_->transport_[idx].LJpotential;
            dr     = 0.5*pow(asali_->transport_[idx].dipole,2.)/(asali_->transport_[idx].LJpotential*1.3806488*pow(asali_->transport_[idx].LJdiameter,3.));
            dr     = 1e06*dr;
            sigma  = collisionIntegrals22(asali_,Tr,dr);
            mu     = (5./16.)*sqrt(asali_->pi_*1.3806488*asali_->T_*MW*1.66054)/(asali_->pi_*sigma*pow(asali_->transport_[idx].LJdiameter,2.));
            mu     = mu*1.e-05;
            set_vector_element_from_double(&asali_->mu_,i,mu);
        }
        asali_->mu_updated_ = true;
    }
}

void density_(Asali* asali_)
{
    if ( !asali_->rho_updated_)
    {
        asali_->rho_ = asali_->P_*asali_->MWmix_/(8314.*asali_->T_);
        asali_->rho_updated_ = true;
    }
}

void binary_diffusion_(Asali* asali_)
{
    if ( !asali_->diff_updated_ )
    {
        double MWmix;
        double LJpotentialmix;
        double LJdiametermix;
        double dipolemix;
        double polarn;
        double dipolep;
        double chi;
        double sigma;
        double Tr;
        double dr;
        double diff;

        for (int i=0;i<asali_->NC_;i++)
        {
            int i_idx = get_vector_element_as_int(&asali_->index_,i);
            
            for (int j=i;j<asali_->NC_;j++)
            {
                int j_idx = get_vector_element_as_int(&asali_->index_,j);

                MWmix = get_vector_element_as_double(&asali_->MW_,i)*get_vector_element_as_double(&asali_->MW_,j)/(get_vector_element_as_double(&asali_->MW_,i) + get_vector_element_as_double(&asali_->MW_,j));
                
                if ( asali_->transport_[i_idx].polar == 0 & asali_->transport_[j_idx].polar == 0 )
                {
                    LJpotentialmix = sqrt(asali_->transport_[i_idx].LJpotential*asali_->transport_[j_idx].LJpotential);
                    LJdiametermix  = 0.5*(asali_->transport_[i_idx].LJdiameter + asali_->transport_[j_idx].LJdiameter);
                    dipolemix      = sqrt(asali_->transport_[i_idx].dipole*asali_->transport_[j_idx].dipole);
                }
                else if ( asali_->transport_[i_idx].polar > 0 & asali_->transport_[j_idx].polar > 0 )
                {
                    LJpotentialmix = sqrt(asali_->transport_[i_idx].LJpotential*asali_->transport_[j_idx].LJpotential);
                    LJdiametermix  = 0.5*(asali_->transport_[i_idx].LJdiameter + asali_->transport_[j_idx].LJdiameter);
                    dipolemix      = sqrt(asali_->transport_[i_idx].dipole*asali_->transport_[j_idx].dipole);
                }
                else
                {
                    polarn  = 0.;
                    dipolep = 0.;
                    
                    if ( asali_->transport_[i_idx].polar == 0 )
                    {
                        polarn  = asali_->transport_[i_idx].polar/pow(asali_->transport_[i_idx].LJdiameter,3.);
                        dipolep = 1e02*asali_->transport_[j_idx].dipole;
                        dipolep = dipolep/sqrt(asali_->transport_[j_idx].LJpotential*1.3806488*pow(asali_->transport_[j_idx].LJdiameter,3.));
                        chi     = 0.25*polarn*dipolep;
                        chi     = chi*sqrt(asali_->transport_[j_idx].LJpotential/asali_->transport_[i_idx].LJpotential);
                        chi     = 1. + chi ;
                    }
                    else
                    {
                        polarn  = asali_->transport_[j_idx].polar/pow(asali_->transport_[j_idx].LJdiameter,3.);
                        dipolep = 1e02*asali_->transport_[i_idx].dipole;
                        dipolep = dipolep/sqrt(asali_->transport_[i_idx].LJpotential*1.3806488*pow(asali_->transport_[i_idx].LJdiameter,3.));
                        chi     = 0.25*polarn*dipolep;
                        chi     = chi*sqrt(asali_->transport_[i_idx].LJpotential/asali_->transport_[j_idx].LJpotential);
                        chi     = 1. + chi;
                    }

                    LJpotentialmix = pow(chi, 2.) * sqrt(asali_->transport_[i_idx].LJpotential * asali_->transport_[j_idx].LJpotential);
                    LJdiametermix = 0.5 * (asali_->transport_[i_idx].LJdiameter + asali_->transport_[j_idx].LJdiameter) * pow(chi, -1. / 6.);
                    dipolemix = 0.;
                }

                Tr    = asali_->T_/LJpotentialmix;
                dr    = 0.5*pow(dipolemix,2.)/(LJpotentialmix*1.3806488*pow(LJdiametermix,3.));
                dr    = 1e06*dr;
                sigma = collisionIntegrals11(asali_,Tr,dr);
                diff  = (3./16.)*sqrt(2.*asali_->pi_*pow((1.3806488*asali_->T_),3.)/(MWmix*1.66054))/(asali_->P_*asali_->pi_*pow(LJdiametermix,2.)*sigma);
                diff  = diff*0.1;
                set_matrix_element_from_double(&asali_->diff_,i,j,diff);
                set_matrix_element_from_double(&asali_->diff_,j,i,diff);
            }
        }
        asali_->diff_updated_ = true;
    }
}

void species_thermal_conductivity_(Asali* asali_)  //[W/m/K]
{
    if ( !asali_->cond_updated_ )
    {
        double A       = 0.;
        double B       = 0.;
        double Zrot    = 0.;
        double cvtrans = 0.;
        double cvrot   = 0.;
        double cvvib   = 0.;
        double ftrans  = 0.;
        double frot    = 0.;
        double fvib    = 0.;
        double R       = 8314; //[J/kmol/K]
        double F_T     = 0.;
        double F_298   = 0.;

        species_viscosity_(asali_);
        binary_diffusion_(asali_);
        density_(asali_);
        species_cp_(asali_);
        
        for (int i=0;i<asali_->NC_;i++)
        {
            int idx = get_vector_element_as_int(&asali_->index_,i);
            if ( asali_->transport_[idx].geometry == 0 ) //single atom
            {
                cvtrans = 3.*R*0.5;
                cvrot   = 0.;
                cvvib   = 0.;
            }
            else if ( asali_->transport_[idx].geometry == 1 ) //linear
            {
                cvtrans = 3.*R*0.5;
                cvrot   = R;
                cvvib   = get_vector_element_as_double(&asali_->cp_mole_,i) - R - 5.*R*0.5;
            }
            else //non linear
            {
                cvtrans = 3.*R*0.5;
                cvrot   = 3.*R*0.5;
                cvvib   = get_vector_element_as_double(&asali_->cp_mole_,i) - R - 3.*R;
            }
            
            double rho  = asali_->P_*get_vector_element_as_double(&asali_->MW_,i)/(R*asali_->T_);
            double diff = get_matrix_element_as_double(&asali_->diff_,i,i);
            double mu   = get_vector_element_as_double(&asali_->mu_,i);
            
            A = (5./2.) - rho*diff/mu;

            F_T   = 1. + 0.5*sqrt(pow(asali_->pi_,3.)*asali_->transport_[idx].LJpotential/asali_->T_) 
                  + (0.25*pow(asali_->pi_,2.) + 2.)*(asali_->transport_[idx].LJpotential/asali_->T_)
                  + sqrt(pow((asali_->pi_*asali_->transport_[idx].LJpotential/asali_->T_),3.));
            F_298 = 1. + 0.5*sqrt(pow(asali_->pi_,3.)*asali_->transport_[idx].LJpotential/298.) 
                  + (0.25*pow(asali_->pi_,2.) + 2.)*(asali_->transport_[idx].LJpotential/298.)
                  + sqrt(pow((asali_->pi_*asali_->transport_[idx].LJpotential/298.),3.));
            
            Zrot = asali_->transport_[idx].collision*F_298/F_T;
            
            B = Zrot + (2./asali_->pi_)*((5./3.)*(cvrot/R) + rho*diff/mu);
            
            ftrans = (5./2.)*(1. - 2.*cvrot*A/(asali_->pi_*cvtrans*B));
            frot   = (rho*diff/mu)*(1. + 2.*A/(asali_->pi_*B));
            fvib   = rho*diff/mu;
            
            double cond = mu*(ftrans*cvtrans + frot*cvrot + fvib*cvvib)/get_vector_element_as_double(&asali_->MW_,i);

            set_vector_element_from_double(&asali_->cond_,i,cond);
        }
        asali_->cond_updated_ = true;
    }
}

void species_cp_(Asali* asali_)
{
    if ( !asali_->cp_updated_ )
    {
        for (int i=0;i<asali_->NC_;i++)
        {
            double cp  = 0.;
            int    idx = get_vector_element_as_int(&asali_->index_,i);
            if ( asali_->T_ < 1000 )
            {
                cp = asali_->thermo_[idx].low[0] 
                   + asali_->thermo_[idx].low[1]*asali_->T_
                   + asali_->thermo_[idx].low[2]*pow(asali_->T_,2.)
                   + asali_->thermo_[idx].low[3]*pow(asali_->T_,3.)
                   + asali_->thermo_[idx].low[4]*pow(asali_->T_,4.);
            }
            else
            {
                cp = asali_->thermo_[idx].high[0] 
                   + asali_->thermo_[idx].high[1]*asali_->T_
                   + asali_->thermo_[idx].high[2]*pow(asali_->T_,2.)
                   + asali_->thermo_[idx].high[3]*pow(asali_->T_,3.)
                   + asali_->thermo_[idx].high[4]*pow(asali_->T_,4.);
            }

            set_vector_element_from_double(&asali_->cp_mole_,i,cp*8314.); //J/kmol/K
            set_vector_element_from_double(&asali_->cp_mass_,i,cp*8314/get_vector_element_as_double(&asali_->MW_,i)); //J/kg/K
        }
        asali_->cp_updated_ = true;
    }
}

void species_h_(Asali* asali_)
{
    if ( !asali_->h_updated_ )
    {
        for (int i=0;i<asali_->NC_;i++)
        {
            double h   = 0.;
            int    idx = get_vector_element_as_int(&asali_->index_,i);
            if ( asali_->T_ < 1000 )
            {
                h = asali_->thermo_[idx].low[0] 
                  + asali_->thermo_[idx].low[1]*asali_->T_/2.
                  + asali_->thermo_[idx].low[2]*pow(asali_->T_,2.)/3.
                  + asali_->thermo_[idx].low[3]*pow(asali_->T_,3.)/4.
                  + asali_->thermo_[idx].low[4]*pow(asali_->T_,4.)/5.
                  + asali_->thermo_[idx].low[5]/asali_->T_;
            }
            else
            {
                h = asali_->thermo_[idx].high[0] 
                  + asali_->thermo_[idx].high[1]*asali_->T_/2.
                  + asali_->thermo_[idx].high[2]*pow(asali_->T_,2.)/3.
                  + asali_->thermo_[idx].high[3]*pow(asali_->T_,3.)/4.
                  + asali_->thermo_[idx].high[4]*pow(asali_->T_,4.)/5.
                  + asali_->thermo_[idx].high[5]/asali_->T_;
            }

            set_vector_element_from_double(&asali_->h_mole_,i,h*8314.*asali_->T_); //J/kmol
            set_vector_element_from_double(&asali_->h_mass_,i,h*8314*asali_->T_/get_vector_element_as_double(&asali_->MW_,i)); //J/kg
        }
        asali_->h_updated_ = true;
    }
}

void species_s_(Asali* asali_)
{
    if ( !asali_->s_updated_ )
    {
        for (int i=0;i<asali_->NC_;i++)
        {
            double s   = 0.;
            int    idx = get_vector_element_as_int(&asali_->index_,i);
            if ( asali_->T_ < 1000 )
            {
                s = asali_->thermo_[idx].low[0]*log(asali_->T_)
                  + asali_->thermo_[idx].low[1]*asali_->T_
                  + asali_->thermo_[idx].low[2]*pow(asali_->T_,2.)/2.
                  + asali_->thermo_[idx].low[3]*pow(asali_->T_,3.)/3.
                  + asali_->thermo_[idx].low[4]*pow(asali_->T_,4.)/4.
                  + asali_->thermo_[idx].low[6];
            }
            else
            {
                s = asali_->thermo_[idx].high[0]*log(asali_->T_)
                  + asali_->thermo_[idx].high[1]*asali_->T_
                  + asali_->thermo_[idx].high[2]*pow(asali_->T_,2.)/2.
                  + asali_->thermo_[idx].high[3]*pow(asali_->T_,3.)/3.
                  + asali_->thermo_[idx].high[4]*pow(asali_->T_,4.)/4.
                  + asali_->thermo_[idx].high[6];
            }

            s = 8314.*(s - log(asali_->P_*get_vector_element_as_double(&asali_->x_,i)/1.0e05));

            set_vector_element_from_double(&asali_->s_mole_,i,s); //J/kmol/K
            set_vector_element_from_double(&asali_->s_mass_,i,s/get_vector_element_as_double(&asali_->MW_,i)); //J/kg/K
        }
        asali_->s_updated_ = true;
    }
}

double get_mixture_thermal_conductivity(Asali* asali_) //[W/m/K]
{
    if ( !asali_->cond_mix_updated_ )
    {
        species_thermal_conductivity_(asali_);
        double A = 0.;
        double B = 0.;
        for (int i=0;i<asali_->NC_;i++)
        {
            A = A + get_vector_element_as_double(&asali_->x_,i)*get_vector_element_as_double(&asali_->cond_,i);
            B = B + get_vector_element_as_double(&asali_->x_,i)/get_vector_element_as_double(&asali_->cond_,i);
        }
        asali_->cond_mix_ = 0.5*(A + 1./B);
        asali_->cond_mix_updated_ = true;
    }
    
    return asali_->cond_mix_;
}

double get_mixture_viscosity(Asali* asali_) //[Pa*s]
{
    if ( !asali_->mu_mix_updated_ )
    {
        species_viscosity_(asali_);
        double somma, phi;
        for (int i=0;i<asali_->NC_;i++)
        {
            somma = 0.;
            for (int j=0;j<asali_->NC_;j++)
            {
                phi = (1./sqrt(8.))*(1./sqrt(1. + get_vector_element_as_double(&asali_->MW_,i)/get_vector_element_as_double(&asali_->MW_,j)));
                phi = phi*pow((1. + sqrt(get_vector_element_as_double(&asali_->mu_,i)/get_vector_element_as_double(&asali_->mu_,j))*(pow((get_vector_element_as_double(&asali_->MW_,j)/get_vector_element_as_double(&asali_->MW_,i)),(1./4.)))),2);
                somma = somma + get_vector_element_as_double(&asali_->x_,j)*phi;
            }
            asali_->mu_mix_ = asali_->mu_mix_ + get_vector_element_as_double(&asali_->x_,i)*get_vector_element_as_double(&asali_->mu_,i)/somma;
        }
        asali_->mu_mix_updated_ = true;
    }

    return asali_->mu_mix_;
}

AsaliVector get_mixture_diffusion(Asali* asali_) //[m2/s]
{
    if ( !asali_->diff_mix_updated_ )
    {
        binary_diffusion_(asali_);
        double A,B;
        for (int i=0;i<asali_->NC_;i++)
        {
            A = 0.;
            B = 0.;
            for (int j=0;j<asali_->NC_;j++)
            {
                if ( j != i )
                {
                    A = A + get_vector_element_as_double(&asali_->x_,j)*get_vector_element_as_double(&asali_->MW_,j);
                    B = B + get_vector_element_as_double(&asali_->x_,j)/get_matrix_element_as_double(&asali_->diff_,j,i);
                }
            }
            set_vector_element_from_double(&asali_->diff_mix_,i,A/(asali_->MWmix_*B));
        }
        asali_->diff_mix_updated_ = true;
    }
    
    return asali_->diff_mix_;
}

AsaliVector get_arithmetic_mean_gas_velocity(Asali* asali_)
{
    if ( !asali_->v_updated_ )
    {
        for (int i=0;i<asali_->NC_;i++)
        {
            set_vector_element_from_double(&asali_->v_,i,sqrt(8*8314*asali_->T_/(asali_->pi_*get_vector_element_as_double(&asali_->MW_,i))));
        }
        asali_->v_updated_ = true;
    }

    return asali_->v_;
}

AsaliVector get_mean_free_path(Asali* asali_)
{
    if ( !asali_->l_updated_ )
    {
        for (int i=0;i<asali_->NC_;i++)
        {
            int idx = get_vector_element_as_int(&asali_->index_,i);
            set_vector_element_from_double(&asali_->l_,i,1.38064852*1e-03*asali_->T_/(sqrt(2.)*asali_->P_*pow(asali_->transport_[idx].LJdiameter,2.)));
        }
        asali_->l_updated_ = true;
    }

    return asali_->l_;
}

double get_mixture_molar_specific_heat(Asali* asali_)
{
    if ( !asali_->cpmole_mix_updated_ )
    {
        species_cp_(asali_);
        asali_->cpmole_mix_ = 0.;
        for (int i=0;i<asali_->NC_;i++)
        {
            asali_->cpmole_mix_ = asali_->cpmole_mix_ + get_vector_element_as_double(&asali_->x_,i)*get_vector_element_as_double(&asali_->cp_mole_,i);
        }
        asali_->cpmole_mix_updated_ = true;
    }

    return asali_->cpmole_mix_;
}

double get_mixture_mass_specific_heat(Asali* asali_)
{
    if ( !asali_->cpmass_mix_updated_ )
    {
        species_cp_(asali_);
        asali_->cpmass_mix_ = 0.;
        for (int i=0;i<asali_->NC_;i++)
        {
            asali_->cpmass_mix_ = asali_->cpmass_mix_ + get_vector_element_as_double(&asali_->y_,i)*get_vector_element_as_double(&asali_->cp_mass_,i);
        }
        asali_->cpmass_mix_updated_ = true;
    }

    return asali_->cpmass_mix_;
}

double get_mixture_molar_enthalpy(Asali* asali_)
{
    if ( !asali_->hmole_mix_updated_ )
    {
        species_h_(asali_);
        asali_->hmole_mix_ = 0.;
        for (int i=0;i<asali_->NC_;i++)
        {
            asali_->hmole_mix_ = asali_->hmole_mix_ + get_vector_element_as_double(&asali_->x_,i)*get_vector_element_as_double(&asali_->h_mole_,i);
        }
        asali_->hmole_mix_updated_ = true;
    }

    return asali_->hmole_mix_;
}

double get_mixture_mass_enthalpy(Asali* asali_)
{
    if ( !asali_->hmass_mix_updated_ )
    {
        species_h_(asali_);
        asali_->hmass_mix_ = 0.;
        for (int i=0;i<asali_->NC_;i++)
        {
            asali_->hmass_mix_ = asali_->hmass_mix_ + get_vector_element_as_double(&asali_->y_,i)*get_vector_element_as_double(&asali_->h_mass_,i);
        }
        asali_->hmass_mix_updated_ = true;
    }

    return asali_->hmass_mix_;
}

double get_mixture_molar_entropy(Asali* asali_)
{
    if ( !asali_->smole_mix_updated_ )
    {
        species_s_(asali_);
        asali_->smole_mix_ = 0.;
        for (int i=0;i<asali_->NC_;i++)
        {
            asali_->smole_mix_ = asali_->smole_mix_ + get_vector_element_as_double(&asali_->x_,i)*get_vector_element_as_double(&asali_->s_mole_,i);
        }
        asali_->smole_mix_updated_ = true;
    }

    return asali_->smole_mix_;
}

double get_mixture_mass_entropy(Asali* asali_)
{
    asali_->smass_mix_ = get_mixture_molar_entropy(asali_)/asali_->MWmix_;
    return asali_->smass_mix_;
}

void resize(Asali* asali_,int NC)
{
    empty_vector_of_char(&asali_->name_,NC);
    
    vector_from_int(&asali_->index_,NC,-1);
    
    empty_vector_of_double(&asali_->MW_,NC);
    empty_vector_of_double(&asali_->x_,NC);
    empty_vector_of_double(&asali_->y_,NC);
    empty_vector_of_double(&asali_->mu_,NC);
    empty_vector_of_double(&asali_->cond_,NC);
    empty_vector_of_double(&asali_->cp_mass_,NC);
    empty_vector_of_double(&asali_->cp_mole_,NC);
    empty_vector_of_double(&asali_->h_mass_,NC);
    empty_vector_of_double(&asali_->h_mole_,NC);
    empty_vector_of_double(&asali_->s_mass_,NC);
    empty_vector_of_double(&asali_->s_mole_,NC);
    empty_vector_of_double(&asali_->diff_mix_,NC);
    empty_vector_of_double(&asali_->v_,NC);
    empty_vector_of_double(&asali_->l_,NC);
    
    empty_matrix_of_double(&asali_->diff_,NC,NC);
    
    asali_->cond_mix_   = 0.;
    asali_->mu_mix_     = 0.;
    asali_->cpmole_mix_ = 0.;
    asali_->cpmass_mix_ = 0.;
    asali_->hmole_mix_  = 0.;
    asali_->hmass_mix_  = 0.;
    asali_->smole_mix_  = 0.;
    asali_->smass_mix_  = 0.;
}

void initialize(Asali* asali_)
{
    asali_->thermo_updated_     = false;
    asali_->transport_updated_  = false;
    asali_->omega11_updated_    = false;
    asali_->omega22_updated_    = false;
    asali_->mu_updated_         = false;
    asali_->diff_updated_       = false;
    asali_->cp_updated_         = false;
    asali_->h_updated_          = false;
    asali_->s_updated_          = false;
    asali_->cond_updated_       = false;
    asali_->cond_mix_updated_   = false;
    asali_->mu_mix_updated_     = false;
    asali_->diff_mix_updated_   = false;
    asali_->v_updated_          = false;
    asali_->l_updated_          = false;
    asali_->cpmole_mix_updated_ = false;
    asali_->cpmass_mix_updated_ = false;
    asali_->hmole_mix_updated_  = false;
    asali_->hmass_mix_updated_  = false;
    asali_->smole_mix_updated_  = false;

    asali_->pi_ = 3.14159265358979323846;
    
    thermo_update(asali_);
    transport_update(asali_);
    omega_update(asali_);
}


double get_mixture_molecular_weight(Asali* asali_)
{
    return asali_->MWmix_;
}

double get_density(Asali* asali_)
{
    density_(asali_);
    return asali_->rho_;
}

AsaliVector get_mass_fraction(Asali* asali_)
{
    return asali_->y_;
}

AsaliVector get_mole_fraction(Asali* asali_)
{
    return asali_->x_;
}

AsaliVector get_species_viscosity(Asali* asali_)
{
    species_viscosity_(asali_);
    return asali_->mu_;
}

AsaliMatrix get_binary_diffusion(Asali* asali_)
{
    binary_diffusion_(asali_);
    return asali_->diff_;
}

AsaliVector get_species_molar_specific_heat(Asali* asali_)
{
    species_cp_(asali_);
    return asali_->cp_mole_;
}

AsaliVector get_species_mass_specific_heat(Asali* asali_)
{
    species_cp_(asali_);
    return asali_->cp_mass_;
}

AsaliVector get_species_molar_enthalpy(Asali* asali_)
{
    species_h_(asali_);
    return asali_->h_mole_;
}

AsaliVector get_species_mass_enthalpy(Asali* asali_)
{
    species_h_(asali_);
    return asali_->h_mass_;
}

AsaliVector get_species_molar_entropy(Asali* asali_)
{
    species_s_(asali_);
    return asali_->s_mole_;
}

AsaliVector get_species_mass_entropy(Asali* asali_)
{
    species_s_(asali_);
    return asali_->s_mass_;
}

AsaliVector get_species_thermal_conductivity(Asali* asali_)
{
    species_thermal_conductivity_(asali_);
    return asali_->cond_;
}

double collisionIntegrals22(Asali* asali_, const double Tr,const double dr)
{
    float x[4], b[4];
    int Ta = -1;
    int Tb = -1;

    for (unsigned int j=0;j<(asali_->omega22_.size-1);j++)
    {
        if ( Tr >= asali_->omega22_.T[j] && Tr < asali_->omega22_.T[j+1])
        {
            Ta = j;
            Tb = j + 1;
            break;
        }
    }

    if ( Ta == -1 )
    {
        if ( Tr <= asali_->omega22_.T[0] )
        {
            Ta = 0;
            Tb = 1;
        }
        else if ( Tr >= asali_->omega22_.T[asali_->omega22_.size - 1] ) 
        {
            Ta = asali_->omega22_.size - 2;
            Tb = asali_->omega22_.size - 1;
        }
    }

    int da = -1;
    int db = -1;

    for (unsigned int j=0;j<7;j++)
    {
        if ( dr >= asali_->omega22_.d[j] && dr < asali_->omega22_.d[j+1])
        {
            da = j;
            db = j + 1;
            break;
        }
    }

    if ( da == -1 )
    {
        if ( dr <= asali_->omega22_.d[0] )
        {
            da = 0;
            db = 1;
        }
        else if ( dr >= asali_->omega22_.d[7] ) 
        {
            da = asali_->omega22_.size - 2;
            db = asali_->omega22_.size - 1;
        }
    }

    b[0] = asali_->omega22_.sigma[Ta][da];
    b[1] = asali_->omega22_.sigma[Ta][db];
    b[2] = asali_->omega22_.sigma[Tb][da];
    b[3] = asali_->omega22_.sigma[Tb][db];

    x[3] = (b[0] - b[1]- b[2] + b[3])/(asali_->omega22_.T[Ta]*asali_->omega22_.d[da] - asali_->omega22_.T[Ta]*asali_->omega22_.d[db] - asali_->omega22_.T[Tb]*asali_->omega22_.d[da] + asali_->omega22_.T[Tb]*asali_->omega22_.d[db]);
    
    x[2] = (-x[3]*(asali_->omega22_.T[Ta]*asali_->omega22_.d[da] - asali_->omega22_.T[Ta]*asali_->omega22_.d[db]) - b[1] + b[0])/(asali_->omega22_.d[da] - asali_->omega22_.d[db]);
    
    x[1] = (-x[3]*(asali_->omega22_.T[Ta]*asali_->omega22_.d[da] - asali_->omega22_.T[Tb]*asali_->omega22_.d[da]) - b[2] + b[0])/(asali_->omega22_.T[Ta] - asali_->omega22_.T[Tb]);
    
    x[0] = -x[1]*asali_->omega22_.T[Ta] - x[2]*asali_->omega22_.d[da] - x[3]*asali_->omega22_.T[Ta]*asali_->omega22_.d[da] + b[0];

    return x[0] + x[1]*Tr + x[2]*dr + x[3]*Tr*dr;
}

double collisionIntegrals11(Asali* asali_, const double Tr,const double dr)
{
    float x[4], b[4];
    int Ta = -1;
    int Tb = -1;

    for (unsigned int j=0;j<(asali_->omega11_.size-1);j++)
    {
        if ( Tr >= asali_->omega11_.T[j] && Tr < asali_->omega11_.T[j+1])
        {
            Ta = j;
            Tb = j + 1;
            break;
        }
    }

    if ( Ta == -1 )
    {
        if ( Tr <= asali_->omega11_.T[0] )
        {
            Ta = 0;
            Tb = 1;
        }
        else if ( Tr >= asali_->omega11_.T[asali_->omega11_.size - 1] ) 
        {
            Ta = asali_->omega11_.size - 2;
            Tb = asali_->omega11_.size - 1;
        }
    }

    int da = -1;
    int db = -1;

    for (unsigned int j=0;j<7;j++)
    {
        if ( dr >= asali_->omega11_.d[j] && dr < asali_->omega11_.d[j+1])
        {
            da = j;
            db = j + 1;
            break;
        }
    }

    if ( da == -1 )
    {
        if ( dr <= asali_->omega11_.d[0] )
        {
            da = 0;
            db = 1;
        }
        else if ( dr >= asali_->omega11_.d[7] ) 
        {
            da = asali_->omega11_.size - 2;
            db = asali_->omega11_.size - 1;
        }
    }

    b[0] = asali_->omega11_.sigma[Ta][da];
    b[1] = asali_->omega11_.sigma[Ta][db];
    b[2] = asali_->omega11_.sigma[Tb][da];
    b[3] = asali_->omega11_.sigma[Tb][db];
    
    x[3] = (b[0] - b[1]- b[2] + b[3])/(asali_->omega11_.T[Ta]*asali_->omega11_.d[da] - asali_->omega11_.T[Ta]*asali_->omega11_.d[db] - asali_->omega11_.T[Tb]*asali_->omega11_.d[da] + asali_->omega11_.T[Tb]*asali_->omega11_.d[db]);
    
    x[2] = (-x[3]*(asali_->omega11_.T[Ta]*asali_->omega11_.d[da] - asali_->omega11_.T[Ta]*asali_->omega11_.d[db]) - b[1] + b[0])/(asali_->omega11_.d[da] - asali_->omega11_.d[db]);
    
    x[1] = (-x[3]*(asali_->omega11_.T[Ta]*asali_->omega11_.d[da] - asali_->omega11_.T[Tb]*asali_->omega11_.d[da]) - b[2] + b[0])/(asali_->omega11_.T[Ta] - asali_->omega11_.T[Tb]);
    
    x[0] = -x[1]*asali_->omega11_.T[Ta] - x[2]*asali_->omega11_.d[da] - x[3]*asali_->omega11_.T[Ta]*asali_->omega11_.d[da] + b[0];

    return x[0] + x[1]*Tr + x[2]*dr + x[3]*Tr*dr;
}
