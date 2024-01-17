close all
clear all
clc

args = argv();
N = floor(str2double(args{1}));

%Class generation
initialization_start = clock();
for i=1:(N-1)
    p = Asali('database.mat');
end
p = Asali('database.mat');
initialization_end = clock();

%Set up composition/pressure and temperature
estimation_start = clock();
for i=1:N
    p.Pressure     = 4e05;
    p.Temperature  = 393.15;
    p.Names        = {'H2' 'O2' 'C3H8' 'C2H6' 'CH4' 'CO2' 'HE' 'N2' 'NH3'};
    p.MoleFraction = [0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.2];

    mu = p.SpecieViscosity;
    diff = p.BinaryDiffusion;
    cp = p.SpeciesMassSpecificHeat;
    h = p.SpecieMassEnthalpy;
    s = p.SpecieMassEntropy;
    cond = p.SpecieThermalConductivity;
    diff_mix = p.MixtureDiffusion;
    v = p.MeanGasVelocity;
    l = p.MeanFreePath;
    MWmix = p.MixtureMolecularWeight;
    rho = p.Density;
    mumix = p.MixtureViscosity;
    cpmassmix = p.MixtureMassSpecificHeat;
    cpmolemix = p.MixtureMolarSpecificHeat;
    hmassmix = p.MixtureMassEnthalpy;
    hmolemix = p.MixtureMolarEnthalpy;
    condmix = p.MixtureThermalConductivity;
    smassmix = p.MixtureMassEntropy;
    smolemix = p.MixtureMolarEntropy;
end
estimation_end = clock();

disp('Octave version')
fprintf('Initialization (s):  %.3e\n',etime(initialization_end,initialization_start)/N)
fprintf('Calculation (s):     %.3e\n',etime(estimation_end,estimation_start)/N)

