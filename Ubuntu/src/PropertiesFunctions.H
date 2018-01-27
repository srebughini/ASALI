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
#   Department of Energy                                                                       #
#   Politecnico di Milano                                                                      #
#   Author: Stefano Rebughini <stefano.rebughini@polimi.it>                                    #
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

#include "TransportFunctions.H"
#include "ThermodynamicFunctions.H"
#include "TransportThermoFunctions.H"

void Asali::showAtomNames()
{
    if ( window_ == "thermo" )
    {
        if ( thermoVector_.size() != 0)
        {
            for (unsigned int i=0;i<thermoVector_.size();i++)
            {
                thermoGrid_.remove(*thermoVector_[i]);
            }
        }

        thermoVector_.clear();
        thermoVector_.resize(n_.size());

        for (unsigned int i=0;i<n_.size();i++)
        { 
            thermoVector_[i] = new Gtk::Label(n_[i]);
            thermoGrid_.attach(*thermoVector_[i],0,i+1,1,1);
        }
    }
    else if ( window_ == "transport" )
    {
        if ( transportVector_.size() != 0)
        {
            for (unsigned int i=0;i<transportVector_.size();i++)
            {
                transportGrid_.remove(*transportVector_[i]);
            }
        }

        transportVector_.clear();
        transportVector_.resize(n_.size());

        for (unsigned int i=0;i<n_.size();i++)
        { 
            transportVector_[i] = new Gtk::Label(n_[i]);
            transportGrid_.attach(*transportVector_[i],0,i+1,1,1);
        }
    }
    else if ( window_ == "all" )
    {
        if ( allVector_.size() != 0)
        {
            for (unsigned int i=0;i<allVector_.size();i++)
            {
                allGrid_.remove(*allVector_[i]);
            }
        }

        allVector_.clear();
        allVector_.resize(n_.size());

        for (unsigned int i=0;i<n_.size();i++)
        { 
            allVector_[i] = new Gtk::Label(n_[i]);
            allGrid_.attach(*allVector_[i],0,i+1,1,1);
        }

    }
    else if ( window_ == "equilibrium" )
    {
        if ( equilibriumVector_.size() != 0)
        {
            for (unsigned int i=0;i<equilibriumVector_.size();i++)
            {
                equilibriumGrid_.remove(*equilibriumVector_[i]);
            }
        }

        equilibriumVector_.clear();
        equilibriumVector_.resize(n_.size()+1);

        for (unsigned int i=0;i<n_.size();i++)
        { 
            equilibriumVector_[i] = new Gtk::Label(n_[i]);
            equilibriumGrid_.attach(*equilibriumVector_[i],0,i+2,1,1);
        }
        
        equilibriumVector_[n_.size()]= new Gtk::Label("Temperature [K]");
        equilibriumGrid_.attach(*equilibriumVector_[n_.size()],0,n_.size()+2,1,1);
    }
}

void Asali::cpUnitConversion(bool check)
{
    if ( check == true )
    {
        if ( window_ == "thermo" )
        {
            if ( cpVector_.size() != 0)
            {
                for (unsigned int i=0;i<cpVector_.size();i++)
                {
                    thermoGrid_.remove(*cpVector_[i]);
                }
            }
        }
        else if ( window_ == "all" )
        {
            if ( cpVector_.size() != 0)
            {
                for (unsigned int i=0;i<cpVector_.size();i++)
                {
                    allGrid_.remove(*cpVector_[i]);
                }
            }
        }
    }

    cpVector_.clear();
    cpVector_.resize(n_.size());
    std::vector<double> converter(n_.size());

    if ( cpCombo_.get_active_row_number() == 0 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1.; //J/kmol/K
        }
    }
    else if ( cpCombo_.get_active_row_number() == 1 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1./1.e03; //J/mol/K
        }
    }
    else if ( cpCombo_.get_active_row_number() == 2 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1./MW_[i]; //J/kg/K
        }
    }
    else if ( cpCombo_.get_active_row_number() == 3 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1./4.186; //cal/kmol/K
        }
    }
    else if ( cpCombo_.get_active_row_number() == 4 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1./(1.e03*4.186); //cal/mol/K
        }
    }
    else if ( cpCombo_.get_active_row_number() == 5 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1./(MW_[i]*4.186); //cal/kg/K
        }
    }

    if ( window_ == "thermo" )
    { 
        for (unsigned int i=0;i<n_.size();i++)
        {
            std::stringstream cp;
            cp << std::scientific << std::setprecision(OP_) << cp_[i]*converter[i];
            cpVector_[i] = new Gtk::Label(cp.str());
            thermoGrid_.attach(*cpVector_[i],1,i+1,1,1);
        }
    }
    else if ( window_ == "all" )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            std::stringstream cp;
            cp << std::scientific << std::setprecision(OP_) << cp_[i]*converter[i];
            cpVector_[i] = new Gtk::Label(cp.str());
            allGrid_.attach(*cpVector_[i],1,i+1,1,1);
        }
    }
    
    this->show_all_children();
}

