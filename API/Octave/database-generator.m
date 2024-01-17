close all
clear all
clc

%Read transport
a = importdata('../database/transport.asali');
for i=1:size(a,1)
    b = strsplit(a{i},'\t');
    database.name{i} = b{1};
    database.transport(i,1) = str2double(b{2});
    database.transport(i,2) = str2double(b{3});
    database.transport(i,3) = str2double(b{4});
    database.transport(i,4) = str2double(b{5});
    database.transport(i,5) = str2double(b{6});
    database.transport(i,6) = str2double(b{7});
    database.transport(i,7) = str2double(b{8});
end

%Read thermo
id    = fopen('../database/thermo.asali');
tline = fgetl(id);
A{1} = strsplit(tline,'\t');
counter = 2;
while ischar(tline)
    tline = fgetl(id);
    if ischar(tline)
        A{counter} = strsplit(tline,'\t');
        counter = counter + 1;
    end
end

for i=1:size(A,2)
    if size(A{i},2) == 1
        for j=1:length(database.name)
            if strcmpi(A{i},database.name{j})
                counter = 1;
                for k=1:size(A{i+1},2)
                    if ~strcmpi(A{i+1}(k),'') 
                        database.thermo(j,counter) = str2double(A{i+1}(k));
                        counter = counter + 1;
                    end
                end
                for k=1:size(A{i+2},2)
                    if ~strcmpi(A{i+2}(k),'') 
                        database.thermo(j,counter) = str2double(A{i+2}(k));
                        counter = counter + 1;
                    end
                end
                for k=1:size(A{i+3},2)
                    if ~strcmpi(A{i+3}(k),'') 
                        database.thermo(j,counter) = str2double(A{i+3}(k));
                        counter = counter + 1;
                    end
                end                
            end
        end
    end
end
        

%Read omega22
a = importdata('../database/omega22.asali');

database.d = (a.data(1,:));
for i=2:size(a.textdata,1)
    database.T(i-1) = str2double(a.textdata{i});
    database.omega22(i-1,:) = a.data(i,:);
end

%Read astar
a = importdata('../database/astar.asali');

for i=2:size(a.textdata,1)
    database.omega11(i-1,:) = database.omega22(i-1,:)./a.data(i,:);
end

save('database.mat','database');
