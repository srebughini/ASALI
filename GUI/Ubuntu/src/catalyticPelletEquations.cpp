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

#include "catalyticPelletEquations.hpp"

namespace ASALI
{
    catalyticPelletEquations::catalyticPelletEquations()
    {}

    void catalyticPelletEquations::resize()
    {
        if ( type_ == "CANTERA" )
        {
            NC_      = gas_->nSpecies();
            SURF_NC_ = surface_->nSpecies();
            NE_      = NP_*(NC_ + SURF_NC_);

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
            NE_      = NP_*(NC_ + SURF_NC_);
        }
        
        {
            omega0_.resize(NC_);
            x_.resize(NC_);
            omega_.resize(NC_);
            MW_.resize(NC_);
            diff_.resize(NC_);
            RfromGas_.resize(NC_);
            RfromSurface_.resize(NC_);

            Z_.resize(SURF_NC_);
            Rsurface_.resize(SURF_NC_);

            rhoVector_.resize(NP_);
            omegaMatrix_.resize(NP_);
            xMatrix_.resize(NP_);
            Zmatrix_.resize(NP_);
            diffMatrix_.resize(NP_);
            fluxMatrix_.resize(NP_);
            MwMatrix_.resize(NP_);
            RfromGasMatrix_.resize(NP_);
            RfromSurfaceMatrix_.resize(NP_);
            RsurfaceMatrix_.resize(NP_);
            for (unsigned int i=0;i<NP_;i++)
            {
                omegaMatrix_[i].resize(NC_);
                xMatrix_[i].resize(NC_);
                diffMatrix_[i].resize(NC_);
                fluxMatrix_[i].resize(NC_);
                MwMatrix_[i].resize(NC_);
                RfromGasMatrix_[i].resize(NC_);
                RfromSurfaceMatrix_[i].resize(NC_);
                Zmatrix_[i].resize(SURF_NC_);
                RsurfaceMatrix_[i].resize(SURF_NC_);
            }
            
            diffBinaryMatrix_.resize(NP_);
            for (unsigned int i=0;i<NP_;i++)
            {
                diffBinaryMatrix_[i].resize(NC_);
                for (unsigned int j=0;j<NC_;j++)
                {
                    diffBinaryMatrix_[i][j].resize(NC_);
                }
            }

            algb_.resize(NE_);

            SD_ = 1.;
            
            energyEquation_ = false;
        }

        {
            Length_.clear();
            Specie_.clear();
            Site_.clear();
            Time_.clear();
        }
    }

    void catalyticPelletEquations::setPressure(const double P)
    {
        P_ = P;
    }

    void catalyticPelletEquations::setTemperature(const double T)
    {
        T_ = T;
    }

    void catalyticPelletEquations::setPelletType(const std::string pelletType)
    {
        pelletType_ = pelletType;
    }

    void catalyticPelletEquations::setDiffusionModel(const std::string modelType)
    {
        modelType_ = modelType;
    }

    void catalyticPelletEquations::setResolutionType(const std::string resolution)
    {
        resolution_ = resolution;
    }

    void catalyticPelletEquations::setSlab(const double tw)
    {
        tw_ = tw;
        dz_ = tw_/(NP_-1);
        
        Length_.resize(NP_);
        
        for (unsigned int i=0;i<NP_;i++)
        {
            Length_[i] = double(i)*dz_;
        }
    }
    
    void catalyticPelletEquations::setSphere(const double D)
    {
        D_  = D;
        r_  = D_*0.5;
        dz_ = r_/(NP_-1);
        
        Length_.resize(NP_);
        
        for (unsigned int i=0;i<NP_;i++)
        {
            Length_[i] = double(i)*dz_;
        }
    }

    void catalyticPelletEquations::setCylinder(const double D)
    {
        D_  = D;
        r_  = D_*0.5;
        dz_ = r_/(NP_-1);
        
        Length_.resize(NP_);
        
        for (unsigned int i=0;i<NP_;i++)
        {
            Length_[i] = double(i)*dz_;
        }
    }

    void catalyticPelletEquations::setNumberOfPoints(const double NP)
    {
        NP_ = int(NP);
    }

    void catalyticPelletEquations::setCatalystProperties(const double alfa,const double tau,const double epsi)
    {
        alfa_  = alfa;
        tau_   = tau;
        epsi_  = epsi;
    }
    
    void catalyticPelletEquations::setPoreDiameter(const double dp)
    {
        dp_ = dp;
    }
    
    void catalyticPelletEquations::setInert(const unsigned int inertIndex)
    {
        inertIndex_ = inertIndex;
    }
    
