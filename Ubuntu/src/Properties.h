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

#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <string>
#include <iostream>
#include <math.h>
#include <ctime>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <Eigen/Dense>

namespace ASALI
{
    class Properties 
    {
        public:

            Properties();

           ~Properties(void);

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
            std::vector<double>                aritmeticMeanGasVelocity();
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

            struct thermoProperties
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

            const double pi_ = 3.14159265358979323846;
    };

}

#endif
