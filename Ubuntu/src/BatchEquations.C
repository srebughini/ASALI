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

#include "BatchEquations.h"

namespace ASALI
{
    BatchEquations::BatchEquations()
    {}

    void BatchEquations::setCanteraThermo(Cantera::ThermoPhase* gas)
    {
        gas_ = gas;
    }
    
    void BatchEquations::setCanteraInterface(Cantera::Interface* surface)
    {
        surface_ = surface;
    }

    void BatchEquations::setCanteraKinetics(Cantera::Kinetics* kinetic)
    {
        kinetic_ = kinetic;
    }

    void BatchEquations::setCanteraTransport(Cantera::Transport* transport)
    {
        transport_ = transport;
    }

    void BatchEquations::setKineticType(const std::string type)
    {
        type_ = type;
    }

    void BatchEquations::resize()
    {
        if ( type_ == "CANTERA" )
        {
            NC_      = gas_->nSpecies();
            SURF_NC_ = surface_->nSpecies();
            NE_      = NC_ + SURF_NC_ + 1 + 1;

            x_.resize(NC_);
            omega_.resize(NC_);
            MW_.resize(NC_);
            RfromGas_.resize(NC_);
            RfromSurface_.resize(NC_);
            
            Z_.resize(NC_);
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
            NE_      = NC_ + SURF_NC_ + 1 + 1;

            x_.resize(NC_);
            omega_.resize(NC_);
            MW_.resize(NC_);
            RfromGas_.resize(NC_);
            RfromSurface_.resize(NC_);
            h_.resize(NC_);

            SD_   = 1.;
            alfa_ = 1.;
        }

        {
            Time_.clear();
            Specie_.clear();
            Site_.clear();
            Temperature_.clear();
            Pressure_.clear();
            Volume_.clear();
            Mass_.clear();
        }
    }

    void BatchEquations::setPressure(const double P)
    {
        P_ = P;
    }

    void BatchEquations::setTemperature (const double T)
    {
        T_ = T;
    }

    void BatchEquations::setVolume (const double V)
    {
        V_ = V;
    }

    void BatchEquations::setIntegrationTime(const double tF)
    {
        tF_ = tF;
    }

    void BatchEquations::setCatalystLoad(const double alfa)
    {
        alfa_ = alfa;
    }

    void BatchEquations::setResolutionType(const std::string resolution)
    {
        resolution_ = resolution;
    }

    void BatchEquations::setAsaliKinetic(const unsigned int                           NR,
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
    
    
    void BatchEquations::turnOnUserDefined(const bool check)
    {
        userCheck_ = check;
    }
    
    void BatchEquations::set_MW(const std::vector<double> MW)
    {
        MW_ = MW;
    }
    
    void BatchEquations::set_QfromSurface(const std::vector<double> Q)
    {
        Quser_ = Q;
    }

    void BatchEquations::set_cp(const double cp)
    {
        cp_ = cp;
    }

    std::vector<double> BatchEquations::reactionRate(const std::vector<double> omega,const double rho)
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

    double BatchEquations::heatOfReaction(const std::vector<double> omega,const double rho, const std::vector<double> h)
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
            double Q = 0.;
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
        return Q;
    }

