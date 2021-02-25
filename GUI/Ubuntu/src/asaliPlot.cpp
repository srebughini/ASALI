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

#include "asaliPlot.hpp"

namespace ASALI
{
    asaliPlot::asaliPlot()
    : plotButton_("Plot"),
      exitButton_("Exit"),
      moleLabel_("Mole fraction"),
      massLabel_("Mass fraction"),
      siteLabel_("Coverage"),
      otherLabel_("Others"),
      NC_(0),
      SURF_NC_(0),
      NP_(0)
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

        mainGrid_.attach(moleLabel_,0,0,1,1);
        mainGrid_.attach(moleGrid_,0,1,1,1);
        mainGrid_.attach(massLabel_,0,2,1,1);
        mainGrid_.attach(massGrid_,0,3,1,1);
        mainGrid_.attach(siteLabel_,0,4,1,1);
        mainGrid_.attach(siteGrid_,0,5,1,1);
        mainGrid_.attach(otherLabel_,0,6,1,1);
        mainGrid_.attach(otherGrid_,0,7,1,1);
        mainGrid_.attach(buttonBox_,0,8,1,1);

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
        plotButton_.signal_clicked().connect(sigc::mem_fun(*this,&asaliPlot::plot));
        exitButton_.signal_clicked().connect(sigc::mem_fun(*this,&asaliPlot::exit));
    }
    
    void asaliPlot::build()
    {
        unsigned int row    = 0;
        unsigned int column = 0;
        moleButton_.clear();
        massButton_.clear();
        siteButton_.clear();
        otherButton_.clear();
        for (unsigned int i=0;i<NC_;i++)
        {
            if ( column == 5 )
            {
                column = 0;
                row++;
            }
            moleButton_.push_back(new Gtk::CheckButton(n_[i]));
            moleGrid_.attach(*moleButton_[i],column,row,1,1);
            massButton_.push_back(new Gtk::CheckButton(n_[i]));
            massGrid_.attach(*massButton_[i],column,row,1,1);
            column++;
        }
        
        if ( SURF_NC_ == 0 )
        {
            mainGrid_.remove(siteLabel_);
            mainGrid_.remove(siteGrid_);
        }
        else
        {
            row    = 0;
            column = 0;
            for (unsigned int i=0;i<SURF_NC_;i++)
            {
                if ( column == 5 )
                {
                    column = 0;
                    row++;
                }
                siteButton_.push_back(new Gtk::CheckButton(nc_[i]));
                siteGrid_.attach(*siteButton_[i],column,row,1,1);
                column++;
            }
        }
        
        if ( type_ == "batch" )
        {
            otherButton_.push_back(new Gtk::CheckButton("Temperature"));
            otherGrid_.attach(*otherButton_[0],0,0,1,1);
            otherButton_.push_back(new Gtk::CheckButton("Volume"));
            otherGrid_.attach(*otherButton_[1],1,0,1,1);
        }
        else if ( type_ == "ph1d" )
        {
            otherButton_.push_back(new Gtk::CheckButton("Temperature"));
            otherGrid_.attach(*otherButton_[0],0,0,1,1);
        }
        else if ( type_ == "cstr" )
        {
            otherButton_.push_back(new Gtk::CheckButton("Temperature"));
            otherGrid_.attach(*otherButton_[0],0,0,1,1);
        }
        else if ( type_ == "het1d" )
        {
            otherButton_.push_back(new Gtk::CheckButton("Temperature(bulk)"));
            otherGrid_.attach(*otherButton_[0],0,0,1,1);
            otherButton_.push_back(new Gtk::CheckButton("Temperature(wall)"));
            otherGrid_.attach(*otherButton_[1],1,0,1,1);
        }

        this->resize(mainGrid_.get_width(),mainGrid_.get_height ());
        this->show_all_children();
    }
    

    void asaliPlot::setSpecieNames(const std::vector<std::string> n)
    {
        n_  = n;
        NC_ = n.size();
    }

    void asaliPlot::setSiteNames(const std::vector<std::string> nc)
    {
        SURF_NC_ = nc.size();
        if ( SURF_NC_ != 0 )
        {
            nc_ = nc;
        }
    }

    void asaliPlot::setTime(const std::vector<double> t)
    {
        t_ = t;
    }

    void asaliPlot::setLength(const std::vector<double> L,const std::string Lud)
    {
        L_   = L;
        Lud_ = Lud;
        NP_  = L.size();

        for (unsigned int i=0;i<NP_;i++)
        {
            ConvertsFromMeter(L_[i],Lud_);
        }
    }

    void asaliPlot::setTemperature(const std::vector<double> T)
    {
        T_ = T;
    }

    void asaliPlot::setTemperature(const std::vector<std::vector<double> > T)
    {
        Tt_.resize(T.size());
        for (unsigned int i=0;i<T.size();i++)
        {
            Tt_[i] = T[i];
        }
    }

    void asaliPlot::setTemperature(const std::vector<std::vector<double> > Tb,
                                   const std::vector<std::vector<double> > Tw)
    {
        Tb_.resize(Tb.size());
        for (unsigned int i=0;i<Tb.size();i++)
        {
            Tb_[i] = Tb[i];
        }

        Tw_.resize(Tw.size());
        for (unsigned int i=0;i<Tw.size();i++)
        {
            Tw_[i] = Tw[i];
        }
    }

    void asaliPlot::setVolume(const std::vector<double> V)
    {
        V_ = V;
    }
    
    void asaliPlot::setSpecie(const std::vector<std::vector<double> > y,const std::vector<std::vector<double> > x)
    {
        y_.resize(y.size());
        for (unsigned int i=0;i<y.size();i++)
        {
            y_[i] = y[i];
        }

        x_.resize(x.size());
        for (unsigned int i=0;i<x.size();i++)
        {
            x_[i] = x[i];
        }
    }

    void asaliPlot::setSpecie(const std::vector<std::vector<std::vector<double> > > y,const std::vector<std::vector<std::vector<double> > > x)
    {
        yt_.resize(y.size());
        for (unsigned int i=0;i<y.size();i++)
        {
            yt_[i].resize(y[i].size());
            for (unsigned int j=0;j<y[i].size();j++)
            {
                yt_[i][j] = y[i][j];
            }
        }

        xt_.resize(x.size());
        for (unsigned int i=0;i<x.size();i++)
        {
            xt_[i].resize(x[i].size());
            for (unsigned int j=0;j<x[i].size();j++)
            {
                xt_[i][j] = x[i][j];
            }
        }
    }

    void asaliPlot::setSpecie(const std::vector<std::vector<std::vector<double> > > yb,const std::vector<std::vector<std::vector<double> > > xb,
                              const std::vector<std::vector<std::vector<double> > > yw,const std::vector<std::vector<std::vector<double> > > xw)
    {
        yt_.resize(yb.size());
        xt_.resize(yb.size());
        for (unsigned int i=0;i<yb.size();i++)
        {
            yt_[i].resize(yb[i].size());
            xt_[i].resize(xb[i].size());
            for (unsigned int j=0;j<yb[i].size();j++)
            {
                yt_[i][j].resize(yb[i][j].size() + yw[i][j].size());
                xt_[i][j].resize(xb[i][j].size() + xw[i][j].size());
                for (unsigned int k=0;k<yb[i][j].size(); k++)
                {
                    yt_[i][j][k] = yb[i][j][k];
                    xt_[i][j][k] = xb[i][j][k];
                }

                for (unsigned int k=0;k<yw[i][j].size(); k++)
                {
                    yt_[i][j][k + yb[i][j].size()] = yw[i][j][k];
                    xt_[i][j][k + xb[i][j].size()] = xw[i][j][k];
                }
            }
        }
    }

    void asaliPlot::setSite(const std::vector<std::vector<double> > z)
    {
        z_.resize(z.size());
        for (unsigned int i=0;i<z.size();i++)
        {
            z_[i] = z[i];
        }
    }

    void asaliPlot::setSite(const std::vector<std::vector<std::vector<double> > > z)
    {
        zt_.resize(z.size());
        for (unsigned int i=0;i<z.size();i++)
        {
            zt_[i].resize(z[i].size());
            for (unsigned int j=0;j<z[i].size();j++)
            {
                zt_[i][j] = z[i][j];
            }
        }
    }

    void asaliPlot::setType(const std::string type)
    {
        type_ = type;
    }

    void asaliPlot::setResolutionType(const std::string resolution)
    {
        resolution_ = resolution;
    }

    void asaliPlot::exit()
    {
        this->destroy();
        this->hide();
    }
    
    void asaliPlot::plot()
    {
        this->setPythonPath();
        if ( type_ == "batch" )
        {
            this->batchplot();
        }
        else if ( type_ == "ph1d" )
        {
            this->ph1dplot(resolution_);
        }
        else if ( type_ == "cstr" )
        {
            this->cstrplot();
        }
        else if ( type_ == "het1d" )
        {
            this->het1dplot();
        }
        else if ( type_ == "pellet" )
        {
            this->pelletplot();
        }
    }

    void asaliPlot::batchplot()
    {
        unsigned int nFig = 1;
        if ( this->isChecked(massButton_) )
        {
            matplotlibcpp::figure(nFig++);
            std::vector<double> y(t_.size());
            for (unsigned int i=0;i<NC_;i++)
            {
                if ( massButton_[i]->get_active() )
                {
                    for (unsigned int j=0;j<t_.size();j++)
                    {
                        y[j] = std::max(0.,y_[j][i]);
                    }
                    matplotlibcpp::named_plot(n_[i],t_,y);
                }
            }
            matplotlibcpp::title("MASS FRACTION");
            matplotlibcpp::xlabel("Time [s]");
            matplotlibcpp::ylabel("Mass fraction [-]");
            matplotlibcpp::legend("best", false);
        }

        if ( this->isChecked(moleButton_) )
        {
            matplotlibcpp::figure(nFig++);
            std::vector<double> x(t_.size());
            for (unsigned int i=0;i<NC_;i++)
            {
                if ( moleButton_[i]->get_active() )
                {
                    for (unsigned int j=0;j<t_.size();j++)
                    {
                        x[j] = std::max(0.,x_[j][i]);
                    }
                    matplotlibcpp::named_plot(n_[i],t_,x);
                }
            }
            matplotlibcpp::title("MOLE FRACTION");
            matplotlibcpp::xlabel("Time [s]");
            matplotlibcpp::ylabel("Mole fraction [-]");
            matplotlibcpp::legend("best", false);
        }
        
        if ( this->isChecked(siteButton_) )
        {
            matplotlibcpp::figure(nFig++);
            std::vector<double> z(t_.size());
            for (unsigned int i=0;i<NC_;i++)
            {
                if ( siteButton_[i]->get_active() )
                {
                    for (unsigned int j=0;j<t_.size();j++)
                    {
                        z[j] = std::max(0.,z_[j][i]);
                    }
                    matplotlibcpp::named_plot(nc_[i],t_,z);
                }
            }
            matplotlibcpp::title("COVERAGE");
            matplotlibcpp::xlabel("Time [s]");
            matplotlibcpp::ylabel("Coverage [-]");
            matplotlibcpp::legend("best", false);
        }
        
        if ( this->isChecked(otherButton_) )
        {
            if ( otherButton_[0]->get_active() ) //Temperature
            {
                matplotlibcpp::figure(nFig++);
                matplotlibcpp::plot(t_,T_);
                matplotlibcpp::title("TEMPERATURE");
                matplotlibcpp::xlabel("Time [s]");
                matplotlibcpp::ylabel("Temperature [K]");
            }


            if ( otherButton_[1]->get_active() ) //Volume
            {
                matplotlibcpp::figure(nFig++);
                matplotlibcpp::plot(t_,V_);
                matplotlibcpp::title("VOLUME");
                matplotlibcpp::xlabel("Time [s]");
                matplotlibcpp::ylabel("Volume [m3]");
            }
        }
        matplotlibcpp::show();
    }

    void asaliPlot::ph1dplot(const std::string resolution)
    {
        if ( resolution == "steady state" )
        {
            unsigned int nFig = 1;
            if ( this->isChecked(massButton_) )
            {
                matplotlibcpp::figure(nFig++);
                std::vector<double> y(L_.size());
                for (unsigned int i=0;i<NC_;i++)
                {
                    if ( massButton_[i]->get_active() )
                    {
                        for (unsigned int j=0;j<L_.size();j++)
                        {
                            y[j] = std::max(0.,y_[j][i]);
                        }
                        matplotlibcpp::named_plot(n_[i],L_,y);
                    }
                }
                matplotlibcpp::title("MASS FRACTION");
                matplotlibcpp::xlabel("Length [" + Lud_ + "]");
                matplotlibcpp::ylabel("Mass fraction [-]");
                matplotlibcpp::legend("best", false);
            }

            if ( this->isChecked(moleButton_) )
            {
                matplotlibcpp::figure(nFig++);
                std::vector<double> x(L_.size());
                for (unsigned int i=0;i<NC_;i++)
                {
                    if ( moleButton_[i]->get_active() )
                    {
                        for (unsigned int j=0;j<L_.size();j++)
                        {
                            x[j] = std::max(0.,x_[j][i]);
                        }
                        matplotlibcpp::named_plot(n_[i],L_,x);
                    }
                }
                matplotlibcpp::title("MOLE FRACTION");
                matplotlibcpp::xlabel("Length [" + Lud_ + "]");
                matplotlibcpp::ylabel("Mole fraction [-]");
                matplotlibcpp::legend("best", false);
            }


            if ( this->isChecked(siteButton_) )
            {
                matplotlibcpp::figure(nFig++);
                std::vector<double> z(L_.size());
                for (unsigned int i=0;i<NC_;i++)
                {
                    if ( siteButton_[i]->get_active() )
                    {
                        for (unsigned int j=0;j<L_.size();j++)
                        {
                            z[j] = std::max(0.,z_[j][i]);
                        }
                        matplotlibcpp::named_plot(nc_[i],L_,z);
                    }
                }
                matplotlibcpp::title("COVERAGE");
                matplotlibcpp::xlabel("Length [" + Lud_ + "]");
                matplotlibcpp::ylabel("Coverage [-]");
                matplotlibcpp::legend("best", false);
            }

            if ( this->isChecked(otherButton_) )
            {
                if ( otherButton_[0]->get_active() )
                {
                    matplotlibcpp::figure(nFig++);
                    matplotlibcpp::plot(L_,T_);
                    matplotlibcpp::title("TEMPERATURE");
                    matplotlibcpp::xlabel("Length [" + Lud_ + "]");
                    matplotlibcpp::ylabel("Temperature [K]");
                }
            }
        }
        else if ( resolution == "transient" )
        {
            unsigned int nFig = 1;
            if ( this->isChecked(massButton_) )
            {
                for (unsigned int i=0;i<NC_;i++)
                {
                    if ( massButton_[i]->get_active() )
                    {
                        matplotlibcpp::figure(nFig++);
                        std::vector<double> y(L_.size());
                        for (unsigned int k=0;k<t_.size();k++)
                        {
                            for (unsigned int j=0;j<L_.size();j++)
                            {
                                y[j] = std::max(0.,yt_[k][j][i]);
                            }
                            matplotlibcpp::plot(L_,y);
                        }
                        matplotlibcpp::title(n_[i]);
                        matplotlibcpp::xlabel("Length [" + Lud_ + "]");
                        matplotlibcpp::ylabel("Mass fraction [-]");
                    }
                }
            }

            if ( this->isChecked(moleButton_) )
            {
                for (unsigned int i=0;i<NC_;i++)
                {
                    if ( moleButton_[i]->get_active() )
                    {
                        matplotlibcpp::figure(nFig++);
                        std::vector<double> x(L_.size());
                        for (unsigned int k=0;k<t_.size();k++)
                        {
                            for (unsigned int j=0;j<L_.size();j++)
                            {
                                x[j] = std::max(0.,xt_[k][j][i]);
                            }
                            matplotlibcpp::plot(L_,x);
                        }
                        matplotlibcpp::title(n_[i]);
                        matplotlibcpp::xlabel("Length [" + Lud_ + "]");
                        matplotlibcpp::ylabel("Mole fraction [-]");
                    }
                }
            }

            if ( this->isChecked(siteButton_) )
            {
                for (unsigned int i=0;i<SURF_NC_;i++)
                {
                    if ( siteButton_[i]->get_active() )
                    {
                        matplotlibcpp::figure(nFig++);
                        std::vector<double> z(L_.size());
                        for (unsigned int k=0;k<t_.size();k++)
                        {
                            for (unsigned int j=0;j<L_.size();j++)
                            {
                                z[j] = std::max(0.,zt_[k][j][i]);
                            }
                            matplotlibcpp::plot(L_,z);
                        }
                        matplotlibcpp::title(nc_[i]);
                        matplotlibcpp::xlabel("Length [" + Lud_ + "]");
                        matplotlibcpp::ylabel("Coverage [-]");
                    }
                }
            }

            if ( this->isChecked(otherButton_) )
            {
                if ( otherButton_[0]->get_active() )
                {
                    matplotlibcpp::figure(nFig++);
                    std::vector<double> T(L_.size());
                    for (unsigned int k=0;k<t_.size();k++)
                    {
                        for (unsigned int j=0;j<L_.size();j++)
                        {
                            T[j] = std::max(0.,Tt_[k][j]);
                        }
                        matplotlibcpp::plot(L_,T);
                    }
                    matplotlibcpp::title("TEMPERATURE");
                    matplotlibcpp::xlabel("Length [" + Lud_ + "]");
                    matplotlibcpp::ylabel("Temperature [K]");
                }
            }
        }
        matplotlibcpp::show();
    }

    void asaliPlot::cstrplot()
    {
        unsigned int nFig = 1;
        if ( this->isChecked(massButton_) )
        {
            matplotlibcpp::figure(nFig++);
            std::vector<double> y(t_.size());
            for (unsigned int i=0;i<NC_;i++)
            {
                if ( massButton_[i]->get_active() )
                {
                    for (unsigned int j=0;j<t_.size();j++)
                    {
                        y[j] = std::max(0.,y_[j][i]);
                    }
                    matplotlibcpp::named_plot(n_[i],t_,y);
                }
            }
            matplotlibcpp::title("MASS FRACTION");
            matplotlibcpp::xlabel("Time [s]");
            matplotlibcpp::ylabel("Mass fraction [-]");
            matplotlibcpp::legend("best", false);
        }

        if ( this->isChecked(moleButton_) )
        {
            matplotlibcpp::figure(nFig++);
            std::vector<double> x(t_.size());
            for (unsigned int i=0;i<NC_;i++)
            {
                if ( moleButton_[i]->get_active() )
                {
                    for (unsigned int j=0;j<t_.size();j++)
                    {
                        x[j] = std::max(0.,x_[j][i]);
                    }
                    matplotlibcpp::named_plot(n_[i],t_,x);
                }
            }
            matplotlibcpp::title("MOLE FRACTION");
            matplotlibcpp::xlabel("Time [s]");
            matplotlibcpp::ylabel("Mole fraction [-]");
            matplotlibcpp::legend("best", false);
        }
        
        if ( this->isChecked(siteButton_) )
        {
            matplotlibcpp::figure(nFig++);
            std::vector<double> z(t_.size());
            for (unsigned int i=0;i<NC_;i++)
            {
                if ( moleButton_[i]->get_active() )
                {
                    for (unsigned int j=0;j<t_.size();j++)
                    {
                        z[j] = std::max(0.,z_[j][i]);
                    }
                    matplotlibcpp::named_plot(nc_[i],t_,z);
                }
            }
            matplotlibcpp::title("COVERAGE");
            matplotlibcpp::xlabel("Time [s]");
            matplotlibcpp::ylabel("Coverage [-]");
            matplotlibcpp::legend("best", false);
        }
        
        if ( this->isChecked(otherButton_) )
        {
            if ( otherButton_[0]->get_active() ) //Temperature
            {
                matplotlibcpp::figure(nFig++);
                matplotlibcpp::plot(t_,T_);
                matplotlibcpp::title("TEMPERATURE");
                matplotlibcpp::xlabel("Time [s]");
                matplotlibcpp::ylabel("Temperature [K]");
            }
        }
        matplotlibcpp::show();
    }

    void asaliPlot::het1dplot()
    {
        unsigned int nFig = 1;
        if ( this->isChecked(massButton_) )
        {
            for (unsigned int i=0;i<NC_;i++)
            {
                if ( massButton_[i]->get_active() )
                {
                    matplotlibcpp::figure(nFig++);
                    std::vector<double> y(L_.size());
                    for (unsigned int k=0;k<t_.size();k++)
                    {
                        for (unsigned int j=0;j<L_.size();j++)
                        {
                            y[j] = std::max(0.,yt_[k][j][i]);
                        }
                        matplotlibcpp::plot(L_,y);
                    }
                    matplotlibcpp::title(n_[i]);
                    matplotlibcpp::xlabel("Length [" + Lud_ + "]");
                    matplotlibcpp::ylabel("Mass fraction [-]");
                }
            }
        }

        if ( this->isChecked(moleButton_) )
        {
            for (unsigned int i=0;i<NC_;i++)
            {
                if ( moleButton_[i]->get_active() )
                {
                    matplotlibcpp::figure(nFig++);
                    std::vector<double> x(L_.size());
                    for (unsigned int k=0;k<t_.size();k++)
                    {
                        for (unsigned int j=0;j<L_.size();j++)
                        {
                            x[j] = std::max(0.,xt_[k][j][i]);
                        }
                        matplotlibcpp::plot(L_,x);
                    }
                    matplotlibcpp::title(n_[i]);
                    matplotlibcpp::xlabel("Length [" + Lud_ + "]");
                    matplotlibcpp::ylabel("Mole fraction [-]");
                }
            }
        }

        if ( this->isChecked(siteButton_) )
        {
            for (unsigned int i=0;i<SURF_NC_;i++)
            {
                if ( siteButton_[i]->get_active() )
                {
                    matplotlibcpp::figure(nFig++);
                    std::vector<double> z(L_.size());
                    for (unsigned int k=0;k<t_.size();k++)
                    {
                        for (unsigned int j=0;j<L_.size();j++)
                        {
                            z[j] = std::max(0.,zt_[k][j][i]);
                        }
                        matplotlibcpp::plot(L_,z);
                    }
                    matplotlibcpp::title(nc_[i]);
                    matplotlibcpp::xlabel("Length [" + Lud_ + "]");
                    matplotlibcpp::ylabel("Coverage [-]");
                }
            }
        }

        if ( this->isChecked(otherButton_) )
        {
            if ( otherButton_[0]->get_active() )
            {
                matplotlibcpp::figure(nFig++);
                std::vector<double> T(L_.size());
                for (unsigned int k=0;k<t_.size();k++)
                {
                    for (unsigned int j=0;j<L_.size();j++)
                    {
                        T[j] = std::max(0.,Tb_[k][j]);
                    }
                    matplotlibcpp::plot(L_,T);
                }
                matplotlibcpp::title("BULK TEMPERATURE");
                matplotlibcpp::xlabel("Length [" + Lud_ + "]");
                matplotlibcpp::ylabel("Temperature [K]");
            }

            if ( otherButton_[1]->get_active() )
            {
                matplotlibcpp::figure(nFig++);
                std::vector<double> T(L_.size());
                for (unsigned int k=0;k<t_.size();k++)
                {
                    for (unsigned int j=0;j<L_.size();j++)
                    {
                        T[j] = std::max(0.,Tw_[k][j]);
                    }
                    matplotlibcpp::plot(L_,T);
                }
                matplotlibcpp::title("WALL TEMPERATURE");
                matplotlibcpp::xlabel("Length [" + Lud_ + "]");
                matplotlibcpp::ylabel("Temperature [K]");
            }
        }
        matplotlibcpp::show();
    }

    void asaliPlot::pelletplot()
    {
        unsigned int nFig = 1;
        if ( this->isChecked(massButton_) )
        {
            for (unsigned int i=0;i<NC_;i++)
            {
                if ( massButton_[i]->get_active() )
                {
                    matplotlibcpp::figure(nFig++);
                    std::vector<double> y(L_.size());
                    for (unsigned int k=0;k<t_.size();k++)
                    {
                        for (unsigned int j=0;j<L_.size();j++)
                        {
                            y[j] = std::max(0.,yt_[k][j][i]);
                        }
                        matplotlibcpp::plot(L_,y);
                    }
                    matplotlibcpp::title(n_[i]);
                    matplotlibcpp::xlabel("Length [" + Lud_ + "]");
                    matplotlibcpp::ylabel("Mass fraction [-]");
                }
            }
        }

        if ( this->isChecked(moleButton_) )
        {
            for (unsigned int i=0;i<NC_;i++)
            {
                if ( moleButton_[i]->get_active() )
                {
                    matplotlibcpp::figure(nFig++);
                    std::vector<double> x(L_.size());
                    for (unsigned int k=0;k<t_.size();k++)
                    {
                        for (unsigned int j=0;j<L_.size();j++)
                        {
                            x[j] = std::max(0.,xt_[k][j][i]);
                        }
                        matplotlibcpp::plot(L_,x);
                    }
                    matplotlibcpp::title(n_[i]);
                    matplotlibcpp::xlabel("Length [" + Lud_ + "]");
                    matplotlibcpp::ylabel("Mole fraction [-]");
                }
            }
        }

        if ( this->isChecked(siteButton_) )
        {
            for (unsigned int i=0;i<SURF_NC_;i++)
            {
                if ( siteButton_[i]->get_active() )
                {
                    matplotlibcpp::figure(nFig++);
                    std::vector<double> z(L_.size());
                    for (unsigned int k=0;k<t_.size();k++)
                    {
                        for (unsigned int j=0;j<L_.size();j++)
                        {
                            z[j] = std::max(0.,zt_[k][j][i]);
                        }
                        matplotlibcpp::plot(L_,z);
                    }
                    matplotlibcpp::title(nc_[i]);
                    matplotlibcpp::xlabel("Length [" + Lud_ + "]");
                    matplotlibcpp::ylabel("Coverage [-]");
                }
            }
        }
        matplotlibcpp::show();
    }

    void asaliPlot::destroy()
    {
        if ( NC_ != 0 )
        {
            for (unsigned int i=0;i<NC_;i++)
            {
                moleGrid_.remove(*moleButton_[i]);
                massGrid_.remove(*massButton_[i]);
            }
            
            if ( SURF_NC_ == 0 )
            {
                mainGrid_.attach(siteLabel_,0,4,1,1);
                mainGrid_.attach(siteGrid_,0,5,1,1);
            }
            else
            {
                for (unsigned int i=0;i<SURF_NC_;i++)
                {
                    siteGrid_.remove(*siteButton_[i]);
                }
            }

            for (unsigned int i=0;i<otherButton_.size();i++)
            {
                otherGrid_.remove(*otherButton_[i]);
            }
            
            NC_      = 0;
            SURF_NC_ = 0;
        }
    }

    bool asaliPlot::isChecked(std::vector<Gtk::CheckButton *> button)
    {
        for (unsigned int i=0;i<button.size();i++)
        {
            if ( button[i]->get_active())
            {
                return true;
            }
        }
        return false;
    }
    
    void asaliPlot::setPythonPath()
    {
        #if ASALI_ON_WINDOW == 1
        std::string python_path = "python/";
        _putenv_s("PYTHONPATH",python_path.c_str());
        size_t python_path_size = strlen(python_path.c_str());
        const wchar_t* python_path_char = Py_DecodeLocale(python_path.c_str(),&python_path_size);
        Py_SetPythonHome(python_path_char);
        #endif
    }

    asaliPlot::~asaliPlot()
    {
    }
 
}
