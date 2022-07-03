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

#include "frontend/mainGui.hpp"

namespace ASALI
{
    mainGui::mainGui()
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
          convertCanteraFileButton_("CANTERA -> CANTERA converter"),
          noneInputButton_("User defined constant properties"),
          conversionButton_("CHEMKIN -> CANTERA converter"),
          canteraInputButton_("Select CANTERA kinetic/properties file"),
          transportButton_("Transport properties"),
          thermoButton_("Thermodynamic properties"),
          thermoTransportButton_("Thermodynamic & Transport properties"),
          equilibriumButton_("Themodynamic equilibrium (CANTERA)"),
          linearRegressionButton_("Linear Regression of gas properties"),
          reactorsButton_("Catalytic reactors"),
          physicalChemicalButton_("Physical & Chemical properties"),
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
          heading_("\nAuthor: Stefano Rebughini, PhD"
                   "\nE-mail: ste.rebu@outlook.it"),
#if ASALI_USING_CANTERA == 1
          kineticLabel_("<b>Please, load your CANTERA kinetic/propeties file</b>"
                        "<b>\nor select the default one (database/data.xml)</b>"
                        "\n\nLoading might take several minutes, depending"
                        "\non your system performances."),
#else
          kineticLabel_("<b>You are using the version of ASALI without Cantera</b>"),
#endif
          bigLogo_(fileManager_.relative_path_to_absolute_path("images/BigLogo.png")),
          smallLogo1_(fileManager_.relative_path_to_absolute_path("images/SmallLogo.png")),
          smallLogo2_(fileManager_.relative_path_to_absolute_path("images/SmallLogo.png")),
          smallLogo3_(fileManager_.relative_path_to_absolute_path("images/SmallLogo.png")),
          smallLogo4_(fileManager_.relative_path_to_absolute_path("images/SmallLogo.png")),
          basicXMLfilepath_(fileManager_.relative_path_to_absolute_path("database/data.xml")),
          basicGasPhase_("gas")
    {
        beerQuote_ = new ASALI::beerQuote();

        //First window
        {
            this->set_border_width(15);
            this->set_title("ASALI");
            this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
            this->set_icon_from_file(fileManager_.relative_path_to_absolute_path("images/Icon.png"));

            //Add background grid
            this->add(grid_);

            //Adding the logo (position 1,0)
            grid_.attach(logoEventBox_, 1, 0, 1, 1);
            grid_.set_row_spacing(10);
            logoEventBox_.add(bigLogo_);
            logoEventBox_.set_events(Gdk::BUTTON_PRESS_MASK);
            logoEventBox_.signal_button_press_event().connect(sigc::mem_fun(*this, &mainGui::chemistryMenu1));
            logoEventBox_.signal_realize().connect(sigc::mem_fun(*this, &mainGui::changeCursor));

            //Adding beer
            beerLabel_.set_text(beerQuote_->getRandomQuote());
            beerLabel_.set_use_markup(true);
            beerLabel_.set_justify(Gtk::JUSTIFY_CENTER);
            grid_.attach(beerLabel_, 1, 1, 1, 1);

            //Adding the heading (position 1,1)
            heading_.set_justify(Gtk::JUSTIFY_LEFT);
            grid_.attach(heading_, 1, 2, 1, 1);
            grid_.attach(linkButtonBox_, 1, 3, 1, 1);
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
            grid_.attach(startButtonBox_, 1, 4, 1, 1);
            startButtonBox_.set_layout(Gtk::BUTTONBOX_CENTER);
            startButtonBox_.pack_start(startButton_, Gtk::PACK_SHRINK);
            startButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::chemistryMenu2));

            //Adding discrimer button (position 0,2)
            grid_.attach(discrimerButtonBox_, 0, 4, 1, 1);
            discrimerButtonBox_.set_layout(Gtk::BUTTONBOX_START);
            discrimerButtonBox_.pack_start(discrimerButton_, Gtk::PACK_SHRINK);
            discrimerButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::discrimer));

            //Adding exit button (position 2,2)
            grid_.attach(exitButtonBox_, 2, 4, 1, 1);
            exitButtonBox_.set_layout(Gtk::BUTTONBOX_END);
            exitButtonBox_.pack_start(exitButton1_, Gtk::PACK_SHRINK);
            exitButton1_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::exit));

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
            defaultCanteraInputButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::defaultCanteraInput));
            defaultCanteraInputButton_.set_tooltip_text("Select the ASALI database for transport and thermodynamic properties");
