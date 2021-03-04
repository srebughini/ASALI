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

#include "backend/canteraInterface.hpp"

namespace ASALI
{
    canteraInterface::canteraInterface(Cantera::ThermoPhase *thermo,
                                       Cantera::Transport *transport,
                                       Cantera::Kinetics *kinetic,
                                       Cantera::SurfPhase *surface,
                                       Cantera::InterfaceKinetics *surface_kinetic) : basicInterface(),
                                                                                      thermo_(thermo),
                                                                                      transport_(transport),
                                                                                      kinetic_(kinetic),
                                                                                      surface_(surface),
                                                                                      surface_kinetic_(surface_kinetic)
    {
        this->resize();

        QfromGas_ = 0.;
        QfromSurface_ = 0.;

        RfromGas_.resize(NS_);
        RfromSurface_.resize(NS_);
        Rsurface_.resize(NS_);

        for (unsigned int i = 0; i < SURF_NS_; i++)
        {
            nc_[i] = surface_->speciesName(i);
        }
    }

    void canteraInterface::setTemperature(const double T)
    {
        T_ = T;
    }

    void canteraInterface::setPressure(const double p)
    {
        p_ = p;
    }

    void canteraInterface::setMoleFraction(const std::vector<double> x, const std::vector<std::string> name)
    {
        for (unsigned int i = 0; i < NS_; i++)
        {
            x_[i] = 0.;
            for (unsigned int j = 0; j < name.size(); j++)
            {
                if (name[j] == thermo_->speciesName(i))
                {
                    x_[i] = x[j];
                    break;
                }
            }
        }
        this->setStateFromMoleFraction(x_, T_, p_);
    }

    void canteraInterface::setMassFraction(const std::vector<double> y, const std::vector<std::string> name)
    {
        for (unsigned int i = 0; i < NS_; i++)
        {
            y_[i] = 0.;
            for (unsigned int j = 0; j < name.size(); j++)
            {
                if (name[j] == thermo_->speciesName(i))
                {
                    y_[i] = y[j];
                    break;
                }
            }
        }
        this->setStateFromMassFraction(y_, T_, p_);
    }

    void canteraInterface::setStateFromMassFraction(const double *y, const double T, double p)
    {
        T_ = T;
        p_ = p;
        thermo_->setState_TPY(T_, p_, y);
        thermo_->getMoleFractions(x_);

        for (unsigned int i = 0; i < NS_; i++)
        {
            y_[i] = y[i];
            mass_[i] = y_[i];
            mole_[i] = x_[i];
            n_[i] = thermo_->speciesName(i);
            MW_[i] = thermo_->molecularWeight(i);
        }
    }

    void canteraInterface::setStateFromMoleFraction(const double *x, const double T, double p)
    {
        T_ = T;
        p_ = p;
        thermo_->setState_TPX(T_, p_, x);
        thermo_->getMassFractions(y_);

        for (unsigned int i = 0; i < NS_; i++)
        {
            x_[i] = x[i];
            mass_[i] = y_[i];
            mole_[i] = x_[i];
            n_[i] = thermo_->speciesName(i);
            MW_[i] = thermo_->molecularWeight(i);
        }
    }

    void canteraInterface::equilibriumCalculate(std::string type)
    {
        thermo_->equilibrate(type);
        thermo_->getMassFractions(y_);
        thermo_->getMoleFractions(x_);

        for (unsigned int i = 0; i < NS_; i++)
        {
            mass_[i] = y_[i];
            mole_[i] = x_[i];
            n_[i] = thermo_->speciesName(i);
        }
    }

    void canteraInterface::vacuumCalculate()
    {
        for (unsigned int i = 0; i < NS_; i++)
        {
            const Cantera::GasTransportData *transportData = dynamic_cast<Cantera::GasTransportData *>(thermo_->species(n_[i])->transport.get());
            v_[i] = std::sqrt(8. * 8314. * T_ / (pi_ * MW_[i]));
            l_[i] = 1.38064852 * 1e-23 * T_ / (std::sqrt(2) * p_ * std::pow(transportData->diameter, 2.));
        }
    }

