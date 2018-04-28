close all
clear all
clc

%Class generation
p = Asali('database.mat');

%Set up composition/pressure and temperature
p.Pressure     = 101325;
p.Temperature  = 500;
p.Names        = {'N2' 'O2'};
p.MoleFraction = [0.78 0.22];

%Get properties
p.SpecieViscosity
p.SpecieMolarSpecificHeat
p.SpecieMassSpecificHeat
p.BinaryDiffusion
p.SpecieThermalConductivity
p.SpecieMassEnthalpy
p.SpecieMolarEnthalpy
p.MixtureMolarSpecificHeat
p.MixtureMassSpecificHeat
p.MixtureThermalConductivity
p.MixtureDiffusion