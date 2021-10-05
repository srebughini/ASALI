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

#include "backend/het1dEquations.hpp"

namespace ASALI
{
    het1dEquations::het1dEquations()
    {
    }

    void het1dEquations::resize()
    {
        if (type_ == "CANTERA")
        {
            NC_ = chemistryInterface_->numberOfGasSpecies();
            SURF_NC_ = chemistryInterface_->numberOfSurfaceSpecies();
            NE_ = NP_ * (NC_ + NC_ + SURF_NC_ + 1 + 1);

            canteraIndex_.resize(NC_);
            for (unsigned int i = 0; i < NC_; i++)
            {
                canteraIndex_[i] = i;
            }
        }
        else if (type_ == "ASALI")
        {
            NC_ = canteraIndex_.size();
            SURF_NC_ = 0;
            NE_ = NP_ * (NC_ + NC_ + SURF_NC_ + 1 + 1);
        }

        {
            x_.resize(NC_);
            omega_.resize(NC_);
            omega0_.resize(NC_);
            MW_.resize(NC_);
            diff_.resize(NC_);
            RfromGas_.resize(NC_);
            RfromSurface_.resize(NC_);
            h_.resize(NC_);

            Z_.resize(SURF_NC_);
            Rsurface_.resize(SURF_NC_);

            TBvector_.resize(NP_);
            TWvector_.resize(NP_);
            kHeatVector_.resize(NP_);
            rhoVector_.resize(NP_);
            cpVector_.resize(NP_);
            condVector_.resize(NP_);
            QfromGasVector_.resize(NP_);
            QfromSurfaceVector_.resize(NP_);
            omegaBMatrix_.resize(NP_);
            omegaWMatrix_.resize(NP_);
            Zmatrix_.resize(NP_);
            diffMatrix_.resize(NP_);
            kMatMatrix_.resize(NP_);
            RfromGasMatrix_.resize(NP_);
            RfromSurfaceMatrix_.resize(NP_);
            RsurfaceMatrix_.resize(NP_);
            for (unsigned int i = 0; i < NP_; i++)
            {
                omegaBMatrix_[i].resize(NC_);
                omegaWMatrix_[i].resize(NC_);
                diffMatrix_[i].resize(NC_);
                kMatMatrix_[i].resize(NC_);
                RfromGasMatrix_[i].resize(NC_);
                RfromSurfaceMatrix_[i].resize(NC_);
                Zmatrix_[i].resize(SURF_NC_);
                RsurfaceMatrix_[i].resize(SURF_NC_);
            }

            algb_.resize(NE_);

            SD_ = 1.;
        }

        {
            Length_.clear();
            SpecieB_.clear();
            SpecieW_.clear();
            Site_.clear();
            Time_.clear();
            TemperatureB_.clear();
            TemperatureW_.clear();
            Pressure_.clear();
        }
    }

    void het1dEquations::setEnergy(const bool flag)
    {
        energyEquation_ = flag;
    }

    void het1dEquations::setPressure(const double P)
    {
        P_ = P;
    }

    void het1dEquations::setLength(const double L)
    {
        L_ = L;
        dz_ = L_ / double(NP_ - 1);
        z_.resize(NP_);
        for (unsigned int i = 0; i < NP_; i++)
        {
            z_[i] = i * dz_;
        }
    }

    void het1dEquations::setReactorType(const std::string reactorType)
    {
        reactorType_ = reactorType;
    }

    void het1dEquations::setResolutionType(const std::string resolution)
    {
        resolution_ = resolution;
    }

    void het1dEquations::setPackedBed(const double Dt, const double Dp, const double epsi)
    {
        Dt_ = Dt;
        Dp_ = Dp;
        epsi_ = epsi;
        av_ = 6. * (1. - epsi_) / Dp_;
    }