#if ASALI_USING_CANTERA == 1
            chemistryButtonBox_.pack_start(loadCanteraInputButton_, Gtk::PACK_SHRINK);
            loadCanteraInputButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::loadCanteraInput));
            loadCanteraInputButton_.set_tooltip_text("Load CANTERA input file");
            chemistryButtonBox_.pack_start(convertCanteraFileButton_, Gtk::PACK_SHRINK);
            convertCanteraFileButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::convertCanteraInputFile));
            convertCanteraFileButton_.set_tooltip_text("Converter CANTERA input files");
#if ASALI_ON_WINDOW == 0
            chemistryButtonBox_.pack_start(conversionButton_, Gtk::PACK_SHRINK);
            conversionButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::chemkin));
            conversionButton_.set_tooltip_text("Converter of CHEMKIN files to CANTERA file");
#endif
            chemistryButtonBox_.pack_start(noneInputButton_, Gtk::PACK_SHRINK);
            noneInputButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::noneInput));
            noneInputButton_.set_tooltip_text("No input file required. Constant properties are used.");
#endif
            chemistryButtonBox_.pack_start(asaliKineticButton_, Gtk::PACK_SHRINK);
            asaliKineticButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::kineticAsali));
            asaliKineticButton_.set_tooltip_text("Write or check a kinetic scheme in ASALI format");

            //Adding exit button
            chemistryButtonBox_.pack_start(exitButton2_, Gtk::PACK_SHRINK);
            exitButton2_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::exit));
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
            asaliKineticMakeButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::kineticMake));
            asaliKineticMakeButton_.set_tooltip_text("Write a new kinetic scheme in ASALI format");
            kineticButtonBox_.pack_start(asaliKineticCheckButton_, Gtk::PACK_SHRINK);
            asaliKineticCheckButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::kineticCheck));
            asaliKineticCheckButton_.set_tooltip_text("Check a kinetic scheme in ASALI format");

            //Adding exit button
            kineticButtonBox_.pack_start(kineticButtonGrid_, Gtk::PACK_SHRINK);

            kineticButtonGrid_.set_column_homogeneous(true);
            kineticButtonGrid_.set_column_spacing(10);
            kineticButtonGrid_.set_row_spacing(10);
            kineticButtonGrid_.attach(backButton2_, 0, 0, 1, 1);
            backButton2_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::chemistryMenu2));
            kineticButtonGrid_.attach(exitButton5_, 1, 0, 1, 1);
            exitButton5_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::exit));
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
#if ASALI_USING_CANTERA == 1
            menuButtonBox_.pack_start(canteraInputButton_, Gtk::PACK_SHRINK);
            canteraInputButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::chemistryMenu2));
#endif
            menuButtonBox_.pack_start(transportButton_, Gtk::PACK_SHRINK);
            transportButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::transport));
            transportButton_.set_tooltip_text("Estimation of transport properties at assigned Temperture, Pressure and Composition");
            menuButtonBox_.pack_start(thermoButton_, Gtk::PACK_SHRINK);
            thermoButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::thermo));
            thermoButton_.set_tooltip_text("Estimation of thermodynamic properties at assigned Temperture, Pressure and Composition");
            menuButtonBox_.pack_start(thermoTransportButton_, Gtk::PACK_SHRINK);
            thermoTransportButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::thermoTransport));
            thermoTransportButton_.set_tooltip_text("Estimation of thermodynamic & transport properties\nat assigned Temperture, Pressure and Composition");
            menuButtonBox_.pack_start(physicalChemicalButton_, Gtk::PACK_SHRINK);
            physicalChemicalButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::physicalChemical));
            physicalChemicalButton_.set_tooltip_text("Estimation of physical & chemical properties\nat assigned Temperture, Pressure and Composition");
            menuButtonBox_.pack_start(vacuumButton_, Gtk::PACK_SHRINK);
            vacuumButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::vacuum));
            vacuumButton_.set_tooltip_text("Estimation of specie vacuum properties at assigned Temperture and Pressure");
            menuButtonBox_.pack_start(linearRegressionButton_, Gtk::PACK_SHRINK);
            linearRegressionButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::linearRegression));
            linearRegressionButton_.set_tooltip_text("Estimaion of linear equations for thermodynamic and transport properties\nof a gas mixture as a function of Temperature");
