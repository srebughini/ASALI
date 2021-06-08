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

#include "frontend/plot.hpp"

namespace ASALI
{
    plot::plot()
        : plotButton_("Plot"),
          exitButton_("Exit"),
          moleLabel_("Mole fraction"),
          massLabel_("Mass fraction"),
          siteLabel_("Coverage"),
          otherLabel_("Others"),
          NC_(0),
          SURF_NC_(0),
          NP_(0),
          MAX_COL_(4)
    {
        this->set_border_width(15);
        this->set_title("ASALI: plotting");
        this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
        this->set_icon_from_file(this->relative_path_to_absolute_path("images/Icon.png"));

        //Add background grid

        this->add(mainGrid_);

        mainGrid_.set_column_homogeneous(true);
        mainGrid_.set_column_spacing(10);
        mainGrid_.set_row_spacing(10);

        mainGrid_.attach(moleLabel_, 0, 0, 1, 1);
        mainGrid_.attach(moleGrid_, 0, 1, 1, 1);
        mainGrid_.attach(massLabel_, 0, 2, 1, 1);
        mainGrid_.attach(massGrid_, 0, 3, 1, 1);
        mainGrid_.attach(siteLabel_, 0, 4, 1, 1);
        mainGrid_.attach(siteGrid_, 0, 5, 1, 1);
        mainGrid_.attach(otherLabel_, 0, 6, 1, 1);
        mainGrid_.attach(otherGrid_, 0, 7, 1, 1);
        mainGrid_.attach(buttonBox_, 0, 8, 1, 1);

        moleGrid_.set_column_homogeneous(true);
        moleGrid_.set_column_spacing(10);
        moleGrid_.set_row_homogeneous(true);
        moleGrid_.set_row_spacing(10);

        massGrid_.set_column_homogeneous(true);
        massGrid_.set_column_spacing(10);
        massGrid_.set_row_homogeneous(true);
        massGrid_.set_row_spacing(10);

        otherGrid_.set_column_homogeneous(true);
        otherGrid_.set_column_spacing(10);
        otherGrid_.set_row_homogeneous(true);
        otherGrid_.set_row_spacing(10);

        otherGrid_.set_column_homogeneous(true);
        otherGrid_.set_column_spacing(10);
        otherGrid_.set_row_homogeneous(true);
        otherGrid_.set_row_spacing(10);

        buttonBox_.set_layout(Gtk::BUTTONBOX_CENTER);
        buttonBox_.set_spacing(10);
        buttonBox_.pack_start(plotButton_, Gtk::PACK_SHRINK);
        buttonBox_.pack_start(exitButton_, Gtk::PACK_SHRINK);
        plotButton_.signal_clicked().connect(sigc::mem_fun(*this, &plot::runPlot));
        exitButton_.signal_clicked().connect(sigc::mem_fun(*this, &plot::exit));
    }

    void plot::build()
    {
        unsigned int row = 0;
        unsigned int column = 0;
        moleButton_.clear();
        massButton_.clear();
        siteButton_.clear();
        otherButton_.clear();
        for (unsigned int i = 0; i < NC_; i++)
        {
            if (column == 5)
            {
                column = 0;
                row++;
            }
            moleButton_.push_back(new Gtk::CheckButton(n_[i]));
            moleGrid_.attach(*moleButton_[i], column, row, 1, 1);
            massButton_.push_back(new Gtk::CheckButton(n_[i]));
            massGrid_.attach(*massButton_[i], column, row, 1, 1);
            column++;
        }

        if (SURF_NC_ == 0)
        {
            mainGrid_.remove(siteLabel_);
            mainGrid_.remove(siteGrid_);
        }
        else
        {
            row = 0;
            column = 0;
            for (unsigned int i = 0; i < SURF_NC_; i++)
            {
                if (column == 5)
                {
                    column = 0;
                    row++;
                }
                siteButton_.push_back(new Gtk::CheckButton(nc_[i]));
                siteGrid_.attach(*siteButton_[i], column, row, 1, 1);
                column++;
            }
        }

        if (type_ == "batch")
        {
            otherButton_.push_back(new Gtk::CheckButton("Temperature"));
            otherGrid_.attach(*otherButton_[0], 0, 0, 1, 1);
            otherButton_.push_back(new Gtk::CheckButton("Volume"));
            otherGrid_.attach(*otherButton_[1], 1, 0, 1, 1);
        }
        else if (type_ == "ph1d")
        {
            otherButton_.push_back(new Gtk::CheckButton("Temperature"));
            otherGrid_.attach(*otherButton_[0], 0, 0, 1, 1);
        }
        else if (type_ == "cstr")
        {
            otherButton_.push_back(new Gtk::CheckButton("Temperature"));
            otherGrid_.attach(*otherButton_[0], 0, 0, 1, 1);
        }
        else if (type_ == "het1d")
        {
            otherButton_.push_back(new Gtk::CheckButton("Temperature(bulk)"));
            otherGrid_.attach(*otherButton_[0], 0, 0, 1, 1);
            otherButton_.push_back(new Gtk::CheckButton("Temperature(wall)"));
            otherGrid_.attach(*otherButton_[1], 1, 0, 1, 1);
        }

        this->resize(mainGrid_.get_width(), mainGrid_.get_height());
        this->show_all_children();
    }

