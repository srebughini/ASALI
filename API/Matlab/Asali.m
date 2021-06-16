classdef Asali
    
    properties
        Pressure                   = [];
        Temperature                = [];
        Names                      = [];
        Density                    = [];
        MixtureMolecularWeight     = [];
        SpeciesMolarSpecificHeat   = [];
        SpeciesMassSpecificHeat    = [];
        SpecieMolarEnthalpy        = [];
        SpecieMassEnthalpy         = [];
        SpecieMolarEntropy         = [];
        SpecieMassEntropy          = [];
        SpecieViscosity            = [];
        BinaryDiffusion            = [];
        SpecieThermalConductivity  = [];
        MixtureMolarSpecificHeat   = [];
        MixtureMassSpecificHeat    = [];
        MixtureMolarEnthalpy       = [];
        MixtureMassEnthalpy        = [];
        MixtureMolarEntropy        = [];
        MixtureMassEntropy         = [];
        MixtureViscosity           = [];
        MixtureThermalConductivity = [];
        MixtureDiffusion           = [];
        MeanGasVelocity            = [];
        MeanFreePath               = [];
    end
    
    properties (Dependent)
        MoleFraction               = [];
        MassFraction               = [];
    end
    
    properties (Access = private)
        pi_                      = 3.14159265358979323846;
        R_                       = 8314.;
        index                    = [];
        MW                       = [];
        y                        = [];
        x                        = [];
        mu                       = [];
        MWmix                    = [];
        cpmole                   = [];
        cpmass                   = [];
        hmole                    = [];
        hmass                    = [];
        smole                    = [];
        smass                    = [];
        diff                     = [];
        cond                     = [];
        rho                      = []
        v                        = [];
        l                        = [];
        data                     = [];
        cpmole_mix               = [];
        cpmass_mix               = [];
        hmole_mix                = [];
        hmass_mix                = [];
        smole_mix                = [];
        smass_mix                = [];
        mu_mix                   = [];
        cond_mix                 = [];
        diff_mix                 = [];
        cp_updated_              = false;
        h_updated_               = false;
        s_updated_               = false;
        mu_updated_              = false;
        diff_updated_            = false;
        cond_updated_            = false;
        rho_updated_             = false;
        cpmole_mix_updated_      = false;
        cpmass_mix_updated_      = false;
        hmole_mix_updated_       = false;
        hmass_mix_updated_       = false;
        smole_mix_updated_       = false;
        smass_mix_updated_       = false;
        cond_mix_updated_        = false;
        diff_mix_updated_        = false;
        mu_mix_updated_          = false;
        v_updated_               = false;
        l_updated_               = false;
    end
    
    methods
        
        %Load data
        function obj = Asali(value)
            load(value);
            obj.data = database;
        end
        
        %SetNames
        function obj = set.Names(obj,value)
            obj.Names = value;
            for i=1:length(value)
                if ~ismember(value{i},obj.data.name)
                    error([value{i},' is not present in ASALI database'])
                else
                    obj.index(i) = find(strcmpi(value{i},obj.data.name));
                end
            end
            obj.cp_updated_         = false;
            obj.h_updated_          = false;
            obj.s_updated_          = false;
            obj.mu_updated_         = false;
            obj.diff_updated_       = false;
            obj.cond_updated_       = false;
            obj.rho_updated_        = false;
            obj.cpmole_mix_updated_ = false;
            obj.cpmass_mix_updated_ = false;
            obj.hmole_mix_updated_  = false;
            obj.hmass_mix_updated_  = false;
            obj.smole_mix_updated_  = false;
            obj.smass_mix_updated_  = false;
            obj.cond_mix_updated_   = false;
            obj.diff_mix_updated_   = false;
            obj.mu_mix_updated_     = false;
        end
        
        %Set mole fraction
        function obj = set.MoleFraction(obj,value)
            if ~isempty(value)
                if length(value) ~= length(obj.index)
                    error('Wrong number of species in MoleFraction')
                elseif sum(value) ~= 1
                    error('Sum of MoleFraction must be 1')
                else
                    obj.x     = value;
                    obj.MWmix = sum(value.*obj.MW);
                    obj.y     = value.*obj.MW/obj.MWmix;
                end
            end
            obj.cp_updated_         = false;
            obj.h_updated_          = false;
            obj.s_updated_          = false;
            obj.mu_updated_         = false;
            obj.diff_updated_       = false;
            obj.cond_updated_       = false;
            obj.rho_updated_        = false;
            obj.cpmole_mix_updated_ = false;
            obj.cpmass_mix_updated_ = false;
            obj.hmole_mix_updated_  = false;
            obj.hmass_mix_updated_  = false;
            obj.smole_mix_updated_  = false;
            obj.smass_mix_updated_  = false;
            obj.cond_mix_updated_   = false;
            obj.diff_mix_updated_   = false;
            obj.mu_mix_updated_     = false;
        end
        
        %Set mass fraction
        function obj = set.MassFraction(obj,value)
            if ~isempty(value)
                if length(value) ~= length(obj.index)
                    error('Wrong number of species in MassFraction')
                elseif sum(value) ~= 1
                    error('Sum of MassFraction must be 1')
                else
                    obj.y     = value;
                    obj.MWmix = 1/sum(value./obj.MW);
                    obj.x     = obj.MWmix*(value./obj.MW);
                end
            end
            obj.cp_updated_         = false;
            obj.h_updated_          = false;
            obj.s_updated_          = false;
            obj.mu_updated_         = false;
            obj.diff_updated_       = false;
            obj.cond_updated_       = false;
            obj.rho_updated_        = false;
            obj.cpmole_mix_updated_ = false;
            obj.cpmass_mix_updated_ = false;
            obj.hmole_mix_updated_  = false;
            obj.hmass_mix_updated_  = false;
            obj.smole_mix_updated_  = false;
            obj.smass_mix_updated_  = false;
            obj.cond_mix_updated_   = false;
            obj.diff_mix_updated_   = false;
            obj.mu_mix_updated_     = false;
        end
        
        %Set pressure
        function obj = set.Pressure(obj,value)
            obj.Pressure = value;
            obj.cp_updated_         = false;
            obj.h_updated_          = false;
            obj.s_updated_          = false;
            obj.mu_updated_         = false;
            obj.diff_updated_       = false;
            obj.cond_updated_       = false;
            obj.rho_updated_        = false;
            obj.cpmole_mix_updated_ = false;
            obj.cpmass_mix_updated_ = false;
            obj.hmole_mix_updated_  = false;
            obj.hmass_mix_updated_  = false;
            obj.smole_mix_updated_  = false;
            obj.smass_mix_updated_  = false;
            obj.cond_mix_updated_   = false;
            obj.diff_mix_updated_   = false;
            obj.mu_mix_updated_     = false;
        end
        
        %Set temperature
        function obj = set.Temperature(obj,value)
            obj.Temperature = value;
            obj.cp_updated_         = false;
            obj.h_updated_          = false;
            obj.s_updated_          = false;
            obj.mu_updated_         = false;
            obj.diff_updated_       = false;
            obj.cond_updated_       = false;
            obj.rho_updated_        = false;
            obj.cpmole_mix_updated_ = false;
            obj.cpmass_mix_updated_ = false;
            obj.hmole_mix_updated_  = false;
            obj.hmass_mix_updated_  = false;
            obj.smole_mix_updated_  = false;
            obj.smass_mix_updated_  = false;
            obj.cond_mix_updated_   = false;
            obj.diff_mix_updated_   = false;
            obj.mu_mix_updated_     = false;
        end
        
        %Molecular weigth  [g/mol]
        function MW = get.MW(obj)
            for i=1:length(obj.index)
                MW(i) = obj.data.transport(obj.index(i),7);
            end
        end
        
        %Get density [kg/m3]
        function rho = get.Density(obj)
            obj.rho = obj.density_(obj);
            rho = obj.rho;
        end
        
        %Get mole fraction
        function x = get.MoleFraction(obj)
            x = obj.x;
        end
        
        %Get mass fraction
        function y = get.MassFraction(obj)
            y = obj.y;
        end
        
        %Get mass fraction
        function MWmix = get.MixtureMolecularWeight(obj)
            MWmix = obj.MWmix;
        end
        
        %Get species molar specific heat [J/kmol/K]
        function cp = get.SpeciesMolarSpecificHeat(obj)
            [obj.cpmole, obj.cpmass] = obj.species_cp_(obj);
            cp = obj.cpmole;
        end
        
        %Get species molar specific heat [J/kg/K]
        function cp = get.SpeciesMassSpecificHeat(obj)
            [obj.cpmole, obj.cpmass] = obj.species_cp_(obj);
            cp = obj.cpmass;
        end
        
        %Get species molar enthalpy [J/kmol]
        function h = get.SpecieMolarEnthalpy(obj)
            [obj.hmole, obj.hmass] = obj.species_h_(obj);
            h = obj.hmole;
        end
        
        %Get species mass enthalpy [J/kg]
        function h = get.SpecieMassEnthalpy(obj)
            [obj.hmole, obj.hmass] = obj.species_h_(obj);
            h = obj.hmass;
        end
        
        %Get species molar entropy [J/kmol]
        function s = get.SpecieMolarEntropy(obj)
            [obj.smole, obj.smass] = obj.species_s_(obj);
            s = obj.smole;
        end
        
        %Get species mass entropy [J/kg/K]
        function s = get.SpecieMassEntropy(obj)
            [obj.smole, obj.smass] = obj.species_s_(obj);
            s = obj.smass;
        end
        
        %Get species viscosity [Pas]
        function mu = get.SpecieViscosity(obj)
            obj.mu = obj.species_viscosity_(obj);
            mu = obj.mu;
        end
        
        %Get binary diffusion [m2/s]
        function diff = get.BinaryDiffusion(obj)
            obj.diff = obj.binary_diffusion_(obj);
            diff = obj.diff;
        end
        
        %Get species thermal conductivity [W/m/K]
        function cond = get.SpecieThermalConductivity(obj)
            obj.cond = obj.species_cond_(obj);
            cond = obj.cond;
        end
        
        %Get specific heat [J/kmol/K]
        function cp = get.MixtureMolarSpecificHeat(obj)
            [obj.cpmole, obj.cpmass] = obj.species_cp_(obj);
            if ~obj.cpmole_mix_updated_
                X   = obj.x;
                cp  = 0;
                for i=1:length(X)
                    cp = cp + X(i)*obj.cpmole(i);
                end
                obj.cpmole_mix = cp;
                obj.cpmole_mix_updated_ = true;
            else
                cp = obj.cpmole_mix;
            end
        end
        
        %Get specific heat [J/kmol/K]
        function cp = get.MixtureMassSpecificHeat(obj)
            [obj.cpmole, obj.cpmass] = obj.species_cp_(obj);
            if ~obj.cpmass_mix_updated_
                Y   = obj.y;
                cp  = 0;
                for i=1:length(Y)
                    cp = cp + Y(i)*obj.cpmass(i);
                end
                obj.cpmass_mix = cp;
                obj.cpmass_mix_updated_ = true;
            else
                cp = obj.cpmass_mix;
            end
        end
        
        %Get enthalpy [J/kmol/K]
        function h = get.MixtureMolarEnthalpy(obj)
            [obj.hmole, obj.hmass] = obj.species_h_(obj);
            if ~obj.hmole_mix_updated_
                X   = obj.x;
                h  = 0;
                for i=1:length(X)
                    h = h + X(i)*obj.hmole(i);
                end
                obj.hmole_mix = h;
                obj.hmole_mix_updated_ = true;
            else
                h = obj.hmole_mix;
            end
        end
        
        %Get enthalpy [J/kmol/K]
        function h = get.MixtureMassEnthalpy(obj)
            [obj.hmole, obj.hmass] = obj.species_h_(obj);
            if ~obj.hmass_mix_updated_
                Y   = obj.y;
                h  = 0;
                for i=1:length(Y)
                    h = h + Y(i)*obj.hmass(i);
                end
                obj.hmass_mix = h;
                obj.hmass_mix_updated_ = true;
            else
                h = obj.hmass_mix;
            end
        end
        
        %Get entropy [J/kmol/K]
        function s = get.MixtureMolarEntropy(obj)
            [obj.smole, obj.smass] = obj.species_s_(obj);
            if ~obj.smole_mix_updated_
                X   = obj.x;
                s  = 0;
                for i=1:length(X)
                    s = s + X(i)*obj.smole(i);
                end
                obj.smole_mix = s;
                obj.smole_mix_updated_ = true;
            else
                s = obj.smole_mix;
            end
        end
        
        %Get entropy [J/kmol/K]
        function s = get.MixtureMassEntropy(obj)
            [obj.smole, obj.smass] = obj.species_s_(obj);
            if ~obj.smass_mix_updated_
                X   = obj.x;
                s  = 0;
                for i=1:length(X)
                    s = s + X(i)*obj.smole(i);
                end
                obj.smass_mix = s/obj.MWmix;
                obj.smass_mix_updated_ = true;
            else
                s = obj.smass_mix;
            end
        end
        
        
        %Get viscosity [Pas]
        function mu = get.MixtureViscosity(obj)
            if ~obj.mu_mix_updated_
                obj.mu = obj.species_viscosity_(obj);
                mus = obj.mu;
                X   = obj.x;
                mu  = 0;
                for i=1:length(obj.index)
                    sum = 0;
                    for j=1:length(obj.index)
                        phi = (1/sqrt(8))*(1/sqrt(1 + obj.MW(i)/obj.MW(j)))*(1 + sqrt(mus(i)/mus(j))*((obj.MW(j)/obj.MW(i))^(1/4)))^2;
                        sum = sum + X(j)*phi;
                    end
                    mu = mu + X(i)*mus(i)/sum;
                end
                obj.mu_mix = mu;
                obj.mu_mix_updated_ = true;
            else
                mu = obj.mu_mix;
            end
        end
        
        %Get thermal conductivity [W/m/K]
        function cond = get.MixtureThermalConductivity(obj)
            if ~obj.cond_mix_updated_
                obj.cond = obj.species_cond_(obj);
                conds = obj.cond;
                X     = obj.x;
                A     = 0;
                B     = 0;
                for i=1:length(obj.index)
                    A = A + X(i)*conds(i);
                    B = B + X(i)/conds(i);
                end
                cond = 0.5*(A + 1/B);
                obj.cond_mix = cond;
                obj.cond_mix_updated_ = true;
            else
                cond = obj.cond_mix;
            end
        end
        
        %Get mixture diffusion [m2/s]
        function diff = get.MixtureDiffusion(obj)
            if ~obj.diff_mix_updated_
                diff  = zeros(length(obj.index),1);
                obj.diff = obj.binary_diffusion_(obj);
                diffs = obj.diff;
                X     = obj.x;
                for i=1:length(obj.index)
                    A = 0;
                    B = 0;
                    for j=1:length(obj.index)
                        if j ~= i
                            A = A + X(j)*obj.MW(j);
                            B = B + X(j)/diffs(j,i);
                        end
                    end
                    diff(i) = A/(obj.MWmix*B);
                end
                obj.diff_mix = diff;
                obj.diff_mix_updated_ = true;
            else
                diff = obj.diff_mix;
            end
        end
        
        function v = get.MeanGasVelocity(obj)
            if ~obj.v_updated_
                v  = zeros(length(obj.index),1);
                for i=1:length(obj.index)
                    v(i) = sqrt(8*obj.R_*obj.Temperature/(obj.pi_*obj.MW(i)));
                end
                obj.v = v;
                obj.v_updated_ = true;
            else
                v = obj.v;
            end
        end
        
        function l = get.MeanFreePath(obj)
            if ~obj.l_updated_
                l  = zeros(length(obj.index),1);
                for i=1:length(obj.index)
                    l(i) = 1.38064852*1e-03*obj.Temperature/(sqrt(2)*obj.Pressure*((obj.data.transport(obj.index(i),3))^2));
                end
                obj.l = l;
                obj.l_updated_ = false;
            else
                l = obj.l;
            end
        end
        
        
    end
    
    methods (Static)
        function rho = density_(obj)
            if ~obj.rho_updated_
                rho = obj.Pressure*obj.MWmix/(obj.R_*obj.Temperature);
                obj.rho_updated_ = true;
            else
                rho = obj.rho;
            end
        end
        
        function [cpmole,cpmass] = species_cp_(obj)
            if ~obj.cp_updated_
                cp = zeros(length(obj.index),1);
                T = obj.Temperature;
                for i=1:length(obj.index)
                    if ( obj.Temperature > 1000 )
                        cp(i) = obj.data.thermo(obj.index(i),1) + obj.data.thermo(obj.index(i),2)*T + obj.data.thermo(obj.index(i),3)*T*T + obj.data.thermo(obj.index(i),4)*T*T*T + obj.data.thermo(obj.index(i),5)*T*T*T*T;
                    else
                        cp(i) = obj.data.thermo(obj.index(i),8) + obj.data.thermo(obj.index(i),9)*T + obj.data.thermo(obj.index(i),10)*T*T + obj.data.thermo(obj.index(i),11)*T*T*T + obj.data.thermo(obj.index(i),12)*T*T*T*T;
                    end
                end
                cpmole = cp*8314;
                cpmass = cpmole./obj.MW';
                obj.cp_updated_ = true;
            else
                cpmole = obj.cpmole;
                cpmass = obj.cpmass;
            end
        end
        
        function [hmole,hmass] = species_h_(obj)
            if ~obj.h_updated_
                h = zeros(length(obj.index),1);
                T = obj.Temperature;
                for i=1:length(obj.index)
                    if ( obj.Temperature > 1000 )
                        h(i) = obj.data.thermo(obj.index(i),1) + obj.data.thermo(obj.index(i),2)*T/2 + obj.data.thermo(obj.index(i),3)*T*T/3 + obj.data.thermo(obj.index(i),4)*T*T*T/4 + obj.data.thermo(obj.index(i),5)*T*T*T*T/5 + obj.data.thermo(obj.index(i),6)/T;
                    else
                        h(i) = obj.data.thermo(obj.index(i),8) + obj.data.thermo(obj.index(i),9)*T/2 + obj.data.thermo(obj.index(i),10)*T*T/3 + obj.data.thermo(obj.index(i),11)*T*T*T/4 + obj.data.thermo(obj.index(i),12)*T*T*T*T/5 + obj.data.thermo(obj.index(i),13)/T;
                    end
                end
                hmole = h*obj.R_*T;
                hmass = hmole./obj.MW';
                obj.h_updated_ = true;
            else
                hmole = obj.hmole;
                hmass = obj.hmass;
            end
        end
        
        function [smole,smass] = species_s_(obj)
            if ~obj.s_updated_
                s = zeros(length(obj.index),1);
                T = obj.Temperature;
                X = obj.x;
                for i=1:length(obj.index)
                    if ( obj.Temperature > 1000 )
                        s(i) = obj.data.thermo(obj.index(i),1)*log(T) + obj.data.thermo(obj.index(i),2)*T + obj.data.thermo(obj.index(i),3)*T*T/2 + obj.data.thermo(obj.index(i),4)*T*T*T/3 + obj.data.thermo(obj.index(i),5)*T*T*T*T/4 + obj.data.thermo(obj.index(i),7);
                    else
                        s(i) = obj.data.thermo(obj.index(i),8)*log(T) + obj.data.thermo(obj.index(i),9)*T + obj.data.thermo(obj.index(i),10)*T*T/2 + obj.data.thermo(obj.index(i),11)*T*T*T/3 + obj.data.thermo(obj.index(i),12)*T*T*T*T/4 + obj.data.thermo(obj.index(i),14);
                    end
                    s(i) = 8314*(s(i) - log(obj.Pressure*X(i)/1.0e05));
                end
                smole = s;
                smass = smole./obj.MW';
                obj.s_updated_ = true;
            else
                smole = obj.smole;
                smass = obj.smass;
            end
        end
        
        function mu = species_viscosity_(obj)
            if ~obj.mu_updated_
                mu = zeros(length(obj.index),1);
                for i=1:length(obj.index)
                    Tr    = obj.Temperature/obj.data.transport(obj.index(i),2);
                    dr    = 0.5*(obj.data.transport(obj.index(i),4)^2)/(obj.data.transport(obj.index(i),2)*1.3806488*(obj.data.transport(obj.index(i),3)^3));
                    dr    = 1e06*dr;
                    sigma = obj.collisionIntegral22(Tr,dr,obj);
                    mu(i) = (5/16)*sqrt(obj.pi_*1.3806488*obj.Temperature*obj.MW(i)*1.66054)/(obj.pi_*sigma*(obj.data.transport(obj.index(i),3)^2));
                    mu(i) = mu(i)*1e-05;
                end
                obj.mu_updated_ = true;
            else
                mu = obj.mu;
            end
        end
        
        
        function diff = binary_diffusion_(obj)
            if ~obj.diff_updated_
                diff = zeros(length(obj.index),length(obj.index));
                for i=1:length(obj.index)
                    for j=i:length(obj.index)
                        PMmix = obj.MW(i)*obj.MW(j)/(obj.MW(i) + obj.MW(j));
                        if obj.data.transport(obj.index(i),5) == 0 && obj.data.transport(obj.index(j),5) == 0
                            LJpotentialmix = sqrt(obj.data.transport(obj.index(i),2)*obj.data.transport(obj.index(j),2));
                            LJdiametermix  = 0.5*(obj.data.transport(obj.index(i),3) + obj.data.transport(obj.index(j),3));
                            dipolemix      = sqrt(obj.data.transport(obj.index(i),4)*obj.data.transport(obj.index(j),4));
                        elseif obj.data.transport(obj.index(i),5) > 0 && obj.data.transport(obj.index(j),5) > 0
                            LJpotentialmix = sqrt(obj.data.transport(obj.index(i),2)*obj.data.transport(obj.index(j),2));
                            LJdiametermix  = 0.5*(obj.data.transport(obj.index(i),3) + obj.data.transport(obj.index(j),3));
                            dipolemix      = sqrt(obj.data.transport(obj.index(i),4)*obj.data.transport(obj.index(j),4));
                        else
                            if obj.data.transport(obj.index(i),5) == 0
                                polarn  = obj.data.transport(obj.index(i),5)/(obj.data.transport(obj.index(i),2)^3);
                                dipolep = 1e02*obj.data.transport(obj.index(j),4)/sqrt(obj.data.transport(obj.index(j),2)*1.3806488*(obj.data.transport(obj.index(j),3)^3));
                                chi     = 1 + 0.25*polarn*dipolep*sqrt(obj.data.transport(obj.index(i),2)/obj.data.transport(obj.index(j),2));
                            else
                                polarn  = obj.data.transport(obj.index(j),5)/(obj.data.transport(obj.index(j),2)^3);
                                dipolep = 1e02*obj.data.transport(obj.index(i),4)/sqrt(obj.data.transport(obj.index(i),2)*1.3806488*(obj.data.transport(obj.index(i),3)^3));
                                chi     = 1 + 0.25*polarn*dipolep*sqrt(obj.data.transport(obj.index(i),2)/obj.data.transport(obj.index(j),2));
                            end
                            LJpotentialmix = (chi^2)*sqrt(obj.data.transport(obj.index(i),2)*obj.data.transport(obj.index(j),2));
                            LJdiametermix  = 0.5*(obj.data.transport(obj.index(i),3) + obj.data.transport(obj.index(j),3))*(chi^(-1/6));
                            dipolemix      = 0.
                        end
                        Tr        = obj.Temperature/LJpotentialmix;
                        dr        = 0.5*(dipolemix^2)/(LJpotentialmix*1.3806488*(LJdiametermix^3));
                        dr        = 1e06*dr;
                        sigma     = obj.collisionIntegral11(Tr,dr,obj);
                        diff(i,j) = (3/16)*sqrt(2*obj.pi_*((1.3806488*obj.Temperature)^3)/(PMmix*1.66054))/(obj.Pressure*obj.pi_*(LJdiametermix^2)*sigma);
                        diff(i,j) = diff(i,j)*0.1;
                        diff(j,i) = diff(i,j);
                    end
                end
                obj.diff_updated_ = true;
            else
                diff = obj.diff;
            end
        end
        
        function cond = species_cond_(obj)
            if ~obj.cond_updated_
                cond = zeros(length(obj.index),1);
                [obj.cpmole, obj.cpmass] = obj.species_cp_(obj);
                obj.mu = obj.species_viscosity_(obj);
                obj.diff = obj.binary_diffusion_(obj);
                obj.rho = obj.density_(obj);
                
                cpmole = obj.cpmole;
                mu = obj.mu;
                diff = obj.diff;
                rho = obj.rho;
                
                for i=1:length(obj.index)
                    if ( obj.data.transport(obj.index(i),1) == 0 )
                        cvtrans = 3.*obj.R_*0.5;
                        cvrot   = 0.;
                        cvvib   = 0.;
                    elseif ( obj.data.transport(obj.index(i),1) == 1 )
                        cvtrans = 3.*obj.R_*0.5;
                        cvrot   = obj.R_*0.5;
                        cvvib   = cpmole(i) - 8314 - 5*obj.R_*0.5;
                    else
                        cvtrans = 3.*obj.R_*0.5;
                        cvrot   = 3.*obj.R_*0.5;
                        cvvib   = cpmole(i) - 8314 - 3*8314;
                    end
                    
                    A       = (5/2) - rho*diff(i,i)/mu(i);
                    
                    F_T     = 1 + 0.5*sqrt((obj.pi_^3)*obj.data.transport(obj.index(i),2)/obj.Temperature) + (0.25*(obj.pi_^2) + 2)*(obj.data.transport(obj.index(i),2)/obj.Temperature) + sqrt((obj.pi_*(obj.data.transport(obj.index(i),2)/obj.Temperature))^3);
                    F_298   = 1 + 0.5*sqrt((obj.pi_^3)*obj.data.transport(obj.index(i),2)/298) + (0.25*(obj.pi_^2) + 2)*(obj.data.transport(obj.index(i),2)/298) + sqrt((obj.pi_*(obj.data.transport(obj.index(i),2)/298))^3);
                    Zrot    = obj.data.transport(obj.index(i),6)*F_298/F_T;
                    B       = Zrot + (2/obj.pi_)*((5/3)*(cvrot/8314) + rho*diff(i,i)/mu(i));
                    ftrans  = (5/2)*(1 - 2*cvrot*A/(obj.pi_*cvtrans*B));
                    frot    = (rho*diff(i,i)/mu(i))*(1 + 2*A/(obj.pi_*B));
                    fvib    = (rho*diff(i,i)/mu(i));
                    cond(i) = mu(i)*(ftrans*cvtrans + frot*cvrot + fvib*cvvib)/obj.MW(i);
                end
                obj.cond_updated_ = true;
            else
                cond = obj.cond;
            end
        end
        
        
        function sigma = collisionIntegral11(Tr,dr,obj)
            Ta = -1;
            Tb = -1;
            for i=1:(length(obj.data.T)-1)
                if ( Tr >= obj.data.T(i) && Tr < obj.data.T(i + 1))
                    Ta = i;
                    Tb = i + 1;
                    break;
                end
            end
            
            if Ta == -1
                if ( Tr <= obj.data.T(1) )
                    Ta = 0;
                    Tb = 1;
                else
                    Ta = length(obj.data.T) - 1;
                    Tb = Ta + 1;
                end
            end
            
            da = -1;
            db = -1;
            for i=1:(length(obj.data.d)-1)
                if ( dr >= obj.data.d(i) && dr < obj.data.d(i + 1))
                    da = i;
                    db = i + 1;
                    break;
                end
            end
            
            if da == -1
                if ( dr <= obj.data.d(1) )
                    da = 0;
                    db = 1;
                else
                    da = length(obj.data.d) - 1;
                    db = sa + 1;
                end
            end
            
            A = [1 obj.data.T(Ta) obj.data.d(da) obj.data.T(Ta)*obj.data.d(da);
                1 obj.data.T(Ta) obj.data.d(db) obj.data.T(Ta)*obj.data.d(db);
                1 obj.data.T(Tb) obj.data.d(da) obj.data.T(Tb)*obj.data.d(da);
                1 obj.data.T(Tb) obj.data.d(db) obj.data.T(Tb)*obj.data.d(db)];
            
            b = [obj.data.omega11(Ta,da);obj.data.omega11(Ta,db);obj.data.omega11(Tb,da);obj.data.omega11(Tb,db)];
            
            x = mldivide(A,b);
            
            sigma = x(1) + x(2)*Tr + x(3)*dr + x(4)*Tr*dr;
        end
        
        function sigma = collisionIntegral22(Tr,dr,obj)
            Ta = -1;
            Tb = -1;
            for i=1:(length(obj.data.T)-1)
                if ( Tr >= obj.data.T(i) && Tr < obj.data.T(i + 1))
                    Ta = i;
                    Tb = i + 1;
                    break;
                end
            end
            
            if Ta == -1
                if ( Tr <= obj.data.T(1) )
                    Ta = 0;
                    Tb = 1;
                else
                    Ta = length(obj.data.T) - 1;
                    Tb = Ta + 1;
                end
            end
            
            da = -1;
            db = -1;
            for i=1:(length(obj.data.d)-1)
                if ( dr >= obj.data.d(i) && dr < obj.data.d(i + 1))
                    da = i;
                    db = i + 1;
                    break;
                end
            end
            
            if da == -1
                if ( dr <= obj.data.d(1) )
                    da = 0;
                    db = 1;
                else
                    da = length(obj.data.d) - 1;
                    db = sa + 1;
                end
            end
            
            A = [1 obj.data.T(Ta) obj.data.d(da) obj.data.T(Ta)*obj.data.d(da);
                1 obj.data.T(Ta) obj.data.d(db) obj.data.T(Ta)*obj.data.d(db);
                1 obj.data.T(Tb) obj.data.d(da) obj.data.T(Tb)*obj.data.d(da);
                1 obj.data.T(Tb) obj.data.d(db) obj.data.T(Tb)*obj.data.d(db)];
            
            b = [obj.data.omega22(Ta,da);obj.data.omega22(Ta,db);obj.data.omega22(Tb,da);obj.data.omega22(Tb,db)];
            
            x = mldivide(A,b);
            
            sigma = x(1) + x(2)*Tr + x(3)*dr + x(4)*Tr*dr;
        end
    end
end
