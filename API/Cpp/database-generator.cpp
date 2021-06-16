/*##############################################################################################
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
##############################################################################################*/

// C++
#include <string>
#include <iostream>
#include <math.h>
#include <ctime>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::string> namesFromTransport;
    {
        std::ifstream transport("../database/transport.asali");

        std::string                line;
        std::vector<std::string>   all;
        if (transport.is_open())
        {
            while ( getline (transport,line) )
            {
                if (!line.empty())
                {
                    std::size_t pos = line.find("#");
                    if (pos != 0)
                    {
                        all.push_back(line);
                    }
                }
            }
            transport.close();
            
            unsigned int                           counter = 0;
            std::vector<std::vector<std::string> > allv(all.size());
            
            for (unsigned int i=0;i<all.size();i++)
            {
                line = all[i];
                std::istringstream iss(line);
                while (iss >> line)
                {
                    allv[i].push_back(line);
                    counter++;
                }

                if ( counter == 8 )
                {
                    counter = 0;
                }
                else
                {
                    std::cout << "\nASALI::error" << std::endl;
                    std::cout << "database/transport.asali missing parameter in line:\n" << std::endl;
                    std::cout << all[i] << "\n" << std::endl;
                    exit(EXIT_FAILURE);
                }
            }
            
            
            for (unsigned int i=0;i<allv.size();i++)
            {
                if ( std::stoi(allv[i][1]) > 2 )
                {
                    std::cout << "\nASALI::error" << std::endl;
                    std::cout << "database/transport.asali second paramter should be || 0 || 1 || 2 || in line:\n" << std::endl;
                    std::cout << all[i] << "\n" << std::endl;
                    exit(EXIT_FAILURE);
                }
            }

            remove("shared/transport.H");
            std::ofstream output;
            output.open("shared/transport.H",std::ios::out);
            output << "/*##############################################################################################" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#     #############       #############       #############       ####                ####     #" << std::endl;
            output << "#    #             #     #             #     #             #     #    #              #    #    #" << std::endl;
            output << "#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #" << std::endl;
            output << "#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #" << std::endl;
            output << "#    #    #####    #     #    #              #    #####    #     #    #              #    #    #" << std::endl;
            output << "#    #             #     #    #########      #             #     #    #              #    #    #" << std::endl;
            output << "#    #             #     #             #     #             #     #    #              #    #    #" << std::endl;
            output << "#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #" << std::endl;
            output << "#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #" << std::endl;
            output << "#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #" << std::endl;
            output << "#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #" << std::endl;
            output << "#     ####     ####       #############       ####     ####       #############       ####     #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "################################################################################################" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   License                                                                                    #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   This file is part of ASALI.                                                                #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   ASALI is free software: you can redistribute it and/or modify                              #" << std::endl;
            output << "#   it under the terms of the GNU General Public License as published by                       #" << std::endl;
            output << "#   the Free Software Foundation, either version 3 of the License, or                          #" << std::endl;
            output << "#   (at your option) any later version.                                                        #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   ASALI is distributed in the hope that it will be useful,                                   #" << std::endl;
            output << "#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #" << std::endl;
            output << "#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #" << std::endl;
            output << "#   GNU General Public License for more details.                                               #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   You should have received a copy of the GNU General Public License                          #" << std::endl;
            output << "#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "##############################################################################################*/" << std::endl;
            output << " " << std::endl;
            for (unsigned int i=0;i<allv.size();i++)
            {
                allv[i][0].erase(std::remove_if(allv[i][0].begin(),allv[i][0].end(),[]( char c ) { return !std::isalnum(c) ; } ), allv[i][0].end() ); 
                output << "{" << std::endl;
                output << "\ttransport_.name.push_back(\"" << allv[i][0] << "\");" << std::endl;
                output << "\ttransport_.geometry.push_back(" << std::stoi(allv[i][1]) << ");" << std::endl;
                output << "\ttransport_.LJpotential.push_back(" << allv[i][2] << ");" << std::endl;
                output << "\ttransport_.LJdiameter.push_back(" << allv[i][3] << ");" << std::endl;
                output << "\ttransport_.dipole.push_back(" << allv[i][4] << ");" << std::endl;
                output << "\ttransport_.polar.push_back(" << allv[i][5] << ");" << std::endl;
                output << "\ttransport_.collision.push_back(" << allv[i][6] << ");" << std::endl;
                output << "\ttransport_.MW.push_back(" << allv[i][7] << ");" << std::endl;
                output << "}" << std::endl;
                output << " " << std::endl;
                allv[i][0].erase(std::remove(allv[i][0].begin(),allv[i][0].end(),' '),allv[i][0].end());
                namesFromTransport.push_back(allv[i][0]);
            }
            output.close();
        }
        else
        {
            std::cout << "\nASALI::error" << std::endl;
            std::cout << "database/transport.tra is missing!\n" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    std::vector<std::vector<std::string> > omega22;
    {
        std::ifstream transport("../database/omega22.asali");

        std::string                line;
        std::vector<std::string>   all;
        if (transport.is_open())
        {
            while ( getline (transport,line) )
            {
                if (!line.empty())
                {
                    std::size_t pos = line.find("#");
                    if (pos != 0)
                    {
                        all.push_back(line);
                    }
                }
            }
            transport.close();
            
            unsigned int                           counter = 0;
            std::vector<std::vector<std::string> > allv(all.size());
            omega22.resize(all.size());

            for (unsigned int i=0;i<all.size();i++)
            {
                line = all[i];
                std::istringstream iss(line);
                while (iss >> line)
                {
                    allv[i].push_back(line);
                    counter++;
                }
                omega22[i] = allv[i];
            }

            remove("shared/omega22.H");
            std::ofstream output;
            output.open("shared/omega22.H",std::ios::out);
            output << "/*##############################################################################################" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#     #############       #############       #############       ####                ####     #" << std::endl;
            output << "#    #             #     #             #     #             #     #    #              #    #    #" << std::endl;
            output << "#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #" << std::endl;
            output << "#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #" << std::endl;
            output << "#    #    #####    #     #    #              #    #####    #     #    #              #    #    #" << std::endl;
            output << "#    #             #     #    #########      #             #     #    #              #    #    #" << std::endl;
            output << "#    #             #     #             #     #             #     #    #              #    #    #" << std::endl;
            output << "#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #" << std::endl;
            output << "#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #" << std::endl;
            output << "#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #" << std::endl;
            output << "#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #" << std::endl;
            output << "#     ####     ####       #############       ####     ####       #############       ####     #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "################################################################################################" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   License                                                                                    #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   This file is part of ASALI.                                                                #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   ASALI is free software: you can redistribute it and/or modify                              #" << std::endl;
            output << "#   it under the terms of the GNU General Public License as published by                       #" << std::endl;
            output << "#   the Free Software Foundation, either version 3 of the License, or                          #" << std::endl;
            output << "#   (at your option) any later version.                                                        #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   ASALI is distributed in the hope that it will be useful,                                   #" << std::endl;
            output << "#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #" << std::endl;
            output << "#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #" << std::endl;
            output << "#   GNU General Public License for more details.                                               #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   You should have received a copy of the GNU General Public License                          #" << std::endl;
            output << "#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "##############################################################################################*/" << std::endl;
            output << " " << std::endl;
            output << "{" << std::endl;
            for (unsigned int j=1;j<allv[0].size();j++)
            {
                output << "\tdsigma22_.push_back(" << allv[0][j] << ");" << std::endl;
            }
            output << "}" << std::endl;
            output << " " << std::endl;
            output << "{" << std::endl;
            for (unsigned int j=1;j<allv.size();j++)
            {
                output << "\tTsigma22_.push_back(" << allv[j][0] << ");" << std::endl;
            }
            output << "}" << std::endl;
            output << " " << std::endl;
            output << " " << std::endl;
            output << "sigmaMatrix22_.resize(" << allv.size()-1 << ");" << std::endl;
            output << "{" << std::endl;
            for (unsigned int i=1;i<allv.size();i++)
            {
                for (unsigned int j=1;j<allv[i].size();j++)
                {
                    output << "\tsigmaMatrix22_[" << i - 1 << "].push_back(" << allv[i][j] << ");" << std::endl;
                }
                output << " " << std::endl;
            }
            output << "}" << std::endl;
            output << " " << std::endl;
            output.close();
        }
        else
        {
            std::cout << "\nASALI::error" << std::endl;
            std::cout << "database/omega22.asali is missing!\n" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    {
        std::ifstream transport("../database/astar.asali");

        std::string                line;
        std::vector<std::string>   all;
        if (transport.is_open())
        {
            while ( getline (transport,line) )
            {
                if (!line.empty())
                {
                    std::size_t pos = line.find("#");
                    if (pos != 0)
                    {
                        all.push_back(line);
                    }
                }
            }
            transport.close();
            
            unsigned int                           counter = 0;
            std::vector<std::vector<std::string> > allv(all.size());
            
            for (unsigned int i=0;i<all.size();i++)
            {
                line = all[i];
                std::istringstream iss(line);
                while (iss >> line)
                {
                    allv[i].push_back(line);
                    counter++;
                }
            }

            remove("shared/omega11.H");
            std::ofstream output;
            output.open("shared/omega11.H",std::ios::out);
            output << "/*##############################################################################################" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#     #############       #############       #############       ####                ####     #" << std::endl;
            output << "#    #             #     #             #     #             #     #    #              #    #    #" << std::endl;
            output << "#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #" << std::endl;
            output << "#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #" << std::endl;
            output << "#    #    #####    #     #    #              #    #####    #     #    #              #    #    #" << std::endl;
            output << "#    #             #     #    #########      #             #     #    #              #    #    #" << std::endl;
            output << "#    #             #     #             #     #             #     #    #              #    #    #" << std::endl;
            output << "#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #" << std::endl;
            output << "#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #" << std::endl;
            output << "#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #" << std::endl;
            output << "#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #" << std::endl;
            output << "#     ####     ####       #############       ####     ####       #############       ####     #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "################################################################################################" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   License                                                                                    #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   This file is part of ASALI.                                                                #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   ASALI is free software: you can redistribute it and/or modify                              #" << std::endl;
            output << "#   it under the terms of the GNU General Public License as published by                       #" << std::endl;
            output << "#   the Free Software Foundation, either version 3 of the License, or                          #" << std::endl;
            output << "#   (at your option) any later version.                                                        #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   ASALI is distributed in the hope that it will be useful,                                   #" << std::endl;
            output << "#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #" << std::endl;
            output << "#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #" << std::endl;
            output << "#   GNU General Public License for more details.                                               #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   You should have received a copy of the GNU General Public License                          #" << std::endl;
            output << "#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "##############################################################################################*/" << std::endl;
            output << " " << std::endl;
            output << "{" << std::endl;
            for (unsigned int j=1;j<allv[0].size();j++)
            {
                output << "\tdsigma11_.push_back(" << allv[0][j] << ");" << std::endl;
            }
            output << "}" << std::endl;
            output << " " << std::endl;
            output << "{" << std::endl;
            for (unsigned int j=1;j<allv.size();j++)
            {
                output << "\tTsigma11_.push_back(" << allv[j][0] << ");" << std::endl;
            }
            output << "}" << std::endl;
            output << " " << std::endl;
            output << "sigmaMatrix11_.resize(" << allv.size() << ");" << std::endl;
            output << "{" << std::endl;
            for (unsigned int i=1;i<allv.size();i++)
            {
                for (unsigned int j=1;j<allv[i].size();j++)
                {
                    output << "\tsigmaMatrix11_[" << i - 1 << "].push_back(" << omega22[i][j] << "/" << allv[i][j] << ");" << std::endl;
                }
                output << " " << std::endl;
            }
            output << "}" << std::endl;
            output << " " << std::endl;
            output.close();
        }
        else
        {
            std::cout << "\nASALI::error" << std::endl;
            std::cout << "../database/astar.asali is missing!\n" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    {
        std::ifstream thermo("../database/thermo.asali");

        std::string                line;
        std::vector<std::string>   all;
        if (thermo.is_open())
        {
            while ( getline (thermo,line) )
            {
                if (!line.empty())
                {
                    std::size_t pos = line.find("#");
                    if (pos != 0)
                    {
                        all.push_back(line);
                    }
                }
            }
            thermo.close();
            
            
            if ( all.size()%4 != 0 )
            {
                std::cout << "\nASALI::error" << std::endl;
                std::cout << "the number of line in the database/thermo.asali is wrong\n" << std::endl;
                exit(EXIT_FAILURE);
            }
            
            unsigned int                                         nameCounter = 0;
            std::vector<std::vector<std::vector<std::string> > > allv(int(all.size()/4));
            std::vector<std::string>                             name(int(all.size()/4));
            
            for (unsigned int i=0;i<all.size();i = i + 4)
            {
                //Name
                {
                    name[nameCounter] = all[i];
                    name[nameCounter].erase(std::remove_if(name[nameCounter].begin(),name[nameCounter].end(),[]( char c ) { return !std::isalnum(c) ; } ), name[nameCounter].end() ); 
                }
                
                allv[nameCounter].resize(3);
                
                for (unsigned k=0;k<3;k++)
                {
                    line = all[i+k+1];
                    
                    std::istringstream iss(line);
                    while (iss >> line)
                    {
                        allv[nameCounter][k].push_back(line);
                    }
                }
                allv[nameCounter][2].push_back("none");
                nameCounter++;
            }
            

            {
                std::vector<bool> check(namesFromTransport.size());
                
                for (unsigned int i=0;i<namesFromTransport.size();i++)
                {
                    check[i] = false;
                    for (unsigned int k=0;k<name.size();k++)
                    {
                        if ( namesFromTransport[i] == name[k] )
                        {
                            check[i] = true;
                            break;
                        }
                    }
                }

                for (unsigned int i=0;i<namesFromTransport.size();i++)
                {
                    if ( check[i] == false )
                    {
                        std::cout << "\nASALI::error" << std::endl;
                        std::cout << "specie " << namesFromTransport[i] << " is missing in the database/thermo.asali!\n" << std::endl;
                        exit(EXIT_FAILURE);
                    }
                }
            }
            
            
            remove("shared/thermo.H");
            std::ofstream output;
            output.open("shared/thermo.H",std::ios::out);
            output << "/*##############################################################################################" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#     #############       #############       #############       ####                ####     #" << std::endl;
            output << "#    #             #     #             #     #             #     #    #              #    #    #" << std::endl;
            output << "#    #    #####    #     #    #########      #    #####    #     #    #              #    #    #" << std::endl;
            output << "#    #    #   #    #     #    #              #    #   #    #     #    #              #    #    #" << std::endl;
            output << "#    #    #####    #     #    #              #    #####    #     #    #              #    #    #" << std::endl;
            output << "#    #             #     #    #########      #             #     #    #              #    #    #" << std::endl;
            output << "#    #             #     #             #     #             #     #    #              #    #    #" << std::endl;
            output << "#    #    #####    #      #########    #     #    #####    #     #    #              #    #    #" << std::endl;
            output << "#    #    #   #    #              #    #     #    #   #    #     #    #              #    #    #" << std::endl;
            output << "#    #    #   #    #      #########    #     #    #   #    #     #    #########      #    #    #" << std::endl;
            output << "#    #    #   #    #     #             #     #    #   #    #     #             #     #    #    #" << std::endl;
            output << "#     ####     ####       #############       ####     ####       #############       ####     #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   Author: Stefano Rebughini <ste.rebu@outlook.it>                                            #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "################################################################################################" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   License                                                                                    #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   This file is part of ASALI.                                                                #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   ASALI is free software: you can redistribute it and/or modify                              #" << std::endl;
            output << "#   it under the terms of the GNU General Public License as published by                       #" << std::endl;
            output << "#   the Free Software Foundation, either version 3 of the License, or                          #" << std::endl;
            output << "#   (at your option) any later version.                                                        #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   ASALI is distributed in the hope that it will be useful,                                   #" << std::endl;
            output << "#   but WITHOUT ANY WARRANTY; without even the implied warranty of                             #" << std::endl;
            output << "#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                              #" << std::endl;
            output << "#   GNU General Public License for more details.                                               #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "#   You should have received a copy of the GNU General Public License                          #" << std::endl;
            output << "#   along with ASALI. If not, see <http://www.gnu.org/licenses/>.                              #" << std::endl;
            output << "#                                                                                              #" << std::endl;
            output << "##############################################################################################*/" << std::endl;
            output << " " << std::endl;

            output << "{" << std::endl;
            output << "\tthermo_.high.resize(" << name.size() << ");" << std::endl;
            output << "\tthermo_.low.resize(" << name.size() << ");" << std::endl;
            output << "\tthermo_.name.resize(" << name.size() << ");" << std::endl;
            output << "}" << std::endl;
            output << " " << std::endl;
            for(unsigned int k=0;k<namesFromTransport.size();k++)
            {
                for(unsigned int i=0;i<name.size();i++)
                {
                    if ( name[i] == namesFromTransport[k] )
                    {
                        output << "{" << std::endl;
                        output << "\tthermo_.name[" << k << "] = \"" << name[i] << "\";" << std::endl;
                        output << "\tthermo_.high[" << k << "].push_back(" << allv[i][0][0] << ");" << std::endl;
                        output << "\tthermo_.high[" << k << "].push_back(" << allv[i][0][1] << ");" << std::endl;
                        output << "\tthermo_.high[" << k << "].push_back(" << allv[i][0][2] << ");" << std::endl;
                        output << "\tthermo_.high[" << k << "].push_back(" << allv[i][0][3] << ");" << std::endl;
                        output << "\tthermo_.high[" << k << "].push_back(" << allv[i][0][4] << ");" << std::endl;
                        output << "\tthermo_.high[" << k << "].push_back(" << allv[i][1][0] << ");" << std::endl;
                        output << "\tthermo_.high[" << k << "].push_back(" << allv[i][1][1] << ");" << std::endl;
                        output << "\tthermo_.low[" << k << "].push_back(" << allv[i][1][2] << ");" << std::endl;
                        output << "\tthermo_.low[" << k << "].push_back(" << allv[i][1][3] << ");" << std::endl;
                        output << "\tthermo_.low[" << k << "].push_back(" << allv[i][1][4] << ");" << std::endl;
                        output << "\tthermo_.low[" << k << "].push_back(" << allv[i][2][0] << ");" << std::endl;
                        output << "\tthermo_.low[" << k << "].push_back(" << allv[i][2][1] << ");" << std::endl;
                        output << "\tthermo_.low[" << k << "].push_back(" << allv[i][2][2] << ");" << std::endl;
                        output << "\tthermo_.low[" << k << "].push_back(" << allv[i][2][3] << ");" << std::endl;
                        output << "}" << std::endl;
                        output << " " << std::endl;
                        break;
                    }
                }
            }
            output << " " << std::endl;
            output.close();
        }
        else
        {
            std::cout << "\nASALI::error" << std::endl;
            std::cout << "database/thermo.asali is missing!\n" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