#if ASALI_USING_CANTERA == 1
            menuButtonBox_.pack_start(equilibriumButton_, Gtk::PACK_SHRINK);
            equilibriumButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::equilibrium));
            equilibriumButton_.set_tooltip_text("Estimation of chemical equilibrium based on CANTERA");
            menuButtonBox_.pack_start(reactorsButton_, Gtk::PACK_SHRINK);
            reactorsButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::reactors));
            reactorsButton_.set_tooltip_text("Solvers for different catalytic reactor geometries");
#if ASALI_NEXT_VERSION == 1
            menuButtonBox_.pack_start(pelletButton_, Gtk::PACK_SHRINK);
            pelletButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::pellets));
            pelletButton_.set_tooltip_text("Solvers for different catalytic pellet geometries");
#endif
#endif

            //Adding exit button
            menuButtonBox_.pack_start(exitButton3_, Gtk::PACK_SHRINK);
            exitButton3_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::exit));
        }

        //Catalytic reactor menu
        {
#if ASALI_USING_CANTERA == 1
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
            batchButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::batch));
            reactorButtonBox_.pack_start(cstrButton_, Gtk::PACK_SHRINK);
            cstrButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::cstr));
            reactorButtonBox_.pack_start(ph1dButton_, Gtk::PACK_SHRINK);
            ph1dButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::ph1d));
#if ASALI_NEXT_VERSION == 1
            reactorButtonBox_.pack_start(het1dButton_, Gtk::PACK_SHRINK);
            het1dButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::het1d));
#endif
            reactorButtonBox_.pack_start(dpButton_, Gtk::PACK_SHRINK);
            dpButton_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::dp));

            //Adding exit button
            reactorButtonBox_.pack_start(reactorButtonGrid_, Gtk::PACK_SHRINK);

            reactorButtonGrid_.set_column_homogeneous(true);
            reactorButtonGrid_.set_column_spacing(10);
            reactorButtonGrid_.set_row_spacing(10);
            reactorButtonGrid_.attach(backButton1_, 0, 0, 1, 1);
            backButton1_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::mainMenu));
            reactorButtonGrid_.attach(exitButton4_, 1, 0, 1, 1);
            exitButton4_.signal_clicked().connect(sigc::mem_fun(*this, &mainGui::exit));