    int BatchEquations::Equations(double& t, std::vector<double>& y, std::vector<double>& dy)
    {
        // Recover unknowns
        {
            unsigned int counter=0;

            for(unsigned int i=0;i<NC_;i++)
                omega_[i] = y[counter++];

            mass_ = y[counter++];

            for(unsigned int i=0;i<SURF_NC_;i++)
                Z_[i] = y[counter++];

            T_ = y[counter++];
        }
        
        if ( resolution_ == "volume" )
        {
            // Calculates the pressure and the concentrations of species
            if ( userCheck_ == false )
            {
                double canteraArray[gas_->nSpecies()];
                memset(canteraArray,0.,sizeof(canteraArray));
                for (unsigned int i=0;i<NC_;i++)
                {
                    canteraArray[canteraIndex_[i]] = omega_[i];
                }

                MWmix_ = gas_->meanMolecularWeight();
                rho_   = mass_/V_;
                cTot_  = rho_/MWmix_;
                P_     = cTot_*8314.*T_;

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
                rho_   = mass_/V_;
                cTot_  = rho_/MWmix_;
                P_     = cTot_*8314.*T_;
            }

            // Calculates homogeneous kinetics
            {
                //TO BE IMPLEMENTED
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
                            double reactionArray[NC_+SURF_NC_];

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
                                QfromSurface_ = QfromSurface_ + reactionArray[j]*enthalpyArray[j];  //J/kmol/s
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

            // Variation of gas mass in the reactor
            const double dm_over_dt = V_*alfa_*DotProduct(RfromSurface_, MW_);

            // Number of moles
            const double moles = cTot_*V_;
            const double sumMoleFormationRates = V_*SumElements(RfromGas_) + V_*alfa_*SumElements(RfromSurface_);
            
            // Recovering residuals
            {
                unsigned int counter=0;
            
                // Gas phase species
                for (unsigned int i=0;i<NC_;i++)
                {
                    dy[counter++] = MW_[i]*RfromGas_[i]/rho_ + (-omega_[i]*dm_over_dt + V_*alfa_*RfromSurface_[i]*MW_[i])/mass_;
                }
                
                // Total mass
                dy[counter++] = dm_over_dt;

                // Surface site species
                for (unsigned int i=0;i<SURF_NC_;i++)    
                {
                    dy[counter++] = Rsurface_[i]/SD_;
                }

                // Energy equation
                if (energyEquation_ == true)
                {
                    dy[counter++] = (V_*QfromGas_+ V_*alfa_*QfromSurface_ + 8314.*T_*sumMoleFormationRates)/(mass_*cp_ - 8314.*moles);
                }
                else
                {
                    dy[counter++] = 0.;
                }
            }
        }
        else if ( resolution_ == "pressure" )
        {
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
                V_     = mass_/rho_;

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
                V_     = mass_/rho_;
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
                                QfromSurface_ = QfromSurface_ + reactionArray[j]*enthalpyArray[j];  //J/kmol/s
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

            // Variation of gas mass in the reactor
            const double dm_over_dt = V_*alfa_*DotProduct(RfromSurface_, MW_);

            // Recovering residuals
            {

                unsigned int counter=0;
            
                // Gas phase species
                for (unsigned int i=0;i<NC_;i++)
                {
                    dy[counter++] = MW_[i]*RfromGas_[i]/rho_ + (-omega_[i]*dm_over_dt + V_*alfa_*RfromSurface_[i]*MW_[i])/mass_;
                }

                // Total mass
                dy[counter++] = dm_over_dt;

                // Surface site species
                for (unsigned int i=0;i<SURF_NC_;i++)    
                {
                    dy[counter++] = Rsurface_[i]/SD_;
                }

                // Energy equation
                if (energyEquation_ == true)
                {
                    dy[counter++] = (V_*QfromGas_+ V_*alfa_*QfromSurface_)/(mass_*cp_);
                }
                else
                {
                    dy[counter++] = 0.;
                }
            }
        }

        if ( t >= tF_ )
        {
            Time_.push_back(t);
            Specie_.push_back(omega_);
            Site_.push_back(Z_);
            Temperature_.push_back(T_);
            Pressure_.push_back(P_);
            Volume_.push_back(V_);
            Mass_.push_back(mass_);
            timeCounter_++;
        }

        return 0;
    }
    
    
    double BatchEquations::meanMolecularWeight(const std::vector<double> omega,const std::vector<double> MW)
    {
        double MWmix = 0.;
        for (unsigned int i=0;i<NC_;i++)
        {
            MWmix = MWmix + omega[i]/MW[i];
        }
        return 1./MWmix;
    }
}