    void het1dEquations::setTubular(const double Dt, const double tw, const std::string section)
    {
        Dt_ = Dt - 2. * tw;
        av_ = 4. / Dt;
        if (section == "circle")
        {
            Nuinf_ = 3.659;
            Shinf_ = 3.659;
        }
        else if (section == "square")
        {
            Nuinf_ = 2.977;
            Shinf_ = 2.977;
        }
        else if (section == "triangle")
        {
            Nuinf_ = 2.494;
            Shinf_ = 2.494;
        }
        epsi_ = std::pow(Dt_ / Dt, 2.);
    }

    void het1dEquations::setHoneyComb(const double cpsi, const double tw, const std::string section)
    {
        if (section == "circle")
        {
            Nuinf_ = 3.659;
            Shinf_ = 3.659;
        }
        else if (section == "square")
        {
            Nuinf_ = 2.977;
            Shinf_ = 2.977;
        }
        else if (section == "triangle")
        {
            Nuinf_ = 2.494;
            Shinf_ = 2.494;
        }
        Dt_ = sqrt(1. / cpsi) * 2.54 * 1e-02 - tw; //[m]

        epsi_ = std::pow(Dt_, 2.) / std::pow(Dt_ + tw, 2.);
        av_ = 4. * epsi_ / Dt_;
    }

    void het1dEquations::setSpecificMassFlowRate(const double G)
    {
        G_ = G / epsi_;
    }

    void het1dEquations::setNumberOfPoints(const double NP)
    {
        NP_ = int(NP);
    }

    void het1dEquations::setCatalystProperties(const double alfa, const double rhos, const double cps, const double conds)
    {
        alfa_ = alfa;
        rhos_ = rhos;
        cps_ = cps;
        conds_ = conds;
    }

    void het1dEquations::setInert(const unsigned int inertIndex)
    {
        inertIndex_ = inertIndex;
    }

    void het1dEquations::setInletConditions(const std::vector<double> omega0, const double T0)
    {
        omega0_ = omega0;
        T0_ = T0;
    }

