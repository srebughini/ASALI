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

#include "Ph1DEquations.h"

namespace ASALI
{
    Ph1DEquations::Ph1DEquations()
    {}

    void Ph1DEquations::setCanteraThermo(Cantera::ThermoPhase* gas)
    {
        gas_ = gas;
    }
    
    void Ph1DEquations::setCanteraInterface(Cantera::Interface* surface)
    {
        surface_ = surface;
    }

    void Ph1DEquations::setCanteraKinetics(Cantera::Kinetics* kinetic)
    {
        kinetic_ = kinetic;
    }

    void Ph1DEquations::setCanteraTransport(Cantera::Transport* transport)
    {
        transport_ = transport;
    }

    void Ph1DEquations::setKineticType(const std::string type)
    {
        type_ = type;
    }

    void Ph1DEquations::resize()
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

    void Ph1DEquations::setPressure(const double P)
    {
        P_ = P;
    }

    void Ph1DEquations::setTemperature (const double T)
    {
        T_ = T;
    }

    void Ph1DEquations::setLength(const double L)
    {
        L_  = L;
        dz_ = L_/double(NP_-1);
    }

    void Ph1DEquations::setSpecificMassFlowRate(const double G)
    {
        G_ = G;
    }

    void Ph1DEquations::setNumberOfPoints(const double NP)
    {
        NP_ = int(NP);
    }

    void Ph1DEquations::setCatalystLoad(const double alfa)
    {
        alfa_ = alfa;
    }

    void Ph1DEquations::setResolutionType(const std::string resolution)
    {
        resolution_ = resolution;
    }

    void Ph1DEquations::setAsaliKinetic(const unsigned int                           NR,
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
    
    
    void Ph1DEquations::turnOnUserDefined(const bool check)
    {
        userCheck_ = check;
    }
    
    void Ph1DEquations::set_MW(const std::vector<double> MW)
    {
        MW_ = MW;
    }

    void Ph1DEquations::set_diff(const std::vector<double> diff)
    {
        diff_ = diff;
    }

    void Ph1DEquations::set_QfromSurface(const std::vector<double> Q)
    {
        Quser_ = Q;
    }

    void Ph1DEquations::set_cp(const double cp)
    {
        cp_ = cp;
    }

    void Ph1DEquations::set_cond(const double cond)
    {
        cond_ = cond;
    }

    void Ph1DEquations::setInletConditions(const std::vector<double> omega0, const double T0)
    {
        omega0_ = omega0;
        T0_     = T0;
    }

    std::vector<double> Ph1DEquations::reactionRate(const std::vector<double> omega,const double rho)
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
                    R[i] = R[i] + stoich_[j][i]*k_[j]*std::pow(T_,n_[j])*std::exp(-Eatt_[j]/(8314*T_))*std::pow(rho*omega[index1_[j]]*converter_/MW_[index1_[j]],a_[j]);
                }
                else if ( name_[j][0] == "none" &&
                          name_[j][1] != "none")
                {
                    R[i] = R[i] + stoich_[j][i]*k_[j]*std::pow(T_,n_[j])*std::exp(-Eatt_[j]/(8314*T_))*std::pow(rho*omega[index2_[j]]*converter_/MW_[index2_[j]],b_[j]);
                
                }
                else if ( name_[j][0] != "none" &&
                          name_[j][1] != "none")
                {
                    R[i] = R[i] + stoich_[j][i]*k_[j]*std::pow(T_,n_[j])*std::exp(-Eatt_[j]/(8314*T_))*std::pow(rho*omega[index1_[j]]*converter_/MW_[index1_[j]],a_[j])*std::pow(rho*omega[index2_[j]]*converter_/MW_[index2_[j]],b_[j]);
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

    double Ph1DEquations::heatOfReaction(const std::vector<double> omega,const double rho, const std::vector<double> h)
    {
        double Q = 0.;
        if ( userCheck_ == false )
        {
            for (unsigned int i=0;i<NC_;i++)
            {
                double R = 0.;
                for (unsigned int j=0;j<NR_;j++)
                {
                    if ( name_[j][0] != "none" &&
                         name_[j][1] == "none")
                    {
                        R = R + stoich_[j][i]*k_[j]*std::pow(T_,n_[j])*std::exp(-Eatt_[j]/(8314*T_))*std::pow(rho*omega[index1_[j]]*converter_/MW_[index1_[j]],a_[j]);
                    }
                    else if ( name_[j][0] == "none" &&
                              name_[j][1] != "none")
                    {
                        R = R + stoich_[j][i]*k_[j]*std::pow(T_,n_[j])*std::exp(-Eatt_[j]/(8314*T_))*std::pow(rho*omega[index2_[j]]*converter_/MW_[index2_[j]],b_[j]);
                    
                    }
                    else if ( name_[j][0] != "none" &&
                              name_[j][1] != "none")
                    {
                        R = R + stoich_[j][i]*k_[j]*std::pow(T_,n_[j])*std::exp(-Eatt_[j]/(8314*T_))*std::pow(rho*omega[index1_[j]]*converter_/MW_[index1_[j]],a_[j])*std::pow(rho*omega[index2_[j]]*converter_/MW_[index2_[j]],b_[j]);
                    }
                    else
                    {
                        R = R + 0.;
                    }
                }
                Q = Q + R*h[i]/converter_;
            }
        }
        else
        {
            for (unsigned int j=0;j<NR_;j++)
            {
                double R = 0.;
                if ( name_[j][0] != "none" &&
                     name_[j][1] == "none")
                {
                    R = k_[j]*std::pow(T_,n_[j])*std::exp(-Eatt_[j]/(8314*T_))*std::pow(rho*omega[index1_[j]]*converter_/MW_[index1_[j]],a_[j]);
                }
                else if ( name_[j][0] == "none" &&
                          name_[j][1] != "none")
                {
                    R = k_[j]*std::pow(T_,n_[j])*std::exp(-Eatt_[j]/(8314*T_))*std::pow(rho*omega[index2_[j]]*converter_/MW_[index2_[j]],b_[j]);
                
                }
                else if ( name_[j][0] != "none" &&
                          name_[j][1] != "none")
                {
                    R = k_[j]*std::pow(T_,n_[j])*std::exp(-Eatt_[j]/(8314*T_))*std::pow(rho*omega[index1_[j]]*converter_/MW_[index1_[j]],a_[j])*std::pow(rho*omega[index2_[j]]*converter_/MW_[index2_[j]],b_[j]);
                }
                else
                {
                    R = 0.;
                }
                Q = Q + R*Quser_[j]/converter_;
            }
        }
        return -Q;
    }

    int Ph1DEquations::Equations(double& t, std::vector<double>& y, std::vector<double>& dy)
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

                for (unsigned int i=0;i<NC_;i++)
                {
                    MW_[i] = gas_->molecularWeight(canteraIndex_[i]);
                }

                cp_ = gas_->cp_mass();
            }
            else
            {
                MWmix_ = this->meanMolecularWeight(omega_,MW_);
                cTot_  = P_/(8314.*T_);
                rho_   = cTot_*MWmix_;
            }

