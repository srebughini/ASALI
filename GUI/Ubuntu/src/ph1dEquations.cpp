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

#include "ph1dEquations.hpp"

namespace ASALI
{
    ph1dEquations::ph1dEquations()
    {}

    void ph1dEquations::resize()
    {
        if ( resolution_ == "steady state" )
        {
            if ( type_ == "CANTERA" )
            {
                NC_      = gas_->nSpecies();
                SURF_NC_ = surface_->nSpecies();
                NE_      = NC_ + SURF_NC_ + 1;

                x_.resize(NC_);
                omega_.resize(NC_);
                MW_.resize(NC_);
                RfromGas_.resize(NC_);
                RfromSurface_.resize(NC_);
                
                Z_.resize(SURF_NC_);
                Rsurface_.resize(SURF_NC_);

                SD_ = 1.;
                
                canteraIndex_.resize(NC_);
                for (unsigned int i=0;i<NC_;i++)
                {
                    canteraIndex_[i] = i;
                }
                
            }
            else if ( type_ == "ASALI" )
            {
                NC_      = canteraIndex_.size();
                SURF_NC_ = 0;
                NE_      = NC_ + SURF_NC_ + 1;

                x_.resize(NC_);
                omega_.resize(NC_);
                MW_.resize(NC_);
                RfromGas_.resize(NC_);
                RfromSurface_.resize(NC_);
                h_.resize(NC_);

                SD_   = 1.;
                alfa_ = 1.;
            }
        }
        else if ( resolution_ == "transient" ||
                  resolution_ == "initial")
        {
            if ( type_ == "CANTERA" )
            {
                NC_      = gas_->nSpecies();
                SURF_NC_ = surface_->nSpecies();
                NE_      = NP_*(NC_ + SURF_NC_ + 1);

                x_.resize(NC_);
                omega_.resize(NC_);
                MW_.resize(NC_);
                diff_.resize(NC_);
                RfromGas_.resize(NC_);
                RfromSurface_.resize(NC_);
                h_.resize(NC_);

                Z_.resize(SURF_NC_);
                Rsurface_.resize(SURF_NC_);
                
                Tvector_.resize(NP_);
                rhoVector_.resize(NP_);
                cpVector_.resize(NP_);
                condVector_.resize(NP_);
                QfromGasVector_.resize(NP_);
                QfromSurfaceVector_.resize(NP_);
                omegaMatrix_.resize(NP_);
                Zmatrix_.resize(NP_);
                diffMatrix_.resize(NP_);
                RfromGasMatrix_.resize(NP_);
                RfromSurfaceMatrix_.resize(NP_);
                RsurfaceMatrix_.resize(NP_);
                for (unsigned int i=0;i<NP_;i++)
                {
                    omegaMatrix_[i].resize(NC_);
                    diffMatrix_[i].resize(NC_);
                    RfromGasMatrix_[i].resize(NC_);
                    RfromSurfaceMatrix_[i].resize(NC_);
                    Zmatrix_[i].resize(SURF_NC_);
                    RsurfaceMatrix_[i].resize(SURF_NC_);
                }
                
                
                algb_.resize(NE_);

                SD_ = 1.;
                
                canteraIndex_.resize(NC_);
                for (unsigned int i=0;i<NC_;i++)
                {
                    canteraIndex_[i] = i;
                }
                
            }
            else if ( type_ == "ASALI" )
            {
                NC_      = canteraIndex_.size();
                SURF_NC_ = 0;
                NE_      = NP_*(NC_ + SURF_NC_ + 1);

                x_.resize(NC_);
                omega_.resize(NC_);
                MW_.resize(NC_);
                diff_.resize(NC_);
                RfromGas_.resize(NC_);
                RfromSurface_.resize(NC_);
                h_.resize(NC_);
                
                Tvector_.resize(NP_);
                rhoVector_.resize(NP_);
                cpVector_.resize(NP_);
                condVector_.resize(NP_);
                QfromGasVector_.resize(NP_);
                QfromSurfaceVector_.resize(NP_);
                omegaMatrix_.resize(NP_);
                diffMatrix_.resize(NP_);
                RfromGasMatrix_.resize(NP_);
                RfromSurfaceMatrix_.resize(NP_);
                for (unsigned int i=0;i<NP_;i++)
                {
                    omegaMatrix_[i].resize(NC_);
                    diffMatrix_[i].resize(NC_);
                    RfromGasMatrix_[i].resize(NC_);
                    RfromSurfaceMatrix_[i].resize(NC_);
                }

                algb_.resize(NE_);

                SD_   = 1.;
                alfa_ = 1.;
            }
        }

        {
            Length_.clear();
            Specie_.clear();
            Site_.clear();
            Time_.clear();
            Temperature_.clear();
            Pressure_.clear();
            SpecieTransient_.clear();
            SiteTransient_.clear();
            TemperatureTransient_.clear();
        }
    }

