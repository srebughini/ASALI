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
#   Department of Energy                                                                       #
#   Politecnico di Milano                                                                      #
#   Author: Stefano Rebughini <stefano.rebughini@polimi.it>                                    #
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

#include "catalyticPelletEquations.h"

namespace ASALI
{
    catalyticPelletEquations::catalyticPelletEquations()
    {}

    void catalyticPelletEquations::setCanteraThermo(Cantera::ThermoPhase* gas)
    {
        gas_ = gas;
    }
    
    void catalyticPelletEquations::setCanteraInterface(Cantera::Interface* surface)
    {
        surface_ = surface;
    }

    void catalyticPelletEquations::setCanteraKinetics(Cantera::Kinetics* kinetic)
    {
        kinetic_ = kinetic;
    }

    void catalyticPelletEquations::setCanteraTransport(Cantera::Transport* transport)
    {
        transport_ = transport;
    }

    void catalyticPelletEquations::setKineticType(const std::string type)
    {
        type_ = type;
    }

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

            algb_.resize(NE_);

            SD_ = 1.;
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
    
    void catalyticPelletEquations::setReductionCoefficient(const double rc)
    {
        rc_ = rc;
    }

    void catalyticPelletEquations::setAsaliKinetic(const unsigned int                           NR,
                                                   const std::vector<double>                    k,
                                                   const std::vector<double>                    Eatt,
                                                   const std::vector<double>                    n,
                                                   const std::vector<double>                    a,
                                                   const std::vector<double>                    b,
                                                   const std::vector<int>                       index1,
                                                   const std::vector<int>                       index2,
                                                   const std::vector<int>                       canteraIndex,
                                                   const std::vector<std::vector<std::string> > name,
                                                   const std::vector<std::vector<int> >         stoich,
                                                   const double converter)
    {
        NR_           = NR;
        k_            = k;
        Eatt_         = Eatt;
        n_            = n;
        a_            = a;
        b_            = b;
        index1_       = index1;
        index2_       = index2;
        canteraIndex_ = canteraIndex;
        
        stoich_.resize(NR_);
        name_.resize(NR_);
        for (unsigned int i=0;i<NR_;i++)
        {
            stoich_[i] = stoich[i];
            name_[i]   = name[i];
        }

        converter_ = converter;
    }
    
    
    void catalyticPelletEquations::turnOnUserDefined(const bool check)
    {
        userCheck_ = check;
    }
    
    void catalyticPelletEquations::setInert(const unsigned int inertIndex)
    {
        inertIndex_ = inertIndex;
    }
    
    void catalyticPelletEquations::set_MW(const std::vector<double> MW)
    {
        MW_ = MW;
    }

    void catalyticPelletEquations::set_diff(const std::vector<double> diff)
    {
        diff_ = diff;
    }

    void catalyticPelletEquations::setInletConditions(const std::vector<double> omega0)
    {
        omega0_ = omega0;
    }