void Asali::hUnitConversion(bool check)
{
    if ( check == true )
    {
        if ( window_ == "thermo" )
        {
            if ( hVector_.size() != 0)
            {
                for (unsigned int i=0;i<hVector_.size();i++)
                {
                    thermoGrid_.remove(*hVector_[i]);
                }
            }
        }
        else if ( window_ == "all" )
        {
            if ( hVector_.size() != 0)
            {
                for (unsigned int i=0;i<hVector_.size();i++)
                {
                    allGrid_.remove(*hVector_[i]);
                }
            }
        }
    }

    hVector_.clear();
    hVector_.resize(n_.size());
    std::vector<double> converter(n_.size());

    if ( hCombo_.get_active_row_number() == 0 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1.; //J/kmol
        }
    }
    else if ( hCombo_.get_active_row_number() == 1 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1./1.e03; //J/mol
        }
    }
    else if ( hCombo_.get_active_row_number() == 2 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1./MW_[i]; //J/kg
        }
    }
    else if ( hCombo_.get_active_row_number() == 3 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1./4.186; //cal/kmol
        }
    }
    else if ( hCombo_.get_active_row_number() == 4 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1./(1.e03*4.186); //cal/mol
        }
    }
    else if ( hCombo_.get_active_row_number() == 5 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1./(MW_[i]*4.186); //cal/kg
        }
    }

    if ( window_ == "thermo" )
    { 
        for (unsigned int i=0;i<n_.size();i++)
        {
            std::stringstream h;
            h << std::scientific << std::setprecision(OP_) << h_[i]*converter[i];
            hVector_[i] = new Gtk::Label(h.str());
            thermoGrid_.attach(*hVector_[i],2,i+1,1,1);
        }
    }
    else if ( window_ == "all" )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            std::stringstream h;
            h << std::scientific << std::setprecision(OP_) << h_[i]*converter[i];
            hVector_[i] = new Gtk::Label(h.str());
            allGrid_.attach(*hVector_[i],2,i+1,1,1);
        }
    }
    
    this->show_all_children();
}

