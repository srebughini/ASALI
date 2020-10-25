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

#include "Asali.hpp"

namespace ASALI
{
    Asali::Asali()
    : discrimerButton_("Discrimer"),
      exitButton1_("Exit"),
      exitButton2_("Exit"),
      exitButton3_("Exit"),
      exitButton4_("Exit"),
      exitButton5_("Exit"),
      backButton1_("Back"),
      backButton2_("Back"),
      startButton_("Start"),
      defaultCanteraInputButton_("Default (only transport/thermodynamic)"),
      loadCanteraInputButton_("Load CANTERA kinetic/properties file"),
      noneInputButton_("User defined constant properties"),
      conversionButton_("CHEMKIN -> CANTERA converter"),
      canteraInputButton_("Select CANTERA kinetic/properties file"),
      transportButton_("Transport properties"),
      thermoButton_("Thermodynamic properties"),
      thermoTransportButton_("Thermodynamic & Transport properties"),
      physicalChemicalButton_("Physical & Chemical properties"),
      equilibriumButton_("Themodynamic equilibrium (CANTERA)"),
      linearRegressionButton_("Linear Regression of gas properties"),
      reactorsButton_("Catalytic reactors"),
      vacuumButton_("Vacuum properties"),
      pelletButton_("Catalytic pellets"),
      batchButton_("Batch Reactor"),
      cstrButton_("Continuous Stirred Tank Reactor"),
      ph1dButton_("1D Pseudo-homogeneous Plug Flow Reactor"),
      het1dButton_("1D Heterogeneous Plug Flow Reactor"),
      dpButton_("Pressure drops"),
      asaliKineticButton_("Make/Check ASALI kinetic scheme"),
      asaliKineticMakeButton_("Write a new kinetic scheme"),
      asaliKineticCheckButton_("Check your kinetic scheme"),
      linkButtonBox_(Gtk::ORIENTATION_VERTICAL),
      chemistryButtonBox_(Gtk::ORIENTATION_VERTICAL),
      menuButtonBox_(Gtk::ORIENTATION_VERTICAL),
      reactorButtonBox_(Gtk::ORIENTATION_VERTICAL),
      kineticButtonBox_(Gtk::ORIENTATION_VERTICAL),
      heading_("\nAuthor: Stefano Rebughini, Ph.D."
               "\nE-mail: ste.rebu@outlook.it"),
      kineticLabel_("<b>Please, load your CANTERA kinetic/propeties file</b>"
                    "<b>\nor select the default one (database/data.xml)</b>"
                    "\n\nLoading might take several minutes, depending"
                    "\non your system performances."),
      bigLogo_("images/BigLogo.png"),
      smallLogo1_("images/SmallLogo.png"),
      smallLogo2_("images/SmallLogo.png"),
      smallLogo3_("images/SmallLogo.png"),
      smallLogo4_("images/SmallLogo.png")
    {
        #include "shared/Beer.H"
        #include "shared/BeerShort.H"
        
        //First window
        {
            this->set_border_width(15);
            this->set_title("ASALI");
            this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
            this->set_icon_from_file("images/Icon.png");

            //Add background grid
            this->add(grid_);

            //Adding the logo (position 1,0)
            grid_.attach(logoEventBox_,1,0,1,1);
            grid_.set_row_spacing(10);
            logoEventBox_.add(bigLogo_);
            logoEventBox_.set_events(Gdk::BUTTON_PRESS_MASK);
            logoEventBox_.signal_button_press_event().connect(sigc::mem_fun(*this,&Asali::chemistryMenu1));
            logoEventBox_.signal_realize().connect(sigc::mem_fun(*this,&Asali::changeCursor));

            //Adding beer
            beerLabel_.set_text(this->getBeer());
            beerLabel_.set_use_markup(true);
            beerLabel_.set_justify(Gtk::JUSTIFY_CENTER);
            grid_.attach(beerLabel_,1,1,1,1);

            //Adding the heading (position 1,1)
            heading_.set_justify(Gtk::JUSTIFY_LEFT);
            grid_.attach(heading_,1,2,1,1);
            grid_.attach(linkButtonBox_,1,3,1,1);
            startButtonBox_.set_layout(Gtk::BUTTONBOX_CENTER);
            #if ASALI_ON_WINDOW == 0
            linkButtonBox_.pack_start(gitButton_, Gtk::PACK_SHRINK);
            gitButton_.set_label("GitHub");
            gitButton_.set_uri("https://github.com/srebughini/ASALI");
            linkButtonBox_.pack_start(forgeButton_, Gtk::PACK_SHRINK);
            forgeButton_.set_label("SourceForge");
            forgeButton_.set_uri("https://sourceforge.net/projects/asali");
            #endif

            //Adding starting button (position 1,2)
            grid_.attach(startButtonBox_,1,4,1,1);
            startButtonBox_.set_layout(Gtk::BUTTONBOX_CENTER);
            startButtonBox_.pack_start(startButton_, Gtk::PACK_SHRINK);
            startButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::chemistryMenu2));

