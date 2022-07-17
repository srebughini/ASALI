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

#include "backend/asaliFileManager.hpp"

namespace ASALI
{
    asaliFileManager::asaliFileManager():
        speciesPopupfilepath_(this->relative_path_to_absolute_path("database/species.asali")),
        ck2yamlfilepath_(this->relative_path_to_absolute_path("scripts/ck2yaml.py")),
        cti2yamlfilepath_(this->relative_path_to_absolute_path("scripts/cti2yaml.py")),
        ctml2yamlfilepath_(this->relative_path_to_absolute_path("scripts/ctml2yaml.py"))
    {
    }

    std::string asaliFileManager::saveFile(gpointer window, std::string current_file_name)
    {
        GtkWindow *parent_window = GTK_WINDOW(window);
        GtkFileChooserNative *native;
        GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_SAVE;
        gint res;

        native = gtk_file_chooser_native_new("Save File", parent_window, action, "_Save", "_Cancel");
        gtk_file_chooser_set_current_name(GTK_FILE_CHOOSER(native), current_file_name.c_str());
        res = gtk_native_dialog_run(GTK_NATIVE_DIALOG(native));
        if (res == GTK_RESPONSE_ACCEPT)
        {
            char *filename;
            GtkFileChooser *chooser = GTK_FILE_CHOOSER(native);
            filename = gtk_file_chooser_get_filename(chooser);
            g_object_unref(native);
            return std::string(filename);
        }
        else
        {
            return "";
        }
    }

    std::string asaliFileManager::openFile(gpointer window)
    {
        GtkWindow *parent_window = GTK_WINDOW(window);
        GtkFileChooserNative *native;
        GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
        gint res;

        native = gtk_file_chooser_native_new("Open File", parent_window, action, "_Open", "_Cancel");
        res = gtk_native_dialog_run(GTK_NATIVE_DIALOG(native));
        if (res == GTK_RESPONSE_ACCEPT)
        {
            char *filename;
            GtkFileChooser *chooser = GTK_FILE_CHOOSER(native);
            filename = gtk_file_chooser_get_filename(chooser);
            g_object_unref(native);
            return std::string(filename);
        }
        else
        {
            return "";
        }
    }

    std::string asaliFileManager::relative_path_to_absolute_path(std::string relpath)
    {
        return std::string(g_build_filename(COMPILING_PATH, relpath.c_str(), NULL));
    }

