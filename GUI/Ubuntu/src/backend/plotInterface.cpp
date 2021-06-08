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

#include "backend/plotInterface.hpp"

namespace ASALI
{
    #if ASALI_ON_WINDOW == 1
    plotInterface::plotInterface() : nFig_(-1),
                                     defaultTextColor_({255, 255, 235}),
                                     defaultBgColor_({0, 0, 0}),
                                     onScreenOutputFormats_({"wingcc", "wingid"})
    {
        _putenv_s("PLPLOT_LIB", "share/plplot5.15.0");
        _putenv_s("WININSTALLDIR", ".");
    }
    #else
    plotInterface::plotInterface() : nFig_(-1),
                                     defaultTextColor_({255, 255, 235}),
                                     defaultBgColor_({0, 0, 0}),
                                     onScreenOutputFormats_({"xcairo", "wxwidgets", "qtwidget"})
    {
    }
    #endif

    double plotInterface::maxElement(const std::vector<double> v)
    {
        double max = DBL_MIN;

        for (unsigned int i = 0; i < v.size(); i++)
            max = std::max(v[i], max);

        return max;
    }

    double plotInterface::minElement(const std::vector<double> v)
    {
        double min = DBL_MAX;

        for (unsigned int i = 0; i < v.size(); i++)
            min = std::min(v[i], min);

        return min;
    }

    int plotInterface::maxElement(const std::vector<int> v)
    {
        int max = INT_MIN;

        for (unsigned int i = 0; i < v.size(); i++)
            max = std::max(v[i], max);

        return max;
    }

    int plotInterface::minElement(const std::vector<int> v)
    {
        int min = INT_MAX;

        for (unsigned int i = 0; i < v.size(); i++)
            min = std::min(v[i], min);

        return min;
    }


    void plotInterface::setDefaultBackgroundColor(int r, int b, int g)
    {
        std::cout << defaultBgColor_.size() << std::endl;
        defaultBgColor_[0] = r;
        defaultBgColor_[1] = b;
        defaultBgColor_[2] = g;
    }

    void plotInterface::setDefaultTextColor(int r, int b, int g)
    {
        defaultTextColor_[0] = r;
        defaultTextColor_[1] = b;
        defaultTextColor_[2] = g;
    }

    void plotInterface::newFigure()
    {
        nFig_++;
        xLabel_.push_back("");
        yLabel_.push_back("");
        title_.push_back("");
        outputFormat_.push_back("?");
        isLegend_.push_back(false);
        isOnFile_.push_back(true);
        legendPosition_.push_back(PL_POSITION_TOP | PL_POSITION_OUTSIDE);
        optBase_.push_back(PL_LEGEND_BACKGROUND | PL_LEGEND_BOUNDING_BOX);
        nCol_.push_back(0);
        nRow_.push_back(0);
        nLegend_.push_back(0);
        legendWidth_.push_back(0.);
        legendHeight_.push_back(0.);
        xmax_.push_back(DBL_MIN);
        xmin_.push_back(DBL_MAX);
        ymax_.push_back(DBL_MIN);
        ymin_.push_back(DBL_MAX);
        textColor_.push_back(defaultTextColor_);
        bgColor_.push_back(defaultBgColor_);
        textColors_.push_back({0});
        lineColors_.push_back({0});
        lineStyles_.push_back({0});
        lineWidths_.push_back({0});
        optArray_.push_back({0});
        legendTextForSingleFigure_.clear();
        xForSingleFig_.clear();
        yForSingleFig_.clear();
    }

    void plotInterface::setXlimits(double xmax, double xmin)
    {
        if ( xmax == xmin )
        {
            xmin = 0.;
        }

        xmin_[nFig_] = std::min(xmin, xmin_[nFig_]);
        xmax_[nFig_] = std::max(xmax, xmax_[nFig_]);
    }

    void plotInterface::setYlimits(double ymax, double ymin)
    {
        if ( ymax == ymin )
        {
            ymin = 0.;
        }

        ymin_[nFig_] = std::min(ymin, ymin_[nFig_]);
        ymax_[nFig_] = std::max(ymax, ymax_[nFig_]);
    }

    void plotInterface::setXlabel(std::string xlabel)
    {
        xLabel_[nFig_] = xlabel;
    }

    void plotInterface::setYlabel(std::string ylabel)
    {
        yLabel_[nFig_] = ylabel;
    }

    void plotInterface::setTitle(std::string title)
    {
        title_[nFig_] = title;
    }

    void plotInterface::setTextColor(int r, int b, int g)
    {
        textColor_[nFig_][0] = r;
        textColor_[nFig_][1] = b;
        textColor_[nFig_][2] = g;
    }