void Asali::sUnitConversion(bool check)
{
    if ( check == true )
    {
        if ( window_ == "thermo" )
        {
            if ( sVector_.size() != 0)
            {
                for (unsigned int i=0;i<sVector_.size();i++)
                {
                    thermoGrid_.remove(*sVector_[i]);
                }
            }
        }
        else if ( window_ == "all" )
        {
            if ( sVector_.size() != 0)
            {
                for (unsigned int i=0;i<sVector_.size();i++)
                {
                    allGrid_.remove(*sVector_[i]);
                }
            }
        }
    }

    sVector_.clear();
    sVector_.resize(n_.size());
    std::vector<double> converter(n_.size());

    if ( sCombo_.get_active_row_number() == 0 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1.; //J/kmol/K
        }
    }
    else if ( sCombo_.get_active_row_number() == 1 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1./1.e03; //J/mol/K
        }
    }
    else if ( sCombo_.get_active_row_number() == 2 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1./MW_[i]; //J/kg/K
        }
    }
    else if ( sCombo_.get_active_row_number() == 3 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1./4.186; //cal/kmol/K
        }
    }
    else if ( sCombo_.get_active_row_number() == 4 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1./(1.e03*4.186); //cal/mol/K
        }
    }
    else if ( sCombo_.get_active_row_number() == 5 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1./(MW_[i]*4.186); //cal/kg/K
        }
    }

    if ( window_ == "thermo" )
    { 
        for (unsigned int i=0;i<n_.size();i++)
        {
            std::stringstream s;
            s << std::scientific << std::setprecision(OP_) << std::setprecision(OP_) << s_[i]*converter[i];
            sVector_[i] = new Gtk::Label(s.str());
            thermoGrid_.attach(*sVector_[i],3,i+1,1,1);
        }
    }
    else if ( window_ == "all" )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            std::stringstream s;
            s << std::scientific << std::setprecision(OP_) << s_[i]*converter[i];
            sVector_[i] = new Gtk::Label(s.str());
            allGrid_.attach(*sVector_[i],3,i+1,1,1);
        }
    }
    
    this->show_all_children();
}

void Asali::condUnitConversion(bool check)
{
    if ( check == true )
    {
        if ( window_ == "transport" )
        {
            if ( condVector_.size() != 0)
            {
                for (unsigned int i=0;i<condVector_.size();i++)
                {
                    transportGrid_.remove(*condVector_[i]);
                }
            }
        }
        else if ( window_ == "all" )
        {
            if ( condVector_.size() != 0)
            {
                for (unsigned int i=0;i<condVector_.size();i++)
                {
                    allGrid_.remove(*condVector_[i]);
                }
            }
        }
    }

    condVector_.clear();
    condVector_.resize(n_.size());
    std::vector<double> converter(n_.size());

    if ( condCombo_.get_active_row_number() == 0 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1.; //W/m/K
        }
    }
    else if ( condCombo_.get_active_row_number() == 1 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1./4.186; //cal/m/s/K
        }
    }

    if ( window_ == "transport" )
    { 
        for (unsigned int i=0;i<n_.size();i++)
        {
            std::stringstream cond;
            cond << std::scientific << std::setprecision(OP_) << cond_[i]*converter[i];
            condVector_[i] = new Gtk::Label(cond.str());
            transportGrid_.attach(*condVector_[i],1,i+1,1,1);
        }
    }
    else if ( window_ == "all" )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            std::stringstream cond;
            cond << std::scientific << std::setprecision(OP_) << cond_[i]*converter[i];
            condVector_[i] = new Gtk::Label(cond.str());
            allGrid_.attach(*condVector_[i],4,i+1,1,1);
        }
    }
    
    this->show_all_children();
}

void Asali::muUnitConversion(bool check)
{
    if ( check == true )
    {
        if ( window_ == "transport" )
        {
            if ( muVector_.size() != 0)
            {
                for (unsigned int i=0;i<muVector_.size();i++)
                {
                    transportGrid_.remove(*muVector_[i]);
                }
            }
        }
        else if ( window_ == "all" )
        {
            if ( muVector_.size() != 0)
            {
                for (unsigned int i=0;i<muVector_.size();i++)
                {
                    allGrid_.remove(*muVector_[i]);
                }
            }
        }
    }

    muVector_.clear();
    muVector_.resize(n_.size());
    std::vector<double> converter(n_.size());

    if ( muCombo_.get_active_row_number() == 0 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1.; //Pa
        }
    }
    else if ( muCombo_.get_active_row_number() == 1 )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            converter[i] = 1e03; //cP
        }
    }

    if ( window_ == "transport" )
    { 
        for (unsigned int i=0;i<n_.size();i++)
        {
            std::stringstream mu;
            mu << std::scientific << std::setprecision(OP_) << mu_[i]*converter[i];
            muVector_[i] = new Gtk::Label(mu.str());
            transportGrid_.attach(*muVector_[i],2,i+1,1,1);
        }
    }
    else if ( window_ == "all" )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            std::stringstream mu;
            mu << std::scientific << std::setprecision(OP_) << mu_[i]*converter[i];
            muVector_[i] = new Gtk::Label(mu.str());
            allGrid_.attach(*muVector_[i],5,i+1,1,1);
        }
    }
    
    this->show_all_children();
}