    void plot::setSpecieNames(const std::vector<std::string> n)
    {
        n_ = n;
        NC_ = n.size();
    }

    void plot::setSiteNames(const std::vector<std::string> nc)
    {
        SURF_NC_ = nc.size();
        if (SURF_NC_ != 0)
        {
            nc_ = nc;
        }
    }

    void plot::setTime(const std::vector<double> t)
    {
        t_ = t;
    }

    void plot::setLength(const std::vector<double> L, const std::string Lud)
    {
        L_ = L;
        Lud_ = Lud;
        NP_ = L.size();

        for (unsigned int i = 0; i < NP_; i++)
        {
            ConvertsFromMeter(L_[i], Lud_);
        }
    }

    void plot::setTemperature(const std::vector<double> T)
    {
        T_ = T;
    }

    void plot::setTemperature(const std::vector<std::vector<double>> T)
    {
        Tt_.resize(T.size());
        for (unsigned int i = 0; i < T.size(); i++)
        {
            Tt_[i] = T[i];
        }
    }

    void plot::setTemperature(const std::vector<std::vector<double>> Tb,
                              const std::vector<std::vector<double>> Tw)
    {
        Tb_.resize(Tb.size());
        for (unsigned int i = 0; i < Tb.size(); i++)
        {
            Tb_[i] = Tb[i];
        }

        Tw_.resize(Tw.size());
        for (unsigned int i = 0; i < Tw.size(); i++)
        {
            Tw_[i] = Tw[i];
        }
    }

    void plot::setVolume(const std::vector<double> V)
    {
        V_ = V;
    }

    void plot::setSpecie(const std::vector<std::vector<double>> y, const std::vector<std::vector<double>> x)
    {
        y_.resize(y.size());
        for (unsigned int i = 0; i < y.size(); i++)
        {
            y_[i] = y[i];
        }

        x_.resize(x.size());
        for (unsigned int i = 0; i < x.size(); i++)
        {
            x_[i] = x[i];
        }
    }

    void plot::setSpecie(const std::vector<std::vector<std::vector<double>>> y, const std::vector<std::vector<std::vector<double>>> x)
    {
        yt_.resize(y.size());
        for (unsigned int i = 0; i < y.size(); i++)
        {
            yt_[i].resize(y[i].size());
            for (unsigned int j = 0; j < y[i].size(); j++)
            {
                yt_[i][j] = y[i][j];
            }
        }

        xt_.resize(x.size());
        for (unsigned int i = 0; i < x.size(); i++)
        {
            xt_[i].resize(x[i].size());
            for (unsigned int j = 0; j < x[i].size(); j++)
            {
                xt_[i][j] = x[i][j];
            }
        }
    }

