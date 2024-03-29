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

#ifndef ASALIFILEMANAGER_H
#define ASALIFILEMANAGER_H

#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctime>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <limits>
#include <numeric>
#include <functional>
#include <gtk/gtk.h>

namespace ASALI
{
    /// Class that handles file opening/closing
    class asaliFileManager
    {
    public:
        /// Class constuctor
        asaliFileManager();

        /// Save file
        static std::string saveFile(gpointer window, std::string current_file_name);

        /// Open file
        static std::string openFile(gpointer window);

        /// Convert relative to absolute path
        static std::string relative_path_to_absolute_path(std::string relpath);

        /// Split string based on character
        static std::vector<std::string> splitString(std::string txt, std::string ch);

        /// Split path
        std::vector<std::string> splitPath(std::string path);

        /// Get Cantera interfaces
        static std::vector<std::string> getCanteraInterfaces(std::string filename);

        /// Get Cantera phase name from interface
        static std::string getCanteraPhaseName(std::string interfaceName);

        /// Remove extension from file path
        void removeFileExtension(std::string &filename, const std::string &extension);

    private:
        /// Remove substring from string
        void eraseSubString(std::string &mainStr, const std::string &toErase);
    };
}
#endif