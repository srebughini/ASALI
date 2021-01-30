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

#ifndef ASALI_H_
#define ASALI_H_

#include <stdbool.h>
#include <math.h>
#include "AsaliVector.h"
#include "AsaliMatrix.h"

struct thermoParameters
{
    char*  name;
    float* high;
    float* low;
};

struct omega
{
    int    size;
    float* T;
    float* d;
    float** sigma;
};

struct transportParameters
{
    char*  name;
    int    geometry;
    float  LJpotential;
    float  LJdiameter;
    float  dipole;
    float  polar;
    float  collision;
    float  MW;
};

typedef struct
{
    double pi_;
    double T_;
    double P_;
    double MWmix_;
    double rho_;
    double cond_mix_;
    double mu_mix_;
    double cpmole_mix_;
    double cpmass_mix_;
    double hmole_mix_;
    double hmass_mix_;
    double smole_mix_;
    double smass_mix_;

    int    NC_;
    int    number_of_species;
   
    struct thermoParameters*    thermo_;
    struct transportParameters* transport_;
    struct omega                omega11_;
    struct omega                omega22_;
    
    bool   thermo_updated_;
    bool   transport_updated_;
    bool   omega11_updated_;
    bool   omega22_updated_ ;
    bool   mu_updated_ ;
    bool   rho_updated_;
    bool   diff_updated_;
    bool   cp_updated_;
    bool   h_updated_;
    bool   s_updated_;
    bool   cond_updated_;
    bool   cond_mix_updated_;
    bool   mu_mix_updated_;
    bool   diff_mix_updated_;
    bool   v_updated_;
    bool   l_updated_;
    bool   cpmole_mix_updated_;
    bool   cpmass_mix_updated_;
    bool   hmole_mix_updated_;
    bool   hmass_mix_updated_;
    bool   smole_mix_updated_;
    
    AsaliVector name_;
    AsaliVector index_;
    AsaliVector MW_;
    AsaliVector x_;
    AsaliVector y_;
    AsaliVector mu_;
    AsaliVector cp_mole_;
    AsaliVector cp_mass_;
    AsaliVector h_mole_;
    AsaliVector h_mass_;
    AsaliVector s_mole_;
    AsaliVector s_mass_;
    AsaliVector cond_;
    AsaliVector diff_mix_;
    AsaliVector v_;
    AsaliVector l_;
   
    AsaliMatrix diff_;
    
} Asali;

void initialize(Asali* asali_);
void set_temperature(Asali* asali_, double T);
void set_pressure(Asali* asali_, double P);
void set_number_of_species(Asali* asali_, int NC);
void set_species_names(Asali* asali_,AsaliVector names);
void set_mass_fraction(Asali* asali_,AsaliVector y);
void set_mole_fraction(Asali* asali_,AsaliVector x);

void species_viscosity_(Asali* asali_);
void binary_diffusion_(Asali* asali_);
void species_cp_(Asali* asali_);
void species_h_(Asali* asali_);
void species_thermal_conductivity_(Asali* asali_);

void thermo_update(Asali* asali_);
void transport_update(Asali* asali_);
void omega_update(Asali* asali_);
void resize(Asali* asali_, int NC);

double get_mixture_molecular_weight(Asali* asali_);
double get_density(Asali* asali_);
double get_mixture_thermal_conductivity(Asali* asali_);
double get_mixture_viscosity(Asali* asali_);
double get_mixture_molar_specific_heat(Asali* asali_);
double get_mixture_mass_specific_heat(Asali* asali_);
double get_mixture_molar_enthalpy(Asali* asali_);
double get_mixture_mass_enthalpy(Asali* asali_);
double get_mixture_molar_entropy(Asali* asali_);
double get_mixture_mass_entropy(Asali* asali_);

AsaliVector get_mass_fraction(Asali* asali_);
AsaliVector get_mole_fraction(Asali* asali_);
AsaliVector get_species_viscosity(Asali* asali_);
AsaliVector get_species_molar_specific_heat(Asali* asali_);
AsaliVector get_species_mass_specific_heat(Asali* asali_);
AsaliVector get_species_molar_enthalpy(Asali* asali_);
AsaliVector get_species_mass_enthalpy(Asali* asali_);
AsaliVector get_species_molar_entropy(Asali* asali_);
AsaliVector get_species_mass_entropy(Asali* asali_);
AsaliVector get_species_thermal_conductivity(Asali* asali_);
AsaliVector get_mixture_diffusion(Asali* asali_);
AsaliVector get_arithmetic_mean_gas_velocity(Asali* asali_);
AsaliVector get_mean_free_path(Asali* asali_);

AsaliMatrix get_binary_diffusion(Asali* asali_);

double collisionIntegrals22(Asali* asali_,double Tr,double dr);
double collisionIntegrals11(Asali* asali_,double Tr,double dr);

#endif // ASALI_H_

