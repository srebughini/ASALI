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

#ifndef ASALI_H
#define ASALI_H

#include <string>
#include <iostream>
#include <math.h>
#include <ctime>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

namespace ASALI
{
    class Asali 
    {
        public:

            Asali();

           ~Asali(void);

            //- Return functions
            std::vector<std::string>           speciesName();
            std::vector<std::string>           allSpeciesName();
            std::vector<double>                speciesMolecularWeight();
            std::vector<double>                moleFraction();
            std::vector<double>                massFraction();
            std::vector<double>                speciesViscosity();
            std::vector<double>                speciesThermalConductivity();
            std::vector<double>                speciesMolarCp();
            std::vector<double>                speciesMassCp();
            std::vector<double>                speciesMolarEnthalpy();
            std::vector<double>                speciesMassEnthalpy();
            std::vector<double>                speciesMolarEntropy();
            std::vector<double>                speciesMassEntropy();
            std::vector<double>                mixtureDiffusion();
            std::vector<double>                arithmeticMeanGasVelocity();
            std::vector<double>                meanFreePath();
            std::vector<std::vector<double> >  binaryDiffusion();
            unsigned int                       numberOfSpecies();
            unsigned int                       numberOfAllSpecies();
            double                             mixtureMolecularWeight();
            double                             density();
            double                             mixtureThermalConductivity();
            double                             mixtureViscosity();
            double                             mixtureMolarCp();
            double                             mixtureMassCp();
            double                             mixtureMolarEnthalpy();
            double                             mixtureMassEnthalpy();
            double                             mixtureMolarEntropy();
            double                             mixtureMassEntropy();

            void setTemperature(const double T);
            
            void setPressure(const double p);
            
            void setMassFraction(const std::vector<double> y);
            
            void setMoleFraction(const std::vector<double> x);
            
            void setSpecies(const std::vector<std::string> name);

        private:

            struct transportParameters
            {
                std::vector<std::string>  name;
                std::vector<unsigned int> geometry;
                std::vector<double>       LJpotential;
                std::vector<double>       LJdiameter;
                std::vector<double>       dipole;
                std::vector<double>       polar;
                std::vector<double>       collision;
                std::vector<double>       MW;
            } transport_;

            struct thermoParameters
            {
                std::vector<std::string>                name;
                std::vector<std::vector<double> >       high;
                std::vector<std::vector<double> >       low;
            } thermo_;

            unsigned int NC_;
            
            double p_;
            double T_;
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
            
            std::vector<double> y_;
            std::vector<double> x_;
            std::vector<double> MW_;
            std::vector<double> mu_;
            std::vector<double> cond_;
            std::vector<double> cpmole_;
            std::vector<double> cpmass_;
            std::vector<double> hmole_;
            std::vector<double> hmass_;
            std::vector<double> smole_;
            std::vector<double> smass_;
            std::vector<double> diff_mix_;
            std::vector<double> v_;
            std::vector<double> l_;
            std::vector<double> Tsigma11_;
            std::vector<double> dsigma11_;
            std::vector<double> Tsigma22_;
            std::vector<double> dsigma22_;

            std::vector<std::vector<double> > sigmaMatrix11_;
            std::vector<std::vector<double> > sigmaMatrix22_;
            std::vector<std::vector<double> > diff_;

            std::vector<int> index_;

            std::vector<std::string> name_;

            void resize();
            void density_();
            void speciesViscosity_();
            void binaryDiffusion_();
            void speciesThermalConductivity_();
            void speciesCp_();
            void speciesH_();
            void speciesS_();

            double collisionIntegrals11(const double Tr,const double dr);
            double collisionIntegrals22(const double Tr,const double dr);

            double pi_;

            bool mu_update_;
            bool diff_update_;
            bool rho_update_;
            bool cp_update_;
            bool h_update_;
            bool s_update_;
            bool cond_update_;
            bool v_update_;
            bool l_update_;
            bool mu_mix_update_;
            bool diff_mix_update_;
            bool cond_mix_update_;
            bool cpmole_mix_update_;
            bool cpmass_mix_update_;
            bool hmole_mix_update_;
            bool hmass_mix_update_;
            bool smole_mix_update_;
    };

}

#endif
