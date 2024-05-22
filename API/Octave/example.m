%################################################################################################
%#                                                                                              #
%#     #############       #############       #############       ####                ####     #
%#    #             #     #             #     #             #     #    #              #    #    #
%#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #
%#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #
%#    #    #####    #     #    #              #    #####    #     #    #              #    #    #
%#    #             #     #    #########      #             #     #    #              #    #    #
%#    #             #     #             #     #             #     #    #              #    #    #
%#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #
%#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #
%#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #
%#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #
%#     ####     ####       #############       ####     ####       #############       ####     #
%#                                                                                              #
%#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #
%#                                                                                              #
%################################################################################################
%#                                                                                              #
%#   License                                                                                    #
%#                                                                                              #
%#   This file is part of ASALI.                                                                #
%#                                                                                              #
%#   ASALI is free software: you can redistribute it and/or modify                              #
%#   it under the terms of the GNU General Public License as published by                       #
%#   the Free Software Foundation, either version 3 of the License, or                          #
%#   (at your option) any later version.                                                        #
%#                                                                                              #
%#   ASALI is distributed in the hope that it will be useful,                                   #
%#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #
%#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #
%#   GNU General Public License for more details.                                               #
%#                                                                                              #
%#   You should have received a copy of the GNU General Public License                          #
%#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #
%#                                                                                              #
%################################################################################################

close all
clear all
clc

%Class generation
p = Asali('database.mat');

%Set up composition/pressure and temperature
p.Pressure     = 4e05;
p.Temperature  = 393.15;
p.Names        = {'H2' 'O2' 'N2'};
p.MoleFraction = [0.1 0.2 0.7];

cp = p.SpeciesMassSpecificHeat;
h = p.SpecieMassEnthalpy;
s = p.SpecieMassEntropy;
mu = p.SpecieViscosity;
diff = p.BinaryDiffusion;
cond = p.SpecieThermalConductivity;
diff_mix = p.MixtureDiffusion;
v = p.MeanGasVelocity;
l = p.MeanFreePath;

disp(['Mixture molecular weight:     ',num2str(p.MixtureMolecularWeight),' [kg/kmol]'])
disp(['Density:                      ',num2str(p.Density),' [kg/m^3]'])
disp(['Mixture viscosity:            ',num2str(p.MixtureViscosity),' [Pas]'])
disp(['Mixture specific heat:        ',num2str(p.MixtureMassSpecificHeat),' [J/kg/K]'])
disp(['Mixture specific heat:        ',num2str(p.MixtureMolarSpecificHeat),' [J/kmol/K]'])
disp(['Mixture enthalpy:             ',num2str(p.MixtureMassEnthalpy),' [J/kg]'])
disp(['Mixture enthalpy:             ',num2str(p.MixtureMolarEnthalpy),' [J/kmol]'])
disp(['Mixture thermal conductivity: ',num2str(p.MixtureThermalConductivity),' [W/m/K]'])
disp(['Mixture entropy:              ',num2str(p.MixtureMassEntropy),' [J/kg/K]'])
disp(['Mixture entropy:              ',num2str(p.MixtureMolarEntropy),' [J/kmol/K]'])

disp(' ')
disp('Species viscosity [Pas]')
for i=1:3
    disp([p.Names{i},': ',num2str(mu(i))])
end

disp(' ')
disp('Species binary diffusion coefficient [m2/s]')
for i=1:3
    disp([p.Names{i},': ',num2str(diff(i,1)),',',num2str(diff(i,2)),',',num2str(diff(i,3))])
end

disp(' ')
disp('Species specific heat [J/kg/K]')
for i=1:3
    disp([p.Names{i},': ',num2str(cp(i))])
end

disp(' ')
disp('Species enthalpy [J/kg]')
for i=1:3
    disp([p.Names{i},': ',num2str(h(i))])
end

disp(' ')
disp('Species entropy [J/kg/K]')
for i=1:3
    disp([p.Names{i},': ',num2str(s(i))])
end

disp(' ')
disp('Species thermal conductivity [W/m/K]')
for i=1:3
    disp([p.Names{i},': ',num2str(cond(i))])
end

disp(' ')
disp('Mixture diffusion coefficient [m2/s]')
for i=1:3
    disp([p.Names{i},': ',num2str(diff_mix(i))])
end

disp(' ')
disp('Mean gas velocity [m/s]')
for i=1:3
    disp([p.Names{i},': ',num2str(v(i))])
end

disp(' ')
disp('Mean free path [m]')
for i=1:3
    disp([p.Names{i},': ',num2str(l(i))])
end