#endif
        }
    }

    void mainGui::changeCursor()
    {
        logoEventBox_.get_window()->set_cursor(Gdk::Cursor::create(Gdk::HAND1));
    }

    bool mainGui::chemistryMenu1(GdkEventButton *)
    {
        this->remove();
        this->set_title("ASALI");
        this->add(chemistryBox_);
        this->resize(chemistryBox_.get_width(), chemistryBox_.get_height());
        this->show_all_children();
        return true;
    }

    void mainGui::chemistryMenu2()
    {
        this->remove();
        this->set_title("ASALI");
        this->add(chemistryBox_);
        this->resize(chemistryBox_.get_width(), chemistryBox_.get_height());
        this->show_all_children();
    }

    void mainGui::mainMenu()
    {
        this->remove();
        this->set_title("ASALI");
        this->add(menuBox_);
        this->resize(menuBox_.get_width(), menuBox_.get_height());
        this->show_all_children();
    }

    void mainGui::discrimer()
    {
        Gtk::MessageDialog dialog(*this, "ASALI is free software: You can redistribute it and/or modify\n"
                                         " it the terms of the GNU General Public License as published by\n"
                                         "the Free Software Foundation, either version 3 of the License,\n"
                                         "or (at your option) any later version.\n"
                                         "\nASALI is distributed in the hope that it will be useful,\n"
                                         "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
                                         "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n"
                                         "\nSee the GNU General Public License for more details.\n"
                                         "You should have received a copy of the GNU General Public License\n"
                                         "along with ASALI. If not, see http://www.gnu.org/licenses/.\n",
                                  true, Gtk::MESSAGE_OTHER);
        dialog.run();
    }

    void mainGui::noneInputError()
    {
        Gtk::MessageDialog dialog(*this, "This feauture is not available. To use it, please, select a CANTERA kinetic/properties file.", true, Gtk::MESSAGE_ERROR);
        dialog.set_secondary_text(beerQuote_->getRandomQuote(), true);
        dialog.run();
    }

    void mainGui::updateBasicChemistryInterface()
    {
        if (!chemistryInterface_)
        {
            delete chemistryInterface_;
        }

#if ASALI_USING_CANTERA == 1
        chemistryInterface_ = new ASALI::canteraInterface(basicXMLfilepath_, basicGasPhase_, "none");
#else
        chemistryInterface_ = new ASALI::asaliInterface();
#endif
    }

    void mainGui::updateChemistryInterface(const std::string &filepath, const std::string &gasPhase, const std::string &surfPhase)
    {
        if (!chemistryInterface_)
        {
            delete chemistryInterface_;
        }

#if ASALI_USING_CANTERA == 1
        chemistryInterface_ = new ASALI::canteraInterface(filepath, gasPhase, surfPhase);
#else
        chemistryInterface_ = new ASALI::asaliInterface();
#endif
    }

    void mainGui::defaultCanteraInput()
    {
        this->updateBasicChemistryInterface();
        speciesNames_ = new ASALI::speciesPopup();
        kineticType_ = "default";
        this->mainMenu();
    }

    void mainGui::noneInput()
    {
        kineticType_ = "none";
        this->mainMenu();
    }

    void mainGui::kineticAsali()
    {
        this->set_title("ASALI: Kinetic");
        this->remove();
        this->add(kineticBox_);
        this->resize(kineticBox_.get_width(), kineticBox_.get_height());
        this->show_all_children();
    }

    void mainGui::kineticMake()
    {
        if (!kineticMakerMenu_)
        {
            delete kineticMakerMenu_;
        }

        this->updateBasicChemistryInterface();

        kineticMakerMenu_ = new ASALI::kineticMaker();
        kineticMakerMenu_->setChemistryInterface(chemistryInterface_);
        kineticMakerMenu_->show();
    }

    void mainGui::kineticCheck()
    {
        std::string filename = fileManager_.openFile(this->get_toplevel()->gobj());
        if (filename != "")
        {
            std::ifstream input;
            const char *path = filename.c_str();
            input.open(path);

            if (filename.substr(filename.length() - 3, filename.length()) != ".py")
            {
                Gtk::MessageDialog dialogSmall(*this, "Something is wrong in your ASALI kinetic file!", true, Gtk::MESSAGE_ERROR);
                dialogSmall.set_secondary_text(beerQuote_->getRandomQuote(), true);
                dialogSmall.run();
            }
            else
            {
                std::vector<std::string> filevector = fileManager_.splitPath(filename);
                std::string function = filevector.back().substr(0, filevector.back().length() - 3);
                std::string path = filename.substr(0, filename.length() - function.length() - 3);

                ASALI::pythonInterface pi;
                std::string check = pi.initialize(function, path);
                pi.close();

                if (check != "done")
                {
                    Gtk::MessageDialog dialogSmall(*this, "Something is wrong in your ASALI kinetic file!", true, Gtk::MESSAGE_ERROR);
                    dialogSmall.set_secondary_text(beerQuote_->getRandomQuote(), true);
                    dialogSmall.run();
                }
                else
                {
                    Gtk::MessageDialog dialogSmall(*this, "Your ASALI kinetic file is perfect!", true, Gtk::MESSAGE_INFO);
                    dialogSmall.set_secondary_text(beerQuote_->getRandomQuote(), true);
                    dialogSmall.run();
                }
            }
        }
    }

    void mainGui::transport()
    {
        if (kineticType_ == "none")
        {
            this->noneInputError();
        }
        else
        {
            if (!transportMenu_)
            {
                delete transportMenu_;
            }
            transportMenu_ = new ASALI::transportProperties(speciesNames_, kineticType_);
            transportMenu_->setChemistryInterface(chemistryInterface_);
            transportMenu_->update();
            transportMenu_->show();
        }
    }

    void mainGui::thermo()
    {
        if (kineticType_ == "none")
        {
            this->noneInputError();
        }
        else
        {
            if (!thermoMenu_)
            {
                delete thermoMenu_;
            }
            thermoMenu_ = new ASALI::thermoProperties(speciesNames_, kineticType_);
            thermoMenu_->setChemistryInterface(chemistryInterface_);
            thermoMenu_->update();
            thermoMenu_->show();
        }
    }

    void mainGui::thermoTransport()
    {
        if (kineticType_ == "none")
        {
            this->noneInputError();
        }
        else
        {
            if (!thermoTransportMenu_)
            {
                delete thermoTransportMenu_;
            }
            thermoTransportMenu_ = new ASALI::thermoTransportProperties(speciesNames_, kineticType_);
            thermoTransportMenu_->setChemistryInterface(chemistryInterface_);
            thermoTransportMenu_->update();
            thermoTransportMenu_->show();
        }
    }

    void mainGui::physicalChemical()
    {
        if (kineticType_ == "none")
        {
            this->noneInputError();
        }
        else
        {
            if (!physicalChemicalMenu_)
            {
                delete physicalChemicalMenu_;
            }
            physicalChemicalMenu_ = new ASALI::physicalChemicalProperties(speciesNames_, kineticType_);
            physicalChemicalMenu_->setChemistryInterface(chemistryInterface_);
            physicalChemicalMenu_->show();
        }
    }

    void mainGui::vacuum()
    {
        if (kineticType_ == "none")
        {
            this->noneInputError();
        }
        else
        {
            if (!vacuumMenu_)
            {
                delete vacuumMenu_;
            }
            vacuumMenu_ = new ASALI::vacuumProperties(speciesNames_, kineticType_);
            vacuumMenu_->setChemistryInterface(chemistryInterface_);
            vacuumMenu_->show();
        }
    }

    void mainGui::linearRegression()
    {
        if (kineticType_ == "none")
        {
            this->noneInputError();
        }
        else
        {
            if (!linearRegressionMenu_)
            {
                delete linearRegressionMenu_;
            }
            linearRegressionMenu_ = new ASALI::linearRegression(speciesNames_, kineticType_);
            linearRegressionMenu_->setChemistryInterface(chemistryInterface_);
            linearRegressionMenu_->show();
        }
    }