    void canteraInterface::thermoCalculate()
    {
        double mw[NS_];
        double h[NS_];
        double s[NS_];
        double cp[NS_];

        thermo_->getMolecularWeights(mw);
        thermo_->getPartialMolarEnthalpies(h);
        thermo_->getPartialMolarEntropies(s);
        thermo_->getPartialMolarCp(cp);

        for (unsigned int i = 0; i < NS_; i++)
        {
            n_[i] = thermo_->speciesName(i);
            h_[i] = h[i];
            s_[i] = s[i];
            cp_[i] = cp[i];
            MW_[i] = mw[i];
        }

        n_[NS_] = "mix";
        h_[NS_] = thermo_->enthalpy_mole(); //J/Kmol
        s_[NS_] = thermo_->entropy_mole();  //J/Kmol/K
        cp_[NS_] = this->getCpMoleMix();    //J/Kmol/K
        MW_[NS_] = this->getMWmix();
    }

    void canteraInterface::transportCalculate()
    {
        double mu[NS_];
        double diff[NS_ * NS_];
        double diffM[NS_];

        transport_->getSpeciesViscosities(mu);
        transport_->getBinaryDiffCoeffs(NS_, diff);
        transport_->getMixDiffCoeffs(diffM);

        unsigned int counter = 0;
        for (unsigned int i = 0; i < (NS_ + 1); i++)
        {
            if (i == NS_)
            {
                n_[i] = "mix";
                mu_[i] = transport_->viscosity();             //Pas
                cond_[i] = transport_->thermalConductivity(); //W/m/K
                MW_[i] = thermo_->meanMolecularWeight();
                for (unsigned int j = 0; j < (NS_ + 1); j++)
                {
                    diff_[i][j] = -1.;
                }
            }
            else
            {
                n_[i] = thermo_->speciesName(i);
                mu_[i] = mu[i];
                MW_[i] = thermo_->molecularWeight(i);

                for (unsigned int j = 0; j < (NS_ + 1); j++)
                {
                    if (j == NS_)
                    {
                        diff_[i][j] = diffM[i];
                    }
                    else
                    {
                        diff_[i][j] = diff[counter++];
                    }
                }
            }
        }

        {
            double X[NS_];
            for (unsigned int i = 0; i < NS_; i++)
            {
                for (unsigned int j = 0; j < NS_; j++)
                {
                    if (j == i)
                    {
                        X[j] = 1.;
                    }
                    else
                    {
                        X[j] = 0.;
                    }
                }

                thermo_->setState_TPY(T_, p_, X);
                cond_[i] = transport_->thermalConductivity();
            }
        }
    }

    double canteraInterface::getTemperature()
    {
        return thermo_->temperature();
    }

    double canteraInterface::getDensity()
    {
        return thermo_->density();
    }

    double canteraInterface::getCpMassMix()
    {
        return thermo_->cp_mass();
    }

    double canteraInterface::getCpMoleMix()
    {
        return thermo_->cp_mole();
    }

    double canteraInterface::getMWmix()
    {
        return thermo_->meanMolecularWeight();
    }

    double canteraInterface::getCondMix()
    {
        return transport_->thermalConductivity();
    }

    double canteraInterface::getMuMix()
    {
        return transport_->viscosity();
    }

    int canteraInterface::getSpecieIndex(std::string name)
    {
        return thermo_->speciesIndex(name);
    }

    int canteraInterface::checkNames(std::string name)
    {
        int check = 1;

        this->convertToCaption(name);
        for (unsigned int j = 0; j < NS_; j++)
        {
            if (name == thermo_->speciesName(j))
            {
                check = 0;
                break;
            }
        }

        return check;
    }

    unsigned int canteraInterface::numberOfGasSpecies()
    {
        return thermo_->nSpecies();
    }

    unsigned int canteraInterface::numberOfSurfaceSpecies()
    {
        if (surface_)
        {
            return surface_->nSpecies();
        }
        else
        {
            return 0;
        }
    }

    unsigned int canteraInterface::numberOfHomogeneousReactions()
    {
        return kinetic_->nReactions();
    }

    std::vector<double> canteraInterface::doubleVectorToStdVector(double* double_vector, unsigned int vector_size)
    {
        std::vector<double> std_vector(vector_size);
        for (unsigned int i = 0; i < vector_size; i++)
        {
            std_vector[i] = double_vector[i];
        }
        return std_vector;
    }

