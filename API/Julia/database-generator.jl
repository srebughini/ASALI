################################################################################################
#                                                                                              #
#     #############       #############       #############       ####                ####     #
#    #             #     #             #     #             #     #    #              #    #    #
#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #
#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #
#    #    #####    #     #    #              #    #####    #     #    #              #    #    #
#    #             #     #    #########      #             #     #    #              #    #    #
#    #             #     #             #     #             #     #    #              #    #    #
#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #
#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #
#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #
#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #
#     ####     ####       #############       ####     ####       #############       ####     #
#                                                                                              #
#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #
#                                                                                              #
################################################################################################
#                                                                                              #
#   License                                                                                    #
#                                                                                              #
#   This file is part of ASALI.                                                                #
#                                                                                              #
#   ASALI is free software: you can redistribute it and/or modify                              #
#   it under the terms of the GNU General Public License as published by                       #
#   the Free Software Foundation, either version 3 of the License, or                          #
#   (at your option) any later version.                                                        #
#                                                                                              #
#   ASALI is distributed in the hope that it will be useful,                                   #
#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #
#   GNU General Public License for more details.                                               #
#                                                                                              #
#   You should have received a copy of the GNU General Public License                          #
#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #
#                                                                                              #
################################################################################################
function read_file(file_path)
    path = joinpath(@__DIR__, file_path)
    io = open(path, "r")
    return readlines(io)
end

function read_transport()
    all = read_file("../database/transport.asali")
    NC = size(all,1)
    names = Array{String}(undef, NC)
    geometry = Vector{Int64}(undef, NC)
    LJpotential = Vector{Float64}(undef, NC)
    LJdiameter = Vector{Float64}(undef, NC)
    dipole = Vector{Float64}(undef, NC)
    polar = Vector{Float64}(undef, NC)
    collision = Vector{Float64}(undef, NC)
    MW = Vector{Float64}(undef, NC)
    for i in 1:NC
        line = split(getindex(all,i),"\t")
        setindex!(names,getindex(line,1),i)
        setindex!(geometry,parse(Int64,getindex(line,2)),i)
        setindex!(LJpotential,parse(Float64,getindex(line,3)),i)
        setindex!(LJdiameter,parse(Float64,getindex(line,4)),i)
        setindex!(dipole,parse(Float64,getindex(line,5)),i)
        setindex!(polar,parse(Float64,getindex(line,6)),i)
        setindex!(collision,parse(Float64,getindex(line,7)),i)
        setindex!(MW,parse(Float64,getindex(line,8)),i)
    end

    return NC, names, geometry, LJpotential, LJdiameter, dipole, polar, collision, MW
end

function read_thermo()
    all = read_file("../database/thermo.asali")
    NC = size(all,1) ÷ 4
    names = Array{String}(undef, NC)
    highA = Vector{Float64}(undef, NC)
    highB = Vector{Float64}(undef, NC)
    highC = Vector{Float64}(undef, NC)
    highD = Vector{Float64}(undef, NC)
    highE = Vector{Float64}(undef, NC)
    highF = Vector{Float64}(undef, NC)
    highG = Vector{Float64}(undef, NC)
    lowA = Vector{Float64}(undef, NC)
    lowB = Vector{Float64}(undef, NC)
    lowC = Vector{Float64}(undef, NC)
    lowD = Vector{Float64}(undef, NC)
    lowE = Vector{Float64}(undef, NC)
    lowF = Vector{Float64}(undef, NC)
    lowG = Vector{Float64}(undef, NC)
    linecounter = 1
    for i in 1:NC
        line = split(getindex(all,linecounter),"\t")
        setindex!(names,getindex(line,1),i)

        linecounter = linecounter + 1
        line = split(getindex(all,linecounter),"\t")
        setindex!(highA,parse(Float64,getindex(line,1)),i)
        setindex!(highB,parse(Float64,getindex(line,2)),i)
        setindex!(highC,parse(Float64,getindex(line,3)),i)
        setindex!(highD,parse(Float64,getindex(line,4)),i)
        setindex!(highE,parse(Float64,getindex(line,5)),i)

        linecounter = linecounter + 1
        line = split(getindex(all,linecounter),"\t")
        setindex!(highF,parse(Float64,getindex(line,1)),i)
        setindex!(highG,parse(Float64,getindex(line,2)),i)
        setindex!(lowA,parse(Float64,getindex(line,3)),i)
        setindex!(lowB,parse(Float64,getindex(line,4)),i)
        setindex!(lowC,parse(Float64,getindex(line,5)),i)

        linecounter = linecounter + 1
        line = split(getindex(all,linecounter),"\t")
        setindex!(lowD,parse(Float64,getindex(line,1)),i)
        setindex!(lowE,parse(Float64,getindex(line,2)),i)
        setindex!(lowF,parse(Float64,getindex(line,3)),i)
        setindex!(lowG,parse(Float64,getindex(line,4)),i)

        linecounter = linecounter + 1
    end
    return NC, names, highA, highB, highC, highD, highE, highF, highG, lowA, lowB, lowC, lowD, lowE, lowF, lowG
