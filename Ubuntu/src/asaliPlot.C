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

#include "asaliPlot.h"

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
        this->set_icon_from_file("images/Icon.tiff");

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

    void asaliPlot::setLength(const std::vector<double> L)
    {
        L_  = L;
        NP_ = L.size(); 
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
        Gtk::FileChooserDialog dialog("",Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER);
        dialog.set_transient_for(*this);

        //Add response buttons
        dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
        dialog.add_button("_Save", Gtk::RESPONSE_OK);

        //Show the dialog and wait for a user response
        int result = dialog.run();
        
        std::vector<std::string> massNames;
        std::vector<std::string> moleNames;
        std::vector<std::string> siteNames;

        std::string foldername;

        //Handle the response
        switch(result)
        {
            case(Gtk::RESPONSE_OK):
            {
                foldername = dialog.get_filename();
                if ( type_ == "batch" )
                {
                    if ( massButton_.size() != 0 )
                    {
                        //Make .dat for mass fraction
                        {
                            std::string filename = foldername + "/mass.dat";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            output.setf(std::ios::scientific);
                            output.precision(6);
                            for (unsigned int j=0;j<t_.size();j++)
                            {
                                output << t_[j] << "\t";
                                for (unsigned int i=0;i<NC_;i++)
                                {
                                    if ( massButton_[i]->get_active() )
                                    {
                                        output << std::max(0.,y_[j][i]) << "\t";

                                        if ( j == 0 )
                                        {
                                            massNames.push_back(n_[i]);
                                        }
                                    }
                                }
                                output << std::endl;
                            }
                            output.close();
                        }

                        //Make .gnuplot for mass fraction
                        if ( massNames.size() != 0 )
                        {
                            std::string filename = foldername + "/mass.gnuplot";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            
                            #if ASALI_ON_WINDOW == 0
                            output << "set terminal wxt 0" << std::endl;
                            output << "set ylabel 'Mass fraction [-]'" << std::endl;
                            output << "set xlabel 'Time [s]'" << std::endl;
                            output << "set key outside right center" << std::endl;;
                            output << "set size square" << std::endl;

                            for (unsigned int i=0;i<massNames.size();i++)
                            {
                                if ( i == 0 )
                                {
                                    output << "plot '" << foldername << "/mass.dat" << "' u 1:" << i+2 << " w l title '" << massNames[i] << "'";
                                }
                                else if ( i == (massNames.size() - 1) )
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mass.dat" << "' u 1:" << i+2 << " w l title '" << massNames[i] << "'";
                                }
                                else
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mass.dat" << "' u 1:" << i+2 << " w l title '" << massNames[i] << "'";
                                }
                            }

                            output << std::endl;
                            #endif
                            output << "set terminal pngcairo" << std::endl;
                            output << "set output '" << foldername << "/";
                            for (unsigned int i=0;i<massNames.size();i++)
                            {
                                output << massNames[i] << "_";
                            }
                            output << "massFraction.png'" << std::endl;

                            output << "set ylabel 'Mass fraction [-]'" << std::endl;
                            output << "set xlabel 'Time [s]'" << std::endl;
                            output << "set key outside right center" << std::endl;
                            output << "set size square" << std::endl;


                            for (unsigned int i=0;i<massNames.size();i++)
                            {
                                if ( i == 0 )
                                {
                                    output << "plot '" << foldername << "/mass.dat" << "' u 1:" << i+2 << " w l title '" << massNames[i] << "'";
                                }
                                else if ( i == (massNames.size() - 1) )
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mass.dat" << "' u 1:" << i+2 << " w l title '" << massNames[i] << "'";
                                }
                                else
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mass.dat" << "' u 1:" << i+2 << " w l title '" << massNames[i] << "'";
                                }
                            }

                            output.close();
                        }
                    }

                    if ( moleButton_.size() != 0 )
                    {
                        //Make .dat for mole fraction
                        {
                            std::string filename = foldername + "/mole.dat";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            output.setf(std::ios::scientific);
                            output.precision(6);
                            for (unsigned int j=0;j<t_.size();j++)
                            {
                                output << t_[j] << "\t";
                                for (unsigned int i=0;i<NC_;i++)
                                {
                                    if ( moleButton_[i]->get_active() )
                                    {
                                        output << std::max(0.,x_[j][i]) << "\t";

                                        if ( j == 0 )
                                        {
                                            moleNames.push_back(n_[i]);
                                        }
                                    }
                                }
                                output << std::endl;
                            }
                            output.close();
                        }

                        //Make .gnuplot for mole fraction
                        if ( moleNames.size() != 0 )
                        {
                            std::string filename = foldername + "/mole.gnuplot";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            #if ASALI_ON_WINDOW == 0
                            output << "set terminal wxt 1" << std::endl;
                            output << "set ylabel 'Mole fraction [-]'" << std::endl;
                            output << "set xlabel 'Time [s]'" << std::endl;
                            output << "set key outside right center" << std::endl;;
                            output << "set size square" << std::endl;

                            for (unsigned int i=0;i<moleNames.size();i++)
                            {
                                if ( i == 0 )
                                {
                                    output << "plot '" << foldername << "/mole.dat" << "' u 1:" << i+2 << " w l title '" << moleNames[i] << "'";
                                }
                                else if ( i == (massNames.size() - 1) )
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mole.dat" << "' u 1:" << i+2 << " w l title '" << moleNames[i] << "'";
                                }
                                else
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mole.dat" << "' u 1:" << i+2 << " w l title '" << moleNames[i] << "'";
                                }
                            }

                            output << std::endl;
                            #endif
                            output << "set terminal pngcairo" << std::endl;
                            output << "set output '" << foldername << "/";
                            for (unsigned int i=0;i<moleNames.size();i++)
                            {
                                output << moleNames[i] << "_";
                            }
                            output << "moleFraction.png'" << std::endl;

                            output << "set ylabel 'Mole fraction [-]'" << std::endl;
                            output << "set xlabel 'Time [s]'" << std::endl;
                            output << "set key outside right center" << std::endl;
                            output << "set size square" << std::endl;


                            for (unsigned int i=0;i<moleNames.size();i++)
                            {
                                if ( i == 0 )
                                {
                                    output << "plot '" << foldername << "/mole.dat" << "' u 1:" << i+2 << " w l title '" << moleNames[i] << "'";
                                }
                                else if ( i == (massNames.size() - 1) )
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mole.dat" << "' u 1:" << i+2 << " w l title '" << moleNames[i] << "'";
                                }
                                else
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mole.dat" << "' u 1:" << i+2 << " w l title '" << moleNames[i] << "'";
                                }
                            }

                            output.close();
                        }
                    }

                    if ( siteButton_.size() != 0 )
                    {
                        //Make .dat for coverage
                        {
                            std::string filename = foldername + "/site.dat";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            output.setf(std::ios::scientific);
                            output.precision(6);
                            for (unsigned int j=0;j<t_.size();j++)
                            {
                                output << t_[j] << "\t";
                                for (unsigned int i=0;i<SURF_NC_;i++)
                                {
                                    if ( siteButton_[i]->get_active() )
                                    {
                                        output << std::max(0.,z_[j][i]) << "\t";

                                        if ( j == 0 )
                                        {
                                            siteNames.push_back(nc_[i]);
                                        }
                                    }
                                }
                                output << std::endl;
                            }
                            output.close();
                        }

                        //Make .gnuplot for coverage
                        if ( siteNames.size() != 0 )
                        {
                            std::string filename = foldername + "/site.gnuplot";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            
                            #if ASALI_ON_WINDOW == 0
                            output << "set terminal wxt 2" << std::endl;
                            output << "set ylabel 'Coverage [-]'" << std::endl;
                            output << "set xlabel 'Time [s]'" << std::endl;
                            output << "set key outside right center" << std::endl;;
                            output << "set size square" << std::endl;

                            for (unsigned int i=0;i<siteNames.size();i++)
                            {
                                if ( i == 0 )
                                {
                                    output << "plot '" << foldername << "/site.dat" << "' u 1:" << i+2 << " w l title '" << siteNames[i] << "'";
                                }
                                else if ( i == (massNames.size() - 1) )
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/site.dat" << "' u 1:" << i+2 << " w l title '" << siteNames[i] << "'";
                                }
                                else
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/site.dat" << "' u 1:" << i+2 << " w l title '" << siteNames[i] << "'";
                                }
                            }

                            output << std::endl;
                            #endif
                            output << "set terminal pngcairo" << std::endl;
                            output << "set output '" << foldername << "/";
                            for (unsigned int i=0;i<siteNames.size();i++)
                            {
                                output << siteNames[i] << "_";
                            }
                            output << "coverage.png'" << std::endl;

                            output << "set ylabel 'Coverage [-]'" << std::endl;
                            output << "set xlabel 'Time [s]'" << std::endl;
                            output << "set key outside right center" << std::endl;
                            output << "set size square" << std::endl;


                            for (unsigned int i=0;i<siteNames.size();i++)
                            {
                                if ( i == 0 )
                                {
                                    output << "plot '" << foldername << "/site.dat" << "' u 1:" << i+2 << " w l title '" << siteNames[i] << "'";
                                }
                                else if ( i == (massNames.size() - 1) )
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/site.dat" << "' u 1:" << i+2 << " w l title '" << siteNames[i] << "'";
                                }
                                else
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/site.dat" << "' u 1:" << i+2 << " w l title '" << siteNames[i] << "'";
                                }
                            }

                            output.close();
                        }
                    }


                    //Make .dat for other
                    if ( otherButton_.size() != 0 )
                    {
                        {
                            std::string filename = foldername + "/other.dat";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            output.setf(std::ios::scientific);
                            output.precision(6);
                            for (unsigned int j=0;j<t_.size();j++)
                            {
                                output << t_[j] << "\t" << V_[j] << "\t" << T_[j] << std::endl;
                            }
                            output.close();
                        }

                        //Make .gnuplot for other
                        {
                            std::string filename = foldername + "/other.gnuplot";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            
                            if ( otherButton_[1]->get_active() )
                            {
                                #if ASALI_ON_WINDOW == 0
                                output << "set terminal wxt 3" << std::endl;
                                output << "set ylabel 'Volume [m3]'" << std::endl;
                                output << "set xlabel 'Time [s]'" << std::endl;
                                output << "set key off" << std::endl;;
                                output << "set size square" << std::endl;
                                output << "plot '" << foldername << "/other.dat" << "' u 1:2 w l" << std::endl;
                                #endif

                                output << "set terminal pngcairo" << std::endl;
                                output << "set output '" << foldername << "/Volume.png'" << std::endl;
                                output << "set ylabel 'Volume [m3]'" << std::endl;
                                output << "set xlabel 'Time [s]'" << std::endl;
                                output << "set key off" << std::endl;;
                                output << "set size square" << std::endl;
                                output << "plot '" << foldername << "/other.dat" << "' u 1:2 w l" << std::endl;
                            }
                            
                            if ( otherButton_[0]->get_active() )
                            {
                                #if ASALI_ON_WINDOW == 0
                                output << "set terminal wxt 4" << std::endl;
                                output << "set ylabel 'Temperature [K]'" << std::endl;
                                output << "set xlabel 'Time [s]'" << std::endl;
                                output << "set key off" << std::endl;;
                                output << "set size square" << std::endl;
                                output << "plot '" << foldername << "/other.dat" << "' u 1:3 w l" << std::endl;
                                #endif

                                output << "set terminal pngcairo" << std::endl;
                                output << "set output '" << foldername << "/Temperature.png'" << std::endl;
                                output << "set ylabel 'Temperature [K]'" << std::endl;
                                output << "set xlabel 'Time [s]'" << std::endl;
                                output << "set key off" << std::endl;;
                                output << "set size square" << std::endl;
                                output << "plot '" << foldername << "/other.dat" << "' u 1:3 w l" << std::endl;
                            }

                            output.close();
                        }
                    }
                }
                else if ( type_ == "ph1d" && resolution_ == "steady state")
                {
                    if ( massButton_.size() != 0 )
                    {
                        //Make .dat for mass fraction
                        {
                            std::string filename = foldername + "/mass.dat";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            output.setf(std::ios::scientific);
                            output.precision(6);
                            for (unsigned int j=0;j<L_.size();j++)
                            {
                                output << L_[j] << "\t";
                                for (unsigned int i=0;i<NC_;i++)
                                {
                                    if ( massButton_[i]->get_active() )
                                    {
                                        output << std::max(0.,y_[j][i]) << "\t";

                                        if ( j == 0 )
                                        {
                                            massNames.push_back(n_[i]);
                                        }
                                    }
                                }
                                output << std::endl;
                            }
                            output.close();
                        }

                        //Make .gnuplot for mass fraction
                        if ( massNames.size() != 0 )
                        {
                            std::string filename = foldername + "/mass.gnuplot";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            
                            #if ASALI_ON_WINDOW == 0
                            output << "set terminal wxt 0" << std::endl;
                            output << "set ylabel 'Mass fraction [-]'" << std::endl;
                            output << "set xlabel 'Length [m]'" << std::endl;
                            output << "set key outside right center" << std::endl;;
                            output << "set size square" << std::endl;

                            for (unsigned int i=0;i<massNames.size();i++)
                            {
                                if ( i == 0 )
                                {
                                    output << "plot '" << foldername << "/mass.dat" << "' u 1:" << i+2 << " w l title '" << massNames[i] << "'";
                                }
                                else if ( i == (massNames.size() - 1) )
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mass.dat" << "' u 1:" << i+2 << " w l title '" << massNames[i] << "'";
                                }
                                else
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mass.dat" << "' u 1:" << i+2 << " w l title '" << massNames[i] << "'";
                                }
                            }

                            output << std::endl;
                            #endif
                            output << "set terminal pngcairo" << std::endl;
                            output << "set output '" << foldername << "/";
                            for (unsigned int i=0;i<massNames.size();i++)
                            {
                                output << massNames[i] << "_";
                            }
                            output << "massFraction.png'" << std::endl;

                            output << "set ylabel 'Mass fraction [-]'" << std::endl;
                            output << "set xlabel 'Length [m]'" << std::endl;
                            output << "set key outside right center" << std::endl;
                            output << "set size square" << std::endl;


                            for (unsigned int i=0;i<massNames.size();i++)
                            {
                                if ( i == 0 )
                                {
                                    output << "plot '" << foldername << "/mass.dat" << "' u 1:" << i+2 << " w l title '" << massNames[i] << "'";
                                }
                                else if ( i == (massNames.size() - 1) )
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mass.dat" << "' u 1:" << i+2 << " w l title '" << massNames[i] << "'";
                                }
                                else
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mass.dat" << "' u 1:" << i+2 << " w l title '" << massNames[i] << "'";
                                }
                            }

                            output.close();
                        }
                    }

                    if ( moleButton_.size() != 0 )
                    {
                        //Make .dat for mole fraction
                        {
                            std::string filename = foldername + "/mole.dat";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            output.setf(std::ios::scientific);
                            output.precision(6);
                            for (unsigned int j=0;j<L_.size();j++)
                            {
                                output << L_[j] << "\t";
                                for (unsigned int i=0;i<NC_;i++)
                                {
                                    if ( moleButton_[i]->get_active() )
                                    {
                                        output << std::max(0.,x_[j][i]) << "\t";

                                        if ( j == 0 )
                                        {
                                            moleNames.push_back(n_[i]);
                                        }
                                    }
                                }
                                output << std::endl;
                            }
                            output.close();
                        }

                        //Make .gnuplot for mole fraction
                        if ( moleNames.size() != 0 )
                        {
                            std::string filename = foldername + "/mole.gnuplot";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            
                            #if ASALI_ON_WINDOW == 0
                            output << "set terminal wxt 1" << std::endl;
                            output << "set ylabel 'Mole fraction [-]'" << std::endl;
                            output << "set xlabel 'Length [m]'" << std::endl;
                            output << "set key outside right center" << std::endl;;
                            output << "set size square" << std::endl;

                            for (unsigned int i=0;i<moleNames.size();i++)
                            {
                                if ( i == 0 )
                                {
                                    output << "plot '" << foldername << "/mole.dat" << "' u 1:" << i+2 << " w l title '" << moleNames[i] << "'";
                                }
                                else if ( i == (massNames.size() - 1) )
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mole.dat" << "' u 1:" << i+2 << " w l title '" << moleNames[i] << "'";
                                }
                                else
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mole.dat" << "' u 1:" << i+2 << " w l title '" << moleNames[i] << "'";
                                }
                            }

                            output << std::endl;
                            #endif
                            output << "set terminal pngcairo" << std::endl;
                            output << "set output '" << foldername << "/";
                            for (unsigned int i=0;i<moleNames.size();i++)
                            {
                                output << moleNames[i] << "_";
                            }
                            output << "moleFraction.png'" << std::endl;

                            output << "set ylabel 'Mole fraction [-]'" << std::endl;
                            output << "set xlabel 'Length [m]'" << std::endl;
                            output << "set key outside right center" << std::endl;
                            output << "set size square" << std::endl;


                            for (unsigned int i=0;i<moleNames.size();i++)
                            {
                                if ( i == 0 )
                                {
                                    output << "plot '" << foldername << "/mole.dat" << "' u 1:" << i+2 << " w l title '" << moleNames[i] << "'";
                                }
                                else if ( i == (massNames.size() - 1) )
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mole.dat" << "' u 1:" << i+2 << " w l title '" << moleNames[i] << "'";
                                }
                                else
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mole.dat" << "' u 1:" << i+2 << " w l title '" << moleNames[i] << "'";
                                }
                            }

                            output.close();
                        }
                    }


                    if ( siteButton_.size() != 0 )
                    {
                        //Make .dat for coverage
                        {
                            std::string filename = foldername + "/site.dat";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            output.setf(std::ios::scientific);
                            output.precision(6);
                            for (unsigned int j=0;j<L_.size();j++)
                            {
                                output << L_[j] << "\t";
                                for (unsigned int i=0;i<SURF_NC_;i++)
                                {
                                    if ( siteButton_[i]->get_active() )
                                    {
                                        output << std::max(0.,z_[j][i]) << "\t";

                                        if ( j == 0 )
                                        {
                                            siteNames.push_back(nc_[i]);
                                        }
                                    }
                                }
                                output << std::endl;
                            }
                            output.close();
                        }

                        //Make .gnuplot for coverage
                        if ( siteNames.size() != 0 )
                        {
                            std::string filename = foldername + "/site.gnuplot";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            
                            #if ASALI_ON_WINDOW == 0
                            output << "set terminal wxt 2" << std::endl;
                            output << "set ylabel 'Coverage [-]'" << std::endl;
                            output << "set xlabel 'Length [m]'" << std::endl;
                            output << "set key outside right center" << std::endl;;
                            output << "set size square" << std::endl;

                            for (unsigned int i=0;i<siteNames.size();i++)
                            {
                                if ( i == 0 )
                                {
                                    output << "plot '" << foldername << "/site.dat" << "' u 1:" << i+2 << " w l title '" << siteNames[i] << "'";
                                }
                                else if ( i == (massNames.size() - 1) )
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/site.dat" << "' u 1:" << i+2 << " w l title '" << siteNames[i] << "'";
                                }
                                else
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/site.dat" << "' u 1:" << i+2 << " w l title '" << siteNames[i] << "'";
                                }
                            }

                            output << std::endl;
                            #endif
                            output << "set terminal pngcairo" << std::endl;
                            output << "set output '" << foldername << "/";
                            for (unsigned int i=0;i<siteNames.size();i++)
                            {
                                output << siteNames[i] << "_";
                            }
                            output << "coverage.png'" << std::endl;

                            output << "set ylabel 'Coverage [-]'" << std::endl;
                            output << "set xlabel 'Length [m]'" << std::endl;
                            output << "set key outside right center" << std::endl;
                            output << "set size square" << std::endl;


                            for (unsigned int i=0;i<siteNames.size();i++)
                            {
                                if ( i == 0 )
                                {
                                    output << "plot '" << foldername << "/site.dat" << "' u 1:" << i+2 << " w l title '" << siteNames[i] << "'";
                                }
                                else if ( i == (massNames.size() - 1) )
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/site.dat" << "' u 1:" << i+2 << " w l title '" << siteNames[i] << "'";
                                }
                                else
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/site.dat" << "' u 1:" << i+2 << " w l title '" << siteNames[i] << "'";
                                }
                            }

                            output.close();
                        }
                        
                    }


                    //Make .dat for other
                    if ( otherButton_.size() != 0 )
                    {
                        {
                            std::string filename = foldername + "/other.dat";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            output.setf(std::ios::scientific);
                            output.precision(6);
                            for (unsigned int j=0;j<L_.size();j++)
                            {
                                output << L_[j] << "\t" << T_[j] << std::endl;
                            }
                            output.close();
                        }

                        //Make .gnuplot for other
                        {
                            std::string filename = foldername + "/other.gnuplot";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            
                            if ( otherButton_[0]->get_active() )
                            {
                                #if ASALI_ON_WINDOW == 0
                                output << "set terminal wxt 3" << std::endl;
                                output << "set ylabel 'Temperature [K]'" << std::endl;
                                output << "set xlabel 'Time [s]'" << std::endl;
                                output << "set key off" << std::endl;;
                                output << "set size square" << std::endl;
                                output << "plot '" << foldername << "/other.dat" << "' u 1:2 w l" << std::endl;
                                #endif

                                output << "set terminal pngcairo" << std::endl;
                                output << "set output '" << foldername << "/Temperature.png'" << std::endl;
                                output << "set ylabel 'Temperature [K]'" << std::endl;
                                output << "set xlabel 'Time [s]'" << std::endl;
                                output << "set key off" << std::endl;;
                                output << "set size square" << std::endl;
                                output << "plot '" << foldername << "/other.dat" << "' u 1:2 w l" << std::endl;
                            }

                            output.close();
                        }
                    }
                }
                else if ( type_ == "ph1d" && resolution_ == "transient")
                {
                    if ( massButton_.size() != 0 )
                    {
                        //Make .dat for mass fraction
                        for (unsigned int i=0;i<NC_;i++)
                        {
                            if ( massButton_[i]->get_active() )
                            {
                                massNames.push_back(n_[i]);

                                std::string filename = foldername + "/mass." + n_[i] + ".dat";
                                std::ofstream output;
                                const char *path = filename.c_str();
                                output.open(path,std::ios::out);
                                output.setf(std::ios::scientific);
                                output.precision(6);
                                for (unsigned int j=0;j<L_.size();j++)
                                {
                                    output << L_[j] << "\t";
                                    for (unsigned int k=0;k<t_.size();k++)
                                    {
                                        output << std::max(0.,yt_[k][j][i]) << "\t";
                                    }
                                    output << std::endl;
                                }
                                output.close();
                            }
                        }

                        //Make .gnuplot for mass fraction
                        if ( massNames.size() != 0 )
                        {
                            int Ncol = 3;
                            int Nrow = std::round(massNames.size()/Ncol);

                            if ( Nrow == 0 )
                            {
                                Ncol = massNames.size();
                                Nrow = 1;
                            }
                            else
                            {
                                int diff = massNames.size() - Nrow*Ncol;
                                
                                if ( diff != 0 )
                                {
                                    Nrow++;
                                }
                            }

                            std::string filename = foldername + "/mass.gnuplot";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            
                            #if ASALI_ON_WINDOW == 0
                            output << "set terminal wxt 0 font 'Helvetica,10' size " << 320*Ncol << "," << 320*Nrow << std::endl;
                            output << "set ylabel 'Mass fraction [-]'" << std::endl;
                            output << "set xlabel 'Length [m]'" << std::endl;
                            output << "unset key" << std::endl;   
                            output << "set multiplot layout " << Nrow << "," << Ncol << std::endl;

                            for (unsigned int i=0;i<massNames.size();i++)
                            {
                                output << "set title '" << massNames[i] << "'" << std::endl;
                                for (unsigned int k=0;k<t_.size();k++)
                                {
                                    if ( k == 0 )
                                    {
                                        output << "plot '" << foldername << "/mass." << massNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else if ( i == (massNames.size() - 1) )
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/mass." << massNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/mass." << massNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                }
                                output << std::endl;
                            }
                            output << "unset multiplot " << std::endl;
                            #endif

                            output << std::endl;
                            output << "set terminal pngcairo font 'Helvetica,10' size " << 320*Ncol << "," << 320*Nrow << std::endl;
                            output << "set output '" << foldername << "/";
                            for (unsigned int i=0;i<massNames.size();i++)
                            {
                                output << massNames[i] << "_";
                            }
                            output << "massFraction.png'" << std::endl;

                            output << "set ylabel 'Mass fraction [-]'" << std::endl;
                            output << "set xlabel 'Length [m]'" << std::endl;
                            output << "unset key" << std::endl;;
                            output << "set multiplot layout " << Nrow << "," << Ncol << std::endl;

                            for (unsigned int i=0;i<massNames.size();i++)
                            {
                                output << "set title '" << massNames[i] << "'" << std::endl;
                                for (unsigned int k=0;k<t_.size();k++)
                                {
                                    if ( k == 0 )
                                    {
                                        output << "plot '" << foldername << "/mass." << massNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else if ( i == (massNames.size() - 1) )
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/mass." << massNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/mass." << massNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                }
                                output << std::endl;
                            }
                            output << "unset multiplot " << std::endl;

                            output.close();
                        }
                    }

                    if ( moleButton_.size() != 0 )
                    {
                        //Make .dat for mole fraction
                        for (unsigned int i=0;i<NC_;i++)
                        {
                            if ( moleButton_[i]->get_active() )
                            {
                                moleNames.push_back(n_[i]);

                                std::string filename = foldername + "/mole." + n_[i] + ".dat";
                                std::ofstream output;
                                const char *path = filename.c_str();
                                output.open(path,std::ios::out);
                                output.setf(std::ios::scientific);
                                output.precision(6);
                                for (unsigned int j=0;j<L_.size();j++)
                                {
                                    output << L_[j] << "\t";
                                    for (unsigned int k=0;k<t_.size();k++)
                                    {
                                        output << std::max(0.,xt_[k][j][i]) << "\t";
                                    }
                                    output << std::endl;
                                }
                                output.close();
                            }
                        }

                        //Make .gnuplot for mole fraction
                        if ( moleNames.size() != 0 )
                        {
                            int Ncol = 3;
                            int Nrow = std::round(moleNames.size()/Ncol);

                            if ( Nrow == 0 )
                            {
                                Ncol = moleNames.size();
                                Nrow = 1;
                            }
                            else
                            {
                                int diff = moleNames.size() - Nrow*Ncol;
                                
                                if ( diff != 0 )
                                {
                                    Nrow++;
                                }
                            }

                            std::string filename = foldername + "/mole.gnuplot";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            
                            #if ASALI_ON_WINDOW == 0
                            output << "set terminal wxt 0 font 'Helvetica,10' size " << 320*Ncol << "," << 320*Nrow << std::endl;
                            output << "set ylabel 'Mole fraction [-]'" << std::endl;
                            output << "set xlabel 'Length [m]'" << std::endl;
                            output << "unset key" << std::endl;   
                            output << "set multiplot layout " << Nrow << "," << Ncol << std::endl;

                            for (unsigned int i=0;i<moleNames.size();i++)
                            {
                                output << "set title '" << moleNames[i] << "'" << std::endl;
                                for (unsigned int k=0;k<t_.size();k++)
                                {
                                    if ( k == 0 )
                                    {
                                        output << "plot '" << foldername << "/mole." << moleNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else if ( i == (moleNames.size() - 1) )
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/mole." << moleNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/mole." << moleNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                }
                                output << std::endl;
                            }
                            output << "unset multiplot " << std::endl;
                            #endif

                            output << std::endl;
                            output << "set terminal pngcairo font 'Helvetica,10' size " << 320*Ncol << "," << 320*Nrow << std::endl;
                            output << "set output '" << foldername << "/";
                            for (unsigned int i=0;i<moleNames.size();i++)
                            {
                                output << moleNames[i] << "_";
                            }
                            output << "moleFraction.png'" << std::endl;

                            output << "set ylabel 'Mole fraction [-]'" << std::endl;
                            output << "set xlabel 'Length [m]'" << std::endl;
                            output << "unset key" << std::endl;;
                            output << "set multiplot layout " << Nrow << "," << Ncol << std::endl;

                            for (unsigned int i=0;i<moleNames.size();i++)
                            {
                                output << "set title '" << moleNames[i] << "'" << std::endl;
                                for (unsigned int k=0;k<t_.size();k++)
                                {
                                    if ( k == 0 )
                                    {
                                        output << "plot '" << foldername << "/mole." << moleNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else if ( i == (moleNames.size() - 1) )
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/mole." << moleNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/mole." << moleNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                }
                                output << std::endl;
                            }
                            output << "unset multiplot " << std::endl;

                            output.close();
                        }
                    }

                    if ( siteButton_.size() != 0 )
                    {
                        //Make .dat for coverage
                        for (unsigned int i=0;i<SURF_NC_;i++)
                        {
                            if ( siteButton_[i]->get_active() )
                            {
                                siteNames.push_back(nc_[i]);

                                std::string filename = foldername + "/site." + nc_[i] + ".dat";
                                std::ofstream output;
                                const char *path = filename.c_str();
                                output.open(path,std::ios::out);
                                output.setf(std::ios::scientific);
                                output.precision(6);
                                for (unsigned int j=0;j<L_.size();j++)
                                {
                                    output << L_[j] << "\t";
                                    for (unsigned int k=0;k<t_.size();k++)
                                    {
                                        output << std::max(0.,zt_[k][j][i]) << "\t";
                                    }
                                    output << std::endl;
                                }
                                output.close();
                            }
                        }
                        
                        //Make .gnuplot for coverage
                        if ( siteNames.size() != 0 )
                        {
                            int Ncol = 3;
                            int Nrow = std::round(siteNames.size()/Ncol);

                            if ( Nrow == 0 )
                            {
                                Ncol = siteNames.size();
                                Nrow = 1;
                            }
                            else
                            {
                                int diff = siteNames.size() - Nrow*Ncol;
                                
                                if ( diff != 0 )
                                {
                                    Nrow++;
                                }
                            }

                            std::string filename = foldername + "/site.gnuplot";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            
                            #if ASALI_ON_WINDOW == 0
                            output << "set terminal wxt 0 font 'Helvetica,10' size " << 320*Ncol << "," << 320*Nrow << std::endl;
                            output << "set ylabel 'Coverage [-]'" << std::endl;
                            output << "set xlabel 'Length [m]'" << std::endl;
                            output << "unset key" << std::endl;   
                            output << "set multiplot layout " << Nrow << "," << Ncol << std::endl;

                            for (unsigned int i=0;i<siteNames.size();i++)
                            {
                                output << "set title '" << siteNames[i] << "'" << std::endl;
                                for (unsigned int k=0;k<t_.size();k++)
                                {
                                    if ( k == 0 )
                                    {
                                        output << "plot '" << foldername << "/site." << siteNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else if ( i == (siteNames.size() - 1) )
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/site." << siteNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/site." << siteNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                }
                                output << std::endl;
                            }
                            output << "unset multiplot " << std::endl;
                            #endif

                            output << std::endl;
                            output << "set terminal pngcairo font 'Helvetica,10' size " << 320*Ncol << "," << 320*Nrow << std::endl;
                            output << "set output '" << foldername << "/";
                            for (unsigned int i=0;i<siteNames.size();i++)
                            {
                                output << siteNames[i] << "_";
                            }
                            output << "siteFraction.png'" << std::endl;

                            output << "set ylabel 'Coverage [-]'" << std::endl;
                            output << "set xlabel 'Length [m]'" << std::endl;
                            output << "unset key" << std::endl;;
                            output << "set multiplot layout " << Nrow << "," << Ncol << std::endl;

                            for (unsigned int i=0;i<siteNames.size();i++)
                            {
                                output << "set title '" << siteNames[i] << "'" << std::endl;
                                for (unsigned int k=0;k<t_.size();k++)
                                {
                                    if ( k == 0 )
                                    {
                                        output << "plot '" << foldername << "/site." << siteNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else if ( i == (siteNames.size() - 1) )
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/site." << siteNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/site." << siteNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                }
                                output << std::endl;
                            }
                            output << "unset multiplot " << std::endl;

                            output.close();
                        }
                    }

                    //Make .dat for other
                    if ( otherButton_.size() != 0 )
                    {
                        {
                            std::string filename = foldername + "/other.dat";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            output.setf(std::ios::scientific);
                            output.precision(6);
                            for (unsigned int j=0;j<L_.size();j++)
                            {
                                output << L_[j] << "\t";
                                for (unsigned int k=0;k<t_.size();k++)
                                {
                                    output << std::max(0.,Tt_[k][j]) << "\t";
                                }
                                output << std::endl;
                            }
                            output.close();
                        }

                        //Make .gnuplot for other
                        {
                            std::string filename = foldername + "/other.gnuplot";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            
                            if ( otherButton_[0]->get_active() )
                            {
                                #if ASALI_ON_WINDOW == 0
                                output << "set terminal wxt 0 font 'Helvetica,10' "<< std::endl;
                                output << "set ylabel 'Temperature [K]'" << std::endl;
                                output << "set xlabel 'Length [m]'" << std::endl;
                                output << "unset key" << std::endl;   

                                for (unsigned int k=0;k<t_.size();k++)
                                {
                                    if ( k == 0 )
                                    {
                                        output << "plot '" << foldername << "/other.dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/other.dat" << "' u 1:" << k+2 << " w l";
                                    }
                                }
                                output << std::endl;
                                #endif

                                output << std::endl;
                                output << "set terminal pngcairo font 'Helvetica,10' " << std::endl;
                                output << "set output '" << foldername << "/Temperature.png'" << std::endl;

                                output << "set ylabel 'Temperature [K]'" << std::endl;
                                output << "set xlabel 'Length [m]'" << std::endl;
                                output << "unset key" << std::endl;;

                                for (unsigned int k=0;k<t_.size();k++)
                                {
                                    if ( k == 0 )
                                    {
                                        output << "plot '" << foldername << "/other.dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/other.dat" << "' u 1:" << k+2 << " w l";
                                    }
                                }
                                output << std::endl;

                            }

                            output.close();
                        }
                    }
                }
                else if ( type_ == "cstr" )
                {
                    if ( massButton_.size() != 0 )
                    {
                        //Make .dat for mass fraction
                        {
                            std::string filename = foldername + "/mass.dat";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            output.setf(std::ios::scientific);
                            output.precision(6);
                            for (unsigned int j=0;j<t_.size();j++)
                            {
                                output << t_[j] << "\t";
                                for (unsigned int i=0;i<NC_;i++)
                                {
                                    if ( massButton_[i]->get_active() )
                                    {
                                        output << std::max(0.,y_[j][i]) << "\t";

                                        if ( j == 0 )
                                        {
                                            massNames.push_back(n_[i]);
                                        }
                                    }
                                }
                                output << std::endl;
                            }
                            output.close();
                        }

                        //Make .gnuplot for mass fraction
                        if ( massNames.size() != 0 )
                        {
                            std::string filename = foldername + "/mass.gnuplot";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            
                            #if ASALI_ON_WINDOW == 0
                            output << "set terminal wxt 0" << std::endl;
                            output << "set ylabel 'Mass fraction [-]'" << std::endl;
                            output << "set xlabel 'Time [s]'" << std::endl;
                            output << "set key outside right center" << std::endl;;
                            output << "set size square" << std::endl;

                            for (unsigned int i=0;i<massNames.size();i++)
                            {
                                if ( i == 0 )
                                {
                                    output << "plot '" << foldername << "/mass.dat" << "' u 1:" << i+2 << " w l title '" << massNames[i] << "'";
                                }
                                else if ( i == (massNames.size() - 1) )
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mass.dat" << "' u 1:" << i+2 << " w l title '" << massNames[i] << "'";
                                }
                                else
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mass.dat" << "' u 1:" << i+2 << " w l title '" << massNames[i] << "'";
                                }
                            }

                            output << std::endl;
                            #endif
                            output << "set terminal pngcairo" << std::endl;
                            output << "set output '" << foldername << "/";
                            for (unsigned int i=0;i<massNames.size();i++)
                            {
                                output << massNames[i] << "_";
                            }
                            output << "massFraction.png'" << std::endl;

                            output << "set ylabel 'Mass fraction [-]'" << std::endl;
                            output << "set xlabel 'Time [s]'" << std::endl;
                            output << "set key outside right center" << std::endl;
                            output << "set size square" << std::endl;


                            for (unsigned int i=0;i<massNames.size();i++)
                            {
                                if ( i == 0 )
                                {
                                    output << "plot '" << foldername << "/mass.dat" << "' u 1:" << i+2 << " w l title '" << massNames[i] << "'";
                                }
                                else if ( i == (massNames.size() - 1) )
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mass.dat" << "' u 1:" << i+2 << " w l title '" << massNames[i] << "'";
                                }
                                else
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mass.dat" << "' u 1:" << i+2 << " w l title '" << massNames[i] << "'";
                                }
                            }

                            output.close();
                        }
                    }

                    if ( moleButton_.size() != 0 )
                    {
                        //Make .dat for mole fraction
                        {
                            std::string filename = foldername + "/mole.dat";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            output.setf(std::ios::scientific);
                            output.precision(6);
                            for (unsigned int j=0;j<t_.size();j++)
                            {
                                output << t_[j] << "\t";
                                for (unsigned int i=0;i<NC_;i++)
                                {
                                    if ( moleButton_[i]->get_active() )
                                    {
                                        output << std::max(0.,x_[j][i]) << "\t";

                                        if ( j == 0 )
                                        {
                                            moleNames.push_back(n_[i]);
                                        }
                                    }
                                }
                                output << std::endl;
                            }
                            output.close();
                        }

                        //Make .gnuplot for mole fraction
                        if ( moleNames.size() != 0 )
                        {
                            std::string filename = foldername + "/mole.gnuplot";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            
                            #if ASALI_ON_WINDOW == 0
                            output << "set terminal wxt 1" << std::endl;
                            output << "set ylabel 'Mole fraction [-]'" << std::endl;
                            output << "set xlabel 'Time [s]'" << std::endl;
                            output << "set key outside right center" << std::endl;;
                            output << "set size square" << std::endl;

                            for (unsigned int i=0;i<moleNames.size();i++)
                            {
                                if ( i == 0 )
                                {
                                    output << "plot '" << foldername << "/mole.dat" << "' u 1:" << i+2 << " w l title '" << moleNames[i] << "'";
                                }
                                else if ( i == (massNames.size() - 1) )
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mole.dat" << "' u 1:" << i+2 << " w l title '" << moleNames[i] << "'";
                                }
                                else
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mole.dat" << "' u 1:" << i+2 << " w l title '" << moleNames[i] << "'";
                                }
                            }

                            output << std::endl;
                            #endif
                            output << "set terminal pngcairo" << std::endl;
                            output << "set output '" << foldername << "/";
                            for (unsigned int i=0;i<moleNames.size();i++)
                            {
                                output << moleNames[i] << "_";
                            }
                            output << "moleFraction.png'" << std::endl;

                            output << "set ylabel 'Mole fraction [-]'" << std::endl;
                            output << "set xlabel 'Time [s]'" << std::endl;
                            output << "set key outside right center" << std::endl;
                            output << "set size square" << std::endl;


                            for (unsigned int i=0;i<moleNames.size();i++)
                            {
                                if ( i == 0 )
                                {
                                    output << "plot '" << foldername << "/mole.dat" << "' u 1:" << i+2 << " w l title '" << moleNames[i] << "'";
                                }
                                else if ( i == (massNames.size() - 1) )
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mole.dat" << "' u 1:" << i+2 << " w l title '" << moleNames[i] << "'";
                                }
                                else
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/mole.dat" << "' u 1:" << i+2 << " w l title '" << moleNames[i] << "'";
                                }
                            }

                            output.close();
                        }
                    }

                    if ( siteButton_.size() != 0 )
                    {
                        //Make .dat for coverage
                        {
                            std::string filename = foldername + "/site.dat";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            output.setf(std::ios::scientific);
                            output.precision(6);
                            for (unsigned int j=0;j<t_.size();j++)
                            {
                                output << t_[j] << "\t";
                                for (unsigned int i=0;i<SURF_NC_;i++)
                                {
                                    if ( siteButton_[i]->get_active() )
                                    {
                                        output << std::max(0.,z_[j][i]) << "\t";

                                        if ( j == 0 )
                                        {
                                            siteNames.push_back(nc_[i]);
                                        }
                                    }
                                }
                                output << std::endl;
                            }
                            output.close();
                        }

                        //Make .gnuplot for coverage
                        if ( siteNames.size() != 0 )
                        {
                            std::string filename = foldername + "/site.gnuplot";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            
                            #if ASALI_ON_WINDOW == 0
                            output << "set terminal wxt 2" << std::endl;
                            output << "set ylabel 'Coverage [-]'" << std::endl;
                            output << "set xlabel 'Time [s]'" << std::endl;
                            output << "set key outside right center" << std::endl;;
                            output << "set size square" << std::endl;

                            for (unsigned int i=0;i<siteNames.size();i++)
                            {
                                if ( i == 0 )
                                {
                                    output << "plot '" << foldername << "/site.dat" << "' u 1:" << i+2 << " w l title '" << siteNames[i] << "'";
                                }
                                else if ( i == (massNames.size() - 1) )
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/site.dat" << "' u 1:" << i+2 << " w l title '" << siteNames[i] << "'";
                                }
                                else
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/site.dat" << "' u 1:" << i+2 << " w l title '" << siteNames[i] << "'";
                                }
                            }

                            output << std::endl;
                            #endif
                            output << "set terminal pngcairo" << std::endl;
                            output << "set output '" << foldername << "/";
                            for (unsigned int i=0;i<siteNames.size();i++)
                            {
                                output << siteNames[i] << "_";
                            }
                            output << "coverage.png'" << std::endl;

                            output << "set ylabel 'Coverage [-]'" << std::endl;
                            output << "set xlabel 'Time [s]'" << std::endl;
                            output << "set key outside right center" << std::endl;
                            output << "set size square" << std::endl;


                            for (unsigned int i=0;i<siteNames.size();i++)
                            {
                                if ( i == 0 )
                                {
                                    output << "plot '" << foldername << "/site.dat" << "' u 1:" << i+2 << " w l title '" << siteNames[i] << "'";
                                }
                                else if ( i == (massNames.size() - 1) )
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/site.dat" << "' u 1:" << i+2 << " w l title '" << siteNames[i] << "'";
                                }
                                else
                                {
                                    output << ",\\" << std::endl;
                                    output << "     '" << foldername << "/site.dat" << "' u 1:" << i+2 << " w l title '" << siteNames[i] << "'";
                                }
                            }

                            output.close();
                        }
                    }


                    //Make .dat for other
                    if ( otherButton_.size() != 0 )
                    {
                        {
                            std::string filename = foldername + "/other.dat";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            output.setf(std::ios::scientific);
                            output.precision(6);
                            for (unsigned int j=0;j<t_.size();j++)
                            {
                                output << t_[j] << "\t" << T_[j] << std::endl;
                            }
                            output.close();
                        }

                        //Make .gnuplot for other
                        {
                            std::string filename = foldername + "/other.gnuplot";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);

                            if ( otherButton_[0]->get_active() )
                            {
                                #if ASALI_ON_WINDOW == 0
                                output << "set terminal wxt 4" << std::endl;
                                output << "set ylabel 'Temperature [K]'" << std::endl;
                                output << "set xlabel 'Time [s]'" << std::endl;
                                output << "set key off" << std::endl;;
                                output << "set size square" << std::endl;
                                output << "plot '" << foldername << "/other.dat" << "' u 1:2 w l" << std::endl;
                                #endif

                                output << "set terminal pngcairo" << std::endl;
                                output << "set output '" << foldername << "/Temperature.png'" << std::endl;
                                output << "set ylabel 'Temperature [K]'" << std::endl;
                                output << "set xlabel 'Time [s]'" << std::endl;
                                output << "set key off" << std::endl;;
                                output << "set size square" << std::endl;
                                output << "plot '" << foldername << "/other.dat" << "' u 1:2 w l" << std::endl;
                            }

                            output.close();
                        }
                    }
                }
                else if ( type_ == "het1d")
                {
                    if ( massButton_.size() != 0 )
                    {
                        //Make .dat for mass fraction
                        for (unsigned int i=0;i<NC_;i++)
                        {
                            if ( massButton_[i]->get_active() )
                            {
                                massNames.push_back(n_[i]);

                                std::string filename = foldername + "/mass." + n_[i] + ".dat";
                                std::ofstream output;
                                const char *path = filename.c_str();
                                output.open(path,std::ios::out);
                                output.setf(std::ios::scientific);
                                output.precision(6);
                                for (unsigned int j=0;j<L_.size();j++)
                                {
                                    output << L_[j] << "\t";
                                    for (unsigned int k=0;k<t_.size();k++)
                                    {
                                        output << std::max(0.,yt_[k][j][i]) << "\t";
                                    }
                                    output << std::endl;
                                }
                                output.close();
                            }
                        }

                        //Make .gnuplot for mass fraction
                        if ( massNames.size() != 0 )
                        {
                            int Ncol = 3;
                            int Nrow = std::round(massNames.size()/Ncol);

                            if ( Nrow == 0 )
                            {
                                Ncol = massNames.size();
                                Nrow = 1;
                            }
                            else
                            {
                                int diff = massNames.size() - Nrow*Ncol;
                                
                                if ( diff != 0 )
                                {
                                    Nrow++;
                                }
                            }

                            std::string filename = foldername + "/mass.gnuplot";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            
                            #if ASALI_ON_WINDOW == 0
                            output << "set terminal wxt 0 font 'Helvetica,10' size " << 320*Ncol << "," << 320*Nrow << std::endl;
                            output << "set ylabel 'Mass fraction [-]'" << std::endl;
                            output << "set xlabel 'Length [m]'" << std::endl;
                            output << "unset key" << std::endl;   
                            output << "set multiplot layout " << Nrow << "," << Ncol << std::endl;

                            for (unsigned int i=0;i<massNames.size();i++)
                            {
                                output << "set title '" << massNames[i] << "'" << std::endl;
                                for (unsigned int k=0;k<t_.size();k++)
                                {
                                    if ( k == 0 )
                                    {
                                        output << "plot '" << foldername << "/mass." << massNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else if ( i == (massNames.size() - 1) )
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/mass." << massNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/mass." << massNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                }
                                output << std::endl;
                            }
                            output << "unset multiplot " << std::endl;
                            #endif

                            output << std::endl;
                            output << "set terminal pngcairo font 'Helvetica,10' size " << 320*Ncol << "," << 320*Nrow << std::endl;
                            output << "set output '" << foldername << "/";
                            for (unsigned int i=0;i<massNames.size();i++)
                            {
                                output << massNames[i] << "_";
                            }
                            output << "massFraction.png'" << std::endl;

                            output << "set ylabel 'Mass fraction [-]'" << std::endl;
                            output << "set xlabel 'Length [m]'" << std::endl;
                            output << "unset key" << std::endl;;
                            output << "set multiplot layout " << Nrow << "," << Ncol << std::endl;

                            for (unsigned int i=0;i<massNames.size();i++)
                            {
                                output << "set title '" << massNames[i] << "'" << std::endl;
                                for (unsigned int k=0;k<t_.size();k++)
                                {
                                    if ( k == 0 )
                                    {
                                        output << "plot '" << foldername << "/mass." << massNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else if ( i == (massNames.size() - 1) )
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/mass." << massNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/mass." << massNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                }
                                output << std::endl;
                            }
                            output << "unset multiplot " << std::endl;

                            output.close();
                        }
                    }

                    if ( moleButton_.size() != 0 )
                    {
                        //Make .dat for mole fraction
                        for (unsigned int i=0;i<NC_;i++)
                        {
                            if ( moleButton_[i]->get_active() )
                            {
                                moleNames.push_back(n_[i]);

                                std::string filename = foldername + "/mole." + n_[i] + ".dat";
                                std::ofstream output;
                                const char *path = filename.c_str();
                                output.open(path,std::ios::out);
                                output.setf(std::ios::scientific);
                                output.precision(6);
                                for (unsigned int j=0;j<L_.size();j++)
                                {
                                    output << L_[j] << "\t";
                                    for (unsigned int k=0;k<t_.size();k++)
                                    {
                                        output << std::max(0.,xt_[k][j][i]) << "\t";
                                    }
                                    output << std::endl;
                                }
                                output.close();
                            }
                        }

                        //Make .gnuplot for mole fraction
                        if ( moleNames.size() != 0 )
                        {
                            int Ncol = 3;
                            int Nrow = std::round(moleNames.size()/Ncol);

                            if ( Nrow == 0 )
                            {
                                Ncol = moleNames.size();
                                Nrow = 1;
                            }
                            else
                            {
                                int diff = moleNames.size() - Nrow*Ncol;
                                
                                if ( diff != 0 )
                                {
                                    Nrow++;
                                }
                            }

                            std::string filename = foldername + "/mole.gnuplot";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            
                            #if ASALI_ON_WINDOW == 0
                            output << "set terminal wxt 0 font 'Helvetica,10' size " << 320*Ncol << "," << 320*Nrow << std::endl;
                            output << "set ylabel 'Mole fraction [-]'" << std::endl;
                            output << "set xlabel 'Length [m]'" << std::endl;
                            output << "unset key" << std::endl;   
                            output << "set multiplot layout " << Nrow << "," << Ncol << std::endl;

                            for (unsigned int i=0;i<moleNames.size();i++)
                            {
                                output << "set title '" << moleNames[i] << "'" << std::endl;
                                for (unsigned int k=0;k<t_.size();k++)
                                {
                                    if ( k == 0 )
                                    {
                                        output << "plot '" << foldername << "/mole." << moleNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else if ( i == (moleNames.size() - 1) )
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/mole." << moleNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/mole." << moleNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                }
                                output << std::endl;
                            }
                            output << "unset multiplot " << std::endl;
                            #endif

                            output << std::endl;
                            output << "set terminal pngcairo font 'Helvetica,10' size " << 320*Ncol << "," << 320*Nrow << std::endl;
                            output << "set output '" << foldername << "/";
                            for (unsigned int i=0;i<moleNames.size();i++)
                            {
                                output << moleNames[i] << "_";
                            }
                            output << "moleFraction.png'" << std::endl;

                            output << "set ylabel 'Mole fraction [-]'" << std::endl;
                            output << "set xlabel 'Length [m]'" << std::endl;
                            output << "unset key" << std::endl;;
                            output << "set multiplot layout " << Nrow << "," << Ncol << std::endl;

                            for (unsigned int i=0;i<moleNames.size();i++)
                            {
                                output << "set title '" << moleNames[i] << "'" << std::endl;
                                for (unsigned int k=0;k<t_.size();k++)
                                {
                                    if ( k == 0 )
                                    {
                                        output << "plot '" << foldername << "/mole." << moleNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else if ( i == (moleNames.size() - 1) )
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/mole." << moleNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/mole." << moleNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                }
                                output << std::endl;
                            }
                            output << "unset multiplot " << std::endl;

                            output.close();
                        }
                    }

                    if ( siteButton_.size() != 0 )
                    {
                        //Make .dat for coverage
                        for (unsigned int i=0;i<SURF_NC_;i++)
                        {
                            if ( siteButton_[i]->get_active() )
                            {
                                siteNames.push_back(nc_[i]);

                                std::string filename = foldername + "/site." + nc_[i] + ".dat";
                                std::ofstream output;
                                const char *path = filename.c_str();
                                output.open(path,std::ios::out);
                                output.setf(std::ios::scientific);
                                output.precision(6);
                                for (unsigned int j=0;j<L_.size();j++)
                                {
                                    output << L_[j] << "\t";
                                    for (unsigned int k=0;k<t_.size();k++)
                                    {
                                        output << std::max(0.,zt_[k][j][i]) << "\t";
                                    }
                                    output << std::endl;
                                }
                                output.close();
                            }
                        }
                        
                        //Make .gnuplot for coverage
                        if ( siteNames.size() != 0 )
                        {
                            int Ncol = 3;
                            int Nrow = std::round(siteNames.size()/Ncol);

                            if ( Nrow == 0 )
                            {
                                Ncol = siteNames.size();
                                Nrow = 1;
                            }
                            else
                            {
                                int diff = siteNames.size() - Nrow*Ncol;
                                
                                if ( diff != 0 )
                                {
                                    Nrow++;
                                }
                            }

                            std::string filename = foldername + "/site.gnuplot";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            
                            #if ASALI_ON_WINDOW == 0
                            output << "set terminal wxt 0 font 'Helvetica,10' size " << 320*Ncol << "," << 320*Nrow << std::endl;
                            output << "set ylabel 'Coverage [-]'" << std::endl;
                            output << "set xlabel 'Length [m]'" << std::endl;
                            output << "unset key" << std::endl;   
                            output << "set multiplot layout " << Nrow << "," << Ncol << std::endl;

                            for (unsigned int i=0;i<siteNames.size();i++)
                            {
                                output << "set title '" << siteNames[i] << "'" << std::endl;
                                for (unsigned int k=0;k<t_.size();k++)
                                {
                                    if ( k == 0 )
                                    {
                                        output << "plot '" << foldername << "/site." << siteNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else if ( i == (siteNames.size() - 1) )
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/site." << siteNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/site." << siteNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                }
                                output << std::endl;
                            }
                            output << "unset multiplot " << std::endl;
                            #endif

                            output << std::endl;
                            output << "set terminal pngcairo font 'Helvetica,10' size " << 320*Ncol << "," << 320*Nrow << std::endl;
                            output << "set output '" << foldername << "/";
                            for (unsigned int i=0;i<siteNames.size();i++)
                            {
                                output << siteNames[i] << "_";
                            }
                            output << "siteFraction.png'" << std::endl;

                            output << "set ylabel 'Coverage [-]'" << std::endl;
                            output << "set xlabel 'Length [m]'" << std::endl;
                            output << "unset key" << std::endl;;
                            output << "set multiplot layout " << Nrow << "," << Ncol << std::endl;

                            for (unsigned int i=0;i<siteNames.size();i++)
                            {
                                output << "set title '" << siteNames[i] << "'" << std::endl;
                                for (unsigned int k=0;k<t_.size();k++)
                                {
                                    if ( k == 0 )
                                    {
                                        output << "plot '" << foldername << "/site." << siteNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else if ( i == (siteNames.size() - 1) )
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/site." << siteNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/site." << siteNames[i] << ".dat" << "' u 1:" << k+2 << " w l";
                                    }
                                }
                                output << std::endl;
                            }
                            output << "unset multiplot " << std::endl;

                            output.close();
                        }
                    }

                    //Make .dat for other
                    if ( otherButton_.size() != 0 )
                    {
                        {
                            std::string filename = foldername + "/other.dat";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            output.setf(std::ios::scientific);
                            output.precision(6);
                            for (unsigned int j=0;j<L_.size();j++)
                            {
                                output << L_[j] << "\t";
                                for (unsigned int k=0;k<t_.size();k++)
                                {
                                    output << std::max(0.,Tb_[k][j]) << "\t";
                                }
                                for (unsigned int k=0;k<t_.size();k++)
                                {
                                    output << std::max(0.,Tw_[k][j]) << "\t";
                                }
                                output << std::endl;
                            }
                            output.close();
                        }

                        //Make .gnuplot for other
                        {
                            std::string filename = foldername + "/other.gnuplot";
                            std::ofstream output;
                            const char *path = filename.c_str();
                            output.open(path,std::ios::out);
                            
                            if ( otherButton_[0]->get_active() )
                            {
                                #if ASALI_ON_WINDOW == 0
                                output << "set terminal wxt 0 font 'Helvetica,10' "<< std::endl;
                                output << "set ylabel 'Bulk Temperature [K]'" << std::endl;
                                output << "set xlabel 'Length [m]'" << std::endl;
                                output << "unset key" << std::endl;   

                                for (unsigned int k=0;k<t_.size();k++)
                                {
                                    if ( k == 0 )
                                    {
                                        output << "plot '" << foldername << "/other.dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/other.dat" << "' u 1:" << k+2 << " w l";
                                    }
                                }
                                output << std::endl;
                                #endif

                                output << std::endl;
                                output << "set terminal pngcairo font 'Helvetica,10' " << std::endl;
                                output << "set output '" << foldername << "/Temperature_bulk.png'" << std::endl;

                                output << "set ylabel 'Bulk Temperature [K]'" << std::endl;
                                output << "set xlabel 'Length [m]'" << std::endl;
                                output << "unset key" << std::endl;;

                                for (unsigned int k=0;k<t_.size();k++)
                                {
                                    if ( k == 0 )
                                    {
                                        output << "plot '" << foldername << "/other.dat" << "' u 1:" << k+2 << " w l";
                                    }
                                    else
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/other.dat" << "' u 1:" << k+2 << " w l";
                                    }
                                }
                                output << std::endl;

                            }

                            if ( otherButton_[1]->get_active() )
                            {
                                #if ASALI_ON_WINDOW == 0
                                output << "set terminal wxt 0 font 'Helvetica,10' "<< std::endl;
                                output << "set ylabel 'Wall Temperature [K]'" << std::endl;
                                output << "set xlabel 'Length [m]'" << std::endl;
                                output << "unset key" << std::endl;   

                                for (unsigned int k=0;k<t_.size();k++)
                                {
                                    if ( k == 0 )
                                    {
                                        output << "plot '" << foldername << "/other.dat" << "' u 1:" << t_.size() + k + 2 << " w l";
                                    }
                                    else
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/other.dat" << "' u 1:" << t_.size() + k + 2 << " w l";
                                    }
                                }
                                output << std::endl;
                                #endif

                                output << std::endl;
                                output << "set terminal pngcairo font 'Helvetica,10' " << std::endl;
                                output << "set output '" << foldername << "/Temperature_wall.png'" << std::endl;

                                output << "set ylabel 'Wall Temperature [K]'" << std::endl;
                                output << "set xlabel 'Length [m]'" << std::endl;
                                output << "unset key" << std::endl;;

                                for (unsigned int k=0;k<t_.size();k++)
                                {
                                    if ( k == 0 )
                                    {
                                        output << "plot '" << foldername << "/other.dat" << "' u 1:" << t_.size() + k + 2 << " w l";
                                    }
                                    else
                                    {
                                        output << ",\\" << std::endl;
                                        output << "     '" << foldername << "/other.dat" << "' u 1:" << t_.size() + k + 2 << " w l";
                                    }
                                }
                                output << std::endl;

                            }

                            output.close();
                        }
                    }
                }
                dialog.hide();
                break;
            }
            case(Gtk::RESPONSE_CANCEL):
            {
                dialog.hide();
                break;
            }
            default:
            {
                std::cout << "Unexpected button clicked." << std::endl;
                break;
            }
        }

        if (bool(std::ifstream("mass.gnuplot")))
        {
            #if ASALI_ON_WINDOW == 1
            {
                std::string run = "wgnuplot.exe " + foldername + "\\mass.gnuplot -p";
                system(run.c_str());
            }
            #else
            {
                std::string run = "gnuplot " + foldername + "/mass.gnuplot -p";
                system(run.c_str());
            }
            #endif
            {
                std::string filename = foldername + "/mass.dat";
                if (bool(std::ifstream(filename)))
                    std::remove(filename.c_str());
            }
            for (unsigned int i=0;i<massNames.size();i++)
            {
                std::string filename = foldername + "/mass." + massNames[i] + ".dat";
                if (bool(std::ifstream(filename)))
                    std::remove(filename.c_str());
            }
            {
                std::string filename = foldername + "/mass.gnuplot";
                std::remove(filename.c_str());
            }
        }
  
        if (bool(std::ifstream("mole.gnuplot")))
        {
            #if ASALI_ON_WINDOW == 1
            {
                std::string run = "wgnuplot.exe " + foldername + "\\mole.gnuplot -p";
                system(run.c_str());
            }
            #else
            {
                std::string run = "gnuplot " + foldername + "/mole.gnuplot -p";
                system(run.c_str());
            }
            #endif
            {
                std::string filename = foldername + "/mole.dat";
                if (bool(std::ifstream(filename)))
                    std::remove(filename.c_str());
            }
            for (unsigned int i=0;i<moleNames.size();i++)
            {
                std::string filename = foldername + "/mole." + moleNames[i] + ".dat";
                if (bool(std::ifstream(filename)))
                    std::remove(filename.c_str());
            }
            {
                std::string filename = foldername + "/mole.gnuplot";
                std::remove(filename.c_str());
            }
        }

        if (bool(std::ifstream("site.gnuplot")))
        {
            #if ASALI_ON_WINDOW == 1
            {
                std::string run = "wgnuplot.exe " + foldername + "\\site.gnuplot -p";
                system(run.c_str());
            }
            #else
            {
                std::string run = "gnuplot " + foldername + "/site.gnuplot -p";
                system(run.c_str());
            }
            #endif
            {
                std::string filename = foldername + "/site.dat";
                if (bool(std::ifstream(filename)))
                    std::remove(filename.c_str());
            }
            for (unsigned int i=0;i<siteNames.size();i++)
            {
                std::string filename = foldername + "/site." + siteNames[i] + ".dat";
                if (bool(std::ifstream(filename)))
                    std::remove(filename.c_str());
            }
            {
                std::string filename = foldername + "/site.gnuplot";
                std::remove(filename.c_str());
            }
        }

        if (bool(std::ifstream("other.gnuplot")))
        {
            #if ASALI_ON_WINDOW == 1
            {
                std::string run = "wgnuplot.exe " + foldername + "\\other.gnuplot -p";
                system(run.c_str());
            }
            #else
            {
                std::string run = "gnuplot " + foldername + "/other.gnuplot -p";
                system(run.c_str());
            }
            #endif
            {
                std::string filename = foldername + "/other.dat";
                if (bool(std::ifstream(filename)))
                    std::remove(filename.c_str());
            }
            {
                std::string filename = foldername + "/other.gnuplot";
                std::remove(filename.c_str());
            }
        }
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

    asaliPlot::~asaliPlot()
    {
    }
 
}