    void catalyticPelletEquations::setInletConditions(const std::vector<double> omega0)
    {
        omega0_ = omega0;
    }

    std::vector<std::vector<double> > catalyticPelletEquations::epsi_tau_model(const std::vector<std::vector<double> > diff,const std::vector<std::vector<double> > omega)
    {
        std::vector<std::vector<double> > N = diff;
        for (unsigned int i=0;i<NP_;i++)
        {
            if ( i == 0 )
            {
                for (unsigned int j=0;j<NC_;j++)
                {
                    N[i][j] = (epsi_/tau_)*(diff[i+1][j]*omega[i+1][j] - diff[i][j]*omega[i][j])/dz_;
                }
            }
            else
            {
                for (unsigned int j=0;j<NC_;j++)
                {
                    N[i][j] = (epsi_/tau_)*(diff[i][j]*omega[i][j] - diff[i-1][j]*omega[i-1][j])/dz_;
                }
            }
        }

        return N;
    }

    std::vector<std::vector<double> > catalyticPelletEquations::dusty_gas_model(const std::vector<std::vector<std::vector<double> > > diff,
                                                                                const std::vector<std::vector<double> > omega,
                                                                                const std::vector<std::vector<double> > MW)
    {
        std::vector<std::vector<double> > x = omega;
        std::vector<std::vector<double> > N = omega;

        Eigen::MatrixXd B(NC_,NC_);
        Eigen::MatrixXd db(NC_,NC_);
        Eigen::MatrixXd sum(NC_,NC_);
        Eigen::VectorXd gradx(NC_);
        Eigen::VectorXd dk(NC_);
        Eigen::VectorXd Nv(NC_);

        for (unsigned int i=0;i<NP_;i++)
        {
            for (unsigned int j=0;j<NC_;j++)
            {
                dk(j) = (dp_/3.)*(epsi_/tau_)*std::sqrt(8.*8.314*T_/(3.14*MW[i][j]*1e-03));
                for (unsigned int k=0;k<NC_;k++)
                {
                    db(j,k) = (epsi_/tau_)*diff[i][j][k];
                }
            }

            x[i] = this->moleFraction(omega[i],MW[i],this->meanMolecularWeight(omega[i],MW[i]));

            if ( i == 0 )
            {
                x[i+1] = this->moleFraction(omega[i+1],MW[i+1],this->meanMolecularWeight(omega[i+1],MW[i+1]));

                for (unsigned int j=0;j<NC_;j++)
                {
                    gradx(j)  = (x[i+1][j] - x[i][j])/dz_;
                }
            }
            else
            {
                for (unsigned int j=0;j<NC_;j++)
                {
                    gradx(j)  = (x[i][j] - x[i-1][j])/dz_;
                }
            }
            
            sum.setZero();
            for (unsigned int j=0;j<NC_;j++)
            {
                for (unsigned int k=0;k<NC_;k++)
                {
                    if ( j != k )
                    {
                        B(j,k) = -x[i][j]/db(j,k);
                        sum(j) = sum(j) + x[i][k]/db(j,k);
                    }
                    else
                    {
                        B(j,k) = 1./dk(j);
                    }
                }
            }

            for (unsigned int j=0;j<NC_;j++)
            {
                B(j,j) = B(j,j) + sum(j);
            }

            Nv = B.colPivHouseholderQr().solve(gradx);

            for (unsigned int j=0;j<NC_;j++)
            {
                N[i][j] = Nv(j);
            } 
        }

        return N;
    }

    int catalyticPelletEquations::Equations(double& t, std::vector<double>& y, std::vector<double>& dy)
    {
        this->properties(y);
        if ( resolution_ == "initial" )
        {
            if ( pelletType_ == "slab" )
            {
                this->slabOde(dy);
            }
            else if ( pelletType_ == "sphere" )
            {
                this->sphereOde(dy);
            }
            else if ( pelletType_ == "cylinder" )
            {
                this->cylinderOde(dy);
            }
        }
        else if ( resolution_ == "model" )
        {
            if ( pelletType_ == "slab" )
            {
                this->slab(dy);
            }
            else if ( pelletType_ == "sphere" )
            {
                this->sphere(dy);
            }
            else if ( pelletType_ == "cylinder" )
            {
                this->cylinder(dy);
            }
        }
        return 0;
    }