    void ph1dEquations::setPressure(const double P)
    {
        P_ = P;
    }

    void ph1dEquations::setTemperature (const double T)
    {
        T_ = T;
    }

    void ph1dEquations::setLength(const double L)
    {
        L_  = L;
        dz_ = L_/double(NP_-1);
    }

    void ph1dEquations::setSpecificMassFlowRate(const double G)
    {
        G_ = G;
    }

    void ph1dEquations::setNumberOfPoints(const double NP)
    {
        NP_ = int(NP);
    }

    void ph1dEquations::setCatalystLoad(const double alfa)
    {
        alfa_ = alfa;
    }

    void ph1dEquations::setResolutionType(const std::string resolution)
    {
        resolution_ = resolution;
    }


    void ph1dEquations::setInletConditions(const std::vector<double> omega0, const double T0)
    {
        omega0_ = omega0;
        T0_     = T0;
    }


    int ph1dEquations::Equations(double& t, std::vector<double>& y, std::vector<double>& dy)
    {
        if ( resolution_ == "steady state" )
        {
            // Recover unknowns
            {
                unsigned int counter=0;

                for(unsigned int i=0;i<NC_;i++)
                    omega_[i] = y[counter++];

                for(unsigned int i=0;i<SURF_NC_;i++)
                    Z_[i] = y[counter++];

                T_ = y[counter++];
            }

            // Calculates the volume and the concentrations of species
            if ( userCheck_ == false )
            {
                double canteraArray[gas_->nSpecies()];
                memset(canteraArray,0.,sizeof(canteraArray));
                for (unsigned int i=0;i<NC_;i++)
                {
                    canteraArray[canteraIndex_[i]] = omega_[i];
                }
                MWmix_ = gas_->meanMolecularWeight();
                cTot_  = P_/(8314.*T_);
                rho_   = cTot_*MWmix_;

                gas_->setState_TPY(T_,P_,canteraArray);
                
                gas_->getMoleFractions(canteraArray);

                for (unsigned int i=0;i<NC_;i++)
                {
                    MW_[i] = gas_->molecularWeight(canteraIndex_[i]);
                    x_[i]  = canteraArray[canteraIndex_[i]];
                }

                cp_ = gas_->cp_mass();
            }
            else
            {
                MWmix_ = this->meanMolecularWeight(omega_,MW_);
                x_     = this->moleFraction(omega_,MW_,MWmix_);
                cTot_  = P_/(8314.*T_);
                rho_   = cTot_*MWmix_;
            }

            // Calculates homogeneous kinetics
            {
                #include "shared/HomogeneousReactions.H"
            }

            // Calculates heterogeneous kinetics
            {
                #include "shared/HeterogeneousReactions.H"
            }

            // Recovering residuals
            {
                unsigned int counter=0;
            
                // Gas phase species
                for (unsigned int i=0;i<NC_;i++)
                {
                    dy[counter++] = (MW_[i]*RfromGas_[i] + alfa_*RfromSurface_[i]*MW_[i])/(G_);
                }

                // Surface site species
                for (unsigned int i=0;i<SURF_NC_;i++)    
                {
                    dy[counter++] = 1e03*(Rsurface_[i]/SD_);
                }

                // Energy equation
                if (energyEquation_ == true)
                {
                    dy[counter++] = (QfromGas_+ alfa_*QfromSurface_)/(G_*cp_);
                }
                else
                {
                    dy[counter++] = 0.;
                }
            }
        }
        else if ( resolution_ == "transient" )
        {
            // Recover unknowns
            {
                unsigned int counter=0;
                for (unsigned int i=0;i<NP_;i++)
                {
                    for(unsigned int j=0;j<NC_;j++)
                    {
                        omegaMatrix_[i][j] = y[counter++];
                    }

                    for(unsigned int j=0;j<SURF_NC_;j++)
                    {
                        Zmatrix_[i][j] = y[counter++];
                    }

                    Tvector_[i] = y[counter++];
                }
            }

            for (unsigned int i=0;i<NP_;i++)
            {
                
                omega_ = omegaMatrix_[i];
                T_     = Tvector_[i];

                if ( SURF_NC_ != 0 )
                {
                    Z_     = Zmatrix_[i];
                }

                // Calculates the volume and the concentrations of species
                if ( userCheck_ == false )
                {
                    double canteraArray[gas_->nSpecies()];
                    memset(canteraArray,0.,sizeof(canteraArray));
                    for (unsigned int j=0;j<NC_;j++)
                    {
                        canteraArray[canteraIndex_[j]] = omega_[j];
                    }

                    MWmix_ = gas_->meanMolecularWeight();
                    cTot_  = P_/(8314.*T_);
                    rho_   = cTot_*MWmix_;

                    gas_->setState_TPY(T_,P_,canteraArray);
                    
                    gas_->getMoleFractions(canteraArray);

                    for (unsigned int j=0;j<NC_;j++)
                    {
                        MW_[j] = gas_->molecularWeight(canteraIndex_[j]);
                        x_[j]  = canteraArray[canteraIndex_[j]];
                    }

                    for (unsigned int j=0;j<NC_;j++)
                    {
                        MW_[j] = gas_->molecularWeight(canteraIndex_[j]);
                    }

                    transport_->getMixDiffCoeffs(canteraArray);

                    for (unsigned int j=0;j<NC_;j++)
                    {
                        diff_[j] = canteraArray[canteraIndex_[j]];
                    }

                    cp_   = gas_->cp_mass();
                    cond_ = transport_->thermalConductivity();
                }
                else
                {
                    MWmix_ = this->meanMolecularWeight(omega_,MW_);
                    x_     = this->moleFraction(omega_,MW_,MWmix_);
                    cTot_  = P_/(8314.*T_);
                    rho_   = cTot_*MWmix_;
                }

                // Calculates homogeneous kinetics
                {
                    #include "shared/HomogeneousReactions.H"
                }

                // Calculates heterogeneous kinetics
                {
                    #include "shared/HeterogeneousReactions.H"
                }

                rhoVector_[i]          = rho_;
                cpVector_[i]           = cp_;
                condVector_[i]         = cond_;
                diffMatrix_[i]         = diff_;
                RfromGasMatrix_[i]     = RfromGas_;
                QfromGasVector_[i]     = QfromGas_;
                RfromSurfaceMatrix_[i] = RfromSurface_;
                QfromSurfaceVector_[i] = QfromSurface_;
                if ( SURF_NC_ != 0 )
                {
                    RsurfaceMatrix_[i] = Rsurface_;
                }
            }

            unsigned int counter = 0;
            for (unsigned int i=0;i<NP_;i++)
            {
                if ( i == 0 )
                {
                    for (unsigned int j=0;j<NC_;j++)
                    {
                        dy[counter]    = omega0_[j] - omegaMatrix_[i][j];
                        algb_[counter] = true;
                        counter++;
                    }

                    for (unsigned int j=0;j<SURF_NC_;j++)
                    {
                        dy[counter]    = RsurfaceMatrix_[i][j]/SD_;
                        algb_[counter] = false;
                        counter++;
                    }
                    
                    dy[counter]    = T0_ - Tvector_[i];
                    algb_[counter] = true;
                    counter++;
                }
                else if ( i == NP_ - 1)
                {
                    for (unsigned int j=0;j<NC_;j++)
                    {
                        dy[counter]    = omegaMatrix_[i][j] - omegaMatrix_[i-1][j];
                        algb_[counter] = true;
                        counter++;
                    }

                    for (unsigned int j=0;j<SURF_NC_;j++)
                    {
                        dy[counter]    = RsurfaceMatrix_[i][j]/SD_;
                        algb_[counter] = false;
                        counter++;
                    }
                    
                    dy[counter]    = Tvector_[i] - Tvector_[i-1];
                    algb_[counter] = true;
                    counter++;
                }
                else
                {
                    for (unsigned int j=0;j<NC_;j++)
                    {
                        dy[counter]    = -(G_/rhoVector_[i])*(omegaMatrix_[i][j] - omegaMatrix_[i-1][j])/dz_
                                         + diffMatrix_[i][j]*(omegaMatrix_[i+1][j] -2.*omegaMatrix_[i][j] + omegaMatrix_[i-1][j])/(dz_*dz_)
                                         + RfromGasMatrix_[i][j]/rhoVector_[i]
                                         + alfa_*RfromSurfaceMatrix_[i][j]*MW_[j]/rhoVector_[i];
                        algb_[counter] = false;
                        counter++;
                    }
                    
                    for (unsigned int j=0;j<SURF_NC_;j++)
                    {
                        dy[counter]    = RsurfaceMatrix_[i][j]/SD_;
                        algb_[counter] = false;
                        counter++;
                    }
                    
                    dy[counter]    = -(G_/(cpVector_[i]*rhoVector_[i]))*(Tvector_[i] - Tvector_[i-1])/dz_
                                     +(condVector_[i]/(rhoVector_[i]*cpVector_[i]))*(Tvector_[i+1] -2.*Tvector_[i] + Tvector_[i-1])/(dz_*dz_)
                                     + QfromGasVector_[i]/(cpVector_[i]*rhoVector_[i])
                                     + alfa_*QfromSurfaceVector_[i]/(cpVector_[i]*rhoVector_[i]);
                    algb_[counter] = false;
                    counter++;
                }
            }
        }
        else if ( resolution_ == "initial" )
        {
            // Recover unknowns
            {
                unsigned int counter=0;
                for (unsigned int i=0;i<NP_;i++)
                {
                    for(unsigned int j=0;j<NC_;j++)
                    {
                        omegaMatrix_[i][j] = y[counter++];
                    }

                    for(unsigned int j=0;j<SURF_NC_;j++)
                    {
                        Zmatrix_[i][j] = y[counter++];
                    }

                    Tvector_[i] = y[counter++];
                }
            }

            unsigned int counter = 0;
            for (unsigned int i=0;i<NP_;i++)
            {
                if ( i == 0 )
                {
                    for (unsigned int j=0;j<NC_;j++)
                    {
                        dy[counter] = 1e03*(omega0_[j] - omegaMatrix_[i][j]);
                        counter++;
                    }

                    for (unsigned int j=0;j<SURF_NC_;j++)
                    {
                        dy[counter] = 0.;
                        counter++;
                    }
                    
                    dy[counter]    = 1e03*(T0_ - Tvector_[i]);
                    counter++;
                }
                else if ( i == NP_ - 1)
                {
                    for (unsigned int j=0;j<NC_;j++)
                    {
                        dy[counter] = 1e03*(omegaMatrix_[i][j] - omegaMatrix_[i-1][j]);
                        counter++;
                    }

                    for (unsigned int j=0;j<SURF_NC_;j++)
                    {
                        dy[counter] = 0.;
                        counter++;
                    }
                    
                    dy[counter] = 1e03*(Tvector_[i] - Tvector_[i-1]);
                    counter++;
                }
                else
                {
                    for (unsigned int j=0;j<NC_;j++)
                    {
                        dy[counter] = 0.;
                        counter++;
                    }
                    
                    for (unsigned int j=0;j<SURF_NC_;j++)
                    {
                        dy[counter] = 0.;
                        counter++;
                    }
                
                    dy[counter] = 0.;
                    counter++;
                }
            }
        }

        return 0;
    }