    void plot::setSpecie(const std::vector<std::vector<std::vector<double>>> yb, const std::vector<std::vector<std::vector<double>>> xb,
                         const std::vector<std::vector<std::vector<double>>> yw, const std::vector<std::vector<std::vector<double>>> xw)
    {
        yt_.resize(yb.size());
        xt_.resize(yb.size());
        for (unsigned int i = 0; i < yb.size(); i++)
        {
            yt_[i].resize(yb[i].size());
            xt_[i].resize(xb[i].size());
            for (unsigned int j = 0; j < yb[i].size(); j++)
            {
                yt_[i][j].resize(yb[i][j].size() + yw[i][j].size());
                xt_[i][j].resize(xb[i][j].size() + xw[i][j].size());
                for (unsigned int k = 0; k < yb[i][j].size(); k++)
                {
                    yt_[i][j][k] = yb[i][j][k];
                    xt_[i][j][k] = xb[i][j][k];
                }

                for (unsigned int k = 0; k < yw[i][j].size(); k++)
                {
                    yt_[i][j][k + yb[i][j].size()] = yw[i][j][k];
                    xt_[i][j][k + xb[i][j].size()] = xw[i][j][k];
                }
            }
        }
    }

    void plot::setSite(const std::vector<std::vector<double>> z)
    {
        z_.resize(z.size());
        for (unsigned int i = 0; i < z.size(); i++)
        {
            z_[i] = z[i];
        }
    }

    void plot::setSite(const std::vector<std::vector<std::vector<double>>> z)
    {
        zt_.resize(z.size());
        for (unsigned int i = 0; i < z.size(); i++)
        {
            zt_[i].resize(z[i].size());
            for (unsigned int j = 0; j < z[i].size(); j++)
            {
                zt_[i][j] = z[i][j];
            }
        }
    }

    void plot::setType(const std::string type)
    {
        type_ = type;
    }

    void plot::setResolutionType(const std::string resolution)
    {
        resolution_ = resolution;
    }

    void plot::exit()
    {
        this->destroy();
        this->hide();
    }

    void plot::runPlot()
    {
        ASALI::plotInterface *plotInterface;
        plotInterface = new ASALI::plotInterface();
        this->defaultcolors(plotInterface);

        if (type_ == "batch")
        {
            this->batchplot(plotInterface);
        }
        else if (type_ == "ph1d")
        {
            this->ph1dplot(resolution_);
        }
        else if (type_ == "cstr")
        {
            this->cstrplot();
        }
        else if (type_ == "het1d")
        {
            this->het1dplot();
        }
        else if (type_ == "pellet")
        {
            this->pelletplot();
        }
        delete plotInterface;
    }


    void plot::defaultcolors(ASALI::plotInterface *plotInterface)
    {
        plotInterface->setDefaultTextColor(220,230,242);
        plotInterface->setDefaultBackgroundColor(16,37,63);
    }

    void plot::legend(ASALI::plotInterface *plotInterface, int ndata)
    {
        if ( ndata <= MAX_COL_ )
        {
            plotInterface->setLegendPosition("top");
        }
        else
        {
            plotInterface->setLegendPosition("top");
            plotInterface->setLegendGrid(MAX_COL_, ndata/MAX_COL_);
        }
    }
    
    void plot::output(ASALI::plotInterface *plotInterface)
    {
        #if ASALI_ON_WINDOW == 1
        plotInterface->setOutputFormat("wingdi");
        #else
        plotInterface->setOutputFormat("qtwidget");
        #endif
    }

