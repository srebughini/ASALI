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
	asaliFileManager::asaliFileManager()
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

	std::vector<std::string> asaliFileManager::splitString(const std::string txt, std::string ch)
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

	std::vector<std::string> asaliFileManager::splitPath(const std::string path)
	{
#if ASALI_ON_WINDOW == 0
		return this->splitString(path, "/");
#else
		return this->splitString(path, "\\");
#endif
	}

	std::vector<std::string> asaliFileManager::getCanteraInterfaces(const std::string filename)
	{
		const char *path = filename.c_str();
		std::ifstream input;
		input.open(path);
		std::vector<std::string> readed(2);
		readed[0] = "none";
		readed[1] = "none";

		std::vector<std::string> a;
		std::vector<std::string> b;
		while (!input.eof())
		{
			std::string line;
			getline(input, line);
			if (line.find("<phase ") != std::string::npos)
			{
				a.push_back(line);
			}
			else if (line.find("<kinetics ") != std::string::npos)
			{
				b.push_back(line);
			}
		}

		for (unsigned int i = 0; i < b.size(); i++)
		{
			if (b[i].find("Interface") != std::string::npos)
			{
				readed[1] = a[i];
			}
			else if (b[i].find("GasKinetics") != std::string::npos)
			{
				readed[0] = a[i];
			}
		}
		input.close();
		return readed;
	}

	std::string asaliFileManager::getCanteraPhaseName(std::string interfaceName)
	{
		for (std::size_t j = 0; j < interfaceName.size(); j++)
		{
			if (interfaceName.substr(j, 1) == ">")
			{
				interfaceName.replace(j, 1, " ");
			}
			else if (interfaceName.substr(j, 1) == "\"")
			{
				interfaceName.replace(j, 1, " ");
			}
			else if (interfaceName.substr(j, 1) == "=")
			{
				interfaceName.replace(j, 1, " ");
			}
		}

		std::vector<std::string> dummyVector;
		dummyVector.clear();

		std::istringstream iss(interfaceName);
		while (iss >> interfaceName)
		{
			dummyVector.push_back(interfaceName);
		}

		std::string phaseName = "none";

		if (dummyVector.size() > 4)
		{
			for (unsigned int j = 0; j < dummyVector.size() - 1; j++)
			{
				if (dummyVector[j] == "<phase" &&
					dummyVector[j + 1] == "dim" &&
					dummyVector[j + 3] == "id")
				{
					phaseName = dummyVector[j + 4];
					phaseName.erase(std::remove(phaseName.begin(), phaseName.end(), '"'), phaseName.end());
					phaseName.erase(std::remove(phaseName.begin(), phaseName.end(), ' '), phaseName.end());
				}
				else if (dummyVector[j] == "<phase" &&
						 dummyVector[j + 1] == "id" &&
						 dummyVector[j + 3] == "dim")
				{
					phaseName = dummyVector[j + 2];
					phaseName.erase(std::remove(phaseName.begin(), phaseName.end(), '"'), phaseName.end());
					phaseName.erase(std::remove(phaseName.begin(), phaseName.end(), ' '), phaseName.end());
				}
			}
		}

		return phaseName;
	}

	asaliFileManager::~asaliFileManager()
	{
	}
}
