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

#ifndef PLOTINTERFACE_H
#define PLOTINTERFACE_H

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
#include <climits>
#include <numeric>
#include <functional>
#include <float.h>

#include "backend/asaliVectorUtils.hpp"
#include "plplot.h"
#include "plstream.h"

namespace ASALI
{
    /// Class to plot results based on Plplot (http://plplot.org/)
    class plotInterface
    {
    public:
        /// Class constructor
        plotInterface();

        /// Generate new figure
        void newFigure();

        /// Set data to be plotted: abscissa, ordinate, label
        void setData(std::vector<double> x, std::vector<double> y, std::string label);

        /// Set abscissa lower and upper limit
        void setXlimits(double xmin, double xmax);

        /// Set ordinate lower and upper limit
        void setYlimits(double ymin, double ymax);

        /// Set abscissa axis label
        void setXlabel(std::string xlabel);

        /// Set ordinate axis label
        void setYlabel(std::string ylabel);

        /// Set title
        void setTitle(std::string title);

        /// Set text color
        void setTextColor(int r, int b, int g);

        /// Set default text color
        void setDefaultTextColor(int r, int b, int g);

        /// Set background color
        void setBackgroundColor(int r, int b, int g);

        /// Set default background color
        void setDefaultBackgroundColor(int r, int b, int g);

        /// Set legend position
        void setLegendPosition(const std::string position);

        /// Set legend grid number of columns and rows
        void setLegendGrid(int ncol, int nrow);

        /// Set output format
        void setOutputFormat(const std::string outputFormat);

        /// Set output file name
        void setOutputFileName(const std::string fileName);

        /// Enable/Disable legend
        void legend();

        /// Show plots
        void show();

        /// Class destructor
        virtual ~plotInterface();

    private:
        /// Convert std::vector<double> to Plplot vector of float
        void convertToPLFLT(std::vector<double> v, PLFLT *p);

        /// Convert std::vector<int> to Plplot vector of int
        void convertToPLINT(std::vector<int> v, PLINT *p);

        /// Plot single figure from index
        void plot(plstream *pls, int figIndex);

        /// Initialize figure from index
        void initialize(plstream *pls, int figIndex);

        int nFig_; /// Number of figure counter

        std::string defaultGeometry_; /// Default geometry

        std::vector<plstream *> pls; /// Plplot object that represents the plot

        std::vector<int> nSize_;            /// Figure size
        std::vector<int> nLegend_;          /// Legends
        std::vector<int> defaultTextColor_; /// Default text color
        std::vector<int> defaultBgColor_;   /// Background text color

        std::vector<std::string> xLabel_;                    /// Abscissa axis label
        std::vector<std::string> yLabel_;                    /// Ordinate axis label
        std::vector<std::string> title_;                     /// Title
        std::vector<std::string> outputFormat_;              /// Output format
        std::vector<std::string> fileName_;                  /// Output file name
        std::vector<std::string> onScreenOutputFormats_;     /// On screen output format
        std::vector<std::string> legendTextForSingleFigure_; /// Legend text
        std::vector<std::string> geometry_;                  /// Geometry

        std::vector<bool> isLegend_; /// Enable/Disable legend
        std::vector<bool> isOnFile_; /// Enable/Disable output of file

        std::vector<PLINT> legendPosition_; /// Legend position
        std::vector<PLINT> optBase_;        /// Optimize position
        std::vector<PLINT> nCol_;           /// Number of columns
        std::vector<PLINT> nRow_;           /// Number of rows

        std::vector<PLFLT> xmax_;          /// Abscissa upper limit
        std::vector<PLFLT> xmin_;          /// Abscissa lower limit
        std::vector<PLFLT> ymax_;          /// Ordinate upper limit
        std::vector<PLFLT> ymin_;          /// Ordinate lower limit
        std::vector<PLFLT> legendWidth_;   /// Legend width
        std::vector<PLFLT> legendHeight_;  /// Legend height
        std::vector<PLFLT> legendXoffset_; /// Legend abscissa offset
        std::vector<PLFLT> legendYoffset_; /// Legend ordinate offset

        std::vector<std::vector<std::string>> legendText_; /// Legend color

        std::vector<std::vector<int>> textColors_; /// Text color
        std::vector<std::vector<int>> lineColors_; /// Line color
        std::vector<std::vector<int>> lineStyles_; /// Line style
        std::vector<std::vector<int>> optArray_;   /// Line optimization
        std::vector<std::vector<int>> textColor_;  /// Text color
        std::vector<std::vector<int>> bgColor_;    /// Background color

        std::vector<std::vector<double>> lineWidths_;    /// Line width
        std::vector<std::vector<double>> xForSingleFig_; /// Abscissa dataset
        std::vector<std::vector<double>> yForSingleFig_; /// Ordinate dataset

        std::vector<std::vector<std::vector<double>>> x_; /// Abscissa dataset
        std::vector<std::vector<std::vector<double>>> y_; /// Ordinate dataset

        ASALI::asaliVectorUtils vectorUtils_; /// Object to performe vector operations with std::vector
    };
}
#endif