    void ph1dEquations::store(const double tf,const std::vector<double> xf)
    {
        if ( resolution_ == "transient" )
        {
            // Recover unknowns
            {
                unsigned int counter=0;
                for (unsigned int i=0;i<NP_;i++)
                {
                    for(unsigned int j=0;j<NC_;j++)
                    {
                        omegaMatrix_[i][j] = xf[counter++];
                    }

                    for(unsigned int j=0;j<SURF_NC_;j++)
                    {
                        Zmatrix_[i][j] = xf[counter++];
                    }

                    Tvector_[i] = xf[counter++];
                }
            }

            Time_.push_back(tf);
            SpecieTransient_.push_back(omegaMatrix_);
            SiteTransient_.push_back(Zmatrix_);
            TemperatureTransient_.push_back(Tvector_);
        }
        else if ( resolution_ == "steady state" )
        {
            // Recover unknowns
            {
                unsigned int counter=0;

                for(unsigned int i=0;i<NC_;i++)
                    omega_[i] = xf[counter++];

                for(unsigned int i=0;i<SURF_NC_;i++)
                    Z_[i] = xf[counter++];

                T_ = xf[counter++];
            }
            
            Length_.push_back(tf);
            Specie_.push_back(omega_);
            Site_.push_back(Z_);
            Temperature_.push_back(T_);
        }
    }
    
}