    void catalyticPelletEquations::properties(std::vector<double>& y)
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
            }
        }

        for (unsigned int i=0;i<NP_;i++)
        {
            omega_ = omegaMatrix_[i];
            
            if ( SURF_NC_ != 0 )
            {
                Z_ = Zmatrix_[i];
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

                transport_->getMixDiffCoeffs(canteraArray);

                for (unsigned int j=0;j<NC_;j++)
                {
                    diff_[j] = canteraArray[canteraIndex_[j]];
                }
                
                if ( modelType_ == "Dusty Gas Model" )
                {
                    double canteraMatrix[gas_->nSpecies()*gas_->nSpecies()];
                    transport_->getBinaryDiffCoeffs(gas_->nSpecies(),canteraMatrix);

                    std::vector<std::vector<double> > diffM(gas_->nSpecies());

                    unsigned int counter = 0;
                    for (unsigned int j=0;j<gas_->nSpecies();j++)
                    {
                        diffM[j].resize(gas_->nSpecies());
                        for (unsigned int k=0;k<gas_->nSpecies();k++)
                        {
                            diffM[j][k] = canteraMatrix[counter++];
                        }
                    }

                    for (unsigned int j=0;j<NC_;j++)
                    {
                        for (unsigned int k=0;k<NC_;k++)
                        {
                            diffBinaryMatrix_[i][j][k] = diffM[canteraIndex_[j]][canteraIndex_[k]];
                        }
                    }
                }
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
            RfromGasMatrix_[i]     = RfromGas_;
            RfromSurfaceMatrix_[i] = RfromSurface_;
            diffMatrix_[i]         = diff_;
            MwMatrix_[i]           = MW_;

            if ( SURF_NC_ != 0 )
            {
                RsurfaceMatrix_[i] = Rsurface_;
            }
        }

        if ( modelType_ == "\u03B5-\u03C4 model" )
        {
            fluxMatrix_ = epsi_tau_model(diffMatrix_,omegaMatrix_);
        }
        else if ( modelType_ =="Dusty Gas Model" )
        {
            fluxMatrix_ = dusty_gas_model(diffBinaryMatrix_,omegaMatrix_,MwMatrix_);
        }
    }

    void catalyticPelletEquations::slabOde(std::vector<double>& dy)
    {
        unsigned int counter = 0;
        for (unsigned int i=0;i<NP_;i++)
        {
            if ( i == 0 )
            {
                for (unsigned int j=0;j<NC_;j++)
                {
                    if ( j != inertIndex_ )
                    {
                        dy[counter++] = 1e03*(omega0_[j] - omegaMatrix_[i][j]);
                    }
                    else
                    {
                        dy[counter++] = 1e03*(1. - SumElements(omegaMatrix_[i]));
                    }
                }

                for (unsigned int j=0;j<SURF_NC_;j++)
                {
                    dy[counter++] = 0.;
                }
            }
            else if ( i == (NP_ - 1) )
            {
                for (unsigned int j=0;j<NC_;j++)
                {
                    if ( j != inertIndex_ )
                    {
                        dy[counter++] = 1e03*(omega0_[j] - omegaMatrix_[i][j]);
                    }
                    else
                    {
                        dy[counter++] = 1e03*(1. - SumElements(omegaMatrix_[i]));
                    }
                }

                for (unsigned int j=0;j<SURF_NC_;j++)
                {
                    dy[counter++] = 0.;
                }
            }
            else
            {
                for (unsigned int j=0;j<NC_;j++)
                {
                    if ( j != inertIndex_ )
                    {
                        dy[counter++] = 0.;
                    }
                    else
                    {
                        dy[counter++] = 1e03*(1. - SumElements(omegaMatrix_[i]));
                    }
                }

                for (unsigned int j=0;j<SURF_NC_;j++)
                {
                    dy[counter++] = 0.;
                }
            }
        }
    }

    void catalyticPelletEquations::sphereOde(std::vector<double>& dy)
    {
        unsigned int counter = 0;
        for (unsigned int i=0;i<NP_;i++)
        {
            if ( i == 0 )
            {
                for (unsigned int j=0;j<NC_;j++)
                {
                    if ( j != inertIndex_ )
                    {
                        dy[counter++] = 1e03*(omegaMatrix_[i+1][j] - omegaMatrix_[i][j]);
                    }
                    else
                    {
                        dy[counter++] = 1e03*(1. - SumElements(omegaMatrix_[i]));
                    }
                }

                for (unsigned int j=0;j<SURF_NC_;j++)
                {
                    dy[counter++] = 0.;
                }

            }
            else if ( i == (NP_ - 1) )
            {
                for (unsigned int j=0;j<NC_;j++)
                {
                    if ( j != inertIndex_ )
                    {
                        dy[counter++] = 1e03*(omega0_[j] - omegaMatrix_[i][j]);
                    }
                    else
                    {
                        dy[counter++] = 1e03*(1. - SumElements(omegaMatrix_[i]));
                    }
                }

                for (unsigned int j=0;j<SURF_NC_;j++)
                {
                    dy[counter++] = 0.;
                }
            }
            else
            {
                for (unsigned int j=0;j<NC_;j++)
                {
                    if ( j != inertIndex_ )
                    {
                        dy[counter++] = 0.;
                    }
                    else
                    {
                        dy[counter++] = 1e03*(1. - SumElements(omegaMatrix_[i]));
                    }
                }

                for (unsigned int j=0;j<SURF_NC_;j++)
                {
                    dy[counter++] = 0.;
                }
            }
        }
    }

    void catalyticPelletEquations::cylinderOde(std::vector<double>& dy)
    {
        this->sphereOde(dy);
    }

    void catalyticPelletEquations::slab(std::vector<double>& dy)
    {
        unsigned int counter = 0;
        for (unsigned int i=0;i<NP_;i++)
        {
            if ( i == 0 )
            {
                for (unsigned int j=0;j<NC_;j++)
                {
                    if ( j != inertIndex_ )
                    {
                        dy[counter]    = omega0_[j] - omegaMatrix_[i][j];
                        algb_[counter] = true;
                        counter++;
                    }
                    else
                    {
                        dy[counter]    = (1. - SumElements(omegaMatrix_[i]));
                        algb_[counter] = true;
                        counter++;
                    }
                }

                for (unsigned int j=0;j<SURF_NC_;j++)
                {
                    dy[counter]    = RsurfaceMatrix_[i][j]/SD_;
                    algb_[counter] = false;
                    counter++;
                }
            }
            else if ( i == (NP_ - 1) )
            {
                for (unsigned int j=0;j<NC_;j++)
                {
                    if ( j != inertIndex_ )
                    {
                        dy[counter]    = omega0_[j] - omegaMatrix_[i][j];
                        algb_[counter] = true;
                        counter++;
                    }
                    else
                    {
                        dy[counter]    = (1. - SumElements(omegaMatrix_[i]));
                        algb_[counter] = true;
                        counter++;
                    }
                }

                for (unsigned int j=0;j<SURF_NC_;j++)
                {
                    dy[counter]    = RsurfaceMatrix_[i][j]/SD_;
                    algb_[counter] = false;
                    counter++;
                }
            }
            else
            {
                for (unsigned int j=0;j<NC_;j++)
                {
                    if ( j != inertIndex_ )
                    {
                        dy[counter]    = (fluxMatrix_[i+1][j] - fluxMatrix_[i][j])/dz_
                                       +  alfa_*RfromSurfaceMatrix_[i][j]*MW_[j]/rhoVector_[i]
                                       +  epsi_*RfromGasMatrix_[i][j]*MW_[j]/rhoVector_[i];
                        algb_[counter] = false;
                        counter++;
                    }
                    else
                    {
                        dy[counter]    = (1. - SumElements(omegaMatrix_[i]));
                        algb_[counter] = true;
                        counter++;
                    }
                }

                for (unsigned int j=0;j<SURF_NC_;j++)
                {
                    dy[counter]    = RsurfaceMatrix_[i][j]/SD_;
                    algb_[counter] = false;
                    counter++;
                }
            }
        }
    }

    void catalyticPelletEquations::sphere(std::vector<double>& dy)
    {
        unsigned int counter = 0;
        for (unsigned int i=0;i<NP_;i++)
        {
            if ( i == 0 )
            {
                for (unsigned int j=0;j<NC_;j++)
                {
                    if ( j != inertIndex_ )
                    {
                        dy[counter]    = omegaMatrix_[i+1][j] - omegaMatrix_[i][j];
                        algb_[counter] = true;
                        counter++;
                    }
                    else
                    {
                        dy[counter]    = (1. - SumElements(omegaMatrix_[i]));
                        algb_[counter] = true;
                        counter++;
                    }
                }

                for (unsigned int j=0;j<SURF_NC_;j++)
                {
                    dy[counter]    = RsurfaceMatrix_[i][j]/SD_;
                    algb_[counter] = false;
                    counter++;
                }
            }
            else if ( i == (NP_ - 1) )
            {
                for (unsigned int j=0;j<NC_;j++)
                {
                    if ( j != inertIndex_ )
                    {
                        dy[counter]    = omega0_[j] - omegaMatrix_[i][j];
                        algb_[counter] = true;
                        counter++;
                    }
                    else
                    {
                        dy[counter]    = (1. - SumElements(omegaMatrix_[i]));
                        algb_[counter] = true;
                        counter++;
                    }
                }

                for (unsigned int j=0;j<SURF_NC_;j++)
                {
                    dy[counter]    = RsurfaceMatrix_[i][j]/SD_;
                    algb_[counter] = false;
                    counter++;
                }
            }
            else
            {
                for (unsigned int j=0;j<NC_;j++)
                {
                    if ( j != inertIndex_ )
                    {
                        dy[counter]    = (1./std::pow(Length_[i],2.))*(std::pow((Length_[i+1]+Length_[i])*0.5,2.)*fluxMatrix_[i+1][j] - std::pow((Length_[i]+Length_[i-1])*0.5,2.)*fluxMatrix_[i][j])/dz_
                                       +  alfa_*RfromSurfaceMatrix_[i][j]*MW_[j]/rhoVector_[i]
                                       +  epsi_*RfromGasMatrix_[i][j]*MW_[j]/rhoVector_[i];
                        algb_[counter] = false;
                        counter++;
                    }
                    else
                    {
                        dy[counter]    = (1. - SumElements(omegaMatrix_[i]));
                        algb_[counter] = true;
                        counter++;
                    }
                }

                for (unsigned int j=0;j<SURF_NC_;j++)
                {
                    dy[counter]    = RsurfaceMatrix_[i][j]/SD_;
                    algb_[counter] = false;
                    counter++;
                }
            }
        }
    }

    void catalyticPelletEquations::cylinder(std::vector<double>& dy)
    {
        unsigned int counter = 0;
        for (unsigned int i=0;i<NP_;i++)
        {
            if ( i == 0 )
            {
                for (unsigned int j=0;j<NC_;j++)
                {
                    if ( j != inertIndex_ )
                    {
                        dy[counter]    = omegaMatrix_[i+1][j] - omegaMatrix_[i][j];
                        algb_[counter] = true;
                        counter++;
                    }
                    else
                    {
                        dy[counter]    = (1. - SumElements(omegaMatrix_[i]));
                        algb_[counter] = true;
                        counter++;
                    }
                }

                for (unsigned int j=0;j<SURF_NC_;j++)
                {
                    dy[counter]    = RsurfaceMatrix_[i][j]/SD_;
                    algb_[counter] = false;
                    counter++;
                }
            }
            else if ( i == (NP_ - 1) )
            {
                for (unsigned int j=0;j<NC_;j++)
                {
                    if ( j != inertIndex_ )
                    {
                        dy[counter]    = omega0_[j] - omegaMatrix_[i][j];
                        algb_[counter] = true;
                        counter++;
                    }
                    else
                    {
                        dy[counter]    = (1. - SumElements(omegaMatrix_[i]));
                        algb_[counter] = true;
                        counter++;
                    }
                }

                for (unsigned int j=0;j<SURF_NC_;j++)
                {
                    dy[counter]    = RsurfaceMatrix_[i][j]/SD_;
                    algb_[counter] = false;
                    counter++;
                }
            }
            else
            {
                for (unsigned int j=0;j<NC_;j++)
                {
                    if ( j != inertIndex_ )
                    {
                        dy[counter]    = (1./Length_[i])*((Length_[i+1]+Length_[i])*0.5*fluxMatrix_[i+1][j] - (Length_[i]+Length_[i-1])*0.5*fluxMatrix_[i][j])/dz_
                                       +  alfa_*RfromSurfaceMatrix_[i][j]*MW_[j]/rhoVector_[i]
                                       +  epsi_*RfromGasMatrix_[i][j]*MW_[j]/rhoVector_[i];
                        algb_[counter] = false;
                        counter++;
                    }
                    else
                    {
                        dy[counter]    = (1. - SumElements(omegaMatrix_[i]));
                        algb_[counter] = true;
                        counter++;
                    }
                }

                for (unsigned int j=0;j<SURF_NC_;j++)
                {
                    dy[counter]    = RsurfaceMatrix_[i][j]/SD_;
                    algb_[counter] = false;
                    counter++;
                }
            }
        }
    }

    void catalyticPelletEquations::store(const double tf,const std::vector<double> xf)
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
            }
        }

        Time_.push_back(tf);
        Specie_.push_back(omegaMatrix_);
        Site_.push_back(Zmatrix_);
    }
    
    double catalyticPelletEquations::getLength()
    {
        return MaxElement(Length_);
    }
    
}
