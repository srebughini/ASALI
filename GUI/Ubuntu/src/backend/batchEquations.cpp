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

#include "backend/batchEquations.hpp"

namespace ASALI
{
    batchEquations::batchEquations()
    {
    }

    void batchEquations::resize()
    {
        if (type_ == "CANTERA")
        {
            NC_ = chemistryInterface_->numberOfGasSpecies();
            SURF_NC_ = chemistryInterface_->numberOfSurfaceSpecies();
            NE_ = NC_ + SURF_NC_ + 1 + 1;

            x_.resize(NC_);
            omega_.resize(NC_);
            MW_.resize(NC_);
            RfromGas_.resize(NC_);
            RfromSurface_.resize(NC_);

            Z_.resize(NC_);
            Rsurface_.resize(SURF_NC_);

            SD_ = 1.;

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
            NE_ = NC_ + SURF_NC_ + 1 + 1;

            x_.resize(NC_);
            omega_.resize(NC_);
            MW_.resize(NC_);
            RfromGas_.resize(NC_);
            RfromSurface_.resize(NC_);
            h_.resize(NC_);

            SD_ = 1.;
            alfa_ = 1.;
        }

        {
            Time_.clear();
            Specie_.clear();
            Site_.clear();
            Temperature_.clear();
            Volume_.clear();
            Mass_.clear();
        }
    }

    void batchEquations::setEnergy(const bool flag)
    {
        energyEquation_ = flag;
    }

    void batchEquations::setPressure(const double P)
    {
        P_ = P;
    }

    void batchEquations::setTemperature(const double T)
    {
        T_ = T;
    }

    void batchEquations::setVolume(const double V)
    {
        V_ = V;
    }

    void batchEquations::setCatalystLoad(const double alfa)
    {
        alfa_ = alfa;
    }

    int batchEquations::Equations(double &t, std::vector<double> &y, std::vector<double> &dy)
    {
        // Recover unknowns
        {
            unsigned int counter = 0;

            for (unsigned int i = 0; i < NC_; i++)
            {
                omega_[i] = y[counter++];
            }

            mass_ = y[counter++];

            for (unsigned int i = 0; i < SURF_NC_; i++)
            {
                Z_[i] = y[counter++];
            }

            T_ = y[counter++];
        }

        // Calculates the volume and the concentrations of species
        if (userCheck_ == false)
        {
            double canteraArray[chemistryInterface_->numberOfGasSpecies()];
            memset(canteraArray, 0., sizeof(canteraArray));
            for (unsigned int i = 0; i < NC_; i++)
            {
                canteraArray[canteraIndex_[i]] = omega_[i];
            }

            MWmix_ = chemistryInterface_->getMWmix();
            cTot_ = P_ / (8314. * T_);
            rho_ = cTot_ * MWmix_;
            V_ = mass_ / rho_;

            chemistryInterface_->setStateFromMassFraction(canteraArray, T_, P_);

            std::vector<double> x = chemistryInterface_->mole();
            std::vector<double> mw = chemistryInterface_->getMW();

            for (unsigned int i = 0; i < NC_; i++)
            {
                MW_[i] = mw[canteraIndex_[i]];
                x_[i] = x[canteraIndex_[i]];
            }

            cp_ = chemistryInterface_->getCpMassMix();
        }
        else
        {
            MWmix_ = this->meanMolecularWeight(omega_, MW_);
            x_ = this->moleFraction(omega_, MW_, MWmix_);
            cTot_ = P_ / (8314. * T_);
            rho_ = cTot_ * MWmix_;
            V_ = mass_ / rho_;
        }

		// Calculates homogeneous kinetics
		{
			this->updateHomogenousChemistry();
		}

		// Calculates heterogeneous kinetics
		{
			this->updateHeterogeneousChemistry();
		}

        // Variation of gas mass in the reactor
        const double dm_over_dt = V_ * alfa_ * DotProduct(RfromSurface_, MW_);

        // Recovering residuals
        {
            unsigned int counter = 0;

            // Gas phase species
            for (unsigned int i = 0; i < NC_; i++)
            {
                dy[counter++] = MW_[i] * RfromGas_[i] / rho_ + (-omega_[i] * dm_over_dt + V_ * alfa_ * RfromSurface_[i] * MW_[i]) / mass_;
            }

            // Total mass
            dy[counter++] = dm_over_dt;

            // Surface site species
            for (unsigned int i = 0; i < SURF_NC_; i++)
            {
                dy[counter++] = Rsurface_[i] / SD_;
            }

            // Energy equation
            if (energyEquation_ == true)
            {
                dy[counter++] = (V_ * QfromGas_ + V_ * alfa_ * QfromSurface_) / (mass_ * cp_);
            }
            else
            {
                dy[counter++] = 0.;
            }
        }
        return 0;
    }

    void batchEquations::store(const double tf, const std::vector<double> xf)
    {
        // Recover unknowns
        {
            unsigned int counter = 0;

            for (unsigned int i = 0; i < NC_; i++)
                omega_[i] = xf[counter++];

            mass_ = xf[counter++];

            for (unsigned int i = 0; i < SURF_NC_; i++)
                Z_[i] = xf[counter++];

            T_ = xf[counter++];
        }

        {
            Time_.push_back(tf);
            Specie_.push_back(omega_);
            Site_.push_back(Z_);
            Temperature_.push_back(T_);
            Volume_.push_back(V_);
            Mass_.push_back(mass_);
        }
    }

    batchEquations::~batchEquations()
    {
    }
}
