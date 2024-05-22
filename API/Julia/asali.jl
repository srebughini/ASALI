################################################################################################
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
################################################################################################
module asali
    include("thermoDatabase.jl")
    include("transportDatabase.jl")
    include("omegaDatabase.jl")

    thermo_ = thermoDatabase.update()
    transport_ = transportDatabase.update()
    omega11_, omega22_ = omegaDatabase.update()

    T_ = 0
    p_ = 0
    NC_ = 0
    MWmix_ = 0
    rho_  = 0
    cond_mix_ = 0
    mu_mix_ = 0
    cpmole_mix_ = 0
    cpmass_mix_ = 0
    hmole_mix_ = 0
    hmass_mix_ = 0
    smole_mix_ = 0
    smass_mix_ = 0
    pi_ = 3.14159265358979323846

    mu_updated_ = false
    rho_updated_ = false
    diff_updated_ = false
    cp_updated_ = false
    h_updated_ = false
    s_updated_ = false
    cond_updated_ = false
    cond_mix_updated_ = false
    mu_mix_updated_ = false
    v_updated_ = false
    l_updated_ = false
    cpmole_mix_updated_ = false
    cpmass_mix_updated_ = false
    hmole_mix_updated_ = false
    hmass_mix_updated_ = false
    smole_mix_updated_ = false
    smass_mix_updated_ = false
    diff_mix_updated_ = false

    index_ = Int64[]
    MW_ = Float64[]
    names_ = String[]
    y_ = Float64[]
    x_ = Float64[]
    mu_ = Float64[]
    diff_ = Float64[]
    cpmass_ = Float64[]
    cpmole_ = Float64[]
    hmass_ = Float64[]
    hmole_ = Float64[]
    smass_ = Float64[]
    smole_ = Float64[]
    cond_ = Float64[]
    v_ = Float64[]
    l_ = Float64[]
    diff_mix_ = Float64[]

    function set_temperature(T)
        global T_
        if T != T_
            T_ = T
            refresh()
        end
    end

    function set_pressure(p)
        global p_
        if p != p_
            p_ = p
            refresh()
        end
    end

    function set_number_of_species(NC)
        global NC_
        if NC != NC_
            NC_ = NC
            refresh()
            resize()
        end
    end

    function set_species_names(species)
        global NC_, index_, MW_, names_, transport_
        if size(species,1) == NC_
            for j in 1:NC_
                index_[j] = -1
                names_[j] = species[j]
                for i in 1:transport_.NC
                    if transport_.name[i] == names_[j]
                        index_[j] = i
                        MW_[j] = transport_.MW[i]
                        break
                    end
                end
                if index_[j] == -1
                    print(string("\nASALI::ERROR--> ",species[j]," is missing in ASALI database\n"))
                    exit()
                end
            end
            refresh()
        else
            print("\nASALI::ERROR-->Wrong number of species names\n")
            exit()
        end
    end

    function set_mass_fraction(y)
        global NC_, MW_, MWmix_, y_, x_
        if size(y,1) == NC_
            MWmix_ = 0
            for i in 1:NC_
                y_[i] = y[i]
                MWmix_ = MWmix_ + y[i]/MW_[i]
            end

            for i in 1:NC_
                x_[i] = (y_[i]/MW_[i])/MWmix_
            end
            refresh()
        else
            print("\nASALI::ERROR-->Wrong number of mass fractions\n")
            exit()
        end
    end

    function set_mole_fraction(x)
        global NC_, MW_, MWmix_, y_, x_
        if size(x,1) == NC_
            MWmix_ = 0
            for i in 1:NC_
                x_[i] = x[i]
                MWmix_ = MWmix_ + x[i]*MW_[i]
            end

            for i in 1:NC_
                y_[i] = x_[i]*MW_[i]/MWmix_
            end
            refresh()
        else
            print("\nASALI::ERROR-->Wrong number of mole fractions\n")
            exit()
        end
    end

    function species_viscosity_()
        global NC_, mu_updated_, transport_, mu_, T_, index_, pi_
        if !mu_updated_
            for i in 1:NC_
                id = index_[i]
                Tr = T_/transport_.LJpotential[id]
                dr = 0.5*(transport_.dipole[id]^2.)
                dr = dr/(transport_.LJpotential[id]*1.3806488*(transport_.LJdiameter[id]^3.))
                dr = 1e06*dr
                sigma = collision_integrals_22_(Tr,dr)
                mu_[i] = (5/16)*sqrt(pi_*1.3806488*T_*MW_[i]*1.66054)/(pi_*sigma*(transport_.LJdiameter[id]^2.))
                mu_[i] = mu_[i]*1e-05
            end
            mu_updated_ = true
        end
    end

    function density_()
        global MWmix_, T_, rho_, p_, rho_updated_
        if !rho_updated_
            rho_ = MWmix_*p_/(8314*T_)
            rho_updated_ = true
        end
    end

    function binary_diffusion_()
        global diff_updated_, NC_, MW_, T_, pi_, p_
        if !diff_updated_
            for i in 1:NC_
                for j in 1:i
                    diff_[i,j] = diff_[j,i]
                end

                for j in i:NC_
                    MWmix = MW_[i]*MW_[j]/(MW_[i] + MW_[j])
                    id = index_[i]
                    jd = index_[j]
                    if transport_.polar[id] == 0. && transport_.polar[jd] == 0.
                        LJpotentialmix = sqrt(transport_.LJpotential[id]*transport_.LJpotential[jd])
                        LJdiametermix  = 0.5*(transport_.LJdiameter[id] + transport_.LJdiameter[jd])
                        dipolemix      = sqrt(transport_.dipole[id]*transport_.dipole[jd])
                    elseif transport_.polar[id] > 0. && transport_.polar[jd] > 0.
                        LJpotentialmix = sqrt(transport_.LJpotential[id]*transport_.LJpotential[jd])
                        LJdiametermix  = 0.5*(transport_.LJdiameter[id] + transport_.LJdiameter[jd])
                        dipolemix      = sqrt(transport_.dipole[jd]*transport_.dipole[jd])
                    else
                        polarn  = 0.
                        dipolep = 0.

                        if transport_.polar[id] == 0.
                            polarn  = transport_.polar[id]/(transport_.LJdiameter[id]^3.)
                            dipolep = 1e02*transport_.dipole[jd]
                            dipolep = dipolep/sqrt(transport_.LJpotential[jd]*1.3806488*transport_.LJdiameter[jd]^3.)
                            chi     = 0.25*polarn*dipolep
                            chi     = chi*sqrt(transport_.LJpotential[jd]/transport_.LJpotential[id])
                            chi     = 1. + chi
                        else
                            polarn  = transport_.polar[jd]/(transport_.LJdiameter[jd]^3.)
                            dipolep = 1e02*transport_.dipole[id]
                            dipolep = dipolep/sqrt(transport_.LJpotential[id]*1.3806488*transport_.LJdiameter[id]^3.)
                            chi     = 0.25*polarn*dipolep
                            chi     = chi*sqrt(transport_.LJpotential[id]/transport_.LJpotential[jd])
                            chi     = 1. + chi
                        end

                        LJpotentialmix = (chi^2.)*sqrt(transport_.LJpotential[id]*transport_.LJpotential[jd])
                        LJdiametermix  = 0.5*(transport_.LJdiameter[id] + transport_.LJdiameter[jd])*(chi^(-1/6))
                        dipolemix      = 0.
                    end
                    Tr          = T_/LJpotentialmix
                    dr          = 0.5*(dipolemix^2.)/(LJpotentialmix*1.3806488*(LJdiametermix^3.))
                    dr          = 1e06*dr
                    sigma       = collision_integrals_11_(Tr,dr)
                    diff_[i,j] = (3/16.)*sqrt(2*pi_*((1.3806488*T_)^3.)/(MWmix*1.66054))/(p_*pi_*(LJdiametermix^2)*sigma)
                    diff_[i,j] = diff_[i,j]*0.1
                end
            end
            diff_updated_ = true
        end
    end

    function species_cp_()
        global cp_updated_, cpmole_, cpmass_, T_, NC_, thermo_, index_, MW_
        if !cp_updated_
            for i in 1:NC_
                if T_ < 1000
                    cpmole_[i]  = thermo_.lowA[index_[i]]
                    cpmole_[i] += thermo_.lowB[index_[i]]*T_
                    cpmole_[i] += thermo_.lowC[index_[i]]*(T_^2.)
                    cpmole_[i] += thermo_.lowD[index_[i]]*(T_^3.)
                    cpmole_[i] += thermo_.lowE[index_[i]]*(T_^4.)
                else
                    cpmole_[i]  = thermo_.highA[index_[i]]
                    cpmole_[i] += thermo_.highB[index_[i]]*T_
                    cpmole_[i] += thermo_.highC[index_[i]]*(T_^2.)
                    cpmole_[i] += thermo_.highD[index_[i]]*(T_^3.)
                    cpmole_[i] += thermo_.highE[index_[i]]*(T_^4.)
                end
                cpmole_[i] = cpmole_[i]*8314.  #J/Kmol/K
                cpmass_[i] = cpmole_[i]/MW_[i] #J/Kg/K
            end
            cp_updated_ = true
        end
    end

    function species_h_()
        global h_updated_, hmole_, hmass_, T_, NC_, thermo_, index_, MW_
        if !h_updated_
            for i in 1:NC_
                if T_ < 1000
                    hmole_[i]  = thermo_.lowA[index_[i]]
                    hmole_[i] += thermo_.lowB[index_[i]]*T_/2
                    hmole_[i] += thermo_.lowC[index_[i]]*(T_^2.)/3
                    hmole_[i] += thermo_.lowD[index_[i]]*(T_^3.)/4
                    hmole_[i] += thermo_.lowE[index_[i]]*(T_^4.)/5
                    hmole_[i] += thermo_.lowF[index_[i]]/T_
                else
                    hmole_[i]  = thermo_.highA[index_[i]]
                    hmole_[i] += thermo_.highB[index_[i]]*T_/2
                    hmole_[i] += thermo_.highC[index_[i]]*(T_^2.)/3
                    hmole_[i] += thermo_.highD[index_[i]]*(T_^3.)/4
                    hmole_[i] += thermo_.highE[index_[i]]*(T_^4.)/5
                    hmole_[i] += thermo_.highF[index_[i]]/T_
                end
                hmole_[i] = hmole_[i]*8314*T_  #J/Kmol/K
                hmass_[i] = hmole_[i]/MW_[i] #J/Kg/K
            end
            h_updated_ = true
        end
    end

    function species_s_()
        global s_updated_, smole_, smass_, T_, NC_, thermo_, index_, MW_
        if !s_updated_
            for i in 1:NC_
                if T_ < 1000
                    smole_[i]  = thermo_.lowA[index_[i]]*log(T_)
                    smole_[i] += thermo_.lowB[index_[i]]*T_
                    smole_[i] += thermo_.lowC[index_[i]]*(T_^2.)/2
                    smole_[i] += thermo_.lowD[index_[i]]*(T_^3.)/3
                    smole_[i] += thermo_.lowE[index_[i]]*(T_^4.)/4
                    smole_[i] += thermo_.lowG[index_[i]]
                else
                    smole_[i]  = thermo_.highA[index_[i]]*log(T_)
                    smole_[i] += thermo_.highB[index_[i]]*T_
                    smole_[i] += thermo_.highC[index_[i]]*(T_^2.)/2
                    smole_[i] += thermo_.highD[index_[i]]*(T_^3.)/3
                    smole_[i] += thermo_.highE[index_[i]]*(T_^4.)/4
                    smole_[i] += thermo_.highG[index_[i]]
                end
                smole_[i] = 8314*(smole_[i] - log(p_*x_[i]/1.e05))  #J/Kmol/K
                smass_[i] = smole_[i]/MW_[i] #J/Kg/K
            end
            s_updated_ = true
        end
    end

    function species_thermal_conductivity_()
        global cond_updated_, diff_, cpmole_, mu_, NC_, rho_, index_, transport_, T_, pi_, MW_, cond_

        species_viscosity_()
        binary_diffusion_()
        density_()
        species_cp_()

        R = 8314

        if !cond_updated_
            for i in 1:NC_
                id = index_[i]
                if ( transport_.geometry[id] == 0)
                    cvtrans = 3*R*0.5
                    cvrot   = 0.
                    cvvib   = 0.
                elseif ( transport_.geometry[id] == 1)
                    cvtrans = 3*R*0.5
                    cvrot   = R
                    cvvib   = cpmole_[i] - R - 5*R*0.5
                else
                    cvtrans = 3*R*0.5
                    cvrot   = 3*R*0.5
                    cvvib   = cpmole_[i] - R - 3*R
                end

                rho = MW_[i]*p_/(R*T_)
                A = (5/2) - rho*diff_[i,i]/mu_[i]

                F_T = 1 + 0.5*sqrt((pi_^3)*transport_.LJpotential[id]/T_)
                        + (0.25*(pi_^2) + 2)*(transport_.LJpotential[id]/T_)
                        + sqrt((pi_*transport_.LJpotential[id]/T_)^3)

                F_298 = 1 + 0.5*sqrt((pi_^3)*transport_.LJpotential[id]/298)
                      + (0.25*(pi_^2) + 2)*(transport_.LJpotential[id]/298)
                      + sqrt((pi_*transport_.LJpotential[id]/298)^3)

                Zrot = transport_.collision[id]*F_298/F_T

                B = Zrot + (2/pi_)*((5/3)*(cvrot/R) + rho*diff_[i,i]/mu_[i])

                ftrans = (5/2)*(1 - 2*cvrot*A/(pi_*cvtrans*B))
                frot   = (rho*diff_[i,i]/mu_[i])*(1 + 2*A/(pi_*B))
                fvib   = rho*diff_[i,i]/mu_[i]

                cond_[i] = mu_[i]*(ftrans*cvtrans + frot*cvrot + fvib*cvvib)/MW_[i]

            end
            cond_updated_ = true
        end
    end

    function resize()
        global NC_, index_, MW_, names_, mu_, diff_, x_, y_, cpmole_, cpmass_,
               hmole_, hmass_, smole_, smass_, cond_, v_, l_, diff_mix_
        resize!(index_,NC_)
        resize!(MW_,NC_)
        resize!(names_,NC_)
        resize!(y_,NC_)
        resize!(x_,NC_)
        resize!(mu_,NC_)
        resize!(cpmass_,NC_)
        resize!(cpmole_,NC_)
        resize!(hmass_,NC_)
        resize!(hmole_,NC_)
        resize!(smass_,NC_)
        resize!(smole_,NC_)
        resize!(cond_,NC_)
        resize!(v_,NC_)
        resize!(l_,NC_)
        resize!(diff_mix_,NC_)
        resize!(diff_,NC_*NC_)
        diff_= reshape(diff_, NC_, NC_)
    end

    function refresh()
        global mu_updated_, rho_updated_, diff_updated_, cp_updated_,
               h_updated_, s_updated_, cond_updated_, cond_mix_updated_,
               mu_mix_updated_, v_updated_, l_updated_, cpmole_mix_updated_,
               cpmass_mix_updated_, hmole_mix_updated_, hmass_mix_updated_,
               smole_mix_updated_, smass_mix_updated_, diff_mix_updated_
               mu_updated_ = false
               rho_updated_ = false
               diff_updated_ = false
               cp_updated_ = false
               h_updated_ = false
               s_updated_ = false
               cond_updated_ = false
               cond_mix_updated_ = false
               mu_mix_updated_ = false
               v_updated_ = false
               l_updated_ = false
               cpmole_mix_updated_ = false
               cpmass_mix_updated_ = false
               hmole_mix_updated_ = false
               hmass_mix_updated_ = false
               smole_mix_updated_ = false
               smass_mix_updated_ = false
               diff_mix_updated_ = false
    end

    function collision_integrals_22_(Tr,dr)
        Ta = -1
        Tb = -1

        for j in 1:size(omega22_.T,1)-1
            if ( Tr >= omega22_.T[j] && Tr < omega22_.T[j+1] )
                Ta = j
                Tb = j + 1
                break
            end
        end

        if ( Ta == -1 )
            if ( Tr <= omega22_.T[1] )
                Ta = 1
                Tb = 2
            elseif ( Tr >= omega22_.T[end] )
                Ta = size(omega22_.T,1)-1
                Tb = size(omega22_.T,1)
            end
        end

        da = -1
        db = -1

        for j in 1:size(omega22_.d,1)-1
            if ( dr >= omega22_.d[j] && dr < omega22_.d[j+1] )
                da = j
                db = j + 1
                break
            end
        end

        if ( da == -1 )
            if ( dr <= omega22_.d[1] )
                da = 1
                db = 2
            elseif ( dr >= omega22_.d[end] )
                da = size(omega22_.d,1)-1
                db = size(omega22_.d,1)
            end
        end

        A = [1. omega22_.T[Ta] omega22_.d[da] omega22_.T[Ta]*omega22_.d[da];
             1. omega22_.T[Ta] omega22_.d[db] omega22_.T[Ta]*omega22_.d[db];
             1. omega22_.T[Tb] omega22_.d[da] omega22_.T[Tb]*omega22_.d[da];
             1. omega22_.T[Tb] omega22_.d[db] omega22_.T[Tb]*omega22_.d[db]]

        b = [omega22_.s[Ta,da]; omega22_.s[Ta,db]; omega22_.s[Tb,da]; omega22_.s[Tb,db]]

        x = A\b
        return x[1] + x[2]*Tr + x[3]*dr + x[4]*Tr*dr
    end

    function collision_integrals_11_(Tr,dr)
        Ta = -1
        Tb = -1

        for j in 1:size(omega11_.T,1)-1
            if ( Tr >= omega11_.T[j] && Tr < omega11_.T[j+1] )
                Ta = j
                Tb = j + 1
                break
            end
        end

        if ( Ta == -1 )
            if ( Tr <= omega11_.T[1] )
                Ta = 1
                Tb = 2
            elseif ( Tr >= omega11_.T[end] )
                Ta = size(omega11_.T,1)-1
                Tb = size(omega11_.T,1)
            end
        end

        da = -1
        db = -1

        for j in 1:size(omega11_.d,1)-1
            if ( dr >= omega11_.d[j] && dr < omega11_.d[j+1] )
                da = j
                db = j + 1
                break
            end
        end

        if ( da == -1 )
            if ( dr <= omega11_.d[1] )
                da = 1
                db = 2
            elseif ( dr >= omega11_.d[end] )
                da = size(omega11_.d,1)-1
                db = size(omega11_.d,1)
            end
        end

        A = [1. omega11_.T[Ta] omega11_.d[da] omega11_.T[Ta]*omega11_.d[da];
             1. omega11_.T[Ta] omega11_.d[db] omega11_.T[Ta]*omega11_.d[db];
             1. omega11_.T[Tb] omega11_.d[da] omega11_.T[Tb]*omega11_.d[da];
             1. omega11_.T[Tb] omega11_.d[db] omega11_.T[Tb]*omega11_.d[db]]

        b = [omega11_.s[Ta,da]; omega11_.s[Ta,db]; omega11_.s[Tb,da]; omega11_.s[Tb,db]]

        x = A\b
        return x[1] + x[2]*Tr + x[3]*dr + x[4]*Tr*dr
    end


    function get_species_viscosity()
        global mu_
        species_viscosity_()
        return mu_
    end

    function get_density()
        global rho_
        density_()
        return rho_
    end

    function get_mixture_molecular_weight()
        global MWmix_
        return MWmix_
    end

    function get_binary_diffusion()
        global diff_
        binary_diffusion_()
        return diff_
    end

    function get_species_molar_specific_heat()
        global cpmole_
        species_cp_()
        return cpmole_
    end

    function get_species_mass_specific_heat()
        global cpmass_
        species_cp_()
        return cpmass_
    end

    function get_species_molar_enthalpy()
        global hmole_
        species_h_()
        return hmole_
    end

    function get_species_mass_enthalpy()
        global hmass_
        species_h_()
        return hmass_
    end

    function get_species_molar_entropy()
        global smole_
        species_s_()
        return smole_
    end

    function get_species_mass_entropy()
        global smass_
        species_s_()
        return smass_
    end

    function get_species_thermal_conductivity()
        global cond_
        species_thermal_conductivity_()
        return cond_
    end

    function get_mixture_thermal_conductivity()
        global cond_mix_, cond_, NC_, x_, cond_mix_updated_
        if !cond_mix_updated_
            species_thermal_conductivity_()
            A = 0
            B = 0
            for i in 1:NC_
                A = A + x_[i]*cond_[i]
                B = B + x_[i]/cond_[i]
            end
            cond_mix_ = 0.5*(A + 1/B)
            cond_mix_updated_ = true
        end
        return cond_mix_
    end

    function get_mixture_viscosity()
        global mu_mix_, mu_mix_updated_, NC_, x_, MW_, mu_
        if !mu_mix_updated_
            species_viscosity_()
            for k in 1:NC_
                somma = 0
                for j in 1:NC_
                    phi = (1/sqrt(8))*(1/sqrt(1 + MW_[k]/MW_[j]))
                    phi = phi*((1 + sqrt(mu_[k]/mu_[j])*((MW_[j]/MW_[k])^(1/4)))^2)
                    somma = somma + x_[j]*phi;
                end
                mu_mix_ = mu_mix_ + x_[k]*mu_[k]/somma
            end
            mu_mix_updated_ = true
        end
        return mu_mix_
    end

    function get_mixture_diffusion()
        global diff_mix_updated_, diff_mix_, NC_, diff_, x_, MWmix_
        if !diff_mix_updated_
            binary_diffusion_()
            for k in 1:NC_
                A = 0
                B = 0
                for j in 1:NC_
                    if j != k
                        A = A + x_[j]*MW_[j];
                        B = B + x_[j]/diff_[j,k];
                    end
                end
                diff_mix_[k] = A/(MWmix_*B)
            end
            diff_mix_updated_ = true
        end
        return diff_mix_
    end

    function get_aritmetic_mean_gas_velocity()
        global v_updated_, NC_, v_, pi_, T_, MW_
        if !v_updated_
            for i in 1:NC_
                v_[i] = sqrt(8*8314*T_/(pi_*MW_[i]))
            end
            v_updated_ = true
        end
        return v_
    end

    function get_mean_free_path()
        global l_updated_, NC_, l_, transport_, p_, T_, index_
        if !l_updated_
            for i in 1:NC_
                l_[i] = 1.38064852*1e-03*T_/(sqrt(2)*p_*(transport_.LJdiameter[index_[i]]^2))
            end
            l_updated_ = true
        end
        return l_
    end

    function get_mixture_molar_specific_heat()
        global cpmole_mix_, cpmole_mix_updated_, NC_, x_
        if !cpmole_mix_updated_
            cpmole_mix_ = 0
            species_cp_()
            for i in 1:NC_
                cpmole_mix_ = cpmole_mix_ + x_[i]*cpmole_[i]
            end
            cpmole_mix_updated_ = true
        end
        return cpmole_mix_
    end

    function get_mixture_mass_specific_heat()
        global cpmass_mix_, cpmass_mix_updated_, NC_, y_
        if !cpmass_mix_updated_
            cpmass_mix_ = 0
            species_cp_()
            for i in 1:NC_
                cpmass_mix_ = cpmass_mix_ + y_[i]*cpmass_[i]
            end
            cpmass_mix_updated_ = true
        end
        return cpmass_mix_
    end

    function get_mixture_molar_enthalpy()
        global hmole_mix_, hmole_mix_updated_, NC_, x_
        if !hmole_mix_updated_
            hmole_mix_ = 0
            species_h_()
            for i in 1:NC_
                hmole_mix_ = hmole_mix_ + x_[i]*hmole_[i]
            end
            hmole_mix_updated_ = true
        end
        return hmole_mix_
    end

    function get_mixture_mass_enthalpy()
        global hmass_mix_, hmass_mix_updated_, NC_, y_
        if !hmass_mix_updated_
            hmass_mix_ = 0
            species_h_()
            for i in 1:NC_
                hmass_mix_ = hmass_mix_ + y_[i]*hmass_[i]
            end
            hmass_mix_updated_ = true
        end
        return hmass_mix_
    end

    function get_mixture_molar_entropy()
        global smole_mix_, smole_mix_updated_, NC_, x_
        if !smole_mix_updated_
            smole_mix_ = 0
            species_s_()
            for i in 1:NC_
                smole_mix_ = smole_mix_ + x_[i]*smole_[i]
            end
            smole_mix_updated_ = true
        end
        return smole_mix_
    end

    function get_mixture_mass_entropy()
        global smass_mix_, smass_mix_updated_, NC_, y_
        if !smass_mix_updated_
            smass_mix_ = 0
            species_s_()
            for i in 1:NC_
                smass_mix_ = smass_mix_ + y_[i]*smass_[i]
            end
            smass_mix_updated_ = true
        end
        return smass_mix_
    end

    export set_temperature, set_pressure, set_number_of_species, set_species_names,
           set_mass_fraction, set_mole_fraction, get_species_viscosity, get_density,
           get_mixture_molecular_weight, get_binary_diffusion, get_species_molar_specific_heat,
           get_species_mass_specific_heat, get_species_molar_enthalpy, get_species_mass_enthalpy,
           get_species_molar_entropy, get_species_mass_entropy, get_species_thermal_conductivity,
           get_mixture_thermal_conductivity, get_mixture_viscosity, get_aritmetic_mean_gas_velocity,
           get_mean_free_path, get_mixture_molar_specific_heat, get_mixture_mass_specific_heat,
           get_mixture_molar_enthalpy, get_mixture_mass_enthalpy, get_mixture_molar_entropy,
           get_mixture_mass_entropy
end