void Asali::diffUnitConversion(bool check)
{
    if ( check == true )
    {
        if ( window_ == "transport" )
        {
            if ( diffBoxVector_.size() != 0)
            {
                for (unsigned int i=0;i<diffBoxVector_.size();i++)
                {
                    transportGrid_.remove(*diffBoxVector_[i]);
                }
            }
        }
        else if ( window_ == "all" )
        {
            if ( diffBoxVector_.size() != 0)
            {
                for (unsigned int i=0;i<diffBoxVector_.size();i++)
                {
                    allGrid_.remove(*diffBoxVector_[i]);
                }
            }
        }
    }
    
    speciesCombo_.clear();
    diffBoxVector_.clear();
    diffVector_.clear();
    speciesCombo_.resize(n_.size());
    diffBoxVector_.resize(n_.size());
    diffVector_.resize(n_.size());

    for (unsigned int i=0;i<n_.size();i++)
    { 
        speciesCombo_[i]  = new Gtk::ComboBoxText();
        diffBoxVector_[i] = new Gtk::Box();
        for (unsigned int j=0;j<n_.size();j++)
        {
            speciesCombo_[i]->append(n_[j]);
            speciesCombo_[i]->set_active(j);
        }
        speciesCombo_[i]->signal_changed().connect(sigc::bind<unsigned int>(sigc::mem_fun(*this,&Asali::diffSpecies),i));
        diffBoxVector_[i]->pack_end(*speciesCombo_[i]);
    }


    if ( window_ == "transport" )
    { 
        for (unsigned int i=0;i<n_.size();i++)
        {
            this->diffSpecies(i);
            transportGrid_.attach(*diffBoxVector_[i],3,i+1,1,1);
        }
    }
    else if ( window_ == "all" )
    {
        for (unsigned int i=0;i<n_.size();i++)
        {
            this->diffSpecies(i);
            allGrid_.attach(*diffBoxVector_[i],6,i+1,1,1);
        }
    }
    
    this->show_all_children();
}

void Asali::diffSpecies(unsigned int row)
{
    double converter = 0.;
    if ( diffCombo_.get_active_row_number() == 0 )
    {
        converter = 1.; //m2/s
    }

    for (unsigned int i=0;i<n_.size();i++)
    {
        if ( speciesCombo_[row]->get_active_row_number() == int(i) )
        {
            std::string diffstr = "";

            if ( diff_[row][i] == -1 )
            {
                diffstr = "n.a.";
                if ( diffBoxVector_[row]->get_children().size() == 1 )
                {
                    diffBoxVector_[row]->remove(*diffBoxVector_[row]->get_children()[0]);
                }
                else if ( diffBoxVector_[row]->get_children().size() == 2 )
                {
                    diffBoxVector_[row]->remove(*diffBoxVector_[row]->get_children()[0]);
                    diffBoxVector_[row]->remove(*diffBoxVector_[row]->get_children()[1]);
                }
            }
            else
            {
                std::stringstream diff;
                diff << std::scientific << std::setprecision(OP_) << diff_[row][i]*converter;
                diffstr = diffstr + diff.str() + " in ";

                if ( diffBoxVector_[row]->get_children().size() > 1 )
                {
                    diffBoxVector_[row]->remove(*diffBoxVector_[row]->get_children()[0]);
                }
            }
            

            diffVector_[i] = new Gtk::Label(diffstr);
            diffBoxVector_[row]->pack_start(*diffVector_[i]);

            break;
        }
    }

    this->show_all_children();
}
