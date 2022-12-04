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

#ifndef BASICINTERFACE_H
#define BASICINTERFACE_H
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
#include <numeric>
#include <functional>

namespace ASALI
{
    /// Abstract class to estimate gas mixture properties
    class basicInterface
    {
    public:
        /// Class constructor
        basicInterface();

        /// Convert string from lower case to upper case
        static void convertToCaption(std::string &n);

        /// Resize variables based on number of species in the gas mixture
        void resize();

        /// Return the property of a specie from species name and property name
        double specieProperty(std::string p, std::string n);

        /// Return mole fraction from names
        std::vector<double> getMoleFractionFromNames(const std::vector<std::string> &names);

        /// Return mass fraction from names
        std::vector<double> getMassFractionFromNames(const std::vector<std::string> &names);

        /// Return mole fraction
        inline std::vector<double> getMoleFraction() const { return mole_; };

        /// Return mass fraction
        inline std::vector<double> getMassFraction() const { return mass_; };

        /// Return species and mixture enthalpy in [J/kmol]
        inline std::vector<double> h() const { return h_; };

        /// Return species and mixture entropy in [J/kmol/K]
        inline std::vector<double> s() const { return s_; };

        /// Return species and mixture molar specific heat in [J/kmol/K]
        inline std::vector<double> cp() const { return cp_; };

        /// Return species and mixture molecular weight in [g/mol]
        inline std::vector<double> MW() const { return MW_; };

        /// Return species and mixture viscosity in [Pas]
        inline std::vector<double> mu() const { return mu_; };

        /// Return species and mixture thermal conductivity in [W/m/K]
        inline std::vector<double> cond() const { return cond_; };

        /// Return species arithmetic mean gas velocity [m/s]
        inline std::vector<double> vm() const { return v_; };

        /// Return species binary and mixture diffusion coefficients [m2/s]
        inline std::vector<std::vector<double>> diff() const { return diff_; };

        /// Return species mean free path [m]
        inline std::vector<double> l() const { return l_; };

        /// Return mole fraction
        inline std::vector<double> mole() const { return mole_; };

        /// Return mass fraction
        inline std::vector<double> mass() const { return mass_; };

        /// Return gas species names
        inline std::vector<std::string> names() const { return names_; };

        /// Return gas species names and mixture
        inline std::vector<std::string> mixtureNames() const { return n_; };

        /// Return coverage species names
        inline std::vector<std::string> coverageNames() const { return nc_; };

        /// Set temperature in [K]
        virtual void setTemperature(const double T) = 0;

        /// Set pressure in [Pa]
        virtual void setPressure(const double p) = 0;

        /// Set mass fraction
        virtual void setMoleFraction(const std::vector<double> &x, const std::vector<std::string> &name) = 0;

        /// Set mole fraction
        virtual void setMassFraction(const std::vector<double> &y, const std::vector<std::string> &name) = 0;

        /// Set mass fraction, temperature in [K] and pressure in [Pa]
        virtual void setStateFromMassFraction(const double *y, const double T, const double p) = 0;

        /// Set mole fraction, temperature in [K] and pressure in [Pa]
        virtual void setStateFromMoleFraction(const double *x, const double T, const double p) = 0;

        /// Calculate thermodynamic properties
        virtual void thermoCalculate() = 0;

        /// Calculate transport properties
        virtual void transportCalculate() = 0;

        /// Calculate vacuum properties
        virtual void vacuumCalculate() = 0;

        /// Get gas mixture temperature in [K]
        virtual double getTemperature() = 0;

        /// Get gas mixture density in [kg/m3]
        virtual double getDensity() = 0;

        /// Get gas mixture mass specific heat in [J/kg/K]
        virtual double getCpMassMix() = 0;

        /// Get gas mixture molar specific heat in [J/kmol/K]
        virtual double getCpMoleMix() = 0;

        /// Get gas mixture molecular weight in [g/mol]
        virtual double getMWmix() = 0;

        /// Get gas mixture thermal conductivity in [W/m/K]
        virtual double getCondMix() = 0;

        /// Get gas mixture viscosity in [Pas]
        virtual double getMuMix() = 0;

        /// Get species molecular weight in [g/mol]
        virtual std::vector<double> getMW() = 0;

        /// Get species molar enthalpy in [J/kmol]
        virtual std::vector<double> getHmole() = 0;

        /// Get species molar entropy in [J/kmol/K]
        virtual std::vector<double> getSmole() = 0;

        /// Get species molar specific heat in [J/kmol/K]
        virtual std::vector<double> getCpMole() = 0;

        /// Get species mixture diffusion coefficient in [m2/s]
        virtual std::vector<double> getDiffMix() = 0;

        /// Get species binary diffusion coefficient in [m2/s] as vector
        virtual std::vector<double> getBinaryDiffVector() = 0;

        /// Check species names
        virtual std::vector<int> checkNames(std::vector<std::string> &name) = 0;

        /// Check single species name
        virtual int checkNames(std::string name) = 0;

        /// Return specie index from specie name
        virtual int getSpecieIndex(std::string n) = 0;

        /// Return number of gas species in the gas mixture
        virtual unsigned int numberOfGasSpecies() = 0;

        /// Return number of coverage species
        virtual unsigned int numberOfSurfaceSpecies() = 0;

        /// Return the flag for surface species and reactions
        virtual bool isSurface() = 0;

        /// Class destructor
        virtual ~basicInterface();

        double T_;  /// Temperature in [K]
        double p_;  /// Pressure in [Pa]
        double *x_; /// Mole fraction
        double *y_; /// Mass fraction

        unsigned int NS_;      /// Number of gas species
        unsigned int SURF_NS_; /// Number of coverage species

        std::vector<double> h_;    /// Species and mixture enthalpy in [J/kmol]
        std::vector<double> s_;    /// Species and mixture entropy in [J/kmol/K]
        std::vector<double> cp_;   /// Species and mixture molar specific heat in [J/kmol/K]
        std::vector<double> v_;    /// Species arithmetic mean gas velocity [m/s]
        std::vector<double> l_;    /// Species mean free path [m]
        std::vector<double> MW_;   /// Species and mixture molecular weight in [g/mol]
        std::vector<double> mu_;   /// Species and mixture viscosity in [Pas]
        std::vector<double> cond_; /// Species and mixture thermal conductivity in [W/m/K]
        std::vector<double> mole_; /// Mole fraction
        std::vector<double> mass_; /// Mass fraction

        std::vector<std::vector<double>> diff_; /// Species binary and mixture diffusion coefficients [m2/s]

        std::vector<std::string> names_; /// Gas species names
        std::vector<std::string> n_;     /// Gas species names including "mix"
        std::vector<std::string> nc_;    /// Coverage species names

        const double pi_ = 3.14159265358979323846; /// Pi

    private:
    };
}
#endif
