#include <stdlib.h>
#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>
#include "gtk.h"

GtkWidget *make_window()
{
   GtkWidget *pF = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(pF), "Titre");
   gtk_window_set_default_size(GTK_WINDOW(pF), 320, 200);
   gtk_window_set_deletable(GTK_WINDOW(pF), TRUE);

   g_signal_connect(G_OBJECT(pF), "destroy", G_CALLBACK(gtk_main_quit), NULL);

   return pF;
}// Fin make_window()

GtkWidget *make_menu(GtkWidget *pFenetre)
{
   GtkWidget *barre_menu, *menu_fichier;
   GtkWidget *item_fichier, *item_nouveau, *item_ouvrir;
   GtkWidget *item_quitter = NULL, *item_separateur;
   GtkAccelGroup *accelerateur = NULL;

   //Création des éléments
   barre_menu = gtk_menu_bar_new();
   menu_fichier = gtk_menu_new();

   accelerateur = gtk_accel_group_new();
   gtk_window_add_accel_group(GTK_WINDOW(pFenetre), accelerateur);
   gtk_widget_add_accelerator(item_quitter, "activate", accelerateur,
                              GDK_r, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

   item_fichier = gtk_menu_item_new_with_mnemonic("_Fichier");
   item_nouveau = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW, NULL);
   item_ouvrir = gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN, NULL);
   item_separateur = gtk_separator_menu_item_new();
   item_quitter = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, accelerateur);

   //Attacher les items
   gtk_menu_item_set_submenu(GTK_MENU_ITEM(item_fichier), menu_fichier);
   gtk_menu_shell_append(GTK_MENU_SHELL(menu_fichier), item_nouveau);
   gtk_menu_shell_append(GTK_MENU_SHELL(menu_fichier), item_ouvrir);
   gtk_menu_shell_append(GTK_MENU_SHELL(menu_fichier), item_separateur);
   gtk_menu_shell_append(GTK_MENU_SHELL(menu_fichier), item_quitter);
   gtk_menu_shell_append(GTK_MENU_SHELL(barre_menu), item_fichier);

   //Signal
   g_signal_connect(G_OBJECT(item_quitter), "activate", G_CALLBACK(gtk_main_quit), NULL);

   return barre_menu;
}//Fin make_menu()
