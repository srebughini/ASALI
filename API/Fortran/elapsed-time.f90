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

include "Asali.f90"

program example
    use asali
    implicit none

	real, dimension(9) :: x, mu, cp, h, s, cond, diffmix, v, l
	real, dimension(9,9) :: diff
	real :: rho, MWmix, condmix, mumix, cpmolemix, cpmassmix, &
			hmolemix, hmassmix, smolemix, smassmix, tStart, tEnd
	integer :: i, N
	character(len=200), dimension(9) :: names

	character(len=32) :: arg

	call getarg(1, arg)
	read (arg,'(I32)') N

    call cpu_time(tStart)

    do i=1,N
		names(1) = 'H2'
		names(2) = 'O2'
		names(3) = 'C3H8'
		names(4) = 'C2H6'
		names(5) = 'CH4'
		names(6) = 'CO2'
		names(7) = 'HE'
		names(8) = 'N2'
		names(9) = 'NH3'

		x(1) = 0.1
		x(2) = 0.1
		x(3) = 0.1
		x(4) = 0.1
		x(5) = 0.1
		x(6) = 0.1
		x(7) = 0.1
		x(8) = 0.1
		x(9) = 1.-x(1)-x(2)-x(3)-x(4)-x(5)-x(6)-x(7)-x(8)
		
		call set_temperature(393.15)
		
		call set_pressure(4e05)
		
		call set_number_of_species(9)
		
		call set_species_names(names)
		
		call set_mole_fraction(x)
		
		mu = get_species_viscosity()
		rho = get_density()
		MWmix = get_mixture_molecular_weight()
		condmix = get_mixture_thermal_conductivity()
		mumix = get_mixture_viscosity()
		diffmix = get_mixture_diffusion()
		cpmolemix = get_mixture_molar_specific_heat()
		cpmassmix = get_mixture_mass_specific_heat()
		hmolemix = get_mixture_molar_enthalpy()
		hmassmix = get_mixture_mass_enthalpy()
		smolemix = get_mixture_molar_entropy()
		smassmix = get_mixture_mass_entropy()
		diff = get_binary_diffusion()
		cp = get_species_mass_specific_heat()
		h  = get_species_mass_enthalpy()
		s  = get_species_mass_entropy()
		cond = get_species_thermal_conductivity()
		v = get_aritmetic_mean_gas_velocity()
		l = get_mean_free_path()
	end do
	
	call cpu_time(tEnd)
	
	print '(A15)' ,'Fortran version'
	print '(A21,A4)' ,'Initialization (s):  ', 'n.a.'
	print '(A21,ES9.3)' ,'Calculation (s):     ', (tEnd - tStart)/N

end program example