    void plot::batchplot(ASALI::plotInterface *plotInterface)
    {
        if (this->isChecked(massButton_))
        {
            plotInterface->newFigure();
            std::vector<double> y(t_.size());
            int ndata = 0;
            for (unsigned int i = 0; i < NC_; i++)
            {
                if (massButton_[i]->get_active())
                {
                    for (unsigned int j = 0; j < t_.size(); j++)
                    {
                        y[j] = std::max(0., y_[j][i]);
                    }
                    plotInterface->setData(t_, y, n_[i]);
                    ndata++;
                }
            }
            plotInterface->setXlabel("Time [s]");
            plotInterface->setYlabel("Mass fraction [-]");
            this->legend(plotInterface, ndata);
            this->output(plotInterface);
            plotInterface->legend();
        }

        if (this->isChecked(moleButton_))
        {
            plotInterface->newFigure();
            std::vector<double> x(t_.size());
            int ndata = 0;
            for (unsigned int i = 0; i < NC_; i++)
            {
                if (moleButton_[i]->get_active())
                {
                    for (unsigned int j = 0; j < t_.size(); j++)
                    {
                        x[j] = std::max(0., x_[j][i]);
                    }
                    plotInterface->setData(t_,x, n_[i]);
                    ndata++;
                }
            }
            plotInterface->setXlabel("Time [s]");
            plotInterface->setYlabel("Mole fraction [-]");
            this->legend(plotInterface, ndata);
            this->output(plotInterface);
            plotInterface->legend();
        }

        if (this->isChecked(siteButton_))
        {
            plotInterface->newFigure();
            std::vector<double> z(t_.size());
            int ndata = 0;
            for (unsigned int i = 0; i < NC_; i++)
            {
                if (siteButton_[i]->get_active())
                {
                    for (unsigned int j = 0; j < t_.size(); j++)
                    {
                        z[j] = std::max(0., z_[j][i]);
                    }
                    plotInterface->setData(t_, z, nc_[i]);
                    ndata++;
                }
            }
            plotInterface->setXlabel("Time [s]");
            plotInterface->setYlabel("Coverage [-]");
            this->legend(plotInterface, ndata);
            this->output(plotInterface);
            plotInterface->legend();
        }

        if (this->isChecked(otherButton_))
        {
            if (otherButton_[0]->get_active()) //Temperature
            {
                plotInterface->newFigure();
                plotInterface->setData(t_, T_, "");
                plotInterface->setXlabel("Time [s]");
                plotInterface->setYlabel("Temperature [K]");
                this->output(plotInterface);
            }

            if (otherButton_[1]->get_active()) //Volume
            {
                plotInterface->newFigure();
                plotInterface->setData(t_, V_, "");
                plotInterface->setXlabel("Time [s]");
                plotInterface->setYlabel("Volume [m3]");
                this->output(plotInterface);
            }
        }
        plotInterface->show();
    }