    int het1dEquations::Equations(double &t, std::vector<double> &y, std::vector<double> &dy)
    {
        // Recover unknowns
        {
            unsigned int counter = 0;
            for (unsigned int i = 0; i < NP_; i++)
            {
                for (unsigned int j = 0; j < NC_; j++)
                {
                    omegaBMatrix_[i][j] = y[counter++];
                }

                for (unsigned int j = 0; j < NC_; j++)
                {
                    omegaWMatrix_[i][j] = y[counter++];
                }

                for (unsigned int j = 0; j < SURF_NC_; j++)
                {
                    Zmatrix_[i][j] = y[counter++];
                }

                TBvector_[i] = y[counter++];
                TWvector_[i] = y[counter++];
            }
        }

        for (unsigned int i = 0; i < NP_; i++)
        {
            omega_ = omegaBMatrix_[i];
            T_ = TBvector_[i];

            // Calculates the volume and the concentrations of species
            if (userCheck_ == false)
            {
                MWmix_ = chemistryInterface_->getMWmix();
                cTot_ = P_ / (8314. * T_);
                rho_ = cTot_ * MWmix_;

                chemistryInterface_->setStateFromMassFraction(omega_.data(), T_, P_);

                std::vector<double> mole = chemistryInterface_->mole();
                std::vector<double> mw = chemistryInterface_->getMW();

                for (unsigned int i = 0; i < NC_; i++)
                {
                    MW_[i] = mw[canteraIndex_[i]];
                    x_[i] = mole[canteraIndex_[i]];
                }

                std::vector<double> diffMix = chemistryInterface_->getDiffMix();

                for (unsigned int j = 0; j < NC_; j++)
                {
                    diff_[j] = diffMix[canteraIndex_[j]];
                }

                cp_ = chemistryInterface_->getCpMassMix();
                cond_ = chemistryInterface_->getCondMix();
                mu_ = chemistryInterface_->getMuMix();
            }
            else
            {
                MWmix_ = this->meanMolecularWeight(omega_, MW_);
                x_ = this->moleFraction(omega_, MW_, MWmix_);
                cTot_ = P_ / (8314. * T_);
                rho_ = cTot_ * MWmix_;
            }

            // Calculates homogeneous kinetics
            {
                this->updateHomogenousChemistry();
            }

            omega_ = omegaWMatrix_[i];
            T_ = TWvector_[i];

            if (SURF_NC_ != 0)
            {
                Z_ = Zmatrix_[i];
            }

            // Calculates heterogeneous kinetics
            {
                this->updateHeterogeneousChemistry();
            }

            //Calculate transport properties
            {
                kMat_ = this->massTransferCoefficient(z_[i], mu_, rho_, diff_);

                if (energyEquation_ == true)
                {
                    kHeat_ = this->heatTransferCoefficient(z_[i], mu_, cond_, cp_);
                }
            }

            rhoVector_[i] = rho_;
            cpVector_[i] = cp_;
            condVector_[i] = cond_;
            diffMatrix_[i] = diff_;
            kMatMatrix_[i] = kMat_;
            RfromGasMatrix_[i] = RfromGas_;
            QfromGasVector_[i] = QfromGas_;
            RfromSurfaceMatrix_[i] = RfromSurface_;
            QfromSurfaceVector_[i] = QfromSurface_;
            kHeatVector_[i] = kHeat_;
            if (SURF_NC_ != 0)
            {
                RsurfaceMatrix_[i] = Rsurface_;
            }
        }

        if (resolution_ == "initial")
        {
            unsigned int counter = 0;
            for (unsigned int i = 0; i < NP_; i++)
            {
                if (i == 0)
                {
                    for (unsigned int j = 0; j < NC_; j++)
                    {
                        if (j != inertIndex_)
                        {
                            dy[counter++] = omega0_[j] - omegaBMatrix_[i][j];
                        }
                        else
                        {
                            dy[counter++] = 1e03 * (1. - vectorUtils_->SumElements(omegaBMatrix_[i]));
                        }
                    }

                    for (unsigned int j = 0; j < NC_; j++)
                    {
                        if (j != inertIndex_)
                        {
                            dy[counter++] = av_ * rhoVector_[i] * kMatMatrix_[i][j] * (omegaBMatrix_[i][j] - omegaWMatrix_[i][j]) * epsi_ + alfa_ * epsi_ * RfromSurfaceMatrix_[i][j] * MW_[j];
                        }
                        else
                        {
                            dy[counter++] = 1e03 * (1. - vectorUtils_->SumElements(omegaWMatrix_[i]));
                        }
                    }

                    for (unsigned int j = 0; j < SURF_NC_; j++)
                    {
                        dy[counter++] = 0.;
                    }

                    if (energyEquation_ == true)
                    {
                        dy[counter++] = T0_ - TBvector_[i];
                        dy[counter++] = TWvector_[i + 1] - TWvector_[i];
                    }
                    else
                    {
                        dy[counter++] = 0.;
                        dy[counter++] = 0.;
                    }
                }
                else if (i == (NP_ - 1))
                {
                    for (unsigned int j = 0; j < NC_; j++)
                    {
                        if (j != inertIndex_)
                        {
                            dy[counter++] = 0.;
                        }
                        else
                        {
                            dy[counter++] = 1e03 * (1. - vectorUtils_->SumElements(omegaBMatrix_[i]));
                        }
                    }

                    for (unsigned int j = 0; j < NC_; j++)
                    {
                        if (j != inertIndex_)
                        {
                            dy[counter++] = av_ * rhoVector_[i] * kMatMatrix_[i][j] * (omegaBMatrix_[i][j] - omegaWMatrix_[i][j]) * epsi_ + alfa_ * epsi_ * RfromSurfaceMatrix_[i][j] * MW_[j];
                        }
                        else
                        {
                            dy[counter++] = 1e03 * (1. - vectorUtils_->SumElements(omegaWMatrix_[i]));
                        }
                    }

                    for (unsigned int j = 0; j < SURF_NC_; j++)
                    {
                        dy[counter++] = 0.;
                    }

                    if (energyEquation_ == true)
                    {
                        dy[counter++] = 0.;
                        dy[counter++] = TWvector_[i + 1] - TWvector_[i];
                    }
                    else
                    {
                        dy[counter++] = 0.;
                        dy[counter++] = 0.;
                    }
                }
                else
                {
                    for (unsigned int j = 0; j < NC_; j++)
                    {
                        if (j != inertIndex_)
                        {
                            dy[counter++] = 0.;
                        }
                        else
                        {
                            dy[counter++] = 1e03 * (1. - vectorUtils_->SumElements(omegaBMatrix_[i]));
                        }
                    }

                    for (unsigned int j = 0; j < NC_; j++)
                    {
                        if (j != inertIndex_)
                        {
                            dy[counter++] = av_ * rhoVector_[i] * kMatMatrix_[i][j] * (omegaBMatrix_[i][j] - omegaWMatrix_[i][j]) * epsi_ + alfa_ * epsi_ * RfromSurfaceMatrix_[i][j] * MW_[j];
                        }
                        else
                        {
                            dy[counter++] = 1e03 * (1. - vectorUtils_->SumElements(omegaWMatrix_[i]));
                        }
                    }

                    for (unsigned int j = 0; j < SURF_NC_; j++)
                    {
                        dy[counter++] = 0.;
                    }

                    dy[counter++] = 0.;
                    dy[counter++] = 0.;
                }
            }
        }
        else if (resolution_ == "model")
        {
            unsigned int counter = 0;
            for (unsigned int i = 0; i < NP_; i++)
            {
                if (i == 0)
                {
                    for (unsigned int j = 0; j < NC_; j++)
                    {
                        if (j != inertIndex_)
                        {
                            dy[counter] = omega0_[j] - omegaBMatrix_[i][j];
                            algb_[counter] = true;
                            counter++;
                        }
                        else
                        {
                            dy[counter] = (1. - vectorUtils_->SumElements(omegaBMatrix_[i]));
                            algb_[counter] = true;
                            counter++;
                        }
                    }

                    if (SURF_NC_ == 0)
                    {
                        for (unsigned int j = 0; j < NC_; j++)
                        {
                            if (j != inertIndex_)
                            {
                                dy[counter] = av_ * rhoVector_[i] * kMatMatrix_[i][j] * (omegaBMatrix_[i][j] - omegaWMatrix_[i][j]) * epsi_ + alfa_ * epsi_ * RfromSurfaceMatrix_[i][j] * MW_[j];
                                algb_[counter] = true;
                                counter++;
                            }
                            else
                            {
                                dy[counter] = (1. - vectorUtils_->SumElements(omegaWMatrix_[i]));
                                algb_[counter] = true;
                                counter++;
                            }
                        }
                    }
                    else
                    {
                        for (unsigned int j = 0; j < NC_; j++)
                        {
                            if (j != inertIndex_)
                            {
                                dy[counter] = (1. / (0.75 * rhoVector_[i])) * (av_ * rhoVector_[i] * kMatMatrix_[i][j] * (omegaBMatrix_[i][j] - omegaWMatrix_[i][j]) * epsi_ + alfa_ * epsi_ * RfromSurfaceMatrix_[i][j] * MW_[j]);
                                algb_[counter] = false;
                                counter++;
                            }
                            else
                            {
                                dy[counter] = (1. - vectorUtils_->SumElements(omegaWMatrix_[i]));
                                algb_[counter] = true;
                                counter++;
                            }
                        }
                    }

                    for (unsigned int j = 0; j < SURF_NC_; j++)
                    {
                        dy[counter] = RsurfaceMatrix_[i][j] / SD_;
                        algb_[counter] = false;
                        counter++;
                    }

                    if (energyEquation_ == true)
                    {
                        dy[counter] = T0_ - TBvector_[i];
                        algb_[counter] = true;
                        counter++;
                        dy[counter] = TWvector_[i + 1] - TWvector_[i];
                        algb_[counter] = true;
                        counter++;
                    }
                    else
                    {
                        dy[counter] = 0.;
                        algb_[counter] = false;
                        counter++;
                        dy[counter] = 0.;
                        algb_[counter] = false;
                        counter++;
                    }
                }
                else if (i == (NP_ - 1))
                {
                    for (unsigned int j = 0; j < NC_; j++)
                    {
                        if (j != inertIndex_)
                        {
                            dy[counter] = -(G_ / (rhoVector_[i] * epsi_)) * (omegaBMatrix_[i][j] - omegaBMatrix_[i - 1][j]) / dz_ - av_ * kMatMatrix_[i][j] * (omegaBMatrix_[i][j] - omegaWMatrix_[i][j]) / epsi_ + RfromGasMatrix_[i][j] / rhoVector_[i];
                            algb_[counter] = false;
                            counter++;
                        }
                        else
                        {
                            dy[counter] = (1. - vectorUtils_->SumElements(omegaBMatrix_[i]));
                            algb_[counter] = true;
                            counter++;
                        }
                    }

                    if (SURF_NC_ == 0)
                    {
                        for (unsigned int j = 0; j < NC_; j++)
                        {
                            if (j != inertIndex_)
                            {
                                dy[counter] = av_ * rhoVector_[i] * kMatMatrix_[i][j] * (omegaBMatrix_[i][j] - omegaWMatrix_[i][j]) * epsi_ + alfa_ * epsi_ * RfromSurfaceMatrix_[i][j] * MW_[j];
                                algb_[counter] = true;
                                counter++;
                            }
                            else
                            {
                                dy[counter] = (1. - vectorUtils_->SumElements(omegaWMatrix_[i]));
                                algb_[counter] = true;
                                counter++;
                            }
                        }
                    }
                    else
                    {
                        for (unsigned int j = 0; j < NC_; j++)
                        {
                            if (j != inertIndex_)
                            {
                                dy[counter] = (1. / (0.75 * rhoVector_[i])) * (av_ * rhoVector_[i] * kMatMatrix_[i][j] * (omegaBMatrix_[i][j] - omegaWMatrix_[i][j]) * epsi_ + alfa_ * epsi_ * RfromSurfaceMatrix_[i][j] * MW_[j]);
                                algb_[counter] = false;
                                counter++;
                            }
                            else
                            {
                                dy[counter] = (1. - vectorUtils_->SumElements(omegaWMatrix_[i]));
                                algb_[counter] = true;
                                counter++;
                            }
                        }
                    }

                    for (unsigned int j = 0; j < SURF_NC_; j++)
                    {
                        dy[counter] = RsurfaceMatrix_[i][j] / SD_;
                        algb_[counter] = false;
                        counter++;
                    }

                    if (energyEquation_ == true)
                    {
                        dy[counter] = -(G_ / (rhoVector_[i] * epsi_)) * (TBvector_[i] - TBvector_[i - 1]) / dz_ + kHeatVector_[i] * av_ * (TBvector_[i] - TWvector_[i]) / (epsi_ * rhoVector_[i] * cpVector_[i]) + QfromGasVector_[i] / (rhoVector_[i] * cpVector_[i]);
                        algb_[counter] = false;
                        counter++;
                        dy[counter] = TWvector_[i + 1] - TWvector_[i];
                        algb_[counter] = true;
                        counter++;
                    }
                    else
                    {
                        dy[counter] = 0.;
                        algb_[counter] = false;
                        counter++;
                        dy[counter] = 0.;
                        algb_[counter] = false;
                        counter++;
                    }
                }
                else
                {
                    for (unsigned int j = 0; j < NC_; j++)
                    {
                        if (j != inertIndex_)
                        {
                            dy[counter] = -(G_ / (rhoVector_[i] * epsi_)) * (omegaBMatrix_[i][j] - omegaBMatrix_[i - 1][j]) / dz_ - av_ * kMatMatrix_[i][j] * (omegaBMatrix_[i][j] - omegaWMatrix_[i][j]) / epsi_ + RfromGasMatrix_[i][j] / rhoVector_[i];
                            algb_[counter] = false;
                            counter++;
                        }
                        else
                        {
                            dy[counter] = (1. - vectorUtils_->SumElements(omegaBMatrix_[i]));
                            algb_[counter] = true;
                            counter++;
                        }
                    }

                    if (SURF_NC_ == 0)
                    {
                        for (unsigned int j = 0; j < NC_; j++)
                        {
                            if (j != inertIndex_)
                            {
                                dy[counter] = av_ * rhoVector_[i] * kMatMatrix_[i][j] * (omegaBMatrix_[i][j] - omegaWMatrix_[i][j]) * epsi_ + alfa_ * epsi_ * RfromSurfaceMatrix_[i][j] * MW_[j];
                                algb_[counter] = true;
                                counter++;
                            }
                            else
                            {
                                dy[counter] = (1. - vectorUtils_->SumElements(omegaWMatrix_[i]));
                                algb_[counter] = true;
                                counter++;
                            }
                        }
                    }
                    else
                    {
                        for (unsigned int j = 0; j < NC_; j++)
                        {
                            if (j != inertIndex_)
                            {
                                dy[counter] = (1. / (0.75 * rhoVector_[i])) * (av_ * rhoVector_[i] * kMatMatrix_[i][j] * (omegaBMatrix_[i][j] - omegaWMatrix_[i][j]) * epsi_ + alfa_ * epsi_ * RfromSurfaceMatrix_[i][j] * MW_[j]);
                                algb_[counter] = false;
                                counter++;
                            }
                            else
                            {
                                dy[counter] = (1. - vectorUtils_->SumElements(omegaWMatrix_[i]));
                                algb_[counter] = true;
                                counter++;
                            }
                        }
                    }

                    for (unsigned int j = 0; j < SURF_NC_; j++)
                    {
                        dy[counter] = RsurfaceMatrix_[i][j] / SD_;
                        algb_[counter] = false;
                        counter++;
                    }

                    if (energyEquation_ == true)
                    {
                        dy[counter] = -(G_ / (rhoVector_[i] * epsi_)) * (TBvector_[i] - TBvector_[i - 1]) / dz_ - kHeatVector_[i] * av_ * (TBvector_[i] - TWvector_[i]) / (epsi_ * rhoVector_[i] * cpVector_[i]) + QfromGasVector_[i] / (rhoVector_[i] * cpVector_[i]);
                        algb_[counter] = false;
                        counter++;
                        dy[counter] = (conds_ / (rhos_ * cp_)) * (TWvector_[i + 1] - 2 * TWvector_[i] + TWvector_[i - 1]) / (dz_ * dz_) + kHeatVector_[i] * av_ * (TBvector_[i] - TWvector_[i]) / ((1. - epsi_) * rhos_ * cps_) + alfa_ * QfromSurfaceVector_[i] / ((1. - epsi_) * rhos_ * cps_);
                        algb_[counter] = false;
                        counter++;
                    }
                    else
                    {
                        dy[counter] = 0.;
                        algb_[counter] = false;
                        counter++;
                        dy[counter] = 0.;
                        algb_[counter] = false;
                        counter++;
                    }
                }
            }
        }
        return 0;
    }