end

function read_omega(filepath)
    all = read_file(filepath)
    nr = size(all,1) - 1

    line = split(getindex(all,1),"\t")

    nc = size(line,1) - 1
    dsigma = Vector{Float64}(undef, nc)
    Tsigma = Vector{Float64}(undef, nr)
    sigmaMatrix = Matrix{Float64}(undef, nr, nc)

    for i in 2:nc+1
        setindex!(dsigma,parse(Float64,getindex(line,i)),i-1)
    end

    for i in 2:nr+1
        line = split(getindex(all,i),"\t")

        setindex!(Tsigma,parse(Float64,getindex(line,1)),i-1)
        for j in 2:nc+1
            setindex!(sigmaMatrix,parse(Float64,getindex(line,j)),i-1,j-1)
        end

    end

    return dsigma, Tsigma, sigmaMatrix
end

function get_heading()
    heading = string("################################################################################################\n",
                     "#                                                                                              #\n",
                     "#     #############       #############       #############       ####                ####     #\n",
                     "#    #             #     #             #     #             #     #    #              #    #    #\n",
                     "#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #\n",
                     "#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #\n",
                     "#    #    #####    #     #    #              #    #####    #     #    #              #    #    #\n",
                     "#    #             #     #    #########      #             #     #    #              #    #    #\n",
                     "#    #             #     #             #     #             #     #    #              #    #    #\n",
                     "#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #\n",
                     "#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #\n",
                     "#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #\n",
                     "#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #\n",
                     "#     ####     ####       #############       ####     ####       #############       ####     #\n",
                     "#                                                                                              #\n",
                     "#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #\n",
                     "#                                                                                              #\n",
                     "################################################################################################\n",
                     "#                                                                                              #\n",
                     "#   License                                                                                    #\n",
                     "#                                                                                              #\n",
                     "#   This file is part of ASALI.                                                                #\n",
                     "#                                                                                              #\n",
                     "#   ASALI is free software: you can redistribute it and/or modify                              #\n",
                     "#   it under the terms of the GNU General Public License as published by                       #\n",
                     "#   the Free Software Foundation, either version 3 of the License, or                          #\n",
                     "#   (at your option) any later version.                                                        #\n",
                     "#                                                                                              #\n",
                     "#   ASALI is distributed in the hope that it will be useful,                                   #\n",
                     "#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #\n",
                     "#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #\n",
                     "#   GNU General Public License for more details.                                               #\n",
                     "#                                                                                              #\n",
                     "#   You should have received a copy of the GNU General Public License                          #\n",
                     "#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #\n",
                     "#                                                                                              #\n",
                     "################################################################################################\n")
    return heading
end