    void plot::ph1dplot(const std::string resolution)
    {
        /*
        if (resolution == "steady state")
        {
            if (this->isChecked(massButton_))
            {
                plotInterface_->newFigure();
                std::vector<double> y(L_.size());
                for (unsigned int i = 0; i < NC_; i++)
                {
                    if (massButton_[i]->get_active())
                    {
                        for (unsigned int j = 0; j < L_.size(); j++)
                        {
                            y[j] = std::max(0., y_[j][i]);
                        }
                        plotInterface_->setData(L_, y, n_[i]);
                    }
                }
                plotInterface_->setXlabel("Length [" + Lud_ + "]");
                plotInterface_->setYlabel("Mass fraction [-]");
                #if ASALI_ON_WINDOW == 1
                plotInterface_->setOutputFormat("wingdi");
                #else
                plotInterface_->setOutputFormat("xcairo");
                #endif
                plotInterface_->legend();
            }

            if (this->isChecked(moleButton_))
            {
                plotInterface_->newFigure();
                std::vector<double> x(L_.size());
                for (unsigned int i = 0; i < NC_; i++)
                {
                    if (moleButton_[i]->get_active())
                    {
                        for (unsigned int j = 0; j < L_.size(); j++)
                        {
                            x[j] = std::max(0., x_[j][i]);
                        }
                        plotInterface_->setData(L_, x, n_[i]);
                    }
                }
                plotInterface_->setXlabel("Length [" + Lud_ + "]");
                plotInterface_->setYlabel("Mole fraction [-]");
                #if ASALI_ON_WINDOW == 1
                plotInterface_->setOutputFormat("wingdi");
                #else
                plotInterface_->setOutputFormat("xcairo");
                #endif
                plotInterface_->legend();
            }

            if (this->isChecked(siteButton_))
            {
                plotInterface_->newFigure();
                std::vector<double> z(L_.size());
                for (unsigned int i = 0; i < NC_; i++)
                {
                    if (siteButton_[i]->get_active())
                    {
                        for (unsigned int j = 0; j < L_.size(); j++)
                        {
                            z[j] = std::max(0., z_[j][i]);
                        }
                        plotInterface_->setData(L_, z, nc_[i]);
                    }
                }
                plotInterface_->setXlabel("Length [" + Lud_ + "]");
                plotInterface_->setYlabel("Coverage [-]");
                #if ASALI_ON_WINDOW == 1
                plotInterface_->setOutputFormat("wingdi");
                #else
                plotInterface_->setOutputFormat("xcairo");
                #endif
                plotInterface_->legend();
            }

            if (this->isChecked(otherButton_))
            {
                if (otherButton_[0]->get_active())
                {
                    plotInterface_->newFigure();
                    plotInterface_->setData(L_, T_, "");
                    plotInterface_->setXlabel("Length [" + Lud_ + "]");
                    plotInterface_->setYlabel("Temperature [K]");
                }
            }
        }
        else if (resolution == "transient")
        {
            if (this->isChecked(massButton_))
            {
                for (unsigned int i = 0; i < NC_; i++)
                {
                    if (massButton_[i]->get_active())
                    {
                        plotInterface_->newFigure();
                        std::vector<double> y(L_.size());
                        for (unsigned int k = 0; k < t_.size(); k++)
                        {
                            for (unsigned int j = 0; j < L_.size(); j++)
                            {
                                y[j] = std::max(0., yt_[k][j][i]);
                            }
                            plotInterface_->setData(L_, y, "");
                        }
                        plotInterface_->setTitle(n_[i]);
                        plotInterface_->setXlabel("Length [" + Lud_ + "]");
                        plotInterface_->setYlabel("Mass fraction [-]");
                    }
                }
            }

            if (this->isChecked(moleButton_))
            {
                for (unsigned int i = 0; i < NC_; i++)
                {
                    if (moleButton_[i]->get_active())
                    {
                        plotInterface_->newFigure();
                        std::vector<double> x(L_.size());
                        for (unsigned int k = 0; k < t_.size(); k++)
                        {
                            for (unsigned int j = 0; j < L_.size(); j++)
                            {
                                x[j] = std::max(0., xt_[k][j][i]);
                            }
                            plotInterface_->setData(L_, x, "");
                        }
                        plotInterface_->setTitle(n_[i]);
                        plotInterface_->setXlabel("Length [" + Lud_ + "]");
                        plotInterface_->setYlabel("Mole fraction [-]");
                    }
                }
            }

            if (this->isChecked(siteButton_))
            {
                for (unsigned int i = 0; i < SURF_NC_; i++)
                {
                    if (siteButton_[i]->get_active())
                    {
                        plotInterface_->newFigure();
                        std::vector<double> z(L_.size());
                        for (unsigned int k = 0; k < t_.size(); k++)
                        {
                            for (unsigned int j = 0; j < L_.size(); j++)
                            {
                                z[j] = std::max(0., zt_[k][j][i]);
                            }
                            plotInterface_->setData(L_, z, "");
                        }
                        plotInterface_->setTitle(nc_[i]);
                        plotInterface_->setXlabel("Length [" + Lud_ + "]");
                        plotInterface_->setYlabel("Coverage [-]");
                    }
                }
            }

            if (this->isChecked(otherButton_))
            {
                if (otherButton_[0]->get_active())
                {
                    plotInterface_->newFigure();
                    std::vector<double> T(L_.size());
                    for (unsigned int k = 0; k < t_.size(); k++)
                    {
                        for (unsigned int j = 0; j < L_.size(); j++)
                        {
                            T[j] = std::max(0., Tt_[k][j]);
                        }
                        plotInterface_->setData(L_, T, "");
                    }
                    plotInterface_->setXlabel("Length [" + Lud_ + "]");
                    plotInterface_->setYlabel("Temperature [K]");
                }
            }
        }
        plotInterface_->show();*/
    }

