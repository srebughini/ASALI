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

#include "plplot.h"
#include "plstream.h"

namespace ASALI
{
    class plotInterface
    {
    public:
        plotInterface();

        void newFigure();
        void setData(std::vector<double> x, std::vector<double> y, std::string label);
        void setXlimits(double xmin, double xmax);
        void setYlimits(double ymin, double ymax);
        void setXlabel(std::string xlabel);
        void setYlabel(std::string ylabel);
        void setTitle(std::string title);
        void setTextColor(int r, int b, int g);
        void setBackgroundColor(int r, int b, int g);
        void setLegendPosition(const std::string position);
        void setOutputFormat(const std::string outputFormat);
        void setOutputFileName(const std::string fileName);
        void legend();
        void show();

        virtual ~plotInterface();

    private:
        void convertToPLFLT(std::vector<double> v, PLFLT *p);
        void convertToPLINT(std::vector<int> v, PLINT *p);
        void plot(plstream *pls, int figIndex);
        void initialize(plstream *pls, int figIndex);

        double minElement(const std::vector<double> v);
        double maxElement(const std::vector<double> v);

        int minElement(const std::vector<int> v);
        int maxElement(const std::vector<int> v);

        int nFig_;

        std::vector<plstream *> pls;

        std::vector<int> nSize_;
        std::vector<int> nLegend_;

        std::vector<std::string> xLabel_;
        std::vector<std::string> yLabel_;
        std::vector<std::string> title_;
        std::vector<std::string> outputFormat_;
        std::vector<std::string> fileName_;
        std::vector<std::string> onScreenOutputFormats_;
        std::vector<std::string> legendTextForSingleFigure_;

        std::vector<bool> isLegend_;
        std::vector<bool> isOnFile_;

        std::vector<PLINT> legendPosition_;
        std::vector<PLINT> optBase_;
        std::vector<PLINT> nCol_;
        std::vector<PLINT> nRow_;

        std::vector<PLFLT> xmax_;
        std::vector<PLFLT> xmin_;
        std::vector<PLFLT> ymax_;
        std::vector<PLFLT> ymin_;
        std::vector<PLFLT> legendWidth_;
        std::vector<PLFLT> legendHeight_;

        std::vector<std::vector<std::string>> legendText_;

        std::vector<std::vector<int>> textColors_;
        std::vector<std::vector<int>> lineColors_;
        std::vector<std::vector<int>> lineStyles_;
        std::vector<std::vector<int>> optArray_;
        std::vector<std::vector<int>> textColor_;
        std::vector<std::vector<int>> bgColor_;

        std::vector<std::vector<double>> lineWidths_;
        std::vector<std::vector<double>> xForSingleFig_;
        std::vector<std::vector<double>> yForSingleFig_;

        std::vector<std::vector<std::vector<double>>> x_;
        std::vector<std::vector<std::vector<double>>> y_;
    };
}
#endif
