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

#include "backend/asaliInterface.hpp"

namespace ASALI
{
    asaliInterface::asaliInterface() : basicInterface()
    {
        asali_ = new ASALI::Asali();
        names_ = asali_->allSpeciesName();
    }

    void asaliInterface::setTemperature(const double T)
    {
        T_ = T;
        asali_->setTemperature(T_);
    }

    void asaliInterface::setPressure(const double p)
    {
        p_ = p;
        asali_->setPressure(p_);
    }

    void asaliInterface::setMoleFraction(const std::vector<double> x, const std::vector<std::string> name)
    {
        asali_->setSpecies(name);
        this->setStateFromMoleFraction(x.data(), T_, p_);
    }

    void asaliInterface::setMassFraction(const std::vector<double> y, const std::vector<std::string> name)
    {
        asali_->setSpecies(name);
        this->setStateFromMassFraction(y.data(), T_, p_);
    }

    void asaliInterface::setStateFromMassFraction(const double *y, const double T, const double p)
    {
        this->resize();
        T_ = T;
        p_ = p;

        std::vector<double> dummy(y, y + NS_);

        asali_->setMassFraction(dummy);
        asali_->setTemperature(T_);
        asali_->setPressure(p_);

        mole_ = asali_->moleFraction();
        mass_ = asali_->massFraction();

        x_ = mole_.data();
        y_ = mass_.data();

        for (unsigned int i = 0; i < NS_; i++)
        {
            n_[i] = asali_->speciesName()[i];
            MW_[i] = asali_->speciesMolecularWeight()[i];
        }
    }

    void asaliInterface::setStateFromMoleFraction(const double *x, const double T, const double p)
    {
        this->resize();
        T_ = T;
        p_ = p;

        std::vector<double> dummy(x, x + NS_);

        asali_->setMoleFraction(dummy);
        asali_->setTemperature(T_);
        asali_->setPressure(p_);

        mole_ = asali_->moleFraction();
        mass_ = asali_->massFraction();

        x_ = mole_.data();
        y_ = mass_.data();

        for (unsigned int i = 0; i < NS_; i++)
        {
            n_[i] = asali_->speciesName()[i];
            MW_[i] = asali_->speciesMolecularWeight()[i];
        }
    }

    void asaliInterface::vacuumCalculate()
    {
        l_ = asali_->meanFreePath();
        v_ = asali_->arithmeticMeanGasVelocity();
    }

    void asaliInterface::thermoCalculate()
    {
        std::vector<double> mw = asali_->speciesMolecularWeight();
        std::vector<double> h = asali_->speciesMolarEnthalpy();
        std::vector<double> s = asali_->speciesMolarEntropy();
        std::vector<double> cp = asali_->speciesMolarCp();

        std::vector<std::string> n = asali_->speciesName();

        for (unsigned int i = 0; i < NS_; i++)
        {
            n_[i] = n[i];
            h_[i] = h[i];
            s_[i] = s[i];
            cp_[i] = cp[i];
            MW_[i] = mw[i];
        }

        n_[NS_] = "mix";
        h_[NS_] = asali_->mixtureMolarEnthalpy(); //J/Kmol
        s_[NS_] = asali_->mixtureMolarEntropy();  //J/Kmol/K
        cp_[NS_] = asali_->mixtureMolarCp();      //J/Kmol/K
        MW_[NS_] = asali_->mixtureMolecularWeight();
    }

    void asaliInterface::transportCalculate()
    {
        std::vector<double> mu = asali_->speciesViscosity();
        std::vector<double> mw = asali_->speciesMolecularWeight();
        std::vector<double> diffM = asali_->mixtureDiffusion();
        std::vector<double> cond = asali_->speciesThermalConductivity();

        std::vector<std::vector<double>> diff = asali_->binaryDiffusion();

        std::vector<std::string> n = asali_->speciesName();

        for (unsigned int i = 0; i < (NS_ + 1); i++)
        {
            if (i == NS_)
            {
                n_[i] = "mix";
                mu_[i] = asali_->mixtureViscosity();             //Pas
                cond_[i] = asali_->mixtureThermalConductivity(); //W/m/K
                MW_[i] = asali_->mixtureMolecularWeight();
                for (unsigned int j = 0; j < (NS_ + 1); j++)
                {
                    diff_[i][j] = -1.;
                }
            }
            else
            {
                n_[i] = n[i];
                mu_[i] = mu[i];
                MW_[i] = mw[i];
                cond_[i] = cond[i];

                for (unsigned int j = 0; j < (NS_ + 1); j++)
                {
                    if (j == NS_)
                    {
                        diff_[i][j] = diffM[i];
                    }
                    else
                    {
                        diff_[i][j] = diff[i][j];
                    }
                }
            }
        }
    }

    double asaliInterface::getTemperature()
    {
        return T_;
    }

    double asaliInterface::getDensity()
    {
        return asali_->density();
    }

    double asaliInterface::getCpMassMix()
    {
        return asali_->mixtureMassCp();
    }

    double asaliInterface::getCpMoleMix()
    {
        return asali_->mixtureMolarCp();
    }

    double asaliInterface::getMWmix()
    {
        return asali_->mixtureMolecularWeight();
    }
    
    double asaliInterface::getCondMix()
    {
        return asali_->mixtureThermalConductivity();
    }

    double asaliInterface::getMuMix()
    {
        return asali_->mixtureViscosity();
    }

    int asaliInterface::checkNames(std::string name)
    {
        int check = 1;
        std::cout << name << std::endl;
        this->convertToCaption(name);
        std::cout << name << std::endl;
        for (unsigned int j = 0; j < names_.size(); j++)
        {
            if (name == names_[j])
            {
                check = 0;
                break;
            }
        }
        return check;
    }

    unsigned int asaliInterface::numberOfGasSpecies()
    {
        return asali_->numberOfSpecies();
    }

    unsigned int asaliInterface::numberOfSurfaceSpecies()
    {
        return 0.;
    }

    std::vector<double> asaliInterface::getMW()
    {
        return asali_->speciesMolecularWeight();
    }

    std::vector<double> asaliInterface::getHmole()
    {
        return asali_->speciesMolarEnthalpy();
    }

    std::vector<double> asaliInterface::getSmole()
    {
        return asali_->speciesMolarEntropy();
    }

    std::vector<double> asaliInterface::getCpMole()
    {
        return asali_->speciesMolarCp();
    }

    std::vector<double> asaliInterface::getDiffMix()
    {
        return asali_->mixtureDiffusion();
    }

    std::vector<double> asaliInterface::getBinaryDiffVector()
    {
        std::vector<std::vector<double> > diffMatrix = asali_->binaryDiffusion();
        std::vector<double> diffVector(NS_*NS_);
        
        unsigned int counter = 0;
        for (unsigned int i = 0; i < NS_; i++)
        {
            for (unsigned int j = 0; j < NS_; j++)
            {
                diffVector[counter] = diffMatrix[i][j];
                counter++;
            }
        }
        
        return diffVector;
    }

    std::vector<int> asaliInterface::checkNames(std::vector<std::string> &name)
    {
        std::vector<int> check(name.size());
        for (unsigned int i = 0; i < name.size(); i++)
        {
            this->convertToCaption(name[i]);
            check[i] = 1;
            for (unsigned int j = 0; j < names_.size(); j++)
            {
                if (name[i] == names_[j])
                {
                    check[i] = 0;
                    break;
                }
            }
        }

        return check;
    }

    asaliInterface::~asaliInterface()
    {
    }
}