    std::vector<double> catalyticPelletEquations::reactionRate(const double T, const std::vector<double> omega,const double rho)
    {
        std::vector<double> R(NC_);
        for (unsigned int i=0;i<NC_;i++)
        {
            R[i] = 0.;
            for (unsigned int j=0;j<NR_;j++)
            {
                if ( name_[j][0] != "none" &&
                     name_[j][1] == "none")
                {
                    R[i] = R[i] + stoich_[j][i]*k_[j]*std::pow(T,n_[j])*std::exp(-Eatt_[j]/(8314*T))*std::pow(rho*omega[index1_[j]]*converter_/MW_[index1_[j]],a_[j]);
                }
                else if ( name_[j][0] == "none" &&
                          name_[j][1] != "none")
                {
                    R[i] = R[i] + stoich_[j][i]*k_[j]*std::pow(T,n_[j])*std::exp(-Eatt_[j]/(8314*T))*std::pow(rho*omega[index2_[j]]*converter_/MW_[index2_[j]],b_[j]);
                
                }
                else if ( name_[j][0] != "none" &&
                          name_[j][1] != "none")
                {
                    R[i] = R[i] + stoich_[j][i]*k_[j]*std::pow(T,n_[j])*std::exp(-Eatt_[j]/(8314*T))*std::pow(rho*omega[index1_[j]]*converter_/MW_[index1_[j]],a_[j])*std::pow(rho*omega[index2_[j]]*converter_/MW_[index2_[j]],b_[j]);
                }
                else
                {
                    R[i] = R[i] + 0.;
                }
            }
            R[i] = R[i]/converter_;
        }
        return R;
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

    std::vector<std::vector<double> > catalyticPelletEquations::reduction_coefficient_model(const std::vector<std::vector<double> > diff,const std::vector<std::vector<double> > omega)
    {
        std::vector<std::vector<double> > N = diff;
        for (unsigned int i=0;i<NP_;i++)
        {
            if ( i == 0 )
            {
                for (unsigned int j=0;j<NC_;j++)
                {
                    N[i][j] = rc_*(diff[i+1][j]*omega[i+1][j] - diff[i][j]*omega[i][j])/dz_;
                }
            }
            else
            {
                for (unsigned int j=0;j<NC_;j++)
                {
                    N[i][j] = rc_*(diff[i][j]*omega[i][j] - diff[i-1][j]*omega[i-1][j])/dz_;
                }
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
    
    double catalyticPelletEquations::meanMolecularWeight(const std::vector<double> omega,const std::vector<double> MW)
    {
        double MWmix = 0.;
        for (unsigned int i=0;i<omega.size();i++)
        {
            MWmix = MWmix + omega[i]/MW[i];
        }
        return 1./MWmix;
    }
    
    std::vector<double> catalyticPelletEquations::fromMassToMoleFraction(const std::vector<double> omega,const std::vector<double> MW)
    {
        std::vector<double> x = omega;
        
        double MWmix = meanMolecularWeight(omega,MW);
        
        
        for (unsigned int i=0;i<omega.size();i++)
        {
            x[i] = omega[i]*MWmix/MW[i];
        }
        
        return x;
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

                for (unsigned int j=0;j<NC_;j++)
                {
                    MW_[j] = gas_->molecularWeight(canteraIndex_[j]);
                }

                transport_->getMixDiffCoeffs(canteraArray);

                for (unsigned int j=0;j<NC_;j++)
                {
                    diff_[j] = canteraArray[canteraIndex_[j]];
                }
            }
            else
            {
                MWmix_ = this->meanMolecularWeight(omega_,MW_);
                cTot_  = P_/(8314.*T_);
                rho_   = cTot_*MWmix_;
                
            }

            // Calculates heterogeneous kinetics
            {
                if ( heterogeneusReactions_ == true && alfa_ != 0.)
                {
                    if ( type_ == "CANTERA" )
                    {
                        double* bulkArray     = omega_.data();
                        double* coverageArray = Z_.data();
                        double  reactionArray[NC_+SURF_NC_];

                        gas_->setState_TPY(T_,P_,bulkArray);

                        surface_->setTemperature(T_);
                        surface_->setCoveragesNoNorm(coverageArray);
                        surface_->getNetProductionRates(reactionArray);

                        unsigned int rcounter = 0;
                        for (unsigned int j=0;j<NC_;j++)
                        {
                            RfromSurface_[j] = reactionArray[rcounter++]; //kmol/m2/s
                        }

                        for (unsigned int j=0;j<SURF_NC_;j++)
                        {
                            Rsurface_[j] = reactionArray[rcounter++];
                        }

                        SD_ = surface_->siteDensity();
                    }
                    else if ( type_ == "ASALI" )
                    {
                        RfromSurface_ = this->reactionRate(T_,omega_,rho_); //kmol/m3/s
                    }
                }
                else
                {
                    for (unsigned int j=0;j<NC_;j++)
                    {
                        RfromSurface_[j] = 0.;
                    }

                    for (unsigned int j=0;j<SURF_NC_;j++)
                    {
                        Rsurface_[j] = 0.;
                    }
                }
            }
            
            // Calculates homogeneous kinetics
            {
                if ( homogeneousReactions_ == true )
                {
                    double* bulkArray = omega_.data();
                    double  reactionArray[NC_];

                    gas_->setState_TPY(T_,P_,bulkArray);
                    kinetic_->getNetProductionRates(reactionArray);

                    for (unsigned int j=0;j<NC_;j++)
                    {
                        RfromGas_[j] = reactionArray[j]; //kmol/m2/s
                    }
                }
                else
                {
                    for (unsigned int j=0;j<NC_;j++)
                    {
                        RfromGas_[j] = 0.; //kmol/m2/s
                    }
                }
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
        else if ( modelType_ =="Reduction coefficient" )
        {
            fluxMatrix_ = reduction_coefficient_model(diffMatrix_,omegaMatrix_);
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