            // Calculates homogeneous kinetics
            {
                //To be done
                /*
                if ( homogeneusReactions_ == true )
                {
                    double* canteraArray = omega_.data();
                    gas_->setState_TPY(T_,P_,canteraArray);
                    kinetic_.getNetProductionRates(canteraArray);
                    for (unsigned int j=0;j<NC_;j++)
                    {
                        RfromGas_[j] = canteraArray[j]; //kmol/m3/s
                    }

                    double reactionArray[kinetic_.nReactions()];
                    double enthalpyArray[kinetic_.nReactions()];
                    kinetic_.getNetRatesOfProgress(reactionArray);
                    kinetic_.getDeltaEnthalpy(enthalpyArray);
                    QfromGas_ = 0.;
                    for (unsigned int j=0;j<kinetic_.nReactions();j++)
                    {   
                        QfromGas_ = QfromGas_ + reactionArray[j]*enthalpyArray[j];  //J/kmol/k
                    }
                    QfromGas_ = -QfromGas_;
                }
                else
                {
                    for (unsigned int j=0;j<NC_;j++)
                    {
                        RfromGas_[j] = 0.;
                    }
                    QfromGas_ = 0.;
                }*/

                for (unsigned int j=0;j<NC_;j++)
                {
                    RfromGas_[j] = 0.;
                }
                QfromGas_ = 0.;

            }

            // Calculates heterogeneous kinetics
            {
                if ( heterogeneusReactions_ == true )
                {
                    if ( type_ == "CANTERA" )
                    {
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
                        }
                        
                        if ( energyEquation_ == true )
                        {
                            double reactionArray[surface_->nReactions()];
                            double enthalpyArray[surface_->nReactions()];
                            surface_->getNetRatesOfProgress(reactionArray);
                            surface_->getDeltaEnthalpy(enthalpyArray);
                            QfromSurface_ = 0.;
                            for (unsigned int j=0;j<surface_->nReactions();j++)
                            {
                                QfromSurface_ = QfromSurface_ + reactionArray[j]*enthalpyArray[j]; //W/m3
                            }

                            QfromSurface_ = -QfromSurface_;

                            SD_ = surface_->siteDensity();
                        }
                        else
                        {
                            QfromSurface_ = 0.;

                            SD_ = surface_->siteDensity();
                        }
                    }
                    else if ( type_ == "ASALI" )
                    {
                        RfromSurface_ = this->reactionRate(omega_,rho_); //kmol/m3/s

                        if ( energyEquation_ == true )
                        {
                            if ( userCheck_ == false )
                            {
                                double hArray[gas_->nSpecies()];
                                gas_->getPartialMolarEnthalpies(hArray);
                                
                                for (unsigned int i=0;i<NC_;i++)
                                {
                                    h_[i] = hArray[canteraIndex_[i]];
                                }

                                QfromSurface_ = this->heatOfReaction(omega_,rho_,h_); //W/m3
                            }
                            else
                            {

                                for (unsigned int i=0;i<NC_;i++)
                                {
                                    h_[i] = 0.;
                                }
                                QfromSurface_ = this->heatOfReaction(omega_,rho_,h_); //W/m3
                            }
                        }
                        else
                        {
                            QfromSurface_ = 0.;
                        }
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
                    
                    QfromSurface_ = 0.;
                }
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
                    cTot_  = P_/(8314.*T_);
                    rho_   = cTot_*MWmix_;
                }