    std::vector<double> canteraInterface::getMW()
    {
        double mw[NS_];
        thermo_->getMolecularWeights(mw);
        return this->doubleVectorToStdVector(mw, NS_);
    }

    std::vector<double> canteraInterface::getHmole()
    {
        double h[NS_];
        thermo_->getPartialMolarEnthalpies(h);
        return this->doubleVectorToStdVector(h, NS_);
    }

    std::vector<double> canteraInterface::getSmole()
    {
        double s[NS_];
        thermo_->getPartialMolarEntropies(s);
        return this->doubleVectorToStdVector(s, NS_);
    }

    std::vector<double> canteraInterface::getCpMole()
    {
        double cp[NS_];
        thermo_->getPartialMolarCp(cp);
        return this->doubleVectorToStdVector(cp, NS_);
    }

    std::vector<double> canteraInterface::getDiffMix()
    {
        double diff[NS_];
        transport_->getMixDiffCoeffs(diff);
        return this->doubleVectorToStdVector(diff, NS_);
    }

    std::vector<double> canteraInterface::getBinaryDiffVector()
    {
        double diff[NS_ * NS_];
        transport_->getBinaryDiffCoeffs(NS_ * NS_, diff);
        return this->doubleVectorToStdVector(diff, NS_ * NS_);
    }

    std::vector<int> canteraInterface::checkNames(std::vector<std::string> &name)
    {
        std::vector<int> check(name.size());

        for (unsigned int i = 0; i < name.size(); i++)
        {
            this->convertToCaption(name[i]);
            check[i] = 1;
            for (unsigned int j = 0; j < NS_; j++)
            {
                if (name[i] == thermo_->speciesName(j))
                {
                    check[i] = 0;
                    break;
                }
            }
        }
        return check;
    }

    void canteraInterface::calculateHomogeneousReactions(std::vector<double> omega, double T, double p)
    {
        double *bulkArray = omega.data();
        double canteraArray[NS_];

        this->setStateFromMassFraction(bulkArray, T, p);

        kinetic_->getNetProductionRates(canteraArray);

        for (unsigned int j = 0; j < NS_; j++)
        {
            RfromGas_[j] = canteraArray[j]; //kmol/m2/s
        }

        double reactionArray[kinetic_->nReactions()];
        double enthalpyArray[kinetic_->nReactions()];
        kinetic_->getNetRatesOfProgress(reactionArray);
        kinetic_->getDeltaEnthalpy(enthalpyArray);
        QfromGas_ = 0.;
        for (unsigned int j = 0; j < kinetic_->nReactions(); j++)
        {
            QfromGas_ = QfromGas_ + reactionArray[j] * enthalpyArray[j]; //J/kmol/k
        }
        QfromGas_ = -QfromGas_;
    }

    void canteraInterface::calculateHeterogeneousReactions(std::vector<double> omega, std::vector<double> Z, double T, double p)
    {
        {
            double *bulkArray = omega.data();
            double *coverageArray = Z.data();
            double reactionArray[NS_ + SURF_NS_];

            this->setStateFromMassFraction(bulkArray, T, p);

            surface_->setTemperature(T);
            surface_->setPressure(p);
            surface_->setCoveragesNoNorm(coverageArray);
            surface_kinetic_->getNetProductionRates(reactionArray);

            unsigned int rcounter = 0;
            for (unsigned int j = 0; j < NS_; j++)
            {
                RfromSurface_[j] = reactionArray[rcounter++]; //kmol/m2/s
            }

            for (unsigned int j = 0; j < SURF_NS_; j++)
            {
                Rsurface_[j] = reactionArray[rcounter++];
            }
        }

        {
            double reactionArray[surface_kinetic_->nReactions()];
            double enthalpyArray[surface_kinetic_->nReactions()];
            surface_kinetic_->getNetRatesOfProgress(reactionArray);
            surface_kinetic_->getDeltaEnthalpy(enthalpyArray);
            QfromSurface_ = 0.;
            for (unsigned int j = 0; j < surface_kinetic_->nReactions(); j++)
            {
                QfromSurface_ = QfromSurface_ + reactionArray[j] * enthalpyArray[j]; //J/kmol/s
            }

            QfromSurface_ = -QfromSurface_;
            SD_ = surface_->siteDensity();
        }
    }

    canteraInterface::~canteraInterface()
    {
    }
}
