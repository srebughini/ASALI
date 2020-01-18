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

program database_generator
    implicit none
    integer             :: NC, ios, nl
    integer             :: i, j, k, dummy_i
    integer, parameter  :: read_unit = 14
    character(len=200)  :: dummy_c
    character(len=200)  :: nome_fmt, geometry_fmt, LJpotential_fmt, LJdiameter_fmt, dipole_fmt
    character(len=200)  :: polar_fmt, collision_fmt, MW_fmt, high_fmt, low_fmt

    character(len=200), allocatable :: names(:), names_in_thermo(:)
    integer,            allocatable :: geometry(:)
    real,               allocatable :: LJpotential(:), LJdiameter(:), dipole(:), polar(:), collision(:), MW(:)
    real,               allocatable :: highA(:), highB(:), highC(:), highD(:), highE(:), highF(:), highG(:)
    real,               allocatable :: lowA(:), lowB(:), lowC(:), lowD(:), lowE(:), lowF(:), lowG(:)
    real,               allocatable :: Tsigma22(:), sigmaMatrix22(:,:), Tsigma11(:), sigmaMatrix11(:,:)
    real                            :: dsigma22(8) , dsigma11(8)

    ! READ transport.asali
    NC = get_number_of_lines_in_file('../database/transport.asali')

    allocate(names(NC))
    allocate(geometry(NC))
    allocate(LJpotential(NC))
    allocate(LJdiameter(NC))
    allocate(dipole(NC))
    allocate(polar(NC))
    allocate(collision(NC))
    allocate(MW(NC))

    open(unit=read_unit, file='../database/transport.asali', iostat=ios, action='read')
    do i = 1, NC
        read(read_unit, *) names(i), geometry(i), LJpotential(i), LJdiameter(i), dipole(i), polar(i), collision(i), MW(i)
    end do

    close(unit=read_unit)
    
    !WRITE transport_subroutine.f90
    open(unit=read_unit, file='transport_subroutine.f90', iostat=ios, action='write')
    
    write(read_unit,'(A)') '!################################################################################################'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#     #############       #############       #############       ####                ####     #'
    write(read_unit,'(A)') '!#    #             #     #             #     #             #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #####    #     #    #              #    #####    #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #             #     #    #########      #             #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #             #     #             #     #             #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #'
    write(read_unit,'(A)') '!#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #'
    write(read_unit,'(A)') '!#     ####     ####       #############       ####     ####       #############       ####     #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!################################################################################################'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   License                                                                                    #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   This file is part of ASALI.                                                                #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   ASALI is free software: you can redistribute it and/or modify                              #'
    write(read_unit,'(A)') '!#   it under the terms of the GNU General Public License as published by                       #'
    write(read_unit,'(A)') '!#   the Free Software Foundation, either version 3 of the License, or                          #'
    write(read_unit,'(A)') '!#   (at your option) any later version.                                                        #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   ASALI is distributed in the hope that it will be useful,                                   #'
    write(read_unit,'(A)') '!#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #'
    write(read_unit,'(A)') '!#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #'
    write(read_unit,'(A)') '!#   GNU General Public License for more details.                                               #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   You should have received a copy of the GNU General Public License                          #'
    write(read_unit,'(A)') '!#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!################################################################################################'
    write(read_unit,'(A1)') ' '
    write(read_unit,'(A)') 'subroutine transport_update()'

    do i = 1,NC
        if (len(trim(names(i))) .LT. 10) then 
            write(dummy_c,'(I1)') len(trim(names(i)))
        else if ( len(trim(names(i))) .GE. 10 .AND.  len(trim(names(i))) .LT. 100) then
            write(dummy_c,'(I2)') len(trim(names(i)))
        end if

        if (i .LT. 10) then
            nome_fmt        = '(A11,I1,A8,A'
            geometry_fmt    = '(A11,I1,A11,I1)'
            LJpotential_fmt = '(A11,I1,A14,F7.3)'
            LJdiameter_fmt  = '(A11,I1,A13,F7.3)'
            dipole_fmt      = '(A11,I1,A9,F7.3)'
            polar_fmt       = '(A11,I1,A8,F7.3)'
            collision_fmt   = '(A11,I1,A12,F7.3)'
            MW_fmt          = '(A11,I1,A5,F7.3)'
        else if ( i .GE. 10 .AND.  i .LT. 100) then
            nome_fmt        = '(A11,I2,A8,A'
            geometry_fmt    = '(A11,I2,A11,I1)'
            LJpotential_fmt = '(A11,I2,A14,F7.3)'
            LJdiameter_fmt  = '(A11,I2,A13,F7.3)'
            dipole_fmt      = '(A11,I2,A9,F7.3)'
            polar_fmt       = '(A11,I2,A8,F7.3)'
            collision_fmt   = '(A11,I2,A12,F7.3)'
            MW_fmt          = '(A11,I2,A5,F7.3)'
        else if ( i .GE. 100 .AND.  i .LT. 1000) then
            nome_fmt        = '(A11,I3,A8,A'
            geometry_fmt    = '(A11,I3,A11,I1)'
            LJpotential_fmt = '(A11,I3,A14,F7.3)'
            LJdiameter_fmt  = '(A11,I3,A13,F7.3)'
            dipole_fmt      = '(A11,I3,A9,F7.3)'
            polar_fmt       = '(A11,I3,A8,F7.3)'
            collision_fmt   = '(A11,I3,A12,F7.3)'
            MW_fmt          = '(A11,I3,A5,F7.3)'
        else if ( i .GE. 100 .AND.  i .LT. 10000) then
            nome_fmt        = '(A11,I4,A8,A'
            geometry_fmt    = '(A11,I4,A11,I1)'
            LJpotential_fmt = '(A11,I4,A14,F7.3)'
            LJdiameter_fmt  = '(A11,I4,A13,F7.3)'
            dipole_fmt      = '(A11,I4,A9,F7.3)'
            polar_fmt       = '(A11,I4,A8,F7.3)'
            collision_fmt   = '(A11,I4,A12,F7.3)'
            MW_fmt          = '(A11,I4,A5,F7.3)'
        else if ( i .GE. 1000 .AND.  i .LT. 100000) then
            nome_fmt        = '(A11,I5,A8,A'
            geometry_fmt    = '(A11,I5,A11,I1)'
            LJpotential_fmt = '(A11,I5,A14,F7.3)'
            LJdiameter_fmt  = '(A11,I5,A13,F7.3)'
            dipole_fmt      = '(A11,I5,A9,F7.3)'
            polar_fmt       = '(A11,I5,A8,F7.3)'
            collision_fmt   = '(A11,I5,A12,F7.3)'
            MW_fmt          = '(A11,I5,A5,F7.3)'
        end if

        nome_fmt = trim(nome_fmt)//trim(dummy_c)
        nome_fmt = trim(nome_fmt)//',A1)'

        write(read_unit,'(A1)') ' '
        write(read_unit,trim(nome_fmt)) 'transport_(',i,')%nome=''',trim(names(i)),''''
        write(read_unit,trim(geometry_fmt)) 'transport_(',i,')%geometry=',geometry(i)
        write(read_unit,trim(LJpotential_fmt)) 'transport_(',i,')%LJpotential=',LJpotential(i)
        write(read_unit,trim(LJdiameter_fmt)) 'transport_(',i,')%LJdiameter=',LJdiameter(i)
        write(read_unit,trim(dipole_fmt)) 'transport_(',i,')%dipole=',dipole(i)
        write(read_unit,trim(polar_fmt)) 'transport_(',i,')%polar=',polar(i)
        write(read_unit,trim(collision_fmt)) 'transport_(',i,')%collision=',collision(i)
        write(read_unit,trim(MW_fmt)) 'transport_(',i,')%MW=',MW(i)
        
    end do
    
    write(read_unit,'(A)') 'end subroutine transport_update'
    close(unit=read_unit)


    ! READ thermo.asali
    nl = get_number_of_lines_in_file('../database/thermo.asali')

    allocate(names_in_thermo(nl/4))
    allocate(highA(nl/4))
    allocate(highB(nl/4))
    allocate(highC(nl/4))
    allocate(highD(nl/4))
    allocate(highE(nl/4))
    allocate(highF(nl/4))
    allocate(highG(nl/4))
    allocate(lowA(nl/4))
    allocate(lowB(nl/4))
    allocate(lowC(nl/4))
    allocate(lowD(nl/4))
    allocate(lowE(nl/4))
    allocate(lowF(nl/4))
    allocate(lowG(nl/4))
    
    open(unit=read_unit, file='../database/thermo.asali', iostat=ios, action='read')

    k = 1
    do i = 1,nl,4
        read(read_unit, *) names_in_thermo(k)
        read(read_unit, *) highA(k), highB(k), highC(k), highD(k), highE(k)
        read(read_unit, *) highF(k), highG(k), lowA(k), lowB(k), lowC(k)
        read(read_unit, *) lowD(k), lowE(k), lowF(k), lowG(k)
        k = k + 1
    end do
    
    close(unit=read_unit)

    !WRITE thermo_subroutine.f90
    open(unit=read_unit, file='thermo_subroutine.f90', iostat=ios, action='write')
    
    write(read_unit,'(A)') '!################################################################################################'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#     #############       #############       #############       ####                ####     #'
    write(read_unit,'(A)') '!#    #             #     #             #     #             #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #####    #     #    #              #    #####    #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #             #     #    #########      #             #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #             #     #             #     #             #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #'
    write(read_unit,'(A)') '!#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #'
    write(read_unit,'(A)') '!#     ####     ####       #############       ####     ####       #############       ####     #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!################################################################################################'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   License                                                                                    #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   This file is part of ASALI.                                                                #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   ASALI is free software: you can redistribute it and/or modify                              #'
    write(read_unit,'(A)') '!#   it under the terms of the GNU General Public License as published by                       #'
    write(read_unit,'(A)') '!#   the Free Software Foundation, either version 3 of the License, or                          #'
    write(read_unit,'(A)') '!#   (at your option) any later version.                                                        #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   ASALI is distributed in the hope that it will be useful,                                   #'
    write(read_unit,'(A)') '!#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #'
    write(read_unit,'(A)') '!#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #'
    write(read_unit,'(A)') '!#   GNU General Public License for more details.                                               #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   You should have received a copy of the GNU General Public License                          #'
    write(read_unit,'(A)') '!#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!################################################################################################'
    write(read_unit,'(A1)') ' '
    write(read_unit,'(A)') 'subroutine thermo_update()'

    do j = 1,NC
        do i = 1,NC
            if ( trim(names_in_thermo(i)) .EQ. trim(names(j)) ) then 
                if (len(trim(names_in_thermo(i))) .LT. 10) then 
                    write(dummy_c,'(I1)') len(trim(names_in_thermo(i)))
                else if ( len(trim(names_in_thermo(i))) .GE. 10 .AND.  len(trim(names_in_thermo(i))) .LT. 100) then
                    write(dummy_c,'(I2)') len(trim(names_in_thermo(i)))
                end if

                if (j .LT. 10) then
                    nome_fmt = '(A8,I1,A8,A'
                    high_fmt = '(A8,I1,A10,ES15.8)'
                    low_fmt  = '(A8,I1,A9,ES15.8)'
                else if ( j .GE. 10 .AND.  j .LT. 100) then
                    nome_fmt = '(A8,I2,A8,A'
                    high_fmt = '(A8,I2,A10,ES15.8)'
                    low_fmt  = '(A8,I2,A9,ES15.8)'
                else if ( j .GE. 100 .AND.  j .LT. 1000) then
                    nome_fmt = '(A8,I3,A8,A'
                    high_fmt = '(A8,I3,A10,ES15.8)'
                    low_fmt  = '(A8,I3,A9,ES15.8)'
                else if ( j .GE. 100 .AND.  j .LT. 10000) then
                    nome_fmt = '(A8,I4,A8,A'
                    high_fmt = '(A8,I4,A10,ES15.8)'
                    low_fmt  = '(A8,I4,A9,ES15.8)'
                else if ( j .GE. 1000 .AND.  j .LT. 100000) then
                    nome_fmt = '(A8,I5,A8,A'
                    high_fmt = '(A8,I5,A10,ES15.8)'
                    low_fmt  = '(A8,I5,A9,ES15.8)'
                end if

                nome_fmt = trim(nome_fmt)//trim(dummy_c)
                nome_fmt = trim(nome_fmt)//',A1)'

                write(read_unit,'(A1)') ' '
                write(read_unit,trim(nome_fmt)) 'thermo_(',j,')%nome=''',trim(names_in_thermo(i)),''''
                write(read_unit,trim(high_fmt)) 'thermo_(',j,')%high(1)=',highA(i)
                write(read_unit,trim(high_fmt)) 'thermo_(',j,')%high(2)=',highB(i)
                write(read_unit,trim(high_fmt)) 'thermo_(',j,')%high(3)=',highC(i)
                write(read_unit,trim(high_fmt)) 'thermo_(',j,')%high(4)=',highD(i)
                write(read_unit,trim(high_fmt)) 'thermo_(',j,')%high(5)=',highE(i)
                write(read_unit,trim(high_fmt)) 'thermo_(',j,')%high(6)=',highF(i)
                write(read_unit,trim(high_fmt)) 'thermo_(',j,')%high(7)=',highG(i)
                write(read_unit,trim(low_fmt))  'thermo_(',j,')%low(1)=',lowA(i)
                write(read_unit,trim(low_fmt))  'thermo_(',j,')%low(2)=',lowB(i)
                write(read_unit,trim(low_fmt))  'thermo_(',j,')%low(3)=',lowC(i)
                write(read_unit,trim(low_fmt))  'thermo_(',j,')%low(4)=',lowD(i)
                write(read_unit,trim(low_fmt))  'thermo_(',j,')%low(5)=',lowE(i)
                write(read_unit,trim(low_fmt))  'thermo_(',j,')%low(6)=',lowF(i)
                write(read_unit,trim(low_fmt))  'thermo_(',j,')%low(7)=',lowG(i)
                exit
            end if
        end do
    end do
    
    write(read_unit,'(A)') 'end subroutine thermo_update'
    close(unit=read_unit)

    !READ omega22.asali
    nl = get_number_of_lines_in_file('../database/omega22.asali')
    allocate(Tsigma22(nl))
    allocate(sigmaMatrix22(nl-1,8))
    
    
    open(unit=read_unit, file='../database/omega22.asali', iostat=ios, action='read')
    read(read_unit, *) dummy_c, dsigma22(1), dsigma22(2), dsigma22(3), dsigma22(4), dsigma22(5), &
                                dsigma22(6), dsigma22(7), dsigma22(8)
    
    do i = 2,nl
        read(read_unit, *) Tsigma22(i), sigmaMatrix22(i-1,1), sigmaMatrix22(i-1,2), sigmaMatrix22(i-1,3), & 
                                        sigmaMatrix22(i-1,4), sigmaMatrix22(i-1,5), sigmaMatrix22(i-1,6), &
                                        sigmaMatrix22(i-1,7), sigmaMatrix22(i-1,8)
    end do

    close(unit=read_unit)

    !READ astar.asali
    nl = get_number_of_lines_in_file('../database/astar.asali')
    allocate(Tsigma11(nl))
    allocate(sigmaMatrix11(nl-1,8))
    
    open(unit=read_unit, file='../database/astar.asali', iostat=ios, action='read')
    read(read_unit, *) dummy_c, dsigma11(1), dsigma11(2), dsigma11(3), dsigma11(4), dsigma11(5), &
                                dsigma11(6), dsigma11(7), dsigma11(8)
    
    do i = 2,nl
        read(read_unit, *) Tsigma11(i), sigmaMatrix11(i-1,1), sigmaMatrix11(i-1,2), sigmaMatrix11(i-1,3), & 
                                        sigmaMatrix11(i-1,4), sigmaMatrix11(i-1,5), sigmaMatrix11(i-1,6), &
                                        sigmaMatrix11(i-1,7), sigmaMatrix11(i-1,8)
    end do

    close(unit=read_unit)

    !WRITE omega_subroutine.f90
    open(unit=read_unit, file='omega_subroutine.f90', iostat=ios, action='write')
    
    write(read_unit,'(A)') '!################################################################################################'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#     #############       #############       #############       ####                ####     #'
    write(read_unit,'(A)') '!#    #             #     #             #     #             #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #####    #     #    #              #    #####    #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #             #     #    #########      #             #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #             #     #             #     #             #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #'
    write(read_unit,'(A)') '!#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #'
    write(read_unit,'(A)') '!#     ####     ####       #############       ####     ####       #############       ####     #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!################################################################################################'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   License                                                                                    #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   This file is part of ASALI.                                                                #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   ASALI is free software: you can redistribute it and/or modify                              #'
    write(read_unit,'(A)') '!#   it under the terms of the GNU General Public License as published by                       #'
    write(read_unit,'(A)') '!#   the Free Software Foundation, either version 3 of the License, or                          #'
    write(read_unit,'(A)') '!#   (at your option) any later version.                                                        #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   ASALI is distributed in the hope that it will be useful,                                   #'
    write(read_unit,'(A)') '!#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #'
    write(read_unit,'(A)') '!#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #'
    write(read_unit,'(A)') '!#   GNU General Public License for more details.                                               #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   You should have received a copy of the GNU General Public License                          #'
    write(read_unit,'(A)') '!#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!################################################################################################'
    write(read_unit,'(A1)') ' '
    write(read_unit,'(A)') 'subroutine omega_update()'

    write(read_unit,'(A1)') ' '
    do i = 1,size(dsigma22)
        write(read_unit,'(A10,I1,A2,F4.2)') 'dsigma22_(',i,')=',dsigma22(i)
    end do
    
    write(read_unit,'(A1)') ' '
    do i = 2,size(Tsigma22)
        if (i-1 .LT. 10) then
            write(read_unit,'(A10,I1,A2,F6.2)') 'Tsigma22_(',i-1,')=',Tsigma22(i)
        else if ( i-1 .GE. 10 .AND.  i-1 .LT. 100) then
            write(read_unit,'(A10,I2,A2,F6.2)') 'Tsigma22_(',i-1,')=',Tsigma22(i)
        else
            write(read_unit,*) 'Tsigma22_(',i,')=',Tsigma22(i)
        end if
    end do
    
    write(read_unit,'(A1)') ' '
    do i = 1,size(sigmaMatrix22,1)
        if (i .LT. 10) then
            do j = 1,8
                write(read_unit,'(A15,I1,A1,I1,A2,F8.4)') 'sigmaMatrix22_(',i,',',j,')=',sigmaMatrix22(i,j)
            end do
        else if ( i .GE. 10 .AND.  i .LT. 100) then
            do j = 1,8
                write(read_unit,'(A15,I2,A1,I1,A2,F8.4)') 'sigmaMatrix22_(',i,',',j,')=',sigmaMatrix22(i,j)
            end do
        else
            write(read_unit,*) 'sigmaMatrix22_(',i,',',j,')=',sigmaMatrix22(i,j)
        end if
    end do

    write(read_unit,'(A1)') ' '
    do i = 1,size(dsigma11)
        write(read_unit,'(A10,I1,A2,F4.2)') 'dsigma11_(',i,')=',dsigma11(i)
    end do

    write(read_unit,'(A1)') ' '
    do i = 2,size(Tsigma11)
        if (i-1 .LT. 10) then
            write(read_unit,'(A10,I1,A2,F6.2)') 'Tsigma11_(',i-1,')=',Tsigma11(i)
        else if ( i-1 .GE. 10 .AND.  i-1 .LT. 100) then
            write(read_unit,'(A10,I2,A2,F6.2)') 'Tsigma11_(',i-1,')=',Tsigma11(i)
        else
            write(read_unit,*) 'Tsigma11_(',i,')=',Tsigma11(i)
        end if
    end do

    write(read_unit,'(A1)') ' '
    do i = 1,size(sigmaMatrix11,1)
        if (i .LT. 10) then
            do j = 1,8
                write(read_unit,'(A15,I1,A1,I1,A2,F8.4)') 'sigmaMatrix11_(',i,',',j,')=',sigmaMatrix22(i,j)/sigmaMatrix11(i,j)
            end do
        else if ( i .GE. 10 .AND.  i .LT. 100) then
            do j = 1,8
                write(read_unit,'(A15,I2,A1,I1,A2,F8.4)') 'sigmaMatrix11_(',i,',',j,')=',sigmaMatrix22(i,j)/sigmaMatrix11(i,j)
            end do
        else
            write(read_unit,*) 'sigmaMatrix11_(',i,',',j,')=',sigmaMatrix22(i,j)/sigmaMatrix11(i,j)
        end if
    end do


    write(read_unit,'(A1)') ' '
    write(read_unit,'(A)') 'end subroutine omega_update'
    close(unit=read_unit)


    !WRITE definitions.f90
    open(unit=read_unit, file='definitions.f90', iostat=ios, action='write')
    
    write(read_unit,'(A)') '!################################################################################################'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#     #############       #############       #############       ####                ####     #'
    write(read_unit,'(A)') '!#    #             #     #             #     #             #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #####    #     #    #              #    #####    #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #             #     #    #########      #             #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #             #     #             #     #             #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #'
    write(read_unit,'(A)') '!#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #'
    write(read_unit,'(A)') '!#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #'
    write(read_unit,'(A)') '!#     ####     ####       #############       ####     ####       #############       ####     #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!################################################################################################'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   License                                                                                    #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   This file is part of ASALI.                                                                #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   ASALI is free software: you can redistribute it and/or modify                              #'
    write(read_unit,'(A)') '!#   it under the terms of the GNU General Public License as published by                       #'
    write(read_unit,'(A)') '!#   the Free Software Foundation, either version 3 of the License, or                          #'
    write(read_unit,'(A)') '!#   (at your option) any later version.                                                        #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   ASALI is distributed in the hope that it will be useful,                                   #'
    write(read_unit,'(A)') '!#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #'
    write(read_unit,'(A)') '!#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #'
    write(read_unit,'(A)') '!#   GNU General Public License for more details.                                               #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!#   You should have received a copy of the GNU General Public License                          #'
    write(read_unit,'(A)') '!#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #'
    write(read_unit,'(A)') '!#                                                                                              #'
    write(read_unit,'(A)') '!################################################################################################'
    write(read_unit,'(A1)') ' '
    write(read_unit,'(A)') 'type :: transport'
    write(read_unit,'(A)') '    character(len=200) :: nome'
    write(read_unit,'(A)') '    real               :: geometry'
    write(read_unit,'(A)') '    real               :: LJpotential'
    write(read_unit,'(A)') '    real               :: LJdiameter'
    write(read_unit,'(A)') '    real               :: dipole'
    write(read_unit,'(A)') '    real               :: polar'
    write(read_unit,'(A)') '    real               :: collision'
    write(read_unit,'(A)') '    real               :: MW'
    write(read_unit,'(A)') 'end type'
    write(read_unit,'(A1)') ' '

    if (NC .LT. 10) then
        write(read_unit,'(A,I1,A)') 'type(transport) :: transport_(',NC,')'
    else if ( NC .GE. 10 .AND.  NC .LT. 100) then
        write(read_unit,'(A,I2,A)') 'type(transport) :: transport_(',NC,')'
    else if ( NC .GE. 100 .AND.  NC .LT. 1000) then
        write(read_unit,'(A,I3,A)') 'type(transport) :: transport_(',NC,')'
    else if ( NC .GE. 100 .AND.  NC .LT. 10000) then
        write(read_unit,'(A,I4,A)') 'type(transport) :: transport_(',NC,')'
    else if ( NC .GE. 1000 .AND.  NC .LT. 100000) then
        write(read_unit,'(A,I5,A)') 'type(transport) :: transport_(',NC,')'
    else
        write(read_unit,*) 'type(transport) :: transport_(',NC,')'
    end if

    write(read_unit,'(A1)') ' '
    write(read_unit,'(A)') 'type :: thermo'
    write(read_unit,'(A)') '    character(len=200) :: nome'
    write(read_unit,'(A)') '    real               :: high(7)'
    write(read_unit,'(A)') '    real               :: low(7)'
    write(read_unit,'(A)') 'end type'
    write(read_unit,'(A1)') ' '

    if (NC .LT. 10) then
        write(read_unit,'(A,I1,A)') 'type(thermo) :: thermo_(',NC,')'
    else if ( NC .GE. 10 .AND.  NC .LT. 100) then
        write(read_unit,'(A,I2,A)') 'type(thermo) :: thermo_(',NC,')'
    else if ( NC .GE. 100 .AND.  NC .LT. 1000) then
        write(read_unit,'(A,I3,A)') 'type(thermo) :: thermo_(',NC,')'
    else if ( NC .GE. 100 .AND.  NC .LT. 10000) then
        write(read_unit,'(A,I4,A)') 'type(thermo) :: thermo_(',NC,')'
    else if ( NC .GE. 1000 .AND.  NC .LT. 100000) then
        write(read_unit,'(A,I5,A)') 'type(thermo) :: thermo_(',NC,')'
    else
        write(read_unit,*) 'type(thermo) :: thermo_(',NC,')'
    end if
    
    
    write(read_unit,'(A1)') ' '
    write(read_unit,'(A,I1,A)') 'real :: dsigma22_(',size(dsigma22),')'

    if (size(Tsigma22) .LT. 10) then
        write(read_unit,'(A18,I1,A1)') 'real :: Tsigma22_(',size(Tsigma22)-1,')'
        write(read_unit,'(A,I1,A)') 'real :: sigmaMatrix22_(',size(Tsigma22)-1,',8)'
    else if ( size(Tsigma22) .GE. 10 .AND.  size(Tsigma22) .LT. 100) then
        write(read_unit,'(A18,I2,A1)') 'real :: Tsigma22_(',size(Tsigma22)-1,')'
        write(read_unit,'(A,I2,A)') 'real :: sigmaMatrix22_(',size(Tsigma22)-1,',8)'
    else if ( size(Tsigma22) .GE. 100 .AND.  size(Tsigma22) .LT. 1000) then
        write(read_unit,'(A18,I3,A1)') 'real :: Tsigma22_(',size(Tsigma22)-1,')'
        write(read_unit,'(A,I3,A)') 'real :: sigmaMatrix22_(',size(Tsigma22)-1,',8)'
    else if ( size(Tsigma22) .GE. 100 .AND.  size(Tsigma22) .LT. 10000) then
        write(read_unit,'(A18,I4,A1)') 'real :: Tsigma22_(',size(Tsigma22)-1,')'
        write(read_unit,'(A,I4,A)') 'real :: sigmaMatrix22_(',size(Tsigma22)-1,',8)'
    else if ( size(Tsigma22) .GE. 1000 .AND.  size(Tsigma22) .LT. 100000) then
        write(read_unit,'(A18,I5,A1)') 'real :: Tsigma22_(',size(Tsigma22)-1,')'
        write(read_unit,'(A,I5,A)') 'real :: sigmaMatrix22_(',size(Tsigma22)-1,',8)'
    else
        write(read_unit,*) 'real :: Tsigma22_(',size(Tsigma22)-1,')'
        write(read_unit,*) 'real :: sigmaMatrix22_(',size(Tsigma22)-1,',8)'
    end if

    write(read_unit,'(A1)') ' '
    write(read_unit,'(A,I1,A)') 'real :: dsigma11_(',size(dsigma11),')'

    if (size(Tsigma11) .LT. 10) then
        write(read_unit,'(A18,I1,A1)') 'real :: Tsigma11_(',size(Tsigma11)-1,')'
        write(read_unit,'(A,I1,A)') 'real :: sigmaMatrix11_(',size(Tsigma11)-1,',8)'
    else if ( size(Tsigma11) .GE. 10 .AND.  size(Tsigma11) .LT. 100) then
        write(read_unit,'(A18,I2,A1)') 'real :: Tsigma11_(',size(Tsigma11)-1,')'
        write(read_unit,'(A,I2,A)') 'real :: sigmaMatrix11_(',size(Tsigma11)-1,',8)'
    else if ( size(Tsigma11) .GE. 100 .AND.  size(Tsigma11) .LT. 1000) then
        write(read_unit,'(A18,I3,A1)') 'real :: Tsigma11_(',size(Tsigma11)-1,')'
        write(read_unit,'(A,I3,A)') 'real :: sigmaMatrix11_(',size(Tsigma11)-1,',8)'
    else if ( size(Tsigma11) .GE. 100 .AND.  size(Tsigma11) .LT. 10000) then
        write(read_unit,'(A18,I4,A1)') 'real :: Tsigma11_(',size(Tsigma11)-1,')'
        write(read_unit,'(A,I4,A)') 'real :: sigmaMatrix11_(',size(Tsigma11)-1,',8)'
    else if ( size(Tsigma11) .GE. 1000 .AND.  size(Tsigma11) .LT. 100000) then
        write(read_unit,'(A18,I5,A1)') 'real :: Tsigma11_(',size(Tsigma11)-1,')'
        write(read_unit,'(A,I5,A)') 'real :: sigmaMatrix11_(',size(Tsigma11)-1,',8)'
    else
        write(read_unit,*) 'real :: Tsigma11_(',size(Tsigma11)-1,')'
        write(read_unit,*) 'real :: sigmaMatrix11_(',size(Tsigma11)-1,',8)'
    end if
    close(unit=read_unit)


    contains
    integer function get_number_of_lines_in_file(path) result(n)
        character(len=*), intent(in) :: path
        integer                      :: ios
        integer, parameter           :: read_unit = 99
        character(len=200)           :: line

        open(unit=read_unit, file=path, iostat=ios, action='read')
        if ( ios /= 0 ) stop "Error opening file "
        n = 0
        do
            read(unit=read_unit, fmt='(A)', iostat=ios) line
            if (ios /= 0) exit
            n = n + 1
        end do
        close(unit=read_unit)
    end function get_number_of_lines_in_file

end program database_generator