function write_thermo(NC_transport, names_transport)
    NC_thermo, names_thermo, highA, highB, highC, highD, highE, highF, highG, lowA, lowB, lowC, lowD, lowE, lowF, lowG = read_thermo()
    path = joinpath(@__DIR__, "thermoDatabase.jl")
    io = open(path, "w")

    heading = get_heading()

    write(io, heading)
    write(io, "module thermoDatabase\n")
    write(io, "\tstruct Thermo\n")
    write(io, "\t\tNC::Int64\n")
    write(io, "\t\tname::Array{String}\n")
    write(io, "\t\thighA::Vector{Float64}\n")
    write(io, "\t\thighB::Vector{Float64}\n")
    write(io, "\t\thighC::Vector{Float64}\n")
    write(io, "\t\thighD::Vector{Float64}\n")
    write(io, "\t\thighE::Vector{Float64}\n")
    write(io, "\t\thighF::Vector{Float64}\n")
    write(io, "\t\thighG::Vector{Float64}\n")
    write(io, "\t\tlowA::Vector{Float64}\n")
    write(io, "\t\tlowB::Vector{Float64}\n")
    write(io, "\t\tlowC::Vector{Float64}\n")
    write(io, "\t\tlowD::Vector{Float64}\n")
    write(io, "\t\tlowE::Vector{Float64}\n")
    write(io, "\t\tlowF::Vector{Float64}\n")
    write(io, "\t\tlowG::Vector{Float64}\n")
    write(io, "\tend\n\n")

    nameStr  = "\n\tnames = String["
    highAStr = "\n\thighA = Float64["
    highBStr = "\n\thighB = Float64["
    highCStr = "\n\thighC = Float64["
    highDStr = "\n\thighD = Float64["
    highEStr = "\n\thighE = Float64["
    highFStr = "\n\thighF = Float64["
    highGStr = "\n\thighG = Float64["
    lowAStr = "\n\tlowA = Float64["
    lowBStr = "\n\tlowB = Float64["
    lowCStr = "\n\tlowC = Float64["
    lowDStr = "\n\tlowD = Float64["
    lowEStr = "\n\tlowE = Float64["
    lowFStr = "\n\tlowF = Float64["
    lowGStr = "\n\tlowG = Float64["

    for j in 1:NC_thermo
        if getindex(names_transport,1) == getindex(names_thermo,j)
            nameStr = string(nameStr,"\"",getindex(names_transport,j),"\",\n")
            highAStr = string(highAStr,getindex(highA,j),",\n")
            highBStr = string(highBStr,getindex(highB,j),",\n")
            highCStr = string(highCStr,getindex(highC,j),",\n")
            highDStr = string(highDStr,getindex(highD,j),",\n")
            highEStr = string(highEStr,getindex(highE,j),",\n")
            highFStr = string(highFStr,getindex(highF,j),",\n")
            highGStr = string(highGStr,getindex(highG,j),",\n")
            lowAStr = string(lowAStr,getindex(lowA,j),",\n")
            lowBStr = string(lowBStr,getindex(lowB,j),",\n")
            lowCStr = string(lowCStr,getindex(lowC,j),",\n")
            lowDStr = string(lowDStr,getindex(lowD,j),",\n")
            lowEStr = string(lowEStr,getindex(lowE,j),",\n")
            lowFStr = string(lowFStr,getindex(lowF,j),",\n")
            lowGStr = string(lowGStr,getindex(lowG,j),",\n")
        end
    end


    for i in 2:NC_transport - 1
        for j in 1:NC_thermo
            if getindex(names_transport,i) == getindex(names_thermo,j)
                nameStr = string(nameStr,"\t               \"",getindex(names_transport,j),"\",\n")
                highAStr = string(highAStr,"\t                ",getindex(highA,j),",\n")
                highBStr = string(highBStr,"\t                ",getindex(highB,j),",\n")
                highCStr = string(highCStr,"\t                ",getindex(highC,j),",\n")
                highDStr = string(highDStr,"\t                ",getindex(highD,j),",\n")
                highEStr = string(highEStr,"\t                ",getindex(highE,j),",\n")
                highFStr = string(highFStr,"\t                ",getindex(highF,j),",\n")
                highGStr = string(highGStr,"\t                ",getindex(highG,j),",\n")
                lowAStr = string(lowAStr,"\t                ",getindex(lowA,j),",\n")
                lowBStr = string(lowBStr,"\t                ",getindex(lowB,j),",\n")
                lowCStr = string(lowCStr,"\t                ",getindex(lowC,j),",\n")
                lowDStr = string(lowDStr,"\t                ",getindex(lowD,j),",\n")
                lowEStr = string(lowEStr,"\t                ",getindex(lowE,j),",\n")
                lowFStr = string(lowFStr,"\t                ",getindex(lowF,j),",\n")
                lowGStr = string(lowGStr,"\t                ",getindex(lowG,j),",\n")
            end
        end
    end

    for j in 1:NC_thermo
        if getindex(names_transport,NC_transport) == getindex(names_thermo,j)
            nameStr = string(nameStr,"\t               \"",getindex(names_transport,j),"\"]\n")
            highAStr = string(highAStr,"\t                ",getindex(highA,j),"]\n")
            highBStr = string(highBStr,"\t                ",getindex(highB,j),"]\n")
            highCStr = string(highCStr,"\t                ",getindex(highC,j),"]\n")
            highDStr = string(highDStr,"\t                ",getindex(highD,j),"]\n")
            highEStr = string(highEStr,"\t                ",getindex(highE,j),"]\n")
            highFStr = string(highFStr,"\t                ",getindex(highF,j),"]\n")
            highGStr = string(highGStr,"\t                ",getindex(highG,j),"]\n")
            lowAStr = string(lowAStr,"\t                ",getindex(lowA,j),"]\n")
            lowBStr = string(lowBStr,"\t                ",getindex(lowB,j),"]\n")
            lowCStr = string(lowCStr,"\t                ",getindex(lowC,j),"]\n")
            lowDStr = string(lowDStr,"\t                ",getindex(lowD,j),"]\n")
            lowEStr = string(lowEStr,"\t                ",getindex(lowE,j),"]\n")
            lowFStr = string(lowFStr,"\t                ",getindex(lowF,j),"]\n")
            lowGStr = string(lowGStr,"\t                ",getindex(lowG,j),"]\n")
        end
    end


    write(io, nameStr)
    write(io, highAStr)
    write(io, highBStr)
    write(io, highCStr)
    write(io, highDStr)
    write(io, highEStr)
    write(io, highFStr)
    write(io, highGStr)
    write(io, lowAStr)
    write(io, lowBStr)
    write(io, lowCStr)
    write(io, lowDStr)
    write(io, lowEStr)
    write(io, lowFStr)
    write(io, lowGStr)

    write(io, "\n\tfunction update()\n")
    write(io, string("\t\treturn Thermo(",string(NC_transport),",names,highA,highB,highC,highD,highE,highF,highG,lowA,lowB,lowC,lowD,lowE,lowF,lowG)\n"))
    write(io, "\tend\n")
    write(io, "end")

    close(io)