    void plotInterface::setBackgroundColor(int r, int b, int g)
    {
        bgColor_[nFig_][0] = r;
        bgColor_[nFig_][1] = b;
        bgColor_[nFig_][2] = g;
    }

    void plotInterface::setData(std::vector<double> x, std::vector<double> y, std::string label)
    {
        xForSingleFig_.push_back(x);
        yForSingleFig_.push_back(y);
        legendTextForSingleFigure_.push_back(label);

        if ( (int)x_.size() == nFig_)
        {
            x_.push_back(xForSingleFig_);
        }
        else
        {
            x_[nFig_] = xForSingleFig_;
        }

        if ( (int)y_.size() == nFig_)
        {
            y_.push_back(yForSingleFig_);
        }
        else
        {
            y_[nFig_] = yForSingleFig_;
        }

        if ( (int)legendText_.size() == nFig_)
        {
            legendText_.push_back(legendTextForSingleFigure_);
        }
        else
        {
            legendText_[nFig_] = legendTextForSingleFigure_;
        }

        nLegend_[nFig_] = xForSingleFig_.size();

        this->setXlimits(this->maxElement(x), this->minElement(x));
        this->setYlimits(this->maxElement(y), this->minElement(y));
    }

    void plotInterface::setLegendPosition(const std::string position)
    {
        if (position == "top")
        {
            legendPosition_[nFig_] = PL_POSITION_OUTSIDE | PL_POSITION_TOP;
            nCol_[nFig_] = nLegend_[nFig_];
        }
        else if (position == "bottom")
        {
            legendPosition_[nFig_] = PL_POSITION_OUTSIDE | PL_POSITION_BOTTOM;
            nCol_[nFig_] = nLegend_[nFig_];
        }
        else if (position == "left")
        {
            legendPosition_[nFig_] = PL_POSITION_INSIDE | PL_POSITION_LEFT;
            nRow_[nFig_] = nLegend_[nFig_];
        }
        else if (position == "right")
        {
            legendPosition_[nFig_] = PL_POSITION_INSIDE | PL_POSITION_RIGHT;
            nRow_[nFig_] = nLegend_[nFig_];
        }
        else if (position == "left_top")
        {
            legendPosition_[nFig_] = PL_POSITION_INSIDE | PL_POSITION_LEFT | PL_POSITION_TOP;
            nRow_[nFig_] = nLegend_[nFig_];
        }
        else if (position == "right_top")
        {
            legendPosition_[nFig_] = PL_POSITION_INSIDE | PL_POSITION_RIGHT | PL_POSITION_TOP;
            nRow_[nFig_] = nLegend_[nFig_];
        }
        else if (position == "left_bottom")
        {
            legendPosition_[nFig_] = PL_POSITION_INSIDE | PL_POSITION_LEFT | PL_POSITION_BOTTOM;
            nRow_[nFig_] = nLegend_[nFig_];
        }
        else if (position == "right_bottom")
        {
            legendPosition_[nFig_] = PL_POSITION_INSIDE | PL_POSITION_RIGHT | PL_POSITION_BOTTOM;
            nRow_[nFig_] = nLegend_[nFig_];
        }
        else
        {
            nCol_[nFig_] = nLegend_[nFig_];
        }
    }
    
    void plotInterface::setLegendGrid(int ncol, int nrow)
    {
        nCol_[nFig_] = ncol;
        nRow_[nFig_] = nrow;
    }

    void plotInterface::setOutputFormat(std::string outputFormat)
    {
        outputFormat_[nFig_] = outputFormat;
        for (unsigned int i = 0; i < onScreenOutputFormats_.size(); i++)
        {
            if (outputFormat_[nFig_] == onScreenOutputFormats_[i])
            {
                isOnFile_[nFig_] = false;
                break;
            }
        }
    }

    void plotInterface::setOutputFileName(std::string fileName)
    {
        fileName_[nFig_] = fileName;
    }

    void plotInterface::legend()
    {
        isLegend_[nFig_] = true;

        textColors_[nFig_].resize(nLegend_[nFig_]);

        lineColors_[nFig_].resize(nLegend_[nFig_]);
        lineStyles_[nFig_].resize(nLegend_[nFig_]);
        lineWidths_[nFig_].resize(nLegend_[nFig_]);

        optArray_[nFig_].resize(nLegend_[nFig_]);

        for (int i = 0; i < nLegend_[nFig_]; i++)
        {
            textColors_[nFig_][i] = 1;
            lineColors_[nFig_][i] = i + 2;
            lineStyles_[nFig_][i] = 1;
            lineWidths_[nFig_][i] = 1.0;
            optArray_[nFig_][i] = PL_LEGEND_LINE;
        }
    }