    void plot::cstrplot()
    {
        /*
        if (this->isChecked(massButton_))
        {
            plotInterface_->newFigure();
            std::vector<double> y(t_.size());
            for (unsigned int i = 0; i < NC_; i++)
            {
                if (massButton_[i]->get_active())
                {
                    for (unsigned int j = 0; j < t_.size(); j++)
                    {
                        y[j] = std::max(0., y_[j][i]);
                    }
                    plotInterface_->setData(t_, y, n_[i]);
                }
            }
            plotInterface_->setXlabel("Time [s]");
            plotInterface_->setYlabel("Mass fraction [-]");
            #if ASALI_ON_WINDOW == 1
            plotInterface_->setOutputFormat("wingdi");
            #else
            plotInterface_->setOutputFormat("xcairo");
            #endif
            plotInterface_->legend();
        }

        if (this->isChecked(moleButton_))
        {
            plotInterface_->newFigure();
            std::vector<double> x(t_.size());
            for (unsigned int i = 0; i < NC_; i++)
            {
                if (moleButton_[i]->get_active())
                {
                    for (unsigned int j = 0; j < t_.size(); j++)
                    {
                        x[j] = std::max(0., x_[j][i]);
                    }
                    plotInterface_->setData(t_, x, n_[i]);
                }
            }
            plotInterface_->setXlabel("Time [s]");
            plotInterface_->setYlabel("Mole fraction [-]");
            #if ASALI_ON_WINDOW == 1
            plotInterface_->setOutputFormat("wingdi");
            #else
            plotInterface_->setOutputFormat("xcairo");
            #endif
            plotInterface_->legend();
        }

        if (this->isChecked(siteButton_))
        {
            plotInterface_->newFigure();
            std::vector<double> z(t_.size());
            for (unsigned int i = 0; i < NC_; i++)
            {
                if (moleButton_[i]->get_active())
                {
                    for (unsigned int j = 0; j < t_.size(); j++)
                    {
                        z[j] = std::max(0., z_[j][i]);
                    }
                    plotInterface_->setData(t_, z, nc_[i]);
                }
            }
            plotInterface_->setXlabel("Time [s]");
            plotInterface_->setYlabel("Coverage [-]");
            #if ASALI_ON_WINDOW == 1
            plotInterface_->setOutputFormat("wingdi");
            #else
            plotInterface_->setOutputFormat("xcairo");
            #endif
            plotInterface_->legend();
        }

        if (this->isChecked(otherButton_))
        {
            if (otherButton_[0]->get_active()) //Temperature
            {
                plotInterface_->newFigure();
                plotInterface_->setData(t_, T_, "");
                plotInterface_->setXlabel("Time [s]");
                plotInterface_->setYlabel("Temperature [K]");
            }
        }
        plotInterface_->show();*/
    }

    void plot::het1dplot()
    {
        /*
        if (this->isChecked(massButton_))
        {
            for (unsigned int i = 0; i < NC_; i++)
            {
                if (massButton_[i]->get_active())
                {
                    plotInterface_->newFigure();
                    std::vector<double> y(L_.size());
                    for (unsigned int k = 0; k < t_.size(); k++)
                    {
                        for (unsigned int j = 0; j < L_.size(); j++)
                        {
                            y[j] = std::max(0., yt_[k][j][i]);
                        }
                        plotInterface_->setData(L_, y, "");
                    }
                    plotInterface_->setTitle(n_[i]);
                    plotInterface_->setXlabel("Length [" + Lud_ + "]");
                    plotInterface_->setYlabel("Mass fraction [-]");
                }
            }
        }

        if (this->isChecked(moleButton_))
        {
            for (unsigned int i = 0; i < NC_; i++)
            {
                if (moleButton_[i]->get_active())
                {
                    plotInterface_->newFigure();
                    std::vector<double> x(L_.size());
                    for (unsigned int k = 0; k < t_.size(); k++)
                    {
                        for (unsigned int j = 0; j < L_.size(); j++)
                        {
                            x[j] = std::max(0., xt_[k][j][i]);
                        }
                        plotInterface_->setData(L_, x, "");
                    }
                    plotInterface_->setTitle(n_[i]);
                    plotInterface_->setXlabel("Length [" + Lud_ + "]");
                    plotInterface_->setYlabel("Mole fraction [-]");
                }
            }
        }

        if (this->isChecked(siteButton_))
        {
            for (unsigned int i = 0; i < SURF_NC_; i++)
            {
                if (siteButton_[i]->get_active())
                {
                    plotInterface_->newFigure();
                    std::vector<double> z(L_.size());
                    for (unsigned int k = 0; k < t_.size(); k++)
                    {
                        for (unsigned int j = 0; j < L_.size(); j++)
                        {
                            z[j] = std::max(0., zt_[k][j][i]);
                        }
                        plotInterface_->setData(L_, z, "");
                    }
                    plotInterface_->setTitle(nc_[i]);
                    plotInterface_->setXlabel("Length [" + Lud_ + "]");
                    plotInterface_->setYlabel("Coverage [-]");
                }
            }
        }

        if (this->isChecked(otherButton_))
        {
            if (otherButton_[0]->get_active())
            {
                plotInterface_->newFigure();
                std::vector<double> T(L_.size());
                for (unsigned int k = 0; k < t_.size(); k++)
                {
                    for (unsigned int j = 0; j < L_.size(); j++)
                    {
                        T[j] = std::max(0., Tb_[k][j]);
                    }
                    plotInterface_->setData(L_, T, "");
                }
                plotInterface_->setXlabel("Length [" + Lud_ + "]");
                plotInterface_->setYlabel("Bulk temperature [K]");
            }

            if (otherButton_[1]->get_active())
            {
                plotInterface_->newFigure();
                std::vector<double> T(L_.size());
                for (unsigned int k = 0; k < t_.size(); k++)
                {
                    for (unsigned int j = 0; j < L_.size(); j++)
                    {
                        T[j] = std::max(0., Tw_[k][j]);
                    }
                    plotInterface_->setData(L_, T, "");
                }
                plotInterface_->setXlabel("Length [" + Lud_ + "]");
                plotInterface_->setYlabel("Wall temperature [K]");
            }
        }
        plotInterface_->show();*/
    }