end

function write_transport()
    NC, names , geometry, LJpotential, LJdiameter, dipole, polar, collision, MW = read_transport()

    path = joinpath(@__DIR__, "transportDatabase.jl")
    io = open(path, "w")

    heading = get_heading()

    write(io, heading)
    write(io, "module transportDatabase\n")
    write(io, "\tstruct Transport\n")
    write(io, "\t\tNC::Int64\n")
    write(io, "\t\tname::Array{String}\n")
    write(io, "\t\tgeometry::Vector{Int64}\n")
    write(io, "\t\tLJpotential::Vector{Float64}\n")
    write(io, "\t\tLJdiameter::Vector{Float64}\n")
    write(io, "\t\tdipole::Vector{Float64}\n")
    write(io, "\t\tpolar::Vector{Float64}\n")
    write(io, "\t\tcollision::Vector{Float64}\n")
    write(io, "\t\tMW::Vector{Float64}\n")
    write(io, "\tend\n\n")

    nameStr        = "\n\tnames = String["
    geometryStr    = "\n\tgeometry = Int64["
    LJpotentialStr = "\n\tLJpotential = Float64["
    LJdiameterStr  = "\n\tLJdiameter = Float64["
    dipoleStr      = "\n\tdipole = Float64["
    polarStr       = "\n\tpolar = Float64["
    collisionStr   = "\n\tcollision = Float64["
    MWStr          = "\n\tMW = Float64["

    nameStr = string(nameStr,"\"",getindex(names,1),"\",\n")
    geometryStr = string(geometryStr,getindex(geometry,1),",\n")
    LJpotentialStr = string(LJpotentialStr,getindex(LJpotential,1),",\n")
    LJdiameterStr = string(LJdiameterStr,getindex(LJdiameter,1),",\n")
    dipoleStr = string(dipoleStr,getindex(dipole,1),",\n")
    polarStr = string(polarStr,getindex(polar,1),",\n")
    collisionStr = string(collisionStr,getindex(collision,1),",\n")
    MWStr = string(MWStr,getindex(MW,1),",\n")

    for i in 2:NC - 1
        nameStr = string(nameStr,"\t               \"",getindex(names,i),"\",\n")
        geometryStr = string(geometryStr,"\t                 ",getindex(geometry,i),",\n")
        LJpotentialStr = string(LJpotentialStr,"\t                      ",getindex(LJpotential,i),",\n")
        LJdiameterStr = string(LJdiameterStr,"\t                     ",getindex(LJdiameter,i),",\n")
        dipoleStr = string(dipoleStr,"\t                 ",getindex(dipole,i),",\n")
        polarStr = string(polarStr,"\t                ",getindex(polar,i),",\n")
        collisionStr = string(collisionStr,"\t                    ",getindex(collision,i),",\n")
        MWStr = string(MWStr,"\t             ",getindex(MW,i),",\n")
    end

    nameStr = string(nameStr,"\t               \"",getindex(names,NC),"\"]\n")
    geometryStr = string(geometryStr,"\t                 ",getindex(geometry,NC),"]\n")
    LJpotentialStr = string(LJpotentialStr,"\t                      ",getindex(LJpotential,NC),"]\n")
    LJdiameterStr = string(LJdiameterStr,"\t                     ",getindex(LJdiameter,NC),"]\n")
    dipoleStr = string(dipoleStr,"\t                 ",getindex(dipole,NC),"]\n")
    polarStr = string(polarStr,"\t                ",getindex(polar,NC),"]\n")
    collisionStr = string(collisionStr,"\t                    ",getindex(collision,NC),"]\n")
    MWStr = string(MWStr,"\t             ",getindex(MW,NC),"]\n")

    write(io, nameStr)
    write(io, geometryStr)
    write(io, LJpotentialStr)
    write(io, LJdiameterStr)
    write(io, dipoleStr)
    write(io, polarStr)
    write(io, collisionStr)
    write(io, MWStr)

    write(io, "\n\tfunction update()\n")
    write(io, string("\t\treturn Transport(",string(NC),",names,geometry,LJpotential,LJdiameter,dipole,polar,collision,MW)\n"))
    write(io, "\tend\n")
    write(io, "end")


    close(io)
    return NC, names