                // Calculates homogeneous kinetics
                {
                    //To be done
                    /*
                    if ( homogeneusReactions_ == true )
                    {
                        double* canteraArray = omega_.data();
                        gas_->setState_TPY(T_,P_,canteraArray);
                        kinetic_.getNetProductionRates(canteraArray);
                        for (unsigned int j=0;j<NC_;j++)
                        {
                            RfromGas_[j] = canteraArray[j]; //kmol/m3/s
                        }

                        double reactionArray[kinetic_.nReactions()];
                        double enthalpyArray[kinetic_.nReactions()];
                        kinetic_.getNetRatesOfProgress(reactionArray);
                        kinetic_.getDeltaEnthalpy(enthalpyArray);
                        QfromGas_ = 0.;
                        for (unsigned int j=0;j<kinetic_.nReactions();j++)
                        {   
                            QfromGas_ = QfromGas_ + reactionArray[j]*enthalpyArray[j];  //J/kmol/k
                        }
                        QfromGas_ = -QfromGas_;
                    }
                    else
                    {
                        for (unsigned int j=0;j<NC_;j++)
                        {
                            RfromGas_[j] = 0.;
                        }
                        QfromGas_ = 0.;
                    }*/

                    for (unsigned int j=0;j<NC_;j++)
                    {
                        RfromGas_[j] = 0.;
                    }
                    QfromGas_ = 0.;
                }

                // Calculates heterogeneous kinetics
                {
                    if ( heterogeneusReactions_ == true )
                    {
                        if ( type_ == "CANTERA" )
                        {
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
                                    RfromSurface_[j] = reactionArray[rcounter++]*MW_[j]; //kg/m2/s
                                }

                                for (unsigned int j=0;j<SURF_NC_;j++)
                                {
                                    Rsurface_[j] = reactionArray[rcounter++];
                                }
                            }
                            
                            if ( energyEquation_ == true )
                            {
                                double reactionArray[surface_->nReactions()];
                                double enthalpyArray[surface_->nReactions()];
                                surface_->getNetRatesOfProgress(reactionArray);
                                surface_->getDeltaEnthalpy(enthalpyArray);
                                QfromSurface_ = 0.;
                                for (unsigned int j=0;j<surface_->nReactions();j++)
                                {
                                    QfromSurface_ = QfromSurface_ + reactionArray[j]*enthalpyArray[j];  //W/m3
                                }

                                QfromSurface_ = -QfromSurface_;

                                SD_ = surface_->siteDensity();
                            }
                            else
                            {
                                QfromSurface_ = 0.;

                                SD_ = surface_->siteDensity();
                            }
                        }
                        else if ( type_ == "ASALI" )
                        {
                            RfromSurface_ = this->reactionRate(omega_,rho_); //kmol/m3/s

                            if ( energyEquation_ == true )
                            {
                                if ( userCheck_ == false )
                                {
                                    double hArray[gas_->nSpecies()];
                                    gas_->getPartialMolarEnthalpies(hArray);
                                    
                                    for (unsigned int i=0;i<NC_;i++)
                                    {
                                        h_[i] = hArray[canteraIndex_[i]];
                                    }

                                    QfromSurface_ = this->heatOfReaction(omega_,rho_,h_); //W/m3
                                }
                                else
                                {

                                    for (unsigned int i=0;i<NC_;i++)
                                    {
                                        h_[i] = 0.;
                                    }
                                    QfromSurface_ = this->heatOfReaction(omega_,rho_,h_); //W/m3
                                }
                            }
                            else
                            {
                                QfromSurface_ = 0.;
                            }
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
                        
                        QfromSurface_ = 0.;
                    }
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
                                         + alfa_*RfromSurfaceMatrix_[i][j]/rhoVector_[i];
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
    
    
    double Ph1DEquations::meanMolecularWeight(const std::vector<double> omega,const std::vector<double> MW)
    {
        double MWmix = 0.;
        for (unsigned int i=0;i<NC_;i++)
        {
            MWmix = MWmix + omega[i]/MW[i];
        }
        return 1./MWmix;
    }
    
    
    void Ph1DEquations::store(const double tf,const std::vector<double> xf)
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