#if ASALI_USING_CANTERA == 1
    void mainGui::chemkin()
    {
        if (!converter_)
        {
            delete converter_;
        }
        converter_ = new ASALI::chemkinConverter();
        converter_->show();
    }

    void mainGui::loadCanteraInput()
    {
        std::string filename = fileManager_.openFile(this->get_toplevel()->gobj());
        if (filename != "")
        {
            std::ifstream input;
            const char *path = filename.c_str();
            input.open(path);

            if (filename.find("cti") != std::string::npos)
            {
                Gtk::MessageDialog errorDialog(*this, "Sorry, ASALI use only the xml version of CANTERA input file\nConvert .cti to .xml using CANTERA -> CANTERA converter", true, Gtk::MESSAGE_WARNING);
                errorDialog.set_secondary_text(beerQuote_->getRandomQuote(), true);
                errorDialog.run();
            }
            else if (filename.find("xml") != std::string::npos)
            {
                std::vector<std::string> interfaces = fileManager_.getCanteraInterfaces(filename);

                if (interfaces[0] == "none" ||
                    interfaces[1] == "none")
                {
                    Gtk::MessageDialog smallDialog(*this, "We detect that your CANTERA input file does not have a surface phase.\nDo you wonna continue anyway?", true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_YES_NO);
                    smallDialog.set_secondary_text(beerQuote_->getShortRandomQuote(), true);
                    int answer = smallDialog.run();

                    //Handle the response:
                    switch (answer)
                    {
                    case (Gtk::RESPONSE_YES):
                    {
                        std::string type = "none";
                        for (unsigned int i = 0; i < interfaces.size(); i++)
                        {
                            if (interfaces[i] != "none")
                            {
                                type = fileManager_.getCanteraPhaseName(interfaces[i]);
                            }
                        }

                        if (type == "none")
                        {
                            Gtk::MessageDialog errorDialog(*this, "Something is wrong in your CANTERA input file.", true, Gtk::MESSAGE_WARNING);
                            errorDialog.set_secondary_text(beerQuote_->getShortRandomQuote(), true);
                            errorDialog.run();
                            smallDialog.hide();
                            break;
                        }
                        else
                        {
                            this->updateChemistryInterface(filename, type, "none");
                            speciesNames_ = new ASALI::speciesPopup();
                            kineticType_ = "nokinetic";
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
                    for (unsigned int i = 0; i < interfaces.size(); i++)
                    {
                        type[i] = fileManager_.getCanteraPhaseName(interfaces[i]);

                        if (type[0] != "none" && type[1] != "none")
                        {
                            break;
                        }
                    }

                    if (type[0] == "none" ||
                        type[1] == "none")
                    {
                        Gtk::MessageDialog errorDialog(*this, "Something is wrong in your CANTERA kinetic file.", true, Gtk::MESSAGE_WARNING);
                        errorDialog.set_secondary_text(beerQuote_->getShortRandomQuote(), true);
                        errorDialog.run();
                    }
                    else
                    {
                        this->updateChemistryInterface(filename, type[0], type[1]);
                        kineticType_ = "load";
                        this->mainMenu();
                    }
                }
            }
            else
            {
                Gtk::MessageDialog smallDialog(*this, "Something is wrong in your CANTERA kinetic file.", true, Gtk::MESSAGE_WARNING);
                smallDialog.set_secondary_text(beerQuote_->getShortRandomQuote(), true);
                smallDialog.run();
            }
        }
    }

    void mainGui::convertCanteraInputFile()
    {
        std::string filename = fileManager_.openFile(this->get_toplevel()->gobj());
        if (filename != "")
        {
            std::ifstream input;
            const char *path = filename.c_str();
            input.open(path);

            if (filename.find("cti") != std::string::npos)
            {
                fileManager_.fromCtiToYaml(filename);
                Gtk::MessageDialog dialog(*this, "Conversion completed. Your file as been saved.\nThank you for using ASALI.", true, Gtk::MESSAGE_OTHER);
                dialog.set_secondary_text(beerQuote_->getShortRandomQuote(), true);
                dialog.run();
            }
            else if (filename.find("xml") != std::string::npos)
            {
                fileManager_.fromXmlToYaml(filename);
                Gtk::MessageDialog dialog(*this, "Conversion completed. Your file as been saved.\nThank you for using ASALI.", true, Gtk::MESSAGE_OTHER);
                dialog.set_secondary_text(beerQuote_->getShortRandomQuote(), true);
                dialog.run();
            }
            else
            {
                Gtk::MessageDialog errorDialog(*this, "Sorry, not recognized CANTERA format", true, Gtk::MESSAGE_WARNING);
                errorDialog.set_secondary_text(beerQuote_->getRandomQuote(), true);
                errorDialog.run();
            }
        }
    }

    void mainGui::equilibrium()
    {
        if (kineticType_ == "none")
        {
            this->noneInputError();
        }
        else
        {
            if (!equilibriumMenu_)
            {
                delete equilibriumMenu_;
            }
            equilibriumMenu_ = new ASALI::equilibriumCalculator(speciesNames_, kineticType_);
            equilibriumMenu_->setChemistryInterface(chemistryInterface_);
            equilibriumMenu_->update();
            equilibriumMenu_->show();
        }
    }

    void mainGui::pellets()
    {
        if (!pelletMenu_)
        {
            delete pelletMenu_;
        }
        pelletMenu_ = new ASALI::catalyticPellet(kineticType_);
        pelletMenu_->setChemistryInterface(chemistryInterface_);
        pelletMenu_->show();
    }

    void mainGui::reactors()
    {
        this->set_title("ASALI: Catalytic reactors");
        this->remove();
        this->add(reactorBox_);
        this->resize(reactorBox_.get_width(), reactorBox_.get_height());
        this->show_all_children();
    }

    void mainGui::batch()
    {
        if (!batchMenu_)
        {
            delete batchMenu_;
        }
        batchMenu_ = new ASALI::batchReactor(kineticType_);
        batchMenu_->setChemistryInterface(chemistryInterface_);
        batchMenu_->show();
    }

    void mainGui::cstr()
    {
        if (!cstrMenu_)
        {
            delete cstrMenu_;
        }
        cstrMenu_ = new ASALI::cstrReactor(kineticType_);
        cstrMenu_->setChemistryInterface(chemistryInterface_);
        cstrMenu_->show();
    }

    void mainGui::ph1d()
    {
        if (!ph1dMenu_)
        {
            delete ph1dMenu_;
        }
        ph1dMenu_ = new ASALI::ph1dReactor(kineticType_);
        ph1dMenu_->setChemistryInterface(chemistryInterface_);
        ph1dMenu_->show();
    }

    void mainGui::het1d()
    {
        if (!het1dMenu_)
        {
            delete het1dMenu_;
        }
        het1dMenu_ = new ASALI::het1dReactor(kineticType_);
        het1dMenu_->setChemistryInterface(chemistryInterface_);
        het1dMenu_->show();
    }

    void mainGui::dp()
    {
        if (!dpMenu_)
        {
            delete dpMenu_;
        }
        dpMenu_ = new ASALI::pressureDrops(speciesNames_, kineticType_);
        dpMenu_->setChemistryInterface(chemistryInterface_);
        dpMenu_->show();
    }
#endif

    void mainGui::exit()
    {
        this->hide();
    }
}