end

function write_omega()
    d22, T22, s22 = read_omega("../database/omega22.asali")
    d11, T11, s11 = read_omega("../database/astar.asali")
    path = joinpath(@__DIR__, "omegaDatabase.jl")
    io = open(path, "w")

    heading = get_heading()
    write(io, heading)
    write(io, "module omegaDatabase\n")
    write(io, "\tstruct Omega\n")
    write(io, "\t\tT::Vector{Float64}\n")
    write(io, "\t\td::Vector{Float64}\n")
    write(io, "\t\ts::Matrix{Float64}\n")
    write(io, "\tend\n\n")


    d11str = "\n\td11 = Float64["
    T11str = "\n\tT11 = Float64["
    s11str = "\n\ts11 = ["
    d22str = "\n\td22 = Float64["
    T22str = "\n\tT22 = Float64["
    s22str = "\n\ts22 = ["

    d11str = string(d11str,getindex(d11,1),",")
    d22str = string(d22str,getindex(d22,1),",")
    for j in 2:size(d11,1)-1
        d11str = string(d11str,getindex(d11,j),",")
        d22str = string(d22str,getindex(d22,j),",")
    end
    d11str = string(d11str,getindex(d11,size(d11,1)),"]\n")
    d22str = string(d22str,getindex(d22,size(d22,1)),"]\n")

    T11str = string(T11str,getindex(T11,1),",\n")
    T22str = string(T22str,getindex(T22,1),",\n")
    for j in 2:size(T11,1)-1
        T11str = string(T11str,"\t              ",getindex(T11,j),",\n")
        T22str = string(T22str,"\t              ",getindex(T22,j),",\n")
    end
    T11str = string(T11str,"\t              ",getindex(T11,size(T11,1)),"]\n")
    T22str = string(T22str,"\t              ",getindex(T22,size(T22,1)),"]\n")

    s11str = string(s11str,getindex(s22,1,1)/getindex(s11,1,1)," ")
    s22str = string(s22str,getindex(s22,1,1)," ")
    for j in 2:size(d11,1)-1
        s11str = string(s11str,getindex(s22,1,j)/getindex(s11,1,j)," ")
        s22str = string(s22str,getindex(s22,1,j)," ")
    end
    s11str = string(s11str,getindex(s22,1,size(d22,1))/getindex(s11,1,size(d11,1)),";\n")
    s22str = string(s22str,getindex(s22,1,size(d22,1)),";\n")

    for i in 2:size(T11,1)-1
        s11str = string(s11str,"\t       ")
        s22str = string(s22str,"\t       ")
        for j in 1:size(d11,1)-1
            s11str = string(s11str,getindex(s22,i,j)/getindex(s11,i,j)," ")
            s22str = string(s22str,getindex(s22,i,j)," ")
        end
        s11str = string(s11str,getindex(s22,i,size(d22,1))/getindex(s11,i,size(d11,1)),";\n")
        s22str = string(s22str,getindex(s22,i,size(d22,1)),";\n")
    end

    s11str = string(s11str,"\t       ")
    s22str = string(s22str,"\t       ")
    for j in 1:size(d11,1)-1
        s11str = string(s11str,getindex(s22,size(T22,1),j)/getindex(s11,size(T11,1),j)," ")
        s22str = string(s22str,getindex(s22,size(T22,1),j)," ")
    end
    s11str = string(s11str,getindex(s22,size(T22,1),size(d22,1))/getindex(s11,size(T11,1),size(d11,1)),"]\n")
    s22str = string(s22str,getindex(s22,size(T22,1),size(d22,1)),"]\n")

    write(io, d11str)
    write(io, T11str)
    write(io, d22str)
    write(io, T22str)

    write(io, s11str)
    write(io, s22str)

    write(io, "\n\tfunction update()\n")
    write(io, "\t\treturn Omega(T11,d11,s11), Omega(T22,d22,s22)\n")
    write(io, "\tend\n")
    write(io, "end")

    close(io)
end

function write_all_files()
    NC_transport, names_transport = write_transport()
    write_thermo(NC_transport, names_transport)
    write_omega()
end

print("\nASALI::Generating database modules...")
write_all_files()
print("...done!\n")
