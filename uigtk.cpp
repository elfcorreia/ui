#include <gtk/gtk.h>
#include <iostream>

#include "ui.h"

using namespace std;

struct dialog_holder {
    GtkApplication* app;
    GtkWidget* window;
};

static void app_activate(GtkApplication* app, gpointer user_data) {
    cout << "app activate called!\n";
    ui::dialog* dialog = static_cast<ui::dialog*>(user_data);
    dialog_holder* holder = static_cast<dialog_holder*>(dialog->platform_data());
    
    GtkWidget* w = gtk_application_window_new(app);
    gtk_window_set_title (GTK_WINDOW (w), dialog->title().c_str());
    gtk_window_set_default_size (GTK_WINDOW (w), 200, 200);
    holder->window = w;

    gtk_widget_show(w);
}

void ui::dialog::platform::show(ui::dialog* dialog) {
    cout << "show called!\n";
    dialog_holder* holder = new dialog_holder;
    GtkApplication *app = gtk_application_new("ui.emerson", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(app_activate), dialog);
    holder->app = app;
    dialog->set_platform_data(holder);

    g_application_run(G_APPLICATION(app), 0, nullptr);
    g_object_unref(app);
}