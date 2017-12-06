function [r] = Asali(type,T,p,x,n)
% ASALI: Octave interface for ASALI (https://github.com/srebughini)
% R = Asali(TYPE,T,P,X,N) estimates the transport/thermo properties of
% ideal gas mixtures.
%
% TYPE: string representing transport/thermodynamic property to be
% estimated. Available properties: 
%     1/ diffusivity         [m2/s]
%     2/ viscosity           [Pas]
%     3/ molecularWeight     [g/mol]
%     4/ enthalpy            [J/kg]
%     5/ entropy             [J/kg/K]
%     6/ specificHeat        [J/kg/K]
%     7/ conductivity        [W/m/K]
%
% T: number describing the mixture temperature in K.
%
% P: number describing the mixture pressure in Pa.
%
% X: vector describing the MOLE fraction (e.g. X = [0.5 0.5]).
%
% N: cell array describing the species NAMES (e.g. N = {'O2' 'H2'}).
%
% R: vector of the estimated transport/thermodynamic property. The last
% element of the vector is the property of the gas mixture.
%
% Example:
% [mu] = Asali('viscosity',273.15,101325,[0.5 0.5],{'N2' 'O2'})

NC = length(x);

input = ["Asali.exe " type " " num2str(T) " " num2str(p) " " num2str(NC)];

for i=1:NC
    input = [input " " n{i}];
end

for i=1:NC
    input = [input " " num2str(x(i))];
end

[status,cmd] = system(input);

if isempty(strfind(cmd,','))
    r = cmd;
else
    if strcmpi(type,'diffusivity')
        NC = NC;
    else
        if NC > 1
            NC = NC + 1;
        end
    end

    rs = strsplit(cmd,',');

    r = zeros(NC,1);

    for i=1:NC
        r(i) = str2num(rs{i});
    end
end

end
