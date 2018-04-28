classdef Asali
     
   properties
       Pressure                   = [];
       Temperature                = [];
       Density                    = [];
       Names                      = [];
       SpecieViscosity            = [];
       SpecieThermalConductivity  = [];
       BinaryDiffusion            = [];
       SpecieMolarSpecificHeat    = [];
       SpecieMassSpecificHeat     = [];
       SpecieMolarEnthalpy        = [];
       SpecieMassEnthalpy         = [];
       SpecieMolarEntropy         = [];
       SpecieMassEntropy          = [];
       MixtureViscosity           = [];
       MixtureThermalConductivity = [];
       MixtureDiffusion           = [];
       MixtureMolarSpecificHeat   = [];
       MixtureMassSpecificHeat    = [];
       MixtureMolarEnthalpy       = [];
       MixtureMassEnthalpy        = [];
       MixtureMolarEntropy        = [];
       MixtureMassEntropy         = [];
       MW                         = [];
       y                          = [];
       x                          = [];
       MWmix                      = [];
       data                       = [];
   end

   properties (Dependent)
       MoleFraction               = [];
       MassFraction               = [];
   end
   
   methods
       
       %Load data
       function obj = Asali(value)
           load(value);
           obj.data = database;
       end

       %SetNames
       function obj = set.Names(obj,value)
            for i=1:length(value)
                if ~ismember(value{i},obj.data.name)
                    error([value{i},' is not present in ASALI database'])
                else
                    
                    obj.Names(i) = find(strcmpi(value{i},obj.data.name));
                end
            end
        end

       %Set mole fraction
       function obj = set.MoleFraction(obj,value)
            if ~isempty(value)
                if length(value) ~= length(obj.Names)
                    error('Wrong number of species in MoleFraction')
                elseif sum(value) ~= 1
                    error('Sum of MoleFraction must be 1')
                else
                    obj.x     = value;
                    obj.MWmix = sum(value.*obj.MW);
                    obj.y     = value.*obj.MW/obj.MWmix;
                end
            end
        end
 
       %Set mass fraction
       function obj = set.MassFraction(obj,value)
            if ~isempty(value)
                if length(value) ~= length(obj.Names)
                    error('Wrong number of species in MassFraction')
                elseif sum(value) ~= 1
                    error('Sum of MassFraction must be 1')
                else
                    obj.y     = value;
                    obj.MWmix = 1/sum(value./obj.MW);
                    obj.x     = obj.MWmix*(value./obj.MW);
                end
            end
        end
        
       %Molecular weigth  [g/mol]
       function MW = get.MW(obj)
            for i=1:length(obj.Names)
               MW(i) = obj.data.transport(obj.Names(i),7); 
            end  
        end
        
       %Get density [kg/m3]
       function rho = get.Density(obj)
              rho = obj.Pressure*obj.MWmix/(8314*obj.Temperature);
        end

       %Get mole fraction
       function x = get.MoleFraction(obj)
            x = obj.x;
        end
 
       %Get mass fraction
       function y = get.MassFraction(obj)
            y = obj.y;
        end
        
       %Get specific heat [J/kmol/K]
       function cp = get.SpecieMolarSpecificHeat(obj)
            cp = zeros(length(obj.Names),1);
            T = obj.Temperature;
            for i=1:length(obj.Names)
               if ( obj.Temperature > 1000 )
                  cp(i) = obj.data.thermo(obj.Names(i),1) + obj.data.thermo(obj.Names(i),2)*T + obj.data.thermo(obj.Names(i),3)*T*T + obj.data.thermo(obj.Names(i),4)*T*T*T + obj.data.thermo(obj.Names(i),5)*T*T*T*T;
               else
                  cp(i) = obj.data.thermo(obj.Names(i),8) + obj.data.thermo(obj.Names(i),9)*T + obj.data.thermo(obj.Names(i),10)*T*T + obj.data.thermo(obj.Names(i),11)*T*T*T + obj.data.thermo(obj.Names(i),12)*T*T*T*T; 
               end
            end
            cp = cp*8314;
        end

       %Get specific heat [J/kg/K]
       function cp = get.SpecieMassSpecificHeat(obj)
            cp = zeros(length(obj.Names),1);
            T  = obj.Temperature;
            for i=1:length(obj.Names)
               if ( obj.Temperature > 1000 )
                  cp(i) = obj.data.thermo(obj.Names(i),1) + obj.data.thermo(obj.Names(i),2)*T + obj.data.thermo(obj.Names(i),3)*T*T + obj.data.thermo(obj.Names(i),4)*T*T*T + obj.data.thermo(obj.Names(i),5)*T*T*T*T;
               else
                  cp(i) = obj.data.thermo(obj.Names(i),8) + obj.data.thermo(obj.Names(i),9)*T + obj.data.thermo(obj.Names(i),10)*T*T + obj.data.thermo(obj.Names(i),11)*T*T*T + obj.data.thermo(obj.Names(i),12)*T*T*T*T; 
               end
               cp(i) = cp(i)*8314/obj.MW(i);   
            end
       end
       
       %Get enthalpy [J/kmol]
       function h = get.SpecieMolarEnthalpy(obj)
            h = zeros(length(obj.Names),1);
            T = obj.Temperature;
            for i=1:length(obj.Names)
               if ( obj.Temperature > 1000 )
                  h(i) = obj.data.thermo(obj.Names(i),1) + obj.data.thermo(obj.Names(i),2)*T/2 + obj.data.thermo(obj.Names(i),3)*T*T/3 + obj.data.thermo(obj.Names(i),4)*T*T*T/4 + obj.data.thermo(obj.Names(i),5)*T*T*T*T/5 + obj.data.thermo(obj.Names(i),6)/T;
               else
                  h(i) = obj.data.thermo(obj.Names(i),8) + obj.data.thermo(obj.Names(i),9)*T/2 + obj.data.thermo(obj.Names(i),10)*T*T/3 + obj.data.thermo(obj.Names(i),11)*T*T*T/4 + obj.data.thermo(obj.Names(i),12)*T*T*T*T/5 + obj.data.thermo(obj.Names(i),13)/T; 
               end
            end
            h = h*8314*T;
       end

       %Get enthalpy [J/kg]
       function h = get.SpecieMassEnthalpy(obj)
            h = zeros(length(obj.Names),1);
            T = obj.Temperature;
            for i=1:length(obj.Names)
               if ( obj.Temperature > 1000 )
                  h(i) = obj.data.thermo(obj.Names(i),1) + obj.data.thermo(obj.Names(i),2)*T/2 + obj.data.thermo(obj.Names(i),3)*T*T/3 + obj.data.thermo(obj.Names(i),4)*T*T*T/4 + obj.data.thermo(obj.Names(i),5)*T*T*T*T/5 + obj.data.thermo(obj.Names(i),6)/T;
               else
                  h(i) = obj.data.thermo(obj.Names(i),8) + obj.data.thermo(obj.Names(i),9)*T/2 + obj.data.thermo(obj.Names(i),10)*T*T/3 + obj.data.thermo(obj.Names(i),11)*T*T*T/4 + obj.data.thermo(obj.Names(i),12)*T*T*T*T/5 + obj.data.thermo(obj.Names(i),13)/T; 
               end
               h(i) = h(i)*8314*T/obj.MW(i);   
            end
       end

       %Get entropy [J/kmol/K]
       function s = get.SpecieMolarEntropy(obj)
            s = zeros(length(obj.Names),1);
            T = obj.Temperature;
            for i=1:length(obj.Names)
               if ( obj.Temperature > 1000 )
                  s(i) = obj.data.thermo(obj.Names(i),1)*log(T) + obj.data.thermo(obj.Names(i),2)*T + obj.data.thermo(obj.Names(i),3)*T*T/2 + obj.data.thermo(obj.Names(i),4)*T*T*T/3 + obj.data.thermo(obj.Names(i),5)*T*T*T*T/4 + obj.data.thermo(obj.Names(i),7);
               else
                  s(i) = obj.data.thermo(obj.Names(i),8)*log(T) + obj.data.thermo(obj.Names(i),9)*T + obj.data.thermo(obj.Names(i),10)*T*T/2 + obj.data.thermo(obj.Names(i),11)*T*T*T/3 + obj.data.thermo(obj.Names(i),12)*T*T*T*T/4 + obj.data.thermo(obj.Names(i),14); 
               end
            end
            s = s*8314;
       end

       %Get entropy [J/kg/K]
       function s = get.SpecieMassEntropy(obj)
            s = zeros(length(obj.Names),1);
            T = obj.Temperature;
            for i=1:length(obj.Names)
               if ( obj.Temperature > 1000 )
                  s(i) = obj.data.thermo(obj.Names(i),1)*log(T) + obj.data.thermo(obj.Names(i),2)*T + obj.data.thermo(obj.Names(i),3)*T*T/2 + obj.data.thermo(obj.Names(i),4)*T*T*T/3 + obj.data.thermo(obj.Names(i),5)*T*T*T*T/4 + obj.data.thermo(obj.Names(i),7);
               else
                  s(i) = obj.data.thermo(obj.Names(i),8)*log(T) + obj.data.thermo(obj.Names(i),9)*T + obj.data.thermo(obj.Names(i),10)*T*T/2 + obj.data.thermo(obj.Names(i),11)*T*T*T/3 + obj.data.thermo(obj.Names(i),12)*T*T*T*T/4 + obj.data.thermo(obj.Names(i),14); 
               end
               s(i) = s(i)*8314/obj.MW(i);   
            end
       end

       %Get viscosity [Pas]
       function mu = get.SpecieViscosity(obj)
            mu = zeros(length(obj.Names),1);
            for i=1:length(obj.Names)
               Tr    = obj.Temperature/obj.data.transport(obj.Names(i),2);
               dr    = 0.5*(obj.data.transport(obj.Names(i),4)^2)/(obj.data.transport(obj.Names(i),2)*1.3806488*(obj.data.transport(obj.Names(i),3)^3));
               dr    = 1e06*dr;
               sigma = obj.collisionIntegral22(Tr,dr,obj);
               mu(i) = (5/16)*sqrt(3.14159*1.3806488*obj.Temperature*obj.MW(i)*1.66054)/(3.14159*sigma*(obj.data.transport(obj.Names(i),3)^2));
               mu(i) = mu(i)*1e-05;
            end
        end
        
       %Get binary diffusion [m2/s]
       function diff = get.BinaryDiffusion(obj)
            diff = zeros(length(obj.Names),length(obj.Names));
            for i=1:length(obj.Names)
                for j=i:length(obj.Names)
                    PMmix = obj.MW(i)*obj.MW(j)/(obj.MW(i) + obj.MW(j));
                    if obj.data.transport(obj.Names(i),5) == 0 && obj.data.transport(obj.Names(j),5) == 0
                        LJpotentialmix = sqrt(obj.data.transport(obj.Names(i),2)*obj.data.transport(obj.Names(j),2));
                        LJdiametermix  = 0.5*(obj.data.transport(obj.Names(i),3) + obj.data.transport(obj.Names(j),3));
                        dipolemix      = sqrt(obj.data.transport(obj.Names(i),4)*obj.data.transport(obj.Names(j),4));
                    elseif obj.data.transport(obj.Names(i),5) > 0 && obj.data.transport(obj.Names(j),5) > 0
                        LJpotentialmix = sqrt(obj.data.transport(obj.Names(i),2)*obj.data.transport(obj.Names(j),2));
                        LJdiametermix  = 0.5*(obj.data.transport(obj.Names(i),3) + obj.data.transport(obj.Names(j),3));
                        dipolemix      = sqrt(obj.data.transport(obj.Names(i),4)*obj.data.transport(obj.Names(j),4));
                    else
                        if obj.data.transport(obj.Names(i),5) == 0
                            polarn  = obj.data.transport(obj.Names(i),5)/(obj.data.transport(obj.Names(i),2)^3);
                            dipolep = 1e02*obj.data.transport(obj.Names(j),4)/sqrt(obj.data.transport(obj.Names(j),2)*1.3806488*(obj.data.transport(obj.Names(j),3)^3));
                            chi     = 1 + 0.25*polarn*dipolep*sqrt(obj.data.transport(obj.Names(i),2)/obj.data.transport(obj.Names(j),2));
                        else
                            polarn  = obj.data.transport(obj.Names(j),5)/(obj.data.transport(obj.Names(j),2)^3);
                            dipolep = 1e02*obj.data.transport(obj.Names(i),4)/sqrt(obj.data.transport(obj.Names(i),2)*1.3806488*(obj.data.transport(obj.Names(i),3)^3));
                            chi     = 1 + 0.25*polarn*dipolep*sqrt(obj.data.transport(obj.Names(i),2)/obj.data.transport(obj.Names(j),2));
                        end
                        LJpotentialmix = (chi^2)*sqrt(obj.data.transport(obj.Names(i),2)*obj.data.transport(obj.Names(j),2));
                        LJdiametermix  = 0.5*(obj.data.transport(obj.Names(i),3) + obj.data.transport(obj.Names(j),3))*(chi^(-1/6));
                        dipolemix      = 0.
                    end
                    Tr        = obj.Temperature/LJpotentialmix;
                    dr        = 0.5*(dipolemix^2)/(LJpotentialmix*1.3806488*(LJdiametermix^3));
                    dr        = 1e06*dr;
                    sigma     = obj.collisionIntegral11(Tr,dr,obj);
                    diff(i,j) = (3/16)*sqrt(2*3.14159*((1.3806488*obj.Temperature)^3)/(PMmix*1.66054))/(obj.Pressure*3.14159*(LJdiametermix^2)*sigma);
                    diff(i,j) = diff(i,j)*0.1;
                    diff(j,i) = diff(i,j);
                end
            end
        end
        
       %Get thermal conductivity [W/m/K]
       function cond = get.SpecieThermalConductivity(obj)
           cond = zeros(length(obj.Names),1);
            for i=1:length(obj.Names)
               if ( obj.data.transport(obj.Names(i),1) == 0 )
                   cvtrans = 3.*8314*0.5;
                   cvrot   = 0.;
                   cvvib   = 0.;
               elseif ( obj.data.transport(obj.Names(i),1) == 1 )
                   cvtrans = 3.*8314*0.5;
                   cvrot   = 8314;
                   cvvib   = obj.SpecieMolarSpecificHeat(i) - 8314 - 5*8314*0.5;
               else
                   cvtrans = 3.*8314*0.5;
                   cvrot   = 3.*8314*0.5;
                   cvvib   = obj.SpecieMolarSpecificHeat(i) - 8314 - 3*8314;
               end
               
               A       = (5/2) - obj.Density*obj.BinaryDiffusion(i,i)/obj.SpecieViscosity(i);
               F_T     = 1 + 0.5*sqrt((3.14159^3)*obj.data.transport(obj.Names(i),2)/obj.Temperature) + (0.25*(3.14159^2) + 2)*(obj.data.transport(obj.Names(i),2)/obj.Temperature) + sqrt((3.14159*(obj.data.transport(obj.Names(i),2)/obj.Temperature))^3);
               F_298   = 1 + 0.5*sqrt((3.14159^3)*obj.data.transport(obj.Names(i),2)/298) + (0.25*(3.14159^2) + 2)*(obj.data.transport(obj.Names(i),2)/298) + sqrt((3.14159*(obj.data.transport(obj.Names(i),2)/298))^3);
               Zrot    = obj.data.transport(obj.Names(i),6)*F_298/F_T;
               B       = Zrot + (2/3.14159)*((5/3)*(cvrot/8314) + obj.Density*obj.BinaryDiffusion(i,i)/obj.SpecieViscosity(i));
               ftrans  = (5/2)*(1 - 2*cvrot*A/(3.14159*cvtrans*B));
               frot    = (obj.Density*obj.BinaryDiffusion(i,i)/obj.SpecieViscosity(i))*(1 + 2*A/(3.14159*B));
               fvib    = (obj.Density*obj.BinaryDiffusion(i,i)/obj.SpecieViscosity(i));
               cond(i) = obj.SpecieViscosity(i)*(ftrans*cvtrans + frot*cvrot + fvib*cvvib)/obj.MW(i);
            end
       end
       
       %Get specific heat [J/kmol/K]
       function cp = get.MixtureMolarSpecificHeat(obj)
            cps = obj.SpecieMolarSpecificHeat;
            X   = obj.x;
            cp  = 0;
            for i=1:length(X)
                cp = cp + X(i)*cps(i);
            end
        end

       %Get specific heat [J/kg/K]
       function cp = get.MixtureMassSpecificHeat(obj)
            cps = obj.SpecieMassSpecificHeat;
            Y   = obj.y;
            cp  = 0;
            for i=1:length(Y)
                cp = cp + Y(i)*cps(i);
            end
       end    
       
       %Get enthalpy [J/kmol]
       function h = get.MixtureMolarEnthalpy(obj)
            hs = obj.SpecieMolarEnthalpy;
            X  = obj.x;
            h  = 0;
            for i=1:length(X)
                h = h + X(i)*hs(i);
            end
        end

       %Get enthalpy [J/kg]
       function h = get.MixtureMassEnthalpy(obj)
            hs = obj.SpecieMassEnthalpy;
            Y  = obj.y;
            h  = 0;
            for i=1:length(Y)
                h = h + Y(i)*hs(i);
            end
       end    
       
       %Get entropy [J/kmol/K]
       function s = get.MixtureMolarEntropy(obj)
            ss = obj.SpecieMolarEntropy;
            X  = obj.x;
            s  = 0;
            for i=1:length(X)
                s = s + X(i)*ss(i);
            end
        end

       %Get enthalpy [J/kg]
       function s = get.MixtureMassEntropy(obj)
            ss = obj.SpecieMassEntropy;
            Y  = obj.y;
            s  = 0;
            for i=1:length(Y)
                s = s + Y(i)*ss(i);
            end
       end          
 
       %Get viscosity [Pas]
       function mu = get.MixtureViscosity(obj)
            mus = obj.SpecieViscosity;
            X   = obj.x;
            mu  = 0;
            for i=1:length(obj.Names)
                sum = 0;
                for j=1:length(obj.Names)
                    phi = (1/sqrt(8))*(1/sqrt(1 + obj.MW(i)/obj.MW(j)))*(1 + sqrt(mus(i)/mus(j))*((obj.MW(j)/obj.MW(i))^(1/4)))^2;
                    sum = sum + X(j)*phi;
                end
                mu = mu + X(i)*mus(i)/sum;
            end
       end
 
       %Get thermal conductivity [W/m/K]
       function cond = get.MixtureThermalConductivity(obj)
           conds = obj.SpecieThermalConductivity;
           X     = obj.x;
           A     = 0;
           B     = 0;
           for i=1:length(obj.Names)
              A = A + X(i)*conds(i);
              B = B + X(i)/conds(i);
           end
           cond = 0.5*(A + 1/B);
       end
 
       %Get mixture diffusion [m2/s]
       function diff = get.MixtureDiffusion(obj)
           diff  = zeros(length(obj.Names),1);
           diffs = obj.BinaryDiffusion;
           X     = obj.x;
           for i=1:length(obj.Names)
               A = 0;
               B = 0;
               for j=1:length(obj.Names)
                   if j ~= i
                      A = A + X(j)*obj.MW(j);
                      B = B + X(j)/diffs(j,i);
                   end
               end
               diff(i) = A/(obj.MWmix*B);
           end
       end
       
   end
   
   methods (Static)
       %Get collision integral 11
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
        
       %Get collision integral 22
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