            //Adding discrimer button (position 0,2)
            grid_.attach(discrimerButtonBox_,0,4,1,1);
            discrimerButtonBox_.set_layout(Gtk::BUTTONBOX_START);
            discrimerButtonBox_.pack_start(discrimerButton_, Gtk::PACK_SHRINK);
            discrimerButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::discrimer));

            //Adding exit button (position 2,2)
            grid_.attach(exitButtonBox_,2,4,1,1);
            exitButtonBox_.set_layout(Gtk::BUTTONBOX_END);
            exitButtonBox_.pack_start(exitButton1_, Gtk::PACK_SHRINK);
            exitButton1_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::exit));

            this->show_all_children();
        }

        //Chemistry menu
        {
            //Adding logo
            chemistryBox_.set_halign(Gtk::ALIGN_START);
            chemistryBox_.set_spacing(10);
            chemistryBox_.pack_start(smallLogo1_, Gtk::PACK_SHRINK);

            //Adding thermo and transport buttons
            chemistryBox_.pack_start(chemistryButtonBox_, Gtk::PACK_SHRINK);
            chemistryButtonBox_.set_valign(Gtk::ALIGN_CENTER);
            chemistryButtonBox_.set_spacing(10);
            chemistryButtonBox_.pack_start(kineticLabel_, Gtk::PACK_SHRINK);
            kineticLabel_.set_use_markup(true);
            chemistryButtonBox_.pack_start(defaultCanteraInputButton_, Gtk::PACK_SHRINK);
            defaultCanteraInputButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::defaultCanteraInput));
            defaultCanteraInputButton_.set_tooltip_text("Select the ASALI database for transport and thermodynamic properties");
            chemistryButtonBox_.pack_start(loadCanteraInputButton_, Gtk::PACK_SHRINK);
            loadCanteraInputButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::loadCanteraInput));
            loadCanteraInputButton_.set_tooltip_text("Load CANTERA input file");
            chemistryButtonBox_.pack_start(noneInputButton_, Gtk::PACK_SHRINK);
            noneInputButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::noneInput));
            noneInputButton_.set_tooltip_text("No input file required. Constant properties are used.");
            chemistryButtonBox_.pack_start(conversionButton_, Gtk::PACK_SHRINK);
            conversionButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::chemkin));
            conversionButton_.set_tooltip_text("Converter of CHEMKIN files to CANTERA file");
            chemistryButtonBox_.pack_start(asaliKineticButton_, Gtk::PACK_SHRINK);
            asaliKineticButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::kineticAsali));
            asaliKineticButton_.set_tooltip_text("Write or check a kinetic scheme in ASALI format");
            
            //Adding exit button
            chemistryButtonBox_.pack_start(exitButton2_, Gtk::PACK_SHRINK);
            exitButton2_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::exit));
        }

        //Asali kinetic 
        {
            //Adding logo
            kineticBox_.set_halign(Gtk::ALIGN_START);
            kineticBox_.set_spacing(10);
            kineticBox_.pack_start(smallLogo4_, Gtk::PACK_SHRINK);

            //Adding buttons
            kineticBox_.pack_start(kineticButtonBox_, Gtk::PACK_SHRINK);
            kineticButtonBox_.set_layout(Gtk::BUTTONBOX_CENTER);
            kineticButtonBox_.set_spacing(10);
            kineticButtonBox_.set_homogeneous(true);
            kineticButtonBox_.pack_start(asaliKineticMakeButton_, Gtk::PACK_SHRINK);
            asaliKineticMakeButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::kineticMake));
            asaliKineticMakeButton_.set_tooltip_text("Write a new kinetic scheme in ASALI format");
            kineticButtonBox_.pack_start(asaliKineticCheckButton_, Gtk::PACK_SHRINK);
            asaliKineticCheckButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::kineticCheck));
            asaliKineticCheckButton_.set_tooltip_text("Check a kinetic scheme in ASALI format");

            //Adding exit button
            kineticButtonBox_.pack_start(kineticButtonGrid_, Gtk::PACK_SHRINK);

            kineticButtonGrid_.set_column_homogeneous(true);
            kineticButtonGrid_.set_column_spacing(10);
            kineticButtonGrid_.set_row_spacing(10);
            kineticButtonGrid_.attach(backButton2_,0,0,1,1);
            backButton2_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::chemistryMenu2));
            kineticButtonGrid_.attach(exitButton5_,1,0,1,1);
            exitButton5_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::exit));
        }

        //Main Menu
        {
            //Adding logo
            menuBox_.set_halign(Gtk::ALIGN_START);
            menuBox_.set_spacing(10);
            menuBox_.pack_start(smallLogo2_, Gtk::PACK_SHRINK);

            //Adding buttons
            menuBox_.pack_start(menuButtonBox_, Gtk::PACK_SHRINK);
            menuButtonBox_.set_layout(Gtk::BUTTONBOX_CENTER);
            menuButtonBox_.set_spacing(10);
            menuButtonBox_.set_homogeneous(true);
            menuButtonBox_.pack_start(canteraInputButton_, Gtk::PACK_SHRINK);
            canteraInputButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::chemistryMenu2));
            menuButtonBox_.pack_start(transportButton_, Gtk::PACK_SHRINK);
            transportButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::transport));
            transportButton_.set_tooltip_text("Estimation of transport properties at assigned Temperture, Pressure and Composition");
            menuButtonBox_.pack_start(thermoButton_, Gtk::PACK_SHRINK);
            thermoButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::thermo));
            thermoButton_.set_tooltip_text("Estimation of thermodynamic properties at assigned Temperture, Pressure and Composition");
            menuButtonBox_.pack_start(thermoTransportButton_, Gtk::PACK_SHRINK);
            thermoTransportButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::thermoTransport));
            thermoTransportButton_.set_tooltip_text("Estimation of thermodynamic & transport properties\nat assigned Temperture, Pressure and Composition");
            menuButtonBox_.pack_start(physicalChemicalButton_, Gtk::PACK_SHRINK);
            physicalChemicalButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::physicalChemical));
            physicalChemicalButton_.set_tooltip_text("Estimation of physical & chemical properties\nat assigned Temperture, Pressure and Composition");
            menuButtonBox_.pack_start(vacuumButton_, Gtk::PACK_SHRINK);
            vacuumButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::vacuum));
            vacuumButton_.set_tooltip_text("Estimation of specie vacuum properties at assigned Temperture and Pressure");
            menuButtonBox_.pack_start(equilibriumButton_, Gtk::PACK_SHRINK);
            equilibriumButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::equilibrium));
            equilibriumButton_.set_tooltip_text("Estimation of chemical equilibrium based on CANTERA");
            menuButtonBox_.pack_start(linearRegressionButton_, Gtk::PACK_SHRINK);
            linearRegressionButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::linearRegression));
            linearRegressionButton_.set_tooltip_text("Estimaion of linear equations for thermodynamic and transport properties\nof a gas mixture as a function of Temperature");
            menuButtonBox_.pack_start(reactorsButton_, Gtk::PACK_SHRINK);
            reactorsButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::reactors));
            reactorsButton_.set_tooltip_text("Solvers for different catalytic reactor geometries");
            menuButtonBox_.pack_start(pelletButton_, Gtk::PACK_SHRINK);
            pelletButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::pellets));
            pelletButton_.set_tooltip_text("Solvers for different catalytic pellet geometries");

            //Adding exit button
            menuButtonBox_.pack_start(exitButton3_, Gtk::PACK_SHRINK);
            exitButton3_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::exit));
        }
        
        //Catalytic reactor menu
        {
            //Adding logo
            reactorBox_.set_halign(Gtk::ALIGN_START);
            reactorBox_.set_spacing(10);
            reactorBox_.pack_start(smallLogo3_, Gtk::PACK_SHRINK);

            //Adding buttons
            reactorBox_.pack_start(reactorButtonBox_, Gtk::PACK_SHRINK);
            reactorButtonBox_.set_layout(Gtk::BUTTONBOX_CENTER);
            reactorButtonBox_.set_spacing(10);
            reactorButtonBox_.set_homogeneous(true);
            reactorButtonBox_.pack_start(batchButton_, Gtk::PACK_SHRINK);
            batchButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::batch));
            reactorButtonBox_.pack_start(cstrButton_, Gtk::PACK_SHRINK);
            cstrButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::cstr));
            reactorButtonBox_.pack_start(ph1dButton_, Gtk::PACK_SHRINK);
            ph1dButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::ph1d));
            reactorButtonBox_.pack_start(het1dButton_, Gtk::PACK_SHRINK);
            het1dButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::het1d));
            reactorButtonBox_.pack_start(dpButton_, Gtk::PACK_SHRINK);
            dpButton_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::dp));

            //Adding exit button
            reactorButtonBox_.pack_start(reactorButtonGrid_, Gtk::PACK_SHRINK);

            reactorButtonGrid_.set_column_homogeneous(true);
            reactorButtonGrid_.set_column_spacing(10);
            reactorButtonGrid_.set_row_spacing(10);
            reactorButtonGrid_.attach(backButton1_,0,0,1,1);
            backButton1_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::mainMenu));
            reactorButtonGrid_.attach(exitButton4_,1,0,1,1);
            exitButton4_.signal_clicked().connect(sigc::mem_fun(*this,&Asali::exit));
        }
    }

    Asali::~Asali()
    {
    }

    void Asali::changeCursor()
    {
        logoEventBox_.get_window()->set_cursor(Gdk::Cursor::create(Gdk::HAND1));
    }

    bool Asali::chemistryMenu1(GdkEventButton*)
    {
        this->remove();
        this->set_title("ASALI");
        this->add(chemistryBox_);
        this->resize(chemistryBox_.get_width(),chemistryBox_.get_height());
        this->show_all_children();

        return true;
    }

    void Asali::chemistryMenu2()
    {
        this->remove();
        this->set_title("ASALI");
        this->add(chemistryBox_);
        this->resize(chemistryBox_.get_width(),chemistryBox_.get_height());
        this->show_all_children();
    }

    void Asali::mainMenu()
    {
        this->remove();
        this->set_title("ASALI");
        this->add(menuBox_);
        this->resize(menuBox_.get_width(),menuBox_.get_height());
        this->show_all_children();
    }

    void Asali::discrimer()
    {
        Gtk::MessageDialog dialog(*this,"ASALI is free software: You can redistribute it and/or modify\n"
                                        " it the terms of the GNU General Public License as published by\n"
                                        "the Free Software Foundation, either version 3 of the License,\n"
                                        "or (at your option) any later version.\n"
                                        "\nASALI is distributed in the hope that it will be useful,\n"
                                        "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
                                        "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n"
                                        "\nSee the GNU General Public License for more details.\n"
                                        "You should have received a copy of the GNU General Public License\n"
                                        "along with ASALI. If not, see http://www.gnu.org/licenses/.\n",true,Gtk::MESSAGE_OTHER);
        dialog.run();
    }
    
    void Asali::noneInputError()
    {
        Gtk::MessageDialog dialog(*this,"This feauture is not available. To use it, please, select a CANTERA kinetic/properties file.",true,Gtk::MESSAGE_ERROR);
        dialog.set_secondary_text(this->getBeer(),true);
        dialog.run();
    }

    void Asali::defaultCanteraInput()
    {
        thermo_           = Cantera::newPhase("database/data.xml","gas");
        transport_        = Cantera::newDefaultTransportMgr(thermo_);
        canteraInterface_ = new ASALI::canteraInterface(thermo_,transport_);
        speciesNames_     = new ASALI::speciesPopup();
        kineticType_      = "default";
        this->mainMenu();
    }
    
    void Asali::noneInput()
    {
        kineticType_ = "none";
        this->mainMenu();
    }

    void Asali::chemkin()
    {
        if (!converter_)
        {
            delete converter_;
        }
        converter_ = new ASALI::chemkinConverter();
        converter_->show();
    }
    
    void Asali::kineticAsali()
    {
        this->set_title("ASALI: Kinetic");
        this->remove();
        this->add(kineticBox_);
        this->resize(kineticBox_.get_width(),kineticBox_.get_height());
        this->show_all_children();
    }

    void Asali::kineticMake()
    {
        if (!asaliKineticMakerMenu_)
        {
            delete asaliKineticMakerMenu_;
        }
        asaliKineticMakerMenu_ = new ASALI::asaliKineticMaker();
        asaliKineticMakerMenu_->show();
    }

    void Asali::kineticCheck()
    {
        std::string filename = this->open_file(this->get_toplevel()->gobj());
        if ( filename != "" )
        {
            std::ifstream input;
            const char *path = filename.c_str();
            input.open(path);

            if ( filename.substr(filename.length()-3,filename.length()) != ".py" )
            {
                Gtk::MessageDialog dialogSmall(*this,"Something is wrong in your ASALI kinetic file!",true,Gtk::MESSAGE_ERROR);
                dialogSmall.set_secondary_text(this->getBeer(),true);
                dialogSmall.run();
            }
            else
            {
                #if ASALI_ON_WINDOW == 0
                std::vector<std::string> filevector = this->splitString(filename,"/");
                #else
                std::vector<std::string> filevector = this->splitString(filename,"\\");
                #endif
                
                std::string function = filevector.back().substr(0,filevector.back().length()-3);
                std::string path     = filename.substr(0,filename.length() - function.length()-3);

                ASALI::pythonInterface pi;
                std::string check = pi.initialize(function,path);
                pi.close();

                if ( check != "done" )
                {
                    Gtk::MessageDialog dialogSmall(*this,"Something is wrong in your ASALI kinetic file!",true,Gtk::MESSAGE_ERROR);
                    dialogSmall.set_secondary_text(this->getBeer(),true);
                    dialogSmall.run();
                }
                else
                {
                    Gtk::MessageDialog dialogSmall(*this,"Your ASALI kinetic file is perfect!",true,Gtk::MESSAGE_INFO);
                    dialogSmall.set_secondary_text(this->getBeer(),true);
                    dialogSmall.run();
                }
            }
        }
    }

    void Asali::loadCanteraInput()
    {
        std::string filename = this->open_file(this->get_toplevel()->gobj());
        if ( filename != "" )
        {
            std::ifstream input;
            const char *path = filename.c_str();
            input.open(path);

            if (filename.find("cti")!=std::string::npos)
            {
                Gtk::MessageDialog errorDialog(*this,"Sorry, ASALI use only the xml version of CANTERA input file\nTo convert .cti to .xml use ctml_writer command",true,Gtk::MESSAGE_WARNING);
                errorDialog.set_secondary_text(this->getBeer(),true);
                errorDialog.run();
            }
            else if (filename.find("xml")!=std::string::npos)
            {
                std::vector<std::string> readed(2);
                readed[0] = "none";
                readed[1] = "none";
                {
                    std::vector<std::string> a;
                    std::vector<std::string> b;
                    while (!input.eof()) 
                    {
                        std::string line;
                        getline(input,line);
                        if (line.find("<phase ")!=std::string::npos)
                        {
                            a.push_back(line);
                        }
                        else if (line.find("<kinetics ")!=std::string::npos)
                        {
                            b.push_back(line);
                        }
                    }

                    for (unsigned int i=0;i<b.size();i++)
                    {
                        if (b[i].find("Interface")!=std::string::npos)
                        {
                            readed[1] = a[i];
                        }
                        else if (b[i].find("GasKinetics")!=std::string::npos)
                        {
                            readed[0] = a[i];
                        }
                    }
                }
                
                if ( readed[0] == "none" ||
                     readed[1] == "none" )
                {
                    Gtk::MessageDialog smallDialog(*this,"We detect that your CANTERA input file does not have a surface phase.\nDo you wonna continue anyway?",true,Gtk::MESSAGE_QUESTION,Gtk::BUTTONS_YES_NO);
                    smallDialog.set_secondary_text(this->getBeerShort(),true);
                    int answer = smallDialog.run();

                    //Handle the response:
                    switch(answer)
                    {
                        case(Gtk::RESPONSE_YES):
                        {
                            std::string type = "none";
                            for (unsigned int i=0;i<readed.size();i++)
                            {
                                if ( readed[i] != "none" )
                                {
                                    std::string dummyString = readed[i];

                                    for (std::size_t j=0;j<dummyString.size();j++)
                                    {
                                        if ( dummyString.substr(j,1) == ">" )
                                        {
                                            dummyString.replace(j,1," ");
                                        }
                                        else if ( dummyString.substr(j,1) == "\"" )
                                        {
                                            dummyString.replace(j,1," ");
                                        }
                                        else if ( dummyString.substr(j,1) == "=" )
                                        {
                                            dummyString.replace(j,1," ");
                                        }
                                    }

                                    std::vector<std::string> dummyVector;
                                    dummyVector.clear();

                                    std::istringstream iss(dummyString);
                                    while (iss >> dummyString)
                                    {
                                        dummyVector.push_back(dummyString);
                                    }

                                    if ( dummyVector.size() > 4 )
                                    {
                                        for (unsigned int j=0;j<dummyVector.size()-1;j++)
                                        {
                                            if (dummyVector[j] == "<phase"  &&
                                                dummyVector[j + 1] == "dim" &&
                                                dummyVector[j + 3] == "id" )
                                            {
                                                type = dummyVector[j+4];
                                                type.erase(std::remove(type.begin(), type.end(), '"'), type.end());
                                                type.erase(std::remove(type.begin(), type.end(), ' '), type.end());
                                            }
                                            else if (dummyVector[j] == "<phase"  &&
                                                     dummyVector[j + 1] == "id" &&
                                                     dummyVector[j + 3] == "dim" )
                                            {
                                                type = dummyVector[j+2];
                                                type.erase(std::remove(type.begin(), type.end(), '"'), type.end());
                                                type.erase(std::remove(type.begin(), type.end(), ' '), type.end());
                                             }
                                        }
                                    }
                                }
                            }

                            if ( type == "none")
                            {
                                Gtk::MessageDialog errorDialog(*this,"Something is wrong in your CANTERA input file.",true,Gtk::MESSAGE_WARNING);
                                errorDialog.set_secondary_text(this->getBeerShort(),true);
                                errorDialog.run();
                                smallDialog.hide();
                                break;
                            }
                            else
                            {
                                thermo_           = Cantera::newPhase(filename,type);
                                transport_        = Cantera::newDefaultTransportMgr(thermo_);
                                canteraInterface_ = new ASALI::canteraInterface(thermo_,transport_);
                                speciesNames_     = new ASALI::speciesPopup();
                                kineticType_      = "nokinetic";
                                smallDialog.hide();
                                this->mainMenu();
                                break;
                            }
                        }
                        default:
                        {
                            smallDialog.hide();
                            break;
                        }
                    }
                }
                else
                {
                    std::vector<std::string> type(2);
                    type[0] = "none";
                    type[1] = "none";
                    for (unsigned int i=0;i<readed.size();i++)
                    {
                        std::string dummyString = readed[i];

                        for (std::size_t j=0;j<dummyString.size();j++)
                        {
                            if ( dummyString.substr(j,1) == ">" )
                            {
                                dummyString.replace(j,1," ");
                            }
                            else if ( dummyString.substr(j,1) == "\"" )
                            {
                                dummyString.replace(j,1," ");
                            }
                            else if ( dummyString.substr(j,1) == "=" )
                            {
                                dummyString.replace(j,1," ");
                            }
                        }

                        std::vector<std::string> dummyVector;
                        dummyVector.clear();

                        std::istringstream iss(dummyString);
                        while (iss >> dummyString)
                        {
                            dummyVector.push_back(dummyString);
                        }

                        if ( dummyVector.size() > 4 )
                        {
                            for (unsigned int j=0;j<dummyVector.size()-1;j++)
                            {
                                if (dummyVector[j] == "<phase"  &&
                                    dummyVector[j + 1] == "dim" &&
                                    dummyVector[j + 3] == "id" )
                                {
                                    type[i] = dummyVector[j+4];
                                    type[i].erase(std::remove(type[i].begin(), type[i].end(), '"'), type[i].end());
                                    type[i].erase(std::remove(type[i].begin(), type[i].end(), ' '), type[i].end());
                                }
                                else if (dummyVector[j] == "<phase"  &&
                                         dummyVector[j + 1] == "id" &&
                                         dummyVector[j + 3] == "dim" )
                                {
                                    type[i] = dummyVector[j+2];
                                    type[i].erase(std::remove(type[i].begin(), type[i].end(), '"'), type[i].end());
                                    type[i].erase(std::remove(type[i].begin(), type[i].end(), ' '), type[i].end());
                                }
                            }
                        }

                        if ( type[0] != "none" && type[1] != "none")
                        {
                            break;
                        }
                    }

                    if ( type[0] == "none" ||
                         type[1] == "none" )
                    {
                        Gtk::MessageDialog errorDialog(*this,"Something is wrong in your CANTERA kinetic file.",true,Gtk::MESSAGE_WARNING);
                        errorDialog.set_secondary_text(this->getBeerShort(),true);
                        errorDialog.run();
                    }
                    else
                    {
                        thermo_     = Cantera::newPhase(filename,type[0]);
                        std::vector<Cantera::ThermoPhase*>  phases{thermo_};
                        surface_    = Cantera::importInterface(filename,type[1],phases);
                        kinetic_    = Cantera::newKineticsMgr(thermo_->xml(), phases);
                        transport_  = Cantera::newDefaultTransportMgr(thermo_);
                        canteraInterface_ = new ASALI::canteraInterface(thermo_,transport_);
                        kineticType_ = "load";
                        this->mainMenu();
                    }
                }
            }
            else
            {
                Gtk::MessageDialog smallDialog(*this,"Something is wrong in your CANTERA kinetic file.",true,Gtk::MESSAGE_WARNING);
                smallDialog.set_secondary_text(this->getBeerShort(),true);
                smallDialog.run();
            }
        }
    }

    void Asali::transport()
    {
        if ( kineticType_ == "none" )
        {
            this->noneInputError();
        }
        else
        {
            if (!transportMenu_)
            {
                delete transportMenu_;
            }
            transportMenu_ = new ASALI::transportProperties(canteraInterface_,speciesNames_,kineticType_);
            transportMenu_->show();
        }
    }

    void Asali::thermo()
    {
        if ( kineticType_ == "none" )
        {
            this->noneInputError();
        }
        else
        {
            if (!thermoMenu_)
            {
                delete thermoMenu_;
            }
            thermoMenu_ = new ASALI::thermoProperties(canteraInterface_,speciesNames_,kineticType_);
            thermoMenu_->show();
        }
    }

    void Asali::thermoTransport()
    {
        if ( kineticType_ == "none" )
        {
            this->noneInputError();
        }
        else
        {
            if (!thermoTransportMenu_)
            {
                delete thermoTransportMenu_;
            }
            thermoTransportMenu_ = new ASALI::thermoTransportProperties(canteraInterface_,speciesNames_,kineticType_);
            thermoTransportMenu_->show();
        }
    }
    
    void Asali::physicalChemical()
    {
        if ( kineticType_ == "none" )
        {
            this->noneInputError();
        }
        else
        {
            if (!physicalChemicalMenu_)
            {
                delete physicalChemicalMenu_;
            }
            physicalChemicalMenu_ = new ASALI::physicalChemicalProperties(canteraInterface_,speciesNames_,kineticType_);
            physicalChemicalMenu_->show();
        }
    }

    void Asali::vacuum()
    {
        if ( kineticType_ == "none" )
        {
            this->noneInputError();
        }
        else
        {
            if (!vacuumMenu_)
            {
                delete vacuumMenu_;
            }
            vacuumMenu_ = new ASALI::vacuumProperties(canteraInterface_,speciesNames_,kineticType_);
            vacuumMenu_->show();
        }
    }

    void Asali::equilibrium()
    {
        if ( kineticType_ == "none" )
        {
            this->noneInputError();
        }
        else
        {
            if (!equilibriumMenu_)
            {
                delete equilibriumMenu_;
            }
            equilibriumMenu_ = new ASALI::equilibriumCalculator(canteraInterface_,speciesNames_,kineticType_);
            equilibriumMenu_->show();
        }
    }

    void Asali::linearRegression()
    {
        if ( kineticType_ == "none" )
        {
            this->noneInputError();
        }
        else
        {
            if (!linearRegressionMenu_)
            {
                delete linearRegressionMenu_;
            }
            linearRegressionMenu_ = new ASALI::linearRegression(canteraInterface_,speciesNames_,kineticType_);
            linearRegressionMenu_->show();
        }
    }

    void Asali::pellets()
    {
        if (!pelletMenu_)
        {
            delete pelletMenu_;
        }
        pelletMenu_ = new ASALI::catalyticPellet(thermo_,transport_,kinetic_,surface_,kineticType_);
        pelletMenu_->show();
    }

    void Asali::reactors()
    {
        this->set_title("ASALI: Catalytic reactors");
        this->remove();
        this->add(reactorBox_);
        this->resize(reactorBox_.get_width(),reactorBox_.get_height());
        this->show_all_children();
    }

    void Asali::batch()
    {
        if (!batchMenu_)
        {
            delete batchMenu_;
        }
        batchMenu_ = new ASALI::batchReactor(thermo_,transport_,kinetic_,surface_,kineticType_);
        batchMenu_->show();
    }

    void Asali::cstr()
    {
        if (!cstrMenu_)
        {
            delete cstrMenu_;
        }
        cstrMenu_ = new ASALI::cstrReactor(thermo_,transport_,kinetic_,surface_,kineticType_);
        cstrMenu_->show();
    }

    void Asali::ph1d()
    {
        if (!ph1dMenu_)
        {
            delete ph1dMenu_;
        }
        ph1dMenu_ = new ASALI::ph1dReactor(thermo_,transport_,kinetic_,surface_,kineticType_);
        ph1dMenu_->show();
    }

    void Asali::het1d()
    {
        if (!het1dMenu_)
        {
            delete het1dMenu_;
        }
        het1dMenu_ = new ASALI::het1dReactor(thermo_,transport_,kinetic_,surface_,kineticType_);
        het1dMenu_->show();
    }

    void Asali::dp()
    {
        if (!dpMenu_)
        {
            delete dpMenu_;
        }
        dpMenu_ = new ASALI::pressureDrops(canteraInterface_,speciesNames_,kineticType_);
        dpMenu_->show();
    }

    void Asali::exit()
    {
        this->hide();
    }
    
    std::string Asali::getBeer()
    {
        unsigned int seed = time(NULL);
        int i = rand_r(&seed)%beer_.size();
        return beer_[i];
    }

    std::string Asali::getBeerShort()
    {
        unsigned int seed = time(NULL);
        int i = rand_r(&seed)%beerShort_.size();
        return beerShort_[i];
    }


    std::vector<std::string> Asali::splitString(const std::string txt, std::string ch)
    {
        std::vector<std::string> strs;
        std::size_t pos        = txt.find( ch );
        std::size_t initialPos = 0;

        strs.clear();

        while( pos != std::string::npos )
        {
            strs.push_back( txt.substr( initialPos, pos - initialPos ) );
            initialPos = pos + 1;

            pos = txt.find( ch, initialPos );
        }

        strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );

        return strs;
    }

}