    void het1dEquations::store(const double tf, const std::vector<double> xf)
    {
        // Recover unknowns
        {
            unsigned int counter = 0;
            for (unsigned int i = 0; i < NP_; i++)
            {
                for (unsigned int j = 0; j < NC_; j++)
                {
                    omegaBMatrix_[i][j] = xf[counter++];
                }

                for (unsigned int j = 0; j < NC_; j++)
                {
                    omegaWMatrix_[i][j] = xf[counter++];
                }

                for (unsigned int j = 0; j < SURF_NC_; j++)
                {
                    Zmatrix_[i][j] = xf[counter++];
                }

                TBvector_[i] = xf[counter++];
                TWvector_[i] = xf[counter++];
            }
        }

        Time_.push_back(tf);
        SpecieB_.push_back(omegaBMatrix_);
        SpecieW_.push_back(omegaWMatrix_);
        Site_.push_back(Zmatrix_);
        TemperatureB_.push_back(TBvector_);
        TemperatureW_.push_back(TWvector_);
    }

    std::vector<double> het1dEquations::massTransferCoefficient(const double z, const double mu, const double rho, const std::vector<double> d)
    {
        std::vector<double> kMat(NC_);
        if (reactorType_ == "honeycomb" ||
            reactorType_ == "tubular")
        {
            double Re = G_ * Dt_ / (mu * epsi_);
            for (unsigned int i = 0; i < NC_; i++)
            {
                if (d[i] != 0.)
                {
                    double Sc = mu / (rho * d[i]);
                    double zStar = std::fabs(std::max(z, 1e-06) / (Dt_ * Re * Sc));
                    double Sh = Shinf_ + 6.874 * std::pow((1000. * zStar), -0.488) * std::exp(-57.2 * zStar);
                    kMat[i] = Sh * d[i] / Dt_;
                }
                else
                {
                    kMat[i] = 1.;
                }
            }
        }
        else if (reactorType_ == "packedBed")
        {
            //Yoshida et al.
            double Re = G_ * Dt_ / (mu_ * (1. - epsi_) * 6.);
            double ReReal = G_ * Dt_ / mu_;
            double Sc;
            double Sh;
            double jM;
            for (unsigned int i = 0; i < NC_; i++)
            {
                if (diff_[i] != 0.)
                {
                    Sc = mu_ / (rho_ * diff_[i]);
                    if (Re < 50.)
                    {
                        jM = 0.91 / (std::pow(Re, 0.51));
                        Sh = jM * std::pow(Sc, (1. / 3.)) * ReReal;
                        kMat[i] = Sh * diff_[i] / Dt_;
                    }
                    else
                    {
                        jM = 0.61 / (std::pow(Re, 0.41));
                        Sh = jM * std::pow(Sc, (1. / 3.)) * ReReal;
                        kMat[i] = Sh * diff_[i] / Dt_;
                    }
                }
                else
                {
                    kMat[i] = 1.;
                }
            }
        }

        return kMat;
    }

