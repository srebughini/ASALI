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
#   ASALI is free software you can redistribute it and/or modify                               #
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

std::string save_file(gpointer window, std::string current_file_name)
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

std::string open_file(gpointer window)
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

std::string relative_path_to_absolute_path(std::string relpath)
{
    return std::string(g_build_filename(COMPILING_PATH, relpath.c_str(), NULL));
}