    void plot::pelletplot()
    {
        /*if (this->isChecked(massButton_))
        {
            for (unsigned int i = 0; i < NC_; i++)
            {
                if (massButton_[i]->get_active())
                {
                    plotInterface_->newFigure();
                    std::vector<double> y(L_.size());
                    for (unsigned int k = 0; k < t_.size(); k++)
                    {
                        for (unsigned int j = 0; j < L_.size(); j++)
                        {
                            y[j] = std::max(0., yt_[k][j][i]);
                        }
                        plotInterface_->setData(L_, y, "");
                    }
                    plotInterface_->setTitle(n_[i]);
                    plotInterface_->setXlabel("Length [" + Lud_ + "]");
                    plotInterface_->setYlabel("Mass fraction [-]");
                }
            }
        }

        if (this->isChecked(moleButton_))
        {
            for (unsigned int i = 0; i < NC_; i++)
            {
                if (moleButton_[i]->get_active())
                {
                    plotInterface_->newFigure();
                    std::vector<double> x(L_.size());
                    for (unsigned int k = 0; k < t_.size(); k++)
                    {
                        for (unsigned int j = 0; j < L_.size(); j++)
                        {
                            x[j] = std::max(0., xt_[k][j][i]);
                        }
                        plotInterface_->setData(L_, x, "");
                    }
                    plotInterface_->setTitle(n_[i]);
                    plotInterface_->setXlabel("Length [" + Lud_ + "]");
                    plotInterface_->setYlabel("Mole fraction [-]");
                }
            }
        }

        if (this->isChecked(siteButton_))
        {
            for (unsigned int i = 0; i < SURF_NC_; i++)
            {
                if (siteButton_[i]->get_active())
                {
                    plotInterface_->newFigure();
                    std::vector<double> z(L_.size());
                    for (unsigned int k = 0; k < t_.size(); k++)
                    {
                        for (unsigned int j = 0; j < L_.size(); j++)
                        {
                            z[j] = std::max(0., zt_[k][j][i]);
                        }
                        plotInterface_->setData(L_, z, "");
                    }
                    plotInterface_->setTitle(nc_[i]);
                    plotInterface_->setXlabel("Length [" + Lud_ + "]");
                    plotInterface_->setYlabel("Coverage [-]");
                }
            }
        }
        plotInterface_->show();*/
    }

    void plot::destroy()
    {
        if (NC_ != 0)
        {
            for (unsigned int i = 0; i < NC_; i++)
            {
                moleGrid_.remove(*moleButton_[i]);
                massGrid_.remove(*massButton_[i]);
            }

            if (SURF_NC_ == 0)
            {
                mainGrid_.attach(siteLabel_, 0, 4, 1, 1);
                mainGrid_.attach(siteGrid_, 0, 5, 1, 1);
            }
            else
            {
                for (unsigned int i = 0; i < SURF_NC_; i++)
                {
                    siteGrid_.remove(*siteButton_[i]);
                }
            }

            for (unsigned int i = 0; i < otherButton_.size(); i++)
            {
                otherGrid_.remove(*otherButton_[i]);
            }

            NC_ = 0;
            SURF_NC_ = 0;
        }
    }

    bool plot::isChecked(std::vector<Gtk::CheckButton *> button)
    {
        for (unsigned int i = 0; i < button.size(); i++)
        {
            if (button[i]->get_active())
            {
                return true;
            }
        }
        return false;
    }

    plot::~plot()
    {
    }

}