    double het1dEquations::heatTransferCoefficient(const double z, const double mu, const double cond, const double cp)
    {
        double kHeat = 0.;
        if (reactorType_ == "honeycomb" ||
            reactorType_ == "tubular")
        {
            double Re = G_ * Dt_ / (mu * epsi_);
            double Pr = cp * mu / cond;
            double zStar = std::fabs(std::max(z, 1e-06) / (Dt_ * Re * Pr));
            double Nu = Nuinf_ + 8.827 * std::pow((1000. * zStar), -0.545) * std::exp(-48.2 * zStar);
            kHeat = Nu * cond / Dt_;
        }
        else if (reactorType_ == "packed bed")
        {
            //Yoshida et al.
            double Re = G_ * Dt_ / (mu * (1. - epsi_) * 6.);
            double ReReal = G_ * Dt_ / mu;
            double Pr = cp * mu / cond;
            if (Re < 50.)
            {
                double jM = 0.91 / (std::pow(Re, 0.51));
                double Nu = jM * std::pow(Pr, (1. / 3.)) * ReReal;
                kHeat = Nu * cond / Dt_;
            }
            else
            {
                double jM = 0.61 / (std::pow(Re, 0.41));
                double Nu = jM * std::pow(Pr, (1. / 3.)) * ReReal;
                kHeat = Nu * cond / Dt_;
            }
        }
        return kHeat;
    }
}