    std::vector<std::string> asaliFileManager::splitString(std::string txt, std::string ch)
    {
        std::vector<std::string> strs;
        std::size_t pos = txt.find(ch);
        std::size_t initialPos = 0;

        strs.clear();

        while (pos != std::string::npos)
        {
            strs.push_back(txt.substr(initialPos, pos - initialPos));
            initialPos = pos + 1;

            pos = txt.find(ch, initialPos);
        }

        strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));

        return strs;
    }

    std::vector<std::string> asaliFileManager::splitPath(std::string path)
    {
#if ASALI_ON_WINDOW == 0
        return this->splitString(path, "/");
#else
        return this->splitString(path, "\\");
#endif
    }

    std::vector<std::string> asaliFileManager::getCanteraInterfaces(std::string filename)
    {
        YAML::Node input = YAML::LoadFile(filename);

        std::vector<std::string> interfaceNames(2);
        interfaceNames[0] = "none";
        interfaceNames[1] = "none";
        
        unsigned int n_phases = input["phases"].size();
        
        if (n_phases < 3)
        {
            for (unsigned int i=0;i<n_phases;i++)
            {
                if (input["phases"][i]["thermo"].as<std::string>() == "ideal-gas")
                {
                    interfaceNames[0] = input["phases"][i]["name"].as<std::string>();
                }
                else if (input["phases"][i]["thermo"].as<std::string>() == "ideal-surface")
                {
                    interfaceNames[1] = input["phases"][i]["name"].as<std::string>();
                }
            }
        }
        return interfaceNames;
    }

    bool asaliFileManager::areReactionsPresent(std::string filename)
    {
        YAML::Node input = YAML::LoadFile(filename);
        
        if (input["reactions"])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    std::vector<std::vector<std::string>> asaliFileManager::readSpeciesPopupFile()
    {
		std::vector<std::string> formula;
		std::vector<std::string> description;
		std::vector<std::string> name;
		
		std::ifstream inputfile(speciesPopupfilepath_);
		std::string line;
		while (std::getline(inputfile, line))
		{
			std::vector<std::string> row = this->splitString(line, "\t");
			formula.push_back(row[0]);
			description.push_back(row[1]);
			name.push_back(row[2]);
		}

		std::vector<std::vector<std::string>> output{formula, description, name};
		return output;
	} 
    

#if ASALI_USING_CANTERA == 1
    void asaliFileManager::fromXmlToYaml(std::string xmlFilePath)
    {
        ASALI::pythonInterface pi_;
        std::string yamlFilePath = this->replaceFileExtension(xmlFilePath, "yaml");
        int argc = 3;
        char* argv[] = {strdup(ctml2yamlfilepath_.c_str()),
                        strdup(xmlFilePath.c_str()),
                        strdup(yamlFilePath.c_str())};

        pi_.runScript(ctml2yamlfilepath_, argc, argv);
    }

    void asaliFileManager::fromCtiToYaml(std::string ctiFilePath)
    {
        ASALI::pythonInterface pi_;
        std::string yamlFilePath = this->replaceFileExtension(ctiFilePath, "yaml");
        int argc = 3;
        char* argv[] = {strdup(cti2yamlfilepath_.c_str()),
                        strdup(ctiFilePath.c_str()),
                        strdup(yamlFilePath.c_str())};

        pi_.runScript(cti2yamlfilepath_, argc, argv);
    }

    void asaliFileManager::fromCkToYaml(std::vector<std::string> ckFilePaths, bool is_surface)
    {
        ASALI::pythonInterface pi_;
        
        
        if (is_surface == true)
        {
            int argc = 9;
            char* argv[] = {strdup(ck2yamlfilepath_.c_str()),
                            strdup(ckFilePaths[0].c_str()),
                            strdup(ckFilePaths[1].c_str()),
                            strdup(ckFilePaths[2].c_str()),
                            strdup(ckFilePaths[3].c_str()),
                            strdup(ckFilePaths[4].c_str()),
                            strdup("--quiet"),
                            strdup("--no-validate"),
                            strdup("--permissive")};

            pi_.runScript(ck2yamlfilepath_, argc, argv);
        }
        else
        {
            int argc = 8;
            char* argv[] = {strdup(ck2yamlfilepath_.c_str()),
                            strdup(ckFilePaths[0].c_str()),
                            strdup(ckFilePaths[1].c_str()),
                            strdup(ckFilePaths[2].c_str()),
                            strdup(ckFilePaths[4].c_str()),
                            strdup("--quiet"),
                            strdup("--no-validate"),
                            strdup("--permissive")};

            pi_.runScript(ck2yamlfilepath_, argc, argv);
        }

    }
#endif

    void asaliFileManager::removeFileExtension(std::string &filename, const std::string &extension)
    {
        this->eraseSubString(filename, extension);
    }

    void asaliFileManager::eraseSubString(std::string &mainStr, const std::string &toErase)
    {
        size_t pos = std::string::npos;

        while ((pos = mainStr.find(toErase)) != std::string::npos)
        {
            mainStr.erase(pos, toErase.length());
        }
    }
    
    std::string asaliFileManager::replaceFileExtension(const std::string mainStr, const std::string extension)
    {
        std::vector<std::string> mainStrVector = this->splitString(mainStr, ".");
        
        if (mainStrVector.size() == 2 )
        {
            return mainStrVector[0] + "." + extension;
        }
        else
        {
            return mainStr;
        }
    }
}