    void plotInterface::show()
    {
        pls.resize(nFig_ + 1);
        for (int i=0; i<=nFig_; i++)
        {
            pls[i] = new plstream();
            this->initialize(pls[i], i);
            this->plot(pls[i], i);
        } 

        for (int i=0; i<=nFig_; i++)
        {
            delete pls[i];            
        }

        pls.clear();
    }

    void plotInterface::convertToPLFLT(std::vector<double> v, PLFLT *p)
    {
        for (unsigned int i = 0; i < v.size(); i++)
        {
            p[i] = v[i];
        }
    }

    void plotInterface::convertToPLINT(std::vector<int> v, PLINT *p)
    {
        for (unsigned int i = 0; i < v.size(); i++)
        {
            p[i] = v[i];
        }
    }

    void plotInterface::initialize(plstream *pls, int figIndex)
    {
        // Change Background Color
        pls->scolbg(bgColor_[figIndex][0], bgColor_[figIndex][1], bgColor_[figIndex][2]);

        // Set Text Color
        pls->scol0(1, textColor_[figIndex][0], textColor_[figIndex][1], textColor_[figIndex][2]);

        // Create output format
        pls->sdev(outputFormat_[figIndex].c_str());
        if (!fileName_.empty())
        {
            if (!fileName_[figIndex].empty() && isOnFile_[figIndex])
            {
                pls->sfnam(fileName_[figIndex].c_str());
            }
        }

        // Parse and process command line arguments
        pls->init();
    }

    void plotInterface::plot(plstream *pls, int figIndex)
    {
        // Create a labelled box to hold the plot.
        pls->env(xmin_[figIndex], xmax_[figIndex], ymin_[figIndex], ymax_[figIndex], 0, 0);
        pls->lab(xLabel_[figIndex].c_str(), yLabel_[figIndex].c_str(), title_[figIndex].c_str());

        // Plot the data that was prepared above.
        for (int i = 0; i < nLegend_[figIndex]; i++)
        {
            PLFLT x[x_[figIndex][i].size()];

            this->convertToPLFLT(x_[figIndex][i], x);
            PLFLT y[y_[figIndex][i].size()];
            this->convertToPLFLT(y_[figIndex][i], y);

            pls->col0(i + 2);
            pls->line(x_[figIndex][i].size(), x, y);
        }

        if (isLegend_[figIndex] == true)
        {
            PLINT opt_array[nLegend_[figIndex]];
            this->convertToPLINT(optArray_[figIndex], opt_array);

            std::vector<const char *> texts(nLegend_[figIndex]);
            for (int i = 0; i < nLegend_[figIndex]; i++)
            {
                texts[i] = legendText_[figIndex][i].c_str();
            }
            PLINT text_colors[nLegend_[figIndex]];
            this->convertToPLINT(textColors_[figIndex], text_colors);

            PLINT line_colors[nLegend_[figIndex]];
            this->convertToPLINT(lineColors_[figIndex], line_colors);
            PLINT line_styles[nLegend_[figIndex]];
            this->convertToPLINT(lineStyles_[figIndex], line_styles);
            PLFLT line_widths[nLegend_[figIndex]];
            this->convertToPLFLT(lineWidths_[figIndex], line_widths);

            pls->legend(&legendWidth_[figIndex],   //p_legend_width
                        &legendHeight_[figIndex],  //p_legend_height
                        optBase_[figIndex],        //opt
                        legendPosition_[figIndex], //position
                        0.05,                      //x
                        0.05,                      //y
                        0.1,                       //plot_width
                        0,                         //bg_color
                        0,                         //bb_color
                        1,                         //bb_style
                        nRow_[figIndex],           //nrow
                        nCol_[figIndex],           //ncolumn
                        nLegend_[figIndex],        //nlegend
                        opt_array,                 //opt_array
                        1.0,                       //text_offset
                        1.0,                       //text_scale
                        2.0,                       //text_spacing
                        1.,                        //test_justification
                        text_colors,               //text_colors
                        texts.data(),              //texts
                        NULL,                      //box_colors
                        NULL,                      //box_patterns
                        NULL,                      //box_scales
                        NULL,                      //box_line_widths
                        line_colors,               //line_colors
                        line_styles,               //line_styles
                        line_widths,               //line_widths
                        NULL,                      //symbol_colors
                        NULL,                      //symbol_scales
                        NULL,                      //symbol_numbers
                        NULL);                     //symbols
        }
    }

    plotInterface::~plotInterface()
    {
    }

}
