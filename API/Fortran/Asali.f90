!################################################################################################
!#                                                                                              #
!#     #############       #############       #############       ####                ####     #
!#    #             #     #             #     #             #     #    #              #    #    #
!#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #
!#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #
!#    #    #####    #     #    #              #    #####    #     #    #              #    #    #
!#    #             #     #    #########      #             #     #    #              #    #    #
!#    #             #     #             #     #             #     #    #              #    #    #
!#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #
!#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #
!#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #
!#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #
!#     ####     ####       #############       ####     ####       #############       ####     #
!#                                                                                              #
!#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #
!#                                                                                              #
!################################################################################################
!#                                                                                              #
!#   License                                                                                    #
!#                                                                                              #
!#   This file is part of ASALI.                                                                #
!#                                                                                              #
!#   ASALI is free software: you can redistribute it and/or modify                              #
!#   it under the terms of the GNU General Public License as published by                       #
!#   the Free Software Foundation, either version 3 of the License, or                          #
!#   (at your option) any later version.                                                        #
!#                                                                                              #
!#   ASALI is distributed in the hope that it will be useful,                                   #
!#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #
!#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #
!#   GNU General Public License for more details.                                               #
!#                                                                                              #
!#   You should have received a copy of the GNU General Public License                          #
!#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #
!#                                                                                              #
!################################################################################################

module asali
    implicit none 

    include "definitions.f90"
    
    real              :: T_, P_, MWmix_, rho_, mu_mix_, cond_mix_, cpmole_mix_, &
                         cpmass_mix_, hmole_mix_, hmass_mix_, smole_mix_, smass_mix_
    real              :: pi_ = 3.14159265358979323846
    real, allocatable :: MW_(:), x_(:), y_(:), mu_(:), diff_(:,:), cpmole_(:), cpmass_(:), &
                         hmole_(:), hmass_(:), smole_(:), smass_(:), cond_(:), diff_mix_(:), &
                         v_(:), l_(:)
    
    integer              :: NC_
    integer, allocatable :: index_(:)
    
    character(len=200)              :: error_
    character(len=200), allocatable :: name_(:)
    
    logical :: mu_update_   = .FALSE.
    logical :: diff_update_ = .FALSE.
    logical :: rho_update_  = .FALSE.
    logical :: cp_update_   = .FALSE.
    logical :: h_update_    = .FALSE.
    logical :: s_update_    = .FALSE.
    logical :: cond_update_ = .FALSE.
    logical :: v_update_    = .FALSE.
    logical :: l_update_    = .FALSE.
    logical :: mu_mix_update_     = .FALSE.
    logical :: diff_mix_update_   = .FALSE.
    logical :: cond_mix_update_   = .FALSE.
    logical :: cpmole_mix_update_ = .FALSE.
    logical :: cpmass_mix_update_ = .FALSE.
    logical :: hmole_mix_update_  = .FALSE.
    logical :: hmass_mix_update_  = .FALSE.
    logical :: smole_mix_update_  = .FALSE.

    contains      
    include "transport_subroutine.f90"
    include "thermo_subroutine.f90"
    include "omega_subroutine.f90"
    
    subroutine set_temperature(T)
        real, intent(in) :: T
        if ( T .NE. T_ ) then
            T_ = T
            mu_update_   = .FALSE.
            diff_update_ = .FALSE.
            rho_update_  = .FALSE.
            cp_update_   = .FALSE.
            h_update_    = .FALSE.
            s_update_    = .FALSE.
            cond_update_ = .FALSE.
            v_update_    = .FALSE.
            l_update_    = .FALSE.
            mu_mix_update_     = .FALSE.
            diff_mix_update_   = .FALSE.
            cond_mix_update_   = .FALSE.
            cpmole_mix_update_ = .FALSE.
            cpmass_mix_update_ = .FALSE.
            hmole_mix_update_  = .FALSE.
            hmass_mix_update_  = .FALSE.
            smole_mix_update_  = .FALSE.
        end if
    end subroutine set_temperature
    
    subroutine set_pressure(P)
        real, intent(in) :: P
        if ( P .NE. P_ ) then
            P_ = P
            mu_update_   = .FALSE.
            diff_update_ = .FALSE.
            rho_update_  = .FALSE.
            cp_update_   = .FALSE.
            h_update_    = .FALSE.
            s_update_    = .FALSE.
            cond_update_ = .FALSE.
            v_update_    = .FALSE.
            l_update_    = .FALSE.
            mu_mix_update_     = .FALSE.
            diff_mix_update_   = .FALSE.
            cond_mix_update_   = .FALSE.
            cpmole_mix_update_ = .FALSE.
            cpmass_mix_update_ = .FALSE.
            hmole_mix_update_  = .FALSE.
            hmass_mix_update_  = .FALSE.
            smole_mix_update_  = .FALSE.
        end if
    end subroutine set_pressure
    
    subroutine set_number_of_species(NC)
        integer, intent(in) :: NC
        if ( NC_ .NE. NC ) then
            NC_ = NC
            call resize(NC)
            call transport_update()
            call thermo_update()
            call omega_update()
        end if
    end subroutine set_number_of_species
    
    subroutine set_species_names(names)
        character(len=200), dimension(:), intent(in) :: names
        integer :: j,i
        if ( all(names .NE. name_) ) then
            if (size(names) .EQ. NC_) then
                do j=1,NC_
                    index_(j) = -1
                    name_(j) = names(j)
                    do i=1,size(transport_)
                        if ( trim(names(j)) .EQ. trim(transport_(i)%nome) ) then
                            index_(j) = i
                            MW_(j) = transport_(i)%MW
                            exit
                        end if
                    end do
                    
                    if ( index_(j) .EQ. -1 ) then
                        error_ = 'ASALI::ERROR-->'
                        error_ = trim(error_)//trim(names(j))
                        error_ = trim(error_)//' is missing in ASALI database.'
                        print*, error_
                        error stop
                    end if
                end do
            else
                print *,'ASALI::ERROR-->Wrong number of species names'
                error stop
            end if
            mu_update_   = .FALSE.
            diff_update_ = .FALSE.
            rho_update_  = .FALSE.
            cp_update_   = .FALSE.
            h_update_    = .FALSE.
            s_update_    = .FALSE.
            cond_update_ = .FALSE.
            v_update_    = .FALSE.
            l_update_    = .FALSE.
            mu_mix_update_     = .FALSE.
            diff_mix_update_   = .FALSE.
            cond_mix_update_   = .FALSE.
            cpmole_mix_update_ = .FALSE.
            cpmass_mix_update_ = .FALSE.
            hmole_mix_update_  = .FALSE.
            hmass_mix_update_  = .FALSE.
            smole_mix_update_  = .FALSE.
        end if
    end subroutine set_species_names
    
    subroutine set_mass_fraction(y)
        real, dimension(:), intent(in) :: y
        integer :: i
        if ( all(y_ .NE. y) ) then
            y_ = y
            if ( size(y) .EQ. NC_ ) then
                MWmix_ = 0.
                do i=1,NC_
                    MWmix_ = MWmix_ + y_(i)/MW_(i)
                end do
                
                do i=1,NC_
                    x_(i) = (y_(i)/MW_(i))/MWmix_
                end do
                
                MWmix_ = 1/MWmix_
            else
                print *,'ASALI::ERROR-->Wrong number of mass fractions'
                error stop
            end if 
            mu_update_   = .FALSE.
            diff_update_ = .FALSE.
            rho_update_  = .FALSE.
            cp_update_   = .FALSE.
            h_update_    = .FALSE.
            s_update_    = .FALSE.
            cond_update_ = .FALSE.
            v_update_    = .FALSE.
            l_update_    = .FALSE.
            mu_mix_update_     = .FALSE.
            diff_mix_update_   = .FALSE.
            cond_mix_update_   = .FALSE.
            cpmole_mix_update_ = .FALSE.
            cpmass_mix_update_ = .FALSE.
            hmole_mix_update_  = .FALSE.
            hmass_mix_update_  = .FALSE.
            smole_mix_update_  = .FALSE.
        end if
    end subroutine set_mass_fraction

    subroutine set_mole_fraction(x)
        real, dimension(:), intent(in) :: x
        integer :: i
        if ( all(x_ .NE. x)) then
            x_ = x
            if ( size(x) .EQ. NC_ ) then
                MWmix_ = 0.
                do i=1,NC_
                    MWmix_ = MWmix_ + x_(i)*MW_(i)
                end do
                
                do i=1,NC_
                    y_(i) = x_(i)*MW_(i)/MWmix_
                end do
            else
                print *,'ASALI::ERROR-->Wrong number of mole fractions'
                error stop
            end if 
            mu_update_   = .FALSE.
            diff_update_ = .FALSE.
            rho_update_  = .FALSE.
            cp_update_   = .FALSE.
            h_update_    = .FALSE.
            s_update_    = .FALSE.
            cond_update_ = .FALSE.
            v_update_    = .FALSE.
            l_update_    = .FALSE.
            mu_mix_update_     = .FALSE.
            diff_mix_update_   = .FALSE.
            cond_mix_update_   = .FALSE.
            cpmole_mix_update_ = .FALSE.
            cpmass_mix_update_ = .FALSE.
            hmole_mix_update_  = .FALSE.
            hmass_mix_update_  = .FALSE.
            smole_mix_update_  = .FALSE.
        end if
    end subroutine set_mole_fraction
    
    function get_mass_fraction()
        real, dimension(NC_) :: get_mass_fraction
        get_mass_fraction = y_
        return
    end function get_mass_fraction

    function get_mole_fraction()
        real, dimension(NC_) :: get_mole_fraction
        get_mole_fraction = x_
        return
    end function get_mole_fraction

    subroutine species_viscosity_()     ![Pa*s]
        real :: Tr, dr, sigma
        integer :: i
        if ( mu_update_ .EQV. .FALSE. ) then
            do i=1,NC_
                Tr     = T_/transport_(index_(i))%LJpotential
                dr     = 0.5*(transport_(index_(i))%dipole**2.)
                dr     = dr/(transport_(index_(i))%LJpotential*1.3806488*(transport_(index_(i))%LJdiameter**3.))
                dr     = 1e06*dr
                sigma  = collision_integrals_22(Tr,dr)
                mu_(i) = (5./16.)*sqrt(pi_*1.3806488*T_*MW_(i)*1.66054)/(pi_*sigma*(transport_(index_(i))%LJdiameter**2.))
                mu_(i) = mu_(i)*1.e-05;
            end do
            mu_update_ = .TRUE.
        end if
    end subroutine species_viscosity_
    
    function get_species_viscosity()
        real, dimension(NC_) :: get_species_viscosity
        call species_viscosity_()
        get_species_viscosity = mu_
        return
    end function get_species_viscosity

    subroutine density_() ![kg/m3]
        if ( rho_update_ .EQV. .FALSE. ) then
            rho_ = MWmix_*P_/(8314.*T_)
            rho_update_ = .TRUE.
        end if
    end subroutine
    
    function get_density()
        real :: get_density
        call density_
        get_density = rho_
    end function get_density

    function get_mixture_molecular_weight()
        real :: get_mixture_molecular_weight
        get_mixture_molecular_weight = MWmix_
    end function get_mixture_molecular_weight

    subroutine binary_diffusion_()  ![m2/s]
        real :: MWmix, LJpotentialmix, LJdiametermix, dipolemix, &
                polarn, dipolep, chi, sigma, Tr, dr

        integer :: i,j
        
        if ( diff_update_ .EQV. .FALSE. ) then
            do i=1,NC_
                do j=1,i
                    diff_(i,j) = diff_(j,i)
                end do
                
                do j=i,NC_
                    MWmix = MW_(i)*MW_(j)/(MW_(i) + MW_(j))
                    
                    if ( transport_(index_(i))%polar .EQ. 0. .AND. transport_(index_(j))%polar .EQ. 0. ) then
                        LJpotentialmix = sqrt(transport_(index_(i))%LJpotential*transport_(index_(j))%LJpotential)
                        LJdiametermix  = 0.5*(transport_(index_(i))%LJdiameter + transport_(index_(j))%LJdiameter)
                        dipolemix      = sqrt(transport_(index_(i))%dipole*transport_(index_(j))%dipole)
                    else if ( transport_(index_(i))%polar .GT. 0. .AND. transport_(index_(j))%polar .GT. 0. ) then
                        LJpotentialmix = sqrt(transport_(index_(i))%LJpotential*transport_(index_(j))%LJpotential)
                        LJdiametermix  = 0.5*(transport_(index_(i))%LJdiameter + transport_(index_(j))%LJdiameter)
                        dipolemix      = sqrt(transport_(index_(i))%dipole*transport_(index_(j))%dipole)
                    else
                        polarn  = 0.
                        dipolep = 0.

                        if ( transport_(index_(i))%polar .EQ. 0. ) then
                            polarn  = transport_(index_(i))%polar/(transport_(index_(i))%LJdiameter**3.)
                            dipolep = 1e02*transport_(index_(j))%dipole
                            dipolep = dipolep/sqrt(transport_(index_(j))%LJpotential*1.3806488*transport_(index_(j))%LJdiameter**3.)
                            chi     = 0.25*polarn*dipolep
                            chi     = chi*sqrt(transport_(index_(j))%LJpotential/transport_(index_(i))%LJpotential)
                            chi     = 1. + chi 
                        else
                            polarn  = transport_(index_(j))%polar/(transport_(index_(j))%LJdiameter**3.)
                            dipolep = 1e02*transport_(index_(i))%dipole
                            dipolep = dipolep/sqrt(transport_(index_(i))%LJpotential*1.3806488*transport_(index_(i))%LJdiameter**3.)
                            chi     = 0.25*polarn*dipolep
                            chi     = chi*sqrt(transport_(index_(i))%LJpotential/transport_(index_(j))%LJpotential)
                            chi     = 1. + chi
                        end if

                        LJpotentialmix = (chi**2.)*sqrt(transport_(index_(i))%LJpotential*transport_(index_(j))%LJpotential)
                        LJdiametermix  = 0.5*(transport_(index_(i))%LJdiameter + transport_(index_(j))%LJdiameter)*(chi**(-1./6.))
                        dipolemix      = 0.
                    end if
                
                    Tr          = T_/LJpotentialmix
                    dr          = 0.5*(dipolemix**2.)/(LJpotentialmix*1.3806488*(LJdiametermix**3.))
                    dr          = 1e06*dr
                    sigma       = collision_integrals_11(Tr,dr)
                    diff_(i,j) = (3./16.)*sqrt(2.*pi_*((1.3806488*T_)**3.)/(MWmix*1.66054))/(P_*pi_*(LJdiametermix**2.)*sigma)
                    diff_(i,j) = diff_(i,j)*0.1
                    
                end do
            end do
            diff_update_ = .TRUE.
        end if
    end subroutine binary_diffusion_

    function get_binary_diffusion()
        real, dimension(NC_,NC_) :: get_binary_diffusion
        call binary_diffusion_()
        get_binary_diffusion = diff_
        return
    end function get_binary_diffusion

    subroutine species_cp_()
        integer :: i
        
        if ( cp_update_ .EQV. .FALSE. ) then     
            do i=1,NC_
                if ( T_ .LT. 1000. ) then
                    cpmole_(i) = thermo_(index_(i))%low(1)           &
                               + thermo_(index_(i))%low(2)*T_        &
                               + thermo_(index_(i))%low(3)*(T_**2.)  &
                               + thermo_(index_(i))%low(4)*(T_**3.)  &
                               + thermo_(index_(i))%low(5)*(T_**4.)
                else
                    cpmole_(i) = thermo_(index_(i))%high(1)           &
                               + thermo_(index_(i))%high(2)*T_        &
                               + thermo_(index_(i))%high(3)*(T_**2.)  &
                               + thermo_(index_(i))%high(4)*(T_**3.)  &
                               + thermo_(index_(i))%high(5)*(T_**4.)
                end if
                
                cpmole_(i) = cpmole_(i)*8314.  !J/Kmol/K
                cpmass_(i) = cpmole_(i)/MW_(i) !J/Kg/K
            end do
            cp_update_ = .TRUE.
        end if
    end subroutine species_cp_

    function get_species_molar_specific_heat()
        real, dimension(NC_) :: get_species_molar_specific_heat
        call species_cp_()
        get_species_molar_specific_heat = cpmole_
        return
    end function get_species_molar_specific_heat

    function get_species_mass_specific_heat()
        real, dimension(NC_) :: get_species_mass_specific_heat
        call species_cp_()
        get_species_mass_specific_heat = cpmass_
        return
    end function get_species_mass_specific_heat

    subroutine species_h_()
        integer :: i
        
        if ( h_update_ .EQV. .FALSE. ) then     
            do i=1,NC_
                if ( T_ .LT. 1000. ) then
                    hmole_(i) = thermo_(index_(i))%low(1)              &
                              + thermo_(index_(i))%low(2)*T_/2.        &
                              + thermo_(index_(i))%low(3)*(T_**2.)/3.  &
                              + thermo_(index_(i))%low(4)*(T_**3.)/4.  &
                              + thermo_(index_(i))%low(5)*(T_**4.)/5.  &
                              + thermo_(index_(i))%low(6)/T_
                else
                    hmole_(i) = thermo_(index_(i))%high(1)              &
                              + thermo_(index_(i))%high(2)*T_/2.        &
                              + thermo_(index_(i))%high(3)*(T_**2.)/3.  &
                              + thermo_(index_(i))%high(4)*(T_**3.)/4.  &
                              + thermo_(index_(i))%high(5)*(T_**4.)/5.  &
                              + thermo_(index_(i))%high(6)/T_
                end if
                
                hmole_(i) = hmole_(i)*8314.*T_  !J/Kmol
                hmass_(i) = hmole_(i)/MW_(i) !J/Kg
            end do
            h_update_ = .TRUE.
        end if
    end subroutine species_h_

    function get_species_molar_enthalpy()
        real, dimension(NC_) :: get_species_molar_enthalpy
        call species_h_()
        get_species_molar_enthalpy = hmole_
        return
    end function get_species_molar_enthalpy

    function get_species_mass_enthalpy()
        real, dimension(NC_) :: get_species_mass_enthalpy
        call species_h_()
        get_species_mass_enthalpy = hmass_
        return
    end function get_species_mass_enthalpy

    subroutine species_s_()
        integer :: i
        
        if ( s_update_ .EQV. .FALSE. ) then     
            do i=1,NC_
                if ( T_ .LT. 1000. ) then
                    smole_(i) = thermo_(index_(i))%low(1)*log(T_)     &
                              + thermo_(index_(i))%low(2)*T_          &
                              + thermo_(index_(i))%low(3)*(T_**2.)/2. &
                              + thermo_(index_(i))%low(4)*(T_**3.)/3. &
                              + thermo_(index_(i))%low(5)*(T_**4.)/4. &
                              + thermo_(index_(i))%low(7)
                else
                    smole_(i) = thermo_(index_(i))%high(1)*log(T_)     &
                              + thermo_(index_(i))%high(2)*T_          &
                              + thermo_(index_(i))%high(3)*(T_**2.)/2. &
                              + thermo_(index_(i))%high(4)*(T_**3.)/3. &
                              + thermo_(index_(i))%high(5)*(T_**4.)/4. &
                              + thermo_(index_(i))%high(7)
                end if
                
                smole_(i) = 8314.*(smole_(i) - log(P_*x_(i)/1.e05)) !J/Kmol/K
                smass_(i) = smole_(i)/MW_(i) !J/Kg/K
            end do
            s_update_ = .TRUE.
        end if
    end subroutine species_s_

    function get_species_molar_entropy()
        real, dimension(NC_) :: get_species_molar_entropy
        call species_s_()
        get_species_molar_entropy = smole_
        return
    end function get_species_molar_entropy

    function get_species_mass_entropy()
        real, dimension(NC_) :: get_species_mass_entropy
        call species_s_()
        get_species_mass_entropy = smass_
        return
    end function get_species_mass_entropy

    subroutine species_thermal_conductivity_() ![W/m/K]
        integer :: i

        real :: A       = 0.
        real :: B       = 0.
        real :: Zrot    = 0.
        real :: cvtrans = 0.
        real :: cvrot   = 0.
        real :: cvvib   = 0.
        real :: ftrans  = 0.
        real :: frot    = 0.
        real :: fvib    = 0.
        real :: R       = 8314 ![J/Kmol/K]
        real :: F_T     = 0.
        real :: F_298   = 0.

        call species_viscosity_()
        call binary_diffusion_()
        call density_()
        call species_cp_()

        if ( cond_update_ .EQV. .FALSE. ) then
            do i=1,NC_
                if (transport_(index_(i))%geometry .EQ. 0 ) then !single atom
                    cvtrans = 3.*R*0.5
                    cvrot   = 0.
                    cvvib   = 0.
                else if (transport_(index_(i))%geometry .EQ. 1 ) then !linear
                    cvtrans = 3.*R*0.5
                    cvrot   = R*0.5
                    cvvib   = cpmole_(i) - R - 5.*R*0.5
                else !non linear
                    cvtrans = 3.*R*0.5
                    cvrot   = 3.*R*0.5
                    cvvib   = cpmole_(i) - R - 3.*R
                end if

                A = (5./2.) - rho_*diff_(i,i)/mu_(i)

                F_T   = 1. + 0.5*sqrt((pi_**3.)*transport_(index_(i))%LJpotential/T_) &
                      + (0.25*(pi_**2.) + 2.)*(transport_(index_(i))%LJpotential/T_)  &
                      + sqrt((pi_*transport_(index_(i))%LJpotential/T_)**3.)
                F_298 = 1. + 0.5*sqrt((pi_**3.)*transport_(index_(i))%LJpotential/298.) &
                      + (0.25*(pi_**2.) + 2.)*(transport_(index_(i))%LJpotential/298.)  &
                      + sqrt((pi_*transport_(index_(i))%LJpotential/298.)**3.)
                 
                Zrot = transport_(index_(i))%collision*F_298/F_T

                B = Zrot + (2./pi_)*((5./3.)*(cvrot/R) + rho_*diff_(i,i)/mu_(i))
                
                ftrans = (5./2.)*(1. - 2.*cvrot*A/(pi_*cvtrans*B))
                frot   = (rho_*diff_(i,i)/mu_(i))*(1. + 2.*A/(pi_*B))
                fvib   = rho_*diff_(i,i)/mu_(i)

                cond_(i) = mu_(i)*(ftrans*cvtrans + frot*cvrot + fvib*cvvib)/MW_(i)
            end do
            cond_update_ = .TRUE.
        end if
    end subroutine species_thermal_conductivity_

    function get_species_thermal_conductivity()
        real, dimension(NC_) :: get_species_thermal_conductivity
        call species_thermal_conductivity_()
        get_species_thermal_conductivity = cond_
        return
    end function get_species_thermal_conductivity

    function get_mixture_thermal_conductivity() ![W/m/K]
        real    :: get_mixture_thermal_conductivity, A, B
        integer :: i
        if (cond_mix_update_ .EQV. .FALSE. ) then
            call species_thermal_conductivity_()
            A = 0.
            B = 0.
            do i=1,NC_
                A = A + x_(i)*cond_(i)
                B = B + x_(i)/cond_(i)
            end do
            cond_mix_ = 0.5*(A + 1./B) 
            get_mixture_thermal_conductivity = 0.5*(A + 1./B)
            cond_mix_update_ = .TRUE.
        else
            get_mixture_thermal_conductivity = cond_mix_
        end if
        return
    end function get_mixture_thermal_conductivity

    function get_mixture_viscosity()     ![Pa*s]
        real    :: mumix, somma, get_mixture_viscosity, phi
        integer :: k,j
        if (mu_mix_update_ .EQV. .FALSE. ) then
            call species_viscosity_()
            do k=1,NC_
                somma = 0.
                do j=1,NC_
                    phi = (1./sqrt(8.))*(1./sqrt(1. + MW_(k)/MW_(j)))
                    phi = phi*((1. + sqrt(mu_(k)/mu_(j))*((MW_(j)/MW_(k))**(1./4.)))**2.)
                    somma = somma + x_(j)*phi;
                end do
                mu_mix_ = mu_mix_ + x_(k)*mu_(k)/somma
            end do
            mu_mix_update_ = .TRUE.
        end if
        get_mixture_viscosity = mu_mix_
        return
    end function get_mixture_viscosity

    function get_mixture_diffusion()  ![m2/s]
        real, dimension(NC_) :: get_mixture_diffusion
        real                 :: A,B
        integer              :: k,j
        if (diff_mix_update_ .EQV. .FALSE. ) then 
            call binary_diffusion_()
            do k=1,NC_
                A = 0
                B = 0
                do j=1,NC_
                    if ( j .NE. k ) then
                        A = A + x_(j)*MW_(j);
                        B = B + x_(j)/diff_(j,k);
                    end if
                end do
                diff_mix_(k) = A/(MWmix_*B)
            end do
            diff_mix_update_ = .TRUE.
        end if
        get_mixture_diffusion = diff_mix_
        return
    end function get_mixture_diffusion

    function get_aritmetic_mean_gas_velocity()
        real, dimension(NC_) :: get_aritmetic_mean_gas_velocity
        integer              :: i
        if ( v_update_ .EQV. .FALSE. ) then
            do i=1,NC_
                v_(i) = sqrt(8*8314*T_/(pi_*MW_(i)))
            end do
            v_update_ = .TRUE.
        end if
        get_aritmetic_mean_gas_velocity = v_
        return
    end function get_aritmetic_mean_gas_velocity

    function get_mean_free_path()
        real, dimension(NC_) :: get_mean_free_path
        integer              :: i
        if ( l_update_ .EQV. .FALSE. ) then
            do i=1,NC_
                l_(i) = 1.38064852*1e-03*T_/(sqrt(2.)*p_*(transport_(index_(i))%LJdiameter**2.))
            end do
            l_update_ = .TRUE.
        end if
        get_mean_free_path = l_
        return
    end function get_mean_free_path

    function get_mixture_molar_specific_heat()
        real    :: get_mixture_molar_specific_heat
        integer :: i
        if ( cpmole_mix_update_ .EQV. .FALSE. ) then
            call species_cp_()
            cpmole_mix_ = 0.
            do i=1,NC_
                cpmole_mix_ = cpmole_mix_ + x_(i)*cpmole_(i);
            end do
            cpmole_mix_update_ = .TRUE.
        end if
        get_mixture_molar_specific_heat = cpmole_mix_
        return
    end function get_mixture_molar_specific_heat

    function get_mixture_mass_specific_heat()
        real    :: get_mixture_mass_specific_heat
        integer :: i
        if ( cpmass_mix_update_ .EQV. .FALSE. ) then
            call species_cp_()
            cpmass_mix_ = 0.
            do i=1,NC_
                cpmass_mix_ = cpmass_mix_ + y_(i)*cpmass_(i);
            end do
            cpmass_mix_update_ = .TRUE.
        end if
        get_mixture_mass_specific_heat = cpmass_mix_
        return
    end function get_mixture_mass_specific_heat

    function get_mixture_molar_enthalpy()
        real    :: get_mixture_molar_enthalpy
        integer :: i
        if ( hmole_mix_update_ .EQV. .FALSE. ) then
            call species_h_()
            hmole_mix_ = 0.
            do i=1,NC_
                hmole_mix_ = hmole_mix_ + x_(i)*hmole_(i);
            end do
            hmole_mix_update_ = .TRUE.
        end if
        get_mixture_molar_enthalpy = hmole_mix_
        return
    end function get_mixture_molar_enthalpy

    function get_mixture_mass_enthalpy()
        real    :: get_mixture_mass_enthalpy
        integer :: i
        if ( hmass_mix_update_ .EQV. .FALSE. ) then
            call species_h_()
            hmass_mix_ = 0.
            do i=1,NC_
                hmass_mix_ = hmass_mix_ + y_(i)*hmass_(i);
            end do
            hmass_mix_update_ = .TRUE.
        end if
        get_mixture_mass_enthalpy = hmass_mix_
        return
    end function get_mixture_mass_enthalpy

    function get_mixture_molar_entropy()
        real    :: get_mixture_molar_entropy
        integer :: i
        if ( smole_mix_update_ .EQV. .FALSE. ) then
            call species_s_()
            smole_mix_ = 0.
            do i=1,NC_
                smole_mix_ = smole_mix_ + x_(i)*smole_(i)
            end do
            smole_mix_update_ = .TRUE.
        end if
        get_mixture_molar_entropy = smole_mix_
        return
    end function get_mixture_molar_entropy

    function get_mixture_mass_entropy()
        real    :: get_mixture_mass_entropy
        integer :: i
        if ( smole_mix_update_ .EQV. .FALSE. ) then
            call species_s_()
            smole_mix_ = 0.
            do i=1,NC_
                smole_mix_ = smole_mix_ + x_(i)*smole_(i)
            end do
            smole_mix_update_ = .TRUE.
        end if
        smass_mix_ = smole_mix_/MWmix_
        get_mixture_mass_entropy = smass_mix_
        return
    end function get_mixture_mass_entropy

    subroutine resize(NC)
        integer, intent(in) :: NC
        
        allocate(name_(NC))
        allocate(index_(NC))
        allocate(MW_(NC))
        allocate(x_(NC))
        allocate(y_(NC))
        allocate(mu_(NC))
        allocate(cond_(NC_))
        allocate(diff_(NC_,NC_))
        allocate(cpmole_(NC_))
        allocate(cpmass_(NC_))
        allocate(hmole_(NC_))
        allocate(hmass_(NC_))
        allocate(smole_(NC_))
        allocate(smass_(NC_))
        allocate(diff_mix_(NC_))
        allocate(v_(NC_))
        allocate(l_(NC_))
    end subroutine resize

    function collision_integrals_22(Tr,dr) result(sigma)
        real, intent(in)  :: Tr, dr
        real              :: sigma
        
        real, dimension(4) :: b, x
        real, dimension(4,4) :: A

        integer :: Ta, Tb, da, db, ok, pivot(4), j

        Ta = -1;
        Tb = -1;

        do j=1,size(Tsigma22_)-1
            if ( Tr .GE. Tsigma22_(j) .AND. Tr .LT. Tsigma22_(j+1) ) then
                Ta = j
                Tb = j + 1
                exit
            end if
        end do

        if ( Ta .EQ. -1 ) then
            if ( Tr .LE. Tsigma22_(1) ) then
                Ta = 1
                Tb = 2
            else if ( Tr .GE. Tsigma22_(size(Tsigma22_)) ) then
                Ta = size(Tsigma22_) - 1
                Tb = size(Tsigma22_)
            end if
        end if

        da = -1;
        db = -1;

        do j=1,size(dsigma22_) - 1
            if ( dr .GE. dsigma22_(j) .AND. dr .LT. dsigma22_(j+1) ) then
                da = j
                db = j + 1
                exit
            end if
        end do

        if ( da .EQ. -1 ) then
            if ( dr .LE. dsigma22_(1) ) then
                da = 1
                db = 2
            else if ( dr .GE. dsigma22_(size(dsigma22_)) ) then
                da = size(dsigma22_) - 1
                db = size(dsigma22_)
            end if
        end if

        A(1,:) = (/1.,Tsigma22_(Ta),dsigma22_(da),Tsigma22_(Ta)*dsigma22_(da)/)
        A(2,:) = (/1.,Tsigma22_(Ta),dsigma22_(db),Tsigma22_(Ta)*dsigma22_(db)/)
        A(3,:) = (/1.,Tsigma22_(Tb),dsigma22_(da),Tsigma22_(Tb)*dsigma22_(da)/)
        A(4,:) = (/1.,Tsigma22_(Tb),dsigma22_(db),Tsigma22_(Tb)*dsigma22_(db)/)

        b(1) = sigmaMatrix22_(Ta,da)
        b(2) = sigmaMatrix22_(Ta,db)
        b(3) = sigmaMatrix22_(Tb,da)
        b(4) = sigmaMatrix22_(Tb,db)

        x(4) = (b(1) - b(2)- b(3) + b(4))/(Tsigma22_(Ta)*dsigma22_(da) &
               - Tsigma22_(Ta)*dsigma22_(db)                           &
               - Tsigma22_(Tb)*dsigma22_(da)                           &
               + Tsigma22_(Tb)*dsigma22_(db))
               
        x(3) = (-x(4)*(Tsigma22_(Ta)*dsigma22_(da)                     &
                     - Tsigma22_(Ta)*dsigma22_(db))                    &
                     - b(2) + b(1))/(dsigma22_(da) - dsigma22_(db))

        x(2) = (-x(4)*(Tsigma22_(Ta)*dsigma22_(da)                     &
                     - Tsigma22_(Tb)*dsigma22_(da))                    &
                     - b(3) + b(1))/(Tsigma22_(Ta) - Tsigma22_(Tb))
                     
        x(1) = -x(2)*Tsigma22_(Ta)                                     &
               -x(3)*dsigma22_(da)                                     &
               -x(4)*Tsigma22_(Ta)*dsigma22_(da) + b(1)

        sigma = x(1) + x(2)*Tr + x(3)*dr + x(4)*Tr*dr

    end function collision_integrals_22

    function collision_integrals_11(Tr,dr) result(sigma)
        real, intent(in)  :: Tr, dr
        real              :: sigma
        
        real, dimension(4) :: b, x
        real, dimension(4,4) :: A

        integer :: Ta, Tb, da, db, ok, pivot(4), j

        Ta = -1;
        Tb = -1;

        do j=1,size(Tsigma11_)-1
            if ( Tr .GE. Tsigma11_(j) .AND. Tr .LT. Tsigma11_(j+1) ) then
                Ta = j
                Tb = j + 1
                exit
            end if
        end do

        if ( Ta .EQ. -1 ) then
            if ( Tr .LE. Tsigma11_(1) ) then
                Ta = 1
                Tb = 2
            else if ( Tr .GE. Tsigma11_(size(Tsigma11_)) ) then
                Ta = size(Tsigma11_) - 1
                Tb = size(Tsigma11_)
            end if
        end if

        da = -1;
        db = -1;

        do j=1,size(dsigma11_) - 1
            if ( dr .GE. dsigma11_(j) .AND. dr .LT. dsigma11_(j+1) ) then
                da = j
                db = j + 1
                exit
            end if
        end do

        if ( da .EQ. -1 ) then
            if ( dr .LE. dsigma11_(1) ) then
                da = 1
                db = 2
            else if ( dr .GE. dsigma11_(size(dsigma11_)) ) then
                da = size(dsigma11_) - 1
                db = size(dsigma11_)
            end if
        end if

        A(1,:) = (/1.,Tsigma11_(Ta),dsigma11_(da),Tsigma11_(Ta)*dsigma11_(da)/)
        A(2,:) = (/1.,Tsigma11_(Ta),dsigma11_(db),Tsigma11_(Ta)*dsigma11_(db)/)
        A(3,:) = (/1.,Tsigma11_(Tb),dsigma11_(da),Tsigma11_(Tb)*dsigma11_(da)/)
        A(4,:) = (/1.,Tsigma11_(Tb),dsigma11_(db),Tsigma11_(Tb)*dsigma11_(db)/)

        b(1) = sigmaMatrix11_(Ta,da)
        b(2) = sigmaMatrix11_(Ta,db)
        b(3) = sigmaMatrix11_(Tb,da)
        b(4) = sigmaMatrix11_(Tb,db)

        x(4) = (b(1) - b(2)- b(3) + b(4))/(Tsigma11_(Ta)*dsigma11_(da) &
               - Tsigma11_(Ta)*dsigma11_(db)                           &
               - Tsigma11_(Tb)*dsigma11_(da)                           &
               + Tsigma11_(Tb)*dsigma11_(db))
               
        x(3) = (-x(4)*(Tsigma11_(Ta)*dsigma11_(da)                     &
                     - Tsigma11_(Ta)*dsigma11_(db))                    &
                     - b(2) + b(1))/(dsigma11_(da) - dsigma11_(db))

        x(2) = (-x(4)*(Tsigma11_(Ta)*dsigma11_(da)                     &
                     - Tsigma11_(Tb)*dsigma11_(da))                    &
                     - b(3) + b(1))/(Tsigma11_(Ta) - Tsigma11_(Tb))
                     
        x(1) = -x(2)*Tsigma11_(Ta)                                     &
               -x(3)*dsigma11_(da)                                     &
               -x(4)*Tsigma11_(Ta)*dsigma11_(da) + b(1)

        sigma = x(1) + x(2)*Tr + x(3)*dr + x(4)*Tr*dr

    end function collision_integrals_11
end module asali
